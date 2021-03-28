/**
 *  @file   lcdkOMAPL138_pll.c
 *
 *  @brief  Routines to initialize PLL module
 *
 *  ============================================================================
 */
/******************************************************************************
 * Copyright (c) 2017 Texas Instruments Incorporated - http://www.ti.com
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
 *  \brief  Initializes core PLL clocks
 *
 *  \return BOARD_SOK 
 */
Board_STATUS Board_CorePLLConfig(void)
{
     volatile uint32_t delay = 0;
     uint32_t clkmode = 0;
     uint32_t pllm = 24;
     uint32_t postdiv = 1;
     uint32_t plldiv1 = 0; 
     uint32_t plldiv2 = 1; 
     uint32_t plldiv3 = 11; 
     uint32_t plldiv7 = 5;

    /* Clear PLL lock bit */
    CFGCHIP0 &= ~(0x00000010);

    /* Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR */
    hPLL0Cfg->PLLCTL &= ~(0x00000020);

    /* PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Freon */
    hPLL0Cfg->PLLCTL &= ~(0x00000200);

    /* Set PLLEN=0 to put in bypass mode*/
    hPLL0Cfg->PLLCTL &= ~(0x00000001);

    /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
    for(delay = 0; delay < PLLEN_MUX_SWITCH; delay++) {;}

    /* Select the Clock Mode bit 8 as External Clock or On Chip Oscilator*/
    hPLL0Cfg->PLLCTL &= 0xFFFFFEFF;
    hPLL0Cfg->PLLCTL |= (clkmode << 8);

    /*Clear PLLRST bit to reset the PLL */
    hPLL0Cfg->PLLCTL &= ~(0x00000008);

    /* Disable the PLL output*/
    hPLL0Cfg->PLLCTL |= (0x00000010);

    /* PLL initialization sequence
    Power up the PLL by setting PWRDN bit set to 0 */
    hPLL0Cfg->PLLCTL &= ~(0x00000002);

    /* Enable the PLL output*/
    hPLL0Cfg->PLLCTL &= ~(0x00000010);

    /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
    for(delay = 0; delay < PLL_STABILIZATION_TIME; delay++) {;}

    /*Program the required multiplier value in PLLM*/
    hPLL0Cfg->PLLM    = pllm;

    /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the POSTDIV ratio*/
    hPLL0Cfg->POSTDIV = 0x8000 | postdiv;

    /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
    while((hPLL0Cfg->PLLSTAT & 0x1) == 1){}

    /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
    hPLL0Cfg->PLLDIV1 = 0x8000 | plldiv1;             // Fixed Ratio /1
    hPLL0Cfg->PLLDIV2 = 0x8000 | plldiv2;             // Fixed Ratio /2
    hPLL0Cfg->PLLDIV4 = 0x8000 | (((plldiv1+1)*4)-1); // Fixed Ratio /4
    hPLL0Cfg->PLLDIV6 = 0x8000 | plldiv1;             // Fixed Ratio /1
    hPLL0Cfg->PLLDIV3 = 0x8000 | plldiv3;             // Variable Ratio (EMIF)
    hPLL0Cfg->PLLDIV7 = 0x8000 | plldiv7;             // Variable Ratio (RMII)


    /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
    hPLL0Cfg->PLLCMD |= 0x1;

    /*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
    while((hPLL0Cfg->PLLSTAT & 0x1) == 1) { }

    /*Wait for PLL to reset properly.*/
    for(delay = 0; delay < PLL_RESET_TIME_CNT; delay++) {;}

    /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
    hPLL0Cfg->PLLCTL |= 0x8;

    /*Wait for PLL to lock.*/
    for(delay = 0; delay < PLL_LOCK_TIME_CNT; delay++) {;}

    /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
    hPLL0Cfg->PLLCTL |=  0x1;

	return (BOARD_SOK);
}

/*
 *  \brief  Initializes DDR PLL clocks
 *
 *  \return BOARD_SOK 
 */
Board_STATUS Board_DDRPLLConfig(void)
{
    volatile uint32_t delay = 0;
    uint32_t pllm = 24;
    uint32_t postdiv = 1;
    uint32_t plldiv1 = 0; 
    uint32_t plldiv2 = 1; 
    uint32_t plldiv3 = 2;     

    /* Clear PLL lock bit */
    CFGCHIP3 &= ~(0x00000020);

    /* Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR */
    hPLL1Cfg->PLLCTL &= ~(0x00000020);

    /* PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Freon */
    hPLL1Cfg->PLLCTL &= ~(0x00000200);

    /* Set PLLEN=0 to put in bypass mode*/
    hPLL1Cfg->PLLCTL &= ~(0x00000001);

    /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
    for(delay = 0; delay < PLLEN_MUX_SWITCH; delay++) {;}

    /*Clear PLLRST bit to reset the PLL */
    hPLL1Cfg->PLLCTL &= ~(0x00000008);

    /* Disable the PLL output*/
    hPLL1Cfg->PLLCTL |= (0x00000010);

    /* PLL initialization sequence
    Power up the PLL by setting PWRDN bit set to 0 */
    hPLL1Cfg->PLLCTL &= ~(0x00000002);

    /* Enable the PLL output*/
    hPLL1Cfg->PLLCTL &= ~(0x00000010);

    /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
    for(delay = 0; delay < PLL_STABILIZATION_TIME; delay++) {;}

    /*Program the required multiplier value in PLLM*/
    hPLL1Cfg->PLLM    = pllm;

    /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the POSTDIV ratio*/
    hPLL1Cfg->POSTDIV = 0x8000 | postdiv;

    /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
    while(hPLL1Cfg->PLLSTAT & 0x1==1){}

    /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
    hPLL1Cfg->PLLDIV1 = 0x8000 | plldiv1;   // DDR frequency (aka 2X_CLK)
    hPLL1Cfg->PLLDIV2 = 0x8000 | plldiv2;   // Optional CFGCHIP3[ASYNC3_CLKSRC] clock source
    hPLL1Cfg->PLLDIV3 = 0x8000 | plldiv3;   // Optional PLL0 clock source

    /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
    hPLL1Cfg->PLLCMD |= 0x1;

    /*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
    while(hPLL1Cfg->PLLSTAT & 0x1==1) { }

    /*Wait for PLL to reset properly */
    for(delay = 0; delay < PLL_RESET_TIME_CNT; delay++) {;}

    /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
    hPLL1Cfg->PLLCTL |= 0x8;

    /*Wait for PLL to lock. See PLL spec for PLL lock time*/
    for(delay = 0; delay < PLL_LOCK_TIME_CNT; delay++) {;}

    /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
    hPLL1Cfg->PLLCTL |=  0x1;    
    
    return (BOARD_SOK);
}

/*
 *  \brief  Initializes PLL clocks
 *
 *  \return BOARD_SOK 
 */
Board_STATUS Board_PLLInit(void)
{
    Board_CorePLLConfig();
    Board_DDRPLLConfig();
    
    return (BOARD_SOK);
}
