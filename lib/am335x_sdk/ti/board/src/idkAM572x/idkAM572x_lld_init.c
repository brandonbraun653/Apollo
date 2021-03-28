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

Board_STATUS Board_internalInitI2C()
{
    I2C_Params i2cParams;
    int i;
    Board_STATUS ret = BOARD_SOK;
    uint8_t flag = 0;

    /* Board i2c usage does not depend on interrupts */
    for (i=0; i < I2C_HWIP_MAX_CNT; i++)
    {
        /* Check if interrupt set to true. Change it to false and raise a flag
            Note that number of i2c instances will not exceed 8 */
        if (((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr == true)
        {
            flag |= (1<<i);
            ((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = false;
        }
    }

    I2C_init();

    I2C_Params_init(&i2cParams);

    /* Internal handle for I2C1 */
    Board_obj.i2cHandle = I2C_open(BOARD_I2C_EEPROM_INSTANCE, &i2cParams);
    if (Board_obj.i2cHandle == NULL)
        ret = BOARD_I2C_OPEN_FAIL;

    /* Restore the original I2C_config table */
    for (i=0; i < I2C_HWIP_MAX_CNT; i++)
    {
        if (flag & (1<<i))
            ((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = true;
    }

    return ret;
}

Board_STATUS Board_uartStdioInit()
{
    Board_IDInfo id;
    Board_STATUS ret;
    ret = Board_getIDInfo(&id);
	socId_t socId = Board_soc_detect();
    if (ret != BOARD_SOK)
    {
        return ret;
    }

#if defined (_TMS320C6X)
    /*
     * AM5 DSP does not have a default Xbar connection for UART
     * interrupt, need the following Xbar interrupt configuration
     */
    /* Use reserved DSP1_IRQ_34 */
    CSL_xbarDspIrqConfigure(1,
                            CSL_XBAR_INST_DSP1_IRQ_34,
                            CSL_XBAR_UART3_IRQ);
#endif

    /* Check if version is 1.0 or 1.1 */
    if ((id.version[0] == '1' && id.version[2] == '0' && socId == SOC_ID_AM572x) ||
		(id.version[0] == '1' && id.version[2] == '1' && socId == SOC_ID_AM572x))
        UART_stdioInit(BOARD_UART_INSTANCE_ALPHA);
    else
        UART_stdioInit(BOARD_UART_INSTANCE_BETA);
    return BOARD_SOK;
}
