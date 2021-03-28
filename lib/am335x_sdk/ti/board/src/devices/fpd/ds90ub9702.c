/******************************************************************************
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
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
 * \file  ds90ub9702.c
 *
 * \brief This file contains the API's for configuring the ds90ub9702 deserailizer hub.
 *
 */
#include "ds90ub9702.h"

/* DES UB9702 configurations for RAW12 1920x1080 30fps, 4 lanes @1.5Gbps
   Corresponding Macro(for passing to API call): BOARD_FPD_UB9702_PG_RAW12_1920_1080_30_FPS */
Board_I2cRegProgObj Board_FpdUb9702PGCfg0[] =
{
    {0x32, 0x01, 0x50},
	{0x1F, 0x00, 0x50},
	{0xC9, 0x1E, 0x50},
	{0xB0, 0x1C, 0x50},
	{0xB1, 0x92, 0x50},
	{0xB2, 0x40, 0x50},
	{0xB0, 0x01, 0x50},
	{0xB1, 0x01, 0x50},
	{0xB2, 0x01, 0x50},
	{0xB1, 0x02, 0x50},
	{0xB2, 0x33, 0x50},
	{0xB1, 0x03, 0x50},
	{0xB2, 0x2C, 0x50},
	{0xB1, 0x04, 0x50},
	{0xB2, 0x0B, 0x50},
	{0xB1, 0x05, 0x50},
	{0xB2, 0x40, 0x50},
	{0xB1, 0x06, 0x50},
	{0xB2, 0x01, 0x50},
	{0xB1, 0x07, 0x50},
	{0xB2, 0x68, 0x50},
	{0xB1, 0x08, 0x50},
	{0xB2, 0x04, 0x50},
	{0xB1, 0x09, 0x50},
	{0xB2, 0x38, 0x50},
	{0xB1, 0x0A, 0x50},
	{0xB2, 0x07, 0x50},
	{0xB1, 0x0B, 0x50},
	{0xB2, 0x98, 0x50},
	{0xB1, 0x0C, 0x50},
	{0xB2, 0x06, 0x50},
	{0xB1, 0x0D, 0x50},
	{0xB2, 0xB3, 0x50},
	{0xB1, 0x0E, 0x50},
	{0xB2, 0x07, 0x50},
	{0xB1, 0x0F, 0x50},
	{0xB2, 0x08, 0x50},
	{0x33, 0x33, 0x50},
    {BOARD_DEVICES_CONFIG_END},
};

/* DES UB9702 configurations for RAW12 3840x2160 40fps, 4 lanes @1.5Gbps 
   Corresponding Macro(for passing to API call): BOARD_FPD_UB9702_PG_RAW12_3840_2160_40_FPS */ 
Board_I2cRegProgObj Board_FpdUb9702PGCfg1[] =
{
    {0x32, 0x01, 0x50},
	{0x1F, 0x00, 0x50},
	{0xC9, 0x1E, 0x50},
	{0xB0, 0x1C, 0x50},
	{0xB1, 0x92, 0x50},
	{0xB2, 0x40, 0x50},
	{0xB0, 0x01, 0x50},
	{0xB1, 0x01, 0x50},
	{0xB2, 0x01, 0x50},
	{0xB1, 0x02, 0x50},
	{0xB2, 0x33, 0x50},
	{0xB1, 0x03, 0x50},
	{0xB2, 0x2C, 0x50},
	{0xB1, 0x04, 0x50},
	{0xB2, 0x16, 0x50},
	{0xB1, 0x05, 0x50},
	{0xB2, 0x80, 0x50},
	{0xB1, 0x06, 0x50},
	{0xB2, 0x02, 0x50},
	{0xB1, 0x07, 0x50},
	{0xB2, 0xD0, 0x50},
	{0xB1, 0x08, 0x50},
	{0xB2, 0x08, 0x50},
	{0xB1, 0x09, 0x50},
	{0xB2, 0x70, 0x50},
	{0xB1, 0x0A, 0x50},
	{0xB2, 0x08, 0x50},
	{0xB1, 0x0B, 0x50},
	{0xB2, 0x80, 0x50},
	{0xB1, 0x0C, 0x50},
	{0xB2, 0x04, 0x50},
	{0xB1, 0x0D, 0x50},
	{0xB2, 0x7D, 0x50},
	{0xB1, 0x0E, 0x50},
	{0xB2, 0x07, 0x50},
	{0xB1, 0x0F, 0x50},
	{0xB2, 0x08, 0x50},
	{0x33, 0x73, 0x50},
    {BOARD_DEVICES_CONFIG_END},
};

