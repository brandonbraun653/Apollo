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
#ifndef CSLR_PMMCITM_H_
#define CSLR_PMMCITM_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for _ALL_
**************************************************************************/
typedef struct {
    volatile Uint32 ITM_STIM[32];
    volatile Uint8  RSVD0[3456];
    volatile Uint32 ITM_TER;
    volatile Uint8  RSVD1[60];
    volatile Uint32 ITM_TPR;
    volatile Uint8  RSVD2[60];
    volatile Uint32 ITM_TCR;
    volatile Uint8  RSVD3[379];
} CSL_pmmcItmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* These registers provide the interface for generating instrumentation
 * messages */
#define CSL_PMMCITM_ITM_STIM(i)                                 (0x0U + ((i) * (0x4U)))

/* This register provides individual mask bits for the stimulus registers */
#define CSL_PMMCITM_ITM_TER                                     (0xE00U)

/* This register allows an operating system to control which stimulus ports
 * can be accessed by User code The register is cleared on Power-up reset. */
#define CSL_PMMCITM_ITM_TPR                                     (0xE40U)

/* Trace Control Register is used to configure and control transfers through
 * the ITM interface */
#define CSL_PMMCITM_ITM_TCR                                     (0xE80U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* ITM_STIM */

#define CSL_PMMCITM_ITM_STIM_STIMULUS_MASK                      (0xFFFFFFFFU)
#define CSL_PMMCITM_ITM_STIM_STIMULUS_SHIFT                     (0U)
#define CSL_PMMCITM_ITM_STIM_STIMULUS_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_STIM_STIMULUS_MAX                       (0xffffffffU)

#define CSL_PMMCITM_ITM_STIM_RESETVAL                           (0x00000000U)

/* ITM_TER */

