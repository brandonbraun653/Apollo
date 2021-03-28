/**
 *
 *  \file  i2c.c
 *
 *  \brief File provides functional level APIs for I2C interface.
 */

/*
* Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdbool.h>
#include <ti/csl/src/ip/i2c/V0/i2c.h>

/*******************************************************************************
*                       INTERNAL MACRO DEFINITIONS
*******************************************************************************/



/*******************************************************************************
*                        API FUNCTION DEFINITIONS
*******************************************************************************/

/**
 * \brief   This API will divide the system clock fed to I2C module between
 *          12 and 100Mhz.It will also configure the I2C bus clock frequency.
 *
 * \param   baseAdd     It is the Memory address of the I2C instance used.
 * \param   sysClk      It is the System clock fed to I2C module.
 * \param   internalClk It is the internal clock used by I2C module.Which is
 *                      obtained by scaling System clock fed to I2C module.
 * \param   outputClk   It is the required I2C bus speed or frequency.
 *
 * \return  None.
 **/
void I2CMasterInitExpClk(uint32_t baseAdd, uint32_t sysClk,
                         uint32_t internalClk, uint32_t outputClk)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;
    uint32_t prescalar;
    uint32_t divider;

    /* Set the prescalar value */
    prescalar = sysClk / internalClk - 1U;
    i2cRegs->ICPSC = prescalar;

    /* Set the CLKL and CLKH values */
    divider = internalClk / outputClk;
    divider = divider / 2U;
    i2cRegs->ICCLKL = divider - 6U;
    i2cRegs->ICCLKH = divider - 6U;
}

/**
 * \brief   Enables the I2C module.This will bring the I2C module out of reset.
 *
 * \param   baseAdd   It is the Memory address of the I2C instance used.
 *
 * \return  None.
 *
 **/
void I2CMasterEnable(uint32_t baseAdd)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    /* Set Own Address */
    i2cRegs->ICOAR = I2C_OWN_ADDR;

    /* Enable master mode */
    i2cRegs->ICMDR = CSL_I2C_ICMDR_MST_MASK | CSL_I2C_ICMDR_FREE_MASK;

    /* Bring I2C out of reset */
    i2cRegs->ICMDR |= CSL_I2C_ICMDR_IRS_MASK;
}


/**
 * \brief   Enables the I2C module in slave mode.
 *          This will bring the I2C module out of reset.
 *
 * \param   baseAdd   It is the Memory address of the I2C instance used.
 *
 * \return  None.
 *
 **/
void I2CSlaveEnable(uint32_t baseAdd)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    /* Enable master mode */
    i2cRegs->ICMDR = CSL_I2C_ICMDR_FREE_MASK;

    /* Bring I2C out of reset */
    i2cRegs->ICMDR |= CSL_I2C_ICMDR_IRS_MASK;
}

/**
 * \brief   Disables the I2C Module.This will put the I2C module in reset.
 *          Only Tx and Rx are cleared,status bits are set their default
 *          values and all configuration registers are not reset,they keep
 *          their initial values.
 *
 * \param   baseAdd   It is the Memory address of the I2C instance used.
 *
 * \return  None.
 *
 **/
void I2CMasterDisable(uint32_t baseAdd)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    i2cRegs->ICMDR &= ~CSL_I2C_ICMDR_IRS_MASK;
}

/**
 * \brief   This API determines whether bus is busy or not.
 *
 * \param   baseAdd   It is the Memory address of the I2C instance used.
 *
 * \return  returns true if bus is busy.
 *          returns false if bus is free.
 *
 **/
bool I2CMasterBusBusy(uint32_t baseAdd)
{
    bool ret_val = false;
    if(I2CMasterIntStatusEx(baseAdd, I2C_INT_BUS_BUSY))
    {
        ret_val = (bool)true;
    }
    else
    {
        ret_val = (bool)false;
    }
    return ret_val;
}


