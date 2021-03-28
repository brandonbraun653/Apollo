/**
 *  \file     hs_mmcsd.c
 *
 *  \brief    This file contains the device abstraction layer APIs for High
 *            speed MMC/SD controller.
 *            peripheral.
 *
 *  \copyright Copyright (C) 2013-2015 Texas Instruments Incorporated -
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

#include <ti/csl/tistdtypes.h>
#include <ti/csl/csl_error.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/mmcsd/src/v1/MMCSD_v1_lld.h>
#include <ti/csl/cslr_mmchs.h>
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
    int32_t retVal = CSL_SOK;

    HW_WR_FIELD32((baseAddr + CSL_MMCHS_SYSCONFIG),
        CSL_MMCHS_SYSCONFIG_SOFTRESET, CSL_MMCHS_SYSCONFIG_SOFTRESET_ST_RST_W);

    while(CSL_MMCHS_SYSCONFIG_SOFTRESET_ONRESET_R !=
            HW_RD_FIELD32((baseAddr + CSL_MMCHS_SYSSTATUS),
            CSL_MMCHS_SYSSTATUS_RESETDONE))
    {
    }

    return retVal;
}


void HSMMCSDLinesReset(uint32_t baseAddr, uint32_t resetMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + CSL_MMCHS_SYSCTL);
    regVal |= resetMask;
    HW_WR_REG32((baseAddr + CSL_MMCHS_SYSCTL), regVal);

    while(resetMask == (HW_RD_REG32(baseAddr + CSL_MMCHS_SYSCTL) & resetMask))
    {}
}


void HSMMCSDSystemConfig(uint32_t baseAddr, const hsMmcsdSysCfg_t *pCfg)
{
    uint32_t regVal = 0U;
    uint32_t enableAutoIdle = 0U;
    uint32_t enableWakeup = 0U;


    regVal = HW_RD_REG32(baseAddr + CSL_MMCHS_SYSCONFIG);

    /* Set clock activity, standby mode and idle mode */
    HW_SET_FIELD(regVal, CSL_MMCHS_SYSCONFIG_CLOCKACTIVITY,
        pCfg->clockActivity);
    HW_SET_FIELD(regVal, CSL_MMCHS_SYSCONFIG_STANDBYMODE, pCfg->standbyMode);
    HW_SET_FIELD(regVal, CSL_MMCHS_SYSCONFIG_SIDLEMODE, pCfg->idleMode);

    /* Set wake up enable control */
    enableWakeup = (TRUE == pCfg->enableWakeup) ?
        CSL_MMCHS_SYSCONFIG_ENAWAKEUP_ENABLE :
        CSL_MMCHS_SYSCONFIG_ENAWAKEUP_DISABLED;
    HW_SET_FIELD(regVal, CSL_MMCHS_SYSCONFIG_ENAWAKEUP, enableWakeup);

    /* Set auto idle enable control */
    enableAutoIdle = (TRUE == pCfg->enableAutoIdle) ?
        CSL_MMCHS_SYSCONFIG_AUTOIDLE_ON :
        CSL_MMCHS_SYSCONFIG_AUTOIDLE_OFF;
    HW_SET_FIELD(regVal, CSL_MMCHS_SYSCONFIG_AUTOIDLE, enableAutoIdle);

    HW_WR_REG32((baseAddr + CSL_MMCHS_SYSCONFIG), regVal);
}


void HSMMCSDSetBusWidth(uint32_t baseAddr, uint32_t width)
{
    switch (width)
    {
        case HS_MMCSD_BUS_WIDTH_8BIT:
            HW_WR_FIELD32((baseAddr + CSL_MMCHS_CON),
                CSL_MMCHS_CON_DW8, CSL_MMCHS_CON_DW8__8BITMODE);
            break;

        case HS_MMCSD_BUS_WIDTH_4BIT:
            HW_WR_FIELD32((baseAddr + CSL_MMCHS_CON),
                CSL_MMCHS_CON_DW8, CSL_MMCHS_CON_DW8__1_4BITMODE);
            HW_WR_FIELD32((baseAddr + CSL_MMCHS_HCTL),
                CSL_MMCHS_HCTL_DTW, CSL_MMCHS_HCTL_DTW__4_BITMODE);
            break;

        case HS_MMCSD_BUS_WIDTH_1BIT:
            HW_WR_FIELD32((baseAddr + CSL_MMCHS_CON),
                CSL_MMCHS_CON_DW8, CSL_MMCHS_CON_DW8__1_4BITMODE);
            HW_WR_FIELD32((baseAddr + CSL_MMCHS_HCTL),
                CSL_MMCHS_HCTL_DTW, CSL_MMCHS_HCTL_DTW__1_BITMODE);
            break;

        default:
            break;
    }
}


