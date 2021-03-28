/********************************************************************
 * Copyright (C) 2018 Texas Instruments Incorporated.
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
 *  Name        : cslr_ufshci.h
*/
#ifndef CSLR_UFSHCI_H_
#define CSLR_UFSHCI_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_UFSHCISS_REGS_BASE                                                 (0x00000000U)
#define CSL_UFSHCI_ECC_AGGR_REGS_BASE                                          (0x00000000U)
#define CSL_UFSHCI_ERR_INJ_REGS_BASE                                           (0x00000000U)
#define CSL_UFSHCI_REGS_REGS_BASE                                              (0x00000000U)


/**************************************************************************
* Hardware Region  : UFS HCI Cadence controller configuration memory space
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t CAP;
    volatile uint8_t  Resv_8[4];
    volatile uint32_t VER;
    volatile uint8_t  Resv_16[4];
    volatile uint32_t HCPID;
    volatile uint32_t HCMID;
    volatile uint32_t AHIT;
    volatile uint8_t  Resv_32[4];
    volatile uint32_t IS;
    volatile uint32_t IE;
    volatile uint8_t  Resv_48[8];
    volatile uint32_t HCS;
    volatile uint32_t HCE;
    volatile uint32_t UECPA;
    volatile uint32_t UECDL;
    volatile uint32_t UECN;
    volatile uint32_t UECT;
    volatile uint32_t UECDME;
    volatile uint32_t UTRIACR;
    volatile uint32_t UTRLBA;
    volatile uint32_t UTRLBAU;
    volatile uint32_t UTRLDBR;
    volatile uint32_t UTRLCLR;
    volatile uint32_t UTRLRSR;
    volatile uint32_t UTRLCNR;
    volatile uint8_t  Resv_112[8];
    volatile uint32_t UTMRLBA;
    volatile uint32_t UTMRLBAU;
    volatile uint32_t UTMRLDBR;
    volatile uint32_t UTMRLCLR;
    volatile uint32_t UTMRLRSR;
    volatile uint8_t  Resv_144[12];
    volatile uint32_t UICCMD;
    volatile uint32_t UICCMDARG1;
    volatile uint32_t UICCMDARG2;
    volatile uint32_t UICCMDARG3;
    volatile uint32_t SYSTHRTL;
    volatile uint8_t  Resv_172[8];
    volatile uint32_t HCI_MMIO_TOSH_UNIRESPOL;
    volatile uint8_t  Resv_196[20];
    volatile uint32_t OSYSR;
    volatile uint32_t XCNF;
    volatile uint32_t ADSIT;
    volatile uint32_t CDACFG;
    volatile uint32_t CDATX1;
    volatile uint32_t CDATX2;
    volatile uint32_t CDARX1;
    volatile uint32_t CDARX2;
    volatile uint32_t CDASTA;
    volatile uint32_t XASB;
    volatile uint8_t  Resv_240[4];
    volatile uint32_t LBMCFG;
    volatile uint32_t LBMSTA;
    volatile uint32_t DBG;
    volatile uint32_t HCLKDIV;
    volatile uint32_t CCAP;
    volatile uint32_t CRYPTOCAP;
    volatile uint8_t  Resv_1280[1016];
    volatile uint32_t CRYPTOCFG0;
    volatile uint32_t CRYPTOCFG1;
    volatile uint32_t CRYPTOCFG2;
    volatile uint32_t CRYPTOCFG3;
    volatile uint8_t  Resv_1344[48];
    volatile uint32_t CRYPTOCFG16;
    volatile uint32_t CRYPTOCFG17;
    volatile uint8_t  Resv_1408[56];
    volatile uint32_t CRYPTOCFG32;
    volatile uint32_t CRYPTOCFG33;
    volatile uint32_t CRYPTOCFG34;
    volatile uint32_t CRYPTOCFG35;
    volatile uint8_t  Resv_1472[48];
    volatile uint32_t CRYPTOCFG48;
    volatile uint32_t CRYPTOCFG49;
    volatile uint8_t  Resv_4096[2616];
    volatile uint32_t ASF_INT_STATUS;
    volatile uint32_t ASF_INT_RAW_STATUS;
    volatile uint32_t ASF_INT_MASK;
    volatile uint32_t ASF_INT_TEST;
    volatile uint32_t ASF_FATAL_NONFATAL_SELECT;
    volatile uint8_t  Resv_4128[12];
    volatile uint32_t ASF_SRAM_CORR_FAULT_STATUS;
    volatile uint32_t ASF_SRAM_UNCORR_FAULT_STATUS;
    volatile uint32_t ASF_SRAM_FAULT_STATS;
    volatile uint8_t  Resv_4144[4];
    volatile uint32_t ASF_TRANS_TO_CTRL;
    volatile uint32_t ASF_TRANS_TO_FAULT_MASK;
    volatile uint32_t ASF_TRANS_TO_FAULT_STATUS;
    volatile uint8_t  Resv_4160[4];
    volatile uint32_t ASF_PROTOCOL_FAULT_MASK;
    volatile uint32_t ASF_PROTOCOL_FAULT_STATUS;
    volatile uint8_t  Resv_4184[16];
    volatile uint32_t ASF_INTEGRITY_ERR_INJ;
    volatile uint8_t  Resv_4352[164];
    volatile uint32_t MAG_NUM;
    volatile uint32_t MPHYSTAT_XCFGO1;
    volatile uint32_t MPHYSTAT_XCFGO2;
    volatile uint32_t MPHYSTAT_XCFGO3;
    volatile uint32_t MPHYSTAT_XCFGO4;
    volatile uint32_t MPHYSTAT_XCFGO5;
    volatile uint32_t MPHYSTAT_XCFGO6;
    volatile uint32_t MPHYSTAT_XCFGO7;
    volatile uint32_t MPHYSTAT_XCFGO8;
    volatile uint32_t MPHYSTAT_XCFGO9;
    volatile uint32_t MPHY_DEBUG_OUT;
    volatile uint32_t MPHY_BIST;
    volatile uint32_t MPHY_SF;
    volatile uint32_t MPHYSTAT;
    volatile uint32_t MPHY_MMIO_A;
    volatile uint32_t MPHYCFG_XCFGD1;
    volatile uint32_t MPHYCFG_XCFGD2;
    volatile uint32_t MPHYCFG_XCFGD3;
    volatile uint32_t MPHYCFG_XCFGD4;
    volatile uint32_t MPHYCFG_XCFGD5;
    volatile uint32_t MPHYCFG_XCFGA1;
    volatile uint32_t MPHYCFG_XCFGA2;
    volatile uint32_t MPHYCFG_XCFGA3;
    volatile uint32_t MPHYCFG_XCFGA4;
    volatile uint32_t MPHYCFG_XCFGA5;
    volatile uint32_t MPHYCFG_XCFGA6;
    volatile uint32_t MPHYCFG_XCFGA7;
    volatile uint32_t MPHYCFG_XCFGA8;
    volatile uint32_t MPHYCFG_XCFGA9;
    volatile uint32_t MPHYCFG_XCFGA10;
    volatile uint32_t MPHYCFG_XCFGA11;
    volatile uint32_t MPHYCFG_XCFGA12;
    volatile uint32_t MPHYCFG_XCFGA13;
    volatile uint32_t MPHYCFG_MISC;
    volatile uint32_t MPHYCFG_VCONTROL;
    volatile uint32_t MPHY_BIST_CTRLPIN;
    volatile uint32_t MPHY_SF_WD;
} CSL_ufshci_regsRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_UFSHCI_REGS_CAP                                                    (0x00000000U)
#define CSL_UFSHCI_REGS_VER                                                    (0x00000008U)
#define CSL_UFSHCI_REGS_HCPID                                                  (0x00000010U)
#define CSL_UFSHCI_REGS_HCMID                                                  (0x00000014U)
#define CSL_UFSHCI_REGS_AHIT                                                   (0x00000018U)
#define CSL_UFSHCI_REGS_IS                                                     (0x00000020U)
#define CSL_UFSHCI_REGS_IE                                                     (0x00000024U)
#define CSL_UFSHCI_REGS_HCS                                                    (0x00000030U)
#define CSL_UFSHCI_REGS_HCE                                                    (0x00000034U)
#define CSL_UFSHCI_REGS_UECPA                                                  (0x00000038U)
#define CSL_UFSHCI_REGS_UECDL                                                  (0x0000003CU)
#define CSL_UFSHCI_REGS_UECN                                                   (0x00000040U)
#define CSL_UFSHCI_REGS_UECT                                                   (0x00000044U)
#define CSL_UFSHCI_REGS_UECDME                                                 (0x00000048U)
#define CSL_UFSHCI_REGS_UTRIACR                                                (0x0000004CU)
#define CSL_UFSHCI_REGS_UTRLBA                                                 (0x00000050U)
#define CSL_UFSHCI_REGS_UTRLBAU                                                (0x00000054U)
#define CSL_UFSHCI_REGS_UTRLDBR                                                (0x00000058U)
#define CSL_UFSHCI_REGS_UTRLCLR                                                (0x0000005CU)
#define CSL_UFSHCI_REGS_UTRLRSR                                                (0x00000060U)
#define CSL_UFSHCI_REGS_UTRLCNR                                                (0x00000064U)
#define CSL_UFSHCI_REGS_UTMRLBA                                                (0x00000070U)
#define CSL_UFSHCI_REGS_UTMRLBAU                                               (0x00000074U)
#define CSL_UFSHCI_REGS_UTMRLDBR                                               (0x00000078U)
#define CSL_UFSHCI_REGS_UTMRLCLR                                               (0x0000007CU)
#define CSL_UFSHCI_REGS_UTMRLRSR                                               (0x00000080U)
#define CSL_UFSHCI_REGS_UICCMD                                                 (0x00000090U)
#define CSL_UFSHCI_REGS_UICCMDARG1                                             (0x00000094U)
#define CSL_UFSHCI_REGS_UICCMDARG2                                             (0x00000098U)
#define CSL_UFSHCI_REGS_UICCMDARG3                                             (0x0000009CU)
#define CSL_UFSHCI_REGS_SYSTHRTL                                               (0x000000A0U)
#define CSL_UFSHCI_REGS_HCI_MMIO_TOSH_UNIRESPOL                                (0x000000ACU)
#define CSL_UFSHCI_REGS_OSYSR                                                  (0x000000C4U)
#define CSL_UFSHCI_REGS_XCNF                                                   (0x000000C8U)
#define CSL_UFSHCI_REGS_ADSIT                                                  (0x000000CCU)
#define CSL_UFSHCI_REGS_CDACFG                                                 (0x000000D0U)
#define CSL_UFSHCI_REGS_CDATX1                                                 (0x000000D4U)
#define CSL_UFSHCI_REGS_CDATX2                                                 (0x000000D8U)
#define CSL_UFSHCI_REGS_CDARX1                                                 (0x000000DCU)
#define CSL_UFSHCI_REGS_CDARX2                                                 (0x000000E0U)
#define CSL_UFSHCI_REGS_CDASTA                                                 (0x000000E4U)
#define CSL_UFSHCI_REGS_XASB                                                   (0x000000E8U)
#define CSL_UFSHCI_REGS_LBMCFG                                                 (0x000000F0U)
#define CSL_UFSHCI_REGS_LBMSTA                                                 (0x000000F4U)
#define CSL_UFSHCI_REGS_DBG                                                    (0x000000F8U)
#define CSL_UFSHCI_REGS_HCLKDIV                                                (0x000000FCU)
#define CSL_UFSHCI_REGS_CCAP                                                   (0x00000100U)
#define CSL_UFSHCI_REGS_CRYPTOCAP                                              (0x00000104U)
#define CSL_UFSHCI_REGS_CRYPTOCFG0                                             (0x00000500U)
#define CSL_UFSHCI_REGS_CRYPTOCFG1                                             (0x00000504U)
#define CSL_UFSHCI_REGS_CRYPTOCFG2                                             (0x00000508U)
#define CSL_UFSHCI_REGS_CRYPTOCFG3                                             (0x0000050CU)
#define CSL_UFSHCI_REGS_CRYPTOCFG16                                            (0x00000540U)
#define CSL_UFSHCI_REGS_CRYPTOCFG17                                            (0x00000544U)
#define CSL_UFSHCI_REGS_CRYPTOCFG32                                            (0x00000580U)
#define CSL_UFSHCI_REGS_CRYPTOCFG33                                            (0x00000584U)
#define CSL_UFSHCI_REGS_CRYPTOCFG34                                            (0x00000588U)
#define CSL_UFSHCI_REGS_CRYPTOCFG35                                            (0x0000058CU)
#define CSL_UFSHCI_REGS_CRYPTOCFG48                                            (0x000005C0U)
#define CSL_UFSHCI_REGS_CRYPTOCFG49                                            (0x000005C4U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS                                         (0x00001000U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS                                     (0x00001004U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK                                           (0x00001008U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST                                           (0x0000100CU)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT                              (0x00001010U)
#define CSL_UFSHCI_REGS_ASF_SRAM_CORR_FAULT_STATUS                             (0x00001020U)
#define CSL_UFSHCI_REGS_ASF_SRAM_UNCORR_FAULT_STATUS                           (0x00001024U)
#define CSL_UFSHCI_REGS_ASF_SRAM_FAULT_STATS                                   (0x00001028U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL                                      (0x00001030U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK                                (0x00001034U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS                              (0x00001038U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK                                (0x00001040U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS                              (0x00001044U)
#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ                                  (0x00001058U)
#define CSL_UFSHCI_REGS_MAG_NUM                                                (0x00001100U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO1                                        (0x00001104U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO2                                        (0x00001108U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO3                                        (0x0000110CU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO4                                        (0x00001110U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO5                                        (0x00001114U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO6                                        (0x00001118U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO7                                        (0x0000111CU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO8                                        (0x00001120U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO9                                        (0x00001124U)
#define CSL_UFSHCI_REGS_MPHY_DEBUG_OUT                                         (0x00001128U)
#define CSL_UFSHCI_REGS_MPHY_BIST                                              (0x0000112CU)
#define CSL_UFSHCI_REGS_MPHY_SF                                                (0x00001130U)
#define CSL_UFSHCI_REGS_MPHYSTAT                                               (0x00001134U)
#define CSL_UFSHCI_REGS_MPHY_MMIO_A                                            (0x00001138U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD1                                         (0x0000113CU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD2                                         (0x00001140U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD3                                         (0x00001144U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD4                                         (0x00001148U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD5                                         (0x0000114CU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA1                                         (0x00001150U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA2                                         (0x00001154U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA3                                         (0x00001158U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA4                                         (0x0000115CU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA5                                         (0x00001160U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA6                                         (0x00001164U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA7                                         (0x00001168U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA8                                         (0x0000116CU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA9                                         (0x00001170U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA10                                        (0x00001174U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA11                                        (0x00001178U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA12                                        (0x0000117CU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA13                                        (0x00001180U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC                                           (0x00001184U)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL                                       (0x00001188U)
#define CSL_UFSHCI_REGS_MPHY_BIST_CTRLPIN                                      (0x0000118CU)
#define CSL_UFSHCI_REGS_MPHY_SF_WD                                             (0x00001190U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* CAP */

