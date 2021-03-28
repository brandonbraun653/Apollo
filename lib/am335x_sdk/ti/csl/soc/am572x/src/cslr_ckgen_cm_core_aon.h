/********************************************************************
 * Copyright (C) 2013-2016 Texas Instruments Incorporated.
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
#ifndef CSLR_CKGEN_CM_CORE_AON_H
#define CSLR_CKGEN_CM_CORE_AON_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 CM_CLKSEL_CORE_REG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 CM_CLKSEL_ABE_REG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 CM_DLL_CTRL_REG;
    volatile Uint8  RSVD2[12];
    volatile Uint32 CM_CLKMODE_DPLL_CORE_REG;
    volatile Uint32 CM_IDLEST_DPLL_CORE_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_CORE_REG;
    volatile Uint32 CM_CLKSEL_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_M2_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_M3_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_H11_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_H12_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_H13_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_H14_DPLL_CORE_REG;
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_CORE_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_H21_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_H22_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_H23_DPLL_CORE_REG;
    volatile Uint32 CM_DIV_H24_DPLL_CORE_REG;
    volatile Uint32 CM_CLKMODE_DPLL_MPU_REG;
    volatile Uint32 CM_IDLEST_DPLL_MPU_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_MPU_REG;
    volatile Uint32 CM_CLKSEL_DPLL_MPU_REG;
    volatile Uint32 CM_DIV_M2_DPLL_MPU_REG;
    volatile Uint8  RSVD3[20];
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_MPU_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_MPU_REG;
    volatile Uint8  RSVD4[12];
    volatile Uint32 CM_BYPCLK_DPLL_MPU_REG;
    volatile Uint32 CM_CLKMODE_DPLL_IVA_REG;
    volatile Uint32 CM_IDLEST_DPLL_IVA_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_IVA_REG;
    volatile Uint32 CM_CLKSEL_DPLL_IVA_REG;
    volatile Uint32 CM_DIV_M2_DPLL_IVA_REG;
    volatile Uint32 CM_DIV_M3_DPLL_IVA_REG;
    volatile Uint8  RSVD5[16];
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_IVA_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_IVA_REG;
    volatile Uint8  RSVD6[12];
    volatile Uint32 CM_BYPCLK_DPLL_IVA_REG;
    volatile Uint32 CM_CLKMODE_DPLL_ABE_REG;
    volatile Uint32 CM_IDLEST_DPLL_ABE_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_ABE_REG;
    volatile Uint32 CM_CLKSEL_DPLL_ABE_REG;
    volatile Uint32 CM_DIV_M2_DPLL_ABE_REG;
    volatile Uint32 CM_DIV_M3_DPLL_ABE_REG;
    volatile Uint8  RSVD7[16];
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_ABE_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_ABE_REG;
    volatile Uint32 CM_CLKMODE_DPLL_DDR_REG;
    volatile Uint32 CM_IDLEST_DPLL_DDR_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_DDR_REG;
    volatile Uint32 CM_CLKSEL_DPLL_DDR_REG;
    volatile Uint32 CM_DIV_M2_DPLL_DDR_REG;
    volatile Uint32 CM_DIV_M3_DPLL_DDR_REG;
    volatile Uint32 CM_DIV_H11_DPLL_DDR_REG;
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_DDR_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_DDR_REG;
    volatile Uint32 CM_CLKMODE_DPLL_DSP_REG;
    volatile Uint32 CM_IDLEST_DPLL_DSP_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_DSP_REG;
    volatile Uint32 CM_CLKSEL_DPLL_DSP_REG;
    volatile Uint32 CM_DIV_M2_DPLL_DSP_REG;
    volatile Uint32 CM_DIV_M3_DPLL_DSP_REG;
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_DSP_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_DSP_REG;
    volatile Uint32 CM_BYPCLK_DPLL_DSP_REG;
    volatile Uint8  RSVD8[8];
    volatile Uint32 CM_SHADOW_FREQ_CONFIG1_REG;
    volatile Uint32 CM_SHADOW_FREQ_CONFIG2_REG;
    volatile Uint8  RSVD9[8];
    volatile Uint32 CM_DYN_DEP_PRESCAL_REG;
    volatile Uint8  RSVD10[12];
    volatile Uint32 CM_RESTORE_ST_REG;
    volatile Uint32 CM_CLKMODE_DPLL_EVE_REG;
    volatile Uint32 CM_IDLEST_DPLL_EVE_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_EVE_REG;
    volatile Uint32 CM_CLKSEL_DPLL_EVE_REG;
    volatile Uint32 CM_DIV_M2_DPLL_EVE_REG;
    volatile Uint32 CM_DIV_M3_DPLL_EVE_REG;
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_EVE_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_EVE_REG;
    volatile Uint32 CM_BYPCLK_DPLL_EVE_REG;
    volatile Uint32 CM_CLKMODE_DPLL_GMAC_REG;
    volatile Uint32 CM_IDLEST_DPLL_GMAC_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_GMAC_REG;
    volatile Uint32 CM_CLKSEL_DPLL_GMAC_REG;
    volatile Uint32 CM_DIV_M2_DPLL_GMAC_REG;
    volatile Uint32 CM_DIV_M3_DPLL_GMAC_REG;
    volatile Uint32 CM_DIV_H11_DPLL_GMAC_REG;
    volatile Uint32 CM_DIV_H12_DPLL_GMAC_REG;
    volatile Uint32 CM_DIV_H13_DPLL_GMAC_REG;
    volatile Uint32 CM_DIV_H14_DPLL_GMAC_REG;
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_GMAC_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_GMAC_REG;
    volatile Uint32 CM_CLKMODE_DPLL_GPU_REG;
    volatile Uint32 CM_IDLEST_DPLL_GPU_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_GPU_REG;
    volatile Uint32 CM_CLKSEL_DPLL_GPU_REG;
    volatile Uint32 CM_DIV_M2_DPLL_GPU_REG;
    volatile Uint32 CM_DIV_M3_DPLL_GPU_REG;
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_GPU_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_GPU_REG;
} CSL_ckgen_cm_core_aonRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* CORE module clock selection. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG                ((uint32_t)(0x0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG)


/* ABE module clock selection. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG                 ((uint32_t)(0x8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE   (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG)


/* Special register for DLL control */
#define CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG                   ((uint32_t)(0x10U))
/* Below define for backward compatibility */
#define CM_DLL_CTRL     (CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG          ((uint32_t)(0x20U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG           ((uint32_t)(0x24U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG         ((uint32_t)(0x28U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG           ((uint32_t)(0x2CU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG           ((uint32_t)(0x30U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG)


