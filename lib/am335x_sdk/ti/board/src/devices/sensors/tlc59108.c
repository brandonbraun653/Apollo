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
 * \file    tlc59108.c
 *
 * \brief   This file contains the default API's for initializing the
 *          remote FPD tlc59108 display sensor device.
 *
 */

#include "tlc59108.h"

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
                                             uint8_t dutyCycle)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData, regAddr = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    switch (chNum)
    {
        case BOARD_FPD_TLC59108_PWM_CH0:
             regAddr = BOARD_FPD_TLC59108_PWM_CH0_REG_ADDR;
             break;
        case BOARD_FPD_TLC59108_PWM_CH1:
             regAddr = BOARD_FPD_TLC59108_PWM_CH1_REG_ADDR;
             break;
        case BOARD_FPD_TLC59108_PWM_CH2:
             regAddr = BOARD_FPD_TLC59108_PWM_CH2_REG_ADDR;
             break;
        case BOARD_FPD_TLC59108_PWM_CH3:
             regAddr = BOARD_FPD_TLC59108_PWM_CH3_REG_ADDR;
             break;
        case BOARD_FPD_TLC59108_PWM_CH4:
             regAddr = BOARD_FPD_TLC59108_PWM_CH4_REG_ADDR;
             break;
        case BOARD_FPD_TLC59108_PWM_CH5:
             regAddr = BOARD_FPD_TLC59108_PWM_CH5_REG_ADDR;
             break;
        case BOARD_FPD_TLC59108_PWM_CH6:
             regAddr = BOARD_FPD_TLC59108_PWM_CH6_REG_ADDR;
             break;
        case BOARD_FPD_TLC59108_PWM_CH7:
             regAddr = BOARD_FPD_TLC59108_PWM_CH7_REG_ADDR;
             break;
        default :
            BOARD_DEVICES_ERR_LOG("\nInvalid channel\n");
            break;
    }

    regData = ((dutyCycle * 256)/100);

    ret = Board_i2c8BitRegWr(handle,
                             fpdRmtParams->i2cDevAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return ret;
    }

    return BOARD_SOK;
}

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
                                      uint8_t ledDrvSet)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;
    uint8_t mask = 0, cnt = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if(ledSel == BOARD_FPD_TLC59108_LED0)
    {
        mask = BOARD_FPD_TLC59108_LED0_BIT_MASK;
        cnt = BOARD_FPD_TLC59108_LED0_SHIFT_CNT;
    }
    else if(ledSel == BOARD_FPD_TLC59108_LED1)
    {
        mask = BOARD_FPD_TLC59108_LED1_BIT_MASK;
        cnt = BOARD_FPD_TLC59108_LED1_SHIFT_CNT;
    }
    else if(ledSel == BOARD_FPD_TLC59108_LED2)
    {
        mask = BOARD_FPD_TLC59108_LED2_BIT_MASK;
        cnt = BOARD_FPD_TLC59108_LED2_SHIFT_CNT;
    }
    else if(ledSel == BOARD_FPD_TLC59108_LED3)
    {
        mask = BOARD_FPD_TLC59108_LED3_BIT_MASK;
        cnt = BOARD_FPD_TLC59108_LED3_SHIFT_CNT;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdRmtParams->i2cDevAliasAddr,
                             BOARD_FPD_TLC59108_LEDOUT0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return ret;
    }

    regData &= ~(mask);
    regData |= (ledDrvSet << cnt);
    ret = Board_i2c8BitRegWr(handle,
                             fpdRmtParams->i2cDevAliasAddr,
                             BOARD_FPD_TLC59108_LEDOUT0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return ret;
    }

    return BOARD_SOK;

}

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
                                             uint8_t oscMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdRmtParams->i2cDevAliasAddr,
                             BOARD_FPD_TLC59108_MODE1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return ret;
    }

    regData &= ~(BOARD_FPD_TLC59108_DEVICE_RESPONDS_BIT_MASK);
    regData |= (respMode << BOARD_FPD_TLC59108_DEVICE_RESPONDS_SHIFT_CNT);

    regData &= ~(BOARD_FPD_TLC59108_OSC_BIT_MASK);
    regData |= (oscMode << BOARD_FPD_TLC59108_OSC_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdRmtParams->i2cDevAliasAddr,
                             BOARD_FPD_TLC59108_MODE1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return ret;
    }

    return BOARD_SOK;

}
