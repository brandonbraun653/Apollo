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
#ifndef CSLR_PMMCFPB_H_
#define CSLR_PMMCFPB_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for FPB_Registers
**************************************************************************/
typedef struct {
    volatile Uint32 FP_CTRL;
    volatile Uint32 FP_REMAP;
    volatile Uint32 FP_COMP_CODE[6];
    volatile Uint32 FP_COMP_LIT[2];
    volatile Uint8  RSVD0[4008];
    volatile Uint32 PID4;
    volatile Uint32 PID5;
    volatile Uint32 PID6;
    volatile Uint32 PID7;
    volatile Uint32 PID0;
    volatile Uint32 PID1;
    volatile Uint32 PID2;
    volatile Uint32 PID3;
    volatile Uint32 CID0;
    volatile Uint32 CID1;
    volatile Uint32 CID2;
    volatile Uint32 CID3;
    volatile Uint8  RSVD1[4];
} CSL_pmmcFpbRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* FlashPatch Control Register */
#define CSL_PMMCFPB_FP_CTRL                                     (0x0U)

/* FlashPatch Remap Register */
#define CSL_PMMCFPB_FP_REMAP                                    (0x4U)

/* FlashPatch Comparator Register. Note: For FP_COMP0 to FP_COMP7, bit 0 is
 * reset to 0. Other bits in these registers are not reset. Instruction
 * comparators can be configured to remap the instruction to SRAM or to behave
 * as a breakpoint. */
#define CSL_PMMCFPB_FP_COMP_CODE(i)                             (0x8U + ((i) * (0x4U)))

/* Literal comparators can only be configured with a remapping capability */
#define CSL_PMMCFPB_FP_COMP_LIT(i)                              (0x20U + ((i) * (0x4U)))

/* Peripheral identification register4 */
#define CSL_PMMCFPB_PID4                                        (0xFD0U)

/* Peripheral identification register5 */
#define CSL_PMMCFPB_PID5                                        (0xFD4U)

/* Peripheral identification register6 */
#define CSL_PMMCFPB_PID6                                        (0xFD8U)

/* Peripheral identification register7 */
#define CSL_PMMCFPB_PID7                                        (0xFDCU)

/* Peripheral identification register0 */
#define CSL_PMMCFPB_PID0                                        (0xFE0U)

/* Peripheral identification register1 */
#define CSL_PMMCFPB_PID1                                        (0xFE4U)

/* Peripheral identification register2 */
#define CSL_PMMCFPB_PID2                                        (0xFE8U)

/* Peripheral identification register3 */
#define CSL_PMMCFPB_PID3                                        (0xFECU)

/* Component identification register0 */
#define CSL_PMMCFPB_CID0                                        (0xFF0U)

/* Component identification register1 */
#define CSL_PMMCFPB_CID1                                        (0xFF4U)

/* Component identification register2 */
#define CSL_PMMCFPB_CID2                                        (0xFF8U)

/* Component identification register3 */
#define CSL_PMMCFPB_CID3                                        (0xFFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* FP_CTRL */

#define CSL_PMMCFPB_FP_CTRL_ENABLE_MASK                         (0x00000001U)
#define CSL_PMMCFPB_FP_CTRL_ENABLE_SHIFT                        (0U)
#define CSL_PMMCFPB_FP_CTRL_ENABLE_RESETVAL                     (0x00000000U)
#define CSL_PMMCFPB_FP_CTRL_ENABLE_ENABLE                       (0x00000001U)
#define CSL_PMMCFPB_FP_CTRL_ENABLE_DISABLE                      (0x00000000U)

#define CSL_PMMCFPB_FP_CTRL_KEY_MASK                            (0x00000002U)
#define CSL_PMMCFPB_FP_CTRL_KEY_SHIFT                           (1U)
#define CSL_PMMCFPB_FP_CTRL_KEY_RESETVAL                        (0x00000000U)
#define CSL_PMMCFPB_FP_CTRL_KEY_MAX                             (0x00000001U)

