/**
 *  \file   mailbox.c
 *
 *  \brief  This file contains the device abstraction layer API implementation
 *          of the Mailbox.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "error.h"
#include "hw_types.h"
#include "hw_mailbox.h"
#include "mailbox.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define MLB_MESSAGE(n)                                (0x40U + ((n) * 0x4U))
#define MLB_FIFOSTS(n)                                (0x80U + ((n) * 0x4U))
#define MLB_MSGSTS(n)                                 (0xc0U + ((n) * 0x4U))
#define MLB_IRQSTS_RAW(n)                             (0x100U + ((n) * 0x10U))
#define MLB_IRQSTS_CLR(n)                             (0x104U + ((n) * 0x10U))
#define MLB_IRQEN_SET(n)                              (0x108U + ((n) * 0x10U))
#define MLB_IRQEN_CLR(n)                              (0x10cU + ((n) * 0x10U))

/* MESSAGE */
#define MLB_MESSAGE_MESSAGEVALUEMBM_SHIFT                     (0U)
#define MLB_MESSAGE_MESSAGEVALUEMBM_MASK                      (0xffffffffU)

/* FIFOSTATUS_0 */
#define MLB_FIFOSTS_MESSAGEVALUEMBM_SHIFT                     (1U)
#define MLB_FIFOSTS_MESSAGEVALUEMBM_MASK                      (0xfffffffeU)

#define MLB_FIFOSTS_FIFOFULLMBM_SHIFT                         (0U)
#define MLB_FIFOSTS_FIFOFULLMBM_MASK                          (0x00000001U)
#define MLB_FIFOSTS_FIFOFULLMBM_NOTFULL                        (0U)
#define MLB_FIFOSTS_FIFOFULLMBM_FULL                           (1U)

/* MESSAGESTATUS */
#define MLB_MSGSTS_NBOFMSGMBM_SHIFT                           (0U)
#define MLB_MSGSTS_NBOFMSGMBM_MASK                            (0x00000007U)

/* IRQSTATUS_RAW */
#define MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_SHIFT                   (0U)
#define MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_MASK                    (0x00000001U)
#define MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_NOEVENT                  (0U)
#define MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_EVENTPENDING             (1U)
#define MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_NOACTION                 (0U)
#define MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_SETEVENT                 (1U)

#define MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_SHIFT                  (1U)
#define MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_MASK                   (0x00000002U)
#define MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_NOEVENT                 (0U)
#define MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_EVENTPENDING            (1U)
#define MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_NOACTION                (0U)
#define MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_SETEVENT                (1U)

/* IRQSTATUS_CLR */
#define MLB_IRQSTS_CLR_NEWMSGSTSUUMB0_SHIFT                   (0U)
#define MLB_IRQSTS_CLR_NEWMSGSTSUUMB0_MASK                    (0x00000001U)
#define MLB_IRQSTS_CLR_NEWMSGSTSUUMB0_NOEVENT                  (0U)
#define MLB_IRQSTS_CLR_NEWMSGSTSUUMB0_EVENTPENDING             (1U)
#define MLB_IRQSTS_CLR_NEWMSGSTSUUMB0_NOACTION                 (0U)
#define MLB_IRQSTS_CLR_NEWMSGSTSUUMB0_SETEVENT                 (1U)

#define MLB_IRQSTS_CLR_NOTFULLSTSUUMB0_SHIFT                  (1U)
#define MLB_IRQSTS_CLR_NOTFULLSTSUUMB0_MASK                   (0x00000002U)
#define MLB_IRQSTS_CLR_NOTFULLSTSUUMB0_NOEVENT                 (0U)
#define MLB_IRQSTS_CLR_NOTFULLSTSUUMB0_EVENTPENDING            (1U)
#define MLB_IRQSTS_CLR_NOTFULLSTSUUMB0_NOACTION                (0U)
#define MLB_IRQSTS_CLR_NOTFULLSTSUUMB0_SETEVENT                (1U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void MLBReset(uint32_t baseAddr)
{
    /*  Start the soft reset sequence   */
    HW_WR_FIELD32(baseAddr + MLB_SYSCONFIG, MLB_SYSCONFIG_SOFTRESET,
        MLB_SYSCONFIG_SOFTRESET_RESET);

    /*  Wait till the reset is complete */
    while(MLB_SYSCONFIG_SOFTRESET_RESET ==
        HW_RD_FIELD32(baseAddr + MLB_SYSCONFIG, MLB_SYSCONFIG_SOFTRESET));
}

void MLBSetIdleMode(uint32_t baseAddr, uint32_t idleMode)
{
    /*  Configure idle mode */
    HW_WR_FIELD32(baseAddr + MLB_SYSCONFIG, MLB_SYSCONFIG_SIDLEMODE, idleMode);
}

