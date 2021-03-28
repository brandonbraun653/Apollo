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
#ifndef CSLR_PMMCDWT_H_
#define CSLR_PMMCDWT_H_

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
    volatile Uint32 DWT_CTRL;
    volatile Uint32 DWT_CYCCNT;
    volatile Uint32 DWT_CPICNT;
    volatile Uint32 DWT_EXCCNT;
    volatile Uint32 DWT_SLEEPCNT;
    volatile Uint32 DWT_LSUCNT;
    volatile Uint32 DWT_FOLDCNT;
    volatile Uint32 DWT_PCSR;
    volatile Uint8  RSVD0[4016];
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
} CSL_pmmcDwtRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* DWT_CTRL */
#define CSL_PMMCDWT_DWT_CTRL                                    (0x0U)

/* DWT_CYCCNT */
#define CSL_PMMCDWT_DWT_CYCCNT                                  (0x4U)

/* DWT_CPICNT */
#define CSL_PMMCDWT_DWT_CPICNT                                  (0x8U)

/* DWT_EXCCNT */
#define CSL_PMMCDWT_DWT_EXCCNT                                  (0xCU)

/* DWT_SLEEPCNT */
#define CSL_PMMCDWT_DWT_SLEEPCNT                                (0x10U)

/* DWT_LSUCNT */
#define CSL_PMMCDWT_DWT_LSUCNT                                  (0x14U)

/* DWT_FOLDCNT */
#define CSL_PMMCDWT_DWT_FOLDCNT                                 (0x18U)

/* DWT_PCSR */
#define CSL_PMMCDWT_DWT_PCSR                                    (0x1CU)

/* PID4 */
#define CSL_PMMCDWT_PID4                                        (0xFD0U)

/* PID5 */
#define CSL_PMMCDWT_PID5                                        (0xFD4U)

/* PID6 */
#define CSL_PMMCDWT_PID6                                        (0xFD8U)

/* PID7 */
#define CSL_PMMCDWT_PID7                                        (0xFDCU)

/* PID0 */
#define CSL_PMMCDWT_PID0                                        (0xFE0U)

/* PID1 */
#define CSL_PMMCDWT_PID1                                        (0xFE4U)

/* PID2 */
#define CSL_PMMCDWT_PID2                                        (0xFE8U)

/* PID3 */
#define CSL_PMMCDWT_PID3                                        (0xFECU)

/* CID0 */
#define CSL_PMMCDWT_CID0                                        (0xFF0U)

/* CID1 */
#define CSL_PMMCDWT_CID1                                        (0xFF4U)

/* CID2 */
#define CSL_PMMCDWT_CID2                                        (0xFF8U)

/* CID3 */
#define CSL_PMMCDWT_CID3                                        (0xFFCU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* DWT_CTRL */

#define CSL_PMMCDWT_DWT_CTRL_NUMCOMP_MASK                       (0xF0000000U)
#define CSL_PMMCDWT_DWT_CTRL_NUMCOMP_SHIFT                      (28U)
#define CSL_PMMCDWT_DWT_CTRL_NUMCOMP_RESETVAL                   (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_NUMCOMP_MAX                        (0x0000000fU)

#define CSL_PMMCDWT_DWT_CTRL_FOLDEVTENA_MASK                    (0x00200000U)
#define CSL_PMMCDWT_DWT_CTRL_FOLDEVTENA_SHIFT                   (21U)
#define CSL_PMMCDWT_DWT_CTRL_FOLDEVTENA_RESETVAL                (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_FOLDEVTENA_NOT_ENABLED             (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_FOLDEVTENA_ENABLED                 (0x00000001U)

#define CSL_PMMCDWT_DWT_CTRL_CYCEVTENA_MASK                     (0x00400000U)
#define CSL_PMMCDWT_DWT_CTRL_CYCEVTENA_SHIFT                    (22U)
#define CSL_PMMCDWT_DWT_CTRL_CYCEVTENA_RESETVAL                 (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_CYCEVTENA_MAX                      (0x00000001U)

