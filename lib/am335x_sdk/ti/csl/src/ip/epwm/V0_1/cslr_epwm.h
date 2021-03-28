/********************************************************************
 * Copyright (C) 2019 Texas Instruments Incorporated.
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
 *  Name        : cslr_epwm.h
*/
#ifndef CSLR_EPWM_H_
#define CSLR_EPWM_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint16_t TBCTL;
    volatile uint16_t TBSTS;
    volatile uint16_t TBPHSHR;
    volatile uint16_t TBPHS;
    volatile uint16_t TBCNT;
    volatile uint16_t TBPRD;
    volatile uint8_t  Resv_14[2];
    volatile uint16_t CMPCTL;
    volatile uint16_t CMPAHR;
    volatile uint16_t CMPA;
    volatile uint16_t CMPB;
    volatile uint16_t AQCTLA;
    volatile uint16_t AQCTLB;
    volatile uint16_t AQSFRC;
    volatile uint16_t AQCSFRC;
    volatile uint16_t DBCTL;
    volatile uint16_t DBRED;
    volatile uint16_t DBFED;
    volatile uint16_t TZSEL;
    volatile uint8_t  Resv_40[2];
    volatile uint16_t TZCTL;
    volatile uint16_t TZEINT;
    volatile uint16_t TZFLG;
    volatile uint16_t TZCLR;
    volatile uint16_t TZFRC;
    volatile uint16_t ETSEL;
    volatile uint16_t ETPS;
    volatile uint16_t ETFLG;
    volatile uint16_t ETCLR;
    volatile uint16_t ETFRC;
    volatile uint16_t PCCTL;
    volatile uint8_t  Resv_92[30];
    volatile uint32_t PID;
} CSL_epwmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_EPWM_TBCTL                                                         (0x00000000U)
#define CSL_EPWM_TBSTS                                                         (0x00000002U)
#define CSL_EPWM_TBPHSHR                                                       (0x00000004U)
#define CSL_EPWM_TBPHS                                                         (0x00000006U)
#define CSL_EPWM_TBCNT                                                         (0x00000008U)
#define CSL_EPWM_TBPRD                                                         (0x0000000AU)
#define CSL_EPWM_CMPCTL                                                        (0x0000000EU)
#define CSL_EPWM_CMPAHR                                                        (0x00000010U)
#define CSL_EPWM_CMPA                                                          (0x00000012U)
#define CSL_EPWM_CMPB                                                          (0x00000014U)
#define CSL_EPWM_AQCTLA                                                        (0x00000016U)
#define CSL_EPWM_AQCTLB                                                        (0x00000018U)
#define CSL_EPWM_AQSFRC                                                        (0x0000001AU)
#define CSL_EPWM_AQCSFRC                                                       (0x0000001CU)
#define CSL_EPWM_DBCTL                                                         (0x0000001EU)
#define CSL_EPWM_DBRED                                                         (0x00000020U)
#define CSL_EPWM_DBFED                                                         (0x00000022U)
#define CSL_EPWM_TZSEL                                                         (0x00000024U)
#define CSL_EPWM_TZCTL                                                         (0x00000028U)
#define CSL_EPWM_TZEINT                                                        (0x0000002AU)
#define CSL_EPWM_TZFLG                                                         (0x0000002CU)
#define CSL_EPWM_TZCLR                                                         (0x0000002EU)
#define CSL_EPWM_TZFRC                                                         (0x00000030U)
#define CSL_EPWM_ETSEL                                                         (0x00000032U)
#define CSL_EPWM_ETPS                                                          (0x00000034U)
#define CSL_EPWM_ETFLG                                                         (0x00000036U)
#define CSL_EPWM_ETCLR                                                         (0x00000038U)
#define CSL_EPWM_ETFRC                                                         (0x0000003AU)
#define CSL_EPWM_PCCTL                                                         (0x0000003CU)
#define CSL_EPWM_PID                                                           (0x0000005CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* TBCTL */

#define CSL_EPWM_TBCTL_CTRMODE_MASK                                            (0x0003U)
#define CSL_EPWM_TBCTL_CTRMODE_SHIFT                                           (0x0000U)
#define CSL_EPWM_TBCTL_CTRMODE_RESETVAL                                        (0x0003U)
#define CSL_EPWM_TBCTL_CTRMODE_MAX                                             (0x0003U)

#define CSL_EPWM_TBCTL_PHSEN_MASK                                              (0x0004U)
#define CSL_EPWM_TBCTL_PHSEN_SHIFT                                             (0x0002U)
#define CSL_EPWM_TBCTL_PHSEN_RESETVAL                                          (0x0000U)
#define CSL_EPWM_TBCTL_PHSEN_MAX                                               (0x0001U)

#define CSL_EPWM_TBCTL_PRDLD_MASK                                              (0x0008U)
#define CSL_EPWM_TBCTL_PRDLD_SHIFT                                             (0x0003U)
#define CSL_EPWM_TBCTL_PRDLD_RESETVAL                                          (0x0000U)
#define CSL_EPWM_TBCTL_PRDLD_MAX                                               (0x0001U)

#define CSL_EPWM_TBCTL_SYNCOSEL_MASK                                           (0x0030U)
#define CSL_EPWM_TBCTL_SYNCOSEL_SHIFT                                          (0x0004U)
#define CSL_EPWM_TBCTL_SYNCOSEL_RESETVAL                                       (0x0000U)
#define CSL_EPWM_TBCTL_SYNCOSEL_MAX                                            (0x0003U)

