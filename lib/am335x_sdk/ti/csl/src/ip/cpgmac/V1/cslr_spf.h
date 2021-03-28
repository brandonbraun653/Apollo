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
#ifndef CSLR_SPF_H_
#define CSLR_SPF_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 IDVER;
    volatile Uint32 STATUS;
    volatile Uint32 CONTROL;
    volatile Uint32 DROPCOUNT;
    volatile Uint32 SWRESET;
    volatile Uint32 PRESCALE;
    volatile Uint32 RATELIM[4];
    volatile Uint32 CONST[8];
    volatile Uint8  RSVD0[8];
    volatile Uint32 INSTRW2;
    volatile Uint32 INSTRW1;
    volatile Uint32 INSTRW0;
    volatile Uint32 INSTR_CTL;
    volatile Uint32 LOG_BEGIN;
    volatile Uint32 LOG_END;
    volatile Uint32 LOG_HWPTR;
    volatile Uint32 LOG_SWPTR;
    volatile Uint32 LOG_MAP0;
    volatile Uint32 LOG_MAP1;
    volatile Uint32 LOG_THRESH[9];
    volatile Uint32 INTCNT;
    volatile Uint32 INT_RAW;
    volatile Uint32 INT_MASKED;
    volatile Uint32 MASK_SET;
    volatile Uint32 MASK_CLR;
} CSL_SpfRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* IDVER */
#define CSL_SPF_IDVER                                           (0x0U)

/* STATUS */
#define CSL_SPF_STATUS                                          (0x4U)

/* CONTROL */
#define CSL_SPF_CONTROL                                         (0x8U)

/* DROPCOUNT */
#define CSL_SPF_DROPCOUNT                                       (0xCU)

/* SWRESET */
#define CSL_SPF_SWRESET                                         (0x10U)

/* PRESCALE */
#define CSL_SPF_PRESCALE                                        (0x14U)

/* RATELIM */
#define CSL_SPF_RATELIM(i)                                      (0x18U + ((i) * (0x4U)))

/* CONST */
#define CSL_SPF_CONST(i)                                        (0x28U + ((i) * (0x4U)))

/* INSTRW2 */
#define CSL_SPF_INSTRW2                                         (0x50U)

/* INSTRW1 */
#define CSL_SPF_INSTRW1                                         (0x54U)

/* INSTRW0 */
#define CSL_SPF_INSTRW0                                         (0x58U)

/* INSTR_CTL */
#define CSL_SPF_INSTR_CTL                                       (0x5CU)

/* LOG_BEGIN */
#define CSL_SPF_LOG_BEGIN                                       (0x60U)

/* LOG_END */
#define CSL_SPF_LOG_END                                         (0x64U)

/* LOG_HWPTR */
#define CSL_SPF_LOG_HWPTR                                       (0x68U)

/* LOG_SWPTR */
#define CSL_SPF_LOG_SWPTR                                       (0x6CU)

/* LOG_MAP0 */
#define CSL_SPF_LOG_MAP0                                        (0x70U)

/* LOG_MAP1 */
#define CSL_SPF_LOG_MAP1                                        (0x74U)

/* LOG_THRESH */
#define CSL_SPF_LOG_THRESH(i)                                   (0x78U + ((i) * (0x4U)))

/* INTCNT */
#define CSL_SPF_INTCNT                                          (0x9CU)

/* INT_RAW */
#define CSL_SPF_INT_RAW                                         (0xA0U)

/* INT_MASKED */
#define CSL_SPF_INT_MASKED                                      (0xA4U)

/* MASK_SET */
#define CSL_SPF_MASK_SET                                        (0xA8U)

/* MASK_CLR */
#define CSL_SPF_MASK_CLR                                        (0xACU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* IDVER */

#define CSL_SPF_IDVER_IDVER_MASK                                (0xFFFF0000U)
#define CSL_SPF_IDVER_IDVER_SHIFT                               (16U)
#define CSL_SPF_IDVER_IDVER_RESETVAL                            (0x00000000U)
#define CSL_SPF_IDVER_IDVER_MAX                                 (0x0000ffffU)

#define CSL_SPF_IDVER_MAJVER_MASK                               (0x0000FF00U)
#define CSL_SPF_IDVER_MAJVER_SHIFT                              (8U)
#define CSL_SPF_IDVER_MAJVER_RESETVAL                           (0x00000000U)
#define CSL_SPF_IDVER_MAJVER_MAX                                (0x000000ffU)

