/**
 *  \file   SPI_v1.c
 *
 *  \brief  MCSPI IP V1 specific driver implementation.
 *
 *   This file contains the driver APIs for SPI.
 */

/*
 * Copyright (c) 2014-2019, Texas Instruments Incorporated
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

#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ti/drv/spi/MCSPI.h>
#include <ti/drv/spi/soc/SPI_v1.h>
#include <ti/csl/src/ip/mcspi/V0/mcspi.h>
#include <ti/csl/src/ip/mcspi/V0/hw_mcspi.h>
#include <ti/drv/spi/src/SPI_osal.h>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#endif

#define SPI_PARAMS_SIZE               (32U)

#define MCSPI_TX_RX_FIFO_OFFSET       (4U)

#define MCSPI_POLLING_TIMEOUT_LOOP    (1000U)

/* SPI functions */
static void          SPI_close_v1(SPI_Handle handle);
static void          SPI_init_v1(SPI_Handle handle);
static SPI_Handle    SPI_open_v1(SPI_Handle handle, const SPI_Params *params);
static bool          SPI_transfer_v1(SPI_Handle handle,
                                     SPI_Transaction *transaction);
static void          SPI_transferCancel_v1(SPI_Handle handle);
static int32_t       SPI_control_v1(SPI_Handle handle, uint32_t cmd, const void *arg);

/* MCSPI functions */
static void          MCSPI_close_v1(MCSPI_Handle mcHandle);
static void          MCSPI_init_v1(MCSPI_Handle mcHandle);
static MCSPI_Handle  MCSPI_open_v1(MCSPI_Handle mcHandle, const MCSPI_Params *params);
static bool          MCSPI_transfer_v1(MCSPI_Handle mcHandle,
                                       SPI_Transaction *transaction);
static void          MCSPI_transferCancel_v1(MCSPI_Handle mcHandle);
static int32_t       MCSPI_control_v1(MCSPI_Handle mcHandle, uint32_t cmd, const void *arg);

static MCSPI_Handle  MCSPI_get_handle(SPI_Handle handle);
static void          MCSPI_get_params(const SPI_Params *params, MCSPI_Params *mcParams);

/* SPI function table for SPI_v1 implementation */
const SPI_FxnTable SPI_FxnTable_v1 = {
    &SPI_close_v1,
    &SPI_control_v1,
    &SPI_init_v1,
    &SPI_open_v1,
    &SPI_transfer_v1,
    &SPI_transferCancel_v1,
    NULL
};

/* MCSPI function table for MCSPI_v1 implementation */
const MCSPI_FxnTable MCSPI_FxnTable_v1 =
{
    &MCSPI_close_v1,
    &MCSPI_control_v1,
    &MCSPI_init_v1,
    &MCSPI_open_v1,
    &MCSPI_transfer_v1,
    &MCSPI_transferCancel_v1
};

/*
 *  ======== MCSPI_get_handle ========
 *  @pre    Function assumes that the handle is not NULL
 */
static MCSPI_Handle MCSPI_get_handle(SPI_Handle handle)
{
    MCSPI_Handle          mcHandle = NULL;
    SPI_v1_HWAttrs const *hwAttrs;
    uint32_t              chNum;
    uint32_t              i;

    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;
    chNum   = hwAttrs->chNum;

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

/*
 *  ======== SPI_close_v1 ========
 *  @pre    Function assumes that the handle is not NULL
 */
static void SPI_close_v1(SPI_Handle handle)
{
    SPI_v1_Object   *object;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object */
        object = (SPI_v1_Object*)handle->object;

        MCSPI_close_v1(object->mcHandle);

        object->mcHandle = NULL;
    }
}

/*
 *  ======== SPI_init_v1 ========
 *  @pre    Function assumes that the handle is not NULL
 */
static void SPI_init_v1(SPI_Handle handle)
{
    MCSPI_Handle     mcHandle;
    SPI_v1_Object   *object;

    /* Input parameter validation */
    if (handle != NULL)
    {
        object = (SPI_v1_Object*)handle->object;

        /* Get multi-channel handle */
        mcHandle = MCSPI_get_handle(handle);
        if (mcHandle != NULL)
        {
            MCSPI_init_v1(mcHandle);
        }

        /* initialize object varibles */
        object->hwi                 = NULL;
        object->mutex               = NULL;
        object->transferComplete    = NULL;
        object->transferCallbackFxn = NULL;
        object->chOpenedCnt         = 0;
    }
}

/*
 *  ======== SPI_open_v1 ========
 *  @pre    Function assumes that the handle is not NULL
 */
static SPI_Handle SPI_open_v1(SPI_Handle handle, const SPI_Params *params)
{
    MCSPI_Handle          mcHandle;
    MCSPI_Params          mcParams;
    SPI_v1_Object        *object;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object */
        object = (SPI_v1_Object*)handle->object;

        /* Get multi-channel handle */
        mcHandle = MCSPI_get_handle(handle);
        if (mcHandle != NULL)
        {
            if (params != NULL)
            {
                /* covert SPI_Params to MCSPI_Params */
                MCSPI_get_params(params, &mcParams);

                /* save the transferCallbackFxn in SPI_Params */
                object->transferCallbackFxn = params->transferCallbackFxn;
            }
            mcHandle = MCSPI_open_v1(mcHandle, &mcParams);
            if (mcHandle != NULL)
            {
                object->mcHandle = mcHandle;
            }
            else
            {
                object->mcHandle = NULL;
            }
        }
    }

    return (handle);
}

/*
 *  ======== SPI_transfer_v1 ========
 *  @pre    Function assumes that handle and transaction is not NULL
 */
static bool SPI_transfer_v1(SPI_Handle handle, SPI_Transaction *transaction)
{
    MCSPI_Handle   mcHandle;
    bool           ret_val = (bool)false;

    /* Input parameter validation */
    if ((handle != NULL) && (transaction != NULL))
    {
        /* Get multi-channel handle */
        mcHandle = MCSPI_get_handle(handle);
        if (mcHandle != NULL)
        {
            ret_val = MCSPI_transfer_v1(mcHandle, transaction);
        }
    }

    return (ret_val);
}


/*
 *  ======== SPI_transferCancel_v1 ========
 */
static void SPI_transferCancel_v1(SPI_Handle handle)
{
    MCSPI_Handle   mcHandle;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get multi-channel handle */
        mcHandle = MCSPI_get_handle(handle);
        if (mcHandle != NULL)
        {
            MCSPI_transferCancel_v1(mcHandle);
        }
    }
    return;
}

/*
 *  ======== SPI_control_v1 ========
 */
static int32_t SPI_control_v1(SPI_Handle handle, uint32_t cmd, const void *arg)
{
    MCSPI_Handle   mcHandle;
    int32_t        ret_val = SPI_STATUS_ERROR;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get multi-channel handle */
        mcHandle = MCSPI_get_handle(handle);
        if (mcHandle != NULL)
        {
            ret_val = MCSPI_control_v1(mcHandle, cmd, arg);
        }
    }

    return ret_val;
}

/*
 *  ======== MCSPI_get_params ========
 *  @pre    Function assumes that params and mcParams are not NULL
 */
