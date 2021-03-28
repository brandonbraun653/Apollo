/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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
 * \file    pmlib_cpuidle_a9host.c
 *
 * \brief   This file declares the interface for MPU CPU Idle functionality.
 *          This is a low latency power saving mode which allows fast wakeup
 *          depending on the power mode set.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include "pmhal_prcm.h"
#include "pmhal_mm.h"
#include "pmhal_cm.h"
#include "pmhal_pdm.h"
#include "pmlib_cpuidle.h"
#include "pmlib_cpuidle_utils_a9host.h"
#include "pm_utils.h"

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

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

pmErrCode_t PMLIBCpuIdle(pmhalPrcmPdState_t pwrst)
{
    pmErrCode_t status = PM_SUCCESS;

    if (pwrst < PMHAL_PRCM_PD_STATUS_COUNT)
    {
        /* Just call WFI to enable auto clock gating.  Powering off A9 has
         * unknown wakeup consequences due to potential silicon bug */
        PmlibDoWFI();
    }
    else
    {
        status = PM_BADARGS;
    }

    return status;
}

pmErrCode_t PMLIBCpuModePrepare(pmhalPrcmModuleId_t moduleId,
                                pmlibCpuIdleMode_t  mode)
{
    pmErrCode_t                retVal;
    pmhalPrcmPdState_t         pdState;
    pmhalPrcmCdClkTrnModes_t   cdMode;
    pmhalPrcmPdId_t            pdId;
    pmhalPrcmCdId_t            cdId;
    pmhalPrcmCpuId_t           cpuId;

    if (mode == PMLIB_IDLE_CPU_MODE_IDLE)
    {
        /* A9 idle should keep a9 powered on and just go to auto clock gating
         * mode.  Powering off A9 has unknown wakeup consequences due to
         * potential silicon bug */
        pdState = PMHAL_PRCM_PD_STATE_ON_ACTIVE;
        cdMode  = PMHAL_PRCM_CD_CLKTRNMODES_HW_AUTO;
        retVal  = PM_SUCCESS;
    }
    else
    {
        retVal = PM_BADARGS;
    }

    if (retVal == PM_SUCCESS)
    {
        /* Get the CPU id for the given module id */
        cpuId = PMUtilsGetCpuId(moduleId);

        /* Verify that module id belongs to CPU clock domain */
        if (cpuId != PMHAL_PRCM_CPU_ID_UNDEF)
        {
            cdId = PMUtilsGetCdId((pmhalPrcmModuleId_t) moduleId);
            pdId = PMUtilsGetPdId(cdId);

            /* Enable CPU Power/Clock domain to configure to next power state */
            retVal = (pmErrCode_t) PMHALPdmSetPDState(pdId, pdState,
                                                      PM_TIMEOUT_NOWAIT);
            if (retVal == PM_SUCCESS)
            {
                retVal = (pmErrCode_t)PMHALCMSetCdClockMode(cdId,
                                                            cdMode,
                                                            PM_TIMEOUT_NOWAIT);
            }
        }
        else
        {
            retVal = PM_BADARGS;
        }
    }
    return retVal;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */

