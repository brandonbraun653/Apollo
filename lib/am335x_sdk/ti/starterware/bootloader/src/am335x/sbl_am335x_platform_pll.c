/**
 *  \file  sbl_am335x_platform_pll.c
 *
 * \brief  This file contains the the function to configure PLLs of SoC and OPP.
 *
 *  \copyright Copyright (C) 2013-2017 Texas Instruments Incorporated -
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

#include <types.h>
#include "hw_types.h"
#include "hw_cm_cefuse.h"
#include "hw_cm_device.h"
#include "hw_cm_dpll.h"
#include "hw_cm_mpu.h"
#include "hw_cm_per.h"
#include "hw_cm_rtc.h"
#include "hw_cm_wkup.h"
#include "soc_am335x.h"
#include "hw_control_am335x.h"
#include "board.h"
#include "sbl_am335x_platform_pll.h"
#include "console_utils.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

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
void SblPlatformPllCoreInit(uint32_t dpllMult,
                            uint32_t dpllDiv,
                            uint32_t dpllPostDivM4,
                            uint32_t dpllPostDivM5,
                            uint32_t dpllPostDivM6);

/**
 * \brief This function initializes the DISPLAY PLL
 *
 * \param dpllMult       DPLL multiplier factor
 * \param dpllDiv        DPLL divider factor
 * \param dpllPostDivM2  DPLL post-divider factor M2
 */
void SblPlatformPllDisplayInit(uint32_t dpllMult,
                               uint32_t dpllDiv,
                               uint32_t dpllPostDivM2);

/**
 * \brief This function initializes the PER PLL
 *
 * \param dpllMult       DPLL multiplier factor
 * \param dpllDiv        DPLL divider factor
 * \param dpllPostDivM2  DPLL post-divider factor M2
 * \param sigmaDelatDiv  Sigma Delat divider
 */
void SblPlatformPllPerInit(uint32_t dpllMult,
                           uint32_t dpllDiv,
                           uint32_t sigmaDelatDiv,
                           uint32_t dpllPostDivM2);

/**
 * \brief This function initializes the DDR PLL
 *
 * \param dpllMult       DPLL multiplier factor
 * \param dpllDiv        DPLL divider factor
 * \param dpllPostDivM2  DPLL post-divider factor M2
 * \param dpllPostDivM4  DPLL post-divider factor M4
 */
void SblPlatformPllDdrInit(uint32_t dpllMult,
                           uint32_t dpllDiv,
                           uint32_t dpllPostDivM2,
                           uint32_t dpllPostDivM4);

/**
 * \brief  This function initializes the MPU PLL.
 *
 * \param dpllMult       DPLL multiplier factor
 * \param dpllDiv        DPLL divider factor
 * \param dpllPostDivM2  DPLL post-divider factor M2
 */
void SblPlatformPllMpuInit(uint32_t dpllMult,
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
 * \param  none
 *
 * \return none
 */
void SBLPlatformPllInit(uint32_t boardId)
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
    uint32_t ddrDpllDiv = 0U;
    uint32_t ddrDpllMult = 0U;
    uint32_t ddrDpllPostDivM2 = 0U;
    uint32_t ddrDpllPostDivM4 = 0U;
    uint32_t dispDpllDiv = 0U;
    uint32_t dispDpllMult = 0U;
    uint32_t dispDpllPostDivM2 = 0U;

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

    /* Need to check for clock frequency from board data */

    /* EVM independent pll configuration. */

    /*
     * mpuDpllMult = mpuClk/mpuDpllDiv
     * mpuDpllPostDivM2 = mpuM2Clk/mpuClk
     */

    /*
     * coreDpllMult = coreClk/coreDpllDiv
     * coreDpllPostDivM4 = coreM4Clk/coreClk
     * coreDpllPostDivM5 = coreM5Clk/coreClk
     * coreDpllPostDivM6 = coreM6Clk/coreClk
     */

    /*
     * perDpllMult = perClk/perDpllDiv
     * perDpllPostDivM2 = perM2Clk/perClk
     * perSigmaDeltaDiv = (perClk/256U) + 1U
     */

     /*
      * dispDpllMult = dispClk/dispDpllDiv
      * dispDpllPostDivM2 = dispM2Clk/dispClk
      */

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

        dispDpllDiv = 24U;
        dispDpllMult = 48U;
        dispDpllPostDivM2 = 1U;
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

        dispDpllDiv = 0U;
        dispDpllMult = 2U;
        dispDpllPostDivM2 = 1U;
    }


    /* TODO: The above values can be obtained from OPP table. */

    /* TODO: Read EVM ID and update accordingly */
    /* EVM dependent pll configuration. */

    /*
     * ddrDpllMult = coreClk/coreDpllDiv
     * ddrDpllPostDivM2 = ddrM2Clk/ddrClk
     * ddrDpllPostDivM4 = ddrM4Clk/ddrClk
     */
