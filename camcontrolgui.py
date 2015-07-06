#!/usr/bin/python

# Menubar:
# 	Path to config file
# 	Exit
# Fields to read/set:
# 	resolution
# 	fps
# 	bitrate
# 	ratecontrol
# Buttons:
# 	Set button
# 	Read button
# Statusbar:
# 	Set/get results

import wx
from cam_control import CameraController

class MainWindow(wx.Frame):
	def __init__(self, parent, title):
		wx.Frame.__init__(self, parent, title = title)

		self.InitUI()
		self.Center(wx.CENTER_ON_SCREEN)
		self.Show(True)
		self.CCInit()

	def InitUI(self):

		self.SetSizeHints(270, 350, 270, 350) # Window is not resizeable 

		panel   = wx.Panel(self)

		lbl_cf  = wx.StaticText(panel, label = "Configuration file: ")
		lbl_pcf = wx.StaticText(panel, label = "path/to/file.conf")
		cf_hbox = wx.BoxSizer(wx.HORIZONTAL)
		cf_hbox.AddMany([(lbl_cf), (lbl_pcf)])

		self.ReadyCameras = wx.TextCtrl(panel, size = (160, -1), style = wx.TE_READONLY)

		lbl_res = wx.StaticText(panel, label = "Resolution")
		lbl_fps = wx.StaticText(panel, label = "FPS")
		lbl_br  = wx.StaticText(panel, label = "Bitrate")
		lbl_rc  = wx.StaticText(panel, label = "Rate control")
		res_values = ["2048x1536", "1920x1440", "1600x1200", "1280x960", "800x600", "640x480", "320x240"]
		fps_values = ["30", "25", "20", "15", "12", "10", "6", "5", "4", "3", "2", "1"]
		rc_values  = ["cbr", "vbr"]
		self.cb_res = wx.ComboBox(panel, size = (120, -1), choices = res_values, style = wx.CB_READONLY) # + wx.SpinButton by implementing TextCtrlSpinning class
		self.cb_fps = wx.ComboBox(panel, size = (120, -1), choices = fps_values, style = wx.CB_READONLY)
		self.sc_br  = wx.SpinCtrl(panel, size = (120, -1), min = 100, max = 12000)
		self.cb_rc  = wx.ComboBox(panel, size = (120, -1), choices = rc_values, style = wx.CB_READONLY)
		fgs = wx.FlexGridSizer(4, 2, 9, 15)
		fgs.AddMany([(lbl_res, 0, wx.ALIGN_CENTER_VERTICAL), (self.cb_res, 1, wx.EXPAND),
					 (lbl_fps, 0, wx.ALIGN_CENTER_VERTICAL), (self.cb_fps, 1, wx.EXPAND),
					 (lbl_br,  0, wx.ALIGN_CENTER_VERTICAL), (self.sc_br,  1, wx.EXPAND),
					 (lbl_rc,  0, wx.ALIGN_CENTER_VERTICAL), (self.cb_rc,  1, wx.EXPAND)])

		btn_set = wx.Button(panel, label = "Set", size = (70, 30))
		btn_get = wx.Button(panel, label = "Get", size = (70, 30))
		btn_set.Bind(wx.EVT_BUTTON, self.OnSetButton)
		btn_get.Bind(wx.EVT_BUTTON, self.OnGetButton)
		btn_box = wx.BoxSizer(wx.HORIZONTAL)
		btn_box.AddMany([(btn_set, 0, wx.RIGHT, 20), (btn_get)])

		vbox    = wx.BoxSizer(wx.VERTICAL)
		vbox.AddMany([(cf_hbox, 0, wx.BOTTOM, 10), (self.ReadyCameras, 0, wx.ALIGN_CENTER_HORIZONTAL|wx.TOP|wx.BOTTOM, 10), (fgs, 1, wx.EXPAND), (btn_box, 0, wx.ALIGN_RIGHT)]),

		gen_box = wx.BoxSizer(wx.HORIZONTAL)
		gen_box.Add(vbox, flag = wx.ALL|wx.EXPAND, border = 15)
		panel.SetSizer(gen_box)
		
		filemenu = wx.Menu()
		self.Bind(wx.EVT_MENU,          self.OnConfFile,  filemenu.Append(wx.ID_FILE, "Configuration file", "Point path to configuration file"))
		self.Bind(wx.EVT_MENU,          self.OnExit,      filemenu.Append(wx.ID_EXIT, "Exit",               "Quit the program"))
		# self.Bind(wx.EVT_WINDOW_CREATE, self.OnStart)

		menubar = wx.MenuBar()
		menubar.Append(filemenu, "File")
		self.SetMenuBar(menubar)

		self.CreateStatusBar()

	def CCInit(self):
		self.cc = CameraController(conf_file = "default.conf")
		self.cb_res.SetValue(self.cc.video.video_enc1_res)
		# self.cb_fps   self.cc.video.video_enc1_fps
		# self.sc_br    self.cc.video.video_enc1_bitrate
		# self.cb_rc    self.cc.video.video_enc1_ratecontrol
		if self.cc.ready:
			self.ReadyCameras.SetValue("Cameras are ready")
		else:
			self.ReadyCameras.SetValue("Cameras are not ready")

	def OnSetButton(self, event):
		pass
		# cc.SetUpCameras()		

	def OnGetButton(self, event):
		print "OnGetButton"

	def OnConfFile(self, event):
		print "OnFile, with dict %s" % event.__dict__

	def OnExit(self, event):
		self.Close(True)

app=wx.App()
frame = MainWindow(None, "Camera controller")
app.MainLoop()