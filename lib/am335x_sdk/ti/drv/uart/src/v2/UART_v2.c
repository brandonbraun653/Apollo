/**
 *  \file   UART_v2.c
 *
 *  \brief  PRU UART FW specific UART Driver APIs implementation.
 *
 *   This file contains the driver APIs for UART FW controller.
 */

/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/v2/UART_v2.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/uart/soc/tiuart_pruss_intc_mapping.h>

// Tx/Rx interrupt types
#define TX_BUFF_EMPTY_INT   ( 1 )       // Tx buffer empty interrupt
#define RX_CHAR_INT         ( 2 )       // Rx char interrupt

#define PRUICSS_PINMUX_DEF  ( 0x0 )     // default ICSS pinmux setting
    
static uint32_t gUartCurrentICSSModePruLockInit = FALSE; // whether ICSS PRU locks have been created
// UART ICSS Config Mode instance
static UART_ICSS_funct_mode gUartCurrentICSSMode[UART_MAX_ICSS_INSTANCE] = 
{
    {
        {
            {0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}},
            {0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}}
        }
    },
    {
        {
            {0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}},
            {0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}}
        }
    },
    {
        {
            {0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}},
            {0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}}
        }
    }
};

/* UART V2 functions */
// close UART instance
static void         UART_close_v2(UART_Handle handle);

// control UART instance
static int32_t      UART_control_v2(UART_Handle handle, uint32_t cmd, void *arg);

// initialize UART instance
static void         UART_init_v2(UART_Handle handle);
// open UART instance
static UART_Handle  UART_open_v2(UART_Handle handle, const UART_Params *params);

// read size chars from UART instance to buffer
static int32_t      UART_read_v2(UART_Handle handle, void *buffer, size_t size);
// read size chars from UART instance to buffer, POLLING mode
static int32_t      UART_readPolling_v2(UART_Handle handle, void *buf, size_t size);
// cancel current read from UART instance
static void         UART_readCancel_v2(UART_Handle handle);

// write size chars in buffer to UART instance
static int32_t      UART_write_v2(UART_Handle handle, const void *buffer, size_t size);
// write size chars in buffer to UART instance, POLLING mode
// attempt to write characters until all characters written, or time out occurs
static int32_t      UART_writePolling_v2(UART_Handle handle, const void *buf, size_t size);
// cancel current write to UART instance
static void         UART_writeCancel_v2(UART_Handle handle);

// perform read transaction from UART instance
static int32_t      UART_read2_v2(UART_Handle handle, UART_Transaction *transaction);
// perform write transaction to UART instance
static int32_t      UART_write2_v2(UART_Handle handle, UART_Transaction *transaction);


// Initialize ICSS & PRU:
//  set ICSS pinmux
//  disable PRU
//  init (clear) IMEM/DMEM
//  download code/data to IMEM/DMEM
static int32_t UART_v2_initIcssPru(UART_Handle handle, const UART_Params *params, bool enablePru);

// De-initialize PRU:
//  disable PRU
//  reset PRU
//  init IMEM/DMEM
static int32_t UART_v2_deinitIcssPru(UART_Handle handle);

// reset UART v2 object
static void UART_v2_resetObject(UART_V2_Object *object);

// configure PRU UART global configuration registers
static int32_t UART_v2_initFwGlobalCfg(UART_Handle handle, PRUSS_PruCores pruInstId);
// wait (poll) for FW init notification
static int32_t UART_v2_waitFwInitNotify(UART_Handle handle);

// enable PRU (start code execution)
static int32_t UART_v2_enablePru(UART_Handle handle);
// disable PRU (stop code execution)
static int32_t UART_v2_disablePru(UART_Handle handle);
// reset PRU
static int32_t UART_v2_resetPru(UART_Handle handle);

// disable PRU UART FW instance
static int32_t UART_v2_disableInst(UART_Handle handle);
// check PRU UART FW instance disabled
static int32_t UART_v2_checkInstDisabled(UART_Handle handle);
// enable PRU UART FW instance
static int32_t UART_v2_enableInst(UART_Handle handle);
// wait (poll) for PRU UART FW instance enable-ack
static int32_t UART_v2_waitInstEnableAck(UART_Handle handle);

// disable PRU UART FW instance Tx interrupt
static int32_t UART_v2_disableInstTxInt(UART_Handle handle, uint8_t intMask);
// enable PRU UART FW instance Tx interrupt
static int32_t UART_v2_enableInstTxInt(UART_Handle handle, uint8_t intMask);
// disable PRU UART FW instance Rx interrupt
static int32_t UART_v2_disableInstRxInt(UART_Handle handle, uint8_t intMask);
// enable PRU UART FW instance Rx interrupt
static int32_t UART_v2_enableInstRxInt(UART_Handle handle, uint8_t intMask);

// configure PRU UART FW instance pinmux
static int32_t UART_v2_configInstPinMux(UART_Handle handle, bool enableHwFcPins);

// configure PRU UART FW instance configuration FW register
static int32_t UART_v2_configInst(UART_Handle handle);
// configure PRU UART FW instance Tx/Rx pins FW registers
static int32_t UART_v2_configInstPins(UART_Handle handle);
// configure PRU UART FW instance Tx/Rx system events FW registers
static int32_t UART_v2_configInstSysEvts(UART_Handle handle);
// clear PRU UART FW instance Tx buffer
static int32_t UART_v2_clearInstTxBuffer(UART_Handle handle);
// clear PRU UART FW instance Rx buffer
static int32_t UART_v2_clearInstRxBuffer(UART_Handle handle);

// change the pinmux of GPIO pins of pru based on FW
static void UART_v2_pruGPIOMuxConfig(UART_PRU_IOPinMuxAttrs *handle, uint32_t pinMode);
// configure Baud Rate FW register
static int32_t UART_v2_configInstBaudRate(UART_Handle handle);
// Translate UART API Baud Rate parameter to Baud Rate FW register setting
static uint8_t xlateUartBaudRateToFwBaudRate(uint32_t baudRate);
// Configure Number of Bits Per Character FW register
static int32_t UART_v2_configInstNumBitsPerChar(UART_Handle handle);
// Translate UART API Data Length parameter to Number of Bits per Character FW register setting
static uint8_t xlateUartDatalenToFwNumBitsPerChar(UART_LEN dataLength);
// Configure Stop Bit Size FW register
static int32_t UART_v2_configInstStopBitSize(UART_Handle handle);
// Translate UART API Stop Bits to Number of Bits per Character FW register setting
static uint8_t xlateUartStopBitsToFwStopBitSize(UART_STOP stopBits);
// Configure Parity Enable / Type FW registers
static int32_t UART_v2_configInstParity(UART_Handle handle);
// Configure HW Flow Control FW registers
static int32_t UART_v2_configInstHwFlowControl(UART_Handle handle);

// Cancel write for UART instance, no callback
static bool UART_v2_cancelInstWriteNoCallback(UART_Handle handle);
// Cancel read from UART instance, no callback
static bool UART_v2_cancelInstReadNoCallback(UART_Handle handle);

// Continuously perform non-blocking write to Tx Buffer, until write successful or time out
static uint32_t UART_v2_putInstCharTxBuffTimeout(UART_SWIPAttrs const *swipAttrs, uint16_t charWrite, uint32_t *timeout);
// Continuously perform non-blocking read from Rx Buffer, until read successful or time out
static uint32_t UART_v2_getInstCharRxBuffTimeout(UART_SWIPAttrs const *swipAttrs, uint16_t *pCharRead, uint32_t *timeout);

// Write character into Tx Buffer
static void UART_v2_putInstCharTxBuff(UART_SWIPAttrs const *swipAttrs, uint16_t charWrite);
// Perform non-blocking write of 16-bit character into Tx Buffer
static uint32_t UART_v2_putInstCharTxBuffNonBlock(UART_SWIPAttrs const *swipAttrs, uint16_t charWrite);
// Perform blocking write of 16-bit character into Tx Buffer
static void UART_v2_putInstCharTxBuffBlock(UART_SWIPAttrs const *swipAttrs, uint16_t charWrite);
// Check Tx Buffer full status
static uint32_t UART_v2_getInstTxBuffFullStatus(uint32_t baseAddr);
// Check Tx Buffer empty status
static uint32_t UART_v2_getInstTxBuffEmptyStatus(uint32_t baseAddr);

// Perform non-blocking read of 16-bit character from Rx Buffer
static uint32_t UART_v2_getInstCharRxBuffNonBlock(UART_SWIPAttrs const *swipAttrs, uint16_t *pCharRead);

// UART v2 callback function
void UART_v2_callback(UART_Handle handle, bool readTrans);
// UART V2 HWI function
static void UART_v2_hwiIntFxn(uintptr_t arg);

/* UART function table for PRU UART FW implementation */
const UART_FxnTable UART_v2_FxnTable = {
    &UART_close_v2,
    &UART_control_v2,
    &UART_init_v2,
    &UART_open_v2,
    &UART_read_v2,
    &UART_readPolling_v2,
    &UART_readCancel_v2,
    &UART_write_v2,
    &UART_writePolling_v2,
    &UART_writeCancel_v2,
    &UART_read2_v2,
    &UART_write2_v2,
};

/*
 *  ======== UART_writeData_v2 ========
 *  Write and process data to the UART.
 */
// Parameters:
//  handle  : Input, UART instance handle
//  size    : Input, number of characters to write
//
//  return  : number of characters yet to be written
static inline int32_t UART_writeData_v2(UART_Handle handle, int32_t size); /* for misra warnings*/
static inline int32_t UART_writeData_v2(UART_Handle handle, int32_t size)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t txBuffFull;    // flag indicates whether Tx Buffer is full
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    txBuffFull = FALSE;
    while ((size != 0) && (txBuffFull == FALSE))
    {
        if (object->params.writeDataMode == UART_DATA_TEXT)
        {
            // Data mode is text for write
            
            if (object->writeCR)
            {
                // output carriage return
                
                txBuffFull = UART_v2_getInstTxBuffFullStatus(swipAttrs->baseAddr);
                if (txBuffFull == FALSE)
                {
                    // write character to Tx Buffer
                    UART_v2_putInstCharTxBuff(swipAttrs, ((uint16_t)('\r')));
                    
                    size--;                 // decrement remaining number of chars to write
                    object->writeCount++;   // increment object number of chars written
                    object->writeCR = 0;    // reset carriage return flag
                }
            }
            else
            {
                // Output line feed after carriage return.
                if (*(uint16_t *)object->writeBuf == ((uint16_t)('\n')))
                {
                    size++;                 // increment remaining number of chars to write since extra char output
                    object->writeCR = 1;    // set carriage return flag
                }

                txBuffFull = UART_v2_getInstTxBuffFullStatus(swipAttrs->baseAddr);
                if (txBuffFull == TRUE)
                {
                    if (object->writeCR)
                    {
                        size--;                 // decrement remaining number of chars to write
                        object->writeCR = 0;    // reset carriage return flag
                    }
                }
                else
                {
                    // write character to Tx Buffer
                    UART_v2_putInstCharTxBuff(swipAttrs, *(uint16_t *)object->writeBuf);
                    
                    // increment pointer to write buffer, 
                    // this will be rewound before return to write caller
                    object->writeBuf = (uint16_t *)object->writeBuf + 1;
                    
                    size--;                 // decrement remaining number of chars to write
                    object->writeCount++;   // increment object number of chars written
                }
            }
        }
        else
        {
            // Data mode is binary for write
            
            // check if Tx Buffer is full
            txBuffFull = UART_v2_getInstTxBuffFullStatus(swipAttrs->baseAddr);
            if (txBuffFull == FALSE)
            {
                // write character to Tx Buffer
                UART_v2_putInstCharTxBuff(swipAttrs, *(uint16_t *)object->writeBuf);
                
                // increment pointer to write buffer, 
                // this will be rewound before return to write caller
                object->writeBuf = (uint16_t *)object->writeBuf + 1;
                
                size--;                 // decrement remaining number of chars to write
                object->writeCount++;   // increment object number of chars written
            }
        }
    }
    
    return size;    // return remaining number of chars to write
}

/*
 *  ======== UART_readData_v2 ========
 *  Read and process data from the UART.
 */
