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
 * \file pmhal_mpu_m3.c
 *
 * \brief   MPU M3 Proxy interface API definition.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <ti/csl/hw_types.h>
#include <ti/osal/HwiP.h>
#include "pm_types.h"
#include "pmhal_prcm.h"
#include "pmhal_mpu_m3.h"
#include "pmhal_prcm_includes.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define MLB_MESSAGE(n)                                (0x40U + ((n) * 0x4U))
#define MLB_FIFOSTS(n)                                (0x80U + ((n) * 0x4U))
#define MLB_MSGSTS(n)                                 (0xc0U + ((n) * 0x4U))
#define MLB_IRQSTS_RAW(n)                             (0x100U + ((n) * 0x10U))
#define MLB_IRQSTS_CLR(n)                             (0x104U + ((n) * 0x10U))
#define MLB_IRQEN_SET(n)                              (0x108U + ((n) * 0x10U))
#define MLB_IRQEN_CLR(n)                              (0x10cU + ((n) * 0x10U))

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Cortex a8 M3 event ISR handler
 *
 * \param   None
 *
 * \return  None
 */
static void PmhalMpuM3Isr(void);

/**
 * \brief   This function returns the status of the last sent command
 *
 * \param   None
 *
 * \return  status    status of the last sent command
 */
static unsigned short PmhalMpuReadCmdStatus(void);

/**
 *  \brief   This function configures the deep sleep data in to IPC registers
 *
 * \param    pmDsDataVar structure variable containing deep sleep data
 *
 * \return   None
 */
static void PmhalMpuConfigIPCRegs(deepSleepData pmDsDataVar);

/**
 *  \brief   Generate Mailbox interrupt to CM3 by writing a dummy value to
 *           mailbox reg
 *
 * \param    None
 *
 * \return   status   status of the mailbox interrupt generation
 */
static int32_t PmhalMpuGenerateMailboxInt(void);

/**
 *  \brief   Clear mail box messages
 *
 * \param    None
 *
 * \return   status   status of the mailbox clear
 */
static int32_t PmhalMpuClearMailboxMsg(void);

/**
 *  \brief   MPU and CM3 Sync
 *
 * \param    responseWait Wait for interrupt response when enabled
 *
 * \return   None   status of the mailbox interrupt generation
 */
static void PmhalMpuM3Sync(uint8_t responseWait);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

extern void romRestoreLocation(void);

/* HWI handle */
HwiP_Handle hwiHandle = NULL;

/* Flag to indicate M3 event is received   */
volatile unsigned int isM3IntReceived = 0;

/* Standby data - don't cares are not defined */
deepSleepData cpuIdleData = {
    .dsDataBits.cmdID = PM_CMD_CPUIDLE_MODE,

    .dsDataBits.wakeSources = WAKE_SOURCE_MPU,
};


/*      Command to reset CM3 state machine      */
deepSleepData dsDataM3reset = {
    .dsDataBits.cmdID = 0xE
};


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void PMHALMpuM3IntRegister(void)
{
    HwiP_Params hwiParams;
    HwiP_Fxn    hwiFxn;

    /* Configure and enable M3 interrupt to a8 */
    HwiP_Params_init(&hwiParams);
    hwiParams.name = "M3_TXEV_EOI";
    hwiParams.priority = 1;
    hwiFxn = (HwiP_Fxn) (&PmhalMpuM3Isr);
    hwiParams.arg = 0;
    hwiHandle = HwiP_create(CM3_TXEV_EOI_A8_INT_NUM, hwiFxn, &hwiParams);
    /* Clear any previous interrupts to ensure we are not getting
     * false interrupts */
    HwiP_clearInterrupt(CM3_TXEV_EOI_A8_INT_NUM);
    HwiP_enableInterrupt(CM3_TXEV_EOI_A8_INT_NUM);
}

void PMHALMpuM3EventsClear(void)
{
    /* Clear M3_TXEV event */
    HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_M3_TXEV_EOI,
                      CONTROL_M3_TXEV_EOI_M3_TXEV_EOI,
                      CONTROL_M3_TXEV_EOI_M3_TXEV_EOI_SHIFT,
                      CONTROL_M3_TXEV_EOI_M3_TXEV_EOI);

    /* Re-arm M3_TXEV event */
    HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_M3_TXEV_EOI,
                      CONTROL_M3_TXEV_EOI_M3_TXEV_EOI,
                      CONTROL_M3_TXEV_EOI_M3_TXEV_EOI_SHIFT,
                      (~CONTROL_M3_TXEV_EOI_M3_TXEV_EOI));
}