#define CSL_PMMCITM_ITM_TER_STIMENA0_MASK                       (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA0_SHIFT                      (0U)
#define CSL_PMMCITM_ITM_TER_STIMENA0_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA0_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA0_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA1_MASK                       (0x00000002U)
#define CSL_PMMCITM_ITM_TER_STIMENA1_SHIFT                      (1U)
#define CSL_PMMCITM_ITM_TER_STIMENA1_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA1_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA1_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA2_MASK                       (0x00000004U)
#define CSL_PMMCITM_ITM_TER_STIMENA2_SHIFT                      (2U)
#define CSL_PMMCITM_ITM_TER_STIMENA2_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA2_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA2_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA3_MASK                       (0x00000008U)
#define CSL_PMMCITM_ITM_TER_STIMENA3_SHIFT                      (3U)
#define CSL_PMMCITM_ITM_TER_STIMENA3_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA3_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA3_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA4_MASK                       (0x00000010U)
#define CSL_PMMCITM_ITM_TER_STIMENA4_SHIFT                      (4U)
#define CSL_PMMCITM_ITM_TER_STIMENA4_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA4_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA4_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA5_MASK                       (0x00000020U)
#define CSL_PMMCITM_ITM_TER_STIMENA5_SHIFT                      (5U)
#define CSL_PMMCITM_ITM_TER_STIMENA5_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA5_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA5_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA6_MASK                       (0x00000040U)
#define CSL_PMMCITM_ITM_TER_STIMENA6_SHIFT                      (6U)
#define CSL_PMMCITM_ITM_TER_STIMENA6_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA6_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA6_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA7_MASK                       (0x00000080U)
#define CSL_PMMCITM_ITM_TER_STIMENA7_SHIFT                      (7U)
#define CSL_PMMCITM_ITM_TER_STIMENA7_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA7_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA7_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA8_MASK                       (0x00000100U)
#define CSL_PMMCITM_ITM_TER_STIMENA8_SHIFT                      (8U)
#define CSL_PMMCITM_ITM_TER_STIMENA8_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA8_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA8_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA9_MASK                       (0x00000200U)
#define CSL_PMMCITM_ITM_TER_STIMENA9_SHIFT                      (9U)
#define CSL_PMMCITM_ITM_TER_STIMENA9_RESETVAL                   (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA9_EN                         (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA9_DIS                        (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA10_MASK                      (0x00000400U)
#define CSL_PMMCITM_ITM_TER_STIMENA10_SHIFT                     (10U)
#define CSL_PMMCITM_ITM_TER_STIMENA10_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA10_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA10_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA11_MASK                      (0x00000800U)
#define CSL_PMMCITM_ITM_TER_STIMENA11_SHIFT                     (11U)
#define CSL_PMMCITM_ITM_TER_STIMENA11_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA11_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA11_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA12_MASK                      (0x00001000U)
#define CSL_PMMCITM_ITM_TER_STIMENA12_SHIFT                     (12U)
#define CSL_PMMCITM_ITM_TER_STIMENA12_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA12_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA12_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA13_MASK                      (0x00002000U)
#define CSL_PMMCITM_ITM_TER_STIMENA13_SHIFT                     (13U)
#define CSL_PMMCITM_ITM_TER_STIMENA13_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA13_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA13_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA14_MASK                      (0x00004000U)
#define CSL_PMMCITM_ITM_TER_STIMENA14_SHIFT                     (14U)
#define CSL_PMMCITM_ITM_TER_STIMENA14_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA14_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA14_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA15_MASK                      (0x00008000U)
#define CSL_PMMCITM_ITM_TER_STIMENA15_SHIFT                     (15U)
#define CSL_PMMCITM_ITM_TER_STIMENA15_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA15_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA15_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA16_MASK                      (0x00010000U)
#define CSL_PMMCITM_ITM_TER_STIMENA16_SHIFT                     (16U)
#define CSL_PMMCITM_ITM_TER_STIMENA16_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA16_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA16_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA17_MASK                      (0x00020000U)
#define CSL_PMMCITM_ITM_TER_STIMENA17_SHIFT                     (17U)
#define CSL_PMMCITM_ITM_TER_STIMENA17_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA17_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA17_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA18_MASK                      (0x00040000U)
#define CSL_PMMCITM_ITM_TER_STIMENA18_SHIFT                     (18U)
#define CSL_PMMCITM_ITM_TER_STIMENA18_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA18_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA18_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA19_MASK                      (0x00080000U)
#define CSL_PMMCITM_ITM_TER_STIMENA19_SHIFT                     (19U)
#define CSL_PMMCITM_ITM_TER_STIMENA19_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA19_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA19_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA20_MASK                      (0x00100000U)
#define CSL_PMMCITM_ITM_TER_STIMENA20_SHIFT                     (20U)
#define CSL_PMMCITM_ITM_TER_STIMENA20_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA20_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA20_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA21_MASK                      (0x00200000U)
#define CSL_PMMCITM_ITM_TER_STIMENA21_SHIFT                     (21U)
#define CSL_PMMCITM_ITM_TER_STIMENA21_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA21_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA21_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA22_MASK                      (0x00400000U)
#define CSL_PMMCITM_ITM_TER_STIMENA22_SHIFT                     (22U)
#define CSL_PMMCITM_ITM_TER_STIMENA22_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA22_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA22_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA23_MASK                      (0x00800000U)
#define CSL_PMMCITM_ITM_TER_STIMENA23_SHIFT                     (23U)
#define CSL_PMMCITM_ITM_TER_STIMENA23_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA23_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA23_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA24_MASK                      (0x01000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA24_SHIFT                     (24U)
#define CSL_PMMCITM_ITM_TER_STIMENA24_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA24_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA24_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA25_MASK                      (0x02000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA25_SHIFT                     (25U)
#define CSL_PMMCITM_ITM_TER_STIMENA25_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA25_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA25_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA26_MASK                      (0x04000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA26_SHIFT                     (26U)
#define CSL_PMMCITM_ITM_TER_STIMENA26_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA26_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA26_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA27_MASK                      (0x08000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA27_SHIFT                     (27U)
#define CSL_PMMCITM_ITM_TER_STIMENA27_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA27_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA27_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA28_MASK                      (0x10000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA28_SHIFT                     (28U)
#define CSL_PMMCITM_ITM_TER_STIMENA28_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA28_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA28_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA29_MASK                      (0x20000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA29_SHIFT                     (29U)
#define CSL_PMMCITM_ITM_TER_STIMENA29_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA29_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA29_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA30_MASK                      (0x40000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA30_SHIFT                     (30U)
#define CSL_PMMCITM_ITM_TER_STIMENA30_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA30_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA30_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_STIMENA31_MASK                      (0x80000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA31_SHIFT                     (31U)
#define CSL_PMMCITM_ITM_TER_STIMENA31_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TER_STIMENA31_EN                        (0x00000001U)
#define CSL_PMMCITM_ITM_TER_STIMENA31_DIS                       (0x00000000U)

#define CSL_PMMCITM_ITM_TER_RESETVAL                            (0x00000000U)

/* ITM_TPR */

#define CSL_PMMCITM_ITM_TPR_PRIVMASK0_MASK                      (0x00000001U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK0_SHIFT                     (0U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK0_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK0_USER                      (0x00000000U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK0_PRIV                      (0x00000001U)

#define CSL_PMMCITM_ITM_TPR_PRIVMASK1_MASK                      (0x00000002U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK1_SHIFT                     (1U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK1_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK1_USER                      (0x00000000U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK1_PRIV                      (0x00000001U)

#define CSL_PMMCITM_ITM_TPR_PRIVMASK2_MASK                      (0x00000004U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK2_SHIFT                     (2U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK2_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK2_USER                      (0x00000000U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK2_PRIV                      (0x00000001U)

