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
#ifndef CSLR_CSSTM_H_
#define CSLR_CSSTM_H_

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
    volatile Uint32 STMDMASTARTR;
    volatile Uint32 STMDMASTOPR;
    volatile Uint32 STMDMASTATR;
    volatile Uint32 STMDMACTLR;
    volatile Uint8  RSVD0[232];
    volatile Uint32 STMDMAIDR;
    volatile Uint32 STMHEER;
    volatile Uint8  RSVD1[28];
    volatile Uint32 STMHETER;
    volatile Uint8  RSVD2[64];
    volatile Uint32 STMHEMCR;
    volatile Uint8  RSVD3[140];
    volatile Uint32 STMHEMASTR;
    volatile Uint32 STMHEFEAT1R;
    volatile Uint32 STMHEIDR;
    volatile Uint32 STMSPER;
    volatile Uint8  RSVD4[28];
    volatile Uint32 STMSPTER;
    volatile Uint8  RSVD5[60];
    volatile Uint32 STMSPSCR;
    volatile Uint32 STMSPMSCR;
    volatile Uint32 STMSPOVERRIDER;
    volatile Uint32 STMSPMOVERRIDER;
    volatile Uint32 STMSPTRIGCSR;
    volatile Uint8  RSVD6[12];
    volatile Uint32 STMTCSR;
    volatile Uint32 STMTSSTIMR;
    volatile Uint8  RSVD7[4];
    volatile Uint32 STMTSFREQR;
    volatile Uint32 STMSYNCR;
    volatile Uint32 STMAUXCR;
    volatile Uint8  RSVD8[8];
    volatile Uint32 STMFEAT1R;
    volatile Uint32 STMFEAT2R;
    volatile Uint32 STMFEAT3R;
    volatile Uint8  RSVD9[84];
    volatile Uint32 STMITCTRL;
    volatile Uint8  RSVD10[156];
    volatile Uint32 STMCLAIMSET;
    volatile Uint32 STMCLAIMCLR;
    volatile Uint8  RSVD11[8];
    volatile Uint32 STMLAR;
    volatile Uint32 STMLSR;
    volatile Uint32 STMAUTHSTATUS;
    volatile Uint8  RSVD12[12];
    volatile Uint32 STMDEVID;
    volatile Uint32 STMDEVTYPE;
    volatile Uint32 STMPIDR4;
    volatile Uint8  RSVD13[12];
    volatile Uint32 STMPIDR0;
    volatile Uint32 STMPIDR1;
    volatile Uint32 STMPIDR2;
    volatile Uint32 STMPIDR3;
    volatile Uint32 STMCIDR0;
    volatile Uint32 STMCIDR1;
    volatile Uint32 STMCIDR2;
    volatile Uint32 STMCIDR3;
} CSL_CsstmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* DMA Transfer Start Register */
#define CSL_CSSTM_STMDMASTARTR                                  (0xC04U)

/* DMA Transfer Stop Register */
#define CSL_CSSTM_STMDMASTOPR                                   (0xC08U)

/* DMA Transfer Status Register */
#define CSL_CSSTM_STMDMASTATR                                   (0xC0CU)

/* DMA Control Register */
#define CSL_CSSTM_STMDMACTLR                                    (0xC10U)

/* DMA ID Register */
#define CSL_CSSTM_STMDMAIDR                                     (0xCFCU)

/* Hardware Event Enable Register */
#define CSL_CSSTM_STMHEER                                       (0xD00U)

/* Hardware Event Trigger Enable Register */
#define CSL_CSSTM_STMHETER                                      (0xD20U)

/* Hardware Event Main Control Register */
#define CSL_CSSTM_STMHEMCR                                      (0xD64U)

/* Hardware Event Master Number Register */
#define CSL_CSSTM_STMHEMASTR                                    (0xDF4U)

/* Hardware Event Features 1 Register */
#define CSL_CSSTM_STMHEFEAT1R                                   (0xDF8U)

/* Hardware Event Features ID Register */
#define CSL_CSSTM_STMHEIDR                                      (0xDFCU)

/* Stimulus Port Enable Register */
#define CSL_CSSTM_STMSPER                                       (0xE00U)

/* Stimulus Port Trigger Enable Register */
#define CSL_CSSTM_STMSPTER                                      (0xE20U)

/* Stimulus Port Select Configuration Register */
#define CSL_CSSTM_STMSPSCR                                      (0xE60U)

/* Stimulus Port Master Select Configuration Register */
#define CSL_CSSTM_STMSPMSCR                                     (0xE64U)

/* Stimulus Port Override Register */
#define CSL_CSSTM_STMSPOVERRIDER                                (0xE68U)

/* Stimulus Port Master Override Register */
#define CSL_CSSTM_STMSPMOVERRIDER                               (0xE6CU)

/* Stimulus Port Trigger Control and Status Register */
#define CSL_CSSTM_STMSPTRIGCSR                                  (0xE70U)

/* Trace Control and Status Register */
#define CSL_CSSTM_STMTCSR                                       (0xE80U)

/* Timestamp Stimulus Register */
#define CSL_CSSTM_STMTSSTIMR                                    (0xE84U)

/* Timestamp Frequency Register */
#define CSL_CSSTM_STMTSFREQR                                    (0xE8CU)

/* Synchronization Control Register */
#define CSL_CSSTM_STMSYNCR                                      (0xE90U)

/* Auxiliary Control Register */
#define CSL_CSSTM_STMAUXCR                                      (0xE94U)

/* Features 1 Register */
#define CSL_CSSTM_STMFEAT1R                                     (0xEA0U)

/* Features 2 Register */
#define CSL_CSSTM_STMFEAT2R                                     (0xEA4U)

/* Features 3 Register */
#define CSL_CSSTM_STMFEAT3R                                     (0xEA8U)

/* Integration Mode Control Register */
#define CSL_CSSTM_STMITCTRL                                     (0xF00U)

/* Claim Tag Set Register */
#define CSL_CSSTM_STMCLAIMSET                                   (0xFA0U)

/* Claim Tag Clear Register */
#define CSL_CSSTM_STMCLAIMCLR                                   (0xFA4U)

/* Lock Access Register */
#define CSL_CSSTM_STMLAR                                        (0xFB0U)

/* Lock Status Register */
#define CSL_CSSTM_STMLSR                                        (0xFB4U)

/* Authentication Status Register */
#define CSL_CSSTM_STMAUTHSTATUS                                 (0xFB8U)

/* Device Configuration Register */
#define CSL_CSSTM_STMDEVID                                      (0xFC8U)

/* Device Type Register */
#define CSL_CSSTM_STMDEVTYPE                                    (0xFCCU)

