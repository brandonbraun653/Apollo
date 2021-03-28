/**
 *  \file  soc_platform_pll.c
 *
 * \brief  This file contains the the function to configure PLLs of SoC and OPP.
 *
 *  \copyright Copyright (C) 2018-2019 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "soc_platform_pll.h"

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This function initializes the CORE PLL
 *
 * \param dpllMult       DPLL multiplier factor
 * \param dpllDiv        DPLL divider factor
 * \param dpllPostDivM4  DPLL post-divider factor M4
 * \param dpllPostDivM5  DPLL post-divider factor M5
 * \param dpllPostDivM6  DPLL post-divider factor M6
 */
static void socPlatformPllCoreInit(uint32_t dpllMult,
                                   uint32_t dpllDiv,
                                   uint32_t dpllPostDivM4,
                                   uint32_t dpllPostDivM5,
                                   uint32_t dpllPostDivM6);

/**
 * \brief This function initializes the PER PLL
 *
 * \param dpllMult       DPLL multiplier factor
 * \param dpllDiv        DPLL divider factor
 * \param dpllPostDivM2  DPLL post-divider factor M2
 * \param sigmaDelatDiv  Sigma Delat divider
 */
static void socPlatformPllPerInit(uint32_t dpllMult,
                                  uint32_t dpllDiv,
                                  uint32_t sigmaDelatDiv,
                                  uint32_t dpllPostDivM2);

/**
 * \brief  This function initializes the MPU PLL.
 *
 * \param dpllMult       DPLL multiplier factor
 * \param dpllDiv        DPLL divider factor
 * \param dpllPostDivM2  DPLL post-divider factor M2
 */
static void socPlatformPllMpuInit(uint32_t dpllMult,
                                  uint32_t dpllDiv,
                                  uint32_t dpllPostDivM2);

/**
 * \brief  This function initializes the External Device PLL.
 *
 * \param dpllMult       DPLL multiplier factor
 * \param dpllDiv        DPLL divider factor
 * \param dpllPostDivM2  DPLL post-divider factor M2
 */

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*
 * \brief This function sets up various PLLs
 *
 * \param  Board Id read from the board
 *
 * \return none
 */
void socPlatformPllInit(uint32_t boardId)
{
    uint32_t crystalFreqSel = 0U;
    uint32_t inputClk = 0U;
    uint32_t mpuDpllDiv = 0U;
    uint32_t mpuDpllMult = 0U;
    uint32_t mpuDpllPostDivM2 = 0U;
    uint32_t coreDpllDiv = 0U;
    uint32_t coreDpllMult = 0U;
    uint32_t coreDpllPostDivM4 = 0U;
    uint32_t coreDpllPostDivM5 = 0U;
    uint32_t coreDpllPostDivM6 = 0U;
    uint32_t perDpllDiv = 0U;
    uint32_t perDpllMult = 0U;
    uint32_t perSigmaDelatDiv = 0U;
    uint32_t perDpllPostDivM2 = 0U;

    /* Get input clock frequency. */
    crystalFreqSel = HW_RD_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_STATUS,
        CONTROL_STATUS_SYSBOOT1,
        CONTROL_STATUS_SYSBOOT1_SHIFT);

    switch(crystalFreqSel)
    {
        case 0U:
        {
            inputClk = 19U;
            break;
        }

        case 1U:
        {
            inputClk = 24U;
            break;
        }

        case 2U:
        {
            inputClk = 25U;
            break;
        }

        case 3U:
        {
            inputClk = 26U;
            break;
        }

        default:
        {
            break;
        }
    }

    mpuDpllDiv = 0U;

    /* The input clock for AMIC110 Board is 25MHz
     * The following are the PLL configuration with respect to the
     * 25MHz input clock.
     */
    if(BOARD_AMIC110 == boardId)
    {
        mpuDpllMult = 24U;
        mpuDpllPostDivM2 = 2U;

        coreDpllDiv = 0U;
        coreDpllMult = 40U;
        coreDpllPostDivM4 = 10U;
        coreDpllPostDivM5 = 8U;
        coreDpllPostDivM6 = 4U;

        perDpllDiv = 9U;
        perDpllMult = 384U;
        perSigmaDelatDiv = (((perDpllMult /(perDpllDiv + 1)) * inputClk / 250U) + 1U);
        perDpllPostDivM2 = 5U;
    }
    /* The following are the PLL configuration with respect to
     * 24MHz input clock.
     */
    else
    {
        mpuDpllMult = 25U;
        mpuDpllPostDivM2 = 1U;

        coreDpllDiv = 2U;
        coreDpllMult = 125U;
        coreDpllPostDivM4 = 10U;
        coreDpllPostDivM5 = 8U;
        coreDpllPostDivM6 = 4U;

        perDpllDiv = 9U;
        perDpllMult = 400U;
        perSigmaDelatDiv = (((perDpllMult /(perDpllDiv + 1)) * inputClk / 250U) + 1U);
        perDpllPostDivM2 = 5U;

    }

    /* TODO:  If possible replace with PRCM API or simplify the below
     *  implementation
     */
    socPlatformPllMpuInit(mpuDpllMult, mpuDpllDiv, mpuDpllPostDivM2);
    socPlatformPllCoreInit(coreDpllMult, coreDpllDiv, coreDpllPostDivM4,
    coreDpllPostDivM5, coreDpllPostDivM6);
    socPlatformPllPerInit(perDpllMult, perDpllDiv, perSigmaDelatDiv,
    perDpllPostDivM2);

}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void socPlatformPllCoreInit(uint32_t dpllMult,
                                   uint32_t dpllDiv,
                                   uint32_t dpllPostDivM4,
                                   uint32_t dpllPostDivM5,
                                   uint32_t dpllPostDivM6)
{
    /* Enable the Core PLL */

    /* Put the PLL in bypass mode */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_CORE,
        CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN_DPLL_MN_BYP_MODE);

    /* Wait for DPLL to go in to bypass mode */

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_CORE,
        CM_WKUP_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS,
        CM_WKUP_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS_SHIFT));

    /* Set the multipler and divider values for the PLL */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_CORE,
        CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_MULT,
        CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_MULT_SHIFT,
        dpllMult);
    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_CORE,
        CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_DIV_SHIFT,
        dpllDiv);

    /* Configure the High speed dividers */

    /* Set M4 divider */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M4_DPLL_CORE,
        CM_WKUP_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_DIV,
        CM_WKUP_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_DIV_SHIFT,
        dpllPostDivM4);

    /* Set M5 divider */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M5_DPLL_CORE,
        CM_WKUP_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_DIV,
        CM_WKUP_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_DIV_SHIFT,
        dpllPostDivM5);

    /* Set M6 divider */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M6_DPLL_CORE,
        CM_WKUP_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_DIV,
        CM_WKUP_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_DIV_SHIFT,
        dpllPostDivM6);

    /* Now LOCK the PLL by enabling it */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_CORE,
        CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN);

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_CORE,
                        CM_WKUP_CM_IDLEST_DPLL_CORE_ST_DPLL_CLK,
                        CM_WKUP_CM_IDLEST_DPLL_CORE_ST_DPLL_CLK_SHIFT));
}

