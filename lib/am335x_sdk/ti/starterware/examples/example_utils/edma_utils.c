/**
 *  \file  edma_utils.c
 *
 * \brief  This file contain functions which configure and execute transfers
 *         with EDMA.
 *
 *  \copyright Copyright (C) 2013-2018 Texas Instruments Incorporated -
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
#include "interrupt.h"
#include "prcm.h"
#include "dma.h"
#include "edma.h"
#include "console_utils.h"
#include "dma_utils_types.h"
#include "edma_utils.h"

#ifdef RTOS_BUILD
#include <ti/osal/RegisterIntr.h>
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Maximum number of EDMA instance supported. */
#define EDMA_UTILS_INSTANCE_MAX                                   (1U)

/** \brief Maximum number of EDMA channel supported. */
#define EDMA_UTILS_CHANNEL_MAX                                    (64U)

/** \brief Retry count to process EDMA handler. */
#define EDMA_UTILS_HANDLER_RETRY_COUNT                            (10U)

/** \brief Interrupt mapping for AM43XX */
/* TODO: Remove these macros and use chipdb API's. */
#if defined(AM43XX_FAMILY_BUILD)
    #define SYS_INT_EDMACOMPINT               (32U + 12U)
    #define SYS_INT_EDMAMPERR                 (32U + 13U)
    #define SYS_INT_EDMAERRINT                (32U + 14U)
#else /* if defined(AM43XX_FAMILY_BUILD) */
    #define SYS_INT_EDMACOMPINT               (12U)
    #define SYS_INT_EDMAMPERR                 (13U)
    #define SYS_INT_EDMAERRINT                (14U)
#endif /* if defined(AM43XX_FAMILY_BUILD) */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

static int32_t EdmaUtilsGetSocInfo(uint32_t instNum);

static int32_t EDMAUtilsModuleInit(uint32_t instNum);

static int32_t EDMAUtilsCtrlInit(uint32_t instNum);

/**
 *  \brief   A Interrupt Service routine which is invoked when the EDMA completion
 *           interrupt is raised on any channel. The ISR invokes the callback
 *           function assigned to the channel.
 *
 *  \param   intrNum    interrupt number to which the interrupt event is mapped.
 *  \param   cpuId      id of the CPU to which interrupt is raised.
 *  \param   userParam  parameter to be passed to the ISR.
 */
#ifdef RTOS_BUILD
static void EdmaChCompletionIsr(void* pUserParam);
#else
static void EdmaChCompletionIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);
#endif

/**
 *  \brief   A Interrupt Service routine which is invoked when the EDMA error
 *           interrupt is raised on any channel. The ISR invokes the callback
 *           function assigned to the channel.
 *
 *  \param   intrNum    interrupt number to which the interrupt event is mapped.
 *  \param   cpuId      id of the CPU to which interrupt is raised.
 *  \param   userParam  parameter to be passed to the ISR.
 */
#ifdef RTOS_BUILD
static void EdmaChErrorIsr(void* pUserParam);
#else
static void EdmaChErrorIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);
#endif

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief  EDMA Object array for Max number of instances. */
edmaUtilsObj_t gEdmaUtilsObj[EDMA_UTILS_INSTANCE_MAX];

/** \brief EDMA default data configuration */
static const EDMAParamDataConfig_t EDMA_DATA_DEFAULT =
{
    DMA_XFER_DATA_ADDR_MODE_INC,            /* addrMode */
    DMA_XFER_DATA_FIFO_WIDTH_MIN,              /* fifoWidth */
    {
        0U,                                 /* addr */
        0U,                                 /* bCntIdx */
        0U,                                 /* cCntIdx */
    }, /* EDMAParamDataAddrOff_t */
    {
        0U,                                 /* aCnt */
        0U,                                 /* bCnt */
        0U,                                 /* cCnt */
        0U,                                 /* bCntRld */
    }, /* EDMAParamDataSize_t */
    EDMA_PARAM_SYNC_TYPE_A                  /* syncType */
}; /* EDMAParamDataConfig_t */

