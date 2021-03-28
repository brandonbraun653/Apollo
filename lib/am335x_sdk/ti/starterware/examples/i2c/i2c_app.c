/**
 * \file   i2c_app.c
 *
 * \brief  Source file containing the i2c IP related configuration functions.
 *         These functions will be called by example application.
 *
 */

/**
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "chipdb.h"
#include "pinmux.h"
#include "prcm.h"
#include "i2c.h"
#include "error.h"

/* Application header files */
#include "i2c_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief macro to indicate that the I2C transaction is in progress */
#define I2C_APP_BUS_BUSY                             (-1)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding i2c data transfer parameters. */
typedef struct i2cAppTxRxParams
{
    uint32_t            baseAddr;
    /**< i2c instance  base address. */
    uint32_t            slaveAddr;
    /**< i2c device slave address */
    uint32_t            bufLen;
    /**< Length of the buffer passed */
    uint8_t             *pBuf;
    /**< pointer to a buffer to hold the data */
    uint32_t            txThreshold;
    /**< Transmit FIFO threshold configuration. */
    uint32_t            rxThreshold;
    /**< Receive FIFO threshold configuration. */
    int32_t             statusFlag;
    /**< Status flag to indicate the Transfer Status */
}i2cAppTxRxParams_t;


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief   A Interrupt Service routine which is invoked when the I2C interrupt
 *           is raised. The ISR handles different cases like Trasnmit, Receive
 *           and some error conditions.
 *
 *  \param   intrNum    interrupt number to which the interrupt event is mapped.
 *  \param   cpuId      id of the CPU to which interrupt is raised.
 *  \param   userParam  parameter to be passed to the ISR.
 */
static void I2cAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/**
 *  \brief   Initializes the interrupt controller and configures it with
 *           different parameters like triggertype, Interrupt Priority
 *           and registers the Interrupt Service Routine to be invoked
 *           when the Interrupt is raised.
 *
 *  \param   pI2cIntrConfig    pointer to the interrupt configuration structure.
 */
static int32_t I2cAppInterruptConfig(i2cAppIntrCfgObj_t *pI2cIntrConfig);

/**
 *  \brief   Status check function which polls the status of the I2C device
 *           indefinitely for a particular event.
 *
 *  \param   baseAddr       baseAddress of the I2C instance
 *  \param   intrFlag       flag to indicate which status event to monitor
 *
 *  \retval  status of the flag which is polled.
 */
static uint32_t I2cAppStatusCheck(uint32_t baseAddr, uint32_t intrFlag);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** brief Structure which holds the Interrupt Configuration Params. */
static intcIntrParams_t gI2cAppIntrParams;

/** brief Structure which holds the I2C Transfer Params. */
static i2cAppTxRxParams_t gI2cAppXferParams;


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t I2CAppModuleInit(i2cAppCfgObj_t  *pI2cConfig)
{
    int32_t status = S_PASS;

    /* Clock Configuration  */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_I2C, pI2cConfig->i2cInstNum, 0U);

    if(S_PASS != status)
    {
        /* PinMux Configuration */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_I2C, pI2cConfig->i2cInstNum,
                                    NULL);
    }

    return status;
}

