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
#ifndef CSLR_ICSSM_IEP_H_
#define CSLR_ICSSM_IEP_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for iepaddressBlockTable
**************************************************************************/
typedef struct {
    volatile Uint32 GLOBAL_CFG;
    volatile Uint32 GLOBAL_STATUS;
    volatile Uint32 COMPEN;
    volatile Uint32 COUNT;
    volatile Uint32 CAP_CFG;
    volatile Uint32 CAP_STATUS;
    volatile Uint32 CAPR0;
    volatile Uint32 CAPR1;
    volatile Uint32 CAPR2;
    volatile Uint32 CAPR3;
    volatile Uint32 CAPR4;
    volatile Uint32 CAPR5;
    volatile Uint32 CAPR6;
    volatile Uint32 CAPF6;
    volatile Uint32 CAPR7;
    volatile Uint32 CAPF7;
    volatile Uint32 CMP_CFG;
    volatile Uint32 CMP_STATUS;
    volatile Uint32 CMP0;
    volatile Uint32 CMP1;
    volatile Uint32 CMP2;
    volatile Uint32 CMP3;
    volatile Uint32 CMP4;
    volatile Uint32 CMP5;
    volatile Uint32 CMP6;
    volatile Uint32 CMP7;
    volatile Uint8  RSVD0[24];
    volatile Uint32 RXIPG0;
    volatile Uint32 RXIPG1;
    volatile Uint8  RSVD1[120];
    volatile Uint32 SYNC_CTRL;
    volatile Uint32 SYNC_FIRST_STAT;
    volatile Uint32 SYNC0_STAT;
    volatile Uint32 SYNC1_STAT;
    volatile Uint32 SYNC_PWIDTH;
    volatile Uint32 SYNC0_PERIOD;
    volatile Uint32 SYNC1_DELAY;
    volatile Uint32 SYNC_START;
    volatile Uint8  RSVD2[224];
    volatile Uint32 WD_PREDIV;
    volatile Uint32 PDI_WD_TIM;
    volatile Uint32 PD_WD_TIM;
    volatile Uint32 WD_STATUS;
    volatile Uint32 WD_EXP_CNT;
    volatile Uint32 WD_CTRL;
    volatile Uint8  RSVD3[232];
    volatile Uint32 DIGIO_CTRL;
    volatile Uint32 DIGIO_STATUS;
    volatile Uint32 DIGIO_DATA_IN;
    volatile Uint32 DIGIO_DATA_IN_RAW;
    volatile Uint32 DIGIO_DATA_OUT;
    volatile Uint32 DIGIO_DATA_OUT_EN;
    volatile Uint32 DIGIO_EXP;
} CSL_icssm_iepRegs;


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_ICSSM_IEP_GLOBAL_CFG                                (0x0U)
#define CSL_ICSSM_IEP_GLOBAL_STATUS                             (0x4U)
#define CSL_ICSSM_IEP_COMPEN                                    (0x8U)
#define CSL_ICSSM_IEP_COUNT                                     (0xCU)
#define CSL_ICSSM_IEP_CAP_CFG                                   (0x10U)
#define CSL_ICSSM_IEP_CAP_STATUS                                (0x14U)
#define CSL_ICSSM_IEP_CAPR0                                     (0x18U)
#define CSL_ICSSM_IEP_CAPR1                                     (0x1CU)
#define CSL_ICSSM_IEP_CAPR2                                     (0x20U)
#define CSL_ICSSM_IEP_CAPR3                                     (0x24U)
#define CSL_ICSSM_IEP_CAPR4                                     (0x28U)
#define CSL_ICSSM_IEP_CAPR5                                     (0x2CU)
#define CSL_ICSSM_IEP_CAPR6                                     (0x30U)
#define CSL_ICSSM_IEP_CAPF6                                     (0x34U)
#define CSL_ICSSM_IEP_CAPR7                                     (0x38U)
#define CSL_ICSSM_IEP_CAPF7                                     (0x3CU)
#define CSL_ICSSM_IEP_CMP_CFG                                   (0x40U)
#define CSL_ICSSM_IEP_CMP_STATUS                                (0x44U)
#define CSL_ICSSM_IEP_CMP0                                      (0x48U)
#define CSL_ICSSM_IEP_CMP1                                      (0x4CU)
#define CSL_ICSSM_IEP_CMP2                                      (0x50U)
#define CSL_ICSSM_IEP_CMP3                                      (0x54U)
#define CSL_ICSSM_IEP_CMP4                                      (0x58U)
#define CSL_ICSSM_IEP_CMP5                                      (0x5CU)
#define CSL_ICSSM_IEP_CMP6                                      (0x60U)
#define CSL_ICSSM_IEP_CMP7                                      (0x64U)
#define CSL_ICSSM_IEP_RXIPG0                                    (0x80U)
#define CSL_ICSSM_IEP_RXIPG1                                    (0x84U)
#define CSL_ICSSM_IEP_SYNC_CTRL                                 (0x100U)
#define CSL_ICSSM_IEP_SYNC_FIRST_STAT                           (0x104U)
#define CSL_ICSSM_IEP_SYNC0_STAT                                (0x108U)
#define CSL_ICSSM_IEP_SYNC1_STAT                                (0x10CU)
#define CSL_ICSSM_IEP_SYNC_PWIDTH                               (0x110U)
#define CSL_ICSSM_IEP_SYNC0_PERIOD                              (0x114U)
#define CSL_ICSSM_IEP_SYNC1_DELAY                               (0x118U)
#define CSL_ICSSM_IEP_SYNC_START                                (0x11CU)
#define CSL_ICSSM_IEP_WD_PREDIV                                 (0x200U)
#define CSL_ICSSM_IEP_PDI_WD_TIM                                (0x204U)
#define CSL_ICSSM_IEP_PD_WD_TIM                                 (0x208U)
#define CSL_ICSSM_IEP_WD_STATUS                                 (0x20CU)
#define CSL_ICSSM_IEP_WD_EXP_CNT                                (0x210U)
#define CSL_ICSSM_IEP_WD_CTRL                                   (0x214U)
#define CSL_ICSSM_IEP_DIGIO_CTRL                                (0x300U)
#define CSL_ICSSM_IEP_DIGIO_STATUS                              (0x304U)
#define CSL_ICSSM_IEP_DIGIO_DATA_IN                             (0x308U)
#define CSL_ICSSM_IEP_DIGIO_DATA_IN_RAW                         (0x30CU)
#define CSL_ICSSM_IEP_DIGIO_DATA_OUT                            (0x310U)
#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_EN                         (0x314U)
#define CSL_ICSSM_IEP_DIGIO_EXP                                 (0x318U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* GLOBAL_CFG */

