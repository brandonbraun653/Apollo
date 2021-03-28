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
#ifndef CSLR_CORE_PRM_H
#define CSLR_CORE_PRM_H

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
    volatile Uint32 PM_CORE_PWRSTCTRL_REG;
    volatile Uint32 PM_CORE_PWRSTST_REG;
    volatile Uint8  RSVD0[28];
    volatile Uint32 RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 RM_L3MAIN1_GPMC_CONTEXT_REG;
    volatile Uint8  RSVD2[4];
    volatile Uint32 RM_L3MAIN1_MMU_EDMA_CONTEXT_REG;
    volatile Uint8  RSVD3[20];
    volatile Uint32 RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG;
    volatile Uint32 PM_L3MAIN1_OCMC_RAM1_WKDEP_REG;
    volatile Uint32 RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG;
    volatile Uint32 PM_L3MAIN1_OCMC_RAM2_WKDEP_REG;
    volatile Uint32 RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG;
    volatile Uint32 PM_L3MAIN1_OCMC_RAM3_WKDEP_REG;
    volatile Uint32 RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG;
    volatile Uint8  RSVD4[4];
    volatile Uint32 RM_L3MAIN1_OCMC_ROM_CONTEXT_REG;
    volatile Uint32 PM_L3MAIN1_TPCC_WKDEP_REG;
    volatile Uint32 RM_L3MAIN1_TPCC_CONTEXT_REG;
    volatile Uint32 PM_L3MAIN1_TPTC1_WKDEP_REG;
    volatile Uint32 RM_L3MAIN1_TPTC1_CONTEXT_REG;
    volatile Uint32 PM_L3MAIN1_TPTC2_WKDEP_REG;
    volatile Uint32 RM_L3MAIN1_TPTC2_CONTEXT_REG;
    volatile Uint8  RSVD5[4];
    volatile Uint32 RM_L3MAIN1_VCP1_CONTEXT_REG;
    volatile Uint8  RSVD6[4];
    volatile Uint32 RM_L3MAIN1_VCP2_CONTEXT_REG;
    volatile Uint8  RSVD7[4];
    volatile Uint32 RM_L3MAIN1_SPARE_CME_CONTEXT_REG;
    volatile Uint8  RSVD8[4];
    volatile Uint32 RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG;
    volatile Uint8  RSVD9[4];
    volatile Uint32 RM_L3MAIN1_SPARE_ICM_CONTEXT_REG;
    volatile Uint8  RSVD10[4];
    volatile Uint32 RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG;
    volatile Uint8  RSVD11[4];
    volatile Uint32 RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG;
    volatile Uint8  RSVD12[4];
    volatile Uint32 RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG;
    volatile Uint8  RSVD13[4];
    volatile Uint32 RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG;
    volatile Uint8  RSVD14[4];
    volatile Uint32 RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG;
    volatile Uint8  RSVD15[4];
    volatile Uint32 RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG;
    volatile Uint8  RSVD16[20];
    volatile Uint32 RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG;
    volatile Uint8  RSVD17[4];
    volatile Uint32 RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG;
    volatile Uint8  RSVD18[272];
    volatile Uint32 RM_IPU2_RSTCTRL_REG;
    volatile Uint32 RM_IPU2_RSTST_REG;
    volatile Uint8  RSVD19[12];
    volatile Uint32 RM_IPU2_IPU2_CONTEXT_REG;
    volatile Uint8  RSVD20[252];
    volatile Uint32 RM_DMA_DMA_SYSTEM_CONTEXT_REG;
    volatile Uint8  RSVD21[252];
    volatile Uint32 RM_EMIF_DMM_CONTEXT_REG;
    volatile Uint8  RSVD22[4];
    volatile Uint32 RM_EMIF_EMIF_OCP_FW_CONTEXT_REG;
    volatile Uint8  RSVD23[4];
    volatile Uint32 RM_EMIF_EMIF1_CONTEXT_REG;
    volatile Uint8  RSVD24[4];
    volatile Uint32 RM_EMIF_EMIF2_CONTEXT_REG;
    volatile Uint8  RSVD25[4];
    volatile Uint32 RM_EMIF_EMIF_DLL_CONTEXT_REG;
    volatile Uint8  RSVD26[220];
    volatile Uint32 RM_ATL_ATL_CONTEXT_REG;
    volatile Uint8  RSVD27[252];
    volatile Uint32 RM_L4CFG_L4_CFG_CONTEXT_REG;
    volatile Uint8  RSVD28[4];
    volatile Uint32 RM_L4CFG_SPINLOCK_CONTEXT_REG;
    volatile Uint8  RSVD29[4];
    volatile Uint32 RM_L4CFG_MAILBOX1_CONTEXT_REG;
    volatile Uint8  RSVD30[4];
    volatile Uint32 RM_L4CFG_SAR_ROM_CONTEXT_REG;
    volatile Uint8  RSVD31[4];
    volatile Uint32 RM_L4CFG_OCP2SCP2_CONTEXT_REG;
    volatile Uint8  RSVD32[4];
    volatile Uint32 RM_L4CFG_MAILBOX2_CONTEXT_REG;
    volatile Uint8  RSVD33[4];
    volatile Uint32 RM_L4CFG_MAILBOX3_CONTEXT_REG;
    volatile Uint8  RSVD34[4];
    volatile Uint32 RM_L4CFG_MAILBOX4_CONTEXT_REG;
    volatile Uint8  RSVD35[4];
    volatile Uint32 RM_L4CFG_MAILBOX5_CONTEXT_REG;
    volatile Uint8  RSVD36[4];
    volatile Uint32 RM_L4CFG_MAILBOX6_CONTEXT_REG;
    volatile Uint8  RSVD37[4];
    volatile Uint32 RM_L4CFG_MAILBOX7_CONTEXT_REG;
    volatile Uint8  RSVD38[4];
    volatile Uint32 RM_L4CFG_MAILBOX8_CONTEXT_REG;
    volatile Uint8  RSVD39[4];
    volatile Uint32 RM_L4CFG_MAILBOX9_CONTEXT_REG;
    volatile Uint8  RSVD40[4];
    volatile Uint32 RM_L4CFG_MAILBOX10_CONTEXT_REG;
    volatile Uint8  RSVD41[4];
    volatile Uint32 RM_L4CFG_MAILBOX11_CONTEXT_REG;
    volatile Uint8  RSVD42[4];
    volatile Uint32 RM_L4CFG_MAILBOX12_CONTEXT_REG;
    volatile Uint8  RSVD43[4];
    volatile Uint32 RM_L4CFG_MAILBOX13_CONTEXT_REG;
    volatile Uint8  RSVD44[4];
    volatile Uint32 RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG;
    volatile Uint8  RSVD45[4];
    volatile Uint32 RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG;
    volatile Uint8  RSVD46[4];
    volatile Uint32 RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG;
    volatile Uint8  RSVD47[4];
    volatile Uint32 RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG;
    volatile Uint8  RSVD48[92];
    volatile Uint32 RM_L3INSTR_L3_MAIN_2_CONTEXT_REG;
    volatile Uint8  RSVD49[4];
    volatile Uint32 RM_L3INSTR_L3_INSTR_CONTEXT_REG;
    volatile Uint8  RSVD50[20];
    volatile Uint32 RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG;
} CSL_core_prmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register controls the CORE power state to reach upon a domain sleep 
 * transition */
