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
#ifndef CSLR_TMR_H
#define CSLR_TMR_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for registers
**************************************************************************/
typedef struct {
    volatile Uint32 PID12;
    volatile Uint32 EMUMGT_CLKSPD;
    volatile Uint32 GPINT_EN;
    volatile Uint32 GPDIR_DAT;
    volatile Uint32 CNTLO;
    volatile Uint32 CNTHI;
    volatile Uint32 PRDLO;
    volatile Uint32 PRDHI;
    volatile Uint32 TCR;
    volatile Uint32 TGCR;
    volatile Uint32 WDTCR;
    volatile Uint32 TLGC;
    volatile Uint32 TLMR;
    volatile Uint32 RELLO;
    volatile Uint32 RELHI;
    volatile Uint32 CAPLO;
    volatile Uint32 CAPHI;
    volatile Uint32 INTCTL_STAT;
    volatile Uint8  RSVD0[24];
    volatile Uint32 TIMERLO_COMPARE_REG[8];
    volatile Uint8  RSVD1[4];
} CSL_TmrRegs;

#ifndef CSL_MODIFICATION   

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_TmrRegs             *CSL_TmrRegsOvly;
#endif


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_TMR_PID12                                           (0x0U)

/* Emulation Management/Clock Speed Register */
#define CSL_TMR_EMUMGT_CLKSPD                                   (0x4U)

/* GPIO Interrupt Control/Enable Register */
#define CSL_TMR_GPINT_EN                                        (0x8U)

/* GPIO Direction/Data Register */
#define CSL_TMR_GPDIR_DAT                                       (0xCU)

/* Timer Counter Register 12 */
#define CSL_TMR_CNTLO                                           (0x10U)

/* Timer Counter Register 34 */
#define CSL_TMR_CNTHI                                           (0x14U)

/* Timer Period Register 12 */
#define CSL_TMR_PRDLO                                           (0x18U)

/* Timer Period Register 34 */
#define CSL_TMR_PRDHI                                           (0x1CU)

/* Timer Control Register */
#define CSL_TMR_TCR                                             (0x20U)

/* Timer Global Control Register */
#define CSL_TMR_TGCR                                            (0x24U)

/* Watchdog Timer Control Register */
#define CSL_TMR_WDTCR                                           (0x28U)

/* Test Logic Global Control Register */
#define CSL_TMR_TLGC                                            (0x2CU)

/* Test Logic MISR Result Signature Register */
#define CSL_TMR_TLMR                                            (0x30U)

/* Timer Reload Register 12 */
#define CSL_TMR_RELLO                                           (0x34U)

/* Timer Reload Register 34 */
#define CSL_TMR_RELHI                                           (0x38U)

/* Timer capture (shadow) register 12 */
#define CSL_TMR_CAPLO                                           (0x3CU)

/* Timer capture (shadow) register 34 */
#define CSL_TMR_CAPHI                                           (0x40U)
#define CSL_TMR_INTCTL_STAT                                     (0x44U)

/* Timer 12 Compare Registers */
#define CSL_TMR_TIMERLO_COMPARE_REG(i)                          (0x60U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PID12 */

#define CSL_TMR_PID12_SCHEME_MASK                               (0xC0000000U)
#define CSL_TMR_PID12_SCHEME_SHIFT                              (30U)
#define CSL_TMR_PID12_SCHEME_RESETVAL                           (0x00000000U)
#define CSL_TMR_PID12_SCHEME_MAX                                (0x00000003U)

#define CSL_TMR_PID12_MINOR_MASK                                (0x0000003FU)
#define CSL_TMR_PID12_MINOR_SHIFT                               (0U)
#define CSL_TMR_PID12_MINOR_RESETVAL                            (0x00000000U)
#define CSL_TMR_PID12_MINOR_MAX                                 (0x0000003fU)

#define CSL_TMR_PID12_CUSTOM_MASK                               (0x000000C0U)
#define CSL_TMR_PID12_CUSTOM_SHIFT                              (6U)
#define CSL_TMR_PID12_CUSTOM_RESETVAL                           (0x00000000U)
#define CSL_TMR_PID12_CUSTOM_MAX                                (0x00000003U)

