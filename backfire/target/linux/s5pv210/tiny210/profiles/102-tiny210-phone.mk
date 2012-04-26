#
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/tiny210-phone
  NAME:=TINY210 (phone)
  PACKAGES:=xserver-xorg xf86-video-glamo xf86-input-tslib enlightenment fso-gsm0710muxd fso-frameworkd fso-gpsd paroli wireless-tools block-hotplug uhttpd wpad wpa-supplicant python
endef

define Profile/tiny210-phone/Description
	Package set with accelerated x11-environment and phone-suite (paroli)
endef
$(eval $(call Profile,tiny210-phone))

