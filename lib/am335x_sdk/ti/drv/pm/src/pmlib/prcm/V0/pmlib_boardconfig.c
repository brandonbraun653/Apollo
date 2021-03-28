/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2014
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
 *  \file      pmlib_boardconfig.h
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
    /* PMHAL_PRCM_ROOT_CLK_PCIESREF_ACS */
    100000000U,
    /* PMHAL_PRCM_ROOT_CLK_RMII */
    50000000U,
    /* PMHAL_PRCM_ROOT_CLK_SYS_32K */
    32786U,
    /* PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1 */
    20000000U,
    /* PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2 */
    22579200U
};

#if defined (SOC_TDA2XX) || defined (SOC_AM572x) || defined (SOC_DRA75x)
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
        PMHAL_PRCM_VD_IVAHD,
        NULL,
        0U
    },
    {
        PMHAL_PRCM_VD_DSPEVE,
        NULL,
        0U
    },
    {
        PMHAL_PRCM_VD_GPU,
        NULL,
        0U
    },
    {
        PMHAL_PRCM_VD_RTC,
        NULL,
        0U
    }
};
#else
/**
 *  \brief Array defining Power Domain which share same Voltage rails with
 *         PMHAL_PRCM_VD_IVAHD
 */
pmhalPrcmVdId_t         PMHAL_PRCM_VD_IVAHD_railShareList[] =
{
    PMHAL_PRCM_VD_DSPEVE,
    PMHAL_PRCM_VD_GPU
};
/**
 *  \brief Array defining Power Domain which share same Voltage rails with
 *         PMHAL_PRCM_VD_DSPEVE
 */
pmhalPrcmVdId_t         PMHAL_PRCM_VD_DSPEVE_railShareList[] =
{
    PMHAL_PRCM_VD_IVAHD,
    PMHAL_PRCM_VD_GPU
};
/**
 *  \brief Array defining Power Domain which share same Voltage rails with
 *         PMHAL_PRCM_VD_GPU
 */
pmhalPrcmVdId_t         PMHAL_PRCM_VD_GPU_railShareList[] =
{
    PMHAL_PRCM_VD_DSPEVE,
    PMHAL_PRCM_VD_IVAHD
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
        PMHAL_PRCM_VD_IVAHD,
        PMHAL_PRCM_VD_IVAHD_railShareList,
        PM_UTIL_VSIZE_TYPE(PMHAL_PRCM_VD_IVAHD_railShareList,
                           uint32_t)
    },
    {
        PMHAL_PRCM_VD_DSPEVE,
        PMHAL_PRCM_VD_DSPEVE_railShareList,
        PM_UTIL_VSIZE_TYPE(PMHAL_PRCM_VD_DSPEVE_railShareList,
                           uint32_t)
    },
    {
        PMHAL_PRCM_VD_GPU,
        PMHAL_PRCM_VD_GPU_railShareList,
        PM_UTIL_VSIZE_TYPE(PMHAL_PRCM_VD_GPU_railShareList,
                           uint32_t)
    },
    {
        PMHAL_PRCM_VD_RTC,
        NULL,
        0U
    }
};
#endif
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
