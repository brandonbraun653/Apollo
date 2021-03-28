/**
 *  \file   SPI_dma.c
 *
 *  \brief  EDMA based SPI driver for IP verion 0
 *
 */

/*
 * Copyright (c) 2017, Texas Instruments Incorporated
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
#include <ti/sdo/edma3/drv/edma3_drv.h>

#define SPI_RX_EDMA_CALLBACK_OCCURED    (0x2U)
/**< Flag to indicate that Reception EDMA callback has occured            */

#define SPI_TX_EDMA_CALLBACK_OCCURED    (0x1U)
/**< Flag to indicate that Transmission EDMA callback has occured         */

#define SPI_MAXLINKCNT                  (2U)
/**<  Maximum number of EDMA jobs linked at a time (Must be 2).           */

/**<  Transmit EDMA channel event queue number                            */
#define SPI_TXEVENTQUE                  (0U)

/**<  Receive EDMA channel event queue number                             */
#define SPI_RXEVENTQUE                  (1U)


#define SPI_OPT_TCINTEN_SHIFT           (0x00000014U)
/**< Interrupt enable bit in OPT register for edma                        */

#define SPI_OPT_TCC_SHIFT               (0x0000000CU)
/**<  TCC set bit in OPT register for edma                                */

#define SPI_OPT_TCC_MASK                (0x0003F000U)
/**<  Tcc mask in OPT register for edma                                   */

#define SPI_EDMA3CC_OPT_FIFO_WIDTH      (0xFFFFF8FFU)
/**< Set FIFO Width for edma transfer                                     */

#define SPI_EDMA3CC_OPT_SAM_CONST_MODE  (0x00000001U)
/**< Set SAM in Constant Addressing Mode                                  */

#define SPI_EDMA3CC_OPT_DAM_CONST_MODE  (0x00000002U)
/**< Set DAM in Constant Addressing Mode                                  */

#define SPI_EDMA3CC_OPT_SAM_INCR_MODE   (0xFFFFFFFEU)
/**< Set SAM in Increment Mode                                            */

#define SPI_EDMA3CC_OPT_DAM_INCR_MODE   (0xFFFFFFFDU)
/**< Set DAM in Increment Mode                                            */

#define SPI_EDMA3CC_OPT_SAM_DAM_INCR_MODE (0xFFFFFFFCU)
/**< Set DAM in Increment Mode                                            */

#define SPI_EDMA3CC_OPT_SYNC_AB         (0x00000004U)
/**< It is AB-synchronized                                                */

#define SPI_EDMA3CC_OPT_SYNC_MASK_VALUE (0xFFFFFFFFU)
/**< Mask Value for Transfer Synchronization                              */

#define SPI_EDMA3CC_PARAM_LINK_ADDRESS  (0xFFFFU)
/**< Set link Address                                                     */

#define SPI_EDMA3CC_PARAM_ACNT          (1U)
/**< aCnt Value                                                           */

#define SPI_EDMA3CC_OPT_STATIC_SHIFT    (0x00000003U)
/**< STATIC Token                                                         */

#define SPI_EDMA3CC_SRC_BINDEX          (1U)
/**< Src BIndex Value                                                     */

#define SPI_EDMA3CC_DST_BINDEX          (1U)
/**< Dst BIndex Value                                                     */

#define SPI_EDMA3CC_OPT_SYNC_A          (0x01U)
/**< It is A-synchronized                                                 */

#define SPI_EDMA3CC_OPT_SYNCDIM_SHIFT   (3U)
/**< Transfer synchronization dimension Shift Value                       */

#define SPI_EDMA3CC_COUNT_VALUE         (0xFFFFU)
/**< Count Value                                                          */


/* SPI DMA functions */
static void SPI_dmaRxIsrHandler(uint32_t tcc,
                                EDMA3_RM_TccStatus status,
                                void* appData);
static void SPI_dmaTxIsrHandler(uint32_t tcc,
                                EDMA3_RM_TccStatus status,
                                void* appData);
static void SPI_dmaDoNothing(uint32_t tcc,
                             EDMA3_RM_TccStatus edmaStatus,
                                 void* appData);
static void SPI_dmaUpdateParams(SPI_Handle handle,
                                const SPI_Transaction *transaction,
                                EDMA3_DRV_PaRAMRegs *rxParamSet,
                                EDMA3_DRV_PaRAMRegs *txParamSet);