#define CSL_TMR_PID12_MAJOR_MASK                                (0x00000700U)
#define CSL_TMR_PID12_MAJOR_SHIFT                               (8U)
#define CSL_TMR_PID12_MAJOR_RESETVAL                            (0x00000000U)
#define CSL_TMR_PID12_MAJOR_MAX                                 (0x00000007U)

#define CSL_TMR_PID12_RTL_MASK                                  (0x0000F800U)
#define CSL_TMR_PID12_RTL_SHIFT                                 (11U)
#define CSL_TMR_PID12_RTL_RESETVAL                              (0x00000000U)
#define CSL_TMR_PID12_RTL_MAX                                   (0x0000001fU)

#define CSL_TMR_PID12_FUNC_MASK                                 (0x0FFF0000U)
#define CSL_TMR_PID12_FUNC_SHIFT                                (16U)
#define CSL_TMR_PID12_FUNC_RESETVAL                             (0x00000000U)
#define CSL_TMR_PID12_FUNC_MAX                                  (0x00000fffU)

#define CSL_TMR_PID12_RESETVAL                                  (0x00000000U)

/* EMUMGT_CLKSPD */

#define CSL_TMR_EMUMGT_CLKSPD_CLKDIV_MASK                       (0x000F0000U)
#define CSL_TMR_EMUMGT_CLKSPD_CLKDIV_SHIFT                      (16U)
#define CSL_TMR_EMUMGT_CLKSPD_CLKDIV_RESETVAL                   (0x00000000U)
#define CSL_TMR_EMUMGT_CLKSPD_CLKDIV_DIV0                       (0x00000000U)
#define CSL_TMR_EMUMGT_CLKSPD_CLKDIV_DIV1                       (0x00000001U)
#define CSL_TMR_EMUMGT_CLKSPD_CLKDIV_DIV2                       (0x00000002U)
#define CSL_TMR_EMUMGT_CLKSPD_CLKDIV_DIV4                       (0x00000004U)
#define CSL_TMR_EMUMGT_CLKSPD_CLKDIV_DIV8                       (0x00000008U)
#define CSL_TMR_EMUMGT_CLKSPD_CLKDIV_MAX                        (0x0000000fU)

#define CSL_TMR_EMUMGT_CLKSPD_FREE_MASK                         (0x00000001U)
#define CSL_TMR_EMUMGT_CLKSPD_FREE_SHIFT                        (0U)
#define CSL_TMR_EMUMGT_CLKSPD_FREE_RESETVAL                     (0x00000000U)
#define CSL_TMR_EMUMGT_CLKSPD_FREE_MAX                          (0x00000001U)

#define CSL_TMR_EMUMGT_CLKSPD_SOFT_MASK                         (0x00000002U)
#define CSL_TMR_EMUMGT_CLKSPD_SOFT_SHIFT                        (1U)
#define CSL_TMR_EMUMGT_CLKSPD_SOFT_RESETVAL                     (0x00000000U)
#define CSL_TMR_EMUMGT_CLKSPD_SOFT_MAX                          (0x00000001U)

#define CSL_TMR_EMUMGT_CLKSPD_RESETVAL                          (0x00000000U)

/* GPINT_EN */

#define CSL_TMR_GPINT_EN_GPINT12_ENI_MASK                       (0x00000001U)
#define CSL_TMR_GPINT_EN_GPINT12_ENI_SHIFT                      (0U)
#define CSL_TMR_GPINT_EN_GPINT12_ENI_RESETVAL                   (0x00000000U)
#define CSL_TMR_GPINT_EN_GPINT12_ENI_MAX                        (0x00000001U)

#define CSL_TMR_GPINT_EN_GPINT12_ENO_MASK                       (0x00000002U)
#define CSL_TMR_GPINT_EN_GPINT12_ENO_SHIFT                      (1U)
#define CSL_TMR_GPINT_EN_GPINT12_ENO_RESETVAL                   (0x00000000U)
#define CSL_TMR_GPINT_EN_GPINT12_ENO_MAX                        (0x00000001U)

#define CSL_TMR_GPINT_EN_GPINT12_INVI_MASK                      (0x00000010U)
#define CSL_TMR_GPINT_EN_GPINT12_INVI_SHIFT                     (4U)
#define CSL_TMR_GPINT_EN_GPINT12_INVI_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPINT_EN_GPINT12_INVI_MAX                       (0x00000001U)

