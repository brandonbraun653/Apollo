/**
 *  \file   am43xx_pm_app_cm3.h
 *
 *  \brief  This file contains the function declarations and data structures
 *          corresponding to the PM.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef AM43XX_PM_APP_CM3_H_
#define AM43XX_PM_APP_CM3_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "i2c.h"
#include "interrupt.h"
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/********************** MACROS ***************************/

/* CM3 memory start address and length */
#define CM3_UMEM_START_ADDR         (0x44D00000)
#define CM3_UMEM_LENGTH             (16*1024)

#define CM3_DMEM_START_ADDR         (0x44D80000)
#define CM3_DMEM_LENGTH             (8*1024)

/* CM3 intrrupt number on A8 */
#define CM3_TXEV_EOI_A8_INT_NUM     (78)

/* Mailbox0 base address */
#define MAILBOX_0_BASE_ADDR         (0x480C8000)

/********************* COMMANDS **************************/
/*	Initiates force_sleep on interconnect clocks.
 *	Turns off MPU and PER power domains
 *	Programs the RTC alarm register for deasserting pmic_pwr_enable
*/
#define PM_CMD_RTC_MODE			(0x1)

/*	Programs the RTC alarm register for deasserting pmic_pwr_enable	*/
#define PM_CMD_RTC_FAST_MODE	(0x2)

/*	Initates force_sleep on interconnect clocks
 *	Turns off the MPU and PER power domains
 *	Configures the system for disabling MOSC when CM3 executes WFI
*/
#define PM_CMD_DS0_MODE			(0x4)

/*	Initates force_sleep on interconnect clocks
 *	Turns off the MPU power domains
 *	Configures the system for disabling MOSC when CM3 executes WFI
*/
#define PM_CMD_DS1_MODE			(0x6)

/*	Configures the system for disabling MOSC when CM3 executes WFI	*/
#define PM_CMD_DS2_MODE			(0x8)

/*  Configures the system for Standby mode when CM3 executes WFI */
#define PM_CMD_STANDBY_MODE     (0xc)

/******************** COMMAND STATUS *********************/

/* In init phase this denotes that CM3 was initialized successfully.
When other commands are to be executed, this indicates completion of command */
#define PM_CMD_PASS			(0x0)

/* Early indication of command being carried out */
#define PM_IN_PROGRESS		(0x3)

/* In init phase 0x2 denotes CM3 could not initialize properly.
When other tasks are to be done, this indicates some error in carrying out the task. */
#define PM_CMD_FAIL			(0x1)

/* CM3 INTC will catch the next WFI of A8 and continue with the pre-defined sequence */
#define PM_WAIT4OK			(0x2)

/********************* TRACE BITS **************************/

#define PM_RESET_SEQUENCE_STARTED			(0x0)
#define PM_ENTERING_MAIN_LOOP				(0x1)
#define PM_WAITING_FOR_MBX_INTERRUPT		(0x2)
#define PM_RECEIVED_MBX_INTERRUPT			(0x3)
#define PM_WAITING_FOR_TRIGGER_EVENT_FROM_HOST	(0x4)
#define PM_PARSING_CMD_ID					(0x5)
#define PM_VOL_SCL_CMD_RECD					(0x7)
#define PM_INITIATING_TX_WITH_PMIC			(0x8)
#define PM_RECD_ACK_FROM_PMIC				(0x9)
#define PM_RECD_NACK_FROM_PMIC				(0x10)
#define PM_CLK_DOMAIN_TRANS_STARTED			(0x11)
#define	PM_PWR_DOMAIN_TRANS_STARTED			(0x12)

/* poting macros*/

#define RM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_RET	PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_RESERVED1
#define RM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_OFF	PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_RESERVED2
#define RM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_ON		PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_ON

#define RM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_RET		PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_RESERVED1
#define RM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_OFF		PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_RESERVED2
#define RM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_ON		PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_ON

#define RM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_RET		PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_RET
#define RM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_OFF		PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_OFF
#define RM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_ON		PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_ON


/**************** Memory config values **********************/

#define PM_MOSC_STATE_OFF				(0x0)
#define PM_MOSC_STATE_ON				(0x1)

#define PM_MPU_POWERSTATE_OFF   		(PRM_MPU_PM_MPU_PWRSTCTRL_POWERSTATE_OFF)
#define PM_MPU_POWERSTATE_RET   		(PRM_MPU_PM_MPU_PWRSTCTRL_POWERSTATE_RET)
#define PM_MPU_POWERSTATE_ON   			(PRM_MPU_PM_MPU_PWRSTCTRL_POWERSTATE_ON)


#define PM_MPU_RAM_RETSTATE_ON			(PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_RETSTATE >> \
										PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_RETSTATE_SHIFT)
#define PM_MPU_RAM_RETSTATE_OFF			!(PM_MPU_RAM_RETSTATE_ON)


#define PM_MPU_L1_RETSTATE_ON			(PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L1_RETSTATE >> \
										PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L1_RETSTATE_SHIFT)
