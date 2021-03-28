/**
 *  \file   I2C_v0.c
 *
 *  \brief  IP version 0 specific I2C Driver APIs implementation.
 *
 *   This file contains the driver APIs for I2C controller.
 */

/*
 * Copyright (C) 2015 - 2017 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/drv/i2c/soc/I2C_v0.h>
#include <ti/csl/src/ip/i2c/V0/i2c.h>
#include <ti/drv/i2c/src/I2C_osal.h>
#include <ti/drv/i2c/src/I2C_drv_log.h>

#define I2C_MODULE_OUTPUT_CLK_100KHZ  (100000U)
#define I2C_MODULE_OUTPUT_CLK_400KHZ  (400000U)
#define I2C_MODULE_OUTPUT_CLK_3P4MHZ  (3400000U)

#define I2C_MODULE_INTERNAL_CLK_4MHZ  (4000000U)
#define I2C_MODULE_INTERNAL_CLK_12MHZ (12000000U)
#define I2C_MASTER_ERR_NONE      (0)

/* I2C AM57x functions */
static void       I2C_close_v0(I2C_Handle handle);
static void       I2C_init_v0(I2C_Handle handle);
static I2C_Handle I2C_open_v0(I2C_Handle handle, const I2C_Params *params);
static int16_t       I2C_transfer_v0(I2C_Handle handle,
                                     I2C_Transaction *transaction);
static int16_t       I2C_primeTransfer_v0(I2C_Handle handle,
                                          I2C_Transaction *transaction);
static void       I2C_transfer_Callback_v0(I2C_Handle handle,
                                             I2C_Transaction *msg,
                                             int16_t transferStatus);
static int32_t I2C_v0_control(I2C_Handle handle, uint32_t cmd, void *arg);



/* I2C function table for I2C AM57x implementation */
const I2C_FxnTable I2C_v0_FxnTable = {
    &I2C_close_v0,
    &I2C_v0_control,
    &I2C_init_v0,
    &I2C_open_v0,
    &I2C_transfer_v0
};

/*
 *  ======== I2C_close_v0 ========
 */
static void I2C_close_v0(I2C_Handle handle)
{
    I2C_v0_Object   *object;
    I2C_HwAttrs const  *hwAttrs;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;
        object = (I2C_v0_Object*)handle->object;

        /* Check to see if a I2C transaction is in progress */
        OSAL_Assert(object->headPtr != NULL);

        /* Mask I2C interrupts */
        I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_ALL_INTS_MASK);

        /* Disable the I2C Master */
        I2CMasterDisable(hwAttrs->baseAddr);

        if (I2C_OPER_MODE_POLLING != object->operMode)
        {
            /* Destruct the Hwi */
            I2C_osalHardwareIntDestruct(object->hwi,hwAttrs->eventId);
        }

        /* Destruct the instance lock */
        I2C_osalDeleteBlockingLock(object->mutex);

        if (I2C_OPER_MODE_BLOCKING == object->operMode)
        {
            /* Destruct the transfer completion lock */
            I2C_osalDeleteBlockingLock(object->transferComplete);
        }


        object->isOpen = (bool)false;

        I2C_drv_log1("\n I2C: Object closed 0x%x \n", hwAttrs->baseAddr);
    }
    return;
}
/*
 *  ======== Terminate the current transfer ========
 */
static void I2C_v0_complete_curr_transfer(I2C_Handle handle, int32_t xferStatus);  /*for misra warnings*/
static void I2C_v0_complete_curr_transfer(I2C_Handle handle, int32_t xferStatus)
{
	I2C_v0_Object     *object = (I2C_v0_Object*)handle->object;

	object->mode = I2C_IDLE_MODE;
	if(object->currentTransaction) {
      object->currentTransaction->readCount -= object->readCountIdx;
      object->currentTransaction->writeCount -= object->writeCountIdx;

      /* Callback to application or post semaphore */
      object->i2cParams.transferCallbackFxn(handle,
                                            object->currentTransaction,
                                            xferStatus);

      /* See if we need to process any other transactions */
      if (object->headPtr == object->tailPtr) {
          /* No other transactions need to occur */
          object->currentTransaction = NULL;
          object->headPtr = NULL;

      }  else {
        /* Another transfer needs to take place */
        object->headPtr = (I2C_Transaction*)(object->headPtr->nextPtr);

         /* Start new transfer */
        I2C_primeTransfer_v0(handle, object->headPtr);
      }
	}
}

