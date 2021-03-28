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

/**
 *  \file    hyperflash.c
 *
 *  \brief   hyperflash flash writer API implementation.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hyperflash.h"

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

static int8_t UFP_hpfInit(void);

static int8_t UFP_hpfFlashErase(uint32_t offset, uint32_t length);

static int8_t UFP_hpfFlashImage(uint8_t *flashAddr, uint8_t *checkAddr,
                                uint32_t offset, uint32_t size);

static int8_t UFP_hpfClose(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

Board_flashHandle gHpfHandle;

/* Flash programmer hyperflash function table */
const UFP_fxnTable UFP_hpfFxnTable = {
    &UFP_hpfInit,
    &UFP_hpfFlashErase,
    &UFP_hpfFlashImage,
    &UFP_hpfClose
};

static uint32_t pinMuxHyperbus[PADCONFIG_MAX_COUNT] =
{
    PIN_MCU_OSPI0_CLK,
    PIN_MCU_OSPI0_CSN0,
    PIN_MCU_OSPI0_D0,
    PIN_MCU_OSPI0_D1,
    PIN_MCU_OSPI0_D2,
    PIN_MCU_OSPI0_D3,
    PIN_MCU_OSPI0_D4,
    PIN_MCU_OSPI0_D5,
    PIN_MCU_OSPI0_D6,
    PIN_MCU_OSPI0_D7,
    PIN_MCU_OSPI0_DQS,
    PIN_MCU_OSPI0_LBCLKO
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 *  \brief		This function closes the hyperflash Handle.
 *
 *  \return		int8_t
 *					0		- in case of success
 *
 */
static int8_t UFP_hpfClose(void)
{
    Board_flashClose(gHpfHandle);

    return 0;
}

/**
 *  \brief		This function reads data from specified location of hyperflash.
 *
 *	\param		dst			[OUT]  	Pointer to store the read data
 *	\param		offset		[IN]   	offset of the data on Flash
 *	\param		length		[IN]	Size of data.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */
static int8_t UFP_hpfFlashRead(uint8_t *dst, uint32_t offset, uint32_t length)
{

    if (Board_flashRead(gHpfHandle, offset, dst, length, NULL))
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief		This function writes data to hyperflash on specified location.
 *
 *	\param		src			[IN]   	Pointer to the data to be flashed
 *	\param		offset		[IN]   	Offset to flash the data
 *	\param		length		[IN]	size of the data to be flashed.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */
static int8_t UFP_hpfFlashWrite(uint8_t *src, uint32_t offset, uint32_t length)
{
    uint32_t startBlockNum, endBlockNum, pageNum, i;

    if (!(offset % NOR_HPF_SECTOR_SIZE))
    {
        /* Get starting block number */
        if (Board_flashOffsetToBlkPage(gHpfHandle, offset,
                                       &startBlockNum, &pageNum))
        {
            return -1;
        }

        /* Get ending block number */
        if (Board_flashOffsetToBlkPage(gHpfHandle, (offset + length),
                                       &endBlockNum, &pageNum))
        {
            return -1;
        }

        /* Erase blocks, to which data has to be written */
        for(i = startBlockNum; i <= endBlockNum; i++)
        {
            if (Board_flashEraseBlk(gHpfHandle, i))
            {
                return -1;
            }
        }
    }

    /* Write buffer to flash */
    if (Board_flashWrite(gHpfHandle, offset, src, length, NULL))
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief		This function writes data to hyperflash and reads back
 *				the data from the specified address.
 *
 *  \param      flashAddr   [IN]    Pointer to the data to be flashed
 *	\param		checkAddr   [OUT]   Pointer to store the read data
 *  \param      offset      [IN]    Offset to flash the data
 *  \param      size        [IN]    size of the image to be flashed.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */
static int8_t UFP_hpfFlashImage(uint8_t *flashAddr, uint8_t *checkAddr,
                                uint32_t offset, uint32_t size)
{
    int8_t ret;

    ret = UFP_hpfFlashWrite(flashAddr, offset, size);
    if (ret != 0)
    {
        return -1;
    }

    ret = UFP_hpfFlashRead(checkAddr, offset, size);
    if (ret != 0)
    {
        return -1;
    }

	return 0;
}

/**
 *  \brief		This function erases the hyperflash upto the specified length
 *              from the specified address.
 *
 *	\param		offset		[IN]    Offset to erase the Flash.
 *	\param		length		[IN]    Erase length.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */
static int8_t UFP_hpfFlashErase(uint32_t offset, uint32_t length)
{
    uint32_t startBlockNum, endBlockNum, pageNum, i;

    /* Get starting block number */
    if (Board_flashOffsetToBlkPage(gHpfHandle, offset,
                                   &startBlockNum, &pageNum))
    {
        return -1;
    }

    /* Get ending block number */
    if (Board_flashOffsetToBlkPage(gHpfHandle, (offset + length),
                                   &endBlockNum, &pageNum))
    {
        return -1;
    }

    /* Erase blocks, to which data has to be written */
    for(i = startBlockNum; i <= endBlockNum; i++)
    {
        if (Board_flashEraseBlk(gHpfHandle, i))
        {
            return -1;
        }
    }

	return 0;
}

/**
 *  \brief		This function initializes hyperflash.
 *				
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */
static int8_t UFP_hpfInit(void)
{
    uint8_t index;

    for(index = 0; index < PADCONFIG_MAX_COUNT; index++)
    {
        Board_pinMuxSetModeWkup(pinMuxHyperbus[index],
                                HYPERBUS_MUX_MODE);
    }

    /* Open the Board hyperflash device with 
       default Hyperflash configurations */
    gHpfHandle = Board_flashOpen(UFP_HPF_FLASH_ID, BOARD_HPF_INSTANCE, NULL);

    if (!gHpfHandle)
    {
        return -1;
    }

    return 0;
}
