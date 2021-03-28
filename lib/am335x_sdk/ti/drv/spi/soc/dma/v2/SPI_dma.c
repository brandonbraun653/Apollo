/**
 *  \file   SPI_dma.c
 *
 *  \brief  NAVSS UDMAP based McSPI driver for IP verion 1.
 *
 *   This file contains the driver APIs for SPI.
 */

/*
 * Copyright (c) 2017 - 2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/spi/src/SPI_osal.h>
#include <ti/drv/udma/udma.h>

/** Flag to indicate that Reception EDMA callback has occured             */
#define MCSPI_RX_EDMA_CALLBACK_OCCURED    (0x2U)

/** Flag to indicate that Transmission EDMA callback has occured          */
#define MCSPI_TX_EDMA_CALLBACK_OCCURED    (0x1U)

/* DMA functions */
static void MCSPI_dmaRxIsrHandler(Udma_EventHandle  eventHandle,
                                  uint32_t          eventType,
                                  void             *appData);
static void MCSPI_dmaTxIsrHandler(Udma_EventHandle  eventHandle,
                                  uint32_t          eventType,
                                  void             *appData);
static void MCSPI_dmaCompleteIOCallback(MCSPI_Handle mcHandle);

int32_t MCSPI_dmaConfig(MCSPI_Handle mcHandle);
void MCSPI_dmaTransfer(MCSPI_Handle mcHandle, SPI_Transaction *transaction);
void MCSPI_dmaFreeChannel(MCSPI_Handle handle);

int32_t MCSPI_dmaConfig(MCSPI_Handle mcHandle)
{
    int32_t            retVal;
    int32_t            status;
    SPI_Handle         handle;
    SPI_HWAttrs const *hwAttrs;
    SPI_dmaInfo       *pDmaInfo;
    uint32_t           chNum;
    Udma_DrvHandle     drvHandle;
    uint32_t           chType;
    Udma_ChPrms        chPrms;
    Udma_ChTxPrms      txPrms;
    Udma_ChRxPrms      rxPrms;
    Udma_EventHandle   eventHandle;
    Udma_EventPrms     eventPrms;
    Udma_ChHandle      txChHandle;
    Udma_ChHandle      rxChHandle;

    /* Get the pointer to the object and hwAttrs */
    handle     = mcHandle->handle;
    hwAttrs    = (SPI_HWAttrs const *)handle->hwAttrs;
    pDmaInfo   = hwAttrs->dmaInfo;
    drvHandle  = (Udma_DrvHandle)(hwAttrs->edmaHandle);
    txChHandle = (Udma_ChHandle)(pDmaInfo->txChHandle);
    rxChHandle = (Udma_ChHandle)(pDmaInfo->rxChHandle);
    chNum      = mcHandle->chnNum;

    /* Init TX channel parameters */
    chType = UDMA_CH_TYPE_PDMA_TX;
    UdmaChPrms_init(&chPrms, chType);
    chPrms.peerChNum            = hwAttrs->txDmaEventNumber + chNum;
    chPrms.fqRingPrms.ringMem   = pDmaInfo->txRingMem;
    chPrms.cqRingPrms.ringMem   = pDmaInfo->cqTxRingMem;
    chPrms.fqRingPrms.elemCnt   = 1;
    chPrms.cqRingPrms.elemCnt   = 1;

    /* Open TX channel for transmit */
    retVal = Udma_chOpen(drvHandle, txChHandle, chType, &chPrms);

    if(UDMA_SOK == retVal)
    {
        /* Init RX channel parameters */
        chType = UDMA_CH_TYPE_PDMA_RX;
        UdmaChPrms_init(&chPrms, chType);
        chPrms.peerChNum            = hwAttrs->rxDmaEventNumber + chNum;
        chPrms.fqRingPrms.ringMem   = pDmaInfo->rxRingMem;
        chPrms.cqRingPrms.ringMem   = pDmaInfo->cqRxRingMem;
        chPrms.fqRingPrms.elemCnt   = 1;
        chPrms.cqRingPrms.elemCnt   = 1;

        /* Open RX channel for transmit */
        retVal = Udma_chOpen(drvHandle, rxChHandle, chType, &chPrms);
    }

    if(UDMA_SOK == retVal)
    {
        UdmaChTxPrms_init(&txPrms, chType);
        retVal = Udma_chConfigTx(txChHandle, &txPrms);
    }

    if(UDMA_SOK == retVal)
    {
        UdmaChRxPrms_init(&rxPrms, chType);
        retVal = Udma_chConfigRx(rxChHandle, &rxPrms);
    }

    /* Register TX ring event callback */
    if(UDMA_SOK == retVal)
    {
        /* Register ring completion callback */
        eventHandle = (Udma_EventHandle)(pDmaInfo->txEventHandle);
        UdmaEventPrms_init(&eventPrms);
        eventPrms.eventType         = UDMA_EVENT_TYPE_DMA_COMPLETION;
        eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
        eventPrms.chHandle          = txChHandle;
        eventPrms.masterEventHandle = NULL;
        eventPrms.eventCb           = &MCSPI_dmaTxIsrHandler;
        eventPrms.appData           = (void *)mcHandle;
        retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
    }

    /* Register RX ring event callback */
    if(UDMA_SOK == retVal)
    {
        /* Register ring completion callback */
        eventHandle = (Udma_EventHandle)(pDmaInfo->rxEventHandle);
        UdmaEventPrms_init(&eventPrms);
        eventPrms.eventType         = UDMA_EVENT_TYPE_DMA_COMPLETION;
        eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
        eventPrms.chHandle          = rxChHandle;
        eventPrms.masterEventHandle = NULL;
        eventPrms.eventCb           = &MCSPI_dmaRxIsrHandler;
        eventPrms.appData           = (void *)mcHandle;
        retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
    }

    if (UDMA_SOK == retVal)
    {
        status = SPI_STATUS_SUCCESS;
    }
    else
    {
        status = SPI_STATUS_ERROR;
    }
    return(status);
}

