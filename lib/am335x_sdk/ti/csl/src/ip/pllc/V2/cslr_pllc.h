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
 *  Name        : cslr_pllc.h
*/
#ifndef CSLR_PLLC_H
#define CSLR_PLLC_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Module Base Offset Values
**************************************************************************/

#define CSL_PLLC_REGS_BASE                                             (0x00000000U)


/**************************************************************************
* Hardware Region  : MMRs in region
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;                       /* PID register */
    volatile uint8_t  Resv_208[204];
    volatile uint32_t SHIFTDIV;                  /* Shift divider register */
    volatile uint32_t CS0;                       /* Catscan control register */
    volatile uint32_t DFTFCNTR;                  /* DFT frequency counter register */
    volatile uint32_t DFTFCNTRCNTL;              /* DFT frequency counter control register */
    volatile uint32_t FUSERR;                    /* Fusefarm error register */
    volatile uint32_t RSTYPE;                    /* Reset type status register */
    volatile uint32_t RSCTRL;                    /* Reset control register */
    volatile uint32_t RSCFG;                     /* Reset control register */
    volatile uint32_t RSISO;                     /* Reset isolation control register */
    volatile uint8_t  Resv_256[12];
    volatile uint32_t PLLCTL;                    /* PLL control register */
    volatile uint8_t  Resv_272[12];
    volatile uint32_t PLLM;                      /* PLL multiplier control register */
    volatile uint8_t  Resv_280[4];
    volatile uint32_t PLLDIV1;                   /* PLL controller divider1 control register */
    volatile uint32_t PLLDIV2;                   /* PLL controller divider2 control register */
    volatile uint8_t  Resv_300[12];
    volatile uint32_t BPDIV;                     /* Bypass divider register */
    volatile uint32_t WAKEUP;                    /* Wakeup register */
    volatile uint8_t  Resv_312[4];
    volatile uint32_t PLLCMD;                    /* PLL Controller command  register */
    volatile uint32_t PLLSTAT;                   /* PLL Controller status  register */
    volatile uint32_t ALNCTL;                    /* PLL Controller clock align control register */
    volatile uint32_t DCHANGE;                   /* PLLDIV ratio change register */
    volatile uint8_t  Resv_336[8];
    volatile uint32_t SYSTAT;                    /* Sysclk status register */
} CSL_PllcRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_PLLC_PID                                                   (0x00000000U)
#define CSL_PLLC_SHIFTDIV                                              (0x000000D0U)
#define CSL_PLLC_CS0                                                   (0x000000D4U)
#define CSL_PLLC_DFTFCNTR                                              (0x000000D8U)
#define CSL_PLLC_DFTFCNTRCNTL                                          (0x000000DCU)
#define CSL_PLLC_FUSERR                                                (0x000000E0U)
#define CSL_PLLC_RSTYPE                                                (0x000000E4U)
#define CSL_PLLC_RSCTRL                                                (0x000000E8U)
#define CSL_PLLC_RSCFG                                                 (0x000000ECU)
#define CSL_PLLC_RSISO                                                 (0x000000F0U)
#define CSL_PLLC_PLLCTL                                                (0x00000100U)
#define CSL_PLLC_PLLM                                                  (0x00000110U)
#define CSL_PLLC_PLLDIV1                                               (0x00000118U)
#define CSL_PLLC_PLLDIV2                                               (0x0000011CU)
#define CSL_PLLC_BPDIV                                                 (0x0000012CU)
#define CSL_PLLC_WAKEUP                                                (0x00000130U)
#define CSL_PLLC_PLLCMD                                                (0x00000138U)
#define CSL_PLLC_PLLSTAT                                               (0x0000013CU)
#define CSL_PLLC_ALNCTL                                                (0x00000140U)
#define CSL_PLLC_DCHANGE                                               (0x00000144U)
#define CSL_PLLC_SYSTAT                                                (0x00000150U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_PLLC_PID_MINOR_MASK                                        (0x0000003FU)
#define CSL_PLLC_PID_MINOR_SHIFT                                       (0x00000000U)
#define CSL_PLLC_PID_MINOR_RESETVAL                                    (0x00000000U)
#define CSL_PLLC_PID_MINOR_MAX                                         (0x0000003FU)

#define CSL_PLLC_PID_CUSTOM_MASK                                       (0x000000C0U)
#define CSL_PLLC_PID_CUSTOM_SHIFT                                      (0x00000006U)
#define CSL_PLLC_PID_CUSTOM_RESETVAL                                   (0x00000000U)
#define CSL_PLLC_PID_CUSTOM_MAX                                        (0x00000003U)

#define CSL_PLLC_PID_MAJOR_MASK                                        (0x00000700U)
#define CSL_PLLC_PID_MAJOR_SHIFT                                       (0x00000008U)
#define CSL_PLLC_PID_MAJOR_RESETVAL                                    (0x00000004U)
#define CSL_PLLC_PID_MAJOR_MAX                                         (0x00000007U)