#define CSL_PMMCDWT_DWT_CTRL_NOPRFCNT_MASK                      (0x01000000U)
#define CSL_PMMCDWT_DWT_CTRL_NOPRFCNT_SHIFT                     (24U)
#define CSL_PMMCDWT_DWT_CTRL_NOPRFCNT_RESETVAL                  (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_NOPRFCNT_NOT_ENABLED               (0x00000001U)
#define CSL_PMMCDWT_DWT_CTRL_NOPRFCNT_ENABLED                   (0x00000000U)

#define CSL_PMMCDWT_DWT_CTRL_NOCYCCNT_MASK                      (0x02000000U)
#define CSL_PMMCDWT_DWT_CTRL_NOCYCCNT_SHIFT                     (25U)
#define CSL_PMMCDWT_DWT_CTRL_NOCYCCNT_RESETVAL                  (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_NOCYCCNT_NOT_ENABLED               (0x00000001U)
#define CSL_PMMCDWT_DWT_CTRL_NOCYCCNT_ENABLED                   (0x00000000U)

#define CSL_PMMCDWT_DWT_CTRL_NOEXTTRIG_MASK                     (0x04000000U)
#define CSL_PMMCDWT_DWT_CTRL_NOEXTTRIG_SHIFT                    (26U)
#define CSL_PMMCDWT_DWT_CTRL_NOEXTTRIG_RESETVAL                 (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_NOEXTTRIG_NOT_ENABLED              (0x00000001U)
#define CSL_PMMCDWT_DWT_CTRL_NOEXTTRIG_ENABLED                  (0x00000000U)

#define CSL_PMMCDWT_DWT_CTRL_NOTRCPKT_MASK                      (0x08000000U)
#define CSL_PMMCDWT_DWT_CTRL_NOTRCPKT_SHIFT                     (27U)
#define CSL_PMMCDWT_DWT_CTRL_NOTRCPKT_RESETVAL                  (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_NOTRCPKT_NOT_ENABLED               (0x00000001U)
#define CSL_PMMCDWT_DWT_CTRL_NOTRCPKT_ENABLED                   (0x00000000U)

#define CSL_PMMCDWT_DWT_CTRL_CYCCNTENA_MASK                     (0x00000001U)
#define CSL_PMMCDWT_DWT_CTRL_CYCCNTENA_SHIFT                    (0U)
#define CSL_PMMCDWT_DWT_CTRL_CYCCNTENA_RESETVAL                 (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_CYCCNTENA_MAX                      (0x00000001U)

#define CSL_PMMCDWT_DWT_CTRL_POSTPRESET_MASK                    (0x0000001EU)
#define CSL_PMMCDWT_DWT_CTRL_POSTPRESET_SHIFT                   (1U)
#define CSL_PMMCDWT_DWT_CTRL_POSTPRESET_RESETVAL                (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_POSTPRESET_MAX                     (0x0000000fU)

#define CSL_PMMCDWT_DWT_CTRL_POSTCNT_MASK                       (0x000001E0U)
#define CSL_PMMCDWT_DWT_CTRL_POSTCNT_SHIFT                      (5U)
#define CSL_PMMCDWT_DWT_CTRL_POSTCNT_RESETVAL                   (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_POSTCNT_MAX                        (0x0000000fU)

#define CSL_PMMCDWT_DWT_CTRL_CYCTAP_MASK                        (0x00000200U)
#define CSL_PMMCDWT_DWT_CTRL_CYCTAP_SHIFT                       (9U)
#define CSL_PMMCDWT_DWT_CTRL_CYCTAP_RESETVAL                    (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_CYCTAP_CYCTAP10                    (0x00000001U)
#define CSL_PMMCDWT_DWT_CTRL_CYCTAP_CYCTAP6                     (0x00000000U)

