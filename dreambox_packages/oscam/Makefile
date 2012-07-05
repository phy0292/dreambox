#
# Copyright (C) 2011 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=oscam
PKG_REV:=37d2029796252ed0a4f2808636fd7607bbcfbe63
PKG_VERSION:=7068
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=git://github.com/nx111/oscam-nx111.git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/oscam
  SECTION:=custom
  CATEGORY:=Custom packages
  DEPENDS:=+libopenssl +libpthread 
  TITLE:=OSCam is an Open Source Conditional Access Module software
  URL:=http://streamboard.gmc.to:8001/
endef

define Package/oscam/description
  OSCam is an Open Source Conditional Access Module software nx111 mod
endef

CMAKE_OPTIONS += \
		-DCS_CONFDIR=/etc/oscam

define Build/Prepare
	$(call Build/Prepare/Default)
	sed -i 's:(svnversion.*:echo "$(PKG_REV)":g'  $(PKG_BUILD_DIR)/config.sh

endef


define Package/oscam/install

	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/oscam $(1)/usr/bin/


endef

$(eval $(call BuildPackage,oscam))