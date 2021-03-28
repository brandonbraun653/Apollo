/******************************************************************************
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 * \file   eeprom_stress_test.h
 *
 * \brief  This is the header file for EEPROM Stress test.
 *
 */

#ifndef _EEPROM_STRESS_TEST_H_
#define _EEPROM_STRESS_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#if defined(SOC_J721E)
#include <ti/csl/soc.h>
#endif
#include "board.h"
#include "board_cfg.h"

#include "diag_common_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ONE_KB_SIZE                             (1024U) /* 1024 Bytes */

/* Size of Boot EEPROM is 64 KB */
#define BOOT_EEPROM_SIZE                        (64 * ONE_KB_SIZE)

/* Size of Boot EEPROM page is 128 Bytes */
#define BOOT_EEPROM_PAGE_SIZE                   (128U)

/* Total Boot EEPROM Pages - 512 */
#define TOTAL_BOOT_EEPROM_PAGES                 (BOOT_EEPROM_SIZE/BOOT_EEPROM_PAGE_SIZE)

#define BOARD_EEPROM_FIRST_PAGE                 (0U)

#define BOARD_EEPROM_LAST_PAGE                  (511U)/* 511th Page */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _EEPROM_STRESS_TEST_H_ */
