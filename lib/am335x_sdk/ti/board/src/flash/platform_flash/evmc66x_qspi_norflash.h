/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
 *
 */

/**
 *
 * \file  evmc66x_qspi_norflash.h
 *
 * \brief This file contains structure, typedefs, functions and
 *        prototypes used for qspi norflash.
 *
 *****************************************************************************/
#ifndef _EVMC66X_QSPI_NORFLASH_H_
#define _EVMC66X_QSPI_NORFLASH_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/** Macro to enable 4 byte addressing */
//#define EXT_ADDRESS_ENABLE  (0)

/** FLASH device specific items (note: sizes are in bytes) */
#define QSPI_FLASH_SECTOR_SIZE       (256 * 1024)
#define QSPI_FLASH_SIZE              (64 * 1024 * 1024)
#define QSPI_FLASH_NUM_SECTORS       (QSPI_FLASH_SIZE / QSPI_FLASH_SECTOR_SIZE)
#define QSPI_FLASH_PAGE_SIZE         (512)
#define QSPI_FLASH_MANUFACTURE_ID    (0x01)

/** Flash device commands */
#define QSPI_FLASH_BE_SECTOR_NUM     (-1)
#define QSPI_FLASH_CMD_BULK_ERASE    (0x60)
#define QSPI_FLASH_CMD_WRR			 (0x01)
#define QSPI_FLASH_CMD_WREN			 (0x06)
#define QSPI_FLASH_CMD_RDSR			 (0x05)
#define QSPI_FLASH_CMD_RDCR			 (0x35)
#define QSPI_FLASH_CMD_RDID			 (0x9F)

/** Different commands for 4 byte addressing and 3 byte addressing */
#ifdef EXT_ADDRESS_ENABLE
#define QSPI_FLASH_CMD_SECTOR_ERASE      (0xDC)
#define QSPI_FLASH_CMD_READ              (0x13)
#define QSPI_FLASH_CMD_DUAL_READ         (0x3C)
#define QSPI_FLASH_CMD_QUAD_READ         (0x6C)
#define QSPI_FLASH_CMD_PAGE_PROG         (0x12)
#define QSPI_FLASH_CMD_QUAD_PAGE_PROG    (0x34)
#else
#define QSPI_FLASH_CMD_SECTOR_ERASE      (0xD8)
#define QSPI_FLASH_CMD_READ              (0x03)
#define QSPI_FLASH_CMD_DUAL_READ         (0x3B)
#define QSPI_FLASH_CMD_QUAD_READ         (0x6B)
#define QSPI_FLASH_CMD_PAGE_PROG         (0x02)
#define QSPI_FLASH_CMD_QUAD_PAGE_PROG    (0x32)
#endif

/** Status Register, Write-in-Progress bit */
#define QSPI_FLASH_SR_WIP			(1 << 0)

/** Modes for Write and Read operation */
#define QSPI_FLASH_SINGLE_READ			(0)
#define QSPI_FLASH_DUAL_READ			(1)
#define QSPI_FLASH_QUAD_READ			(2)

#define QSPI_FLASH_SINGLE_PAGE_PROG		(0)
#define QSPI_FLASH_QUAD_PAGE_PROG		(2)

/** Dummy cycles for Read operation */
#define QSPI_FLASH_SINGLE_READ_DUMMY_CYCLE	(0)
#define QSPI_FLASH_DUAL_READ_DUMMY_CYCLE	(8)
#define QSPI_FLASH_QUAD_READ_DUMMY_CYCLE	(8)

/** In Micro seconds */
#define QSPI_FLASH_PAGE_PROG_TIMEOUT		(400)
#define QSPI_FLASH_SECTOR_ERASE_TIMEOUT		(600 * 1000)
#define QSPI_FLASH_WRR_WRITE_TIMEOUT		(600 * 1000)
#define QSPI_FLASH_BULK_ERASE_TIMEOUT	    (110 * 1000 * 1000)


/**************************************************************************
 **                      API function Prototypes
 **************************************************************************/

