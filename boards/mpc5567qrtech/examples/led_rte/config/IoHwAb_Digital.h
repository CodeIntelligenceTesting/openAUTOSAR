/*
* Configuration of module: IoHwAb (IoHwAb_Digital.h)
*
* Created by:              
* Copyright:               
*
* Configured for (MCU):    MPC5567
*
* Module vendor:           ArcCore
* Generator version:       3.1.3
*
* Generated by Arctic Studio (http://arccore.com) 
*/

#ifndef IOHWAB_DIGITAL_H_
#define IOHWAB_DIGITAL_H_

#if !(((IOHWAB_SW_MAJOR_VERSION == 1) && (IOHWAB_SW_MINOR_VERSION == 0)) )
#error IoHwAb: Configuration file expected BSW module version to be 1.0.*
#endif

/**************************************** Digital outputs *****************************************/

#define IOHWAB_SIGNAL_DIGITALSIGNAL_RED_LED	0
Std_ReturnType IoHwAb_Set_Digital_DigitalSignal_Red_Led(IoHwAb_LevelType newValue, IoHwAb_StatusType *status);

/***************************************** Digital inputs *****************************************/

/************************************* Parameterized digital **************************************/

Std_ReturnType IoHwAb_Set_Digital(IoHwAb_SignalType signal, IoHwAb_LevelType newValue, IoHwAb_StatusType *status);

Std_ReturnType IoHwAb_Get_Digital(IoHwAb_SignalType signal, IoHwAb_LevelType *value, IoHwAb_StatusType *status);

/*********************************** Digital validation macros ************************************/

#define IOHWAB_SIGNAL_COUNT_DIGITAL_OUTPUT	1

#define IOHWAB_SIGNAL_IS_VALID_DIGITAL_OUTPUT(signal) \
		(IOHWAB_SIGNAL_DIGITALSIGNAL_RED_LED == signal) || \
		(FALSE)

#define IOHWAB_SIGNAL_COUNT_DIGITAL_INPUT	0

#define IOHWAB_SIGNAL_IS_VALID_DIGITAL_INPUT(signal) \
		(FALSE)


#endif /* IOHWAB_DIGITAL_H_ */
