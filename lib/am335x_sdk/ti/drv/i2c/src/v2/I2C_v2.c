/**
 *  \file   I2C_v2.c
 *
 *  \brief  PRU I2C FW specific I2C Driver APIs implementation.
 *
 *   This file contains the driver APIs for I2C FW controller.
 */

/*
 * Copyright (C) 2014-2017 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_v2.h>
#include <ti/drv/i2c/src/I2C_osal.h>
#include <ti/drv/i2c/src/I2C_drv_log.h>
#include <ti/csl/hw_types.h>

static ICSS_funct_mode CurrentICSSMode[MAX_ICSS_INSTANCE] = 
{
    {
        {
            {I2C_ICSS_NO_CONFIG, 0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}},
            {I2C_ICSS_NO_CONFIG, 0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}}
        }
    },
    {
        {
            {I2C_ICSS_NO_CONFIG, 0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}},
            {I2C_ICSS_NO_CONFIG, 0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}}
        }
    },
    {
        {
            {I2C_ICSS_NO_CONFIG, 0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}},
            {I2C_ICSS_NO_CONFIG, 0U, 0U, PRUICSS_MAX_PRU, NULL, NULL, {(uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL, (uintptr_t)NULL}}
        }
    }
};

/* I2C AM57x functions */
static void       I2C_close_v2(I2C_Handle handle);
static void       I2C_init_v2(I2C_Handle handle);
static            I2C_Handle I2C_open_v2(I2C_Handle handle, const I2C_Params *params);
static int16_t    I2C_transfer_v2(I2C_Handle handle, I2C_Transaction *transaction);
static int16_t    I2C_primeTransfer_v2(I2C_Handle handle, I2C_Transaction *transaction);
static int16_t    I2C_smbusTransfer_v2(I2C_Handle handle, I2C_Transaction *transaction);
static int16_t    I2C_loopbackTransfer_v2(I2C_Handle handle, I2C_Transaction *transaction);
static void       I2C_transfer_Callback_v2(I2C_Handle handle,
                                             I2C_Transaction *msg,
                                             int16_t transferStatus);
static int32_t    I2C_v2_control(I2C_Handle handle, uint32_t cmd, void *arg);

static int32_t    I2C_v2_pruIcssInit(I2C_Handle handle, const I2C_Params *params);
static int32_t    I2C_v2_setupPinMux(I2C_Handle handle);
static int32_t    I2C_v2_writePinNum(I2C_Handle handle);
static int32_t    I2C_v2_setupFifoSize(I2C_Handle handle);
static uint32_t   I2C_v2_pollIrqSts(I2C_Handle handle);
static int32_t    I2C_v2_setBusFrequency(I2C_Handle handle, I2C_ConfigMode busFrequency);
static int32_t    I2C_v2_recoverBus(I2C_Handle handle, uint32_t i2cDelay);

int32_t    I2C_v2_enableModule(I2C_Handle handle);
int32_t    I2C_v2_disableModule(I2C_Handle handle);
int32_t    I2C_v2_enableMasterMode(I2C_Handle handle);
int32_t    I2C_v2_enableSlaveMode(I2C_Handle handle);
int32_t    I2C_v2_7bitAddressMode(I2C_Handle handle);
int32_t    I2C_v2_10bitAddressMode(I2C_Handle handle);
int32_t    I2C_v2_enableStartBit(I2C_Handle handle);
int32_t    I2C_v2_disableStartBit(I2C_Handle handle);
int32_t    I2C_v2_enableStopBit(I2C_Handle handle);
int32_t    I2C_v2_disableStopBit(I2C_Handle handle);
int32_t    I2C_v2_sendCmd2PRU(I2C_Handle handle, uint32_t cmd);
uint32_t   I2C_v2_readResp2PRU(I2C_Handle handle);
int32_t    I2C_v2_clearResp2PRU(I2C_Handle handle);
int32_t    I2C_v2_setSlaveAddress(I2C_Handle handle, uint32_t address);
int32_t    I2C_v2_putSmbusCmdCode(I2C_Handle handle, uint8_t cmdCode);
int32_t    I2C_v2_setDataCount(I2C_Handle handle, uint32_t count);
int32_t    I2C_v2_getDataCount(I2C_Handle handle, uint32_t* count);
int32_t    I2C_v2_putData(I2C_Handle handle, uint8_t* dataPtr, uint32_t dataCount);
int32_t    I2C_v2_getData(I2C_Handle handle, uint8_t* dataPtr, uint32_t dataCount);
int32_t    I2C_v2_waitForCompletion(I2C_Handle handle, uint32_t timeout);
int32_t    I2C_v2_sendNack(I2C_Handle handle);
int32_t    I2C_v2_sendAck(I2C_Handle handle);
int32_t    I2C_v2_enableBurstMode(I2C_Handle handle);
int32_t    I2C_v2_disableBurstMode(I2C_Handle handle);
int32_t    I2C_v2_writeInstId(I2C_Handle handle);
void       I2C_v2_pruGPIOMuxConfig(I2C_PRU_IOPinMuxAttrs *handle, uint32_t pinMode);


#define I2C_DELAY_MED     ((uint32_t) 10000U)
#define I2C_DELAY_BIG     ((uint32_t) 20000U)
#define I2C_DELAY_SMALL   ((uint32_t) 5000U)

/* I2C function table for I2C AM57x implementation */
const I2C_FxnTable I2C_v2_FxnTable = {
    &I2C_close_v2,
    &I2C_v2_control,
    &I2C_init_v2,
    &I2C_open_v2,
    &I2C_transfer_v2
};

/*
 *  ======== I2C_init_v2 ========
 */
static void I2C_init_v2(I2C_Handle handle)
{
    int32_t               i = 0;
    int32_t               j = 0;
    SemaphoreP_Params     semParams;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Mark the object as available */
        ((I2C_v2_Object *)(handle->object))->isOpen = (bool)false;

        /*
         * Construct thread safe handles for this I2C peripheral
         * Semaphore to provide exclusive access to the I2C peripheral
         */
        I2C_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;

        for(i = 0 ; i < 3 ; i++)
        {
            for(j = 0 ; j < 2 ; j++)
            {
                CurrentICSSMode[i].pruMode[j].pruInstLock = I2C_osalCreateBlockingLock(1U, &semParams);
            }
        }
    }
    return;
}

/*
 *  ======== I2C_v2_hwiFxn ========
 *  Hwi interrupt handler to service the I2C peripheral
 *
 *  The handler is a generic handler for a I2C object.
 */
static void I2C_v2_hwiFxn(uintptr_t arg);   /* for misra warnings*/
static void I2C_v2_hwiFxn(uintptr_t arg)
{
    PRU_funct_mode*          pruFuncPtr     = (PRU_funct_mode*)arg;
    I2C_Handle               handle         = NULL;
    I2C_v2_Object           *object         = NULL;
    uint32_t                 irqCommonSts   = 0;
    uint32_t                 irqMaskVal     = 0x80000000U;
    int32_t                  irqId          = 0;
    uint32_t                 cmdResponse    = 0;
    uint32_t                 localStatusErr = 0;
    
    /* Input parameter validation */
    if((void *)pruFuncPtr != NULL)
    {
        /* read the register which indicate the irq status of all instances */
        irqCommonSts = HW_RD_REG32(pruFuncPtr->pruConfigAddr + IRQ_COMMON_REGISTER_OFFSET);

        for(irqId = 3; irqId >=0; irqId--)
        {
            irqMaskVal = ((uint32_t)0x00000001 << irqId);
            if(irqCommonSts & irqMaskVal)
            {
                handle = (I2C_Handle)(pruFuncPtr->handlePtr[irqId]);

                /* Input parameter validation */
                if((void *)handle != NULL)
                {
                    /* Get the pointer to the object */
                    object = (I2C_v2_Object*)handle->object;
                    
                    cmdResponse = I2C_v2_readResp2PRU(handle);
                    if(((cmdResponse & ((uint32_t)0xFFFF0000U)) == 0) && ((cmdResponse & ((uint32_t)0x0000FFFFU)) != 0))
                    {
                        localStatusErr = (cmdResponse & ((uint32_t)0x0000FFFFU));
                        I2C_v2_clearResp2PRU(handle);
                        HW_WR_REG32(pruFuncPtr->pruConfigAddr + IRQ_COMMON_REGISTER_OFFSET, irqCommonSts & ~irqMaskVal);
                        if(TIME_OUT_ERROR != object->intStatusErr)
                        {
                            object->intStatusErr = localStatusErr;
                            if (I2C_OPER_MODE_BLOCKING == object->operMode)
                            {
                                /* Release the lock for this particular I2C command */
                                object->i2cParams.transferCallbackFxn(handle, object->currentTransaction, I2C_STS_SUCCESS);
                            }
                            else if (I2C_OPER_MODE_CALLBACK == object->operMode)
                            {
                                switch(object->currentCmd)
                                {
                                    case ICSS_I2C_RESET_CMD:
                                    case ICSS_I2C_SETUP_CMD:
                                    case ICSS_I2C_READ_SCL_CMD:
                                    case ICSS_I2C_RESET_SLAVE_CMD:
                                        /* Release the lock for this particular I2C command */
                                        I2C_transfer_Callback_v2(handle, object->currentTransaction, I2C_STS_SUCCESS);
                                        break;
                                    case ICSS_I2C_RX_CMD:
                                    case ICSS_I2C_TX_CMD:
                                    case ICSS_I2C_LOOPBACK_CMD:
                                    case ICSS_SMBUS_QUICK_CMD:
                                    case ICSS_SMBUS_SEND_BYTE_CMD:
                                    case ICSS_SMBUS_RECEIVE_BYTE_CMD:
                                    case ICSS_SMBUS_WRITE_BYTE_CMD:
                                    case ICSS_SMBUS_READ_BYTE_CMD:
                                    case ICSS_SMBUS_WRITE_WORD_CMD:
                                    case ICSS_SMBUS_READ_WORD_CMD:
                                    case ICSS_SMBUS_BLOCK_WRITE_CMD:
                                    case ICSS_SMBUS_BLOCK_READ_CMD:
                                        /* Callback to application or post semaphore */
                                        object->i2cParams.transferCallbackFxn(handle, object->currentTransaction, I2C_STS_SUCCESS);
                                        break;
                                    default:
                                        /*unknown command*/
                                        break;
                                }
                            }
                            else
                            {
                                /* nothing to be done here */
                            }
                        }
                    }
                }
            }
        }

        /*clear PRU-ICSS INTC interrupt*/
        if(PRUICCSS_PRU0 == pruFuncPtr->pruInstance)
        {
            HW_WR_REG32(((PRUICSS_HwAttrs const*)((PRUICSS_Handle)pruFuncPtr->pruIcssHandle)->hwAttrs)->prussIntcRegBase + I2C_ICSS_INTC_SECR0, ICSS_I2C_INTC_PRU0_BIT_VAL);
        }
        else if(PRUICCSS_PRU1 == pruFuncPtr->pruInstance)
        {
            HW_WR_REG32(((PRUICSS_HwAttrs const*)((PRUICSS_Handle)pruFuncPtr->pruIcssHandle)->hwAttrs)->prussIntcRegBase + I2C_ICSS_INTC_SECR0, ICSS_I2C_INTC_PRU1_BIT_VAL);
        }
        else
        {
            /* nothing to be done here */
        }
    }
    return;
}