#define CSL_EPWM_TBCTL_SWFSYNC_MASK                                            (0x0040U)
#define CSL_EPWM_TBCTL_SWFSYNC_SHIFT                                           (0x0006U)
#define CSL_EPWM_TBCTL_SWFSYNC_RESETVAL                                        (0x0000U)
#define CSL_EPWM_TBCTL_SWFSYNC_MAX                                             (0x0001U)

#define CSL_EPWM_TBCTL_HSPCLKDIV_MASK                                          (0x0380U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_SHIFT                                         (0x0007U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_RESETVAL                                      (0x0001U)
#define CSL_EPWM_TBCTL_HSPCLKDIV_MAX                                           (0x0007U)

#define CSL_EPWM_TBCTL_CLKDIV_MASK                                             (0x1C00U)
#define CSL_EPWM_TBCTL_CLKDIV_SHIFT                                            (0x000AU)
#define CSL_EPWM_TBCTL_CLKDIV_RESETVAL                                         (0x0000U)
#define CSL_EPWM_TBCTL_CLKDIV_MAX                                              (0x0007U)

#define CSL_EPWM_TBCTL_PHSDIR_MASK                                             (0x2000U)
#define CSL_EPWM_TBCTL_PHSDIR_SHIFT                                            (0x000DU)
#define CSL_EPWM_TBCTL_PHSDIR_RESETVAL                                         (0x0000U)
#define CSL_EPWM_TBCTL_PHSDIR_MAX                                              (0x0001U)

#define CSL_EPWM_TBCTL_FREE_SOFT_MASK                                          (0xC000U)
#define CSL_EPWM_TBCTL_FREE_SOFT_SHIFT                                         (0x000EU)
#define CSL_EPWM_TBCTL_FREE_SOFT_RESETVAL                                      (0x0000U)
#define CSL_EPWM_TBCTL_FREE_SOFT_MAX                                           (0x0003U)

#define CSL_EPWM_TBCTL_RESETVAL                                                (0x0083U)

/* TBSTS */

#define CSL_EPWM_TBSTS_CTRDIR_MASK                                             (0x0001U)
#define CSL_EPWM_TBSTS_CTRDIR_SHIFT                                            (0x0000U)
#define CSL_EPWM_TBSTS_CTRDIR_RESETVAL                                         (0x0000U)
#define CSL_EPWM_TBSTS_CTRDIR_MAX                                              (0x0001U)

#define CSL_EPWM_TBSTS_SYNCI_MASK                                              (0x0002U)
#define CSL_EPWM_TBSTS_SYNCI_SHIFT                                             (0x0001U)
#define CSL_EPWM_TBSTS_SYNCI_RESETVAL                                          (0x0000U)
#define CSL_EPWM_TBSTS_SYNCI_MAX                                               (0x0001U)

#define CSL_EPWM_TBSTS_CTRMAX_MASK                                             (0x0004U)
#define CSL_EPWM_TBSTS_CTRMAX_SHIFT                                            (0x0002U)
#define CSL_EPWM_TBSTS_CTRMAX_RESETVAL                                         (0x0000U)
#define CSL_EPWM_TBSTS_CTRMAX_MAX                                              (0x0001U)

#define CSL_EPWM_TBSTS_RESERVED1_MASK                                          (0xFFF8U)
#define CSL_EPWM_TBSTS_RESERVED1_SHIFT                                         (0x0003U)
#define CSL_EPWM_TBSTS_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_TBSTS_RESERVED1_MAX                                           (0x1FFFU)

#define CSL_EPWM_TBSTS_RESETVAL                                                (0x0000U)

/* TBPHSHR */

#define CSL_EPWM_TBPHSHR_RESERVED1_MASK                                        (0x00FFU)
#define CSL_EPWM_TBPHSHR_RESERVED1_SHIFT                                       (0x0000U)
#define CSL_EPWM_TBPHSHR_RESERVED1_RESETVAL                                    (0x0000U)
#define CSL_EPWM_TBPHSHR_RESERVED1_MAX                                         (0x00FFU)

#define CSL_EPWM_TBPHSHR_TBPHSH_MASK                                           (0xFF00U)
#define CSL_EPWM_TBPHSHR_TBPHSH_SHIFT                                          (0x0008U)
#define CSL_EPWM_TBPHSHR_TBPHSH_RESETVAL                                       (0x0000U)
#define CSL_EPWM_TBPHSHR_TBPHSH_MAX                                            (0x00FFU)

#define CSL_EPWM_TBPHSHR_RESETVAL                                              (0x0000U)

/* TBPHS */

#define CSL_EPWM_TBPHS_TBPHS_MASK                                              (0xFFFFU)
#define CSL_EPWM_TBPHS_TBPHS_SHIFT                                             (0x0000U)
#define CSL_EPWM_TBPHS_TBPHS_RESETVAL                                          (0x0000U)
#define CSL_EPWM_TBPHS_TBPHS_MAX                                               (0xFFFFU)

#define CSL_EPWM_TBPHS_RESETVAL                                                (0x0000U)

/* TBCNT */

#define CSL_EPWM_TBCNT_TBCNT_MASK                                              (0xFFFFU)
#define CSL_EPWM_TBCNT_TBCNT_SHIFT                                             (0x0000U)
#define CSL_EPWM_TBCNT_TBCNT_RESETVAL                                          (0x0000U)
#define CSL_EPWM_TBCNT_TBCNT_MAX                                               (0xFFFFU)

#define CSL_EPWM_TBCNT_RESETVAL                                                (0x0000U)

/* TBPRD */

