/**
 *  \file   ESPI_v2.c
 *
 *  \brief  ESPI IP Version 2 specific driver APIs implementation.
 *
 *   This file contains the driver APIs for ESPI controller.
 */

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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
#include <stddef.h>
#include <stdbool.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/MCSPI.h>
#include <ti/drv/spi/soc/SPI_v1.h>
#include <ti/drv/spi/soc/ESPI_v2.h>
#include <ti/drv/spi/src/SPI_osal.h>
#include <ti/drv/spi/firmware/icss_espi/include/icss_espi.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/**
 * NOTE: MCSPI handles are used, but currently this implementation only supports one channel
 *       so the MCSPI stuff is effectively just a shell for SPI handles for now.
 */

/* ESPI "single" functions */
static void 	     ESPI_initSingle_v2(SPI_Handle handle);

/* ESPI V2 functions */
static void          ESPI_close_v2(MCSPI_Handle mcHandle);
static void          ESPI_init_v2(MCSPI_Handle mcHandle);
static MCSPI_Handle    ESPI_open_v2(MCSPI_Handle mcHandle, const MCSPI_Params *params);
static bool          ESPI_transfer_v2(MCSPI_Handle mcHandle,
				      SPI_Transaction *transaction);
static void          ESPI_transferCancel_v2(MCSPI_Handle mcHandle);
static int32_t       ESPI_control_v2(MCSPI_Handle mcHandle, uint32_t cmd, const void *arg);

static void	     ESPI_v2_gpioCallbackFxn0(void);
static void	     ESPI_v2_hwiFxn(uintptr_t arg);
static int32_t	     ESPI_v2_setupPinMux(SPI_Handle handle);
static void	     ESPI_v2_pruGPIOMuxConfig(ESPI_PRU_IOPinMuxAttrs *handle, uint32_t pinMode);
static int32_t	     ESPI_v2_pruIcssInit(SPI_Handle handle);
static int32_t	     ESPI_v2_initPruCore(PRUSS_PruCores pruInst, PRUICSS_Handle pruIcssHandle,
					 const ICSS_Mem_Ptr *icssMemBuffer);
static int32_t	     ESPI_v2_enableModule(SPI_Handle handle);

static bool ESPI_v2_checkEspiRegisterBit(uint32_t registerBase, uint8_t bitNum);
static void ESPI_v2_setEspiRegisterBit(uint32_t registerBase, uint8_t bitNum);
static int32_t ESPI_v2_readPacket(ESPI_Packet* packet, uint32_t rxBufBase, uint32_t maxPacketSize);
static int32_t ESPI_v2_writePacket(ESPI_Packet* packet, uint32_t txBufBase);
static void ESPI_v2_getData(uint32_t readAddr, uint8_t* dataPtr, uint32_t dataCount);
static void ESPI_v2_putData(uint32_t writeAddr, uint8_t* dataPtr, uint32_t dataCount);

static void	     ESPI_v2_handleRxMsg(SPI_Handle handle);


/* SPI function table so ESPI can be properly initialized */
const SPI_FxnTable ESPI_Init_FxnTable_v2 = {
  NULL,
  NULL,
  &ESPI_initSingle_v2,
  NULL,
  NULL,
  NULL,
  NULL
};

/* MCSPI function table for ESPI implementation */
const MCSPI_FxnTable ESPI_FxnTable_v2 = {
  &ESPI_close_v2,
  &ESPI_control_v2,
  &ESPI_init_v2,
  &ESPI_open_v2,
  &ESPI_transfer_v2,
  &ESPI_transferCancel_v2
};

/*
 *  ======== MCSPI_get_handle ========
 *  @pre    Function assumes that the handle is not NULL
 */
static MCSPI_Handle MCSPI_get_handle(SPI_Handle handle)
{
    MCSPI_Handle          mcHandle = NULL;
    ESPI_SwIPAttrs const *swipAttrs;
    uint32_t              chNum;
    uint32_t              i;

    swipAttrs = (const ESPI_SwIPAttrs *)handle->hwAttrs;
    chNum   = swipAttrs->chNum;

    for (i = 0; i < MCSPI_MAX_NUM_INSTANCES; i++)
    {
        if(MCSPI_config[i][chNum].handle == handle)
        {
            mcHandle = (MCSPI_Handle)&(MCSPI_config[i][chNum]);
            break;
        }
    }

    return (mcHandle);
}

/**
 * According to SPI_drv.c it isn't possible to call the MCSPI init
 * so we need to workaround that with a SPI_Handle init
*/
static void ESPI_initSingle_v2(SPI_Handle handle)
{
  MCSPI_Handle     mcHandle;

  /* Input parameter validation */
  if (handle != NULL)
    {
      /* Get multi-channel handle */
      mcHandle = MCSPI_get_handle(handle);
      if (mcHandle != NULL)
        {	  
	  ESPI_init_v2(mcHandle);
        }
    }
}