/*
 *  ======== I2C_open_v2 ========
 */
static I2C_Handle I2C_open_v2(I2C_Handle handle, const I2C_Params *params)
{
    SemaphoreP_Params     semParams;
    I2C_v2_Object        *object = NULL;
    I2C_SwIPAttrs const  *swipAttrs = NULL;
    uint32_t              key;
    int32_t               ret_flag = 0;
    I2C_ICSS_INSTANCE     ICSSInst = I2C_ICSS_INSTANCE_NONE;
    PRUSS_PruCores        PRUInst;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        object = (I2C_v2_Object*)handle->object;
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;
        ICSSInst = swipAttrs->icssInstance;
        PRUInst = swipAttrs->pruInstance;
        if ((ICSSInst > I2C_ICSS_INSTANCE2) || (PRUInst > PRUICCSS_PRU1))
        {
            ret_flag = 1;
        }

        /* Determine if the device index was already opened */
        key = I2C_osalHardwareIntDisable();
        if(object->isOpen == true) {
            I2C_osalHardwareIntRestore(key);
            handle = NULL;
        }
        else
        {
            /* Mark the handle as being used */
            object->isOpen = (bool)true;
            object->intStatusErr = 0U;
            (object->transactionCmd).transferCmd = STANDARD_I2C_CMD;
            (object->transactionCmd).cmdCode = (uint8_t)0U;
            I2C_osalHardwareIntRestore(key);


            if (ret_flag == 0)
            {
                I2C_osalPendLock(CurrentICSSMode[ICSSInst].pruMode[0].pruInstLock, SemaphoreP_WAIT_FOREVER);
                I2C_osalPendLock(CurrentICSSMode[ICSSInst].pruMode[1].pruInstLock, SemaphoreP_WAIT_FOREVER);
                 
                switch(params->bitRate)
                {
                    case I2C_1P0Mhz:
                        if((CurrentICSSMode[ICSSInst].pruMode[0].pruConfig != I2C_ICSS_NO_CONFIG) ||
                            (CurrentICSSMode[ICSSInst].pruMode[1].pruConfig != I2C_ICSS_NO_CONFIG))
                        {
                            ret_flag = 1;
                        }
                        else
                        {
                            object->configMode = I2C_ICSS_1MHZ_MODE;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfig = I2C_ICSS_1MHZ_MODE;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstance = PRUInst;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].instanceCnt++;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfigAddr = ((I2C_SwIPAttrs const *)handle->hwAttrs)->configAddr;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].handlePtr[((I2C_SwIPAttrs const *)handle->hwAttrs)->i2cInstId] = (uintptr_t)handle;
                        }
                        break;
                    case I2C_400kHz:
                        if((CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfig != I2C_ICSS_NO_CONFIG) ||
                            (CurrentICSSMode[ICSSInst].pruMode[1 - PRUInst].pruConfig == I2C_ICSS_1MHZ_MODE))
                        {
                            ret_flag = 1;
                        }
                        else
                        {
                            object->configMode = I2C_ICSS_400KHZ_MODE;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfig = I2C_ICSS_400KHZ_MODE;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstance = PRUInst;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].instanceCnt++;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfigAddr = ((I2C_SwIPAttrs const *)handle->hwAttrs)->configAddr;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].handlePtr[((I2C_SwIPAttrs const *)handle->hwAttrs)->i2cInstId] = (uintptr_t)handle;
                        }
                        break;
                    case I2C_100kHz:
                        if(((CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfig == I2C_ICSS_100KHZ_MODE) || 
                            (CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfig == I2C_ICSS_NO_CONFIG)) && 
                            (CurrentICSSMode[ICSSInst].pruMode[1 - PRUInst].pruConfig != I2C_ICSS_1MHZ_MODE))
                        {
                            object->configMode = I2C_ICSS_100KHZ_MODE;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfig = I2C_ICSS_100KHZ_MODE;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstance = PRUInst;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].instanceCnt++;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfigAddr = ((I2C_SwIPAttrs const *)handle->hwAttrs)->configAddr;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].handlePtr[((I2C_SwIPAttrs const *)handle->hwAttrs)->i2cInstId] = (uintptr_t)handle;
                        }
                        else
                        {
                            ret_flag = 1;
                        }
                        break;
                    default:
                        ret_flag = 1;
                        break;
                }

                I2C_osalPostLock(CurrentICSSMode[ICSSInst].pruMode[1].pruInstLock);
                I2C_osalPostLock(CurrentICSSMode[ICSSInst].pruMode[0].pruInstLock);
            }

            if(ret_flag == 0)
            {
                /* Store the I2C parameters */
                if (params == NULL) {
                    /* No params passed in, so use the defaults */
                    I2C_Params_init(&(object->i2cParams));
                }
                else {
                    /* Copy the params contents */
                    object->i2cParams = *params;
                }

                /* extract operational mode from i2cparams and hardware attributes */
                if(I2C_MODE_BLOCKING == object->i2cParams.transferMode)
                {
                    if(true == swipAttrs->enableIntr)
                    {
                        object->operMode = I2C_OPER_MODE_BLOCKING;
                    }
                    else
                    {
                        object->operMode = I2C_OPER_MODE_POLLING;
                    }
                }
                else
                {
                    object->operMode = I2C_OPER_MODE_CALLBACK;
                }
            }

            if((I2C_OPER_MODE_POLLING != object->operMode) && (ret_flag == 0) && (ICSSInst <= I2C_ICSS_INSTANCE2))
            {
                I2C_osalPendLock(CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstLock, SemaphoreP_WAIT_FOREVER);
                if(CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruIcssHandle == NULL)
                {
                    OsalRegisterIntrParams_t interruptRegParams;
                    /* Initialize with defaults */
                    Osal_RegisterInterrupt_initParams(&interruptRegParams);
                    
                    /* Populate the interrupt parameters */
                    interruptRegParams.corepacConfig.arg=(uintptr_t)(&(CurrentICSSMode[ICSSInst].pruMode[PRUInst]));
                    interruptRegParams.corepacConfig.name=NULL;
                    interruptRegParams.corepacConfig.isrRoutine=&I2C_v2_hwiFxn;
                    interruptRegParams.corepacConfig.corepacEventNum=swipAttrs->eventId; /* Event going in to CPU */
                    interruptRegParams.corepacConfig.intVecNum=swipAttrs->intNum; /* Host Interrupt vector */
                    
                    /* Register interrupts */
                    I2C_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));
                    if(object->hwi == NULL) {
                        I2C_drv_log("\n Error constructing I2C HWI object \n");
                        ret_flag = 1;
                    }
                    if(ret_flag == 0)
                    {
    #if defined(SOC_AM571X) || defined(SOC_AM572x) || defined(SOC_AM574x)
                        CSL_xbarIrqConfigure(swipAttrs->cpuId, swipAttrs->HostXbarNumber, swipAttrs->PRUXbarNumber);
    #endif
                    }
                }
                I2C_osalPostLock(CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstLock);
            }

            if(ret_flag == 0)
            {
                /*
                 * Construct thread safe handles for this I2C peripheral
                 * Semaphore to provide exclusive access to the I2C peripheral
                 */
                I2C_osalSemParamsInit(&semParams);
                semParams.mode = SemaphoreP_Mode_BINARY;
                object->mutex = I2C_osalCreateBlockingLock(1U, &semParams);

                /*
                 * Store a callback function that posts the transfer complete
                 * semaphore for synchronous mode
                 */
                if (object->operMode == I2C_OPER_MODE_BLOCKING) 
                {
                   /*
                    * Construct thread safe handle for recieving command ACK
                    * Semaphore to provide synchronized access to command response
                    */
                   object->cmdAckSem = I2C_osalCreateBlockingLock(0U, &semParams);
                
                   /* Store internal callback function */
                   object->i2cParams.transferCallbackFxn = &I2C_transfer_Callback_v2;
                }
                if(object->operMode == I2C_OPER_MODE_CALLBACK)
                {
                   /* Check to see if a callback function was defined for async mode */
                   if(object->i2cParams.transferCallbackFxn != NULL)
                   {
                       if (params != NULL) 
                       {
                          /* Save the callback function pointer */
                          object->i2cParams.transferCallbackFxn = params->transferCallbackFxn;
                       }
                   }
                }

                /* Specify the idle state for this I2C peripheral */
                object->mode = I2C_IDLE_MODE;

                /* Clear the head pointer */
                object->headPtr = NULL;
                object->tailPtr = NULL;

                I2C_drv_log1("\n I2C: Object created 0x%x \n", swipAttrs->baseAddr);
            }
            
            if((ret_flag == 0) && (ICSSInst <= I2C_ICSS_INSTANCE2))
            {
                I2C_osalPendLock(CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstLock, SemaphoreP_WAIT_FOREVER);
                if(CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruIcssHandle == NULL)
                {
                    ret_flag = I2C_v2_pruIcssInit(handle, params);
                }
                I2C_osalPostLock(CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstLock);
            }

            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_setupPinMux(handle);
                ret_flag = I2C_v2_writePinNum(handle);
                ret_flag = I2C_v2_setupFifoSize(handle);
                ret_flag = I2C_v2_enableMasterMode(handle);
                ret_flag = I2C_v2_7bitAddressMode(handle);
                ret_flag = I2C_v2_writeInstId(handle);
                ret_flag = I2C_v2_enableStartBit(handle);
                ret_flag = I2C_v2_enableStopBit(handle);
                ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
            }
            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_enableModule(handle);
            }
            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
            }
            if(ret_flag == 1)
            {
                I2C_close_v2(handle);
                handle = NULL;   /*to solve the MISRA.RETURN.NOT_LAST warning*/
            }
        }
    }
    return (handle);
}