static void SPI_dmaCallback(SPI_Handle handle);

int32_t SPI_dmaConfig(SPI_Handle handle);
void SPI_dmaTransfer(SPI_Handle handle, SPI_Transaction *transaction);
void SPI_dmaDisableChannel(SPI_Handle handle, bool txChan);
void SPI_dmaFreeChannel(SPI_Handle handle);

int32_t SPI_dmaConfig(SPI_Handle handle)
{
    SPI_HWAttrs const   *hwAttrs;
    uint32_t             tcc = 0;
    static uint32_t      dummyParamSetAddr = 0;
    EDMA3_RM_EventQueue  queueNum = 0;
    int32_t              status;
    uint32_t             count;
    uint32_t             edmaChanNum = 0;
    uint32_t             reqTcc = EDMA3_DRV_TCC_ANY;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (SPI_HWAttrs*)handle->hwAttrs;

    /* RX Section Configuration */

    /* For receive use EDMA Queue 1 and for transmit use EDMA queue 0 */
    queueNum = (EDMA3_RM_EventQueue) SPI_RXEVENTQUE;

    status = EDMA3_DRV_requestChannel((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                      (uint32_t *)&(hwAttrs->rxDmaEventNumber),
                                      (uint32_t *)&(hwAttrs->rxDmaEventNumber),
                                      queueNum,
                                      &SPI_dmaRxIsrHandler,
                                      (void *)handle);

    /* Acquire the  PaRAM entries used for EDMA transfers linking */
    for (count = 0; count < SPI_MAXLINKCNT; count++)
    {
        /* For requesting for a PaRam set */
        edmaChanNum = EDMA3_DRV_LINK_CHANNEL;
        reqTcc      = EDMA3_DRV_TCC_ANY;

        status = EDMA3_DRV_requestChannel((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                          &edmaChanNum,
                                          &reqTcc,
                                          queueNum,
                                          &SPI_dmaRxIsrHandler,
                                          NULL);
    }

    /* TX Section Configuration */

    queueNum = (EDMA3_RM_EventQueue)SPI_TXEVENTQUE;

    status = EDMA3_DRV_requestChannel((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                      (uint32_t *)&(hwAttrs->txDmaEventNumber),
                                      (uint32_t *)&(hwAttrs->txDmaEventNumber),
                                      queueNum,
                                      &SPI_dmaTxIsrHandler,
                                      (void *)handle);

    /* Acquire the  PaRAM entries used for EDMA transfers linking */
    tcc    = EDMA3_DRV_LINK_CHANNEL;
    reqTcc = EDMA3_DRV_TCC_ANY;

    status = EDMA3_DRV_requestChannel((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                      &tcc,
                                      &reqTcc,
                                      queueNum,
                                      &SPI_dmaDoNothing,
                                      NULL);

    status = EDMA3_DRV_getPaRAMPhyAddr((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                       tcc,
                                       &dummyParamSetAddr);


    /* Acquire the  PaRAM entries used for EDMA transfers linking */
    for (count = 0; count < SPI_MAXLINKCNT; count++)
    {
        /* For requesting for a PaRam set */
        edmaChanNum = EDMA3_DRV_LINK_CHANNEL;
        reqTcc      = EDMA3_DRV_TCC_ANY;

        status = EDMA3_DRV_requestChannel(
                    (EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                    &edmaChanNum,
                    &reqTcc,
                    queueNum,
                    &SPI_dmaTxIsrHandler,
                    NULL);
    }

    return(status);
}

void SPI_dmaTransfer(SPI_Handle       handle,
                     SPI_Transaction *transaction)
{
    SPI_HWAttrs   const *hwAttrs;
    SPI_v0_Object       *object;
    EDMA3_DRV_PaRAMRegs  rxParamSet = {0};
    EDMA3_DRV_PaRAMRegs  txParamSet = {0};
    EDMA3_DRV_PaRAMRegs  dummyParamSet = {0};

    /* Get the pointer to the object and hwAttrs */
    object  = (SPI_v0_Object*)handle->object;
    hwAttrs = (SPI_HWAttrs*)handle->hwAttrs;

    object->edmaCbCheck = 0;

    /* receive parameter set */
    EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                        hwAttrs->rxDmaEventNumber,
                        &rxParamSet);

    /* transmit parameter set */
    EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                        hwAttrs->txDmaEventNumber,
                        &txParamSet);

    /* Update param sets based on the transaction parameters */
    SPI_dmaUpdateParams(handle,
                        transaction,
                        &rxParamSet,
                        &txParamSet);

    /* Dummy paramSet Configuration */
    EDMA3_DRV_getPaRAM(hwAttrs->edmaHandle,
                       EDMA3_DRV_LINK_CHANNEL,
                       &dummyParamSet);

    dummyParamSet.aCnt     = SPI_EDMA3CC_PARAM_ACNT;
    dummyParamSet.linkAddr = SPI_EDMA3CC_PARAM_LINK_ADDRESS;
    dummyParamSet.opt     &= ~((uint32_t)0x01U << SPI_EDMA3CC_OPT_STATIC_SHIFT);

    /* Now, write the PaRAM Set. */
    EDMA3_DRV_setPaRAM(hwAttrs->edmaHandle,
                       EDMA3_DRV_LINK_CHANNEL,
                       &dummyParamSet);

    /* Write Rx param set */
    EDMA3_DRV_setPaRAM((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                        hwAttrs->rxDmaEventNumber,
                        &rxParamSet);

    /* Write Tx param set */
    EDMA3_DRV_setPaRAM((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                       hwAttrs->txDmaEventNumber,
                       &txParamSet);

    /* Link the Dummy paramset */
    EDMA3_DRV_linkChannel(hwAttrs->edmaHandle,
                          hwAttrs->txDmaEventNumber,
                          EDMA3_DRV_LINK_CHANNEL);

    /* Program the RX side */
    EDMA3_DRV_enableTransfer(hwAttrs->edmaHandle,
                             hwAttrs->rxDmaEventNumber,
                             EDMA3_DRV_TRIG_MODE_EVENT);

    /* Program the TX side */
    EDMA3_DRV_enableTransfer(hwAttrs->edmaHandle,
                             hwAttrs->txDmaEventNumber,
                             EDMA3_DRV_TRIG_MODE_EVENT);

    /* Enable SPI DMA for transaction */
    SPIIntEnable(hwAttrs->baseAddr, SPI_INT_DMA_ENABLE);
}

void SPI_dmaDisableChannel(SPI_Handle handle, bool txChan)
{
    SPI_HWAttrs const *hwAttrs = (SPI_HWAttrs*)handle->hwAttrs;
    uint32_t           dmaEvent;

    if (txChan == true)
    {
        dmaEvent = (uint32_t) hwAttrs->txDmaEventNumber;
    }
    else
    {
        dmaEvent = (uint32_t) hwAttrs->rxDmaEventNumber;
    }

    EDMA3_DRV_disableLogicalChannel(
            (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
            dmaEvent,
            (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);
}

void SPI_dmaFreeChannel(SPI_Handle handle)
{
    SPI_HWAttrs const *hwAttrs = (SPI_HWAttrs*)handle->hwAttrs;

    /* Unlink and free the channels */
    EDMA3_DRV_unlinkChannel(hwAttrs->edmaHandle, EDMA3_DRV_LINK_CHANNEL);
    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle, EDMA3_DRV_LINK_CHANNEL);

    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle, hwAttrs->rxDmaEventNumber);
    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle, hwAttrs->txDmaEventNumber);
}

static void SPI_dmaRxIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData)
{
    SPI_Handle           handle;
    SPI_v0_Object       *object;
    SPI_HWAttrs const   *hwAttrs;
    EDMA3_DRV_PaRAMRegs  paramSet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    /* Get the pointer to the object and hwAttrs */
    handle   = (SPI_Handle)appData;
    object   = (SPI_v0_Object*)handle->object;
    hwAttrs  = (SPI_HWAttrs*)handle->hwAttrs;

    if (EDMA3_RM_XFER_COMPLETE != status)
    {
        /* Error condition  */
        /* Ensure to clear the error bits of EDMA channel */
        EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                 hwAttrs->rxDmaEventNumber);

        /* Get the PaRAM set for default parameters */
        EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                            hwAttrs->rxDmaEventNumber,
                            &paramSet);

        /* Update the transaction status and word count transfered */
        object->transaction->status = SPI_TRANSFER_FAILED;
        object->transaction->count -= paramSet.bCnt;
    }

    /* EDMA Rx is done disable the Rx DMA channel */
    EDMA3_DRV_disableTransfer(hwAttrs->edmaHandle,
                              tcc,
                              EDMA3_DRV_TRIG_MODE_EVENT);

    /* clear the error bits in the EDMA(as this is the last packet)   */
    EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                             (uint32_t)tcc);

    if (SPI_TX_EDMA_CALLBACK_OCCURED == object->edmaCbCheck)
    {
        object->edmaCbCheck = 0x0;

        /* Call the completion function */
        SPI_dmaCallback(handle);
    }
    else
    {
        if (EDMA3_RM_XFER_COMPLETE == status)
        {
            object->edmaCbCheck = SPI_RX_EDMA_CALLBACK_OCCURED;
        }
    }

}

static void SPI_dmaTxIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData)
{
    SPI_Handle           handle;
    SPI_v0_Object       *object;
    SPI_HWAttrs const   *hwAttrs;
    EDMA3_DRV_PaRAMRegs  paramSet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    /* Get the pointer to the object and hwAttrs */
    handle   = (SPI_Handle)appData;
    object   = (SPI_v0_Object*)handle->object;
    hwAttrs  = (SPI_HWAttrs*)handle->hwAttrs;

    if (EDMA3_RM_XFER_COMPLETE != status)
    {
        /* Ensure to clear the error bits of EDMA channel */
        EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                                 hwAttrs->txDmaEventNumber);

        /* Get the PaRAM set for default parameters */
        EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                            hwAttrs->txDmaEventNumber,
                            &paramSet);

        /* Update the transaction status and word count transfered */
        object->transaction->status = SPI_TRANSFER_FAILED;
        object->transaction->count -= paramSet.bCnt;
    }

    /* EDMA Rx is done disable the Rx DMA channel */
    EDMA3_DRV_disableTransfer(hwAttrs->edmaHandle,
                              tcc,
                              EDMA3_DRV_TRIG_MODE_EVENT);

    /* clear the error bits in the EDMA */
    EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                             (uint32_t) tcc);

    if (SPI_RX_EDMA_CALLBACK_OCCURED == object->edmaCbCheck)
    {
        object->edmaCbCheck = 0x0;

        /* Call the completion function */
        SPI_dmaCallback(handle);
    }
    else
    {
        if (EDMA3_RM_XFER_COMPLETE == status)
        {
            object->edmaCbCheck = SPI_TX_EDMA_CALLBACK_OCCURED;
        }
    }
}

