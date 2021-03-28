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
#ifndef CSLR_CPTS_H_
#define CSLR_CPTS_H_

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
    volatile Uint32 IDVER_REG;
    volatile Uint32 CONTROL_REG;
    volatile Uint32 RFTCLK_SEL_REG;
    volatile Uint32 TS_PUSH_REG;
    volatile Uint32 TS_LOAD_LOW_VAL_REG;
    volatile Uint32 TS_LOAD_EN_REG;
    volatile Uint32 TS_COMP_LOW_VAL_REG;
    volatile Uint32 TS_COMP_LEN_REG;
    volatile Uint32 INTSTAT_RAW_REG;
    volatile Uint32 INTSTAT_MASKED_REG;
    volatile Uint32 INT_ENABLE_REG;
    volatile Uint32 TS_COMP_NUDGE_REG;
    volatile Uint32 EVENT_POP_REG;
    volatile Uint32 EVENT_0_REG;
    volatile Uint32 EVENT_1_REG;
    volatile Uint32 EVENT_2_REG;
    volatile Uint32 EVENT_3_REG;
    volatile Uint32 TS_LOAD_HIGH_VAL_REG;
    volatile Uint32 TS_COMP_HIGH_VAL_REG;
} CSL_CptsRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Identification and Version Register */
#define CSL_CPTS_IDVER_REG                                      (0x0U)

/* Time Sync Control Register */
#define CSL_CPTS_CONTROL_REG                                    (0x4U)

/* RFTCLK Select Register */
#define CSL_CPTS_RFTCLK_SEL_REG                                 (0x8U)

/* Time Stamp Event Push Register */
#define CSL_CPTS_TS_PUSH_REG                                    (0xCU)

/* Time Stamp Load Low Value Register */
#define CSL_CPTS_TS_LOAD_LOW_VAL_REG                            (0x10U)

/* Time Stamp Load Enable Register */
#define CSL_CPTS_TS_LOAD_EN_REG                                 (0x14U)

/* Time Stamp Comparison Low Value Register */
#define CSL_CPTS_TS_COMP_LOW_VAL_REG                            (0x18U)

/* Time Stamp Comparison Length Register */
#define CSL_CPTS_TS_COMP_LEN_REG                                (0x1CU)

/* Interrupt Status Register Raw */
#define CSL_CPTS_INTSTAT_RAW_REG                                (0x20U)

/* Interrupt Status Register Masked */
#define CSL_CPTS_INTSTAT_MASKED_REG                             (0x24U)

/* Interrupt Enable Register */
#define CSL_CPTS_INT_ENABLE_REG                                 (0x28U)

/* Time Stamp Comparison Nudge Register */
#define CSL_CPTS_TS_COMP_NUDGE_REG                              (0x2CU)

/* Event Pop Register */
#define CSL_CPTS_EVENT_POP_REG                                  (0x30U)

/* Event 0 Register */
#define CSL_CPTS_EVENT_0_REG                                    (0x34U)

/* Event 1 Register */
#define CSL_CPTS_EVENT_1_REG                                    (0x38U)

/* Event 2 Register */
#define CSL_CPTS_EVENT_2_REG                                    (0x3CU)

/* Event 3 Register */
#define CSL_CPTS_EVENT_3_REG                                    (0x40U)

/* Time Stamp Load High Value Register */
#define CSL_CPTS_TS_LOAD_HIGH_VAL_REG                           (0x44U)

/* Time Stamp Comparison High Value Register */
#define CSL_CPTS_TS_COMP_HIGH_VAL_REG                           (0x48U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* IDVER_REG */

#define CSL_CPTS_IDVER_REG_MINOR_VER_MASK                       (0x000000FFU)
#define CSL_CPTS_IDVER_REG_MINOR_VER_SHIFT                      (0U)
#define CSL_CPTS_IDVER_REG_MINOR_VER_RESETVAL                   (0x00000000U)
#define CSL_CPTS_IDVER_REG_MINOR_VER_MAX                        (0x000000ffU)

