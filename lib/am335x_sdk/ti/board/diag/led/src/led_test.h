/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 * \file   led_test.h
 *
 * \brief  This is the header file for LED diagnostic test.
 *
 */

#ifndef _LED_TEST_H_
#define _LED_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(SOC_J721E)
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#endif
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/soc.h>

#include "board.h"
#include "board_cfg.h"

#if (defined(SOC_K2G) || defined(SOC_AM65XX) || defined(SOC_J721E))
#include "diag_common_cfg.h"
#endif

#if (defined(SOC_AM65XX) && defined(AM65XX_BETA_BOARD)) || defined(SOC_J721E)
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include "board_i2c_io_exp.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif


#define GPIO_PIN_VAL_LOW        (0U)
#define GPIO_PIN_VAL_HIGH       (1U)

#define NUMBER_OF_CYCLES        (3)

#if defined (iceK2G)
#include <ti/drv/gpio/soc/GPIO_soc.h>
#define GPIO_LED0_PIN_NUM        (11U) /* by default PADCONFIG139 set to GPIO0_108 */
#define GPIO_LED0_PORT_NUM       (0U)   /* GPIO port 0 */
#define DELAY_VALUE              (5000000)

/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_LED {
    USER_LED0 = 0,
    USER_LED1
}GPIO_LED;

uint32_t gLedNum;
#ifdef _TMS320C6X
#define GPIO_MUX_SEL             (16U) /* Event slect number for DSP GPIOMUX int */
#else
#define GPIO_MUX_SEL             (0U)  /* Event slect number for ARM GPIOMUX int */
#endif

/* Application callback function while running the LED test in interrupt mode */
void AppGpioCallbackFxn(void);
#endif /* iceK2G */

/**
 *  \brief    This function is used to generate delays.
 *
 *  \param    delayValue          [IN]   Delay count.
 *
 */
#if (!((defined(SOC_AM65XX)) || (defined(SOC_J721E))))
void BoardDiag_AppDelay(uint32_t delayVal);
#endif

/**
 *  \brief    This test performs the LED diagnostic test by toggling
 *            all the LEDs that exists.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t led_test(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LED_TEST_H_ */
