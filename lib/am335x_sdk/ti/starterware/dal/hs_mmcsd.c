/**
 *  \file     hs_mmcsd.c
 *
 *  \brief    This file contains the device abstraction layer APIs for High
 *            speed MMC/SD controller.
 *            peripheral.
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
#include "hs_mmcsd.h"
#include "hw_hs_mmcsd.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

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

int32_t HSMMCSDSoftReset(uint32_t baseAddr)
{
    int32_t retVal = S_PASS;

    HW_WR_FIELD32((baseAddr + HS_MMC_SD_SYSCONFIG),
        HS_MMC_SD_SYSCONFIG_SOFTRESET, HS_MMC_SD_SYSCONFIG_SOFTRESET_TRIG_RST);

    while(HS_MMC_SD_SYSSTATUS_RESETDONE_COMPLETED !=
            HW_RD_FIELD32((baseAddr + HS_MMC_SD_SYSSTATUS),
            HS_MMC_SD_SYSSTATUS_RESETDONE))
    {
    }

    return retVal;
}


void HSMMCSDLinesReset(uint32_t baseAddr, uint32_t resetMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + HS_MMC_SD_SYSCTL);
    regVal |= resetMask;
    HW_WR_REG32((baseAddr + HS_MMC_SD_SYSCTL), regVal);

    while(resetMask == (HW_RD_REG32(baseAddr + HS_MMC_SD_SYSCTL) & resetMask));
}


void HSMMCSDSystemConfig(uint32_t baseAddr, hsMmcsdSysCfg_t *pCfg)
{
    uint32_t regVal = 0U;
    uint32_t enableAutoIdle = 0U;
    uint32_t enableWakeup = 0U;


    regVal = HW_RD_REG32(baseAddr + HS_MMC_SD_SYSCONFIG);

    /* Set clock activity, standby mode and idle mode */
    HW_SET_FIELD(regVal, HS_MMC_SD_SYSCONFIG_CLOCKACTIVITY,
        pCfg->clockActivity);
    HW_SET_FIELD(regVal, HS_MMC_SD_SYSCONFIG_STANDBYMODE, pCfg->standbyMode);
    HW_SET_FIELD(regVal, HS_MMC_SD_SYSCONFIG_SIDLEMODE, pCfg->idleMode);

    /* Set wake up enable control */
    enableWakeup = (TRUE == pCfg->enableWakeup) ?
        HS_MMC_SD_SYSCONFIG_ENAWAKEUP_ENABLED :
        HS_MMC_SD_SYSCONFIG_ENAWAKEUP_DISABLED;
    HW_SET_FIELD(regVal, HS_MMC_SD_SYSCONFIG_ENAWAKEUP, enableWakeup);

    /* Set auto idle enable control */
    enableAutoIdle = (TRUE == pCfg->enableAutoIdle) ?
        HS_MMC_SD_SYSCONFIG_AUTOIDLE_GATING :
        HS_MMC_SD_SYSCONFIG_AUTOIDLE_FREE_RUN;
    HW_SET_FIELD(regVal, HS_MMC_SD_SYSCONFIG_AUTOIDLE, enableAutoIdle);

    HW_WR_REG32((baseAddr + HS_MMC_SD_SYSCONFIG), regVal);
}


void HSMMCSDSetBusWidth(uint32_t baseAddr, uint32_t width)
{
    switch (width)
    {
        case HS_MMCSD_BUS_WIDTH_8BIT:
            HW_WR_FIELD32((baseAddr + HS_MMC_SD_CON),
                HS_MMC_SD_CON_DW8, HS_MMC_SD_CON_DW8_EIGHT_BIT);
            break;

        case HS_MMCSD_BUS_WIDTH_4BIT:
            HW_WR_FIELD32((baseAddr + HS_MMC_SD_CON),
                HS_MMC_SD_CON_DW8, HS_MMC_SD_CON_DW8_ONE_OR_FOUR_BIT);
            HW_WR_FIELD32((baseAddr + HS_MMC_SD_HCTL),
                HS_MMC_SD_HCTL_DTW, HS_MMC_SD_HCTL_DTW_WIDTH_4BIT);
            break;

        case HS_MMCSD_BUS_WIDTH_1BIT:
            HW_WR_FIELD32((baseAddr + HS_MMC_SD_CON),
                HS_MMC_SD_CON_DW8, HS_MMC_SD_CON_DW8_ONE_OR_FOUR_BIT);
            HW_WR_FIELD32((baseAddr + HS_MMC_SD_HCTL),
                HS_MMC_SD_HCTL_DTW, HS_MMC_SD_HCTL_DTW_WIDTH_1BIT);
            break;

        default:
            break;
    }
}


