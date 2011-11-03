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
#include <linux/leds.h>
#include <linux/gpio_keys.h>
#include <linux/input.h>

#include <asm/mach-ralink/machine.h>
#include <asm/mach-ralink/dev-gpio-buttons.h>
#include <asm/mach-ralink/dev-gpio-leds.h>
#include <asm/mach-ralink/rt305x.h>
#include <asm/mach-ralink/rt305x_regs.h>

#include "devices.h"

#define HG255D_MTD_PARTITIONS		3  // 1 bootform 0x20000 ,2 bootform 0x40000,3 bootform 0x50000

//#define HG255D_GPIO_BUTTON_RESET	7
#define HG255D_GPIO_BUTTON_WPS		10
#define HG255D_GPIO_BUTTON_WLAN		0

#define HG255D_GPIO_LED_POWER		8
#define HG255D_GPIO_LED_USB		9
#define HG255D_GPIO_LED_INTERNET	13
#define HG255D_GPIO_LED_WLAN		14
#define HG255D_GPIO_LED_WPS		12
//#define HG255D_GPIO_LED_VOICE		17


#define HG255D_BUTTONS_POLL_INTERVAL	20

#define BLOCK_SZ_128K	0x00020000


#ifdef CONFIG_MTD_PARTITIONS
#if (HG255D_MTD_PARTITIONS == 1)
static struct mtd_partition hg255d_partitions[] = {

	{
		.name	= "u-boot",
		.offset	= 0,
		.size	= 0x020000,
//		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "kernel",
		.offset	= 0x0020000,
		.size	= 0x0100000,
	}, {
		.name	= "rootfs",
		.offset	= 0x0120000,
		.size	= 0x06e0000,
	}, {
		.name	= "firmware",
		.offset	= 0x0020000,
		.size	= 0x07e0000,
	}, {
		.name	= "factory",
		.offset	= 0x0fa0000,
		.size	= 0x0020000,
//		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "fullflash",
		.offset	= 0x000000,
		.size	= 0x01000000,
	}
};
#elif (HG255D_MTD_PARTITIONS == 2)
static struct mtd_partition hg255d_partitions[] = {

	
	{
		.name	= "u-boot",
		.offset	= 0,
		.size	= 0x040000,
//		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "kernel",
		.offset	= 0x040000,
		.size	= 0x100000,
	}, {
		.name	= "rootfs",
		.offset	= 0x140000,
		.size	= 0x600000,
	}, {
		.name	= "firmware",
		.offset	= 0x040000,
		.size	= 0xe60000,
	}, {
		.name	= "factory",
		.offset	= 0x0fa0000,
		.size	= 0x0020000,
//		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "fullflash",
		.offset	= 0x000000,
		.size	= 0xfa0000,
	
	} 

};

#elif (HG255D_MTD_PARTITIONS == 3)
static struct mtd_partition hg255d_partitions[] = {

	{
		.name	= "u-boot",
		.offset	= 0,
		.size	= 0x040000,
//		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "kernel",
		.offset	= 0x0050000,
		.size	= 0x0100000,
	}, {
		.name	= "rootfs",
		.offset	= 0x0150000,
		.size	= 0x0e50000,
	}, {
		.name	= "firmware",
		.offset	= 0x0040000,
		.size	= 0x0f60000,
	}, {
		.name	= "factory",
		.offset	= 0x0fa0000,
		.size	= 0x0020000,
//		.mask_flags = MTD_WRITEABLE,
	}, {
		.name	= "fullflash",
		.offset	= 0x000000,
		.size	= 0x01000000,
	}
};

#endif /* CONFIG_MTD_PARTITIONS */
#endif /* CONFIG_MTD_PARTITIONS */

static struct physmap_flash_data hg255d_flash_data = {
#ifdef CONFIG_MTD_PARTITIONS
	.nr_parts	= ARRAY_SIZE(hg255d_partitions),
	.parts		= hg255d_partitions,
#endif
};

static struct gpio_led hg255d_led_pins[] = {
   	{
		.name		= "hg255d:power",
		.gpio		= HG255D_GPIO_LED_POWER,
		.active_low	= 1,
		.default_trigger= "default-on",
	}, {
		.name		= "hg255d:internet",
		.gpio		= HG255D_GPIO_LED_INTERNET,
		.active_low	= 1,
	}, {
		.name		= "hg255d:wlan",
		.gpio		= HG255D_GPIO_LED_WLAN,
		.active_low	= 1,
	}, {
		.name		= "hg255d:usb",
		.gpio		= HG255D_GPIO_LED_USB,
		.active_low	= 1,
	}, {
		.name		= "hg255d:wps",
		.gpio		= HG255D_GPIO_LED_WPS,
		.active_low	= 1,
	}
};

static struct gpio_led_platform_data hg255d_led_data = {
	.leds		= hg255d_led_pins,
	.num_leds	= ARRAY_SIZE(hg255d_led_pins),
};

static struct platform_device hg255d_leds = {
	.name	= "leds-gpio",
	.id	= -1,
	.dev	= {
		.platform_data	= &hg255d_led_data,
	}
};


static struct gpio_keys_button hg255d_buttons[] = {
	{
		.desc		= "BTN_0",
		.type		= EV_KEY,
		.code		= BTN_0,
		.gpio		= HG255D_GPIO_BUTTON_WLAN,
		.active_low	= 1,
		.debounce_interval = 100,
	}, {
		.desc		= "BTN_1",
		.type		= EV_KEY,
		.code		= BTN_1,
		.gpio		= HG255D_GPIO_BUTTON_WPS,
		.active_low	= 1,
		.debounce_interval = 100,
	}
		
};


static struct gpio_keys_platform_data hg255d_button_data = {
	.buttons	= hg255d_buttons,
	.nbuttons	= ARRAY_SIZE(hg255d_buttons),
};

static struct platform_device hg255d_button_device = {
	.name		= "gpio-keys",
	.id		= -1,
	.num_resources	= 0,
	.dev		= {
		.platform_data	= &hg255d_button_data,
	}
};


static void __init hg255d_init(void)
{
	rt305x_gpio_init(RT305X_GPIO_MODE_GPIO << RT305X_GPIO_MODE_UART0_SHIFT);

	rt305x_register_flash(0, &hg255d_flash_data);

	//ramips_register_gpio_leds(-1, ARRAY_SIZE(hg255d_leds_gpio),
	//			  hg255d_leds_gpio);
	platform_device_register(&hg255d_leds);

	//ramips_register_gpio_buttons(-1, HG255D_BUTTONS_POLL_INTERVAL,
	//			     ARRAY_SIZE(hg255d_gpio_buttons),
	//			     hg255d_gpio_buttons);
	platform_device_register(&hg255d_button_device);

	rt305x_esw_data.vlan_config = RT305X_ESW_VLAN_CONFIG_WLLLL;
	rt305x_register_ethernet();
	rt305x_register_wifi();
	rt305x_register_wdt();
	rt305x_register_usb();
	rt305x_register_gpiodev();
}

MIPS_MACHINE(RAMIPS_MACH_HG255D, "HG255D", "HuaWei HG255D",
	     hg255d_init);