/** \brief EDMA default configuration */
static const EDMAParamConfig_t EDMA_XFER_DEFAULT =
{
    NULL,                                   /* pSrc */
    NULL,                                   /* pDst */
    EDMA_PARAM_PRIV_LVL_USER,               /* privType */
    0U,                                     /* privId */
    FALSE,                                  /* enableLink */
    FALSE,                                  /* enableStatic */
    0xFFFFU,                                /* linkAddr */
    FALSE,                                  /* enableChain */
    EDMA_PARAM_XFER_TRIGGER_MASK_NONE,      /* chainMask */
    EDMA_PARAM_TCC_MODE_NORMAL,             /* tccMode */
    0U,                                     /* tcc */
    EDMA_PARAM_TCC_MODE_NORMAL              /* intrMask */
}; /* EDMAParamConfig_t */

/** \brief EDMA default configuration */
static const EDMAChConfig_t EDMA_CH_DEFAULT =
{
    0U,                                     /* regionId */
    0U,                                     /* paRamEntry */
    0U,                                     /* queueNum */
    FALSE,                                  /* enableEvt */
    FALSE                                   /* enableIntr */
}; /* EDMAChConfig_t */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t EDMAUtilsInit(uint32_t instNum,
                      dmaUtilsInitParams_t *pInitParams)
{
    int32_t retStat = S_PASS;

    /* Update SoC info */
    retStat = EdmaUtilsGetSocInfo(instNum);

    if(S_PASS == retStat)
    {
        /* EDMA clock configuration */
        retStat = EDMAUtilsModuleInit(instNum);

        if(S_PASS != retStat)
        {
            CONSOLEUtilsPrintf("Initialization failed!!\n");
        }
        else
        {
            retStat = EDMAUtilsCtrlInit(instNum);

            if( S_PASS != retStat)
            {
                CONSOLEUtilsPrintf("Controller Initialization failed %d\r\n"
                                    ,retStat);
            }
        }
    }

    return retStat;
}

int32_t EDMAUtilsReset(uint32_t instNum)
{
    int32_t retStat = S_PASS;
    edmaUtilsObj_t *pEdmaObj = &gEdmaUtilsObj[instNum];

    EDMARegionReset(pEdmaObj->baseChCtrlAddr, pEdmaObj->region);

    return retStat;
}

int32_t EDMAUtilsDataXferReset(uint32_t instNum, uint32_t xferIdx)
{
    int32_t retStat = S_PASS;
    edmaUtilsObj_t *pEdmaObj = &gEdmaUtilsObj[instNum];

    EDMAParamReset(pEdmaObj->baseChCtrlAddr, xferIdx);

    return retStat;
}