/*
 *  ======== I2C_v2_setupFifoSize ========
 */
static int32_t I2C_v2_setupFifoSize(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    I2C_TrigLvl              fifoSize;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal = 0;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        /* read the Rx Fifo size */
        fifoSize = swipAttrs->rxFifoSize;
        regVal |= (((uint32_t)fifoSize) << 8);

        /* read the Tx Fifo size */
        fifoSize = swipAttrs->txFifoSize;
        regVal |= ((uint32_t)fifoSize);

        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_BUF_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 *  ======== I2C_v2_writePinNum ========
 */
static int32_t I2C_v2_writePinNum(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    I2C_PRU_IOPinMuxAttrs    pinReg;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal = 0;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        /* Set the SCL pin mux register value for GPO */
        pinReg = swipAttrs->sclOutputPin;
        regVal |= ((uint32_t)(pinReg.pinNum));

        /* Set the SDA pin mux register value for GPO */
        pinReg = swipAttrs->sdaOutputPin;
        regVal |= (((uint32_t)(pinReg.pinNum)) << 16);

        /* Set the SDA pin mux register value for GPI */
        pinReg = swipAttrs->sdaInputPin;
        regVal |= (((uint32_t)(pinReg.pinNum)) << 8);
        
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_PRU_PIN_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 *  ======== I2C_v2_setupPinMux ========
 */
static int32_t I2C_v2_setupPinMux(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    I2C_PRU_IOPinMuxAttrs    pinReg;
    int32_t                  retVal = 0;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        /* Set the SCL pin mux register value for GPO */
        pinReg = swipAttrs->sclOutputPin;
        I2C_v2_pruGPIOMuxConfig(&pinReg, I2C_PRU_PINMUX_GPO_MODE);

        /* Set the SDA pin mux register value for GPO */
        pinReg = swipAttrs->sdaOutputPin;
        I2C_v2_pruGPIOMuxConfig(&pinReg, I2C_PRU_PINMUX_GPO_MODE);

        /* Set the SDA pin mux register value for GPI */
        pinReg = swipAttrs->sdaInputPin;
        I2C_v2_pruGPIOMuxConfig(&pinReg, I2C_PRU_PINMUX_GPI_MODE);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 *  ======== I2C_v2_pruIcssInit ========
 */
static int32_t I2C_v2_pruIcssInit(I2C_Handle handle, const I2C_Params *params)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    I2C_ICSS_INSTANCE        ICSSInst = I2C_ICSS_INSTANCE_NONE;
    PRUSS_PruCores           PRUInst;
    PRUICSS_Config          *pruIcssCfg;
    PRUICSS_HwAttrs const   *hwAttrs;
    PRUICSS_Handle           pruIcssHandle;
    int32_t                  retVal = I2C_STATUS_ERROR;
    uint32_t                 icssRevIdMajor = 0U;
    uint32_t                 icssRevIdMinor = 0U;
    uint32_t                 iepCmpIncVal = 0U;
    uint32_t                 iepCmpIncValHalf = 0U;
#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_AM572x)
    uint32_t                 iepCounter32 = 0U;
#endif
#if defined(SOC_K2G) || defined(SOC_AM571x) || defined(SOC_AM572x) || defined(SOC_AM574x)
    uint64_t                 iepCounter64 = 0U;
#endif
    uint32_t                 tempAddr = 0U;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;
        ICSSInst = swipAttrs->icssInstance;
        PRUInst = swipAttrs->pruInstance;

        retVal  = PRUICSS_socGetInitCfg(&pruIcssCfg);
        if ((retVal != PRUICSS_RETURN_SUCCESS) ||
            (ICSSInst > I2C_ICSS_INSTANCE2)    ||
            (PRUInst > PRUICCSS_PRU1))
        {
            retVal = I2C_STATUS_ERROR;
        }
        else
        {
            pruIcssHandle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg, ICSSInst);
            if (pruIcssHandle == NULL)
            {
                retVal = I2C_STATUS_ERROR;
            }
            else
            {
                retVal = I2C_STATUS_SUCCESS;
                CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruIcssHandle = pruIcssHandle;
                hwAttrs = (PRUICSS_HwAttrs const *)pruIcssHandle->hwAttrs;

                PRUICSS_pinMuxConfig(pruIcssHandle, 0x0); /* PRUSS pinmuxing */
                /*Disable PRUs - This is to ensure PRUs are not running when application is not initialized */
                PRUICSS_pruDisable(pruIcssHandle, PRUInst);
                PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
                PRUICSS_pruIntcInit(pruIcssHandle, &pruss_intc_initdata);

                PRUICSS_pruReset(pruIcssHandle, PRUInst);

                PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_DATARAM(PRUInst));
                PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_IRAM(PRUInst));
                
                if(PRUICCSS_PRU0 == PRUInst)
                {
                    PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_DATARAM(PRUInst),0,
                                          ((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->dram0MemBufferStart,
                                          (uint32_t)((uint8_t*)(((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->dram0MemBufferEnd)) - (uint32_t)((uint8_t*)(((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->dram0MemBufferStart)));

                    PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(PRUInst),0,
                                          ((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->iram0MemBufferStart,
                                          (uint32_t)((uint8_t*)(((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->iram0MemBufferEnd)) - (uint32_t)((uint8_t*)(((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->iram0MemBufferStart)));
                }
                else if(PRUICCSS_PRU1 == PRUInst)
                {
                    PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_DATARAM(PRUInst),0,
                                          ((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->dram1MemBufferStart,
                                          (uint32_t)((uint8_t*)(((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->dram1MemBufferEnd)) - (uint32_t)((uint8_t*)(((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->dram1MemBufferStart)));

                    PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_IRAM(PRUInst),0,
                                          ((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->iram1MemBufferStart,
                                          (uint32_t)((uint8_t*)(((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->iram1MemBufferEnd)) - (uint32_t)((uint8_t*)(((ICSS_Mem_Ptr*)(swipAttrs->icssMemBuffer))->iram1MemBufferStart)));
                }
                else
                {
                    retVal = I2C_STATUS_ERROR;
                }

                icssRevIdMajor = (PRUICSS_getICSSVersion(pruIcssHandle) & ((uint32_t)PRU_ICSS_REVISION_MAJOR_MASK)) >> 8;
                icssRevIdMinor = PRUICSS_getICSSVersion(pruIcssHandle) & ((uint32_t)PRU_ICSS_REVISION_MINOR_MASK);

                switch(CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfig)
                {
                    case I2C_ICSS_100KHZ_MODE:
                        iepCmpIncVal = IEP_CMP_INCREMENT_VAL_100KHZ;
                        iepCmpIncValHalf = IEP_CMP_INCREMENT_HALF_VAL_100KHZ;
                        break;
                    case I2C_ICSS_400KHZ_MODE:
                        iepCmpIncVal = IEP_CMP_INCREMENT_VAL_400KHZ;
                        iepCmpIncValHalf = IEP_CMP_INCREMENT_HALF_VAL_400KHZ;
                        break;
                    case I2C_ICSS_1MHZ_MODE:
                        iepCmpIncVal = IEP_CMP_INCREMENT_VAL_1MHZ;
                        iepCmpIncValHalf = IEP_CMP_INCREMENT_HALF_VAL_1MHZ;
                        break;
                    default:
                        iepCmpIncVal = 1U;
                        iepCmpIncValHalf = 1U;
                        break;
                }

                if((icssRevIdMajor <= 0x2U) && (icssRevIdMinor < 0x1U))
                {
#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_AM572x)
                    /*    32-bit IEP Timer for ICSS v2.0 and below
                     *     Reading IEP Counter Value
                     */
                    tempAddr = hwAttrs->prussIepRegBase + ((uint32_t)CSL_ICSSM_IEP_COUNT);
                    iepCounter32 = *(uint32_t*)(tempAddr);
                    iepCounter32 /= iepCmpIncVal;
                    iepCounter32 += 15U;
                    iepCounter32 *= iepCmpIncVal;
                    if(PRUICCSS_PRU1 == PRUInst)
                    {
                        iepCounter32 += iepCmpIncValHalf;
                    }
                    *(uint32_t*)(swipAttrs->configAddr) = iepCounter32;
#endif
                }
                else
                {
#if defined(SOC_K2G) || defined(SOC_AM571x) || defined(SOC_AM572x) || defined(SOC_AM574x)
                    /*    64-bit IEP Timer for ICSS v2.1 and above
                     *    Reading IEP Counter Value
                     */
                    tempAddr = hwAttrs->prussIepRegBase + ((uint32_t)CSL_ICSSIEP_COUNT_REG0);
                    iepCounter64 = *(uint64_t*)(tempAddr);
                    iepCounter64 /= iepCmpIncVal;
                    iepCounter64 += 15U;
                    iepCounter64 *= iepCmpIncVal;
                    if(PRUICCSS_PRU1 == PRUInst)
                    {
                        iepCounter64 += iepCmpIncValHalf;
                    }
                    *(uint64_t*)(swipAttrs->configAddr) = iepCounter64;
#endif
                }

                retVal = I2C_v2_setBusFrequency(handle, CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfig);

                PRUICSS_pruEnable(pruIcssHandle, PRUInst);
            }
        }
    }

    return retVal;
}

/*
 *  ======== I2C_close_v2 ========
 */
static void I2C_close_v2(I2C_Handle handle)
{
    I2C_v2_Object               *object        = NULL;
    I2C_SwIPAttrs const         *swipAttrs     = NULL;
    I2C_ICSS_INSTANCE            ICSSInst      = I2C_ICSS_INSTANCE_NONE;
    PRUSS_PruCores               PRUInst;
    PRUICSS_Handle               pruIcssHandle = NULL;
    PRUICSS_HwAttrs const       *pruHwAttrs;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;
        object = (I2C_v2_Object*)handle->object;
        ICSSInst = swipAttrs->icssInstance;
        PRUInst = swipAttrs->pruInstance;

        if ((ICSSInst <= I2C_ICSS_INSTANCE2) && (PRUInst <= PRUICCSS_PRU1))
        {
            pruIcssHandle = CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruIcssHandle;
            
            /* Check to see if a I2C transaction is in progress */
            if(object->headPtr == NULL)
            {
                I2C_osalPendLock(CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstLock, SemaphoreP_WAIT_FOREVER);
                
                switch(object->configMode)
                {
                    case I2C_ICSS_1MHZ_MODE:
                    case I2C_ICSS_400KHZ_MODE:
                    case I2C_ICSS_100KHZ_MODE:
                        CurrentICSSMode[ICSSInst].pruMode[PRUInst].instanceCnt--;
                        object->configMode = I2C_ICSS_NO_CONFIG;
                        CurrentICSSMode[ICSSInst].pruMode[PRUInst].handlePtr[((I2C_SwIPAttrs const *)handle->hwAttrs)->i2cInstId] = (uintptr_t)NULL;
                        if(CurrentICSSMode[ICSSInst].pruMode[PRUInst].instanceCnt == 0)
                        {
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfig = I2C_ICSS_NO_CONFIG;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstance = PRUICSS_MAX_PRU;
                            CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruConfigAddr = 0x00000000;
                            if(pruIcssHandle != NULL)
                            {
                                PRUICSS_pruDisable(pruIcssHandle, PRUInst);
                                PRUICSS_pruReset(pruIcssHandle, PRUInst);
                                /* disable PRU IEP timer */
                                pruHwAttrs = (PRUICSS_HwAttrs const *)pruIcssHandle->hwAttrs;
                                HW_WR_REG32(pruHwAttrs->prussIepRegBase, (0xFFFFFFFEU & HW_RD_REG32(pruHwAttrs->prussIepRegBase)));
                                PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_DATARAM(PRUInst));
                                PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_IRAM(PRUInst));
                                CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruIcssHandle = NULL;
                            }
                        }
                        break;
                    default:
                        break;
                }
                
                I2C_osalPostLock(CurrentICSSMode[ICSSInst].pruMode[PRUInst].pruInstLock);

                if (I2C_OPER_MODE_POLLING != object->operMode)
                {
                    /* Destruct the Hwi */
                    I2C_osalHardwareIntDestruct(object->hwi,swipAttrs->eventId);
                }

                /* Destruct the instance lock */
                I2C_osalDeleteBlockingLock(object->mutex);

                if (I2C_OPER_MODE_BLOCKING == object->operMode)
                {
                    /* Destruct the transfer completion lock */
                    I2C_osalDeleteBlockingLock(object->cmdAckSem);        
                }

                object->isOpen = (bool)false;
                object->intStatusErr = 0U;
                I2C_drv_log1("\n I2C: Object closed 0x%x \n", swipAttrs->baseAddr);
            }
        }
    }
    return;
}

/*
 *  ======== I2C_primeTransfer_v2 =======
 */
static int16_t I2C_primeTransfer_v2(I2C_Handle handle,
                                 I2C_Transaction *transaction)
{
    I2C_v2_Object           *object = NULL;
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int16_t                  status = I2C_STS_SUCCESS;
    int32_t                  ret_flag = 0;
    uint32_t                 irqCommonSts = 0;
    
    /* Input parameter validation */
    if((handle != NULL) && (transaction != NULL))
    {
        /* Get the pointer to the object and swipAttrs */
        object = (I2C_v2_Object*)handle->object;
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        /* Store the new internal counters and pointers */
        object->currentTransaction = transaction;

        object->writeBufIdx = (uint8_t*)transaction->writeBuf;
        object->writeCountIdx = transaction->writeCount;

        object->readBufIdx = (uint8_t*)transaction->readBuf;
        object->readCountIdx = transaction->readCount;

        object->intStatusErr = 0;

        object->mode = I2C_IDLE_MODE;

        I2C_drv_log2("\n I2C:(0x%x) Starting transaction to slave: 0x%x \n",
            swipAttrs->baseAddr, object->currentTransaction->slaveAddress);

        /* clear all interrupts */
        irqCommonSts = HW_RD_REG32(swipAttrs->configAddr + IRQ_COMMON_REGISTER_OFFSET);
        HW_WR_REG32(swipAttrs->configAddr + IRQ_COMMON_REGISTER_OFFSET, irqCommonSts & (~((uint32_t)0x00000001 << swipAttrs->i2cInstId)));

        if (transaction->masterMode)
        {
            if (object->currentTransaction->expandSA == true)
            {
                /* enable the 10-bit address mode */
                ret_flag = I2C_v2_10bitAddressMode(handle);
            }
            else
            {
                /* enable the 7-bit address mode */
                ret_flag = I2C_v2_7bitAddressMode(handle);
            }
            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_sendAck(handle);
            }
            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_disableBurstMode(handle);
            }
            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
            }
            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
            }

            if(ret_flag == 0)
            {
                /* In master mode, set the I2C slave address */
                ret_flag = I2C_v2_setSlaveAddress(handle, object->currentTransaction->slaveAddress);
            }

            /* Start transfer in Transmit mode */
            if ((ret_flag == 0) && (object->writeCountIdx != 0U))
            {
                if ((object->readCountIdx) == 0U)
                {
                    ret_flag = I2C_v2_enableStopBit(handle);
                }
                else
                {
                    ret_flag = I2C_v2_disableStopBit(handle);
                }
                
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                }
                
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                }
                
                if(ret_flag == 0)
                {
                    /* Set number of bytes to be transmitting */
                    ret_flag = I2C_v2_setDataCount(handle, object->writeCountIdx);
                }

                /*
                 * Configure the I2C transfer to be in master transmitter mode
                 */
                if(ret_flag == 0)
                {
                    /* copy the data */
                    ret_flag = I2C_v2_putData(handle, object->writeBufIdx, object->writeCountIdx);
                }
                
                if(ret_flag == 0)
                {
                    /* Start the tx command */
                    ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_TX_CMD);
                }
                
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                }
                
                if(ret_flag == 0)
                {
                    I2C_drv_log1("\n I2C:(0x%x) I2C_IDLE_MODE: -> I2C_WRITE_MODE; Writing w/ START \n",
                        swipAttrs->baseAddr);
                }
            }
            if ((ret_flag == 0) && ((object->readCountIdx) != 0U))
            {
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_enableStopBit(handle);
                }
                
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                }
                
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                }
                
                if(ret_flag == 0)
                {
                    /* Specify the number of bytes to read */
                    ret_flag = I2C_v2_setDataCount(handle, object->readCountIdx);
                }
                
                /*
                 * Start the I2C transfer in master receive mode,
                 * and automatically send stop when done
                 */
                if(ret_flag == 0)
                {
                    /* Start the RX command */
                    ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_RX_CMD);
                }
                
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                }
                
                if(ret_flag == 0)
                {
                    /* copy the data */
                    ret_flag = I2C_v2_getData(handle, object->readBufIdx, object->readCountIdx);
                }

                if(ret_flag == 0)
                {
                    I2C_drv_log1("\n I2C:(0x%x) I2C_IDLE_MODE: -> I2C_READ_MODE; Reading w/ NACK \n",
                        swipAttrs->baseAddr);
                }
            }
        }
        /* In slave mode */
        else
        {
            status = I2C_STS_ERR_ACCESS_ERROR;
        }
    }
    else
    {
        status = I2C_STS_ERR;
    }

    return status;
}

