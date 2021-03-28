/**
 *  \file   I2C_v1.c
 *
 *  \brief  IP version 1 specific I2C Driver APIs implementation.
 *
 *   This file contains the driver APIs for I2C controller.
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
#include <ti/drv/i2c/soc/I2C_v1.h>
#include <ti/csl/src/ip/i2c/V2/i2c.h>
#include <ti/csl/src/ip/i2c/V2/hw_i2c.h>
#include <ti/drv/i2c/src/I2C_osal.h>
#include <ti/drv/i2c/src/I2C_drv_log.h>
#include <ti/csl/hw_types.h>


#define I2C_MODULE_INTERNAL_CLK_4MHZ  (4000000U)
#define I2C_MODULE_INTERNAL_CLK_12MHZ (12000000U)

/*
 * Maximum number of loop count to handle in the same ISR, which is
 * to process multiple interrupts (ARDY, RRDY, XRDY) in the ISR to
 * reduce interrupt count
 *
 * Keep at least 3 to support optimal RX followed by TX scenario
 * Keep at least 2 to support optimal RX scenario
 */
#define I2C_MAX_CONSECUTIVE_ISRS      (1U)

/* I2C AM57x functions */
static void       I2C_close_v1(I2C_Handle handle);
static void       I2C_init_v1(I2C_Handle handle);
static I2C_Handle I2C_open_v1(I2C_Handle handle, const I2C_Params *params);
static int16_t       I2C_transfer_v1(I2C_Handle handle,
                                     I2C_Transaction *transaction);
static int16_t       I2C_primeTransfer_v1(I2C_Handle handle,
                                          I2C_Transaction *transaction);
static void       I2C_transfer_Callback_v1(I2C_Handle handle,
                                             I2C_Transaction *msg,
                                             int16_t transferStatus);
static int32_t    I2C_v1_control(I2C_Handle handle, uint32_t cmd, void *arg);
static int32_t    I2C_v1_waitForBb(uint32_t baseAddr, uint32_t timeout);
static void       I2C_v1_udelay(uint32_t delay);
static int32_t I2C_v1_setBusFrequency(I2C_Handle handle, uint32_t busFrequency);

static int32_t I2C_v1_recoverBus(I2C_Handle handle, uint32_t i2cDelay);
static int32_t I2C_v1_resetCtrl(I2C_Handle handle);
static int32_t I2C_v1_ctrlInit(I2C_Handle handle);
static uint32_t I2C_v1_waitForPin(I2C_Handle handle,
                                  uint32_t               flag,
                                  uint32_t               timeout,
                                  uint8_t               *timeOutStatus);

#define I2C_DELAY_MED     ((uint32_t) 10000U)
#define I2C_DELAY_BIG     ((uint32_t) 30000U)
#define I2C_DELAY_SMALL   ((uint32_t) 5000U)


/* I2C function table for I2C AM57x implementation */
const I2C_FxnTable I2C_v1_FxnTable = {
    &I2C_close_v1,
    &I2C_v1_control,
    &I2C_init_v1,
    &I2C_open_v1,
    &I2C_transfer_v1
};

/*
 *  ======== I2C_close_v1 ========
 */
static void I2C_close_v1(I2C_Handle handle)
{
    I2C_v1_Object      *object = NULL;
    I2C_HwAttrs const  *hwAttrs = NULL;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;
        object = (I2C_v1_Object*)handle->object;

        /* Check to see if a I2C transaction is in progress */
        if (object->headPtr == NULL)
        {
            /* Mask I2C interrupts */
            I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_INT_ALL);

            /* Disable the I2C Master */
            I2CMasterDisable(hwAttrs->baseAddr);

            if (I2C_OPER_MODE_POLLING != object->operMode)
            {
                if (hwAttrs->configSocIntrPath != NULL)
                {
                    (void)hwAttrs->configSocIntrPath((const void *)hwAttrs, FALSE);
                }

                /* Destruct the Hwi */
                (void)I2C_osalHardwareIntDestruct(object->hwi, (int32_t)hwAttrs->eventId);
            }

            /* Destruct the instance lock */
            (void)I2C_osalDeleteBlockingLock(object->mutex);

            if (I2C_OPER_MODE_BLOCKING == object->operMode)
            {
                /* Destruct the transfer completion lock */
                (void)I2C_osalDeleteBlockingLock(object->transferComplete);
            }


            object->isOpen = (bool)false;

            I2C_drv_log1("\n I2C: Object closed 0x%x \n", hwAttrs->baseAddr);
        }
    }
    return;
}
/*
 *  ======== Terminate the current transfer ========
 */
static void I2C_v1_complete_curr_transfer(I2C_Handle handle, int16_t xferStatus);  /*for misra warnings*/
static void I2C_v1_complete_curr_transfer(I2C_Handle handle, int16_t xferStatus)
{
	I2C_v1_Object     *object = (I2C_v1_Object*)handle->object;

	object->mode = I2C_IDLE_MODE;
	if(object->currentTransaction != NULL)
	{
	      object->currentTransaction->readCount -= object->readCountIdx;
	      object->currentTransaction->writeCount -= object->writeCountIdx;

	      /* Callback to application or post semaphore */
	      object->i2cParams.transferCallbackFxn(handle,
	                                            object->currentTransaction,
	                                            xferStatus);

	      /* See if we need to process any other transactions */
	      if (object->headPtr == object->tailPtr)
	      {
	          /* No other transactions need to occur */
	          object->currentTransaction = NULL;
	          object->headPtr = NULL;

	      }
	      else
	      {
	        /* Another transfer needs to take place */
	        object->headPtr = (I2C_Transaction*)(object->headPtr->nextPtr);

	         /* Start new transfer */
	        (void)I2C_primeTransfer_v1(handle, object->headPtr);
	      }
	}
}

/*
 *  ======== I2C_v1_hwiFxnMaster ========
 *  Hwi interrupt handler to service the I2C peripheral in master mode
 */
