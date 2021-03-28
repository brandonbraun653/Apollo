/**
 *  \file  i2c_utils.c
 *
 *  \brief This file contains I2C Utils functional APIs which provide
 *         a common interface for application to perform any I2C
 *         related operations in master mode. The APIs defined
 *         here are not re-entrant. These Utils allow user to
 *         Communicate with the I2C device in Master mode only,
 *         Slave mode communication is not supported. Multi-Master
 *         mode of I2C is not part of this Utils.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <string.h>
#include "types.h"
#include "hw_types.h"
#include "i2c_utils.h"
#include "chipdb.h"
#include "i2c.h"
#include "error.h"
#include "misc.h"
#if defined(AM335X_FAMILY_BUILD)
#include "soc_am335x.h"
#include "hw_control_am335x.h"
#include "hw_cm_wkup.h"
#include "hw_cm_per.h"
#elif defined(AM43XX_FAMILY_BUILD)
#include "am437x.h"
#include "hw_control_am43xx.h"
#include "hw_cm_wkup.h"
#include "hw_cm_per.h"
#endif /* if defined(AM335x_FAMILY_BUILD) */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Maximum number of I2C instance supported. */
#define I2C_UTILS_INSTANCE_MAX                                   (3U)

/** \brief Maximum Bus Speed in kHz supported by the I2C Controller */
#define I2C_UTILS_BUSSPEED_MAX                                   (400U)

/** \brief System Clock used by the I2C module */
#define I2C_UTILS_SYS_CLK                                       (48000000U)

/** \brief Internal Clock used by the I2C module */
#define I2C_UTILS_INT_CLK                                       (24000000U)

/** \brief Size of the Transmit and Receive FIFO of the I2C Controller */
#define I2C_UTILS_FIFO_DEPTH                                     (32U)

/** \brief Flag to configure the I2C Controller in receive mode */
#define I2C_UTILS_MASTER_RECEIVE                                  (1U)

/** \brief Flag to configure the I2C Controller in transmit mode */
#define I2C_UTILS_MASTER_TRANSMIT                                 (2U)

/** \brief Flag to indicate the START condition */
#define I2C_UTILS_START                                           (4U)

/** \brief Flag to indicate the STOP condition */
#define I2C_UTILS_STOP                                            (8U)

/** \brief Flag to transmit the offset  */
#define I2C_UTILS_OFFSET_TX                                       (16U)

/** \brief Macro defining the Transmit Buffer size. */
#define I2C_UTILS_TX_BUF_SIZE                                     (128U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief structure defining the I2C device object parameters. */
typedef struct i2cUtilsObj
{
    int16_t                   isInit;
    /**< Initialization state of the I2C instance */
    i2cUtilsInitParams_t      i2cInitParams;
    /**< Structure storing the Initialization parameters */
    i2cUtilsTxRxParams_t      i2cTxRxParams;
    /**< Structure storing the I2C transfer related parameters */
    uint32_t                  baseAddr;
    /**< BaseAddress of the I2C device. */
    i2cUtilsOperMode_t        instOperMode;
    /**<Current Operational mode configured */
    int32_t                   statusFlag;
    /**< Flag to verify the status of I2C Operation */
}i2cUtilsObj_t;

/* ========================================================================== */
/*                     Internal Function Declarations                         */
/* ========================================================================== */

/**
 *  \brief   A function to resolve the baseAddress of the device
 *           as per the I2C device instance.
 *
 *  \param   pI2cDevObj pointer to the structure which has to
 *                      be used to resolve the baseAddresses.
 *  \param   instId     Instance number of the I2C controller
 *
 *  \retval  S_PASS on success.
 *  \retval  E_INST_NOT_SUPP on invalid instance number.
 */
static void I2cUtilsUpdateInfo(uint32_t instId,
                                    i2cUtilsObj_t *pI2cDevObj);
/**
 *  \brief   Configures the PinMux configuration for the given I2C instance.
 *
 *  \param   instNum    instance number of the I2C device.
 *
 *  \status  S_PASS     If the Pinmux is successful.
 *  \status  E_INST_NOT_SUPP If the instance is not supported.
 */
static int32_t I2cUtilsPinmuxConfig(uint32_t instNum);

/**
 *  \brief   Configures the Module clock for the selected I2C instance.
 *
 *  \param   instNum    instance number of the I2C device.
 *
 *  \status  S_PASS     If the Clock configuration is successful.
 *  \status  E_INST_NOT_SUPP If the instance is not supported.
 */
static int32_t I2cUtilsModuleClockConfig(uint32_t instNum);

/**
 *  \brief   Validates the parameters passed by the user
 *           to configure the I2C Controller
 *
 *  \param   pConfigParams   pointer to the user Config structure.
 *
 *  \retval  S_PASS on success.
 *  \retval  E_INVALID_PARAM on invalid parameter.
 */
static int32_t I2cUtilsParamsValidate(i2cUtilsInitParams_t *pConfigParams);

/**
 *  \brief   Initializes the I2C Controller with the user passed
 *           parameters.
 *
 *  \param   pConfigParams   pointer to the user Config structure.
 *
 *  \retval  S_PASS on success.
 *  \retval  E_INVALID_PARAM on invalid parameter.
 */
static int32_t I2cUtilsCtrlInit(i2cUtilsObj_t *pCtrlConfig);

/**
 *  \brief   I2C Transfer function which provides a common interface to
 *           perform read write operations through the I2C Controller.
 *
 *  \param   instObj        pointer to the I2C device structure
 *  \param   i2cXferFlags   flags to indicate the type of I2C operation.
 *  \param   timeoutValue   timeoutValue in milli-seconds to avoid blocking
 *                          call.
 *
 *  \retval  S_PASS on success.
 *  \retval  E_I2C_NAK_ERR    when slave does not acknowledge.
 */
