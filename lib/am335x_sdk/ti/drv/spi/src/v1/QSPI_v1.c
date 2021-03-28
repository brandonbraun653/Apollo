/**
 *  \file   QSPI_v1.c
 *
 *  \brief  QSPI IP Version 1 specific driver APIs implementation.
 *
 *   This file contains the driver APIs for QSPI controller.
 */

/*
 * Copyright (C) 2014-2019 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/QSPI_v1.h>
#include <ti/csl/src/ip/qspi/V1/qspi.h>
#include <ti/csl/src/ip/qspi/V1/hw_qspi.h>
#include <ti/drv/spi/src/SPI_osal.h>

/*#define WORD_INTERRUPT*/

/* QSPI AM57x functions */
static void       QSPI_close_v1(SPI_Handle handle);
static void       QSPI_init_v1(SPI_Handle handle);
static SPI_Handle QSPI_open_v1(SPI_Handle handle, const SPI_Params *params);
static bool       QSPI_transfer_v1(SPI_Handle handle,
                                      SPI_Transaction *transaction);
static void       QSPI_primeTransfer_v1(SPI_Handle handle,
                                          const SPI_Transaction *transaction);
static void       QSPI_transferCallback_v1(SPI_Handle handle,
                                              SPI_Transaction *msg);
static int32_t QSPI_control_v1(SPI_Handle handle, uint32_t cmd, const void *arg);
static void QSPI_transferCancel_v1(SPI_Handle handle);
static void QSPI_hwiFxn_v1(uintptr_t arg);
static void QSPI_read_v1(SPI_Handle handle, const SPI_Transaction *transaction);
static void QSPI_write_v1(SPI_Handle handle, const SPI_Transaction *transaction);
static void QSPI_mmap_mode_write_v1(SPI_Handle handle,
                                    const SPI_Transaction *transaction);
static void QSPI_cmd_mode_write_v1(SPI_Handle handle,
                                   const SPI_Transaction *transaction);
static void QSPI_cmd_mode_read_v1(SPI_Handle handle,
                                  const SPI_Transaction *transaction);
static void QSPI_mmap_mode_read_v1(SPI_Handle handle,
                                   const SPI_Transaction *transaction);
static void QSPIMmapCsEnable(uint32_t baseAddr, uint32_t chipSelect);

typedef enum QSPI_intrPollMode_s {
    SPI_OPER_MODE_BLOCKING = 0U,  /*! Interrupt based blocking mode */
    SPI_OPER_MODE_POLLING,        /*! Non interrupt based blocking mode */
    SPI_OPER_MODE_CALLBACK        /*! Interrupt based call back mode */
} QSPI_intrPollMode;



/* SPI function table for QSPI AM57x implementation */
const SPI_FxnTable QSPI_FxnTable_v1 = {
    &QSPI_close_v1,
    &QSPI_control_v1,
    &QSPI_init_v1,
    &QSPI_open_v1,
    &QSPI_transfer_v1,
    &QSPI_transferCancel_v1,
    NULL
};

#define   CTRL_CORE_CONTROL_IO_2       (0x4A002558U)
#define   QSPI_MMAP_CS_SHIFT           (0x8U)

/*
 *  ======== QSPI_close_v1 ========
 */
static void QSPI_close_v1(SPI_Handle handle)
{
    QSPI_v1_Object      *object = NULL;
    QSPI_HwAttrs const  *hwAttrs = NULL;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        object = (QSPI_v1_Object*)handle->object;
        hwAttrs = (const QSPI_HwAttrs *)handle->hwAttrs;

        /* Mask I2C interrupts */
        QSPIintDisable(hwAttrs->baseAddr,
            (QSPI_INTR_MASK_FRAME | QSPI_INTR_MASK_WORD));

        /* Destruct the Hwi */
        if ((SPI_OPER_MODE_BLOCKING == object->intrPollMode) && (true == hwAttrs->intrEnable))
        {
            SPI_osalHardwareIntDestruct(object->hwi, hwAttrs->eventId);
        }

        /* Destruct the instance lock */
        SPI_osalDeleteBlockingLock(object->mutex);

        /* Destruct the transfer completion lock */
        if(SPI_OPER_MODE_BLOCKING == object->intrPollMode)
        {
            SPI_osalDeleteBlockingLock(object->transferComplete);
        }

    #ifdef SPI_DMA_ENABLE
        if (hwAttrs->dmaEnable == true)
        {
            QSPI_dmaFreeChannel(handle);
        }
    #endif

        /* Open flag is set false */
        object->isOpen = (bool)false;
    }

    return;
}

/*
 *  ======== QSPI_hwiFxn_v1 ========
 *  Hwi interrupt handler to service the QSPI peripheral
 *
 *  The handler is a generic handler for a QSPI object.
 */