int32_t EDMAUtilsDataXferConfig(uint32_t instNum,
                                uint32_t xferIdx,
                                dmaUtilsXferObj_t *pDmaXferConfig)
{
    int32_t retStat = E_FAIL;
    edmaUtilsObj_t *pEdmaObj = &gEdmaUtilsObj[instNum];
    EDMAParamDataConfig_t srcData = EDMA_DATA_DEFAULT;
    EDMAParamDataConfig_t dstData = EDMA_DATA_DEFAULT;
    EDMAParamConfig_t xferData = EDMA_XFER_DEFAULT;

    if(NULL != pDmaXferConfig)
    {
        if(NULL != pDmaXferConfig->pSrc)
        {
            if(NULL != pDmaXferConfig->pDst)
            {
                retStat = S_PASS;
            }
        }
    }

    if(S_PASS == retStat)
    {
        /* Configure interrupt mask. */
        if(0U != (pDmaXferConfig->intrConfig & DMA_UTILS_DATA_SYNC_MASK_BLOCK))
        {
            xferData.intrMask |= EDMA_PARAM_XFER_TRIGGER_MASK_COMPLETE;
        }

        if((0U != (pDmaXferConfig->intrConfig & DMA_UTILS_DATA_SYNC_MASK_PACKET)) &&
            (EDMA_PARAM_SYNC_TYPE_A == srcData.syncType))
        {
            xferData.intrMask |= EDMA_PARAM_XFER_TRIGGER_MASK_INTERMEDIATE;
        }
        else if((0U != (pDmaXferConfig->intrConfig & DMA_UTILS_DATA_SYNC_MASK_FRAME)) &&
            (EDMA_PARAM_SYNC_TYPE_AB == srcData.syncType))
        {
            xferData.intrMask |= EDMA_PARAM_XFER_TRIGGER_MASK_INTERMEDIATE;
        }
        else
        {
        }
    }

    if(S_PASS == retStat)
    {
        if(TRUE == pDmaXferConfig->linkEnable)
        {
            xferData.linkAddr = pDmaXferConfig->nxtXferIdx;
        }
        else
        {
            xferData.linkAddr = 0xFFFF;
        }
    }

    if(S_PASS == retStat)
    {
        srcData.addrOff.addr = pDmaXferConfig->pSrc->addr;
        srcData.fifoWidth = pDmaXferConfig->pSrc->fifoWidth;

        if((0U == pDmaXferConfig->pSrc->packetActSize) ||
            (0U == pDmaXferConfig->pSrc->frameActSize) ||
            (0U == pDmaXferConfig->pSrc->blockSize))
        {
            retStat = E_FAIL;
        }
        else
        {
            srcData.size.aCnt = pDmaXferConfig->pSrc->packetActSize;
            srcData.size.bCnt = pDmaXferConfig->pSrc->frameActSize;
            srcData.size.cCnt = pDmaXferConfig->pSrc->blockSize;
        }

        if(S_PASS == retStat)
        {
            if(DMA_XFER_DATA_ADDR_MODE_INC == pDmaXferConfig->pSrc->addrMode)
            {
                srcData.addrMode = DMA_XFER_DATA_ADDR_MODE_INC;
            }
            else if(DMA_XFER_DATA_ADDR_MODE_CONST == pDmaXferConfig->pSrc->addrMode)
            {
                srcData.addrMode = DMA_XFER_DATA_ADDR_MODE_CONST;
            }
            else
            {
                retStat = E_FAIL;
            }
        }

        if(S_PASS == retStat)
        {
            if(DMA_UTILS_DATA_SYNC_PACKET == pDmaXferConfig->pSrc->syncMode)
            {
                srcData.syncType = EDMA_PARAM_SYNC_TYPE_A;
            }
            else if(DMA_UTILS_DATA_SYNC_FRAME == pDmaXferConfig->pSrc->syncMode)
            {
                srcData.syncType = EDMA_PARAM_SYNC_TYPE_AB;
            }
            else if(DMA_UTILS_DATA_SYNC_BLOCK == pDmaXferConfig->pSrc->syncMode)
            {
                srcData.syncType = EDMA_PARAM_SYNC_TYPE_A;
            }
            else
            {
                retStat = E_FAIL;
            }
        }

        if(S_PASS == retStat)
        {
            if((1U == pDmaXferConfig->pSrc->frameActSize) &&
                (1U == pDmaXferConfig->pSrc->blockSize))
            {
                srcData.addrOff.bCntIdx = 0U;
                srcData.addrOff.cCntIdx = 0U;
            }
            else if(1U == pDmaXferConfig->pSrc->blockSize)
            {
                srcData.addrOff.cCntIdx = 0U;
                srcData.addrOff.bCntIdx = pDmaXferConfig->pSrc->packetActSize;
            }
            else
            {
                srcData.addrOff.cCntIdx = pDmaXferConfig->pSrc->frameActSize;
                srcData.addrOff.bCntIdx = pDmaXferConfig->pSrc->packetActSize;
            }
        }

        if(S_PASS == retStat)
        {
            dstData.addrOff.addr = pDmaXferConfig->pDst->addr;

            if(DMA_XFER_DATA_ADDR_MODE_INC == pDmaXferConfig->pDst->addrMode)
            {
                dstData.addrMode = DMA_XFER_DATA_ADDR_MODE_INC;
            }
            else if(DMA_XFER_DATA_ADDR_MODE_CONST == pDmaXferConfig->pDst->addrMode)
            {
                dstData.addrMode = DMA_XFER_DATA_ADDR_MODE_CONST;
            }
            else
            {
                retStat = E_FAIL;
            }
        }

        if(S_PASS == retStat)
        {
            if((1U == pDmaXferConfig->pDst->frameActSize) &&
                (1U == pDmaXferConfig->pDst->blockSize))
            {
                dstData.addrOff.bCntIdx = 0U;
                dstData.addrOff.cCntIdx = 0U;
            }
            else if(1U == pDmaXferConfig->pDst->blockSize)
            {
                dstData.addrOff.cCntIdx = 0U;
                dstData.addrOff.bCntIdx = pDmaXferConfig->pDst->packetActSize;
            }
            else
            {
                dstData.addrOff.cCntIdx = pDmaXferConfig->pDst->frameActSize;
                dstData.addrOff.bCntIdx = pDmaXferConfig->pDst->packetActSize;
            }
        }
    }

    if(S_PASS == retStat)
    {
        xferData.pSrc = &srcData;
        xferData.pDst = &dstData;
        retStat = EDMAParamConfig(pEdmaObj->baseChCtrlAddr, xferIdx, &xferData);
    }

    return retStat;
}