int32_t I2CAppCtrlInit(i2cAppCfgObj_t *pI2CAppCtrlCfg)
{
    int32_t status = S_PASS;
    uint32_t delay = 0x7FFFU;
    /* TODO: The delay value needs to be finalized
    ** when integrating with TimerUtils
    */
    uint32_t busFrequency;

    /* Put i2c in reset/disabled state */
    I2CModuleEnable(pI2CAppCtrlCfg->i2cBaseAddr, FALSE);

    /* Do a Soft reset of the module */
    I2CSoftReset(pI2CAppCtrlCfg->i2cBaseAddr);

    /* Disable Auto-Idle functionality. */
    I2CAutoIdleEnable(pI2CAppCtrlCfg->i2cBaseAddr, FALSE);

    /* Configure i2c bus speed*/
    busFrequency = (pI2CAppCtrlCfg->i2cAppDevCfg.busSpeed * FREQ_KHZ);

    I2CMasterInitExpClk(pI2CAppCtrlCfg->i2cBaseAddr, I2C_SYS_CLK,
                        I2C_INT_CLK, busFrequency);

    /* Verify the addressing mode selected */
    if(I2C_ADDRMODE_7BIT != pI2CAppCtrlCfg->i2cAppDevCfg.addrMode)
    {
        /* return error if 10-bit addressing mode is selected */
        status = E_MODE_NOT_SUPP;
    }

    if(S_PASS == status)
    {
        /*Set Rx and Tx FIFO threshold value and reset the fifo*/
        I2CFIFOThresholdConfig(pI2CAppCtrlCfg->i2cBaseAddr,
                                pI2CAppCtrlCfg->i2cAppDevCfg.txThreshold,
                                I2C_FIFO_TX);

        I2CFIFOThresholdConfig(pI2CAppCtrlCfg->i2cBaseAddr,
                                pI2CAppCtrlCfg->i2cAppDevCfg.rxThreshold,
                                I2C_FIFO_RX);

        /* Disable all I2C interrupts */
        I2CIntrDisable(pI2CAppCtrlCfg->i2cBaseAddr, I2C_INTR_ALL);

        /* Take the I2C module out of reset: */
        I2CModuleEnable(pI2CAppCtrlCfg->i2cBaseAddr, TRUE);

        /* Wait for the reset to get complete */
        while((0U == I2CSystemStatusGet(pI2CAppCtrlCfg->i2cBaseAddr)) && delay)
        {
            /* TODO need to integrate with the timer APIs */
            delay--;
        }

        if(0U == delay)
        {
            /* Soft reset has failed */
            status = E_TIMEOUT;
        }
    }

    if((S_PASS == status) &&
         (I2C_APP_OPMODE_INTERRUPT == pI2CAppCtrlCfg->i2cAppDevCfg.opMode))
    {
        /* Initialize the interrupt Controller */
        status = I2cAppInterruptConfig(&pI2CAppCtrlCfg->i2cAppIntrCfg);
    }

    if(S_PASS == status)
    {
        /* Assign the I2C transfer related parameters to the local structure */
        gI2cAppXferParams.baseAddr = pI2CAppCtrlCfg->i2cBaseAddr;
        gI2cAppXferParams.slaveAddr = pI2CAppCtrlCfg->slaveAddr;
        gI2cAppXferParams.rxThreshold = pI2CAppCtrlCfg->
                                        i2cAppDevCfg.rxThreshold;
        gI2cAppXferParams.txThreshold = pI2CAppCtrlCfg->
                                        i2cAppDevCfg.txThreshold;
    }

    return status;
}