void HSMMCSDSetBusVolt(uint32_t baseAddr, uint32_t voltage)
{
    HW_WR_FIELD32((baseAddr + HS_MMC_SD_HCTL), HS_MMC_SD_HCTL_SDVS, voltage);
}


uint32_t HSMMCSDBusPowerOnCtrl(uint32_t baseAddr, uint32_t pwrCtrl)
{
    uint32_t retVal = TRUE;

    HW_WR_FIELD32((baseAddr + HS_MMC_SD_HCTL), HS_MMC_SD_HCTL_SDBP, pwrCtrl);

    if (HS_MMCSD_PWR_CTRL_ON == pwrCtrl)
    {
        while (pwrCtrl != HW_RD_FIELD32((baseAddr + HS_MMC_SD_HCTL),
            HS_MMC_SD_HCTL_SDBP))
        {
        }
    }

    return retVal;
}


int32_t HSMMCSDIntClockEnable(uint32_t baseAddr, uint32_t enableIntClk)
{
    uint32_t clkEnable = 0U;
    int32_t retVal = S_PASS;

    clkEnable = (TRUE == enableIntClk) ? HS_MMC_SD_SYSCTL_ICE_OSCILLATES :
        HS_MMC_SD_SYSCTL_ICE_STOPPED;
    HW_WR_FIELD32((baseAddr + HS_MMC_SD_SYSCTL), HS_MMC_SD_SYSCTL_ICE,
        clkEnable);

    if (TRUE == enableIntClk)
    {
        if (FALSE == HSMMCSDIsIntClockStable(baseAddr, 0xFFFFU))
        {
            retVal = E_FAIL;
        }
    }

    return retVal;
}


uint32_t HSMMCSDIsIntClockStable(uint32_t baseAddr, uint32_t retry)
{
    uint32_t status = FALSE;

    do
    {
        if ((HS_MMC_SD_SYSCTL_ICS_STABLE == HW_RD_FIELD32((baseAddr + HS_MMC_SD_SYSCTL),
            HS_MMC_SD_SYSCTL_ICS)) || (0U == retry))
        {
            status = TRUE;
            break;
        }
    }
    while (retry--);

    return status;
}


void HSMMCSDSetSupportedVoltage(uint32_t baseAddr, uint32_t voltMask)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + HS_MMC_SD_CAPA);

    regVal &= ~(HS_MMC_SD_CAPA_VS33_MASK | HS_MMC_SD_CAPA_VS30_MASK |
        HS_MMC_SD_CAPA_VS18_MASK);
    regVal |= voltMask;
    HW_WR_REG32((baseAddr + HS_MMC_SD_CAPA), regVal);
}


uint32_t HSMMCSDIsHighSpeedSupported(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + HS_MMC_SD_CAPA), HS_MMC_SD_CAPA_HSS));
}


void HSMMCSDSetDataTimeout(uint32_t baseAddr, uint32_t timeout)
{
    timeout = (timeout - 13U) & 0xFU;
    HW_WR_FIELD32((baseAddr + HS_MMC_SD_SYSCTL), HS_MMC_SD_SYSCTL_DTO, timeout);
}


int32_t HSMMCSDSetBusFreq(uint32_t baseAddr,
                          uint32_t inputFreq,
                          uint32_t outputFreq,
                          uint32_t bypass)
{
    volatile uint32_t clkDiv = 0;
    int32_t retVal = S_PASS;

    /* First enable the internal clocks */
    if (S_PASS == HSMMCSDIntClockEnable(baseAddr, TRUE))
    {
        if (FALSE == bypass)
        {
            /* Calculate and program the divisor */
            clkDiv = inputFreq / outputFreq;
            clkDiv = (clkDiv < 2U) ? 2U : clkDiv;
            clkDiv = (clkDiv > 1023U) ? 1023U : clkDiv;

            /* Do not cross the required freq */
            while(((inputFreq / clkDiv) > outputFreq) && (0 == retVal))
            {
                if (1023U == clkDiv)
                {
                    /* Return we we cannot set the clock freq */
                   retVal = E_FAIL;
                }

                clkDiv++;
            }

            if(S_PASS == retVal)
            {
                HW_WR_FIELD32((baseAddr + HS_MMC_SD_SYSCTL),
                    HS_MMC_SD_SYSCTL_CLKD, clkDiv);

                /* Wait for the interface clock stabilization */
                if(TRUE == HSMMCSDIsIntClockStable(baseAddr, 0xFFFFU))
                {
                    /* Enable clock to the card */
                    HW_WR_FIELD32((baseAddr + HS_MMC_SD_SYSCTL),
                        HS_MMC_SD_SYSCTL_CEN,
                        HS_MMC_SD_SYSCTL_CEN_CLK_PROVIDED);
                }
                else
                {
                    retVal = E_FAIL;
                }
            }
        }
    }
    else
    {
        retVal = E_FAIL;
    }

    return retVal;
}