static void MCSPI_get_params(const SPI_Params *params, MCSPI_Params *mcParams)
{
    mcParams->transferMode        = params->transferMode;
    mcParams->transferTimeout     = params->transferTimeout;
    mcParams->transferCallbackFxn = NULL;
    mcParams->mode                = params->mode;
    mcParams->bitRate             = params->bitRate;
    mcParams->dataSize            = params->dataSize;
    mcParams->frameFormat         = params->frameFormat;
    mcParams->custom              = params->custom;

    return;
}

/*
 *  ======== MCSPI_close_v1 ========
 *  @pre    Function assumes that the handle is not NULL
 */
static void MCSPI_close_v1(MCSPI_Handle mcHandle)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_HWAttrs const *hwAttrs;
    SPI_v1_chObject      *chObj;
    uint32_t              chNum;

    /* Input parameter validation */
    if (mcHandle != NULL)
    {
    /* Get SPI handle and channel */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;

    /* Get the pointer to the instance object and channel object */
    object = (SPI_v1_Object*)handle->object;
    chObj   = &(object->chObject[chNum]);

    MCSPI_init_v1(mcHandle);

    object->chOpenedCnt--;
    if (object->chOpenedCnt == 0U)
    {
        if(object->transferComplete != NULL)
        {
            /* Destruct the semaphore */
            (void)SPI_osalDeleteBlockingLock(object->transferComplete);
            object->transferComplete = NULL;
        }

        /* All the channels closed */
        if(object->hwi != NULL)
        {
            /* Destruct the Hwi */
            (void)SPI_osalHardwareIntDestruct(object->hwi, (int32_t)hwAttrs->eventId);
            object->hwi = NULL;
        }

        if(object->mutex != NULL)
        {
            /* Destruct the instance lock */
            (void)SPI_osalDeleteBlockingLock(object->mutex);
            object->mutex = NULL;
        }

        object->mcHandle = NULL;
        object->transferCallbackFxn = NULL;
    }

#ifdef SPI_DMA_ENABLE
    if (hwAttrs->dmaMode == (bool)true)
    {
        MCSPI_dmaFreeChannel(mcHandle);
    }
#endif

    chObj->isOpen = (bool)false;
    }
}
/* Get recieved data from the RX FIFO based on the data size */

/*
 *  ======== MCSPI_receiveData_v1 ========
 *  
 *  Get recieved data words from the RX FIFO based on the data size
 *
 *  if dataSize <= 8 bits, read 8-bit word from RX FIFO,
 *  if 8 bits < dataSize <= 16 bits, read 16-bit word from RX FIFO,
 *  if 16 bits < dataSize <= 32 bits, read 32-bit word from RX FIFO,
 */
static void *MCSPI_receiveData_v1 (uint32_t baseAddr, uint32_t dataSize, void *dataBuf, uint32_t chNum);  /*for misra warnings*/
static void *MCSPI_receiveData_v1 (uint32_t baseAddr, uint32_t dataSize, void *dataBuf, uint32_t chNum)
{
    void *dataPtr;

    if (dataSize <= 8U)
    {
        *(uint8_t *)dataBuf = (uint8_t)McSPIReceiveData(baseAddr, chNum);
        dataPtr = (void *)(((uint8_t *)dataBuf) + 1U);
    }
    else if (dataSize <= 16U)
    {
        *(uint16_t *)dataBuf = (uint16_t)McSPIReceiveData(baseAddr, chNum);
        dataPtr = (void *)(((uint8_t *)dataBuf) + 2U);
    }
    else
    {
        *(uint32_t *)dataBuf = (uint32_t)McSPIReceiveData(baseAddr, chNum);
        dataPtr = (void *)(((uint8_t *)dataBuf) + 4U);
    }

    return (dataPtr);
}

/*
 *  ======== MCSPI_transmitData_v1 ========
 *  
 *  Put data to the TX FIFO based on the data size (in # of bits)
 *
 *  if dataSize <= 8 bits, write 8-bit word to TX FIFO,
 *  if 8 bits < dataSize <= 16 bits, write 16-bit word to TX FIFO,
 *  if 16 bits < dataSize <= 32 bits, write 32-bit word to TX FIFO,
 */
void *MCSPI_transmitData_v1 (uint32_t baseAddr, uint32_t dataSize, void *dataBuf, uint32_t chNum);  /*for misra warnings*/
void *MCSPI_transmitData_v1 (uint32_t baseAddr, uint32_t dataSize, void *dataBuf, uint32_t chNum)
{
    void *dataPtr;

    if (dataSize <= 8U)
    {
        McSPITransmitData(baseAddr, (uint32_t)(*(uint8_t *)dataBuf), chNum);
        dataPtr = (void *)(((uint8_t *)dataBuf) + 1U);
    }
    else if (dataSize <= 16U)
    {
        McSPITransmitData(baseAddr, (uint32_t)(*(uint16_t *)dataBuf), chNum);
        dataPtr = (void *)(((uint8_t *)dataBuf) + 2U);
    }
    else
    {
        McSPITransmitData(baseAddr, *(uint32_t *)dataBuf, chNum);
        dataPtr = (void *)(((uint8_t *)dataBuf) + 4U);
    }

    return (dataPtr);
}

/*
 *  ======== MCSPI_xferSetup_v1 ========
 *  This functions configures the transfer mode (RX/TX, RX only or TX only)
 *  and setup the TX/RX FIFO trigger level when FIFO mode is enabled
 */
