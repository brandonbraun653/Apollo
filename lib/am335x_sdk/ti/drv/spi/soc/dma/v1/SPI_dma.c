/**
 *  \file   SPI_dma.c
 *
 *  \brief  EDMA based McSPI driver for IP verion 1.
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

#include <ti/drv/spi/soc/SPI_v1.h>
#include <ti/sdo/edma3/drv/edma3_drv.h>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#endif

/** Flag to indicate that Reception EDMA callback has occured             */
#define MCSPI_RX_EDMA_CALLBACK_OCCURED    (0x2U)

/** Flag to indicate that Transmission EDMA callback has occured          */
#define MCSPI_TX_EDMA_CALLBACK_OCCURED    (0x1U)

/** SPI 8 bit character length                                            */
#define MCSPI_EDMA_8_BIT_CHAR_LEN         (8U)

/** CNT flag to indicate in EDMA Transfer                                 */
#define MCSPI_ACNT_FLAG                   (2U)

/** Destination flag to indicate in EDMA Transfer                         */
#define MCSPI_DEST_INDEX_FLAG             (1U)

/** Interrupt enable bit in OPT register for edma                         */
#define MCSPI_OPT_TCINTEN_SHIFT           (0x00000014U)

#define MCSPI_MAXLINKCNT                  (2U)
/**<  Maximum number of EDMA jobs linked at a time (Must be 2).           */

/**<  Transmit EDMA channel event queue number                            */
#define MCSPI_TXEVENTQUE                  (0U)

/**<  Receive EDMA channel event queue number                             */
#define MCSPI_RXEVENTQUE                  (1U)

/**<  Generic invalidate status                                           */
#define MCSPI_STATUS_INVALID              (0xFFFF)

/**<  Generic validate status                                             */
#define MCSPI_STATUS_VALID                (0x1)

#define MCSPI_OPT_SYNCDIM_SHIFT           (0x00000002U)
/**<  Sync Type AB set bit of OPT register for edma                       */

#define MCSPI_OPT_TCC_SHIFT               (0x0000000CU)
/**<  TCC set bit in OPT register for edma                                */

#define MCSPI_OPT_TCC_MASK                (0x0003F000U)
/**<  Tcc mask in OPT register for edma                                   */

#define MCSPI_OPT_TCCMOD_SHIFT            (0x0000000BU)
/**< Transfer completion selection bit                                    */

#define MCSPI_CNT_MAX_VAL                 (0xFFFFU)
/**<  Max possible value of aCnt, bCnt and cCnt                           */

#define MCSPI_EDMA3CC_OPT_FIFO_WIDTH      (0xFFFFF8FFU)
/**< Set FIFO Width for edma transfer                                     */

#define MCSPI_EDMA3CC_OPT_SAM_CONST_MODE  (0x00000001U)
/**< Set SAM in Constant Addressing Mode                                  */

#define MCSPI_EDMA3CC_OPT_DAM_CONST_MODE  (0x00000002U)
/**< Set DAM in Constant Addressing Mode                                  */

#define MCSPI_EDMA3CC_OPT_SAM_INCR_MODE   (0xFFFFFFFEU)
/**< Set SAM in Increment Mode                                            */

#define MCSPI_EDMA3CC_OPT_DAM_INCR_MODE   (0xFFFFFFFDU)
/**< Set DAM in Increment Mode                                            */

#define MCSPI_EDMA3CC_OPT_SAM_DAM_INCR_MODE (0xFFFFFFFCU)
/**< Set DAM in Increment Mode                                            */

#define MCSPI_EDMA3CC_OPT_SYNC_AB         (0x00000004U)
/**< It is AB-synchronized                                                */

#define MCSPI_EDMA3CC_OPT_SYNC_MASK_VALUE (0xFFFFFFFFU)
/**< Mask Value for Transfer Synchronization                              */

#define MCSPI_EDMA3CC_PARAM_LINK_ADDRESS  (0xFFFFU)
/**< Set link Address                                                     */

#define MCSPI_EDMA3CC_PARAM_LINK_ADDR_MASK_VALUE (0x0000FFFFU)
/**< link Address Mask Value                                              */

#define MCSPI_EDMA3CC_PARAM_ACNT          (1U)
/**< aCnt Value                                                           */

#define MCSPI_EDMA3CC_OPT_STATIC_SHIFT    (0x00000003U)
/**< STATIC Token                                                         */

