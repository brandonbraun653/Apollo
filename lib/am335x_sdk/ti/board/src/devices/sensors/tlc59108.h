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
 * \file  tlc59108.h
 *
 * This file includes the structures, enums and register offsets
 * for initializing the remote FPD tlc59108 display sensor device.
 *
 */

#ifndef _TLC59108_H_
#define _TLC59108_H_

#include <ti/board/src/devices/common/common.h>
#include <ti/board/src/devices/fpd/ds90ub924.h>

#ifdef __cplusplus
extern "C" {
#endif
#define BOARD_FPD_TLC59108_PWM_CH0                           (0U)
#define BOARD_FPD_TLC59108_PWM_CH1                           (1U)
#define BOARD_FPD_TLC59108_PWM_CH2                           (2U)
#define BOARD_FPD_TLC59108_PWM_CH3                           (3U)
#define BOARD_FPD_TLC59108_PWM_CH4                           (4U)
#define BOARD_FPD_TLC59108_PWM_CH5                           (5U)
#define BOARD_FPD_TLC59108_PWM_CH6                           (6U)
#define BOARD_FPD_TLC59108_PWM_CH7                           (7U)

#define BOARD_FPD_TLC59108_MODE1_REG_ADDR                    (0x00U)
#define BOARD_FPD_TLC59108_PWM_CH0_REG_ADDR                  (0x2U)
#define BOARD_FPD_TLC59108_PWM_CH1_REG_ADDR                  (0x3U)
#define BOARD_FPD_TLC59108_PWM_CH2_REG_ADDR                  (0x4U)
#define BOARD_FPD_TLC59108_PWM_CH3_REG_ADDR                  (0x5U)
#define BOARD_FPD_TLC59108_PWM_CH4_REG_ADDR                  (0x6U)
#define BOARD_FPD_TLC59108_PWM_CH5_REG_ADDR                  (0x7U)
#define BOARD_FPD_TLC59108_PWM_CH6_REG_ADDR                  (0x8U)
#define BOARD_FPD_TLC59108_PWM_CH7_REG_ADDR                  (0x9U)
#define BOARD_FPD_TLC59108_LEDOUT0_REG_ADDR                  (0x0CU)

#define BOARD_FPD_TLC59108_LED0                              (0U)
#define BOARD_FPD_TLC59108_LED1                              (1U)
#define BOARD_FPD_TLC59108_LED2                              (2U)
#define BOARD_FPD_TLC59108_LED3                              (3U)

#define BOARD_FPD_TLC59108_LED_DRV_OFF                       (0U)
#define BOARD_FPD_TLC59108_LED_DRV_ON                        (1U)
#define BOARD_FPD_TLC59108_LED_DRV_ON_PMWX                   (2U)
#define BOARD_FPD_TLC59108_LED_DRV_ON_PMWX_GRPMW             (3U)

#define BOARD_FPD_TLC59108_LED0_SHIFT_CNT                    (0U)
#define BOARD_FPD_TLC59108_LED1_SHIFT_CNT                    (2U)
#define BOARD_FPD_TLC59108_LED2_SHIFT_CNT                    (4U)
#define BOARD_FPD_TLC59108_LED3_SHIFT_CNT                    (6U)
#define BOARD_FPD_TLC59108_OSC_SHIFT_CNT                     (4U)
#define BOARD_FPD_TLC59108_DEVICE_RESPONDS_SHIFT_CNT         (0U)

#define BOARD_FPD_TLC59108_LED0_BIT_MASK                     (uint8_t)(0x03 << BOARD_FPD_TLC59108_LED0_SHIFT_CNT)
#define BOARD_FPD_TLC59108_LED1_BIT_MASK                     (uint8_t)(0x03 << BOARD_FPD_TLC59108_LED1_SHIFT_CNT)
#define BOARD_FPD_TLC59108_LED2_BIT_MASK                     (uint8_t)(0x03 << BOARD_FPD_TLC59108_LED2_SHIFT_CNT)
#define BOARD_FPD_TLC59108_LED3_BIT_MASK                     (uint8_t)(0x03 << BOARD_FPD_TLC59108_LED3_SHIFT_CNT)
#define BOARD_FPD_TLC59108_OSC_BIT_MASK                      (uint8_t)(0x03 << BOARD_FPD_TLC59108_OSC_SHIFT_CNT)
#define BOARD_FPD_TLC59108_DEVICE_RESPONDS_BIT_MASK          (uint8_t)(0x01 << BOARD_FPD_TLC59108_DEVICE_RESPONDS_SHIFT_CNT)

#define BOARD_FPD_TLC59108_OSC_NORAMAL_OPERATION             (0U)
#define BOARD_FPD_TLC59108_OSC_OFF                           (1U)

/**
 * \brief  PWM Dutycycle control
 *
 * This function is used for configuring the specificed PWM
 * dutycylce of a specified channel.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdRmtParams  [IN]   FPD remote params
 * \param   chNum         [IN]   channel number to be configure
 * \param   dutyCycle     [IN]   dutycycle percentage
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_tlc59108PwmDutycycleCntrl(void *handle,
                                             Board_FpdRmtDevObj *fpdRmtParams,
                                             uint8_t chNum,
                                             uint8_t dutyCycle);

/**
 *  \brief  LED output mode control
 *
 * This function is used for configuring LED output state control.
 *
 *  \param   handle         I2C Handle
 *  \param   fpdModParams   FPD module params
 *  \param   ledSel         Led to be select:
 *                             -BOARD_FPD_tlc59108_LED0
 *                             -BOARD_FPD_tlc59108_LED1
 *                             -BOARD_FPD_tlc59108_LED2
 *                             -BOARD_FPD_tlc59108_LED3
 *  \param   ledDrvSet      Led driver mode to be configured
 *                             -BOARD_FPD_tlc59108_LED_DRV_OFF
 *                             -BOARD_FPD_tlc59108_LED_DRV_ON
 *                             -BOARD_FPD_tlc59108_LED_DRV_ON_PMWX
 *                             -BOARD_FPD_tlc59108_LED_DRV_ON_PMWX_GRPMW
 *
 *  \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_tlc59108LedOut0Cfg(void *handle,
                                      Board_FpdRmtDevObj *fpdRmtParams,
                                      uint8_t ledSel,
                                      uint8_t ledDrvSet);

/**
 *  \brief  Device responds to i2c all call mode control
 *
 * This function is used for configuring Device responds to i2c 
 * all call state control.
 *
 *  \param    handle         I2C Handle
 *  \param    fpdModParams   FPD module params
 *  \param    respMode       Enabling/Disabling device responds:
 *                              -BOARD_FPD_MODE_ENABLE
 *                              -BOARD_FPD_MODE_DISABLE
 *  \param    oscMode        Oscillator operational mode:
 *                              -BOARD_FPD_TLC59108_OSC_NORAMAL_OPERATION
 *                              -BOARD_FPD_TLC59108_OSC_OFF
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_tlc59108DeviceRespModeCfg(void *handle,
                                             Board_FpdRmtDevObj *fpdRmtParams,
                                             uint8_t respMode,
                                             uint8_t oscMode);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TLC59108_H_ */