#define CSL_TMR_GPINT_EN_GPINT12_INVO_MASK                      (0x00000020U)
#define CSL_TMR_GPINT_EN_GPINT12_INVO_SHIFT                     (5U)
#define CSL_TMR_GPINT_EN_GPINT12_INVO_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPINT_EN_GPINT12_INVO_MAX                       (0x00000001U)

#define CSL_TMR_GPINT_EN_GPINT34_ENI_MASK                       (0x00000100U)
#define CSL_TMR_GPINT_EN_GPINT34_ENI_SHIFT                      (8U)
#define CSL_TMR_GPINT_EN_GPINT34_ENI_RESETVAL                   (0x00000000U)
#define CSL_TMR_GPINT_EN_GPINT34_ENI_MAX                        (0x00000001U)

#define CSL_TMR_GPINT_EN_GPINT34_ENO_MASK                       (0x00000200U)
#define CSL_TMR_GPINT_EN_GPINT34_ENO_SHIFT                      (9U)
#define CSL_TMR_GPINT_EN_GPINT34_ENO_RESETVAL                   (0x00000000U)
#define CSL_TMR_GPINT_EN_GPINT34_ENO_MAX                        (0x00000001U)

#define CSL_TMR_GPINT_EN_GPINT34_INVI_MASK                      (0x00001000U)
#define CSL_TMR_GPINT_EN_GPINT34_INVI_SHIFT                     (12U)
#define CSL_TMR_GPINT_EN_GPINT34_INVI_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPINT_EN_GPINT34_INVI_MAX                       (0x00000001U)

#define CSL_TMR_GPINT_EN_GPINT34_INVO_MASK                      (0x00002000U)
#define CSL_TMR_GPINT_EN_GPINT34_INVO_SHIFT                     (13U)
#define CSL_TMR_GPINT_EN_GPINT34_INVO_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPINT_EN_GPINT34_INVO_MAX                       (0x00000001U)

#define CSL_TMR_GPINT_EN_GPIO_ENI12_MASK                        (0x00010000U)
#define CSL_TMR_GPINT_EN_GPIO_ENI12_SHIFT                       (16U)
#define CSL_TMR_GPINT_EN_GPIO_ENI12_RESETVAL                    (0x00000000U)
#define CSL_TMR_GPINT_EN_GPIO_ENI12_MAX                         (0x00000001U)

#define CSL_TMR_GPINT_EN_GPIO_ENO12_MASK                        (0x00020000U)
#define CSL_TMR_GPINT_EN_GPIO_ENO12_SHIFT                       (17U)
#define CSL_TMR_GPINT_EN_GPIO_ENO12_RESETVAL                    (0x00000000U)
#define CSL_TMR_GPINT_EN_GPIO_ENO12_MAX                         (0x00000001U)

#define CSL_TMR_GPINT_EN_GPIO_ENI34_MASK                        (0x01000000U)
#define CSL_TMR_GPINT_EN_GPIO_ENI34_SHIFT                       (24U)
#define CSL_TMR_GPINT_EN_GPIO_ENI34_RESETVAL                    (0x00000000U)
#define CSL_TMR_GPINT_EN_GPIO_ENI34_MAX                         (0x00000001U)

#define CSL_TMR_GPINT_EN_GPIO_ENO34_MASK                        (0x02000000U)
#define CSL_TMR_GPINT_EN_GPIO_ENO34_SHIFT                       (25U)
#define CSL_TMR_GPINT_EN_GPIO_ENO34_RESETVAL                    (0x00000000U)
#define CSL_TMR_GPINT_EN_GPIO_ENO34_MAX                         (0x00000001U)

#define CSL_TMR_GPINT_EN_RESETVAL                               (0x00000000U)

/* GPDIR_DAT */

#define CSL_TMR_GPDIR_DAT_GPIO_DATI12_MASK                      (0x00000001U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATI12_SHIFT                     (0U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATI12_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATI12_MAX                       (0x00000001U)

#define CSL_TMR_GPDIR_DAT_GPIO_DATO12_MASK                      (0x00000002U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATO12_SHIFT                     (1U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATO12_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATO12_MAX                       (0x00000001U)

#define CSL_TMR_GPDIR_DAT_GPIO_DATI34_MASK                      (0x00000100U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATI34_SHIFT                     (8U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATI34_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATI34_MAX                       (0x00000001U)

