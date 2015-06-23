from socket import gethostname, gethostbyname, socket, AF_INET, SOCK_DGRAM, SOL_SOCKET, SO_REUSEADDR, SO_BROADCAST
from ctypes import Structure, c_uint, c_char, sizeof, addressof, memset

from urlparse import urlparse, parse_qs
from urllib import urlencode, urlopen

CMD_GET_INF_REQ     = 1000
CMD_GET_INF_RES     = 1001
CMD_SET_IP_REQ      = 1004
CMD_SET_IP_RES      = 1005
CMD_SET_REBOOT_REQ  = 1006
CMD_SET_REBOOT_RES  = 1007
CMD_SET_USERSET_REQ = 1008
CMD_SET_USERSET_RES = 1009
CMD_SET_RESTORE_REQ = 1010
CMD_SET_RESTORE_RES = 1011
CMD_SET_DEFAULT_REQ = 1012
CMD_SET_DEFAULT_RES = 1013

HTTP                = "0"
HTTPS               = "1"
HTTP_AND_HTTPS      = "2"

SEND_PORT           = 21000
RECV_PORT           = 21001

HOSTNAME            = gethostname()
HOST_IP             = gethostbyname(HOSTNAME)

SEND_ADDR           = ("255.255.255.255", SEND_PORT)
RECV_ADDR           = ("0.0.0.0", RECV_PORT)

NUM_OF_CAMS         = 6 # or 3

MSG_FORMAT          = "i128s20s32s8s8s32s8s64s64s32s8s8s32s32s64s32s20s32s32s8s8s"

VIDEO_PATH = "/video/video.php"
IMAGE_PATH = "/video/image.php"
REC_PATH   = "/record/record.php"

class DiscoveryMessageStruct(Structure):
	'''Describes discovery message structure'''
	_fields_ = [
		("cmd",            c_uint),
		("host_name",      c_char*128),
        ("mac",            c_char*20),
        ("ip",             c_char*32),
        ("http_port",      c_char*8),
        ("rtsp_port",      c_char*8),
        ("rtp_addr",       c_char*32),
        ("rtp_port",       c_char*8),
        ("fw_ver",         c_char*64),
        ("br_ver",         c_char*64),
        ("set_ip",         c_char*32),
        ("https_mode",     c_char*8),
        ("https_port",     c_char*8),
        ("model",          c_char*32),
        ("model_customer", c_char*32),
        ("camera_name",    c_char*64),
        ("zeroconf_ip",    c_char*32),
        ("wireless_mac",   c_char*20),
        ("wireless_ip",    c_char*32),
        # Following fields weren't found in finetree discovery API, but they were in received from device message.
        ("__dev_name__",   c_char*32),
        ("__any_num1__",   c_char*8),
        ("__any_num2__",   c_char*8)]

class DictAttr(dict):
	"""Allows to access to dictionnary elements like to attributes of structure"""
	__getattr__ = dict.__getitem__
	__setattr__ = dict.__setitem__
	def __init__(self, *args, **kwargs):
		super(DictAttr, self).__init__(dict.fromkeys(args), **kwargs)

class Camera(DictAttr):
	"""Describes remote camera"""
	def __init__(self):
		self.host  = DiscoveryMessageStruct()
		self.video = DictAttr(
			"video_enc1_res",# default is "2048x1536"
			"video_enc1_fps",# default is 30 fps
			"video_enc1_bitrate",# default is 10000 kbps !!! 10000 doesn't set up, there are only 5000 kbps and 12000 kbps
			"video_enc1_ratecontrol")# default is "vbr" (variable bitrate)

	#### Send request to camera ####
	def send_request(self, **kwargs):
		'''Returns response from URL in form of dictionary of the lists'''
		q_mark = "?"
		debug = False
		try:
			path = kwargs["path"]
		except KeyError:
			path = ""
		try:
			params = kwargs["params"]
		except KeyError:
			params = ""
			q_mark = ""
		try:
			if isinstance(kwargs["debug"], bool):
				debug = kwargs["debug"]
		except KeyError:
			pass
		url = "http://%s/%s%s%s" % (self.host.ip, path, q_mark, urlencode(params, True))
		self.__print_debug__("URL: %s" % url)
		return parse_qs(urlparse(urlopen(url).read()).path)

	#### Reading from camera ####
	def read_settings(self):
		'''Reads settings of given camera'''
		response = self.get_req(dict(params = list(), path = "video/video.php"))
		for setting in response:
			if hasattr(self.video, setting):
				setattr(self.video, setting, response[setting])

	#### Get camera information ####
	def get_req(self, request):
		'''Gets settings from given request'''
		self.__print_debug__("Get request starts.")
		request["params"].append(("app", "get"))
		response = self.send_request(**request)
		try:
			if response["res"][0]!="200":
				response = False
		except KeyError:
			response = False
		request["params"].pop()
		self.__print_debug__("Get request returns %s." % self.__translate__(response))
		return response

	#### Set up camera ####
	def set_req(self, request):
		'''Sets up settings of given request'''
		self.__print_debug__("Set request starts.")
		request["params"].append(("app", "set"))
		response = False
		try:
			if self.send_request(**request)["res"][0]=="200":
				response = True
		except KeyError:
			pass
		request["params"].pop()
		self.__print_debug__("Set request %s." % self.__translate__(response))
		return response

	#### Setting up cameras from default cameras ####
	def set_up_default(self, **kwargs):
		"""Sets up default settings from file default.conf"""
		global debug
		try:
			debug = kwargs["debug"]
		except KeyError:
			debug = False
		try:
			file_conf = kwargs["file_conf"]
		except KeyError:
			file_conf = "default.conf"
		conf_lines   = self.__conf_file__(file_conf)
		req          = dict(params = list(), group_exists = False)
		set_path     = True
		for line in conf_lines:
			try:
				setting, value = self.__parse_setting__(line)
			except ValueError:
				continue
			if setting == "path":
				if "path" not in req.keys():
					req["path"] = value
					continue
				resp     =  self.set_req(req)
				set_path &= resp
				self.__print_debug__("group: %s: %s" % (req["params"][0][1], self.__translate__(resp)) if req["group_exists"] else "")
				self.__print_debug__("path: %s: %s" % (req["path"], self.__translate__(set_path)))
				req          = dict(path = value, params = list(), group_exists = False)
				set_path     = True
			elif setting == "setting_group":
				if req["group_exists"]:
					resp         =   self.set_req(req)
					set_path     &=  resp 
					req["group_exists"] =   False
					self.__print_debug__("group: %s: %s" % (req["params"][0][1], self.__translate__(resp)))
				req["params"] = [("group", value)]
				req["group_exists"]  = True
			else:
				req["params"].append((setting, value))

	#### Private ####
	def __translate__(self, condition):
		return "OK" if condition else "Bad"

	def __conf_file__(self, file_conf):
		try:
			file_inst = open(file_conf, 'r+')
		except IOError:
			self.__print_debug__("Configuration file not found!")
			return
		self.__print_debug__("Configuration file: %s" % file_conf)
		lines=file_inst.readlines()
		file_inst.close()
		return lines

	def __parse_setting__(self, line):
		line = line.replace("\n", "")
		line = line.replace(" ", "")
		try:
			line = line[0:line.index("#")]#removing comment
		except ValueError: 
			pass
		try:
			setting, value = line.split(":", 1)
		except ValueError:
			return ""
		return setting, value

	def __print_debug__(self, debug_str):
		try:
			if debug and isinstance(debug, bool) and len(debug_str)!=0:
				print debug_str
		except NameError:
			pass