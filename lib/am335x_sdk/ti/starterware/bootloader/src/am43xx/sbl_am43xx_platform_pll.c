/**
 *  \file  sbl_am43xx_platform_ddr.c
 *
 * \brief  This file contains the the function to configure PLLs of SoC and OPP.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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
#include "hw_cm_gfx.h"
#include "hw_cm_mpu.h"
#include "hw_cm_per.h"
#include "hw_cm_rtc.h"
#include "hw_cm_wkup.h"
#include "am437x.h"
#include "hw_control_am43xx.h"
#include "board.h"
#include "sbl_am43xx_platform_pll.h"

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
void SblPlatformPllExtInit(uint32_t dpllMult,
                           uint32_t dpllDiv,
                           uint32_t dpllPostDivM2);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void SBLPlatformPllInit(uint32_t boardId)
{
    uint32_t crystalFreqSel = 0U;
    uint32_t inputClk = 0U;
    uint32_t mpuDpllMult = 0U;
	uint32_t mpuDpllDiv = 0U;
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
	uint32_t extDpllDiv = 0U;
    uint32_t extDpllMult = 0U;
    uint32_t extDpllPostDivM2 = 0U;
	uint32_t dispDpllDiv = 0U;
    uint32_t dispDpllMult = 0U;
    uint32_t dispDpllPostDivM2 = 0U;

    /* Get input clock frequency. */
    crystalFreqSel = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_STS,
        CTRL_STS_SYSBOOT15_14);

    /** Manually verified CONTROL STATUS register and selected 24MHz
     *  for GP,IDK,SK boards. If Input clock is other than 24MHz
     *  configure DDR3 PLL depending on input clock selection.
     **/
    if((BOARD_GPEVM == boardId) || (BOARD_IDKEVM == boardId) ||
          (BOARD_EVMSK == boardId)) /* 24MHz for GP, SK and IDK EVMs */
    {
        crystalFreqSel = 1U;
    }
    else if(BOARD_EPOSEVM == boardId) /* For EPOS EVM 25MHz */
    {
        crystalFreqSel = 2U;
    }
    else if(BOARD_CUSTOM == boardId)
    {
        /* ***CUSTOM BOARD*** Custom board code starts */

        /* Provide OSC clock frequency for CUSTOM board. */

        /* ***CUSTOM BOARD*** Custom board code ends */
    }
    else
    {
        /* It is expected to pass proper value as this doesn't return error. */
    }

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
    mpuDpllDiv = 0U;
    mpuDpllMult = 25;
    mpuDpllPostDivM2 = 1U;

    /*
     * coreDpllMult = coreClk/coreDpllDiv
     * coreDpllPostDivM4 = coreM4Clk/coreClk
     * coreDpllPostDivM5 = coreM5Clk/coreClk
     * coreDpllPostDivM6 = coreM6Clk/coreClk
     */
    coreDpllDiv = 2U;
    coreDpllMult = 125U;
    coreDpllPostDivM4 = 10U;
    coreDpllPostDivM5 = 8U;
    coreDpllPostDivM6 = 4U;

    /*
     * perDpllMult = perClk/perDpllDiv
     * perDpllPostDivM2 = perM2Clk/perClk
     * perSigmaDeltaDiv = (perClk/256U) + 1U
     */
    perDpllDiv = 9U;
    perDpllMult = 400U;
    perSigmaDelatDiv = ((perDpllMult * inputClk) / ((perDpllDiv + 1) * 250)) + 1U;
    perDpllPostDivM2 = 5U;

    /*
     * dispDpllMult = dispClk/dispDpllDiv
     * dispDpllPostDivM2 = dispM2Clk/dispClk
     */
    dispDpllDiv = 1U;
    dispDpllMult = 50U;
    dispDpllPostDivM2 = 6U;

    /*
     * extDpllMult = extClk/extDpllDiv
     * extDpllPostDivM2 = extM2Clk/extClk
     */
    extDpllDiv = 9U;
    extDpllMult = 375U;
    extDpllPostDivM2 = 18U;

    /* TODO: The above values can be obtained from OPP table. */

    /* TODO: Read EVM ID and update accordingly */
    /* EVM dependent pll configuration. */

    /*
     * ddrDpllMult = coreClk/coreDpllDiv
     * ddrDpllPostDivM2 = ddrM2Clk/ddrClk
     * ddrDpllPostDivM4 = ddrM4Clk/ddrClk
     */
    if(BOARD_GPEVM == boardId) /* For GP EVM - 400 MHz */
    {
        ddrDpllDiv = 2U;
        ddrDpllMult = 50U;
        ddrDpllPostDivM2 = 1U;
        ddrDpllPostDivM4 = 2U;
    }
    else if(BOARD_EVMSK == boardId) /* For EVM SK - 400 MHz */
    {
        ddrDpllDiv = 2U;
        ddrDpllMult = 50U;
        ddrDpllPostDivM2 = 1U;
        ddrDpllPostDivM4 = 2U;
    }
    else if(BOARD_IDKEVM == boardId) /* For IDK EVM - 400 MHz */
    {
        ddrDpllDiv = 2U;
        ddrDpllMult = 50U;
        ddrDpllPostDivM2 = 1U;
        ddrDpllPostDivM4 = 2U;
    }
    else if(BOARD_EPOSEVM == boardId) /* For EPOS EVM - 133 MHz */
    {
        ddrDpllDiv = 11U;
        ddrDpllMult = 133U;
        ddrDpllPostDivM2 = 1U;
        ddrDpllPostDivM4 = 4U;
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

    /* TODO:  If possible replace with PRCM API or simplify the below
     *  implementation
     */
    SblPlatformPllMpuInit(mpuDpllMult, mpuDpllDiv, mpuDpllPostDivM2);
    SblPlatformPllCoreInit(coreDpllMult, coreDpllDiv, coreDpllPostDivM4,
    coreDpllPostDivM5, coreDpllPostDivM6);
    SblPlatformPllPerInit(perDpllMult, perDpllDiv, perSigmaDelatDiv,
    perDpllPostDivM2);
    SblPlatformPllDdrInit(ddrDpllMult, ddrDpllDiv, ddrDpllPostDivM2,
    ddrDpllPostDivM4);
    SblPlatformPllExtInit(extDpllMult, extDpllDiv, extDpllPostDivM2);
    /*
     * Display PLL initialization can be skipped for applications
     * not use display.
     */
    SblPlatformPllDisplayInit(dispDpllMult, dispDpllDiv, dispDpllPostDivM2);
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
    uint32_t regVal = 0U;

    /* Enable the Core PLL */

    /* Put the PLL in bypass mode */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_CORE,
    PRCM_CM_CLKMODE_DPLL_CORE_EN, PRCM_CM_CLKMODE_DPLL_CORE_EN_MN_BYP_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_CORE,
        PRCM_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS));

    /* Set the multipler and divider values for the PLL */
    regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_CORE);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_CORE_MULT, dpllMult);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_CORE_DIV, dpllDiv);
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_CORE), regVal);

    /* Configure the High speed dividers */
    /* Set M4 divider */
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_DIV_M4_DPLL_CORE), dpllPostDivM4);

    /* Set M5 divider */
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_DIV_M5_DPLL_CORE), dpllPostDivM5);

    /* Set M6 divider */
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_DIV_M6_DPLL_CORE), dpllPostDivM6);

    /* Now LOCK the PLL by enabling it */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_CORE,
        PRCM_CM_CLKMODE_DPLL_CORE_EN, PRCM_CM_CLKMODE_DPLL_CORE_EN_LOCK_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_CORE,
        PRCM_CM_IDLEST_DPLL_CORE_ST_CLK));
}

