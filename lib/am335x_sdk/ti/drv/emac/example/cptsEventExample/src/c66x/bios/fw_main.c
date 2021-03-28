/*  (C) Copyright 2015, Texas Instruments, Inc.
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

/** ============================================================================
 *   @n@b main
 *
 *   @b Description
 *   @n Entry point for CPTS Event example application.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return
 *   @n None
 * =============================================================================
 */
#include <ti/drv/emac/example/cptsEventExample/src/cpts_event_test.h>
#include <stdio.h>
#include "ti/csl/csl_bootcfgAux.h"

#ifdef  SIMULATOR_SUPPORT
uint32_t autodetectLogic = FALSE;
#else
uint32_t autodetectLogic = TRUE;
#endif
int32_t main (void)
{
    Task_Params                	taskParams;
    uint32_t                    bootMode;

    /* Init internal cycle counter */
    TSCL = 1;

#if 0
    if (autodetectLogic == TRUE)
    {
       bootMode = CSL_BootCfgGetBootMode() & 0x7;

       if (bootMode == 0)
    	  no_bootMode = TRUE;
       else
    	  no_bootMode = FALSE;
    }
    else
#endif     
    {
    	no_bootMode = TRUE;
    }

    if (!cpswSimTest)
    {
 	   if (no_bootMode == TRUE)
 	   {
 		passPowerUp();
 	   }
    }

    /* Initialize the task params */
    Task_Params_init(&taskParams);

    /* Create the CPTS Event example task */
    Task_create((Task_FuncPtr)&Cpts_EventTestApp, &taskParams, NULL);

    /* Start the BIOS Task scheduler */
	BIOS_start ();

	return 0;
}