/**
 * \brief   This API determines whether error occurred or not during
 *          I2C operation.
 *
 * \param   baseAdd   It is the Memory address of the I2C instance used.
 *
 * \returns error status.If error has occurred it returns a non zero value.
 *          If no error has occurred then return status will be zero.
 *
 * Error may occur during I2C operation due to arbitration lost,access error,
 * receive overrun and transmit underrun.
 **/
uint32_t I2CMasterErr(uint32_t baseAdd)
{
    uint32_t errMask;

    errMask = I2C_INT_ARBITRATION_LOST    |
              I2C_INT_NO_ACK              |
              I2C_INT_STOP_CONDITION      |
              I2C_INT_ADRR_ZERO           |
              I2C_INT_RECV_OVER_RUN;

    return (I2CMasterIntStatusEx(baseAdd, errMask));
}

/**
 * \brief   This API configure I2C in different modes of operation in master mode.
 *
 * \param   baseAdd   It is the Memory address of the I2C instance used.
 * \param   ctrlMask  Mask of the control bits to configure I2C in different mode's
 *                    of operation.\n
 * \param   ctrlCmds  Control bits which configures I2C in different mode's
 *                    of operation.\n
 *
 * \return None.
 *
 **/
void I2CMasterControl(uint32_t baseAdd, uint32_t ctrlMask, uint32_t ctrlCmds)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;
    uint32_t i2cMdr = i2cRegs->ICMDR;

    i2cMdr &= ~ctrlMask;
    i2cMdr |= (ctrlCmds | CSL_I2C_ICMDR_MST_MASK);
    i2cRegs->ICMDR = i2cMdr;
}

/**
 * \brief   This API configure I2C in different modes of operation.
 *
 * \param   baseAdd   It is the Memory address of the I2C instance used.
 * \param   ctrlMask  Mask of the control bits to configure I2C in different mode's
 *                    of operation.\n
 * \param   ctrlCmds  Control bits which configures I2C in different mode's
 *                    of operation.\n
 *
 * \return None.
 *
 **/
void I2CModeControl(uint32_t baseAdd, uint32_t ctrlMask, uint32_t ctrlCmds)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;
    uint32_t i2cMdr = i2cRegs->ICMDR;

    i2cMdr &= ~ctrlMask;
    i2cMdr |= ctrlCmds;
    i2cRegs->ICMDR = i2cMdr;
}

/**
 * \brief   This API starts a I2C transaction on the bus. This API must
 *          be called after all the configuration for the i2c module is
 *          done and after bringing I2C out of local reset
 *
 * \param   baseAdd  It is the Memory address of the I2C instance used.
 *
 * \return None.
 **/
void I2CMasterStart(uint32_t baseAdd)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    i2cRegs->ICMDR |= (CSL_I2C_ICMDR_MST_MASK | CSL_I2C_ICMDR_STT_MASK);
}

/**
 * \brief  This API stops a I2C transaction on the bus.
 *         This API must be used in case a deliberate STOP needs to be sent
 *         on the bus.
 *
 * \param  baseAdd  It is the Memory address of the I2C instance used.
 *
 * \return None.
 **/
void I2CMasterStop(uint32_t baseAdd)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    i2cRegs->ICMDR |= (CSL_I2C_ICMDR_MST_MASK | CSL_I2C_ICMDR_STP_MASK);
}

/**
 * \brief  This API enables only specified I2C interrupts in master mode.
 *
 * \param  baseAdd  It is the Memory address of the I2C instance used.
 * \param  intFlag   It specifies the interrupts that are required to be enabled.
 *
 *         intFlag can take following values.\n
 *
 *         I2C_INT_ARBITRATION_LOST     - Arbitration-lost interrupt.\n
 *         I2C_INT_NO_ACK               - No-acknowledgement interrupt.\n
 *         I2C_INT_ADRR_READY_ACESS     - I2C registers are ready to access.\n
 *         I2C_INT_RECV_READY           - Receive-data-ready interrupt.\n
 *         I2C_INT_TRANSMIT_READY       - Transmit-data-ready interrupt.\n
 *         I2C_INT_STOP_CONDITION       - Stop condition interrupt.\n
 *         I2C_INT_ADRR_SLAVE           - Address-as-slave interrupt.\n
 *
 * \return None.
 **/