Board_I2cRegProgObj *Board_FpdUb9702PGCfg[BOARD_FPD_UB9702_PG_MAX] =
{
    &Board_FpdUb9702PGCfg0[0U],       /* RAW12 1920x1080 30fps */
    &Board_FpdUb9702PGCfg1[0U],       /* RAW12 3840x2160 40fps */
};

/**
 * \brief  Set deserializer device Id
 *
 *  This function is used for configuring the deserializer
 *  device Id.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   devId         [IN]   device Id
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetDesDevId(void *handle,
                                        Board_FpdModuleObj *fpdModParams,
                                        uint8_t devId)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_I2C_DEVICE_ID_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_DEVICE_ID_BIT_MASK);
    regData |= ((devId << BOARD_FPD_UB9702_DEVICE_ID_SHIFT_CNT) | BOARD_FPD_UB9702_DES_ID_BIT_MASK);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
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
Board_STATUS Board_fpdUb9702SetDigitalRst1ModeCtrl(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_RESET_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    /* Reset digital RESET1, resets the entire digital block including registers */

    regData &= ~(BOARD_FPD_UB9702_DIGITAL_RESET1_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_DIGITAL_RESET1_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  I2C master enable mode control
 *
 * This function is used for configuring the I2C master enable mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetI2cMstrEnModeCtrl(void *handle,
                                                 Board_FpdModuleObj *fpdModParams,
                                                 uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_GENERAL_CFG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_I2C_MASTER_EN_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_I2C_MASTER_EN_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  output enable mode select
 *
 * This function is used for configuring the output enable mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetOutputEnMode(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_GENERAL_CFG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_OUTPUT_EN_MODE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_OUTPUT_EN_MODE_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set output enable control mode
 *
 * This function is used for configuring the output enable control mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetOutputEnCtrlMode(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_GENERAL_CFG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_OUTPUT_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_OUTPUT_ENABLE_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Output sleep state select
 *
 * This function is used for configuring the output sleep state select mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetOSSSelModeCtrl(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_GENERAL_CFG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    /* Reset digital RESET1, resets the entire digital block
       including registers */
    regData &= ~(BOARD_FPD_UB9702_OUTPUT_SLEEP_STATE_SEL_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_OUTPUT_SLEEP_STATE_SEL_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Get force clock detect status
 *
 * This function is used for getting the status of force clock detect
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   clkDetSts     [IN]   Buffer to hold the clock detect status
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702GetForceRefClkDetSts(void *handle,
                                                 Board_FpdModuleObj *fpdModParams,
                                                 bool *clkDetSts)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_GENERAL_CFG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    *clkDetSts = (((regData & BOARD_FPD_UB9702_FORCE_REFCLK_DET_BIT_MASK) == 1) ? true : false);

    return 0;
}

/**
 * \brief  Set BCC watch dog timer
 *
 * This function is used to set the watch dog for user configurable
 * timeout in multiples of 2 milliseconds.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   timeoutCnt    [IN]   timeout value in units of 2 milliseconds
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetBCCWatchDogTImer(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t timeoutCnt)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_BCC_WATCHDOG_CONTROL_REG_ADDR;

    /* Enables and watch dog timer and sets the watch dog timer count */
    regData = ((timeoutCnt << BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_SHIFT_CNT) | BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_DISABLE_BIT_MASK);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  BCC I2C slave port map
 *
 * This function is used to map control channel to I2C slave port
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   BCCChNum      [IN]   Back channel control channel number
 * \param   I2CSlvPort    [IN]   I2C slave port either '0' or '1'
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetBCCI2CSlvPortMap(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t BCCChNum,
                                                uint8_t I2CSlvPort)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_RX_PORT_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    switch(BCCChNum)
    {
        case BOARD_FPD_UB9702_BCC3_MAP:
             regData &= ~(BOARD_FPD_UB9702_BCC3_MAP_BIT_MASK);
             regData |= (I2CSlvPort << BOARD_FPD_UB9702_BCC3_MAP_SHIFT_CNT);
             break;
        case BOARD_FPD_UB9702_BCC2_MAP:
             regData &= ~(BOARD_FPD_UB9702_BCC2_MAP_BIT_MASK);
             regData |= (I2CSlvPort << BOARD_FPD_UB9702_BCC2_MAP_SHIFT_CNT);
             break;
        case BOARD_FPD_UB9702_BCC1_MAP:
             regData &= ~(BOARD_FPD_UB9702_BCC1_MAP_BIT_MASK);
             regData |= (I2CSlvPort << BOARD_FPD_UB9702_BCC1_MAP_SHIFT_CNT);
             break;
        case BOARD_FPD_UB9702_BCC0_MAP:
             regData &= ~(BOARD_FPD_UB9702_BCC0_MAP_BIT_MASK);
             regData |= (I2CSlvPort << BOARD_FPD_UB9702_BCC0_MAP_SHIFT_CNT);
             break;
        default:
             boardStatus = -1;
             break;
    }

    if(boardStatus == -1)
    {
        return boardStatus;
    }

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Receiver port enable mode control
 *
 * This function is used to set the receiver port enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   RcvrPortNum    [IN]   Receiver port number
 * \param   cfgMode        [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRcvrPortEnModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t RcvrPortNum,
                                                  uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_RX_PORT_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    switch(RcvrPortNum)
    {
        case BOARD_FPD_UB9702_PORT3_EN:
             regData &= ~(BOARD_FPD_UB9702_PORT3_EN_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_PORT3_EN_SHIFT_CNT);
             break;
        case BOARD_FPD_UB9702_PORT2_EN:
             regData &= ~(BOARD_FPD_UB9702_PORT2_EN_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_PORT2_EN_SHIFT_CNT);
             break;
        case BOARD_FPD_UB9702_PORT1_EN:
             regData &= ~(BOARD_FPD_UB9702_PORT1_EN_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_PORT1_EN_SHIFT_CNT);
             break;
        case BOARD_FPD_UB9702_PORT0_EN:
             regData &= ~(BOARD_FPD_UB9702_PORT0_EN_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_PORT0_EN_SHIFT_CNT);
             break;
        default:
             boardStatus = -1;
             break;
    }

    if(boardStatus != 0)
    {
        return boardStatus;
    }

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set IO pin supply
 *
 * This function is used to set IO pin supply
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   ioLevel        [IN]   IO level to be configred i.e; 1.8V or 3.3V
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetIOPinSupply(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t ioLevel)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_IO_CTL_REG_ADDR;

    /* The values written to the SEL3P3V and IO_SUPPLY_MODE fields will be used */
    boardStatus = Board_fpdUb9702SetIOSupplyOverrideModeCtrl(handle,
                                                             fpdModParams,
                                                             BOARD_FPD_MODE_ENABLE);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_SEL3P3V_BIT_MASK);
    regData |= (ioLevel << BOARD_FPD_UB9702_SEL3P3V_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Get IO pin supply
 *
 * This function is used to get IO pin supply
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   ioLevel        [IN]   IO level to be configred i.e; 1.8V or 3.3V
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702GetIOPinSupply(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t *ioLevel)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_IO_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    *ioLevel = ((regData & BOARD_FPD_UB9702_SEL3P3V_BIT_MASK) >> BOARD_FPD_UB9702_SEL3P3V_SHIFT_CNT);

    return 0;
}

/**
 * \brief  Set IO supply voltage level
 *
 * This function is used to set IO supply voltage level
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates override Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetIOSupplyOverrideModeCtrl(void *handle,
                                                        Board_FpdModuleObj *fpdModParams,
                                                        uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_IO_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_IO_SUPPLY_MODE_OV_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_IO_SUPPLY_MODE_OV_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set IO supply mode control
 *
 * This function is used to set IO supply mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   ioLevel        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetIOSupplyMode(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t ioLevel)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_IO_CTL_REG_ADDR;

    /* The values written to the SEL3P3V and IO_SUPPLY_MODE fields will be used */
    boardStatus = Board_fpdUb9702SetIOSupplyOverrideModeCtrl(handle,
                                                             fpdModParams,
                                                             BOARD_FPD_MODE_ENABLE);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_IO_SUPPLY_MODE_BIT_MASK);
    regData |= (ioLevel << BOARD_FPD_UB9702_IO_SUPPLY_MODE_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Get IO pin supply mode
 *
 * This function is used to get the IO supply mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   ioLevel        [IN]   IO level to be configred i.e; 1.8V or 3.3V
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702GetIOSupplyMode(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t *ioLevel)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_IO_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    *ioLevel = ((regData & BOARD_FPD_UB9702_IO_SUPPLY_MODE_BIT_MASK) >> BOARD_FPD_UB9702_IO_SUPPLY_MODE_SHIFT_CNT);
    return 0;
}

/**
 * \brief  Set frame sync mode control
 *
 * This function is used to set frame sync mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSync      [IN]   Frame sync to be configured
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSModeCtrl(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t frameSync)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_FS_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_FS_MODE_BIT_MASK);
    regData |= (frameSync << BOARD_FPD_UB9702_FS_MODE_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set frame sync pulse generate mode control
 *
 * This function is used to set single frame sync pulse generate mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSPulseGenModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_FS_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_FS_SINGLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_FS_SINGLE_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set Frame sync generate enable mode control
 *
 * This function is used to set frame sync generate mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSGenEnModeCtrl(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_FS_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_FS_GEN_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_FS_GEN_ENABLE_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set Frame sync high time1
 *
 * This function is used to set frame sync high time1
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSyncTime  [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSHighTime1(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t frameSyncTime)
{
    int8_t boardStatus;
    uint8_t regAddr;

    regAddr = BOARD_FPD_UB9702_FS_HIGH_TIME_1_REG_ADDR;
    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &frameSyncTime,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set Frame sync high time0
 *
 * This function is used to set frame sync high time1
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSyncTime  [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSHighTime0(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t frameSyncTime)
{
    int8_t boardStatus;
    uint8_t regAddr;

    regAddr = BOARD_FPD_UB9702_FS_HIGH_TIME_0_REG_ADDR;
    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &frameSyncTime,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set Frame sync low time1
 *
 * This function is used to set frame sync low time1
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSyncTime  [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSLowTime1(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t frameSyncTime)
{
    int8_t boardStatus;
    uint8_t regAddr;

    regAddr = BOARD_FPD_UB9702_FS_LOW_TIME_1_REG_ADDR;
    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &frameSyncTime,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set Frame sync low time1
 *
 * This function is used to set frame sync low time0
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSyncTime  [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSLowTime0(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t frameSyncTime)
{
    int8_t boardStatus;
    uint8_t regAddr;

    regAddr = BOARD_FPD_UB9702_FS_LOW_TIME_0_REG_ADDR;
    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &frameSyncTime,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set maximum frame high count
 *
 * This function is used to set maximum frame high count
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameCnt       [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetMaxFrameHiCnt(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t frameCnt)
{
    int8_t boardStatus;
    uint8_t regAddr;

    regAddr = BOARD_FPD_UB9702_MAX_FRM_HI_REG_ADDR;
    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &frameCnt,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set maximum frame low count
 *
 * This function is used to set maximum frame low count
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameCnt       [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetMaxFrameLoCnt(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t frameCnt)
{
    int8_t boardStatus;
    uint8_t regAddr;

    regAddr = BOARD_FPD_UB9702_MAX_FRM_LO_REG_ADDR;
    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &frameCnt,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Select oscillator clock
 *
 * This function is used to set maximum frame low count
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   refClk         [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelOscClk(void *handle,
                                      Board_FpdModuleObj *fpdModParams,
                                      uint8_t refClk)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_PLL_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_SEL_OSC_200M_BIT_MASK);
    regData |= (refClk << BOARD_FPD_UB9702_SEL_OSC_200M_SHIFT_CNT);

     boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set reference clock mode control
 *
 * This function is used to set reference clock mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   refClk         [IN]   reference clock mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRefClkModeCtrl(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t refClk)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_PLL_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_REF_CLK_MODE_BIT_MASK);
    regData |= (refClk << BOARD_FPD_UB9702_REF_CLK_MODE_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Select CSI transmitter speed
 *
 * This function is used to select CSI transmitter speed
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   txSpeed        [IN]   Transmitter speed
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelCSITxSpeed(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t txSpeed)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_PLL_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_CSI_TX_SPEED_BIT_MASK);
    regData |= (txSpeed << BOARD_FPD_UB9702_CSI_TX_SPEED_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set forward port disable mode control
 *
 * This function is used to set forward port disable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   fwdPort        [IN]   forward port number
 * \param   cfgMode        [IN]   configured mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFwdPortDisModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t fwdPort,
                                                  uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_FWD_CTL1_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    switch(fwdPort)
    {
        case BOARD_FPD_9702_FWD_PORT_3:
             regData &= ~(BOARD_FPD_UB9702_FWD_PORT3_DIS_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_FWD_PORT3_DIS_SHIFT_CNT);
             break;
        case BOARD_FPD_9702_FWD_PORT_2:
             regData &= ~(BOARD_FPD_UB9702_FWD_PORT2_DIS_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_FWD_PORT2_DIS_SHIFT_CNT);
             break;
        case BOARD_FPD_9702_FWD_PORT_1:
             regData &= ~(BOARD_FPD_UB9702_FWD_PORT1_DIS_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_FWD_PORT1_DIS_SHIFT_CNT);
             break;
        case BOARD_FPD_9702_FWD_PORT_0:
             regData &= ~(BOARD_FPD_UB9702_FWD_PORT0_DIS_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_FWD_PORT0_DIS_SHIFT_CNT);
             break;
        default:
             boardStatus = -1;
             break;
    }

    if(boardStatus != 0)
    {
        return boardStatus;
    }

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set recevie port map
 *
 * This function is used to set receive port map
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   rxPort         [IN]   receive port number
 * \param   csiPort        [IN]   csi port number
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRxPortMap(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t rxPort,
                                         uint8_t csiPort)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_FWD_CTL1_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    switch(rxPort)
    {
        case BOARD_FPD_9702_FWD_PORT_3:
             regData &= ~(BOARD_FPD_UB9702_RX3_MAP_BIT_MASK);
             regData |= (csiPort << BOARD_FPD_UB9702_RX3_MAP_SHIFT_CNT);
             break;
        case BOARD_FPD_9702_FWD_PORT_2:
             regData &= ~(BOARD_FPD_UB9702_RX2_MAP_BIT_MASK);
             regData |= (csiPort << BOARD_FPD_UB9702_RX2_MAP_SHIFT_CNT);
             break;
        case BOARD_FPD_9702_FWD_PORT_1:
             regData &= ~(BOARD_FPD_UB9702_RX1_MAP_BIT_MASK);
             regData |= (csiPort << BOARD_FPD_UB9702_RX1_MAP_SHIFT_CNT);
             break;
        case BOARD_FPD_9702_FWD_PORT_0:
             regData &= ~(BOARD_FPD_UB9702_RX0_MAP_BIT_MASK);
             regData |= (csiPort << BOARD_FPD_UB9702_RX0_MAP_SHIFT_CNT);
             break;
        default:
             boardStatus = -1;
             break;
    }

    if(boardStatus == -1)
    {
        return boardStatus;
    }

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Select transmit port read back register block
 *
 * This function is used to select the transmit port read back register block
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   regBlk         [IN]   port0/port1 register blocks
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelTxPortRdBackRegBlk(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t regBlk)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_PORT_SEL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_TX_READ_PORT_BIT_MASK);
    regData |= (regBlk << BOARD_FPD_UB9702_TX_READ_PORT_SHIFT_CNT);

   boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set transmit port1 write enable mode control
 *
 * This function is used to set transmit port1 write enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetTxPort1WrEnModeCtrl(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_PORT_SEL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_TX_WRITE_PORT_1_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_TX_WRITE_PORT_1_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set transmit port0 write enable mode control
 *
 * This function is used to set transmit port0 write enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetTxPort0WrEnModeCtrl(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_PORT_SEL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_TX_WRITE_PORT_0_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_TX_WRITE_PORT_0_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;

}

/**
 * \brief  Set CSI lane count
 *
 * This function is used to set CSI lane count
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   laneCnt        [IN]   CSI lane count
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetCSILaneCnt(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t laneCnt)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_CSI_LANE_COUNT_BIT_MASK);
    regData |= (laneCnt << BOARD_FPD_UB9702_CSI_LANE_COUNT_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set CSI continuous clock mode control
 *
 * This function is used to set CSI continuous clock mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetCSIContsClkModeCtrl(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_CSI_CONTS_CLOCK_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_CSI_CONTS_CLOCK_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set CSI output enable mode control
 *
 * This function is used to set CSI output enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetCSIEnableModeCtrl(void *handle,
                                                 Board_FpdModuleObj *fpdModParams,
                                                 uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_CTL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_CSI_ENABLE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_CSI_ENABLE_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set CSI pass mode control
 *
 * This function is used to set CSI pass mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetCSIPassModeCtrl(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_CSI_CTL2_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_CSI_PASS_MODE_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_CSI_PASS_MODE_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Get bi-directional control channel status
 *
 * This function is used to get bi-directional control status
 *
 * \param   handle         [IN]    Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   bccStatus      [OUT]   Buffer to hold BCC status
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702GetBCCStatus(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t *bccStatus)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_BCC_STATUS_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }
    *bccStatus = regData;

    return 0;
}

/**
 * \brief  Select receive port read back register block
 *
 * This function is used to select the receive port register block for read back
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   regBlk         [IN]   port0/port1 register blocks
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelRxPortRdBackRegBlk(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t regBlk)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_FPD3_PORT_SEL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_RX_READ_PORT_BIT_MASK);
    regData |= (regBlk << BOARD_FPD_UB9702_RX_READ_PORT_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set receive port write enable mode control
 *
 * This function is used to set receive port write enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   rxWrPort       [IN]   receive write port number
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRxPortWrEnModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t rxWrPort,
                                                  uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_FPD3_PORT_SEL_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    switch(rxWrPort)
    {
        case BOARD_FPD_9702_RX_WR_PORT_3:
             regData &= ~(BOARD_FPD_UB9702_RX_WRITE_PORT_3_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_RX_WRITE_PORT_3_SHIFT_CNT);
             break;
        case BOARD_FPD_9702_RX_WR_PORT_2:
             regData &= ~(BOARD_FPD_UB9702_RX_WRITE_PORT_2_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_RX_WRITE_PORT_2_SHIFT_CNT);
             break;
        case BOARD_FPD_9702_RX_WR_PORT_1:
             regData &= ~(BOARD_FPD_UB9702_RX_WRITE_PORT_1_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_RX_WRITE_PORT_1_SHIFT_CNT);
             break;
        case BOARD_FPD_9702_RX_WR_PORT_0:
             regData &= ~(BOARD_FPD_UB9702_RX_WRITE_PORT_0_BIT_MASK);
             regData |= (cfgMode << BOARD_FPD_UB9702_RX_WRITE_PORT_0_SHIFT_CNT);
             break;
        default:
             boardStatus = -1;
             break;
    }

    if(boardStatus == -1)
    {
        return boardStatus;
    }

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set I2C pass through all mode control
 *
 * This function is used to set I2C pass through all mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetI2CPassThrAllModeCtrl(void *handle,
                                                     Board_FpdModuleObj *fpdModParams,
                                                     uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_BCC_CONFIG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_I2C_PASS_THROUGH_ALL_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_I2C_PASS_THROUGH_ALL_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set I2C pass through mode control
 *
 * This function is used to set I2C pass through mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetI2CPassThrModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_BCC_CONFIG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_I2C_PASS_THROUGH_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_I2C_PASS_THROUGH_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set I2C Auto acknowledge mode control
 *
 * This function is used to set I2C auto acknowledge mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetI2CAutoAckModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_BCC_CONFIG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_AUTO_ACK_ALL_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_AUTO_ACK_ALL_SHIFT_CNT);

     boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Set back channel enable mode control
 *
 * This function is used to set back channel enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetBCCEnModeCtrl(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_BCC_CONFIG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_BC_ALWAYS_ON_BIT_MASK);
    regData |= (cfgMode << BOARD_FPD_UB9702_BC_ALWAYS_ON_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Select back channel frequency
 *
 * This function is used to select back channel frequency
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   bcFreq         [IN]   Back channel frequency
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelBCFreq(void *handle,
                                      Board_FpdModuleObj *fpdModParams,
                                      uint8_t bcFreq)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_BCC_CONFIG_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_BC_FREQ_SELECT_BIT_MASK);
    regData |= (bcFreq << BOARD_FPD_UB9702_BC_FREQ_SELECT_SHIFT_CNT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
}

/**
 * \brief  Select back channel frequency
 *
 * This function is used to select back channel frequency
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   rmtSerId       [IN]   Remote serializer slave address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRmtSerId(void *handle,
                                        Board_FpdModuleObj *fpdModParams,
                                        uint8_t rmtSerId)
{
    int8_t boardStatus;
    uint8_t regAddr;
    uint8_t regData = 0;

    regAddr = BOARD_FPD_UB9702_SER_ID_REG_ADDR;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    regData &= ~(BOARD_FPD_UB9702_SER_ID_BIT_MASK);
    regData |= ((rmtSerId << BOARD_FPD_UB9702_SER_ID_SHIFT_CNT) | BOARD_FPD_UB9702_FREEZE_DEVICE_ID_BIT_MASK);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     regAddr,
                                     &regData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != 0)
    {
        return boardStatus;
    }

    return 0;
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
Board_STATUS Board_fpdUb9702RmtSerSlvDevAliasIdCfg(void *handle,
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

    slvIdReg = BOARD_FPD_UB9702_SlaveID_0_REG_ADDR;
    slvAliasIdReg = BOARD_FPD_UB9702_SlaveAlias_0_REG_ADDR;

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

    return BOARD_SOK;
}

/**
 * \brief  Get ub9702 i2c address.
 *
 * This function is used to get the I2C address and
 * channel details of UB9702 module.
 * \param   hubInstance [IN]  instance of the csi hub
 * \param   domain      [IN]  I2C instance domain
 * \param   chNum       [IN]  buffer to hold i2c channel number
 * \param   i2cAddr     [IN]  buffer to hold i2c address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
void Board_fpdUb9702GetI2CAddr(uint8_t hubInstance,
                               uint8_t *domain,
                               uint8_t *chNum,
                               uint8_t *i2cAddr)
{
    *domain = BOARD_SOC_DOMAIN_MAIN;
    *chNum = 6U;

    if(hubInstance == BOARD_FPD_9702_CSI2_DES_HUB1)
    {
        *i2cAddr = 0x3DU;
    }
    else if(hubInstance == BOARD_FPD_9702_CSI2_DES_HUB2)
    {
        *i2cAddr = 0x30U;
    }
    else if(hubInstance == BOARD_FPD_9702_CSI2_DES_HUB3)
    {
        *i2cAddr = 0x32U;
    }
    else
    {
        BOARD_DEVICES_STS_LOG("Enter the correct hub instance");
    }
}

Board_STATUS Board_fpdUb9702CfgPG(void *handle,
                                  Board_FpdModuleObj *fpdModParams,
                                  uint32_t pgType)
{
    Board_STATUS ret = BOARD_SOK;
    uint16_t index = 0;
#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
    uint8_t rdData;
#endif
    Board_I2cRegProgObj *ub9702Cfg;

    if((handle == NULL) || (pgType >= BOARD_FPD_UB9702_PG_MAX))
    {
        ret = BOARD_INVALID_PARAM;
    }

    if (ret == BOARD_SOK)
    {
        ub9702Cfg = Board_FpdUb9702PGCfg[pgType];
        BOARD_DEVICES_STS_LOG("PG configurations for deserializer with slave address - 0x%x...\n\r",
                              fpdModParams->desSlvAddr);
        while ((ub9702Cfg[index].regAddr != BOARD_DEVICES_CONFIG_END) && 
               (ret == BOARD_SOK))
            
        {
#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
            BOARD_DEVICES_STS_LOG("regAddr - 0x%2x --- regData - 0x%2x\n\r",
                                  (uint8_t)ub9702Cfg[index].regAddr,
                                  ub9702Cfg[index].regData);
#endif
            ret = Board_i2c8BitRegWr(handle,
                                     fpdModParams->desSlvAddr,
                                     (uint8_t)ub9702Cfg[index].regAddr,
                                     (uint8_t *)(&ub9702Cfg[index].regData),
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
            if(ret != 0)
            {
                ret = BOARD_I2C_TRANSFER_FAIL;
            }

            if(ub9702Cfg[index].i2cDelay != 0)
                Board_delay(ub9702Cfg[index].i2cDelay);

#if defined(BOARD_FPD_I2C_CFG_RD_BACK_EN)
            ret = Board_i2c8BitRegRd(handle,
                                     fpdModParams->desSlvAddr,
                                     (uint8_t)ub9702Cfg[index].regAddr,
                                     &rdData,
                                     1U,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
            if(ret != 0)
            {
                ret = BOARD_I2C_TRANSFER_FAIL;
            }

            BOARD_DEVICES_STS_LOG(" --- read back data - 0x%2x\n\r", rdData);
#endif
            index++;
        }
    }

    return (ret);
}