/* Peripheral ID Registers */
#define CSL_CSSTM_STMPIDR4                                      (0xFD0U)

/* Peripheral ID Registers */
#define CSL_CSSTM_STMPIDR0                                      (0xFE0U)

/* Peripheral ID Registers */
#define CSL_CSSTM_STMPIDR1                                      (0xFE4U)

/* Peripheral ID Registers */
#define CSL_CSSTM_STMPIDR2                                      (0xFE8U)

/* Peripheral ID Registers */
#define CSL_CSSTM_STMPIDR3                                      (0xFECU)

/* Component ID Registers */
#define CSL_CSSTM_STMCIDR0                                      (0xFF0U)

/* Component ID Registers */
#define CSL_CSSTM_STMCIDR1                                      (0xFF4U)

/* Component ID Registers */
#define CSL_CSSTM_STMCIDR2                                      (0xFF8U)

/* Component ID Registers */
#define CSL_CSSTM_STMCIDR3                                      (0xFFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* STMDMASTARTR */

#define CSL_CSSTM_STMDMASTARTR_START_MASK                       (0x00000001U)
#define CSL_CSSTM_STMDMASTARTR_START_SHIFT                      (0U)
#define CSL_CSSTM_STMDMASTARTR_START_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMDMASTARTR_START_MAX                        (0x00000001U)

#define CSL_CSSTM_STMDMASTARTR_RESETVAL                         (0x00000000U)

/* STMDMASTOPR */

#define CSL_CSSTM_STMDMASTOPR_STOP_MASK                         (0x00000001U)
#define CSL_CSSTM_STMDMASTOPR_STOP_SHIFT                        (0U)
#define CSL_CSSTM_STMDMASTOPR_STOP_RESETVAL                     (0x00000000U)
#define CSL_CSSTM_STMDMASTOPR_STOP_MAX                          (0x00000001U)

#define CSL_CSSTM_STMDMASTOPR_RESETVAL                          (0x00000000U)

/* STMDMASTATR */

#define CSL_CSSTM_STMDMASTATR_STATUS_MASK                       (0x00000001U)
#define CSL_CSSTM_STMDMASTATR_STATUS_SHIFT                      (0U)
#define CSL_CSSTM_STMDMASTATR_STATUS_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMDMASTATR_STATUS_MAX                        (0x00000001U)

#define CSL_CSSTM_STMDMASTATR_RESETVAL                          (0x00000000U)

/* STMDMACTLR */

#define CSL_CSSTM_STMDMACTLR_SENS_MASK                          (0x0000000FU)
#define CSL_CSSTM_STMDMACTLR_SENS_SHIFT                         (0U)
#define CSL_CSSTM_STMDMACTLR_SENS_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMDMACTLR_SENS_MAX                           (0x0000000fU)

#define CSL_CSSTM_STMDMACTLR_RESETVAL                           (0x00000000U)

/* STMDMAIDR */

#define CSL_CSSTM_STMDMAIDR_CLASS_MASK                          (0x0000000FU)
#define CSL_CSSTM_STMDMAIDR_CLASS_SHIFT                         (0U)
#define CSL_CSSTM_STMDMAIDR_CLASS_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMDMAIDR_CLASS_MAX                           (0x0000000fU)

#define CSL_CSSTM_STMDMAIDR_CLASSREV_MASK                       (0x000000F0U)
#define CSL_CSSTM_STMDMAIDR_CLASSREV_SHIFT                      (4U)
#define CSL_CSSTM_STMDMAIDR_CLASSREV_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMDMAIDR_CLASSREV_MAX                        (0x0000000fU)

#define CSL_CSSTM_STMDMAIDR_VENDSPEC_MASK                       (0x00000F00U)
#define CSL_CSSTM_STMDMAIDR_VENDSPEC_SHIFT                      (8U)
#define CSL_CSSTM_STMDMAIDR_VENDSPEC_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMDMAIDR_VENDSPEC_MAX                        (0x0000000fU)

#define CSL_CSSTM_STMDMAIDR_RESETVAL                            (0x00000000U)

/* STMHEER */

#define CSL_CSSTM_STMHEER_HEE_MASK                              (0xFFFFFFFFU)
#define CSL_CSSTM_STMHEER_HEE_SHIFT                             (0U)
#define CSL_CSSTM_STMHEER_HEE_RESETVAL                          (0x00000000U)
#define CSL_CSSTM_STMHEER_HEE_MAX                               (0xffffffffU)

#define CSL_CSSTM_STMHEER_RESETVAL                              (0x00000000U)

/* STMHETER */

#define CSL_CSSTM_STMHETER_HETE_MASK                            (0xFFFFFFFFU)
#define CSL_CSSTM_STMHETER_HETE_SHIFT                           (0U)
#define CSL_CSSTM_STMHETER_HETE_RESETVAL                        (0x00000000U)
#define CSL_CSSTM_STMHETER_HETE_MAX                             (0xffffffffU)

#define CSL_CSSTM_STMHETER_RESETVAL                             (0x00000000U)

/* STMHEMCR */

#define CSL_CSSTM_STMHEMCR_EN_MASK                              (0x00000001U)
#define CSL_CSSTM_STMHEMCR_EN_SHIFT                             (0U)
#define CSL_CSSTM_STMHEMCR_EN_RESETVAL                          (0x00000000U)
#define CSL_CSSTM_STMHEMCR_EN_MAX                               (0x00000001U)

#define CSL_CSSTM_STMHEMCR_COMPEN_MASK                          (0x00000002U)
#define CSL_CSSTM_STMHEMCR_COMPEN_SHIFT                         (1U)
#define CSL_CSSTM_STMHEMCR_COMPEN_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMHEMCR_COMPEN_MAX                           (0x00000001U)

#define CSL_CSSTM_STMHEMCR_ERRDETECT_MASK                       (0x00000004U)
#define CSL_CSSTM_STMHEMCR_ERRDETECT_SHIFT                      (2U)
#define CSL_CSSTM_STMHEMCR_ERRDETECT_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMHEMCR_ERRDETECT_MAX                        (0x00000001U)

#define CSL_CSSTM_STMHEMCR_TRIGCTL_MASK                         (0x00000010U)
#define CSL_CSSTM_STMHEMCR_TRIGCTL_SHIFT                        (4U)
#define CSL_CSSTM_STMHEMCR_TRIGCTL_RESETVAL                     (0x00000000U)
#define CSL_CSSTM_STMHEMCR_TRIGCTL_MAX                          (0x00000001U)

