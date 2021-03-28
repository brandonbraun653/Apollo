/**
 * @file   UART_v0.c
 *
 * @brief  This file implements the EDMA based UART driver for IP of version V0
 */
/*
 Copyright (c) 2017-2019, Texas Instruments Incorporated
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

#include <ti/drv/uart/src/v0/UART_v0.h>
#include <ti/csl/src/ip/uart/V0/uart.h>
#include <ti/sdo/edma3/drv/edma3_drv.h>

#define UART_FIFO_SIZE                          (16U)

#define UART_OPT_TCINTEN_SHIFT                  ((uint32_t)0x00000014U)
/**< Interrupt enable bit in OPT register for edma                            */

#define UART_OPT_TCINTEN                        ((uint32_t)1U)
/**< Interrupt enable bit value in OPT register for edma                      */

#define UART_EDMA3CC_OPT_TCC_MASK               ((uint32_t)0x0003F000U)
/**< EDMA OPT TCC Mask value                                                  */

#define UART_EDMA3CC_OPT_TCC_SHIFT              ((uint32_t)0x0000000CU)
/**< EDMA OPT TCC Shift value                                                 */

#define UART_EDMA3CC_OPT_FIFO_WIDTH             ((uint32_t)0xFFFFF8FFU)
/**< Set FIFO Width for edma transfer                                         */

#define UART_EDMA3CC_OPT_SAM_CONST_MODE         ((uint32_t)0x00000001U)
/**< Set SAM in Constant Addressing Mode                                      */

#define UART_EDMA3CC_OPT_DAM_CONST_MODE         ((uint32_t)0x00000002U)
/**< Set DAM in Constant Addressing Mode                                      */

#define UART_EDMA3CC_OPT_SAM_INCR_MODE          ((uint32_t)0xFFFFFFFEU)
/**< Set SAM in Increment Mode                                                */

#define UART_EDMA3CC_OPT_DAM_INCR_MODE          ((uint32_t)0xFFFFFFFDU)
/**< Set DAM in Increment Mode                                                */

#define UART_EDMA3CC_OPT_SYNC_AB                ((uint32_t)0x00000004U)
/**< It is AB-synchronized                                                    */

#define UART_EDMA3CC_OPT_SYNC_MASK_VALUE        ((uint32_t)0xFFFFFFFFU)
/**< Mask Value for Transfer Synchronization                                  */

#define UART_EDMA3CC_PARAM_LINK_ADDRESS         ((uint32_t)0xFFFFU)
/**< Set link Address                                                         */

#define UART_EDMA3CC_PARAM_LINK_ADDR_MASK_VALUE ((uint32_t)0x0000FFFFU)
/**< link Address Mask Value                                                  */

#define UART_EDMA3CC_PARAM_ACNT                 ((uint32_t)1U)
/**< aCnt Value                                                               */

#define UART_EDMA3CC_SRC_BINDEX                 ((uint32_t)1U)
/**< Src BIndex Value                                                         */

#define UART_EDMA3CC_DST_BINDEX                 ((uint32_t)1U)
/**< Dst BIndex Value                                                         */

#define UART_EDMA3CC_OPT_SYNC_A                 ((uint32_t)0x01U)
/**< It is A-synchronized                                                     */

#define UART_EDMA3CC_OPT_SYNCDIM_SHIFT          ((uint32_t)3U)
/**< Transfer synchronization dimension Shift Value                           */

#define UART_EDMA3CC_COUNT_VALUE                ((uint32_t)0xFFFFU)
/**< Count Value                                                              */

static void UART_rxIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData);
static void UART_txIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData);
static void UART_doNothing(uint32_t tcc, EDMA3_RM_TccStatus edmaStatus, void* appData);

void UART_disableDmaChannel(UART_Handle handle, bool txChan)
{
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs*)handle->hwAttrs;
    uint32_t            dmaEvent;

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

void UART_freeDmaChannel(UART_Handle handle)
{
    UART_V0_Object     *object  = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs*)handle->hwAttrs;

    EDMA3_DRV_unlinkChannel(
            hwAttrs->edmaHandle,
            object->edmaLinkChId);

    EDMA3_DRV_freeChannel(
                hwAttrs->edmaHandle,
                object->edmaLinkChId);

    /* Free the DMA TX/RX channels */
    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle,
                          hwAttrs->rxDmaEventNumber);

    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle,
                          hwAttrs->txDmaEventNumber);
}

