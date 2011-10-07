--[[
LuCI - Lua Configuration Interface

Copyright 2008 Steven Barth <steven@midlink.org>
Copyright 2010 Jo-Philipp Wich <xm@subsignal.org>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

$Id: rrule.lua 7338 2011-07-30 20:02:58Z jow $
]]--

local sys = require "luci.sys"
local dsp = require "luci.dispatcher"

arg[1] = arg[1] or ""

m = Map("firewall", translate("portmap"),
	translate("portmap allows to provide network services in the internal network to an external network."))

m.redirect = dsp.build_url("admin", "network", "firewall")

if not m.uci:get(arg[1]) == "portmap" then
	luci.http.redirect(m.redirect)
	return
end

local has_v2 = nixio.fs.access("/lib/firewall/fw.sh")
local wan_zone = nil

m.uci:foreach("firewall", "zone",
	function(s)
		local n = s.network or s.name
		if n then
			local i
			for i in n:gmatch("%S+") do
				if i == "wan" then
					wan_zone = s.name
					return false
				end
			end
		end
	end)

s = m:section(NamedSection, arg[1], "portmap", "")
s.anonymous = true
s.addremove = false

s:tab("general", translate("General Settings"))
s:tab("advanced", translate("Advanced Settings"))

name = s:taboption("general", Value, "_name", translate("Name"))
name.rmempty = true
name.size = 10

target = s:taboption("general", ListValue, "target", translate("Redirection type"))
target:value("DNAT", "DNAT")


src = s:taboption("general", Value, "src", translate("Source zone"))
src.nocreate = true
src.default = "wan"
src.template = "cbi/firewall_zonelist"

proto = s:taboption("general", ListValue, "proto", translate("Protocol"))
proto.optional = true
proto:value("tcpudp", "TCP+UDP")

dport = s:taboption("general", Value, "src_dport", translate("External port"),
	translate("Match incoming traffic directed at the given " ..
		"destination port or port range on this host"))
dport.datatype = "portrange"
dport:depends("proto", "tcp")
dport:depends("proto", "udp")
dport:depends("proto", "tcpudp")

to = s:taboption("general", Value, "dest_ip", translate("Internal IP address"),
	translate("Redirect matched incoming traffic to the specified " ..
		"internal host"))
to.datatype = "ip4addr"
for i, dataset in ipairs(luci.sys.net.arptable()) do
	to:value(dataset["IP address"])
end

toport = s:taboption("general", Value, "dest_port", translate("Internal port (optional)"),
	translate("Redirect matched incoming traffic to the given port on " ..
		"the internal host"))
toport.optional = true
toport.placeholder = "0-65535"
toport.datatype = "portrange"
toport:depends("proto", "tcp")
toport:depends("proto", "udp")
toport:depends("proto", "tcpudp")

dest = s:taboption("general", Value, "dest", translate("Destination zone"))
dest.nocreate = true
dest.default = "lan"
dest.template = "cbi/firewall_zonelist"



reflection = s:taboption("general", Flag, "reflection", translate("Enable NAT Loopback"))
reflection.rmempty = true
reflection.default = reflection.enabled
reflection:depends({ target = "DNAT", src = wan_zone })
reflection.cfgvalue = function(...)
	return Flag.cfgvalue(...) or "1"
end

return m

