def pp(req):
	for key in req.keys():
		print( "%s: %s" % (key, req[key][0]))

def grab(c):
	get = {"app":"get"}
	print "video/video.php"
	pp(c.send_request("video/video.php", **get))
	
	print "\naudio/audio.php"
	pp(c.send_request("audio/audio.php", **get))
	
	print "\nvideo/image.php"
	print "group: basic"
	pp( c.send_request("video/image.php", **dict(group="basic", **get)))
	print "group: osd"
	pp( c.send_request("video/image.php", **dict(group="osd", **get)))
	print "group: ae"
	pp( c.send_request("video/image.php", **dict(group="ae", **get)))
	print "group: awb"
	pp( c.send_request("video/image.php", **dict(group="awb", **get)))
	print "group: af"
	pp( c.send_request("video/image.php", **dict(group="af", **get)))
	print "group: dnn"
	pp( c.send_request("video/image.php", **dict(group="dnn", **get)))
	print "group: wdr"
	pp( c.send_request("video/image.php", **dict(group="wdr", **get)))
	print "group: blc"
	pp( c.send_request("video/image.php", **dict(group="blc", **get)))
	print "group: nr"
	pp( c.send_request("video/image.php", **dict(group="nr", **get)))
	print "group: corridor"
	pp( c.send_request("video/image.php", **dict(group="corridor", **get)))
	print "group: ldc"
	pp( c.send_request("video/image.php", **dict(group="ldc", **get)))
	
	print "\nvideo/pmask.php"
	pp( c.send_request("video/pmask.php", **get))
	
	print "\nvideo/digital_zoom.php"
	pp( c.send_request("video/digital_zoom.php", **get))
	
	print "\nanalytic/dis.php"
	pp( c.send_request("analytic/dis.php", **get))
	
	print "\nanalytic/tamper.php"
	pp( c.send_request("analytic/tamper.php", **get))
	
	print "\nevent/motion.php"
	pp( c.send_request("event/motion.php", **get))
	
	print "\nevent/event_trigger.php"
	print "group: alarmin"
	pp( c.send_request("event/event_trigger.php", **dict(group="alarmin", **get)))
	print "group: onboot"
	pp( c.send_request("event/event_trigger.php", **dict(group="onboot", **get)))
	print "group: trigger"
	pp( c.send_request("event/event_trigger.php", **dict(group="trigger", **get)))
	print "group: netloss"
	pp( c.send_request("event/event_trigger.php", **dict(group="netloss", **get)))
	
	print "\nevent/event_action.php"
	print "group: alarmout"
	pp( c.send_request("event/event_action.php", **dict(group="alarmout", **get)))
	print "group: email"
	pp( c.send_request("event/event_action.php", **dict(group="email", **get)))
	print "group: ftp"
	pp( c.send_request("event/event_action.php", **dict(group="ftp", **get)))
	print "group: video"
	pp( c.send_request("event/event_action.php", **dict(group="video", **get)))
	print "group: preset"
	pp( c.send_request("event/event_action.php", **dict(group="preset", **get)))
	
	print "\nevent/event_rule.php"
	pp( c.send_request("event/event_rule.php", **get))
	
	print "\nsystem/security.php"
	print "group: user"
	pp( c.send_request("system/security.php", **dict(group="user", **get)))
	print "group: https"
	pp( c.send_request("system/security.php", **dict(group="https", **get)))
	print "group: filter"
	pp( c.send_request("system/security.php", **dict(group="filter", **get)))
	print "group: onvif"
	pp( c.send_request("system/security.php", **dict(group="onvif", **get)))
	
	print "\nsystem/time.php"
	pp( c.send_request("system/time.php", **get))
	
	print "\nsystem/network.php"
	print "group: tcpip"
	pp( c.send_request("system/network.php", **dict(group="tcpip", **get)))
	print "group: ddns"
	pp( c.send_request("system/network.php", **dict(group="ddns", **get)))
	print "group: rtp"
	pp( c.send_request("system/network.php", **dict(group="rtp", **get)))
	print "group: upnp"
	pp( c.send_request("system/network.php", **dict(group="upnp", **get)))
	print "group: zeroconf"
	pp( c.send_request("system/network.php", **dict(group="zeroconf", **get)))
	
	print "\nptz/preset.php"
	pp( c.send_request("ptz/preset.php", **get))
	
	print "\nrecord/record.php"
	print "group: record"
	pp( c.send_request("record/record.php", **dict(group="record", **get)))
	print "group: storage"
	pp( c.send_request("record/record.php", **dict(group="storage", **get)))
	
	print "\nconfig.txt"
	pp( c.send_request("config.txt"))