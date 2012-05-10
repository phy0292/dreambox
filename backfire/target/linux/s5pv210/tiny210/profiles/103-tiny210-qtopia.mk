#
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/tiny210-qtopia
  NAME:=TINY210 (qtopia)
  PACKAGES:=ucitrigger udev wireless-tools  block-hotplug uhttpd wpad wpa-supplicant \
          kmod-usb-core kmod-usb-ohci  kmod-usb-storage kmod-usb-storage-extras kmod-usb2 \
          kmod-fs-ext4 kmod-fs-ext3 kmod-fs-ext2  kmod-fs-vfat \
          kmod-nls-utf8 kmod-nls-cp437  kmod-nls-iso8859-1 \
          openssh-client openssh-client-utils openssh-server \
          TSLIB Qtopia
endef

define Profile/tiny210-qtopia/Description
	Packages are set as a qtopia-2.2.0 PDA compatible with the TINY210 hardware
endef
$(eval $(call Profile,tiny210-qtopia))

