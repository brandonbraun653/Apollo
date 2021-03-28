/**
 *  \file   edma.c
 *
 *  \brief This file contains device abstraction layer APIs for the EDMA device.
 *         There are APIs here to enable the EDMA instance, set the required
 *         configurations for communication, transmit or receive data.
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
#include "misc.h"
#include "error.h"
#include "hw_types.h"
#include "hw_edma_tpcc.h"
#include "dma.h"
#include "edma.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

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

void EDMAInit(uint32_t baseAddr, uint32_t region)
{
    uint32_t idx = 0U;
    uint32_t numIntrCh = EDMAGetNumIntrCh(baseAddr);
    uint32_t numDmaCh = EDMAGetNumDmaCh(baseAddr);
    uint32_t numQdmaCh = EDMAGetNumQdmaCh(baseAddr);
    uint32_t numRegion = EDMAGetNumRegions(baseAddr);

    if(region < numRegion)
    {
        EDMARegionReset(baseAddr, region);

        for(idx = 0U; idx < numDmaCh; idx++)
        {
            HW_WR_REG32(baseAddr + EDMA_TPCC_DCHMAP(idx), 0U);
        }

        for(idx = 0U; idx < (numDmaCh / 8U); idx++)
        {
            HW_WR_REG32(baseAddr + EDMA_TPCC_DMAQNUM(idx), 0U);
        }

        for(idx = 0U; idx < numQdmaCh; idx++)
        {
            HW_WR_REG32(baseAddr + EDMA_TPCC_QCHMAP(idx), 0U);
        }

        HW_WR_REG32(baseAddr + EDMA_TPCC_QDMAQNUM, 0U);

        HW_WR_REG32(baseAddr + EDMA_TPCC_EMCR, EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_QEMCR, EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_CCERRCLR, EDMA_SET_ALL_BITS);

        if(numIntrCh >= 32U)
        {
            HW_WR_REG32(baseAddr + EDMA_TPCC_EMCRH, EDMA_SET_ALL_BITS);
        }
    }
}

void EDMARegionReset(uint32_t baseAddr, uint32_t region)
{
    uint32_t numCh = EDMAGetNumIntrCh(baseAddr);
    uint32_t numRegion = EDMAGetNumRegions(baseAddr);

    if(region < numRegion)
    {
        HW_WR_REG32(baseAddr + EDMA_TPCC_DRAE(region), 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_QRAE(region), 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_S_ECR(region), EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_S_EECR(region), EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_S_SECR(region), EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_S_IECR(region), EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_S_ICR(region), EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_S_QEECR(region), EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_S_QSECR(region), EDMA_SET_ALL_BITS);

        if(numCh >= 32U)
        {
            HW_WR_REG32(baseAddr + EDMA_TPCC_DRAEH(region), 0U);
            HW_WR_REG32(baseAddr + EDMA_TPCC_S_ECRH(region), EDMA_SET_ALL_BITS);
            HW_WR_REG32(baseAddr + EDMA_TPCC_S_EECRH(region), EDMA_SET_ALL_BITS);
            HW_WR_REG32(baseAddr + EDMA_TPCC_S_SECRH(region), EDMA_SET_ALL_BITS);
            HW_WR_REG32(baseAddr + EDMA_TPCC_S_IECRH(region), EDMA_SET_ALL_BITS);
            HW_WR_REG32(baseAddr + EDMA_TPCC_S_ICRH(region), EDMA_SET_ALL_BITS);
        }
    }
    else if(region == numRegion)
    {
        HW_WR_REG32(baseAddr + EDMA_TPCC_ECR, EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_EECR, EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_SECR, EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_IECR, EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_ICR, EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_QEECR, EDMA_SET_ALL_BITS);
        HW_WR_REG32(baseAddr + EDMA_TPCC_QSECR, EDMA_SET_ALL_BITS);

        if(numCh >= 32U)
        {
            HW_WR_REG32(baseAddr + EDMA_TPCC_ECRH, EDMA_SET_ALL_BITS);
            HW_WR_REG32(baseAddr + EDMA_TPCC_EECRH, EDMA_SET_ALL_BITS);
            HW_WR_REG32(baseAddr + EDMA_TPCC_SECRH, EDMA_SET_ALL_BITS);
            HW_WR_REG32(baseAddr + EDMA_TPCC_IECRH, EDMA_SET_ALL_BITS);
            HW_WR_REG32(baseAddr + EDMA_TPCC_ICRH, EDMA_SET_ALL_BITS);
        }
    }
    else
    {
    }
}

uint32_t EDMAGetPeripheralId(uint32_t baseAddr)
{
    return (HW_RD_FIELD32(baseAddr + EDMA_TPCC_PID, EDMA_TPCC_PID));
}

uint32_t EDMAIsMemProtectionSupported(uint32_t baseAddr)
{
    uint32_t retVal = FALSE;

    if(EDMA_TPCC_CCCFG_MP_EXIST_TRUE ==
        HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCCFG, EDMA_TPCC_CCCFG_MP_EXIST))
    {
        retVal = TRUE;
    }
    return retVal;
}

uint32_t EDMAIsChMapSupported(uint32_t baseAddr)
{
    uint32_t retVal = FALSE;

    if(EDMA_TPCC_CCCFG_CHMAP_EXIST_TRUE ==
        HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCCFG, EDMA_TPCC_CCCFG_CHMAP_EXIST))
    {
        retVal = TRUE;
    }
    return retVal;
}

uint32_t EDMAGetNumRegions(uint32_t baseAddr)
{
    uint32_t retVal = 0U;
    uint32_t regFieldVal = 0U;

    regFieldVal = HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCCFG,
        EDMA_TPCC_CCCFG_NUM_REGN);

    switch(regFieldVal)
    {
        case 1U:
            retVal = 2U;
            break;

        case 2U:
            retVal = 4U;
            break;

        case 3U:
            retVal = 8U;
            break;

        default:
            retVal = 0U;
            break;
    }

    return retVal;
}

uint32_t EDMAGetNumQueues(uint32_t baseAddr)
{
    return (HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCCFG, EDMA_TPCC_CCCFG_NUM_EVQUE)
        + 1U);
}

uint32_t EDMAGetNumParamSets(uint32_t baseAddr)
{
    uint32_t retVal = 0U;
    uint32_t regFieldVal = 0U;

    regFieldVal = HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCCFG,
        EDMA_TPCC_CCCFG_NUM_PAENTRY);

    switch(regFieldVal)
    {
        case 1U:
            retVal = 32U;
            break;

        case 2U:
            retVal = 64U;
            break;

        case 3U:
            retVal = 128U;
            break;

        case 4U:
            retVal = 256U;
            break;

        case 5U:
            retVal = 512U;
            break;

        default:
            retVal = 16U;
            break;
    }

    return retVal;
}

uint32_t EDMAGetNumIntrCh(uint32_t baseAddr)
{
    uint32_t retVal = 0U;
    uint32_t regFieldVal = 0U;

    regFieldVal = HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCCFG,
        EDMA_TPCC_CCCFG_NUM_INTCH);
    if(regFieldVal && regFieldVal < 5)
	retVal = 1 << (2+ regFieldVal);
    else
	retVal = 0;
    return retVal;
}

uint32_t EDMAGetNumQdmaCh(uint32_t baseAddr)
{
    uint32_t retVal = 0U;
    uint32_t regFieldVal = 0U;

    regFieldVal = HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCCFG,
        EDMA_TPCC_CCCFG_NUM_QDMACH);

    switch(regFieldVal)
    {
        case 1U:
            retVal = 2U;
            break;

        case 2U:
            retVal = 4U;
            break;

        case 3U:
            retVal = 6U;
            break;

        case 4U:
            retVal = 8U;
            break;

        default:
            retVal = 0U;
            break;
    }

    return retVal;
}

uint32_t EDMAGetNumDmaCh(uint32_t baseAddr)
{
    uint32_t retVal = 0U;
    uint32_t regFieldVal = 0U;

    regFieldVal = HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCCFG,
        EDMA_TPCC_CCCFG_NUM_DMACH);

    switch(regFieldVal)
    {
        case 1U:
            retVal = 4U;
            break;

        case 2U:
            retVal = 8U;
            break;

        case 3U:
            retVal = 16U;
            break;

        case 4U:
            retVal = 32U;
            break;

        case 5U:
            retVal = 64U;
            break;

        default:
            retVal = 0U;
            break;
    }

    return retVal;
}

int32_t EDMAShdwRegionChEnable(uint32_t baseAddr,
                                uint32_t shdwRegion,
                                uint32_t chType,
                                uint32_t chNum)
{
    int32_t retVal = E_FAIL;
    uint32_t regVal = 0U;

    if(shdwRegion < EDMAGetNumRegions(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            /* FOR TYPE EDMA */
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                if(chNum < 32U)
                {
                    regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_DRAE(shdwRegion));
                    regVal |= (1U << chNum);
                    HW_WR_REG32(baseAddr + EDMA_TPCC_DRAE(shdwRegion), regVal);
                }
                else
                {
                    regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_DRAEH(shdwRegion));
                    regVal |= (1U << (chNum - 32U));
                    HW_WR_REG32(baseAddr + EDMA_TPCC_DRAEH(shdwRegion), regVal);
                }
                retVal = S_PASS;
            }
        }
        else if (EDMA_CH_TYPE_QDMA== chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumQdmaCh(baseAddr))
            {
                regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_QRAE(shdwRegion));
                regVal |= (1U << chNum);
                HW_WR_REG32(baseAddr + EDMA_TPCC_QRAE(shdwRegion), regVal);
                retVal = S_PASS;
            }
        }
    }
    return retVal;
}