void MCSPI_xferSetup_v1(MCSPI_Handle mcHandle, SPI_Transaction *transaction);  /*for misra warnings*/
void MCSPI_xferSetup_v1(MCSPI_Handle mcHandle, SPI_Transaction *transaction)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    uint32_t              chNum;
    SPI_v1_HWAttrs const *hwAttrs;
    SPI_v1_ChnCfg const  *chnCfg;
    uint32_t              transBytes=0;
    uint32_t              txFifo;
    uint32_t              rxFifo;
    uint32_t              countIndex;
    uint32_t              wordCount;

    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object = (SPI_v1_Object *)handle->object;
    chObj   = &(object->chObject[chNum]);
    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;
    chnCfg  = &(hwAttrs->chnCfg[chNum]);

    if (chnCfg->trMode == MCSPI_RX_ONLY_MODE)
    {
        chObj->writeBufIdx = NULL;
        chObj->writeCountIdx = 0;
    }
    else
    {
        chObj->writeBufIdx = (void *)transaction->txBuf;
        if (chObj->writeBufIdx != NULL)
        {
            chObj->writeCountIdx = (uint32_t)transaction->count;
        }
        else
        {
            chObj->writeCountIdx = 0;
        }
    }

    if (chnCfg->trMode == MCSPI_TX_ONLY_MODE)
    {
        chObj->readBufIdx = NULL;
        chObj->readCountIdx = 0;
    }
    else
    {
        chObj->readBufIdx = (void *)transaction->rxBuf;
        if (chObj->readBufIdx != NULL)
        {
            chObj->readCountIdx = (uint32_t)transaction->count;
        }
        else
        {
            chObj->readCountIdx = 0;
        }
    }

    /* Enable FIFO's dependent on which mode of operation is chosen */
    if (chnCfg->trMode == MCSPI_TX_RX_MODE)
    {
        if ((hwAttrs->txTrigLvl == 0U) || (hwAttrs->rxTrigLvl == 0U))
        {
            txFifo = MCSPI_TX_FIFO_DISABLE;
            rxFifo = MCSPI_RX_FIFO_DISABLE;
            object->fifoSize = 0;
        }
        else
        {
            txFifo = MCSPI_TX_FIFO_ENABLE;
            rxFifo = MCSPI_RX_FIFO_ENABLE;
            object->fifoSize = MCSPI_RX_TX_FIFO_SIZE;
        }
    }
    else if (chnCfg->trMode == MCSPI_TX_ONLY_MODE)
    {
        /* TX_ONLY Mode */
        if (hwAttrs->txTrigLvl == 0U)
        {
            txFifo = MCSPI_TX_FIFO_DISABLE;
            object->fifoSize = 0;
        }
        else
        {
            txFifo = MCSPI_TX_FIFO_ENABLE;
            object->fifoSize = MCSPI_FULL_FIFO_SIZE;
        }
        rxFifo = MCSPI_RX_FIFO_DISABLE;
    }
    else
    {
        /* RX_ONLY Mode */
        txFifo = MCSPI_TX_FIFO_DISABLE;
        if (hwAttrs->rxTrigLvl == 0U)
        {
            rxFifo = MCSPI_RX_FIFO_DISABLE;
            object->fifoSize = 0;
        }
        else
        {
            rxFifo = MCSPI_RX_FIFO_ENABLE;
            object->fifoSize = MCSPI_FULL_FIFO_SIZE;
        }
    }
    McSPITxFIFOConfig(hwAttrs->baseAddr, txFifo, chNum);
    McSPIRxFIFOConfig(hwAttrs->baseAddr, rxFifo, chNum);

    if (object->fifoSize > 0U)
    {
        /* FIFO mode is enabled */

        /* Set FIFO XFER levels */
        transBytes = (uint32_t)transaction->count << chObj->wordLenShift;

        if (transBytes <= object->fifoSize)
        {
            /* Transaction fits entirely in FIFO */
            object->rxTrigLvl = transBytes;
            object->txTrigLvl = transBytes;
        }
        else
        {
            /*
             * Transaction count is more than FIFO size
             */
            object->rxTrigLvl = hwAttrs->rxTrigLvl;
            object->txTrigLvl = hwAttrs->txTrigLvl;

#ifdef SPI_DMA_ENABLE
            if (hwAttrs->dmaMode == (bool)true)
            {
                /*
                 * In DMA mode, update the transaction count to be
                 * multiple of FIFO trigger level size
                 */
                if (chnCfg->trMode == MCSPI_RX_ONLY_MODE)
                {
                    transBytes = (transBytes / object->rxTrigLvl) * object->rxTrigLvl;
                }
                else
                {
                    transBytes = (transBytes / object->txTrigLvl) * object->txTrigLvl;
                }
                transaction->count = (uint32_t)(transBytes >> chObj->wordLenShift);
            }
            else
#endif
            {
                /*
                 * In non-DMA mode, if the RX trigger level equals to the FIFO size,
                 * set the RX trigger level less than the FIFO size, so that TX FIFO
                 * will not under run.
                 */
                if ((chnCfg->trMode == MCSPI_TX_RX_MODE) &&
                    (object->rxTrigLvl == object->fifoSize))
                {
                    object->rxTrigLvl -= MCSPI_TX_RX_FIFO_OFFSET;
                }
            }
        }
        McSPIFIFOTrigLvlSet(hwAttrs->baseAddr, (uint8_t)object->rxTrigLvl,
                            (uint8_t)object->txTrigLvl, chnCfg->trMode);
    }

    /* 
     * convert trigger level (in bytes) to word count 
     * based on the word length
     */
    if (object->fifoSize > 0U)
    {
#ifdef SPI_DMA_ENABLE
        if (hwAttrs->dmaMode == (bool)true)
        {
            wordCount = object->txTrigLvl >> chObj->wordLenShift;
        }
        else
#endif
        {
            if (transBytes > MCSPI_RX_TX_FIFO_SIZE)
            {
                wordCount = (uint32_t)MCSPI_RX_TX_FIFO_SIZE >> (chObj->wordLenShift);
            }
            else
            {
                wordCount = transBytes >> chObj->wordLenShift;
            }
        }
    }
    else
    {
        wordCount = 1U;
    }
    /* Set number of words to be transmitted */
    McSPIWordCountSet(hwAttrs->baseAddr, (uint16_t)transaction->count);

    if ((SPI_SLAVE == chObj->spiParams.mode) && (chObj->writeCountIdx != 0U))
    {
#ifdef SPI_DMA_ENABLE
        if (hwAttrs->dmaMode == (bool)false)
        {
            for (countIndex = 0; countIndex < wordCount; countIndex++)
            {
                chObj->writeBufIdx = MCSPI_transmitData_v1 (hwAttrs->baseAddr,
                                                            chObj->spiParams.dataSize,
                                                            chObj->writeBufIdx,
                                                            chNum);
                chObj->writeCountIdx--;
            }
        }
#else
        for (countIndex = 0; countIndex < wordCount; countIndex++)
        {
            chObj->writeBufIdx = MCSPI_transmitData_v1 (hwAttrs->baseAddr,
                                                        chObj->spiParams.dataSize,
                                                        chObj->writeBufIdx,
                                                        chNum);
            chObj->writeCountIdx--;
        }
#endif
    }
}

static bool MCSPI_pollingXferTimeout_v1(uint32_t *timeout, uint32_t *timeoutLoop, uint32_t timeoutVal);
static bool MCSPI_pollingXferTimeout_v1(uint32_t *timeout, uint32_t *timeoutLoop, uint32_t timeoutVal)
{
    bool     timeoutFlag = (bool)false;

    if (*timeout > 0U)
    {
        *timeout -= 1U;
        if (*timeout == 0U)
        {
            if (*timeoutLoop > 0U)
            {
                *timeoutLoop -= 1U;
                *timeout = timeoutVal;
            }
        }
    }
    else
    {
        if (*timeoutLoop == 0U)
        {
            /* Polling transfer timed out */
            timeoutFlag = (bool)true;
        }
    }

    return (timeoutFlag);
}

/*
 *  ======== MCSPI_primeTransfer_v1 ========
 *  This functions configures the transmit and receive channels for a given
 *  MCSPI_Handle and SPI_Transaction.
 *
 *  Slave driver needs to pre-fill the TX trigger level size data to TX FIFO first before
 *  the channel is enabled. If the transfer size is less than the FIFO size (32 bytes), the
 *  TX/RX trigger level is set to the transfer size. If the transfer size is greater than
 *  or equal to the FIFO size, the TX/RX trigger level is set to the FIFO size. The pre-filling
 *  is required to ensure the TX data is available for master to receive when the channel is
 *  enabled.
 *
 *  In polling mode, master driver continuously writes 1 byte TX data to TX FIFO followed
 *  by reading 1 byte RX data from the RX FIFO until all the data are transfered. slave driver
 *  continuously reads 1 byte data from the RX FIFO followed by writing 1 byte TX data to TX
 *  FIFO until all the data are transfered.
 *
 *  In interrupt mode, master driver enables TX empty, RX full and end of word count interrupts.
 *  slave driver enabls RX full interrupt. The TX/RX data are handled in the ISR.
 *
 *  @pre    Function assumes that the handle and transaction is not NULL
 */