#define CSL_SPF_IDVER_MINVER_MASK                               (0x000000FFU)
#define CSL_SPF_IDVER_MINVER_SHIFT                              (0U)
#define CSL_SPF_IDVER_MINVER_RESETVAL                           (0x00000000U)
#define CSL_SPF_IDVER_MINVER_MAX                                (0x000000ffU)

#define CSL_SPF_IDVER_RESETVAL                                  (0x00000000U)

/* STATUS */

#define CSL_SPF_STATUS_BUSY_MASK                                (0x00000001U)
#define CSL_SPF_STATUS_BUSY_SHIFT                               (0U)
#define CSL_SPF_STATUS_BUSY_RESETVAL                            (0x00000000U)
#define CSL_SPF_STATUS_BUSY_MAX                                 (0x00000001U)

#define CSL_SPF_STATUS_RESETVAL                                 (0x00000000U)

/* CONTROL */

#define CSL_SPF_CONTROL_LOGOW_EN_MASK                           (0x00000200U)
#define CSL_SPF_CONTROL_LOGOW_EN_SHIFT                          (9U)
#define CSL_SPF_CONTROL_LOGOW_EN_RESETVAL                       (0x00000000U)
#define CSL_SPF_CONTROL_LOGOW_EN_MAX                            (0x00000001U)

#define CSL_SPF_CONTROL_LOG_EN_MASK                             (0x00000100U)
#define CSL_SPF_CONTROL_LOG_EN_SHIFT                            (8U)
#define CSL_SPF_CONTROL_LOG_EN_RESETVAL                         (0x00000000U)
#define CSL_SPF_CONTROL_LOG_EN_MAX                              (0x00000001U)

#define CSL_SPF_CONTROL_RULE_LOG_MASK                           (0x00000008U)
#define CSL_SPF_CONTROL_RULE_LOG_SHIFT                          (3U)
#define CSL_SPF_CONTROL_RULE_LOG_RESETVAL                       (0x00000000U)
#define CSL_SPF_CONTROL_RULE_LOG_MAX                            (0x00000001U)

#define CSL_SPF_CONTROL_EXT_BYPASS_MASK                         (0x00000004U)
#define CSL_SPF_CONTROL_EXT_BYPASS_SHIFT                        (2U)
#define CSL_SPF_CONTROL_EXT_BYPASS_RESETVAL                     (0x00000000U)
#define CSL_SPF_CONTROL_EXT_BYPASS_MAX                          (0x00000001U)

#define CSL_SPF_CONTROL_DROP_MASK                               (0x00000002U)
#define CSL_SPF_CONTROL_DROP_SHIFT                              (1U)
#define CSL_SPF_CONTROL_DROP_RESETVAL                           (0x00000000U)
#define CSL_SPF_CONTROL_DROP_MAX                                (0x00000001U)

#define CSL_SPF_CONTROL_ENABLE_MASK                             (0x00000001U)
#define CSL_SPF_CONTROL_ENABLE_SHIFT                            (0U)
#define CSL_SPF_CONTROL_ENABLE_RESETVAL                         (0x00000000U)
#define CSL_SPF_CONTROL_ENABLE_MAX                              (0x00000001U)

#define CSL_SPF_CONTROL_RESETVAL                                (0x00000000U)

/* DROPCOUNT */

#define CSL_SPF_DROPCOUNT_DROPCNT_MASK                          (0x00FFFFFFU)
#define CSL_SPF_DROPCOUNT_DROPCNT_SHIFT                         (0U)
#define CSL_SPF_DROPCOUNT_DROPCNT_RESETVAL                      (0x00000000U)
#define CSL_SPF_DROPCOUNT_DROPCNT_MAX                           (0x00ffffffU)

#define CSL_SPF_DROPCOUNT_RESETVAL                              (0x00000000U)

/* SWRESET */

#define CSL_SPF_SWRESET_SWRST_MASK                              (0x00000001U)
#define CSL_SPF_SWRESET_SWRST_SHIFT                             (0U)
#define CSL_SPF_SWRESET_SWRST_RESETVAL                          (0x00000000U)
#define CSL_SPF_SWRESET_SWRST_MAX                               (0x00000001U)

#define CSL_SPF_SWRESET_RESETVAL                                (0x00000000U)

/* PRESCALE */

