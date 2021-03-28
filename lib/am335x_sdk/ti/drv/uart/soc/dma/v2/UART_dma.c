/**
 * @file   UART_dma.c
 *
 * @brief  This file implements the NAVSS UDMA based UART driver for IP of version V1
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

#include <ti/csl/src/ip/uart/V1/uart.h>
#include <ti/drv/uart/soc/UART_soc.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/udma/udma.h>

static void UART_dmaRxIsrHandler(Udma_EventHandle  eventHandle,
                                 uint32_t          eventType,
                                 void             *appData);
static void UART_dmaTxIsrHandler(Udma_EventHandle  eventHandle,
                                 uint32_t          eventType,
                                 void             *appData);

void UART_disableDmaChannel(UART_Handle handle, bool txChan)
{
    UART_HwAttrs const *hwAttrs;
    Udma_ChHandle       channel;

    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

    if (txChan == (bool)true)
    {
        channel = (Udma_ChHandle)(hwAttrs->dmaInfo->txChHandle);
    }
    else
    {
        channel = (Udma_ChHandle)(hwAttrs->dmaInfo->rxChHandle);
    }

    (void)Udma_chDisable(channel, UDMA_DEFAULT_CH_DISABLE_TIMEOUT);
}

void UART_freeDmaChannel(UART_Handle handle)
{
    int32_t             retVal;
    UART_HwAttrs const *hwAttrs;
    UART_dmaInfo       *pDmaInfo;

    hwAttrs  = (UART_HwAttrs const *)handle->hwAttrs;
    pDmaInfo = hwAttrs->dmaInfo;

    /* Close the TX channel */
    retVal = Udma_eventUnRegister((Udma_EventHandle)(pDmaInfo->txEventHandle));
    if (UDMA_SOK == retVal)
    {
        retVal = Udma_chClose((Udma_ChHandle)(pDmaInfo->txChHandle));
    }

    /* Close the RX channel */
    retVal = Udma_eventUnRegister((Udma_EventHandle)(pDmaInfo->rxEventHandle));
    if (UDMA_SOK == retVal)
    {
        retVal = Udma_chClose((Udma_ChHandle)(pDmaInfo->rxChHandle));
    }

    return;
}

static void UART_udmaHpdInit(Udma_ChHandle  chHandle,
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
    CacheP_wbInv((const void *)pHpd, (int32_t)(sizeof(CSL_UdmapCppi5HMPD)));
#endif
    return;
}

void UART_receiveDMA(UART_Handle handle, const void *buffer, size_t size)
{
    int32_t             retVal;
    UART_HwAttrs const *hwAttrs;
    UART_V1_Object     *object ;
    uint32_t            actualThreshold;
    uint32_t            rxSize;
    UART_dmaInfo       *pDmaInfo;
    Udma_ChPdmaPrms     pdmaPrms;
    uint8_t            *pHpdMem;
    Udma_ChHandle       chHandle;

    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    object  = (UART_V1_Object *)handle->object;
    pDmaInfo = hwAttrs->dmaInfo;
    chHandle = (Udma_ChHandle)(pDmaInfo->rxChHandle);
    actualThreshold = (uint32_t)(hwAttrs->rxTrigLvl);

    if ((uint32_t)size <= actualThreshold)
    {
        rxSize = (uint32_t)size;
    }
    else
    {
        rxSize = ((uint32_t)size / actualThreshold) * actualThreshold;
    }
    object->readDmaSize = rxSize;

    UdmaChPdmaPrms_init(&pdmaPrms);
    pdmaPrms.elemSize = 0;
    if (rxSize > actualThreshold)
    {
        pdmaPrms.elemCnt = actualThreshold;
        pdmaPrms.fifoCnt = rxSize / actualThreshold;
    }
    else
    {
        pdmaPrms.elemCnt = rxSize;
        pdmaPrms.fifoCnt = 1U;
    }

    retVal = Udma_chConfigPdma(chHandle, &pdmaPrms);

    if(UDMA_SOK == retVal)
    {
        retVal = Udma_chEnable(chHandle);
    }

    if(UDMA_SOK == retVal)
    {
        /* Update host packet descriptor */
        pHpdMem = (uint8_t *) pDmaInfo->rxHpdMem;
        UART_udmaHpdInit(chHandle, pHpdMem, buffer, rxSize);

        /* Submit HPD to channel */
        retVal = Udma_ringQueueRaw(Udma_chGetFqRingHandle(chHandle), (uint64_t)pHpdMem);
    }
}

