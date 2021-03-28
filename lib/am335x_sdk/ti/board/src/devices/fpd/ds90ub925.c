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
 * \file   ds90ub925.c
 *
 * \brief  This file contains the API's for configuring the ds90ub925 serailizer.
 *
 */
#include "ds90ub925.h"

/**
 * \brief  RGB gate data enable mode control
 *
 *  This function is used for configuring the serializer
 *  RGB gate DE mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetRGBGateDEModeCtrl(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regAddr;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regAddr = BOARD_FPD_UB925_CONFIGURATION1_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB925_RGB_DE_GATE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB925_RGB_DE_GATE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB925_CONFIGURATION1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return BOARD_SOK;
}

/**
 * \brief  I2S channel-B mode control
 *
 *  This function is used for configuring the serializer
 *  I2S channel-B mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetI2SChBModeCtrl(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regAddr;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regAddr = BOARD_FPD_UB925_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB925_I2S_CHANNEL_B_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB925_I2S_CHANNEL_B_ENABLE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return BOARD_SOK;
}

/**
 * \brief  I2S channel-B override mode control
 *
 *  This function is used for configuring the serializer
 *  I2S channel-B override mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetI2SChBOverrideModeCtrl(void *handle,
                                                     Board_FpdModuleObj *fpdModParams,
                                                     uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regAddr;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regAddr = BOARD_FPD_UB925_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB925_I2S_CHANNEL_B_OVERRIDE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB925_I2S_CHANNEL_B_OVERRIDE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return BOARD_SOK;
}

/**
 * \brief  I2S transport select mode control
 *
 *  This function is used for configuring the serializer
 *  I2S transport select mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetI2STransSelModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regAddr;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regAddr = BOARD_FPD_UB925_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB925_I2S_TRANSPOER_SEL_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB925_I2S_TRANSPOER_SEL_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return BOARD_SOK;
}

/**
 * \brief  RGB 18-bit mode control
 *
 *  This function is used for configuring the serializer
 *  RGB 18-bit mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetRGB18bitModeCtrl(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regAddr;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regAddr = BOARD_FPD_UB925_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB925_RGB_18BIT_MODE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB925_RGB_18BIT_MODE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return BOARD_SOK;
}

/**
 * \brief  Get PCLK lock status
 *
 * This function is used for reading the serializer PCLK
 * lock status
 *
 * \param   handle        [IN]       Low level driver handle
 * \param   fpdModParams  [IN]       FPD module params
 * \param   pllLockStatus [IN/OUT]   Buffer to hold PLL lock status
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925GetPCLKLockStatus(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            bool *pclkLockStatus)
{
    Board_STATUS ret;
    uint8_t regAddr;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regAddr = BOARD_FPD_UB925_GENERAL_STATUS_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if(regData & BOARD_FPD_UB925_PCLK_STATUS_BIT_MASK)
    {
        *pclkLockStatus = 1;
    }
    else
    {
        *pclkLockStatus = 0;
    }
    BOARD_DEVICES_STS_LOG("FPD Serializer Lock status : 0x%x\n", regData);
    
    return BOARD_SOK;
}