#define MCSPI_EDMA3CC_SRC_BINDEX          (1U)
/**< Src BIndex Value                                                     */

#define MCSPI_EDMA3CC_DST_BINDEX          (1U)
/**< Dst BIndex Value                                                     */

#define MCSPI_EDMA3CC_OPT_SYNC_A          (0x01U)
/**< It is A-synchronized                                                 */

#define MCSPI_EDMA3CC_OPT_SYNCDIM_SHIFT   (3U)
/**< Transfer synchronization dimension Shift Value                       */

#define MCSPI_EDMA3CC_COUNT_VALUE         (0xFFFFU)
/**< Count Value                                                          */

/* DMA functions */
static void MCSPI_dmaRxIsrHandler(uint32_t tcc,
                                  EDMA3_RM_TccStatus status,
                                  void* appData);
static void MCSPI_dmaTxIsrHandler(uint32_t tcc,
                                  EDMA3_RM_TccStatus status,
                                  void* appData);
static void MCSPI_dmaDoNothing(uint32_t tcc,
                               EDMA3_RM_TccStatus edmaStatus,
                               void* appData);
static void MCSPI_dmaUpdateParams(MCSPI_Handle mcHandle,
                                  const SPI_Transaction *transaction,
                                  EDMA3_DRV_PaRAMRegs *rxParamSet,
                                  EDMA3_DRV_PaRAMRegs *txParamSet);
static void MCSPI_dmaCompleteIOCallback(MCSPI_Handle mcHandle);

int32_t MCSPI_dmaConfig(MCSPI_Handle mcHandle);
void MCSPI_dmaTransfer(MCSPI_Handle mcHandle, SPI_Transaction *transaction);
void MCSPI_dmaFreeChannel(MCSPI_Handle handle);