#define CSL_PMMCDWT_DWT_CTRL_SYNCTAP_MASK                       (0x00000C00U)
#define CSL_PMMCDWT_DWT_CTRL_SYNCTAP_SHIFT                      (10U)
#define CSL_PMMCDWT_DWT_CTRL_SYNCTAP_RESETVAL                   (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_SYNCTAP_DISABLED                   (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_SYNCTAP_TAP24                      (0x00000001U)
#define CSL_PMMCDWT_DWT_CTRL_SYNCTAP_TAP26                      (0x00000002U)
#define CSL_PMMCDWT_DWT_CTRL_SYNCTAP_TAP28                      (0x00000003U)

#define CSL_PMMCDWT_DWT_CTRL_PCSAMPLENA_MASK                    (0x00001000U)
#define CSL_PMMCDWT_DWT_CTRL_PCSAMPLENA_SHIFT                   (12U)
#define CSL_PMMCDWT_DWT_CTRL_PCSAMPLENA_RESETVAL                (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_PCSAMPLENA_MAX                     (0x00000001U)

#define CSL_PMMCDWT_DWT_CTRL_EXCTRCENA_MASK                     (0x00010000U)
#define CSL_PMMCDWT_DWT_CTRL_EXCTRCENA_SHIFT                    (16U)
#define CSL_PMMCDWT_DWT_CTRL_EXCTRCENA_RESETVAL                 (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_EXCTRCENA_NOT_ENABLED              (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_EXCTRCENA_ENABLED                  (0x00000001U)

#define CSL_PMMCDWT_DWT_CTRL_CPIEVTENA_MASK                     (0x00020000U)
#define CSL_PMMCDWT_DWT_CTRL_CPIEVTENA_SHIFT                    (17U)
#define CSL_PMMCDWT_DWT_CTRL_CPIEVTENA_RESETVAL                 (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_CPIEVTENA_NOT_ENABLED              (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_CPIEVTENA_ENABLED                  (0x00000001U)

#define CSL_PMMCDWT_DWT_CTRL_EXCEVTENA_MASK                     (0x00040000U)
#define CSL_PMMCDWT_DWT_CTRL_EXCEVTENA_SHIFT                    (18U)
#define CSL_PMMCDWT_DWT_CTRL_EXCEVTENA_RESETVAL                 (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_EXCEVTENA_NOT_ENABLED              (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_EXCEVTENA_ENABLED                  (0x00000001U)

#define CSL_PMMCDWT_DWT_CTRL_SLEEPEVTENA_MASK                   (0x00080000U)
#define CSL_PMMCDWT_DWT_CTRL_SLEEPEVTENA_SHIFT                  (19U)
#define CSL_PMMCDWT_DWT_CTRL_SLEEPEVTENA_RESETVAL               (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_SLEEPEVTENA_NOT_ENABLED            (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_SLEEPEVTENA_ENABLED                (0x00000001U)

#define CSL_PMMCDWT_DWT_CTRL_LSUEVTENA_MASK                     (0x00100000U)
#define CSL_PMMCDWT_DWT_CTRL_LSUEVTENA_SHIFT                    (20U)
#define CSL_PMMCDWT_DWT_CTRL_LSUEVTENA_RESETVAL                 (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_LSUEVTENA_NOT_ENABLED              (0x00000000U)
#define CSL_PMMCDWT_DWT_CTRL_LSUEVTENA_ENABLED                  (0x00000001U)

#define CSL_PMMCDWT_DWT_CTRL_RESETVAL                           (0x00000000U)

/* DWT_CYCCNT */

#define CSL_PMMCDWT_DWT_CYCCNT_CYCCNT_MASK                      (0xFFFFFFFFU)
#define CSL_PMMCDWT_DWT_CYCCNT_CYCCNT_SHIFT                     (0U)
#define CSL_PMMCDWT_DWT_CYCCNT_CYCCNT_RESETVAL                  (0x00000000U)
#define CSL_PMMCDWT_DWT_CYCCNT_CYCCNT_MAX                       (0xffffffffU)

