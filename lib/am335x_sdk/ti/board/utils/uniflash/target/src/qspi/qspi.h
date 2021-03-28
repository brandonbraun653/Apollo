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


#ifndef _QSPI_H_
#define _QSPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <xmodem.h>

#include <ti/board/board.h>
#include <ti/board/board_cfg.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>

#if defined(SOC_AM571x)
#include <ti/board/src/idkAM571x/device/qspi_flash.h>
#elif defined(SOC_AM572x)
#include <ti/board/src/idkAM572x/device/qspi_flash.h>
#elif defined(SOC_AM574x)
#include <ti/board/src/idkAM574x/device/qspi_flash.h>

#elif defined(SOC_K2G)
#include <ti/board/src/flash/include/board_flash.h>
#include <ti/board/src/flash/nor/qspi/nor_qspi.h>

#elif defined(SOC_AM437x)
#include <ti/board/src/idkAM437x/device/qspi_flash.h>

#elif defined(j721e_evm)
#include <ti/board/src/flash/include/board_flash.h>
#endif

#ifdef iceK2G
#define QSPI_FLASH_ID   BOARD_FLASH_ID_QSPIFLASH_S25FL256S
#elif evmK2G
#define QSPI_FLASH_ID   BOARD_FLASH_ID_QSPIFLASH_S25FL512S
#elif defined(j721e_evm)
#define QSPI_FLASH_ID           BOARD_FLASH_ID_MT25QU512ABB
#define QSPI_NOR_BLOCK_SIZE     (64U * 1024U)
#endif

#if !(defined(SOC_K2G) || defined(j721e_evm))
extern QSPI_HwAttrs qspiInitCfg[1];

/** QSPI device specific definitions */
#define QSPI_INSTANCE                       (0U)
#if defined (SOC_AM437x)
#define QSPI_OFFSET             			(5U)
#endif
#if defined (SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_AM574x)
#define QSPI_OFFSET             			(4U)
#endif
#define QSPI_DEVICE_BLOCK_SIZE              (S25FL_FLASH_BLOCK_SIZE)

#endif /* SOC_K2G */

#define QSPI_FW_WRITE_DELAY                 (1000U)

extern const UFP_fxnTable UFP_qspiFxnTable;

#ifdef __cplusplus
}
#endif

#endif /* _QSPI_H_ */