int32_t EDMAShdwRegionChDisable(uint32_t baseAddr,
                                 uint32_t shdwRegion,
                                 uint32_t chType,
                                 uint32_t chNum)
{
    int32_t retVal = E_FAIL;
    uint32_t regVal = 0U;

    if(shdwRegion < EDMAGetNumRegions(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            /* FOR TYPE DMA */
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                if(chNum < 32U)
                {
                    regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_DRAE(shdwRegion));
                    regVal &= ~(1U << chNum);
                    HW_WR_REG32(baseAddr + EDMA_TPCC_DRAE(shdwRegion), regVal);
                }
                else
                {
                    regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_DRAEH(shdwRegion));
                    regVal &= ~(1U << (chNum - 32U));
                    HW_WR_REG32(baseAddr + EDMA_TPCC_DRAEH(shdwRegion), regVal);
                }
                retVal = S_PASS;
            }
        }
        else if (EDMA_CH_TYPE_QDMA== chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumQdmaCh(baseAddr))
            {
                regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_QRAE(shdwRegion));
                regVal &= ~(1U << chNum);
                HW_WR_REG32(baseAddr + EDMA_TPCC_QRAE(shdwRegion), regVal);
                retVal = S_PASS;
            }
        }
    }
    return retVal;
}

uint32_t EDMAIsChInShdwRegion(uint32_t baseAddr,
                              uint32_t shdwRegion,
                              uint32_t chType,
                              uint32_t chNum)
{
    uint32_t retVal = FALSE;
    uint32_t regVal = 0U;

    if(shdwRegion < EDMAGetNumRegions(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            /* FOR TYPE DMA */
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                if(chNum < 32U)
                {
                    regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_DRAE(shdwRegion));
                    regVal &= (1U << chNum);

                    if(0U == regVal)
                    {
                        retVal = FALSE;
                    }
                    else
                    {
                        retVal = TRUE;
                    }
                }
                else
                {
                    regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_DRAEH(shdwRegion));
                    regVal &= (1U << (chNum - 32U));

                    if(0U == regVal)
                    {
                        retVal = FALSE;
                    }
                    else
                    {
                        retVal = TRUE;
                    }
                }
            }
        }
        else if (EDMA_CH_TYPE_QDMA== chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumQdmaCh(baseAddr))
            {
                regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_QRAE(shdwRegion));
                regVal &= (1U << chNum);

                if(0U == regVal)
                {
                    retVal = FALSE;
                }
                else
                {
                    retVal = TRUE;
                }
            }
        }
    }
    return retVal;
}

int32_t EDMAChToParamSetMap(uint32_t baseAddr,
                             uint32_t chType,
                             uint32_t chNum,
                             uint32_t paramSet)
{
    int32_t retVal = E_FAIL;

    if(paramSet < EDMAGetNumParamSets(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            /* FOR TYPE DMA*/
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                /* Map Parameter RAM Set Number for specified channel */
                HW_WR_FIELD32(baseAddr + EDMA_TPCC_DCHMAP(chNum),
                    EDMA_TPCC_DCHMAP_PAENTRY, paramSet);
                retVal = S_PASS;
            }
        }
        else if (EDMA_CH_TYPE_QDMA== chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumQdmaCh(baseAddr))
            {
                /* Map Parameter RAM Set Number for specified channel */
                HW_WR_FIELD32(baseAddr + EDMA_TPCC_QCHMAP(chNum),
                    EDMA_TPCC_QCHMAP_PAENTRY, paramSet);
                retVal = S_PASS;
            }
        }
    }
    return retVal;
}

void EDMASetQdmaTriggerWord(uint32_t baseAddr,
                            uint32_t qdmaChNum,
                            uint32_t triggerWord)
{
    /* Set the Trigger Word */
    HW_WR_FIELD32(baseAddr + EDMA_TPCC_QCHMAP(qdmaChNum),
        EDMA_TPCC_QCHMAP_TRWORD, triggerWord);
}

