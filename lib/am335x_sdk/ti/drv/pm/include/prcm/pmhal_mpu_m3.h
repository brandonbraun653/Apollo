/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
 *
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

/**
 *  \file  pmhal_mpu_m3.h
 *
 *  \brief This file contains the MPU M3 Proxy interface declarations.
 */

#ifndef PMHAL_MPU_M3_H_
#define PMHAL_MPU_M3_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* CM3 memory start address and length */
#define CM3_UMEM_START_ADDR         (0x44D00000)
#define CM3_UMEM_LENGTH             (16*1024)

#define CM3_DMEM_START_ADDR         (0x44D80000)
#define CM3_DMEM_LENGTH             (8*1024)

/* CM3 intrrupt number on A8 */
#define CM3_TXEV_EOI_A8_INT_NUM     (78)

/* Mailbox User IDs */
#define MAILBOX_USER_A8             (0)
#define MAILBOX_USER_PRU0           (1)
#define MAILBOX_USER_PRU1           (2)
#define MAILBOX_USER_CM3WKUP        (3)

/* Mailbox Queues */
#define MAILBOX_QUEUE_0             (0)

/******************** CMD FIELDS *************************/

/* IPC_MSG_REG1 CMD_STAT field */
#define CMD_STATUS_SHIFT         (0x00000010u)
#define CMD_STATUS_MASK          (0xFFFF0000u)

/* IPC_MSG_REG1 CMD_ID field */
#define CMD_ID_SHIFT             (0x00000000u)
#define CMD_ID_MASK              (0x0000FFFFu)

/********************* COMMANDS **************************/
/* Initiates force_sleep on interconnect clocks.
 * Turns off MPU and PER power domains
 * Programs the RTC alarm register for deasserting pmic_pwr_enable
*/
#define PM_CMD_RTC_MODE         (0x1)

/* Programs the RTC alarm register for deasserting pmic_pwr_enable */
#define PM_CMD_RTC_FAST_MODE    (0x2)

/* Initates force_sleep on interconnect clocks
 * Turns off the MPU and PER power domains
 * Configures the system for disabling MOSC when CM3 executes WFI
*/
#define PM_CMD_DS0_MODE         (0x3)

/* Initates force_sleep on interconnect clocks
 * Turns off the MPU power domains
 * Configures the system for disabling MOSC when CM3 executes WFI
*/
#define PM_CMD_DS1_MODE         (0x5)

/*	Configures the system for disabling MOSC when CM3 executes WFI */
#define PM_CMD_DS2_MODE         (0x7)

/*  Configures the system for Standby mode when CM3 executes WFI */
#define PM_CMD_STANDBY_MODE     (0xb)

/*  Configures the system for CPU idle mode when CM3 executes WFI */
#define PM_CMD_CPUIDLE_MODE     (0x10)

/******************** COMMAND STATUS *********************/

/* In init phase this denotes that CM3 was initialized successfully. 
When other commands are to be executed, this indicates completion of command */
#define PM_CMD_PASS          (0x0)

/* Early indication of command being carried out */
#define PM_IN_PROGRESS       (0x3)

/* In init phase 0x2 denotes CM3 could not initialize properly. 
When other tasks are to be done, this indicates some error in carrying out the task. */
#define PM_CMD_FAIL          (0x1)

/* CM3 INTC will catch the next WFI of A8 and continue with the pre-defined sequence */
#define PM_WAIT4OK           (0x2)

/*
 ** Wake Source
 */
#define WAKE_SOURCE_TSC                   (0x0100u)
#define WAKE_SOURCE_UART                  (0x0010u)
#define WAKE_SOURCE_TMR                   (0x0008u)
#define WAKE_SOURCE_GPIO                  (0x0020u)
#define WAKE_SOURCE_RTC                   (0x0004u)
#define WAKE_SOURCE_MPU                   (0x0800u)

/********************* TRACE BITS **************************/

