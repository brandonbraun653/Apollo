/******************************************************************************
 * Copyright (c) 2017-2019 Texas Instruments Incorporated - http://www.ti.com
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/

/**
 *
 * \file   boot_eeprom_test.h
 *
 * \brief  This is the header file for EEPROM Diagnostic test.
 *
 */
#ifndef _BOOT_EEPROM_TEST_H_
#define _BOOT_EEPROM_TEST_H_

#ifdef __cplusplus
extern "C" {
#endif
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#if defined(SOC_J721E)
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/csl/csl_gpio.h>
#endif

#include <ti/csl/soc.h>

#include "board.h"
#include "board_cfg.h"

#include "diag_common_cfg.h"

#define ONE_KB_SIZE                             (1024U) /* 1024 Bytes */

#define BOARD_EEPROM_FIRST_PAGE                 (0U)
#if ((defined(am65xx_evm)) || (defined(am65xx_idk)))
/* Size of Boot EEPROM is 64 KB */
#define BOOT_EEPROM_SIZE                        (64 * ONE_KB_SIZE)

/* Size of Boot EEPROM page is 128 Bytes */
#define BOOT_EEPROM_PAGE_SIZE                   (128U)
#define BOARD_EEPROM_LAST_PAGE                  (511U)/* 511th Page */

#else
#define BOOT_EEPROM_SIZE                        (128 * ONE_KB_SIZE)

/* Size of Boot EEPROM page is 256 Bytes */
#define BOOT_EEPROM_PAGE_SIZE                   (256U)
#define BOARD_EEPROM_LAST_PAGE                  (255U) /* 255th Page */

#define BOARD_EEPROM_BLOCK2_FIRST_PAGE          (0U)
#define BOARD_EEPROM_BLOCK2_LAST_PAGE           (255U) /* 255th Page */

#define GPIO_SIGNAL_LOW                         (0U)
#endif

/* Total Boot EEPROM Pages - 512 */
#define TOTAL_BOOT_EEPROM_PAGES                 (BOOT_EEPROM_SIZE/BOOT_EEPROM_PAGE_SIZE)

/**
 *  \brief    The function performs the Boot EEPROM Diagnostic test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_boot_eeprom_test(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BOOT_EEPROM_TEST_H_ */