static void QSPI_hwiFxn_v1(uintptr_t arg)
{
    uint32_t            intrStatus;
    QSPI_v1_Object      *object = NULL;
    QSPI_HwAttrs const  *hwAttrs = NULL;

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object*)(((SPI_Handle)arg)->object);
    hwAttrs = (const QSPI_HwAttrs *)(((SPI_Handle)arg)->hwAttrs);

    /* Read the interrupt status register */
    intrStatus = QSPIintStatus(hwAttrs->baseAddr);

    /* If word count interrupt */
    if(intrStatus & QSPI_INTR_MASK_WORD)
    {
        /* Clear interrupt status */
        QSPIintClear(hwAttrs->baseAddr, QSPI_INTR_MASK_WORD);

        /* Call the call back function */
        object->transaction->status = SPI_TRANSFER_COMPLETED;
        object->qspiParams.transferCallbackFxn((SPI_Handle)arg, NULL);
    }

    /* If word count interrupt */
    if(intrStatus & QSPI_INTR_MASK_FRAME)
    {
        /* Clear interrupt status */
        QSPIintClear(hwAttrs->baseAddr, QSPI_INTR_MASK_FRAME);

        /* Call the call back function */
        object->transaction->status = SPI_TRANSFER_COMPLETED;
        object->qspiParams.transferCallbackFxn((SPI_Handle)arg, NULL);
    }

    return;
}

/*
 *  ======== QSPI_init_v1 ========
 */
static void QSPI_init_v1(SPI_Handle handle)
{
    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Mark the object as available */
        ((QSPI_v1_Object *)(handle->object))->isOpen = (bool)false;
    }
}


/*
 *  ======== QSPI_open_v1 ========
 */
static SPI_Handle QSPI_open_v1(SPI_Handle handle, const SPI_Params *params)
{
    SemaphoreP_Params     semParams;
    uint32_t       key;
    QSPI_v1_Object   *object = NULL;
    QSPI_HwAttrs const  *hwAttrs = NULL;
    OsalRegisterIntrParams_t interruptRegParams;
    uint8_t ret_flag = 0u;
    uint32_t clkDiv;

    /* Input parameter validation */
    if (handle != NULL)
    {
    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object*)handle->object;
    hwAttrs = (const QSPI_HwAttrs *)handle->hwAttrs;

    /* Determine if the device index was already opened */
    key = SPI_osalHardwareIntDisable();
    if(object->isOpen == (bool)true) {
        SPI_osalHardwareIntRestore(key);
        handle = NULL;
    }
    else
    {
      /* Mark the handle as being used */
      object->isOpen = (bool)true;
      SPI_osalHardwareIntRestore(key);

      /* Store the I2C parameters */
      if (params == NULL) {
        /* No params passed in, so use the defaults */
        SPI_Params_init(&(object->qspiParams));
      }
      else {
        /* Copy the params contents */
        object->qspiParams = *params;
      }

      /* Copy the controller mode from hardware attributes to object */
      object->qspiMode = hwAttrs->operMode;
      object->rxLines  = hwAttrs->rxLines;

      /* Extract QSPI operating mode based on hwAttrs and input parameters */
      if(SPI_MODE_BLOCKING == object->qspiParams.transferMode)
      {
          if(true == hwAttrs->intrEnable)
          {
              object->intrPollMode = SPI_OPER_MODE_BLOCKING;
          }
#ifdef SPI_DMA_ENABLE
          else if (true == hwAttrs->dmaEnable)
          {
              object->intrPollMode = SPI_OPER_MODE_BLOCKING;
          }
#endif
          else
          {
              object->intrPollMode = SPI_OPER_MODE_POLLING;
          }
      }
      else
      {
        object->intrPollMode = SPI_OPER_MODE_CALLBACK;
      }


      /* Extract the polling mode from hardware attributes. */
      if ((SPI_OPER_MODE_BLOCKING == object->intrPollMode) && (true == hwAttrs->intrEnable))
      {
		/* register interrrupt when the 1st channel of the instance is opened */
        Osal_RegisterInterrupt_initParams(&interruptRegParams);             

        interruptRegParams.corepacConfig.name=NULL;
        interruptRegParams.corepacConfig.priority = 0x20;
        interruptRegParams.corepacConfig.corepacEventNum = hwAttrs->eventId;
        interruptRegParams.corepacConfig.intVecNum=hwAttrs->intrNum; /* Host Interrupt vector */
        interruptRegParams.corepacConfig.isrRoutine  = (void (*)(uintptr_t))(&QSPI_hwiFxn_v1);
        interruptRegParams.corepacConfig.arg         = (uintptr_t)handle;

        SPI_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));

        if(object->hwi == NULL) {
            QSPI_close_v1(handle);
            ret_flag = 1u;
            handle = NULL;
        }
      }

      if(ret_flag == 0u)
      {
        /*
         * Construct thread safe handles for this QSPI peripheral
         * Semaphore to provide exclusive access to the QSPI peripheral
         */
        SPI_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;
        object->mutex = SPI_osalCreateBlockingLock(1U, &semParams);

        /*
         * Store a callback function that posts the transfer complete
         * semaphore for synchronous mode
         */
        if (object->intrPollMode == SPI_OPER_MODE_BLOCKING) {
          /*
           * Semaphore to cause the waiting task to block for the QSPI
           * to finish
           */
          object->transferComplete = SPI_osalCreateBlockingLock(0, &semParams);

          /* Store internal callback function */
          object->qspiParams.transferCallbackFxn = &QSPI_transferCallback_v1;
        }
        if(object->intrPollMode == SPI_OPER_MODE_CALLBACK){
          /* Check to see if a callback function was defined for async mode */
          OSAL_Assert(object->qspiParams.transferCallbackFxn == NULL);
        }

#ifdef SPI_DMA_ENABLE
        if (hwAttrs->dmaEnable == true)
        {
            /* DMA Configuration */
            QSPI_dmaConfig(handle);
        }
#endif
        /* Setting IDLE mode for QSPI controller */
        QSPIconfigIdleMode(hwAttrs->baseAddr, QSPI_SYSCONFIG_IDLE_MODE_NO_IDLE);

        /* Set clock mode in mode 3 */
        QSPISetClkMode(hwAttrs->baseAddr, hwAttrs->chipSelect, hwAttrs->frmFmt);
        QSPISetCsPol(hwAttrs->baseAddr, hwAttrs->chipSelect, hwAttrs->csPol);
        QSPISetDataDelay(hwAttrs->baseAddr, hwAttrs->chipSelect,
                          hwAttrs->dataDelay);

        /* Enable clock and set divider value */
        if (hwAttrs->clkDiv > 0U)
        {
            /* use SoC specific clock divider if configured */
            clkDiv = hwAttrs->clkDiv;
        }
        else
        {
            /*
             * if SoC specific clock divider not configured
             * calculate the clock divider using QSPI clock and baud rate
             */
            clkDiv = hwAttrs->funcClk / object->qspiParams.bitRate;
        }

        if (clkDiv > 0U)
        {
            clkDiv--;
        }
        QSPISetPreScaler(hwAttrs->baseAddr, clkDiv);

        /* Clear the interrupts and interrupt status */
        QSPIintDisable(hwAttrs->baseAddr,
            (QSPI_INTR_MASK_FRAME | QSPI_INTR_MASK_WORD)) ;
        QSPIintClear(hwAttrs->baseAddr,
            (QSPI_INTR_MASK_FRAME | QSPI_INTR_MASK_WORD));

        QSPISetMemMapNumAddrBytes(hwAttrs->baseAddr,
                      hwAttrs->chipSelect,
                      QSPI_MEM_MAP_NUM_ADDR_BYTES_THREE);

        /* Enable memory mapped port by default */
        QSPISetMemAddrSpace(hwAttrs->baseAddr,
                hwAttrs->chipSelect,
                QSPI_MEM_MAP_PORT_SEL_MEM_MAP_PORT);


        QSPIMmapCsEnable(hwAttrs->baseAddr, hwAttrs->chipSelect);

        /* Return the address of the spiObjectArray[i] configuration structure */
      }
    }
    }
    return(handle);
}

