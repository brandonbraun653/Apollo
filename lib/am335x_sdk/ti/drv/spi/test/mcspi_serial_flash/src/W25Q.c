/**
 *  \file   W25QFL.c
 *
 *  \brief  Flash specific driver implementation. The flash is SPI based flash
 *          memory. The part number flash memory is Winbond W25Q64CV and the
 *          size is 64 Mb.
 *
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

#include "W25Q.h"
#include <ti/drv/spi/SPI.h>
#include <ti/osal/CacheP.h>
__attribute__((aligned(64)))
uint8_t gFlashAppTxBuffer[260U];

__attribute__((aligned(64)))
uint8_t gFlashAppRxBuffer[260U];

__attribute__((aligned(64)))
uint8_t gFlashAppVerifyData[260U];

/*!
 *  @brief Flash object containing flash attributes.
 */
W25QFL_Object w25qflObject = {NULL};

/*
 *  ======== W25QFL_close ========
 */
void W25QFL_close(W25QFL_Handle handle)
{
    SPI_close(handle->spiHandle);
}

/*
 *  ======== W25QFL_open ========
 */
W25QFL_Handle W25QFL_open(unsigned int index, SPI_Params *params)
{
    W25QFL_Handle w25qflHandle;

    w25qflHandle = &w25qflObject;

    /* Open SPI driver for SF25FL */
    w25qflHandle->spiHandle = SPI_open(index, params);

    return w25qflHandle;
}


/*
 *  ======== W25QFL_FlashStatus ========
 */
void W25QFL_FlashStatus(W25QFL_Handle flashHandle)
{
   SPI_Handle handle = (SPI_Handle)flashHandle->spiHandle;
   SPI_Transaction transaction;

   gFlashAppTxBuffer[0U] = FLASH_READ_STAT_REG1;
   gFlashAppTxBuffer[1U] = 0xFFU;

   transaction.txBuf = &gFlashAppTxBuffer[0];
   transaction.rxBuf = &gFlashAppRxBuffer[0];
   transaction.count = 2;

   CacheP_wb((void *)gFlashAppTxBuffer, (int32_t)2);
   SPI_transfer(handle, &transaction);
   CacheP_Inv((void *)gFlashAppRxBuffer, (int32_t)2);
}

/*
 *  ======== W25QFL_IsFlashBusy ========
 */
void W25QFL_IsFlashBusy(W25QFL_Handle handle)
{
    do{
        W25QFL_FlashStatus(handle);
      } while(gFlashAppRxBuffer[1U] & FLASH_WRITE_IN_PROGRESS);
}

/*
 *  ======== W25QFL_SectorErase ========
 */
void W25QFL_SectorErase(W25QFL_Handle flashHandle)
{
    SPI_Handle handle = (SPI_Handle)flashHandle->spiHandle;
    SPI_Transaction transaction;

    gFlashAppTxBuffer[0U] = FLASH_SECTOR_ERASE;
    gFlashAppTxBuffer[1U] = FLASH_SECTOR_ADD_HIGH;
    gFlashAppTxBuffer[2U] = FLASH_SECTOR_ADD_MID;
    gFlashAppTxBuffer[3U] = FLASH_SECTOR_ADD_LOW;

    transaction.txBuf = &gFlashAppTxBuffer[0];
    transaction.rxBuf = &gFlashAppRxBuffer[0];
    transaction.count = 4U;

    CacheP_wb((void *)gFlashAppTxBuffer, (int32_t)4);
    SPI_transfer(handle, &transaction);
    CacheP_Inv((void *)gFlashAppRxBuffer, (int32_t)4);

    W25QFL_IsFlashBusy(flashHandle);
}

/*
 *  ======== W25QFL_WriteEnable ========
 */
void W25QFL_WriteEnable(W25QFL_Handle flashHandle)
{
    SPI_Handle handle = (SPI_Handle)flashHandle->spiHandle;
    SPI_Transaction transaction;

    gFlashAppTxBuffer[0U] = FLASH_WRITE_ENABLE;

    transaction.txBuf = &gFlashAppTxBuffer[0];
    transaction.rxBuf = &gFlashAppRxBuffer[0];
    transaction.count = 1U;

    CacheP_wb((void *)gFlashAppTxBuffer, (int32_t)1);
    SPI_transfer(handle, &transaction);
    CacheP_Inv((void *)gFlashAppRxBuffer, (int32_t)1);
}

