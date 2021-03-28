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
 *   \file  board_i2c_io_exp.c
 *
 *   \brief
 *      This file contains the API's for accessing the i2c slave devices
 *      connected to i2c IO Expander.
 *
 */
 
#include "board_i2c_io_exp.h"

I2C_Handle i2cHandle = NULL;

/**
 *  \brief    Generates a random Board_delay.
 *
 *  \param    Board_delayVal            [IN]   Board_delay count.
 *
 */ 
static void Board_delay(uint32_t Board_delayVal)
{
	uint32_t cnt = 0;
    while(cnt < Board_delayVal)
    {
		asm("");
        cnt++;
    }
}

/**
 *  \brief    This function is used to set the direction of the pins of a
 *            specified GPIO Port.
 *
 *  \param    slaveAddr           [IN]   I2C Slave Address.
 *            portNum             [IN]   Port number of the i2c slave device
 *                                       PORTNUM_X    - Port number of a slave
 *                                                      device
 *            data                [IN]   Register data to be configured.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpSetPortDirection(uint8_t slaveAddr,
                                            i2cIoExpPortNumber_t portNum,
                                            uint8_t data)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t dataBuff[2] = {0};
    I2C_Transaction transaction;

    if(Board_obj.i2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if(portNum == PORTNUM_0)
    {
        dataBuff[0] = BOARD_IO_EXP_CMD_CONFIGURATION_PORT0;
    }
    else if(portNum == PORTNUM_1)
    {
        dataBuff[0] = BOARD_IO_EXP_CMD_CONFIGURATION_PORT1;
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
    transaction.writeCount   = 2; /* writes data size of 2 bytes */
    transaction.readCount    = 0;

    Board_delay(200); /* MAXIE_TBD: Board_delay need to be adjusted */

    ret = I2C_transfer(Board_obj.i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;

}

/**
 *  \brief    This function is used to set the direction of the specified pin
 *            of a specified port.
 *
 *  \param    slaveAddr           [IN]   I2C Slave Address.
 *            portNum             [IN]   Port number of the i2c slave device
 *                                       PORTNUM_X    - Port number of a slave
 *                                                      device
 *            pinNum              [IN]   Pin with in the specified port of 
 *                                       the i2c slave device
 *                                       PORTNUM_0 - 0th Port of a slave device
 *                                       PORTNUM_1 - 1st Port of a slave device
 *            direction           [IN]   Direction of the pin to be configured.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpSetPinDirection(uint8_t slaveAddr,
                                           i2cIoExpPortNumber_t portNum,
                                           i2cIoExpPinNumber_t pinNum,
                                           i2cIoExpPinDirection_t direction)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t dataBuff[2] = {0};
    uint8_t data;
    I2C_Transaction transaction;

    if(Board_obj.i2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if(portNum == PORTNUM_0)
    {
        dataBuff[0] = BOARD_IO_EXP_CMD_CONFIGURATION_PORT0;
    }
    else if(portNum == PORTNUM_1)
    {
        dataBuff[0] = BOARD_IO_EXP_CMD_CONFIGURATION_PORT1;
    }
    else
    {
        return -1;
    }

    Board_i2cIoExpReadPort(slaveAddr, portNum, &data);
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
    transaction.writeCount   = 2; /* writes data size of 2 bytes */
    transaction.readCount    = 0;

    Board_delay(200); /* MAXIE_TBD: Board_delay need to be adjusted */

    ret = I2C_transfer(Board_obj.i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;

}

/**
 *  \brief    This function is used to set the signal level of the pins
 *            of a specified port.
 *
 *  \param    slaveAddr           [IN]   I2C Slave Address.
 *            portNum             [IN]   Port number of the i2c slave device
 *                                       PORTNUM_NONE - Used for single ported
 *                                                      slave devices
 *                                       PORTNUM_X    - Port number of a slave
 *                                                      device
 *            data                [IN]   Signal level data of the pins to be
 *                                       configured.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpWritePort(uint8_t slaveAddr,
                                     i2cIoExpPortNumber_t portNum,
                                     uint8_t data)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t dataBuff[2] = {0};
    I2C_Transaction transaction;

    if(Board_obj.i2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if(portNum == PORTNUM_NONE)
    {
        dataBuff[0] = BOARD_IO_EXP_CMD_DIRECT_LOAD_DATA_OUPTUT;
    }
    else
    {
        if(portNum == PORTNUM_0)
        {
            dataBuff[0] = BOARD_IO_EXP_CMD_OUTPUT_PORT0_DATA;
        }
        else
        {
            dataBuff[0] = BOARD_IO_EXP_CMD_OUTPUT_PORT1_DATA;
        }
    }

    dataBuff[1] = data;

	/* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    /* Control Byte followed by write bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &dataBuff;
    transaction.writeCount   = 2; /* writes data size of 2 bytes */
    transaction.readCount    = 0;

    Board_delay(200); /* MAXIE_TBD: Board_delay need to be adjusted */

    ret = I2C_transfer(Board_obj.i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;
}