#define CSL_SPF_PRESCALE_PRESCALE_MASK                          (0x000FFFFFU)
#define CSL_SPF_PRESCALE_PRESCALE_SHIFT                         (0U)
#define CSL_SPF_PRESCALE_PRESCALE_RESETVAL                      (0x00000000U)
#define CSL_SPF_PRESCALE_PRESCALE_MAX                           (0x000fffffU)

#define CSL_SPF_PRESCALE_RESETVAL                               (0x00000000U)

/* RATELIM */

#define CSL_SPF_RATELIM_RATELIM_MASK                            (0x000000FFU)
#define CSL_SPF_RATELIM_RATELIM_SHIFT                           (0U)
#define CSL_SPF_RATELIM_RATELIM_RESETVAL                        (0x00000000U)
#define CSL_SPF_RATELIM_RATELIM_MAX                             (0x000000ffU)

#define CSL_SPF_RATELIM_RESETVAL                                (0x00000000U)

/* CONST */

#define CSL_SPF_CONST_CONST_MASK                                (0xFFFFFFFFU)
#define CSL_SPF_CONST_CONST_SHIFT                               (0U)
#define CSL_SPF_CONST_CONST_RESETVAL                            (0x00000000U)
#define CSL_SPF_CONST_CONST_MAX                                 (0xffffffffU)

#define CSL_SPF_CONST_RESETVAL                                  (0x00000000U)

/* INSTRW2 */

#define CSL_SPF_INSTRW2_INSTR_W2_MASK                           (0x00003FFFU)
#define CSL_SPF_INSTRW2_INSTR_W2_SHIFT                          (0U)
#define CSL_SPF_INSTRW2_INSTR_W2_RESETVAL                       (0x00000000U)
#define CSL_SPF_INSTRW2_INSTR_W2_MAX                            (0x00003fffU)

#define CSL_SPF_INSTRW2_RESETVAL                                (0x00000000U)

/* INSTRW1 */

#define CSL_SPF_INSTRW1_INSTR_W2_MASK                           (0x00003FFFU)
#define CSL_SPF_INSTRW1_INSTR_W2_SHIFT                          (0U)
#define CSL_SPF_INSTRW1_INSTR_W2_RESETVAL                       (0x00000000U)
#define CSL_SPF_INSTRW1_INSTR_W2_MAX                            (0x00003fffU)

#define CSL_SPF_INSTRW1_RESETVAL                                (0x00000000U)

/* INSTRW0 */

#define CSL_SPF_INSTRW0_INSTR_W0_MASK                           (0xFFFFFFFFU)
#define CSL_SPF_INSTRW0_INSTR_W0_SHIFT                          (0U)
#define CSL_SPF_INSTRW0_INSTR_W0_RESETVAL                       (0x00000000U)
#define CSL_SPF_INSTRW0_INSTR_W0_MAX                            (0xffffffffU)

#define CSL_SPF_INSTRW0_RESETVAL                                (0x00000000U)

/* INSTR_CTL */

#define CSL_SPF_INSTR_CTL_INSTR_WEN_MASK                        (0x80000000U)
#define CSL_SPF_INSTR_CTL_INSTR_WEN_SHIFT                       (31U)
#define CSL_SPF_INSTR_CTL_INSTR_WEN_RESETVAL                    (0x00000000U)
#define CSL_SPF_INSTR_CTL_INSTR_WEN_MAX                         (0x00000001U)

#define CSL_SPF_INSTR_CTL_INSTR_REN_MASK                        (0x40000000U)
#define CSL_SPF_INSTR_CTL_INSTR_REN_SHIFT                       (30U)
#define CSL_SPF_INSTR_CTL_INSTR_REN_RESETVAL                    (0x00000000U)
#define CSL_SPF_INSTR_CTL_INSTR_REN_MAX                         (0x00000001U)

#define CSL_SPF_INSTR_CTL_INSTR_PTR_MASK                        (0x0000001FU)
#define CSL_SPF_INSTR_CTL_INSTR_PTR_SHIFT                       (0U)
#define CSL_SPF_INSTR_CTL_INSTR_PTR_RESETVAL                    (0x00000000U)
#define CSL_SPF_INSTR_CTL_INSTR_PTR_MAX                         (0x0000001fU)

#define CSL_SPF_INSTR_CTL_RESETVAL                              (0x00000000U)

/* LOG_BEGIN */

#define CSL_SPF_LOG_BEGIN_LOG_BEGIN_MASK                        (0xFFFFFFFFU)
#define CSL_SPF_LOG_BEGIN_LOG_BEGIN_SHIFT                       (0U)
#define CSL_SPF_LOG_BEGIN_LOG_BEGIN_RESETVAL                    (0x00000000U)
#define CSL_SPF_LOG_BEGIN_LOG_BEGIN_MAX                         (0xffffffffU)