static void I2C_v1_hwiFxnMaster(I2C_Handle handle);   /* for misra warnings*/
static void I2C_v1_hwiFxnMaster(I2C_Handle handle)
{
    I2C_v1_Object     *object = NULL;
    I2C_HwAttrs const *hwAttrs = NULL;
    int16_t            xferStatus = I2C_STS_SUCCESS;
    uint32_t           isrLoopCount = 0;
    uint32_t           w;
    uint32_t           stat;
    uint32_t           rawStat;
    uint32_t           intErr = 0;
    uint32_t           fatalError = 0;
    uint32_t           xsa;
    uint32_t           regVal;
    uint32_t           loopFlag = TRUE;

    /* Get the pointer to the object and hwAttrs */
    object = (I2C_v1_Object*)handle->object;
    hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

    /*
     * Ack the stat in one go, but [R/X]RDY should be
     * acked after the data operation is complete.
     */

    /*
     * The Master ISR handling is based on AM5 TRM HS I2C Programming Guide
     * Section 24.1.5. The driver only enables [R/X]RDY and ARDY interrupts, and
     * ISR checks the raw interrupt status register to handle any fatal errors
     * (No Ack, arbitration lost, etc.). It also logs non fatal errors (TX underflow
     * RX overflow, etc.) internally. The ISR also handles restart condition (write
     * followed by a restart restart)
     *
     *
     * Keep looping till there are no pending interrupts.
     * This allows I2C_INT_ADRR_READY_ACESS to be processed in same ISR
     * as [R/X]RDY and reduce interrupt count.
     *
     */

    while (loopFlag == TRUE)
    {
        stat = I2CMasterIntStatus(hwAttrs->baseAddr);
        if ((0U == stat) || (isrLoopCount > I2C_MAX_CONSECUTIVE_ISRS))
        {
            loopFlag = FALSE;
        }
        else
        {
            isrLoopCount++;

            rawStat = I2CMasterIntRawStatus(hwAttrs->baseAddr);

            if ((rawStat & I2C_INT_NO_ACK) != 0U)
            {
                intErr   |= I2C_INT_NO_ACK;
                xferStatus = I2C_STS_ERR_NO_ACK;
                I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_NO_ACK);
                fatalError=1U;
            }
			
            if ((rawStat & I2C_INT_ARBITRATION_LOST) != 0U)
            {
                intErr   |= I2C_INT_ARBITRATION_LOST;
                xferStatus = I2C_STS_ERR_ARBITRATION_LOST;
 			    I2CMasterIntClearEx(hwAttrs->baseAddr,I2C_INT_ARBITRATION_LOST);
				fatalError=1U;
            }
			
            if ((rawStat & I2C_INT_ACCESS_ERROR) != 0U)
            {
                intErr   |= I2C_INT_ACCESS_ERROR;
                xferStatus = I2C_STS_ERR_ACCESS_ERROR;
 			    I2CMasterIntClearEx(hwAttrs->baseAddr,I2C_INT_ACCESS_ERROR);
 			    fatalError=1U;
            }

			if(fatalError != 0U)
			{
			   /* ISsue the stop condition*/
			   I2CMasterStop(hwAttrs->baseAddr);
			   I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_INT_ALL);
               object->intStatusErr |= intErr;
               I2C_v1_complete_curr_transfer(handle,xferStatus);
               break;
			}

	        w = stat & ~(I2C_INT_RECV_READY | I2C_INT_TRANSMIT_READY);
	        I2CMasterIntClearEx(hwAttrs->baseAddr, w);

	        if (((stat & I2C_INT_ADRR_READY_ACESS) == I2C_INT_ADRR_READY_ACESS) ||
	            ((stat & I2C_INT_BUS_FREE) == I2C_INT_BUS_FREE))
	        {
	            w = stat & (I2C_INT_RECV_READY | I2C_INT_TRANSMIT_READY);
	            I2CMasterIntClearEx(hwAttrs->baseAddr, w);

	            if (((object->writeCountIdx) == 0U) && ((object->readCountIdx) != 0U))
	            {
	                /* Start write completed, restart read, set read count */
	                I2CSetDataCount(hwAttrs->baseAddr, object->readCountIdx);

	                /*
	                 * Configure peripheral for I2C Receive mode,
	                 * do not send stop when sending restart
	                 */
	                if (object->currentTransaction->expandSA == (bool)true)
	                {
	                    /* enable the 10-bit address mode */
	                    xsa = I2C_CFG_10BIT_SLAVE_ADDR;
	                }
	                else
	                {
	                    /* enable the 7-bit address mode */
	                    xsa = I2C_CFG_7BIT_SLAVE_ADDR;
	                }
	                regVal = I2C_CFG_MST_RX | xsa;
	                if ((object->i2cParams.bitRate == I2C_1P0Mhz) || (object->i2cParams.bitRate == I2C_3P4Mhz))
	                {
	                    regVal |= I2C_CFG_HS_MOD;
	                }
	                I2CMasterControl(hwAttrs->baseAddr, regVal);

	                /* Enable RX interrupt to handle data received */
	                I2CMasterIntEnableEx(hwAttrs->baseAddr, I2C_INT_RECV_READY);

	                /* Start I2C peripheral in RX mode */
	                I2CMasterStart(hwAttrs->baseAddr);
	            }
	            else
	            {
	                if ((rawStat & I2C_INT_BUS_BUSY) != 0U)
	                {
	                    I2CMasterStop(hwAttrs->baseAddr);
	                    /* if bus still busy, enable bus free interrupt to wait for bus released */
	                    I2CMasterIntEnableEx(hwAttrs->baseAddr, I2C_INT_BUS_FREE);
	                }
	                else
	                {
	                    I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_INT_ALL);
	                    I2C_v1_complete_curr_transfer(handle,xferStatus);
	                }
	                loopFlag = FALSE;
	            }
	        }

	        if ((loopFlag == TRUE) && (0U == intErr))
	        {
	            if ((stat & I2C_INT_RECV_READY) != 0U)
	            {
	                /* Save the received data */
	                if (object->readBufIdx > 0U)
	                {
	                    *(object->readBufIdx) = I2CMasterDataGet(hwAttrs->baseAddr);
	                    object->readBufIdx++;
	                    object->readCountIdx--;
	                }

	                I2CMasterIntClearEx(hwAttrs->baseAddr,
	                                    (stat & I2C_INT_RECV_READY));
	            }

	            if ((stat & I2C_INT_TRANSMIT_READY) != 0U)
	            {
	                if (object->writeCountIdx != 0U)
	                {
	                    /*
	                     * Write data until FIFO is full or all data written.
	                     * The math below is: (DCOUNT - TXBUFSTAT) % 64 < TXBUFSIZE.
	                     */
	                    while (((object->writeCountIdx) != 0U) &&
	                        (((I2CDataCountGet(hwAttrs->baseAddr)
	                        - I2CBufferStatus(hwAttrs->baseAddr,
	                        I2C_TX_BUFFER_STATUS)) % 64U) < (((uint32_t)8U) <<
	                        I2CBufferStatus(hwAttrs->baseAddr,I2C_FIFO_DEPTH)))) {

	                        /* Write data into transmit FIFO */
	                        I2CMasterDataPut(hwAttrs->baseAddr,
	                                         *(object->writeBufIdx));
	                        (object->writeBufIdx)++;
	                        object->writeCountIdx--;
	                    }
	                }
	                else
	                {
	                    I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_INT_TRANSMIT_READY);
	                }

	                I2CMasterIntClearEx(hwAttrs->baseAddr,
	                                    (stat & I2C_INT_TRANSMIT_READY));
	            }
	        }

            if ((loopFlag == TRUE) && (0U == intErr))
            {
                if ((stat & I2C_INT_RECV_OVER_RUN) != 0U)
                {
                    intErr |= I2C_INT_RECV_OVER_RUN;
                }
                if ((stat & I2C_INT_TRANSMIT_UNDER_FLOW) != 0U)
                {
                     intErr |= I2C_INT_TRANSMIT_UNDER_FLOW;
                }
            }
        }
    }

    /* Save the interrupt status errors */
    object->intStatusErr |= intErr;
}

/*
 *  ======== I2C_v1_hwiFxnSlave ========
 *  Hwi interrupt handler to service the I2C peripheral in slave mode
 */