#define CSL_TMR_GPDIR_DAT_GPIO_DATO34_MASK                      (0x00000200U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATO34_SHIFT                     (9U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATO34_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DATO34_MAX                       (0x00000001U)

#define CSL_TMR_GPDIR_DAT_GPIO_DIRI12_MASK                      (0x00010000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRI12_SHIFT                     (16U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRI12_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRI12_MAX                       (0x00000001U)

#define CSL_TMR_GPDIR_DAT_GPIO_DIRO12_MASK                      (0x00020000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRO12_SHIFT                     (17U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRO12_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRO12_MAX                       (0x00000001U)

#define CSL_TMR_GPDIR_DAT_GPIO_DIRI34_MASK                      (0x01000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRI34_SHIFT                     (24U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRI34_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRI34_MAX                       (0x00000001U)

#define CSL_TMR_GPDIR_DAT_GPIO_DIRO34_MASK                      (0x02000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRO34_SHIFT                     (25U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRO34_RESETVAL                  (0x00000000U)
#define CSL_TMR_GPDIR_DAT_GPIO_DIRO34_MAX                       (0x00000001U)

#define CSL_TMR_GPDIR_DAT_RESETVAL                              (0x00000000U)

/* CNTLO */

#define CSL_TMR_CNTLO_CNT_MASK                                  (0xFFFFFFFFU)
#define CSL_TMR_CNTLO_CNT_SHIFT                                 (0U)
#define CSL_TMR_CNTLO_CNT_RESETVAL                              (0x00000000U)
#define CSL_TMR_CNTLO_CNT_MAX                                   (0xffffffffU)

#define CSL_TMR_CNTLO_RESETVAL                                  (0x00000000U)

/* CNTHI */

#define CSL_TMR_CNTHI_CNT_MASK                                  (0xFFFFFFFFU)
#define CSL_TMR_CNTHI_CNT_SHIFT                                 (0U)
#define CSL_TMR_CNTHI_CNT_RESETVAL                              (0x00000000U)
#define CSL_TMR_CNTHI_CNT_MAX                                   (0xffffffffU)

#define CSL_TMR_CNTHI_RESETVAL                                  (0x00000000U)

/* PRDLO */

#define CSL_TMR_PRDLO_PRDLO_MASK                                (0xFFFFFFFFU)
#define CSL_TMR_PRDLO_PRDLO_SHIFT                               (0U)
#define CSL_TMR_PRDLO_PRDLO_RESETVAL                            (0x00000000U)
#define CSL_TMR_PRDLO_PRDLO_MAX                                 (0xffffffffU)

#define CSL_TMR_PRDLO_RESETVAL                                  (0x00000000U)

/* PRDHI */

#define CSL_TMR_PRDHI_PRDHI_MASK                                (0xFFFFFFFFU)
#define CSL_TMR_PRDHI_PRDHI_SHIFT                               (0U)
#define CSL_TMR_PRDHI_PRDHI_RESETVAL                            (0x00000000U)
#define CSL_TMR_PRDHI_PRDHI_MAX                                 (0xffffffffU)

#define CSL_TMR_PRDHI_RESETVAL                                  (0x00000000U)

/* TCR */

#define CSL_TMR_TCR_TSTAT_LO_MASK                               (0x00000001U)
#define CSL_TMR_TCR_TSTAT_LO_SHIFT                              (0U)
#define CSL_TMR_TCR_TSTAT_LO_RESETVAL                           (0x00000000U)
#define CSL_TMR_TCR_TSTAT_LO_MAX                                (0x00000001U)

#define CSL_TMR_TCR_INVOUTP_LO_MASK                             (0x00000002U)
#define CSL_TMR_TCR_INVOUTP_LO_SHIFT                            (1U)
#define CSL_TMR_TCR_INVOUTP_LO_RESETVAL                         (0x00000000U)
#define CSL_TMR_TCR_INVOUTP_LO_MAX                              (0x00000001U)

#define CSL_TMR_TCR_INVINP_LO_MASK                              (0x00000004U)
#define CSL_TMR_TCR_INVINP_LO_SHIFT                             (2U)
#define CSL_TMR_TCR_INVINP_LO_RESETVAL                          (0x00000000U)
#define CSL_TMR_TCR_INVINP_LO_MAX                               (0x00000001U)