void PMHALMpuM3LoadAndRun(const void *image, uint32_t size)
{
    /* Load CM3 SW */
    memcpy((void *)(CM3_UMEM_START_ADDR), image, size);

    /* Release CM3 from reset */
    HW_WR_FIELD32_RAW(SOC_PRM_WKUP_REGS + PRM_WKUP_RM_WKUP_RSTCTRL,
                      PRM_WKUP_RM_WKUP_RSTCTRL_WKUP_M3_LRST,
                      PRM_WKUP_RM_WKUP_RSTCTRL_WKUP_M3_LRST_SHIFT,
                      PRM_WKUP_RM_WKUP_RSTCTRL_WKUP_M3_LRST_CLEAR);
}

int32_t PMHALMpuM3WaitForM3TxEvent(uint8_t responseWait)
{
    pmErrCode_t status = PM_SUCCESS;

    if (responseWait == TRUE)
    {
        /* wait until CM3 TX Event is generated */
        while(!isM3IntReceived);
    }

    while(PM_IN_PROGRESS == PmhalMpuReadCmdStatus())
    {
        PMHALMpuM3EventsClear();
    }

    switch(PmhalMpuReadCmdStatus())
    {
       case PM_CMD_PASS:
       case PM_WAIT4OK:
           break;
       case PM_CMD_FAIL:
       default:
           status = PM_FAIL;
           break;
    }

    PMHALMpuM3EventsClear();

    /* Reset interrupt flag */
    isM3IntReceived = 0;

    return status;
}

void PMHALMpuM3MailBoxInit(void)
{
    uint32_t regVal = (0x1U << (MAILBOX_QUEUE_0 * 2U));

    /* Reset Mailbox */
    /* Replace - MLBReset(SOC_MAILBOX_0_REGS); */
    /*  Start the soft reset sequence   */
    HW_WR_FIELD32(SOC_MAILBOX_0_REGS + MLB_SYSCONFIG, MLB_SYSCONFIG_SOFTRESET,
        MLB_SYSCONFIG_SOFTRESET_RESET);

    /*  Wait till the reset is complete */
    while(MLB_SYSCONFIG_SOFTRESET_RESET ==
          HW_RD_FIELD32(SOC_MAILBOX_0_REGS + MLB_SYSCONFIG,
                        MLB_SYSCONFIG_SOFTRESET));

    /* Clear new message status */
    /* Replace - MLBNewMessageIntrClr(SOC_MAILBOX_0_REGS, MAILBOX_USER_CM3WKUP,
                         MAILBOX_QUEUE_0); */
    HW_WR_REG32(SOC_MAILBOX_0_REGS + MLB_IRQSTS_CLR(MAILBOX_USER_CM3WKUP),
                regVal);

    /* Enable new message interrupt */
    /* Replace - MLBNewMessageIntrEnable(SOC_MAILBOX_0_REGS,
                                         MAILBOX_USER_CM3WKUP,
                                         MAILBOX_QUEUE_0, TRUE); */
    HW_WR_REG32(SOC_MAILBOX_0_REGS + MLB_IRQEN_SET(MAILBOX_USER_CM3WKUP),
                regVal);

    /* Configure idle mode */
    /* Replace - MLBSetIdleMode(SOC_MAILBOX_0_REGS,
                                MLB_SYSCONFIG_SIDLEMODE_FORCEIDLE); */
    /*  Configure idle mode */
    HW_WR_FIELD32(SOC_MAILBOX_0_REGS + MLB_SYSCONFIG, MLB_SYSCONFIG_SIDLEMODE,
                  MLB_SYSCONFIG_SIDLEMODE_FORCEIDLE);
}

void PMHALMpuIdlePrepare(void)
{
    deepSleepData dsData = cpuIdleData;
    uint8_t       responseWait;

    /* For now wakeSource is always MPU wake - Will wake on any peripheral
     * interrupt */
    dsData.dsDataBits.wakeSources = WAKE_SOURCE_MPU;

    PmhalMpuConfigIPCRegs(dsData);
    if (dsData.dsDataBits.cmdID == PM_CMD_CPUIDLE_MODE)
    {
        /* Firmware won't generate CM3 TX event since CPUIDLE has a fast
         * trigger */
        responseWait = FALSE;
    }
    else
    {
        responseWait = TRUE;
    }

    PmhalMpuM3Sync(responseWait);
}

