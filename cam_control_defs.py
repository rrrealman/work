from urlparse import urlparse, parse_qs
from urllib import urlencode, urlopen

from DictAttr import DictAttr

def __translate__(condition):
	return "OK" if condition else "Bad"

class Request(DictAttr):
	def __init__(self, params, path, ip):
		self.params = self.__make_list__(params)
		self.path   = path
		self.ip     = ip
	def is_valid(self, param):
		if isinstance(param, tuple) and len(param) == 2: # argument string couldn't have whitespaces
			return True
		return False
	def __make_list__(self, params):
		if self.is_valid(params):
			valid_list = list([params])
		elif isinstance(params, list):
			valid_list = list(params)
		elif isinstance(params, dict):
			valid_list = list(params.items())
		else:
			valid_list = []
		for param in valid_list:
			if not self.is_valid(param):
				valid_list.remove(param)
		return valid_list
	def __iadd__(self, add_params):
		add_list = self.__make_list__(add_params)
		for param in add_list:
			self-=param
			self.params.append(param)
		return self
	def __isub__(self, sub_params):
		sub_list = self.__make_list__(sub_params)
		for param in sub_list:
			while True:
				try:
					self.params.remove(param)
				except:
					break
		return self
	# def __setattr__(self):
	# 	pass
	def __repr__(self):
		slash  = "/" if self.path != "" else ""
		q_mark = "?" if self.params != [] else ""
		return "http://%s%s%s%s%s" % (self.ip, slash, self.path, q_mark, urlencode(self.params))
	def send(self, direction = None):# direction can be tuple or string
		self += direction
		return parse_qs(urlparse(urlopen(repr(self)).read()).path)
	def path_exists(self):
		if self.path != "":
			return True
		return False
	def param_exists(self, param_name = None):
		if param_name is None:
			return bool(self.params)
		for param in self.params:
			if param[0] == param_name:
				return True
		return False

class Camera(DictAttr):
	def __init__(self, ip):
		self.ip = ip
		self.create_req()
		self.ready = False
	def create_req(self, params = list(), path = ""):
		self.req =  Request(params = params, path = path, ip = self.ip)
	def __str__(self):
		return "IP camera %s is %s" % (self.ip, __translate__(self.ready))
	def get_req(self):
		return self.__is_success__(self.req.send(("app", "get")))
	def set_req(self):
		return self.__is_success__(self.req.send(("app", "set")))
	def __is_success__(self, response):
		try:
			if response["res"][0] == "200":
				return response
			else:
				return False
		except:
			return False
	def set(self, conf_lines = list()):
		self.ready = True
		for line in conf_lines:
			try:
				setting, value = self.__parse_setting__(line)
			except ValueError:
				continue
			self.__processing__(setting, value)
		if self.req.param_exists() and self.req.path_exists():
			self.ready &= bool(self.set_req())
	def __processing__(self, setting, value):
		if setting == "path":
			if self.req.path_exists():
				self.ready &= bool(self.set_req())
			self.create_req(path = value)
		elif setting == "setting_group":
			if self.req.param_exists("group"):
				self.ready &= bool(self.set_req())
			self.create_req(path = self.req.path, params = [("group", value)])
		else:
			self.req += (setting, value)
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