void UART_transmitDMA(UART_Handle handle, const void *buffer, size_t size)
{
    int32_t             retVal;
    UART_HwAttrs const *hwAttrs;
    UART_dmaInfo       *pDmaInfo;
    Udma_ChPdmaPrms     pdmaPrms;
    uint8_t            *pHpdMem;
    Udma_ChHandle       chHandle;

    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    pDmaInfo = hwAttrs->dmaInfo;
    chHandle = (Udma_ChHandle)(pDmaInfo->txChHandle);

    UdmaChPdmaPrms_init(&pdmaPrms);
    pdmaPrms.elemSize = 0; /* 8-bit */
    if ((uint32_t)size > (uint32_t)(hwAttrs->txTrigLvl))
    {
        pdmaPrms.elemCnt = (uint32_t)(hwAttrs->txTrigLvl);
    }
    else
    {
        pdmaPrms.elemCnt = (uint32_t)size;
    }
    pdmaPrms.fifoCnt = 0U;   /* Don't care for write */
    retVal = Udma_chConfigPdma(chHandle, &pdmaPrms);

    if(UDMA_SOK == retVal)
    {
        retVal = Udma_chEnable(chHandle);
    }

    if(UDMA_SOK == retVal)
    {
        /* Update host packet descriptor */
        pHpdMem = (uint8_t *) pDmaInfo->txHpdMem;
        UART_udmaHpdInit(chHandle, pHpdMem, buffer, (uint32_t)size);

        /* Submit HPD to channel */
        retVal = Udma_ringQueueRaw(Udma_chGetFqRingHandle(chHandle), (uint64_t)pHpdMem);
    }

    return;
}

int32_t UART_configDMA(UART_Handle handle)
{
    int32_t               retVal;
    int32_t               status = UART_SUCCESS;
    UART_HwAttrs const   *hwAttrs;
    UART_dmaInfo         *pDmaInfo;
    Udma_DrvHandle        drvHandle;
    uint32_t              chType;
    Udma_ChPrms           chPrms;
    Udma_ChTxPrms         txPrms;
    Udma_ChRxPrms         rxPrms;
    Udma_EventHandle      eventHandle;
    Udma_EventPrms        eventPrms;
    Udma_ChHandle         rxChHandle;
    Udma_ChHandle         txChHandle;

    hwAttrs   = (UART_HwAttrs const *)handle->hwAttrs;
    pDmaInfo  = hwAttrs->dmaInfo;
    drvHandle = (Udma_DrvHandle)(hwAttrs->edmaHandle);
    rxChHandle = (Udma_ChHandle)(pDmaInfo->rxChHandle);
    txChHandle = (Udma_ChHandle)(pDmaInfo->txChHandle);

    /* Init TX channel parameters */
    chType = UDMA_CH_TYPE_PDMA_TX;
    UdmaChPrms_init(&chPrms, chType);
    chPrms.peerChNum            = hwAttrs->txDmaEventNumber;
    chPrms.fqRingPrms.ringMem   = pDmaInfo->txRingMem;
    chPrms.cqRingPrms.ringMem   = pDmaInfo->cqTxRingMem;
    chPrms.tdCqRingPrms.ringMem = pDmaInfo->tdCqTxRingMem;
    chPrms.fqRingPrms.elemCnt   = 1;
    chPrms.cqRingPrms.elemCnt   = 1;
    chPrms.tdCqRingPrms.elemCnt = 1;

    /* Open TX channel for transmit */
    retVal = Udma_chOpen(drvHandle, txChHandle, chType, &chPrms);

    if(UDMA_SOK == retVal)
    {
        /* Init RX channel parameters */
        chType = UDMA_CH_TYPE_PDMA_RX;
        UdmaChPrms_init(&chPrms, chType);
        chPrms.peerChNum            = hwAttrs->rxDmaEventNumber;
        chPrms.fqRingPrms.ringMem   = pDmaInfo->rxRingMem;
        chPrms.cqRingPrms.ringMem   = pDmaInfo->cqRxRingMem;
        chPrms.tdCqRingPrms.ringMem = pDmaInfo->tdCqRxRingMem;
        chPrms.fqRingPrms.elemCnt   = 1;
        chPrms.cqRingPrms.elemCnt   = 1;
        chPrms.tdCqRingPrms.elemCnt = 1;

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
        eventPrms.eventCb           = &UART_dmaTxIsrHandler;
        eventPrms.appData           = (void *)handle;
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
        eventPrms.eventCb           = &UART_dmaRxIsrHandler;
        eventPrms.appData           = (void *)handle;
        retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
    }

    if (UDMA_SOK == retVal)
    {
        status = UART_SUCCESS;
    }
    else
    {
        status = UART_ERROR;
    }

    return(status);
}

