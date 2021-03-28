/*
 * Copyright (c) 2019, Texas Instruments Incorporated
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
 * \file  mt25qu512abb.h
 *
 * \brief This file contains MT25QU512ABB NOR device definitions
 *
 *****************************************************************************/
#ifndef MT25QU512ABB_H_
#define MT25QU512ABB_H_

#include <ti/drv/spi/SPI.h>

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/** Macro to enable 4 byte addressing */
/* #define EXT_ADDRESS_ENABLE        (0U) */

/** FLASH device specific items (note: sizes are in bytes) */
#define NOR_BLOCK_SIZE               (64U * 1024U)
#define NOR_SECTOR_SIZE              (4U * 1024U)
#define NOR_SIZE                     (64U * 1024U * 1024U)
#define NOR_NUM_BLOCKS               (NOR_SIZE / NOR_BLOCK_SIZE)
#define NOR_NUM_SECTORS              (NOR_SIZE / NOR_SECTOR_SIZE)
#define NOR_PAGE_SIZE                (256U)
#define NOR_NUM_PAGES_PER_SECTOR     (NOR_SECTOR_SIZE / NOR_PAGE_SIZE)
#define NOR_NUM_PAGES_PER_BLOCK      (NOR_BLOCK_SIZE / NOR_PAGE_SIZE)

/** Flash device commands */
#define NOR_BE_SECTOR_NUM            (-1U)
#define NOR_CMD_BULK_ERASE           (0x60U)
#define NOR_CMD_WRR                  (0x01U)
#define NOR_CMD_WREN                 (0x06U)
#define NOR_CMD_RDSR                 (0x05U)
#define NOR_CMD_RDCR_VOL             (0x85U)
#define NOR_CMD_RDCR_NVOL            (0xB5U)
#define NOR_CMD_RDID                 (0xAFU)

/** Different commands for 4 byte addressing and 3 byte addressing */
#ifdef EXT_ADDRESS_ENABLE
#define NOR_CMD_BLOCK_ERASE          (0xDCU)
#define NOR_CMD_SECTOR_ERASE         (0x21U)
#define NOR_CMD_READ                 (0x13U)
#define NOR_CMD_FAST_READ            (0x0CU)
#define NOR_CMD_OCTAL_O_FAST_RD      (0x7CU)
#define NOR_CMD_OCTAL_IO_FAST_RD     (0xCCU)
#define NOR_CMD_OCTAL_READ           (NOR_CMD_OCTAL_O_FAST_RD)
#define NOR_CMD_PAGE_PROG            (0x12U)
#define NOR_CMD_OCTAL_FAST_PROG      (0x84U)
#define NOR_CMD_EXT_OCTAL_FAST_PROG  (0x8EU)
#define NOR_CMD_OCTAL_PROG           (NOR_CMD_OCTAL_FAST_PROG)
#else
#define NOR_CMD_BLOCK_ERASE          (0xD8U)
#define NOR_CMD_SECTOR_ERASE         (0x20U)
#define NOR_CMD_READ                 (0x03U)
#define NOR_CMD_FAST_READ            (0x0BU)
#define NOR_CMD_QUAD_O_FAST_RD       (0x6BU)
#define NOR_CMD_QUAD_IO_FAST_RD      (0xEBU)
#define NOR_CMD_QUAD_DDR_O_FAST_RD   (0x6DU)
#define NOR_CMD_OCTAL_READ           (NOR_CMD_OCTAL_O_FAST_RD)
#define NOR_CMD_PAGE_PROG            (0x02U)
#define NOR_CMD_EXT_OCTAL_FAST_PROG  (0xC2U)
#define NOR_CMD_QUAD_FAST_PROG       (0x32U)
#define NOR_CMD_EXT_QUAD_FAST_PROG   (0x38U)
#define NOR_CMD_WRITE_VCR            (0x81U)
#define NOR_CMD_WRITE_ENVCR          (0x61U)
#define NOR_CMD_READ_VCR             (0x85U)
#define NOR_CMD_READ_ENVCR           (0x65U)
#define NOR_CMD_WRITE_NVCR           (0xB1U)
#define NOR_CMD_READ_NVCR            (0xB5U)
#endif

/* \brief Read ID command definitions */
#define NOR_RDID_NUM_BYTES           (0x3U)
#define NOR_MANF_ID                  (0x20U)    /* Manufacturer ID */
#define NOR_DEVICE_ID                (0xBB20)   /* Device ID */

/** Status Register, Write-in-Progress bit */
#define NOR_SR_WIP                   (1U << 0U)

/** Dummy cycles for Read operation */
/** Dummy cycles for Read operation */
#define NOR_SINGLE_READ_DUMMY_CYCLE  (0U)
#define NOR_OCTAL_READ_DUMMY_CYCLE   (16U)
#define NOR_QUAD_READ_DUMMY_CYCLE   (10U)


/** In Micro seconds */
#define NOR_PAGE_PROG_TIMEOUT        (400U)
#define NOR_SECTOR_ERASE_TIMEOUT     (600U * 1000U)
#define NOR_WRR_WRITE_TIMEOUT        (600U * 1000U)
#define NOR_BULK_ERASE_TIMEOUT       (110U * 1000U * 1000U)


#endif /* MT25QU512ABB_H_ */
