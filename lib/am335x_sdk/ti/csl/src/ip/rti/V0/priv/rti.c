/*
 *   Copyright (c) Texas Instruments Incorporated 2015
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
 *  \file     rti.c
 *
 *  \brief    This file contains the implementation of the APIs present in the
 *            device abstraction layer file of RTI.
 *            This also contains some related macros.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/cslr_rti.h>
#include "ti/csl/src/ip/rti/V0/rti.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define RTI_DWWDPRLD_MULTIPLIER_SHIFT    (13U)
#define RTI_RTIWDKEY_WDKEY_INVALID_WRITE (0x4444U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

static int32_t RTIDwwdChkReaction(uint32_t dwwdReaction);
static int32_t RTIDwwdChkWindowSize(uint32_t dwwdReaction);
static inline void RTIDwwdWriteWinSz(uint32_t baseAddr, uint32_t dwwdWindowSize);
static inline void RTIDwwdWriteReaction(uint32_t baseAddr, uint32_t dwwdReaction);
static inline uint32_t RTIDwwdReadWinSz(uint32_t baseAddr);
static inline uint32_t RTIDwwdReadReaction(uint32_t baseAddr);
static inline uint32_t RTIDwwdReadCurrentDownCounter(uint32_t baseAddr);
static inline uint32_t RTIDwwdReadTimeOut(uint32_t baseAddr);



/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function implementations                          */
/* ========================================================================== */

 /* internal function to Configure window in which watch-dog should be serviced */
static inline void RTIDwwdWriteWinSz(uint32_t baseAddr, uint32_t dwwdWindowSize)
{
     HW_WR_FIELD32( baseAddr + RTI_RTIDWWDSIZECTRL,
                    RTI_RTIDWWDSIZECTRL_DWWDSIZE,
                    dwwdWindowSize);
}

/* internal function for Configuring Digital Windowed Watchdog Reaction */
static inline void RTIDwwdWriteReaction(uint32_t baseAddr, uint32_t dwwdReaction)
{
     (HW_WR_FIELD32(baseAddr + RTI_RTIDWWDRXNCTRL,
                    RTI_RTIDWWDRXNCTRL_DWWDRXN,
                    dwwdReaction));
}
/* internal function to read the window size */
static inline uint32_t RTIDwwdReadWinSz(uint32_t baseAddr)
{
    uint32_t   windowSize;
    /* Get configured Window Size */
    windowSize = HW_RD_REG32(baseAddr + RTI_RTIDWWDSIZECTRL);
    return (windowSize);
}

/* Internal function to read the reaction register */
static inline uint32_t RTIDwwdReadReaction(uint32_t baseAddr)
{
    uint32_t dwwdReaction;

    /* Get Windowed Watchdog Reaction */
    dwwdReaction = HW_RD_FIELD32(baseAddr + RTI_RTIDWWDRXNCTRL,
                                 RTI_RTIDWWDRXNCTRL_DWWDRXN);

    return dwwdReaction;
}

static inline uint32_t RTIDwwdReadTimeOut(uint32_t baseAddr)
{
    uint32_t timeOutValue;

    timeOutValue = ((HW_RD_REG32(baseAddr + RTI_RTIDWDPRLD)
                     << RTI_DWWDPRLD_MULTIPLIER_SHIFT) |
                    RTI_DWD_MIN_PRELOAD_VAL);

    return timeOutValue;
}

static inline uint32_t RTIDwwdReadCurrentDownCounter(uint32_t baseAddr)
{
    return HW_RD_REG32(baseAddr + RTI_RTIDWDCNTR);
}


/* Check if the reaction value is valid */
static int32_t RTIDwwdChkReaction(uint32_t dwwdReaction)
{
    int32_t retVal = CSL_PASS;
    if ((dwwdReaction != RTI_DWWD_REACTION_GENERATE_RESET) &&
        (dwwdReaction != RTI_DWWD_REACTION_GENERATE_NMI))
    {
        retVal = CSL_EFAIL;
    }
    return (retVal);
}