#define CSL_CPTS_IDVER_REG_MAJOR_VER_MASK                       (0x00000700U)
#define CSL_CPTS_IDVER_REG_MAJOR_VER_SHIFT                      (8U)
#define CSL_CPTS_IDVER_REG_MAJOR_VER_RESETVAL                   (0x00000000U)
#define CSL_CPTS_IDVER_REG_MAJOR_VER_MAX                        (0x00000007U)

#define CSL_CPTS_IDVER_REG_RTL_VER_MASK                         (0x0000F800U)
#define CSL_CPTS_IDVER_REG_RTL_VER_SHIFT                        (11U)
#define CSL_CPTS_IDVER_REG_RTL_VER_RESETVAL                     (0x00000000U)
#define CSL_CPTS_IDVER_REG_RTL_VER_MAX                          (0x0000001fU)

#define CSL_CPTS_IDVER_REG_TX_IDENT_MASK                        (0xFFFF0000U)
#define CSL_CPTS_IDVER_REG_TX_IDENT_SHIFT                       (16U)
#define CSL_CPTS_IDVER_REG_TX_IDENT_RESETVAL                    (0x00000000U)
#define CSL_CPTS_IDVER_REG_TX_IDENT_MAX                         (0x0000ffffU)

#define CSL_CPTS_IDVER_REG_RESETVAL                             (0x00000000U)

/* CONTROL_REG */

#define CSL_CPTS_CONTROL_REG_CPTS_EN_MASK                       (0x00000001U)
#define CSL_CPTS_CONTROL_REG_CPTS_EN_SHIFT                      (0U)
#define CSL_CPTS_CONTROL_REG_CPTS_EN_RESETVAL                   (0x00000000U)
#define CSL_CPTS_CONTROL_REG_CPTS_EN_MAX                        (0x00000001U)

#define CSL_CPTS_CONTROL_REG_INT_TEST_MASK                      (0x00000002U)
#define CSL_CPTS_CONTROL_REG_INT_TEST_SHIFT                     (1U)
#define CSL_CPTS_CONTROL_REG_INT_TEST_RESETVAL                  (0x00000000U)
#define CSL_CPTS_CONTROL_REG_INT_TEST_MAX                       (0x00000001U)

#define CSL_CPTS_CONTROL_REG_TS_COMP_POLARITY_MASK              (0x00000004U)
#define CSL_CPTS_CONTROL_REG_TS_COMP_POLARITY_SHIFT             (2U)
#define CSL_CPTS_CONTROL_REG_TS_COMP_POLARITY_RESETVAL          (0x00000000U)
#define CSL_CPTS_CONTROL_REG_TS_COMP_POLARITY_MAX               (0x00000001U)

#define CSL_CPTS_CONTROL_REG_TSTAMP_EN_MASK                     (0x00000008U)
#define CSL_CPTS_CONTROL_REG_TSTAMP_EN_SHIFT                    (3U)
#define CSL_CPTS_CONTROL_REG_TSTAMP_EN_RESETVAL                 (0x00000000U)
#define CSL_CPTS_CONTROL_REG_TSTAMP_EN_MAX                      (0x00000001U)

#define CSL_CPTS_CONTROL_REG_SEQUENCE_EN_MASK                   (0x00000010U)
#define CSL_CPTS_CONTROL_REG_SEQUENCE_EN_SHIFT                  (4U)
#define CSL_CPTS_CONTROL_REG_SEQUENCE_EN_RESETVAL               (0x00000000U)
#define CSL_CPTS_CONTROL_REG_SEQUENCE_EN_MAX                    (0x00000001U)

#define CSL_CPTS_CONTROL_REG_MODE_MASK                          (0x00000020U)
#define CSL_CPTS_CONTROL_REG_MODE_SHIFT                         (5U)
#define CSL_CPTS_CONTROL_REG_MODE_RESETVAL                      (0x00000000U)
#define CSL_CPTS_CONTROL_REG_MODE_MAX                           (0x00000001U)