static void MCSPI_primeTransfer_v1(MCSPI_Handle mcHandle, SPI_Transaction *transaction);  /* for misra warnings */
static void MCSPI_primeTransfer_v1(MCSPI_Handle mcHandle, SPI_Transaction *transaction)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    uint32_t              chNum;
    SPI_v1_HWAttrs const *hwAttrs;
    SPI_v1_ChnCfg const  *chnCfg;
    uint32_t              channelStatus = 0;
    uint32_t              intStatus;
    uint32_t              timeout;
    uint32_t              timeoutLoop;
    bool                  timeoutFlag;

    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object = (SPI_v1_Object *)handle->object;
    chObj   = &(object->chObject[chNum]);
    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;
    chnCfg  = &(hwAttrs->chnCfg[chNum]);

    /* Enable the McSPI channel for communication */
    McSPIChannelEnable(hwAttrs->baseAddr, chNum);

    /* setup transfer mode and FIFO trigger levels */
    MCSPI_xferSetup_v1(mcHandle, transaction);

    /* Interrupt Mode */
    if(chObj->operMode != (uint32_t)SPI_OPER_MODE_POLLING)
    {
        intStatus =  MCSPI_INT_EOWKE;
        if (chnCfg->trMode == MCSPI_TX_ONLY_MODE)
        {
            intStatus |= (uint32_t)MCSPI_INT_TX_EMPTY(chNum);
        }
        else if (chnCfg->trMode == MCSPI_RX_ONLY_MODE)
        {
            intStatus |= (uint32_t)(MCSPI_INT_RX_FULL(chNum));
        }
        else
        {
            intStatus |= (uint32_t)(MCSPI_INT_RX_FULL(chNum)) | (uint32_t)(MCSPI_INT_TX_EMPTY(chNum));
        }
        McSPIIntStatusClear(hwAttrs->baseAddr, intStatus);

        if(SPI_MASTER == chObj->spiParams.mode)
        {
            McSPIIntEnable(hwAttrs->baseAddr, intStatus);

            if (hwAttrs->chMode == MCSPI_SINGLE_CH)
            {
                /* Assert un-used chip select (Force SPIEN) */
                McSPICSAssert(hwAttrs->baseAddr, chNum);
            }
        }
        else
        {
            McSPIIntEnable(hwAttrs->baseAddr, (uint32_t)(MCSPI_INT_RX_FULL(chNum)));
        }
    }
    /* Polling mode */
    else
    {
        if ((SPI_MASTER == chObj->spiParams.mode) &&
            (hwAttrs->chMode == MCSPI_SINGLE_CH))
        {
            /* SPIEN line is forced to low state.*/
            McSPICSAssert(hwAttrs->baseAddr, chNum);
        }

        /* Initialize the timeout value and loop count in polling mode */
        timeout = chObj->spiParams.transferTimeout;
        timeoutLoop = MCSPI_POLLING_TIMEOUT_LOOP;
        timeoutFlag = (bool)false;

        /* Polling mode transfer */
        while (((chObj->readCountIdx != 0U) || (chObj->writeCountIdx != 0U)) &&
               (timeoutFlag == (bool)false))
        {
            channelStatus = McSPIChannelStatusGet(hwAttrs->baseAddr, chNum);
            if ((SPI_MASTER == chObj->spiParams.mode) && (chObj->writeCountIdx != 0U))
            {
                while (0U == (channelStatus & CSL_MCSPI_CH0STAT_TXS_MASK))
                {
                    channelStatus = McSPIChannelStatusGet(hwAttrs->baseAddr, chNum);
                    timeoutFlag = MCSPI_pollingXferTimeout_v1(&timeout,
                                                              &timeoutLoop,
                                                              chObj->spiParams.transferTimeout);
                    if (timeoutFlag == (bool)true)
                    {
                        break;
                    }
                }
                if (timeoutFlag == (bool)false)
                {
                    chObj->writeBufIdx = MCSPI_transmitData_v1 (hwAttrs->baseAddr,
                                                                chObj->spiParams.dataSize,
                                                                chObj->writeBufIdx,
                                                                chNum);
                    chObj->writeCountIdx--;
                }
            }

            if ((chObj->readCountIdx != 0U) && (timeoutFlag == (bool)false))
            {
                while (0U == (channelStatus & CSL_MCSPI_CH0STAT_RXS_MASK))
                {
                    channelStatus = McSPIChannelStatusGet(hwAttrs->baseAddr, chNum);
                    timeoutFlag = MCSPI_pollingXferTimeout_v1(&timeout,
                                                              &timeoutLoop,
                                                              chObj->spiParams.transferTimeout);
                    if (timeoutFlag == (bool)true)
                    {
                        break;
                    }
                }
                if (timeoutFlag == (bool)false)
                {
                    chObj->readBufIdx = MCSPI_receiveData_v1(hwAttrs->baseAddr,
                                                             chObj->spiParams.dataSize,
                                                             chObj->readBufIdx,
                                                             chNum);
                    chObj->readCountIdx--;
                }
            }

            if ((SPI_SLAVE == chObj->spiParams.mode) &&
                (chObj->writeCountIdx != 0U)         &&
                (timeoutFlag == (bool)false))
            {
                chObj->writeBufIdx = MCSPI_transmitData_v1 (hwAttrs->baseAddr,
                                                            chObj->spiParams.dataSize,
                                                            chObj->writeBufIdx,
                                                            chNum);

                chObj->writeCountIdx--;
            }

            if ((chObj->readCountIdx != 0U) || (chObj->writeCountIdx != 0U))
            {
                timeoutFlag = MCSPI_pollingXferTimeout_v1(&timeout,
                                                          &timeoutLoop,
                                                          chObj->spiParams.transferTimeout);
                if (timeoutFlag == (bool)true)
                {
                    /* Transfer timeout */
                    transaction->status=SPI_TRANSFER_TIMEOUT;
                }
            }
            else
            {
                /* Transfer completed successfully */
                transaction->status=SPI_TRANSFER_COMPLETED;
            }
        }

        if ((SPI_MASTER == chObj->spiParams.mode) &&
            (hwAttrs->chMode == MCSPI_SINGLE_CH))
        {
            /* Force SPIEN line to the inactive state.*/
            McSPICSDeAssert(hwAttrs->baseAddr, chNum);
        }

        /* Disable the McSPI channel.*/
        McSPIChannelDisable(hwAttrs->baseAddr, chNum);

        chObj->transaction = NULL;
    }
}

/*
 *  ======== MCSPI_v1_hwiFxn ========
 *  ISR for the MCSPI in master and slave mode
 *
 *  For both TX and RX enabled mode, the following interrupts are enabled:
 *
 *   TX empty interrupt (master only)
 *   RX full interrupt
 *   End of word count interrupt (master only)
 *
 *  When TX empty interrupt happens, ISR will continuously write TX data
 *  to TX FIFO until the FIFO is full or all the TX data is sent out.
 *
 *  When RX full interrupt happens, ISR will continuously read 1 byte
 *  RX data from RX FIFO followed by writing 1 byte TX data to TX FIFO
 *  until the RX FIFO is empty. When all the bytes are transfered or
 *  end of word count interrupt happens (master only), ISR
 *  will disable all the interrupts and call back to the application
 *  in callback mode or release the semaphore in blocking mode.
 *
 *  If the remaining RX count is less than the RX FIFO size,
 *  ISR will set the RX trigger level to the remaing RX count.
 *
 *  To prevent TX FIFO underrun, RX FIFO trigger level is set less
 *  than the max TX FIFO size
 */