static int32_t I2cUtilsTransceive(i2cUtilsObj_t *instObj,
                                uint32_t i2cXferFlags, uint32_t timeoutValue);

/**
 *  \brief   Status check function which polls the status of the I2C device
 *           along with a timeout value.
 *
 *  \param   instObj        pointer to the I2C device structure
 *  \param   flag           flag to indicate which status flag to monitor
 *  \param   timeout        timeout value passed
 *  \param   pTimeoutStatus  pointer to indicate the timeout status
 *
 *  \retval  status of the flag which is polled.
 */
static uint32_t I2cUtilsStatusCheck(i2cUtilsObj_t *instObj,
                                    uint32_t flag, uint32_t timeout,
                                    uint8_t *pTimeoutStatus);

/**
 *  \brief   Configures the PinMux for the I2C Controller.
 *
 *  \param   instId   Instance number of the controller.
 *
 */
void I2cUtilsPinMuxSetup(unsigned int instId);

/**
 *  \brief   Initializes the I2C1 Module Clock.
 *
 */
void I2C1ModuleClkConfig(void);

/**
 *  \brief   Initialized the I2C0 module clock.
 *
 */
void I2C0ModuleClkConfig(void);

/**
 *  \brief   Confiures the I2C2 module clock.
 *
 */
void I2C2ModuleClkConfig(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief  I2C Controller Object array for Max number of instances. */
static i2cUtilsObj_t gI2CUtilsObj[I2C_UTILS_INSTANCE_MAX] =
{
    {FALSE},  /* isInit */
    {FALSE},  /* isInit */
    {FALSE}   /* isInit */
};

const i2cUtilsInitParams_t I2CUTILSINITPARAMS_DEFAULT ={
    I2C_UTILS_STDMODE_SPEED, /* busSpeed */
    I2C_UTILS_ADDRMODE_7BIT, /* addrMode */
    I2C_UTILS_OPERMODE_POLLING, /* operMode */
    I2C_UTILS_FIFO_THRSHLD_ZERO, /* txThreshold */
    I2C_UTILS_FIFO_THRSHLD_ZERO  /* rxThreshold */
};


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t I2CUtilsInit(uint32_t instId, i2cUtilsInitParams_t *pUserParams)
{
    int32_t status = S_PASS;

    /* Validate the Instance */
    if(instId > I2C_UTILS_INSTANCE_MAX)
    {
        status = E_INST_NOT_SUPP;
    }
    else
    {
        /* Validate the user passed parameters. */
        status = I2cUtilsParamsValidate(pUserParams);
    }

    /*
    ** If user params are valid and I2C device is not initialized before
    ** do the PinMux and Clock Configuration.
    */
    if (S_PASS == status && FALSE == gI2CUtilsObj[instId].isInit)
    {
        /* Resolve the Base Address */
        I2cUtilsUpdateInfo(instId, &gI2CUtilsObj[instId]);

        /* Perform the PinMux */
        status = I2cUtilsPinmuxConfig(instId);

        if(S_PASS == status)
        {
            /* Set the Module Clock */
            status = I2cUtilsModuleClockConfig(instId);
        }
    }

    if (S_PASS == status)
    {
        /* Assign the initialization parameters to the I2C Object */
        gI2CUtilsObj[instId].i2cInitParams.busSpeed = pUserParams->busSpeed;
        gI2CUtilsObj[instId].i2cInitParams.addrMode = pUserParams->addrMode;
        gI2CUtilsObj[instId].i2cInitParams.operMode = pUserParams->operMode;
        gI2CUtilsObj[instId].i2cInitParams.txThreshold =
                                             pUserParams->txThreshold;
        gI2CUtilsObj[instId].i2cInitParams.rxThreshold =
                                             pUserParams->rxThreshold;

        /* Initialize the Controller */
        status = I2cUtilsCtrlInit(&gI2CUtilsObj[instId]);

        if(S_PASS == status)
        {
            gI2CUtilsObj[instId].isInit = TRUE;
        }
    }

    return status;
}

int32_t I2CUtilsWrite(uint32_t instId, i2cUtilsTxRxParams_t *pTxParams,
                        uint32_t timeoutValue)
{
    int32_t status = S_PASS;
    uint32_t dataLen = pTxParams->offsetSize + pTxParams->bufLen;
    uint8_t txBuf[I2C_UTILS_TX_BUF_SIZE];
    uint8_t *pBuf = txBuf;

    if(dataLen > I2C_UTILS_TX_BUF_SIZE)
    {
        status = E_BUF_OVERRUN;
    }
    else
    {
        /* Copy the offset and data to be transmitted into a single buffer. */
        memcpy(pBuf, pTxParams->pOffset, pTxParams->offsetSize);
        pBuf += pTxParams->offsetSize;

        memcpy(pBuf, pTxParams->pBuffer, pTxParams->bufLen);

        /* Validate the parameters */
        if(instId > I2C_UTILS_INSTANCE_MAX)
        {
            status = E_INST_NOT_SUPP;
        }
        else if(FALSE == gI2CUtilsObj[instId].isInit)
        {
            status = E_NOT_INITIALIZED;
        }
        else if(NULL == pTxParams)
        {
            status = E_INVALID_PARAM;
        }
        else
        {
            /* Initialize the Transmit Parameters to the I2C Object */
            gI2CUtilsObj[instId].i2cTxRxParams.slaveAddr = pTxParams->slaveAddr;
            gI2CUtilsObj[instId].i2cTxRxParams.bufLen = dataLen;
            gI2CUtilsObj[instId].i2cTxRxParams.pBuffer = txBuf;

            /*
            ** Call the I2C Transceive function to transmit the data to be
            ** written to the I2C slave device.
            */
            status = I2cUtilsTransceive(&gI2CUtilsObj[instId],
                            (I2C_UTILS_MASTER_TRANSMIT | I2C_UTILS_START |
                             I2C_UTILS_STOP), timeoutValue);
        }
    }

    return status;
}

int32_t I2CUtilsRead(uint32_t instId, i2cUtilsTxRxParams_t *pRxParams,
                       uint32_t timeoutValue)
{
    int32_t status = S_PASS;

    /* Validate the parameters */
    if(instId > I2C_UTILS_INSTANCE_MAX)
    {
        status = E_INST_NOT_SUPP;
    }

    else if(FALSE == gI2CUtilsObj[instId].isInit)
    {
        status = E_NOT_INITIALIZED;
    }

    else if(NULL == pRxParams)
    {
        status = E_INVALID_PARAM;
    }
    else
    {
        /* Initialize the Receive Parameters to the I2C Object */
        gI2CUtilsObj[instId].i2cTxRxParams.slaveAddr = pRxParams->slaveAddr;
        gI2CUtilsObj[instId].i2cTxRxParams.pOffset = pRxParams->pOffset;
        gI2CUtilsObj[instId].i2cTxRxParams.offsetSize = pRxParams->offsetSize;
        gI2CUtilsObj[instId].i2cTxRxParams.bufLen = pRxParams->bufLen;
        gI2CUtilsObj[instId].i2cTxRxParams.pBuffer = pRxParams->pBuffer;

        /*
        ** Call the I2C Transceive function for write operation to transmit the
        ** Offset value.
        */
        status = I2cUtilsTransceive(&gI2CUtilsObj[instId],
                      (I2C_UTILS_MASTER_TRANSMIT | I2C_UTILS_START |
                            I2C_UTILS_OFFSET_TX | I2C_UTILS_STOP),
                              timeoutValue);
        if(S_PASS == status)
        {
            /*
            ** Call the transceive function to read the Data from
            ** the I2C device.
            */
            status = I2cUtilsTransceive(&gI2CUtilsObj[instId],
                        (I2C_UTILS_MASTER_RECEIVE | I2C_UTILS_START |
                         I2C_UTILS_STOP), timeoutValue);
        }
    }
    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t I2cUtilsCtrlInit(i2cUtilsObj_t *pCtrlConfig)
{
    uint32_t delay = 0x7FFF;
    int32_t status = S_PASS;
    uint32_t busFrequency;

    /* Put i2c in reset/disabled state */
    I2CModuleEnable(pCtrlConfig->baseAddr, FALSE);

    /* Do a Soft reset of the module */
    I2CSoftReset(pCtrlConfig->baseAddr);

    /* Disable Auto-Idle functionality. */
    I2CAutoIdleEnable(pCtrlConfig->baseAddr, TRUE);

    /* Configure i2c bus speed*/
    busFrequency = (pCtrlConfig->i2cInitParams.busSpeed * FREQ_KHZ);

    I2CMasterInitExpClk(pCtrlConfig->baseAddr, I2C_UTILS_SYS_CLK,
                        I2C_UTILS_INT_CLK, busFrequency);

    /*Set Rx and Tx FIFO threshold value and reset the fifo*/
    I2CFIFOThresholdConfig(pCtrlConfig->baseAddr,
                           pCtrlConfig->i2cInitParams.txThreshold,
                           I2C_FIFO_TX);

    I2CFIFOThresholdConfig(pCtrlConfig->baseAddr,
                           pCtrlConfig->i2cInitParams.rxThreshold,
                           I2C_FIFO_RX);

    /* Disable all I2C interrupts */
    I2CIntrDisable(pCtrlConfig->baseAddr, I2C_INTR_ALL);

    /* Take the I2C module out of reset: */
    I2CModuleEnable(pCtrlConfig->baseAddr, TRUE);

     /* Wait for the reset to get complete */
    while ((0U == I2CSystemStatusGet(pCtrlConfig->baseAddr)) && delay)
    {
        /* TODO need to integrate with the timer APIs */
        delay--;
    }

    if (0U == delay )
    {
        /* Soft reset has failed */
        status = E_TIMEOUT;
    }

    return status;
}

static int32_t I2cUtilsTransceive(i2cUtilsObj_t *instObj,
                                uint32_t i2cXferFlags, uint32_t timeoutValue)
{
    int32_t  dataCount = 0U;
    uint8_t  fifoThreshold = 0U, buflen = 0U;
    uint8_t  timeoutStatus = 0U;
    uint32_t flag = 0U;
    uint32_t devStatus = 0U;
    uint32_t remainingBytes = 0U;
    uint8_t  dataByte = 0U;
    uint8_t  *pBuf = NULL;
    int32_t status = S_PASS;

    /* Write the slave address */
    I2CMasterSlaveAddrSet(instObj->baseAddr,
                            instObj->i2cTxRxParams.slaveAddr,
                             instObj->i2cInitParams.addrMode);

    /* Pass the offset and its size before the actual Transaction */
    if (i2cXferFlags & I2C_UTILS_OFFSET_TX)
    {
        /*Configure offset size and length*/
        I2CSetDataCount(instObj->baseAddr, instObj->i2cTxRxParams.offsetSize);
        pBuf = (uint8_t *) (instObj->i2cTxRxParams.pOffset);
    }
    else
    {
        /*Configure data buffer length*/
        I2CSetDataCount(instObj->baseAddr, instObj->i2cTxRxParams.bufLen);
        pBuf = instObj->i2cTxRxParams.pBuffer;
    }

    /* Clear all the Interrupt Raw status register */
    I2CIntrClear(instObj->baseAddr, I2C_INTR_ALL);

    /* Configure the Controller in Master Receiver mode */
    if (i2cXferFlags & I2C_UTILS_MASTER_RECEIVE)
    {
        I2CSetMode(instObj->baseAddr, I2C_MODE_MASTER_RX);
    }

    /* Configure the Controller in Master Transmit mode */
    if (i2cXferFlags & I2C_UTILS_MASTER_TRANSMIT)
    {
        I2CSetMode(instObj->baseAddr, I2C_MODE_MASTER_TX);
    }

    /* Configure Controller to generate START condition */
    if (i2cXferFlags & I2C_UTILS_START)
    {
        I2CMasterStart(instObj->baseAddr);
    }

    dataCount = I2CDataCountGet(instObj->baseAddr);

    if (I2C_UTILS_OPERMODE_POLLING == instObj->i2cInitParams.operMode)
    {
        if ( i2cXferFlags & I2C_UTILS_MASTER_TRANSMIT)
        {
            /* Begin to Transmit */
            while(buflen < dataCount)
            {
                flag   = I2C_INTR_TX_READY | I2C_INTR_TX_DRAIN;

                devStatus = I2cUtilsStatusCheck(instObj, flag, timeoutValue,
                                       &timeoutStatus);
                if (0U == timeoutStatus)
                {
                    if(devStatus &
                        (I2C_INTR_TX_READY | I2C_INTR_TX_DRAIN))
                    {
                        if (devStatus & I2C_INTR_TX_READY)
                        {
                            /*Clear other interrupts*/
                            flag = I2C_INTR_TX_READY;

                            I2CIntrClear(instObj->baseAddr,
                                                (devStatus & ~flag));

                            for (fifoThreshold = 0;
                                 fifoThreshold < (instObj->i2cInitParams.
                                 txThreshold + 1); fifoThreshold++)
                            {
                                dataByte = *pBuf++;
                                /*transmit byte of data*/
                                I2CMasterDataPut(instObj->baseAddr, dataByte);

                                /*Check for status*/
                                devStatus = I2CMasterIntRawStatus(instObj->baseAddr);

                                /*check nack status*/
                                if (devStatus & I2C_INTR_NO_ACK)
                                {
                                    status = E_I2C_NAK_ERR;
                                    break;
                                }
                                buflen++;
                            }

                            /*Clear transmit ready interrupt*/
                            I2CIntrClear(instObj->baseAddr, (devStatus & flag));
                        }

                         /* If data is not a multiple of fifo threshold */
                        if (devStatus & I2C_INTR_TX_DRAIN)
                        {
                            /*Clear other interrupts*/
                            flag = I2C_INTR_TX_DRAIN;

                            I2CIntrClear(instObj->baseAddr,
                                                (devStatus & ~flag));

                            remainingBytes = I2CBufferStatus(
                                instObj->baseAddr, I2C_FIFO_TX);

                            while(remainingBytes > 0)
                            {
                                dataByte = *pBuf++;
                                /*transmit byte of data*/
                                I2CMasterDataPut(instObj->baseAddr, dataByte);

                                /*Check for status*/
                                devStatus = I2CMasterIntRawStatus(instObj->baseAddr);

                                /*check nack status*/
                                if (devStatus & I2C_INTR_NO_ACK)
                                {
                                    status = E_I2C_NAK_ERR;
                                    break;
                                }

                                remainingBytes--;
                                buflen++;
                            }

                            I2CIntrClear(instObj->baseAddr,
                                                (devStatus & flag));
                        }
                    }
                    else
                    {
                        /*Check for status*/
                        devStatus = I2CMasterIntRawStatus(instObj->baseAddr);

                        /*check nack status*/
                        if (devStatus & I2C_INTR_NO_ACK)
                        {
                            status = E_I2C_NAK_ERR;
                            break;
                        }
                    }
                }
                else
                {
                    status = E_TIMEOUT;
                    break;
                }
            }
        }
            else
            {
                /* Start Receive from the Slave device */
                while(buflen < dataCount)
                {
                    flag   = I2C_INTR_RX_READY | I2C_INTR_RX_DRAIN;

                    devStatus = I2cUtilsStatusCheck(instObj, flag, timeoutValue,
                                                  &timeoutStatus);
                    if (0U == timeoutStatus)
                    {
                        if ((devStatus) &
                              (I2C_INTR_RX_READY | I2C_INTR_RX_DRAIN))
                        {
                            if (devStatus & I2C_INTR_RX_READY)
                            {
                                flag = I2C_INTR_RX_READY;

                                /*Clear other interrupts*/
                                I2CIntrClear(instObj->baseAddr,
                                                    (devStatus & ~flag));

                                for (fifoThreshold = 0;
                                     fifoThreshold < (instObj->i2cInitParams.
                                     rxThreshold + 1);
                                     fifoThreshold++)
                                {
                                    /*
                                    ** Receive each byte of data from the
                                    ** device
                                    */
                                    dataByte =
                                            I2CMasterDataGet(instObj->baseAddr);
                                    *pBuf++ = dataByte;

                                    /*Check for status*/
                                    devStatus = I2CMasterIntRawStatus
                                                    (instObj->baseAddr);

                                    /* check nack status */
                                    if (devStatus & I2C_INTR_NO_ACK)
                                    {
                                        status = E_I2C_NAK_ERR;
                                        break;
                                    }
                                    buflen++;
                                }

                                /*Clear receive ready interrupt*/
                                I2CIntrClear(instObj->baseAddr,
                                                    (devStatus & flag));
                            }
                            /* If data is not a multiple of fifo threshold */
                            if (devStatus & I2C_INTR_RX_DRAIN)
                            {
                                flag = I2C_INTR_RX_DRAIN;

                                /* Clear other interrupts */
                                I2CIntrClear(instObj->baseAddr,
                                                    (devStatus & ~flag));

                                remainingBytes = I2CBufferStatus(
                                    instObj->baseAddr, I2C_FIFO_RX);

                                while(remainingBytes > 0)
                                {
                                    /*Receive byte of data*/
                                    dataByte = I2CMasterDataGet(instObj->baseAddr);
                                    *pBuf++ = dataByte;

                                    /*Check for status*/
                                    devStatus = I2CMasterIntRawStatus(
                                        instObj->baseAddr);

                                    /*check nack status*/
                                    if (devStatus & I2C_INTR_NO_ACK)
                                    {
                                        status = E_I2C_NAK_ERR;
                                        break;
                                    }

                                    remainingBytes--;
                                    buflen++;
                                }
                                /*Clear receive ready interrupt*/
                                I2CIntrClear(instObj->baseAddr,
                                                    (devStatus & flag));
                            }
                        }
                        else
                        {
                            /*Check for status*/
                            devStatus = I2CMasterIntRawStatus(instObj->baseAddr);

                            /*check nack status*/
                            if (devStatus & I2C_INTR_NO_ACK)
                            {
                                status = E_I2C_NAK_ERR;
                                break;
                            }
                        }
                    }
                    else
                    {
                        status = E_TIMEOUT;
                        break;
                    }
                }
            }

        if ((i2cXferFlags & I2C_UTILS_STOP) || (S_PASS != status))
        {
            /*Wait till bus can be accessed*/
            flag   = I2C_INTR_REG_ACESS_RDY;
            devStatus = I2cUtilsStatusCheck(instObj, flag, timeoutValue,
                                          &timeoutStatus);

            /* Enable the stop condition */
            I2CMasterStop(instObj->baseAddr);

            /*Wait till bus can be accessed*/
            flag   = I2C_INTR_STOP_CONDITION;
            devStatus = I2cUtilsStatusCheck(instObj, flag, timeoutValue,
                                          &timeoutStatus);

            /*Flush FIFO*/
            I2CFIFOClear(instObj->baseAddr, (I2C_FIFO_TX | I2C_FIFO_RX));

            /*Clear all interrupt status*/
            I2CIntrClear(instObj->baseAddr, I2C_INTR_ALL);

            /*Clear data buffer length*/
            I2CSetDataCount(instObj->baseAddr, 0U);
        }
    }
    else
    {
        /* Support for Interrupt and DMA mode will be added later */
        status = E_MODE_NOT_SUPP;
    }
    return status;
}

static uint32_t I2cUtilsStatusCheck(i2cUtilsObj_t *instObj,
                                    uint32_t flag, uint32_t timeout,
                                    uint8_t *pTimeoutStatus)
{
    uint32_t          status;

    volatile uint32_t pinTimeout = timeout;
    *pTimeoutStatus = 0;

    status = I2CMasterIntRawStatus(instObj->baseAddr);

    while (!(status & flag) && pinTimeout)
    {
        status = I2CMasterIntRawStatus(instObj->baseAddr);
        pinTimeout--;
    }

    if (timeout)
    {
        if (pinTimeout == 0U)
        {
            *pTimeoutStatus = 1;
            I2CIntrClear(instObj->baseAddr, I2C_INTR_ALL);
        }
    }

    return status;
}

static int32_t I2cUtilsPinmuxConfig(uint32_t instId)
{
    int32_t status = S_PASS;

   #if defined(AM335X_FAMILY_BUILD)
    if(0U == instId)
    {
         HW_WR_REG32((SOC_CONTROL_REGS + CTRL_CONF_I2C0_SDA),
                (CONTROL_CONF_I2C0_SDA_CONF_I2C0_SDA_RXACTIVE  |
                 CONTROL_CONF_I2C0_SDA_CONF_I2C0_SDA_SLEWCTRL  |
                 CONTROL_CONF_I2C0_SDA_CONF_I2C0_SDA_PUTYPESEL));

         HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_CONF_I2C0_SCL),
                (CONTROL_CONF_I2C0_SCL_CONF_I2C0_SCL_RXACTIVE  |
                 CONTROL_CONF_I2C0_SCL_CONF_I2C0_SCL_SLEWCTRL  |
                 CONTROL_CONF_I2C0_SCL_CONF_I2C0_SCL_PUTYPESEL));

    }
    else if(1U == instId)
    {
                               /* I2C_SCLK */
        HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_CONF_SPI0_D1),
             (CONTROL_CONF_SPI0_D1_CONF_SPI0_D1_PUTYPESEL |
              CONTROL_CONF_SPI0_D1_CONF_SPI0_D1_RXACTIVE  |
              CONTROL_CONF_SPI0_D1_CONF_SPI0_D1_SLEWCTRL  |
              CONTROL_CONF_MUXMODE(2)));
                              /* I2C_SDA */
        HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_CONF_SPI0_CS0),
             (CONTROL_CONF_SPI0_CS0_CONF_SPI0_CS0_PUTYPESEL |
              CONTROL_CONF_SPI0_CS0_CONF_SPI0_CS0_RXACTIVE  |
              CONTROL_CONF_SPI0_D1_CONF_SPI0_D1_SLEWCTRL    |
              CONTROL_CONF_MUXMODE(2)));

    }
    else if(2U == instId)
    {
        HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_CONF_UART_RTSN(1)),
             (CONTROL_CONF_UART1_RTSN_CONF_UART1_RTSN_PUTYPESEL |
              CONTROL_CONF_UART1_RTSN_CONF_UART1_RTSN_RXACTIVE  |
              CONTROL_CONF_UART1_RTSN_CONF_UART1_RTSN_SLEWCTRL  |
              CONTROL_CONF_MUXMODE(3)));

        HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_CONF_UART_CTSN(1)),
             (CONTROL_CONF_UART1_CTSN_CONF_UART1_CTSN_PUTYPESEL |
              CONTROL_CONF_UART1_CTSN_CONF_UART1_CTSN_RXACTIVE  |
              CONTROL_CONF_UART1_CTSN_CONF_UART1_CTSN_SLEWCTRL  |
              CONTROL_CONF_MUXMODE(3)));
    }
    else
    {
        status = E_INST_NOT_SUPP;
    }