static void MCSPI_udmaHpdInit(Udma_ChHandle  chHandle,
                              uint8_t       *pHpdMem,
                              const void    *bufPtr,
                              uint32_t       length)
{
    CSL_UdmapCppi5HMPD *pHpd = (CSL_UdmapCppi5HMPD *) pHpdMem;
    uint32_t descType = (uint32_t)CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST;
    uint32_t cqRingNum = Udma_chGetCqRingNum(chHandle);

    /* Setup descriptor */
    CSL_udmapCppi5SetDescType(pHpd, descType);
    CSL_udmapCppi5SetEpiDataPresent(pHpd, (bool)false);
    CSL_udmapCppi5SetPsDataLoc(pHpd, 0U);
    CSL_udmapCppi5SetPsDataLen(pHpd, 0U);
    CSL_udmapCppi5SetPktLen(pHpd, descType, length);
    CSL_udmapCppi5SetPsFlags(pHpd, 0U);
    CSL_udmapCppi5SetIds(pHpd, descType, 0x321, 0x3FFFU);
    CSL_udmapCppi5SetSrcTag(pHpd, 0x0000);     /* Not used */
    CSL_udmapCppi5SetDstTag(pHpd, 0x0000);     /* Not used */
    CSL_udmapCppi5SetReturnPolicy(
        pHpd,
        descType,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_VAL_ENTIRE_PKT,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_EARLYRET_VAL_NO,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_VAL_TO_TAIL,
        cqRingNum);
    CSL_udmapCppi5LinkDesc(pHpd, 0U);
    CSL_udmapCppi5SetBufferAddr(pHpd, (uint64_t) bufPtr);
    CSL_udmapCppi5SetBufferLen(pHpd, length);
    CSL_udmapCppi5SetOrgBufferAddr(pHpd, (uint64_t) bufPtr);
    CSL_udmapCppi5SetOrgBufferLen(pHpd, length);

#if !defined (__aarch64__)
    CacheP_wbInv((void *)pHpd, (int32_t)sizeof(CSL_UdmapCppi5HMPD));
#endif
    return;
}