// Parameters:
//  handle  : Input, UART instance handle
//  size    : Input, number of characters to read
//
//  return  : number of characters yet to be read
static inline int32_t UART_readData_v2(UART_Handle handle, int32_t size);
static inline int32_t UART_readData_v2(UART_Handle handle, int32_t size)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint16_t charRead = (uint16_t)0xFFFF;
    uint32_t status;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Read character
    status = UART_v2_getInstCharRxBuffNonBlock(swipAttrs, &charRead);
    if (status == TRUE)
    {
        // update object Line Status error
        object->lineStatusErr = charRead & RX_CHAR_ERR_MASK;
    }
    
    while ((size != 0) && (status == TRUE))
    {
        // Process Read Data Mode when set to Text.
        // Replace carriage return w/ line feed.
        if (object->params.readDataMode == UART_DATA_TEXT)
        {
            if (charRead == ((uint16_t)('\r')))
            {
                // If Echo Mode enabled, echo read character
                if (object->params.readEcho)
                {
                    // echo carriage return
                    UART_v2_putInstCharTxBuffBlock(swipAttrs, ((uint16_t)('\r')));
                }
                charRead = (uint16_t)'\n';
            }
        }
        
        *(uint16_t *)object->readBuf = charRead;            // write char to object read buffer
        object->readBuf = (uint16_t *)object->readBuf + 1;  // increment read buffer pointer
        object->readCount++;                                // increment count of characters read
        size--;                                             // decrement count of characters yet to read
     
        // If Echo Mode enabled, echo read character
        if (object->params.readEcho)
        {
            // echo read character
            UART_v2_putInstCharTxBuffBlock(swipAttrs, charRead);
        }
     
        // If read return mode is newline, stop reading if newline received
        if ((object->params.readReturnMode == UART_RETURN_NEWLINE) &&
            (charRead == ((uint16_t)('\n'))))
        {
            size = 0;
            break;
        }
        
        if (size != 0)
        {
            // read char
            status = UART_v2_getInstCharRxBuffNonBlock(swipAttrs, &charRead);
            
            if (status == TRUE)
            {
                // update object Line Status error
                object->lineStatusErr = charRead & RX_CHAR_ERR_MASK;
            }
        }
    }
    
    return size;    // return number of chars yet to read
}

/*
 *  ======== UART_close_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_close().
 */
// close UART instance
static void UART_close_v2(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    OsalInterruptRetCode_e osalIntRetCode;
    SemaphoreP_Status semPStatus;
    UART_ICSS_INSTANCE icssInstId;
    PRUSS_PruCores pruInstId;
    uint32_t status;
    int32_t retVal;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Verify UART instance is open
    if (object->isOpen == FALSE)
    {
        return;
    }

    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    
    //
    // Check active write/read here?
    //
    
    // Wait (poll) for Tx Buffer to empty
    do {
        status = UART_v2_getInstTxBuffEmptyStatus(swipAttrs->baseAddr);
    } while (status == FALSE);
 
    // Disable Tx FIFO empty interrupt
    retVal = UART_v2_disableInstTxInt(handle, TX_BUFF_EMPTY_INT);
    if (retVal == UART_SUCCESS)
    {
        // Disable Rx Character interrupt
        retVal = UART_v2_disableInstRxInt(handle, RX_CHAR_INT);
    }
    
    if (retVal == UART_SUCCESS)
    {
        // Disable UART instance
        retVal = UART_v2_disableInst(handle);
    }
    
    if ((retVal == UART_SUCCESS) && (swipAttrs->enableIntr))
    {
        // delete HWI
        osalIntRetCode = UART_osalHardwareIntDestruct(object->hwi, 0);
        retVal = (osalIntRetCode == OSAL_INT_SUCCESS) ? UART_SUCCESS : UART_ERROR;
        
        if (retVal == UART_SUCCESS)
        {
            semPStatus = SemaphoreP_OK;
            
            if (object->params.writeMode == UART_MODE_BLOCKING)
            {
                // delete write lock
                semPStatus = UART_osalDeleteBlockingLock(object->writeSem);
            }
            
            if ((semPStatus == SemaphoreP_OK) && 
                (object->params.readMode == UART_MODE_BLOCKING))
            {
                // delete read lock
                semPStatus = UART_osalDeleteBlockingLock(object->readSem);                
            }
            
            retVal = (semPStatus == SemaphoreP_OK) ? UART_SUCCESS : UART_ERROR;
        }
    }
    
    if (retVal == UART_SUCCESS)
    {
        icssInstId = swipAttrs->icssInstId; // get ICSS instance ID
        pruInstId = swipAttrs->pruInstId;   // get PRU instance ID

        // Update ICSS PRU global configuration table 
        UART_osalPendLock(gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruInstLock, SemaphoreP_WAIT_FOREVER);
        gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].handlePtr[((UART_SWIPAttrs const *)handle->hwAttrs)->uartInstId] = (uintptr_t)NULL;
        gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].instanceCnt--;
        if (gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].instanceCnt == 0)
        {
            gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruGCfgAddr = (uint32_t)0;
            gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruInstId = PRUICSS_MAX_PRU;
            if (gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruIcssHandle != NULL)
            {
                // De-initialize (free) PRU
                retVal = UART_v2_deinitIcssPru(handle);
            }
        }
        UART_osalPostLock(gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruInstLock);        
    }
    
    if (retVal == UART_SUCCESS)
    {
        object->isOpen = FALSE;
    }
    
    return;
}

/*
 *  ======== UART_control_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_control().
 */
static int32_t UART_control_v2(UART_Handle handle, uint32_t cmd, void *arg)
{
    return 0;
}

/*
 *  ======== UART_init_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_init().
 */
static void UART_init_v2(UART_Handle handle)
{
    uint32_t i = 0;
    uint32_t j = 0;
    SemaphoreP_Params semParams;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Mark the object as available */
        ((UART_V2_Object *)(handle->object))->isOpen = FALSE;
    }
    
    if (gUartCurrentICSSModePruLockInit == FALSE)
    {
        /*
         * Create semaphores to provide exclusive access to the ICSS PRU table for UART peripherals.
         */
        UART_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;

        for (i = 0 ; i < UART_MAX_ICSS_INSTANCE; i++)
        {
            for (j = 0 ; j < UART_PRU_INSTANCE_PER_ICSS; j++)
            {
                gUartCurrentICSSMode[i].pruMode[j].pruInstLock = UART_osalCreateBlockingLock(1U, &semParams);
            }
        }
        
        gUartCurrentICSSModePruLockInit = TRUE;
    }
    
    return;
}
    
/*
 *  ======== UART_open_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_open().
 */
static UART_Handle UART_open_v2(UART_Handle handle, const UART_Params *params)
{
    UART_V2_Object *object;
    UART_SWIPAttrs const *swipAttrs;
    uint32_t key;
    int32_t retVal = UART_SUCCESS;
    OsalRegisterIntrParams_t interruptRegParams;
    SemaphoreP_Params semParams;
    UART_ICSS_INSTANCE icssInstId;
    PRUSS_PruCores pruInstId;

    if (handle != NULL) // check handle parameter against NULL
    {
        // Get the pointer to the object
        object = (UART_V2_Object *)handle->object;

        // Determine if UART instance already opened
        key = UART_osalHardwareIntDisable();    // disable HWI while open status is checked
        if (object->isOpen == TRUE) 
        {
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status

            // Attempt to re-open an already UART instance is an error.
            // Inform application of error return of NULL handle.
            handle = NULL;
            return handle;
        }
        else
        {
            object->isOpen = TRUE;              // mark instance as being used
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status
            
            // Initialize UART instance parameters
            if (params == NULL) 
            {
                // No params passed in, so use defaults
                UART_Params_init(&(object->params));
            }
            else 
            {
                // Copy the params contents
                object->params = *params;
            }
            
            // Reset object
            UART_v2_resetObject(object);
            
            swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;    // get SW IP attributes
            icssInstId = swipAttrs->icssInstId;                     // get ICSS instance ID
            pruInstId = swipAttrs->pruInstId;                       // get PRU instance ID

            // Configure interrupts
            if ((retVal == UART_SUCCESS) && (swipAttrs->enableIntr))
            {
                // register Host interrupt
                
                // Construct Hwi object for this UART peripheral.
                // Initialize with defaults.
                Osal_RegisterInterrupt_initParams(&interruptRegParams);

                // Populate the interrupt parameters
                interruptRegParams.corepacConfig.arg = (uintptr_t)handle;
                interruptRegParams.corepacConfig.name = NULL;
                interruptRegParams.corepacConfig.isrRoutine = UART_v2_hwiIntFxn;
#ifdef __TI_ARM_V7R4__
                interruptRegParams.corepacConfig.priority = 0x8U;
#else
                interruptRegParams.corepacConfig.priority = 0x20U;
#endif
                interruptRegParams.corepacConfig.corepacEventNum = 0;                   // C66x currently unsupported
                interruptRegParams.corepacConfig.intVecNum = swipAttrs->hostIntNum;     // Host interrupt number

                // Register interrupts
                UART_osalRegisterInterrupt(&interruptRegParams, &(object->hwi));
                
                if (object->hwi == NULL)
                {
                    // error, unable to register interrupt
                    retVal = UART_ERROR;
                }
                else
                {
                    UART_osalSemParamsInit(&semParams);
                    semParams.mode = SemaphoreP_Mode_BINARY;
                    
                    // If write mode is blocking, construct a lock and set callback functions to NULL
                    if (object->params.writeMode == UART_MODE_BLOCKING) 
                    {
                        semParams.name = "write";
                        object->writeSem = UART_osalCreateBlockingLock(0, &semParams);
                        if (object->writeSem == NULL)
                        {
                            // error, unable to register interrupt
                            retVal = UART_ERROR;
                        }
                        object->params.writeCallback = NULL;
                        object->params.writeCallback2 = NULL;
                    }

                    // If read mode is blocking, create a lock and set callback functions to NULL
                    if ((retVal == UART_SUCCESS) && (object->params.readMode == UART_MODE_BLOCKING))
                    {
                        semParams.name = "read";
                        object->readSem = UART_osalCreateBlockingLock(0, &semParams);
                        if (object->readSem == NULL)
                        {
                            // error, unable to register interrupt
                            retVal = UART_ERROR;
                        }
                        object->params.readCallback = NULL;
                        object->params.readCallback2 = NULL;
                    }
                }
            }
            
            if (retVal == UART_SUCCESS)
            {
                // Update ICSS PRU global configuration table                
                UART_osalPendLock(gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruInstLock, SemaphoreP_WAIT_FOREVER);
                if ((gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].instanceCnt+1) > UART_MAX_INSTANCE_PER_PRU)
                {
                    // error, unable to add new UART instance
                    UART_osalPostLock(gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruInstLock);
                    retVal = UART_ERROR;
                }
                else
                {
                    if (gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].instanceCnt == 0)
                    {
                        gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruGCfgAddr = ((UART_SWIPAttrs const *)handle->hwAttrs)->gCfgAddr;
                        gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruInstId = pruInstId;
                    }
                    gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].handlePtr[((UART_SWIPAttrs const *)handle->hwAttrs)->uartInstId] = (uintptr_t)handle;
                    gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].instanceCnt++;
                    if (gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruIcssHandle == NULL) // check if PRU FW downloaded
                    {
                        // initialize ICSS & PRU
                        retVal = UART_v2_initIcssPru(handle, params, false);
                        
                        if (retVal == UART_SUCCESS)
                        {
                            // configure PRU UART global configuration registers
                            retVal = UART_v2_initFwGlobalCfg(handle, pruInstId);
                        }
                        
                        if (retVal == UART_SUCCESS)
                        {
                            // enable PRU (start code execution)
                            retVal = UART_v2_enablePru(handle);
                        }

                        if (retVal == UART_SUCCESS)
                        {
                            // wait (poll) for FW init notification
                            retVal = UART_v2_waitFwInitNotify(handle);
                        }
                    }
                    UART_osalPostLock(gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruInstLock);
                }
            }

            if (retVal == UART_SUCCESS)
            {
                // Confirm UART instance disabled
                retVal = UART_v2_checkInstDisabled(handle);
            }
                
            if (retVal == UART_SUCCESS)
            {
                // Configure UART instance
                
                // Configure PRU UART FW pin mux
                retVal = UART_v2_configInstPinMux(handle, swipAttrs->enableHwFcPins);

                if (retVal == UART_SUCCESS)
                {
                    // Disable interrupts
                    
                    // Configure FW register, disable Tx FIFO empty interrupt
                    retVal = UART_v2_disableInstTxInt(handle, TX_BUFF_EMPTY_INT);

                    if (retVal == UART_SUCCESS)
                    {
                        // Configure FW register, disable Rx char interrupt
                        retVal = UART_v2_disableInstRxInt(handle, RX_CHAR_INT);
                    }                
                }
                
                if (retVal == UART_SUCCESS)
                {
                    // Configure FW register, UART configuration
                    retVal = UART_v2_configInst(handle);
                }
                    
                if (retVal == UART_SUCCESS)
                {
                    // Configure FW registers, Tx/Rx pins
                    retVal = UART_v2_configInstPins(handle);
                }
                    
                if (retVal == UART_SUCCESS)
                {
                    // Configure FW registers, Tx/Rx system events
                    retVal = UART_v2_configInstSysEvts(handle);
                }
                    
                if (retVal == UART_SUCCESS)
                {
                    // Clear Tx/Rx buffers
                    
                    // Clear FW Tx buffer
                    retVal = UART_v2_clearInstTxBuffer(handle);

                    if (retVal == UART_SUCCESS)
                    {
                        // Clear FW Rx buffer
                        retVal = UART_v2_clearInstRxBuffer(handle);
                    }
                }                
            }
            
            if (retVal == UART_SUCCESS)
            {
                // Send PRU UART FW configuration notification, FW registers have been initialized
                retVal = UART_v2_enableInst(handle);
                
                // Wait (poll) for PRU UART FW configuration notification ACK
                if (retVal == UART_SUCCESS)
                {
                    retVal = UART_v2_waitInstEnableAck(handle);
                }                
            }
        }
    }
    
    if (retVal != UART_SUCCESS)
    {
        UART_close_v2(handle);        
        handle = NULL;
    }

    return handle;
}

