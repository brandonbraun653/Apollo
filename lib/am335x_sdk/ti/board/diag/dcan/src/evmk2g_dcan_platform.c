/*
 * Copyright (c) 2010-2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * \file   evmc66x_dcan_platform.c
 *
 * \brief  This file contains functions which configures the DCAN module.
 */

#include "platform_internal.h"

#if (PLATFORM_DCAN_IN)

/******************************************************************************
**                      INTERNAL FUNCTION DEFINITIONS
******************************************************************************/
/**
 * \brief   This function selects the DCAN pins for use. The DCAN pins
 *          are multiplexed with pins of other peripherals in the SoC
 *
 * \param   instanceNum       The DCAN instance to be used.
 *
 * \return  TRUE/FALSE.
 *
 */
void DCANPinMuxSetUp(uint32_t instNum, uint32_t boardType)
{
	/* Nothing to be done here. Pinmux taken care during platform init */
}

/**
 * \brief   This function initializes the DCAN message RAM.
 *
 * \param   instanceNum       The DCAN instance to be used.
 *
 * \return  None.
 *
 */
void DCANMsgRAMInit(uint32_t instNum)
{
	if(instNum == 0)
	{
		CSL_FINS(hBootCfg->DCAN_RAMINIT,
				 BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_START,
				 CSL_BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_START_MAX);

		while(!CSL_FEXT(hBootCfg->DCAN_RAMINIT,
		      BOOTCFG_DCAN_RAMINIT_DCAN0_RAMINIT_DONE));
	}
	else
	{
		CSL_FINS(hBootCfg->DCAN_RAMINIT,
				 BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_START,
				 CSL_BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_START_MAX);

		while(!CSL_FEXT(hBootCfg->DCAN_RAMINIT,
		      BOOTCFG_DCAN_RAMINIT_DCAN1_RAMINIT_DONE));
	}
}

/**
 * \brief   This function will enable the module clocks for DCAN.
 *
 * \return  None.
 *
 */
void DCANModuleClkConfig(uint32_t instNum)
{
	/* Nothing to be done here. Clock config is done during platform init */
}

#endif /* #if (PLATFORM_DCAN_IN) */
