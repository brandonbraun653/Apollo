/**
 *  \file   board_spi.c
 *
 *  \brief  AM437x IDK Board SPI specific APIS
 *
 *
 */

/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 **/
#include <stdbool.h>
#include <ti/sysbios/family/arm/a9/Cache.h>
#include <ti/csl/soc.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/drv/gpio/GPIO.h>
#include <examples/board/include/board_spi.h>
#include <examples/board/include/delay_us.h>
#include <ti/drv/spi/soc/QSPI_v1.h>
/* Flash header file */
#include <ti/drv/spi/test/qspi_flash/src/Flash_S25FL/S25FL.h>

#define QSPI_PER_CNT            (1U)
#define QSPI_INSTANCE           (1U)
#define QSPI_OFFSET             (5U)

/** \brief QSPI Flash handle. Can be extern from app*/
Board_flashHandle boardFlashHandle;

S25FL_Handle flashHandle;

extern QSPI_HwAttrs qspiInitCfg[QSPI_PER_CNT];

extern SPI_Handle handle;                   /* SPI handle */

/* Flash header file */

void LoadData(void)
{
    GPIO_write(6, 0);
    delay_us(1);
    GPIO_write(6, 1);
    delay_us(1);
}

void Board_readHVS(uint8_t *switches)
{
    /* MCSPI params required */
    /* Buffer containing the known data that needs to be written to flash */
    uint8_t txBuf[1U];
    /* Buffer containing the received data */
    uint8_t rxBuf[1U] = {0xFFU};
    /* Transfer length */
    uint32_t transferLength;
    SPI_Transaction transaction;         /* SPI transaction */

    /* Load data */
    LoadData();

    /* Initiate transfer */
    txBuf[0] = 0xAAU;
    transferLength = 1U;

    transaction.count = transferLength;
    transaction.txBuf = &txBuf[0];
    transaction.rxBuf = &rxBuf[0];
    SPI_transfer(handle, &transaction);

    *switches = *rxBuf & 0xFF;
}

Board_flash_STATUS Board_flashWrite(Board_flashHandle  flashHandle,
                                    uint32_t           offset,
                                    uint8_t           *buffer,
                                    uint32_t           length,
                                    void              *params)
{
    S25FL_Transaction flashTransaction;  /* Flash transaction structure */
    bool retVal = FALSE;

    /* Update transaction parameters */
    flashTransaction.data       = (uint8_t *)buffer;
    flashTransaction.address    = offset;
    flashTransaction.dataSize   = length;  /* In bytes */

    /* Write buffer to flash */
    retVal = SF25FL_bufferWrite(flashHandle, &flashTransaction);

    if(retVal)
    {
        return BOARD_FLASH_EOK;
    }

    else
    {
        return BOARD_FLASH_EFAIL;
    }
}

Board_flash_STATUS Board_flashRead(Board_flashHandle  flashHandle,
                                   uint32_t           offset,
                                   uint8_t           *buffer,
                                   uint32_t           length,
                                   void              *params)
{
    bool retVal = FALSE;
    S25FL_Transaction flashTransaction;  /* Flash transaction structure */
    flashTransaction.data       = (uint8_t *)buffer;
    flashTransaction.address    = offset;
    flashTransaction.dataSize   = length; /* In bytes */

    /* Read data from flash */
    retVal = SF25FL_bufferRead(flashHandle, &flashTransaction);

    if(retVal)
    {
        return BOARD_FLASH_EOK;
    }

    else
    {
        return BOARD_FLASH_EFAIL;
    }
}


Board_flash_STATUS Board_flashOffsetToBlkPage(Board_flashHandle  handle,
        uint32_t           offset,
        uint32_t          *block,
        uint32_t          *page)
{
    *block = (offset) / handle->blockSize;
    return BOARD_FLASH_EOK;
}



Board_flash_STATUS Board_flashEraseBlk(Board_flashHandle handle,
                                       uint32_t          block_number)
{
    bool retVal = S25FLFlash_BlockErase(handle, block_number);


    if(retVal)
    {
        return BOARD_FLASH_EOK;
    }

    else
    {
        return BOARD_FLASH_EFAIL;
    }
}



bool Board_writeFlashStorage(S25FL_Handle flashHandle, uint32_t offset,
                             uint32_t length, uint8_t *buffer, uint8_t eraseFlag)
{
    uint32_t blockNumber = 0;
    int32_t tempLength = 0;
    uint32_t i = 0;
    S25FL_Transaction flashTransaction;  /* Flash transaction structure */
    bool retVal = FALSE;

    if(1 == eraseFlag)
    {
        tempLength = length;
        blockNumber = (offset) / flashHandle->blockSize;

        /* Erase 64k(blockSize) blocks. Repeat for all required blocks */
        while(tempLength > 0)
        {
            S25FLFlash_BlockErase(flashHandle, blockNumber + i);

            tempLength = tempLength - flashHandle->blockSize;
            i++;
        }
    }

    /* Update transaction parameters */
    flashTransaction.data       = (uint8_t *)buffer;
    flashTransaction.address    = offset;
    flashTransaction.dataSize   = length;  /* In bytes */

    /* Write buffer to flash */
    retVal = SF25FL_bufferWrite(flashHandle, &flashTransaction);

    return retVal;
}

bool Board_readFlashStorage(S25FL_Handle flashHandle, uint32_t offset,
                            uint32_t length, uint8_t *buffer)
{
    bool retVal = FALSE;
    S25FL_Transaction flashTransaction;  /* Flash transaction structure */
    flashTransaction.data       = (uint8_t *)buffer;
    flashTransaction.address    = offset;
    flashTransaction.dataSize   = length; /* In bytes */

    /* Read data from flash */
    retVal = SF25FL_bufferRead(flashHandle, &flashTransaction);
    return retVal;
}

Board_flashHandle Board_flashOpen(uint32_t  deviceId, uint32_t  portNum,
                                  void *params)
{
    SPI_Handle spiFlashHandle;                   /* SPI handle */
    unsigned int rxLines;
    unsigned int qspiMode;
    SPI_Params qspiParams;                /* SPI params structure */
    /* QSPI Init */
    /* Init SPI driver */
    qspiInitCfg[0].intrEnable =
        false;  /* Interrupt mode causes conflict with EDMA ISRs */
    SPI_init();

    /* Default SPI configuration parameters */
    SPI_Params_init(&qspiParams);

    /* Open QSPI driver */
    boardFlashHandle = SF25FL_open(((QSPI_INSTANCE - 1) + (QSPI_OFFSET)),
                                   &qspiParams);

    /* Extract hardware attributes */
    spiFlashHandle = boardFlashHandle->spiHandle;

    /* Mode: CFG & Rx Lines: SINGLE */
    qspiMode = QSPI_OPER_MODE_MMAP;
    SPI_control(spiFlashHandle, SPI_V1_CMD_SETMEMMORYMAPMODE, (void *)&qspiMode);
    rxLines = QSPI_RX_LINES_QUAD;
    S25FLFlash_QuadModeEnable(boardFlashHandle);
    SPI_control(spiFlashHandle, SPI_V1_CMD_SETRXLINES, (void *)&rxLines);

    memcpy(&flashHandle, &boardFlashHandle, sizeof(S25FL_Handle));

    return BOARD_FLASH_EOK;
}