#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG                      (0x0U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL        (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG)


/* This register provides a status on the current CORE power domain state. 
 * [warm reset insensitive] */
#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG                        (0x4U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST          (CSL_CORE_PRM_PM_CORE_PWRSTST_REG)


/* This register contains dedicated L3_MAIN_1 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG           (0x24U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_L3_MAIN_1_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG)


/* This register contains dedicated GPMC context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG                (0x2CU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_GPMC_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG)


/* This register contains dedicated MMU context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG            (0x34U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_EDMA_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG)


/* This register contains dedicated MMU context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG          (0x4CU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_PCIESS_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG)


/* This register controls wakeup dependency based on OCMC_RAM1 service 
 * requests. */
#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG             (0x50U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG)


/* This register contains dedicated OCMC_RAM context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG           (0x54U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM1_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG)


/* This register controls wakeup dependency based on OCMC_RAM2 service 
 * requests. */
#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG             (0x58U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG)


/* This register contains dedicated OCMC_RAM2 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG           (0x5CU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM2_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG)


/* This register controls wakeup dependency based on OCMC_RAM3 service 
 * requests. */
#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG             (0x60U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG)


/* This register contains dedicated OCMC_RAM3 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG           (0x64U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM3_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG)


/* This register contains dedicated OCMC_ROM context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG            (0x6CU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_ROM_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG)


/* This register controls wakeup dependency based on TPCC service requests. */
#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG                  (0x70U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP    (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG)


/* This register contains dedicated TPCC context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG                (0x74U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPCC_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG)


/* This register controls wakeup dependency based on TPTC service requests. */
#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG                 (0x78U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP   (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG)


/* This register contains dedicated TPTC1 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG               (0x7CU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC1_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG)


/* This register controls wakeup dependency based on TPTC service requests. */
#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG                 (0x80U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP   (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG)


/* This register contains dedicated TPTC2 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG               (0x84U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC2_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG)


/* This register contains dedicated VCP1 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG                (0x8CU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP1_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG)


/* This register contains dedicated VCP2 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG                (0x94U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP2_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG)


/* This register contains dedicated SPARE_CME context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG           (0x9CU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_CME_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG)


/* This register contains dedicated SPARE_HDMI context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG          (0xA4U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_HDMI_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG)


/* This register contains dedicated SPARE_ICM context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG           (0xACU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_ICM_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG)


/* This register contains dedicated SPARE_IVA2 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG          (0xB4U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_IVA2_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG)


/* This register contains dedicated SPARE_SATA2 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG         (0xBCU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_SATA2_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG)


/* This register contains dedicated SPARE_UNKNOWN4 context statuses. [warm 
 * reset insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG      (0xC4U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG)


/* This register contains dedicated SPARE_UNKNOWN5 context statuses. [warm 
 * reset insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG      (0xCCU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG)


/* This register contains dedicated SPARE_UNKNOWN6 context statuses. [warm 
 * reset insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG      (0xD4U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG)


/* This register contains dedicated SPARE_VIDEOPLL1 context statuses. [warm 
 * reset insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG     (0xDCU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG)


/* This register contains dedicated SPARE_VIDEOPLL2 context statuses. [warm 
 * reset insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG     (0xF4U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG)


/* This register contains dedicated SPARE_VIDEOPLL3 context statuses. [warm 
 * reset insensitive] */
#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG     (0xFCU)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG)


/* This register controls the release of the IPU2 sub-system resets. */
#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG                        (0x210U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL          (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG)


/* This register logs the different reset sources of the IPU2 SS. Each bit is 
 * set upon release of the domain reset signal. Must be cleared by software. 
 * [warm reset insensitive] */
#define CSL_CORE_PRM_RM_IPU2_RSTST_REG                          (0x214U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST            (CSL_CORE_PRM_RM_IPU2_RSTST_REG)


/* This register contains dedicated BELLINI1 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG                   (0x224U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT     (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG)


/* This register contains dedicated SDMA context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG              (0x324U)
/* Below define for backward compatibility */
#define RM_DMA_DMA_SYSTEM_CONTEXT  (CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG)


/* This register contains dedicated DMM context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG                    (0x424U)
/* Below define for backward compatibility */
#define RM_EMIF_DMM_CONTEXT      (CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG)


/* This register contains dedicated EMIF_OCP_FW context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG            (0x42CU)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_OCP_FW_CONTEXT  (CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG)


/* This register contains dedicated EMIF_1 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG                  (0x434U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF1_CONTEXT    (CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG)


/* This register contains dedicated EMIF_2 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG                  (0x43CU)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF2_CONTEXT    (CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG)


/* This register contains dedicated DLL context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG               (0x444U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_DLL_CONTEXT  (CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG)


/* This register contains dedicated ATL context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG                     (0x524U)
/* Below define for backward compatibility */
#define RM_ATL_ATL_CONTEXT       (CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG)


/* This register contains dedicated L4_CFG context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG                (0x624U)
/* Below define for backward compatibility */
#define RM_L4CFG_L4_CFG_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG)


/* This register contains dedicated HW_SEM context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG              (0x62CU)
/* Below define for backward compatibility */
#define RM_L4CFG_SPINLOCK_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG)


/* This register contains dedicated MAILBOX1 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG              (0x634U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX1_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG)


/* This register contains dedicated SAR_ROM context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG               (0x63CU)
/* Below define for backward compatibility */
#define RM_L4CFG_SAR_ROM_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG)


/* This register contains dedicated OCP2SCP2 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG              (0x644U)
/* Below define for backward compatibility */
#define RM_L4CFG_OCP2SCP2_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG)