int32_t HSMMCSDInitStreamSend(uint32_t baseAddr)
{
    uint32_t status = 0U;

    /* Enable the command completion status to be set */
    HSMMCSDIntrStatusEnable(baseAddr, HS_MMCSD_INTR_MASK_CMDCOMP);

    /* Initiate the INIT command */
    HW_WR_FIELD32((baseAddr + HS_MMC_SD_CON), HS_MMC_SD_CON_INIT,
        HS_MMC_SD_CON_INIT_INITSEQ);
    HW_WR_REG32((baseAddr + HS_MMC_SD_CMD), 0x00U);

    status = HSMMCSDIsCmdComplete(baseAddr, 0xFFFFU);

    HW_WR_FIELD32((baseAddr + HS_MMC_SD_CON), HS_MMC_SD_CON_INIT,
        HS_MMC_SD_CON_INIT_NO_INITSEQ);

    /* Clear all status */
    HSMMCSDIntrClear(baseAddr, 0xFFFFFFFFU);

    return status;
}


void HSMMCSDIntrStatusEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + HS_MMC_SD_IE);
    regVal |= intrMask;
    HW_WR_REG32((baseAddr + HS_MMC_SD_IE), regVal);
}


void HSMMCSDIntrStatusDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + HS_MMC_SD_IE);
    regVal &= ~intrMask;
    HW_WR_REG32((baseAddr + HS_MMC_SD_IE), regVal);
}


void HSMMCSDIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + HS_MMC_SD_ISE);
    regVal |= intrMask;
    HW_WR_REG32((baseAddr + HS_MMC_SD_ISE), regVal);

    HSMMCSDIntrStatusEnable(baseAddr, intrMask);

}

void HSMMCSDIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + HS_MMC_SD_ISE);
    regVal &= ~intrMask;
    HW_WR_REG32((baseAddr + HS_MMC_SD_ISE), regVal);
}


uint32_t HSMMCSDIntrStatus(uint32_t baseAddr)
{
    return HW_RD_REG32(baseAddr + HS_MMC_SD_STAT);
}


void HSMMCSDIntrClear(uint32_t baseAddr, uint32_t intrMask)
{
    HW_WR_REG32((baseAddr + HS_MMC_SD_STAT), intrMask);
}


uint32_t HSMMCSDIsCmdComplete(uint32_t baseAddr, uint32_t retry)
{
    volatile uint32_t status = FALSE;

    do
    {
        if ((HS_MMC_SD_STAT_CC_COMPLETE == HW_RD_FIELD32((baseAddr + HS_MMC_SD_STAT), HS_MMC_SD_STAT_CC)) || (0U  == retry))
        {
            status = TRUE;
            break;
        }
    }
    while(retry--);

    return status;
}


uint32_t HSMMCSDIsXferComplete(uint32_t baseAddr, uint32_t retry)
{
    volatile uint32_t status = FALSE;

    do
    {
        if ((HS_MMC_SD_STAT_TC_COMPLETE == HW_RD_FIELD32((baseAddr + HS_MMC_SD_STAT), HS_MMC_SD_STAT_TC)) || (0U == retry))
        {
            status = TRUE;
            break;
        }
    }
    while(retry--);

    return status;
}


void HSMMCSDSetBlkLength(uint32_t baseAddr, uint32_t blkLen)
{
    HW_WR_FIELD32((baseAddr + HS_MMC_SD_BLK), HS_MMC_SD_BLK_BLEN, blkLen);
}