#define CSL_CSSTM_STMHEMCR_TRIGSTATUS_MASK                      (0x00000020U)
#define CSL_CSSTM_STMHEMCR_TRIGSTATUS_SHIFT                     (5U)
#define CSL_CSSTM_STMHEMCR_TRIGSTATUS_RESETVAL                  (0x00000000U)
#define CSL_CSSTM_STMHEMCR_TRIGSTATUS_MAX                       (0x00000001U)

#define CSL_CSSTM_STMHEMCR_TRIGCLEAR_MASK                       (0x00000040U)
#define CSL_CSSTM_STMHEMCR_TRIGCLEAR_SHIFT                      (6U)
#define CSL_CSSTM_STMHEMCR_TRIGCLEAR_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMHEMCR_TRIGCLEAR_MAX                        (0x00000001U)

#define CSL_CSSTM_STMHEMCR_ATBTRIGEN_MASK                       (0x00000080U)
#define CSL_CSSTM_STMHEMCR_ATBTRIGEN_SHIFT                      (7U)
#define CSL_CSSTM_STMHEMCR_ATBTRIGEN_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMHEMCR_ATBTRIGEN_MAX                        (0x00000001U)

#define CSL_CSSTM_STMHEMCR_RESETVAL                             (0x00000000U)

/* STMHEMASTR */

#define CSL_CSSTM_STMHEMASTR_MASTER_MASK                        (0x0000FFFFU)
#define CSL_CSSTM_STMHEMASTR_MASTER_SHIFT                       (0U)
#define CSL_CSSTM_STMHEMASTR_MASTER_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMHEMASTR_MASTER_MAX                         (0x0000ffffU)

#define CSL_CSSTM_STMHEMASTR_RESETVAL                           (0x00000000U)

/* STMHEFEAT1R */

#define CSL_CSSTM_STMHEFEAT1R_HETER_MASK                        (0x00000001U)
#define CSL_CSSTM_STMHEFEAT1R_HETER_SHIFT                       (0U)
#define CSL_CSSTM_STMHEFEAT1R_HETER_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMHEFEAT1R_HETER_MAX                         (0x00000001U)

#define CSL_CSSTM_STMHEFEAT1R_HEERR_MASK                        (0x00000004U)
#define CSL_CSSTM_STMHEFEAT1R_HEERR_SHIFT                       (2U)
#define CSL_CSSTM_STMHEFEAT1R_HEERR_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMHEFEAT1R_HEERR_MAX                         (0x00000001U)

#define CSL_CSSTM_STMHEFEAT1R_HEMASTR_MASK                      (0x00000008U)
#define CSL_CSSTM_STMHEFEAT1R_HEMASTR_SHIFT                     (3U)
#define CSL_CSSTM_STMHEFEAT1R_HEMASTR_RESETVAL                  (0x00000000U)
#define CSL_CSSTM_STMHEFEAT1R_HEMASTR_MAX                       (0x00000001U)

#define CSL_CSSTM_STMHEFEAT1R_HECOMP_MASK                       (0x00000030U)
#define CSL_CSSTM_STMHEFEAT1R_HECOMP_SHIFT                      (4U)
#define CSL_CSSTM_STMHEFEAT1R_HECOMP_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMHEFEAT1R_HECOMP_MAX                        (0x00000003U)

#define CSL_CSSTM_STMHEFEAT1R_NUMHE_MASK                        (0x00FF8000U)
#define CSL_CSSTM_STMHEFEAT1R_NUMHE_SHIFT                       (15U)
#define CSL_CSSTM_STMHEFEAT1R_NUMHE_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMHEFEAT1R_NUMHE_MAX                         (0x000001ffU)

#define CSL_CSSTM_STMHEFEAT1R_RESETVAL                          (0x00000000U)

/* STMHEIDR */

#define CSL_CSSTM_STMHEIDR_CLASS_MASK                           (0x0000000FU)
#define CSL_CSSTM_STMHEIDR_CLASS_SHIFT                          (0U)
#define CSL_CSSTM_STMHEIDR_CLASS_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMHEIDR_CLASS_MAX                            (0x0000000fU)

#define CSL_CSSTM_STMHEIDR_CLASSREV_MASK                        (0x000000F0U)
#define CSL_CSSTM_STMHEIDR_CLASSREV_SHIFT                       (4U)
#define CSL_CSSTM_STMHEIDR_CLASSREV_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMHEIDR_CLASSREV_MAX                         (0x0000000fU)

#define CSL_CSSTM_STMHEIDR_VENDSPEC_MASK                        (0x00000F00U)
#define CSL_CSSTM_STMHEIDR_VENDSPEC_SHIFT                       (8U)
#define CSL_CSSTM_STMHEIDR_VENDSPEC_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMHEIDR_VENDSPEC_MAX                         (0x0000000fU)

#define CSL_CSSTM_STMHEIDR_RESETVAL                             (0x00000000U)

/* STMSPER */

#define CSL_CSSTM_STMSPER_SPE_MASK                              (0xFFFFFFFFU)
#define CSL_CSSTM_STMSPER_SPE_SHIFT                             (0U)
#define CSL_CSSTM_STMSPER_SPE_RESETVAL                          (0x00000000U)
#define CSL_CSSTM_STMSPER_SPE_MAX                               (0xffffffffU)

#define CSL_CSSTM_STMSPER_RESETVAL                              (0x00000000U)

/* STMSPTER */

#define CSL_CSSTM_STMSPTER_SPTE_MASK                            (0xFFFFFFFFU)
#define CSL_CSSTM_STMSPTER_SPTE_SHIFT                           (0U)
#define CSL_CSSTM_STMSPTER_SPTE_RESETVAL                        (0x00000000U)
#define CSL_CSSTM_STMSPTER_SPTE_MAX                             (0xffffffffU)

#define CSL_CSSTM_STMSPTER_RESETVAL                             (0x00000000U)

/* STMSPSCR */

#define CSL_CSSTM_STMSPSCR_PORTSEL_MASK                         (0xFFF00000U)
#define CSL_CSSTM_STMSPSCR_PORTSEL_SHIFT                        (20U)
#define CSL_CSSTM_STMSPSCR_PORTSEL_RESETVAL                     (0x00000000U)
#define CSL_CSSTM_STMSPSCR_PORTSEL_MAX                          (0x00000fffU)

#define CSL_CSSTM_STMSPSCR_PORTCTL_MASK                         (0x00000003U)
#define CSL_CSSTM_STMSPSCR_PORTCTL_SHIFT                        (0U)
#define CSL_CSSTM_STMSPSCR_PORTCTL_RESETVAL                     (0x00000000U)
#define CSL_CSSTM_STMSPSCR_PORTCTL_MAX                          (0x00000003U)

#define CSL_CSSTM_STMSPSCR_RESETVAL                             (0x00000000U)

/* STMSPMSCR */