static void ESPI_init_v2(MCSPI_Handle mcHandle)
{
  SPI_Handle            handle;
  SemaphoreP_Params     semParams;
  ESPI_v2_Object   *object;
  ESPI_SwIPAttrs const  *swipAttrs = NULL;

  
  /* Input parameter validation */
  if (mcHandle != NULL)
    {
      /* Get the pointer to the object and swipAttrs */
      handle = mcHandle->handle;
      object = (ESPI_v2_Object*)handle->object;
      swipAttrs = (ESPI_SwIPAttrs const *)handle->hwAttrs;

      /*
       * Construct thread safe handles for this ESPI peripheral
       * Semaphore to provide exclusive access to the ESPI peripheral
       */
      SPI_osalSemParamsInit(&semParams);
      semParams.mode = SemaphoreP_Mode_BINARY;

      /* Create ICSS Semaphores */
      semParams.name = "BitbangPruSemaphore";
      object->icssMode.pruMode[swipAttrs->bitbangPru].pruInstLock = SPI_osalCreateBlockingLock(1U, &semParams);
      semParams.name = "ControlPruSemaphore";
      object->icssMode.pruMode[swipAttrs->controlPru].pruInstLock = SPI_osalCreateBlockingLock(1U, &semParams);
      
      /* Create ESPI Semaphores */
      semParams.name = "Ch0Semaphore";
      object->Ch0SemHandle = SPI_osalCreateBlockingLock(0U, &semParams);
      
      /* initialize object varibles */
      object->isOpen 		  = (bool)false;
      object->hwi                 = NULL;
      object->mutex               = NULL;
      object->transferComplete    = NULL;

    }
}

static MCSPI_Handle    ESPI_open_v2(MCSPI_Handle mcHandle, const MCSPI_Params *params)
{
  SPI_Handle            handle;
  SemaphoreP_Params     semParams;
  ESPI_v2_Object        *object = NULL;
  ESPI_SwIPAttrs const  *swipAttrs = NULL;
  uint32_t              key;
  int32_t               ret_flag = SPI_STATUS_SUCCESS;
  PRUSS_PruCores        bitbangPruInst = PRUICSS_MAX_PRU, controlPruInst = PRUICSS_MAX_PRU;
  ESPI_ICSS_INSTANCE    ICSSInst = ESPI_ICSS_INSTANCE_NONE;

  /* Input parameter validation */
  if (mcHandle != NULL)
    {
      /* Get the pointer to the object and swipAttrs */
      handle  = mcHandle->handle;
      object = (ESPI_v2_Object*)handle->object;
      swipAttrs = (ESPI_SwIPAttrs const *)handle->hwAttrs;
      ICSSInst = swipAttrs->icssInstance;
      bitbangPruInst = swipAttrs->bitbangPru;
      controlPruInst = swipAttrs->controlPru;

      /* Determine if the device index was already opened */
      key = SPI_osalHardwareIntDisable();
      if(object->isOpen == true)
	{
	  SPI_osalHardwareIntRestore(key);
	  handle = NULL;
	}
      else
	{
	  /* Mark the handle as being used */
	  object->isOpen = (bool)true;
	  SPI_osalHardwareIntRestore(key);
	  
	  /* Store the ESPI parameters */
	  if (params == NULL) {
	    /* No params passed in, so use the defaults */
	    MCSPI_Params_init(&(object->espiParams));
	  }
	  else {
	    /* Copy the params contents */
	    object->espiParams = *params;
	  }

	  /* Set up INTC interrupts for PRU-CC */
	  SPI_osalPendLock(object->icssMode.pruMode[controlPruInst].pruInstLock, SemaphoreP_WAIT_FOREVER);
	  if(object->icssMode.pruMode[controlPruInst].pruIcssHandle == NULL)
	    {
	      /* Register GPIO interrupts */
	      GPIO_setCallback(ESPI_GPIO_PIN_RESET, ESPI_v2_gpioCallbackFxn0);
	      GPIO_enableInt(ESPI_GPIO_PIN_RESET);
	      
	      OsalRegisterIntrParams_t interruptRegParams;
	      /* Initialize with defaults */
	      Osal_RegisterInterrupt_initParams(&interruptRegParams);
                    
	      /* Populate the interrupt parameters */
	      interruptRegParams.corepacConfig.arg=(uintptr_t)mcHandle;
	      interruptRegParams.corepacConfig.name=NULL;
	      interruptRegParams.corepacConfig.isrRoutine=&ESPI_v2_hwiFxn;
	      interruptRegParams.corepacConfig.corepacEventNum=swipAttrs->eventId; /* Event going in to CPU */
	      interruptRegParams.corepacConfig.intVecNum=swipAttrs->intNum; /* Host Interrupt vector */
                    
	      /* Register interrupts */
	      SPI_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));
	      if(object->hwi == NULL) {
		ret_flag = SPI_STATUS_ERROR;
	      }
	    }

	  //SPI_osalHardwareIntrEnable((int32_t)swipAttrs->intNum);
	  SPI_osalPostLock(object->icssMode.pruMode[controlPruInst].pruInstLock);

	  if(ret_flag == SPI_STATUS_SUCCESS)
	    {
	      /*
	       * Construct thread safe handles for this SPI peripheral
	       * Semaphore to provide exclusive access to the SPI peripheral
	       */
	      if (object->mutex == NULL)
		{
		  SPI_osalSemParamsInit(&semParams);
		  semParams.mode = SemaphoreP_Mode_BINARY;
		  object->mutex = SPI_osalCreateBlockingLock(1U, &semParams);
		}
	    }

	  if((ret_flag == SPI_STATUS_SUCCESS) && (ICSSInst <= ESPI_ICSS_INSTANCE2))
	    {
	      /* Initialize PRU */
	      SPI_osalPendLock(object->icssMode.pruMode[bitbangPruInst].pruInstLock, SemaphoreP_WAIT_FOREVER);
	      SPI_osalPendLock(object->icssMode.pruMode[controlPruInst].pruInstLock, SemaphoreP_WAIT_FOREVER);
	      if( object->icssMode.pruMode[bitbangPruInst].pruIcssHandle == NULL &&
		  object->icssMode.pruMode[controlPruInst].pruIcssHandle == NULL)
                {
		  ret_flag = ESPI_v2_pruIcssInit(handle);
                }
	      SPI_osalPostLock(object->icssMode.pruMode[bitbangPruInst].pruInstLock);
	      SPI_osalPostLock(object->icssMode.pruMode[controlPruInst].pruInstLock);
            }

	  if (ret_flag == SPI_STATUS_SUCCESS)
	    {
	      ret_flag = ESPI_v2_setupPinMux(handle);
	    }
	  if (ret_flag == SPI_STATUS_SUCCESS)
	    {
	      ret_flag =  ESPI_v2_enableModule(handle);
	    }
	  if (ret_flag == SPI_STATUS_ERROR)
	    {
	      ESPI_close_v2(mcHandle);
	      handle = NULL;
	    }
	}
    }
  
  return (mcHandle);
  
}

