/**
 *  \file  dma_utils.c
 *
 *  \brief  This file contain functions which configure and execute transfers
 *         with DMA.
 *
 *  \details  Please find the below detailed description of DMA utils.
 *            -# Programming sequence for DMA transfer configuration
 *               -# #DMAUtilsInit initializes DMA controller.
 *               -# To perform basic DMA transfer following sequence to be followed
 *                  -# #DMAUtilsDataXferReset to reset transfer configuration.
 *                  -# #DMAUtilsDataXferConfig to per data transfer configuration.
 *                  -# #DMAUtilsLinkXferConfig to reconfigure the link transfer.
 *                  -# #DMAUtilsChConfig to per DMA channel configuration.
 *                  -# #DMAUtilsXferStart to start transfer on the DMA channel.
 *                  -# #DMAUtilsXferStop to start transfer on the DMA channel.
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

#include <types.h>
#include "error.h"
#include "chipdb.h"
#include "soc.h"
#include "dma.h"
#include "uart.h"
#include "dma_utils_types.h"
#include "dma_utils.h"
#include "edma_utils.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define MAX_INST (2U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

static void DMAUtilsMemCopyCallBack(uint32_t chNum, uint32_t xferStatus);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief DMA default data configuration */
static const dmaUtilsDataObj_t DMA_UTILS_DATA_DEFAULT =
{
    0U,                                        /* addr */
    DMA_XFER_DATA_ADDR_MODE_INC,               /* addrMode */
    0U,                                        /* fifoWidth */
    1U,                                        /* packetActSize */
    1U,                                        /* frameActSize */
    1U,                                        /* blockSize */
    0U,                                        /* packetInactSize */
    0U,                                        /* frameInactSize */
    DMA_UTILS_DATA_SYNC_BLOCK                  /* syncMode */
}; /* dmaUtilsDataObj_t */

/** \brief DMA default transfer configuration. */
static const dmaUtilsXferObj_t DMA_UTILS_XFER_DEFAULT =
{
    NULL,                                      /* pSrc */
    NULL,                                      /* pDest */
    DMA_UTILS_DATA_SYNC_MASK_NONE,             /* intrConfig */
    FALSE,                                     /* linkEnable */
    0U                                         /* nxtXferIdx */
}; /* dmaUtilsXferObj_t */

/** \brief DMA default channel configuration. */
static const dmaUtilsChObj_t DMA_UTILS_CH_DEFAULT =
{
    DMA_XFER_TRIGGER_TYPE_MANUAL,              /* triggerType */
    0U,                                        /* xferIdx */
    FALSE,                                     /* intrEnable */
    NULL,                                      /* callBack */
    0U                                         /* queueNum */
}; /* dmaUtilsChObj_t */

/** \brief Global status for UART DMA action status. */
volatile uint32_t gDMAUtilsMemCopyStatus = FALSE;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t DMAUtilsInit(uint32_t dmaType,
                     uint32_t instNum,
                     dmaUtilsInitParams_t *pInitParams)
{
    int32_t retStat = E_FAIL;

    switch(dmaType)
    {
        case DMA_TYPE_ENHACED:
            retStat = EDMAUtilsInit(instNum, pInitParams);
            break;

        default:
            break;
    }

    return retStat;
}

int32_t DMAUtilsReset(uint32_t dmaType,
                      uint32_t instNum)
{
    int32_t retStat = E_FAIL;

    switch(dmaType)
    {
        case DMA_TYPE_ENHACED:
            retStat = EDMAUtilsReset(instNum);
            break;

        default:
            break;
    }

    return retStat;
}

int32_t DMAUtilsDataXferConfig(uint32_t dmaType,
                               uint32_t instNum,
                               uint32_t xferIdx,
                               dmaUtilsXferObj_t *pDmaXferConfig)
{
    int32_t retStat = E_FAIL;

    switch(dmaType)
    {
        case DMA_TYPE_ENHACED:
            retStat = EDMAUtilsDataXferConfig(instNum, xferIdx, pDmaXferConfig);
            break;

        default:
            break;
    }

    return retStat;
}

int32_t DMAUtilsDataXferReset(uint32_t dmaType,
                              uint32_t instNum,
                              uint32_t xferIdx)
{
    int32_t retStat = E_FAIL;

    switch(dmaType)
    {
        case DMA_TYPE_ENHACED:
            retStat = EDMAUtilsDataXferReset(instNum, xferIdx);
            break;

        default:
            break;
    }

    return retStat;
}