/*
 *  ======== UART_read_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_read().
 */
// read size chars from UART instance to buffer 
//  Parameters:
//      handle  : Input, UART handle
//      buf     : Input, address of buffer to write characters read
//      size    : Input, number of characters to read
//
//  Return: Number of characters read, or UART_ERROR on error
static int32_t UART_read_v2(UART_Handle handle, void *buffer, size_t size)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t key;
    UART_Transaction *pTrans;
    int32_t retVal = 0;
    
    // Validate input parameters
    if ((handle == NULL) || (buffer == NULL))
    {
        return UART_ERROR;
    }
    
    // Get pointer to SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;

    if (swipAttrs->enableIntr)
    {
        // Interrupts enabled, execute read in BLOCKING or CALLBACK mode
        
        // Determine if read already in progress for UART instance
        key = UART_osalHardwareIntDisable();    // disable HWI while shared context read/written
        if (object->readSize != 0)
        {
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status
            retVal = UART_ERROR;
        }
        else
        {
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status
         
            // save transaction information in object
            pTrans = &(object->rdTrans);
            pTrans->buf = (void *)buffer;
            pTrans->timeout = object->params.readTimeout; // timeout only set in UART_open() for UART_read_v2() API function
            pTrans->count = (uint32_t)size;
            
            // perform read using transaction
            UART_read2_v2(handle, pTrans);
            
            // BLOCKING mode: transaction count is number of characters read
            // CALLBACK mode: transaction count is 0, count obtained from callback function
            retVal = pTrans->count;
        }
    }
    else
    {
        // Interrupts disabled, execute read in POLLING mode.
        // Return value is number of characters read.
        retVal = UART_readPolling_v2(handle, buffer, size);   
    }
    
    return retVal;
}

/*
 *  ======== UART_readPolling_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_readPolling().
 */
// read size chars from UART instance to buffer, POLLING mode
// attempt to read characters until all characters read, or time out occurs
//  Parameters:
//      handle  : Input, UART instance handle
//      buf     : Input, address of buffer to write characters read
//      size    : Input, number of characters to read
//
//  Return: number of characters read, or UART_ERROR on error
static int32_t UART_readPolling_v2(UART_Handle handle, void *buf, size_t size)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t timeout;       // time out value
    int32_t count;          // number of chars read
    uint32_t timeoutErr;    // flag indicating whether time out error occurred
    uint16_t *buffer;
    uint32_t status;

    // Validate input parameters
    if ((handle == NULL) || (buf == NULL))
    {
        return UART_ERROR;
    }

    // Get pointer to SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Initialize pointer to buffer
    buffer = (uint16_t *)buf;
    
    // Get time out value.
    // For this API function, time out value can only be set during UART_open().
    //
    // Time reference for time out is provided by OSAL => RTOS,
    // this can only be executed from a Task context.
    timeout = object->params.readTimeout;

    // Read characters
    count = 0;          // reset count of characters read from UART
    timeoutErr = FALSE; // initialize time out error flag to FALSE
    while ((size != 0) && (timeoutErr == FALSE))
    {
        // Read next character
        status = UART_v2_getInstCharRxBuffTimeout(swipAttrs, buffer, &timeout);
        if (status == FALSE)
        {
            // set flag indicating time out occurred
            timeoutErr = TRUE;
        }
        else
        {
            count++;    // increment count of characters read
            size--;     // decrement count of characters to read

            // Process Read Data Mode when set to Text 
            if ((object->params.readDataMode == UART_DATA_TEXT) && 
                (*buffer == ((uint16_t)('\r'))))
            {
                if (object->params.readEcho)
                {
                    // Echo mode enabled, echo carriage return
                    // note: using read timeout value for write
                    status = UART_v2_putInstCharTxBuffTimeout(swipAttrs, ((uint16_t)('\r')), &timeout);
                    if (status == FALSE)
                    {
                        // set flag indicating time out occurred
                        timeoutErr = TRUE;
                    }
                }
                if (timeoutErr == FALSE)
                {
                    // Read data mode is text.
                    // Replace carriage return w/ line feed.
                    *buffer = ((uint16_t)('\n'));
                }
            }

            // If Echo Mode enabled, echo read character
            if ((timeoutErr == FALSE) && (object->params.readEcho == UART_ECHO_ON))
            {
                // Echo mode enabled, echo carriage return
                // note: using read timeout value for write
                status = UART_v2_putInstCharTxBuffTimeout(swipAttrs, *buffer, &timeout);
                if (status == FALSE)
                {
                    timeoutErr = TRUE;
                }
            }

            // If read return mode is newline, stop reading if newline received
            if ((timeoutErr == FALSE) &&
                (object->params.readReturnMode == UART_RETURN_NEWLINE) &&
                (*buffer == ((uint16_t)('\n'))))
            {
                break;
            }
            else
            {
                buffer++;   // increment buffer pointer
            }
        }
    }

    return count;
}

/*
 *  ======== UART_readCancel_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_readCancel().
 */
// cancel current read from UART instance
static void UART_readCancel_v2(UART_Handle handle)
{
    bool status;
    
    OSAL_Assert(!(handle != NULL));    
    
    // cancel read, no callback
    status = UART_v2_cancelInstReadNoCallback(handle);
    if (status == true)
    {
        // execute callback
        UART_v2_callback(handle, true);
    }

    return;
}

/*
 *  ======== UART_write_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_write().
 */
// Write characters in buffer to UART instance
//  Parameters:
//      handle  : Input, UART handle
//      buffer  : Input, buffer containing characters to write
//      size:   : Input, number of characters to write
//
//  Return: Number of characters written, or UART_ERROR on error
static int32_t UART_write_v2(UART_Handle handle, const void *buffer, size_t size)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t key;
    UART_Transaction *pTrans;
    int32_t retVal = 0;
    
    // Validate input parameters
    if ((handle == NULL) || (buffer == NULL))
    {
        return UART_ERROR;
    }
    
    // Get pointer to SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;

    if (swipAttrs->enableIntr)
    {
        // Interrupts enabled, execute write in BLOCKING or CALLBACK mode
        
        // Determine if write already in progress for UART instance
        key = UART_osalHardwareIntDisable();    // disable HWI while shared context read/written
        if (object->writeSize != 0)
        {
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status
            retVal = UART_ERROR;
        }
        else
        {
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status
         
            // save transaction information in object
            pTrans = &(object->wrTrans);
            pTrans->buf = (void *)buffer;
            pTrans->timeout = object->params.writeTimeout; // timeout only set in UART_open() for UART_write_v2() API function
            pTrans->count = (uint32_t)size;
            
            // perform write using transaction
            UART_write2_v2(handle, pTrans);
            
            // BLOCKING mode: transaction count is number of characters written
            // CALLBACK mode: transaction count is 0, count obtained from callback function
            retVal = pTrans->count;
        }
    }
    else
    {
        // Interrupts disabled, execute write in POLLING mode.
        // Return value is number of characters written.
        retVal = UART_writePolling_v2(handle, buffer, size);   
    }
    
    return retVal;
}

/*
 *  ======== UART_writePolling_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_writePolling().
 */
// write size chars in buffer to UART instance, POLLING mode
// attempt to write characters until all characters written, or time out occurs
//  Parameters:
//      handle  : Input, UART instance handle
//      buf     : Input, address of buffer containing characters to write
//      size    : Input, number of characters to write
//
//  Return: number of characters written, or UART_ERROR on error
static int32_t UART_writePolling_v2(UART_Handle handle, const void *buf, size_t size)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t timeout;       // time out value
    int32_t count;          // number of chars written
    uint32_t timeoutErr;    // flag indicating whether time out error occurred
    uint16_t *buffer;
    uint32_t status;
    
    // Validate input parameters
    if ((handle == NULL) || (buf == NULL))
    {
        return UART_ERROR;
    }
    
    // Get pointer to SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Initialize pointer to buffer
    buffer = (uint16_t *)buf;
    
    // Get time out value.
    // For this API function, time out value can only be set during UART_open().
    //
    // Time reference for time out is provided by OSAL => RTOS,
    // this can only be executed from a Task context.
    timeout = object->params.writeTimeout;
    
    count = 0;          // reset count of characters written to UART
    timeoutErr = FALSE; // initialize time out error flag to FALSE
    while ((size != 0) && (timeoutErr == FALSE))
    {
        // Process Write Data Mode when set to Text
        if ((object->params.writeDataMode == UART_DATA_TEXT) && 
            (*buffer == ((uint16_t)('\n'))))
        {
            // Write data mode is text.
            // Output carriage return before line feed.
            status = UART_v2_putInstCharTxBuffTimeout(swipAttrs, ((uint16_t)('\r')), &timeout);
            if (status == FALSE)
            {
                // set flag indicating time out occurred
                timeoutErr = TRUE;
            }
            else
            {
                count++;    // increment count of character written
            }
            
        }
        
        if (timeoutErr == FALSE)
        {
            // write next character to UART
            status = UART_v2_putInstCharTxBuffTimeout(swipAttrs, *buffer, &timeout);
            if (status == FALSE)
            {
                // set flag indicating time out occurred
                timeoutErr = TRUE;
            }
            else
            {
                buffer++;   // increment buffer pointer
                count++;    // increment count of character written
                size--;     // decrement count of characters to write
            }
        }
    }
    
    return count;
}

/*
 *  ======== UART_writeCancel_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_writeCancel().
 */
// cancel current write to UART instance
static void UART_writeCancel_v2(UART_Handle handle)
{
    bool status;
    
    OSAL_Assert(!(handle != NULL));    
    
    // Cancel write, no callback
    status = UART_v2_cancelInstWriteNoCallback(handle);
    if (status == true)
    {
        // Enable Tx FIFO empty interrupt, 
        // callback to application in HWI
        UART_v2_enableInstTxInt(handle, TX_BUFF_EMPTY_INT);
    }
    
    return;
}

/*
 *  ======== UART_read2_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_read2().
 */
