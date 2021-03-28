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
 * \file  mt29f4g08ab.h
 *
 * \brief This file contains MT29F4G08AB NAND device definitions
 *
 *****************************************************************************/
#ifndef MT29F4G08AB_H_
#define MT29F4G08AB_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/** \brief FLASH device specific items (note: sizes are in bytes) */
#define NAND_BLOCK_SIZE               (256U * 1024U)
#define NAND_SIZE                     (512U * 1024U * 1024U)
#define NAND_NUM_BLOCKS               (NAND_SIZE / NAND_BLOCK_SIZE)
#define NAND_PAGE_SIZE                (4096U)
#define NAND_NUM_PAGES_PER_BLOCK      (NAND_BLOCK_SIZE / NAND_PAGE_SIZE)
#define NAND_SPARE_AREA_SIZE          (224U)

#define NAND_NUM_BYTES_COLUMN_ADDR    (2U)
#define NAND_NUM_BYTES_ROW_ADDR       (4U)

/** \brief Flash device commands */
#define NAND_CMD_RESET                (0xFFU)
#define NAND_CMD_RDID                 (0x90U)
#define NAND_CMD_READ_STATUS          (0x70U)
#define NAND_CMD_READ                 (0x00U)
#define NAND_CMD_READ_CYC2            (0x30U)
#define NAND_CMD_PROG_PAGE            (0x80U)
#define NAND_CMD_PROG_PAGE_CYC2       (0x10U)
#define NAND_CMD_ERASE                (0x60U)
#define NAND_CMD_ERASE_CYC2           (0xD0U)
#define NAND_CMD_READ_RANDOM          (0x05U)
#define NAND_CMD_READ_RANDOM_CYC2     (0xE0U)
#define NAND_CMD_INPUT_RANDOM         (0x85U)
#define NAND_CMD_READ_CACHE           (0x31U)
#define NAND_CMD_READ_CACHE_LAST      (0x3FU)

/* \brief Read ID command definitions */
#define NAND_RDID_NUM_BYTES           (0x5U)
#define NAND_MANF_ID                  (0x2CU)   /* Manufacturer ID */
#define NAND_DEVICE_ID                (0xDC90U) /* Device ID */

/* \brief Read status command definitions */
#define NAND_READ_STATUS_FAIL_MASK    (0x01) /* fail mask */
#define NAND_READ_STATUS_DEVRDY_MASK  (0x20) /* device ready mask */
#define NAND_READ_STATUS_WRPROT_MASK  (0x80) /* write protect mask */

/* \brief Bad block definitions */
#define NAND_BAD_BLK_OFFSET           (0x0U) /* offset address of bad blk mark in spare area*/
#define NAND_BLK_GOOD_MARK            (0xFFU)
#define NAND_BLK_BAD_MARK             (0x0U)

/** \brief Macro to specify the number of bytes per transaction. */
#define NAND_BYTES_PER_XFER           (512U)

/** \brief Time out value in Micro seconds */
#define NAND_TIMEOUT_VAL              (0xFFFFU)


/** \brief Macro defining the Hamming Code ECC Offset value. */
#define NAND_ECC_1BIT_HAMMINGCODE_OOB_OFFSET          (1U)

/** \brief Macro defining the Hamming Code ECC Byte Count value. */
#define NAND_ECC_1BIT_HAMMINGCODE_BYTECNT             (3U)

/** \brief Macro defining the 4-bit Reed-Solomon ECC Offset value. */
#define NAND_ECC_RS_4BIT_OOB_OFFSET                   (0U)

/** \brief Macro defining the 4-bit Reed-Solomon ECC Byte Count value. */
#define NAND_ECC_RS_4BIT_UNUSED_BYTECNT               (6U)

/** \brief Macro defining the 4-bit Reed-Solomon ECC Byte Count value. */
#define NAND_ECC_RS_4BIT_BYTECNT                      (10U)

/** \brief Macro defining the 8-bit BCH ECC Offset value. */
#define NAND_ECC_BCH_8BIT_OOB_OFFSET                  (2U)

/** \brief Macro defining the 8-bit BCH ECC Byte Count value. */
#define NAND_ECC_BCH_8BIT_BYTECNT                     (14U)

/** \brief Macro defining the 8-bit BCH ECC Unused Byte Count value. */
#define NAND_ECC_BCH_8BIT_UNUSED_BYTECNT              (2U)

/** \brief Macro defining the 8-bit BCH ECC Nibble Count value. */
#define NAND_ECC_BCH_8BIT_NIBBLECNT                   (26U)

/** \brief Macro defining the Last Data bit for 8-bit BCH ECC scheme. */
#define NAND_ECC_BCH_8BIT_LASTDATABIT                 ((512 + 13) * 8)

/** \brief Macro defining the Last ECC bit for 8-bit BCH ECC scheme. */
#define NAND_ECC_BCH_8BIT_LASTECCBIT                  ((13 + 1) * 8)

/** \brief Macro defining the Number of ECC bytes per Transfer. */
#define NAND_MAX_ECC_BYTES_PER_TRNFS                  (16)

#ifdef __cplusplus
}
#endif

#endif /* MT29F4G08AB_H_ */

/* Nothing past this point */
