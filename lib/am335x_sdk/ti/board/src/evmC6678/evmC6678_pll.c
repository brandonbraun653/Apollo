/******************************************************************************
 * Copyright (c) 2015 Texas Instruments Incorporated - http://www.ti.com
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

const keystonePllcReg keystonePllcRegs[] = {
	{CSL_BOOT_CFG_REGS + 0x328, CSL_BOOT_CFG_REGS + 0x32c}, /* system PLL */
	{CSL_BOOT_CFG_REGS + 0x338, CSL_BOOT_CFG_REGS + 0x33c}, /* PA PLL */
	{0,                         0                        }, /* no ARM PLL */
	{CSL_BOOT_CFG_REGS + 0x330, CSL_BOOT_CFG_REGS + 0x334}  /* DDR3 PLL */
};

const pllcConfig pllcConfigs[] = {
    {CSL_PLL_SYS,    20,     1,      2}, /* 1000 MHz */
    {CSL_PLL_PA,     21,     1,      2}, /* 1050 MHz*/
    {CSL_PLL_DDR3,   20,     1,      2}, /* 666.67 MHz*/
};

uint32_t Board_getNumPllcConfigs()
{
    return (sizeof(pllcConfigs) / sizeof(pllcConfig));
}