int32_t I2CAppWrite(i2cAppCfgObj_t *pI2cCtrlCfg, uint8_t *pData,
                    uint32_t dataCount)
{
    int32_t status = S_PASS;
    uint32_t intrFlag = 0U;
    uint32_t devStatus = 0U;
    uint32_t fifoThreshold = 0U, remainingBytes = 0U;
    uint8_t dataByte = 0U;

    /* Assign the data to be transmitted and its length */
    gI2cAppXferParams.pBuf = pData;
    gI2cAppXferParams.bufLen = dataCount;
    gI2cAppXferParams.statusFlag = I2C_APP_BUS_BUSY;

    /* Write the slave address */
    I2CMasterSlaveAddrSet(pI2cCtrlCfg->i2cBaseAddr, pI2cCtrlCfg->slaveAddr,
                           pI2cCtrlCfg->i2cAppDevCfg.addrMode);

    /*Configure data buffer length*/
    I2CSetDataCount(pI2cCtrlCfg->i2cBaseAddr, dataCount);

    /* Clear all the Interrupt status register */
    I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, I2C_INTR_ALL);

    /* Configure the Controller in Master Transmit mode */
    I2CSetMode(pI2cCtrlCfg->i2cBaseAddr, I2C_MODE_MASTER_TX);

    /* Configure Controller to generate START condition */
    I2CMasterStart(pI2cCtrlCfg->i2cBaseAddr);

    /* Configure Controller to generate STOP condition */
    I2CMasterStop(pI2cCtrlCfg->i2cBaseAddr);

    if(I2C_APP_OPMODE_INTERRUPT == pI2cCtrlCfg->i2cAppDevCfg.opMode)
    {
        /* Enable Transmit Ready and Drain Interrupts */
        I2CIntrEnable(pI2cCtrlCfg->i2cBaseAddr, (I2C_INTR_TX_READY |
                     I2C_INTR_TX_DRAIN | I2C_INTR_NO_ACK |
                     I2C_INTR_STOP_CONDITION | I2C_INTR_REG_ACESS_RDY));
    }
    else if(I2C_APP_OPMODE_DMA == pI2cCtrlCfg->i2cAppDevCfg.opMode)
    {
        status = E_MODE_NOT_SUPP;
        /* TODO: Support for DMA mode shall be added later */
    }
    else if(I2C_APP_OPMODE_POLLING == pI2cCtrlCfg->i2cAppDevCfg.opMode)
    {
        while(gI2cAppXferParams.bufLen > 0U)
        {
            intrFlag = (I2C_INTR_TX_READY | I2C_INTR_TX_DRAIN);

            devStatus = I2cAppStatusCheck(pI2cCtrlCfg->i2cBaseAddr, intrFlag);

            if(devStatus & I2C_INTR_TX_READY)
            {
                /*Clear other interrupts*/
                intrFlag = I2C_INTR_TX_READY;

                I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, (devStatus & ~intrFlag));

                for(fifoThreshold = 0;
                    fifoThreshold < (pI2cCtrlCfg->i2cAppDevCfg.txThreshold + 1);
                    fifoThreshold++)
                {
                    dataByte = *gI2cAppXferParams.pBuf++;
                    /*transmit byte of data*/
                    I2CMasterDataPut(pI2cCtrlCfg->i2cBaseAddr, dataByte);
                    /*Check for status*/
                    devStatus = I2CMasterIntRawStatus(pI2cCtrlCfg->i2cBaseAddr);
                    /*check nack status*/
                    if(devStatus & I2C_INTR_NO_ACK)
                    {
                        status = E_I2C_NAK_ERR;
                        break;
                    }
                    gI2cAppXferParams.bufLen--;
                }
                /*Clear transmit ready interrupt*/
                I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, (devStatus & intrFlag));
            }

            /* If data is not a multiple of fifo threshold */
            if(devStatus & I2C_INTR_TX_DRAIN)
            {
                /*Clear other interrupts*/
                intrFlag = I2C_INTR_TX_DRAIN;

                I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, (devStatus & ~intrFlag));

                remainingBytes = I2CBufferStatus(pI2cCtrlCfg->i2cBaseAddr,
                                                I2C_FIFO_TX);
                while(remainingBytes > 0U)
                {
                    dataByte =  *gI2cAppXferParams.pBuf++;
                    /*transmit byte of data*/
                    I2CMasterDataPut(pI2cCtrlCfg->i2cBaseAddr, dataByte);

                    /*Check for status*/
                    devStatus = I2CMasterIntRawStatus(pI2cCtrlCfg->i2cBaseAddr);

                    /*check nack status*/
                    if(devStatus & I2C_INTR_NO_ACK)
                    {
                        status = E_I2C_NAK_ERR;
                        break;
                    }
                    remainingBytes--;
                    gI2cAppXferParams.bufLen--;
                }
                I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, (devStatus & intrFlag));
            }
        }
        if((0U == gI2cAppXferParams.bufLen) || (S_PASS != status))
        {
            /*Wait till bus can be accessed*/
            intrFlag   = I2C_INTR_REG_ACESS_RDY;
            devStatus = I2cAppStatusCheck(pI2cCtrlCfg->i2cBaseAddr, intrFlag);

            /*Flush the FIFO*/
            I2CFIFOClear(pI2cCtrlCfg->i2cBaseAddr, I2C_FIFO_TX);

            /*Clear data buffer length*/
            I2CSetDataCount(pI2cCtrlCfg->i2cBaseAddr, 0U);
            /*Clear all interrupt status*/
            I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, I2C_INTR_ALL);
        }
    }
    else
    {
        /* Added for MISRA-C compliance */
    }

    if(I2C_APP_OPMODE_INTERRUPT == pI2cCtrlCfg->i2cAppDevCfg.opMode)
    {
        /* Wait till the I2C transaction completes */
        while(I2C_APP_BUS_BUSY == gI2cAppXferParams.statusFlag);
        /* Return the operation status */
        status = gI2cAppXferParams.statusFlag;
    }

    return status;
}

