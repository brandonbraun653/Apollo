/**
 * \file   dmtimer_app.c
 *
 * \brief  Source file containing the DMTIMER IP related configuration functions.
 *         These functions will be called by example application to configure
 *         the dmtimer for their specific need. 
 *  
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "prcm.h"
#include "error.h"
#include "soc_control.h"
/* Application header files */
#include "dmtimer_app.h"
/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
/* None */
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/* None */
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   this function configures Interrupt parameters in the Interrupt module
 *
 * \param   pDmtimerObj - pointer to DmtimerObj - #dmtimerAppCfg_t
 *
 * \retval  status   Any of the following values, 
 *          - S_PASS - Interrupt Config passed sucessfully 
 *          - E_FAIL - Config failed
 *          - E_INVALID_PARAM - Parameter passed is invalid
 */
int32_t DMTimerAppIntrConfig(dmtimerAppCfg_t *pDmtimerObj);                             

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/*None*/

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void DMTIMERAppInit(dmtimerAppCfg_t *pDmtimerObj)
{
    uint32_t status;

    /* Clock source selection */
    SOCCtrlTimerClkSrcSelect(pDmtimerObj->instNum,
                                SOC_CTRL_DMTIMER_CLK_SRC_M_OSC_24M);
    /* Clock Configuration  */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_DMTIMER, pDmtimerObj->instNum, FALSE);
    
    /* PRCM API (PRCMIsModuleEnabled) is to be used so that module enable can be 
       done else where. Access to  dmtimer registers should happen after checking 
       whether the module is turned on and clocked.  */
    if (S_PASS == status)
    {
        if (NULL!= pDmtimerObj->pFnIntrHandler)
        /*there is an Interrupt handler to be installed */
        {
            DMTimerAppIntrConfig(pDmtimerObj);
        }    
        /* Reset the timer instance which needs to be used */
        DMTimerReset(pDmtimerObj->instAddr);

        /**  Note:
          *  Calculate the Inital count and Reload values depending on time
          *  resolution and the clock source selected
          */

        /* Load the counter with the initial count value */
        DMTimerCounterSet(pDmtimerObj->instAddr, pDmtimerObj->timerInitialCount);

        /* Load the load register with the reload count value */
        DMTimerReloadSet(pDmtimerObj->instAddr,
            pDmtimerObj->timerReloadCount);

        /* Configure/Set the DMTimer for Application specific mode such as 
        auto reload .*/
        DMTimerModeConfigure(pDmtimerObj->instAddr, pDmtimerObj->configMode);
    
        if (pDmtimerObj->enableClockPrescaler)
        /*Input clock needs to be scaled down by enabling the prescaler */
        {
            DMTimerPreScalerClkEnable(pDmtimerObj->instAddr,
                            pDmtimerObj->clockPrescalerRatio);
        }    
        
        if (NULL!= pDmtimerObj->pFnIntrHandler)
        /*there is an Interrupt handler to be installed */
        {
            /* Enable the DMTimer interrupts */
            DMTimerIntEnable(pDmtimerObj->instAddr, pDmtimerObj->intrMask);
        }   
    }
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/*
* Do the necessary DMTimer configurations on to AINTC.
*/
int32_t DMTimerAppIntrConfig(dmtimerAppCfg_t *pDmtimerObj)
 {
    /* Precondition : Enable ARM interrupt control and initialise the Interrupt 
    Controller. */
    
    /* local Structure which holds the Interrupt parameters. */
    intcIntrParams_t intrParams;  
    int32_t returnVal = S_PASS;
    intrParams.triggerType = pDmtimerObj->trigType;
    
    /* Currently hard coded priority number */
    intrParams.priority = 0x20U;
	intrParams.pFnIntrHandler = pDmtimerObj->pFnIntrHandler;
	/* Pointer to the app object being passed to handler */
    intrParams.pUserParam = pDmtimerObj->pUserParam;
    /* Currently hard coded - non secure mode */
    intrParams.isIntrSecure = FALSE;
	
	returnVal = INTCConfigIntr(pDmtimerObj->intrLine, &intrParams,FALSE);
    
    return (returnVal);
 }
 
