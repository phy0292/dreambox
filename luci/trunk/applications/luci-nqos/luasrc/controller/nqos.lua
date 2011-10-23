--[[
LuCI - Lua Configuration Interface

Copyright 2008 Steven Barth <steven@midlink.org>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

$Id: qos.lua 7362 2011-08-12 13:16:27Z jow $
]]--

module("luci.controller.nqos", package.seeall)

function index()
	if not nixio.fs.access("/etc/config/nqos") then
		return
	end
	
	local page

	page = entry({"admin", "network", "nqos"}, cbi("nqos/nqos"), _("N_QoS"))
	page.i18n = "nqos"
	page.dependent = true
end