#define CSL_PMMCITM_ITM_TPR_PRIVMASK3_MASK                      (0x00000008U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK3_SHIFT                     (3U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK3_RESETVAL                  (0x00000000U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK3_USER                      (0x00000000U)
#define CSL_PMMCITM_ITM_TPR_PRIVMASK3_PRIV                      (0x00000001U)

#define CSL_PMMCITM_ITM_TPR_RESETVAL                            (0x00000000U)

/* ITM_TCR */

#define CSL_PMMCITM_ITM_TCR_ITMENA_MASK                         (0x00000001U)
#define CSL_PMMCITM_ITM_TCR_ITMENA_SHIFT                        (0U)
#define CSL_PMMCITM_ITM_TCR_ITMENA_RESETVAL                     (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_ITMENA_EN                           (0x00000001U)
#define CSL_PMMCITM_ITM_TCR_ITMENA_DIS                          (0x00000000U)

#define CSL_PMMCITM_ITM_TCR_TSENA_MASK                          (0x00000002U)
#define CSL_PMMCITM_ITM_TCR_TSENA_SHIFT                         (1U)
#define CSL_PMMCITM_ITM_TCR_TSENA_RESETVAL                      (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_TSENA_EN                            (0x00000001U)
#define CSL_PMMCITM_ITM_TCR_TSENA_DIS                           (0x00000000U)

#define CSL_PMMCITM_ITM_TCR_SYNCENA_MASK                        (0x00000004U)
#define CSL_PMMCITM_ITM_TCR_SYNCENA_SHIFT                       (2U)
#define CSL_PMMCITM_ITM_TCR_SYNCENA_RESETVAL                    (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_SYNCENA_EN                          (0x00000001U)
#define CSL_PMMCITM_ITM_TCR_SYNCENA_DIS                         (0x00000000U)

#define CSL_PMMCITM_ITM_TCR_TXENA_MASK                          (0x00000008U)
#define CSL_PMMCITM_ITM_TCR_TXENA_SHIFT                         (3U)
#define CSL_PMMCITM_ITM_TCR_TXENA_RESETVAL                      (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_TXENA_EN                            (0x00000001U)
#define CSL_PMMCITM_ITM_TCR_TXENA_DIS                           (0x00000000U)

#define CSL_PMMCITM_ITM_TCR_SWOENA_MASK                         (0x00000010U)
#define CSL_PMMCITM_ITM_TCR_SWOENA_SHIFT                        (4U)
#define CSL_PMMCITM_ITM_TCR_SWOENA_RESETVAL                     (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_SWOENA_EN                           (0x00000001U)
#define CSL_PMMCITM_ITM_TCR_SWOENA_DIS                          (0x00000000U)

#define CSL_PMMCITM_ITM_TCR_TSPRESCALE_MASK                     (0x00000300U)
#define CSL_PMMCITM_ITM_TCR_TSPRESCALE_SHIFT                    (8U)
#define CSL_PMMCITM_ITM_TCR_TSPRESCALE_RESETVAL                 (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_TSPRESCALE_DIV1                     (0x00000002U)
#define CSL_PMMCITM_ITM_TCR_TSPRESCALE_DIV4                     (0x00000003U)
#define CSL_PMMCITM_ITM_TCR_TSPRESCALE_DIV16                    (0x00000003U)
#define CSL_PMMCITM_ITM_TCR_TSPRESCALE_DIV64                    (0x00000003U)

#define CSL_PMMCITM_ITM_TCR_TRACEBUSID_MASK                     (0x007F0000U)
#define CSL_PMMCITM_ITM_TCR_TRACEBUSID_SHIFT                    (16U)
#define CSL_PMMCITM_ITM_TCR_TRACEBUSID_RESETVAL                 (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_TRACEBUSID_MAX                      (0x0000007fU)

#define CSL_PMMCITM_ITM_TCR_BUSY_MASK                           (0x07800000U)
#define CSL_PMMCITM_ITM_TCR_BUSY_SHIFT                          (23U)
#define CSL_PMMCITM_ITM_TCR_BUSY_RESETVAL                       (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_BUSY_MAX                            (0x0000000fU)

#define CSL_PMMCITM_ITM_TCR_GTSFREQ_MASK                        (0x18000000U)
#define CSL_PMMCITM_ITM_TCR_GTSFREQ_SHIFT                       (27U)
#define CSL_PMMCITM_ITM_TCR_GTSFREQ_RESETVAL                    (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_GTSFREQ_DIS                         (0x00000000U)
#define CSL_PMMCITM_ITM_TCR_GTSFREQ_GEN1                        (0x00000001U)
#define CSL_PMMCITM_ITM_TCR_GTSFREQ_GEN2                        (0x00000002U)
#define CSL_PMMCITM_ITM_TCR_GTSFREQ_GEN3                        (0x00000003U)

#define CSL_PMMCITM_ITM_TCR_RESETVAL                            (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
