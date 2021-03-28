/**
 *  \file   GPMC_board.h
 *
 *  \brief  GPMC Board header file
 *
 */

/*
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef GPMC_BOARD_H
#define GPMC_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined (ICEV2_AM335X)
#include <ti/board/src/icev2AM335x/include/board_cfg.h>
#elif defined (EVM_AM437X)
#include <ti/board/src/evmAM437x/include/board_cfg.h>
#else
#endif

#if defined (ICEV2_AM335X)
#define BOARD_FLASH_ID         BOARD_FLASH_ID_MT29W160EB
#define BOARD_FLASH_INSTANCE   BOARD_GPMC_NOR_INSTANCE

/* GPMC NOR flash offset address for read/write test */
#define TEST_ADDR_OFFSET       (0x10000U)  /* Sector 1 start address */
/* Test read/write data length in bytes */
#define TEST_DATA_LEN          (512U)

#elif defined (EVM_AM437X)
#define BOARD_FLASH_ID         BOARD_FLASH_ID_MT29F4G08ABAEAWP
#define BOARD_FLASH_INSTANCE   BOARD_GPMC_NAND_INSTANCE

/* GPMC NOR flash offset address for read/write test */
#define TEST_ADDR_OFFSET       (0x40000U)  /* Block 1 start address */
/* Test read/write data length in bytes */
#define TEST_DATA_LEN          (4096U)

#else
#endif

/* Do not enable the erase/write test */
#undef TEST_GPMC_FLASH_WRITE

#ifdef __cplusplus
}
#endif

#endif /* GPMC_BOARD_H */