#define CSL_CSSTM_STMSPMSCR_MASTSEL_MASK                        (0xFFFF8000U)
#define CSL_CSSTM_STMSPMSCR_MASTSEL_SHIFT                       (15U)
#define CSL_CSSTM_STMSPMSCR_MASTSEL_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMSPMSCR_MASTSEL_MAX                         (0x0001ffffU)

#define CSL_CSSTM_STMSPMSCR_MASTCTL_MASK                        (0x00000001U)
#define CSL_CSSTM_STMSPMSCR_MASTCTL_SHIFT                       (0U)
#define CSL_CSSTM_STMSPMSCR_MASTCTL_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMSPMSCR_MASTCTL_MAX                         (0x00000001U)

#define CSL_CSSTM_STMSPMSCR_RESETVAL                            (0x00000000U)

/* STMSPOVERRIDER */

#define CSL_CSSTM_STMSPOVERRIDER_PORTSEL_MASK                   (0xFFFF8000U)
#define CSL_CSSTM_STMSPOVERRIDER_PORTSEL_SHIFT                  (15U)
#define CSL_CSSTM_STMSPOVERRIDER_PORTSEL_RESETVAL               (0x00000000U)
#define CSL_CSSTM_STMSPOVERRIDER_PORTSEL_MAX                    (0x0001ffffU)

#define CSL_CSSTM_STMSPOVERRIDER_OVERTS_MASK                    (0x00000004U)
#define CSL_CSSTM_STMSPOVERRIDER_OVERTS_SHIFT                   (2U)
#define CSL_CSSTM_STMSPOVERRIDER_OVERTS_RESETVAL                (0x00000000U)
#define CSL_CSSTM_STMSPOVERRIDER_OVERTS_MAX                     (0x00000001U)

#define CSL_CSSTM_STMSPOVERRIDER_OVERCTL_MASK                   (0x00000003U)
#define CSL_CSSTM_STMSPOVERRIDER_OVERCTL_SHIFT                  (0U)
#define CSL_CSSTM_STMSPOVERRIDER_OVERCTL_RESETVAL               (0x00000000U)
#define CSL_CSSTM_STMSPOVERRIDER_OVERCTL_MAX                    (0x00000003U)

#define CSL_CSSTM_STMSPOVERRIDER_RESETVAL                       (0x00000000U)

/* STMSPMOVERRIDER */

#define CSL_CSSTM_STMSPMOVERRIDER_MASTSEL_MASK                  (0xFFFF8000U)
#define CSL_CSSTM_STMSPMOVERRIDER_MASTSEL_SHIFT                 (15U)
#define CSL_CSSTM_STMSPMOVERRIDER_MASTSEL_RESETVAL              (0x00000000U)
#define CSL_CSSTM_STMSPMOVERRIDER_MASTSEL_MAX                   (0x0001ffffU)

#define CSL_CSSTM_STMSPMOVERRIDER_MASTCTL_MASK                  (0x00000001U)
#define CSL_CSSTM_STMSPMOVERRIDER_MASTCTL_SHIFT                 (0U)
#define CSL_CSSTM_STMSPMOVERRIDER_MASTCTL_RESETVAL              (0x00000000U)
#define CSL_CSSTM_STMSPMOVERRIDER_MASTCTL_MAX                   (0x00000001U)

#define CSL_CSSTM_STMSPMOVERRIDER_RESETVAL                      (0x00000000U)

/* STMSPTRIGCSR */

#define CSL_CSSTM_STMSPTRIGCSR_ATBTRIGEN_DIR_MASK               (0x00000010U)
#define CSL_CSSTM_STMSPTRIGCSR_ATBTRIGEN_DIR_SHIFT              (4U)
#define CSL_CSSTM_STMSPTRIGCSR_ATBTRIGEN_DIR_RESETVAL           (0x00000000U)
#define CSL_CSSTM_STMSPTRIGCSR_ATBTRIGEN_DIR_MAX                (0x00000001U)

#define CSL_CSSTM_STMSPTRIGCSR_ATBTRIGEN_TE_MASK                (0x00000008U)
#define CSL_CSSTM_STMSPTRIGCSR_ATBTRIGEN_TE_SHIFT               (3U)
#define CSL_CSSTM_STMSPTRIGCSR_ATBTRIGEN_TE_RESETVAL            (0x00000000U)
#define CSL_CSSTM_STMSPTRIGCSR_ATBTRIGEN_TE_MAX                 (0x00000001U)

#define CSL_CSSTM_STMSPTRIGCSR_TRIGCLEAR_MASK                   (0x00000004U)
#define CSL_CSSTM_STMSPTRIGCSR_TRIGCLEAR_SHIFT                  (2U)
#define CSL_CSSTM_STMSPTRIGCSR_TRIGCLEAR_RESETVAL               (0x00000000U)
#define CSL_CSSTM_STMSPTRIGCSR_TRIGCLEAR_MAX                    (0x00000001U)

#define CSL_CSSTM_STMSPTRIGCSR_TRIGSTATUS_MASK                  (0x00000002U)
#define CSL_CSSTM_STMSPTRIGCSR_TRIGSTATUS_SHIFT                 (1U)
#define CSL_CSSTM_STMSPTRIGCSR_TRIGSTATUS_RESETVAL              (0x00000000U)
#define CSL_CSSTM_STMSPTRIGCSR_TRIGSTATUS_MAX                   (0x00000001U)

#define CSL_CSSTM_STMSPTRIGCSR_TRIGCTL_MASK                     (0x00000001U)
#define CSL_CSSTM_STMSPTRIGCSR_TRIGCTL_SHIFT                    (0U)
#define CSL_CSSTM_STMSPTRIGCSR_TRIGCTL_RESETVAL                 (0x00000000U)
#define CSL_CSSTM_STMSPTRIGCSR_TRIGCTL_MAX                      (0x00000001U)

#define CSL_CSSTM_STMSPTRIGCSR_RESETVAL                         (0x00000000U)

/* STMTCSR */

#define CSL_CSSTM_STMTCSR_BUSY_MASK                             (0x00800000U)
#define CSL_CSSTM_STMTCSR_BUSY_SHIFT                            (23U)
#define CSL_CSSTM_STMTCSR_BUSY_RESETVAL                         (0x00000000U)
#define CSL_CSSTM_STMTCSR_BUSY_MAX                              (0x00000001U)

#define CSL_CSSTM_STMTCSR_TRACEID_MASK                          (0x007F0000U)
#define CSL_CSSTM_STMTCSR_TRACEID_SHIFT                         (16U)
#define CSL_CSSTM_STMTCSR_TRACEID_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMTCSR_TRACEID_MAX                           (0x0000007fU)

