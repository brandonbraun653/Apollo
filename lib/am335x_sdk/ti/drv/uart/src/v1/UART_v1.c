/**
 * @file   UART_v1.c
 *
 * @brief  This file implements the combined EDMA based and non-EDMA based
 *         UART driver interface APIs for IP of version V1
 */
/*
 * Copyright (c) 2014-2017, Texas Instruments Incorporated
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
#include <ti/drv/uart/src/v1/UART_v1.h>
#include <ti/csl/src/ip/uart/V1/uart.h>
#include <ti/csl/src/ip/uart/V1/hw_uart.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/csl/src/ip/uart/V1/cslr_uart.h>
#include <ti/drv/uart/src/UART_drv_log.h>



/* UART_v1 functions */
static void         UART_close_v1(UART_Handle handle);
static void         UART_init_v1(UART_Handle handle);
static UART_Handle  UART_open_v1(UART_Handle handle, const UART_Params *params);
static int32_t          UART_read_v1(UART_Handle handle, void *buffer,
                                      size_t size);
static int32_t          UART_readPolling_v1(UART_Handle handle, void *buf,
                                             size_t size);
static void         UART_readCancel_v1(UART_Handle handle);
static int32_t          UART_write_v1(UART_Handle handle, const void *buffer,
                                       size_t size);
static int32_t          UART_writePolling_v1(UART_Handle handle,
                                              const void *buf, size_t size);
static void         UART_writeCancel_v1(UART_Handle handle);

static  int32_t         UART_control_v1(UART_Handle handle,
                                               uint32_t cmd,
                                               void *arg);
static int32_t      UART_read2_v1(UART_Handle handle, UART_Transaction *transaction);
static int32_t      UART_write2_v1(UART_Handle handle, UART_Transaction *transaction);

static void         UART_v1_hwiIntFxn(uintptr_t arg);
static void UARTFifoWait(uint32_t baseAdd);
static bool UART_writeCancelNoCB(UART_Handle handle);
static bool UART_readCancelNoCB(UART_Handle handle);

/* UART function table for UART_v1 implementation */
const UART_FxnTable UART_FxnTable_v1 = {
    &UART_close_v1,
    &UART_control_v1,
    &UART_init_v1,
    &UART_open_v1,
    &UART_read_v1,
    &UART_readPolling_v1,
    &UART_readCancel_v1,
    &UART_write_v1,
    &UART_writePolling_v1,
    &UART_writeCancel_v1,
    &UART_read2_v1,
    &UART_write2_v1,

};

/*
 *  ======== UART_writeData_v1 ========
 *  Write and process data to the UART.
 */
static inline int32_t UART_writeData_v1(UART_Handle handle, int32_t size); /* for misra warnings*/
static inline int32_t UART_writeData_v1(UART_Handle handle, int32_t size)
{
    UART_V1_Object     *object;
    UART_HwAttrs const *hwAttrs;
    int32_t             wrSize = size;

    object = (UART_V1_Object*)handle->object;
    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

    uint8_t FIFO_FULL_FLAG = 0U;

    /* Send characters until FIFO is full or done. */
    while ((wrSize != 0) && (FIFO_FULL_FLAG == 0U))
    {
        /* If mode is TEXT process the characters */
        if (object->params.writeDataMode == UART_DATA_TEXT)
        {
            if (object->writeCR == TRUE)
            {
                if (UARTTxFIFOFullStatusGet(hwAttrs->baseAddr) ==
                    UART_TX_FIFO_FULL)
                {
                    /* Character was not sent, FIFO full */
                    FIFO_FULL_FLAG = 1U;
                }
                /* FIFO not full, write '\r' to FIFO */
                else
                {
                    UARTFIFOCharPut(hwAttrs->baseAddr, ((uint8_t)('\r')));
                    wrSize--;
                    object->writeCount++;
                    object->writeCR = FALSE;

                    UART_drv_log1("UART:(0x%x) Wrote character ", hwAttrs->baseAddr);
                }
            }
            else
            {
                /* Add a return if next character is a newline. */
                if (*(const uint8_t *)object->writeBuf == ((uint8_t)('\n')))
                {
                    wrSize++;
                    object->writeCR = TRUE;
                }

                if (UARTTxFIFOFullStatusGet(hwAttrs->baseAddr) ==
                    UART_TX_FIFO_FULL)
                {
                    /* FIFO full */
                    if (object->writeCR == TRUE)
                    {
                        wrSize--;
                        object->writeCR = FALSE;
                    }
                    FIFO_FULL_FLAG = 1U;
                }
                /* FIFO not full, write to FIFO */
                else
                {
                    UARTFIFOCharPut(hwAttrs->baseAddr, *(const uint8_t *)object->writeBuf);
                    object->writeBuf = (const uint8_t *)object->writeBuf + 1;

                    UART_drv_log2("UART:(0x%x) Wrote character 0x%x",
                                  hwAttrs->baseAddr, *(const uint8_t *)object->writeBuf);

                    wrSize--;
                    object->writeCount++;
                }
            }
        }
        else
        {
            if (UARTTxFIFOFullStatusGet(hwAttrs->baseAddr) ==
                UART_TX_FIFO_FULL)
            {
                /* FIFO full */
                FIFO_FULL_FLAG = 1U;
            }
            /* FIFO not full, write character */
            else
            {
                UARTFIFOCharPut(hwAttrs->baseAddr, *(const uint8_t *)object->writeBuf);
                object->writeBuf = (const uint8_t *)object->writeBuf + 1;

                UART_drv_log2("UART:(0x%x) Wrote character 0x%x",
                              hwAttrs->baseAddr, *(const uint8_t *)object->writeBuf);

                wrSize--;
                object->writeCount++;
            }
        }
    }
    return (wrSize);
}

/*
 *  ======== UART_v1_readData ========
 *  Read and process data from the UART.
 */
