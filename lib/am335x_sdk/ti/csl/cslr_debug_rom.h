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
#ifndef CSLR_DEBUGROM_H_
#define CSLR_DEBUGROM_H_

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
    volatile Uint32 NVIC;
    volatile Uint32 DWT;
    volatile Uint32 FPB;
    volatile Uint32 ITM;
    volatile Uint32 TPIU;
    volatile Uint32 ETM;
    volatile Uint32 ICEC;
    volatile Uint32 END_OF_TABLE;
    volatile Uint8  RSVD0[4012];
    volatile Uint32 MEMTYPE;
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
} CSL_DebugRomRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* NVIC */
#define CSL_DEBUGROM_NVIC                                       (0x0U)

/* DWT */
#define CSL_DEBUGROM_DWT                                        (0x4U)

/* FPB */
#define CSL_DEBUGROM_FPB                                        (0x8U)

/* ITM */
#define CSL_DEBUGROM_ITM                                        (0xCU)

/* TPIU */
#define CSL_DEBUGROM_TPIU                                       (0x10U)

/* ETM */
#define CSL_DEBUGROM_ETM                                        (0x14U)

/* ICEC */
#define CSL_DEBUGROM_ICEC                                       (0x18U)

/* END_OF_TABLE */
#define CSL_DEBUGROM_END_OF_TABLE                               (0x1CU)

/* MEMTYPE */
#define CSL_DEBUGROM_MEMTYPE                                    (0xFCCU)

/* PID4 */
#define CSL_DEBUGROM_PID4                                       (0xFD0U)

/* PID5 */
#define CSL_DEBUGROM_PID5                                       (0xFD4U)

/* PID6 */
#define CSL_DEBUGROM_PID6                                       (0xFD8U)

/* PID7 */
#define CSL_DEBUGROM_PID7                                       (0xFDCU)

/* PID0 */
#define CSL_DEBUGROM_PID0                                       (0xFE0U)

/* PID1 */
#define CSL_DEBUGROM_PID1                                       (0xFE4U)

/* PID2 */
#define CSL_DEBUGROM_PID2                                       (0xFE8U)

/* PID3 */
#define CSL_DEBUGROM_PID3                                       (0xFECU)

/* CID0 */
#define CSL_DEBUGROM_CID0                                       (0xFF0U)

/* CID1 */
#define CSL_DEBUGROM_CID1                                       (0xFF4U)

/* CID2 */
#define CSL_DEBUGROM_CID2                                       (0xFF8U)

/* CID3 */
#define CSL_DEBUGROM_CID3                                       (0xFFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* NVIC */

#define CSL_DEBUGROM_NVIC_NVIC_MASK                             (0xFFFFFFFFU)
#define CSL_DEBUGROM_NVIC_NVIC_SHIFT                            (0U)
#define CSL_DEBUGROM_NVIC_NVIC_RESETVAL                         (0xfff0f003U)
#define CSL_DEBUGROM_NVIC_NVIC_MAX                              (0xffffffffU)

#define CSL_DEBUGROM_NVIC_RESETVAL                              (0xfff0f003U)

/* DWT */

#define CSL_DEBUGROM_DWT_DWT_MASK                               (0xFFFFFFFFU)
#define CSL_DEBUGROM_DWT_DWT_SHIFT                              (0U)
#define CSL_DEBUGROM_DWT_DWT_RESETVAL                           (0xfff02003U)
#define CSL_DEBUGROM_DWT_DWT_MAX                                (0xffffffffU)

#define CSL_DEBUGROM_DWT_RESETVAL                               (0xfff02003U)

/* FPB */

#define CSL_DEBUGROM_FPB_FPB_MASK                               (0xFFFFFFFFU)
#define CSL_DEBUGROM_FPB_FPB_SHIFT                              (0U)
#define CSL_DEBUGROM_FPB_FPB_RESETVAL                           (0xfff03003U)
#define CSL_DEBUGROM_FPB_FPB_MAX                                (0xffffffffU)

#define CSL_DEBUGROM_FPB_RESETVAL                               (0xfff03003U)

/* ITM */

#define CSL_DEBUGROM_ITM_ITM_MASK                               (0xFFFFFFFFU)
#define CSL_DEBUGROM_ITM_ITM_SHIFT                              (0U)
#define CSL_DEBUGROM_ITM_ITM_RESETVAL                           (0xfff01003U)
#define CSL_DEBUGROM_ITM_ITM_MAX                                (0xffffffffU)

#define CSL_DEBUGROM_ITM_RESETVAL                               (0xfff01003U)

/* TPIU */

#define CSL_DEBUGROM_TPIU_TPIU_MASK                             (0xFFFFFFFFU)
#define CSL_DEBUGROM_TPIU_TPIU_SHIFT                            (0U)
#define CSL_DEBUGROM_TPIU_TPIU_RESETVAL                         (0xfff41002U)
#define CSL_DEBUGROM_TPIU_TPIU_MAX                              (0xffffffffU)

#define CSL_DEBUGROM_TPIU_RESETVAL                              (0xfff41002U)

/* ETM */

#define CSL_DEBUGROM_ETM_ETM_MASK                               (0xFFFFFFFFU)
#define CSL_DEBUGROM_ETM_ETM_SHIFT                              (0U)
#define CSL_DEBUGROM_ETM_ETM_RESETVAL                           (0xfff42002U)
#define CSL_DEBUGROM_ETM_ETM_MAX                                (0xffffffffU)