int32_t I2CAppRead(i2cAppCfgObj_t *pI2cCtrlCfg, uint8_t *pData,
                    uint32_t dataCount)
{
    int32_t status = S_PASS;
    uint32_t intrFlag = 0U;
    uint32_t devStatus = 0U;
    uint32_t fifoThreshold = 0U, remainingBytes = 0U;
    uint8_t dataByte = 0U;

    /* Assign the data to be Read and its length */
    gI2cAppXferParams.pBuf = pData;
    gI2cAppXferParams.bufLen = dataCount;
    gI2cAppXferParams.statusFlag = I2C_APP_BUS_BUSY;

    /* Write the slave address */
    I2CMasterSlaveAddrSet(pI2cCtrlCfg->i2cBaseAddr, pI2cCtrlCfg->slaveAddr,
                            pI2cCtrlCfg->i2cAppDevCfg.addrMode);

    /*Configure data buffer length*/
    I2CSetDataCount(pI2cCtrlCfg->i2cBaseAddr, dataCount);

    /* Clear all the Interrupt status register */
    I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, I2C_INTR_ALL);

    /* Configure the Controller in Master Receive mode */
    I2CSetMode(pI2cCtrlCfg->i2cBaseAddr, I2C_MODE_MASTER_RX);

    /* Configure Controller to generate START condition */
    I2CMasterStart(pI2cCtrlCfg->i2cBaseAddr);

    /* Configure Controller to generate STOP condition */
    I2CMasterStop(pI2cCtrlCfg->i2cBaseAddr);

    if(I2C_APP_OPMODE_INTERRUPT == pI2cCtrlCfg->i2cAppDevCfg.opMode)
    {
        /* Enable Receive Ready and Drain Interrupts */
        I2CIntrEnable(pI2cCtrlCfg->i2cBaseAddr, (I2C_INTR_RX_READY |
                    I2C_INTR_RX_DRAIN | I2C_INTR_NO_ACK |
                    I2C_INTR_STOP_CONDITION | I2C_INTR_REG_ACESS_RDY));
    }
    else if(I2C_APP_OPMODE_DMA == pI2cCtrlCfg->i2cAppDevCfg.opMode)
    {
        status = E_MODE_NOT_SUPP;
        /*Support for DMA mode shall be added later */
    }
    else if(I2C_APP_OPMODE_POLLING == pI2cCtrlCfg->i2cAppDevCfg.opMode)
    {
        while(gI2cAppXferParams.bufLen > 0U)
        {
            intrFlag = (I2C_INTR_RX_READY | I2C_INTR_RX_DRAIN);

            devStatus = I2cAppStatusCheck(pI2cCtrlCfg->i2cBaseAddr, intrFlag);

            if (devStatus & I2C_INTR_RX_READY)
            {
                intrFlag = I2C_INTR_RX_READY;
                /*Clear other interrupts*/
                I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, (devStatus & ~intrFlag));

                for(fifoThreshold = 0;
                    fifoThreshold < (pI2cCtrlCfg->i2cAppDevCfg.rxThreshold + 1);
                    fifoThreshold++)
                {
                    /* Receive each byte of data from the device */
                    dataByte = I2CMasterDataGet(pI2cCtrlCfg->i2cBaseAddr);
                    *gI2cAppXferParams.pBuf++ = dataByte;

                    /*Check for status*/
                    devStatus = I2CMasterIntRawStatus(pI2cCtrlCfg->i2cBaseAddr);
                    /* check nack status */
                    if (devStatus & I2C_INTR_NO_ACK)
                    {
                        status = E_I2C_NAK_ERR;
                        break;
                    }
                    gI2cAppXferParams.bufLen--;
                }
                /*Clear receive ready interrupt*/
                I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, (devStatus & intrFlag));
            }

            /* If data is not a multiple of fifo threshold */
            if (devStatus & I2C_INTR_RX_DRAIN)
            {
                intrFlag = I2C_INTR_RX_DRAIN;

                /* Clear other interrupts */
                I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr,(devStatus & ~intrFlag));

                remainingBytes = I2CBufferStatus(pI2cCtrlCfg->i2cBaseAddr,
                                    I2C_FIFO_RX);

                while(remainingBytes > 0U)
                {
                    /*Receive byte of data*/
                    dataByte = I2CMasterDataGet(pI2cCtrlCfg->i2cBaseAddr);
                    *gI2cAppXferParams.pBuf++ = dataByte;

                    /*Check for status*/
                    devStatus = I2CMasterIntRawStatus(pI2cCtrlCfg->i2cBaseAddr);
                    /*check nack status*/
                    if (devStatus & I2C_INTR_NO_ACK)
                    {
                        status = E_I2C_NAK_ERR;
                        break;
                    }
                    remainingBytes--;
                    gI2cAppXferParams.bufLen--;
                }
                /*Clear receive drain interrupt*/
                I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, (devStatus & intrFlag));
            }
        }
        if((0U == gI2cAppXferParams.bufLen) || (S_PASS != status))
        {
            /*Wait till bus can be accessed*/
            intrFlag   = I2C_INTR_REG_ACESS_RDY;
            devStatus = I2cAppStatusCheck(pI2cCtrlCfg->i2cBaseAddr, intrFlag);

            /*Flush the FIFO*/
            I2CFIFOClear(pI2cCtrlCfg->i2cBaseAddr, I2C_FIFO_RX);

            /*Clear data buffer length*/
            I2CSetDataCount(pI2cCtrlCfg->i2cBaseAddr, 0U);
            /*Clear all interrupt status*/
            I2CIntrClear(pI2cCtrlCfg->i2cBaseAddr, I2C_INTR_ALL);
        }
    }
    else
    {
        /* Added for MISRA-C Compliance */
    }

    if(I2C_APP_OPMODE_INTERRUPT == pI2cCtrlCfg->i2cAppDevCfg.opMode)
    {
        /* Wait till the I2C transaction completes */
        while(I2C_APP_BUS_BUSY == gI2cAppXferParams.statusFlag);
        /* Return the operation status */
        status = gI2cAppXferParams.statusFlag;
    }

    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


