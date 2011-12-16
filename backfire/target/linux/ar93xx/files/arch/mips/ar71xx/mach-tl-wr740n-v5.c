/*
 *  TP-LINK TL-WR703N board support
 *
 *  Copyright (C) 2011 flyzjhz <flyzjhz@gmail.com>
 *  Copyright (C) 2011 Gabor Juhos <juhosg@openwrt.org>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/spi/flash.h>
#include <linux/gpio.h>

#include <asm/mach-ar71xx/ar71xx.h>

#include "machtype.h"
#include "devices.h"
#include "dev-ar9xxx-wmac.h"
#include "dev-gpio-buttons.h"
#include "dev-leds-gpio.h"
#include "dev-m25p80.h"
#include "dev-usb.h"

#define TL_WR740N_V5_GPIO_LED_SYSTEM	27
#define TL_WR740N_V5_GPIO_BTN_RESET	11

#define TL_WR740N_V5_GPIO_USB_POWER	8

#define TL_WR740N_V5_KEYS_POLL_INTERVAL	20	/* msecs */
#define TL_WR740N_V5_KEYS_DEBOUNCE_INTERVAL	3

#ifdef CONFIG_MTD_PARTITIONS
static struct mtd_partition tl_wr740n_v5_parts[] = {
	{
		.name		= "u-boot",
		.offset		= 0,
		.size		= 0x020000,
		.mask_flags	= MTD_WRITEABLE,
	}, {
		.name		= "kernel",
		.offset		= 0x020000,
		.size		= 0x100000,
	}, {
		.name		= "rootfs",
		.offset		= 0x120000,
		.size		= 0x2d0000,
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
#define tl_wr740n_v5_nr_parts	ARRAY_SIZE(tl_wr740n_v5_parts)
#else
#define tl_wr740n_v5_parts		NULL
#define tl_wr740n_v5_nr_parts	0
#endif /* CONFIG_MTD_PARTITIONS */

static struct flash_platform_data tl_wr740n_v5_flash_data = {
	.parts		= tl_wr740n_v5_parts,
	.nr_parts	= tl_wr740n_v5_nr_parts,
};

static struct gpio_led tl_wr740n_v5_leds_gpio[] __initdata = {
	{
		.name		= "tl-wr703n:blue:system",
		.gpio		= TL_WR740N_V5_GPIO_LED_SYSTEM,
		.active_low	= 1,
	},
};

static struct gpio_button tl_wr740n_v5_gpio_keys[] __initdata = {
	{
		.desc		= "reset",
		.type		= EV_KEY,
		.code		= KEY_RESTART,
		.threshold = TL_WR740N_V5_KEYS_DEBOUNCE_INTERVAL,
		.gpio		= TL_WR740N_V5_GPIO_BTN_RESET,
		.active_low	= 1,
	}
};

static void __init tl_wr740n_v5_setup(void)
{
	u8 *mac = (u8 *) KSEG1ADDR(0x1f01fc00);
	u8 *ee = (u8 *) KSEG1ADDR(0x1fff1000);

	ar71xx_add_device_m25p80(&tl_wr740n_v5_flash_data);
	ar71xx_add_device_leds_gpio(-1, ARRAY_SIZE(tl_wr740n_v5_leds_gpio),
					tl_wr740n_v5_leds_gpio);
	ar71xx_register_gpio_keys_polled(-1, TL_WR740N_V5_KEYS_POLL_INTERVAL,
					 ARRAY_SIZE(tl_wr740n_v5_gpio_keys),
					 tl_wr740n_v5_gpio_keys);

	gpio_request(TL_WR740N_V5_GPIO_USB_POWER, "USB power");
	gpio_direction_output(TL_WR740N_V5_GPIO_USB_POWER, 1);
	ar71xx_add_device_usb();

	ar71xx_init_mac(ar71xx_eth0_data.mac_addr, mac, 0);
	ar71xx_init_mac(ar71xx_eth1_data.mac_addr, mac, 0);

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


	ar9xxx_add_device_wmac(ee, mac);
}

MIPS_MACHINE(AR71XX_MACH_TL_WR740N_V5, "TL_WR740N_V5", "TP-LINK WR740N V5",
	     tl_WR740N_V5_setup);


