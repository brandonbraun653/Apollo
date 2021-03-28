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
 * \file  common.c
 *
 * \brief This file contains the API's which are common accross different
 *        board devices.
 */

#include "common.h"

/**
 * \brief  Delay generation function
 *
 * This function is used to generates delay in milliseconds.
 *
 * \param    delayCycles   [IN]   Number of milliseconds.
 *
 */
void Board_delay(uint32_t delayCycles)
{
    Osal_delay(delayCycles);
}

/**
 * \brief I2C 16-bit register read fuunction
 *
 * This function is used to read the 16-bit data from the i2c
 * device registers
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    I2C slave address
 * \param   regAddr     [IN]    I2C register offset address
 * \param   regData     [OUT]   I2C register data buffer
 * \param   numOfBytes  [IN]    Receive data width
 * \param   byteOrdSel  [IN]    Register address byte order select
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c16BitRegRd(void   *handle,
                                 uint32_t slaveAddr,
                                 uint16_t regAddr,
                                 uint8_t *regData,
                                 uint8_t numOfBytes,
                                 uint8_t byteOrdSel,
                                 uint32_t i2cTimeout)
{
    Board_STATUS ret = BOARD_SOK;
    I2C_Transaction transaction;
    uint8_t tx[2];

    I2C_Handle i2cHandle = (I2C_Handle)handle;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &tx[0];
    transaction.writeCount   = 2;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;
    transaction.timeout      = i2cTimeout;

    /* 16-bit regAddr data to be sent */
    if(byteOrdSel == BOARD_I2C_REG_ADDR_MSB_FIRST)
    {
        tx[0] = (uint8_t)((regAddr & 0xFF00) >> 8);
        tx[1] = (uint8_t)(regAddr & 0x00FF);
    }
    else
    {
        tx[0] = (uint8_t)(regAddr & 0x00FF);
        tx[1] = (uint8_t)((regAddr & 0xFF00) >> 8);
    }

    ret = I2C_transfer(i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        BOARD_DEVICES_ERR_LOG("Failing while transmitting the rd reg addr with error code - %d\n", ret);
        ret = -1;
        return ret;
    }

    transaction.writeBuf     = NULL;
    transaction.writeCount   = 0;
    transaction.readBuf      = regData;
    transaction.readCount    = numOfBytes;

    ret = I2C_transfer(i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        BOARD_DEVICES_ERR_LOG("Failing while reading the register data by returning - %d\n", ret);
        ret = -1;
        return ret;
    }

    return BOARD_SOK;
}

/**
 * \brief I2C 16-bit register write fuunction
 *
 * This function is used to write the data on the i2c
 * device registers
 *
 * \param   handle      [IN]  Low level driver handle
 * \param   slaveAddr   [IN]  I2C slave address
 * \param   regAddr     [IN]  I2C register offset address
 * \param   regData     [IN]  I2C register data buffer
 * \param   byteOrdSel  [IN]    Register address byte order select
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c16BitRegWr(void *handle,
                                 uint32_t slaveAddr,
                                 uint16_t regAddr,
                                 uint8_t *regData,
                                 uint8_t numOfBytes,
                                 uint8_t byteOrdSel,
                                 uint32_t i2cTimeout)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t tx[6];
    uint8_t *txPtr = NULL;

    I2C_Transaction transaction;

    I2C_Handle i2cHandle = (I2C_Handle)handle;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &tx[0];
    transaction.writeCount   = (numOfBytes + 2);
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;
    transaction.timeout      = i2cTimeout;

    /* 16-bit regAddr data to be sent */
    if(byteOrdSel == BOARD_I2C_REG_ADDR_MSB_FIRST)
    {
        tx[0] = (uint8_t)((regAddr & 0xFF00) >> 8);
        tx[1] = (uint8_t)(regAddr & 0x00FF);
    }
    else
    {
        tx[0] = (uint8_t)(regAddr & 0x00FF);
        tx[1] = (uint8_t)((regAddr & 0xFF00) >> 8);
    }

    txPtr = &tx[2];
    /* regData to be sent */
    while(numOfBytes)
    {
        *txPtr = *regData;
        txPtr++;
        regData++;
        numOfBytes--;
    }

    ret = I2C_transfer(i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        BOARD_DEVICES_ERR_LOG("Failing while writing data by returning - %d\n\r", ret);
        ret = -1;
        return ret;
    }

    return BOARD_SOK;
}

