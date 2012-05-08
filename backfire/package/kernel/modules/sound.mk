#
# Copyright (C) 2006-2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

SOUND_MENU:=Sound Support

define KernelPackage/sound-core
  SUBMENU:=$(SOUND_MENU)
  TITLE:=Sound support
  DEPENDS:=@AUDIO_SUPPORT +!TARGET_x86:kmod-input-core
  KCONFIG:= \
	CONFIG_SOUND \
	CONFIG_SND \
	CONFIG_SND_HWDEP \
	CONFIG_SND_RAWMIDI \
	CONFIG_SND_TIMER \
	CONFIG_SND_PCM \
	CONFIG_SND_SEQUENCER \
	CONFIG_SND_VIRMIDI \
	CONFIG_SND_SEQ_DUMMY \
	CONFIG_SND_SEQUENCER_OSS=y \
	CONFIG_HOSTAUDIO \
	CONFIG_SND_PCM_OSS \
	CONFIG_SND_MIXER_OSS \
	CONFIG_SOUND_OSS_CORE_PRECLAIM=y
endef

define KernelPackage/sound-core/2.4
  FILES:=$(LINUX_DIR)/drivers/sound/soundcore.$(LINUX_KMOD_SUFFIX)
  AUTOLOAD:=$(call AutoLoad,30,soundcore)
endef

# allow 2.6 targets to override the soundcore stuff
SOUNDCORE_LOAD ?= \
	soundcore \
	snd \
	snd-page-alloc \
	snd-hwdep \
	snd-seq-device \
	snd-rawmidi \
	snd-timer \
	snd-pcm \
	snd-mixer-oss \
	snd-pcm-oss

SOUNDCORE_FILES ?= \
	$(LINUX_DIR)/sound/soundcore.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/core/snd.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/core/snd-page-alloc.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/core/snd-hwdep.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/core/seq/snd-seq-device.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/core/snd-rawmidi.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/core/snd-timer.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/core/snd-pcm.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/core/oss/snd-mixer-oss.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/core/oss/snd-pcm-oss.$(LINUX_KMOD_SUFFIX)

define KernelPackage/sound-core/2.6
  FILES:=$(SOUNDCORE_FILES)
  AUTOLOAD:=$(call AutoLoad,30,$(SOUNDCORE_LOAD))
endef

define KernelPackage/sound-core/uml
  FILES:= \
	$(LINUX_DIR)/sound/soundcore.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/arch/um/drivers/hostaudio.$(LINUX_KMOD_SUFFIX)
  AUTOLOAD:=$(call AutoLoad,30,soundcore hostaudio)
endef

define KernelPackage/sound-core/description
 Kernel modules for sound support
endef

$(eval $(call KernelPackage,sound-core))


define KernelPackage/sound/Depends
  SUBMENU:=$(SOUND_MENU)
  DEPENDS:=kmod-sound-core $(1)
endef


define KernelPackage/sound-i8x0
$(call KernelPackage/sound/Depends,@!TARGET_uml)
  TITLE:=Intel/SiS/nVidia/AMD/ALi AC97 Controller
  KCONFIG:=CONFIG_SND_INTEL8X0
  FILES:=$(LINUX_DIR)/sound/pci/snd-intel8x0.$(LINUX_KMOD_SUFFIX)
  AUTOLOAD:=$(call AutoLoad,35,snd-i8x0)
endef

define KernelPackage/sound-i8x0/description
 support for the integrated AC97 sound device on motherboards
 with Intel/SiS/nVidia/AMD chipsets, or ALi chipsets using 
 the M5455 Audio Controller.
endef

$(eval $(call KernelPackage,sound-i8x0))


define KernelPackage/sound-ps3
$(call KernelPackage/sound/Depends,@TARGET_ps3||TARGET_ps3chk)
  TITLE:=PS3 Audio
  KCONFIG:=CONFIG_SND_PS3 \
		CONFIG_SND_PPC=y \
		CONFIG_SND_PS3_DEFAULT_START_DELAY=2000
  FILES:=$(LINUX_DIR)/sound/ppc/snd_ps3.$(LINUX_KMOD_SUFFIX)
  AUTOLOAD:=$(call AutoLoad,35, snd_ps3)
