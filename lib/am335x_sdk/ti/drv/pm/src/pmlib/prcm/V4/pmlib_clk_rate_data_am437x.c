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
 * \file      pmlib_clk_rate_data_am437x.c
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
#include "hw_types.h"
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
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_PER
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 5
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_PER_400_9_M2_5 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 5U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_PER, M = 400, N = 9
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 5
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_PER_400_9_M2_5 =
{400U, 9U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_PER_400_9_M2_5, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_PER
 *         PMHAL_PRCM_DPLL_POST_DIV_DCO_LDO = 1
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_PER_400_9_DCO_LDO_1 =
{PMHAL_PRCM_DPLL_POST_DIV_DCO_LDO, 1U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_PER, M = 400, N = 9
 *         PMHAL_PRCM_DPLL_POST_DIV_DCO_LDO = 1
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_PER_400_9_DCO_LDO_1 =
{400U, 9U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_PER_400_9_DCO_LDO_1, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_MPU
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_MPU_25_1_M2_1 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 1U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_MPU, M = 25, N = 1
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_MPU_25_1_M2_1 =
{25U, 1U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_MPU_25_1_M2_1, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_MPU
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_MPU_25_0_M2_1 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 1U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_MPU, M = 25, N = 0
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_MPU_25_0_M2_1 =
{25U, 0U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_MPU_25_0_M2_1, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_MPU
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_MPU_30_0_M2_1 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 1U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_MPU, M = 30, N = 0
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_MPU_30_0_M2_1 =
{30U, 0U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_MPU_30_0_M2_1, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_MPU
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_MPU_800_23_M2_1 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 1U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_MPU, M = 800, N = 23
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_MPU_800_23_M2_1 =
{800U, 23U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_MPU_800_23_M2_1, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_MPU
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_MPU_1000_23_M2_1 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 1U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_MPU, M = 1000, N = 23
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_MPU_1000_23_M2_1 =
{1000U, 23U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_MPU_1000_23_M2_1, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DDR
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DDR_50_2_M2_1 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 1U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DDR, M = 50, N = 2
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 1
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_DDR_50_2_M2_1 =
{50U, 2U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_DDR_50_2_M2_1, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DDR
 *         PMHAL_PRCM_DPLL_POST_DIV_M4 = 2
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DDR_50_2_M4_2 =
{PMHAL_PRCM_DPLL_POST_DIV_M4, 2U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DDR, M = 50, N = 2
 *         PMHAL_PRCM_DPLL_POST_DIV_M4 = 2
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_DDR_50_2_M4_2 =
{50U, 2U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_DDR_50_2_M4_2, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_DISP
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 6
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_DISP_50_1_M2_6 =
{PMHAL_PRCM_DPLL_POST_DIV_M2, 6U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_DISP, M = 50, N = 1
 *         PMHAL_PRCM_DPLL_POST_DIV_M2 = 6
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_DISP_50_1_M2_6 =
{50U, 1U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_DISP_50_1_M2_6, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_CORE
 *         PMHAL_PRCM_DPLL_POST_DIV_M4 = 10
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_CORE_125_2_M4_10 =
{PMHAL_PRCM_DPLL_POST_DIV_M4, 10U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_CORE, M = 125, N = 2
 *         PMHAL_PRCM_DPLL_POST_DIV_M4 = 10
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_CORE_125_2_M4_10 =
{125U, 2U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_CORE_125_2_M4_10, 1U};

/**
 * \brief  Post divider Configuration for PMHAL_PRCM_DPLL_CORE
 *         PMHAL_PRCM_DPLL_POST_DIV_M5 = 8
 */
pmhalPrcmPllPostDivValue_t postDiv_PMHAL_PRCM_DPLL_CORE_125_2_M5_8 =
{PMHAL_PRCM_DPLL_POST_DIV_M5, 8U};
/**
 * \brief  DPLL Configuration for PMHAL_PRCM_DPLL_CORE, M = 125, N = 2
 *         PMHAL_PRCM_DPLL_POST_DIV_M5 = 8
 */
pmhalPrcmDpllConfig_t PMHAL_PRCM_DPLL_CORE_125_2_M5_8 =
{125U, 2U, 0U,
 &postDiv_PMHAL_PRCM_DPLL_CORE_125_2_M5_8, 1U};

/* -------------------------------------------------------------------------- */
/*              Mux and Divider Configuration Structures                      */
/* -------------------------------------------------------------------------- */

/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4_CEFUSE_GCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_L4_CEFUSE_GCLK_100000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_100M,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_GFX_GFCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_200000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_GFX_GFCLK_MUX,
     PMHAL_PRCM_DIV_SYSCLK1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_GFX_GFCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_GFX_GFCLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_GFX_GFCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_100000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_GFX_GFCLK_MUX,
     PMHAL_PRCM_DIV_SYSCLK1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_GFX_GFCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_100000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_GFX_GFCLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_GFX_GFCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_192000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_GFX_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_GFX_GFCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_192000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_GFX_GFCLK,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_GFX_GFCLK run
 *         at 96000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_96000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_GFX_GFCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_GFX_GFCLK run
 *         at 96000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_96000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_GFX_GFCLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_GFX_L3_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_GFX_L3_GCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK run
 *         at 125000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK_125000000_divSel[] =
{
    {PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK run
 *         at 200000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_200000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX,
     PMHAL_PRCM_DIV_SYSCLK1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK run
 *         at 250000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_250000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX,
     PMHAL_PRCM_DPLL_CORE}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK run
 *         at 100000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_100000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX,
     PMHAL_PRCM_DPLL_DISP}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_DLL_AGING_GCLK run
 *         at 3000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_DLL_AGING_GCLK_3000000_divSel[] =
{
    {PMHAL_PRCM_DIV_DLL_AGING_GCLK,
     8}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_DLL_AGING_GCLK run
 *         at 1500000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_DLL_AGING_GCLK_1500000_divSel[] =
{
    {PMHAL_PRCM_DIV_DLL_AGING_GCLK,
     16}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_DLL_AGING_GCLK run
 *         at 750000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_DLL_AGING_GCLK_750000_divSel[] =
{
    {PMHAL_PRCM_DIV_DLL_AGING_GCLK,
     32}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_DSS_GCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_DSS_GCLK_100000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_DISP_CLK_MUX,
     PMHAL_PRCM_DPLL_DISP}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_DSS_GCLK run
 *         at 250000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_DSS_GCLK_250000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_DISP_CLK_MUX,
     PMHAL_PRCM_DPLL_CORE}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_DSS_GCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_DSS_GCLK_192000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_DISP_CLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_DSS_L3_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_DSS_L3_GCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_DSS_L4_GCLK_EN run
 *         at 100000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_DSS_L4_GCLK_EN_100000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_100M,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_EMIF_L3_GICLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_EMIF_L3_GICLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_HDQ1W_GCLK run
 *         at 12000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_HDQ1W_GCLK_12000000_divSel[] =
{
    {PMHAL_PRCM_DIV_FUNC_12M_CLK,
     16}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_I2C_FCLK run
 *         at 48000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_I2C_FCLK_48000000_divSel[] =
{
    {PMHAL_PRCM_DIV_UART_CLK,
     4}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_ICSS_IEP_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_ICSS_IEP_GCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_ICSS_OCP_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_ICSS_OCP_GCLK_200000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX,
     PMHAL_PRCM_DIV_SYSCLK1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_ICSS_OCP_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_ICSS_OCP_GCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_ICSS_OCP_GCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_ICSS_OCP_GCLK_100000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX,
     PMHAL_PRCM_DPLL_DISP}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3D2_GCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_L3D2_GCLK_100000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_100M,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3S_GCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_L3S_GCLK_100000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_100M,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_L3_GCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L4LS_GCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_L4LS_GCLK_100000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_100M,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_LCD_GCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_LCD_GCLK_100000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_DISP_CLK_MUX,
     PMHAL_PRCM_DPLL_DISP}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_LCD_GCLK run
 *         at 250000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_LCD_GCLK_250000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_DISP_CLK_MUX,
     PMHAL_PRCM_DPLL_CORE}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_LCD_GCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_LCD_GCLK_192000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_DISP_CLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_LCD_L3_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_LCD_L3_GCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_LCD_L4S_GCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_LCD_L4S_GCLK_100000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_100M,
     2}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MGC_FCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_MGC_FCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MGC_FGCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_MGC_FCLK run
 *         at 192000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_MGC_FCLK_192000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_MGC_FGCLK_MUX,
     PMHAL_PRCM_DPLL_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_MMC_FCLK run
 *         at 96000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_MMC_FCLK_96000000_divSel[] =
{
    {PMHAL_PRCM_DIV_MMC_CLK,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_OCPWP_L3_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_OCPWP_L3_GCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN run
 *         at 100000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN_100000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_100M,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_SPI_GCLK run
 *         at 48000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_SPI_GCLK_48000000_divSel[] =
{
    {PMHAL_PRCM_DIV_UART_CLK,
     4}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER10_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER10_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER10_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER10_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER10_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER10_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER11_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER11_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER11_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER11_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER11_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER11_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER2_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER2_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER2_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER2_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER2_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER2_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER3_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER3_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER3_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER3_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER3_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER3_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER4_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER4_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER4_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER4_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER4_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER4_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER5_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER5_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER5_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER5_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER5_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER5_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER6_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER6_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER6_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER6_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER6_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER6_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER7_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER7_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER7_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER7_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER7_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER7_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER8_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER8_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER8_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER8_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER8_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER8_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER9_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER9_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER9_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER9_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER9_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER9_CLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_UART_GFCLK run
 *         at 48000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_UART_GFCLK_48000000_divSel[] =
{
    {PMHAL_PRCM_DIV_UART_CLK,
     4}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_USIM0_FCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_USIM0_FCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_USIM0_FCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_USIM0_FCLK run
 *         at 40000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_USIM0_FCLK_40000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_USIM0_FCLK_MUX,
     PMHAL_PRCM_DIV_CORE_200M}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_USIM0_FCLK run
 *         at 40000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_USIM0_FCLK_40000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_200M,
     5}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_USIM0_FCLK32 run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_USIM0_FCLK32_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_USIM0_FCLK32_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_RC}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_USIM1_FCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_USIM1_FCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_USIM1_FCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_USIM1_FCLK run
 *         at 40000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_USIM1_FCLK_40000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_USIM1_FCLK_MUX,
     PMHAL_PRCM_DIV_CORE_200M}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_USIM1_FCLK run
 *         at 40000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_USIM1_FCLK_40000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_200M,
     5}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_USIM1_FCLK32 run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_USIM1_FCLK32_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_USIM0_FCLK32_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_RC}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_TAMPER_L4_GCLK run
 *         at 25000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_TAMPER_L4_GCLK_25000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_25M,
     8}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_CLK_24MHZ run
 *         at 24000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_CLK_24MHZ_24000000_divSel[] =
{
    {PMHAL_PRCM_DIV_CLK_24MHZ,
     8}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_GPIO0_GDBCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_GPIO0_GDBCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_RC}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3S_TSC_GCLK run
 *         at 100000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_L3S_TSC_GCLK_100000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1},
    {PMHAL_PRCM_DIV_CORE_100M,
     2}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_L3_AON_GCLK run
 *         at 200000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_L3_AON_GCLK_200000000_divSel[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     1}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_RTC}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER1_GCLK run
 *         at 24000000 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER1_GCLK_24000000_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER1_GCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_SYS_CLKIN}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_TIMER1_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_TIMER1_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_TIMER1_GCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_PER}
};
/**
 * \brief  List of the Dividers and their corresponding
 *         values to make the clock PMHAL_PRCM_CLK_UART0_GFCLK run
 *         at 48000000 Hz.
 */
pmlibClockRateDivConfig_t PMHAL_PRCM_CLK_UART0_GFCLK_48000000_divSel[] =
{
    {PMHAL_PRCM_DIV_UART0_CLK,
     4}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_RTC}
};
/**
 * \brief  List of the Muxes and their corresponding Parent
 *         Select to make the clock PMHAL_PRCM_CLK_WDT1_GCLK run
 *         at 32768 Hz.
 */
pmlibClockRateMuxConfig_t PMHAL_PRCM_CLK_WDT1_GCLK_32768_muxSel[] =
{
    {PMHAL_PRCM_MUX_WDT1_GCLK_MUX,
     PMHAL_PRCM_ROOT_CLK_32K_RC}
};
/* -------------------------------------------------------------------------- */
/*              Frequency Configuration Structures                            */
/* -------------------------------------------------------------------------- */

/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4_CEFUSE_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L4_CEFUSE_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4_CEFUSE_GCLK_100000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4_CEFUSE_GCLK_100000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GFX_GFCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    PMHAL_PRCM_CLK_GFX_GFCLK_200000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_GFCLK_200000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_GFX_GFCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_GFCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GFX_GFCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_100000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    PMHAL_PRCM_CLK_GFX_GFCLK_100000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_GFCLK_100000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_GFX_GFCLK_100000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_GFCLK_100000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GFX_GFCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    PMHAL_PRCM_CLK_GFX_GFCLK_192000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_GFCLK_192000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_GFX_GFCLK_192000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_GFCLK_192000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GFX_GFCLK
 *         for the frequency 96000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GFX_GFCLK_96000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    PMHAL_PRCM_CLK_GFX_GFCLK_96000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_GFCLK_96000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_GFX_GFCLK_96000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_GFCLK_96000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GFX_L3_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GFX_L3_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_GFX_L3_GCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_L3_GCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MPU_CLK
 *         for the frequency 300000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_MPU_CLK_300000000 =
{
    PMHAL_PRCM_DPLL_MPU,
    &PMHAL_PRCM_DPLL_MPU_25_1_M2_1,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MPU_CLK
 *         for the frequency 600000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_MPU_CLK_600000000 =
{
    PMHAL_PRCM_DPLL_MPU,
    &PMHAL_PRCM_DPLL_MPU_25_0_M2_1,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MPU_CLK
 *         for the frequency 720000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_MPU_CLK_720000000 =
{
    PMHAL_PRCM_DPLL_MPU,
    &PMHAL_PRCM_DPLL_MPU_30_0_M2_1,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MPU_CLK
 *         for the frequency 800000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_MPU_CLK_800000000 =
{
    PMHAL_PRCM_DPLL_MPU,
    &PMHAL_PRCM_DPLL_MPU_800_23_M2_1,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MPU_CLK
 *         for the frequency 1000000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_MPU_CLK_1000000000 =
{
    PMHAL_PRCM_DPLL_MPU,
    &PMHAL_PRCM_DPLL_MPU_1000_23_M2_1,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CAN_CLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_CAN_CLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK
 *         for the frequency 125000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK_125000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M5_8,
    NULL,
    0U,
    PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK_125000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK_125000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CPSW_250MHZ_CLK
 *         for the frequency 250000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_CPSW_250MHZ_CLK_250000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M5_8,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_200000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_200000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK
 *         for the frequency 250000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_250000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M5_8,
    PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_250000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_250000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_100000000 =
{
    PMHAL_PRCM_DPLL_DISP,
    &PMHAL_PRCM_DPLL_DISP_50_1_M2_6,
    PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_100000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_100000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DDR_DLL_GCLK
 *         for the frequency 400000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DDR_DLL_GCLK_400000000 =
{
    PMHAL_PRCM_DPLL_DDR,
    &PMHAL_PRCM_DPLL_DDR_50_2_M4_2,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DLL_AGING_GCLK
 *         for the frequency 3000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DLL_AGING_GCLK_3000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    PMHAL_PRCM_CLK_DLL_AGING_GCLK_3000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DLL_AGING_GCLK_3000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DLL_AGING_GCLK
 *         for the frequency 1500000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DLL_AGING_GCLK_1500000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    PMHAL_PRCM_CLK_DLL_AGING_GCLK_1500000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DLL_AGING_GCLK_1500000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DLL_AGING_GCLK
 *         for the frequency 750000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DLL_AGING_GCLK_750000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    PMHAL_PRCM_CLK_DLL_AGING_GCLK_750000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DLL_AGING_GCLK_750000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSS_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DSS_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_DISP,
    &PMHAL_PRCM_DPLL_DISP_50_1_M2_6,
    PMHAL_PRCM_CLK_DSS_GCLK_100000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_GCLK_100000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSS_GCLK
 *         for the frequency 250000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DSS_GCLK_250000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M5_8,
    PMHAL_PRCM_CLK_DSS_GCLK_250000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_GCLK_250000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSS_GCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DSS_GCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    PMHAL_PRCM_CLK_DSS_GCLK_192000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_GCLK_192000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSS_L3_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DSS_L3_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_DSS_L3_GCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_L3_GCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSS_L4_GCLK_EN
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DSS_L4_GCLK_EN_100000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_DSS_L4_GCLK_EN_100000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_L4_GCLK_EN_100000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DSS_SYSCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DSS_SYSCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_EMIF_L3_GICLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_EMIF_L3_GICLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_EMIF_L3_GICLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_EMIF_L3_GICLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_EMIF_PHY_GCLK
 *         for the frequency 400000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_EMIF_PHY_GCLK_400000000 =
{
    PMHAL_PRCM_DPLL_DDR,
    &PMHAL_PRCM_DPLL_DDR_50_2_M2_1,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GPIO_1_GDBCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GPIO_1_GDBCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GPIO_2_GDBCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GPIO_2_GDBCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GPIO_3_GDBCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GPIO_3_GDBCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GPIO_4_GDBCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GPIO_4_GDBCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GPIO_5_GDBCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GPIO_5_GDBCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_HDQ1W_GCLK
 *         for the frequency 12000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_HDQ1W_GCLK_12000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    NULL,
    0U,
    PMHAL_PRCM_CLK_HDQ1W_GCLK_12000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_HDQ1W_GCLK_12000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_I2C_FCLK
 *         for the frequency 48000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_I2C_FCLK_48000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    NULL,
    0U,
    PMHAL_PRCM_CLK_I2C_FCLK_48000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_I2C_FCLK_48000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_ICSS_IEP_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_ICSS_IEP_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_ICSS_IEP_GCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ICSS_IEP_GCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_ICSS_OCP_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_ICSS_OCP_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    PMHAL_PRCM_CLK_ICSS_OCP_GCLK_200000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ICSS_OCP_GCLK_200000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_ICSS_OCP_GCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ICSS_OCP_GCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_ICSS_OCP_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_ICSS_OCP_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_DISP,
    &PMHAL_PRCM_DPLL_DISP_50_1_M2_6,
    PMHAL_PRCM_CLK_ICSS_OCP_GCLK_100000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ICSS_OCP_GCLK_100000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_ICSS_UART_GCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_ICSS_UART_GCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3D2_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L3D2_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3D2_GCLK_100000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3D2_GCLK_100000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3S_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L3S_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3S_GCLK_100000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3S_GCLK_100000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L3_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3_GCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3_GCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4LS_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L4LS_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L4LS_GCLK_100000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4LS_GCLK_100000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_LCD_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_LCD_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_DISP,
    &PMHAL_PRCM_DPLL_DISP_50_1_M2_6,
    PMHAL_PRCM_CLK_LCD_GCLK_100000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_LCD_GCLK_100000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_LCD_GCLK
 *         for the frequency 250000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_LCD_GCLK_250000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M5_8,
    PMHAL_PRCM_CLK_LCD_GCLK_250000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_LCD_GCLK_250000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_LCD_GCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_LCD_GCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    PMHAL_PRCM_CLK_LCD_GCLK_192000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_LCD_GCLK_192000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_LCD_L3_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_LCD_L3_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_LCD_L3_GCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_LCD_L3_GCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_LCD_L4S_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_LCD_L4S_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_LCD_L4S_GCLK_100000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_LCD_L4S_GCLK_100000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MCASP_FCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_MCASP_FCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MGC_FCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_MGC_FCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_MGC_FCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MGC_FCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MGC_FCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_MGC_FCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    PMHAL_PRCM_CLK_MGC_FCLK_192000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MGC_FCLK_192000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_MMC_FCLK
 *         for the frequency 96000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_MMC_FCLK_96000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    NULL,
    0U,
    PMHAL_PRCM_CLK_MMC_FCLK_96000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC_FCLK_96000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_OCPWP_L3_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_OCPWP_L3_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_OCPWP_L3_GCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_OCPWP_L3_GCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN_100000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN_100000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN_100000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_SPI_GCLK
 *         for the frequency 48000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_SPI_GCLK_48000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    NULL,
    0U,
    PMHAL_PRCM_CLK_SPI_GCLK_48000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_SPI_GCLK_48000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER10_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER10_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER10_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER10_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER10_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER10_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER10_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER10_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER11_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER11_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER11_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER11_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER11_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER11_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER11_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER11_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER2_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER2_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER2_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER2_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER2_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER2_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER2_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER2_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER3_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER3_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER3_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER3_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER3_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER3_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER3_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER3_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER4_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER4_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER4_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER4_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER4_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER4_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER4_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER4_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER5_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER5_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER5_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER5_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER5_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER5_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER5_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER5_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER6_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER6_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER6_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER6_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER6_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER6_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER6_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER6_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER7_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER7_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER7_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER7_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER7_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER7_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER7_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER7_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER8_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER8_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER8_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER8_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER8_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER8_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER8_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER8_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER9_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER9_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER9_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER9_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER9_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER9_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER9_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER9_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_UART_GFCLK
 *         for the frequency 48000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_UART_GFCLK_48000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    NULL,
    0U,
    PMHAL_PRCM_CLK_UART_GFCLK_48000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART_GFCLK_48000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_USB_PLL_CLK
 *         for the frequency 960000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_USB_PLL_CLK_960000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_DCO_LDO_1,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_USIM0_FCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_USIM0_FCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_USIM0_FCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM0_FCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_USIM0_FCLK
 *         for the frequency 40000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_USIM0_FCLK_40000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    PMHAL_PRCM_CLK_USIM0_FCLK_40000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM0_FCLK_40000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_USIM0_FCLK_40000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM0_FCLK_40000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_USIM0_FCLK32
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_USIM0_FCLK32_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_USIM0_FCLK32_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM0_FCLK32_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_USIM1_FCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_USIM1_FCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_USIM1_FCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM1_FCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_USIM1_FCLK
 *         for the frequency 40000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_USIM1_FCLK_40000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    PMHAL_PRCM_CLK_USIM1_FCLK_40000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM1_FCLK_40000000_muxSel,
        pmlibClockRateMuxConfig_t),
    PMHAL_PRCM_CLK_USIM1_FCLK_40000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM1_FCLK_40000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_USIM1_FCLK32
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_USIM1_FCLK32_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_USIM1_FCLK32_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM1_FCLK32_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4_RTC_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L4_RTC_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_RTC_32KCLK
 *         for the frequency 32786.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_RTC_32KCLK_32786 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TAMPER_L4_GCLK
 *         for the frequency 25000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TAMPER_L4_GCLK_25000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_TAMPER_L4_GCLK_25000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TAMPER_L4_GCLK_25000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_ADC_FCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_ADC_FCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_CLK_24MHZ
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_CLK_24MHZ_24000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    NULL,
    0U,
    PMHAL_PRCM_CLK_CLK_24MHZ_24000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CLK_24MHZ_24000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DBGSYSCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DBGSYSCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK
 *         for the frequency 192000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK_192000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_DISP,
    &PMHAL_PRCM_DPLL_DISP_50_1_M2_6,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_GPIO0_GDBCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_GPIO0_GDBCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_GPIO0_GDBCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GPIO0_GDBCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3S_TSC_GCLK
 *         for the frequency 100000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L3S_TSC_GCLK_100000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3S_TSC_GCLK_100000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3S_TSC_GCLK_100000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L3_AON_GCLK
 *         for the frequency 200000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L3_AON_GCLK_200000000 =
{
    PMHAL_PRCM_DPLL_CORE,
    &PMHAL_PRCM_DPLL_CORE_125_2_M4_10,
    NULL,
    0U,
    PMHAL_PRCM_CLK_L3_AON_GCLK_200000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3_AON_GCLK_200000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_L4_WKUP_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_L4_WKUP_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_SR_SYSCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_SR_SYSCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    NULL,
    0U,
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER1_GCLK
 *         for the frequency 24000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER1_GCLK_24000000 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER1_GCLK_24000000_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER1_GCLK_24000000_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_TIMER1_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_TIMER1_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_TIMER1_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER1_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_UART0_GFCLK
 *         for the frequency 48000000.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_UART0_GFCLK_48000000 =
{
    PMHAL_PRCM_DPLL_PER,
    &PMHAL_PRCM_DPLL_PER_400_9_M2_5,
    NULL,
    0U,
    PMHAL_PRCM_CLK_UART0_GFCLK_48000000_divSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART0_GFCLK_48000000_divSel,
        pmlibClockRateDivConfig_t)
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/**
 * \brief  Configuration structure for the PMHAL_PRCM_CLK_WDT1_GCLK
 *         for the frequency 32768.
 */
pmlibClockRateFreqConfig_t PMHAL_PRCM_CLK_WDT1_GCLK_32768 =
{
    PMHAL_PRCM_DPLL_COUNT,
    NULL,
    PMHAL_PRCM_CLK_WDT1_GCLK_32768_muxSel,
    PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_WDT1_GCLK_32768_muxSel,
        pmlibClockRateMuxConfig_t),
    NULL,
    0U
};
/* -------------------------------------------------------------------------- */
/*              Frequency List for the different Clocks                       */
/* -------------------------------------------------------------------------- */

/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4_CEFUSE_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L4_CEFUSE_GCLK_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_L4_CEFUSE_GCLK_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GFX_GFCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_GFX_GFCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_GFX_GFCLK_200000000},
    {100000000U, &PMHAL_PRCM_CLK_GFX_GFCLK_100000000},
    {192000000U, &PMHAL_PRCM_CLK_GFX_GFCLK_192000000},
    {96000000U, &PMHAL_PRCM_CLK_GFX_GFCLK_96000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GFX_L3_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_GFX_L3_GCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_GFX_L3_GCLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MPU_CLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_MPU_CLK_freqList[] =
{
    {300000000U, &PMHAL_PRCM_CLK_MPU_CLK_300000000},
    {600000000U, &PMHAL_PRCM_CLK_MPU_CLK_600000000},
    {720000000U, &PMHAL_PRCM_CLK_MPU_CLK_720000000},
    {800000000U, &PMHAL_PRCM_CLK_MPU_CLK_800000000},
    {1000000000U, &PMHAL_PRCM_CLK_MPU_CLK_1000000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_CAN_CLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_CAN_CLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_CAN_CLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK_freqList[] =
{
    {125000000U, &PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK_125000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_CPSW_250MHZ_CLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_CPSW_250MHZ_CLK_freqList[] =
{
    {250000000U, &PMHAL_PRCM_CLK_CPSW_250MHZ_CLK_250000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_200000000},
    {250000000U, &PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_250000000},
    {100000000U, &PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DDR_DLL_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DDR_DLL_GCLK_freqList[] =
{
    {400000000U, &PMHAL_PRCM_CLK_DDR_DLL_GCLK_400000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DLL_AGING_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DLL_AGING_GCLK_freqList[] =
{
    {3000000U, &PMHAL_PRCM_CLK_DLL_AGING_GCLK_3000000},
    {1500000U, &PMHAL_PRCM_CLK_DLL_AGING_GCLK_1500000},
    {750000U, &PMHAL_PRCM_CLK_DLL_AGING_GCLK_750000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DSS_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DSS_GCLK_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_DSS_GCLK_100000000},
    {250000000U, &PMHAL_PRCM_CLK_DSS_GCLK_250000000},
    {192000000U, &PMHAL_PRCM_CLK_DSS_GCLK_192000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DSS_L3_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DSS_L3_GCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_DSS_L3_GCLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DSS_L4_GCLK_EN.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DSS_L4_GCLK_EN_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_DSS_L4_GCLK_EN_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DSS_SYSCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DSS_SYSCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_DSS_SYSCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_EMIF_L3_GICLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_EMIF_L3_GICLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_EMIF_L3_GICLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_EMIF_PHY_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_EMIF_PHY_GCLK_freqList[] =
{
    {400000000U, &PMHAL_PRCM_CLK_EMIF_PHY_GCLK_400000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GPIO_1_GDBCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_GPIO_1_GDBCLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_GPIO_1_GDBCLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GPIO_2_GDBCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_GPIO_2_GDBCLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_GPIO_2_GDBCLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GPIO_3_GDBCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_GPIO_3_GDBCLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_GPIO_3_GDBCLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GPIO_4_GDBCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_GPIO_4_GDBCLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_GPIO_4_GDBCLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GPIO_5_GDBCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_GPIO_5_GDBCLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_GPIO_5_GDBCLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_HDQ1W_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_HDQ1W_GCLK_freqList[] =
{
    {12000000U, &PMHAL_PRCM_CLK_HDQ1W_GCLK_12000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_I2C_FCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_I2C_FCLK_freqList[] =
{
    {48000000U, &PMHAL_PRCM_CLK_I2C_FCLK_48000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_ICSS_IEP_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_ICSS_IEP_GCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_ICSS_IEP_GCLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_ICSS_OCP_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_ICSS_OCP_GCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_ICSS_OCP_GCLK_200000000},
    {100000000U, &PMHAL_PRCM_CLK_ICSS_OCP_GCLK_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_ICSS_UART_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_ICSS_UART_GCLK_freqList[] =
{
    {192000000U, &PMHAL_PRCM_CLK_ICSS_UART_GCLK_192000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3D2_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L3D2_GCLK_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_L3D2_GCLK_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3S_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L3S_GCLK_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_L3S_GCLK_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L3_GCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_L3_GCLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4LS_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L4LS_GCLK_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_L4LS_GCLK_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_LCD_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_LCD_GCLK_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_LCD_GCLK_100000000},
    {250000000U, &PMHAL_PRCM_CLK_LCD_GCLK_250000000},
    {192000000U, &PMHAL_PRCM_CLK_LCD_GCLK_192000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_LCD_L3_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_LCD_L3_GCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_LCD_L3_GCLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_LCD_L4S_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_LCD_L4S_GCLK_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_LCD_L4S_GCLK_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MCASP_FCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_MCASP_FCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_MCASP_FCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MGC_FCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_MGC_FCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_MGC_FCLK_24000000},
    {192000000U, &PMHAL_PRCM_CLK_MGC_FCLK_192000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_MMC_FCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_MMC_FCLK_freqList[] =
{
    {96000000U, &PMHAL_PRCM_CLK_MMC_FCLK_96000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_OCPWP_L3_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_OCPWP_L3_GCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_OCPWP_L3_GCLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_SPI_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_SPI_GCLK_freqList[] =
{
    {48000000U, &PMHAL_PRCM_CLK_SPI_GCLK_48000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER10_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER10_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER10_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER10_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER11_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER11_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER11_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER11_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER2_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER2_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER2_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER2_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER3_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER3_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER3_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER3_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER4_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER4_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER4_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER4_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER5_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER5_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER5_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER5_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER6_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER6_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER6_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER6_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER7_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER7_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER7_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER7_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER8_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER8_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER8_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER8_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER9_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER9_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER9_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER9_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_UART_GFCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_UART_GFCLK_freqList[] =
{
    {48000000U, &PMHAL_PRCM_CLK_UART_GFCLK_48000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_USB_PLL_CLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_USB_PLL_CLK_freqList[] =
{
    {960000000U, &PMHAL_PRCM_CLK_USB_PLL_CLK_960000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_USIM0_FCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_USIM0_FCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_USIM0_FCLK_24000000},
    {40000000U, &PMHAL_PRCM_CLK_USIM0_FCLK_40000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_USIM0_FCLK32.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_USIM0_FCLK32_freqList[] =
{
    {32768U, &PMHAL_PRCM_CLK_USIM0_FCLK32_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_USIM1_FCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_USIM1_FCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_USIM1_FCLK_24000000},
    {40000000U, &PMHAL_PRCM_CLK_USIM1_FCLK_40000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_USIM1_FCLK32.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_USIM1_FCLK32_freqList[] =
{
    {32768U, &PMHAL_PRCM_CLK_USIM1_FCLK32_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4_RTC_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L4_RTC_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_L4_RTC_GCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_RTC_32KCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_RTC_32KCLK_freqList[] =
{
    {32786U, &PMHAL_PRCM_CLK_RTC_32KCLK_32786}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TAMPER_L4_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TAMPER_L4_GCLK_freqList[] =
{
    {25000000U, &PMHAL_PRCM_CLK_TAMPER_L4_GCLK_25000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_ADC_FCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_ADC_FCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_ADC_FCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_CLK_24MHZ.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_CLK_24MHZ_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_CLK_24MHZ_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DBGSYSCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DBGSYSCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_DBGSYSCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK_freqList[] =
{
    {192000000U, &PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK_192000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_GPIO0_GDBCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_GPIO0_GDBCLK_freqList[] =
{
    {32768U, &PMHAL_PRCM_CLK_GPIO0_GDBCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3S_TSC_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L3S_TSC_GCLK_freqList[] =
{
    {100000000U, &PMHAL_PRCM_CLK_L3S_TSC_GCLK_100000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L3_AON_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L3_AON_GCLK_freqList[] =
{
    {200000000U, &PMHAL_PRCM_CLK_L3_AON_GCLK_200000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_L4_WKUP_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_L4_WKUP_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_L4_WKUP_GCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_SR_SYSCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_SR_SYSCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_SR_SYSCLK_24000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK_freqList[] =
{
    {32768U, &PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_TIMER1_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_TIMER1_GCLK_freqList[] =
{
    {24000000U, &PMHAL_PRCM_CLK_TIMER1_GCLK_24000000},
    {32768U, &PMHAL_PRCM_CLK_TIMER1_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_UART0_GFCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_UART0_GFCLK_freqList[] =
{
    {48000000U, &PMHAL_PRCM_CLK_UART0_GFCLK_48000000}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK_freqList[] =
{
    {32768U, &PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK_32768}
};
/**
 * \brief  List of the frequencies and pointer to configuration
 *         structures for the clock PMHAL_PRCM_CLK_WDT1_GCLK.
 */
pmlibClockRateFreqList_t PMHAL_PRCM_CLK_WDT1_GCLK_freqList[] =
{
    {32768U, &PMHAL_PRCM_CLK_WDT1_GCLK_32768}
};
/* -------------------------------------------------------------------------- */
/*              Clock ID to Frequency List Array                              */
/* -------------------------------------------------------------------------- */

/**
 * \brief  Array containing the frequency list for all the clocks
 *         in the device.
 */
pmlibClockRateAllFreqList_t  pmlibClockRateAllClockFreq [] =
{
    {PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK */
    {PMHAL_PRCM_CLK_L4_CEFUSE_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4_CEFUSE_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4_CEFUSE_GCLK */
    {PMHAL_PRCM_CLK_GFX_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_GFCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GFX_GFCLK */
    {PMHAL_PRCM_CLK_GFX_L3_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GFX_L3_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GFX_L3_GCLK */
    {PMHAL_PRCM_CLK_MPU_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MPU_CLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MPU_CLK */
    {PMHAL_PRCM_CLK_CAN_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CAN_CLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_CAN_CLK */
    {PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK */
    {PMHAL_PRCM_CLK_CPSW_250MHZ_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CPSW_250MHZ_CLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_CPSW_250MHZ_CLK */
    {NULL, 0U},
    /**< PMHAL_PRCM_CLK_CPSW_50MHZ_CLK */
    {NULL, 0U},
    /**< PMHAL_PRCM_CLK_CPSW_5MHZ_CLK */
    {PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK */
    {PMHAL_PRCM_CLK_DDR_DLL_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DDR_DLL_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DDR_DLL_GCLK */
    {PMHAL_PRCM_CLK_DLL_AGING_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DLL_AGING_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DLL_AGING_GCLK */
    {PMHAL_PRCM_CLK_DSS_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DSS_GCLK */
    {PMHAL_PRCM_CLK_DSS_L3_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_L3_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DSS_L3_GCLK */
    {PMHAL_PRCM_CLK_DSS_L4_GCLK_EN_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_L4_GCLK_EN_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DSS_L4_GCLK_EN */
    {PMHAL_PRCM_CLK_DSS_SYSCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DSS_SYSCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DSS_SYSCLK */
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
    {PMHAL_PRCM_CLK_GPIO_1_GDBCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GPIO_1_GDBCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GPIO_1_GDBCLK */
    {PMHAL_PRCM_CLK_GPIO_2_GDBCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GPIO_2_GDBCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GPIO_2_GDBCLK */
    {PMHAL_PRCM_CLK_GPIO_3_GDBCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GPIO_3_GDBCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GPIO_3_GDBCLK */
    {PMHAL_PRCM_CLK_GPIO_4_GDBCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GPIO_4_GDBCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GPIO_4_GDBCLK */
    {PMHAL_PRCM_CLK_GPIO_5_GDBCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GPIO_5_GDBCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GPIO_5_GDBCLK */
    {PMHAL_PRCM_CLK_HDQ1W_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_HDQ1W_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_HDQ1W_GCLK */
    {PMHAL_PRCM_CLK_I2C_FCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_I2C_FCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_I2C_FCLK */
    {PMHAL_PRCM_CLK_ICSS_IEP_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ICSS_IEP_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_ICSS_IEP_GCLK */
    {PMHAL_PRCM_CLK_ICSS_OCP_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ICSS_OCP_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_ICSS_OCP_GCLK */
    {PMHAL_PRCM_CLK_ICSS_UART_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ICSS_UART_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_ICSS_UART_GCLK */
    {PMHAL_PRCM_CLK_L3D2_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3D2_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3D2_GCLK */
    {PMHAL_PRCM_CLK_L3S_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3S_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3S_GCLK */
    {PMHAL_PRCM_CLK_L3_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3_GCLK */
    {PMHAL_PRCM_CLK_L4LS_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4LS_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4LS_GCLK */
    {PMHAL_PRCM_CLK_LCD_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_LCD_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_LCD_GCLK */
    {PMHAL_PRCM_CLK_LCD_L3_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_LCD_L3_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_LCD_L3_GCLK */
    {PMHAL_PRCM_CLK_LCD_L4S_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_LCD_L4S_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_LCD_L4S_GCLK */
    {PMHAL_PRCM_CLK_MCASP_FCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MCASP_FCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MCASP_FCLK */
    {PMHAL_PRCM_CLK_MGC_FCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MGC_FCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MGC_FCLK */
    {PMHAL_PRCM_CLK_MMC_FCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_MMC_FCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_MMC_FCLK */
    {PMHAL_PRCM_CLK_OCPWP_L3_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_OCPWP_L3_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_OCPWP_L3_GCLK */
    {PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN */
    {PMHAL_PRCM_CLK_SPI_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_SPI_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_SPI_GCLK */
    {PMHAL_PRCM_CLK_TIMER10_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER10_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER10_GCLK */
    {PMHAL_PRCM_CLK_TIMER11_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER11_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER11_GCLK */
    {PMHAL_PRCM_CLK_TIMER2_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER2_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER2_GCLK */
    {PMHAL_PRCM_CLK_TIMER3_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER3_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER3_GCLK */
    {PMHAL_PRCM_CLK_TIMER4_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER4_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER4_GCLK */
    {PMHAL_PRCM_CLK_TIMER5_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER5_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER5_GCLK */
    {PMHAL_PRCM_CLK_TIMER6_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER6_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER6_GCLK */
    {PMHAL_PRCM_CLK_TIMER7_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER7_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER7_GCLK */
    {PMHAL_PRCM_CLK_TIMER8_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER8_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER8_GCLK */
    {PMHAL_PRCM_CLK_TIMER9_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER9_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER9_GCLK */
    {PMHAL_PRCM_CLK_UART_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART_GFCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_UART_GFCLK */
    {PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK */
    {PMHAL_PRCM_CLK_USB_PLL_CLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USB_PLL_CLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_USB_PLL_CLK */
    {PMHAL_PRCM_CLK_USIM0_FCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM0_FCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_USIM0_FCLK */
    {PMHAL_PRCM_CLK_USIM0_FCLK32_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM0_FCLK32_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_USIM0_FCLK32 */
    {PMHAL_PRCM_CLK_USIM1_FCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM1_FCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_USIM1_FCLK */
    {PMHAL_PRCM_CLK_USIM1_FCLK32_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USIM1_FCLK32_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_USIM1_FCLK32 */
    {PMHAL_PRCM_CLK_L4_RTC_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4_RTC_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4_RTC_GCLK */
    {PMHAL_PRCM_CLK_RTC_32KCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_RTC_32KCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_RTC_32KCLK */
    {PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK */
    {PMHAL_PRCM_CLK_TAMPER_L4_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TAMPER_L4_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TAMPER_L4_GCLK */
    {PMHAL_PRCM_CLK_ADC_FCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_ADC_FCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_ADC_FCLK */
    {PMHAL_PRCM_CLK_CLK_24MHZ_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_CLK_24MHZ_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_CLK_24MHZ */
    {PMHAL_PRCM_CLK_DBGSYSCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DBGSYSCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DBGSYSCLK */
    {PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK */
    {PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK */
    {PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK */
    {PMHAL_PRCM_CLK_GPIO0_GDBCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_GPIO0_GDBCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_GPIO0_GDBCLK */
    {NULL, 0U},
    /**< PMHAL_PRCM_CLK_I2C0_GFCLK */
    {PMHAL_PRCM_CLK_L3S_TSC_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3S_TSC_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3S_TSC_GCLK */
    {PMHAL_PRCM_CLK_L3_AON_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L3_AON_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L3_AON_GCLK */
    {PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK */
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_L4_WKUP_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_L4_WKUP_GCLK */
    {PMHAL_PRCM_CLK_SR_SYSCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_SR_SYSCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_SR_SYSCLK */
    {PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK */
    {PMHAL_PRCM_CLK_TIMER1_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_TIMER1_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_TIMER1_GCLK */
    {PMHAL_PRCM_CLK_UART0_GFCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_UART0_GFCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_UART0_GFCLK */
    {PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK */
    {PMHAL_PRCM_CLK_WDT1_GCLK_freqList,
     PM_UTIL_VSIZE_TYPE(
        PMHAL_PRCM_CLK_WDT1_GCLK_freqList,
        pmlibClockRateFreqList_t)},
    /**< PMHAL_PRCM_CLK_WDT1_GCLK */
};

/* -------------------------------------------------------------------------- */
/*              Generic Clock ID List                                         */
/* -------------------------------------------------------------------------- */
/**
 * \brief  Array containing the mapping for which clock of the module can
 *         be referred to by PMHAL_PRCM_CLK_GENERIC in the Set and Get API.
 */
pmhalPrcmClockId_t gModuleGenericClkList[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_AES0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
    PMHAL_PRCM_CLK_CPSW_250MHZ_CLK,
    /**< PMHAL_PRCM_MOD_CPGMAC0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_CRYPTODMA */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
    PMHAL_PRCM_CLK_CAN_CLK,
    /**< PMHAL_PRCM_MOD_DCAN0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
    PMHAL_PRCM_CLK_CAN_CLK,
    /**< PMHAL_PRCM_MOD_DCAN1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DDRPHY
    PMHAL_PRCM_CLK_EMIF_PHY_GCLK,
    /**< PMHAL_PRCM_MOD_DDRPHY */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_DES */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL
    PMHAL_PRCM_CLK_DDR_DLL_GCLK,
    /**< PMHAL_PRCM_MOD_DLL */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING
    PMHAL_PRCM_CLK_DLL_AGING_GCLK,
    /**< PMHAL_PRCM_MOD_DLL_AGING */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSS
    PMHAL_PRCM_CLK_DSS_GCLK,
    /**< PMHAL_PRCM_MOD_DSS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_ELM */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
    PMHAL_PRCM_CLK_EMIF_L3_GICLK,
    /**< PMHAL_PRCM_MOD_EMIF */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_EMIF_FW */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_EPWMSS0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_EPWMSS1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_EPWMSS2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_EPWMSS3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_EPWMSS4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_EPWMSS5 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ERMC
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_ERMC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_GPIO1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_GPIO2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_GPIO3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_GPIO4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_GPIO5 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    PMHAL_PRCM_CLK_L3S_GCLK,
    /**< PMHAL_PRCM_MOD_GPMC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_HDQ1W
    PMHAL_PRCM_CLK_HDQ1W_GCLK,
    /**< PMHAL_PRCM_MOD_HDQ1W */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    PMHAL_PRCM_CLK_I2C_FCLK,
    /**< PMHAL_PRCM_MOD_I2C1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
    PMHAL_PRCM_CLK_I2C_FCLK,
    /**< PMHAL_PRCM_MOD_I2C2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
    PMHAL_PRCM_CLK_ICSS_IEP_GCLK,
    /**< PMHAL_PRCM_MOD_ICSS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_IEEE5000
    PMHAL_PRCM_CLK_L3S_GCLK,
    /**< PMHAL_PRCM_MOD_IEEE5000 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_L3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_L3_INSTR */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_L4FW */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4LS
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_L4LS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_L4_HS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
    PMHAL_PRCM_CLK_LCD_GCLK,
    /**< PMHAL_PRCM_MOD_LCDC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD
    PMHAL_PRCM_CLK_MGC_FCLK,
    /**< PMHAL_PRCM_MOD_MAG_CARD */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_MAILBOX0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    PMHAL_PRCM_CLK_MCASP_FCLK,
    /**< PMHAL_PRCM_MOD_MCASP0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    PMHAL_PRCM_CLK_MCASP_FCLK,
    /**< PMHAL_PRCM_MOD_MCASP1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    PMHAL_PRCM_CLK_MMC_FCLK,
    /**< PMHAL_PRCM_MOD_MMC0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    PMHAL_PRCM_CLK_MMC_FCLK,
    /**< PMHAL_PRCM_MOD_MMC1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    PMHAL_PRCM_CLK_MMC_FCLK,
    /**< PMHAL_PRCM_MOD_MMC2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_MSTR_EXPS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_OCMCRAM */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC
    PMHAL_PRCM_CLK_OCPWP_L3_GCLK,
    /**< PMHAL_PRCM_MOD_OCP_WP_NOC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OTFA_EMIF
    PMHAL_PRCM_CLK_EMIF_L3_GICLK,
    /**< PMHAL_PRCM_MOD_OTFA_EMIF */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_PKA */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_QSPI
    PMHAL_PRCM_CLK_SPI_GCLK,
    /**< PMHAL_PRCM_MOD_QSPI */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_RNG */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RNG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SHA0
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_SHA0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_SLV_EXPS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE0
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_SPARE0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE1
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_SPARE1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
    PMHAL_PRCM_CLK_SPI_GCLK,
    /**< PMHAL_PRCM_MOD_SPI0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
    PMHAL_PRCM_CLK_SPI_GCLK,
    /**< PMHAL_PRCM_MOD_SPI1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
    PMHAL_PRCM_CLK_SPI_GCLK,
    /**< PMHAL_PRCM_MOD_SPI2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    PMHAL_PRCM_CLK_SPI_GCLK,
    /**< PMHAL_PRCM_MOD_SPI3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI4
    PMHAL_PRCM_CLK_SPI_GCLK,
    /**< PMHAL_PRCM_MOD_SPI4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_SPINLOCK */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER10
    PMHAL_PRCM_CLK_TIMER10_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER10 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER11
    PMHAL_PRCM_CLK_TIMER11_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER11 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
    PMHAL_PRCM_CLK_TIMER2_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
    PMHAL_PRCM_CLK_TIMER3_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
    PMHAL_PRCM_CLK_TIMER4_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
    PMHAL_PRCM_CLK_TIMER5_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER5 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
    PMHAL_PRCM_CLK_TIMER6_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER6 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
    PMHAL_PRCM_CLK_TIMER7_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER7 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER8
    PMHAL_PRCM_CLK_TIMER8_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER8 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER9
    PMHAL_PRCM_CLK_TIMER9_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER9 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_TPCC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_TPTC0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_TPTC1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_TPTC2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
    PMHAL_PRCM_CLK_UART_GFCLK,
    /**< PMHAL_PRCM_MOD_UART1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
    PMHAL_PRCM_CLK_UART_GFCLK,
    /**< PMHAL_PRCM_MOD_UART2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
    PMHAL_PRCM_CLK_UART_GFCLK,
    /**< PMHAL_PRCM_MOD_UART3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
    PMHAL_PRCM_CLK_UART_GFCLK,
    /**< PMHAL_PRCM_MOD_UART4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
    PMHAL_PRCM_CLK_UART_GFCLK,
    /**< PMHAL_PRCM_MOD_UART5 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_USBPHYOCP2SCP0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1
    PMHAL_PRCM_CLK_L4LS_GCLK,
    /**< PMHAL_PRCM_MOD_USBPHYOCP2SCP1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0
    PMHAL_PRCM_CLK_L3S_GCLK,
    /**< PMHAL_PRCM_MOD_USB_OTG_SS0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1
    PMHAL_PRCM_CLK_L3S_GCLK,
    /**< PMHAL_PRCM_MOD_USB_OTG_SS1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM0
    PMHAL_PRCM_CLK_USIM0_FCLK,
    /**< PMHAL_PRCM_MOD_USIM0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM1
    PMHAL_PRCM_CLK_USIM1_FCLK,
    /**< PMHAL_PRCM_MOD_USIM1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE0
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_VPFE0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE1
    PMHAL_PRCM_CLK_L3_GCLK,
    /**< PMHAL_PRCM_MOD_VPFE1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    PMHAL_PRCM_CLK_GFX_GFCLK,
    /**< PMHAL_PRCM_MOD_GFX */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    PMHAL_PRCM_CLK_ADC_FCLK,
    /**< PMHAL_PRCM_MOD_ADC_TSC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
    PMHAL_PRCM_CLK_CLK_24MHZ,
    /**< PMHAL_PRCM_MOD_CLKDIV32K */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
    PMHAL_PRCM_CLK_L4_WKUP_GCLK,
    /**< PMHAL_PRCM_MOD_CONTROL */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
    PMHAL_PRCM_CLK_DBGSYSCLK,
    /**< PMHAL_PRCM_MOD_DEBUGSS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    PMHAL_PRCM_CLK_L4_WKUP_GCLK,
    /**< PMHAL_PRCM_MOD_GPIO0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
    PMHAL_PRCM_CLK_UART0_GFCLK,
    /**< PMHAL_PRCM_MOD_I2C0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4WKUP
    PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK,
    /**< PMHAL_PRCM_MOD_L4WKUP */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
    PMHAL_PRCM_CLK_SR_SYSCLK,
    /**< PMHAL_PRCM_MOD_SMARTREFLEX0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
    PMHAL_PRCM_CLK_SR_SYSCLK,
    /**< PMHAL_PRCM_MOD_SMARTREFLEX1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER
    PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK,
    /**< PMHAL_PRCM_MOD_SYNCTIMER */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
    PMHAL_PRCM_CLK_TIMER0_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
    PMHAL_PRCM_CLK_TIMER1_GCLK,
    /**< PMHAL_PRCM_MOD_TIMER1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
    PMHAL_PRCM_CLK_UART0_GFCLK,
    /**< PMHAL_PRCM_MOD_UART0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON
    PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK,
    /**< PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON
    PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK,
    /**< PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
    PMHAL_PRCM_CLK_WDT0_GCLK,
    /**< PMHAL_PRCM_MOD_WDT0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
    PMHAL_PRCM_CLK_WDT1_GCLK,
    /**< PMHAL_PRCM_MOD_WDT1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3
    PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK,
    /**< PMHAL_PRCM_MOD_WKUP_M3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
    PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK,
    /**< PMHAL_PRCM_MOD_CEFUSE */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    PMHAL_PRCM_CLK_RTC_32KCLK,
    /**< PMHAL_PRCM_MOD_RTCSS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
    PMHAL_PRCM_CLK_MPU_CLK,
    /**< PMHAL_PRCM_MOD_MPU */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EFUSE
    PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK,
    /**< PMHAL_PRCM_MOD_EFUSE */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPMSS
    PMHAL_PRCM_CLK_TAMPER_L4_GCLK,
    /**< PMHAL_PRCM_MOD_TPMSS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPMSS */
};

