/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 * \file    boosterpack_gpio_test.h
 *
 * \brief  This is the header file for boost gpio diagnostic test.
 *
 */

#ifndef _BOOST_GPIO_TEST_H_
#define _BOOST_GPIO_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#include <ti/csl/csl_gpio.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <soc.h>

#include "board.h"
#include "board_cfg.h"

#if defined(am65xx_evm)
#include "src/am65xx_evm/am65xx_evm_pinmux.h"
#elif defined(am65xx_idk)
#include "src/am65xx_idk/am65xx_idk_pinmux.h"
#endif
#include "diag_common_cfg.h"
#include "board_internal.h"

#ifdef __cplusplus
extern "C" {
#endif

#define START_OF_PWM_OUT_PINS				   (8U)
#define END_OF_PWM_OUT_PINS					   (13U)

/* Maximum number of pad config registers supported */
#define PADCONFIG_MAX_COUNT                    (23U)

/* pin mux mode */
#define GPIO_PADCONFIG_MUX_MODE                (7U)

#define DEEP_SLEEP_MASK						   (0xF7DFFFFFU)

#define NUM_PIN_SETS                           (11U)
#define PIN_NUM_MAX                            (3U)

typedef enum gpioSignalLevel
{
    SIGNAL_LEVEL_LOW = 0U,
    SIGNAL_LEVEL_HIGH
}gpioSignalLevel_t;

typedef enum headerDetails
{
    J14_HEADER = 14U,
    J15_HEADER
}headerDetails_t;

typedef enum pinDetails
{
    PIN1 = 1U,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15,
    PIN16,
    PIN17,
    PIN18,
    PIN19,
    PIN20
}pinDetails_t;

typedef enum pinSetMode
{
    TWO_PIN_SET = 2U,
    THREE_PIN_SET
}pinSetMode_t;

typedef struct boostGpioPinDetails
{
    headerDetails_t headerName;
    uint8_t pinNum[PIN_NUM_MAX];
    uint8_t offsetIndex;
    pinSetMode_t pinSetMode;
}boostGpioPinDetails_t;

/**
 *  \brief    The function performs Boosterpack GPIO loopback test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_boost_gpio_loopback_test(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* #ifndef _BOOST_GPIO_TEST_H_ */
