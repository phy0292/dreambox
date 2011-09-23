module("luci.controller.admin.sattv", package.seeall)

function index()


	local page

	page = node("admin", "Others")
	page.target = alias("admin", "Others", "sattv")
	page.title  = _("Others")
	page.order  = 70
	page.index  = true	
	
--	entry({"admin", "Others"}, cbi("sattv/epg"), i18n("Others"), 70)
		
	if nixio.fs.access("/etc/config/epg") then
		entry({"admin", "Others", "sattv"}, cbi("sattv/epg"), _("sattv"), 1).i18n = "diskapply"
	end

	if nixio.fs.access("/etc/config/epg") then
		entry({"admin", "Others", "sattv", "epg"}, cbi("sattv/epg"), _("EPG"), 11).i18n = "diskapply"
	end
	
  if nixio.fs.access("/etc/config/oscam") then
	  entry({"admin", "Others", "sattv", "oscam"}, cbi("sattv/oscam"), _("OSCAM"), 12).i18n = "diskapply"
	end

end
