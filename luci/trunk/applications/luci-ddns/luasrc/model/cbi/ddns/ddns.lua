--[[
LuCI - Lua Configuration Interface

Copyright 2008 Steven Barth <steven@midlink.org>
Copyright 2008 Jo-Philipp Wich <xm@leipzig.freifunk.net>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

$Id: ddns.lua 6588 2010-11-29 15:14:50Z jow $
]]--

require("luci.tools.webadmin")

m = Map("ddns", translate("Dynamic DNS"),
	translate("Dynamic DNS allows that your router can be reached with a fixed hostname while having a dynamically changing IP address."))

s = m:section(TypedSection, "goble", "")
s.addremove = false
s.anonymous = true


s:option(Flag, "enabled", translate("Enable"))

s:option(Value, "check_interval",	translate("Check for changed IP every"),translate("interval minute")).default = 10



s = m:section(TypedSection, "service", "")
s.addremove = true
s.anonymous = false

s:option(Flag, "enabled", translate("Enable"))

svc = s:option(ListValue, "service_name", translate("Service"))
svc.rmempty = false

local services = { }
local fd = io.open("/usr/lib/ddns/services", "r")
if fd then
	local ln
	repeat
		ln = fd:read("*l")
		local s = ln and ln:match('^%s*"([^"]+)"')
		if s then services[#services+1] = s end
	until not ln
	fd:close()
end

local v
for _, v in luci.util.vspairs(services) do
	svc:value(v)
end

function svc.cfgvalue(...)
	local v = Value.cfgvalue(...)
	if not v or #v == 0 then
		return "-"
	else
		return v
	end
end

function svc.write(self, section, value)
	if value == "-" then
		m.uci:delete("ddns", section, self.option)
	else
		Value.write(self, section, value)
	end
end

svc:value("-", "-- "..translate("custom").." --")


url = s:option(Value, "update_url", translate("Custom update-URL"))
url:depends("service_name", "-")
url.rmempty = true

neiwang = s:option(Flag, "neiwang", translate("Intranet"),translate("Secondary route setting"))
neiwang:depends("service_name", "3322.org")
neiwang:depends("service_name", "dyndns.org")

neiwang.disabled = 0



s:option(Value, "domain", translate("Hostname")).rmempty = true

s:option(Value, "username", translate("Username")).rmempty = true

pw = s:option(Value, "password", translate("Password"))
pw.rmempty = true
pw.password = true
	
iface = s:option(ListValue, "ip_network", translate("Network"))
iface.rmempty = true
luci.tools.webadmin.cbi_add_networks(iface)

uptime = s:option(DummyValue, "uptime", translate("ddns update time","ddns update time"))
uptime.optional = false
uptime.rmempty = true

ipaddr = s:option(DummyValue, "ipaddr", translate("ip address","ip address"))
ipaddr.optional = false
ipaddr.rmempty = true

local lucierror = luci.sys.lucierror()

return m