#define CSL_PMMCDWT_DWT_CYCCNT_RESETVAL                         (0x00000000U)

/* DWT_CPICNT */

#define CSL_PMMCDWT_DWT_CPICNT_CPICNT_MASK                      (0x000000FFU)
#define CSL_PMMCDWT_DWT_CPICNT_CPICNT_SHIFT                     (0U)
#define CSL_PMMCDWT_DWT_CPICNT_CPICNT_RESETVAL                  (0x00000000U)
#define CSL_PMMCDWT_DWT_CPICNT_CPICNT_MAX                       (0x000000ffU)

#define CSL_PMMCDWT_DWT_CPICNT_RESETVAL                         (0x00000000U)

/* DWT_EXCCNT */

#define CSL_PMMCDWT_DWT_EXCCNT_EXCCNT_MASK                      (0x000000FFU)
#define CSL_PMMCDWT_DWT_EXCCNT_EXCCNT_SHIFT                     (0U)
#define CSL_PMMCDWT_DWT_EXCCNT_EXCCNT_RESETVAL                  (0x00000000U)
#define CSL_PMMCDWT_DWT_EXCCNT_EXCCNT_MAX                       (0x000000ffU)

#define CSL_PMMCDWT_DWT_EXCCNT_RESETVAL                         (0x00000000U)

/* DWT_SLEEPCNT */

#define CSL_PMMCDWT_DWT_SLEEPCNT_SLEEPCNT_MASK                  (0x000000FFU)
#define CSL_PMMCDWT_DWT_SLEEPCNT_SLEEPCNT_SHIFT                 (0U)
#define CSL_PMMCDWT_DWT_SLEEPCNT_SLEEPCNT_RESETVAL              (0x00000000U)
#define CSL_PMMCDWT_DWT_SLEEPCNT_SLEEPCNT_MAX                   (0x000000ffU)

#define CSL_PMMCDWT_DWT_SLEEPCNT_RESETVAL                       (0x00000000U)

/* DWT_LSUCNT */

#define CSL_PMMCDWT_DWT_LSUCNT_LSUCNT_MASK                      (0x000000FFU)
#define CSL_PMMCDWT_DWT_LSUCNT_LSUCNT_SHIFT                     (0U)
#define CSL_PMMCDWT_DWT_LSUCNT_LSUCNT_RESETVAL                  (0x00000000U)
#define CSL_PMMCDWT_DWT_LSUCNT_LSUCNT_MAX                       (0x000000ffU)

#define CSL_PMMCDWT_DWT_LSUCNT_RESETVAL                         (0x00000000U)

/* DWT_FOLDCNT */

#define CSL_PMMCDWT_DWT_FOLDCNT_FOLDCNT_MASK                    (0x000000FFU)
#define CSL_PMMCDWT_DWT_FOLDCNT_FOLDCNT_SHIFT                   (0U)
#define CSL_PMMCDWT_DWT_FOLDCNT_FOLDCNT_RESETVAL                (0x00000000U)
#define CSL_PMMCDWT_DWT_FOLDCNT_FOLDCNT_MAX                     (0x000000ffU)

#define CSL_PMMCDWT_DWT_FOLDCNT_RESETVAL                        (0x00000000U)

/* DWT_PCSR */

#define CSL_PMMCDWT_DWT_PCSR_COMP_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCDWT_DWT_PCSR_COMP_SHIFT                         (0U)
#define CSL_PMMCDWT_DWT_PCSR_COMP_RESETVAL                      (0x00000000U)
#define CSL_PMMCDWT_DWT_PCSR_COMP_MAX                           (0xffffffffU)

#define CSL_PMMCDWT_DWT_PCSR_RESETVAL                           (0x00000000U)