static void I2C_v0_hwiFxnMaster(I2C_Handle handle);   /* for misra warnings*/
static void I2C_v0_hwiFxnMaster(I2C_Handle handle)
{
    uint32_t            errStatus;
    uint32_t            stopCondition;
    I2C_v0_Object      *object;
    I2C_HwAttrs const  *hwAttrs;
    int32_t             xferStatus = I2C_STS_SUCCESS;
    uint32_t            xsa;

    /* Get the pointer to the object and hwAttrs */
    object = (I2C_v0_Object*)handle->object;
    hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

    /* Check for I2C Errors */
    errStatus = I2CMasterErr(hwAttrs->baseAddr);
    if (errStatus & I2C_INT_STOP_CONDITION)
    {
        if ((object->writeCountIdx == 0U) && (object->readCountIdx == 0U))
        {
            /* End of transfer stop condition, not an error */
            stopCondition = I2C_INT_STOP_CONDITION;
            errStatus &= (uint32_t)(~stopCondition);
        }
    }

    if ((errStatus == I2C_MASTER_ERR_NONE) || (object->mode == I2C_ERROR)) {

        /* No errors, now check what we need to do next */
        switch (object->mode) {
            /*
             * ERROR case is OK because if an Error is detected, a STOP bit is
             * sent; which in turn will call another interrupt. This interrupt
             * call will then post the transferComplete semaphore to unblock the
             * I2C_transfer function
             */
            case I2C_ERROR:
            case I2C_IDLE_MODE:
                if(object->mode==I2C_ERROR) {
                  xferStatus=I2C_STS_ERR;
                } else {
                  xferStatus=I2C_STS_SUCCESS;
                } 
		
                /* callback to application or post Semaphore to unblock transfer fxn */
                I2C_v0_complete_curr_transfer(handle,xferStatus);

                /* Clear STOP condition interrupt */
                I2CMasterIntClearEx(hwAttrs->baseAddr,
                                    I2C_INT_STOP_CONDITION);

                /* Disable STOP condition interrupt */
                I2CMasterIntDisableEx(hwAttrs->baseAddr,
                                      I2C_INT_MASK_STOP_CONDITION);

  	        break;

            case I2C_WRITE_MODE:
                /* Check if data needs to be sent */
                if (object->writeCountIdx != 0U) {
                    /* Write data into transmit FIFO */
                    I2CMasterDataPut(hwAttrs->baseAddr,
                                     *(object->writeBufIdx));
                    (object->writeBufIdx)++;
                    object->writeCountIdx--;

                    if (object->writeCountIdx == 0U)
                    {
                        /* End of write, disable TX ready interrupt */
                        I2CMasterIntDisableEx(hwAttrs->baseAddr,
                                              I2C_INT_MASK_TRANSMIT_READY);
                        if (object->readCountIdx)
                        {
                            /* Get register access interrupt to start reading */
                            I2CMasterIntEnableEx(hwAttrs->baseAddr,
                            	                 I2C_INT_MASK_ADRR_READY_ACESS);
                        }
                        else
                        {
                            /* Done with all transmissions, wait for stop condition */
                            object->mode = I2C_IDLE_MODE;
                        }
                    }
                }
                else {
                    if (object->readCountIdx) {
                        /* Next state: Receive mode */
                        object->mode = I2C_READ_MODE;
                        I2CMasterIntDisableEx(hwAttrs->baseAddr,
                                              I2C_INT_MASK_ADRR_READY_ACESS);

                        /* Set number of bytes to receive */
                        I2CSetDataCount(hwAttrs->baseAddr, object->readCountIdx);

                        /* Configure peripheral for I2C Receive mode with stop */
                        if (object->currentTransaction->expandSA == true)
                        {
                            /* enable the 10-bit address mode */
                            xsa = I2C_CFG_CMD_10BIT_ADDRESS;
                        }
                        else
                        {
                            /* enable the 7-bit address mode */
                            xsa = I2C_CFG_CMD_7BIT_ADDRESS;
                        }
                        I2CMasterControl(hwAttrs->baseAddr,
                                         I2C_CFG_MASK_RX | I2C_CFG_MASK_REPEAT_MODE | I2C_CFG_MASK_XA,
                                         I2C_CFG_CMD_RX | I2C_CFG_CMD_REPEAT_MODE_OFF | xsa);

                        /* Enable RX interrupt to handle data received */
                        I2CMasterIntEnableEx(hwAttrs->baseAddr, I2C_INT_MASK_RECV_READY);

                        /* Start I2C peripheral in RX mode */
                        I2CMasterStart(hwAttrs->baseAddr);
                    }
                }
                break;

            case I2C_READ_MODE:
                /* Save the received data */
                *(object->readBufIdx) = I2CMasterDataGet(hwAttrs->baseAddr);

                object->readBufIdx++;
                object->readCountIdx--;

                if (object->readCountIdx == 0U) {
                    /* No more data to receive, Next state: Idle mode */
                    object->mode = I2C_IDLE_MODE;

                    /* Disable RX interrupt, next interrupt will be from STOP */
                    I2CMasterIntDisableEx(hwAttrs->baseAddr,
                                          I2C_INT_MASK_RECV_READY);
                    /* Send stop */
                    I2CMasterStop(hwAttrs->baseAddr);
                }
                break;

            default:
                object->mode = I2C_ERROR;
                break;
        }
    }
    else {
        /* Some sort of error happened! */
        object->mode = I2C_ERROR;
        object->intStatusErr = errStatus;
	    if (errStatus & I2C_INT_NO_ACK)
        {
           xferStatus = I2C_STS_ERR_NO_ACK;
           I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_NO_ACK);
		} else if (errStatus & I2C_INT_ARBITRATION_LOST)
        { 
           xferStatus = I2C_STS_ERR_ARBITRATION_LOST;
 		   I2CMasterIntClearEx(hwAttrs->baseAddr,I2C_INT_ARBITRATION_LOST);
        } else {
           xferStatus = I2C_STS_ERR;
		}
	        
		I2C_v0_complete_curr_transfer(handle,xferStatus);

        /* Try to send a STOP bit to end all I2C communications immediately */
        I2CMasterStop(hwAttrs->baseAddr);
		I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_ALL_INTS);
        I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_ALL_INTS);
    }

    return;
}