#define CSL_CSSTM_STMTCSR_COMPEN_MASK                           (0x00000020U)
#define CSL_CSSTM_STMTCSR_COMPEN_SHIFT                          (5U)
#define CSL_CSSTM_STMTCSR_COMPEN_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMTCSR_COMPEN_MAX                            (0x00000001U)

#define CSL_CSSTM_STMTCSR_SYNCEN_MASK                           (0x00000004U)
#define CSL_CSSTM_STMTCSR_SYNCEN_SHIFT                          (2U)
#define CSL_CSSTM_STMTCSR_SYNCEN_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMTCSR_SYNCEN_MAX                            (0x00000001U)

#define CSL_CSSTM_STMTCSR_TSEN_MASK                             (0x00000002U)
#define CSL_CSSTM_STMTCSR_TSEN_SHIFT                            (1U)
#define CSL_CSSTM_STMTCSR_TSEN_RESETVAL                         (0x00000000U)
#define CSL_CSSTM_STMTCSR_TSEN_MAX                              (0x00000001U)

#define CSL_CSSTM_STMTCSR_EN_MASK                               (0x00000001U)
#define CSL_CSSTM_STMTCSR_EN_SHIFT                              (0U)
#define CSL_CSSTM_STMTCSR_EN_RESETVAL                           (0x00000000U)
#define CSL_CSSTM_STMTCSR_EN_MAX                                (0x00000001U)

#define CSL_CSSTM_STMTCSR_RESETVAL                              (0x00000000U)

/* STMTSSTIMR */

#define CSL_CSSTM_STMTSSTIMR_FORCETS_MASK                       (0x00000001U)
#define CSL_CSSTM_STMTSSTIMR_FORCETS_SHIFT                      (0U)
#define CSL_CSSTM_STMTSSTIMR_FORCETS_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMTSSTIMR_FORCETS_MAX                        (0x00000001U)

#define CSL_CSSTM_STMTSSTIMR_RESETVAL                           (0x00000000U)

/* STMTSFREQR */

#define CSL_CSSTM_STMTSFREQR_FREQ_MASK                          (0xFFFFFFFFU)
#define CSL_CSSTM_STMTSFREQR_FREQ_SHIFT                         (0U)
#define CSL_CSSTM_STMTSFREQR_FREQ_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMTSFREQR_FREQ_MAX                           (0xffffffffU)

#define CSL_CSSTM_STMTSFREQR_RESETVAL                           (0x00000000U)

/* STMSYNCR */

#define CSL_CSSTM_STMSYNCR_MODE_MASK                            (0x00001000U)
#define CSL_CSSTM_STMSYNCR_MODE_SHIFT                           (12U)
#define CSL_CSSTM_STMSYNCR_MODE_RESETVAL                        (0x00000000U)
#define CSL_CSSTM_STMSYNCR_MODE_MAX                             (0x00000001U)

#define CSL_CSSTM_STMSYNCR_COUNT_MASK                           (0x00000FFFU)
#define CSL_CSSTM_STMSYNCR_COUNT_SHIFT                          (0U)
#define CSL_CSSTM_STMSYNCR_COUNT_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMSYNCR_COUNT_MAX                            (0x00000fffU)

#define CSL_CSSTM_STMSYNCR_RESETVAL                             (0x00000000U)

/* STMAUXCR */

#define CSL_CSSTM_STMAUXCR_FIFOAF_MASK                          (0x00000001U)
#define CSL_CSSTM_STMAUXCR_FIFOAF_SHIFT                         (0U)
#define CSL_CSSTM_STMAUXCR_FIFOAF_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMAUXCR_FIFOAF_MAX                           (0x00000001U)

#define CSL_CSSTM_STMAUXCR_ASYNCPE_MASK                         (0x00000002U)
#define CSL_CSSTM_STMAUXCR_ASYNCPE_SHIFT                        (1U)
#define CSL_CSSTM_STMAUXCR_ASYNCPE_RESETVAL                     (0x00000000U)
#define CSL_CSSTM_STMAUXCR_ASYNCPE_MAX                          (0x00000001U)

#define CSL_CSSTM_STMAUXCR_PRIORINVDIS_MASK                     (0x00000004U)
#define CSL_CSSTM_STMAUXCR_PRIORINVDIS_SHIFT                    (2U)
#define CSL_CSSTM_STMAUXCR_PRIORINVDIS_RESETVAL                 (0x00000000U)
#define CSL_CSSTM_STMAUXCR_PRIORINVDIS_MAX                      (0x00000001U)

#define CSL_CSSTM_STMAUXCR_CLKON_MASK                           (0x00000008U)
#define CSL_CSSTM_STMAUXCR_CLKON_SHIFT                          (3U)
#define CSL_CSSTM_STMAUXCR_CLKON_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMAUXCR_CLKON_MAX                            (0x00000001U)

#define CSL_CSSTM_STMAUXCR_AFREADYHIGH_MASK                     (0x00000010U)
#define CSL_CSSTM_STMAUXCR_AFREADYHIGH_SHIFT                    (4U)
#define CSL_CSSTM_STMAUXCR_AFREADYHIGH_RESETVAL                 (0x00000000U)
#define CSL_CSSTM_STMAUXCR_AFREADYHIGH_MAX                      (0x00000001U)

#define CSL_CSSTM_STMAUXCR_RESETVAL                             (0x00000000U)

/* STMFEAT1R */

#define CSL_CSSTM_STMFEAT1R_PROT_MASK                           (0x0000000FU)
#define CSL_CSSTM_STMFEAT1R_PROT_SHIFT                          (0U)
#define CSL_CSSTM_STMFEAT1R_PROT_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_PROT_MAX                            (0x0000000fU)

#define CSL_CSSTM_STMFEAT1R_TS_MASK                             (0x00000030U)
#define CSL_CSSTM_STMFEAT1R_TS_SHIFT                            (4U)
#define CSL_CSSTM_STMFEAT1R_TS_RESETVAL                         (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_TS_MAX                              (0x00000003U)

#define CSL_CSSTM_STMFEAT1R_TSFREQ_MASK                         (0x00000040U)
#define CSL_CSSTM_STMFEAT1R_TSFREQ_SHIFT                        (6U)
#define CSL_CSSTM_STMFEAT1R_TSFREQ_RESETVAL                     (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_TSFREQ_MAX                          (0x00000001U)

#define CSL_CSSTM_STMFEAT1R_FORCETS_MASK                        (0x00000080U)
#define CSL_CSSTM_STMFEAT1R_FORCETS_SHIFT                       (7U)
#define CSL_CSSTM_STMFEAT1R_FORCETS_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_FORCETS_MAX                         (0x00000001U)

