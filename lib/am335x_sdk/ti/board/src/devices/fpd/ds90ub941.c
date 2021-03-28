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
 * \file    ds90ub941.c
 *
 * This file contains the default API's for initializing the
 * FPD module for the communicating with the remote slave device.
 *
 */

#include "ds90ub941.h"

/**
 * \brief  DSI Reset mode control
 *
 * This function is used for configuring the analog (or)
 * digital DSI reset mode.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Normal operation (or) Reset
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetResetModeCtrl(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_RESET_CTL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DISABLE_DSI_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_DISABLE_DSI_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_RESET_CTL_REG_ADDR,
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
 * \brief Digital reset1 mode control
 *
 * This function is used for configuring the operational
 * mode of Digital RESET1.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Normal operation (or) Reset
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDigtialRst1ModeCtrl(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_RESET_CTL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DIGITAL_RESET1_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_DIGITAL_RESET1_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_RESET_CTL_REG_ADDR,
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
 * \brief Digital reset0 mode control
 *
 * This function is used for configuring the operational
 * mode of Digital RESET0.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Normal operation (or) Reset
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDigtialRst0ModeCtrl(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_RESET_CTL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DIGITAL_RESET0_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_DIGITAL_RESET0_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_RESET_CTL_REG_ADDR,
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
 * \brief DSI1 clock lane pin order select
 *
 * This function is used to select the DSI1 clock lane pin order.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   Operational mode to be configured
 *                               BOARD_FPD_UB941_CLK_LANE_PN_MAINTIAN - DSI Port1
 *                               Clock Lane P inputs mapped to P, N inputs
 *                               mapped to N
 *                               BOARD_FPD_UB941_CLK_LANE_PN_SWAP - DSI Port1
 *                               Clock Lane P inputs mapped to P, N inputs
 *                               mapped to P
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDsi1ClkPinOrd(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DSI1_CLK_PN_SWAP_BIT_MASK);
    regData |= (operMode << BOARD_FPD_UB941_DSI1_CLK_PN_SWAP_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR,
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
 * \brief DSI1 data lane pin order select
 *
 * This function is used to select the DSI1 data lane pin order.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   Operational mode to be configured
 *                               BOARD_FPD_UB941_DATA_LANE_PN_MAINTIAN - DSI Port1
 *                               Data Lane P inputs mapped to P, N
 *                               input smapped to N
 *                               BOARD_FPD_UB941_DATA_LANE_PN_SWAP     - DSI Port1
 *                               Data Lane P inputs mapped to P, N
 *                               inputs mapped to P
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelDsi1DataPinOrd(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DSI1_DATA_PN_SWAP_BIT_MASK);
    regData |= (operMode << BOARD_FPD_UB941_DSI1_DATA_PN_SWAP_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR,
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
 * \brief DSI0 clock lane pin order select
 *
 * This function is used to select the DSI0 clock lane pin order.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   Operational mode to be configured
 *                               BOARD_FPD_UB941_CLK_LANE_PN_MAINTIAN - DSI Port0
 *                               Clock Lane P inputs mapped to P, N inputs
 *                               mapped to N
 *                               BOARD_FPD_UB941_CLK_LANE_PN_SWAP - DSI Port0
 *                               Clock Lane P inputs mapped to P, N inputs
 *                               mapped to P
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelDsi0ClkPinOrd(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DSI0_CLK_PN_SWAP_BIT_MASK);
    regData |= (operMode << BOARD_FPD_UB941_DSI0_CLK_PN_SWAP_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR,
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
 * \brief DSI0 data lane pin order select
 *
 * This function is used to select the DSI0 data lane pin order.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   Operational mode to be configured
 *                               BOARD_FPD_UB941_DATA_LANE_PN_MAINTIAN - DSI Port0
 *                               Data Lane P inputs mapped to P, N
 *                               input smapped to N
 *                               BOARD_FPD_UB941_DATA_LANE_PN_SWAP     - DSI Port0
 *                               Data Lane P inputs mapped to P, N
 *                               inputs mapped to P
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelDsi0DataPinOrd(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DSI0_DATA_PN_SWAP_BIT_MASK);
    regData |= (operMode << BOARD_FPD_UB941_DSI0_DATA_PN_SWAP_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR,
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
 * \brief Set deserializer device Id
 *
 * This function is used for setting the user configurable
 * device ID for remote deserializer connected to serializer.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   serSlvAddr    [IN]   Deserailizer device ID.
 *
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941DevIdCfg(void *handle,
                                    Board_FpdModuleObj *fpdModParams,
                                    uint8_t serSlvAddr)
{
    Board_STATUS ret = BOARD_SOK;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }


    serSlvAddr = ((serSlvAddr << 1) | BOARD_FPD_UB941_FREEZE_DEV_ID_BIT_MASK);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DES_ID_REG_ADDR,
                             &serSlvAddr,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return BOARD_SOK;

}

/**
 * \brief Get DSI general error status
 *
 * This function is used to read the general status of different err fileds.
 *
 * \param   handle         [IN]      Low level driver handle
 * \param   fpdModParams   [IN]      FPD module params
 * \param   errStatus      [IN/OUT]  Buffer to hold the error status
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetDsiGenSts(void *handle,
                                        Board_FpdModuleObj *fpdModParams,
                                        uint8_t *errStatus)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t rdData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_GENERAL_STS_REG_ADDR,
                             &rdData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *errStatus = rdData;
    BOARD_DEVICES_STS_LOG("errStatus = %d\n\r",errStatus);

    return BOARD_SOK;

}

/**
 * \brief I2C pass all mode control
 *
 * This function is used to Enable/Disable the I2C Pass All mode.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetI2CPassAllModeCtrl(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_I2C_CONTROL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_I2C_PASS_ALL_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_I2C_PASS_ALL_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_I2C_CONTROL_REG_ADDR,
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
 * \brief Select I2C Access port
 *
 * This function is used to selects Port for register access from
 * primary I2C address
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   portSel       [IN]   Port to be selected
 *                               BOARD_FPD_UB941_PORT0_SEL    - Port0 selected
 *                               BOARD_FPD_UB941_PORT1_SEL    - Port1 selected
 *                               BOARD_FPD_UB941_PORT1_I2C_EN - Enables the secondary
 *                               I2C address
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelI2CAccessPort(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t portSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_TX_PORT_SEL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_I2C_ACCESS_PORT_MASK);
    regData |= portSel;


    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_TX_PORT_SEL_REG_ADDR,
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
 * \brief Indirect register acces block select
 *
 * This function is used to select indirect register access block.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   regBlk        [IN]   Register block to be selected
 *                               BOARD_FPD_UB941_DSI_PORT0_REG
 *                                    - DSI/D-PHY Port 0 Digital Registers
 *
 *                               BOARD_FPD_UB941_DSI_PORT1_REG
 *                                    - DSI/D-PHY Port 1 Digital Registers
 *
 *                               BOARD_FPD_UB941_DSI_ANALOG_PLL_CNTRL_REG     
 *                                    - DSI Analog and PLL Control Registers
 *
 *                               BOARD_FPD_UB941_FPD_LINK_III_PORT0_REG       
 *                                    - FPD-Link III TX Port 0 Registers
 *
 *                               BOARD_FPD_UB941_FPD_LINK_III_PORT1_REG       
 *                                    - FPD-Link III TX Port 1 Registers
 *
 *                               BOARD_FPD_UB941_FPD_LINK_III_PORT0_PORT1_REG 
 *                                    - Simultaneous access to FPD-Link III
 *                                      TX Port 0/1 Registers
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941IndirRegAccBlkSel(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t regBlk)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_IND_ACC_CTL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_IND_ACC_SEL_BIT_MASK);
    regData |= (regBlk << BOARD_FPD_UB941_IND_ACC_SEL_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_IND_ACC_CTL_REG_ADDR,
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
 * \brief Indirect register access mode select
 *
 * This function is used to select indirect register access mode.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   accessMode    [IN]   Indirect access mode to be selected.
 *                               READ_ACCESS  - Read Access selected
 *                               WRITE_ACCESS - Write Access selected.
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941InDirRegAccModeSel(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t accessMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_IND_ACC_CTL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_IND_ACC_READ_BIT_MASK);
    regData |= (accessMode << BOARD_FPD_UB941_IND_ACC_READ_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_IND_ACC_CTL_REG_ADDR,
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
Board_STATUS Board_fpdUb941SetRxCRCCheckerEn(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_RX_CRC_CHECKER_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_RX_CRC_CHECKER_ENABLE_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR,
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
 * \brief Set filter enable
 *
 * This function is used to enable/disable filter.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetFilterEn(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_FILTER_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_FILTER_ENABLE_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR,
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
 * \brief  configure I2C pass through mode
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
Board_STATUS Board_fpdUb941SetI2CPassThrModeCfg(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_I2C_PASS_THROUGH_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_I2C_PASS_THROUGH_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR,
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
 * \brief  configure PCLK auto enable mode
 *
 * This function is used to enable/disable PCLK AUTO mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetPCLKAutoEnModeCfg(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_PCLK_AUTO_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_PCLK_AUTO_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR,
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
 * \brief  DSI indirect register write
 *
 * This function is used to write to the DSI indirect registers
 *
 * \param  handle        [IN]  Low level driver handle
 * \param  fpdModParams  [IN]   FPD module params
 * \param  regBlkType    [IN]  Indirect register block type
 *                             BOARD_FPD_UB941_DSI_PORT_INDIRECT_ACCESS
 *                                 - To enable DSI port register access
 *                             PATTERN_GEN_INDIRECT_ACESS
 *                                 - To enable Pattern Gen register access
 * \param  cfgRegAddr   [IN]   Register address to be accessed 
 * \param  cfgRegData   [IN]   Register data to be programmed
 *
 * \return Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941DsiIndirRegWr(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t regBlkType,
                                         uint8_t cfgRegAddr,
                                         uint8_t cfgRegData)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t addrReg;
    uint8_t dataReg;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }


    if(regBlkType == BOARD_FPD_UB941_DSI_PORT_INDIRECT_ACCESS)
    {
        addrReg = BOARD_FPD_UB941_IND_ACC_ADDR_REG_ADDR;
        dataReg = BOARD_FPD_UB941_IND_ADD_DATA_REG_ADDR;
    }
    else if(regBlkType == BOARD_FPD_UB941_PATTERN_GEN_INDIRECT_ACESS)
    {
        addrReg = BOARD_FPD_UB941_PGIA_PGIA_P1_REG_ADDR;
        dataReg = BOARD_FPD_UB941_PGID_PGID_P1_REG_ADDR;
    }
    else
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             addrReg,
                             &cfgRegAddr,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             dataReg,
                             &cfgRegData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }
    
    return BOARD_SOK;

}

/**
 * \brief  Set DSI bytes per pixel
 *
 * This function is used to configure the DSI bytes per pixel
 *
 * \param  handle          [IN]  Low level driver handle
 * \param  fpdModParams    [IN]   FPD module params
 * \param  bytesPerPixel   [IN]  Number of DSI Bytes Per Pixel
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetPixelBytes(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t bytesPerPixel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_BRIDGE_CFG_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DSI_BYTES_PER_PIXEL_BIT_MASK);
    regData |= (bytesPerPixel << BOARD_FPD_UB941_DSI_BYTES_PER_PIXEL_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_BRIDGE_CFG_REG_ADDR,
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
 * \brief  Set frequency stability threshold
 *
 * This function is used to configure the frequency stability threshold
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   freqStblThr   [IN]   Frequency Stability Threshold
 *                               BOARD_FPD_UB941_FREQ_STBL_40   - 40 micro sec
 *                               BOARD_FPD_UB941_FREQ_STBL_80   - 80 micro sec
 *                               BOARD_FPD_UB941_FREQ_STBL_320  - 320 micro sec
 *                               BOARD_FPD_UB941_FREQ_STBL_1280 - 1280 micro sec
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetFreqStblThr(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t freqStblThr)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DUAL_CTL2_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_FREQ_STBL_THR_BIT_MASK);
    regData |= (freqStblThr << BOARD_FPD_UB941_FREQ_STBL_THR_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DUAL_CTL2_REG_ADDR,
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
 * \brief  Get FPD Link-III link ready status
 *
 * This function is used to get the FPD Link-III ready status
 *
 * \param  handle        [IN]      Low level driver handle
 * \param  fpdModParams  [IN]      FPD module params
 * \param  stsFlag       [IN/OUT]  FPD LinkIII ready status
 *                                 False - FPD Link III module ready
 *                                 True  - FPD Link III module not ready
 *
 * \return Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetFpd3LinkRdySts(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             bool *stsFlag)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DUAL_STS_DUAL_STS_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *stsFlag = (((regData & BOARD_FPD_UB941_FPD3_LINK_RDY_BIT_MASK) >> BOARD_FPD_UB941_FPD3_LINK_RDY_SHIFT_CNT) == 1) ?  true : false;
    BOARD_DEVICES_STS_LOG("stsFlag = %d\n\r",stsFlag);

    return BOARD_SOK;

}

/**
 * \brief  Get FPD Link-III transmit status
 *
 * This function is used to get the FPD LinkIII transmit status.
 *
 * \param  handle        [IN]      Low level driver handle
 * \param  fpdModParams  [IN]      FPD module params
 * \param  stsFlag       [IN/OUT]  FPD LinkIII transmit status
 *                                 False - FPD Link III transmit unsuccessful
 *                                 True  - FPD Link III transmit successful
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetFpd3LinkTxSts(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            bool *stsFlag)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DUAL_STS_DUAL_STS_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *stsFlag = (((regData & BOARD_FPD_UB941_FPD3_TX_STS_BIT_MASK) >> BOARD_FPD_UB941_FPD3_TX_STS_SHIFT_CNT) == 1) ?  true : false;
    BOARD_DEVICES_STS_LOG("stsFlag = %d\n\r",stsFlag);

    return BOARD_SOK;

}

/**
 * \brief  Get DSI clock detect status
 *
 * This function is used to get DSI clock detect status.
 *
 * \param  handle        [IN]      Low level driver handle
 * \param  fpdModParams  [IN]      FPD module params
 * \param  stsFlag       [IN/OUT]  DSI clock detection status
 *                                 False - DSI clock detection failed
 *                                 True  - DSI clock detection successful
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetDsiClkDetSts(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           bool *stsFlag)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DUAL_STS_DUAL_STS_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *stsFlag = (((regData & BOARD_FPD_UB941_DSI_CLK_DET_BIT_MASK) >> BOARD_FPD_UB941_DSI_CLK_DET_SHIFT_CNT) == 1) ?  true : false;
    BOARD_DEVICES_STS_LOG("stsFlag = %d\n\r",stsFlag);

    return BOARD_SOK;

}

/**
 * \brief  Get selected port DSI clock detect status
 *
 *  This function is used to get DSI clock detect status 
 *  of selected port.
 *
 * \param  handle        [IN]      Low level driver handle
 * \param  fpdModParams  [IN]      FPD module params
 * \param  stsFlag       [IN/OUT]  DSI clock detection status of selected port
 *                                 False - DSI clock detection failed
 *                                 True  - DSI clock detection successful
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetSelPortDsiClkDetSts(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  bool *stsFlag)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                            fpdModParams->serSlvAddr,
                            BOARD_FPD_UB941_DUAL_STS_DUAL_STS_P1_REG_ADDR,
                            &regData,
                            1U,
                            BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *stsFlag = (((regData & BOARD_FPD_UB941_NO_DSI_CLK_BIT_MASK) >> BOARD_FPD_UB941_NO_DSI_CLK_SHIFT_CNT) == 1) ?  true : false;
    BOARD_DEVICES_STS_LOG("stsFlag = %d\n\r",stsFlag);

    return BOARD_SOK;

}

/**
 * \brief  Get frequency stability status
 *
 * This function is used to get DSI frequency stability status
 *
 * \param  handle        [IN]       Low level driver handle
 * \param  fpdModParams  [IN]       FPD module params
 * \param  stsFlag       [IN/OUT]   Ferquency stability status
 *                                  False - Frequency status failed
 *                                  True  - Frequency status successful
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetFreqStabilitySts(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               bool *stsFlag)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DUAL_STS_DUAL_STS_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *stsFlag = (((regData & BOARD_FPD_UB941_FREQ_STABLE_BIT_MASK) >> BOARD_FPD_UB941_FREQ_STABLE_SHIFT_CNT) == 1) ?  true : false;
    BOARD_DEVICES_STS_LOG("stsFlag = %d\n\r",stsFlag);

    return BOARD_SOK;

}

/**
 * \brief  configure indirect register read enable mode
 *
 * This function is used to enable/disable PCLK AUTO mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetIndirRegRdEn(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_IND_ACC_CTL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_IND_ACC_CTL_READ_WRITE_BIT_MASK);
    regData |= cfgMode;

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_IND_ACC_CTL_REG_ADDR,
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
 * \brief  configure transmit mode
 *
 * This function is used to confiure the transmit mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   operMode - BOARD_FPD_UB941_AUTO_DETECT_FPD3_MODE 
 *                                          BOARD_FPD_UB941_FORCED_SINGLE_FPD3_TRANSMITTER_MODE
 *                                          BOARD_FPD_UB941_FORCED_DUAL_FPD3_TRANSMITTER_MODE
 *                                          BOARD_FPD_UB941_AUTO_DETECT_FPD3_SINGLE_MODE
 *                                          BOARD_FPD_UB941_FORCED_INDEPENDENT_2_2_MODE
 *                                          BOARD_FPD_UB941_FORCED_SPLITTER_MODE
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941Tx_Mode(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DUAL_CTL1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_FPD3_TX_MODE_BIT_MASK);
    regData |= operMode;

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_DUAL_CTL1_REG_ADDR,
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
 * \brief  configure serializer clock mode control mode
 *
 * This function is used to enable/disable PCLK AUTO mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetSerClkModeCtrl(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_BRIDGE_CTL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DSI_CONTINUOUS_CLK_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_DSI_CONTINUOUS_CLK_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_BRIDGE_CTL_REG_ADDR,
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
 * \brief  configure clock lane mode control mode
 *
 * This function is used to enable/disable PCLK AUTO mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   laneMode       [IN]   ----todo---------
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDsiLaneModeCtrl(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t laneMode)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_BRIDGE_CTL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_BRIDGE_LANE_MODE_BIT_MASK);
    regData |= (laneMode << BOARD_FPD_UB941_BRIDGE_LANE_MODE_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_BRIDGE_CTL_REG_ADDR,
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
 * \brief  Digital Reset mode control
 *
 * Resets the entire digital block including registers
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Normal operation (or) Reset
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDigitalRst1ModeCtrl(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_RESET_CTL_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_DIGITAL_RESET1_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_DIGITAL_RESET1_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_RESET_CTL_REG_ADDR,
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
Board_STATUS Board_fpdUb941SetI2CBusFreq(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t cfgBitRate)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regAddr;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    regAddr = BOARD_FPD_UB941_SCL_HIGH_TIME_REG_ADDR;
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

    regAddr = BOARD_FPD_UB941_SCL_LOW_TIME_REG_ADDR;
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
 * \brief  Remote deserializer slave device id config
 *
 * This function is used for configuring the remote deserializer slave device ID
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   fpdRmtParams  [IN]   Remote device module params
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941RmtDesAliasCfg(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          Board_FpdRmtDevObj *fpdRmtParams)
{
    Board_STATUS ret = BOARD_SOK;

    uint8_t i = 0,i2cDeviceData = 0, i2cAliasData= 0;
    uint8_t i2cDeviceAddr[8] = {BOARD_FPD_UB941_SLAVE_ID0_REG_ADDR,
                                BOARD_FPD_UB941_SLAVE_ID1_REG_ADDR,
                                BOARD_FPD_UB941_SLAVE_ID2_REG_ADDR,
                                BOARD_FPD_UB941_SLAVE_ID3_REG_ADDR,
                                BOARD_FPD_UB941_SLAVE_ID4_REG_ADDR,
                                BOARD_FPD_UB941_SLAVE_ID5_REG_ADDR,
                                BOARD_FPD_UB941_SLAVE_ID6_REG_ADDR,
                                BOARD_FPD_UB941_SLAVE_ID7_REG_ADDR};
    
    uint8_t i2cAliasAddr[8] = {BOARD_FPD_UB941_SLAVE_ALIAS_0_REG_ADDR,
                               BOARD_FPD_UB941_SLAVE_ALIAS_1_REG_ADDR,
                               BOARD_FPD_UB941_SLAVE_ALIAS_2_REG_ADDR,
                               BOARD_FPD_UB941_SLAVE_ALIAS_3_REG_ADDR,
                               BOARD_FPD_UB941_SLAVE_ALIAS_4_REG_ADDR,
                               BOARD_FPD_UB941_SLAVE_ALIAS_5_REG_ADDR,
                               BOARD_FPD_UB941_SLAVE_ALIAS_6_REG_ADDR,
                               BOARD_FPD_UB941_SLAVE_ALIAS_7_REG_ADDR};
    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }
    while((fpdRmtParams[i].i2cDevAddr != 0x00) && (i<8))
    {
        i2cDeviceData = (fpdRmtParams[i].i2cDevAddr << 1);
        ret = Board_i2c8BitRegWr(handle,
                                 fpdModParams->serSlvAddr,
                                 i2cDeviceAddr[i],
                                 &i2cDeviceData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);

        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
        
        i2cAliasData = (fpdRmtParams[i].i2cDevAliasAddr << 1);
        ret = Board_i2c8BitRegWr(handle,
                                 fpdModParams->serSlvAddr,
                                 i2cAliasAddr[i],
                                 &i2cAliasData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);

        if(ret != 0)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
        i++;
    }
    return BOARD_SOK;
}

/**
 * \brief  Inverted color pattern select
 *
 * This function is used to initialize the ub941 DSI module.
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   fpdModParams   [IN]  FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetInvtdClrPattEn(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCFG_PGCFG_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_INVERTED_COLOR_PATTERN_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_INVERTED_COLOR_PATTERN_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCFG_PGCFG_P1_REG_ADDR,
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
Board_STATUS Board_fpdUb941SetAutoScrollPattEn(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCFG_PGCFG_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_AUTO_SCROLL_PATTERN_BIT_MASK);
    regData |= cfgMode;

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCFG_PGCFG_P1_REG_ADDR,
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
 * \brief  configure color bars
 *
 * This function is used to enable/disable pass through mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   patternSel    [IN]   Indicates the pattern to be displayed:
 *                                BOARD_FPD_UB941_PATTERN_CHECKERBOARD
 *                                BOARD_FPD_UB941_PATTERN_WHITE_BLACK
 *                                BOARD_FPD_UB941_PATTERN_BLACK_WHITE
 *                                BOARD_FPD_UB941_PATTERN_RED_CYAN
 *                                BOARD_FPD_UB941_PATTERN_GREEN_MAGNETA
 *                                BOARD_FPD_UB941_PATTERN_BLUE_YELLOW
 *                                BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2WHT_WHT2BLK
 *                                BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2RED_WHT2CYN
 *                                BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2GRN_WHT2MAG
 *                                BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2BLU_WHT2YEL
 *                                BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2WHT_WHT2BLK
 *                                BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2RED_WHT2CYN
 *                                BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2GRN_WHT2MAG
 *                                BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2BLU_WHT2YEL
 *                                BOARD_FPD_UB941_PATTERN_CUSTOM_COLORS
 *                                BOARD_FPD_UB941_PATTERN_VCOM
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelPatt(void *handle,
                                   Board_FpdModuleObj *fpdModParams,
                                   uint8_t patternSel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    ret = Board_i2c8BitRegRd(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCTL_PGCTL_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_PATTERN_SEL_BIT_MASK);
    regData |= (patternSel << BOARD_FPD_UB941_PATTERN_SEL_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCTL_PGCTL_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }
    
    /*enabling colors bars*/
    ret = Board_fpdUb941ColorBarEn(handle,
                                   fpdModParams,
                                   BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        BOARD_DEVICES_ERR_LOG("Enabling Color Bars failed\n");
        return -1;
    } 

    return BOARD_SOK;
}