// perform read transaction from UART instance
//  Parameters:
//      handle      : Input, UART handle
//      transaction : Input/Output, transaction parameters
//          buf     : Input,    address of buffer containing characters read from UART
//          timeout : Input,    time out for transaction
//          count   : Input,    number of characters to read
//                  : Output,   number of characters read
//          status  : Output,   success or failure
//
//  Return: UART_SUCCESS on success, or UART_ERROR on error
static int32_t UART_read2_v2(UART_Handle handle, UART_Transaction *transaction)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t key;
    uint32_t count;
    SemaphoreP_Status semStatus;
    int32_t retVal = UART_SUCCESS;    
    
    // Validate input parameters
    if ((handle == NULL) || (transaction == NULL))
    {
        return UART_ERROR;
    }
    if ((transaction->buf == NULL) || (transaction->count == 0))
    {
        return UART_ERROR;
    }
    
    // Get pointer to SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    if (swipAttrs->enableIntr)
    {
        // Determine if read already in progress for UART instance
        key = UART_osalHardwareIntDisable();    // disable HWI while shared context read/written
        if (object->readSize != 0)
        {
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status
            retVal = UART_ERROR;
        }
        else
        {
            // Initialize transaction status.
            // Can be updated in HWI.
            transaction->status = UART_TRANSFER_STATUS_SUCCESS;            
            
            // Initialize object read control variables
            object->readTrans = transaction;        // set object read transaction pointer
            object->readBuf = transaction->buf;     // set object pointer to read buffer
            object->readCount = 0;                  // reset object count of characters read
            object->lineStatusErr = 0;              // reset Line Status error indicator
            
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status
            
            // Disable Rx Character interrupt
            retVal = UART_v2_disableInstRxInt(handle, RX_CHAR_INT);
            
            if (retVal == UART_SUCCESS)
            {
                // Attempt to read transaction->count chars from Rx Buffer.
                // Return from UART_readData_v2() indicates number of chars yet to read.
                object->readSize = UART_readData_v2(handle, transaction->count);
                if (object->readSize == 0)
                {
                    // all requested chars read
                    
                    // rewind object read buffer pointer, updated in call to UART_readData_v2()
                    object->readBuf = (uint16_t *)object->readBuf - object->readCount;

                    if (object->readTrans != NULL)
                    {
                        // object contains pointer to read transaction
                        //  set read transaction count (inform caller of number of chars read)
                        object->readTrans->count = object->readCount; // return count of chars read
                    
                        // set transaction status
                        //  The UART FW produces two types of Line Status Error: Framing Error & Parity Error.
                        //  Currently only one type of Line Status error can be returned to the application,
                        //  so the errors are prioritized as follows:
                        //      Highest - Framing Error
                        //      Lowest  - Parity Error
                        //
                        if (object->lineStatusErr & RX_CHAR_FRAMING_ERR_MASK)
                        {
                            object->readTrans->status = UART_TRANSFER_STATUS_ERROR_FE;
                        }
                        else if (object->lineStatusErr & RX_CHAR_PARITY_ERR_MASK)
                        {
                            object->readTrans->status = UART_TRANSFER_STATUS_ERROR_PE;
                        }
                        else 
                        {
                            object->readTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                        }
                    }
                        
                    if (object->params.readMode == UART_MODE_CALLBACK)
                    {
                        // all characters read, execute callback function
                        //  CALLBACK mode: callback function executed
                        UART_v2_callback(handle, true);
                    }
                    // clear object read transaction
                    object->readTrans = NULL;
                    
                    // determine return value for function
                    retVal = (transaction->status == UART_TRANSFER_STATUS_SUCCESS) ? 
                        UART_SUCCESS : UART_ERROR;
                }
                else
                {
                    // enable Rx char received interrupt
                    //  HWI will read more chars from Rx Buffer when interrupt is posted
                    retVal = UART_v2_enableInstRxInt(handle, RX_CHAR_INT);
                    
                    if (retVal == UART_SUCCESS)
                    {
                        if (object->params.readMode == UART_MODE_BLOCKING)
                        {
                            // Pend on lock and wait for HWI to finish read
                            semStatus = UART_osalPendLock(object->readSem, transaction->timeout);
                            if (semStatus == SemaphoreP_OK)
                            {
                                // lock posted before time out
                                
                                // determine return status based on transaction status
                                retVal = (transaction->status == UART_TRANSFER_STATUS_SUCCESS) ? 
                                    UART_SUCCESS : UART_ERROR;
                            }
                            else
                            {
                                // lock pend timed out or other error occurred
                                
                                // cancel read for any characters not yet written
                                UART_v2_cancelInstReadNoCallback(handle);

                                // update transaction status according to pend error
                                transaction->status = (semStatus == SemaphoreP_TIMEOUT) ? 
                                    UART_TRANSFER_STATUS_TIMEOUT : UART_TRANSFER_STATUS_ERROR_OTH;
                                                        
                                retVal = UART_ERROR;
                            }
                        }
                        else
                        {
                            // for callback mode, immediately return SUCCESS,
                            // once the transaction is done, callback function
                            // will return transaction status and actual
                            // read count
                            transaction->count = 0;
                            
                            retVal = UART_SUCCESS;
                        }
                    }
                }
            }
        }
    }
    else
    {
        // Interrupts disabled, execute read in POLLING mode.
        // Return value is number of characters read.
        
        count = UART_readPolling_v2(handle,transaction->buf, transaction->count);
        
        // update transaction output fields, count & status
        if (count == transaction->count)
        {
            transaction->status = UART_TRANSFER_STATUS_SUCCESS;
            retVal = UART_SUCCESS;
        }
        else if (count == UART_ERROR)
        {
            transaction->status = UART_TRANSFER_STATUS_ERROR_OTH;
            retVal = UART_ERROR;
        }
        else if (count < transaction->count)
        {
            transaction->status = UART_TRANSFER_STATUS_TIMEOUT;
            retVal = UART_ERROR;
        }
        
        transaction->count = count;        
    }
    
    return retVal;
}

/*
 *  ======== UART_write2_v2 ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of UART_write2().
 */
// perform write transaction to UART instance
//  Parameters:
//      handle      : Input, UART handle
//      transaction : Input/Output, transaction parameters
//          buf     : Input,    address of buffer containing characters to write
//          timeout : Input,    time out for transaction
//          count   : Input,    number of characters to write
//                  : Output,   number of characters written
//          status  : Output,   success or failure
//
//  Return: UART_SUCCESS on success, or UART_ERROR on error
static int32_t UART_write2_v2(UART_Handle handle, UART_Transaction *transaction)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t key;
    uint32_t count;
    SemaphoreP_Status semStatus;
    int32_t retVal = UART_SUCCESS;
    
    // Validate input parameters
    if ((handle == NULL) || (transaction == NULL))
    {
        return UART_ERROR;
    }
    if ((transaction->buf == NULL) || (transaction->count == 0))
    {
        return UART_ERROR;
    }
    
    // Get pointer to SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    if (swipAttrs->enableIntr)
    {
        // Determine if write already in progress for UART instance
        key = UART_osalHardwareIntDisable();    // disable HWI while shared context read/written
        if (object->writeSize != 0)
        {
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status
            retVal = UART_ERROR;
        }
        else
        {
            // Initialize transaction status.
            // Can be updated in HWI.
            transaction->status = UART_TRANSFER_STATUS_SUCCESS;
            
            // Initialize object write control variables
            object->writeTrans = transaction;       // set object write transaction pointer
            object->writeBuf = transaction->buf;    // set object pointer to write buffer
            object->writeCount = 0;                 // reset object count of characters written
            object->txDataSent = FALSE;             // set object write complete flag to false -- used in HWI to trigger callback
            
            UART_osalHardwareIntRestore(key);   // restore HWI interrupt status
            
            // Disable Tx FIFO empty interrupt
            retVal = UART_v2_disableInstTxInt(handle, TX_BUFF_EMPTY_INT);
            
            if (retVal == UART_SUCCESS)
            {
                // Attempt to write all transaction chars to Tx Buffer.
                // Return from UART_writeData_v2() indicates number of characters written.
                object->writeSize = UART_writeData_v2(handle, transaction->count);
                if (object->writeSize == 0)
                {
                    // all requested chars written to Tx Buffer
                    
                    // Rewind object write buffer pointer so caller will see unmodified input parameter
                    object->writeBuf = (uint16_t *)object->writeBuf - object->writeCount;
                    
                    // Set Output parameters in transaction.
                    // Pointer to transaction in object points to transaction parameter provided to function.
                    if (object->writeTrans != NULL)
                    {
                        object->writeTrans->count = object->writeCount;             // return count of chars written
                        object->writeTrans->status = UART_TRANSFER_STATUS_SUCCESS;  // return status
                    }
                    
                    // set object write complete flag to true -- used in HWI to trigger callback
                    object->txDataSent = TRUE;
                }
                
                // Enable Tx FIFO empty interrupt
                retVal = UART_v2_enableInstTxInt(handle, TX_BUFF_EMPTY_INT);
            }
            
            if (retVal == UART_SUCCESS)
            {
                if (object->params.writeMode == UART_MODE_BLOCKING)
                {
                    // Pend on lock and wait for HWI to finish write
                    semStatus = UART_osalPendLock(object->writeSem, transaction->timeout);
                    if (semStatus == SemaphoreP_OK)
                    {
                        // lock posted before time out
                        
                        // determine return status based on transaction status
                        retVal = (transaction->status == UART_TRANSFER_STATUS_SUCCESS) ? 
                            UART_SUCCESS : UART_ERROR;
                    }
                    else
                    {
                        // lock pend timed out or other error occurred
                        
                        // cancel write for any characters not yet written
                        UART_v2_cancelInstWriteNoCallback(handle);

                        // update transaction status according to pend error
                        transaction->status = (semStatus == SemaphoreP_TIMEOUT) ? 
                            UART_TRANSFER_STATUS_TIMEOUT : UART_TRANSFER_STATUS_ERROR_OTH;
                                                
                        retVal = UART_ERROR;
                    }
                }
                else
                {
                        // for callback mode, immediately return SUCCESS,
                        // once the transaction is done, callback function
                        // will return transaction status and actual
                        // write count
                        transaction->count = 0;
                        
                        retVal = UART_SUCCESS;
                }
            }
        }
    }
    else
    {
        // Interrupts disabled, execute write in POLLING mode.
        // Return value is number of characters written.
        count = UART_writePolling_v2(handle, transaction->buf, transaction->count);
        
        // update transaction output fields, count & status
        if (count == transaction->count)
        {
            transaction->status = UART_TRANSFER_STATUS_SUCCESS;
            retVal = UART_SUCCESS;
        }
        else if (count == UART_ERROR)
        {
            transaction->status = UART_TRANSFER_STATUS_ERROR_OTH;
            retVal = UART_ERROR;
        }
        else if (count < transaction->count)
        {
            transaction->status = UART_TRANSFER_STATUS_TIMEOUT;
            retVal = UART_ERROR;
        }

        transaction->count = count;
    }
    
    return retVal;
}

//
// Should be configurable, same configuration should be used for SWIP system event numbers
//
//static PRUICSS_IntcInitData pruicssIntcInitdata = PRUICSS_INTC_INITDATA;   // ICSS INTC configuration

