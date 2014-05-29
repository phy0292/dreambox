#ifndef _RTL8367B_ASICDRV_LED_H_
#define _RTL8367B_ASICDRV_LED_H_

#include <rtl8367b_asicdrv.h>

#define RTL8367B_LEDGROUPNO					3	
#define RTL8367B_LEDGROUPMASK               0x7
#define RTL8367B_LED_FORCE_MODE_BASE        RTL8367B_REG_CPU_FORCE_LED0_CFG0
#define RTL8367B_LED_FORCE_CTRL             RTL8367B_REG_CPU_FORCE_LED_CFG

enum RTL8367B_LEDOP{

    LEDOP_SCAN0=0,         
    LEDOP_SCAN1,        
    LEDOP_PARALLEL,        
    LEDOP_SERIAL, 
    LEDOP_END,
};

enum RTL8367B_LEDSERACT{

    LEDSERACT_HIGH=0,         
    LEDSERACT_LOW,        
    LEDSERACT_MAX,
};

enum RTL8367B_LEDSER{

    LEDSER_16G=0,         
    LEDSER_8G,        
    LEDSER_MAX,
};

enum RTL8367B_LEDCONF{

    LEDCONF_LEDOFF=0,         
    LEDCONF_DUPCOL,        
    LEDCONF_LINK_ACT,        
    LEDCONF_SPD1000,        
    LEDCONF_SPD100,        
    LEDCONF_SPD10,            
    LEDCONF_SPD1000ACT,    
    LEDCONF_SPD100ACT,    
    LEDCONF_SPD10ACT,        
    LEDCONF_SPD10010ACT,  
    LEDCONF_LOOPDETECT,            
    LEDCONF_EEE,            
    LEDCONF_LINKRX,        
    LEDCONF_LINKTX,        
    LEDCONF_MASTER,        
    LEDCONF_ACT,    
    LEDCONF_END    
};

enum RTL8367B_LEDBLINKRATE{

	LEDBLINKRATE_32MS=0, 		
	LEDBLINKRATE_64MS,		
	LEDBLINKRATE_128MS,
	LEDBLINKRATE_256MS,
	LEDBLINKRATE_512MS,
	LEDBLINKRATE_1024MS,
	LEDBLINKRATE_48MS,
	LEDBLINKRATE_96MS,
	LEDBLINKRATE_END,
};

enum RTL8367B_LEDFORCEMODE{

    LEDFORCEMODE_NORMAL=0,
    LEDFORCEMODE_BLINK,
    LEDFORCEMODE_OFF,
    LEDFORCEMODE_ON,
    LEDFORCEMODE_END,
};

enum RTL8367B_LEDFORCERATE{

    LEDFORCERATE_512MS=0,
    LEDFORCERATE_1024MS,
    LEDFORCERATE_2048MS,
    LEDFORCERATE_NORMAL,
    LEDFORCERATE_END,

};


extern ret_t rtl8367b_setAsicLedIndicateInfoConfig(rtk_uint32 ledno, rtk_uint32 config);
extern ret_t rtl8367b_getAsicLedIndicateInfoConfig(rtk_uint32 ledno, rtk_uint32* pConfig);
extern ret_t rtl8367b_setAsicForceLed(rtk_uint32 port, rtk_uint32 group, rtk_uint32 mode);
extern ret_t rtl8367b_getAsicForceLed(rtk_uint32 port, rtk_uint32 group, rtk_uint32* pMode);
extern ret_t rtl8367b_setAsicForceGroupLed(rtk_uint32 groupmask, rtk_uint32 mode);
extern ret_t rtl8367b_getAsicForceGroupLed(rtk_uint32* groupmask, rtk_uint32* pMode);
extern ret_t rtl8367b_setAsicLedBlinkRate(rtk_uint32 blinkRate);
extern ret_t rtl8367b_getAsicLedBlinkRate(rtk_uint32* pBlinkRate);
extern ret_t rtl8367b_setAsicLedForceBlinkRate(rtk_uint32 blinkRate);
extern ret_t rtl8367b_getAsicLedForceBlinkRate(rtk_uint32* pBlinkRate);
extern ret_t rtl8367b_setAsicLedGroupMode(rtk_uint32 mode);
extern ret_t rtl8367b_getAsicLedGroupMode(rtk_uint32* pMode);
extern ret_t rtl8367b_setAsicLedGroupEnable(rtk_uint32 group, rtk_uint32 portmask);
extern ret_t rtl8367b_getAsicLedGroupEnable(rtk_uint32 group, rtk_uint32 *portmask);
extern ret_t rtl8367b_setAsicLedOperationMode(rtk_uint32 mode);
extern ret_t rtl8367b_getAsicLedOperationMode(rtk_uint32 *mode);
extern ret_t rtl8367b_setAsicLedSerialModeConfig(rtk_uint32 active, rtk_uint32 serimode);
extern ret_t rtl8367b_getAsicLedSerialModeConfig(rtk_uint32 *active, rtk_uint32 *serimode);
#endif /*#ifndef _RTL8367B_ASICDRV_LED_H_*/
