--[[
LuCI - Lua Configuration Interface

Copyright 2011 flyzjhz <flyzjhz@gmail.com>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

]]--


require("luci.sys")
local uci = require "luci.model.uci".cursor()
local lanipaddr = uci:get("network", "lan", "ipaddr") or "192.168.1.1"
local oscamport = luci.util.exec("cat /usr/oscam |grep httpport |cut -d \"=\" -f2 |sed s/\ //g") or "8899"

m = Map("oscam", translate("OSCAM","OSCAM"),translate("oscam desc",
"oscam for openwrt"))

s = m:section(TypedSection, "setting", translate("set","settings"))
s.anonymous = true
s.addremove = false

enable = s:option(Flag, "enable", translate("enable", "enable"))
enable.default = false
enable.optional = false
enable.rmempty = false

interval = s:option(Value, "interval", translate("interval","interval"),
translate("interval_desc","interval_desc"))
interval.optional = false
interval.rmempty = false
interval.default = 30

s:option(DummyValue,"oscamweb" ,translate("<a target=\"_blank\" href='http://"..lanipaddr..":"..oscamport.."'>OSCAM Web Intelface</a> "),translate("Open the oscam Web"))



return m