#elif defined (AM43XX_FAMILY_BUILD)
    if(0U == instId)
    {
         HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_CONF_I2C0_SDA),
                (CTRL_CONF_I2C0_SDA_RXACTIVE_MASK  |
                 CTRL_CONF_I2C0_SDA_SLEWCTRL_MASK |
                 CTRL_CONF_I2C0_SDA_PUTYPESEL_MASK));

         HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_CONF_I2C0_SCL),
                (CTRL_CONF_I2C0_SCL_RXACTIVE_MASK |
                 CTRL_CONF_I2C0_SCL_SLEWCTRL_MASK |
                 CTRL_CONF_I2C0_SCL_PUTYPESEL_MASK));
    }
    else if(1U == instId)
    {
         HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_CONF_SPI0_CS0),
                (CTRL_CONF_I2C0_SDA_RXACTIVE_MASK  |
                 CTRL_CONF_I2C0_SDA_SLEWCTRL_MASK |
                 CTRL_CONF_I2C0_SDA_PUTYPESEL_MASK) |
                 CONTROL_CONF_MUXMODE(2));

         HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_CONF_SPI0_D1),
                (CTRL_CONF_I2C0_SCL_RXACTIVE_MASK |
                 CTRL_CONF_I2C0_SCL_SLEWCTRL_MASK |
                 CTRL_CONF_I2C0_SCL_PUTYPESEL_MASK) |
                 CONTROL_CONF_MUXMODE(2));
    }
    else if(2U == instId)
    {
        HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_CONF_UART1_RTSN),
                (CTRL_CONF_UART1_RTSN_RXACTIVE_MASK |
                 CTRL_CONF_UART1_RTSN_SLEWCTRL_MASK |
                 CTRL_CONF_UART1_RTSN_PUTYPESEL_MASK |
                 CONTROL_CONF_MUXMODE(3)));

         HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_CONF_UART1_CTSN),
                (CTRL_CONF_UART1_CTSN_RXACTIVE_MASK |
                 CTRL_CONF_UART1_CTSN_SLEWCTRL_MASK |
                 CTRL_CONF_UART1_CTSN_PUTYPESEL_MASK |
                 CONTROL_CONF_MUXMODE(3)));
    }
    else
    {
        status = E_INST_NOT_SUPP;
    }