#define CSL_UFSHCI_REGS_CAP_NUTRS_MASK                                         (0x0000001FU)
#define CSL_UFSHCI_REGS_CAP_NUTRS_SHIFT                                        (0x00000000U)
#define CSL_UFSHCI_REGS_CAP_NUTRS_MAX                                          (0x0000001FU)

#define CSL_UFSHCI_REGS_CAP_RES3_MASK                                          (0x000000E0U)
#define CSL_UFSHCI_REGS_CAP_RES3_SHIFT                                         (0x00000005U)
#define CSL_UFSHCI_REGS_CAP_RES3_MAX                                           (0x00000007U)

#define CSL_UFSHCI_REGS_CAP_NORTT_MASK                                         (0x0000FF00U)
#define CSL_UFSHCI_REGS_CAP_NORTT_SHIFT                                        (0x00000008U)
#define CSL_UFSHCI_REGS_CAP_NORTT_MAX                                          (0x000000FFU)

#define CSL_UFSHCI_REGS_CAP_NUTMRS_MASK                                        (0x00070000U)
#define CSL_UFSHCI_REGS_CAP_NUTMRS_SHIFT                                       (0x00000010U)
#define CSL_UFSHCI_REGS_CAP_NUTMRS_MAX                                         (0x00000007U)

#define CSL_UFSHCI_REGS_CAP_RES2_MASK                                          (0x00780000U)
#define CSL_UFSHCI_REGS_CAP_RES2_SHIFT                                         (0x00000013U)
#define CSL_UFSHCI_REGS_CAP_RES2_MAX                                           (0x0000000FU)

#define CSL_UFSHCI_REGS_CAP_AUTOH8_MASK                                        (0x00800000U)
#define CSL_UFSHCI_REGS_CAP_AUTOH8_SHIFT                                       (0x00000017U)
#define CSL_UFSHCI_REGS_CAP_AUTOH8_MAX                                         (0x00000001U)

#define CSL_UFSHCI_REGS_CAP_AS64_MASK                                          (0x01000000U)
#define CSL_UFSHCI_REGS_CAP_AS64_SHIFT                                         (0x00000018U)
#define CSL_UFSHCI_REGS_CAP_AS64_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_CAP_OODDS_MASK                                         (0x02000000U)
#define CSL_UFSHCI_REGS_CAP_OODDS_SHIFT                                        (0x00000019U)
#define CSL_UFSHCI_REGS_CAP_OODDS_MAX                                          (0x00000001U)

#define CSL_UFSHCI_REGS_CAP_UICDMETMS_MASK                                     (0x04000000U)
#define CSL_UFSHCI_REGS_CAP_UICDMETMS_SHIFT                                    (0x0000001AU)
#define CSL_UFSHCI_REGS_CAP_UICDMETMS_MAX                                      (0x00000001U)

#define CSL_UFSHCI_REGS_CAP_DBMMS_MASK                                         (0x08000000U)
#define CSL_UFSHCI_REGS_CAP_DBMMS_SHIFT                                        (0x0000001BU)
#define CSL_UFSHCI_REGS_CAP_DBMMS_MAX                                          (0x00000001U)

#define CSL_UFSHCI_REGS_CAP_CS_MASK                                            (0x10000000U)
#define CSL_UFSHCI_REGS_CAP_CS_SHIFT                                           (0x0000001CU)
#define CSL_UFSHCI_REGS_CAP_CS_MAX                                             (0x00000001U)

#define CSL_UFSHCI_REGS_CAP_MHS_MASK                                           (0x20000000U)
#define CSL_UFSHCI_REGS_CAP_MHS_SHIFT                                          (0x0000001DU)
#define CSL_UFSHCI_REGS_CAP_MHS_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_CAP_RES1_MASK                                          (0xC0000000U)
#define CSL_UFSHCI_REGS_CAP_RES1_SHIFT                                         (0x0000001EU)
#define CSL_UFSHCI_REGS_CAP_RES1_MAX                                           (0x00000003U)

/* VER */

#define CSL_UFSHCI_REGS_VER_VER_MASK                                           (0x0000000FU)
#define CSL_UFSHCI_REGS_VER_VER_SHIFT                                          (0x00000000U)
#define CSL_UFSHCI_REGS_VER_VER_MAX                                            (0x0000000FU)

#define CSL_UFSHCI_REGS_VER_MNR_MASK                                           (0x000000F0U)
#define CSL_UFSHCI_REGS_VER_MNR_SHIFT                                          (0x00000004U)
#define CSL_UFSHCI_REGS_VER_MNR_MAX                                            (0x0000000FU)

#define CSL_UFSHCI_REGS_VER_MJR_MASK                                           (0x0000FF00U)
#define CSL_UFSHCI_REGS_VER_MJR_SHIFT                                          (0x00000008U)
#define CSL_UFSHCI_REGS_VER_MJR_MAX                                            (0x000000FFU)

/* HCPID */

#define CSL_UFSHCI_REGS_HCPID_PID_MASK                                         (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_HCPID_PID_SHIFT                                        (0x00000000U)
#define CSL_UFSHCI_REGS_HCPID_PID_MAX                                          (0xFFFFFFFFU)

/* HCMID */

#define CSL_UFSHCI_REGS_HCMID_MIC_MASK                                         (0x000000FFU)
#define CSL_UFSHCI_REGS_HCMID_MIC_SHIFT                                        (0x00000000U)
#define CSL_UFSHCI_REGS_HCMID_MIC_MAX                                          (0x000000FFU)

#define CSL_UFSHCI_REGS_HCMID_BI_MASK                                          (0x0000FF00U)
#define CSL_UFSHCI_REGS_HCMID_BI_SHIFT                                         (0x00000008U)
#define CSL_UFSHCI_REGS_HCMID_BI_MAX                                           (0x000000FFU)

/* AHIT */

#define CSL_UFSHCI_REGS_AHIT_AH8ITV_MASK                                       (0x000003FFU)
#define CSL_UFSHCI_REGS_AHIT_AH8ITV_SHIFT                                      (0x00000000U)
#define CSL_UFSHCI_REGS_AHIT_AH8ITV_MAX                                        (0x000003FFU)

#define CSL_UFSHCI_REGS_AHIT_TS_MASK                                           (0x00001C00U)
#define CSL_UFSHCI_REGS_AHIT_TS_SHIFT                                          (0x0000000AU)
#define CSL_UFSHCI_REGS_AHIT_TS_MAX                                            (0x00000007U)

/* IS */

#define CSL_UFSHCI_REGS_IS_UTRCS_MASK                                          (0x00000001U)
#define CSL_UFSHCI_REGS_IS_UTRCS_SHIFT                                         (0x00000000U)
#define CSL_UFSHCI_REGS_IS_UTRCS_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IS_UDEPRI_MASK                                         (0x00000002U)
#define CSL_UFSHCI_REGS_IS_UDEPRI_SHIFT                                        (0x00000001U)
#define CSL_UFSHCI_REGS_IS_UDEPRI_MAX                                          (0x00000001U)

#define CSL_UFSHCI_REGS_IS_UE_MASK                                             (0x00000004U)
#define CSL_UFSHCI_REGS_IS_UE_SHIFT                                            (0x00000002U)
#define CSL_UFSHCI_REGS_IS_UE_MAX                                              (0x00000001U)

#define CSL_UFSHCI_REGS_IS_UTMS_MASK                                           (0x00000008U)
#define CSL_UFSHCI_REGS_IS_UTMS_SHIFT                                          (0x00000003U)
#define CSL_UFSHCI_REGS_IS_UTMS_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IS_UPMS_MASK                                           (0x00000010U)
#define CSL_UFSHCI_REGS_IS_UPMS_SHIFT                                          (0x00000004U)
#define CSL_UFSHCI_REGS_IS_UPMS_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IS_UHXS_MASK                                           (0x00000020U)
#define CSL_UFSHCI_REGS_IS_UHXS_SHIFT                                          (0x00000005U)
#define CSL_UFSHCI_REGS_IS_UHXS_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IS_UHES_MASK                                           (0x00000040U)
#define CSL_UFSHCI_REGS_IS_UHES_SHIFT                                          (0x00000006U)
#define CSL_UFSHCI_REGS_IS_UHES_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IS_ULLS_MASK                                           (0x00000080U)
#define CSL_UFSHCI_REGS_IS_ULLS_SHIFT                                          (0x00000007U)
#define CSL_UFSHCI_REGS_IS_ULLS_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IS_ULSS_MASK                                           (0x00000100U)
#define CSL_UFSHCI_REGS_IS_ULSS_SHIFT                                          (0x00000008U)
#define CSL_UFSHCI_REGS_IS_ULSS_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IS_UTMRCS_MASK                                         (0x00000200U)
#define CSL_UFSHCI_REGS_IS_UTMRCS_SHIFT                                        (0x00000009U)
#define CSL_UFSHCI_REGS_IS_UTMRCS_MAX                                          (0x00000001U)

#define CSL_UFSHCI_REGS_IS_UCCS_MASK                                           (0x00000400U)
#define CSL_UFSHCI_REGS_IS_UCCS_SHIFT                                          (0x0000000AU)
#define CSL_UFSHCI_REGS_IS_UCCS_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IS_DFES_MASK                                           (0x00000800U)
#define CSL_UFSHCI_REGS_IS_DFES_SHIFT                                          (0x0000000BU)
#define CSL_UFSHCI_REGS_IS_DFES_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IS_UTPES_MASK                                          (0x00001000U)
#define CSL_UFSHCI_REGS_IS_UTPES_SHIFT                                         (0x0000000CU)
#define CSL_UFSHCI_REGS_IS_UTPES_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IS_HCFES_MASK                                          (0x00010000U)
#define CSL_UFSHCI_REGS_IS_HCFES_SHIFT                                         (0x00000010U)
#define CSL_UFSHCI_REGS_IS_HCFES_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IS_SBFES_MASK                                          (0x00020000U)
#define CSL_UFSHCI_REGS_IS_SBFES_SHIFT                                         (0x00000011U)
#define CSL_UFSHCI_REGS_IS_SBFES_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IS_CEFES_MASK                                          (0x00040000U)
#define CSL_UFSHCI_REGS_IS_CEFES_SHIFT                                         (0x00000012U)
#define CSL_UFSHCI_REGS_IS_CEFES_MAX                                           (0x00000001U)

/* IE */