#define CSL_TMR_TCR_CP_LO_MASK                                  (0x00000008U)
#define CSL_TMR_TCR_CP_LO_SHIFT                                 (3U)
#define CSL_TMR_TCR_CP_LO_RESETVAL                              (0x00000000U)
#define CSL_TMR_TCR_CP_LO_MAX                                   (0x00000001U)

#define CSL_TMR_TCR_PWID_LO_MASK                                (0x00000030U)
#define CSL_TMR_TCR_PWID_LO_SHIFT                               (4U)
#define CSL_TMR_TCR_PWID_LO_RESETVAL                            (0x00000000U)
#define CSL_TMR_TCR_PWID_LO_MAX                                 (0x00000003U)

#define CSL_TMR_TCR_ENAMODE_LO_MASK                             (0x000000C0U)
#define CSL_TMR_TCR_ENAMODE_LO_SHIFT                            (6U)
#define CSL_TMR_TCR_ENAMODE_LO_RESETVAL                         (0x00000000U)
#define CSL_TMR_TCR_ENAMODE_LO_DISABLE                          (0x00000000U)

#define CSL_TMR_TCR_CLKSRC_LO_MASK                              (0x00000100U)
#define CSL_TMR_TCR_CLKSRC_LO_SHIFT                             (8U)
#define CSL_TMR_TCR_CLKSRC_LO_RESETVAL                          (0x00000000U)
#define CSL_TMR_TCR_CLKSRC_LO_MAX                               (0x00000001U)

#define CSL_TMR_TCR_TIEN_LO_MASK                                (0x00000200U)
#define CSL_TMR_TCR_TIEN_LO_SHIFT                               (9U)
#define CSL_TMR_TCR_TIEN_LO_RESETVAL                            (0x00000000U)
#define CSL_TMR_TCR_TIEN_LO_MAX                                 (0x00000001U)

#define CSL_TMR_TCR_TSTAT_HI_MASK                               (0x00010000U)
#define CSL_TMR_TCR_TSTAT_HI_SHIFT                              (16U)
#define CSL_TMR_TCR_TSTAT_HI_RESETVAL                           (0x00000000U)
#define CSL_TMR_TCR_TSTAT_HI_MAX                                (0x00000001U)

#define CSL_TMR_TCR_INVOUTP_HI_MASK                             (0x00020000U)
#define CSL_TMR_TCR_INVOUTP_HI_SHIFT                            (17U)
#define CSL_TMR_TCR_INVOUTP_HI_RESETVAL                         (0x00000000U)
#define CSL_TMR_TCR_INVOUTP_HI_MAX                              (0x00000001U)

#define CSL_TMR_TCR_INVINP_HI_MASK                              (0x00040000U)
#define CSL_TMR_TCR_INVINP_HI_SHIFT                             (18U)
#define CSL_TMR_TCR_INVINP_HI_RESETVAL                          (0x00000000U)
#define CSL_TMR_TCR_INVINP_HI_MAX                               (0x00000001U)

#define CSL_TMR_TCR_CP_HI_MASK                                  (0x00080000U)
#define CSL_TMR_TCR_CP_HI_SHIFT                                 (19U)
#define CSL_TMR_TCR_CP_HI_RESETVAL                              (0x00000000U)
#define CSL_TMR_TCR_CP_HI_MAX                                   (0x00000001U)

#define CSL_TMR_TCR_PWID_HI_MASK                                (0x00300000U)
#define CSL_TMR_TCR_PWID_HI_SHIFT                               (20U)
#define CSL_TMR_TCR_PWID_HI_RESETVAL                            (0x00000000U)
#define CSL_TMR_TCR_PWID_HI_MAX                                 (0x00000003U)

#define CSL_TMR_TCR_ENAMODE_HI_MASK                             (0x00C00000U)
#define CSL_TMR_TCR_ENAMODE_HI_SHIFT                            (22U)
#define CSL_TMR_TCR_ENAMODE_HI_RESETVAL                         (0x00000000U)
#define CSL_TMR_TCR_ENAMODE_HI_DISABLE                          (0x00000000U)

#define CSL_TMR_TCR_CLKSRC_HI_MASK                              (0x01000000U)
#define CSL_TMR_TCR_CLKSRC_HI_SHIFT                             (24U)
#define CSL_TMR_TCR_CLKSRC_HI_RESETVAL                          (0x00000000U)
#define CSL_TMR_TCR_CLKSRC_HI_MAX                               (0x00000001U)