/*
 *  ======== I2C_loopbackTransfer_v2 =======
 */
static int16_t I2C_loopbackTransfer_v2(I2C_Handle handle,
                                 I2C_Transaction *transaction)
{
    I2C_v2_Object           *object = NULL;
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int16_t                  status = I2C_STS_SUCCESS;
    int32_t                  ret_flag = 0;
    uint32_t                 irqCommonSts = 0;
    
    /* Input parameter validation */
    if((handle != NULL) && (transaction != NULL))
    {
        /* Get the pointer to the object and swipAttrs */
        object = (I2C_v2_Object*)handle->object;
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        /* Store the new internal counters and pointers */
        object->currentTransaction = transaction;

        object->writeBufIdx = (uint8_t*)transaction->writeBuf;
        object->writeCountIdx = transaction->writeCount;

        object->readBufIdx = (uint8_t*)transaction->readBuf;
        object->readCountIdx = transaction->readCount;

        object->intStatusErr = 0;

        object->mode = I2C_IDLE_MODE;

        /* clear all interrupts */
        irqCommonSts = HW_RD_REG32(swipAttrs->configAddr + IRQ_COMMON_REGISTER_OFFSET);
        HW_WR_REG32(swipAttrs->configAddr + IRQ_COMMON_REGISTER_OFFSET, irqCommonSts & (~((uint32_t)0x00000001 << swipAttrs->i2cInstId)));

        if (transaction->masterMode)
        {
            if(ret_flag == 0)
            {
                /* In master mode, set the I2C slave address */
                ret_flag = I2C_v2_setSlaveAddress(handle, object->currentTransaction->slaveAddress);
            }

            if(ret_flag == 0)
            {
                /* Set number of bytes to be transmitting */
                ret_flag = I2C_v2_setDataCount(handle, object->writeCountIdx);
            }

            /*
             * Configure the I2C transfer to be in master transmitter mode
             */
            if(ret_flag == 0)
            {
                /* copy the data */
                ret_flag = I2C_v2_putData(handle, object->writeBufIdx, object->writeCountIdx);
            }

            if(ret_flag == 0)
            {
                /* Start the tx command */
                ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_LOOPBACK_CMD);
            }

            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
            }

            if(ret_flag == 0)
            {
                /* copy the data */
                ret_flag = I2C_v2_getData(handle, object->readBufIdx, object->writeCountIdx);
            }
        }
        /* In slave mode */
        else
        {
            status = I2C_STS_ERR_ACCESS_ERROR;
        }
    }
    else
    {
        status = I2C_STS_ERR;
    }

    return status;
}

