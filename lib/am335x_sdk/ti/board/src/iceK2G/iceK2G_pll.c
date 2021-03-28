/******************************************************************************
 * Copyright (c) 2015-2017 Texas Instruments Incorporated - http://www.ti.com
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

#include "keystone_pll.h"
#include <stdbool.h>

extern void init_pll(const pllcConfig *data);
Bool Board_getClockMode(void);

const keystonePllcReg keystonePllcRegs[] = {
	{CSL_BOOT_CFG_REGS + 0x350, CSL_BOOT_CFG_REGS + 0x354}, /* system PLL */
	{0                        , 0},                         /* No PA PLL */
	{CSL_BOOT_CFG_REGS + 0x370, CSL_BOOT_CFG_REGS + 0x374}, /* ARM PLL */
	{CSL_BOOT_CFG_REGS + 0x360, CSL_BOOT_CFG_REGS + 0x364}, /* DDR3 PLL */
	{0                        , 0},                         /* No DDR3B PLL */
	{CSL_BOOT_CFG_REGS + 0x358, CSL_BOOT_CFG_REGS + 0x35c}, /* NSS PLL */
	{CSL_BOOT_CFG_REGS + 0x390, CSL_BOOT_CFG_REGS + 0x394}, /* UART PLL */
	{CSL_BOOT_CFG_REGS + 0x380, CSL_BOOT_CFG_REGS + 0x384}, /* DSS PLL */
	{CSL_BOOT_CFG_REGS + 0x388, CSL_BOOT_CFG_REGS + 0x38c}  /* ICSS PLL */
};

const pllcConfig pllcConfigs[] = {
    {CSL_PLL_SYS,    100,    1,      4}, /* 600 MHz */
    {CSL_PLL_NSS,    250,    3,      2}, /* 1000 MHz*/
    {CSL_PLL_ARM,    100,    1,      4}, /* 600 MHz*/
    {CSL_PLL_DDR3,   133,    1,     16}, /* 200 MHz*/
    {CSL_PLL_UART,   128,    1,      8}, /* 384 MHz*/
    {CSL_PLL_DSS,    198,   12,     16}, /* 25 MHz*/
    {CSL_PLL_ICSS,   250,    3,     10}  /* 200 MHz*/
};

const pllcConfig pllcConfigs_extClk[] = {
    {CSL_PLL_SYS,    96,     1,      4}, /* 600 MHz */
    {CSL_PLL_NSS,    240,    3,      2}, /* 1000 MHz*/
    {CSL_PLL_ARM,    96,     1,      4}, /* 600 MHz*/
    {CSL_PLL_DDR3,   128,    1,     16}, /* 200 MHz*/
    {CSL_PLL_UART,   767,    5,     10}, /* 384 MHz*/
    {CSL_PLL_DSS,    190,   12,     16}, /* 25 MHz*/
    {CSL_PLL_ICSS,   240,    3,     10}  /* 200 MHz*/
};

const pllcConfig pllcConfigs_icss_200MHz[] = {
    {CSL_PLL_ICSS,   250,    3,     10},  /* 200MHz ICSS clock with input clock as 24MHz*/
    {CSL_PLL_ICSS,   240,    3,     10}   /* 200MHz ICSS clock with input clock as 25MHz*/
};

const pllcConfig pllcConfigs_icss_225MHz[] = {
    {CSL_PLL_ICSS,   75,    1,     8},  /* 225MHz ICSS clock with input clock as 24MHz*/
    {CSL_PLL_ICSS,   72,    1,     8}   /* 225MHz ICSS clock with input clock as 25MHz*/
};

uint32_t Board_getNumPllcConfigs()
{
    return (sizeof(pllcConfigs) / sizeof(pllcConfig));
}

/* Function to initialize PLL module for external clock input */
Board_STATUS Board_PLLInitExt(void)
{
	uint32_t i;
	uint32_t numConfigs;

	numConfigs = Board_getNumPllcConfigs();
	for (i = 0; i < numConfigs; i++)
		init_pll(&pllcConfigs_extClk[i]);

    return BOARD_SOK;
}

/* Function to select the ICSS clock output.
 * Supports configuring the ICSS clock to either 200MHz and 225MHz.
 */
Board_STATUS Board_PLLICSSConfig(BoardIcssClkOut clkOut)
{
    Board_STATUS status = BOARD_SOK;
    Bool clkMode;

    /* Read the clock mode.
     * Input clock will be either 24MHz or 25MHz based on the clock mode */
    clkMode = Board_getClockMode();

    if(clkOut == BOARD_ICSS_PLL_CLK_225MHZ)
    {
        init_pll(&pllcConfigs_icss_225MHz[clkMode]);
    }
    else if(clkOut == BOARD_ICSS_PLL_CLK_200MHZ)
    {
        init_pll(&pllcConfigs_icss_200MHz[clkMode]);
    }
    else
    {
        /* Unsupported configuration  */
        status = BOARD_INVALID_PARAM;
    }

    return status;
}
