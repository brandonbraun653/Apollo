/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_CORE_CM_CORE_H
#define CSLR_CORE_CM_CORE_H

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
    volatile Uint32 CM_L3MAIN1_CLKSTCTRL_REG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 CM_L3MAIN1_DYNAMICDEP_REG;
    volatile Uint8  RSVD1[20];
    volatile Uint32 CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG;
    volatile Uint8  RSVD2[4];
    volatile Uint32 CM_L3MAIN1_GPMC_CLKCTRL_REG;
    volatile Uint8  RSVD3[4];
    volatile Uint32 CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG;
    volatile Uint8  RSVD4[20];
    volatile Uint32 CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG;
    volatile Uint8  RSVD5[4];
    volatile Uint32 CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG;
    volatile Uint8  RSVD6[4];
    volatile Uint32 CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG;
    volatile Uint8  RSVD7[4];
    volatile Uint32 CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG;
    volatile Uint8  RSVD8[4];
    volatile Uint32 CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG;
    volatile Uint8  RSVD9[4];
    volatile Uint32 CM_L3MAIN1_TPCC_CLKCTRL_REG;
    volatile Uint8  RSVD10[4];
    volatile Uint32 CM_L3MAIN1_TPTC1_CLKCTRL_REG;
    volatile Uint8  RSVD11[4];
    volatile Uint32 CM_L3MAIN1_TPTC2_CLKCTRL_REG;
    volatile Uint8  RSVD12[4];
    volatile Uint32 CM_L3MAIN1_VCP1_CLKCTRL_REG;
    volatile Uint8  RSVD13[4];
    volatile Uint32 CM_L3MAIN1_VCP2_CLKCTRL_REG;
    volatile Uint8  RSVD14[4];
    volatile Uint32 CM_L3MAIN1_SPARE_CME_CLKCTRL_REG;
    volatile Uint8  RSVD15[4];
    volatile Uint32 CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG;
    volatile Uint8  RSVD16[4];
    volatile Uint32 CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG;
    volatile Uint8  RSVD17[4];
    volatile Uint32 CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG;
    volatile Uint8  RSVD18[4];
    volatile Uint32 CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG;
    volatile Uint8  RSVD19[4];
    volatile Uint32 CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG;
    volatile Uint8  RSVD20[4];
    volatile Uint32 CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG;
    volatile Uint8  RSVD21[4];
    volatile Uint32 CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG;
    volatile Uint8  RSVD22[4];
    volatile Uint32 CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG;
    volatile Uint8  RSVD23[20];
    volatile Uint32 CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG;
    volatile Uint8  RSVD24[4];
    volatile Uint32 CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG;
    volatile Uint8  RSVD25[260];
    volatile Uint32 CM_IPU2_CLKSTCTRL_REG;
    volatile Uint32 CM_IPU2_STATICDEP_REG;
    volatile Uint32 CM_IPU2_DYNAMICDEP_REG;
    volatile Uint8  RSVD26[20];
    volatile Uint32 CM_IPU2_IPU2_CLKCTRL_REG;
    volatile Uint8  RSVD27[220];
    volatile Uint32 CM_DMA_CLKSTCTRL_REG;
    volatile Uint32 CM_DMA_STATICDEP_REG;
    volatile Uint32 CM_DMA_DYNAMICDEP_REG;
    volatile Uint8  RSVD28[20];
    volatile Uint32 CM_DMA_DMA_SYSTEM_CLKCTRL_REG;
    volatile Uint8  RSVD29[220];
    volatile Uint32 CM_EMIF_CLKSTCTRL_REG;
    volatile Uint8  RSVD30[28];
    volatile Uint32 CM_EMIF_DMM_CLKCTRL_REG;
    volatile Uint8  RSVD31[4];
    volatile Uint32 CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG;
    volatile Uint8  RSVD32[4];
    volatile Uint32 CM_EMIF_EMIF1_CLKCTRL_REG;
    volatile Uint8  RSVD33[4];
    volatile Uint32 CM_EMIF_EMIF2_CLKCTRL_REG;
    volatile Uint8  RSVD34[4];
    volatile Uint32 CM_EMIF_EMIF_DLL_CLKCTRL_REG;
    volatile Uint8  RSVD35[188];
    volatile Uint32 CM_ATL_ATL_CLKCTRL_REG;
    volatile Uint8  RSVD36[28];
    volatile Uint32 CM_ATL_CLKSTCTRL_REG;
    volatile Uint8  RSVD37[220];
    volatile Uint32 CM_L4CFG_CLKSTCTRL_REG;
    volatile Uint8  RSVD38[4];
    volatile Uint32 CM_L4CFG_DYNAMICDEP_REG;
    volatile Uint8  RSVD39[20];
    volatile Uint32 CM_L4CFG_L4_CFG_CLKCTRL_REG;
    volatile Uint8  RSVD40[4];
    volatile Uint32 CM_L4CFG_SPINLOCK_CLKCTRL_REG;
    volatile Uint8  RSVD41[4];
    volatile Uint32 CM_L4CFG_MAILBOX1_CLKCTRL_REG;
    volatile Uint8  RSVD42[4];
    volatile Uint32 CM_L4CFG_SAR_ROM_CLKCTRL_REG;
    volatile Uint8  RSVD43[4];
    volatile Uint32 CM_L4CFG_OCP2SCP2_CLKCTRL_REG;
    volatile Uint8  RSVD44[4];
    volatile Uint32 CM_L4CFG_MAILBOX2_CLKCTRL_REG;
    volatile Uint8  RSVD45[4];
    volatile Uint32 CM_L4CFG_MAILBOX3_CLKCTRL_REG;
    volatile Uint8  RSVD46[4];
    volatile Uint32 CM_L4CFG_MAILBOX4_CLKCTRL_REG;
    volatile Uint8  RSVD47[4];
    volatile Uint32 CM_L4CFG_MAILBOX5_CLKCTRL_REG;
    volatile Uint8  RSVD48[4];
    volatile Uint32 CM_L4CFG_MAILBOX6_CLKCTRL_REG;
    volatile Uint8  RSVD49[4];
    volatile Uint32 CM_L4CFG_MAILBOX7_CLKCTRL_REG;
    volatile Uint8  RSVD50[4];
    volatile Uint32 CM_L4CFG_MAILBOX8_CLKCTRL_REG;
    volatile Uint8  RSVD51[4];
    volatile Uint32 CM_L4CFG_MAILBOX9_CLKCTRL_REG;
    volatile Uint8  RSVD52[4];
    volatile Uint32 CM_L4CFG_MAILBOX10_CLKCTRL_REG;
    volatile Uint8  RSVD53[4];
    volatile Uint32 CM_L4CFG_MAILBOX11_CLKCTRL_REG;
    volatile Uint8  RSVD54[4];
    volatile Uint32 CM_L4CFG_MAILBOX12_CLKCTRL_REG;
    volatile Uint8  RSVD55[4];
    volatile Uint32 CM_L4CFG_MAILBOX13_CLKCTRL_REG;
    volatile Uint8  RSVD56[4];
    volatile Uint32 CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG;
    volatile Uint8  RSVD57[4];
    volatile Uint32 CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG;
    volatile Uint8  RSVD58[4];
    volatile Uint32 CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG;
    volatile Uint8  RSVD59[4];
    volatile Uint32 CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG;
    volatile Uint8  RSVD60[60];
    volatile Uint32 CM_L3INSTR_CLKSTCTRL_REG;
    volatile Uint8  RSVD61[28];
    volatile Uint32 CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG;
    volatile Uint8  RSVD62[4];
    volatile Uint32 CM_L3INSTR_L3_INSTR_CLKCTRL_REG;
    volatile Uint8  RSVD63[20];
    volatile Uint32 CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG;
    volatile Uint8  RSVD64[4];
    volatile Uint32 CM_L3INSTR_DLL_AGING_CLKCTRL_REG;
    volatile Uint8  RSVD65[4];
    volatile Uint32 CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG;
} CSL_core_cm_coreRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG               (0x0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG)