#define CSL_CPTS_CONTROL_REG_TS_COMP_TOG_MASK                   (0x00000040U)
#define CSL_CPTS_CONTROL_REG_TS_COMP_TOG_SHIFT                  (6U)
#define CSL_CPTS_CONTROL_REG_TS_COMP_TOG_RESETVAL               (0x00000000U)
#define CSL_CPTS_CONTROL_REG_TS_COMP_TOG_MAX                    (0x00000001U)

#define CSL_CPTS_CONTROL_REG_HW1_TS_PUSH_EN_MASK                (0x00000100U)
#define CSL_CPTS_CONTROL_REG_HW1_TS_PUSH_EN_SHIFT               (8U)
#define CSL_CPTS_CONTROL_REG_HW1_TS_PUSH_EN_RESETVAL            (0x00000000U)
#define CSL_CPTS_CONTROL_REG_HW1_TS_PUSH_EN_MAX                 (0x00000001U)

#define CSL_CPTS_CONTROL_REG_HW2_TS_PUSH_EN_MASK                (0x00000200U)
#define CSL_CPTS_CONTROL_REG_HW2_TS_PUSH_EN_SHIFT               (9U)
#define CSL_CPTS_CONTROL_REG_HW2_TS_PUSH_EN_RESETVAL            (0x00000000U)
#define CSL_CPTS_CONTROL_REG_HW2_TS_PUSH_EN_MAX                 (0x00000001U)

#define CSL_CPTS_CONTROL_REG_HW3_TS_PUSH_EN_MASK                (0x00000400U)
#define CSL_CPTS_CONTROL_REG_HW3_TS_PUSH_EN_SHIFT               (10U)
#define CSL_CPTS_CONTROL_REG_HW3_TS_PUSH_EN_RESETVAL            (0x00000000U)
#define CSL_CPTS_CONTROL_REG_HW3_TS_PUSH_EN_MAX                 (0x00000001U)

#define CSL_CPTS_CONTROL_REG_HW4_TS_PUSH_EN_MASK                (0x00000800U)
#define CSL_CPTS_CONTROL_REG_HW4_TS_PUSH_EN_SHIFT               (11U)
#define CSL_CPTS_CONTROL_REG_HW4_TS_PUSH_EN_RESETVAL            (0x00000000U)
#define CSL_CPTS_CONTROL_REG_HW4_TS_PUSH_EN_MAX                 (0x00000001U)

#define CSL_CPTS_CONTROL_REG_HW5_TS_PUSH_EN_MASK                (0x00001000U)
#define CSL_CPTS_CONTROL_REG_HW5_TS_PUSH_EN_SHIFT               (12U)
#define CSL_CPTS_CONTROL_REG_HW5_TS_PUSH_EN_RESETVAL            (0x00000000U)
#define CSL_CPTS_CONTROL_REG_HW5_TS_PUSH_EN_MAX                 (0x00000001U)

#define CSL_CPTS_CONTROL_REG_HW6_TS_PUSH_EN_MASK                (0x00002000U)
#define CSL_CPTS_CONTROL_REG_HW6_TS_PUSH_EN_SHIFT               (13U)
#define CSL_CPTS_CONTROL_REG_HW6_TS_PUSH_EN_RESETVAL            (0x00000000U)
#define CSL_CPTS_CONTROL_REG_HW6_TS_PUSH_EN_MAX                 (0x00000001U)

#define CSL_CPTS_CONTROL_REG_HW7_TS_PUSH_EN_MASK                (0x00004000U)
#define CSL_CPTS_CONTROL_REG_HW7_TS_PUSH_EN_SHIFT               (14U)
#define CSL_CPTS_CONTROL_REG_HW7_TS_PUSH_EN_RESETVAL            (0x00000000U)
#define CSL_CPTS_CONTROL_REG_HW7_TS_PUSH_EN_MAX                 (0x00000001U)

#define CSL_CPTS_CONTROL_REG_HW8_TS_PUSH_EN_MASK                (0x00008000U)
#define CSL_CPTS_CONTROL_REG_HW8_TS_PUSH_EN_SHIFT               (15U)
#define CSL_CPTS_CONTROL_REG_HW8_TS_PUSH_EN_RESETVAL            (0x00000000U)
#define CSL_CPTS_CONTROL_REG_HW8_TS_PUSH_EN_MAX                 (0x00000001U)