/**
 *  \brief    This function is used to set the signal level of the specified
 *            pin of a specified port.
 *
 *  \param    slaveAddr           [IN]   I2C Slave Address.
 *            portNum             [IN]   Port number of the i2c slave device
 *                                       PORTNUM_NONE - Used for single ported
 *                                                      slave devices
 *                                       PORTNUM_X    - Port number of a slave
 *                                                      device
 *            pinNum              [IN]   Pin with in the specified port of
 *                                       the i2c slave device
 *            signalLevel         [IN]   Signal level data of the pin to be
 *                                       configured.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpPinLevelSet(uint8_t slaveAddr,
                                       i2cIoExpPortNumber_t portNum,
                                       i2cIoExpPinNumber_t pinNum,
                                       i2cIoExpSignalLevel_t signalLevel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t dataBuff;
    uint8_t data;

	ret = Board_i2cIoExpReadPort(slaveAddr, portNum, &data);
	if(ret != BOARD_SOK)
	{
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
	}

	dataBuff = (signalLevel << pinNum);
	data = ((data & ~(1 << pinNum)) | dataBuff);
    return (Board_i2cIoExpWritePort(slaveAddr, portNum, data));
}

/**
 *  \brief    This function is used to read the signal level of the pins
 *            of a specified port.
 *
 *  \param    slaveAddr           [IN]   I2C Slave Address.
 *            portNum             [IN]   Port number of the i2c slave device
 *                                       PORTNUM_NONE - Used for single ported
 *                                                      slave devices
 *                                       PORTNUM_X    - Port number of a slave
 *                                                      device
 *            data                [IN]   Pointer to the data buffer to store 
 *                                       the pin level data of a specified port.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpReadPort(uint8_t slaveAddr,
                                    i2cIoExpPortNumber_t portNum,
                                    uint8_t *data)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t subAddr;
    I2C_Transaction transaction;

    if(Board_obj.i2cHandle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if(portNum == PORTNUM_NONE)
    {
        subAddr = BOARD_IO_EXP_INPUT_PORT0_ADDR;
    }
    else
    {
        if(portNum == PORTNUM_0)
        {
            subAddr = BOARD_IO_EXP_CMD_INPUT_PORT0_DATA;
        }
        else
        {
            subAddr = BOARD_IO_EXP_CMD_INPUT_PORT1_DATA;
        }
    }

	/* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    /*Control Byte followed by read bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &subAddr;
    transaction.readBuf      = data;
    transaction.writeCount   = 1; /* 1 Byte */
    transaction.readCount    = 0;

    Board_delay(200);

    ret = I2C_transfer(Board_obj.i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    transaction.writeCount   = 0;
    transaction.readCount    = 1; /* reads data size of 1 byte */

    ret = I2C_transfer(Board_obj.i2cHandle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
    }

    return BOARD_SOK;
}

/**
 *  \brief    This function is used to read the signal level of a pin
 *            of a specified port.
 *
 *  \param    slaveAddr           [IN]   I2C Slave Address.
 *            portNum             [IN]   Port number of the i2c slave device
 *                                       PORTNUM_NONE - Used for single ported
 *                                                      slave devices
 *                                       PORTNUM_X    - Port number of a slave
 *                                                      device
 *            pinNum              [IN]   Pin number of the specified port
 *            signalLevel         [IN]   Data buffer to store specified pin
 *                                       level of a specified port.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpPinLevelGet(uint8_t slaveAddr,
                                       i2cIoExpPortNumber_t portNum,
                                       i2cIoExpPinNumber_t pinNum,
                                       uint8_t *signalLevel)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t data;

	ret = Board_i2cIoExpReadPort(slaveAddr, portNum, &data);
	if(ret != BOARD_SOK)
	{
        ret = BOARD_I2C_TRANSFER_FAIL;
        return ret;
	}

    *signalLevel = (((1 << pinNum) & (data)) >> pinNum);

    return BOARD_SOK;
}

/**
 *  \brief    This function initializes the i2c instance connected to the
 *            i2c IO Expander.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpInit(void)
{
    Board_STATUS ret = BOARD_SOK;
    I2C_Transaction i2cTransaction;

	/* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&i2cTransaction);

    /* If handle not opened yet, initialises i2c */
    if (Board_obj.i2cHandle == NULL)
    {
        ret = Board_internalInitI2C();
		if (ret != BOARD_SOK)
			return ret;
    }

    return ret;
}

/**
 *  \brief    This function de-initializes the i2c instance connected to the
 *            i2c IO Expander.
 *
 */
void Board_i2cIoExpDeInit(void)
{
    /* Closing the i2c IO Exp Instance */
    I2C_close(Board_obj.i2cHandle);
    Board_obj.i2cHandle = NULL;
}
