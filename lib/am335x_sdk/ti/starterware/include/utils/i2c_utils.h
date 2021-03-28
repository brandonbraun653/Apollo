/**
 *  \file  i2c_utils.h
 *
 *  \brief This file provides the API prototypes used by the i2cUtils.
 *         These APIs shall provide a common interface to perform
 *         Initialization, Read and Write Operations using I2C protocol.
 *         The functions defined here are non re-entrant and need to be
 *         modified to be integrated with an RTOS.
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

#ifndef I2CUTILS_H_
#define I2CUTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Macro for I2C Standard Mode Speed in kHz. */
#define I2C_UTILS_STDMODE_SPEED                                  (100U)
/** \brief Macro for I2C Fast Mode Speed in kHz */
#define I2C_UTILS_FASTMODE_SPEED                                 (400U)
/** \brief Default FIFO threshold value */
#define I2C_UTILS_FIFO_THRSHLD_ZERO                              (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Enumerates the types of Operational modes supported
 *         for I2C Operations.
 */
typedef enum i2cUtilsOperMode
{
    I2C_UTILS_OPERMODE_MIN =  0U,
    /**< Min Operational mode type of the I2C device */
    I2C_UTILS_OPERMODE_POLLING = I2C_UTILS_OPERMODE_MIN,
    /**< Polling mode of the I2C device */
    I2C_UTILS_OPERMODE_INTERRUPT,
    /**< Interrupt mode of I2C device */
    I2C_UTILS_OPERMODE_DMA,
    /**< DMA mode of I2C device */
    I2C_UTILS_OPERMODE_MAX = I2C_UTILS_OPERMODE_DMA,
    /**< Max Operational mode type of the I2C device */
}i2cUtilsOperMode_t;

/**
 *  \brief Enumerates the types of Addressing modes supported.
 */
typedef enum i2cUtilsAddrMode
{
    I2C_UTILS_ADDRMODE_MIN = 0U,
    /**< Min Addressing mode of the I2C device */
    I2C_UTILS_ADDRMODE_7BIT = I2C_UTILS_ADDRMODE_MIN,
    /**< 7-bit Addressing mode of the I2C Slave device */
    I2C_UTILS_ADDRMODE_10BIT,
    /**< 10-bit Addressing mode of the I2C Slave device */
    I2C_UTILS_ADDRMODE_MAX = I2C_UTILS_ADDRMODE_10BIT,
    /**< Max Addressing Type of the I2C Slave device */
}i2cUtilsAddrMode_t;

/**
 *  \brief structure defining the parameters required for
 *         i2c Read and Write operations. The parameters are to
 *         be passed by the Application.
 */
typedef struct i2cUtilsTxRxParams
{
    uint32_t             slaveAddr;
    /**< Slave Address of the Part to be accessed */
    uint8_t              *pOffset;
    /**< The offset from where to read/write from the device */
    uint32_t             offsetSize;
    /**< The size of the offset value passed */
    uint32_t             bufLen;
    /**< Length of the buffer passed */
    uint8_t              *pBuffer;
    /**< pointer to a buffer to hold the data */
}i2cUtilsTxRxParams_t;

/**
 *  \brief structure defining the parameters required for
 *         initializing the i2c instance.
 */
typedef struct i2cUtilsInitParams
{
    uint32_t              busSpeed;
    /**< I2C Bus Speed in kHz. */
    i2cUtilsAddrMode_t    addrMode;
    /**< Addressing mode to be configured for the device. */
    i2cUtilsOperMode_t    operMode;
    /**< Operational mode to be configured for the device. */
    uint32_t              txThreshold;
    /**< Transmit FIFO threshold configuration. */
    uint32_t              rxThreshold;
    /**< Receive FIFO threshold configuration. */
}i2cUtilsInitParams_t;


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief Variable to initialize the InitParams with default values. */
extern const i2cUtilsInitParams_t I2CUTILSINITPARAMS_DEFAULT;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief   Initializes the I2C instance with different parameters to enable
 *           the I2C instance for Read/Write operation. When this function is
 *           called it configures the Clock, sets the BusSpeed, Addressing Mode
 *           and other parameters for the particular I2C instance based on
 *           the parameters passed by the User. Depending upon the operational
 *           mode selected the interrupt related or the DMA configuration
 *           is carried out.
 *
 *  \param   instId         Instance number of the I2C controller
 *  \param   pUserParams    pointer to a structure containing parameters
 *                          for initializing the instance.
 *
 *  \retval  S_PASS on successful initialization.
 *  \retval  E_FAIL on failure to initialize the controller.
 *  \retval  E_INST_NOT_SUPP on invalid instance number.
 *  \retval  E_INVALID_PARAM on invalid parameters.
 *  \retval  E_MODE_NOT_SUPP on mode which is not supported.
 */
int32_t I2CUtilsInit(uint32_t instId, i2cUtilsInitParams_t *pUserParams);

/**
 *  \brief   Provides Read functionality of the I2C for the
 *           selected I2C instance using any of the selected
 *           Operational Modes like interrupt, Polling and DMA,
 *           The slave device related information like slave Address,
 *           dataCount are passed by the application.
 *
 *  \param   instId        Instance number of the I2C controller
 *  \param   pRxParams     pointer to a structure containing parameters
 *                         required for Read operation like
 *                         - Slave Address
 *                         - Data Count
 *  \param   timeoutValue  time-out value in milli-seconds for the Read/Write
 *                         operation to avoid Blocking on Read Write Call,
 *                         the value to be passed by the application.
 *
 *  \retval  S_PASS on success.
 *  \retval  E_TIMEOUT        when timeout occurs during Read operation.
 *  \retval  E_INST_NOT_SUPP  on invalid instance number.
 *  \retval  E_INST_NOT_UP    when the instance is not initialized.
 *  \retval  E_I2C_NAK_ERR    when slave does not acknowledge.
 */
int32_t I2CUtilsRead(uint32_t instId, i2cUtilsTxRxParams_t *pRxParams,
                       uint32_t timeoutValue);

/**
 *  \brief   Provides Write functionality of the I2C for the
 *           selected I2C instance using any of the selected
 *           Operational Modes like interrupt, Polling and DMA.
 *
 *  \param   instId        Instance number of the I2C controller
 *  \param   pTxParams     pointer to a structure containing parameters
 *                         required for Write operation like
 *                         - Slave Address
 *                         - Data Count
 *  \param   timeoutValue  time-out value in milli-seconds for the Read/Write
 *                         operation to avoid Blocking on Read Write Call,
 *                         the value to be passed by the application.
 *
 *  \retval  S_PASS on success.
 *  \retval  E_TIMEOUT        when timeout occurs during Read operation.
 *  \retval  E_INST_NOT_SUPP  on invalid instance number.
 *  \retval  E_INST_NOT_UP    when the instance is not initialized.
 *  \retval  E_I2C_NAK_ERR    when master does not receive slave Acknowledge.
 *  \retval  E_BUF_OVERRUN    When the data to be written is more than what
 *                            the Transmit buffer can handle.
 *
 *  \note   The maximum data transfer length is 128 bytes. This is
 *          because the I2C data buffer has a maximum declared size
 *          of 128 bytes.
 */
int32_t I2CUtilsWrite(uint32_t instId, i2cUtilsTxRxParams_t *pTxParams,
                        uint32_t timeoutValue);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef I2CUTILS_H_ */
