/******************************************************************************
 * Copyright (c) 2015 Texas Instruments Incorporated - http://www.ti.com
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
#include "board_clock.h"

static bool set_psc_state(uint32_t domainNum, uint32_t moduleNum, CSL_PSC_MODSTATE state)
{
    uint32_t timeoutCnt = 5;

    /* If state already set, do nothing */
    if (CSL_FEXT(hPscRegs->MDSTAT[moduleNum], PSC_MDSTAT_STATE) == state)
	    return true;

    if (state == PSC_MODSTATE_ENABLE)
        CSL_PSC_enablePowerDomain(domainNum);

    /* Enable the clock for the module */
    CSL_PSC_setModuleNextState(moduleNum, state);

    /* Start the state transition */
    CSL_PSC_startStateTransition(domainNum);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone(domainNum)) {
        BOARD_delay(10);
        timeoutCnt--;
        if (timeoutCnt == 0)
            return false;
	}

    return true;
}

Board_STATUS Board_moduleClockInit()
{
    uint32_t i;
    uint32_t numConfigs;

    numConfigs = Board_getNumPSCconfigs();

    for (i = 0; i < numConfigs; i++) {
        if (set_psc_state(pscConfigs[i].domainNum, pscConfigs[i].moduleNum, PSC_MODSTATE_ENABLE) == false)
            return BOARD_INIT_CLOCK_FAIL;
    }

    return BOARD_SOK;
}