#endif /* if defined(AM43XX_FAMILY_BUILD) */

    return status;
}


static int32_t I2cUtilsModuleClockConfig(uint32_t instId)
{
    int32_t status = S_PASS;

    if(0U == instId)
    {
        I2C0ModuleClkConfig();
    }
    else if(1U == instId)
    {
        I2C1ModuleClkConfig();
    }
    else if(2U == instId)
    {
        I2C2ModuleClkConfig();
    }
    else
    {
        status = E_INST_NOT_SUPP;
    }

    return status;
}

int32_t I2cUtilsParamsValidate(i2cUtilsInitParams_t *pConfigParams)
{
    int32_t status = S_PASS;

    /*
    ** Validate the User passed configuration parameters like
    ** Address Mode, Bus Speed, Fifo threshold & operational mode
    */
    if(NULL == pConfigParams)
    {
        status = E_INVALID_PARAM;
    }
    else if(pConfigParams->busSpeed > I2C_UTILS_BUSSPEED_MAX)
         {
             status = E_INVALID_PARAM;
         }
    else if((pConfigParams->addrMode < I2C_UTILS_ADDRMODE_MIN) ||
            (pConfigParams->addrMode > I2C_UTILS_ADDRMODE_MAX))
         {
             status = E_INVALID_PARAM;
         }
    else if((pConfigParams->operMode < I2C_UTILS_OPERMODE_MIN) ||
            (pConfigParams->operMode > I2C_UTILS_OPERMODE_MAX))
         {
             status = E_INVALID_PARAM;
         }
    else if((pConfigParams->txThreshold > I2C_UTILS_FIFO_DEPTH) ||
            (pConfigParams->rxThreshold > I2C_UTILS_FIFO_DEPTH))
         {
             status = E_INVALID_PARAM;
         }
    else
        {
            status = S_PASS;
        }

    return status;
}