void HSMMCSDSetPAD(uint32_t baseAddr, uint32_t val)
{
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_CON), CSL_MMCHS_CON_PADEN, val);
}

void HSMMCSDSetDLL(uint32_t baseAddr, uint32_t count)
{
    uint32_t regVal;
	int i;
	/*
 	       Set MMCHS_DLL[12] FORCE_VAL to 1 
		   Set MMCHS_DLL[1] DLL_CALIB to 0x1. This transfers the FORCE_SR_C value to the slave delay line.
		   Set MMCHS_DLL[12] DLL_CALIB to 0
    */
	regVal=HW_RD_REG32(baseAddr + CSL_MMCHS_DLL);
	HW_SET_FIELD(regVal, CSL_MMCHS_DLL_FORCE_VALUE, CSL_MMCHS_DLL_FORCE_VALUE_FORCE);
	HW_SET_FIELD(regVal, CSL_MMCHS_DLL_FORCE_SR_C, count);
    HW_WR_REG32((baseAddr + CSL_MMCHS_DLL), regVal);
	
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_DLL), CSL_MMCHS_DLL_DLL_CALIB, CSL_MMCHS_DLL_DLL_CALIB_ENABLED);

    for(i=0;i<1000;i++) {
	 if(HW_RD_FIELD32((baseAddr + CSL_MMCHS_DLL), CSL_MMCHS_DLL_DLL_CALIB))
	    break;
	}

    HW_WR_FIELD32((baseAddr + CSL_MMCHS_DLL), CSL_MMCHS_DLL_DLL_CALIB, CSL_MMCHS_DLL_DLL_CALIB_DISABLED);

}

void HSMMCSDDisableTuning(uint32_t baseAddr)
{
	HW_WR_FIELD32((baseAddr + CSL_MMCHS_AC12), CSL_MMCHS_AC12_SCLK_SEL,CSL_MMCHS_AC12_SCLK_SEL_FIXED);
	HW_WR_FIELD32((baseAddr + CSL_MMCHS_DLL), CSL_MMCHS_DLL_FORCE_VALUE, CSL_MMCHS_DLL_FORCE_VALUE_NO_FORCE);
	HW_WR_FIELD32((baseAddr + CSL_MMCHS_DLL), CSL_MMCHS_DLL_FORCE_SWT, CSL_MMCHS_DLL_FORCE_SWT_DISABLE);
}

void HSMMCSDSetDLLSWT(uint32_t baseAddr,uint32_t val)
{
	HW_WR_FIELD32((baseAddr + CSL_MMCHS_DLL), CSL_MMCHS_DLL_FORCE_SWT,val);
}

uint32_t HSMMCSDGetDLLSWT(uint32_t baseAddr)
{
	return(HW_RD_FIELD32((baseAddr + CSL_MMCHS_DLL), CSL_MMCHS_DLL_FORCE_SWT));
}

void HSMMCSDSetAC12SCLKSEL(uint32_t baseAddr,uint32_t val)
{
	HW_WR_FIELD32((baseAddr + CSL_MMCHS_AC12), CSL_MMCHS_AC12_SCLK_SEL,val);
}

void HSMMCSDSetAC12ExecuteTuning(uint32_t baseAddr,uint32_t val)
{
	HW_WR_FIELD32((baseAddr + CSL_MMCHS_AC12), CSL_MMCHS_AC12_ET,val);
}
uint32_t HSMMCSDGetAC12ExecuteTuning(uint32_t baseAddr)
{
	return(HW_RD_FIELD32((baseAddr + CSL_MMCHS_AC12), CSL_MMCHS_AC12_ET));
}