static void MCSPI_v1_hwiFxn (uintptr_t arg); /* for misra warnings */
static void MCSPI_v1_hwiFxn (uintptr_t arg)
{
    MCSPI_Handle          mcHandle;
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    uint32_t              chNum;
    SPI_v1_HWAttrs const *hwAttrs;
    SPI_v1_ChnCfg const  *chnCfg;
    uint32_t              intCode = 0;
    bool                  trigLvlChg = (bool)false;
    uint32_t              rdBytes;
    uint32_t              wrBytes;
    uint32_t              chnStatus;
    bool                  loopFlag = (bool)true;
    uint32_t              masterTxCnt = 0;

    /* Get the pointer to the object and hwAttrs */
    mcHandle = (MCSPI_Handle)arg;
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object = (SPI_v1_Object *)handle->object;
    chObj   = &(object->chObject[chNum]);
    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;
    chnCfg  = &(hwAttrs->chnCfg[chNum]);

    intCode = McSPIIntStatusGet(hwAttrs->baseAddr);

    while (((chObj->readCountIdx != 0U) || (chObj->writeCountIdx != 0U)) &&
           (loopFlag == (bool)true))
    {
        chnStatus = McSPIChannelStatusGet(hwAttrs->baseAddr, chNum);
        if (SPI_MASTER == chObj->spiParams.mode)
        {
            if (chObj->writeCountIdx != 0U)
            {
                if (0U == (chnStatus & CSL_MCSPI_CH0STAT_TXFFF_MASK))
                {
                    /* TX FIFO is not full */
                    chObj->writeBufIdx = MCSPI_transmitData_v1 (hwAttrs->baseAddr,
                                                                chObj->spiParams.dataSize,
                                                                chObj->writeBufIdx,
                                                                chNum);
                    chObj->writeCountIdx--;
                    masterTxCnt++;
                }
                else
                {
                    loopFlag = (bool)false;
                }
            }
            else
            {
                loopFlag = (bool)false;
            }
        }

        if (chObj->readCountIdx != 0U)
        {
            if ((0U == (chnStatus & CSL_MCSPI_CH0STAT_RXFFE_MASK)) ||
                (0U != (chnStatus & CSL_MCSPI_CH0STAT_RXS_MASK)))
            {
                /* RX FIFO is not empty or RX register is full */
                chObj->readBufIdx = MCSPI_receiveData_v1(hwAttrs->baseAddr,
                                                         chObj->spiParams.dataSize,
                                                         chObj->readBufIdx,
                                                         chNum);
                chObj->readCountIdx--;
                loopFlag = (bool)true;
            }
            else
            {
                if (SPI_MASTER != chObj->spiParams.mode)
                {
                    loopFlag = (bool)false;
                }
            }
        }
        else
        {
            if (SPI_MASTER != chObj->spiParams.mode)
            {
                loopFlag = (bool)false;
            }
        }

        if ((SPI_SLAVE == chObj->spiParams.mode) &&
            (chObj->writeCountIdx != 0U))
        {
            if (0U == (chnStatus & CSL_MCSPI_CH0STAT_TXFFF_MASK))
            {
                /* TX FIFO is not full */
                chObj->writeBufIdx = MCSPI_transmitData_v1 (hwAttrs->baseAddr,
                                                            chObj->spiParams.dataSize,
                                                            chObj->writeBufIdx,
                                                            chNum);
                chObj->writeCountIdx--;
                loopFlag = (bool)true;
            }
        }
        if (masterTxCnt == object->txTrigLvl)
        {
            loopFlag = (bool)false;
        }
    }

    /* Update the TX trigger level */
    if (chObj->writeCountIdx != 0U)
    {
        wrBytes = chObj->writeCountIdx << chObj->wordLenShift;
        if (wrBytes < object->txTrigLvl)
        {
            object->txTrigLvl = wrBytes;
            trigLvlChg = (bool)true;
        }
    }

    /* Update the RX trigger level */
    if (chObj->readCountIdx > 1U)
    {
        rdBytes = chObj->readCountIdx << chObj->wordLenShift;
        if (rdBytes < object->rxTrigLvl)
        {
            object->rxTrigLvl = rdBytes;
            if (chObj->writeCountIdx == 0U)
            {
                object->txTrigLvl = object->fifoSize;
            }
            trigLvlChg = (bool)true;
        }
    }

    if (trigLvlChg == (bool)true)
    {
        McSPIFIFOTrigLvlSet(hwAttrs->baseAddr, (uint8_t)object->rxTrigLvl,
                            (uint8_t)object->txTrigLvl, chnCfg->trMode);
    }

    /*if (MCSPI_INT_EOWKE == (intCode & MCSPI_INT_EOWKE))*/
    if ((MCSPI_INT_EOWKE == (intCode & MCSPI_INT_EOWKE)) ||
        ((chObj->writeCountIdx == 0U) && (chObj->readCountIdx <= 1U) && (chnCfg->trMode != MCSPI_TX_ONLY_MODE)))
    {
        chnStatus = McSPIChannelStatusGet(hwAttrs->baseAddr, chNum);
        while ((0U == (chnStatus & CSL_MCSPI_CH0STAT_EOT_MASK)))
        {
            chnStatus = McSPIChannelStatusGet(hwAttrs->baseAddr, chNum);
        }
        if (chObj->readCountIdx != 0U)
        {
            /* Read final RX byte */
            chObj->readBufIdx = MCSPI_receiveData_v1(hwAttrs->baseAddr,
                                                     chObj->spiParams.dataSize,
                                                     chObj->readBufIdx,
                                                     chNum);
            chObj->readCountIdx--;
        }
        /* Transaction Done */
        intCode = (uint32_t)(MCSPI_INT_RX_FULL(chNum))  |
                  (uint32_t)(MCSPI_INT_TX_EMPTY(chNum)) |
                  MCSPI_INT_EOWKE;
        McSPIIntDisable(hwAttrs->baseAddr,intCode);
        McSPIIntStatusClear(hwAttrs->baseAddr, intCode);
        if ((SPI_MASTER == chObj->spiParams.mode) &&
            (hwAttrs->chMode == MCSPI_SINGLE_CH))
        {
            McSPICSDeAssert(hwAttrs->baseAddr, chNum);
        }
        McSPIChannelDisable(hwAttrs->baseAddr, chNum);
        chObj->transaction->status=SPI_TRANSFER_COMPLETED;
        MCSPI_transferCallback_v1((MCSPI_Handle)arg, chObj->transaction);
    }

    McSPIIntStatusClear(hwAttrs->baseAddr, intCode);
}

/*
 *  ======== MCSPI_init_v1 ========
 *  @pre    Function assumes that the handle is not NULL
 */
static void MCSPI_init_v1(MCSPI_Handle mcHandle)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    uint32_t              chNum;

    /* Input parameter validation */
    if (mcHandle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        handle  = mcHandle->handle;
        chNum   = mcHandle->chnNum;
        object = (SPI_v1_Object*)handle->object;
        chObj   = &(object->chObject[chNum]);

        /* reset channel object */
        (void)memset(chObj, 0, sizeof(SPI_v1_chObject));
        chObj->isOpen = (bool)false;
    }
}

/*
 *  ======== MCSPI_open_v1 ========
 *  @pre    Function assumes that the mcHandle is not NULL
 */