void I2CMasterIntEnableEx(uint32_t baseAdd, uint32_t intFlag)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    i2cRegs->ICIMR |= intFlag;
}


/**
 * \brief  This API disables only specified I2C interrupts in master mode.
 *
 * \param  baseAdd  It is the Memory address of the I2C instance used.
 * \param  intFlag   It specifies the interrupts that are rquired to be disabled
 *
 *         intFlag can take following values.\n
 *
 *         I2C_INT_ARBITRATION_LOST     - Arbitration-lost interrupt.\n
 *         I2C_INT_NO_ACK               - No-acknowledgement interrupt.\n
 *         I2C_INT_ADRR_READY_ACESS     - I2C registers are ready to access.\n
 *         I2C_INT_RECV_READY           - Receive-data-ready interrupt.\n
 *         I2C_INT_TRANSMIT_READY       - Transmit-data-ready interrupt.\n
 *         I2C_INT_STOP_CONDITION       - Stop condition interrupt.\n
 *         I2C_INT_ADRR_SLAVE           - Address-as-slave interrupt.\n
 *
 * \return None.
 **/
void I2CMasterIntDisableEx(uint32_t baseAdd, uint32_t intFlag)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    i2cRegs->ICIMR &= ~intFlag;
}


/**
 * \brief  This API returns the status of specified interrupts in
 *         master mode.
 *
 * \param  baseAdd  It is the Memory address of the I2C instance used.
 * \param  intFlag  It specifies the interrupts whose status needs to be
 *                  returned.\n
 *
 *         intFlag can take following macros.\n
 *
 *         I2C_INT_ARBITRATION_LOST     - Arbitration-lost interrupt.\n
 *         I2C_INT_NO_ACK               - No-acknowledgement interrupt.\n
 *         I2C_INT_ADRR_READY_ACESS     - I2C registers are ready to access.\n
 *         I2C_INT_RECV_READY           - Receive-data-ready interrupt.\n
 *         I2C_INT_TRANSMIT_READY       - Transmit-data-ready interrupt.\n
 *         I2C_INT_STOP_CONDITION       - Stop condition interrupt.\n
 *         I2C_INT_ADRR_ZERO            - Address of all zeros interrupt.\n
 *         I2C_INT_ADRR_SLAVE           - Address-as-slave interrupt.\n
 *         I2C_INT_TRANSMIT_UNDER_FLOW  - Transmit underflow interrupt.\n
 *         I2C_INT_RECV_OVER_RUN        - Receive overrun interrupt.\n
 *         I2C_INT_BUS_BUSY             - Bus busy Interrupt.\n
 *         I2C_INT_NO_ACK_SENT          - No acknowlegement sent interrupt.\n
 *         I2C_INT_SLAVE_DIRECTION      - Slave direction interrupt.\n
 *
 * \returns status of specified interrupts.
 **/
uint32_t I2CMasterIntStatusEx(uint32_t baseAdd, uint32_t intFlag)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    return (i2cRegs->ICSTR & intFlag);
}

