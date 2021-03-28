/*
 * Copyright (C) 2018-2019 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file    spi.c
 *
 *  \brief   SPI flash writer API implementation.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "spi.h"

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

static int8_t UFP_spiInit(void);

static int8_t UFP_spiFlashErase(uint32_t offset, uint32_t length);

static int8_t UFP_spiFlashImage(uint8_t *flashAddr, uint8_t *checkAddr,
                                uint32_t offset, uint32_t size);

static int8_t UFP_spiFlashClose(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

SPI_Handle gSpiHandle;

uint8_t txBuffer[260U]; /* 256 byte data + 1 cmd byte + 3 byte for offset */
uint8_t rxBuffer[260U];

extern uint8_t flag;

/* Flash programmer SPI function table */
const UFP_fxnTable UFP_spiFxnTable = {
    &UFP_spiInit,
    &UFP_spiFlashErase,
    &UFP_spiFlashImage,
    &UFP_spiFlashClose
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 *  \brief		This function enables write operation on SPI.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */
static int8_t UFP_spiWriteEnable(void)
{
	SPI_Transaction transaction;
	bool ret = false;

	txBuffer[0] = WRITE_ENABLE_COMMAND;
    transaction.count = 1U;
    transaction.txBuf = &txBuffer[0];
    transaction.rxBuf = &rxBuffer[0];
    ret = SPI_transfer(gSpiHandle, &transaction);
    if (ret == false)
    {
        SPI_close(gSpiHandle);
        return -1;
    }
	return 0;
}


/**
 *  \brief		This function checks if the SPI Flash
 *				is busy.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */
static int8_t UFP_spiCheckBusy(void)
{
	SPI_Transaction transaction;
	bool ret = false;

	do{
		txBuffer[0] = CHECK_FLASH_BUSY;
		txBuffer[1] = 0xFFU;
		transaction.txBuf = &txBuffer[0];
		transaction.rxBuf = &rxBuffer[0];
		transaction.count = 2U;
		ret = SPI_transfer(gSpiHandle, &transaction);
		if (ret == false)
			return -1;
	} while(rxBuffer[1] & 0x01); /* checking busy status bit */

	return 0;
}

/**
 *  \brief		This function erases a sector on SPI.
 *
 *	\param		offset		[IN]   	Address of a sector to erase.
 *				
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */	
static int8_t UFP_spiErase(uint32_t offset)
{
	SPI_Transaction transaction;
  	bool ret = false;

	txBuffer[0] = ERASE_COMMAND; /* sector command to erase SPI flash */
	txBuffer[1] = (uint8_t ) (offset >> 16);
	txBuffer[2] = (uint8_t ) (offset >> 8);
	txBuffer[3] = (uint8_t ) (offset);
	transaction.txBuf = &txBuffer[0];
	transaction.rxBuf = &rxBuffer[0];
	transaction.count = 4U;
	ret = SPI_transfer(gSpiHandle, &transaction);
	if (ret == false)
	{
		SPI_close(gSpiHandle);
		return -1;
	}
	return 0;
}

/**
 *  \brief		This function reads the image on SPI and copies to DDR.
 *
 *	\param		src			[OUT]   Pointer to store the image.
 *	\param		offset		[IN]   	Address of flashed image on SPI.
 *	\param		length		[IN]	Size of image to be flashed.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */
static int8_t UFP_spiRead(uint8_t *src, uint32_t offset, uint32_t length)
{
	SPI_Transaction transaction; 
	bool ret = false;

	txBuffer[0] = READ_COMMAND;
    txBuffer[1] = (uint8_t ) (offset >> 16);
	txBuffer[2] = (uint8_t ) (offset >> 8);
	txBuffer[3] = (uint8_t ) (offset);

	transaction.count = length + 4;

	transaction.txBuf = &txBuffer[0];
	transaction.rxBuf = &rxBuffer[0];
	ret = SPI_transfer(gSpiHandle, &transaction);
	if (ret == false)
	{
		SPI_close(gSpiHandle);
		return -1;
	}
	memcpy(src, &rxBuffer[4], length);
	return 0;
}

/**
 *  \brief		This function writes the image on SPI.
 *
 *	\param		src			[IN]   	Pointer to the image.
 *	\param		offset		[IN]   	Address to flash on SPI.
 *	\param		length		[IN]	Size of image to be flashed.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */	
static int8_t UFP_spiWrite(uint8_t *src, uint32_t offset, uint32_t length)
{
	SPI_Transaction transaction; 
	bool ret = false;

	txBuffer[0] = WRITE_COMMAND;
    txBuffer[1] = (uint8_t ) (offset >> 16);
	txBuffer[2] = (uint8_t ) (offset >> 8);
	txBuffer[3] = (uint8_t ) (offset);

	memcpy(&txBuffer[4], src, length);
    transaction.count = length + 4;

	transaction.txBuf = &txBuffer[0];
	transaction.rxBuf = &rxBuffer[0];
	ret = SPI_transfer(gSpiHandle, &transaction);
	if (ret == false)
	{
		SPI_close(gSpiHandle);
		return -1;
	}
	return 0;
}

/**
 *  \brief		This function reads the image on SPI flash.
 *
 *	\param		src			[IN]   	Pointer to the image.
 *	\param		length		[IN]	Size of image to be flashed.
 *	\param		offset		[IN]   	Address to be flashed on SPI.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */	
static int8_t UFP_spiPageRead(uint8_t *src, uint32_t length, uint32_t offset)
{
	uint32_t len = 0;
	int8_t ret;

	while(len < length)
	{
		ret = UFP_spiRead((src + len), offset, PAGE_SIZE);
		if (ret != 0)
			return -1;

		len += PAGE_SIZE;
		offset += PAGE_SIZE;
	}
	return 0;
}

/**
 *  \brief		This function writes the image on the pages of SPI flash.
 *
 *	\param		src			[IN]   	Pointer to the image.
 *	\param		length		[IN]	Size of image to be flashed.
 *	\param		offset		[IN]   	Address to flash on SPI.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */	
static int8_t UFP_spiPageWrite(uint8_t *src, uint32_t length, uint32_t offset)
{
	uint32_t len = 0;
	int8_t ret;

	while(len < length)
	{
		if (!(len % SECTOR_SIZE))
		{
			ret = UFP_spiWriteEnable();
			if (ret != 0)
				return -1;

			ret = UFP_spiErase(offset);
			if (ret != 0)
				return -1;

			/* Check for Flash Busy */
			ret = UFP_spiCheckBusy();
			if (ret != 0)
				return -1;
		}

		ret = UFP_spiWriteEnable();
		if (ret != 0)
			return -1;

		ret = UFP_spiWrite((src + len), offset, PAGE_SIZE);
		if (ret != 0)
			return -1;

		len += PAGE_SIZE;
		offset += PAGE_SIZE;

		/* Check for Flash Busy */
		ret = UFP_spiCheckBusy();
		if (ret != 0)
			return -1;
	}
	return 0;
}

/**
 *  \brief		This function closes the SPI Handle.
 *
 *  \return		int8_t
 *					0		- in case of success
 *                 -1       - in case of failure.
 *
 */
static int8_t UFP_spiFlashClose(void)
{
    SPI_close(gSpiHandle);
    return 0;
}

/**
 *  \brief		This function reads the image from specified location of SPI.
 *
 *	\param		dst			[OUT]  	Pointer to store the read image
 *	\param		offset		[IN]   	offset of the image on Flash
 *	\param		length		[IN]	Size of image.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */
static int8_t UFP_spiFlashRead(uint8_t *dst, uint32_t length, uint32_t offset)
{
	int8_t ret;

	ret = UFP_spiPageRead(dst, length, offset);
    if (ret)
    {
        SPI_close(gSpiHandle);
        return -1;
    }
	return 0;
}

/**
 *  \brief		This function writes the image to SPI on specified location.
 *
 *	\param		src			[IN]   	Pointer to the image to be flashed
 *	\param		offset		[IN]   	Offset to flash the image
 *	\param		length		[IN]	size of the image to be flashed.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */	
static int8_t UFP_spiFlashWrite(uint8_t *src, uint32_t length, uint32_t offset)
{
	int8_t ret;

	ret = UFP_spiPageWrite(src, length, offset);
    if (ret)
    {
        SPI_close(gSpiHandle);
        return -1;
    }
	return 0;
}

/**
 *  \brief		This function writes the image to SPI and reads back
 *				the image on specified address.
 *
 *  \param      flashAddr   [IN]    Pointer to the image to be flashed
 *	\param		checkAddr   [OUT]   Pointer to store the read image
 *  \param      offset      [IN]    Offset to flash the image.
 *  \param      size        [IN]    size of the image to be flashed.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */
static int8_t UFP_spiFlashImage(uint8_t *flashAddr, uint8_t *checkAddr,
                                uint32_t offset, uint32_t size)
{
	int8_t ret = 0;

    ret = UFP_spiFlashWrite(flashAddr, size, offset);
    if (ret != 0)
    {
        return -1;
    }

    delay(SPI_FW_WRITE_DELAY);
    ret = UFP_spiFlashRead(checkAddr, size, offset);
    if (ret != 0)
    {
        return -1;
    }
    return 0;
}

/**
 *  \brief		This function erases the SPI flash upto specified length
 *              from the specified address.
 *
 *	\param		offset		[IN]    Offset to erase the Flash.
 *	\param		length		[IN]    Erase length.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */
static int8_t UFP_spiFlashErase(uint32_t offset, uint32_t length)
{
	uint32_t len = 0;
    int8_t ret;

	while(len < length)
	{
		ret = UFP_spiWriteEnable();
		if (ret != 0)
			return -1;

		ret = UFP_spiErase(offset);
		if (ret != 0)
			return -1;

		/* Check for Flash Busy */
		ret = UFP_spiCheckBusy();
		if (ret != 0)
			return -1;

		len += SECTOR_SIZE;
		offset += SECTOR_SIZE;
	}
	return 0;
}

/**
 *  \brief		This function initializes SPI flash.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */
static int8_t UFP_spiInit(void)
{
	SPI_Params spiParams;       /* SPI params structure */

	((SPI_v1_HWAttrs *)SPI_config[MCSPI_INSTANCE].hwAttrs)->enableIntr = false;
	((SPI_v1_HWAttrs *)SPI_config[MCSPI_INSTANCE].hwAttrs)->chNum = 0;

	SPI_init();

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);

    /* Open SPI driver */
    gSpiHandle = SPI_open(MCSPI_INSTANCE, &spiParams);

	if (!gSpiHandle)
    {
        return -1;
    }
    return 0;
}