static void I2C_v1_hwiFxnSlave(I2C_Handle handle);   /* for misra warnings*/
static void I2C_v1_hwiFxnSlave(I2C_Handle handle)
{
    I2C_v1_Object     *object = NULL;
    I2C_HwAttrs const *hwAttrs = NULL;
    uint32_t           rawStat;

    /* Get the pointer to the object and hwAttrs */
    object = (I2C_v1_Object*)handle->object;
    hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

    /*
     *  ISR Handling of different events is as below in same order:
     *  1.  RRDY: Handle receive ready interrupt before AAS or ARDY interrupt,
     *      as If ISR delayed and restart or stop condition received then
     *      the data should be read first.
     *  2.  ARDY: In case of stop condition bus busy will be reset. If it is a
     *      restart condition bus busy will still be set.
     *  3.  AAS: In case of addressed as slave after transfer is initiated, it
     *      is a restart condition. Give the restart callback.
     *  4.  XRDY: Read application tx buffer and send data.
     *
     *  In case of restart hold the bus low till application gives next buffer.
     *  If the Buffers are overflowing or underflowing return error code
     *  accordingly. Application should call the abort transfer explicitly.
     */
    rawStat = I2CSlaveIntRawStatus(hwAttrs->baseAddr);
    
    if ((rawStat & I2C_INT_RECV_READY) != 0U)
    {
        /* Read from Rx register only when current transaction is ongoing */
        if (object->readCountIdx != 0U)
        {
            *(object->readBufIdx) = I2CMasterDataGet(hwAttrs->baseAddr);
            object->readBufIdx++;
            object->readCountIdx--;
            I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_RECV_READY);
        }
        else
        {
            /* Clear the RX data fifo */
            (void)I2CSlaveDataGet(hwAttrs->baseAddr);

            /* Clear all interrupts */
            I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);

            /* Disable STOP condition interrupt */
            I2CSlaveIntDisableEx(hwAttrs->baseAddr, I2C_INT_ALL);

			/* Finish the current transfer */
			I2C_v1_complete_curr_transfer(handle,I2C_STS_ERR);
        }
    }

    if ((rawStat & I2C_INT_ADRR_READY_ACESS) != 0U)
    {
        if ((rawStat & I2C_INT_BUS_BUSY) != 0U)
        {
            /* Clear Interrupt, Callback will be handled in ADDR_SLAVE */
            I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_ADRR_READY_ACESS);
        }
        else
        {
            /* This is end of current transfer */
            I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);
            object->mode = I2C_IDLE_MODE;
         
		    /* Finish the current transfer */
			I2C_v1_complete_curr_transfer(handle,I2C_STS_SUCCESS);
        }
    }

    if ((rawStat & I2C_INT_ADRR_SLAVE) != 0U)
    {
        if (object->mode == I2C_IDLE_MODE)
        {
            /* This is the first transfer initiation from master */
            /* Update the state to transfer started and Clear the Interrupt */
            object->mode = I2C_SLAVE_XFER_MODE;
            I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_ADRR_SLAVE);
        }
        else if (object->mode == I2C_SLAVE_XFER_MODE)
        {
            if ((object->writeCountIdx == 0U) && ((rawStat & I2C_INT_TRANSMIT_UNDER_FLOW) != 0U))
            {
                /*
                 * This is a restart condition, slave write count should be provided by
                 * application in the callback function
                 */

                /* Callback to application to restart read/write */
                object->i2cParams.transferCallbackFxn(handle,
                                                      object->currentTransaction,
                                                      I2C_STS_RESTART);
                object->writeBufIdx = (uint8_t*)(object->currentTransaction->writeBuf);
                object->writeCountIdx = (uint32_t)object->currentTransaction->writeCount;

                object->readBufIdx = (uint8_t*)(object->currentTransaction->readBuf);
                object->readCountIdx = (uint32_t)object->currentTransaction->readCount;
            }
            else
            {
            }

            object->mode = I2C_SLAVE_RESTART_MODE;
            I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_ADRR_SLAVE);
        }
        else
        {
            /* Control should not come here. Sphurious interrupt clear it. */
            I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_ADRR_SLAVE);
        }
    }

    if ((rawStat & I2C_INT_TRANSMIT_READY) != 0U)
    {
        if (object->mode == I2C_SLAVE_XFER_MODE)
        {
            if (object->writeCountIdx != 0U)
            {
                I2CMasterDataPut(hwAttrs->baseAddr, *(object->writeBufIdx));
                object->writeCountIdx--;
                object->writeBufIdx++;
                I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_TRANSMIT_READY);
            }
            else
            {
                /* Clear all interrupts */
                I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);

                /* Disable STOP condition interrupt */
                I2CSlaveIntDisableEx(hwAttrs->baseAddr, I2C_INT_ALL);



                object->readBufIdx = (uint8_t*)(object->currentTransaction->readBuf);
                object->readCountIdx = (uint32_t)object->currentTransaction->readCount;

                

				/* Post Semaphore to unblock transfer fxn */
                object->i2cParams.transferCallbackFxn(handle,
                                                      object->currentTransaction,
                                                     I2C_STS_ERR);

                /* See if we need to process any other transactions */
                if (object->headPtr == object->tailPtr) {
                    /* No other transactions need to occur */
                    object->currentTransaction = NULL;
                    object->headPtr = NULL;

                }
                else {
                    /* Another transfer needs to take place */
                    object->headPtr = (I2C_Transaction*)(object->headPtr->nextPtr);

                    /* Start new transfer */
                    (void)I2C_primeTransfer_v1(handle, object->headPtr);
                }
            }
        }
        else
        {
            if (object->writeCountIdx != 0U)
            {
                I2CMasterDataPut(hwAttrs->baseAddr, *(object->writeBufIdx));
                object->writeCountIdx--;
                object->writeBufIdx++;
                I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_TRANSMIT_READY);
            }
            else
            {
                /* Clear all interrupts */
                I2CSlaveIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);

                /* Disable STOP condition interrupt */
                I2CSlaveIntDisableEx(hwAttrs->baseAddr, I2C_INT_ALL);

                object->readBufIdx = (uint8_t*)(object->currentTransaction->readBuf);
                object->readCountIdx = (uint32_t)object->currentTransaction->readCount;

                /* Post Semaphore to unblock transfer fxn */
                object->i2cParams.transferCallbackFxn(handle,
                                                      object->currentTransaction,
                                                      I2C_STS_ERR);

                /* See if we need to process any other transactions */
                if (object->headPtr == object->tailPtr) {
                    /* No other transactions need to occur */
                    object->currentTransaction = NULL;
                    object->headPtr = NULL;

                }
                else {
                    /* Another transfer needs to take place */
                    object->headPtr = (I2C_Transaction*)(object->headPtr->nextPtr);

                    /* Start new transfer */
                    (void)I2C_primeTransfer_v1(handle, object->headPtr);
                }
            }
        }
    }

    return;
}

/*
 *  ======== I2C_v1_hwiFxn ========
 *  Hwi interrupt handler to service the I2C peripheral
 *
 *  The handler is a generic handler for a I2C object.
 */
static void I2C_v1_hwiFxn(uintptr_t arg);   /* for misra warnings*/
static void I2C_v1_hwiFxn(uintptr_t arg)
{
	I2C_Handle          handle = (I2C_Handle)arg;
    I2C_v1_Object      *object = NULL;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        object = (I2C_v1_Object *)handle->object;

        if (object->currentTransaction->masterMode)
        {
            I2C_v1_hwiFxnMaster(handle);
        }
        else
        {
            I2C_v1_hwiFxnSlave(handle);
        }
    }
    return;
}

/*
 *  ======== I2C_init_v1 ========
 */
static void I2C_init_v1(I2C_Handle handle)
{
    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Mark the object as available */
        ((I2C_v1_Object *)(handle->object))->isOpen = (bool)false;
    }
}


/*
 *  ======== I2C_open_v1 ========
 */