void HSMMCSDCommandSend(uint32_t baseAddr, hsMmcsdCmdObj_t *pObj)
{
    uint32_t cmdRegVal = 0U;

    HW_SET_FIELD(cmdRegVal, HS_MMC_SD_CMD_INDX, pObj->cmd.cmdId);
    HW_SET_FIELD(cmdRegVal, HS_MMC_SD_CMD_TYPE, pObj->cmd.cmdType);
    HW_SET_FIELD(cmdRegVal, HS_MMC_SD_CMD_RSP_TYPE, pObj->cmd.rspType);
    HW_SET_FIELD(cmdRegVal, HS_MMC_SD_CMD_DDIR, pObj->cmd.xferType);

    if (TRUE == pObj->enableData)
    {
        HW_SET_FIELD(cmdRegVal, HS_MMC_SD_CMD_DP, HS_MMC_SD_CMD_DP_TX);
        HW_SET_FIELD(cmdRegVal, HS_MMC_SD_CMD_MSBS, HS_MMC_SD_CMD_MSBS_MULTI_BLK);
        HW_SET_FIELD(cmdRegVal, HS_MMC_SD_CMD_BCE, HS_MMC_SD_CMD_BCE_ENABLED);
    }

    if (TRUE == pObj->enableDma)
    {
        HW_SET_FIELD(cmdRegVal, HS_MMC_SD_CMD_DE, HS_MMC_SD_CMD_DE_ENABLE);
    }

    /* Set the block information; block length is specified separately */
    HW_WR_FIELD32((baseAddr + HS_MMC_SD_BLK), HS_MMC_SD_BLK_NBLK,
        pObj->numBlks);

    /* Set the command/command argument */
    HW_WR_REG32((baseAddr + HS_MMC_SD_ARG), pObj->cmdArg);
    HW_WR_REG32((baseAddr + HS_MMC_SD_CMD), cmdRegVal);
}


void HSMMCSDGetResponse(uint32_t baseAddr, uint32_t *pRsp)
{
    pRsp[0U] = HW_RD_REG32(baseAddr + HS_MMC_SD_RSP10);
    pRsp[1U] = HW_RD_REG32(baseAddr + HS_MMC_SD_RSP32);
    pRsp[2U] = HW_RD_REG32(baseAddr + HS_MMC_SD_RSP54);
    pRsp[3U] = HW_RD_REG32(baseAddr + HS_MMC_SD_RSP76);
}


void HSMMCSDGetData(uint32_t baseAddr, uint8_t *pData, uint32_t len)
{
    uint32_t idx;

    for (idx = 0U; idx < (len / 4U); idx++)
    {
        ((uint32_t*)pData)[idx] = HW_RD_REG32(baseAddr + HS_MMC_SD_DATA);
    }
}


void HSMMCSDSetData(uint32_t baseAddr, uint8_t *pData, uint32_t len)
{
    uint32_t idx;

    for (idx = 0U; idx < (len / 4U); idx++)
    {
        HW_WR_REG32((baseAddr + HS_MMC_SD_DATA), ((uint32_t*)pData)[idx]);
    }
}


uint32_t HSMMCSDIsCardInserted(uint32_t baseAddr)
{
    return
        (HW_RD_FIELD32((baseAddr + HS_MMC_SD_PSTATE), HS_MMC_SD_PSTATE_CINS));
}


uint32_t HSMMCSDIsCardWriteProtected(uint32_t baseAddr)
{
    return HW_RD_FIELD32((baseAddr + HS_MMC_SD_PSTATE), HS_MMC_SD_PSTATE_WP);
}


void MMCSDContextSave(uint32_t mmcsdBase, hsMmcsdCtx_t *pCtx)
{
    pCtx->capa = HW_RD_REG32(mmcsdBase + HS_MMC_SD_CAPA);
    pCtx->systemConfig = HW_RD_REG32(mmcsdBase + HS_MMC_SD_SYSCONFIG);
    pCtx->ctrlInfo = HW_RD_REG32(mmcsdBase + HS_MMC_SD_CON);
    pCtx->sysCtrl = HW_RD_REG32(mmcsdBase + HS_MMC_SD_SYSCTL);
    pCtx->pState = HW_RD_REG32(mmcsdBase + HS_MMC_SD_PSTATE);
    pCtx->hostCtrl = HW_RD_REG32(mmcsdBase + HS_MMC_SD_HCTL);
}



void MMCSDContextRestore(uint32_t mmcsdBase, hsMmcsdCtx_t *pCtx)
{
    HW_WR_REG32((mmcsdBase + HS_MMC_SD_SYSCONFIG), pCtx->systemConfig);
    HW_WR_REG32((mmcsdBase + HS_MMC_SD_SYSCTL), pCtx->sysCtrl);
    HW_WR_REG32((mmcsdBase + HS_MMC_SD_CAPA), pCtx->capa);
    HW_WR_REG32((mmcsdBase + HS_MMC_SD_CON), pCtx->ctrlInfo);
    HW_WR_REG32((mmcsdBase + HS_MMC_SD_HCTL), pCtx->hostCtrl);
    HW_WR_REG32((mmcsdBase + HS_MMC_SD_PSTATE), pCtx->pState);
}


/* ========================================================================== */
/*                   Deprecated Function Definitions                          */
/* ========================================================================== */
