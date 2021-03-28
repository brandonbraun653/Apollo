/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *   \file    board_i2c_io_exp.c
 *
 *   \brief   This file contains the API's for accessing the i2c IO Expander.
 *
 */

#include "board_i2c_io_exp.h"

I2C_Handle gIoExpI2cHandle = NULL;
extern Board_I2cInitCfg_t gBoardI2cInitCfg;

/**
 *  \brief    Reads the current configuration of direction port.
 *
 *  \param    slaveAddr       [IN]      I2C Slave Address.
 *  \param    ioExpType       [IN]      IO expander type.
 *                                      X_PORT_IOEXP - Total number of ports
 *                                                     in slave device.
 *  \param    portNum         [IN]      Port number of the i2c slave device
 *                                      PORTNUM_X    - Port number of a slave
 *                                                     device.
 *  \param    data            [IN/OUT]  Pointer to the data buffer to store
 *                                      the pin level data of a specified port.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpReadDirPort(uint8_t slaveAddr,
                                       i2cIoExpType_t ioExpType,
                                       i2cIoExpPortNumber_t portNum,
                                       uint8_t *data)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t subAddr;
    I2C_Transaction transaction;

    if(gIoExpI2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if (ioExpType == ONE_PORT_IOEXP)
    {
        subAddr = BOARD_1PORT_IOEXP_CONFIGURATION_CMD;
    }
    else if (ioExpType == TWO_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            subAddr = BOARD_2PORT_IOEXP_PORT0_CONFIGURATION_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            subAddr = BOARD_2PORT_IOEXP_PORT1_CONFIGURATION_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else if (ioExpType == THREE_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            subAddr = BOARD_3PORT_IOEXP_PORT0_CONFIGURATION_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            subAddr = BOARD_3PORT_IOEXP_PORT1_CONFIGURATION_CMD;
        }
        else if(portNum == PORTNUM_2)
        {
            subAddr = BOARD_3PORT_IOEXP_PORT2_CONFIGURATION_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else
    {
        return BOARD_INVALID_PARAM;
    }

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    /*Control Byte followed by read bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &subAddr;
    transaction.readBuf      = data;
    transaction.writeCount   = 1;
    transaction.readCount    = 0;

    BOARD_delay(200);

    ret = I2C_transfer(gIoExpI2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    transaction.writeCount   = 0;
    transaction.readCount    = 1;

    BOARD_delay(20000);

    ret = I2C_transfer(gIoExpI2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;
}

/**
 *  \brief    Reads the current configuration of output port.
 *
 *  \param    slaveAddr       [IN]      I2C Slave Address.
 *  \param    ioExpType       [IN]      IO expander type.
 *                                      X_PORT_IOEXP - Total number of ports
 *                                                     in slave device.
 *  \param    portNum         [IN]      Port number of the i2c slave device
 *                                      PORTNUM_X    - Port number of a slave
 *                                                     device.
 *  \param    data            [IN/OUT]  Pointer to the data buffer to store
 *                                      the pin level data of a specified port.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpReadOutputPort(uint8_t slaveAddr,
                                          i2cIoExpType_t ioExpType,
                                          i2cIoExpPortNumber_t portNum,
                                          uint8_t *data)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t subAddr;
    I2C_Transaction transaction;

    if(gIoExpI2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if (ioExpType == ONE_PORT_IOEXP)
    {
        subAddr = BOARD_1PORT_IOEXP_OUTPUT_CMD;
    }
    else if (ioExpType == TWO_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            subAddr = BOARD_2PORT_IOEXP_PORT0_OUTPUT_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            subAddr = BOARD_2PORT_IOEXP_PORT1_OUTPUT_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else if (ioExpType == THREE_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            subAddr = BOARD_3PORT_IOEXP_PORT0_OUTPUT_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            subAddr = BOARD_3PORT_IOEXP_PORT1_OUTPUT_CMD;
        }
        else if(portNum == PORTNUM_2)
        {
            subAddr = BOARD_3PORT_IOEXP_PORT2_OUTPUT_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else
    {
        return BOARD_INVALID_PARAM;
    }

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    /*Control Byte followed by read bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &subAddr;
    transaction.readBuf      = data;
    transaction.writeCount   = 1;
    transaction.readCount    = 0;

    BOARD_delay(200);

    ret = I2C_transfer(gIoExpI2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    transaction.writeCount   = 0;
    transaction.readCount    = 1;

    BOARD_delay(20000);

    ret = I2C_transfer(gIoExpI2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;
}

/**
 *  \brief    Reads the signal level of all the pins of the specified port.
 *
 *  \param    slaveAddr       [IN]      I2C Slave Address.
 *  \param    ioExpType       [IN]      IO expander type.
 *                                      X_PORT_IOEXP - Total number of ports
 *                                                     in slave device.
 *  \param    portNum         [IN]      Port number of the i2c slave device
 *                                      PORTNUM_X    - Port number of a slave
 *                                                     device.
 *  \param    data            [IN/OUT]  Pointer to the data buffer to store
 *                                      the pin level data of a specified port.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpReadInputPort(uint8_t slaveAddr,
                                         i2cIoExpType_t ioExpType,
                                         i2cIoExpPortNumber_t portNum,
                                         uint8_t *data)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t subAddr;
    I2C_Transaction transaction;

    if(gIoExpI2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if (ioExpType == ONE_PORT_IOEXP)
    {
        subAddr = BOARD_1PORT_IOEXP_INPUT_CMD;
    }
    else if (ioExpType == TWO_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            subAddr = BOARD_2PORT_IOEXP_PORT0_INPUT_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            subAddr = BOARD_2PORT_IOEXP_PORT1_INPUT_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else if (ioExpType == THREE_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            subAddr = BOARD_3PORT_IOEXP_PORT0_INPUT_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            subAddr = BOARD_3PORT_IOEXP_PORT1_INPUT_CMD;
        }
        else if(portNum == PORTNUM_2)
        {
            subAddr = BOARD_3PORT_IOEXP_PORT2_INPUT_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else
    {
        return BOARD_INVALID_PARAM;
    }

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    /*Control Byte followed by read bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &subAddr;
    transaction.readBuf      = data;
    transaction.writeCount   = 1;
    transaction.readCount    = 0;

    BOARD_delay(200);

    ret = I2C_transfer(gIoExpI2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    transaction.writeCount   = 0;
    transaction.readCount    = 1;

    BOARD_delay(20000);

    ret = I2C_transfer(gIoExpI2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;
}

/**
 *  \brief    Sets the direction of all the pins of the specified Port.
 *
 *  \param    slaveAddr       [IN]        I2C Slave Address.
 *  \param    ioExpType       [IN]        IO expander type.
 *                                        X_PORT_IOEXP - Total number of ports
 *                                                       in that slave device.
 *  \param    portNum         [IN]        Port number of the i2c slave device
 *                                        PORTNUM_X    - Port number of a
 *                                                       slave device.
 *  \param    data            [IN]        Register data to be configured.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpSetPortDirection(uint8_t slaveAddr,
                                            i2cIoExpType_t ioExpType,
                                            i2cIoExpPortNumber_t portNum,
                                            uint8_t data)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t dataBuff[2] = {0};
    I2C_Transaction transaction;

    if(gIoExpI2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if (ioExpType == ONE_PORT_IOEXP)
    {
        dataBuff[0] = BOARD_1PORT_IOEXP_CONFIGURATION_CMD;
    }
    else if (ioExpType == TWO_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            dataBuff[0] = BOARD_2PORT_IOEXP_PORT0_CONFIGURATION_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            dataBuff[0] = BOARD_2PORT_IOEXP_PORT1_CONFIGURATION_CMD;
        }
        else
        {
            return -1;
        }
    }
    else if (ioExpType == THREE_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            dataBuff[0] = BOARD_3PORT_IOEXP_PORT0_CONFIGURATION_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            dataBuff[0] = BOARD_3PORT_IOEXP_PORT1_CONFIGURATION_CMD;
        }
        else if(portNum == PORTNUM_2)
        {
            dataBuff[0] = BOARD_3PORT_IOEXP_PORT2_CONFIGURATION_CMD;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

    dataBuff[1] = data;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    /* Control Byte followed by write bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &dataBuff;
    transaction.writeCount   = 2;
    transaction.readCount    = 0;

    BOARD_delay(200);

    ret = I2C_transfer(gIoExpI2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;
}

/**
 *  \brief    Sets the direction of the specified pin of the specified port.
 *
 *  \param    slaveAddr       [IN]      I2C Slave Address.
 *  \param    ioExpType       [IN]      IO expander type.
 *                                      X_PORT_IOEXP - Total number of ports
 *                                                     in slave device.
 *  \param    portNum         [IN]      Port number of the i2c slave device
 *                                      PORTNUM_X    - Port number of a slave
 *                                                     device.
 *  \param    pinNum          [IN]      Pin with in the specified port of
 *                                      the i2c slave device.
 *                                      PIN_NUM_X    - Pin number.
 *  \param    direction       [IN]      Direction of the pin to be configured.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpSetPinDirection(uint8_t slaveAddr,
                                           i2cIoExpType_t ioExpType,
                                           i2cIoExpPortNumber_t portNum,
                                           i2cIoExpPinNumber_t pinNum,
                                           i2cIoExpPinDirection_t direction)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t dataBuff[2] = {0};
    uint8_t data;
    I2C_Transaction transaction;

    if(gIoExpI2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if (ioExpType == ONE_PORT_IOEXP)
    {
        dataBuff[0] = BOARD_1PORT_IOEXP_CONFIGURATION_CMD;
    }
    else if (ioExpType == TWO_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            dataBuff[0] = BOARD_2PORT_IOEXP_PORT0_CONFIGURATION_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            dataBuff[0] = BOARD_2PORT_IOEXP_PORT1_CONFIGURATION_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else if (ioExpType == THREE_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            dataBuff[0] = BOARD_3PORT_IOEXP_PORT0_CONFIGURATION_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            dataBuff[0] = BOARD_3PORT_IOEXP_PORT1_CONFIGURATION_CMD;
        }
        else if(portNum == PORTNUM_2)
        {
            dataBuff[0] = BOARD_3PORT_IOEXP_PORT2_CONFIGURATION_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else
    {
        return BOARD_INVALID_PARAM;
    }

    Board_i2cIoExpReadDirPort(slaveAddr, ioExpType, portNum, &data);
    if(direction == PIN_DIRECTION_OUTPUT)
    {
        dataBuff[1] = ((data & ~(1 << pinNum)) | (0 << pinNum));
    }
    else
    {
        dataBuff[1] = ((data & ~(1 << pinNum)) | (1 << pinNum));
    }

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    /* Control Byte followed by write bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &dataBuff;
    transaction.writeCount   = 2;
    transaction.readCount    = 0;

    BOARD_delay(200);

    ret = I2C_transfer(gIoExpI2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;
}

/**
 *  \brief    Sets the signal level of all the pins of the specified port.
 *
 *  \param    slaveAddr       [IN]      I2C Slave Address.
 *  \param    ioExpType       [IN]      IO expander type.
 *                                      X_PORT_IOEXP - Total number of ports
 *                                                     in slave device.
 *  \param    portNum         [IN]      Port number of the i2c slave device
 *                                      PORTNUM_X    - Port number of a slave
 *                                                     device.
 *  \param    data            [IN]      Signal level data of the pins to be
 *                                      configured.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpWritePort(uint8_t slaveAddr,
                                     i2cIoExpType_t ioExpType,
                                     i2cIoExpPortNumber_t portNum,
                                     uint8_t data)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t dataBuff[2] = {0};
    I2C_Transaction transaction;

    if(gIoExpI2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if (ioExpType == ONE_PORT_IOEXP)
    {
        dataBuff[0] = BOARD_1PORT_IOEXP_OUTPUT_CMD;
    }
    else if (ioExpType == TWO_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            dataBuff[0] = BOARD_2PORT_IOEXP_PORT0_OUTPUT_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            dataBuff[0] = BOARD_2PORT_IOEXP_PORT1_OUTPUT_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else if (ioExpType == THREE_PORT_IOEXP)
    {
        if(portNum == PORTNUM_0)
        {
            dataBuff[0] = BOARD_3PORT_IOEXP_PORT0_OUTPUT_CMD;
        }
        else if(portNum == PORTNUM_1)
        {
            dataBuff[0] = BOARD_3PORT_IOEXP_PORT1_OUTPUT_CMD;
        }
        else if(portNum == PORTNUM_2)
        {
            dataBuff[0] = BOARD_3PORT_IOEXP_PORT2_OUTPUT_CMD;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }
    else
    {
        return BOARD_INVALID_PARAM;
    }

    dataBuff[1] = data;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    /* Control Byte followed by write bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &dataBuff;
    transaction.writeCount   = 2;
    transaction.readCount    = 0;

    BOARD_delay(200);

    ret = I2C_transfer(gIoExpI2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;
}

/**
 *  \brief    Sets the signal level of the specified pin of the specified port.
 *
 *  \param    slaveAddr       [IN]      I2C Slave Address.
 *  \param    ioExpType       [IN]      IO expander type.
 *                                      X_PORT_IOEXP - Total number of ports
 *                                                     in slave device.
 *  \param    portNum         [IN]      Port number of the i2c slave device
 *                                      PORTNUM_X    - Port number of a slave
 *                                                     device.
 *  \param    pinNum          [IN]      Pin with in the specified port of
 *                                      the i2c slave device.
 *                                      PIN_NUM_X    - Pin number.
 *  \param    signalLevel     [IN]      Signal level data of the pin to be
 *                                      configured.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpPinLevelSet(uint8_t slaveAddr,
                                       i2cIoExpType_t ioExpType,
                                       i2cIoExpPortNumber_t portNum,
                                       i2cIoExpPinNumber_t pinNum,
                                       i2cIoExpSignalLevel_t signalLevel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t dataBuff;
    uint8_t data;

    ret = Board_i2cIoExpReadOutputPort(slaveAddr, ioExpType, portNum, &data);
    if(ret != BOARD_SOK)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    dataBuff = (signalLevel << pinNum);
    data = ((data & ~(1 << pinNum)) | dataBuff);
    return (Board_i2cIoExpWritePort(slaveAddr, ioExpType, portNum, data));
}

/**
 *  \brief    Reads the signal level of specified pin of the specified port.
 *
 *  \param    slaveAddr       [IN]      I2C Slave Address.
 *  \param    ioExpType       [IN]      IO expander type.
 *                                      X_PORT_IOEXP - Total number of ports
 *                                                     in slave device.
 *  \param    portNum         [IN]      Port number of the i2c slave device.
 *                                      PORTNUM_X    - Port number of a slave
 *                                                     device.
 *  \param    pinNum          [IN]      Pin number of the specified port.
 *                                      PIN_NUM_X    - Pin number.
 *  \param    signalLevel     [IN/OUT]  Data buffer to store specified pin
 *                                      level of a specified port.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpPinLevelGet(uint8_t slaveAddr,
                                       i2cIoExpType_t ioExpType,
                                       i2cIoExpPortNumber_t portNum,
                                       i2cIoExpPinNumber_t pinNum,
                                       uint8_t *signalLevel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t data;

    ret = Board_i2cIoExpReadInputPort(slaveAddr, ioExpType, portNum, &data);
    if(ret != BOARD_SOK)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    *signalLevel = (((1 << pinNum) & (data)) >> pinNum);

    return BOARD_SOK;
}

/**
 *  \brief    Initializes the i2c instance connected to the i2c IO Expander.
 *
 *  \return   BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpInit(void)
{
    Board_STATUS ret = BOARD_SOK;

    /* If handle not opened yet, initializes i2c */
    if (gIoExpI2cHandle == NULL)
    {
        gIoExpI2cHandle = Board_getI2CHandle(gBoardI2cInitCfg.socDomain,
                                             gBoardI2cInitCfg.i2cInst);
        if(gIoExpI2cHandle == NULL)
        {
            ret = BOARD_I2C_OPEN_FAIL;
        }
    }

    return ret;
}

/**
 *  \brief    de-initializes the i2c instance connected to the i2c IO Expander.
 *
 */
void Board_i2cIoExpDeInit(void)
{
    /* Closing the i2c IO Exp Instance */
    Board_i2cDeInit();
    gIoExpI2cHandle = NULL;
}