int32_t DMAUtilsChConfig(uint32_t dmaType,
                         uint32_t instNum,
                         uint32_t chNum,
                         dmaUtilsChObj_t *pDmaChObj)
{
    int32_t retStat = E_FAIL;

    switch(dmaType)
    {
        case DMA_TYPE_ENHACED:
            retStat = EDMAUtilsChConfig(instNum, chNum, pDmaChObj);
            break;

        default:
            break;
    }

    return retStat;
}

int32_t DMAUtilsXferStart(uint32_t dmaType,
                          uint32_t instNum,
                          uint32_t chNum,
                          uint32_t triggerType)
{
    int32_t retStat = E_FAIL;

    switch(dmaType)
    {
        case DMA_TYPE_ENHACED:
            retStat = EDMAUtilsXferStart(instNum, chNum, triggerType);
            break;

        default:
            break;
    }

    return retStat;
}

int32_t DMAUtilsXferStop(uint32_t dmaType,
                         uint32_t instNum,
                         uint32_t chNum,
                         uint32_t triggerType)
{
    int32_t retStat = E_FAIL;

    switch(dmaType)
    {
        case DMA_TYPE_ENHACED:
            retStat = EDMAUtilsXferStop(instNum, chNum, triggerType);
            break;

        default:
            break;
    }

    return retStat;
}

int32_t DMAUtilsMemCopy(uint32_t dmaType,
                        uint32_t instNum,
                        uint8_t *pSrcBuf,
                        uint8_t *pDstBuf,
                        uint32_t noOfBytes)
{
    int32_t retStat = E_FAIL;
    uint32_t xferIdx = 0U;
    uint32_t chNum = 0U;
    dmaUtilsDataObj_t srcDataObj = DMA_UTILS_DATA_DEFAULT;
    dmaUtilsDataObj_t dstDataObj = DMA_UTILS_DATA_DEFAULT;
    dmaUtilsXferObj_t xferObj = DMA_UTILS_XFER_DEFAULT;
    dmaUtilsChObj_t chObj = DMA_UTILS_CH_DEFAULT;

    if((NULL != pSrcBuf) && (NULL != pDstBuf))
    {
        retStat = S_PASS;
        gDMAUtilsMemCopyStatus = FALSE;
    }

    if(S_PASS == retStat)
    {
        xferObj.pSrc = &srcDataObj;
        xferObj.pDst = &dstDataObj;

        xferObj.pSrc->addr = (uint32_t)pSrcBuf;
        xferObj.pSrc->packetActSize = noOfBytes;
        xferObj.pSrc->frameActSize = 1U;
        xferObj.pSrc->blockSize = 1U;
        xferObj.pSrc->addrMode = DMA_XFER_DATA_ADDR_MODE_INC;
        xferObj.pSrc->syncMode = DMA_UTILS_DATA_SYNC_BLOCK;

        xferObj.pDst->addr = (uint32_t)pDstBuf;
        xferObj.pDst->packetActSize = 1U;
        xferObj.pDst->frameActSize = 1U;
        xferObj.pDst->blockSize = 1U;
        xferObj.pDst->addrMode = DMA_XFER_DATA_ADDR_MODE_INC;
        xferObj.pDst->syncMode = DMA_UTILS_DATA_SYNC_BLOCK;

        xferObj.intrConfig = DMA_UTILS_DATA_SYNC_MASK_BLOCK;
        xferObj.linkEnable = TRUE;
        xferObj.nxtXferIdx = 0U;

        retStat = DMAUtilsDataXferConfig(dmaType, instNum, xferIdx, &xferObj);
    }

    if(S_PASS == retStat)
    {
        chObj.xferIdx = xferIdx;
        chObj.queueNum = 0U;
        chObj.intrEnable = TRUE;
        chObj.triggerType = DMA_XFER_TRIGGER_TYPE_MANUAL;
        chObj.callBack = &DMAUtilsMemCopyCallBack;

        retStat = DMAUtilsChConfig(dmaType, instNum, chNum, &chObj);
    }

    if(S_PASS == retStat)
    {
        retStat = DMAUtilsXferStart(dmaType, instNum, chNum, chObj.triggerType);
    }

    return retStat;
}

uint32_t DMAUtilsMemCopyStatus(void)
{
    return gDMAUtilsMemCopyStatus;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void DMAUtilsMemCopyCallBack(uint32_t chNum, uint32_t xferStatus)
{
    gDMAUtilsMemCopyStatus = TRUE;
}

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
