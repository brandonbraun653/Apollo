/**
 *  \file   QSPI_dma.c
 *
 *  \brief  EDMA based QSPI driver for IP verion 1.
 *
 *   This file contains the EDMA driver APIs for QSPI.
 */

/*
 * Copyright (c) 2019, Texas Instruments Incorporated
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

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#endif

/** Flag to indicate that Reception EDMA callback has occured             */
#define QSPI_RX_EDMA_CALLBACK_OCCURED    (0x2U)

/** Flag to indicate that Transmission EDMA callback has occured          */
#define QSPI_TX_EDMA_CALLBACK_OCCURED    (0x1U)

/** SPI 8 bit character length                                            */
#define QSPI_EDMA_8_BIT_CHAR_LEN         (8U)

/** CNT flag to indicate in EDMA Transfer                                 */
#define QSPI_ACNT_FLAG                   (2U)

/** Destination flag to indicate in EDMA Transfer                         */
#define QSPI_DEST_INDEX_FLAG             (1U)

/** Interrupt enable bit in OPT register for edma                         */
#define QSPI_OPT_TCINTEN_SHIFT           (0x00000014U)
#define QSPI_OPT_ITCINTEN_SHIFT          (0x00000015U)

#define QSPI_MAXLINKCNT                  (2U)
/**<  Maximum number of EDMA jobs linked at a time (Must be 2).           */

/**<  EDMA channel event queue number                                     */
#define QSPI_EVENTQUE                    (0U)

/**<  Generic invalidate status                                           */
#define QSPI_STATUS_INVALID              (0xFFFF)

/**<  Generic validate status                                             */
#define QSPI_STATUS_VALID                (0x1)

#define QSPI_OPT_SYNCDIM_SHIFT           (0x00000002U)
/**<  Sync Type AB set bit of OPT register for edma                       */

#define QSPI_OPT_TCC_SHIFT               (0x0000000CU)
/**<  TCC set bit in OPT register for edma                                */

#define QSPI_OPT_TCC_MASK                (0x0003F000U)
/**<  Tcc mask in OPT register for edma                                   */

#define QSPI_OPT_TCCMOD_SHIFT            (0x0000000BU)
/**< Transfer completion selection bit                                    */

#define QSPI_CNT_MAX_VAL                 (0xFFFFU)
/**<  Max possible value of aCnt, bCnt and cCnt                           */

#define QSPI_EDMA3CC_OPT_FIFO_WIDTH      (0xFFFFF8FFU)
/**< Set FIFO Width for edma transfer                                     */

#define QSPI_EDMA3CC_OPT_SAM_CONST_MODE  (0x00000001U)
/**< Set SAM in Constant Addressing Mode                                  */

#define QSPI_EDMA3CC_OPT_DAM_CONST_MODE  (0x00000002U)
/**< Set DAM in Constant Addressing Mode                                  */

#define QSPI_EDMA3CC_OPT_SAM_INCR_MODE   (0xFFFFFFFEU)
/**< Set SAM in Increment Mode                                            */

#define QSPI_EDMA3CC_OPT_DAM_INCR_MODE   (0xFFFFFFFDU)
/**< Set DAM in Increment Mode                                            */

#define QSPI_EDMA3CC_OPT_SAM_DAM_INCR_MODE (0xFFFFFFFCU)
/**< Set DAM in Increment Mode                                            */

#define QSPI_EDMA3CC_OPT_SYNC_AB         (0x00000004U)
/**< It is AB-synchronized                                                */

#define QSPI_EDMA3CC_OPT_SYNC_MASK_VALUE (0xFFFFFFFFU)
/**< Mask Value for Transfer Synchronization                              */

#define QSPI_EDMA3CC_PARAM_LINK_ADDRESS  (0xFFFFU)
/**< Set link Address                                                     */

#define QSPI_EDMA3CC_PARAM_LINK_ADDR_MASK_VALUE (0x0000FFFFU)
/**< link Address Mask Value                                              */

#define QSPI_EDMA3CC_PARAM_ACNT          (1U)
/**< aCnt Value                                                           */

#define QSPI_EDMA3CC_OPT_STATIC_SHIFT    (0x00000003U)
/**< STATIC Token                                                         */