static int32_t MCSPI_dmaTx(MCSPI_Handle   mcHandle,
                           const void    *srcBuf,
                           uint32_t       length)
{
    int32_t            retVal;
    SPI_Handle         handle;
    SPI_v1_Object     *object;
    SPI_HWAttrs const *hwAttrs;
    SPI_dmaInfo       *pDmaInfo;
    uint32_t           chNum;
    Udma_ChPdmaPrms    pdmaPrms;
    uint8_t           *pHpdMem;
    Udma_ChHandle      txChHandle;

    /* Get the pointer to the object and hwAttrs */
    handle   = mcHandle->handle;
    hwAttrs  = (SPI_HWAttrs const *)handle->hwAttrs;
    pDmaInfo = hwAttrs->dmaInfo;
    txChHandle = (Udma_ChHandle)(pDmaInfo->txChHandle);
    chNum    = mcHandle->chnNum;
    object   = (SPI_v1_Object *)handle->object;

    UdmaChPdmaPrms_init(&pdmaPrms);
    if (object->chObject[chNum].wordLenShift < 2U)
    {
        pdmaPrms.elemSize = object->chObject[chNum].wordLenShift;
    }
    else
    {
        pdmaPrms.elemSize = UDMA_PDMA_ES_32BITS;
    }

    if (length > hwAttrs->txTrigLvl)
    {
        pdmaPrms.elemCnt = (uint32_t)(hwAttrs->txTrigLvl >> \
                           object->chObject[chNum].wordLenShift);
    }
    else
    {
        pdmaPrms.elemCnt = (uint32_t)(length >> \
                           object->chObject[chNum].wordLenShift);
    }

    pdmaPrms.fifoCnt    = 0U;   /* Don't care for write */
    retVal = Udma_chConfigPdma(txChHandle, &pdmaPrms);

    if(UDMA_SOK == retVal)
    {
        retVal = Udma_chEnable(txChHandle);
    }

    if(UDMA_SOK == retVal)
    {
        /* Update host packet descriptor */
        pHpdMem = (uint8_t *) pDmaInfo->txHpdMem;
        MCSPI_udmaHpdInit(txChHandle, pHpdMem, srcBuf, length);

        /* Submit HPD to channel */
        retVal = Udma_ringQueueRaw(Udma_chGetFqRingHandle(txChHandle), (uint64_t) pHpdMem);
    }

    return (retVal);
}

