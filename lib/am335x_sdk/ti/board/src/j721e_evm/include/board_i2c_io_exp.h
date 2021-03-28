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
 * \file   board_i2c_io_exp.h
 *
 * \brief  I2C IO Expander configurations header file
 *
 * This file includes the structures, enums and register offsets
 * for configuring the slave devices connected to I2C IO expander.
 *
 */

#ifndef _BOARD_I2C_IO_EXP_H_
#define _BOARD_I2C_IO_EXP_H_

#include "board_internal.h"
#include "board_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Input command for single port IO expander */
#define BOARD_1PORT_IOEXP_INPUT_CMD                             (0x00U)

/* Output command for single port IO expander */
#define BOARD_1PORT_IOEXP_OUTPUT_CMD                            (0x01U)

/* Polarity inversion command for single port IO expander */
#define BOARD_1PORT_IOEXP_POLARITY_CMD                          (0x02U)

/* Configuration command for single port IO expander */
#define BOARD_1PORT_IOEXP_CONFIGURATION_CMD                     (0x03U)

/* Input commands for two port IO expander */
#define BOARD_2PORT_IOEXP_PORT0_INPUT_CMD                       (0x00U)
#define BOARD_2PORT_IOEXP_PORT1_INPUT_CMD                       (0x01U)

/* Output commands for two port IO expander */
#define BOARD_2PORT_IOEXP_PORT0_OUTPUT_CMD                      (0x02U)
#define BOARD_2PORT_IOEXP_PORT1_OUTPUT_CMD                      (0x03U)

/* Polarity inversion commands for two port IO expander */
#define BOARD_2PORT_IOEXP_PORT0_POLARITY_CMD                    (0x04U)
#define BOARD_2PORT_IOEXP_PORT1_POLARITY_CMD                    (0x05U)

/* Configuration commands for two port IO expander */
#define BOARD_2PORT_IOEXP_PORT0_CONFIGURATION_CMD               (0x06U)
#define BOARD_2PORT_IOEXP_PORT1_CONFIGURATION_CMD               (0x07U)

/* Input commands for three port IO expander */
#define BOARD_3PORT_IOEXP_PORT0_INPUT_CMD                       (0x00U)
#define BOARD_3PORT_IOEXP_PORT1_INPUT_CMD                       (0x01U)
#define BOARD_3PORT_IOEXP_PORT2_INPUT_CMD                       (0x02U)

/* Output commands for three port IO expander */
#define BOARD_3PORT_IOEXP_PORT0_OUTPUT_CMD                      (0x04U)
#define BOARD_3PORT_IOEXP_PORT1_OUTPUT_CMD                      (0x05U)
#define BOARD_3PORT_IOEXP_PORT2_OUTPUT_CMD                      (0x06U)

/* Polarity inversion commands for three port IO expander */
#define BOARD_3PORT_IOEXP_PORT0_POLARITY_CMD                    (0x08U)
#define BOARD_3PORT_IOEXP_PORT1_POLARITY_CMD                    (0x09U)
#define BOARD_3PORT_IOEXP_PORT2_POLARITY_CMD                    (0x0AU)

/* Configuration commands for two port IO expander */
#define BOARD_3PORT_IOEXP_PORT0_CONFIGURATION_CMD               (0x0CU)
#define BOARD_3PORT_IOEXP_PORT1_CONFIGURATION_CMD               (0x0DU)
#define BOARD_3PORT_IOEXP_PORT2_CONFIGURATION_CMD               (0x0EU)

/**
 *  \enum    i2cIoExpType_t
 *
 *  \brief   specifies the available types of IO expander.
 */
typedef enum
{
    ONE_PORT_IOEXP = 0,
    TWO_PORT_IOEXP,
    THREE_PORT_IOEXP
}i2cIoExpType_t;

/**
 *  \enum     i2cIoExpPortNumber_t
 *
 *  \brief    specifies the available port types.
 */
typedef enum
{
    PORTNUM_0 = 0,
    PORTNUM_1,
    PORTNUM_2
}i2cIoExpPortNumber_t;

/**
 *  \enum     i2cIoExpPinNumber_t
 *
 *  \brief    specifies the available pin numbers.
 */
typedef enum
{
    PIN_NUM_0 = 0,
    PIN_NUM_1,
    PIN_NUM_2,
    PIN_NUM_3,
    PIN_NUM_4,
    PIN_NUM_5,
    PIN_NUM_6,
    PIN_NUM_7
}i2cIoExpPinNumber_t;

/**
 *  \enum     i2cIoExpPinDirection_t
 *
 *  \brief    specifies the available direction types.
 */
typedef enum
{
    PIN_DIRECTION_OUTPUT = 0,
    PIN_DIRECTION_INPUT
}i2cIoExpPinDirection_t;

/**
 *  \enum     i2cIoExpPinDirection_t
 *
 *  \brief    specifies the available signal levels.
 */
typedef enum
{
    GPIO_SIGNAL_LEVEL_LOW = 0,
    GPIO_SIGNAL_LEVEL_HIGH
}i2cIoExpSignalLevel_t;

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
                                       uint8_t *data);

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
                                          uint8_t *data);

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
                                         uint8_t *data);

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
                                            uint8_t data);

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
                                           i2cIoExpPinDirection_t direction);

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
                                     uint8_t data);

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
                                       i2cIoExpSignalLevel_t signalLevel);


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
                                       uint8_t *signalLevel);

/**
 *  \brief    Initializes the i2c instance connected to the i2c IO Expander.
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpInit(void);
                                          
/**
 *  \brief    de-initializes the i2c instance connected to the i2c IO Expander.
 *
 */
void Board_i2cIoExpDeInit(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BOARD_I2C_IO_EXP_H_ */