void PMHALMpuM3ResetStateMachine(void)
{
    /* Reset CM3 State Machine */
    PmhalMpuConfigIPCRegs(dsDataM3reset);
    PmhalMpuM3Sync(FALSE);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void PmhalMpuM3Isr(void)
{
    isM3IntReceived = 1;
    PMHALMpuM3EventsClear();
    HwiP_clearInterrupt(CM3_TXEV_EOI_A8_INT_NUM);
}

static unsigned short PmhalMpuReadCmdStatus(void)
{
    unsigned short status;

    status = (unsigned short) HW_RD_FIELD32(SOC_CONTROL_REGS +
                                            CONTROL_IPC_MSG_REG(1),
                                            CMD_STATUS);
    return (status);
}

static void PmhalMpuConfigIPCRegs(deepSleepData pmDsDataVar)
{
    /* Command ID */
    HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_IPC_MSG_REG(1),
                      CONTROL_IPC_MSG_REG1_IPC_MSG_REG1,
                      CONTROL_IPC_MSG_REG1_IPC_MSG_REG1_SHIFT,
                      pmDsDataVar.dsParams.short1);

    if((PM_CMD_RTC_MODE == pmDsDataVar.dsDataBits.cmdID) ||
       (PM_CMD_RTC_FAST_MODE == pmDsDataVar.dsDataBits.cmdID))
    {
        /* RTC time out value */
        HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_IPC_MSG_REG(2),
                      CONTROL_IPC_MSG_REG2_IPC_MSG_REG2,
                      CONTROL_IPC_MSG_REG2_IPC_MSG_REG2_SHIFT,
                      pmDsDataVar.dsParams.byte1);
    }
    else
    {
        /* Resume address */
        HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_IPC_MSG_REG(0),
                      CONTROL_IPC_MSG_REG0_IPC_MSG_REG0,
                      CONTROL_IPC_MSG_REG0_IPC_MSG_REG0_SHIFT,
                      pmDsDataVar.dsParams.word0);
        /* deep sleep data */
        HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_IPC_MSG_REG(2),
                      CONTROL_IPC_MSG_REG2_IPC_MSG_REG2,
                      CONTROL_IPC_MSG_REG2_IPC_MSG_REG2_SHIFT,
                      pmDsDataVar.dsParams.word1);
        /* deep sleep data */
        HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_IPC_MSG_REG(3),
                      CONTROL_IPC_MSG_REG3_IPC_MSG_REG3,
                      CONTROL_IPC_MSG_REG3_IPC_MSG_REG3_SHIFT,
                      pmDsDataVar.dsParams.word2);
    }
}

static int32_t PmhalMpuGenerateMailboxInt(void)
{
    uint32_t retVal = PM_FAIL;

    /* Write to Mailbox register */
    /* Replace - MBsendMessage(SOC_MAILBOX_0_REGS, MAILBOX_QUEUE_0,
                               0x12345678u); */
    uint32_t regFieldVal =
        HW_RD_FIELD32(SOC_MAILBOX_0_REGS + MLB_FIFOSTS(MAILBOX_QUEUE_0),
                      MLB_FIFOSTS_0_FIFOFULLMBM);

    /*  Check if queue is not full  */
    if(MLB_FIFOSTS_0_FIFOFULLMBM_FULL != regFieldVal)
    {
        /*  Write message   */
        HW_WR_REG32(SOC_MAILBOX_0_REGS + MLB_MESSAGE(MAILBOX_QUEUE_0),
                    0x12345678u);
        retVal = PM_SUCCESS;
    }

    return retVal;
}

static int32_t PmhalMpuClearMailboxMsg(void)
{
    int32_t   retVal = PM_FAIL;
    uint32_t  regVal = (0x1U << (MAILBOX_QUEUE_0 * 2U));

    /* Read the message back */
    /* Replace - MBgetMessage(MAILBOX_0_BASE_ADDR, MAILBOX_QUEUE_0, &tamp); */
    uint32_t  regFieldVal =
        HW_RD_FIELD32(SOC_MAILBOX_0_REGS + MLB_MSGSTS(MAILBOX_QUEUE_0),
                      MLB_MSGSTS_0_NBOFMSGMBM);

    /*  Check if queue is not empty */
    if(regFieldVal > 0U)
    {
        /*  Read message */
        HW_RD_REG32(SOC_MAILBOX_0_REGS + MLB_MESSAGE(MAILBOX_QUEUE_0));
        retVal = PM_SUCCESS;
    }

    /* Clear new message status */
    /* Replace - MBclrNewMsgStatus(MAILBOX_0_BASE_ADDR, MAILBOX_USER_CM3WKUP,
                                   MAILBOX_QUEUE_0); */
    HW_WR_REG32(SOC_MAILBOX_0_REGS + MLB_IRQSTS_CLR(MAILBOX_USER_CM3WKUP),
                regVal);

    return retVal;
}

static void PmhalMpuM3Sync(uint8_t responseWait)
{
    /* Generate mailbox interrupt to CM3 */
    PmhalMpuGenerateMailboxInt();

    /* Wait for ACK from CM3 */
    PMHALMpuM3WaitForM3TxEvent(responseWait);

    /* Clear the message in mailbox */
    PmhalMpuClearMailboxMsg();
}