static inline int32_t UART_v1_readData(UART_Handle handle, int32_t size);   /* for misra warnings*/
static inline int32_t UART_v1_readData(UART_Handle handle, int32_t size)
{
    uint8_t             readIn;
    UART_V1_Object     *object;
    UART_HwAttrs const *hwAttrs;
    uint32_t            readSuccess;
    int32_t             rdSize = size;

    object = (UART_V1_Object*)handle->object;
    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    readSuccess = UARTCharGetNonBlocking2(hwAttrs->baseAddr, &readIn);

    /* Receive chars until empty or done. */
    while ((rdSize != (int32_t)(0)) && (readSuccess != FALSE))
    {
        /* If data mode is set to TEXT replace return with a newline. */
        if (object->params.readDataMode == UART_DATA_TEXT)
        {
            if (readIn == ((uint8_t)('\r')))
            {
                /* Echo character if enabled. */
                if (object->params.readEcho == UART_ECHO_ON)
                {
                    UARTCharPut(hwAttrs->baseAddr, ((uint8_t)('\r')));
                }
                readIn = (uint8_t)'\n';
            }
        }

        UART_drv_log2("UART:(0x%x) Read character 0x%x",
                      hwAttrs->baseAddr, readIn);

        *(uint8_t *)object->readBuf = readIn;
        object->readBuf = (uint8_t *)object->readBuf + 1;
        object->readCount++;
        rdSize--;

        /* Echo character if enabled. */
        if (object->params.readEcho == UART_ECHO_ON)
        {
            UARTCharPut(hwAttrs->baseAddr, (uint8_t)readIn);
        }

        /* If read return mode is newline, finish if a newline was received. */
        if ((object->params.readReturnMode == UART_RETURN_NEWLINE) &&
            (readIn == ((uint8_t)('\n'))))
        {
            UART_drv_log1("UART:(0x%x) Newline character received, ",
            		      hwAttrs->baseAddr);
            rdSize = 0;
            break;
        }

        /* If read returnMode is UART_RETURN_FULL, avoids missing input character
         * of next read
         */
        if (rdSize != 0)
        {
            readSuccess = UARTCharGetNonBlocking2(hwAttrs->baseAddr, &readIn);
        }

    }

    return (rdSize);
}

void UART_v1_callback(UART_Handle handle, bool readTrans);   /* for misra warnings*/
void UART_v1_callback(UART_Handle handle, bool readTrans)
{
    UART_V1_Object *object = (UART_V1_Object*)handle->object;

    /* Call back to application */
    if (readTrans == (bool)true)
    {
        if (object->params.readCallback2 != NULL)
        {
            object->params.readCallback2(handle, object->readTrans);
        }
        else if (object->params.readCallback != NULL)
        {
            object->params.readCallback(handle,
                                        object->readBuf,
                                        object->readCount);
        }
        else
        {
            (void)UART_osalPostLock(object->readSem);
        }
    }
    else
    {
        if (object->params.writeCallback2 != NULL)
        {
            object->params.writeCallback2(handle, object->writeTrans);
        }
        else if (object->params.writeCallback != NULL)
        {
            object->params.writeCallback(handle,
                                         (void *)(object->writeBuf),
                                         object->writeCount);
        }
        else
        {
            (void)UART_osalPostLock(object->writeSem);
        }
    }
}

static inline void UART_procLineStatusErr(UART_Handle handle);   /* for misra warnings*/
static inline void UART_procLineStatusErr(UART_Handle handle)
{
    UART_V1_Object     *object = (UART_V1_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    uint32_t            lineStatus;

    if (object->readSize > 0U)
    {
        lineStatus = UARTReadStatus(hwAttrs->baseAddr);

        if (((lineStatus & UART_FIFO_PE_FE_BI_DETECTED) == UART_FIFO_PE_FE_BI_DETECTED) ||
            ((lineStatus & UART_OVERRUN_ERROR) == UART_OVERRUN_ERROR))
        {
            /* empty the RX FIFO which contains data with errors */
#ifdef UART_DMA_ENABLE
            if (hwAttrs->dmaMode == TRUE)
            {
                /* Disable DMA RX channel */
                UART_disableDmaChannel(handle, (bool)false);

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
                    object->readTrans->count = (uint32_t)(object->readCount);
                }
            }
            /* dummy read, clear the RX line status interrupt */
            (void)UART_v1_readData(handle, (int32_t)(object->readSize));
            UARTIntDisable(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_LINE_STAT);

            /* Reset the read buffer and read count so we can pass it back */
            object->readBuf = (uint8_t *)object->readBuf - object->readCount;

            if (object->readTrans != NULL)
            {
                if ((lineStatus & UART_BREAK_DETECTED_ERROR) != 0U)
                {
                    object->readTrans->status = UART_TRANSFER_STATUS_ERROR_BI;
                }
                else if ((lineStatus & UART_FRAMING_ERROR) != 0U)
                {
                    object->readTrans->status = UART_TRANSFER_STATUS_ERROR_FE;
                }
                else if ((lineStatus & UART_PARITY_ERROR) != 0U)
                {
                    object->readTrans->status = UART_TRANSFER_STATUS_ERROR_PE;
                }
                else
                {
                    object->readTrans->status = UART_TRANSFER_STATUS_ERROR_OE;
                }
            }

            /* Call back to application if in callback mode */
            UART_v1_callback(handle, (bool)true);
            object->readTrans = NULL;
        }
    }
}

/*
 *  ======== UART_v1_hwiIntFxn ========
 *  Hwi function that processes UART interrupts.
 *
 *  In non-DMA mode, four UART interrupts are enabled:
 *    1. transmit FIFO is below the TX FIFO trigger level (THR)
 *    2. receive FIFO is above RX FIFO trigger level (RHR)
 *    3. line status rx error
 *    4. TX FIFO empty
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
 *  to write the data to the TX FIFO. After all the data are sent, TX FIFO empty 
 *  interrupt is enabled, ISR will update the actual number of bytes transferred 
 *  and transfer status in writeTrans and calls back to application in the callback 
 *  mode or post the read semaphone in the blocking mode.
 *  
 *  TX FIFO empty interrupt is enabled after all the data are written to the TX
 *  FIFO, ISR will 
 *
 *  In DMA mode, three UART interrupt is enabled:
 *    1. line status rx error
 *    2. receive FIFO is above RX FIFO trigger level (RHR)
 *    3. TX FIFO empty
 *
 *  If line status rx error is detected, ISR clears the last read error, update
 *  the actual number of bytes transferred and transfer status in readTrans,
 *  disables the DMA RX channel and calls back to application in the callback mode
 *  or post the read semaphone in the blocking mode.
 *
 *  DMA RX transfer completion is handled in UART_rxIsrHandler. If the read size 
 *  is not multiple of RX threshold size, RHR interrupt is enabled to receive the 
 *  remaining bytes in ISR.  
 *  
 *  TX transfer completion is handled in UART_txIsrHandler. After all the data are 
 *  sent, TX FIFO empty interrupt is enabled, ISR will update the actual number of 
 *  bytes transferred and transfer status in writeTrans and calls back to application 
 *  in the callback mode or post the read semaphone in the blocking mode.
 *
 *  @param(arg)         The UART_Handle for this Hwi.
 */
