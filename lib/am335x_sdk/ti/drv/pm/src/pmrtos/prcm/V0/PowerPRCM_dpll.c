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

pmhalPrcmPllPostDivValue_t dpllCorePostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2 },  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 4 },  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 62},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 5 },  /* div_h14_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H22, 5 },  /* div_h22_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H23, 7 },  /* div_h23_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H24, 6 }  /* div_h24_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllCorePostDivCfgOpp50_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4 },  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 8 },  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 62},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 10},  /* div_h14_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H22, 10},  /* div_h22_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H23, 14},  /* div_h23_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H24, 12}  /* div_h24_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDdrPostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 8},  /* div_h11_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDdrPostDivCfgOpp50_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  1},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 4},  /* div_h11_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllGmacPostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2 },  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  10},  /* div_m3_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 40},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 8 },  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 15},  /* div_h13_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllGmacPostDivCfgOpp50_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4 },  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  10},  /* div_m3_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 40},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 8 },  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 5 },  /* div_h13_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllEvePostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllEvePostDivCfgOpp50_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDspPostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3, 4}, /* div_m3_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDspPostDivCfgOpp50_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3, 4}, /* div_m3_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllGpuPostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllGpuPostDivCfgOpp50_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllPcieRefPostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllMpuPostDivCfgOppSpeedBin_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllMpuPostDivCfgOppHigh_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllMpuPostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllMpuPostDivCfgOpp50_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllPerPostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  3},  /* div_m3_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 6},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 4},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 2},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 2}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllPerPostDivCfgOpp50_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  4},  /* div_m3_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 6},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 4},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 2},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 4}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllPerPostDivCfgOppAudio_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  1},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  1},  /* div_m3_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 1},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 1},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 1},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 1}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllIvaPostDivCfgOppHigh_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  1},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 4},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 5},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 1},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 1}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllIvaPostDivCfgOpp119_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  1},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 2},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 2},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 1},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 1}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllIvaPostDivCfgOpp100_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  1},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 5},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 6},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 1},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 1}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllIvaPostDivCfgOpp50_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  1 },  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 10},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 12},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 1 },  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 1 }  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllAbePostDivCfgAllOpp_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllAbePostDivCfgAllOpp32k_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllUsbPostDivCfgAllOpp_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllUniproPostDivCfgAllOpp_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 1},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 1},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 1},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 1}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllUniproPostDivCfgHs_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 1},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 1},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 1},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 1}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllUniproPostDivCfgHs_gls_192[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 1},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 1},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 1},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 1}  /* div_h14_clkcfg */
};

/*********************************************************************/
/* 20 MHZ */
/*********************************************************************/

pmhalPrcmPllPostDivValue_t dpllMpuPostDivCfgOppLow_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllMpuPostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllCorePostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2 },  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 4 },  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 62},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 5 },  /* div_h14_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H22, 5 },  /* div_h22_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H23, 4 },  /* div_h23_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H24, 1 }  /* div_h24_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllPerPostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  1},  /* div_m3_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 3},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 4},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 4},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 2}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDspPostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3, 3} /* div_m3_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllEvePostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2} /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllIvaPostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 3} /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllGpuPostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2} /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDdrPostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  2},  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 8}  /* div_h11_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllGmacPostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  4 },  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3,  10},  /* div_m3_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 40},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 8 },  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 10}  /* div_h13_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllAbePostDivCfgAllOpp_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3, 1} /* div_m3_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllUsbPostDivCfgAllOpp_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2} /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllPcieRefPostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 15}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllVideo1PostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 13} /* div_h11_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllVideo2PostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2,  5 },  /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H11, 10},  /* div_h11_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H12, 10},  /* div_h12_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H13, 10},  /* div_h13_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_H14, 10}  /* div_h14_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllHdmiPostDivCfgOpp100_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1} /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDspPostDivCfgOppOd_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3, 3} /* div_m3_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllEvePostDivCfgOppOd_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllIvaPostDivCfgOppOd_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllGpuPostDivCfgOppOd_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2} /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllDspPostDivCfgOppHigh_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 1}, /* div_m2_clkcfg */
    {PMHAL_PRCM_DPLL_POST_DIV_M3, 3} /* div_m3_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllEvePostDivCfgOppHigh_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmPllPostDivValue_t dpllIvaPostDivCfgOppHigh_20[] =
{
    {PMHAL_PRCM_DPLL_POST_DIV_M2, 2}, /* div_m2_clkcfg */
};

