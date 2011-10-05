/*
 *  HuaWei HG255D board support by lintel
 *
 *  Copyright (C) 2011 lintel<lintel.huang@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/mtd/physmap.h>

#include <asm/mach-ralink/machine.h>
#include <asm/mach-ralink/dev-gpio-buttons.h>
#include <asm/mach-ralink/dev-gpio-leds.h>
#include <asm/mach-ralink/rt305x.h>
#include <asm/mach-ralink/rt305x_regs.h>

#include "devices.h"

#define HG255D_GPIO_BUTTON_RESET	12
#define HG255D_GPIO_BUTTON_WPS		13

#define HG255D_GPIO_LED_POWER		9
#define HG255D_GPIO_LED_INTERNET	6
#define HG255D_GPIO_LED_WLAN		7
#define HG255D_GPIO_LED_WPS		15
#define HG255D_GPIO_LED_VOICE		17
#define HG255D_GPIO_LED_USB		14

#define HG255D_BUTTONS_POLL_INTERVAL	20

#define BLOCK_SZ_128K	0x00020000


#ifdef CONFIG_MTD_PARTITIONS
static struct mtd_partition hg255d_partitions[] = {
	{
		.name	= "u-boot",
		.offset	= 0,
		.size	= BLOCK_SZ_128K,
		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "kernel",
		.offset	= MTDPART_OFS_APPEND,
		.size	= BLOCK_SZ_128K * 7,
	}, {
		.name	= "rootfs",
		.offset	= MTDPART_OFS_APPEND,
		.size	= MTDPART_SIZ_FULL - BLOCK_SZ_128K,
	}, {
		.name	= "openwrt",
		.offset	= BLOCK_SZ_128K,
		.size	= MTDPART_SIZ_FULL - BLOCK_SZ_128K,
	}
};
#endif /* CONFIG_MTD_PARTITIONS */

static struct physmap_flash_data hg255d_flash_data = {
#ifdef CONFIG_MTD_PARTITIONS
	.nr_parts	= ARRAY_SIZE(hg255d_partitions),
	.parts		= hg255d_partitions,
#endif
};

static struct gpio_led hg255d_leds_gpio[] __initdata = {
   	{
		.name		= "hg255d:power",
		.gpio		= HG255D_GPIO_LED_POWER,
		.active_low	= 1,
	}, {
		.name		= "hg255d:internet",
		.gpio		= HG255D_GPIO_LED_INTERNET,
		.active_low	= 1,
	}, {
		.name		= "hg255d:wlan",
		.gpio		= HG255D_GPIO_LED_WLAN,
		.active_low	= 1,
	}, {
		.name		= "hg255d:wps",
		.gpio		= HG255D_GPIO_LED_WPS,
		.active_low	= 1,
	}, {
		.name		= "hg255d:voice",
		.gpio		= HG255D_GPIO_LED_VOICE,
		.active_low	= 1,
	}, {
		.name		= "hg255d:usb",
		.gpio		= HG255D_GPIO_LED_USB,
		.active_low	= 1,
	}
};

static struct gpio_button hg255d_gpio_buttons[] __initdata = {
	{
		.desc		= "reset",
		.type		= EV_KEY,
		.code		= KEY_RESTART,
		.threshold	= 3,
		.gpio		= HG255D_GPIO_BUTTON_RESET,
		.active_low	= 1,
	}, {
		.desc		= "wps",
		.type		= EV_KEY,
		.code		= BTN_1,
		.threshold	= 3,
		.gpio		= HG255D_GPIO_BUTTON_WPS,
		.active_low	= 1,
	}
};

static void __init hg255d_init(void)
{
	rt305x_gpio_init(RT305X_GPIO_MODE_GPIO << RT305X_GPIO_MODE_UART0_SHIFT);

	rt305x_register_flash(0, &hg255d_flash_data);

	ramips_register_gpio_leds(-1, ARRAY_SIZE(hg255d_leds_gpio),
				  hg255d_leds_gpio);

	ramips_register_gpio_buttons(-1, HG255D_BUTTONS_POLL_INTERVAL,
				     ARRAY_SIZE(hg255d_gpio_buttons),
				     hg255d_gpio_buttons);

	rt305x_register_ethernet();
	rt305x_register_wifi();
}

MIPS_MACHINE(RAMIPS_MACH_HG255D, "HG255D", "HuaWei HG255D",
	     hg255d_init);
