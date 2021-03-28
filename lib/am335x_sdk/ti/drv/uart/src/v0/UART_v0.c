/**
 * @file   UART_v0.c
 *
 * @brief  This file implements the combined EDMA based and non-EDMA based
 *         UART driver interface APIs for IP of version V0
 */
/*
 Copyright (c) 2015 - 2017, Texas Instruments Incorporated
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

#include <stdint.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/v0/UART_v0.h>
#include <ti/csl/src/ip/uart/V0/uart.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/csl/src/ip/uart/V0/cslr_uart.h>
#include <ti/drv/uart/src/UART_drv_log.h>

/* UART_v0 functions */
static void         UART_close_v0(UART_Handle handle);
static void         UART_init_v0(UART_Handle handle);
static UART_Handle  UART_open_v0(UART_Handle handle, const UART_Params *params);
static int32_t      UART_read_v0(UART_Handle handle, void *buffer,
                                      size_t size);
static int32_t      UART_readPolling_v0(UART_Handle handle, void *buf,
                                             size_t size);
static void         UART_readCancel_v0(UART_Handle handle);
static int32_t      UART_write_v0(UART_Handle handle, const void *buffer,
                                       size_t size);
static int32_t      UART_writePolling_v0(UART_Handle handle,
                                              const void *buf, size_t size);
static void         UART_writeCancel_v0(UART_Handle handle);

static int32_t      UART_control_v0(UART_Handle handle,
                                               uint32_t cmd,
                                               void *arg);
static int32_t      UART_read2_v0(UART_Handle handle,
		                             UART_Transaction *transaction);
static int32_t      UART_write2_v0(UART_Handle handle,
		                              UART_Transaction *transaction);

static bool UART_writeCancelNoCB(UART_Handle handle);
static bool UART_readCancelNoCB(UART_Handle handle);

/* UART function table for UART_v0 implementation */
const UART_FxnTable UART_FxnTable_v0 =
{
    &UART_close_v0,
    &UART_control_v0,
    &UART_init_v0,
    &UART_open_v0,
    &UART_read_v0,
    &UART_readPolling_v0,
    &UART_readCancel_v0,
    &UART_write_v0,
    &UART_writePolling_v0,
    &UART_writeCancel_v0,
    &UART_read2_v0,
    &UART_write2_v0,
};

/*
 *  ======== UART_v0_writeData ========
 *  Write and process data to the UART.
 */
static inline int32_t UART_writeData_v0(UART_Handle handle, int32_t size);  /*for misra warnings*/
static inline int32_t UART_writeData_v0(UART_Handle handle, int32_t size)
{
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    uint32_t            fifoCnt;

    fifoCnt = 0;

    uint8_t FIFO_FULL_FLAG = 0U;

    /* Send characters until FIFO is full or done. */
    while ((size != 0) && (FIFO_FULL_FLAG == 0U))
    {
        /* If mode is TEXT process the characters */
        if (object->params.writeDataMode == UART_DATA_TEXT)
        {
            if (object->writeCR)
            {
                if (fifoCnt == TX_FIFO_SIZE)
                {
                    /* Character was not sent, FIFO is full */
                    FIFO_FULL_FLAG = 1U;
                }

                /* FIFO is empty, write '\r' to FIFO */
                else
                {
                    UART_fIFOCharPut_v0(hwAttrs->baseAddr, (uint8_t)'\r');
                    fifoCnt++;
                    size--;
                    object->writeCount++;
                    object->writeCR = 0;

                    UART_drv_log1("UART:(%p) Wrote character 0x%x",
                               hwAttrs->baseAddr);
                }
            }
            else
            {
                /* Add a return if next character is a newline. */
                if (*(uint8_t *)object->writeBuf == (uint8_t)'\n')
                {
                    size++;
                    object->writeCR = (uint32_t)TRUE;
                }

                if (fifoCnt == TX_FIFO_SIZE)
                {
                    /* FIFO full */
                    if (object->writeCR)
                    {
                        size--;
                        object->writeCR = (uint32_t)FALSE;
                    }
                    FIFO_FULL_FLAG = 1U;
                }
                /* FIFO not full, write to FIFO */
                else
                {
                    UART_fIFOCharPut_v0(hwAttrs->baseAddr, *(uint8_t *)object->writeBuf);
                    fifoCnt++;
                    object->writeBuf = (uint8_t *)object->writeBuf + 1;

                    UART_drv_log2("UART:(%p) Wrote character 0x%x",
                              hwAttrs->baseAddr, *(uint8_t *)object->writeBuf);

                    size--;
                    object->writeCount++;
                }
            }
        }
        else
        {
            if (fifoCnt == TX_FIFO_SIZE)
            {
                /* FIFO full */
                FIFO_FULL_FLAG = 1U;
            }

            /* FIFO not full, write character */
            else
            {
                UART_fIFOCharPut_v0(hwAttrs->baseAddr, *(uint8_t *)object->writeBuf);
                fifoCnt++;
                object->writeBuf = (uint8_t *)object->writeBuf + 1;

                UART_drv_log2("UART:(%p) Wrote character 0x%x",
                           hwAttrs->baseAddr, *(uint8_t *)object->writeBuf);

                size--;
                object->writeCount++;
            }
        }
    }
    return (size);
}

/*
 *  ======== UART_v0_readData ========
 *  Read and process data from the UART.
 */
static inline int32_t UART_v0_readData(UART_Handle handle, int32_t size);  /*for misra warnings*/
static inline int32_t UART_v0_readData(UART_Handle handle, int32_t size)
{
    uint8_t             readIn;
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    uint32_t            readSuccess;

    readSuccess = UART_charGetNonBlocking2_v0(hwAttrs->baseAddr, &readIn);
    /* Receive chars until empty or done. */
    while ((size != (int32_t)(0)) &&
           (readSuccess != FALSE))
    {
        /* If data mode is set to TEXT replace return with a newline. */
        if (object->params.readDataMode == UART_DATA_TEXT)
        {
            if (readIn == (uint8_t)'\r')
            {
                /* Echo character if enabled. */
                if (object->params.readEcho)
                {
                    UART_charPut_v0(hwAttrs->baseAddr, (uint8_t)'\r');
                }
                readIn = (uint8_t)'\n';
            }
        }

        UART_drv_log2("UART:(%p) Read character 0x%x",
                   hwAttrs->baseAddr, readIn);

       *(uint8_t *)object->readBuf = readIn;
        object->readBuf = (uint8_t *)object->readBuf + 1;
        object->readCount++;
        size--;

        /* Echo character if enabled. */
        if (object->params.readEcho)
        {
            UART_charPut_v0(hwAttrs->baseAddr, readIn);
        }

        /* If read return mode is newline, finish if a newline was received. */
        if ((object->params.readReturnMode == UART_RETURN_NEWLINE) &&
            (readIn == (uint8_t)'\n'))
        {
            UART_drv_log1("UART:(%p) Newline character received, "
                       , hwAttrs->baseAddr);

            size = 0;
            break;
        }

        /* If read returnMode is UART_RETURN_FULL, avoids missing input character
         * of next read
         */
        if (size != 0)
        {
            readSuccess = (int32_t)UART_charGetNonBlocking2_v0(hwAttrs->baseAddr, &readIn);
        }
    }

    return (size);
}