#define CSL_PLLC_PID_RTL_MASK                                          (0x0000F800U)
#define CSL_PLLC_PID_RTL_SHIFT                                         (0x0000000BU)
#define CSL_PLLC_PID_RTL_RESETVAL                                      (0x0000000BU)
#define CSL_PLLC_PID_RTL_MAX                                           (0x0000001FU)

#define CSL_PLLC_PID_FUNC_MASK                                         (0x0FFF0000U)
#define CSL_PLLC_PID_FUNC_SHIFT                                        (0x00000010U)
#define CSL_PLLC_PID_FUNC_RESETVAL                                     (0x00000481U)
#define CSL_PLLC_PID_FUNC_MAX                                          (0x00000FFFU)

#define CSL_PLLC_PID_BU_MASK                                           (0x30000000U)
#define CSL_PLLC_PID_BU_SHIFT                                          (0x0000001CU)
#define CSL_PLLC_PID_BU_RESETVAL                                       (0x00000000U)
#define CSL_PLLC_PID_BU_MAX                                            (0x00000003U)

#define CSL_PLLC_PID_SCHEME_MASK                                       (0xC0000000U)
#define CSL_PLLC_PID_SCHEME_SHIFT                                      (0x0000001EU)
#define CSL_PLLC_PID_SCHEME_RESETVAL                                   (0x00000001U)
#define CSL_PLLC_PID_SCHEME_MAX                                        (0x00000003U)

#define CSL_PLLC_PID_RESETVAL                                          (0x44815C00U)

/* SHIFTDIV */

#define CSL_PLLC_SHIFTDIV_RSVD_MASK                                    (0xFFFFFF00U)
#define CSL_PLLC_SHIFTDIV_RSVD_SHIFT                                   (0x00000008U)
#define CSL_PLLC_SHIFTDIV_RSVD_RESETVAL                                (0x00000000U)
#define CSL_PLLC_SHIFTDIV_RSVD_MAX                                     (0x00FFFFFFU)

#define CSL_PLLC_SHIFTDIV_DIV_VALUE_MASK                               (0x000000FFU)
#define CSL_PLLC_SHIFTDIV_DIV_VALUE_SHIFT                              (0x00000000U)
#define CSL_PLLC_SHIFTDIV_DIV_VALUE_RESETVAL                           (0x00000000U)
#define CSL_PLLC_SHIFTDIV_DIV_VALUE_MAX                                (0x000000FFU)

#define CSL_PLLC_SHIFTDIV_RESETVAL                                     (0x00000000U)

/* CS0 */

#define CSL_PLLC_CS0_RSVD_MASK                                         (0xFFFFFFFEU)
#define CSL_PLLC_CS0_RSVD_SHIFT                                        (0x00000001U)
#define CSL_PLLC_CS0_RSVD_RESETVAL                                     (0x00000000U)
#define CSL_PLLC_CS0_RSVD_MAX                                          (0x7FFFFFFFU)

#define CSL_PLLC_CS0_CS_CLK_START_MASK                                 (0x00000001U)
#define CSL_PLLC_CS0_CS_CLK_START_SHIFT                                (0x00000000U)
#define CSL_PLLC_CS0_CS_CLK_START_RESETVAL                             (0x00000000U)
#define CSL_PLLC_CS0_CS_CLK_START_MAX                                  (0x00000001U)

#define CSL_PLLC_CS0_RESETVAL                                          (0x00000000U)

/* DFTFCNTR */

#define CSL_PLLC_DFTFCNTR_PLLCNT_MASK                                  (0x0000FFFFU)
#define CSL_PLLC_DFTFCNTR_PLLCNT_SHIFT                                 (0x00000000U)
#define CSL_PLLC_DFTFCNTR_PLLCNT_RESETVAL                              (0x00000000U)
#define CSL_PLLC_DFTFCNTR_PLLCNT_MAX                                   (0x0000FFFFU)

#define CSL_PLLC_DFTFCNTR_PLLREFCNT_MASK                               (0xFFFF0000U)
#define CSL_PLLC_DFTFCNTR_PLLREFCNT_SHIFT                              (0x00000010U)
#define CSL_PLLC_DFTFCNTR_PLLREFCNT_RESETVAL                           (0x00000000U)
#define CSL_PLLC_DFTFCNTR_PLLREFCNT_MAX                                (0x0000FFFFU)

#define CSL_PLLC_DFTFCNTR_RESETVAL                                     (0x00000000U)

/* DFTFCNTRCNTL */

#define CSL_PLLC_DFTFCNTRCNTL_START_MASK                               (0x00000001U)
#define CSL_PLLC_DFTFCNTRCNTL_START_SHIFT                              (0x00000000U)
#define CSL_PLLC_DFTFCNTRCNTL_START_RESETVAL                           (0x00000000U)
#define CSL_PLLC_DFTFCNTRCNTL_START_MAX                                (0x00000001U)

#define CSL_PLLC_DFTFCNTRCNTL_STATUS_MASK                              (0x00000002U)
#define CSL_PLLC_DFTFCNTRCNTL_STATUS_SHIFT                             (0x00000001U)
#define CSL_PLLC_DFTFCNTRCNTL_STATUS_RESETVAL                          (0x00000000U)
#define CSL_PLLC_DFTFCNTRCNTL_STATUS_MAX                               (0x00000001U)

#define CSL_PLLC_DFTFCNTRCNTL_CLKMUX_MASK                              (0x000000F0U)
#define CSL_PLLC_DFTFCNTRCNTL_CLKMUX_SHIFT                             (0x00000004U)
#define CSL_PLLC_DFTFCNTRCNTL_CLKMUX_RESETVAL                          (0x00000000U)
#define CSL_PLLC_DFTFCNTRCNTL_CLKMUX_MAX                               (0x0000000FU)

#define CSL_PLLC_DFTFCNTRCNTL_RSVD_MASK                                (0xFFFFFF00U)
#define CSL_PLLC_DFTFCNTRCNTL_RSVD_SHIFT                               (0x00000008U)
#define CSL_PLLC_DFTFCNTRCNTL_RSVD_RESETVAL                            (0x00000000U)
#define CSL_PLLC_DFTFCNTRCNTL_RSVD_MAX                                 (0x00FFFFFFU)

#define CSL_PLLC_DFTFCNTRCNTL_RESETVAL                                 (0x00000000U)

/* FUSERR */

#define CSL_PLLC_FUSERR_ERR_MASK                                       (0x0000001FU)
#define CSL_PLLC_FUSERR_ERR_SHIFT                                      (0x00000000U)
#define CSL_PLLC_FUSERR_ERR_RESETVAL                                   (0x00000000U)
#define CSL_PLLC_FUSERR_ERR_MAX                                        (0x0000001FU)

#define CSL_PLLC_FUSERR_RSVD_MASK                                      (0xFFFFFFE0U)
#define CSL_PLLC_FUSERR_RSVD_SHIFT                                     (0x00000005U)
#define CSL_PLLC_FUSERR_RSVD_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_FUSERR_RSVD_MAX                                       (0x07FFFFFFU)

#define CSL_PLLC_FUSERR_RESETVAL                                       (0x00000000U)

/* RSTYPE */

#define CSL_PLLC_RSTYPE_POR_MASK                                       (0x00000001U)
#define CSL_PLLC_RSTYPE_POR_SHIFT                                      (0x00000000U)
#define CSL_PLLC_RSTYPE_POR_RESETVAL                                   (0x00000000U)
#define CSL_PLLC_RSTYPE_POR_MAX                                        (0x00000001U)

#define CSL_PLLC_RSTYPE_RSTIN_MASK                                     (0x00000002U)
#define CSL_PLLC_RSTYPE_RSTIN_SHIFT                                    (0x00000001U)
#define CSL_PLLC_RSTYPE_RSTIN_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_RSTYPE_RSTIN_MAX                                      (0x00000001U)

#define CSL_PLLC_RSTYPE_PLLCNTL_MASK                                   (0x00000004U)
#define CSL_PLLC_RSTYPE_PLLCNTL_SHIFT                                  (0x00000002U)
#define CSL_PLLC_RSTYPE_PLLCNTL_RESETVAL                               (0x00000000U)
#define CSL_PLLC_RSTYPE_PLLCNTL_MAX                                    (0x00000001U)

#define CSL_PLLC_RSTYPE_RSVD_MASK                                      (0x000000F8U)
#define CSL_PLLC_RSTYPE_RSVD_SHIFT                                     (0x00000003U)
#define CSL_PLLC_RSTYPE_RSVD_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_RSTYPE_RSVD_MAX                                       (0x0000001FU)

#define CSL_PLLC_RSTYPE_RSTREQ_MASK                                    (0x0000FF00U)
#define CSL_PLLC_RSTYPE_RSTREQ_SHIFT                                   (0x00000008U)
#define CSL_PLLC_RSTYPE_RSTREQ_RESETVAL                                (0x00000000U)
#define CSL_PLLC_RSTYPE_RSTREQ_MAX                                     (0x000000FFU)

#define CSL_PLLC_RSTYPE_RSVD1_MASK                                     (0x0FFF0000U)
#define CSL_PLLC_RSTYPE_RSVD1_SHIFT                                    (0x00000010U)
#define CSL_PLLC_RSTYPE_RSVD1_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_RSTYPE_RSVD1_MAX                                      (0x00000FFFU)

#define CSL_PLLC_RSTYPE_EMU0_MASK                                      (0x10000000U)
#define CSL_PLLC_RSTYPE_EMU0_SHIFT                                     (0x0000001CU)
#define CSL_PLLC_RSTYPE_EMU0_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_RSTYPE_EMU0_MAX                                       (0x00000001U)

#define CSL_PLLC_RSTYPE_EMU1_MASK                                      (0x20000000U)
#define CSL_PLLC_RSTYPE_EMU1_SHIFT                                     (0x0000001DU)
#define CSL_PLLC_RSTYPE_EMU1_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_RSTYPE_EMU1_MAX                                       (0x00000001U)