#define CSL_SPF_LOG_BEGIN_RESETVAL                              (0x00000000U)

/* LOG_END */

#define CSL_SPF_LOG_END_LOG_END_MASK                            (0xFFFFFFFFU)
#define CSL_SPF_LOG_END_LOG_END_SHIFT                           (0U)
#define CSL_SPF_LOG_END_LOG_END_RESETVAL                        (0x00000000U)
#define CSL_SPF_LOG_END_LOG_END_MAX                             (0xffffffffU)

#define CSL_SPF_LOG_END_RESETVAL                                (0x00000000U)

/* LOG_HWPTR */

#define CSL_SPF_LOG_HWPTR_LOG_HWPTR_MASK                        (0xFFFFFFFFU)
#define CSL_SPF_LOG_HWPTR_LOG_HWPTR_SHIFT                       (0U)
#define CSL_SPF_LOG_HWPTR_LOG_HWPTR_RESETVAL                    (0x00000000U)
#define CSL_SPF_LOG_HWPTR_LOG_HWPTR_MAX                         (0xffffffffU)

#define CSL_SPF_LOG_HWPTR_RESETVAL                              (0x00000000U)

/* LOG_SWPTR */

#define CSL_SPF_LOG_SWPTR_LOG_SWPTR_MASK                        (0xFFFFFFFFU)
#define CSL_SPF_LOG_SWPTR_LOG_SWPTR_SHIFT                       (0U)
#define CSL_SPF_LOG_SWPTR_LOG_SWPTR_RESETVAL                    (0x00000000U)
#define CSL_SPF_LOG_SWPTR_LOG_SWPTR_MAX                         (0xffffffffU)

#define CSL_SPF_LOG_SWPTR_RESETVAL                              (0x00000000U)

/* LOG_MAP0 */

#define CSL_SPF_LOG_MAP0_LOGMAP3_MASK                           (0xFF000000U)
#define CSL_SPF_LOG_MAP0_LOGMAP3_SHIFT                          (24U)
#define CSL_SPF_LOG_MAP0_LOGMAP3_RESETVAL                       (0x00000000U)
#define CSL_SPF_LOG_MAP0_LOGMAP3_MAX                            (0x000000ffU)

#define CSL_SPF_LOG_MAP0_LOGMAP2_MASK                           (0x00FF0000U)
#define CSL_SPF_LOG_MAP0_LOGMAP2_SHIFT                          (16U)
#define CSL_SPF_LOG_MAP0_LOGMAP2_RESETVAL                       (0x00000000U)
#define CSL_SPF_LOG_MAP0_LOGMAP2_MAX                            (0x000000ffU)

#define CSL_SPF_LOG_MAP0_LOGMAP1_MASK                           (0x0000FF00U)
#define CSL_SPF_LOG_MAP0_LOGMAP1_SHIFT                          (8U)
#define CSL_SPF_LOG_MAP0_LOGMAP1_RESETVAL                       (0x00000000U)
#define CSL_SPF_LOG_MAP0_LOGMAP1_MAX                            (0x000000ffU)

#define CSL_SPF_LOG_MAP0_LOGMAP0_MASK                           (0x000000FFU)
#define CSL_SPF_LOG_MAP0_LOGMAP0_SHIFT                          (0U)
#define CSL_SPF_LOG_MAP0_LOGMAP0_RESETVAL                       (0x00000000U)
#define CSL_SPF_LOG_MAP0_LOGMAP0_MAX                            (0x000000ffU)

#define CSL_SPF_LOG_MAP0_RESETVAL                               (0x00000000U)

/* LOG_MAP1 */

#define CSL_SPF_LOG_MAP1_LOGMAP7_MASK                           (0xFF000000U)
#define CSL_SPF_LOG_MAP1_LOGMAP7_SHIFT                          (24U)
#define CSL_SPF_LOG_MAP1_LOGMAP7_RESETVAL                       (0x00000000U)
#define CSL_SPF_LOG_MAP1_LOGMAP7_MAX                            (0x000000ffU)

#define CSL_SPF_LOG_MAP1_LOGMAP6_MASK                           (0x00FF0000U)
#define CSL_SPF_LOG_MAP1_LOGMAP6_SHIFT                          (16U)
#define CSL_SPF_LOG_MAP1_LOGMAP6_RESETVAL                       (0x00000000U)
#define CSL_SPF_LOG_MAP1_LOGMAP6_MAX                            (0x000000ffU)