void UART_v0_callback(UART_Handle handle, bool readTrans)
{
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;

    /* Call back to application */
    if (readTrans == true)
    {
        if (object->params.readCallback2)
        {
            object->params.readCallback2(handle, object->readTrans);
        }
        else if (object->params.readCallback)
        {
            object->params.readCallback(handle,
                                        object->readBuf,
                                        object->readCount);
        }
        else
        {
            UART_osalPostLock(object->readSem);
        }
    }
    else
    {
        if (object->params.writeCallback2)
        {
            object->params.writeCallback2(handle, object->writeTrans);
        }
        else if (object->params.writeCallback)
        {
            object->params.writeCallback(handle,
                                         (void *)object->writeBuf,
                                         object->writeCount);
        }
        else
        {
            UART_osalPostLock(object->writeSem);
        }
    }
}

static inline void UART_procLineStatusErr(UART_Handle handle);   /* for misra warnings*/
static inline void UART_procLineStatusErr(UART_Handle handle)
{
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    uint32_t            lineStatus;

    if (object->readSize)
    {
        lineStatus = UART_readLineStatus_v0(hwAttrs->baseAddr);

        if (((lineStatus & UART_FIFO_PE_FE_BI_DETECTED) == UART_FIFO_PE_FE_BI_DETECTED) ||
            ((lineStatus & UART_OVERRUN_ERROR) == UART_OVERRUN_ERROR))
        {
            /* empty the RX FIFO which contains data with errors */
#ifdef UART_DMA_ENABLE
            if (hwAttrs->dmaMode == TRUE)
            {
                /* Disable DMA RX channel */
                UART_disableDmaChannel(handle, false);

                if (object->readTrans != NULL)
                {
                    object->readTrans->count = 0;
                }
                else
                {
                    object->readCount = 0;
                }
            }
            else
#endif
            {
                if (object->readTrans != NULL)
                {
                    object->readTrans->count = object->readCount;
                }
            }
            /* dummy read, clear the RX line status interrupt */
            UART_v0_readData(handle, object->readSize);
            UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_LINE_STAT);

            /* Reset the read buffer and read count so we can pass it back */
            object->readBuf = (uint8_t *)object->readBuf - object->readCount;

            if (object->readTrans != NULL)
            {
                if ((lineStatus & UART_BREAK_DETECTED_ERROR) == UART_BREAK_DETECTED_ERROR)
                {
                    object->readTrans->status = UART_TRANSFER_STATUS_ERROR_BI;
                }
                else if ((lineStatus & UART_FRAMING_ERROR) == UART_FRAMING_ERROR)
                {
                    object->readTrans->status = UART_TRANSFER_STATUS_ERROR_FE;
                }
                else if ((lineStatus & UART_PARITY_ERROR) == UART_PARITY_ERROR)
                {
                    object->readTrans->status = UART_TRANSFER_STATUS_ERROR_PE;
                }
                else
                {
                    object->readTrans->status = UART_TRANSFER_STATUS_ERROR_OE;
                }
            }

            /* Call back to application if in callback mode */
            UART_v0_callback(handle, true);
            object->readTrans = NULL;
        }
    }
}

/*
 *  ======== UART_v0_hwiIntFxn ========
 *  Hwi function that processes UART interrupts.
 *
 *  In non-DMA mode, three UART interrupts are enabled:
 *    1. transmit holding register empty (THR)
 *    2. receive FIFO is above RX FIFO trigger level (RHR)
 *    3. line status rx error
 *
 *  ISR checks the three interrupts in a while(1) loop, to ensure that all
 *  the pending interrupts are handled before exiting.
 *
 *  If line status rx error is detected, ISR clears the last read error, update
 *  the actual number of bytes transferred and transfer status in readTrans and
 *  calls back to application in the callback mode or post the read semaphone
 *  in the blocking mode. ISR
 *
 *  If RHR interrupt is received, ISR calls the in-lined function readData to
 *  read the data out from the RX FIFO. When all the data are received, ISR updates
 *  the actual number of bytes transferred and transfer status in readTrans and
 *  calls back to the application in the callback mode or post the read semaphone
 *  in the blocking mode. if RX timeout is detected, ISR will log the timeout
 *  count.
 *
 *  If THR interrupt is received, ISR calls the in-lined function writeData,
 *  to write the data to the TX FIFO. When all the data are sent, ISR updates
 *  the actual number of bytes transferred and transfer status in writeTrans and
 *  calls back to application in the callback mode or post the read semaphone
 *  in the blocking mode.
 *
 *  In DMA mode, one UART interrupt is enabled:
 *    1. line status rx error
 *
 *  If line status rx error is detected, ISR clears the last read error, update
 *  the actual number of bytes transferred and transfer status in readTrans,
 *  disables the DMA RX channel and calls back to application in the callback mode
 *  or post the read semaphone in the blocking mode.
 *
 *  DMA RX transfer completion is handled in UART_rxIsrHandler, TX transfer
 *  completion is handled in UART_txIsrHandler.
 *
 *  @param(arg)         The UART_Handle for this Hwi.
 */