/*
 *  ======== I2C_v0_hwiFxnSlave ========
 *  Hwi interrupt handler to service the I2C peripheral in slave mode
 */
static void I2C_v0_hwiFxnSlave(I2C_Handle handle);   /* for misra warnings*/
static void I2C_v0_hwiFxnSlave(I2C_Handle handle)
{
    I2C_v0_Object     *object;
    I2C_HwAttrs const *hwAttrs;
    uint32_t           intCode;
    uint32_t           intStat;

    /* Get the pointer to the object and hwAttrs */
    object = (I2C_v0_Object*)handle->object;
    hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

    intCode = I2CIntVectGet(hwAttrs->baseAddr);
    intStat = I2CMasterIntStatusEx(hwAttrs->baseAddr, I2C_ALL_INTS);

    switch (intCode)
    {
        case I2C_IVR_INTCODE_AAS:
            if (object->mode == I2C_IDLE_MODE)
            {
                /*
                 * This is the first transfer initiation from master
                 * Update the state to transfer started and enable
                 * all the salve interrupts
                 */
                object->mode = I2C_SLAVE_XFER_MODE;
                I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_ALL_INTS);
                I2CMasterIntEnableEx(hwAttrs->baseAddr,
                                                I2C_INT_MASK_TRANSMIT_READY | I2C_INT_MASK_RECV_READY |
                                                I2C_INT_MASK_ADRR_READY_ACESS | I2C_INT_MASK_ADRR_SLAVE |
                                                I2C_INT_MASK_NO_ACK | I2C_INT_MASK_STOP_CONDITION);

                if (((object->writeCountIdx) != 0) &&
                    ((intStat & I2C_INT_TRANSMIT_READY) == I2C_INT_TRANSMIT_READY))
                {
                    /* Slave transmit mode, send data and clear the interrupt */
                    I2CMasterDataPut(hwAttrs->baseAddr, *(object->writeBufIdx));
                    object->writeCountIdx--;
                    object->writeBufIdx++;

                }
            }
            else if (object->mode == I2C_SLAVE_XFER_MODE)
            {
                /*
                 * This is a restart condition, callback to application
                 * to restart read/write
                 */
                object->currentTransaction->readCount -= object->readCountIdx;
                object->currentTransaction->writeCount -= object->writeCountIdx;
                object->i2cParams.transferCallbackFxn(handle,
                                                      object->currentTransaction,
                                                      I2C_STS_RESTART);
                object->writeBufIdx = (uint8_t*)(object->currentTransaction->writeBuf);
                object->writeCountIdx = object->currentTransaction->writeCount;

                object->readBufIdx = (uint8_t*)(object->currentTransaction->readBuf);
                object->readCountIdx = object->currentTransaction->readCount;

                object->mode = I2C_SLAVE_RESTART_MODE;
                if (((object->writeCountIdx) != 0U) &&
                    ((intStat & I2C_INT_TRANSMIT_READY) == I2C_INT_TRANSMIT_READY))
                {
                    /* Slave transmit mode with restart, send data and clear the interrupt */
                    I2CMasterDataPut(hwAttrs->baseAddr, *(object->writeBufIdx));
                    object->writeCountIdx--;
                    object->writeBufIdx++;
                }
            }
            else
            {
                /* Control should not come here. Sphurious interrupt clear it. */
            }
            I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ADRR_SLAVE);
            break;

        case I2C_IVR_INTCODE_NACK:
            /* Get a NACK from master, stop the transfer and callback */
            object->currentTransaction->readCount -= object->readCountIdx;
            object->currentTransaction->writeCount -= object->writeCountIdx;
            object->i2cParams.transferCallbackFxn(handle,
                                                  object->currentTransaction,
                                                  I2C_STS_ERR_NO_ACK);
            I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_ALL_INTS_MASK);
            I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_ALL_INTS);
            break;

        case I2C_IVR_INTCODE_ARDY:
            I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ADRR_READY_ACESS);
            break;

        case I2C_IVR_INTCODE_RRDY:
            /* Read from Rx register only when current transaction is ongoing */
            if (object->readCountIdx)
            {
                *(object->readBufIdx) = I2CMasterDataGet(hwAttrs->baseAddr);
                object->readBufIdx++;
                object->readCountIdx--;
                I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_RECV_READY);
            }
            else
            {
                /* RX buffer full, drop the data received */
                I2CMasterDataGet(hwAttrs->baseAddr);
            }
            I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_RECV_READY);
            break;

        case I2C_IVR_INTCODE_XRDY:
            if ((object->mode == I2C_SLAVE_XFER_MODE) || (object->mode == I2C_SLAVE_RESTART_MODE))
            {
                if (object->writeCountIdx != 0U)
                {
                    I2CMasterDataPut(hwAttrs->baseAddr, *(object->writeBufIdx));
                    object->writeCountIdx--;
                    object->writeBufIdx++;
                }
                else
                {
                    if (object->currentTransaction->writeCount)
                    {
                        /* TX buffer empty, send 0 */
                        I2CMasterDataPut(hwAttrs->baseAddr, 0);
                    }
                }
            }
            break;

        case I2C_IVR_INTCODE_SCD:
            /* stop condition detected, end of current transfer */
            I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_ALL_INTS);
            object->mode = I2C_IDLE_MODE;
            object->currentTransaction->readCount -= object->readCountIdx;
            object->currentTransaction->writeCount -= object->writeCountIdx;

            /* Callback to application or post semaphore */
            object->i2cParams.transferCallbackFxn(handle,
                                                  object->currentTransaction,
                                                  I2C_STS_SUCCESS);

            /* See if we need to process any other transactions */
            if (object->headPtr == object->tailPtr)
            {
                /* No other transactions need to occur */
                object->currentTransaction = NULL;
                object->headPtr = NULL;
                I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_ALL_INTS_MASK);
            }
            else
            {
                /* Another transfer needs to take place */
                object->headPtr = (I2C_Transaction*)(object->headPtr->nextPtr);

                /* Start new transfer */
                I2C_primeTransfer_v0(handle, object->headPtr);
            }
            break;

        default:
            break;
    }

    return;
}