#define CSL_UFSHCI_REGS_IE_UTRCE_MASK                                          (0x00000001U)
#define CSL_UFSHCI_REGS_IE_UTRCE_SHIFT                                         (0x00000000U)
#define CSL_UFSHCI_REGS_IE_UTRCE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_UDEPRIE_MASK                                        (0x00000002U)
#define CSL_UFSHCI_REGS_IE_UDEPRIE_SHIFT                                       (0x00000001U)
#define CSL_UFSHCI_REGS_IE_UDEPRIE_MAX                                         (0x00000001U)

#define CSL_UFSHCI_REGS_IE_UEE_MASK                                            (0x00000004U)
#define CSL_UFSHCI_REGS_IE_UEE_SHIFT                                           (0x00000002U)
#define CSL_UFSHCI_REGS_IE_UEE_MAX                                             (0x00000001U)

#define CSL_UFSHCI_REGS_IE_UTMSE_MASK                                          (0x00000008U)
#define CSL_UFSHCI_REGS_IE_UTMSE_SHIFT                                         (0x00000003U)
#define CSL_UFSHCI_REGS_IE_UTMSE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_UPMSE_MASK                                          (0x00000010U)
#define CSL_UFSHCI_REGS_IE_UPMSE_SHIFT                                         (0x00000004U)
#define CSL_UFSHCI_REGS_IE_UPMSE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_UHXSE_MASK                                          (0x00000020U)
#define CSL_UFSHCI_REGS_IE_UHXSE_SHIFT                                         (0x00000005U)
#define CSL_UFSHCI_REGS_IE_UHXSE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_UHESE_MASK                                          (0x00000040U)
#define CSL_UFSHCI_REGS_IE_UHESE_SHIFT                                         (0x00000006U)
#define CSL_UFSHCI_REGS_IE_UHESE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_ULLSE_MASK                                          (0x00000080U)
#define CSL_UFSHCI_REGS_IE_ULLSE_SHIFT                                         (0x00000007U)
#define CSL_UFSHCI_REGS_IE_ULLSE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_ULSSE_MASK                                          (0x00000100U)
#define CSL_UFSHCI_REGS_IE_ULSSE_SHIFT                                         (0x00000008U)
#define CSL_UFSHCI_REGS_IE_ULSSE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_UTMRCE_MASK                                         (0x00000200U)
#define CSL_UFSHCI_REGS_IE_UTMRCE_SHIFT                                        (0x00000009U)
#define CSL_UFSHCI_REGS_IE_UTMRCE_MAX                                          (0x00000001U)

#define CSL_UFSHCI_REGS_IE_UCCE_MASK                                           (0x00000400U)
#define CSL_UFSHCI_REGS_IE_UCCE_SHIFT                                          (0x0000000AU)
#define CSL_UFSHCI_REGS_IE_UCCE_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IE_DFEE_MASK                                           (0x00000800U)
#define CSL_UFSHCI_REGS_IE_DFEE_SHIFT                                          (0x0000000BU)
#define CSL_UFSHCI_REGS_IE_DFEE_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_IE_UTPEE_MASK                                          (0x00001000U)
#define CSL_UFSHCI_REGS_IE_UTPEE_SHIFT                                         (0x0000000CU)
#define CSL_UFSHCI_REGS_IE_UTPEE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_HCFEE_MASK                                          (0x00010000U)
#define CSL_UFSHCI_REGS_IE_HCFEE_SHIFT                                         (0x00000010U)
#define CSL_UFSHCI_REGS_IE_HCFEE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_SBFEE_MASK                                          (0x00020000U)
#define CSL_UFSHCI_REGS_IE_SBFEE_SHIFT                                         (0x00000011U)
#define CSL_UFSHCI_REGS_IE_SBFEE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_IE_CEFEE_MASK                                          (0x00040000U)
#define CSL_UFSHCI_REGS_IE_CEFEE_SHIFT                                         (0x00000012U)
#define CSL_UFSHCI_REGS_IE_CEFEE_MAX                                           (0x00000001U)

/* HCS */

#define CSL_UFSHCI_REGS_HCS_DP_MASK                                            (0x00000001U)
#define CSL_UFSHCI_REGS_HCS_DP_SHIFT                                           (0x00000000U)
#define CSL_UFSHCI_REGS_HCS_DP_MAX                                             (0x00000001U)

#define CSL_UFSHCI_REGS_HCS_UTRLRDY_MASK                                       (0x00000002U)
#define CSL_UFSHCI_REGS_HCS_UTRLRDY_SHIFT                                      (0x00000001U)
#define CSL_UFSHCI_REGS_HCS_UTRLRDY_MAX                                        (0x00000001U)

#define CSL_UFSHCI_REGS_HCS_UTMRLRDY_MASK                                      (0x00000004U)
#define CSL_UFSHCI_REGS_HCS_UTMRLRDY_SHIFT                                     (0x00000002U)
#define CSL_UFSHCI_REGS_HCS_UTMRLRDY_MAX                                       (0x00000001U)

#define CSL_UFSHCI_REGS_HCS_UCRDY_MASK                                         (0x00000008U)
#define CSL_UFSHCI_REGS_HCS_UCRDY_SHIFT                                        (0x00000003U)
#define CSL_UFSHCI_REGS_HCS_UCRDY_MAX                                          (0x00000001U)

#define CSL_UFSHCI_REGS_HCS_UPMCRS_MASK                                        (0x00000700U)
#define CSL_UFSHCI_REGS_HCS_UPMCRS_SHIFT                                       (0x00000008U)
#define CSL_UFSHCI_REGS_HCS_UPMCRS_MAX                                         (0x00000007U)

#define CSL_UFSHCI_REGS_HCS_UTPEC_MASK                                         (0x0000F000U)
#define CSL_UFSHCI_REGS_HCS_UTPEC_SHIFT                                        (0x0000000CU)
#define CSL_UFSHCI_REGS_HCS_UTPEC_MAX                                          (0x0000000FU)

#define CSL_UFSHCI_REGS_HCS_TTAGUTPE_MASK                                      (0x00FF0000U)
#define CSL_UFSHCI_REGS_HCS_TTAGUTPE_SHIFT                                     (0x00000010U)
#define CSL_UFSHCI_REGS_HCS_TTAGUTPE_MAX                                       (0x000000FFU)

#define CSL_UFSHCI_REGS_HCS_TLUNUTPE_MASK                                      (0xFF000000U)
#define CSL_UFSHCI_REGS_HCS_TLUNUTPE_SHIFT                                     (0x00000018U)
#define CSL_UFSHCI_REGS_HCS_TLUNUTPE_MAX                                       (0x000000FFU)

/* HCE */

#define CSL_UFSHCI_REGS_HCE_HCE_MASK                                           (0x00000001U)
#define CSL_UFSHCI_REGS_HCE_HCE_SHIFT                                          (0x00000000U)
#define CSL_UFSHCI_REGS_HCE_HCE_MAX                                            (0x00000001U)

#define CSL_UFSHCI_REGS_HCE_CGE_MASK                                           (0x00000002U)
#define CSL_UFSHCI_REGS_HCE_CGE_SHIFT                                          (0x00000001U)
#define CSL_UFSHCI_REGS_HCE_CGE_MAX                                            (0x00000001U)

/* UECPA */

#define CSL_UFSHCI_REGS_UECPA_EC_MASK                                          (0x0000001FU)
#define CSL_UFSHCI_REGS_UECPA_EC_SHIFT                                         (0x00000000U)
#define CSL_UFSHCI_REGS_UECPA_EC_MAX                                           (0x0000001FU)

#define CSL_UFSHCI_REGS_UECPA_ERR_MASK                                         (0x80000000U)
#define CSL_UFSHCI_REGS_UECPA_ERR_SHIFT                                        (0x0000001FU)
#define CSL_UFSHCI_REGS_UECPA_ERR_MAX                                          (0x00000001U)

/* UECDL */

#define CSL_UFSHCI_REGS_UECDL_EC_MASK                                          (0x00007FFFU)
#define CSL_UFSHCI_REGS_UECDL_EC_SHIFT                                         (0x00000000U)
#define CSL_UFSHCI_REGS_UECDL_EC_MAX                                           (0x00007FFFU)

#define CSL_UFSHCI_REGS_UECDL_ERR_MASK                                         (0x80000000U)
#define CSL_UFSHCI_REGS_UECDL_ERR_SHIFT                                        (0x0000001FU)
#define CSL_UFSHCI_REGS_UECDL_ERR_MAX                                          (0x00000001U)

/* UECN */

#define CSL_UFSHCI_REGS_UECN_EC_MASK                                           (0x00000007U)
#define CSL_UFSHCI_REGS_UECN_EC_SHIFT                                          (0x00000000U)
#define CSL_UFSHCI_REGS_UECN_EC_MAX                                            (0x00000007U)

#define CSL_UFSHCI_REGS_UECN_ERR_MASK                                          (0x80000000U)
#define CSL_UFSHCI_REGS_UECN_ERR_SHIFT                                         (0x0000001FU)
#define CSL_UFSHCI_REGS_UECN_ERR_MAX                                           (0x00000001U)

/* UECT */

#define CSL_UFSHCI_REGS_UECT_EC_MASK                                           (0x0000007FU)
#define CSL_UFSHCI_REGS_UECT_EC_SHIFT                                          (0x00000000U)
#define CSL_UFSHCI_REGS_UECT_EC_MAX                                            (0x0000007FU)

#define CSL_UFSHCI_REGS_UECT_ERR_MASK                                          (0x80000000U)
#define CSL_UFSHCI_REGS_UECT_ERR_SHIFT                                         (0x0000001FU)
#define CSL_UFSHCI_REGS_UECT_ERR_MAX                                           (0x00000001U)

/* UECDME */

#define CSL_UFSHCI_REGS_UECDME_EC_MASK                                         (0x00000001U)
#define CSL_UFSHCI_REGS_UECDME_EC_SHIFT                                        (0x00000000U)
#define CSL_UFSHCI_REGS_UECDME_EC_MAX                                          (0x00000001U)

#define CSL_UFSHCI_REGS_UECDME_ERR_MASK                                        (0x80000000U)
#define CSL_UFSHCI_REGS_UECDME_ERR_SHIFT                                       (0x0000001FU)
#define CSL_UFSHCI_REGS_UECDME_ERR_MAX                                         (0x00000001U)

/* UTRIACR */

#define CSL_UFSHCI_REGS_UTRIACR_IATOVAL_MASK                                   (0x000000FFU)
#define CSL_UFSHCI_REGS_UTRIACR_IATOVAL_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_UTRIACR_IATOVAL_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_UTRIACR_IACTH_MASK                                     (0x00001F00U)
#define CSL_UFSHCI_REGS_UTRIACR_IACTH_SHIFT                                    (0x00000008U)
#define CSL_UFSHCI_REGS_UTRIACR_IACTH_MAX                                      (0x0000001FU)

#define CSL_UFSHCI_REGS_UTRIACR_CTR_MASK                                       (0x00010000U)
#define CSL_UFSHCI_REGS_UTRIACR_CTR_SHIFT                                      (0x00000010U)
#define CSL_UFSHCI_REGS_UTRIACR_CTR_MAX                                        (0x00000001U)

#define CSL_UFSHCI_REGS_UTRIACR_IASB_MASK                                      (0x00100000U)
#define CSL_UFSHCI_REGS_UTRIACR_IASB_SHIFT                                     (0x00000014U)
#define CSL_UFSHCI_REGS_UTRIACR_IASB_MAX                                       (0x00000001U)

#define CSL_UFSHCI_REGS_UTRIACR_IAPWEN_MASK                                    (0x01000000U)
#define CSL_UFSHCI_REGS_UTRIACR_IAPWEN_SHIFT                                   (0x00000018U)
#define CSL_UFSHCI_REGS_UTRIACR_IAPWEN_MAX                                     (0x00000001U)

#define CSL_UFSHCI_REGS_UTRIACR_IAEN_MASK                                      (0x80000000U)
#define CSL_UFSHCI_REGS_UTRIACR_IAEN_SHIFT                                     (0x0000001FU)
#define CSL_UFSHCI_REGS_UTRIACR_IAEN_MAX                                       (0x00000001U)

/* UTRLBA */

#define CSL_UFSHCI_REGS_UTRLBA_UTRLBA_MASK                                     (0xFFFFFC00U)
#define CSL_UFSHCI_REGS_UTRLBA_UTRLBA_SHIFT                                    (0x0000000AU)
#define CSL_UFSHCI_REGS_UTRLBA_UTRLBA_MAX                                      (0x003FFFFFU)

/* UTRLBAU */

#define CSL_UFSHCI_REGS_UTRLBAU_UTRLBAU_MASK                                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_UTRLBAU_UTRLBAU_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_UTRLBAU_UTRLBAU_MAX                                    (0xFFFFFFFFU)

/* UTRLDBR */

#define CSL_UFSHCI_REGS_UTRLDBR_UTRLDBR_MASK                                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_UTRLDBR_UTRLDBR_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_UTRLDBR_UTRLDBR_MAX                                    (0xFFFFFFFFU)