#define PM_RESET_SEQUENCE_STARTED              (0x0)
#define PM_ENTERING_MAIN_LOOP                  (0x1)
#define PM_WAITING_FOR_MBX_INTERRUPT           (0x2)
#define PM_RECEIVED_MBX_INTERRUPT              (0x3)
#define PM_WAITING_FOR_TRIGGER_EVENT_FROM_HOST (0x4)
#define PM_PARSING_CMD_ID                      (0x5)
#define PM_VOL_SCL_CMD_RECD                    (0x7)
#define PM_INITIATING_TX_WITH_PMIC             (0x8)
#define PM_RECD_ACK_FROM_PMIC                  (0x9)
#define PM_RECD_NACK_FROM_PMIC                 (0x10)
#define PM_CLK_DOMAIN_TRANS_STARTED            (0x11)
#define	PM_PWR_DOMAIN_TRANS_STARTED            (0x12)

/**************** Memory config values **********************/

#define PM_MOSC_STATE_OFF               (0x0)
#define PM_MOSC_STATE_ON                (0x1)

#define PM_MPU_POWERSTATE_OFF           (PRM_MPU_PM_MPU_PWRSTCTRL_POWERSTATE_OFF)
#define PM_MPU_POWERSTATE_RET           (PRM_MPU_PM_MPU_PWRSTCTRL_POWERSTATE_RET)
#define PM_MPU_POWERSTATE_ON            (PRM_MPU_PM_MPU_PWRSTCTRL_POWERSTATE_ON)


#define PM_MPU_RAM_RETSTATE_ON          (PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_RETSTATE >> \
                                         PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_RETSTATE_SHIFT)
#define PM_MPU_RAM_RETSTATE_OFF         !(PM_MPU_RAM_RETSTATE_ON)


#define PM_MPU_L1_RETSTATE_ON           (PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L1_RETSTATE >> \
                                         PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L1_RETSTATE_SHIFT)
#define PM_MPU_L1_RETSTATE_OFF          !(PM_MPU_L1_RETSTATE_ON)


#define PM_MPU_L2_RETSTATE_ON           (PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L2_RETSTATE >> \
                                         PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L2_RETSTATE_SHIFT)
#define PM_MPU_L2_RETSTATE_OFF          !(PM_MPU_L2_RETSTATE_ON)


#define PM_MPU_RAM_ONSTATE_OFF          (PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_ONSTATE_MEM_OFF)
#define PM_MPU_RAM_ONSTATE_ON           (PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_ONSTATE_MEM_ON)


#define PM_PER_POWERSTATE_OFF           (PRM_PER_PM_PER_PWRSTCTRL_POWERSTATE_OFF)
#define PM_PER_POWERSTATE_RET           (PRM_PER_PM_PER_PWRSTCTRL_POWERSTATE_RET)
#define PM_PER_POWERSTATE_ON            (PRM_PER_PM_PER_PWRSTCTRL_POWERSTATE_ON)


#define PM_PER_ICSS_RAM_RETSTATE_RET    (PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_RET)
#define PM_PER_ICSS_RAM_RETSTATE_OFF    (PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_OFF)


#define	PM_PER_MEM_RETSTATE_RET         (PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_RETSTATE_RET)
#define	PM_PER_MEM_RETSTATE_OFF         (PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_RETSTATE_OFF)


#define PM_PER_OCMC_RAM_RETSTATE_RET    (PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_RETSTATE_RET)
#define PM_PER_OCMC_RAM_RETSTATE_OFF    (PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_RETSTATE_OFF)


#define PM_PER_ICSS_RAM_ONSTATE_OFF     (PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_RESERVED2)
#define PM_PER_ICSS_RAM_ONSTATE_ON      (PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_ON)


#define PM_PER_MEM_ONSTATE_OFF          (PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_RESERVED2)
#define PM_PER_MEM_ONSTATE_ON           (PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_ON)


