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
 *   \file    ds90ub924.c
 *
 *      This file contains the default API's for initializing the
 *      FPD module for the communicating with the remote slave device.
 *
 */

#include "ds90ub924.h"

/**
 *  \brief    DSI Reset1 mode control
 *
 * This function is used for configuring the operational
 * mode of Digital RESET1.
 *
 *  \param    handle             I2C Handle
 *  \param    fpdModParams       FPD module params
 *  \param    operMode           Operational mode to be configured
 *                                 NORMAL_OPERATION - Normal Mode
 *                                 RESET            - Reset Mode
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SelDesDigialRst1Mode(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t operMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_RESET_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_DIGITAL_RST1_BIT_MASK);
    regData |= (operMode << BOARD_FPD_UB924_DIGITAL_RST1_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_RESET_REG_ADDR,
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
 *  \brief    DSI Reset0 mode control
 *
 *  This function is used for configuring the operational
 *  mode of Digital RESET0.
 *
 *  \param    handle                     I2C Handle
 *  \param    fpdModParams               FPD module params
 *  \param    operMode                   Operational mode to be configured
 *                                           NORMAL_OPERATION - Normal Mode
 *                                           RESET            - Reset Mode.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SelDesDigialRst0Mode(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t operMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_RESET_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_DIGITAL_RST0_BIT_MASK);
    regData |= (operMode << BOARD_FPD_UB924_DIGITAL_RST0_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_RESET_REG_ADDR,
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
 *  \brief    DSI Back channel mode control
 *
 *  This function is used for enabling/disabling back channel
 *  enable mode.
 *
 *  \param    handle                     I2C Handle
 *  \param    fpdModParams               FPD module params
 *  \param    cfgMode                    Mode to be configured
 *                                           DISABLE - Disabled back channel
 *                                           ENABLE  - Enables back channel
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SelDesBCEnMode(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_RESET_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_BC_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_BC_ENABLE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_RESET_REG_ADDR,
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
 *  \brief    Deserializer filter mode control
 *
 *  This function is used for enabling/disabling filter
 *  enable mode.
 *
 *  \param    handle                     I2C Handle
 *  \param    fpdModParams               FPD module params
 *  \param    cfgMode                    Mode to be configured
 *                                           DISABLE - Disabled back channel
 *                                           ENABLE  - Enables back channel
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SelDesFilterEnMode(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_FILTER_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_FILTER_ENABLE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
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
 *  \brief    I2C pass through mode control
 *
 *  This function is used for enabling/disabling i2c
 *  pass through enable mode.
 *
 *  \param    handle                     I2C Handle
 *  \param    fpdModParams               FPD module params
 *  \param    cfgMode                    Mode to be configured
 *                                           DISABLE - Disabled back channel
 *                                           ENABLE  - Enables back channel
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SetI2CPassThrModeCfg(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_I2C_PASS_THROUGH_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_I2C_PASS_THROUGH_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
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
 *  \brief    Deserializer auto acknowledge mode control
 *
 *  This function is used for enabling/disabling i2c
 *  auto acknowledge mode.
 *
 *  \param    handle                     I2C Handle
 *  \param    fpdModParams               FPD module params
 *  \param    cfgMode                    Mode to be configured
 *                                           DISABLE - Disabled back channel
 *                                           ENABLE  - Enables back channel
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SelDesAutoACKMode(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_AUTO_ACK_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_AUTO_ACK_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
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
 *  \brief    Deserializer DE gate RGB mode control
 *
 *  This function is used for enabling/disabling i2c
 *  DE Gate RGB mode.
 *
 *  \param    handle                     I2C Handle
 *  \param    fpdModParams               FPD module params
 *  \param    cfgMode                    Mode to be configured
 *                                           DISABLE - Disabled back channel
 *                                           ENABLE  - Enables back channel
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SelDesDEGateMode(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_DE_GATE_RGB_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_DE_GATE_RGB_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
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
 *  \brief    Deserializer pass through all mode control
 *
 *  This function is used for enabling/disabling i2c
 *  pass all mode.
 *
 *  \param    handle                     I2C Handle
 *  \param    fpdModParams               FPD module params
 *  \param    cfgMode                    Mode to be configured
 *                                           DISABLE - Disabled back channel
 *                                           ENABLE  - Enables back channel
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SelDesPassAllMode(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_I2C_CONTROL1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_I2C_PASS_ALL_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_I2C_PASS_ALL_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_I2C_CONTROL1_REG_ADDR,
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
 *  \brief    I2C device address read
 *
 *  This function is used to read the I2C device address
 *  of deserailizer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   *rdBuff       – Pointer to hold the 7–bit address
 *                          of deserializer.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924GetDesI2CAddr(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t *rdBuff)
{
    Board_STATUS ret = BOARD_SOK;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }


    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_I2C_DEVICE_ID_REG_ADDR,
                             rdBuff,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *rdBuff = (*rdBuff >> 1);

    return ret;
}

/**
 *  \brief    Auto clock mode control
 *
 *  This function is used for Auto clock enable mode.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   modeSel       – OSC Clock Output, Enables On loss of lock
 *                              DISABLE - Diasables the Auto-
 *                                        clock enable mode
 *                              ENABLE  - Enables the Auto-
 *                                        clock enable mode

 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesAutoClkEnMode(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t modeSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_AUTO_CLK_EN_BIT_MASK);
    regData |= (modeSel << BOARD_FPD_UB924_AUTO_CLK_EN_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    Backward override mode control
 *
 *  This function is used for configuring backwards
 *  compatibility override mode.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   modeSel       – Backwards Compatibility Mode Override    
 *                              DISABLE_OVERRIDE - Uses MODE_SEL pin
 *                              ENABLE_OVERRIDE  - Use register bit to
 *                                                 set BKWD mode.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesBKWDOvrMode(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t modeSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_BKWD_OVERRIDE_BIT_MASK);
    regData |= (modeSel << BOARD_FPD_UB924_BKWD_OVERRIDE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    Backward mode control
 *
 *  This function is used for configuring backwards
 *  compatibility mode.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   modeSel       – Backwards Compatibility Mode
 *                              DISABLE - Diasables the BKWD
 *                                        compatibility mode
 *                              ENABLE  - Enables the BKWD
 *                                        compatibility mode

 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesBKWDMode(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t modeSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_BKWD_MODE_BIT_MASK);
    regData |= (modeSel << BOARD_FPD_UB924_BKWD_MODE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    Low frequency override mode control
 *
 *  This function is used for configuring Low Frequency mode.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   modeSel       – Low Frequency Mode Override    
 *                              DISABLE_OVERRIDE - Uses MODE_SEL pin
 *                              ENABLE_OVERRIDE  - Use register bit to
 *                                                 set LF mode.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesLFMODEOvr(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t modeSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_LFMODE_OVERRIDE_BIT_MASK);
    regData |= (modeSel << BOARD_FPD_UB924_LFMODE_OVERRIDE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    Low frequency mode control
 *
 *  This function is used for configuring low frequency mode.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   modeSel       – Backwards Compatibility Mode Override    
 *                              DISABLE - 15MHz ≤ PCLK ≤ 96MHz
 *                              ENABLE  - 5MHz ≤ PCLK < 15MHz
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesLFMODE(void *handle,
                                        Board_FpdModuleObj *fpdModParams,
                                        uint8_t modeSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_LFMODE_BIT_MASK);
    regData |= (modeSel << BOARD_FPD_UB924_LFMODE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    Video color depth mode control
 *
 *  This function is used for configuring the video color depth mode.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   modeSel       – Color depth mode select
 *                              MODE_SEL_24 - 24-bit mode select
 *                              MODE_SEL_18 - 18-bit mode select
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesVidClrDepthMode(void *handle,
                                                 Board_FpdModuleObj *fpdModParams,
                                                 uint8_t modeSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regData = (1 << 7U);
    /* Disables auto loading of this register from the forward channel */
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_DATA_PATH_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_DATA_PATH_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_VID_BIT_MODE_SEL_BIT_MASK);
    regData |= (modeSel << BOARD_FPD_UB924_VID_BIT_MODE_SEL_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_DATA_PATH_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    Data enable polarity mode control
 *
 *  This function is used for configuring the Data Enable(DE) polarity.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   polSel        – DE Polarity select
 *                              DE_POSITIVE - active high, idle low
 *                              DE_INVERTED - active low, idle high
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesDEPolarity(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t polSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regData = (1 << 7U);
    /* Disables auto loading of this register from the forward channel */
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_DATA_PATH_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_DATA_PATH_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_DE_POLARITY_BIT_MASK);
    regData |= (polSel << BOARD_FPD_UB924_DE_POLARITY_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_DATA_PATH_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    I2C bus frequency mode control
 *
 *  This function is used to the I2C Bus frequency
 *  of FPD LinkIII interface with the user selected
 *  frequency.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   cfgBitRate    – enum variable for selecting different 
 *                          frequencies to be configured.
 *                          KBPS_100   - Net Bit Rate:- 100Kbps
 *                          KBPS_400   - Net Bit Rate:- 400Kbps
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SetDesI2cBusFreq(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t cfgBitRate)
{
    Board_STATUS ret = BOARD_SOK;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }


    /* Configures the I2C Bit rate to 400kbit/sec */
    /* Configures the SCL High time */
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_SCL_HIGH_TIME_REG_ADDR,
                             &cfgBitRate,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Configures the SCL High time */
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_SCL_HIGH_TIME_REG_ADDR,
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
 *  \brief    Horizontal sync polarity mode control
 *
 *  This function is used for configuring the Horizontal Sync(HS)
 *  polarity.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   polSel        – Horizontal Sync Polarity select
 *                              ACTIVE_HIGH - active high, idle low
 *                              ACTIVE_LOW - active low, idle high
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesHSSyncPolarity(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t polSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_HS_POLARITY_BIT_MASK);
    regData |= (polSel << BOARD_FPD_UB924_HS_POLARITY_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    Vertical sync polarity mode control
 *
 *  This function is used for configuring the Vertical Sync(VS)
 *  polarity.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   polSel        – Vertical Sync Polarity select
 *                              ACTIVE_HIGH - active high, idle low
 *                              ACTIVE_LOW - active low, idle high
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesVSSyncPolarity(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t polSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_VS_POLARITY_BIT_MASK);
    regData |= (polSel << BOARD_FPD_UB924_VS_POLARITY_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    Data enable sync polarity mode control
 *
 *  This function is used for configuring the Data Enable Sync
 *  polarity.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   polSel        – Data Enable Sync Polarity select
 *                              ACTIVE_HIGH - active high, idle low
 *                              ACTIVE_LOW - active low, idle high
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesDESyncPolarity(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t polSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_DE_SYNC_POLARITY_BIT_MASK);
    regData |= (polSel << BOARD_FPD_UB924_DE_SYNC_POLARITY_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return ret;
}

/**
 *  \brief    FRC2 mode control
 *
 *  This function is used for enabling/disabling
 *  FRC2 mode of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   cfgMode       – FRC2 mode select
 *                             DISABLE - Disable FRC2
 *                             ENABLE  - Enable FRC2
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesFRC2Mode(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_FRC2_EN_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_FRC2_EN_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
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
 *  \brief    FRC1 mode control
 *
 *  This function is used for enabling/disabling
 *  FRC2 mode of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   cfgMode       – FRC1 mode select
 *                             DISABLE - Disable FRC1
 *                             ENABLE  - Enable FRC1
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesFRC1Mode(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_FRC1_EN_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_FRC1_EN_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
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
 *  \brief    Hi-FRC2 mode control
 *
 *  This function is used for enabling/disabling
 *  Hi-FRC2 mode of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   cfgMode       – Hi-FRC2 mode select
 *                             DISABLE - Disable HiFRC2
 *                             ENABLE  - Enable HiFRC2
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesHiFRC2Mode(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_HI_FRC2_EN_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_HI_FRC2_EN_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
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
 *  \brief    Hi-FRC1 mode control
 *
 *  This function is used for enabling/disabling
 *  Hi-FRC1 mode of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   cfgMode       – Hi-FRC1 mode select
 *                             DISABLE - Disable HiFRC1
 *                             ENABLE  - Enable HiFRC1
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesHiFRC1Mode(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t cfgMode)
{
   Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_HI_FRC1_EN_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_HI_FRC1_EN_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
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
 *  \brief    Pattern generator clock source mode control
 *
 *  This function is used for selecting the pattern generator
 *  clock source of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   clkSrc        – Clock source selection
 *                          EXT_CLK_SRC - External clk source
 *                          INT_CLK_SRC - Internal Clock source.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SetDesPGIntClkEn(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t clkSrc)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_INT_CLK_EN_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_PG_INT_CLK_EN_BIT_MASK);
    regData |= (clkSrc << BOARD_FPD_UB924_PG_INT_CLK_EN_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_INT_CLK_EN_REG_ADDR,
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
 *  \brief    LVDS Vod mode control
 *
 *  This function is used for configuring the LVDS Vod control
 *  of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   lvdsVod        – LVDS Vod config
 *                           MILLI_VOLT_400 - 400 milli volt
 *                           MILLI_VOLT_600 - 600 milli volt.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924DesLVDSDrvSetting(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t lvdsVod)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_LVDS_DRV_SETTING_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_LVDS_VOD_CNTRL_BIT_MASK);
    regData |= (lvdsVod << BOARD_FPD_UB924_LVDS_VOD_CNTRL_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_LVDS_DRV_SETTING_REG_ADDR,
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
 *  \brief    loop through driver mode control
 *
 *  This function is used for enabling/disabling the loop through
 *  driver of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   cfgMode       – Loop through driver mode select
 *                             ENABLE  - Loop through driver mode enable
 *                             DISABLE - Loop through driver mode disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924CfgDesLoopThrDrv(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_LOOP_THR_DRV_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_LOOP_THR_DRV_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_LOOP_THR_DRV_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_LOOP_THR_DRV_REG_ADDR,
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
 *  \brief    color bar pattern mode control
 *
 *  This function is used for enabling/disabling the color bar
 *  pattern mode of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   cfgMode       – Color bar pattern mode select
 *                             DISABLE - Color Bars disabled
 *                             ENABLE  - Color Bars enabled
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesClrBarPatMode(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_CLR_BAR_PAT_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_CLR_BAR_PAT_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CONTROL_REG_ADDR,
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
 *  \brief    Pattern generator mode control
 *
 *  This function is used for enabling/disabling the
 *  pattern generator mode of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   cfgMode       – Pattern Generator mode select
 *                             DISABLE - Pattern Generator disabled
 *                             ENABLE  - Pattern Generator enabled
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesPGMode(void *handle,
                                        Board_FpdModuleObj *fpdModParams,
                                        uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_PG_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_PG_ENABLE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CONTROL_REG_ADDR,
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
 *  \brief    pattern generator bit mode control
 *
 *  This function is used for cofiguring the
 *  pattern generator bit mode of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   cfgMode       – Pattern Generator mode select
 *                             MODE_SEL_24 - 24-Bit Mode
 *                             MODE_SEL_18 - 18-Bit Mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesPGBitMode(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CNFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_PG_BIT_MODE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_PG_BIT_MODE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CNFG_REG_ADDR,
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
 *  \brief    pattern generator external clock mode control
 *
 *  This function is used for selecting the pattern
 *  generator External clock source of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   clkSrc        – Clock source used
 *                             INT_CLK_SRC - Internal divider clock
 *                             EXT_CLK_SRC - External pixel clock
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesPGExtClk(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t clkSrc)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CNFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_EXT_CLK_BIT_MASK);
    regData |= (clkSrc << BOARD_FPD_UB924_EXT_CLK_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CNFG_REG_ADDR,
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
 *  \brief    pattern generator timing mode control
 *
 *  This function is used for selecting the pattern
 *  generator timing of a deserializer.
 *
 *  \param   handle        - pointer to the i2c handle
 *  \param   fpdModParams  - FPD module params
 *  \param   vidTmng       – Video timing used
 *                             EXT_VIDEO_TIMING - Uses external video timing
 *                             OWN_VIDEO_TIMING - Creates its own video timing
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb924SelDesPGTmngSel(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t vidTmng)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CNFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_TIMING_SEL_BIT_MASK);
    regData |= (vidTmng << BOARD_FPD_UB924_TIMING_SEL_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CNFG_REG_ADDR,
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
 * \brief Receive CRC checker enable
 *
 * This function is used to enable/disable CRC Checker.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SetRxCRCCheckerEn(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_RX_CRC_CHECKER_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB924_RX_CRC_CHECKER_ENABLE_SHIFT_CNT);
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
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
 * \brief  configure auto scroll for pattern
 *
 * This function is used to enable/disable pass through mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924SetAutoScrollPattEn(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CNFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB924_AUTO_SCROLL_PATTERN_BIT_MASK);
    regData |= cfgMode;
    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serDesAliasAddr,
                             BOARD_FPD_UB924_PG_CNFG_REG_ADDR,
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
 *  \brief    DSI GPIO mode control
 *
 * This function is used for configuring the GPIO0 output value.
 *
 *  \param    handle             I2C Handle
 *  \param    fpdModParams       FPD module params
 *  \param    gpioSel            select GPIO to be configured
 *                                 -BOARD_FPD_UB924_GPIO0
 *                                 -BOARD_FPD_UB924_GPIO1
 *                                 -BOARD_FPD_UB924_GPIO2
 *                                 -BOARD_FPD_UB924_GPIO3
 *                                 -BOARD_FPD_UB924_GPIO5
 *                                 -BOARD_FPD_UB924_GPIO6
 *                                 -BOARD_FPD_UB924_GPIO7
 *                                 -BOARD_FPD_UB924_GPIO8
 *  \param    outSel             Operational mode to be configured
 *                                 BOARD_FPD_UB924_OUTPUT_HIGH - active high
 *                                 BOARD_FPD_UB924_OUTPUT_LOW - active low
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924GpioOutputMode(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t gpioSel,
                                          uint8_t outSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0, regAddr = 0, mask = 0, cnt = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    switch(gpioSel)
    {
        case BOARD_FPD_UB924_GPIO0:
             regAddr = BOARD_FPD_UB924_GPIO0_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO0_OUTPUT_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO0_OUTPUT_SHIFT_CNT;
             break;
            
        case BOARD_FPD_UB924_GPIO1:
             regAddr = BOARD_FPD_UB924_GPIO1_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO1_OUTPUT_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO1_OUTPUT_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO2:
             regAddr = BOARD_FPD_UB924_GPIO2_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO2_OUTPUT_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO2_OUTPUT_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO3:
             regAddr = BOARD_FPD_UB924_GPIO3_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO3_OUTPUT_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO3_OUTPUT_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO8:
             regAddr = BOARD_FPD_UB924_GPIO8_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO8_OUTPUT_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO8_OUTPUT_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO5:
             regAddr = BOARD_FPD_UB924_GPIO5_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO5_OUTPUT_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO5_OUTPUT_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO6:
             regAddr = BOARD_FPD_UB924_GPIO6_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO6_OUTPUT_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO6_OUTPUT_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO7:
             regAddr = BOARD_FPD_UB924_GPIO7_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO7_OUTPUT_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO7_OUTPUT_SHIFT_CNT;
             break;
        default:
             ret = BOARD_INVALID_PARAM;
             break;
    }

    if(ret != BOARD_SOK)
    {
        return ret;
    }

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

    regData &= ~(mask);
    regData |= (outSel << cnt);
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
 *  \brief    DSI GPIO Remote mode control
 *
 * This function is used for configuring the GPIO0 remote value.
 *
 *  \param    handle             I2C Handle
 *  \param    fpdModParams       FPD module params
 *  \param    gpioSel            select GPIO to be configured
 *                                 -BOARD_FPD_UB924_GPIO0
 *                                 -BOARD_FPD_UB924_GPIO1
 *                                 -BOARD_FPD_UB924_GPIO2
 *                                 -BOARD_FPD_UB924_GPIO3
 *                                 -BOARD_FPD_UB924_GPIO5
 *                                 -BOARD_FPD_UB924_GPIO6
 *                                 -BOARD_FPD_UB924_GPIO7
 *                                 -BOARD_FPD_UB924_GPIO8
 *  \param    modeSel             Operational mode to be configured
 *                                 BOARD_FPD_MODE_ENABLE
 *                                 BOARD_FPD_MODE_DISABLE
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924GpioRemoteMode(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t gpioSel,
                                          uint8_t modeSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0, regAddr = 0, mask = 0, cnt = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    switch(gpioSel)
    {
        case BOARD_FPD_UB924_GPIO0:
        {
            regAddr = BOARD_FPD_UB924_GPIO0_CFG_REG_ADDR;
            mask = BOARD_FPD_UB924_GPIO0_REMOTE_BIT_MASK;
            cnt = BOARD_FPD_UB924_GPIO0_REMOTE_SHIFT_CNT;
            break;
            
        }
        case BOARD_FPD_UB924_GPIO1:
        {
            regAddr = BOARD_FPD_UB924_GPIO1_CFG_REG_ADDR;
            mask = BOARD_FPD_UB924_GPIO1_REMOTE_BIT_MASK;
            cnt = BOARD_FPD_UB924_GPIO1_REMOTE_SHIFT_CNT;
            break;
        }
        case BOARD_FPD_UB924_GPIO2:
        {
            regAddr = BOARD_FPD_UB924_GPIO2_CFG_REG_ADDR;
            mask = BOARD_FPD_UB924_GPIO2_REMOTE_BIT_MASK;
            cnt = BOARD_FPD_UB924_GPIO2_REMOTE_SHIFT_CNT;
            break;
        }
        case BOARD_FPD_UB924_GPIO3:
        {
            regAddr = BOARD_FPD_UB924_GPIO3_CFG_REG_ADDR;
            mask = BOARD_FPD_UB924_GPIO3_REMOTE_BIT_MASK;
            cnt = BOARD_FPD_UB924_GPIO3_REMOTE_SHIFT_CNT;
            break;
        }
        default:
             ret = BOARD_INVALID_PARAM;
             break;
    }

    if(ret != BOARD_SOK)
    {
        return ret;
    }

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

    regData &= ~(mask);
    regData |= (modeSel << cnt);
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
 *  \brief    DSI GPIO Direction mode control
 *
 * This function is used for configuring the GPIO0 Direction value.
 *
 *  \param    handle             I2C Handle
 *  \param    fpdModParams       FPD module params
 *  \param    gpioSel            select GPIO to be configured
 *                                 -BOARD_FPD_UB924_GPIO0
 *                                 -BOARD_FPD_UB924_GPIO1
 *                                 -BOARD_FPD_UB924_GPIO2
 *                                 -BOARD_FPD_UB924_GPIO3
 *                                 -BOARD_FPD_UB924_GPIO5
 *                                 -BOARD_FPD_UB924_GPIO6
 *                                 -BOARD_FPD_UB924_GPIO7
 *                                 -BOARD_FPD_UB924_GPIO8
 *  \param    modeSel             Operational mode to be configured
 *                                 BOARD_FPD_UB924_OUTPUT
 *                                 BOARD_FPD_UB924_INPUT
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924GpioDirectionMode(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t gpioSel,
                                             uint8_t modeSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0, regAddr = 0, mask = 0, cnt = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    switch(gpioSel)
    {
        case BOARD_FPD_UB924_GPIO0:
             regAddr = BOARD_FPD_UB924_GPIO0_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO0_DIRECTION_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO0_DIRECTION_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO1:
             regAddr = BOARD_FPD_UB924_GPIO1_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO1_DIRECTION_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO1_DIRECTION_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO2:
             regAddr = BOARD_FPD_UB924_GPIO2_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO2_DIRECTION_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO2_DIRECTION_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO3:
             regAddr = BOARD_FPD_UB924_GPIO3_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO3_DIRECTION_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO3_DIRECTION_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO8:
             regAddr = BOARD_FPD_UB924_GPIO8_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO8_DIRECTION_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO8_DIRECTION_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO5:
             regAddr = BOARD_FPD_UB924_GPIO5_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO5_DIRECTION_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO5_DIRECTION_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO6:
             regAddr = BOARD_FPD_UB924_GPIO6_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO6_DIRECTION_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO6_DIRECTION_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO7:
             regAddr = BOARD_FPD_UB924_GPIO7_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO7_DIRECTION_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO7_DIRECTION_SHIFT_CNT;
             break;
        default:
             ret = BOARD_INVALID_PARAM;
             break;
    }

    if(ret != BOARD_SOK)
    {
        return ret;
    }

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

    regData &= ~(mask);
    regData |= (modeSel << cnt);
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
 *  \brief    DSI GPIO Enable mode control
 *
 * This function is used for configuring the GPIO0 Enable value.
 *
 *  \param    handle             I2C Handle
 *  \param    fpdModParams       FPD module params
 *  \param    gpioSel            select GPIO to be configured
 *                                 -BOARD_FPD_UB924_GPIO0
 *                                 -BOARD_FPD_UB924_GPIO1
 *                                 -BOARD_FPD_UB924_GPIO2
 *                                 -BOARD_FPD_UB924_GPIO3
 *                                 -BOARD_FPD_UB924_GPIO5
 *                                 -BOARD_FPD_UB924_GPIO6
 *                                 -BOARD_FPD_UB924_GPIO7
 *                                 -BOARD_FPD_UB924_GPIO8
 *  \param    modeSel             Operational mode to be configured
 *                                 BOARD_FPD_MODE_NORMAL
 *                                 BOARD_FPD_UB924_GPIO
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924GpioEnMode(void *handle,
                                      Board_FpdModuleObj *fpdModParams,
                                      uint8_t gpioSel,
                                      uint8_t modeSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0, regAddr = 0, mask = 0, cnt = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    switch(gpioSel)
    {
        case BOARD_FPD_UB924_GPIO0:
             regAddr = BOARD_FPD_UB924_GPIO0_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO0_ENABLE_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO0_ENABLE_SHIFT_CNT;
             break;
            
        case BOARD_FPD_UB924_GPIO1:
             regAddr = BOARD_FPD_UB924_GPIO1_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO1_ENABLE_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO1_ENABLE_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO2:
             regAddr = BOARD_FPD_UB924_GPIO2_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO2_ENABLE_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO2_ENABLE_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO3:
             regAddr = BOARD_FPD_UB924_GPIO3_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO3_ENABLE_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO3_ENABLE_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO8:
             regAddr = BOARD_FPD_UB924_GPIO8_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO8_ENABLE_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO8_ENABLE_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO5:
             regAddr = BOARD_FPD_UB924_GPIO5_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO5_ENABLE_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO5_ENABLE_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO6:
             regAddr = BOARD_FPD_UB924_GPIO6_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO6_ENABLE_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO6_ENABLE_SHIFT_CNT;
             break;
        case BOARD_FPD_UB924_GPIO7:
             regAddr = BOARD_FPD_UB924_GPIO7_CFG_REG_ADDR;
             mask = BOARD_FPD_UB924_GPIO7_ENABLE_BIT_MASK;
             cnt = BOARD_FPD_UB924_GPIO7_ENABLE_SHIFT_CNT;
             break;
        default:
             ret = BOARD_INVALID_PARAM;
             break;
    }

    if(ret != BOARD_SOK)
    {
        return ret;
    }

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

    regData &= ~(mask);
    regData |= (modeSel << cnt);
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