/* UTRLCLR */

#define CSL_UFSHCI_REGS_UTRLCLR_UTRLCLR_MASK                                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_UTRLCLR_UTRLCLR_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_UTRLCLR_UTRLCLR_MAX                                    (0xFFFFFFFFU)

/* UTRLRSR */

#define CSL_UFSHCI_REGS_UTRLRSR_UTRLRSR_MASK                                   (0x00000001U)
#define CSL_UFSHCI_REGS_UTRLRSR_UTRLRSR_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_UTRLRSR_UTRLRSR_MAX                                    (0x00000001U)

/* UTRLCNR */

#define CSL_UFSHCI_REGS_UTRLCNR_UTRLCNR_MASK                                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_UTRLCNR_UTRLCNR_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_UTRLCNR_UTRLCNR_MAX                                    (0xFFFFFFFFU)

/* UTMRLBA */

#define CSL_UFSHCI_REGS_UTMRLBA_UTMRLBA_MASK                                   (0xFFFFFC00U)
#define CSL_UFSHCI_REGS_UTMRLBA_UTMRLBA_SHIFT                                  (0x0000000AU)
#define CSL_UFSHCI_REGS_UTMRLBA_UTMRLBA_MAX                                    (0x003FFFFFU)

/* UTMRLBAU */

#define CSL_UFSHCI_REGS_UTMRLBAU_UTMRLBAU_MASK                                 (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_UTMRLBAU_UTMRLBAU_SHIFT                                (0x00000000U)
#define CSL_UFSHCI_REGS_UTMRLBAU_UTMRLBAU_MAX                                  (0xFFFFFFFFU)

/* UTMRLDBR */

#define CSL_UFSHCI_REGS_UTMRLDBR_UTMRLDBR_MASK                                 (0x000000FFU)
#define CSL_UFSHCI_REGS_UTMRLDBR_UTMRLDBR_SHIFT                                (0x00000000U)
#define CSL_UFSHCI_REGS_UTMRLDBR_UTMRLDBR_MAX                                  (0x000000FFU)

/* UTMRLCLR */

#define CSL_UFSHCI_REGS_UTMRLCLR_UTMRLCLR_MASK                                 (0x000000FFU)
#define CSL_UFSHCI_REGS_UTMRLCLR_UTMRLCLR_SHIFT                                (0x00000000U)
#define CSL_UFSHCI_REGS_UTMRLCLR_UTMRLCLR_MAX                                  (0x000000FFU)

/* UTMRLRSR */

#define CSL_UFSHCI_REGS_UTMRLRSR_UTMRLRSR_MASK                                 (0x00000001U)
#define CSL_UFSHCI_REGS_UTMRLRSR_UTMRLRSR_SHIFT                                (0x00000000U)
#define CSL_UFSHCI_REGS_UTMRLRSR_UTMRLRSR_MAX                                  (0x00000001U)

/* UICCMD */

#define CSL_UFSHCI_REGS_UICCMD_CMDOP_MASK                                      (0x000000FFU)
#define CSL_UFSHCI_REGS_UICCMD_CMDOP_SHIFT                                     (0x00000000U)
#define CSL_UFSHCI_REGS_UICCMD_CMDOP_MAX                                       (0x000000FFU)

/* UICCMDARG1 */

#define CSL_UFSHCI_REGS_UICCMDARG1_ARG1_MASK                                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_UICCMDARG1_ARG1_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_UICCMDARG1_ARG1_MAX                                    (0xFFFFFFFFU)

/* UICCMDARG2 */

#define CSL_UFSHCI_REGS_UICCMDARG2_ARG2_MASK                                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_UICCMDARG2_ARG2_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_UICCMDARG2_ARG2_MAX                                    (0xFFFFFFFFU)

/* UICCMDARG3 */

#define CSL_UFSHCI_REGS_UICCMDARG3_ARG3_MASK                                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_UICCMDARG3_ARG3_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_UICCMDARG3_ARG3_MAX                                    (0xFFFFFFFFU)

/* SYSTHRTL */

#define CSL_UFSHCI_REGS_SYSTHRTL_SYSDLY_MASK                                   (0x000000FFU)
#define CSL_UFSHCI_REGS_SYSTHRTL_SYSDLY_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_SYSTHRTL_SYSDLY_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_SYSTHRTL_MAXOSYSRR_MASK                                (0x0000FF00U)
#define CSL_UFSHCI_REGS_SYSTHRTL_MAXOSYSRR_SHIFT                               (0x00000008U)
#define CSL_UFSHCI_REGS_SYSTHRTL_MAXOSYSRR_MAX                                 (0x000000FFU)

#define CSL_UFSHCI_REGS_SYSTHRTL_MAXOSYSRW_MASK                                (0x01FF0000U)
#define CSL_UFSHCI_REGS_SYSTHRTL_MAXOSYSRW_SHIFT                               (0x00000010U)
#define CSL_UFSHCI_REGS_SYSTHRTL_MAXOSYSRW_MAX                                 (0x000001FFU)

#define CSL_UFSHCI_REGS_SYSTHRTL_RES4_MASK                                     (0xFE000000U)
#define CSL_UFSHCI_REGS_SYSTHRTL_RES4_SHIFT                                    (0x00000019U)
#define CSL_UFSHCI_REGS_SYSTHRTL_RES4_MAX                                      (0x0000007FU)

/* HCI_MMIO_TOSH_UNIRESPOL */

#define CSL_UFSHCI_REGS_HCI_MMIO_TOSH_UNIRESPOL_RESPOL_MASK                    (0x00000001U)
#define CSL_UFSHCI_REGS_HCI_MMIO_TOSH_UNIRESPOL_RESPOL_SHIFT                   (0x00000000U)
#define CSL_UFSHCI_REGS_HCI_MMIO_TOSH_UNIRESPOL_RESPOL_MAX                     (0x00000001U)

/* OSYSR */

#define CSL_UFSHCI_REGS_OSYSR_OSYSR_MASK                                       (0x0000003FU)
#define CSL_UFSHCI_REGS_OSYSR_OSYSR_SHIFT                                      (0x00000000U)
#define CSL_UFSHCI_REGS_OSYSR_OSYSR_MAX                                        (0x0000003FU)

#define CSL_UFSHCI_REGS_OSYSR_OSYSW_MASK                                       (0x00000FC0U)
#define CSL_UFSHCI_REGS_OSYSR_OSYSW_SHIFT                                      (0x00000006U)
#define CSL_UFSHCI_REGS_OSYSR_OSYSW_MAX                                        (0x0000003FU)

/* XCNF */

#define CSL_UFSHCI_REGS_XCNF_XRSE_MASK                                         (0x00000001U)
#define CSL_UFSHCI_REGS_XCNF_XRSE_SHIFT                                        (0x00000000U)
#define CSL_UFSHCI_REGS_XCNF_XRSE_MAX                                          (0x00000001U)

#define CSL_UFSHCI_REGS_XCNF_DSE_MASK                                          (0x00000002U)
#define CSL_UFSHCI_REGS_XCNF_DSE_SHIFT                                         (0x00000001U)
#define CSL_UFSHCI_REGS_XCNF_DSE_MAX                                           (0x00000001U)

#define CSL_UFSHCI_REGS_XCNF_AXIIDS_MASK                                       (0x00000004U)
#define CSL_UFSHCI_REGS_XCNF_AXIIDS_SHIFT                                      (0x00000002U)
#define CSL_UFSHCI_REGS_XCNF_AXIIDS_MAX                                        (0x00000001U)

#define CSL_UFSHCI_REGS_XCNF_MCLKGE_MASK                                       (0x000000F8U)
#define CSL_UFSHCI_REGS_XCNF_MCLKGE_SHIFT                                      (0x00000003U)
#define CSL_UFSHCI_REGS_XCNF_MCLKGE_MAX                                        (0x0000001FU)

#define CSL_UFSHCI_REGS_XCNF_RES12_MASK                                        (0x00000300U)
#define CSL_UFSHCI_REGS_XCNF_RES12_SHIFT                                       (0x00000008U)
#define CSL_UFSHCI_REGS_XCNF_RES12_MAX                                         (0x00000003U)

#define CSL_UFSHCI_REGS_XCNF_MHSDIS_MASK                                       (0x00000400U)
#define CSL_UFSHCI_REGS_XCNF_MHSDIS_SHIFT                                      (0x0000000AU)
#define CSL_UFSHCI_REGS_XCNF_MHSDIS_MAX                                        (0x00000001U)

#define CSL_UFSHCI_REGS_XCNF_RES12A_MASK                                       (0x00000800U)
#define CSL_UFSHCI_REGS_XCNF_RES12A_SHIFT                                      (0x0000000BU)
#define CSL_UFSHCI_REGS_XCNF_RES12A_MAX                                        (0x00000001U)

#define CSL_UFSHCI_REGS_XCNF_CAPWREN_MASK                                      (0x00001000U)
#define CSL_UFSHCI_REGS_XCNF_CAPWREN_SHIFT                                     (0x0000000CU)
#define CSL_UFSHCI_REGS_XCNF_CAPWREN_MAX                                       (0x00000001U)

#define CSL_UFSHCI_REGS_XCNF_RES11_MASK                                        (0x00002000U)
#define CSL_UFSHCI_REGS_XCNF_RES11_SHIFT                                       (0x0000000DU)
#define CSL_UFSHCI_REGS_XCNF_RES11_MAX                                         (0x00000001U)

#define CSL_UFSHCI_REGS_XCNF_DSGM_MASK                                         (0x0000C000U)
#define CSL_UFSHCI_REGS_XCNF_DSGM_SHIFT                                        (0x0000000EU)
#define CSL_UFSHCI_REGS_XCNF_DSGM_MAX                                          (0x00000003U)

#define CSL_UFSHCI_REGS_XCNF_PCPCONFEX_MASK                                    (0x00030000U)
#define CSL_UFSHCI_REGS_XCNF_PCPCONFEX_SHIFT                                   (0x00000010U)
#define CSL_UFSHCI_REGS_XCNF_PCPCONFEX_MAX                                     (0x00000003U)

#define CSL_UFSHCI_REGS_XCNF_RES10_MASK                                        (0xFFFC0000U)
#define CSL_UFSHCI_REGS_XCNF_RES10_SHIFT                                       (0x00000012U)
#define CSL_UFSHCI_REGS_XCNF_RES10_MAX                                         (0x00003FFFU)

/* ADSIT */

#define CSL_UFSHCI_REGS_ADSIT_ADSTV_MASK                                       (0x000003FFU)
#define CSL_UFSHCI_REGS_ADSIT_ADSTV_SHIFT                                      (0x00000000U)
#define CSL_UFSHCI_REGS_ADSIT_ADSTV_MAX                                        (0x000003FFU)

#define CSL_UFSHCI_REGS_ADSIT_TS_MASK                                          (0x00001C00U)
#define CSL_UFSHCI_REGS_ADSIT_TS_SHIFT                                         (0x0000000AU)
#define CSL_UFSHCI_REGS_ADSIT_TS_MAX                                           (0x00000007U)

/* CDACFG */

#define CSL_UFSHCI_REGS_CDACFG_CDABES_MASK                                     (0x000000FFU)
#define CSL_UFSHCI_REGS_CDACFG_CDABES_SHIFT                                    (0x00000000U)
#define CSL_UFSHCI_REGS_CDACFG_CDABES_MAX                                      (0x000000FFU)

#define CSL_UFSHCI_REGS_CDACFG_CDABE_MASK                                      (0x0000FF00U)
#define CSL_UFSHCI_REGS_CDACFG_CDABE_SHIFT                                     (0x00000008U)
#define CSL_UFSHCI_REGS_CDACFG_CDABE_MAX                                       (0x000000FFU)

#define CSL_UFSHCI_REGS_CDACFG_CDAEOM_MASK                                     (0x00010000U)
#define CSL_UFSHCI_REGS_CDACFG_CDAEOM_SHIFT                                    (0x00000010U)
#define CSL_UFSHCI_REGS_CDACFG_CDAEOM_MAX                                      (0x00000001U)

#define CSL_UFSHCI_REGS_CDACFG_CDAEN_MASK                                      (0x10000000U)
#define CSL_UFSHCI_REGS_CDACFG_CDAEN_SHIFT                                     (0x0000001CU)
#define CSL_UFSHCI_REGS_CDACFG_CDAEN_MAX                                       (0x00000001U)

/* CDATX1 */