#ifndef DDRLESS
    if(BOARD_BEAGLEBONE == boardId) /* For BEAGLEBONE - 266 MHz */
    {
        ddrDpllMult = 133U;
        ddrDpllDiv  = 11U;
        ddrDpllPostDivM2 = 1U;
        ddrDpllPostDivM4 = 1U;
    }
    else if(BOARD_BEAGLEBONEBLACK == boardId) /* For BEAGLEBONE BLACK - 400 MHz */
    {
        ddrDpllMult = 50U;
        ddrDpllDiv  = 2U;
        ddrDpllPostDivM2 = 1U;
        ddrDpllPostDivM4 = 1U;
    }
    else if(BOARD_EVMSK == boardId)
    {
        ddrDpllMult = 101U;
        ddrDpllDiv  = 3U;
        ddrDpllPostDivM2 = 2U;
        ddrDpllPostDivM4 = 1U;
    }
    else if(BOARD_GPEVM == boardId)
    {
        ddrDpllMult = 101U;
        ddrDpllDiv  = 3U;
        ddrDpllPostDivM2 = 2U;
        ddrDpllPostDivM4 = 1U;
    }
	else if(BOARD_ICEV1 == boardId)
    {
       ddrDpllMult = 133U;
        ddrDpllDiv  = 11U;
        ddrDpllPostDivM2 = 1U;
        ddrDpllPostDivM4 = 1U;
    }
    else if(BOARD_ICEV2 == boardId)
    {
        ddrDpllMult = 50U;
        ddrDpllDiv  = 2U;
        ddrDpllPostDivM2 = 1U;
        ddrDpllPostDivM4 = 1U;
    }
    else if(BOARD_AMIC110 == boardId)
    {
        ddrDpllMult = 16U;
        ddrDpllDiv  = 0U;
        ddrDpllPostDivM2 = 1U;
        ddrDpllPostDivM4 = 1U;
    }
    else if(BOARD_CUSTOM == boardId)
    {
        /* ***CUSTOM BOARD*** Custom board code starts */

        /* Provide operating frequency of memory device for CUSTOM board. */

        /* ***CUSTOM BOARD*** Custom board code ends */
    }
    else
    {
        /* It is expected to pass proper value as this doesn't return error. */
    }
#endif
    /* TODO:  If possible replace with PRCM API or simplify the below
     *  implementation
     */
    SblPlatformPllMpuInit(mpuDpllMult, mpuDpllDiv, mpuDpllPostDivM2);
    SblPlatformPllCoreInit(coreDpllMult, coreDpllDiv, coreDpllPostDivM4,
    coreDpllPostDivM5, coreDpllPostDivM6);
    SblPlatformPllPerInit(perDpllMult, perDpllDiv, perSigmaDelatDiv,
    perDpllPostDivM2);