void SblPlatformPllDisplayInit(uint32_t dpllMult,
                               uint32_t dpllDiv,
                               uint32_t dpllPostDivM2)
{
    uint32_t regVal = 0U;

    /* Put the PLL in bypass mode */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_DISP,
        PRCM_CM_CLKMODE_DPLL_DISP_EN, PRCM_CM_CLKMODE_DPLL_DISP_EN_MN_BYP_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_DISP,
        PRCM_CM_IDLEST_DPLL_DISP_ST_MN_BYPASS));

    /* Set the multipler and divider values for the PLL */
    regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_DISP);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_DISP_MULT, dpllMult);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_DISP_DIV, dpllDiv);
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_DISP), regVal);

    /* Set the CLKOUT2 divider */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_DISP,
        PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT, dpllPostDivM2);

    /* Now LOCK the PLL by enabling it */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_DISP,
        PRCM_CM_CLKMODE_DPLL_DISP_EN, PRCM_CM_CLKMODE_DPLL_DISP_EN_LOCK_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_DISP,
        PRCM_CM_IDLEST_DPLL_DISP_ST_CLK));
}

void SblPlatformPllPerInit(uint32_t dpllMult,
                           uint32_t dpllDiv,
                           uint32_t sigmaDelatDiv,
                           uint32_t dpllPostDivM2)
{
    uint32_t regVal = 0U;

    /* Put the PLL in bypass mode */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_PER,
        PRCM_CM_CLKMODE_DPLL_PER_EN, PRCM_CM_CLKMODE_DPLL_PER_EN_MN_BYP_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_PER,
        PRCM_CM_IDLEST_DPLL_PER_ST_MN_BYPASS));

    /* Set the multipler and divider values for the PLL */
    regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_PER);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_PER_MULT, dpllMult);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_PER_DIV, dpllDiv);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_PER_SD_DIV, sigmaDelatDiv);
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_PER), regVal);

    /* Set the CLKOUT2 divider */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_PER,
        PRCM_CM_DIV_M2_DPLL_PER_CLKOUT, dpllPostDivM2);

    /* Now LOCK the PLL by enabling it */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_PER,
        PRCM_CM_CLKMODE_DPLL_PER_EN, PRCM_CM_CLKMODE_DPLL_PER_EN_LOCK_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_PER,
        PRCM_CM_IDLEST_DPLL_PER_ST_CLK));
}

