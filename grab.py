def pp(req):
	for key in req.keys():
		print( "%s: %s" % (key, req[key][0]))

def grab(c):
	get = {"app":"get"}
	print "video/video.php"
	pp(c.get_req(dict(path="video/video.php")))
	
	print "\naudio/audio.php"
	pp(c.get_req(dict(path="audio/audio.php")))
	
	print "\nvideo/image.php"
	print "group: basic"
	path="video/image.php"
	pp( c.get_req(**dict(path=path, params=[(group, "basic")])))
	print "group: osd"
	pp( c.get_req(**dict(path=path, group="osd")))
	print "group: ae"
	pp( c.get_req(**dict(path=path, group="ae")))
	print "group: awb"
	pp( c.get_req(**dict(path=path, group="awb")))
	print "group: af"
	pp( c.get_req(**dict(path=path, group="af")))
	print "group: dnn"
	pp( c.get_req(**dict(path=path, group="dnn")))
	print "group: wdr"
	pp( c.get_req( **dict(path=path, group="wdr")))
	print "group: blc"
	pp( c.get_req(**dict(path=path, group="blc")))
	print "group: nr"
	pp( c.get_req(**dict(path=path, group="nr")))
	print "group: corridor"
	pp( c.get_req(**dict(path=path, group="corridor")))
	print "group: ldc"
	pp( c.get_req(**dict(path=path, group="ldc")))
	
	print "\nvideo/pmask.php"
	pp(c.get_req(dict(path="video/pmask.php")))
	
	print "\nvideo/digital_zoom.php"
	pp( c.get_req(dict(path="video/digital_zoom.php")))
	
	print "\nanalytic/dis.php"
	pp( c.get_req(dict(path="analytic/dis.php")))
	
	print "\nanalytic/tamper.php"
	pp( c.get_req(dict(path="analytic/tamper.php")))
	
	print "\nevent/motion.php"
	pp( c.get_req("event/motion.php"))
	
	print "\nevent/event_trigger.php"
	print "group: alarmin"
	pp( c.get_req("event/event_trigger.php", **dict(group="alarmin")))
	print "group: onboot"
	pp( c.get_req("event/event_trigger.php", **dict(group="onboot")))
	print "group: trigger"
	pp( c.get_req("event/event_trigger.php", **dict(group="trigger")))
	print "group: netloss"
	pp( c.get_req("event/event_trigger.php", **dict(group="netloss")))
	
	print "\nevent/event_action.php"
	print "group: alarmout"
	pp( c.get_req("event/event_action.php", **dict(group="alarmout")))
	print "group: email"
	pp( c.get_req("event/event_action.php", **dict(group="email")))
	print "group: ftp"
	pp( c.get_req("event/event_action.php", **dict(group="ftp")))
	print "group: video"
	pp( c.get_req("event/event_action.php", **dict(group="video")))
	print "group: preset"
	pp( c.get_req("event/event_action.php", **dict(group="preset")))
	
	print "\nevent/event_rule.php"
	pp( c.get_req("event/event_rule.php"))
	
	print "\nsystem/security.php"
	print "group: user"
	pp( c.get_req("system/security.php", **dict(group="user")))
	print "group: https"
	pp( c.get_req("system/security.php", **dict(group="https")))
	print "group: filter"
	pp( c.get_req("system/security.php", **dict(group="filter")))
	print "group: onvif"
	pp( c.get_req("system/security.php", **dict(group="onvif")))
	
	print "\nsystem/time.php"
	pp( c.get_req("system/time.php"))
	
	print "\nsystem/network.php"
	print "group: tcpip"
	pp( c.get_req("system/network.php", **dict(group="tcpip")))
	print "group: ddns"
	pp( c.get_req("system/network.php", **dict(group="ddns")))
	print "group: rtp"
	pp( c.get_req("system/network.php", **dict(group="rtp")))
	print "group: upnp"
	pp( c.get_req("system/network.php", **dict(group="upnp")))
	print "group: zeroconf"
	pp( c.get_req("system/network.php", **dict(group="zeroconf")))
	
	print "\nptz/preset.php"
	pp( c.get_req("ptz/preset.php"))
	
	print "\nrecord/record.php"
	print "group: record"
	pp( c.get_req("record/record.php", **dict(group="record")))
	print "group: storage"
	pp( c.get_req("record/record.php", **dict(group="storage")))
	
	print "\nconfig.txt"
	pp( c.get_req("config.txt"))