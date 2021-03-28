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

#ifndef EVM_KEYSTONE_PLL_H
#define EVM_KEYSTONE_PLL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_pllc.h>
#include <ti/csl/cslr_bootcfg.h>
#include <ti/csl/hw_types.h>

#include "board_pll.h"

/** \brief PLL controller macros */
#define pllctl_reg(reg)            (&(pllcReg->reg))
#define pllctl_reg_read(reg)       HW_RD_REG32((uint32_t)pllctl_reg(reg))
#define pllctl_reg_write(reg, val) HW_WR_REG32((uint32_t)pllctl_reg(reg), val)

#define pllctl_reg_rmw(reg, mask, val) \
        pllctl_reg_write(reg, \
                (pllctl_reg_read(reg) & ~(mask)) | val)

#define pllctl_reg_setbits(reg, mask) \
        pllctl_reg_rmw(reg, 0, mask)

#define pllctl_reg_clrbits(reg, mask) \
        pllctl_reg_rmw(reg, mask, 0)

#define clrbits32(addr, clear) \
        HW_WR_REG32((addr), HW_RD_REG32(addr) & ~(clear))
#define setbits32(addr, set) \
        HW_WR_REG32((addr), HW_RD_REG32(addr) | (set))
#define clrsetbits32(addr, clear, set) \
        HW_WR_REG32((addr), (HW_RD_REG32(addr) & ~(clear)) | (set))

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         Keystone II PLL controller.
 */
typedef struct
{
	uint32_t reg0;
	uint32_t reg1;
} keystonePllcReg;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         PLL controller.
 */
typedef struct
{
	CSL_PllcType pll;
    /**< PLL controller type */
	uint32_t pll_m;
    /**< PLL multiplier */
	uint32_t pll_d;
    /**< PLL divider */
	uint32_t pll_od;
    /**< PLL output divider */
} pllcConfig;

extern const keystonePllcReg keystonePllcRegs[];
extern const pllcConfig pllcConfigs[];

extern uint32_t Board_getNumPllcConfigs();

#ifdef __cplusplus
}
#endif

#endif  /* EVM_KEYSTONE_PLL_H */