int32_t I2cAppInterruptConfig(i2cAppIntrCfgObj_t *pI2cIntrConfig)
{
    int32_t status = S_PASS;

    /* Initialize the Interrupt Controller */
    if(TRUE == pI2cIntrConfig->isIntrSecure)
    {
        INTCInit(INTC_SECURE_MODE);
    }
    else
    {
        INTCInit(INTC_NON_SECURE_MODE);
    }

    if(S_PASS == status)
    {
        /* Do the interrupt related configurations */
        gI2cAppIntrParams.triggerType = pI2cIntrConfig->intrTrigType;
        gI2cAppIntrParams.priority = pI2cIntrConfig->intrPriority;
        /*
        ** Assign the ISR to the function pointer to invoke when the
        ** interrupt is raised.
        */
        gI2cAppIntrParams.pFnIntrHandler = &I2cAppIsr;
        /* Assign the I2C Transfer structure to pass to the generic ISR */
        gI2cAppIntrParams.pUserParam =  &gI2cAppXferParams;
        gI2cAppIntrParams.isIntrSecure = pI2cIntrConfig->isIntrSecure;

        /* Configure the interrupt Controller */
        status = INTCConfigIntr(pI2cIntrConfig->intrLine, &gI2cAppIntrParams,
                                 pI2cIntrConfig->isIntrSecure);
    }

    return status;
}