static void UART_v1_hwiIntFxn(uintptr_t arg);   /* for misra warnings*/
static void UART_v1_hwiIntFxn(uintptr_t arg)
{
    UART_Handle         handle = (UART_Handle)arg;
    UART_V1_Object     *object = (UART_V1_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    uint32_t            intType;
    uint8_t             rdData;

    while ((bool)true)
    {
        intType = UARTIntIdentityGet(hwAttrs->baseAddr);
        
        if ((intType & UART_INTID_RX_THRES_REACH) == UART_INTID_RX_THRES_REACH)
        {
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
                if (object->readSize > 0U)
                {
                    object->readSize = (size_t)UART_v1_readData(handle, (int32_t)(object->readSize));
                    if ((object->readSize) == 0U)
                    {
                        UARTIntDisable(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_LINE_STAT);
                        /* Reset the read buffer so we can pass it back */
                        object->readBuf = (uint8_t *)object->readBuf - object->readCount;
                        if (object->readTrans != NULL)
                        {
                            object->readTrans->count = (uint32_t)(object->readCount);
                            object->readTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                        }

                        /* Call back to application if in callback mode */
                        UART_v1_callback(handle, (bool)true);
                        object->readTrans = NULL;
                    }
                }
                else
                {
                    (void)UARTCharGetNonBlocking2(hwAttrs->baseAddr, &rdData);
                    UARTIntDisable(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_LINE_STAT);
                }
            }
        }
        else if ((intType & UART_INTID_TX_THRES_REACH) == UART_INTID_TX_THRES_REACH)
        {
            /* TX FIFO threshold reached */
            if (object->writeSize > 0U)
            {
                object->writeSize = (size_t)UART_writeData_v1(handle, (int32_t)(object->writeSize));
                if ((object->writeSize) == 0U)
                {
                    UARTIntDisable(hwAttrs->baseAddr, UART_INT_THR);
                    /* Reset the write buffer so we can pass it back */
                    object->writeBuf = (const uint8_t *)object->writeBuf - object->writeCount;

                    if (object->writeTrans != NULL)
                    {
                        object->writeTrans->count = (uint32_t)(object->writeCount);
                        object->writeTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                    }

                    object->txDataSent = TRUE;
                    UARTInt2Enable(hwAttrs->baseAddr, UART_INT2_TX_EMPTY);
                }
            }
            else
            {
                UARTIntDisable(hwAttrs->baseAddr, UART_INT_THR);
            }
        }
        else
        {
            break;
        }
    }

    if (object->txDataSent == TRUE)
    {
        intType = UARTInt2StatusGet(hwAttrs->baseAddr);
        if ((intType & UART_INT2_TX_EMPTY) != 0U)
        {
            UARTInt2Disable(hwAttrs->baseAddr, UART_INT2_TX_EMPTY);

            /* Call back to application if in callback mode */
            UART_v1_callback(handle, (bool)false);
            object->writeTrans = NULL;
            object->txDataSent = FALSE;
        }
    }
}

/*
 *  ======== UART_init_v1 ========
 */
static void UART_init_v1(UART_Handle handle)
{
    /* Mark the object as available */
    ((UART_V1_Object *)(handle->object))->isOpen = FALSE;
}

static uint32_t UART_getTxTrigLvl(UART_TxTrigLvl trigLevel);   /* for misra warnings*/
static uint32_t UART_getTxTrigLvl(UART_TxTrigLvl trigLevel)
{
    uint32_t value;

    switch (trigLevel)
	{
        case UART_TXTRIGLVL_8:
            value = UART_FCR_TX_TRIG_LVL_8;
            break;

        case UART_TXTRIGLVL_16:
            value = UART_FCR_TX_TRIG_LVL_16;
            break;

        case UART_TXTRIGLVL_32:
            value = UART_FCR_TX_TRIG_LVL_32;
            break;

        case UART_TXTRIGLVL_56:
            value = UART_FCR_TX_TRIG_LVL_56;
            break;

        default:
        	value = 0;
            break;
	}

    return (value);
}

static uint32_t UART_getRxTrigLvl(UART_RxTrigLvl trigLevel);   /* for misra warnings*/
static uint32_t UART_getRxTrigLvl(UART_RxTrigLvl trigLevel)
{
    uint32_t value;

    switch (trigLevel)
	{
        case UART_RXTRIGLVL_8:
            value = UART_FCR_RX_TRIG_LVL_8;
            break;

        case UART_RXTRIGLVL_16:
            value = UART_FCR_RX_TRIG_LVL_16;
            break;

        case UART_RXTRIGLVL_56:
            value = UART_FCR_RX_TRIG_LVL_56;
            break;

        case UART_RXTRIGLVL_60:
            value = UART_FCR_RX_TRIG_LVL_60;
            break;

        default:
        	value = 0;
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
            value = UART_PARITY_NONE;
            break;

        case UART_PAR_EVEN:
            value = UART_EVEN_PARITY;
            break;

        case UART_PAR_ODD:
            value = UART_ODD_PARITY;
            break;

        case UART_PAR_ZERO:
            value = UART_PARITY_REPR_0;
            break;

        case UART_PAR_ONE:
            value = UART_PARITY_REPR_1;
            break;

        default:
            value = (uint32_t)UART_PAR_NONE;
            break;
    }

    return (value);
}