endef

define KernelPackage/sound-ps3/description
 support for the integrated PS3 audio device
endef

$(eval $(call KernelPackage,sound-ps3))


define KernelPackage/sound-cs5535audio
$(call KernelPackage/sound/Depends,@!TARGET_uml)
  TITLE:=CS5535 PCI Controller
  KCONFIG:=CONFIG_SND_CS5535AUDIO
  FILES:=$(LINUX_DIR)/sound/pci/cs5535audio/snd-cs5535audio.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/ac97_bus.$(LINUX_KMOD_SUFFIX) \
	$(LINUX_DIR)/sound/pci/ac97/snd-ac97-codec.$(LINUX_KMOD_SUFFIX) 
  AUTOLOAD:=$(call AutoLoad,35, ac97_bus snd-ac97-codec snd-cs5535audio)
endef

define KernelPackage/sound-cs5535audio/description
 support for the integrated AC97 sound device on olpc
endef

$(eval $(call KernelPackage,sound-cs5535audio))


define KernelPackage/sound-soc-core
$(call KernelPackage/sound/Depends)
  TITLE:=SoC sound support
  KCONFIG:= \
	CONFIG_SND_SOC \
	CONFIG_SND_SOC_ALL_CODECS=n
  FILES:=$(LINUX_DIR)/sound/soc/snd-soc-core.ko
  AUTOLOAD:=$(call AutoLoad,55, snd-soc-core)
endef

$(eval $(call KernelPackage,sound-soc-core))

define KernelPackage/sound-soc-s3c24xx-i2s
$(call KernelPackage/sound/Depends)
  TITLE:=S3c24xx SoC sound support
  DEPENDS:=@AUDIO_SUPPORT @TARGET_s3c24xx +kmod-sound-soc-core
  KCONFIG:= \
	CONFIG_SND_S3C24XX_SOC \
	CONFIG_SND_S3C24XX_SOC_I2S
  FILES:= \
	$(LINUX_DIR)/sound/soc/s3c24xx/snd-soc-s3c24xx.ko \
	$(LINUX_DIR)/sound/soc/s3c24xx/snd-soc-s3c24xx-i2s.ko
  AUTOLOAD:= \
	$(call AutoLoad,55, snd-soc-s3c24xx) \
	$(call AutoLoad,55, snd-soc-s3c24xx-i2s) 
endef

$(eval $(call KernelPackage,sound-soc-s3c24xx-i2s))

define KernelPackage/sound-soc-s3c24xx-uda134x
$(call KernelPackage/sound/Depends)
  TITLE:=UDA134x SoC sound Chip support
  DEPENDS:=@AUDIO_SUPPORT @TARGET_s3c24xx +kmod-sound-soc-s3c24xx-i2s
  KCONFIG:= \
	CONFIG_SND_S3C24XX_SOC_S3C24XX_UDA134X \
	CONFIG_SND_SOC_UDA134X \
	CONFIG_SND_S3C24XX_SOC_LN2440SBC_ALC650=n \
	CONFIG_SND_S3C24XX_SOC_SIMTEC_TLV320AIC23=n \
	CONFIG_SND_S3C24XX_SOC_SIMTEC_HERMES=n 
  FILES:= \
	$(LINUX_DIR)/sound/soc/codecs/snd-soc-uda134x.ko \
	$(LINUX_DIR)/sound/soc/s3c24xx/snd-soc-s3c24xx-uda134x.ko
  AUTOLOAD:= \
	$(call AutoLoad,55,snd-soc-uda134x) \
	$(call AutoLoad,55,snd-soc-s3c24xx-uda134x) 
endef

$(eval $(call KernelPackage,sound-soc-s3c24xx-uda134x))