static void UART_v0_hwiIntFxn(uintptr_t arg);   /* for misra warnings*/
static void UART_v0_hwiIntFxn(uintptr_t arg)
{
    UART_Handle         handle = (UART_Handle)arg;
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    uint32_t            intType;

    while (TRUE)
    {
        intType = UART_intIdentityGet_v0(hwAttrs->baseAddr);
        if (intType & UART_INTID_RX_THRES_REACH)
        {
            /* RX FIFO trigger or char timeout interrupt */
            if ((intType & UART_INTID_RX_LINE_STAT_ERROR) ==
                UART_INTID_RX_LINE_STAT_ERROR)
            {
                /* RX line status error */
                UART_procLineStatusErr(handle);
            }
            else
            {
                if ((intType & UART_INTID_CHAR_TIMEOUT) == UART_INTID_CHAR_TIMEOUT)
                {
                    /* rx timeout, log the rx timeout errors */
                    object->rxTimeoutCnt++;
                }

                /* RX FIFO threshold reached */
                if (object->readSize)
                {
                    object->readSize = UART_v0_readData(handle, object->readSize);
                    if ((object->readSize) == 0U)
                    {
                        UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_LINE_STAT);
                        /* Reset the read buffer so we can pass it back */
                        object->readBuf = (uint8_t *)object->readBuf - object->readCount;
                        if (object->readTrans != NULL)
                        {
                            object->readTrans->count = object->readCount;
                            object->readTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                        }

                        /* Call back to application if in callback mode */
                        UART_v0_callback(handle, true);
                        object->readTrans = NULL;
                    }
                }
            }
        }
        else if (intType & UART_INTID_TX_THRES_REACH)
        {
            /* TX empty interrupt */
            if (object->writeSize)
            {
                object->writeSize = UART_writeData_v0(handle, object->writeSize);
                if ((object->writeSize) == 0U)
                {
                    UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_THR);
                    /* Reset the write buffer so we can pass it back */
                    object->writeBuf = (uint8_t *)object->writeBuf - object->writeCount;
                    if (object->writeTrans != NULL)
                    {
                        object->writeTrans->count = object->writeCount;
                        object->writeTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                    }

                    /* Call back to application if in callback mode */
                    UART_v0_callback(handle, false);
                    object->writeTrans = NULL;
                }
            }
            else
            {
                if (object->txDataSent == TRUE)
                {
                    UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_THR);

                    /* Call back to application if in callback mode */
                    UART_v0_callback(handle, false);
                    object->writeTrans = NULL;
                    object->txDataSent = FALSE;
                }
            }
        }
        else
        {
            break;
        }
    }
}

/*
 *  ======== UART_init_v0 ========
 */
static void UART_init_v0(UART_Handle handle)
{
    /* Mark the object as available */
    ((UART_V0_Object *)(handle->object))->isOpen = (uint32_t)FALSE;
}

static uint32_t UART_getRxTrigLvl_v0(UART_RxTrigLvl trigLevel);
static uint32_t UART_getRxTrigLvl_v0(UART_RxTrigLvl trigLevel)
{
    uint32_t value;

    switch (trigLevel)
	{
        case UART_RXTRIGLVL_1:
            value = UART_FIFO_RXTL0;
            break;

        case UART_RXTRIGLVL_4:
            value = UART_FIFO_RXTL1;
            break;

        case UART_RXTRIGLVL_8:
            value = UART_FIFO_RXTL2;
            break;

        case UART_RXTRIGLVL_14:
            value = UART_FIFO_RXTL3;
            break;

        default:
            value = UART_FIFO_RXTL0;
            break;
	}

    return (value);
}

static uint32_t UART_getParityType(UART_PAR parityType);
static uint32_t UART_getParityType(UART_PAR parityType)
{
    uint32_t value;

    switch (parityType)
    {
        case UART_PAR_NONE:
            value = (uint32_t)UART_PARITY_NONE;
            break;

        case UART_PAR_EVEN:
            value = (uint32_t)UART_EVEN_PARITY;
            break;

        case UART_PAR_ODD:
            value = (uint32_t)UART_ODD_PARITY;
            break;

        case UART_PAR_ZERO:
            value = (uint32_t)UART_PARITY_REPR_0;
            break;

        case UART_PAR_ONE:
            value = (uint32_t)UART_PARITY_REPR_1;
            break;

        default:
            value = (uint32_t)UART_PAR_NONE;
            break;
    }

    return (value);
}

/*
 *  ======== UART_open_v0 ========
 */
