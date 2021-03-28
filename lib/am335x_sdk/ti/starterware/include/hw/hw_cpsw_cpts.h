/*
* hw_cpsw_cpts.h
*
* Register-level header file for CPSW_CPTS
*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
*
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

#ifndef HW_CPSW_CPTS_H_
#define HW_CPSW_CPTS_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CPSW_CPTS_EVT_LOW                                           (0x34U)
#define CPSW_CPTS_PUSH                                              (0xcU)
#define CPSW_CPTS_IDVER                                             (0x0U)
#define CPSW_CPTS_LOAD_VAL                                          (0x10U)
#define CPSW_CPTS_INTSTAT_RAW                                       (0x20U)
#define CPSW_CPTS_EVT_HIGH                                          (0x38U)
#define CPSW_CPTS_LOAD_EN                                           (0x14U)
#define CPSW_CPTS_INT_EN                                            (0x28U)
#define CPSW_CPTS_CTRL                                              (0x4U)
#define CPSW_CPTS_EVT_POP                                           (0x30U)
#define CPSW_CPTS_INTSTAT_MASKED                                    (0x24U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CPSW_CPTS_EVT_LOW_TIME_STAMP_SHIFT                                              (0U)
#define CPSW_CPTS_EVT_LOW_TIME_STAMP_MASK                                               (0xffffffffU)

#define CPSW_CPTS_PUSH_TS_SHIFT                                                         (0U)
#define CPSW_CPTS_PUSH_TS_MASK                                                          (0x00000001U)

#define CPSW_CPTS_IDVER_MINOR_VER_SHIFT                                                 (0U)
#define CPSW_CPTS_IDVER_MINOR_VER_MASK                                                  (0x000000ffU)

#define CPSW_CPTS_IDVER_MAJOR_VER_SHIFT                                                 (8U)
#define CPSW_CPTS_IDVER_MAJOR_VER_MASK                                                  (0x00000700U)

#define CPSW_CPTS_IDVER_RTL_VER_SHIFT                                                   (11U)
#define CPSW_CPTS_IDVER_RTL_VER_MASK                                                    (0x0000f800U)

#define CPSW_CPTS_IDVER_TX_IDENT_SHIFT                                                  (16U)
#define CPSW_CPTS_IDVER_TX_IDENT_MASK                                                   (0xffff0000U)

#define CPSW_CPTS_LOAD_VAL_TS_SHIFT                                                     (0U)
#define CPSW_CPTS_LOAD_VAL_TS_MASK                                                      (0xffffffffU)

#define CPSW_CPTS_INTSTAT_RAW_TS_PEND_SHIFT                                             (0U)
#define CPSW_CPTS_INTSTAT_RAW_TS_PEND_MASK                                              (0x00000001U)

#define CPSW_CPTS_EVT_HIGH_SEQUENCE_ID_SHIFT                                            (0U)
#define CPSW_CPTS_EVT_HIGH_SEQUENCE_ID_MASK                                             (0x0000ffffU)

#define CPSW_CPTS_EVT_HIGH_MESSAGE_TYPE_SHIFT                                           (16U)
#define CPSW_CPTS_EVT_HIGH_MESSAGE_TYPE_MASK                                            (0x000f0000U)

#define CPSW_CPTS_EVT_HIGH_TYPE_SHIFT                                                   (20U)
#define CPSW_CPTS_EVT_HIGH_TYPE_MASK                                                    (0x00f00000U)

#define CPSW_CPTS_EVT_HIGH_PORT_NUMBER_SHIFT                                            (24U)
#define CPSW_CPTS_EVT_HIGH_PORT_NUMBER_MASK                                             (0x1f000000U)

#define CPSW_CPTS_LOAD_EN_TS_SHIFT                                                      (0U)
#define CPSW_CPTS_LOAD_EN_TS_MASK                                                       (0x00000001U)

#define CPSW_CPTS_INT_EN_TS_PEND_SHIFT                                                  (0U)
#define CPSW_CPTS_INT_EN_TS_PEND_MASK                                                   (0x00000001U)

#define CPSW_CPTS_CTRL_EN_SHIFT                                                         (0U)
#define CPSW_CPTS_CTRL_EN_MASK                                                          (0x00000001U)

#define CPSW_CPTS_CTRL_INT_TEST_SHIFT                                                   (1U)
#define CPSW_CPTS_CTRL_INT_TEST_MASK                                                    (0x00000002U)

#define CPSW_CPTS_CTRL_HW1_TS_PUSH_EN_SHIFT                                             (8U)
#define CPSW_CPTS_CTRL_HW1_TS_PUSH_EN_MASK                                              (0x00000100U)

#define CPSW_CPTS_CTRL_HW2_TS_PUSH_EN_SHIFT                                             (9U)
#define CPSW_CPTS_CTRL_HW2_TS_PUSH_EN_MASK                                              (0x00000200U)

#define CPSW_CPTS_CTRL_HW3_TS_PUSH_EN_SHIFT                                             (10U)
#define CPSW_CPTS_CTRL_HW3_TS_PUSH_EN_MASK                                              (0x00000400U)

#define CPSW_CPTS_CTRL_HW4_TS_PUSH_EN_SHIFT                                             (11U)
#define CPSW_CPTS_CTRL_HW4_TS_PUSH_EN_MASK                                              (0x00000800U)

#define CPSW_CPTS_EVT_POP_SHIFT                                                         (0U)
#define CPSW_CPTS_EVT_POP_MASK                                                          (0x00000001U)

#define CPSW_CPTS_INTSTAT_MASKED_TS_PEND_SHIFT                                          (0U)
#define CPSW_CPTS_INTSTAT_MASKED_TS_PEND_MASK                                           (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CPSW_CPTS_H_ */