int32_t EDMAChToEvtQueueMap(uint32_t baseAddr,
                         uint32_t chType,
                         uint32_t chNum,
                         uint32_t queueNum)
{
    int32_t retVal = E_FAIL;

    if(queueNum < EDMAGetNumQueues(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            /* FOR TYPE EDMA*/
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                retVal = S_PASS;
                switch(chNum % 8U)
                {
                    case 0U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_DMAQNUM(chNum >> 3U),
                            EDMA_TPCC_DMAQNUM_E0, queueNum);
                        break;

                    case 1U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_DMAQNUM(chNum >> 3U),
                            EDMA_TPCC_DMAQNUM_E1, queueNum);
                        break;

                    case 2U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_DMAQNUM(chNum >> 3U),
                            EDMA_TPCC_DMAQNUM_E2, queueNum);
                        break;

                    case 3U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_DMAQNUM(chNum >> 3U),
                            EDMA_TPCC_DMAQNUM_E3, queueNum);
                        break;

                    case 4U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_DMAQNUM(chNum >> 3U),
                            EDMA_TPCC_DMAQNUM_E4, queueNum);
                        break;

                    case 5U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_DMAQNUM(chNum >> 3U),
                            EDMA_TPCC_DMAQNUM_E5, queueNum);
                        break;

                    case 6U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_DMAQNUM(chNum >> 3U),
                            EDMA_TPCC_DMAQNUM_E6, queueNum);
                        break;

                    case 7U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_DMAQNUM(chNum >> 3U),
                            EDMA_TPCC_DMAQNUM_E7, queueNum);
                        break;

                    default:
                        retVal = E_FAIL;
                        break;
                }
            }
        }
        else if (EDMA_CH_TYPE_QDMA == chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                retVal = S_PASS;
                switch(chNum)
                {
                    case 0U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_QDMAQNUM,
                            EDMA_TPCC_QDMAQNUM_E0, queueNum);
                        break;

                    case 1U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_QDMAQNUM,
                            EDMA_TPCC_QDMAQNUM_E1, queueNum);
                        break;

                    case 2U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_QDMAQNUM,
                            EDMA_TPCC_QDMAQNUM_E2, queueNum);
                        break;

                    case 3U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_QDMAQNUM,
                            EDMA_TPCC_QDMAQNUM_E3, queueNum);
                        break;

                    case 4U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_QDMAQNUM,
                            EDMA_TPCC_QDMAQNUM_E4, queueNum);
                        break;

                    case 5U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_QDMAQNUM,
                            EDMA_TPCC_QDMAQNUM_E5, queueNum);
                        break;

                    case 6U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_QDMAQNUM,
                            EDMA_TPCC_QDMAQNUM_E6, queueNum);
                        break;

                    case 7U:
                        HW_WR_FIELD32(baseAddr + EDMA_TPCC_QDMAQNUM,
                            EDMA_TPCC_QDMAQNUM_E7, queueNum);
                        break;

                    default:
                        retVal = E_FAIL;
                        break;
                }
            }
        }
    }
    return retVal;
}

int32_t EDMAChMissEvtClear(uint32_t baseAddr,
                           uint32_t region,
                           uint32_t chType,
                           uint32_t chNum)
{
    int32_t retVal = E_FAIL;
    uint32_t regVal = 0U;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            /* FOR TYPE EDMA*/
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                if(chNum < 32U)
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_EMCR, (1U << chNum));
                    HW_WR_REG32(baseAddr + EDMA_TPCC_S_SECR(region),
                        (1U << chNum));
                }
                else
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_EMCRH, (1U << (chNum -32U)));
                    HW_WR_REG32(baseAddr + EDMA_TPCC_S_SECRH(region),
                        (1U << (chNum -32U)));
                }
                retVal = S_PASS;
            }
        }
        else if (EDMA_CH_TYPE_QDMA == chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_QEMCR, (1U << chNum));
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_QSECR(region), (1U << chNum));
            }
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            /* FOR TYPE EDMA*/
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                if(chNum < 32U)
                {
                    regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_EMCR);
                    regVal &= ~(1U << chNum);
                    HW_WR_REG32(baseAddr + EDMA_TPCC_EMCR, regVal);
                    HW_WR_REG32(baseAddr + EDMA_TPCC_SECR, regVal);
                }
                else
                {
                    regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_EMCRH);
                    regVal &= ~(1U << (chNum - 32U));
                    HW_WR_REG32(baseAddr + EDMA_TPCC_EMCRH, regVal);
                    HW_WR_REG32(baseAddr + EDMA_TPCC_SECRH, regVal);
                }
                retVal = S_PASS;
            }
        }
        else if (EDMA_CH_TYPE_QDMA == chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_QEMCR);
                regVal &= ~(1U << chNum);
                HW_WR_REG32(baseAddr + EDMA_TPCC_QEMCR, regVal);
                HW_WR_REG32(baseAddr + EDMA_TPCC_QSECR, regVal);
            }
        }
    }
    else
    {
    }

    return retVal;
}

uint32_t EDMAEvtMissStatus(uint32_t baseAddr,
                           uint32_t chType,
                           uint32_t chSet)
{
    uint32_t retVal = 0U;

    if (EDMA_CH_TYPE_DMA == chType)
    {
        /* FOR TYPE EDMA */
        if(EDMA_CH_SET_0_31 == chSet)
        {
            retVal = HW_RD_REG32(baseAddr + EDMA_TPCC_EMR);
        }
        else
        {
            retVal = HW_RD_REG32(baseAddr + EDMA_TPCC_EMRH);
        }
    }
    else if (EDMA_CH_TYPE_QDMA== chType)
    {
        /* FOR TYPE QDMA */
        retVal = HW_RD_REG32(baseAddr + EDMA_TPCC_QEMR);
    }

    return retVal;
}

void EDMAComplCodeErrClear(uint32_t baseAddr)
{
    /* (CCERRCLR) - clear channel controller error register */
    HW_WR_FIELD32(baseAddr + EDMA_TPCC_CCERRCLR, EDMA_TPCC_CCERRCLR_TCCERR,
        EDMA_TPCC_CCERRCLR_TCCERR_CLEAR);
}

int32_t EDMAQueueThresholdErrClear(uint32_t baseAddr, uint32_t queueNum)
{
    int32_t retVal = E_FAIL;

    if(queueNum < EDMAGetNumQueues(baseAddr))
    {
        switch(queueNum)
        {
            case 0U:
                HW_WR_FIELD32(baseAddr + EDMA_TPCC_CCERRCLR,
                    EDMA_TPCC_CCERRCLR_QTHRXCD0, 1U);
                break;

            case 1U:
                HW_WR_FIELD32(baseAddr + EDMA_TPCC_CCERRCLR,
                    EDMA_TPCC_CCERRCLR_QTHRXCD1, 1U);
                break;

            case 2U:
                HW_WR_FIELD32(baseAddr + EDMA_TPCC_CCERRCLR,
                    EDMA_TPCC_CCERRCLR_QTHRXCD2, 1U);
                break;

            default:
                break;
        }
        retVal = S_PASS;
    }
    return retVal;
}

uint32_t EDMAComplCodeErrStatus(uint32_t baseAddr)
{
    uint32_t retVal = FALSE;
    uint32_t regFieldVal = 0U;

    regFieldVal = HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCERR,
        EDMA_TPCC_CCERR_TCCERR);

    if(EDMA_TPCC_CCERR_TCCERR_REACHED == regFieldVal)
    {
        retVal = TRUE;
    }
    return retVal;
}

uint32_t EDMAQueueThresholdErrStatus(uint32_t baseAddr, uint32_t queueNum)
{
    uint32_t retVal = FALSE;

    if(queueNum < EDMAGetNumQueues(baseAddr))
    {
        switch(queueNum)
        {
            case 0U:
                retVal = HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCERR,
                    EDMA_TPCC_CCERRCLR_QTHRXCD0);
                break;

            case 1U:
                retVal = HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCERR,
                    EDMA_TPCC_CCERRCLR_QTHRXCD1);
                break;

            case 2U:
                retVal = HW_RD_FIELD32(baseAddr + EDMA_TPCC_CCERR,
                    EDMA_TPCC_CCERRCLR_QTHRXCD2);
                break;

            default:
                break;
        }
    }
    return retVal;
}