static MCSPI_Handle MCSPI_open_v1(MCSPI_Handle        mcHandle,
                                  const MCSPI_Params *params)
{
    SPI_Handle            handle;
    MCSPI_Handle          retMcHandle = mcHandle;
    const MCSPI_Params   *pParams = params;
    SemaphoreP_Params     semParams;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    uint32_t              chNum;
    SPI_v1_HWAttrs const *hwAttrs;
    SPI_v1_ChnCfg const  *chnCfg;
    OsalRegisterIntrParams_t interruptRegParams;
    uint32_t              ret_flag = 0u;

    /* Input parameter validation */
    if (mcHandle != NULL)
    {
    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object = (SPI_v1_Object *)handle->object;
    chObj   = &(object->chObject[chNum]);
    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;
    chnCfg  = &(hwAttrs->chnCfg[chNum]);

    /* Determine if the device index was already opened */
    if(chObj->isOpen == (bool)true) {
        retMcHandle = NULL;
    }
    else
    {
        /* Mark the channel handle as being used */
        chObj->isOpen = (bool)true;

        /* Store the SPI parameters */
        if (pParams == NULL)
        {
            /* No params passed in, so use the defaults */
            MCSPI_Params_init(&(chObj->spiParams));
            pParams = &(chObj->spiParams);
        }
        else
        {
            chObj->spiParams = *pParams;
        }

        if (pParams->dataSize < 4U)
        {
            /* wrong data size param */
            retMcHandle = NULL;
            ret_flag = 1U;
        }
        else if (pParams->dataSize <= 8U)
        {
            chObj->wordLenShift = 0U;
        }
        else if (pParams->dataSize <= 16U)
        {
            chObj->wordLenShift = 1U;
        }
        else if (pParams->dataSize <= 32U)
        {
            chObj->wordLenShift = 2U;
        }
        else
        {
            /* wrong data size param */
            retMcHandle = NULL;
            ret_flag = 1U;
        }

        /* Store the current mode. Extract operating mode from hwAttrs and params */
        if(SPI_MODE_BLOCKING == pParams->transferMode)
        {
            if ((bool)true == hwAttrs->enableIntr)
            {
                chObj->operMode = (uint32_t)SPI_OPER_MODE_BLOCKING;
            }
#ifdef SPI_DMA_ENABLE
            else if ((bool)true == hwAttrs->dmaMode)
            {
                chObj->operMode = (uint32_t)SPI_OPER_MODE_BLOCKING;
            }
#endif
            else
            {
                chObj->operMode = (uint32_t)SPI_OPER_MODE_POLLING;
            }
        }
        else
        {
            chObj->operMode = (uint32_t)SPI_OPER_MODE_CALLBACK;
            /* Check to see if a callback function was defined for async mode */
            if ((pParams->transferCallbackFxn == NULL) &&
                (object->transferCallbackFxn == NULL))
            {
                retMcHandle = NULL;
                ret_flag = 1U;
            }
        }

        if ((chObj->operMode != (uint32_t)SPI_OPER_MODE_POLLING) &&
            (object->hwi == NULL))
        {
            /* register interrrupt when the 1st
               channel of the instance is opened */
            Osal_RegisterInterrupt_initParams(&interruptRegParams);             

            interruptRegParams.corepacConfig.name=NULL;
#ifdef __TI_ARM_V7R4
            interruptRegParams.corepacConfig.priority=0x8U;
#else
            interruptRegParams.corepacConfig.priority=0x20U;
#endif
            interruptRegParams.corepacConfig.corepacEventNum = (int32_t)hwAttrs->eventId;
            interruptRegParams.corepacConfig.intVecNum = (int32_t)hwAttrs->intNum; /* Host Interrupt vector */
            interruptRegParams.corepacConfig.isrRoutine  = (void (*)(uintptr_t))(&MCSPI_v1_hwiFxn);
            interruptRegParams.corepacConfig.arg         = (uintptr_t)mcHandle;

            (void)SPI_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));

            if(object->hwi == NULL)
            {
                MCSPI_close_v1(mcHandle);
                ret_flag = 1u;
                retMcHandle = NULL;
            }
        }

        if(ret_flag == 0u)
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

            if (chObj->operMode == (uint32_t)SPI_OPER_MODE_BLOCKING)
            {
                /*
                 * Construct a semaphore to block task execution for the duration of the
                 * SPI transfer
                 */
                if (object->transferComplete == NULL)
                {
                    SPI_osalSemParamsInit(&semParams);
                    semParams.mode = SemaphoreP_Mode_BINARY;
                    object->transferComplete = SPI_osalCreateBlockingLock(0U, &semParams);
                }
            }

            chObj->transaction = NULL;

            /* Extract clock mode from the frame format */
            switch(pParams->frameFormat)
            {
                case SPI_POL0_PHA0:
                    chObj->clockMode = MCSPI_CLK_MODE_0;
                    break;

                case SPI_POL0_PHA1:
                    chObj->clockMode = MCSPI_CLK_MODE_1;
                    break;

                case SPI_POL1_PHA0:
                    chObj->clockMode = MCSPI_CLK_MODE_2;
                    break;

                case SPI_POL1_PHA1:
                    chObj->clockMode = MCSPI_CLK_MODE_3;
                    break;

                default:
                	chObj->clockMode = MCSPI_CLK_MODE_2;
                    break;
            }

            if (object->chOpenedCnt == 0U)
            {
#ifdef SPI_DMA_ENABLE
                if (hwAttrs->dmaMode == (bool)true)
                {
                    /* DMA Configuration */
                    (void)MCSPI_dmaConfig(mcHandle);

                    McSPIDMADisable(hwAttrs->baseAddr,
                                    ((uint32_t) MCSPI_DMA_RX_EVENT | (uint32_t) MCSPI_DMA_TX_EVENT),
                                    chNum);
                }
#endif
                /* Reset SPI Peripheral */
                McSPIReset(hwAttrs->baseAddr);

                MCSPISysConfigSetup(hwAttrs->baseAddr, MCSPI_CLOCKS_OCP_ON_FUNC_ON,
                                    MCSPI_SIDLEMODE_NO, MCSPI_WAKEUP_DISABLE,
                                    MCSPI_AUTOIDLE_OFF);

                if (hwAttrs->chMode == MCSPI_SINGLE_CH)
                {
                    /* Configure 3 pin or 4 pin mode */
                    if((uint32_t)SPI_PINMODE_3_PIN == hwAttrs->pinMode)
                    {
                        /* Disable chip select pin.*/
                        McSPICSDisable(hwAttrs->baseAddr);
                    }
                    else
                    {
                        /* Enable chip select pin.*/
                        McSPICSEnable(hwAttrs->baseAddr);
                    }
                }
            }

            if ((object->chOpenedCnt != 0U) &&
                ((pParams->mode != SPI_MASTER) || (object->mode != SPI_MASTER)))
            {

                /*
                 * McSPI supports multiple master channels or single slave channel per instance:
                 *
                 * 1. if an instance has already had a channle opened in SPI_MASTER mode,
                 * the new channel being opened should have the same SPI mode as the previous
                 * channel opened.
                 *
                 * 2. if an instance has already had a channle opened in SPI_SLAVE mode,
                 * no new channel can be opened.
                 */
                ret_flag = 1u;
                retMcHandle = NULL;
            }

            if((SPI_MASTER == pParams->mode) && (ret_flag == 0U))
            {
                if (object->chOpenedCnt == 0U)
                {
                    /*
                     * first channel opened in this instance,
                     * enable SPI Master
                     */
                    McSPIMasterModeEnable(hwAttrs->baseAddr);
                    object->mode = SPI_MASTER;
                }

                /* Configure the peripheral as single channel SPI Master */
                (void)McSPIMasterModeConfig(hwAttrs->baseAddr,
                                            hwAttrs->chMode,
                                            chnCfg->trMode,
                                            chnCfg->dataLineCommMode,
                                            chNum);
                /* Clock configuration */
                McSPIClkConfig(hwAttrs->baseAddr,
                               hwAttrs->inputClkFreq,
                               pParams->bitRate,
                               chNum,
                               chObj->clockMode);

                /* configure initial SPI delay only in signle master mode */
                if ((hwAttrs->chMode == MCSPI_SINGLE_CH) && (object->chOpenedCnt == 0U))
                {
                    McSPIInitDelayConfig(hwAttrs->baseAddr, hwAttrs->initDelay);
                }
            }
            else
            {
                if (object->chOpenedCnt == 0U)
                {
                    /*
                     * first channel opened in this instance,
                     * enable SPI Slave
                     */
                    McSPISlaveModeEnable(hwAttrs->baseAddr);
                    object->mode = SPI_SLAVE;
                }

                /* Clock configuration */
                McSPIClkConfig(hwAttrs->baseAddr,
                               hwAttrs->inputClkFreq,
                               pParams->bitRate,
                               chNum,
                               chObj->clockMode);

                /* Set pin direction. */
                (void)MCSPIPinDirSet(hwAttrs->baseAddr,
                                     chnCfg->trMode,
                                     chnCfg->dataLineCommMode,
                                     chNum);
            }

            /* Set word length for corresponding channel */
            McSPIWordLengthSet(hwAttrs->baseAddr,
                               MCSPI_WORD_LENGTH(pParams->dataSize),
                               chNum);

            /* Set polarity of SPIEN to low.*/
            McSPICSPolarityConfig(hwAttrs->baseAddr,
                                  chnCfg->csPolarity,
                                  chNum);
        }

        if(SPI_MASTER == pParams->mode)
        {
            /* Configure chip-select time control */
            McSPICSTimeControlSet(hwAttrs->baseAddr, chnCfg->tcs, chNum);
        }

        /* increment the channel opened count */
        object->chOpenedCnt++;
    }
    }

    return (retMcHandle);
}