static void          ESPI_close_v2(MCSPI_Handle mcHandle)
{
  SPI_Handle            handle;
  ESPI_v2_Object        *object = NULL;
  /* ESPI_SwIPAttrs const         *swipAttrs = NULL; */
  /* ESPI_ICSS_INSTANCE           ICSSInst = ESPI_ICSS_INSTANCE_NONE; */
  /* PRUSS_PruCores               pruInst = PRUICSS_MAX_PRU; */
  /* PRUICSS_Handle               pruIcssHandle = NULL; */
  
  handle  = mcHandle->handle;
  object = (ESPI_v2_Object*)handle->object;

  /* Input parameter validation */
  if(handle != NULL)
    {
      /* Get the pointer to the object and swipAttrs */
      /* swipAttrs = (ESPI_SwIPAttrs const *)handle->hwAttrs; */
      object = (ESPI_v2_Object*)handle->object;

      object->isOpen = (bool)false;
    }
}


/*
 *  ======== ESPI_transfer_v2 ========
 *  This functions configures the transmit and receive channels for a given
 *  MCMCSPI_Handle and SPI_Transaction.
 *
 *  RX: The SPI_Transaction rxBuf should be non-NULL, and count indicates the
 *      maximum size of the transaction. Upon return, count will hold the actual
 *      number of bytes read from the buffer (aka packet size)
 *
 *  TX: The SPI_Transaction txBuf should be non-NULL, and count indicates the
 *      number of bytes to be written (aka packet size)
 *
 *  @pre    Function assumes that the handle and transaction is not NULL
 */
