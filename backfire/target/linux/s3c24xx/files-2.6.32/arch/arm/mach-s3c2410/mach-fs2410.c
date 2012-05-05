/* linux/arch/arm/mach-s3c2410/mach-fs2410.c
 *
 * Base by richardnee's Patch
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
*/

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/list.h>
#include <linux/timer.h>
#include <linux/init.h>
#include <linux/serial_core.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#include <linux/gpio.h>
#include <linux/sysdev.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/nand_ecc.h>
#include <linux/mtd/partitions.h>
//#include <linux/dm9000.h>
#include <linux/mmc/host.h>

#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <asm/mach/irq.h>
#include <asm/irq.h>
#include <asm/mach-types.h>

#include <mach/hardware.h>
#include <mach/regs-gpio.h>
#include <mach/regs-clock.h>
#include <mach/regs-lcd.h>
#include <mach/leds-gpio.h>
#include <linux/leds.h>
#include <mach/idle.h>
#include <mach/fb.h>

#include <plat/regs-serial.h>
#include <plat/iic.h>
#include <plat/s3c2410.h>
//#include <plat/s3c2440.h>
#include <plat/clock.h>
#include <plat/devs.h>
#include <plat/cpu.h>
#include <plat/nand.h>
#include <plat/pm.h>
#include <plat/mci.h>

//#include <plat/usb-control.h> //fs2410 usb ctl
#include <linux/delay.h>

#define CONFIG_FB_S3C2410_VGA1024768 1

#define NAND_FLASH_SIZE 0x000004000000
#include <sound/s3c24xx_uda134x.h>

static struct map_desc fs2440_iodesc[] __initdata = {
};

#define UCON S3C2410_UCON_DEFAULT | S3C2410_UCON_UCLK
#define ULCON S3C2410_LCON_CS8 | S3C2410_LCON_PNONE | S3C2410_LCON_STOPB
#define UFCON S3C2410_UFCON_RXTRIG8 | S3C2410_UFCON_FIFOMODE

static struct s3c2410_uartcfg fs2440_uartcfgs[] __initdata = {
	[0] = {
		.hwport	     = 0,
		.flags	     = 0,
		.ucon	     = 0x3c5,
		.ulcon	     = 0x03,
		.ufcon	     = 0x51,
	},
	[1] = {
		.hwport	     = 1,
		.flags	     = 0,
		.ucon	     = 0x3c5,
		.ulcon	     = 0x03,
		.ufcon	     = 0x51,
	},
	[2] = {
		.hwport	     = 2,
		.flags	     = 0,
		.ucon	     = 0x3c5,
		.ulcon	     = 0x03,
		.ufcon	     = 0x51,
	}
};

/* LCD driver info */

#if defined(CONFIG_FB_S3C2410_N240320)

#define LCD_WIDTH 240
#define LCD_HEIGHT 320
#define LCD_PIXCLOCK 100000

#define LCD_RIGHT_MARGIN 36
#define LCD_LEFT_MARGIN 19
#define LCD_HSYNC_LEN 5

#define LCD_UPPER_MARGIN 1
#define LCD_LOWER_MARGIN 5
#define LCD_VSYNC_LEN 1

#elif defined(CONFIG_FB_S3C2410_N480272)

#define LCD_WIDTH 480
#define LCD_HEIGHT 272
#define LCD_PIXCLOCK 100000

#define LCD_RIGHT_MARGIN 36
#define LCD_LEFT_MARGIN 19
#define LCD_HSYNC_LEN 5

#define LCD_UPPER_MARGIN 1
#define LCD_LOWER_MARGIN 5
#define LCD_VSYNC_LEN 1

#elif defined(CONFIG_FB_S3C2410_TFT640480)
#define LCD_WIDTH 640
#define LCD_HEIGHT 480
#define LCD_PIXCLOCK 40000

#define LCD_RIGHT_MARGIN 67 
#define LCD_LEFT_MARGIN 40
#define LCD_HSYNC_LEN 31

#define LCD_UPPER_MARGIN 5
#define LCD_LOWER_MARGIN 25
#define LCD_VSYNC_LEN 1