#define CSL_SPF_LOG_MAP1_LOGMAP5_MASK                           (0x0000FF00U)
#define CSL_SPF_LOG_MAP1_LOGMAP5_SHIFT                          (8U)
#define CSL_SPF_LOG_MAP1_LOGMAP5_RESETVAL                       (0x00000000U)
#define CSL_SPF_LOG_MAP1_LOGMAP5_MAX                            (0x000000ffU)

#define CSL_SPF_LOG_MAP1_LOGMAP4_MASK                           (0x000000FFU)
#define CSL_SPF_LOG_MAP1_LOGMAP4_SHIFT                          (0U)
#define CSL_SPF_LOG_MAP1_LOGMAP4_RESETVAL                       (0x00000000U)
#define CSL_SPF_LOG_MAP1_LOGMAP4_MAX                            (0x000000ffU)

#define CSL_SPF_LOG_MAP1_RESETVAL                               (0x00000000U)

/* LOG_THRESH */

#define CSL_SPF_LOG_THRESH_COUNT_MASK                           (0xFFFF0000U)
#define CSL_SPF_LOG_THRESH_COUNT_SHIFT                          (16U)
#define CSL_SPF_LOG_THRESH_COUNT_RESETVAL                       (0x00000000U)
#define CSL_SPF_LOG_THRESH_COUNT_MAX                            (0x0000ffffU)

#define CSL_SPF_LOG_THRESH_THRESH_MASK                          (0x0000FFFFU)
#define CSL_SPF_LOG_THRESH_THRESH_SHIFT                         (0U)
#define CSL_SPF_LOG_THRESH_THRESH_RESETVAL                      (0x00000000U)
#define CSL_SPF_LOG_THRESH_THRESH_MAX                           (0x0000ffffU)

#define CSL_SPF_LOG_THRESH_RESETVAL                             (0x00000000U)

/* INTCNT */

#define CSL_SPF_INTCNT_INTCNT_MASK                              (0x0000001FU)
#define CSL_SPF_INTCNT_INTCNT_SHIFT                             (0U)
#define CSL_SPF_INTCNT_INTCNT_RESETVAL                          (0x00000000U)
#define CSL_SPF_INTCNT_INTCNT_MAX                               (0x0000001fU)

#define CSL_SPF_INTCNT_RESETVAL                                 (0x00000000U)

/* INT_RAW */

#define CSL_SPF_INT_RAW_INTRAW_MASK                             (0x00000001U)
#define CSL_SPF_INT_RAW_INTRAW_SHIFT                            (0U)
#define CSL_SPF_INT_RAW_INTRAW_RESETVAL                         (0x00000000U)
#define CSL_SPF_INT_RAW_INTRAW_MAX                              (0x00000001U)

#define CSL_SPF_INT_RAW_RESETVAL                                (0x00000000U)

/* INT_MASKED */

#define CSL_SPF_INT_MASKED_INTMASKED_MASK                       (0x00000001U)
#define CSL_SPF_INT_MASKED_INTMASKED_SHIFT                      (0U)
#define CSL_SPF_INT_MASKED_INTMASKED_RESETVAL                   (0x00000000U)
#define CSL_SPF_INT_MASKED_INTMASKED_MAX                        (0x00000001U)

#define CSL_SPF_INT_MASKED_RESETVAL                             (0x00000000U)

/* MASK_SET */

#define CSL_SPF_MASK_SET_MASKSET_MASK                           (0x00000001U)
#define CSL_SPF_MASK_SET_MASKSET_SHIFT                          (0U)
#define CSL_SPF_MASK_SET_MASKSET_RESETVAL                       (0x00000000U)
#define CSL_SPF_MASK_SET_MASKSET_MAX                            (0x00000001U)

#define CSL_SPF_MASK_SET_RESETVAL                               (0x00000000U)

/* MASK_CLR */

#define CSL_SPF_MASK_CLR_MASKCLR_MASK                           (0x00000001U)
#define CSL_SPF_MASK_CLR_MASKCLR_SHIFT                          (0U)
#define CSL_SPF_MASK_CLR_MASKCLR_RESETVAL                       (0x00000000U)
#define CSL_SPF_MASK_CLR_MASKCLR_MAX                            (0x00000001U)

#define CSL_SPF_MASK_CLR_RESETVAL                               (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