// Initialize ICSS & PRU:
//  set ICSS pinmux
//  disable PRU
//  init (clear) IMEM/DMEM
//  download code/data to IMEM/DMEM
static int32_t UART_v2_initIcssPru(UART_Handle handle, const UART_Params *params, bool enablePru)
{
    UART_SWIPAttrs const *swipAttrs;
    PRUICSS_Config *pruIcssCfg; // ICSS configuration
    UART_ICSS_INSTANCE icssInstId;
    PRUSS_PruCores pruInstId;
    PRUICSS_Handle pruIcssHandle;
    PRUICSS_IntcInitData pruicssIntcInitdata = PRUICSS_INTC_INITDATA;   // ICSS INTC configuration
    int32_t size;
    int32_t retVal = UART_SUCCESS;

    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    icssInstId = swipAttrs->icssInstId; // get ICSS instance ID
    pruInstId = swipAttrs->pruInstId;   // get PRU instance ID
    
    retVal = PRUICSS_socGetInitCfg(&pruIcssCfg);
    if ((retVal != PRUICSS_RETURN_SUCCESS) || (icssInstId > UART_ICSS_INSTANCE2))
    {
        retVal = UART_ERROR;
    }
    else
    {
        // Create ICSS PRU instance
        pruIcssHandle = PRUICSS_create(pruIcssCfg, icssInstId);
        if (pruIcssHandle == NULL)
        {
            retVal = UART_ERROR;
        }
        
        if (retVal == UART_SUCCESS)
        {
            // Update ICSS PRU global configuration table                
            //UART_osalPendLock(gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruInstLock, SemaphoreP_WAIT_FOREVER);
            gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruIcssHandle = pruIcssHandle;  // update table w/ PRU ICSS handle
            //UART_osalPostLock(gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruInstLock);

            // Set ICSS pinmux to default
            PRUICSS_pinMuxConfig(pruIcssHandle, PRUICSS_PINMUX_DEF);
            
            // Disable PRUs to ensure PRUs not running when application not initialized
            retVal = PRUICSS_pruDisable(pruIcssHandle, pruInstId);
        }
        
        if (retVal == UART_SUCCESS)
        {
            // Initialize ICSS INTC
            retVal = PRUICSS_pruIntcInit(pruIcssHandle, &pruicssIntcInitdata);
            if (retVal != PRUICSS_RETURN_SUCCESS)
            {
                retVal = UART_ERROR;                   
            }
        }
        
        if (retVal == UART_SUCCESS)
        {
            // Reset PRU
            retVal = PRUICSS_pruReset(pruIcssHandle, pruInstId);
            if (retVal != PRUICSS_RETURN_SUCCESS)
            {
                retVal = UART_ERROR;                   
            }
        }
        
        if (retVal == UART_SUCCESS)
        {
            // Initialize PRU local memories
            
            // Initialize DMEM
            size = PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_DATARAM(pruInstId));
            if (size == 0)
            {
                retVal = UART_ERROR;
            }

            if (retVal == UART_SUCCESS)
            {
                // Initialize IMEM
                size = PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_IRAM(pruInstId));
                if (size == 0)
                {
                    retVal = UART_ERROR;
                }
            }
        }
        
        if (retVal == UART_SUCCESS)
        {
            const uint32_t *sourceMem;  // Source memory[ Array of uint32_tegers ]
            uint32_t byteLength;        // Total number of characters to be writen
            
            // Write PRU local memories
            
            if (pruInstId == PRUICCSS_PRU0)
            {
                // Write DMEM0
                sourceMem = ((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->dram0MemBufferStart;
                byteLength = (uint32_t)((uint8_t *)(((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->dram0MemBufferEnd)) - 
                    (uint32_t)((uint8_t *)(((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->dram0MemBufferStart));
                size = PRUICSS_pruWriteMemory(pruIcssHandle, PRU_ICSS_DATARAM(pruInstId), 0, sourceMem, byteLength);
                if (size == 0)
                {
                    retVal = UART_ERROR;
                }
                    
                if (retVal == UART_SUCCESS)
                {
                    // Write IMEM0
                    sourceMem = ((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->iram0MemBufferStart;
                    byteLength = (uint32_t)((uint8_t *)(((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->iram0MemBufferEnd)) - 
                        (uint32_t)((uint8_t *)(((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->iram0MemBufferStart));
                    size = PRUICSS_pruWriteMemory(pruIcssHandle, PRU_ICSS_IRAM(pruInstId), 0, sourceMem, byteLength);
                    if (size == UART_SUCCESS)
                    {
                        retVal = UART_ERROR;
                    }
                }
                
            }
            else if (pruInstId == PRUICCSS_PRU1)
            {
                // Write PRU1 local memories
                
                // Write DMEM1
                sourceMem = ((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->dram1MemBufferStart;
                byteLength = (uint32_t)((uint8_t *)(((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->dram1MemBufferEnd)) - 
                    (uint32_t)((uint8_t *)(((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->dram1MemBufferStart));
                size = PRUICSS_pruWriteMemory(pruIcssHandle, PRU_ICSS_DATARAM(pruInstId), 0, sourceMem, byteLength);
                if (size == 0)
                {
                    retVal = UART_ERROR;
                }
                
                if (retVal == UART_SUCCESS)
                {
                    sourceMem = ((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->iram1MemBufferStart;
                    byteLength = (uint32_t)((uint8_t *)(((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->iram1MemBufferEnd)) - 
                        (uint32_t)((uint8_t *)(((UART_ICSS_Mem_Ptr *)(swipAttrs->icssMemBuff))->iram1MemBufferStart));
                    size = PRUICSS_pruWriteMemory(pruIcssHandle, PRU_ICSS_IRAM(pruInstId), 0, sourceMem, byteLength);
                    if (size == 0)
                    {
                        retVal = UART_ERROR;
                    }
                }                    
            }
            else
            {
                // error, unknown PRU instance ID
                retVal = UART_ERROR;
            }
        }
        
        if ((retVal == UART_SUCCESS) && (enablePru == true))
        {
            // enable PRU
            retVal = PRUICSS_pruEnable(pruIcssHandle, pruInstId);
        }
    }   

    return retVal;
}

// De-initialize PRU:
//  disable PRU
//  reset PRU
//  init IMEM/DMEM
static int32_t UART_v2_deinitIcssPru(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_ICSS_INSTANCE icssInstId;
    PRUSS_PruCores pruInstId;
    PRUICSS_Handle pruIcssHandle;
    int32_t size;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
   // Disable PRU (stop code execution)
    retVal = UART_v2_disablePru(handle);

    // Reset PRU
    if (retVal == UART_SUCCESS)
    {
        retVal = UART_v2_resetPru(handle);
    }
    
    if (retVal == UART_SUCCESS)
    {
        swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;    // get pointer to SWIP attributes
        icssInstId = swipAttrs->icssInstId;                     // get ICSS instance ID
        pruInstId = swipAttrs->pruInstId;                       // get PRU instance ID

        // Get PRU ICSS handle
        pruIcssHandle = gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruIcssHandle;
    
        // Initialize PRU memory
        size = PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_DATARAM(pruInstId));
        if (size == 0)
        {
            retVal = UART_ERROR;
        }
        
        if (retVal == UART_SUCCESS)
        { 
            size = PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_IRAM(pruInstId));
            if (size == 0)
            {
                retVal = UART_ERROR;
            }
        }
    }
    
    if (retVal == UART_SUCCESS)
    {
        gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruIcssHandle = NULL;   
    }

    return retVal;
}

// reset UART v2 object
static void UART_v2_resetObject(UART_V2_Object *object)
{
    object->writeBuf = NULL;
    object->writeCount = 0;
    object->writeSize = 0;
    object->writeCR = false;
    
    object->readBuf = NULL;
    object->readCount = 0;
    object->readSize = 0;
    
    object->readTrans = NULL;
    object->writeTrans = NULL;
        
    return;
}

// configure PRU UART global configuration registers
static int32_t UART_v2_initFwGlobalCfg(UART_Handle handle, PRUSS_PruCores pruInstId)
{
    UART_SWIPAttrs const *swipAttrs;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    
    // Read global configuration FW register
    regVal = HW_RD_REG32(swipAttrs->gCfgAddr);

    // Clear & set PRU ID bit field
    regVal &= ~(uint32_t)ICSS_UART_GCFG__PRU_ID_MASK;
    regVal |= (uint32_t)pruInstId << ICSS_UART_GCFG__PRU_ID_SHIFT;

    // Clear FW init bit field
    regVal &= ~(uint32_t)ICSS_UART_GCFG__FW_INIT_MASK;

    // Write updated global configuration FW register
    HW_WR_REG32(swipAttrs->gCfgAddr, regVal);
        
    return retVal;
}

// wait (poll) for FW init notification
static int32_t UART_v2_waitFwInitNotify(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    uint32_t regVal;
    uint8_t fwInit;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    // Wait (poll) for FW init bit true
    do
    {
        // Read global configuration FW register
        regVal = HW_RD_REG32(swipAttrs->gCfgAddr);

        // Read FW init bit
        fwInit = (uint8_t)((regVal & ICSS_UART_GCFG__FW_INIT_MASK) >> ICSS_UART_GCFG__FW_INIT_SHIFT);
    } while (fwInit == ICSS_UART_GCFG__FW_INIT_FALSE);
        
    return retVal;
}

// enable PRU (start code execution)
static int32_t UART_v2_enablePru(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_ICSS_INSTANCE icssInstId;
    PRUSS_PruCores pruInstId;
    PRUICSS_Handle pruIcssHandle;    
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    icssInstId = swipAttrs->icssInstId; // get ICSS instance ID
    pruInstId = swipAttrs->pruInstId;   // get PRU instance ID
    pruIcssHandle = gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruIcssHandle;  // get PRU ICSS handle

    // Enable PRU
    retVal = PRUICSS_pruEnable(pruIcssHandle, pruInstId);

    return retVal;
}

// disable PRU (stop code execution)
static int32_t UART_v2_disablePru(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_ICSS_INSTANCE icssInstId;
    PRUSS_PruCores pruInstId;
    PRUICSS_Handle pruIcssHandle;    
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    icssInstId = swipAttrs->icssInstId; // get ICSS instance ID
    pruInstId = swipAttrs->pruInstId;   // get PRU instance ID
    pruIcssHandle = gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruIcssHandle;  // get PRU ICSS handle

    // Disable PRU
    retVal = PRUICSS_pruDisable(pruIcssHandle, pruInstId);

    return retVal;
}

// reset PRU
static int32_t UART_v2_resetPru(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_ICSS_INSTANCE icssInstId;
    PRUSS_PruCores pruInstId;
    PRUICSS_Handle pruIcssHandle;    
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    icssInstId = swipAttrs->icssInstId; // get ICSS instance ID
    pruInstId = swipAttrs->pruInstId;   // get PRU instance ID
    pruIcssHandle = gUartCurrentICSSMode[icssInstId].pruMode[pruInstId].pruIcssHandle;  // get PRU ICSS handle

    // Disable PRU
    retVal = PRUICSS_pruReset(pruIcssHandle, pruInstId);

    return retVal;
}

// disable PRU UART FW instance
static int32_t UART_v2_disableInst(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    uint8_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get the pointer to the object and SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
          
    // set enable bit for UART instance
    regVal = HW_RD_REG8(swipAttrs->baseAddr + UART_CTRL_OFFSET);       // read UART Control FW register
    regVal &= ~(uint8_t)UART_CTRL__EN_MASK;                            // clear enable bit
    regVal |= (uint8_t)UART_CTRL__EN_DISABLE << UART_CTRL__EN_SHIFT;   // write disable setting to bit
    HW_WR_REG8(swipAttrs->baseAddr + UART_CTRL_OFFSET, regVal);        // write global configuration FW register

    return retVal;
}

// check PRU UART FW instance disabled
static int32_t UART_v2_checkInstDisabled(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    uint32_t regVal;
    uint8_t enable, txEnableAck, rxEnableAck;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get the pointer to the object and SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    
    // read UART Control FW register
    regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CTRL_OFFSET);

    // get enable & enable-ack bits for UART instance
    enable      = (uint8_t)((regVal & UART_CTRL__EN_MASK) >> UART_CTRL__EN_SHIFT);
    txEnableAck = (uint8_t)((regVal & UART_CTRL__TX_EN_ACK_MASK) >> UART_CTRL__TX_EN_ACK_SHIFT);
    rxEnableAck = (uint8_t)((regVal & UART_CTRL__RX_EN_ACK_MASK) >> UART_CTRL__RX_EN_ACK_SHIFT);

    // enable & enable-ack bits should be cleared if UART instance is disabled
    if ((enable == UART_CTRL__EN_ENABLE) || 
        (txEnableAck == UART_CTRL__EN_ACK_ENABLE) || 
        (rxEnableAck == UART_CTRL__EN_ACK_ENABLE))
    {
        retVal = UART_ERROR;
    }

    return retVal;
}

// enable PRU UART FW instance
static int32_t UART_v2_enableInst(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    uint8_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get the pointer to the object and SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
          
    // set enable bit for UART instance
    regVal = HW_RD_REG8(swipAttrs->baseAddr + UART_CTRL_OFFSET);        // read UART Control FW register
    regVal &= ~(uint8_t)UART_CTRL__EN_MASK;                             // clear enable bit
    regVal |= (uint8_t)UART_CTRL__EN_ENABLE << UART_CTRL__EN_SHIFT;     // write enable setting to bit
    HW_WR_REG8(swipAttrs->baseAddr + UART_CTRL_OFFSET, regVal);         // write global configuration FW register
    
    return retVal;
}

// wait (poll) for PRU UART FW instance enable-ack
static int32_t UART_v2_waitInstEnableAck(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    volatile uint32_t regVal;
    uint8_t txEnableAck, rxEnableAck;
    int32_t retVal = UART_SUCCESS;

    OSAL_Assert(!(handle != NULL));
    
    // Get the pointer to the object and SW IP attributs
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
            
    // wait (poll) for enable-ack bits enabled
    do
    {
        // read UART Control FW register
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CTRL_OFFSET);
        
        // get enable-ack bits for UART instance
        txEnableAck = (uint8_t)((regVal & UART_CTRL__TX_EN_ACK_MASK) >> UART_CTRL__TX_EN_ACK_SHIFT);
        rxEnableAck = (uint8_t)((regVal & UART_CTRL__RX_EN_ACK_MASK) >> UART_CTRL__RX_EN_ACK_SHIFT);
    } while ((txEnableAck == UART_CTRL__EN_ACK_DISABLE) || (rxEnableAck == UART_CTRL__EN_ACK_DISABLE));

    return retVal;
}

// disable PRU UART FW instance interrupt
static int32_t UART_v2_disableInstTxInt(UART_Handle handle, uint8_t intMask)
{
    UART_SWIPAttrs const *swipAttrs;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    if (intMask & TX_BUFF_EMPTY_INT)
    {
        // disable Tx interrupt
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_TX_PIN_INT_OFFSET);
        regVal &= ~(uint32_t)UART_TX_PIN_INT_CFG__TX_INT_EN_MASK;
        HW_WR_REG32(swipAttrs->baseAddr + UART_TX_PIN_INT_OFFSET, regVal);
    }
    else
    {
        // error, invalid interrupt mask
        retVal = UART_ERROR;
    }        

    return retVal;
}

// enable PRU UART FW instance Tx interrupt
static int32_t UART_v2_enableInstTxInt(UART_Handle handle, uint8_t intMask)
{
    UART_SWIPAttrs const *swipAttrs;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;

    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    if (intMask & TX_BUFF_EMPTY_INT)
    {
        // enable Tx interrupt
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_TX_PIN_INT_OFFSET);
        regVal |= (uint32_t)UART_TX_PIN_INT_CFG__TX_INT_EN_MASK;
        HW_WR_REG32(swipAttrs->baseAddr + UART_TX_PIN_INT_OFFSET, regVal);
    }
    else
    {
        // error, invalid interrupt mask
        retVal = UART_ERROR;
    }        

    return retVal;
}

// disable PRU UART FW instance interrupt
static int32_t UART_v2_disableInstRxInt(UART_Handle handle, uint8_t intMask)
{
    UART_SWIPAttrs const *swipAttrs;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    if (intMask & RX_CHAR_INT)
    {
        // disable Rx interrupt
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_RX_PIN_INT_OFFSET);
        regVal &= ~(uint32_t)UART_RX_PIN_INT_CFG__RX_INT_EN_MASK;
        HW_WR_REG32(swipAttrs->baseAddr + UART_RX_PIN_INT_OFFSET, regVal);
    }
    else
    {
        // error, invalid interrupt mask
        retVal = UART_ERROR;
    }        

    return retVal;
}

// enable PRU UART FW instance interrupt
static int32_t UART_v2_enableInstRxInt(UART_Handle handle, uint8_t intMask)
{
    UART_SWIPAttrs const *swipAttrs;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    if (intMask & RX_CHAR_INT)
    {
        // disable Rx interrupt
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_RX_PIN_INT_OFFSET);
        regVal |= (uint32_t)UART_RX_PIN_INT_CFG__RX_INT_EN_MASK;
        HW_WR_REG32(swipAttrs->baseAddr + UART_RX_PIN_INT_OFFSET, regVal);
    }
    else
    {
        // error, invalid interrupt mask
        retVal = UART_ERROR;
    }        

    return retVal;
}

/*
 *  ======== UART_v2_configInstPinMux ========
 */
static int32_t UART_v2_configInstPinMux(UART_Handle handle, bool enableHwFcPins)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_PRU_IOPinMuxAttrs pinReg;
    int32_t retVal = UART_SUCCESS;

    OSAL_Assert(!(handle != NULL));
    
    // Get the pointer to the object and SW IP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    // Set the Tx pin mux register value for GPO
    pinReg = swipAttrs->txPin;
    UART_v2_pruGPIOMuxConfig(&pinReg, UART_PRU_PINMUX_GPO_MODE);

    // Set the Rx pin mux register value for GPI
    pinReg = swipAttrs->rxPin;
    UART_v2_pruGPIOMuxConfig(&pinReg, UART_PRU_PINMUX_GPI_MODE);

    if (enableHwFcPins == true)
    {
        // Set the CTS pin mux register value for GPI
        pinReg = swipAttrs->ctsPin;
        UART_v2_pruGPIOMuxConfig(&pinReg, UART_PRU_PINMUX_GPI_MODE);

        // Set the RTS pin mux register value for GPO
        pinReg = swipAttrs->rtsPin;
        UART_v2_pruGPIOMuxConfig(&pinReg, UART_PRU_PINMUX_GPO_MODE);
    }

    return retVal;
}

// setup PRU UART FW instance configuration register
static int32_t UART_v2_configInst(UART_Handle handle)
{
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Configure Baud Rate FW register
    retVal = UART_v2_configInstBaudRate(handle);
    
    // Configure Number of Bits Per Character FW register
    if (retVal == UART_SUCCESS)
    {
        retVal = UART_v2_configInstNumBitsPerChar(handle);
    }
    
    // Configure Stop Bit Size FW register
    if (retVal == UART_SUCCESS)
    {
        retVal = UART_v2_configInstStopBitSize(handle);
    }
    
    // Configure Parity Enable / Type FW registers
    if (retVal == UART_SUCCESS)
    {
        retVal = UART_v2_configInstParity(handle);
    }
    
    // Configure HW Flow Control FW registers
    if (retVal == UART_SUCCESS)
    {
        retVal = UART_v2_configInstHwFlowControl(handle);
    }
    
    return retVal;
}

// setup PRU UART FW instance Tx/Rx pins registers
static int32_t UART_v2_configInstPins(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    // Setup Tx pins registers
    regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_TX_PIN_INT_OFFSET);
    regVal &= ~(uint32_t)UART_TX_PIN_INT_CFG__TX_PIN_MASK;
    regVal |= (uint32_t)swipAttrs->txPin.pinNum << UART_TX_PIN_INT_CFG__TX_PIN_SHIFT;
    regVal &= ~(uint32_t)UART_TX_PIN_INT_CFG__CTS_PIN_MASK;
    regVal |= (uint32_t)swipAttrs->ctsPin.pinNum << UART_TX_PIN_INT_CFG__CTS_PIN_SHIFT;
    HW_WR_REG32(swipAttrs->baseAddr + UART_TX_PIN_INT_OFFSET, regVal);
    
    // Setup Rx pins registers
    regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_RX_PIN_INT_OFFSET);
    regVal &= ~(uint32_t)UART_RX_PIN_INT_CFG__RX_PIN_MASK;
    regVal |= (uint32_t)swipAttrs->rxPin.pinNum << UART_RX_PIN_INT_CFG__RX_PIN_SHIFT;
    regVal &= ~(uint32_t)UART_RX_PIN_INT_CFG__RTS_PIN_MASK;
    regVal |= (uint32_t)swipAttrs->rtsPin.pinNum << UART_RX_PIN_INT_CFG__RTS_PIN_SHIFT;
    HW_WR_REG32(swipAttrs->baseAddr + UART_RX_PIN_INT_OFFSET, regVal);        

    return retVal;
}

// setup PRU UART FW instance Tx/Rx system events registers
static int32_t UART_v2_configInstSysEvts(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    // Setup Tx System Event register
    regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_TX_PIN_INT_OFFSET);
    regVal &= ~(uint32_t)UART_TX_PIN_INT_CFG__TX_INT_NUM_MASK;
    regVal |= (uint32_t)swipAttrs->txIcssIntcSysEvt << UART_TX_PIN_INT_CFG__TX_INT_NUM_SHIFT;
    HW_WR_REG32(swipAttrs->baseAddr + UART_TX_PIN_INT_OFFSET, regVal);
    
    // Setup Rx System Event register
    regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_RX_PIN_INT_OFFSET);
    regVal &= ~(uint32_t)UART_RX_PIN_INT_CFG__RX_INT_NUM_MASK;
    regVal |= (uint32_t)swipAttrs->rxIcssIntcSysEvt << UART_RX_PIN_INT_CFG__RX_INT_NUM_SHIFT;        
    HW_WR_REG32(swipAttrs->baseAddr + UART_RX_PIN_INT_OFFSET, regVal);        

    return retVal;
}

// clear PRU UART FW instance Tx buffer
static int32_t UART_v2_clearInstTxBuffer(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    // Clear buffer
    memset((void *)swipAttrs->txBuff, 0, BUFF_SIZE*sizeof(uint8_t));

    return retVal;
}

// clear PRU UART FW instance Rx buffer
static int32_t UART_v2_clearInstRxBuffer(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;

    // Clear buffer
    memset((void *)swipAttrs->rxBuff, 0, BUFF_SIZE*sizeof(uint8_t));

    return retVal;
}

/**
 * change the pinmux of GPIO pins of pru based on FW.
 **/ 
static void UART_v2_pruGPIOMuxConfig(UART_PRU_IOPinMuxAttrs *handle, uint32_t pinMode)
{
    uint32_t regVal;
    
    OSAL_Assert(!(handle != NULL));
    
    regVal = *(volatile uint32_t *)(handle->baseRegAddr);
    if (UART_PRU_PINMUX_GPI_MODE == pinMode)
    {
        regVal &= UART_PRU_GPI_SELECT_MASK;
        regVal |= UART_PRU_GPI_INPUT_ENABLE;
        regVal |= (uint32_t)(handle->inputModeVal);
    }
    else if (UART_PRU_PINMUX_GPO_MODE == pinMode)
    {
        regVal &= UART_PRU_GPO_SELECT_MASK;
        regVal |= UART_PRU_GPO_OUTPUT_ENABLE;
        regVal |= (uint32_t)(handle->outputModeVal);
    }
    else
    {
        /* nothing to be done here */
    }
    *(volatile uint32_t *)(handle->baseRegAddr) = regVal;
}

// configure Baud Rate FW register
static int32_t UART_v2_configInstBaudRate(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint8_t fwBaudRate;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;

    // Translate UART API Baud Rate parameter to Baud Rate FW register setting
    fwBaudRate = xlateUartBaudRateToFwBaudRate(object->params.baudRate);
    
    // Setup Baud Rate FW register
    regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
    regVal &= ~(uint32_t)UART_CFG__BAUD_RATE_MASK;                  // clear Baud Rate bit field
    regVal |= (uint32_t)fwBaudRate << UART_CFG__BAUD_RATE_SHIFT;    // set Baud Rate bit field
    HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);

    return retVal;
}

// Translate UART API Baud Rate parameter to Baud Rate FW register setting
static uint8_t xlateUartBaudRateToFwBaudRate(uint32_t baudRate)
{
    int8_t retVal;

    switch (baudRate)
    {
        case BAUD_RATE_300:
            retVal = UART_CFG__BAUD_RATE_300;
            break;
        case BAUD_RATE_600:
            retVal = UART_CFG__BAUD_RATE_600;
            break;
        case BAUD_RATE_1200:
            retVal = UART_CFG__BAUD_RATE_1200;
            break;
        case BAUD_RATE_2400:
            retVal = UART_CFG__BAUD_RATE_2400;
            break;
        case BAUD_RATE_4800:
            retVal = UART_CFG__BAUD_RATE_4800;
            break;
        case BAUD_RATE_9600:
            retVal = UART_CFG__BAUD_RATE_9600;
            break;
        case BAUD_RATE_14400:
            retVal = UART_CFG__BAUD_RATE_14400;
            break;
        case BAUD_RATE_19200:
            retVal = UART_CFG__BAUD_RATE_19200;
            break;
        case BAUD_RATE_28800:
            retVal = UART_CFG__BAUD_RATE_28800;
            break;
        case BAUD_RATE_38400:
            retVal = UART_CFG__BAUD_RATE_38400;
            break;
        case BAUD_RATE_57600:
            retVal = UART_CFG__BAUD_RATE_57600;
            break;
        case BAUD_RATE_115200:
            retVal = UART_CFG__BAUD_RATE_115200;
            break;
        default:
            // invalid data length setting
            retVal = (-((int8_t)1));            
            break;
    }
    
    return retVal;
}


// Configure Number of Bits Per Character FW register
static int32_t UART_v2_configInstNumBitsPerChar(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint8_t fwNumBitsPerChar;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Translate UART API Data Length parameter to Number of Bits per Character FW register setting
    fwNumBitsPerChar = xlateUartDatalenToFwNumBitsPerChar(object->params.dataLength);
    
    // Setup Number of Bits Per Character FW register
    regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
    regVal &= ~(uint32_t)UART_CFG__NO_BITS_PER_CHAR_MASK;                       // clear Number of Bits per Character bit field
    regVal |= (uint32_t)fwNumBitsPerChar << UART_CFG__NO_BITS_PER_CHAR_SHIFT;   // set Number of Bits per Character bit field
    HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);

    return retVal;
}

// Translate UART API Data Length parameter to Number of Bits per Character FW register setting
static uint8_t xlateUartDatalenToFwNumBitsPerChar(UART_LEN dataLength)
{
    int8_t retVal;
    
    switch (dataLength)
    {
        case UART_LEN_5:
            retVal = UART_CFG__NUM_BITS_PER_CHAR_5;
            break;
        case UART_LEN_6:
            retVal = UART_CFG__NUM_BITS_PER_CHAR_6;
            break;
        case UART_LEN_7:
            retVal = UART_CFG__NUM_BITS_PER_CHAR_7;
            break;
        case UART_LEN_8:
            retVal = UART_CFG__NUM_BITS_PER_CHAR_8;
            break;
        case UART_LEN_9:
            retVal = UART_CFG__NUM_BITS_PER_CHAR_9;
            break;
        default:
            // invalid data length setting
            retVal = (-((int8_t)1));
            break;
    }
    
    return retVal;
}


// Configure Stop Bit Size FW register
static int32_t UART_v2_configInstStopBitSize(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint8_t fwStopBitSize;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Translate UART API Stop Bits parameter to Stop Bits Size FW register setting
    fwStopBitSize = xlateUartStopBitsToFwStopBitSize(object->params.stopBits);
    
    // Setup Number of Bits Per Character FW register
    regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
    regVal &= ~(uint32_t)UART_CFG__STOP_BIT_SZ_MASK;                    // clear Stop Bit Size bit field
    regVal |= (uint32_t)fwStopBitSize << UART_CFG__STOP_BIT_SZ_SHIFT;   // set Stop Bit Size bit field
    HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);

    return retVal;
}

// Translate UART API Stop Bits to Number of Bits per Character FW register setting
static uint8_t xlateUartStopBitsToFwStopBitSize(UART_STOP stopBits)
{
    int8_t retVal;
    
    switch (stopBits)
    {
        case UART_STOP_ONE:
            retVal = UART_CFG__STOP_BIT_SZ_1;
            break;
        case UART_STOP_TWO:
            retVal = UART_CFG__STOP_BIT_SZ_2;
            break;
        case UART_STOP_ONEP5:
            retVal = UART_CFG__STOP_BIT_SZ_1_5;
            break;
        default:
            // invalid data length setting
            retVal = (-((int8_t)1));
            break;
    }
    
    return retVal;
}

// Configure Parity Enable / Type FW registers
static int32_t UART_v2_configInstParity(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Setup Parity Enable & Parity Type FW registers
    if (object->params.parityType == UART_PAR_NONE)
    {
        // Set Parity Enable FW register to disable
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
        regVal &= ~(uint32_t)UART_CFG__PARITY_EN_MASK;                                  // clear Parity Enable bit field
        regVal |= (uint32_t)UART_CFG__PARITY_EN_DISABLE << UART_CFG__PARITY_EN_SHIFT;   // set Parity Enable bit field
        HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);
    }
    else if (object->params.parityType == UART_PAR_EVEN)
    {
        // Set Parity Enable FW register to enable
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
        regVal &= ~(uint32_t)UART_CFG__PARITY_EN_MASK;                                  // clear Parity Enable bit field
        regVal |= (uint32_t)UART_CFG__PARITY_EN_ENABLE << UART_CFG__PARITY_EN_SHIFT;    // set Parity Enable bit field
        HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);
 
        // Set Parity Type FW register
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
        regVal &= ~(uint32_t)UART_CFG__PARITY_TYPE_MASK;                                // clear Parity Type bit field
        regVal |= (uint32_t)UART_CFG__PARITY_TYPE_EVEN << UART_CFG__PARITY_TYPE_SHIFT;  // set Parity Type bit field
        HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);
    }
    else if (object->params.parityType == UART_PAR_ODD)
    {
        // Set Parity Enable FW register to enable
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
        regVal &= ~(uint32_t)UART_CFG__PARITY_EN_MASK;                                  // clear Parity Enable bit field
        regVal |= (uint32_t)UART_CFG__PARITY_EN_ENABLE << UART_CFG__PARITY_EN_SHIFT;    // set Parity Enable bit field
        HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);
 
        // Set Parity Type FW register
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
        regVal &= ~(uint32_t)UART_CFG__PARITY_TYPE_MASK;                                // clear Parity Type bit field
        regVal |= (uint32_t)UART_CFG__PARITY_TYPE_ODD << UART_CFG__PARITY_TYPE_SHIFT;   // set Parity Type bit field
        HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);
    }
    else
    {
        // Unsupported (ZERO, ONE) or invalid parity type
        retVal = UART_ERROR;
    }

    return retVal;
}