#define CSL_PLLC_RSTYPE_RSVD2_MASK                                     (0xC0000000U)
#define CSL_PLLC_RSTYPE_RSVD2_SHIFT                                    (0x0000001EU)
#define CSL_PLLC_RSTYPE_RSVD2_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_RSTYPE_RSVD2_MAX                                      (0x00000003U)

#define CSL_PLLC_RSTYPE_RESETVAL                                       (0x00000000U)

/* RSCTRL */

#define CSL_PLLC_RSCTRL_KEY_MASK                                       (0x0000FFFFU)
#define CSL_PLLC_RSCTRL_KEY_SHIFT                                      (0x00000000U)
#define CSL_PLLC_RSCTRL_KEY_RESETVAL                                   (0x00000003U)
#define CSL_PLLC_RSCTRL_KEY_MAX                                        (0x0000FFFFU)

#define CSL_PLLC_RSCTRL_SWRST_MASK                                     (0x00010000U)
#define CSL_PLLC_RSCTRL_SWRST_SHIFT                                    (0x00000010U)
#define CSL_PLLC_RSCTRL_SWRST_RESETVAL                                 (0x00000001U)
#define CSL_PLLC_RSCTRL_SWRST_MAX                                      (0x00000001U)

#define CSL_PLLC_RSCTRL_RSVD_MASK                                      (0xFFFE0000U)
#define CSL_PLLC_RSCTRL_RSVD_SHIFT                                     (0x00000011U)
#define CSL_PLLC_RSCTRL_RSVD_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_RSCTRL_RSVD_MAX                                       (0x00007FFFU)

#define CSL_PLLC_RSCTRL_RESETVAL                                       (0x00010003U)

/* RSCFG */

#define CSL_PLLC_RSCFG_RSTREQTYPE_MASK                                 (0x000000FFU)
#define CSL_PLLC_RSCFG_RSTREQTYPE_SHIFT                                (0x00000000U)
#define CSL_PLLC_RSCFG_RSTREQTYPE_RESETVAL                             (0x00000000U)
#define CSL_PLLC_RSCFG_RSTREQTYPE_MAX                                  (0x000000FFU)

#define CSL_PLLC_RSCFG_RSVD_MASK                                       (0x00000F00U)
#define CSL_PLLC_RSCFG_RSVD_SHIFT                                      (0x00000008U)
#define CSL_PLLC_RSCFG_RSVD_RESETVAL                                   (0x00000000U)
#define CSL_PLLC_RSCFG_RSVD_MAX                                        (0x0000000FU)

#define CSL_PLLC_RSCFG_RSTPITYPE_MASK                                  (0x00001000U)
#define CSL_PLLC_RSCFG_RSTPITYPE_SHIFT                                 (0x0000000CU)
#define CSL_PLLC_RSCFG_RSTPITYPE_RESETVAL                              (0x00000000U)
#define CSL_PLLC_RSCFG_RSTPITYPE_MAX                                   (0x00000001U)

#define CSL_PLLC_RSCFG_PLLCTRLSOFT_MASK                                (0x00002000U)
#define CSL_PLLC_RSCFG_PLLCTRLSOFT_SHIFT                               (0x0000000DU)
#define CSL_PLLC_RSCFG_PLLCTRLSOFT_RESETVAL                            (0x00000000U)
#define CSL_PLLC_RSCFG_PLLCTRLSOFT_MAX                                 (0x00000001U)

#define CSL_PLLC_RSCFG_RSVD1_MASK                                      (0x0000C000U)
#define CSL_PLLC_RSCFG_RSVD1_SHIFT                                     (0x0000000EU)
#define CSL_PLLC_RSCFG_RSVD1_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_RSCFG_RSVD1_MAX                                       (0x00000003U)

#define CSL_PLLC_RSCFG_RSTBLOCK_MASK                                   (0x00FF0000U)
#define CSL_PLLC_RSCFG_RSTBLOCK_SHIFT                                  (0x00000010U)
#define CSL_PLLC_RSCFG_RSTBLOCK_RESETVAL                               (0x00000000U)
#define CSL_PLLC_RSCFG_RSTBLOCK_MAX                                    (0x000000FFU)

#define CSL_PLLC_RSCFG_RSVD2_MASK                                      (0x1F000000U)
#define CSL_PLLC_RSCFG_RSVD2_SHIFT                                     (0x00000018U)
#define CSL_PLLC_RSCFG_RSVD2_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_RSCFG_RSVD2_MAX                                       (0x0000001FU)

#define CSL_PLLC_RSCFG_PLLCNTLBLOCK_MASK                               (0x20000000U)
#define CSL_PLLC_RSCFG_PLLCNTLBLOCK_SHIFT                              (0x0000001DU)
#define CSL_PLLC_RSCFG_PLLCNTLBLOCK_RESETVAL                           (0x00000000U)
#define CSL_PLLC_RSCFG_PLLCNTLBLOCK_MAX                                (0x00000001U)