static bool          ESPI_transfer_v2(MCSPI_Handle mcHandle,
				      SPI_Transaction *transaction)
{
  SPI_Handle            handle;
  ESPI_SwIPAttrs const*	swipAttrs = NULL;
  ESPI_v2_Object*	object    = NULL;
  bool			ret_val   = false;

  handle  = mcHandle->handle;
  swipAttrs = (ESPI_SwIPAttrs const *)(handle->hwAttrs);
  object = (ESPI_v2_Object*)handle->object;

  /* Acquire the lock for the SPI transfer on this instance */
  SPI_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

  /* Check initial conditions are met to properly transfer */
  if (
      /* There must actually be data to transfer */
      (transaction->rxBuf == NULL && transaction->txBuf == NULL) ||

      /* Data must only be transferred in one direction */
      (transaction->rxBuf != NULL && transaction->txBuf != NULL) ||
      
      /* There may not already be a transaction in progress */
      (object->transaction != NULL)
      
      )
    {
      goto ERR;
    }

  /* Begin transaction */
  transaction->status = SPI_TRANSFER_STARTED;
  object->transaction = transaction;
  
  /* RX Transfer */
  if (transaction->rxBuf != NULL)
    {
      /* Set up object buffers */
      object->packet.dataBuf = transaction->rxBuf;
      
      /* Wait for data to appear */
      SPI_osalPendLock(object->Ch0SemHandle, SemaphoreP_WAIT_FOREVER);

      /* Data in PC Queue */
      if (!ESPI_v2_checkEspiRegisterBit(swipAttrs->baseAddr + STATUS_REGISTER_BASE, STATUS_PC_FREE_BIT))
	{
	  /* Read PC ESPI packet */
	  ret_val = ESPI_v2_readPacket(&object->packet, swipAttrs->baseAddr + CH0_PC_RX_BUFFER_BASE,
				       transaction->count);
	  if (ret_val != 0)
	    {
	      goto ERR;
	    }

	  /* Preemptively set PC TXQ Full bit */
	  ESPI_v2_setEspiRegisterBit(swipAttrs->baseAddr + INTERNAL_STATUS_REGISTER_BASE, CHAN0_PC_TXQ_FULL_BIT);
	  
	  /* Set the PC_FREE bit */
	  ESPI_v2_setEspiRegisterBit(swipAttrs->baseAddr + STATUS_REGISTER_BASE, STATUS_PC_FREE_BIT);
	}

      /* Data in NP Queue */
      else if (!ESPI_v2_checkEspiRegisterBit(swipAttrs->baseAddr + STATUS_REGISTER_BASE, STATUS_NP_FREE_BIT))
	{
	  /* Read PC ESPI packet */
	  ret_val = ESPI_v2_readPacket(&object->packet, swipAttrs->baseAddr + CH0_NP_RX_BUFFER_BASE,
				       transaction->count);
	  if (ret_val != 0)
	    {
	      goto ERR;
	    }

	  /* Set the NP_FREE bit */
	  ESPI_v2_setEspiRegisterBit(swipAttrs->baseAddr + STATUS_REGISTER_BASE, STATUS_NP_FREE_BIT);
	}

      /* Data not actually available (IRQ handler should not let it get to this point) */
      else
	{
	  /* Shouldn't get here */
	}

      /* Set the count to the actual number of bytes read */
      transaction->count = object->packet.len;
    }
  
  /* TX Transfer */
  else if (transaction->txBuf)
    {
      /* NOTE: Currently all TX transactions are PC  */

      /* Check vaild TX size */
      if(transaction->count > ESPI_PACKET_MAX_SIZE)
	{
	  goto ERR;
	}

      /* Setup packet */
      object->packet.magicNum = ESPI_PACKET_MAGIC_NUMBER;
      object->packet.len = transaction->count;
      object->packet.dataBuf = transaction->txBuf;

      /* Write packet to PRU */
      ret_val = ESPI_v2_writePacket(&object->packet, swipAttrs->baseAddr + CH0_PC_TX_BUFFER_BASE);
      if(ret_val != 0)
	{
	  goto ERR;
	}

      /* Set TXQ_Avail Status bit */      
      ESPI_v2_setEspiRegisterBit(swipAttrs->baseAddr + STATUS_REGISTER_BASE, STATUS_PC_AVAIL_BIT);
    }
  
  /* Bad direction, shouldn't get here */
  else
    {
      goto ERR;
    }

  ret_val = (bool)true;
  goto END;
 ERR:
  transaction->status = SPI_TRANSFER_CANCELED;
  ret_val = (bool)false;
 END:
  SPI_osalPostLock(object->mutex);
  object->transaction = NULL;
  return ret_val;
}

static int32_t ESPI_v2_readPacket(ESPI_Packet* packet, uint32_t rxBufBase, uint32_t maxPacketSize)
{
  uint32_t readOffset = 0;
  
  /* Read Packet Magic Number */
  ESPI_v2_getData(rxBufBase + readOffset, (uint8_t*)&packet->magicNum, sizeof(packet->magicNum));
  readOffset += sizeof(packet->magicNum);
	  
  /* Read Packet Length */
  ESPI_v2_getData(rxBufBase + readOffset, (uint8_t*)&packet->len, sizeof(packet->len));
  readOffset += sizeof(packet->len);

  /* Check invalid packet */       
  if ((packet->magicNum != ESPI_PACKET_MAGIC_NUMBER) ||
      (packet->len == 0) ||
      (packet->len > maxPacketSize)
      ) {
    return -1;
  }

  /* Read the rest of the PC Packet */
  ESPI_v2_getData(rxBufBase + readOffset, packet->dataBuf, packet->len);
  
  return 0;
}

static int32_t ESPI_v2_writePacket(ESPI_Packet* packet, uint32_t txBufBase)
{
  uint32_t writeOffset = 0;
  
  /* Write Packet Magic Number */
  ESPI_v2_putData(txBufBase + writeOffset, (uint8_t*)&packet->magicNum, sizeof(packet->magicNum));
  writeOffset += sizeof(packet->magicNum);
	  
  /* Write Packet Length */
  ESPI_v2_putData(txBufBase + writeOffset, (uint8_t*)&packet->len, sizeof(packet->len));
  writeOffset += sizeof(packet->len);

  /* Write the rest of the PC Packet */
  ESPI_v2_putData(txBufBase + writeOffset, packet->dataBuf, packet->len);
  
  return 0;
}

static void ESPI_v2_getData(uint32_t readAddr, uint8_t* dataPtr, uint32_t dataCount)
{
  uint32_t                 i = 0U;
    
  for(i = 0U; i < dataCount; i++)
    {
      dataPtr[i] = HW_RD_REG8(readAddr + i);
    }
}

static void ESPI_v2_putData(uint32_t writeAddr, uint8_t* dataPtr, uint32_t dataCount)
{
  uint32_t                 i = 0U;
	
  for(i = 0U; i < dataCount; i++)
    {
      HW_WR_REG8(writeAddr + i, dataPtr[i]);
    }
}

static void          ESPI_transferCancel_v2(MCSPI_Handle mcHandle)
{
  
}

static int32_t       ESPI_control_v2(MCSPI_Handle mcHandle, uint32_t cmd, const void *arg)
{
  return -1;
}

/*
 *  ======== ESPI_v2_gpioCallbackFxn0 ========
 *  GPIO interrupt handler for ESPI instance #0
 *  
 */
static void ESPI_v2_gpioCallbackFxn0(void) {
  SPI_Handle		   handle;
  ESPI_SwIPAttrs const     *swipAttrs = NULL;
  ESPI_v2_Object           *object = NULL;
  ESPI_ICSS_INSTANCE       ICSSInst = ESPI_ICSS_INSTANCE_NONE;
  PRUSS_PruCores           bitbangPruInst = PRUICSS_MAX_PRU, controlPruInst = PRUICSS_MAX_PRU;
  int32_t                  ret_flag = 0;

  /* Get the ESPI handle */
  handle = MCSPI_config[2][0].handle;

  /* Get the pointer to the swipAttrs */
  swipAttrs = (ESPI_SwIPAttrs const *)handle->hwAttrs;
  object = (ESPI_v2_Object*)handle->object;
  ICSSInst = swipAttrs->icssInstance;
  bitbangPruInst = swipAttrs->bitbangPru;
  controlPruInst = swipAttrs->controlPru;
      
  /* Initialize PRU */
  if((ret_flag == 0) && (ICSSInst <= ESPI_ICSS_INSTANCE2))
  {
    SPI_osalPendLock(object->icssMode.pruMode[bitbangPruInst].pruInstLock, SemaphoreP_WAIT_FOREVER);
    SPI_osalPendLock(object->icssMode.pruMode[controlPruInst].pruInstLock, SemaphoreP_WAIT_FOREVER);
    if( object->icssMode.pruMode[bitbangPruInst].pruIcssHandle == NULL &&
	object->icssMode.pruMode[controlPruInst].pruIcssHandle == NULL)
      {
	ret_flag = ESPI_v2_pruIcssInit(handle);
      }
    SPI_osalPostLock(object->icssMode.pruMode[bitbangPruInst].pruInstLock);
    SPI_osalPostLock(object->icssMode.pruMode[controlPruInst].pruInstLock);
  }
  
  if (ret_flag == 0)
    {
      ret_flag = ESPI_v2_setupPinMux(handle);
    }
  if (ret_flag == 0)
    {
      ret_flag =  ESPI_v2_enableModule(handle);
    }
  
}

/*
 *  ======== ESPI_v2_hwiFxn ========
 *  Hwi interrupt handler to service the ESPI peripheral
 */
static void ESPI_v2_hwiFxn(uintptr_t arg)
{
  MCSPI_Handle		mcHandle;
  SPI_Handle		handle;
  ESPI_SwIPAttrs const*	swipAttrs;
  ESPI_v2_Object*	object;
  uint32_t		irqCommonSts	 = 0;
  PRUICSS_Handle	controlPruHandle = NULL;

  mcHandle = (MCSPI_Handle)arg;
    
  /* Input parameter validation */
  if( mcHandle != NULL )
    {
      /* Get the pointer to the object and hwAttrs */
      handle  = mcHandle->handle;
      swipAttrs = (ESPI_SwIPAttrs const *)handle->hwAttrs;
      object = (ESPI_v2_Object*)handle->object;
      controlPruHandle = object->icssMode.pruMode[swipAttrs->controlPru].pruIcssHandle;

      /* Read message from IPC register */
      irqCommonSts = HW_RD_REG32(swipAttrs->baseAddr + IPC_REGISTER_BASE);

      switch (irqCommonSts)
	{
	case ICSS_ESPI_IPC_MSG_NONE:
	  break;
	case ICSS_ESPI_IPC_MSG_RESET:
	  break;
	case ICSS_ESPI_IPC_MSG_ERROR:
	  break;
	case ICSS_ESPI_IPC_MSG_RX_AVAIL:
	  ESPI_v2_handleRxMsg(handle);
	  break;
	default:
	  break;
	}

      /* clear the IPC register */
      HW_WR_REG32(swipAttrs->baseAddr + IPC_REGISTER_BASE, ICSS_ESPI_IPC_MSG_NONE);
      
      /* clear PRU-ICSS INTC interrupt */
      HW_WR_REG32(((PRUICSS_HwAttrs const*)controlPruHandle->hwAttrs)->prussIntcRegBase + ESPI_ICSS_INTC_SECR0, ICSS_ESPI_INTC_BIT_VAL);
    }
  return;
}

/*
 *  ======== ESPI_v2_handleRxMsg ========
 *  Hwi interrupt indicated RX message is available. Dispatch any waiting threads.
 */
static void ESPI_v2_handleRxMsg(SPI_Handle handle)
{
  uint32_t	statusRegister	= 0;
  ESPI_SwIPAttrs const*	swipAttrs = (ESPI_SwIPAttrs const *)handle->hwAttrs;

  /* Read status register */
  /* RXQ is only one item deep, so _FREE bit indicates a packet is available */
  
  statusRegister = HW_RD_REG32(swipAttrs->baseAddr + STATUS_REGISTER_BASE);
  
  /* Currently only Channel 0 is supported */
  if ( !(statusRegister & (0x1 << STATUS_PC_FREE_BIT)) ||
       !(statusRegister & (0x1 << STATUS_NP_FREE_BIT))
       ) {
    SPI_osalPostLock(((ESPI_v2_Object*)handle->object)->Ch0SemHandle);
  }
}

/*
 *  ======== ESPI_v2_checkEspiRegisterBit ========
 *  Check an ESPI register bit
 */
static bool ESPI_v2_checkEspiRegisterBit(uint32_t registerBase, uint8_t bitNum)
{
  uint32_t	registerVal	= 0;
  
  registerVal = HW_RD_REG32(registerBase);
  return (bool)(registerVal & (0x1 << bitNum));
}

/*
 *  ======== ESPI_v2_setEspiRegisterBit ========
 *  Set an ESPI register bit
 */
static void ESPI_v2_setEspiRegisterBit(uint32_t registerBase, uint8_t bitNum)
{
  uint32_t	registerVal	= 0;
  
  registerVal = HW_RD_REG32(registerBase);
  HW_WR_REG32(registerBase, registerVal | (0x1 << bitNum));
}

/*
 *  ======== ESPI_v2_setupPinMux ========
 */