/*
 *  ======== I2C_smbusTransfer_v2 =======
 */
static int16_t I2C_smbusTransfer_v2(I2C_Handle handle,
                                 I2C_Transaction *transaction)
{
    I2C_v2_Object           *object = NULL;
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int16_t                  status = I2C_STS_SUCCESS;
    int32_t                  ret_flag = 0;
    uint32_t                 irqCommonSts = 0;
    
    /* Input parameter validation */
    if((handle != NULL) && (transaction != NULL))
    {
        /* Get the pointer to the object and swipAttrs */
        object = (I2C_v2_Object*)handle->object;
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        /* Store the new internal counters and pointers */
        object->currentTransaction = transaction;

        if(SMBUS_QUICK_CMD != (object->transactionCmd).transferCmd)
        {
            object->writeBufIdx = (uint8_t*)transaction->writeBuf;
            object->writeCountIdx = transaction->writeCount;

            object->readBufIdx = (uint8_t*)transaction->readBuf;
            object->readCountIdx = transaction->readCount;
        }
        object->intStatusErr = 0;

        object->mode = I2C_IDLE_MODE;

        I2C_drv_log2("\n I2C:(0x%x) Starting transaction to slave: 0x%x \n",
            swipAttrs->baseAddr, object->currentTransaction->slaveAddress);

        /* clear all interrupts */
        irqCommonSts = HW_RD_REG32(swipAttrs->configAddr + IRQ_COMMON_REGISTER_OFFSET);
        HW_WR_REG32(swipAttrs->configAddr + IRQ_COMMON_REGISTER_OFFSET, irqCommonSts & (~((uint32_t)0x00000001 << swipAttrs->i2cInstId)));

        if (transaction->masterMode)
        {
            if (object->currentTransaction->expandSA == true)
            {
                /* enable the 10-bit address mode */
                ret_flag = 1;
                status = I2C_STS_ERR_ACCESS_ERROR;
            }
            else
            {
                /* enable the 7-bit address mode */
                ret_flag = I2C_v2_7bitAddressMode(handle);
            }
            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_enableStopBit(handle);
            }
            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
            }
            if(ret_flag == 0)
            {
                ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
            }

            if(ret_flag == 0)
            {
                /* In master mode, set the I2C slave address */
                ret_flag = I2C_v2_setSlaveAddress(handle, object->currentTransaction->slaveAddress);
            }

            /* Start transfer in Transmit mode */
            if (ret_flag == 0)
            {
                switch((object->transactionCmd).transferCmd)
                {
                    case SMBUS_QUICK_CMD:
                         /*
                          * Configure the I2C transfer to be in smbus quick command mode
                          */
                         ret_flag = I2C_v2_sendAck(handle);
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_disableBurstMode(handle);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                         }
                         if(ret_flag == 0)
                         {
                             /* Start the tx command */
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_SMBUS_QUICK_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                         }
                         break;
                    case SMBUS_SEND_BYTE_CMD:
                         /*
                          * Configure the I2C transfer to be in smbus send byte mode
                          */
                         ret_flag = I2C_v2_sendAck(handle);
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_disableBurstMode(handle);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                         }
                         if(ret_flag == 0)
                         {
                             /* Set number of bytes to be transmitting */
                             ret_flag = I2C_v2_setDataCount(handle, 1U);
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putData(handle, object->writeBufIdx, 1U);
                         }
     
                         if(ret_flag == 0)
                         {
                             /* Start the tx command */
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_SMBUS_SEND_BYTE_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                         }
                         break;
                    case SMBUS_RECEIVE_BYTE_CMD:
                         /*
                          * Configure the I2C transfer to be in smbus recieve byte mode
                          */
                         ret_flag = I2C_v2_sendNack(handle);
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_disableBurstMode(handle);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                         }
                         if(ret_flag == 0)
                         {
                             /* Set number of bytes to be transmitting */
                             ret_flag = I2C_v2_setDataCount(handle, 1U);
                         }
     
                         if(ret_flag == 0)
                         {
                             /* Start the tx command */
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_SMBUS_RECEIVE_BYTE_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                         }

                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_getData(handle, object->readBufIdx, 1U);
                         }
                         break;
                    case SMBUS_WRITE_BYTE_CMD:
                         /*
                          * Configure the I2C transfer to be in smbus write byte mode
                          */
                         ret_flag = I2C_v2_sendAck(handle);
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_disableBurstMode(handle);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                         }
                         if(ret_flag == 0)
                         {
                             /* Set number of bytes to be transmitting */
                             ret_flag = I2C_v2_setDataCount(handle, 1U);
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putSmbusCmdCode(handle, (object->transactionCmd).cmdCode);
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putData(handle, object->writeBufIdx, 1U);
                         }
     
                         if(ret_flag == 0)
                         {
                             /* Start the tx command */
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_SMBUS_WRITE_BYTE_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                         }
                         break;
                    case SMBUS_READ_BYTE_CMD:
                         /*
                          * Configure the I2C transfer to be in smbus read byte mode
                          */
                         ret_flag = I2C_v2_sendNack(handle);
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_disableBurstMode(handle);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                         }
                         if(ret_flag == 0)
                         {
                             /* Set number of bytes to be transmitting */
                             ret_flag = I2C_v2_setDataCount(handle, 1U);
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putSmbusCmdCode(handle, (object->transactionCmd).cmdCode);
                         }
     
                         if(ret_flag == 0)
                         {
                             /* Start the tx command */
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_SMBUS_READ_BYTE_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                         }

                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_getData(handle, object->readBufIdx, 1U);
                         }
                         break;
                    case SMBUS_WRITE_WORD_CMD:
                         /*
                          * Configure the I2C transfer to be in smbus write byte mode
                          */
                         ret_flag = I2C_v2_sendAck(handle);
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_disableBurstMode(handle);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                         }
                         if(ret_flag == 0)
                         {
                             /* Set number of bytes to be transmitting */
                             ret_flag = I2C_v2_setDataCount(handle, 2U);
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putSmbusCmdCode(handle, (object->transactionCmd).cmdCode);
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putData(handle, object->writeBufIdx, 2U);
                         }
     
                         if(ret_flag == 0)
                         {
                             /* Start the tx command */
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_SMBUS_WRITE_WORD_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                         }
                         break;
                    case SMBUS_READ_WORD_CMD:
                         /*
                          * Configure the I2C transfer to be in smbus read byte mode
                          */
                         ret_flag = I2C_v2_sendNack(handle);
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_disableBurstMode(handle);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                         }
                         if(ret_flag == 0)
                         {
                             /* Set number of bytes to be transmitting */
                             ret_flag = I2C_v2_setDataCount(handle, 2U);
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putSmbusCmdCode(handle, (object->transactionCmd).cmdCode);
                         }
     
                         if(ret_flag == 0)
                         {
                             /* Start the tx command */
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_SMBUS_READ_WORD_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                         }

                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_getData(handle, object->readBufIdx, 2U);
                         }
                         break;
                    case SMBUS_BLOCK_WRITE_CMD:
                         /*
                          * Configure the I2C transfer to be in smbus write byte mode
                          */
                         ret_flag = I2C_v2_sendAck(handle);
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_enableBurstMode(handle);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                         }
                         if(ret_flag == 0)
                         {
                             /* Set number of bytes to be transmitting */
                             ret_flag = I2C_v2_setDataCount(handle, object->writeCountIdx);
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putSmbusCmdCode(handle, (object->transactionCmd).cmdCode);
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putData(handle, object->writeBufIdx, object->writeCountIdx);
                         }
     
                         if(ret_flag == 0)
                         {
                             /* Start the tx command */
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_SMBUS_BLOCK_WRITE_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                         }
                         break;
                    case SMBUS_BLOCK_READ_CMD:
                         /*
                          * Configure the I2C transfer to be in smbus read byte mode
                          */
                         ret_flag = I2C_v2_sendNack(handle);
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_enableBurstMode(handle);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                         }
                         if(ret_flag == 0)
                         {
                             /* Set number of bytes to be transmitting */
                             ret_flag = I2C_v2_getDataCount(handle, &(object->readCountIdx));
                         }
                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_putSmbusCmdCode(handle, (object->transactionCmd).cmdCode);
                         }
     
                         if(ret_flag == 0)
                         {
                             /* Start the tx command */
                             ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_SMBUS_READ_WORD_CMD);
                         }
                         if(ret_flag == 0)
                         {
                             ret_flag = I2C_v2_waitForCompletion(handle, transaction->timeout);
                         }

                         if(ret_flag == 0)
                         {
                             /* copy the data to buffer */
                             ret_flag = I2C_v2_getData(handle, object->readBufIdx, object->readCountIdx);
                         }
                         break;
                    default:
                         status = I2C_STS_ERR_INVALID_COMMAND;
                         break;
                }
            }
        }
        /* In slave mode */
        else
        {
            status = I2C_STS_ERR_ACCESS_ERROR;
        }
    }
    else
    {
        status = I2C_STS_ERR;
    }

    return status;
}