#define CSL_PMMCFPB_FP_CTRL_NUM_CODE1_MASK                      (0x000000F0U)
#define CSL_PMMCFPB_FP_CTRL_NUM_CODE1_SHIFT                     (4U)
#define CSL_PMMCFPB_FP_CTRL_NUM_CODE1_RESETVAL                  (0x00000006U)
#define CSL_PMMCFPB_FP_CTRL_NUM_CODE1_MAX                       (0x0000000fU)

#define CSL_PMMCFPB_FP_CTRL_NUM_LIT_MASK                        (0x00000F00U)
#define CSL_PMMCFPB_FP_CTRL_NUM_LIT_SHIFT                       (8U)
#define CSL_PMMCFPB_FP_CTRL_NUM_LIT_RESETVAL                    (0x00000002U)
#define CSL_PMMCFPB_FP_CTRL_NUM_LIT_MAX                         (0x0000000fU)

#define CSL_PMMCFPB_FP_CTRL_NUM_CODE2_MASK                      (0x00007000U)
#define CSL_PMMCFPB_FP_CTRL_NUM_CODE2_SHIFT                     (12U)
#define CSL_PMMCFPB_FP_CTRL_NUM_CODE2_RESETVAL                  (0x00000000U)
#define CSL_PMMCFPB_FP_CTRL_NUM_CODE2_MAX                       (0x00000007U)

#define CSL_PMMCFPB_FP_CTRL_RESETVAL                            (0x00000260U)

/* FP_REMAP */

#define CSL_PMMCFPB_FP_REMAP_REMAP_MASK                         (0x1FFFFFE0U)
#define CSL_PMMCFPB_FP_REMAP_REMAP_SHIFT                        (5U)
#define CSL_PMMCFPB_FP_REMAP_REMAP_RESETVAL                     (0x00000000U)
#define CSL_PMMCFPB_FP_REMAP_REMAP_MAX                          (0x00ffffffU)

#define CSL_PMMCFPB_FP_REMAP_REMAP_MODE_MASK                    (0x20000000U)
#define CSL_PMMCFPB_FP_REMAP_REMAP_MODE_SHIFT                   (29U)
#define CSL_PMMCFPB_FP_REMAP_REMAP_MODE_RESETVAL                (0x00000000U)
#define CSL_PMMCFPB_FP_REMAP_REMAP_MODE_REMAP_NOT_SUPPORTED     (0x00000000U)
#define CSL_PMMCFPB_FP_REMAP_REMAP_MODE_REMAP_TO_SRAM           (0x00000001U)

#define CSL_PMMCFPB_FP_REMAP_RAZ_MASK                           (0xC0000000U)
#define CSL_PMMCFPB_FP_REMAP_RAZ_SHIFT                          (30U)
#define CSL_PMMCFPB_FP_REMAP_RAZ_RESETVAL                       (0x00000000U)
#define CSL_PMMCFPB_FP_REMAP_RAZ_MAX                            (0x00000003U)

#define CSL_PMMCFPB_FP_REMAP_RESETVAL                           (0x00000000U)

/* FP_COMP_CODE */

#define CSL_PMMCFPB_FP_COMP_CODE_ENABLE_MASK                    (0x00000001U)
#define CSL_PMMCFPB_FP_COMP_CODE_ENABLE_SHIFT                   (0U)
#define CSL_PMMCFPB_FP_COMP_CODE_ENABLE_RESETVAL                (0x00000000U)
#define CSL_PMMCFPB_FP_COMP_CODE_ENABLE_ENABLE                  (0x00000001U)
#define CSL_PMMCFPB_FP_COMP_CODE_ENABLE_DISABLE                 (0x00000000U)

#define CSL_PMMCFPB_FP_COMP_CODE_COMP_MASK                      (0x1FFFFFFCU)
#define CSL_PMMCFPB_FP_COMP_CODE_COMP_SHIFT                     (2U)
#define CSL_PMMCFPB_FP_COMP_CODE_COMP_RESETVAL                  (0x0000002cU)
#define CSL_PMMCFPB_FP_COMP_CODE_COMP_MAX                       (0x07ffffffU)

