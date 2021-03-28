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
 * \file  s25fl512s.h
 *
 * \brief This file contains S25Fl512S NOR device definitions
 *
 *****************************************************************************/
#ifndef S71KS512S_H_
#define S71KS512S_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 **                       Macro Definitions
 **************************************************************************/

/** FLASH device address */
#define NOR_HPF_MANF_ID_ADDR        (0x0000U)
#define NOR_HPF_DEV_ID_ADDR         (0x0002U)

#define NOR_HPF_QUERY_REG1          (0x0080U)
#define NOR_HPF_QUERY_REG2          (0x0082U)
#define NOR_HPF_QUERY_REG3          (0x0084U)

#define NOR_HPF_CMD_ADDR1           (0xAAAU)
#define NOR_HPF_CMD_ADDR2           (0x554U)

/** FLASH device specific items (note: sizes are in bytes) */
#define NOR_SECTOR_SIZE             (256U * 1024U)
#define NOR_SIZE                    (64U * 1024U * 1024U)
#define NOR_NUM_SECTORS             (NOR_SIZE / NOR_SECTOR_SIZE)
#define NOR_PAGE_SIZE               (32U)
#define NOR_NUM_PAGES_PER_SECTOR    (NOR_SECTOR_SIZE / NOR_PAGE_SIZE)

/** Flash device commands */
#define NOR_BE_SECTOR_NUM           (-1U)
#define NOR_CMD_BULK_ERASE          (0x10U)
#define NOR_CMD_SECTOR_ERASE        (0x30U)
#define NOR_CMD_WRITE_UNLOCK1       (0xAAU)
#define NOR_CMD_WRITE_UNLOCK2       (0x55U)
#define NOR_CMD_CFI_ENTRY           (0x90U)
#define NOR_CMD_WRITE_BUFFER        (0x25U)
#define NOR_CMD_WRITE_COMMENCE      (0x29U)
#define NOR_CMD_ERASE_CMD1          (0x80U)
#define NOR_CMD_ERASE_CMD2          (0xAAU)
#define NOR_CMD_ERASE_CMD3          (0x55U)
#define NOR_CMD_READ_DEV_STS        (0x70U)
#define NOR_CMD_CLEAR_DEV_STS       (0x71U)
#define NOR_CMD_RESET               (0xF0U)

#define NOR_DEV_READY_STATUS        (0x80U)
#define NOR_MAX_WRITE_LEN           (512U)      /* 512 Bytes */

#define NOR_MANF_ID                 (0x0001U)   /* Manufacturer ID */
#define NOR_DEVICE_ID               (0x007EU)   /* Device ID */

/** In Micro seconds */
#define NOR_PAGE_PROG_TIMEOUT		(400U)
#define NOR_SECTOR_ERASE_TIMEOUT	(3U * 1000U * 1000U)
#define NOR_BULK_ERASE_TIMEOUT	    (500U * 1000U * 1000U)
#define NOR_WRR_WRITE_TIMEOUT		(5000U)
#define NOR_WRR_READ_TIMEOUT		(1000U)

#define NOR_HPF_DLL_LOCK_MAX_CHECK  (20U)

#ifdef __cplusplus
}
#endif

#endif /* S71KS512S_H_ */

/* Nothing past this point */