/**
 * \brief  This API Clears the status of specified interrupts in
 *         master mode.
 *
 * \param  baseAdd  It is the Memory address of the I2C instance used.
 * \param  intFlag  It specifies the interrupts whose status needs to be cleared
 *
 *         intFlag can take following macros.\n
 *
 *         I2C_INT_ARBITRATION_LOST     - Arbitration-lost interrupt.\n
 *         I2C_INT_NO_ACK               - No-acknowledgement interrupt.\n
 *         I2C_INT_ADRR_READY_ACESS     - I2C registers are ready to access.\n
 *         I2C_INT_RECV_READY           - Receive-data-ready interrupt.\n
 *         I2C_INT_TRANSMIT_READY       - Transmit-data-ready interrupt.\n
 *         I2C_INT_STOP_CONDITION       - Stop condition interrupt.\n
 *         I2C_INT_ADRR_ZERO            - Address of all zeros interrupt.\n
 *         I2C_INT_ADRR_SLAVE           - Address-as-slave interrupt.\n
 *         I2C_INT_TRANSMIT_UNDER_FLOW  - Transmit underflow interrupt.\n
 *         I2C_INT_RECV_OVER_RUN        - Receive overrun interrupt.\n
 *         I2C_INT_BUS_BUSY             - Bus busy Interrupt.\n
 *         I2C_INT_NO_ACK_SENT          - No acknowlegement sent interrupt.\n
 *         I2C_INT_SLAVE_DIRECTION      - Slave direction interrupt.\n
 *
 * \returns None
 **/
void I2CMasterIntClearEx(uint32_t baseAdd, uint32_t intFlag)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    i2cRegs->ICSTR = intFlag;
}


/**
 * \brief   This API sets the address of the slave device with which I2C wants
 *          to communicate.
 *
 * \param   baseAdd   It is the Memory address of the I2C instance used.
 * \param   slaveAdd  slave address.
 *
 * \return None.
 **/
void I2CMasterSlaveAddrSet(uint32_t baseAdd, uint32_t slaveAdd)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    i2cRegs->ICSAR = slaveAdd;
}


/**
 * \brief   This API configure I2C data count register with a value.
 *          The value in the I2C data count register indicate how many data
 *          words to transfer when the I2C is configured as a master-transmitter
 *          and repeat mode is off.
 *
 * \param   baseAdd  It is the Memory address of the I2C instance used.
 * \param   count    It is value which is set to I2C data count register.
 *
 * \return None.
 **/
void I2CSetDataCount(uint32_t baseAdd, uint32_t count)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    i2cRegs->ICCNT = count;
}

/**
 * \brief   This API gets the current value from the I2C data count register with a value.
 *          The value in the I2C data count register indicate how many data
 *          words to transfer when the I2C is configured as a master-transmitter
 *          and repeat mode is off.
 *
 * \param   baseAdd  It is the Memory address of the I2C instance used.
 *
 * \return  number of bytes transferred over the I2C bus.
 **/
uint32_t I2CDataCountGet(uint32_t baseAdd)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    return(i2cRegs->ICCNT);
}

/**
 * \brief  This function Transmits a byte from the I2C in Master mode.
 *
 * \param  baseAdd is the Memory address of the I2C instance used.
 * \param  data data to be transmitted from the I2C Master.
 *
 * \return None.\n
 *
 **/
void I2CMasterDataPut(uint32_t baseAdd, uint8_t data)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    i2cRegs->ICDXR = data;
}

/**
 *  \brief  This Receives a byte that has been sent to the I2C in Master mode.
 *
 *  \param  baseAdd is the Memory address of the I2C instance used.
 *
 *  \return Returns the byte received from by the I2C in Master mode.
 *
 **/
uint8_t I2CMasterDataGet(uint32_t baseAdd)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    return (uint8_t)(i2cRegs->ICDRR);
}

/**
 *  \brief  Set the own slave address
 *
 *  \param  baseAddr is the Memory address of the I2C instance used.
 *  \param  ownAddr is the own slave address of the I2C instance.
 *
 *  \return none.
 *
 **/
void I2COwnAddressSet(uint32_t baseAddr, uint32_t ownAddr)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAddr;

    i2cRegs->ICOAR = ownAddr;
}

/**
 *  \brief  Get the interrupt vector code.
 *
 *  \param  baseAdd is the Memory address of the I2C instance used.
 *
 *  \return Returns the byte received from by the I2C in Master mode.
 *
 **/
uint32_t I2CIntVectGet(uint32_t baseAdd)
{
    CSL_I2cRegsOvly i2cRegs = (CSL_I2cRegsOvly)baseAdd;

    return ((i2cRegs->ICIVR) & I2C_IVR_INTCODE_MASK);
}
