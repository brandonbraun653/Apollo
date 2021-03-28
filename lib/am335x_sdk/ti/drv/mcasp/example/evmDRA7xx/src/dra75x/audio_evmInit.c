/*
 * audio_evmInit.c
 *
 * This file contains Audio application related EVM (platform) specific routines
 * implementation.
 * This is part of the EVM Initialization library (evmInit) which contains pinmux
 * enabling routines for peripherals used by the application, and may contain
 * related device pre-driver initialization routines.
 *
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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
 *  (C) Copyright 2017, Texas Instruments, Inc
 *
 */

#include <xdc/std.h>

#include <Audio_evmInit.h>
#include <ti/csl/soc.h>
#include <mcasp_cfg.h>
#include <ti/board/board.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>

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

/* extern void PinmuxConfig(void); */

extern Board_STATUS Board_init(Board_initCfg);

static void Configure_XBAR(void);

/*
 * Function to enable the pinmux for the mcasp and i2c devices in the soc.
 *
 */
void configureAudio(void)
{
    Board_STATUS  stat = BOARD_SOK;
    Board_initCfg arg  = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_UART_STDIO |
                         BOARD_INIT_PLL | BOARD_INIT_MODULE_CLOCK;

    stat = Board_init(arg);

    Configure_XBAR();
}

static void Configure_XBAR(void)
{
    /* Map the IRQ crossbar for McASP3, according to the interrupts reserved in cslr_soc.h and used
     * in mcasp_soc.c to assign interrupt for McASP Rx and Tx interrupt events Please note that the API below takes
     * the mapped DMAReq  with 1 as the base, whereas CSL_EDMA3_CHA_MCASP'n' are with base 0. */
#if defined(__ARM_ARCH_7A__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_INTC_EVENTID_MCASP2_RXINT, CSL_XBAR_McASP3_IRQ_AREVT);
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_INTC_EVENTID_MCASP2_TXINT, CSL_XBAR_McASP3_IRQ_AXEVT);
#elif defined(__TI_ARM_V7M4__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_INTC_EVENTID_MCASP2_RXINT, CSL_XBAR_McASP3_IRQ_AREVT);
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_INTC_EVENTID_MCASP2_TXINT, CSL_XBAR_McASP3_IRQ_AXEVT);
#elif defined(_TMS320C6X)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_DSP1, CSL_INTC_EVENTID_MCASP2_RXINT, CSL_XBAR_McASP3_IRQ_AREVT);
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_DSP1, CSL_INTC_EVENTID_MCASP2_TXINT, CSL_XBAR_McASP3_IRQ_AXEVT);
#endif

    /* Map the DMA crossbar for McASP3, according to the interrupts reserved in cslr_soc.h and used
     * in mcasp_soc.c to assign interrupt for McASP Rx and Tx DMA events Please note that the API below takes
     * the mapped DMAReq  with 1 as the base, whereas CSL_EDMA3_CHA_MCASP'n' are with base 0. */
    CSL_xbarDmaConfigure(CSL_XBAR_DMA_CPU_ID_EDMA, CSL_EDMA3_CHA_MCASP2_RX + 1, CSL_XBAR_DMA_McASP3_DREQ_RX);
    CSL_xbarDmaConfigure(CSL_XBAR_DMA_CPU_ID_EDMA, CSL_EDMA3_CHA_MCASP2_TX + 1, CSL_XBAR_DMA_McASP3_DREQ_TX);
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

    if(hwInfo.muxNum==MCASP_INVALID_MUX_NUM)
    {
#ifdef _TMS320C6X
       /* Choosing a free Crossbar Instance number from DSP1_INTC Default Interrupt Mapping
        * in the DRA75x TRM . Please note that this is fore Core 0 , i.e DSP1 only*/
       /* Freely available cross bar instance numbers for DSP1 */
       hwInfo.txMuxOutEvent=CSL_XBAR_INST_DSP1_IRQ_74;
       hwInfo.rxMuxOutEvent=CSL_XBAR_INST_DSP1_IRQ_75;
       /* The CPU event numbers corresponding to the above  */
       hwInfo.cpuTxEventNumber = 74;
       hwInfo.cpuRxEventNumber = 75;

       hwInfo.muxNum=MUXINTCP_CROSSBAR_MUXNUM_DSP1; /* We use DSP1 for this demo */

#elif defined(__TI_ARM_V7M4__)
      /* M4 */

       /* Choosing a free Crossbar Instance number from IPU_INTC Default Interrupt Mapping
        * in the DRA75x TRM. Please note that this is fore Core 0 , i.e IPU1 */
       hwInfo.txMuxOutEvent=CSL_XBAR_INST_IPU1_IRQ_27;
       hwInfo.rxMuxOutEvent=CSL_XBAR_INST_IPU1_IRQ_28;

      /* The corresponding interrupts for MPU  */
       hwInfo.txIntNum = 27;
       hwInfo.rxIntNum = 28;

       hwInfo.cpuTxEventNumber =  27;
       hwInfo.cpuRxEventNumber =  28;

       hwInfo.muxNum=MUXINTCP_CROSSBAR_MUXNUM_IPU1;

#else
       /* A15 */
       /* Choosing a free Crossbar Instance number from MPU_INTC Default Interrupt Mapping
        * in the DRA75x TRM */
       hwInfo.txMuxOutEvent=CSL_XBAR_INST_MPU_IRQ_141;
       hwInfo.rxMuxOutEvent=CSL_XBAR_INST_MPU_IRQ_142;

       /* The corresponding interrupts for MPU  */
       hwInfo.txIntNum = (141+32);
       hwInfo.rxIntNum = (142+32);

       hwInfo.cpuTxEventNumber = (141+32);
       hwInfo.cpuRxEventNumber = (142+32);

       hwInfo.muxNum=MUXINTCP_CROSSBAR_MUXNUM_MPU;
#endif
    }
    /* Write back */
    Mcasp_socSetInitCfg(MCASP_NUM,&hwInfo);
}

/* ========================================================================== */
/*                              END OF FILE                                   */
/* ========================================================================== */