int32_t EDMASetEvt(uint32_t baseAddr, uint32_t region, uint32_t dmaChNum)
{
    int32_t retVal = E_FAIL;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if(dmaChNum < EDMAGetNumDmaCh(baseAddr))
        {
            if(dmaChNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_ESR(region),
                    (1U << dmaChNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_ESRH(region),
                    (1U << (dmaChNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if(dmaChNum < EDMAGetNumDmaCh(baseAddr))
        {
            if(dmaChNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_ESR, (1U << dmaChNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_ESRH, (1U << (dmaChNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else
    {
    }
    return retVal;
}

int32_t EDMAEvtClear(uint32_t baseAddr, uint32_t region, uint32_t dmaChNum)
{
    int32_t retVal = E_FAIL;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if(dmaChNum < EDMAGetNumDmaCh(baseAddr))
        {
            if(dmaChNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_ECR(region), (1U << dmaChNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_ECRH(region), (1U << (dmaChNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if(dmaChNum < EDMAGetNumDmaCh(baseAddr))
        {
            if(dmaChNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_ECR, (1U << dmaChNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_ECRH, (1U << (dmaChNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else
    {
    }
    return retVal;
}

uint32_t EDMAEvtStatus(uint32_t baseAddr,
                       uint32_t region,
                       uint32_t dmaChNum)
{
    uint32_t retVal = FALSE;
    uint32_t regVal = 0U;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if(dmaChNum < EDMAGetNumDmaCh(baseAddr))
        {
            if(32U > dmaChNum)
            {
                regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_S_ER(region));
                if(0U != (regVal & (1U << (dmaChNum -32U))))
                {
                    retVal = TRUE;
                }
            }
            else
            {
                regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_S_ERH(region));
                if(0U != (regVal & (1U << dmaChNum)))
                {
                    retVal = TRUE;
                }
            }
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if(dmaChNum < EDMAGetNumDmaCh(baseAddr))
        {
            if(32U > dmaChNum)
            {
                regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_ER);
                if(0U != (regVal & (1U << (dmaChNum -32U))))
                {
                    retVal = TRUE;
                }
            }
            else
            {
                regVal = HW_RD_REG32(baseAddr + EDMA_TPCC_ERH);
                if(0U != (regVal & (1U << dmaChNum)))
                {
                    retVal = TRUE;
                }
            }
        }
    }
    else
    {
    }
    return retVal;
}

int32_t EDMAEvtEnable(uint32_t baseAddr,
                      uint32_t region,
                      uint32_t chType,
                      uint32_t chNum)
{
    int32_t retVal = E_FAIL;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                if(chNum < 32U)
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_S_EESR(region),
                        (1U << chNum));
                    retVal = S_PASS;
                }
                else
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_S_EESRH(region),
                        (1U << (chNum - 32U)));
                    retVal = S_PASS;
                }
            }
        }
        else if (EDMA_CH_TYPE_QDMA== chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumQdmaCh(baseAddr))
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_QEESR(region), (1U << chNum));
                retVal = S_PASS;
            }
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                if(chNum < 32U)
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_EESR, (1U << chNum));
                    retVal = S_PASS;
                }
                else
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_EESRH,
                        (1U << (chNum - 32U)));
                    retVal = S_PASS;
                }
            }
        }
        else if (EDMA_CH_TYPE_QDMA== chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumQdmaCh(baseAddr))
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_QEESR, (1U << chNum));
                retVal = S_PASS;
            }
        }
    }
    else
    {
    }
    return retVal;
}

int32_t EDMAEvtDisable(uint32_t baseAddr,
                        uint32_t region,
                        uint32_t chType,
                        uint32_t chNum)
{
    int32_t retVal = E_FAIL;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                if(chNum < 32U)
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_S_EECR(region),
                        (1U << chNum));
                    retVal = S_PASS;
                }
                else
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_S_EECRH(region),
                        (1U << (chNum - 32U)));
                    retVal = S_PASS;
                }
            }
        }
        else if (EDMA_CH_TYPE_QDMA== chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumQdmaCh(baseAddr))
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_QEECR(region), (1U << chNum));
                retVal = S_PASS;
            }
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if (EDMA_CH_TYPE_DMA == chType)
        {
            if(chNum < EDMAGetNumDmaCh(baseAddr))
            {
                if(chNum < 32U)
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_EECR, (1U << chNum));
                    retVal = S_PASS;
                }
                else
                {
                    HW_WR_REG32(baseAddr + EDMA_TPCC_EECRH,
                        (1U << (chNum - 32U)));
                    retVal = S_PASS;
                }
            }
        }
        else if (EDMA_CH_TYPE_QDMA== chType)
        {
            /* FOR TYPE QDMA */
            if(chNum < EDMAGetNumQdmaCh(baseAddr))
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_QEECR, (1U << chNum));
                retVal = S_PASS;
            }
        }
    }
    else
    {
    }
    return retVal;
}

int32_t EDMAIntrEnable(uint32_t baseAddr,
                        uint32_t region,
                        uint32_t chNum)
{
    int32_t retVal = E_FAIL;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if(chNum < EDMAGetNumIntrCh(baseAddr))
        {
            if(chNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_IESR(region), (1U << chNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_IESRH(region),
                    (1U << (chNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if(chNum < EDMAGetNumIntrCh(baseAddr))
        {
            if(chNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_IESR, (1U << chNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_IESRH, (1U << (chNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else
    {
    }
    return retVal;
}

int32_t EDMAIntrDisable(uint32_t baseAddr,
                         uint32_t region,
                         uint32_t chNum)
{
    int32_t retVal = E_FAIL;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if(chNum < EDMAGetNumIntrCh(baseAddr))
        {
            if(chNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_IECR(region), (1U << chNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_IECRH(region),
                    (1U << (chNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if(chNum < EDMAGetNumIntrCh(baseAddr))
        {
            if(chNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_IECR, (1U << chNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_IECRH, (1U << (chNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else
    {
    }
    return retVal;
}

uint32_t EDMAIntrStatus(uint32_t baseAddr,
                        uint32_t region,
                        uint32_t chSet)
{
    uint32_t retVal = 0U;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if(EDMA_CH_SET_0_31 == chSet)
        {
            retVal = HW_RD_REG32(baseAddr + EDMA_TPCC_S_IPR(region));
        }
        else
        {
            retVal = HW_RD_REG32(baseAddr + EDMA_TPCC_S_IPRH(region));
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if(EDMA_CH_SET_0_31 == chSet)
        {
            retVal = HW_RD_REG32(baseAddr + EDMA_TPCC_IPR);
        }
        else
        {
            retVal = HW_RD_REG32(baseAddr + EDMA_TPCC_IPRH);
        }
    }
    else
    {
    }

    return retVal;
}

int32_t EDMAIntrClear(uint32_t baseAddr, uint32_t region, uint32_t chNum)
{
    int32_t retVal = E_FAIL;

    if(region < EDMAGetNumRegions(baseAddr))
    {
        if(chNum < EDMAGetNumIntrCh(baseAddr))
        {
            if(chNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_ICR(region), (1U << chNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_S_ICRH(region), (1U << (chNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else if(region == EDMAGetNumRegions(baseAddr))
    {
        if(chNum < EDMAGetNumIntrCh(baseAddr))
        {
            if(chNum < 32U)
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_ICR, (1U << chNum));
                retVal = S_PASS;
            }
            else
            {
                HW_WR_REG32(baseAddr + EDMA_TPCC_ICRH, (1U << (chNum - 32U)));
                retVal = S_PASS;
            }
        }
    }
    else
    {
    }
    return retVal;
}

int32_t EDMASetParamEntry(uint32_t baseAddr,
                           uint32_t paRamIdx,
                           EDMAParamEntry_t* pParamEntry)
{
    int32_t retVal = E_FAIL;

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_OPT,
            pParamEntry->word1);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_SRC,
            pParamEntry->word2);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_A_B_CNT,
            pParamEntry->word3);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_DST,
            pParamEntry->word4);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_SRC_DST_BIDX,
            pParamEntry->word5);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_LINK_BCNT_RLD,
            pParamEntry->word6);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_SRC_DST_CIDX,
            pParamEntry->word7);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_C_CNT,
            pParamEntry->word8);
        retVal = S_PASS;
    }

    return retVal;
}

int32_t EDMAGetParamEntry(uint32_t baseAddr,
                           uint32_t paRamIdx,
                           EDMAParamEntry_t* pParamEntry)
{
    int32_t retVal = E_FAIL;

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        pParamEntry->word1 = HW_RD_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_OPT);
        pParamEntry->word2 = HW_RD_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_SRC);
        pParamEntry->word3 = HW_RD_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_A_B_CNT);
        pParamEntry->word4 = HW_RD_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_DST);
        pParamEntry->word5 = HW_RD_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_SRC_DST_BIDX);
        pParamEntry->word6 = HW_RD_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_LINK_BCNT_RLD);
        pParamEntry->word7 = HW_RD_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_SRC_DST_CIDX);
        pParamEntry->word8 = HW_RD_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_C_CNT);
        retVal = S_PASS;
    }

    return retVal;
}

int32_t EDMAParamReset(uint32_t baseAddr, uint32_t paRamIdx)
{
    int32_t retVal = E_FAIL;

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_OPT, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_SRC, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_A_B_CNT, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_DST, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_SRC_DST_BIDX, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_LINK_BCNT_RLD, 0U);
        HW_WR_FIELD32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_LINK_BCNT_RLD, EDMA_PARAM_LINK, 0xFFFFU);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_SRC_DST_CIDX, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_C_CNT, 0U);
        retVal = S_PASS;
    }

    return retVal;
}

int32_t EDMASetParamDummy(uint32_t baseAddr, uint32_t paRamIdx)
{
    int32_t retVal = E_FAIL;

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_OPT, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_SRC, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_A_B_CNT, 0U);
        HW_WR_FIELD32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_A_B_CNT, EDMA_PARAM_A_CNT, 1U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) + EDMA_PARAM_DST, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_SRC_DST_BIDX, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_LINK_BCNT_RLD, 0U);
        HW_WR_FIELD32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_LINK_BCNT_RLD, EDMA_PARAM_LINK, 0xFFFFU);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_SRC_DST_CIDX, 0U);
        HW_WR_REG32(baseAddr + EDMA_TPCC_PARAM(paRamIdx) +
            EDMA_PARAM_C_CNT, 0U);
        retVal = S_PASS;
    }

    return retVal;
}