int32_t EDMAUtilsChConfig(uint32_t instNum,
                          uint32_t chNum,
                          dmaUtilsChObj_t *pDmaChObj)
{
    int32_t retStat = E_FAIL;
    edmaUtilsObj_t *pEdmaObj = &gEdmaUtilsObj[instNum];
    EDMAChConfig_t chConfig = EDMA_CH_DEFAULT;
    uint32_t chType = EDMA_CH_TYPE_DMA;
    EDMAParamDataConfig_t srcData = EDMA_DATA_DEFAULT;
    EDMAParamDataConfig_t dstData = EDMA_DATA_DEFAULT;
    EDMAParamConfig_t xferData = EDMA_XFER_DEFAULT;

    /*  Resets the channel before it is configured for a transfer. */
    retStat = EDMAChReset(pEdmaObj->baseChCtrlAddr, pEdmaObj->region, chType,
                chNum);

    if(retStat != E_FAIL)
    {
        if(NULL != pDmaChObj)
        {
            xferData.pSrc = &srcData;
            xferData.pDst = &dstData;
            retStat = EDMAGetParamConfig(pEdmaObj->baseChCtrlAddr, pDmaChObj->xferIdx, &xferData);
        }

        if(S_PASS == retStat)
        {
            do
            {
                if((EDMA_PARAM_XFER_TRIGGER_MASK_INTERMEDIATE == xferData.intrMask)
                    || (EDMA_PARAM_XFER_TRIGGER_MASK_COMPLETE == xferData.intrMask))
                {
                    xferData.tcc = chNum;
                    retStat = EDMAParamIntrConfig(pEdmaObj->baseChCtrlAddr, pDmaChObj->xferIdx, &xferData);
                }

                if(S_PASS == retStat)
                {
                    if(TRUE == xferData.enableLink)
                    {
                        retStat = EDMAGetParamConfig(pEdmaObj->baseChCtrlAddr, pDmaChObj->xferIdx, &xferData);
                    }
                }
            } while((S_PASS == retStat) && (TRUE == xferData.enableLink));
        }

        if(S_PASS == retStat)
        {
            chConfig.region = pEdmaObj->region;
            chConfig.paramIdx = pDmaChObj->xferIdx;
            chConfig.queueNum = pDmaChObj->queueNum;
            chConfig.enableEvt = FALSE;
            chConfig.enableIntr = pDmaChObj->intrEnable;
            pEdmaObj->pFnCallBack[chNum] = pDmaChObj->callBack;

            if((DMA_XFER_TRIGGER_TYPE_MANUAL == pDmaChObj->triggerType) ||
                (DMA_XFER_TRIGGER_TYPE_EVENT == pDmaChObj->triggerType))
            {
                chType = EDMA_CH_TYPE_DMA;
            }
            else if(DMA_XFER_TRIGGER_TYPE_AUTO == pDmaChObj->triggerType)
            {
                chType = EDMA_CH_TYPE_QDMA;
            }
            else
            {
                retStat = E_FAIL;
            }
        }

        if(S_PASS == retStat)
        {
            retStat = EDMAChConfig(pEdmaObj->baseChCtrlAddr, chType, chNum, &chConfig);
        }
    }

    return retStat;
}