static I2C_Handle I2C_open_v1(I2C_Handle handle, const I2C_Params *params)
{
    SemaphoreP_Params   semParams;
    uintptr_t           key;
    uint32_t            outputClk;
    I2C_v1_Object      *object = NULL;
    I2C_HwAttrs const  *hwAttrs = NULL;
    uint32_t            internalClk;
    uint8_t             ret_flag = 0U;
    I2C_Handle          retHandle = handle;

    /* Input parameter validation */
    if (handle == NULL)
    {
        ret_flag = 1U;
    }
    else
    {
        /* Get the pointer to the object and hwAttrs */
        object = (I2C_v1_Object*)handle->object;
        hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;
    }

    /* Determine if the device index was already opened */
    key = I2C_osalHardwareIntDisable();
    if ((ret_flag == 1U)                ||
        (object->isOpen == (bool)true))
    {
        I2C_osalHardwareIntRestore(key);
        retHandle = NULL;
    }
    else
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
            if((bool)true == hwAttrs->enableIntr)
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
               OsalRegisterIntrParams_t interruptRegParams;

               if (hwAttrs->configSocIntrPath != NULL)
               {
                   /* setup the interrupt router path via DMSC */
                   (void)hwAttrs->configSocIntrPath((const void *)hwAttrs, TRUE);
               }

               /* Initialize with defaults */
               Osal_RegisterInterrupt_initParams(&interruptRegParams);

               /* Populate the interrupt parameters */
               interruptRegParams.corepacConfig.arg = (uintptr_t)handle;
               interruptRegParams.corepacConfig.name = NULL;
               interruptRegParams.corepacConfig.isrRoutine = &I2C_v1_hwiFxn;
               interruptRegParams.corepacConfig.corepacEventNum = (int32_t)hwAttrs->eventId; /* Event going in to CPU */
               interruptRegParams.corepacConfig.intVecNum = (int32_t)hwAttrs->intNum; /* Host Interrupt vector */

               /* Register interrupts */
               (void)I2C_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));
               if(object->hwi == NULL) {
                  I2C_drv_log("\n Error constructing I2C HWI object \n");
                  I2C_close_v1(handle);
                  retHandle = NULL;   /*to solve the MISRA.RETURN.NOT_LAST warning*/
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
          if (object->operMode == I2C_OPER_MODE_BLOCKING)
          {
             /*
              * Semaphore to cause the waiting task to block for the I2C
              * to finish
              */
             object->transferComplete = I2C_osalCreateBlockingLock(0, &semParams);

             /* Store internal callback function */
             object->i2cParams.transferCallbackFxn = &I2C_transfer_Callback_v1;
          }
          if(object->operMode == I2C_OPER_MODE_CALLBACK)
          {
             if (params != NULL)
             {
                /* Save the callback function pointer */
                object->i2cParams.transferCallbackFxn = params->transferCallbackFxn;
             }
          }

          /* Specify the idle state for this I2C peripheral */
          object->mode = I2C_IDLE_MODE;

          /* Clear the head pointer */
          object->headPtr = NULL;
          object->tailPtr = NULL;

          I2C_drv_log1("\n I2C: Object created 0x%x \n", hwAttrs->baseAddr);

          /* Put i2c in reset/disabled state */
          I2CMasterDisable(hwAttrs->baseAddr);

          /* Disable Auto Idle functionality */
          I2CAutoIdleDisable(hwAttrs->baseAddr);

          /* Extract bit rate from the input parameter */
          switch(object->i2cParams.bitRate)
          {
             case I2C_100kHz:
             {
                 outputClk = 100000U;
                 internalClk = I2C_MODULE_INTERNAL_CLK_4MHZ;
                 break;
             }

             case I2C_400kHz:
             {
                 outputClk = 400000U;
                 internalClk = I2C_MODULE_INTERNAL_CLK_12MHZ;
                 break;
             }

             case I2C_1P0Mhz:
             {
                 outputClk = 1000000U;
                 internalClk = I2C_MODULE_INTERNAL_CLK_12MHZ;
                 break;
             }

             case I2C_3P4Mhz:
             {
                 outputClk = 3400000U;
                 internalClk = I2C_MODULE_INTERNAL_CLK_12MHZ;
                 break;
             }

             default:
             {
                 /* Default case force it to 100 KHz bit rate */
                 outputClk = 100000U;
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
          I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);

          /* Mask off all interrupts */
          I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_INT_ALL);

          /* Enable the I2C Master for operation */
          I2CMasterEnable(hwAttrs->baseAddr);

          /* Enable free run mode */
          I2CMasterEnableFreeRun(hwAttrs->baseAddr);

          /* Return the address of the i2cObjectArray[i] configuration struct */
        }
    }
    return (retHandle);
}

/*
 *  ======== I2C_primeTransfer_v1 =======
 */