/**
 * \brief I2C 8-bit register read fuunction
 *
 * This function is used to read the 8-bit data from the i2c
 * device registers
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    I2C slave address
 * \param   regAddr     [IN]    I2C register offset address
 * \param   regData     [OUT]   I2C register data buffer
 * \param   numOfBytes  [IN]    Receive data width
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c8BitRegRd(void   *handle,
                                uint32_t slaveAddr,
                                uint8_t regAddr,
                                uint8_t *regData,
                                uint8_t numOfBytes,
                                uint32_t i2cTimeout)
{
    Board_STATUS ret = BOARD_SOK;
    I2C_Transaction transaction;

    I2C_Handle i2cHandle = (I2C_Handle)handle;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &regAddr;
    transaction.writeCount   = 1;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;
    transaction.timeout      = i2cTimeout;

    ret = I2C_transfer(i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        BOARD_DEVICES_ERR_LOG("Failing while transmitting the rd reg addr with error code - %d\n", ret);
        ret = -1;
        return ret;
    }

    transaction.writeBuf     = NULL;
    transaction.writeCount   = 0;
    transaction.readBuf      = regData;
    transaction.readCount    = numOfBytes;

    ret = I2C_transfer(i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        BOARD_DEVICES_ERR_LOG("Failing while reading the register data by returning - %d\n", ret);
        ret = -1;
        return ret;
    }

    return BOARD_SOK;
}

/**
 * \brief I2C 8-bit register write fuunction
 *
 * This function is used to write the 8-bit data on the i2c
 * device registers
 *
 * \param   handle      [IN]  Low level driver handle
 * \param   slaveAddr   [IN]  I2C slave address
 * \param   regAddr     [IN]  I2C register offset address
 * \param   regData     [IN]  I2C register data buffer
 * \param   numOfBytes  [IN]  Transmit data width
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c8BitRegWr(void *handle,
                                uint32_t slaveAddr,
                                uint8_t regAddr,
                                uint8_t *regData,
                                uint8_t numOfBytes,
                                uint32_t i2cTimeout)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t tx[5];
    uint8_t *txPtr = NULL;
    I2C_Transaction transaction;

    I2C_Handle i2cHandle = (I2C_Handle)handle;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &tx[0];
    transaction.writeCount   = 2;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;
    transaction.timeout      = i2cTimeout;

    tx[0] = regAddr;
    txPtr = &tx[1];
    /* regData to be sent */
    while(numOfBytes)
    {
        *txPtr = *regData;
        txPtr++;
        regData++;
        numOfBytes--;
    }

    ret = I2C_transfer(i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        BOARD_DEVICES_ERR_LOG("Failing while writing data by returning - %d\n\r", ret);
        ret = -1;
        return ret;
    }

    return BOARD_SOK;
}

/*********************************************************************
 * \brief   I2C 16-bit register read function in 10-bit slave address
 *
 * This function is used to read 16 bit register value from
 * the 10-bit slave address devices.
 *
 * \param   handle      [IN]  Low level driver handle
 * \param   slaveAddr   [IN]  I2C slave address
 * \param   regAddr     [IN]  I2C register offset address
 * \param   regData     [IN]  I2C register data buffer
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c10bit16bitRegRd(void *handle,
                                      uint32_t slaveAddr,
                                      uint16_t regAddr,
                                      uint16_t *regData,
                                      uint32_t i2cTimeout)
{
    int8_t boardStatus;
    uint8_t tx[2];
    uint8_t rx[2] = {0, 0};
    *regData = 0;
    I2C_Transaction transaction;

    I2C_Handle i2cHandle = (I2C_Handle)handle;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = tx;
    transaction.writeCount   = 2;
    transaction.readBuf      = rx;
    transaction.readCount    = 2;
    transaction.expandSA     = true;
    transaction.timeout      = i2cTimeout;

    tx[0] = ((0xFF00) & regAddr  >> 8);
    tx[1] = (0x00FF) & regAddr;

    boardStatus = I2C_transfer(i2cHandle, &transaction);
    if(boardStatus != I2C_STS_SUCCESS)
    {
        BOARD_DEVICES_ERR_LOG("Failing while reading the register data by returning - %d\n", boardStatus);
        boardStatus = -1;
    }
    *regData = (uint16_t)(rx[0] << 8) | (rx[1]);

    return 0;
}

/*********************************************************************
 * \brief   I2C 16-bit register read function in 10-bit slave address
 *
 * This function is used to read 16 bit register value from
 * the 10-bit slave address devices.
 *
 * \param   handle      [IN]  Low level driver handle
 * \param   slaveAddr   [IN]  I2C slave address
 * \param   regAddr     [IN]  I2C register offset address
 * \param   regData     [IN]  I2C register data buffer
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c10bit16bitRegWr(void *handle,
                                      uint32_t slaveAddr,
                                      uint16_t regAddr,
                                      uint16_t regData,
                                      uint32_t i2cTimeout)
{
    int8_t boardStatus = 0;
    uint8_t tx[4];
    I2C_Transaction transaction;

    I2C_Handle i2cHandle = (I2C_Handle)handle;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &tx[0];
    transaction.writeCount   = 4;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;
    transaction.expandSA     = true;
    transaction.timeout      = i2cTimeout;

    /* MSB of 16-bit data should be sent first followed by the LSB */
    tx[0] = (uint8_t)((regAddr & 0xFF00) >> 8);
    tx[1] = (uint8_t)(regAddr & 0x00FF);
    
    /* MSB of 16-bit data should be sent first followed by the LSB */
    tx[2] = (uint8_t)((regData & 0xFF00) >> 8);
    tx[3] = (uint8_t)(regData & 0x00FF);

    boardStatus = I2C_transfer(i2cHandle, &transaction);
    if(boardStatus != I2C_STS_SUCCESS)
    {
        BOARD_DEVICES_ERR_LOG("Failing while writing data by returning - %d\n\r", boardStatus);
        boardStatus = -1;
    }
    return 0;
}