#define CSL_TMR_TCR_TIEN_HI_MASK                                (0x02000000U)
#define CSL_TMR_TCR_TIEN_HI_SHIFT                               (25U)
#define CSL_TMR_TCR_TIEN_HI_RESETVAL                            (0x00000000U)
#define CSL_TMR_TCR_TIEN_HI_MAX                                 (0x00000001U)

#define CSL_TMR_TCR_READRSTMODE_HI_MASK                         (0x04000000U)
#define CSL_TMR_TCR_READRSTMODE_HI_SHIFT                        (26U)
#define CSL_TMR_TCR_READRSTMODE_HI_RESETVAL                     (0x00000000U)
#define CSL_TMR_TCR_READRSTMODE_HI_MAX                          (0x00000001U)

#define CSL_TMR_TCR_CAPEVTMODE_LO_MASK                          (0x00003000U)
#define CSL_TMR_TCR_CAPEVTMODE_LO_SHIFT                         (12U)
#define CSL_TMR_TCR_CAPEVTMODE_LO_RESETVAL                      (0x00000000U)
#define CSL_TMR_TCR_CAPEVTMODE_LO_MAX                           (0x00000003U)

#define CSL_TMR_TCR_CAPMODE_LO_MASK                             (0x00000800U)
#define CSL_TMR_TCR_CAPMODE_LO_SHIFT                            (11U)
#define CSL_TMR_TCR_CAPMODE_LO_RESETVAL                         (0x00000000U)
#define CSL_TMR_TCR_CAPMODE_LO_MAX                              (0x00000001U)

#define CSL_TMR_TCR_READRSTMODE_LO_MASK                         (0x00000400U)
#define CSL_TMR_TCR_READRSTMODE_LO_SHIFT                        (10U)
#define CSL_TMR_TCR_READRSTMODE_LO_RESETVAL                     (0x00000000U)
#define CSL_TMR_TCR_READRSTMODE_LO_MAX                          (0x00000001U)

#define CSL_TMR_TCR_CAPMODE_HI_MASK                             (0x08000000U)
#define CSL_TMR_TCR_CAPMODE_HI_SHIFT                            (27U)
#define CSL_TMR_TCR_CAPMODE_HI_RESETVAL                         (0x00000000U)
#define CSL_TMR_TCR_CAPMODE_HI_MAX                              (0x00000001U)

#define CSL_TMR_TCR_CAPEVTMODE_HI_MASK                          (0x30000000U)
#define CSL_TMR_TCR_CAPEVTMODE_HI_SHIFT                         (28U)
#define CSL_TMR_TCR_CAPEVTMODE_HI_RESETVAL                      (0x00000000U)
#define CSL_TMR_TCR_CAPEVTMODE_HI_MAX                           (0x00000003U)

#define CSL_TMR_TCR_RESETVAL                                    (0x00000000U)

/* TGCR */

#define CSL_TMR_TGCR_TIMLORS_MASK                               (0x00000001U)
#define CSL_TMR_TGCR_TIMLORS_SHIFT                              (0U)
#define CSL_TMR_TGCR_TIMLORS_RESETVAL                           (0x00000000U)
#define CSL_TMR_TGCR_TIMLORS_RESET_ON                           (0x00000000U)
#define CSL_TMR_TGCR_TIMLORS_RESET_OFF                          (0x00000001U)

#define CSL_TMR_TGCR_TIMHIRS_MASK                               (0x00000002U)
#define CSL_TMR_TGCR_TIMHIRS_SHIFT                              (1U)
#define CSL_TMR_TGCR_TIMHIRS_RESETVAL                           (0x00000000U)
#define CSL_TMR_TGCR_TIMHIRS_RESET_ON                           (0x00000000U)
#define CSL_TMR_TGCR_TIMHIRS_RESET_OFF                          (0x00000001U)

#define CSL_TMR_TGCR_TIMMODE_MASK                               (0x0000000CU)
#define CSL_TMR_TGCR_TIMMODE_SHIFT                              (2U)
#define CSL_TMR_TGCR_TIMMODE_RESETVAL                           (0x00000000U)
#define CSL_TMR_TGCR_TIMMODE_MAX                                (0x00000003U)

#define CSL_TMR_TGCR_PSCHI_MASK                                 (0x00000F00U)
#define CSL_TMR_TGCR_PSCHI_SHIFT                                (8U)
#define CSL_TMR_TGCR_PSCHI_RESETVAL                             (0x00000000U)
#define CSL_TMR_TGCR_PSCHI_MAX                                  (0x0000000fU)

#define CSL_TMR_TGCR_TDDRHI_MASK                                (0x0000F000U)
#define CSL_TMR_TGCR_TDDRHI_SHIFT                               (12U)
#define CSL_TMR_TGCR_TDDRHI_RESETVAL                            (0x00000000U)
#define CSL_TMR_TGCR_TDDRHI_MAX                                 (0x0000000fU)

#define CSL_TMR_TGCR_BW_COMPATIBLE_MASK                         (0x00000010U)
#define CSL_TMR_TGCR_BW_COMPATIBLE_SHIFT                        (4U)
#define CSL_TMR_TGCR_BW_COMPATIBLE_RESETVAL                     (0x00000000U)
#define CSL_TMR_TGCR_BW_COMPATIBLE_MAX                          (0x00000001U)

#define CSL_TMR_TGCR_RESETVAL                                   (0x00000000U)

/* WDTCR */

#define CSL_TMR_WDTCR_WDIKEY_MASK                               (0x00003000U)
#define CSL_TMR_WDTCR_WDIKEY_SHIFT                              (12U)
#define CSL_TMR_WDTCR_WDIKEY_RESETVAL                           (0x00000000U)
#define CSL_TMR_WDTCR_WDIKEY_MAX                                (0x00000003U)

#define CSL_TMR_WDTCR_WDEN_MASK                                 (0x00004000U)
#define CSL_TMR_WDTCR_WDEN_SHIFT                                (14U)
#define CSL_TMR_WDTCR_WDEN_RESETVAL                             (0x00000000U)
#define CSL_TMR_WDTCR_WDEN_DISABLE                              (0x00000000U)
#define CSL_TMR_WDTCR_WDEN_ENABLE                               (0x00000001U)

#define CSL_TMR_WDTCR_WDFLAG_MASK                               (0x00008000U)
#define CSL_TMR_WDTCR_WDFLAG_SHIFT                              (15U)
#define CSL_TMR_WDTCR_WDFLAG_RESETVAL                           (0x00000000U)
#define CSL_TMR_WDTCR_WDFLAG_MAX                                (0x00000001U)

#define CSL_TMR_WDTCR_WDKEY_MASK                                (0xFFFF0000U)
#define CSL_TMR_WDTCR_WDKEY_SHIFT                               (16U)
#define CSL_TMR_WDTCR_WDKEY_RESETVAL                            (0x00000000U)
#define CSL_TMR_WDTCR_WDKEY_CMD1                                (0x0000a5c6U)
#define CSL_TMR_WDTCR_WDKEY_CMD2                                (0x0000da7eU)
#define CSL_TMR_WDTCR_WDKEY_MAX                                 (0x0000ffffU)

#define CSL_TMR_WDTCR_RESETVAL                                  (0x00000000U)

/* TLGC */

#define CSL_TMR_TLGC_RESETVAL                                   (0x00000290U)

/* TLMR */

#define CSL_TMR_TLMR_RESETVAL                                   (0x00000000U)

/* RELLO */

#define CSL_TMR_RELLO_RELLO_MASK                                (0xFFFFFFFFU)
#define CSL_TMR_RELLO_RELLO_SHIFT                               (0U)
#define CSL_TMR_RELLO_RELLO_RESETVAL                            (0x00000000U)
#define CSL_TMR_RELLO_RELLO_MAX                                 (0xffffffffU)

#define CSL_TMR_RELLO_RESETVAL                                  (0x00000000U)

/* RELHI */

#define CSL_TMR_RELHI_RELHI_MASK                                (0xFFFFFFFFU)
#define CSL_TMR_RELHI_RELHI_SHIFT                               (0U)
#define CSL_TMR_RELHI_RELHI_RESETVAL                            (0x00000000U)
#define CSL_TMR_RELHI_RELHI_MAX                                 (0xffffffffU)

#define CSL_TMR_RELHI_RESETVAL                                  (0x00000000U)

/* CAPLO */

#define CSL_TMR_CAPLO_RESETVAL                                  (0x00000000U)

/* CAPHI */

#define CSL_TMR_CAPHI_RESETVAL                                  (0x00000000U)

