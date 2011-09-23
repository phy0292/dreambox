--[[

config 'setting' 
	option 'enable' '1'

config 'conf' 
	option 'global_nice' '-1'
	option 'global_logfile' '/var/oscam/oscam.log'
	option 'global_clientmaxidle' '300'
	option 'global_resolvegethostbyname' '1'
	option 'webif_httpport' '8888'
	option 'webif_httpuser' 'test'
	option 'webif_httppwd' 'test'
	option 'webif_httpallowed' '192.168.3.1-192.168.3.254'
	option 'cccam_port' '7788'
	option 'cccam_version' '2.1.4'
	option 'cccam_ignorereshare' '1'
	
config 'server' 
	option 'label' 'remote'
	option 'protocol' 'cccam'
	option 'device' 'dm500.3322.org,35478'
	option 'account' 'username,password'	
	option	group  1
	option  fallback  1
	option  cccversion  2.1.4

config 'user' 
	option 'user' '001'
	option 'pwd' '001'
	option 'uniq' '1'
	option 'group' '1'
	option 'au' '1'
	

]]--



require("luci.sys")
local uci = require "luci.model.uci".cursor()
local lanipaddr = uci:get("network", "lan", "ipaddr") or "192.168.1.1"
local oscamport = uci:get_first("oscam", "conf", "webif_httpport") or "8899"

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


s = m:section(TypedSection, "conf", translate("config","config"))
s.anonymous = true
s.addremove = false

s.addremove = false

s:option(DummyValue,"oscamweb" ,translate("<a target=\"_blank\" href='http://"..lanipaddr..":"..oscamport.."'>OSCAM Web Intelface</a> "),translate("Open the oscam Web"))


logenable = s:option(Flag, "logenable", translate("logenable", "logenable"))
logenable.default = false
logenable.optional = false
logenable.rmempty = false

global_logfile = s:option(Value, "global_logfile", translate("global_logfile","global_logfile"),
translate("global_logfile_desc","global_logfile_desc"))
global_logfile.optional = false
global_logfile.rmempty = false


global_maxlogsize = s:option(Value, "global_maxlogsize", translate("global_maxlogsize","global_maxlogsizee"),
translate("global_maxlogsize_desc","global_maxlogsize_desc"))
global_maxlogsize.optional = false
global_maxlogsize.rmempty = false


readerautoloadbalance = s:option(Flag, "readerautoloadbalance", translate("readerautoloadbalance", "readerautoloadbalance"),
translate("readerautoloadbalance_desc", "readerautoloadbalance_desc"))
readerautoloadbalance.default = false
readerautoloadbalance.optional = false
readerautoloadbalance.rmempty = false



webifenable = s:option(Flag, "webifenable", translate("webifenable", "webifenable"))
webifenable.default = false
webifenable.optional = false
webifenable.rmempty = false

webif_httpport = s:option(Value, "webif_httpport", translate("webif_httpport","webif_httpport"),
translate("webif_httpport_desc","webif_httpport_desc"))
webif_httpport.optional = false
webif_httpport.rmempty = false

webif_httpuser = s:option(Value, "webif_httpuser", translate("webif_httpuser","webif_httpuser"),
translate("webif_httpuser_desc","webif_httpuser_desc"))
webif_httpuser.optional = false
webif_httpuser.rmempty = false

webif_httppwd = s:option(Value, "webif_httppwd", translate("webif_httppwd","webif_httppwd"),
translate("webif_httppwd_desc","webif_httppwd_desc"))
webif_httppwd.optional = false
webif_httppwd.rmempty = false

webif_httpallowed = s:option(Value, "webif_httpallowed", translate("webif_httpallowed","webif_httpallowed"),
translate("webif_httpallowed_desc","webif_httpallowed_desc"))
webif_httpallowed.optional = false
webif_httpallowed.rmempty = false


cccam_port = s:option(Value, "cccam_port", translate("cccam_port","cccam_port"),
translate("cccam_port_desc","cccam_port_desc"))
cccam_port.optional = false
cccam_port.rmempty = false

cccam_version = s:option(Value, "cccam_version", translate("cccam_version","cccam_version"),
translate("cccam_version_desc","cccam_version_desc"))
cccam_version.optional = false
cccam_version.rmempty = false

cccam_ignorereshare = s:option(Value, "cccam_ignorereshare", translate("cccam_ignorereshare","cccam_ignorereshare"),
translate("cccam_ignorereshare_desc","cccam_ignorereshare_desc"))
cccam_ignorereshare.optional = false
cccam_ignorereshare.rmempty = false


	
s = m:section(TypedSection, "server", translate("server","server"))
s.template = "cbi/tblsection"
s.anonymous = true
s.addremove = true	
	
	
cenable = s:option(Flag, "cenable", translate("enable", "enable"))
cenable.default = false
cenable.optional = false
cenable.rmempty = false

cccam_label = s:option(Value, "cccam_label", translate("cccam_label","cccam_label"),
translate("cccam_label_desc","cccam_label_desc"))
cccam_label.optional = false
cccam_label.rmempty = false

cccam_account = s:option(Value, "cccam_account", translate("cccam_account","cccam_account"),
translate("cccam_account_desc","cccam_account_desc"))
cccam_account.optional = false
cccam_account.rmempty = false




s = m:section(TypedSection, "user", translate("user","user"),
translate("user_desc","user_desc"))
s.template = "cbi/tblsection"
s.anonymous = true
s.addremove = true	


uenable = s:option(Flag, "uenable", translate("enable", "enable"))
uenable.default = false
uenable.optional = false
uenable.rmempty = false

user = s:option(Value, "user", translate("user","user"),
translate("user_desc","user_desc"))
user.optional = false
user.rmempty = false

pwd = s:option(Value, "pwd", translate("pwd","pwd"),
translate("pwd_desc","pwd_desc"))
pwd.optional = false
pwd.rmempty = false

local lucierror = luci.sys.lucierror()

return m

