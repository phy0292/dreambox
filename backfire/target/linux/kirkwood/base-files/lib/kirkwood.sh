#!/bin/sh
#
# Copyright (C) 2009 OpenWrt.org
#

kirkwood_board_name() {
	local machine
	local name

	machine=$(awk 'BEGIN{FS="[ \t]+:[ \t]"} /Hardware/ {print $2}' /proc/cpuinfo)

	case "$machine" in

	'DDNAS Wireless')
		name="ddnas"
		;;
	esac

	echo $name
}
