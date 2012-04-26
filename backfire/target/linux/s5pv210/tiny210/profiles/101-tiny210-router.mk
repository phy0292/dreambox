#
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/tiny210-router
  NAME:=TINY210 (router)
  PACKAGES:=wireless-tools  block-hotplug uhttpd wpad wpa-supplicant kmod-usb-core kmod-usb-ohci  kmod-usb-storage kmod-fs-ext4 kmod-fs-ext3 kmod-fs-ext2  kmod-fs-vfat  kmod-nls-utf8 kmod-nls-cp437  kmod-nls-iso8859-1
endef

define Profile/tiny210-router/Description
	Package set compatible with the TINY210 hardware as a Router.
endef
$(eval $(call Profile,tiny210-router))