int32_t EDMAUtilsXferStart(uint32_t instNum,
                           uint32_t chNum,
                           uint32_t triggerType)
{
    int32_t retStat = E_FAIL;
    edmaUtilsObj_t *pEdmaObj = &gEdmaUtilsObj[instNum];

    retStat = EDMATransferStart(pEdmaObj->baseChCtrlAddr, pEdmaObj->region, chNum, triggerType);

    return retStat;
}

int32_t EDMAUtilsXferStop(uint32_t instNum,
                          uint32_t chNum,
                          uint32_t triggerType)
{
    int32_t retStat = E_FAIL;
    edmaUtilsObj_t *pEdmaObj = &gEdmaUtilsObj[instNum];

    retStat = EDMATransferStop(pEdmaObj->baseChCtrlAddr, pEdmaObj->region, chNum, triggerType);

    return retStat;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t EdmaUtilsGetSocInfo(uint32_t instNum)
{
    int32_t status = S_PASS;
    edmaUtilsObj_t *pEdmaObj = &gEdmaUtilsObj[instNum];

    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_EDMA3CC, instNum))
    {
        pEdmaObj->baseChCtrlAddr =
            CHIPDBBaseAddress(CHIPDB_MOD_ID_EDMA3CC, instNum);
        pEdmaObj->region = 0U;
        pEdmaObj->intrCfg.complIntrLine = SYS_INT_EDMACOMPINT;
        pEdmaObj->intrCfg.errorIntrLine = SYS_INT_EDMAERRINT;
        /* TODO: Need to update the interrupt Number data base of ChipDB */
    }
    else
    {
        status = E_FAIL;
    }

    return status;
}

static int32_t EDMAUtilsModuleInit(uint32_t instNum)
{
    int32_t retStat = S_PASS;

    /* Clock Configuration  */
    retStat = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3CC, instNum, 0U);
    retStat = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3TC, 0U, 0U);
    retStat = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3TC, 1U, 0U);
    retStat = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3TC, 2U, 0U);

    return retStat;
}

static int32_t EDMAUtilsIntcConfigure(uint32_t instNum)
{
    int32_t retStat = S_PASS;
#ifndef RTOS_BUILD
    intcIntrParams_t *pIntrParams = NULL;
#endif
    edmaUtilsObj_t *pEdmaObj = &gEdmaUtilsObj[instNum];

    /* Initialize the Interrupt Controller. */
#ifdef RTOS_BUILD
    OsalRegisterIntrParams_t intrRegParams1;
    HwiP_Handle hwiPHandlePtr1;
    OsalRegisterIntrParams_t intrRegParams2;
    HwiP_Handle hwiPHandlePtr2;

    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&intrRegParams1);

    /* Populate the interrupt parameters */
    intrRegParams1.corepacConfig.arg                = (uintptr_t) pEdmaObj;
    intrRegParams1.corepacConfig.name               = "hwi1";
    intrRegParams1.corepacConfig.isrRoutine         = (void *)EdmaChCompletionIsr;
    intrRegParams1.corepacConfig.priority           = 0x10;
    intrRegParams1.corepacConfig.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    intrRegParams1.corepacConfig.intVecNum          = pEdmaObj->intrCfg.complIntrLine;

    /* Register interrupts */
    Osal_RegisterInterrupt(&intrRegParams1, &hwiPHandlePtr1);
    if(S_PASS == retStat)
    {
        /* Initialize with defaults */
        Osal_RegisterInterrupt_initParams(&intrRegParams2);

        /* Populate the interrupt parameters */
        intrRegParams2.corepacConfig.arg                = (uintptr_t) pEdmaObj;
        intrRegParams2.corepacConfig.name               = "hwi2";
        intrRegParams2.corepacConfig.isrRoutine         = (void *)EdmaChErrorIsr;
        intrRegParams2.corepacConfig.priority           = 0x10;
        intrRegParams2.corepacConfig.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
        intrRegParams2.corepacConfig.intVecNum          = pEdmaObj->intrCfg.errorIntrLine;
        /* Register interrupts */
        Osal_RegisterInterrupt(&intrRegParams2, &hwiPHandlePtr2);
    }