void UART_receiveDMA(UART_Handle handle,const void *buffer, size_t size )
{
    UART_V0_Object     *object ;
    UART_HwAttrs const *hwAttrs;
    uint32_t            actualThreshold;
    int32_t             result = EDMA3_DRV_SOK;
    EDMA3_DRV_PaRAMRegs paramSet   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool                ret_val = false;

    hwAttrs = (UART_HwAttrs*)handle->hwAttrs;
    actualThreshold = hwAttrs->rxTrigLvl;
    object = (UART_V0_Object*)handle->object;

    if (size < actualThreshold)
    {
        /*
         * if read size is less than the rx trigger level, do
         * not use dma, use rx timeout intterupt to receive data
         */
        UART_intEnable_v0(hwAttrs->baseAddr, UART_INT_RHR_CTI);
        ret_val = true;
    }

    if ((ret_val == false) && (result == EDMA3_DRV_SOK))
    {
        /* Get the PaRAM set for default parameters                               */
        EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                    (uint32_t) hwAttrs->rxDmaEventNumber, &paramSet);
        /* Fill the PaRAM Set with transfer specific information */
        paramSet.destAddr  = (uint32_t)(buffer);
        paramSet.srcAddr = (uint32_t) ((hwAttrs->baseAddr) + CSL_UART_RBR);

        /**
         * Be Careful !!!
         * Valid values for SRCBIDX/DSTBIDX are between \9632768 and 32767
         * Valid values for SRCCIDX/DSTCIDX are between \9632768 and 32767
         */
        paramSet.aCnt       = 1;
        paramSet.bCnt       = (uint16_t) actualThreshold;
        paramSet.srcBIdx    = 0; /* src addr no modification */
        paramSet.srcCIdx    = 0; /* src addr no modification per event */

        paramSet.destBIdx   = UART_EDMA3CC_DST_BINDEX; /* dest addr increment */
        paramSet.destCIdx   = actualThreshold;		/* dest addr + actualThreshold per event */

        /**
         * Be Careful !!!
         * Valid values for ACNT/BCNT/CCNT are between 0 and 65535.
         * ACNT/BCNT/CCNT must be greater than or equal to 1.
         * Maximum number of bytes in an array (ACNT) is 65535 bytes
         * Maximum number of arrays in a frame (BCNT) is 65535
         * Maximum number of frames in a block (CCNT) is 65535
         */

        if ((size <= UART_EDMA3CC_COUNT_VALUE))
        {
            paramSet.cCnt = (uint16_t) (UART_EDMA3CC_COUNT_VALUE &
                                   (size / actualThreshold));
        }
        else
        {
            result = (int32_t)(-1);
        }
        /* For AB-synchronized transfers, BCNTRLD is not used. */
        paramSet.linkAddr   = 0xFFFFu;
        paramSet.bCntReload = (uint16_t) 0;

        /* Src is in FIFO mode & Dest is in INCR modes                            */
        paramSet.opt &= UART_EDMA3CC_OPT_DAM_INCR_MODE;
        paramSet.opt |= UART_EDMA3CC_OPT_SAM_CONST_MODE;

        /* FIFO width is 8 bit                                                    */
        paramSet.opt &= UART_EDMA3CC_OPT_FIFO_WIDTH;

        /* EDMA3_DRV_SYNC_AB                                                      */
        paramSet.opt &= UART_EDMA3CC_OPT_SYNC_MASK_VALUE;
        paramSet.opt |= UART_EDMA3CC_OPT_SYNC_AB;


        /* EDMA3_DRV_OPT_FIELD_TCINTEN                                            */
        paramSet.opt |= ((uint32_t) 1U << UART_OPT_TCINTEN_SHIFT);

        /* ADDED FOR ARM PLATFORM                                                 */
        /* update the transfer completion code                                    */
        paramSet.opt &= (~UART_EDMA3CC_OPT_TCC_MASK);
        paramSet.opt |= ((object->rxTcc) << UART_EDMA3CC_OPT_TCC_SHIFT);

        result = EDMA3_DRV_setPaRAM(hwAttrs->edmaHandle, hwAttrs->rxDmaEventNumber, &paramSet);

        if (result == 0)
        {
            result = EDMA3_DRV_disableTransfer(
                                 (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                 (uint32_t) hwAttrs->rxDmaEventNumber,
                                 (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);
        }
        if (result == 0)
        {
            result = EDMA3_DRV_enableTransfer(
                                 (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                 (uint32_t) hwAttrs->rxDmaEventNumber,
                                 (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);
        }
    }
}

void UART_transmitDMA(UART_Handle handle,const void *buffer, size_t size)
{
    UART_HwAttrs const *hwAttrs;
    uint32_t            actualThreshold;
    UART_V0_Object     *object ;
    uint32_t            isTxFifoEmpty = FALSE;
    uint32_t            edmaStatus = 0U, isEdmaEventPending = FALSE;
    int32_t             result = EDMA3_DRV_SOK;
    EDMA3_DRV_PaRAMRegs paramSet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint32_t            txTrigLvl;

    hwAttrs = (UART_HwAttrs*)handle->hwAttrs;
    if ((hwAttrs->txTrigLvl == 0U) || (hwAttrs->txTrigLvl > UART_FIFO_SIZE))
    {
        txTrigLvl = 1U;
    }
    else
    {
        txTrigLvl = hwAttrs->txTrigLvl;
    }
    actualThreshold = txTrigLvl;
    object = (UART_V0_Object*)handle->object;
    if (result == EDMA3_DRV_SOK)
    {
        /* Get the PaRAM set for default parameters                               */
        EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                           (uint32_t) hwAttrs->txDmaEventNumber, &paramSet);

        /* Fill the PaRAM Set with transfer specific information */
        paramSet.srcAddr    = (uint32_t)(buffer);
        paramSet.destAddr = (uint32_t) ((hwAttrs->baseAddr)
                                    + CSL_UART_THR);
        /**
         * Be Careful !!!
         * Valid values for SRCBIDX/DSTBIDX are between \9632768 and 32767
         * Valid values for SRCCIDX/DSTCIDX are between \9632768 and 32767
         */
        paramSet.aCnt     = 1;
        if ((uint32_t)size < actualThreshold)
        {
            paramSet.bCnt   = (uint16_t) size;
        }
        else
        {
            paramSet.bCnt   = (uint16_t) actualThreshold;
        }
        paramSet.srcBIdx    = UART_EDMA3CC_SRC_BINDEX; /* src addr increment */
        paramSet.srcCIdx    = actualThreshold;         /* srr addr + actualThreshold every event */

        paramSet.destBIdx   = 0; /* des addr no modification */
        paramSet.destCIdx   = 0; /* des addr no modification per event */

        /**
         * Be Careful !!!
         * Valid values for ACNT/BCNT/CCNT are between 0 and 65535.
         * ACNT/BCNT/CCNT must be greater than or equal to 1.
         * Maximum number of bytes in an array (ACNT) is 65535 bytes
         * Maximum number of arrays in a frame (BCNT) is 65535
         * Maximum number of frames in a block (CCNT) is 65535
         */

        if ((size <= UART_EDMA3CC_COUNT_VALUE) &&
            (size > actualThreshold))
        {
            paramSet.cCnt = (uint16_t)(UART_EDMA3CC_COUNT_VALUE &
                                  (size / actualThreshold));
        }
        else if ((size <= actualThreshold) && (size > 0))
        {
            paramSet.cCnt = 1;
        }
        else
        {
            result = -1;
        }

        /* For AB-synchronized transfers, BCNTRLD is not used. */
        paramSet.bCntReload = (uint16_t) 0;
        paramSet.linkAddr = (uint16_t) (object->edmaLinkChPhyAddr
                                  & UART_EDMA3CC_PARAM_LINK_ADDR_MASK_VALUE);

        /* Src is in INCR mode & Dest is in FIFO modes                            */
        paramSet.opt &= UART_EDMA3CC_OPT_SAM_INCR_MODE;
        paramSet.opt |= UART_EDMA3CC_OPT_DAM_CONST_MODE;

        /* FIFO width is 8 bit                                                    */
        paramSet.opt &= UART_EDMA3CC_OPT_FIFO_WIDTH;

        /* EDMA3_DRV_SYNC_AB                                                      */
        paramSet.opt &= UART_EDMA3CC_OPT_SYNC_MASK_VALUE;
        paramSet.opt |= UART_EDMA3CC_OPT_SYNC_AB;

        /* EDMA3_DRV_OPT_FIELD_TCINTEN                                            */
        paramSet.opt |= (UART_OPT_TCINTEN << UART_OPT_TCINTEN_SHIFT);

        /* update the transfer completion code                                    */
        paramSet.opt &= (~UART_EDMA3CC_OPT_TCC_MASK);
        paramSet.opt |= (( object->txTcc) << UART_EDMA3CC_OPT_TCC_SHIFT);

        result = EDMA3_DRV_setPaRAM(hwAttrs->edmaHandle, hwAttrs->txDmaEventNumber, &paramSet);

        if (result == 0)
        {
            result = EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                        (uint32_t) object->edmaLinkChId,
                                        &paramSet);

            paramSet.aCnt     = 1;
            paramSet.linkAddr = UART_EDMA3CC_PARAM_LINK_ADDRESS;
            paramSet.opt     &= ~(UART_EDMA3CC_OPT_SYNC_A << UART_EDMA3CC_OPT_SYNCDIM_SHIFT);

            if (0 == result)
            {
                /* Now, write the PaRAM Set.                                          */
                result = EDMA3_DRV_setPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                            (uint32_t) object->edmaLinkChId,
                                            &paramSet);
            }
            if (0 == result)
            {
                result = EDMA3_DRV_linkChannel((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                               (uint32_t) hwAttrs->txDmaEventNumber,
                                               (uint32_t) object->edmaLinkChId);
            }

            if (0 == result)
            {
                isTxFifoEmpty = UART_fifoEmpty_v0(hwAttrs->baseAddr);

                /* Get EDMA event pending status */
                result = EDMA3_DRV_getChannelStatus(
                                            (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                            (uint32_t) hwAttrs->txDmaEventNumber,
                                            &edmaStatus);
                if (result != ((Int32) 0))
                {
                    result = -1;
                }
                if ((uint32_t) EDMA3_DRV_CHANNEL_EVENT_PENDING ==
                                (edmaStatus & ((uint32_t) EDMA3_DRV_CHANNEL_EVENT_PENDING)))
                {
                    isEdmaEventPending = (uint32_t) TRUE;
                }

                /* Note: Getting the FIFO status and EDMA event pend should be
                 * done prior to enabling the EDMA channel */
                result = EDMA3_DRV_enableTransfer(
                                        (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                        (uint32_t) hwAttrs->txDmaEventNumber,
                                        (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);
                if (result != ((Int32) EDMA3_DRV_SOK))
                {
                    result = -1;
                }

                /* Workaround: In case of DMA mode, the UART IP generates the
                 * next EDMA event as soon as the FIFO gets emptied or when there are
                 * TX threshold level bytes free in FIFO. In the EDMA ISR,
                 * the DMA mode is disabled and EDMA channel is disabled.
                 * There is a race condition between software (CPU) disabling the DMA
                 * mode and the UART IP generating the DMA event to EDMA.
                 *
                 * In cases when the software is slower (multi-tasking systems or
                 * in heavily CPU loaded systems or for lower FIFO trigger levels),
                 * the UART IP DMA event gets generated before the CPU could disable
                 * the DMA event generation.
                 *
                 * When this happens, since the EDMA channel is enabled, the EDMA will
                 * acknowledge the EDMA event but it doesn't have proper param set to
                 * do the actual transfer to the UART FIFO. Hence the event gets lost
                 * and the UART IP doesn't generate the next EDMA event unless the FIFO
                 * is written. This becomes a deadlock!!
                 *
                 * To break the dead lock, first we need to identify whether this had
                 * happened by checking the UART FIFO level and the EDMA channel status.
                 * As per UART IP, in DMA mode, when ever the FIFO is empty or has TX
                 * threshold amount of free space it should have raised an DMA event.
                 * Hence we check if the UART FIFO has room and see if the event is
                 * latched in the EDMA register.
                 * So if FIFO is empty and event is not latched, then we are in a
                 * deadlock.
                 *
                 * To recover from the deadlock, we do a manual trigger for the first
                 * time and the rest of the transfer is taken care automatically
                 * by further UART events.
                 */
                if (((uint32_t) TRUE == isTxFifoEmpty) &&
                    ((uint32_t) FALSE == isEdmaEventPending))
                {
                    result = EDMA3_DRV_enableTransfer(
                                            (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                            (uint32_t) hwAttrs->txDmaEventNumber,
                                            (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_MANUAL);
                    if (result != ((Int32) EDMA3_DRV_SOK))
                    {
                        result = (int32_t)(-1);
                    }
                }
            }
        }
    }
}

int32_t UART_configDMA(UART_Handle handle )
{
    UART_HwAttrs const           *hwAttrs =(UART_HwAttrs*)handle->hwAttrs;
    uint32_t      rxDmaEventNumber;
    uint32_t      txDmaEventNumber;
    uint32_t tcc = 0;
    UART_V0_Object        *object  = (UART_V0_Object*)handle->object;

    Int32 status = EDMA3_DRV_SOK;

    rxDmaEventNumber = hwAttrs->rxDmaEventNumber;


    txDmaEventNumber = hwAttrs->txDmaEventNumber;
    object->rxTcc = EDMA3_DRV_TCC_ANY;

    status = (Int32) EDMA3_DRV_requestChannel(
                        (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                        &rxDmaEventNumber,
                        &object->rxTcc,
                        (EDMA3_RM_EventQueue) hwAttrs->edmaRxTC,
                        &UART_rxIsrHandler,
                        (void *) handle);
    if(status == EDMA3_DRV_SOK )
    {
        object->txTcc = EDMA3_DRV_TCC_ANY;
        status = (Int32) EDMA3_DRV_requestChannel(
                                        (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                        &txDmaEventNumber,
                                        &object->txTcc,
                                        (EDMA3_RM_EventQueue) 0,
                                        &UART_txIsrHandler,
                                        (void *) handle);
        if(status == EDMA3_DRV_SOK)
        {
             tcc = EDMA3_DRV_TCC_ANY;
             object->edmaLinkChId = EDMA3_DRV_LINK_CHANNEL;
             status = EDMA3_DRV_requestChannel(
                                hwAttrs->edmaHandle,
                                &object->edmaLinkChId,
                                &tcc,
                                0,
                                &UART_doNothing,
                                NULL);

             if (EDMA3_DRV_SOK == status)
             {
                 status = EDMA3_DRV_getPaRAMPhyAddr(
                                        hwAttrs->edmaHandle,
                                        object->edmaLinkChId,
                                    &object->edmaLinkChPhyAddr);
             }
        }
    }
    return(status);
}

static void UART_doNothing(uint32_t tcc, EDMA3_RM_TccStatus edmaStatus, void* appData)
{
}

static void UART_rxIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData)
{
    UART_Handle         handle;
    UART_HwAttrs const *hwAttrs;
    UART_V0_Object     *object ;
    EDMA3_DRV_PaRAMRegs paramSet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint32_t            bytesRemain = 0;
    uint32_t            bytesReceived;
    if(appData != NULL)
    {
        handle = (UART_Handle)appData;
        hwAttrs = (UART_HwAttrs*)handle->hwAttrs;
        object = (UART_V0_Object*)handle->object;

        bytesRemain = object->readSize % hwAttrs->rxTrigLvl;
        if (object->readSize >= hwAttrs->rxTrigLvl)
        {
            bytesReceived = object->readSize - bytesRemain;
        }
        else
        {
            bytesReceived = bytesRemain;
        }

        /* Disable DMA RX channel */
        UART_disableDmaChannel(handle, false);

        if (EDMA3_RM_XFER_COMPLETE != status)
        {
            /* Ensure to clear the error bits of EDMA channel                 */
            EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                       hwAttrs->rxDmaEventNumber);


            /* Get the PaRAM set for default parameters                       */
            EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                   hwAttrs->rxDmaEventNumber,
                                              &paramSet);

            /* calculate the amount of bytes remaining                        */
            object->readSize = 0;
            if (object->readTrans != NULL)
            {
                object->readTrans->count =
                    bytesReceived - (paramSet.aCnt * paramSet.bCnt * paramSet.cCnt);
                object->readTrans->status = UART_TRANSFER_STATUS_ERROR_OTH;
            }
            else
            {
                object->readCount =
                    bytesReceived - (paramSet.aCnt * paramSet.bCnt * paramSet.cCnt);
            }
            UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_LINE_STAT);
            UART_v0_callback(handle, true);
        }
        else
        {
            object->readCount = bytesReceived;
            if ((object->readSize >= hwAttrs->rxTrigLvl) && (bytesRemain != 0))
            {
                /*
                 * read size is not multiple of RX threshold
                 * enable RHR interrupt to receive the
                 * remaining bytes in ISR
                 */
                object->readSize = bytesRemain;
                object->readBuf = (uint8_t *)object->readBuf + object->readCount;
                UART_intEnable_v0(hwAttrs->baseAddr, UART_INT_RHR_CTI);
            }
            else
            {
                /*
                 * all the data received
                 */
                if (object->readTrans != NULL)
                {
                    object->readTrans->count = object->readCount;
                    object->readTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                }
                object->readSize = 0;
                UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_LINE_STAT);
                UART_v0_callback(handle, true);
            }
        }
    }
}

static void UART_txIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData)
{
    UART_Handle         handle;
    UART_HwAttrs const *hwAttrs;
    UART_V0_Object     *object ;
    EDMA3_DRV_PaRAMRegs paramSet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint32_t            bytesRemain;
    uint32_t            bytesSent;
    uint32_t            txTrigLvl;

    if(appData != NULL)
    {
        handle = (UART_Handle)appData;
        hwAttrs = (UART_HwAttrs*)handle->hwAttrs;
        object = (UART_V0_Object*)handle->object;

        if ((hwAttrs->txTrigLvl == 0U) || (hwAttrs->txTrigLvl > UART_FIFO_SIZE))
        {
            txTrigLvl = 1U;
        }
        else
        {
            txTrigLvl = hwAttrs->txTrigLvl;
        }

        bytesRemain = object->writeSize % txTrigLvl;
        if (object->writeSize >= txTrigLvl)
        {
            bytesSent = object->writeSize - bytesRemain;
        }
        else
        {
            bytesSent = bytesRemain;
        }
        /* Disable DMA TX channel */
        UART_disableDmaChannel(handle, true);

        if (EDMA3_RM_XFER_COMPLETE != status)
        {
            /* Ensure to clear the error bits of EDMA channel                 */
            EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                       hwAttrs->txDmaEventNumber);
            /* Get the PaRAM set for default parameters                       */
            EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                               hwAttrs->txDmaEventNumber,
                                               &paramSet);

            if (object->writeTrans != NULL)
            {
                object->writeTrans->count =
                    bytesSent - (paramSet.aCnt * paramSet.bCnt * paramSet.cCnt);
                object->writeTrans->status = UART_TRANSFER_STATUS_ERROR_OTH;
            }
            else
            {
                object->writeCount =
                    bytesSent - (paramSet.aCnt * paramSet.bCnt * paramSet.cCnt);
            }
            object->writeSize = 0;
            UART_v0_callback(handle, false);
        }
        else
        {
            if ((object->writeSize >= txTrigLvl) && (bytesRemain != 0))
            {
                /*
                 * write size is not multiple of TX threshold
                 * kick off another DMA transfer to send the
                 * remaining bytes
                 */
                object->writeCount = bytesSent;
                object->writeSize = bytesRemain;
                UART_transmitDMA(handle, (void *)((uint8_t *)object->writeBuf + bytesSent), bytesRemain);
            }
            else
            {
                /*
                 * all the data sent
                 */
                object->writeCount += bytesSent;
                if (object->writeTrans != NULL)
                {
                    object->writeTrans->count = object->writeCount;
                    object->writeTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                }
                object->writeSize = 0;
                object->txDataSent = TRUE;
                UART_intEnable_v0(hwAttrs->baseAddr, UART_INT_THR);
            }
        }
    }
}
