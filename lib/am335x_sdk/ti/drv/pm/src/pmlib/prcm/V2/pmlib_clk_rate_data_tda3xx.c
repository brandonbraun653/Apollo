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
 * \file      pmlib_clk_rate_data_tda3xx.c
 *
 * \brief     PMLIB Clock Rate Data Base used by Clock Rate Manager.
 *
 * \note      This file is auto generated from the Clock Rate xlsm.
 *            DO NOT Modify Manually.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <ti/csl/hw_types.h>
#include "pmhal_vm.h"
#include "pmhal_mm.h"
#include "pmhal_cm.h"
#include "pmhal_clocktree.h"
#include "pmlib_clk_rate_data_priv.h"
#include "pmhal_prcm.h"

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

/* -------------------------------------------------------------------------- */
/*                     DPLL Configuration Structures                          */
/* -------------------------------------------------------------------------- */

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_CORE
 *         PMHAL_PRCM_DPLL_POST_DIV_H12 = 4
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H12_4 =
{PMHAL_PRCM_DPLL_POST_DIV_H12, 4U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_CORE, M = 266, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H12 = 4
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_CORE_266_4_H12_4 =
{266U,                                      4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H12_4, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_CORE
 *         PMHAL_PRCM_DPLL_POST_DIV_H22 = 5
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H22_5 =
{PMHAL_PRCM_DPLL_POST_DIV_H22, 5U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_CORE, M = 266, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H22 = 5
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_CORE_266_4_H22_5 =
{266U,                                      4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H22_5, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_CORE
 *         PMHAL_PRCM_DPLL_POST_DIV_H13 = 44
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H13_44 =
{PMHAL_PRCM_DPLL_POST_DIV_H13, 44U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_CORE, M = 266, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H13 = 44
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_CORE_266_4_H13_44 =
{266U,                                       4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H13_44, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_CORE
 *         PMHAL_PRCM_DPLL_POST_DIV_H23 = 10
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H23_10 =
{PMHAL_PRCM_DPLL_POST_DIV_H23, 10U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_CORE, M = 266, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H23 = 10
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_CORE_266_4_H23_10 =
{266U,                                       4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H23_10, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_CORE
 *         PMHAL_PRCM_DPLL_POST_DIV_H11 = 8
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H11_8 =
{PMHAL_PRCM_DPLL_POST_DIV_H11, 8U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_CORE, M = 266, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H11 = 8
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_CORE_266_4_H11_8 =
{266U,                                      4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H11_8, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_CORE
 *         PMHAL_PRCM_DPLL_POST_DIV_H21 = 11
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H21_11 =
{PMHAL_PRCM_DPLL_POST_DIV_H21, 11U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_CORE, M = 266, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H21 = 11
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_CORE_266_4_H21_11 =
{266U,                                       4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_CORE_266_4_H21_11, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DDR
 *         PMHAL_PRCM_DPLL_POST_DIV_H11 = 8
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DDR_266_4_H11_8 =
{PMHAL_PRCM_DPLL_POST_DIV_H11, 8U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DDR, M = 266, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H11 = 8
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DDR_266_4_H11_8 =
{266U,                                     4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DDR_266_4_H11_8, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DDR
 *         PMHAL_PRCM_DPLL_POST_DIV_H11 = 8
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DDR_200_4_H11_8 =
{PMHAL_PRCM_DPLL_POST_DIV_H11, 8U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DDR, M = 200, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H11 = 8
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DDR_200_4_H11_8 =
{200U,                                     4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DDR_200_4_H11_8, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DDR
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 2
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DDR_200_4_M2_2 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 2U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DDR, M = 200, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 2
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DDR_200_4_M2_2 =
{200U,                                    4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DDR_200_4_M2_2, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DDR
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 2
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DDR_266_4_M2_2 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 2U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DDR, M = 266, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 2
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DDR_266_4_M2_2 =
{266U,                                    4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DDR_266_4_M2_2, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DSP_GMAC
 *         PMHAL_PRCM_DPLL_POST_DIV_M3 = 4
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_M3_4 =
{PMHAL_PRCM_DPLL_POST_DIV_M3, 4U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DSP_GMAC, M = 250, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_M3 = 4
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DSP_GMAC_250_4_M3_4 =
{250U,                                         4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_M3_4, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DSP_GMAC
 *         PMHAL_PRCM_DPLL_POST_DIV_H13 = 4
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H13_4 =
{PMHAL_PRCM_DPLL_POST_DIV_H13, 4U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DSP_GMAC, M = 250, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H13 = 4
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H13_4 =
{250U,                                          4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H13_4, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DSP_GMAC
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 4
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_M2_4 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 4U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DSP_GMAC, M = 250, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 4
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DSP_GMAC_250_4_M2_4 =
{250U,                                         4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_M2_4, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DSP_GMAC
 *         PMHAL_PRCM_DPLL_POST_DIV_H12 = 8
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H12_8 =
{PMHAL_PRCM_DPLL_POST_DIV_H12, 8U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DSP_GMAC, M = 250, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H12 = 8
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H12_8 =
{250U,                                          4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H12_8, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DSP_GMAC
 *         PMHAL_PRCM_DPLL_POST_DIV_H11 = 40
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H11_40 =
{PMHAL_PRCM_DPLL_POST_DIV_H11, 40U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DSP_GMAC, M = 250, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H11 = 40
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H11_40 =
{250U,                                           4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H11_40, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DSP_GMAC
 *         PMHAL_PRCM_DPLL_POST_DIV_H14 = 25
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H14_25 =
{PMHAL_PRCM_DPLL_POST_DIV_H14, 25U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DSP_GMAC, M = 250, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H14 = 25
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H14_25 =
{250U,                                           4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H14_25, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_PER
 *         PMHAL_PRCM_DPLL_POST_DIV_H12 = 8
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_PER_192_4_H12_8 =
{PMHAL_PRCM_DPLL_POST_DIV_H12, 8U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_PER, M = 192, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H12 = 8
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_PER_192_4_H12_8 =
{192U,                                     4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_PER_192_4_H12_8, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_PER
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 8
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_PER_192_4_M2_8 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 8U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_PER, M = 192, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 8
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_PER_192_4_M2_8 =
{192U,                                    4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_PER_192_4_M2_8, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_PER
 *         PMHAL_PRCM_DPLL_POST_DIV_M2X2 = 8
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_PER_192_4_M2X2_8 =
{PMHAL_PRCM_DPLL_POST_DIV_M2X2, 8U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_PER, M = 192, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_M2X2 = 8
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_PER_192_4_M2X2_8 =
{192U,                                      4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_PER_192_4_M2X2_8, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_PER
 *         PMHAL_PRCM_DPLL_POST_DIV_H13 = 12
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_PER_192_4_H13_12 =
{PMHAL_PRCM_DPLL_POST_DIV_H13, 12U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_PER, M = 192, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H13 = 12
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_PER_192_4_H13_12 =
{192U,                                      4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_PER_192_4_H13_12, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_PER
 *         PMHAL_PRCM_DPLL_POST_DIV_H14 = 4
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_PER_192_4_H14_4 =
{PMHAL_PRCM_DPLL_POST_DIV_H14, 4U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_PER, M = 192, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_H14 = 4
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_PER_192_4_H14_4 =
{192U,                                     4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_PER_192_4_H14_4, 1U,
 0U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_EVE_VID_DSP
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 3
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_EVE_VID_DSP_222_4_M2_3 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 3U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_EVE_VID_DSP, M = 222, N = 4
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 3
 */
pmhalPrcmDpllConfig_t      PMHAL_PRCM_DPLL_EVE_VID_DSP_222_4_M2_3 =
{222U,                                            4U,
 0U,
 &postDiv_PMHAL_PRCM_DPLL_EVE_VID_DSP_222_4_M2_3, 1U,
 0U};

/* -------------------------------------------------------------------------- */
/*              Mux and Divider Configuration Structures                      */
/* -------------------------------------------------------------------------- */

/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_CRC_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_CRC_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK_20000000_muxSel[]
    =
    {
    {PMHAL_PRCM_MUX_WKUPAON_ICLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
    };
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK_20000000_muxSel
[] =
{
    {PMHAL_PRCM_MUX_WKUPAON_ICLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_DSP1_GFCLK run
 *         at 500000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_DSP1_GFCLK_500000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_DSP_GFCLK_MUX,
     PMHAL_PRCM_DPLL_DSP_GMAC}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_DSP2_GFCLK run
 *         at 500000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_DSP2_GFCLK_500000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_DSP_GFCLK_MUX,
     PMHAL_PRCM_DPLL_DSP_GMAC}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_DSS_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_DSS_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_DSS_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_DSS_L4_GICLK_133000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_EMIF_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_EMIF_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_EVE1_GFCLK run
 *         at 500000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_EVE1_GFCLK_500000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_EVE_GCLK_MUX,
     PMHAL_PRCM_DPLL_DSP_GMAC},
    {PMHAL_PRCM_MUX_EVE_CLK_MUX,
     PMHAL_PRCM_MUX_EVE_GCLK_MUX}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_GMAC_RFT_CLK run
 *         at 266000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_GMAC_RFT_CLK_266000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_GMAC_RFT_CLK_MUX,
     PMHAL_PRCM_DIV_L3_ICLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_GMAC_RFT_CLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_GMAC_RFT_CLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RMII_50MHZ_CLK run
 *         at 50000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_RMII_50MHZ_CLK_50000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_RMII_50M_CLK_MUX,
     PMHAL_PRCM_DPLL_DSP_GMAC}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RGMII_5MHZ_CLK run
 *         at 5000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_RGMII_5MHZ_CLK_5000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_RMII_50M_CLK_MUX,
     PMHAL_PRCM_DPLL_DSP_GMAC}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKR run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKR_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AHCLKR_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKR run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKR_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKR run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKR_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AHCLKR_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKR run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKR_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKR run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKR_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AHCLKR_MUX,
     PMHAL_PRCM_DIV_FUNC_24M_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKX run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKX_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AHCLKX_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKX run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKX_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKX run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKX_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AHCLKX_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKX run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKX_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AHCLKX run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKX_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AHCLKX_MUX,
     PMHAL_PRCM_DIV_FUNC_24M_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 5000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_5000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 5000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_5000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     4}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_2500000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP1_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_2500000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     8}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 133000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_133000000_muxSel[]
    =
    {
    {PMHAL_PRCM_MUX_MCASP1_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_L4_ROOT_CLK}
    };
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_133000000_divSel[]
    =
    {
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
    };
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER5_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER5_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER5_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER5_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER5_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER5_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER5_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER5_GFCLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX},
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER5_GFCLK run
 *         at 22579200 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_22579200_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER5_GFCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER6_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER6_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER6_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER6_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER6_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER6_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER6_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER6_GFCLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX},
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER6_GFCLK run
 *         at 22579200 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_22579200_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER6_GFCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER7_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER7_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER7_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER7_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER7_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER7_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER7_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER7_GFCLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX},
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER7_GFCLK run
 *         at 22579200 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_22579200_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER7_GFCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER8_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER8_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER8_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER8_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER8_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER8_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER8_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER8_GFCLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX},
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER8_GFCLK run
 *         at 22579200 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_22579200_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER8_GFCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_IPU1_GFCLK run
 *         at 212800000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_IPU1_GFCLK_212800000_muxSel[] =
{
    {PMHAL_PRCM_MUX_IPU1_GFCLK_MUX,
     PMHAL_PRCM_DPLL_CORE}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INIT_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_L3INIT_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_L3INSTR_TS_GCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_2500000_muxSel[] =
{
    {PMHAL_PRCM_MUX_WKUPAON_ICLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INSTR_TS_GCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_2500000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3INSTR_TS_GCLK,
     8}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_L3INSTR_TS_GCLK run
 *         at 1250000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_1250000_muxSel[] =
{
    {PMHAL_PRCM_MUX_WKUPAON_ICLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INSTR_TS_GCLK run
 *         at 1250000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_1250000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3INSTR_TS_GCLK,
     16}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_L3INSTR_TS_GCLK run
 *         at 625000 Hz.
 */
pmlibClockRateMuxConfig_t  PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_625000_muxSel[] =
{
    {PMHAL_PRCM_MUX_WKUPAON_ICLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INSTR_TS_GCLK run
 *         at 625000 Hz.
 */
pmlibClockRateDivConfig_t  PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_625000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3INSTR_TS_GCLK,
     32}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateMuxConfig_t
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_2500000_muxSel
[] =
{
    {PMHAL_PRCM_MUX_WKUPAON_ICLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateDivConfig_t
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_2500000_divSel
[] =
{
    {PMHAL_PRCM_DIV_L3INSTR_TS_GCLK,
     8}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK run
 *         at 1250000 Hz.
 */
pmlibClockRateMuxConfig_t
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_1250000_muxSel
[] =
{
    {PMHAL_PRCM_MUX_WKUPAON_ICLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK run
 *         at 1250000 Hz.
 */
pmlibClockRateDivConfig_t
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_1250000_divSel
[] =
{
    {PMHAL_PRCM_DIV_L3INSTR_TS_GCLK,
     16}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK run
 *         at 625000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_625000_muxSel
[] =
{
    {PMHAL_PRCM_MUX_WKUPAON_ICLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK run
 *         at 625000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_625000_divSel
[] =
{
    {PMHAL_PRCM_DIV_L3INSTR_TS_GCLK,
     32}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INSTR_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L3INSTR_L3_GICLK_266000000_divSel[]
    =
    {
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
    };
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK_266000000_divSel[]
    =
    {
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
    };
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK_133000000_divSel[]
    =
    {
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
    };
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4CFG_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L4CFG_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4CFG_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L4CFG_L4_GICLK_133000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4PER_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L4PER_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4PER_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L4PER_L4_GICLK_133000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER2_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER2_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER2_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER2_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TIMER2_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER2_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER2_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER2_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER2_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TIMER2_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER2_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER2_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER2_GFCLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX},
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER2_GFCLK run
 *         at 22579200 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER2_GFCLK_22579200_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER2_GFCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER3_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER3_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER3_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER3_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TIMER3_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER3_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER3_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER3_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER3_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TIMER3_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER3_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER3_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER3_GFCLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX},
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER3_GFCLK run
 *         at 22579200 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER3_GFCLK_22579200_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER3_GFCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER4_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER4_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER4_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER4_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TIMER4_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER4_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER4_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER4_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER4_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TIMER4_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER4_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER4_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER4_GFCLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX},
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER4_GFCLK run
 *         at 22579200 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER4_GFCLK_22579200_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER4_GFCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_UART1_GFCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_UART1_GFCLK_192000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_UART1_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_UART1_GFCLK run
 *         at 48000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_UART1_GFCLK_48000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_UART1_GFCLK_MUX,
     PMHAL_PRCM_DIV_FUNC_48M_FCLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_UART2_GFCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_UART2_GFCLK_192000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_UART2_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_UART2_GFCLK run
 *         at 48000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_UART2_GFCLK_48000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_UART2_GFCLK_MUX,
     PMHAL_PRCM_DIV_FUNC_48M_FCLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_UART3_GFCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_UART3_GFCLK_192000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_UART3_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_UART3_GFCLK run
 *         at 48000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_UART3_GFCLK_48000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_UART3_GFCLK_MUX,
     PMHAL_PRCM_DIV_FUNC_48M_FCLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_GPIO_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_GPIO_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_L4PER_32K_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_L4PER_32K_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_192000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MMC4_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_192000000_divSel[] =
{
    {PMHAL_PRCM_DIV_MMC4_GFCLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 96000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_96000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MMC4_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 96000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_96000000_divSel[] =
{
    {PMHAL_PRCM_DIV_MMC4_GFCLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 48000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_48000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MMC4_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 48000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_48000000_divSel[] =
{
    {PMHAL_PRCM_DIV_MMC4_GFCLK,
     4}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MMC4_GFCLK_MUX,
     PMHAL_PRCM_DIV_FUNC_48M_FCLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_24000000_divSel[] =
{
    {PMHAL_PRCM_DIV_MMC4_GFCLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 12000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_12000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MMC4_GFCLK_MUX,
     PMHAL_PRCM_DIV_FUNC_48M_FCLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MMC4_GFCLK run
 *         at 12000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MMC4_GFCLK_12000000_divSel[] =
{
    {PMHAL_PRCM_DIV_MMC4_GFCLK,
     4}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4PER2_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L4PER2_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4PER2_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L4PER2_L4_GICLK_133000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_QSPI_GFCLK run
 *         at 128000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_QSPI_GFCLK_128000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_QSPI_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_QSPI_GFCLK run
 *         at 128000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_QSPI_GFCLK_128000000_divSel[] =
{
    {PMHAL_PRCM_DIV_QSPI_GFCLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_QSPI_GFCLK run
 *         at 64000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_QSPI_GFCLK_64000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_QSPI_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_QSPI_GFCLK run
 *         at 64000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_QSPI_GFCLK_64000000_divSel[] =
{
    {PMHAL_PRCM_DIV_QSPI_GFCLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_QSPI_GFCLK run
 *         at 32000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_QSPI_GFCLK_32000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_QSPI_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_QSPI_GFCLK run
 *         at 32000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_QSPI_GFCLK_32000000_divSel[] =
{
    {PMHAL_PRCM_DIV_QSPI_GFCLK,
     4}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4PER3_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L4PER3_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4PER3_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L4PER3_L4_GICLK_133000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_VIP1_GCLK run
 *         at 266000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_VIP1_GCLK_266000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_VIP1_GCLK_MUX,
     PMHAL_PRCM_DIV_L3_ICLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_VIP1_GCLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_VIP1_GCLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_ADC_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_ADC_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_ADC_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_ADC_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_ADC_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_FUNC_32K_CLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_FUNC_32K_CLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_WKUPAON_GICLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_WKUPAON_GICLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_WKUPAON_ICLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_DCAN1_SYS_CLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_DCAN1_SYS_CLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_DCAN1_SYS_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_DCAN1_SYS_CLK run
 *         at 22579200 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_DCAN1_SYS_CLK_22579200_muxSel[] =
{
    {PMHAL_PRCM_MUX_DCAN1_SYS_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER1_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER1_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER1_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER1_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TIMER1_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER1_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER1_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER1_GFCLK_MUX,
     PMHAL_PRCM_DIV_TIMER_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TIMER1_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TIMER1_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_TIMER_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER1_GFCLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER1_GFCLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER1_GFCLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX},
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER1_GFCLK run
 *         at 22579200 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_TIMER1_GFCLK_22579200_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER1_GFCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_VID_PIX_CLK run
 *         at 74000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_VID_PIX_CLK_74000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VID_PIX_CLK,
     4}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TESOC_EXT_CLK run
 *         at 48360000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TESOC_EXT_CLK_48360000_divSel[] =
{
    {PMHAL_PRCM_DIV_TESOC_EXT_CLK,
     1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TESOC_EXT_CLK run
 *         at 24180000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TESOC_EXT_CLK_24180000_divSel[] =
{
    {PMHAL_PRCM_DIV_TESOC_EXT_CLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TESOC_EXT_CLK run
 *         at 12090000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_TESOC_EXT_CLK_12090000_divSel[] =
{
    {PMHAL_PRCM_DIV_TESOC_EXT_CLK,
     4}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI1_CLK run
 *         at 5000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI1_CLK_5000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI1_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI1_CLK run
 *         at 5644800 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI1_CLK_5644800_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI1_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI1_CLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI1_CLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK},
    {PMHAL_PRCM_MUX_RTI1_CLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI2_CLK run
 *         at 5000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI2_CLK_5000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI2_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI2_CLK run
 *         at 5644800 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI2_CLK_5644800_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI2_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI2_CLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI2_CLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK},
    {PMHAL_PRCM_MUX_RTI2_CLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI3_CLK run
 *         at 5000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI3_CLK_5000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI3_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI3_CLK run
 *         at 5644800 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI3_CLK_5644800_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI3_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI3_CLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI3_CLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK},
    {PMHAL_PRCM_MUX_RTI3_CLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI4_CLK run
 *         at 5000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI4_CLK_5000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI4_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI4_CLK run
 *         at 5644800 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI4_CLK_5644800_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI4_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI4_CLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI4_CLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK},
    {PMHAL_PRCM_MUX_RTI4_CLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI5_CLK run
 *         at 5000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI5_CLK_5000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI5_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI5_CLK run
 *         at 5644800 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI5_CLK_5644800_muxSel[] =
{
    {PMHAL_PRCM_MUX_RTI5_CLK_MUX,
     PMHAL_PRCM_DIV_SYS_CLK2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_RTI5_CLK run
 *         at 32786 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_RTI5_CLK_32786_muxSel[] =
{
    {PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX,
     PMHAL_PRCM_DIV_FUNC_32K_CLK},
    {PMHAL_PRCM_MUX_RTI5_CLK_MUX,
     PMHAL_PRCM_MUX_FUNC_32K_CLK_MUX}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_IPU_L3_GICLK run
 *         at 266000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_IPU_L3_GICLK_266000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_IPU_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_IPU_L4_GICLK_133000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INSTR_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L3INSTR_L4_GICLK_133000000_divSel[]
    =
    {
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
    };
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_COREAON_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_COREAON_L4_GICLK_133000000_divSel[]
    =
    {
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
    };
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK_133000000_divSel
[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3INIT_L4_GICLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_L3INIT_L4_GICLK_133000000_divSel[] =
{
    {PMHAL_PRCM_DIV_L3_ICLK,
     2},
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKR run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKR_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AHCLKR_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKR run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKR_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKR run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKR_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AHCLKR_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKR run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKR_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKR run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKR_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AHCLKR_MUX,
     PMHAL_PRCM_DIV_FUNC_24M_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKX run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKX_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AHCLKX_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKX run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKX_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKX run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKX_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AHCLKX_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKX run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKX_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AHCLKX run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AHCLKX_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AHCLKX_MUX,
     PMHAL_PRCM_DIV_FUNC_24M_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 5000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_5000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 5000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_5000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     4}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_2500000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP2_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_2500000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     8}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 133000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_133000000_muxSel[]
    =
    {
    {PMHAL_PRCM_MUX_MCASP2_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_L4_ROOT_CLK}
    };
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_133000000_divSel[]
    =
    {
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
    };
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKR run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKR_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AHCLKR_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKR run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKR_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKR run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKR_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AHCLKR_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKR run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKR_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKR run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKR_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AHCLKR_MUX,
     PMHAL_PRCM_DIV_FUNC_24M_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKX run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKX_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AHCLKX_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKX run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKX_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKX run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKX_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AHCLKX_MUX,
     PMHAL_PRCM_DIV_ABE_SYS_CLK}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKX run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKX_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_ABE_SYS_CLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AHCLKX run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AHCLKX_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AHCLKX_MUX,
     PMHAL_PRCM_DIV_FUNC_24M_CLK}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_20000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 20000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_20000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_10000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 10000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_10000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 5000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_5000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 5000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_5000000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     4}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_2500000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MCASP3_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_VIDEO2_CLK2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 2500000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_2500000_divSel[] =
{
    {PMHAL_PRCM_DIV_VIDEO2_CLK2,
     8}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 133000000 Hz.
 */
pmlibClockRateMuxConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_133000000_muxSel[]
    =
    {
    {PMHAL_PRCM_MUX_MCASP3_AUX_GFCLK_MUX,
     PMHAL_PRCM_DIV_L4_ROOT_CLK}
    };
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK run
 *         at 133000000 Hz.
 */
pmlibClockRateDivConfig_t   PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_133000000_divSel[]
    =
    {
    {PMHAL_PRCM_DIV_L4_ROOT_CLK,
     2}
    };
/* -------------------------------------------------------------------------- */
/*              Frequency Configuration Structures                            */
/* -------------------------------------------------------------------------- */

/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CRC_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_CRC_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_CRC_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CRC_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CUSTEFUSE_SYS_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_CUSTEFUSE_SYS_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSP1_GFCLK
 *         for the frequency 500000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DSP1_GFCLK_500000000 =
{
    PMHAL_PRCM_DPLL_DSP_GMAC,
    &PMHAL_PRCM_DPLL_DSP_GMAC_250_4_M3_4,
    PMHAL_PRCM_CLK_DSP1_GFCLK_500000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSP1_GFCLK_500000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSP2_GFCLK
 *         for the frequency 500000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DSP2_GFCLK_500000000 =
{
    PMHAL_PRCM_DPLL_DSP_GMAC,
    &PMHAL_PRCM_DPLL_DSP_GMAC_250_4_M3_4,
    PMHAL_PRCM_CLK_DSP2_GFCLK_500000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSP2_GFCLK_500000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSS_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DSS_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_DSS_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSS_GFCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DSS_GFCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_H12_8,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSS_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DSS_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_DSS_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_EMIF_DLL_GCLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_EMIF_DLL_GCLK_266000000 =
{
    PMHAL_PRCM_DPLL_DDR,
    &PMHAL_PRCM_DPLL_DDR_266_4_H11_8,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_EMIF_DLL_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_EMIF_DLL_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_DDR,
    &PMHAL_PRCM_DPLL_DDR_200_4_H11_8,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_EMIF_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_EMIF_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_EMIF_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_EMIF_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_EMIF_PHY_GCLK
 *         for the frequency 400000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_EMIF_PHY_GCLK_400000000 =
{
    PMHAL_PRCM_DPLL_DDR,
    &PMHAL_PRCM_DPLL_DDR_200_4_M2_2,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_EMIF_PHY_GCLK
 *         for the frequency 532000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_EMIF_PHY_GCLK_532000000 =
{
    PMHAL_PRCM_DPLL_DDR,
    &PMHAL_PRCM_DPLL_DDR_266_4_M2_2,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_EVE1_GFCLK
 *         for the frequency 500000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_EVE1_GFCLK_500000000 =
{
    PMHAL_PRCM_DPLL_DSP_GMAC,
    &PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H13_4,
    PMHAL_PRCM_CLK_EVE1_GFCLK_500000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_EVE1_GFCLK_500000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GMAC_RFT_CLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_GMAC_RFT_CLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    PMHAL_PRCM_CLK_GMAC_RFT_CLK_266000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GMAC_RFT_CLK_266000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_GMAC_RFT_CLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GMAC_RFT_CLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GMAC_MAIN_CLK
 *         for the frequency 125000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_GMAC_MAIN_CLK_125000000 =
{
    PMHAL_PRCM_DPLL_DSP_GMAC,
    &PMHAL_PRCM_DPLL_DSP_GMAC_250_4_M2_4,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GMII_250MHZ_CLK
 *         for the frequency 250000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_GMII_250MHZ_CLK_250000000 =
{
    PMHAL_PRCM_DPLL_DSP_GMAC,
    &PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H12_8,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RMII_50MHZ_CLK
 *         for the frequency 50000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RMII_50MHZ_CLK_50000000 =
{
    PMHAL_PRCM_DPLL_DSP_GMAC,
    &PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H11_40,
    PMHAL_PRCM_CLK_RMII_50MHZ_CLK_50000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RMII_50MHZ_CLK_50000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RGMII_5MHZ_CLK
 *         for the frequency 5000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RGMII_5MHZ_CLK_5000000 =
{
    PMHAL_PRCM_DPLL_DSP_GMAC,
    &PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H11_40,
    PMHAL_PRCM_CLK_RGMII_5MHZ_CLK_5000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RGMII_5MHZ_CLK_5000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AHCLKR
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKR_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP1_AHCLKR_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKR_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP1_AHCLKR_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKR_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AHCLKR
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKR_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP1_AHCLKR_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKR_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP1_AHCLKR_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKR_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AHCLKR
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKR_24000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2_8,
    PMHAL_PRCM_CLK_MCASP1_AHCLKR_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKR_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AHCLKX
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKX_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP1_AHCLKX_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKX_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP1_AHCLKX_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKX_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AHCLKX
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKX_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP1_AHCLKX_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKX_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP1_AHCLKX_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKX_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AHCLKX
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AHCLKX_24000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2_8,
    PMHAL_PRCM_CLK_MCASP1_AHCLKX_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AHCLKX_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK
 *         for the frequency 5000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_5000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_5000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_5000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_5000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_5000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK
 *         for the frequency 2500000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_2500000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_2500000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_2500000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_2500000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_2500000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_133000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_133000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER5_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER5_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER5_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER5_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER5_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER5_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER5_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER5_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER5_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER5_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER5_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER5_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER5_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER5_GFCLK
 *         for the frequency 22579200.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER5_GFCLK_22579200 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER5_GFCLK_22579200_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER5_GFCLK_22579200_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER6_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER6_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER6_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER6_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER6_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER6_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER6_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER6_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER6_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER6_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER6_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER6_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER6_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER6_GFCLK
 *         for the frequency 22579200.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER6_GFCLK_22579200 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER6_GFCLK_22579200_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER6_GFCLK_22579200_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER7_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER7_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER7_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER7_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER7_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER7_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER7_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER7_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER7_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER7_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER7_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER7_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER7_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER7_GFCLK
 *         for the frequency 22579200.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER7_GFCLK_22579200 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER7_GFCLK_22579200_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER7_GFCLK_22579200_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER8_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER8_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER8_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER8_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER8_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER8_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER8_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER8_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER8_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER8_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER8_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER8_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER8_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER8_GFCLK
 *         for the frequency 22579200.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER8_GFCLK_22579200 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER8_GFCLK_22579200_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER8_GFCLK_22579200_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_IPU1_GFCLK
 *         for the frequency 212800000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_IPU1_GFCLK_212800000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H22_5,
    PMHAL_PRCM_CLK_IPU1_GFCLK_212800000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_IPU1_GFCLK_212800000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INIT_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INIT_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3INIT_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INIT_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INSTR_TS_GCLK
 *         for the frequency 2500000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_2500000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_2500000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_2500000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_2500000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_2500000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INSTR_TS_GCLK
 *         for the frequency 1250000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_1250000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_1250000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_1250000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_1250000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_1250000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INSTR_TS_GCLK
 *         for the frequency 625000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_625000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_625000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_625000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_625000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_625000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK
 *         for the frequency 2500000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_2500000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_2500000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_2500000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_2500000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_2500000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK
 *         for the frequency 1250000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_1250000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_1250000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_1250000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_1250000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_1250000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK
 *         for the frequency 625000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_625000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_625000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_625000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_625000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_625000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INSTR_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INSTR_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3INSTR_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4CFG_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L4CFG_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4CFG_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4CFG_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4CFG_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L4CFG_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4CFG_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4CFG_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4PER_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L4PER_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4PER_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4PER_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_PER_96M_GFCLK
 *         for the frequency 96000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_PER_96M_GFCLK_96000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4PER_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L4PER_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4PER_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4PER_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER2_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER2_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER2_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER2_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER2_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER2_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER2_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER2_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER2_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER2_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER2_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER2_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER2_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER2_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER2_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER2_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER2_GFCLK
 *         for the frequency 22579200.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER2_GFCLK_22579200 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER2_GFCLK_22579200_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER2_GFCLK_22579200_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER3_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER3_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER3_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER3_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER3_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER3_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER3_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER3_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER3_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER3_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER3_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER3_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER3_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER3_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER3_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER3_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER3_GFCLK
 *         for the frequency 22579200.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER3_GFCLK_22579200 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER3_GFCLK_22579200_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER3_GFCLK_22579200_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER4_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER4_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER4_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER4_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER4_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER4_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER4_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER4_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER4_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER4_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER4_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER4_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER4_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER4_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER4_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER4_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER4_GFCLK
 *         for the frequency 22579200.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER4_GFCLK_22579200 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER4_GFCLK_22579200_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER4_GFCLK_22579200_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_PER_48M_GFCLK
 *         for the frequency 48000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_PER_48M_GFCLK_48000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_UART1_GFCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_UART1_GFCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_UART1_GFCLK_192000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART1_GFCLK_192000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_UART1_GFCLK
 *         for the frequency 48000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_UART1_GFCLK_48000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_UART1_GFCLK_48000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART1_GFCLK_48000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_UART2_GFCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_UART2_GFCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_UART2_GFCLK_192000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART2_GFCLK_192000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_UART2_GFCLK
 *         for the frequency 48000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_UART2_GFCLK_48000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_UART2_GFCLK_48000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART2_GFCLK_48000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_UART3_GFCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_UART3_GFCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_UART3_GFCLK_192000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART3_GFCLK_192000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_UART3_GFCLK
 *         for the frequency 48000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_UART3_GFCLK_48000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_UART3_GFCLK_48000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART3_GFCLK_48000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GPIO_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_GPIO_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_GPIO_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GPIO_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4PER_32K_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L4PER_32K_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_L4PER_32K_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4PER_32K_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MMC4_GFCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MMC4_GFCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_MMC4_GFCLK_192000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_192000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MMC4_GFCLK_192000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_192000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MMC4_GFCLK
 *         for the frequency 96000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MMC4_GFCLK_96000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_MMC4_GFCLK_96000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_96000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MMC4_GFCLK_96000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_96000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MMC4_GFCLK
 *         for the frequency 48000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MMC4_GFCLK_48000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_MMC4_GFCLK_48000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_48000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MMC4_GFCLK_48000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_48000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MMC4_GFCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MMC4_GFCLK_24000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_MMC4_GFCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MMC4_GFCLK_24000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_24000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MMC4_GFCLK
 *         for the frequency 12000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MMC4_GFCLK_12000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2X2_8,
    PMHAL_PRCM_CLK_MMC4_GFCLK_12000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_12000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MMC4_GFCLK_12000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC4_GFCLK_12000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DCAN2_SYS_CLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DCAN2_SYS_CLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4PER2_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L4PER2_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4PER2_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4PER2_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4PER2_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L4PER2_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4PER2_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4PER2_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_QSPI_GFCLK
 *         for the frequency 128000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_QSPI_GFCLK_128000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_H13_12,
    PMHAL_PRCM_CLK_QSPI_GFCLK_128000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_QSPI_GFCLK_128000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_QSPI_GFCLK_128000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_QSPI_GFCLK_128000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_QSPI_GFCLK
 *         for the frequency 64000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_QSPI_GFCLK_64000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_H13_12,
    PMHAL_PRCM_CLK_QSPI_GFCLK_64000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_QSPI_GFCLK_64000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_QSPI_GFCLK_64000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_QSPI_GFCLK_64000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_QSPI_GFCLK
 *         for the frequency 32000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_QSPI_GFCLK_32000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_H13_12,
    PMHAL_PRCM_CLK_QSPI_GFCLK_32000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_QSPI_GFCLK_32000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_QSPI_GFCLK_32000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_QSPI_GFCLK_32000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4PER3_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L4PER3_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4PER3_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4PER3_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4PER3_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L4PER3_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4PER3_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4PER3_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_VIP1_GCLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_VIP1_GCLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    PMHAL_PRCM_CLK_VIP1_GCLK_266000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_VIP1_GCLK_266000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_VIP1_GCLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_VIP1_GCLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_ISS_GCLK
 *         for the frequency 212800000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_ISS_GCLK_212800000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H23_10,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_ADC_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_ADC_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_ADC_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ADC_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_ADC_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_ADC_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_ADC_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ADC_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_FUNC_32K_CLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_FUNC_32K_CLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_FUNC_32K_CLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_FUNC_32K_CLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_WKUPAON_GICLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_WKUPAON_GICLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_WKUPAON_GICLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_WKUPAON_GICLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DCAN1_SYS_CLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DCAN1_SYS_CLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_DCAN1_SYS_CLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DCAN1_SYS_CLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DCAN1_SYS_CLK
 *         for the frequency 22579200.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DCAN1_SYS_CLK_22579200 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_DCAN1_SYS_CLK_22579200_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DCAN1_SYS_CLK_22579200_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER1_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER1_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER1_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER1_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER1_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER1_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER1_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER1_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER1_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER1_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_TIMER1_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER1_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER1_GFCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER1_GFCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER1_GFCLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER1_GFCLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER1_GFCLK
 *         for the frequency 22579200.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TIMER1_GFCLK_22579200 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER1_GFCLK_22579200_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER1_GFCLK_22579200_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_VID_PIX_CLK
 *         for the frequency 74000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_VID_PIX_CLK_74000000 =
{
    PMHAL_PRCM_DPLL_EVE_VID_DSP,
    &PMHAL_PRCM_DPLL_EVE_VID_DSP_222_4_M2_3,
    NULL,
    0U,
    PMHAL_PRCM_CLK_VID_PIX_CLK_74000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_VID_PIX_CLK_74000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TESOC_EXT_CLK
 *         for the frequency 48360000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TESOC_EXT_CLK_48360000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H13_44,
    NULL,
    0U,
    PMHAL_PRCM_CLK_TESOC_EXT_CLK_48360000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TESOC_EXT_CLK_48360000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TESOC_EXT_CLK
 *         for the frequency 24180000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TESOC_EXT_CLK_24180000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H13_44,
    NULL,
    0U,
    PMHAL_PRCM_CLK_TESOC_EXT_CLK_24180000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TESOC_EXT_CLK_24180000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TESOC_EXT_CLK
 *         for the frequency 12090000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_TESOC_EXT_CLK_12090000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H13_44,
    NULL,
    0U,
    PMHAL_PRCM_CLK_TESOC_EXT_CLK_12090000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TESOC_EXT_CLK_12090000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DEBUG_ATB_CLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DEBUG_ATB_CLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H11_8,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DEBUG_TREXCPT_CLK
 *         for the frequency 384000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DEBUG_TREXCPT_CLK_384000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_H14_4,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DEBUG_STMEXPT_CLK
 *         for the frequency 193450000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_DEBUG_STMEXPT_CLK_193450000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H21_11,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI1_CLK
 *         for the frequency 5000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI1_CLK_5000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI1_CLK_5000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI1_CLK_5000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI1_CLK
 *         for the frequency 5644800.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI1_CLK_5644800 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI1_CLK_5644800_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI1_CLK_5644800_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI1_CLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI1_CLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI1_CLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI1_CLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI2_CLK
 *         for the frequency 5000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI2_CLK_5000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI2_CLK_5000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI2_CLK_5000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI2_CLK
 *         for the frequency 5644800.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI2_CLK_5644800 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI2_CLK_5644800_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI2_CLK_5644800_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI2_CLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI2_CLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI2_CLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI2_CLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI3_CLK
 *         for the frequency 5000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI3_CLK_5000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI3_CLK_5000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI3_CLK_5000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI3_CLK
 *         for the frequency 5644800.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI3_CLK_5644800 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI3_CLK_5644800_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI3_CLK_5644800_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI3_CLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI3_CLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI3_CLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI3_CLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI4_CLK
 *         for the frequency 5000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI4_CLK_5000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI4_CLK_5000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI4_CLK_5000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI4_CLK
 *         for the frequency 5644800.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI4_CLK_5644800 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI4_CLK_5644800_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI4_CLK_5644800_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI4_CLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI4_CLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI4_CLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI4_CLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI5_CLK
 *         for the frequency 5000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI5_CLK_5000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI5_CLK_5000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI5_CLK_5000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI5_CLK
 *         for the frequency 5644800.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI5_CLK_5644800 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI5_CLK_5644800_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI5_CLK_5644800_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTI5_CLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_RTI5_CLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_RTI5_CLK_32786_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTI5_CLK_32786_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_IPU_L3_GICLK
 *         for the frequency 266000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_IPU_L3_GICLK_266000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_IPU_L3_GICLK_266000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_IPU_L3_GICLK_266000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_IPU_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_IPU_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_IPU_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_IPU_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INSTR_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INSTR_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3INSTR_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INSTR_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_COREAON_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_COREAON_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_COREAON_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_COREAON_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3INIT_L4_GICLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_L3INIT_L4_GICLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3INIT_L4_GICLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3INIT_L4_GICLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCAN_CLK
 *         for the frequency 80000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCAN_CLK_80000000 =
{
    PMHAL_PRCM_DPLL_DSP_GMAC,
    &PMHAL_PRCM_DPLL_DSP_GMAC_250_4_H14_25,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AHCLKR
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AHCLKR_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP2_AHCLKR_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKR_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP2_AHCLKR_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKR_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AHCLKR
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AHCLKR_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP2_AHCLKR_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKR_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP2_AHCLKR_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKR_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AHCLKR
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AHCLKR_24000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2_8,
    PMHAL_PRCM_CLK_MCASP2_AHCLKR_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKR_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AHCLKX
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AHCLKX_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP2_AHCLKX_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKX_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP2_AHCLKX_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKX_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AHCLKX
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AHCLKX_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP2_AHCLKX_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKX_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP2_AHCLKX_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKX_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AHCLKX
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AHCLKX_24000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2_8,
    PMHAL_PRCM_CLK_MCASP2_AHCLKX_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AHCLKX_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK
 *         for the frequency 5000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_5000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_5000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_5000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_5000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_5000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK
 *         for the frequency 2500000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_2500000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_2500000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_2500000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_2500000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_2500000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_133000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_133000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AHCLKR
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AHCLKR_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP3_AHCLKR_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKR_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP3_AHCLKR_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKR_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AHCLKR
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AHCLKR_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP3_AHCLKR_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKR_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP3_AHCLKR_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKR_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AHCLKR
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AHCLKR_24000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2_8,
    PMHAL_PRCM_CLK_MCASP3_AHCLKR_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKR_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AHCLKX
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AHCLKX_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP3_AHCLKX_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKX_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP3_AHCLKX_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKX_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AHCLKX
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AHCLKX_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP3_AHCLKX_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKX_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP3_AHCLKX_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKX_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AHCLKX
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AHCLKX_24000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_192_4_M2_8,
    PMHAL_PRCM_CLK_MCASP3_AHCLKX_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AHCLKX_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK
 *         for the frequency 20000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_20000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_20000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_20000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_20000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_20000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK
 *         for the frequency 10000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_10000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_10000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_10000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_10000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_10000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK
 *         for the frequency 5000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_5000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_5000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_5000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_5000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_5000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK
 *         for the frequency 2500000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_2500000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_2500000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_2500000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_2500000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_2500000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK
 *         for the frequency 133000000.
 */
pmlibClockRateFreqConfig_t  PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_133000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_266_4_H12_4,
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_133000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_133000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_133000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_133000000_divSel,
        pmlibClockRateDivConfig_t)
};
/* -------------------------------------------------------------------------- */
/*              Frequency List for the different Clocks                       */
/* -------------------------------------------------------------------------- */

/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_CRC_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_CRC_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_CRC_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK_20000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK_20000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_CUSTEFUSE_SYS_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_CUSTEFUSE_SYS_GFCLK_freqList[] =
{
    {10000000U, &PMHAL_PRCM_CLK_CUSTEFUSE_SYS_GFCLK_10000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DSP1_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DSP1_GFCLK_freqList[] =
{
    {500000000U, &PMHAL_PRCM_CLK_DSP1_GFCLK_500000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DSP2_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DSP2_GFCLK_freqList[] =
{
    {500000000U, &PMHAL_PRCM_CLK_DSP2_GFCLK_500000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DSS_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DSS_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_DSS_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DSS_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DSS_GFCLK_freqList[] =
{
    {192000000U, &PMHAL_PRCM_CLK_DSS_GFCLK_192000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DSS_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DSS_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_DSS_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_EMIF_DLL_GCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_EMIF_DLL_GCLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_EMIF_DLL_GCLK_266000000},
    {200000000U, &PMHAL_PRCM_CLK_EMIF_DLL_GCLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_EMIF_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_EMIF_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_EMIF_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_EMIF_PHY_GCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_EMIF_PHY_GCLK_freqList[] =
{
    {400000000U, &PMHAL_PRCM_CLK_EMIF_PHY_GCLK_400000000},
    {532000000U, &PMHAL_PRCM_CLK_EMIF_PHY_GCLK_532000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_EVE1_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_EVE1_GFCLK_freqList[] =
{
    {500000000U, &PMHAL_PRCM_CLK_EVE1_GFCLK_500000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GMAC_RFT_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_GMAC_RFT_CLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_GMAC_RFT_CLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GMAC_MAIN_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_GMAC_MAIN_CLK_freqList[] =
{
    {125000000U, &PMHAL_PRCM_CLK_GMAC_MAIN_CLK_125000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GMII_250MHZ_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_GMII_250MHZ_CLK_freqList[] =
{
    {250000000U, &PMHAL_PRCM_CLK_GMII_250MHZ_CLK_250000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_RMII_50MHZ_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_RMII_50MHZ_CLK_freqList[] =
{
    {50000000U, &PMHAL_PRCM_CLK_RMII_50MHZ_CLK_50000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_RGMII_5MHZ_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_RGMII_5MHZ_CLK_freqList[] =
{
    {5000000U, &PMHAL_PRCM_CLK_RGMII_5MHZ_CLK_5000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP1_AHCLKR.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCASP1_AHCLKR_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_MCASP1_AHCLKR_20000000},
    {10000000U, &PMHAL_PRCM_CLK_MCASP1_AHCLKR_10000000},
    {24000000U, &PMHAL_PRCM_CLK_MCASP1_AHCLKR_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP1_AHCLKX.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCASP1_AHCLKX_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_MCASP1_AHCLKX_20000000},
    {10000000U, &PMHAL_PRCM_CLK_MCASP1_AHCLKX_10000000},
    {24000000U, &PMHAL_PRCM_CLK_MCASP1_AHCLKX_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_freqList[] =
{
    {20000000U,  &PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_20000000 },
    {10000000U,  &PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_10000000 },
    {5000000U,   &PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_5000000  },
    {2500000U,   &PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_2500000  },
    {133000000U, &PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER5_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_TIMER5_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_TIMER5_GFCLK_20000000},
    {10000000U, &PMHAL_PRCM_CLK_TIMER5_GFCLK_10000000},
    {32786U,    &PMHAL_PRCM_CLK_TIMER5_GFCLK_32786   },
    {22579200U, &PMHAL_PRCM_CLK_TIMER5_GFCLK_22579200}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER6_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_TIMER6_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_TIMER6_GFCLK_20000000},
    {10000000U, &PMHAL_PRCM_CLK_TIMER6_GFCLK_10000000},
    {32786U,    &PMHAL_PRCM_CLK_TIMER6_GFCLK_32786   },
    {22579200U, &PMHAL_PRCM_CLK_TIMER6_GFCLK_22579200}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER7_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_TIMER7_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_TIMER7_GFCLK_20000000},
    {10000000U, &PMHAL_PRCM_CLK_TIMER7_GFCLK_10000000},
    {32786U,    &PMHAL_PRCM_CLK_TIMER7_GFCLK_32786   },
    {22579200U, &PMHAL_PRCM_CLK_TIMER7_GFCLK_22579200}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER8_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_TIMER8_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_TIMER8_GFCLK_20000000},
    {10000000U, &PMHAL_PRCM_CLK_TIMER8_GFCLK_10000000},
    {32786U,    &PMHAL_PRCM_CLK_TIMER8_GFCLK_32786   },
    {22579200U, &PMHAL_PRCM_CLK_TIMER8_GFCLK_22579200}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_IPU1_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_IPU1_GFCLK_freqList[] =
{
    {212800000U, &PMHAL_PRCM_CLK_IPU1_GFCLK_212800000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3INIT_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L3INIT_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_L3INIT_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3INSTR_TS_GCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_freqList[] =
{
    {2500000U, &PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_2500000},
    {1250000U, &PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_1250000},
    {625000U,  &PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_625000 }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_freqList[] =
{
    {2500000U, &PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_2500000},
    {1250000U, &PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_1250000},
    {625000U,  &PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_625000 }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3INSTR_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L3INSTR_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_L3INSTR_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4CFG_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L4CFG_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_L4CFG_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4CFG_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L4CFG_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_L4CFG_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4PER_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L4PER_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_L4PER_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_PER_96M_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_PER_96M_GFCLK_freqList[] =
{
    {96000000U, &PMHAL_PRCM_CLK_PER_96M_GFCLK_96000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4PER_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L4PER_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_L4PER_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER2_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_TIMER2_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_TIMER2_GFCLK_20000000},
    {10000000U, &PMHAL_PRCM_CLK_TIMER2_GFCLK_10000000},
    {32786U,    &PMHAL_PRCM_CLK_TIMER2_GFCLK_32786   },
    {22579200U, &PMHAL_PRCM_CLK_TIMER2_GFCLK_22579200}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER3_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_TIMER3_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_TIMER3_GFCLK_20000000},
    {10000000U, &PMHAL_PRCM_CLK_TIMER3_GFCLK_10000000},
    {32786U,    &PMHAL_PRCM_CLK_TIMER3_GFCLK_32786   },
    {22579200U, &PMHAL_PRCM_CLK_TIMER3_GFCLK_22579200}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER4_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_TIMER4_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_TIMER4_GFCLK_20000000},
    {10000000U, &PMHAL_PRCM_CLK_TIMER4_GFCLK_10000000},
    {32786U,    &PMHAL_PRCM_CLK_TIMER4_GFCLK_32786   },
    {22579200U, &PMHAL_PRCM_CLK_TIMER4_GFCLK_22579200}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_PER_48M_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_PER_48M_GFCLK_freqList[] =
{
    {48000000U, &PMHAL_PRCM_CLK_PER_48M_GFCLK_48000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_UART1_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_UART1_GFCLK_freqList[] =
{
    {192000000U, &PMHAL_PRCM_CLK_UART1_GFCLK_192000000},
    {48000000U,  &PMHAL_PRCM_CLK_UART1_GFCLK_48000000 }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_UART2_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_UART2_GFCLK_freqList[] =
{
    {192000000U, &PMHAL_PRCM_CLK_UART2_GFCLK_192000000},
    {48000000U,  &PMHAL_PRCM_CLK_UART2_GFCLK_48000000 }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_UART3_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_UART3_GFCLK_freqList[] =
{
    {192000000U, &PMHAL_PRCM_CLK_UART3_GFCLK_192000000},
    {48000000U,  &PMHAL_PRCM_CLK_UART3_GFCLK_48000000 }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GPIO_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_GPIO_GFCLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_GPIO_GFCLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4PER_32K_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L4PER_32K_GFCLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_L4PER_32K_GFCLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MMC4_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MMC4_GFCLK_freqList[] =
{
    {192000000U, &PMHAL_PRCM_CLK_MMC4_GFCLK_192000000},
    {96000000U,  &PMHAL_PRCM_CLK_MMC4_GFCLK_96000000 },
    {48000000U,  &PMHAL_PRCM_CLK_MMC4_GFCLK_48000000 },
    {24000000U,  &PMHAL_PRCM_CLK_MMC4_GFCLK_24000000 },
    {12000000U,  &PMHAL_PRCM_CLK_MMC4_GFCLK_12000000 }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DCAN2_SYS_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DCAN2_SYS_CLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_DCAN2_SYS_CLK_20000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4PER2_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L4PER2_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_L4PER2_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4PER2_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L4PER2_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_L4PER2_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_QSPI_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_QSPI_GFCLK_freqList[] =
{
    {128000000U, &PMHAL_PRCM_CLK_QSPI_GFCLK_128000000},
    {64000000U,  &PMHAL_PRCM_CLK_QSPI_GFCLK_64000000 },
    {32000000U,  &PMHAL_PRCM_CLK_QSPI_GFCLK_32000000 }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4PER3_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L4PER3_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_L4PER3_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4PER3_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L4PER3_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_L4PER3_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_VIP1_GCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_VIP1_GCLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_VIP1_GCLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_ISS_GCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_ISS_GCLK_freqList[] =
{
    {212800000U, &PMHAL_PRCM_CLK_ISS_GCLK_212800000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_ADC_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_ADC_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_ADC_GFCLK_20000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_ADC_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_ADC_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_ADC_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_FUNC_32K_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_FUNC_32K_CLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_FUNC_32K_CLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_WKUPAON_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_WKUPAON_GICLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_WKUPAON_GICLK_20000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DCAN1_SYS_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DCAN1_SYS_CLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_DCAN1_SYS_CLK_20000000},
    {22579200U, &PMHAL_PRCM_CLK_DCAN1_SYS_CLK_22579200}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER1_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_TIMER1_GFCLK_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_TIMER1_GFCLK_20000000},
    {10000000U, &PMHAL_PRCM_CLK_TIMER1_GFCLK_10000000},
    {32786U,    &PMHAL_PRCM_CLK_TIMER1_GFCLK_32786   },
    {22579200U, &PMHAL_PRCM_CLK_TIMER1_GFCLK_22579200}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_VID_PIX_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_VID_PIX_CLK_freqList[] =
{
    {74000000U, &PMHAL_PRCM_CLK_VID_PIX_CLK_74000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TESOC_EXT_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_TESOC_EXT_CLK_freqList[] =
{
    {48360000U, &PMHAL_PRCM_CLK_TESOC_EXT_CLK_48360000},
    {24180000U, &PMHAL_PRCM_CLK_TESOC_EXT_CLK_24180000},
    {12090000U, &PMHAL_PRCM_CLK_TESOC_EXT_CLK_12090000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DEBUG_ATB_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DEBUG_ATB_CLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_DEBUG_ATB_CLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DEBUG_TREXCPT_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DEBUG_TREXCPT_CLK_freqList[] =
{
    {384000000U, &PMHAL_PRCM_CLK_DEBUG_TREXCPT_CLK_384000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DEBUG_STMEXPT_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_DEBUG_STMEXPT_CLK_freqList[] =
{
    {193450000U, &PMHAL_PRCM_CLK_DEBUG_STMEXPT_CLK_193450000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_RTI1_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_RTI1_CLK_freqList[] =
{
    {5000000U, &PMHAL_PRCM_CLK_RTI1_CLK_5000000},
    {5644800U, &PMHAL_PRCM_CLK_RTI1_CLK_5644800},
    {32786U,   &PMHAL_PRCM_CLK_RTI1_CLK_32786  }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_RTI2_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_RTI2_CLK_freqList[] =
{
    {5000000U, &PMHAL_PRCM_CLK_RTI2_CLK_5000000},
    {5644800U, &PMHAL_PRCM_CLK_RTI2_CLK_5644800},
    {32786U,   &PMHAL_PRCM_CLK_RTI2_CLK_32786  }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_RTI3_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_RTI3_CLK_freqList[] =
{
    {5000000U, &PMHAL_PRCM_CLK_RTI3_CLK_5000000},
    {5644800U, &PMHAL_PRCM_CLK_RTI3_CLK_5644800},
    {32786U,   &PMHAL_PRCM_CLK_RTI3_CLK_32786  }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_RTI4_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_RTI4_CLK_freqList[] =
{
    {5000000U, &PMHAL_PRCM_CLK_RTI4_CLK_5000000},
    {5644800U, &PMHAL_PRCM_CLK_RTI4_CLK_5644800},
    {32786U,   &PMHAL_PRCM_CLK_RTI4_CLK_32786  }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_RTI5_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_RTI5_CLK_freqList[] =
{
    {5000000U, &PMHAL_PRCM_CLK_RTI5_CLK_5000000},
    {5644800U, &PMHAL_PRCM_CLK_RTI5_CLK_5644800},
    {32786U,   &PMHAL_PRCM_CLK_RTI5_CLK_32786  }
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_IPU_L3_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_IPU_L3_GICLK_freqList[] =
{
    {266000000U, &PMHAL_PRCM_CLK_IPU_L3_GICLK_266000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_IPU_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_IPU_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_IPU_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3INSTR_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L3INSTR_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_L3INSTR_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_COREAON_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_COREAON_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_COREAON_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3INIT_L4_GICLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_L3INIT_L4_GICLK_freqList[] =
{
    {133000000U, &PMHAL_PRCM_CLK_L3INIT_L4_GICLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCAN_CLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCAN_CLK_freqList[] =
{
    {80000000U, &PMHAL_PRCM_CLK_MCAN_CLK_80000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP2_AHCLKR.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCASP2_AHCLKR_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_MCASP2_AHCLKR_20000000},
    {10000000U, &PMHAL_PRCM_CLK_MCASP2_AHCLKR_10000000},
    {24000000U, &PMHAL_PRCM_CLK_MCASP2_AHCLKR_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP2_AHCLKX.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCASP2_AHCLKX_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_MCASP2_AHCLKX_20000000},
    {10000000U, &PMHAL_PRCM_CLK_MCASP2_AHCLKX_10000000},
    {24000000U, &PMHAL_PRCM_CLK_MCASP2_AHCLKX_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_freqList[] =
{
    {20000000U,  &PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_20000000 },
    {10000000U,  &PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_10000000 },
    {5000000U,   &PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_5000000  },
    {2500000U,   &PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_2500000  },
    {133000000U, &PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_133000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP3_AHCLKR.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCASP3_AHCLKR_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_MCASP3_AHCLKR_20000000},
    {10000000U, &PMHAL_PRCM_CLK_MCASP3_AHCLKR_10000000},
    {24000000U, &PMHAL_PRCM_CLK_MCASP3_AHCLKR_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP3_AHCLKX.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCASP3_AHCLKX_freqList[] =
{
    {20000000U, &PMHAL_PRCM_CLK_MCASP3_AHCLKX_20000000},
    {10000000U, &PMHAL_PRCM_CLK_MCASP3_AHCLKX_10000000},
    {24000000U, &PMHAL_PRCM_CLK_MCASP3_AHCLKX_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK.
 */
pmlibClockRateFreqList_t    PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_freqList[] =
{
    {20000000U,  &PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_20000000 },
    {10000000U,  &PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_10000000 },
    {5000000U,   &PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_5000000  },
    {2500000U,   &PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_2500000  },
    {133000000U, &PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_133000000}
};
/* -------------------------------------------------------------------------- */
/*              Clock ID to Frequency List Array                              */
/* -------------------------------------------------------------------------- */

/**
 * \brief  Array containing the frequency list for all the clocks
 *         in the device.
 */
pmlibClockRateAllFreqList_t pmlibClockRateAllClockFreq[] =
{
    {PMHAL_PRCM_CLK_CRC_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_CRC_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_CRC_L3_GICLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_ABE_GICLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_CLKOUTMUX1_CLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_CLKOUTMUX2_CLK */
    {PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK */
    {PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK */
    {PMHAL_PRCM_CLK_CUSTEFUSE_SYS_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_CUSTEFUSE_SYS_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_CUSTEFUSE_SYS_GFCLK */
    {PMHAL_PRCM_CLK_DSP1_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DSP1_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DSP1_GFCLK */
    {PMHAL_PRCM_CLK_DSP2_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DSP2_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DSP2_GFCLK */
    {PMHAL_PRCM_CLK_DSS_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DSS_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DSS_L3_GICLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_HDMI_CEC_GFCLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_HDMI_PHY_GFCLK */
    {PMHAL_PRCM_CLK_DSS_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DSS_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DSS_GFCLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_HDMI_DPLL_CLK */
    {PMHAL_PRCM_CLK_DSS_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DSS_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DSS_L4_GICLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_VIDEO1_DPLL_CLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_VIDEO2_DPLL_CLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_SDVENC_GFCLK */
    {PMHAL_PRCM_CLK_EMIF_DLL_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_EMIF_DLL_GCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_EMIF_DLL_GCLK */
    {PMHAL_PRCM_CLK_EMIF_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_EMIF_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_EMIF_L3_GICLK */
    {PMHAL_PRCM_CLK_EMIF_PHY_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_EMIF_PHY_GCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_EMIF_PHY_GCLK */
    {PMHAL_PRCM_CLK_EVE1_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_EVE1_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_EVE1_GFCLK */
    {PMHAL_PRCM_CLK_GMAC_RFT_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_GMAC_RFT_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GMAC_RFT_CLK */
    {PMHAL_PRCM_CLK_GMAC_MAIN_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_GMAC_MAIN_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GMAC_MAIN_CLK */
    {PMHAL_PRCM_CLK_GMII_250MHZ_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_GMII_250MHZ_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GMII_250MHZ_CLK */
    {PMHAL_PRCM_CLK_RMII_50MHZ_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_RMII_50MHZ_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_RMII_50MHZ_CLK */
    {PMHAL_PRCM_CLK_RGMII_5MHZ_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_RGMII_5MHZ_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_RGMII_5MHZ_CLK */
    {PMHAL_PRCM_CLK_MCASP1_AHCLKR_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCASP1_AHCLKR_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP1_AHCLKR */
    {PMHAL_PRCM_CLK_MCASP1_AHCLKX_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCASP1_AHCLKX_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP1_AHCLKX */
    {PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP1_AUX_GFCLK */
    {PMHAL_PRCM_CLK_TIMER5_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_TIMER5_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER5_GFCLK */
    {PMHAL_PRCM_CLK_TIMER6_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_TIMER6_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER6_GFCLK */
    {PMHAL_PRCM_CLK_TIMER7_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_TIMER7_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER7_GFCLK */
    {PMHAL_PRCM_CLK_TIMER8_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_TIMER8_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER8_GFCLK */
    {PMHAL_PRCM_CLK_IPU1_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_IPU1_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_IPU1_GFCLK */
    {PMHAL_PRCM_CLK_L3INIT_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L3INIT_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3INIT_L3_GICLK */
    {PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L3INSTR_TS_GCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3INSTR_TS_GCLK */
    {PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK */
    {PMHAL_PRCM_CLK_L3INSTR_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L3INSTR_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3INSTR_L3_GICLK */
    {PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK */
    {PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3MAIN1_L4_GICLK */
    {PMHAL_PRCM_CLK_L4CFG_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L4CFG_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4CFG_L3_GICLK */
    {PMHAL_PRCM_CLK_L4CFG_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L4CFG_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4CFG_L4_GICLK */
    {PMHAL_PRCM_CLK_L4PER_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L4PER_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4PER_L3_GICLK */
    {PMHAL_PRCM_CLK_PER_96M_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_PER_96M_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_PER_96M_GFCLK */
    {PMHAL_PRCM_CLK_L4PER_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L4PER_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4PER_L4_GICLK */
    {PMHAL_PRCM_CLK_TIMER2_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_TIMER2_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER2_GFCLK */
    {PMHAL_PRCM_CLK_TIMER3_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_TIMER3_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER3_GFCLK */
    {PMHAL_PRCM_CLK_TIMER4_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_TIMER4_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER4_GFCLK */
    {PMHAL_PRCM_CLK_PER_48M_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_PER_48M_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_PER_48M_GFCLK */
    {PMHAL_PRCM_CLK_UART1_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_UART1_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_UART1_GFCLK */
    {PMHAL_PRCM_CLK_UART2_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_UART2_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_UART2_GFCLK */
    {PMHAL_PRCM_CLK_UART3_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_UART3_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_UART3_GFCLK */
    {PMHAL_PRCM_CLK_GPIO_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_GPIO_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GPIO_GFCLK */
    {PMHAL_PRCM_CLK_L4PER_32K_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L4PER_32K_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4PER_32K_GFCLK */
    {PMHAL_PRCM_CLK_MMC4_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MMC4_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MMC4_GFCLK */
    {PMHAL_PRCM_CLK_DCAN2_SYS_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DCAN2_SYS_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DCAN2_SYS_CLK */
    {PMHAL_PRCM_CLK_L4PER2_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L4PER2_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4PER2_L3_GICLK */
    {PMHAL_PRCM_CLK_L4PER2_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L4PER2_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4PER2_L4_GICLK */
    {PMHAL_PRCM_CLK_QSPI_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_QSPI_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_QSPI_GFCLK */
    {PMHAL_PRCM_CLK_L4PER3_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L4PER3_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4PER3_L3_GICLK */
    {PMHAL_PRCM_CLK_L4PER3_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L4PER3_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4PER3_L4_GICLK */
    {PMHAL_PRCM_CLK_VIP1_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_VIP1_GCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_VIP1_GCLK */
    {PMHAL_PRCM_CLK_ISS_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_ISS_GCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_ISS_GCLK */
    {NULL,                                          0U },
    /**< PMHAL_PRCM_CLK_EMU_SYS_CLK */
    {PMHAL_PRCM_CLK_ADC_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_ADC_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_ADC_GFCLK */
    {PMHAL_PRCM_CLK_ADC_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_ADC_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_ADC_L3_GICLK */
    {PMHAL_PRCM_CLK_FUNC_32K_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_FUNC_32K_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_FUNC_32K_CLK */
    {PMHAL_PRCM_CLK_WKUPAON_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_WKUPAON_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_WKUPAON_GICLK */
    {PMHAL_PRCM_CLK_DCAN1_SYS_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DCAN1_SYS_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DCAN1_SYS_CLK */
    {PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK */
    {PMHAL_PRCM_CLK_TIMER1_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_TIMER1_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER1_GFCLK */
    {PMHAL_PRCM_CLK_VID_PIX_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_VID_PIX_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_VID_PIX_CLK */
    {PMHAL_PRCM_CLK_TESOC_EXT_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_TESOC_EXT_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TESOC_EXT_CLK */
    {PMHAL_PRCM_CLK_DEBUG_ATB_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DEBUG_ATB_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DEBUG_ATB_CLK */
    {PMHAL_PRCM_CLK_DEBUG_TREXCPT_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DEBUG_TREXCPT_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DEBUG_TREXCPT_CLK */
    {PMHAL_PRCM_CLK_DEBUG_STMEXPT_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_DEBUG_STMEXPT_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DEBUG_STMEXPT_CLK */
    {PMHAL_PRCM_CLK_RTI1_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_RTI1_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_RTI1_CLK */
    {PMHAL_PRCM_CLK_RTI2_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_RTI2_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_RTI2_CLK */
    {PMHAL_PRCM_CLK_RTI3_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_RTI3_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_RTI3_CLK */
    {PMHAL_PRCM_CLK_RTI4_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_RTI4_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_RTI4_CLK */
    {PMHAL_PRCM_CLK_RTI5_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_RTI5_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_RTI5_CLK */
    {PMHAL_PRCM_CLK_IPU_L3_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_IPU_L3_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_IPU_L3_GICLK */
    {PMHAL_PRCM_CLK_IPU_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_IPU_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_IPU_L4_GICLK */
    {PMHAL_PRCM_CLK_L3INSTR_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L3INSTR_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3INSTR_L4_GICLK */
    {PMHAL_PRCM_CLK_COREAON_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_COREAON_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_COREAON_L4_GICLK */
    {PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_CUSTEFUSE_L4_GICLK */
    {PMHAL_PRCM_CLK_L3INIT_L4_GICLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_L3INIT_L4_GICLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3INIT_L4_GICLK */
    {PMHAL_PRCM_CLK_MCAN_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCAN_CLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCAN_CLK */
    {PMHAL_PRCM_CLK_MCASP2_AHCLKR_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCASP2_AHCLKR_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP2_AHCLKR */
    {PMHAL_PRCM_CLK_MCASP2_AHCLKX_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCASP2_AHCLKX_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP2_AHCLKX */
    {PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP2_AUX_GFCLK */
    {PMHAL_PRCM_CLK_MCASP3_AHCLKR_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCASP3_AHCLKR_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP3_AHCLKR */
    {PMHAL_PRCM_CLK_MCASP3_AHCLKX_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCASP3_AHCLKX_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP3_AHCLKX */
    {PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
         PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK_freqList,
         pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP3_AUX_GFCLK */
};

/* -------------------------------------------------------------------------- */
/*              Generic Clock ID List                                         */
/* -------------------------------------------------------------------------- */
/**
 * \brief  Array containing the mapping for which clock of the module can
 *         be referred to by PMHAL_PRCM_CLK_GENERIC in the Set and Get API.
 */
pmhalPrcmClockId_t          gModuleGenericClkList[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CRC
    PMHAL_PRCM_CLK_CRC_L3_GICLK,
    /**< PMHAL_PRCM_MOD_CRC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CRC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX_CORE
    PMHAL_PRCM_CLK_SR_CORE_SYS_GFCLK,
    /**< PMHAL_PRCM_MOD_SMARTREFLEX_CORE */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX_CORE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX_DSPEVE
    PMHAL_PRCM_CLK_SR_DSPEVE_SYS_GFCLK,
    /**< PMHAL_PRCM_MOD_SMARTREFLEX_DSPEVE */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX_DSPEVE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EFUSE_CTRL_CUST
    PMHAL_PRCM_CLK_CUSTEFUSE_SYS_GFCLK,
    /**< PMHAL_PRCM_MOD_EFUSE_CTRL_CUST */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EFUSE_CTRL_CUST */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSP1
    PMHAL_PRCM_CLK_DSP1_GFCLK,
    /**< PMHAL_PRCM_MOD_DSP1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSP2
    PMHAL_PRCM_CLK_DSP2_GFCLK,
    /**< PMHAL_PRCM_MOD_DSP2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSP2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSS
    PMHAL_PRCM_CLK_DSS_GFCLK,
    /**< PMHAL_PRCM_MOD_DSS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL
    PMHAL_PRCM_CLK_EMIF_DLL_GCLK,
    /**< PMHAL_PRCM_MOD_DLL */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF1
    PMHAL_PRCM_CLK_EMIF_PHY_GCLK,
    /**< PMHAL_PRCM_MOD_EMIF1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EVE1
    PMHAL_PRCM_CLK_EVE1_GFCLK,
    /**< PMHAL_PRCM_MOD_EVE1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EVE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC
    PMHAL_PRCM_CLK_GMAC_MAIN_CLK,
    /**< PMHAL_PRCM_MOD_CPGMAC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    PMHAL_PRCM_CLK_MCASP1_AHCLKR,
    /**< PMHAL_PRCM_MOD_MCASP1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
    PMHAL_PRCM_CLK_TIMER5_GFCLK,
    /**< PMHAL_PRCM_MOD_TIMER5 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
    PMHAL_PRCM_CLK_TIMER6_GFCLK,
    /**< PMHAL_PRCM_MOD_TIMER6 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
    PMHAL_PRCM_CLK_TIMER7_GFCLK,
    /**< PMHAL_PRCM_MOD_TIMER7 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER8
    PMHAL_PRCM_CLK_TIMER8_GFCLK,
    /**< PMHAL_PRCM_MOD_TIMER8 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_IPU1
    PMHAL_PRCM_CLK_IPU1_GFCLK,
    /**< PMHAL_PRCM_MOD_IPU1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IPU1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_IEEE1500_2_OCP
    PMHAL_PRCM_CLK_L3INIT_L3_GICLK,
    /**< PMHAL_PRCM_MOD_IEEE1500_2_OCP */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE1500_2_OCP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CTRL_MODULE_BANDGAP
    PMHAL_PRCM_CLK_L3INSTR_TS_GCLK,
    /**< PMHAL_PRCM_MOD_CTRL_MODULE_BANDGAP */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CTRL_MODULE_BANDGAP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING
    PMHAL_PRCM_CLK_L3INSTR_DLL_AGING_GCLK,
    /**< PMHAL_PRCM_MOD_DLL_AGING */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
    PMHAL_PRCM_CLK_L3INSTR_L3_GICLK,
    /**< PMHAL_PRCM_MOD_L3_INSTR */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_MAIN_2
    PMHAL_PRCM_CLK_L3INSTR_L3_GICLK,
    /**< PMHAL_PRCM_MOD_L3_MAIN_2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_MAIN_2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC
    PMHAL_PRCM_CLK_L3INSTR_L3_GICLK,
    /**< PMHAL_PRCM_MOD_OCP_WP_NOC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK,
    /**< PMHAL_PRCM_MOD_GPMC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_MAIN_1
    PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK,
    /**< PMHAL_PRCM_MOD_L3_MAIN_1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_MAIN_1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU_EDMA
    PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK,
    /**< PMHAL_PRCM_MOD_MMU_EDMA */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU_EDMA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMC_RAM1
    PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK,
    /**< PMHAL_PRCM_MOD_OCMC_RAM1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMC_RAM1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TESOC
    PMHAL_PRCM_CLK_TESOC_EXT_CLK,
    /**< PMHAL_PRCM_MOD_TESOC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TESOC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
    PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK,
    /**< PMHAL_PRCM_MOD_TPCC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
    PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK,
    /**< PMHAL_PRCM_MOD_TPTC1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
    PMHAL_PRCM_CLK_L3MAIN1_L3_GICLK,
    /**< PMHAL_PRCM_MOD_TPTC2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_CFG
    PMHAL_PRCM_CLK_L4CFG_L3_GICLK,
    /**< PMHAL_PRCM_MOD_L4_CFG */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_CFG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    PMHAL_PRCM_CLK_L4CFG_L3_GICLK,
    /**< PMHAL_PRCM_MOD_SPINLOCK */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1
    PMHAL_PRCM_CLK_L4CFG_L3_GICLK,
    /**< PMHAL_PRCM_MOD_MAILBOX1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX2
    PMHAL_PRCM_CLK_L4CFG_L3_GICLK,
    /**< PMHAL_PRCM_MOD_MAILBOX2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    PMHAL_PRCM_CLK_PER_96M_GFCLK,
    /**< PMHAL_PRCM_MOD_I2C1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
    PMHAL_PRCM_CLK_PER_96M_GFCLK,
    /**< PMHAL_PRCM_MOD_I2C2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_PER1
    PMHAL_PRCM_CLK_L4PER_L3_GICLK,
    /**< PMHAL_PRCM_MOD_L4_PER1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_PER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCC6
    PMHAL_PRCM_CLK_L4PER_L4_GICLK,
    /**< PMHAL_PRCM_MOD_DCC6 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCC6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCC7
    PMHAL_PRCM_CLK_L4PER_L4_GICLK,
    /**< PMHAL_PRCM_MOD_DCC7 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCC7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
    PMHAL_PRCM_CLK_TIMER2_GFCLK,
    /**< PMHAL_PRCM_MOD_TIMER2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
    PMHAL_PRCM_CLK_TIMER3_GFCLK,
    /**< PMHAL_PRCM_MOD_TIMER3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
    PMHAL_PRCM_CLK_TIMER4_GFCLK,
    /**< PMHAL_PRCM_MOD_TIMER4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCC5
    PMHAL_PRCM_CLK_L4PER_L4_GICLK,
    /**< PMHAL_PRCM_MOD_DCC5 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCC5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    PMHAL_PRCM_CLK_L4PER_L3_GICLK,
    /**< PMHAL_PRCM_MOD_ELM */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ESM
    PMHAL_PRCM_CLK_L4PER_L3_GICLK,
    /**< PMHAL_PRCM_MOD_ESM */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ESM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCSPI1
    PMHAL_PRCM_CLK_PER_48M_GFCLK,
    /**< PMHAL_PRCM_MOD_MCSPI1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCSPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCSPI2
    PMHAL_PRCM_CLK_PER_48M_GFCLK,
    /**< PMHAL_PRCM_MOD_MCSPI2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCSPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCSPI3
    PMHAL_PRCM_CLK_PER_48M_GFCLK,
    /**< PMHAL_PRCM_MOD_MCSPI3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCSPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCSPI4
    PMHAL_PRCM_CLK_PER_48M_GFCLK,
    /**< PMHAL_PRCM_MOD_MCSPI4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCSPI4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
    PMHAL_PRCM_CLK_UART1_GFCLK,
    /**< PMHAL_PRCM_MOD_UART1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
    PMHAL_PRCM_CLK_UART2_GFCLK,
    /**< PMHAL_PRCM_MOD_UART2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
    PMHAL_PRCM_CLK_UART3_GFCLK,
    /**< PMHAL_PRCM_MOD_UART3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    PMHAL_PRCM_CLK_GPIO_GFCLK,
    /**< PMHAL_PRCM_MOD_GPIO2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    PMHAL_PRCM_CLK_GPIO_GFCLK,
    /**< PMHAL_PRCM_MOD_GPIO3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    PMHAL_PRCM_CLK_GPIO_GFCLK,
    /**< PMHAL_PRCM_MOD_GPIO4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC4
    PMHAL_PRCM_CLK_MMC4_GFCLK,
    /**< PMHAL_PRCM_MOD_MMC4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN2
    PMHAL_PRCM_CLK_DCAN2_SYS_CLK,
    /**< PMHAL_PRCM_MOD_DCAN2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_PER2
    PMHAL_PRCM_CLK_L4PER2_L3_GICLK,
    /**< PMHAL_PRCM_MOD_L4_PER2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_PER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC
    PMHAL_PRCM_CLK_ADC_GFCLK,
    /**< PMHAL_PRCM_MOD_ADC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PWMSS1
    PMHAL_PRCM_CLK_L4PER2_L3_GICLK,
    /**< PMHAL_PRCM_MOD_PWMSS1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_QSPI
    PMHAL_PRCM_CLK_QSPI_GFCLK,
    /**< PMHAL_PRCM_MOD_QSPI */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_PER3
    PMHAL_PRCM_CLK_L4PER3_L3_GICLK,
    /**< PMHAL_PRCM_MOD_L4_PER3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_PER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCC1
    PMHAL_PRCM_CLK_L4PER3_L4_GICLK,
    /**< PMHAL_PRCM_MOD_DCC1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCC2
    PMHAL_PRCM_CLK_L4PER3_L4_GICLK,
    /**< PMHAL_PRCM_MOD_DCC2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCC3
    PMHAL_PRCM_CLK_L4PER3_L4_GICLK,
    /**< PMHAL_PRCM_MOD_DCC3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCC3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCC4
    PMHAL_PRCM_CLK_L4PER3_L4_GICLK,
    /**< PMHAL_PRCM_MOD_DCC4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCC4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VIP1
    PMHAL_PRCM_CLK_VIP1_GCLK,
    /**< PMHAL_PRCM_MOD_VIP1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VIP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ISS
    PMHAL_PRCM_CLK_ISS_GCLK,
    /**< PMHAL_PRCM_MOD_ISS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ISS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUG_LOGIC
    PMHAL_PRCM_CLK_DEBUG_STMEXPT_CLK,
    /**< PMHAL_PRCM_MOD_DEBUG_LOGIC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUG_LOGIC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_COUNTER_32K
    PMHAL_PRCM_CLK_FUNC_32K_CLK,
    /**< PMHAL_PRCM_MOD_COUNTER_32K */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_COUNTER_32K */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CTRL_MODULE_WKUP
    PMHAL_PRCM_CLK_WKUPAON_GICLK,
    /**< PMHAL_PRCM_MOD_CTRL_MODULE_WKUP */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CTRL_MODULE_WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
    PMHAL_PRCM_CLK_DCAN1_SYS_CLK,
    /**< PMHAL_PRCM_MOD_DCAN1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    PMHAL_PRCM_CLK_WKUPAON_SYS_GFCLK,
    /**< PMHAL_PRCM_MOD_GPIO1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_WKUP
    PMHAL_PRCM_CLK_WKUPAON_GICLK,
    /**< PMHAL_PRCM_MOD_L4_WKUP */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTI1
    PMHAL_PRCM_CLK_RTI1_CLK,
    /**< PMHAL_PRCM_MOD_RTI1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTI2
    PMHAL_PRCM_CLK_RTI2_CLK,
    /**< PMHAL_PRCM_MOD_RTI2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTI3
    PMHAL_PRCM_CLK_RTI3_CLK,
    /**< PMHAL_PRCM_MOD_RTI3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTI4
    PMHAL_PRCM_CLK_RTI4_CLK,
    /**< PMHAL_PRCM_MOD_RTI4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTI4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTI5
    PMHAL_PRCM_CLK_RTI5_CLK,
    /**< PMHAL_PRCM_MOD_RTI5 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTI5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
    PMHAL_PRCM_CLK_TIMER1_GFCLK,
    /**< PMHAL_PRCM_MOD_TIMER1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CAMERARX
    PMHAL_PRCM_CLK_PER_96M_GFCLK,
    /**< PMHAL_PRCM_MOD_CAMERARX */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CAMERARX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCAN
    PMHAL_PRCM_CLK_MCAN_CLK,
    /**< PMHAL_PRCM_MOD_MCAN */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCAN */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ATL
    PMHAL_PRCM_CLK_L4PER2_L3_GICLK,
    /**< PMHAL_PRCM_MOD_ATL */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ATL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP2
    PMHAL_PRCM_CLK_MCASP2_AHCLKR,
    /**< PMHAL_PRCM_MOD_MCASP2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP3
    PMHAL_PRCM_CLK_MCASP3_AHCLKR,
    /**< PMHAL_PRCM_MOD_MCASP3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP3 */
};