#define QSPI_EDMA3CC_SRC_BINDEX          (1U)
/**< Src BIndex Value                                                     */

#define QSPI_EDMA3CC_DST_BINDEX          (1U)
/**< Dst BIndex Value                                                     */

#define QSPI_EDMA3CC_OPT_SYNC_A          (0x01U)
/**< It is A-synchronized                                                 */

#define QSPI_EDMA3CC_OPT_SYNCDIM_SHIFT   (3U)
/**< Transfer synchronization dimension Shift Value                       */

#define QSPI_EDMA3CC_COUNT_VALUE         (0xFFFFU)
/**< Count Value                                                          */

/* DMA functions */
static void QSPI_dmaIsrHandler(uint32_t tcc,
                               EDMA3_RM_TccStatus status,
                               void* appData);

int32_t QSPI_dmaConfig(SPI_Handle handle);
int32_t QSPI_dmaTransfer(SPI_Handle handle, const SPI_Transaction *transaction);
int32_t QSPI_dmaFreeChannel(SPI_Handle handle);

int32_t QSPI_dmaConfig(SPI_Handle handle)
{
    QSPI_HwAttrs         *hwAttrs;
    EDMA3_DRV_Result      status;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (QSPI_HwAttrs*)handle->hwAttrs;

    /* Set tcc to any */
    hwAttrs->edmaTcc  = EDMA3_DRV_TCC_ANY;
    hwAttrs->edmaChId = EDMA3_DRV_DMA_CHANNEL_ANY;

    status = EDMA3_DRV_requestChannel((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                                      &(hwAttrs->edmaChId),
                                      &(hwAttrs->edmaTcc),
                                      QSPI_EVENTQUE,
                                      &QSPI_dmaIsrHandler,
                                      (void *)handle);

    return status;
}

static int32_t QSPI_dmaMemcpy(SPI_Handle     handle,
                              void          *destBuf,
                              void          *srcBuf,
                              uint32_t       length)

{
    QSPI_HwAttrs const   *hwAttrs;
    EDMA3_DRV_PaRAMRegs   paramSet = {0, };
    int32_t               cIdx;
    EDMA3_DRV_Result      status;

    /* Get the pointer to the hwAttrs */
    hwAttrs = (QSPI_HwAttrs *)handle->hwAttrs;

    /* receive parameter set */
    EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                        hwAttrs->edmaChId,
                        &paramSet);

    paramSet.srcAddr  = (uint32_t)srcBuf;
    paramSet.destAddr = (uint32_t)destBuf;

    /* aCnt holds the number of bytes in an array.*/
    paramSet.aCnt = (uint16_t)1;

    /*
     * bCnt holds the number of such arrays to be transferred.
     * cCnt holds the number of frames of aCnt*bBcnt bytes to be transferred
     */
    if (length < 0x8000U)
    {
        paramSet.bCnt = (uint16_t)length;
        paramSet.cCnt = (uint16_t)1;
        cIdx          = (int32_t)paramSet.bCnt;
    }
    else
    {
        paramSet.bCnt = (uint16_t)0x4000;
        paramSet.cCnt = (uint16_t)(length / paramSet.bCnt);
        cIdx          = (int32_t)paramSet.bCnt;
    }

    /**
     * Be Careful !!!
     * Valid values for SRCBIDX/DSTBIDX are between -32768 and 32767
     * Valid values for SRCCIDX/DSTCIDX are between -32768 and 32767
     */
    paramSet.srcBIdx  = (int32_t)paramSet.aCnt;
    paramSet.destBIdx = (int32_t)paramSet.aCnt;
    paramSet.srcCIdx  = cIdx;
    paramSet.destCIdx = cIdx;

    /* Linking transfers in EDMA3 are not used.*/
    paramSet.linkAddr = 0xFFFF;

    paramSet.bCntReload = paramSet.bCnt;

    /* By default SAM and DAM bits are set to INCR mode                  */
    paramSet.opt &= 0xFFFFFFFCU;

    /* update the transfer completion code                               */
    paramSet.opt |= ((hwAttrs->edmaTcc << QSPI_OPT_TCC_SHIFT)& QSPI_OPT_TCC_MASK);


    /* EDMA3_DRV_SYNC_AB mode                                            */
    paramSet.opt &= QSPI_EDMA3CC_OPT_SYNC_MASK_VALUE;
    paramSet.opt |= QSPI_EDMA3CC_OPT_SYNC_AB;

    /* EDMA3_DRV_OPT_FIELD_TCINTEN                                       */
    paramSet.opt |= 1U << QSPI_OPT_TCINTEN_SHIFT;

    /* Now, write the PaRAM Set. */
    status = EDMA3_DRV_setPaRAM(hwAttrs->edmaHandle, hwAttrs->edmaChId, &paramSet);

    if (status == EDMA3_DRV_SOK)
    {
        status = EDMA3_DRV_enableTransfer(hwAttrs->edmaHandle,
                                          hwAttrs->edmaChId,
                                          EDMA3_DRV_TRIG_MODE_MANUAL);
    }

    return (status);
}