static bool UART_getWLenStbFlag(UART_LEN dataLength, UART_STOP stopBits, uint32_t *pValue);
static bool UART_getWLenStbFlag(UART_LEN dataLength, UART_STOP stopBits, uint32_t *pValue)
{
    uint32_t value;
    bool ret = (bool)true;

    // NOTE1: Word Length 5 && Stop Bits 2 is an invalid combination of parameters for the UART HW IP.
    //  This combination of parameters is treated as an error.
    //
    // NOTE2: Word Length 6,7,8 && Stop Bits 1.5 is an invalid combination of parameters for the UART HW IP.
    //  Stop Bit 1.5 configuration currently isn't supported by LLD HW IP driver.
    //  Once this is added, check for this invalid combination of parameters and treat as an error.
    //
    if ((dataLength == UART_LEN_5) &&
        (stopBits == UART_STOP_TWO))
    {
        value = UART_FRAME_WORD_LENGTH_5 | UART_FRAME_NUM_STB_1;
        *pValue = value;
        ret = (bool)false;
    }

    if (ret == (bool)true)
    {
        switch (dataLength)
        {
            case UART_LEN_5:
                value = UART_FRAME_WORD_LENGTH_5;
                break;

            case UART_LEN_6:
                value = UART_FRAME_WORD_LENGTH_6;
                break;

            case UART_LEN_7:
                value = UART_FRAME_WORD_LENGTH_7;
                break;

            case UART_LEN_8:
                value = UART_FRAME_WORD_LENGTH_8;
                break;

            default:
                value = UART_FRAME_WORD_LENGTH_5;
                break;
        }

        switch (stopBits)
        {
            case UART_STOP_ONE:
                value |= UART_FRAME_NUM_STB_1;
                break;

            case UART_STOP_TWO:
                value |= UART_FRAME_NUM_STB_1_5_2;
                break;

            default:
                value |= UART_FRAME_NUM_STB_1;
                break;
        }
        
        ret = (bool)true;
    }
    
    *pValue = value;
    return ret;
}


/*
 *  ======== UART_open_v1 ========
 */
static UART_Handle UART_open_v1(UART_Handle handle, const UART_Params *params)
{
    uintptr_t           key;
    UART_V1_Object     *object = (UART_V1_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    SemaphoreP_Params   semParams;
    uint32_t            divisorValue;
    uint32_t            txTrigLevel;
    uint32_t            rxTrigLevel;
    uint32_t            regVal = 0x00;
    uint32_t            parityType;
    uint32_t            wLenStbFlag;
    OsalRegisterIntrParams_t interruptRegParams;
    UART_Handle         retHandle = handle;
    char                semRdName[] = "read";
    char                semWrName[] = "write";

    /* If params are NULL use defaults. */
    if (params == NULL) {
        UART_Params_init(&object->params);
    }
    else {
        /* Save UART parameters. */
        object->params = *params;
    }

    /* Disable preemption while checking if the UART is open. */
    key = UART_osalHardwareIntDisable();

    /* Check if the UART is open already with the base addr. */
    if(object->isOpen == TRUE) {
        UART_osalHardwareIntRestore(key);
       UART_drv_log1("UART:(0x%x) already in use.", hwAttrs->baseAddr);

       retHandle = NULL;
    }

    /* UART is open by setting base addr */
    else
    {
        object->isOpen = TRUE;
        UART_osalHardwareIntRestore(key);

        /* Set UART variables to defaults. */
        object->writeBuf = NULL;
        object->readBuf = NULL;
        object->writeCount = 0;
        object->readCount = 0;
        object->writeSize = 0;
        object->readSize = 0;
        object->writeCR = FALSE;
        object->readTrans = NULL;
        object->writeTrans = NULL;
            /* Disable UART interrupts. */
        UARTIntDisable(hwAttrs->baseAddr,
                       UART_INT_RHR_CTI | UART_INT_THR | UART_INT_LINE_STAT);
        UARTInt2Disable(hwAttrs->baseAddr, UART_INT2_TX_EMPTY | UART_INT2_RX_EMPTY);

        if(hwAttrs->enableInterrupt == TRUE)
        {
            if (hwAttrs->configSocIntrPath != NULL)
            {
                /* setup the interrupt router path via DMSC */
                (void)hwAttrs->configSocIntrPath((const void *)hwAttrs, TRUE);
            }

            /* Construct Hwi object for this UART peripheral. */
            /* Initialize with defaults */
            Osal_RegisterInterrupt_initParams(&interruptRegParams);

             /* Populate the interrupt parameters */
            interruptRegParams.corepacConfig.arg=(uintptr_t)handle;
            interruptRegParams.corepacConfig.name=NULL;
            interruptRegParams.corepacConfig.isrRoutine=UART_v1_hwiIntFxn;
#ifdef __TI_ARM_V7R4__
            interruptRegParams.corepacConfig.priority=0x8U;
#else
#ifdef __C7100__
            interruptRegParams.corepacConfig.priority=0x01U;
#else
            interruptRegParams.corepacConfig.priority=0x20U;
#endif
#endif
            interruptRegParams.corepacConfig.corepacEventNum = (int32_t)(hwAttrs->eventId); /* Event going to INTC */
            interruptRegParams.corepacConfig.intVecNum = (int32_t)(hwAttrs->intNum); /* Host Interrupt vector */

             /* Register interrupts */
            (void)UART_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));

            if(object->hwi == NULL)
            {
                retHandle = NULL;
            }
            else
            {
                UART_osalSemParamsInit(&semParams);
                semParams.mode = SemaphoreP_Mode_BINARY;
                /* If write mode is blocking construct a lock and set callback to NULL. */
                if (object->params.writeMode == UART_MODE_BLOCKING) {
                    semParams.name = semWrName;
                    object->writeSem = UART_osalCreateBlockingLock(0, &semParams);
                    object->params.writeCallback = NULL;
                    object->params.writeCallback2 = NULL;
                }

                /* If read mode is blocking create a lock and set callback to NULL. */
                if (object->params.readMode == UART_MODE_BLOCKING) {
                    semParams.name = semRdName;
                    object->readSem = UART_osalCreateBlockingLock(0, &semParams);
                    object->params.readCallback = NULL;
                    object->params.readCallback2 = NULL;
                }
            }
        }

        if (retHandle != NULL)
        {
            /* Set up the TX and RX FIFO Trigger levels. */
            txTrigLevel = UART_getTxTrigLvl(hwAttrs->txTrigLvl);
            rxTrigLevel = UART_getRxTrigLvl(hwAttrs->rxTrigLvl);
#ifdef UART_DMA_ENABLE
            if (hwAttrs->dmaMode == TRUE)
            {
                regVal = UART_FIFO_CONFIG(UART_TRIG_LVL_GRANULARITY_4,
                                          UART_TRIG_LVL_GRANULARITY_4,
                                          txTrigLevel,
                                          rxTrigLevel,
                                          1U,
                                          1U,
                                          UART_DMA_EN_PATH_FCR,
                                          UART_DMA_MODE_1_ENABLE);
                /* Configuring the FIFO settings. */
                (void)UARTFIFOConfig(hwAttrs->baseAddr, regVal);

                (void)UART_configDMA(handle);
            }
            else
#endif
            {
                regVal = UART_FIFO_CONFIG(UART_TRIG_LVL_GRANULARITY_4,
                                          UART_TRIG_LVL_GRANULARITY_4,
                                          txTrigLevel,
                                          rxTrigLevel,
                                          1U,
                                          1U,
                                          UART_DMA_EN_PATH_FCR,
                                          UART_DMA_MODE_0_ENABLE);
                /* Configuring the FIFO settings. */
                (void)UARTFIFOConfig(hwAttrs->baseAddr, regVal);
            }
            /* Computing the Divisor Value for params.baudRate */
            divisorValue = UARTDivisorValCompute(hwAttrs->frequency,
                                                 object->params.baudRate,
                                                 hwAttrs->operMode,
                                                 UART_MIR_OVERSAMPLING_RATE_42);
            /* Configuring the Baud Rate settings. */
            (void)UARTDivisorLatchWrite(hwAttrs->baseAddr, divisorValue);

            /* Configuring UART line characteristics */
            parityType = UART_getParityType(object->params.parityType);
            UART_getWLenStbFlag(object->params.dataLength, object->params.stopBits, &wLenStbFlag);
            UARTLineCharacConfig(hwAttrs->baseAddr,
                                 wLenStbFlag,
                                 parityType);

            /* Disable write access to Divisor Latches. */
            UARTDivisorLatchDisable(hwAttrs->baseAddr);

            /* Disable Break Control. */
            UARTBreakCtl(hwAttrs->baseAddr, UART_BREAK_COND_DISABLE);
            if (hwAttrs->loopback == TRUE)
            {
                UARTLoopbackModeControl(hwAttrs->baseAddr, UART_LOOPBACK_MODE_ENABLE);
            }
            else
            {
                UARTLoopbackModeControl(hwAttrs->baseAddr, UART_LOOPBACK_MODE_DISABLE);
            }

            /* Enable UART */
            (void)UARTOperatingModeSelect(hwAttrs->baseAddr, hwAttrs->operMode);

            UART_drv_log3("UART:(0x%x) CPU freq: %d; UART baudrate to %d",
                hwAttrs->baseAddr, hwAttrs->frequency, object->params.baudRate);

            UART_drv_log1("UART:(0x%x) opened", hwAttrs->baseAddr);
        }
    }
    /* Return the handle of the UART_Object. */
    return (retHandle);
}


