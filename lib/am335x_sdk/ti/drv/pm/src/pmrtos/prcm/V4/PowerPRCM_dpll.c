/*
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== PowerPRCM_dpll.c ========
 */
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <ti/drv/pm/include/prcm/pmhal_prcm.h>
#include <PowerPRCM_deviceInit.h>

#ifdef __cplusplus
extern "C" {
#endif

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

/*********************************************************************/
/* 24 MHZ */
/*********************************************************************/

pmhalPrcmPllPostDivValue_t dpllPerPostDivCfgOppNom_24[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 5} /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllMpuPostDivCfgOppNom_24[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1} /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDdrPostDivCfgOppNom_24[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M4, 2}  /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDispPostDivCfgOppNom_24[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 6} /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllCorePostDivCfgOppNom_24[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M4, 10}, /* div_m4_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M5, 8 }, /* div_m5_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M6, 4 }  /* div_m6_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllExtdevPostDivCfgOppNom_24[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 18} /* div_m2_clkcfg */
};

pmhalPrcmDpllConfig_t      dpllPerCfgOppNom_24 =
{
    400,                        /* multiplier */
    9,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllPerPostDivCfgOppNom_24,
    (sizeof (dpllPerPostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOppLow_24 =
{
    25,                         /* multiplier */
    1,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllMpuPostDivCfgOppNom_24,
    (sizeof (dpllMpuPostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOppNom_24 =
{
    25,                         /* multiplier */
    0,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllMpuPostDivCfgOppNom_24,
    (sizeof (dpllMpuPostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOppOd_24 =
{
    30,                         /* multiplier */
    0,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllMpuPostDivCfgOppNom_24,
    (sizeof (dpllMpuPostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOppHigh_24 =
{
    800,                        /* multiplier */
    23,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllMpuPostDivCfgOppNom_24,
    (sizeof (dpllMpuPostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOppHigh2_24 =
{
    1000,                       /* multiplier */
    23,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllMpuPostDivCfgOppNom_24,
    (sizeof (dpllMpuPostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllDdrCfgOppNom_24 =
{
    50,                         /* multiplier */
    2,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllDdrPostDivCfgOppNom_24,
    (sizeof (dpllDdrPostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllDispCfgOppNom_24 =
{
    50,                         /* multiplier */
    1,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllDispPostDivCfgOppNom_24,
    (sizeof (dpllDispPostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllCoreCfgOppNom_24 =
{
    125,                        /* multiplier */
    2,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllCorePostDivCfgOppNom_24,
    (sizeof (dpllCorePostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllExtdevCfgOppNom_24 =
{
    375,                        /* multiplier */
    9,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllExtdevPostDivCfgOppNom_24,
    (sizeof (dpllExtdevPostDivCfgOppNom_24) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t     *pDpllPerCfg_24[] =
{
    &dpllPerCfgOppNom_24,
    &dpllPerCfgOppNom_24,
    &dpllPerCfgOppNom_24,
    &dpllPerCfgOppNom_24,
    &dpllPerCfgOppNom_24
};

pmhalPrcmDpllConfig_t     *pDpllMpuCfg_24[] =
{
    &dpllMpuCfgOppLow_24,  /* OPP 50 */
    &dpllMpuCfgOppNom_24,  /* OPP 100 */
    &dpllMpuCfgOppOd_24,   /* OPP 120 */
    &dpllMpuCfgOppHigh_24, /* OPP Turbo */
    &dpllMpuCfgOppHigh2_24 /* OPP Nitro */
};

pmhalPrcmDpllConfig_t     *pDpllDdrCfg_24[] =
{
    &dpllDdrCfgOppNom_24,
    &dpllDdrCfgOppNom_24,
    &dpllDdrCfgOppNom_24,
    &dpllDdrCfgOppNom_24,
    &dpllDdrCfgOppNom_24
};

pmhalPrcmDpllConfig_t     *pDpllDispCfg_24[] =
{
    &dpllDispCfgOppNom_24,
    &dpllDispCfgOppNom_24,
    &dpllDispCfgOppNom_24,
    &dpllDispCfgOppNom_24,
    &dpllDispCfgOppNom_24
};

/* Core has OPP Low (50) and Nom (100) but only use NOM for now*/
pmhalPrcmDpllConfig_t     *pDpllCoreCfg_24[] =
{
    &dpllCoreCfgOppNom_24, /* &dpllCoreCfgOppLow_24 */
    &dpllCoreCfgOppNom_24,
    &dpllCoreCfgOppNom_24,
    &dpllCoreCfgOppNom_24,
    &dpllCoreCfgOppNom_24
};

pmhalPrcmDpllConfig_t     *pDpllExtdevCfg_24[] =
{
    &dpllExtdevCfgOppNom_24,
    &dpllExtdevCfgOppNom_24,
    &dpllExtdevCfgOppNom_24,
    &dpllExtdevCfgOppNom_24,
    &dpllExtdevCfgOppNom_24
};

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

int32_t PRCM_getDpllStructure(pmhalPrcmNodeId_t       dpllId,
                              pmhalPrcmSysClkVal_t    sysClk,
                              uint32_t                opp,
                              uint32_t                siliconPackageType,
                              pmhalPrcmDpllConfig_t **dpllCfg)
{
    int32_t retVal = PM_SUCCESS;
    if (PMHAL_PRCM_SYSCLK_24_MHZ == sysClk)
    {
        switch (dpllId)
        {
            case PMHAL_PRCM_DPLL_PER:
                *dpllCfg = pDpllPerCfg_24[opp];
                break;
            case PMHAL_PRCM_DPLL_MPU:
                *dpllCfg = pDpllMpuCfg_24[opp];
                break;
            case PMHAL_PRCM_DPLL_DDR:
                *dpllCfg = pDpllDdrCfg_24[opp];
                break;
            case PMHAL_PRCM_DPLL_DISP:
                *dpllCfg = pDpllDispCfg_24[opp];
                break;
            case PMHAL_PRCM_DPLL_CORE:
                *dpllCfg = pDpllCoreCfg_24[opp];
                break;
            case PMHAL_PRCM_DPLL_EXTDEV:
                *dpllCfg = pDpllExtdevCfg_24[opp];
                break;
            default:
                /* Nothing to be done here */
                break;
        }
        retVal = PM_SUCCESS;
    }
    else
    {
        retVal = PM_BADARGS;
    }
    return retVal;
}

#ifdef __cplusplus
}
#endif

