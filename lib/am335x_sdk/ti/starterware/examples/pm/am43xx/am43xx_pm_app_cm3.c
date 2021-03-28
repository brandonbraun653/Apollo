/**
 * \file   am43xx_pm_app_cm3.c
 *
 * \brief  Source file containing the CM3 related configuration functions.
 *         These functions will be called by example application.
 *
 */

/**
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "error.h"
#include "hw_prcm.h"
#include "am437x.h"
#include "hw_control_am43xx.h"
#include "hw_prm_wkup.h"
#include "hw_cm_per.h"
#include "mailbox.h"
#include "board.h"
#include "soc.h"
#include "prcm.h"
#include "device.h"
#include "chipdb.h"
#include "cache.h"
#include "mmu.h"
#include "interrupt.h"
#include "example_utils_mmu.h"
#include "console_utils.h"
#include "am43xx_pm_app_cm3_image.h"
#include "am43xx_pm_app_cm3.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* Number of CLK_M_OSC clocks to be seen before exiting deep sleep mode */
#define  PM_DEEP_SLEEP_COUNT                    (0x6A75U)

/*	User Id's	*/
#define MAILBOX_USER_A8 		0
#define MAILBOX_USER_PRU0 		1
#define MAILBOX_USER_PRU1 		2
#define MAILBOX_USER_CM3WKUP 	3

/*	Mailbox Queue's	*/
#define	MAILBOX_QUEUE_0			0
#define	MAILBOX_QUEUE_1			1
#define	MAILBOX_QUEUE_2			2
#define	MAILBOX_QUEUE_3			3
#define	MAILBOX_QUEUE_4			4
#define	MAILBOX_QUEUE_5			5
#define	MAILBOX_QUEUE_6			6
#define	MAILBOX_QUEUE_7			7

#define MESSAGE_VALID			0
#define MESSAGE_INVALID			1

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

extern void romRestoreLocation(void);
void PMAppCm3AckWait(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/*  Flag to indicate M3 event is received   */
volatile uint32_t isM3IntReceived = 0;

/* DS0 data - don't cares are not defined */
pmAppCm3Config_t ds0Data = {
    .param.cmdID = PM_CMD_DS0_MODE,

    .param.resumeAddr = (uint32_t)romRestoreLocation,
    .param.moscState = FALSE,
    .param.deepSleepCount = PM_DEEP_SLEEP_COUNT,

    /* Value is reserved */
    .param.vddMpuVal = 0,

    .param.pdMpuState = PRCM_PD_STATUS_OFF,
    .param.pdMpuRamRetState = FALSE,
    .param.pdMpuL1RetState = FALSE,
    .param.pdMpuL2RetState = FALSE,

    .param.pdPerState = PRCM_PD_STATUS_RET,
    .param.pdPerIcssMemRetState = FALSE,
    .param.pdPerMemRetState = FALSE,
    .param.pdPerOcmcRetState = TRUE,
    .param.pdPerOcmc2RetState = FALSE,

    .param.wakeSources = WAKE_SOURCE_TSC,
    .param.reserved_param2_3 = 0,

    .param.i2cSleepOff = 0xFFFFU,
    .param.i2cWakeOff = 0xFFFFU
};

/*      Command to reset CM3 state machine      */
pmAppCm3Config_t dsDataM3reset = {
    .param.cmdID = 0xE,

    .param.i2cSleepOff = 0xFFFFU,
    .param.i2cWakeOff = 0xFFFFU
};

pmAppCm3Obj_t gPMAppCm3Obj;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 *  \brief   This function configures the deep sleep data in to IPC registers
 *
 * \param     pmDsDataVar	structure variable containing deep sleep data
 *
 * \return 	  None
 */

void PMAppCm3Config(pmAppCm3Config_t pmDsDataVar)
{
	/*	Command ID	*/
	HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_MSG_REG1, pmDsDataVar.param.cmdID);

	if((PM_CMD_RTC_MODE == pmDsDataVar.param.cmdID) ||
			(PM_CMD_RTC_FAST_MODE == pmDsDataVar.param.cmdID))
	{
		/*	RTC time out value	*/
	}
	else
	{
		/*	Resume address	*/
		HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_MSG_REG0, pmDsDataVar.word.resumeAddr);
		/*	deep sleep data	*/
		HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_MSG_REG2, pmDsDataVar.word.param1);
		/*	deep sleep data	*/
		HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_MSG_REG3, pmDsDataVar.word.param2);
        /*      deep sleep data */
        HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_MSG_REG4, pmDsDataVar.word.param3);
        /*      deep sleep data */
        HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_MSG_REG5, pmDsDataVar.word.param4);
	}

    /* IPC M3 interrupt control */
    /* TODO:
    ** HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_INTR, 0xFFFFFFFFU);
    */
}


/**
 *  \brief   This function reads teh trace data from CM3
 *
 * \param     None
 *
 * \return 	  trace		trace data indicating the state of CM3
 */

uint32_t PMAppCm3TraceRead(void)
{
	return HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_MSG_REG4);
}


/**
 *  \brief   This function returns the status of the last sent command
 *
 * \param     None
 *
 * \return 	  status 	status of the last sent command
 */

uint32_t PMAppCm3CmdStatusRead(void)
{
	return (HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_MSG_REG1) >> 16U);
}

/**
 * \brief   This function extracts the firmware version from IPC message register
 *
 * \param   None
 *
 * \return  CM3 firmware version
 */