static UART_Handle UART_open_v0(UART_Handle handle, const UART_Params *params)
{
    uint32_t                 key;
    UART_V0_Object          *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const      *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    SemaphoreP_Params        semParams;
    uint32_t                 divisorValue;
    uint32_t                 fifoConfig;
    uint32_t                 rxTrigLevel;
    uint32_t                 parityType;
    OsalRegisterIntrParams_t interruptRegParams;
    MuxIntcP_inParams        muxInParams;
    MuxIntcP_outParams       muxOutParams;


    /* If params are NULL use defaults. */
    if (params == NULL)
    {
        UART_Params_init(&object->params);
    }
    else
    {
        /* Save UART parameters. */
        object->params = *params;
    }

    /* Disable preemption while checking if the UART is open. */
    key = UART_osalHardwareIntDisable();

    /* Check if the UART is open already with the base addr. */
    if(object->isOpen == TRUE)
    {
        UART_osalHardwareIntRestore(key);

        UART_drv_log1("UART:(%p) already in use.", hwAttrs->baseAddr);

        handle = (NULL);
    }

    /* UART is open by setting base addr */
    else
    {
        object->isOpen = (uint32_t)TRUE;
        UART_osalHardwareIntRestore(key);

        /* Set UART variables to defaults. */
        object->writeBuf = NULL;
        object->readBuf = NULL;
        object->writeCount = 0;
        object->readCount = 0;
        object->writeSize = 0;
        object->readSize = 0;
        object->writeCR = (uint32_t)FALSE;
        object->readTrans = NULL;
        object->writeTrans = NULL;

        if(hwAttrs->enableInterrupt)
        {
            /* Initialize with defaults */
            Osal_RegisterInterrupt_initParams(&interruptRegParams);

            /* Construct Hwi object for this UART peripheral. */
            if (hwAttrs->intcMuxNum != UART_INVALID_INTC_MUX_NUM)
            {
                /* Setup Chip Interrupt Controller */
                muxInParams.arg         = (uintptr_t)handle;
                muxInParams.muxNum      = hwAttrs->intcMuxNum;
                muxInParams.muxInEvent  = hwAttrs->intcMuxInEvent;
                muxInParams.muxOutEvent = hwAttrs->intcMuxOutEvent;
                muxInParams.muxIntcFxn  = (MuxIntcFxn)(&UART_v0_hwiIntFxn);

                muxOutParams.arg        = (uintptr_t)0U;
                muxOutParams.eventId    = 0U;
                muxOutParams.muxIntcFxn = (MuxIntcFxn)(NULL);

                UART_osalMuxIntcSetup(&muxInParams, &muxOutParams);

                interruptRegParams.corepacConfig.isrRoutine = muxOutParams.muxIntcFxn;
                interruptRegParams.corepacConfig.arg = (uintptr_t)muxOutParams.arg;
            }
            else
            {
                interruptRegParams.corepacConfig.isrRoutine = (&UART_v0_hwiIntFxn);
                interruptRegParams.corepacConfig.arg = (uintptr_t)handle;
            }

                /* Populate the interrupt parameters */
            interruptRegParams.corepacConfig.name=NULL;
            interruptRegParams.corepacConfig.intVecNum=hwAttrs->intNum; /* Host Interrupt vector */
#if defined(__TI_ARM_V5__)
            interruptRegParams.corepacConfig.priority =hwAttrs->eventId;
#else
            interruptRegParams.corepacConfig.priority = 0x20;
#endif

#if defined (__ARM_ARCH_7A__)
            interruptRegParams.corepacConfig.corepacEventNum=0; /* Event ID not used in GIC */
            interruptRegParams.corepacConfig.triggerSensitivity = 0x3; /* interrupt edge triggered */
#else
            interruptRegParams.corepacConfig.corepacEventNum=hwAttrs->eventId; /* Event going in to CPU */
#endif

                /* Register interrupts */
            UART_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));

            if(object->hwi == NULL)
            {
                handle = NULL;
            }
            else
            {
                UART_osalSemParamsInit(&semParams);
                semParams.mode = SemaphoreP_Mode_BINARY;
                /* If write mode is blocking construct a lock and set callback. */
                if (object->params.writeMode == UART_MODE_BLOCKING)
                {
                    semParams.name = "write";
                    object->writeSem = UART_osalCreateBlockingLock(0, &semParams);
                    object->params.writeCallback = NULL;
                    object->params.writeCallback2 = NULL;
                }

                /* If read mode is blocking create a lock and set callback. */
                if (object->params.readMode == UART_MODE_BLOCKING)
                {
                    semParams.name = "read";
                    object->readSem = UART_osalCreateBlockingLock(0, &semParams);
                    object->params.readCallback = NULL;
                    object->params.readCallback2 = NULL;
                }
            }
        }
        if (handle != NULL)
        {
            /* Reset and enable UART TX/RX in free-running mode */
            UART_pwremuConfig_v0(hwAttrs->baseAddr, UART_PWREMU_MGMT_ENABLE);

            /* Disable UART interrupts */
            UART_intDisable_v0(hwAttrs->baseAddr,
                               UART_INT_RHR_CTI | UART_INT_THR | UART_INT_LINE_STAT);
            rxTrigLevel = UART_getRxTrigLvl_v0(hwAttrs->rxTrigLvl);
#ifdef UART_DMA_ENABLE
            if (hwAttrs->dmaMode == TRUE)
            {
                /*FIFO and DMA setting */
                UART_fIFORegisterWrite_v0((uint32_t) hwAttrs->baseAddr,
                                          (uint32_t) 0x00U);

                /* Setting the RX FIFO Trigger levels, DMA enabled. */
                fifoConfig = UART_FIFO_CONFIG(rxTrigLevel,
                                              UART_FIFO_TXCLR,
                                              UART_FIFO_RXCLR,
                                              UART_FIFO_DMAMODE1_ENABLE);
                /* Configuring the FIFO settings. */
                UART_fIFOConfig_v0(hwAttrs->baseAddr, fifoConfig);

                UART_configDMA(handle);
            }
            else
#endif
            {
                /* Setting the RX FIFO Trigger levels as 1. No DMA enabled. */
                fifoConfig = UART_FIFO_CONFIG(rxTrigLevel,
                                              UART_FIFO_TXCLR,
                                              UART_FIFO_RXCLR,
                                              UART_FIFO_DMAMODE1_DISABLE);
                /* Configuring the FIFO settings. */
                UART_fIFOConfig_v0(hwAttrs->baseAddr, fifoConfig);
            }

            /* Computing the Divisor Value for params.baudRate */
            divisorValue = UART_divisorValCompute_v0(hwAttrs->frequency,
                                                     object->params.baudRate,
                                                     hwAttrs->operMode);
            /* Configuring the Baud Rate settings. */
            UART_divisorLatchWrite_v0(hwAttrs->baseAddr, divisorValue);

            /* Configuring UART line characteristics */
            parityType = UART_getParityType(object->params.parityType);
            UART_lineCharacConfig_v0(hwAttrs->baseAddr,
                                 (object->params.dataLength | object->params.stopBits),
                                 parityType);

            /* Disable write access to Divisor Latches. */
            UART_divisorLatchDisable_v0(hwAttrs->baseAddr);

            /* Disable Break Control. */
            UART_breakCtl_v0(hwAttrs->baseAddr, UART_BREAK_COND_DISABLE);

            if (hwAttrs->loopback == TRUE)
            {
                UART_loopbackModeControl_v0(hwAttrs->baseAddr, UART_LOOPBACK_MODE_ENABLE);
            }
            else
            {
                UART_loopbackModeControl_v0(hwAttrs->baseAddr, UART_LOOPBACK_MODE_DISABLE);
            }

            /* Enable UART */
            UART_operatingModeSelect_v0(hwAttrs->baseAddr, hwAttrs->operMode);

            UART_drv_log3("UART:(%p) CPU freq: %d; UART baudrate to %d",
                                    hwAttrs->baseAddr,
                                    hwAttrs->frequency,
                                    object->params.baudRate);

            UART_drv_log1("UART:(%p) opened", hwAttrs->baseAddr);
        }
    }
    /* Return the handle of the UART_Object. */
    return (handle);
}


/*
 *  ======== UART_v0_delete ========
 */
static void UART_close_v0(UART_Handle handle)
{
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

    /* Wait for TX FIFO empty */
    UART_fifoWait_v0(hwAttrs->baseAddr);

    /* Disable UART and interrupts. */
    UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_THR);
    UART_operatingModeSelect_v0(hwAttrs->baseAddr, UART_DISABLED_MODE);