#define CSL_CPTS_CONTROL_REG_TS_SYNC_SEL_MASK                   (0xF0000000U)
#define CSL_CPTS_CONTROL_REG_TS_SYNC_SEL_SHIFT                  (28U)
#define CSL_CPTS_CONTROL_REG_TS_SYNC_SEL_RESETVAL               (0x00000000U)
#define CSL_CPTS_CONTROL_REG_TS_SYNC_SEL_MAX                    (0x0000000fU)

#define CSL_CPTS_CONTROL_REG_RESETVAL                           (0x00000000U)

/* RFTCLK_SEL_REG */

#define CSL_CPTS_RFTCLK_SEL_REG_RFTCLK_SEL_MASK                 (0x0000001FU)
#define CSL_CPTS_RFTCLK_SEL_REG_RFTCLK_SEL_SHIFT                (0U)
#define CSL_CPTS_RFTCLK_SEL_REG_RFTCLK_SEL_RESETVAL             (0x00000000U)
#define CSL_CPTS_RFTCLK_SEL_REG_RFTCLK_SEL_MAX                  (0x0000001fU)

#define CSL_CPTS_RFTCLK_SEL_REG_RESETVAL                        (0x00000000U)

/* TS_PUSH_REG */

#define CSL_CPTS_TS_PUSH_REG_TS_PUSH_MASK                       (0x00000001U)
#define CSL_CPTS_TS_PUSH_REG_TS_PUSH_SHIFT                      (0U)
#define CSL_CPTS_TS_PUSH_REG_TS_PUSH_RESETVAL                   (0x00000000U)
#define CSL_CPTS_TS_PUSH_REG_TS_PUSH_MAX                        (0x00000001U)

#define CSL_CPTS_TS_PUSH_REG_RESETVAL                           (0x00000000U)

/* TS_LOAD_LOW_VAL_REG */

#define CSL_CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL_MASK           (0xFFFFFFFFU)
#define CSL_CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL_SHIFT          (0U)
#define CSL_CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL_RESETVAL       (0x00000000U)
#define CSL_CPTS_TS_LOAD_LOW_VAL_REG_TS_LOAD_VAL_MAX            (0xffffffffU)

#define CSL_CPTS_TS_LOAD_LOW_VAL_REG_RESETVAL                   (0x00000000U)

/* TS_LOAD_EN_REG */

#define CSL_CPTS_TS_LOAD_EN_REG_TS_LOAD_EN_MASK                 (0x00000001U)
#define CSL_CPTS_TS_LOAD_EN_REG_TS_LOAD_EN_SHIFT                (0U)
#define CSL_CPTS_TS_LOAD_EN_REG_TS_LOAD_EN_RESETVAL             (0x00000000U)
#define CSL_CPTS_TS_LOAD_EN_REG_TS_LOAD_EN_MAX                  (0x00000001U)

#define CSL_CPTS_TS_LOAD_EN_REG_RESETVAL                        (0x00000000U)

/* TS_COMP_LOW_VAL_REG */

#define CSL_CPTS_TS_COMP_LOW_VAL_REG_TS_COMP_VAL_MASK           (0xFFFFFFFFU)
#define CSL_CPTS_TS_COMP_LOW_VAL_REG_TS_COMP_VAL_SHIFT          (0U)
#define CSL_CPTS_TS_COMP_LOW_VAL_REG_TS_COMP_VAL_RESETVAL       (0x00000000U)
#define CSL_CPTS_TS_COMP_LOW_VAL_REG_TS_COMP_VAL_MAX            (0xffffffffU)

#define CSL_CPTS_TS_COMP_LOW_VAL_REG_RESETVAL                   (0x00000000U)

/* TS_COMP_LEN_REG */

#define CSL_CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH_MASK            (0x00FFFFFFU)
#define CSL_CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH_SHIFT           (0U)
#define CSL_CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH_RESETVAL        (0x00000000U)
#define CSL_CPTS_TS_COMP_LEN_REG_TS_COMP_LENGTH_MAX             (0x00ffffffU)