#define CSL_UFSHCI_REGS_CDATX1_CDATX1B7_MASK                                   (0x000000FFU)
#define CSL_UFSHCI_REGS_CDATX1_CDATX1B7_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_CDATX1_CDATX1B7_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDATX1_CDATX1B6_MASK                                   (0x0000FF00U)
#define CSL_UFSHCI_REGS_CDATX1_CDATX1B6_SHIFT                                  (0x00000008U)
#define CSL_UFSHCI_REGS_CDATX1_CDATX1B6_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDATX1_CDATX1B5_MASK                                   (0x00FF0000U)
#define CSL_UFSHCI_REGS_CDATX1_CDATX1B5_SHIFT                                  (0x00000010U)
#define CSL_UFSHCI_REGS_CDATX1_CDATX1B5_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDATX1_CDATX1B4_MASK                                   (0xFF000000U)
#define CSL_UFSHCI_REGS_CDATX1_CDATX1B4_SHIFT                                  (0x00000018U)
#define CSL_UFSHCI_REGS_CDATX1_CDATX1B4_MAX                                    (0x000000FFU)

/* CDATX2 */

#define CSL_UFSHCI_REGS_CDATX2_CDATX2B3_MASK                                   (0x000000FFU)
#define CSL_UFSHCI_REGS_CDATX2_CDATX2B3_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_CDATX2_CDATX2B3_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDATX2_CDATX2B2_MASK                                   (0x0000FF00U)
#define CSL_UFSHCI_REGS_CDATX2_CDATX2B2_SHIFT                                  (0x00000008U)
#define CSL_UFSHCI_REGS_CDATX2_CDATX2B2_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDATX2_CDATX2B1_MASK                                   (0x00FF0000U)
#define CSL_UFSHCI_REGS_CDATX2_CDATX2B1_SHIFT                                  (0x00000010U)
#define CSL_UFSHCI_REGS_CDATX2_CDATX2B1_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDATX2_CDATX2B0_MASK                                   (0xFF000000U)
#define CSL_UFSHCI_REGS_CDATX2_CDATX2B0_SHIFT                                  (0x00000018U)
#define CSL_UFSHCI_REGS_CDATX2_CDATX2B0_MAX                                    (0x000000FFU)

/* CDARX1 */

#define CSL_UFSHCI_REGS_CDARX1_CDARX1B7_MASK                                   (0x000000FFU)
#define CSL_UFSHCI_REGS_CDARX1_CDARX1B7_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_CDARX1_CDARX1B7_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDARX1_CDARX1B6_MASK                                   (0x0000FF00U)
#define CSL_UFSHCI_REGS_CDARX1_CDARX1B6_SHIFT                                  (0x00000008U)
#define CSL_UFSHCI_REGS_CDARX1_CDARX1B6_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDARX1_CDARX1B5_MASK                                   (0x00FF0000U)
#define CSL_UFSHCI_REGS_CDARX1_CDARX1B5_SHIFT                                  (0x00000010U)
#define CSL_UFSHCI_REGS_CDARX1_CDARX1B5_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDARX1_CDARX1B4_MASK                                   (0xFF000000U)
#define CSL_UFSHCI_REGS_CDARX1_CDARX1B4_SHIFT                                  (0x00000018U)
#define CSL_UFSHCI_REGS_CDARX1_CDARX1B4_MAX                                    (0x000000FFU)

/* CDARX2 */

#define CSL_UFSHCI_REGS_CDARX2_CDARX2B3_MASK                                   (0x000000FFU)
#define CSL_UFSHCI_REGS_CDARX2_CDARX2B3_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_CDARX2_CDARX2B3_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDARX2_CDARX2B2_MASK                                   (0x0000FF00U)
#define CSL_UFSHCI_REGS_CDARX2_CDARX2B2_SHIFT                                  (0x00000008U)
#define CSL_UFSHCI_REGS_CDARX2_CDARX2B2_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDARX2_CDARX2B1_MASK                                   (0x00FF0000U)
#define CSL_UFSHCI_REGS_CDARX2_CDARX2B1_SHIFT                                  (0x00000010U)
#define CSL_UFSHCI_REGS_CDARX2_CDARX2B1_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CDARX2_CDARX2B0_MASK                                   (0xFF000000U)
#define CSL_UFSHCI_REGS_CDARX2_CDARX2B0_SHIFT                                  (0x00000018U)
#define CSL_UFSHCI_REGS_CDARX2_CDARX2B0_MAX                                    (0x000000FFU)

/* CDASTA */

#define CSL_UFSHCI_REGS_CDASTA_CDASBE_MASK                                     (0x000000FFU)
#define CSL_UFSHCI_REGS_CDASTA_CDASBE_SHIFT                                    (0x00000000U)
#define CSL_UFSHCI_REGS_CDASTA_CDASBE_MAX                                      (0x000000FFU)

#define CSL_UFSHCI_REGS_CDASTA_CDABE_MASK                                      (0x0000FF00U)
#define CSL_UFSHCI_REGS_CDASTA_CDABE_SHIFT                                     (0x00000008U)
#define CSL_UFSHCI_REGS_CDASTA_CDABE_MAX                                       (0x000000FFU)

#define CSL_UFSHCI_REGS_CDASTA_CDASOM_MASK                                     (0x00010000U)
#define CSL_UFSHCI_REGS_CDASTA_CDASOM_SHIFT                                    (0x00000010U)
#define CSL_UFSHCI_REGS_CDASTA_CDASOM_MAX                                      (0x00000001U)

#define CSL_UFSHCI_REGS_CDASTA_CDAEOM_MASK                                     (0x00020000U)
#define CSL_UFSHCI_REGS_CDASTA_CDAEOM_SHIFT                                    (0x00000011U)
#define CSL_UFSHCI_REGS_CDASTA_CDAEOM_MAX                                      (0x00000001U)

#define CSL_UFSHCI_REGS_CDASTA_CDASTA_MASK                                     (0x00040000U)
#define CSL_UFSHCI_REGS_CDASTA_CDASTA_SHIFT                                    (0x00000012U)
#define CSL_UFSHCI_REGS_CDASTA_CDASTA_MAX                                      (0x00000001U)

#define CSL_UFSHCI_REGS_CDASTA_CDABUSY_MASK                                    (0x00080000U)
#define CSL_UFSHCI_REGS_CDASTA_CDABUSY_SHIFT                                   (0x00000013U)
#define CSL_UFSHCI_REGS_CDASTA_CDABUSY_MAX                                     (0x00000001U)

#define CSL_UFSHCI_REGS_CDASTA_CDARES_MASK                                     (0x00700000U)
#define CSL_UFSHCI_REGS_CDASTA_CDARES_SHIFT                                    (0x00000014U)
#define CSL_UFSHCI_REGS_CDASTA_CDARES_MAX                                      (0x00000007U)

/* XASB */

#define CSL_UFSHCI_REGS_XASB_XDP_MASK                                          (0x0000003FU)
#define CSL_UFSHCI_REGS_XASB_XDP_SHIFT                                         (0x00000000U)
#define CSL_UFSHCI_REGS_XASB_XDP_MAX                                           (0x0000003FU)

#define CSL_UFSHCI_REGS_XASB_RES7_MASK                                         (0x000000C0U)
#define CSL_UFSHCI_REGS_XASB_RES7_SHIFT                                        (0x00000006U)
#define CSL_UFSHCI_REGS_XASB_RES7_MAX                                          (0x00000003U)

#define CSL_UFSHCI_REGS_XASB_PEP_MASK                                          (0x00003F00U)
#define CSL_UFSHCI_REGS_XASB_PEP_SHIFT                                         (0x00000008U)
#define CSL_UFSHCI_REGS_XASB_PEP_MAX                                           (0x0000003FU)

#define CSL_UFSHCI_REGS_XASB_RES6_MASK                                         (0xFFFFC000U)
#define CSL_UFSHCI_REGS_XASB_RES6_SHIFT                                        (0x0000000EU)
#define CSL_UFSHCI_REGS_XASB_RES6_MAX                                          (0x0003FFFFU)

/* LBMCFG */

#define CSL_UFSHCI_REGS_LBMCFG_UDLY_MASK                                       (0x0000000FU)
#define CSL_UFSHCI_REGS_LBMCFG_UDLY_SHIFT                                      (0x00000000U)
#define CSL_UFSHCI_REGS_LBMCFG_UDLY_MAX                                        (0x0000000FU)

#define CSL_UFSHCI_REGS_LBMCFG_USDLY_MASK                                      (0x00000010U)
#define CSL_UFSHCI_REGS_LBMCFG_USDLY_SHIFT                                     (0x00000004U)
#define CSL_UFSHCI_REGS_LBMCFG_USDLY_MAX                                       (0x00000001U)

#define CSL_UFSHCI_REGS_LBMCFG_PDSIZE_MASK                                     (0x000001E0U)
#define CSL_UFSHCI_REGS_LBMCFG_PDSIZE_SHIFT                                    (0x00000005U)
#define CSL_UFSHCI_REGS_LBMCFG_PDSIZE_MAX                                      (0x0000000FU)

#define CSL_UFSHCI_REGS_LBMCFG_LBME_MASK                                       (0x00000200U)
#define CSL_UFSHCI_REGS_LBMCFG_LBME_SHIFT                                      (0x00000009U)
#define CSL_UFSHCI_REGS_LBMCFG_LBME_MAX                                        (0x00000001U)

#define CSL_UFSHCI_REGS_LBMCFG_MRTTE_MASK                                      (0x00000400U)
#define CSL_UFSHCI_REGS_LBMCFG_MRTTE_SHIFT                                     (0x0000000AU)
#define CSL_UFSHCI_REGS_LBMCFG_MRTTE_MAX                                       (0x00000001U)

#define CSL_UFSHCI_REGS_LBMCFG_TRTLDV_MASK                                     (0x00007800U)
#define CSL_UFSHCI_REGS_LBMCFG_TRTLDV_SHIFT                                    (0x0000000BU)
#define CSL_UFSHCI_REGS_LBMCFG_TRTLDV_MAX                                      (0x0000000FU)

#define CSL_UFSHCI_REGS_LBMCFG_BEPS_MASK                                       (0x00008000U)
#define CSL_UFSHCI_REGS_LBMCFG_BEPS_SHIFT                                      (0x0000000FU)
#define CSL_UFSHCI_REGS_LBMCFG_BEPS_MAX                                        (0x00000001U)

#define CSL_UFSHCI_REGS_LBMCFG_BEP_MASK                                        (0x000F0000U)
#define CSL_UFSHCI_REGS_LBMCFG_BEP_SHIFT                                       (0x00000010U)
#define CSL_UFSHCI_REGS_LBMCFG_BEP_MAX                                         (0x0000000FU)

/* LBMSTA */

#define CSL_UFSHCI_REGS_LBMSTA_ERR_MASK                                        (0x00000001U)
#define CSL_UFSHCI_REGS_LBMSTA_ERR_SHIFT                                       (0x00000000U)
#define CSL_UFSHCI_REGS_LBMSTA_ERR_MAX                                         (0x00000001U)

/* DBG */

#define CSL_UFSHCI_REGS_DBG_HCSTATE_MASK                                       (0x0000FFFFU)
#define CSL_UFSHCI_REGS_DBG_HCSTATE_SHIFT                                      (0x00000000U)
#define CSL_UFSHCI_REGS_DBG_HCSTATE_MAX                                        (0x0000FFFFU)

#define CSL_UFSHCI_REGS_DBG_HCIER_MASK                                         (0x00030000U)
#define CSL_UFSHCI_REGS_DBG_HCIER_SHIFT                                        (0x00000010U)
#define CSL_UFSHCI_REGS_DBG_HCIER_MAX                                          (0x00000003U)

/* HCLKDIV */

#define CSL_UFSHCI_REGS_HCLKDIV_HCLKDIV_MASK                                   (0x0000FFFFU)
#define CSL_UFSHCI_REGS_HCLKDIV_HCLKDIV_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_HCLKDIV_HCLKDIV_MAX                                    (0x0000FFFFU)

#define CSL_UFSHCI_REGS_HCLKDIV_RES_MASK                                       (0xFFFF0000U)
#define CSL_UFSHCI_REGS_HCLKDIV_RES_SHIFT                                      (0x00000010U)
#define CSL_UFSHCI_REGS_HCLKDIV_RES_MAX                                        (0x0000FFFFU)

/* CCAP */

#define CSL_UFSHCI_REGS_CCAP_CC_MASK                                           (0x000000FFU)
#define CSL_UFSHCI_REGS_CCAP_CC_SHIFT                                          (0x00000000U)
#define CSL_UFSHCI_REGS_CCAP_CC_MAX                                            (0x000000FFU)

#define CSL_UFSHCI_REGS_CCAP_CFGC_MASK                                         (0x0000FF00U)
#define CSL_UFSHCI_REGS_CCAP_CFGC_SHIFT                                        (0x00000008U)
#define CSL_UFSHCI_REGS_CCAP_CFGC_MAX                                          (0x000000FFU)

#define CSL_UFSHCI_REGS_CCAP_RES8_MASK                                         (0x00FF0000U)
#define CSL_UFSHCI_REGS_CCAP_RES8_SHIFT                                        (0x00000010U)
#define CSL_UFSHCI_REGS_CCAP_RES8_MAX                                          (0x000000FFU)