#define CSL_ICSSM_IEP_GLOBAL_CFG_CMP_INC_MASK                   (0x000FFF00U)
#define CSL_ICSSM_IEP_GLOBAL_CFG_CMP_INC_SHIFT                  (0x00000008U)
#define CSL_ICSSM_IEP_GLOBAL_CFG_CMP_INC_RESETVAL               (0x00000005U)
#define CSL_ICSSM_IEP_GLOBAL_CFG_CMP_INC_MAX                    (0x00000fffU)

#define CSL_ICSSM_IEP_GLOBAL_CFG_DEFAULT_INC_MASK               (0x000000F0U)
#define CSL_ICSSM_IEP_GLOBAL_CFG_DEFAULT_INC_SHIFT              (0x00000004U)
#define CSL_ICSSM_IEP_GLOBAL_CFG_DEFAULT_INC_RESETVAL           (0x00000005U)
#define CSL_ICSSM_IEP_GLOBAL_CFG_DEFAULT_INC_MAX                (0x0000000fU)

#define CSL_ICSSM_IEP_GLOBAL_CFG_CNT_ENABLE_MASK                (0x00000001U)
#define CSL_ICSSM_IEP_GLOBAL_CFG_CNT_ENABLE_SHIFT               (0x00000000U)
#define CSL_ICSSM_IEP_GLOBAL_CFG_CNT_ENABLE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_IEP_GLOBAL_CFG_CNT_ENABLE_MAX                 (0x00000001U)

#define CSL_ICSSM_IEP_GLOBAL_CFG_RESETVAL                       (0x00000550U)

/* GLOBAL_STATUS */

#define CSL_ICSSM_IEP_GLOBAL_STATUS_CNT_OVF_MASK                (0x00000001U)
#define CSL_ICSSM_IEP_GLOBAL_STATUS_CNT_OVF_SHIFT               (0x00000000U)
#define CSL_ICSSM_IEP_GLOBAL_STATUS_CNT_OVF_RESETVAL            (0x00000000U)
#define CSL_ICSSM_IEP_GLOBAL_STATUS_CNT_OVF_MAX                 (0x00000001U)

#define CSL_ICSSM_IEP_GLOBAL_STATUS_RESETVAL                    (0x00000000U)

/* COMPEN */

#define CSL_ICSSM_IEP_COMPEN_COMPEN_CNT_MASK                    (0x007FFFFFU)
#define CSL_ICSSM_IEP_COMPEN_COMPEN_CNT_SHIFT                   (0x00000000U)
#define CSL_ICSSM_IEP_COMPEN_COMPEN_CNT_RESETVAL                (0x00000000U)
#define CSL_ICSSM_IEP_COMPEN_COMPEN_CNT_MAX                     (0x007fffffU)

#define CSL_ICSSM_IEP_COMPEN_RESETVAL                           (0x00000000U)

/* COUNT */

#define CSL_ICSSM_IEP_COUNT_COUNT_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_COUNT_COUNT_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_COUNT_COUNT_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_COUNT_COUNT_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_COUNT_RESETVAL                            (0x00000000U)

/* CAP_CFG */

#define CSL_ICSSM_IEP_CAP_CFG_CAP_1ST_EVENT_EN_MASK             (0x0000003FU)
#define CSL_ICSSM_IEP_CAP_CFG_CAP_1ST_EVENT_EN_SHIFT            (0x00000000U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP_1ST_EVENT_EN_RESETVAL         (0x00000000U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP_1ST_EVENT_EN_MAX              (0x0000003fU)

#define CSL_ICSSM_IEP_CAP_CFG_CAP6R_1ST_EVENT_EN_MASK           (0x00000040U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP6R_1ST_EVENT_EN_SHIFT          (0x00000006U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP6R_1ST_EVENT_EN_RESETVAL       (0x00000000U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP6R_1ST_EVENT_EN_MAX            (0x00000001U)

#define CSL_ICSSM_IEP_CAP_CFG_CAP6F_1ST_EVENT_EN_MASK           (0x00000080U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP6F_1ST_EVENT_EN_SHIFT          (0x00000007U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP6F_1ST_EVENT_EN_RESETVAL       (0x00000000U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP6F_1ST_EVENT_EN_MAX            (0x00000001U)

