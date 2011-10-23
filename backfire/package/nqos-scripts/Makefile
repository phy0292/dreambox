# 
# Copyright (C) 2006-2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nqos-scripts
PKG_VERSION:=1.0.0
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/nqos-scripts
  SECTION:=utils
  CATEGORY:=Base system
  DEPENDS:=+tc +kmod-sched +iptables +iptables-mod-filter +iptables-mod-ipopt +iptables-mod-conntrack-extra +kmod-ifb +iptables-mod-opendpi
  TITLE:=New QoS scripts use opendpi
  PKGARCH:=all
endef

define Package/qos-scripts/description
 opendpi support
 A set of scripts that abstract QoS configuration into a simple 
 configuration file supporting stanzas that specify any number of QoS 
 entries.
endef

define Package/nqos-scripts/conffiles
/etc/config/nqos
endef

define Build/Prepare
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/nqos-scripts/install
	$(INSTALL_DIR) $(1)
	$(CP) ./files/* $(1)/
endef

$(eval $(call BuildPackage,nqos-scripts))