int32_t MCSPI_dmaConfig(MCSPI_Handle mcHandle)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_HWAttrs const *hwAttrs;
    uint32_t              tcc = 0;
    static uint32_t       dummyParamSetAddr = 0;
    EDMA3_RM_EventQueue   queueNum    = 0;
    int32_t               status;
    uint32_t              count;
    uint32_t              edmaChanNum = 0;
    uint32_t              reqTcc = EDMA3_DRV_TCC_ANY;

    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    object  = (SPI_v1_Object*)handle->object;
    hwAttrs = (SPI_v1_HWAttrs*)handle->hwAttrs;

    /* RX Section Configuration */

    /* For receive use EDMA Queue 1 and for transmit use EDMA queue 0 */
    queueNum = (EDMA3_RM_EventQueue) MCSPI_RXEVENTQUE;

    status = EDMA3_DRV_requestChannel((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                      (uint32_t *)&(hwAttrs->rxDmaEventNumber),
                                      (uint32_t *)&(hwAttrs->rxDmaEventNumber),
                                      queueNum,
                                      &MCSPI_dmaRxIsrHandler,
                                      (void *)mcHandle);

    /* Acquire the  PaRAM entries used for EDMA transfers linking */
    for (count = 0; count < MCSPI_MAXLINKCNT; count++)
    {
        /* For requesting for a PaRam set */
        edmaChanNum = EDMA3_DRV_LINK_CHANNEL;
        reqTcc      = EDMA3_DRV_TCC_ANY;

        status = EDMA3_DRV_requestChannel((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                          &edmaChanNum,
                                          &reqTcc,
                                          queueNum,
                                          &MCSPI_dmaRxIsrHandler,
                                          NULL);

        if (EDMA3_DRV_SOK == status)
        {
            status = EDMA3_DRV_getPaRAMPhyAddr(
                (EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                edmaChanNum,
                &object->edmaLinkChPhyAddrRx[count]);
        }
    }

    /* TX Section Configuration */

    queueNum = (EDMA3_RM_EventQueue)MCSPI_TXEVENTQUE;

    status = EDMA3_DRV_requestChannel((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                      (uint32_t *)&(hwAttrs->txDmaEventNumber),
                                      (uint32_t *)&(hwAttrs->txDmaEventNumber),
                                      queueNum,
                                      &MCSPI_dmaTxIsrHandler,
                                      (void *)mcHandle);

    /* Acquire the  PaRAM entries used for EDMA transfers linking */
    tcc    = EDMA3_DRV_LINK_CHANNEL;
    reqTcc = EDMA3_DRV_TCC_ANY;

    status = EDMA3_DRV_requestChannel((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                      &tcc,
                                      &reqTcc,
                                      queueNum,
                                      &MCSPI_dmaDoNothing,
                                      NULL);

    status = EDMA3_DRV_getPaRAMPhyAddr((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                       tcc,
                                       &dummyParamSetAddr);


    /* Acquire the  PaRAM entries used for EDMA transfers linking */
    for (count = 0; count < MCSPI_MAXLINKCNT; count++)
    {
        /* For requesting for a PaRam set */
        edmaChanNum = EDMA3_DRV_LINK_CHANNEL;
        reqTcc      = EDMA3_DRV_TCC_ANY;

        status = EDMA3_DRV_requestChannel(
                    (EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                    &edmaChanNum,
                    &reqTcc,
                    queueNum,
                    &MCSPI_dmaTxIsrHandler,
                    NULL);

        status = EDMA3_DRV_getPaRAMPhyAddr(
                    (EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                    edmaChanNum,
                    &object->edmaLinkChPhyAddrTx[count]);
    }

    return status;
}

void MCSPI_dmaTransfer(MCSPI_Handle     mcHandle,
                       SPI_Transaction *transaction)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    uint32_t              chNum;
    SPI_v1_HWAttrs const *hwAttrs;
    EDMA3_DRV_PaRAMRegs   rxParamSet = {0};
    EDMA3_DRV_PaRAMRegs   txParamSet = {0};
    EDMA3_DRV_PaRAMRegs   dummyParamSet = {0};

    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object  = (SPI_v1_Object*)handle->object;
    chObj   = &(object->chObject[chNum]);
    hwAttrs = (SPI_v1_HWAttrs*)handle->hwAttrs;

    /* setup transfer mode and FIFO trigger levels */
    MCSPI_xferSetup_v1(mcHandle, transaction);

    chObj->dmaCbCheck = 0;

    /* receive parameter set */
    EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                        hwAttrs->rxDmaEventNumber,
                        &rxParamSet);

    /* transmit parameter set */
    EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                        hwAttrs->txDmaEventNumber,
                        &txParamSet);

    /* Update param sets based on the transaction parameters */
    MCSPI_dmaUpdateParams(mcHandle,
                          transaction,
                          &rxParamSet,
                          &txParamSet);

    /* Dummy paramSet Configuration */
    EDMA3_DRV_getPaRAM(hwAttrs->edmaHandle,
                       EDMA3_DRV_LINK_CHANNEL,
                       &dummyParamSet);

    dummyParamSet.aCnt     = (uint16_t)MCSPI_EDMA3CC_PARAM_ACNT;
    dummyParamSet.linkAddr = MCSPI_EDMA3CC_PARAM_LINK_ADDRESS;
    dummyParamSet.opt     &= ~((uint32_t)0x01U << MCSPI_EDMA3CC_OPT_STATIC_SHIFT);

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

}

void MCSPI_dmaFreeChannel(MCSPI_Handle mcHandle)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_HWAttrs const *hwAttrs;

    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    object  = (SPI_v1_Object*)handle->object;
    hwAttrs = (SPI_v1_HWAttrs*)handle->hwAttrs;

    EDMA3_DRV_unlinkChannel(hwAttrs->edmaHandle, object->edmaLinkChId);
    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle, object->edmaLinkChId);

    /* Free the DMA TX/RX channels */
    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle, hwAttrs->rxDmaEventNumber);
    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle, hwAttrs->txDmaEventNumber);
}