/* This register provides controls over the M3 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG           ((uint32_t)(0x34U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG)


/* This register provides controls over the CLKOUT1 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG          ((uint32_t)(0x38U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG)


/* This register provides controls over the CLKOUT2 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG          ((uint32_t)(0x3CU))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG)


/* This register provides controls over the CLKOUT3 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG          ((uint32_t)(0x40U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG)


/* This register provides controls over the CLKOUT4 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG          ((uint32_t)(0x44U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_CORE_REG   ((uint32_t)(0x48U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_CORE_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG   ((uint32_t)(0x4CU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG)


/* This register provides controls over the CLKOUT1 o/p of the 2nd HSDIVIDER. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG          ((uint32_t)(0x50U))
/* Below define for backward compatibility */
#define CM_DIV_H21_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG)


/* This register provides controls over the CLKOUT2 o/p of the 2nd HSDIVIDER. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG          ((uint32_t)(0x54U))
/* Below define for backward compatibility */
#define CM_DIV_H22_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG)


/* This register provides controls over the CLKOUT3 o/p of the 2nd HSDIVIDER. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG          ((uint32_t)(0x58U))
/* Below define for backward compatibility */
#define CM_DIV_H23_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG)


/* This register provides controls over the CLKOUT4 o/p of the 2nd HSDIVIDER. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG          ((uint32_t)(0x5CU))
/* Below define for backward compatibility */
#define CM_DIV_H24_DPLL_CORE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG           ((uint32_t)(0x60U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG            ((uint32_t)(0x64U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG          ((uint32_t)(0x68U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG            ((uint32_t)(0x6CU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG            ((uint32_t)(0x70U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_MPU  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_MPU_REG    ((uint32_t)(0x88U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_MPU  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_MPU_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG    ((uint32_t)(0x8CU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_MPU  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG)


/* Control MPU PLL BYPASS clock. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG            ((uint32_t)(0x9CU))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_MPU  (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG           ((uint32_t)(0xA0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG            ((uint32_t)(0xA4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG          ((uint32_t)(0xA8U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG            ((uint32_t)(0xACU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG            ((uint32_t)(0xB0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_IVA  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG)


/* This register provides controls over the M3 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG            ((uint32_t)(0xB4U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_IVA  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_IVA_REG    ((uint32_t)(0xC8U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_IVA  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_IVA_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG    ((uint32_t)(0xCCU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_IVA  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG)


/* Control IVA PLL BYPASS clock. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG            ((uint32_t)(0xDCU))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_IVA  (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG           ((uint32_t)(0xE0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG            ((uint32_t)(0xE4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG          ((uint32_t)(0xE8U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG            ((uint32_t)(0xECU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG            ((uint32_t)(0xF0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG)


/* This register provides controls over the M3 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG            ((uint32_t)(0xF4U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_ABE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_ABE_REG    ((uint32_t)(0x108U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_ABE  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_ABE_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG    ((uint32_t)(0x10CU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_ABE  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG           ((uint32_t)(0x110U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG            ((uint32_t)(0x114U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG          ((uint32_t)(0x118U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG            ((uint32_t)(0x11CU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG            ((uint32_t)(0x120U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DDR  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG)


/* This register provides controls over the M3 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG            ((uint32_t)(0x124U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DDR  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG)


/* This register provides controls over the CLKOUT1 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG           ((uint32_t)(0x128U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_DDR  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DDR_REG    ((uint32_t)(0x12CU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_DDR  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DDR_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG    ((uint32_t)(0x130U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DDR  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG           ((uint32_t)(0x134U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG            ((uint32_t)(0x138U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG          ((uint32_t)(0x13CU))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG            ((uint32_t)(0x140U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG            ((uint32_t)(0x144U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DSP  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG)


/* This register provides controls over the M3 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG            ((uint32_t)(0x148U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DSP  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DSP_REG    ((uint32_t)(0x14CU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_DSP  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DSP_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG    ((uint32_t)(0x150U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DSP  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG)


/* Control IVA PLL BYPASS clock. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG            ((uint32_t)(0x154U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_DSP  (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG)


/* Shadow register to program new DPLL configuration affecting EMIF and GPMC
 * (L3 clock) functional frequency during DVFS. The PRCM h/w automatically
 * applies the new configuration after EMIF/GPMC have been put in idle state. */
#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG        ((uint32_t)(0x160U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG)


/* Shadow register to program new DPLL configuration affecting GPMC (L3 clock)
 * functional frequency during DVFS. The PRCM h/w automatically applies the
 * new configuration after EMIF/GPMC have been put in idle state. */
#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG        ((uint32_t)(0x164U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG)


/* Control the time unit of the sliding window for dynamic dependencies
 * (auto-sleep feature). */
#define CSL_CKGEN_CM_CORE_AON_CM_DYN_DEP_PRESCAL_REG            ((uint32_t)(0x170U))
/* Below define for backward compatibility */
#define CM_DYN_DEP_PRESCAL  (CSL_CKGEN_CM_CORE_AON_CM_DYN_DEP_PRESCAL_REG)


/* Automatic restore status. This register is used by the system DMA to write
 * a predefined value at the end of each automatic restore phase. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG                 ((uint32_t)(0x180U))
/* Below define for backward compatibility */
#define CM_RESTORE_ST   (CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG           ((uint32_t)(0x184U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG            ((uint32_t)(0x188U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG          ((uint32_t)(0x18CU))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG            ((uint32_t)(0x190U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG            ((uint32_t)(0x194U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_EVE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG)