/* PID4 */

#define CSL_PMMCDWT_PID4_KB4COUNT_MASK                          (0x000000F0U)
#define CSL_PMMCDWT_PID4_KB4COUNT_SHIFT                         (4U)
#define CSL_PMMCDWT_PID4_KB4COUNT_RESETVAL                      (0x00000000U)
#define CSL_PMMCDWT_PID4_KB4COUNT_MAX                           (0x0000000fU)

#define CSL_PMMCDWT_PID4_JEP106CONTINUATIONCODE_MASK            (0x0000000FU)
#define CSL_PMMCDWT_PID4_JEP106CONTINUATIONCODE_SHIFT           (0U)
#define CSL_PMMCDWT_PID4_JEP106CONTINUATIONCODE_RESETVAL        (0x00000004U)
#define CSL_PMMCDWT_PID4_JEP106CONTINUATIONCODE_MAX             (0x0000000fU)

#define CSL_PMMCDWT_PID4_RESETVAL                               (0x00000004U)

/* PID5 */

#define CSL_PMMCDWT_PID5_RESETVAL                               (0x00000000U)

/* PID6 */

#define CSL_PMMCDWT_PID6_RESETVAL                               (0x00000000U)

/* PID7 */

#define CSL_PMMCDWT_PID7_RESETVAL                               (0x00000000U)

/* PID0 */

#define CSL_PMMCDWT_PID0_PARTNUMBER_MASK                        (0x000000FFU)
#define CSL_PMMCDWT_PID0_PARTNUMBER_SHIFT                       (0U)
#define CSL_PMMCDWT_PID0_PARTNUMBER_RESETVAL                    (0x00000002U)
#define CSL_PMMCDWT_PID0_PARTNUMBER_MAX                         (0x000000ffU)

#define CSL_PMMCDWT_PID0_RESETVAL                               (0x00000002U)

/* PID1 */

#define CSL_PMMCDWT_PID1_PARTNUMBER_MASK                        (0x0000FF00U)
#define CSL_PMMCDWT_PID1_PARTNUMBER_SHIFT                       (8U)
#define CSL_PMMCDWT_PID1_PARTNUMBER_RESETVAL                    (0x00000000U)
#define CSL_PMMCDWT_PID1_PARTNUMBER_MAX                         (0x000000ffU)

#define CSL_PMMCDWT_PID1_JEP106IDCODE_MASK                      (0x000000F0U)
#define CSL_PMMCDWT_PID1_JEP106IDCODE_SHIFT                     (4U)
#define CSL_PMMCDWT_PID1_JEP106IDCODE_RESETVAL                  (0x0000000bU)
#define CSL_PMMCDWT_PID1_JEP106IDCODE_MAX                       (0x0000000fU)

#define CSL_PMMCDWT_PID1_RESETVAL                               (0x000000b0U)

/* PID2 */

#define CSL_PMMCDWT_PID2_JEP106IDCODE_MASK                      (0x00000007U)
#define CSL_PMMCDWT_PID2_JEP106IDCODE_SHIFT                     (0U)
#define CSL_PMMCDWT_PID2_JEP106IDCODE_RESETVAL                  (0x00000003U)
#define CSL_PMMCDWT_PID2_JEP106IDCODE_MAX                       (0x00000007U)

#define CSL_PMMCDWT_PID2_REVISION_MASK                          (0x000000F0U)
#define CSL_PMMCDWT_PID2_REVISION_SHIFT                         (4U)
#define CSL_PMMCDWT_PID2_REVISION_RESETVAL                      (0x00000003U)
#define CSL_PMMCDWT_PID2_REVISION_MAX                           (0x0000000fU)

