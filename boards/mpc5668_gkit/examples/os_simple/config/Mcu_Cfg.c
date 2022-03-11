/*
* Configuration of module: Mcu (Mcu_Cfg.c)
*
* Created by:              
* Copyright:               
*
* Configured for (MCU):    MPC5668
*
* Module vendor:           ArcCore
* Generator version:       2.0.4
*
* Generated by Arctic Studio (http://arccore.com) 
*/


#ifndef MCU_CFG_C_
#define MCU_CFG_C_

#include "Mcu.h"



const Mcu_ClockSettingConfigType Mcu_ClockSettingConfigData[] =
{
  {
    .McuClockReferencePointFrequency = 40000000UL,
    .Pll1    = 9,
    .Pll2    = 40,
    .Pll3    = 1,
  },
};


const Mcu_ConfigType McuConfigData[] = {
  {
	.McuClockSrcFailureNotification = 0,
	.McuRamSectors = MCU_NBR_OF_RAM_SECTIONS,
	.McuClockSettings = 1,
	.McuDefaultClockSettings = 0,
	.McuClockSettingConfig = &Mcu_ClockSettingConfigData[0],
	.McuRamSectorSettingConfig = NULL,
  }
};

#endif /*MCU_CFG_C_*/
