/*
 *  Atheros WR740N_V5 board support
 *
 *  Copyright (C) 2011 Gabor Juhos <juhosg@openwrt.org>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/spi/flash.h>

#include "machtype.h"
#include "devices.h"
#include "dev-ar9xxx-wmac.h"
#include "dev-gpio-buttons.h"
#include "dev-leds-gpio.h"
#include "dev-m25p80.h"
#include "dev-usb.h"

#define WR740N_V5_GPIO_LED_WLAN	0
#define WR740N_V5_GPIO_LED_USB		1

#define WR740N_V5_GPIO_BTN_JUMPSTART	11
#define WR740N_V5_GPIO_BTN_RESET	12

#define WR740N_V5_KEYS_POLL_INTERVAL	20	/* msecs */
#define WR740N_V5_KEYS_DEBOUNCE_INTERVAL	(3 * WR740N_V5_KEYS_POLL_INTERVAL)

#define WR740N_V5_MAC0_OFFSET	0x0000
#define WR740N_V5_MAC1_OFFSET	0x0006
#define WR740N_V5_CALDATA_OFFSET	0x1000
#define WR740N_V5_WMAC_MAC_OFFSET	0x1002

#define WR740N_V5_MINI_GPIO_LED_WLAN	0
#define WR740N_V5_MINI_GPIO_BTN_JUMPSTART	12
#define WR740N_V5_MINI_GPIO_BTN_RESET	11

#ifdef CONFIG_MTD_PARTITIONS
static struct mtd_partition WR740N_V5_parts[] = {
	{
		.name		= "u-boot",
		.offset		= 0,
		.size		= 0x020000,
		.mask_flags	= MTD_WRITEABLE,
	}, {
		.name		= "kernel",
		.offset		= 0x020000,
		.size		= 0x140000,
	}, {
		.name		= "rootfs",
		.offset		= 0x160000,
		.size		= 0x290000,
	}, {
		.name		= "art",
		.offset		= 0x3f0000,
		.size		= 0x010000,
		.mask_flags	= MTD_WRITEABLE,
	}, {
		.name		= "firmware",
		.offset		= 0x020000,
		.size		= 0x3d0000,
	}
};
#define WR740N_V5_nr_parts		ARRAY_SIZE(WR740N_V5_parts)



#else
#define WR740N_V5_parts		NULL
#define WR740N_V5_nr_parts		0

#endif /* CONFIG_MTD_PARTITIONS */

static struct flash_platform_data WR740N_V5_flash_data = {
	.parts		= WR740N_V5_parts,
	.nr_parts	= WR740N_V5_nr_parts,
};

static struct gpio_led WR740N_V5_leds_gpio[] __initdata = {
	{
		.name		= "WR740N_V5:green:usb",
		.gpio		= WR740N_V5_GPIO_LED_USB,
		.active_low	= 0,
	},
	{
		.name		= "WR740N_V5:green:wlan",
		.gpio		= WR740N_V5_GPIO_LED_WLAN,
		.active_low	= 0,
	},
};

static struct gpio_keys_button WR740N_V5_gpio_keys[] __initdata = {
	{
		.desc		= "jumpstart button",
		.type		= EV_KEY,
		.code		= KEY_WPS_BUTTON,
		.debounce_interval = WR740N_V5_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= WR740N_V5_GPIO_BTN_JUMPSTART,
		.active_low	= 1,
	},
	{
		.desc		= "reset button",
		.type		= EV_KEY,
		.code		= KEY_RESTART,
		.debounce_interval = WR740N_V5_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= WR740N_V5_GPIO_BTN_RESET,
		.active_low	= 1,
	}
};




static void __init WR740N_V5_common_setup(void)
{
	u8 *art = (u8 *) KSEG1ADDR(0x1fff0000);

	ar71xx_add_device_m25p80(&WR740N_V5_flash_data);

	ar71xx_init_mac(ar71xx_eth0_data.mac_addr, art + WR740N_V5_MAC0_OFFSET, 0);
	ar71xx_init_mac(ar71xx_eth1_data.mac_addr, art + WR740N_V5_MAC1_OFFSET, 0);

	/* WAN port */
	ar71xx_eth0_data.phy_if_mode = PHY_INTERFACE_MODE_RMII;
	ar71xx_eth0_data.speed = SPEED_100;
	ar71xx_eth0_data.duplex = DUPLEX_FULL;
	ar71xx_eth0_data.phy_mask = BIT(4);

	/* LAN ports */
	ar71xx_eth1_data.phy_if_mode = PHY_INTERFACE_MODE_RMII;
	ar71xx_eth1_data.speed = SPEED_1000;
	ar71xx_eth1_data.duplex = DUPLEX_FULL;
	ar71xx_eth1_data.has_ar7240_switch = 1;

	ar71xx_add_device_mdio(0x0);
	ar71xx_add_device_eth(1);
	ar71xx_add_device_eth(0);

	ar9xxx_add_device_wmac(art + WR740N_V5_CALDATA_OFFSET,
			       art + WR740N_V5_WMAC_MAC_OFFSET);
}

static void __init WR740N_V5_setup(void)
{
	WR740N_V5_flash_data.parts = WR740N_V5_parts;
	WR740N_V5_flash_data.nr_parts = WR740N_V5_nr_parts;

	WR740N_V5_common_setup();

	ar71xx_add_device_leds_gpio(-1, ARRAY_SIZE(WR740N_V5_leds_gpio),
					WR740N_V5_leds_gpio);
	ar71xx_register_gpio_keys_polled(-1, WR740N_V5_KEYS_POLL_INTERVAL,
					 ARRAY_SIZE(WR740N_V5_gpio_keys),
					 WR740N_V5_gpio_keys);

	ar71xx_add_device_usb();
}


MIPS_MACHINE(AR71XX_MACH_TL_WR740N_V5, "TL_WR740N_V5", "TP-LINK WR740N V5",
	     WR740N_V5_setup);

