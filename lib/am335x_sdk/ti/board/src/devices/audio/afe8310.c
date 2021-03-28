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
 * \file  afe8310.c
 *
 * \brief APIs to configure the AFE8310 tuner.
 *
 */

#include "afe8310.h"

/** AFE8310 tuner minimal configurations */
Board_Afe8310ProgObj Board_Afe8310CfgObj[] =
{
	{0x0002, 0x0002},   /* FM mode preset values */
    {0x0011, 0x0110},   /* No of bits per slot - 16, No of fs pulse per sample - 1 */
    {0x0012, 0x0011},   /* DCLK and DFS Master mode, rising edge of DCLK, mclk_div */
    {0x0013, 0x0011},   /* DFS delay and DFS mode */
    {0x0010, 0x0001},   /* dout_en set value */
    {0x0017, 0x0021},   /* dout0 config - I sample and Q sample */
    {0x0018, 0x0000},   /* No data source in e slot of dout0 */
    {0x0019, 0x0043},   /* dout1 config - I sample and Q sample */
    {0x001a, 0x0000},   /* No data source in e slot of dout1 */
    {0x004e, 0x4310},   /* FM - no noise blanker config */
    {0x0053, 0x4310},   /* FM - no noise blanker config */
    {0x005e, 0x4310},   /* FM - no noise blanker config */
    {BOARD_DEVICES_CONFIG_END}
};

/**
 * \brief   This function is used to configure the AFE8310 tuner.
 *
 * All the registers of AFE8310 code shall be configured.
 *
 * @param   handle          [IN] I2C driver handle
 * @param   fpdRmtDevParams [IN] structure holding the fpd params.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_afe8310TunerConfig(void *handle,
                                      Board_FpdRmtDevObj *fpdRmtDevParams)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t index = 0;
    uint16_t regData = 0;

	if(handle == NULL)
	{
		return BOARD_INVALID_PARAM;
	}

    while(Board_Afe8310CfgObj[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        UART_printf("Writing RegAddr 0x%x RegValue 0x%x \n", Board_Afe8310CfgObj[index].regAddr,
                                                             Board_Afe8310CfgObj[index].regData);
        boardStatus = Board_i2c10bit16bitRegWr(handle,
                                               fpdRmtDevParams->i2cDevAliasAddr,
                                               Board_Afe8310CfgObj[index].regAddr,
                                               Board_Afe8310CfgObj[index].regData,
                                               BOARD_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        UART_printf("Readback \n");
        boardStatus = Board_i2c10bit16bitRegRd(handle,
                                               fpdRmtDevParams->i2cDevAliasAddr,
                                               Board_Afe8310CfgObj[index].regAddr,
                                               &regData,
                                               BOARD_I2C_TRANSACTION_TIMEOUT);
        UART_printf("RegAddr 0x%x RegValue 0x%x \n", Board_Afe8310CfgObj[index].regAddr, regData);
        index++;
    }

    return boardStatus;
}
