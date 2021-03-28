/*
 *  Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file  mailbox.c
 *
 *  \brief Mailbox Device Abstraction Layer APIs
 *
 *   This file contains the device abstraction layer APIs for the
 *   mailbox module. These are used for IPC communication.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "stdint.h"
#include "ti/csl/csl_mailbox.h"

/* ========================================================================== */
/*                          Function Definitions                             */
/* ========================================================================== */
void MailboxReset(uint32_t baseAddr)
{
    /*    Start the soft reset sequence    */
    /* write SOFTRESET field */
    HW_WR_FIELD32(baseAddr + MAILBOX_SYSCONFIG, MAILBOX_SYSCONFIG_SOFTRESET,
                  MAILBOX_SYSCONFIG_SOFTRESET_B1);

    /*    Wait till the reset is complete    */
    while (MAILBOX_SYSCONFIG_SOFTRESET_B1 ==
           HW_RD_FIELD32(baseAddr + MAILBOX_SYSCONFIG,
                         MAILBOX_SYSCONFIG_SOFTRESET))
    {
        /* Do nothing - Busy wait */
    }

    return;
}

void MailboxConfigIdleMode(uint32_t baseAddr, uint32_t idleMode)
{
#if defined(SOC_AM572x)|| defined(SOC_AM571x) || defined(SOC_TDA2XX) || \
    defined(SOC_DRA7XX) || defined(SOC_TDA2EX) || defined(SOC_TDA3XX)
    /*    Configure idle mode    */
    HW_WR_FIELD32(baseAddr + MAILBOX_SYSCONFIG, MAILBOX_SYSCONFIG_SIDLEMODE,
                  idleMode);
#endif
}

uint32_t MailboxGetMessage(uint32_t baseAddr, uint32_t queueId,
                           uint32_t *msgPtr)
{
    uint32_t msgCount;
    uint32_t retval;

    msgCount = MailboxGetMessageCount(baseAddr, queueId);

    if (msgCount > 0U)
    {
        /*    Read message    */
        *msgPtr = HW_RD_REG32(baseAddr + MAILBOX_MESSAGE(queueId));
        retval  = MESSAGE_VALID;
    }
    else
    {
        /*    Queue empty*/
        retval = MESSAGE_INVALID;
    }

    return retval;
}

uint32_t MailboxSendMessage(uint32_t baseAddr, uint32_t queueId, uint32_t msg)
{
    uint32_t fifoFull;
    uint32_t retval;

    /* Read the FIFO Status */
    fifoFull = HW_RD_REG32(baseAddr + MAILBOX_FIFOSTATUS(queueId));
    if (fifoFull == 0U)
    {
        /* FIFO not full write msg */
        MailboxWriteMessage(baseAddr, queueId, msg);
        retval = MESSAGE_VALID;
    }
    else
    {
        retval = MESSAGE_INVALID;
    }

    return retval;
}

void MailboxEnableNewMsgInt(uint32_t baseAddr, uint32_t userId,
                            uint32_t queueId)
{
    /* Set the NewMsgEnable field - Writing zero has no effect */
    HW_WR_REG32(baseAddr + MAILBOX_IRQENABLE_SET(userId), (uint32_t) 0x1 <<
                (queueId * 2U));
}

void MailboxEnableQueueNotFullInt(uint32_t baseAddr, uint32_t userId,
                                  uint32_t queueId)
{
    /* Set the FIFO Not Full field - Writing zero has no effect */
    HW_WR_REG32(baseAddr + MAILBOX_IRQENABLE_SET(userId), (uint32_t) 0x2 <<
                (queueId * 2U));
}

void MailboxDisableNewMsgInt(uint32_t baseAddr, uint32_t userId,
                             uint32_t queueId)
{
    /* Set the NewMsgEnable field - Writing zero has no effect */
    HW_WR_REG32(baseAddr + MAILBOX_IRQENABLE_CLR(userId), (uint32_t) 0x1 <<
                (queueId * 2U));
}

void MailboxDisableQueueNotFullInt(uint32_t baseAddr, uint32_t userId,
                                   uint32_t queueId)
{
    /* Set the FIFO Not Full field - Writing zero has no effect */
    HW_WR_REG32(baseAddr + MAILBOX_IRQENABLE_CLR(userId), (uint32_t) 0x2 <<
                (queueId * 2U));
}

void MailboxClrNewMsgStatus(uint32_t baseAddr, uint32_t userId,
                            uint32_t queueId)
{
    /* Set the NewMsgEnable field - Writing zero has no effect */
    HW_WR_REG32(baseAddr + MAILBOX_IRQSTATUS_CLR(userId), (uint32_t) 0x1 <<
                (queueId * 2U));
}

void MailboxClrQueueNotFullStatus(uint32_t baseAddr, uint32_t userId,
                                  uint32_t queueId)
{
    /* Set the NewMsgEnable field - Writing zero has no effect */
    HW_WR_REG32(baseAddr + MAILBOX_IRQSTATUS_CLR(userId), (uint32_t) 0x2 <<
                (queueId * 2U));
}

uint32_t MailboxGetRawNewMsgStatus(uint32_t baseAddr,
                                   uint32_t userId,
                                   uint32_t queueId)
{
    uint32_t regVal;

    /* Read the IRQSTATUSRAW */
    regVal = HW_RD_REG32(baseAddr + MAILBOX_IRQSTATUS_RAW(userId));

    /* Mask & read the NewMsgStatus for given queueId */
    regVal &= (uint32_t) 0x1 << (queueId * 2U);

    return (regVal >> (queueId * 2U));
}

uint32_t MailboxGetRawQueueNotFullStatus(uint32_t baseAddr,
                                         uint32_t userId,
                                         uint32_t queueId)
{
    uint32_t regVal;

    /* Read the IRQSTATUSRAW */
    regVal = HW_RD_REG32(baseAddr + MAILBOX_IRQSTATUS_RAW(userId));

    /* Mask & read the FIFO Not full for given queueId */
    regVal &= (uint32_t) 0x2 << (queueId * 2U);

    return (regVal >> (queueId * 2U));
}

uint32_t MailboxGetIrqEnableStatus(uint32_t baseAddr,
                                   uint32_t userId,
                                   uint32_t queueId)
{
    uint32_t regVal;

    /* Read the IRQENABLESET */
    regVal = HW_RD_REG32(baseAddr + MAILBOX_IRQENABLE_SET(userId));

    /* Mask & read the FIFO Not full for given queueId */
    regVal &= (uint32_t) 0x1 << (queueId * 2U);

    return (regVal);
}

uint32_t MailboxGetMessageCount(uint32_t baseAddr,
                                uint32_t queueId)
{
    /* Return message count */
    return (HW_RD_REG32(baseAddr + MAILBOX_MSGSTATUS(queueId)));
}

void MailboxWriteMessage(uint32_t baseAddr, uint32_t queueId, uint32_t msg)
{
    /* Write mailbox message */
    HW_WR_REG32(baseAddr + MAILBOX_MESSAGE(queueId), msg);
}

void MailboxWriteEOI(uint32_t baseAddr, uint32_t value)
{
    /* Write mailbox message */
    HW_WR_REG32(baseAddr + MAILBOX_IRQ_EOI, value);
}
/********************************* End of file ******************************/