#elif defined(CONFIG_FB_S3C2410_T240320)
#define LCD_WIDTH 240
#define LCD_HEIGHT 320
#define LCD_PIXCLOCK 170000
#define LCD_RIGHT_MARGIN 25
#define LCD_LEFT_MARGIN 0
#define LCD_HSYNC_LEN 4
#define LCD_UPPER_MARGIN 1
#define LCD_LOWER_MARGIN 4
#define LCD_VSYNC_LEN 1
#define LCD_CON5 (S3C2410_LCDCON5_FRM565 | S3C2410_LCDCON5_INVVDEN | S3C2410_LCDCON5_INVVFRAME | S3C2410_LCDCON5_INVVLINE | S3C2410_LCDCON5_INVVCLK | S3C2410_LCDCON5_HWSWP ) 

#elif defined(CONFIG_FB_S3C2410_TFT800480)
#define LCD_WIDTH 800
#define LCD_HEIGHT 480
#define LCD_PIXCLOCK 40000

#define LCD_RIGHT_MARGIN 67
#define LCD_LEFT_MARGIN 40
#define LCD_HSYNC_LEN 31

#define LCD_UPPER_MARGIN 25
#define LCD_LOWER_MARGIN 5
#define LCD_VSYNC_LEN 1

#elif defined(CONFIG_FB_S3C2410_VGA1024768)
#define LCD_WIDTH 1024
#define LCD_HEIGHT 768
#define LCD_PIXCLOCK 80000

#define LCD_RIGHT_MARGIN 15
#define LCD_LEFT_MARGIN 199
#define LCD_HSYNC_LEN 15

#define LCD_UPPER_MARGIN 1
#define LCD_LOWER_MARGIN 1
#define LCD_VSYNC_LEN 1
#define LCD_CON5 (S3C2410_LCDCON5_FRM565 | S3C2410_LCDCON5_HWSWP)

#endif




/*
#if defined (LCD_WIDTH)

static struct s3c2410fb_display fs2440_lcd_cfg __initdata = {

#if !defined (LCD_CON5)
	.lcdcon5	= S3C2410_LCDCON5_FRM565 |
			  S3C2410_LCDCON5_INVVLINE |
			  S3C2410_LCDCON5_INVVFRAME |
			  S3C2410_LCDCON5_PWREN |
			  S3C2410_LCDCON5_HWSWP,
#else
	.lcdcon5	= LCD_CON5,
#endif

	.type		= S3C2410_LCDCON1_TFT,

	.width		= LCD_WIDTH,
	.height		= LCD_HEIGHT,

	.pixclock	= LCD_PIXCLOCK,
	.xres		= LCD_WIDTH,
	.yres		= LCD_HEIGHT,
	.bpp		= 16,
	.left_margin	= LCD_LEFT_MARGIN + 1,
	.right_margin	= LCD_RIGHT_MARGIN + 1,
	.hsync_len	= LCD_HSYNC_LEN + 1,
	.upper_margin	= LCD_UPPER_MARGIN + 1,
	.lower_margin	= LCD_LOWER_MARGIN + 1,
	.vsync_len	= LCD_VSYNC_LEN + 1,
};


static struct s3c2410fb_mach_info fs2440_fb_info __initdata = {
	.displays	= &fs2440_lcd_cfg,
	.num_displays	= 1,
	.default_display = 0,

	.gpccon =       0xaa955699,
	.gpccon_mask =  0xffc003cc,
	.gpcup =        0x0000ffff,
	.gpcup_mask =   0xffffffff,

	.gpdcon =       0xaa95aaa1,
	.gpdcon_mask =  0xffc0fff0,
	.gpdup =        0x0000faff,
	.gpdup_mask =   0xffffffff,


	.lpcsel		= 0xf82,
};

#endif
*/


/****************** lcd *********************/
/* LCD driver info_320x240 */
#if 0
static struct s3c2410fb_display fs2440_lcd_cfg __initdata = {
	.lcdcon5 = S3C2410_LCDCON5_FRM565 |
 				S3C2410_LCDCON5_INVVLINE |
 				S3C2410_LCDCON5_INVVFRAME |
 				S3C2410_LCDCON5_PWREN |
 				S3C2410_LCDCON5_HWSWP,

	.type = S3C2410_LCDCON1_TFT,
	.width = 320,
	.height = 240,
	.pixclock = 170000, /* HCLK 60 MHz, divisor 10 */
	.xres = 320,
	.yres = 240,
	.bpp = 16,
	.left_margin = 21,
	.right_margin = 39,
	.hsync_len = 31,
	.upper_margin = 16,
	.lower_margin = 13,
	.vsync_len = 4,

};
#endif

