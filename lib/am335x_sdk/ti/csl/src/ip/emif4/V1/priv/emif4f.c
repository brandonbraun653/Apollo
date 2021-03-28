/*
 *  Copyright (C) 2019 Texas Instruments Incorporated
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
 *  \file     emif4f.c
 *
 *  \brief    This file contains the implementation of the APIs present in the
 *            device abstraction layer file of EMIF.
 *            This also contains some related macros.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <string.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_emif4fAux.h>

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

int32_t EMIFConfigECCInitECCParams(uint32_t               baseAddr,
                                   const emifEccCfgPrm_t *pCfgPrm)
{
    uint32_t startAddr;
    uint32_t endAddr;
    uint32_t emifMsbStartAddr;
    const emifEccAddrRangeCfgPrm_t  *pAddrRangeCfgPrm;
	EMIF4_ECC_CONTROL pEmif4EccControl;
    int32_t  retVal = STW_SOK;

    if ((pCfgPrm == NULL) || (pCfgPrm->addrRangeCfgPrm == NULL))
    {
        retVal = STW_EFAIL;
    }
    else
    {
        pAddrRangeCfgPrm = pCfgPrm->addrRangeCfgPrm;
        emifMsbStartAddr = pCfgPrm->emifStartAddr;

        startAddr = (pAddrRangeCfgPrm->startAddr - emifMsbStartAddr) >> 17U;
        endAddr = ((pAddrRangeCfgPrm->endAddr - 0x10000000) & (0xFFFF0000)) >> 16U;
		//endAddr = 0x8000;

        CSL_EMIF4F_GetECCControl(&pEmif4EccControl);
        CSL_EMIF4F_SetECCAddressRange(pAddrRangeCfgPrm->addrRangeNum, endAddr, startAddr);
        if (pAddrRangeCfgPrm->addrRangeNum == EMIF_ECC_ADDR_RANGE_NUM_2)
        {
             /*Enable/Disable ECC address range 2*/
            pEmif4EccControl.addrRng2En = CSL_EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_2_EN_MAX;
        }
        else
        {
            /*Enable/Disable ECC address range 1*/
            pEmif4EccControl.addrRng1En = CSL_EMIF4FV_ECC_CTRL_REG_ECC_ADDR_RNG_1_EN_MAX;
        }

        /*Configs EMIF ECC Addr Range is within /Outside defined Addr range*/
		pEmif4EccControl.addrRngProt = pAddrRangeCfgPrm->addrRangeType;
        pEmif4EccControl.rmwEn = 0;
		pEmif4EccControl.eccVerifyEn = 0;
        CSL_EMIF4F_SetECCControl(&pEmif4EccControl);

        /*Configure the thresholds to generate 1-bit error interrupt*/
        CSL_FINS(hEmif->ONE_BIT_ECC_ERR_THRSH, EMIF4FV_ONE_BIT_ECC_ERR_THRSH_REG_1B_ECC_ERR_THRSH,\
                      pCfgPrm->thresholdVal );
    }

    return retVal;
}

void EMIFConfigECCEnableEcc(uint32_t baseAddr)
{
	//uint32_t i = 0xffffffff;
    /*Enable EMIF ECC*/
    CSL_FINS(hEmif->ECC_CTRL, EMIF4FV_ECC_CTRL_REG_ECC_EN, \
                      EMIF_ECC_ENABLE);

    //for (;i>0;i--);
    while (!(CSL_FEXT(hEmif->ECC_CTRL, EMIF4FV_ECC_CTRL_REG_ECC_EN)));
}

void EMIFConfigECCDisableEcc(uint32_t baseAddr)
{
    /*Disable EMIF ECC*/
    CSL_FINS(hEmif->ECC_CTRL, EMIF4FV_ECC_CTRL_REG_ECC_EN, \
                      EMIF_ECC_DISABLE);

     while ((CSL_FEXT(hEmif->ECC_CTRL, EMIF4FV_ECC_CTRL_REG_ECC_EN)));
}

void EMIFEnableIntr(uint32_t baseAddr, uint32_t intrMask)
{
    CSL_EMIF4F_EnableInterrupts(intrMask);
	//while (!(hEmif->IRQENABLE_SET_SYS && intrMask));
}

void EMIFDisableIntr(uint32_t baseAddr, uint32_t intrMask)
{
    CSL_EMIF4F_DisableInterrupts(intrMask);
}

void EMIFWriteEOI(uint32_t baseAddr)
{
    CSL_FINS (hEmif->IRQ_EOI, EMIF4FV_IRQ_EOI_REG_EOI, \
                          EMIF_EOI_CLEAR);
}

uint32_t EMIFGetIntrStatus(uint32_t baseAddr)
{
    return (hEmif->IRQSTATUS_SYS);
}

void EMIFClearIntrStatus(uint32_t baseAddr, uint32_t intrMask)
{
    CSL_EMIF4F_ClearInterruptStatus(intrMask);
}

uint32_t EMIFGetIntrRawStatus(uint32_t baseAddr)
{
    return (hEmif->IRQSTATUS_RAW_SYS);
}

