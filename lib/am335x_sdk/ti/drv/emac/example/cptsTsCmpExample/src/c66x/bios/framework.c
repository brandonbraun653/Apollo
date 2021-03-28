/**
 * @file framework.c
 *
 * @brief
 *  This file holds all the platform specific framework
 *  initialization and setup code.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009-2013, Texas Instruments, Inc.
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
#include <ti/drv/emac/example/cptsTsCmpExample/src/cpts_ts_cmp.h>

#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_psc.h>
#include <ti/csl/csl_pscAux.h>

/***************************************************************************************
 * FUNCTION PURPOSE: Power up PA subsystem
 ***************************************************************************************
 * DESCRIPTION: this function powers up the PA subsystem domains
 ***************************************************************************************/
void passPowerUp (void)
{

#ifndef NSS_LITE
    /* PASS power domain is turned OFF by default. It needs to be turned on before doing any
     * PASS device register access. This not required for the simulator. */

    /* Set PASS Power domain to ON */
    CSL_PSC_enablePowerDomain (CSL_PSC_PD_NETCP);

    /* Enable the clocks for PASS modules */
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_CPGMAC,  PSC_MODSTATE_ENABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_NETCP);
    
    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_NETCP));
    
#else

    /* Set NSS Power domain to ON */        
    CSL_PSC_enablePowerDomain (CSL_PSC_PD_NSS);

    /* Enable the clocks for NSS modules */
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_NSS, PSC_MODSTATE_ENABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_NSS);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_NSS));
    
    /* Set SA Power domain to ON */        
#endif
}

/** ============================================================================
 *   @n@b Config_CPTS
 *
 *   @b Description
 *   @n Init and configure CPTS module
 *
 *   @param[in]
 *   @n toggle      1: Toggle mode
 *                  0: non-Toggle mpde
 *
 *   @return
 *   @n None
 * =============================================================================
 */
void Config_CPTS (uint32_t toggle)
{
    CSL_CPTS_CONTROL    ctrl;
    uint32_t            refClockSelect = 0;
    
    memset(&ctrl, 0, sizeof(CSL_CPTS_CONTROL));
    ctrl.cptsEn = 1;
    ctrl.tsCompToggle = toggle;
    ctrl.ts64bMode = 1;
    
    CSL_CPTS_disableCpts();
    
    CSL_CPTS_setRFTCLKSelectReg (refClockSelect);   
    
    CSL_CPTS_setCntlReg(&ctrl);

}


void CycleDelay (int32_t count)
{
    uint32_t                  TSCLin;

    if (count <= 0)
        return;

    /* Get the current TSCL  */
    TSCLin = TSCL ;

    while ((TSCL - TSCLin) < (uint32_t)count);
}

void CycleDelayTo (int32_t time)
{
    uint32_t                  TSCLin, count;

    /* Get the current TSCL  */
    TSCLin = TSCL ;
    count = time - TSCLin;

    while ((TSCL - TSCLin) < count);
}


void APP_exit (int32_t code)
{
	BIOS_exit(code);
}

/* Nothing past this point */
