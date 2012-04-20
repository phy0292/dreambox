#
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/tiny210-minimal
  NAME:=TINY210 (minimal)
  PACKAGES:=kmod-usb-ohci kmod-usb-storage  wireless-tools  block-hotplug uhttpd wpad wpa-supplicant kmod-fs-ext4 kmod-fs-ext3 kmod-fs-ext2  kmod-fs-vfat  kmod-nls-utf8 kmod-nls-cp437  kmod-nls-iso8859-1
endef

define Profile/tiny210-minimal/Description
	minimal Package set compatible with the TINY210 hardware
endef
$(eval $(call Profile,tiny210-minimal))