#define CSL_PMMCDWT_PID2_JEDECASSIGNEDIDFIELDS_MASK             (0x00000008U)
#define CSL_PMMCDWT_PID2_JEDECASSIGNEDIDFIELDS_SHIFT            (3U)
#define CSL_PMMCDWT_PID2_JEDECASSIGNEDIDFIELDS_RESETVAL         (0x00000001U)
#define CSL_PMMCDWT_PID2_JEDECASSIGNEDIDFIELDS_MAX              (0x00000001U)

#define CSL_PMMCDWT_PID2_RESETVAL                               (0x0000003bU)

/* PID3 */

#define CSL_PMMCDWT_PID3_CUSTOMERMODIFIEDBLOCK_MASK             (0x0000000FU)
#define CSL_PMMCDWT_PID3_CUSTOMERMODIFIEDBLOCK_SHIFT            (0U)
#define CSL_PMMCDWT_PID3_CUSTOMERMODIFIEDBLOCK_RESETVAL         (0x00000000U)
#define CSL_PMMCDWT_PID3_CUSTOMERMODIFIEDBLOCK_MAX              (0x0000000fU)

#define CSL_PMMCDWT_PID3_REVANDMINORREVISIONFIELD_MASK          (0x000000F0U)
#define CSL_PMMCDWT_PID3_REVANDMINORREVISIONFIELD_SHIFT         (4U)
#define CSL_PMMCDWT_PID3_REVANDMINORREVISIONFIELD_RESETVAL      (0x00000000U)
#define CSL_PMMCDWT_PID3_REVANDMINORREVISIONFIELD_MAX           (0x0000000fU)

#define CSL_PMMCDWT_PID3_RESETVAL                               (0x00000000U)

/* CID0 */

#define CSL_PMMCDWT_CID0_PREAMBLE_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCDWT_CID0_PREAMBLE_SHIFT                         (0U)
#define CSL_PMMCDWT_CID0_PREAMBLE_RESETVAL                      (0x0000000dU)
#define CSL_PMMCDWT_CID0_PREAMBLE_MAX                           (0xffffffffU)

#define CSL_PMMCDWT_CID0_RESETVAL                               (0x0000000dU)

/* CID1 */

#define CSL_PMMCDWT_CID1_COMPONENTCLASS_MASK                    (0x000000F0U)
#define CSL_PMMCDWT_CID1_COMPONENTCLASS_SHIFT                   (4U)
#define CSL_PMMCDWT_CID1_COMPONENTCLASS_RESETVAL                (0x0000000eU)
#define CSL_PMMCDWT_CID1_COMPONENTCLASS_MAX                     (0x0000000fU)

#define CSL_PMMCDWT_CID1_PREAMBLE_MASK                          (0x0000000FU)
#define CSL_PMMCDWT_CID1_PREAMBLE_SHIFT                         (0U)
#define CSL_PMMCDWT_CID1_PREAMBLE_RESETVAL                      (0x00000000U)
#define CSL_PMMCDWT_CID1_PREAMBLE_MAX                           (0x0000000fU)

#define CSL_PMMCDWT_CID1_RESETVAL                               (0x000000e0U)

/* CID2 */

#define CSL_PMMCDWT_CID2_PREAMBLE_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCDWT_CID2_PREAMBLE_SHIFT                         (0U)
#define CSL_PMMCDWT_CID2_PREAMBLE_RESETVAL                      (0x00000005U)
#define CSL_PMMCDWT_CID2_PREAMBLE_MAX                           (0xffffffffU)

#define CSL_PMMCDWT_CID2_RESETVAL                               (0x00000005U)

/* CID3 */

#define CSL_PMMCDWT_CID3_PREAMBLE_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCDWT_CID3_PREAMBLE_SHIFT                         (0U)
#define CSL_PMMCDWT_CID3_PREAMBLE_RESETVAL                      (0x000000b1U)
#define CSL_PMMCDWT_CID3_PREAMBLE_MAX                           (0xffffffffU)

#define CSL_PMMCDWT_CID3_RESETVAL                               (0x000000b1U)

#ifdef __cplusplus
}
#endif
#endif