static int32_t MCSPI_dmaRx(MCSPI_Handle   mcHandle,
                           const void    *destBuf,
                           uint32_t       length)
{
    int32_t            retVal;
    SPI_Handle         handle;
    SPI_v1_Object     *object;
    SPI_HWAttrs const *hwAttrs;
    SPI_dmaInfo       *pDmaInfo;
    uint32_t           chNum;
    Udma_ChPdmaPrms    pdmaPrms;
    uint8_t           *pHpdMem;
    Udma_ChHandle      rxChHandle;

    /* Get the pointer to the object and hwAttrs */
    handle   = mcHandle->handle;
    hwAttrs  = (SPI_HWAttrs const *)handle->hwAttrs;
    pDmaInfo = hwAttrs->dmaInfo;
    rxChHandle = (Udma_ChHandle)(pDmaInfo->rxChHandle);
    chNum    = mcHandle->chnNum;
    object   = (SPI_v1_Object *)handle->object;

    UdmaChPdmaPrms_init(&pdmaPrms);
    if (object->chObject[chNum].wordLenShift < 2U)
    {
        pdmaPrms.elemSize = object->chObject[chNum].wordLenShift;
    }
    else
    {
        pdmaPrms.elemSize = UDMA_PDMA_ES_32BITS;
    }

    if (length > hwAttrs->rxTrigLvl)
    {
        pdmaPrms.elemCnt = (uint32_t)(hwAttrs->rxTrigLvl >> \
                           object->chObject[chNum].wordLenShift);
        pdmaPrms.fifoCnt = length / hwAttrs->rxTrigLvl;
    }
    else
    {
        pdmaPrms.elemCnt = (uint32_t)(length >> \
                           object->chObject[chNum].wordLenShift);
        pdmaPrms.fifoCnt = 1U;
    }

    retVal = Udma_chConfigPdma(rxChHandle, &pdmaPrms);

    if(UDMA_SOK == retVal)
    {
        retVal = Udma_chEnable(rxChHandle);
    }

    if(UDMA_SOK == retVal)
    {
        /* Update host packet descriptor */
        pHpdMem = (uint8_t *) pDmaInfo->rxHpdMem;
        MCSPI_udmaHpdInit(rxChHandle, pHpdMem, destBuf, length);

        /* Submit HPD to channel */
        retVal = Udma_ringQueueRaw(Udma_chGetFqRingHandle(rxChHandle), (uint64_t) pHpdMem);
    }

    return (retVal);
}

void MCSPI_dmaTransfer(MCSPI_Handle     mcHandle,
                       SPI_Transaction *transaction)
{
    SPI_Handle           handle;
    SPI_v1_Object       *object;
    SPI_HWAttrs const   *hwAttrs;
    SPI_v1_chObject     *chObj;
    SPI_v1_ChnCfg const *chnCfg;
    uint32_t             chNum;
    uint32_t             transBytes;

    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    hwAttrs = (SPI_HWAttrs const *)handle->hwAttrs;
    chNum   = mcHandle->chnNum;
    object  = (SPI_v1_Object *)handle->object;
    chObj   = &(object->chObject[chNum]);
    chnCfg  = &(hwAttrs->chnCfg[chNum]);

    /* setup transfer mode and FIFO trigger levels */
    MCSPI_xferSetup_v1(mcHandle, transaction);

    chObj->dmaCbCheck = 0;

    /* Enable McSPI DMA for transaction
     * MCSPI_CH(chNum)CONF -> DMAR bit for receive DMA
     */
    McSPIDMAEnable((uint32_t)(hwAttrs->baseAddr),
                   ((uint32_t)MCSPI_DMA_RX_EVENT |
                    (uint32_t)MCSPI_DMA_TX_EVENT),
                   chNum);

    /* Enable the channel */
    McSPIChannelEnable((uint32_t)(hwAttrs->baseAddr), chNum);

    if ((SPI_MASTER == chObj->spiParams.mode) &&
        (hwAttrs->chMode == MCSPI_SINGLE_CH))
    {
        /* Assert chip select signal */
        McSPICSAssert((uint32_t)(hwAttrs->baseAddr), chNum);
    }

    transBytes = (uint32_t)transaction->count << chObj->wordLenShift;
    if (chnCfg->trMode == MCSPI_TX_RX_MODE)
    {
        (void)MCSPI_dmaRx(mcHandle, (const void *)transaction->rxBuf, transBytes);
        (void)MCSPI_dmaTx(mcHandle, (const void *)transaction->txBuf, transBytes);
    }
    else if (chnCfg->trMode == MCSPI_TX_ONLY_MODE)
    {
        /* TX_ONLY Mode */
        (void)MCSPI_dmaTx(mcHandle, (const void *)transaction->txBuf, transBytes);
    }
    else
    {
        /* RX_ONLY Mode */
        (void)MCSPI_dmaRx(mcHandle, (const void *)transaction->rxBuf, transBytes);
    }
}