/* This register provides controls over the M3 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG            ((uint32_t)(0x198U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_EVE  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_EVE_REG    ((uint32_t)(0x19CU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_EVE  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_EVE_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG    ((uint32_t)(0x1A0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_EVE  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG)


/* Control IVA PLL BYPASS clock. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG            ((uint32_t)(0x1A4U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_EVE  (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG          ((uint32_t)(0x1A8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG           ((uint32_t)(0x1ACU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG         ((uint32_t)(0x1B0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG           ((uint32_t)(0x1B4U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG           ((uint32_t)(0x1B8U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG)


/* This register provides controls over the M3 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG           ((uint32_t)(0x1BCU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG)


/* This register provides controls over the CLKOUT1 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG          ((uint32_t)(0x1C0U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG)


/* This register provides controls over the CLKOUT2 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG          ((uint32_t)(0x1C4U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG)


/* This register provides controls over the CLKOUT3 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG          ((uint32_t)(0x1C8U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG)


/* This register provides controls over the CLKOUT4 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG          ((uint32_t)(0x1CCU))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GMAC_REG   ((uint32_t)(0x1D0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GMAC_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG   ((uint32_t)(0x1D4U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GMAC  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG           ((uint32_t)(0x1D8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG            ((uint32_t)(0x1DCU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG          ((uint32_t)(0x1E0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG            ((uint32_t)(0x1E4U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG            ((uint32_t)(0x1E8U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GPU  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG)


/* This register provides controls over the M3 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG            ((uint32_t)(0x1ECU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GPU  (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GPU_REG    ((uint32_t)(0x1F0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_GPU  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GPU_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG    ((uint32_t)(0x1F4U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GPU  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CM_CLKSEL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_CLKSEL_L3_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_CLKSEL_L3_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3_CORE_CLK_DIV_1  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_CLKSEL_L3_CORE_CLK_DIV_1       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3_CORE_CLK_DIV_1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3_CORE_CLK_DIV_2  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_CLKSEL_L3_CORE_CLK_DIV_2       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3_CORE_CLK_DIV_2)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L4_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_CLKSEL_L4_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L4_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L4_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L4_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_CLKSEL_L4_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L4_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L4_L3_CLK_DIV_1  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_CLKSEL_L4_L3_CLK_DIV_1         (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L4_L3_CLK_DIV_1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L4_L3_CLK_DIV_2  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_CORE_CLKSEL_L4_L3_CLK_DIV_2         (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L4_L3_CLK_DIV_2)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_RESETVAL       ((uint32_t)(0x00000100U))

/* CM_CLKSEL_ABE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_MASK  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLKSEL_OPP_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLKSEL_OPP_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_DIV_1  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLKSEL_OPP_DIV_1                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_DIV_1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_DIV_2  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLKSEL_OPP_DIV_2                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_DIV_2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_DIV_4  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLKSEL_OPP_DIV_4                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_DIV_4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_CLKSEL_OPP_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_CLKSEL_OPP_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_PAD_CLKS_GATE_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PAD_CLKS_GATE_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_PAD_CLKS_GATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_PAD_CLKS_GATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_PAD_CLKS_GATE_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PAD_CLKS_GATE_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_PAD_CLKS_GATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_PAD_CLKS_GATE_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PAD_CLKS_GATE_GATED             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_PAD_CLKS_GATE_GATED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_PAD_CLKS_GATE_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_PAD_CLKS_GATE_ENABLED           (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_PAD_CLKS_GATE_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_SLIMBUS1_CLK_GATE_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_SLIMBUS1_CLK_GATE_MASK          (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_SLIMBUS1_CLK_GATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_SLIMBUS1_CLK_GATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_SLIMBUS1_CLK_GATE_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_SLIMBUS1_CLK_GATE_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_SLIMBUS1_CLK_GATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_SLIMBUS1_CLK_GATE_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_SLIMBUS1_CLK_GATE_GATED         (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_SLIMBUS1_CLK_GATE_GATED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_SLIMBUS1_CLK_GATE_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_ABE_SLIMBUS1_CLK_GATE_ENABLED       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_SLIMBUS1_CLK_GATE_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_ABE_REG_RESETVAL        ((uint32_t)(0x00000000U))

/* CM_DLL_CTRL_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_DLL_OVERRIDE_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DLL_CTRL_DLL_OVERRIDE_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_DLL_OVERRIDE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_DLL_OVERRIDE_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_DLL_OVERRIDE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DLL_CTRL_DLL_OVERRIDE_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_DLL_OVERRIDE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_DLL_OVERRIDE_NO_OVR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DLL_CTRL_DLL_OVERRIDE_NO_OVR               (CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_DLL_OVERRIDE_NO_OVR)

#define CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_DLL_OVERRIDE_OVR  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DLL_CTRL_DLL_OVERRIDE_OVR                  (CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_DLL_OVERRIDE_OVR)


#define CSL_CKGEN_CM_CORE_AON_CM_DLL_CTRL_REG_RESETVAL          ((uint32_t)(0x00000001U))

/* CM_CLKMODE_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_RESERVED         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_RESERVED1        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_RESERVED2        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_RESERVED3        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_RESERVED4        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_EN_DPLL_LOCK_MODE   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_DRIFTGUARD_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_LEVEL_MASK     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_LEVEL_SHIFT    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_REFCLKX2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_REFCLKX4  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_REFCLKX8  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_LPMODE_EN_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_LPMODE_EN_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_LPMODE_EN_DISABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_LPMODE_EN_ENABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_REGM4XEN_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_REGM4XEN_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_REGM4XEN_DISABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_REGM4XEN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_EN_MASK         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_EN_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_EN_DISABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_EN_ENABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_ACK_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_ACK_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_ACK_DISABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_ACK_ENABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_TYPE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_TYPE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_CORE_DPLL_SSC_TYPE_SQUARE     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_CLK_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_CLK_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_CLK_DPLL_LOCKED   (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_MASK         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_TRANSIENT    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_LP_STOP      (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_FR_STOP      (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_RESERVED1    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_RESERVED2    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_LP_BYP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_FR_BYP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_MODE_RESERVED3    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_INIT_MASK         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_INIT_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_CORE_ST_DPLL_INIT_DPLL_INIT    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_MASK     (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_SHIFT    (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_RESERVED1  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE_RESERVED2  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_AUTO_DPLL_MODE_RESERVED2)


#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_DIV_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_DIV_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_DIV_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_BYP_CLKSEL_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_BYP_CLKSEL_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_CLKOUTHIF_CLKSEL_MASK  ((uint32_t)(0x00100000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_CLKOUTHIF_CLKSEL_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_CLKOUTHIF_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_CLKOUTHIF_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_CLKOUTHIF_CLKSEL_SHIFT  ((uint32_t)(20U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_CLKOUTHIF_CLKSEL_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_CLKOUTHIF_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_DCO  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_CLKOUTHIF_CLKSEL_SEL_DCO  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_DCO)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_CLKINPHIF  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_CLKOUTHIF_CLKSEL_SEL_CLKINPHIF  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_CLKINPHIF)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_MULT_MASK            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DPLL_MULT_SHIFT           (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DCC_EN_MASK               (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DCC_EN_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_CORE_DCC_EN_DISABLED           (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DCC_EN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_DIV_M2_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_CORE_DIVHS_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_CORE_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_CORE_DIVHS_RESERVED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_CORE_CLKST_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_CORE_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_CORE_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_CORE_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_M3_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_CORE_DIVHS_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_CORE_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_CORE_DIVHS_RESERVED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_CORE_CLKST_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_CORE_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_CORE_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_CORE_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H11_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_CORE_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_CORE_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_CORE_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_CORE_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_CORE_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_CORE_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_CORE_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H12_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_CORE_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_CORE_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_CORE_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_CORE_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_CORE_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_CORE_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_CORE_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H13_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_CORE_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_CORE_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_CORE_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_CORE_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_CORE_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_CORE_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_CORE_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H14_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_CORE_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_CORE_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_CORE_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_CORE_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_CORE_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_CORE_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_CORE_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_CORE_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_CORE_DELTAMSTEP_MASK   (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_CORE_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_CORE_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_CORE_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_CORE_DELTAMSTEP_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_CORE_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_CORE_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_CORE_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_CORE_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_CORE_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_CORE_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_DIV_H21_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H21_DPLL_CORE_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H21_DPLL_CORE_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H21_DPLL_CORE_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H21_DPLL_CORE_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H21_DPLL_CORE_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H21_DPLL_CORE_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H21_DPLL_CORE_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H21_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H22_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H22_DPLL_CORE_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H22_DPLL_CORE_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H22_DPLL_CORE_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H22_DPLL_CORE_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H22_DPLL_CORE_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H22_DPLL_CORE_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H22_DPLL_CORE_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H23_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H23_DPLL_CORE_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H23_DPLL_CORE_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H23_DPLL_CORE_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H23_DPLL_CORE_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H23_DPLL_CORE_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H23_DPLL_CORE_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H23_DPLL_CORE_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H24_DPLL_CORE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H24_DPLL_CORE_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H24_DPLL_CORE_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H24_DPLL_CORE_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H24_DPLL_CORE_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H24_DPLL_CORE_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H24_DPLL_CORE_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H24_DPLL_CORE_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_CLKMODE_DPLL_MPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_RESERVED          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_RESERVED1         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_RESERVED2         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_RESERVED3         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_RESERVED4         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_EN_DPLL_LOCK_MODE    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_LEVEL_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_LEVEL_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_REFCLKX2   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_REFCLKX4   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_REFCLKX8   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_DRIFTGUARD_EN_MASK   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_LPMODE_EN_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_LPMODE_EN_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_LPMODE_EN_DISABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_LPMODE_EN_ENABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_REGM4XEN_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_REGM4XEN_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_REGM4XEN_DISABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_REGM4XEN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_EN_MASK          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_EN_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_EN_DISABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_EN_ENABLED       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_ACK_MASK         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_ACK_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_ACK_DISABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_ACK_ENABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_TYPE_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_TYPE_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_MPU_DPLL_SSC_TYPE_SQUARE      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_MPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_CLK_MASK           (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_CLK_SHIFT          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_CLK_DPLL_LOCKED    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_TRANSIENT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_LP_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_FR_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_RESERVED1     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_RESERVED2     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_LP_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_FR_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_MODE_RESERVED3     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_INIT_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_INIT_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_MPU_ST_DPLL_INIT_DPLL_INIT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_MPU_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_MPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_MPU_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_MPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DPLL_DIV_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DPLL_DIV_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_DIV_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DPLL_BYP_CLKSEL_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DPLL_BYP_CLKSEL_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DPLL_MULT_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DPLL_MULT_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DCC_EN_MASK                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DCC_EN_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DCC_EN_DISABLED            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_MPU_DCC_EN_ENABLED             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_RESETVAL   ((uint32_t)(0x00800000U))

/* CM_DIV_M2_DPLL_MPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_MPU_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_MPU_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_MPU_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_MPU_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_MPU_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_MPU_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_MPU_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_MPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_MPU_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_MPU_DELTAMSTEP_MASK    (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_MPU_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_MPU_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_MPU_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_MPU_DELTAMSTEP_SHIFT   (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_MPU_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_MPU_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_MPU_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_MPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_MPU_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_MPU_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_MPU_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_MPU_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_MPU_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_BYPCLK_DPLL_MPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_MASK  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_MPU_CLKSEL_MASK                (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_MPU_CLKSEL_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_CORE_X2_CLK_DIV_1  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_MPU_CLKSEL_CORE_X2_CLK_DIV_1   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_CORE_X2_CLK_DIV_1)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_CORE_X2_CLK_DIV_2  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_MPU_CLKSEL_CORE_X2_CLK_DIV_2   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_CORE_X2_CLK_DIV_2)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_CORE_X2_CLK_DIV_4  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_MPU_CLKSEL_CORE_X2_CLK_DIV_4   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_CORE_X2_CLK_DIV_4)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_CORE_X2_CLK_DIV_8  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_MPU_CLKSEL_CORE_X2_CLK_DIV_8   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_CLKSEL_CORE_X2_CLK_DIV_8)


#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_MPU_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_CLKMODE_DPLL_IVA_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_RESERVED          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_RESERVED1         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_RESERVED2         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_RESERVED3         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_RESERVED4         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_EN_DPLL_LOCK_MODE    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_LEVEL_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_LEVEL_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_REFCLKX2   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_REFCLKX4   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_REFCLKX8   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_DRIFTGUARD_EN_MASK   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_LPMODE_EN_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_LPMODE_EN_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_LPMODE_EN_DISABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_LPMODE_EN_ENABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_REGM4XEN_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_REGM4XEN_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_REGM4XEN_DISABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_REGM4XEN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_EN_MASK          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_EN_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_EN_DISABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_EN_ENABLED       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_ACK_MASK         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_ACK_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_ACK_DISABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_ACK_ENABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_TYPE_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_TYPE_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_IVA_DPLL_SSC_TYPE_SQUARE      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_IVA_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_CLK_MASK           (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_CLK_SHIFT          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_CLK_DPLL_LOCKED    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_TRANSIENT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_LP_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_FR_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_RESERVED1     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_RESERVED2     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_LP_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_FR_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_MODE_RESERVED3     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_INIT_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_INIT_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_IVA_ST_DPLL_INIT_DPLL_INIT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_IVA_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_IVA_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_IVA_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_IVA_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_IVA_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA_DPLL_DIV_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA_DPLL_DIV_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_DIV_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA_DPLL_BYP_CLKSEL_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA_DPLL_BYP_CLKSEL_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA_DPLL_MULT_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA_DPLL_MULT_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA_DCC_EN_MASK                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA_DCC_EN_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_IVA_DCC_EN_DISABLED            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DCC_EN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_DIV_M2_DPLL_IVA_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_IVA_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_IVA_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_IVA_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_IVA_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_IVA_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_IVA_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_IVA_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_DIV_M3_DPLL_IVA_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_IVA_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_IVA_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_IVA_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_IVA_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_IVA_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_IVA_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_IVA_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_IVA_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_IVA_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_IVA_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_IVA_DELTAMSTEP_MASK    (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_IVA_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_IVA_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_IVA_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_IVA_DELTAMSTEP_SHIFT   (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_IVA_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_IVA_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_IVA_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_IVA_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_IVA_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_IVA_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_IVA_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_IVA_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_IVA_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_BYPCLK_DPLL_IVA_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_MASK  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_IVA_CLKSEL_MASK                (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_IVA_CLKSEL_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_CORE_X2_CLK_DIV_1  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_IVA_CLKSEL_CORE_X2_CLK_DIV_1   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_CORE_X2_CLK_DIV_1)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_CORE_X2_CLK_DIV_2  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_IVA_CLKSEL_CORE_X2_CLK_DIV_2   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_CORE_X2_CLK_DIV_2)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_CORE_X2_CLK_DIV_4  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_IVA_CLKSEL_CORE_X2_CLK_DIV_4   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_CORE_X2_CLK_DIV_4)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_CORE_X2_CLK_DIV_8  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_IVA_CLKSEL_CORE_X2_CLK_DIV_8   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_CLKSEL_CORE_X2_CLK_DIV_8)


#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_IVA_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_CLKMODE_DPLL_ABE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_RESERVED          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_RESERVED1         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_RESERVED2         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_RESERVED3         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_RESERVED4         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_EN_DPLL_LOCK_MODE    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_LEVEL_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_LEVEL_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_REFCLKX2   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_REFCLKX4   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_REFCLKX8   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_DRIFTGUARD_EN_MASK   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_LPMODE_EN_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_LPMODE_EN_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_LPMODE_EN_DISABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_LPMODE_EN_ENABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_REGM4XEN_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_REGM4XEN_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_REGM4XEN_DISABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_REGM4XEN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_REGM4XEN_ENABLE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_REGM4XEN_ENABLE      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_REGM4XEN_ENABLE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_EN_MASK          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_EN_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_EN_DISABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_EN_ENABLED       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_ACK_MASK         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_ACK_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_ACK_DISABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_ACK_ENABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_TYPE_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_TYPE_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_ABE_DPLL_SSC_TYPE_SQUARE      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_ABE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_CLK_MASK           (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_CLK_SHIFT          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_CLK_DPLL_LOCKED    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_TRANSIENT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_LP_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_FR_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_RESERVED1     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_RESERVED2     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_LP_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_FR_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_MODE_RESERVED3     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_INIT_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_INIT_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_ABE_ST_DPLL_INIT_DPLL_INIT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_ABE_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_ABE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_ABE_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_ABE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_ABE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE_DPLL_DIV_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE_DPLL_DIV_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_DIV_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE_DPLL_BYP_CLKSEL_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE_DPLL_BYP_CLKSEL_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE_DPLL_MULT_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE_DPLL_MULT_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE_DCC_EN_MASK                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE_DCC_EN_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_ABE_DCC_EN_DISABLED            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DCC_EN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_RESETVAL   ((uint32_t)(0x00800000U))

/* CM_DIV_M2_DPLL_ABE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKX2ST_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_CLKX2ST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKX2ST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKX2ST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKX2ST_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_CLKX2ST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKX2ST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKX2ST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_CLKX2ST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKX2ST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKX2ST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_ABE_CLKX2ST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_CLKX2ST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_DIV_M3_DPLL_ABE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_ABE_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_ABE_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_ABE_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_ABE_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_ABE_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_ABE_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_ABE_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_ABE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_ABE_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_ABE_DELTAMSTEP_MASK    (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_ABE_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_ABE_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_ABE_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_ABE_DELTAMSTEP_SHIFT   (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_ABE_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_ABE_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_ABE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_ABE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_ABE_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_ABE_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_ABE_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_ABE_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_ABE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKMODE_DPLL_DDR_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_RESERVED          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_RESERVED1         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_RESERVED2         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_RESERVED3         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_RESERVED4         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_EN_DPLL_LOCK_MODE    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_LEVEL_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_LEVEL_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_REFCLKX2   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_REFCLKX4   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_REFCLKX8   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_DRIFTGUARD_EN_MASK   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_LPMODE_EN_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_LPMODE_EN_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_LPMODE_EN_DISABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_LPMODE_EN_ENABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_REGM4XEN_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_REGM4XEN_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_REGM4XEN_DISABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_REGM4XEN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_EN_MASK          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_EN_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_EN_DISABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_EN_ENABLED       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_ACK_MASK         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_ACK_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_ACK_DISABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_ACK_ENABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_TYPE_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_TYPE_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DDR_DPLL_SSC_TYPE_SQUARE      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_DDR_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_CLK_MASK           (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_CLK_SHIFT          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_CLK_DPLL_LOCKED    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_TRANSIENT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_LP_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_FR_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_RESERVED1     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_RESERVED2     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_LP_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_FR_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_MODE_RESERVED3     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_INIT_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_INIT_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DDR_ST_DPLL_INIT_DPLL_INIT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DDR_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_DDR_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DDR_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_DDR_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DPLL_DIV_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DPLL_DIV_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_DIV_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DPLL_MULT_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DPLL_MULT_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DCC_EN_MASK                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DCC_EN_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DCC_EN_DISABLED            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DCC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DCC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DCC_EN_ENABLED             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DCC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DPLL_BYP_CLKSEL_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DDR_DPLL_BYP_CLKSEL_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_DIV_M2_DPLL_DDR_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DDR_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DDR_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DDR_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DDR_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DDR_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DDR_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DDR_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_DIV_M3_DPLL_DDR_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DDR_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DDR_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DDR_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DDR_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DDR_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DDR_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DDR_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_DIV_H11_DPLL_DDR_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_DDR_DIVHS_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_DDR_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_DDR_DIVHS_RESERVED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_DDR_CLKST_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_DDR_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_DDR_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_DDR_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_DDR_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DDR_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_DDR_DELTAMSTEP_MASK    (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DDR_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DDR_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DDR_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_DDR_DELTAMSTEP_SHIFT   (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DDR_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DDR_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DDR_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_DDR_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DDR_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DDR_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DDR_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DDR_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DDR_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKMODE_DPLL_DSP_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_RESERVED          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_RESERVED1         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_RESERVED2         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_RESERVED3         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_RESERVED4         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_EN_DPLL_LOCK_MODE    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_LEVEL_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_LEVEL_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_REFCLKX2   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_REFCLKX4   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_REFCLKX8   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_DRIFTGUARD_EN_MASK   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_LPMODE_EN_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_LPMODE_EN_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_LPMODE_EN_DISABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_LPMODE_EN_ENABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_REGM4XEN_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_REGM4XEN_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_REGM4XEN_DISABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_REGM4XEN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_EN_MASK          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_EN_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_EN_DISABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_EN_ENABLED       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_ACK_MASK         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_ACK_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_ACK_DISABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_ACK_ENABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_TYPE_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_TYPE_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_DSP_DPLL_SSC_TYPE_SQUARE      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_DSP_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_CLK_MASK           (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_CLK_SHIFT          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_CLK_DPLL_LOCKED    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_TRANSIENT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_LP_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_FR_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_RESERVED1     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_RESERVED2     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_LP_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_FR_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_MODE_RESERVED3     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_INIT_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_INIT_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_DSP_ST_DPLL_INIT_DPLL_INIT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_DSP_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_DSP_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_DSP_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_DSP_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_DSP_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP_DPLL_DIV_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP_DPLL_DIV_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_DIV_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP_DPLL_BYP_CLKSEL_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP_DPLL_BYP_CLKSEL_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP_DPLL_MULT_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP_DPLL_MULT_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP_DCC_EN_MASK                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP_DCC_EN_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_DSP_DCC_EN_DISABLED            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DCC_EN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_DIV_M2_DPLL_DSP_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DSP_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DSP_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DSP_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DSP_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DSP_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DSP_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_DSP_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_DIV_M3_DPLL_DSP_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DSP_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DSP_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DSP_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DSP_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DSP_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DSP_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_DSP_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_DSP_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DSP_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_DSP_DELTAMSTEP_MASK    (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DSP_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DSP_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DSP_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_DSP_DELTAMSTEP_SHIFT   (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DSP_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DSP_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_DSP_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_DSP_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DSP_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DSP_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DSP_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_DSP_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_DSP_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_BYPCLK_DPLL_DSP_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_MASK  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_DSP_CLKSEL_MASK                (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_DSP_CLKSEL_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_CORE_X2_CLK_DIV_1  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_DSP_CLKSEL_CORE_X2_CLK_DIV_1   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_CORE_X2_CLK_DIV_1)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_CORE_X2_CLK_DIV_2  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_DSP_CLKSEL_CORE_X2_CLK_DIV_2   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_CORE_X2_CLK_DIV_2)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_CORE_X2_CLK_DIV_4  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_DSP_CLKSEL_CORE_X2_CLK_DIV_4   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_CORE_X2_CLK_DIV_4)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_CORE_X2_CLK_DIV_8  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_DSP_CLKSEL_CORE_X2_CLK_DIV_8   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_CLKSEL_CORE_X2_CLK_DIV_8)


#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_DSP_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_SHADOW_FREQ_CONFIG1_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_M2_DIV_MASK  ((uint32_t)(0x0000F800U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_M2_DIV_MASK   (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_M2_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_M2_DIV_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_M2_DIV_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_M2_DIV_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_M2_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_M2_DIV_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_M2_DIV_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_M2_DIV_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_FREQ_UPDATE_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_FREQ_UPDATE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_FREQ_UPDATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_FREQ_UPDATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_FREQ_UPDATE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_FREQ_UPDATE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_FREQ_UPDATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_FREQ_UPDATE_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_OVERRIDE_MASK  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DLL_OVERRIDE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_OVERRIDE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_OVERRIDE_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_OVERRIDE_SHIFT  ((uint32_t)(2U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DLL_OVERRIDE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_OVERRIDE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_OVERRIDE_NO_OVR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DLL_OVERRIDE_NO_OVR    (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_OVERRIDE_NO_OVR)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_OVERRIDE_OVR  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DLL_OVERRIDE_OVR       (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_OVERRIDE_OVR)


#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_RESET_MASK  ((uint32_t)(0x00000008U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DLL_RESET_MASK         (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_RESET_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_RESET_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_RESET_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DLL_RESET_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_RESET_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_RESET_NO_RESET  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DLL_RESET_NO_RESET     (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_RESET_NO_RESET)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_RESET_RESET  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DLL_RESET_RESET        (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DLL_RESET_RESET)


#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_MASK  ((uint32_t)(0x00070000U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_SHIFT  ((uint32_t)(16U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_RESERVED1  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_RESERVED2  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_RESERVED3  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_RESERVED4  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_DPLL_EN_DPLL_LOCK_MODE  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_DPLL_DDR_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG1_REG_RESETVAL  ((uint32_t)(0x0005080cU))

/* CM_SHADOW_FREQ_CONFIG2_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_DPLL_CORE_H12_DIV_MASK  ((uint32_t)(0x000000FCU))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_H12_DIV_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_DPLL_CORE_H12_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_DPLL_CORE_H12_DIV_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_DPLL_CORE_H12_DIV_SHIFT  ((uint32_t)(2U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_H12_DIV_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_DPLL_CORE_H12_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_DPLL_CORE_H12_DIV_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_H12_DIV_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_DPLL_CORE_H12_DIV_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_GPMC_FREQ_UPDATE_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_GPMC_FREQ_UPDATE_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_GPMC_FREQ_UPDATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_GPMC_FREQ_UPDATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_GPMC_FREQ_UPDATE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_GPMC_FREQ_UPDATE_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_GPMC_FREQ_UPDATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_GPMC_FREQ_UPDATE_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_GPMC_FREQ_UPDATE_DISABLED  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_GPMC_FREQ_UPDATE_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_GPMC_FREQ_UPDATE_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_GPMC_FREQ_UPDATE_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_GPMC_FREQ_UPDATE_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_CLKSEL_L3_MASK  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_CLKSEL_L3_MASK         (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_CLKSEL_L3_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_CLKSEL_L3_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_CLKSEL_L3_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_CLKSEL_L3_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_CLKSEL_L3_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_CLKSEL_L3_CORE_CLK_DIV_1  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_CLKSEL_L3_CORE_CLK_DIV_1  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_CLKSEL_L3_CORE_CLK_DIV_1)

#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_CLKSEL_L3_CORE_CLK_DIV_2  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_SHADOW_FREQ_CONFIG2_CLKSEL_L3_CORE_CLK_DIV_2  (CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_CLKSEL_L3_CORE_CLK_DIV_2)


#define CSL_CKGEN_CM_CORE_AON_CM_SHADOW_FREQ_CONFIG2_REG_RESETVAL  ((uint32_t)(0x00000004U))

/* CM_DYN_DEP_PRESCAL_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DYN_DEP_PRESCAL_REG_PRESCAL_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DYN_DEP_PRESCAL_PRESCAL_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DYN_DEP_PRESCAL_REG_PRESCAL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DYN_DEP_PRESCAL_REG_PRESCAL_RESETVAL  ((uint32_t)(0x00000020U))

#define CSL_CKGEN_CM_CORE_AON_CM_DYN_DEP_PRESCAL_REG_PRESCAL_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DYN_DEP_PRESCAL_PRESCAL_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DYN_DEP_PRESCAL_REG_PRESCAL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DYN_DEP_PRESCAL_REG_PRESCAL_MAX  ((uint32_t)(0x0000003fU))

#define CSL_CKGEN_CM_CORE_AON_CM_DYN_DEP_PRESCAL_REG_RESETVAL   ((uint32_t)(0x00000020U))

/* CM_RESTORE_ST_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE1_COMPLETED_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_RESTORE_ST_PHASE1_COMPLETED_MASK           (CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE1_COMPLETED_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE1_COMPLETED_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE1_COMPLETED_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_RESTORE_ST_PHASE1_COMPLETED_SHIFT          (CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE1_COMPLETED_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE1_COMPLETED_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2A_COMPLETED_MASK  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_RESTORE_ST_PHASE2A_COMPLETED_MASK          (CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2A_COMPLETED_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2A_COMPLETED_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2A_COMPLETED_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_RESTORE_ST_PHASE2A_COMPLETED_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2A_COMPLETED_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2A_COMPLETED_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2B_COMPLETED_MASK  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_RESTORE_ST_PHASE2B_COMPLETED_MASK          (CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2B_COMPLETED_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2B_COMPLETED_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2B_COMPLETED_SHIFT  ((uint32_t)(2U))
/* Below define for backward compatibility */
#define CM_RESTORE_ST_PHASE2B_COMPLETED_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2B_COMPLETED_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_PHASE2B_COMPLETED_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_RESTORE_ST_REG_RESETVAL        ((uint32_t)(0x00000000U))