static int16_t I2C_primeTransfer_v1(I2C_Handle handle,
                                 I2C_Transaction *transaction)
{
    I2C_v1_Object  *object = NULL;
    I2C_HwAttrs const *hwAttrs = NULL;
    int16_t status = I2C_STS_SUCCESS;
    uint8_t timeoutStatus = 0;
    uint32_t errStat=0,fatalError=0;
    uint32_t regVal;
    uint32_t xsa;
	
    /* Get the pointer to the object and hwAttrs */
    object = (I2C_v1_Object*)handle->object;
    hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

    /* Store the new internal counters and pointers */
    object->currentTransaction = transaction;

    object->writeBufIdx = (uint8_t*)transaction->writeBuf;
    object->writeCountIdx = (uint32_t)transaction->writeCount;

    object->readBufIdx = (uint8_t*)transaction->readBuf;
    object->readCountIdx = (uint32_t)transaction->readCount;

    object->intStatusErr = 0;

    object->mode = I2C_IDLE_MODE;

    I2C_drv_log2("\n I2C:(0x%x) Starting transaction to slave: 0x%x \n",
        hwAttrs->baseAddr, object->currentTransaction->slaveAddress);

    /* clear all interrupts */
    I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);

    if (transaction->masterMode)
    {
        if (object->currentTransaction->expandSA == (bool)true)
        {
            /* enable the 10-bit address mode */
            xsa = I2C_CFG_10BIT_SLAVE_ADDR;
        }
        else
        {
            /* enable the 7-bit address mode */
            xsa = I2C_CFG_7BIT_SLAVE_ADDR;
        }

        /* In master mode, set the I2C slave address */
        I2CMasterSlaveAddrSet(hwAttrs->baseAddr,
                              object->currentTransaction->slaveAddress);

        if(I2C_OPER_MODE_POLLING != object->operMode)
        {
            /* Start transfer in Transmit mode */
            if (object->writeCountIdx != 0U)
            {
                /* Set number of bytes to be transmitting */
                I2CSetDataCount(hwAttrs->baseAddr, object->writeCountIdx);

                /*
                 * Configure the I2C transfer to be in master transmitter mode
                 */
                regVal = I2C_CFG_MST_TX | xsa;
                if ((object->readCountIdx) == 0U)
                {
                    /*
                     * if there is no read data, automatically send stop when write is complete
                     * otherwise (restart), do not send stop
                     */
                    regVal |= I2C_CFG_STOP;
                }

                if ((object->i2cParams.bitRate == I2C_1P0Mhz) || (object->i2cParams.bitRate == I2C_3P4Mhz))
                {
                    regVal |= I2C_CFG_HS_MOD;
                }
                I2CMasterControl(hwAttrs->baseAddr, regVal);

                regVal = I2C_INT_TRANSMIT_READY | I2C_INT_ADRR_READY_ACESS | I2C_INT_NO_ACK | I2C_INT_ARBITRATION_LOST;
                I2CMasterIntEnableEx(hwAttrs->baseAddr, regVal);

                /* Start the I2C transfer in master transmit mode */
                I2CMasterStart(hwAttrs->baseAddr);

                I2C_drv_log1("\n I2C:(0x%x) I2C_IDLE_MODE: -> I2C_WRITE_MODE; Writing w/ START \n",
                    hwAttrs->baseAddr);
            }
            else
            {
                /* Specify the number of bytes to read */
                I2CSetDataCount(hwAttrs->baseAddr, object->readCountIdx);

                /*
                 * Start the I2C transfer in master receive mode,
                 * and automatically send stop when done
                 */
                regVal = I2C_CFG_MST_RX | I2C_CFG_STOP | xsa;
                if ((object->i2cParams.bitRate == I2C_1P0Mhz) || (object->i2cParams.bitRate == I2C_3P4Mhz))
                {
                    regVal |= I2C_CFG_HS_MOD;
                }
                I2CMasterControl(hwAttrs->baseAddr, regVal);

                /* Enable RX interrupts */
                I2CMasterIntEnableEx(hwAttrs->baseAddr,
                                     I2C_INT_RECV_READY | I2C_INT_ADRR_READY_ACESS | I2C_INT_NO_ACK | I2C_INT_ARBITRATION_LOST);

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
                /* set number of bytes to write */
                I2CSetDataCount(hwAttrs->baseAddr, object->writeCountIdx);

                /* set to master transmitter mode */
                regVal = I2C_CFG_MST_TX | xsa;
                if ((object->i2cParams.bitRate == I2C_1P0Mhz) || (object->i2cParams.bitRate == I2C_3P4Mhz))
                {
                    regVal |= I2C_CFG_HS_MOD;
                }
                I2CMasterControl(hwAttrs->baseAddr, regVal);

                /* generate start */
                I2CMasterStart(hwAttrs->baseAddr);

                /* wait for bus busy */
                while(I2CMasterBusBusy(hwAttrs->baseAddr)==0)
                {
                }

                while(object->writeCountIdx != 0U)
                {
                    /* wait for transmit ready or error */
                    while((I2CMasterIntRawStatusEx(hwAttrs->baseAddr,
                        I2C_INT_TRANSMIT_READY) == 0U) &&
                        (I2CMasterIntRawStatusEx(hwAttrs->baseAddr,
                        I2C_INT_ARBITRATION_LOST | I2C_INT_NO_ACK |
                        I2C_INT_ACCESS_ERROR | I2C_INT_STOP_CONDITION ) == 0U))
                        {
                        }

                    errStat=I2CMasterIntRawStatusEx(hwAttrs->baseAddr,
                        I2C_INT_ARBITRATION_LOST | I2C_INT_NO_ACK |
                        I2C_INT_ACCESS_ERROR);

                    /* if we get an error, do a stop and return failure */
                    if (errStat != 0U)
                    /* if we get an error, do a stop and return failure */
                    {
                       fatalError=1U;
                       break;
                    }
                    /* write byte and increase data pointer to next byte */
                    I2CMasterDataPut(hwAttrs->baseAddr, *(object->writeBufIdx));
                    (object->writeBufIdx)++;

                    /* clear transmit ready interrupt */
                    I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_TRANSMIT_READY);

                    /* update number of bytes written */
                    object->writeCountIdx--;
                }
                

                if(fatalError == 0U) {
                   /* wait for register access ready */
                    (void)I2C_v1_waitForPin(handle,
                                            I2C_INT_ADRR_READY_ACESS,
                                            transaction->timeout,
                                            &timeoutStatus);
                }

                if ((errStat & I2C_INT_ARBITRATION_LOST) == I2C_INT_ARBITRATION_LOST)
                {
                    status = I2C_STS_ERR_ARBITRATION_LOST;
                }
                else if ((errStat & I2C_INT_NO_ACK) == I2C_INT_NO_ACK)
                {
                    status = I2C_STS_ERR_NO_ACK;
                }
                else if ((errStat & I2C_INT_ACCESS_ERROR) == I2C_INT_ACCESS_ERROR)
                {
                    status = I2C_STS_ERR_ACCESS_ERROR;
                }
                else if (timeoutStatus==(uint8_t)1U)
                {
                    status = I2C_STS_ERR_TIMEOUT;
                }
                else
                {
                    status = I2C_STS_SUCCESS;
                }

                if (object->readCountIdx == 0U)
                {
                    /* generate stop when there is no read following by write */
                    I2CMasterStop(hwAttrs->baseAddr);

                    /* wait for stop to happen */
                    (void)I2C_v1_waitForPin(handle,
                                            I2C_INT_STOP_CONDITION,
                                            transaction->timeout,
                                            &timeoutStatus);

                    
                    /* wait for register access ready */
                    (void)I2C_v1_waitForPin(handle,
                                            I2C_INT_ADRR_READY_ACESS,
                                            transaction->timeout,
                                            &timeoutStatus);

                    if(((uint8_t)1U) == timeoutStatus) {
                       status = I2C_STS_ERR_TIMEOUT;
                    }
                }
            }

            if ((object->readCountIdx != 0U) && (status==I2C_STS_SUCCESS))
            {
                /* clear all interrupts */
                I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);

                /* set number of bytes to read */
                I2CSetDataCount(hwAttrs->baseAddr, object->readCountIdx);

                /* set to master receiver mode */
                regVal = I2C_CFG_MST_RX | xsa;
                if ((object->i2cParams.bitRate == I2C_1P0Mhz) || (object->i2cParams.bitRate == I2C_3P4Mhz))
                {
                    regVal |= I2C_CFG_HS_MOD;
                }
                I2CMasterControl(hwAttrs->baseAddr, regVal);

                /* generate start */
                I2CMasterStart(hwAttrs->baseAddr);

                /* wait for bus not busy */
                while(I2CMasterBusBusy(hwAttrs->baseAddr)==0)
                {
                }

                while(object->readCountIdx != 0U)
                {
                    /* wait for receive ready or error */
                    while((I2CMasterIntRawStatusEx(hwAttrs->baseAddr,
                        I2C_INT_RECV_READY) == 0U) &&
                        (I2CMasterIntRawStatusEx(hwAttrs->baseAddr,
                        I2C_INT_ARBITRATION_LOST | I2C_INT_NO_ACK |
                        I2C_INT_ACCESS_ERROR ) == 0U))
                        {
                        }

                    errStat=I2CMasterIntRawStatusEx(hwAttrs->baseAddr,
                        I2C_INT_ARBITRATION_LOST | I2C_INT_NO_ACK |
                        I2C_INT_ACCESS_ERROR);

                    /* if we get an error, do a stop and return failure */
                    if (errStat != 0U)
                    {
                       fatalError=1U;
                       break;
                    }

                    /* read byte and increase data pointer to next byte */
                    *(object->readBufIdx) =
                        (uint8_t)I2CMasterDataGet(hwAttrs->baseAddr);

                    /* clear receive ready interrupt */
                    I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_RECV_READY);

                    object->readBufIdx++;
                    object->readCountIdx--;   /* update number of bytes read */
                }
                
                if(fatalError == 0U) {
                    /* wait for register access ready */
                    (void)I2C_v1_waitForPin(handle,
                                            I2C_INT_ADRR_READY_ACESS,
                                            transaction->timeout,
                                            &timeoutStatus);
                }

            if ((errStat & I2C_INT_ARBITRATION_LOST) == I2C_INT_ARBITRATION_LOST)
            {
                status = I2C_STS_ERR_ARBITRATION_LOST;
            }
            else if ((errStat & I2C_INT_NO_ACK) == I2C_INT_NO_ACK)
            {
                status = I2C_STS_ERR_NO_ACK;
            }
            else if ((errStat & I2C_INT_ACCESS_ERROR) == I2C_INT_ACCESS_ERROR)
            {
                status = I2C_STS_ERR_ACCESS_ERROR;
            }
            else if (timeoutStatus == (uint8_t)1U)
            {
                status = I2C_STS_ERR_TIMEOUT;
            }
            else
            {
                status = I2C_STS_SUCCESS;
            }

            /* generate stop when requested */
            I2CMasterStop(hwAttrs->baseAddr);

                    /* wait for stop to happen */
            (void)I2C_v1_waitForPin(handle,
                                    I2C_INT_STOP_CONDITION,
                                    transaction->timeout,
                                    &timeoutStatus);
                
            /* wait for register access ready */
            (void)I2C_v1_waitForPin(handle,
                                    I2C_INT_ADRR_READY_ACESS,
                                    transaction->timeout,
                                    &timeoutStatus);

             if(((uint8_t)1U) == timeoutStatus) {
               status = I2C_STS_ERR_TIMEOUT;
            }
             
        }
      }
    }
    /* In slave mode */
    else
    {
        if (object->currentTransaction->expandSA == (bool)true)
        {
            /* enable the 10-bit address mode */
            xsa = I2C_CFG_10BIT_OWN_ADDR_0;
        }
        else
        {
            /* enable the 7-bit address mode */
            xsa = I2C_CFG_7BIT_OWN_ADDR_0;
        }

        /* Currently slave mode is supported only when interrupt is enabled */
        if(I2C_OPER_MODE_POLLING != object->operMode)
        {
            /* In slave mode, set the I2C own address */
            I2COwnAddressSet(hwAttrs->baseAddr,
                             hwAttrs->ownSlaveAddr[0],
                             I2C_OWN_ADDR_0);

            /* Configure data buffer length to 0 as the actual number of bytes to
               transmit/receive is dependant on external master. */
            I2CSetDataCount(hwAttrs->baseAddr, 0U);

            /* Enable interrupts in slave mode */
            I2CSlaveIntEnableEx(hwAttrs->baseAddr,
                                I2C_INT_TRANSMIT_READY | I2C_INT_RECV_READY |
                                I2C_INT_ADRR_READY_ACESS | I2C_INT_ADRR_SLAVE);

            /* Start the I2C transfer in slave mode */
            regVal = I2C_CFG_MST_ENABLE | xsa;
            if ((object->i2cParams.bitRate == I2C_1P0Mhz) || (object->i2cParams.bitRate == I2C_3P4Mhz))
            {
                regVal |= I2C_CFG_HS_MOD;
            }
            I2CMasterControl(hwAttrs->baseAddr, regVal);
        }
    }

    return status;
}

