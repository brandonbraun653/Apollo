/*
 * audio_evmInit.c
 *
 * This file contains Audio application related EVM (platform) specific routines
 * implementation. 
 * This is part of the EVM Initialization library (evmInit) which contains pinmux
 * enabling routines for peripherals used by the application, and may contain 
 * related device pre-driver initialization routines.
 *
 * Copyright (C) 2009-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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
*/

/**
 *  \file   audio_evmInit.c
 *
 *  \brief  This file contains the board specific code for enabling the use of
 *          audio driver.
 *
 *  (C) Copyright 2009, Texas Instruments, Inc
 *
 */

#include <xdc/std.h>
#define SW_I2C
#ifndef SW_I2C
#include <i2c/include/I2c.h>
#endif
#include <xdc/runtime/System.h>
#include <Audio_evmInit.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/soc.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <mcasp_cfg.h>
#include <board.h>

#include <ti/csl/hw_types.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/starterware/include/hw/soc_am335x.h>
#include <ti/starterware/include/hw/hw_control_am335x.h>
#include <ti/starterware/include/am335x/hw_cm_per.h>
#include <ti/starterware/include/am335x/hw_cm_wkup.h>
#include <ti/starterware/include/chipdb.h>
#include <ti/starterware/include/prcm.h>
#include <ti/starterware/include/error.h>
#include <ti/starterware/include/pinmux.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_v1.h>
#include <ti/board/board.h>
#include "MCASP_log.h"

/*============================================================================*/
/*                          MACRO DEFINITIONS                                 */
/*============================================================================*/

/**
 *  \brief    Initializes platform specific modules
 *
 *  This function initializes the modules like PLL, DDR, I2C etc
 *  which are required for audio processing. Need to call this function
 *  before doing any HW related operations.
 *
 *  \return    Platform_EOK on Success or error code
 */


extern Board_STATUS Board_init(Board_initCfg);

void PRCM_ClockConfig(void);

//#define HW_WR_REG32(addr, data)   *(unsigned int*)(addr) =(unsigned int)(data)

/*
 * Function to enable the pinmux for the mcasp and i2c devices in the soc.
 *
 */
void configureAudio(void)
{
	Board_STATUS stat = BOARD_SOK;
	Board_initCfg arg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;

	stat = Board_init(arg);

    if( BOARD_SOK != stat)
    {
        MCASP_log("Board init failed!!");
        return;
    }

#ifndef DEVICE_LOOPBACK
	// set the pinmux for the McASP 1 for Audio Codec Loopback example
	/* McASP1 AXR2 */
	HWREG(SOC_CONTROL_REGS + CONTROL_CONF_MII1_COL) = (4
		| (0x1 << CONTROL_CONF_MII1_COL_CONF_MII1_COL_PUDEN_SHIFT)
		/* | (0x1 << CONTROL_CONF_MII1_COL_CONF_MII1_COL_RXACTIVE_SHIFT) */
		/* | (0x1 << CONTROL_CONF_MII1_COL_CONF_MII1_COL_SLEWCTRL_SHIFT) */
		);

	/* McASP1 ACLKX */
	HWREG(SOC_CONTROL_REGS + CONTROL_CONF_MII1_CRS) = (4
		| (0x1 << CONTROL_CONF_MII1_CRS_CONF_MII1_CRS_PUDEN_SHIFT)
		| (0x1 << CONTROL_CONF_MII1_CRS_CONF_MII1_CRS_RXACTIVE_SHIFT)
		| (0x1 << CONTROL_CONF_MII1_CRS_CONF_MII1_CRS_SLEWCTRL_SHIFT)
		);

	/* McASP1 FSX */
	HWREG(SOC_CONTROL_REGS + CONTROL_CONF_MII1_RXERR) = (4
		| (0x1 << CONTROL_CONF_MII1_RXERR_CONF_MII1_RXERR_PUDEN_SHIFT)
		| (0x1 << CONTROL_CONF_MII1_RXERR_CONF_MII1_RXERR_RXACTIVE_SHIFT)
		| (0x1 << CONTROL_CONF_MII1_RXERR_CONF_MII1_RXERR_SLEWCTRL_SHIFT)
		);

	/* McASP1 AHCLKX in mode 7 */	/* McASP1 AXR3 in mode 5 */		/* testing */
	/* Confirm whether AHCLKX is required for this -- AHCLKX is a Master clock
	 * and Audio codec has master as Oscillator clock, so this pin will be used as
	 * McASP1 AXR3 */
	HWREG(SOC_CONTROL_REGS + CONTROL_CONF_RMII1_REFCLK) = (4
		| (0x1 << CONTROL_CONF_RMII1_REFCLK_CONF_RMII1_REFCLK_PUDEN_SHIFT)
		| (0x1 << CONTROL_CONF_RMII1_REFCLK_CONF_RMII1_REFCLK_RXACTIVE_SHIFT) );
		/* | (0x1 << CONTROL_CONF_RMII1_REFCLK_CONF_RMII1_REFCLK_SLEWCTRL_SHIFT) */

#endif

	/* Enable the PRCM Clock to get a 24.6 MHz clock as Aux Clock to MCASP */
	PRCM_ClockConfig();
}


