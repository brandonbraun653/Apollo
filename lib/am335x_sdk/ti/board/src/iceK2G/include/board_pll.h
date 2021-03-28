/******************************************************************************
 * Copyright (c) 2015-2017, Texas Instruments Incorporated - http://www.ti.com
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

#ifndef EVM_K2H_PLL_H
#define EVM_K2H_PLL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "board_internal.h"

/** \brief Keystone Main/PA/ARM PLL control registers */

/* Main/ARM/PA/DDR3 PLLC0 Register Bits */
#define PLL_BWADJ_LO_SMASK      CSL_BOOTCFG_MAIN_PLL_CTL0_BWADJ_MASK
#define PLL_BWADJ_LO_SHIFT      CSL_BOOTCFG_MAIN_PLL_CTL0_BWADJ_SHIFT
#define PLL_BWADJ_LO_MASK       (PLL_BWADJ_LO_SMASK >> PLL_BWADJ_LO_SHIFT)
#define PLL_CLKOD_SMASK         CSL_BOOTCFG_NSS_PLL_CTL0_CLKOD_MASK
#define PLL_CLKOD_SHIFT         CSL_BOOTCFG_NSS_PLL_CTL0_CLKOD_SHIFT
#define PLL_CLKOD_MASK          (CSL_BOOTCFG_NSS_PLL_CTL0_CLKOD_MASK >> PLL_CLKOD_SHIFT)
#define PLLM_MULT_HI_SMASK      CSL_BOOTCFG_MAIN_PLL_CTL0_PLLM_MASK
#define PLL_MULT_SHIFT          CSL_BOOTCFG_NSS_PLL_CTL0_PLLM_SHIFT
#define PLL_DIV_MASK            CSL_BOOTCFG_MAIN_PLL_CTL0_PLLD_MASK

/* Main/ARM/PA PLLC1 Register Bits */
#define PLL_BWADJ_HI_MASK       CSL_BOOTCFG_MAIN_PLL_CTL1_BWADJ_MASK
#define PLL_PLLRST              CSL_BOOTCFG_NSS_PLL_CTL1_PLLRST_MASK
#define PLLCTL_ENSAT            CSL_BOOTCFG_MAIN_PLL_CTL1_ENSAT_MASK
#define MAIN_ENSAT_OFFSET       CSL_BOOTCFG_MAIN_PLL_CTL1_ENSAT_SHIFT
#define PA_PLL_SEL              CSL_BOOTCFG_NSS_PLL_CTL1_PLLSEL_MASK

/** \brief PLL controller registers */

/* PLLC Register Base address */
#define PLLCTL_REGS_BASE_ADDR   CSL_PLLC_CFG_REGS

/* PLLC PLLCTL Register Bits */
#define PLLCTL_PLLENSRC         CSL_PLLC_PLLCTL_PLLENSRC_MASK
#define PLLCTL_PLLRST           CSL_PLLC_PLLCTL_PLLRST_MASK
#define PLLCTL_PLLPWRDN         CSL_PLLC_PLLCTL_PLLPWRDN_MASK
#define PLLCTL_PLLEN            CSL_PLLC_PLLCTL_PLLEN_MASK

/* PLLC SECCTL Register Bits */
#define PLLCTL_BYPASS           CSL_PLLC_SECCTL_BYPASS_MASK

/* PLLC PLLM Bits */
#define PLLM_MULT_LO_MASK       CSL_PLLC_PLLM_PLLM_MASK

/* PLLC PLLDIV Bits */
#define PLLDIV_ENABLE           CSL_PLLC_PLLDIV1_3_DNEN_MASK
#define PLLM_RATIO_DIV1         (PLLDIV_ENABLE | 0x0)
#define PLLM_RATIO_DIV2         (PLLDIV_ENABLE | 0x0)
#define PLLM_RATIO_DIV3         (PLLDIV_ENABLE | 0x1)
#define PLLM_RATIO_DIV4         (PLLDIV_ENABLE | 0x4)
#define PLLM_RATIO_DIV5         (PLLDIV_ENABLE | 0x17)

/* PLLC PLLCMD Bits */
#define PLLSTAT_GO              CSL_PLLC_PLLCMD_GOSET_MASK

/* Keystone II Chip misc 1 register */
#define KS2_CHIP_MISC1          (CSL_BOOT_CFG_REGS + 0xc7c)
#define KS2_ARM_PLL_EN          (0x00002000u)

Board_STATUS Board_PLLInitExt(void);

#ifdef __cplusplus
}
#endif

#endif  /* EVM_K2H_PLL_H */
