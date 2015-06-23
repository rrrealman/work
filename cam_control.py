#!/usr/bin/python
from cam_control_defs import *
from socket import *
# from grab import grab

from struct import *

class CameraController(object):

	def __init__(self):
		self.cams=[]
		self.discover_cams()
		if len(self.cams) == 0:
			self.Ready = False
		else:
			self.Ready = True

	def setup_cams(self):
		'''Sets up cameras of CameraController object'''
		for cam in self.cams:
			cam.setup()

	def read_cams_settings(self):
		'''Updates settings of all cameras in CameraController'''
		for cam in self.cams:
			cam.read_settings()

#### Debugging section ####
	# def print_struct(self, struct, prefix):
	# 	'''Prints given C-styled struct in human-friendly view'''
	# 	for field_name, field_type in struct._fields_:
	# 		print "%s%s: %s" % (prefix, field_name, getattr(struct, field_name))

	# def print_cam(self, cam):
	# 	'''Prints all settings of given camera'''
	# 	print "\nCamera IP: %s" % cam.host.ip
	# 	self.print_struct(cam.host, "\t")
	# 	for setting_name, setting_type in cam.camera._fields_:
	# 		self.print_struct(getattr(cam.camera, setting_name), "\t")

	# def print_cams(self):
	# 	'''Prints settings of all cameras of CameraController object'''
	# 	for cam in self.cams:
	# 		self.print_cam(cam)

#### Class init section ####
	def socket_udp_init(self, timeout=0):
		'''Initializes UDP-socket to discover cameras in network'''
		socket_udp = socket(AF_INET, SOCK_DGRAM)
		socket_udp.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
		socket_udp.setsockopt(SOL_SOCKET, SO_BROADCAST, 1)
		socket_udp.bind(RECV_ADDR)

		if timeout != 0:
			socket_udp.settimeout(timeout)
		
		return socket_udp

	def discover_cams(self):
		'''Discovers available cameras in network'''
		msg = DiscoveryMessageStruct(CMD_GET_INF_REQ)
		socket_udp = self.socket_udp_init(5)
		socket_udp.sendto(msg, SEND_ADDR) # add condition data is not transmitted
		while True:
			try:
				dm = DiscoveryMessageStruct(*unpack(MSG_FORMAT, socket_udp.recvfrom(1024)[0]))
				c=Camera()
				c.host = dm
				self.cams.append(c)
			except timeout:
				break
		self.read_cams_settings()
		return len(self.cams)
#### End class ####

if __name__ == "__main__":
	cc = CameraController()
	cc.cams[0].set_up_default(file_conf = "default.conf", debug = True)
	cc.read_cams_settings()
	print cc.cams[0].host.rtsp_port
	print cc.cams[0].host.rtp_addr