#define PM_MPU_L1_RETSTATE_OFF			!(PM_MPU_L1_RETSTATE_ON)


#define PM_MPU_L2_RETSTATE_ON			(PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L2_RETSTATE >> \
										PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L2_RETSTATE_SHIFT)
#define PM_MPU_L2_RETSTATE_OFF			!(PM_MPU_L2_RETSTATE_ON)


#define PM_MPU_RAM_ONSTATE_OFF			(PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_ONSTATE_MEM_OFF)
#define PM_MPU_RAM_ONSTATE_ON			(PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_ONSTATE_MEM_ON)


#define PM_PER_POWERSTATE_OFF   		(PRM_PER_PM_PER_PWRSTCTRL_POWERSTATE_OFF)
#define PM_PER_POWERSTATE_RET   		(PRM_PER_PM_PER_PWRSTCTRL_POWERSTATE_RET)
#define PM_PER_POWERSTATE_ON   			(PRM_PER_PM_PER_PWRSTCTRL_POWERSTATE_ON)


#define PM_PER_ICSS_RAM_RETSTATE_RET	(PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_RET)
#define PM_PER_ICSS_RAM_RETSTATE_OFF	(PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_OFF)


#define	PM_PER_MEM_RETSTATE_RET			(PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_RETSTATE_RET)
#define	PM_PER_MEM_RETSTATE_OFF			(PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_RETSTATE_OFF)


#define PM_PER_OCMC_RAM_RETSTATE_RET	(PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_RETSTATE_RET)
#define PM_PER_OCMC_RAM_RETSTATE_OFF	(PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_RETSTATE_OFF)


#define PM_PER_ICSS_RAM_ONSTATE_OFF		(PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_RESERVED2)
#define PM_PER_ICSS_RAM_ONSTATE_ON		(PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_ON)


#define PM_PER_MEM_ONSTATE_OFF			(PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_RESERVED2)
#define PM_PER_MEM_ONSTATE_ON			(PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_ON)


#define PM_PER_OCMC_RAM_ONSTATE_RET		(PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_RET)
#define PM_PER_OCMC_RAM_ONSTATE_OFF		(PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_OFF)
#define PM_PER_OCMC_RAM_ONSTATE_ON		(PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_ON)

/*
** Wake Source
*/
#define WAKE_SOURCE_TSC                   (0x0100u)
#define WAKE_SOURCE_UART                  (0x0010u)
#define WAKE_SOURCE_TMR                   (0x0008u)
#define WAKE_SOURCE_GPIO                  (0x0020u)
#define WAKE_SOURCE_RTC                   (0x0004u)
#define WAKE_SOURCE_MPU                   (0x0800u)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief enumerates the wake configurations */
typedef enum pmAppCm3WakeSrc
{
    PM_APP_CM3_WAKE_SRC_MIN = 0U,
    /**< Minimum value of the wake sources */
    PM_APP_CM3_WAKE_SRC_USB = PM_APP_CM3_WAKE_SRC_MIN,
    /**< USB wake source */
    PM_APP_CM3_WAKE_SRC_I2C,
    /**< I2C wake source */
    PM_APP_CM3_WAKE_SRC_RTC_ALARM,
    /**< RTC alarm wake source */
    PM_APP_CM3_WAKE_SRC_TIMER1,
    /**< Timer1 wake source */
    PM_APP_CM3_WAKE_SRC_UART,
    /**< UART wake source */
    PM_APP_CM3_WAKE_SRC_GPIO0_WAKE0,
    /**< GPIO0 wake0 source */
    PM_APP_CM3_WAKE_SRC_GPIO0_WAKE1,
    /**< GPIO0 wake1 source */
    PM_APP_CM3_WAKE_SRC_WDT1,
    /**< WDT1 wake source */
    PM_APP_CM3_WAKE_SRC_ADC_TSC,
    /**< ADC touch screen wake source */
    PM_APP_CM3_WAKE_SRC_RTC_TIMER,
    /**< RTC timer wake source */
    PM_APP_CM3_WAKE_SRC_USBWOUT0,
    /**< RTC timer wake source */
    PM_APP_CM3_WAKE_SRC_MPU,
    /**< Interrupt sources */
    PM_APP_CM3_WAKE_SRC_USBWOUT1,
    /**< Interrupt sources */
    PM_APP_CM3_WAKE_SRC_MAX = PM_APP_CM3_WAKE_SRC_USBWOUT1
    /**< Maximum value of the wake sources */
}pmAppCm3WakeSrc_t;