#ifdef UART_DMA_ENABLE
    if (hwAttrs->dmaMode == TRUE)
    {
        UART_freeDmaChannel(handle);
    }
#endif
    if(hwAttrs->enableInterrupt) {
     /* Destruct the hwi. */
      UART_osalHardwareIntDestruct(object->hwi,hwAttrs->eventId);

      if (object->params.writeMode == UART_MODE_BLOCKING)
      {
        UART_osalDeleteBlockingLock(object->writeSem);
      }
      if (object->params.readMode == UART_MODE_BLOCKING)
      {
        UART_osalDeleteBlockingLock(object->readSem);
      }
	}  

    object->isOpen = (uint32_t)FALSE;

    UART_drv_log1("UART:(%p) closed", hwAttrs->baseAddr);
}


static int32_t UART_write_v0(UART_Handle handle, const void *buffer, size_t size)
{
    uint32_t             key;
    UART_V0_Object      *object = (UART_V0_Object*)handle->object;
    int32_t              ret_val = 0;
    UART_Transaction    *pTrans;
    UART_HwAttrs const  *hwAttrs;

    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

    if (hwAttrs->enableInterrupt)
    {
        /* Disable preemption while checking if the uart is in use. */
        key = UART_osalHardwareIntDisable();
        if (object->writeSize)
        {
            UART_osalHardwareIntRestore(key);
            ret_val = UART_ERROR;
        }
        else
        {
            UART_osalHardwareIntRestore(key);

            pTrans = &(object->wrTrans);
            pTrans->buf = (void *)buffer;
            pTrans->timeout = object->params.writeTimeout;
            pTrans->count = (uint32_t)size;
            UART_write2_v0(handle, pTrans);
            ret_val = pTrans->count;
       }
   }
   else
   {
       /* Use polling if interrupt is disabled */
       ret_val = UART_writePolling_v0(handle,buffer,size);
   }   
   
   return (ret_val);
}

static int32_t UART_write2_v0(UART_Handle handle, UART_Transaction * transaction)
{
    uint32_t            key;
    UART_V0_Object     *object;
    UART_HwAttrs const *hwAttrs;
    int32_t             ret_val = UART_SUCCESS;
    SemaphoreP_Status   semStatus;

    /* Input parameter validation */
    if ((handle != NULL)            &&
        (transaction != NULL)       &&
        (transaction->count != 0U))
    {
        /* Get the pointer to the hwAttrs */
        hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

        /* Get the pointer to the object */
        object = (UART_V0_Object*)handle->object;

        if(hwAttrs->enableInterrupt) {
        /* Disable preemption while checking if the uart is in use. */
        key = UART_osalHardwareIntDisable();
        if (object->writeSize)
        {
            UART_osalHardwareIntRestore(key);

            UART_drv_log1("UART:(0x%x) Could not write data, uart in use.",
                          hwAttrs->baseAddr);

            ret_val = UART_ERROR;
        }

        /* Save the data to be written and restore interrupts. */
        else
        {
            transaction->status = UART_TRANSFER_STATUS_SUCCESS;

            /*
             * When legacy UART_write API is called in callback mode,
             * object->params.writeCallback will save the callback function
             * pointer passed from the application, otherwise
             * object->params.writeCallback will be set to NULL.
             *
             * If legacy UART_write API is called in callback mode,
             * transaction parameter passed to UART_write2_v0 is
             * declared in the stack, and cannot be used in the ISR,
             * otherwise will cause data corruption in the stack.
             * The driver should only use object->writeTrans when it
             * is NOT called from egacy UART_write API in callback mode
             */
            if (object->params.writeCallback == NULL)
            {
                object->writeTrans = transaction;
            }
            else
            {
                object->writeTrans = NULL;
            }
            object->writeBuf = transaction->buf;
            object->writeCount = 0;
            object->txDataSent = FALSE;
            UART_fifoWait_v0(hwAttrs->baseAddr);

#ifdef UART_DMA_ENABLE
            if (hwAttrs->dmaMode == TRUE)
            {
                /* DMA mode */
                object->writeSize = transaction->count;
                UART_osalHardwareIntRestore(key);

                UART_transmitDMA(handle,(void*)object->writeBuf, object->writeSize);

                /* If writeMode is blocking, block and get the status. */
                if (object->params.writeMode == UART_MODE_BLOCKING)
                {
                    /* Pend on semaphore and wait for Hwi to finish. */
                    semStatus = UART_osalPendLock(object->writeSem,
                                                  transaction->timeout);
                    if (semStatus == SemaphoreP_OK)
                    {
                        if (transaction->status == UART_TRANSFER_STATUS_SUCCESS)
                        {
                            ret_val = UART_SUCCESS;
                        }
                        else
                        {
                            /* RX errors */
                            ret_val = UART_ERROR;
                        }
                    }
                    else
                    {
                        if (semStatus == SemaphoreP_TIMEOUT)
                        {
                            transaction->status = UART_TRANSFER_STATUS_TIMEOUT;
                        }
                        else
                        {
                            transaction->status = UART_TRANSFER_STATUS_ERROR_OTH;
                        }
                        /* Cancel the DMA without posting the semaphore */
                        UART_writeCancelNoCB(handle);
                        ret_val = UART_ERROR;
                    }
                }
                else
                {
                    /*
                     * for callback mode, immediately return SUCCESS,
                     * once the transaction is done, callback function
                     * will return the transaction status and actual
                     * write count
                     */
                    transaction->count = 0;
                    ret_val = UART_SUCCESS;
                }
            }
            else
#endif
            {
                /* non-DMA mode */
                UART_osalHardwareIntRestore(key);

                /* Disable TX threshold interrupt */
                UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_THR);

                object->writeSize = UART_writeData_v0(handle, (int32_t)(transaction->count));
                if ((object->writeSize) == 0)
                {
                    /* Write is finished. */
                    UART_drv_log2("UART(%p): Write finished, %d bytes written",
                                  hwAttrs->baseAddr, object->writeCount);

                    /* Reset the write buffer so we can pass it back */
                    object->writeBuf = (uint8_t *)object->writeBuf - object->writeCount;
                    if (object->writeTrans != NULL)
                    {
                        object->writeTrans->count = object->writeCount;
                        object->writeTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                    }
                    object->txDataSent = TRUE;
                    UART_intEnable_v0(hwAttrs->baseAddr, UART_INT_THR);
                }
                /* If writeMode is blocking, block and get the status. */
                else
                {
                    UART_intEnable_v0(hwAttrs->baseAddr, UART_INT_THR);
                }

                if (object->params.writeMode == UART_MODE_BLOCKING)
                {
                    /* Pend on lock and wait for Hwi to finish. */
                    semStatus = UART_osalPendLock(object->writeSem,
                                                  transaction->timeout);
                    if (semStatus == SemaphoreP_OK)
                    {
                        if (transaction->status == UART_TRANSFER_STATUS_SUCCESS)
                        {
                            ret_val = UART_SUCCESS;
                        }
                        else
                        {
                            ret_val = UART_ERROR;
                        }
                    }
                    else
                    {
                        if (semStatus == SemaphoreP_TIMEOUT)
                        {
                            transaction->status = UART_TRANSFER_STATUS_TIMEOUT;
                        }
                        else
                        {
                            transaction->status = UART_TRANSFER_STATUS_ERROR_OTH;
                        }
                        /* Cancel the DMA without posting the semaphore */
                        UART_writeCancelNoCB(handle);
                        ret_val = UART_ERROR;
                    }
                }
                else
                {
                    /*
                     * for callback mode, immediately return SUCCESS,
                     * once the transaction is done, callback function
                     * will return the transaction status and actual
                     * write count
                     */
                    transaction->count = 0;
                    ret_val = UART_SUCCESS;
                }
            }
          }
        }
        else
        {
            /* Use polling if interrupt is disabled */
            transaction->count = UART_writePolling_v0(handle,transaction->buf,transaction->count);
            transaction->status = UART_TRANSFER_STATUS_SUCCESS;
        }
    }
    else
    {
        ret_val = UART_ERROR;
    }

    return(ret_val);
}

