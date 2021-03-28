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
 * \file        pmlib_clkrate.c
 *
 * \brief       PMLIB Clock Rate Manager API implementation for PMMC.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>

#include "pmhal_pmmc.h"

#include "pmlib_clkrate_pmmc.h"

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

pmErrCode_t PMLIBClkRateSet(pmhalPmmcModuleId_t modId,
                            pmhalPmmcClockId_t  clkId,
                            uint32_t            clkRate)
{
    pmErrCode_t retVal;
    uint32_t    currRate = 0;

    /* Get the current Rate */
    retVal = PMLIBClkRateGet(modId, clkId, &currRate);
    /* Check if given rate is same as current rate */
    if ((PM_SUCCESS == retVal) && (currRate == clkRate))
    {
        retVal = PM_CLOCKRATE_SAME_FREQ_CHANGE_REQ;
    }

    if (PM_SUCCESS == retVal)
    {
        /* TODO: Verify clkId is valid for modId */

        retVal = PMHALPmmcClockSetRate(modId, clkId, clkRate);
    }

    return retVal;
}

pmErrCode_t PMLIBClkRateGet(pmhalPmmcModuleId_t modId,
                            pmhalPmmcClockId_t  clkId,
                            uint32_t           *clkRate)
{
    pmErrCode_t retVal = PM_SUCCESS;

    if (clkRate == NULL)
    {
        retVal = PM_BADARGS;
    }
    else
    {
        /* TODO: Verify clkId is valid for modId */

        retVal = PMHALPmmcClockGetRate(modId, clkId, clkRate);
    }
    return retVal;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

/* None */