static int32_t ESPI_v2_setupPinMux(SPI_Handle handle)
{
  ESPI_SwIPAttrs const	*swipAttrs = NULL;
  ESPI_PRU_IOPinMuxAttrs		pinReg;
  int32_t			retVal = 0;

  /* Input parameter validation */
  if(handle != NULL)
    {
      /* Get the pointer to the object and swipAttrs */
      swipAttrs = (ESPI_SwIPAttrs const *)handle->hwAttrs;

      /** GPI Pins **/
      /* D0 In */
      pinReg = swipAttrs->d0InputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPI_MODE);

      /* D1 In */
      pinReg = swipAttrs->d1InputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPI_MODE);

      /* D2 In */
      pinReg = swipAttrs->d2InputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPI_MODE);

      /* D3 In */
      pinReg = swipAttrs->d3InputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPI_MODE);
	
      /* SCL */
      pinReg = swipAttrs->sclInputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPI_MODE);

      /* CS */
      pinReg = swipAttrs->csInputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPI_MODE);

	
      /** GPO Pins **/
      /* D0 Out */
      pinReg = swipAttrs->d0OutputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPO_MODE);

      /* D0 Out */
      pinReg = swipAttrs->d1OutputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPO_MODE);

      /* D0 Out */
      pinReg = swipAttrs->d2OutputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPO_MODE);

      /* D0 Out */
      pinReg = swipAttrs->d3OutputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPO_MODE);

      /* ALERT */
      pinReg = swipAttrs->alertOutputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPO_MODE);

      /* EN */
      pinReg = swipAttrs->enOutputPin;
      ESPI_v2_pruGPIOMuxConfig(&pinReg, ESPI_PRU_PINMUX_GPO_MODE);
	
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
void ESPI_v2_pruGPIOMuxConfig(ESPI_PRU_IOPinMuxAttrs *handle, uint32_t pinMode)
{
  if (handle->baseRegAddr != 0) {
    uint32_t regVal = *(volatile uint32_t *)(handle->baseRegAddr);
    if(ESPI_PRU_PINMUX_GPI_MODE == pinMode)
      {
	/* regVal &= ESPI_PRU_GPI_SELECT_MASK; */
	regVal = ESPI_PRU_GPI_INPUT_ENABLE;
	regVal |= ESPI_PRU_GPO_PULLUP_DISABLE;
	regVal |= (uint32_t)(handle->inputModeVal);
      }
    else if(ESPI_PRU_PINMUX_GPO_MODE == pinMode)
      {
	/* regVal &= ESPI_PRU_GPO_SELECT_MASK; */
	regVal = ESPI_PRU_GPO_PULLUP_DISABLE;
	regVal |= (uint32_t)(handle->outputModeVal);
      }
    else
      {
	/* nothing to be done here */
      }
    *(volatile uint32_t *)(handle->baseRegAddr) = regVal;
  } else {
    /* Don't mux this pin */
  }
}

/*
 * enable soft IP ESPI module
 */
int32_t ESPI_v2_enableModule(SPI_Handle handle)
{
  ESPI_SwIPAttrs const     *swipAttrs = NULL;
  uint32_t                 regVal = 0x00000000;
  int32_t                  retVal    = 0;
    
  /* Input parameter validation */
  if(handle != NULL)
    {
      /* Get the pointer to the object and swipAttrs */
      swipAttrs = (ESPI_SwIPAttrs const *)handle->hwAttrs;

      regVal = HW_RD_REG32(swipAttrs->baseAddr + CHAN0_CAP_CON_REGISTER_BASE);
      regVal |= ((uint32_t)1U << PERIPHERAL_CHAN_ENABLE_OFFSET);
      HW_WR_REG32(swipAttrs->baseAddr + CHAN0_CAP_CON_REGISTER_BASE, regVal);
    }
  else
    {
      retVal = (-((int32_t)1));
    }

  return retVal;
}


/*
 *  ======== ESPI_v2_pruIcssInit ========
 */