#define CSL_CSSTM_STMFEAT1R_SYNC_MASK                           (0x00000300U)
#define CSL_CSSTM_STMFEAT1R_SYNC_SHIFT                          (8U)
#define CSL_CSSTM_STMFEAT1R_SYNC_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_SYNC_MAX                            (0x00000003U)

#define CSL_CSSTM_STMFEAT1R_TRACEBUS_MASK                       (0x00003C00U)
#define CSL_CSSTM_STMFEAT1R_TRACEBUS_SHIFT                      (10U)
#define CSL_CSSTM_STMFEAT1R_TRACEBUS_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_TRACEBUS_MAX                        (0x0000000fU)

#define CSL_CSSTM_STMFEAT1R_TRIGCTL_MASK                        (0x0000C000U)
#define CSL_CSSTM_STMFEAT1R_TRIGCTL_SHIFT                       (14U)
#define CSL_CSSTM_STMFEAT1R_TRIGCTL_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_TRIGCTL_MAX                         (0x00000003U)

#define CSL_CSSTM_STMFEAT1R_TSPRESCALE_MASK                     (0x00030000U)
#define CSL_CSSTM_STMFEAT1R_TSPRESCALE_SHIFT                    (16U)
#define CSL_CSSTM_STMFEAT1R_TSPRESCALE_RESETVAL                 (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_TSPRESCALE_MAX                      (0x00000003U)

#define CSL_CSSTM_STMFEAT1R_HWTEN_MASK                          (0x000C0000U)
#define CSL_CSSTM_STMFEAT1R_HWTEN_SHIFT                         (18U)
#define CSL_CSSTM_STMFEAT1R_HWTEN_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_HWTEN_MAX                           (0x00000003U)

#define CSL_CSSTM_STMFEAT1R_SYNCEN_MASK                         (0x00300000U)
#define CSL_CSSTM_STMFEAT1R_SYNCEN_SHIFT                        (20U)
#define CSL_CSSTM_STMFEAT1R_SYNCEN_RESETVAL                     (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_SYNCEN_MAX                          (0x00000003U)

#define CSL_CSSTM_STMFEAT1R_SWOEN_MASK                          (0x00C00000U)
#define CSL_CSSTM_STMFEAT1R_SWOEN_SHIFT                         (22U)
#define CSL_CSSTM_STMFEAT1R_SWOEN_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMFEAT1R_SWOEN_MAX                           (0x00000003U)

#define CSL_CSSTM_STMFEAT1R_RESETVAL                            (0x00000000U)

/* STMFEAT2R */

#define CSL_CSSTM_STMFEAT2R_SPTER_MASK                          (0x00000003U)
#define CSL_CSSTM_STMFEAT2R_SPTER_SHIFT                         (0U)
#define CSL_CSSTM_STMFEAT2R_SPTER_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMFEAT2R_SPTER_MAX                           (0x00000003U)

#define CSL_CSSTM_STMFEAT2R_SPER_MASK                           (0x00000004U)
#define CSL_CSSTM_STMFEAT2R_SPER_SHIFT                          (2U)
#define CSL_CSSTM_STMFEAT2R_SPER_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMFEAT2R_SPER_MAX                            (0x00000001U)

#define CSL_CSSTM_STMFEAT2R_SPCOMP_MASK                         (0x00000030U)
#define CSL_CSSTM_STMFEAT2R_SPCOMP_SHIFT                        (4U)
#define CSL_CSSTM_STMFEAT2R_SPCOMP_RESETVAL                     (0x00000000U)
#define CSL_CSSTM_STMFEAT2R_SPCOMP_MAX                          (0x00000003U)

#define CSL_CSSTM_STMFEAT2R_SPOVERRIDE_MASK                     (0x00000040U)
#define CSL_CSSTM_STMFEAT2R_SPOVERRIDE_SHIFT                    (6U)
#define CSL_CSSTM_STMFEAT2R_SPOVERRIDE_RESETVAL                 (0x00000000U)
#define CSL_CSSTM_STMFEAT2R_SPOVERRIDE_MAX                      (0x00000001U)

#define CSL_CSSTM_STMFEAT2R_PRIVMASK_MASK                       (0x00000180U)
#define CSL_CSSTM_STMFEAT2R_PRIVMASK_SHIFT                      (7U)
#define CSL_CSSTM_STMFEAT2R_PRIVMASK_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMFEAT2R_PRIVMASK_MAX                        (0x00000003U)

#define CSL_CSSTM_STMFEAT2R_SPTRTYPE_MASK                       (0x00000600U)
#define CSL_CSSTM_STMFEAT2R_SPTRTYPE_SHIFT                      (9U)
#define CSL_CSSTM_STMFEAT2R_SPTRTYPE_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMFEAT2R_SPTRTYPE_MAX                        (0x00000003U)

#define CSL_CSSTM_STMFEAT2R_DSIZE_MASK                          (0x0000F000U)
#define CSL_CSSTM_STMFEAT2R_DSIZE_SHIFT                         (12U)
#define CSL_CSSTM_STMFEAT2R_DSIZE_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMFEAT2R_DSIZE_MAX                           (0x0000000fU)

#define CSL_CSSTM_STMFEAT2R_SPTYPE_MASK                         (0x00030000U)
#define CSL_CSSTM_STMFEAT2R_SPTYPE_SHIFT                        (16U)
#define CSL_CSSTM_STMFEAT2R_SPTYPE_RESETVAL                     (0x00000000U)
#define CSL_CSSTM_STMFEAT2R_SPTYPE_MAX                          (0x00000003U)

#define CSL_CSSTM_STMFEAT2R_RESETVAL                            (0x00000000U)

/* STMFEAT3R */

#define CSL_CSSTM_STMFEAT3R_NUMMAST_MASK                        (0x0000007FU)
#define CSL_CSSTM_STMFEAT3R_NUMMAST_SHIFT                       (0U)
#define CSL_CSSTM_STMFEAT3R_NUMMAST_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMFEAT3R_NUMMAST_MAX                         (0x0000007fU)

#define CSL_CSSTM_STMFEAT3R_RESETVAL                            (0x00000000U)

/* STMITCTRL */

#define CSL_CSSTM_STMITCTRL_INTEGRATION_MODE_MASK               (0x00000001U)
#define CSL_CSSTM_STMITCTRL_INTEGRATION_MODE_SHIFT              (0U)
#define CSL_CSSTM_STMITCTRL_INTEGRATION_MODE_RESETVAL           (0x00000000U)
#define CSL_CSSTM_STMITCTRL_INTEGRATION_MODE_MAX                (0x00000001U)

#define CSL_CSSTM_STMITCTRL_RESETVAL                            (0x00000000U)