/*
 *  ======== MCSPI_transfer_v1 ========
 *  @pre    Function assumes that mcHandle and transaction is not NULL
 */
static bool MCSPI_transfer_v1(MCSPI_Handle mcHandle, SPI_Transaction *transaction)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    SPI_v1_HWAttrs const *hwAttrs;
    uint32_t              chNum, clrInt = 0U;;
    bool                  ret_val = (bool)false;
    SemaphoreP_Status   semStatus = SemaphoreP_OK;

    /* Input parameter validation */
    if ((mcHandle != NULL) && (transaction != NULL))
    {
    /* Get the pointer to the object and hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object = (SPI_v1_Object *)handle->object;
    chObj   = &(object->chObject[chNum]);
    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;

    /* Acquire the lock for the SPI transfer on this instance */
    (void)SPI_osalPendLock(object->mutex, SemaphoreP_WAIT_FOREVER);
    if (chObj->spiParams.transferTimeout == 0U)
    {
        /* timeout cannot be NO_WAIT, set it to default value */
        chObj->spiParams.transferTimeout = SPI_WAIT_FOREVER;
    }

    if ((uint32_t)transaction->count != 0U)
    {
        transaction->status = SPI_TRANSFER_STARTED;

        /* Check if a transfer is in progress */
        if (chObj->transaction != NULL)
        {
            transaction->status = SPI_TRANSFER_CANCELED;

            /* transfer is in progress */
            ret_val = (bool)false;
        }
        else
        {
            /* Save the pointer to the transaction */
            chObj->transaction = transaction;

#ifdef SPI_DMA_ENABLE
            if (hwAttrs->dmaMode == (bool)true)
            {
                MCSPI_dmaTransfer(mcHandle, transaction);
            }
            else
#endif
            {
                MCSPI_primeTransfer_v1(mcHandle, transaction);
            }

            if (chObj->operMode == (uint32_t)SPI_OPER_MODE_BLOCKING)
            {
                semStatus = SPI_osalPendLock(object->transferComplete, chObj->spiParams.transferTimeout);
            }
            if (semStatus == SemaphoreP_TIMEOUT)
            {
                /* clear the interrupts */
                clrInt = (uint32_t)((MCSPI_INT_TX_EMPTY(chNum) | MCSPI_INT_RX_FULL(chNum)
                                    | MCSPI_INT_EOWKE));
                if(SPI_MASTER == chObj->spiParams.mode)
                {
                    McSPIIntDisable(hwAttrs->baseAddr, clrInt);
                }
                else
                {
                    McSPIIntDisable(hwAttrs->baseAddr, (uint32_t)(MCSPI_INT_RX_FULL(chNum)));
                }
                McSPIIntStatusClear(hwAttrs->baseAddr, clrInt);
                if ((SPI_MASTER == chObj->spiParams.mode) &&
                    (hwAttrs->chMode == MCSPI_SINGLE_CH))
                {
                    McSPICSDeAssert(hwAttrs->baseAddr, chNum);
                }
                McSPIChannelDisable(hwAttrs->baseAddr, chNum);

                /*
                 * Interrupt/dma (timeout) transaction
                 * returns timeout status
                 */
                transaction->status=SPI_TRANSFER_TIMEOUT;
                chObj->transaction = NULL;
                ret_val = (bool)false;
            }
            else
            {
                if (chObj->operMode == (uint32_t)SPI_OPER_MODE_POLLING)
                {
                    /*
                     * Polling transaction status is set in MCSPI_primeTransfer_v1
                     */
                    if (transaction->status == SPI_TRANSFER_COMPLETED)
                    {
                        ret_val = (bool)true;
                    }
                    else
                    {
                        ret_val = (bool)false;
                    }
                }
                else
                {
                    /*
                     * Callback transaction or interrupt/dma (no timeout) transaction
                     * returns completed status
                     */
                    transaction->status = SPI_TRANSFER_COMPLETED;
                    ret_val = (bool)true;
                }
            }
        }
    }
    else
    {
        transaction->status=SPI_TRANSFER_CANCELED;
    }

    /* Release the lock for the SPI transfer on this instance */
    (void)SPI_osalPostLock(object->mutex);
    }

    return (ret_val);
}

/*
 *  ======== MCSPI_transferCallback_v1 ========
 *  Callback function for when the SPI is in SPI_MODE_BLOCKING
 *
 *  @pre    Function assumes that the handle is not NULL
 */
void MCSPI_transferCallback_v1(MCSPI_Handle     mcHandle,
                               SPI_Transaction *transaction)
{
    SPI_Handle         handle;
    SPI_v1_Object     *object;
    SPI_v1_chObject   *chObj;
    uint32_t           chNum;

    if (mcHandle != NULL)
    {
    /* Get the pointer to the channel object */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object = (SPI_v1_Object*)handle->object;
    chObj   = &(object->chObject[chNum]);

    if (chObj->operMode == (uint32_t)SPI_OPER_MODE_CALLBACK)
    {
        if (object->transferCallbackFxn != NULL)
        {
            /* Single channel mode callback */
            object->transferCallbackFxn(handle, transaction);
        }
        else
        {
            /* multi channel mode callback */
            chObj->spiParams.transferCallbackFxn(mcHandle, transaction);
        }
    }
    else
    {
        (void)SPI_osalPostLock(object->transferComplete);
    }

    chObj->transaction = NULL;
    }
}