void I2cAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    i2cAppTxRxParams_t *instObj = (i2cAppTxRxParams_t *) pUserParam;
    uint32_t status = 0U;
    uint32_t intrFlag = 0U;
    uint32_t fifoThreshold = 0U;
    uint8_t byte = 0U;
    uint32_t remainingBytes = 0U;

    status = I2CMasterIntStatus(instObj->baseAddr);

    /*
    ** Acknowledge the status of all interrupts except
    ** for Receive/Transmit Ready and Drain interrupts
    ** which shall be cleared after data operation is complete
    */
    intrFlag = status & ~(I2C_INTR_RX_READY | I2C_INTR_RX_DRAIN |
                 I2C_INTR_TX_READY | I2C_INTR_TX_DRAIN);
    I2CIntrClear(instObj->baseAddr, intrFlag);

    if(status & I2C_INTR_RX_READY)
    {
        for(fifoThreshold = 0; fifoThreshold < (instObj->rxThreshold + 1);
                 fifoThreshold++)
            {
                byte = I2CMasterDataGet(instObj->baseAddr);

                if (instObj->bufLen > 0U)
                {
                    *instObj->pBuf++ = (uint8_t) byte;
                    instObj->bufLen--;
                }

            }
        /* Clear the Receive Ready interrupt */
        I2CIntrClear(instObj->baseAddr, (status & I2C_INTR_RX_READY));
    }

    if(status & I2C_INTR_RX_DRAIN)
    {
        remainingBytes = I2CBufferStatus(instObj->baseAddr, I2C_FIFO_RX);

        while(remainingBytes > 0U)
        {
            byte = I2CMasterDataGet(instObj->baseAddr);

            if(instObj->bufLen > 0U)
            {
                *instObj->pBuf++ = (uint8_t) byte;
                instObj->bufLen--;
            }
            remainingBytes--;
        }
        /* Clear the Rx Drain Interrupt */
        I2CIntrClear(instObj->baseAddr, (status & I2C_INTR_RX_DRAIN));
    }

    if(status & I2C_INTR_TX_READY)
    {
        for (fifoThreshold = 0; fifoThreshold < (instObj->txThreshold + 1);
                 fifoThreshold++)
        {
            if (instObj->bufLen > 0U)
            {
                byte = *instObj->pBuf++;
                instObj->bufLen--;
            }

            I2CMasterDataPut(instObj->baseAddr, byte);
        }
        /* Clear the TxRDY interrupt */
        I2CIntrClear(instObj->baseAddr, (status & I2C_INTR_TX_READY));
    }

    if(status & I2C_INTR_TX_DRAIN)
    {
        remainingBytes = I2CBufferStatus(instObj->baseAddr, I2C_FIFO_TX);
        while(remainingBytes > 0U)
        {
            byte = *instObj->pBuf++;

            if(instObj->bufLen > 0U)
            {
                I2CMasterDataPut(instObj->baseAddr, byte);
                instObj->bufLen--;
            }
            remainingBytes--;
        }
        /* Clear the TxDrain interrupt */
        I2CIntrClear(instObj->baseAddr, (status & I2C_INTR_TX_DRAIN));
    }

    if(status & I2C_INTR_NO_ACK)
    {
        /* Clear all the interrupts */
        I2CIntrClear(instObj->baseAddr, (I2C_INTR_RX_READY | I2C_INTR_RX_DRAIN |
                 I2C_INTR_TX_READY | I2C_INTR_TX_DRAIN |
                 I2C_INTR_NO_ACK | I2C_INTR_STOP_CONDITION));

        I2CMasterStop(instObj->baseAddr);
        /* Return the Error status */
        instObj->statusFlag = E_I2C_NAK_ERR;
    }

    if(status & I2C_INTR_REG_ACESS_RDY)
    {
        if(status & I2C_INTR_STOP_CONDITION)
        {
            I2CFIFOClear(instObj->baseAddr, (I2C_FIFO_TX | I2C_FIFO_RX));

            /*Clear data buffer length*/
            I2CSetDataCount(instObj->baseAddr, 0U);
        }
        /* Clear all the Interrupts */
        I2CIntrClear(instObj->baseAddr, (I2C_INTR_RX_READY | I2C_INTR_RX_DRAIN |
                 I2C_INTR_TX_READY | I2C_INTR_TX_DRAIN | I2C_INTR_REG_ACESS_RDY
                 | I2C_INTR_STOP_CONDITION));

        /* Update the status flag with the transaction status */
        instObj->statusFlag = S_PASS;
    }

    if(status & I2C_INTR_ARBITRATION_LOST)
    {
        /* Update the error Status */
        instObj->statusFlag = E_FAIL;
    }
}

static uint32_t I2cAppStatusCheck(uint32_t baseAddr, uint32_t intrFlag)
{
    uint32_t  status;

    status = I2CMasterIntRawStatus(baseAddr);

    /* Poll on the Status of the required flag */
    while(0U == (status & intrFlag))
    {
        status = I2CMasterIntRawStatus(baseAddr);
    }

    return status;
}