static void QSPIMmapCsEnable(uint32_t baseAddr, uint32_t chipSelect)
{
#if !defined(SOC_AM437x)
    uint32_t regVal;

    regVal = HW_RD_REG32(CTRL_CORE_CONTROL_IO_2);
    regVal |= ((chipSelect + 1U) << QSPI_MMAP_CS_SHIFT);
    HW_WR_REG32(CTRL_CORE_CONTROL_IO_2, regVal);
#endif
}

/*
 *  ======== QSPI_primeTransfer_v1 =======
 */
static void QSPI_primeTransfer_v1(SPI_Handle handle,
                                  const SPI_Transaction *transaction)
{
    QSPI_v1_Object  *object = NULL;
    QSPI_HwAttrs const  *hwAttrs = NULL;

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object*)handle->object;
    hwAttrs = (const QSPI_HwAttrs *)handle->hwAttrs;

    /* Store the new internal counters and pointers */
    object->writeBufIdx = (uint8_t*)transaction->txBuf;
    object->writeCountIdx = transaction->count;

    object->readBufIdx = (uint8_t*)transaction->rxBuf;
    object->readCountIdx = transaction->count;


    /* Interrupt mode */
    if ((SPI_OPER_MODE_BLOCKING == object->intrPollMode) && (true == hwAttrs->intrEnable))
    {
#ifdef WORD_INTERRUPT
        /* Enable the word count interrupt */
        QSPIintEnable(hwAttrs->baseAddr, QSPI_INTR_MASK_WORD);
#else
        /* Enable the frame count interrupt */
        QSPIintEnable(hwAttrs->baseAddr, QSPI_INTR_MASK_FRAME);
#endif
    }

    /* Identify the direction of transfer (whether read/write) */
    if(SPI_TRANSACTION_TYPE_READ == object->transactionType)
    {
        QSPI_read_v1(handle, transaction);
    }

    if(SPI_TRANSACTION_TYPE_WRITE == object->transactionType)
    {
        QSPI_write_v1(handle, transaction);
    }
}


