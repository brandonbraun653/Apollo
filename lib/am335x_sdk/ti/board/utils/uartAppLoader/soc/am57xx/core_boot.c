/**
 *  \file   core_boot.c
 *
 *  \brief  This file contain functions related to slave core boot-up.
 *
 */

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <sbl_slave_core_boot.h>

/**
 * \brief    core_Bringup function calls the relevant functions
 *           to bring the particular core, out of reset.
 *
 * \param    entry - pointer to the structure holding the
 *           entry address of the applications for different cores
 *
 **/
 
void core_Bringup(sblEntryPoint_t *entry)
{
#if defined(SOC_AM572x) || defined(SOC_AM574x)
	if (entry->entryPoint_MPU_CPU1 != 0)
	{
	/* Bring the A15 CPU1 core out of reset. */
	    SBL_MPU_CPU1_BringUp(entry->entryPoint_MPU_CPU1);
	}

	if (entry->entryPoint_DSP2 != 0)
	{
	    /* Release the DSP2 core out of reset */
	    SBL_DSP2_BringUp(entry->entryPoint_DSP2);
	}

	if (entry->entryPoint_IPU1_CPU1 != 0)
	{
	    SBL_IPU1_CPU1_BringUp(entry->entryPoint_IPU1_CPU1);
	}

	if (entry->entryPoint_IPU2_CPU0 != 0)
	{
	    /* Release the IPU2 core out of reset and set the Entry point */
	    SBL_IPU2_CPU0_BringUp(entry->entryPoint_IPU2_CPU0);
	}

	if (entry->entryPoint_IPU2_CPU1 != 0)
	{
	    /* Release the IPU2 CPU1 core out of reset and set the Entry point */
	    SBL_IPU2_CPU1_BringUp(entry->entryPoint_IPU2_CPU1);
	}
#endif
	if (entry->entryPoint_DSP1 != 0)
	{
	    /* Release the DSP1 core out of reset */
	    SBL_DSP1_BringUp(entry->entryPoint_DSP1);
	}

	if (entry->entryPoint_IPU1_CPU0 != 0)
	{
	    /* Release the IPU1 core out of reset and set the Entry point */
	    SBL_IPU1_CPU0_BringUp(entry->entryPoint_IPU1_CPU0);
	}

}