/**
 * \brief  configure pattern display
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
Board_STATUS Board_fpdUb941PattGenEn(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCTL_PGCTL_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_PATTERN_GENERATOR_BIT_MASK);
    regData |= cfgMode;

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCTL_PGCTL_P1_REG_ADDR,
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
 * \brief  configure color bars
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
Board_STATUS Board_fpdUb941ColorBarEn(void *handle,
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
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCTL_PGCTL_P1_REG_ADDR,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_FPD_UB941_COLORS_BAR_PATTERN_SEL_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB941_COLORS_BAR_PATTERN_SEL_SHIFT_CNT);

    ret = Board_i2c8BitRegWr(handle,
                             fpdModParams->serSlvAddr,
                             BOARD_FPD_UB941_PGCTL_PGCTL_P1_REG_ADDR,
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
 * \brief  Get ub941 i2c address.
 *
 * This function is used to get the I2C address and
 * channel details of UB960 module.
 *
 * \param   domain    [IN]  I2C instance domain
 * \param   chNum     [IN]  buffer to hold i2c channel number
 * \param   i2cAddr   [IN]  buffer to hold i2c address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
void Board_fpdUb941GetI2CAddr(uint8_t *domain,
                              uint8_t *chNum,
                              uint8_t *i2cAddr)
{
    *domain = BOARD_SOC_DOMAIN_MAIN;
    *chNum = 1U;
    *i2cAddr = 0x16;
}