#define CSL_EPWM_TBPRD_TBPRD_MASK                                              (0xFFFFU)
#define CSL_EPWM_TBPRD_TBPRD_SHIFT                                             (0x0000U)
#define CSL_EPWM_TBPRD_TBPRD_RESETVAL                                          (0x0000U)
#define CSL_EPWM_TBPRD_TBPRD_MAX                                               (0xFFFFU)

#define CSL_EPWM_TBPRD_RESETVAL                                                (0x0000U)

/* CMPCTL */

#define CSL_EPWM_CMPCTL_LOADAMODE_MASK                                         (0x0003U)
#define CSL_EPWM_CMPCTL_LOADAMODE_SHIFT                                        (0x0000U)
#define CSL_EPWM_CMPCTL_LOADAMODE_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPCTL_LOADAMODE_MAX                                          (0x0003U)

#define CSL_EPWM_CMPCTL_LOADBMODE_MASK                                         (0x000CU)
#define CSL_EPWM_CMPCTL_LOADBMODE_SHIFT                                        (0x0002U)
#define CSL_EPWM_CMPCTL_LOADBMODE_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPCTL_LOADBMODE_MAX                                          (0x0003U)

#define CSL_EPWM_CMPCTL_SHDWAMODE_MASK                                         (0x0010U)
#define CSL_EPWM_CMPCTL_SHDWAMODE_SHIFT                                        (0x0004U)
#define CSL_EPWM_CMPCTL_SHDWAMODE_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPCTL_SHDWAMODE_MAX                                          (0x0001U)

#define CSL_EPWM_CMPCTL_RESERVED3_MASK                                         (0x0020U)
#define CSL_EPWM_CMPCTL_RESERVED3_SHIFT                                        (0x0005U)
#define CSL_EPWM_CMPCTL_RESERVED3_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPCTL_RESERVED3_MAX                                          (0x0001U)

#define CSL_EPWM_CMPCTL_SHDWBMODE_MASK                                         (0x0040U)
#define CSL_EPWM_CMPCTL_SHDWBMODE_SHIFT                                        (0x0006U)
#define CSL_EPWM_CMPCTL_SHDWBMODE_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPCTL_SHDWBMODE_MAX                                          (0x0001U)

#define CSL_EPWM_CMPCTL_RESERVED2_MASK                                         (0x0080U)
#define CSL_EPWM_CMPCTL_RESERVED2_SHIFT                                        (0x0007U)
#define CSL_EPWM_CMPCTL_RESERVED2_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPCTL_RESERVED2_MAX                                          (0x0001U)

#define CSL_EPWM_CMPCTL_SHDWAFULL_MASK                                         (0x0100U)
#define CSL_EPWM_CMPCTL_SHDWAFULL_SHIFT                                        (0x0008U)
#define CSL_EPWM_CMPCTL_SHDWAFULL_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPCTL_SHDWAFULL_MAX                                          (0x0001U)

#define CSL_EPWM_CMPCTL_SHDWBFULL_MASK                                         (0x0200U)
#define CSL_EPWM_CMPCTL_SHDWBFULL_SHIFT                                        (0x0009U)
#define CSL_EPWM_CMPCTL_SHDWBFULL_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPCTL_SHDWBFULL_MAX                                          (0x0001U)

#define CSL_EPWM_CMPCTL_RESERVED1_MASK                                         (0xFC00U)
#define CSL_EPWM_CMPCTL_RESERVED1_SHIFT                                        (0x000AU)
#define CSL_EPWM_CMPCTL_RESERVED1_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPCTL_RESERVED1_MAX                                          (0x003FU)

#define CSL_EPWM_CMPCTL_RESETVAL                                               (0x0000U)

/* CMPAHR */

#define CSL_EPWM_CMPAHR_RESERVED1_MASK                                         (0x00FFU)
#define CSL_EPWM_CMPAHR_RESERVED1_SHIFT                                        (0x0000U)
#define CSL_EPWM_CMPAHR_RESERVED1_RESETVAL                                     (0x0000U)
#define CSL_EPWM_CMPAHR_RESERVED1_MAX                                          (0x00FFU)

#define CSL_EPWM_CMPAHR_CMPAHR_MASK                                            (0xFF00U)
#define CSL_EPWM_CMPAHR_CMPAHR_SHIFT                                           (0x0008U)
#define CSL_EPWM_CMPAHR_CMPAHR_RESETVAL                                        (0x0000U)
#define CSL_EPWM_CMPAHR_CMPAHR_MAX                                             (0x00FFU)

#define CSL_EPWM_CMPAHR_RESETVAL                                               (0x0000U)

/* CMPA */

#define CSL_EPWM_CMPA_CMPA_MASK                                                (0xFFFFU)
#define CSL_EPWM_CMPA_CMPA_SHIFT                                               (0x0000U)
#define CSL_EPWM_CMPA_CMPA_RESETVAL                                            (0x0000U)
#define CSL_EPWM_CMPA_CMPA_MAX                                                 (0xFFFFU)

#define CSL_EPWM_CMPA_RESETVAL                                                 (0x0000U)

/* CMPB */

#define CSL_EPWM_CMPB_CMPB_MASK                                                (0xFFFFU)
#define CSL_EPWM_CMPB_CMPB_SHIFT                                               (0x0000U)
#define CSL_EPWM_CMPB_CMPB_RESETVAL                                            (0x0000U)
#define CSL_EPWM_CMPB_CMPB_MAX                                                 (0xFFFFU)

#define CSL_EPWM_CMPB_RESETVAL                                                 (0x0000U)

/* AQCTLA */

