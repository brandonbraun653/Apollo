/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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

/*  CLK CONFIGS SYSTEM CLOCK 19.2MHZ */



/*********************************************************************/
/* 20 MHZ */
/*********************************************************************/

static pmhalPrcmPllPostDivValue_t dpllCore15X15PostDivCfgOppNom_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  4 },  /* Div_m3_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 8 },  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 4 },  /* Div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 44},  /* Div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 4 },  /* Div_h14_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H21, 11},  /* Div_h21_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H22, 5 },  /* Div_h22_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H23, 10},  /* Div_h23_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllCore12X12PostDivCfgOppNom_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  6 },  /* Div_m3_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 8 },  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 4 },  /* Div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 44},  /* Div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 6 },  /* Div_h14_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H21, 11},  /* Div_h21_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H22, 5 },  /* Div_h22_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H23, 10},  /* Div_h23_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllPerPostDivCfgOppNom_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  8},  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  3},  /* Div_m3_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 6},  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 8},  /* Div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 8},  /* Div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 4}   /* Div_h14_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllDdr3PostDivCfgOppNom_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 8 },  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 31},  /* Div_h12_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllLpDdr2PostDiv333MHzCfgOppNom_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 4 },  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 31},  /* Div_h12_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllGmac15X15PostDivCfgOppNom_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  4 },  /* Div_m3_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 40},  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 8 },  /* Div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 4 }  /* Div_h13_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllGmac12X12PostDivCfgOppNom_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  6 },  /* Div_m3_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 40},  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 8 },  /* Div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 6 }  /* Div_h13_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllCore15X15PostDivCfgOppOd_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  4 },  /* Div_m3_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 8 },  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 4 },  /* Div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 44},  /* Div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 3 },  /* Div_h14_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H21, 11},  /* Div_h21_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H22, 5 },  /* Div_h22_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H23, 10},  /* Div_h23_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllCore15X15PostDivCfgOppHigh_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  4 },  /* Div_m3_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 8 },  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 4 },  /* Div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 44},  /* Div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 3 },  /* Div_h14_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H21, 11},  /* Div_h21_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H22, 5 },  /* Div_h22_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H23, 10},  /* Div_h23_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllGmac15X15PostDivCfgOppOd_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  3 },  /* Div_m3_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 40},  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 8 },  /* Div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 3 }   /* Div_h13_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllGmac15X15PostDivCfgOppHigh_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4 },  /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  3 },  /* Div_m3_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 40},  /* Div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 8 },  /* Div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 3 }   /* Div_h13_clkcfg */
};

static pmhalPrcmPllPostDivValue_t dpllEveVidDsp15X15PostDivCfgOppNom_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1},    /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3, 2}     /* Div_m3_clkcfg  */
};

static pmhalPrcmPllPostDivValue_t dpllEveVidDsp15X15PostDivCfgOppOd_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2},    /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3, 2}     /* Div_m3_clkcfg  */
};

static pmhalPrcmPllPostDivValue_t dpllEveVidDsp15X15PostDivCfgOppHigh_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 5},    /* Div_m2_clkcfg  */
    {PMHAL_PRCM_DPLL_POST_DIV_M3, 2}     /* Div_m3_clkcfg  */
};