/*
 *  ======== UART_charPut ========
 *
 *  This function continuously does a non-blocking write, until it writes
 *  successfully or times out.
 */
static uint32_t UART_charPut(UART_HwAttrs const *hwAttrs, uint8_t data, uint32_t *timeout);  /*for misra warnings*/
static uint32_t UART_charPut(UART_HwAttrs const *hwAttrs, uint8_t data, uint32_t *timeout)
{
    uint32_t status;
    uint32_t timeoutCnt = *timeout;
    uint32_t retVal = TRUE;

    while (retVal == TRUE)
    {
        status = UART_fifoEmpty_v0(hwAttrs->baseAddr);
        if (status == FALSE)
        {
            if (timeoutCnt == 0)
            {
                retVal = FALSE;
            }
            else
            {
                UART_osalDelay(1U);
                timeoutCnt--;
            }
        }
        else
        {
            UART_fIFOCharPut_v0(hwAttrs->baseAddr, data);
            break;
        }
    }

    *timeout =  timeoutCnt;

    return (retVal);
}

/*
 *  ======== UART_writePolling_v0 ========
 */
static int32_t UART_writePolling_v0(UART_Handle handle, const void *buf,
                                     size_t size)
{
    int32_t             count = 0;
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    uint8_t            *buffer = (uint8_t *)buf;
    uint32_t            timeout;
    uint32_t            timeoutErr = FALSE;

    timeout = object->params.writeTimeout;

    /* Write characters. */
    while ((size != 0) && (timeoutErr == FALSE))
    {
        if ((object->params.writeDataMode == UART_DATA_TEXT) && (*buffer == (uint8_t)'\n'))
        {
            if (UART_charPut(hwAttrs, ((uint8_t)('\r')), &timeout) == FALSE)
            {
                timeoutErr = TRUE;
            }
            else
            {
                count++;
            }
        }

        if (timeoutErr == FALSE)
        {
            if (UART_charPut(hwAttrs, *buffer, &timeout) == FALSE)
            {
                timeoutErr = TRUE;
            }
            else
            {
                UART_drv_log2("UART:(%p) Wrote character 0x%x",
                           hwAttrs->baseAddr, *buffer);

                buffer++;
                count++;
                size--;
            }
        }
    }

    if (timeoutErr == TRUE)
    {
        UART_drv_log2("UART:(%p) Write polling timed out, %d bytes written",
                      hwAttrs->baseAddr, count);
    }
    else
    {
        UART_drv_log2("UART:(%p) Write polling finished, %d bytes written",
                   hwAttrs->baseAddr, count);
    }

    return (count);
}

/*
 *  ======== UART_writeCancel_v0 ========
 */
static void UART_writeCancel_v0(UART_Handle handle);   /* for misra warnings*/
static void UART_writeCancel_v0(UART_Handle handle)
{
    if (UART_writeCancelNoCB(handle) == true)
    {
        UART_v0_callback(handle, false);

        UART_drv_log2("UART:(%p) Write cancelled, %d bytes written",
                      ((UART_HwAttrs const *)(handle->hwAttrs))->baseAddr,
                      object->writeCount);
    }
}

/*
 *  ======== UART_charGet ========
 *
 *  This function continuously does a non-blocking read, until it reads
 *  successfully or times out.
 */
static uint32_t UART_charGet(UART_HwAttrs const *hwAttrs, uint8_t *data, uint32_t *timeout);  /*for misra warnings*/
static uint32_t UART_charGet(UART_HwAttrs const *hwAttrs, uint8_t *data, uint32_t *timeout)
{
    uint8_t  rdData;
    uint32_t timeoutCnt = *timeout;
    uint32_t retVal = TRUE;
    uint32_t rdSuccess;

    while (retVal == TRUE)
    {
        rdSuccess = UART_charGetNonBlocking2_v0(hwAttrs->baseAddr, &rdData);
        if (rdSuccess == FALSE)
        {
            if (timeoutCnt == 0)
            {
                retVal = FALSE;
            }
            else
            {
                UART_osalDelay(1U);
                timeoutCnt--;
            }
        }
        else
        {
            *data = rdData;
            break;
        }
    }

    *timeout = timeoutCnt;

    return (retVal);
}

/*
 *  ======== UART_readPolling_v0 ========
 */