uint32_t HSMMCSDGetAC12SCLKSEL(uint32_t baseAddr)
{
	return(HW_RD_FIELD32((baseAddr + CSL_MMCHS_AC12), CSL_MMCHS_AC12_SCLK_SEL));
}

void HSMMCSDSetCLKEXTFree(uint32_t baseAddr, uint32_t val)
{
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_CON), CSL_MMCHS_CON_CLKEXTFREE, val);
}

void HSMMCSDSetAC12UHSMode(uint32_t baseAddr,uint32_t val)
{
	HW_WR_FIELD32((baseAddr + CSL_MMCHS_SYSCTL),
                        CSL_MMCHS_SYSCTL_CEN,
                        CSL_MMCHS_SYSCTL_CEN_DISABLE);
	
	HW_WR_FIELD32((baseAddr + CSL_MMCHS_AC12), CSL_MMCHS_AC12_UHSMS,val);
	
	HW_WR_FIELD32((baseAddr + CSL_MMCHS_SYSCTL),
                        CSL_MMCHS_SYSCTL_CEN,
                        CSL_MMCHS_SYSCTL_CEN_ENABLE);

}


void HSMMCSDV18SigSet(uint32_t baseAddr, uint32_t en)
{
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_AC12), CSL_MMCHS_AC12_V1V8_SIGEN, en);
}

void HSMMCSDSetBusVolt(uint32_t baseAddr, uint32_t voltage)
{
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_HCTL), CSL_MMCHS_HCTL_SDVS, voltage);
}

uint32_t HSMMCSDGetBusVolt(uint32_t baseAddr)
{
    return(HW_RD_FIELD32((baseAddr + CSL_MMCHS_HCTL), CSL_MMCHS_HCTL_SDVS));
}


uint32_t HSMMCSDBusPowerOnCtrl(uint32_t baseAddr, uint32_t pwrCtrl)
{
    uint32_t retVal = (uint32_t)CSL_SOK;

    HW_WR_FIELD32((baseAddr + CSL_MMCHS_HCTL), CSL_MMCHS_HCTL_SDBP, pwrCtrl);

    if (HS_MMCSD_PWR_CTRL_ON == pwrCtrl)
    {
        while (pwrCtrl != HW_RD_FIELD32((baseAddr + CSL_MMCHS_HCTL),
            CSL_MMCHS_HCTL_SDBP))
        {
        }
    }

    return retVal;
}


int32_t HSMMCSDIntClockEnable(uint32_t baseAddr, uint32_t enableIntClk)
{
    uint32_t clkEnable = 0U;
    int32_t retVal = CSL_SOK;

    clkEnable = (TRUE == enableIntClk) ? CSL_MMCHS_SYSCTL_ICE_OSCILLATE :
        CSL_MMCHS_SYSCTL_ICE_STOP;
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_SYSCTL), CSL_MMCHS_SYSCTL_ICE,
        clkEnable);

    if (TRUE == enableIntClk)
    {
        if (FALSE == HSMMCSDIsIntClockStable(baseAddr, 0xFFFFU))
        {
            retVal = CSL_ESYS_FAIL;
        }
    }

    return retVal;
}


uint32_t HSMMCSDIsIntClockStable(uint32_t baseAddr, uint32_t retry)
{
    uint32_t status = FALSE;

    do
    {
        if ((CSL_MMCHS_SYSCTL_ICS_READY == HW_RD_FIELD32((baseAddr + CSL_MMCHS_SYSCTL),
            CSL_MMCHS_SYSCTL_ICS)) || (0U == retry))
        {
            status = (uint32_t)TRUE;
            break;
        }
    }
    while (retry--);

    return status;
}


void HSMMCSDSetSupportedVoltage(uint32_t baseAddr, uint32_t voltMask)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + CSL_MMCHS_CAPA);

    regVal &= ~(CSL_MMCHS_CAPA_VS33_MASK | CSL_MMCHS_CAPA_VS30_MASK |
        CSL_MMCHS_CAPA_VS18_MASK);
    regVal |= voltMask;
    HW_WR_REG32((baseAddr + CSL_MMCHS_CAPA), regVal);
}