/*
 *  ======== I2C_v0_hwiFxn ========
 *  Hwi interrupt handler to service the I2C peripheral
 *
 *  The handler is a generic handler for a I2C object.
 */
static void I2C_v0_hwiFxn(uintptr_t arg);   /* for misra warnings*/
static void I2C_v0_hwiFxn(uintptr_t arg)
{
	I2C_Handle          handle = (I2C_Handle)arg;
    I2C_v0_Object      *object;
    I2C_HwAttrs const  *hwAttrs;

    /* Input parameter validation */
    if ((void *)handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        object = (I2C_v0_Object*)(((I2C_Handle)arg)->object);
        hwAttrs = (I2C_HwAttrs const *)(((I2C_Handle)arg)->hwAttrs);

        if (hwAttrs->intcMuxNum != INVALID_INTC_MUX_NUM)
        {
            I2C_osalMuxIntcDisableHostInt(hwAttrs->intcMuxNum, hwAttrs->intcMuxOutEvent);
            I2C_osalMuxIntcClearSysInt(hwAttrs->intcMuxNum, hwAttrs->intcMuxInEvent);
        }

        if (object->currentTransaction->masterMode)
        {
            I2C_v0_hwiFxnMaster(handle);
        }
        else
        {
            I2C_v0_hwiFxnSlave(handle);
        }

        if (hwAttrs->intcMuxNum != INVALID_INTC_MUX_NUM)
        {
            I2C_osalMuxIntcClearSysInt(hwAttrs->intcMuxNum, hwAttrs->intcMuxInEvent);
            I2C_osalHardwareIntrClear(hwAttrs->eventId,hwAttrs->intNum);
            I2C_osalMuxIntcEnableHostInt(hwAttrs->intcMuxNum, hwAttrs->intcMuxOutEvent);
        }
    }
    return;
}

/*
 *  ======== I2C_init_v0 ========
 */
static void I2C_init_v0(I2C_Handle handle)
{
    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Mark the object as available */
        ((I2C_v0_Object *)(handle->object))->isOpen = (bool)false;
    }
}


/*
 *  ======== I2C_open_v0 ========
 */