/* STMCLAIMSET */

#define CSL_CSSTM_STMCLAIMSET_CLAIMSET_MASK                     (0x0000000FU)
#define CSL_CSSTM_STMCLAIMSET_CLAIMSET_SHIFT                    (0U)
#define CSL_CSSTM_STMCLAIMSET_CLAIMSET_RESETVAL                 (0x00000000U)
#define CSL_CSSTM_STMCLAIMSET_CLAIMSET_MAX                      (0x0000000fU)

#define CSL_CSSTM_STMCLAIMSET_RESETVAL                          (0x00000000U)

/* STMCLAIMCLR */

#define CSL_CSSTM_STMCLAIMCLR_CLAIMCLR_MASK                     (0x0000000FU)
#define CSL_CSSTM_STMCLAIMCLR_CLAIMCLR_SHIFT                    (0U)
#define CSL_CSSTM_STMCLAIMCLR_CLAIMCLR_RESETVAL                 (0x00000000U)
#define CSL_CSSTM_STMCLAIMCLR_CLAIMCLR_MAX                      (0x0000000fU)

#define CSL_CSSTM_STMCLAIMCLR_RESETVAL                          (0x00000000U)

/* STMLAR */

#define CSL_CSSTM_STMLAR_ACCESS_W_MASK                          (0xFFFFFFFFU)
#define CSL_CSSTM_STMLAR_ACCESS_W_SHIFT                         (0U)
#define CSL_CSSTM_STMLAR_ACCESS_W_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMLAR_ACCESS_W_MAX                           (0xffffffffU)

#define CSL_CSSTM_STMLAR_RESETVAL                               (0x00000000U)

/* STMLSR */

#define CSL_CSSTM_STMLSR_PRESENT_MASK                           (0x00000001U)
#define CSL_CSSTM_STMLSR_PRESENT_SHIFT                          (0U)
#define CSL_CSSTM_STMLSR_PRESENT_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMLSR_PRESENT_MAX                            (0x00000001U)

#define CSL_CSSTM_STMLSR_LOCKED_MASK                            (0x00000002U)
#define CSL_CSSTM_STMLSR_LOCKED_SHIFT                           (1U)
#define CSL_CSSTM_STMLSR_LOCKED_RESETVAL                        (0x00000000U)
#define CSL_CSSTM_STMLSR_LOCKED_MAX                             (0x00000001U)

#define CSL_CSSTM_STMLSR_TYPE_MASK                              (0x00000004U)
#define CSL_CSSTM_STMLSR_TYPE_SHIFT                             (2U)
#define CSL_CSSTM_STMLSR_TYPE_RESETVAL                          (0x00000000U)
#define CSL_CSSTM_STMLSR_TYPE_MAX                               (0x00000001U)

#define CSL_CSSTM_STMLSR_RESETVAL                               (0x00000000U)

/* STMAUTHSTATUS */

#define CSL_CSSTM_STMAUTHSTATUS_NSID_MASK                       (0x00000003U)
#define CSL_CSSTM_STMAUTHSTATUS_NSID_SHIFT                      (0U)
#define CSL_CSSTM_STMAUTHSTATUS_NSID_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMAUTHSTATUS_NSID_MAX                        (0x00000003U)

#define CSL_CSSTM_STMAUTHSTATUS_NSNID_MASK                      (0x0000000CU)
#define CSL_CSSTM_STMAUTHSTATUS_NSNID_SHIFT                     (2U)
#define CSL_CSSTM_STMAUTHSTATUS_NSNID_RESETVAL                  (0x00000000U)
#define CSL_CSSTM_STMAUTHSTATUS_NSNID_MAX                       (0x00000003U)

#define CSL_CSSTM_STMAUTHSTATUS_SID_MASK                        (0x00000030U)
#define CSL_CSSTM_STMAUTHSTATUS_SID_SHIFT                       (4U)
#define CSL_CSSTM_STMAUTHSTATUS_SID_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMAUTHSTATUS_SID_MAX                         (0x00000003U)

#define CSL_CSSTM_STMAUTHSTATUS_SNID_MASK                       (0x000000C0U)
#define CSL_CSSTM_STMAUTHSTATUS_SNID_SHIFT                      (6U)
#define CSL_CSSTM_STMAUTHSTATUS_SNID_RESETVAL                   (0x00000000U)
#define CSL_CSSTM_STMAUTHSTATUS_SNID_MAX                        (0x00000003U)

#define CSL_CSSTM_STMAUTHSTATUS_RESETVAL                        (0x00000000U)

/* STMDEVID */

#define CSL_CSSTM_STMDEVID_NUMSP_MASK                           (0x0001FFFFU)
#define CSL_CSSTM_STMDEVID_NUMSP_SHIFT                          (0U)
#define CSL_CSSTM_STMDEVID_NUMSP_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMDEVID_NUMSP_MAX                            (0x0001ffffU)

#define CSL_CSSTM_STMDEVID_RESETVAL                             (0x00000000U)

/* STMDEVTYPE */

#define CSL_CSSTM_STMDEVTYPE_MAJOR_TYPE_MASK                    (0x0000000FU)
#define CSL_CSSTM_STMDEVTYPE_MAJOR_TYPE_SHIFT                   (0U)
#define CSL_CSSTM_STMDEVTYPE_MAJOR_TYPE_RESETVAL                (0x00000000U)
#define CSL_CSSTM_STMDEVTYPE_MAJOR_TYPE_MAX                     (0x0000000fU)

#define CSL_CSSTM_STMDEVTYPE_SUB_TYPE_MASK                      (0x000000F0U)
#define CSL_CSSTM_STMDEVTYPE_SUB_TYPE_SHIFT                     (4U)
#define CSL_CSSTM_STMDEVTYPE_SUB_TYPE_RESETVAL                  (0x00000000U)
#define CSL_CSSTM_STMDEVTYPE_SUB_TYPE_MAX                       (0x0000000fU)

#define CSL_CSSTM_STMDEVTYPE_RESETVAL                           (0x00000000U)

/* STMPIDR4 */

#define CSL_CSSTM_STMPIDR4_JEP106_CONT_MASK                     (0x0000000FU)
#define CSL_CSSTM_STMPIDR4_JEP106_CONT_SHIFT                    (0U)
#define CSL_CSSTM_STMPIDR4_JEP106_CONT_RESETVAL                 (0x00000000U)
#define CSL_CSSTM_STMPIDR4_JEP106_CONT_MAX                      (0x0000000fU)

