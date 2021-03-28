/*
* hw_cpsw_cpdma.h
*
* Register-level header file for CPSW_CPDMA
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

#ifndef HW_CPSW_CPDMA_H_
#define HW_CPSW_CPDMA_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CPSW_CPDMA_DMA_INTSTAT_RAW                                  (0xb0U)
#define CPSW_CPDMA_RX_PENDTHRESH(n)                                 (0xc0U + ((n) * 0x4U))
#define CPSW_CPDMA_DMA_INTMASK_SET                                  (0xb8U)
#define CPSW_CPDMA_IN_VECTOR                                        (0x90U)
#define CPSW_CPDMA_DMA_INTSTAT_MASKED                               (0xb4U)
#define CPSW_CPDMA_TX_INTMASK_CLR                                   (0x8cU)
#define CPSW_CPDMA_RX_BUFFER_OFFSET                                 (0x28U)
#define CPSW_CPDMA_RX_INTMASK_SET                                   (0xa8U)
#define CPSW_CPDMA_RX_FREEBUFFER(n)                                 (0xe0U + ((n) * 0x4U))
#define CPSW_CPDMA_SOFT_RESET                                       (0x1cU)
#define CPSW_CPDMA_TX_PRI_RATE(n)                                   (0x30U + ((n) * 0x4U))
#define CPSW_CPDMA_TX_INTMASK_SET                                   (0x88U)
#define CPSW_CPDMA_EMCTRL                                           (0x2cU)
#define CPSW_CPDMA_DMACTRL                                          (0x20U)
#define CPSW_CPDMA_TX_TEARDOWN                                      (0x8U)
#define CPSW_CPDMA_RX_IDVER                                         (0x10U)
#define CPSW_CPDMA_DMASTS                                           (0x24U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED                                (0xa4U)
#define CPSW_CPDMA_TX_IDVER                                         (0x0U)
#define CPSW_CPDMA_TX_INTSTAT_RAW                                   (0x80U)
#define CPSW_CPDMA_RX_TEARDOWN                                      (0x18U)
#define CPSW_CPDMA_EOI_VECTOR                                       (0x94U)
#define CPSW_CPDMA_RX_INTMASK_CLR                                   (0xacU)
#define CPSW_CPDMA_DMA_INTMASK_CLR                                  (0xbcU)
#define CPSW_CPDMA_TX_CTRL                                          (0x4U)
#define CPSW_CPDMA_TX_INTSTAT_MASKED                                (0x84U)
#define CPSW_CPDMA_RX_INTSTAT_RAW                                   (0xa0U)
#define CPSW_CPDMA_RX_CTRL                                          (0x14U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CPSW_CPDMA_DMA_INTSTAT_RAW_STAT_PEND_SHIFT                                      (0U)
#define CPSW_CPDMA_DMA_INTSTAT_RAW_STAT_PEND_MASK                                       (0x00000001U)

#define CPSW_CPDMA_DMA_INTSTAT_RAW_HOST_PEND_SHIFT                                      (1U)
#define CPSW_CPDMA_DMA_INTSTAT_RAW_HOST_PEND_MASK                                       (0x00000002U)

#define CPSW_CPDMA_RX_PENDTHRESH_RX_SHIFT                                               (0U)
#define CPSW_CPDMA_RX_PENDTHRESH_RX_MASK                                                (0x000000ffU)

#define CPSW_CPDMA_DMA_INTMASK_SET_STAT_INT_MASK_SHIFT                                  (0U)
#define CPSW_CPDMA_DMA_INTMASK_SET_STAT_INT_MASK_MASK                                   (0x00000001U)

#define CPSW_CPDMA_DMA_INTMASK_SET_HOST_ERR_INT_MASK_SHIFT                              (1U)
#define CPSW_CPDMA_DMA_INTMASK_SET_HOST_ERR_INT_MASK_MASK                               (0x00000002U)

#define CPSW_CPDMA_IN_VECTOR_DMA_SHIFT                                                  (0U)
#define CPSW_CPDMA_IN_VECTOR_DMA_MASK                                                   (0xffffffffU)

#define CPSW_CPDMA_DMA_INTSTAT_MASKED_STAT_PEND_SHIFT                                   (0U)
#define CPSW_CPDMA_DMA_INTSTAT_MASKED_STAT_PEND_MASK                                    (0x00000001U)

#define CPSW_CPDMA_DMA_INTSTAT_MASKED_HOST_PEND_SHIFT                                   (1U)
#define CPSW_CPDMA_DMA_INTSTAT_MASKED_HOST_PEND_MASK                                    (0x00000002U)

#define CPSW_CPDMA_TX_INTMASK_CLR_TX0_MASK_SHIFT                                        (0U)
#define CPSW_CPDMA_TX_INTMASK_CLR_TX0_MASK_MASK                                         (0x00000001U)

#define CPSW_CPDMA_TX_INTMASK_CLR_TX1_MASK_SHIFT                                        (1U)
#define CPSW_CPDMA_TX_INTMASK_CLR_TX1_MASK_MASK                                         (0x00000002U)

#define CPSW_CPDMA_TX_INTMASK_CLR_TX2_MASK_SHIFT                                        (2U)
#define CPSW_CPDMA_TX_INTMASK_CLR_TX2_MASK_MASK                                         (0x00000004U)

#define CPSW_CPDMA_TX_INTMASK_CLR_TX3_MASK_SHIFT                                        (3U)
#define CPSW_CPDMA_TX_INTMASK_CLR_TX3_MASK_MASK                                         (0x00000008U)

#define CPSW_CPDMA_TX_INTMASK_CLR_TX4_MASK_SHIFT                                        (4U)
#define CPSW_CPDMA_TX_INTMASK_CLR_TX4_MASK_MASK                                         (0x00000010U)

#define CPSW_CPDMA_TX_INTMASK_CLR_TX5_MASK_SHIFT                                        (5U)
#define CPSW_CPDMA_TX_INTMASK_CLR_TX5_MASK_MASK                                         (0x00000020U)

#define CPSW_CPDMA_TX_INTMASK_CLR_TX6_MASK_SHIFT                                        (6U)
#define CPSW_CPDMA_TX_INTMASK_CLR_TX6_MASK_MASK                                         (0x00000040U)

#define CPSW_CPDMA_TX_INTMASK_CLR_TX7_MASK_SHIFT                                        (7U)
#define CPSW_CPDMA_TX_INTMASK_CLR_TX7_MASK_MASK                                         (0x00000080U)

#define CPSW_CPDMA_RX_BUFFER_OFFSET_SHIFT                                               (0U)
#define CPSW_CPDMA_RX_BUFFER_OFFSET_MASK                                                (0x0000ffffU)

#define CPSW_CPDMA_RX_INTMASK_SET_RX0_PEND_MASK_SHIFT                                   (0U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX0_PEND_MASK_MASK                                    (0x00000001U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX1_PEND_MASK_SHIFT                                   (1U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX1_PEND_MASK_MASK                                    (0x00000002U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX2_PEND_MASK_SHIFT                                   (2U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX2_PEND_MASK_MASK                                    (0x00000004U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX3_PEND_MASK_SHIFT                                   (3U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX3_PEND_MASK_MASK                                    (0x00000008U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX4_PEND_MASK_SHIFT                                   (4U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX4_PEND_MASK_MASK                                    (0x00000010U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX5_PEND_MASK_SHIFT                                   (5U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX5_PEND_MASK_MASK                                    (0x00000020U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX6_PEND_MASK_SHIFT                                   (6U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX6_PEND_MASK_MASK                                    (0x00000040U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX7_PEND_MASK_SHIFT                                   (7U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX7_PEND_MASK_MASK                                    (0x00000080U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX0_THRESH_PEND_MASK_SHIFT                            (8U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX0_THRESH_PEND_MASK_MASK                             (0x00000100U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX1_THRESH_PEND_MASK_SHIFT                            (9U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX1_THRESH_PEND_MASK_MASK                             (0x00000200U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX2_THRESH_PEND_MASK_SHIFT                            (10U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX2_THRESH_PEND_MASK_MASK                             (0x00000400U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX3_THRESH_PEND_MASK_SHIFT                            (11U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX3_THRESH_PEND_MASK_MASK                             (0x00000800U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX4_THRESH_PEND_MASK_SHIFT                            (12U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX4_THRESH_PEND_MASK_MASK                             (0x00001000U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX5_THRESH_PEND_MASK_SHIFT                            (13U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX5_THRESH_PEND_MASK_MASK                             (0x00002000U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX6_THRESH_PEND_MASK_SHIFT                            (14U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX6_THRESH_PEND_MASK_MASK                             (0x00004000U)

#define CPSW_CPDMA_RX_INTMASK_SET_RX7_THRESH_PEND_MASK_SHIFT                            (15U)
#define CPSW_CPDMA_RX_INTMASK_SET_RX7_THRESH_PEND_MASK_MASK                             (0x00008000U)

#define CPSW_CPDMA_SOFT_RESET_SHIFT                                                     (0U)
#define CPSW_CPDMA_SOFT_RESET_MASK                                                      (0x00000001U)
#define CPSW_CPDMA_SOFT_RESET_EN_0x1                                                     (1U)
#define CPSW_CPDMA_SOFT_RESET_EN_0x0                                                     (0U)

#define CPSW_CPDMA_TX_PRI_RATE_PRIN_SEND_CNT_SHIFT                                      (0U)
#define CPSW_CPDMA_TX_PRI_RATE_PRIN_SEND_CNT_MASK                                       (0x00003fffU)

#define CPSW_CPDMA_TX_PRI_RATE_PRIN_IDLE_CNT_SHIFT                                      (16U)
#define CPSW_CPDMA_TX_PRI_RATE_PRIN_IDLE_CNT_MASK                                       (0x3fff0000U)

#define CPSW_CPDMA_TX_INTMASK_SET_TX0_MASK_SHIFT                                        (0U)
#define CPSW_CPDMA_TX_INTMASK_SET_TX0_MASK_MASK                                         (0x00000001U)

#define CPSW_CPDMA_TX_INTMASK_SET_TX1_MASK_SHIFT                                        (1U)
#define CPSW_CPDMA_TX_INTMASK_SET_TX1_MASK_MASK                                         (0x00000002U)

#define CPSW_CPDMA_TX_INTMASK_SET_TX2_MASK_SHIFT                                        (2U)
#define CPSW_CPDMA_TX_INTMASK_SET_TX2_MASK_MASK                                         (0x00000004U)

#define CPSW_CPDMA_TX_INTMASK_SET_TX3_MASK_SHIFT                                        (3U)
#define CPSW_CPDMA_TX_INTMASK_SET_TX3_MASK_MASK                                         (0x00000008U)

#define CPSW_CPDMA_TX_INTMASK_SET_TX4_MASK_SHIFT                                        (4U)
#define CPSW_CPDMA_TX_INTMASK_SET_TX4_MASK_MASK                                         (0x00000010U)

#define CPSW_CPDMA_TX_INTMASK_SET_TX5_MASK_SHIFT                                        (5U)
#define CPSW_CPDMA_TX_INTMASK_SET_TX5_MASK_MASK                                         (0x00000020U)

#define CPSW_CPDMA_TX_INTMASK_SET_TX6_MASK_SHIFT                                        (6U)
#define CPSW_CPDMA_TX_INTMASK_SET_TX6_MASK_MASK                                         (0x00000040U)

#define CPSW_CPDMA_TX_INTMASK_SET_TX7_MASK_SHIFT                                        (7U)
#define CPSW_CPDMA_TX_INTMASK_SET_TX7_MASK_MASK                                         (0x00000080U)

#define CPSW_CPDMA_EMCTRL_FREE_SHIFT                                                    (0U)
#define CPSW_CPDMA_EMCTRL_FREE_MASK                                                     (0x00000001U)

#define CPSW_CPDMA_EMCTRL_SOFT_SHIFT                                                    (1U)
#define CPSW_CPDMA_EMCTRL_SOFT_MASK                                                     (0x00000002U)

#define CPSW_CPDMA_DMACTRL_TX_PTYPE_SHIFT                                               (0U)
#define CPSW_CPDMA_DMACTRL_TX_PTYPE_MASK                                                (0x00000001U)

#define CPSW_CPDMA_DMACTRL_RX_OWNERSHIP_SHIFT                                           (1U)
#define CPSW_CPDMA_DMACTRL_RX_OWNERSHIP_MASK                                            (0x00000002U)

#define CPSW_CPDMA_DMACTRL_RX_OFFLEN_BLOCK_SHIFT                                        (2U)
#define CPSW_CPDMA_DMACTRL_RX_OFFLEN_BLOCK_MASK                                         (0x00000004U)

#define CPSW_CPDMA_DMACTRL_CMD_IDLE_SHIFT                                               (3U)
#define CPSW_CPDMA_DMACTRL_CMD_IDLE_MASK                                                (0x00000008U)
#define CPSW_CPDMA_DMACTRL_CMD_IDLE_ENABLE                                               (1U)
#define CPSW_CPDMA_DMACTRL_CMD_IDLE_DISABLE                                              (0U)

#define CPSW_CPDMA_DMACTRL_RX_CEF_SHIFT                                                 (4U)
#define CPSW_CPDMA_DMACTRL_RX_CEF_MASK                                                  (0x00000010U)

#define CPSW_CPDMA_DMACTRL_TX_RLIM_SHIFT                                                (8U)
#define CPSW_CPDMA_DMACTRL_TX_RLIM_MASK                                                 (0x0000ff00U)

#define CPSW_CPDMA_TX_TEARDOWN_TDN_CH_SHIFT                                             (0U)
#define CPSW_CPDMA_TX_TEARDOWN_TDN_CH_MASK                                              (0x00000007U)

#define CPSW_CPDMA_TX_TEARDOWN_TDN_RDY_SHIFT                                            (31U)
#define CPSW_CPDMA_TX_TEARDOWN_TDN_RDY_MASK                                             (0x80000000U)

#define CPSW_CPDMA_RX_IDVER_MINOR_VER_SHIFT                                             (0U)
#define CPSW_CPDMA_RX_IDVER_MINOR_VER_MASK                                              (0x000000ffU)

#define CPSW_CPDMA_RX_IDVER_MAJOR_VER_SHIFT                                             (8U)
#define CPSW_CPDMA_RX_IDVER_MAJOR_VER_MASK                                              (0x0000ff00U)

#define CPSW_CPDMA_RX_IDVER_IDENT_SHIFT                                                 (16U)
#define CPSW_CPDMA_RX_IDVER_IDENT_MASK                                                  (0xffff0000U)

#define CPSW_CPDMA_DMASTS_RX_ERR_CH_SHIFT                                               (8U)
#define CPSW_CPDMA_DMASTS_RX_ERR_CH_MASK                                                (0x00000700U)

#define CPSW_CPDMA_DMASTS_RX_HOST_ERR_CODE_SHIFT                                        (12U)
#define CPSW_CPDMA_DMASTS_RX_HOST_ERR_CODE_MASK                                         (0x0000f000U)

#define CPSW_CPDMA_DMASTS_TX_ERR_CH_SHIFT                                               (16U)
#define CPSW_CPDMA_DMASTS_TX_ERR_CH_MASK                                                (0x00070000U)

#define CPSW_CPDMA_DMASTS_TX_HOST_ERR_CODE_SHIFT                                        (20U)
#define CPSW_CPDMA_DMASTS_TX_HOST_ERR_CODE_MASK                                         (0x00f00000U)

#define CPSW_CPDMA_DMASTS_IDLE_SHIFT                                                    (31U)
#define CPSW_CPDMA_DMASTS_IDLE_MASK                                                     (0x80000000U)
#define CPSW_CPDMA_DMASTS_IDLE_EN_0x1                                                    (1U)
#define CPSW_CPDMA_DMASTS_IDLE_EN_0x0                                                    (0U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX0_PEND_SHIFT                                     (0U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX0_PEND_MASK                                      (0x00000001U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX1_PEND_SHIFT                                     (1U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX1_PEND_MASK                                      (0x00000002U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX2_PEND_SHIFT                                     (2U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX2_PEND_MASK                                      (0x00000004U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX3_PEND_SHIFT                                     (3U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX3_PEND_MASK                                      (0x00000008U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX4_PEND_SHIFT                                     (4U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX4_PEND_MASK                                      (0x00000010U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX5_PEND_SHIFT                                     (5U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX5_PEND_MASK                                      (0x00000020U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX6_PEND_SHIFT                                     (6U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX6_PEND_MASK                                      (0x00000040U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX7_PEND_SHIFT                                     (7U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX7_PEND_MASK                                      (0x00000080U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX0_THRESH_PEND_SHIFT                              (8U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX0_THRESH_PEND_MASK                               (0x00000100U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX1_THRESH_PEND_SHIFT                              (9U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX1_THRESH_PEND_MASK                               (0x00000200U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX2_THRESH_PEND_SHIFT                              (10U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX2_THRESH_PEND_MASK                               (0x00000400U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX3_THRESH_PEND_SHIFT                              (11U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX3_THRESH_PEND_MASK                               (0x00000800U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX4_THRESH_PEND_SHIFT                              (12U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX4_THRESH_PEND_MASK                               (0x00001000U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX5_THRESH_PEND_SHIFT                              (13U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX5_THRESH_PEND_MASK                               (0x00002000U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX6_THRESH_PEND_SHIFT                              (14U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX6_THRESH_PEND_MASK                               (0x00004000U)

#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX7_THRESH_PEND_SHIFT                              (15U)
#define CPSW_CPDMA_RX_INTSTAT_MASKED_RX7_THRESH_PEND_MASK                               (0x00008000U)

#define CPSW_CPDMA_TX_IDVER_MINOR_VER_SHIFT                                             (0U)
#define CPSW_CPDMA_TX_IDVER_MINOR_VER_MASK                                              (0x000000ffU)

#define CPSW_CPDMA_TX_IDVER_MAJOR_VER_SHIFT                                             (8U)
#define CPSW_CPDMA_TX_IDVER_MAJOR_VER_MASK                                              (0x0000ff00U)

#define CPSW_CPDMA_TX_IDVER_IDENT_SHIFT                                                 (16U)
#define CPSW_CPDMA_TX_IDVER_IDENT_MASK                                                  (0xffff0000U)

#define CPSW_CPDMA_TX_INTSTAT_RAW_TX0_PEND_SHIFT                                        (0U)
#define CPSW_CPDMA_TX_INTSTAT_RAW_TX0_PEND_MASK                                         (0x00000001U)

#define CPSW_CPDMA_TX_INTSTAT_RAW_TX1_PEND_SHIFT                                        (1U)
#define CPSW_CPDMA_TX_INTSTAT_RAW_TX1_PEND_MASK                                         (0x00000002U)

#define CPSW_CPDMA_TX_INTSTAT_RAW_TX2_PEND_SHIFT                                        (2U)
#define CPSW_CPDMA_TX_INTSTAT_RAW_TX2_PEND_MASK                                         (0x00000004U)

#define CPSW_CPDMA_TX_INTSTAT_RAW_TX3_PEND_SHIFT                                        (3U)
#define CPSW_CPDMA_TX_INTSTAT_RAW_TX3_PEND_MASK                                         (0x00000008U)

#define CPSW_CPDMA_TX_INTSTAT_RAW_TX4_PEND_SHIFT                                        (4U)
#define CPSW_CPDMA_TX_INTSTAT_RAW_TX4_PEND_MASK                                         (0x00000010U)

#define CPSW_CPDMA_TX_INTSTAT_RAW_TX5_PEND_SHIFT                                        (5U)
#define CPSW_CPDMA_TX_INTSTAT_RAW_TX5_PEND_MASK                                         (0x00000020U)

#define CPSW_CPDMA_TX_INTSTAT_RAW_TX6_PEND_SHIFT                                        (6U)
#define CPSW_CPDMA_TX_INTSTAT_RAW_TX6_PEND_MASK                                         (0x00000040U)

#define CPSW_CPDMA_TX_INTSTAT_RAW_TX7_PEND_SHIFT                                        (7U)
#define CPSW_CPDMA_TX_INTSTAT_RAW_TX7_PEND_MASK                                         (0x00000080U)

#define CPSW_CPDMA_RX_TEARDOWN_TDN_CH_SHIFT                                             (0U)
#define CPSW_CPDMA_RX_TEARDOWN_TDN_CH_MASK                                              (0x00000007U)

#define CPSW_CPDMA_RX_TEARDOWN_TDN_RDY_SHIFT                                            (31U)
#define CPSW_CPDMA_RX_TEARDOWN_TDN_RDY_MASK                                             (0x80000000U)

#define CPSW_CPDMA_EOI_VECTOR_DMA_SHIFT                                                 (0U)
#define CPSW_CPDMA_EOI_VECTOR_DMA_MASK                                                  (0x0000001fU)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX0_PEND_MASK_SHIFT                                   (0U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX0_PEND_MASK_MASK                                    (0x00000001U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX1_PEND_MASK_SHIFT                                   (1U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX1_PEND_MASK_MASK                                    (0x00000002U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX2_PEND_MASK_SHIFT                                   (2U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX2_PEND_MASK_MASK                                    (0x00000004U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX3_PEND_MASK_SHIFT                                   (3U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX3_PEND_MASK_MASK                                    (0x00000008U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX4_PEND_MASK_SHIFT                                   (4U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX4_PEND_MASK_MASK                                    (0x00000010U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX5_PEND_MASK_SHIFT                                   (5U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX5_PEND_MASK_MASK                                    (0x00000020U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX6_PEND_MASK_SHIFT                                   (6U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX6_PEND_MASK_MASK                                    (0x00000040U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX7_PEND_MASK_SHIFT                                   (7U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX7_PEND_MASK_MASK                                    (0x00000080U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX0_THRESH_PEND_MASK_SHIFT                            (8U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX0_THRESH_PEND_MASK_MASK                             (0x00000100U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX1_THRESH_PEND_MASK_SHIFT                            (9U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX1_THRESH_PEND_MASK_MASK                             (0x00000200U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX2_THRESH_PEND_MASK_SHIFT                            (10U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX2_THRESH_PEND_MASK_MASK                             (0x00000400U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX3_THRESH_PEND_MASK_SHIFT                            (11U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX3_THRESH_PEND_MASK_MASK                             (0x00000800U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX4_THRESH_PEND_MASK_SHIFT                            (12U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX4_THRESH_PEND_MASK_MASK                             (0x00001000U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX5_THRESH_PEND_MASK_SHIFT                            (13U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX5_THRESH_PEND_MASK_MASK                             (0x00002000U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX6_THRESH_PEND_MASK_SHIFT                            (14U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX6_THRESH_PEND_MASK_MASK                             (0x00004000U)

#define CPSW_CPDMA_RX_INTMASK_CLR_RX7_THRESH_PEND_MASK_SHIFT                            (15U)
#define CPSW_CPDMA_RX_INTMASK_CLR_RX7_THRESH_PEND_MASK_MASK                             (0x00008000U)

#define CPSW_CPDMA_DMA_INTMASK_CLR_STAT_INT_MASK_SHIFT                                  (0U)
#define CPSW_CPDMA_DMA_INTMASK_CLR_STAT_INT_MASK_MASK                                   (0x00000001U)

#define CPSW_CPDMA_DMA_INTMASK_CLR_HOST_ERR_INT_MASK_SHIFT                              (1U)
#define CPSW_CPDMA_DMA_INTMASK_CLR_HOST_ERR_INT_MASK_MASK                               (0x00000002U)

#define CPSW_CPDMA_RX_FREEBUFFER_RX_SHIFT                                               (0U)
#define CPSW_CPDMA_RX_FREEBUFFER_RX_MASK                                                (0x0000ffffU)

#define CPSW_CPDMA_TX_CTRL_EN_SHIFT                                                     (0U)
#define CPSW_CPDMA_TX_CTRL_EN_MASK                                                      (0x00000001U)
#define CPSW_CPDMA_TX_CTRL_EN_EN_0x1                                                     (1U)
#define CPSW_CPDMA_TX_CTRL_EN_EN_0x0                                                     (0U)

#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX0_PEND_SHIFT                                     (0U)
#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX0_PEND_MASK                                      (0x00000001U)

#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX1_PEND_SHIFT                                     (1U)
#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX1_PEND_MASK                                      (0x00000002U)

#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX2_PEND_SHIFT                                     (2U)
#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX2_PEND_MASK                                      (0x00000004U)

#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX3_PEND_SHIFT                                     (3U)
#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX3_PEND_MASK                                      (0x00000008U)

#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX4_PEND_SHIFT                                     (4U)
#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX4_PEND_MASK                                      (0x00000010U)

#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX5_PEND_SHIFT                                     (5U)
#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX5_PEND_MASK                                      (0x00000020U)

#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX6_PEND_SHIFT                                     (6U)
#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX6_PEND_MASK                                      (0x00000040U)

#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX7_PEND_SHIFT                                     (7U)
#define CPSW_CPDMA_TX_INTSTAT_MASKED_TX7_PEND_MASK                                      (0x00000080U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX0_PEND_SHIFT                                        (0U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX0_PEND_MASK                                         (0x00000001U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX1_PEND_SHIFT                                        (1U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX1_PEND_MASK                                         (0x00000002U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX2_PEND_SHIFT                                        (2U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX2_PEND_MASK                                         (0x00000004U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX3_PEND_SHIFT                                        (3U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX3_PEND_MASK                                         (0x00000008U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX4_PEND_SHIFT                                        (4U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX4_PEND_MASK                                         (0x00000010U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX5_PEND_SHIFT                                        (5U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX5_PEND_MASK                                         (0x00000020U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX6_PEND_SHIFT                                        (6U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX6_PEND_MASK                                         (0x00000040U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX7_PEND_SHIFT                                        (7U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX7_PEND_MASK                                         (0x00000080U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX0_THRESH_PEND_SHIFT                                 (8U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX0_THRESH_PEND_MASK                                  (0x00000100U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX1_THRESH_PEND_SHIFT                                 (9U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX1_THRESH_PEND_MASK                                  (0x00000200U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX2_THRESH_PEND_SHIFT                                 (10U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX2_THRESH_PEND_MASK                                  (0x00000400U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX3_THRESH_PEND_SHIFT                                 (11U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX3_THRESH_PEND_MASK                                  (0x00000800U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX4_THRESH_PEND_SHIFT                                 (12U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX4_THRESH_PEND_MASK                                  (0x00001000U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX5_THRESH_PEND_SHIFT                                 (13U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX5_THRESH_PEND_MASK                                  (0x00002000U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX6_THRESH_PEND_SHIFT                                 (14U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX6_THRESH_PEND_MASK                                  (0x00004000U)

#define CPSW_CPDMA_RX_INTSTAT_RAW_RX7_THRESH_PEND_SHIFT                                 (15U)
#define CPSW_CPDMA_RX_INTSTAT_RAW_RX7_THRESH_PEND_MASK                                  (0x00008000U)

#define CPSW_CPDMA_RX_CTRL_EN_SHIFT                                                     (0U)
#define CPSW_CPDMA_RX_CTRL_EN_MASK                                                      (0x00000001U)
#define CPSW_CPDMA_RX_CTRL_EN_EN_0x1                                                     (1U)
#define CPSW_CPDMA_RX_CTRL_EN_EN_0x0                                                     (0U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CPSW_CPDMA_H_ */