static void I2cUtilsUpdateInfo(uint32_t instId,
                                    i2cUtilsObj_t *pI2cDevObj)
{

    pI2cDevObj->baseAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_I2C, instId);

    /* TODO Resolve interrupt Number and DMA Base Address and channel numbers
    ** along with Tx-Rx Number
    */
}

void I2C1ModuleClkConfig(void)
{
    uint32_t regVal = 0U;

#if defined(AM335X_FAMILY_BUILD)
    regVal = HW_RD_REG32(SOC_PRCM_REGS + CM_PER_I2C1_CLKCTRL);
    regVal |= CM_PER_I2C1_CLKCTRL_MODULEMODE_ENABLE;
    HW_WR_REG32(SOC_PRCM_REGS + CM_PER_I2C1_CLKCTRL, regVal);

    /* Waiting for MODULEMODE field to reflect the written value */
    while(CM_PER_I2C1_CLKCTRL_MODULEMODE_ENABLE !=
           (HW_RD_REG32(SOC_PRCM_REGS + CM_PER_I2C1_CLKCTRL) &
             CM_PER_I2C1_CLKCTRL_MODULEMODE));

    /*
    ** Waiting for CLKACTIVITY_I2C1_FCLK field in CM_PER_L4LS_CLKSTCTRL
    ** to attain desired value.
    */
    while(CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK !=
            (HW_RD_REG32(SOC_PRCM_REGS + CM_PER_L4LS_CLKSTCTRL) &
            CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK));

    /*
    ** Waiting for IDLEST field in CM_PER_I2C1_CLKCTRL register to attain
    ** desired value.
    */
    while((CM_PER_I2C1_CLKCTRL_IDLEST_FUNC <<
            CM_PER_I2C1_CLKCTRL_IDLEST_SHIFT)!=
            (HW_RD_REG32(SOC_PRCM_REGS + CM_PER_I2C1_CLKCTRL) &
             CM_PER_I2C1_CLKCTRL_IDLEST));

#elif defined(AM43XX_FAMILY_BUILD)
    /* Writing to MODULEMODE field of PRCM_CM_WKUP_I2C0_CLKCTRL register. */
    regVal = HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_I2C1_CLKCTRL);
    regVal |= PRCM_CM_PER_I2C1_CLKCTRL_MODULEMODE_ENABLE;
    HW_WR_REG32((SOC_CM_PER_REG + PRCM_CM_PER_I2C1_CLKCTRL), regVal);

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(PRCM_CM_PER_I2C1_CLKCTRL_MODULEMODE_ENABLE !=
          (HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_I2C1_CLKCTRL) &
            PRCM_CM_PER_I2C1_CLKCTRL_MODULEMODE_MASK));

    /*
    ** Waiting for CLKACTIVITY_I2C1_GFCLK field in PRCM_CM_PER_L4LS_CLKSTCTRL
    ** register to attain desired value.
    */
    while(PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK_MASK !=
            (HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_L4LS_CLKSTCTRL) &
            PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK_MASK));
    /*
    ** Waiting for IDLEST field in PRCM_CM_PER_I2C1_CLKCTRL register to attain
    ** desired value.
    */
     while((PRCM_CM_PER_I2C1_CLKCTRL_IDLEST_FUNC <<
            PRCM_CM_PER_I2C1_CLKCTRL_IDLEST_SHIFT)!=
            (HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_I2C1_CLKCTRL) &
             PRCM_CM_PER_I2C1_CLKCTRL_IDLEST_MASK));