#define CSL_CPTS_TS_COMP_LEN_REG_RESETVAL                       (0x00000000U)

/* INTSTAT_RAW_REG */

#define CSL_CPTS_INTSTAT_RAW_REG_TS_PEND_RAW_MASK               (0x00000001U)
#define CSL_CPTS_INTSTAT_RAW_REG_TS_PEND_RAW_SHIFT              (0U)
#define CSL_CPTS_INTSTAT_RAW_REG_TS_PEND_RAW_RESETVAL           (0x00000000U)
#define CSL_CPTS_INTSTAT_RAW_REG_TS_PEND_RAW_MAX                (0x00000001U)

#define CSL_CPTS_INTSTAT_RAW_REG_RESETVAL                       (0x00000000U)

/* INTSTAT_MASKED_REG */

#define CSL_CPTS_INTSTAT_MASKED_REG_TS_PEND_MASK                (0x00000001U)
#define CSL_CPTS_INTSTAT_MASKED_REG_TS_PEND_SHIFT               (0U)
#define CSL_CPTS_INTSTAT_MASKED_REG_TS_PEND_RESETVAL            (0x00000000U)
#define CSL_CPTS_INTSTAT_MASKED_REG_TS_PEND_MAX                 (0x00000001U)

#define CSL_CPTS_INTSTAT_MASKED_REG_RESETVAL                    (0x00000000U)

/* INT_ENABLE_REG */

#define CSL_CPTS_INT_ENABLE_REG_TS_PEND_EN_MASK                 (0x00000001U)
#define CSL_CPTS_INT_ENABLE_REG_TS_PEND_EN_SHIFT                (0U)
#define CSL_CPTS_INT_ENABLE_REG_TS_PEND_EN_RESETVAL             (0x00000000U)
#define CSL_CPTS_INT_ENABLE_REG_TS_PEND_EN_MAX                  (0x00000001U)

#define CSL_CPTS_INT_ENABLE_REG_RESETVAL                        (0x00000000U)

/* TS_COMP_NUDGE_REG */

#define CSL_CPTS_TS_COMP_NUDGE_REG_NUDGE_MASK                   (0x000000FFU)
#define CSL_CPTS_TS_COMP_NUDGE_REG_NUDGE_SHIFT                  (0U)
#define CSL_CPTS_TS_COMP_NUDGE_REG_NUDGE_RESETVAL               (0x00000000U)
#define CSL_CPTS_TS_COMP_NUDGE_REG_NUDGE_MAX                    (0x000000ffU)

#define CSL_CPTS_TS_COMP_NUDGE_REG_RESETVAL                     (0x00000000U)

/* EVENT_POP_REG */

#define CSL_CPTS_EVENT_POP_REG_EVENT_POP_MASK                   (0x00000001U)
#define CSL_CPTS_EVENT_POP_REG_EVENT_POP_SHIFT                  (0U)
#define CSL_CPTS_EVENT_POP_REG_EVENT_POP_RESETVAL               (0x00000000U)
#define CSL_CPTS_EVENT_POP_REG_EVENT_POP_MAX                    (0x00000001U)

#define CSL_CPTS_EVENT_POP_REG_RESETVAL                         (0x00000000U)

/* EVENT_0_REG */

#define CSL_CPTS_EVENT_0_REG_TIME_STAMP_MASK                    (0xFFFFFFFFU)
#define CSL_CPTS_EVENT_0_REG_TIME_STAMP_SHIFT                   (0U)
#define CSL_CPTS_EVENT_0_REG_TIME_STAMP_RESETVAL                (0x00000000U)
#define CSL_CPTS_EVENT_0_REG_TIME_STAMP_MAX                     (0xffffffffU)

#define CSL_CPTS_EVENT_0_REG_RESETVAL                           (0x00000000U)

/* EVENT_1_REG */

#define CSL_CPTS_EVENT_1_REG_SEQUENCE_ID_MASK                   (0x0000FFFFU)
#define CSL_CPTS_EVENT_1_REG_SEQUENCE_ID_SHIFT                  (0U)
#define CSL_CPTS_EVENT_1_REG_SEQUENCE_ID_RESETVAL               (0x00000000U)
#define CSL_CPTS_EVENT_1_REG_SEQUENCE_ID_MAX                    (0x0000ffffU)