#define CSL_EPWM_AQCTLA_ZRO_MASK                                               (0x0003U)
#define CSL_EPWM_AQCTLA_ZRO_SHIFT                                              (0x0000U)
#define CSL_EPWM_AQCTLA_ZRO_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLA_ZRO_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLA_PRD_MASK                                               (0x000CU)
#define CSL_EPWM_AQCTLA_PRD_SHIFT                                              (0x0002U)
#define CSL_EPWM_AQCTLA_PRD_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLA_PRD_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLA_CAU_MASK                                               (0x0030U)
#define CSL_EPWM_AQCTLA_CAU_SHIFT                                              (0x0004U)
#define CSL_EPWM_AQCTLA_CAU_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLA_CAU_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLA_CAD_MASK                                               (0x00C0U)
#define CSL_EPWM_AQCTLA_CAD_SHIFT                                              (0x0006U)
#define CSL_EPWM_AQCTLA_CAD_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLA_CAD_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLA_CBU_MASK                                               (0x0300U)
#define CSL_EPWM_AQCTLA_CBU_SHIFT                                              (0x0008U)
#define CSL_EPWM_AQCTLA_CBU_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLA_CBU_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLA_CBD_MASK                                               (0x0C00U)
#define CSL_EPWM_AQCTLA_CBD_SHIFT                                              (0x000AU)
#define CSL_EPWM_AQCTLA_CBD_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLA_CBD_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLA_RESERVED1_MASK                                         (0xF000U)
#define CSL_EPWM_AQCTLA_RESERVED1_SHIFT                                        (0x000CU)
#define CSL_EPWM_AQCTLA_RESERVED1_RESETVAL                                     (0x0000U)
#define CSL_EPWM_AQCTLA_RESERVED1_MAX                                          (0x000FU)

#define CSL_EPWM_AQCTLA_RESETVAL                                               (0x0000U)

/* AQCTLB */

#define CSL_EPWM_AQCTLB_ZRO_MASK                                               (0x0003U)
#define CSL_EPWM_AQCTLB_ZRO_SHIFT                                              (0x0000U)
#define CSL_EPWM_AQCTLB_ZRO_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLB_ZRO_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLB_PRD_MASK                                               (0x000CU)
#define CSL_EPWM_AQCTLB_PRD_SHIFT                                              (0x0002U)
#define CSL_EPWM_AQCTLB_PRD_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLB_PRD_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLB_CAU_MASK                                               (0x0030U)
#define CSL_EPWM_AQCTLB_CAU_SHIFT                                              (0x0004U)
#define CSL_EPWM_AQCTLB_CAU_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLB_CAU_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLB_CAD_MASK                                               (0x00C0U)
#define CSL_EPWM_AQCTLB_CAD_SHIFT                                              (0x0006U)
#define CSL_EPWM_AQCTLB_CAD_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLB_CAD_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLB_CBU_MASK                                               (0x0300U)
#define CSL_EPWM_AQCTLB_CBU_SHIFT                                              (0x0008U)
#define CSL_EPWM_AQCTLB_CBU_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLB_CBU_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLB_CBD_MASK                                               (0x0C00U)
#define CSL_EPWM_AQCTLB_CBD_SHIFT                                              (0x000AU)
#define CSL_EPWM_AQCTLB_CBD_RESETVAL                                           (0x0000U)
#define CSL_EPWM_AQCTLB_CBD_MAX                                                (0x0003U)

#define CSL_EPWM_AQCTLB_RESERVED1_MASK                                         (0xF000U)
#define CSL_EPWM_AQCTLB_RESERVED1_SHIFT                                        (0x000CU)
#define CSL_EPWM_AQCTLB_RESERVED1_RESETVAL                                     (0x0000U)
#define CSL_EPWM_AQCTLB_RESERVED1_MAX                                          (0x000FU)

#define CSL_EPWM_AQCTLB_RESETVAL                                               (0x0000U)

/* AQSFRC */

#define CSL_EPWM_AQSFRC_ACTSFA_MASK                                            (0x0003U)
#define CSL_EPWM_AQSFRC_ACTSFA_SHIFT                                           (0x0000U)
#define CSL_EPWM_AQSFRC_ACTSFA_RESETVAL                                        (0x0000U)
#define CSL_EPWM_AQSFRC_ACTSFA_MAX                                             (0x0003U)

#define CSL_EPWM_AQSFRC_OTSFA_MASK                                             (0x0004U)
#define CSL_EPWM_AQSFRC_OTSFA_SHIFT                                            (0x0002U)
#define CSL_EPWM_AQSFRC_OTSFA_RESETVAL                                         (0x0000U)
#define CSL_EPWM_AQSFRC_OTSFA_MAX                                              (0x0001U)

#define CSL_EPWM_AQSFRC_ACTSFB_MASK                                            (0x0018U)
#define CSL_EPWM_AQSFRC_ACTSFB_SHIFT                                           (0x0003U)
#define CSL_EPWM_AQSFRC_ACTSFB_RESETVAL                                        (0x0000U)
#define CSL_EPWM_AQSFRC_ACTSFB_MAX                                             (0x0003U)

#define CSL_EPWM_AQSFRC_OTSFB_MASK                                             (0x0020U)
#define CSL_EPWM_AQSFRC_OTSFB_SHIFT                                            (0x0005U)
#define CSL_EPWM_AQSFRC_OTSFB_RESETVAL                                         (0x0000U)
#define CSL_EPWM_AQSFRC_OTSFB_MAX                                              (0x0001U)

#define CSL_EPWM_AQSFRC_RLDCSF_MASK                                            (0x00C0U)
#define CSL_EPWM_AQSFRC_RLDCSF_SHIFT                                           (0x0006U)
#define CSL_EPWM_AQSFRC_RLDCSF_RESETVAL                                        (0x0000U)
#define CSL_EPWM_AQSFRC_RLDCSF_MAX                                             (0x0003U)