static int32_t ESPI_v2_pruIcssInit(SPI_Handle handle)
{
    ESPI_SwIPAttrs const    *swipAttrs  = NULL;
    ESPI_v2_Object          *object     = NULL;
    ESPI_ICSS_INSTANCE       icssInst   = ESPI_ICSS_INSTANCE_NONE;
    PRUSS_PruCores           bitbangPruInst  = PRUICSS_MAX_PRU, controlPruInst = PRUICSS_MAX_PRU;
    PRUICSS_Config          *pruIcssCfg = NULL;
    PRUICSS_Handle           bitbangPruHandle  = NULL, controlPruHandle = NULL;
    int32_t                  retVal = SPI_STATUS_ERROR;

    /**
     *  Input parameter validation
     */
    if (handle != NULL)
    {
        /**
         * Get all useful pointers
         */
        swipAttrs = (ESPI_SwIPAttrs const *)handle->hwAttrs;
        object    = (ESPI_v2_Object*)handle->object;
        icssInst  = swipAttrs->icssInstance;
        bitbangPruInst   = swipAttrs->bitbangPru;
        controlPruInst   = swipAttrs->controlPru;

        /**
         * Initialize PRU-ICSS configuration
         */
        retVal = PRUICSS_socGetInitCfg(&pruIcssCfg);
        if ((retVal != PRUICSS_RETURN_SUCCESS) || (icssInst > ESPI_ICSS_INSTANCE2))
        {
            retVal = SPI_STATUS_ERROR;
        }
        else
        {
            retVal = SPI_STATUS_SUCCESS;
            /**
             * Create PRU-ICSS handle
             */
            bitbangPruHandle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg, icssInst);
            controlPruHandle = PRUICSS_create((PRUICSS_Config*) pruIcssCfg, icssInst);
            if ((bitbangPruHandle == NULL) || (controlPruHandle == NULL))
            {
                retVal = SPI_STATUS_ERROR;
            }
        }

        if (retVal == SPI_STATUS_SUCCESS)
        {
            object->icssMode.pruMode[bitbangPruInst].pruIcssHandle = bitbangPruHandle;
            object->icssMode.pruMode[controlPruInst].pruIcssHandle = controlPruHandle;

            /**
             * Pinmuxing
             */
            PRUICSS_pinMuxConfig(bitbangPruHandle, 0x0); /* enable PRUSS pinmuxing on the IO PRU */

            /**
             * Disable the PRU while it is initialized and configured
             */
            PRUICSS_pruDisable(bitbangPruHandle, bitbangPruInst);
            PRUICSS_pruDisable(controlPruHandle, controlPruInst);

            /**
             * Initialize bitbang PRU core
             */
            retVal = ESPI_v2_initPruCore(bitbangPruInst, bitbangPruHandle, swipAttrs->icssMemBuffer);
        }

        if (retVal == SPI_STATUS_SUCCESS)
        {
            /**
             * Initialize control PRU core
             */
            retVal = ESPI_v2_initPruCore(controlPruInst, controlPruHandle, swipAttrs->icssMemBuffer);
        }

        if (retVal == SPI_STATUS_SUCCESS)
        {
            /* Zero out the shared memory */
            PRUICSS_pruInitMemory(controlPruHandle, PRU_ICSS_SHARED_RAM);

            /**
             * Start the PRU
             */
            PRUICSS_pruEnable(bitbangPruHandle, bitbangPruInst);
            PRUICSS_pruEnable(controlPruHandle, controlPruInst);
        }
    }
    return retVal;
}

static int32_t ESPI_v2_initPruCore(PRUSS_PruCores pruInst,
                                   PRUICSS_Handle pruIcssHandle,
				                   const ICSS_Mem_Ptr *icssMemBuffer)
{
    PRUICSS_IntcInitData pruss_intc_initdata = PRUSS_INTC_INITDATA;
    int32_t              retVal = SPI_STATUS_SUCCESS;
    uint32_t *dramBufferStart, *dramBufferEnd, *iramBufferStart, *iramBufferEnd;
    uint32_t  dramBufferLength, iramBufferLength;
  
    /**
     * Initialize the PRU
     */
    PRUICSS_pruIntcInit(pruIcssHandle, &pruss_intc_initdata);        /* Initialize INTC */
    PRUICSS_pruReset(pruIcssHandle, pruInst);                        /* Restart the PRU */
    PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_DATARAM(pruInst)); /* Initialize PRU data memory */
    PRUICSS_pruInitMemory(pruIcssHandle, PRU_ICSS_IRAM(pruInst));    /* Initialize PRU instruction memory */

    /**
     * Set PRU memory address values
     */
    if(PRUICCSS_PRU0 == pruInst)
    {   /* PRU0 */
        dramBufferStart = icssMemBuffer->dram0MemBufferStart;
        dramBufferEnd   = icssMemBuffer->dram0MemBufferEnd;
        iramBufferStart = icssMemBuffer->iram0MemBufferStart;
        iramBufferEnd   = icssMemBuffer->iram0MemBufferEnd;
    }
    else if(PRUICCSS_PRU1 == pruInst)
    {   /* PRU1 */
        dramBufferStart = icssMemBuffer->dram1MemBufferStart;
        dramBufferEnd   = icssMemBuffer->dram1MemBufferEnd;
        iramBufferStart = icssMemBuffer->iram1MemBufferStart;
        iramBufferEnd   = icssMemBuffer->iram1MemBufferEnd;
    }
    else
    {   /* Invalid PRU number */
        retVal = SPI_STATUS_ERROR;
    }

    if (retVal == SPI_STATUS_SUCCESS)
    {
        /**
         * Calculate PRU memory buffer lengths
         */
        dramBufferLength = (uint32_t)((uint8_t*)dramBufferEnd) - (uint32_t)((uint8_t*)dramBufferStart);
        iramBufferLength = (uint32_t)((uint8_t*)iramBufferEnd) - (uint32_t)((uint8_t*)iramBufferStart);

        /**
         * Write PRU memory
         */
        PRUICSS_pruWriteMemory(pruIcssHandle, PRU_ICSS_DATARAM(pruInst), 0,
                   dramBufferStart, dramBufferLength);
        PRUICSS_pruWriteMemory(pruIcssHandle, PRU_ICSS_IRAM(pruInst), 0,
                   iramBufferStart, iramBufferLength);
    }
    return retVal;
}