#endif /* if defined(AM335X_FAMILY_BUILD) */
}


/*
** This function enables the system L3 and system L4_WKUP clocks.
** This also enables the clocks for I2C0 instance.
*/
void I2C0ModuleClkConfig(void)
{
    uint32_t regVal = 0U;

#if defined(AM335X_FAMILY_BUILD)
    /* Writing to MODULEMODE field of CM_WKUP_I2C0_CLKCTRL register. */
    regVal = HW_RD_REG32(SOC_CM_WKUP_REGS + CM_WKUP_I2C0_CLKCTRL);
    regVal |= CM_WKUP_I2C0_CLKCTRL_MODULEMODE_ENABLE;
    HW_WR_REG32(SOC_CM_WKUP_REGS + CM_WKUP_I2C0_CLKCTRL, regVal);

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(CM_WKUP_I2C0_CLKCTRL_MODULEMODE_ENABLE !=
          (HW_RD_REG32(SOC_CM_WKUP_REGS + CM_WKUP_I2C0_CLKCTRL) &
           CM_WKUP_I2C0_CLKCTRL_MODULEMODE));

    /*
    ** Waiting for IDLEST field in CM_WKUP_CONTROL_CLKCTRL register to attain
    ** desired value.
    */
    while((CM_WKUP_CONTROL_CLKCTRL_IDLEST_FUNC <<
           CM_WKUP_CONTROL_CLKCTRL_IDLEST_SHIFT) !=
          (HW_RD_REG32(SOC_CM_WKUP_REGS + CM_WKUP_CONTROL_CLKCTRL) &
           CM_WKUP_CONTROL_CLKCTRL_IDLEST));
    /*
    ** Waiting for CLKACTIVITY_I2C0_GFCLK field in CM_WKUP_CLKSTCTRL
    ** register to attain desired value.
    */
    while(CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK !=
          (HW_RD_REG32(SOC_CM_WKUP_REGS + CM_WKUP_CLKSTCTRL) &
           CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK));

    /*
    ** Waiting for IDLEST field in CM_WKUP_I2C0_CLKCTRL register to attain
    ** desired value.
    */
    while((CM_WKUP_I2C0_CLKCTRL_IDLEST_FUNC <<
           CM_WKUP_I2C0_CLKCTRL_IDLEST_SHIFT) !=
          (HW_RD_REG32(SOC_CM_WKUP_REGS + CM_WKUP_I2C0_CLKCTRL) &
           CM_WKUP_I2C0_CLKCTRL_IDLEST));
#elif defined(AM43XX_FAMILY_BUILD)

    /* Writing to MODULEMODE field of PRCM_CM_WKUP_I2C0_CLKCTRL register. */
    regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_WKUP_I2C0_CLKCTRL);
    regVal |= PRCM_CM_WKUP_I2C0_CLKCTRL_MODULEMODE_ENABLE;
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_WKUP_I2C0_CLKCTRL), regVal);

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(PRCM_CM_WKUP_I2C0_CLKCTRL_MODULEMODE_ENABLE !=
          (HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_WKUP_I2C0_CLKCTRL) &
            PRCM_CM_WKUP_I2C0_CLKCTRL_MODULEMODE_MASK));

    /*
    ** Waiting for CLKACTIVITY_I2C0_GFCLK field in PRCM_CM_WKUP_CLKSTCTRL
    ** register to attain desired value.
    */
    while(PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK_MASK !=
            (HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_WKUP_CLKSTCTRL) &
            PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK_MASK));
    /*
    ** Waiting for IDLEST field in PRCM_CM_WKUP_I2C0_CLKCTRL register to attain
    ** desired value.
    */
     while((PRCM_CM_WKUP_I2C0_CLKCTRL_IDLEST_FUNC <<
            PRCM_CM_WKUP_I2C0_CLKCTRL_IDLEST_SHIFT)!=
            (HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_WKUP_I2C0_CLKCTRL) &
             PRCM_CM_WKUP_I2C0_CLKCTRL_IDLEST_MASK));