static I2C_Handle I2C_open_v0(I2C_Handle handle, const I2C_Params *params)
{
    SemaphoreP_Params     semParams;
    uint32_t              key, outputClk;
    I2C_v0_Object        *object = NULL;
    I2C_HwAttrs const    *hwAttrs = NULL;
    uint32_t              internalClk;
    OsalRegisterIntrParams_t interruptRegParams;
    MuxIntcP_inParams     muxInParams;
    MuxIntcP_outParams    muxOutParams;
    uint32_t              ret_flag = 0U;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        object = (I2C_v0_Object*)handle->object;
        hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

        /* Determine if the device index was already opened */
        key = I2C_osalHardwareIntDisable();
        if(object->isOpen == true) {
            I2C_osalHardwareIntRestore(key);
            handle = NULL;
            ret_flag = 1U;
        }
    }
    else
    {
        ret_flag = 1U;
    }

    if (ret_flag == 0U)
    {
        /* Mark the handle as being used */
        object->isOpen = (bool)true;
        I2C_osalHardwareIntRestore(key);

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
            if(true == hwAttrs->enableIntr)
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

        if(I2C_OPER_MODE_POLLING != object->operMode)
        {
            /* Initialize with defaults */
            Osal_RegisterInterrupt_initParams(&interruptRegParams);

            if (hwAttrs->intcMuxNum != INVALID_INTC_MUX_NUM)
            {
			    /* Setup Chip Interrupt Controller */
                muxInParams.arg         = (uintptr_t)handle;
                muxInParams.muxNum      = hwAttrs->intcMuxNum;
                muxInParams.muxInEvent  = hwAttrs->intcMuxInEvent;
                muxInParams.muxOutEvent = hwAttrs->intcMuxOutEvent;
                muxInParams.muxIntcFxn  = (MuxIntcFxn)(&I2C_v0_hwiFxn);

                muxOutParams.muxIntcFxn = (MuxIntcFxn)NULL;
                muxOutParams.arg        = (uintptr_t)NULL;
                I2C_osalMuxIntcSetup(&muxInParams, &muxOutParams);

                interruptRegParams.corepacConfig.isrRoutine = muxOutParams.muxIntcFxn;
                interruptRegParams.corepacConfig.arg        = muxOutParams.arg;
            }
            else
            {
                interruptRegParams.corepacConfig.isrRoutine = (&I2C_v0_hwiFxn);
                interruptRegParams.corepacConfig.arg      = (uintptr_t)handle;
            }

            /* Populate the interrupt parameters */
            interruptRegParams.corepacConfig.name=NULL;
            interruptRegParams.corepacConfig.corepacEventNum=hwAttrs->eventId; /* Event going in to CPU */
            interruptRegParams.corepacConfig.intVecNum=hwAttrs->intNum; /* Host Interrupt vector */
#if defined (__TI_ARM_V5__)
	    interruptRegParams.corepacConfig.priority = hwAttrs->intNum;
#endif

             /* Register interrupts */
            I2C_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));

            if(object->hwi == NULL) {
                I2C_drv_log("\n Error constructing I2C HWI object \n");
                I2C_close_v0(handle);
                handle = NULL;   /*to solve the MISRA.RETURN.NOT_LAST warning*/
                ret_flag = 1U;
            }
        }

        if(ret_flag == 0U)
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
            if (object->operMode == I2C_OPER_MODE_BLOCKING) {
                /*
                 * Semaphore to cause the waiting task to block for the I2C
                 * to finish
                 */
                object->transferComplete = I2C_osalCreateBlockingLock(0, &semParams);

                /* Store internal callback function */
                object->i2cParams.transferCallbackFxn = &I2C_transfer_Callback_v0;
            }
            if(object->operMode == I2C_OPER_MODE_CALLBACK){
                /* Check to see if a callback function was defined for async mode */
                OSAL_Assert(object->i2cParams.transferCallbackFxn == NULL);
            }

            /* Specify the idle state for this I2C peripheral */
            object->mode = I2C_IDLE_MODE;

            /* Clear the head pointer */
            object->headPtr = NULL;
            object->tailPtr = NULL;

            I2C_drv_log1("\n I2C: Object created 0x%x \n", hwAttrs->baseAddr);

            /* Put i2c in reset/disabled state */
            I2CMasterDisable(hwAttrs->baseAddr);

            /* Extract bit rate from the input parameter */
            switch(object->i2cParams.bitRate)
            {
                case I2C_100kHz:
                {
                    outputClk = I2C_MODULE_OUTPUT_CLK_100KHZ;
                    internalClk = I2C_MODULE_INTERNAL_CLK_4MHZ;
                    break;
                }

                case I2C_400kHz:
                {
                    outputClk = I2C_MODULE_OUTPUT_CLK_400KHZ;
                    internalClk = I2C_MODULE_INTERNAL_CLK_12MHZ;
                    break;
                }

                case I2C_3P4Mhz:
                {
                    outputClk = I2C_MODULE_OUTPUT_CLK_3P4MHZ;
                    internalClk = I2C_MODULE_INTERNAL_CLK_12MHZ;
                    break;
                }

                default:
                {
                    /* Default case force it to 100 KHz bit rate */
                    outputClk = I2C_MODULE_OUTPUT_CLK_100KHZ;
                    internalClk = I2C_MODULE_INTERNAL_CLK_4MHZ;
                }
                break;
            }

            /* Set the I2C configuration */
            I2CMasterInitExpClk(hwAttrs->baseAddr,
                                hwAttrs->funcClk,
                                internalClk,
                                outputClk);

            /* Clear any pending interrupts */
            I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_ALL_INTS);

            /* Mask off all interrupts */
            I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_ALL_INTS_MASK);

            /* Enable the I2C Master for operation */
            I2CMasterEnable(hwAttrs->baseAddr);
            I2COwnAddressSet(hwAttrs->baseAddr, hwAttrs->ownSlaveAddr);
        }
    }
    /* Return the address of the i2cObjectArray[i] configuration struct */
    return (handle);
}

/*
 *  ======== I2C_primeTransfer_v0 =======
 */
