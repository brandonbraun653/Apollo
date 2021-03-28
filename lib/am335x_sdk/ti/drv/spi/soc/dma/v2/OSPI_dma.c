/**
 *  \file   SPI_dma.c
 *
 *  \brief  NAVSS UDMAP based OSPI driver for IP verion 0.
 *
 *   This file contains the DMA driver APIs for OSPI.
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

/* DMA functions */
static void OSPI_dmaIsrHandler(Udma_EventHandle eventHandle,
                               uint32_t         eventType,
                               void            *appData);
int32_t OSPI_dmaConfig(SPI_Handle handle);
void OSPI_dmaTransfer(SPI_Handle handle, const SPI_Transaction *transaction);
void OSPI_dmaFreeChannel(SPI_Handle handle);

int32_t OSPI_dmaConfig(SPI_Handle handle)
{
    int32_t                retVal;
    int32_t                status;
    OSPI_v0_HwAttrs const *hwAttrs;
    OSPI_dmaInfo          *pDmaInfo;
    uint32_t               chType;
    Udma_ChPrms            chPrms;
    Udma_ChTxPrms          txPrms;
    Udma_ChRxPrms          rxPrms;
    Udma_EventHandle       eventHandle;
    Udma_EventPrms         eventPrms;
    Udma_DrvHandle         drvHandle;
    Udma_ChHandle          chHandle;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs  = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    pDmaInfo = hwAttrs->dmaInfo;
    drvHandle = (Udma_DrvHandle)(pDmaInfo->drvHandle);
    chHandle = (Udma_ChHandle)(pDmaInfo->chHandle);
    eventHandle = (Udma_EventHandle)(pDmaInfo->eventHandle);

    /* Init channel parameters */
    chType = UDMA_CH_TYPE_TR_BLK_COPY;
    UdmaChPrms_init(&chPrms, chType);
    chPrms.fqRingPrms.ringMem   = pDmaInfo->ringMem;
    chPrms.cqRingPrms.ringMem   = pDmaInfo->cqRingMem;
    chPrms.tdCqRingPrms.ringMem = pDmaInfo->tdCqRingMem;
    chPrms.fqRingPrms.elemCnt   = 1;
    chPrms.cqRingPrms.elemCnt   = 1;
    chPrms.tdCqRingPrms.elemCnt = 1;

    /* Open channel for block copy */
    retVal = Udma_chOpen(drvHandle,
                         chHandle,
                         chType,
                         &chPrms);
    if(UDMA_SOK == retVal)
    {
        /* Config TX channel */
        UdmaChTxPrms_init(&txPrms, chType);
        retVal = Udma_chConfigTx(chHandle, &txPrms);
    }

    if(UDMA_SOK == retVal)
    {
        /* Config RX channel - which is implicitly paired to TX channel in
         * block copy mode */
        UdmaChRxPrms_init(&rxPrms, chType);
        retVal = Udma_chConfigRx(chHandle, &rxPrms);
    }

    if(UDMA_SOK == retVal)
    {
        /* Register ring completion callback */
        eventHandle = (Udma_EventHandle) pDmaInfo->eventHandle;
        UdmaEventPrms_init(&eventPrms);
        eventPrms.eventType         = UDMA_EVENT_TYPE_DMA_COMPLETION;
        eventPrms.eventMode         = UDMA_EVENT_MODE_SHARED;
        eventPrms.chHandle          = chHandle;
        eventPrms.masterEventHandle = NULL;
        eventPrms.eventCb           = &OSPI_dmaIsrHandler;
        eventPrms.appData           = (void *)handle;
        retVal = Udma_eventRegister(drvHandle, eventHandle, &eventPrms);
    }

    if(UDMA_SOK == retVal)
    {
        /* Enable channel */
        retVal = Udma_chEnable(chHandle);
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

static void OSPI_udmaTrpdInit(Udma_ChHandle   chHandle,
                              uint8_t        *pTrpdMem,
                              const void     *destBuf,
                              const void     *srcBuf,
                              const uint16_t *iCnt)
{
    CSL_UdmapCppi5TRPD *pTrpd = (CSL_UdmapCppi5TRPD *) pTrpdMem;
    CSL_UdmapTR15 *pTr = (CSL_UdmapTR15 *)(pTrpdMem + sizeof(CSL_UdmapTR15));
    uint32_t *pTrResp = (uint32_t *) (pTrpdMem + (sizeof(CSL_UdmapTR15) * 2U));
    uint32_t cqRingNum = Udma_chGetCqRingNum(chHandle);
    uint32_t descType = CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR;

    /* Setup descriptor */
    CSL_udmapCppi5SetDescType(pTrpd, descType);
    CSL_udmapCppi5TrSetReload(pTrpd, 0U, 0U);
    CSL_udmapCppi5SetPktLen(pTrpd, descType, 1U);       /* Only one TR in TRPD */
    CSL_udmapCppi5SetIds(pTrpd, descType, 0U, 0x3FFFU); /* Flow ID and Packet ID */
    CSL_udmapCppi5SetSrcTag(pTrpd, 0x0000);     /* Not used */
    CSL_udmapCppi5SetDstTag(pTrpd, 0x0000);     /* Not used */
    CSL_udmapCppi5TrSetEntryStride(
        pTrpd, CSL_UDMAP_CPPI5_TRPD_PKTINFO_RECSIZE_VAL_64B);
    CSL_udmapCppi5SetReturnPolicy(
        pTrpd,
        descType,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_VAL_ENTIRE_PKT,   /* Don't care for TR */
        CSL_UDMAP_CPPI5_PD_PKTINFO2_EARLYRET_VAL_NO,
        CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_VAL_TO_TAIL,
        cqRingNum);

    /* Setup TR */
    pTr->flags    = CSL_FMK(UDMAP_TR_FLAGS_TYPE, (uint32_t)15U)                                 |
                    CSL_FMK(UDMAP_TR_FLAGS_STATIC, (uint32_t)0U)                                |
                    CSL_FMK(UDMAP_TR_FLAGS_EOL, (uint32_t)0U)                                   |   /* NA */
                    CSL_FMK(UDMAP_TR_FLAGS_EVENT_SIZE, CSL_UDMAP_TR_FLAGS_EVENT_SIZE_COMPLETION)|
                    CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                    CSL_FMK(UDMAP_TR_FLAGS_TRIGGER0_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                    CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1, CSL_UDMAP_TR_FLAGS_TRIGGER_NONE)           |
                    CSL_FMK(UDMAP_TR_FLAGS_TRIGGER1_TYPE, CSL_UDMAP_TR_FLAGS_TRIGGER_TYPE_ALL)  |
                    CSL_FMK(UDMAP_TR_FLAGS_CMD_ID, (uint32_t)0x25U)                             |   /* This will come back in TR response */
                    CSL_FMK(UDMAP_TR_FLAGS_SA_INDIRECT, (uint32_t)0U)                           |
                    CSL_FMK(UDMAP_TR_FLAGS_DA_INDIRECT, (uint32_t)0U)                           |
                    CSL_FMK(UDMAP_TR_FLAGS_EOP, (uint32_t)1U);
    pTr->icnt0    = iCnt[0];
    pTr->icnt1    = iCnt[1];
    pTr->icnt2    = iCnt[2];
    pTr->icnt3    = iCnt[3];
    pTr->dim1     = (int32_t)pTr->icnt0;
    pTr->dim2     = (int32_t)pTr->icnt0 * (int32_t)pTr->icnt1;
    pTr->dim3     = (int32_t)pTr->icnt0 * (int32_t)pTr->icnt1 * (int32_t)pTr->icnt2;
    pTr->addr     = (uint64_t) srcBuf;
    pTr->fmtflags = 0x00000000U;        /* Linear addressing, 1 byte per elem.
                                           Replace with CSL-FL API */
    pTr->dicnt0   = iCnt[0];
    pTr->dicnt1   = iCnt[1];
    pTr->dicnt2   = iCnt[2];
    pTr->dicnt3   = iCnt[3];
    pTr->ddim1    = (int32_t)pTr->dicnt0;
    pTr->ddim2    = (int32_t)pTr->dicnt0 * (int32_t)pTr->dicnt1;
    pTr->ddim3    = (int32_t)pTr->dicnt0 * (int32_t)pTr->dicnt1 * (int32_t)pTr->dicnt2;
    pTr->daddr    = (uint64_t) destBuf;

    /* Clear TR response memory */
    *pTrResp = 0xFFFFFFFFU;

#if !defined (__aarch64__)
    CacheP_wbInv((void *)pTrpd, (int32_t)(sizeof(CSL_UdmapTR15)*2U));
#endif
    return;
}

#define OSPI_DMA_XFER_SIZE           (0x00008000U)
#define OSPI_DMA_MAX_L0_XFER_SIZE    (0x00010000U)
static int32_t OSPI_udmaMemcpy(SPI_Handle     handle,
                               const void    *destBuf,
                               const void    *srcBuf,
                               uint32_t       length)
{
    int32_t                retVal = UDMA_SOK;
    OSPI_v0_HwAttrs const *hwAttrs;
    OSPI_dmaInfo          *pDmaInfo;
    Udma_ChHandle          chHandle;
    uint32_t               quotient;
    uint16_t               iCnt[4];

    /* Get the pointer to hwAttrs */
    hwAttrs  = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    pDmaInfo = hwAttrs->dmaInfo;
    chHandle = (Udma_ChHandle)(pDmaInfo->chHandle);

    if (length < OSPI_DMA_MAX_L0_XFER_SIZE)
    {
        iCnt[0] = (uint16_t)length;
        iCnt[1] = (uint16_t)1U;
        iCnt[2] = (uint16_t)1U;
        iCnt[3] = (uint16_t)1U;
    }
    else
    {
        iCnt[0] = (uint16_t)OSPI_DMA_XFER_SIZE;
        quotient = length / OSPI_DMA_XFER_SIZE;
        iCnt[1] = (uint16_t)(quotient);
        if (quotient < OSPI_DMA_MAX_L0_XFER_SIZE)
        {
            iCnt[2] = (uint16_t)1U;
        }
        else
        {
            iCnt[2] = (uint16_t)(quotient / OSPI_DMA_MAX_L0_XFER_SIZE);
        }
        iCnt[3] = (uint16_t)1U;
    }
    /* Update TR packet descriptor */
    OSPI_udmaTrpdInit(chHandle, (uint8_t *)pDmaInfo->tprdMem, destBuf, srcBuf, iCnt);

    /* Submit TRPD to channel */
    retVal = Udma_ringQueueRaw(Udma_chGetFqRingHandle(chHandle), (uint64_t)(pDmaInfo->tprdMem));

    return (retVal);
}

void OSPI_dmaTransfer(SPI_Handle             handle,
                      const SPI_Transaction *transaction)
{
    OSPI_v0_Object        *object;
    OSPI_v0_HwAttrs const *hwAttrs;
    uintptr_t              dataPtr;
    uint32_t               offset;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    object  = (OSPI_v0_Object *)handle->object;

    offset = (uint32_t)((uintptr_t)transaction->arg); /* OSPI Flash offset address to write */
    dataPtr = (uintptr_t)(hwAttrs->dataAddr + offset);

    if((uint32_t)SPI_TRANSACTION_TYPE_READ == object->transactionType)
    {
        /* RX Mode */
        (void)OSPI_udmaMemcpy(handle,
                              (void *)transaction->rxBuf,
                              (void *)dataPtr,
                              (uint32_t)transaction->count);
    }
    else
    {
        /* TX Mode */
        (void)OSPI_udmaMemcpy(handle,
                              (void *)dataPtr,
                              (void *)transaction->txBuf,
                              (uint32_t)transaction->count);
    }
}

void OSPI_dmaFreeChannel(SPI_Handle handle)
{
    OSPI_v0_HwAttrs const *hwAttrs;
    OSPI_dmaInfo          *pDmaInfo;
    Udma_ChHandle          chHandle;
    int32_t                retVal = UDMA_SOK;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs  = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    pDmaInfo = hwAttrs->dmaInfo;
    chHandle = (Udma_ChHandle)(pDmaInfo->chHandle);
    retVal = Udma_chDisable(chHandle, UDMA_DEFAULT_CH_DISABLE_TIMEOUT);

    /* Unregister master event at the end */
    if(UDMA_SOK == retVal)
    {
        retVal = Udma_eventUnRegister((Udma_EventHandle) pDmaInfo->eventHandle);
    }
    if(UDMA_SOK == retVal)
    {
        retVal = Udma_chClose(chHandle);
    }
}

static void OSPI_dmaIsrHandler(Udma_EventHandle eventHandle,
                               uint32_t         eventType,
                               void            *appData)
{
    int32_t                status = UDMA_SOK;
    SPI_Handle             handle;
    OSPI_v0_Object        *object;
    OSPI_v0_HwAttrs const *hwAttrs;
    OSPI_dmaInfo          *pDmaInfo;
    uint64_t               pDesc = 0;
    Udma_ChHandle          chHandle;
    uint32_t               remainder = 0;
    uint16_t               iCnt[4];
    uint32_t               xferedCnt;
    uint8_t               *srcBuf;
    uint8_t               *destBuf;
    uintptr_t              dataPtr;
    uint32_t               offset;
    bool                   callBack = (bool)false;

    if(appData != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        handle   = (SPI_Handle)appData;
        hwAttrs  = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
        object   = (OSPI_v0_Object *)handle->object;
        pDmaInfo = hwAttrs->dmaInfo;
        chHandle = (Udma_ChHandle)(pDmaInfo->chHandle);

        /* Update the transaction status and word count transfered */
        if (eventType == UDMA_EVENT_TYPE_DMA_COMPLETION)
        {
            /*
             * Dequeue the descriptor from the completion queue
             * to be re-used for the next transfer
             */
            status = Udma_ringDequeueRaw(Udma_chGetCqRingHandle(chHandle), &pDesc);
            if(UDMA_SOK != status)
            {
                /* transfer completed, but dequeue error */
                object->transaction->status = SPI_TRANSFER_FAILED;
                object->transaction->count = 0;
                callBack = (bool)true;
            }
            else
            {
                object->transaction->status = SPI_TRANSFER_COMPLETED;
                if((uint32_t)SPI_TRANSACTION_TYPE_READ == object->transactionType)
                {
                    if (object->readCountIdx > OSPI_DMA_MAX_L0_XFER_SIZE)
                    {
                        /* 1st RX transfer completed with size > 64KB */
                        remainder = object->readCountIdx % OSPI_DMA_XFER_SIZE;
                        xferedCnt = object->readCountIdx - remainder;
                        object->readBufIdx += xferedCnt;
                        object->readCountIdx -= xferedCnt;

                        offset = (uint32_t)(uintptr_t)(object->transaction->arg) + xferedCnt; /* OSPI Flash offset address to write */
                        dataPtr = (uintptr_t)(hwAttrs->dataAddr + offset);
                        srcBuf = (uint8_t *)dataPtr;
                        destBuf = object->readBufIdx;
                    }
                }
                else
                {
                    if (object->writeCountIdx > OSPI_DMA_MAX_L0_XFER_SIZE)
                    {
                        /* 1st RX transfer completed with size > 64KB */
                        remainder = object->writeCountIdx % OSPI_DMA_XFER_SIZE;
                        xferedCnt = object->writeCountIdx - remainder;
                        object->writeBufIdx += xferedCnt;
                        object->writeCountIdx -= xferedCnt;

                        offset = (uint32_t)(uintptr_t)(object->transaction->arg) + xferedCnt; /* OSPI Flash offset address to write */
                        dataPtr = (uintptr_t)(hwAttrs->dataAddr + offset);
                        destBuf = (uint8_t *)dataPtr;
                        srcBuf = object->writeBufIdx;
                    }
                }

                if (remainder != 0U)
                {
                    /* kick off 2nd transfer with remaining bytes */
                    iCnt[0] = (uint16_t)remainder;
                    iCnt[1] = (uint16_t)1U;
                    iCnt[2] = (uint16_t)1U;
                    iCnt[3] = (uint16_t)1U;

                    /* Update TR packet descriptor */
                    OSPI_udmaTrpdInit(chHandle,
                                      (uint8_t *)pDmaInfo->tprdMem,
                                      (const void *)destBuf,
                                      (const void *)srcBuf,
                                      iCnt);

                    /* Submit TRPD to channel */
                    (void)Udma_ringQueueRaw(Udma_chGetFqRingHandle(chHandle), (uint64_t)(pDmaInfo->tprdMem));
                }
                else
                {
                    callBack = (bool)true;
                }
            }
        }
        else
        {
            object->transaction->status = SPI_TRANSFER_FAILED;
            object->transaction->count = 0;
            callBack = (bool)true;
        }
    }

    if (callBack)
    {
        object->ospiParams.transferCallbackFxn(handle, object->transaction);
    }
    (void)eventHandle;
}

