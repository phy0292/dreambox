#
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/tiny210-qtopia
  NAME:=TINY210 (qtopia)
  PACKAGES:=Tslib Qtopia Filebrowser MurphyPinyin Konqueror libsqlite3 Zbedic
endef

define Profile/tiny210-qtopia/Description
	Packages are set as a qtopia-2.2.0 PDA compatible with the TINY210 hardware
endef
$(eval $(call Profile,tiny210-qtopia))

