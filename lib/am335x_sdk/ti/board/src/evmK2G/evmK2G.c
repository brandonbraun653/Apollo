/******************************************************************************
 * Copyright (c) 2010-2017 Texas Instruments Incorporated - http://www.ti.com
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
#include "board_utils.h"
#include "board_pll.h"

Board_gblObj Board_obj;

/* external input clock to System/PA/ARM/DDR3 PLLs */
const uint32_t Board_ext_clk[CSL_PLL_MAX] =
{
    EXT_CLK_24M,     /* sys clock */
    0,               /* No NSS clock */
    EXT_CLK_24M,     /* ARM clock */
    EXT_CLK_100M,    /* DDR3 clock */
    0,               /* No DDR3B clock */
    EXT_CLK_24M,     /* NSS clock */
    EXT_CLK_24M,     /* UART clock */
    EXT_CLK_24M,     /* DSS clock */
    EXT_CLK_24M,     /* ICSS clock */
};

Board_STATUS Board_unlockMMR(void)
{
    CSL_BootCfgUnlockKicker();

    return BOARD_SOK;
}

/* Function to read the device variant K2G02 or K2G1x selection
*	Refer to Errata document for differentiating the silicon revisions
*	JTAGID == 0x8BB0602F : 1Ghz K2G1x or 600 MHz K2G1x
*	JTAGID == 0x0BB0602F, 0x1BB0602F : 600 MHz K2G02
*/
int Board_getJTAGID(void)
{
    return (*(unsigned int*)JTAGID);
}

/* Refer DEVSPEED definition in BOOTCFG_EFUSE_BOOTROM register in TRM 
			   0b0000_0001	600 MHz
               0b0000_1xxx	1000 MHz
               0b01xx_xxxx	600 MHz
			   Other		Reserved Efuse setting
*/ 
int Board_getDEVSPEED(void)
{
	int devSpeed;
	devSpeed = (unsigned int)(((*(unsigned int*)EFUSE_BOOTROM)&(DEVSPEED_MASK<<DEVSPEED_SHIFT))>>DEVSPEED_SHIFT);
	
	if((devSpeed & DEVSPEED600_MASK1) == 0x01)
    {
		return(DEVSPEED600);
	}
	else if((devSpeed & DEVSPEED1G_MASK1) == 0x08)
    {
		return(DEVSPEED1G);
    }
	else if((devSpeed & DEVSPEED600_MASK2) == 0x40)
    {
		return(DEVSPEED600);
	}
	else 
		return(0);
}

Board_STATUS Board_init(Board_initCfg cfg)
{
    BOARD_initPerfCounters();
	uint32_t var;
	
    Board_STATUS ret = BOARD_SOK;
    if (cfg & BOARD_INIT_UNLOCK_MMR)
        ret = Board_unlockMMR();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_PLL)
	{
		var= Board_getDEVSPEED();
        if(var == DEVSPEED1G)
        {
			ret = Board_PLLInit_1G();
        }
        else if(var == DEVSPEED600)
        {
			ret = Board_PLLInit();
        }
		else
			return BOARD_UNSUPPORTED_FEATURE;
    }
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_DDR)
        ret = Board_DDR3Init();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_WATCHDOG_DISABLE)
        return BOARD_UNSUPPORTED_FEATURE;

    if (cfg & BOARD_INIT_PINMUX_CONFIG)
        ret = Board_pinmuxConfig();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_UART_STDIO)
        ret = Board_uartStdioInit();
    if (ret != BOARD_SOK)
        return ret;

   if (cfg & BOARD_INIT_MODULE_CLOCK)
        ret = Board_moduleClockInit();
    if (ret != BOARD_SOK)
        return ret;

    return ret;
}

