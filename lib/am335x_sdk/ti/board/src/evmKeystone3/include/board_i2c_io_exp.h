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

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_IO_EXP_INPUT_PORT0_ADDR                    (0x00)
#define BOARD_IO_EXP_INPUT_PORT1_ADDR                    (0x01)
#define BOARD_IO_EXP_OUTPUT_PORT0_ADDR                   (0x02)
#define BOARD_IO_EXP_OUTPUT_PORT1_ADDR                   (0x03)
#define BOARD_IO_EXP_POLARITY_INVERSION_PORT0_ADDR       (0x04)
#define BOARD_IO_EXP_POLARITY_INVERSION_PORT1_ADDR       (0x05)
#define BOARD_IO_EXP_CONFIGURATION_PORT0_ADDR            (0x06)
#define BOARD_IO_EXP_CONFIGURATION_PORT1_ADDR            (0x07)

/* This command is used to read the data from the data input register,
   If read/write mode bit is set to read */
#define BOARD_IO_EXP_CMD_READ_INPUT                      (0x11)
/* This command is used only to fill the write data shift register,
   but data will not be transferred to the data output register(If read/write
   mode bit is set to write) */ 
#define BOARD_IO_EXP_CMD_WRITE_DATA_SHIFT                (0x11)
/* This command is used to transfer from the already filled write data shift 
   register to the data output register */
#define BOARD_IO_EXP_CMD_LOAD_DATA_OUTPUT                (0x22)
/* This command is used to write data to the data shift register and transfer
   it to the output storage register immediately (extra load 22H command not 
   needed) */
#define BOARD_IO_EXP_CMD_DIRECT_LOAD_DATA_OUPTUT         (0x44)


/* The Input Port register '0' reflects the incoming logic levels of the pins,
   regardless of whether the pin is defined as an input or an output by the
   configuration register */
#define BOARD_IO_EXP_CMD_INPUT_PORT0_DATA                (0x00)
/* The Input Port register '1' reflects the incoming logic levels of the pins,
   regardless of whether the pin is defined as an input or an output by the
   configuration register */
#define BOARD_IO_EXP_CMD_INPUT_PORT1_DATA                (0x01)
/* The Output Port register '0' shows the outgoing logic levels of the pins
   defined as outputs by the Configuration register */
#define BOARD_IO_EXP_CMD_OUTPUT_PORT0_DATA               (0x02)
/* The Output Port register '1' shows the outgoing logic levels of the pins
   defined as outputs by the Configuration register */
#define BOARD_IO_EXP_CMD_OUTPUT_PORT1_DATA               (0x03)
/* The Polarity Inversion register '0' allow polarity inversion of pins defined 
   as inputs by the Configuration register. If a bit in this register is 
   set(written with '1'), the corresponding port pin's polarity is inverted.
   If a bit in this register is cleared (written with a '0'), the corresponding
   port pin's original polarity is retained. */
#define BOARD_IO_EXP_CMD_POLARITY_INVERSION_PORT0        (0x04)
/* The Polarity Inversion register '0' allow polarity inversion of pins defined 
   as inputs by the Configuration register. If a bit in this register is 
   set(written with '1'), the corresponding port pin's polarity is inverted.
   If a bit in this register is cleared (written with a '0'), the corresponding
   port pin's original polarity is retained. */
#define BOARD_IO_EXP_CMD_POLARITY_INVERSION_PORT1        (0x05)
/* The Configuration register '0' configure the direction of the I/O pins. If
   a bit in this register is set to '1', the corresponding port pin is enabled
   as an input with a high-impedance output driver. If a bit in this register
   is cleared to '0', the corresponding port pin is enabled as an output. */
#define BOARD_IO_EXP_CMD_CONFIGURATION_PORT0             (0x06)
/* The Configuration register '1' configure the direction of the I/O pins. If
   a bit in this register is set to '1', the corresponding port pin is enabled
   as an input with a high-impedance output driver. If a bit in this register
   is cleared to '0', the corresponding port pin is enabled as an output. */
#define BOARD_IO_EXP_CMD_CONFIGURATION_PORT1             (0x07)

/**
 * \enum i2cIoExpPortNumber_t
 *
 * \brief specifies the available port types.
 */
typedef enum
{
    PORTNUM_0 = 0,
    PORTNUM_1,
    PORTNUM_NONE
}i2cIoExpPortNumber_t;

/**
 * \enum i2cIoExpPinNumber_t
 *
 * \brief specifies the available pin numbers.
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
 * \enum i2cIoExpPinDirection_t
 *
 * \brief specifies the available direction types.
 */
typedef enum
{
    PIN_DIRECTION_OUTPUT = 0,
    PIN_DIRECTION_INPUT
}i2cIoExpPinDirection_t;

/**
 * \enum i2cIoExpPinDirection_t
 *
 * \brief specifies the available signal levels.
 */
typedef enum
{
    GPIO_SIGNAL_LEVEL_LOW = 0,
    GPIO_SIGNAL_LEVEL_HIGH
}i2cIoExpSignalLevel_t;

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
                                      uint8_t data);

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
 *            direction           [IN]   Direction of the pin to be configured.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpSetPinDirection(uint8_t slaveAddr,
                                     i2cIoExpPortNumber_t portNum,
                                     i2cIoExpPinNumber_t pinNum,
                                     i2cIoExpPinDirection_t direction);

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
                               uint8_t data);


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
                                 i2cIoExpSignalLevel_t signalLevel);
                                        
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
                              uint8_t *data);

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
                                 uint8_t *signalLevel);

/**
 *  \brief    This function initializes the i2c instance connected to the
 *            i2c IO Expander.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_i2cIoExpInit(void);

/**
 *  \brief    This function de-initializes the i2c instance connected to the
 *            i2c IO Expander.
 *
 */
void Board_i2cIoExpDeInit(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BOARD_I2C_IO_EXP_H_ */