static int16_t I2C_primeTransfer_v0(I2C_Handle handle,
                                 I2C_Transaction *transaction)
{
    I2C_v0_Object  *object = NULL;
    I2C_HwAttrs const *hwAttrs = NULL;
    int16_t retVal = I2C_STS_SUCCESS;
    uint32_t errStat=0,fatalError=0;
    uint32_t xsa;

    /* Get the pointer to the object and hwAttrs */
    object = (I2C_v0_Object*)handle->object;
    hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

    /* Store the new internal counters and pointers */
    object->currentTransaction = transaction;

    object->writeBufIdx = (uint8_t*)transaction->writeBuf;
    object->writeCountIdx = transaction->writeCount;

    object->readBufIdx = (uint8_t*)transaction->readBuf;
    object->readCountIdx = transaction->readCount;

    I2C_drv_log2("\n I2C:(0x%x) Starting transaction to slave: 0x%x \n",
        hwAttrs->baseAddr, object->currentTransaction->slaveAddress);

    if (object->currentTransaction->expandSA == true)
    {
        /* enable the 10-bit address mode */
        xsa = I2C_CFG_CMD_10BIT_ADDRESS;
    }
    else
    {
        /* enable the 7-bit address mode */
        xsa = I2C_CFG_CMD_7BIT_ADDRESS;
    }

    if (transaction->masterMode)
    {
        /* Specify the I2C slave address */
        I2CMasterSlaveAddrSet(hwAttrs->baseAddr,
                              object->currentTransaction->slaveAddress);

        if(I2C_OPER_MODE_POLLING != object->operMode)
        {
            /* clear all interrupts */
            I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_ALL_INTS);

            /* Enable interrupts on stop and error bits */
            I2CMasterIntEnableEx(hwAttrs->baseAddr,
                                 I2C_INT_MASK_ARBITRATION_LOST |
                                 I2C_INT_MASK_NO_ACK           |
                                 I2C_INT_MASK_STOP_CONDITION);

            /* Start transfer in Transmit mode */
            if (object->writeCountIdx != 0U) {
                /* Set number of bytes to be transmitting */
                I2CSetDataCount(hwAttrs->baseAddr, object->writeCountIdx);

                /*
                 * Configure the I2C transfer to be in master transmitter mode.
                 */
                I2CMasterControl(hwAttrs->baseAddr,
                                 I2C_CFG_MASK_TX | I2C_CFG_MASK_REPEAT_MODE | I2C_CFG_MASK_XA,
                                 I2C_CFG_CMD_TX | I2C_CFG_CMD_REPEAT_MODE_OFF | xsa);

                /* Log the transaction */
                I2C_drv_log3("\n I2C:(0x%x) I2C_IDLE_MODE: Data to write: 0x%x; To Slave: 0x%x \n",
                        hwAttrs->baseAddr, *(object->writeBufIdx),
                        object->currentTransaction->slaveAddress);

                /* set the trasfer state to write mode */
                object->mode = I2C_WRITE_MODE;

                /*
                 * enable transmit interrupt.
                 */
                I2CMasterIntEnableEx(hwAttrs->baseAddr, I2C_INT_MASK_TRANSMIT_READY | I2C_INT_NO_ACK | I2C_INT_ARBITRATION_LOST);

                if (object->readCountIdx == 0U)
                {
                    /* If no data read, send stop at the end of write */
                    I2CMasterControl(hwAttrs->baseAddr,
                                     I2C_CFG_MASK_STOP | I2C_CFG_MASK_XA,
                                     I2C_CFG_CMD_STOP | xsa);
                }

                /* Start the I2C transfer in master transmit mode */
                I2CMasterStart(hwAttrs->baseAddr);

                I2C_drv_log1("\n I2C:(0x%x) I2C_IDLE_MODE: -> I2C_WRITE_MODE; Writing w/ START \n",
                    hwAttrs->baseAddr);
            }

            /* Start transfer in Receive mode */
            else {
                object->mode = I2C_READ_MODE;

                /* set number of bytes to read */
                I2CSetDataCount(hwAttrs->baseAddr, object->readCountIdx);

                /* set to master receiver mode */
                I2CMasterControl(hwAttrs->baseAddr,
                                 I2C_CFG_MASK_RX | I2C_CFG_MASK_REPEAT_MODE  | I2C_CFG_MASK_XA,
                                 I2C_CFG_CMD_RX | I2C_CFG_CMD_REPEAT_MODE_OFF | xsa);

                /* Enable RX interrupts */
                I2CMasterIntEnableEx(hwAttrs->baseAddr, I2C_INT_MASK_RECV_READY  | I2C_INT_NO_ACK | I2C_INT_ARBITRATION_LOST);

                /* Send start bit */
                I2CMasterStart(hwAttrs->baseAddr);

                I2C_drv_log1("\n I2C:(0x%x) I2C_IDLE_MODE: -> I2C_READ_MODE; Reading w/ NACK \n",
                    hwAttrs->baseAddr);
            }
        }
        else  /* POLLING MODE */
        {
            if(object->writeCountIdx != 0U)
            {
                /* wait for bus free */
                while(I2CMasterBusBusy(hwAttrs->baseAddr))
                {}

                /* clear all interrupts */
                I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_ALL_INTS);

                /* set number of bytes to write */
                I2CSetDataCount(hwAttrs->baseAddr, object->writeCountIdx);

                /* set to master transmitter mode */
                I2CMasterControl(hwAttrs->baseAddr,
                                 I2C_CFG_MASK_TX | I2C_CFG_MASK_REPEAT_MODE | I2C_CFG_MASK_XA,
                                 I2C_CFG_CMD_TX | I2C_CFG_CMD_REPEAT_MODE_OFF | xsa);

                /* Write byte and increase data pointer to next byte */
                I2CMasterDataPut(hwAttrs->baseAddr, *(object->writeBufIdx));
                (object->writeBufIdx)++;

                /* Update number of bytes written */
                object->writeCountIdx--;

                /* generate start */
                I2CMasterStart(hwAttrs->baseAddr);

                /* wait for bus busy */
                while(I2CMasterBusBusy(hwAttrs->baseAddr) == false)
                {}
                while(object->writeCountIdx != 0U)
                {
                    /* wait for transmit ready or error */
                    while((I2CMasterIntStatusEx(hwAttrs->baseAddr,
                        I2C_INT_TRANSMIT_READY) == 0U) &&
                        (I2CMasterIntStatusEx(hwAttrs->baseAddr,
                        I2C_INT_ARBITRATION_LOST | I2C_INT_NO_ACK |
                        I2C_INT_STOP_CONDITION ) == 0U))
                    {}

                    /* if we get an error, do a stop */
                    errStat=I2CMasterIntStatusEx(hwAttrs->baseAddr,
                        I2C_INT_ARBITRATION_LOST | I2C_INT_NO_ACK |
                        I2C_INT_STOP_CONDITION );
                    if(errStat)
                    /* if we get an error, do a stop and return failure */
                    {
                       fatalError=1U;
                       break;
                    }
                    /* write byte and increase data pointer to next byte */
                    I2CMasterDataPut(hwAttrs->baseAddr, *(object->writeBufIdx));
                    (object->writeBufIdx)++;

                    /* update number of bytes written */
                    object->writeCountIdx--;
                }

                if(fatalError == 0U) {
                /* wait for register access ready */
                while(I2CMasterIntStatusEx(hwAttrs->baseAddr,
                    I2C_INT_ADRR_READY_ACESS) == 0U) {
                  }
                }
                if ((errStat & I2C_INT_ARBITRATION_LOST) == I2C_INT_ARBITRATION_LOST)
                {
                   retVal = I2C_STS_ERR_ARBITRATION_LOST;
                }
                else if ((errStat & I2C_INT_NO_ACK) == I2C_INT_NO_ACK)
                {
                   retVal = I2C_STS_ERR_NO_ACK;
                }
                else
                {
                   retVal = I2C_STS_SUCCESS;
                }

                if(object->readCountIdx == 0U)
                {
                    /* generate stop when no data read */
                    I2CMasterStop(hwAttrs->baseAddr);

                    /* wait for stop to happen */
                    while(I2CMasterIntStatusEx(hwAttrs->baseAddr,
                        I2C_INT_STOP_CONDITION) == 0U)
                    {}
                }
            }

            if((object->readCountIdx != 0U) && (retVal==I2C_STS_SUCCESS))
            {
                /* clear all interrupts */
                I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_ALL_INTS);

                /* set number of bytes to read */
                I2CSetDataCount(hwAttrs->baseAddr, object->readCountIdx);

                /* set to master receiver mode */
                I2CMasterControl(hwAttrs->baseAddr,
                                 I2C_CFG_MASK_RX | I2C_CFG_MASK_REPEAT_MODE | I2C_CFG_MASK_XA,
                                 I2C_CFG_CMD_RX | I2C_CFG_CMD_REPEAT_MODE_OFF | xsa);

                /* generate start */
                I2CMasterStart(hwAttrs->baseAddr);

                /* wait for bus not busy */
                while(I2CMasterBusBusy(hwAttrs->baseAddr) == false)
                {}
                while(object->readCountIdx != 0U)
                {
                    /* wait for receive ready or error */
                    while((I2CMasterIntStatusEx(hwAttrs->baseAddr,
                        I2C_INT_RECV_READY) == 0U) &&
                        (I2CMasterIntStatusEx(hwAttrs->baseAddr,
                        I2C_INT_ARBITRATION_LOST | I2C_INT_NO_ACK |
                        I2C_INT_STOP_CONDITION) == 0U))
                    {}

                    /* if we get an error, do a stop and return failure */
                    errStat=I2CMasterIntStatusEx(hwAttrs->baseAddr,
                        I2C_INT_ARBITRATION_LOST | I2C_INT_NO_ACK |
                        I2C_INT_STOP_CONDITION);
                    if(errStat) {
                       fatalError=1U;
                       break;

                    }
                    /* read byte and increase data pointer to next byte */
                    *(object->readBufIdx) =
                        (uint8_t)I2CMasterDataGet(hwAttrs->baseAddr);

                    object->readBufIdx++;
                    object->readCountIdx--;   /* update number of bytes read */
                }

                if ((errStat & I2C_INT_ARBITRATION_LOST) == I2C_INT_ARBITRATION_LOST)
                {
                    retVal = I2C_STS_ERR_ARBITRATION_LOST;
                }
                else if ((errStat & I2C_INT_NO_ACK) == I2C_INT_NO_ACK)
                {
                    retVal = I2C_STS_ERR_NO_ACK;
                }
                else
                {
                    retVal = I2C_STS_SUCCESS;
                 }
                /* generate stop when requested */
                I2CMasterStop(hwAttrs->baseAddr);

                /* wait for stop to happen */
                while(I2CMasterIntStatusEx(hwAttrs->baseAddr,
                    I2C_INT_STOP_CONDITION) == 0U)
                {}
            }
        }
    }
    /* In slave mode */
    else
    {
        /* clear all interrupts */
        I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_ALL_INTS);

        /* Currently slave mode is supported only when interrupt is enabled */
        if(I2C_OPER_MODE_POLLING != object->operMode)
        {
            /*
             * Enable Address as Slave interrupt which is the first interrupt
             * received in slave mode
             */
            I2CMasterIntEnableEx(hwAttrs->baseAddr, I2C_INT_MASK_ADRR_SLAVE);
            /* Configure data buffer length to 0 as the actual number of bytes to
               transmit/receive is dependant on external master. */
            I2CSetDataCount(hwAttrs->baseAddr, 0U);

            /* Start the I2C transfer in slave mode */
            I2CSlaveEnable(hwAttrs->baseAddr);

            /* set to master receiver mode */
            I2CModeControl(hwAttrs->baseAddr, I2C_CFG_MASK_XA, xsa);
        }
    }

    return retVal;
}

