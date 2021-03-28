/**
 *  \file  i2c_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the i2c.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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
 */

#ifndef i2c_APP_H_
#define i2c_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "i2c.h"
#include "interrupt.h"
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/**
 *  \brief Enumerates the types of Operational modes supported
 *         for I2C Operations.
 */
typedef enum i2cAppOpMode
{
    I2C_APP_OPMODE_MIN =  0U,
    /**< Min Operational mode type of the I2C device */
    I2C_APP_OPMODE_POLLING = I2C_APP_OPMODE_MIN,
    /**< Polling mode of the I2C device */
    I2C_APP_OPMODE_INTERRUPT,
    /**< Interrupt mode of I2C device */
    I2C_APP_OPMODE_DMA,
    /**< DMA mode of I2C device */
    I2C_APP_OPMODE_MAX = I2C_APP_OPMODE_DMA,
    /**< Max Operational mode type of the I2C device */
}i2cAppOpMode_t;

typedef struct i2cAppIntrCfgObj
{
    intcTrigType_t intrTrigType;
    /**< Type of interrupt Edge/Level. */
    uint32_t intrLine;
    /**< Interrupt line number. */
    uint32_t intrPriority;
    /**< Interrupt priority level. */
    uint32_t isIntrSecure;
    /**< Secure Interrupt or not */
    void (*pFnIntrHandler)(uint32_t intrId, uint32_t cpuId, void* pUserParam);
    /**< Function pointer to Interrupt handler which needs to be
     *  registered with the interrupt Controller.- Application needs
     *  to initialize this. If set to null then polling Mode is assumed
     */
}i2cAppIntrCfgObj_t;

/** \brief Structure holding I2C device configuration parameters. */
typedef struct i2cAppDevCfg
{
    uint32_t            busSpeed;
    /**< I2C Bus Speed in kHz. */
    i2cAddrMode_t       addrMode;
    /**< Addressing mode to be configured for the device. */
    i2cAppOpMode_t      opMode;
    /**< Operational mode to be configured for the device. */
    uint32_t            txThreshold;
    /**< Transmit FIFO threshold configuration. */
    uint32_t            rxThreshold;
    /**< Receive FIFO threshold configuration. */
}i2cAppDevCfg_t;

/** \brief Structure holding I2C device Object parameters. */
typedef struct i2cAppCfgObj
{
    uint32_t       i2cInstNum;
    /**< i2c instance number. */
    uint32_t       i2cBaseAddr;
    /**< i2c instance base address. */
    uint32_t       slaveAddr;
    /**< Slave Address of the Part to be accessed */
    i2cAppDevCfg_t i2cAppDevCfg;
    /**< I2C device configuration params structure */
    i2cAppIntrCfgObj_t i2cAppIntrCfg;
    /**< I2C interrupt Configuration Structure */
}i2cAppCfgObj_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief  Initializes the I2C controller with the configuration
 *         like BusSpeed, Address Mode, Fifo Configuration
 *         passed to by the application.
 *
 * \param   pI2cConfig    Pointer to the I2C configuration object
 *                        holding different configurable parameters
 *                        like BusSpeed, AddressMode, Operational mode
 *
 * \retval  S_PASS on Successful Initialization
 * \retval  E_TIMEOUT when timeout occurs during the Controller Initalization
 * \retval  E_INVALID_PARAM on invalid parameters
 */
int32_t I2CAppCtrlInit(i2cAppCfgObj_t *pI2cConfig);

/**
 * \brief  Initializes the Pinmux and Module Clock for the instance.
 *
 * \param   pI2cConfig    Pointer to the I2C configuration object.
 *
 * \retval  S_PASS on Successful Initialization
 * \retval  E_INVALID_PARAM on invalid parameters
 */
int32_t I2CAppModuleInit(i2cAppCfgObj_t  *pI2cConfig);

/**
 * \brief  Provides the Raw Read functionality of the I2C for the
 *         particular instance as per the I2C configuration.
 *
 * \param  pI2cCtrlCfg  Pointer to the Application configuration object
 * \param  pData        Pointer to the Data buffer where the data is to be stored.
 * \param  dataCount    Length of the data to be read from the device.
 *
 * \retval  S_PASS on success
 * \retval  E_I2C_NAK_ERR    when master does not receive slave Acknowledge.
 * \retval  E_TIMEOUT        when timeout occurs during Read operation.
 */
int32_t I2CAppRead(i2cAppCfgObj_t *pI2cCtrlCfg, uint8_t *pData,
                    uint32_t dataCount);

/**
 * \brief  Provides the Raw Write functionality of the I2C for the
 *         particular instance as per the I2C configuration.
 *
 * \param  pI2cCtrlCfg  Pointer to the Application configuration object
 * \param  pData        Pointer to the Data buffer from where the data is to be written.
 * \param  dataCount    Length of the data to be read from the device.
 *
 * \retval  S_PASS on success.
 * \retval  E_I2C_NAK_ERR    when master does not receive slave Acknowledge.
 * \retval  E_TIMEOUT        when timeout occurs during Read operation.
 */
int32_t I2CAppWrite(i2cAppCfgObj_t *pI2cCtrlCfg, uint8_t *pData,
                    uint32_t dataCount);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef i2c_APP_H_ */