static void MCSPI_dmaRxIsrHandler(uint32_t           tcc,
                                  EDMA3_RM_TccStatus status,
                                  void*              appData)
{
    MCSPI_Handle          mcHandle;
    uint32_t              chNum;
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    SPI_v1_HWAttrs const *hwAttrs;
    SPI_v1_ChnCfg const  *chnCfg;
    EDMA3_DRV_PaRAMRegs   paramSet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint32_t              bytesRemain;
    uint32_t              intStatus;

    /* Get the pointer to the object and hwAttrs */
    mcHandle = (MCSPI_Handle)appData;
    chNum    = mcHandle->chnNum;
    handle   = mcHandle->handle;
    object   = (SPI_v1_Object*)handle->object;
    chObj    = &(object->chObject[chNum]);
    hwAttrs  = (SPI_v1_HWAttrs*)handle->hwAttrs;
    chnCfg   = &(hwAttrs->chnCfg[chNum]);

    if (EDMA3_RM_XFER_COMPLETE != status)
    {
        /*Error condition  */
        /* Ensure to clear the error bits of EDMA channel */
        EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                 hwAttrs->rxDmaEventNumber);

        /* Get the PaRAM set for default parameters */
        EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                            hwAttrs->rxDmaEventNumber,
                            &paramSet);

        /* calculate the amount of bytes remaining */
        bytesRemain = (paramSet.aCnt * paramSet.bCnt * paramSet.cCnt);

        /* Update the transaction status and word count transfered */
        chObj->transaction->status = SPI_TRANSFER_FAILED;
        chObj->transaction->count -= (bytesRemain >> chObj->wordLenShift);
    }

    /* EDMA Rx is done disable the Rx DMA channel */
    EDMA3_DRV_disableTransfer(hwAttrs->edmaHandle,
                              tcc,
                              EDMA3_DRV_TRIG_MODE_EVENT);

    /* clear the error bits in the EDMA(as this is the last packet)   */
    EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                             (uint32_t)tcc);

    if ((MCSPI_TX_EDMA_CALLBACK_OCCURED == chObj->dmaCbCheck) ||
        (chnCfg->trMode == MCSPI_RX_ONLY_MODE))
    {
        /* Now Both Tx and Rx EDMA Callbacks have happened */
        chObj->dmaCbCheck = 0x0;

        intStatus = McSPIChannelStatusGet((uint32_t)hwAttrs->baseAddr,
                                          chNum);

        /* Clear interrupt error status */
        MCSPI_clearIntErrStatus(mcHandle, intStatus);

        /* Call the completion function */
        MCSPI_dmaCompleteIOCallback(mcHandle);
    }
    else
    {
        if (EDMA3_RM_XFER_COMPLETE == status)
        {
            chObj->dmaCbCheck = MCSPI_RX_EDMA_CALLBACK_OCCURED;
        }
    }
}

static void MCSPI_dmaTxIsrHandler(uint32_t           tcc,
                                  EDMA3_RM_TccStatus status,
                                  void*              appData)
{
    MCSPI_Handle          mcHandle;
    uint32_t              chNum;
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    SPI_v1_HWAttrs const *hwAttrs;
    SPI_v1_ChnCfg const  *chnCfg;
    EDMA3_DRV_PaRAMRegs   paramSet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint32_t              bytesRemain;
    uint32_t              intStatus;

    /* Get the pointer to the object and hwAttrs */
    mcHandle = (MCSPI_Handle)appData;
    chNum    = mcHandle->chnNum;
    handle   = mcHandle->handle;
    object   = (SPI_v1_Object*)handle->object;
    chObj    = &(object->chObject[chNum]);
    hwAttrs  = (SPI_v1_HWAttrs*)handle->hwAttrs;
    chnCfg   = &(hwAttrs->chnCfg[chNum]);

    if (EDMA3_RM_XFER_COMPLETE != status)
    {
        /* Ensure to clear the error bits of EDMA channel */
        EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                                 hwAttrs->txDmaEventNumber);

        /* Get the PaRAM set for default parameters */
        EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                            hwAttrs->txDmaEventNumber,
                            &paramSet);

        /* calculate the amount of bytes remaining */
        bytesRemain = (paramSet.aCnt * paramSet.bCnt * paramSet.cCnt);

        /* Update the transaction status and word count transfered */
        chObj->transaction->status = SPI_TRANSFER_FAILED;
        chObj->transaction->count -= (bytesRemain >> chObj->wordLenShift);
    }

    /* EDMA Rx is done disable the Rx DMA channel */
    EDMA3_DRV_disableTransfer(hwAttrs->edmaHandle,
                              tcc,
                              EDMA3_DRV_TRIG_MODE_EVENT);

    /* clear the error bits in the EDMA */
    EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                             (uint32_t) tcc);

    if ((MCSPI_RX_EDMA_CALLBACK_OCCURED == chObj->dmaCbCheck) ||
        (chnCfg->trMode == MCSPI_TX_ONLY_MODE))
    {
        chObj->dmaCbCheck = 0x0;

        intStatus = McSPIChannelStatusGet((uint32_t) hwAttrs->baseAddr,
                                          chNum);

        /* Clear interrupt error status */
        MCSPI_clearIntErrStatus(mcHandle, intStatus);

        /* Call the completion function */
        MCSPI_dmaCompleteIOCallback(mcHandle);
    }
    else
    {
        if (EDMA3_RM_XFER_COMPLETE == status)
        {
            chObj->dmaCbCheck = MCSPI_TX_EDMA_CALLBACK_OCCURED;
        }
    }
}