#else
    INTCInit(FALSE);

    /* Configure edma completion interrupt */
    pIntrParams = &(pEdmaObj->intrCfg.complIntrParams);
    pIntrParams->triggerType    = INTC_TRIG_HIGH_LEVEL;
    pIntrParams->priority       = 0x10;
    pIntrParams->pFnIntrHandler = EdmaChCompletionIsr;
    pIntrParams->pUserParam     = (void*)pEdmaObj;
    pIntrParams->isIntrSecure   = FALSE;

    retStat = INTCConfigIntr(pEdmaObj->intrCfg.complIntrLine, pIntrParams, FALSE);

    if(S_PASS == retStat)
    {
        /* Configure edma error interrupt */
        pIntrParams = &(pEdmaObj->intrCfg.errorIntrParams);
        pIntrParams->triggerType    = INTC_TRIG_HIGH_LEVEL;
        pIntrParams->priority       = 0x10;
        pIntrParams->pFnIntrHandler   = EdmaChErrorIsr;
        pIntrParams->pUserParam     = (void*)pEdmaObj;
        pIntrParams->isIntrSecure   = FALSE;

        retStat = INTCConfigIntr(pEdmaObj->intrCfg.errorIntrLine, pIntrParams, FALSE);

        if(S_PASS != retStat)
        {
            CONSOLEUtilsPuts("Interrupt configuration failed for EDMA error  \
                                                            interrupt.\r\n");
            retStat = E_FAIL;
        }
    }
#endif
    else
    {
        CONSOLEUtilsPuts("Interrupt configuration failed for EDMA completion  \
                                                              interrupt.\r\n");
        retStat = E_FAIL;
    }


    return retStat;
}
static int32_t EDMAUtilsCtrlInit(uint32_t instNum)
{
    int32_t retStat = S_PASS;
    edmaUtilsObj_t *pEdmaObj = &gEdmaUtilsObj[instNum];

    /* Initialization of EDMA */
    EDMAInit(pEdmaObj->baseChCtrlAddr, pEdmaObj->region);

    /* Register EDMA3 Interrupts */
    EDMAUtilsIntcConfigure(instNum);

    return retStat;
}

#ifdef RTOS_BUILD
static void EdmaChCompletionIsr(void* pUserParam)
#else
static void EdmaChCompletionIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
#endif
{
    uint32_t cnt = 0U;
    uint32_t maxIntrCh = 0U;
    uint32_t chIdx = 0U;
    edmaUtilsObj_t *pInstObj = NULL;
    volatile uint32_t intrStatus = 0U;

    if(NULL != pUserParam)
    {
        pInstObj = (edmaUtilsObj_t *) pUserParam;

        maxIntrCh = EDMAGetNumIntrCh(pInstObj->baseChCtrlAddr);

        while ((cnt < EDMA_UTILS_HANDLER_RETRY_COUNT) && (0U == intrStatus))
        {
            intrStatus = EDMAIntrStatus(pInstObj->baseChCtrlAddr,
                pInstObj->region, EDMA_CH_SET_0_31);
            cnt++;
        }

        while(0U != (intrStatus >> chIdx))
        {
            if(0U != (intrStatus & (1U << chIdx)))
            {
                EDMAIntrClear(pInstObj->baseChCtrlAddr, pInstObj->region, chIdx);

                if(NULL != pInstObj->pFnCallBack[chIdx])
                {
                    pInstObj->pFnCallBack[chIdx](chIdx, DMA_CH_XFER_STATUS_NORMAL);
                }
            }
            chIdx++;
        }

        cnt = 0U;
        chIdx = 0U;
        intrStatus = 0U;

        if(32U < maxIntrCh)
        {
            while ((cnt < EDMA_UTILS_HANDLER_RETRY_COUNT) && (0U == intrStatus))
            {
                intrStatus = EDMAIntrStatus(pInstObj->baseChCtrlAddr,
                    pInstObj->region, EDMA_CH_SET_32_63);
                cnt++;
            }

            while(0U != (intrStatus >> chIdx))
            {
                if(0U != (intrStatus & (1U << chIdx)))
                {
                    EDMAIntrClear(pInstObj->baseChCtrlAddr, pInstObj->region, chIdx + 32U);

                    if(NULL != pInstObj->pFnCallBack[chIdx + 32U])
                    {
                        pInstObj->pFnCallBack[chIdx + 32U](chIdx + 32U, DMA_CH_XFER_STATUS_NORMAL);
                    }
                }
                chIdx++;
            }
        }
    }
}