#define CSL_UFSHCI_REGS_CCAP_CFGPTR_MASK                                       (0xFF000000U)
#define CSL_UFSHCI_REGS_CCAP_CFGPTR_SHIFT                                      (0x00000018U)
#define CSL_UFSHCI_REGS_CCAP_CFGPTR_MAX                                        (0x000000FFU)

/* CRYPTOCAP */

#define CSL_UFSHCI_REGS_CRYPTOCAP_ALGID_MASK                                   (0x000000FFU)
#define CSL_UFSHCI_REGS_CRYPTOCAP_ALGID_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCAP_ALGID_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CRYPTOCAP_SDUSB_MASK                                   (0x0000FF00U)
#define CSL_UFSHCI_REGS_CRYPTOCAP_SDUSB_SHIFT                                  (0x00000008U)
#define CSL_UFSHCI_REGS_CRYPTOCAP_SDUSB_MAX                                    (0x000000FFU)

#define CSL_UFSHCI_REGS_CRYPTOCAP_KS_MASK                                      (0x00FF0000U)
#define CSL_UFSHCI_REGS_CRYPTOCAP_KS_SHIFT                                     (0x00000010U)
#define CSL_UFSHCI_REGS_CRYPTOCAP_KS_MAX                                       (0x000000FFU)

#define CSL_UFSHCI_REGS_CRYPTOCAP_RES_MASK                                     (0xFF000000U)
#define CSL_UFSHCI_REGS_CRYPTOCAP_RES_SHIFT                                    (0x00000018U)
#define CSL_UFSHCI_REGS_CRYPTOCAP_RES_MAX                                      (0x000000FFU)

/* CRYPTOCFG0 */

#define CSL_UFSHCI_REGS_CRYPTOCFG0_CRYPTOKEY0_MASK                             (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG0_CRYPTOKEY0_SHIFT                            (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG0_CRYPTOKEY0_MAX                              (0xFFFFFFFFU)

/* CRYPTOCFG1 */

#define CSL_UFSHCI_REGS_CRYPTOCFG1_CRYPTOKEY1_MASK                             (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG1_CRYPTOKEY1_SHIFT                            (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG1_CRYPTOKEY1_MAX                              (0xFFFFFFFFU)

/* CRYPTOCFG2 */

#define CSL_UFSHCI_REGS_CRYPTOCFG2_CRYPTOKEY2_MASK                             (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG2_CRYPTOKEY2_SHIFT                            (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG2_CRYPTOKEY2_MAX                              (0xFFFFFFFFU)

/* CRYPTOCFG3 */

#define CSL_UFSHCI_REGS_CRYPTOCFG3_CRYPTOKEY3_MASK                             (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG3_CRYPTOKEY3_SHIFT                            (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG3_CRYPTOKEY3_MAX                              (0xFFFFFFFFU)

/* CRYPTOCFG16 */

#define CSL_UFSHCI_REGS_CRYPTOCFG16_DUSIZE_MASK                                (0x000000FFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG16_DUSIZE_SHIFT                               (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG16_DUSIZE_MAX                                 (0x000000FFU)

#define CSL_UFSHCI_REGS_CRYPTOCFG16_CAPIDX_MASK                                (0x0000FF00U)
#define CSL_UFSHCI_REGS_CRYPTOCFG16_CAPIDX_SHIFT                               (0x00000008U)
#define CSL_UFSHCI_REGS_CRYPTOCFG16_CAPIDX_MAX                                 (0x000000FFU)

#define CSL_UFSHCI_REGS_CRYPTOCFG16_RES_MASK                                   (0x7FFF0000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG16_RES_SHIFT                                  (0x00000010U)
#define CSL_UFSHCI_REGS_CRYPTOCFG16_RES_MAX                                    (0x00007FFFU)

#define CSL_UFSHCI_REGS_CRYPTOCFG16_CFGE_MASK                                  (0x80000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG16_CFGE_SHIFT                                 (0x0000001FU)
#define CSL_UFSHCI_REGS_CRYPTOCFG16_CFGE_MAX                                   (0x00000001U)

/* CRYPTOCFG17 */

#define CSL_UFSHCI_REGS_CRYPTOCFG17_VSB_MASK                                   (0xFFFF0000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG17_VSB_SHIFT                                  (0x00000010U)
#define CSL_UFSHCI_REGS_CRYPTOCFG17_VSB_MAX                                    (0x0000FFFFU)

/* CRYPTOCFG32 */

#define CSL_UFSHCI_REGS_CRYPTOCFG32_CRYPTOKEY32_MASK                           (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG32_CRYPTOKEY32_SHIFT                          (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG32_CRYPTOKEY32_MAX                            (0xFFFFFFFFU)

/* CRYPTOCFG33 */

#define CSL_UFSHCI_REGS_CRYPTOCFG33_CRYPTOKEY33_MASK                           (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG33_CRYPTOKEY33_SHIFT                          (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG33_CRYPTOKEY33_MAX                            (0xFFFFFFFFU)

/* CRYPTOCFG34 */

#define CSL_UFSHCI_REGS_CRYPTOCFG34_CRYPTOKEY34_MASK                           (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG34_CRYPTOKEY34_SHIFT                          (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG34_CRYPTOKEY34_MAX                            (0xFFFFFFFFU)

/* CRYPTOCFG35 */

#define CSL_UFSHCI_REGS_CRYPTOCFG35_CRYPTOKEY35_MASK                           (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG35_CRYPTOKEY35_SHIFT                          (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG35_CRYPTOKEY35_MAX                            (0xFFFFFFFFU)

/* CRYPTOCFG48 */

#define CSL_UFSHCI_REGS_CRYPTOCFG48_DUSIZE1_MASK                               (0x000000FFU)
#define CSL_UFSHCI_REGS_CRYPTOCFG48_DUSIZE1_SHIFT                              (0x00000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG48_DUSIZE1_MAX                                (0x000000FFU)

#define CSL_UFSHCI_REGS_CRYPTOCFG48_CAPIDX1_MASK                               (0x0000FF00U)
#define CSL_UFSHCI_REGS_CRYPTOCFG48_CAPIDX1_SHIFT                              (0x00000008U)
#define CSL_UFSHCI_REGS_CRYPTOCFG48_CAPIDX1_MAX                                (0x000000FFU)

#define CSL_UFSHCI_REGS_CRYPTOCFG48_RES_MASK                                   (0x7FFF0000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG48_RES_SHIFT                                  (0x00000010U)
#define CSL_UFSHCI_REGS_CRYPTOCFG48_RES_MAX                                    (0x00007FFFU)

#define CSL_UFSHCI_REGS_CRYPTOCFG48_CFGE1_MASK                                 (0x80000000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG48_CFGE1_SHIFT                                (0x0000001FU)
#define CSL_UFSHCI_REGS_CRYPTOCFG48_CFGE1_MAX                                  (0x00000001U)

/* CRYPTOCFG49 */

#define CSL_UFSHCI_REGS_CRYPTOCFG49_VSB1_MASK                                  (0xFFFF0000U)
#define CSL_UFSHCI_REGS_CRYPTOCFG49_VSB1_SHIFT                                 (0x00000010U)
#define CSL_UFSHCI_REGS_CRYPTOCFG49_VSB1_MAX                                   (0x0000FFFFU)

/* ASF_INT_STATUS */

#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_SRAM_CORR_ERR_MASK                  (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_SRAM_CORR_ERR_SHIFT                 (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_SRAM_CORR_ERR_MAX                   (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_SRAM_UNCORR_ERR_MASK                (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_SRAM_UNCORR_ERR_SHIFT               (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_SRAM_UNCORR_ERR_MAX                 (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_STATUS_RESERVED_2_2_MASK                       (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_RESERVED_2_2_SHIFT                      (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_RESERVED_2_2_MAX                        (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_STATUS_RESERVED_3_3_MASK                       (0x00000008U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_RESERVED_3_3_SHIFT                      (0x00000003U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_RESERVED_3_3_MAX                        (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_TRANS_TO_ERR_MASK                   (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_TRANS_TO_ERR_SHIFT                  (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_TRANS_TO_ERR_MAX                    (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_PROTOCOL_ERR_MASK                   (0x00000020U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_PROTOCOL_ERR_SHIFT                  (0x00000005U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_PROTOCOL_ERR_MAX                    (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_INTEGRITY_ERR_MASK                  (0x00000040U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_INTEGRITY_ERR_SHIFT                 (0x00000006U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_ASF_INTEGRITY_ERR_MAX                   (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_STATUS_RESERVED_31_7_MASK                      (0xFFFFFF80U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_RESERVED_31_7_SHIFT                     (0x00000007U)
#define CSL_UFSHCI_REGS_ASF_INT_STATUS_RESERVED_31_7_MAX                       (0x01FFFFFFU)

/* ASF_INT_RAW_STATUS */

#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_SRAM_CORR_ERR_MASK              (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_SRAM_CORR_ERR_SHIFT             (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_SRAM_CORR_ERR_MAX               (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_SRAM_UNCORR_ERR_MASK            (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_SRAM_UNCORR_ERR_SHIFT           (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_SRAM_UNCORR_ERR_MAX             (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_RESERVED_2_2_MASK                   (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_RESERVED_2_2_SHIFT                  (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_RESERVED_2_2_MAX                    (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_RESERVED_3_3_MASK                   (0x00000008U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_RESERVED_3_3_SHIFT                  (0x00000003U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_RESERVED_3_3_MAX                    (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_TRANS_TO_ERR_MASK               (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_TRANS_TO_ERR_SHIFT              (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_TRANS_TO_ERR_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_PROTOCOL_ERR_MASK               (0x00000020U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_PROTOCOL_ERR_SHIFT              (0x00000005U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_PROTOCOL_ERR_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_INTEGRITY_ERR_MASK              (0x00000040U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_INTEGRITY_ERR_SHIFT             (0x00000006U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_ASF_INTEGRITY_ERR_MAX               (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_RESERVED_31_7_MASK                  (0xFFFFFF80U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_RESERVED_31_7_SHIFT                 (0x00000007U)
#define CSL_UFSHCI_REGS_ASF_INT_RAW_STATUS_RESERVED_31_7_MAX                   (0x01FFFFFFU)

/* ASF_INT_MASK */

#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_SRAM_CORR_ERR_MASK_MASK               (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_SRAM_CORR_ERR_MASK_SHIFT              (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_SRAM_CORR_ERR_MASK_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_SRAM_UNCORR_ERR_MASK_MASK             (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_SRAM_UNCORR_ERR_MASK_SHIFT            (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_SRAM_UNCORR_ERR_MASK_MAX              (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_MASK_RESERVED_2_2_MASK                         (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_RESERVED_2_2_SHIFT                        (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_RESERVED_2_2_MAX                          (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_MASK_RESERVED_3_3_MASK                         (0x00000008U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_RESERVED_3_3_SHIFT                        (0x00000003U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_RESERVED_3_3_MAX                          (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_TRANS_TO_ERR_MASK_MASK                (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_TRANS_TO_ERR_MASK_SHIFT               (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_TRANS_TO_ERR_MASK_MAX                 (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_PROTOCOL_ERR_MASK_MASK                (0x00000020U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_PROTOCOL_ERR_MASK_SHIFT               (0x00000005U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_PROTOCOL_ERR_MASK_MAX                 (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_INTEGRITY_ERR_MASK_MASK               (0x00000040U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_INTEGRITY_ERR_MASK_SHIFT              (0x00000006U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_ASF_INTEGRITY_ERR_MASK_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_MASK_RESERVED_31_7_MASK                        (0xFFFFFF80U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_RESERVED_31_7_SHIFT                       (0x00000007U)
#define CSL_UFSHCI_REGS_ASF_INT_MASK_RESERVED_31_7_MAX                         (0x01FFFFFFU)

/* ASF_INT_TEST */

#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_SRAM_CORR_ERR_TEST_MASK               (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_SRAM_CORR_ERR_TEST_SHIFT              (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_SRAM_CORR_ERR_TEST_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_SRAM_UNCORR_ERR_TEST_MASK             (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_SRAM_UNCORR_ERR_TEST_SHIFT            (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_SRAM_UNCORR_ERR_TEST_MAX              (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_TEST_RESERVED_2_2_MASK                         (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_RESERVED_2_2_SHIFT                        (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_RESERVED_2_2_MAX                          (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_TEST_RESERVED_3_3_MASK                         (0x00000008U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_RESERVED_3_3_SHIFT                        (0x00000003U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_RESERVED_3_3_MAX                          (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_TRANS_TO_ERR_TEST_MASK                (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_TRANS_TO_ERR_TEST_SHIFT               (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_TRANS_TO_ERR_TEST_MAX                 (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_PROTOCOL_ERR_TEST_MASK                (0x00000020U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_PROTOCOL_ERR_TEST_SHIFT               (0x00000005U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_PROTOCOL_ERR_TEST_MAX                 (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_INTEGRITY_ERR_TEST_MASK               (0x00000040U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_INTEGRITY_ERR_TEST_SHIFT              (0x00000006U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_ASF_INTEGRITY_ERR_TEST_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INT_TEST_RESERVED_31_7_MASK                        (0xFFFFFF80U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_RESERVED_31_7_SHIFT                       (0x00000007U)
#define CSL_UFSHCI_REGS_ASF_INT_TEST_RESERVED_31_7_MAX                         (0x01FFFFFFU)

