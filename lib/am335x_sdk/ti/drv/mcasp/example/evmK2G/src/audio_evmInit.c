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
 *  (C) Copyright 2009-2018, Texas Instruments, Inc
 *
 */

#include <xdc/std.h>
#define SW_I2C
#ifndef SW_I2C
#include <i2c/include/I2c.h>
#endif

#include <Audio_evmInit.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_bootcfg.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>  /* To use the socGetConfig/setConfig() APIs */
#include <mcasp_cfg.h>
#include <board.h>

#include <ti/csl/hw_types.h>
#include <ti/drv/uart/UART_stdio.h>
#include "MCASP_log.h"
extern Board_STATUS Board_init(Board_initCfg);


#if defined (_TMS320C6X)
#include <ti/sysbios/family/c66/tci66xx/CpIntc.h>
#else
#include <ti/sysbios/family/arm/a15/tci66xx/CpIntc.h>
#endif

typedef enum {
    PADCONFIG_MUX_MODE_PRIMARY = 0,  /**< Primary pin mux mode    */
    PADCONFIG_MUX_MODE_SECONDARY,    /**< Secondary pin mux mode  */
    PADCONFIG_MUX_MODE_TERTIARY,     /**< Tertiary pin mux mode   */
    PADCONFIG_MUX_MODE_QUATERNARY,   /**< Quaternary pin mux mode */
    PADCONFIG_MUX_MODE_QUINARY,      /**< Quinary pin mux mode    */
    PADCONFIG_MUX_MODE_SENARY        /**< Senary pin mux mode     */

} PadCfgMuxMode;

/*
 * Function to enable the pinmux for the mcasp and i2c devices in the soc.
 *
 */
void pinMuxSetMode_local(uint32_t padCfgId, PadCfgMuxMode muxMode)
{
	volatile uint32_t *padCfgBase;

    padCfgBase = &hBootCfg->PADCONFIG0;
    CSL_FINS(*(padCfgBase + padCfgId), BOOTCFG_PADCONFIG0_MUXMODE, muxMode);
}

/*
 * Function to configure the Audio parameters in the EVM.
 * THis includes providing the necessary clock needed for McASP such as
 * PLL values, Audio Oscillator config etc.
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

	/* Configure McASP AUXCLK source as AUDIO_OSCCLK  */
	hBootCfg->SERIALPORT_CLKCTL = 0;
	/* Enable audio oscillator  */
	hBootCfg->OSC_CTL = 0x200;	//SW2:SW1 = 01 (15 - 30 MHz)

	 {
		int padCfg;
		for (padCfg = 139; padCfg <= 191; padCfg++)
		{
			pinMuxSetMode_local(padCfg, PADCONFIG_MUX_MODE_QUINARY);
		}
	  }

   return;
}
/*
 * Function to configure SOC specific parameters. This includes SOC
 * specific parameters such as interrupt configuration using Muxes,
 * interrupt configuration etc.
 */
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

#ifdef _TMS320C6X
   /*  The interrupt IRQ_ goes to CIC for C66x. Plug the IRQ events to the
    * appropritate Mux out events and configure the same */
    if(hwInfo.muxNum==MCASP_INVALID_MUX_NUM)
    {
      hwInfo.muxNum=0; /* CIC Mux 0*/
    }

    if(hwInfo.txMuxOutEvent==MCASP_UNASSIGNED_MUX_EVENTNUM)
    {
      hwInfo.txMuxOutEvent=47; /* Choosing CIC_OUT_47. Please check to see if it is unused in the application */
      hwInfo.cpuTxEventNumber = 63; /* The INTC event corresponding to CIC_OUT_47 */
    }

    if(hwInfo.rxMuxOutEvent==MCASP_UNASSIGNED_MUX_EVENTNUM)
    {
       hwInfo.rxMuxOutEvent=48; /* Choosing CIC_OUT_48.Please check to see if it is unused in the application  */
       hwInfo.cpuRxEventNumber = 64; /* The INTC event corresponding to CIC_OUT_48 */
    }
#endif

    /* Write back */
    Mcasp_socSetInitCfg(MCASP_NUM,&hwInfo);
}

/* ========================================================================== */
/*                              END OF FILE                                   */
/* ========================================================================== */