#ifdef RTOS_BUILD
void EdmaChErrorIsr(void* pUserParam)
#else
void EdmaChErrorIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
#endif
{
    uint32_t cnt = 0U;
    uint32_t maxIntrCh = 0U;
    uint32_t maxQueue = 0U;
    uint32_t chIdx = 0U;
    edmaUtilsObj_t *pInstObj = NULL;
    volatile uint32_t intrErrStatus = 0U;

    if(NULL != pUserParam)
    {
        pInstObj = (edmaUtilsObj_t *) pUserParam;
        maxIntrCh = EDMAGetNumIntrCh(pInstObj->baseChCtrlAddr);
        maxQueue = EDMAGetNumQueues(pInstObj->baseChCtrlAddr);

        while ((cnt < EDMA_UTILS_HANDLER_RETRY_COUNT) && (0U == intrErrStatus))
        {
            intrErrStatus = EDMAEvtMissStatus(pInstObj->baseChCtrlAddr,
                EDMA_CH_TYPE_QDMA, EDMA_CH_SET_0_31);
            cnt++;
        }

        while(0U != (intrErrStatus >> chIdx))
        {
            if(0U != (intrErrStatus & (1U << chIdx)))
            {
                EDMAChMissEvtClear(pInstObj->baseChCtrlAddr, pInstObj->region, EDMA_CH_TYPE_QDMA, chIdx);
            }
            chIdx++;
        }

        cnt = 0U;
        chIdx = 0U;
        intrErrStatus = 0U;

        while ((cnt < EDMA_UTILS_HANDLER_RETRY_COUNT) && (0U == intrErrStatus))
        {
            intrErrStatus = EDMAEvtMissStatus(pInstObj->baseChCtrlAddr,
                EDMA_CH_TYPE_DMA, EDMA_CH_SET_0_31);
            cnt++;
        }

        while(0U != (intrErrStatus >> chIdx))
        {
            if(0U != (intrErrStatus & (1U << chIdx)))
            {
                EDMAChMissEvtClear(pInstObj->baseChCtrlAddr, pInstObj->region, EDMA_CH_TYPE_DMA, chIdx);
            }
            chIdx++;
        }

        cnt = 0U;
        chIdx = 0U;
        intrErrStatus = 0U;

        if(32U < maxIntrCh)
        {
            while ((cnt < EDMA_UTILS_HANDLER_RETRY_COUNT) && (0U == intrErrStatus))
            {
                intrErrStatus = EDMAEvtMissStatus(pInstObj->baseChCtrlAddr,
                    EDMA_CH_TYPE_DMA, EDMA_CH_SET_32_63);
                cnt++;
            }

            while(0U != (intrErrStatus >> chIdx))
            {
                if(0U != (intrErrStatus & (1U << chIdx)))
                {
                    EDMAChMissEvtClear(pInstObj->baseChCtrlAddr, pInstObj->region, EDMA_CH_TYPE_DMA, chIdx + 32U);
                }
                chIdx++;
            }
        }

        cnt = 0U;
        chIdx = 0U;
        intrErrStatus = TRUE;

        while ((cnt < EDMA_UTILS_HANDLER_RETRY_COUNT) && (TRUE == intrErrStatus))
        {
            EDMAComplCodeErrClear(pInstObj->baseChCtrlAddr);
            intrErrStatus = EDMAComplCodeErrStatus(pInstObj->baseChCtrlAddr);
            cnt++;
        }

        for(chIdx = 0U; chIdx < maxQueue; chIdx++)
        {
            cnt = 0U;
            intrErrStatus = TRUE;

            while ((cnt < EDMA_UTILS_HANDLER_RETRY_COUNT) && (TRUE == intrErrStatus))
            {
                EDMAQueueThresholdErrClear(pInstObj->baseChCtrlAddr, chIdx);
                intrErrStatus = EDMAQueueThresholdErrStatus(pInstObj->baseChCtrlAddr, chIdx);
                cnt++;
            }
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
