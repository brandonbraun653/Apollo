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
 * \file   led_indusrial_test.h
 *
 * \brief  This is the header file for LED Industrial diagnostic test.
 *
 */

#ifndef _LED_INDUSTRIAL_TEST_H_
#define _LED_INDUSTRIAL_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#if (defined(SOC_AM65XX) || defined(SOC_K2G))
#include "diag_common_cfg.h"
#endif

#if defined(SOC_AM65XX)
#include "board_i2c_io_exp.h"
#endif

#include "board.h"
#include "board_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_OF_TEST_ITERATIONS                               (3U)
#define NUM_OF_CONFIGURABLE_LEDS_PER_ITERATION               (8U)

/**
 *  \brief    This function is used to generate delays.
 *
 *  \param    delayValue          [IN]   Delay count.
 *
 */
#if ((!(defined(SOC_AM65XX))) || (!(defined(SOC_K2G))))
void BoardDiag_AppDelay(uint32_t delayVal);
#endif

/**
 *  \brief    This function is used to set the output level of the LEDs
 *            connected to the i2c slave device.
 *
 *  \param    handle              [IN]   I2C Handler
 *            signalLevelData     [IN]   Device output signal data.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
#if (!defined(SOC_AM65XX))
void led_write(I2C_Handle handle, uint8_t signalLevelData);
#endif

/**
 *  \brief    This test is used to run LED industrial diagnostic test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_led_industrial_test(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LED_INDUSTRIAL_TEST_H_ */
