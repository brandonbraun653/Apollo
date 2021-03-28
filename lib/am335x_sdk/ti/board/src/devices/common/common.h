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
 * \file   common.h
 *
 * \brief  The macro definitions and function prototypes which
 *         are common across different board devices.
 *
 */

#ifndef _COMMON_H_
#define _COMMON_H_

/**
 *
 *  \ingroup BOARD_LIB_DEVICES
 *
 *  \defgroup BOARD_LIB_DEVICES_COMMON Board Device Common Library
 *
 *  Common APIs for writing a register or reading a register of the devices
 *  supported by board device library. Uses I2C LLD for the HW read/write.
 *
 *  @{
 *
 */
/* @} */

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/board/board.h>

#include <ti/osal/osal.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_COMMON 
 *
 *  \defgroup BOARD_LIB_DEVICES_COMMON_TYPES Data Types
 *
 *  @{
 *
 */

#define BOARD_DEVICES_CONFIG_END           (-1)

/* Define below macros to enable the debug logs from board device library */
/* Enables status logs */
#undef BOARD_DEVICES_ENABLE_STATUS_LOGS
/* Enables error logs which are displayed during function execution failure */
#undef BOARD_DEVICES_ENABLE_ERROR_LOGS

#if defined(BOARD_DEVICES_ENABLE_STATUS_LOGS)
#define BOARD_DEVICES_STS_LOG     UART_printf
#else
#define BOARD_DEVICES_STS_LOG(x, ...)
#endif  /* #if defined(BOARD_DEVICES_ENABLE_STATUS_LOGS) */

#if defined(BOARD_DEVICES_ENABLE_ERROR_LOGS)
#define BOARD_DEVICES_ERR_LOG     UART_printf
#else
#define BOARD_DEVICES_ERR_LOG(x, ...)
#endif  /* #if defined(BOARD_DEVICES_ENABLE_ERROR_LOGS) */

#define BOARD_FPD_MAX_REMOTE_SENSOR_DEVICES                 (8U)

/** Sete the FPD module to disable state */
#define BOARD_FPD_MODE_DISABLE                              (0U)
/** Sete the FPD module to enable state */
#define BOARD_FPD_MODE_ENABLE                               (1U)

/** Sets the FPD mode to normal operation */
#define BOARD_FPD_MODE_NORMAL                               (0U)
/** Sets the FPD mode to reset */
#define BOARD_FPD_MODE_RESET                                (1U)

/** Sets the FPD I2C serial clock frequency to 100KBPS */
#define BOARD_FPD_KBPS_100                                  (0x64U)
/** Sets the FPD I2C serial clock frequency to 400KBPS */
#define BOARD_FPD_KBPS_400                                  (0x32U)

/** To send the MSB of a register offset address first */
#define BOARD_I2C_REG_ADDR_MSB_FIRST                        (0x0U)

/** To send the LSB of a register offset address first */
#define BOARD_I2C_REG_ADDR_LSB_FIRST                        (0x1U)

#define ONE_MILLI_SEC                                       (1U)

/** I2C delay of 5 milliseconds */
#define BOARD_FPD_I2C_CFG_DELAY                             (5 * ONE_MILLI_SEC)

/** I2C transaction default timeout */
#define BOARD_I2C_TRANSACTION_TIMEOUT                       (2000U)

/**
 * \brief  FPD remote device object structure
 */
typedef struct Board_FpdRmtDevObj_s
{
    /** FPD remote sensor I2C device address */
    uint32_t i2cDevAddr;
    /** FPD remote I2C sensor device alias address */
    uint32_t i2cDevAliasAddr;
} Board_FpdRmtDevObj;

/**
 * \brief  FPD module object structure
 */
typedef struct Board_FpdModuleObj_s
{
    /** FPD deserializer device address */
    uint32_t desSlvAddr;
    /** FPD serializer device address */
    uint32_t serSlvAddr;
    /** FPD remote serializer/deserializer device alias address */
    uint32_t serDesAliasAddr;
} Board_FpdModuleObj;

/**
 * \brief  FPD remote device object structure
 */
typedef struct Board_I2cRegProgObj_s
{
    /** FPD register offset address */
    int32_t regAddr;
    /** FPD register data */
    uint32_t regData;
    /** FPD i2c delay in milliseconds */
    uint32_t i2cDelay;
} Board_I2cRegProgObj;

/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_COMMON 
 *
 *  \defgroup BOARD_LIB_DEVICES_API Application Interfaces
 *
 *  @{
 *
 */
 
/**
 * \brief  Delay generation function
 *
 * This function is used to generates delay proportional to user
 * specified delay cycles.
 *
 * \param    delayCycles   [IN]   Number of delay cycles.
 *
 */
void Board_delay(uint32_t delayCycles);

/**
 * \brief I2C 16-bit register read function
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
 * \param   i2cTimeout  [IN]  I2C driver timeout value
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c16BitRegRd(void   *handle,
                                 uint32_t slaveAddr,
                                 uint16_t regAddr,
                                 uint8_t *regData,
                                 uint8_t numOfBytes,
                                 uint8_t byteOrdSel,
                                 uint32_t i2cTimeout);

/**
 * \brief I2C 16-bit register write function
 *
 * This function is used to write the data on the i2c
 * device registers
 *
 * \param   handle      [IN]  Low level driver handle
 * \param   slaveAddr   [IN]  I2C slave address
 * \param   regAddr     [IN]  I2C register offset address
 * \param   regData     [IN]  I2C register data buffer
 * \param   numOfBytes  [IN]  Receive data width
 * \param   byteOrdSel  [IN]  Register address byte order select
 * \param   i2cTimeout  [IN]  I2C driver timeout value
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c16BitRegWr(void *handle,
                                 uint32_t slaveAddr,
                                 uint16_t regAddr,
                                 uint8_t *regData,
                                 uint8_t numOfBytes,
                                 uint8_t byteOrdSel,
                                 uint32_t i2cTimeout);

/**
 * \brief I2C 8-bit register read function
 *
 * This function is used to read the 8-bit data from the i2c
 * device registers
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    I2C slave address
 * \param   regAddr     [IN]    I2C register offset address
 * \param   regData     [OUT]   I2C register data buffer
 * \param   numOfBytes  [IN]    Receive data width
 * \param   i2cTimeout  [IN]  I2C driver timeout value 
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c8BitRegRd(void   *handle,
                                uint32_t slaveAddr,
                                uint8_t regAddr,
                                uint8_t *regData,
                                uint8_t numOfBytes,
                                uint32_t i2cTimeout);

/**
 * \brief I2C 8-bit register write function
 *
 * This function is used to write the 8-bit data on the i2c
 * device registers
 *
 * \param   handle      [IN]  Low level driver handle
 * \param   slaveAddr   [IN]  I2C slave address
 * \param   regAddr     [IN]  I2C register offset address
 * \param   regData     [IN]  I2C register data buffer
 * \param   numOfBytes  [IN]  Transmit data width
 * \param   i2cTimeout  [IN]  I2C driver timeout value 
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c8BitRegWr(void *handle,
                                uint32_t slaveAddr,
                                uint8_t regAddr,
                                uint8_t *regData,
                                uint8_t numOfBytes,
                                uint32_t i2cTimeout);

/**
 * \brief I2C 10-bit slave address register read function
 *
 * This function is used to write the 8-bit data on the i2c
 * device registers
 *
 * \param   handle      [IN]  Low level driver handle
 * \param   slaveAddr   [IN]  I2C slave address
 * \param   regAddr     [IN]  I2C register offset address
 * \param   regData     [IN]  I2C register data buffer
 * \param   i2cTimeout  [IN]  I2C driver timeout value 
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c10bit16bitRegRd(void *handle,
                                      uint32_t slaveAddr,
                                      uint16_t regAddr,
                                      uint16_t *regData,
                                      uint32_t i2cTimeout);

/**
 * \brief I2C 10-bit slave address register write function
 *
 * This function is used to write the 8-bit data on the i2c
 * device registers
 *
 * \param   handle      [IN]  Low level driver handle
 * \param   slaveAddr   [IN]  I2C slave address
 * \param   regAddr     [IN]  I2C register offset address
 * \param   regData     [IN]  I2C register data buffer
 * \param   i2cTimeout  [IN]  I2C driver timeout value 
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_i2c10bit16bitRegWr(void *handle,
                                      uint32_t slaveAddr,
                                      uint16_t regAddr,
                                      uint16_t regData,
                                      uint32_t i2cTimeout);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _COMMON_H_ */

/* @} */