/*
 *  ======== I2C_transfer_v1 ========
 */
static int16_t I2C_transfer_v1(I2C_Handle handle,
                            I2C_Transaction *transaction)
{
    int16_t             retVal = I2C_STS_ERR;
    uint8_t             ret_flag = 0U;
    uintptr_t           key;
    I2C_v1_Object      *object = NULL;
    I2C_HwAttrs const  *hwAttrs = NULL;
    SemaphoreP_Status   semStatus;

    if ((handle != NULL) && (transaction != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (I2C_v1_Object*)handle->object;
        hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

        if ((transaction->validParams & I2C_TRANS_VALID_PARAM_MASTER_MODE) == 0U)
        {
            /*
             * masterMode valid param bit field is not set,
             * set masterMode to default mode (master)
             */
            transaction->masterMode = (bool)true;
        }

        if ((transaction->validParams & I2C_TRANS_VALID_PARAM_EXPAND_SA) == 0U)
        {
            /*
             * expandSA valid param bit field is not set,
             * set to 7-bit address mode by default
             */
            transaction->expandSA = (bool)false;
        }

        if (transaction->timeout == 0U)
        {
            /* timeout cannot be NO_WAIT, set it to default value */
            transaction->timeout = I2C_WAIT_FOREVER;
        }
    }
    else
    {
        ret_flag = 1U;
    }

    if ((ret_flag == 0U) &&
        ((transaction->writeCount != 0U) ||
         (transaction->readCount != 0U)))
    {
        if (object->operMode == I2C_OPER_MODE_CALLBACK)
        {
            /* Check if a transfer is in progress */
            key = I2C_osalHardwareIntDisable();
            if (object->headPtr != NULL)
            {
                /* Transfer in progress. Update the message pointed by the tailPtr
                 * to point to the next message in the queue
                 */
                object->tailPtr->nextPtr = transaction;

                /* Update the tailPtr to point to the last message */
                object->tailPtr = transaction;

                /* I2C is still being used */
                I2C_osalHardwareIntRestore(key);
                retVal = I2C_STS_SUCCESS;
                ret_flag = 1U;
            }
            else
            {
                /* Store the headPtr indicating I2C is in use */
                object->headPtr = transaction;
                object->tailPtr = transaction;
                I2C_osalHardwareIntRestore(key);
            }
        }

        if(ret_flag == 0U)
        {
            /* Acquire the lock for this particular I2C handle */
            (void)I2C_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

            /*
             * Clear the RX + TX FIFOs. If the previous transfer failed due to an error,
             * there's a possibility data could still be in the FIFO.
             */
            I2CFIFOClear(hwAttrs->baseAddr, I2C_TX_MODE);
            I2CFIFOClear(hwAttrs->baseAddr, I2C_RX_MODE);
            /*
             * I2CSubArtic_primeTransfer is a longer process and
             * protection is needed from the I2C interrupt
             */
            if (I2C_OPER_MODE_POLLING != object->operMode)
            {
                I2C_osalHardwareIntrDisable((int32_t)hwAttrs->eventId, (int32_t)hwAttrs->intNum);
            }

            retVal = I2C_primeTransfer_v1(handle, transaction);

            if (I2C_OPER_MODE_POLLING != object->operMode)
            {
                I2C_osalHardwareIntrEnable((int32_t)hwAttrs->eventId, (int32_t)hwAttrs->intNum);
            }
            if (object->operMode == I2C_OPER_MODE_BLOCKING)
            {
                I2C_drv_log1("\n I2C:(0x%x) Pending on transferComplete semaphore \n",
                             hwAttrs->baseAddr);
                /*
                  * Wait for the transfer to complete here.
                  * It's OK to block from here because the I2C's Hwi will unblock
                  * upon errors
                  */
                semStatus = I2C_osalPendLock(object->transferComplete, transaction->timeout);
                if (semStatus == SemaphoreP_TIMEOUT)
                {
                    /* Transaction timed out */
                    retVal = I2C_STS_ERR_TIMEOUT;
                    (void)I2C_v1_recoverBus(handle, I2C_DELAY_SMALL);
                }
                else
                {
                    /* Hwi handle has posted a 'transferComplete' check for Errors */
                    if (object->mode == I2C_IDLE_MODE)
                    {
                        I2C_drv_log1("\n I2C:(0x%x) Transfer OK \n", hwAttrs->baseAddr);
                    }
                    if ((object->intStatusErr & I2C_INT_ARBITRATION_LOST) != 0U)
                    {
                        retVal = I2C_STS_ERR_ARBITRATION_LOST;
                    }
                    else if ((object->intStatusErr & I2C_INT_NO_ACK) != 0U)
                    {
                        retVal = I2C_STS_ERR_NO_ACK;
                    }
                    else if ((object->intStatusErr & I2C_INT_ACCESS_ERROR) != 0U)
                    {
                        retVal = I2C_STS_ERR_ACCESS_ERROR;
                    }
                    else
                    {
                        retVal = I2C_STS_SUCCESS;
                    }
                }
            }
            /* Release the lock for this particular I2C handle */
            (void)I2C_osalPostLock(object->mutex);
        }
    }

    return (retVal);
}

/*
 *  ======== I2C_transfer_Callback_v1 ========
 */
static void I2C_transfer_Callback_v1(I2C_Handle handle,
                                    I2C_Transaction *msg,
                                    int16_t transferStatus)
{
    I2C_v1_Object   *object;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object */
        object = (I2C_v1_Object *)handle->object;

        /* Indicate transfer complete */
        (void)I2C_osalPostLock(object->transferComplete);
        msg = msg;
        (void)transferStatus;
    }
}

/*
 *  ======== I2C_v1_control ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              I2C_control().
 */
