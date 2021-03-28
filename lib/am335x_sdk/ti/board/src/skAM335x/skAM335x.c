/******************************************************************************
 * Copyright (c) 2010-2015 Texas Instruments Incorporated - http://www.ti.com
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

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "board_internal.h"
#include "error.h"
#include "chipdb.h"
#include "prcm.h"
#include "board_cfg.h"

Board_gblObj Board_obj;

/* EEPROM data on ICEv 2.1A */
char eepromData[I2C_EEPROM_RX_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x33,
                                         0x33, 0x35, 0x58, 0x5f, 0x53};

/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
Board_STATUS Board_DDR3Init()
{
    return BOARD_SOK;
}

Board_STATUS Board_PLLInit()
{
    return BOARD_SOK;
}

Board_STATUS Board_moduleClockInit()
{
    int32_t status;
    
    /* UART */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_UART, 0U, 0U);

    /* CPSW */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_CPSW, 0U, 0U);
    }    
    
    /* GPIO */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, 0U, 0U);
    }
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, 1U, 0U);
    }
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, 2U, 0U);
    }

    /* I2C */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_I2C, 0U, 0U);
    }

    /* EDMA3CC */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3CC, 0U, 0U);
    }

    /* EDMA3TC0 */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3TC, 0U, 0U);
    }

    /* EDMA3TC1 */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3TC, 1U, 0U);
    }

    /* EDMA3TC2 */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3TC, 2U, 0U);
    }

    /* MMCSD */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_MMCSD, 0U, 0U);
    }
	/* LCDC */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_LCDC, 0U, 0U);
    }

    /* RTCSS */
     if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_RTCSS, 0U, 0U);
    }

    /* TSCADC */
     if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_ADC0, 0U, 0U);
    }

    return BOARD_SOK;
}

Board_STATUS Board_init(Board_initCfg cfg)
{
    Board_STATUS ret = BOARD_SOK;

    if (cfg & BOARD_INIT_PLL)
        ret = Board_PLLInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_MODULE_CLOCK)
        ret = Board_moduleClockInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_DDR)
        ret = Board_DDR3Init();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_PINMUX_CONFIG)
        ret = Board_pinmuxConfig();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_UART_STDIO)
        ret = Board_uartStdioInit();
    if (ret != BOARD_SOK)
        return ret;

    return ret;
}

void boardInit()
{
    Board_PLLInit();
    Board_moduleClockInit();
    Board_DDR3Init();
    Board_pinmuxConfig();
}