/*
 *  ======== I2C_transfer_v0 ========
 */
static int16_t I2C_transfer_v0(I2C_Handle handle,
                            I2C_Transaction *transaction)
{
    int16_t             retVal = I2C_STS_ERR;
    uint32_t            ret_flag = 0U;
    uint32_t            key;
    I2C_v0_Object      *object = NULL;
    I2C_HwAttrs const  *hwAttrs = NULL;
    SemaphoreP_Status  semStatus = SemaphoreP_OK;

    if ((handle != NULL) && (transaction != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (I2C_v0_Object*)handle->object;
        hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

        if ((transaction->validParams & I2C_TRANS_VALID_PARAM_MASTER_MODE) !=
            I2C_TRANS_VALID_PARAM_MASTER_MODE)
        {
            /*
             * masterMode valid param bit field is not set,
             * set masterMode to default mode (master)
             */
            transaction->masterMode = true;
        }

        if (transaction->timeout == 0)
        {
            /* timeout cannot be NO_WAIT, set it to default value */
            transaction->timeout = I2C_WAIT_FOREVER;
        }
    }
    else
    {
        ret_flag = 1U;
    }

    /* Check if anything needs to be written or read */
    if ((ret_flag == 0U) &&
        ((transaction->writeCount != 0U) || (transaction->readCount != 0U)))
    {
        if (object->operMode == I2C_OPER_MODE_CALLBACK) {
            /* Check if a transfer is in progress */
            key = I2C_osalHardwareIntDisable();
            if (object->headPtr) {
                /* Transfer in progress. Update the message pointed by the tailPtr
                 * to point to the next message in the queue
                 */
                object->tailPtr->nextPtr = transaction;

                /* Update the tailPtr to point to the last message */
                object->tailPtr = transaction;

                /* I2C is still being used */
                I2C_osalHardwareIntRestore(key);
                retVal = (int16_t)I2C_STS_SUCCESS;
                ret_flag = 1U;
            }
            else {
                /* Store the headPtr indicating I2C is in use */
                object->headPtr = transaction;
                object->tailPtr = transaction;
                I2C_osalHardwareIntRestore(key);
            }
        }

        if(ret_flag == 0U) {
            /* Acquire the lock for this particular I2C handle */
            I2C_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

            /*
             * I2CSubArtic_primeTransfer is a longer process and
             * protection is needed from the I2C interrupt
             */
            if (I2C_OPER_MODE_POLLING != object->operMode)
            {
                I2C_osalHardwareIntrDisable(hwAttrs->eventId,hwAttrs->intNum);
            }

            retVal = I2C_primeTransfer_v0(handle, transaction);

            if (I2C_OPER_MODE_POLLING != object->operMode)
            {
                I2C_osalHardwareIntrEnable(hwAttrs->eventId,hwAttrs->intNum);
            }

            if (object->operMode == I2C_OPER_MODE_BLOCKING) {
                I2C_drv_log1("\n I2C:(0x%x) Pending on transferComplete semaphore \n",
                    hwAttrs->baseAddr);

                /*
                 * Wait for the transfer to complete here.
                 * It's OK to block from here because the I2C's Hwi will unblock
                 * upon errors
                 */
                semStatus = I2C_osalPendLock(object->transferComplete, transaction->timeout);
				/* If interrupt is enabled and no specific call back routine is supplied by
				   the application, the error status is stored in object->intStatusErr.
				   Read it and return the error status accordingly */
		        if (object->intStatusErr & I2C_INT_NO_ACK)
                {
                   retVal = I2C_STS_ERR_NO_ACK;
		        } else if (object->intStatusErr & I2C_INT_ARBITRATION_LOST)
                { 
                   retVal = I2C_STS_ERR_ARBITRATION_LOST;
                } else {
                   retVal = I2C_STS_SUCCESS;
		        }
				
				if (semStatus == SemaphoreP_TIMEOUT) {
                 retVal = (int16_t)I2C_STS_ERR;
				}
				else{
					I2C_drv_log1("\n I2C:(0x%x) Transaction completed \n", hwAttrs->baseAddr);

					/* Hwi handle has posted a 'transferComplete' check for Errors */
					if (object->mode == I2C_IDLE_MODE) {
						I2C_drv_log1("\n I2C:(0x%x) Transfer OK \n", hwAttrs->baseAddr);
					}
				}
            }

            /* Release the lock for this particular I2C handle */
            I2C_osalPostLock(object->mutex);   
        } 
    }

    /* Return the number of bytes transferred by the I2C */
    return (retVal);
}

/*
 *  ======== I2C_transfer_Callback_v0 ========
 */
static void I2C_transfer_Callback_v0(I2C_Handle handle,
                                    I2C_Transaction *msg,
                                    int16_t transferStatus)
{
    I2C_v0_Object   *object;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object */
        object = (I2C_v0_Object*)handle->object;

        /* Indicate transfer complete */
        I2C_osalPostLock(object->transferComplete);
    }
}

/*
 *  ======== I2C_v0_control ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              I2C_control().
 */
static int32_t I2C_v0_control(I2C_Handle handle, uint32_t cmd, void *arg)
{
    int32_t status = I2C_STATUS_ERROR;

    /* Input parameter validation */
    if (handle != NULL)
    {
        status = I2C_STATUS_UNDEFINEDCMD;
    }

    return (status);
}