#define CSL_CPTS_EVENT_1_REG_MESSAGE_TYPE_MASK                  (0x000F0000U)
#define CSL_CPTS_EVENT_1_REG_MESSAGE_TYPE_SHIFT                 (16U)
#define CSL_CPTS_EVENT_1_REG_MESSAGE_TYPE_RESETVAL              (0x00000000U)
#define CSL_CPTS_EVENT_1_REG_MESSAGE_TYPE_MAX                   (0x0000000fU)

#define CSL_CPTS_EVENT_1_REG_EVENT_TYPE_MASK                    (0x00F00000U)
#define CSL_CPTS_EVENT_1_REG_EVENT_TYPE_SHIFT                   (20U)
#define CSL_CPTS_EVENT_1_REG_EVENT_TYPE_RESETVAL                (0x00000000U)
#define CSL_CPTS_EVENT_1_REG_EVENT_TYPE_MAX                     (0x0000000fU)

#define CSL_CPTS_EVENT_1_REG_PORT_NUMBER_MASK                   (0x1F000000U)
#define CSL_CPTS_EVENT_1_REG_PORT_NUMBER_SHIFT                  (24U)
#define CSL_CPTS_EVENT_1_REG_PORT_NUMBER_RESETVAL               (0x00000000U)
#define CSL_CPTS_EVENT_1_REG_PORT_NUMBER_MAX                    (0x0000001fU)

#define CSL_CPTS_EVENT_1_REG_RESETVAL                           (0x00000000U)

/* EVENT_2_REG */

#define CSL_CPTS_EVENT_2_REG_DOMAIN_MASK                        (0x000000FFU)
#define CSL_CPTS_EVENT_2_REG_DOMAIN_SHIFT                       (0U)
#define CSL_CPTS_EVENT_2_REG_DOMAIN_RESETVAL                    (0x00000000U)
#define CSL_CPTS_EVENT_2_REG_DOMAIN_MAX                         (0x000000ffU)

#define CSL_CPTS_EVENT_2_REG_RESETVAL                           (0x00000000U)

/* EVENT_3_REG */

#define CSL_CPTS_EVENT_3_REG_TIME_STAMP_MASK                    (0xFFFFFFFFU)
#define CSL_CPTS_EVENT_3_REG_TIME_STAMP_SHIFT                   (0U)
#define CSL_CPTS_EVENT_3_REG_TIME_STAMP_RESETVAL                (0x00000000U)
#define CSL_CPTS_EVENT_3_REG_TIME_STAMP_MAX                     (0xffffffffU)

#define CSL_CPTS_EVENT_3_REG_RESETVAL                           (0x00000000U)

/* TS_LOAD_HIGH_VAL_REG */

#define CSL_CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL_MASK          (0xFFFFFFFFU)
#define CSL_CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL_SHIFT         (0U)
#define CSL_CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL_RESETVAL      (0x00000000U)
#define CSL_CPTS_TS_LOAD_HIGH_VAL_REG_TS_LOAD_VAL_MAX           (0xffffffffU)

#define CSL_CPTS_TS_LOAD_HIGH_VAL_REG_RESETVAL                  (0x00000000U)

/* TS_COMP_HIGH_VAL_REG */

#define CSL_CPTS_TS_COMP_HIGH_VAL_REG_TS_COMP_VAL_MASK          (0xFFFFFFFFU)
#define CSL_CPTS_TS_COMP_HIGH_VAL_REG_TS_COMP_VAL_SHIFT         (0U)
#define CSL_CPTS_TS_COMP_HIGH_VAL_REG_TS_COMP_VAL_RESETVAL      (0x00000000U)
#define CSL_CPTS_TS_COMP_HIGH_VAL_REG_TS_COMP_VAL_MAX           (0xffffffffU)

#define CSL_CPTS_TS_COMP_HIGH_VAL_REG_RESETVAL                  (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
