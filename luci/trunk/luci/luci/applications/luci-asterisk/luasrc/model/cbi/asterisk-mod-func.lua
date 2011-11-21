--[[
LuCI - Lua Configuration Interface

Copyright 2008 Steven Barth <steven@midlink.org>
Copyright 2008 Jo-Philipp Wich <xm@leipzig.freifunk.net>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

$Id: asterisk-mod-func.lua 3618 2008-10-23 02:25:26Z jow $
]]--

cbimap = Map("asterisk", "asterisk", "")

module = cbimap:section(TypedSection, "module", "Modules", "")
module.anonymous = true

func_callerid = module:option(ListValue, "func_callerid", "Caller ID related dialplan functions", "")
func_callerid:value("yes", "Load")
func_callerid:value("no", "Do Not Load")
func_callerid:value("auto", "Load as Required")
func_callerid.rmempty = true

func_enum = module:option(ListValue, "func_enum", "ENUM Functions", "")
func_enum:value("yes", "Load")
func_enum:value("no", "Do Not Load")
func_enum:value("auto", "Load as Required")
func_enum.rmempty = true

func_uri = module:option(ListValue, "func_uri", "URI encoding / decoding functions", "")
func_uri:value("yes", "Load")
func_uri:value("no", "Do Not Load")
func_uri:value("auto", "Load as Required")
func_uri.rmempty = true


return cbimap