static void QSPI_mmap_mode_read_v1(SPI_Handle handle,
                                   const SPI_Transaction *transaction)
{
    QSPI_HwAttrs const  *hwAttrs = NULL;
    uint8_t *pDst = NULL;
    uint8_t *pSrc = NULL;
    uint32_t count;
    uint32_t mmapReadCmd = 0U;
    QSPI_v1_Object  *object;
    uintptr_t offset;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (const QSPI_HwAttrs *)handle->hwAttrs;
    object = (QSPI_v1_Object*)handle->object;

    /* get flash offset */
    offset = (uintptr_t)transaction->txBuf;

    /* Extract memory map mode read command */
    mmapReadCmd = (uint32_t)object->transferCmd;

    /* Set the number of address bytes to three */
    QSPISetMemMapNumAddrBytes(hwAttrs->baseAddr, hwAttrs->chipSelect,
        QSPI_MEM_MAP_NUM_ADDR_BYTES_THREE);

    /* 4 byte addressing mode */
    if(offset > (uintptr_t)0xFFFFFF)
    {
        /* Enable 4 byte addressing mode */
        QSPISetMemMapNumAddrBytes(hwAttrs->baseAddr, hwAttrs->chipSelect,
            QSPI_MEM_MAP_NUM_ADDR_BYTES_FOUR);
    }

    switch(object->rxLines)
    {
        case QSPI_RX_LINES_SINGLE:
        {
            QSPISetMemMapReadCmd(hwAttrs->baseAddr, hwAttrs->chipSelect,
                mmapReadCmd);
            QSPISetMemMapReadType(hwAttrs->baseAddr, hwAttrs->chipSelect,
                QSPI_MEM_MAP_READ_TYPE_NORMAL);
            QSPISetMemMapNumDummyBits(hwAttrs->baseAddr, hwAttrs->chipSelect,
                0x0U);
            break;
        }

        case QSPI_RX_LINES_DUAL:
        {
            QSPISetMemMapReadCmd(hwAttrs->baseAddr, hwAttrs->chipSelect,
                mmapReadCmd);
            QSPISetMemMapReadType(hwAttrs->baseAddr, hwAttrs->chipSelect,
                QSPI_MEM_MAP_READ_TYPE_DUAL);
            QSPISetMemMapNumDummyBits(hwAttrs->baseAddr, hwAttrs->chipSelect,
                0x8U);
            break;
        }

        case QSPI_RX_LINES_QUAD:
        {
            QSPISetMemMapReadCmd(hwAttrs->baseAddr, hwAttrs->chipSelect,
                mmapReadCmd);
            QSPISetMemMapReadType(hwAttrs->baseAddr, hwAttrs->chipSelect,
                QSPI_MEM_MAP_READ_TYPE_QUAD);
            QSPISetMemMapNumDummyBits(hwAttrs->baseAddr, hwAttrs->chipSelect,
                0x8U);
            break;
        }

        default:
        break;
    }

#ifdef SPI_DMA_ENABLE
    if (hwAttrs->dmaEnable == true)
    {
        QSPI_dmaTransfer(handle, (SPI_Transaction *)transaction);
    }
    else
#endif
    {
        uintptr_t temp_addr = ((uintptr_t)hwAttrs->memMappedBaseAddr + (uintptr_t)transaction->txBuf);
        pSrc = ((uint8_t *)(temp_addr));
        pDst = (uint8_t *)transaction->rxBuf;
        count = transaction->count;

        while(count)
        {
            /* Do the normal memory to memory transfer. Copy will be in bytes */
            *pDst = *pSrc;
            pDst++;
            pSrc++;
            count--;
        }
    }

    /* 4 byte addressing mode */
    if(offset > (uint32_t)0xFFFFFF)
    {
        /*
         * After the transfer switch back to 3 byte addressing mode.
         * This is the default mode.
         */
        QSPISetMemMapNumAddrBytes(hwAttrs->baseAddr, hwAttrs->chipSelect,
            QSPI_MEM_MAP_NUM_ADDR_BYTES_THREE);
    }
}