int32_t EMIFConfigECCGetEccErrInfo(uint32_t          baseAddr,
                                   uint32_t          errType,
                                   emifEccErrInfo_t *pErrInfo)
{
    uint32_t fifoIndex = 0;
    int32_t  retVal    = STW_SOK;

    if (pErrInfo == NULL)
    {
        retVal = STW_EFAIL;
    }
    else
    {
        if ((errType & EMIF_ERR_ECC_ONEBIT) == EMIF_ERR_ECC_ONEBIT)
        {
            /* Reads ECC Err count and clears ECC Err count*/
            pErrInfo->errCnt = CSL_FEXT(hEmif->ONE_BIT_ECC_ERR_CNT,\
                        EMIF4FV_ONE_BIT_ECC_ERR_CNT_REG_1B_ECC_ERR_CNT);

            CSL_FINS(hEmif->ONE_BIT_ECC_ERR_CNT, EMIF4FV_ONE_BIT_ECC_ERR_CNT_REG_1B_ECC_ERR_CNT,\
                       pErrInfo->errCnt);

            /* Reads ECC Err Bit mask and clears ECC Err Bit mask*/
            pErrInfo->errBitLoc = CSL_FEXT(hEmif->ONE_BIT_ECC_ERR_DIST_1,\
                        EMIF4FV_ONE_BIT_ECC_ERR_DIST_1_REG_1B_ECC_ERR_DIST_1);

            CSL_FINS(hEmif->ONE_BIT_ECC_ERR_DIST_1, EMIF4FV_ONE_BIT_ECC_ERR_DIST_1_REG_1B_ECC_ERR_DIST_1,\
                       pErrInfo->errBitLoc);

            if (pErrInfo->errCnt > EMIF_ECC_FIFO_BUF_SIZE)
            {
                /* Address log FIFO Buffer is overflowed*/
                pErrInfo->numValidErrAddr = EMIF_ECC_FIFO_BUF_SIZE;
            }
            else
            {
                pErrInfo->numValidErrAddr = pErrInfo->errCnt;
            }

            while (fifoIndex < pErrInfo->numValidErrAddr)
            {
                /* Reads ECC Err Addr log and clears ECC Err Addr log reg and
                 * Address log Fifo Buffer */
                pErrInfo->errAddr[fifoIndex] =
                    (CSL_FEXT(hEmif->ONE_BIT_ECC_ERR_ADDR_LOG,\
                    EMIF4FV_ONE_BIT_ECC_ERR_ADDR_LOG_REG_1B_ECC_ERR_ADDR)) << 1;

                CSL_FINS(hEmif->ONE_BIT_ECC_ERR_ADDR_LOG, \
                    EMIF4FV_ONE_BIT_ECC_ERR_ADDR_LOG_REG_1B_ECC_ERR_ADDR, 0x1);
                fifoIndex++;
            }
        }
        else if ((errType & EMIF_ERR_ECC_TWOBIT) == EMIF_ERR_ECC_TWOBIT)
        {
            /* Reads ECC Err Addr log and clears ECC Err Addr log reg and
             * Address log Fifo Buffer */
            pErrInfo->errAddr[fifoIndex] =
                CSL_FEXT(hEmif->TWO_BIT_ECC_ERR_ADDR_LOG,\
                    EMIF4FV_TWO_BIT_ECC_ERR_ADDR_LOG_REG_2B_ECC_ERR_ADDR) << 1;

            CSL_FINS(hEmif->TWO_BIT_ECC_ERR_ADDR_LOG, \
                    EMIF4FV_TWO_BIT_ECC_ERR_ADDR_LOG_REG_2B_ECC_ERR_ADDR, 0x1);
        }
        else
        {
            /* Nothing */
        }
    }

    return retVal;
}

void EMIFConfigECCClrAllEccErrInfo(uint32_t baseAddr)
{
    uint32_t regVal;
    uint32_t errCnt;
    uint32_t numValidErrAddr;

    /* Clears 1Bit ECC Err Info*/
    errCnt = CSL_FEXT(hEmif->ONE_BIT_ECC_ERR_CNT,\
                        EMIF4FV_ONE_BIT_ECC_ERR_CNT_REG_1B_ECC_ERR_CNT);
    CSL_FINS(hEmif->ONE_BIT_ECC_ERR_CNT, \
                        EMIF4FV_ONE_BIT_ECC_ERR_CNT_REG_1B_ECC_ERR_CNT,\
                        errCnt);

    regVal = CSL_FEXT(hEmif->ONE_BIT_ECC_ERR_DIST_1,\
                        EMIF4FV_ONE_BIT_ECC_ERR_DIST_1_REG_1B_ECC_ERR_DIST_1);

    CSL_FINS(hEmif->ONE_BIT_ECC_ERR_DIST_1, \
                        EMIF4FV_ONE_BIT_ECC_ERR_DIST_1_REG_1B_ECC_ERR_DIST_1,\
                        regVal);

    if (errCnt > EMIF_ECC_FIFO_BUF_SIZE)
    {
        /* Adress log FIFO Buffer is overflowed*/
        numValidErrAddr = EMIF_ECC_FIFO_BUF_SIZE;
    }
    else
    {
        numValidErrAddr = errCnt;
    }

    while (numValidErrAddr)
    {
        regVal = CSL_FEXT(hEmif->ONE_BIT_ECC_ERR_ADDR_LOG,\
                    EMIF4FV_ONE_BIT_ECC_ERR_ADDR_LOG_REG_1B_ECC_ERR_ADDR);

        CSL_FINS(hEmif->ONE_BIT_ECC_ERR_ADDR_LOG, \
                    EMIF4FV_ONE_BIT_ECC_ERR_ADDR_LOG_REG_1B_ECC_ERR_ADDR, 0x1);

        numValidErrAddr = numValidErrAddr - 1U;
    }

    /* Clears 2Bit ECC Err Info*/
    regVal = CSL_FEXT(hEmif->TWO_BIT_ECC_ERR_ADDR_LOG,\
                    EMIF4FV_TWO_BIT_ECC_ERR_ADDR_LOG_REG_2B_ECC_ERR_ADDR);

    CSL_FINS(hEmif->TWO_BIT_ECC_ERR_ADDR_LOG, \
                    EMIF4FV_TWO_BIT_ECC_ERR_ADDR_LOG_REG_2B_ECC_ERR_ADDR, 0x1);
}