static int32_t I2C_v1_control(I2C_Handle handle, uint32_t cmd, void *arg)
{
    int32_t             retVal = I2C_STATUS_ERROR;
    uint32_t            regVal;
    I2C_HwAttrs const  *hwAttrs = NULL;
    I2C_v1_Object      *object = NULL;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to hwAttrs */
        hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;
        object  = (I2C_v1_Object*)handle->object;

        switch (cmd)
        {
            case I2C_CMD_PROBE:
            {
                uint32_t slaveAddr = *((uint32_t *) arg);

                /* Disable interrupts first */
                regVal = I2CGetEnabledIntStatus(hwAttrs->baseAddr, I2C_INT_ALL);

                I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_INT_ALL);

                /* wait until bus not busy */
                if (I2C_v1_waitForBb(hwAttrs->baseAddr, I2C_DELAY_MED) != I2C_STATUS_SUCCESS)
                {
                    retVal = I2C_STATUS_ERROR;
                }
                else
                {
                    /* set slave address */
                    I2CMasterSlaveAddrSet(hwAttrs->baseAddr, (uint32_t) slaveAddr);

                    /* try to write one byte */
                    I2CMasterDataPut(hwAttrs->baseAddr, (uint8_t) 0U);
                    I2CSetDataCount(hwAttrs->baseAddr, (uint32_t) 1U);

                    /* stop bit needed here */
                    I2CConfig(hwAttrs->baseAddr,
                              (I2C_CFG_MST_ENABLE | I2C_CFG_MST_TX | I2C_CFG_START |
                               I2C_CFG_STOP));

                    /* enough delay for the NACK bit set */
                    I2C_v1_udelay(I2C_DELAY_BIG);

                    if (0U == I2CMasterIntRawStatusEx(hwAttrs->baseAddr, I2C_INT_NO_ACK))
                    {
                        retVal = I2C_STATUS_SUCCESS;        /* success case */
                    }
                    else
                    {
                        /* Clear sources*/
                        I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);

                        /* finish up xfer */
                        I2CMasterStop(hwAttrs->baseAddr);
                        (void)I2C_v1_waitForBb(hwAttrs->baseAddr, I2C_DELAY_MED);

                        retVal = I2C_STATUS_ERROR;         /* Error case */
                    }

                    I2CFIFOClear(hwAttrs->baseAddr, I2C_TX_MODE);
                    I2CFIFOClear(hwAttrs->baseAddr, I2C_RX_MODE);
                    I2CSetDataCount(hwAttrs->baseAddr, 0);
                    I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);
                }

                /* wait for bus free */
                if (I2C_v1_waitForBb(hwAttrs->baseAddr, I2C_DELAY_MED) != I2C_STATUS_SUCCESS)
                {
                    retVal = I2C_STATUS_ERROR;
                }

                /* Enable interrupts now */
                I2CMasterIntEnableEx(hwAttrs->baseAddr, regVal);

                break;
            }

            case I2C_CMD_SET_BUS_FREQUENCY:
            {
                uint32_t busFrequency = *((uint32_t *) arg);

                /* Acquire the lock for this particular I2C handle */
                (void)I2C_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

                /* Set the required bus frequency */
                retVal = I2C_v1_setBusFrequency(handle, busFrequency);

                /* Release the lock for this particular I2C handle */
                (void)I2C_osalPostLock(object->mutex);

                break;
            }

            case I2C_CMD_RECOVER_BUS:
            {
                uint32_t i2cDelay = *((uint32_t *) arg);

                /* Acquire the lock for this particular I2C handle */
                (void)I2C_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

                /* perform Bus recovery */
                retVal = I2C_v1_recoverBus(handle, i2cDelay);

                /* Release the lock for this particular I2C handle */
                (void)I2C_osalPostLock(object->mutex);

                break;
            }

            default:
            {
                retVal = I2C_STATUS_UNDEFINEDCMD;
                arg = arg;
                break;
            }
        }
    }
    return (retVal);
}

static int32_t I2C_v1_waitForBb(uint32_t baseAddr, uint32_t timeout)
{
    uint32_t            stat;
    int32_t             retVal = I2C_STATUS_SUCCESS;
    volatile uint32_t   bbtimeout = timeout;

    if(bbtimeout > 0U)
    {
        /* Clear current interrupts...*/
        I2CMasterIntClearEx(baseAddr, I2C_INT_ALL);

    while (bbtimeout > 0U)
    {
        stat = I2CMasterIntRawStatusEx(baseAddr, I2C_INT_BUS_BUSY);
        if (stat == 0U)
        {
            break;
        }
        bbtimeout = bbtimeout - 1U;
        I2CMasterIntClearEx(baseAddr, stat);
    }

    if (timeout > 0U)
    {
        if (bbtimeout == 0U)
        {
            retVal = I2C_STATUS_ERROR;
        }
    }

        /* clear delayed stuff*/
        I2CMasterIntClearEx(baseAddr, I2C_INT_ALL);
    }
    else
    {
        while(I2CMasterBusBusy(baseAddr)==0)
        {
        }
    }

    return retVal;
}

static void I2C_v1_udelay(uint32_t delay)
{
    volatile uint32_t del = delay;

    while (del != 0U)
    {
        del = del - 1U;
    }
}

static int32_t I2C_v1_setBusFrequency(I2C_Handle handle, uint32_t busFrequency)
{
    int32_t retVal = I2C_STATUS_SUCCESS;
    I2C_HwAttrs const  *hwAttrs = NULL;
    uint32_t          outputClk = 0;
    uint32_t          internalClk = 0;

    /* Input parameter validation */
    if(NULL != handle)
    {
        /* Get the pointer to the object and hwAttrs */
         hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

        /* Put i2c in reset/disabled state */
        I2CMasterDisable(hwAttrs->baseAddr);

        /* Extract bit rate from the input parameter */
        switch(busFrequency)
        {
           case (uint32_t)I2C_100kHz:
           {
               outputClk = 100000U;
               internalClk = I2C_MODULE_INTERNAL_CLK_4MHZ;
               break;
           }

           case (uint32_t)I2C_400kHz:
           {
               outputClk = 400000U;
               internalClk = I2C_MODULE_INTERNAL_CLK_12MHZ;
               break;
           }
           default:
           {
               outputClk = 100000U;
               internalClk = I2C_MODULE_INTERNAL_CLK_4MHZ;
               break;
           }
        }

        /* Set the I2C configuration */
        I2CMasterInitExpClk(hwAttrs->baseAddr, hwAttrs->funcClk, internalClk,
            outputClk);

        /* Clear any pending interrupts */
        I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);

        /* Mask off all interrupts */
        I2CMasterIntDisableEx(hwAttrs->baseAddr, I2C_INT_ALL);

        /* Enable the I2C Master for operation */
        I2CMasterEnable(hwAttrs->baseAddr);

        /* Enable free run mode */
        I2CMasterEnableFreeRun(hwAttrs->baseAddr);

        retVal = I2C_STATUS_SUCCESS;
    }
    else
    {
        retVal = I2C_STATUS_ERROR;
    }

    return retVal;
}

/*
 *  ======== I2C_v1_recoverBus ========
 */
