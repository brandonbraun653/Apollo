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
#ifndef CSLR_CKGEN_CM_CORE_H
#define CSLR_CKGEN_CM_CORE_H

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
    volatile Uint8  RSVD0[4];
    volatile Uint32 CM_CLKSEL_USB_60MHZ_REG;
    volatile Uint8  RSVD1[56];
    volatile Uint32 CM_CLKMODE_DPLL_PER_REG;
    volatile Uint32 CM_IDLEST_DPLL_PER_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_PER_REG;
    volatile Uint32 CM_CLKSEL_DPLL_PER_REG;
    volatile Uint32 CM_DIV_M2_DPLL_PER_REG;
    volatile Uint32 CM_DIV_M3_DPLL_PER_REG;
    volatile Uint32 CM_DIV_H11_DPLL_PER_REG;
    volatile Uint32 CM_DIV_H12_DPLL_PER_REG;
    volatile Uint32 CM_DIV_H13_DPLL_PER_REG;
    volatile Uint32 CM_DIV_H14_DPLL_PER_REG;
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_PER_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_PER_REG;
    volatile Uint8  RSVD2[16];
    volatile Uint32 CM_CLKMODE_DPLL_USB_REG;
    volatile Uint32 CM_IDLEST_DPLL_USB_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_USB_REG;
    volatile Uint32 CM_CLKSEL_DPLL_USB_REG;
    volatile Uint32 CM_DIV_M2_DPLL_USB_REG;
    volatile Uint8  RSVD3[20];
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_USB_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_USB_REG;
    volatile Uint8  RSVD4[4];
    volatile Uint32 CM_CLKDCOLDO_DPLL_USB_REG;
    volatile Uint8  RSVD5[72];
    volatile Uint32 CM_CLKMODE_DPLL_PCIE_REF_REG;
    volatile Uint32 CM_IDLEST_DPLL_PCIE_REF_REG;
    volatile Uint32 CM_AUTOIDLE_DPLL_PCIE_REF_REG;
    volatile Uint32 CM_CLKSEL_DPLL_PCIE_REF_REG;
    volatile Uint32 CM_DIV_M2_DPLL_PCIE_REF_REG;
    volatile Uint32 CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG;
    volatile Uint32 CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG;
    volatile Uint32 CM_CLKMODE_APLL_PCIE_REG;
    volatile Uint32 CM_IDLEST_APLL_PCIE_REG;
    volatile Uint32 CM_DIV_M2_APLL_PCIE_REG;
    volatile Uint32 CM_CLKVCOLDO_APLL_PCIE_REG;
} CSL_ckgen_cm_coreRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Selects the configuration of the divider generating 60MHz clock for USB
 * from the DPLL_USB o/p. */
