/*
 * Copyright (c) 2017 - 2019, Texas Instruments Incorporated
 * All rights reserved.
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
 *
 * \file  n25q128a13esf40f.h
 *
 * \brief This file contains N25Q128A13ESF40F NOR device definitions
 *
 *****************************************************************************/
#ifndef W25X32VSFIG_H_
#define W25X32VSFIG_H_

#include <ti/drv/spi/SPI.h>

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/*!
 *  @brief FLASH device specific items (note: sizes are in bytes)
 */
#define NOR_BLOCK_SIZE              (65536U)
#define NOR_SECTOR_SIZE             (4096U)
#define NOR_SIZE                    (64U * 65536U)
#define NOR_NUM_BLOCKS              (NOR_SIZE / NOR_BLOCK_SIZE)
#define NOR_NUM_SECTORS             (NOR_SIZE / NOR_SECTOR_SIZE)
#define NOR_PAGE_SIZE               (256U)
#define NOR_NUM_PAGES_PER_SECTOR    (NOR_SECTOR_SIZE / NOR_PAGE_SIZE)
#define NOR_NUM_PAGES_PER_BLOCK     (NOR_BLOCK_SIZE / NOR_PAGE_SIZE)

/*!
 *  @brief Flash device commands
 */
#define NOR_BE_SECTOR_NUM           (-1U)
#define NOR_CMD_BULK_ERASE          (0xC7U)
#define NOR_CMD_BLOCK_ERASE         (0xD8U)
#define NOR_CMD_SECTOR_ERASE        (0x20U)
#define NOR_CMD_WREN                (0x06U)
#define NOR_CMD_RDSR                (0x05U)
#define NOR_CMD_RDID                (0x9FU)
#define NOR_CMD_READ                (0x03U)
#define NOR_CMD_PAGE_PROG           (0x02U)

/*!
 *  @brief Read ID command definitions
 */
#define NOR_RDID_NUM_BYTES          (0x3U)
#define NOR_MANF_ID                 (0xEFU)   /* Manufacturer ID */
#define NOR_DEVICE_ID               (0x4016)  /* Device ID */

/** Status Register, Write-in-Progress bit */
#define NOR_SR_WIP                  (1U << 0U)

/** In Micro seconds */
/*!
 *  @brief Timeout values in micro seconds
 */
#define NOR_PAGE_PROG_TIMEOUT       (400U)
#define NOR_SECTOR_ERASE_TIMEOUT    (600U * 1000U)
#define NOR_BULK_ERASE_TIMEOUT	    (110U * 1000U * 1000U)

#ifdef __cplusplus
}
#endif

#endif /* W25X32VSFIG_H_ */