/* ASF_FATAL_NONFATAL_SELECT */

#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_CORR_ERR_MASK       (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_CORR_ERR_SHIFT      (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_CORR_ERR_MAX        (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_UNCORR_ERR_MASK     (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_UNCORR_ERR_SHIFT    (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_UNCORR_ERR_MAX      (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_RESERVED_2_2_MASK            (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_RESERVED_2_2_SHIFT           (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_RESERVED_2_2_MAX             (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_RESERVED_3_3_MASK            (0x00000008U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_RESERVED_3_3_SHIFT           (0x00000003U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_RESERVED_3_3_MAX             (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_TRANS_TO_ERR_MASK        (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_TRANS_TO_ERR_SHIFT       (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_TRANS_TO_ERR_MAX         (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_PROTOCOL_ERR_MASK        (0x00000020U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_PROTOCOL_ERR_SHIFT       (0x00000005U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_PROTOCOL_ERR_MAX         (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_INTEGRITY_ERR_MASK       (0x00000040U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_INTEGRITY_ERR_SHIFT      (0x00000006U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_ASF_INTEGRITY_ERR_MAX        (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_RESERVED_31_7_MASK           (0xFFFFFF80U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_RESERVED_31_7_SHIFT          (0x00000007U)
#define CSL_UFSHCI_REGS_ASF_FATAL_NONFATAL_SELECT_RESERVED_31_7_MAX            (0x01FFFFFFU)

/* ASF_SRAM_CORR_FAULT_STATUS */

#define CSL_UFSHCI_REGS_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_ADDR_MASK (0x00FFFFFFU)
#define CSL_UFSHCI_REGS_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_ADDR_SHIFT (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_ADDR_MAX (0x00FFFFFFU)

#define CSL_UFSHCI_REGS_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_INST_MASK (0xFF000000U)
#define CSL_UFSHCI_REGS_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_INST_SHIFT (0x00000018U)
#define CSL_UFSHCI_REGS_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_INST_MAX (0x000000FFU)

/* ASF_SRAM_UNCORR_FAULT_STATUS */

#define CSL_UFSHCI_REGS_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_ADDR_MASK (0x00FFFFFFU)
#define CSL_UFSHCI_REGS_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_ADDR_SHIFT (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_ADDR_MAX (0x00FFFFFFU)

#define CSL_UFSHCI_REGS_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_INST_MASK (0xFF000000U)
#define CSL_UFSHCI_REGS_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_INST_SHIFT (0x00000018U)
#define CSL_UFSHCI_REGS_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_INST_MAX (0x000000FFU)

/* ASF_SRAM_FAULT_STATS */

#define CSL_UFSHCI_REGS_ASF_SRAM_FAULT_STATS_ASF_SRAM_FAULT_CORR_STATS_MASK    (0x0000FFFFU)
#define CSL_UFSHCI_REGS_ASF_SRAM_FAULT_STATS_ASF_SRAM_FAULT_CORR_STATS_SHIFT   (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_SRAM_FAULT_STATS_ASF_SRAM_FAULT_CORR_STATS_MAX     (0x0000FFFFU)

#define CSL_UFSHCI_REGS_ASF_SRAM_FAULT_STATS_ASF_SRAM_FAULT_UNCORR_STATS_MASK  (0xFFFF0000U)
#define CSL_UFSHCI_REGS_ASF_SRAM_FAULT_STATS_ASF_SRAM_FAULT_UNCORR_STATS_SHIFT (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_SRAM_FAULT_STATS_ASF_SRAM_FAULT_UNCORR_STATS_MAX   (0x0000FFFFU)

