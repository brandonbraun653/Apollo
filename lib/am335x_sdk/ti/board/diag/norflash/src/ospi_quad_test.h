/*
 * Copyright (C) 2019-2020 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   ospi_quad_test.h
 *
 *  \brief  NOR flash diagnostic test header file.
 *
 */

#ifndef _OSPI_QUAD_TEST_H_
#define _OSPI_QUAD_TEST_H_

#include <ti/drv/uart/UART_stdio.h>
#include <stdlib.h>
#include <ti/drv/spi/SPI.h>
#include <ti/board/src/flash/include/board_flash.h>
#include <ti/board/src/flash/nor/ospi/nor_qspi.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#include "board.h"
#include "board_cfg.h"
#include "diag_common_cfg.h"

//#define UDMA_ENABLE
#if defined(UDMA_ENABLE)
/* for enabling SPI_DMA */
#include <ti/drv/udma/udma.h>

/*
 * Ring parameters
 */
/** \brief Number of ring entries - we can prime this much memcpy operations */
#define UDMA_TEST_APP_RING_ENTRIES      (1U)
/** \brief Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define UDMA_TEST_APP_RING_ENTRY_SIZE   (sizeof(uint64_t))
/** \brief Total ring memory */
#define UDMA_TEST_APP_RING_MEM_SIZE     (UDMA_TEST_APP_RING_ENTRIES * \
                                         UDMA_TEST_APP_RING_ENTRY_SIZE)
/**
 *  \brief UDMA TR packet descriptor memory.
 *  This contains the CSL_UdmapCppi5TRPD + Padding to sizeof(CSL_UdmapTR15) +
 *  one Type_15 TR (CSL_UdmapTR15) + one TR response of 4 bytes.
 *  Since CSL_UdmapCppi5TRPD is less than CSL_UdmapTR15, size is just two times
 *  CSL_UdmapTR15 for alignment.
 */
#define UDMA_TEST_APP_TRPD_SIZE         ((sizeof(CSL_UdmapTR15) * 2U) + 4U)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_SPI_FIRST_PAGE                 (0)

#ifdef DIAG_STRESS_TEST
#define TEST_DATA_LEN                        (NOR_BLOCK_SIZE)
#define BOARD_SPI_LAST_PAGE                  (0x03FF0000U)

#else
#define TEST_DATA_LEN                        (NOR_PAGE_SIZE)
#define BOARD_SPI_LAST_PAGE         		 (0x03FFFF00U)
#endif

/**
 * \brief  NOR flash test function
 *
 * This function executes NOR flash test
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 */
int8_t BoardDiag_spiTest(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _OSPI_QUAD_TEST_H_ */
