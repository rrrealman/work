from ctypes import Structure, c_uint, c_char, sizeof, addressof, memset
from socket import gethostname, gethostbyname, socket, AF_INET, SOCK_DGRAM, SOL_SOCKET, SO_REUSEADDR, SO_BROADCAST

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