#define PM_PER_OCMC_RAM_ONSTATE_RET     (PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_RET)
#define PM_PER_OCMC_RAM_ONSTATE_OFF     (PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_OFF)
#define PM_PER_OCMC_RAM_ONSTATE_ON      (PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_ON)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* deep sleep data */
typedef struct
    {
    /* Address to where the control should jump on wake up on A8	*/
    unsigned int resumeAddr;

    /* MOSC to be kept on (1) or off (0) */
    unsigned int moscState :1;
    /* Count of how many OSC clocks needs to be seen before exiting deep sleep
     mode. Default = 0x6A75 */
    unsigned int deepSleepCount :16;

    /* If vdd_mpu is to be lowered, vdd_mpu in 0.01mV steps */
    unsigned int vddMpuVal :15;

    /* Powerstate of PD_MPU */
    unsigned int pdMpuState :2;
    /* State of Sabertooth RAM memory when power domain is in retention */
    unsigned int pdMpuRamRetState :1;
    /* State of L1 memory when power domain is in retention */
    unsigned int pdMpul1RetState :1;
    /* State of L2 memory when power domain is in retention */
    unsigned int pdMpul2RetState :1;
    /* State of Sabertooth RAM memory when power domain is ON */
    unsigned int pdMpuRamOnState :2;

    /* Powerstate of PD_PER */
    unsigned int pdPerState :2;
    /* State of ICSS memory when power domain is in retention */
    unsigned int pdPerIcssMemRetState :1;
    /* State of other memories when power domain is in retention */
    unsigned int pdPerMemRetState :1; 
    /* State of OCMC memory when power domain is in retention */	
    unsigned int pdPerOcmcRetState :1; 
    /* State of ICSS memory when power domain is ON */
    unsigned int pdPerIcssMemOnState :2;
    /* State of other memories when power domain is ON */ 	
    unsigned int pdPerMemOnState :2; 
    /* State of OCMC memory when power domain is ON */
    unsigned int pdPerOcmcOnState :2; 

    /* Wake sources */
    /* USB, I2C0, RTC_Timer, RTC_Alarm, Timer0, Timer1, UART0, GPIO0_Wake0, \
     GPIO0_Wake1, MPU, WDT0, WDT1, ADTSC*/
    unsigned int wakeSources :13;

    unsigned int reserved :1;

    /* Command id to uniquely identify the intented deep sleep state	*/
    unsigned int cmdID:16;

    /* Delay for RTC alarm timeout. Default = 2secs */
    unsigned char rtcTimeoutVal :4;

}pmAttributes;

/* deep sleep data - This structure is used to copy the data together,
 * instead of copying bit-by-bit.
 *
 *  4 bytes - resume address
 *  4 bytes - deep sleep data
 *  4 bytes - deep sleep data
 *  2 bytes - command id
 *  1 byte  - RTC timeout value
 */
typedef struct
{
    unsigned int word0;
    unsigned int word1;
    unsigned int word2;
    unsigned short short1;
    char byte1;
}pmCmdParams;

typedef union
{
    pmAttributes dsDataBits;
    pmCmdParams  dsParams;
}deepSleepData;


/* ========================================================================== */
/*                      Global Variables Declarations                         */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Function to register the M3 interrupt to the MPU
 *
 * \param   None.
 *
 * \return  None.
 */
void PMHALMpuM3IntRegister(void);

/**
 * \brief   Function to clear M3 events
 *
 * \param   None.
 *
 * \return  None.
 */
void PMHALMpuM3EventsClear(void);

/**
 * \brief   Function to load and run the M3 firmware
 *
 * \param   image   Pointer to M3 firmware image
 *
 * \param   size    Size of M3 firmware image in bytes
 *
 * \return  None.
 */
void PMHALMpuM3LoadAndRun(const void *image, uint32_t size);

/**
 * \brief   Function to wait for M3 transmit event
 *
 * \param   responseWait    wait for CM3 TX event
 *
 * \return  status  PM_SUCCESS If event is received
 *                  PM_FAIL If event is not received
 */
int32_t PMHALMpuM3WaitForM3TxEvent(uint8_t responseWait);

/**
 * \brief   Function to initialize the mailbox used to communicate with the M3
 *
 * \param   None.
 *
 * \return  None.
 */
void PMHALMpuM3MailBoxInit(void);

/**
 * \brief   Function to prepare the MPU for entering idle modes
 *
 * \param   None.
 *
 * \return  None.
 */
void PMHALMpuIdlePrepare(void);

/**
 * \brief   Function to reset the M3 firmware state machine
 *
 * \param   None.
 *
 * \return  None.
 */
void PMHALMpuM3ResetStateMachine(void);

#ifdef __cplusplus
}
#endif

#endif

