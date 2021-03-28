/**
 *  @file   lcdkOMAPL138_clock.c
 *
 *  @brief  Module clock configurations for OMAPL138 LCDK.
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

#include "board_internal.h"
#include <ti/csl/csl_psc.h>
#include <ti/csl/csl_pscAux.h>

/*
 *  \brief  Enables the PSC module clocks
 *
 *  \return none
 */
void Board_moduleClockEnable(uint32_t module)
{
    /* Set NEXT state to ENABLE */
    CSL_PSC_setModuleNextState(module, PSC_MODSTATE_ENABLE);

	if(module >= PSC0_MAX_LPSC_MODULE)
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
	while (CSL_PSC_getModuleState(module) != PSC_MODSTATE_ENABLE);
}

/*
 *  \brief  Sync Reset function for the LPSC
 *
 *  \return none
 */
void Board_moduleClockSyncReset(uint32_t module)
{
    /* Set NEXT state to ENABLE */
    CSL_PSC_setModuleNextState(module, PSC_MODSTATE_SYNCRST);

    if(module >= PSC0_MAX_LPSC_MODULE)
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
    while (CSL_PSC_getModuleState(module) != PSC_MODSTATE_SYNCRST);
}

/*
 *  \brief  Enables clock for all the modules
 *
 *  \return BOARD_SOK
 */
Board_STATUS Board_moduleClockInit(void)
{
	/* Enable clock for the modules under PSC0 */
    Board_moduleClockEnable(CSL_PSC_CC);
    Board_moduleClockEnable(CSL_PSC_TC0);
    Board_moduleClockEnable(CSL_PSC_TC1);
    Board_moduleClockEnable(CSL_PSC_EMIFA);
    Board_moduleClockEnable(CSL_PSC_SPI0);
    Board_moduleClockEnable(CSL_PSC_MMCSD0);
#ifndef _TMS320C6X
    Board_moduleClockEnable(CSL_PSC_AINTC);
#endif
    Board_moduleClockEnable(CSL_PSC_UART0);
    Board_moduleClockEnable(CSL_PSC_SCR0_SS);
    Board_moduleClockEnable(CSL_PSC_SCR1_SS);
    Board_moduleClockEnable(CSL_PSC_SCR2_SS);

    /* Enable clock for the modules under PSC1 */
    Board_moduleClockEnable(CSL_PSC_EDMA_CC1);
    Board_moduleClockEnable(CSL_PSC_USB20);
    Board_moduleClockEnable(CSL_PSC_USB11);
    Board_moduleClockEnable(CSL_PSC_GPIO);
    Board_moduleClockEnable(CSL_PSC_UHPI);
    Board_moduleClockEnable(CSL_PSC_EMAC);
    Board_moduleClockEnable(CSL_PSC_MCASP0);
    Board_moduleClockEnable(CSL_PSC_VPIF);
    Board_moduleClockEnable(CSL_PSC_SPI1);
    Board_moduleClockEnable(CSL_PSC_I2C1);
    Board_moduleClockEnable(CSL_PSC_UART1);
    Board_moduleClockEnable(CSL_PSC_UART2);
    Board_moduleClockEnable(CSL_PSC_MCBSP0);
    Board_moduleClockEnable(CSL_PSC_MCBSP1);
    Board_moduleClockEnable(CSL_PSC_LCDC);
    Board_moduleClockEnable(CSL_PSC_EPWM);
    Board_moduleClockEnable(CSL_PSC_MMCSD1);
    Board_moduleClockEnable(CSL_PSC_UPP);
    Board_moduleClockEnable(CSL_PSC_ECAP);
    Board_moduleClockEnable(CSL_PSC_EDMA_TC2);

	return (BOARD_SOK);
}