#define CSL_EPWM_AQSFRC_RESERVED1_MASK                                         (0xFF00U)
#define CSL_EPWM_AQSFRC_RESERVED1_SHIFT                                        (0x0008U)
#define CSL_EPWM_AQSFRC_RESERVED1_RESETVAL                                     (0x0000U)
#define CSL_EPWM_AQSFRC_RESERVED1_MAX                                          (0x00FFU)

#define CSL_EPWM_AQSFRC_RESETVAL                                               (0x0000U)

/* AQCSFRC */

#define CSL_EPWM_AQCSFRC_CSFA_MASK                                             (0x0003U)
#define CSL_EPWM_AQCSFRC_CSFA_SHIFT                                            (0x0000U)
#define CSL_EPWM_AQCSFRC_CSFA_RESETVAL                                         (0x0000U)
#define CSL_EPWM_AQCSFRC_CSFA_MAX                                              (0x0003U)

#define CSL_EPWM_AQCSFRC_CSFB_MASK                                             (0x000CU)
#define CSL_EPWM_AQCSFRC_CSFB_SHIFT                                            (0x0002U)
#define CSL_EPWM_AQCSFRC_CSFB_RESETVAL                                         (0x0000U)
#define CSL_EPWM_AQCSFRC_CSFB_MAX                                              (0x0003U)

#define CSL_EPWM_AQCSFRC_RESERVED1_MASK                                        (0xFFF0U)
#define CSL_EPWM_AQCSFRC_RESERVED1_SHIFT                                       (0x0004U)
#define CSL_EPWM_AQCSFRC_RESERVED1_RESETVAL                                    (0x0000U)
#define CSL_EPWM_AQCSFRC_RESERVED1_MAX                                         (0x0FFFU)

#define CSL_EPWM_AQCSFRC_RESETVAL                                              (0x0000U)

/* DBCTL */

#define CSL_EPWM_DBCTL_OUT_MODE_MASK                                           (0x0003U)
#define CSL_EPWM_DBCTL_OUT_MODE_SHIFT                                          (0x0000U)
#define CSL_EPWM_DBCTL_OUT_MODE_RESETVAL                                       (0x0000U)
#define CSL_EPWM_DBCTL_OUT_MODE_MAX                                            (0x0003U)

#define CSL_EPWM_DBCTL_POLSEL_MASK                                             (0x000CU)
#define CSL_EPWM_DBCTL_POLSEL_SHIFT                                            (0x0002U)
#define CSL_EPWM_DBCTL_POLSEL_RESETVAL                                         (0x0000U)
#define CSL_EPWM_DBCTL_POLSEL_MAX                                              (0x0003U)

#define CSL_EPWM_DBCTL_IN_MODE_MASK                                            (0x0030U)
#define CSL_EPWM_DBCTL_IN_MODE_SHIFT                                           (0x0004U)
#define CSL_EPWM_DBCTL_IN_MODE_RESETVAL                                        (0x0000U)
#define CSL_EPWM_DBCTL_IN_MODE_MAX                                             (0x0003U)

#define CSL_EPWM_DBCTL_RESERVED1_MASK                                          (0xFFC0U)
#define CSL_EPWM_DBCTL_RESERVED1_SHIFT                                         (0x0006U)
#define CSL_EPWM_DBCTL_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_DBCTL_RESERVED1_MAX                                           (0x03FFU)

#define CSL_EPWM_DBCTL_RESETVAL                                                (0x0000U)

/* DBRED */

#define CSL_EPWM_DBRED_DEL_MASK                                                (0x03FFU)
#define CSL_EPWM_DBRED_DEL_SHIFT                                               (0x0000U)
#define CSL_EPWM_DBRED_DEL_RESETVAL                                            (0x0000U)
#define CSL_EPWM_DBRED_DEL_MAX                                                 (0x03FFU)

#define CSL_EPWM_DBRED_RESERVED1_MASK                                          (0xFC00U)
#define CSL_EPWM_DBRED_RESERVED1_SHIFT                                         (0x000AU)
#define CSL_EPWM_DBRED_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_DBRED_RESERVED1_MAX                                           (0x003FU)

#define CSL_EPWM_DBRED_RESETVAL                                                (0x0000U)

/* DBFED */

#define CSL_EPWM_DBFED_DEL_MASK                                                (0x03FFU)
#define CSL_EPWM_DBFED_DEL_SHIFT                                               (0x0000U)
#define CSL_EPWM_DBFED_DEL_RESETVAL                                            (0x0000U)
#define CSL_EPWM_DBFED_DEL_MAX                                                 (0x03FFU)

#define CSL_EPWM_DBFED_RESERVED1_MASK                                          (0xFC00U)
#define CSL_EPWM_DBFED_RESERVED1_SHIFT                                         (0x000AU)
#define CSL_EPWM_DBFED_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_DBFED_RESERVED1_MAX                                           (0x003FU)

#define CSL_EPWM_DBFED_RESETVAL                                                (0x0000U)

/* TZSEL */

#define CSL_EPWM_TZSEL_CBCN_MASK                                               (0x00FFU)
#define CSL_EPWM_TZSEL_CBCN_SHIFT                                              (0x0000U)
#define CSL_EPWM_TZSEL_CBCN_RESETVAL                                           (0x0000U)
#define CSL_EPWM_TZSEL_CBCN_MAX                                                (0x00FFU)

