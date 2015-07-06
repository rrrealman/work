#!/usr/bin/python
from socket import *
from struct import unpack
from os.path import exists

from Discovery import DiscoveryMessageStruct, CMD_GET_INF_REQ, RECV_ADDR, SEND_ADDR, MSG_FORMAT
from cam_control_defs import Camera, DictAttr, __translate__

class CameraController(DictAttr):
	def __init__(self, conf_file=""):
		self.cams = []
		if exists(conf_file):
			self.file = conf_file
		else:
			self.file = ""
		# self.ready = self.discover_cams()
		self.ready = True
		self.video = DictAttr(
			"video_enc1_res",# default is "2048x1536"
			"video_enc1_fps",# default is 30 fps
			"video_enc1_bitrate",# default is 10000 kbps !!! 10000 doesn't set up, there are only 5000 kbps and 12000 kbps
			"video_enc1_ratecontrol")# default is "vbr" (variable bitrate)
		# self.read_tgt_stgs() 
		self.video.video_enc1_res = "1920x1440"
		print self.video
		print self

	def __str__(self):
		return "CameraController instance with %d cameras is %s." % (len(self.cams), __translate__(self.ready))
	def read_tgt_stgs(self):
		for cam in self.cams:
			cam.create_req(path = "video/video.php")
			resp = cam.get_req()
			for stg in resp.keys():
				if stg in self.video.keys():
					if self.video[stg] is None or self.video[stg] == resp[stg]:
						self.video[stg] = resp[stg]
					else:
						self.ready = False
	def setup_cams(self):
		res = True
		for cam in self.cams:
			cam.set(self.__conf_file__())
			print cam
			res &= cam.ready
		return res
	def __conf_file__(self):
		try:
			file_inst = open(self.file, 'r+')
		except IOError:
			return []
		print "Configuration file: %s" % self.file
		lines = file_inst.readlines()
		file_inst.close()
		return lines
	def __socket_udp_init__(self, timeout=0):
		socket_udp = socket(AF_INET, SOCK_DGRAM)
		socket_udp.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
		socket_udp.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)
		socket_udp.bind(RECV_ADDR)
		if timeout != 0:
			socket_udp.settimeout(timeout)
		return socket_udp
	def discover_cams(self):
		msg = DiscoveryMessageStruct(CMD_GET_INF_REQ)
		socket_udp = self.__socket_udp_init__(5)
		socket_udp.sendto(msg, SEND_ADDR) # add condition data is not transmitted
		while True:
			try:
				dm = DiscoveryMessageStruct(*unpack(MSG_FORMAT, socket_udp.recvfrom(1024)[0]))
				self.cams.append(Camera(ip=dm.ip))
			except timeout:
				break
		return self.setup_cams()

if __name__ == "__main__":
	# Realize command line args
	cc = CameraController()
	cc.cams[0].set_up_default(conf_file = "default.conf", debug = True)
	cc.read_cams_settings()
	print cc.cams[0].host.rtsp_port
	print cc.cams[0].host.rtp_addr