static void QSPI_cmd_mode_read_v1(SPI_Handle handle,
                                  const SPI_Transaction *transaction)
{
    QSPI_v1_Object  *object;         /* QSPI object */
    QSPI_HwAttrs const  *hwAttrs;    /* QSPI hardware attributes */
    uint32_t count = 0U;         /* transfer length in bytes */
    uint32_t wordLenBytes = 0U;  /* Word length in number of bytes */
    uint32_t cmd = 0;           /* transmit command */
    uint32_t dataVal[4] = {0U, 0U, 0U, 0U};  /* data to be written */
    uint32_t idx, idx1, idx2, idx3;  /* indexes */
    uint32_t numWords = 0U;          /* number of words */
    uint8_t *dstAddr;              /* destination address */

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object*)handle->object;
    hwAttrs = (const QSPI_HwAttrs *)handle->hwAttrs;

    dstAddr = object->readBufIdx;

    /*formulate the command */
    HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_FLEN, (object->frmLength - 1));
    HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_WLEN, (object->qspiParams.dataSize - 1));
    HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_CSNUM, hwAttrs->chipSelect);

    switch(object->rxLines)
    {
        case QSPI_RX_LINES_SINGLE:
        {
            HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_CMD,
                QSPI_SPI_CMD_REG_CMD_FOUR_PIN_READ_SINGLE);
            break;
        }
        case QSPI_RX_LINES_DUAL:
        {
            HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_CMD,
                QSPI_SPI_CMD_REG_CMD_FOUR_PIN_READ_DUAL);
            break;
        }
        case QSPI_RX_LINES_QUAD:
        {
            HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_CMD,
                QSPI_SPI_CMD_REG_CMD_SIX_PIN_READ_QUAD);
            break;
        }

        default:
        break;
    }

    /* Enable interrupts in the polling mode */
    if ((SPI_OPER_MODE_BLOCKING == object->intrPollMode) && (true == hwAttrs->intrEnable))
    {
#ifdef WORD_INTERRUPT
        /* Enable word count interrupt */
        HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_WIRQ, true);
#else
        /* Enable frame count interrupt */
        HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_FIRQ, true);