#define CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG               ((uint32_t)(0x4U))
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_60MHZ  (CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG               ((uint32_t)(0x40U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG                ((uint32_t)(0x44U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG              ((uint32_t)(0x48U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG                ((uint32_t)(0x4CU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG                ((uint32_t)(0x50U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG)


/* This register provides controls over the M3 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG                ((uint32_t)(0x54U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG)


/* This register provides controls over the CLKOUT1 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG               ((uint32_t)(0x58U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG)


/* This register provides controls over the CLKOUT2 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG               ((uint32_t)(0x5CU))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG)


/* This register provides controls over the CLKOUT3 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG               ((uint32_t)(0x60U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG)


/* This register provides controls over the CLKOUT4 o/p of the HSDIVIDER1. */
#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG               ((uint32_t)(0x64U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PER_REG        ((uint32_t)(0x68U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PER_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG        ((uint32_t)(0x6CU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PER  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG               ((uint32_t)(0x80U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG                ((uint32_t)(0x84U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG              ((uint32_t)(0x88U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG                ((uint32_t)(0x8CU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB  (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG                ((uint32_t)(0x90U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_USB  (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_USB_REG        ((uint32_t)(0xA8U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_USB  (CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_USB_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG        ((uint32_t)(0xACU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_USB  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG)


/* This register provides status over CLKDCOLDO output of the DPLL. */
#define CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG             ((uint32_t)(0xB4U))
/* Below define for backward compatibility */
#define CM_CLKDCOLDO_DPLL_USB  (CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG)


/* This register allows controlling the DPLL modes. */
#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG          ((uint32_t)(0x100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG)


/* This register allows monitoring DPLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG           ((uint32_t)(0x104U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG)


/* This register provides automatic control over the DPLL activity. */
#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG         ((uint32_t)(0x108U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG)


/* This register provides controls over the DPLL. */
#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG           ((uint32_t)(0x10CU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF  (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG           ((uint32_t)(0x110U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF  (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG)


/* Control the DeltaMStep parameter for Spread Spectrum Clocking. [warm reset
 * insensitive] */
#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG   ((uint32_t)(0x114U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_PCIE_REF  (CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG)


/* Control the Modulation Frequency (Fm) for Spread Spectrum Clocking. [warm
 * reset insensitive] */
#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG   ((uint32_t)(0x118U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PCIE_REF  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG)


/* This register allows controlling the APLL modes. */
#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG              ((uint32_t)(0x11CU))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG)


/* This register allows monitoring APLL activity. This register is read only
 * and automatically updated. [warm reset insensitive] */
#define CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG               ((uint32_t)(0x120U))
/* Below define for backward compatibility */
#define CM_IDLEST_APLL_PCIE  (CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG)


/* This register provides controls over the M2 divider of the DPLL. */
#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG               ((uint32_t)(0x124U))
/* Below define for backward compatibility */
#define CM_DIV_M2_APLL_PCIE  (CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG)


/* This register provides status over CLKVCOLDO and CLKVCOLDO_DIV outputs of
 * the APLL. */
#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG            ((uint32_t)(0x128U))
/* Below define for backward compatibility */
#define CM_CLKVCOLDO_APLL_PCIE  (CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CM_CLKSEL_USB_60MHZ_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_CLKSEL_MASK   ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_60MHZ_CLKSEL_MASK               (CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_CLKSEL_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_CLKSEL_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_60MHZ_CLKSEL_SHIFT              (CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_CLKSEL_SEL_DIV_8  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_60MHZ_CLKSEL_SEL_DIV_8          (CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_CLKSEL_SEL_DIV_8)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_CLKSEL_SEL_DIV_1  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_USB_60MHZ_CLKSEL_SEL_DIV_1          (CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_CLKSEL_SEL_DIV_1)


#define CSL_CKGEN_CM_CORE_CM_CLKSEL_USB_60MHZ_REG_RESETVAL      ((uint32_t)(0x00000001U))

/* CM_CLKMODE_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_MASK              (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_SHIFT             (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_RESERVED          (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_RESERVED1         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED1)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_RESERVED2         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_RESERVED3         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_RESERVED4         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_RESERVED4)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_DPLL_FR_BYP_MODE  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_DPLL_FR_BYP_MODE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_DPLL_FR_BYP_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_EN_DPLL_LOCK_MODE    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_DPLL_LOCK_MODE)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_MASK  ((uint32_t)(0x00000018U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_LEVEL_MASK      (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_LEVEL_SHIFT     (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_LEVEL_RAMP_DISABLE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_RAMP_DISABLE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_LEVEL_RAMP_ALGO1  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_RAMP_ALGO1)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_LEVEL_RAMP_ALGO2  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_RAMP_ALGO2)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_RESERVED  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_LEVEL_RESERVED  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_LEVEL_RESERVED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_MASK  ((uint32_t)(0x000000E0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_MASK       (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_SHIFT  ((uint32_t)(5U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_SHIFT      (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX2  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_REFCLKX2   (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX2)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX4  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_REFCLKX4   (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX4)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX8  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_REFCLKX8   (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX8)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX16  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_REFCLKX16  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX16)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX32  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_REFCLKX32  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX32)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX64  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_REFCLKX64  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX64)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX128  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_REFCLKX128  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX128)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX512  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RAMP_RATE_REFCLKX512  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RAMP_RATE_REFCLKX512)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_DRIFTGUARD_EN_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_DRIFTGUARD_EN_MASK   (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_DRIFTGUARD_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_DRIFTGUARD_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_DRIFTGUARD_EN_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_DRIFTGUARD_EN_SHIFT  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_DRIFTGUARD_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_DRIFTGUARD_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_DRIFTGUARD_EN_ENABLED  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_DRIFTGUARD_EN_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_DRIFTGUARD_EN_DIASBLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_DRIFTGUARD_EN_DIASBLED  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_DRIFTGUARD_EN_DIASBLED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RELOCK_RAMP_EN_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RELOCK_RAMP_EN_MASK  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RELOCK_RAMP_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RELOCK_RAMP_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RELOCK_RAMP_EN_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_RELOCK_RAMP_EN_SHIFT  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RELOCK_RAMP_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_RELOCK_RAMP_EN_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_LPMODE_EN_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_LPMODE_EN_MASK       (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_LPMODE_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_LPMODE_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_LPMODE_EN_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_LPMODE_EN_SHIFT      (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_LPMODE_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_LPMODE_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_LPMODE_EN_DISABLED   (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_LPMODE_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_LPMODE_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_LPMODE_EN_ENABLED    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_LPMODE_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_REGM4XEN_MASK  ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_REGM4XEN_MASK        (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_REGM4XEN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_REGM4XEN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_REGM4XEN_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_REGM4XEN_SHIFT       (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_REGM4XEN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_REGM4XEN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_REGM4XEN_DISABLED    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_REGM4XEN_DISABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_EN_MASK          (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_EN_SHIFT         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_EN_DISABLED      (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_EN_ENABLED       (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_ACK_MASK         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_ACK_SHIFT        (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_ACK_DISABLED     (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_ACK_ENABLED      (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_TYPE_MASK        (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_TYPE_SHIFT       (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PER_DPLL_SSC_TYPE_SQUARE      (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_RESETVAL      ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_CLK_MASK           (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_CLK_SHIFT          (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_CLK_DPLL_LOCKED    (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_MASK          (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_SHIFT         (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_TRANSIENT     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_LP_STOP       (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_FR_STOP       (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_FR_STOP)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_RESERVED1     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_RESERVED1)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_RESERVED2     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_LP_BYP        (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_FR_BYP        (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_FR_BYP)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_MODE_RESERVED3     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_MODE_RESERVED3)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_INIT_MASK          (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_INIT_SHIFT         (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PER_ST_DPLL_INIT_DPLL_INIT     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PER_REG_RESETVAL       ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_MASK      (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_SHIFT     (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_FR_STOP  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_AUTO_FR_STOP  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_FR_STOP)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_FR_BYP  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_AUTO_FR_BYP  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_AUTO_FR_BYP)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PER_REG_RESETVAL     ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_DIV_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER_DPLL_DIV_MASK              (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER_DPLL_DIV_SHIFT             (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_DIV_MAX   ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER_DPLL_BYP_CLKSEL_MASK       (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER_DPLL_BYP_CLKSEL_SHIFT      (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_MULT_MASK  ((uint32_t)(0x0007FF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER_DPLL_MULT_MASK             (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER_DPLL_MULT_SHIFT            (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_MULT_MAX  ((uint32_t)(0x000007ffU))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DCC_EN_MASK    ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER_DCC_EN_MASK                (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DCC_EN_SHIFT   ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER_DCC_EN_SHIFT               (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PER_DCC_EN_DISABLED            (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DCC_EN_DISABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_RESETVAL       ((uint32_t)(0x00000000U))

/* CM_DIV_M2_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_DIVHS_MASK     ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_DIVHS_SHIFT    ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKST_MASK     ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_CLKST_MASK                 (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKST_SHIFT    ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKX2ST_MASK   ((uint32_t)(0x00000800U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_CLKX2ST_MASK               (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKX2ST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKX2ST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKX2ST_SHIFT  ((uint32_t)(11U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_CLKX2ST_SHIFT              (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKX2ST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKX2ST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_CLKX2ST_CLK_ENABLED        (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKX2ST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKX2ST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PER_CLKX2ST_CLK_GATED          (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_CLKX2ST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_RESETVAL       ((uint32_t)(0x00000001U))

/* CM_DIV_M3_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_DIVHS_MASK     ((uint32_t)(0x0000001FU))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_PER_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_DIVHS_SHIFT    ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_PER_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_PER_DIVHS_RESERVED             (CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_CLKST_MASK     ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_PER_CLKST_MASK                 (CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_CLKST_SHIFT    ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_PER_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_PER_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M3_DPLL_PER_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_RESETVAL       ((uint32_t)(0x00000001U))

/* CM_DIV_H11_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_DIVHS_MASK    ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_PER_DIVHS_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_DIVHS_SHIFT   ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_PER_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_PER_DIVHS_RESERVED            (CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_CLKST_MASK    ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_PER_CLKST_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_CLKST_SHIFT   ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_PER_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_PER_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H11_DPLL_PER_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_RESETVAL      ((uint32_t)(0x00000001U))

/* CM_DIV_H12_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_DIVHS_MASK    ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_PER_DIVHS_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_DIVHS_SHIFT   ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_PER_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_PER_DIVHS_RESERVED            (CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_CLKST_MASK    ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_PER_CLKST_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_CLKST_SHIFT   ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_PER_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_PER_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H12_DPLL_PER_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_RESETVAL      ((uint32_t)(0x00000001U))

/* CM_DIV_H13_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_DIVHS_MASK    ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_PER_DIVHS_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_DIVHS_SHIFT   ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_PER_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_PER_DIVHS_RESERVED            (CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_CLKST_MASK    ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_PER_CLKST_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_CLKST_SHIFT   ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_PER_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_PER_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H13_DPLL_PER_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_RESETVAL      ((uint32_t)(0x00000001U))

/* CM_DIV_H14_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_DIVHS_MASK    ((uint32_t)(0x0000003FU))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_PER_DIVHS_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_DIVHS_SHIFT   ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_PER_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_DIVHS_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_PER_DIVHS_RESERVED            (CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_DIVHS_RESERVED)


#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_CLKST_MASK    ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_PER_CLKST_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_CLKST_SHIFT   ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_PER_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_PER_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_H14_DPLL_PER_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_RESETVAL      ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PER_REG_DELTAMSTEP_MASK  ((uint32_t)(0x000FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_PER_DELTAMSTEP_MASK    (CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PER_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PER_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PER_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_PER_DELTAMSTEP_SHIFT   (CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PER_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PER_REG_DELTAMSTEP_MAX  ((uint32_t)(0x000fffffU))

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PER_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_PER_REG */

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PER_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PER_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PER_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PER_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PER_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKMODE_DPLL_USB_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_MASK              (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_SHIFT             (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_RESERVED          (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_DPLL_LP_STP_MODE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_DPLL_LP_STP_MODE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_DPLL_LP_STP_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_RESERVED2         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_RESERVED3         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED6  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_RESERVED6         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED6)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_DPLL_LOCK_MODE    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_DPLL_LOCK_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_EN_RESERVED4         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_EN_RESERVED4)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_EN_MASK          (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_EN_SHIFT         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_EN_DISABLED      (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_EN_ENABLED       (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_ACK_MASK         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_ACK_SHIFT        (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_ACK_DISABLED     (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_ACK_ENABLED      (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_TYPE_MASK        (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_TYPE_SHIFT       (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_USB_DPLL_SSC_TYPE_SQUARE      (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_USB_REG_RESETVAL      ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_USB_REG */

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_CLK_MASK           (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_CLK_SHIFT          (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_CLK_DPLL_LOCKED    (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_MASK          (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_SHIFT         (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_TRANSIENT     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_LP_STOP       (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_RESERVED2     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_RESERVED3     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_RESERVED4     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_LP_BYP        (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED6  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_RESERVED6     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED6)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_MODE_RESERVED7     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_INIT_MASK          (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_INIT_SHIFT         (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_USB_ST_DPLL_INIT_DPLL_INIT     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_USB_REG_RESETVAL       ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_USB_REG */

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_MASK      (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_SHIFT     (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_RESERVED2  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED6  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_RESERVED6  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED6)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_USB_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_USB_REG_RESETVAL     ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_USB_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_DIV_MASK  ((uint32_t)(0x000000FFU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_DIV_MASK              (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_DIV_SHIFT             (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_DIV_MAX   ((uint32_t)(0x000000ffU))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_MULT_MASK  ((uint32_t)(0x000FFF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_MULT_MASK             (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_MULT_SHIFT            (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_MULT_MAX  ((uint32_t)(0x00000fffU))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SD_DIV_MASK  ((uint32_t)(0xFF000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_SD_DIV_MASK           (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SD_DIV_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SD_DIV_RESETVAL  ((uint32_t)(0x00000004U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SD_DIV_SHIFT  ((uint32_t)(24U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_SD_DIV_SHIFT          (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SD_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SD_DIV_MAX  ((uint32_t)(0x000000ffU))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_BYP_CLKSEL_MASK       (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_BYP_CLKSEL_SHIFT      (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DCC_EN_MASK    ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DCC_EN_MASK                (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DCC_EN_SHIFT   ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DCC_EN_SHIFT               (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DCC_EN_DISABLED            (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DCC_EN_DISABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SELFREQDCO_MASK  ((uint32_t)(0x00200000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_SELFREQDCO_MASK       (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SELFREQDCO_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SELFREQDCO_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SELFREQDCO_SHIFT  ((uint32_t)(21U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_SELFREQDCO_SHIFT      (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SELFREQDCO_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SELFREQDCO_LS_CLK  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_SELFREQDCO_LS_CLK     (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SELFREQDCO_LS_CLK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SELFREQDCO_HS_CLK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_USB_DPLL_SELFREQDCO_HS_CLK     (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_DPLL_SELFREQDCO_HS_CLK)


#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_USB_REG_RESETVAL       ((uint32_t)(0x04000000U))

/* CM_DIV_M2_DPLL_USB_REG */

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_DIVHS_MASK     ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_USB_DIVHS_MASK                 (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_DIVHS_SHIFT    ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_USB_DIVHS_SHIFT                (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_DIVHS_MAX      ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_CLKST_MASK     ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_USB_CLKST_MASK                 (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_CLKST_SHIFT    ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_USB_CLKST_SHIFT                (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_USB_CLKST_CLK_ENABLED          (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_USB_CLKST_CLK_GATED            (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_USB_REG_RESETVAL       ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_USB_REG */

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_USB_REG_DELTAMSTEP_MASK  ((uint32_t)(0x001FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_USB_DELTAMSTEP_MASK    (CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_USB_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_USB_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_USB_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_USB_DELTAMSTEP_SHIFT   (CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_USB_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_USB_REG_DELTAMSTEP_MAX  ((uint32_t)(0x001fffffU))

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_USB_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_USB_REG */

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_USB_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_USB_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_USB_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_USB_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_USB_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKDCOLDO_DPLL_USB_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_ST_DPLL_CLKDCOLDO_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKDCOLDO_DPLL_USB_ST_DPLL_CLKDCOLDO_MASK  (CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_ST_DPLL_CLKDCOLDO_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_ST_DPLL_CLKDCOLDO_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_ST_DPLL_CLKDCOLDO_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKDCOLDO_DPLL_USB_ST_DPLL_CLKDCOLDO_SHIFT  (CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_ST_DPLL_CLKDCOLDO_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_ST_DPLL_CLKDCOLDO_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKDCOLDO_DPLL_USB_ST_DPLL_CLKDCOLDO_CLK_ENABLED  (CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_ST_DPLL_CLKDCOLDO_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_ST_DPLL_CLKDCOLDO_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKDCOLDO_DPLL_USB_ST_DPLL_CLKDCOLDO_CLK_GATED  (CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_ST_DPLL_CLKDCOLDO_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_CLKDCOLDO_DPLL_USB_REG_RESETVAL    ((uint32_t)(0x00000000U))

/* CM_CLKMODE_DPLL_PCIE_REF_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_MASK         (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESETVAL  ((uint32_t)(0x00000005U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_SHIFT        (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_RESERVED     (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_DPLL_LP_STP_MODE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_DPLL_LP_STP_MODE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_DPLL_LP_STP_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_RESERVED2    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED2)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_RESERVED3    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED3)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_DPLL_LP_BYP_MODE  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_DPLL_LP_BYP_MODE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_DPLL_LP_BYP_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED6  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_RESERVED6    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED6)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_DPLL_LOCK_MODE  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_DPLL_LOCK_MODE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_DPLL_LOCK_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_EN_RESERVED4    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_RESERVED4)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_EN_MASK  ((uint32_t)(0x00001000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_EN_MASK     (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_EN_SHIFT  ((uint32_t)(12U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_EN_SHIFT    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_EN_DISABLED  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_EN_DISABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_EN_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_EN_ENABLED  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_EN_ENABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_ACK_MASK  ((uint32_t)(0x00002000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_ACK_MASK    (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_ACK_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_ACK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_ACK_SHIFT  ((uint32_t)(13U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_ACK_SHIFT   (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_ACK_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_ACK_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_ACK_DISABLED  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_ACK_DISABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_ACK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_ACK_ENABLED  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_ACK_ENABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_DOWNSPREAD_MASK  ((uint32_t)(0x00004000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_DOWNSPREAD_MASK  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_DOWNSPREAD_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_DOWNSPREAD_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_DOWNSPREAD_SHIFT  ((uint32_t)(14U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_DOWNSPREAD_SHIFT  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_DOWNSPREAD_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_DOWNSPREAD_FULL_SPREAD  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_DOWNSPREAD_FULL_SPREAD)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_DOWNSPREAD_LOW_SPREAD  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_DOWNSPREAD_LOW_SPREAD)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_TYPE_MASK  ((uint32_t)(0x00008000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_TYPE_MASK   (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_TYPE_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_TYPE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_TYPE_SHIFT  ((uint32_t)(15U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_TYPE_SHIFT  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_TYPE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_TYPE_TRIANGULAR  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_TYPE_TRIANGULAR  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_TYPE_TRIANGULAR)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_TYPE_SQUARE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_DPLL_PCIE_REF_DPLL_SSC_TYPE_SQUARE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_SSC_TYPE_SQUARE)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_RESETVAL  ((uint32_t)(0x00000005U))

/* CM_IDLEST_DPLL_PCIE_REF_REG */

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_CLK_MASK      (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_CLK_SHIFT     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_DPLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_CLK_DPLL_UNLOCKED  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_DPLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_DPLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_CLK_DPLL_LOCKED  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_CLK_DPLL_LOCKED)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_MASK  ((uint32_t)(0x0000000EU))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_MASK     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_SHIFT  ((uint32_t)(1U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_SHIFT    (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_TRANSIENT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_TRANSIENT  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_TRANSIENT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_LP_STOP  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_LP_STOP)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_RESERVED2  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_LP_BYP   (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_LP_BYP)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED6  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_RESERVED6  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED6)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_INIT_MASK  ((uint32_t)(0x00000010U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_INIT_MASK     (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_INIT_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_INIT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_INIT_SHIFT  ((uint32_t)(4U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_INIT_SHIFT    (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_INIT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_INIT_DPLL_NOTINIT  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_INIT_DPLL_NOTINIT  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_INIT_DPLL_NOTINIT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_INIT_DPLL_INIT  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_DPLL_PCIE_REF_ST_DPLL_INIT_DPLL_INIT  (CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_ST_DPLL_INIT_DPLL_INIT)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_DPLL_PCIE_REF_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_AUTOIDLE_DPLL_PCIE_REF_REG */

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_MASK  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_MASK  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_MASK)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_SHIFT  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_AUTO_CTL_DISABLE  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_AUTO_CTL_DISABLE)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_AUTO_LP_STOP  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_AUTO_LP_STOP  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_AUTO_LP_STOP)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED2  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_RESERVED2  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED2)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED3  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_RESERVED3  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED3)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED4  ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_RESERVED4  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED4)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_AUTO_LP_BYP  ((uint32_t)(0x00000005U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_AUTO_LP_BYP  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_AUTO_LP_BYP)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED6  ((uint32_t)(0x00000006U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_RESERVED6  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED6)

#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED7  ((uint32_t)(0x00000007U))
/* Below define for backward compatibility */
#define CM_AUTOIDLE_DPLL_PCIE_REF_AUTO_DPLL_MODE_RESERVED7  (CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_AUTO_DPLL_MODE_RESERVED7)


#define CSL_CKGEN_CM_CORE_CM_AUTOIDLE_DPLL_PCIE_REF_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKSEL_DPLL_PCIE_REF_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_DIV_MASK  ((uint32_t)(0x000000FFU))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_DIV_MASK         (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_DIV_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_DIV_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_DIV_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_DIV_SHIFT        (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_DIV_MAX  ((uint32_t)(0x000000ffU))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_MULT_MASK  ((uint32_t)(0x000FFF00U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_MULT_MASK        (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_MULT_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_MULT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_MULT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_MULT_SHIFT       (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_MULT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_MULT_MAX  ((uint32_t)(0x00000fffU))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SD_DIV_MASK  ((uint32_t)(0xFF000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_SD_DIV_MASK      (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SD_DIV_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SD_DIV_RESETVAL  ((uint32_t)(0x00000004U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SD_DIV_SHIFT  ((uint32_t)(24U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_SD_DIV_SHIFT     (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SD_DIV_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SD_DIV_MAX  ((uint32_t)(0x000000ffU))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_BYP_CLKSEL_MASK  ((uint32_t)(0x00800000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_BYP_CLKSEL_MASK  (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_BYP_CLKSEL_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_BYP_CLKSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_BYP_CLKSEL_SHIFT  ((uint32_t)(23U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_BYP_CLKSEL_SHIFT  (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_BYP_CLKSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_BYP_CLKSEL_MAX  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DCC_EN_MASK  ((uint32_t)(0x00400000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DCC_EN_MASK           (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DCC_EN_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DCC_EN_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DCC_EN_SHIFT  ((uint32_t)(22U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DCC_EN_SHIFT          (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DCC_EN_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DCC_EN_DISABLED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DCC_EN_DISABLED       (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DCC_EN_DISABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SELFREQDCO_MASK  ((uint32_t)(0x00200000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_SELFREQDCO_MASK  (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SELFREQDCO_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SELFREQDCO_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SELFREQDCO_SHIFT  ((uint32_t)(21U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_SELFREQDCO_SHIFT  (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SELFREQDCO_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SELFREQDCO_LS_CLK  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_SELFREQDCO_LS_CLK  (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SELFREQDCO_LS_CLK)

#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SELFREQDCO_HS_CLK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKSEL_DPLL_PCIE_REF_DPLL_SELFREQDCO_HS_CLK  (CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_SELFREQDCO_HS_CLK)


#define CSL_CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_RESETVAL  ((uint32_t)(0x04000000U))

/* CM_DIV_M2_DPLL_PCIE_REF_REG */

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_DIVHS_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_DIVHS_MASK            (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_DIVHS_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_DIVHS_SHIFT           (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_DIVHS_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKLDOST_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_CLKLDOST_MASK         (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKLDOST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKLDOST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKLDOST_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_CLKLDOST_SHIFT        (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKLDOST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKLDOST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_CLKLDOST_CLK_ENABLED  (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKLDOST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKLDOST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_CLKLDOST_CLK_GATED    (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKLDOST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_CLKST_MASK            (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_CLKST_SHIFT           (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_CLKST_CLK_ENABLED     (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_DPLL_PCIE_REF_CLKST_CLK_GATED       (CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_RESETVAL  ((uint32_t)(0x00000001U))

/* CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG */

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG_DELTAMSTEP_MASK  ((uint32_t)(0x001FFFFFU))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_DELTAMSTEP_MASK  (CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG_DELTAMSTEP_MASK)

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG_DELTAMSTEP_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG_DELTAMSTEP_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_DELTAMSTEP_SHIFT  (CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG_DELTAMSTEP_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG_DELTAMSTEP_MAX  ((uint32_t)(0x001fffffU))

#define CSL_CKGEN_CM_CORE_CM_SSC_DELTAMSTEP_DPLL_PCIE_REF_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG */

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_MANTISSA_MASK  ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PCIE_REF_MODFREQDIV_MANTISSA_MASK  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_MANTISSA_MASK)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_MANTISSA_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_MANTISSA_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PCIE_REF_MODFREQDIV_MANTISSA_SHIFT  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_MANTISSA_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_MANTISSA_MAX  ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_EXPONENT_MASK  ((uint32_t)(0x00000700U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PCIE_REF_MODFREQDIV_EXPONENT_MASK  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_EXPONENT_MASK)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_EXPONENT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_EXPONENT_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_SSC_MODFREQDIV_DPLL_PCIE_REF_MODFREQDIV_EXPONENT_SHIFT  (CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_EXPONENT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_MODFREQDIV_EXPONENT_MAX  ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_CM_SSC_MODFREQDIV_DPLL_PCIE_REF_REG_RESETVAL  ((uint32_t)(0x00000000U))

/* CM_CLKMODE_APLL_PCIE_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_MASK  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_MODE_SELECT_MASK         (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_MODE_SELECT_SHIFT        (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_APLL_FORCE_LOCK_MODE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_MODE_SELECT_APLL_FORCE_LOCK_MODE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_APLL_FORCE_LOCK_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_APLL_FORCE_IDLE_MODE  ((uint32_t)(0x00000002U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_MODE_SELECT_APLL_FORCE_IDLE_MODE  (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_APLL_FORCE_IDLE_MODE)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_RESERVED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_MODE_SELECT_RESERVED     (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_RESERVED)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_RESERVED1  ((uint32_t)(0x00000003U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_MODE_SELECT_RESERVED1    (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SELECT_RESERVED1)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_MASK    ((uint32_t)(0x00000004U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_MODE_MASK                (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SHIFT   ((uint32_t)(2U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_MODE_SHIFT               (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_PCIE    ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_MODE_PCIE                (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_MODE_PCIE)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_INPSEL_MASK  ((uint32_t)(0x00000038U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_INPSEL_MASK              (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_INPSEL_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_INPSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_INPSEL_SHIFT  ((uint32_t)(3U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_INPSEL_SHIFT             (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_INPSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_INPSEL_MAX   ((uint32_t)(0x00000007U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_REFSEL_MASK  ((uint32_t)(0x00000080U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_REFSEL_MASK              (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_REFSEL_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_REFSEL_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_REFSEL_SHIFT  ((uint32_t)(7U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_REFSEL_SHIFT             (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_REFSEL_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_REFSEL_CLKREF_ADPLL  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_REFSEL_CLKREF_ADPLL      (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_REFSEL_CLKREF_ADPLL)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_REFSEL_CLKREF_ACSPCIE  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_REFSEL_CLKREF_ACSPCIE    (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_REFSEL_CLKREF_ACSPCIE)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_CLKDIV_BYPASS_MASK  ((uint32_t)(0x00000100U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_CLKDIV_BYPASS_MASK       (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_CLKDIV_BYPASS_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_CLKDIV_BYPASS_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_CLKDIV_BYPASS_SHIFT  ((uint32_t)(8U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_CLKDIV_BYPASS_SHIFT      (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_CLKDIV_BYPASS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_CLKDIV_BYPASS_PCIEDIVBY2_BYPASS_0  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_CLKDIV_BYPASS_PCIEDIVBY2_BYPASS_0  (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_CLKDIV_BYPASS_PCIEDIVBY2_BYPASS_0)

#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_CLKDIV_BYPASS_PCIEDIVBY2_BYPASS_1  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKMODE_APLL_PCIE_CLKDIV_BYPASS_PCIEDIVBY2_BYPASS_1  (CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_CLKDIV_BYPASS_PCIEDIVBY2_BYPASS_1)


#define CSL_CKGEN_CM_CORE_CM_CLKMODE_APLL_PCIE_REG_RESETVAL     ((uint32_t)(0x00000000U))

/* CM_IDLEST_APLL_PCIE_REG */

#define CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_ST_APLL_CLK_MASK  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_APLL_PCIE_ST_APLL_CLK_MASK          (CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_ST_APLL_CLK_MASK)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_ST_APLL_CLK_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_ST_APLL_CLK_SHIFT  ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_IDLEST_APLL_PCIE_ST_APLL_CLK_SHIFT         (CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_ST_APLL_CLK_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_ST_APLL_CLK_APLL_UNLOCKED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_IDLEST_APLL_PCIE_ST_APLL_CLK_APLL_UNLOCKED  (CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_ST_APLL_CLK_APLL_UNLOCKED)

#define CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_ST_APLL_CLK_APLL_LOCKED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_IDLEST_APLL_PCIE_ST_APLL_CLK_APLL_LOCKED   (CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_ST_APLL_CLK_APLL_LOCKED)


#define CSL_CKGEN_CM_CORE_CM_IDLEST_APLL_PCIE_REG_RESETVAL      ((uint32_t)(0x00000000U))

/* CM_DIV_M2_APLL_PCIE_REG */

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_DIVHS_MASK    ((uint32_t)(0x0000007FU))
/* Below define for backward compatibility */
#define CM_DIV_M2_APLL_PCIE_DIVHS_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_DIVHS_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_DIVHS_RESETVAL  ((uint32_t)(0x00000001U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_DIVHS_SHIFT   ((uint32_t)(0U))
/* Below define for backward compatibility */
#define CM_DIV_M2_APLL_PCIE_DIVHS_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_DIVHS_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_DIVHS_MAX     ((uint32_t)(0x0000007fU))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_CLKST_MASK    ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_DIV_M2_APLL_PCIE_CLKST_MASK                (CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_CLKST_SHIFT   ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_DIV_M2_APLL_PCIE_CLKST_SHIFT               (CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_DIV_M2_APLL_PCIE_CLKST_CLK_ENABLED         (CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_DIV_M2_APLL_PCIE_CLKST_CLK_GATED           (CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_DIV_M2_APLL_PCIE_REG_RESETVAL      ((uint32_t)(0x00000001U))

/* CM_CLKVCOLDO_APLL_PCIE_REG */

#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLKST_MASK  ((uint32_t)(0x00000200U))
/* Below define for backward compatibility */
#define CM_CLKVCOLDO_APLL_PCIE_CLKST_MASK             (CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLKST_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLKST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLKST_SHIFT  ((uint32_t)(9U))
/* Below define for backward compatibility */
#define CM_CLKVCOLDO_APLL_PCIE_CLKST_SHIFT            (CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLKST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLKST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKVCOLDO_APLL_PCIE_CLKST_CLK_ENABLED      (CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLKST_CLK_ENABLED)

#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLKST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKVCOLDO_APLL_PCIE_CLKST_CLK_GATED        (CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLKST_CLK_GATED)


#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLK_DIVST_MASK  ((uint32_t)(0x00000400U))
/* Below define for backward compatibility */
#define CM_CLKVCOLDO_APLL_PCIE_CLK_DIVST_MASK         (CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLK_DIVST_MASK)

#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLK_DIVST_RESETVAL  ((uint32_t)(0x00000000U))

#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLK_DIVST_SHIFT  ((uint32_t)(10U))
/* Below define for backward compatibility */
#define CM_CLKVCOLDO_APLL_PCIE_CLK_DIVST_SHIFT        (CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLK_DIVST_SHIFT)

#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLK_DIVST_CLK_GATED  ((uint32_t)(0x00000000U))
/* Below define for backward compatibility */
#define CM_CLKVCOLDO_APLL_PCIE_CLK_DIVST_CLK_GATED    (CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLK_DIVST_CLK_GATED)

#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLK_DIVST_CLK_ENABLED  ((uint32_t)(0x00000001U))
/* Below define for backward compatibility */
#define CM_CLKVCOLDO_APLL_PCIE_CLK_DIVST_CLK_ENABLED  (CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_CLK_DIVST_CLK_ENABLED)


#define CSL_CKGEN_CM_CORE_CM_CLKVCOLDO_APLL_PCIE_REG_RESETVAL   ((uint32_t)(0x00000000U))

#ifdef __cplusplus
}
#endif
#endif