/* This register contains dedicated MAILBOX2 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG              (0x64CU)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX2_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG)


/* This register contains dedicated MAILBOX3 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG              (0x654U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX3_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG)


/* This register contains dedicated MAILBOX4 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG              (0x65CU)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX4_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG)


/* This register contains dedicated MAILBOX5 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG              (0x664U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX5_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG)


/* This register contains dedicated MAILBOX6 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG              (0x66CU)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX6_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG)


/* This register contains dedicated MAILBOX7 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG              (0x674U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX7_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG)


/* This register contains dedicated MAILBOX8 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG              (0x67CU)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX8_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG)


/* This register contains dedicated MAILBOX9 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG              (0x684U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX9_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG)


/* This register contains dedicated MAILBOX10 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG             (0x68CU)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX10_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG)


/* This register contains dedicated MAILBOX11 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG             (0x694U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX11_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG)


/* This register contains dedicated MAILBOX12 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG             (0x69CU)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX12_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG)


/* This register contains dedicated MAILBOX13 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG             (0x6A4U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX13_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG)


/* This register contains dedicated SPARE_SMARTREFLEX_RTC context statuses. 
 * [warm reset insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG  (0x6ACU)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG)


/* This register contains dedicated SPARE_SMARTREFLEX_SDRAM context statuses. 
 * [warm reset insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG  (0x6B4U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG)


/* This register contains dedicated SPARE_SMARTREFLEX_WKUP context statuses. 
 * [warm reset insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG  (0x6BCU)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG)


/* This register contains dedicated IO_DELAY_BLOCK context statuses. [warm 
 * reset insensitive] */
#define CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG        (0x6C4U)
/* Below define for backward compatibility */
#define RM_L4CFG_IO_DELAY_BLOCK_CONTEXT  (CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG)


/* This register contains dedicated L3_3 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG           (0x724U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_MAIN_2_CONTEXT  (CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG)


/* This register contains dedicated L3_INSTR context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG            (0x72CU)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_INSTR_CONTEXT  (CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG)


/* This register contains dedicated OCP_WP1 context statuses. [warm reset 
 * insensitive] */