/*
 *  ======== W25QFL_IsWriteSuccess ========
 */
uint32_t W25QFL_IsWriteSuccess(W25QFL_Handle flashHandle)
{
    SPI_Handle handle = (SPI_Handle)flashHandle->spiHandle;
    SPI_Transaction transaction;
    unsigned int retVal = false;

    gFlashAppTxBuffer[0U] = FLASH_READ_STAT_REG1;
    gFlashAppTxBuffer[1U] = FLASH_DUMMY_BYTE;

    transaction.txBuf = &gFlashAppTxBuffer[0];
    transaction.rxBuf = &gFlashAppRxBuffer[0];
    transaction.count = 2U;

    CacheP_wb((void *)gFlashAppTxBuffer, (int32_t)2);
    SPI_transfer(handle, &transaction);
    CacheP_Inv((void *)gFlashAppRxBuffer, (int32_t)2);

    if(0x02U == gFlashAppRxBuffer[1U])
    {
        retVal = true;
    }

    return retVal;
}

/*
 *  ======== W25QFL_WriteToFlash ========
 */
void W25QFL_WriteToFlash(W25QFL_Handle flashHandle)
{
    SPI_Handle handle = (SPI_Handle)flashHandle->spiHandle;
    SPI_Transaction transaction;
    unsigned int index = 0U;

    gFlashAppTxBuffer[0U] = FLASH_PAGE_PROGRAM;
    gFlashAppTxBuffer[1U] = FLASH_SECTOR_ADD_HIGH;
    gFlashAppTxBuffer[2U] = FLASH_SECTOR_ADD_MID;
    gFlashAppTxBuffer[3U] = FLASH_SECTOR_ADD_LOW;

    for(index = 0U; index < 256U; index++)
    {
        gFlashAppTxBuffer[index + 4U] = (uint8_t) index;
        gFlashAppVerifyData[index] = (uint8_t) index;
    }

    transaction.txBuf = &gFlashAppTxBuffer[0];
    transaction.rxBuf = &gFlashAppRxBuffer[0];
    transaction.count = 260U;

    CacheP_wb((void *)gFlashAppTxBuffer, (int32_t)260);
    SPI_transfer(handle, &transaction);
    CacheP_Inv((void *)gFlashAppRxBuffer, (int32_t)260);
}

/*
 *  ======== W25QFL_ReadFromFlash ========
 */
void W25QFL_ReadFromFlash(W25QFL_Handle flashHandle)
{
    SPI_Handle handle = (SPI_Handle)flashHandle->spiHandle;
    SPI_Transaction transaction;
    unsigned int index = 0U;

    gFlashAppTxBuffer[0U] = FLASH_DATA_READ;
    gFlashAppTxBuffer[1U] = FLASH_SECTOR_ADD_HIGH;
    gFlashAppTxBuffer[2U] = FLASH_SECTOR_ADD_MID;
    gFlashAppTxBuffer[3U] = FLASH_SECTOR_ADD_LOW;

    for(index = 4U; index < 260U; index++)
    {
        gFlashAppTxBuffer[index] = 0U;
    }

    transaction.txBuf = &gFlashAppTxBuffer[0];
    transaction.rxBuf = &gFlashAppRxBuffer[0];
    transaction.count = 260U;

    CacheP_wb((void *)gFlashAppTxBuffer, (int32_t)260);
    SPI_transfer(handle, &transaction);
    CacheP_Inv((void *)gFlashAppRxBuffer, (int32_t)260);
}

/*
 *  ======== W25QFL_VerifyData ========
 */
bool W25QFL_VerifyData(void)
{
    unsigned int index = 0U;
    bool retVal = true;

    for(index = 4U; index < 260U; index++)
    {
        if(gFlashAppRxBuffer[index] != gFlashAppVerifyData[index - 4U])
        {
            retVal = false;
            break;
        }
    }

    return retVal;
}
