/*
* hw_i2c.h
*
* Register-level header file for I2C [AEGIS_PUBLIC_INCLUDE]
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

#ifndef HW_I2C_H_
#define HW_I2C_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define I2C_DATA                                                    (0x9cU)
#define I2C_PSC                                                     (0xb0U)
#define I2C_REVNB_LO                                                (0x0U)
#define I2C_SYSTEST                                                 (0xbcU)
#define I2C_IRQSTS_RAW                                              (0x24U)
#define I2C_SCLH                                                    (0xb8U)
#define I2C_OA                                                      (0xa8U)
#define I2C_CNT                                                     (0x98U)
#define I2C_SYSS                                                    (0x90U)
#define I2C_SBLOCK                                                  (0xd4U)
#define I2C_REVNB_HI                                                (0x4U)
#define I2C_IRQEN_CLR                                               (0x30U)
#define I2C_DMATXEN_SET                                             (0x3cU)
#define I2C_DMARXWAKE_EN                                            (0x48U)
#define I2C_DMATXWAKE_EN                                            (0x4cU)
#define I2C_IRQSTS                                                  (0x28U)
#define I2C_BUFSTAT                                                 (0xc0U)
#define I2C_BUF                                                     (0x94U)
#define I2C_OA3                                                     (0xccU)
#define I2C_DMARXEN_SET                                             (0x38U)
#define I2C_OA2                                                     (0xc8U)
#define I2C_CON                                                     (0xa4U)
#define I2C_ACTOA                                                   (0xd0U)
#define I2C_SA                                                      (0xacU)
#define I2C_WE                                                      (0x34U)
#define I2C_DMATXEN_CLR                                             (0x44U)
#define I2C_OA1                                                     (0xc4U)
#define I2C_SCLL                                                    (0xb4U)
#define I2C_IRQEN_SET                                               (0x2cU)
#define I2C_SYSC                                                    (0x10U)
#define I2C_DMARXEN_CLR                                             (0x40U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define I2C_DATA_SHIFT                                                                  (0U)
#define I2C_DATA_MASK                                                                   (0x000000ffU)

#define I2C_PSC_SHIFT                                                                   (0U)
#define I2C_PSC_MASK                                                                    (0x000000ffU)
#define I2C_PSC_DIV_2                                                                    (1U)
#define I2C_PSC_DIV_1                                                                    (0U)
#define I2C_PSC_DIV_256                                                                  (255U)

#define I2C_REVNB_LO_MINOR_SHIFT                                                        (0U)
#define I2C_REVNB_LO_MINOR_MASK                                                         (0x0000003fU)

#define I2C_REVNB_LO_CUSTOM_SHIFT                                                       (6U)
#define I2C_REVNB_LO_CUSTOM_MASK                                                        (0x000000c0U)

#define I2C_REVNB_LO_MAJOR_SHIFT                                                        (8U)
#define I2C_REVNB_LO_MAJOR_MASK                                                         (0x00000700U)

#define I2C_REVNB_LO_RTL_SHIFT                                                          (11U)
#define I2C_REVNB_LO_RTL_MASK                                                           (0x0000f800U)

#define I2C_SYSTEST_SDA_O_SHIFT                                                         (0U)
#define I2C_SYSTEST_SDA_O_MASK                                                          (0x00000001U)
#define I2C_SYSTEST_SDA_O_WRITE_1                                                        (1U)
#define I2C_SYSTEST_SDA_O_WRITE_0                                                        (0U)

#define I2C_SYSTEST_SDA_I_SHIFT                                                         (1U)
#define I2C_SYSTEST_SDA_I_MASK                                                          (0x00000002U)
#define I2C_SYSTEST_SDA_I_READ_1                                                         (1U)
#define I2C_SYSTEST_SDA_I_READ_0                                                         (0U)

#define I2C_SYSTEST_SCL_O_SHIFT                                                         (2U)
#define I2C_SYSTEST_SCL_O_MASK                                                          (0x00000004U)
#define I2C_SYSTEST_SCL_O_HIGH_IMPEDANCE                                                 (1U)
#define I2C_SYSTEST_SCL_O_FORCE_0                                                        (0U)

#define I2C_SYSTEST_SCL_I_SHIFT                                                         (3U)
#define I2C_SYSTEST_SCL_I_MASK                                                          (0x00000008U)
#define I2C_SYSTEST_SCL_I_READ_1                                                         (1U)
#define I2C_SYSTEST_SCL_I_READ_0                                                         (0U)

#define I2C_SYSTEST_SDA_O_FUNC_SHIFT                                                    (5U)
#define I2C_SYSTEST_SDA_O_FUNC_MASK                                                     (0x00000020U)
#define I2C_SYSTEST_SDA_O_FUNC_DRIVEN_1                                                  (1U)
#define I2C_SYSTEST_SDA_O_FUNC_DRIVEN_0                                                  (0U)

#define I2C_SYSTEST_SDA_I_FUNC_SHIFT                                                    (6U)
#define I2C_SYSTEST_SDA_I_FUNC_MASK                                                     (0x00000040U)
#define I2C_SYSTEST_SDA_I_FUNC_READ_1                                                    (1U)
#define I2C_SYSTEST_SDA_I_FUNC_READ_0                                                    (0U)

#define I2C_SYSTEST_SCL_O_FUNC_SHIFT                                                    (7U)
#define I2C_SYSTEST_SCL_O_FUNC_MASK                                                     (0x00000080U)
#define I2C_SYSTEST_SCL_O_FUNC_DRIVEN_1                                                  (1U)
#define I2C_SYSTEST_SCL_O_FUNC_DRIVEN_0                                                  (0U)

#define I2C_SYSTEST_SCL_I_FUNC_SHIFT                                                    (8U)
#define I2C_SYSTEST_SCL_I_FUNC_MASK                                                     (0x00000100U)
#define I2C_SYSTEST_SCL_I_FUNC_READ_1                                                    (1U)
#define I2C_SYSTEST_SCL_I_FUNC_READ_0                                                    (0U)

#define I2C_SYSTEST_SSB_SHIFT                                                           (11U)
#define I2C_SYSTEST_SSB_MASK                                                            (0x00000800U)
#define I2C_SYSTEST_SSB_NO_ACTION                                                        (0U)
#define I2C_SYSTEST_SSB_SET_INT                                                          (1U)

#define I2C_SYSTEST_TMODE_SHIFT                                                         (12U)
#define I2C_SYSTEST_TMODE_MASK                                                          (0x00003000U)
#define I2C_SYSTEST_TMODE_FUNCTIONAL                                                     (0U)
#define I2C_SYSTEST_TMODE_TEST                                                           (2U)
#define I2C_SYSTEST_TMODE_LOOP_BACK                                                      (3U)

#define I2C_SYSTEST_FREE_SHIFT                                                          (14U)
#define I2C_SYSTEST_FREE_MASK                                                           (0x00004000U)
#define I2C_SYSTEST_FREE_RUNNING                                                         (1U)
#define I2C_SYSTEST_FREE_STOP                                                            (0U)

#define I2C_SYSTEST_ST_EN_SHIFT                                                         (15U)
#define I2C_SYSTEST_ST_EN_MASK                                                          (0x00008000U)
#define I2C_SYSTEST_ST_EN_NORMAL                                                         (0U)
#define I2C_SYSTEST_ST_EN_STSTEM_TEST                                                    (1U)

#define I2C_IRQSTS_RAW_AL_SHIFT                                                         (0U)
#define I2C_IRQSTS_RAW_AL_MASK                                                          (0x00000001U)
#define I2C_IRQSTS_RAW_AL_NORMAL                                                         (0U)
#define I2C_IRQSTS_RAW_AL_ARBITRATION_LOST                                               (1U)

#define I2C_IRQSTS_RAW_NACK_SHIFT                                                       (1U)
#define I2C_IRQSTS_RAW_NACK_MASK                                                        (0x00000002U)
#define I2C_IRQSTS_RAW_NACK_NORMAL                                                       (0U)
#define I2C_IRQSTS_RAW_NACK_NO_ACK                                                       (1U)

#define I2C_IRQSTS_RAW_ARDY_SHIFT                                                       (2U)
#define I2C_IRQSTS_RAW_ARDY_MASK                                                        (0x00000004U)
#define I2C_IRQSTS_RAW_ARDY_ACCESS_READY                                                 (1U)
#define I2C_IRQSTS_RAW_ARDY_NO_ACTION                                                    (0U)

#define I2C_IRQSTS_RAW_RRDY_SHIFT                                                       (3U)
#define I2C_IRQSTS_RAW_RRDY_MASK                                                        (0x00000008U)
#define I2C_IRQSTS_RAW_RRDY_FIFO_THRESHOLD_NOT_REACHED                                   (0U)
#define I2C_IRQSTS_RAW_RRDY_FIFO_THRESHOLD_REACHED                                       (1U)

#define I2C_IRQSTS_RAW_XRDY_SHIFT                                                       (4U)
#define I2C_IRQSTS_RAW_XRDY_MASK                                                        (0x00000010U)
#define I2C_IRQSTS_RAW_XRDY_READY                                                        (1U)
#define I2C_IRQSTS_RAW_XRDY_ONGOING                                                      (0U)

#define I2C_IRQSTS_RAW_GC_SHIFT                                                         (5U)
#define I2C_IRQSTS_RAW_GC_MASK                                                          (0x00000020U)
#define I2C_IRQSTS_RAW_GC_GENERAL_CALL                                                   (1U)
#define I2C_IRQSTS_RAW_GC_NO_GENERAL_CALL                                                (0U)

#define I2C_IRQSTS_RAW_STC_SHIFT                                                        (6U)
#define I2C_IRQSTS_RAW_STC_MASK                                                         (0x00000040U)
#define I2C_IRQSTS_RAW_STC_START_CONDITION                                               (1U)
#define I2C_IRQSTS_RAW_STC_NO_ACTION                                                     (0U)

#define I2C_IRQSTS_RAW_AERR_SHIFT                                                       (7U)
#define I2C_IRQSTS_RAW_AERR_MASK                                                        (0x00000080U)
#define I2C_IRQSTS_RAW_AERR_ACCESS_ERROR                                                 (1U)
#define I2C_IRQSTS_RAW_AERR_NO_ACTION                                                    (0U)

#define I2C_IRQSTS_RAW_BF_SHIFT                                                         (8U)
#define I2C_IRQSTS_RAW_BF_MASK                                                          (0x00000100U)
#define I2C_IRQSTS_RAW_BF_BUS_FREE                                                       (1U)
#define I2C_IRQSTS_RAW_BF_NO_ACTION                                                      (0U)

#define I2C_IRQSTS_RAW_AAS_SHIFT                                                        (9U)
#define I2C_IRQSTS_RAW_AAS_MASK                                                         (0x00000200U)
#define I2C_IRQSTS_RAW_AAS_ADDRESS_RECOGNIZED                                            (1U)
#define I2C_IRQSTS_RAW_AAS_NO_ACTION                                                     (0U)

#define I2C_IRQSTS_RAW_XUDF_SHIFT                                                       (10U)
#define I2C_IRQSTS_RAW_XUDF_MASK                                                        (0x00000400U)
#define I2C_IRQSTS_RAW_XUDF_TRANSMIT_UNDERFLOW                                           (1U)
#define I2C_IRQSTS_RAW_XUDF_NORMAL                                                       (0U)

#define I2C_IRQSTS_RAW_ROVR_SHIFT                                                       (11U)
#define I2C_IRQSTS_RAW_ROVR_MASK                                                        (0x00000800U)
#define I2C_IRQSTS_RAW_ROVR_RECEIVER_OVERRUN                                             (1U)
#define I2C_IRQSTS_RAW_ROVR_NORMAL                                                       (0U)

#define I2C_IRQSTS_RAW_BB_SHIFT                                                         (12U)
#define I2C_IRQSTS_RAW_BB_MASK                                                          (0x00001000U)
#define I2C_IRQSTS_RAW_BB_OCCUPIED                                                       (1U)
#define I2C_IRQSTS_RAW_BB_FREE                                                           (0U)

#define I2C_IRQSTS_RAW_RDR_SHIFT                                                        (13U)
#define I2C_IRQSTS_RAW_RDR_MASK                                                         (0x00002000U)
#define I2C_IRQSTS_RAW_RDR_INACTIVE                                                      (0U)
#define I2C_IRQSTS_RAW_RDR_ENABLED                                                       (1U)

#define I2C_IRQSTS_RAW_XDR_SHIFT                                                        (14U)
#define I2C_IRQSTS_RAW_XDR_MASK                                                         (0x00004000U)
#define I2C_IRQSTS_RAW_XDR_INACTIVE                                                      (0U)
#define I2C_IRQSTS_RAW_XDR_ENABLED                                                       (1U)

#define I2C_SCLH_SHIFT                                                                  (0U)
#define I2C_SCLH_MASK                                                                   (0x000000ffU)

#define I2C_OA_SHIFT                                                                    (0U)
#define I2C_OA_MASK                                                                     (0x000003ffU)

#define I2C_CNT_DCOUNT_SHIFT                                                            (0U)
#define I2C_CNT_DCOUNT_MASK                                                             (0x0000ffffU)
#define I2C_CNT_DCOUNT_COUNTER_65536                                                     (0U)
#define I2C_CNT_DCOUNT_COUNTER_1                                                         (1U)
#define I2C_CNT_DCOUNT_COUNTER_65535                                                     (65535U)

#define I2C_SYSS_RDONE_SHIFT                                                            (0U)
#define I2C_SYSS_RDONE_MASK                                                             (0x00000001U)
#define I2C_SYSS_RDONE_ONGOING                                                           (0U)
#define I2C_SYSS_RDONE_COMPLETE                                                          (1U)

#define I2C_SBLOCK_OA0_EN_SHIFT                                                         (0U)
#define I2C_SBLOCK_OA0_EN_MASK                                                          (0x00000001U)
#define I2C_SBLOCK_OA0_EN_RELEASED                                                       (0U)
#define I2C_SBLOCK_OA0_EN_BLOCKED                                                        (1U)

#define I2C_SBLOCK_OA1_EN_SHIFT                                                         (1U)
#define I2C_SBLOCK_OA1_EN_MASK                                                          (0x00000002U)
#define I2C_SBLOCK_OA1_EN_RELEASED                                                       (0U)
#define I2C_SBLOCK_OA1_EN_BLOCKED                                                        (1U)

#define I2C_SBLOCK_OA2_EN_SHIFT                                                         (2U)
#define I2C_SBLOCK_OA2_EN_MASK                                                          (0x00000004U)
#define I2C_SBLOCK_OA2_EN_RELEASED                                                       (0U)
#define I2C_SBLOCK_OA2_EN_BLOCKED                                                        (1U)

#define I2C_SBLOCK_OA3_EN_SHIFT                                                         (3U)
#define I2C_SBLOCK_OA3_EN_MASK                                                          (0x00000008U)
#define I2C_SBLOCK_OA3_EN_RELEASED                                                       (0U)
#define I2C_SBLOCK_OA3_EN_BLOCKED                                                        (1U)

#define I2C_REVNB_HI_FUNC_SHIFT                                                         (0U)
#define I2C_REVNB_HI_FUNC_MASK                                                          (0x00000fffU)

#define I2C_REVNB_HI_SCHEME_SHIFT                                                       (14U)
#define I2C_REVNB_HI_SCHEME_MASK                                                        (0x0000c000U)

#define I2C_IRQEN_CLR_AL_IE_SHIFT                                                       (0U)
#define I2C_IRQEN_CLR_AL_IE_MASK                                                        (0x00000001U)
#define I2C_IRQEN_CLR_AL_IE_ENABLED                                                      (1U)
#define I2C_IRQEN_CLR_AL_IE_DISABLED                                                     (0U)

#define I2C_IRQEN_CLR_NACK_IE_SHIFT                                                     (1U)
#define I2C_IRQEN_CLR_NACK_IE_MASK                                                      (0x00000002U)
#define I2C_IRQEN_CLR_NACK_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_CLR_NACK_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_CLR_ARDY_IE_SHIFT                                                     (2U)
#define I2C_IRQEN_CLR_ARDY_IE_MASK                                                      (0x00000004U)
#define I2C_IRQEN_CLR_ARDY_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_CLR_ARDY_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_CLR_RRDY_IE_SHIFT                                                     (3U)
#define I2C_IRQEN_CLR_RRDY_IE_MASK                                                      (0x00000008U)
#define I2C_IRQEN_CLR_RRDY_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_CLR_RRDY_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_CLR_XRDY_IE_SHIFT                                                     (4U)
#define I2C_IRQEN_CLR_XRDY_IE_MASK                                                      (0x00000010U)
#define I2C_IRQEN_CLR_XRDY_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_CLR_XRDY_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_CLR_GC_IE_SHIFT                                                       (5U)
#define I2C_IRQEN_CLR_GC_IE_MASK                                                        (0x00000020U)
#define I2C_IRQEN_CLR_GC_IE_ENABLED                                                      (1U)
#define I2C_IRQEN_CLR_GC_IE_DISABLED                                                     (0U)

#define I2C_IRQEN_CLR_STC_IE_SHIFT                                                      (6U)
#define I2C_IRQEN_CLR_STC_IE_MASK                                                       (0x00000040U)
#define I2C_IRQEN_CLR_STC_IE_ENABLED                                                     (1U)
#define I2C_IRQEN_CLR_STC_IE_DISABLED                                                    (0U)

#define I2C_IRQEN_CLR_AERR_IE_SHIFT                                                     (7U)
#define I2C_IRQEN_CLR_AERR_IE_MASK                                                      (0x00000080U)
#define I2C_IRQEN_CLR_AERR_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_CLR_AERR_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_CLR_BF_IE_SHIFT                                                       (8U)
#define I2C_IRQEN_CLR_BF_IE_MASK                                                        (0x00000100U)
#define I2C_IRQEN_CLR_BF_IE_ENABLED                                                      (1U)
#define I2C_IRQEN_CLR_BF_IE_DISABLED                                                     (0U)

#define I2C_IRQEN_CLR_AAS_IE_SHIFT                                                      (9U)
#define I2C_IRQEN_CLR_AAS_IE_MASK                                                       (0x00000200U)
#define I2C_IRQEN_CLR_AAS_IE_ENABLED                                                     (1U)
#define I2C_IRQEN_CLR_AAS_IE_DISABLED                                                    (0U)

#define I2C_IRQEN_CLR_XUDF_SHIFT                                                        (10U)
#define I2C_IRQEN_CLR_XUDF_MASK                                                         (0x00000400U)
#define I2C_IRQEN_CLR_XUDF_ENABLED                                                       (1U)
#define I2C_IRQEN_CLR_XUDF_DISABLED                                                      (0U)

#define I2C_IRQEN_CLR_ROVR_SHIFT                                                        (11U)
#define I2C_IRQEN_CLR_ROVR_MASK                                                         (0x00000800U)
#define I2C_IRQEN_CLR_ROVR_ENABLED                                                       (1U)
#define I2C_IRQEN_CLR_ROVR_DISABLED                                                      (0U)

#define I2C_IRQEN_CLR_RDR_IE_SHIFT                                                      (13U)
#define I2C_IRQEN_CLR_RDR_IE_MASK                                                       (0x00002000U)
#define I2C_IRQEN_CLR_RDR_IE_ENABLED                                                     (1U)
#define I2C_IRQEN_CLR_RDR_IE_DISABLED                                                    (0U)

#define I2C_IRQEN_CLR_XDR_IE_SHIFT                                                      (14U)
#define I2C_IRQEN_CLR_XDR_IE_MASK                                                       (0x00004000U)
#define I2C_IRQEN_CLR_XDR_IE_ENABLED                                                     (1U)
#define I2C_IRQEN_CLR_XDR_IE_DISABLED                                                    (0U)

#define I2C_DMATXEN_SET_DMATX_TRANSMIT_SHIFT                                            (0U)
#define I2C_DMATXEN_SET_DMATX_TRANSMIT_MASK                                             (0x00000001U)

#define I2C_DMARXWAKE_EN_AL_SHIFT                                                       (0U)
#define I2C_DMARXWAKE_EN_AL_MASK                                                        (0x00000001U)
#define I2C_DMARXWAKE_EN_AL_ENABLED                                                      (1U)
#define I2C_DMARXWAKE_EN_AL_DISABLED                                                     (0U)

#define I2C_DMARXWAKE_EN_NACK_SHIFT                                                     (1U)
#define I2C_DMARXWAKE_EN_NACK_MASK                                                      (0x00000002U)
#define I2C_DMARXWAKE_EN_NACK_ENABLED                                                    (1U)
#define I2C_DMARXWAKE_EN_NACK_DISABLED                                                   (0U)

#define I2C_DMARXWAKE_EN_ARDY_SHIFT                                                     (2U)
#define I2C_DMARXWAKE_EN_ARDY_MASK                                                      (0x00000004U)
#define I2C_DMARXWAKE_EN_ARDY_ENABLED                                                    (1U)
#define I2C_DMARXWAKE_EN_ARDY_DISABLED                                                   (0U)

#define I2C_DMARXWAKE_EN_DRDY_SHIFT                                                     (3U)
#define I2C_DMARXWAKE_EN_DRDY_MASK                                                      (0x00000008U)
#define I2C_DMARXWAKE_EN_DRDY_ENABLED                                                    (1U)
#define I2C_DMARXWAKE_EN_DRDY_DISABLED                                                   (0U)

#define I2C_DMARXWAKE_EN_GC_SHIFT                                                       (5U)
#define I2C_DMARXWAKE_EN_GC_MASK                                                        (0x00000020U)
#define I2C_DMARXWAKE_EN_GC_ENABLED                                                      (1U)
#define I2C_DMARXWAKE_EN_GC_DISABLED                                                     (0U)

#define I2C_DMARXWAKE_EN_STC_SHIFT                                                      (6U)
#define I2C_DMARXWAKE_EN_STC_MASK                                                       (0x00000040U)
#define I2C_DMARXWAKE_EN_STC_ENABLED                                                     (1U)
#define I2C_DMARXWAKE_EN_STC_DISABLED                                                    (0U)

#define I2C_DMARXWAKE_EN_BF_SHIFT                                                       (8U)
#define I2C_DMARXWAKE_EN_BF_MASK                                                        (0x00000100U)
#define I2C_DMARXWAKE_EN_BF_ENABLED                                                      (1U)
#define I2C_DMARXWAKE_EN_BF_DISABLED                                                     (0U)

#define I2C_DMARXWAKE_EN_AAS_SHIFT                                                      (9U)
#define I2C_DMARXWAKE_EN_AAS_MASK                                                       (0x00000200U)
#define I2C_DMARXWAKE_EN_AAS_ENABLED                                                     (1U)
#define I2C_DMARXWAKE_EN_AAS_DISABLED                                                    (0U)

#define I2C_DMARXWAKE_EN_XUDF_SHIFT                                                     (10U)
#define I2C_DMARXWAKE_EN_XUDF_MASK                                                      (0x00000400U)
#define I2C_DMARXWAKE_EN_XUDF_ENABLED                                                    (1U)
#define I2C_DMARXWAKE_EN_XUDF_DISABLED                                                   (0U)

#define I2C_DMARXWAKE_EN_ROVR_SHIFT                                                     (11U)
#define I2C_DMARXWAKE_EN_ROVR_MASK                                                      (0x00000800U)
#define I2C_DMARXWAKE_EN_ROVR_ENABLED                                                    (1U)
#define I2C_DMARXWAKE_EN_ROVR_DISABLED                                                   (0U)

#define I2C_DMARXWAKE_EN_RDR_SHIFT                                                      (13U)
#define I2C_DMARXWAKE_EN_RDR_MASK                                                       (0x00002000U)
#define I2C_DMARXWAKE_EN_RDR_ENABLED                                                     (1U)
#define I2C_DMARXWAKE_EN_RDR_DISABLED                                                    (0U)

#define I2C_DMARXWAKE_EN_XDR_SHIFT                                                      (14U)
#define I2C_DMARXWAKE_EN_XDR_MASK                                                       (0x00004000U)
#define I2C_DMARXWAKE_EN_XDR_ENABLED                                                     (1U)
#define I2C_DMARXWAKE_EN_XDR_DISABLED                                                    (0U)

#define I2C_DMATXWAKE_EN_AL_SHIFT                                                       (0U)
#define I2C_DMATXWAKE_EN_AL_MASK                                                        (0x00000001U)
#define I2C_DMATXWAKE_EN_AL_ENABLED                                                      (1U)
#define I2C_DMATXWAKE_EN_AL_DISABLED                                                     (0U)

#define I2C_DMATXWAKE_EN_NACK_SHIFT                                                     (1U)
#define I2C_DMATXWAKE_EN_NACK_MASK                                                      (0x00000002U)
#define I2C_DMATXWAKE_EN_NACK_ENABLED                                                    (1U)
#define I2C_DMATXWAKE_EN_NACK_DISABLED                                                   (0U)

#define I2C_DMATXWAKE_EN_ARDY_SHIFT                                                     (2U)
#define I2C_DMATXWAKE_EN_ARDY_MASK                                                      (0x00000004U)
#define I2C_DMATXWAKE_EN_ARDY_ENABLED                                                    (1U)
#define I2C_DMATXWAKE_EN_ARDY_DISABLED                                                   (0U)

#define I2C_DMATXWAKE_EN_DRDY_SHIFT                                                     (3U)
#define I2C_DMATXWAKE_EN_DRDY_MASK                                                      (0x00000008U)
#define I2C_DMATXWAKE_EN_DRDY_ENABLED                                                    (1U)
#define I2C_DMATXWAKE_EN_DRDY_DISABLED                                                   (0U)

#define I2C_DMATXWAKE_EN_GC_SHIFT                                                       (5U)
#define I2C_DMATXWAKE_EN_GC_MASK                                                        (0x00000020U)
#define I2C_DMATXWAKE_EN_GC_ENABLED                                                      (1U)
#define I2C_DMATXWAKE_EN_GC_DISABLED                                                     (0U)

#define I2C_DMATXWAKE_EN_STC_SHIFT                                                      (6U)
#define I2C_DMATXWAKE_EN_STC_MASK                                                       (0x00000040U)
#define I2C_DMATXWAKE_EN_STC_ENABLED                                                     (1U)
#define I2C_DMATXWAKE_EN_STC_DISABLED                                                    (0U)

#define I2C_DMATXWAKE_EN_BF_SHIFT                                                       (8U)
#define I2C_DMATXWAKE_EN_BF_MASK                                                        (0x00000100U)
#define I2C_DMATXWAKE_EN_BF_ENABLED                                                      (1U)
#define I2C_DMATXWAKE_EN_BF_DISABLED                                                     (0U)

#define I2C_DMATXWAKE_EN_AAS_SHIFT                                                      (9U)
#define I2C_DMATXWAKE_EN_AAS_MASK                                                       (0x00000200U)
#define I2C_DMATXWAKE_EN_AAS_ENABLED                                                     (1U)
#define I2C_DMATXWAKE_EN_AAS_DISABLED                                                    (0U)

#define I2C_DMATXWAKE_EN_XUDF_SHIFT                                                     (10U)
#define I2C_DMATXWAKE_EN_XUDF_MASK                                                      (0x00000400U)
#define I2C_DMATXWAKE_EN_XUDF_ENABLED                                                    (1U)
#define I2C_DMATXWAKE_EN_XUDF_DISABLED                                                   (0U)

#define I2C_DMATXWAKE_EN_ROVR_SHIFT                                                     (11U)
#define I2C_DMATXWAKE_EN_ROVR_MASK                                                      (0x00000800U)
#define I2C_DMATXWAKE_EN_ROVR_ENABLED                                                    (1U)
#define I2C_DMATXWAKE_EN_ROVR_DISABLED                                                   (0U)

#define I2C_DMATXWAKE_EN_RDR_SHIFT                                                      (13U)
#define I2C_DMATXWAKE_EN_RDR_MASK                                                       (0x00002000U)
#define I2C_DMATXWAKE_EN_RDR_ENABLED                                                     (1U)
#define I2C_DMATXWAKE_EN_RDR_DISABLED                                                    (0U)

#define I2C_DMATXWAKE_EN_XDR_SHIFT                                                      (14U)
#define I2C_DMATXWAKE_EN_XDR_MASK                                                       (0x00004000U)
#define I2C_DMATXWAKE_EN_XDR_ENABLED                                                     (1U)
#define I2C_DMATXWAKE_EN_XDR_DISABLED                                                    (0U)

#define I2C_IRQSTS_AL_SHIFT                                                             (0U)
#define I2C_IRQSTS_AL_MASK                                                              (0x00000001U)
#define I2C_IRQSTS_AL_NORMAL                                                             (0U)
#define I2C_IRQSTS_AL_ARBITRATION_LOST                                                   (1U)

#define I2C_IRQSTS_NACK_SHIFT                                                           (1U)
#define I2C_IRQSTS_NACK_MASK                                                            (0x00000002U)
#define I2C_IRQSTS_NACK_NORMAL                                                           (0U)
#define I2C_IRQSTS_NACK_NO_ACK                                                           (1U)

#define I2C_IRQSTS_ARDY_SHIFT                                                           (2U)
#define I2C_IRQSTS_ARDY_MASK                                                            (0x00000004U)
#define I2C_IRQSTS_ARDY_ACCESS_READY                                                     (1U)
#define I2C_IRQSTS_ARDY_NO_ACTION                                                        (0U)

#define I2C_IRQSTS_RRDY_SHIFT                                                           (3U)
#define I2C_IRQSTS_RRDY_MASK                                                            (0x00000008U)
#define I2C_IRQSTS_RRDY_FIFO_THRESHOLD_NOT_REACHED                                       (0U)
#define I2C_IRQSTS_RRDY_FIFO_THRESHOLD_REACHED                                           (1U)

#define I2C_IRQSTS_XRDY_SHIFT                                                           (4U)
#define I2C_IRQSTS_XRDY_MASK                                                            (0x00000010U)
#define I2C_IRQSTS_XRDY_READY                                                            (1U)
#define I2C_IRQSTS_XRDY_ONGOING                                                          (0U)

#define I2C_IRQSTS_GC_SHIFT                                                             (5U)
#define I2C_IRQSTS_GC_MASK                                                              (0x00000020U)
#define I2C_IRQSTS_GC_GENERAL_CALL                                                       (1U)
#define I2C_IRQSTS_GC_NO_GENERAL_CALL                                                    (0U)

#define I2C_IRQSTS_STC_SHIFT                                                            (6U)
#define I2C_IRQSTS_STC_MASK                                                             (0x00000040U)
#define I2C_IRQSTS_STC_START_CONDITION                                                   (1U)
#define I2C_IRQSTS_STC_NO_ACTION                                                         (0U)

#define I2C_IRQSTS_AERR_SHIFT                                                           (7U)
#define I2C_IRQSTS_AERR_MASK                                                            (0x00000080U)
#define I2C_IRQSTS_AERR_ACCESS_ERROR                                                     (1U)
#define I2C_IRQSTS_AERR_NO_ACTION                                                        (0U)

#define I2C_IRQSTS_BF_SHIFT                                                             (8U)
#define I2C_IRQSTS_BF_MASK                                                              (0x00000100U)
#define I2C_IRQSTS_BF_BUS_FREE                                                           (1U)
#define I2C_IRQSTS_BF_NO_ACTION                                                          (0U)

#define I2C_IRQSTS_AAS_SHIFT                                                            (9U)
#define I2C_IRQSTS_AAS_MASK                                                             (0x00000200U)
#define I2C_IRQSTS_AAS_ADDRESS_RECOGNIZED                                                (1U)
#define I2C_IRQSTS_AAS_NO_ACTION                                                         (0U)

#define I2C_IRQSTS_XUDF_SHIFT                                                           (10U)
#define I2C_IRQSTS_XUDF_MASK                                                            (0x00000400U)
#define I2C_IRQSTS_XUDF_TRANSMIT_UNDERFLOW                                               (1U)
#define I2C_IRQSTS_XUDF_NORMAL                                                           (0U)

#define I2C_IRQSTS_ROVR_SHIFT                                                           (11U)
#define I2C_IRQSTS_ROVR_MASK                                                            (0x00000800U)
#define I2C_IRQSTS_ROVR_RECEIVER_OVERRUN                                                 (1U)
#define I2C_IRQSTS_ROVR_NORMAL                                                           (0U)

#define I2C_IRQSTS_BB_SHIFT                                                             (12U)
#define I2C_IRQSTS_BB_MASK                                                              (0x00001000U)
#define I2C_IRQSTS_BB_OCCUPIED                                                           (1U)
#define I2C_IRQSTS_BB_FREE                                                               (0U)

#define I2C_IRQSTS_RDR_SHIFT                                                            (13U)
#define I2C_IRQSTS_RDR_MASK                                                             (0x00002000U)
#define I2C_IRQSTS_RDR_INACTIVE                                                          (0U)
#define I2C_IRQSTS_RDR_ENABLED                                                           (1U)

#define I2C_IRQSTS_XDR_SHIFT                                                            (14U)
#define I2C_IRQSTS_XDR_MASK                                                             (0x00004000U)
#define I2C_IRQSTS_XDR_INACTIVE                                                          (0U)
#define I2C_IRQSTS_XDR_ENABLED                                                           (1U)

#define I2C_BUFSTAT_TXSTAT_SHIFT                                                        (0U)
#define I2C_BUFSTAT_TXSTAT_MASK                                                         (0x0000003fU)

#define I2C_BUFSTAT_RXSTAT_SHIFT                                                        (8U)
#define I2C_BUFSTAT_RXSTAT_MASK                                                         (0x00003f00U)

#define I2C_BUFSTAT_FIFODEPTH_SHIFT                                                     (14U)
#define I2C_BUFSTAT_FIFODEPTH_MASK                                                      (0x0000c000U)
#define I2C_BUFSTAT_FIFODEPTH_BYTE_8                                                     (0U)
#define I2C_BUFSTAT_FIFODEPTH_BYTE_16                                                    (1U)
#define I2C_BUFSTAT_FIFODEPTH_BYTE_32                                                    (2U)
#define I2C_BUFSTAT_FIFODEPTH_BYTE_64                                                    (3U)

#define I2C_BUF_TXTRSH_SHIFT                                                            (0U)
#define I2C_BUF_TXTRSH_MASK                                                             (0x0000003fU)
#define I2C_BUF_TXTRSH_THRESHOLD_2                                                       (1U)
#define I2C_BUF_TXTRSH_THRESHOLD_64                                                      (63U)
#define I2C_BUF_TXTRSH_THRESHOLD_1                                                       (0U)

#define I2C_BUF_TXFIFO_CLR_SHIFT                                                        (6U)
#define I2C_BUF_TXFIFO_CLR_MASK                                                         (0x00000040U)
#define I2C_BUF_TXFIFO_CLR_RESET                                                         (1U)
#define I2C_BUF_TXFIFO_CLR_NORMAL                                                        (0U)

#define I2C_BUF_XDMA_EN_SHIFT                                                           (7U)
#define I2C_BUF_XDMA_EN_MASK                                                            (0x00000080U)
#define I2C_BUF_XDMA_EN_ENABLED                                                          (1U)
#define I2C_BUF_XDMA_EN_DISABLED                                                         (0U)

#define I2C_BUF_RXTRSH_SHIFT                                                            (8U)
#define I2C_BUF_RXTRSH_MASK                                                             (0x00003f00U)
#define I2C_BUF_RXTRSH_THRESHOLD_2                                                       (1U)
#define I2C_BUF_RXTRSH_THRESHOLD_1                                                       (0U)
#define I2C_BUF_RXTRSH_THRESHOLD_64                                                      (63U)

#define I2C_BUF_RXFIFO_CLR_SHIFT                                                        (14U)
#define I2C_BUF_RXFIFO_CLR_MASK                                                         (0x00004000U)
#define I2C_BUF_RXFIFO_CLR_RESET                                                         (1U)
#define I2C_BUF_RXFIFO_CLR_NORMAL                                                        (0U)

#define I2C_BUF_RDMA_EN_SHIFT                                                           (15U)
#define I2C_BUF_RDMA_EN_MASK                                                            (0x00008000U)
#define I2C_BUF_RDMA_EN_DISABLED                                                         (0U)
#define I2C_BUF_RDMA_EN_ENABLED                                                          (1U)

#define I2C_OA3_SHIFT                                                                   (0U)
#define I2C_OA3_MASK                                                                    (0x000003ffU)

#define I2C_DMARXEN_SET_DMARX_EN_SHIFT                                                  (0U)
#define I2C_DMARXEN_SET_DMARX_EN_MASK                                                   (0x00000001U)

#define I2C_OA2_SHIFT                                                                   (0U)
#define I2C_OA2_MASK                                                                    (0x000003ffU)

#define I2C_CON_STT_SHIFT                                                               (0U)
#define I2C_CON_STT_MASK                                                                (0x00000001U)
#define I2C_CON_STT_NO_ACTION                                                            (0U)
#define I2C_CON_STT_START_CONDITION                                                      (1U)

#define I2C_CON_STP_SHIFT                                                               (1U)
#define I2C_CON_STP_MASK                                                                (0x00000002U)
#define I2C_CON_STP_STOP_CONDITION                                                       (1U)
#define I2C_CON_STP_NO_ACTION                                                            (0U)

#define I2C_CON_XOA3_SHIFT                                                              (4U)
#define I2C_CON_XOA3_MASK                                                               (0x00000010U)
#define I2C_CON_XOA3_MODE_7                                                              (0U)
#define I2C_CON_XOA3_MODE_10                                                             (1U)

#define I2C_CON_XOA2_SHIFT                                                              (5U)
#define I2C_CON_XOA2_MASK                                                               (0x00000020U)
#define I2C_CON_XOA2_MODE_7                                                              (0U)
#define I2C_CON_XOA2_MODE_10                                                             (1U)

#define I2C_CON_XOA1_SHIFT                                                              (6U)
#define I2C_CON_XOA1_MASK                                                               (0x00000040U)
#define I2C_CON_XOA1_MODE_7                                                              (0U)
#define I2C_CON_XOA1_MODE_10                                                             (1U)

#define I2C_CON_XOA0_SHIFT                                                              (7U)
#define I2C_CON_XOA0_MASK                                                               (0x00000080U)
#define I2C_CON_XOA0_MODE_7                                                              (0U)
#define I2C_CON_XOA0_MODE_10                                                             (1U)

#define I2C_CON_XSA_SHIFT                                                               (8U)
#define I2C_CON_XSA_MASK                                                                (0x00000100U)
#define I2C_CON_XSA_MODE_7                                                               (0U)
#define I2C_CON_XSA_MODE_10                                                              (1U)

#define I2C_CON_TRX_SHIFT                                                               (9U)
#define I2C_CON_TRX_MASK                                                                (0x00000200U)
#define I2C_CON_TRX_TRANSMITTER                                                          (1U)
#define I2C_CON_TRX_RECEIVER                                                             (0U)

#define I2C_CON_MST_SHIFT                                                               (10U)
#define I2C_CON_MST_MASK                                                                (0x00000400U)
#define I2C_CON_MST_MASTER                                                               (1U)
#define I2C_CON_MST_SLAVE                                                                (0U)

#define I2C_CON_STB_SHIFT                                                               (11U)
#define I2C_CON_STB_MASK                                                                (0x00000800U)
#define I2C_CON_STB_NORMAL                                                               (0U)
#define I2C_CON_STB_START_BYTE                                                           (1U)

#define I2C_CON_OPMODE_SHIFT                                                            (12U)
#define I2C_CON_OPMODE_MASK                                                             (0x00003000U)
#define I2C_CON_OPMODE_FAST                                                              (0U)

#define I2C_CON_EN_SHIFT                                                                (15U)
#define I2C_CON_EN_MASK                                                                 (0x00008000U)
#define I2C_CON_EN_ENABLED                                                               (1U)
#define I2C_CON_EN_RESET                                                                 (0U)

#define I2C_ACTOA_OA0_ACT_SHIFT                                                         (0U)
#define I2C_ACTOA_OA0_ACT_MASK                                                          (0x00000001U)
#define I2C_ACTOA_OA0_ACT_INACTIVE                                                       (0U)
#define I2C_ACTOA_OA0_ACT_ACTIVE                                                         (1U)

#define I2C_ACTOA_OA1_ACT_SHIFT                                                         (1U)
#define I2C_ACTOA_OA1_ACT_MASK                                                          (0x00000002U)
#define I2C_ACTOA_OA1_ACT_INACTIVE                                                       (0U)
#define I2C_ACTOA_OA1_ACT_ACTIVE                                                         (1U)

#define I2C_ACTOA_OA2_ACT_SHIFT                                                         (2U)
#define I2C_ACTOA_OA2_ACT_MASK                                                          (0x00000004U)
#define I2C_ACTOA_OA2_ACT_INACTIVE                                                       (0U)
#define I2C_ACTOA_OA2_ACT_ACTIVE                                                         (1U)

#define I2C_ACTOA_OA3_ACT_SHIFT                                                         (3U)
#define I2C_ACTOA_OA3_ACT_MASK                                                          (0x00000008U)
#define I2C_ACTOA_OA3_ACT_INACTIVE                                                       (0U)
#define I2C_ACTOA_OA3_ACT_ACTIVE                                                         (1U)

#define I2C_SA_SHIFT                                                                    (0U)
#define I2C_SA_MASK                                                                     (0x000003ffU)

#define I2C_WE_AL_SHIFT                                                                 (0U)
#define I2C_WE_AL_MASK                                                                  (0x00000001U)
#define I2C_WE_AL_ENABLED                                                                (1U)
#define I2C_WE_AL_DISABLED                                                               (0U)

#define I2C_WE_NACK_SHIFT                                                               (1U)
#define I2C_WE_NACK_MASK                                                                (0x00000002U)
#define I2C_WE_NACK_ENABLED                                                              (1U)
#define I2C_WE_NACK_DISABLED                                                             (0U)

#define I2C_WE_ARDY_SHIFT                                                               (2U)
#define I2C_WE_ARDY_MASK                                                                (0x00000004U)
#define I2C_WE_ARDY_ENABLED                                                              (1U)
#define I2C_WE_ARDY_DISABLED                                                             (0U)

#define I2C_WE_DRDY_SHIFT                                                               (3U)
#define I2C_WE_DRDY_MASK                                                                (0x00000008U)
#define I2C_WE_DRDY_ENABLED                                                              (1U)
#define I2C_WE_DRDY_DISABLED                                                             (0U)

#define I2C_WE_GC_SHIFT                                                                 (5U)
#define I2C_WE_GC_MASK                                                                  (0x00000020U)
#define I2C_WE_GC_ENABLED                                                                (1U)
#define I2C_WE_GC_DISABLED                                                               (0U)

#define I2C_WE_STC_SHIFT                                                                (6U)
#define I2C_WE_STC_MASK                                                                 (0x00000040U)
#define I2C_WE_STC_ENABLED                                                               (1U)
#define I2C_WE_STC_DISABLED                                                              (0U)

#define I2C_WE_BF_SHIFT                                                                 (8U)
#define I2C_WE_BF_MASK                                                                  (0x00000100U)
#define I2C_WE_BF_ENABLED                                                                (1U)
#define I2C_WE_BF_DISABLED                                                               (0U)

#define I2C_WE_AAS_SHIFT                                                                (9U)
#define I2C_WE_AAS_MASK                                                                 (0x00000200U)
#define I2C_WE_AAS_ENABLED                                                               (1U)
#define I2C_WE_AAS_DISABLED                                                              (0U)

#define I2C_WE_XUDF_SHIFT                                                               (10U)
#define I2C_WE_XUDF_MASK                                                                (0x00000400U)
#define I2C_WE_XUDF_ENABLED                                                              (1U)
#define I2C_WE_XUDF_DISABLED                                                             (0U)

#define I2C_WE_ROVR_SHIFT                                                               (11U)
#define I2C_WE_ROVR_MASK                                                                (0x00000800U)
#define I2C_WE_ROVR_ENABLED                                                              (1U)
#define I2C_WE_ROVR_DISABLED                                                             (0U)

#define I2C_WE_RDR_SHIFT                                                                (13U)
#define I2C_WE_RDR_MASK                                                                 (0x00002000U)
#define I2C_WE_RDR_ENABLED                                                               (1U)
#define I2C_WE_RDR_DISABLED                                                              (0U)

#define I2C_WE_XDR_SHIFT                                                                (14U)
#define I2C_WE_XDR_MASK                                                                 (0x00004000U)
#define I2C_WE_XDR_ENABLED                                                               (1U)
#define I2C_WE_XDR_DISABLED                                                              (0U)

#define I2C_DMATXEN_CLR_DMATX_EN_SHIFT                                                  (0U)
#define I2C_DMATXEN_CLR_DMATX_EN_MASK                                                   (0x00000001U)

#define I2C_OA1_SHIFT                                                                   (0U)
#define I2C_OA1_MASK                                                                    (0x000003ffU)

#define I2C_SCLL_SHIFT                                                                  (0U)
#define I2C_SCLL_MASK                                                                   (0x000000ffU)

#define I2C_IRQEN_SET_AL_IE_SHIFT                                                       (0U)
#define I2C_IRQEN_SET_AL_IE_MASK                                                        (0x00000001U)
#define I2C_IRQEN_SET_AL_IE_ENABLED                                                      (1U)
#define I2C_IRQEN_SET_AL_IE_DISABLED                                                     (0U)

#define I2C_IRQEN_SET_NACK_IE_SHIFT                                                     (1U)
#define I2C_IRQEN_SET_NACK_IE_MASK                                                      (0x00000002U)
#define I2C_IRQEN_SET_NACK_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_SET_NACK_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_SET_ARDY_IE_SHIFT                                                     (2U)
#define I2C_IRQEN_SET_ARDY_IE_MASK                                                      (0x00000004U)
#define I2C_IRQEN_SET_ARDY_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_SET_ARDY_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_SET_RRDY_IE_SHIFT                                                     (3U)
#define I2C_IRQEN_SET_RRDY_IE_MASK                                                      (0x00000008U)
#define I2C_IRQEN_SET_RRDY_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_SET_RRDY_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_SET_XRDY_IE_SHIFT                                                     (4U)
#define I2C_IRQEN_SET_XRDY_IE_MASK                                                      (0x00000010U)
#define I2C_IRQEN_SET_XRDY_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_SET_XRDY_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_SET_GC_IE_SHIFT                                                       (5U)
#define I2C_IRQEN_SET_GC_IE_MASK                                                        (0x00000020U)
#define I2C_IRQEN_SET_GC_IE_ENABLED                                                      (1U)
#define I2C_IRQEN_SET_GC_IE_DISABLED                                                     (0U)

#define I2C_IRQEN_SET_STC_IE_SHIFT                                                      (6U)
#define I2C_IRQEN_SET_STC_IE_MASK                                                       (0x00000040U)
#define I2C_IRQEN_SET_STC_IE_ENABLED                                                     (1U)
#define I2C_IRQEN_SET_STC_IE_DISABLED                                                    (0U)

#define I2C_IRQEN_SET_AERR_IE_SHIFT                                                     (7U)
#define I2C_IRQEN_SET_AERR_IE_MASK                                                      (0x00000080U)
#define I2C_IRQEN_SET_AERR_IE_ENABLED                                                    (1U)
#define I2C_IRQEN_SET_AERR_IE_DISABLED                                                   (0U)

#define I2C_IRQEN_SET_BF_IE_SHIFT                                                       (8U)
#define I2C_IRQEN_SET_BF_IE_MASK                                                        (0x00000100U)
#define I2C_IRQEN_SET_BF_IE_ENABLED                                                      (1U)
#define I2C_IRQEN_SET_BF_IE_DISABLED                                                     (0U)

#define I2C_IRQEN_SET_AAS_IE_SHIFT                                                      (9U)
#define I2C_IRQEN_SET_AAS_IE_MASK                                                       (0x00000200U)
#define I2C_IRQEN_SET_AAS_IE_ENABLED                                                     (1U)
#define I2C_IRQEN_SET_AAS_IE_DISABLED                                                    (0U)

#define I2C_IRQEN_SET_XUDF_SHIFT                                                        (10U)
#define I2C_IRQEN_SET_XUDF_MASK                                                         (0x00000400U)
#define I2C_IRQEN_SET_XUDF_ENABLED                                                       (1U)
#define I2C_IRQEN_SET_XUDF_DISABLED                                                      (0U)

#define I2C_IRQEN_SET_ROVR_SHIFT                                                        (11U)
#define I2C_IRQEN_SET_ROVR_MASK                                                         (0x00000800U)
#define I2C_IRQEN_SET_ROVR_ENABLED                                                       (1U)
#define I2C_IRQEN_SET_ROVR_DISABLED                                                      (0U)

#define I2C_IRQEN_SET_RDR_IE_SHIFT                                                      (13U)
#define I2C_IRQEN_SET_RDR_IE_MASK                                                       (0x00002000U)
#define I2C_IRQEN_SET_RDR_IE_ENABLED                                                     (1U)
#define I2C_IRQEN_SET_RDR_IE_DISABLED                                                    (0U)

#define I2C_IRQEN_SET_XDR_IE_SHIFT                                                      (14U)
#define I2C_IRQEN_SET_XDR_IE_MASK                                                       (0x00004000U)
#define I2C_IRQEN_SET_XDR_IE_ENABLED                                                     (1U)
#define I2C_IRQEN_SET_XDR_IE_DISABLED                                                    (0U)

#define I2C_SYSC_AUTOIDLE_SHIFT                                                         (0U)
#define I2C_SYSC_AUTOIDLE_MASK                                                          (0x00000001U)
#define I2C_SYSC_AUTOIDLE_ENABLE                                                         (1U)
#define I2C_SYSC_AUTOIDLE_DISABLE                                                        (0U)

#define I2C_SYSC_SRST_SHIFT                                                             (1U)
#define I2C_SYSC_SRST_MASK                                                              (0x00000002U)
#define I2C_SYSC_SRST_NORMAL_MODE                                                        (0U)
#define I2C_SYSC_SRST_RESET                                                              (1U)

#define I2C_SYSC_ENAWAKEUP_SHIFT                                                        (2U)
#define I2C_SYSC_ENAWAKEUP_MASK                                                         (0x00000004U)
#define I2C_SYSC_ENAWAKEUP_ENABLE                                                        (1U)
#define I2C_SYSC_ENAWAKEUP_DISABLE                                                       (0U)

#define I2C_SYSC_IDLEMODE_SHIFT                                                         (3U)
#define I2C_SYSC_IDLEMODE_MASK                                                          (0x00000018U)
#define I2C_SYSC_IDLEMODE_FORCE_IDLE                                                     (0U)
#define I2C_SYSC_IDLEMODE_NO_IDLE                                                        (1U)
#define I2C_SYSC_IDLEMODE_SMART_IDLE                                                     (2U)
#define I2C_SYSC_IDLEMODE_SMART_IDLE_WAKEUP                                              (3U)

#define I2C_SYSC_CLKACTIVITY_SHIFT                                                      (8U)
#define I2C_SYSC_CLKACTIVITY_MASK                                                       (0x00000300U)
#define I2C_SYSC_CLKACTIVITY_INTERFACE_ACTIVE                                            (1U)
#define I2C_SYSC_CLKACTIVITY_BOTH_ACTIVE                                                 (3U)
#define I2C_SYSC_CLKACTIVITY_SYSTEM_ACTIVE                                               (2U)
#define I2C_SYSC_CLKACTIVITY_BOTH_CUT_OFF                                                (0U)

#define I2C_DMARXEN_CLR_DMARX_EN_SHIFT                                                  (0U)
#define I2C_DMARXEN_CLR_DMARX_EN_MASK                                                   (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_I2C_H_ */