#define CSL_ICSSM_IEP_CAP_CFG_CAP7R_1ST_EVENT_EN_MASK           (0x00000100U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP7R_1ST_EVENT_EN_SHIFT          (0x00000008U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP7R_1ST_EVENT_EN_RESETVAL       (0x00000000U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP7R_1ST_EVENT_EN_MAX            (0x00000001U)

#define CSL_ICSSM_IEP_CAP_CFG_CAP7F_1ST_EVENT_EN_MASK           (0x00000200U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP7F_1ST_EVENT_EN_SHIFT          (0x00000009U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP7F_1ST_EVENT_EN_RESETVAL       (0x00000000U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP7F_1ST_EVENT_EN_MAX            (0x00000001U)

#define CSL_ICSSM_IEP_CAP_CFG_CAP_ASYNC_EN_MASK                 (0x0003FC00U)
#define CSL_ICSSM_IEP_CAP_CFG_CAP_ASYNC_EN_SHIFT                (0x0000000AU)
#define CSL_ICSSM_IEP_CAP_CFG_CAP_ASYNC_EN_RESETVAL             (0x0000007fU)
#define CSL_ICSSM_IEP_CAP_CFG_CAP_ASYNC_EN_MAX                  (0x000000ffU)

#define CSL_ICSSM_IEP_CAP_CFG_RESETVAL                          (0x0001fc00U)

/* CAP_STATUS */

#define CSL_ICSSM_IEP_CAP_STATUS_CAP_RAW_MASK                   (0x00FF0000U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAP_RAW_SHIFT                  (0x00000010U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAP_RAW_RESETVAL               (0x00000000U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAP_RAW_MAX                    (0x000000ffU)

#define CSL_ICSSM_IEP_CAP_STATUS_CAP_VALID_MASK                 (0x00000400U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAP_VALID_SHIFT                (0x0000000AU)
#define CSL_ICSSM_IEP_CAP_STATUS_CAP_VALID_RESETVAL             (0x00000000U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAP_VALID_MAX                  (0x00000001U)

#define CSL_ICSSM_IEP_CAP_STATUS_CAPF7_VALID_MASK               (0x00000200U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPF7_VALID_SHIFT              (0x00000009U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPF7_VALID_RESETVAL           (0x00000000U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPF7_VALID_MAX                (0x00000001U)

#define CSL_ICSSM_IEP_CAP_STATUS_CAPR7_VALID_MASK               (0x00000100U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPR7_VALID_SHIFT              (0x00000008U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPR7_VALID_RESETVAL           (0x00000000U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPR7_VALID_MAX                (0x00000001U)

#define CSL_ICSSM_IEP_CAP_STATUS_CAPF6_VALID_MASK               (0x00000080U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPF6_VALID_SHIFT              (0x00000007U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPF6_VALID_RESETVAL           (0x00000000U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPF6_VALID_MAX                (0x00000001U)

#define CSL_ICSSM_IEP_CAP_STATUS_CAPR6_VALID_MASK               (0x00000040U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPR6_VALID_SHIFT              (0x00000006U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPR6_VALID_RESETVAL           (0x00000000U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPR6_VALID_MAX                (0x00000001U)

#define CSL_ICSSM_IEP_CAP_STATUS_CAPR_VALID_MASK                (0x0000003FU)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPR_VALID_SHIFT               (0x00000000U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPR_VALID_RESETVAL            (0x00000000U)
#define CSL_ICSSM_IEP_CAP_STATUS_CAPR_VALID_MAX                 (0x0000003fU)

#define CSL_ICSSM_IEP_CAP_STATUS_RESETVAL                       (0x00000000U)

/* CAPR0 */

#define CSL_ICSSM_IEP_CAPR0_CAPR0_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPR0_CAPR0_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPR0_CAPR0_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPR0_CAPR0_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPR0_RESETVAL                            (0x00000000U)

/* CAPR1 */

#define CSL_ICSSM_IEP_CAPR1_CAPR1_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPR1_CAPR1_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPR1_CAPR1_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPR1_CAPR1_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPR1_RESETVAL                            (0x00000000U)

/* CAPR2 */

#define CSL_ICSSM_IEP_CAPR2_CAPR2_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPR2_CAPR2_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPR2_CAPR2_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPR2_CAPR2_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPR2_RESETVAL                            (0x00000000U)

/* CAPR3 */

#define CSL_ICSSM_IEP_CAPR3_CAPR3_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPR3_CAPR3_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPR3_CAPR3_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPR3_CAPR3_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPR3_RESETVAL                            (0x00000000U)

/* CAPR4 */

#define CSL_ICSSM_IEP_CAPR4_CAPR4_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPR4_CAPR4_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPR4_CAPR4_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPR4_CAPR4_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPR4_RESETVAL                            (0x00000000U)

/* CAPR5 */

#define CSL_ICSSM_IEP_CAPR5_CAPR5_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPR5_CAPR5_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPR5_CAPR5_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPR5_CAPR5_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPR5_RESETVAL                            (0x00000000U)

/* CAPR6 */

#define CSL_ICSSM_IEP_CAPR6_CAPR6_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPR6_CAPR6_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPR6_CAPR6_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPR6_CAPR6_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPR6_RESETVAL                            (0x00000000U)