/*LCD driver info_800x480*/
#if 1
//static struct s3c2410fb_display fs2440_lcd_cfg __initdata = {
static struct s3c2410fb_display fs2440_lcd_cfg  = {
	.lcdcon5 = S3C2410_LCDCON5_FRM565 |
 				S3C2410_LCDCON5_INVVLINE |
 				S3C2410_LCDCON5_INVVFRAME |
 				S3C2410_LCDCON5_PWREN |
 				S3C2410_LCDCON5_HWSWP,

	.type = S3C2410_LCDCON1_TFT,
	.width = 800,
	.height = 480,
	.pixclock = 170000, /* HCLK 60 MHz, divisor 10 */
	.xres = 800,
	.yres = 480,
	.bpp = 16,
	.left_margin = 40,
	.right_margin = 40,
	.hsync_len = 48,
	.upper_margin = 29,
	.lower_margin = 13,
	.vsync_len = 3,
};
#endif

#if 0
static struct s3c2410fb_display fs2440_lcd_cfg __initdata = {
	.lcdcon5 = S3C2410_LCDCON5_FRM565 |
 				S3C2410_LCDCON5_INVVLINE |
 				S3C2410_LCDCON5_INVVFRAME |
 				S3C2410_LCDCON5_PWREN |
 				S3C2410_LCDCON5_HWSWP,

	.type = S3C2410_LCDCON1_TFT,
	.width = 480,
	.height = 272,
	.pixclock = 170000, /* HCLK 60 MHz, divisor 10 */
	.xres = 480,
	.yres = 272,
	.bpp = 16,
	.left_margin = 40,
	.right_margin = 40,
	.hsync_len = 48,
	.upper_margin = 29,
	.lower_margin = 13,
	.vsync_len = 3,
};
#endif

/* 640*480 VGA driver info */
#if 0
static struct s3c2410fb_display fs2440_lcd_cfg __initdata = {
	
	.lcdcon5 = S3C2410_LCDCON5_FRM565 |
 				S3C2410_LCDCON5_INVVLINE |
 				S3C2410_LCDCON5_INVVFRAME |
 				S3C2410_LCDCON5_PWREN |
 				S3C2410_LCDCON5_HWSWP,

	.type = S3C2410_LCDCON1_TFT,
	.width = 640,
	.height = 480,
	.pixclock = 5000, /* HCLK 60 MHz, divisor 10 */
	.xres = 640,
	.yres = 480,
	.bpp = 16,


	.left_margin = 23,
	.right_margin = 1,
	.hsync_len = 135,
	.upper_margin = 28,
	.lower_margin = 2,
	.vsync_len = 5,
};
#endif

static struct s3c2410fb_mach_info fs2440_fb_info __initdata = {
	.displays = &fs2440_lcd_cfg,
	.num_displays = 1,
	.default_display = 0,
/*
*/
};



static struct s3c24xx_uda134x_platform_data s3c24xx_uda134x_data = {
	.l3_clk = S3C2410_GPB(4),
	.l3_data = S3C2410_GPB(3),
	.l3_mode = S3C2410_GPB(2),
	.model = UDA134X_UDA1341,
};

static struct platform_device s3c24xx_uda134x = {
	.name = "s3c24xx_uda134x",
	.dev = {
		.platform_data    = &s3c24xx_uda134x_data,
	}
};

static struct mtd_partition fs2440_default_nand_part[] = {
	[0] = {
		.name	= "u-boot",
		.size	= SZ_256K+SZ_128K,
		.offset	= 0,
	},
	[1] = {
		.name	= "u-boot-env",
		.offset = SZ_256K+SZ_128K,
		.size	= SZ_128K,
	},
	[2] = {
		.name	= "kernel",
		.offset = ((SZ_256K+SZ_128K)+SZ_128K),
		.size	= (SZ_1M * 5),
	},
	[3] = {
		.name	= "rootfs",
		.offset = (((SZ_256K+SZ_128K)+SZ_128K)+ (SZ_1M * 5)),
		.size	= (SZ_1M * 50),
//		.size	= 0x2000000,
	},
	[4] = {
		.name	= "other-rootfs",
		.offset = MTDPART_OFS_APPEND,
		.size	= MTDPART_SIZ_FULL,
	},
};