/* ASF_TRANS_TO_CTRL */

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_CTRL_MASK               (0x0000FFFFU)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_CTRL_SHIFT              (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_CTRL_MAX                (0x0000FFFFU)

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL_RESERVED_31_3_MASK                   (0x7FFF0000U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL_RESERVED_31_3_SHIFT                  (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL_RESERVED_31_3_MAX                    (0x00007FFFU)

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_EN_MASK                 (0x80000000U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_EN_SHIFT                (0x0000001FU)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_EN_MAX                  (0x00000001U)

/* ASF_TRANS_TO_FAULT_MASK */

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_FCX_PROT_TMR_MASK_MASK         (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_FCX_PROT_TMR_MASK_SHIFT        (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_FCX_PROT_TMR_MASK_MAX          (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_AFCX_REQ_TMR_MASK_MASK         (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_AFCX_REQ_TMR_MASK_SHIFT        (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_AFCX_REQ_TMR_MASK_MAX          (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_TCX_REPL_TMR_MASK_MASK         (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_TCX_REPL_TMR_MASK_SHIFT        (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_TCX_REPL_TMR_MASK_MAX          (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_RESERVED_31_3_MASK             (0xFFFFFFF8U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_RESERVED_31_3_SHIFT            (0x00000003U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_MASK_RESERVED_31_3_MAX              (0x1FFFFFFFU)

/* ASF_TRANS_TO_FAULT_STATUS */

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_FCX_PROT_TMR_ERR_MASK        (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_FCX_PROT_TMR_ERR_SHIFT       (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_FCX_PROT_TMR_ERR_MAX         (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_AFCX_REQ_TMR_ERR_MASK        (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_AFCX_REQ_TMR_ERR_SHIFT       (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_AFCX_REQ_TMR_ERR_MAX         (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_TCX_REPL_TMR_ERR_MASK        (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_TCX_REPL_TMR_ERR_SHIFT       (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_TCX_REPL_TMR_ERR_MAX         (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_RESERVED_31_3_MASK           (0xFFFFFFF8U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_RESERVED_31_3_SHIFT          (0x00000003U)
#define CSL_UFSHCI_REGS_ASF_TRANS_TO_FAULT_STATUS_RESERVED_31_3_MAX            (0x1FFFFFFFU)

/* ASF_PROTOCOL_FAULT_MASK */

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_NAC_RCV_MASK_MASK              (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_NAC_RCV_MASK_SHIFT             (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_NAC_RCV_MASK_MAX               (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_CRC_ERR_MASK_MASK              (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_CRC_ERR_MASK_SHIFT             (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_CRC_ERR_MASK_MAX               (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_RXBUG_OF_MASK_MASK             (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_RXBUG_OF_MASK_SHIFT            (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_RXBUG_OF_MASK_MAX              (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_MFL_EX_MASK_MASK               (0x00000008U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_MFL_EX_MASK_SHIFT              (0x00000003U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_MFL_EX_MASK_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_WSQ_NO_MASK_MASK               (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_WSQ_NO_MASK_SHIFT              (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_WSQ_NO_MASK_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_AFC_F_S_MASK_MASK              (0x00000020U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_AFC_F_S_MASK_SHIFT             (0x00000005U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_AFC_F_S_MASK_MAX               (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_NAC_F_S_MASK_MASK              (0x00000040U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_NAC_F_S_MASK_SHIFT             (0x00000006U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_NAC_F_S_MASK_MAX               (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_EOF_S_MASK_MASK                (0x00000080U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_EOF_S_MASK_SHIFT               (0x00000007U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_EOF_S_MASK_MAX                 (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_FRM_S_MASK_MASK                (0x00000100U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_FRM_S_MASK_SHIFT               (0x00000008U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_FRM_S_MASK_MAX                 (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_BAD_CTRL_S_MASK_MASK           (0x00000200U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_BAD_CTRL_S_MASK_SHIFT          (0x00000009U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_BAD_CTRL_S_MASK_MAX            (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_PA_INT_MASK_MASK               (0x00000400U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_PA_INT_MASK_SHIFT              (0x0000000AU)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_PA_INT_MASK_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_PA_IND_RCV_MASK_MASK           (0x00000800U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_PA_IND_RCV_MASK_SHIFT          (0x0000000BU)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_PA_IND_RCV_MASK_MAX            (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_RESERVED_31_12_MASK            (0xFFFFF000U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_RESERVED_31_12_SHIFT           (0x0000000CU)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_MASK_RESERVED_31_12_MAX             (0x000FFFFFU)

/* ASF_PROTOCOL_FAULT_STATUS */

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_NAC_RCV_ERR_MASK             (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_NAC_RCV_ERR_SHIFT            (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_NAC_RCV_ERR_MAX              (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_CRC_ERR_ERR_MASK             (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_CRC_ERR_ERR_SHIFT            (0x00000001U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_CRC_ERR_ERR_MAX              (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_RXBUG_OF_ERR_MASK            (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_RXBUG_OF_ERR_SHIFT           (0x00000002U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_RXBUG_OF_ERR_MAX             (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_MFL_EX_ERR_MASK              (0x00000008U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_MFL_EX_ERR_SHIFT             (0x00000003U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_MFL_EX_ERR_MAX               (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_WSQ_NO_ERR_MASK              (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_WSQ_NO_ERR_SHIFT             (0x00000004U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_WSQ_NO_ERR_MAX               (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_AFC_F_S_ERR_MASK             (0x00000020U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_AFC_F_S_ERR_SHIFT            (0x00000005U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_AFC_F_S_ERR_MAX              (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_NAC_F_S_ERR_MASK             (0x00000040U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_NAC_F_S_ERR_SHIFT            (0x00000006U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_NAC_F_S_ERR_MAX              (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_EOF_S_ERR_MASK               (0x00000080U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_EOF_S_ERR_SHIFT              (0x00000007U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_EOF_S_ERR_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_FRM_S_ERR_MASK               (0x00000100U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_FRM_S_ERR_SHIFT              (0x00000008U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_FRM_S_ERR_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_BAD_CTRL_S_ERR_MASK          (0x00000200U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_BAD_CTRL_S_ERR_SHIFT         (0x00000009U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_BAD_CTRL_S_ERR_MAX           (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_PA_INT_ERR_MASK              (0x00000400U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_PA_INT_ERR_SHIFT             (0x0000000AU)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_PA_INT_ERR_MAX               (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_PA_IND_RCV_ERR_MASK          (0x00000800U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_PA_IND_RCV_ERR_SHIFT         (0x0000000BU)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_PA_IND_RCV_ERR_MAX           (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_RESERVED_31_12_MASK          (0xFFFFF000U)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_RESERVED_31_12_SHIFT         (0x0000000CU)
#define CSL_UFSHCI_REGS_ASF_PROTOCOL_FAULT_STATUS_RESERVED_31_12_MAX           (0x000FFFFFU)

/* ASF_INTEGRITY_ERR_INJ */

#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ_ASF_INTEGRITY_ERR_INJ_NUM_MASK   (0x00007FFFU)
#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ_ASF_INTEGRITY_ERR_INJ_NUM_SHIFT  (0x00000000U)
#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ_ASF_INTEGRITY_ERR_INJ_NUM_MAX    (0x00007FFFU)

#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ_ASF_INTEGRITY_ERR_INJ_EN_MASK    (0x00008000U)
#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ_ASF_INTEGRITY_ERR_INJ_EN_SHIFT   (0x0000000FU)
#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ_ASF_INTEGRITY_ERR_INJ_EN_MAX     (0x00000001U)

#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ_RESERVED_MASK                    (0xFFFF0000U)
#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ_RESERVED_SHIFT                   (0x00000010U)
#define CSL_UFSHCI_REGS_ASF_INTEGRITY_ERR_INJ_RESERVED_MAX                     (0x0000FFFFU)

/* MAG_NUM */

#define CSL_UFSHCI_REGS_MAG_NUM_MAG_NUM_MASK                                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MAG_NUM_MAG_NUM_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_MAG_NUM_MAG_NUM_MAX                                    (0xFFFFFFFFU)

/* MPHYSTAT_XCFGO1 */

#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO1_XCFGO1_MASK                            (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO1_XCFGO1_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO1_XCFGO1_MAX                             (0xFFFFFFFFU)

/* MPHYSTAT_XCFGO2 */

#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO2_XCFGO2_MASK                            (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO2_XCFGO2_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO2_XCFGO2_MAX                             (0xFFFFFFFFU)

/* MPHYSTAT_XCFGO3 */

#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO3_XCFGO3_MASK                            (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO3_XCFGO3_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO3_XCFGO3_MAX                             (0xFFFFFFFFU)

/* MPHYSTAT_XCFGO4 */

#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO4_XCFGO4_MASK                            (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO4_XCFGO4_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO4_XCFGO4_MAX                             (0xFFFFFFFFU)

/* MPHYSTAT_XCFGO5 */

#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO5_XCFGO5_MASK                            (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO5_XCFGO5_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO5_XCFGO5_MAX                             (0xFFFFFFFFU)

/* MPHYSTAT_XCFGO6 */

#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO6_XCFGO6_MASK                            (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO6_XCFGO6_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO6_XCFGO6_MAX                             (0xFFFFFFFFU)

/* MPHYSTAT_XCFGO7 */

#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO7_XCFGO7_MASK                            (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO7_XCFGO7_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO7_XCFGO7_MAX                             (0xFFFFFFFFU)

/* MPHYSTAT_XCFGO8 */

#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO8_XCFGO8_MASK                            (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO8_XCFGO8_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO8_XCFGO8_MAX                             (0xFFFFFFFFU)

/* MPHYSTAT_XCFGO9 */

#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO9_XCFGO9_MASK                            (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO9_XCFGO9_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_XCFGO9_XCFGO9_MAX                             (0xFFFFFFFFU)

/* MPHY_DEBUG_OUT */

#define CSL_UFSHCI_REGS_MPHY_DEBUG_OUT_DEBUG_OUT_MASK                          (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHY_DEBUG_OUT_DEBUG_OUT_SHIFT                         (0x00000000U)
#define CSL_UFSHCI_REGS_MPHY_DEBUG_OUT_DEBUG_OUT_MAX                           (0xFFFFFFFFU)

/* MPHY_BIST */

#define CSL_UFSHCI_REGS_MPHY_BIST_MPHY_BIST_MASK                               (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHY_BIST_MPHY_BIST_SHIFT                              (0x00000000U)
#define CSL_UFSHCI_REGS_MPHY_BIST_MPHY_BIST_MAX                                (0xFFFFFFFFU)

/* MPHY_SF */

#define CSL_UFSHCI_REGS_MPHY_SF_MPHY_SF_MASK                                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHY_SF_MPHY_SF_SHIFT                                  (0x00000000U)
#define CSL_UFSHCI_REGS_MPHY_SF_MPHY_SF_MAX                                    (0xFFFFFFFFU)

/* MPHYSTAT */

#define CSL_UFSHCI_REGS_MPHYSTAT_RES_MASK                                      (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYSTAT_RES_SHIFT                                     (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYSTAT_RES_MAX                                       (0xFFFFFFFFU)

/* MPHY_MMIO_A */

#define CSL_UFSHCI_REGS_MPHY_MMIO_A_MMIO_A_MASK                                (0x00000001U)
#define CSL_UFSHCI_REGS_MPHY_MMIO_A_MMIO_A_SHIFT                               (0x00000000U)
#define CSL_UFSHCI_REGS_MPHY_MMIO_A_MMIO_A_MAX                                 (0x00000001U)

#define CSL_UFSHCI_REGS_MPHY_MMIO_A_RES_MASK                                   (0xFFFFFFFEU)
#define CSL_UFSHCI_REGS_MPHY_MMIO_A_RES_SHIFT                                  (0x00000001U)
#define CSL_UFSHCI_REGS_MPHY_MMIO_A_RES_MAX                                    (0x7FFFFFFFU)

/* MPHYCFG_XCFGD1 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD1_MPHYCFG_XCFGD1_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD1_MPHYCFG_XCFGD1_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD1_MPHYCFG_XCFGD1_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGD2 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD2_MPHYCFG_XCFGD2_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD2_MPHYCFG_XCFGD2_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD2_MPHYCFG_XCFGD2_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGD3 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD3_MPHYCFG_XCFGD3_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD3_MPHYCFG_XCFGD3_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD3_MPHYCFG_XCFGD3_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGD4 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD4_MPHYCFG_XCFGD4_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD4_MPHYCFG_XCFGD4_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD4_MPHYCFG_XCFGD4_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGD5 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD5_MPHYCFG_XCFGD5_MASK                     (0x0000001FU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD5_MPHYCFG_XCFGD5_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD5_MPHYCFG_XCFGD5_MAX                      (0x0000001FU)

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD5_RES_MASK                                (0xFFFFFFE0U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD5_RES_SHIFT                               (0x00000005U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGD5_RES_MAX                                 (0x07FFFFFFU)

/* MPHYCFG_XCFGA1 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA1_MPHYCFG_XCFGA1_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA1_MPHYCFG_XCFGA1_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA1_MPHYCFG_XCFGA1_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGA2 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA2_MPHYCFG_XCFGA2_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA2_MPHYCFG_XCFGA2_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA2_MPHYCFG_XCFGA2_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGA3 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA3_MPHYCFG_XCFGA3_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA3_MPHYCFG_XCFGA3_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA3_MPHYCFG_XCFGA3_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGA4 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA4_MPHYCFG_XCFGA4_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA4_MPHYCFG_XCFGA4_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA4_MPHYCFG_XCFGA4_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGA5 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA5_MPHYCFG_XCFGA5_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA5_MPHYCFG_XCFGA5_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA5_MPHYCFG_XCFGA5_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGA6 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA6_MPHYCFG_XCFGA6_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA6_MPHYCFG_XCFGA6_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA6_MPHYCFG_XCFGA6_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGA7 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA7_MPHYCFG_XCFGA7_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA7_MPHYCFG_XCFGA7_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA7_MPHYCFG_XCFGA7_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGA8 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA8_MPHYCFG_XCFGA8_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA8_MPHYCFG_XCFGA8_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA8_MPHYCFG_XCFGA8_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGA9 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA9_MPHYCFG_XCFGA9_MASK                     (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA9_MPHYCFG_XCFGA9_SHIFT                    (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA9_MPHYCFG_XCFGA9_MAX                      (0xFFFFFFFFU)

/* MPHYCFG_XCFGA10 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA10_MPHYCFG_XCFGA10_MASK                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA10_MPHYCFG_XCFGA10_SHIFT                  (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA10_MPHYCFG_XCFGA10_MAX                    (0xFFFFFFFFU)

/* MPHYCFG_XCFGA11 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA11_MPHYCFG_XCFGA11_MASK                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA11_MPHYCFG_XCFGA11_SHIFT                  (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA11_MPHYCFG_XCFGA11_MAX                    (0xFFFFFFFFU)

/* MPHYCFG_XCFGA12 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA12_MPHYCFG_XCFGA12_MASK                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA12_MPHYCFG_XCFGA12_SHIFT                  (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA12_MPHYCFG_XCFGA12_MAX                    (0xFFFFFFFFU)

/* MPHYCFG_XCFGA13 */

#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA13_MPHYCFG_XCFGA13_MASK                   (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA13_MPHYCFG_XCFGA13_SHIFT                  (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_XCFGA13_MPHYCFG_XCFGA13_MAX                    (0xFFFFFFFFU)

/* MPHYCFG_MISC */

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_DEBUG_SEL_MASK                            (0x0000007FU)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_DEBUG_SEL_SHIFT                           (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_DEBUG_SEL_MAX                             (0x0000007FU)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES1_MASK                                 (0x00000780U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES1_SHIFT                                (0x00000007U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES1_MAX                                  (0x0000000FU)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RX_DEEP_STALL_EN_MASK                     (0x00000800U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RX_DEEP_STALL_EN_SHIFT                    (0x0000000BU)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RX_DEEP_STALL_EN_MAX                      (0x00000001U)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_TX_DEEP_STALL_EN_MASK                     (0x00001000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_TX_DEEP_STALL_EN_SHIFT                    (0x0000000CU)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_TX_DEEP_STALL_EN_MAX                      (0x00000001U)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES2_MASK                                 (0x00006000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES2_SHIFT                                (0x0000000DU)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES2_MAX                                  (0x00000003U)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_REFCLK_FREQ_SEL_MASK                      (0x00018000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_REFCLK_FREQ_SEL_SHIFT                     (0x0000000FU)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_REFCLK_FREQ_SEL_MAX                       (0x00000003U)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_REFCLK_NOGATED_MASK                       (0x00020000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_REFCLK_NOGATED_SHIFT                      (0x00000011U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_REFCLK_NOGATED_MAX                        (0x00000001U)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES32_MASK                                (0x00FC0000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES32_SHIFT                               (0x00000012U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES32_MAX                                 (0x0000003FU)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_TX1_TEST_15_MMIO_MASK                     (0x01000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_TX1_TEST_15_MMIO_SHIFT                    (0x00000018U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_TX1_TEST_15_MMIO_MAX                      (0x00000001U)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_TX0_TEST_15_MMIO_MASK                     (0x02000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_TX0_TEST_15_MMIO_SHIFT                    (0x00000019U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_TX0_TEST_15_MMIO_MAX                      (0x00000001U)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_CMN_MPX_SEL_MMIO_MASK                     (0x1C000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_CMN_MPX_SEL_MMIO_SHIFT                    (0x0000001AU)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_CMN_MPX_SEL_MMIO_MAX                      (0x00000007U)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_CMN_MPX_EN_MMIO_MASK                      (0x20000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_CMN_MPX_EN_MMIO_SHIFT                     (0x0000001DU)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_CMN_MPX_EN_MMIO_MAX                       (0x00000001U)

#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES31_MASK                                (0xC0000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES31_SHIFT                               (0x0000001EU)
#define CSL_UFSHCI_REGS_MPHYCFG_MISC_RES31_MAX                                 (0x00000003U)

/* MPHYCFG_VCONTROL */

#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_VCONTROL_MASK                         (0x000003FFU)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_VCONTROL_SHIFT                        (0x00000000U)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_VCONTROL_MAX                          (0x000003FFU)

#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_VCONTROL_DEEMP_SEL_MASK               (0x00000C00U)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_VCONTROL_DEEMP_SEL_SHIFT              (0x0000000AU)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_VCONTROL_DEEMP_SEL_MAX                (0x00000003U)

#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_RES1_MASK                             (0x0000F000U)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_RES1_SHIFT                            (0x0000000CU)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_RES1_MAX                              (0x0000000FU)

#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_VCONTROL_LA_SA_SEL_MASK               (0x00010000U)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_VCONTROL_LA_SA_SEL_SHIFT              (0x00000010U)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_VCONTROL_LA_SA_SEL_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_RES2_MASK                             (0xFFFE0000U)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_RES2_SHIFT                            (0x00000011U)
#define CSL_UFSHCI_REGS_MPHYCFG_VCONTROL_RES2_MAX                              (0x00007FFFU)

/* MPHY_BIST_CTRLPIN */

#define CSL_UFSHCI_REGS_MPHY_BIST_CTRLPIN_MPHY_BIST_CTRLPIN_MASK               (0xFFFFFFFFU)
#define CSL_UFSHCI_REGS_MPHY_BIST_CTRLPIN_MPHY_BIST_CTRLPIN_SHIFT              (0x00000000U)
#define CSL_UFSHCI_REGS_MPHY_BIST_CTRLPIN_MPHY_BIST_CTRLPIN_MAX                (0xFFFFFFFFU)

/* MPHY_SF_WD */

#define CSL_UFSHCI_REGS_MPHY_SF_WD_SF_CDR1_WATCHDOG_EN_MMIO_MASK               (0x00000001U)
#define CSL_UFSHCI_REGS_MPHY_SF_WD_SF_CDR1_WATCHDOG_EN_MMIO_SHIFT              (0x00000000U)
#define CSL_UFSHCI_REGS_MPHY_SF_WD_SF_CDR1_WATCHDOG_EN_MMIO_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_MPHY_SF_WD_SF_CDR0_WATCHDOG_EN_MMIO_MASK               (0x00000002U)
#define CSL_UFSHCI_REGS_MPHY_SF_WD_SF_CDR0_WATCHDOG_EN_MMIO_SHIFT              (0x00000001U)
#define CSL_UFSHCI_REGS_MPHY_SF_WD_SF_CDR0_WATCHDOG_EN_MMIO_MAX                (0x00000001U)

#define CSL_UFSHCI_REGS_MPHY_SF_WD_SF_PLL_WATCHDOG_EN_MMIO_MASK                (0x00000004U)
#define CSL_UFSHCI_REGS_MPHY_SF_WD_SF_PLL_WATCHDOG_EN_MMIO_SHIFT               (0x00000002U)
#define CSL_UFSHCI_REGS_MPHY_SF_WD_SF_PLL_WATCHDOG_EN_MMIO_MAX                 (0x00000001U)

#define CSL_UFSHCI_REGS_MPHY_SF_WD_RES_MASK                                    (0xFFFFFFF8U)
#define CSL_UFSHCI_REGS_MPHY_SF_WD_RES_SHIFT                                   (0x00000003U)
#define CSL_UFSHCI_REGS_MPHY_SF_WD_RES_MAX                                     (0x1FFFFFFFU)

#ifdef __cplusplus
}
#endif
#endif