int32_t EDMAParamConfig(uint32_t baseAddr,
                         uint32_t paRamIdx,
                         EDMAParamConfig_t *pParamConfig)
{
    int32_t retVal = E_FAIL;
    uint32_t maxPaRamSet = EDMAGetNumParamSets(baseAddr);
    uint32_t maxIntrCh = EDMAGetNumIntrCh(baseAddr);
    EDMAParamDataConfig_t *pSrc = NULL;
    EDMAParamDataConfig_t *pDst = NULL;
    EDMAParamEntry_t paramset = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        if(NULL != pParamConfig)
        {
            if(NULL != pParamConfig->pSrc)
            {
                pSrc = pParamConfig->pSrc;
                if(NULL != pParamConfig->pDst)
                {
                    pDst = pParamConfig->pDst;
                    retVal = S_PASS;
                }
            }
        }
    }

    if(S_PASS == retVal)
    {
        if(FALSE == pParamConfig->enableLink)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_STATIC, EDMA_PARAM_OPT_STATIC_DISABLE);
            HW_SET_FIELD(paramset.word6,
                EDMA_PARAM_LINK, 0xFFFFU);
        }
        else
        {
            if(FALSE == pParamConfig->enableStatic)
            {
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_STATIC, EDMA_PARAM_OPT_STATIC_DISABLE);
            }
            else
            {
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_STATIC, EDMA_PARAM_OPT_STATIC_ENABLE);
            }

            if(pParamConfig->linkAddr < maxPaRamSet)
            {
                HW_SET_FIELD(paramset.word6,
                    EDMA_PARAM_LINK, EDMA_TPCC_PARAM(pParamConfig->linkAddr));
            }
            else
            {
                retVal = E_FAIL;
            }
        }
    }

    if(S_PASS == retVal)
    {
        if(EDMA_PARAM_PRIV_LVL_USER == pParamConfig->privType)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_PRIV, EDMA_PARAM_OPT_PRIV_USER);
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_PRIV_ID, 0U);
        }
        else if(EDMA_PARAM_PRIV_LVL_SUPERVISOR == pParamConfig->privType)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_PRIV, EDMA_PARAM_OPT_PRIV_SUPERVISOR);
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_PRIV_ID, pParamConfig->privId);
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        if(FALSE == pParamConfig->enableChain)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_DISABLE);
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_DISABLE);
        }
        else if(TRUE == pParamConfig->enableChain)
        {
            switch(pParamConfig->chainMask)
            {
                case 0U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_DISABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_DISABLE);
                    break;

                case 1U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_ENABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_DISABLE);
                    break;

                case 2U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_DISABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_ENABLE);
                    break;

                case 3U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_ENABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_ENABLE);
                    break;

                default:
                    retVal = E_FAIL;
                    break;
            }
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        if((pParamConfig->tccMode >= EDMA_PARAM_TCC_MODE_MIN)
            && (pParamConfig->tccMode <= EDMA_PARAM_TCC_MODE_MAX))
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_TCC_MODE, pParamConfig->tccMode);
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        if(pParamConfig->tcc < maxIntrCh)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_TCC, pParamConfig->tcc);
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        switch(pParamConfig->intrMask)
        {
            case 0U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_DISABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_DISABLE);
                break;

            case 1U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_ENABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_DISABLE);
                break;

            case 2U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_DISABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_ENABLE);
                break;

            case 3U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_ENABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_ENABLE);
                break;

            default:
                retVal = E_FAIL;
                break;
        }
    }

    if(S_PASS == retVal)
    {
        HW_SET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_SRC_ADDR_MODE, pSrc->addrMode);
        paramset.word2 = pSrc->addrOff.addr;
        HW_SET_FIELD(paramset.word5,
            EDMA_PARAM_SRC_BIDX, pSrc->addrOff.bCntIdx);
        HW_SET_FIELD(paramset.word7,
            EDMA_PARAM_SRC_CIDX, pSrc->addrOff.cCntIdx);
        HW_SET_FIELD(paramset.word3,
            EDMA_PARAM_A_CNT, pSrc->size.aCnt);
        HW_SET_FIELD(paramset.word3,
            EDMA_PARAM_B_CNT, pSrc->size.bCnt);
        HW_SET_FIELD(paramset.word8,
            EDMA_PARAM_C_CNT, pSrc->size.cCnt);
        HW_SET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_SYNC_DIM, pSrc->syncType);
        HW_SET_FIELD(paramset.word6,
            EDMA_PARAM_BCNT_RLD, pSrc->size.bCntRld);
        HW_SET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_DST_ADDR_MODE, pDst->addrMode);
        paramset.word4 = pDst->addrOff.addr;
        HW_SET_FIELD(paramset.word5,
            EDMA_PARAM_DST_BIDX, pDst->addrOff.bCntIdx);
        HW_SET_FIELD(paramset.word7,
            EDMA_PARAM_DST_CIDX, pDst->addrOff.cCntIdx);

        retVal = EDMASetParamEntry(baseAddr, paRamIdx, &paramset);
    }

    return retVal;
}