#define CSL_EPWM_TZSEL_OSHTN_MASK                                              (0xFF00U)
#define CSL_EPWM_TZSEL_OSHTN_SHIFT                                             (0x0008U)
#define CSL_EPWM_TZSEL_OSHTN_RESETVAL                                          (0x0000U)
#define CSL_EPWM_TZSEL_OSHTN_MAX                                               (0x00FFU)

#define CSL_EPWM_TZSEL_RESETVAL                                                (0x0000U)

/* TZCTL */

#define CSL_EPWM_TZCTL_TZA_MASK                                                (0x0003U)
#define CSL_EPWM_TZCTL_TZA_SHIFT                                               (0x0000U)
#define CSL_EPWM_TZCTL_TZA_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZCTL_TZA_MAX                                                 (0x0003U)

#define CSL_EPWM_TZCTL_TZB_MASK                                                (0x000CU)
#define CSL_EPWM_TZCTL_TZB_SHIFT                                               (0x0002U)
#define CSL_EPWM_TZCTL_TZB_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZCTL_TZB_MAX                                                 (0x0003U)

#define CSL_EPWM_TZCTL_RESERVED1_MASK                                          (0xFFF0U)
#define CSL_EPWM_TZCTL_RESERVED1_SHIFT                                         (0x0004U)
#define CSL_EPWM_TZCTL_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_TZCTL_RESERVED1_MAX                                           (0x0FFFU)

#define CSL_EPWM_TZCTL_RESETVAL                                                (0x0000U)

/* TZEINT */

#define CSL_EPWM_TZEINT_RESERVED2_MASK                                         (0x0001U)
#define CSL_EPWM_TZEINT_RESERVED2_SHIFT                                        (0x0000U)
#define CSL_EPWM_TZEINT_RESERVED2_RESETVAL                                     (0x0000U)
#define CSL_EPWM_TZEINT_RESERVED2_MAX                                          (0x0001U)

#define CSL_EPWM_TZEINT_CBC_MASK                                               (0x0002U)
#define CSL_EPWM_TZEINT_CBC_SHIFT                                              (0x0001U)
#define CSL_EPWM_TZEINT_CBC_RESETVAL                                           (0x0000U)
#define CSL_EPWM_TZEINT_CBC_MAX                                                (0x0001U)

#define CSL_EPWM_TZEINT_OST_MASK                                               (0x0004U)
#define CSL_EPWM_TZEINT_OST_SHIFT                                              (0x0002U)
#define CSL_EPWM_TZEINT_OST_RESETVAL                                           (0x0000U)
#define CSL_EPWM_TZEINT_OST_MAX                                                (0x0001U)

#define CSL_EPWM_TZEINT_RESERVED1_MASK                                         (0xFFF8U)
#define CSL_EPWM_TZEINT_RESERVED1_SHIFT                                        (0x0003U)
#define CSL_EPWM_TZEINT_RESERVED1_RESETVAL                                     (0x0000U)
#define CSL_EPWM_TZEINT_RESERVED1_MAX                                          (0x1FFFU)

#define CSL_EPWM_TZEINT_RESETVAL                                               (0x0000U)

/* TZFLG */

#define CSL_EPWM_TZFLG_INT_MASK                                                (0x0001U)
#define CSL_EPWM_TZFLG_INT_SHIFT                                               (0x0000U)
#define CSL_EPWM_TZFLG_INT_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZFLG_INT_MAX                                                 (0x0001U)

#define CSL_EPWM_TZFLG_CBC_MASK                                                (0x0002U)
#define CSL_EPWM_TZFLG_CBC_SHIFT                                               (0x0001U)
#define CSL_EPWM_TZFLG_CBC_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZFLG_CBC_MAX                                                 (0x0001U)

#define CSL_EPWM_TZFLG_OST_MASK                                                (0x0004U)
#define CSL_EPWM_TZFLG_OST_SHIFT                                               (0x0002U)
#define CSL_EPWM_TZFLG_OST_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZFLG_OST_MAX                                                 (0x0001U)

#define CSL_EPWM_TZFLG_RESERVED1_MASK                                          (0xFFF8U)
#define CSL_EPWM_TZFLG_RESERVED1_SHIFT                                         (0x0003U)
#define CSL_EPWM_TZFLG_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_TZFLG_RESERVED1_MAX                                           (0x1FFFU)

#define CSL_EPWM_TZFLG_RESETVAL                                                (0x0000U)

/* TZCLR */

#define CSL_EPWM_TZCLR_INT_MASK                                                (0x0001U)
#define CSL_EPWM_TZCLR_INT_SHIFT                                               (0x0000U)
#define CSL_EPWM_TZCLR_INT_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZCLR_INT_MAX                                                 (0x0001U)

#define CSL_EPWM_TZCLR_CBC_MASK                                                (0x0002U)
#define CSL_EPWM_TZCLR_CBC_SHIFT                                               (0x0001U)
#define CSL_EPWM_TZCLR_CBC_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZCLR_CBC_MAX                                                 (0x0001U)

#define CSL_EPWM_TZCLR_OST_MASK                                                (0x0004U)
#define CSL_EPWM_TZCLR_OST_SHIFT                                               (0x0002U)
#define CSL_EPWM_TZCLR_OST_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZCLR_OST_MAX                                                 (0x0001U)

#define CSL_EPWM_TZCLR_RESERVED1_MASK                                          (0xFFF8U)
#define CSL_EPWM_TZCLR_RESERVED1_SHIFT                                         (0x0003U)
#define CSL_EPWM_TZCLR_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_TZCLR_RESERVED1_MAX                                           (0x1FFFU)