// Configure HW Flow Control FW registers
static int32_t UART_v2_configInstHwFlowControl(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t regVal;
    int32_t retVal = UART_SUCCESS;
    
    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Setup Parity Enable & Parity Type FW registers
    if (object->params.flowControlType == UART_FC_NONE)
    {
        // Set Flow Control FW register to disable
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
        regVal &= ~(uint32_t)UART_CFG__FC_EN_MASK;                                          // clear Flow Control enable bit field
        regVal |= (uint32_t)UART_CFG__FC_EN_DISABLE << UART_CFG__FC_EN_SHIFT;               // set Flow Control enable bit field
        HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);
    }
    else if (object->params.flowControlType == UART_FC_HW)
    {
        // Set Flow Control FW register to enable
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
        regVal &= ~(uint32_t)UART_CFG__FC_EN_MASK;                                          // clear Flow Control enable bit field
        regVal |= (uint32_t)UART_CFG__FC_EN_ENABLE << UART_CFG__FC_EN_SHIFT;                // set Flow Control enable bit field
        HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);
 
        // Set HW Flow Control Threshold FW register
        regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET);
        regVal &= ~(uint32_t)UART_CFG__HW_FC_THR_MASK;                                      // clear Parity Type bit field
        regVal |= (uint32_t)object->params.hwFlowControlThr << UART_CFG__HW_FC_THR_SHIFT;   // set Parity Type bit field
        HW_WR_REG32(swipAttrs->baseAddr + UART_CFG_OFFSET, regVal);
    }
    else
    {
        // Invalid flow control type
        retVal = UART_ERROR;
    }

    return retVal;
}

