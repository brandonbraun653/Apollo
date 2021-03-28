/**
 *  @file   evmOMAPL137_pll.c
 *
 *  @brief  Routines to initialize PLL module
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

#include "board_cfg.h"
#include "board_internal.h"
#include "board_pll.h"

/*
 *  \brief  Initializes SoC PLL clocks
 *
 *  \return BOARD_SOK 
 */
Board_STATUS Board_PLLInit(void)
{
    int delay = 0;

    /* Configure ARM, DSP at 300MHz, EMIFs at 133MHz */
    unsigned int CLKMODE = 0;
    unsigned int PLLM = 24;
    unsigned int POSTDIV = 1;
    unsigned int PLLDIV3 = 2;
    unsigned int PLLDIV5 = 5;
    unsigned int PLLDIV7 = 7;
	
	/* Unlock MMR register write access */
	Board_unlockMMR();

    /* Set PLLEN=0 to bypass the PLL */
    hPllRegs->PLLCTL &=  0xFFFFFFFE; 	/* PLL BYPASS MODE */

    /* Wait for 4 cycles to allow PLLEN mux switches properly to bypass clock */
    for(delay = 0; delay < PLLEN_MUX_SWITCH; delay++) {;}

    /* Select the Clock Mode bit 8 as External Clock or On Chip Oscillator */
	hPllRegs->PLLCTL &= 0xFFFFFEFF;
    hPllRegs->PLLCTL |= (CLKMODE << 8);  /* Make CLKSRC as BootPacket to pass the value */

    /* Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR */
    hPllRegs->PLLCTL &=  0xFFFFFFDF;

    /* PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Primus */
    hPllRegs->PLLCTL &=  0xFFFFFDFF;

    /* Clear PLLRST bit to 0 -Reset the PLL */
    hPllRegs->PLLCTL &= 0xFFFFFFF7;

    /* PLL initialization sequence */

    /* Power up the PLL- PWRDN bit set to 0 to bring the PLL out of power down bit */
    hPllRegs->PLLCTL &= 0xFFFFFFFD;

    /* Program the required multiplier value in PLLM */
    hPllRegs->PLLM    = PLLM; /* Make PLLMULTIPLEIR as bootpacket*/

    /* If desired to scale all the SYSCLK frequencies of a given PLLC, program the POSTDIV ratio */
    hPllRegs->POSTDIV = 0x8000 | POSTDIV; /* Make POSTDIV as bootpacket*/

    /* If Necessary program the PLLDIVx */
    /* Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress */
    while((hPllRegs->PLLSTAT & 0x1) == 1){;}

    /* Program the RATIO field in PLLDIVx with the desired divide factors. 
	   In addition, make sure in this step you leave the PLLDIVx.DxEN bits 
	   set so clocks are still enabled (default) */
    hPllRegs->PLLDIV3 = 0x8000 | PLLDIV3; /* Make PLLDIV3 as bootpacket, do it for other PLLDIVx to if required*/
    hPllRegs->PLLDIV5 = 0x8000 | PLLDIV5; /* Make PLLDIV5 as bootpacket, do it for other PLLDIVx to if required*/
    hPllRegs->PLLDIV7 = 0x8000 | PLLDIV7; /* Make PLLDIV7 as bootpacket, do it for other PLLDIVx to if required*/

    /* Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition */
    hPllRegs->PLLCMD |= 0x1;

	/* Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment) */
    while((hPllRegs->PLLSTAT & 0x1) == 1) {;}

    /* Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset */
    hPllRegs->PLLCTL |= 0x8;

    /* Wait for PLL to lock. See PLL spec for PLL lock time */
    for(delay = 0; delay < PLL_LOCK_TIME_CNT; delay++) {;} /* Make PLL_LOCK_TIME_CNT as boot Packet */

    /* Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode */
    hPllRegs->PLLCTL |=  0x1;
    
    hSysCfg->CFGCHIP3 |= 0x4;       // Enable 4.5 divider PLL
    hSysCfg->CFGCHIP3 |= 0x1;       // Select 4.5 divider for EMIFB clock source only (not EMIFA)

	return (BOARD_SOK);
}