/* CAPF6 */

#define CSL_ICSSM_IEP_CAPF6_CAPF6_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPF6_CAPF6_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPF6_CAPF6_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPF6_CAPF6_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPF6_RESETVAL                            (0x00000000U)

/* CAPR7 */

#define CSL_ICSSM_IEP_CAPR7_CAPR7_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPR7_CAPR7_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPR7_CAPR7_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPR7_CAPR7_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPR7_RESETVAL                            (0x00000000U)

/* CAPF7 */

#define CSL_ICSSM_IEP_CAPF7_CAPF7_MASK                          (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CAPF7_CAPF7_SHIFT                         (0x00000000U)
#define CSL_ICSSM_IEP_CAPF7_CAPF7_RESETVAL                      (0x00000000U)
#define CSL_ICSSM_IEP_CAPF7_CAPF7_MAX                           (0xffffffffU)

#define CSL_ICSSM_IEP_CAPF7_RESETVAL                            (0x00000000U)

/* CMP_CFG */

#define CSL_ICSSM_IEP_CMP_CFG_CMP_EN_MASK                       (0x000001FEU)
#define CSL_ICSSM_IEP_CMP_CFG_CMP_EN_SHIFT                      (0x00000001U)
#define CSL_ICSSM_IEP_CMP_CFG_CMP_EN_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_IEP_CMP_CFG_CMP_EN_MAX                        (0x000000ffU)

#define CSL_ICSSM_IEP_CMP_CFG_CMP0_RST_CNT_EN_MASK              (0x00000001U)
#define CSL_ICSSM_IEP_CMP_CFG_CMP0_RST_CNT_EN_SHIFT             (0x00000000U)
#define CSL_ICSSM_IEP_CMP_CFG_CMP0_RST_CNT_EN_RESETVAL          (0x00000000U)
#define CSL_ICSSM_IEP_CMP_CFG_CMP0_RST_CNT_EN_MAX               (0x00000001U)

#define CSL_ICSSM_IEP_CMP_CFG_RESETVAL                          (0x00000000U)

/* CMP_STATUS */

#define CSL_ICSSM_IEP_CMP_STATUS_CMP_HIT_MASK                   (0x000000FFU)
#define CSL_ICSSM_IEP_CMP_STATUS_CMP_HIT_SHIFT                  (0x00000000U)
#define CSL_ICSSM_IEP_CMP_STATUS_CMP_HIT_RESETVAL               (0x00000000U)
#define CSL_ICSSM_IEP_CMP_STATUS_CMP_HIT_MAX                    (0x000000ffU)

#define CSL_ICSSM_IEP_CMP_STATUS_RESETVAL                       (0x00000000U)

/* CMP0 */

#define CSL_ICSSM_IEP_CMP0_CMP0_MASK                            (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CMP0_CMP0_SHIFT                           (0x00000000U)
#define CSL_ICSSM_IEP_CMP0_CMP0_RESETVAL                        (0x00000000U)
#define CSL_ICSSM_IEP_CMP0_CMP0_MAX                             (0xffffffffU)

#define CSL_ICSSM_IEP_CMP0_RESETVAL                             (0x00000000U)

/* CMP1 */

#define CSL_ICSSM_IEP_CMP1_CMP1_MASK                            (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CMP1_CMP1_SHIFT                           (0x00000000U)
#define CSL_ICSSM_IEP_CMP1_CMP1_RESETVAL                        (0x00000000U)
#define CSL_ICSSM_IEP_CMP1_CMP1_MAX                             (0xffffffffU)

#define CSL_ICSSM_IEP_CMP1_RESETVAL                             (0x00000000U)

/* CMP2 */

#define CSL_ICSSM_IEP_CMP2_CMP2_MASK                            (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CMP2_CMP2_SHIFT                           (0x00000000U)
#define CSL_ICSSM_IEP_CMP2_CMP2_RESETVAL                        (0x00000000U)
#define CSL_ICSSM_IEP_CMP2_CMP2_MAX                             (0xffffffffU)

#define CSL_ICSSM_IEP_CMP2_RESETVAL                             (0x00000000U)

/* CMP3 */

#define CSL_ICSSM_IEP_CMP3_CMP3_MASK                            (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CMP3_CMP3_SHIFT                           (0x00000000U)
#define CSL_ICSSM_IEP_CMP3_CMP3_RESETVAL                        (0x00000000U)
#define CSL_ICSSM_IEP_CMP3_CMP3_MAX                             (0xffffffffU)

#define CSL_ICSSM_IEP_CMP3_RESETVAL                             (0x00000000U)

/* CMP4 */

#define CSL_ICSSM_IEP_CMP4_CMP4_MASK                            (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CMP4_CMP4_SHIFT                           (0x00000000U)
#define CSL_ICSSM_IEP_CMP4_CMP4_RESETVAL                        (0x00000000U)
#define CSL_ICSSM_IEP_CMP4_CMP4_MAX                             (0xffffffffU)

#define CSL_ICSSM_IEP_CMP4_RESETVAL                             (0x00000000U)

/* CMP5 */

#define CSL_ICSSM_IEP_CMP5_CMP5_MASK                            (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CMP5_CMP5_SHIFT                           (0x00000000U)
#define CSL_ICSSM_IEP_CMP5_CMP5_RESETVAL                        (0x00000000U)
#define CSL_ICSSM_IEP_CMP5_CMP5_MAX                             (0xffffffffU)