/* This register controls the dynamic domain depedencies from L3MAIN1 domain
 * towards 'target' domains. It is relevant only for domain having OCP master
 * port(s). */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG              (0x8U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP  (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG)


/* This register manages the L3_MAIN_1 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG       (0x20U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG)


/* This register manages the GPMC clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG            (0x28U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG)


/* This register manages the MMU_L4_EDMA clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG        (0x30U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG)


/* This register manages the MMU_L4_PCIESS clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG      (0x48U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG)


/* This register manages the OCMC_RAM1 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG       (0x50U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG)


/* This register manages the OCMC_RAM2 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG       (0x58U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG)


/* This register manages the OCMC_RAM3 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG       (0x60U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG)


/* This register manages the OCMC_RAM clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG        (0x68U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG)


/* This register manages the TPCC clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG            (0x70U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG)


/* This register manages the TPTC1 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG           (0x78U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG)


/* This register manages the TPTC2 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG           (0x80U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG)


/* This register manages the VCP1 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG            (0x88U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG)


/* This register manages the VCP2 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG            (0x90U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG)


/* This register manages the SPARE_CME clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG       (0x98U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG)


/* This register manages the SPARE_HDMI clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG      (0xA0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG)


/* This register manages the SPARE_ICM clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG       (0xA8U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG)


/* This register manages the SPARE_IVA2 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG      (0xB0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG)


/* This register manages the SPARE_SATA2 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG     (0xB8U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG)


/* This register manages the SPARE_UNKNOWN4 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG  (0xC0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG)


/* This register manages the SPARE_UNKNOWN5 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG  (0xC8U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG)


/* This register manages the SPARE_UNKNOWN6 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG  (0xD0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG)


/* This register manages the SPARE_VIDEOPLL1 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG  (0xD8U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG)


/* This register manages the SPARE_VIDEOPLL2 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG  (0xF0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG)


/* This register manages the SPARE_VIDEOPLL3 clocks. */
#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG  (0xF8U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG)


/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG                  (0x200U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL    (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG)


/* This register controls the static domain depedencies from IPU domain
 * towards 'target' domains. It is relevant only for domain having system
 * initiator(s). */
#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG                  (0x204U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP    (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG)


/* This register controls the dynamic domain depedencies from IPU domain
 * towards 'target' domains. It is relevant only for domain having OCP master
 * port(s). */
#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG                 (0x208U)
/* Below define for backward compatibility */
#define CM_IPU2_DYNAMICDEP   (CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG)


/* This register manages the IPU2 clocks. */
#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG               (0x220U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL  (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG)


/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG                   (0x300U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL     (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG)


/* This register controls the static domain depedencies from DMA domain
 * towards 'target' domains. It is relevant only for domain having system
 * initiator(s). */
#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG                   (0x304U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP     (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG)


/* This register controls the dynamic domain depedencies from SDMA domain
 * towards 'target' domains. It is relevant only for domain having OCP master
 * port(s). */
#define CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG                  (0x308U)
/* Below define for backward compatibility */
#define CM_DMA_DYNAMICDEP    (CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG)


/* This register manages the DMA_SYSTEM clocks. */
#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG          (0x320U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL  (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG)


/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG                  (0x400U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL    (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG)


/* This register manages the DMM clocks. */
#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG                (0x420U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL  (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG)


/* This register manages the EMIF_OCP_FW clocks. */
#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG        (0x428U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL  (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG)


/* This register manages the EMIF1 clocks. */
#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG              (0x430U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL  (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG)


/* This register manages the EMIF2 clocks. */
#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG              (0x438U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL  (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG)


/* This register manages the DLL clock. */
#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG           (0x440U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_DLL_CLKCTRL  (CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG)


/* This register manages the ATL clocks. */
#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG                 (0x500U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL   (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG)


/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG                   (0x520U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL     (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG)


/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG                 (0x600U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL   (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG)


/* This register controls the dynamic domain depedencies from L4CFG domain
 * towards 'target' domains. It is relevant only for domain having OCP master
 * port(s). */
#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG                (0x608U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP  (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG)


/* This register manages the L4_CFG clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG            (0x620U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG)


/* This register manages the SPINLOCK clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG          (0x628U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG)


/* This register manages the MAILBOX1 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG          (0x630U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG)


/* This register manages the SAR_ROM clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG           (0x638U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG)


/* This register manages the OCP2SCP2 clocks and the optional clock of USB
 * PHY. */
#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG          (0x640U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG)


/* This register manages the MAILBOX2 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG          (0x648U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG)


/* This register manages the MAILBOX3 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG          (0x650U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG)


/* This register manages the MAILBOX4 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG          (0x658U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG)


/* This register manages the MAILBOX5 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG          (0x660U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG)


/* This register manages the MAILBOX6 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG          (0x668U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG)


/* This register manages the MAILBOX7 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG          (0x670U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG)


/* This register manages the MAILBOX8 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG          (0x678U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG)


/* This register manages the MAILBOX9 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG          (0x680U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG)


/* This register manages the MAILBOX10 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG         (0x688U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG)


/* This register manages the MAILBOX11 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG         (0x690U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG)


/* This register manages the MAILBOX12 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG         (0x698U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG)


/* This register manages the MAILBOX13 clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG         (0x6A0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG)


/* This register manages the SPARE_SMARTREFLEX_RTC clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG  (0x6A8U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG)


/* This register manages the SPARE_SMARTREFLEX_SDRAM clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG  (0x6B0U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG)


/* This register manages the SPARE_SMARTREFLEX_WKUP clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG  (0x6B8U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG)


/* This register manages the IO_DELAY_BLOCK clocks. */
#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG    (0x6C0U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL  (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG)


/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG               (0x700U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG)


/* This register manages the L3_MAIN_2 clocks. [warm reset insensitive] */
#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG       (0x720U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG)


/* This register manages the L3 INSTRUMENTATION clocks. [warm reset
 * insensitive] */
#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG        (0x728U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG)


/* This register manages the OCP_WP_NOC clocks. [warm reset insensitive] */
#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG      (0x740U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG)


/* This register manages the DLL_AGING clocks. */
#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG       (0x748U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG)


/* This register manages the CTRL_MODULE_BANDGAP clock. */
#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG  (0x750U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CM_L3MAIN1_CLKSTCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKTRCTRL_MASK           (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKTRCTRL_SHIFT          (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKTRCTRL_NO_SLEEP       (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKTRCTRL_RESERVED_1     (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKTRCTRL_RESERVED_2     (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKTRCTRL_HW_AUTO        (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L3_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKACTIVITY_L3MAIN1_L3_GICLK_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L3_GICLK_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L3_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKACTIVITY_L3MAIN1_L3_GICLK_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L3_GICLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKACTIVITY_L3MAIN1_L3_GICLK_INACT  (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L3_GICLK_INACT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKACTIVITY_L3MAIN1_L3_GICLK_ACT  (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L3_GICLK_ACT)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L4_GICLK_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKACTIVITY_L3MAIN1_L4_GICLK_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L4_GICLK_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L4_GICLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L4_GICLK_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKACTIVITY_L3MAIN1_L4_GICLK_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L4_GICLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L4_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKACTIVITY_L3MAIN1_L4_GICLK_INACT  (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L4_GICLK_INACT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L4_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_CLKSTCTRL_CLKACTIVITY_L3MAIN1_L4_GICLK_ACT  (CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_CLKACTIVITY_L3MAIN1_L4_GICLK_ACT)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_CLKSTCTRL_REG_RESETVAL      (0x00000000U)

/* CM_L3MAIN1_DYNAMICDEP_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EMIF_DYNDEP_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EMIF_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EMIF_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EMIF_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EMIF_DYNDEP_SHIFT  (4U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EMIF_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EMIF_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EMIF_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EMIF_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EMIF_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WINDOWSIZE_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_WINDOWSIZE_MASK         (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WINDOWSIZE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WINDOWSIZE_RESETVAL  (0x00000004U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WINDOWSIZE_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_WINDOWSIZE_SHIFT        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WINDOWSIZE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WINDOWSIZE_MAX  (0x0000000fU)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4CFG_DYNDEP_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4CFG_DYNDEP_MASK       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4CFG_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4CFG_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4CFG_DYNDEP_SHIFT  (12U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4CFG_DYNDEP_SHIFT      (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4CFG_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4CFG_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4CFG_DYNDEP_ENABLED    (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4CFG_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WKUPAON_DYNDEP_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_WKUPAON_DYNDEP_MASK     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WKUPAON_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WKUPAON_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WKUPAON_DYNDEP_SHIFT  (15U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_WKUPAON_DYNDEP_SHIFT    (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WKUPAON_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WKUPAON_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_WKUPAON_DYNDEP_ENABLED  (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_WKUPAON_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU2_DYNDEP_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IPU2_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU2_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU2_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU2_DYNDEP_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IPU2_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU2_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU2_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IPU2_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU2_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP1_DYNDEP_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_DSP1_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP1_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP1_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP1_DYNDEP_SHIFT  (1U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_DSP1_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP1_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP1_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_DSP1_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP1_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP2_DYNDEP_MASK  (0x00100000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_DSP2_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP2_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP2_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP2_DYNDEP_SHIFT  (20U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_DSP2_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP2_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP2_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_DSP2_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSP2_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSS_DYNDEP_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_DSS_DYNDEP_MASK         (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSS_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSS_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSS_DYNDEP_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_DSS_DYNDEP_SHIFT        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSS_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSS_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_DSS_DYNDEP_ENABLED      (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_DSS_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE1_DYNDEP_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE1_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE1_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE1_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE1_DYNDEP_SHIFT  (28U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE1_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE1_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE1_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE1_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE1_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE2_DYNDEP_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE2_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE2_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE2_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE2_DYNDEP_SHIFT  (29U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE2_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE2_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE2_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE2_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE2_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE3_DYNDEP_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE3_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE3_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE3_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE3_DYNDEP_SHIFT  (30U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE3_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE3_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE3_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE3_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE3_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE4_DYNDEP_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE4_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE4_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE4_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE4_DYNDEP_SHIFT  (31U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE4_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE4_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE4_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_EVE4_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_EVE4_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_GPU_DYNDEP_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_GPU_DYNDEP_MASK         (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_GPU_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_GPU_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_GPU_DYNDEP_SHIFT  (10U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_GPU_DYNDEP_SHIFT        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_GPU_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_GPU_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_GPU_DYNDEP_ENABLED      (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_GPU_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU1_DYNDEP_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IPU1_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU1_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU1_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU1_DYNDEP_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IPU1_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU1_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU1_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IPU1_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU1_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU_DYNDEP_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IPU_DYNDEP_MASK         (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU_DYNDEP_SHIFT  (3U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IPU_DYNDEP_SHIFT        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IPU_DYNDEP_ENABLED      (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IPU_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IVA_DYNDEP_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IVA_DYNDEP_MASK         (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IVA_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IVA_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IVA_DYNDEP_SHIFT  (2U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IVA_DYNDEP_SHIFT        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IVA_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IVA_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_IVA_DYNDEP_ENABLED      (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_IVA_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER_DYNDEP_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4PER_DYNDEP_MASK       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER_DYNDEP_SHIFT  (13U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4PER_DYNDEP_SHIFT      (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4PER_DYNDEP_ENABLED    (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER2_DYNDEP_MASK  (0x00400000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4PER2_DYNDEP_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER2_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER2_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER2_DYNDEP_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4PER2_DYNDEP_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER2_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER2_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4PER2_DYNDEP_ENABLED   (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER2_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER3_DYNDEP_MASK  (0x00800000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4PER3_DYNDEP_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER3_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER3_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER3_DYNDEP_SHIFT  (23U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4PER3_DYNDEP_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER3_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER3_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4PER3_DYNDEP_ENABLED   (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4PER3_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4SEC_DYNDEP_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4SEC_DYNDEP_MASK       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4SEC_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4SEC_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4SEC_DYNDEP_SHIFT  (14U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4SEC_DYNDEP_SHIFT      (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4SEC_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4SEC_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_L4SEC_DYNDEP_ENABLED    (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_L4SEC_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_PCIE_DYNDEP_MASK  (0x00200000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_PCIE_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_PCIE_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_PCIE_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_PCIE_DYNDEP_SHIFT  (21U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_PCIE_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_PCIE_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_PCIE_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_DYNAMICDEP_PCIE_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_PCIE_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_DYNAMICDEP_REG_RESETVAL     (0xf4f4f51fU)

/* CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL_IDLEST_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL_IDLEST_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL_IDLEST_DISABLE   (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL_IDLEST_IDLE      (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL_IDLEST_FUNC      (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_L3_MAIN_1_CLKCTRL_IDLEST_TRANS     (CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_GPMC_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_IDLEST_MASK           (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_IDLEST_SHIFT          (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_IDLEST_DISABLE        (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_IDLEST_IDLE           (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_IDLEST_FUNC           (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_IDLEST_TRANS          (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_MODULEMODE_MASK       (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_MODULEMODE_SHIFT      (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_MODULEMODE_DISABLED   (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_MODULEMODE_AUTO       (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_GPMC_CLKCTRL_MODULEMODE_RESERVED   (CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_GPMC_CLKCTRL_REG_RESETVAL   (0x00030001U)

/* CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL_MODULEMODE_MASK   (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL_MODULEMODE_AUTO   (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL_IDLEST_MASK       (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL_IDLEST_SHIFT      (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL_IDLEST_DISABLE    (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL_IDLEST_IDLE       (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL_IDLEST_FUNC       (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_EDMA_CLKCTRL_IDLEST_TRANS      (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_EDMA_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL_IDLEST_MASK     (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL_IDLEST_SHIFT    (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL_IDLEST_IDLE     (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL_IDLEST_FUNC     (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_MMU_PCIESS_CLKCTRL_IDLEST_TRANS    (CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_MMU_PCIESS_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL_IDLEST_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL_IDLEST_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL_IDLEST_DISABLE   (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL_IDLEST_IDLE      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL_IDLEST_FUNC      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM1_CLKCTRL_IDLEST_TRANS     (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM1_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL_IDLEST_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL_IDLEST_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL_IDLEST_DISABLE   (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL_IDLEST_IDLE      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL_IDLEST_FUNC      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM2_CLKCTRL_IDLEST_TRANS     (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM2_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL_IDLEST_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL_IDLEST_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL_IDLEST_DISABLE   (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL_IDLEST_IDLE      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL_IDLEST_FUNC      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_RAM3_CLKCTRL_IDLEST_TRANS     (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_RAM3_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL_MODULEMODE_MASK   (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL_MODULEMODE_AUTO   (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL_IDLEST_MASK       (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL_IDLEST_SHIFT      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL_IDLEST_DISABLE    (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL_IDLEST_IDLE       (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL_IDLEST_FUNC       (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_OCMC_ROM_CLKCTRL_IDLEST_TRANS      (CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_OCMC_ROM_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_TPCC_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL_MODULEMODE_MASK       (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL_MODULEMODE_SHIFT      (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL_MODULEMODE_AUTO       (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL_IDLEST_MASK           (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL_IDLEST_SHIFT          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL_IDLEST_DISABLE        (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL_IDLEST_IDLE           (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL_IDLEST_FUNC           (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPCC_CLKCTRL_IDLEST_TRANS          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPCC_CLKCTRL_REG_RESETVAL   (0x00030001U)

/* CM_L3MAIN1_TPTC1_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_STBYST_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_STBYST_MASK          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_STBYST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_STBYST_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_STBYST_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_STBYST_SHIFT         (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_STBYST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_STBYST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_STBYST_FUNC          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_STBYST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_STBYST_STANDBY  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_STBYST_STANDBY       (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_STBYST_STANDBY)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_IDLEST_MASK          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_IDLEST_SHIFT         (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_IDLEST_DISABLE       (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_IDLEST_IDLE          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_IDLEST_FUNC          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_IDLEST_TRANS         (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_MODULEMODE_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_MODULEMODE_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_MODULEMODE_DISABLED  (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_MODULEMODE_AUTO      (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC1_CLKCTRL_MODULEMODE_RESERVED  (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC1_CLKCTRL_REG_RESETVAL  (0x00070000U)

/* CM_L3MAIN1_TPTC2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_STBYST_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_STBYST_MASK          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_STBYST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_STBYST_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_STBYST_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_STBYST_SHIFT         (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_STBYST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_STBYST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_STBYST_FUNC          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_STBYST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_STBYST_STANDBY  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_STBYST_STANDBY       (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_STBYST_STANDBY)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_IDLEST_MASK          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_IDLEST_SHIFT         (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_IDLEST_DISABLE       (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_IDLEST_IDLE          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_IDLEST_FUNC          (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_IDLEST_TRANS         (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_MODULEMODE_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_MODULEMODE_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_MODULEMODE_DISABLED  (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_MODULEMODE_AUTO      (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_TPTC2_CLKCTRL_MODULEMODE_RESERVED  (CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_TPTC2_CLKCTRL_REG_RESETVAL  (0x00070000U)

/* CM_L3MAIN1_VCP1_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL_MODULEMODE_MASK       (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL_MODULEMODE_SHIFT      (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL_MODULEMODE_AUTO       (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL_IDLEST_MASK           (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL_IDLEST_SHIFT          (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL_IDLEST_DISABLE        (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL_IDLEST_IDLE           (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL_IDLEST_FUNC           (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP1_CLKCTRL_IDLEST_TRANS          (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP1_CLKCTRL_REG_RESETVAL   (0x00030001U)

/* CM_L3MAIN1_VCP2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL_MODULEMODE_MASK       (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL_MODULEMODE_SHIFT      (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL_MODULEMODE_AUTO       (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL_IDLEST_MASK           (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL_IDLEST_SHIFT          (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL_IDLEST_DISABLE        (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL_IDLEST_IDLE           (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL_IDLEST_FUNC           (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_VCP2_CLKCTRL_IDLEST_TRANS          (CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_VCP2_CLKCTRL_REG_RESETVAL   (0x00030001U)

/* CM_L3MAIN1_SPARE_CME_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL_IDLEST_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL_IDLEST_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL_IDLEST_DISABLE   (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL_IDLEST_IDLE      (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL_IDLEST_FUNC      (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL_IDLEST_TRANS     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_CME_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_CME_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL_IDLEST_MASK     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL_IDLEST_SHIFT    (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL_IDLEST_IDLE     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL_IDLEST_FUNC     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL_IDLEST_TRANS    (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_HDMI_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_HDMI_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL_IDLEST_MASK      (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL_IDLEST_SHIFT     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL_IDLEST_DISABLE   (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL_IDLEST_IDLE      (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL_IDLEST_FUNC      (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL_IDLEST_TRANS     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_ICM_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_ICM_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL_IDLEST_MASK     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL_IDLEST_SHIFT    (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL_IDLEST_IDLE     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL_IDLEST_FUNC     (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL_IDLEST_TRANS    (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_IVA2_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_IVA2_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL_IDLEST_MASK    (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL_IDLEST_SHIFT   (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL_IDLEST_IDLE    (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL_IDLEST_FUNC    (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL_IDLEST_TRANS   (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_SATA2_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_SATA2_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN4_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN5_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_UNKNOWN6_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL1_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL2_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3MAIN1_SPARE_VIDEOPLL3_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_IPU2_CLKSTCTRL_REG */

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_MASK   (0x00000003U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKTRCTRL_MASK              (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKTRCTRL_SHIFT             (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKTRCTRL_NO_SLEEP          (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKTRCTRL_SW_SLEEP          (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_SW_SLEEP)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKTRCTRL_SW_WKUP           (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKTRCTRL_HW_AUTO           (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKACTIVITY_IPU2_GFCLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKACTIVITY_IPU2_GFCLK_MASK  (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKACTIVITY_IPU2_GFCLK_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKACTIVITY_IPU2_GFCLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKACTIVITY_IPU2_GFCLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKACTIVITY_IPU2_GFCLK_SHIFT  (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKACTIVITY_IPU2_GFCLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKACTIVITY_IPU2_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKACTIVITY_IPU2_GFCLK_INACT  (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKACTIVITY_IPU2_GFCLK_INACT)

#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKACTIVITY_IPU2_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_CLKSTCTRL_CLKACTIVITY_IPU2_GFCLK_ACT  (CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_CLKACTIVITY_IPU2_GFCLK_ACT)


#define CSL_CORE_CM_CORE_CM_IPU2_CLKSTCTRL_REG_RESETVAL         (0x00000003U)

/* CM_IPU2_STATICDEP_REG */

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP1_STATDEP_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSP1_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP1_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP1_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP1_STATDEP_SHIFT  (1U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSP1_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP1_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSP1_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP1_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP1_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSP1_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP1_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IVA_STATDEP_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IVA_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IVA_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IVA_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IVA_STATDEP_SHIFT  (2U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IVA_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IVA_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IVA_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IVA_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IVA_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IVA_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IVA_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IVA_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EMIF_STATDEP_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EMIF_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EMIF_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EMIF_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EMIF_STATDEP_SHIFT  (4U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EMIF_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EMIF_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EMIF_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EMIF_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EMIF_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EMIF_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EMIF_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EMIF_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3MAIN1_STATDEP_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L3MAIN1_STATDEP_MASK        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3MAIN1_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3MAIN1_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3MAIN1_STATDEP_SHIFT  (5U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L3MAIN1_STATDEP_SHIFT       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3MAIN1_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3MAIN1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L3MAIN1_STATDEP_ENABLED     (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3MAIN1_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3MAIN1_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L3MAIN1_STATDEP_DISABLED    (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3MAIN1_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3INIT_STATDEP_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L3INIT_STATDEP_MASK         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3INIT_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3INIT_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3INIT_STATDEP_SHIFT  (7U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L3INIT_STATDEP_SHIFT        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3INIT_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3INIT_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L3INIT_STATDEP_ENABLED      (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3INIT_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3INIT_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L3INIT_STATDEP_DISABLED     (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L3INIT_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSS_STATDEP_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSS_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSS_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSS_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSS_STATDEP_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSS_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSS_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSS_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSS_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSS_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSS_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSS_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSS_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CAM_STATDEP_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_CAM_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CAM_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CAM_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CAM_STATDEP_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_CAM_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CAM_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CAM_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_CAM_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CAM_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GPU_STATDEP_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_GPU_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GPU_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GPU_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GPU_STATDEP_SHIFT  (10U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_GPU_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GPU_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GPU_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_GPU_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GPU_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GPU_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_GPU_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GPU_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4CFG_STATDEP_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4CFG_STATDEP_MASK          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4CFG_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4CFG_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4CFG_STATDEP_SHIFT  (12U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4CFG_STATDEP_SHIFT         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4CFG_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4CFG_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4CFG_STATDEP_ENABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4CFG_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4CFG_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4CFG_STATDEP_DISABLED      (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4CFG_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER_STATDEP_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER_STATDEP_MASK          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER_STATDEP_SHIFT  (13U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER_STATDEP_SHIFT         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER_STATDEP_ENABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER_STATDEP_DISABLED      (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4SEC_STATDEP_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4SEC_STATDEP_MASK          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4SEC_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4SEC_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4SEC_STATDEP_SHIFT  (14U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4SEC_STATDEP_SHIFT         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4SEC_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4SEC_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4SEC_STATDEP_ENABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4SEC_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4SEC_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4SEC_STATDEP_DISABLED      (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4SEC_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_COREAON_STATDEP_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_COREAON_STATDEP_MASK        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_COREAON_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_COREAON_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_COREAON_STATDEP_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_COREAON_STATDEP_SHIFT       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_COREAON_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_COREAON_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_COREAON_STATDEP_DISABLED    (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_COREAON_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CUSTEFUSE_STATDEP_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_CUSTEFUSE_STATDEP_MASK      (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CUSTEFUSE_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CUSTEFUSE_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CUSTEFUSE_STATDEP_SHIFT  (17U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_CUSTEFUSE_STATDEP_SHIFT     (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CUSTEFUSE_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CUSTEFUSE_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_CUSTEFUSE_STATDEP_DISABLED  (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_CUSTEFUSE_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_SDMA_STATDEP_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_SDMA_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_SDMA_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_SDMA_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_SDMA_STATDEP_SHIFT  (11U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_SDMA_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_SDMA_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_SDMA_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_SDMA_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_SDMA_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_WKUPAON_STATDEP_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_WKUPAON_STATDEP_MASK        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_WKUPAON_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_WKUPAON_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_WKUPAON_STATDEP_SHIFT  (15U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_WKUPAON_STATDEP_SHIFT       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_WKUPAON_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_WKUPAON_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_WKUPAON_STATDEP_ENABLED     (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_WKUPAON_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_WKUPAON_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_WKUPAON_STATDEP_DISABLED    (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_WKUPAON_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_ATL_STATDEP_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_ATL_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_ATL_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_ATL_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_ATL_STATDEP_SHIFT  (30U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_ATL_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_ATL_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_ATL_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_ATL_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_ATL_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_ATL_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_ATL_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_ATL_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP2_STATDEP_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSP2_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP2_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP2_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP2_STATDEP_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSP2_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP2_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP2_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSP2_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP2_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP2_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_DSP2_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_DSP2_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE1_STATDEP_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE1_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE1_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE1_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE1_STATDEP_SHIFT  (19U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE1_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE1_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE1_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE1_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE1_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE1_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE1_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE3_STATDEP_MASK  (0x00200000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE3_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE3_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE3_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE3_STATDEP_SHIFT  (21U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE3_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE3_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE3_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE3_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE3_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE3_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE3_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE3_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE2_STATDEP_MASK  (0x00100000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE2_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE2_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE2_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE2_STATDEP_SHIFT  (20U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE2_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE2_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE2_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE2_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE2_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE2_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE2_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE2_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE4_STATDEP_MASK  (0x00400000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE4_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE4_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE4_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE4_STATDEP_SHIFT  (22U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE4_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE4_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE4_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE4_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE4_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE4_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_EVE4_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_EVE4_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU1_STATDEP_MASK  (0x00800000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IPU1_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU1_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU1_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU1_STATDEP_SHIFT  (23U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IPU1_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU1_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IPU1_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU1_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU1_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IPU1_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU1_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU_STATDEP_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IPU_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU_STATDEP_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IPU_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IPU_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_IPU_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_IPU_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GMAC_STATDEP_MASK  (0x02000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_GMAC_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GMAC_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GMAC_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GMAC_STATDEP_SHIFT  (25U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_GMAC_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GMAC_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GMAC_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_GMAC_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GMAC_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GMAC_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_GMAC_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_GMAC_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER3_STATDEP_MASK  (0x08000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER3_STATDEP_MASK         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER3_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER3_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER3_STATDEP_SHIFT  (27U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER3_STATDEP_SHIFT        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER3_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER3_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER3_STATDEP_ENABLED      (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER3_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER3_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER3_STATDEP_DISABLED     (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER3_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER2_STATDEP_MASK  (0x04000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER2_STATDEP_MASK         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER2_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER2_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER2_STATDEP_SHIFT  (26U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER2_STATDEP_SHIFT        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER2_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER2_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER2_STATDEP_ENABLED      (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER2_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER2_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_L4PER2_STATDEP_DISABLED     (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_L4PER2_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_PCIE_STATDEP_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_PCIE_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_PCIE_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_PCIE_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_PCIE_STATDEP_SHIFT  (29U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_PCIE_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_PCIE_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_PCIE_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_PCIE_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_PCIE_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_PCIE_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_PCIE_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_PCIE_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_VPE_STATDEP_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_VPE_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_VPE_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_VPE_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_VPE_STATDEP_SHIFT  (28U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_VPE_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_VPE_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_VPE_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_VPE_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_VPE_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_VPE_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_STATICDEP_VPE_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_VPE_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_STATICDEP_REG_RESETVAL         (0x70009030U)

/* CM_IPU2_DYNAMICDEP_REG */

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define CM_IPU2_DYNAMICDEP_L3MAIN1_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_L3MAIN1_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT  (5U)
/* Below define for backward compatibility */
#define CM_IPU2_DYNAMICDEP_L3MAIN1_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_L3MAIN1_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_DYNAMICDEP_L3MAIN1_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_L3MAIN1_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_CAM_DYNDEP_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_IPU2_DYNAMICDEP_CAM_DYNDEP_MASK            (CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_CAM_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_CAM_DYNDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_CAM_DYNDEP_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_IPU2_DYNAMICDEP_CAM_DYNDEP_SHIFT           (CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_CAM_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_CAM_DYNDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_DYNAMICDEP_CAM_DYNDEP_DISABLED        (CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_CAM_DYNDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_WINDOWSIZE_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_IPU2_DYNAMICDEP_WINDOWSIZE_MASK            (CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_WINDOWSIZE_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_WINDOWSIZE_RESETVAL  (0x00000004U)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_WINDOWSIZE_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_IPU2_DYNAMICDEP_WINDOWSIZE_SHIFT           (CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_WINDOWSIZE_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_WINDOWSIZE_MAX  (0x0000000fU)

#define CSL_CORE_CM_CORE_CM_IPU2_DYNAMICDEP_REG_RESETVAL        (0x04000020U)

/* CM_IPU2_IPU2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_STBYST_MASK   (0x00040000U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_STBYST_MASK              (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_STBYST_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_STBYST_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_STBYST_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_STBYST_SHIFT             (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_STBYST_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_STBYST_FUNC   (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_STBYST_FUNC              (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_STBYST_FUNC)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_STBYST_STANDBY  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_STBYST_STANDBY           (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_STBYST_STANDBY)


#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_MASK   (0x00030000U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_IDLEST_MASK              (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_IDLEST_SHIFT             (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_IDLEST_DISABLE           (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_IDLE   (0x00000002U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_IDLEST_IDLE              (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_FUNC   (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_IDLEST_FUNC              (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_IDLEST_TRANS             (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_MODULEMODE_MASK          (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_MODULEMODE_SHIFT         (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_MODULEMODE_DISABLED      (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_MODULEMODE_AUTO          (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_MODULEMODE_RESERVED_2    (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_IPU2_IPU2_CLKCTRL_MODULEMODE_RESERVED      (CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_IPU2_IPU2_CLKCTRL_REG_RESETVAL      (0x00070000U)

/* CM_DMA_CLKSTCTRL_REG */

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_MASK    (0x00000003U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKTRCTRL_MASK               (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_SHIFT   (0U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKTRCTRL_SHIFT              (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKTRCTRL_NO_SLEEP           (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKTRCTRL_RESERVED_1         (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKTRCTRL_SW_WKUP            (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKTRCTRL_HW_AUTO            (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKACTIVITY_DMA_L3_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKACTIVITY_DMA_L3_GICLK_MASK  (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKACTIVITY_DMA_L3_GICLK_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKACTIVITY_DMA_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKACTIVITY_DMA_L3_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKACTIVITY_DMA_L3_GICLK_SHIFT  (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKACTIVITY_DMA_L3_GICLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKACTIVITY_DMA_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKACTIVITY_DMA_L3_GICLK_INACT  (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKACTIVITY_DMA_L3_GICLK_INACT)

#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKACTIVITY_DMA_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_CLKSTCTRL_CLKACTIVITY_DMA_L3_GICLK_ACT  (CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_CLKACTIVITY_DMA_L3_GICLK_ACT)


#define CSL_CORE_CM_CORE_CM_DMA_CLKSTCTRL_REG_RESETVAL          (0x00000003U)

/* CM_DMA_STATICDEP_REG */

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU2_STATDEP_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU2_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU2_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU2_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU2_STATDEP_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU2_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU2_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU2_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU2_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU2_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU2_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU2_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU2_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IVA_STATDEP_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IVA_STATDEP_MASK             (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IVA_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IVA_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IVA_STATDEP_SHIFT  (2U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IVA_STATDEP_SHIFT            (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IVA_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IVA_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IVA_STATDEP_ENABLED          (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IVA_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IVA_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IVA_STATDEP_DISABLED         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IVA_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU_STATDEP_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU_STATDEP_MASK             (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU_STATDEP_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU_STATDEP_SHIFT            (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU_STATDEP_ENABLED          (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU_STATDEP_DISABLED         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_EMIF_STATDEP_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_EMIF_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_EMIF_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_EMIF_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_EMIF_STATDEP_SHIFT  (4U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_EMIF_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_EMIF_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_EMIF_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_EMIF_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_EMIF_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_EMIF_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_EMIF_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_EMIF_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3MAIN1_STATDEP_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L3MAIN1_STATDEP_MASK         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3MAIN1_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3MAIN1_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3MAIN1_STATDEP_SHIFT  (5U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L3MAIN1_STATDEP_SHIFT        (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3MAIN1_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3MAIN1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L3MAIN1_STATDEP_ENABLED      (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3MAIN1_STATDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3INIT_STATDEP_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L3INIT_STATDEP_MASK          (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3INIT_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3INIT_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3INIT_STATDEP_SHIFT  (7U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L3INIT_STATDEP_SHIFT         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3INIT_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3INIT_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L3INIT_STATDEP_ENABLED       (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3INIT_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3INIT_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L3INIT_STATDEP_DISABLED      (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L3INIT_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_DSS_STATDEP_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_DSS_STATDEP_MASK             (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_DSS_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_DSS_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_DSS_STATDEP_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_DSS_STATDEP_SHIFT            (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_DSS_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_DSS_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_DSS_STATDEP_ENABLED          (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_DSS_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_DSS_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_DSS_STATDEP_DISABLED         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_DSS_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_CAM_STATDEP_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_CAM_STATDEP_MASK             (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_CAM_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_CAM_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_CAM_STATDEP_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_CAM_STATDEP_SHIFT            (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_CAM_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_CAM_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_CAM_STATDEP_DISABLED         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_CAM_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER_STATDEP_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER_STATDEP_SHIFT  (13U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4SEC_STATDEP_MASK  (0x00004000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4SEC_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4SEC_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4SEC_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4SEC_STATDEP_SHIFT  (14U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4SEC_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4SEC_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4SEC_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4SEC_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4SEC_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4SEC_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4SEC_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4SEC_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4CFG_STATDEP_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4CFG_STATDEP_MASK           (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4CFG_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4CFG_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4CFG_STATDEP_SHIFT  (12U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4CFG_STATDEP_SHIFT          (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4CFG_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4CFG_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4CFG_STATDEP_ENABLED        (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4CFG_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4CFG_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4CFG_STATDEP_DISABLED       (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4CFG_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_WKUPAON_STATDEP_MASK  (0x00008000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_WKUPAON_STATDEP_MASK         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_WKUPAON_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_WKUPAON_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_WKUPAON_STATDEP_SHIFT  (15U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_WKUPAON_STATDEP_SHIFT        (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_WKUPAON_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_WKUPAON_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_WKUPAON_STATDEP_ENABLED      (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_WKUPAON_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_WKUPAON_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_WKUPAON_STATDEP_DISABLED     (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_WKUPAON_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU1_STATDEP_MASK  (0x00800000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU1_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU1_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU1_STATDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU1_STATDEP_SHIFT  (23U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU1_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU1_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU1_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU1_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU1_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU1_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_IPU1_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_IPU1_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER2_STATDEP_MASK  (0x04000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER2_STATDEP_MASK          (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER2_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER2_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER2_STATDEP_SHIFT  (26U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER2_STATDEP_SHIFT         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER2_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER2_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER2_STATDEP_ENABLED       (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER2_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER2_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER2_STATDEP_DISABLED      (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER2_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER3_STATDEP_MASK  (0x08000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER3_STATDEP_MASK          (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER3_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER3_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER3_STATDEP_SHIFT  (27U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER3_STATDEP_SHIFT         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER3_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER3_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER3_STATDEP_ENABLED       (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER3_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER3_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_L4PER3_STATDEP_DISABLED      (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_L4PER3_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_PCIE_STATDEP_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_PCIE_STATDEP_MASK            (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_PCIE_STATDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_PCIE_STATDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_PCIE_STATDEP_SHIFT  (29U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_PCIE_STATDEP_SHIFT           (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_PCIE_STATDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_PCIE_STATDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_PCIE_STATDEP_ENABLED         (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_PCIE_STATDEP_ENABLED)

#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_PCIE_STATDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_STATICDEP_PCIE_STATDEP_DISABLED        (CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_PCIE_STATDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_STATICDEP_REG_RESETVAL          (0x2c00b0b0U)

/* CM_DMA_DYNAMICDEP_REG */

#define CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define CM_DMA_DYNAMICDEP_L3MAIN1_DYNDEP_MASK         (CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG_L3MAIN1_DYNDEP_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT  (5U)
/* Below define for backward compatibility */
#define CM_DMA_DYNAMICDEP_L3MAIN1_DYNDEP_SHIFT        (CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG_L3MAIN1_DYNDEP_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_DYNAMICDEP_L3MAIN1_DYNDEP_DISABLED     (CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG_L3MAIN1_DYNDEP_DISABLED)


#define CSL_CORE_CM_CORE_CM_DMA_DYNAMICDEP_REG_RESETVAL         (0x00000000U)

/* CM_DMA_DMA_SYSTEM_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_STBYST_MASK  (0x00040000U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_STBYST_MASK         (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_STBYST_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_STBYST_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_STBYST_SHIFT  (18U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_STBYST_SHIFT        (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_STBYST_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_STBYST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_STBYST_FUNC         (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_STBYST_FUNC)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_STBYST_STANDBY  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_STBYST_STANDBY      (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_STBYST_STANDBY)


#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_DMA_DMA_SYSTEM_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_DMA_DMA_SYSTEM_CLKCTRL_REG_RESETVAL  (0x00070001U)

/* CM_EMIF_CLKSTCTRL_REG */

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_MASK   (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKTRCTRL_MASK              (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKTRCTRL_SHIFT             (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKTRCTRL_NO_SLEEP          (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKTRCTRL_RESERVED_1        (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKTRCTRL_HW_AUTO           (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKTRCTRL_SW_WKUP           (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)


#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_L3_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_L3_GICLK_MASK  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_L3_GICLK_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_L3_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_L3_GICLK_SHIFT  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_L3_GICLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_L3_GICLK_INACT  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_L3_GICLK_INACT)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_L3_GICLK_ACT  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_L3_GICLK_ACT)


#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_DLL_GCLK_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_DLL_GCLK_MASK  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_DLL_GCLK_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_DLL_GCLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_DLL_GCLK_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_DLL_GCLK_SHIFT  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_DLL_GCLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_DLL_GCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_DLL_GCLK_INACT  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_DLL_GCLK_INACT)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_DLL_GCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_DLL_GCLK_ACT  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_DLL_GCLK_ACT)


#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_PHY_GCLK_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_PHY_GCLK_MASK  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_PHY_GCLK_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_PHY_GCLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_PHY_GCLK_SHIFT  (10U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_PHY_GCLK_SHIFT  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_PHY_GCLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_PHY_GCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_PHY_GCLK_INACT  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_PHY_GCLK_INACT)

#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_PHY_GCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_CLKSTCTRL_CLKACTIVITY_EMIF_PHY_GCLK_ACT  (CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_CLKACTIVITY_EMIF_PHY_GCLK_ACT)


#define CSL_CORE_CM_CORE_CM_EMIF_CLKSTCTRL_REG_RESETVAL         (0x00000000U)

/* CM_EMIF_DMM_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL_MODULEMODE_MASK           (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL_MODULEMODE_SHIFT          (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL_MODULEMODE_AUTO           (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_MASK    (0x00030000U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL_IDLEST_MASK               (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_SHIFT   (16U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL_IDLEST_SHIFT              (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL_IDLEST_DISABLE            (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_IDLE    (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL_IDLEST_IDLE               (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_FUNC    (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL_IDLEST_FUNC               (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_TRANS   (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_DMM_CLKCTRL_IDLEST_TRANS              (CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_EMIF_DMM_CLKCTRL_REG_RESETVAL       (0x00030001U)

/* CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL_MODULEMODE_MASK   (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL_MODULEMODE_AUTO   (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL_IDLEST_MASK       (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL_IDLEST_SHIFT      (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL_IDLEST_DISABLE    (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL_IDLEST_IDLE       (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL_IDLEST_FUNC       (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_OCP_FW_CLKCTRL_IDLEST_TRANS      (CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_OCP_FW_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_EMIF_EMIF1_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_IDLEST_MASK             (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_IDLEST_SHIFT            (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_IDLEST_DISABLE          (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_IDLEST_IDLE             (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_IDLEST_FUNC             (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_IDLEST_TRANS            (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_MODULEMODE_MASK         (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_MODULEMODE_SHIFT        (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_MODULEMODE_DISABLED     (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_MODULEMODE_AUTO         (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_MODULEMODE_RESERVED_2   (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_MODULEMODE_RESERVED     (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_CLKSEL_LL_MASK  (0x01000000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_CLKSEL_LL_MASK          (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_CLKSEL_LL_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_CLKSEL_LL_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_CLKSEL_LL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_CLKSEL_LL_SHIFT         (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_CLKSEL_LL_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_CLKSEL_LL_SEL_C2C  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_CLKSEL_LL_SEL_C2C       (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_CLKSEL_LL_SEL_C2C)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_CLKSEL_LL_SEL_LLI  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF1_CLKCTRL_CLKSEL_LL_SEL_LLI       (CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_CLKSEL_LL_SEL_LLI)


#define CSL_CORE_CM_CORE_CM_EMIF_EMIF1_CLKCTRL_REG_RESETVAL     (0x00030001U)

/* CM_EMIF_EMIF2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_IDLEST_MASK             (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_IDLEST_SHIFT            (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_IDLEST_DISABLE          (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_IDLEST_IDLE             (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_IDLEST_FUNC             (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_IDLEST_TRANS            (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_MODULEMODE_MASK         (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_MODULEMODE_SHIFT        (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_MODULEMODE_DISABLED     (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_MODULEMODE_AUTO         (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_MODULEMODE_RESERVED_2   (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF2_CLKCTRL_MODULEMODE_RESERVED     (CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_EMIF_EMIF2_CLKCTRL_REG_RESETVAL     (0x00030001U)

/* CM_EMIF_EMIF_DLL_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_OPTFCLKEN_DLL_CLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_DLL_CLKCTRL_OPTFCLKEN_DLL_CLK_MASK  (CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_OPTFCLKEN_DLL_CLK_MASK)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_OPTFCLKEN_DLL_CLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_OPTFCLKEN_DLL_CLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_DLL_CLKCTRL_OPTFCLKEN_DLL_CLK_SHIFT  (CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_OPTFCLKEN_DLL_CLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_OPTFCLKEN_DLL_CLK_FCLK_EN  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_DLL_CLKCTRL_OPTFCLKEN_DLL_CLK_FCLK_EN  (CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_OPTFCLKEN_DLL_CLK_FCLK_EN)

#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_OPTFCLKEN_DLL_CLK_FCLK_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMIF_EMIF_DLL_CLKCTRL_OPTFCLKEN_DLL_CLK_FCLK_DIS  (CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_OPTFCLKEN_DLL_CLK_FCLK_DIS)


#define CSL_CORE_CM_CORE_CM_EMIF_EMIF_DLL_CLKCTRL_REG_RESETVAL  (0x00000000U)

/* CM_ATL_ATL_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_MASK     (0x00030000U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_IDLEST_MASK                (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_SHIFT    (16U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_IDLEST_SHIFT               (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_IDLEST_DISABLE             (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_IDLE     (0x00000002U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_IDLEST_IDLE                (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_FUNC     (0x00000000U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_IDLEST_FUNC                (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_TRANS    (0x00000001U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_IDLEST_TRANS               (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE1_MASK        (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_MASK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE1_SHIFT       (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SHIFT)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SEL_VIDEO1_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE1_SEL_VIDEO1_CLK  (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SEL_VIDEO1_CLK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SEL_VIDEO2_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE1_SEL_VIDEO2_CLK  (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SEL_VIDEO2_CLK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SEL_HDMI_CLK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE1_SEL_HDMI_CLK  (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SEL_HDMI_CLK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SEL_FUNC_32K_CLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE1_SEL_FUNC_32K_CLK  (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE1_SEL_FUNC_32K_CLK)


#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_MASK  (0x0C000000U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE2_MASK        (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_MASK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_SHIFT  (26U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE2_SHIFT       (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_SHIFT)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_SEL_L3_ICLK  (0x00000000U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE2_SEL_L3_ICLK  (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_SEL_L3_ICLK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_SEL_PER_ABE_X1_CLK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE2_SEL_PER_ABE_X1_CLK  (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_SEL_PER_ABE_X1_CLK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_SEL_DPLL_CLK  (0x00000002U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE2_SEL_DPLL_CLK  (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_SEL_DPLL_CLK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_CLKSEL_SOURCE2_RESERVED    (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_CLKSEL_SOURCE2_RESERVED)


#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_MODULEMODE_MASK            (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_MODULEMODE_SHIFT           (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_MODULEMODE_DISABLED        (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_MODULEMODE_RESERVED_1      (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_MODULEMODE_ENABLE          (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_ATL_ATL_CLKCTRL_MODULEMODE_RESERVED        (CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_ATL_ATL_CLKCTRL_REG_RESETVAL        (0x00030000U)

/* CM_ATL_CLKSTCTRL_REG */

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_MASK    (0x00000003U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKTRCTRL_MASK               (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_SHIFT   (0U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKTRCTRL_SHIFT              (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKTRCTRL_NO_SLEEP           (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKTRCTRL_RESERVED_1         (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKTRCTRL_SW_WKUP            (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKTRCTRL_HW_AUTO            (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_L3_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKACTIVITY_ATL_L3_GICLK_MASK  (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_L3_GICLK_MASK)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_L3_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKACTIVITY_ATL_L3_GICLK_SHIFT  (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_L3_GICLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKACTIVITY_ATL_L3_GICLK_INACT  (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_L3_GICLK_INACT)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKACTIVITY_ATL_L3_GICLK_ACT  (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_L3_GICLK_ACT)


#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_GFCLK_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKACTIVITY_ATL_GFCLK_MASK   (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_GFCLK_MASK)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_GFCLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_GFCLK_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKACTIVITY_ATL_GFCLK_SHIFT  (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_GFCLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKACTIVITY_ATL_GFCLK_INACT  (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_GFCLK_INACT)

#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_ATL_CLKSTCTRL_CLKACTIVITY_ATL_GFCLK_ACT    (CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_CLKACTIVITY_ATL_GFCLK_ACT)


#define CSL_CORE_CM_CORE_CM_ATL_CLKSTCTRL_REG_RESETVAL          (0x00000003U)

/* CM_L4CFG_CLKSTCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKTRCTRL_MASK             (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKTRCTRL_SHIFT            (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKTRCTRL_NO_SLEEP         (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKTRCTRL_RESERVED_1       (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKTRCTRL_RESERVED_2       (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKTRCTRL_HW_AUTO          (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L4_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKACTIVITY_L4CFG_L4_GICLK_MASK  (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L4_GICLK_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L4_GICLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L4_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKACTIVITY_L4CFG_L4_GICLK_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L4_GICLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L4_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKACTIVITY_L4CFG_L4_GICLK_INACT  (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L4_GICLK_INACT)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L4_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKACTIVITY_L4CFG_L4_GICLK_ACT  (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L4_GICLK_ACT)


#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L3_GICLK_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKACTIVITY_L4CFG_L3_GICLK_MASK  (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L3_GICLK_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L3_GICLK_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKACTIVITY_L4CFG_L3_GICLK_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L3_GICLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKACTIVITY_L4CFG_L3_GICLK_INACT  (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L3_GICLK_INACT)

#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_CLKSTCTRL_CLKACTIVITY_L4CFG_L3_GICLK_ACT  (CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_CLKACTIVITY_L4CFG_L3_GICLK_ACT)


#define CSL_CORE_CM_CORE_CM_L4CFG_CLKSTCTRL_REG_RESETVAL        (0x00000000U)

/* CM_L4CFG_DYNAMICDEP_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_EMIF_DYNDEP_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_EMIF_DYNDEP_MASK          (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_EMIF_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_EMIF_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_EMIF_DYNDEP_SHIFT  (4U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_EMIF_DYNDEP_SHIFT         (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_EMIF_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_EMIF_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_EMIF_DYNDEP_ENABLED       (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_EMIF_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3INIT_DYNDEP_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_L3INIT_DYNDEP_MASK        (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3INIT_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3INIT_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3INIT_DYNDEP_SHIFT  (7U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_L3INIT_DYNDEP_SHIFT       (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3INIT_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3INIT_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_L3INIT_DYNDEP_ENABLED     (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3INIT_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_COREAON_DYNDEP_MASK  (0x00010000U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_COREAON_DYNDEP_MASK       (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_COREAON_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_COREAON_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_COREAON_DYNDEP_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_COREAON_DYNDEP_SHIFT      (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_COREAON_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_COREAON_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_COREAON_DYNDEP_ENABLED    (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_COREAON_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_CUSTEFUSE_DYNDEP_MASK  (0x00020000U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_CUSTEFUSE_DYNDEP_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_CUSTEFUSE_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_CUSTEFUSE_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_CUSTEFUSE_DYNDEP_SHIFT  (17U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_CUSTEFUSE_DYNDEP_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_CUSTEFUSE_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_CUSTEFUSE_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_CUSTEFUSE_DYNDEP_ENABLED  (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_CUSTEFUSE_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_SDMA_DYNDEP_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_SDMA_DYNDEP_MASK          (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_SDMA_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_SDMA_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_SDMA_DYNDEP_SHIFT  (11U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_SDMA_DYNDEP_SHIFT         (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_SDMA_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_SDMA_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_SDMA_DYNDEP_ENABLED       (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_SDMA_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_L3MAIN1_DYNDEP_MASK       (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3MAIN1_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT  (5U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_L3MAIN1_DYNDEP_SHIFT      (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3MAIN1_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_L3MAIN1_DYNDEP_ENABLED    (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_L3MAIN1_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_WINDOWSIZE_MASK  (0x0F000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_WINDOWSIZE_MASK           (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_WINDOWSIZE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_WINDOWSIZE_RESETVAL  (0x00000004U)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_WINDOWSIZE_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_WINDOWSIZE_SHIFT          (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_WINDOWSIZE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_WINDOWSIZE_MAX  (0x0000000fU)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_MPU_DYNDEP_MASK  (0x00080000U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_MPU_DYNDEP_MASK           (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_MPU_DYNDEP_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_MPU_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_MPU_DYNDEP_SHIFT  (19U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_MPU_DYNDEP_SHIFT          (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_MPU_DYNDEP_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_MPU_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_DYNAMICDEP_MPU_DYNDEP_ENABLED        (CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_MPU_DYNDEP_ENABLED)


#define CSL_CORE_CM_CORE_CM_L4CFG_DYNAMICDEP_REG_RESETVAL       (0x040b08b0U)

/* CM_L4CFG_L4_CFG_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL_MODULEMODE_MASK       (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL_MODULEMODE_SHIFT      (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL_MODULEMODE_AUTO       (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL_IDLEST_MASK           (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL_IDLEST_SHIFT          (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL_IDLEST_DISABLE        (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL_IDLEST_IDLE           (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL_IDLEST_FUNC           (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_L4_CFG_CLKCTRL_IDLEST_TRANS          (CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_L4_CFG_CLKCTRL_REG_RESETVAL   (0x00030001U)

/* CM_L4CFG_SPINLOCK_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPINLOCK_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_SPINLOCK_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX1_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX1_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX1_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_SAR_ROM_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL_MODULEMODE_MASK      (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL_MODULEMODE_SHIFT     (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL_MODULEMODE_AUTO      (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL_IDLEST_MASK          (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL_IDLEST_SHIFT         (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL_IDLEST_DISABLE       (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL_IDLEST_IDLE          (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL_IDLEST_FUNC          (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SAR_ROM_CLKCTRL_IDLEST_TRANS         (CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_SAR_ROM_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_OCP2SCP2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_OCP2SCP2_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_OCP2SCP2_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX2_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX2_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX3_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX3_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX3_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX4_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX4_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX4_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX5_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX5_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX5_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX6_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX6_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX6_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX7_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX7_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX7_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX8_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX8_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX8_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX9_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL_MODULEMODE_MASK     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL_MODULEMODE_SHIFT    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL_MODULEMODE_AUTO     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL_IDLEST_MASK         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL_IDLEST_SHIFT        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL_IDLEST_DISABLE      (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL_IDLEST_IDLE         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL_IDLEST_FUNC         (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX9_CLKCTRL_IDLEST_TRANS        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX9_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX10_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL_MODULEMODE_MASK    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL_MODULEMODE_SHIFT   (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL_MODULEMODE_AUTO    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL_IDLEST_MASK        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL_IDLEST_SHIFT       (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL_IDLEST_DISABLE     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL_IDLEST_IDLE        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL_IDLEST_FUNC        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX10_CLKCTRL_IDLEST_TRANS       (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX10_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX11_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL_MODULEMODE_MASK    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL_MODULEMODE_SHIFT   (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL_MODULEMODE_AUTO    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL_IDLEST_MASK        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL_IDLEST_SHIFT       (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL_IDLEST_DISABLE     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL_IDLEST_IDLE        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL_IDLEST_FUNC        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX11_CLKCTRL_IDLEST_TRANS       (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX11_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX12_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL_MODULEMODE_MASK    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL_MODULEMODE_SHIFT   (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL_MODULEMODE_AUTO    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL_IDLEST_MASK        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL_IDLEST_SHIFT       (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL_IDLEST_DISABLE     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL_IDLEST_IDLE        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL_IDLEST_FUNC        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX12_CLKCTRL_IDLEST_TRANS       (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX12_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_MAILBOX13_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL_MODULEMODE_MASK    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL_MODULEMODE_SHIFT   (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL_MODULEMODE_AUTO    (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL_IDLEST_MASK        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL_IDLEST_SHIFT       (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL_IDLEST_DISABLE     (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL_IDLEST_IDLE        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL_IDLEST_FUNC        (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_MAILBOX13_CLKCTRL_IDLEST_TRANS       (CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_MAILBOX13_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_RTC_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_SPARE_SMARTREFLEX_WKUP_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_IDLEST_MASK   (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_IDLEST_IDLE   (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_IDLEST_FUNC   (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L4CFG_IO_DELAY_BLOCK_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3INSTR_CLKSTCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKTRCTRL_MASK           (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKTRCTRL_SHIFT          (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKTRCTRL_HW_AUTO        (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_L3_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_L3_GICLK_MASK  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_L3_GICLK_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_L3_GICLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_L3_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_L3_GICLK_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_L3_GICLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_L3_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_L3_GICLK_INACT  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_L3_GICLK_INACT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_L3_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_L3_GICLK_ACT  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_L3_GICLK_ACT)


#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_MASK  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_INACT  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_INACT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_ACT  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_DLL_AGING_GCLK_ACT)


#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_TS_GCLK_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_TS_GCLK_MASK  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_TS_GCLK_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_TS_GCLK_RESETVAL  (0x00000000U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_TS_GCLK_SHIFT  (10U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_TS_GCLK_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_TS_GCLK_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_TS_GCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_TS_GCLK_INACT  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_TS_GCLK_INACT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_TS_GCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CLKSTCTRL_CLKACTIVITY_L3INSTR_TS_GCLK_ACT  (CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_CLKACTIVITY_L3INSTR_TS_GCLK_ACT)


#define CSL_CORE_CM_CORE_CM_L3INSTR_CLKSTCTRL_REG_RESETVAL      (0x00000003U)

/* CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_IDLEST_MASK      (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_IDLEST_SHIFT     (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_IDLEST_DISABLE   (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_IDLEST_IDLE      (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_IDLEST_FUNC      (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_IDLEST_TRANS     (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_MODULEMODE_DISABLED  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_MAIN_2_CLKCTRL_MODULEMODE_RESERVED  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_MAIN_2_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3INSTR_L3_INSTR_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_IDLEST_MASK       (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_IDLEST_SHIFT      (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_IDLEST_DISABLE    (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_IDLEST_IDLE       (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_IDLEST_FUNC       (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_IDLEST_TRANS      (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_MODULEMODE_MASK   (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_MODULEMODE_DISABLED  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_MODULEMODE_AUTO   (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_L3_INSTR_CLKCTRL_MODULEMODE_RESERVED  (CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_L3INSTR_L3_INSTR_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_IDLEST_MASK     (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_IDLEST_SHIFT    (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_IDLEST_IDLE     (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_IDLEST_FUNC     (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_IDLEST_TRANS    (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_MODULEMODE_DISABLED  (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_OCP_WP_NOC_CLKCTRL_MODULEMODE_RESERVED  (CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CORE_CM_CORE_CM_L3INSTR_OCP_WP_NOC_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3INSTR_DLL_AGING_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL_IDLEST_MASK      (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL_IDLEST_SHIFT     (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL_IDLEST_DISABLE   (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL_IDLEST_IDLE      (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL_IDLEST_FUNC      (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_DLL_AGING_CLKCTRL_IDLEST_TRANS     (CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3INSTR_DLL_AGING_CLKCTRL_REG_RESETVAL  (0x00030001U)

/* CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG */

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_MODULEMODE_MASK  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_MODULEMODE_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_MODULEMODE_AUTO  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_IDLEST_MASK  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_IDLEST_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_IDLEST_DISABLE  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_IDLEST_IDLE  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_IDLEST_FUNC  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_IDLEST_TRANS  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_CLKSEL_MASK  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_MASK)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_RESETVAL  (0x00000002U)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_SHIFT  (24U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_CLKSEL_SHIFT  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_SHIFT)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_DIV8  (0x00000000U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_CLKSEL_DIV8  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_DIV8)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_DIV16  (0x00000001U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_CLKSEL_DIV16  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_DIV16)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_DIV32  (0x00000002U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_CLKSEL_DIV32  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_DIV32)

#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_CLKSEL_RESERVED  (CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_CLKSEL_RESERVED)


#define CSL_CORE_CM_CORE_CM_L3INSTR_CTRL_MODULE_BANDGAP_CLKCTRL_REG_RESETVAL  (0x02030001U)

#ifdef __cplusplus
}
#endif
#endif