#define CSL_PLLC_RSCFG_RSVD3_MASK                                      (0xC0000000U)
#define CSL_PLLC_RSCFG_RSVD3_SHIFT                                     (0x0000001EU)
#define CSL_PLLC_RSCFG_RSVD3_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_RSCFG_RSVD3_MAX                                       (0x00000003U)

#define CSL_PLLC_RSCFG_RESETVAL                                        (0x00000000U)

/* RSISO */

#define CSL_PLLC_RSISO_RSVD_MASK                                       (0xFFFF0000U)
#define CSL_PLLC_RSISO_RSVD_SHIFT                                      (0x00000010U)
#define CSL_PLLC_RSISO_RSVD_RESETVAL                                   (0x00000000U)
#define CSL_PLLC_RSISO_RSVD_MAX                                        (0x0000FFFFU)

#define CSL_PLLC_RSISO_SYSCLKISO_MASK                                  (0x0000FFFFU)
#define CSL_PLLC_RSISO_SYSCLKISO_SHIFT                                 (0x00000000U)
#define CSL_PLLC_RSISO_SYSCLKISO_RESETVAL                              (0x00000000U)
#define CSL_PLLC_RSISO_SYSCLKISO_MAX                                   (0x0000FFFFU)

#define CSL_PLLC_RSISO_RESETVAL                                        (0x00000000U)

/* PLLCTL */

#define CSL_PLLC_PLLCTL_PLLEN_MASK                                     (0x00000001U)
#define CSL_PLLC_PLLCTL_PLLEN_SHIFT                                    (0x00000000U)
#define CSL_PLLC_PLLCTL_PLLEN_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_PLLCTL_PLLEN_MAX                                      (0x00000001U)

#define CSL_PLLC_PLLCTL_PLLPWRDN_MASK                                  (0x00000002U)
#define CSL_PLLC_PLLCTL_PLLPWRDN_SHIFT                                 (0x00000001U)
#define CSL_PLLC_PLLCTL_PLLPWRDN_RESETVAL                              (0x00000001U)
#define CSL_PLLC_PLLCTL_PLLPWRDN_MAX                                   (0x00000001U)

#define CSL_PLLC_PLLCTL_RSVD_MASK                                      (0x00000004U)
#define CSL_PLLC_PLLCTL_RSVD_SHIFT                                     (0x00000002U)
#define CSL_PLLC_PLLCTL_RSVD_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_PLLCTL_RSVD_MAX                                       (0x00000001U)

#define CSL_PLLC_PLLCTL_PLLRST_MASK                                    (0x00000008U)
#define CSL_PLLC_PLLCTL_PLLRST_SHIFT                                   (0x00000003U)
#define CSL_PLLC_PLLCTL_PLLRST_RESETVAL                                (0x00000000U)
#define CSL_PLLC_PLLCTL_PLLRST_MAX                                     (0x00000001U)

#define CSL_PLLC_PLLCTL_PLLDIS_MASK                                    (0x00000010U)
#define CSL_PLLC_PLLCTL_PLLDIS_SHIFT                                   (0x00000004U)
#define CSL_PLLC_PLLCTL_PLLDIS_RESETVAL                                (0x00000000U)
#define CSL_PLLC_PLLCTL_PLLDIS_MAX                                     (0x00000001U)

#define CSL_PLLC_PLLCTL_PLLENSRC_MASK                                  (0x00000020U)
#define CSL_PLLC_PLLCTL_PLLENSRC_SHIFT                                 (0x00000005U)
#define CSL_PLLC_PLLCTL_PLLENSRC_RESETVAL                              (0x00000001U)
#define CSL_PLLC_PLLCTL_PLLENSRC_MAX                                   (0x00000001U)

#define CSL_PLLC_PLLCTL_RSVD1_MASK                                     (0x00000040U)
#define CSL_PLLC_PLLCTL_RSVD1_SHIFT                                    (0x00000006U)
#define CSL_PLLC_PLLCTL_RSVD1_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_PLLCTL_RSVD1_MAX                                      (0x00000001U)

#define CSL_PLLC_PLLCTL_PLLSELB_MASK                                   (0x00000080U)
#define CSL_PLLC_PLLCTL_PLLSELB_SHIFT                                  (0x00000007U)
#define CSL_PLLC_PLLCTL_PLLSELB_RESETVAL                               (0x00000000U)
#define CSL_PLLC_PLLCTL_PLLSELB_MAX                                    (0x00000001U)

#define CSL_PLLC_PLLCTL_CLKMODE_MASK                                   (0x00000100U)
#define CSL_PLLC_PLLCTL_CLKMODE_SHIFT                                  (0x00000008U)
#define CSL_PLLC_PLLCTL_CLKMODE_RESETVAL                               (0x00000000U)
#define CSL_PLLC_PLLCTL_CLKMODE_MAX                                    (0x00000001U)

#define CSL_PLLC_PLLCTL_EXCLKSRC_MASK                                  (0x00000200U)
#define CSL_PLLC_PLLCTL_EXCLKSRC_SHIFT                                 (0x00000009U)
#define CSL_PLLC_PLLCTL_EXCLKSRC_RESETVAL                              (0x00000000U)
#define CSL_PLLC_PLLCTL_EXCLKSRC_MAX                                   (0x00000001U)

#define CSL_PLLC_PLLCTL_RSVD2_MASK                                     (0xFFFFFC00U)
#define CSL_PLLC_PLLCTL_RSVD2_SHIFT                                    (0x0000000AU)
#define CSL_PLLC_PLLCTL_RSVD2_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_PLLCTL_RSVD2_MAX                                      (0x003FFFFFU)

#define CSL_PLLC_PLLCTL_RESETVAL                                       (0x00000022U)

/* PLLM */

#define CSL_PLLC_PLLM_PLLM_MASK                                        (0x000000FFU)
#define CSL_PLLC_PLLM_PLLM_SHIFT                                       (0x00000000U)
#define CSL_PLLC_PLLM_PLLM_RESETVAL                                    (0x00000000U)
#define CSL_PLLC_PLLM_PLLM_MAX                                         (0x000000FFU)

#define CSL_PLLC_PLLM_RSVD_MASK                                        (0xFFFFFF00U)
#define CSL_PLLC_PLLM_RSVD_SHIFT                                       (0x00000008U)
#define CSL_PLLC_PLLM_RSVD_RESETVAL                                    (0x00000000U)
#define CSL_PLLC_PLLM_RSVD_MAX                                         (0x00FFFFFFU)

#define CSL_PLLC_PLLM_RESETVAL                                         (0x00000000U)

/* PLLDIV1 */

#define CSL_PLLC_PLLDIV1_RATIO_MASK                                    (0x000000FFU)
#define CSL_PLLC_PLLDIV1_RATIO_SHIFT                                   (0x00000000U)
#define CSL_PLLC_PLLDIV1_RATIO_RESETVAL                                (0x00000000U)
#define CSL_PLLC_PLLDIV1_RATIO_MAX                                     (0x000000FFU)

#define CSL_PLLC_PLLDIV1_RSVD_MASK                                     (0x00003F00U)
#define CSL_PLLC_PLLDIV1_RSVD_SHIFT                                    (0x00000008U)
#define CSL_PLLC_PLLDIV1_RSVD_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_PLLDIV1_RSVD_MAX                                      (0x0000003FU)

#define CSL_PLLC_PLLDIV1_HALF_RATIO_MASK                               (0x00004000U)
#define CSL_PLLC_PLLDIV1_HALF_RATIO_SHIFT                              (0x0000000EU)
#define CSL_PLLC_PLLDIV1_HALF_RATIO_RESETVAL                           (0x00000000U)
#define CSL_PLLC_PLLDIV1_HALF_RATIO_MAX                                (0x00000001U)

#define CSL_PLLC_PLLDIV1_DN_EN_MASK                                    (0x00008000U)
#define CSL_PLLC_PLLDIV1_DN_EN_SHIFT                                   (0x0000000FU)
#define CSL_PLLC_PLLDIV1_DN_EN_RESETVAL                                (0x00000000U)
#define CSL_PLLC_PLLDIV1_DN_EN_MAX                                     (0x00000001U)

#define CSL_PLLC_PLLDIV1_RSVD1_MASK                                    (0xFFFF0000U)
#define CSL_PLLC_PLLDIV1_RSVD1_SHIFT                                   (0x00000010U)
#define CSL_PLLC_PLLDIV1_RSVD1_RESETVAL                                (0x00000000U)
#define CSL_PLLC_PLLDIV1_RSVD1_MAX                                     (0x0000FFFFU)

#define CSL_PLLC_PLLDIV1_RESETVAL                                      (0x00000000U)

/* PLLDIV2 */

#define CSL_PLLC_PLLDIV2_RATIO_MASK                                    (0x000000FFU)
#define CSL_PLLC_PLLDIV2_RATIO_SHIFT                                   (0x00000000U)
#define CSL_PLLC_PLLDIV2_RATIO_RESETVAL                                (0x00000000U)
#define CSL_PLLC_PLLDIV2_RATIO_MAX                                     (0x000000FFU)

#define CSL_PLLC_PLLDIV2_RSVD_MASK                                     (0x00003F00U)
#define CSL_PLLC_PLLDIV2_RSVD_SHIFT                                    (0x00000008U)
#define CSL_PLLC_PLLDIV2_RSVD_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_PLLDIV2_RSVD_MAX                                      (0x0000003FU)

#define CSL_PLLC_PLLDIV2_HALF_RATIO_MASK                               (0x00004000U)
#define CSL_PLLC_PLLDIV2_HALF_RATIO_SHIFT                              (0x0000000EU)
#define CSL_PLLC_PLLDIV2_HALF_RATIO_RESETVAL                           (0x00000000U)
#define CSL_PLLC_PLLDIV2_HALF_RATIO_MAX                                (0x00000001U)

#define CSL_PLLC_PLLDIV2_DN_EN_MASK                                    (0x00008000U)
#define CSL_PLLC_PLLDIV2_DN_EN_SHIFT                                   (0x0000000FU)
#define CSL_PLLC_PLLDIV2_DN_EN_RESETVAL                                (0x00000000U)
#define CSL_PLLC_PLLDIV2_DN_EN_MAX                                     (0x00000001U)

#define CSL_PLLC_PLLDIV2_RSVD1_MASK                                    (0xFFFF0000U)
#define CSL_PLLC_PLLDIV2_RSVD1_SHIFT                                   (0x00000010U)
#define CSL_PLLC_PLLDIV2_RSVD1_RESETVAL                                (0x00000000U)
#define CSL_PLLC_PLLDIV2_RSVD1_MAX                                     (0x0000FFFFU)

#define CSL_PLLC_PLLDIV2_RESETVAL                                      (0x00000000U)

/* BPDIV */

#define CSL_PLLC_BPDIV_RATIO_MASK                                      (0x000000FFU)
#define CSL_PLLC_BPDIV_RATIO_SHIFT                                     (0x00000000U)
#define CSL_PLLC_BPDIV_RATIO_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_BPDIV_RATIO_MAX                                       (0x000000FFU)

#define CSL_PLLC_BPDIV_RSVD_MASK                                       (0x00007F00U)
#define CSL_PLLC_BPDIV_RSVD_SHIFT                                      (0x00000008U)
#define CSL_PLLC_BPDIV_RSVD_RESETVAL                                   (0x00000000U)
#define CSL_PLLC_BPDIV_RSVD_MAX                                        (0x0000007FU)

#define CSL_PLLC_BPDIV_BPDEN_MASK                                      (0x00008000U)
#define CSL_PLLC_BPDIV_BPDEN_SHIFT                                     (0x0000000FU)
#define CSL_PLLC_BPDIV_BPDEN_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_BPDIV_BPDEN_MAX                                       (0x00000001U)

#define CSL_PLLC_BPDIV_RSVD1_MASK                                      (0xFFFF0000U)
#define CSL_PLLC_BPDIV_RSVD1_SHIFT                                     (0x00000010U)
#define CSL_PLLC_BPDIV_RSVD1_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_BPDIV_RSVD1_MAX                                       (0x0000FFFFU)

#define CSL_PLLC_BPDIV_RESETVAL                                        (0x00000000U)

/* WAKEUP */

#define CSL_PLLC_WAKEUP_WKEN_MASK                                      (0x0000FFFFU)
#define CSL_PLLC_WAKEUP_WKEN_SHIFT                                     (0x00000000U)
#define CSL_PLLC_WAKEUP_WKEN_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_WAKEUP_WKEN_MAX                                       (0x0000FFFFU)

#define CSL_PLLC_WAKEUP_RSVD_MASK                                      (0xFFFF0000U)
#define CSL_PLLC_WAKEUP_RSVD_SHIFT                                     (0x00000010U)
#define CSL_PLLC_WAKEUP_RSVD_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_WAKEUP_RSVD_MAX                                       (0x0000FFFFU)

#define CSL_PLLC_WAKEUP_RESETVAL                                       (0x00000000U)

/* PLLCMD */

#define CSL_PLLC_PLLCMD_GOSET_MASK                                     (0x00000001U)
#define CSL_PLLC_PLLCMD_GOSET_SHIFT                                    (0x00000000U)
#define CSL_PLLC_PLLCMD_GOSET_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_PLLCMD_GOSET_MAX                                      (0x00000001U)

#define CSL_PLLC_PLLCMD_OSCPWRDN_MASK                                  (0x00000002U)
#define CSL_PLLC_PLLCMD_OSCPWRDN_SHIFT                                 (0x00000001U)
#define CSL_PLLC_PLLCMD_OSCPWRDN_RESETVAL                              (0x00000000U)
#define CSL_PLLC_PLLCMD_OSCPWRDN_MAX                                   (0x00000001U)

#define CSL_PLLC_PLLCMD_RSVD_MASK                                      (0xFFFFFFFCU)
#define CSL_PLLC_PLLCMD_RSVD_SHIFT                                     (0x00000002U)
#define CSL_PLLC_PLLCMD_RSVD_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_PLLCMD_RSVD_MAX                                       (0x3FFFFFFFU)

#define CSL_PLLC_PLLCMD_RESETVAL                                       (0x00000000U)

/* PLLSTAT */

#define CSL_PLLC_PLLSTAT_GOSET_MASK                                    (0x00000001U)
#define CSL_PLLC_PLLSTAT_GOSET_SHIFT                                   (0x00000000U)
#define CSL_PLLC_PLLSTAT_GOSET_RESETVAL                                (0x00000000U)
#define CSL_PLLC_PLLSTAT_GOSET_MAX                                     (0x00000001U)

