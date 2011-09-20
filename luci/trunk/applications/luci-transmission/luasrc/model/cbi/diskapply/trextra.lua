require("luci.tools.webadmin")

--[[
config 'trextraqueue'
	option 'queue_enabled' '1'
	option 'queue_max_downloadings' '1'
	option 'queue_max_seedings' '5'
	option 'queue_interval' '30'
	
config 'trextraemail'
	option 'email_enable' '1'
	option 'smtp_address' 'smtp.163.com'      
	option 'smtp_user' 'abcdef'
	option 'smtp_password' '123456' 
	   
config 'mail_address'
	option 'address' '138888888@139.com'
	
config 'mail_address'
	option 'address' 'openwrt@163.com'

]]--

m = Map("trextra", translate("Transmission Extra","Transmission Extra"),
                    translate("Transmission Extra desc","Transmission Extra desc"))

s = m:section(TypedSection, "trextraqueueemail", translate("Trextra set","transmission_Extra setting"))
s.anonymous = true
s.addremove = false

s:tab("trextraqueue", translate("queue set"))
s.anonymous = true
s.addremove = false
s:tab("trextraemail", translate("email set","transmission email setting"))
s.anonymous = true
s.addremove = false

email_enable = s:taboption("trextraemail", Flag, "email_enable", translate("Email enable", "Email enabled"))
email_enable.default = false
email_enable.optional = false
email_enable.rmempty = false

from_address = s:taboption("trextraemail", Value, "from_address", translate("from_address","from_address"))
from_address.optional = false
from_address.rmempty = false

smtp_address = s:taboption("trextraemail", Value, "smtp_address", translate("smtp_address","smtp_address"))
smtp_address.optional = false
smtp_address.rmempty = false

smtp_user = s:taboption("trextraemail", Value, "smtp_user", translate("smtp_user","smtp_user"))
smtp_user.optional = false
smtp_user.rmempty = false

smtp_password = s:taboption("trextraemail", Value, "smtp_password", translate("smtp_password","smtp_password"))
smtp_password.optional = false
smtp_password.rmempty = false
smtp_password.password = true

queue_enabled = s:taboption("trextraqueue", Flag, "queue_enabled", translate("queue_enabled", "queue enabled"))
queue_enabled.default = false
queue_enabled.optional = false
queue_enabled.rmempty = false

queue_max_downloadings= s:taboption("trextraqueue", Value, "queue_max_downloadings", translate("queue_max_downloadings","queue max downloadings"),
          translate("queue_max_downloadings_desc","queue max downloadings num"))
queue_max_downloadings.optional = false
queue_max_downloadings.rmempty = false

queue_max_seedings= s:taboption("trextraqueue", Value, "queue_max_seedings", translate("queue_max_seedings","queue max seedings"),
          translate("queue_max_seedings_desc","queue max downloadings num"))
queue_max_seedings.optional = false
queue_max_seedings.rmempty = false

queue_interval= s:taboption("trextraqueue", Value, "queue_interval", translate("queue_interval","queue interval"),
          translate("queue_interval_desc","queue interval default 30 min"))
queue_interval.optional = false
queue_interval.rmempty = false



s = m:section(TypedSection, "mail_address", translate("mail_address","mail_address"),
 translate("mail_address_desc","mail_address_desc"))

s.template = "cbi/tblsection"
s.anonymous = true
s.addremove = true

use_enable = s:option(Flag, "use_enable", translate("Use Email", "Use Email"))
use_enable.default = false
use_enable.optional = false
use_enable.rmempty = false

finashed = s:option(Flag, "finish", translate("finished", "finished"))
finashed.default = false
finashed.optional = false
finashed.rmempty = false

low_speed = s:option(Value, "low_speed", translate("low_speed","low_speed"))
low_speed.optional = false
low_speed.rmempty = false


address = s:option(Value, "address", translate("receive address","receive address"))
address.optional = false
address.rmempty = false

return m
