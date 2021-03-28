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
 *  \file      pmlib_boardconfig.c
 *
 *  \brief     This file contains structure declarations for aggregating
 *             customer board specific power management related information
 *             such as - root clocks,ganging of voltage rails.
 */

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include "pmlib_boardconfig.h"
#include "pm_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/**
 *  \brief Structure defining Root Clock Frequencies in Hz
 */
uint32_t                rootClockFrequencies[] =
{
    /* PMHAL_PRCM_ROOT_CLK_SYS_CLKIN */
    24000000U,
    /* PMHAL_PRCM_ROOT_CLK_TCLKIN */
    0U,
    /* PMHAL_PRCM_ROOT_CLK_32K_PER */
    32786U,
    /* PMHAL_PRCM_ROOT_CLK_32K_RC */
    32786U,
    /* PMHAL_PRCM_ROOT_CLK_32K_RTC */
    32786U,
    /* PMHAL_PRCM_ROOT_CLK_32K_TPM */
    32786U,
    /* PMHAL_PRCM_ROOT_CLK_32K_MOSC */
    32786U
};

/**
 *  \brief Array of Structure defining relationship between voltage domains on
 *         the basis of Voltage rails shared
 */
pmlibBoardVdRailShare_t vdRailShareInfoList[] =
{
    {
        PMHAL_PRCM_VD_MPU,
        NULL,
        0U
    },
    {
        PMHAL_PRCM_VD_CORE,
        NULL,
        0U
    },
    {
        PMHAL_PRCM_VD_RTC,
        NULL,
        0U
    }
};

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

uint32_t *PMLIBBoardConfigGetRootClks(void)
{
    return rootClockFrequencies;
}

pmlibBoardVdRailShare_t *PMLIBBoardConfigGetVdRailShareInfo(void)
{
    return vdRailShareInfoList;
}

#ifdef __cplusplus
}
#endif