#define CSL_PLLC_PLLSTAT_LOCK_MASK                                     (0x00000002U)
#define CSL_PLLC_PLLSTAT_LOCK_SHIFT                                    (0x00000001U)
#define CSL_PLLC_PLLSTAT_LOCK_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_PLLSTAT_LOCK_MAX                                      (0x00000001U)

#define CSL_PLLC_PLLSTAT_STABLE_MASK                                   (0x00000004U)
#define CSL_PLLC_PLLSTAT_STABLE_SHIFT                                  (0x00000002U)
#define CSL_PLLC_PLLSTAT_STABLE_RESETVAL                               (0x00000000U)
#define CSL_PLLC_PLLSTAT_STABLE_MAX                                    (0x00000001U)

#define CSL_PLLC_PLLSTAT_RSVD_MASK                                     (0xFFFFFFF8U)
#define CSL_PLLC_PLLSTAT_RSVD_SHIFT                                    (0x00000003U)
#define CSL_PLLC_PLLSTAT_RSVD_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_PLLSTAT_RSVD_MAX                                      (0x1FFFFFFFU)

#define CSL_PLLC_PLLSTAT_RESETVAL                                      (0x00000000U)

/* ALNCTL */

#define CSL_PLLC_ALNCTL_ALN1_MASK                                      (0x00000001U)
#define CSL_PLLC_ALNCTL_ALN1_SHIFT                                     (0x00000000U)
#define CSL_PLLC_ALNCTL_ALN1_RESETVAL                                  (0x00000001U)
#define CSL_PLLC_ALNCTL_ALN1_MAX                                       (0x00000001U)

#define CSL_PLLC_ALNCTL_ALN_MASK                                       (0x0000FFFEU)
#define CSL_PLLC_ALNCTL_ALN_SHIFT                                      (0x00000001U)
#define CSL_PLLC_ALNCTL_ALN_RESETVAL                                   (0x00000001U)
#define CSL_PLLC_ALNCTL_ALN_MAX                                        (0x00007FFFU)

#define CSL_PLLC_ALNCTL_RSVD_MASK                                      (0xFFFF0000U)
#define CSL_PLLC_ALNCTL_RSVD_SHIFT                                     (0x00000010U)
#define CSL_PLLC_ALNCTL_RSVD_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_ALNCTL_RSVD_MAX                                       (0x0000FFFFU)

#define CSL_PLLC_ALNCTL_RESETVAL                                       (0x00000003U)

/* DCHANGE */

#define CSL_PLLC_DCHANGE_SYS1_MASK                                     (0x00000001U)
#define CSL_PLLC_DCHANGE_SYS1_SHIFT                                    (0x00000000U)
#define CSL_PLLC_DCHANGE_SYS1_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_DCHANGE_SYS1_MAX                                      (0x00000001U)

#define CSL_PLLC_DCHANGE_SYS_MASK                                      (0x0000FFFEU)
#define CSL_PLLC_DCHANGE_SYS_SHIFT                                     (0x00000001U)
#define CSL_PLLC_DCHANGE_SYS_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_DCHANGE_SYS_MAX                                       (0x00007FFFU)

#define CSL_PLLC_DCHANGE_RSVD_MASK                                     (0xFFFF0000U)
#define CSL_PLLC_DCHANGE_RSVD_SHIFT                                    (0x00000010U)
#define CSL_PLLC_DCHANGE_RSVD_RESETVAL                                 (0x00000000U)
#define CSL_PLLC_DCHANGE_RSVD_MAX                                      (0x0000FFFFU)

#define CSL_PLLC_DCHANGE_RESETVAL                                      (0x00000000U)

/* SYSTAT */

#define CSL_PLLC_SYSTAT_SYS1_ON_MASK                                   (0x00000001U)
#define CSL_PLLC_SYSTAT_SYS1_ON_SHIFT                                  (0x00000000U)
#define CSL_PLLC_SYSTAT_SYS1_ON_RESETVAL                               (0x00000000U)
#define CSL_PLLC_SYSTAT_SYS1_ON_MAX                                    (0x00000001U)

#define CSL_PLLC_SYSTAT_SYS2_ON_MASK                                   (0x00000002U)
#define CSL_PLLC_SYSTAT_SYS2_ON_SHIFT                                  (0x00000001U)
#define CSL_PLLC_SYSTAT_SYS2_ON_RESETVAL                               (0x00000000U)
#define CSL_PLLC_SYSTAT_SYS2_ON_MAX                                    (0x00000001U)

#define CSL_PLLC_SYSTAT_RSVD_MASK                                      (0xFFFFFFFCU)
#define CSL_PLLC_SYSTAT_RSVD_SHIFT                                     (0x00000002U)
#define CSL_PLLC_SYSTAT_RSVD_RESETVAL                                  (0x00000000U)
#define CSL_PLLC_SYSTAT_RSVD_MAX                                       (0x3FFFFFFFU)

#define CSL_PLLC_SYSTAT_RESETVAL                                       (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
