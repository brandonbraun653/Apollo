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
 * \file  ds90ub926.c
 *
 * \brief This file contains the API's for configuring the ds90ub926 deserailizer.
 *
 */
#include "ds90ub926.h"

/**
 * \brief  I2S channel-B enable mode control
 *
 *  This function is used for configuring the deserializer
 *  I2S Channel-B mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2SChBEnableModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB926_I2S_CHANNEL_B_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_I2S_CHANNEL_B_ENABLE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * This function is used for configuring the deserializer
 * I2S Channel-B override mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2SChBOverrideModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB926_I2S_CHANNEL_B_OVERRIDE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_I2S_CHANNEL_B_OVERRIDE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * \brief  I2S Transport select mode control
 *
 * This function is used for configuring the deserializer I2S transport
 * select mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2STransportSelModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB926_I2S_TRANSPOER_SEL_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_I2S_TRANSPOER_SEL_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * \brief  I2S generation mode control
 *
 * This function is used for configuring the deserializer I2S generation mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2SGenModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB926_I2S_GEN_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_I2S_GEN_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * \brief  Pass RGB mode control
 *
 * This function is used for configuring the deserializer RGB pass mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetPassRGBModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB926_PASS_RGB_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_PASS_RGB_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * \brief  Override forward channel configuation mode control
 *
 * This function is used for configuring the deserializer override
 * forward channel mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetOverrideFCConfigModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB926_OVERRIDE_FC_CONFIG_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_OVERRIDE_FC_CONFIG_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * This function is used for configuring the deserializer RGB
 * 18-bit mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetRGB18bitModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_DATA_PATH_CONTROL_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB926_RGB_18BIT_MODE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_RGB_18BIT_MODE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * \brief  Get PLL lock status
 *
 * This function is used for reading the deserializer PLL
 * lock status
 *
 * \param   handle        [IN]       Low level driver handle
 * \param   fpdModParams  [IN]       FPD module params
 * \param   pllLockStatus [IN/OUT]   Buffer to hold PLL lock status
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926GetPLLLockStatus(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            bool *pllLockStatus)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regAddr;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regAddr = BOARD_FPD_UB926_GENERAL_STATUS_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if(regData & BOARD_FPD_UB926_I2S_PLL_LOCK_STATUS_BIT_MASK)
    {
        *pllLockStatus = 1;
    }
    else
    {
        *pllLockStatus = 0;
    }
    BOARD_DEVICES_STS_LOG("FPD Deserializer Lock status : 0x%x\n", regData);
    
    return BOARD_SOK;
}

/**
 * \brief  Remote serializer slave device id config
 *
 * This function is used for configuring the remote serializer slave device ID
 *
 * \param   handle       [IN] Low level driver handle
 * \param   fpdModParams [IN] FPD module params
 * @param   fpdRmtParams [IN] structure holding the fpd params
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926RmtSerSlvDevAliasIdCfg(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  Board_FpdRmtDevObj *fpdRmtParams)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t slvIdReg;
    uint8_t slvAliasIdReg;
    uint8_t regData;
    uint8_t index = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    slvIdReg = BOARD_FPD_UB926_SLAVE_ID0_REG_ADDR;
    slvAliasIdReg = BOARD_FPD_UB926_SLAVE_ALIAS0_REG_ADDR;

    while((fpdRmtParams[index].i2cDevAddr != 0) && (index < BOARD_FPD_MAX_REMOTE_SENSOR_DEVICES))
    {
        regData = ((uint8_t)(fpdRmtParams[index].i2cDevAddr) << 1);
        ret = Board_i2c8BitRegWr(handle,
                                 fpdModParams->desSlvAddr,
                                 slvIdReg,
                                 &regData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);

        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = ((uint8_t)(fpdRmtParams[index].i2cDevAliasAddr) << 1);
        ret = Board_i2c8BitRegWr(handle,
                                 fpdModParams->desSlvAddr,
                                 slvAliasIdReg,
                                 &regData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);

        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
        slvIdReg++;
        slvAliasIdReg++;
        index++;
    }

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return BOARD_SOK;
}

/**
 * \brief  I2C pass through all mode control
 *
 * This function is used for configuring the deserializer
 * I2C pass through all mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2CPassThrAllModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_I2C_CONTROL1_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Configures the user specified i2c pass through all mode */
    regData &= ~(BOARD_FPD_UB926_I2C_PASS_THROUGH_ALL_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_I2C_PASS_THROUGH_ALL_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * \brief  I2C pass through mode control
 *
 * This function is used for configuring the deserializer
 * I2C pass through mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2CPassThrModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_CONFIGURATION1_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Configures the user specified i2c pass through mode */
    regData &= ~(BOARD_FPD_UB926_I2C_PASS_THROUGH_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_I2C_PASS_THROUGH_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * \brief  I2C bus frequency set
 *
 * This function is used for setting the deserializer I2C bus frequency
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgBitRate    [IN]   Indicates I2C serial clock frequency
 *                               config modes
 *                               BOARD_FPD_KBPS_100 - 100 KBPS
 *                               BOARD_FPD_KBPS_400 - 400 KBPS
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2CBusFreq(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t cfgBitRate)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regAddr;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regAddr = BOARD_FPD_UB926_SCL_HIGH_TIME_REG_ADDR;
    /* Configures the I2C Bit rate to 400kbit/sec */
    /* Configures the SCL High time */
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &cfgBitRate,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regAddr = BOARD_FPD_UB926_SCL_LOW_TIME_REG_ADDR;
    /* Configures the SCL High time */
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &cfgBitRate,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }
    
    return BOARD_SOK;
}

/**
 * \brief  Deserializer back channel mode control
 *
 * This function is used for configuring the deserializer back channel mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetBackChModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_RESET_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Reset digital RESET1, resets the entire digital block
       including registers */
    regData &= ~(BOARD_FPD_UB926_BC_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_BC_ENABLE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * \brief  Deserializer digital reset1 mode control
 *
 * This function is used for configuring the deserializer digital reset1 mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetDigitalRst1ModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_RESET_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Reset digital RESET1, resets the entire digital block
       including registers */
    regData &= ~(BOARD_FPD_UB926_DIGITAL_RESET1_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_DIGITAL_RESET1_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
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
 * \brief  Remote auto-power down mode control
 *
 * This function is used for configuring the deserializer auto power down mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetRmtAutoPwrDwnModeCtrl(void *handle,
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

    regAddr = BOARD_FPD_UB926_RESET_REG_ADDR;
    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Auto power down read failed\n\r");
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Configures the user specified auto power down mode,
       i.e; either enable or disable */
    regData &= ~(BOARD_FPD_UB926_REMOTE_AUTO_PWR_DWN_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB926_REMOTE_AUTO_PWR_DWN_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->desSlvAddr,
                             regAddr,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);

    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Auto power down write failed\n\r");
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return BOARD_SOK;
}

/**
 * \brief  Get ub926 i2c address.
 *
 * This function is used to get the I2C address and
 * channel details of UB926 module.
 *
 * \param   domain    [IN]  I2C instance domain
 * \param   chNum     [IN]  buffer to hold i2c channel number
 * \param   i2cAddr   [IN]  buffer to hold i2c address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
void Board_fpdUb926GetI2CAddr(uint8_t *domain,
                              uint8_t *chNum,
                              uint8_t *i2cAddr)
{
    *domain = BOARD_SOC_DOMAIN_MAIN;
    *chNum = 3U;
    *i2cAddr = 0x2C;
}

