#
# Copyright (C) 2011 OpenWrt.org
#

ralink_set_mac() {
	local part
	local mac

	[ -z $(which maccalc) ] && return

	. /etc/functions.sh

	part=$(find_mtd_part "factory")
	[ -z $part ] && return
#Switch and WLAN
	mac=$(dd bs=1 skip=4 count=6 if=$part 2>/dev/null | maccalc bin2mac)
	[ -z $mac ] && return

	mac=$(maccalc or "$mac" "02:00:00:00:00:00")
	ifconfig eth0 hw ether $mac 2>/dev/null
#LAN MAC
	mac=$(dd bs=1 skip=39 count=6 if=$part 2>/dev/null | maccalc bin2mac)
	[ -z $mac ] && return

	mac=$(maccalc or "$mac" "02:00:00:00:00:00")
	ifconfig eth0.1 hw ether $mac 2>/dev/null
#WAN MAC
	mac=$(dd bs=1 skip=45 count=6 if=$part 2>/dev/null | maccalc bin2mac)
	[ -z $mac ] && return

	mac=$(maccalc or "$mac" "02:00:00:00:00:00")
	ifconfig eth0.2 hw ether $mac 2>/dev/null
}

preinit_set_mac_address() {
	. /lib/ramips.sh

	case $(ramips_board_name) in
	nw718)
		ralink_set_mac
		;;
	rt-n13)
		ralink_set_mac
		;;
	hg255d)
		ralink_set_mac
		;;
	esac
}

boot_hook_add preinit_main preinit_set_mac_address