#define CSL_ICSSM_IEP_CMP5_RESETVAL                             (0x00000000U)

/* CMP6 */

#define CSL_ICSSM_IEP_CMP6_CMP6_MASK                            (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CMP6_CMP6_SHIFT                           (0x00000000U)
#define CSL_ICSSM_IEP_CMP6_CMP6_RESETVAL                        (0x00000000U)
#define CSL_ICSSM_IEP_CMP6_CMP6_MAX                             (0xffffffffU)

#define CSL_ICSSM_IEP_CMP6_RESETVAL                             (0x00000000U)

/* CMP7 */

#define CSL_ICSSM_IEP_CMP7_CMP7_MASK                            (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_CMP7_CMP7_SHIFT                           (0x00000000U)
#define CSL_ICSSM_IEP_CMP7_CMP7_RESETVAL                        (0x00000000U)
#define CSL_ICSSM_IEP_CMP7_CMP7_MAX                             (0xffffffffU)

#define CSL_ICSSM_IEP_CMP7_RESETVAL                             (0x00000000U)

/* RXIPG0 */

#define CSL_ICSSM_IEP_RXIPG0_RX_MIN_IPG_MASK                    (0xFFFF0000U)
#define CSL_ICSSM_IEP_RXIPG0_RX_MIN_IPG_SHIFT                   (0x00000010U)
#define CSL_ICSSM_IEP_RXIPG0_RX_MIN_IPG_RESETVAL                (0x0000ffffU)
#define CSL_ICSSM_IEP_RXIPG0_RX_MIN_IPG_MAX                     (0x0000ffffU)

#define CSL_ICSSM_IEP_RXIPG0_RX_IPG_MASK                        (0x0000FFFFU)
#define CSL_ICSSM_IEP_RXIPG0_RX_IPG_SHIFT                       (0x00000000U)
#define CSL_ICSSM_IEP_RXIPG0_RX_IPG_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_IEP_RXIPG0_RX_IPG_MAX                         (0x0000ffffU)

#define CSL_ICSSM_IEP_RXIPG0_RESETVAL                           (0xffff0000U)

/* RXIPG1 */

#define CSL_ICSSM_IEP_RXIPG1_RX_MIN_IPG_MASK                    (0xFFFF0000U)
#define CSL_ICSSM_IEP_RXIPG1_RX_MIN_IPG_SHIFT                   (0x00000010U)
#define CSL_ICSSM_IEP_RXIPG1_RX_MIN_IPG_RESETVAL                (0x0000ffffU)
#define CSL_ICSSM_IEP_RXIPG1_RX_MIN_IPG_MAX                     (0x0000ffffU)

#define CSL_ICSSM_IEP_RXIPG1_RX_IPG_MASK                        (0x0000FFFFU)
#define CSL_ICSSM_IEP_RXIPG1_RX_IPG_SHIFT                       (0x00000000U)
#define CSL_ICSSM_IEP_RXIPG1_RX_IPG_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_IEP_RXIPG1_RX_IPG_MAX                         (0x0000ffffU)

#define CSL_ICSSM_IEP_RXIPG1_RESETVAL                           (0xffff0000U)

/* SYNC_CTRL */

#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_IND_EN_MASK               (0x00000100U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_IND_EN_SHIFT              (0x00000008U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_IND_EN_RESETVAL           (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_IND_EN_MAX                (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_CYCLIC_EN_MASK            (0x00000080U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_CYCLIC_EN_SHIFT           (0x00000007U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_CYCLIC_EN_RESETVAL        (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_CYCLIC_EN_MAX             (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_ACK_EN_MASK               (0x00000040U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_ACK_EN_SHIFT              (0x00000006U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_ACK_EN_RESETVAL           (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_ACK_EN_MAX                (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_CYCLIC_EN_MASK            (0x00000020U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_CYCLIC_EN_SHIFT           (0x00000005U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_CYCLIC_EN_RESETVAL        (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_CYCLIC_EN_MAX             (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_ACK_EN_MASK               (0x00000010U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_ACK_EN_SHIFT              (0x00000004U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_ACK_EN_RESETVAL           (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_ACK_EN_MAX                (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_EN_MASK                   (0x00000004U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_EN_SHIFT                  (0x00000002U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_EN_RESETVAL               (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC1_EN_MAX                    (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_EN_MASK                   (0x00000002U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_EN_SHIFT                  (0x00000001U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_EN_RESETVAL               (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC0_EN_MAX                    (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC_EN_MASK                    (0x00000001U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC_EN_SHIFT                   (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC_EN_RESETVAL                (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_CTRL_SYNC_EN_MAX                     (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_CTRL_RESETVAL                        (0x00000000U)

/* SYNC_FIRST_STAT */

#define CSL_ICSSM_IEP_SYNC_FIRST_STAT_FIRST_SYNC1_MASK          (0x00000002U)
#define CSL_ICSSM_IEP_SYNC_FIRST_STAT_FIRST_SYNC1_SHIFT         (0x00000001U)
#define CSL_ICSSM_IEP_SYNC_FIRST_STAT_FIRST_SYNC1_RESETVAL      (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_FIRST_STAT_FIRST_SYNC1_MAX           (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_FIRST_STAT_FIRST_SYNC0_MASK          (0x00000001U)
#define CSL_ICSSM_IEP_SYNC_FIRST_STAT_FIRST_SYNC0_SHIFT         (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_FIRST_STAT_FIRST_SYNC0_RESETVAL      (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_FIRST_STAT_FIRST_SYNC0_MAX           (0x00000001U)