#define CSL_DEBUGROM_ETM_RESETVAL                               (0xfff42002U)

/* ICEC */

#define CSL_DEBUGROM_ICEC_ICEC_MASK                             (0xFFFFFFFFU)
#define CSL_DEBUGROM_ICEC_ICEC_SHIFT                            (0U)
#define CSL_DEBUGROM_ICEC_ICEC_RESETVAL                         (0xfff43003U)
#define CSL_DEBUGROM_ICEC_ICEC_MAX                              (0xffffffffU)

#define CSL_DEBUGROM_ICEC_RESETVAL                              (0xfff43003U)

/* END_OF_TABLE */

#define CSL_DEBUGROM_END_OF_TABLE_EOT_MASK                      (0xFFFFFFFFU)
#define CSL_DEBUGROM_END_OF_TABLE_EOT_SHIFT                     (0U)
#define CSL_DEBUGROM_END_OF_TABLE_EOT_RESETVAL                  (0x00000000U)
#define CSL_DEBUGROM_END_OF_TABLE_EOT_MAX                       (0xffffffffU)

#define CSL_DEBUGROM_END_OF_TABLE_RESETVAL                      (0x00000000U)

/* MEMTYPE */

#define CSL_DEBUGROM_MEMTYPE_MEMTYPE_MASK                       (0xFFFFFFFFU)
#define CSL_DEBUGROM_MEMTYPE_MEMTYPE_SHIFT                      (0U)
#define CSL_DEBUGROM_MEMTYPE_MEMTYPE_RESETVAL                   (0x00000001U)
#define CSL_DEBUGROM_MEMTYPE_MEMTYPE_MAX                        (0xffffffffU)

#define CSL_DEBUGROM_MEMTYPE_RESETVAL                           (0x00000001U)

/* PID4 */

#define CSL_DEBUGROM_PID4_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_PID4_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_PID4_NEWBITFIELD1_RESETVAL                 (0x00000000U)
#define CSL_DEBUGROM_PID4_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_PID4_RESETVAL                              (0x00000000U)

/* PID5 */

#define CSL_DEBUGROM_PID5_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_PID5_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_PID5_NEWBITFIELD1_RESETVAL                 (0x00000000U)
#define CSL_DEBUGROM_PID5_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_PID5_RESETVAL                              (0x00000000U)

/* PID6 */

#define CSL_DEBUGROM_PID6_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_PID6_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_PID6_NEWBITFIELD1_RESETVAL                 (0x00000000U)
#define CSL_DEBUGROM_PID6_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_PID6_RESETVAL                              (0x00000000U)

/* PID7 */

#define CSL_DEBUGROM_PID7_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_PID7_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_PID7_NEWBITFIELD1_RESETVAL                 (0x00000000U)
#define CSL_DEBUGROM_PID7_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_PID7_RESETVAL                              (0x00000000U)

/* PID0 */

#define CSL_DEBUGROM_PID0_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_PID0_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_PID0_NEWBITFIELD1_RESETVAL                 (0x00000000U)
#define CSL_DEBUGROM_PID0_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_PID0_RESETVAL                              (0x00000000U)

/* PID1 */

#define CSL_DEBUGROM_PID1_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_PID1_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_PID1_NEWBITFIELD1_RESETVAL                 (0x00000000U)
#define CSL_DEBUGROM_PID1_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_PID1_RESETVAL                              (0x00000000U)

/* PID2 */

#define CSL_DEBUGROM_PID2_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_PID2_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_PID2_NEWBITFIELD1_RESETVAL                 (0x00000000U)
#define CSL_DEBUGROM_PID2_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_PID2_RESETVAL                              (0x00000000U)

/* PID3 */

#define CSL_DEBUGROM_PID3_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_PID3_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_PID3_NEWBITFIELD1_RESETVAL                 (0x00000000U)
#define CSL_DEBUGROM_PID3_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_PID3_RESETVAL                              (0x00000000U)

/* CID0 */

#define CSL_DEBUGROM_CID0_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_CID0_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_CID0_NEWBITFIELD1_RESETVAL                 (0x0000000dU)
#define CSL_DEBUGROM_CID0_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_CID0_RESETVAL                              (0x0000000dU)

/* CID1 */

#define CSL_DEBUGROM_CID1_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_CID1_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_CID1_NEWBITFIELD1_RESETVAL                 (0x00000010U)
#define CSL_DEBUGROM_CID1_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_CID1_RESETVAL                              (0x00000010U)

/* CID2 */

#define CSL_DEBUGROM_CID2_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_CID2_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_CID2_NEWBITFIELD1_RESETVAL                 (0x00000005U)
#define CSL_DEBUGROM_CID2_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_CID2_RESETVAL                              (0x00000005U)

/* CID3 */

#define CSL_DEBUGROM_CID3_NEWBITFIELD1_MASK                     (0xFFFFFFFFU)
#define CSL_DEBUGROM_CID3_NEWBITFIELD1_SHIFT                    (0U)
#define CSL_DEBUGROM_CID3_NEWBITFIELD1_RESETVAL                 (0x000000b1U)
#define CSL_DEBUGROM_CID3_NEWBITFIELD1_MAX                      (0xffffffffU)

#define CSL_DEBUGROM_CID3_RESETVAL                              (0x000000b1U)

#ifdef __cplusplus
}
#endif
#endif