static void MCSPI_dmaDoNothing(uint32_t           tcc,
                               EDMA3_RM_TccStatus edmaStatus,
                               void*              appData)
{
    /* No implementation required */
}

static void MCSPI_dmaUpdateParams(MCSPI_Handle           mcHandle,
                                  const SPI_Transaction *transaction,
                                  EDMA3_DRV_PaRAMRegs   *rxParamSet,
                                  EDMA3_DRV_PaRAMRegs   *txParamSet)
{
    SPI_Handle            handle;
    uint32_t              chNum;
    SPI_v1_HWAttrs const *hwAttrs;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;

    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    hwAttrs = (SPI_v1_HWAttrs*)handle->hwAttrs;
    object  = (SPI_v1_Object*)handle->object;
    chObj   = &(object->chObject[chNum]);

    /* Receive param set configuration */

    /* Source address */
    rxParamSet->srcAddr =  hwAttrs->baseAddr + MCSPI_CHRX(chNum);

    /* destAddr is address of memory location named buffer.*/
    rxParamSet->destAddr = (uint32_t) transaction->rxBuf;

    if (chObj->readCountIdx != 0)
    {
        /* aCnt holds the number of bytes in an array.*/
        rxParamSet->aCnt = (uint16_t)(1 << chObj->wordLenShift);

        /* bCnt holds the number of such arrays to be transferred.*/
        rxParamSet->bCnt = (uint16_t)(object->rxTrigLvl >> chObj->wordLenShift);

        /* cCnt holds the number of frames of aCnt*bBcnt bytes to be transferred.*/
        rxParamSet->cCnt = (uint16_t)(transaction->count / rxParamSet->bCnt);

    }
    else
    {
        /* No transfer on RX channel */
        rxParamSet->aCnt = (uint16_t)0;
        rxParamSet->bCnt = (uint16_t)0;
        rxParamSet->cCnt = (uint16_t)0;

    }

    /* The srcBidx should not be incremented since it is a h/w register.*/
    rxParamSet->srcBIdx = 0;

    if(NULL != transaction->rxBuf)
    {
        /* The destBidx should be incremented for every byte.*/
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
    rxParamSet->destCIdx = object->rxTrigLvl;

    /* Linking transfers in EDMA3 are not used.*/
    rxParamSet->linkAddr = 0xFFFF;

    rxParamSet->bCntReload = rxParamSet->bCnt;

    /* By default SAM and DAM bits are set to INCR mode                  */
    rxParamSet->opt &= 0xFFFFFFFCU;

    if (NULL == transaction->rxBuf)
    {
        /* Since the EDMA is using the driver internal buffer, so no need to
         * increment the buffer. INCR mode is disabled
         */
        rxParamSet->opt |= MCSPI_EDMA3CC_OPT_DAM_CONST_MODE;
    }

    /* FIFO width is 8 bit                                               */
    rxParamSet->opt &= 0xFFFFF8FFU;

    /* EDMA3_DRV_SYNC_AB                                                 */
    rxParamSet->opt &= MCSPI_EDMA3CC_OPT_SYNC_MASK_VALUE;
    rxParamSet->opt |= MCSPI_EDMA3CC_OPT_SYNC_AB;

    /* EDMA3_DRV_OPT_FIELD_TCINTEN                                       */
    rxParamSet->opt |= 1U << MCSPI_OPT_TCINTEN_SHIFT;

    /* update the transfer completion code                               */
    rxParamSet->opt &= (~MCSPI_OPT_TCC_MASK);
    rxParamSet->opt |= ((hwAttrs->rxDmaEventNumber) <<
                        MCSPI_OPT_TCC_SHIFT);

    /* Transmit param set configuration */

    /* srcAddr holds address of memory location buffer. */
    txParamSet->srcAddr = (uint32_t) transaction->txBuf;

    /* destAddr holds address of McSPI_TX register. */
    txParamSet->destAddr = (uint32_t) hwAttrs->baseAddr +
                           MCSPI_CHTX(chNum);

    if (chObj->writeCountIdx != 0)
    {
        /* aCnt holds the number of bytes in an array. */
        txParamSet->aCnt = (uint16_t)(1 << chObj->wordLenShift);

        /* bCnt holds the number of such arrays to be transferred. */
        txParamSet->bCnt = (uint16_t)(object->txTrigLvl >> chObj->wordLenShift);

        /* cCnt holds the number of frames of aCnt*bBcnt bytes to be transferred. */
        txParamSet->cCnt = (uint16_t)(transaction->count / txParamSet->bCnt);
    }
    else
    {
        /* No transfer on RX channel */
        txParamSet->aCnt = (uint16_t)0;
        txParamSet->bCnt = (uint16_t)0;
        txParamSet->cCnt = (uint16_t)0;
    }

    /*
    ** The srcBidx should be incremented by aCnt number of bytes since the
    ** source used here is memory.
    */
    txParamSet->srcBIdx = txParamSet->aCnt;
    txParamSet->destBIdx = 0;

    /* Async Transfer Mode is set in OPT.*/
    /* srCIdx and destCIdx set to zero since ASYNC Mode is used. */
    txParamSet->srcCIdx = object->txTrigLvl;
    txParamSet->destCIdx = 0;

    /* Linking transfers in EDMA3 are not used. */
    txParamSet->linkAddr = MCSPI_EDMA3CC_PARAM_LINK_ADDRESS;
    txParamSet->bCntReload = txParamSet->bCnt;

    /* By default SAM and DAM bits are set to INCR mode                  */
    txParamSet->opt &= MCSPI_EDMA3CC_OPT_SAM_DAM_INCR_MODE;

    if (NULL == transaction->txBuf)
    {
        /* Since the EDMA is using the driver internal buffer, so no need to
         * increment the buffer. INCR mode is disabled.
         */
        txParamSet->opt |= MCSPI_EDMA3CC_OPT_SAM_CONST_MODE;
    }

    /* FIFO width is 8 bit                                               */
    txParamSet->opt &= MCSPI_EDMA3CC_OPT_FIFO_WIDTH;

    /* EDMA3_DRV_SYNC_AB                                                 */
    txParamSet->opt &= MCSPI_EDMA3CC_OPT_SYNC_MASK_VALUE;
    txParamSet->opt |= MCSPI_EDMA3CC_OPT_SYNC_AB;

    /* EDMA3_DRV_OPT_FIELD_TCINTEN                                       */
    txParamSet->opt |= (1U << MCSPI_OPT_TCINTEN_SHIFT);

    /* update the transfer completion code                               */
    txParamSet->opt &= (~MCSPI_OPT_TCC_MASK);
    txParamSet->opt |= ((hwAttrs->txDmaEventNumber) <<
                        MCSPI_OPT_TCC_SHIFT);
}

static void MCSPI_dmaCompleteIOCallback(MCSPI_Handle mcHandle)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    SPI_v1_HWAttrs const *hwAttrs;
    uint32_t              chNum;

    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object  = (SPI_v1_Object*)handle->object;
    chObj   = &(object->chObject[chNum]);
    hwAttrs = (SPI_v1_HWAttrs*)handle->hwAttrs;

    /* disable all the spi transfers */
    McSPIChannelDisable((uint32_t) hwAttrs->baseAddr, chNum);

    /* Clear all the interrupts here, only related to the perticular
     * channel
     */
    MCSPI_clearIntStatus(mcHandle);

    if ((SPI_MASTER == chObj->spiParams.mode) &&
        (hwAttrs->chMode == MCSPI_SINGLE_CH))
    {
        /* Deassert chip select signal */
        McSPICSDeAssert(hwAttrs->baseAddr, chNum);
    }

    EDMA3_DRV_disableTransfer(hwAttrs->edmaHandle,
                              hwAttrs->txDmaEventNumber,
                              EDMA3_DRV_TRIG_MODE_EVENT);

    EDMA3_DRV_disableTransfer(hwAttrs->edmaHandle,
                              hwAttrs->rxDmaEventNumber,
                              EDMA3_DRV_TRIG_MODE_EVENT);

    /* Call the transfer completion callback function */
    chObj->transaction->status = SPI_TRANSFER_COMPLETED;
    MCSPI_transferCallback_v1(mcHandle, chObj->transaction);
}

