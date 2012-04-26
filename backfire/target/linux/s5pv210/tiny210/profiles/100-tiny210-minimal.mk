#
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/tiny210-minimal
  NAME:=TINY210 (minimal)
  PACKAGES:=
endef

define Profile/tiny210-minimal/Description
	None any other Packages(not default) set compatible with the TINY210 hardware
endef
$(eval $(call Profile,tiny210-minimal))