void MCSPI_dmaFreeChannel(MCSPI_Handle mcHandle)
{
    SPI_Handle         handle;
    SPI_HWAttrs const *hwAttrs;
    SPI_dmaInfo       *pDmaInfo;

    /* Get the pointer to the object and hwAttrs */
    handle   = mcHandle->handle;
    hwAttrs  = (SPI_HWAttrs const *)handle->hwAttrs;
    pDmaInfo = hwAttrs->dmaInfo;

    /* Close the TX channel */
    (void)Udma_eventUnRegister((Udma_EventHandle)(pDmaInfo->txEventHandle));
    (void)Udma_chClose((Udma_ChHandle)(pDmaInfo->txChHandle));

    /* Close the RX channel */
    (void)Udma_eventUnRegister((Udma_EventHandle)(pDmaInfo->rxEventHandle));
    (void)Udma_chClose((Udma_ChHandle)(pDmaInfo->rxChHandle));
}

static void MCSPI_dmaTxIsrHandler(Udma_EventHandle  eventHandle,
                                  uint32_t          eventType,
                                  void             *appData)
{
    MCSPI_Handle         mcHandle;
    uint32_t             chNum;
    SPI_Handle           handle;
    SPI_v1_Object       *object;
    SPI_v1_chObject     *chObj;
    SPI_HWAttrs const   *hwAttrs;
    SPI_v1_ChnCfg const *chnCfg;
    uint32_t             intStatus;
    uint64_t             pDesc = 0;
    int32_t              status;
    Udma_ChHandle        txChHandle;

    if(appData != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        mcHandle = (MCSPI_Handle)appData;
        chNum    = mcHandle->chnNum;
        handle   = mcHandle->handle;
        object   = (SPI_v1_Object *)handle->object;
        chObj    = &(object->chObject[chNum]);
        hwAttrs  = (SPI_HWAttrs const *)handle->hwAttrs;
        chnCfg   = &(hwAttrs->chnCfg[chNum]);
        txChHandle = (Udma_ChHandle)(hwAttrs->dmaInfo->txChHandle);

        /* Update the transaction status and word count transfered */
        if (eventType == UDMA_EVENT_TYPE_DMA_COMPLETION)
        {
            /*
             * Dequeue the descriptor from the TX completion queue
             * to be re-used for the next transfer
             */
            status = Udma_ringDequeueRaw(Udma_chGetCqRingHandle(txChHandle), &pDesc);
            if(UDMA_SOK != status)
            {
                chObj->transaction->status = SPI_TRANSFER_FAILED;
            }
            else
            {
                chObj->transaction->status = SPI_TRANSFER_COMPLETED;
            }
        }
        else
        {
            chObj->transaction->status = SPI_TRANSFER_FAILED;
        }

        if ((MCSPI_RX_EDMA_CALLBACK_OCCURED == chObj->dmaCbCheck) ||
            (chnCfg->trMode == MCSPI_TX_ONLY_MODE))
        {
            chObj->dmaCbCheck = 0x0;

            /* Clear error status */
            intStatus = McSPIChannelStatusGet(hwAttrs->baseAddr, chNum);
            MCSPI_clearIntErrStatus(mcHandle, intStatus);

            /* Call the completion function */
            MCSPI_dmaCompleteIOCallback(mcHandle);
        }
        else
        {
            if (eventType == UDMA_EVENT_TYPE_DMA_COMPLETION)
            {
                chObj->dmaCbCheck = MCSPI_TX_EDMA_CALLBACK_OCCURED;
            }
        }
        (void)eventHandle;
    }
}

