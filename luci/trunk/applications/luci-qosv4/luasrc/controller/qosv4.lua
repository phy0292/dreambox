module("luci.controller.qosv4", package.seeall)

function index()

	if nixio.fs.access("/etc/config/qosv4") then
	local page 
	page = entry({"admin", "network", "qosv4"}, cbi("qosv4"), _("QOSv4"),55)
	page.i18n = "qosv4"
	page.dependent = true
	end

end
