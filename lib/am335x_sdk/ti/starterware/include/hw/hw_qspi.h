/*
* hw_qspi.h
*
* Register-level header file for QSPI
*
* Copyright (C) 2013 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef HW_QSPI_H_
#define HW_QSPI_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define QSPI_PID                                                    (0x0U)
#define QSPI_SYSCONFIG                                              (0x10U)
#define QSPI_INTR_STS_RAW_SET                                       (0x20U)
#define QSPI_INTR_STS_EN_CLR                                        (0x24U)
#define QSPI_INTR_EN_SET_REG                                        (0x28U)
#define QSPI_INTR_EN_CLR_REG                                        (0x2cU)
#define QSPI_INTC_EOI_REG                                           (0x30U)
#define QSPI_CLOCK_CNTRL_REG                                        (0x40U)
#define QSPI_DC_REG                                                 (0x44U)
#define QSPI_CMD_REG                                                (0x48U)
#define QSPI_STS_REG                                                (0x4cU)
#define QSPI_DATA_REG                                               (0x50U)
#define QSPI_SETUP_REG(n)                                           (0x54U + ((n) * 0x4U))
#define QSPI_SETUP_REG_NUM_ELEMS                                    (4U)
#define QSPI_SWITCH_REG                                             (0x64U)
#define QSPI_DATA_REG_1                                             (0x68U)
#define QSPI_DATA_REG_2                                             (0x6cU)
#define QSPI_DATA_REG_3                                             (0x70U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define QSPI_PID_MINOR_SHIFT                                                            (0U)
#define QSPI_PID_MINOR_MASK                                                             (0x0000003fU)

#define QSPI_PID_CUSTOM_SHIFT                                                           (6U)
#define QSPI_PID_CUSTOM_MASK                                                            (0x000000c0U)

#define QSPI_PID_MAJOR_SHIFT                                                            (8U)
#define QSPI_PID_MAJOR_MASK                                                             (0x00000700U)

#define QSPI_PID_RTL_VERSION_SHIFT                                                      (11U)
#define QSPI_PID_RTL_VERSION_MASK                                                       (0x0000f800U)

#define QSPI_PID_FUNC_SHIFT                                                             (16U)
#define QSPI_PID_FUNC_MASK                                                              (0x0fff0000U)

#define QSPI_PID_RSVD_SHIFT                                                             (28U)
#define QSPI_PID_RSVD_MASK                                                              (0x30000000U)

#define QSPI_PID_SCHEME_SHIFT                                                           (30U)
#define QSPI_PID_SCHEME_MASK                                                            (0xc0000000U)

#define QSPI_SYSCONFIG_RSVD_1_SHIFT                                                     (0U)
#define QSPI_SYSCONFIG_RSVD_1_MASK                                                      (0x00000003U)

#define QSPI_SYSCONFIG_IDLE_MODE_SHIFT                                                  (2U)
#define QSPI_SYSCONFIG_IDLE_MODE_MASK                                                   (0x0000000cU)
#define QSPI_SYSCONFIG_IDLE_MODE_FORCE                                                   (0U)
#define QSPI_SYSCONFIG_IDLE_MODE_NO                                                      (1U)
#define QSPI_SYSCONFIG_IDLE_MODE_SMART                                                   (2U)
#define QSPI_SYSCONFIG_IDLE_MODE_SMART_WAKEUP_CAPABLE                                    (3U)

#define QSPI_SYSCONFIG_RSVD_3_SHIFT                                                     (4U)
#define QSPI_SYSCONFIG_RSVD_3_MASK                                                      (0x00000030U)

#define QSPI_SYSCONFIG_RSVD_2_SHIFT                                                     (6U)
#define QSPI_SYSCONFIG_RSVD_2_MASK                                                      (0xffffffc0U)

#define QSPI_INTR_STS_RAW_SET_FIRQ_SHIFT                                                (0U)
#define QSPI_INTR_STS_RAW_SET_FIRQ_MASK                                                 (0x00000001U)
#define QSPI_INTR_STS_RAW_SET_FIRQ_READ_INACTIVE                                         (0U)
#define QSPI_INTR_STS_RAW_SET_FIRQ_READ_ACTIVE                                           (1U)

#define QSPI_INTR_STS_RAW_SET_WIRQ_SHIFT                                                (1U)
#define QSPI_INTR_STS_RAW_SET_WIRQ_MASK                                                 (0x00000002U)
#define QSPI_INTR_STS_RAW_SET_WIRQ_READ_INACTIVE                                         (0U)
#define QSPI_INTR_STS_RAW_SET_WIRQ_READ_ACTIVE                                           (1U)

#define QSPI_INTR_STS_RAW_SET_RSVD_SHIFT                                                (2U)
#define QSPI_INTR_STS_RAW_SET_RSVD_MASK                                                 (0xfffffffcU)

#define QSPI_INTR_STS_EN_CLR_FIRQ_ENA_SHIFT                                             (0U)
#define QSPI_INTR_STS_EN_CLR_FIRQ_ENA_MASK                                              (0x00000001U)
#define QSPI_INTR_STS_EN_CLR_FIRQ_ENA_INACTIVE                                           (0U)
#define QSPI_INTR_STS_EN_CLR_FIRQ_ENA_ACTIVE                                             (1U)

#define QSPI_INTR_STS_EN_CLR_WIRQ_ENA_SHIFT                                             (1U)
#define QSPI_INTR_STS_EN_CLR_WIRQ_ENA_MASK                                              (0x00000002U)
#define QSPI_INTR_STS_EN_CLR_WIRQ_ENA_INACTIVE                                           (0U)
#define QSPI_INTR_STS_EN_CLR_WIRQ_ENA_ACTIVE                                             (1U)

#define QSPI_INTR_STS_EN_CLR_RSVD_SHIFT                                                 (2U)
#define QSPI_INTR_STS_EN_CLR_RSVD_MASK                                                  (0xfffffffcU)

#define QSPI_INTR_EN_SET_REG_FIRQ_ENA_SHIFT                                             (0U)
#define QSPI_INTR_EN_SET_REG_FIRQ_ENA_MASK                                              (0x00000001U)
#define QSPI_INTR_EN_SET_REG_FIRQ_ENA_INACTIVE                                           (0U)
#define QSPI_INTR_EN_SET_REG_FIRQ_ENA_ACTIVE                                             (1U)

#define QSPI_INTR_EN_SET_REG_WIRQ_ENA_SHIFT                                             (1U)
#define QSPI_INTR_EN_SET_REG_WIRQ_ENA_MASK                                              (0x00000002U)
#define QSPI_INTR_EN_SET_REG_WIRQ_ENA_INACTIVE                                           (0U)
#define QSPI_INTR_EN_SET_REG_WIRQ_ENA_ACTIVE                                             (1U)

#define QSPI_INTR_EN_SET_REG_RSVD_SHIFT                                                 (2U)
#define QSPI_INTR_EN_SET_REG_RSVD_MASK                                                  (0xfffffffcU)

#define QSPI_INTR_EN_CLR_REG_FIRQ_ENA_SHIFT                                             (0U)
#define QSPI_INTR_EN_CLR_REG_FIRQ_ENA_MASK                                              (0x00000001U)
#define QSPI_INTR_EN_CLR_REG_FIRQ_ENA_INACTIVE                                           (0U)
#define QSPI_INTR_EN_CLR_REG_FIRQ_ENA_ACTIVE                                             (1U)

#define QSPI_INTR_EN_CLR_REG_WIRQ_ENA_SHIFT                                             (1U)
#define QSPI_INTR_EN_CLR_REG_WIRQ_ENA_MASK                                              (0x00000002U)
#define QSPI_INTR_EN_CLR_REG_WIRQ_ENA_INACTIVE                                           (0U)
#define QSPI_INTR_EN_CLR_REG_WIRQ_ENA_ACTIVE                                             (1U)

#define QSPI_INTR_EN_CLR_REG_RSVD_SHIFT                                                 (2U)
#define QSPI_INTR_EN_CLR_REG_RSVD_MASK                                                  (0xfffffffcU)

#define QSPI_INTC_EOI_REG_VECTOR_SHIFT                                                  (0U)
#define QSPI_INTC_EOI_REG_VECTOR_MASK                                                   (0xffffffffU)

#define QSPI_CLOCK_CNTRL_REG_DCLK_DIV_SHIFT                                             (0U)
#define QSPI_CLOCK_CNTRL_REG_DCLK_DIV_MASK                                              (0x0000ffffU)

#define QSPI_CLOCK_CNTRL_REG_RSVD_SHIFT                                                 (16U)
#define QSPI_CLOCK_CNTRL_REG_RSVD_MASK                                                  (0x7fff0000U)

#define QSPI_CLOCK_CNTRL_REG_CLKEN_SHIFT                                                (31U)
#define QSPI_CLOCK_CNTRL_REG_CLKEN_MASK                                                 (0x80000000U)
#define QSPI_CLOCK_CNTRL_REG_CLKEN_DCLOCK_ON                                             (1U)
#define QSPI_CLOCK_CNTRL_REG_CLKEN_DCLOCK_OFF                                            (0U)

#define QSPI_DC_REG_CKP0_SHIFT                                                          (0U)
#define QSPI_DC_REG_CKP0_MASK                                                           (0x00000001U)
#define QSPI_DC_REG_CKP0_DATA_ACTIVE                                                     (1U)
#define QSPI_DC_REG_CKP0_DATA_INACTIVE                                                   (0U)

#define QSPI_DC_REG_CSP0_SHIFT                                                          (1U)
#define QSPI_DC_REG_CSP0_MASK                                                           (0x00000002U)
#define QSPI_DC_REG_CSP0_ACTIVE_LOW                                                      (0U)
#define QSPI_DC_REG_CSP0_ACTIVE_HIGH                                                     (1U)

#define QSPI_DC_REG_CKPH0_SHIFT                                                         (2U)
#define QSPI_DC_REG_CKPH0_MASK                                                          (0x00000004U)
#define QSPI_DC_REG_CKPH0_CKP_0_SHIFT_OUT_FALLING_EDGE                                   (0U)
#define QSPI_DC_REG_CKPH0_CKP_0_SHIFT_OUT_RISING_EDGE                                    (1U)
#define QSPI_DC_REG_CKPH0_CKP_1_SHIFT_OUT_RISING_EDGE                                    (0U)
#define QSPI_DC_REG_CKPH0_CKP_1_SHIFT_OUT_FALLING_EDGE                                   (1U)

#define QSPI_DC_REG_DD0_SHIFT                                                           (3U)
#define QSPI_DC_REG_DD0_MASK                                                            (0x00000018U)
#define QSPI_DC_REG_DD0_CS_TO_DATA_DELAY_0                                               (0U)
#define QSPI_DC_REG_DD0_CS_TO_DATA_DELAY_1                                               (1U)
#define QSPI_DC_REG_DD0_CS_TO_DATA_DELAY_2                                               (2U)
#define QSPI_DC_REG_DD0_CS_TO_DATA_DELAY_3                                               (3U)

#define QSPI_DC_REG_RSVD_0_SHIFT                                                        (5U)
#define QSPI_DC_REG_RSVD_0_MASK                                                         (0x000000e0U)

#define QSPI_DC_REG_CKP1_SHIFT                                                          (8U)
#define QSPI_DC_REG_CKP1_MASK                                                           (0x00000100U)
#define QSPI_DC_REG_CKP1_DATA_ACTIVE                                                     (1U)
#define QSPI_DC_REG_CKP1_DATA_INACTIVE                                                   (0U)

#define QSPI_DC_REG_CSP1_SHIFT                                                          (9U)
#define QSPI_DC_REG_CSP1_MASK                                                           (0x00000200U)
#define QSPI_DC_REG_CSP1_ACTIVE_LOW                                                      (0U)
#define QSPI_DC_REG_CSP1_ACTIVE_HIGH                                                     (1U)

#define QSPI_DC_REG_CKPH1_SHIFT                                                         (10U)
#define QSPI_DC_REG_CKPH1_MASK                                                          (0x00000400U)
#define QSPI_DC_REG_CKPH1_CKP_0_SHIFT_OUT_FALLING_EDGE                                   (0U)
#define QSPI_DC_REG_CKPH1_CKP_0_SHIFT_OUT_RISING_EDGE                                    (1U)
#define QSPI_DC_REG_CKPH1_CKP_1_SHIFT_OUT_RISING_EDGE                                    (0U)
#define QSPI_DC_REG_CKPH1_CKP_1_SHIFT_OUT_FALLING_EDGE                                   (1U)

#define QSPI_DC_REG_DD1_SHIFT                                                           (11U)
#define QSPI_DC_REG_DD1_MASK                                                            (0x00001800U)
#define QSPI_DC_REG_DD1_CS_TO_DATA_DELAY_0                                               (0U)
#define QSPI_DC_REG_DD1_CS_TO_DATA_DELAY_1                                               (1U)
#define QSPI_DC_REG_DD1_CS_TO_DATA_DELAY_2                                               (2U)
#define QSPI_DC_REG_DD1_CS_TO_DATA_DELAY_3                                               (3U)

#define QSPI_DC_REG_RSVD_1_SHIFT                                                        (13U)
#define QSPI_DC_REG_RSVD_1_MASK                                                         (0x0000e000U)

#define QSPI_DC_REG_CKP2_SHIFT                                                          (16U)
#define QSPI_DC_REG_CKP2_MASK                                                           (0x00010000U)
#define QSPI_DC_REG_CKP2_DATA_ACTIVE                                                     (1U)
#define QSPI_DC_REG_CKP2_DATA_INACTIVE                                                   (0U)

#define QSPI_DC_REG_CSP2_SHIFT                                                          (17U)
#define QSPI_DC_REG_CSP2_MASK                                                           (0x00020000U)
#define QSPI_DC_REG_CSP2_ACTIVE_LOW                                                      (0U)
#define QSPI_DC_REG_CSP2_ACTIVE_HIGH                                                     (1U)

#define QSPI_DC_REG_CKPH2_SHIFT                                                         (18U)
#define QSPI_DC_REG_CKPH2_MASK                                                          (0x00040000U)
#define QSPI_DC_REG_CKPH2_CKP_0_SHIFT_OUT_FALLING_EDGE                                   (0U)
#define QSPI_DC_REG_CKPH2_CKP_0_SHIFT_OUT_RISING_EDGE                                    (1U)
#define QSPI_DC_REG_CKPH2_CKP_1_SHIFT_OUT_RISING_EDGE                                    (0U)
#define QSPI_DC_REG_CKPH2_CKP_1_SHIFT_OUT_FALLING_EDGE                                   (1U)

#define QSPI_DC_REG_DD2_SHIFT                                                           (19U)
#define QSPI_DC_REG_DD2_MASK                                                            (0x00180000U)
#define QSPI_DC_REG_DD2_CS_TO_DATA_DELAY_0                                               (0U)
#define QSPI_DC_REG_DD2_CS_TO_DATA_DELAY_1                                               (1U)
#define QSPI_DC_REG_DD2_CS_TO_DATA_DELAY_2                                               (2U)
#define QSPI_DC_REG_DD2_CS_TO_DATA_DELAY_3                                               (3U)

#define QSPI_DC_REG_RSVD_2_SHIFT                                                        (21U)
#define QSPI_DC_REG_RSVD_2_MASK                                                         (0x00e00000U)

#define QSPI_DC_REG_CKP3_SHIFT                                                          (24U)
#define QSPI_DC_REG_CKP3_MASK                                                           (0x01000000U)
#define QSPI_DC_REG_CKP3_DATA_ACTIVE                                                     (1U)
#define QSPI_DC_REG_CKP3_DATA_INACTIVE                                                   (0U)

#define QSPI_DC_REG_CSP3_SHIFT                                                          (25U)
#define QSPI_DC_REG_CSP3_MASK                                                           (0x02000000U)
#define QSPI_DC_REG_CSP3_ACTIVE_LOW                                                      (0U)
#define QSPI_DC_REG_CSP3_ACTIVE_HIGH                                                     (1U)

#define QSPI_DC_REG_CKPH3_SHIFT                                                         (26U)
#define QSPI_DC_REG_CKPH3_MASK                                                          (0x04000000U)
#define QSPI_DC_REG_CKPH3_CKP_0_SHIFT_OUT_FALLING_EDGE                                   (0U)
#define QSPI_DC_REG_CKPH3_CKP_0_SHIFT_OUT_RISING_EDGE                                    (1U)
#define QSPI_DC_REG_CKPH3_CKP_1_SHIFT_OUT_RISING_EDGE                                    (0U)
#define QSPI_DC_REG_CKPH3_CKP_1_SHIFT_OUT_FALLING_EDGE                                   (1U)

#define QSPI_DC_REG_DD3_SHIFT                                                           (27U)
#define QSPI_DC_REG_DD3_MASK                                                            (0x18000000U)
#define QSPI_DC_REG_DD3_CS_TO_DATA_DELAY_0                                               (0U)
#define QSPI_DC_REG_DD3_CS_TO_DATA_DELAY_1                                               (1U)
#define QSPI_DC_REG_DD3_CS_TO_DATA_DELAY_2                                               (2U)
#define QSPI_DC_REG_DD3_CS_TO_DATA_DELAY_3                                               (3U)

#define QSPI_DC_REG_RSVD_3_SHIFT                                                        (29U)
#define QSPI_DC_REG_RSVD_3_MASK                                                         (0xe0000000U)

#define QSPI_CMD_REG_FLEN_SHIFT                                                         (0U)
#define QSPI_CMD_REG_FLEN_MASK                                                          (0x00000fffU)
#define QSPI_CMD_REG_FLEN_ONE_WORD                                                       (0U)
#define QSPI_CMD_REG_FLEN_TWO_WORDS                                                      (1U)
#define QSPI_CMD_REG_FLEN_FOUR_THOUSAND_NINETY_SIX_WORDS                                 (4095U)

#define QSPI_CMD_REG_RSVD_SHIFT                                                         (12U)
#define QSPI_CMD_REG_RSVD_MASK                                                          (0x00003000U)

#define QSPI_CMD_REG_WIRQ_SHIFT                                                         (14U)
#define QSPI_CMD_REG_WIRQ_MASK                                                          (0x00004000U)
#define QSPI_CMD_REG_WIRQ_WORD_COUNT_IRQ_ENABLE                                          (1U)
#define QSPI_CMD_REG_WIRQ_WORD_COUNT_IRQ_DISABLE                                         (0U)

#define QSPI_CMD_REG_FIRQ_SHIFT                                                         (15U)
#define QSPI_CMD_REG_FIRQ_MASK                                                          (0x00008000U)
#define QSPI_CMD_REG_FIRQ_FRAME_COUNT_IRQ_ENABLE                                         (1U)
#define QSPI_CMD_REG_FIRQ_FRAME_COUNT_IRQ_DISABLE                                        (0U)

#define QSPI_CMD_REG_SHIFT                                                              (16U)
#define QSPI_CMD_REG_MASK                                                               (0x00070000U)
#define QSPI_CMD_REG_FOUR_PIN_READ_SINGLE                                                (1U)
#define QSPI_CMD_REG_FOUR_PIN_WRITE_SINGLE                                               (2U)
#define QSPI_CMD_REG_FOUR_PIN_READ_DUAL                                                  (3U)
#define QSPI_CMD_REG_THREE_PIN_READ_SINGLE                                               (5U)
#define QSPI_CMD_REG_THREE_PIN_WRITE_SINGLE                                              (6U)
#define QSPI_CMD_REG_SIX_PIN_READ_QUAD                                                   (7U)

#define QSPI_CMD_REG_WLEN_SHIFT                                                         (19U)
#define QSPI_CMD_REG_WLEN_MASK                                                          (0x00f80000U)
#define QSPI_CMD_REG_WLEN_ONE_BIT                                                        (0U)
#define QSPI_CMD_REG_WLEN_TWO_BITS                                                       (1U)
#define QSPI_CMD_REG_WLEN_THIRTY_TWO_BITS                                                (31U)

#define QSPI_CMD_REG_RSVD_2_SHIFT                                                       (24U)
#define QSPI_CMD_REG_RSVD_2_MASK                                                        (0x0f000000U)

#define QSPI_CMD_REG_CSNUM_SHIFT                                                        (28U)
#define QSPI_CMD_REG_CSNUM_MASK                                                         (0x30000000U)
#define QSPI_CMD_REG_CSNUM_CS_0                                                          (0U)
#define QSPI_CMD_REG_CSNUM_CS_1                                                          (1U)
#define QSPI_CMD_REG_CSNUM_CS_2                                                          (2U)
#define QSPI_CMD_REG_CSNUM_CS_3                                                          (3U)

#define QSPI_CMD_REG_RSVD_3_SHIFT                                                       (30U)
#define QSPI_CMD_REG_RSVD_3_MASK                                                        (0xc0000000U)

#define QSPI_STS_REG_BUSY_SHIFT                                                         (0U)
#define QSPI_STS_REG_BUSY_MASK                                                          (0x00000001U)
#define QSPI_STS_REG_BUSY_IDLE                                                           (0U)
#define QSPI_STS_REG_BUSY                                                                (1U)

#define QSPI_STS_REG_WC_SHIFT                                                           (1U)
#define QSPI_STS_REG_WC_MASK                                                            (0x00000002U)
#define QSPI_STS_REG_WC_WORD_TRANSFER_NOT_COMPLETE                                       (0U)
#define QSPI_STS_REG_WC_WORD_TRANSFER_COMPLETE                                           (1U)

#define QSPI_STS_REG_FC_SHIFT                                                           (2U)
#define QSPI_STS_REG_FC_MASK                                                            (0x00000004U)
#define QSPI_STS_REG_FC_FRAME_TRANSFER_NOT_COMPLETE                                      (0U)
#define QSPI_STS_REG_FC_FRAME_TRANSFER_COMPLETE                                          (1U)

#define QSPI_STS_REG_RSVD_SHIFT                                                         (3U)
#define QSPI_STS_REG_RSVD_MASK                                                          (0x0000fff8U)

#define QSPI_STS_REG_WDCNT_SHIFT                                                        (16U)
#define QSPI_STS_REG_WDCNT_MASK                                                         (0x0fff0000U)

#define QSPI_STS_REG_RSVD_2_SHIFT                                                       (28U)
#define QSPI_STS_REG_RSVD_2_MASK                                                        (0xf0000000U)

#define QSPI_DATA_REG_SHIFT                                                             (0U)
#define QSPI_DATA_REG_MASK                                                              (0xffffffffU)

#define QSPI_SETUP_REG_RCMD_SHIFT                                                       (0U)
#define QSPI_SETUP_REG_RCMD_MASK                                                        (0x000000ffU)

#define QSPI_SETUP_REG_NUM_A_BYTES_SHIFT                                                (8U)
#define QSPI_SETUP_REG_NUM_A_BYTES_MASK                                                 (0x00000300U)
#define QSPI_SETUP_REG_NUM_A_BYTES_ONE_BYTE                                              (0U)
#define QSPI_SETUP_REG_NUM_A_BYTES_TWO                                                   (1U)
#define QSPI_SETUP_REG_NUM_A_BYTES_THREE                                                 (2U)
#define QSPI_SETUP_REG_NUM_A_BYTES_FOUR                                                  (3U)

#define QSPI_SETUP_REG_NUM_D_BYTES_SHIFT                                                (10U)
#define QSPI_SETUP_REG_NUM_D_BYTES_MASK                                                 (0x00000c00U)
#define QSPI_SETUP_REG_NUM_D_BYTES_USE_BITS                                              (0U)
#define QSPI_SETUP_REG_NUM_D_BYTES_USE_8_BITS                                            (1U)
#define QSPI_SETUP_REG_NUM_D_BYTES_USE_16_BITS                                           (2U)
#define QSPI_SETUP_REG_NUM_D_BYTES_USE_24_BITS                                           (3U)

#define QSPI_SETUP_REG_READ_TYPE_SHIFT                                                  (12U)
#define QSPI_SETUP_REG_READ_TYPE_MASK                                                   (0x00003000U)
#define QSPI_SETUP_REG_READ_TYPE_NORMAL                                                  (0U)
#define QSPI_SETUP_REG_READ_TYPE_DUAL                                                    (1U)
#define QSPI_SETUP_REG_READ_TYPE_NORMAL_READTYPE                                         (2U)
#define QSPI_SETUP_REG_READ_TYPE_QUAD                                                    (3U)

#define QSPI_SETUP_REG_RSVD_1_SHIFT                                                     (14U)
#define QSPI_SETUP_REG_RSVD_1_MASK                                                      (0x0000c000U)

#define QSPI_SETUP_REG_WCMD_SHIFT                                                       (16U)
#define QSPI_SETUP_REG_WCMD_MASK                                                        (0x00ff0000U)

#define QSPI_SETUP_REG_RSVD_2_SHIFT                                                     (29U)
#define QSPI_SETUP_REG_RSVD_2_MASK                                                      (0xe0000000U)

#define QSPI_SETUP_REG_NUM_D_BITS_SHIFT                                                 (24U)
#define QSPI_SETUP_REG_NUM_D_BITS_MASK                                                  (0x1f000000U)

#define QSPI_SWITCH_REG_MMPT_S_SHIFT                                                    (0U)
#define QSPI_SWITCH_REG_MMPT_S_MASK                                                     (0x00000001U)
#define QSPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT                                              (0U)
#define QSPI_SWITCH_REG_MMPT_S_SEL_MM_PORT                                               (1U)

#define QSPI_SWITCH_REG_MM_INT_EN_SHIFT                                                 (1U)
#define QSPI_SWITCH_REG_MM_INT_EN_MASK                                                  (0x00000002U)
#define QSPI_SWITCH_REG_MM_INT_EN_MODE_INTR_DISABLED                                     (0U)
#define QSPI_SWITCH_REG_MM_INT_EN_MODE_INTR_ENABLED                                      (1U)

#define QSPI_SWITCH_REG_RSVD_SHIFT                                                      (2U)
#define QSPI_SWITCH_REG_RSVD_MASK                                                       (0xfffffffcU)

#define QSPI_DATA_REG_1_SHIFT                                                           (0U)
#define QSPI_DATA_REG_1_MASK                                                            (0xffffffffU)

#define QSPI_DATA_REG_2_SHIFT                                                           (0U)
#define QSPI_DATA_REG_2_MASK                                                            (0xffffffffU)

#define QSPI_DATA_REG_3_SHIFT                                                           (0U)
#define QSPI_DATA_REG_3_MASK                                                            (0xffffffffU)

#ifdef __cplusplus
}
#endif
#endif  /* HW_QSPI_H_ */

