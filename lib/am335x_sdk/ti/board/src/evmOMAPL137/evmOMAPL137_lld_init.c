/**
 *  @file   evmOMAPL137_lld_init.c
 *
 *  @brief  Routines to initialize the LLD modules used by board library
 *
 *  ============================================================================
 */ 
/******************************************************************************
 * Copyright (c) 2016 Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  \brief  Initializes I2C LLD module
 *  
 *  Modules using board library can access the I2C LLD handle created by this 
 *  function using Board object (Board_obj)
 *
 *  \return BOARD_SOK for success or error code 
 */
Board_STATUS Board_internalInitI2C(void)
{
    I2C_Params i2cParams;
	I2C_HwAttrs initCfg;
	int32_t ret;
	uint32_t index;
	
	/* Disable the interrupts for all the I2C instances */
	for (index = 0; index < CSL_I2C_CNT; index++)
	{        	
        ret = I2C_socGetInitCfg(index, &initCfg);
		if (ret != 0)
            return BOARD_I2C_OPEN_FAIL;
        initCfg.enableIntr = false;
        I2C_socSetInitCfg(index, &initCfg);
        if (ret != 0)
			return BOARD_I2C_OPEN_FAIL;
	}		
	
    I2C_init();
    I2C_Params_init(&i2cParams);

    Board_obj.i2cHandle = I2C_open(BOARD_I2C_EEPROM_INSTANCE, &i2cParams);
    if (Board_obj.i2cHandle == NULL)
        return BOARD_I2C_OPEN_FAIL;
    else
        return BOARD_SOK;
}

/*
 *  \brief  Initializes UART LLD module
 *  
 *  Modules using board library can call this function to initialize UART LLD
 *  before calling any UART STDIO functions
 *
 *  \return BOARD_SOK
 */
Board_STATUS Board_uartStdioInit(void)
{
    UART_stdioInit(BOARD_UART_INSTANCE);

    return BOARD_SOK;
}