/*
 *  ======== I2C_transfer_v2 ========
 */
static int16_t I2C_transfer_v2(I2C_Handle handle,
                            I2C_Transaction *transaction)
{
    int16_t                     retVal = I2C_STS_ERR;
    uint8_t                     ret_flag = 0U;
    I2C_v2_Object              *object = NULL;

    if((handle != NULL) && (transaction != NULL))
    {
        /* Get the pointer to the object */
        object = (I2C_v2_Object*)handle->object;

        if ((transaction->validParams & I2C_TRANS_VALID_PARAM_MASTER_MODE) == 0U)
        {
            /*
             * masterMode valid param bit field is not set,
             * set masterMode to default mode (master)
             */
            transaction->masterMode = true;
        }

        if ((transaction->validParams & I2C_TRANS_VALID_PARAM_EXPAND_SA) == 0U)
        {
            /*
             * expandSA valid param bit field is not set,
             * set to 7-bit address mode by default
             */
            transaction->expandSA = false;
        }

        if (transaction->timeout == 0)
        {
            /* timeout cannot be NO_WAIT, set it to default value */
            transaction->timeout = I2C_WAIT_FOREVER;
        }

        if(ret_flag == 0U)
        {
            /* Acquire the lock for this particular I2C handle */
            I2C_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

            if(STANDARD_I2C_CMD == (object->transactionCmd).transferCmd)
            {
                retVal = I2C_primeTransfer_v2(handle, transaction);
            }
            else if(STANDARD_LOOPBACK_CMD == (object->transactionCmd).transferCmd)
            {
                retVal = I2C_loopbackTransfer_v2(handle, transaction);
            }
            else
            {
                retVal = I2C_smbusTransfer_v2(handle, transaction); 
            }

            (object->transactionCmd).transferCmd = STANDARD_I2C_CMD;
            (object->transactionCmd).cmdCode = (uint8_t)0U;

            /* Hwi handle has posted a 'cmdAckSem' check for Errors */
            switch(object->intStatusErr)
            {
                case RESET_COMMAND_FAILED:
                case SETUP_COMMAND_FAILED:
                case TX_COMMAND_FAILED:
                case RX_COMMAND_FAILED:
                case INVALID_DATA_COUNT:
                    retVal = I2C_STS_ERR_COMMAND_FAILURE;
                    break;
                case ADDRESS_ACKNOWLDEGE_FAILED:
                case DATA_ACKNOWLDEGE_FAILED:
                    retVal = I2C_STS_ERR_NO_ACK;
                    break;
                case MASTER_SLAVE_MODE_FAILED:
                case ADDRESSING_MODE_FAILED:
                    retVal = I2C_STS_ERR_ACCESS_ERROR;
                    break;
                case INVALID_COMMAND:
                    retVal = I2C_STS_ERR_INVALID_COMMAND;
                    break;
                case TIME_OUT_ERROR:
                    retVal = I2C_STS_ERR_TIMEOUT;
                    break;
                default:
                    retVal = I2C_STS_SUCCESS;
                    break;
            }
            
            /* Release the lock for this particular I2C handle */
            I2C_osalPostLock(object->mutex);
        }
    }
    else
    {
        retVal = I2C_STS_ERR;
    }

    return retVal;
}

/*
 *  ======== I2C_v2_recoverBus ========
 */