#define CSL_EPWM_TZCLR_RESETVAL                                                (0x0000U)

/* TZFRC */

#define CSL_EPWM_TZFRC_RESERVED2_MASK                                          (0x0001U)
#define CSL_EPWM_TZFRC_RESERVED2_SHIFT                                         (0x0000U)
#define CSL_EPWM_TZFRC_RESERVED2_RESETVAL                                      (0x0000U)
#define CSL_EPWM_TZFRC_RESERVED2_MAX                                           (0x0001U)

#define CSL_EPWM_TZFRC_CBC_MASK                                                (0x0002U)
#define CSL_EPWM_TZFRC_CBC_SHIFT                                               (0x0001U)
#define CSL_EPWM_TZFRC_CBC_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZFRC_CBC_MAX                                                 (0x0001U)

#define CSL_EPWM_TZFRC_OST_MASK                                                (0x0004U)
#define CSL_EPWM_TZFRC_OST_SHIFT                                               (0x0002U)
#define CSL_EPWM_TZFRC_OST_RESETVAL                                            (0x0000U)
#define CSL_EPWM_TZFRC_OST_MAX                                                 (0x0001U)

#define CSL_EPWM_TZFRC_RESERVED1_MASK                                          (0xFFF8U)
#define CSL_EPWM_TZFRC_RESERVED1_SHIFT                                         (0x0003U)
#define CSL_EPWM_TZFRC_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_TZFRC_RESERVED1_MAX                                           (0x1FFFU)

#define CSL_EPWM_TZFRC_RESETVAL                                                (0x0000U)

/* ETSEL */

#define CSL_EPWM_ETSEL_INTSEL_MASK                                             (0x0007U)
#define CSL_EPWM_ETSEL_INTSEL_SHIFT                                            (0x0000U)
#define CSL_EPWM_ETSEL_INTSEL_RESETVAL                                         (0x0000U)
#define CSL_EPWM_ETSEL_INTSEL_MAX                                              (0x0007U)

#define CSL_EPWM_ETSEL_INTEN_MASK                                              (0x0008U)
#define CSL_EPWM_ETSEL_INTEN_SHIFT                                             (0x0003U)
#define CSL_EPWM_ETSEL_INTEN_RESETVAL                                          (0x0000U)
#define CSL_EPWM_ETSEL_INTEN_MAX                                               (0x0001U)

#define CSL_EPWM_ETSEL_RESERVED1_MASK                                          (0xFFF0U)
#define CSL_EPWM_ETSEL_RESERVED1_SHIFT                                         (0x0004U)
#define CSL_EPWM_ETSEL_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_ETSEL_RESERVED1_MAX                                           (0x0FFFU)

#define CSL_EPWM_ETSEL_RESETVAL                                                (0x0000U)

/* ETPS */

#define CSL_EPWM_ETPS_INTPRD_MASK                                              (0x0003U)
#define CSL_EPWM_ETPS_INTPRD_SHIFT                                             (0x0000U)
#define CSL_EPWM_ETPS_INTPRD_RESETVAL                                          (0x0000U)
#define CSL_EPWM_ETPS_INTPRD_MAX                                               (0x0003U)

#define CSL_EPWM_ETPS_INTCNT_MASK                                              (0x000CU)
#define CSL_EPWM_ETPS_INTCNT_SHIFT                                             (0x0002U)
#define CSL_EPWM_ETPS_INTCNT_RESETVAL                                          (0x0000U)
#define CSL_EPWM_ETPS_INTCNT_MAX                                               (0x0003U)

#define CSL_EPWM_ETPS_RESERVED1_MASK                                           (0xFFF0U)
#define CSL_EPWM_ETPS_RESERVED1_SHIFT                                          (0x0004U)
#define CSL_EPWM_ETPS_RESERVED1_RESETVAL                                       (0x0000U)
#define CSL_EPWM_ETPS_RESERVED1_MAX                                            (0x0FFFU)

#define CSL_EPWM_ETPS_RESETVAL                                                 (0x0000U)

/* ETFLG */

#define CSL_EPWM_ETFLG_INT_MASK                                                (0x0001U)
#define CSL_EPWM_ETFLG_INT_SHIFT                                               (0x0000U)
#define CSL_EPWM_ETFLG_INT_RESETVAL                                            (0x0000U)
#define CSL_EPWM_ETFLG_INT_MAX                                                 (0x0001U)

#define CSL_EPWM_ETFLG_RESERVED1_MASK                                          (0xFFFEU)
#define CSL_EPWM_ETFLG_RESERVED1_SHIFT                                         (0x0001U)
#define CSL_EPWM_ETFLG_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_ETFLG_RESERVED1_MAX                                           (0x7FFFU)

#define CSL_EPWM_ETFLG_RESETVAL                                                (0x0000U)

/* ETCLR */

#define CSL_EPWM_ETCLR_INT_MASK                                                (0x0001U)
#define CSL_EPWM_ETCLR_INT_SHIFT                                               (0x0000U)
#define CSL_EPWM_ETCLR_INT_RESETVAL                                            (0x0000U)
#define CSL_EPWM_ETCLR_INT_MAX                                                 (0x0001U)

#define CSL_EPWM_ETCLR_RESERVED1_MASK                                          (0xFFFEU)
#define CSL_EPWM_ETCLR_RESERVED1_SHIFT                                         (0x0001U)
#define CSL_EPWM_ETCLR_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_ETCLR_RESERVED1_MAX                                           (0x7FFFU)

#define CSL_EPWM_ETCLR_RESETVAL                                                (0x0000U)

/* ETFRC */