// Cancel write for UART instance.
// No cancellation performed for characters already written to SW IP.
static bool UART_v2_cancelInstWriteNoCallback(UART_Handle handle)
{
    UART_V2_Object *object;
    uint32_t key;
    int32_t disIntStatus = UART_SUCCESS;
    bool retVal = true;

    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Disable Tx Buffer empty interrupt
    disIntStatus = UART_v2_disableInstTxInt(handle, TX_BUFF_EMPTY_INT);

    if (disIntStatus == UART_SUCCESS)
    {
        // Disable interrupts to avoid writing data while changing state. */
        key = UART_osalHardwareIntDisable();

        if (object->writeSize == 0)
        {
            // no write in progress to cancel
            UART_osalHardwareIntRestore(key);
            
            if (object->txDataSent == FALSE) // check if callback already invoked
            {
                retVal = false;
            }
        }
        else
        {
            // Rewind object write buffer pointer so caller will see unmodified input parameter
            object->writeBuf = (uint16_t *)object->writeBuf - object->writeCount;
            
            // Set Output parameters in transaction.
            // Pointer to transaction in object points to transaction parameter provided to function.
            if (object->writeTrans != NULL)
            {
                // return count of chars written up to cancellation
                object->writeTrans->count = object->writeCount;
            }

            // set object write size to 0 since no more chars to write (at point of cancel)
            object->writeSize = 0;
            
            // disable HWI until object write size set to 0
            UART_osalHardwareIntRestore(key);
        }
    }
    else
    {
        retVal = false;
    }
    
    return retVal;
}

// Cancel read from UART instance.
// Flushes Rx Buffer.
static bool UART_v2_cancelInstReadNoCallback(UART_Handle handle)
{
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    uint32_t key;
    int32_t disIntStatus = UART_SUCCESS;
    uint16_t charRead = (uint16_t)0xFFFF;
    uint32_t status;
    bool retVal = true;

    OSAL_Assert(!(handle != NULL));
    
    // Get pointer to SWIP attributes
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;
    // Get pointer to object
    object = (UART_V2_Object *)handle->object;
    
    // Disable Rx Character interrupt
    disIntStatus = UART_v2_disableInstRxInt(handle, RX_CHAR_INT);

    if (disIntStatus == UART_SUCCESS)
    {
        // Disable interrupts to avoid writing data while changing state. */
        key = UART_osalHardwareIntDisable();

        if (object->readSize == 0)
        {
            // no read in progress to cancel
            UART_osalHardwareIntRestore(key);
            retVal = false;
        }
        else
        {
            // Rewind object read buffer pointer so caller will see unmodified input parameter
            object->readBuf = (uint16_t *)object->readBuf - object->readCount;
            
            // Set Output parameters in transaction.
            // Pointer to transaction in object points to transaction parameter provided to function.
            if (object->readTrans != NULL)
            {
                // return count of chars read (at point of read cancel)
                object->readTrans->count = object->readCount;
            }

            // set object read size to 0 since no more chars to read (at point of cancel)
            object->readSize = 0;
            
            // enable HW interrupts,
            // HWI disabled until object read size set to 0
            UART_osalHardwareIntRestore(key);
            
            // Flush Rx Buffer
            do 
                status = UART_v2_getInstCharRxBuffNonBlock(swipAttrs, &charRead);
            while (status == TRUE);
        }
    }
    else
    {
        retVal = false;
    }
    
    return retVal;
}

/*
 *  ======== UART_v2_putInstCharTxBuffTimeout ========
 *
 *  This function continuously does a non-blocking write, until it writes
 *  successfully or times out.
 */
// Time reference for time out is provided by OSAL => RTOS,
// this can only be executed from a Task context.
static uint32_t UART_v2_putInstCharTxBuffTimeout(UART_SWIPAttrs const *swipAttrs, uint16_t charWrite, uint32_t *timeout)
{
    uint32_t timeoutCnt = *timeout;
    uint32_t status;
    uint32_t retVal;

    retVal = TRUE;
    while (retVal == TRUE)
    {
        status = UART_v2_putInstCharTxBuffNonBlock(swipAttrs, charWrite);
        if (status == FALSE)
        {
            // character not written to Tx Buffer
            if (timeoutCnt > 0)
            {
                UART_osalDelay(1U);
                timeoutCnt--;
            }
            
            if (timeoutCnt == 0)
            {
                retVal = FALSE;
            }
        }
        else
        {
            // character written to Tx Buffer
            break;
        }
        
    }
    
    *timeout = timeoutCnt;  // return time out count
    return retVal;
}

// Continuously perform non-blocking read from Rx Buffer, until read successful or time out
// Time reference for time out is provided by OSAL => RTOS,
// this can only be executed from a Task context.
static uint32_t UART_v2_getInstCharRxBuffTimeout(UART_SWIPAttrs const *swipAttrs, uint16_t *pCharRead, uint32_t *timeout)
{
    uint32_t timeoutCnt = *timeout;
    uint16_t charRead = (uint16_t)0xFFFF;
    uint32_t status;
    uint32_t retVal;

    retVal = TRUE;
    while (retVal == TRUE)
    {
        status = UART_v2_getInstCharRxBuffNonBlock(swipAttrs, &charRead);
        if (status == FALSE)
        {
            // character not read from Rx Buffer
            if (timeoutCnt > 0)
            {
                UART_osalDelay(1U);
                timeoutCnt--;
            }
            
            if (timeoutCnt == 0)
            {
                retVal = FALSE;
            }
        }
        else
        {
            // character read from Rx Buffer
            *pCharRead = charRead;
            break;
        }
    }
    
    *timeout = timeoutCnt;  // return time out count
    return retVal;
}

// Write character into Tx Buffer
static void UART_v2_putInstCharTxBuff(UART_SWIPAttrs const *swipAttrs, uint16_t charWrite)
{
    uint8_t *ptr;
    uint8_t txWrPtr;
    
    // get Tx buffer write pointer
    ptr = (uint8_t *)(swipAttrs->baseAddr + UART_RD_WR_PTRS_OFFSET);
    txWrPtr = *(ptr+1);
    
    // write character
    *((uint16_t *)swipAttrs->txBuff + (txWrPtr>>1)) = charWrite;

    // update write pointer
    txWrPtr = (txWrPtr+sizeof(uint16_t))&(BUFF_SIZE-1);
    *(ptr+1) = txWrPtr;
    
    return;
}

// Perform non-blocking write of 16-bit character into Tx Buffer
//  Parameters:
//      baseAddr    : SWIP base address
//      charWrite   : character to be written to Tx buffer
//
//  Return: TRUE if space available in Tx Buffer and character was written, else FALSE.
static uint32_t UART_v2_putInstCharTxBuffNonBlock(UART_SWIPAttrs const *swipAttrs, uint16_t charWrite)
{
    //uint32_t regVal;
    uint8_t *ptr;
    uint8_t txRdPtr, txWrPtr, tempTxWrPtr;
    //uint16_t *txBuff;
    uint32_t retVal;

    // get Tx buffer write pointer
    // get Tx buffer read pointer
    //regVal = HW_RD_REG32(swipAttrs->baseAddr + UART_RD_WR_PTRS_OFFSET);    
    //txRdPtr = (uint8_t)((regVal & UART_RD_WR_PTRS__TX_BUFF_RD_IDX_MASK)>>UART_RD_WR_PTRS__TX_BUFF_RD_IDX_SHIFT);
    //txWrPtr = (uint8_t)((regVal & UART_RD_WR_PTRS__TX_BUFF_WR_IDX_MASK)>>UART_RD_WR_PTRS__TX_BUFF_WR_IDX_SHIFT);
    ptr = (uint8_t *)(swipAttrs->baseAddr + UART_RD_WR_PTRS_OFFSET);
    txRdPtr = *ptr;
    txWrPtr = *(ptr+1);
    
    tempTxWrPtr = (txWrPtr+sizeof(uint16_t))&(BUFF_SIZE-1);    // determine next write pointer location
    if (tempTxWrPtr != txRdPtr)
    {
        // next write pointer location is not at read pointer location =>
        // Tx Buffer not full
        
        // write character
        //txBuff = (uint16_t *)swipAttrs->txBuff;
        //txBuff[txWrPtr] = charWrite;
        *((uint16_t *)swipAttrs->txBuff + (txWrPtr>>1)) = charWrite;
        
        // update write pointer
        //txWrPtr = (txWrPtr+1)&(BUFF_SIZE-1);
        txWrPtr = tempTxWrPtr;
        
        //regVal &= ~(uint32_t)UART_RD_WR_PTRS__RX_BUFF_RD_IDX_MASK;
        //regVal |= (uint32_t)txWrPtr << UART_RD_WR_PTRS__RX_BUFF_RD_IDX_SHIFT;
        //HW_WR_REG32(swipAttrs->baseAddr + UART_RD_WR_PTRS_OFFSET, regVal);
        *(ptr+1) = txWrPtr;
        
        retVal = TRUE;  // char written
    }
    else
    {
        // next write pointer location is at read pointer location =>
        // Tx Buffer full
        
        retVal = FALSE; // char not written
    }
    
    return retVal;
}