int32_t MLBGetMessage(uint32_t baseAddr, uint32_t queueId, uint32_t *pMessage)
{
    uint32_t regFieldVal =
    HW_RD_FIELD32(baseAddr + MLB_MSGSTS(queueId), MLB_MSGSTS_NBOFMSGMBM);
    int32_t retVal = E_FAIL;

    /*  Check if queue is not empty */
    if(regFieldVal > 0U)
    {
        /*  Read message    */
        *pMessage = HW_RD_REG32(baseAddr + MLB_MESSAGE(queueId));
        retVal = S_PASS;
    }

    return retVal;
}

uint32_t MLBMessageSend(uint32_t baseAddr, uint32_t queueId, uint32_t message)
{
    uint32_t regFieldVal =
        HW_RD_FIELD32(baseAddr + MLB_FIFOSTS(queueId), MLB_FIFOSTS_FIFOFULLMBM);
    uint32_t retVal = E_FAIL;

    /*  Check if queue is not full  */
    if(MLB_FIFOSTS_FIFOFULLMBM_FULL != regFieldVal)
    {
        /*  Write message   */
        HW_WR_REG32(baseAddr + MLB_MESSAGE(queueId), message);
        retVal = S_PASS;
    }

    return retVal;
}

void MLBNewMessageIntrEnable(uint32_t baseAddr,
                             uint32_t userId,
                             uint32_t queueId,
                             uint32_t enableNewMessageIntr)
{
    uint32_t regVal = (0x1U << (queueId * 2U));

    if(FALSE == enableNewMessageIntr)
    {
        HW_WR_REG32(baseAddr + MLB_IRQEN_CLR(userId), regVal);
    }
    else
    {
        HW_WR_REG32(baseAddr + MLB_IRQEN_SET(userId), regVal);
    }
}

void MLBNotFullIntrEnable(uint32_t baseAddr,
                          uint32_t userId,
                          uint32_t queueId,
                          uint32_t enableNotFullIntr)
{
    uint32_t regVal = (0x1U << ((queueId * 2U) + 1U));

    if(FALSE == enableNotFullIntr)
    {
        HW_WR_REG32(baseAddr + MLB_IRQEN_CLR(userId), regVal);
    }
    else
    {
        HW_WR_REG32(baseAddr + MLB_IRQEN_SET(userId), regVal);
    }
}

uint32_t MLBNewMessageIntrStatus(uint32_t baseAddr,
                                 uint32_t userId,
                                 uint32_t queueId)
{
    uint32_t regFieldValShift = queueId * 2U;
    uint32_t regFieldValMask = (0x1U << regFieldValShift);
    uint32_t retVal = FALSE;

    if(0U != (HW_RD_REG32(baseAddr + MLB_IRQSTS_RAW(userId)) & regFieldValMask))
    {
        retVal = TRUE;
    }

    return retVal;
}

uint32_t MLBNotFullIntrStatus(uint32_t baseAddr,
                              uint32_t userId,
                              uint32_t queueId)
{
    uint32_t regFieldValShift = (queueId * 2U) + 1U;
    uint32_t regFieldValMask = (0x1U << regFieldValShift);
    uint32_t retVal = FALSE;

    if(0U != (HW_RD_REG32(baseAddr + MLB_IRQSTS_RAW(userId)) & regFieldValMask))
    {
        retVal = TRUE;
    }

    return retVal;
}

void MLBNewMessageIntrClr(uint32_t baseAddr,
                          uint32_t userId,
                          uint32_t queueId)
{
    uint32_t regVal = (0x1U << (queueId * 2U));
    HW_WR_REG32(baseAddr + MLB_IRQSTS_CLR(userId), regVal);
}

void MLBNotFullIntrClr(uint32_t baseAddr,
                       uint32_t userId,
                       uint32_t queueId)
{
    uint32_t regVal = (0x1U << ((queueId * 2U) + 1U));
    HW_WR_REG32(baseAddr + MLB_IRQSTS_CLR(userId), regVal);
}

void MLBSetRawNewMessageIntrStatus(uint32_t baseAddr,
                                   uint32_t userId,
                                   uint32_t queueId)
{
    uint32_t regVal = (0x1U << (queueId * 2U));
    HW_WR_REG32(baseAddr + MLB_IRQSTS_RAW(userId), regVal);
}

void MLBSetRawNotFullIntrStatus(uint32_t baseAddr,
                                uint32_t userId,
                                uint32_t queueId)
{
    uint32_t regVal = (0x1U << ((queueId * 2U) + 1U));
    HW_WR_REG32(baseAddr + MLB_IRQSTS_RAW(userId), regVal);
}

/* ========================================================================== */
/*                          Deprecated Function Definitions                   */
/* ========================================================================== */
