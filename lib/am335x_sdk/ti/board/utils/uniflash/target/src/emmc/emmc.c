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
 *  \file    emmc.c
 *
 *  \brief   eMMC flash writer API implementation.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "emmc.h"
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

static int8_t UFP_emmcInit(void);

static int8_t UFP_emmcFlashErase(uint32_t offset, uint32_t length);

static int8_t UFP_emmcFlashImage(uint8_t *flashAddr, uint8_t *checkAddr,
                                 uint32_t offset, uint32_t size);

static int8_t UFP_emmcClose(void);

extern uint8_t gDataCheckBuff[DATA_BUFF_LEN];

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

MMCSD_Handle gEmmcHandle = NULL;

/* Flash programmer eMMC function table */
const UFP_fxnTable UFP_emmcFxnTable = {
    &UFP_emmcInit,
    &UFP_emmcFlashErase,
    &UFP_emmcFlashImage,
    &UFP_emmcClose
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 *  \brief		This function resets eMMC by making the eMMC reset line
 *              low and high.
 *
 */
static void UFP_emmcReset(void)
{
#if !defined(SOC_J721E)
#if defined(SOC_AM65XX) && !defined (__aarch64__)
    I2C_HwAttrs i2cCfg;

    I2C_socGetInitCfg(0, &i2cCfg);

    i2cCfg.baseAddr = CSL_I2C0_CFG_BASE;
    i2cCfg.enableIntr = 0;

    I2C_socSetInitCfg(0, &i2cCfg);
#endif

    Board_i2cIoExpInit();
    /* Setting the pin direction as output */
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  PORTNUM_0,
                                  PIN_NUM_0,
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling the EMMC RST line to low for the reset to happen */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              PORTNUM_0,
                              PIN_NUM_0,
                              GPIO_SIGNAL_LEVEL_LOW);
    /* Wait for short duration before pulling the reset line high
       to initiate eMMC reset */
    Osal_delay(EMMC_FW_DELAY);

    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              PORTNUM_0,
                              PIN_NUM_0,
                              GPIO_SIGNAL_LEVEL_HIGH);
#endif
}

/**
 *  \brief		This function closes the eMMC Handle.
 *
 *  \return		int8_t
 *					0		- in case of success
 *                 -1       - in case of failure.
 *
 */
static int8_t UFP_emmcClose(void)
{
    MMCSD_Error    ret;

    ret = MMCSD_close(gEmmcHandle);
    gEmmcHandle = NULL;
    if(ret != MMCSD_OK)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief		This function reads the image from specified location of eMMC.
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
static int8_t UFP_emmcFlashRead(uint8_t *dst, uint32_t offset, uint32_t length)
{
    MMCSD_Error    ret;
    uint32_t blockNum;
    uint32_t blockCnt;

    blockNum = offset/EMMC_SECTOR_SIZE;
    blockCnt = length/EMMC_SECTOR_SIZE;

    ret = MMCSD_read(gEmmcHandle, dst, blockNum, blockCnt);
    if(ret != MMCSD_OK)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief		This function writes the image to eMMC on specified location.
 *
 *	\param		src			[IN]   	Pointer to the image to be flashed
 *	\param		offset		[IN]   	Offset to flash the image
 *	\param		length		[IN]	size of the image to be flashed.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */
static int8_t UFP_emmcFlashWrite(uint8_t *src, uint32_t offset, uint32_t length)
{
    MMCSD_Error    ret;
    uint32_t blockNum;
    uint32_t blockCnt;

    blockNum = offset/EMMC_SECTOR_SIZE;
    blockCnt = length/EMMC_SECTOR_SIZE;

    ret = MMCSD_write(gEmmcHandle, src, blockNum, blockCnt);
    if(ret != MMCSD_OK)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief		This function writes the image to eMMC and reads back
 *				the image on specified address.
 *
 *  \param      flashAddr   [IN]    Pointer to the image to be flashed
 *	\param		checkAddr   [OUT]   Pointer to store the read image
 *  \param      offset      [IN]    Offset to flash the image
 *  \param      size        [IN]    size of the image to be flashed.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */
static int8_t UFP_emmcFlashImage(uint8_t *flashAddr, uint8_t *checkAddr,
                                 uint32_t offset, uint32_t size)
{
    int8_t ret;

    ret = UFP_emmcFlashWrite(flashAddr, offset, size);
    if (ret != 0)
    {
        return -1;
    }
#if defined(SOC_AM65XX)
    /* Wait few cycles for the eMMC flash to be ready for next transfer.
       Ideally, this is not needed but just to make sure multi-sector transfer
       busy state is exited  */
    Osal_delay(EMMC_FW_WRITE_DELAY);
#endif

    ret = UFP_emmcFlashRead(checkAddr, offset, size);
    if (ret != 0)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief		This function erases the eMMC flash upto specified length
 *              from the specified address.
 *
 *	\param		offset		[IN]    Offset to erase the Flash.
 *	\param		length		[IN]    Erase length.
 *
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 */
static int8_t UFP_emmcFlashErase(uint32_t offset, uint32_t length)
{
    MMCSD_Error    ret;
    uint32_t blockNum;
    uint32_t blockCnt;
    uint32_t eraseLen;
    uint8_t *eraseBuff = gDataCheckBuff;  /* Reusing the buffer for erase */

    /* Erase the flash.
       There is no erase command for eMMC. Will be filled with 0s */
    while (length != 0)
    {
        if (length > DATA_BUFF_LEN)
        {
            eraseLen = DATA_BUFF_LEN;
            length -= DATA_BUFF_LEN;
        }
        else
        {
            eraseLen = length;
            length = 0;
        }
        blockNum = offset/EMMC_SECTOR_SIZE;
        blockCnt = eraseLen/EMMC_SECTOR_SIZE;

        if (eraseLen % 512)
        {
            ++blockCnt;
        }

        ret = MMCSD_write(gEmmcHandle, (uint8_t *)&eraseBuff[0], blockNum, blockCnt);
        if(ret != MMCSD_OK)
        {
            return -1;
        }
        offset += eraseLen;
    }

    return 0;
}

/**
 *  \brief		This function initializes eMMC flash.
 *				
 *  \return		int8_t
 *					0		- in case of success
 *	               -1		- in case of failure.
 *
 */
static int8_t UFP_emmcInit(void)
{
	MMCSD_Error         ret;
    int8_t partition = 1;

    UFP_emmcReset();
    MMCSD_init();

    ret = MMCSD_open(BOARD_MMCSD_EMMC_INSTANCE, NULL, &gEmmcHandle);
    if(ret != MMCSD_OK)
    {
        return -1;
    }

    /* Enable boot partition configurations */
    if ((ret = MMCSD_control(gEmmcHandle, MMCSD_CMD_ENABLEBOOTPARTITION,
                            (void *)&partition)))
    {
        return -1;
    }

    return 0;
}
