/*
 *  La Fonera20N board support
 *
 *  Copyright (C) 2009 John Crispin <blogic@openwrt.org>
 *  Copyright (C) 2010 Gabor Juhos <juhosg@openwrt.org>
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
#define HG255D_GPIO_SWITCH		13
#define HG255D_GPIO_LED_WIFI		7
#define HG255D_GPIO_LED_POWER	9
#define HG255D_GPIO_LED_USB		14

#define HG255D_BUTTONS_POLL_INTERVAL	20

#ifdef CONFIG_MTD_PARTITIONS
static struct mtd_partition hg255d_partitions[] = {
	{
		.name	= "u-boot",
		.offset	= 0,
		.size	= 0x030000,
		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "u-boot-env",
		.offset	= 0x030000,
		.size	= 0x010000,
		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "factory",
		.offset	= 0x040000,
		.size	= 0x010000,
		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "kernel",
		.offset	= 0x050000,
		.size	= 0x0a0000,
	}, {
		.name	= "rootfs",
		.offset	= 0x150000,
		.size	= 0xEE0000,
	}, {
		.name	= "openwrt",
		.offset	= 0x050000,
		.size	= 0xFB0000,
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
		.name		= "hg255d:orange:wifi",
		.gpio		= HG255D_GPIO_LED_WIFI,
		.active_low	= 1,
	}, {
		.name		= "hg255d:green:power",
		.gpio		= HG255D_GPIO_LED_POWER,
		.active_low	= 1,
	}, {
		.name		= "hg255d:orange:usb",
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
		.desc		= "switch",
		.type		= EV_KEY,
		.code		= BTN_1,
		.threshold	= 3,
		.gpio		= HG255D_GPIO_SWITCH,
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