int32_t QSPI_dmaTransfer(SPI_Handle             handle,
                         const SPI_Transaction *transaction)
{
    QSPI_v1_Object        *object;
    QSPI_HwAttrs const    *hwAttrs;
    uintptr_t              dataPtr;
    int32_t                status;

    /* Get the pointer to the hwAttrs */
    object  = (QSPI_v1_Object *)handle->object;
    hwAttrs = (QSPI_HwAttrs *)handle->hwAttrs;

    dataPtr = ((uintptr_t)hwAttrs->memMappedBaseAddr + (uintptr_t)transaction->txBuf);

    if(SPI_TRANSACTION_TYPE_READ == object->transactionType)
    {
        /* RX Mode */
        status = QSPI_dmaMemcpy(handle,
                                (void *)transaction->rxBuf,
                                (void *)dataPtr,
                                transaction->count);
    }
    else
    {
        /* TX Mode */
        status  = QSPI_dmaMemcpy(handle,
                                (void *)dataPtr,
                                (void *)transaction->rxBuf,
                                transaction->count);
    }

    return (status);
}

int32_t QSPI_dmaFreeChannel(SPI_Handle handle)
{
    QSPI_HwAttrs const *hwAttrs;
    int32_t             status;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (QSPI_HwAttrs*)handle->hwAttrs;

    status = EDMA3_DRV_freeChannel(hwAttrs->edmaHandle, hwAttrs->edmaChId);

    return (status);
}

static void QSPI_dmaIsrHandler(uint32_t           tcc,
                               EDMA3_RM_TccStatus status,
                               void*              appData)
{
    SPI_Handle            handle;
    QSPI_v1_Object       *object;
    QSPI_HwAttrs const   *hwAttrs;
    EDMA3_DRV_PaRAMRegs   paramSet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint32_t              bytesRemain;

    /* Get the pointer to the object and hwAttrs */
    handle   = (SPI_Handle)appData;
    object   = (QSPI_v1_Object*)handle->object;
    hwAttrs  = (QSPI_HwAttrs*)handle->hwAttrs;

    if (EDMA3_RM_XFER_COMPLETE != status)
    {
        /* Error condition  */

        /* Ensure to clear the error bits of EDMA channel */
        EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                 hwAttrs->edmaChId);

        /* Get the PaRAM set for default parameters */
        EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                            hwAttrs->edmaChId,
                            &paramSet);

        /* calculate the amount of bytes remaining */
        bytesRemain = (paramSet.aCnt * paramSet.bCnt * paramSet.cCnt);

        /* Update the transaction status and word count transfered */
        object->transaction->status = SPI_TRANSFER_FAILED;
        object->transaction->count -= bytesRemain;

        /* clear the error bits in the EDMA(as this is the last packet)   */
        EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)(hwAttrs->edmaHandle),
                                 (uint32_t)tcc);
    }
    else
    {
        /* Call the transfer completion callback function */
        object->transaction->status = SPI_TRANSFER_COMPLETED;
    }

    /* EDMA Rx is done disable the Rx DMA channel */
    EDMA3_DRV_disableTransfer(hwAttrs->edmaHandle,
                              hwAttrs->edmaChId,
                              EDMA3_DRV_TRIG_MODE_MANUAL);

    object->qspiParams.transferCallbackFxn(handle, object->transaction);
}

