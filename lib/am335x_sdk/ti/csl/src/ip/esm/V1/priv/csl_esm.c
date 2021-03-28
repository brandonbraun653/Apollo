/*
 *   Copyright (c) Texas Instruments Incorporated 2017-2019
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
 *  \file     csl_esm.c
 *
 *  \brief    This file contains the implementation of the APIs present in the
 *            device abstraction layer file of ESM.
 *            This also contains some related macros.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_esm.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define ESM_NUM_INTR_PER_GRP              (32U)
#define ESM_INTR_GRP_NUM                  (32U)
#define ESM_MAX_NUM_INTRS                 (1024U)
#define ESM_ESM_PIN_CTRL_KEY_RESET_VAL    (0x5U)
#define ESM_SFT_RST_KEY_RESET_VAL         (0xFU)
#define ESM_EN_KEY_MASK                   (0xFU)
#define ESM_EN_KEY_ENBALE_VAL             (0xFU)
#define ESM_EN_KEY_DISABLE_VAL            (0x0U)


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 *  Requirement: REQ_TAG(PRSDK-1694)
 *  Design: did_csl_esm_err_foce_mode
 */
int32_t ESMSetMode(uint32_t baseAddr, esmOperationMode_t mode)
{
    int32_t    retVal = CSL_EBADARGS;
    uint32_t   regVal;

    /* Map the mode passed to supported values */
    if (mode == ESM_OPERATION_MODE_NORMAL)
    {
        regVal = ((uint32_t)(ESM_OPERATION_MODE_NORMAL));
    }
    else
    {
        regVal = ((uint32_t)(ESM_OPERATION_MODE_ERROR_FORCE));
    }

    if (baseAddr != ((uint32_t) (0u)))
    {
        HW_WR_FIELD32(baseAddr + CSL_ESM_PIN_CTRL, CSL_ESM_PIN_CTRL_KEY, regVal);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetMode(uint32_t baseAddr, esmOperationMode_t *pMode)
{
    int32_t    retVal = CSL_EBADARGS;
    uint32_t   regVal;
    if (baseAddr != ((uint32_t) (0u)))
    {
        if (pMode != ((void *) 0))
        {
            regVal = HW_RD_FIELD32(baseAddr + CSL_ESM_PIN_CTRL, CSL_ESM_PIN_CTRL_KEY);
            *pMode = regVal;
            retVal = CSL_PASS;
        }
    }

    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691) REQ_TAG(PRSDK-1693)
 *  Design: did_csl_handle_esm_cfg_err_int
 */
int32_t ESMSetInfluenceOnErrPin(uint32_t baseAddr, uint32_t intrSrc, bool  enable)
{
    int32_t  retVal;
    uint32_t regVal;

    if ( (baseAddr == ((uint32_t) (0u))) ||
         (intrSrc  >= ESM_MAX_NUM_INTRS) )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        retVal = CSL_PASS;
    }

    if (retVal == CSL_PASS)
    {
        if ((bool) true == enable)
        {
            regVal  = HW_RD_REG32(baseAddr +
                CSL_ESM_ERR_GRP_PIN_EN_SET(intrSrc / ESM_NUM_INTR_PER_GRP));
            regVal &= ~((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
            regVal |= ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
            HW_WR_REG32(baseAddr +
                CSL_ESM_ERR_GRP_PIN_EN_SET(intrSrc / ESM_NUM_INTR_PER_GRP),
                regVal);
        }
        else
        {
            regVal  = HW_RD_REG32(baseAddr +
                CSL_ESM_ERR_GRP_PIN_EN_CLR(intrSrc / ESM_NUM_INTR_PER_GRP));
            regVal &= ~((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
            regVal |= ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
            HW_WR_REG32(baseAddr +
                CSL_ESM_ERR_GRP_PIN_EN_CLR(intrSrc / ESM_NUM_INTR_PER_GRP),
                regVal);
        }
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetInfluenceOnErrPin(uint32_t baseAddr, uint32_t intrSrc,
                                uint32_t *pInfluence)
{
    int32_t  retVal;
    uint32_t regVal, mask;

    if ( (baseAddr == ((uint32_t) (0u))) ||
         (intrSrc  >= ESM_MAX_NUM_INTRS) ||
         (pInfluence == ((void *) 0)))
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        retVal = CSL_PASS;
    }


    if (retVal == CSL_PASS)
    {
         regVal  = HW_RD_REG32(baseAddr +
                CSL_ESM_ERR_GRP_PIN_EN_SET(intrSrc / ESM_NUM_INTR_PER_GRP));
         mask   = ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
         regVal &= mask;

         if (regVal == ((uint32_t) (0u)))
         {
            *pInfluence = ((uint32_t) (0u));
         }
         else
         {
            *pInfluence = ((uint32_t) (1u));
         }
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1693)
 *  Design: did_csl_esm_init_sequence
 */
int32_t ESMSetErrPinLowTimePreload(uint32_t baseAddr, uint32_t lowTime)
{
    int32_t retVal = CSL_EBADARGS;

    if (baseAddr != ((uint32_t) (0u)))
    {
        if (CSL_ESM_PIN_CNTR_PRE_COUNT_MAX >= lowTime)
        {
            HW_WR_FIELD32(baseAddr + CSL_ESM_PIN_CNTR_PRE,
                          CSL_ESM_PIN_CNTR_PRE_COUNT,
                          lowTime);
            retVal = CSL_PASS;
        }
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetErrPinLowTimePreload(uint32_t baseAddr, uint32_t *pLowTime)
{
    int32_t retVal = CSL_EBADARGS;

    if (baseAddr != ((uint32_t) (0u)))
    {
        if (pLowTime != ((void *) 0))
        {
            *pLowTime = HW_RD_FIELD32(baseAddr + CSL_ESM_PIN_CNTR_PRE,
                          CSL_ESM_PIN_CNTR_PRE_COUNT);
            retVal = CSL_PASS;
        }
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetCurrErrPinLowTimeCnt(uint32_t baseAddr, uint32_t *pPinCntrPre)
{
    int32_t    retVal = CSL_EBADARGS;

    if (baseAddr != ((uint32_t) (0u)))
    {
        if (pPinCntrPre != ((void *) 0))
        {
            *pPinCntrPre = HW_RD_FIELD32(baseAddr + CSL_ESM_PIN_CNTR, CSL_ESM_PIN_CNTR_COUNT);
            retVal =CSL_PASS;
        }
     }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetErrPinStatus(uint32_t baseAddr, uint32_t *pStatus)
{
    int32_t    retVal = CSL_EBADARGS;
    if (baseAddr != ((uint32_t) (0u)))
    {
        if (pStatus != ((void *) 0))
        {
            *pStatus = HW_RD_FIELD32(baseAddr + CSL_ESM_PIN_STS, CSL_ESM_PIN_STS_VAL);
            retVal =  CSL_PASS;
        }
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1693)
 *  Design: did_csl_esm_init_sequence
 */
int32_t ESMResetErrPin(uint32_t baseAddr)
{
    int32_t    retVal = CSL_EBADARGS;
    if (baseAddr != ((uint32_t) (0u)))
    {
        HW_WR_FIELD32(baseAddr + CSL_ESM_PIN_CTRL, CSL_ESM_PIN_CTRL_KEY,
                      ESM_ESM_PIN_CTRL_KEY_RESET_VAL);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMIsEnableIntr(uint32_t baseAddr, uint32_t intrSrc, uint32_t *pEnStatus)
{
    int32_t  retVal = CSL_EBADARGS;
    uint32_t regVal, mask;

    if ( (baseAddr == ((uint32_t) (0u)))   ||
         (intrSrc  >= ESM_MAX_NUM_INTRS) ||
         (pEnStatus == ((void *) 0)) )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        retVal = CSL_PASS;
    }

    if (retVal == CSL_PASS)
    {
        regVal  = HW_RD_REG32(baseAddr +
                CSL_ESM_ERR_GRP_INTR_EN_SET(intrSrc / ESM_NUM_INTR_PER_GRP));
        mask  = ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        regVal &= mask;

        if (regVal == ((uint32_t) (0u)))
        {
           *pEnStatus = ((uint32_t) (0u));
        }
        else
        {
           *pEnStatus = ((uint32_t) (1u));
        }
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691) REQ_TAG(PRSDK-1693)
 *  Design: did_csl_handle_esm_cfg_err_int
 */
int32_t ESMEnableIntr(uint32_t baseAddr, uint32_t intrSrc)
{
    int32_t  retVal;
    uint32_t regVal;

    if ( (baseAddr == ((uint32_t) (0u)))   ||
         (intrSrc  >= ESM_MAX_NUM_INTRS) )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        retVal = CSL_PASS;
    }

    if (retVal == CSL_PASS)
    {
        regVal  = HW_RD_REG32(baseAddr +
                CSL_ESM_ERR_GRP_INTR_EN_SET(intrSrc / ESM_NUM_INTR_PER_GRP));
        regVal &= ~((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        regVal |= ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        HW_WR_REG32(baseAddr +
                CSL_ESM_ERR_GRP_INTR_EN_SET(intrSrc / ESM_NUM_INTR_PER_GRP),
                regVal);
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691)
 *  Design: did_csl_handle_esm_cfg_err_int
 */
int32_t ESMDisableIntr(uint32_t baseAddr, uint32_t intrSrc)
{
    int32_t  retVal;
    uint32_t regVal;


    if ( (baseAddr == ((uint32_t) (0u)))   ||
         (intrSrc  >= ESM_MAX_NUM_INTRS) )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        retVal = CSL_PASS;
    }

    if (retVal == CSL_PASS)
    {
        regVal  = HW_RD_REG32(baseAddr +
                CSL_ESM_ERR_GRP_INTR_EN_CLR(intrSrc / ESM_NUM_INTR_PER_GRP));
        regVal &= ~((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        regVal |= ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        HW_WR_REG32(baseAddr +
            CSL_ESM_ERR_GRP_INTR_EN_CLR(intrSrc / ESM_NUM_INTR_PER_GRP),
            regVal);
     }
     return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691) REQ_TAG(PRSDK-1693)
 *  Design: did_csl_handle_esm_cfg_err_int
 */
int32_t ESMSetIntrPriorityLvl(uint32_t baseAddr, uint32_t intrSrc,
                           esmIntrPriorityLvl_t intrPriorityLvl)
{
    int32_t  retVal = CSL_EBADARGS;
    uint32_t regVal;

    if ( (baseAddr != ((uint32_t) (0u)))  &&
         (intrSrc  < ESM_MAX_NUM_INTRS) )
    {
        regVal  = HW_RD_REG32(baseAddr +
                CSL_ESM_ERR_GRP_INT_PRIO(intrSrc / ESM_NUM_INTR_PER_GRP));
        if (intrPriorityLvl == (esmIntrPriorityLvl_t)ESM_INTR_PRIORITY_LEVEL_LOW)
        {
            regVal &= ~((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        }
        else
        {
            regVal |= ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        }
        HW_WR_REG32(baseAddr +
                CSL_ESM_ERR_GRP_INT_PRIO(intrSrc / ESM_NUM_INTR_PER_GRP),
                regVal);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetIntrPriorityLvl(uint32_t baseAddr, uint32_t intrSrc,
                              esmIntrPriorityLvl_t *pIntrPriorityLvl)
{
    int32_t  retVal = CSL_EBADARGS;
    uint32_t regVal, mask;

    if ( (baseAddr != ((uint32_t) (0u))) &&
         (intrSrc  < ESM_MAX_NUM_INTRS)  &&
         (pIntrPriorityLvl != ((void *) 0)) )
    {
        regVal  = HW_RD_REG32(baseAddr +
                CSL_ESM_ERR_GRP_INT_PRIO(intrSrc / ESM_NUM_INTR_PER_GRP));
        mask = ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        regVal &= mask;
        if (regVal == ((uint32_t) (0u)))
        {
           *pIntrPriorityLvl = ESM_INTR_PRIORITY_LEVEL_LOW;
        }
        else
        {
            *pIntrPriorityLvl = ESM_INTR_PRIORITY_LEVEL_HIGH;
        }

        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691) REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetIntrStatus(uint32_t baseAddr, uint32_t intrSrc, uint32_t *pStatus)
{
    int32_t    retVal = CSL_EBADARGS;
    uint32_t regVal;

    if ( (baseAddr != ((uint32_t) (0u))) &&
         (intrSrc  < ESM_MAX_NUM_INTRS))
    {
        regVal  = HW_RD_REG32(baseAddr +
                    CSL_ESM_ERR_GRP_STS(intrSrc / ESM_NUM_INTR_PER_GRP));
        regVal &= ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        if (pStatus != ((void *) 0))
        {
            *pStatus  = (regVal >> (intrSrc % ESM_NUM_INTR_PER_GRP));
            retVal = CSL_PASS;
        }
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetGroupIntrStatus(uint32_t baseAddr, esmIntrPriorityLvl_t intrPrioType,
                           esmGroupIntrStatus_t *pIntrstatus)
{
    int32_t    retVal = CSL_EBADARGS;

    if ((baseAddr != ((uint32_t) (0u))) &&
        (pIntrstatus != ((void *) 0)))
    {
        if (intrPrioType == (esmIntrPriorityLvl_t)ESM_INTR_PRIORITY_LEVEL_LOW)
        {
            pIntrstatus->highestPendPlsIntNum = HW_RD_FIELD32(
                        baseAddr + CSL_ESM_LOW_PRI, CSL_ESM_LOW_PRI_PLS);
            pIntrstatus->highestPendLvlIntNum = HW_RD_FIELD32(
                        baseAddr + CSL_ESM_LOW_PRI, CSL_ESM_LOW_PRI_LVL);
            pIntrstatus->grpIntrStatus = HW_RD_REG32(baseAddr + CSL_ESM_LOW);
        }
        else
        {
            pIntrstatus->highestPendPlsIntNum = HW_RD_FIELD32(
                        baseAddr + CSL_ESM_HI_PRI, CSL_ESM_HI_PRI_PLS);
            pIntrstatus->highestPendLvlIntNum = HW_RD_FIELD32(
                        baseAddr + CSL_ESM_HI_PRI, CSL_ESM_HI_PRI_LVL);
            pIntrstatus->grpIntrStatus = HW_RD_REG32(baseAddr + CSL_ESM_HI);
        }
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691)
 *  Design: did_csl_handle_esm_cfg_err_int
 */
int32_t ESMClearIntrStatus(uint32_t baseAddr, uint32_t intrSrc)
{
    int32_t  retVal = CSL_EBADARGS;
    uint32_t regVal = 0U;
    if ( (baseAddr != ((uint32_t) (0u))) &&
         (intrSrc  < ESM_MAX_NUM_INTRS))
    {
        regVal = ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        HW_WR_REG32(baseAddr +
                CSL_ESM_ERR_GRP_STS(intrSrc / ESM_NUM_INTR_PER_GRP), regVal);
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691) REQ_TAG(PRSDK-1695)
 *  Design: did_csl_esm_rw_raw_status
 */
int32_t ESMSetIntrStatusRAW(uint32_t baseAddr, uint32_t intrSrc)
{
    uint32_t regVal;
    int32_t  retVal = CSL_EBADARGS;
    if ((baseAddr != ((uint32_t) (0u))) &&
        (intrSrc  < ESM_MAX_NUM_INTRS))
    {
        regVal  = HW_RD_REG32(baseAddr +
                    CSL_ESM_ERR_GRP_RAW(intrSrc / ESM_NUM_INTR_PER_GRP));
        regVal |= ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        HW_WR_REG32(baseAddr +
                    CSL_ESM_ERR_GRP_RAW(intrSrc / ESM_NUM_INTR_PER_GRP),
                    regVal);
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1695)  REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_rw_raw_status
 */
int32_t ESMGetIntrStatusRAW(uint32_t baseAddr, uint32_t intrSrc, uint32_t *pStatus)
{
    uint32_t regVal;
    int32_t  retVal = CSL_EBADARGS;

    if ((baseAddr != ((uint32_t) (0u))) &&
        (intrSrc  < ESM_MAX_NUM_INTRS)  &&
        (pStatus != ((void *) 0)))
    {
        regVal  = HW_RD_REG32(baseAddr +
                    CSL_ESM_ERR_GRP_RAW(intrSrc / ESM_NUM_INTR_PER_GRP));
        regVal &= ((uint32_t) 0x1U << (intrSrc % ESM_NUM_INTR_PER_GRP));
        *pStatus  = (regVal >> (intrSrc % ESM_NUM_INTR_PER_GRP));
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691)
 *  Design: did_csl_handle_esm_cfg_err_int
 */
int32_t ESMWriteEOI(uint32_t baseAddr, esmIntrType_t intrType)
{
    int32_t  retVal = CSL_EBADARGS;
    if (baseAddr != ((uint32_t) (0u)))
    {
        HW_WR_FIELD32(baseAddr +CSL_ESM_EOI, CSL_ESM_EOI_KEY, intrType);
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetRevisionId(uint32_t baseAddr, esmRevisionId_t *revId)
{
    uint32_t regVal;
    int32_t  retVal = CSL_EBADARGS;
    if (baseAddr != ((uint32_t) (0u)))
    {
        regVal  = HW_RD_REG32(baseAddr + CSL_ESM_PID);
        revId->scheme = HW_GET_FIELD(regVal, CSL_ESM_PID_SCHEME);
        revId->func   = HW_GET_FIELD(regVal, CSL_ESM_PID_FUNC);
        revId->rtlRev = HW_GET_FIELD(regVal, CSL_ESM_PID_RTL);
        revId->major  = HW_GET_FIELD(regVal, CSL_ESM_PID_MAJOR);
        revId->custom = HW_GET_FIELD(regVal, CSL_ESM_PID_CUSTOM);
        revId->minor  = HW_GET_FIELD(regVal, CSL_ESM_PID_MINOR);
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetInfo(uint32_t baseAddr, esmInfo_t *info)
{
    uint32_t regVal;
    int32_t  retVal = CSL_EBADARGS;
    if (baseAddr != ((uint32_t) (0u)))
    {
        regVal  = HW_RD_REG32(baseAddr + CSL_ESM_INFO);
        info->lastRstType = HW_GET_FIELD(regVal, CSL_ESM_INFO_LAST_RESET);
        info->plsGrpNum   = HW_GET_FIELD(regVal, CSL_ESM_INFO_PULSE_GROUPS);
        info->lvlGrpNum   = (HW_GET_FIELD(regVal, CSL_ESM_INFO_GROUPS) -
                             HW_GET_FIELD(regVal, CSL_ESM_INFO_PULSE_GROUPS));
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMGetGlobalIntrEnabledStatus(uint32_t baseAddr, uint32_t *pStatus)
{
    int32_t  retVal = CSL_EBADARGS;
    uint32_t regVal;

    if ( (baseAddr != ((uint32_t) (0u))) &&
         (pStatus  != ((void *) 0)) )
    {
        regVal = HW_RD_FIELD32(baseAddr +CSL_ESM_EN,
                      CSL_ESM_EN_KEY);

       *pStatus = regVal & ESM_EN_KEY_MASK;
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691) REQ_TAG(PRSDK-1693)
 *  Design: did_csl_handle_esm_cfg_err_int
 */
int32_t ESMEnableGlobalIntr(uint32_t baseAddr)
{
    int32_t  retVal = CSL_EBADARGS;
    if (baseAddr != ((uint32_t) (0u)))
    {
        HW_WR_FIELD32(baseAddr +CSL_ESM_EN,
                      CSL_ESM_EN_KEY,
                      ESM_EN_KEY_ENBALE_VAL);
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1691) REQ_TAG(PRSDK-1693)
 *  Design: did_csl_handle_esm_cfg_err_int
 */
int32_t ESMDisableGlobalIntr(uint32_t baseAddr)
{
    int32_t  retVal = CSL_EBADARGS;
    if (baseAddr != ((uint32_t) (0u)))
    {
        HW_WR_FIELD32(baseAddr +CSL_ESM_EN,
                      CSL_ESM_EN_KEY,
                      ESM_EN_KEY_DISABLE_VAL);
        retVal = CSL_PASS;
     }
     return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1693)
 *  Design: did_csl_esm_init_sequence
 */
int32_t ESMReset(uint32_t baseAddr)
{
    int32_t  retVal = CSL_EBADARGS;
    if (baseAddr != ((uint32_t) (0u)))
    {
        HW_WR_FIELD32(baseAddr +CSL_ESM_SFT_RST,
                      CSL_ESM_SFT_RST_KEY,
                      ESM_SFT_RST_KEY_RESET_VAL);
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 *  Requirement: REQ_TAG(PRSDK-1680)
 *  Design: did_csl_esm_readback
 */
int32_t ESMReadStaticRegs (uint32_t baseAddr, CSL_esmStaticRegs *pStaticRegs)
{
    int32_t  retVal = CSL_EBADARGS;
    CSL_esmRegs *esmRegs = (CSL_esmRegs *) (uintptr_t)baseAddr;
    uint32_t  i;

    if ((baseAddr != ((uint32_t) (0u))) &&
        (pStaticRegs != ((void *) 0)))
    {
        pStaticRegs->PID           = esmRegs->PID;
        pStaticRegs->INFO          = esmRegs->INFO;
        pStaticRegs->EN            = esmRegs->EN;
        pStaticRegs->ERR_EN_SET    = esmRegs->ERR_EN_SET;
        pStaticRegs->ERR_EN_CLR    = esmRegs->ERR_EN_CLR;
        pStaticRegs->LOW_PRI       = esmRegs->LOW_PRI;
        pStaticRegs->HI_PRI        = esmRegs->HI_PRI;
        pStaticRegs->LOW           = esmRegs->LOW;
        pStaticRegs->HI            = esmRegs->HI;
        pStaticRegs->PIN_CTRL      = esmRegs->PIN_CTRL;
        pStaticRegs->PIN_CNTR      = esmRegs->PIN_CNTR;
        pStaticRegs->PIN_CNTR_PRE  = esmRegs->PIN_CNTR_PRE;

        for (i = ((uint32_t) (0u)); i < ESM_NUMBER_OF_GROUP_REGS; i++)
        {
            pStaticRegs->ERR_GRP[i].RAW  = esmRegs->ERR_GRP[i].RAW;
            pStaticRegs->ERR_GRP[i].INTR_EN_SET  = esmRegs->ERR_GRP[i].INTR_EN_SET;
            pStaticRegs->ERR_GRP[i].INTR_EN_CLR  = esmRegs->ERR_GRP[i].INTR_EN_CLR;
            pStaticRegs->ERR_GRP[i].INT_PRIO    = esmRegs->ERR_GRP[i].INT_PRIO;
            pStaticRegs->ERR_GRP[i].PIN_EN_SET  = esmRegs->ERR_GRP[i].PIN_EN_SET;
            pStaticRegs->ERR_GRP[i].PIN_EN_CLR  = esmRegs->ERR_GRP[i].PIN_EN_CLR;
        }
        retVal = CSL_PASS;
    }
    return retVal;

}