/*
 *  ======== UART_close_v1 ========
 */
static void UART_close_v1(UART_Handle handle)
{
    UART_V1_Object     *object = (UART_V1_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

    UARTFifoWait(hwAttrs->baseAddr);

    /* Disable UART and interrupts. */
    UARTIntDisable(hwAttrs->baseAddr,
                   UART_INT_RHR_CTI | UART_INT_THR | UART_INT_LINE_STAT);
    UARTInt2Disable(hwAttrs->baseAddr, UART_INT2_TX_EMPTY);
    (void)UARTOperatingModeSelect(hwAttrs->baseAddr, UART_DISABLED_MODE);

#ifdef UART_DMA_ENABLE
    if (hwAttrs->dmaMode == TRUE)
    {
        UART_freeDmaChannel(handle);
    }
#endif

    if(hwAttrs->enableInterrupt == TRUE)
    {
        if (hwAttrs->configSocIntrPath != NULL)
        {
            (void)hwAttrs->configSocIntrPath((const void *)hwAttrs, FALSE);
        }

        /* Delete the the SYS/BIOS objects. */
        (void)UART_osalHardwareIntDestruct(object->hwi, (int32_t)(hwAttrs->eventId));

        if (object->params.writeMode == UART_MODE_BLOCKING)
        {
            (void)UART_osalDeleteBlockingLock(object->writeSem);
        }
        if (object->params.readMode == UART_MODE_BLOCKING)
        {
            (void)UART_osalDeleteBlockingLock(object->readSem);
        }
    }

    object->isOpen = FALSE;

    UART_drv_log1("UART:(0x%x) closed", hwAttrs->baseAddr);

}


static int32_t UART_write_v1(UART_Handle handle, const void *buffer, size_t size)
{
    uintptr_t           key;
    UART_V1_Object     *object = (UART_V1_Object*)handle->object;
    int32_t             ret_val = 0;
    UART_Transaction   *pTrans;
    UART_HwAttrs const *hwAttrs;

    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;


    if (hwAttrs->enableInterrupt == TRUE)
    {
        /* Disable preemption while checking if the uart is in use. */
        key = UART_osalHardwareIntDisable();

        if (object->writeSize > 0U)
        {
            UART_osalHardwareIntRestore(key);
            ret_val = UART_ERROR;
        }
        /* Save the data to be written and restore interrupts. */
        else
        {
            UART_osalHardwareIntRestore(key);

            pTrans = &(object->wrTrans);
            pTrans->buf = (void *)buffer;
            pTrans->timeout = object->params.writeTimeout;
            pTrans->count = (uint32_t)size;
            (void)UART_write2_v1(handle, pTrans);

            ret_val = (int32_t)(pTrans->count);
        }
    }
    else
    {
        /* Use polling if interrupt is disabled */
       ret_val = UART_writePolling_v1(handle,buffer,size);
    }
    return(ret_val);
}

static int32_t UART_write2_v1(UART_Handle handle, UART_Transaction * transaction)
{
    uintptr_t           key;
    UART_V1_Object     *object;
    UART_HwAttrs const *hwAttrs;
    int32_t             ret_val = UART_SUCCESS;
    SemaphoreP_Status   semStatus;

    /* Input parameter validation */
    if ((handle == NULL)           ||
        (transaction == NULL)      ||
        (transaction->count == 0U))
    {
        ret_val = UART_ERROR;
    }
    else
    {
        /* Get the pointer to the hwAttrs */
        hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

        /* Get the pointer to the object */
        object = (UART_V1_Object*)handle->object;

        if(hwAttrs->enableInterrupt == TRUE)
        {
            /* Disable preemption while checking if the uart is in use. */

             key = UART_osalHardwareIntDisable();

             if (object->writeSize > 0U)
             {
                 UART_osalHardwareIntRestore(key);

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
                  * transaction parameter passed to UART_write2_v1 is
                  * declared in the stack, and cannot be used in the ISR,
                  * otherwise will cause data corruption in the stack.
                  * The driver should only use object->writeTrans when it
                  * is NOT called from egacy UART_write API in callback mode
                  */
                 object->writeTrans = transaction;
                 object->writeBuf = transaction->buf;
                 object->writeCount = 0;
                 object->txDataSent = FALSE;

#ifdef UART_DMA_ENABLE
                 if (hwAttrs->dmaMode == TRUE)
                 {
                     /* DMA mode */
                     object->writeSize = transaction->count;
                     UART_osalHardwareIntRestore(key);

                     UART_transmitDMA(handle,(const void*)object->writeBuf, object->writeSize);

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

                     /* Disable TX interrupts */
                     UARTIntDisable(hwAttrs->baseAddr, UART_INT_THR);
                     UARTInt2Disable(hwAttrs->baseAddr, UART_INT2_TX_EMPTY);

                     object->writeSize = (size_t)UART_writeData_v1(handle, (int32_t)(transaction->count));
                     if ((object->writeSize) == (size_t)0)
                     {
                         /* Write is finished. */
                         UART_drv_log2("UART(0x%x): Write finished, %d bytes written",
                                       hwAttrs->baseAddr, object->writeCount);

                         /* Reset the write buffer so we can pass it back */
                         object->writeBuf = (const uint8_t *)object->writeBuf - object->writeCount;
                         if (object->writeTrans != NULL)
                         {
                             object->writeTrans->count = (uint32_t)(object->writeCount);
                             object->writeTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                         }
                         object->txDataSent = TRUE;
                         UARTInt2Enable(hwAttrs->baseAddr, UART_INT2_TX_EMPTY);
                     }
                     /* If writeMode is blocking, block and get the status. */
                     else
                     {
                         UARTIntEnable(hwAttrs->baseAddr, UART_INT_THR);
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
            transaction->count = (uint32_t)UART_writePolling_v1(handle,transaction->buf,transaction->count);
            transaction->status = UART_TRANSFER_STATUS_SUCCESS;
        }
    }
    return(ret_val);
}

/*
 *  ======== UART_charPut_v1 ========
 *
 *  This function continuously does a non-blocking write, until it writes
 *  successfully or times out.
 */
static uint32_t UART_charPut_v1(UART_HwAttrs const *hwAttrs, uint8_t data, uint32_t *timeout);  /*for misra warnings*/
static uint32_t UART_charPut_v1(UART_HwAttrs const *hwAttrs, uint8_t data, uint32_t *timeout)
{
    uint32_t status;
    uint32_t timeoutCnt = *timeout;
    uint32_t retVal = TRUE;

    while (retVal == TRUE)
    {
        status = UARTCharPutNonBlocking(hwAttrs->baseAddr, data);
        if (status == FALSE)
        {
            if (timeoutCnt == 0U)
            {
                retVal = FALSE;
            }
            else
            {
                (void)UART_osalDelay(1U);
                timeoutCnt--;
            }
        }
        else
        {
            break;
        }
    }

    *timeout =  timeoutCnt;

    return (retVal);
}

/*
 *  ======== UART_writePolling_v1 ========
 */
static int32_t UART_writePolling_v1(UART_Handle handle, const void *buf,
                                     size_t size)
{
    int32_t             count = 0;
    const uint8_t      *buffer = (const uint8_t *)buf;
    uint32_t            timeout;
    uint32_t            timeoutErr = FALSE;
    size_t              wrSize = size;

    /* Get the pointer to the object and hwAttrs */
    UART_V1_Object     *object = (UART_V1_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

    timeout = object->params.writeTimeout;

    /* Write characters. */
    while ((wrSize != (size_t)0) && (timeoutErr == FALSE))
    {
        if ((object->params.writeDataMode == UART_DATA_TEXT) && (*buffer == ((uint8_t)('\n'))))
        {
            if (UART_charPut_v1(hwAttrs, ((uint8_t)('\r')), &timeout) == FALSE)
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
            if (UART_charPut_v1(hwAttrs, *buffer, &timeout) == FALSE)
            {
                timeoutErr = TRUE;
            }
            else
            {
                UART_drv_log2("UART:(0x%x) Wrote character 0x%x",
                    hwAttrs->baseAddr, *buffer);

                buffer++;
                count++;
                wrSize--;
            }
        }
    }

    if (timeoutErr == TRUE)
    {
        UART_drv_log2("UART:(0x%x) Write polling timed out, %d bytes written",
                      hwAttrs->baseAddr, (int32_t)count);
    }
    else
    {
        UART_drv_log2("UART:(0x%x) Write polling finished, %d bytes written",
                      hwAttrs->baseAddr, (int32_t)count);
    }

    return (count);
}

/*
 *  ======== UART_writeCancel_v1 ========
 */
static void UART_writeCancel_v1(UART_Handle handle)
{
    UART_V1_Object     *object;
    UART_HwAttrs const *hwAttrs;

    object = (UART_V1_Object*)handle->object;
    
    if (UART_writeCancelNoCB(handle) == (bool)true)
    {
        hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

        /* enable the TX FIFO interrupt and callback to application in ISR */
        object->txDataSent = TRUE;
        UARTInt2Enable(hwAttrs->baseAddr, UART_INT2_TX_EMPTY);

        UART_drv_log2("UART:(%p) Write cancelled, %d bytes written",
                      ((UART_HwAttrs const *)(handle->hwAttrs))->baseAddr,
                      object->writeCount);
    }
}

/*
 *  ======== UART_read_v1 ========
 */
static int32_t UART_read_v1(UART_Handle handle, void *buffer, size_t size)
{
    uintptr_t           key;
    UART_V1_Object     *object;
    int32_t             ret_val = 0;
    UART_Transaction   *pTrans;
    UART_HwAttrs const *hwAttrs;

    /* Get the pointer to the object */
    object = (UART_V1_Object*)handle->object;
    /* Get the pointer to the hwAttrs */
    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

   if (hwAttrs->enableInterrupt == TRUE)
   {
       /* Disable preemption while checking if the uart is in use. */
       key = UART_osalHardwareIntDisable();
       if (object->readSize > 0U)
       {
           UART_osalHardwareIntRestore(key);
           ret_val = UART_ERROR;
       }
       else
       {
           UART_osalHardwareIntRestore(key);
           pTrans = &(object->rdTrans);
           pTrans->buf = (void *)buffer;
           pTrans->timeout = object->params.readTimeout;
           pTrans->count = (uint32_t)size;
           (void)UART_read2_v1(handle, pTrans);
           ret_val = (int32_t)(pTrans->count);
       }
   }
   else
   {
       ret_val = UART_readPolling_v1(handle,buffer,size);
   }

   return(ret_val);
}

/*
 *  ======== UART_read2_v1 ========
 */
static int32_t UART_read2_v1(UART_Handle handle, UART_Transaction *transaction)
{
    uintptr_t              key;
    UART_V1_Object        *object;
    UART_HwAttrs const    *hwAttrs;
    int32_t                ret_val = UART_SUCCESS;
    SemaphoreP_Status      semStatus;

    /* Input parameter validation */
    if (handle == NULL)
    {
        ret_val = UART_ERROR;
    }

    if (transaction == NULL)
    {
        ret_val = UART_ERROR;
    }
    else
    {
        if (transaction->count == 0U)
        {
            ret_val = UART_ERROR;
        }
    }

    if (ret_val == UART_SUCCESS)
    {
    /* Get the pointer to the hwAttrs */
    hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;

    /* Get the pointer to the object */
    object = (UART_V1_Object*)handle->object;


    if(hwAttrs->enableInterrupt == TRUE) {
    /* Disable preemption while checking if the uart is in use. */
    key = UART_osalHardwareIntDisable();
    if (object->readSize > 0U) {
        UART_osalHardwareIntRestore(key);

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
         * transaction parameter passed to UART_read2_v1 is
         * declared in the stack, and cannot be used in the ISR,
         * otherwise will cause data corruption in the stack.
         * The driver should only use object->readTrans when it
         * is NOT called from egacy UART_read API in callback mode
         */
        object->readTrans = transaction;
        object->readBuf = transaction->buf;
        object->readCount = 0;
        object->rxTimeoutCnt = 0;

#ifdef UART_DMA_ENABLE
        if (hwAttrs->dmaMode == TRUE)
        {
            /* DMA mode */
            object->readSize = transaction->count;
            UART_osalHardwareIntRestore(key);

            UARTIntEnable(hwAttrs->baseAddr, UART_INT_LINE_STAT);
            if (object->readSize < (size_t)(hwAttrs->rxTrigLvl))
            {
                /*
                 * read size less than RX threshold, no DMA trigger event
                 * enable RHR interrupt to receive data in ISR
                 */
                UARTIntEnable(hwAttrs->baseAddr, UART_INT_RHR_CTI);
            }
            else
            {
                UART_receiveDMA(handle,(void*)object->readBuf, object->readSize);
            }

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
            UARTIntDisable(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_LINE_STAT);

            object->readSize = (size_t)UART_v1_readData(handle, (int32_t)(transaction->count));
            if ((object->readSize) == (size_t)0)
            {

                UART_drv_log2("UART:(0x%x) Read finished, %d bytes read",
                              hwAttrs->baseAddr, object->readCount);

                /* Update the actual read count */
                transaction->count = (uint32_t)(object->readCount);

            	if (object->params.readMode == UART_MODE_CALLBACK)
                {
                    UART_v1_callback(handle, (bool)true);
                }
                ret_val = UART_SUCCESS;
            }
            else
            {
                UARTIntEnable(hwAttrs->baseAddr, UART_INT_RHR_CTI | UART_INT_LINE_STAT);
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
                    	/* Cancel the DMA without posting the semaphore */
                        UART_readCancelNoCB(handle);
                        ret_val = UART_ERROR;
                    }
                    transaction->count = (uint32_t)(object->readCount);
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
       transaction->count = (uint32_t)UART_readPolling_v1(handle,transaction->buf,transaction->count);
       transaction->status = UART_TRANSFER_STATUS_SUCCESS;
    }
    }
    return(ret_val);
}

/*
 *  ======== UART_charGet_v1 ========
 *
 *  This function continuously does a non-blocking read, until it reads
 *  successfully or times out.
 */
static uint32_t UART_charGet_v1(UART_HwAttrs const *hwAttrs, uint8_t *data, uint32_t *timeout);  /*for misra warnings*/
static uint32_t UART_charGet_v1(UART_HwAttrs const *hwAttrs, uint8_t *data, uint32_t *timeout)
{
    uint8_t  rdData;
    uint32_t timeoutCnt = *timeout;
    uint32_t retVal = TRUE;
    uint32_t rdSuccess;

    while (retVal == TRUE)
    {
        rdSuccess = UARTCharGetNonBlocking2(hwAttrs->baseAddr, &rdData);
        if (rdSuccess == FALSE)
        {
            if (timeoutCnt == 0U)
            {
                retVal = FALSE;
            }
            else
            {
                (void)UART_osalDelay(1U);
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
 *  ======== UART_readPolling_v1 ========
 */
static int32_t UART_readPolling_v1(UART_Handle handle, void *buf, size_t size)
{
    int32_t                count = 0;
    UART_V1_Object     *object = (UART_V1_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    uint8_t               *buffer = (uint8_t *)buf;
    uint32_t               timeout;
    uint8_t                ret_flag = 0U;
    uint32_t               timeoutErr = FALSE;
    size_t                 rdSize = size;

    timeout = object->params.readTimeout;

    /* Read characters. */
    while ((rdSize != (size_t)0) && (timeoutErr == FALSE))
    {
        if (UART_charGet_v1(hwAttrs, buffer, &timeout) == FALSE)
        {
            timeoutErr = TRUE;
        }
        else
        {
            UART_drv_log2("UART:(0x%x) Read character 0x%x",
                hwAttrs->baseAddr, *buffer);

            count++;
            rdSize--;

            if ((object->params.readDataMode == UART_DATA_TEXT) && (*buffer == ((uint8_t)('\r'))))
            {
                /* Echo character if enabled. */
                if (object->params.readEcho == UART_ECHO_ON)
                {
                    if (UART_charPut_v1(hwAttrs, ((uint8_t)('\r')), &timeout) == FALSE)
                    {
                        timeoutErr = TRUE;
                    }
                }
                if (timeoutErr == FALSE)
                {
                    *buffer = ((uint8_t)('\n'));
                }
            }

            /* Echo character if enabled. */
            if ((timeoutErr == FALSE) && (object->params.readEcho == UART_ECHO_ON))
            {
                if (UART_charPut_v1(hwAttrs, *buffer, &timeout) == FALSE)
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
        UART_drv_log2("UART:(0x%x) Read polling timed out, %d bytes read",
                      hwAttrs->baseAddr, (int32_t)count);
    }

    if(ret_flag == 0U)
    {
        UART_drv_log2("UART:(0x%x) Read polling finished, %d bytes read",
        hwAttrs->baseAddr, (int32_t)count);
    }

    return (count);
}

/*
 *  ======== UART_readCancel_v1 ========
 */
static void UART_readCancel_v1(UART_Handle handle)
{
    if (UART_readCancelNoCB(handle) == (bool)true)
    {
        UART_v1_callback(handle, (bool)true);

        UART_drv_log2("UART:(0x%x) Read cancelled, %d bytes read",
                      ((UART_HwAttrs const *)(handle->hwAttrs))->baseAddr,
                      object->readCount);
    }
}

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              UART_control().
 */
static int32_t UART_control_v1 (UART_Handle handle, uint32_t cmd, void *arg)
{
    /* Workaround to resolve the Misra-C 2012 Rule 2.7 issue */
    (void)handle;
    (void)cmd;
    arg = arg;

    return(0);
}

/**
 * \brief   This API waits indefinitely until the Transmitter FIFO
 *          (THR register in non-FIFO mode) and Transmitter Shift
 *          Register are empty.
 *
 * \param   baseAdd     Memory address of the UART instance being used
 *
 * \return  None
 */
static void UARTFifoWait(uint32_t baseAdd)
{
    uint32_t flag;

    do
    {
        flag = UARTIsTransmitterEmpty(baseAdd);
    }
    while (flag == FALSE);
}

static bool UART_writeCancelNoCB(UART_Handle handle)
{
    uintptr_t           key;
    UART_V1_Object     *object = (UART_V1_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    bool                retVal = (bool)true;

    UARTIntDisable(hwAttrs->baseAddr, UART_INT_THR);
    UARTInt2Disable(hwAttrs->baseAddr, UART_INT2_TX_EMPTY);

    /* Disable interrupts to avoid writing data while changing state. */
    key = UART_osalHardwareIntDisable();

    /* Return if there is no write. */
    if ((object->writeSize) == 0U)
    {
        UART_osalHardwareIntRestore(key);
        retVal = (bool)false;
    }
    else
    {
#ifdef UART_DMA_ENABLE
        if (hwAttrs->dmaMode == TRUE)
        {
            /* Disable DMA TX channel */
            UART_disableDmaChannel(handle, (bool)true);

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
            object->writeBuf = (const uint8_t *)object->writeBuf - object->writeCount;
            if (object->writeTrans != NULL)
            {
                object->writeTrans->count = (uint32_t)(object->writeCount);
            }
        }

        /* Set size = 0 to prevent writing and restore interrupts. */
        object->writeSize = 0;
        UART_osalHardwareIntRestore(key);
    }

    return (retVal);
}

static bool UART_readCancelNoCB(UART_Handle handle)
{
    uintptr_t           key;
    UART_V1_Object     *object = (UART_V1_Object*)handle->object;
    UART_HwAttrs const *hwAttrs = (UART_HwAttrs const *)handle->hwAttrs;
    bool                retVal = (bool)true;
    uint8_t             rdData;
    uint32_t            flag;

    UARTIntDisable(hwAttrs->baseAddr,
                   UART_INT_RHR_CTI | UART_INT_LINE_STAT);

    /* Disable interrupts to avoid reading data while changing state. */
    key = UART_osalHardwareIntDisable();
    if ((object->readSize) == 0U)
    {
        UART_osalHardwareIntRestore(key);
        retVal = (bool)false;
    }
    else
    {
#ifdef UART_DMA_ENABLE
        if (hwAttrs->dmaMode == TRUE)
        {
            /* Disable DMA RX channel */
            UART_disableDmaChannel(handle, (bool)false);

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
                object->readTrans->count = (uint32_t)(object->readCount);
            }
        }

        /* Set size = 0 to prevent reading and restore interrupts. */
        object->readSize = 0;
        UART_osalHardwareIntRestore(key);

        /* Flush the RX FIFO */
        do
        {
            flag = UARTCharGetNonBlocking2(hwAttrs->baseAddr, &rdData);
        }
        while (flag != FALSE);
    }

    return (retVal);
}