static struct s3c2410_nand_set fs2440_nand_sets[] = {
	[0] = {
		.name		= "NAND",
		.nr_chips	= 1,
		.nr_partitions	= ARRAY_SIZE(fs2440_default_nand_part),
		.partitions	= fs2440_default_nand_part,
	},
};

/* choose a set of timings which should suit most 512Mbit
 * chips and beyond.
*/

static struct s3c2410_platform_nand fs2440_nand_info = {
	.tacls		= 20,
	.twrph0		= 60,
	.twrph1		= 20,
	.nr_sets	= ARRAY_SIZE(fs2440_nand_sets),
	.sets		= fs2440_nand_sets,
	.ignore_unset_ecc = 1,
};

/* CS89000A 10/100 ethernet controller */
#define MACH_FS2440_CS8900A_BASE 0x19000000

/*This must has some struct for CS8900A  ethernet controller */




/* MMC/SD  */

static struct s3c24xx_mci_pdata fs2440_mmc_cfg = {
   .gpio_detect   = S3C2410_GPG(10),
   .gpio_wprotect = S3C2410_GPH(10),
   .set_power     = NULL,
   .ocr_avail     = MMC_VDD_32_33,
};

//LED
static struct gpio_led fs2440_led_pins[] = {
#if 0  /* LED Disabled,Because Pins Unknow*/
	{
		.name		= "LED1",
		.gpio		= S3C2410_GPB(5),
		.active_low	= true,
	},
	{
		.name		= "LED2",
		.gpio		= S3C2410_GPB(6) ,
		.active_low	= true,
	},
	{
		.name		= "LED3",
		.gpio		= S3C2410_GPB(7),
		.active_low	= true,
	},
	{
		.name		= "LED4",
		.gpio		= S3C2410_GPB(8),
		.active_low	= true,
	},
#endif
};

static struct gpio_led_platform_data fs2440_led_data = {
	.num_leds		= ARRAY_SIZE(fs2440_led_pins),
	.leds			= fs2440_led_pins,
};

static struct platform_device fs2440_leds = {
	.name			= "leds-gpio",
	.id			= -1,
	.dev.platform_data	= &fs2440_led_data,
};


static struct resource gpiodev_resource = {
	.start			= 0xFFFFFFFF,
};


/* devices we initialise */

static struct platform_device *fs2440_devices[] __initdata = {
	&s3c_device_usb,
	&s3c_device_rtc,
	&s3c_device_lcd,
	&s3c_device_wdt,
	&s3c_device_i2c0,
	&s3c_device_iis,
//	&fs2440_device_eth,  //no ethernet controller config
	&s3c24xx_uda134x,
	&s3c_device_nand,
	&s3c_device_sdi,
	&s3c_device_usbgadget,
	&fs2440_leds,
};


static void __init fs2440_map_io(void)
{
	s3c24xx_init_io(fs2440_iodesc, ARRAY_SIZE(fs2440_iodesc));
	s3c24xx_init_clocks(12000000);
	s3c24xx_init_uarts(fs2440_uartcfgs, ARRAY_SIZE(fs2440_uartcfgs));
//	usb_fs2440_init();
}

static void __init fs2440_machine_init(void)
{

	s3c24xx_fb_set_platdata(&fs2440_fb_info);

	s3c_i2c0_set_platdata(NULL);

	s3c2410_gpio_cfgpin(S3C2410_GPC(0), S3C2410_GPC0_LEND);
//	s3c_device_usb.dev.platform_data = &usb_fs2410_info;
	s3c_device_nand.dev.platform_data = &fs2440_nand_info;
	s3c_device_sdi.dev.platform_data = &fs2440_mmc_cfg;
	platform_add_devices(fs2440_devices, ARRAY_SIZE(fs2440_devices));
	platform_device_register_simple("GPIODEV", 0, &gpiodev_resource, 1); //GPIO resource MAP
	s3c_pm_init();
}

MACHINE_START(FS2410, "FS2440 development board")
	.phys_io	= S3C2410_PA_UART,
	.io_pg_offst	= (((u32)S3C24XX_VA_UART) >> 18) & 0xfffc,
	.boot_params	= S3C2410_SDRAM_PA + 0x100,

	.init_irq	= s3c24xx_init_irq,
	.map_io		= fs2440_map_io,
	.init_machine	= fs2440_machine_init,
	.timer		= &s3c24xx_timer,
MACHINE_END