int32_t EDMAParamXferConfig(uint32_t baseAddr,
                            uint32_t paRamIdx,
                            EDMAParamConfig_t *pParamConfig)
{
    int32_t retVal = E_FAIL;
    uint32_t maxPaRamSet = EDMAGetNumParamSets(baseAddr);
    EDMAParamDataConfig_t *pSrc = NULL;
    EDMAParamDataConfig_t *pDst = NULL;
    EDMAParamEntry_t paramset = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        if(NULL != pParamConfig)
        {
            if(NULL != pParamConfig->pSrc)
            {
                pSrc = pParamConfig->pSrc;
                if(NULL != pParamConfig->pDst)
                {
                    pDst = pParamConfig->pDst;
                    retVal = EDMAGetParamEntry(baseAddr, paRamIdx, &paramset);
                }
            }
        }
    }

    if(S_PASS == retVal)
    {
        if(FALSE == pParamConfig->enableLink)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_STATIC, EDMA_PARAM_OPT_STATIC_DISABLE);
            HW_SET_FIELD(paramset.word6,
                EDMA_PARAM_LINK, 0xFFFFU);
        }
        else
        {
            if(FALSE == pParamConfig->enableStatic)
            {
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_STATIC, EDMA_PARAM_OPT_STATIC_DISABLE);
            }
            else
            {
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_STATIC, EDMA_PARAM_OPT_STATIC_ENABLE);
            }

            if(pParamConfig->linkAddr < maxPaRamSet)
            {
                HW_SET_FIELD(paramset.word6,
                    EDMA_PARAM_LINK, EDMA_TPCC_PARAM(pParamConfig->linkAddr));
            }
            else
            {
                retVal = E_FAIL;
            }
        }
    }

    if(S_PASS == retVal)
    {
        if(EDMA_PARAM_PRIV_LVL_USER == pParamConfig->privType)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_PRIV, EDMA_PARAM_OPT_PRIV_USER);
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_PRIV_ID, 0U);
        }
        else if(EDMA_PARAM_PRIV_LVL_SUPERVISOR == pParamConfig->privType)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_PRIV, EDMA_PARAM_OPT_PRIV_SUPERVISOR);
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_PRIV_ID, pParamConfig->privId);
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        if(FALSE == pParamConfig->enableChain)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_DISABLE);
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_DISABLE);
        }
        else if(TRUE == pParamConfig->enableChain)
        {
            switch(pParamConfig->chainMask)
            {
                case 0U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_DISABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_DISABLE);
                    break;

                case 1U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_ENABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_DISABLE);
                    break;

                case 2U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_DISABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_ENABLE);
                    break;

                case 3U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_ENABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_ENABLE);
                    break;

                default:
                    retVal = E_FAIL;
                    break;
            }
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        switch(pParamConfig->intrMask)
        {
            case 0U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_DISABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_DISABLE);
                break;

            case 1U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_ENABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_DISABLE);
                break;

            case 2U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_DISABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_ENABLE);
                break;

            case 3U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_ENABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_ENABLE);
                break;

            default:
                retVal = E_FAIL;
                break;
        }
    }

    if(S_PASS == retVal)
    {
        HW_SET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_SRC_ADDR_MODE, pSrc->addrMode);
        paramset.word2 = pSrc->addrOff.addr;
        HW_SET_FIELD(paramset.word5,
            EDMA_PARAM_SRC_BIDX, pSrc->addrOff.bCntIdx);
        HW_SET_FIELD(paramset.word7,
            EDMA_PARAM_SRC_CIDX, pSrc->addrOff.cCntIdx);
        HW_SET_FIELD(paramset.word3,
            EDMA_PARAM_A_CNT, pSrc->size.aCnt);
        HW_SET_FIELD(paramset.word3,
            EDMA_PARAM_B_CNT, pSrc->size.bCnt);
        HW_SET_FIELD(paramset.word8,
            EDMA_PARAM_C_CNT, pSrc->size.cCnt);
        HW_SET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_SYNC_DIM, pSrc->syncType);
        HW_SET_FIELD(paramset.word6,
            EDMA_PARAM_BCNT_RLD, pSrc->size.bCntRld);
        HW_SET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_DST_ADDR_MODE, pDst->addrMode);
        paramset.word4 = pDst->addrOff.addr;
        HW_SET_FIELD(paramset.word5,
            EDMA_PARAM_DST_BIDX, pDst->addrOff.bCntIdx);
        HW_SET_FIELD(paramset.word7,
            EDMA_PARAM_DST_CIDX, pDst->addrOff.cCntIdx);

        retVal = EDMASetParamEntry(baseAddr, paRamIdx, &paramset);
    }

    return retVal;
}

int32_t EDMAParamLinkConfig(uint32_t baseAddr,
                            uint32_t paRamIdx,
                            EDMAParamConfig_t *pParamConfig)
{
    int32_t retVal = E_FAIL;
    uint32_t maxPaRamSet = EDMAGetNumParamSets(baseAddr);
    EDMAParamEntry_t paramset = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        if(NULL != pParamConfig)
        {
            retVal = EDMAGetParamEntry(baseAddr, paRamIdx, &paramset);
        }
    }

    if(S_PASS == retVal)
    {
        if(FALSE == pParamConfig->enableLink)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_STATIC, EDMA_PARAM_OPT_STATIC_DISABLE);
            HW_SET_FIELD(paramset.word6,
                EDMA_PARAM_LINK, 0xFFFFU);
        }
        else
        {
            if(FALSE == pParamConfig->enableStatic)
            {
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_STATIC, EDMA_PARAM_OPT_STATIC_DISABLE);
            }
            else
            {
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_STATIC, EDMA_PARAM_OPT_STATIC_ENABLE);
            }

            if(pParamConfig->linkAddr < maxPaRamSet)
            {
                HW_SET_FIELD(paramset.word6,
                    EDMA_PARAM_LINK, EDMA_TPCC_PARAM(pParamConfig->linkAddr));
            }
            else
            {
                retVal = E_FAIL;
            }
        }
    }

    if(S_PASS == retVal)
    {
        retVal = EDMASetParamEntry(baseAddr, paRamIdx, &paramset);
    }

    return retVal;
}