static void SPI_dmaDoNothing(uint32_t           tcc,
                             EDMA3_RM_TccStatus edmaStatus,
                             void*              appData)
{
    /* No implementation required */
}

static void SPI_dmaUpdateParams(SPI_Handle             handle,
                                const SPI_Transaction *transaction,
                                EDMA3_DRV_PaRAMRegs   *rxParamSet,
                                EDMA3_DRV_PaRAMRegs   *txParamSet)
{
    SPI_HWAttrs const *hwAttrs;
    SPI_v0_Object     *object;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (SPI_HWAttrs*)handle->hwAttrs;
    object  = (SPI_v0_Object*)handle->object;

    /* Receive param set configuration */

    /* Source address */
    rxParamSet->srcAddr = (uint32_t) ((hwAttrs->baseAddr) + CSL_SPI_SPIBUF);

    /* destAddr is address of memory location named buffer.*/
    rxParamSet->destAddr = (uint32_t) transaction->rxBuf;

    /* aCnt holds the number of bytes in an array.*/
    if (object->frameSize == SPI_v0_8bit)
    {
        /* 8-bit word length */
        rxParamSet->aCnt = 1;
    }
    else
    {
        /* 16-bit word length */
        rxParamSet->aCnt = 2;
    }

    /* bCnt holds the number of such arrays to be transferred.*/
    rxParamSet->bCnt = transaction->count;

    /* cCnt holds the number of frames of aCnt*bBcnt bytes to be transferred.*/
    rxParamSet->cCnt = 1;

    /* The srcBidx should not be incremented since it is a h/w register.*/
    rxParamSet->srcBIdx = 0;

    if(NULL != transaction->rxBuf)
    {
        /* The destBidx should be incremented aCnt number of bytes.*/
        rxParamSet->destBIdx = rxParamSet->aCnt;
    }
    else
    {
        /* The destBidx should not be incremented.*/
        rxParamSet->destBIdx = 0;
    }

    /* A sync Transfer Mode. */
    /* srCIdx and destCIdx set to zero since ASYNC Mode is used.*/
    rxParamSet->srcCIdx = 0;
    rxParamSet->destCIdx = 0;

    /* Linking transfers in EDMA3 are not used.*/
    rxParamSet->linkAddr = 0xFFFF;

    rxParamSet->bCntReload = 0;

    rxParamSet->opt = 0x00000000;

    /* EDMA3_DRV_OPT_FIELD_TCINTEN */
    rxParamSet->opt |= (uint32_t) 1U << SPI_OPT_TCINTEN_SHIFT;

    /* update the transfer completion code */
    rxParamSet->opt &= (~SPI_OPT_TCC_MASK);
    rxParamSet->opt |= ((hwAttrs->rxDmaEventNumber) <<
                        SPI_OPT_TCC_SHIFT);


    /* Transmit param set configuration */

    /* srcAddr holds address of memory location buffer. */
    txParamSet->srcAddr = (uint32_t) transaction->txBuf;

    /* destAddr holds address of SPIDAT1 register. */
    txParamSet->destAddr = (uint32_t) ((hwAttrs->baseAddr) + CSL_SPI_SPIDAT0);

    /* aCnt holds the number of bytes in an array. */
    if (object->frameSize == SPI_v0_8bit)
    {
        /* 8-bit word length */
        txParamSet->aCnt = 1;
    }
    else
    {
        /* 16-bit word length */
        txParamSet->aCnt = 2;
    }

    /* bCnt holds the number of such arrays to be transferred. */
    txParamSet->bCnt = transaction->count;

    /* cCnt holds the number of frames of aCnt*bBcnt bytes to be transferred. */
    txParamSet->cCnt = 1;

    /*
    ** The srcBidx should be incremented by aCnt number of bytes since the
    ** source used here is memory.
    */
    txParamSet->srcBIdx = txParamSet->aCnt;
    txParamSet->destBIdx = 0;

    /* Async Transfer Mode is set in OPT.*/
    /* srCIdx and destCIdx set to zero since ASYNC Mode is used. */
    txParamSet->srcCIdx = 0;
    txParamSet->destCIdx = 0;

    /* Linking transfers in EDMA3 are not used. */
    txParamSet->linkAddr = SPI_EDMA3CC_PARAM_LINK_ADDRESS;
    txParamSet->bCntReload = 0;

    txParamSet->opt = 0x00000000;

    /* EDMA3_DRV_OPT_FIELD_TCINTEN */
    txParamSet->opt |= ((uint32_t) 1 << SPI_OPT_TCINTEN_SHIFT);

    /* update the transfer completion code */
    txParamSet->opt &= (~SPI_OPT_TCC_MASK);
    txParamSet->opt |= ((hwAttrs->txDmaEventNumber) <<
                        SPI_OPT_TCC_SHIFT);
}


static void SPI_dmaCallback(SPI_Handle handle)
{
    SPI_v0_Object     *object;
    SPI_HWAttrs const *hwAttrs;

    /* Get the pointer to the object and hwAttrs */
    object  = (SPI_v0_Object*)handle->object;
    hwAttrs = (SPI_HWAttrs*)handle->hwAttrs;

    EDMA3_DRV_disableTransfer(hwAttrs->edmaHandle,
                              hwAttrs->txDmaEventNumber,
                              EDMA3_DRV_TRIG_MODE_EVENT);

    EDMA3_DRV_disableTransfer(hwAttrs->edmaHandle,
                              hwAttrs->rxDmaEventNumber,
                              EDMA3_DRV_TRIG_MODE_EVENT);

    /* Call the transfer completion callback function */
    if ((object->transaction->status != SPI_TRANSFER_FAILED) &&
        (object->transferErr == SPI_XFER_ERR_NONE))
    {
        object->transaction->status = SPI_TRANSFER_COMPLETED;
    }
    else
    {
        object->transaction->status = SPI_TRANSFER_FAILED;
    }
    object->transferCallbackFxn(handle, object->transaction);
    object->transaction = NULL;
}