static int32_t I2C_v2_recoverBus(I2C_Handle handle, uint32_t i2cDelay)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    I2C_v2_Object           *object = NULL;
    I2C_PRU_IOPinMuxAttrs    pinReg;
    int32_t                  status = I2C_STATUS_SUCCESS;
    int32_t                  ret_flag = 0;
    
    
    if(handle == NULL)
    {
        status = I2C_STATUS_ERROR;
    }
    
    if(I2C_STATUS_SUCCESS == status)
    {
        /* Get the pointer to swipAttrs */
        object = (I2C_v2_Object*)handle->object;
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        if((object == NULL) || (swipAttrs == NULL))
        {
            status = I2C_STATUS_ERROR;
        }
    }

    if (I2C_STATUS_SUCCESS == status)
    {
        /* Check if SDA or SCL is stuck low based on the SYSTEST.
         * If SCL is stuck low we reset the IP.
         * If SDA is stuck low drive 9 clock pulses on SCL and check if the
         * slave has released the SDA. If not we reset the I2C controller.
         */

        /* Set the SCL pin mux register value for GPI */
        pinReg = swipAttrs->sclOutputPin;
        I2C_v2_pruGPIOMuxConfig(&pinReg, I2C_PRU_PINMUX_GPI_MODE);

        ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_READ_SCL_CMD);
        
        if(ret_flag == 0)
        {
            if(I2C_OPER_MODE_POLLING != object->operMode)
            {
                I2C_osalPendLock(object->cmdAckSem, SemaphoreP_WAIT_FOREVER);
            }
            else
            {
                object->intStatusErr = I2C_v2_pollIrqSts(handle);
            }
        }

        /* Set the SCL pin mux register value for GPI */
        pinReg = swipAttrs->sclOutputPin;
        I2C_v2_pruGPIOMuxConfig(&pinReg, I2C_PRU_PINMUX_GPO_MODE);

        if(ret_flag == 0)
        {
            if (SCL_VALUE_LOW == object->intStatusErr)
            {
                /* SCL is stuck low reset the I2C IP */
                ret_flag = I2C_v2_disableModule(handle);
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_RESET_CMD);
                }
                if(ret_flag == 0)
                {
                    if(I2C_OPER_MODE_POLLING != object->operMode)
                    {
                        I2C_osalPendLock(object->cmdAckSem, SemaphoreP_WAIT_FOREVER);
                    }
                    else
                    {
                        object->intStatusErr = I2C_v2_pollIrqSts(handle);
                    }
                    if(object->intStatusErr != (uint32_t)COMMAND_SUCCESS)
                    {
                        ret_flag = 1;
                    }
                }
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_setupPinMux(handle);
                    ret_flag = I2C_v2_writePinNum(handle);
                    ret_flag = I2C_v2_setupFifoSize(handle);
                    ret_flag = I2C_v2_enableMasterMode(handle);
                    ret_flag = I2C_v2_7bitAddressMode(handle);
                    ret_flag = I2C_v2_enableStartBit(handle);
                    ret_flag = I2C_v2_enableStopBit(handle);
                    ret_flag = I2C_v2_enableModule(handle);
                    ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                }
                if(ret_flag == 0)
                {
                    if(I2C_OPER_MODE_POLLING != object->operMode)
                    {
                        I2C_osalPendLock(object->cmdAckSem, SemaphoreP_WAIT_FOREVER);
                    }
                    else
                    {
                        object->intStatusErr = I2C_v2_pollIrqSts(handle);
                    }
                    if(object->intStatusErr != (uint32_t)COMMAND_SUCCESS)
                    {
                        ret_flag = 1;
                    }
                }
            }
            else if (SCL_VALUE_HIGH == object->intStatusErr)
            {
                /* SDA is stuck low generate 9 clk pulses on SCL */
                /* switch to system test mode */
                ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_RESET_SLAVE_CMD);
                if(ret_flag == 0)
                {
                    if(I2C_OPER_MODE_POLLING != object->operMode)
                    {
                        I2C_osalPendLock(object->cmdAckSem, SemaphoreP_WAIT_FOREVER);
                    }
                    else
                    {
                        object->intStatusErr = I2C_v2_pollIrqSts(handle);
                    }
                }
            }
            else
            {
                status = I2C_STATUS_ERROR;
            }
        }

    }

    if(ret_flag == 1)
    {
        status = I2C_STATUS_ERROR;
    }

    return status;
}

/*
 *  ======== I2C_transfer_Callback_v2 ========
 */
static void I2C_transfer_Callback_v2(I2C_Handle handle,
                                    I2C_Transaction *msg,
                                    int16_t transferStatus)
{
    I2C_v2_Object   *object = NULL;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object */
        object = (I2C_v2_Object*)handle->object;

        /* Indicate transfer complete */
        I2C_osalPostLock(object->cmdAckSem);
    }

    return;
}

static int32_t I2C_v2_setBusFrequency(I2C_Handle handle, I2C_ConfigMode busFrequency)
{
    int32_t                  retVal       = I2C_STATUS_SUCCESS;
    I2C_SwIPAttrs const     *swipAttrs    = NULL;

    /* Input parameter validation */
    if(NULL != handle)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        /* Extract bit rate from the input parameter */
        switch(busFrequency)
        {
           case I2C_ICSS_1MHZ_MODE:
           {
               /* Set the I2C configuration */
               HW_WR_REG32(swipAttrs->configAddr + I2C_BUS_FREQUENCY_OFFSET, (((uint32_t)IEP_CMP_INCREMENT_VAL_1MHZ << 16) | ICSS_I2C_1MHZ_FREQ));
               break;
           }

           case I2C_ICSS_400KHZ_MODE:
           {
               /* Set the I2C configuration */
               HW_WR_REG32(swipAttrs->configAddr + I2C_BUS_FREQUENCY_OFFSET, (((uint32_t)IEP_CMP_INCREMENT_VAL_400KHZ << 16) | ICSS_I2C_400KHZ_FREQ));
               break;
           }
           
           case I2C_ICSS_100KHZ_MODE:
           {
               /* Set the I2C configuration */
               HW_WR_REG32(swipAttrs->configAddr + I2C_BUS_FREQUENCY_OFFSET, (((uint32_t)IEP_CMP_INCREMENT_VAL_100KHZ << 16) | ICSS_I2C_100KHZ_FREQ));
               break;
           }
           
           default:
           {
               retVal = 1;
               break;
           }
        }
    }
    else
    {
        retVal = I2C_STATUS_ERROR;
    }

    return retVal;
}

/*
 *  ======== I2C_v2_control ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              I2C_control().
 */
static int32_t I2C_v2_control(I2C_Handle handle, uint32_t cmd, void *arg)
{
    int32_t                  retVal = I2C_STATUS_UNDEFINEDCMD;
    uint8_t                  regVal = 0;
    I2C_v2_Object           *object = NULL;
    int32_t                  ret_flag = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to object */
        object  = (I2C_v2_Object*)handle->object;

        switch (cmd)
        {
            case I2C_CMD_PROBE:
            {
                uint32_t slaveAddr = *((uint32_t *) arg);

                /* Acquire the lock for this particular I2C handle */
                I2C_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);
            
                ret_flag = I2C_v2_enableStopBit(handle);
                ret_flag = I2C_v2_enableStartBit(handle);

                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_SETUP_CMD);
                }
                
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_waitForCompletion(handle, SemaphoreP_WAIT_FOREVER);
                }

                if(ret_flag == 0)
                {
                    /* Set number of bytes to be transmitting */
                    ret_flag = I2C_v2_setSlaveAddress(handle, slaveAddr);
                    ret_flag = I2C_v2_setDataCount(handle, 1U);
                }

                /*
                 * Configure the I2C transfer to be in master transmitter mode
                 */
                if(ret_flag == 0)
                {
                    /* copy the data */
                    ret_flag = I2C_v2_putData(handle, &regVal, 1U);
                }
                
                if(ret_flag == 0)
                {
                    /* Start the tx command */
                    ret_flag = I2C_v2_sendCmd2PRU(handle, ICSS_I2C_TX_CMD);
                }
                
                if(ret_flag == 0)
                {
                    ret_flag = I2C_v2_waitForCompletion(handle, I2C_DELAY_BIG);
                }
                
                if(1 == ret_flag)
                {
                    retVal = I2C_STATUS_ERROR;
                }
                else
                {
                    retVal = I2C_STATUS_SUCCESS;
                }

                /* Release the lock for this particular I2C handle */
                I2C_osalPostLock(object->mutex);

                break;
            }

            case I2C_CMD_RECOVER_BUS:
            {
                uint32_t i2cDelay = *((uint32_t *) arg);

                /* Acquire the lock for this particular I2C handle */
                I2C_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

                /* perform Bus recovery */
                retVal = I2C_v2_recoverBus(handle, i2cDelay);

                /* Release the lock for this particular I2C handle */
                I2C_osalPostLock(object->mutex);

                break;
            }

            case I2C_CMD_SMBUS_TYPE:
            {
                I2C_TransactionCmd currCmd = *((I2C_TransactionCmd *) arg);

                /* Acquire the lock for this particular I2C handle */
                I2C_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

                /* copy current transaction command to object command */
                object->transactionCmd = currCmd;
                retVal = I2C_STATUS_SUCCESS;

                /* Release the lock for this particular I2C handle */
                I2C_osalPostLock(object->mutex);

                break;
            }

            default:
            {
                retVal = I2C_STATUS_UNDEFINEDCMD;
                break;
            }
        }
    }
    else
    {
        retVal = I2C_STATUS_ERROR;
    }

    return retVal;
}

/*
 * enable soft IP I2C module
 */