#define CSL_PMMCFPB_FP_COMP_CODE_REPLACE_MASK                   (0xC0000000U)
#define CSL_PMMCFPB_FP_COMP_CODE_REPLACE_SHIFT                  (30U)
#define CSL_PMMCFPB_FP_COMP_CODE_REPLACE_RESETVAL               (0x00000000U)
#define CSL_PMMCFPB_FP_COMP_CODE_REPLACE_REMAP_TO_REMAP_ADDR    (0x00000000U)
#define CSL_PMMCFPB_FP_COMP_CODE_REPLACE_BP_ON_LOWER_HALFWORD   (0x00000001U)
#define CSL_PMMCFPB_FP_COMP_CODE_REPLACE_BP_ON_UPPER_HALFWORD   (0x00000002U)
#define CSL_PMMCFPB_FP_COMP_CODE_REPLACE_BP_ON_BOTH_HALFWORDS   (0x00000003U)

#define CSL_PMMCFPB_FP_COMP_CODE_RESETVAL                       (0x000000b0U)

/* FP_COMP_LIT */

#define CSL_PMMCFPB_FP_COMP_LIT_ENABLE_MASK                     (0x00000001U)
#define CSL_PMMCFPB_FP_COMP_LIT_ENABLE_SHIFT                    (0U)
#define CSL_PMMCFPB_FP_COMP_LIT_ENABLE_RESETVAL                 (0x00000000U)
#define CSL_PMMCFPB_FP_COMP_LIT_ENABLE_ENABLE                   (0x00000001U)
#define CSL_PMMCFPB_FP_COMP_LIT_ENABLE_DISABLE                  (0x00000000U)

#define CSL_PMMCFPB_FP_COMP_LIT_COMP_MASK                       (0x1FFFFFFCU)
#define CSL_PMMCFPB_FP_COMP_LIT_COMP_SHIFT                      (2U)
#define CSL_PMMCFPB_FP_COMP_LIT_COMP_RESETVAL                   (0x0000002cU)
#define CSL_PMMCFPB_FP_COMP_LIT_COMP_MAX                        (0x07ffffffU)

#define CSL_PMMCFPB_FP_COMP_LIT_RAZ_WI_MASK                     (0xC0000000U)
#define CSL_PMMCFPB_FP_COMP_LIT_RAZ_WI_SHIFT                    (30U)
#define CSL_PMMCFPB_FP_COMP_LIT_RAZ_WI_RESETVAL                 (0x00000000U)
#define CSL_PMMCFPB_FP_COMP_LIT_RAZ_WI_MAX                      (0x00000003U)

#define CSL_PMMCFPB_FP_COMP_LIT_RESETVAL                        (0x000000b0U)

/* PID4 */

#define CSL_PMMCFPB_PID4_JEP_CONTINUATION_CODE_MASK             (0x0000000FU)
#define CSL_PMMCFPB_PID4_JEP_CONTINUATION_CODE_SHIFT            (0U)
#define CSL_PMMCFPB_PID4_JEP_CONTINUATION_CODE_RESETVAL         (0x00000004U)
#define CSL_PMMCFPB_PID4_JEP_CONTINUATION_CODE_MAX              (0x0000000fU)

#define CSL_PMMCFPB_PID4_COUNT_MASK                             (0x000000F0U)
#define CSL_PMMCFPB_PID4_COUNT_SHIFT                            (4U)
#define CSL_PMMCFPB_PID4_COUNT_RESETVAL                         (0x00000000U)
#define CSL_PMMCFPB_PID4_COUNT_MAX                              (0x0000000fU)

#define CSL_PMMCFPB_PID4_RESETVAL                               (0x00000004U)

/* PID5 */

#define CSL_PMMCFPB_PID5_RESETVAL                               (0x00000000U)

/* PID6 */

#define CSL_PMMCFPB_PID6_RESETVAL                               (0x00000000U)

/* PID7 */

#define CSL_PMMCFPB_PID7_RESETVAL                               (0x00000000U)

/* PID0 */

