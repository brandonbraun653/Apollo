/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   spi_test.h
 *
 *  \brief  spi diagnostic test header file.
 *
 */

#ifndef _SPI_TEST_H_
#define _SPI_TEST_H_

#include <ti/drv/uart/UART_stdio.h>
#include <stdlib.h>
#include <ti/drv/spi/SPI.h>
#include <ti/board/src/flash/include/board_flash.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#include "board.h"
#include "board_cfg.h"
#include "diag_common_cfg.h"
#include "soc.h"

#define NOR_PAGE_SIZE       (256U)
#define TEST_DATA_LEN       (NOR_PAGE_SIZE)
#define BUFF_SIZE           (TEST_DATA_LEN)
#define MAX_BUFF_SIZE       (NOR_PAGE_SIZE)

#define PAGES_PER_SECTOR    (256U)
#define SECTOR_SIZE         (PAGES_PER_SECTOR * NOR_PAGE_SIZE)
#define MAX_SECTORS         (256U)
#define TESTPAGES           (1U)

#ifdef DIAG_STRESS_TEST
#define SPI_FLAH_TEST_MAX_PAGES     (MAX_SECTORS * PAGES_PER_SECTOR)
#else
#define SPI_FLAH_TEST_MAX_PAGES     (1U)
#endif

#define DATA_PATTERN_FF     (1)
#define DATA_PATTERN_INC    (2)
#define DATA_PATTERN_AA     (3)
#define DATA_PATTERN_55     (4)
#define DATA_PATTERN_RANDOM (5)

#define CSL_SPI_PER_CNT   (2U)

#define SPI_INSTANCE      (2U)

#define BOARD_SPI_FIRST_PAGE        (0x0000)
#define BOARD_SPI_LAST_PAGE         (0xFFFF00)

#define MAX_CLOCK 48000000 /* 48MHz */

/* Flash device commands */
#define NOR_CMD_SECTOR_ERASE        (0xD8U)
#define NOR_CMD_WREN                (0x06U)
#define NOR_CMD_RDSR                (0x05U)
#define NOR_CMD_READ                (0x03U)
#define NOR_CMD_PAGE_PROG           (0x02U)
#define NOR_CMD_RDID                (0x9FU)

#define MCSPI1_BASE_ADDRESS CSL_MCSPI0_CFG_BASE

#define MCSPI_OUT_FREQ              (24000000U)
#define MCSPI_IN_CLK                (48000000U)

#define SPI_FLASH_DEVID_BYTE0       (0x20)
#define SPI_FLASH_DEVID_BYTE1       (0xBA)
#define SPI_FLASH_DEVID_BYTE2       (0x18)

/**
 * \brief  spi flash test function
 *
 *  This test executes SPI NOR flash memory access test and boundary test.
 *  Memory access test can be verified using the erase, read and write commands
 *  Boundary test can be verified by performing memory access test on first and last
 *  pages of the memory.
 *
 * \return  int
 *             0  - in case of success
 *             -1  - in case of failure
 */
int BoardDiag_SpiFlashTest(void);

/**
 * \brief  spi test function
 *
 * This function executes spi flash test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */
int BoardDiag_SpiTest(void);

#endif /* _SPI_TEST_H_ */