#endif

    }
    else
    {
        /* Disable word count interrupt */
        HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_WIRQ, false);
        HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_FIRQ, false);
    }

    /* Extract frame length in bytes */
    count = transaction->count;

    /* Extract word length in number of bytes */
    wordLenBytes = (object->qspiParams.dataSize >> 3U);

    /* Write the data into shift registers */
    while(count)
    {
        /* Write tx command to command register */
        QSPIsetCommandReg(hwAttrs->baseAddr, cmd);

#ifdef WORD_INTERRUPT
        /* interrupt mode */
        if ((SPI_OPER_MODE_BLOCKING == object->intrPollMode) && (true == hwAttrs->intrEnable))
        {
            /* wait for the lock posted form the word completion interrupt */
            SPI_osalPendLock(object->transferComplete, SemaphoreP_WAIT_FOREVER);
        }

        if(SPI_OPER_MODE_POLLING == object->intrPollMode)
        {
            /* Wait for the QSPI busy status */
            QSPIWaitIdle(hwAttrs->baseAddr);
        }
#else

            /* Wait for the QSPI busy status */
            QSPIWaitIdle(hwAttrs->baseAddr);
#endif


        if(wordLenBytes <= 4U)
        {
            numWords = 1U;

            /* Read data from the data registers */
            QSPIreadData(hwAttrs->baseAddr, &dataVal[0], (int32_t)numWords);

            /* Write the extracted data into receive buffer */
            for(idx = 0U; idx < wordLenBytes; idx++)
            {
                *dstAddr = (uint8_t)((dataVal[0] >> (8U - (8U * (idx + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }
        }
        else if((wordLenBytes > 4U) && (wordLenBytes <= 8U))
        {
            numWords = 2U;

            /* Read data from the data registers */
            QSPIreadData(hwAttrs->baseAddr, &dataVal[0], (int32_t)numWords);

            /* Formulate the 32 bit word to write to data register */
            for(idx = 0U; idx < 4U; idx++)
            {
                *dstAddr = (uint8_t)((dataVal[0] >> (8U - (8U * (idx + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }

            for(idx1 = 4U; idx1 < wordLenBytes; idx1++)
            {
                *dstAddr = (uint8_t)((dataVal[1] >> (8U - (8U * (idx1 + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }
        }
        else if((wordLenBytes > 8U) && (wordLenBytes <= 12U))
        {
            numWords = 3U;

            /* Read data from the data registers */
            QSPIreadData(hwAttrs->baseAddr, &dataVal[0], (int32_t)numWords);

            /* Formulate the 32 bit word to write to data register */
            for(idx = 0U; idx < 4U; idx++)
            {
                *dstAddr = (uint8_t)((dataVal[0] >> (8U - (8U * (idx + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }

            for(idx1 = 4U; idx1 < 8U; idx1++)
            {
                *dstAddr = (uint8_t)((dataVal[1] >> (8U - (8U * (idx1 + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }

            for(idx2 = 8U; idx2 < 12U; idx2++)
            {
                *dstAddr = (uint8_t)((dataVal[2] >> (8U - (8U * (idx2 + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }
        }
        else if((wordLenBytes > 12U) && (wordLenBytes <= 16U))
        {
            numWords = 4U;

            /* Read data from the data registers */
            QSPIreadData(hwAttrs->baseAddr, &dataVal[0], (int32_t)numWords);

            /* Formulate the 32 bit word to write to data register */
            for(idx = 0U; idx < 4U; idx++)
            {
                *dstAddr = (uint8_t)((dataVal[0] >> (8U - (8U * (idx + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }

            for(idx1 = 4U; idx1 < 8U; idx1++)
            {
                *dstAddr = (uint8_t)((dataVal[1] >> (8U - (8U * (idx1 + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }

            for(idx2 = 8U; idx2 < 12U; idx2++)
            {
                *dstAddr = (uint8_t)((dataVal[2] >> (8U - (8U * (idx2 + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }

            for(idx3 = 12U; idx3 < 16U; idx3++)
            {
                *dstAddr = (uint8_t)((dataVal[3] >> (8U - (8U * (idx3 + 1U)))) &
                    (0x000000FFU));
                dstAddr++;
            }
        }
        else
        {
            /* Not supported */
        }

        /* Update the number of bytes to be transmitted */
        count -= wordLenBytes;
    }

    /* Update read buffer index in the object */
    object->readBufIdx = dstAddr;
}


static void QSPI_read_v1(SPI_Handle handle, const SPI_Transaction *transaction)
{
    QSPI_v1_Object  *object = NULL;

    object = (QSPI_v1_Object*)handle->object;

    if(QSPI_OPER_MODE_MMAP == object->qspiMode)
    {
        QSPI_mmap_mode_read_v1(handle, transaction);
    }

    if(QSPI_OPER_MODE_CFG == object->qspiMode)
    {
        QSPI_cmd_mode_read_v1(handle, transaction);
    }
}



static void QSPI_mmap_mode_write_v1(SPI_Handle handle,
                                    const SPI_Transaction *transaction)
{
    QSPI_HwAttrs const  *hwAttrs;          /* QSPI hardware attributes */
    uint32_t mmapWriteCmd = 0U;        /* Mmap command */
    uint32_t count = 0U;               /* transaction length */
    uint8_t *pSrc;                   /* Source address */
    uint8_t *pDst;                   /* Destination address */
    QSPI_v1_Object  *object;               /* QSPI object */
    uintptr_t offset;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (const QSPI_HwAttrs *)handle->hwAttrs;
    object = (QSPI_v1_Object*)handle->object;

    offset = (uintptr_t)transaction->txBuf;

    /* Extract memory map mode command */
    mmapWriteCmd = (uint32_t)object->transferCmd;

    QSPISetMemMapWriteCmd(hwAttrs->baseAddr, hwAttrs->chipSelect, mmapWriteCmd);
    QSPISetMemMapNumAddrBytes(hwAttrs->baseAddr, hwAttrs->chipSelect,
        QSPI_MEM_MAP_NUM_ADDR_BYTES_THREE);
    QSPISetMemAddrSpace(hwAttrs->baseAddr, hwAttrs->chipSelect,
        QSPI_MEM_MAP_PORT_SEL_MEM_MAP_PORT);

    QSPIMmapCsEnable(hwAttrs->baseAddr, hwAttrs->chipSelect);

    /* 4 byte addressing mode. */
    if(offset > (uint32_t)0xFFFFFF)
    {
        /* Switch to four byte addressing mode */
        QSPISetMemMapNumAddrBytes(hwAttrs->baseAddr, hwAttrs->chipSelect,
            QSPI_MEM_MAP_NUM_ADDR_BYTES_FOUR);
    }

#ifdef SPI_DMA_ENABLE
    if (hwAttrs->dmaEnable == true)
    {
        QSPI_dmaTransfer(handle, transaction);
    }
    else
#endif
    {
        pSrc = (uint8_t*)transaction->rxBuf;
        /* Compute the flash destination address */
        uintptr_t temp_addr = ((uintptr_t)hwAttrs->memMappedBaseAddr + (uintptr_t)transaction->txBuf);
        pDst = ((uint8_t *)(temp_addr));
        count = transaction->count;

        while(count)
        {
            *pDst = *pSrc;
            pDst++;
            pSrc++;
            count--;
        }
    }

    /* 4 byte addressing mode. */
    if(offset > (uintptr_t)0xFFFFFF)
    {
        /* Switch back to three byte addressing mode. */
        QSPISetMemMapNumAddrBytes(hwAttrs->baseAddr, hwAttrs->chipSelect,
            QSPI_MEM_MAP_NUM_ADDR_BYTES_FOUR);
    }
}


static void QSPI_cmd_mode_write_v1(SPI_Handle handle,
                                   const SPI_Transaction *transaction)
{
    QSPI_v1_Object  *object;         /* QSPI object */
    QSPI_HwAttrs const  *hwAttrs;    /* QSPI hardware attributes */
    uint32_t count = 0U;         /* transfer length in bytes */
    uint32_t wordLenBytes = 0U;  /* Word length in number of bytes */
    uint32_t cmd = 0;           /* transmit command */
    uint32_t dataVal[4] = {0U, 0U, 0U, 0U};  /* data to be written */
    uint32_t idx, idx1, idx2, idx3;          /* indexes */
    uint32_t numWords = 0U;                  /* number of words */
    uint8_t *srcAddr;                      /* Source address */

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object*)handle->object;
    hwAttrs = (const QSPI_HwAttrs *)handle->hwAttrs;

    srcAddr = object->writeBufIdx;

    /* formulate the command */
    HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_FLEN, (object->frmLength - 1));
    HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_WLEN, (object->qspiParams.dataSize - 1));
    HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_CSNUM, hwAttrs->chipSelect);
    HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_CMD,
        QSPI_SPI_CMD_REG_CMD_FOUR_PIN_WRITE_SINGLE);


    /* Enable interrupts in the polling mode */
    if ((SPI_OPER_MODE_BLOCKING == object->intrPollMode) && (true == hwAttrs->intrEnable))
    {
#ifdef WORD_INTERRUPT
        /* Enable word count interrupt */
        HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_WIRQ, true);
#else
        /* Enable frame count interrupt */
        HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_FIRQ, true);
#endif

    }
    else
    {
        /* Disable word count interrupt */
        HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_WIRQ, false);
        HW_SET_FIELD32(cmd, QSPI_SPI_CMD_REG_FIRQ, false);
    }


    /* Extract frame length in bytes */
    count = transaction->count;

    /* Extract word length in number of bytes */
    wordLenBytes = (object->qspiParams.dataSize >> 3U);

    /* Write the data into shift registers */
    while(count)
    {
        dataVal[0] = 0;
        dataVal[1] = 0;
        dataVal[2] = 0;
        dataVal[3] = 0;

        if(wordLenBytes <= 4U)
        {
            /* Formulate the 32 bit word to write to data register */
            for(idx = 0U; idx < wordLenBytes; idx++)
            {
                dataVal[0] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            numWords = 1U;
        }
        else if((wordLenBytes > 4U) && (wordLenBytes <= 8U))
        {
            /* Formulate the 32 bit word to write to data register */
            for(idx = 0U; idx < 4U; idx++)
            {
                dataVal[0] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            for(idx1 = 4U; idx1 < wordLenBytes; idx1++)
            {
                dataVal[1] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            numWords = 2U;
        }
        else if((wordLenBytes > 8U) && (wordLenBytes <= 12U))
        {
            /* Formulate the 32 bit word to write to data register */
            for(idx = 0U; idx < 4U; idx++)
            {
                dataVal[0] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            for(idx1 = 4U; idx1 < 8U; idx1++)
            {
                dataVal[1] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            for(idx2 = 8U; idx2 < 12U; idx2++)
            {
                dataVal[2] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            numWords = 3U;
        }
        else if((wordLenBytes > 12U) && (wordLenBytes <= 16U))
        {
            /* Formulate the 32 bit word to write to data register */
            for(idx = 0U; idx < 4U; idx++)
            {
                dataVal[0] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            for(idx1 = 4U; idx1 < 8U; idx1++)
            {
                dataVal[1] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            for(idx2 = 8U; idx2 < 12U; idx2++)
            {
                dataVal[2] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            for(idx3 = 12U; idx3 < 16U; idx3++)
            {
                dataVal[3] |= (((uint32_t)(*srcAddr) << (8u - (8u * (idx + 1u)))));
                srcAddr++;
            }

            numWords = 4U;
        }
        else
        {
            /* Not supported */
        }

        /* Write data to data registers */
        QSPIwriteData(hwAttrs->baseAddr, &dataVal[0], (int32_t)numWords);

        /* Write tx command to command register */
        QSPIsetCommandReg(hwAttrs->baseAddr, cmd);

#ifdef WORD_INTERRUPT
        /* interrupt mode */
        if ((SPI_OPER_MODE_BLOCKING == object->intrPollMode) && (true == hwAttrs->intrEnable))
        {
            /* wait for the lock posted form the word completion interrupt */
            SPI_osalPendLock(object->transferComplete, SemaphoreP_WAIT_FOREVER);
        }

        if(SPI_OPER_MODE_POLLING == object->intrPollMode)
        {
            /* Wait for the QSPI busy status */
            QSPIWaitIdle(hwAttrs->baseAddr);
        }
#else

        /* Wait for the QSPI busy status */
        QSPIWaitIdle(hwAttrs->baseAddr);
#endif


        /* Update the number of bytes to be transmitted */
        count -= wordLenBytes;
    }

    /* Update write buffer index in the object */
    object->writeBufIdx = srcAddr;
}


static void QSPI_write_v1(SPI_Handle handle, const SPI_Transaction *transaction)
{
    QSPI_v1_Object  *object = NULL;         /* QSPI object */

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object*)handle->object;

    if(QSPI_OPER_MODE_MMAP == object->qspiMode)
    {
        QSPI_mmap_mode_write_v1(handle, transaction);
    }

    if(QSPI_OPER_MODE_CFG == object->qspiMode)
    {
        QSPI_cmd_mode_write_v1(handle, transaction);
    }
}


/*
 *  ======== i2c_am57x_transfer ========
 */
static bool QSPI_transfer_v1(SPI_Handle handle, SPI_Transaction *transaction)
{
    bool  ret = false;                /* return value */
    QSPI_v1_Object   *object;         /* QSPI object */
    QSPI_HwAttrs const  *hwAttrs;     /* QSPI hardware attributes */

    /* Input parameter validation */
    if ((handle != NULL) && (transaction != NULL))
    {
    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object*)handle->object;
    hwAttrs = (const QSPI_HwAttrs *)handle->hwAttrs;

    /* Check if anything needs to be written or read */
    if (0 != transaction->count)
    {
        transaction->status=SPI_TRANSFER_STARTED;
		/* Acquire the lock for this particular I2C handle */
        SPI_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);

        /* Book keeping of transmit and receive buffers. */
        object->writeBufIdx = (uint8_t *)transaction->txBuf;
        object->writeCountIdx = transaction->count;
        object->readBufIdx =  (uint8_t *)transaction->rxBuf;
        object->readCountIdx = transaction->count;
        object->transaction = transaction;

         /*
         * QSPI_primeTransfer_v1 is a longer process and
         * protection is needed from the QSPI interrupt
         */
        if ((SPI_OPER_MODE_BLOCKING == object->intrPollMode) && (true == hwAttrs->intrEnable))
        {
            SPI_osalHardwareIntrEnable(hwAttrs->eventId,hwAttrs->intrNum);
        }

        QSPI_primeTransfer_v1(handle, transaction);

        if (object->intrPollMode == SPI_OPER_MODE_BLOCKING) {
#ifdef SPI_DMA_ENABLE
            if ((hwAttrs->dmaEnable == true) && (QSPI_OPER_MODE_MMAP == object->qspiMode))
            {
                SPI_osalPendLock(object->transferComplete, SemaphoreP_WAIT_FOREVER);
            }
#endif
            /* transfer is completed and semaphore is posted. */
            ret = (bool)true;
        }
        else {
            /* Always return true if in Asynchronous mode */
            ret = (bool)true;
        }

        /* Release the lock for this particular I2C handle */
        SPI_osalPostLock(object->mutex);
    } else {
	   transaction->status=SPI_TRANSFER_CANCELED;
	}
    }

    /* Return the number of bytes transferred by the I2C */
    return (ret);
}

/*
 *  ======== QSPI_transferCallback_v1 ========
 */
static void QSPI_transferCallback_v1(SPI_Handle handle, SPI_Transaction *msg)
{
    QSPI_v1_Object   *object;            /* QSPI object */

    /* Get the pointer to the object */
    object = (QSPI_v1_Object*)handle->object;

	/* Indicate transfer complete */
    SPI_osalPostLock(object->transferComplete);
}

/*
 *  ======== QSPI_control_v1 ========
 */
static int32_t QSPI_control_v1(SPI_Handle handle, uint32_t cmd, const void *arg)
{
    QSPI_v1_Object   *object;            /* QSPI object */
    int32_t retVal = SPI_STATUS_ERROR;

    /* Input parameter validation */
    if (handle != NULL)
    {
    /* Get the pointer to the object */
    object = (QSPI_v1_Object*)handle->object;

    switch (cmd)
    {
        case SPI_V1_CMD_SETFRAMELENGTH:
        {
            object->frmLength = *(uint32_t *)arg;
            retVal = SPI_STATUS_SUCCESS;
            break;
        }

        case SPI_V1_CMD_MMAP_TRANSFER_CMD:
        {
            object->transferCmd = *(uint8_t *)arg;
            retVal = SPI_STATUS_SUCCESS;
            break;
        }

        case SPI_V1_CMD_TRANSFERMODE_RW:
        {
            object->transactionType = *(uint32_t *)arg;
            retVal = SPI_STATUS_SUCCESS;
            break;
        }

        case SPI_V1_CMD_SETCONFIGMODE:
        {
            object->qspiMode = QSPI_OPER_MODE_CFG;
            retVal = SPI_STATUS_SUCCESS;
            break;
        }

        case SPI_V1_CMD_SETRXLINES:
        {
            object->rxLines = *(uint32_t *)arg;
            retVal = SPI_STATUS_SUCCESS;
            break;
        }

        case SPI_V1_CMD_SETMEMMORYMAPMODE:
        {
            object->qspiMode = QSPI_OPER_MODE_MMAP;
            retVal = SPI_STATUS_SUCCESS;
            break;
        }

        default:
        retVal = SPI_STATUS_UNDEFINEDCMD;
        break;
    }
    }

    return retVal;
}


/*
 *  ======== QSPI_transferCancel_v1 ========
 */
static void QSPI_transferCancel_v1(SPI_Handle handle)
{
    return;
}