static int32_t UART_readPolling_v0(UART_Handle handle, void *buf, size_t size)
{
    int32_t                count = 0;
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    uint8_t               *buffer = (uint8_t *)buf;
    uint32_t               timeout;
    uint8_t                ret_flag = 0U;
    uint32_t               timeoutErr = FALSE;

    timeout = object->params.readTimeout;

    /* Read characters. */
    while ((size != 0) && (timeoutErr == FALSE))
    {
        if (UART_charGet(hwAttrs, buffer, &timeout) == FALSE)
        {
            timeoutErr = TRUE;
        }
        else
        {
            UART_drv_log2("UART:(%p) Read character 0x%x",
                       hwAttrs->baseAddr, *buffer);

            count++;
            size--;

            if ((object->params.readDataMode == UART_DATA_TEXT) && (*buffer == (uint8_t)'\r'))
            {
                /* Echo character if enabled. */
                if (object->params.readEcho)
                {
                    if (UART_charPut(hwAttrs, ((uint8_t)('\r')), &timeout) == FALSE)
                    {
                        timeoutErr = TRUE;
                    }
                }
                if (timeoutErr == FALSE)
                {
                    *buffer = (uint8_t)'\n';
                }
            }

            /* Echo character if enabled. */
            if ((timeoutErr == FALSE) && (object->params.readEcho == UART_ECHO_ON))
            {
                if (UART_charPut(hwAttrs, *buffer, &timeout) == FALSE)
                {
                    timeoutErr = TRUE;
                }
            }

            /* If read return mode is newline, finish if a newline was received. */
            if ((timeoutErr == FALSE) &&
                (object->params.readReturnMode == UART_RETURN_NEWLINE) &&
                (*buffer == ((uint8_t)('\n'))))
            {
                ret_flag = 1U;
                break;
            }
            else
            {
                buffer++;
            }
        }
    }

    if(timeoutErr == FALSE)
    {
        UART_drv_log2("UART:(%p) Read polling timed out, %d bytes read",
                      hwAttrs->baseAddr, count);
    }

    if(ret_flag == 0U)
    {   
        UART_drv_log2("UART:(%p) Read polling finished, %d bytes read",
               hwAttrs->baseAddr, count);
    }

    return (count);
}

/*
 *  ======== UART_readCancel_v0 ========
 */
static void UART_readCancel_v0(UART_Handle handle);   /* for misra warnings*/
static void UART_readCancel_v0(UART_Handle handle)
{
    if (UART_readCancelNoCB(handle) == true)
    {
    	UART_v0_callback(handle, true);

        UART_drv_log2("UART:(%p) Read cancelled, %d bytes read",
                      ((UART_HwAttrs const *)(handle->hwAttrs))->baseAddr,
                      object->readCount);
    }
}

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_control().
 */
static int32_t UART_control_v0 (UART_Handle handle, uint32_t cmd, void *arg)  /*for misra warnings*/
{
    return(0);
}

/*
 *  ======== UART_read_v0 ========
 */
static int32_t UART_read_v0(UART_Handle handle, void *buffer, size_t size)
{
    uint32_t            key;
    UART_V0_Object     *object;
    int32_t             ret_val = 0;
    UART_Transaction   *pTrans;
    UART_HwAttrs const *hwAttrs;

    /* Get the pointer to the object */
    object = (UART_V0_Object*)handle->object;
    /* Get the pointer to the hwAttrs */
    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
	if (hwAttrs->enableInterrupt)
	{
        /* Disable preemption while checking if the uart is in use. */
        key = UART_osalHardwareIntDisable();
        if (object->readSize)
        {
            UART_osalHardwareIntRestore(key);
            ret_val = UART_ERROR;
        }
        else
        {
            UART_osalHardwareIntRestore(key);

            pTrans = &(object->wrTrans);
            pTrans->buf = (void *)buffer;
            pTrans->timeout = object->params.readTimeout;
            pTrans->count = (uint32_t)size;
            UART_read2_v0(handle, pTrans);
            ret_val = pTrans->count;
        }
    }
    else
    {
       ret_val = UART_readPolling_v0(handle,buffer,size);
    }
    return (ret_val);
}

/*
 *  ======== UART_read2_v0 ========
 */