static int32_t I2C_v1_recoverBus(I2C_Handle handle, uint32_t i2cDelay)
{
    I2C_HwAttrs const  *hwAttrs = NULL;
    I2C_v1_Object   *object = NULL;
    int32_t status = I2C_STATUS_SUCCESS;
    uint32_t sysTest, i;

    if(handle == NULL)
    {
        status = I2C_STATUS_ERROR;
    }
    if(I2C_STATUS_SUCCESS == status)
    {
        /* Get the pointer to hwAttrs */
        object = (I2C_v1_Object*)handle->object;
        hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

        if((object == NULL)&&(hwAttrs == NULL))
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

        sysTest = I2CMasterGetSysTest(hwAttrs->baseAddr);
        if ((sysTest & I2C_SYSTEST_SCL_I_FUNC_MASK) == 0U)
        {
            /* SCL is stuck low reset the I2C IP */
            status = I2C_v1_resetCtrl(handle);
        }
        else if ((sysTest & I2C_SYSTEST_SDA_I_FUNC_MASK) == 0U)
        {
            /* SDA is stuck low generate 9 clk pulses on SCL */
            /* switch to system test mode */
            HW_SET_FIELD32(sysTest, I2C_SYSTEST_ST_EN, I2C_SYSTEST_ST_EN_ENABLE);
            HW_SET_FIELD32(sysTest, I2C_SYSTEST_TMODE,
                           I2C_SYSTEST_TMODE_LOOPBACK);
            I2CMasterSetSysTest(hwAttrs->baseAddr, sysTest);
            for (i = 0; i < 9U; i++)
            {
                HW_SET_FIELD32(sysTest, I2C_SYSTEST_SCL_O,
                               I2C_SYSTEST_SCL_O_SCLOH);
                I2CMasterSetSysTest(hwAttrs->baseAddr, sysTest);
                I2C_v1_udelay(i2cDelay);
                HW_SET_FIELD32(sysTest, I2C_SYSTEST_SCL_O,
                               I2C_SYSTEST_SCL_O_SCLOL);
                I2CMasterSetSysTest(hwAttrs->baseAddr, sysTest);
                I2C_v1_udelay(i2cDelay);
            }
            /* Switch back to functional mode */
            HW_SET_FIELD32(sysTest, I2C_SYSTEST_ST_EN,
                           I2C_SYSTEST_ST_EN_DISABLE);
            HW_SET_FIELD32(sysTest, I2C_SYSTEST_TMODE,
                           I2C_SYSTEST_TMODE_FUNCTIONAL);
            I2CMasterSetSysTest(hwAttrs->baseAddr, sysTest);
            /* Now check if the SDA is releases. If its still stuck low,
             * There is nothing that can be done. We still try to reset our IP.
             */
            sysTest = I2CMasterGetSysTest(hwAttrs->baseAddr);
            if ((sysTest & I2C_SYSTEST_SDA_I_FUNC_MASK) == 0U)
            {
                status = I2C_v1_resetCtrl(handle);
            }
        }
        else
        {
            /* Nothing to be done. SCA and SDA both are not stuck to low */
        }
    }
    return status;
}


/*
 *  ======== I2C_v1_resetCtrl ========
 */
static int32_t I2C_v1_resetCtrl(I2C_Handle handle)
{
    I2C_HwAttrs const  *hwAttrs = NULL;
    I2C_v1_Object   *object = NULL;
    int32_t status = I2C_STATUS_SUCCESS;

    if(handle == NULL)
    {
        status = I2C_STATUS_ERROR;
    }
    if(I2C_STATUS_SUCCESS == status)
    {
        /* Get the pointer to hwAttrs */
        object = (I2C_v1_Object*)handle->object;
        hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;
        if((object == NULL) || (hwAttrs == NULL))
        {
            status = I2C_STATUS_ERROR;
        }
    }

    if (I2C_STATUS_SUCCESS == status)
    {
        status = I2C_v1_ctrlInit(handle);
    }

    return status;
}

/*
 *  ======== I2C_v1_ctrlInit ========
 */
static int32_t I2C_v1_ctrlInit(I2C_Handle handle)
{
    I2C_HwAttrs const  *hwAttrs = NULL;
    I2C_v1_Object      *object = NULL;
    uint32_t             delay = 50U;
    uint32_t             outputClk;
    uint32_t             internalClk;
    uint32_t             regVal;
    int32_t retVal = I2C_STATUS_SUCCESS;

    /* Get the pointer to hwAttrs */
    object = (I2C_v1_Object*)handle->object;
    hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

    /* Do a software reset */
    I2CSoftReset(hwAttrs->baseAddr);

    /* Enable i2c module */
    I2CMasterEnable(hwAttrs->baseAddr);

    /* Wait for the reset to get complete  -- constant delay - 50ms */
    while ((I2CSystemStatusGet(hwAttrs->baseAddr) == 0U) && (delay != 0U))
    {
        delay--;
        I2C_v1_udelay(I2C_DELAY_SMALL);
    }

    if (delay == 0U)
    {
        /* reset has failed, return!!! */
        retVal = I2C_STATUS_ERROR;
    }
    else
    {
        /* Put i2c in reset/disabled state */
        I2CMasterDisable(hwAttrs->baseAddr);

        /* Configure i2c bus speed*/
        switch(object->i2cParams.bitRate)
        {
           case I2C_100kHz:
           {
               outputClk = 100000U;
               internalClk = I2C_MODULE_INTERNAL_CLK_4MHZ;
               break;
           }

           case I2C_400kHz:
           {
               outputClk = 400000U;
               internalClk = I2C_MODULE_INTERNAL_CLK_12MHZ;
               break;
           }

           case I2C_1P0Mhz:
           {
               outputClk = 3400000U;
               internalClk = I2C_MODULE_INTERNAL_CLK_12MHZ;
               break;
           }

           default:
           {
               /* Default case force it to 100 KHz bit rate */
               outputClk = 100000U;
               internalClk = I2C_MODULE_INTERNAL_CLK_4MHZ;
           }
           break;
        }

        /* Set the I2C configuration */
        I2CMasterInitExpClk(hwAttrs->baseAddr,
                  hwAttrs->funcClk,
                  internalClk,
                  outputClk);


        /**
         * Configure I2C_SYSC params
         * Disable auto idle mode
         * Both OCP and systen clock cut off
         * Wake up mechanism disabled
         * No idle mode selected
         */
        regVal = I2C_AUTOIDLE_DISABLE | I2C_CUT_OFF_BOTH_CLK |
                 I2C_ENAWAKEUP_DISABLE | I2C_NO_IDLE_MODE;
        I2CSyscInit(hwAttrs->baseAddr, regVal);

        /* Configure I2C_CON params */
        regVal = I2C_OPMODE_FAST_STAND_MODE | I2C_NORMAL_MODE;
        I2CConfig(hwAttrs->baseAddr, regVal);

        /* Take the I2C module out of reset: */
        I2CMasterEnable(hwAttrs->baseAddr);

        /* Enable free run mode */
        I2CMasterEnableFreeRun(hwAttrs->baseAddr);
    }

    /*Clear status register */
    I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);

    return retVal;
}

/*
 *  ======== I2C_v1_waitForPin ========
 */
static uint32_t I2C_v1_waitForPin(I2C_Handle handle,
                                  uint32_t               flag,
                                  uint32_t               timeout,
                                  uint8_t               *timeOutStatus)
{
    uint32_t          status = 0;
    I2C_HwAttrs const  *hwAttrs = NULL;
    volatile uint32_t pinTimeout = timeout;

    *timeOutStatus = 0;

    /* Get the pointer to hwAttrs */
    hwAttrs = (I2C_HwAttrs const *)handle->hwAttrs;

    /*  For backware compatibility. Perform timeout check if value is greater
     *  than 0 only.
     */
    if(pinTimeout > 0U)
    {
        status = I2CMasterIntRawStatus(hwAttrs->baseAddr);
        while ((uint32_t) 0U == (status & flag))
        {
            if ((uint32_t) 0U != pinTimeout)
            {
                status = I2CMasterIntRawStatus(hwAttrs->baseAddr);
                pinTimeout = pinTimeout - 1U;
            }
            else
            {
                break;
            }
        }

        if (0U != timeout)
        {
            if (pinTimeout == 0U)
            {
                *timeOutStatus = (uint8_t)1U;
                I2CMasterIntClearEx(hwAttrs->baseAddr, I2C_INT_ALL);
            }
        }
    }
    else
    {
        while(I2CMasterIntRawStatusEx(hwAttrs->baseAddr, flag) == 0U)
        {
        }
    }

    return status;
}