#define CSL_ICSSM_IEP_SYNC_FIRST_STAT_RESETVAL                  (0x00000000U)

/* SYNC0_STAT */

#define CSL_ICSSM_IEP_SYNC0_STAT_SYNC0_PEND_MASK                (0x00000001U)
#define CSL_ICSSM_IEP_SYNC0_STAT_SYNC0_PEND_SHIFT               (0x00000000U)
#define CSL_ICSSM_IEP_SYNC0_STAT_SYNC0_PEND_RESETVAL            (0x00000000U)
#define CSL_ICSSM_IEP_SYNC0_STAT_SYNC0_PEND_MAX                 (0x00000001U)

#define CSL_ICSSM_IEP_SYNC0_STAT_RESETVAL                       (0x00000000U)

/* SYNC1_STAT */

#define CSL_ICSSM_IEP_SYNC1_STAT_SYNC1_PEND_MASK                (0x00000001U)
#define CSL_ICSSM_IEP_SYNC1_STAT_SYNC1_PEND_SHIFT               (0x00000000U)
#define CSL_ICSSM_IEP_SYNC1_STAT_SYNC1_PEND_RESETVAL            (0x00000000U)
#define CSL_ICSSM_IEP_SYNC1_STAT_SYNC1_PEND_MAX                 (0x00000001U)

#define CSL_ICSSM_IEP_SYNC1_STAT_RESETVAL                       (0x00000000U)

/* SYNC_PWIDTH */

#define CSL_ICSSM_IEP_SYNC_PWIDTH_SYNC_HPW_MASK                 (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_SYNC_PWIDTH_SYNC_HPW_SHIFT                (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_PWIDTH_SYNC_HPW_RESETVAL             (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_PWIDTH_SYNC_HPW_MAX                  (0xffffffffU)

#define CSL_ICSSM_IEP_SYNC_PWIDTH_RESETVAL                      (0x00000000U)

/* SYNC0_PERIOD */

#define CSL_ICSSM_IEP_SYNC0_PERIOD_SYNC0_PERIOD_MASK            (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_SYNC0_PERIOD_SYNC0_PERIOD_SHIFT           (0x00000000U)
#define CSL_ICSSM_IEP_SYNC0_PERIOD_SYNC0_PERIOD_RESETVAL        (0x00000001U)
#define CSL_ICSSM_IEP_SYNC0_PERIOD_SYNC0_PERIOD_MAX             (0xffffffffU)

#define CSL_ICSSM_IEP_SYNC0_PERIOD_RESETVAL                     (0x00000001U)

/* SYNC1_DELAY */

#define CSL_ICSSM_IEP_SYNC1_DELAY_SYNC1_DELAY_MASK              (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_SYNC1_DELAY_SYNC1_DELAY_SHIFT             (0x00000000U)
#define CSL_ICSSM_IEP_SYNC1_DELAY_SYNC1_DELAY_RESETVAL          (0x00000000U)
#define CSL_ICSSM_IEP_SYNC1_DELAY_SYNC1_DELAY_MAX               (0xffffffffU)

#define CSL_ICSSM_IEP_SYNC1_DELAY_RESETVAL                      (0x00000000U)

/* SYNC_START */

#define CSL_ICSSM_IEP_SYNC_START_SYNC_START_MASK                (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_SYNC_START_SYNC_START_SHIFT               (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_START_SYNC_START_RESETVAL            (0x00000000U)
#define CSL_ICSSM_IEP_SYNC_START_SYNC_START_MAX                 (0xffffffffU)

#define CSL_ICSSM_IEP_SYNC_START_RESETVAL                       (0x00000000U)

/* WD_PREDIV */

#define CSL_ICSSM_IEP_WD_PREDIV_PRE_DIV_MASK                    (0x0000FFFFU)
#define CSL_ICSSM_IEP_WD_PREDIV_PRE_DIV_SHIFT                   (0x00000000U)
#define CSL_ICSSM_IEP_WD_PREDIV_PRE_DIV_RESETVAL                (0x00004e20U)
#define CSL_ICSSM_IEP_WD_PREDIV_PRE_DIV_MAX                     (0x0000ffffU)

#define CSL_ICSSM_IEP_WD_PREDIV_RESETVAL                        (0x00004e20U)

/* PDI_WD_TIM */

#define CSL_ICSSM_IEP_PDI_WD_TIM_PDI_WD_TIME_MASK               (0x0000FFFFU)
#define CSL_ICSSM_IEP_PDI_WD_TIM_PDI_WD_TIME_SHIFT              (0x00000000U)
#define CSL_ICSSM_IEP_PDI_WD_TIM_PDI_WD_TIME_RESETVAL           (0x000003e8U)
#define CSL_ICSSM_IEP_PDI_WD_TIM_PDI_WD_TIME_MAX                (0x0000ffffU)

#define CSL_ICSSM_IEP_PDI_WD_TIM_RESETVAL                       (0x000003e8U)

/* PD_WD_TIM */

#define CSL_ICSSM_IEP_PD_WD_TIM_PD_WD_TIME_MASK                 (0x0000FFFFU)
#define CSL_ICSSM_IEP_PD_WD_TIM_PD_WD_TIME_SHIFT                (0x00000000U)
#define CSL_ICSSM_IEP_PD_WD_TIM_PD_WD_TIME_RESETVAL             (0x000003e8U)
#define CSL_ICSSM_IEP_PD_WD_TIM_PD_WD_TIME_MAX                  (0x0000ffffU)