int32_t EDMAParamChainConfig(uint32_t baseAddr,
                             uint32_t paRamIdx,
                             EDMAParamConfig_t *pParamConfig)
{
    int32_t retVal = E_FAIL;
    uint32_t maxIntrCh = EDMAGetNumIntrCh(baseAddr);
    EDMAParamEntry_t paramset = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        if(NULL != pParamConfig)
        {
            retVal = EDMAGetParamEntry(baseAddr, paRamIdx, &paramset);
        }
    }

    if(S_PASS == retVal)
    {
        if(FALSE == pParamConfig->enableChain)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_DISABLE);
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_DISABLE);
        }
        else if(TRUE == pParamConfig->enableChain)
        {
            switch(pParamConfig->chainMask)
            {
                case 0U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_DISABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_DISABLE);
                    break;

                case 1U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_ENABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_DISABLE);
                    break;

                case 2U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_DISABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_ENABLE);
                    break;

                case 3U:
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_ITC_CH_EN, EDMA_PARAM_OPT_ITC_CH_EN_ENABLE);
                    HW_SET_FIELD(paramset.word1,
                        EDMA_PARAM_OPT_TC_CH_EN, EDMA_PARAM_OPT_TC_CH_EN_ENABLE);
                    break;

                default:
                    retVal = E_FAIL;
                    break;
            }
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        if((pParamConfig->tccMode >= EDMA_PARAM_TCC_MODE_MIN)
            && (pParamConfig->tccMode <= EDMA_PARAM_TCC_MODE_MAX))
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_TCC_MODE, pParamConfig->tccMode);
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        if(pParamConfig->tcc < maxIntrCh)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_TCC, pParamConfig->tcc);
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        retVal = EDMASetParamEntry(baseAddr, paRamIdx, &paramset);
    }

    return retVal;
}

int32_t EDMAParamIntrConfig(uint32_t baseAddr,
                            uint32_t paRamIdx,
                            EDMAParamConfig_t *pParamConfig)
{
    int32_t retVal = E_FAIL;
    uint32_t maxIntrCh = EDMAGetNumIntrCh(baseAddr);
    EDMAParamEntry_t paramset = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        if(NULL != pParamConfig)
        {
            retVal = EDMAGetParamEntry(baseAddr, paRamIdx, &paramset);
        }
    }

    if(S_PASS == retVal)
    {
        if((pParamConfig->tccMode >= EDMA_PARAM_TCC_MODE_MIN)
            && (pParamConfig->tccMode <= EDMA_PARAM_TCC_MODE_MAX))
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_TCC_MODE, pParamConfig->tccMode);
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        if(pParamConfig->tcc < maxIntrCh)
        {
            HW_SET_FIELD(paramset.word1,
                EDMA_PARAM_OPT_TCC, pParamConfig->tcc);
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        switch(pParamConfig->intrMask)
        {
            case 0U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_DISABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_DISABLE);
                break;

            case 1U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_ENABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_DISABLE);
                break;

            case 2U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_DISABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_ENABLE);
                break;

            case 3U:
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_ITC_INT_EN, EDMA_PARAM_OPT_ITC_INT_EN_ENABLE);
                HW_SET_FIELD(paramset.word1,
                    EDMA_PARAM_OPT_TC_INT_EN, EDMA_PARAM_OPT_TC_INT_EN_ENABLE);
                break;

            default:
                retVal = E_FAIL;
                break;
        }
    }

    if(S_PASS == retVal)
    {
        retVal = EDMASetParamEntry(baseAddr, paRamIdx, &paramset);
    }

    return retVal;
}

int32_t EDMAGetParamConfig(uint32_t baseAddr,
                           uint32_t paRamIdx,
                           EDMAParamConfig_t *pParamConfig)
{
    int32_t retVal = E_FAIL;
    uint32_t linkAddr = 0U;
    uint32_t maxPaRamSet = EDMAGetNumParamSets(baseAddr);
    uint32_t maxIntrCh = EDMAGetNumIntrCh(baseAddr);
    EDMAParamDataConfig_t *pSrc = NULL;
    EDMAParamDataConfig_t *pDst = NULL;
    EDMAParamEntry_t paramset = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

    if (paRamIdx < EDMAGetNumParamSets(baseAddr))
    {
        if(NULL != pParamConfig)
        {
            if(NULL != pParamConfig->pSrc)
            {
                pSrc = pParamConfig->pSrc;
                if(NULL != pParamConfig->pDst)
                {
                    pDst = pParamConfig->pDst;
                    retVal = EDMAGetParamEntry(baseAddr, paRamIdx, &paramset);
                }
            }
        }
    }

    if(S_PASS == retVal)
    {
        linkAddr = HW_GET_FIELD(paramset.word6, EDMA_PARAM_LINK);

        if(0xFFFFU == linkAddr)
        {
            pParamConfig->enableLink = FALSE;
        }
        else if((linkAddr < EDMA_TPCC_PARAM(maxPaRamSet))
            && (0U == ((linkAddr - (uint32_t)0x4000U) % (0x20U))))
        {
            pParamConfig->enableLink = TRUE;
            pParamConfig->linkAddr = ((linkAddr - (uint32_t)0x4000U) / (0x20U));
        }
        else
        {
            pParamConfig->enableLink = FALSE;
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        pSrc->addrMode = HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_SRC_ADDR_MODE);
        pSrc->addrOff.addr = paramset.word2;
        pSrc->addrOff.bCntIdx = HW_GET_FIELD(paramset.word5,
            EDMA_PARAM_SRC_BIDX);
        pSrc->addrOff.cCntIdx = HW_GET_FIELD(paramset.word7,
            EDMA_PARAM_SRC_CIDX);
        pSrc->size.aCnt = HW_GET_FIELD(paramset.word3,
            EDMA_PARAM_A_CNT);
        pSrc->size.bCnt = HW_GET_FIELD(paramset.word3,
            EDMA_PARAM_B_CNT);
        pSrc->size.cCnt = HW_GET_FIELD(paramset.word8,
            EDMA_PARAM_C_CNT);
        pSrc->syncType = HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_SYNC_DIM);
        pSrc->size.bCntRld = HW_GET_FIELD(paramset.word6,
            EDMA_PARAM_BCNT_RLD);
        pDst->addrMode = HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_DST_ADDR_MODE);
        pDst->addrOff.addr = paramset.word4;
        pDst->addrOff.bCntIdx = HW_GET_FIELD(paramset.word5,
            EDMA_PARAM_DST_BIDX);
        pDst->addrOff.cCntIdx = HW_GET_FIELD(paramset.word7,
            EDMA_PARAM_DST_CIDX);
        pParamConfig->tccMode = HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_TCC_MODE);
        pParamConfig->tcc = HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_TCC);

        if(pParamConfig->tcc >= maxIntrCh)
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        if(EDMA_PARAM_OPT_STATIC_ENABLE == HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_STATIC))
        {
            pParamConfig->enableStatic = TRUE;
        }
        else
        {
            pParamConfig->enableStatic = FALSE;
        }

        if(EDMA_PARAM_OPT_PRIV_USER == HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_PRIV))
        {
            pParamConfig->privType = EDMA_PARAM_PRIV_LVL_USER;
        }
        else
        {
            pParamConfig->privType = EDMA_PARAM_PRIV_LVL_SUPERVISOR;
        }

        pParamConfig->privId = HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_PRIV_ID);

        if(EDMA_PARAM_OPT_ITC_INT_EN_ENABLE == HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_ITC_INT_EN))
        {
            pParamConfig->chainMask |= EDMA_PARAM_XFER_TRIGGER_MASK_INTERMEDIATE;
            pParamConfig->enableChain = TRUE;
        }
        else
        {
            pParamConfig->chainMask &= ~EDMA_PARAM_XFER_TRIGGER_MASK_INTERMEDIATE;
            pParamConfig->enableChain = FALSE;
        }

        if(EDMA_PARAM_OPT_TC_INT_EN_ENABLE == HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_TC_INT_EN))
        {
            pParamConfig->chainMask |= EDMA_PARAM_XFER_TRIGGER_MASK_COMPLETE;
            pParamConfig->enableChain = TRUE;
        }
        else
        {
            pParamConfig->chainMask &= ~EDMA_PARAM_XFER_TRIGGER_MASK_COMPLETE;
        }

        if(EDMA_PARAM_OPT_ITC_INT_EN_ENABLE == HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_ITC_INT_EN))
        {
            pParamConfig->intrMask |= EDMA_PARAM_XFER_TRIGGER_MASK_INTERMEDIATE;
        }
        else
        {
            pParamConfig->intrMask &= ~EDMA_PARAM_XFER_TRIGGER_MASK_INTERMEDIATE;
        }

        if(EDMA_PARAM_OPT_TC_INT_EN_ENABLE == HW_GET_FIELD(paramset.word1,
            EDMA_PARAM_OPT_TC_INT_EN))
        {
            pParamConfig->intrMask |= EDMA_PARAM_XFER_TRIGGER_MASK_COMPLETE;
        }
        else
        {
            pParamConfig->intrMask &= ~EDMA_PARAM_XFER_TRIGGER_MASK_COMPLETE;
        }
    }

    return retVal;
}