#define CSL_EPWM_ETFRC_INT_MASK                                                (0x0001U)
#define CSL_EPWM_ETFRC_INT_SHIFT                                               (0x0000U)
#define CSL_EPWM_ETFRC_INT_RESETVAL                                            (0x0000U)
#define CSL_EPWM_ETFRC_INT_MAX                                                 (0x0001U)

#define CSL_EPWM_ETFRC_RESERVED1_MASK                                          (0xFFFEU)
#define CSL_EPWM_ETFRC_RESERVED1_SHIFT                                         (0x0001U)
#define CSL_EPWM_ETFRC_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_ETFRC_RESERVED1_MAX                                           (0x7FFFU)

#define CSL_EPWM_ETFRC_RESETVAL                                                (0x0000U)

/* PCCTL */

#define CSL_EPWM_PCCTL_CHPEN_MASK                                              (0x0001U)
#define CSL_EPWM_PCCTL_CHPEN_SHIFT                                             (0x0000U)
#define CSL_EPWM_PCCTL_CHPEN_RESETVAL                                          (0x0000U)
#define CSL_EPWM_PCCTL_CHPEN_MAX                                               (0x0001U)

#define CSL_EPWM_PCCTL_OSHTWTH_MASK                                            (0x001EU)
#define CSL_EPWM_PCCTL_OSHTWTH_SHIFT                                           (0x0001U)
#define CSL_EPWM_PCCTL_OSHTWTH_RESETVAL                                        (0x0000U)
#define CSL_EPWM_PCCTL_OSHTWTH_MAX                                             (0x000FU)

#define CSL_EPWM_PCCTL_CHPFREQ_MASK                                            (0x00E0U)
#define CSL_EPWM_PCCTL_CHPFREQ_SHIFT                                           (0x0005U)
#define CSL_EPWM_PCCTL_CHPFREQ_RESETVAL                                        (0x0000U)
#define CSL_EPWM_PCCTL_CHPFREQ_MAX                                             (0x0007U)

#define CSL_EPWM_PCCTL_CHPDUTY_MASK                                            (0x0700U)
#define CSL_EPWM_PCCTL_CHPDUTY_SHIFT                                           (0x0008U)
#define CSL_EPWM_PCCTL_CHPDUTY_RESETVAL                                        (0x0000U)
#define CSL_EPWM_PCCTL_CHPDUTY_MAX                                             (0x0007U)

#define CSL_EPWM_PCCTL_RESERVED1_MASK                                          (0xF800U)
#define CSL_EPWM_PCCTL_RESERVED1_SHIFT                                         (0x000BU)
#define CSL_EPWM_PCCTL_RESERVED1_RESETVAL                                      (0x0000U)
#define CSL_EPWM_PCCTL_RESERVED1_MAX                                           (0x001FU)

#define CSL_EPWM_PCCTL_RESETVAL                                                (0x0000U)

/* PID */

#define CSL_EPWM_PID_Y_MINOR_MASK                                              (0x0000003FU)
#define CSL_EPWM_PID_Y_MINOR_SHIFT                                             (0x00000000U)
#define CSL_EPWM_PID_Y_MINOR_RESETVAL                                          (0x00000003U)
#define CSL_EPWM_PID_Y_MINOR_MAX                                               (0x0000003FU)

#define CSL_EPWM_PID_CUSTOM_MASK                                               (0x000000C0U)
#define CSL_EPWM_PID_CUSTOM_SHIFT                                              (0x00000006U)
#define CSL_EPWM_PID_CUSTOM_RESETVAL                                           (0x00000000U)
#define CSL_EPWM_PID_CUSTOM_MAX                                                (0x00000003U)

#define CSL_EPWM_PID_X_MAJOR_MASK                                              (0x00000700U)
#define CSL_EPWM_PID_X_MAJOR_SHIFT                                             (0x00000008U)
#define CSL_EPWM_PID_X_MAJOR_RESETVAL                                          (0x00000001U)
#define CSL_EPWM_PID_X_MAJOR_MAX                                               (0x00000007U)

#define CSL_EPWM_PID_R_RTL_MASK                                                (0x0000F800U)
#define CSL_EPWM_PID_R_RTL_SHIFT                                               (0x0000000BU)
#define CSL_EPWM_PID_R_RTL_RESETVAL                                            (0x00000001U)
#define CSL_EPWM_PID_R_RTL_MAX                                                 (0x0000001FU)

#define CSL_EPWM_PID_FUNC_MASK                                                 (0x0FFF0000U)
#define CSL_EPWM_PID_FUNC_SHIFT                                                (0x00000010U)
#define CSL_EPWM_PID_FUNC_RESETVAL                                             (0x000004D1U)
#define CSL_EPWM_PID_FUNC_MAX                                                  (0x00000FFFU)

#define CSL_EPWM_PID_RESERVED1_MASK                                            (0x30000000U)
#define CSL_EPWM_PID_RESERVED1_SHIFT                                           (0x0000001CU)
#define CSL_EPWM_PID_RESERVED1_RESETVAL                                        (0x00000000U)
#define CSL_EPWM_PID_RESERVED1_MAX                                             (0x00000003U)

#define CSL_EPWM_PID_SCHEME_MASK                                               (0xC0000000U)
#define CSL_EPWM_PID_SCHEME_SHIFT                                              (0x0000001EU)
#define CSL_EPWM_PID_SCHEME_RESETVAL                                           (0x00000001U)
#define CSL_EPWM_PID_SCHEME_MAX                                                (0x00000003U)

#define CSL_EPWM_PID_RESETVAL                                                  (0x44D10903U)

#ifdef __cplusplus
}
#endif
#endif