#define CSL_ICSSM_IEP_PD_WD_TIM_RESETVAL                        (0x000003e8U)

/* WD_STATUS */

#define CSL_ICSSM_IEP_WD_STATUS_PDI_WD_STAT_MASK                (0x00010000U)
#define CSL_ICSSM_IEP_WD_STATUS_PDI_WD_STAT_SHIFT               (0x00000010U)
#define CSL_ICSSM_IEP_WD_STATUS_PDI_WD_STAT_RESETVAL            (0x00000001U)
#define CSL_ICSSM_IEP_WD_STATUS_PDI_WD_STAT_MAX                 (0x00000001U)

#define CSL_ICSSM_IEP_WD_STATUS_PD_WD_STAT_MASK                 (0x00000001U)
#define CSL_ICSSM_IEP_WD_STATUS_PD_WD_STAT_SHIFT                (0x00000000U)
#define CSL_ICSSM_IEP_WD_STATUS_PD_WD_STAT_RESETVAL             (0x00000001U)
#define CSL_ICSSM_IEP_WD_STATUS_PD_WD_STAT_MAX                  (0x00000001U)

#define CSL_ICSSM_IEP_WD_STATUS_RESETVAL                        (0x00010001U)

/* WD_EXP_CNT */

#define CSL_ICSSM_IEP_WD_EXP_CNT_PD_EXP_CNT_MASK                (0x0000FF00U)
#define CSL_ICSSM_IEP_WD_EXP_CNT_PD_EXP_CNT_SHIFT               (0x00000008U)
#define CSL_ICSSM_IEP_WD_EXP_CNT_PD_EXP_CNT_RESETVAL            (0x00000000U)
#define CSL_ICSSM_IEP_WD_EXP_CNT_PD_EXP_CNT_MAX                 (0x000000ffU)

#define CSL_ICSSM_IEP_WD_EXP_CNT_PDI_EXP_CNT_MASK               (0x000000FFU)
#define CSL_ICSSM_IEP_WD_EXP_CNT_PDI_EXP_CNT_SHIFT              (0x00000000U)
#define CSL_ICSSM_IEP_WD_EXP_CNT_PDI_EXP_CNT_RESETVAL           (0x00000000U)
#define CSL_ICSSM_IEP_WD_EXP_CNT_PDI_EXP_CNT_MAX                (0x000000ffU)

#define CSL_ICSSM_IEP_WD_EXP_CNT_RESETVAL                       (0x00000000U)

/* WD_CTRL */

#define CSL_ICSSM_IEP_WD_CTRL_PDI_WD_EN_MASK                    (0x00010000U)
#define CSL_ICSSM_IEP_WD_CTRL_PDI_WD_EN_SHIFT                   (0x00000010U)
#define CSL_ICSSM_IEP_WD_CTRL_PDI_WD_EN_RESETVAL                (0x00000000U)
#define CSL_ICSSM_IEP_WD_CTRL_PDI_WD_EN_MAX                     (0x00000001U)

#define CSL_ICSSM_IEP_WD_CTRL_PD_WD_EN_MASK                     (0x00000001U)
#define CSL_ICSSM_IEP_WD_CTRL_PD_WD_EN_SHIFT                    (0x00000000U)
#define CSL_ICSSM_IEP_WD_CTRL_PD_WD_EN_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_IEP_WD_CTRL_PD_WD_EN_MAX                      (0x00000001U)

#define CSL_ICSSM_IEP_WD_CTRL_RESETVAL                          (0x00000000U)

/* DIGIO_CTRL */

#define CSL_ICSSM_IEP_DIGIO_CTRL_OUT_MODE_MASK                  (0x000000C0U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_OUT_MODE_SHIFT                 (0x00000006U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_OUT_MODE_RESETVAL              (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_OUT_MODE_MAX                   (0x00000003U)

#define CSL_ICSSM_IEP_DIGIO_CTRL_IN_MODE_MASK                   (0x00000030U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_IN_MODE_SHIFT                  (0x00000004U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_IN_MODE_RESETVAL               (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_IN_MODE_MAX                    (0x00000003U)

#define CSL_ICSSM_IEP_DIGIO_CTRL_WD_MODE_MASK                   (0x00000008U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_WD_MODE_SHIFT                  (0x00000003U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_WD_MODE_RESETVAL               (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_WD_MODE_MAX                    (0x00000001U)

#define CSL_ICSSM_IEP_DIGIO_CTRL_BIDI_MODE_MASK                 (0x00000004U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_BIDI_MODE_SHIFT                (0x00000002U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_BIDI_MODE_RESETVAL             (0x00000001U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_BIDI_MODE_MAX                  (0x00000001U)

#define CSL_ICSSM_IEP_DIGIO_CTRL_OUTVALID_MODE_MASK             (0x00000002U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_OUTVALID_MODE_SHIFT            (0x00000001U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_OUTVALID_MODE_RESETVAL         (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_OUTVALID_MODE_MAX              (0x00000001U)

#define CSL_ICSSM_IEP_DIGIO_CTRL_OUTVALID_POL_MASK              (0x00000001U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_OUTVALID_POL_SHIFT             (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_OUTVALID_POL_RESETVAL          (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_CTRL_OUTVALID_POL_MAX               (0x00000001U)

