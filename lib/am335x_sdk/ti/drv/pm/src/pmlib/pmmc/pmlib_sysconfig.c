/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017
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
 * \file    pmlib_sysconfig.c
 *
 * \brief   This file defines the function used for
 *          switching on or switching off modules or putting them in HW
 *          controlled Auto Clock Gated mode via PMMC
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "pmhal_pmmc.h"
#include "pmhal_ti_sci.h"

#include "pmlib_sysconfig_pmmc.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

pmErrCode_t PMLIBSysConfigPmmcSetPowerState(
    const pmlibSysConfigPmmcPowerStateParams_t *inputTable,
    uint32_t                                    numConfig,
    uint32_t                                    timeout,
    pmlibSysConfigPmmcErrReturn_t              *resultReturn)
{
    pmErrCode_t status   = PM_SUCCESS;
    uint32_t    modCount = 0U;
    uint32_t    logError = 0U;

    /* Check if the errors can be logged. Done only when a valid pointer
     * is passed to the API for returning the results.
     */
    if (NULL != resultReturn)
    {
        logError = 1U;
    }

    if ((NULL == inputTable) || (0U == numConfig))
    {
        status = PM_BADARGS;
    }
    else
    {
        /* Loop through the number of modules given to the API */
        for (modCount = 0U; modCount < numConfig; modCount++)
        {
            pmhalPmmcModuleId_t currMod = inputTable[modCount].modId;
            uint32_t            desiredPwrSt = inputTable[modCount].pwrState;

            /* Check if the input parameters are correct */
            if ((PM_SUCCESS != PMHALPmmcModuleIsIdValid(currMod)) ||
                (PM_SUCCESS != PMHALPmmcModuleIsStateValid(desiredPwrSt)))
            {
                if (1U == logError)
                {
                    resultReturn[modCount].moduleId  = currMod;
                    resultReturn[modCount].failCause = PM_BADARGS;
                }
                status = PM_FAIL;
            }
            else
            {
                pmlibSysConfigPmmcErrReturn_t *currResult = NULL;
                if (1U == logError)
                {
                    currResult = &resultReturn[modCount];
                }

                status = PMHALPmmcModuleSetState(currMod, desiredPwrSt,
                                                 timeout);

                if ((status != PM_SUCCESS) &&
                    (1U == logError))
                {
                    currResult->moduleId = currMod;
                    currResult->failCause = status;
                }
            }
        }
    }

    return status;
}

pmErrCode_t PMLIBSysConfigPmmcPowerStateParams_init(
    pmlibSysConfigPmmcPowerStateParams_t *inputTable,
    uint32_t                              numConfig)
{
    pmErrCode_t status   = PM_SUCCESS;
    uint32_t    modCount = 0U;
    if ((NULL == inputTable) || (0U == numConfig))
    {
        status = PM_BADARGS;
    }
    else
    {
        /* Loop through the number of modules given. The Init API would
         * fill in the details of all the modules in a sequence of module IDs
         * and initialize the initial state of the modules to DISABLED. Based
         * on what the software wants to enable the modules corresponding to
         * that can be enabled/auto clock gated.
         */
        for (modCount = 0U; modCount < numConfig; modCount++)
        {
            inputTable[modCount].modId = (pmhalPmmcModuleId_t)
                                         ((uint32_t) PMHAL_PMMC_MOD_LOWER_BOUND
                                          +
                                          modCount + 1U);
            inputTable[modCount].pwrState = MSG_DEVICE_SW_STATE_AUTO_OFF;
        }
    }
    return status;
}

pmErrCode_t PMLIBSysConfigPmmcGetPowerState(
    pmhalPmmcModuleId_t                moduleId,
    uint32_t                          *currState,
    pmlibSysConfigPmmcDetailedState_t *detailedState)
{
    pmErrCode_t status = PM_SUCCESS;

    if (NULL == currState)
    {
        status = PM_BADARGS;
    }
    else
    {
        pmhalPmmcModuleId_t    currMod = moduleId;
        pmhalPmmcModuleState_t modState;
        uint32_t               timeout = PMHAL_PMMC_TIMEOUT_DEFAULT;

        status = PMHALPmmcModuleGetState(currMod,
                                         &modState,
                                         timeout);

        /* CONSIDERATION: Add calls to get clock state for all clocks mapped to
         *                module for complete state information */

        if (status == PM_SUCCESS)
        {
            *currState = modState.currentState;

            if (detailedState != NULL)
            {
                /* Return remaining state info if detailed structure passed */
                memset((void *)detailedState, 0, sizeof(*detailedState));
                detailedState->contextLossCount = modState.contextLossCount;
                detailedState->resets = modState.resets;
                detailedState->programmedState = modState.programmedState;
                detailedState->currentState = modState.currentState;
            }
        }
    }

    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */

