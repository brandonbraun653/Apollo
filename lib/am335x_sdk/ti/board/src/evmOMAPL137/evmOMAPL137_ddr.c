/**
 *  @file   evmOMAPL137_ddr.c
 *
 *  @brief  DDR initialization routines for OMAPL137 EVM
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

/*
 *  \brief  Setup Async-EMIFA to the specified timings using either NAND HW
 *          controller or normal EMIF controller                                
 *
 *  \return none
 */
static void Board_setupEMIFA(void)
{
    /* Use extended wait cycles to keep CE low during NAND access */
    hEmif->AWCC = 0xff;

    /* Setup CS2 - 8-bit normal async */
    hEmif->CE2CFG = 0x00300608;
    hEmif->NANDFCR &= ~1;

    /* Setup CS3 - 8-bit NAND */
    hEmif->CE3CFG = 0x00300388;
    hEmif->NANDFCR |= 2;

    /* Setup CS4 - 8-bit normal async */
    hEmif->CE4CFG = 0x00a00504;  // Setup=0, Strobe=A, Hold=0, TA=1, 8-bit
    hEmif->NANDFCR &= ~4;

    /* Setup CS5 - 8-bit normal async */
    hEmif->CE5CFG = 0x00a00504;  // Setup=0, Strobe=A, Hold=0, TA=1, 8-bit
    hEmif->NANDFCR &= ~8;
}

/*
 *  \brief  Configure SDRAM.
 *
 *  \return none
 */
static void Board_setupEMIFB(void)
{
    /* ISSI IS42S16160B-6BL SDRAM, 2 x 16M x 16 (32-bit data path), 133MHz */
    hEmifb->SDCFG = 0       /* SDRAM Bank Config Register */
        |( 1 << 15)         /* Unlock timing registers */
        |( 2 << 9 )         /* CAS latency is 2 */
        |( 2 << 4 )         /* 4 bank SDRAM devices */
        |( 1 << 0 );        /* 512-word pages requiring 9 column address bits */

    hEmifb->SDRFC = 0       /* SDRAM Refresh Control Register */
        |( 0 << 31)         /* Low power mode disabled */
        |( 0 << 30)         /* MCLK stoping disabled */
        |( 0 << 23)         /* Selects self refresh instead of power down */
        |( 1040 <<0);       /* Refresh rate = 7812.5ns / 7.5ns */

    hEmifb->SDTIM1 = 0      /* SDRAM Timing Register 1 */
        |( 25 << 25)        /* (67.5ns / 7.55ns) - 1 = TRFC  @ 133MHz */
        |( 2 << 22 )        /* (20ns / 7.5ns) - 1 =TRP */
        |( 2 << 19 )        /* (20ns / 7.5ns) - 1 = TRCD */
        |( 1 << 16 )        /* (14ns / 7.5ns) - 1 = TWR */
        |( 5 << 11 )        /* (45ns / 7.5ns) - 1 = TRAS */
        |( 8 <<  6 )        /* (67.5ns / 7.5ns) - 1 = TRC */
        |( 2 <<  3 );       /* *(((4 * 14ns) + (2 * 7.5ns)) / (4 * 7.5ns)) -1. = TRRD */

    hEmifb->SDTIM2 = 0      /* SDRAM Timing Register 2 */
        |( 14<< 27)         /* not sure how they got this number. the datasheet says value should be */
        |( 9 << 16)         /* ( 70 / 7.5) - 1 */
        |( 5 << 0 );        /* ( 45 / 7.5 ) - 1 */

    hEmifb->SDCFG = 0       /* SDRAM Bank Config Register */
	    |( 1 << 16)
        |( 0 << 15)         /* Unlock timing registers */
        |( 2 << 9 )         /* CAS latency is 2 */
        |( 2 << 4 )         /* 4 bank SDRAM devices */
        |( 1 << 0 );        /* 512-word pages requiring 9 column address bits */
}

/*
 *  \brief  Sets the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input
 *
 *  \return none
 */
Board_STATUS Board_DDR3Init(void)
{
	Board_setupEMIFA();
	Board_setupEMIFB();
	
    return (BOARD_SOK);
}