#define CSL_CSSTM_STMPIDR4_FOURKB_COUNT_MASK                    (0x000000F0U)
#define CSL_CSSTM_STMPIDR4_FOURKB_COUNT_SHIFT                   (4U)
#define CSL_CSSTM_STMPIDR4_FOURKB_COUNT_RESETVAL                (0x00000000U)
#define CSL_CSSTM_STMPIDR4_FOURKB_COUNT_MAX                     (0x0000000fU)

#define CSL_CSSTM_STMPIDR4_RESETVAL                             (0x00000000U)

/* STMPIDR0 */

#define CSL_CSSTM_STMPIDR0_PART_NUMBER_BITS7TO0_MASK            (0x000000FFU)
#define CSL_CSSTM_STMPIDR0_PART_NUMBER_BITS7TO0_SHIFT           (0U)
#define CSL_CSSTM_STMPIDR0_PART_NUMBER_BITS7TO0_RESETVAL        (0x00000000U)
#define CSL_CSSTM_STMPIDR0_PART_NUMBER_BITS7TO0_MAX             (0x000000ffU)

#define CSL_CSSTM_STMPIDR0_RESETVAL                             (0x00000000U)

/* STMPIDR1 */

#define CSL_CSSTM_STMPIDR1_PART_NUMBER_BITS11TO8_MASK           (0x0000000FU)
#define CSL_CSSTM_STMPIDR1_PART_NUMBER_BITS11TO8_SHIFT          (0U)
#define CSL_CSSTM_STMPIDR1_PART_NUMBER_BITS11TO8_RESETVAL       (0x00000000U)
#define CSL_CSSTM_STMPIDR1_PART_NUMBER_BITS11TO8_MAX            (0x0000000fU)

#define CSL_CSSTM_STMPIDR1_JEP106_BITS3TO0_MASK                 (0x000000F0U)
#define CSL_CSSTM_STMPIDR1_JEP106_BITS3TO0_SHIFT                (4U)
#define CSL_CSSTM_STMPIDR1_JEP106_BITS3TO0_RESETVAL             (0x00000000U)
#define CSL_CSSTM_STMPIDR1_JEP106_BITS3TO0_MAX                  (0x0000000fU)

#define CSL_CSSTM_STMPIDR1_RESETVAL                             (0x00000000U)

/* STMPIDR2 */

#define CSL_CSSTM_STMPIDR2_JEP106_BITS6TO4_MASK                 (0x00000007U)
#define CSL_CSSTM_STMPIDR2_JEP106_BITS6TO4_SHIFT                (0U)
#define CSL_CSSTM_STMPIDR2_JEP106_BITS6TO4_RESETVAL             (0x00000000U)
#define CSL_CSSTM_STMPIDR2_JEP106_BITS6TO4_MAX                  (0x00000007U)

#define CSL_CSSTM_STMPIDR2_JEDEC_MASK                           (0x00000008U)
#define CSL_CSSTM_STMPIDR2_JEDEC_SHIFT                          (3U)
#define CSL_CSSTM_STMPIDR2_JEDEC_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMPIDR2_JEDEC_MAX                            (0x00000001U)

#define CSL_CSSTM_STMPIDR2_REVISION_MASK                        (0x000000F0U)
#define CSL_CSSTM_STMPIDR2_REVISION_SHIFT                       (4U)
#define CSL_CSSTM_STMPIDR2_REVISION_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMPIDR2_REVISION_MAX                         (0x0000000fU)

#define CSL_CSSTM_STMPIDR2_RESETVAL                             (0x00000000U)

/* STMPIDR3 */

#define CSL_CSSTM_STMPIDR3_CUSTOMER_MODIFIED_MASK               (0x0000000FU)
#define CSL_CSSTM_STMPIDR3_CUSTOMER_MODIFIED_SHIFT              (0U)
#define CSL_CSSTM_STMPIDR3_CUSTOMER_MODIFIED_RESETVAL           (0x00000000U)
#define CSL_CSSTM_STMPIDR3_CUSTOMER_MODIFIED_MAX                (0x0000000fU)

#define CSL_CSSTM_STMPIDR3_REVAND_MASK                          (0x000000F0U)
#define CSL_CSSTM_STMPIDR3_REVAND_SHIFT                         (4U)
#define CSL_CSSTM_STMPIDR3_REVAND_RESETVAL                      (0x00000000U)
#define CSL_CSSTM_STMPIDR3_REVAND_MAX                           (0x0000000fU)

#define CSL_CSSTM_STMPIDR3_RESETVAL                             (0x00000000U)

/* STMCIDR0 */

#define CSL_CSSTM_STMCIDR0_PREAMBLE_MASK                        (0x000000FFU)
#define CSL_CSSTM_STMCIDR0_PREAMBLE_SHIFT                       (0U)
#define CSL_CSSTM_STMCIDR0_PREAMBLE_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMCIDR0_PREAMBLE_MAX                         (0x000000ffU)

#define CSL_CSSTM_STMCIDR0_RESETVAL                             (0x00000000U)

/* STMCIDR1 */

#define CSL_CSSTM_STMCIDR1_PREAMBLE_MASK                        (0x0000000FU)
#define CSL_CSSTM_STMCIDR1_PREAMBLE_SHIFT                       (0U)
#define CSL_CSSTM_STMCIDR1_PREAMBLE_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMCIDR1_PREAMBLE_MAX                         (0x0000000fU)

#define CSL_CSSTM_STMCIDR1_CLASS_MASK                           (0x000000F0U)
#define CSL_CSSTM_STMCIDR1_CLASS_SHIFT                          (4U)
#define CSL_CSSTM_STMCIDR1_CLASS_RESETVAL                       (0x00000000U)
#define CSL_CSSTM_STMCIDR1_CLASS_MAX                            (0x0000000fU)

#define CSL_CSSTM_STMCIDR1_RESETVAL                             (0x00000000U)

/* STMCIDR2 */

#define CSL_CSSTM_STMCIDR2_PREAMBLE_MASK                        (0x000000FFU)
#define CSL_CSSTM_STMCIDR2_PREAMBLE_SHIFT                       (0U)
#define CSL_CSSTM_STMCIDR2_PREAMBLE_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMCIDR2_PREAMBLE_MAX                         (0x000000ffU)

#define CSL_CSSTM_STMCIDR2_RESETVAL                             (0x00000000U)

/* STMCIDR3 */

#define CSL_CSSTM_STMCIDR3_PREAMBLE_MASK                        (0x000000FFU)
#define CSL_CSSTM_STMCIDR3_PREAMBLE_SHIFT                       (0U)
#define CSL_CSSTM_STMCIDR3_PREAMBLE_RESETVAL                    (0x00000000U)
#define CSL_CSSTM_STMCIDR3_PREAMBLE_MAX                         (0x000000ffU)

#define CSL_CSSTM_STMCIDR3_RESETVAL                             (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