uint32_t PMAppCm3FwVersionRead(void)
{
    return (HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_IPC_MSG_REG2) & 0xFFFFU);
}

/*
** Clear CM3 event and re-enable the event
*/
void PMAppCm3EventsClear(void)
{
    /* Clear M3_TXEV event */
    HW_WR_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_WAKEM3_TXEV_EOI,
        CTRL_WAKEM3_TXEV_EOI, 1U);

    /* Re-arm M3_TXEV event */
    HW_WR_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_WAKEM3_TXEV_EOI,
        CTRL_WAKEM3_TXEV_EOI, 0U);
}

void PMAppCm3Isr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    isM3IntReceived = 1;
    PMAppCm3EventsClear();
}

int32_t PMAppCm3IntrConfigure(void)
{
    int32_t retStat = S_PASS;
    intcIntrParams_t *pIntrParams = NULL;
    pmAppCm3Obj_t *pInstObj = &gPMAppCm3Obj;

    /* Initialize the Interrupt Controller. */
    INTCInit(FALSE);

    /* Configure edma completion interrupt */
    pIntrParams = &(pInstObj->intrParams);
    pInstObj->intrLine = 32U + 78U;
    pIntrParams->triggerType    = INTC_TRIG_HIGH_LEVEL;
    pIntrParams->priority       = 0x10U;
    pIntrParams->pFnIntrHandler = PMAppCm3Isr;
    pIntrParams->pUserParam     = (void*)pInstObj;
    pIntrParams->isIntrSecure   = FALSE;

    retStat = INTCConfigIntr(pInstObj->intrLine, pIntrParams, FALSE);

    if(S_PASS != retStat)
    {
        CONSOLEUtilsPuts("Interrupt configuration failed for TX.\r\n");
        retStat = E_FAIL;
    }

    return retStat;
}

/*
** Load CM3 image into its memory and release CM3 from reset
*/
void PMAppCm3LoadAndRun(void)
{
    /* Load CM3 SW */
    memcpy((void *)(SOC_WKUP_PROC_UMEM_L4_REG), (const void *)cm3image,
           sizeof(cm3image));

    /* Release CM3 from reset */
    HW_WR_FIELD32(SOC_PRM_WKUP_REG + PRCM_RM_WKUP_RSTCTRL,
          PRCM_RM_WKUP_RSTCTRL_M3_LRST, PRCM_RM_WKUP_RSTCTRL_M3_LRST_CLEAR);
}

/*
** Initializes Mailbox
*/
void PMAppCm3MailboxInit(void)
{
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_MAILBOX, 0U))
    {
        gPMAppCm3Obj.baseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_MAILBOX, 0U);

        /* Enable Mailbox clock */
        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_MAILBOX0_CLKCTRL,
          PRCM_CM_PER_MAILBOX0_CLKCTRL_MODULEMODE,
          PRCM_CM_PER_MAILBOX0_CLKCTRL_MODULEMODE_ENABLE);

        /* Reset Mailbox */
        MLBReset(gPMAppCm3Obj.baseAddr);

        /* Clear new message status */
        MLBNewMessageIntrClr(gPMAppCm3Obj.baseAddr, MAILBOX_USER_CM3WKUP,
            MAILBOX_QUEUE_0);

        /* Enable new message interrupt */
        MLBNewMessageIntrEnable(gPMAppCm3Obj.baseAddr, MAILBOX_USER_CM3WKUP,
            MAILBOX_QUEUE_0, TRUE);

        /* Configure idle mode */
        MLBSetIdleMode(gPMAppCm3Obj.baseAddr, 0x0U);
    }
}

/*
** Initializes Mailbox
*/
void PMAppCm3Init(void)
{
    PMAppCm3IntrConfigure();

    PMAppCm3EventsClear();

    PMAppCm3LoadAndRun();

    PMAppCm3AckWait();

    PMAppCm3MailboxInit();
}

/*
** Wait for ACK from CM3
*/
void PMAppCm3AckWait(void)
{
    /* wait until CM3 TX Event is generated */
    while(!isM3IntReceived);

    while(PM_IN_PROGRESS == PMAppCm3CmdStatusRead())
    {
        PMAppCm3EventsClear();
    }

    switch(PMAppCm3CmdStatusRead())
    {
       case PM_CMD_PASS:
       case PM_WAIT4OK:
           break;

       case PM_CMD_FAIL:
       default:

           /* Command failed or invalid status */
           CONSOLEUtilsPrintf("\n\n ACK Failed \r\n");

           while(1);
    }

    PMAppCm3EventsClear();

    /* Reset interrupt flag */
    isM3IntReceived = 0;
}

/*
** MPU and CM3 Sync
*/
void PMAppCm3Sync(void)
{
    uint32_t tamp;

    /* Write to Mailbox register */
    MLBMessageSend(gPMAppCm3Obj.baseAddr, MAILBOX_QUEUE_0, 0x12345678U);

    /* Wait for ACK from CM3 */
    PMAppCm3AckWait();

    /* Read the message back */
    MLBGetMessage(gPMAppCm3Obj.baseAddr, MAILBOX_QUEUE_0, &tamp);

    /* Clear new message status */
    MLBNewMessageIntrClr(gPMAppCm3Obj.baseAddr, MAILBOX_USER_CM3WKUP, MAILBOX_QUEUE_0);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
