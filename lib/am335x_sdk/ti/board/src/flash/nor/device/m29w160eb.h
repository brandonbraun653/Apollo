/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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
 * \file  m29w160eb.h
 *
 * \brief This file contains M29W160EB NOR device definitions
 *
 *****************************************************************************/
#ifndef M29W160EB_H_
#define M29W160EB_H_

#include <ti/drv/spi/SPI.h>

#ifdef __cplusplus
extern "C" {
#endif
/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/** Macro to enable 4 byte addressing */
/* #define EXT_ADDRESS_ENABLE        (0U) */

/** FLASH device specific items (note: sizes are in bytes) */
#define NOR_SECTOR_SIZE             (64U * 1024U)
#define NOR_SIZE                    (64U * 1024U * 32U)
#define NOR_NUM_SECTORS             (NOR_SIZE / NOR_SECTOR_SIZE)
#define NOR_PAGE_SIZE               NOR_SECTOR_SIZE
#define NOR_NUM_PAGES_PER_SECTOR    (NOR_SECTOR_SIZE / NOR_PAGE_SIZE)
#define NOR_NUM_BLOCKS              NOR_NUM_SECTORS
#define NOR_NUM_PAGES_PER_BLOCK     NOR_NUM_PAGES_PER_SECTOR

#define NOR_BE_SECTOR_NUM           (-1U)

/** Flash device commands */
#define NOR_CMD_RESET               (0xF0U)     /* NOR Reset Command */
#define NOR_CMD_RDID                (0x90U)
#define NOR_CMD_BLK_ERASE_SETUP     (0x80U)     /* Block erase setup */
#define NOR_CMD_BLK_ERASE           (0x30U)     /* Block erase confirm */
#define NOR_CMD_BULK_ERASE          (0x10U)
#define NOR_CMD_BLK_ERASE_DONE      (0xFFU)     /* Block erase check value */
#define NOR_CMD_PROG                (0xA0U)     /* simple Write command */

#define NOR_CMD0                    (0xAAU)     /* NOR CMD PREFIX 0 */
#define NOR_CMD1                    (0x55U)     /*  NOR CMD PREFIX 1 */
#define NOR_CMD0_ADDR               (0x555U)    /*  NOR CMD0 Offset */
#define NOR_CMD1_ADDR               (0x2AAU)    /*  NOR CMD1 Offset */
#define NOR_CMD2_ADDR               (0x555U)    /* NOR CMD2 Offset */

#define NOR_MANFID_ADDR             (0x00U)     /* Manufacturer ID offset */
#define NOR_DEVID_ADDR0             (0x01U)     /* First device ID offset */
#define NOR_DEVID_ADDR1             (0x0EU)     /* Offset for 2nd byte of 3 byte ID */
#define NOR_DEVID_ADDR2             (0x0FU)     /* Offset for 3rd byte of 3 byte ID */

#define NOR_MANF_ID                 (0x20U)     /* Manufacturer ID */
#define NOR_DEVICE_ID               (0x2249U)   /* Device ID */

/** In Micro seconds */
#define NOR_WRITE_TIMEOUT           (600U * 1000U)
#define NOR_SECTOR_ERASE_TIMEOUT    (20U * 1000U * 1000U)
#define NOR_BULK_ERASE_TIMEOUT	    (110U * 1000U * 1000U)

#define NOR_MANUFACTURE_ID          (0x01U)

#ifdef __cplusplus
}
#endif

#endif /* M29W160EB_H_ */

/* Nothing past this point */