/* Verify if the WindowSize argument is valid */
static int32_t RTIDwwdChkWindowSize(uint32_t dwwdWindowSize)
{
    int32_t retVal;
    switch (dwwdWindowSize)
    {
        case RTI_DWWD_WINDOWSIZE_100_PERCENT:
        case RTI_DWWD_WINDOWSIZE_50_PERCENT:
        case RTI_DWWD_WINDOWSIZE_25_PERCENT:
        case RTI_DWWD_WINDOWSIZE_12_5_PERCENT:
        case RTI_DWWD_WINDOWSIZE_6_25_PERCENT:
        case RTI_DWWD_WINDOWSIZE_3_125_PERCENT:
            retVal = CSL_PASS;
            break;
        default:
            retVal = CSL_EFAIL;
            break;
    }
    return (retVal);
}


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTI_DWWDReadStaticRegs(uint32_t baseAddr, rtiDwwdStaticRegs_t *pStaticRegs)
{
    int32_t readStatus = CSL_EFAIL;
    if ((baseAddr != ((uint32_t) NULL)) &&
       (pStaticRegs != (NULL_PTR)))
    {
        pStaticRegs->RTI_DWDCTRL = HW_RD_REG32(baseAddr + RTI_RTIDWDCTRL);
        pStaticRegs->RTI_DWDPRLD = HW_RD_REG32(baseAddr + RTI_RTIDWDPRLD);
        pStaticRegs->RTI_WWDRXNCTRL = HW_RD_REG32(baseAddr + RTI_RTIDWWDRXNCTRL);
        pStaticRegs->RTI_WWDSIZECTRL = HW_RD_REG32(baseAddr + RTI_RTIDWWDSIZECTRL);
        readStatus = CSL_PASS;
    }
    return (readStatus);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210) REQ_TAG(PRSDK-2209)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdWindowConfig(uint32_t baseAddr,
                            uint32_t dwwdReaction,
                            uint32_t dwwdPreloadVal,
                            uint32_t dwwdWindowSize)
{
    int32_t configStatus = CSL_EFAIL;

    if ( (baseAddr                             != ((uint32_t) NULL)) &&
         (RTIDwwdChkReaction(dwwdReaction)     == CSL_PASS)          &&
         (RTIDwwdChkWindowSize(dwwdWindowSize) == CSL_PASS) )
    {
        /* Configure window in which watch-dog should be serviced */
        RTIDwwdWriteWinSz(baseAddr, dwwdWindowSize);
        /* Initialize DWD Expiration Period */
        configStatus = RTIDwwdSetPreload(baseAddr, dwwdPreloadVal);
        if (configStatus == CSL_PASS)
        {
            /* Configure Digital Windowed Watchdog Reaction */
            RTIDwwdWriteReaction(baseAddr, dwwdReaction);
        }
    }
    return configStatus;
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdWindowVerifyConfig(uint32_t baseAddr,
                                  uint32_t dwwdReaction,
                                  uint32_t dwwdPreloadVal,
                                  uint32_t dwwdWindowSize)
{
    int32_t    cslRet, verifyStatus = CSL_EFAIL;
    uint32_t   reaction_l, preload_l, winSz_l, preload;

    cslRet = RTIDwwdGetPreload(baseAddr, &preload_l);
    preload = (dwwdPreloadVal >>  ((uint32_t) RTI_DWWDPRLD_MULTIPLIER_SHIFT));

    if (cslRet == CSL_PASS)
    {
        cslRet = RTIDwwdGetWindowSize(baseAddr, &winSz_l);
    }

    if (cslRet == CSL_PASS)
    {
        reaction_l = RTIDwwdReadReaction(baseAddr);
    }

    if (cslRet == CSL_PASS)
    {
        if ((dwwdReaction   == reaction_l) &&
            (preload        == preload_l)  &&
            (dwwdWindowSize == winSz_l) )
        {
            verifyStatus = CSL_PASS;
        }
    }
    return (verifyStatus);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdCounterEnable(uint32_t baseAddr)
{
    int32_t retVal = CSL_EFAIL;
    if (baseAddr  != ((uint32_t) NULL))
    {
        /* Enable DWWD by writing pre-defined value '0xA98559DA' to RTIDWDCTRL    */
        HW_WR_REG32(baseAddr + RTI_RTIDWDCTRL,
                    RTI_RTIDWDCTRL_DWDCTRL_ENABLE);
        retVal = CSL_PASS;
    }

    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2211)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdIsCounterEnabled(uint32_t baseAddr, uint32_t *pIsCounterEnabled)
{
    int32_t    retVal = CSL_EFAIL;
    if ((baseAddr            != ((uint32_t)   NULL)) &&
        (pIsCounterEnabled   != (NULL_PTR)))
    {
        /* Enable DWWD by writing pre-defined value '0xA98559DA' to RTIDWDCTRL    */
        if(RTI_RTIDWDCTRL_DWDCTRL_ENABLE == HW_RD_REG32(baseAddr + RTI_RTIDWDCTRL))
        {
            *pIsCounterEnabled = CSL_TRUE;
        }
        else
        {
            *pIsCounterEnabled = CSL_FALSE;
        }
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t  RTIDwwdService(uint32_t baseAddr)
{
    int32_t retVal = CSL_EFAIL;
    if (baseAddr  != ((uint32_t) NULL))
    {
        HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
                      RTI_RTIWDKEY_WDKEY,
                      RTI_RTIWDKEY_WDKEY_FIRST_WRITE);
        HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
                      RTI_RTIWDKEY_WDKEY,
                      RTI_RTIWDKEY_WDKEY_SECOND_WRITE);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdGetLastResetStatus(uint32_t baseAddr, rtiDwwdResetStatus_t *pResetStatus)
{
    int32_t              retVal = CSL_EFAIL;

    if ((baseAddr            != ((uint32_t)   NULL)) &&
        (pResetStatus        != (NULL_PTR)))
    {
        if (1U == HW_RD_FIELD32(baseAddr + RTI_RTIWDSTATUS,
                                RTI_RTIWDSTATUS_DWDST))
        {
            *pResetStatus = RTI_DWWD_RESET_STATUS_GENERATED;
        }
        else
        {
            *pResetStatus = RTI_DWWD_RESET_STATUS_NOT_GENERATED;
        }
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdSetPreload(uint32_t baseAddr, uint32_t dwwdPreloadVal)
{
    int32_t preloadConfigStatus = CSL_EFAIL;
    uint32_t dwwdPreloadVal_l;

    if (baseAddr  != ((uint32_t) NULL))
    {
        dwwdPreloadVal_l = (dwwdPreloadVal >>
                          ((uint32_t) RTI_DWWDPRLD_MULTIPLIER_SHIFT));
        if ((uint32_t) RTI_RTIDWDPRLD_DWDPRLD_MAX > dwwdPreloadVal_l)
        {
            /* Initialize DWD Expiration Period */
            HW_WR_FIELD32(baseAddr + RTI_RTIDWDPRLD,
                          RTI_RTIDWDPRLD_DWDPRLD,
                          dwwdPreloadVal_l);
            preloadConfigStatus = CSL_PASS;
        }
    }
    return preloadConfigStatus;
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdSetReaction(uint32_t baseAddr, uint32_t dwwdReaction)
{
    int32_t retVal = CSL_EFAIL;
    if (baseAddr  != ((uint32_t) NULL))
    {
        retVal = CSL_PASS;
        RTIDwwdWriteReaction(baseAddr, dwwdReaction);
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t  RTIDwwdSetWindowSize(uint32_t baseAddr, uint32_t dwwdWindowSize)
{
    int32_t retVal = CSL_EFAIL;
    if (baseAddr  != ((uint32_t) NULL))
    {
        RTIDwwdWriteWinSz(baseAddr, dwwdWindowSize);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2211)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdIsClosedWindow(uint32_t baseAddr, uint32_t *pIsClosedWindow)
{
    uint32_t closedWindowstatus, currentDownCounter, windowSizeShift;
    uint32_t windowStartTime, timeOutValue, windowSize;

    int32_t retVal = CSL_EFAIL;
    if ((baseAddr        != ((uint32_t) NULL)) &&
        (pIsClosedWindow != (NULL_PTR)))
    {
        windowSizeShift    = (uint32_t)
                             RTI_RTIDWWDSIZECTRL_DWWDSIZE_100_PERCENT_SHIFT;
        /* Get configured Window Size */
        windowSize = RTIDwwdReadWinSz(baseAddr);
        switch (windowSize)
        {
            case RTI_DWWD_WINDOWSIZE_100_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_100_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_50_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_50_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_25_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_25_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_12_5_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_12_5_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_6_25_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_6_25_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_3_125_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_3_125_PERCENT_SHIFT;
                break;
            default:
                break;
        }
        timeOutValue    = RTIDwwdReadTimeOut(baseAddr);
        windowStartTime = (timeOutValue /
                           (uint32_t) ((uint32_t) 0x1U << windowSizeShift));
        /* Get current down counter */
        currentDownCounter = HW_RD_REG32(baseAddr + RTI_RTIDWDCNTR);
        if (currentDownCounter > windowStartTime)
        {
            closedWindowstatus = CSL_TRUE;
        }
        else
        {
            closedWindowstatus = CSL_FALSE;
        }
        /* Update the status */
        *pIsClosedWindow = closedWindowstatus;
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdGenerateSysReset(uint32_t baseAddr)
{
    int32_t retVal = CSL_EFAIL;
    if (baseAddr  != ((uint32_t) NULL))
    {
        /* Generate system reset by writing value other than pre-defined
         *  second write value '0x0000A35C' to RTI_RTIWDKEY */
        HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
                      RTI_RTIWDKEY_WDKEY,
                      RTI_RTIWDKEY_WDKEY_FIRST_WRITE);
        HW_WR_FIELD32(baseAddr + RTI_RTIWDKEY,
                      RTI_RTIWDKEY_WDKEY,
                      RTI_RTIWDKEY_WDKEY_INVALID_WRITE);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2211)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdGetStatus(uint32_t baseAddr, uint32_t *pDwwdStatus)
{
    int32_t retVal = CSL_EFAIL;
    if ((baseAddr     != ((uint32_t) NULL)) &&
         (pDwwdStatus != (NULL_PTR)))
    {
        *pDwwdStatus = HW_RD_REG32(baseAddr + RTI_RTIWDSTATUS);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdClearStatus(uint32_t baseAddr, uint32_t status)
{
    int32_t retVal = CSL_EFAIL;
    if (baseAddr  != ((uint32_t) NULL))
    {
        HW_WR_REG32(baseAddr + RTI_RTIWDSTATUS, status);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdGetCurrentDownCounter(uint32_t baseAddr, uint32_t *pCurDownCounter)
{
    int32_t retVal = CSL_EFAIL;
    if ((baseAddr           != ((uint32_t)   NULL)) &&
        (pCurDownCounter    != (NULL_PTR)))
    {
        *pCurDownCounter = RTIDwwdReadCurrentDownCounter(baseAddr);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2211)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIIsDwwdKeySequenceCorrect(uint32_t baseAddr, uint32_t *pKeySeqStatus)
{
    int32_t retVal = CSL_EFAIL;
    if ((baseAddr           != ((uint32_t)   NULL)) &&
        (pKeySeqStatus      != (NULL_PTR)))
    {
        if (1U == (HW_RD_FIELD32(baseAddr + RTI_RTIWDSTATUS,
                                 RTI_RTIWDSTATUS_KEYST)))
        {
            *pKeySeqStatus = (uint32_t) RTI_RTIWDSTATUS_KEYST_INCORRECT_KEY;
        }
        else
        {
            *pKeySeqStatus = (uint32_t) RTI_RTIWDSTATUS_KEYST_CORRECT_KEY;
        }
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdGetPreload(uint32_t baseAddr, uint32_t *pPreloadVal)
{
    int32_t retVal = CSL_EFAIL;
    if ((baseAddr           != ((uint32_t)   NULL)) &&
        (pPreloadVal        != (NULL_PTR)))
    {
        *pPreloadVal = HW_RD_FIELD32(baseAddr + RTI_RTIDWDPRLD,
                                   RTI_RTIDWDPRLD_DWDPRLD);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdGetWindowSize(uint32_t baseAddr, uint32_t *pWinSize)
{
    int32_t retVal = CSL_EFAIL;
    if ((baseAddr           != ((uint32_t)   NULL)) &&
        (pWinSize           != (NULL_PTR)))
    {
        *pWinSize = RTIDwwdReadWinSz(baseAddr);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdGetTimeOut(uint32_t baseAddr, uint32_t *pTimeOutVal)
{
    int32_t retVal = CSL_EFAIL;
    if ((baseAddr           != ((uint32_t)   NULL)) &&
        (pTimeOutVal        != (NULL_PTR)))
    {
        *pTimeOutVal = RTIDwwdReadTimeOut(baseAddr);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdGetTicksToOpenWindow(uint32_t baseAddr, uint32_t *pClkTicks)
{
    uint32_t currentDownCounter, windowSizeShift, timeOutValue;
    uint32_t windowStartTime, windowSize;
    int32_t retVal = CSL_EFAIL;
    if ((baseAddr           != ((uint32_t)   NULL)) &&
        (pClkTicks          != (NULL_PTR)))
    {
        *pClkTicks        = ((uint32_t) (0U));
        windowSizeShift = (uint32_t)
                          RTI_RTIDWWDSIZECTRL_DWWDSIZE_100_PERCENT_SHIFT;
        /* Get configured Window Size */
        windowSize = HW_RD_REG32(baseAddr + RTI_RTIDWWDSIZECTRL);
        switch (windowSize)
        {
            case RTI_DWWD_WINDOWSIZE_100_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_100_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_50_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_50_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_25_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_25_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_12_5_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_12_5_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_6_25_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_6_25_PERCENT_SHIFT;
                break;
            case RTI_DWWD_WINDOWSIZE_3_125_PERCENT:
                windowSizeShift = (uint32_t)
                                  RTI_RTIDWWDSIZECTRL_DWWDSIZE_3_125_PERCENT_SHIFT;
                break;
            default:
                break;
        }
        timeOutValue    = RTIDwwdReadTimeOut(baseAddr);
        windowStartTime = (timeOutValue /
                           (uint32_t) ((uint32_t) 0x1U << windowSizeShift));
        /* Get current down counter */
        currentDownCounter = RTIDwwdReadCurrentDownCounter(baseAddr);
        if (currentDownCounter > windowStartTime)
        {
            *pClkTicks = (currentDownCounter - windowStartTime);
        }
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2210)
 * Design: did_csl_rti_dwwt
 */
int32_t RTIDwwdGetReaction(uint32_t baseAddr, rtiDwwdReaction_t *pReaction)
{
    int32_t retVal = CSL_EFAIL;
    if ((baseAddr           != ((uint32_t)   NULL)) &&
        (pReaction          != (NULL_PTR)))
    {
        *pReaction = RTIDwwdReadReaction(baseAddr);
        retVal = CSL_PASS;
    }
    return (retVal);
}
/* Nothing past this point */