#ifndef DDRLESS
    SblPlatformPllDdrInit(ddrDpllMult, ddrDpllDiv, ddrDpllPostDivM2,
    ddrDpllPostDivM4);

	/*
     * Display PLL initialization can be skipped for applications
     * not use display.
     */
    SblPlatformPllDisplayInit(dispDpllMult, dispDpllDiv, dispDpllPostDivM2);
#endif
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

void SblPlatformPllCoreInit(uint32_t dpllMult,
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

void SblPlatformPllDisplayInit(uint32_t dpllMult,
                               uint32_t dpllDiv,
                               uint32_t dpllPostDivM2)
{
    /* Put the PLL in bypass mode */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_DISP,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN_DPLL_MN_BYP_MODE);

     /* Wait for DPLL to go in to bypass mode */

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_DISP,
        CM_WKUP_CM_IDLEST_DPLL_DISP_ST_MN_BYPASS,
        CM_WKUP_CM_IDLEST_DPLL_DISP_ST_MN_BYPASS_SHIFT));

    /* Set the multipler and divider values for the PLL */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_DISP,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_MULT,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_MULT_SHIFT,
        dpllMult);
    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_DISP,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_DIV_SHIFT,
        dpllDiv);

    /* Set the CLKOUT2 divider */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M2_DPLL_DISP,
        CM_WKUP_CM_DIV_M2_DPLL_DISP_DPLL_CLKOUT_DIV,
        CM_WKUP_CM_DIV_M2_DPLL_DISP_DPLL_CLKOUT_DIV_SHIFT,
        dpllPostDivM2);

    /* Now LOCK the PLL by enabling it */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_DISP,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN);

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_DISP,
        CM_WKUP_CM_IDLEST_DPLL_DISP_ST_DPLL_CLK,
        CM_WKUP_CM_IDLEST_DPLL_DISP_ST_DPLL_CLK_SHIFT));
}

void SblPlatformPllPerInit(uint32_t dpllMult,
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

void SblPlatformPllDdrInit(uint32_t dpllMult,
                           uint32_t dpllDiv,
                           uint32_t dpllPostDivM2,
                           uint32_t dpllPostDivM4)
{
    /* Put the PLL in bypass mode */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_DDR,
        CM_WKUP_CM_CLKMODE_DPLL_DDR_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_DDR_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_MPU_DPLL_EN_DPLL_MN_BYP_MODE);

    /* Wait for DPLL to go in to bypass mode */

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_DDR,
        CM_WKUP_CM_IDLEST_DPLL_DDR_ST_MN_BYPASS,
        CM_WKUP_CM_IDLEST_DPLL_DDR_ST_MN_BYPASS_SHIFT));

    /* Set the multipler and divider values for the PLL */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_DDR,
        CM_WKUP_CM_CLKSEL_DPLL_DDR_DPLL_MULT,
        CM_WKUP_CM_CLKSEL_DPLL_DDR_DPLL_MULT_SHIFT,
        dpllMult);
    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_DDR,
        CM_WKUP_CM_CLKSEL_DPLL_DDR_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_DDR_DPLL_DIV_SHIFT,
        dpllDiv);

    /* Set the CLKOUT2 divider */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M2_DPLL_DDR,
        CM_WKUP_CM_DIV_M2_DPLL_DDR_DPLL_CLKOUT_DIV,
        CM_WKUP_CM_DIV_M2_DPLL_DDR_DPLL_CLKOUT_DIV_SHIFT,
        dpllPostDivM2);

    /* Now LOCK the PLL by enabling it */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_DDR,
        CM_WKUP_CM_CLKMODE_DPLL_DDR_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_DDR_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_DDR_DPLL_EN);


    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_DDR,
        CM_WKUP_CM_IDLEST_DPLL_DDR_ST_DPLL_CLK,
        CM_WKUP_CM_IDLEST_DPLL_DDR_ST_DPLL_CLK_SHIFT));
}

void SblPlatformPllMpuInit(uint32_t dpllMult,
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