#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG          (0x744U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PM_CORE_PWRSTCTRL_REG */

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_RETSTATE_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OTHER_BANK_RETSTATE_MASK  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_RETSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_RETSTATE_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_RETSTATE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OTHER_BANK_RETSTATE_SHIFT  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_RETSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_RETSTATE_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OTHER_BANK_RETSTATE_MEM_RET  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_RETSTATE_MEM_RET)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_ONSTATE_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OTHER_BANK_ONSTATE_MASK  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_ONSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_ONSTATE_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OTHER_BANK_ONSTATE_SHIFT  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_ONSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OTHER_BANK_ONSTATE_MEM_ON  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OTHER_BANK_ONSTATE_MEM_ON)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOGICRETSTATE_MASK   (0x00000004U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_LOGICRETSTATE_MASK          (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOGICRETSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOGICRETSTATE_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOGICRETSTATE_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_LOGICRETSTATE_SHIFT         (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOGICRETSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_LOGICRETSTATE_LOGIC_RET     (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_RET)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_LOGICRETSTATE_LOGIC_OFF     (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_OFF)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_MASK      (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_POWERSTATE_MASK             (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_SHIFT     (0U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_POWERSTATE_SHIFT            (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_RESERVED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_POWERSTATE_RESERVED         (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_RESERVED)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_INACT     (0x00000002U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_POWERSTATE_INACT            (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_INACT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_RET       (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_POWERSTATE_RET              (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_RET)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_ON        (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_POWERSTATE_ON               (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_POWERSTATE_ON)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_RETSTATE_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OCMRAM_RETSTATE_MASK   (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_RETSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_RETSTATE_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_RETSTATE_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OCMRAM_RETSTATE_SHIFT  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_RETSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_RETSTATE_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OCMRAM_RETSTATE_MEM_RET  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_RETSTATE_MEM_RET)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_ONSTATE_MASK  (0x000C0000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OCMRAM_ONSTATE_MASK    (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_ONSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_ONSTATE_SHIFT  (18U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OCMRAM_ONSTATE_SHIFT   (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_ONSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_CORE_OCMRAM_ONSTATE_MEM_ON  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_CORE_OCMRAM_ONSTATE_MEM_ON)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_RETSTATE_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_L2RAM_RETSTATE_MASK     (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_RETSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_RETSTATE_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_RETSTATE_SHIFT  (10U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_L2RAM_RETSTATE_SHIFT    (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_RETSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_RETSTATE_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_L2RAM_RETSTATE_MEM_RET  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_RETSTATE_MEM_RET)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_RETSTATE_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_L2RAM_RETSTATE_MEM_OFF  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_RETSTATE_MEM_OFF)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_ONSTATE_MASK  (0x00300000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_L2RAM_ONSTATE_MASK      (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_ONSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_ONSTATE_SHIFT  (20U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_L2RAM_ONSTATE_SHIFT     (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_ONSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_L2RAM_ONSTATE_MEM_ON    (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_L2RAM_ONSTATE_MEM_ON)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_RETSTATE_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_UNICACHE_RETSTATE_MASK  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_RETSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_RETSTATE_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_RETSTATE_SHIFT  (11U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_UNICACHE_RETSTATE_SHIFT  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_RETSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_RETSTATE_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_UNICACHE_RETSTATE_MEM_OFF  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_RETSTATE_MEM_OFF)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_RETSTATE_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_UNICACHE_RETSTATE_MEM_RET  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_RETSTATE_MEM_RET)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_ONSTATE_MASK  (0x00C00000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_UNICACHE_ONSTATE_MASK   (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_ONSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_ONSTATE_SHIFT  (22U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_UNICACHE_ONSTATE_SHIFT  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_ONSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_IPU_UNICACHE_ONSTATE_MEM_ON  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_IPU_UNICACHE_ONSTATE_MEM_ON)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_RETSTATE_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_OCP_NRET_BANK_RETSTATE_MASK  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_RETSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_RETSTATE_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_RETSTATE_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_OCP_NRET_BANK_RETSTATE_SHIFT  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_RETSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_RETSTATE_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_OCP_NRET_BANK_RETSTATE_MEM_OFF  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_RETSTATE_MEM_OFF)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_ONSTATE_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_OCP_NRET_BANK_ONSTATE_MASK  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_ONSTATE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_ONSTATE_SHIFT  (24U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_OCP_NRET_BANK_ONSTATE_SHIFT  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_ONSTATE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_OCP_NRET_BANK_ONSTATE_MEM_ON  (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_OCP_NRET_BANK_ONSTATE_MEM_ON)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_LOWPOWERSTATECHANGE_MASK    (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_LOWPOWERSTATECHANGE_SHIFT   (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_LOWPOWERSTATECHANGE_EN      (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_EN)

#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_DIS  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTCTRL_LOWPOWERSTATECHANGE_DIS     (CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_LOWPOWERSTATECHANGE_DIS)


#define CSL_CORE_PRM_PM_CORE_PWRSTCTRL_REG_RESETVAL             (0x03ff0f07U)

/* PM_CORE_PWRSTST_REG */

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_MASK      (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_POWERSTATEST_MASK             (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_SHIFT     (0U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_POWERSTATEST_SHIFT            (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_ON        (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_POWERSTATEST_ON               (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_ON)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_RESERVED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_POWERSTATEST_RESERVED         (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_RESERVED)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_RET       (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_POWERSTATEST_RET              (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_RET)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_POWERSTATEST_INACTIVE         (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_POWERSTATEST_INACTIVE)


#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_INTRANSITION_MASK      (0x00100000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_INTRANSITION_MASK             (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_INTRANSITION_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_INTRANSITION_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_INTRANSITION_SHIFT     (20U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_INTRANSITION_SHIFT            (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_INTRANSITION_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_INTRANSITION_NO        (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_INTRANSITION_NO               (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_INTRANSITION_NO)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_INTRANSITION_ONGOING   (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_INTRANSITION_ONGOING          (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_INTRANSITION_ONGOING)


#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LOGICSTATEST_MASK      (0x00000004U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LOGICSTATEST_MASK             (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LOGICSTATEST_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LOGICSTATEST_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LOGICSTATEST_SHIFT     (2U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LOGICSTATEST_SHIFT            (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LOGICSTATEST_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LOGICSTATEST_ON        (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LOGICSTATEST_ON               (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LOGICSTATEST_ON)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LOGICSTATEST_OFF       (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LOGICSTATEST_OFF              (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LOGICSTATEST_OFF)


#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_MASK  (0x00000030U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OTHER_BANK_STATEST_MASK  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OTHER_BANK_STATEST_SHIFT  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OTHER_BANK_STATEST_MEM_ON  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_MEM_ON)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OTHER_BANK_STATEST_MEM_RET  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_MEM_RET)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OTHER_BANK_STATEST_MEM_OFF  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_MEM_OFF)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OTHER_BANK_STATEST_RESERVED  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OTHER_BANK_STATEST_RESERVED)


#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_MASK  (0x000000C0U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OCMRAM_STATEST_MASK      (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OCMRAM_STATEST_SHIFT     (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OCMRAM_STATEST_MEM_ON    (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_MEM_ON)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OCMRAM_STATEST_MEM_RET   (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_MEM_RET)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OCMRAM_STATEST_MEM_OFF   (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_MEM_OFF)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_CORE_OCMRAM_STATEST_RESERVED  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_CORE_OCMRAM_STATEST_RESERVED)


#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_MASK  (0x00000300U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_L2RAM_STATEST_MASK        (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_L2RAM_STATEST_SHIFT       (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_L2RAM_STATEST_MEM_ON      (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_MEM_ON)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_L2RAM_STATEST_MEM_RET     (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_MEM_RET)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_L2RAM_STATEST_MEM_OFF     (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_MEM_OFF)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_L2RAM_STATEST_RESERVED    (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_L2RAM_STATEST_RESERVED)


#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_MASK  (0x00000C00U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_UNICACHE_STATEST_MASK     (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_SHIFT  (10U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_UNICACHE_STATEST_SHIFT    (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_UNICACHE_STATEST_MEM_ON   (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_MEM_ON)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_UNICACHE_STATEST_MEM_RET  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_MEM_RET)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_UNICACHE_STATEST_MEM_OFF  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_MEM_OFF)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_IPU_UNICACHE_STATEST_RESERVED  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_IPU_UNICACHE_STATEST_RESERVED)


#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_MASK  (0x00003000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_OCP_NRET_BANK_STATEST_MASK    (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_RESETVAL  (0x00000003U)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_OCP_NRET_BANK_STATEST_SHIFT   (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_OCP_NRET_BANK_STATEST_MEM_ON  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_MEM_ON)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_RESERVED1  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_OCP_NRET_BANK_STATEST_RESERVED1  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_RESERVED1)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_OCP_NRET_BANK_STATEST_MEM_OFF  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_MEM_OFF)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_OCP_NRET_BANK_STATEST_RESERVED  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_OCP_NRET_BANK_STATEST_RESERVED)


#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LASTPOWERSTATEENTERED_MASK    (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT  (24U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LASTPOWERSTATEENTERED_SHIFT   (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LASTPOWERSTATEENTERED_ON      (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_ON)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LASTPOWERSTATEENTERED_OFF     (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LASTPOWERSTATEENTERED_RET     (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_RET)

#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CORE_PWRSTST_LASTPOWERSTATEENTERED_INACTIVE  (CSL_CORE_PRM_PM_CORE_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE)


#define CSL_CORE_PRM_PM_CORE_PWRSTST_REG_RESETVAL               (0x00003ff7U)

/* RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_L3_MAIN_1_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_L3_MAIN_1_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_L3_MAIN_1_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_L3_MAIN_1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_L3_MAIN_1_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_L3_MAIN_1_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_L3_MAIN_1_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_L3_MAIN_1_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_L3_MAIN_1_CONTEXT_REG_RESETVAL  (0x00000003U)

/* RM_L3MAIN1_GPMC_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_GPMC_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_GPMC_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_GPMC_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_GPMC_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_GPMC_CONTEXT_REG_RESETVAL       (0x00000002U)

/* RM_L3MAIN1_MMU_EDMA_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_EDMA_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_EDMA_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_EDMA_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_EDMA_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_MMU_EDMA_CONTEXT_REG_RESETVAL   (0x00000002U)

/* RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_PCIESS_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_PCIESS_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_PCIESS_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_MMU_PCIESS_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_MMU_PCIESS_CONTEXT_REG_RESETVAL  (0x00000002U)

/* PM_L3MAIN1_OCMC_RAM1_WKDEP_REG */

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_MPU_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_MPU_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_MPU_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_MPU_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_MPU_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_MPU_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_MPU_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_MPU_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_MPU_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_DSP1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_DSP1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_DSP1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_DSP1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_IPU2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_IPU2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_IPU2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_IPU2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_IPU1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_IPU1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_IPU1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_IPU1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_IPU1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_DSP2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_DSP2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_DSP2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_DSP2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_DSP2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE3_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE3_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE3_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE3_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE3_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE3_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE3_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE3_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE3_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE4_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE4_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE4_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE4_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE4_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE4_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE4_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM1_WKDEP_WKUPDEP_OCMC_RAM1_EVE4_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_WKUPDEP_OCMC_RAM1_EVE4_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM1_WKDEP_REG_RESETVAL    (0x00000000U)

/* RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM1_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM1_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM1_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM1_CONTEXT_LOSTMEM_CORE_OCMRAM_MASK  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM1_CONTEXT_LOSTMEM_CORE_OCMRAM_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM1_CONTEXT_LOSTMEM_CORE_OCMRAM_LOST  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM1_CONTEXT_LOSTMEM_CORE_OCMRAM_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM1_CONTEXT_REG_RESETVAL  (0x00000101U)

/* PM_L3MAIN1_OCMC_RAM2_WKDEP_REG */

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_MPU_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_MPU_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_MPU_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_MPU_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_MPU_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_MPU_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_MPU_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_MPU_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_MPU_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_IPU2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_IPU2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_IPU2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_IPU2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_DSP1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_DSP1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_DSP1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_DSP1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_IPU1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_IPU1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_IPU1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_IPU1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_IPU1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_DSP2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_DSP2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_DSP2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_DSP2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_DSP2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE3_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE3_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE3_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE3_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE3_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE3_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE3_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE3_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE3_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE4_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE4_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE4_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE4_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE4_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE4_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE4_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM2_WKDEP_WKUPDEP_OCMC_RAM2_EVE4_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_WKUPDEP_OCMC_RAM2_EVE4_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM2_WKDEP_REG_RESETVAL    (0x00000000U)

/* RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM2_CONTEXT_LOSTMEM_CORE_OCMRAM_MASK  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM2_CONTEXT_LOSTMEM_CORE_OCMRAM_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM2_CONTEXT_LOSTMEM_CORE_OCMRAM_LOST  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM2_CONTEXT_LOSTMEM_CORE_OCMRAM_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM2_CONTEXT_REG_RESETVAL  (0x00000101U)

/* PM_L3MAIN1_OCMC_RAM3_WKDEP_REG */

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_MPU_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_MPU_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_MPU_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_MPU_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_MPU_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_MPU_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_MPU_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_MPU_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_MPU_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_IPU2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_IPU2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_IPU2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_IPU2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_DSP1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_DSP1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_DSP1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_DSP1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_IPU1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_IPU1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_IPU1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_IPU1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_IPU1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_DSP2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_DSP2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_DSP2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_DSP2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_DSP2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE3_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE3_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE3_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE3_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE3_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE3_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE3_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE3_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE3_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE4_MASK  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE4_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE4_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE4_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE4_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE4_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE4_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_OCMC_RAM3_WKDEP_WKUPDEP_OCMC_RAM3_EVE4_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_WKUPDEP_OCMC_RAM3_EVE4_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_OCMC_RAM3_WKDEP_REG_RESETVAL    (0x00000000U)

/* RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM3_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM3_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM3_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM3_CONTEXT_LOSTMEM_CORE_OCMRAM_MASK  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM3_CONTEXT_LOSTMEM_CORE_OCMRAM_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM3_CONTEXT_LOSTMEM_CORE_OCMRAM_LOST  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_RAM3_CONTEXT_LOSTMEM_CORE_OCMRAM_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_LOSTMEM_CORE_OCMRAM_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_RAM3_CONTEXT_REG_RESETVAL  (0x00000101U)

/* RM_L3MAIN1_OCMC_ROM_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_ROM_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_ROM_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_ROM_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_ROM_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTMEM_CORE_OCMROM_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_ROM_CONTEXT_LOSTMEM_CORE_OCMROM_MASK  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTMEM_CORE_OCMROM_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTMEM_CORE_OCMROM_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTMEM_CORE_OCMROM_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_ROM_CONTEXT_LOSTMEM_CORE_OCMROM_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTMEM_CORE_OCMROM_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTMEM_CORE_OCMROM_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_ROM_CONTEXT_LOSTMEM_CORE_OCMROM_LOST  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTMEM_CORE_OCMROM_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTMEM_CORE_OCMROM_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_OCMC_ROM_CONTEXT_LOSTMEM_CORE_OCMROM_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_LOSTMEM_CORE_OCMROM_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_OCMC_ROM_CONTEXT_REG_RESETVAL   (0x00000101U)

/* PM_L3MAIN1_TPCC_WKDEP_REG */

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_MPU_MASK   (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_MPU_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_MPU_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_MPU_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_MPU_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_MPU_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_MPU_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_MPU_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_MPU_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_DSP1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_DSP1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_DSP1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_DSP1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_IPU2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_IPU2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_IPU2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_IPU2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_IPU1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_IPU1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_IPU1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_IPU1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_IPU1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_DSP2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_DSP2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_DSP2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_DSP2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_DSP2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE3_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE3_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE3_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE3_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE3_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE3_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE3_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE3_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE3_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE4_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE4_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE4_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE4_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE4_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE4_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE4_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPCC_WKDEP_WKUPDEP_TPCC_EVE4_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_WKUPDEP_TPCC_EVE4_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPCC_WKDEP_REG_RESETVAL         (0x00000000U)

/* RM_L3MAIN1_TPCC_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPCC_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPCC_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPCC_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPCC_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTMEM_TPCC_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPCC_CONTEXT_LOSTMEM_TPCC_BANK_MASK  (CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTMEM_TPCC_BANK_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTMEM_TPCC_BANK_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTMEM_TPCC_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPCC_CONTEXT_LOSTMEM_TPCC_BANK_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTMEM_TPCC_BANK_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTMEM_TPCC_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPCC_CONTEXT_LOSTMEM_TPCC_BANK_LOST  (CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTMEM_TPCC_BANK_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTMEM_TPCC_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPCC_CONTEXT_LOSTMEM_TPCC_BANK_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_LOSTMEM_TPCC_BANK_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_TPCC_CONTEXT_REG_RESETVAL       (0x00000102U)

/* PM_L3MAIN1_TPTC1_WKDEP_REG */

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_MPU_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_MPU_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_MPU_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_MPU_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_MPU_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_MPU_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_MPU_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_MPU_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_MPU_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_DSP1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_DSP1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_DSP1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_DSP1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_IPU2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_IPU2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_IPU2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_IPU2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_IPU1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_IPU1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_IPU1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_IPU1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_IPU1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_DSP2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_DSP2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_DSP2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_DSP2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_DSP2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE3_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE3_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE3_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE3_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE3_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE3_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE3_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE3_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE3_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE4_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE4_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE4_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE4_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE4_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE4_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE4_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC1_WKDEP_WKUPDEP_TPTC1_EVE4_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_WKUPDEP_TPTC1_EVE4_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC1_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L3MAIN1_TPTC1_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC1_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC1_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC1_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC1_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTMEM_TPTC_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC1_CONTEXT_LOSTMEM_TPTC_BANK_MASK  (CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTMEM_TPTC_BANK_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTMEM_TPTC_BANK_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTMEM_TPTC_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC1_CONTEXT_LOSTMEM_TPTC_BANK_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTMEM_TPTC_BANK_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTMEM_TPTC_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC1_CONTEXT_LOSTMEM_TPTC_BANK_LOST  (CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTMEM_TPTC_BANK_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTMEM_TPTC_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC1_CONTEXT_LOSTMEM_TPTC_BANK_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_LOSTMEM_TPTC_BANK_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_TPTC1_CONTEXT_REG_RESETVAL      (0x00000102U)

/* PM_L3MAIN1_TPTC2_WKDEP_REG */

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_MPU_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_MPU_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_MPU_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_MPU_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_MPU_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_MPU_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_MPU_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_MPU_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_MPU_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_MPU_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_MPU_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_MPU_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_MPU_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP1_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_DSP1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP1_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_DSP1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_DSP1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_DSP1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU2_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_IPU2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU2_SHIFT  (1U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_IPU2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_IPU2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_IPU2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_IPU1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_IPU1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_IPU1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_IPU1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_IPU1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP2_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_DSP2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP2_SHIFT  (5U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_DSP2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_DSP2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_DSP2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_DSP2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE1_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE1_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE1_SHIFT  (6U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE1_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE1_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE1_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE1_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE1_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE1_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE1_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE1_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE2_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE2_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE2_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE2_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE2_SHIFT  (7U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE2_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE2_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE2_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE2_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE2_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE2_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE2_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE2_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE3_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE3_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE3_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE3_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE3_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE3_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE3_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE3_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE3_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE3_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE3_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE3_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE3_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE4_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE4_MASK  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE4_MASK)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE4_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE4_SHIFT  (9U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE4_SHIFT  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE4_SHIFT)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE4_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE4_ENABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE4_ENABLED)

#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE4_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define PM_L3MAIN1_TPTC2_WKDEP_WKUPDEP_TPTC2_EVE4_DISABLED  (CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_WKUPDEP_TPTC2_EVE4_DISABLED)


#define CSL_CORE_PRM_PM_L3MAIN1_TPTC2_WKDEP_REG_RESETVAL        (0x00000000U)

/* RM_L3MAIN1_TPTC2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC2_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC2_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC2_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC2_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTMEM_TPTC_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC2_CONTEXT_LOSTMEM_TPTC_BANK_MASK  (CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTMEM_TPTC_BANK_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTMEM_TPTC_BANK_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTMEM_TPTC_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC2_CONTEXT_LOSTMEM_TPTC_BANK_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTMEM_TPTC_BANK_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTMEM_TPTC_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC2_CONTEXT_LOSTMEM_TPTC_BANK_LOST  (CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTMEM_TPTC_BANK_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTMEM_TPTC_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_TPTC2_CONTEXT_LOSTMEM_TPTC_BANK_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_LOSTMEM_TPTC_BANK_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_TPTC2_CONTEXT_REG_RESETVAL      (0x00000102U)

/* RM_L3MAIN1_VCP1_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP1_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP1_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP1_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTMEM_VCP_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP1_CONTEXT_LOSTMEM_VCP_BANK_MASK  (CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTMEM_VCP_BANK_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTMEM_VCP_BANK_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTMEM_VCP_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP1_CONTEXT_LOSTMEM_VCP_BANK_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTMEM_VCP_BANK_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTMEM_VCP_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP1_CONTEXT_LOSTMEM_VCP_BANK_LOST  (CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTMEM_VCP_BANK_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTMEM_VCP_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP1_CONTEXT_LOSTMEM_VCP_BANK_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_LOSTMEM_VCP_BANK_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_VCP1_CONTEXT_REG_RESETVAL       (0x00000101U)

/* RM_L3MAIN1_VCP2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTMEM_VCP_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP2_CONTEXT_LOSTMEM_VCP_BANK_MASK  (CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTMEM_VCP_BANK_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTMEM_VCP_BANK_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTMEM_VCP_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP2_CONTEXT_LOSTMEM_VCP_BANK_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTMEM_VCP_BANK_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTMEM_VCP_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP2_CONTEXT_LOSTMEM_VCP_BANK_LOST  (CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTMEM_VCP_BANK_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTMEM_VCP_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_VCP2_CONTEXT_LOSTMEM_VCP_BANK_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_LOSTMEM_VCP_BANK_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_VCP2_CONTEXT_REG_RESETVAL       (0x00000101U)

/* RM_L3MAIN1_SPARE_CME_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_CME_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_CME_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_CME_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_CME_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_CME_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_HDMI_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_HDMI_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_HDMI_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_HDMI_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_HDMI_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_ICM_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_ICM_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_ICM_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_ICM_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_ICM_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_ICM_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_IVA2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_IVA2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_IVA2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_IVA2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_IVA2_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_SATA2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_SATA2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_SATA2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_SATA2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_SATA2_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN4_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN5_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_UNKNOWN6_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL1_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL2_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3MAIN1_SPARE_VIDEOPLL3_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_IPU2_RSTCTRL_REG */

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU0_MASK          (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_CPU0_MASK                 (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU0_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU0_RESETVAL      (0x00000001U)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU0_SHIFT         (0U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_CPU0_SHIFT                (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU0_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU0_ASSERT        (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_CPU0_ASSERT               (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU0_ASSERT)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU0_CLEAR         (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_CPU0_CLEAR                (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU0_CLEAR)


#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU1_MASK          (0x00000002U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_CPU1_MASK                 (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU1_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU1_RESETVAL      (0x00000001U)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU1_SHIFT         (1U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_CPU1_SHIFT                (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU1_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU1_ASSERT        (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_CPU1_ASSERT               (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU1_ASSERT)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU1_CLEAR         (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_CPU1_CLEAR                (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_CPU1_CLEAR)


#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_IPU_MASK           (0x00000004U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_IPU_MASK                  (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_IPU_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_IPU_RESETVAL       (0x00000001U)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_IPU_SHIFT          (2U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_IPU_SHIFT                 (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_IPU_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_IPU_ASSERT         (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_IPU_ASSERT                (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_IPU_ASSERT)

#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_IPU_CLEAR          (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTCTRL_RST_IPU_CLEAR                 (CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RST_IPU_CLEAR)


#define CSL_CORE_PRM_RM_IPU2_RSTCTRL_REG_RESETVAL               (0x00000007U)

/* RM_IPU2_RSTST_REG */

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU0_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_EMULATION_CPU0_MASK         (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU0_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU0_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU0_SHIFT  (3U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_EMULATION_CPU0_SHIFT        (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU0_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU0_RESET_YES  (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_EMULATION_CPU0_RESET_YES    (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU0_RESET_YES)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU0_RESET_NO  (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_EMULATION_CPU0_RESET_NO     (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU0_RESET_NO)


#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU1_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_EMULATION_CPU1_MASK         (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU1_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU1_SHIFT  (4U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_EMULATION_CPU1_SHIFT        (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU1_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU1_RESET_YES  (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_EMULATION_CPU1_RESET_YES    (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU1_RESET_YES)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU1_RESET_NO  (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_EMULATION_CPU1_RESET_NO     (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_EMULATION_CPU1_RESET_NO)


#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU0_MASK            (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_CPU0_MASK                   (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU0_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU0_RESETVAL        (0x00000000U)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU0_SHIFT           (0U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_CPU0_SHIFT                  (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU0_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU0_RESET_YES       (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_CPU0_RESET_YES              (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU0_RESET_YES)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU0_RESET_NO        (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_CPU0_RESET_NO               (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU0_RESET_NO)


#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU1_MASK            (0x00000002U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_CPU1_MASK                   (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU1_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU1_RESETVAL        (0x00000000U)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU1_SHIFT           (1U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_CPU1_SHIFT                  (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU1_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU1_RESET_YES       (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_CPU1_RESET_YES              (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU1_RESET_YES)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU1_RESET_NO        (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_CPU1_RESET_NO               (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_CPU1_RESET_NO)


#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_IPU_MASK             (0x00000004U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_IPU_MASK                    (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_IPU_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_IPU_RESETVAL         (0x00000000U)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_IPU_SHIFT            (2U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_IPU_SHIFT                   (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_IPU_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_IPU_RESET_YES        (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_IPU_RESET_YES               (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_IPU_RESET_YES)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_IPU_RESET_NO         (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_IPU_RESET_NO                (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_IPU_RESET_NO)


#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU0_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_ICECRUSHER_CPU0_MASK        (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU0_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU0_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU0_SHIFT  (5U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_ICECRUSHER_CPU0_SHIFT       (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU0_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU0_RESET_YES  (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_ICECRUSHER_CPU0_RESET_YES   (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU0_RESET_YES)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU0_RESET_NO  (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_ICECRUSHER_CPU0_RESET_NO    (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU0_RESET_NO)


#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU1_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_ICECRUSHER_CPU1_MASK        (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU1_MASK)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU1_RESETVAL  (0x00000000U)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU1_SHIFT  (6U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_ICECRUSHER_CPU1_SHIFT       (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU1_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU1_RESET_YES  (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_ICECRUSHER_CPU1_RESET_YES   (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU1_RESET_YES)

#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU1_RESET_NO  (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_RSTST_RST_ICECRUSHER_CPU1_RESET_NO    (CSL_CORE_PRM_RM_IPU2_RSTST_REG_RST_ICECRUSHER_CPU1_RESET_NO)


#define CSL_CORE_PRM_RM_IPU2_RSTST_REG_RESETVAL                 (0x00000000U)

/* RM_IPU2_IPU2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTCONTEXT_DFF_MASK     (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTCONTEXT_DFF_SHIFT    (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTCONTEXT_DFF_LOST     (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTCONTEXT_RFF_MASK     (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTCONTEXT_RFF_SHIFT    (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTCONTEXT_RFF_LOST     (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_UNICACHE_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTMEM_IPU_UNICACHE_MASK  (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_UNICACHE_MASK)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_UNICACHE_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_UNICACHE_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTMEM_IPU_UNICACHE_SHIFT  (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_UNICACHE_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_UNICACHE_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTMEM_IPU_UNICACHE_LOST  (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_UNICACHE_LOST)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_UNICACHE_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTMEM_IPU_UNICACHE_MAINTAINED  (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_UNICACHE_MAINTAINED)


#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_L2RAM_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTMEM_IPU_L2RAM_MASK   (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_L2RAM_MASK)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_L2RAM_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_L2RAM_SHIFT  (9U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTMEM_IPU_L2RAM_SHIFT  (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_L2RAM_SHIFT)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_L2RAM_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTMEM_IPU_L2RAM_LOST   (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_L2RAM_LOST)

#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_L2RAM_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_IPU2_IPU2_CONTEXT_LOSTMEM_IPU_L2RAM_MAINTAINED  (CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_LOSTMEM_IPU_L2RAM_MAINTAINED)


#define CSL_CORE_PRM_RM_IPU2_IPU2_CONTEXT_REG_RESETVAL          (0x00000303U)

/* RM_DMA_DMA_SYSTEM_CONTEXT_REG */

#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_DMA_DMA_SYSTEM_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_DMA_DMA_SYSTEM_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_DMA_DMA_SYSTEM_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_DMA_DMA_SYSTEM_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTMEM_CORE_OTHER_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_DMA_DMA_SYSTEM_CONTEXT_LOSTMEM_CORE_OTHER_BANK_MASK  (CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTMEM_CORE_OTHER_BANK_MASK)

#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTMEM_CORE_OTHER_BANK_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTMEM_CORE_OTHER_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_DMA_DMA_SYSTEM_CONTEXT_LOSTMEM_CORE_OTHER_BANK_SHIFT  (CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTMEM_CORE_OTHER_BANK_SHIFT)

#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTMEM_CORE_OTHER_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_DMA_DMA_SYSTEM_CONTEXT_LOSTMEM_CORE_OTHER_BANK_LOST  (CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTMEM_CORE_OTHER_BANK_LOST)

#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTMEM_CORE_OTHER_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_DMA_DMA_SYSTEM_CONTEXT_LOSTMEM_CORE_OTHER_BANK_MAINTAINED  (CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_LOSTMEM_CORE_OTHER_BANK_MAINTAINED)


#define CSL_CORE_PRM_RM_DMA_DMA_SYSTEM_CONTEXT_REG_RESETVAL     (0x00000102U)

/* RM_EMIF_DMM_CONTEXT_REG */

#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_DMM_CONTEXT_LOSTCONTEXT_DFF_MASK      (CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_EMIF_DMM_CONTEXT_LOSTCONTEXT_DFF_SHIFT     (CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_DMM_CONTEXT_LOSTCONTEXT_DFF_LOST      (CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMIF_DMM_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_EMIF_DMM_CONTEXT_LOSTCONTEXT_RFF_MASK      (CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_EMIF_DMM_CONTEXT_LOSTCONTEXT_RFF_SHIFT     (CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_DMM_CONTEXT_LOSTCONTEXT_RFF_LOST      (CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMIF_DMM_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_EMIF_DMM_CONTEXT_REG_RESETVAL           (0x00000003U)

/* RM_EMIF_EMIF_OCP_FW_CONTEXT_REG */

#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_OCP_FW_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_OCP_FW_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_OCP_FW_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_OCP_FW_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_OCP_FW_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_OCP_FW_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_OCP_FW_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_OCP_FW_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_EMIF_EMIF_OCP_FW_CONTEXT_REG_RESETVAL   (0x00000003U)

/* RM_EMIF_EMIF1_CONTEXT_REG */

#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF1_CONTEXT_LOSTCONTEXT_RFF_MASK    (CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF1_CONTEXT_LOSTCONTEXT_RFF_SHIFT   (CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF1_CONTEXT_LOSTCONTEXT_RFF_LOST    (CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF1_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF1_CONTEXT_LOSTCONTEXT_DFF_MASK    (CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF1_CONTEXT_LOSTCONTEXT_DFF_SHIFT   (CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF1_CONTEXT_LOSTCONTEXT_DFF_LOST    (CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_EMIF_EMIF1_CONTEXT_REG_RESETVAL         (0x00000003U)

/* RM_EMIF_EMIF2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF2_CONTEXT_LOSTCONTEXT_RFF_MASK    (CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF2_CONTEXT_LOSTCONTEXT_RFF_SHIFT   (CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF2_CONTEXT_LOSTCONTEXT_RFF_LOST    (CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF2_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF2_CONTEXT_LOSTCONTEXT_DFF_MASK    (CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF2_CONTEXT_LOSTCONTEXT_DFF_SHIFT   (CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF2_CONTEXT_LOSTCONTEXT_DFF_LOST    (CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_EMIF_EMIF2_CONTEXT_REG_RESETVAL         (0x00000003U)

/* RM_EMIF_EMIF_DLL_CONTEXT_REG */

#define CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_DLL_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_DLL_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_DLL_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMIF_EMIF_DLL_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_EMIF_EMIF_DLL_CONTEXT_REG_RESETVAL      (0x00000001U)

/* RM_ATL_ATL_CONTEXT_REG */

#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_ATL_ATL_CONTEXT_LOSTCONTEXT_DFF_MASK       (CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_ATL_ATL_CONTEXT_LOSTCONTEXT_DFF_SHIFT      (CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_ATL_ATL_CONTEXT_LOSTCONTEXT_DFF_LOST       (CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_ATL_ATL_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTMEM_ATL_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_ATL_ATL_CONTEXT_LOSTMEM_ATL_BANK_MASK      (CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTMEM_ATL_BANK_MASK)

#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTMEM_ATL_BANK_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTMEM_ATL_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_ATL_ATL_CONTEXT_LOSTMEM_ATL_BANK_SHIFT     (CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTMEM_ATL_BANK_SHIFT)

#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTMEM_ATL_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_ATL_ATL_CONTEXT_LOSTMEM_ATL_BANK_LOST      (CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTMEM_ATL_BANK_LOST)

#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTMEM_ATL_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_ATL_ATL_CONTEXT_LOSTMEM_ATL_BANK_MAINTAINED  (CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_LOSTMEM_ATL_BANK_MAINTAINED)


#define CSL_CORE_PRM_RM_ATL_ATL_CONTEXT_REG_RESETVAL            (0x00000101U)

/* RM_L4CFG_L4_CFG_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_L4_CFG_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4CFG_L4_CFG_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_L4_CFG_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_L4_CFG_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_L4_CFG_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_L4_CFG_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_L4_CFG_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_L4_CFG_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_L4_CFG_CONTEXT_REG_RESETVAL       (0x00000003U)

/* RM_L4CFG_SPINLOCK_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPINLOCK_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPINLOCK_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPINLOCK_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPINLOCK_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_SPINLOCK_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_MAILBOX1_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX1_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX1_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX1_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX1_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX1_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_SAR_ROM_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_SAR_ROM_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4CFG_SAR_ROM_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_SAR_ROM_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_SAR_ROM_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_SAR_ROM_CONTEXT_REG_RESETVAL      (0x00000001U)

/* RM_L4CFG_OCP2SCP2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_OCP2SCP2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4CFG_OCP2SCP2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_OCP2SCP2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_OCP2SCP2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_OCP2SCP2_CONTEXT_REG_RESETVAL     (0x00000001U)

/* RM_L4CFG_MAILBOX2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX2_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX2_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX2_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX2_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX2_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_MAILBOX3_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX3_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX3_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX3_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX3_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX3_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_MAILBOX4_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX4_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX4_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX4_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX4_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX4_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_MAILBOX5_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX5_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX5_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX5_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX5_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX5_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_MAILBOX6_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX6_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX6_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX6_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX6_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX6_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_MAILBOX7_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX7_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX7_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX7_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX7_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX7_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_MAILBOX8_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX8_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX8_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX8_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX8_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX8_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_MAILBOX9_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX9_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX9_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX9_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX9_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX9_CONTEXT_REG_RESETVAL     (0x00000002U)

/* RM_L4CFG_MAILBOX10_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX10_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX10_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX10_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX10_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX10_CONTEXT_REG_RESETVAL    (0x00000002U)

/* RM_L4CFG_MAILBOX11_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX11_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX11_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX11_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX11_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX11_CONTEXT_REG_RESETVAL    (0x00000002U)

/* RM_L4CFG_MAILBOX12_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX12_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX12_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX12_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX12_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX12_CONTEXT_REG_RESETVAL    (0x00000002U)

/* RM_L4CFG_MAILBOX13_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX13_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX13_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX13_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_MAILBOX13_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_MAILBOX13_CONTEXT_REG_RESETVAL    (0x00000002U)

/* RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_RTC_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_SDRAM_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_SPARE_SMARTREFLEX_WKUP_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L4CFG_IO_DELAY_BLOCK_CONTEXT_REG_RESETVAL  (0x00000001U)

/* RM_L3INSTR_L3_MAIN_2_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_MAIN_2_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_MAIN_2_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_MAIN_2_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_MAIN_2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_MAIN_2_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_MAIN_2_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_MAIN_2_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_MAIN_2_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3INSTR_L3_MAIN_2_CONTEXT_REG_RESETVAL  (0x00000003U)

/* RM_L3INSTR_L3_INSTR_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_INSTR_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_INSTR_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_INSTR_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3INSTR_L3_INSTR_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3INSTR_L3_INSTR_CONTEXT_REG_RESETVAL   (0x00000001U)

/* RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG */

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_RFF_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTCONTEXT_RFF_MASK  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_RFF_MASK)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_RFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTCONTEXT_RFF_SHIFT  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_RFF_SHIFT)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_RFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTCONTEXT_RFF_LOST  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_RFF_LOST)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_RFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTCONTEXT_DFF_MASK  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTCONTEXT_DFF_LOST  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTMEM_CORE_NRET_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTMEM_CORE_NRET_BANK_MASK  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTMEM_CORE_NRET_BANK_MASK)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTMEM_CORE_NRET_BANK_RESETVAL  (0x00000001U)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTMEM_CORE_NRET_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTMEM_CORE_NRET_BANK_SHIFT  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTMEM_CORE_NRET_BANK_SHIFT)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTMEM_CORE_NRET_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTMEM_CORE_NRET_BANK_LOST  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTMEM_CORE_NRET_BANK_LOST)

#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTMEM_CORE_NRET_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_L3INSTR_OCP_WP_NOC_CONTEXT_LOSTMEM_CORE_NRET_BANK_MAINTAINED  (CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_LOSTMEM_CORE_NRET_BANK_MAINTAINED)


#define CSL_CORE_PRM_RM_L3INSTR_OCP_WP_NOC_CONTEXT_REG_RESETVAL  (0x00000103U)

#ifdef __cplusplus
}
#endif
#endif
