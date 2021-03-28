/**
 *  @file   evmOMAPL137_clock.c
 *
 *  @brief  Module clock configurations for OMAPL137 EVM.
 *
 *  ============================================================================
 */
/******************************************************************************
 * Copyright (c) 2016-2017 Texas Instruments Incorporated - http://www.ti.com
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
#include "ti/csl/csl_psc.h"
#include "ti/csl/csl_pscAux.h"

/*
 *  \brief  Enables the PSC module clocks
 *
 *  \return none
 */
void Board_moduleClockEnable(uint32_t module)
{
    /* Set NEXT state to ENABLE */
    CSL_PSC_setModuleNextState(module, PSC_MODSTATE_ENABLE);

	if(module > PSC0_MAX_LPSC_MODULE)
	{
		/* Set GO bit to initiate state transition */
        CSL_PSC_startStateTransition2(0);
	
		/* Wait for power state transition to finish */
		while (!CSL_PSC_isStateTransitionDone2(0));
	}
	else
	{
		/* Set GO bit initiate state transition */
        CSL_PSC_startStateTransition(0);
	
		/* Wait for power state transition to finish */
		while (!CSL_PSC_isStateTransitionDone(0));
	}
	
	/* Wait for state transition */
	while (CSL_PSC_getModuleState(module) != CSL_PSC_MDSTAT_STATE_ENABLE);
}

#ifndef _TMS320C6X
/*
 *  \brief  Enables emulation suspend soource for Timer in ARM9
 *
 *  \return none
 */
static void Board_suspendSourceConfig (void)
{
    hSysCfg->SUSPSRC = (hSysCfg->SUSPSRC & ~(SYSCFG_SUSPSRC_TIMER64_0SRC_MASK))
                         | ((SYSCFG_SUSPSRC_TIMER64_01SRC_ARM << SYSCFG_SUSPSRC_TIMER64_0SRC_SHIFT)
                          & SYSCFG_SUSPSRC_TIMER64_0SRC_MASK);
    hSysCfg->SUSPSRC = (hSysCfg->SUSPSRC & ~(SYSCFG_SUSPSRC_TIMER64_1SRC_MASK))
                         | ((SYSCFG_SUSPSRC_TIMER64_01SRC_ARM << SYSCFG_SUSPSRC_TIMER64_1SRC_SHIFT)
                          & SYSCFG_SUSPSRC_TIMER64_1SRC_MASK);
}
#endif

/*
 *  \brief  Enables clock for all the modules
 *
 *  \return BOARD_SOK
 */
Board_STATUS Board_moduleClockInit(void)
{
    Board_moduleClockEnable(CSL_PSC_CC);
    Board_moduleClockEnable(CSL_PSC_TC0);
    Board_moduleClockEnable(CSL_PSC_TC1);
	Board_moduleClockEnable(CSL_PSC_EMIFA);
	Board_moduleClockEnable(CSL_PSC_SPI0);
	Board_moduleClockEnable(CSL_PSC_MMCSD0);
#ifndef _TMS320C6X
	Board_moduleClockEnable(CSL_PSC_AINTC);
#endif
	Board_moduleClockEnable(CSL_PSC_SECCNTL_KEYMGR);
    Board_moduleClockEnable(CSL_PSC_UART0);
    Board_moduleClockEnable(CSL_PSC_SCR0_SS);
    Board_moduleClockEnable(CSL_PSC_SCR1_SS);
    Board_moduleClockEnable(CSL_PSC_SCR2_SS);
    Board_moduleClockEnable(CSL_PSC_RESV0);  //PRU PSC

	Board_moduleClockEnable(CSL_PSC_USB0);
	Board_moduleClockEnable(CSL_PSC_USB1);
	Board_moduleClockEnable(CSL_PSC_GPIO);
	Board_moduleClockEnable(CSL_PSC_UHPI);
	Board_moduleClockEnable(CSL_PSC_EMAC);
	Board_moduleClockEnable(CSL_PSC_EMIFB);
	Board_moduleClockEnable(CSL_PSC_MCASP0);
	Board_moduleClockEnable(CSL_PSC_MCASP1);
	Board_moduleClockEnable(CSL_PSC_MCASP2);
	Board_moduleClockEnable(CSL_PSC_SPI1);
	Board_moduleClockEnable(CSL_PSC_I2C1);
	Board_moduleClockEnable(CSL_PSC_UART1);
	Board_moduleClockEnable(CSL_PSC_UART2);
	Board_moduleClockEnable(CSL_PSC_LCDC);
	Board_moduleClockEnable(CSL_PSC_EHRPWM0_1_2);
	Board_moduleClockEnable(CSL_PSC_ECAP0_1_2);
    Board_moduleClockEnable(CSL_PSC_EQEP0_1_2);
    Board_moduleClockEnable(CSL_PSC_SCR8_SS);
    Board_moduleClockEnable(CSL_PSC_SCR7_SS);
    Board_moduleClockEnable(CSL_PSC_SCR12_SS);
#ifndef _TMS320C6X
    /*In OMPAL137 SOC by default emulation suspend signal is
	controlled by DSP which fails the timer to work in case of
	ARM9 example. to avoid this the emulation suspend control
	for timer is given to ARM core.*/
	Board_suspendSourceConfig();
#endif

	return (BOARD_SOK);
}