uint32_t HSMMCSDIsHighSpeedSupported(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + CSL_MMCHS_CAPA), CSL_MMCHS_CAPA_HSS));
}

uint32_t HSMMCSDIsUHSSDR50Supported(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + CSL_MMCHS_CAPA2), CSL_MMCHS_CAPA2_SDR50));
}
uint32_t HSMMCSDIsUHSSDR104Supported(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + CSL_MMCHS_CAPA2), CSL_MMCHS_CAPA2_SDR104));
}
uint32_t HSMMCSDIsUHSDDR50Supported(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + CSL_MMCHS_CAPA2), CSL_MMCHS_CAPA2_DDR50));
}

void HSMMCSDSetDataTimeout(uint32_t baseAddr, uint32_t timeout)
{
    timeout = (timeout - 13U) & 0xFU;
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_SYSCTL), CSL_MMCHS_SYSCTL_DTO, timeout);
}


int32_t HSMMCSDSetBusFreq(uint32_t baseAddr,
                          uint32_t inputFreq,
                          uint32_t outputFreq,
                          uint32_t bypass)
{
    volatile uint32_t clkDiv = 0;
    int32_t retVal = CSL_SOK;

    /* First enable the internal clocks */
    if (CSL_SOK == HSMMCSDIntClockEnable(baseAddr, TRUE))
    {
        if (FALSE == bypass)
        {
            /* Calculate and program the divisor */
            clkDiv = inputFreq / outputFreq;
            if(clkDiv > 1023U)
            {
                clkDiv = 1023U;
            } else if (clkDiv==0) {
			    clkDiv = 1; 
			}

            /* Do not cross the required freq */
            while(((inputFreq / clkDiv) > outputFreq) && (CSL_SOK == retVal))
            {
                if (1023U == clkDiv)
                {
                    /* Return we we cannot set the clock freq */
                   retVal = CSL_ESYS_FAIL;
                }

                clkDiv++;
            }

            if(CSL_SOK == retVal)
            {
                HW_WR_FIELD32((baseAddr + CSL_MMCHS_SYSCTL),
                    CSL_MMCHS_SYSCTL_CLKD, clkDiv);

                /* Wait for the interface clock stabilization */
                if(TRUE == HSMMCSDIsIntClockStable(baseAddr, 0xFFFFU))
                {
                    /* Enable clock to the card */
                    HW_WR_FIELD32((baseAddr + CSL_MMCHS_SYSCTL),
                        CSL_MMCHS_SYSCTL_CEN,
                        CSL_MMCHS_SYSCTL_CEN_ENABLE);
                }
                else
                {
                    retVal = CSL_ESYS_FAIL;
                }
            }
        }
    }
    else
    {
        retVal = CSL_ESYS_FAIL;
    }

    return retVal;
}


int32_t HSMMCSDInitStreamSend(uint32_t baseAddr)
{
    uint32_t status = 0U;

    /* Enable the command completion status to be set */
    HSMMCSDIntrStatusEnable(baseAddr, HS_MMCSD_INTR_MASK_CMDCOMP);

    /* Initiate the INIT command */
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_CON), CSL_MMCHS_CON_INIT,
        CSL_MMCHS_CON_INIT_INITSTREAM);
    HW_WR_REG32((baseAddr + CSL_MMCHS_CMD), 0x00U);

    status = HSMMCSDIsCmdComplete(baseAddr, 0xFFFFU);

    HW_WR_FIELD32((baseAddr + CSL_MMCHS_CON), CSL_MMCHS_CON_INIT,
        CSL_MMCHS_CON_INIT_NOINIT);

    /* Clear all status */
    HSMMCSDIntrClear(baseAddr, 0xFFFFFFFFU);

    return((int32_t)status);
}


void HSMMCSDIntrStatusEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + CSL_MMCHS_IE);
    regVal |= intrMask;
    HW_WR_REG32((baseAddr + CSL_MMCHS_IE), regVal);
}


void HSMMCSDIntrStatusDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + CSL_MMCHS_IE);
    regVal &= ~intrMask;
    HW_WR_REG32((baseAddr + CSL_MMCHS_IE), regVal);
}


void HSMMCSDIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + CSL_MMCHS_ISE);
    regVal |= intrMask;
    HW_WR_REG32((baseAddr + CSL_MMCHS_ISE), regVal);

    HSMMCSDIntrStatusEnable(baseAddr, intrMask);

}

void HSMMCSDIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + CSL_MMCHS_ISE);
    regVal &= ~intrMask;
    HW_WR_REG32((baseAddr + CSL_MMCHS_ISE), regVal);
}

uint32_t HSMMCSDIntrGet(uint32_t baseAddr)
{
    return HW_RD_REG32(baseAddr + CSL_MMCHS_ISE);
}


uint32_t HSMMCSDIntrStatus(uint32_t baseAddr)
{
    return HW_RD_REG32(baseAddr + CSL_MMCHS_STAT);
}


void HSMMCSDIntrClear(uint32_t baseAddr, uint32_t intrMask)
{
    HW_WR_REG32((baseAddr + CSL_MMCHS_STAT), intrMask);
}


uint32_t HSMMCSDIsCmdComplete(uint32_t baseAddr, uint32_t retry)
{
    volatile uint32_t status = FALSE;

    do
    {
        if ((CSL_MMCHS_STAT_CC_IRQ_TRU_R == HW_RD_FIELD32((baseAddr + CSL_MMCHS_STAT), CSL_MMCHS_STAT_CC)) || (0U  == retry))
        {
            status = (uint32_t)TRUE;
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
        if ((CSL_MMCHS_STAT_TC_IRQ_TRU_R == HW_RD_FIELD32((baseAddr + CSL_MMCHS_STAT), CSL_MMCHS_STAT_TC)) || (0U == retry))
        {
            status = (uint32_t)TRUE;
            break;
        }
    }
    while(retry--);

    return status;
}


void HSMMCSDSetBlkLength(uint32_t baseAddr, uint32_t blkLen)
{
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_BLK), CSL_MMCHS_BLK_BLEN, blkLen);
}


uint32_t HSMMCSDGetBlkLength(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + CSL_MMCHS_BLK), CSL_MMCHS_BLK_BLEN));
}

uint32_t HSMMCSDGetBlkCount(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + CSL_MMCHS_BLK), CSL_MMCHS_BLK_NBLK));
}


void HSMMCSDCommandSend(uint32_t baseAddr, const hsMmcsdCmdObj_t *pObj)
{
    uint32_t cmdRegVal = 0U;

    HW_SET_FIELD(cmdRegVal, CSL_MMCHS_CMD_INDX, pObj->cmd.cmdId);
    HW_SET_FIELD(cmdRegVal, CSL_MMCHS_CMD_CMD_TYPE, pObj->cmd.cmdType);
    HW_SET_FIELD(cmdRegVal, CSL_MMCHS_CMD_RSP_TYPE, pObj->cmd.rspType);
    HW_SET_FIELD(cmdRegVal, CSL_MMCHS_CMD_DDIR, pObj->cmd.xferType);

    if (TRUE == pObj->enableData)
    {
        HW_SET_FIELD(cmdRegVal, CSL_MMCHS_CMD_DP, CSL_MMCHS_CMD_DP_DATA);
        HW_SET_FIELD(cmdRegVal, CSL_MMCHS_CMD_MSBS, CSL_MMCHS_CMD_MSBS_MULTIBLK);
        HW_SET_FIELD(cmdRegVal, CSL_MMCHS_CMD_BCE, CSL_MMCHS_CMD_BCE_ENABLE);
    }

    if (TRUE == pObj->enableDma)
    {
  	   HW_SET_FIELD(cmdRegVal, CSL_MMCHS_CMD_DE, CSL_MMCHS_CMD_DE_ENABLE);
    }

    /* Set the block information; block length is specified separately */
    HW_WR_FIELD32((baseAddr + CSL_MMCHS_BLK), CSL_MMCHS_BLK_NBLK,
        pObj->numBlks);



	/* Set the command/command argument */
    HW_WR_REG32((baseAddr + CSL_MMCHS_ARG), pObj->cmdArg);
    HW_WR_REG32((baseAddr + CSL_MMCHS_CMD), cmdRegVal);
}