static void UART_dmaRxIsrHandler(Udma_EventHandle  eventHandle,
                                 uint32_t          eventType,
                                 void             *appData)
{
    UART_Handle         handle;
    UART_HwAttrs const *hwAttrs;
    UART_V1_Object     *object ;
    uint32_t            bytesRemain;
    uint64_t            pDesc = 0;
    int32_t             status;
    CSL_UdmapCppi5HMPD *pHmpd;
    uint32_t            size = 0;

    if(appData != NULL)
    {
        handle  = (UART_Handle)appData;
        hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
        object  = (UART_V1_Object *)handle->object;

#if !defined (__aarch64__)
        CacheP_Inv((const void *)hwAttrs->dmaInfo->cqRxRingMem, (int32_t)(sizeof(void *)));
#endif
        /*
         * Dequeue the descriptor from the RX completion queue
         * to be re-used for the next transfer
         */
        status = Udma_ringDequeueRaw(Udma_chGetCqRingHandle((Udma_ChHandle) hwAttrs->dmaInfo->rxChHandle), &pDesc);
        if ((UDMA_SOK == status) && (pDesc != 0UL))
        {
            pHmpd = (CSL_UdmapCppi5HMPD *)(uintptr_t)pDesc;
            size = (pHmpd->descInfo & CSL_UDMAP_CPPI5_PD_DESCINFO_PKTLEN_MASK) >> CSL_UDMAP_CPPI5_PD_DESCINFO_PKTLEN_SHIFT;
            object->readCount += size;
        }

        if (UDMA_SOK == status)
        {
            if (size == object->readDmaSize)
            {
                /*
                 * read DMA transfer succussful, calculate the amount of remaining
                 * bytes that need to be received in non-DMA mode
                 */
                bytesRemain = (uint32_t)(object->readSize) % (uint32_t)(hwAttrs->rxTrigLvl);
                if (((uint32_t)(object->readSize) >= (uint32_t)(hwAttrs->rxTrigLvl)) && (bytesRemain != 0U))
                {
                    /*
                     * read size is not multiple of RX threshold
                     * enable RHR interrupt to receive the
                     * remaining bytes in non-DMA mode
                     */
                    object->readSize = bytesRemain;
                    object->readBuf = (uint8_t *)object->readBuf + object->readCount;
                    UARTIntEnable(hwAttrs->baseAddr, UART_INT_RHR_CTI);
                }
                else
                {
                    /*
                     * all the data received
                     */
                    if (object->readTrans != NULL)
                    {
                        object->readTrans->count = (uint32_t)(object->readCount);
                        object->readTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                    }
                    object->readSize = 0;
                    UARTIntDisable(hwAttrs->baseAddr, UART_INT_LINE_STAT);
                    UART_v1_callback(handle, (bool)true);
                }
            }
        }
    }
}

static void UART_dmaTxIsrHandler(Udma_EventHandle  eventHandle,
                                 uint32_t          eventType,
                                 void             *appData)
{
    UART_Handle         handle;
    UART_HwAttrs const *hwAttrs;
    UART_V1_Object     *object ;
    uint64_t            pDesc = 0;
    int32_t             status;
    CSL_UdmapCppi5HMPD *pHmpd;
    uint32_t            size = 0;

    if(appData != NULL)
    {
        handle = (UART_Handle)appData;
        hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
        object = (UART_V1_Object *)handle->object;

#if !defined (__aarch64__)
        CacheP_Inv((const void *)hwAttrs->dmaInfo->cqTxRingMem, (int32_t)(sizeof(void *)));
#endif
        /*
         * Dequeue the descriptor from the TX completion queue
         * to be re-used for the next transfer
         */
        status = Udma_ringDequeueRaw(Udma_chGetCqRingHandle((Udma_ChHandle) hwAttrs->dmaInfo->txChHandle), &pDesc);

        if ((UDMA_SOK == status) && (pDesc != 0UL))
        {
            pHmpd = (CSL_UdmapCppi5HMPD *)(uintptr_t)pDesc;
            size = (pHmpd->descInfo & CSL_UDMAP_CPPI5_PD_DESCINFO_PKTLEN_MASK) >> CSL_UDMAP_CPPI5_PD_DESCINFO_PKTLEN_SHIFT;
            object->writeCount += size;

            /*
             * all the data sent
             */
            if (object->writeTrans != NULL)
            {
                object->writeTrans->count = (uint32_t)(object->writeCount);
                object->writeTrans->status = UART_TRANSFER_STATUS_SUCCESS;
            }
            object->writeSize = 0;
            object->txDataSent = TRUE;
            UARTInt2Enable(hwAttrs->baseAddr, UART_INT2_TX_EMPTY);
        }
    }
}