static pmhalPrcmDpllConfig_t      dpllCore15X15CfgOppNom_20 =
{
    266,                             /* Multiplier */
    4,                               /* Divider */
    0,                               /* DutyCycleCorrector */
    dpllCore15X15PostDivCfgOppNom_20,
    (sizeof (dpllCore15X15PostDivCfgOppNom_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllCore15X15CfgOppOd_20 =
{
    266,                            /* Multiplier */
    4,                              /* Divider */
    0,                              /* DutyCycleCorrector */
    dpllCore15X15PostDivCfgOppOd_20,
    (sizeof (dpllCore15X15PostDivCfgOppOd_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllCore15X15CfgOppHigh_20 =
{
    266,                              /* Multiplier */
    4,                                /* Divider */
    0,                                /* DutyCycleCorrector */
    dpllCore15X15PostDivCfgOppHigh_20,
    (sizeof (dpllCore15X15PostDivCfgOppHigh_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllCore12X12CfgOppNom_20 =
{
    266,                             /* Multiplier */
    4,                               /* Divider */
    0,                               /* DutyCycleCorrector */
    dpllCore12X12PostDivCfgOppNom_20,
    (sizeof (dpllCore12X12PostDivCfgOppNom_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllPerCfgOppNom_20 =
{
    192,                       /* Multiplier */
    4,                         /* Divider */
    0,                         /* DutyCycleCorrector */
    dpllPerPostDivCfgOppNom_20,
    (sizeof (dpllPerPostDivCfgOppNom_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllDdr3CfgOppNom532MHz_20 =
{
    266,                        /* Multiplier */
    4,                          /* Divider */
    0,                          /* DutyCycleCorrector */
    dpllDdr3PostDivCfgOppNom_20,
    (sizeof (dpllDdr3PostDivCfgOppNom_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllLpDdr2CfgOppNom333MHz_20 =
{
    166,                                /* Multiplier */
    4,                                  /* Divider */
    0,                                  /* DutyCycleCorrector */
    dpllLpDdr2PostDiv333MHzCfgOppNom_20,
    (sizeof (dpllLpDdr2PostDiv333MHzCfgOppNom_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllGmac15X15CfgOppNom_20 =
{
    250,                             /* Multiplier */
    4,                               /* Divider */
    0,                               /* DutyCycleCorrector */
    dpllGmac15X15PostDivCfgOppNom_20,
    (sizeof (dpllGmac15X15PostDivCfgOppNom_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllGmac15X15CfgOppOd_20 =
{
    250,                            /* Multiplier */
    4,                              /* Divider */
    0,                              /* DutyCycleCorrector */
    dpllGmac15X15PostDivCfgOppOd_20,
    (sizeof (dpllGmac15X15PostDivCfgOppOd_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllGmac15X15CfgOppHigh_20 =
{
    250,                              /* Multiplier */
    4,                                /* Divider */
    0,                                /* DutyCycleCorrector */
    dpllGmac15X15PostDivCfgOppHigh_20,
    (sizeof (dpllGmac15X15PostDivCfgOppHigh_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllGmac12X12CfgOppNom_20 =
{
    250,                             /* Multiplier */
    4,                               /* Divider */
    0,                               /* DutyCycleCorrector */
    dpllGmac12X12PostDivCfgOppNom_20,
    (sizeof (dpllGmac12X12PostDivCfgOppNom_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllEveVidDsp15X15CfgOppNom_20 =
{
    238,                                  /* Multiplier */
    7,                                    /* Divider */
    0,                                    /* DutyCycleCorrector */
    dpllEveVidDsp15X15PostDivCfgOppNom_20,
    (sizeof (dpllEveVidDsp15X15PostDivCfgOppNom_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllEveVidDsp15X15CfgOppOd_20 =
{
    238,                                 /* Multiplier */
    7,                                   /* Divider */
    0,                                   /* DutyCycleCorrector */
    dpllEveVidDsp15X15PostDivCfgOppOd_20,
    (sizeof (dpllEveVidDsp15X15PostDivCfgOppOd_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t      dpllEveVidDsp15X15CfgOppHigh_20 =
{
    149,                                   /* Multiplier */
    3,                                     /* Divider */
    0,                                     /* DutyCycleCorrector */
    dpllEveVidDsp15X15PostDivCfgOppHigh_20,
    (sizeof (dpllEveVidDsp15X15PostDivCfgOppHigh_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

static pmhalPrcmDpllConfig_t     *pDpllCore15X15Cfg_20[] =
{
    &dpllCore15X15CfgOppNom_20,
    &dpllCore15X15CfgOppNom_20,
    &dpllCore15X15CfgOppOd_20,
    &dpllCore15X15CfgOppHigh_20
};

static pmhalPrcmDpllConfig_t     *pDpllCore12X12Cfg_20[] =
{
    &dpllCore12X12CfgOppNom_20,
    &dpllCore12X12CfgOppNom_20,
    &dpllCore12X12CfgOppNom_20,
    &dpllCore12X12CfgOppNom_20
};

static pmhalPrcmDpllConfig_t     *pDpllDdr3Cfg532MHz_20[] =
{
    &dpllDdr3CfgOppNom532MHz_20,
    &dpllDdr3CfgOppNom532MHz_20,
    &dpllDdr3CfgOppNom532MHz_20,
    &dpllDdr3CfgOppNom532MHz_20
};

static pmhalPrcmDpllConfig_t     *pDpllLpDdr2Cfg333MHz_20[] =
{
    &dpllLpDdr2CfgOppNom333MHz_20,
    &dpllLpDdr2CfgOppNom333MHz_20,
    &dpllLpDdr2CfgOppNom333MHz_20,
    &dpllLpDdr2CfgOppNom333MHz_20
};

static pmhalPrcmDpllConfig_t     *pDpllGmac15X15Cfg_20[] =
{
    &dpllGmac15X15CfgOppNom_20,
    &dpllGmac15X15CfgOppNom_20,
    &dpllGmac15X15CfgOppOd_20,
    &dpllGmac15X15CfgOppHigh_20
};

static pmhalPrcmDpllConfig_t     *pDpllGmac12X12Cfg_20[] =
{
    &dpllGmac12X12CfgOppNom_20,
    &dpllGmac12X12CfgOppNom_20,
    &dpllGmac12X12CfgOppNom_20,
    &dpllGmac12X12CfgOppNom_20
};

static pmhalPrcmDpllConfig_t     *pDpllPerCfg_20[] =
{
    &dpllPerCfgOppNom_20,
    &dpllPerCfgOppNom_20,
    &dpllPerCfgOppNom_20,
    &dpllPerCfgOppNom_20
};

static pmhalPrcmDpllConfig_t     *pDpllEveVidDsp15x15Cfg_20[] =
{
    &dpllEveVidDsp15X15CfgOppNom_20,
    &dpllEveVidDsp15X15CfgOppNom_20,
    &dpllEveVidDsp15X15CfgOppOd_20,
    &dpllEveVidDsp15X15CfgOppHigh_20
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PRCM_getDpllStructure(pmhalPrcmNodeId_t       dpllId,
                              pmhalPrcmSysClkVal_t    sysClk,
                              uint32_t                opp,
                              uint32_t                siliconPackageType,
                              pmhalPrcmDpllConfig_t **dpllCfg)
{
    int32_t  retVal = PM_SUCCESS;

    if (PMHAL_PRCM_SYSCLK_20_MHZ == sysClk)
    {
        switch (dpllId)
        {
            case PMHAL_PRCM_DPLL_CORE:
                if (POWERPRCM_PACKAGE_TYPE_0 == siliconPackageType)
                {
                    *dpllCfg = pDpllCore12X12Cfg_20[opp];
                }
                else /* POWERPRCM_PACKAGE_TYPE_1 ==
                      * siliconPackageType */
                {
                    *dpllCfg = pDpllCore15X15Cfg_20[opp];
                }
                break;
            case PMHAL_PRCM_DPLL_DDR:
                if (POWERPRCM_PACKAGE_TYPE_0 == siliconPackageType)
                {
                    /* Default to LPDDR2 333MHz */
                    *dpllCfg = pDpllLpDdr2Cfg333MHz_20[opp];
                }
                else /* POWERPRCM_PACKAGE_TYPE_1 ==
                      * siliconPackageType */
                {
                    /* Default to DDR3 532MHz */
                    *dpllCfg = pDpllDdr3Cfg532MHz_20[opp];
                }
                break;
            case PMHAL_PRCM_DPLL_DSP_GMAC:
                if (POWERPRCM_PACKAGE_TYPE_0 == siliconPackageType)
                {
                    *dpllCfg = pDpllGmac12X12Cfg_20[opp];
                }
                else /* POWERPRCM_PACKAGE_TYPE_1 ==
                      * siliconPackageType */
                {
                    *dpllCfg = pDpllGmac15X15Cfg_20[opp];
                }
                break;
            case PMHAL_PRCM_DPLL_EVE_VID_DSP:
                if (POWERPRCM_PACKAGE_TYPE_0 == siliconPackageType)
                {
                    /* EVE VID DSP DPLL configuration not currently
                     * supported for 12x12 */
                    retVal = PM_FAIL;
                }
                else /* POWERPRCM_PACKAGE_TYPE_1 ==
                      * siliconPackageType */
                {
                    *dpllCfg = pDpllEveVidDsp15x15Cfg_20[opp];
                }
                break;
            case PMHAL_PRCM_DPLL_PER:
                *dpllCfg = pDpllPerCfg_20[opp];
                break;
            default:
                /* To remove MISRA C error */
                break;
        }
    }

    return retVal;
}

#ifdef __cplusplus
}
#endif