void HSMMCSDGetResponse(uint32_t baseAddr, uint32_t *pRsp)
{
    pRsp[0U] = HW_RD_REG32(baseAddr + CSL_MMCHS_RSP10);
    pRsp[1U] = HW_RD_REG32(baseAddr + CSL_MMCHS_RSP32);
    pRsp[2U] = HW_RD_REG32(baseAddr + CSL_MMCHS_RSP54);
    pRsp[3U] = HW_RD_REG32(baseAddr + CSL_MMCHS_RSP76);
}


void HSMMCSDGetData(uint32_t baseAddr, uint8_t *pData, uint32_t len)
{
    uint32_t idx;

    for (idx = 0U; idx < (len / 4U); idx++)
    {
        ((uint32_t*)pData)[idx] = HW_RD_REG32(baseAddr + CSL_MMCHS_DATA);
    }
}

void HSMMCSDSetData(uint32_t baseAddr, const uint8_t *pData, uint32_t len);  /*for misra warning*/
void HSMMCSDSetData(uint32_t baseAddr, const uint8_t *pData, uint32_t len)
{
    uint32_t idx;

    for (idx = 0U; idx < (len / 4U); idx++)
    {
        HW_WR_REG32((baseAddr + CSL_MMCHS_DATA), ((uint32_t*)pData)[idx]);
    }
}

uint32_t HSMMCSDGetCmdSignalLevel(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + CSL_MMCHS_PSTATE), CSL_MMCHS_PSTATE_CLEV));
	
}

uint32_t HSMMCSDGetDataSignalLevel(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + CSL_MMCHS_PSTATE), CSL_MMCHS_PSTATE_DLEV));
	
}


uint32_t HSMMCSDIsCardInserted(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + CSL_MMCHS_PSTATE), CSL_MMCHS_PSTATE_CDPL));
}


uint32_t HSMMCSDIsCardWriteProtected(uint32_t baseAddr)
{
    return HW_RD_FIELD32((baseAddr + CSL_MMCHS_PSTATE), CSL_MMCHS_PSTATE_WP);
}

void MMCSDContextSave(uint32_t mmcsdBase, hsMmcsdCtx_t *pCtx);  /*for misra warning*/
void MMCSDContextSave(uint32_t mmcsdBase, hsMmcsdCtx_t *pCtx)
{
    pCtx->capa = HW_RD_REG32(mmcsdBase + CSL_MMCHS_CAPA);
    pCtx->systemConfig = HW_RD_REG32(mmcsdBase + CSL_MMCHS_SYSCONFIG);
    pCtx->ctrlInfo = HW_RD_REG32(mmcsdBase + CSL_MMCHS_CON);
    pCtx->sysCtrl = HW_RD_REG32(mmcsdBase + CSL_MMCHS_SYSCTL);
    pCtx->pState = HW_RD_REG32(mmcsdBase + CSL_MMCHS_PSTATE);
    pCtx->hostCtrl = HW_RD_REG32(mmcsdBase + CSL_MMCHS_HCTL);
}


void MMCSDContextRestore(uint32_t mmcsdBase, const hsMmcsdCtx_t *pCtx);  /*for misra warning*/
void MMCSDContextRestore(uint32_t mmcsdBase, const hsMmcsdCtx_t *pCtx)
{
    HW_WR_REG32((mmcsdBase + CSL_MMCHS_SYSCONFIG), pCtx->systemConfig);
    HW_WR_REG32((mmcsdBase + CSL_MMCHS_SYSCTL), pCtx->sysCtrl);
    HW_WR_REG32((mmcsdBase + CSL_MMCHS_CAPA), pCtx->capa);
    HW_WR_REG32((mmcsdBase + CSL_MMCHS_CON), pCtx->ctrlInfo);
    HW_WR_REG32((mmcsdBase + CSL_MMCHS_HCTL), pCtx->hostCtrl);
    HW_WR_REG32((mmcsdBase + CSL_MMCHS_PSTATE), pCtx->pState);
}

/* ========================================================================== */
/*                   Deprecated Function Definitions                          */
/* ========================================================================== */