/* This function sets up the CORE PLL which provides AUXCLK to McASP */
void PRCM_ClockConfig(void)
{
#ifdef DEVICE_LOOPBACK
    uint32_t dpllMult; /* M */
    uint32_t dpllDiv; /* N */
    uint32_t inputClk;
    uint32_t dpllPostDivM4;
    uint32_t dpllPostDivM5;
    uint32_t dpllPostDivM6;
    uint32_t crystalFreqSel;

	/* Set the Core PLL (ADPLLS), as per Section 8.1.6.7 in the TRM */
	/*
	1. Switch PLL to bypass mode by setting CM_CLKMODE_DPLL_CORE.DPLL_EN to 0x4

	2. Wait for CM_IDLEST_DPLL_CORE.ST_MN_BYPASS = 1 to ensure PLL is in bypass
	(CM_IDLEST_DPLL_CORE.ST_DPLL_CLK should also change to 0 to denote the PLL is unlocked).
	3. Configure Multiply and Divide values by setting CM_CLKSEL_DPLL_CORE.DPLL_MULT and
	DPLL_DIV to the desired values.
	4. Configure M4, M5 and M6 dividers by setting HSDIVIDER_CLKOUT1_DIV bits in
	CM_DIV_M4_DPLL_CORE,CM_DIV_M5_DPLL_CORE, and CM_DIV_M6_DPLL_CORE to the
	desired values.
	5. Switch over to lock mode by setting CM_CLKMODE_DPLL_CORE.DPLL_EN to 0x7.
	6. Wait for CM_IDLEST_DPLL_CORE.ST_DPLL_CLK = 1 to ensure PLL is locked
	(CM_IDLEST_DPLL_CORE.ST_MN_BYPASS should also change to 0 to denote the PLL is out of
	bypass mode).
	*/
    /* Get input clock frequency. */
    crystalFreqSel = HW_RD_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_STATUS,
        CONTROL_STATUS_SYSBOOT1,
        CONTROL_STATUS_SYSBOOT1_SHIFT);
    switch(crystalFreqSel)
     {
         case 0U:
         {
             inputClk = 19U;
             break;
         }

         case 1U:
         {
             inputClk = 24U;
             break;
         }

         case 2U:
         {
             inputClk = 25U;
             break;
         }

         case 3U:
         {
             inputClk = 26U;
             break;
         }

         default:
         {
             break;
         }
     }

     /*
      * pllDiv = (inputClk/refClk) - 1U
      * PLL divider derived from input clock with referance clock as 1MHz.
      * PLL divider is same for all PLLs.
      */

    /* The below values are chosen for this EVM because of the following reason */
    /* The MCASP needs a bit clock of 3.072 Mhz (ACLK) - This is derived from
     *   48Khz * 64 bits (because of L+R 32 bit channels) = 3.072 Mhz
     *   But ACLK = AuxCLK /( AHCLKDIV + ACLKDIV)
     *   If we keep AHCLKDIV + ACLKDIV = 8 approx, we get a desired AuxCLK=  24.576 Mhz
     *
     *   In AM335x , the AUXCLK is provided by L4_PER_CLK which is the output of Core PLL
     *   By programming the ADPLLS and the dividers of the Core PLL appropriately, we can
     *   get the 24.576 Mhz, or in this example a close enough value 24.61 Mhz.
     *
     *   The L4_PER_CLK = CLKDCOOUT (of the ADPLLS) /(M4 Div) * (2)
     *                  = (2*(M/(N+1))/((M4 Div)*2)
     */
     dpllDiv = inputClk - 1U; /* N=23 */
     dpllMult = 1000U; /* M= 1000 */
     dpllPostDivM4 = 39;
     dpllPostDivM5 = 8U;/* Not used here */
     dpllPostDivM6 = 4U;/* Not used here */
    /* Put the PLL in bypass mode */
     HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_CORE,
         CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN,
         CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN_SHIFT,
         CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN_DPLL_MN_BYP_MODE);

     /* Wait for DPLL to go in to bypass mode */

     while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_CORE,
         CM_WKUP_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS,
         CM_WKUP_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS_SHIFT));

     /* Set the multipler and divider values for the PLL */

     HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_CORE,
         CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_MULT,
         CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_MULT_SHIFT,
         dpllMult);
     HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_CORE,
         CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_DIV,
         CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_DIV_SHIFT,
         dpllDiv);

     /* Configure the High speed dividers */

     /* Set M4 divider */
     HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M4_DPLL_CORE,
         CM_WKUP_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_DIV,
         CM_WKUP_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_DIV_SHIFT,
         dpllPostDivM4);

     /* Set M5 divider */

     HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M5_DPLL_CORE,
         CM_WKUP_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_DIV,
         CM_WKUP_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_DIV_SHIFT,
         dpllPostDivM5);

     /* Set M6 divider */

     HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M6_DPLL_CORE,
         CM_WKUP_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_DIV,
         CM_WKUP_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_DIV_SHIFT,
         dpllPostDivM6);

     /* Now LOCK the PLL by enabling it */

     HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_CORE,
         CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN,
         CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN_SHIFT,
         CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN);

     while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_CORE,
                         CM_WKUP_CM_IDLEST_DPLL_CORE_ST_DPLL_CLK,
                         CM_WKUP_CM_IDLEST_DPLL_CORE_ST_DPLL_CLK_SHIFT));

#else
     /// if the audio codec loopback is selected, eanble the clock for McASP 1
 	/* For McASP1 clock setting */
 	HWREG(SOC_PRCM_REGS + CM_PER_MCASP1_CLKCTRL) = CM_PER_MCASP1_CLKCTRL_MODULEMODE_ENABLE ;
#endif
}

void configMcASP_SocHwInfo()
{
  /* Configure the interrupts for the McASP Instance MCASP_NUM */
  /* ON Keystone, it involves CIC programming as well.
   * The McASP does that internally, if configured with the correct parameters.
   * Such as muxNum, muxInEvent, muxOutEvent,
   * cpuInEventNum, cpuIntNum
  */
    Mcasp_HwInfo hwInfo;

    Mcasp_socGetInitCfg(MCASP_NUM, &hwInfo);


/* Change anything if needed */
    Mcasp_socSetInitCfg(MCASP_NUM,&hwInfo);
}

/* ========================================================================== */
/*                              END OF FILE                                   */
/* ========================================================================== */