/*
 *  ======== MCSPI_transferCancel_v1 ========
 */
static void MCSPI_transferCancel_v1(MCSPI_Handle mcHandle)
{
    SPI_Handle            handle;
    SPI_v1_Object        *object;
    SPI_v1_chObject      *chObj;
    SPI_v1_HWAttrs const *hwAttrs;
    uint32_t              chNum;
    uint32_t              intCode;

    /* Get the pointer to the channel object */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    object  = (SPI_v1_Object*)handle->object;
    chObj   = &(object->chObject[chNum]);
    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;

    if(true == hwAttrs->enableIntr)
    {
        intCode = (uint32_t)(MCSPI_INT_RX_FULL(chNum))  |
                  (uint32_t)(MCSPI_INT_TX_EMPTY(chNum)) |
                  MCSPI_INT_EOWKE;
        McSPIIntDisable(hwAttrs->baseAddr,intCode);
        McSPIIntStatusClear(hwAttrs->baseAddr, intCode);
    }

    if ((SPI_MASTER == chObj->spiParams.mode) &&
        (hwAttrs->chMode == MCSPI_SINGLE_CH))
    {
        McSPICSDeAssert(hwAttrs->baseAddr, chNum);
    }
    McSPIChannelDisable(hwAttrs->baseAddr, chNum);

    chObj->transaction->status = SPI_TRANSFER_CANCELED;
    MCSPI_transferCallback_v1(mcHandle, chObj->transaction);

    return;
}

/*
 *  ======== MCSPI_control_v1 ========
 */
static int32_t MCSPI_control_v1(MCSPI_Handle mcHandle, uint32_t cmd, const void *arg)
{
    (void)mcHandle;
    (void)cmd;
    arg = arg;
    return SPI_STATUS_UNDEFINEDCMD;
}

/**
 *  \brief  function is used to clear the channel specific interrupt status
 */
void MCSPI_clearIntStatus(MCSPI_Handle mcHandle)
{
    SPI_Handle            handle;
    SPI_v1_HWAttrs const *hwAttrs;
    uint32_t              chNum;
    uint32_t              clrIntr = (uint32_t) 0;

    /* Get the pointer to the hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;

    switch (chNum)
    {
        case MCSPI_CHANNEL_0:
                /* clear all channel '0' interrupts */
                clrIntr = (uint32_t) 0;

                clrIntr = (CSL_MCSPI_IRQSTATUS_TX0_EMPTY_MASK |
                               CSL_MCSPI_IRQSTATUS_TX0_UNDERFLOW_MASK |
                               CSL_MCSPI_IRQSTATUS_RX0_FULL_MASK);

                McSPIIntStatusClear((uint32_t) hwAttrs->baseAddr, clrIntr);

            break;

        case MCSPI_CHANNEL_1:
                /* Enable all channel '1' interrupts */
                clrIntr = (uint32_t) 0;
                clrIntr = (CSL_MCSPI_IRQSTATUS_TX1_EMPTY_MASK |
                           CSL_MCSPI_IRQSTATUS_TX1_UNDERFLOW_MASK |
                           CSL_MCSPI_IRQSTATUS_RX1_FULL_MASK);

                McSPIIntStatusClear((uint32_t) hwAttrs->baseAddr, clrIntr);

            break;

        case MCSPI_CHANNEL_2:
                /* Enable all channel '2' interrupts */
                clrIntr = (uint32_t) 0;
                clrIntr = (CSL_MCSPI_IRQSTATUS_TX2_EMPTY_MASK |
                           CSL_MCSPI_IRQSTATUS_TX2_UNDERFLOW_MASK |
                           CSL_MCSPI_IRQSTATUS_RX2_FULL_MASK);

                McSPIIntStatusClear((uint32_t) hwAttrs->baseAddr, clrIntr);

            break;

        case MCSPI_CHANNEL_3:
                /* Enable all channel '3' interrupts */
                clrIntr = (uint32_t) 0;
                clrIntr = (CSL_MCSPI_IRQSTATUS_TX3_EMPTY_MASK |
                           CSL_MCSPI_IRQSTATUS_TX3_UNDERFLOW_MASK |
                           CSL_MCSPI_IRQSTATUS_RX3_FULL_MASK);

                McSPIIntStatusClear((uint32_t) hwAttrs->baseAddr, clrIntr);

            break;

        default:
            break;
    }
}

/**
 *  \brief  function is used to clear the channel specific interrupt error status
 */
void MCSPI_clearIntErrStatus(MCSPI_Handle mcHandle, uint32_t intStatus)
{
    SPI_Handle            handle;
    uint32_t              chNum;
    SPI_v1_HWAttrs const *hwAttrs;

    /* Get the pointer to the hwAttrs */
    handle  = mcHandle->handle;
    chNum   = mcHandle->chnNum;
    hwAttrs = (const SPI_v1_HWAttrs *)handle->hwAttrs;

    /* check Timeout interrupt                                           */
    switch (chNum)
    {
        case MCSPI_CHANNEL_0:

            if ((uint32_t) CSL_MCSPI_IRQSTATUS_TX0_UNDERFLOW_MASK ==
                (intStatus & (uint32_t) CSL_MCSPI_IRQSTATUS_TX0_UNDERFLOW_MASK))
            {
                McSPIIntStatusClear(
                    (uint32_t) hwAttrs->baseAddr,
                    (uint32_t) CSL_MCSPI_IRQSTATUS_TX0_UNDERFLOW_MASK);
            }
            break;

        case MCSPI_CHANNEL_1:

            if ((uint32_t) CSL_MCSPI_IRQSTATUS_TX1_UNDERFLOW_MASK ==
                (intStatus & (uint32_t) CSL_MCSPI_IRQSTATUS_TX1_UNDERFLOW_MASK))
            {
                McSPIIntStatusClear(
                    (uint32_t) hwAttrs->baseAddr,
                    (uint32_t) CSL_MCSPI_IRQSTATUS_TX1_UNDERFLOW_MASK);
            }
            break;

        case MCSPI_CHANNEL_2:
            if ((uint32_t) CSL_MCSPI_IRQSTATUS_TX2_UNDERFLOW_MASK ==
                (intStatus & (uint32_t) CSL_MCSPI_IRQSTATUS_TX2_UNDERFLOW_MASK))
            {
                McSPIIntStatusClear(
                    (uint32_t) hwAttrs->baseAddr,
                    (uint32_t) CSL_MCSPI_IRQSTATUS_TX2_UNDERFLOW_MASK);
            }
            break;

        case MCSPI_CHANNEL_3:

            if ((uint32_t) CSL_MCSPI_IRQSTATUS_TX3_UNDERFLOW_MASK ==
                (intStatus & (uint32_t) CSL_MCSPI_IRQSTATUS_TX3_UNDERFLOW_MASK))
            {
                McSPIIntStatusClear(
                    (uint32_t) hwAttrs->baseAddr,
                    (uint32_t) CSL_MCSPI_IRQSTATUS_TX3_UNDERFLOW_MASK);
            }
            break;

        default:
            break;
    }
}
