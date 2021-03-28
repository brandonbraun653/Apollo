/**
 *   @file  evmOMAPL137_config.c
 *
 *   @brief
 *      This file contains the Ethernet PHY configurations for OMAPL137 EVM
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017, Texas Instruments, Inc.
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
 *  \par
*/


#include "board_internal.h"

/**
 * \brief  Board specific configurations for Ethernet PHYs
 *
 * \return  none
 */
Board_STATUS Board_EthConfig(void)
{
    uint32_t dataCnt = 2;
    I2C_Transaction i2cTransaction;
    Board_STATUS ret = BOARD_SOK;
    I2C_Handle handle = NULL;
    char txBuf[2];
    bool status;

    /* If handle not opened yet, init i2c */
    if (Board_obj.i2cHandle == NULL)
    {
        ret = Board_internalInitI2C();
    }    
    if (ret != BOARD_SOK)
        return ret;

    handle = Board_obj.i2cHandle;
    
    txBuf[0] = 0x01;
    txBuf[1] = 0x23;
    
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = BOARD_ETH_PHY_I2C_ADDR;
    i2cTransaction.writeBuf     = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount   = dataCnt;
    i2cTransaction.readBuf      = (uint8_t *)NULL;
    i2cTransaction.readCount    = 0;
    
    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;        
    }
    
    return ret;
}