/* INTCTL_STAT */

#define CSL_TMR_INTCTL_STAT_CMP_INT_EN_LO_MASK                  (0x00000001U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_EN_LO_SHIFT                 (0U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_EN_LO_RESETVAL              (0x00000000U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_EN_LO_MAX                   (0x00000001U)

#define CSL_TMR_INTCTL_STAT_CMP_INT_STAT_LO_MASK                (0x00000002U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_STAT_LO_SHIFT               (1U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_STAT_LO_RESETVAL            (0x00000000U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_STAT_LO_MAX                 (0x00000001U)

#define CSL_TMR_INTCTL_STAT_EVT_INT_EN_LO_MASK                  (0x00000004U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_EN_LO_SHIFT                 (2U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_EN_LO_RESETVAL              (0x00000000U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_EN_LO_MAX                   (0x00000001U)

#define CSL_TMR_INTCTL_STAT_EVT_INT_STAT_LO_MASK                (0x00000008U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_STAT_LO_SHIFT               (3U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_STAT_LO_RESETVAL            (0x00000000U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_STAT_LO_MAX                 (0x00000001U)

#define CSL_TMR_INTCTL_STAT_EVAL_LO_MASK                        (0x00004000U)
#define CSL_TMR_INTCTL_STAT_EVAL_LO_SHIFT                       (14U)
#define CSL_TMR_INTCTL_STAT_EVAL_LO_RESETVAL                    (0x00000000U)
#define CSL_TMR_INTCTL_STAT_EVAL_LO_MAX                         (0x00000001U)

#define CSL_TMR_INTCTL_STAT_SET_LO_MASK                         (0x00008000U)
#define CSL_TMR_INTCTL_STAT_SET_LO_SHIFT                        (15U)
#define CSL_TMR_INTCTL_STAT_SET_LO_RESETVAL                     (0x00000000U)
#define CSL_TMR_INTCTL_STAT_SET_LO_MAX                          (0x00000001U)

#define CSL_TMR_INTCTL_STAT_CMP_INT_EN_HI_MASK                  (0x00010000U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_EN_HI_SHIFT                 (16U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_EN_HI_RESETVAL              (0x00000000U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_EN_HI_MAX                   (0x00000001U)

#define CSL_TMR_INTCTL_STAT_CMP_INT_STAT_HI_MASK                (0x00020000U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_STAT_HI_SHIFT               (17U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_STAT_HI_RESETVAL            (0x00000000U)
#define CSL_TMR_INTCTL_STAT_CMP_INT_STAT_HI_MAX                 (0x00000001U)

#define CSL_TMR_INTCTL_STAT_EVT_INT_EN_HI_MASK                  (0x00040000U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_EN_HI_SHIFT                 (18U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_EN_HI_RESETVAL              (0x00000000U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_EN_HI_MAX                   (0x00000001U)

#define CSL_TMR_INTCTL_STAT_EVT_INT_STAT_HI_MASK                (0x00080000U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_STAT_HI_SHIFT               (19U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_STAT_HI_RESETVAL            (0x00000000U)
#define CSL_TMR_INTCTL_STAT_EVT_INT_STAT_HI_MAX                 (0x00000001U)

#define CSL_TMR_INTCTL_STAT_EVAL_HI_MASK                        (0x40000000U)
#define CSL_TMR_INTCTL_STAT_EVAL_HI_SHIFT                       (30U)
#define CSL_TMR_INTCTL_STAT_EVAL_HI_RESETVAL                    (0x00000000U)
#define CSL_TMR_INTCTL_STAT_EVAL_HI_MAX                         (0x00000001U)

#define CSL_TMR_INTCTL_STAT_SET_HI_MASK                         (0x80000000U)
#define CSL_TMR_INTCTL_STAT_SET_HI_SHIFT                        (31U)
#define CSL_TMR_INTCTL_STAT_SET_HI_RESETVAL                     (0x00000000U)
#define CSL_TMR_INTCTL_STAT_SET_HI_MAX                          (0x00000001U)

#define CSL_TMR_INTCTL_STAT_RESETVAL                            (0x00000000U)

/* TIMERLO_COMPARE_REG */

#define CSL_TMR_TIMERLO_COMPARE_REG_RESETVAL                    (0xffffffffU)

#ifdef __cplusplus
}
#endif
#endif