/*	deep sleep data */
typedef struct pmAppCm3ConfigParam
{
	/*	Address to where the control should jump on wake up on A8	*/
	uint32_t resumeAddr;

	/*	Command id to uniquely identify the intented deep sleep state	*/
	uint32_t cmdID:16;

    uint32_t reserved_cmd :16;

	/* MOSC to be kept on (1) or off (0) */
	uint32_t moscState :1;
	/* Count of how many OSC clocks needs to be seen before exiting deep sleep
		mode. Default = 0x6A75 */
	uint32_t deepSleepCount :16;

	/* If vdd_mpu is to be lowered, vdd_mpu in 0.01mV steps */
	uint32_t vddMpuVal :15;

	/* Powerstate of PD_MPU */
	uint32_t pdMpuState :2;
	/* State of Sabertooth RAM memory when power domain is in retention */
	uint32_t pdMpuRamRetState :1;
	/* State of L1 memory when power domain is in retention */
	uint32_t pdMpuL1RetState :1;
	/* State of L2 memory when power domain is in retention */
	uint32_t pdMpuL2RetState :1;

	uint32_t reserved_param2_0 :2;

	/* Powerstate of PD_PER */
	uint32_t pdPerState :2;
	/* State of ICSS memory when power domain is in retention */
	uint32_t pdPerIcssMemRetState :1;
	/* State of other memories when power domain is in retention */
	uint32_t pdPerMemRetState :1;
	/* State of OCMC memory when power domain is in retention */
	uint32_t pdPerOcmcRetState :1;
	/* State of OCMC2 memory when power domain is in retention */
	uint32_t pdPerOcmc2RetState :1;

	uint32_t reserved_param2_1 :5;

	/* Wake sources */
	/* USB, I2C0, RTC_Timer, RTC_Alarm, Timer0, Timer1, UART0, GPIO0_Wake0, \
		GPIO0_Wake1, MPU, WDT0, WDT1, ADTSC*/
	uint32_t wakeSources :13;

    uint32_t reserved_param2_3 :1;

    uint32_t memType :3;

    uint32_t vttState :1;

    uint32_t vttGpioPin :6;

    uint32_t ioIsolation :1;

    uint32_t reserved_param3 :21;

    uint32_t i2cSleepOff :16;

    uint32_t i2cWakeOff :16;
}pmAppCm3ConfigParam_t;


/*	deep sleep data - This structure is used to copy the data together, \
	instead of copying bit-by-bit. \

	4 bytes - resume address \
	4 bytes - deep sleep data \
	4 bytes - deep sleep data \
	2 bytes - command id \
	1 byte  - RTC timeout value \
*/
typedef struct pmAppCm3ConfigWord
{
	uint32_t resumeAddr;
	uint32_t cmdIdStatus;
	uint32_t param1;
    uint32_t param2;
    uint32_t param3;
    uint32_t param4;
}pmAppCm3ConfigWord_t;

typedef union pmAppCm3Config
{
	pmAppCm3ConfigParam_t param;
	pmAppCm3ConfigWord_t  word;
}pmAppCm3Config_t;

/**
 *  \brief structure defining the parameters required for interrupt configuration.
 */
typedef struct pmAppCm3Obj
{
    uint32_t baseAddr;
    /**< Base address */
    uint32_t userId;
    /**< User Index of MPU */
    uint32_t intrLine;
    /**< Interrupt line. */
    intcIntrParams_t intrParams;
    /**< RX interrupt configuration. */
}pmAppCm3Obj_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

extern pmAppCm3Config_t ds0Data;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief     This function configures the deep sleep data in to IPC registers
 *
 *  \param     pmDsDataVar	structure variable containing deep sleep data
 *
 */
void PMAppCm3Config(pmAppCm3Config_t pmDsDataVar);

/**
 *  \brief     This function reads teh trace data from CM3
 *
 *  \retval    trace  trace data indicating the state of CM3
 */
uint32_t PMAppCm3TraceRead(void);

/**
 *  \brief     This function returns the status of the last sent command
 *
 *  \retval    status  Status of the last sent command
 */
uint32_t PMAppCm3CmdStatusRead(void);

/**
 *  \brief   This function extracts the firmware version from IPC message
 *           register
 *
 *  \retval  CM3 firmware version
 */
uint32_t PMAppCm3FwVersionRead(void);

/*
** Clear CM3 event and re-enable the event
*/
void PMAppCm3EventsClear(void);

/**
 *  \brief   This function returns the status of the last sent command
 *
 *  \param   intrId      Interrupt number to which the interrupt event is mapped.
 *  \param   cpuId       Id of the CPU to which interrupt is raised.
 *  \param   puserParam  Parameter to be passed to the ISR.
 */
void PMAppCm3Isr(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/**
 *  \brief   Initializes the interrupt controller and configures it with
 *           different parameters like triggertype, Interrupt Priority
 *           and registers the Interrupt Service Routine to be invoked
 *           when the Interrupt is raised.
 *
 *  \retval  S_PASS     If Interrupt Configuration successful
 *  \retval  E_FAIL     If Interrupt Configuration fails
 */
int32_t PMAppCm3IntrConfigure(void);

/*
** Load CM3 image into its memory and release CM3 from reset
*/
void PMAppCm3LoadAndRun(void);

/*
** Initializes Mailbox
*/
void PMAppCm3Init(void);

/*
** MPU and CM3 Sync
*/
void PMAppCm3Sync(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef AM43XX_PM_APP_CM3_H_ */