static int32_t UART_read2_v0(UART_Handle handle, UART_Transaction *transaction)
{
    uint32_t            key;
    UART_V0_Object     *object;
    UART_HwAttrs const *hwAttrs;
    int32_t             ret_val = UART_SUCCESS;
    SemaphoreP_Status   semStatus;

    /* Input parameter validation */
    if ((handle != NULL)            &&
        (transaction != NULL)       &&
        (transaction->count != 0U))
    {
        /* Get the pointer to the hwAttrs */
        hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

        /* Get the pointer to the object */
        object = (UART_V0_Object*)handle->object;
        if(hwAttrs->enableInterrupt)
        {
            /* Disable preemption while checking if the uart is in use. */
            key = UART_osalHardwareIntDisable();
            if (object->readSize)
            {
                UART_osalHardwareIntRestore(key);

                UART_drv_log1("UART:(0x%x) Could not read data, uart in use.",
                              hwAttrs->baseAddr);

                ret_val = UART_ERROR;
            }
            else
            {
                /* Save the data to be read and restore interrupts. */
                transaction->status = UART_TRANSFER_STATUS_SUCCESS;

                /*
                 * When legacy UART_read API is called in callback mode,
                 * object->params.readCallback will save the callback function
                 * pointer passed from the application, otherwise
                 * object->params.readCallback will be set to NULL.
                 *
                 * If legacy UART_read API is called in callback mode,
                 * transaction parameter passed to UART_read2_v0 is
                 * declared in the stack, and cannot be used in the ISR,
                 * otherwise will cause data corruption in the stack.
                 * The driver should only use object->readTrans when it
                 * is NOT called from egacy UART_read API in callback mode
                 */
                if (object->params.readCallback == NULL)
                {
                    object->readTrans = transaction;
                }
                else
                {
                    object->readTrans = NULL;
                }
                object->readBuf = transaction->buf;
                object->readCount = 0;

#ifdef UART_DMA_ENABLE
                if (hwAttrs->dmaMode == TRUE)
                {
                    /* DMA mode */
                    object->readSize = transaction->count;
                    UART_osalHardwareIntRestore(key);

                    UART_intEnable_v0(hwAttrs->baseAddr, UART_INT_LINE_STAT);
                    UART_receiveDMA(handle,(void*)object->readBuf, object->readSize);

                    /* If readMode is blocking, block and get the status. */
                    if (object->params.readMode == UART_MODE_BLOCKING)
                    {
                        /* Pend on semaphore and wait for Hwi to finish. */
                        semStatus = UART_osalPendLock(object->readSem,
                                                      transaction->timeout);
                        if (semStatus == SemaphoreP_OK)
                        {
                            if (transaction->status == UART_TRANSFER_STATUS_SUCCESS)
                            {
                                ret_val = UART_SUCCESS;
                            }
                            else
                            {
                                /* RX errors */
                                ret_val = UART_ERROR;
                            }
                        }
                        else
                        {
                            if (semStatus == SemaphoreP_TIMEOUT)
                            {
                                transaction->status = UART_TRANSFER_STATUS_TIMEOUT;
                            }
                            else
                            {
                                transaction->status = UART_TRANSFER_STATUS_ERROR_OTH;
                            }
                            /* Cancel the read without posting the semaphore */
                            UART_readCancelNoCB(handle);
                            ret_val = UART_ERROR;
                        }
                    }
                    else
                    {
                        /*
                         * for callback mode, immediately return SUCCESS,
                         * once the transaction is done, callback function
                         * will return the transaction status and actual
                         * write count
                         */
                        transaction->count = 0;
                        ret_val = UART_SUCCESS;
                    }
                }
                else
#endif
                {
                    /* non-DMA mode */
                    UART_osalHardwareIntRestore(key);

                    /* Disable RX threshold and line status error interrupt */
                    UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_LINE_STAT);

                    object->readSize = UART_v0_readData(handle, (int32_t)(transaction->count));
                    if ((object->readSize) == 0)
                    {
                        /* Read is finished. */
                        UART_drv_log2("UART:(0x%x) Read finished, %d bytes read",
                                      hwAttrs->baseAddr, object->readCount);

                        /* Update the actual read count */
                        transaction->count = object->readCount;

                        if (object->params.readMode == UART_MODE_CALLBACK)
                        {
                            UART_v0_callback(handle, true);
                        }
                        ret_val = UART_SUCCESS;
                    }
                    else
                    {
                        UART_intEnable_v0(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_LINE_STAT);
                        if (object->params.readMode == UART_MODE_BLOCKING)
                        {
                            /* Pend on lock and wait for Hwi to finish. */
                            semStatus = UART_osalPendLock(object->readSem,
                                                         transaction->timeout);
                            if (semStatus == SemaphoreP_OK)
                            {
                                if (transaction->status == UART_TRANSFER_STATUS_SUCCESS)
                                {
                                    ret_val = UART_SUCCESS;
                                }
                                else
                                {
                                    ret_val = UART_ERROR;
                                }
                            }
                            else
                            {
                                if (semStatus == SemaphoreP_TIMEOUT)
                                {
                                    transaction->status = UART_TRANSFER_STATUS_TIMEOUT;
                                }
                                else
                                {
                                    transaction->status = UART_TRANSFER_STATUS_ERROR_OTH;
                                }
                                /* Cancel the read without posting the semaphore */
                                UART_readCancelNoCB(handle);
                                ret_val = UART_ERROR;
                            }
                        }
                        else
                        {
                            /*
                             * for callback mode, immediately return SUCCESS,
                             * once the transaction is done, callback function
                             * will return the transaction status and actual
                             * read count
                             */
                            transaction->count = 0;
                            ret_val = UART_SUCCESS;
                        }
                    }
                }
            }
        }
        else
        {
           transaction->count = UART_readPolling_v0(handle,transaction->buf,transaction->count);
           transaction->status = UART_TRANSFER_STATUS_SUCCESS;
        }
    }
    else
    {
        ret_val = UART_ERROR;
    }

    return(ret_val);
}

static bool UART_writeCancelNoCB(UART_Handle handle)
{
    uint32_t            key;
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    bool                retVal = true;

    UART_intDisable_v0(hwAttrs->baseAddr, UART_INT_THR);

    /* Disable interrupts to avoid writing data while changing state. */
    key = UART_osalHardwareIntDisable();

    /* Return if there is no write. */
    if ((object->writeSize) == 0U)
    {
        UART_osalHardwareIntRestore(key);
        retVal = false;
    }
    else
    {
#ifdef UART_DMA_ENABLE
        if (hwAttrs->dmaMode == TRUE)
        {
            /* Disable DMA TX channel */
            UART_disableDmaChannel(handle, true);

            if (object->writeTrans != NULL)
            {
                object->writeTrans->count = 0;
            }
            else
            {
                object->writeCount = 0;
            }
        }
        else
#endif
        {
            /* Reset the write buffer so we can pass it back */
            object->writeBuf = (uint8_t *)object->writeBuf - object->writeCount;
            if (object->writeTrans != NULL)
            {
                object->writeTrans->count = object->writeCount;
            }
        }

        /* Set size = 0 to prevent writing and restore interrupts. */
        object->writeSize = 0;
        UART_osalHardwareIntRestore(key);

        /* Flush the TX FIFO */
        UART_fifoWait_v0(hwAttrs->baseAddr);
    }

    return (retVal);
}

static bool UART_readCancelNoCB(UART_Handle handle)
{
    uint32_t            key;
    UART_V0_Object     *object = (UART_V0_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    bool                retVal = true;
    uint8_t             rdData;

    UART_intDisable_v0(hwAttrs->baseAddr,
                       UART_INT_RHR_CTI | UART_INT_LINE_STAT);

    /* Disable interrupts to avoid reading data while changing state. */
    key = UART_osalHardwareIntDisable();
    if ((object->readSize) == 0U)
    {
        UART_osalHardwareIntRestore(key);
        retVal = false;
    }
    else
    {
#ifdef UART_DMA_ENABLE
        if (hwAttrs->dmaMode == TRUE)
        {
            /* Disable DMA RX channel */
            UART_disableDmaChannel(handle, false);

            if (object->readTrans != NULL)
            {
                object->readTrans->count = 0;
            }
            else
            {
                object->readCount = 0;
            }
        }
        else
#endif
        {
            /* Reset the read buffer so we can pass it back */
            object->readBuf = (uint8_t *)object->readBuf - object->readCount;
            if (object->readTrans != NULL)
            {
                object->readTrans->count = object->readCount;
            }
        }

        /* Set size = 0 to prevent reading and restore interrupts. */
        object->readSize = 0;
        UART_osalHardwareIntRestore(key);

        /* Flush the RX FIFO */
        while (UART_charGetNonBlocking2_v0(hwAttrs->baseAddr, &rdData) != FALSE);
    }

    return (retVal);
}
