/******************************************************************************
 * Copyright (c) 2010-2018 Texas Instruments Incorporated - http://www.ti.com
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

#include "board_internal.h"
#include "board_cfg.h"

Board_STATUS Board_uartStdioInit()
{
    UART_stdioInit(BOARD_UART_INSTANCE);
    return BOARD_SOK;
}

Board_STATUS Board_internalInitI2C()
{
    I2C_Params i2cParams;
    I2C_Transaction transaction;
    int i;
    int16_t transferStatus;
    uint8_t out_buff[2] ={ 0x85, 0x00 };
    for (i=0; i < I2C_HWIP_MAX_CNT; i++)
    {
        ((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = false;
    }

    I2C_init();

    I2C_Params_init(&i2cParams);

    Board_obj.i2cHandle = I2C_open(BOARD_I2C_EEPROM_INSTANCE, &i2cParams);
    if (Board_obj.i2cHandle == NULL) 
        return BOARD_I2C_OPEN_FAIL;
    I2C_transactionInit(&transaction);
    transaction.arg = NULL;
    transaction.nextPtr = NULL;
    transaction.readBuf = NULL;
    transaction.readCount = 0;
    transaction.slaveAddress = 0x65;
    transaction.writeBuf =(uint8_t *)&out_buff[0];
    transaction.writeCount = 2;
    transferStatus = I2C_transfer(Board_obj.i2cHandle, &transaction);

    if(I2C_STS_SUCCESS != transferStatus)
    {
        I2C_close(Board_obj.i2cHandle);
        return BOARD_I2C_TRANSFER_FAIL;
    }
    else
        return BOARD_SOK;
}