#define CSL_ICSSM_IEP_DIGIO_CTRL_RESETVAL                       (0x00000004U)

/* DIGIO_STATUS */

#define CSL_ICSSM_IEP_DIGIO_STATUS_DIGIO_STAT_MASK              (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_DIGIO_STATUS_DIGIO_STAT_SHIFT             (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_STATUS_DIGIO_STAT_RESETVAL          (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_STATUS_DIGIO_STAT_MAX               (0xffffffffU)

#define CSL_ICSSM_IEP_DIGIO_STATUS_RESETVAL                     (0x00000000U)

/* DIGIO_DATA_IN */

#define CSL_ICSSM_IEP_DIGIO_DATA_IN_DATA_IN_MASK                (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_DIGIO_DATA_IN_DATA_IN_SHIFT               (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_DATA_IN_DATA_IN_RESETVAL            (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_DATA_IN_DATA_IN_MAX                 (0xffffffffU)

#define CSL_ICSSM_IEP_DIGIO_DATA_IN_RESETVAL                    (0x00000000U)

/* DIGIO_DATA_IN_RAW */

#define CSL_ICSSM_IEP_DIGIO_DATA_IN_RAW_DATA_IN_RAW_MASK        (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_DIGIO_DATA_IN_RAW_DATA_IN_RAW_SHIFT       (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_DATA_IN_RAW_DATA_IN_RAW_RESETVAL    (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_DATA_IN_RAW_DATA_IN_RAW_MAX         (0xffffffffU)

#define CSL_ICSSM_IEP_DIGIO_DATA_IN_RAW_RESETVAL                (0x00000000U)

/* DIGIO_DATA_OUT */

#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_DATA_OUT_MASK              (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_DATA_OUT_SHIFT             (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_DATA_OUT_RESETVAL          (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_DATA_OUT_MAX               (0xffffffffU)

#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_RESETVAL                   (0x00000000U)

/* DIGIO_DATA_OUT_EN */

#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_EN_DATA_OUT_EN_MASK        (0xFFFFFFFFU)
#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_EN_DATA_OUT_EN_SHIFT       (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_EN_DATA_OUT_EN_RESETVAL    (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_EN_DATA_OUT_EN_MAX         (0xffffffffU)

#define CSL_ICSSM_IEP_DIGIO_DATA_OUT_EN_RESETVAL                (0x00000000U)

/* DIGIO_EXP */

#define CSL_ICSSM_IEP_DIGIO_EXP_EOF_SEL_MASK                    (0x00002000U)
#define CSL_ICSSM_IEP_DIGIO_EXP_EOF_SEL_SHIFT                   (0x0000000DU)
#define CSL_ICSSM_IEP_DIGIO_EXP_EOF_SEL_RESETVAL                (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_EXP_EOF_SEL_MAX                     (0x00000001U)

#define CSL_ICSSM_IEP_DIGIO_EXP_SOF_SEL_MASK                    (0x00001000U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SOF_SEL_SHIFT                   (0x0000000CU)
#define CSL_ICSSM_IEP_DIGIO_EXP_SOF_SEL_RESETVAL                (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SOF_SEL_MAX                     (0x00000001U)

#define CSL_ICSSM_IEP_DIGIO_EXP_SOF_DLY_MASK                    (0x00000F00U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SOF_DLY_SHIFT                   (0x00000008U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SOF_DLY_RESETVAL                (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SOF_DLY_MAX                     (0x0000000fU)

#define CSL_ICSSM_IEP_DIGIO_EXP_OUTVALID_DLY_MASK               (0x000000F0U)
#define CSL_ICSSM_IEP_DIGIO_EXP_OUTVALID_DLY_SHIFT              (0x00000004U)
#define CSL_ICSSM_IEP_DIGIO_EXP_OUTVALID_DLY_RESETVAL           (0x00000002U)
#define CSL_ICSSM_IEP_DIGIO_EXP_OUTVALID_DLY_MAX                (0x0000000fU)

#define CSL_ICSSM_IEP_DIGIO_EXP_SW_OUTVALID_MASK                (0x00000004U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SW_OUTVALID_SHIFT               (0x00000002U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SW_OUTVALID_RESETVAL            (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SW_OUTVALID_MAX                 (0x00000001U)

#define CSL_ICSSM_IEP_DIGIO_EXP_OUTVALID_OVR_EN_MASK            (0x00000002U)
#define CSL_ICSSM_IEP_DIGIO_EXP_OUTVALID_OVR_EN_SHIFT           (0x00000001U)
#define CSL_ICSSM_IEP_DIGIO_EXP_OUTVALID_OVR_EN_RESETVAL        (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_EXP_OUTVALID_OVR_EN_MAX             (0x00000001U)

#define CSL_ICSSM_IEP_DIGIO_EXP_SW_DATA_OUT_UPDATE_MASK         (0x00000001U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SW_DATA_OUT_UPDATE_SHIFT        (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SW_DATA_OUT_UPDATE_RESETVAL     (0x00000000U)
#define CSL_ICSSM_IEP_DIGIO_EXP_SW_DATA_OUT_UPDATE_MAX          (0x00000001U)

#define CSL_ICSSM_IEP_DIGIO_EXP_RESETVAL                        (0x00000020U)

#ifdef __cplusplus
}
#endif
#endif
