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
 * \file   gpio_test_header.h
 *
 * \brief  This is the header file for gpio test header diagnostic test.
 *
 */

#ifndef _GPIO_TEST_HEADER_H_
#define _GPIO_TEST_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <soc.h>

#include "board.h"
#include "board_cfg.h"

#if defined(am65xx_evm)
#include "src/am65xx_evm/am65xx_evm_pinmux.h"
#elif defined(am65xx_idk)
#include "src/am65xx_idk/am65xx_idk_pinmux.h"
#elif defined(SOC_J721E)
#include "board_pinmux.h"
#endif

#include "diag_common_cfg.h"

#if (defined(SOC_J721E))
#include <ti/csl/csl_gpio.h>
#include "board_internal.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO_PIN_VAL_LOW            (0U)
#define GPIO_PIN_VAL_HIGH           (1U)

#define MAX_HEADER_LENGTH           (50U)
#define I2C_IO_STS_SUCCESS          (0U)

#if defined(SOC_AM65XX)
/* Maximum number of pad config registers supported */
#define PADCONFIG_MAX_COUNT         (5U)
#define MAIN_PADCONFIG_MAX_COUNT    (5U)
/* number of gpio pin sets for loopback test*/
#define NUM_PIN_SETS                (2U)
#else /* defined SOC_J721E */
/* Maximum number of pad config registers supported for J7 evm */
#define PADCONFIG_MAX_COUNT_ALPHA         (30U)
#define MAIN_PADCONFIG_MAX_COUNT_ALPHA    (28U)
#define MLB_HEADER_PADCONFIG_INDEX        (31U)

#define PADCONFIG_MAX_COUNT_BETA         (16U)
#define MAIN_PADCONFIG_MAX_COUNT_BETA    (14U)

#define NUM_OF_MLB_HEADER_PINS      (3U)
/* number of gpio pin sets for loopback test*/
#define NUM_PIN_SETS                (3U)
#endif

/* Quaternary pin mux mode */
#define GPIO_PADCONFIG_MUX_MODE     (7U)

#if (defined(SOC_J721E))
#include "board_i2c_io_exp.h"
#define I2C_INSTANCE                (0)
#endif

typedef struct testHeaderPinDetails
{
    char headerName[MAX_HEADER_LENGTH];
    uint8_t offsetIndex;
    uint8_t numOfPins;
    uint32_t baseAddress;
}testHeaderPinDetails_t;

/**
 *  \brief    The function performs GPIO test header verification test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_gpio_test_header_verification(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* #ifndef _GPIO_TEST_HEADER_H_ */