#endif /* if defined(AM335X_FAMILY_BUILD) */
}

void  I2C2ModuleClkConfig(void)
{
    uint32_t regVal = 0U;

#if defined(AM335X_FAMILY_BUILD)
    regVal = HW_RD_REG32(SOC_PRCM_REGS + CM_PER_I2C2_CLKCTRL);
    regVal |= CM_PER_I2C2_CLKCTRL_MODULEMODE_ENABLE;
    HW_WR_REG32(SOC_PRCM_REGS + CM_PER_I2C2_CLKCTRL, regVal);

    /* Waiting for MODULEMODE field to reflect the written value */
    while(CM_PER_I2C2_CLKCTRL_MODULEMODE_ENABLE !=
           (HW_RD_REG32(SOC_PRCM_REGS + CM_PER_I2C2_CLKCTRL) &
            CM_PER_I2C2_CLKCTRL_MODULEMODE));

    regVal = HW_RD_REG32(SOC_PRCM_REGS + CM_PER_I2C2_CLKCTRL);
    while((regVal & CM_PER_I2C2_CLKCTRL_MODULEMODE) !=
           CM_PER_I2C2_CLKCTRL_MODULEMODE_ENABLE);

    /*
    ** Waiting for CLKACTIVITY_I2C2_FCLK field in CM_PER_L4LS_CLKSTCTRL
    ** to attain desired value.
    */
    while(CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK !=
            (HW_RD_REG32(SOC_PRCM_REGS + CM_PER_L4LS_CLKSTCTRL) &
            CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK));

    /*
    ** Waiting for IDLEST field in CM_PER_I2C2_CLKCTRL register to attain
    ** desired value.
    */
    while((CM_PER_I2C2_CLKCTRL_IDLEST_FUNC <<
            CM_PER_I2C2_CLKCTRL_IDLEST_SHIFT)!=
            (HW_RD_REG32(SOC_PRCM_REGS + CM_PER_I2C2_CLKCTRL) &
             CM_PER_I2C2_CLKCTRL_IDLEST));

    regVal = HW_RD_REG32(SOC_PRCM_REGS + CM_PER_L4LS_CLKSTCTRL);
    while(!((regVal) & (CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK |
            CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK)));
#elif defined(AM43XX_FAMILY_BUILD)
    /* Writing to MODULEMODE field of PRCM_CM_PER_I2C2_CLKCTRL register. */
    regVal = HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_I2C2_CLKCTRL);
    regVal |= PRCM_CM_PER_I2C2_CLKCTRL_MODULEMODE_ENABLE;
    HW_WR_REG32(SOC_CM_PER_REG + PRCM_CM_PER_I2C2_CLKCTRL, regVal);

    /* Waiting for MODULEMODE field to reflect the written value. */
    while(PRCM_CM_PER_I2C2_CLKCTRL_MODULEMODE_ENABLE !=
          (HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_I2C2_CLKCTRL) &
            PRCM_CM_PER_I2C2_CLKCTRL_MODULEMODE_MASK));

    /*
    ** Waiting for CLKACTIVITY_I2C2_GFCLK field in PRCM_CM_PER_L4LS_CLKSTCTRL
    ** register to attain desired value.
    */
    while(PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK_MASK !=
            (HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_L4LS_CLKSTCTRL) &
            PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK_MASK));

    /*
    ** Waiting for IDLEST field in PRCM_CM_PER_I2C1_CLKCTRL register to attain
    ** desired value.
    */
     while((PRCM_CM_PER_I2C2_CLKCTRL_IDLEST_FUNC <<
            PRCM_CM_PER_I2C2_CLKCTRL_IDLEST_SHIFT)!=
            (HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_I2C2_CLKCTRL) &
             PRCM_CM_PER_I2C2_CLKCTRL_IDLEST_MASK));

#endif /* if defined(AM335X_FAMILY_BUILD) */
}