pmhalPrcmDpllConfig_t      dpllCoreCfgOpp100_192 =
{
    655,                         /* multiplier */
    11,                          /* divider */
    0,                           /* dutyCycleCorrector */
    dpllCorePostDivCfgOpp100_192,
    (sizeof (dpllCorePostDivCfgOpp100_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllCoreCfgOpp50_192 =
{
    655,                        /* multiplier */
    11,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllCorePostDivCfgOpp50_192,
    (sizeof (dpllCorePostDivCfgOpp50_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllDdrCfgOpp100_192 =
{
    665,                        /* multiplier */
    23,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllDdrPostDivCfgOpp100_192,
    (sizeof (dpllDdrPostDivCfgOpp100_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllDdrCfgOpp50_192 =
{
    113,                       /* multiplier */
    12,                        /* divider */
    0,                         /* dutyCycleCorrector */
    dpllDdrPostDivCfgOpp50_192,
    (sizeof (dpllDdrPostDivCfgOpp50_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllGmacCfgOpp100_192 =
{
    500,                         /* multiplier */
    12,                          /* divider */
    0,                           /* dutyCycleCorrector */
    dpllGmacPostDivCfgOpp100_192,
    (sizeof (dpllGmacPostDivCfgOpp100_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllGmacCfgOpp50_192 =
{
    250,                        /* multiplier */
    12,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllGmacPostDivCfgOpp50_192,
    (sizeof (dpllGmacPostDivCfgOpp50_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllEveCfgOpp100_192 =
{
    550,                        /* multiplier */
    12,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllEvePostDivCfgOpp100_192,
    (sizeof (dpllEvePostDivCfgOpp100_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllEveCfgOpp50_192 =
{
    275,                       /* multiplier */
    12,                        /* divider */
    0,                         /* dutyCycleCorrector */
    dpllEvePostDivCfgOpp50_192,
    (sizeof (dpllEvePostDivCfgOpp50_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllDspCfgOpp100_192 =
{
    600,                        /* multiplier */
    12,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllDspPostDivCfgOpp100_192,
    (sizeof (dpllDspPostDivCfgOpp100_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllDspCfgOpp50_192 =
{
    150,                       /* multiplier */
    12,                        /* divider */
    0,                         /* dutyCycleCorrector */
    dpllDspPostDivCfgOpp50_192,
    (sizeof (dpllDspPostDivCfgOpp50_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllGpuCfgOpp100_192 =
{
    665,                        /* multiplier */
    23,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllGpuPostDivCfgOpp100_192,
    (sizeof (dpllGpuPostDivCfgOpp100_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllGpuCfgOpp50_192 =
{
    213,                       /* multiplier */
    12,                        /* divider */
    0,                         /* dutyCycleCorrector */
    dpllGpuPostDivCfgOpp50_192,
    (sizeof (dpllGpuPostDivCfgOpp50_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllPcieRefCfgOpp100_192 =
{
    665,                            /* multiplier */
    23,                             /* divider */
    0,                              /* dutyCycleCorrector */
    dpllPcieRefPostDivCfgOpp100_192,
    (sizeof (dpllPcieRefPostDivCfgOpp100_192) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOppSpeedBin_192 =
{
    469,                             /* multiplier */
    8,                               /* divider */
    0,                               /* dutyCycleCorrector */
    dpllMpuPostDivCfgOppSpeedBin_192,
    (sizeof (dpllMpuPostDivCfgOppSpeedBin_192) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOppHigh_192 =
{
    1375,                        /* multiplier */
    23,                          /* divider */
    0,                           /* dutyCycleCorrector */
    dpllMpuPostDivCfgOppHigh_192,
    (sizeof (dpllMpuPostDivCfgOppHigh_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOpp100_192 =
{
    375,                        /* multiplier */
    8,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllMpuPostDivCfgOpp100_192,
    (sizeof (dpllMpuPostDivCfgOpp100_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOpp50_192 =
{
    375,                       /* multiplier */
    8,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllMpuPostDivCfgOpp50_192,
    (sizeof (dpllMpuPostDivCfgOpp50_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllPerCfgOpp100_192 =
{
    20,                         /* multiplier */
    0,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllPerPostDivCfgOpp100_192,
    (sizeof (dpllPerPostDivCfgOpp100_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllPerCfgOpp50_192 =
{
    20,                        /* multiplier */
    0,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllPerPostDivCfgOpp50_192,
    (sizeof (dpllPerPostDivCfgOpp50_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllPerCfgOppAudio_192 =
{
    0,                            /* multiplier */
    0,                            /* divider */
    0,                            /* dutyCycleCorrector */
    dpllPerPostDivCfgOppAudio_192,
    (sizeof (dpllPerPostDivCfgOppAudio_192) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllIvaCfgOppHigh_192 =
{
    287,                         /* multiplier */
    7,                           /* divider */
    0,                           /* dutyCycleCorrector */
    dpllIvaPostDivCfgOppHigh_192,
    (sizeof (dpllIvaPostDivCfgOppHigh_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllIvaCfgOpp119_192 =
{
    665,                        /* multiplier */
    23,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllIvaPostDivCfgOpp119_192,
    (sizeof (dpllIvaPostDivCfgOpp119_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllIvaCfgOpp100_192 =
{
    1881,                       /* multiplier */
    30,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllIvaPostDivCfgOpp100_192,
    (sizeof (dpllIvaPostDivCfgOpp100_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllIvaCfgOpp50_192 =
{
    1881,                      /* multiplier */
    30,                        /* divider */
    0,                         /* dutyCycleCorrector */
    dpllIvaPostDivCfgOpp50_192,
    (sizeof (dpllIvaPostDivCfgOpp50_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllAbeCfgAllOpp_192 =
{
    512,                        /* multiplier */
    99,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllAbePostDivCfgAllOpp_192,
    (sizeof (dpllAbePostDivCfgAllOpp_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllAbeCfgAllOpp32k_192 =
{
    750,                           /* multiplier */
    30,                            /* divider */
    0,                             /* dutyCycleCorrector */
    dpllAbePostDivCfgAllOpp32k_192,
    (sizeof (dpllAbePostDivCfgAllOpp32k_192) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllUsbCfgAllOpp_192 =
{
    400,                        /* multiplier */
    7,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllUsbPostDivCfgAllOpp_192,
    (sizeof (dpllUsbPostDivCfgAllOpp_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllUniproCfgAllOpp_192 =
{
    520,                           /* multiplier */
    7,                             /* divider */
    0,                             /* dutyCycleCorrector */
    dpllUniproPostDivCfgAllOpp_192,
    (sizeof (dpllUniproPostDivCfgAllOpp_192) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllUniproCfgHs_192 =
{
    911,                       /* multiplier */
    11,                        /* divider */
    0,                         /* dutyCycleCorrector */
    dpllUniproPostDivCfgHs_192,
    (sizeof (dpllUniproPostDivCfgHs_192) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllUniproCfgHs_gls_192 =
{
    492,                           /* multiplier */
    12,                            /* divider */
    0,                             /* dutyCycleCorrector */
    dpllUniproPostDivCfgHs_gls_192,
    (sizeof (dpllUniproPostDivCfgHs_gls_192) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllMpuCfgOppLow_20 =
{
    250,                       /* multiplier */
    9,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllMpuPostDivCfgOppLow_20,
    (sizeof (dpllMpuPostDivCfgOppLow_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

#if defined (SOC_TDA2XX) || defined (SOC_DRA75x)
pmhalPrcmDpllConfig_t      dpllMpuCfgOpp100_20 =
{
    375,                       /* multiplier */
    9,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllMpuPostDivCfgOpp100_20,
    (sizeof (dpllMpuPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};
#elif defined (SOC_TDA2EX)
pmhalPrcmDpllConfig_t      dpllMpuCfgOpp100_20 =
{
    400,                       /* multiplier */
    9,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllMpuPostDivCfgOpp100_20,
    (sizeof (dpllMpuPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};
#elif defined (SOC_AM571x) || defined (SOC_AM572x)
pmhalPrcmDpllConfig_t      dpllMpuCfgOpp100_20 =
{
    500,                       /* multiplier */
    9,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllMpuPostDivCfgOpp100_20,
    (sizeof (dpllMpuPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};
#endif

pmhalPrcmDpllConfig_t      dpllCoreCfgOpp100_20 =
{
    266,                        /* multiplier */
    4,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllCorePostDivCfgOpp100_20,
    (sizeof (dpllCorePostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllPerCfgOpp100_20 =
{
    96,                        /* multiplier */
    4,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllPerPostDivCfgOpp100_20,
    (sizeof (dpllPerPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllDspCfgOpp100_20 =
{
    150,                       /* multiplier */
    4,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllDspPostDivCfgOpp100_20,
    (sizeof (dpllDspPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllEveCfgOpp100_20 =
{
    214,                       /* multiplier */
    3,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllEvePostDivCfgOpp100_20,
    (sizeof (dpllEvePostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllIvaCfgOpp100_20 =
{
    233,                       /* multiplier */
    3,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllIvaPostDivCfgOpp100_20,
    (sizeof (dpllIvaPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllGpuCfgOpp100_20 =
{
    170,                       /* multiplier */
    3,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllGpuPostDivCfgOpp100_20,
    (sizeof (dpllGpuPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x)
pmhalPrcmDpllConfig_t      dpllDdrCfgOpp100_20 =
{
    266,                       /* multiplier */
    4,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllDdrPostDivCfgOpp100_20,
    (sizeof (dpllDdrPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};
#elif defined (SOC_TDA2EX) || defined (SOC_AM571x)
pmhalPrcmDpllConfig_t      dpllDdrCfgOpp100_20 =
{
    333,                       /* multiplier */
    4,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllDdrPostDivCfgOpp100_20,
    (sizeof (dpllDdrPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};
#endif

pmhalPrcmDpllConfig_t      dpllGmacCfgOpp100_20 =
{
    250,                        /* multiplier */
    4,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllGmacPostDivCfgOpp100_20,
    (sizeof (dpllGmacPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllAbeCfgAllOpp_20 =
{
    200,                       /* multiplier */
    9,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllAbePostDivCfgAllOpp_20,
    (sizeof (dpllAbePostDivCfgAllOpp_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllUsbCfgAllOpp_20 =
{
    27,                        /* multiplier */
    0,                         /* divider */
    0,                         /* dutyCycleCorrector */
    dpllUsbPostDivCfgAllOpp_20,
    (sizeof (dpllUsbPostDivCfgAllOpp_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllPcieRefCfgOpp100_20 =
{
    750,                           /* multiplier */
    9,                             /* divider */
    0,                             /* dutyCycleCorrector */
    dpllPcieRefPostDivCfgOpp100_20,
    (sizeof (dpllPcieRefPostDivCfgOpp100_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllVideo1CfgOpp100_20 =
{
    1637,                         /* multiplier */
    39,                           /* divider */
    0,                            /* dutyCycleCorrector */
    dpllVideo1PostDivCfgOpp100_20,
    (sizeof (dpllVideo1PostDivCfgOpp100_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllVideo2CfgOpp100_20 =
{
    297,                          /* multiplier */
    7,                            /* divider */
    0,                            /* dutyCycleCorrector */
    dpllVideo2PostDivCfgOpp100_20,
    (sizeof (dpllVideo2PostDivCfgOpp100_20) /
     sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllHdmiCfgOpp100_20 =
{
    1188,                       /* multiplier */
    15,                         /* divider */
    0,                          /* dutyCycleCorrector */
    dpllHdmiPostDivCfgOpp100_20,
    (sizeof (dpllHdmiPostDivCfgOpp100_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllDspCfgOppOd_20 =
{
    175,                      /* multiplier */
    4,                        /* divider */
    0,                        /* dutyCycleCorrector */
    dpllDspPostDivCfgOppOd_20,
    (sizeof (dpllDspPostDivCfgOppOd_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllEveCfgOppOd_20 =
{
    240,                      /* multiplier */
    3,                        /* divider */
    0,                        /* dutyCycleCorrector */
    dpllEvePostDivCfgOppOd_20,
    (sizeof (dpllEvePostDivCfgOppOd_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllIvaCfgOppOd_20 =
{
    172,                      /* multiplier */
    3,                        /* divider */
    0,                        /* dutyCycleCorrector */
    dpllIvaPostDivCfgOppOd_20,
    (sizeof (dpllIvaPostDivCfgOppOd_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllGpuCfgOppOd_20 =
{
    200,                      /* multiplier */
    3,                        /* divider */
    0,                        /* dutyCycleCorrector */
    dpllGpuPostDivCfgOppOd_20,
    (sizeof (dpllGpuPostDivCfgOppOd_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};
#if defined (SOC_TDA2EX) || defined (SOC_AM571x)
pmhalPrcmDpllConfig_t      dpllGpuCfgOppHigh_20 =
{
    212,                      /* multiplier */
    3,                        /* divider */
    0,                        /* dutyCycleCorrector */
    dpllGpuPostDivCfgOppOd_20,
    (sizeof (dpllGpuPostDivCfgOppOd_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};
#endif
pmhalPrcmDpllConfig_t      dpllDspCfgOppHigh_20 =
{
    187,                        /* multiplier */
    4,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllDspPostDivCfgOppHigh_20,
    (sizeof (dpllDspPostDivCfgOppHigh_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllEveCfgOppHigh_20 =
{
    260,                        /* multiplier */
    3,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllEvePostDivCfgOppHigh_20,
    (sizeof (dpllEvePostDivCfgOppHigh_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t      dpllIvaCfgOppHigh_20 =
{
    260,                        /* multiplier */
    4,                          /* divider */
    0,                          /* dutyCycleCorrector */
    dpllIvaPostDivCfgOppHigh_20,
    (sizeof (dpllIvaPostDivCfgOppHigh_20) / sizeof (pmhalPrcmPllPostDivValue_t))
};

pmhalPrcmDpllConfig_t     *pDpllAbeCfg_192[] =
{
    &dpllAbeCfgAllOpp_192,
    &dpllAbeCfgAllOpp_192,
    &dpllAbeCfgAllOpp_192,
    &dpllAbeCfgAllOpp_192
};

pmhalPrcmDpllConfig_t     *pDpllCoreCfg_192[] =
{
    &dpllCoreCfgOpp50_192,
    &dpllCoreCfgOpp100_192,
    &dpllCoreCfgOpp100_192,
    &dpllCoreCfgOpp100_192
};

pmhalPrcmDpllConfig_t     *pDpllDdrCfg_192[] =
{
    &dpllDdrCfgOpp50_192,
    &dpllDdrCfgOpp100_192,
    &dpllDdrCfgOpp100_192,
    &dpllDdrCfgOpp100_192
};

pmhalPrcmDpllConfig_t     *pDpllGmacCfg_192[] =
{
    &dpllGmacCfgOpp50_192,
    &dpllGmacCfgOpp100_192,
    &dpllGmacCfgOpp100_192,
    &dpllGmacCfgOpp100_192
};

pmhalPrcmDpllConfig_t     *pDpllGpuCfg_192[] =
{
    &dpllGpuCfgOpp50_192,
    &dpllGpuCfgOpp100_192,
    &dpllGpuCfgOpp100_192,
    &dpllGpuCfgOpp100_192
};

pmhalPrcmDpllConfig_t     *pDpllIvaCfg_192[] =
{
    &dpllIvaCfgOpp50_192,
    &dpllIvaCfgOpp100_192,
    &dpllIvaCfgOpp119_192,
    &dpllIvaCfgOppHigh_192
};

pmhalPrcmDpllConfig_t     *pDpllPcieRefCfg_192[] =
{
    &dpllPcieRefCfgOpp100_192,
    &dpllPcieRefCfgOpp100_192,
    &dpllPcieRefCfgOpp100_192,
    &dpllPcieRefCfgOpp100_192
};

pmhalPrcmDpllConfig_t     *pDpllPerCfg_192[] =
{
    &dpllPerCfgOpp50_192,
    &dpllPerCfgOpp100_192,
    &dpllPerCfgOpp100_192,
    &dpllPerCfgOpp100_192
};

pmhalPrcmDpllConfig_t     *pDpllUsbCfg_192[] =
{
    &dpllUsbCfgAllOpp_192,
    &dpllUsbCfgAllOpp_192,
    &dpllUsbCfgAllOpp_192,
    &dpllUsbCfgAllOpp_192
};

pmhalPrcmDpllConfig_t     *pDpllDspCfg_192[] =
{
    &dpllDspCfgOpp50_192,
    &dpllDspCfgOpp100_192,
    &dpllDspCfgOpp100_192,
    &dpllDspCfgOpp100_192
};

pmhalPrcmDpllConfig_t     *pDpllEveCfg_192[] =
{
    &dpllEveCfgOpp50_192,
    &dpllEveCfgOpp100_192,
    &dpllEveCfgOpp100_192,
    &dpllEveCfgOpp100_192
};

pmhalPrcmDpllConfig_t     *pDpllMpuCfg_192[] =
{
    &dpllMpuCfgOpp50_192,
    &dpllMpuCfgOpp100_192,
    &dpllMpuCfgOppSpeedBin_192,
    &dpllMpuCfgOppHigh_192
};

pmhalPrcmDpllConfig_t     *pDpllAbeCfg_20[] =
{
    &dpllAbeCfgAllOpp_20,
    &dpllAbeCfgAllOpp_20,
    &dpllAbeCfgAllOpp_20,
    &dpllAbeCfgAllOpp_20
};

pmhalPrcmDpllConfig_t     *pDpllCoreCfg_20[] =
{
    &dpllCoreCfgOpp100_20,
    &dpllCoreCfgOpp100_20,
    &dpllCoreCfgOpp100_20,
    &dpllCoreCfgOpp100_20
};

pmhalPrcmDpllConfig_t     *pDpllDdrCfg_20[] =
{
    &dpllDdrCfgOpp100_20,
    &dpllDdrCfgOpp100_20,
    &dpllDdrCfgOpp100_20,
    &dpllDdrCfgOpp100_20
};

pmhalPrcmDpllConfig_t     *pDpllGmacCfg_20[] =
{
    &dpllGmacCfgOpp100_20,
    &dpllGmacCfgOpp100_20,
    &dpllGmacCfgOpp100_20,
    &dpllGmacCfgOpp100_20
};
#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x)
pmhalPrcmDpllConfig_t     *pDpllGpuCfg_20[] =
{
    &dpllGpuCfgOpp100_20,
    &dpllGpuCfgOpp100_20,
    &dpllGpuCfgOppOd_20,
    &dpllGpuCfgOppOd_20
};
#elif defined (SOC_TDA2EX) || defined (SOC_AM571x)
pmhalPrcmDpllConfig_t     *pDpllGpuCfg_20[] =
{
    &dpllGpuCfgOpp100_20,
    &dpllGpuCfgOpp100_20,
    &dpllGpuCfgOppOd_20,
    &dpllGpuCfgOppHigh_20
};
#endif

pmhalPrcmDpllConfig_t     *pDpllIvaCfg_20[] =
{
    &dpllIvaCfgOpp100_20,
    &dpllIvaCfgOpp100_20,
    &dpllIvaCfgOppOd_20,
    &dpllIvaCfgOppHigh_20
};

pmhalPrcmDpllConfig_t     *pDpllPcieRefCfg_20[] =
{
    &dpllPcieRefCfgOpp100_20,
    &dpllPcieRefCfgOpp100_20,
    &dpllPcieRefCfgOpp100_20,
    &dpllPcieRefCfgOpp100_20
};

pmhalPrcmDpllConfig_t     *pDpllPerCfg_20[] =
{
    &dpllPerCfgOpp100_20,
    &dpllPerCfgOpp100_20,
    &dpllPerCfgOpp100_20,
    &dpllPerCfgOpp100_20
};

pmhalPrcmDpllConfig_t     *pDpllUsbCfg_20[] =
{
    &dpllUsbCfgAllOpp_20,
    &dpllUsbCfgAllOpp_20,
    &dpllUsbCfgAllOpp_20,
    &dpllUsbCfgAllOpp_20
};
#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x)
pmhalPrcmDpllConfig_t     *pDpllDspCfg_20[] =
{
    &dpllDspCfgOpp100_20,
    &dpllDspCfgOpp100_20,
    &dpllDspCfgOppOd_20,
    &dpllDspCfgOppHigh_20
};
#elif defined (SOC_TDA2EX) || defined (SOC_AM571x)
pmhalPrcmDpllConfig_t     *pDpllDspCfg_20[] =
{
    &dpllDspCfgOpp100_20,
    &dpllDspCfgOpp100_20,
    &dpllDspCfgOppOd_20,
    &dpllDspCfgOppOd_20
};
#endif
pmhalPrcmDpllConfig_t     *pDpllEveCfg_20[] =
{
    &dpllEveCfgOpp100_20,
    &dpllEveCfgOpp100_20,
    &dpllEveCfgOppOd_20,
    &dpllEveCfgOppHigh_20
};

#if defined (SOC_TDA2XX) || defined (SOC_DRA75x) || defined (SOC_AM572x)
pmhalPrcmDpllConfig_t     *pDpllMpuCfg_20[] =
{
    &dpllMpuCfgOppLow_20,
    &dpllMpuCfgOpp100_20,
    &dpllMpuCfgOpp100_20,
    &dpllMpuCfgOpp100_20
};
#elif defined (SOC_TDA2EX) || defined (SOC_AM571x)
pmhalPrcmDpllConfig_t     *pDpllMpuCfg_20[] =
{
    &dpllMpuCfgOpp100_20,
    &dpllMpuCfgOpp100_20,
    &dpllMpuCfgOpp100_20,
    &dpllMpuCfgOpp100_20
};
#endif

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
    if (PMHAL_PRCM_SYSCLK_20_MHZ == sysClk)
    {
        switch (dpllId)
        {
            case PMHAL_PRCM_DPLL_ABE:
                *dpllCfg = pDpllAbeCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_CORE:
                *dpllCfg = pDpllCoreCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_DDR:
                *dpllCfg = pDpllDdrCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_GMAC:
                *dpllCfg = pDpllGmacCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_GPU:
                *dpllCfg = pDpllGpuCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_IVA:
                *dpllCfg = pDpllIvaCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_PCIE_REF:
                *dpllCfg = pDpllPcieRefCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_PER:
                *dpllCfg = pDpllPerCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_USB:
                *dpllCfg = pDpllUsbCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_DSP:
                *dpllCfg = pDpllDspCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_EVE:
                *dpllCfg = pDpllEveCfg_20[opp];
                break;
            case PMHAL_PRCM_DPLL_MPU:
                *dpllCfg = pDpllMpuCfg_20[opp];
                break;
            default:
                /* Nothing to be done here */
                break;
        }
        retVal = PM_SUCCESS;
    }
    else if (PMHAL_PRCM_SYSCLK_19_2_MHZ == sysClk)
    {
        switch (dpllId)
        {
            case PMHAL_PRCM_DPLL_ABE:
                *dpllCfg = pDpllAbeCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_CORE:
                *dpllCfg = pDpllCoreCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_DDR:
                *dpllCfg = pDpllDdrCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_GMAC:
                *dpllCfg = pDpllGmacCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_GPU:
                *dpllCfg = pDpllGpuCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_IVA:
                *dpllCfg = pDpllIvaCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_PCIE_REF:
                *dpllCfg = pDpllPcieRefCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_PER:
                *dpllCfg = pDpllPerCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_USB:
                *dpllCfg = pDpllUsbCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_DSP:
                *dpllCfg = pDpllDspCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_EVE:
                *dpllCfg = pDpllEveCfg_192[opp];
                break;
            case PMHAL_PRCM_DPLL_MPU:
                *dpllCfg = pDpllMpuCfg_192[opp];
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