/**
 * \brief     Enables/Disables the QUAD mode of the FLASH device.
 *
 * \param     pDevice [IN]	: Platform device handle.
 * \param     enable [IN]	: Enables or disables the QUAD mode.
 *                 1		- Enable QUAD mode
 *                 0		- Disable QUAD mode.
 *
 * \return    QSPI_SUCCESS	: if success.
 *            QSPI_ERR		: if error.
 *
 **/
QSPI_STATUS qspiFlashQuadModeCtrl(PLATFORM_DEVICE_info *pDevice,
                                  uint8_t enable);

/**
 * \brief     Reads the device ID and manufacture ID of the FLASH device.
 *
 * \param     pDevice [IN]	: Platform device handle.
 *
 * \return    QSPI_SUCCESS	: if success.
 *            QSPI_ERR		: if error.
 *
 **/
QSPI_STATUS qspiFlashReadId(PLATFORM_DEVICE_info *pDevice);

/**
 * \brief     Reads the data from the FLASH device.
 *
 * \param     pDevice [IN]	: Platform device handle.
 * \param     addr    [IN]	: Address of the FLASH device in bytes.
 * \param     len     [IN]	: Length of the data to be read in bytes.
 * \param     buf     [IN]	: Pointer to the buffer of read data.
 * \param     mode    [IN]	: Mode of the FLASH device to be operated.
 *                            QSPI_FLASH_SINGLE_READ - Single mode.
 *                            QSPI_FLASH_DUAL_READ	 - Dual mode.
 *                            QSPI_FLASH_QUAD_READ	 - Quad mode.
 *
 *
 * \return    QSPI_SUCCESS		: if success.
 *            QSPI_ERR			: if error.
 *
 **/
QSPI_STATUS qspiFlashRead(PLATFORM_DEVICE_info *pDevice, uint32_t addr,
                          uint32_t len, uint8_t *buf, uint8_t mode);
/**
 * \brief     Writes the data into the FLASH device.
 *
 * \param     pDevice [IN]	: Platform device handle.
 * \param     addr    [IN]	: Address of the FLASH device in bytes.
 * \param     len     [IN]	: Length of the data to be written in bytes.
 * \param     buf     [IN]	: Pointer to the buffer of data to be
 *                            written.
 * \param     mode    [IN]	: Mode of the FLASH device to be
 *                            operated.
 *                            QSPI_FLASH_SINGLE_PAGE_PROG - Single mode.
 *                            QSPI_FLASH_QUAD_PAGE_PROG	  - Quad mode.
 *
 *
 * \return    QSPI_SUCCESS		: if success.
 *            QSPI_ERR			: if error.
 *
 **/
QSPI_STATUS qspiFlashWrite(PLATFORM_DEVICE_info *pDevice, uint32_t addr,
                           uint32_t len, uint8_t *buf, uint8_t mode);

/**
 * \brief     Erase the FLASH device.
 *
 * This function can perform sector erase or complete device erase of the
 * flash.
 *  Pass sector number as parameter for sector erase.
 *  Pass 'QSPI_FLASH_BE_SECTOR_NUM' as parameter for bulk or device erase.
 *
 * \param     pDevice [IN]		: Platform device handle.
 * \param     sector  [IN]		: Sector number to be erased.
 *                                0 to 255 - SECTOR ERASE.
 *                                QSPI_FLASH_BE_SECTOR_NUM - BULK ERASE.
 *
 * \return    QSPI_SUCCESS		: if success.
 *            QSPI_ERR			: if error.
 *
 **/
QSPI_STATUS qspiFlashErase(PLATFORM_DEVICE_info *pDevice, int32_t  sector);

/**
 * \brief     Initializes the FLASH device and configure communication
 *            between FLASH and QSPI controller.
 *
 * \param     pDevice  [IN]	: Platform device handle.
 *
 * \return    QSPI_SUCCESS	: if success.
 *            QSPI_ERR		: if error.
 *
 **/
QSPI_STATUS qspiFlashInit(PLATFORM_DEVICE_info *pDevice);

#ifdef __cplusplus
}
#endif

#endif /* _EVMC66X_QSPI_NORFLASH_H_ */

/* Nothing past this point */
