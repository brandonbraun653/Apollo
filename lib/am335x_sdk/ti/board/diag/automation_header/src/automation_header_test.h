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
 * \file   automation_header_test.h
 *
 * \brief  This is the header file for automation header diagnostic test.
 *
 */
#ifndef _AUTOMATION_HEADER_TEST_H_
#define _AUTOMATION_HEADER_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/csl/soc.h>
#include <soc.h>

#include "board.h"
#include "board_cfg.h"

#include "diag_common_cfg.h"

#if (defined(am65xx_som) || defined(j7es_som) || defined(SOC_J721E))
#include "board_internal.h"
#include "board_i2c_io_exp.h"
#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SIGNAL_LEVEL_LOW                           (0U)

#define CMD_INPUT_PORT0_REG_ACCESS                 (0x00)
#define CMD_INPUT_PORT1_REG_ACCESS                 (0x01)
#define CMD_INPUT_PORT2_REG_ACCESS                 (0x02)

#define CMD_OUTPUT_PORT0_REG_ACCESS                (0x4)
#define CMD_OUTPUT_PORT1_REG_ACCESS                (0x5)
#define CMD_OUTPUT_PORT2_REG_ACCESS                (0x6)

#define CMD_CFG_PORT0_REG_ACCESS                (0xC)
#define CMD_CFG_PORT1_REG_ACCESS                (0xD)
#define CMD_CFG_PORT2_REG_ACCESS                (0xE)

#define NUM_OF_SW2_CONFIGURABLE_POSITIONS          (9U)
#define NUM_OF_SW3_CONFIGURABLE_POSITIONS          (9U)

#if (defined(am65xx_som) || defined(j7es_som) || defined(SOC_J721E))
#define BOOTMODE_CFG_SET1_PIN_POS                  (0x00U) //J7ES_TBD: Need to update sd boot mode
#define BOOTMODE_CFG_SET2_PIN_POS                  (0x07U)
#else
#define BOOTMODE_CFG_SET1_PIN_POS                  (0x06U) /* SW3 */
#define BOOTMODE_CFG_SET2_PIN_POS                  (0x10U) /* SW2 */
#endif

/**
 *  \brief    The function performs the Automation header test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_automationHeaderTest(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _AUTOMATION_HEADER_TEST_H_ */