void SblPlatformPllDdrInit(uint32_t dpllMult,
                           uint32_t dpllDiv,
                           uint32_t dpllPostDivM2,
                           uint32_t dpllPostDivM4)
{
    uint32_t regVal = 0U;

    /* Put the PLL in bypass mode */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_DDR,
        PRCM_CM_CLKMODE_DPLL_DDR_EN, PRCM_CM_CLKMODE_DPLL_DDR_EN_MN_BYP_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_DDR,
        PRCM_CM_IDLEST_DPLL_DDR_ST_MN_BYPASS));

    /* Set the multipler and divider values for the PLL */
    regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_DDR);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_DDR_MULT, dpllMult);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_DDR_DIV, dpllDiv);
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_DDR), regVal);

    /* Set the CLKOUT2 divider */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_DDR,
        PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT, dpllPostDivM2);

    /* Set M4 divider */
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_DIV_M4_DPLL_DDR), dpllPostDivM4);

    /* Now LOCK the PLL by enabling it */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_DDR,
        PRCM_CM_CLKMODE_DPLL_DDR_EN, PRCM_CM_CLKMODE_DPLL_DDR_EN_LOCK_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_DDR,
        PRCM_CM_IDLEST_DPLL_DDR_ST_CLK));
}

void SblPlatformPllMpuInit(uint32_t dpllMult,
                           uint32_t dpllDiv,
                           uint32_t dpllPostDivM2)
{
    uint32_t regVal = 0U;

    /* Put the PLL in bypass mode */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_MPU,
        PRCM_CM_CLKMODE_DPLL_MPU_EN, PRCM_CM_CLKMODE_DPLL_MPU_EN_MN_BYP_MODE);

    /* Wait for DPLL to go in to bypass mode */
    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_MPU,
        PRCM_CM_IDLEST_DPLL_MPU_ST_MN_BYPASS));

    /* Clear the MULT and DIV field of DPLL_MPU register */
    regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_MPU);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_MPU_MULT, dpllMult);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_MPU_DIV, dpllDiv);
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_MPU), regVal);

    /* Set the CLKOUT2 divider */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_MPU,
        PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT, dpllPostDivM2);

    /* Now LOCK the PLL by enabling it */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_MPU,
        PRCM_CM_CLKMODE_DPLL_MPU_EN, PRCM_CM_CLKMODE_DPLL_MPU_EN_LOCK_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_MPU,
        PRCM_CM_IDLEST_DPLL_MPU_ST_CLK));
}

void SblPlatformPllExtInit(uint32_t dpllMult,
                           uint32_t dpllDiv,
                           uint32_t dpllPostDivM2)
{
    uint32_t regVal = 0U;

    /* Put the PLL in bypass mode */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_EXTDEV,
        PRCM_CM_CLKMODE_DPLL_EXTDEV_EN,
        PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_MN_BYP_MODE);

    /* Wait for DPLL to go in to bypass mode */
    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_EXTDEV,
        PRCM_CM_IDLEST_DPLL_EXTDEV_ST_MN_BYPASS));

    /* Clear the MULT and DIV field of DPLL_MPU register */
    regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_EXTDEV);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_EXTDEV_MULT, dpllMult);
    HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_EXTDEV_DIV, dpllDiv);
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_EXTDEV), regVal);

    /* Set the CLKOUT2 divider */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_EXTDEV,
        PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT, dpllPostDivM2);

    /* Now LOCK the PLL by enabling it */
    HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_EXTDEV,
        PRCM_CM_CLKMODE_DPLL_EXTDEV_EN,
        PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_LOCK_MODE);

    while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_EXTDEV,
        PRCM_CM_IDLEST_DPLL_EXTDEV_ST_CLK));
}

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