uint32_t EDMAChConfig(uint32_t baseAddr,
                      uint32_t chType,
                      uint32_t chNum,
                      EDMAChConfig_t* pChConfig)
{
    int32_t retVal = E_FAIL;
    uint32_t idx = 0U;
    uint32_t maxNumReg = EDMAGetNumRegions(baseAddr);

    if(NULL != pChConfig)
    {
        if (pChConfig->region < maxNumReg)
        {
            retVal = S_PASS;
        }
    }

    if(S_PASS == retVal)
    {
        for(idx = 0U; idx < maxNumReg; idx++)
        {
            if(TRUE == EDMAIsChInShdwRegion(baseAddr, idx, chType,
                chNum))
            {
                if(pChConfig->region != idx)
                {
                    retVal = E_FAIL;
                }
                break;
            }
        }
    }

    if(S_PASS == retVal)
    {
        retVal = EDMAShdwRegionChEnable(baseAddr, pChConfig->region, chType,
            chNum);
    }

    if(S_PASS == retVal)
    {
        retVal = EDMAChToParamSetMap(baseAddr, chType, chNum,
            pChConfig->paramIdx);
    }

    if(S_PASS == retVal)
    {
        retVal = EDMAChToEvtQueueMap(baseAddr, chType, chNum,
            pChConfig->queueNum);
    }

    if(S_PASS == retVal)
    {
        if(TRUE == pChConfig->enableEvt)
        {
            retVal = EDMAEvtEnable(baseAddr, pChConfig->region, chType, chNum);
        }
        else
        {
            retVal = EDMAEvtDisable(baseAddr, pChConfig->region, chType, chNum);
        }
    }

    if(S_PASS == retVal)
    {
        if(TRUE == pChConfig->enableIntr)
        {
            retVal = EDMAIntrEnable(baseAddr, pChConfig->region, chNum);
        }
        else
        {
            retVal = EDMAIntrDisable(baseAddr, pChConfig->region, chNum);
        }
    }
    return retVal;
}

uint32_t  EDMAChReset(uint32_t baseAddr,
                      uint32_t region,
                      uint32_t chType,
                      uint32_t chNum)
{
    int32_t retVal = E_FAIL;
    uint32_t idx = 0U;
    uint32_t maxNumReg = EDMAGetNumRegions(baseAddr);

    if (region < maxNumReg)
    {
        retVal = S_PASS;
        for(idx = 0U; idx < maxNumReg; idx++)
        {
            if(TRUE == EDMAIsChInShdwRegion(baseAddr, idx, chType, chNum))
            {
                if(region != idx)
                {
                    retVal = E_FAIL;
                }
                break;
            }
        }
    }

    if(S_PASS == retVal)
    {
        retVal = EDMAEvtDisable(baseAddr, region, chType, chNum);
    }

    if(S_PASS == retVal)
    {
        retVal = EDMAIntrDisable(baseAddr, region, chNum);
    }

    if(S_PASS == retVal)
    {
        retVal = EDMAShdwRegionChDisable(baseAddr, region, chType, chNum);
    }

    if(S_PASS == retVal)
    {
        retVal = EDMAChToParamSetMap(baseAddr, chType, chNum, 0U);
    }

    if(S_PASS == retVal)
    {
        retVal = EDMAChToEvtQueueMap(baseAddr, chType, chNum, 0U);
    }

    return retVal;
}

int32_t EDMATransferStart(uint32_t baseAddr,
                           uint32_t region,
                           uint32_t chNum,
                           uint32_t triggerMode)
{
    int32_t retVal = E_FAIL;
    uint32_t maxNumReg = EDMAGetNumRegions(baseAddr);

    if (region < maxNumReg)
    {
        retVal = S_PASS;
        switch (triggerMode)
        {
            case DMA_XFER_TRIGGER_TYPE_MANUAL:
                if (chNum < EDMAGetNumDmaCh(baseAddr))
                {
                    EDMASetEvt(baseAddr, region, chNum);
                }
            break;

            case DMA_XFER_TRIGGER_TYPE_AUTO:
                if (chNum < EDMAGetNumQdmaCh(baseAddr))
                {
                    EDMAEvtEnable(baseAddr, region, EDMA_CH_TYPE_QDMA, chNum);
                }
            break;

            case DMA_XFER_TRIGGER_TYPE_EVENT:
                if (chNum < EDMAGetNumDmaCh(baseAddr))
                {
                    /* Clear SECR & EMCR to clean any previous NULL request. */
                    EDMAChMissEvtClear(baseAddr, region, EDMA_CH_TYPE_DMA, chNum);
                    /* Set EESR to enable event. */
                    EDMAEvtEnable(baseAddr, region, EDMA_CH_TYPE_DMA, chNum);
                }
            break;

            default :
                retVal = E_FAIL;
            break;
        }
    }
    return retVal;
}

int32_t EDMATransferStop(uint32_t baseAddr,
                          uint32_t region,
                          uint32_t chNum,
                          uint32_t triggerMode)
{
    int32_t retVal = E_FAIL;
    uint32_t maxNumReg = EDMAGetNumRegions(baseAddr);

    if (region < maxNumReg)
    {
        switch (triggerMode)
        {
            case DMA_XFER_TRIGGER_TYPE_MANUAL:
                if (chNum < EDMAGetNumDmaCh(baseAddr))
                {
                    EDMAEvtClear(baseAddr, region, chNum);
                    retVal = S_PASS;
                }
            break;

            case DMA_XFER_TRIGGER_TYPE_AUTO:
                if (chNum < EDMAGetNumQdmaCh(baseAddr))
                {
                    EDMAEvtDisable(baseAddr, region, EDMA_CH_TYPE_QDMA, chNum);
                    retVal = S_PASS;
                }
            break;

            case DMA_XFER_TRIGGER_TYPE_EVENT:
                if (chNum < EDMAGetNumDmaCh(baseAddr))
                {
                    /* Clear SECR & EMCR to clean any previous NULL request. */
                    EDMAChMissEvtClear(baseAddr, region, EDMA_CH_TYPE_DMA, chNum);
                    /* Set EESR to enable event. */
                    EDMAEvtDisable(baseAddr, region, EDMA_CH_TYPE_DMA, chNum);
                    retVal = S_PASS;
                }
            break;

            default :
                retVal = E_FAIL;
            break;
        }
    }
    return retVal;
}

/* ========================================================================== */
/*                   Deprecated Function Definitions                          */
/* ========================================================================== */
