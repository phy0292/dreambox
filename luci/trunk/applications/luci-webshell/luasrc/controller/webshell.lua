module("luci.controller.webshell", package.seeall)

function index()
luci.i18n.loadc("base")
local i18n = luci.i18n.translate
	page = entry({"admin", "system", "cmd_run"}, call("cmd_run"), nil)
	page.leaf = true

	page = entry({"admin", "system", "cmd_read"}, call("read_to_json"), nil)
	page.leaf = true

	page = node("admin", "system", "WebShell")
	page.target = template("webshell")
	page.title  = i18n("WebShell")
	page.order  = 60
end

function string.starts(String,Start)
   return string.sub(String,1,string.len(Start))==Start
end

function cmd_run()
	local re =""
	local path = luci.dispatcher.context.requestpath
	local rv   = { }
	local cmd = luci.http.formvalue("cmd")
	local path = luci.http.formvalue("path")
	local runcmd="cd "..path.."&&"..cmd

	os.execute(runcmd.." 2>>/tmp/web_shell_output 1>>/tmp/web_shell_output &")
	local pwdcmd = "cd "..path.."&& pwd 2>&1"
	if string.starts(cmd,"cd") then
		if cmd=="cd" then cmd="cd /root" end
		pwdcmd = "cd "..path.."&&"..cmd.."&& pwd 2>&1"
	end
	local shellpipe = io.popen(pwdcmd,"r")
	local newpath = shellpipe:read("*a")
	shellpipe:close()

	if not string.starts(newpath,"/") then 
		newpath=path
	end

	local pathcmd = io.popen("ls "..newpath.."2>&1","r")
	local ls = pathcmd:read("*a")
	pathcmd:close()
	
	ls = string.gsub(ls, "\n", ",")
	rv[#rv+1]=read();
	rv[#rv+1]=newpath
	rv[#rv+1]=ls
	
	if #rv > 0 then
		luci.http.prepare_content("application/json")
		luci.http.write_json(rv)
				return
	end

	luci.http.status(404, "No such device")
end

function read_to_json()
	local re =""
	local path = luci.dispatcher.context.requestpath
	local rv   = { }
	
	rv[#rv+1]=read();

	if #rv > 0 then
		luci.http.prepare_content("application/json")
		luci.http.write_json(rv)
				return
	end

	luci.http.status(404, "No such device")
end

function read()
	re = {}
	count=0;
	local f = io.open("/tmp/web_shell_output","r")
	if f~=nil then 
		for line in f:lines() do 
			re[#re+1]=line 
		end
		f:close()
	end
	
	if #re>1 then 
		os.execute("echo > /tmp/web_shell_output &") 
		return table.concat(re,"\r\n")
	end
	return ""
end