int32_t I2C_v2_enableModule(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal |= ((uint32_t)1U << ICSS_I2C_MODULE_ENABLE_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * disable soft IP I2C module
 */
int32_t I2C_v2_disableModule(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal &= ~((uint32_t)1U << ICSS_I2C_MODULE_ENABLE_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * enable soft IP I2C Master Mode
 */
int32_t I2C_v2_enableMasterMode(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal |= ((uint32_t)1U << ICSS_I2C_MASTER_SLAVE_MODE_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * enable soft IP I2C Slave Mode
 */
int32_t I2C_v2_enableSlaveMode(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal &= ~((uint32_t)1U << ICSS_I2C_MASTER_SLAVE_MODE_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * enable soft IP I2C 7 bits addressing Mode
 */
int32_t I2C_v2_7bitAddressMode(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal &= ~((uint32_t)1U << ICSS_I2C_ADDRESSING_MODE_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * enable soft IP I2C 10 bits addressing Mode
 */
int32_t I2C_v2_10bitAddressMode(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal |= ((uint32_t)1U << ICSS_I2C_ADDRESSING_MODE_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * send soft IP I2C START condition bits
 */
int32_t I2C_v2_enableStartBit(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal |= ((uint32_t)1U << ICSS_I2C_START_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * Do not send soft IP I2C START condition bits *
 */
int32_t I2C_v2_disableStartBit(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal &= ~((uint32_t)1U << ICSS_I2C_START_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * send soft IP I2C STOP condition bits *
 */
int32_t I2C_v2_enableStopBit(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal |= ((uint32_t)1U << ICSS_I2C_STOP_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * Do not send soft IP I2C STOP condition bits * *
 */
int32_t I2C_v2_disableStopBit(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal    = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal &= ~((uint32_t)1U << ICSS_I2C_STOP_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

int32_t I2C_v2_sendCmd2PRU(I2C_Handle handle, uint32_t cmd)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    I2C_v2_Object           *object    = NULL;
    uint32_t                 regVal    = 0x00000000;
    int32_t                  retVal    = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;
        object = (I2C_v2_Object*)handle->object;

        object->currentCmd = cmd;
        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_COMMAND_OFFSET);
        if(regVal != 0x00000000)
        {
            retVal = (-((int32_t)1));
        }
        else
        {
            regVal |= (cmd << 16);
            HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_COMMAND_OFFSET,regVal);
        }    
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

uint32_t I2C_v2_readResp2PRU(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_COMMAND_OFFSET);
    }

    return regVal;
}

int32_t I2C_v2_clearResp2PRU(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_COMMAND_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

static uint32_t I2C_v2_pollIrqSts(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs      = NULL;
    uint32_t                 irqCommonSts   = 0;
    uint32_t                 irqMaskVal     = 0x80000000U;
    uint32_t                 cmdResponse    = 0;
    uint32_t                 retVal         = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;
                
        /* read the register which indicate the irq status of all instances */
        irqCommonSts = HW_RD_REG32(swipAttrs->configAddr + IRQ_COMMON_REGISTER_OFFSET);
        irqMaskVal = ((uint32_t)0x00000001 << swipAttrs->i2cInstId);
        
        while((irqCommonSts & irqMaskVal) == 0U)
        {
            irqCommonSts = HW_RD_REG32(swipAttrs->configAddr + IRQ_COMMON_REGISTER_OFFSET);
        }

        cmdResponse = I2C_v2_readResp2PRU(handle);
        if(((cmdResponse & ((uint32_t)0xFFFF0000U)) == 0) && ((cmdResponse & ((uint32_t)0x0000FFFFU)) != 0))
        {
            retVal = (cmdResponse & ((uint32_t)0x0000FFFFU));
            I2C_v2_clearResp2PRU(handle);
            HW_WR_REG32(swipAttrs->configAddr + IRQ_COMMON_REGISTER_OFFSET, irqCommonSts & ~irqMaskVal);
        }
    }
    else
    {
        retVal = 1U;
    }

    return retVal;
}

int32_t I2C_v2_setSlaveAddress(I2C_Handle handle, uint32_t address)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int32_t                  retVal = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_SA_OFFSET, address);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

int32_t I2C_v2_putSmbusCmdCode(I2C_Handle handle, uint8_t cmdCode)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int32_t                  retVal = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        HW_WR_REG8(swipAttrs->baseAddr + ICSS_I2C_PRU_CMD_CODE_OFFSET, cmdCode);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

int32_t I2C_v2_setDataCount(I2C_Handle handle, uint32_t count)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int32_t                  retVal = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CNT_OFFSET, count);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

int32_t I2C_v2_getDataCount(I2C_Handle handle, uint32_t* count)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int32_t                  retVal = 0;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        *count = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CNT_OFFSET);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

int32_t I2C_v2_putData(I2C_Handle handle, uint8_t* dataPtr, uint32_t dataCount)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int32_t                  retVal = 0;
    uint32_t                 i = 0U;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        for(i=0U;i<dataCount;i++)
        {
            HW_WR_REG8(swipAttrs->baseAddr + (uint32_t)ICSS_I2C_INSTANCE_TX_OFFSET + i, dataPtr[i]);
        }
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

int32_t I2C_v2_getData(I2C_Handle handle, uint8_t* dataPtr, uint32_t dataCount)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int32_t                  retVal = 0;
    uint32_t                 i = 0U;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        for(i=0U;i<dataCount;i++)
        {
            dataPtr[i] = HW_RD_REG8(swipAttrs->baseAddr + (uint32_t)ICSS_I2C_INSTANCE_RX_OFFSET + i);
        }
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

int32_t I2C_v2_waitForCompletion(I2C_Handle handle, uint32_t timeout)
{
    I2C_v2_Object           *object = NULL;
    int32_t                  retVal = 0;
    SemaphoreP_Status        semStatus;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object */
        object = (I2C_v2_Object*)handle->object;

        if(I2C_OPER_MODE_POLLING != object->operMode)
        {
            semStatus = I2C_osalPendLock(object->cmdAckSem, timeout);
            if (semStatus == SemaphoreP_TIMEOUT)
            {
                /* Transaction timed out */
                object->intStatusErr = TIME_OUT_ERROR;
                I2C_v2_recoverBus(handle, I2C_DELAY_SMALL);
            }
        }
        else
        {
            object->intStatusErr = I2C_v2_pollIrqSts(handle);
        }
        if(object->intStatusErr != (uint32_t)COMMAND_SUCCESS)
        {
            retVal = 1;
        }
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * create NACK at the end of data transfer *
 */
int32_t I2C_v2_sendNack(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal = 0;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal |= ((uint32_t)1U << ICSS_I2C_RECIEVE_NACK_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * create ACK at the end of data transfer *
 */
int32_t I2C_v2_sendAck(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal = 0;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal &= ~((uint32_t)1U << ICSS_I2C_RECIEVE_NACK_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * create NACK at the end of data transfer *
 */
int32_t I2C_v2_enableBurstMode(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal = 0;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal |= ((uint32_t)1U << ICSS_I2C_SMBUS_BURST_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * create ACK at the end of data transfer *
 */
int32_t I2C_v2_disableBurstMode(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    uint32_t                 regVal = 0x00000000;
    int32_t                  retVal = 0;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        regVal = HW_RD_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET);
        regVal &= ~((uint32_t)1U << ICSS_I2C_SMBUS_BURST_BIT);
        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_CON_OFFSET,regVal);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/*
 * create NACK at the end of data transfer *
 */
int32_t I2C_v2_writeInstId(I2C_Handle handle)
{
    I2C_SwIPAttrs const     *swipAttrs = NULL;
    int32_t                  retVal = 0;

    /* Input parameter validation */
    if(handle != NULL)
    {
        /* Get the pointer to the object and swipAttrs */
        swipAttrs = (I2C_SwIPAttrs const *)handle->hwAttrs;

        HW_WR_REG32(swipAttrs->baseAddr + ICSS_I2C_PRU_INST_ID_OFFSET, swipAttrs->i2cInstId);
    }
    else
    {
        retVal = (-((int32_t)1));
    }

    return retVal;
}

/**
 * change the pinmux of GPIO pins of pru based on FW.
 **/ 
void I2C_v2_pruGPIOMuxConfig(I2C_PRU_IOPinMuxAttrs *handle, uint32_t pinMode)
{
    uint32_t regVal = *(volatile uint32_t *)(handle->baseRegAddr);
    if(I2C_PRU_PINMUX_GPI_MODE == pinMode)
    {
        regVal &= I2C_PRU_GPI_SELECT_MASK;
        regVal |= I2C_PRU_GPI_INPUT_ENABLE;
        regVal |= (uint32_t)(handle->inputModeVal);
    }
    else if(I2C_PRU_PINMUX_GPO_MODE == pinMode)
    {
        regVal &= I2C_PRU_GPO_SELECT_MASK;
        regVal |= I2C_PRU_GPO_PULLUP_DISABLE;
        regVal |= (uint32_t)(handle->outputModeVal);
    }
    else
    {
        /* nothing to be done here */
    }
    *(volatile uint32_t *)(handle->baseRegAddr) = regVal;
}