#define CSL_PMMCFPB_PID0_PART_NUMBER_MASK                       (0x000000FFU)
#define CSL_PMMCFPB_PID0_PART_NUMBER_SHIFT                      (0U)
#define CSL_PMMCFPB_PID0_PART_NUMBER_RESETVAL                   (0x00000003U)
#define CSL_PMMCFPB_PID0_PART_NUMBER_MAX                        (0x000000ffU)

#define CSL_PMMCFPB_PID0_RESETVAL                               (0x00000003U)

/* PID1 */

#define CSL_PMMCFPB_PID1_RESETVAL                               (0x000000b0U)

/* PID2 */

#define CSL_PMMCFPB_PID2_RESETVAL                               (0x0000002bU)

/* PID3 */

#define CSL_PMMCFPB_PID3_CUSTOM_MASK                            (0x0000000FU)
#define CSL_PMMCFPB_PID3_CUSTOM_SHIFT                           (0U)
#define CSL_PMMCFPB_PID3_CUSTOM_RESETVAL                        (0x00000000U)
#define CSL_PMMCFPB_PID3_CUSTOM_MAX                             (0x0000000fU)

#define CSL_PMMCFPB_PID3_MINOR_REV_MASK                         (0x000000F0U)
#define CSL_PMMCFPB_PID3_MINOR_REV_SHIFT                        (4U)
#define CSL_PMMCFPB_PID3_MINOR_REV_RESETVAL                     (0x00000000U)
#define CSL_PMMCFPB_PID3_MINOR_REV_MAX                          (0x0000000fU)

#define CSL_PMMCFPB_PID3_RESETVAL                               (0x00000000U)

/* CID0 */

#define CSL_PMMCFPB_CID0_PREAMBLE_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCFPB_CID0_PREAMBLE_SHIFT                         (0U)
#define CSL_PMMCFPB_CID0_PREAMBLE_RESETVAL                      (0x0000000dU)
#define CSL_PMMCFPB_CID0_PREAMBLE_MAX                           (0xffffffffU)

#define CSL_PMMCFPB_CID0_RESETVAL                               (0x0000000dU)

/* CID1 */

#define CSL_PMMCFPB_CID1_PREAMBLE_MASK                          (0x0000000FU)
#define CSL_PMMCFPB_CID1_PREAMBLE_SHIFT                         (0U)
#define CSL_PMMCFPB_CID1_PREAMBLE_RESETVAL                      (0x00000000U)
#define CSL_PMMCFPB_CID1_PREAMBLE_MAX                           (0x0000000fU)

#define CSL_PMMCFPB_CID1_COMPONENT_CLASS_MASK                   (0x000000F0U)
#define CSL_PMMCFPB_CID1_COMPONENT_CLASS_SHIFT                  (4U)
#define CSL_PMMCFPB_CID1_COMPONENT_CLASS_RESETVAL               (0x0000000eU)
#define CSL_PMMCFPB_CID1_COMPONENT_CLASS_MAX                    (0x0000000fU)

#define CSL_PMMCFPB_CID1_RESETVAL                               (0x000000e0U)

/* CID2 */

#define CSL_PMMCFPB_CID2_PREAMBLE_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCFPB_CID2_PREAMBLE_SHIFT                         (0U)
#define CSL_PMMCFPB_CID2_PREAMBLE_RESETVAL                      (0x00000005U)
#define CSL_PMMCFPB_CID2_PREAMBLE_MAX                           (0xffffffffU)

#define CSL_PMMCFPB_CID2_RESETVAL                               (0x00000005U)

/* CID3 */

#define CSL_PMMCFPB_CID3_PREAMBLE_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCFPB_CID3_PREAMBLE_SHIFT                         (0U)
#define CSL_PMMCFPB_CID3_PREAMBLE_RESETVAL                      (0x000000b1U)
#define CSL_PMMCFPB_CID3_PREAMBLE_MAX                           (0xffffffffU)

#define CSL_PMMCFPB_CID3_RESETVAL                               (0x000000b1U)

#ifdef __cplusplus
}
#endif
#endif
