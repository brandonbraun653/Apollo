/******************************************************************************
 * Copyright (c) 2017 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *
 * \file   am65xx_evm_pll.c
 *
 * \brief  PLL configuration structures
 *
 * This file provides the PLL base addressess and configurations 
 * for PLL initialization
 *
 */
 
#include "keystone3_pll.h"

/**
 *
 * \brief  PLL base address 
 *
 * This structure gives the  PLL base addressess 
 * and controller base address for different PLLs
 *
 */
const keystonePllcReg keystonePllcRegs[] = {
    /* MCU PLL0 */
    {CSL_MCU_PLL0_CFG_BASE , CSL_WKUP_PLLCTRL0_BASE +  0x0},
    /* MAIN PLL0 */
    {CSL_PLL0_CFG_BASE ,     CSL_PLLCTRL0_BASE  + 0x0},
    /* ARM0 - PLL6 */
    {CSL_PLL0_CFG_BASE + 0x6000 ,    0x0},
    /* ARM1 - PLL7 */
    {CSL_PLL0_CFG_BASE + 0x7000,     0x0},
    /* DDR  - PLL3 */
    {CSL_PLL0_CFG_BASE + 0x3000,     0x0},
    /* PER0 - PLL1 */
    {CSL_PLL0_CFG_BASE + 0x1000,     0x0},
    /* PER1 - PLL2 */
    {CSL_PLL0_CFG_BASE + 0x2000,     0x0},
    /* CPSW - MCU_PLL1 */
    {CSL_MCU_PLL0_CFG_BASE + 0x1000 ,  0x0},
    /* DSS  - PLL4 */
    {CSL_PLL0_CFG_BASE + 0x4000,      0x0}
    
};

/**
 *
 * \brief  PLL base address
 *
 * This structure gives the  PLL base addressess
 * and controller base address for different PLLs
 *
 */
const keystonePllcReg keystoneM3PllcRegs[] = {
    /* MCU PLL0 */
    {CSL_MCU_PLL0_CFG_BASE + M3_MCU_OFFSET,
     CSL_WKUP_PLLCTRL0_BASE + M3_MCU_OFFSET  +  0x0},
    /* MAIN PLL0 */
    {CSL_PLL0_CFG_BASE  + M3_MAIN_OFFSET,
     CSL_PLLCTRL0_BASE + M3_MAIN_OFFSET + 0x0},
    /* ARM0 - PLL6 */
    {CSL_PLL0_CFG_BASE + M3_MAIN_OFFSET + 0x6000 ,     M3_MAIN_OFFSET + 0x0},
    /* ARM1 - PLL7 */
    {CSL_PLL0_CFG_BASE + M3_MAIN_OFFSET + 0x7000 ,     M3_MAIN_OFFSET + 0x0},
    /* DDR  - PLL3 */
    {CSL_PLL0_CFG_BASE + M3_MAIN_OFFSET + 0x3000,      M3_MAIN_OFFSET + 0x0},
    /* PER0 - PLL1 */
    {CSL_PLL0_CFG_BASE + M3_MAIN_OFFSET  + 0x1000 ,    M3_MAIN_OFFSET + 0x0},
    /* PER1 - PLL2 */
    {CSL_PLL0_CFG_BASE + M3_MAIN_OFFSET + 0x2000 ,     M3_MAIN_OFFSET + 0x0},
    /* CPSW - MCU_PLL1 */
    {CSL_MCU_PLL0_CFG_BASE  + M3_MCU_OFFSET + 0x1000,  M3_MCU_OFFSET + 0x0},
    /* DSS  - PLL4 */
    {CSL_PLL0_CFG_BASE + M3_MAIN_OFFSET + 0x4000,      M3_MAIN_OFFSET + 0x0}
    
};  

/**
 *
 * \brief  PLL configurations 
 *
 * This structure gives the different PLL controller configurations
 *
 */
const pllcConfig pllcConfigs[] = {
    /* CSL_PllcType pll, PllcType, hsdiv_exist, ctrl_exist, m_frac_mult, 
       m_int_mult, sd_div, n_div, m1_div, m2_div, m3_div,hsdiv4, hsdiv3, 
       hsdiv2, hsdiv1, bpdiv_val, od1_val, div1_val */
    {CSL_MCU_PLL,   PLL_TYPEOF_ADPLLM,   1, 1, 0,  480,   0,  9,  0,
        3, 1, 17, 24, 29, 39, 0, 0, 0},  /*400MHz */
    {CSL_MAIN_PLL,  PLL_TYPEOF_ADPLLLJM, 1, 1, 0, 1000,  10,  9,  0,
        25, 0, 24, 9, 49,  4, 0, 0, 0},  /*100MHz */
    {CSL_ARM0_PLL,  PLL_TYPEOF_ADPLLM,   0, 0, 0,  320,   0,  9,  0,
        1, 1,  0,  0,  0,  0, 0, 0, 0},  /*800MHz */
    {CSL_ARM1_PLL,  PLL_TYPEOF_ADPLLM,   0, 0, 0,  320,   0,  9,  0,
        1, 1,  0,  0,  0,  0, 0, 0, 0},  /*800MHz */
#if !(defined(ENABLE_DDR4_1600MHZ))
    {CSL_DDR_PLL,   PLL_TYPEOF_ADPLLLJM, 0, 0, 0,  640,   6,  11,  0,
        4, 0,  0,  0,  0,  0, 0, 0, 0},  /*333MHz */
#else
    {CSL_DDR_PLL,   PLL_TYPEOF_ADPLLLJM, 0, 0, 0,  320,   4,  9,  0,
        2, 0,  0,  0,  0,  0, 0, 0, 0},  /*400MHz */    
#endif
    {CSL_PER0_PLL,  PLL_TYPEOF_ADPLLLJM, 0, 0, 0,  768,   8,  9,  0,
        2, 0,  0,  0,  0,  0, 0, 0, 0},  /*960MHz */
    {CSL_PER1_PLL,  PLL_TYPEOF_ADPLLLJM, 1, 0, 0,  720,   8,  9,  0,
        6, 0,  3,  8, 17,  7, 0, 0, 0},  /*300MHz */
    {CSL_CPSW_PLL,  PLL_TYPEOF_ADPLLM,   1, 0, 0,  400,   0,  9,  0,
        4, 1,  11,  9,  7,  9, 0, 0, 0},  /*250MHz */
    {CSL_DSS_PLL,   PLL_TYPEOF_ADPLLLJM, 0, 0, 0,  995,   4,  24,  0,
        2, 0,  0,  0,  0,  0, 0, 0, 0}   /*499.7MHz */
};

/**
 *
 * \brief  Number of PLLs to configure
 *
 * This function gives the various PLL controller configurations
 *
 * \return  uint32_t - number of PLLs to configure
 */
uint32_t Board_getNumPllcConfigs(void)
{
    return (sizeof(pllcConfigs) / sizeof(pllcConfig));
}