// Perform blocking write of 16-bit character into Tx Buffer
static void UART_v2_putInstCharTxBuffBlock(UART_SWIPAttrs const *swipAttrs, uint16_t charWrite)
{
    volatile uint8_t *ptr;
    volatile uint8_t txRdPtr;
    uint8_t txWrPtr, tempTxWrPtr;
    
    // get Tx buffer write pointer
    // get Tx buffer read pointer
    ptr = (uint8_t *)(swipAttrs->baseAddr + UART_RD_WR_PTRS_OFFSET);
    txRdPtr = *ptr;
    txWrPtr = *(ptr+1);
    
    tempTxWrPtr = (txWrPtr+sizeof(uint16_t))&(BUFF_SIZE-1);    // determine next write pointer location
    while (tempTxWrPtr == txRdPtr)
    {
        txRdPtr = *ptr;
    }
    
    // write character
    *((uint16_t *)swipAttrs->txBuff + (txWrPtr>>1)) = charWrite;
    
    // update write pointer
    txWrPtr = tempTxWrPtr;
    *(ptr+1) = txWrPtr;
    
    return;
}

// Check Tx Buffer full status
static uint32_t UART_v2_getInstTxBuffFullStatus(uint32_t baseAddr)
{
    uint8_t *ptr;
    uint8_t txRdPtr, txWrPtr, tempTxWrPtr;
    uint32_t retVal;

    // get Tx buffer write pointer
    // get Tx buffer read pointer
    ptr = (uint8_t *)(baseAddr + UART_RD_WR_PTRS_OFFSET);
    txRdPtr = *ptr;
    txWrPtr = *(ptr+1);

    tempTxWrPtr = (txWrPtr+sizeof(uint16_t))&(BUFF_SIZE-1);    // determine next write pointer location
    retVal = (tempTxWrPtr == txRdPtr) ? TRUE : FALSE;
    
    return retVal;
}

// Check Tx Buffer empty status
static uint32_t UART_v2_getInstTxBuffEmptyStatus(uint32_t baseAddr)
{
    uint8_t *ptr;
    uint8_t txRdPtr, txWrPtr;
    uint32_t retVal;

    // get Tx buffer write pointer
    // get Tx buffer read pointer
    ptr = (uint8_t *)(baseAddr + UART_RD_WR_PTRS_OFFSET);
    txRdPtr = *ptr;
    txWrPtr = *(ptr+1);

    retVal = (txWrPtr == txRdPtr) ? TRUE : FALSE;
    
    return retVal;
}


// Perform non-blocking read of 16-bit character from Rx Buffer
static uint32_t UART_v2_getInstCharRxBuffNonBlock(UART_SWIPAttrs const *swipAttrs, uint16_t *pCharRead)
{
    uint8_t *ptr;
    uint8_t rxRdPtr, rxWrPtr;
    uint32_t retVal;

    // get Rx buffer write pointer
    // get Rx buffer read pointer
    ptr = (uint8_t *)(swipAttrs->baseAddr + UART_RD_WR_PTRS_OFFSET + RX_BUFF_RD_IDX_BYTEN);
    rxRdPtr = *ptr;
    rxWrPtr = *(ptr+1);
    
    if (rxRdPtr != rxWrPtr)
    {
        // write pointer location is not at read pointer location =>
        // Rx Buffer not empty
        
        // read character
        *pCharRead = *((uint16_t *)swipAttrs->rxBuff + (rxRdPtr>>1));
        
        // update write pointer
        rxRdPtr = (rxRdPtr+sizeof(uint16_t))&(BUFF_SIZE-1);
        *ptr = rxRdPtr;
        
        retVal = TRUE;  // char read
    }
    else
    {
        // write pointer location is at read pointer location =>
        // Rx Buffer empty
        
        retVal = FALSE; // char not read
    }
    
    return retVal;
}

// UART v2 callback function
void UART_v2_callback(UART_Handle handle, bool readTrans)
{
    UART_V2_Object *object;

    OSAL_Assert(!(handle != NULL));
    
    object = (UART_V2_Object *)handle->object;   // get object
    
    // Call back to application
    //  invoke callback functions in CALLBACK mode
    //  post semaphore in BLOCKING mode
    if (readTrans == true)
    {
        if (object->params.readCallback2)
        {
            object->params.readCallback2(handle, object->readTrans);
        }
        else if (object->params.readCallback)
        {
            object->params.readCallback(handle, object->readBuf, object->readCount);
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
            object->params.writeCallback(handle, (void *)object->writeBuf, object->writeCount);
        }
        else
        {
            UART_osalPostLock(object->writeSem);
        }
    }
    
    return;
}

// Debug variables
uint32_t gDisableInstRxIntErrCnt=0; // Rx disable interrupt error count (expected 0)
uint32_t gDisableInstTxIntErrCnt=0; // Tx disable interrupt error count (expected 0)
uint32_t gTxDataSentFlagErrCnt=0;   // Tx data sent flag error count (expected 0)
uint32_t gRxIntCnt=0;               // Rx interrupt count
uint32_t gRxIntRdSzZCnt=0;          // Rx interrupt count, zero read size
uint32_t gRxIntRdSzNZCnt=0;         // Rx interrupt count, non-zero read size
uint32_t gTxIntCnt=0;               // Tx interrupt count
uint32_t gTxIntWrSzZCnt=0;          // Tx interrupt count, zero write size
uint32_t gTxIntWrSzNZCnt=0;         // Tx interrupt count, non-zero write size

/*
 *  ======== UART_v2_hwiIntFxn ========
 *  Hwi function that processes UART interrupts.
 *
 *  @param(arg)         The UART_Handle for this HWI.
 */
static void UART_v2_hwiIntFxn(uintptr_t arg)
{
    UART_Handle handle;
    UART_SWIPAttrs const *swipAttrs;
    UART_V2_Object *object;
    UART_ICSS_INSTANCE icssInstId;
    PRUSS_PruCores pruInstId;
    UART_PRU_funct_mode *pruFuncModePtr;
    PRUICSS_Handle pruIcssHandle;
    PRUICSS_HwAttrs const *pruIcssHwAttrs;
    uint32_t done;
    uint32_t intType;
    uint32_t rxIntMask, txIntMask;
    int32_t retVal;
    
    handle = (UART_Handle)arg;                              // get UART handle
    OSAL_Assert(!(handle != NULL));
    
    swipAttrs = (UART_SWIPAttrs const *)handle->hwAttrs;    // get pointer to SWIP attributes
    object = (UART_V2_Object *)handle->object;              // get pointer to object
    icssInstId = swipAttrs->icssInstId;                     // get ICSS instance ID
    pruInstId = swipAttrs->pruInstId;                       // get PRU instance ID
    
    // get PRU configuration mode
    pruFuncModePtr = (UART_PRU_funct_mode *)&gUartCurrentICSSMode[icssInstId].pruMode[pruInstId];
    
    pruIcssHandle = (PRUICSS_Handle)pruFuncModePtr->pruIcssHandle;      // get PRUICSS handle
    pruIcssHwAttrs = (PRUICSS_HwAttrs const *)pruIcssHandle->hwAttrs;   // get PRU ICSS HW attributes

    rxIntMask = (uint32_t)1 << swipAttrs->rxIcssIntcSysEvt;
    txIntMask = (uint32_t)1 << swipAttrs->txIcssIntcSysEvt;
    
    // loop until all interrupts processed
    done = FALSE;
    while (done == FALSE)
    {
        // read interrupt register
        intType = HW_RD_REG32(pruIcssHwAttrs->prussIntcRegBase + UART_ICSS_INTC_SECR0);

        if (intType & rxIntMask)
        {
            gRxIntCnt++;
            
            // process Rx character interrupt
            //
            
            // clear Rx interrupt
            intType &= ~rxIntMask;
            HW_WR_REG32(pruIcssHwAttrs->prussIntcRegBase + UART_ICSS_INTC_SECR0, rxIntMask);
            
            if (object->readSize != 0)
            {
                // more data to read
                
                // Attempt to read transaction->count chars from Rx Buffer.
                // Return from UART_readData_v2() indicates number of chars yet to read.
                object->readSize = UART_readData_v2(handle, object->readSize);
                if (object->readSize == 0)
                {
                    gRxIntRdSzZCnt++;
                    
                    //
                    // all requested chars read
                    //
                    
                    // disable Rx Character interrupt
                    retVal = UART_v2_disableInstRxInt(handle, RX_CHAR_INT);
                    if (retVal != 0) gDisableInstRxIntErrCnt++; // increment error counter
                    
                    // rewind object read buffer pointer, updated in call to UART_readData_v2()
                    object->readBuf = (uint16_t *)object->readBuf - object->readCount;
                    
                    if (object->readTrans != NULL)
                    {
                        // object contains pointer to read transaction
                        //  set read transaction count (inform caller of number of chars read)
                        object->readTrans->count = object->readCount; // return count of chars read
                    
                        // set transaction status
                        //  The UART FW produces two types of Line Status Error: Framing Error & Parity Error.
                        //  Currently only one type of Line Status error can be returned to the application,
                        //  so the errors are prioritized as follows:
                        //      Highest - Framing Error
                        //      Lowest  - Parity Error
                        //
                        if (object->lineStatusErr & RX_CHAR_FRAMING_ERR_MASK)
                        {
                            object->readTrans->status = UART_TRANSFER_STATUS_ERROR_FE;
                        }
                        else if (object->lineStatusErr & RX_CHAR_PARITY_ERR_MASK)
                        {
                            object->readTrans->status = UART_TRANSFER_STATUS_ERROR_PE;
                        }
                        else 
                        {
                            object->readTrans->status = UART_TRANSFER_STATUS_SUCCESS;
                        }
                        
                        // all characters read, execute callback function
                        //  CALLBACK mode: callback function executed
                        UART_v2_callback(handle, true);
                        // clear object read transaction
                        object->readTrans = NULL;
                    }
                }
                else
                {
                    // Continue reading
                    
                    gRxIntRdSzNZCnt++;
                }
            }
            
        }
        else if (intType & txIntMask)
        {
            gTxIntCnt++;
            
            // process Tx Buffer empty interrupt
            //
            
            // clear Tx interrupt
            intType &= ~txIntMask;
            HW_WR_REG32(pruIcssHwAttrs->prussIntcRegBase + UART_ICSS_INTC_SECR0, txIntMask);
            
            if (object->writeSize != 0)
            {
                gTxIntWrSzNZCnt++;
                
                //
                // more data to write
                //
                
                object->writeSize = UART_writeData_v2(handle, object->writeSize);
                if (object->writeSize == 0)
                {
                    // all requested chars written to Tx Buffer
                    
                    // Rewind object write buffer pointer so caller will see unmodified input parameter
                    object->writeBuf = (uint16_t *)object->writeBuf - object->writeCount;
                    
                    // Set Output parameters in transaction.
                    // Pointer to transaction in object points to transaction parameter provided to function.
                    if (object->writeTrans != NULL)
                    {
                        object->writeTrans->count = object->writeCount;             // return count of chars written
                        object->writeTrans->status = UART_TRANSFER_STATUS_SUCCESS;  // return status
                    }
                    
                    // set object write complete flag to true -- used to trigger callback
                    object->txDataSent = TRUE;
                }
            }
            else
            {
                gTxIntWrSzZCnt++;
                
                //
                // all data written to Tx Buffer
                //
                
                if (object->txDataSent == TRUE)
                {
                    // invoke callback
                    
                    // disable Tx Buffer empty interrupt
                    retVal = UART_v2_disableInstTxInt(handle, TX_BUFF_EMPTY_INT);
                    if (retVal != 0) gDisableInstTxIntErrCnt++; // increment error counter
                    
                    // invoke callback function
                    UART_v2_callback(handle, false);
                    // clear object write transaction
                    object->writeTrans = NULL;
                    
                    object->txDataSent = FALSE; // indicate callback invoked
                }
                else
                {
                    // This shouldn't occur.
                    // Callback should be invoked when all data written to Tx Buffer.
                    //
                    gTxDataSentFlagErrCnt++;
                }
            }
        }
        else
        {
            // no more interrupts to process
            //
            done = TRUE;
        }
    }
}
