/**
 *  @file   board_pll.h
 *
 *  @brief  PLL configuration definitions
 *
 *  ============================================================================
 */
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

#ifndef BOARD_PLL_H
#define BOARD_PLL_H

#ifdef __cplusplus
extern "C"
{
#endif

#define PLLEN_MUX_SWITCH         (4U)
#define PLL_LOCK_TIME_CNT        (2400U)
#define PLL_STABILIZATION_TIME   (2000U)
#define PLL_RESET_TIME_CNT       (200U)

#define CFGCHIP0            *(uint32_t*)(CSL_SYSCFG_0_REGS + 0x17C)
#define CFGCHIP1            *(uint32_t*)(CSL_SYSCFG_0_REGS + 0x180)
#define CFGCHIP2            *(uint32_t*)(CSL_SYSCFG_0_REGS + 0x184)
#define CFGCHIP3            *(uint32_t*)(CSL_SYSCFG_0_REGS + 0x188)
#define CFGCHIP4            *(uint32_t*)(CSL_SYSCFG_0_REGS + 0x18C)

#define hPLL0Cfg     ((CSL_PllcRegs*)CSL_PLLC_CFG_0_REGS)
#define hPLL1Cfg     ((CSL_PllcRegs*)CSL_PLLC_CFG_1_REGS)

#ifdef __cplusplus
}
#endif

#endif  /* BOARD_PLL_H */
