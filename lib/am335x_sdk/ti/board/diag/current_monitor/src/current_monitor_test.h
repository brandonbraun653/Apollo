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
 * \file   current_monitor_test.h
 *
 * \brief  This is the header file for current monitor diagnostic test.
 *
 */

#ifndef _CURRENT_MONITOR_TEST_H_
#define _CURRENT_MONITOR_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/csl/soc.h>

#include "board.h"
#include "board_cfg.h"

#include "diag_common_cfg.h"

#if defined(SOC_J721E)
#include <ti/drv/gpio/GPIO.h>
#include "board_internal.h"
#include "board_i2c_io_exp.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* INA Device Register Address Offsets */
#define CONFIGURATION_REG_ADDR_OFFSET     (0x00U)
#define SHUNT_VOLTAGE_REG_ADDR_OFFSET     (0x01U)
#define BUS_VOLTAGE_REG_ADDR_OFFSET       (0x02U)
#define POWER_REG_ADDR_OFFSET             (0x03U)
#define CURRENT_REG_ADDR_OFFSET           (0x04U)
#define CALIBRATION_REG_ADDR_OFFSET       (0x05U)

/* Number of INA device Instances used */
#if defined(SOC_AM65XX)
#define NUM_OF_INA_DEVICES                (0x08U)
#elif defined(SOC_K2G)
#define NUM_OF_INA_DEVICES                (0x04U)
#elif defined(SOC_J721E)
#define NUM_OF_INA_DEVICES                (31U)
#define TOT_INA_IN_PM1                    (15U)
#endif

/* INA Device register masks */
#define SHUNT_VOLTAGE_REG_MASK            (0x7fffU)
#define BUS_VOLTAGE_REG_MASK              (0x7fffU)
#define POWER_REG_MASK                    (0xffffU)
#define CURRENT_REG_MASK                  (0x7fffU)

#define CALIBRATION_CONSTANT              (5120000U)
#define DEFAULT_CONFIG_REG_VAL            (0x4497U)

#if defined(SOC_J721E)
#define SIGNAL_LEVEL_LOW                  (0U)
#define SIGNAL_LEVEL_HIGH                 (1U)
#endif

/**
 *  \brief Structure defining INA Device calibration parameters.
 */
typedef struct  CalibrationParams{
    uint8_t maxRShunt;
    float shuntVolLsb;
    float busVolLsb;
    float powerLsb;
    float currentLsb;
    uint16_t calibrartion;
}calParams_t;

/**
 *  \brief Structure defining INA Device configuration parameters.
 */
typedef struct inaCfgObj{
    char deviceID[20];
    uint8_t slaveAddr;
    calParams_t inaCalParams;
}inaCfgObj_t;

/**
 *  \brief    Generates a random delay.
 *
 *  \param    delayVal            [IN]   Delay count.
 *
 */
void BoardDiag_AppDelay(uint32_t delayVal);

/**
 *  \brief    The function performs the Current Monitor Diagnostic test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_CurrentMonitorTest(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _CURRENT_MONITOR_TEST_H_ */