static void socPlatformPllPerInit(uint32_t dpllMult,
                                  uint32_t dpllDiv,
                                  uint32_t sigmaDelatDiv,
                                  uint32_t dpllPostDivM2)
{
    /* Put the PLL in bypass mode */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_PER,
        CM_WKUP_CM_CLKMODE_DPLL_PER_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_PER_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_PER_DPLL_EN_DPLL_MN_BYP_MODE);

    /* Wait for DPLL to go in to bypass mode */

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_PER,
        CM_WKUP_CM_IDLEST_DPLL_PER_ST_MN_BYPASS,
        CM_WKUP_CM_IDLEST_DPLL_PER_ST_MN_BYPASS_SHIFT));

    /* Set the multipler and divider values for the PLL */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_PERIPH,
        CM_WKUP_CM_CLKSEL_DPLL_PERIPH_DPLL_MULT,
        CM_WKUP_CM_CLKSEL_DPLL_PERIPH_DPLL_MULT_SHIFT,
        dpllMult);
    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_PERIPH,
        CM_WKUP_CM_CLKSEL_DPLL_PERIPH_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_PERIPH_DPLL_DIV_SHIFT,
        dpllDiv);

    /* Set the CLKOUT2 divider */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M2_DPLL_PER,
        CM_WKUP_CM_DIV_M2_DPLL_PER_DPLL_CLKOUT_DIV,
        CM_WKUP_CM_DIV_M2_DPLL_PER_DPLL_CLKOUT_DIV_SHIFT,
        dpllPostDivM2);
    /* Now LOCK the PLL by enabling it */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_PER,
        CM_WKUP_CM_CLKMODE_DPLL_PER_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_PER_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_PER_DPLL_EN);

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_PER,
        CM_WKUP_CM_IDLEST_DPLL_PER_ST_DPLL_CLK,
        CM_WKUP_CM_IDLEST_DPLL_PER_ST_DPLL_CLK_SHIFT));

}

static void socPlatformPllMpuInit(uint32_t dpllMult,
                                  uint32_t dpllDiv,
                                  uint32_t dpllPostDivM2)
{
    /* Put the PLL in bypass mode */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_MPU,
        CM_WKUP_CM_CLKMODE_DPLL_MPU_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_MPU_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_MPU_DPLL_EN_DPLL_MN_BYP_MODE);

    /* Wait for DPLL to go in to bypass mode */

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_MPU,
        CM_WKUP_CM_IDLEST_DPLL_MPU_ST_MN_BYPASS,
        CM_WKUP_CM_IDLEST_DPLL_MPU_ST_MN_BYPASS_SHIFT));

    /* Set the multiplier and divider values for the PLL */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_MPU,
        CM_WKUP_CM_CLKSEL_DPLL_MPU_DPLL_MULT,
        CM_WKUP_CM_CLKSEL_DPLL_MPU_DPLL_MULT_SHIFT,
        dpllMult);
    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_MPU,
        CM_WKUP_CM_CLKSEL_DPLL_MPU_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_MPU_DPLL_DIV_SHIFT,
        dpllDiv);

    /* Set the CLKOUT2 divider */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M2_DPLL_MPU,
        CM_WKUP_CM_DIV_M2_DPLL_MPU_DPLL_CLKOUT_DIV,
        CM_WKUP_CM_DIV_M2_DPLL_MPU_DPLL_CLKOUT_DIV_SHIFT,
        dpllPostDivM2);


    /* Now LOCK the PLL by enabling it */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_MPU,
        CM_WKUP_CM_CLKMODE_DPLL_MPU_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_MPU_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_MPU_DPLL_EN);

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_MPU,
        CM_WKUP_CM_IDLEST_DPLL_MPU_ST_DPLL_CLK,
        CM_WKUP_CM_IDLEST_DPLL_MPU_ST_DPLL_CLK_SHIFT));
}

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