/* CM_CLKMODE_DPLL_EVE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_RESERVED          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_RESERVED1         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_RESERVED2         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_RESERVED3         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_RESERVED4         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_EN_DPLL_LOCK_MODE    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_LEVEL_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_LEVEL_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_REFCLKX2   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_REFCLKX4   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_REFCLKX8   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_DRIFTGUARD_EN_MASK   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_LPMODE_EN_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_LPMODE_EN_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_LPMODE_EN_DISABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_LPMODE_EN_ENABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_REGM4XEN_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_REGM4XEN_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_REGM4XEN_DISABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_REGM4XEN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_EN_MASK          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_EN_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_EN_DISABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_EN_ENABLED       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_ACK_MASK         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_ACK_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_ACK_DISABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_ACK_ENABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_TYPE_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_TYPE_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_EVE_DPLL_SSC_TYPE_SQUARE      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_EVE_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_EVE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_CLK_MASK           (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_CLK_SHIFT          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_CLK_DPLL_LOCKED    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_TRANSIENT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_LP_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_FR_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_RESERVED1     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_RESERVED2     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_LP_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_FR_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_MODE_RESERVED3     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_INIT_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_INIT_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_EVE_ST_DPLL_INIT_DPLL_INIT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_EVE_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_EVE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_EVE_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_EVE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_EVE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE_DPLL_DIV_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE_DPLL_DIV_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_DIV_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE_DPLL_BYP_CLKSEL_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE_DPLL_BYP_CLKSEL_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE_DPLL_MULT_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE_DPLL_MULT_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE_DCC_EN_MASK                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE_DCC_EN_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_EVE_DCC_EN_DISABLED            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_DCC_EN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_EVE_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_DIV_M2_DPLL_EVE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_EVE_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_EVE_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_EVE_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_EVE_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_EVE_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_EVE_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_EVE_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_EVE_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_DIV_M3_DPLL_EVE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_EVE_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_EVE_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_EVE_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_EVE_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_EVE_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_EVE_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_EVE_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_EVE_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_EVE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_EVE_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_EVE_DELTAMSTEP_MASK    (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_EVE_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_EVE_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_EVE_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_EVE_DELTAMSTEP_SHIFT   (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_EVE_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_EVE_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_EVE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_EVE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_EVE_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_EVE_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_EVE_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_EVE_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_EVE_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_BYPCLK_DPLL_EVE_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_MASK  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_EVE_CLKSEL_MASK                (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_EVE_CLKSEL_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_CORE_X2_CLK_DIV_1  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_EVE_CLKSEL_CORE_X2_CLK_DIV_1   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_CORE_X2_CLK_DIV_1)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_CORE_X2_CLK_DIV_2  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_EVE_CLKSEL_CORE_X2_CLK_DIV_2   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_CORE_X2_CLK_DIV_2)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_CORE_X2_CLK_DIV_4  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_EVE_CLKSEL_CORE_X2_CLK_DIV_4   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_CORE_X2_CLK_DIV_4)

#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_CORE_X2_CLK_DIV_8  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_BYPCLK_DPLL_EVE_CLKSEL_CORE_X2_CLK_DIV_8   (CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_CLKSEL_CORE_X2_CLK_DIV_8)


#define CSL_CKGEN_CM_CORE_AON_CM_BYPCLK_DPLL_EVE_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_CLKMODE_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_RESERVED         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_RESERVED1        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_RESERVED2        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_RESERVED3        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_RESERVED4        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_EN_DPLL_LOCK_MODE   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_LEVEL_MASK     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_LEVEL_SHIFT    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_REFCLKX2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_REFCLKX4  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_REFCLKX8  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_DRIFTGUARD_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_LPMODE_EN_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_LPMODE_EN_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_LPMODE_EN_DISABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_LPMODE_EN_ENABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_REGM4XEN_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_REGM4XEN_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_REGM4XEN_DISABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_REGM4XEN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_EN_MASK         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_EN_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_EN_DISABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_EN_ENABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_ACK_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_ACK_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_ACK_DISABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_ACK_ENABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_TYPE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_TYPE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GMAC_DPLL_SSC_TYPE_SQUARE     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_CLK_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_CLK_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_CLK_DPLL_LOCKED   (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_MASK         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_TRANSIENT    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_LP_STOP      (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_FR_STOP      (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_RESERVED1    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_RESERVED2    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_LP_BYP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_FR_BYP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_MODE_RESERVED3    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_INIT_MASK         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_INIT_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GMAC_ST_DPLL_INIT_DPLL_INIT    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_MASK     (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_SHIFT    (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GMAC_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_DIV_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_DIV_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_DIV_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_MULT_MASK            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_MULT_SHIFT           (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DCC_EN_MASK               (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DCC_EN_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DCC_EN_DISABLED           (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DCC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DCC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DCC_EN_ENABLED            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DCC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_BYP_CLKSEL_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_BYP_CLKSEL_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_CLKOUTHIF_CLKSEL_MASK  ((uint32_t)(0x00100000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_CLKOUTHIF_CLKSEL_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_CLKOUTHIF_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_CLKOUTHIF_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_CLKOUTHIF_CLKSEL_SHIFT  ((uint32_t)(20U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_CLKOUTHIF_CLKSEL_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_CLKOUTHIF_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_DCO  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_CLKOUTHIF_CLKSEL_SEL_DCO  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_DCO)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_CLKINPHIF  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GMAC_DPLL_CLKOUTHIF_CLKSEL_SEL_CLKINPHIF  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_CLKINPHIF)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_DIV_M2_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GMAC_DIVHS_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GMAC_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GMAC_DIVHS_RESERVED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GMAC_CLKST_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GMAC_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GMAC_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GMAC_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_M3_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GMAC_DIVHS_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GMAC_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GMAC_DIVHS_RESERVED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GMAC_CLKST_MASK                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GMAC_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GMAC_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GMAC_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H11_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_GMAC_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_GMAC_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_GMAC_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_GMAC_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_GMAC_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_GMAC_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_GMAC_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H12_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_GMAC_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_GMAC_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_GMAC_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_GMAC_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_GMAC_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_GMAC_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_GMAC_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H13_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_GMAC_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_GMAC_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_GMAC_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_GMAC_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_GMAC_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_GMAC_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_GMAC_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_DIV_H14_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_DIVHS_MASK  ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_GMAC_DIVHS_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_GMAC_DIVHS_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_GMAC_DIVHS_RESERVED           (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_GMAC_CLKST_MASK               (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_GMAC_CLKST_SHIFT              (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_GMAC_CLKST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_GMAC_CLKST_CLK_GATED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GMAC_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_GMAC_DELTAMSTEP_MASK   (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GMAC_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GMAC_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GMAC_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_GMAC_DELTAMSTEP_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GMAC_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GMAC_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_GMAC_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GMAC_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GMAC_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GMAC_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GMAC_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GMAC_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKMODE_DPLL_GPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_RESERVED          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_RESERVED1         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_RESERVED2         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_RESERVED3         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_RESERVED4         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_EN_DPLL_LOCK_MODE    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_DRIFTGUARD_EN_MASK   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_LEVEL_MASK      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_LEVEL_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_REFCLKX2   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_REFCLKX4   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_REFCLKX8   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_LPMODE_EN_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_LPMODE_EN_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_LPMODE_EN_DISABLED   (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_LPMODE_EN_ENABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_REGM4XEN_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_REGM4XEN_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_REGM4XEN_DISABLED    (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_REGM4XEN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_EN_MASK          (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_EN_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_EN_DISABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_EN_ENABLED       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_ACK_MASK         (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_ACK_SHIFT        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_ACK_DISABLED     (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_ACK_ENABLED      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_TYPE_MASK        (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_TYPE_SHIFT       (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_GPU_DPLL_SSC_TYPE_SQUARE      (CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_GPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_CLK_MASK           (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_CLK_SHIFT          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_CLK_DPLL_LOCKED    (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_TRANSIENT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_LP_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_FR_STOP       (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_RESERVED1     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_RESERVED2     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_LP_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_FR_BYP        (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_MODE_RESERVED3     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_INIT_MASK          (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_INIT_SHIFT         (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_GPU_ST_DPLL_INIT_DPLL_INIT     (CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_AON_CM_IDLEST_DPLL_GPU_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_GPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_MASK      (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_SHIFT     (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_RESERVED  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_RESERVED)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_RESERVED1  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_GPU_AUTO_DPLL_MODE_RESERVED2  (CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_AUTO_DPLL_MODE_RESERVED2)


#define CSL_CKGEN_CM_CORE_AON_CM_AUTOIDLE_DPLL_GPU_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_GPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_DIV_MASK              (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_DIV_SHIFT             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_DIV_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_BYP_CLKSEL_MASK       (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_BYP_CLKSEL_SHIFT      (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_CLKOUTHIF_CLKSEL_MASK  ((uint32_t)(0x00100000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_CLKOUTHIF_CLKSEL_MASK  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_CLKOUTHIF_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_CLKOUTHIF_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_CLKOUTHIF_CLKSEL_SHIFT  ((uint32_t)(20U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_CLKOUTHIF_CLKSEL_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_CLKOUTHIF_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_DCO  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_CLKOUTHIF_CLKSEL_SEL_DCO  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_DCO)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_CLKINPHIF  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_CLKOUTHIF_CLKSEL_SEL_CLKINPHIF  (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_CLKOUTHIF_CLKSEL_SEL_CLKINPHIF)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_MULT_MASK             (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DPLL_MULT_SHIFT            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DCC_EN_MASK                (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DCC_EN_SHIFT               (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_GPU_DCC_EN_DISABLED            (CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DCC_EN_DISABLED)


#define CSL_CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_RESETVAL   ((uint32_t)(0x00000000U))

/* CM_DIV_M2_DPLL_GPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GPU_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GPU_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GPU_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GPU_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GPU_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GPU_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_GPU_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_DIV_M3_DPLL_GPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_DIVHS_MASK  ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GPU_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GPU_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GPU_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GPU_CLKST_MASK                 (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GPU_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GPU_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_GPU_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GPU_REG_RESETVAL   ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_GPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GPU_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_GPU_DELTAMSTEP_MASK    (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GPU_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GPU_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GPU_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_GPU_DELTAMSTEP_SHIFT   (CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GPU_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GPU_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_DELTAMSTEP_DPLL_GPU_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_GPU_REG */

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GPU_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GPU_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GPU_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_GPU_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_AON_CM_SSC_MODFREQDIV_DPLL_GPU_REG_RESETVAL  ((uint32_t)(0x00000000U))

#ifdef __cplusplus
}
#endif
#endif