static void MCSPI_dmaRxIsrHandler(Udma_EventHandle  eventHandle,
                                  uint32_t          eventType,
                                  void             *appData)
{
    MCSPI_Handle         mcHandle;
    uint32_t             chNum;
    SPI_Handle           handle;
    SPI_v1_Object       *object;
    SPI_v1_chObject     *chObj;
    SPI_HWAttrs const   *hwAttrs;
    SPI_v1_ChnCfg const *chnCfg;
    uint32_t             intStatus;
    uint64_t             pDesc = 0;
    int32_t              status;
    Udma_ChHandle        rxChHandle;

    if(appData != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        mcHandle = (MCSPI_Handle)appData;
        chNum    = mcHandle->chnNum;
        handle   = mcHandle->handle;
        object   = (SPI_v1_Object *)handle->object;
        chObj    = &(object->chObject[chNum]);
        hwAttrs  = (SPI_HWAttrs const *)handle->hwAttrs;
        chnCfg   = &(hwAttrs->chnCfg[chNum]);
        rxChHandle = (Udma_ChHandle)(hwAttrs->dmaInfo->rxChHandle);

        /* Update the transaction status and word count transfered */
        if (eventType == UDMA_EVENT_TYPE_DMA_COMPLETION)
        {
            /*
             * Dequeue the descriptor from the RX completion queue
             * to be re-used for the next transfer
             */
            status = Udma_ringDequeueRaw(Udma_chGetCqRingHandle(rxChHandle), &pDesc);
            if(UDMA_SOK != status)
            {
                chObj->transaction->status = SPI_TRANSFER_FAILED;
            }
            else
            {
                chObj->transaction->status = SPI_TRANSFER_COMPLETED;
            }
        }
        else
        {
            chObj->transaction->status = SPI_TRANSFER_FAILED;
        }

        if ((MCSPI_TX_EDMA_CALLBACK_OCCURED == chObj->dmaCbCheck) ||
            (chnCfg->trMode == MCSPI_RX_ONLY_MODE))
        {
            /* Now Both Tx and Rx EDMA Callbacks have happened */
            chObj->dmaCbCheck = 0x0;

            /* Clear error status */
            intStatus = McSPIChannelStatusGet(hwAttrs->baseAddr, chNum);
            MCSPI_clearIntErrStatus(mcHandle, intStatus);

            /* Call the completion function */
            MCSPI_dmaCompleteIOCallback(mcHandle);
        }
        else
        {
            if (eventType == UDMA_EVENT_TYPE_DMA_COMPLETION)
            {
                chObj->dmaCbCheck = MCSPI_RX_EDMA_CALLBACK_OCCURED;
            }
        }
        (void)eventHandle;
    }
}

static void MCSPI_dmaCompleteIOCallback(MCSPI_Handle mcHandle)
{
    SPI_Handle         handle;
    SPI_v1_Object     *object;
    SPI_v1_chObject   *chObj;
    SPI_HWAttrs const *hwAttrs;
    uint32_t           chNum;

    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object  = (SPI_v1_Object *)handle->object;
    chObj   = &(object->chObject[chNum]);
    hwAttrs = (SPI_HWAttrs const *)handle->hwAttrs;

    /* disable all the spi transfers */
    McSPIChannelDisable((uint32_t) hwAttrs->baseAddr, chNum);

    /* Clear all the interrupts here, only related to the perticular
     * channel
     */
    MCSPI_clearIntStatus(mcHandle);

    /* Disable RX/TX DMA */
    McSPIDMADisable((uint32_t)(hwAttrs->baseAddr),
                    ((uint32_t)MCSPI_DMA_RX_EVENT |
                     (uint32_t)MCSPI_DMA_TX_EVENT),
                     chNum);

    if ((SPI_MASTER == chObj->spiParams.mode) &&
        (hwAttrs->chMode == MCSPI_SINGLE_CH))
    {
        /* Deassert chip select signal */
        McSPICSDeAssert(hwAttrs->baseAddr, chNum);
    }

    /* Call the transfer completion callback function */
    chObj->transaction->status = SPI_TRANSFER_COMPLETED;
    MCSPI_transferCallback_v1(mcHandle, chObj->transaction);
}
