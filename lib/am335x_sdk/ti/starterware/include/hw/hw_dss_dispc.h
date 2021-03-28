/*
* hw_dss_dispc.h
*
* Register-level header file for DSS_DISPC [AEGIS_PUBLIC_INCLUDE]
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

#ifndef HW_DSS_DISPC_H_
#define HW_DSS_DISPC_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define DISPC_REVISION                                              (0x0U)
#define DISPC_SYSCFG                                                (0x10U)
#define DISPC_SYSSTS                                                (0x14U)
#define DISPC_IRQSTS                                                (0x18U)
#define DISPC_IRQEN                                                 (0x1cU)
#define DISPC_CTRL                                                  (0x40U)
#define DISPC_CFG                                                   (0x44U)
#define DISPC_CAPABLE                                               (0x48U)
#define DISPC_DEFAULT_COLOR(m)                                      ((uint32_t)0x4cU + ((m) * 0x4U))
#define DISPC_DEFAULT_COLOR_NUM_ELEMS                               (2U)
#define DISPC_LINE_STS                                              (0x5cU)
#define DISPC_LINE_NUMBER                                           (0x60U)
#define DISPC_TIMING_H                                              (0x64U)
#define DISPC_TIMING_V                                              (0x68U)
#define DISPC_POL_FREQ                                              (0x6cU)
#define DISPC_DIVISOR                                               (0x70U)
#define DISPC_GLOBAL_ALPHA                                          (0x74U)
#define DISPC_SIZE_DIG                                              (0x78U)
#define DISPC_SIZE_LCD                                              (0x7cU)
#define DISPC_TRANS_COLOR(m)                                        ((uint32_t)0x54U + ((m) * 0x4U))
#define DISPC_TRANS_COLOR_NUM_ELEMS                                 (2U)
#define DISPC_GFX_BA(m)                                             ((uint32_t)0x80U + ((m) * 0x4U))
#define DISPC_GFX_BA_NUM_ELEMS                                      (2U)
#define DISPC_GFX_POSITION                                          (0x88U)
#define DISPC_GFX_SIZE                                              (0x8cU)
#define DISPC_GFX_ATTRS                                             (0xa0U)
#define DISPC_GFX_FIFO_THR                                          (0xa4U)
#define DISPC_GFX_FIFO_SIZE_STS                                     (0xa8U)
#define DISPC_GFX_ROW_INC                                           (0xacU)
#define DISPC_GFX_PIXEL_INC                                         (0xb0U)
#define DISPC_GFX_WINDOW_SKIP                                       (0xb4U)
#define DISPC_GFX_TBL_BA                                            (0xb8U)
#define DISPC_VID_BA(m,n)                                           ((uint32_t)0xbcU + ((m) * 0x90U) + ((n) * 0x4U))
#define DISPC_VID_BA_NUM_ELEMS                                      (2U)
#define DISPC_VID_POSITION(m)                                       ((uint32_t)0xc4U + ((m) * 0x90U))
#define DISPC_VID_POSITION_NUM_ELEMS                                (2U)
#define DISPC_VID_SIZE(m)                                           ((uint32_t)0xc8U + ((m) * 0x90U))
#define DISPC_VID_SIZE_NUM_ELEMS                                    (2U)
#define DISPC_VID_ATTRS(m)                                          ((uint32_t)0xccU + ((m) * 0x90U))
#define DISPC_VID_ATTRS_NUM_ELEMS                                   (2U)
#define DISPC_VID_FIFO_THR(m)                                       ((uint32_t)0xd0U + ((m) * 0x90U))
#define DISPC_VID_FIFO_THR_NUM_ELEMS                                (2U)
#define DISPC_VID_FIFO_SIZE_STS(m)                                  ((uint32_t)0xd4U + ((m) * 0x90U))
#define DISPC_VID_FIFO_SIZE_STS_NUM_ELEMS                           (2U)
#define DISPC_VID_ROW_INC(m)                                        ((uint32_t)0xd8U + ((m) * 0x90U))
#define DISPC_VID_ROW_INC_NUM_ELEMS                                 (2U)
#define DISPC_VID_PIXEL_INC(m)                                      ((uint32_t)0xdcU + ((m) * 0x90U))
#define DISPC_VID_PIXEL_INC_NUM_ELEMS                               (2U)
#define DISPC_VID_FIR(m)                                            ((uint32_t)0xe0U + ((m) * 0x90U))
#define DISPC_VID_FIR_NUM_ELEMS                                     (2U)
#define DISPC_VID_PICTURE_SIZE(m)                                   ((uint32_t)0xe4U + ((m) * 0x90U))
#define DISPC_VID_PICTURE_SIZE_NUM_ELEMS                            (2U)
#define DISPC_VID_ACCU(m,n)                                         ((uint32_t)0xe8U + ((m) * 0x90U) + ((n) * 0x4U))
#define DISPC_VID_ACCU_NUM_ELEMS                                    (2U)
#define DISPC_VID1_FIR_COEF_H(m)                                    ((uint32_t)0xf0U + ((m) * 0x8U))
#define DISPC_VID1_FIR_COEF_H_NUM_ELEMS                             (8U)
#define DISPC_VID1_FIR_COEF_HV(m)                                   ((uint32_t)0xf4U + ((m) * 0x8U))
#define DISPC_VID1_FIR_COEF_HV_NUM_ELEMS                            (8U)
#define DISPC_VID_PRELOAD(n)                                        ((uint32_t)0x230U + ((n) * 0x4U))
#define DISPC_VID_PRELOAD_NUM_ELEMS                                 (2U)
#define DISPC_GFX_PRELOAD                                           (0x22cU)
#define DISPC_VID2_FIR_COEF_H(m)                                    ((uint32_t)0x180U + ((m) * 0x8U))
#define DISPC_VID2_FIR_COEF_H_NUM_ELEMS                             (8U)
#define DISPC_VID2_FIR_COEF_HV(m)                                   ((uint32_t)0x184U + ((m) * 0x8U))
#define DISPC_VID2_FIR_COEF_HV_NUM_ELEMS                            (8U)
#define DISPC_DATA_CYCLE(m)                                         ((uint32_t)0x1d4U + ((m) * 0x4U))
#define DISPC_DATA_CYCLE_NUM_ELEMS                                  (3U)
#define DISPC_CPR_COEF_R                                            (0x220U)
#define DISPC_CPR_COEF_G                                            (0x224U)
#define DISPC_CPR_COEF_B                                            (0x228U)
#define DISPC_VID_CONV_COEF0(m)                                     ((uint32_t)0x130U + ((m) * 0x90U))
#define DISPC_VID_CONV_COEF0_NUM_ELEMS                              (2U)
#define DISPC_VID_CONV_COEF1(m)                                     ((uint32_t)0x134U + ((m) * 0x90U))
#define DISPC_VID_CONV_COEF1_NUM_ELEMS                              (2U)
#define DISPC_VID_CONV_COEF2(m)                                     ((uint32_t)0x138U + ((m) * 0x90U))
#define DISPC_VID_CONV_COEF2_NUM_ELEMS                              (2U)
#define DISPC_VID_CONV_COEF3(m)                                     ((uint32_t)0x13cU + ((m) * 0x90U))
#define DISPC_VID_CONV_COEF3_NUM_ELEMS                              (2U)
#define DISPC_VID_CONV_COEF4(m)                                     ((uint32_t)0x140U + ((m) * 0x90U))
#define DISPC_VID_CONV_COEF4_NUM_ELEMS                              (2U)
#define DISPC_VID_FIR_COEF_V(m,n)                                   ((uint32_t)0x1e0U + ((m) * 0x20U) + ((n) * 0x4U))
#define DISPC_VID_FIR_COEF_V_NUM_ELEMS                              (8U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define DISPC_REVISION_REV_SHIFT                                                        (0U)
#define DISPC_REVISION_REV_MASK                                                         (0x000000ffU)

#define DISPC_SYSCFG_AUTOIDLE_SHIFT                                                     (0U)
#define DISPC_SYSCFG_AUTOIDLE_MASK                                                      (0x00000001U)
#define DISPC_SYSCFG_AUTOIDLE_FREE                                                       (0U)
#define DISPC_SYSCFG_AUTOIDLE_AUTOMATIC                                                  (1U)

#define DISPC_SYSCFG_SOFTRESET_SHIFT                                                    (1U)
#define DISPC_SYSCFG_SOFTRESET_MASK                                                     (0x00000002U)
#define DISPC_SYSCFG_SOFTRESET_NORMAL                                                    (0U)
#define DISPC_SYSCFG_SOFTRESET_RESET                                                     (1U)

#define DISPC_SYSCFG_ENWAKEUP_SHIFT                                                     (2U)
#define DISPC_SYSCFG_ENWAKEUP_MASK                                                      (0x00000004U)
#define DISPC_SYSCFG_ENWAKEUP_DISABLED                                                   (0U)
#define DISPC_SYSCFG_ENWAKEUP_ENABLED                                                    (1U)

#define DISPC_SYSCFG_SIDLEMODE_SHIFT                                                    (3U)
#define DISPC_SYSCFG_SIDLEMODE_MASK                                                     (0x00000018U)
#define DISPC_SYSCFG_SIDLEMODE_FORCEIDLE                                                 (0U)
#define DISPC_SYSCFG_SIDLEMODE_NOIDLE                                                    (1U)
#define DISPC_SYSCFG_SIDLEMODE_SMARTIDLE                                                 (2U)
#define DISPC_SYSCFG_SIDLEMODE_RESERVED                                                  (3U)

#define DISPC_SYSCFG_CLOCK_ACTIVITY_SHIFT                                               (8U)
#define DISPC_SYSCFG_CLOCK_ACTIVITY_MASK                                                (0x00000300U)
#define DISPC_SYSCFG_CLOCK_ACTIVITY_IN_FUN_OFF                                           (0U)
#define DISPC_SYSCFG_CLOCK_ACTIVITY_FUN_OFF                                              (1U)
#define DISPC_SYSCFG_CLOCK_ACTIVITY_IN_OFF                                               (2U)
#define DISPC_SYSCFG_CLOCK_ACTIVITY_IN_FUN_ON                                            (3U)

#define DISPC_SYSCFG_MIDLEMODE_SHIFT                                                    (12U)
#define DISPC_SYSCFG_MIDLEMODE_MASK                                                     (0x00003000U)
#define DISPC_SYSCFG_MIDLEMODE_FORCESTANDBY                                              (0U)
#define DISPC_SYSCFG_MIDLEMODE_NOSTANDBY                                                 (1U)
#define DISPC_SYSCFG_MIDLEMODE_SMARTSTANDBY                                              (2U)
#define DISPC_SYSCFG_MIDLEMODE_RESERVED                                                  (1U)

#define DISPC_SYSSTS_RESETDONE_SHIFT                                                    (0U)
#define DISPC_SYSSTS_RESETDONE_MASK                                                     (0x00000001U)
#define DISPC_SYSSTS_RESETDONE_ONGOING                                                   (0U)
#define DISPC_SYSSTS_RESETDONE_DONE                                                      (1U)

#define DISPC_IRQSTS_FRMDONE_SHIFT                                                      (0U)
#define DISPC_IRQSTS_FRMDONE_MASK                                                       (0x00000001U)
#define DISPC_IRQSTS_FRMDONE_FALSE                                                       (0U)
#define DISPC_IRQSTS_FRMDONE_UNCHANGED                                                   (0U)
#define DISPC_IRQSTS_FRMDONE_TRUE                                                        (1U)
#define DISPC_IRQSTS_FRMDONE_RESET                                                       (1U)

#define DISPC_IRQSTS_VSYNC_SHIFT                                                        (1U)
#define DISPC_IRQSTS_VSYNC_MASK                                                         (0x00000002U)
#define DISPC_IRQSTS_VSYNC_FALSE                                                         (0U)
#define DISPC_IRQSTS_VSYNC_UNCHANGED                                                     (0U)
#define DISPC_IRQSTS_VSYNC_TRUE                                                          (1U)
#define DISPC_IRQSTS_VSYNC_RESET                                                         (1U)

#define DISPC_IRQSTS_EVSYNC_EVEN_SHIFT                                                  (2U)
#define DISPC_IRQSTS_EVSYNC_EVEN_MASK                                                   (0x00000004U)
#define DISPC_IRQSTS_EVSYNC_EVEN_FALSE                                                   (0U)
#define DISPC_IRQSTS_EVSYNC_EVEN_UNCHANGED                                               (0U)
#define DISPC_IRQSTS_EVSYNC_EVEN_TRUE                                                    (1U)
#define DISPC_IRQSTS_EVSYNC_EVEN_RESET                                                   (1U)

#define DISPC_IRQSTS_EVSYNC_ODD_SHIFT                                                   (3U)
#define DISPC_IRQSTS_EVSYNC_ODD_MASK                                                    (0x00000008U)
#define DISPC_IRQSTS_EVSYNC_ODD_FALSE                                                    (0U)
#define DISPC_IRQSTS_EVSYNC_ODD_UNCHANGED                                                (0U)
#define DISPC_IRQSTS_EVSYNC_ODD_TRUE                                                     (1U)
#define DISPC_IRQSTS_EVSYNC_ODD_RESET                                                    (1U)

#define DISPC_IRQSTS_ACBIAS_CNT_STS_SHIFT                                               (4U)
#define DISPC_IRQSTS_ACBIAS_CNT_STS_MASK                                                (0x00000010U)
#define DISPC_IRQSTS_ACBIAS_CNT_STS_FALSE                                                (0U)
#define DISPC_IRQSTS_ACBIAS_CNT_STS_UNCHANGED                                            (0U)
#define DISPC_IRQSTS_ACBIAS_CNT_STS_TRUE                                                 (1U)
#define DISPC_IRQSTS_ACBIAS_CNT_STS_RESET                                                (1U)

#define DISPC_IRQSTS_PGM_LINE_NO_SHIFT                                                  (5U)
#define DISPC_IRQSTS_PGM_LINE_NO_MASK                                                   (0x00000020U)
#define DISPC_IRQSTS_PGM_LINE_NO_FALSE                                                   (0U)
#define DISPC_IRQSTS_PGM_LINE_NO_UNCHANGED                                               (0U)
#define DISPC_IRQSTS_PGM_LINE_NO_TRUE                                                    (1U)
#define DISPC_IRQSTS_PGM_LINE_NO_RESET                                                   (1U)

#define DISPC_IRQSTS_GFXFIFO_UFLOW_SHIFT                                                (6U)
#define DISPC_IRQSTS_GFXFIFO_UFLOW_MASK                                                 (0x00000040U)
#define DISPC_IRQSTS_GFXFIFO_UFLOW_FALSE                                                 (0U)
#define DISPC_IRQSTS_GFXFIFO_UFLOW_UNCHANGED                                             (0U)
#define DISPC_IRQSTS_GFXFIFO_UFLOW_TRUE                                                  (1U)
#define DISPC_IRQSTS_GFXFIFO_UFLOW_RESET                                                 (1U)

#define DISPC_IRQSTS_GFXEND_WINDOW_SHIFT                                                (7U)
#define DISPC_IRQSTS_GFXEND_WINDOW_MASK                                                 (0x00000080U)
#define DISPC_IRQSTS_GFXEND_WINDOW_FALSE                                                 (0U)
#define DISPC_IRQSTS_GFXEND_WINDOW_UNCHANGED                                             (0U)
#define DISPC_IRQSTS_GFXEND_WINDOW_TRUE                                                  (1U)
#define DISPC_IRQSTS_GFXEND_WINDOW_RESET                                                 (1U)

#define DISPC_IRQSTS_PALLETE_GAMMA_LOADING_SHIFT                                        (8U)
#define DISPC_IRQSTS_PALLETE_GAMMA_LOADING_MASK                                         (0x00000100U)
#define DISPC_IRQSTS_PALLETE_GAMMA_LOADING_FALSE                                         (0U)
#define DISPC_IRQSTS_PALLETE_GAMMA_LOADING_UNCHANGED                                     (0U)
#define DISPC_IRQSTS_PALLETE_GAMMA_LOADING_TRUE                                          (1U)
#define DISPC_IRQSTS_PALLETE_GAMMA_LOADING_RESET                                         (1U)

#define DISPC_IRQSTS_OCP_ERROR_SHIFT                                                    (9U)
#define DISPC_IRQSTS_OCP_ERROR_MASK                                                     (0x00000200U)
#define DISPC_IRQSTS_OCP_ERROR_FALSE                                                     (0U)
#define DISPC_IRQSTS_OCP_ERROR_UNCHANGED                                                 (0U)
#define DISPC_IRQSTS_OCP_ERROR_TRUE                                                      (1U)
#define DISPC_IRQSTS_OCP_ERROR_RESET                                                     (1U)

#define DISPC_IRQSTS_VID1_FIFO_UFLOW_SHIFT                                              (10U)
#define DISPC_IRQSTS_VID1_FIFO_UFLOW_MASK                                               (0x00000400U)
#define DISPC_IRQSTS_VID1_FIFO_UFLOW_FALSE                                               (0U)
#define DISPC_IRQSTS_VID1_FIFO_UFLOW_UNCHANGED                                           (0U)
#define DISPC_IRQSTS_VID1_FIFO_UFLOW_TRUE                                                (1U)
#define DISPC_IRQSTS_VID1_FIFO_UFLOW_RESET                                               (1U)

#define DISPC_IRQSTS_VID1_END_WINDOW_SHIFT                                              (11U)
#define DISPC_IRQSTS_VID1_END_WINDOW_MASK                                               (0x00000800U)
#define DISPC_IRQSTS_VID1_END_WINDOW_FALSE                                               (0U)
#define DISPC_IRQSTS_VID1_END_WINDOW_UNCHANGED                                           (0U)
#define DISPC_IRQSTS_VID1_END_WINDOW_TRUE                                                (1U)
#define DISPC_IRQSTS_VID1_END_WINDOW_RESET                                               (1U)

#define DISPC_IRQSTS_VID2_FIFO_UFLOW_SHIFT                                              (12U)
#define DISPC_IRQSTS_VID2_FIFO_UFLOW_MASK                                               (0x00001000U)
#define DISPC_IRQSTS_VID2_FIFO_UFLOW_FALSE                                               (0U)
#define DISPC_IRQSTS_VID2_FIFO_UFLOW_UNCHANGED                                           (0U)
#define DISPC_IRQSTS_VID2_FIFO_UFLOW_TRUE                                                (1U)
#define DISPC_IRQSTS_VID2_FIFO_UFLOW_RESET                                               (1U)

#define DISPC_IRQSTS_VID2_END_WINDOW_SHIFT                                              (13U)
#define DISPC_IRQSTS_VID2_END_WINDOW_MASK                                               (0x00002000U)
#define DISPC_IRQSTS_VID2_END_WINDOW_FALSE                                               (0U)
#define DISPC_IRQSTS_VID2_END_WINDOW_UNCHANGED                                           (0U)
#define DISPC_IRQSTS_VID2_END_WINDOW_TRUE                                                (1U)
#define DISPC_IRQSTS_VID2_END_WINDOW_RESET                                               (1U)

#define DISPC_IRQSTS_SYNC_LOST_SHIFT                                                    (14U)
#define DISPC_IRQSTS_SYNC_LOST_MASK                                                     (0x00004000U)
#define DISPC_IRQSTS_SYNC_LOST_FALSE                                                     (0U)
#define DISPC_IRQSTS_SYNC_LOST_UNCHANGED                                                 (0U)
#define DISPC_IRQSTS_SYNC_LOST_TRUE                                                      (1U)
#define DISPC_IRQSTS_SYNC_LOST_RESET                                                     (1U)

#define DISPC_IRQSTS_SYNC_LOST_DIGITAL_SHIFT                                            (15U)
#define DISPC_IRQSTS_SYNC_LOST_DIGITAL_MASK                                             (0x00008000U)
#define DISPC_IRQSTS_SYNC_LOST_DIGITAL_FALSE                                             (0U)
#define DISPC_IRQSTS_SYNC_LOST_DIGITAL_UNCHANGED                                         (0U)
#define DISPC_IRQSTS_SYNC_LOST_DIGITAL_TRUE                                              (1U)
#define DISPC_IRQSTS_SYNC_LOST_DIGITAL_RESET                                             (1U)

#define DISPC_IRQSTS_WAKEUP_SHIFT                                                       (16U)
#define DISPC_IRQSTS_WAKEUP_MASK                                                        (0x00010000U)
#define DISPC_IRQSTS_WAKEUP_FALSE                                                        (0U)
#define DISPC_IRQSTS_WAKEUP_UNCHANGED                                                    (0U)
#define DISPC_IRQSTS_WAKEUP_TRUE                                                         (1U)
#define DISPC_IRQSTS_WAKEUP_RESET                                                        (1U)

#define DISPC_IRQEN_FRM_DONE_SHIFT                                                      (0U)
#define DISPC_IRQEN_FRM_DONE_MASK                                                       (0x00000001U)
#define DISPC_IRQEN_FRM_DONE_MASKED                                                      (0U)
#define DISPC_IRQEN_FRM_DONE_ENABLED                                                     (1U)

#define DISPC_IRQEN_VSYNC_SHIFT                                                         (1U)
#define DISPC_IRQEN_VSYNC_MASK                                                          (0x00000002U)
#define DISPC_IRQEN_VSYNC_MASKED                                                         (0U)
#define DISPC_IRQEN_VSYNC_ENABLED                                                        (1U)

#define DISPC_IRQEN_EVSYNC_EVEN_SHIFT                                                   (2U)
#define DISPC_IRQEN_EVSYNC_EVEN_MASK                                                    (0x00000004U)
#define DISPC_IRQEN_EVSYNC_EVEN_MASKED                                                   (0U)
#define DISPC_IRQEN_EVSYNC_EVEN_ENABLED                                                  (1U)

#define DISPC_IRQEN_EVSYNC_ODD_SHIFT                                                    (3U)
#define DISPC_IRQEN_EVSYNC_ODD_MASK                                                     (0x00000008U)
#define DISPC_IRQEN_EVSYNC_ODD_MASKED                                                    (0U)
#define DISPC_IRQEN_EVSYNC_ODD_ENABLED                                                   (1U)

#define DISPC_IRQEN_ACBIAS_COUNT_STS_SHIFT                                              (4U)
#define DISPC_IRQEN_ACBIAS_COUNT_STS_MASK                                               (0x00000010U)
#define DISPC_IRQEN_ACBIAS_COUNT_STS_MASKED                                              (0U)
#define DISPC_IRQEN_ACBIAS_COUNT_STS_ENABLED                                             (1U)

#define DISPC_IRQEN_PGM_LINE_NO_SHIFT                                                   (5U)
#define DISPC_IRQEN_PGM_LINE_NO_MASK                                                    (0x00000020U)
#define DISPC_IRQEN_PGM_LINE_NO_MASKED                                                   (0U)
#define DISPC_IRQEN_PGM_LINE_NO_ENABLED                                                  (1U)

#define DISPC_IRQEN_GFXFIFO_UFLOW_SHIFT                                                 (6U)
#define DISPC_IRQEN_GFXFIFO_UFLOW_MASK                                                  (0x00000040U)
#define DISPC_IRQEN_GFXFIFO_UFLOW_MASKED                                                 (0U)
#define DISPC_IRQEN_GFXFIFO_UFLOW_ENABLED                                                (1U)

#define DISPC_IRQEN_GFXEND_WINDOW_SHIFT                                                 (7U)
#define DISPC_IRQEN_GFXEND_WINDOW_MASK                                                  (0x00000080U)
#define DISPC_IRQEN_GFXEND_WINDOW_MASKED                                                 (0U)
#define DISPC_IRQEN_GFXEND_WINDOW_ENABLED                                                (1U)

#define DISPC_IRQEN_PALLETE_GAMMA_LOADING_SHIFT                                         (8U)
#define DISPC_IRQEN_PALLETE_GAMMA_LOADING_MASK                                          (0x00000100U)
#define DISPC_IRQEN_PALLETE_GAMMA_LOADING_MASKED                                         (0U)
#define DISPC_IRQEN_PALLETE_GAMMA_LOADING_ENABLED                                        (1U)

#define DISPC_IRQEN_OCP_ERROR_SHIFT                                                     (9U)
#define DISPC_IRQEN_OCP_ERROR_MASK                                                      (0x00000200U)
#define DISPC_IRQEN_OCP_ERROR_MASKED                                                     (0U)
#define DISPC_IRQEN_OCP_ERROR_ENABLED                                                    (1U)

#define DISPC_IRQEN_VID1_FIFO_UFLOW_SHIFT                                               (10U)
#define DISPC_IRQEN_VID1_FIFO_UFLOW_MASK                                                (0x00000400U)
#define DISPC_IRQEN_VID1_FIFO_UFLOW_MASKED                                               (0U)
#define DISPC_IRQEN_VID1_FIFO_UFLOW_ENABLED                                              (1U)

#define DISPC_IRQEN_VID1_END_WINDOW_SHIFT                                               (11U)
#define DISPC_IRQEN_VID1_END_WINDOW_MASK                                                (0x00000800U)
#define DISPC_IRQEN_VID1_END_WINDOW_MASKED                                               (0U)
#define DISPC_IRQEN_VID1_END_WINDOW_ENABLED                                              (1U)

#define DISPC_IRQEN_VID2_FIFO_UFLOW_SHIFT                                               (12U)
#define DISPC_IRQEN_VID2_FIFO_UFLOW_MASK                                                (0x00001000U)
#define DISPC_IRQEN_VID2_FIFO_UFLOW_MASKED                                               (0U)
#define DISPC_IRQEN_VID2_FIFO_UFLOW_ENABLED                                              (1U)

#define DISPC_IRQEN_VID2_END_WINDOW_SHIFT                                               (13U)
#define DISPC_IRQEN_VID2_END_WINDOW_MASK                                                (0x00002000U)
#define DISPC_IRQEN_VID2_END_WINDOW_MASKED                                               (0U)
#define DISPC_IRQEN_VID2_END_WINDOW_ENABLED                                              (1U)

#define DISPC_IRQEN_SYNC_LOST_SHIFT                                                     (14U)
#define DISPC_IRQEN_SYNC_LOST_MASK                                                      (0x00004000U)
#define DISPC_IRQEN_SYNC_LOST_MASKED                                                     (0U)
#define DISPC_IRQEN_SYNC_LOST_ENABLED                                                    (1U)

#define DISPC_IRQEN_SYNC_LOST_DIGITAL_SHIFT                                             (15U)
#define DISPC_IRQEN_SYNC_LOST_DIGITAL_MASK                                              (0x00008000U)
#define DISPC_IRQEN_SYNC_LOST_DIGITAL_MASKED                                             (0U)
#define DISPC_IRQEN_SYNC_LOST_DIGITAL_ENABLED                                            (1U)

#define DISPC_IRQEN_WAKEUP_SHIFT                                                        (16U)
#define DISPC_IRQEN_WAKEUP_MASK                                                         (0x00010000U)
#define DISPC_IRQEN_WAKEUP_MASKED                                                        (0U)
#define DISPC_IRQEN_WAKEUP_ENABLED                                                       (1U)

#define DISPC_CTRL_LCD_EN_SHIFT                                                         (0U)
#define DISPC_CTRL_LCD_EN_MASK                                                          (0x00000001U)
#define DISPC_CTRL_LCD_EN_DISABLED                                                       (0U)
#define DISPC_CTRL_LCD_EN_ENABLED                                                        (1U)

#define DISPC_CTRL_DIGITAL_EN_SHIFT                                                     (1U)
#define DISPC_CTRL_DIGITAL_EN_MASK                                                      (0x00000002U)
#define DISPC_CTRL_DIGITAL_EN_DISABLED                                                   (0U)
#define DISPC_CTRL_DIGITAL_EN_ENABLED                                                    (1U)

#define DISPC_CTRL_MONO_COLOR_SHIFT                                                     (2U)
#define DISPC_CTRL_MONO_COLOR_MASK                                                      (0x00000004U)
#define DISPC_CTRL_MONO_COLOR_EN                                                         (0U)
#define DISPC_CTRL_MONO_COLOR_MONOCHROME_EN                                              (1U)

#define DISPC_CTRL_STNTFT_SHIFT                                                         (3U)
#define DISPC_CTRL_STNTFT_MASK                                                          (0x00000008U)
#define DISPC_CTRL_STNTFT_PASSIVE_MATRIX                                                 (0U)
#define DISPC_CTRL_STNTFT_ACTIVE_MATRIX                                                  (1U)

#define DISPC_CTRL_M8B_SHIFT                                                            (4U)
#define DISPC_CTRL_M8B_MASK                                                             (0x00000010U)
#define DISPC_CTRL_M8B_PIX_3_0                                                           (0U)
#define DISPC_CTRL_M8B_PIX_7_0                                                           (1U)

#define DISPC_CTRL_GO_LCD_SHIFT                                                         (5U)
#define DISPC_CTRL_GO_LCD_MASK                                                          (0x00000020U)
#define DISPC_CTRL_GO_LCD_FINISHED_UPDATING                                              (0U)
#define DISPC_CTRL_GO_LCD_FINISHED_PROGRAMMING                                           (1U)

#define DISPC_CTRL_GO_DIGITAL_SHIFT                                                     (6U)
#define DISPC_CTRL_GO_DIGITAL_MASK                                                      (0x00000040U)
#define DISPC_CTRL_GO_DIGITAL_FINISHED_UPDATING                                          (0U)
#define DISPC_CTRL_GO_DIGITAL_FINISHED_PROGRAMMING                                       (1U)

#define DISPC_CTRL_ST_DITHER_EN_SHIFT                                                   (7U)
#define DISPC_CTRL_ST_DITHER_EN_MASK                                                    (0x00000080U)
#define DISPC_CTRL_ST_DITHER_EN_DISABLED                                                 (0U)
#define DISPC_CTRL_ST_DITHER_EN_ENABLED                                                  (1U)

#define DISPC_CTRL_TFT_DATA_LINES_SHIFT                                                 (8U)
#define DISPC_CTRL_TFT_DATA_LINES_MASK                                                  (0x00000300U)
#define DISPC_CTRL_TFT_DATA_LINES_BIT_12                                                 (0U)
#define DISPC_CTRL_TFT_DATA_LINES_BIT_16                                                 (1U)
#define DISPC_CTRL_TFT_DATA_LINES_BIT_18                                                 (2U)
#define DISPC_CTRL_TFT_DATA_LINES_BIT_24                                                 (3U)

#define DISPC_CTRL_STALL_MODE_SHIFT                                                     (11U)
#define DISPC_CTRL_STALL_MODE_MASK                                                      (0x00000800U)
#define DISPC_CTRL_STALL_MODE_NORMAL                                                     (0U)
#define DISPC_CTRL_STALL_MODE                                                            (1U)

#define DISPC_CTRL_OVLY_OPT_SHIFT                                                       (12U)
#define DISPC_CTRL_OVLY_OPT_MASK                                                        (0x00001000U)
#define DISPC_CTRL_OVLY_OPT_VIDEO_DATA_FETCHED                                           (0U)
#define DISPC_CTRL_OVLY_OPT_VIDEO_DATA_NOT_FETCHED                                       (1U)

#define DISPC_CTRL_GPIN0_SHIFT                                                          (13U)
#define DISPC_CTRL_GPIN0_MASK                                                           (0x00002000U)
#define DISPC_CTRL_GPIN0_RESET                                                           (0U)
#define DISPC_CTRL_GPIN0_SET                                                             (1U)

#define DISPC_CTRL_GPIN1_SHIFT                                                          (14U)
#define DISPC_CTRL_GPIN1_MASK                                                           (0x00004000U)
#define DISPC_CTRL_GPIN1_RESET                                                           (0U)
#define DISPC_CTRL_GPIN1_SET                                                             (1U)

#define DISPC_CTRL_GPOUT0_SHIFT                                                         (15U)
#define DISPC_CTRL_GPOUT0_MASK                                                          (0x00008000U)
#define DISPC_CTRL_GPOUT0_RESET                                                          (0U)
#define DISPC_CTRL_GPOUT0_SET                                                            (1U)

#define DISPC_CTRL_GPOUT1_SHIFT                                                         (16U)
#define DISPC_CTRL_GPOUT1_MASK                                                          (0x00010000U)
#define DISPC_CTRL_GPOUT1_RESET                                                          (0U)
#define DISPC_CTRL_GPOUT1_SET                                                            (1U)

#define DISPC_CTRL_HT_SHIFT                                                             (17U)
#define DISPC_CTRL_HT_MASK                                                              (0x000e0000U)

#define DISPC_CTRL_TDM_EN_SHIFT                                                         (20U)
#define DISPC_CTRL_TDM_EN_MASK                                                          (0x00100000U)
#define DISPC_CTRL_TDM_EN_DISABLED                                                       (0U)
#define DISPC_CTRL_TDM_EN_ENABLED                                                        (1U)

#define DISPC_CTRL_TDM_PARALLEL_MODE_SHIFT                                              (21U)
#define DISPC_CTRL_TDM_PARALLEL_MODE_MASK                                               (0x00600000U)
#define DISPC_CTRL_TDM_PARALLEL_MODE_BIT_8                                               (0U)
#define DISPC_CTRL_TDM_PARALLEL_MODE_BIT_9                                               (1U)
#define DISPC_CTRL_TDM_PARALLEL_MODE_BIT_12                                              (2U)
#define DISPC_CTRL_TDM_PARALLEL_MODE_BIT_16                                              (3U)

#define DISPC_CTRL_TDM_CYCLE_FMT_SHIFT                                                  (23U)
#define DISPC_CTRL_TDM_CYCLE_FMT_MASK                                                   (0x01800000U)
#define DISPC_CTRL_TDM_CYCLE_FMT_1                                                       (0U)
#define DISPC_CTRL_TDM_CYCLE_FMT_2                                                       (1U)
#define DISPC_CTRL_TDM_CYCLE_FMT_3                                                       (2U)
#define DISPC_CTRL_TDM_CYCLE_FMT_3_PIXELS_2                                              (3U)

#define DISPC_CTRL_TDM_UNUSED_BITS_SHIFT                                                (25U)
#define DISPC_CTRL_TDM_UNUSED_BITS_MASK                                                 (0x06000000U)
#define DISPC_CTRL_TDM_UNUSED_BITS_LOW_LEVEL                                             (0U)
#define DISPC_CTRL_TDM_UNUSED_BITS_HIGH_LEVEL                                            (1U)
#define DISPC_CTRL_TDM_UNUSED_BITS_UNCHANGED                                             (2U)
#define DISPC_CTRL_TDM_UNUSED_BITS_RESERVED                                              (3U)

#define DISPC_CTRL_PCK_FREE_EN_SHIFT                                                    (27U)
#define DISPC_CTRL_PCK_FREE_EN_MASK                                                     (0x08000000U)
#define DISPC_CTRL_PCK_FREE_EN_DISABLED                                                  (0U)
#define DISPC_CTRL_PCK_FREE_EN_ENABLED                                                   (1U)

#define DISPC_CTRL_LCD_EN_SIGNAL_SHIFT                                                  (28U)
#define DISPC_CTRL_LCD_EN_SIGNAL_MASK                                                   (0x10000000U)
#define DISPC_CTRL_LCD_EN_SIGNAL_DISABLED                                                (0U)
#define DISPC_CTRL_LCD_EN_SIGNAL_ENABLED                                                 (1U)

#define DISPC_CTRL_LCD_EN_POL_SHIFT                                                     (29U)
#define DISPC_CTRL_LCD_EN_POL_MASK                                                      (0x20000000U)
#define DISPC_CTRL_LCD_EN_POL_ACTIVE_LOW                                                 (0U)
#define DISPC_CTRL_LCD_EN_POL_ACTIVE_HIGH                                                (1U)

#define DISPC_CTRL_SPATIAL_TEMPORAL_DITHER_SHIFT                                        (30U)
#define DISPC_CTRL_SPATIAL_TEMPORAL_DITHER_MASK                                         (0xc0000000U)
#define DISPC_CTRL_SPATIAL_TEMPORAL_DITHER_ONLY                                          (0U)
#define DISPC_CTRL_SPATIAL_TEMPORAL_DITHER_AND_OVR_2_FRAMES                              (1U)
#define DISPC_CTRL_SPATIAL_TEMPORAL_DITHER_AND_OVR_4_FRAMES                              (2U)
#define DISPC_CTRL_SPATIAL_TEMPORAL_DITHER_RESERVED                                      (3U)

#define DISPC_CFG_PIXEL_GATED_SHIFT                                                     (0U)
#define DISPC_CFG_PIXEL_GATED_MASK                                                      (0x00000001U)
#define DISPC_CFG_PIXEL_GATED_ALWAYS_TOGGLES                                             (0U)
#define DISPC_CFG_PIXEL_GATED_TOGGLES_WHEN_VALID_DATA                                    (1U)

#define DISPC_CFG_LOAD_MODE_SHIFT                                                       (1U)
#define DISPC_CFG_LOAD_MODE_MASK                                                        (0x00000006U)
#define DISPC_CFG_LOAD_MODE_GAMMA_TBL_AND_DATA_LOADED_FOR_EVERY_FRAME                    (0U)
#define DISPC_CFG_LOAD_MODE_GAMMA_TBL_LOADED                                             (1U)
#define DISPC_CFG_LOAD_MODE_DATA_LOADED                                                  (2U)
#define DISPC_CFG_LOAD_MODE_GAMMA_TBL_AND_DATA_LOADED_FOR_FIRST_FRAME                    (3U)

#define DISPC_CFG_PALETTEGAMMA_TBL_SHIFT                                                (3U)
#define DISPC_CFG_PALETTEGAMMA_TBL_MASK                                                 (0x00000008U)
#define DISPC_CFG_PALETTEGAMMA_TBL_LUT_PALETTE                                           (0U)
#define DISPC_CFG_PALETTEGAMMA_TBL_LUT_GAMMA                                             (1U)

#define DISPC_CFG_PIXEL_DATA_GATED_SHIFT                                                (4U)
#define DISPC_CFG_PIXEL_DATA_GATED_MASK                                                 (0x00000010U)
#define DISPC_CFG_PIXEL_DATA_GATED_DISABLED                                              (0U)
#define DISPC_CFG_PIXEL_DATA_GATED_ENABLED                                               (1U)

#define DISPC_CFG_PIXEL_CLK_GATED_SHIFT                                                 (5U)
#define DISPC_CFG_PIXEL_CLK_GATED_MASK                                                  (0x00000020U)
#define DISPC_CFG_PIXEL_CLK_GATED_DISABLED                                               (0U)
#define DISPC_CFG_PIXEL_CLK_GATED_ENABLED                                                (1U)

#define DISPC_CFG_HSYNC_GATED_SHIFT                                                     (6U)
#define DISPC_CFG_HSYNC_GATED_MASK                                                      (0x00000040U)
#define DISPC_CFG_HSYNC_GATED_DISABLED                                                   (0U)
#define DISPC_CFG_HSYNC_GATED_ENABLED                                                    (1U)

#define DISPC_CFG_VSYNC_GATED_SHIFT                                                     (7U)
#define DISPC_CFG_VSYNC_GATED_MASK                                                      (0x00000080U)
#define DISPC_CFG_VSYNC_GATED_DISABLED                                                   (0U)
#define DISPC_CFG_VSYNC_GATED_ENABLED                                                    (1U)

#define DISPC_CFG_ACBIAS_GATED_SHIFT                                                    (8U)
#define DISPC_CFG_ACBIAS_GATED_MASK                                                     (0x00000100U)
#define DISPC_CFG_ACBIAS_GATED_DISABLED                                                  (0U)
#define DISPC_CFG_ACBIAS_GATED_ENABLED                                                   (1U)

#define DISPC_CFG_FUNC_GATED_SHIFT                                                      (9U)
#define DISPC_CFG_FUNC_GATED_MASK                                                       (0x00000200U)
#define DISPC_CFG_FUNC_GATED_DISABLED                                                    (0U)
#define DISPC_CFG_FUNC_GATED_ENABLED                                                     (1U)

#define DISPC_CFG_TCK_LCD_EN_SHIFT                                                      (10U)
#define DISPC_CFG_TCK_LCD_EN_MASK                                                       (0x00000400U)
#define DISPC_CFG_TCK_LCD_EN_DISABLED                                                    (0U)
#define DISPC_CFG_TCK_LCD_EN_ENABLED                                                     (1U)

#define DISPC_CFG_TCK_LCD_SELECTION_SHIFT                                               (11U)
#define DISPC_CFG_TCK_LCD_SELECTION_MASK                                                (0x00000800U)
#define DISPC_CFG_TCK_LCD_SELECTION_GRAPHICS_DEST                                        (0U)
#define DISPC_CFG_TCK_LCD_SELECTION_VIDEO_SOURCE                                         (1U)

#define DISPC_CFG_TCK_DIG_EN_SHIFT                                                      (12U)
#define DISPC_CFG_TCK_DIG_EN_MASK                                                       (0x00001000U)
#define DISPC_CFG_TCK_DIG_EN_DISABLED                                                    (0U)
#define DISPC_CFG_TCK_DIG_EN_ENABLED                                                     (1U)

#define DISPC_CFG_TCK_DIG_SELECTION_SHIFT                                               (13U)
#define DISPC_CFG_TCK_DIG_SELECTION_MASK                                                (0x00002000U)
#define DISPC_CFG_TCK_DIG_SELECTION_GRAPHICS_DEST                                        (0U)
#define DISPC_CFG_TCK_DIG_SELECTION_VIDEO_SOURCE                                         (1U)

#define DISPC_CFG_FIFO_MERGE_SHIFT                                                      (14U)
#define DISPC_CFG_FIFO_MERGE_MASK                                                       (0x00004000U)
#define DISPC_CFG_FIFO_MERGE_DISABLED                                                    (0U)
#define DISPC_CFG_FIFO_MERGE_ENABLED                                                     (1U)

#define DISPC_CFG_CPR_SHIFT                                                             (15U)
#define DISPC_CFG_CPR_MASK                                                              (0x00008000U)
#define DISPC_CFG_CPR_DISABLED                                                           (0U)
#define DISPC_CFG_CPR_ENABLED                                                            (1U)

#define DISPC_CFG_FIFO_HAND_CHECK_SHIFT                                                 (16U)
#define DISPC_CFG_FIFO_HAND_CHECK_MASK                                                  (0x00010000U)
#define DISPC_CFG_FIFO_HAND_CHECK_STALL_ONLY                                             (0U)
#define DISPC_CFG_FIFO_HAND_CHECK_STALL_AND                                              (1U)

#define DISPC_CFG_FIFO_FILLING_SHIFT                                                    (17U)
#define DISPC_CFG_FIFO_FILLING_MASK                                                     (0x00020000U)
#define DISPC_CFG_FIFO_FILLING_EACH                                                      (0U)
#define DISPC_CFG_FIFO_FILLING_ATLEAST_ONE                                               (1U)

#define DISPC_CFG_LCD_APLHABLDR_EN_SHIFT                                                (18U)
#define DISPC_CFG_LCD_APLHABLDR_EN_MASK                                                 (0x00040000U)
#define DISPC_CFG_LCD_APLHABLDR_EN_DISABLED                                              (0U)
#define DISPC_CFG_LCD_APLHABLDR_EN_ENABLED                                               (1U)

#define DISPC_CFG_TV_ALPHA_BLDR_EN_SHIFT                                                (19U)
#define DISPC_CFG_TV_ALPHA_BLDR_EN_MASK                                                 (0x00080000U)
#define DISPC_CFG_TV_ALPHA_BLDR_EN_DISABLED                                              (0U)
#define DISPC_CFG_TV_ALPHA_BLDR_EN_ENABLED                                               (1U)

#define DISPC_CAPABLE_VID_SHIFT                                                         (0U)
#define DISPC_CAPABLE_VID_MASK                                                          (0x00000001U)

#define DISPC_CAPABLE_VID_HORFIR_SHIFT                                                  (1U)
#define DISPC_CAPABLE_VID_HORFIR_MASK                                                   (0x00000002U)

#define DISPC_CAPABLE_VID_VERTFIR_SHIFT                                                 (2U)
#define DISPC_CAPABLE_VID_VERTFIR_MASK                                                  (0x00000004U)

#define DISPC_CAPABLE_VID_LAYER_SHIFT                                                   (3U)
#define DISPC_CAPABLE_VID_LAYER_MASK                                                    (0x00000008U)

#define DISPC_CAPABLE_ID_TRANS_SRC_SHIFT                                                (4U)
#define DISPC_CAPABLE_ID_TRANS_SRC_MASK                                                 (0x00000010U)

#define DISPC_CAPABLE_TFT_DITHERING_SHIFT                                               (5U)
#define DISPC_CAPABLE_TFT_DITHERING_MASK                                                (0x00000020U)

#define DISPC_CAPABLE_STN_DITHERING_SHIFT                                               (6U)
#define DISPC_CAPABLE_STN_DITHERING_MASK                                                (0x00000040U)

#define DISPC_CAPABLE_GFX_TRANSDST_SHIFT                                                (7U)
#define DISPC_CAPABLE_GFX_TRANSDST_MASK                                                 (0x00000080U)

#define DISPC_CAPABLE_GFX_LAYER_SHIFT                                                   (8U)
#define DISPC_CAPABLE_GFX_LAYER_MASK                                                    (0x00000100U)

#define DISPC_CAPABLE_GFX_GAMMA_TBL_SHIFT                                               (9U)
#define DISPC_CAPABLE_GFX_GAMMA_TBL_MASK                                                (0x00000200U)

#define DISPC_DEFAULT_COLOR_SHIFT                                                       (0U)
#define DISPC_DEFAULT_COLOR_MASK                                                        (0x00ffffffU)

#define DISPC_LINE_STS_NUMBER_SHIFT                                                     (0U)
#define DISPC_LINE_STS_NUMBER_MASK                                                      (0x000007ffU)

#define DISPC_LINE_NUMBER_SHIFT                                                         (0U)
#define DISPC_LINE_NUMBER_MASK                                                          (0x000007ffU)

#define DISPC_TIMING_H_HSW_SHIFT                                                        (0U)
#define DISPC_TIMING_H_HSW_MASK                                                         (0x000000ffU)

#define DISPC_TIMING_H_HFP_SHIFT                                                        (8U)
#define DISPC_TIMING_H_HFP_MASK                                                         (0x000fff00U)

#define DISPC_TIMING_H_HBP_SHIFT                                                        (20U)
#define DISPC_TIMING_H_HBP_MASK                                                         (0xfff00000U)

#define DISPC_TIMING_V_VSW_SHIFT                                                        (0U)
#define DISPC_TIMING_V_VSW_MASK                                                         (0x000000ffU)

#define DISPC_TIMING_V_VFP_SHIFT                                                        (8U)
#define DISPC_TIMING_V_VFP_MASK                                                         (0x000fff00U)

#define DISPC_TIMING_V_VBP_SHIFT                                                        (20U)
#define DISPC_TIMING_V_VBP_MASK                                                         (0xfff00000U)

#define DISPC_POL_FREQ_ACB_SHIFT                                                        (0U)
#define DISPC_POL_FREQ_ACB_MASK                                                         (0x000000ffU)

#define DISPC_POL_FREQ_ACBI_SHIFT                                                       (8U)
#define DISPC_POL_FREQ_ACBI_MASK                                                        (0x00000f00U)

#define DISPC_POL_FREQ_IVS_SHIFT                                                        (12U)
#define DISPC_POL_FREQ_IVS_MASK                                                         (0x00001000U)
#define DISPC_POL_FREQ_IVS_ACTIVE_HIGH                                                   (0U)
#define DISPC_POL_FREQ_IVS_ACTIVE_LOW                                                    (1U)

#define DISPC_POL_FREQ_IHS_SHIFT                                                        (13U)
#define DISPC_POL_FREQ_IHS_MASK                                                         (0x00002000U)
#define DISPC_POL_FREQ_IHS_ACTIVE_HIGH                                                   (0U)
#define DISPC_POL_FREQ_IHS_ACTIVE_LOW                                                    (1U)

#define DISPC_POL_FREQ_IPC_SHIFT                                                        (14U)
#define DISPC_POL_FREQ_IPC_MASK                                                         (0x00004000U)
#define DISPC_POL_FREQ_IPC_RISING_EDGE                                                   (0U)
#define DISPC_POL_FREQ_IPC_FALLING_EDGE                                                  (1U)

#define DISPC_POL_FREQ_IEO_SHIFT                                                        (15U)
#define DISPC_POL_FREQ_IEO_MASK                                                         (0x00008000U)
#define DISPC_POL_FREQ_IEO_ACTIVE_HIGH                                                   (0U)
#define DISPC_POL_FREQ_IEO_ACTIVE_LOW                                                    (1U)

#define DISPC_POL_FREQ_RF_SHIFT                                                         (16U)
#define DISPC_POL_FREQ_RF_MASK                                                          (0x00010000U)
#define DISPC_POL_FREQ_RF_FALLING_EDGE                                                   (0U)
#define DISPC_POL_FREQ_RF_RISING_EDGE                                                    (1U)

#define DISPC_POL_FREQ_ONOFF_SHIFT                                                      (17U)
#define DISPC_POL_FREQ_ONOFF_MASK                                                       (0x00020000U)
#define DISPC_POL_FREQ_ONOFF_OPP_EDGES                                                   (0U)
#define DISPC_POL_FREQ_ONOFF_ASPER_BIT_16                                                (1U)

#define DISPC_DIVISOR_PCD_SHIFT                                                         (0U)
#define DISPC_DIVISOR_PCD_MASK                                                          (0x000000ffU)

#define DISPC_DIVISOR_LCD_SHIFT                                                         (16U)
#define DISPC_DIVISOR_LCD_MASK                                                          (0x00ff0000U)

#define DISPC_GLOBAL_ALPHA_GFX_SHIFT                                                    (0U)
#define DISPC_GLOBAL_ALPHA_GFX_MASK                                                     (0x000000ffU)

#define DISPC_GLOBAL_ALPHA_VID2_SHIFT                                                   (16U)
#define DISPC_GLOBAL_ALPHA_VID2_MASK                                                    (0x00ff0000U)

#define DISPC_SIZE_DIG_PPL_SHIFT                                                        (0U)
#define DISPC_SIZE_DIG_PPL_MASK                                                         (0x000007ffU)

#define DISPC_SIZE_DIG_LPP_SHIFT                                                        (16U)
#define DISPC_SIZE_DIG_LPP_MASK                                                         (0x07ff0000U)

#define DISPC_SIZE_LCD_PPL_SHIFT                                                        (0U)
#define DISPC_SIZE_LCD_PPL_MASK                                                         (0x000007ffU)

#define DISPC_SIZE_LCD_LPP_SHIFT                                                        (16U)
#define DISPC_SIZE_LCD_LPP_MASK                                                         (0x07ff0000U)

#define DISPC_TRANS_COLOR_KEY_SHIFT                                                     (0U)
#define DISPC_TRANS_COLOR_KEY_MASK                                                      (0x00ffffffU)

#define DISPC_GFX_BA_SHIFT                                                              (0U)
#define DISPC_GFX_BA_MASK                                                               (0xffffffffU)

#define DISPC_GFX_POSITION_POSX_SHIFT                                                   (0U)
#define DISPC_GFX_POSITION_POSX_MASK                                                    (0x000007ffU)

#define DISPC_GFX_POSITION_POSY_SHIFT                                                   (16U)
#define DISPC_GFX_POSITION_POSY_MASK                                                    (0x07ff0000U)

#define DISPC_GFX_SIZE_SIZEX_SHIFT                                                      (0U)
#define DISPC_GFX_SIZE_SIZEX_MASK                                                       (0x000007ffU)

#define DISPC_GFX_SIZE_SIZEY_SHIFT                                                      (16U)
#define DISPC_GFX_SIZE_SIZEY_MASK                                                       (0x07ff0000U)

#define DISPC_GFX_ATTRS_EN_SHIFT                                                        (0U)
#define DISPC_GFX_ATTRS_EN_MASK                                                         (0x00000001U)
#define DISPC_GFX_ATTRS_EN_DISABLED                                                      (0U)
#define DISPC_GFX_ATTRS_EN_ENABLED                                                       (1U)

#define DISPC_GFX_ATTRS_FMT_SHIFT                                                       (1U)
#define DISPC_GFX_ATTRS_FMT_MASK                                                        (0x0000001eU)
#define DISPC_GFX_ATTRS_FMT_BITMAP1                                                      (0U)
#define DISPC_GFX_ATTRS_FMT_BITMAP2                                                      (1U)
#define DISPC_GFX_ATTRS_FMT_BITMAP4                                                      (2U)
#define DISPC_GFX_ATTRS_FMT_BITMAP8                                                      (3U)
#define DISPC_GFX_ATTRS_FMT_RGB12                                                        (4U)
#define DISPC_GFX_ATTRS_FMT_ARGB16                                                       (5U)
#define DISPC_GFX_ATTRS_FMT_RGB16                                                        (6U)
#define DISPC_GFX_ATTRS_FMT_RGB24_UNPACKED                                               (8U)
#define DISPC_GFX_ATTRS_FMT_RGB24_PACKED                                                 (9U)
#define DISPC_GFX_ATTRS_FMT_ARGB32                                                       (12U)
#define DISPC_GFX_ATTRS_FMT_RGBA32                                                       (13U)
#define DISPC_GFX_ATTRS_FMT_RGBX32                                                       (14U)

#define DISPC_GFX_ATTRS_REPLICATION_EN_SHIFT                                            (5U)
#define DISPC_GFX_ATTRS_REPLICATION_EN_MASK                                             (0x00000020U)
#define DISPC_GFX_ATTRS_REPLICATION_EN_DISABLED                                          (0U)
#define DISPC_GFX_ATTRS_REPLICATION_EN_ENABLED                                           (1U)

#define DISPC_GFX_ATTRS_BURST_SIZE_SHIFT                                                (6U)
#define DISPC_GFX_ATTRS_BURST_SIZE_MASK                                                 (0x000000c0U)
#define DISPC_GFX_ATTRS_BURST_SIZE_BITS4X32                                              (0U)
#define DISPC_GFX_ATTRS_BURST_SIZE_BITS8X32                                              (1U)
#define DISPC_GFX_ATTRS_BURST_SIZE_BITS16X32                                             (2U)
#define DISPC_GFX_ATTRS_BURST_SIZE_RESERVED                                              (3U)

#define DISPC_GFX_ATTRS_CHANNEL_OUT_SHIFT                                               (8U)
#define DISPC_GFX_ATTRS_CHANNEL_OUT_MASK                                                (0x00000100U)
#define DISPC_GFX_ATTRS_CHANNEL_OUT_LCD                                                  (0U)
#define DISPC_GFX_ATTRS_CHANNEL_OUT_BIT24                                                (1U)

#define DISPC_GFX_ATTRS_NIBBLE_MODE_SHIFT                                               (9U)
#define DISPC_GFX_ATTRS_NIBBLE_MODE_MASK                                                (0x00000200U)
#define DISPC_GFX_ATTRS_NIBBLE_MODE_DISABLED                                             (0U)
#define DISPC_GFX_ATTRS_NIBBLE_MODE_ENABLED                                              (1U)

#define DISPC_GFX_ATTRS_ENDIAN_SHIFT                                                    (10U)
#define DISPC_GFX_ATTRS_ENDIAN_MASK                                                     (0x00000400U)
#define DISPC_GFX_ATTRS_ENDIAN_LITTLE                                                    (0U)
#define DISPC_GFX_ATTRS_ENDIAN_BIG                                                       (1U)

#define DISPC_GFX_ATTRS_FIFO_PRELOAD_SHIFT                                              (11U)
#define DISPC_GFX_ATTRS_FIFO_PRELOAD_MASK                                               (0x00000800U)
#define DISPC_GFX_ATTRS_FIFO_PRELOAD_VAL                                                 (0U)
#define DISPC_GFX_ATTRS_FIFO_PRELOAD_THRESHOLD_VAL                                       (1U)

#define DISPC_GFX_ATTRS_ROTATION_SHIFT                                                  (12U)
#define DISPC_GFX_ATTRS_ROTATION_MASK                                                   (0x00003000U)
#define DISPC_GFX_ATTRS_ROTATION_DEG0                                                    (0U)
#define DISPC_GFX_ATTRS_ROTATION_DEG90                                                   (1U)
#define DISPC_GFX_ATTRS_ROTATION_DEG180                                                  (2U)
#define DISPC_GFX_ATTRS_ROTATION_DEG270                                                  (3U)

#define DISPC_GFX_ATTRS_ARBITRATION_SHIFT                                               (14U)
#define DISPC_GFX_ATTRS_ARBITRATION_MASK                                                (0x00004000U)
#define DISPC_GFX_ATTRS_ARBITRATION_NORMAL_PRIORITY                                      (0U)
#define DISPC_GFX_ATTRS_ARBITRATION_HIGH_PRIORITY                                        (1U)

#define DISPC_GFX_ATTRS_SELF_REFRESH_SHIFT                                              (15U)
#define DISPC_GFX_ATTRS_SELF_REFRESH_MASK                                               (0x00008000U)
#define DISPC_GFX_ATTRS_SELF_REFRESH_INTERCON                                            (0U)
#define DISPC_GFX_ATTRS_SELF_REFRESH_FIFO                                                (1U)

#define DISPC_GFX_ATTRS_PRE_MULTIPLY_ALPHA_SHIFT                                        (28U)
#define DISPC_GFX_ATTRS_PRE_MULTIPLY_ALPHA_MASK                                         (0x10000000U)
#define DISPC_GFX_ATTRS_PRE_MULTIPLY_ALPHA_DISABLED                                      (0U)
#define DISPC_GFX_ATTRS_PRE_MULTIPLY_ALPHA_ENABLED                                       (1U)

#define DISPC_GFX_FIFO_THR_LOW_SHIFT                                                    (0U)
#define DISPC_GFX_FIFO_THR_LOW_MASK                                                     (0x000007ffU)

#define DISPC_GFX_FIFO_THR_HIGH_SHIFT                                                   (16U)
#define DISPC_GFX_FIFO_THR_HIGH_MASK                                                    (0x07ff0000U)

#define DISPC_GFX_FIFO_SIZE_STS_SHIFT                                                   (0U)
#define DISPC_GFX_FIFO_SIZE_STS_MASK                                                    (0x000007ffU)

#define DISPC_GFX_ROW_INC_SHIFT                                                         (0U)
#define DISPC_GFX_ROW_INC_MASK                                                          (0xffffffffU)

#define DISPC_GFX_PIXEL_INC_SHIFT                                                       (0U)
#define DISPC_GFX_PIXEL_INC_MASK                                                        (0x0000ffffU)

#define DISPC_GFX_WINDOW_SKIP_SHIFT                                                     (0U)
#define DISPC_GFX_WINDOW_SKIP_MASK                                                      (0xffffffffU)

#define DISPC_GFX_TBL_BA_SHIFT                                                          (0U)
#define DISPC_GFX_TBL_BA_MASK                                                           (0xffffffffU)

#define DISPC_VID_BA_SHIFT                                                              (0U)
#define DISPC_VID_BA_MASK                                                               (0xffffffffU)

#define DISPC_VID_POSITION_POSX_SHIFT                                                   (0U)
#define DISPC_VID_POSITION_POSX_MASK                                                    (0x000007ffU)

#define DISPC_VID_POSITION_POSY_SHIFT                                                   (16U)
#define DISPC_VID_POSITION_POSY_MASK                                                    (0x07ff0000U)

#define DISPC_VID_SIZE_X_SHIFT                                                          (0U)
#define DISPC_VID_SIZE_X_MASK                                                           (0x000007ffU)

#define DISPC_VID_SIZE_Y_SHIFT                                                          (16U)
#define DISPC_VID_SIZE_Y_MASK                                                           (0x07ff0000U)

#define DISPC_VID_ATTRS_EN_SHIFT                                                        (0U)
#define DISPC_VID_ATTRS_EN_MASK                                                         (0x00000001U)
#define DISPC_VID_ATTRS_EN_DISBALE                                                       (0U)
#define DISPC_VID_ATTRS_EN_ENABLE                                                        (1U)

#define DISPC_VID_ATTRS_FMT_SHIFT                                                       (1U)
#define DISPC_VID_ATTRS_FMT_MASK                                                        (0x0000001eU)
#define DISPC_VID_ATTRS_FMT_RESERVED1                                                    (0U)
#define DISPC_VID_ATTRS_FMT_RESERVED2                                                    (1U)
#define DISPC_VID_ATTRS_FMT_RESERVED3                                                    (2U)
#define DISPC_VID_ATTRS_FMT_RESERVED4                                                    (3U)
#define DISPC_VID_ATTRS_FMT_RGB12                                                        (4U)
#define DISPC_VID_ATTRS_FMT_ARGB16                                                       (5U)
#define DISPC_VID_ATTRS_FMT_RGB16                                                        (6U)
#define DISPC_VID_ATTRS_FMT_RESERVED5                                                    (7U)
#define DISPC_VID_ATTRS_FMT_RGB24_UNPACKED                                               (8U)
#define DISPC_VID_ATTRS_FMT_RGB24_PACKED                                                 (9U)
#define DISPC_VID_ATTRS_FMT_YUV2_422                                                     (10U)
#define DISPC_VID_ATTRS_FMT_YUVY_422                                                     (11U)
#define DISPC_VID_ATTRS_FMT_ARGB32                                                       (12U)
#define DISPC_VID_ATTRS_FMT_RGBA32                                                       (13U)
#define DISPC_VID_ATTRS_FMT_RGBX32                                                       (14U)
#define DISPC_VID_ATTRS_FMT_RESERVED6                                                    (15U)

#define DISPC_VID_ATTRS_RESIZE_EN_SHIFT                                                 (5U)
#define DISPC_VID_ATTRS_RESIZE_EN_MASK                                                  (0x00000060U)
#define DISPC_VID_ATTRS_RESIZE_EN_DISBALE                                                (0U)
#define DISPC_VID_ATTRS_RESIZE_EN_ENABLE_HOR                                             (1U)
#define DISPC_VID_ATTRS_RESIZE_EN_ENABLE_VER                                             (2U)
#define DISPC_VID_ATTRS_RESIZE_EN_ENABLE_BOTH                                            (3U)

#define DISPC_VID_ATTRS_HRESIZE_CONF_SHIFT                                              (7U)
#define DISPC_VID_ATTRS_HRESIZE_CONF_MASK                                               (0x00000080U)
#define DISPC_VID_ATTRS_HRESIZE_CONF_UPSAMPLING                                          (0U)
#define DISPC_VID_ATTRS_HRESIZE_CONF_DOWNSAMPLING                                        (1U)

#define DISPC_VID_ATTRS_VRESIZE_CONF_SHIFT                                              (8U)
#define DISPC_VID_ATTRS_VRESIZE_CONF_MASK                                               (0x00000100U)
#define DISPC_VID_ATTRS_VRESIZE_CONF_UPSAMPLING                                          (0U)
#define DISPC_VID_ATTRS_VRESIZE_CONF_DOWNSAMPLING                                        (1U)

#define DISPC_VID_ATTRS_COLOR_CONV_EN_SHIFT                                             (9U)
#define DISPC_VID_ATTRS_COLOR_CONV_EN_MASK                                              (0x00000200U)
#define DISPC_VID_ATTRS_COLOR_CONV_EN_DISBALE                                            (0U)
#define DISPC_VID_ATTRS_COLOR_CONV_EN_ENABLE                                             (1U)

#define DISPC_VID_ATTRS_REPLICATION_EN_SHIFT                                            (10U)
#define DISPC_VID_ATTRS_REPLICATION_EN_MASK                                             (0x00000400U)
#define DISPC_VID_ATTRS_REPLICATION_EN_DISBALE                                           (0U)
#define DISPC_VID_ATTRS_REPLICATION_EN_ENABLE                                            (1U)

#define DISPC_VID_ATTRS_FULL_RANGE_SHIFT                                                (11U)
#define DISPC_VID_ATTRS_FULL_RANGE_MASK                                                 (0x00000800U)
#define DISPC_VID_ATTRS_FULL_RANGE_LIMITED                                               (0U)
#define DISPC_VID_ATTRS_FULL_RANGE                                                       (1U)

#define DISPC_VID_ATTRS_ROTATION_SHIFT                                                  (12U)
#define DISPC_VID_ATTRS_ROTATION_MASK                                                   (0x00003000U)
#define DISPC_VID_ATTRS_ROTATION_DEG0                                                    (0U)
#define DISPC_VID_ATTRS_ROTATION_DEG90                                                   (1U)
#define DISPC_VID_ATTRS_ROTATION_DEG180                                                  (2U)
#define DISPC_VID_ATTRS_ROTATION_DEG270                                                  (3U)

#define DISPC_VID_ATTRS_BURST_SIZE_SHIFT                                                (14U)
#define DISPC_VID_ATTRS_BURST_SIZE_MASK                                                 (0x0000c000U)
#define DISPC_VID_ATTRS_BURST_SIZE_BITS4X32                                              (0U)
#define DISPC_VID_ATTRS_BURST_SIZE_BITS8X32                                              (1U)
#define DISPC_VID_ATTRS_BURST_SIZE_BITS16X32                                             (2U)
#define DISPC_VID_ATTRS_BURST_SIZE_RESERVED                                              (3U)

#define DISPC_VID_ATTRS_CHANNEL_OUT_SHIFT                                               (16U)
#define DISPC_VID_ATTRS_CHANNEL_OUT_MASK                                                (0x00010000U)
#define DISPC_VID_ATTRS_CHANNEL_OUT_LCD                                                  (0U)
#define DISPC_VID_ATTRS_CHANNEL_OUT_BIT24                                                (1U)

#define DISPC_VID_ATTRS_ENDIAN_SHIFT                                                    (17U)
#define DISPC_VID_ATTRS_ENDIAN_MASK                                                     (0x00020000U)
#define DISPC_VID_ATTRS_ENDIAN_LITTLE                                                    (0U)
#define DISPC_VID_ATTRS_ENDIAN_BIG                                                       (1U)

#define DISPC_VID_ATTRS_ROW_REPEAT_EN_SHIFT                                             (18U)
#define DISPC_VID_ATTRS_ROW_REPEAT_EN_MASK                                              (0x00040000U)
#define DISPC_VID_ATTRS_ROW_REPEAT_EN_DISBALE                                            (0U)
#define DISPC_VID_ATTRS_ROW_REPEAT_EN_ENABLE                                             (1U)

#define DISPC_VID_ATTRS_FIFO_PRELOAD_SHIFT                                              (19U)
#define DISPC_VID_ATTRS_FIFO_PRELOAD_MASK                                               (0x00080000U)
#define DISPC_VID_ATTRS_FIFO_PRELOAD_VAL                                                 (0U)
#define DISPC_VID_ATTRS_FIFO_PRELOAD_THRESHOLD_VAL                                       (1U)

#define DISPC_VID_ATTRS_OPTIMIZATION_SHIFT                                              (20U)
#define DISPC_VID_ATTRS_OPTIMIZATION_MASK                                               (0x00100000U)
#define DISPC_VID_ATTRS_OPTIMIZATION_ONE_PIX                                             (0U)
#define DISPC_VID_ATTRS_OPTIMIZATION_TWO_PIX                                             (1U)

#define DISPC_VID_ATTRS_VERTICAL_TAPS_SHIFT                                             (21U)
#define DISPC_VID_ATTRS_VERTICAL_TAPS_MASK                                              (0x00200000U)
#define DISPC_VID_ATTRS_VERTICAL_TAPS_THREE                                              (0U)
#define DISPC_VID_ATTRS_VERTICAL_TAPS_FIVE                                               (1U)

#define DISPC_VID_ATTRS_LINE_BUFFER_SPLIT_SHIFT                                         (22U)
#define DISPC_VID_ATTRS_LINE_BUFFER_SPLIT_MASK                                          (0x00400000U)
#define DISPC_VID_ATTRS_LINE_BUFFER_SPLIT_NOT                                            (0U)
#define DISPC_VID_ATTRS_LINE_BUFFER_SPLIT_INTO_TWO                                       (1U)

#define DISPC_VID_ATTRS_ARBITRATION_SHIFT                                               (23U)
#define DISPC_VID_ATTRS_ARBITRATION_MASK                                                (0x00800000U)
#define DISPC_VID_ATTRS_ARBITRATION_NORMAL_PRIORITY                                      (0U)
#define DISPC_VID_ATTRS_ARBITRATION_HIGH_PRIORITY                                        (1U)

#define DISPC_VID_ATTRS_SELF_REFRESH_SHIFT                                              (24U)
#define DISPC_VID_ATTRS_SELF_REFRESH_MASK                                               (0x01000000U)
#define DISPC_VID_ATTRS_SELF_REFRESH_INTERCON                                            (0U)
#define DISPC_VID_ATTRS_SELF_REFRESH_FIFO                                                (1U)

#define DISPC_VID_ATTRS_PRE_MULTIPLY_ALPHA_SHIFT                                        (28U)
#define DISPC_VID_ATTRS_PRE_MULTIPLY_ALPHA_MASK                                         (0x10000000U)
#define DISPC_VID_ATTRS_PRE_MULTIPLY_ALPHA_DISBALE                                       (0U)
#define DISPC_VID_ATTRS_PRE_MULTIPLY_ALPHA_ENABLE                                        (1U)

#define DISPC_VID_FIFO_THR_LOW_SHIFT                                                    (0U)
#define DISPC_VID_FIFO_THR_LOW_MASK                                                     (0x000007ffU)

#define DISPC_VID_FIFO_THR_HIGH_SHIFT                                                   (16U)
#define DISPC_VID_FIFO_THR_HIGH_MASK                                                    (0x07ff0000U)

#define DISPC_VID_FIFO_SIZE_STS_SHIFT                                                   (0U)
#define DISPC_VID_FIFO_SIZE_STS_MASK                                                    (0x000007ffU)

#define DISPC_VID_ROW_INC_SHIFT                                                         (0U)
#define DISPC_VID_ROW_INC_MASK                                                          (0xffffffffU)

#define DISPC_VID_PIXEL_INC_SHIFT                                                       (0U)
#define DISPC_VID_PIXEL_INC_MASK                                                        (0x0000ffffU)

#define DISPC_VID_FIR_H_INC_SHIFT                                                       (0U)
#define DISPC_VID_FIR_H_INC_MASK                                                        (0x00001fffU)

#define DISPC_VID_FIR_V_INC_SHIFT                                                       (16U)
#define DISPC_VID_FIR_V_INC_MASK                                                        (0x1fff0000U)

#define DISPC_VID_PICTURE_SIZE_ORG_X_SHIFT                                              (0U)
#define DISPC_VID_PICTURE_SIZE_ORG_X_MASK                                               (0x000007ffU)

#define DISPC_VID_PICTURE_SIZE_ORG_Y_SHIFT                                              (16U)
#define DISPC_VID_PICTURE_SIZE_ORG_Y_MASK                                               (0x07ff0000U)

#define DISPC_VID_ACCU_HORIZONTAL_SHIFT                                                 (0U)
#define DISPC_VID_ACCU_HORIZONTAL_MASK                                                  (0x000003ffU)

#define DISPC_VID_ACCU_VERTICAL_SHIFT                                                   (16U)
#define DISPC_VID_ACCU_VERTICAL_MASK                                                    (0x03ff0000U)

#define DISPC_VID1_FIR_COEF_H_HC0_SHIFT                                                 (0U)
#define DISPC_VID1_FIR_COEF_H_HC0_MASK                                                  (0x000000ffU)

#define DISPC_VID1_FIR_COEF_H_HC1_SHIFT                                                 (8U)
#define DISPC_VID1_FIR_COEF_H_HC1_MASK                                                  (0x0000ff00U)

#define DISPC_VID1_FIR_COEF_H_HC2_SHIFT                                                 (16U)
#define DISPC_VID1_FIR_COEF_H_HC2_MASK                                                  (0x00ff0000U)

#define DISPC_VID1_FIR_COEF_H_HC3_SHIFT                                                 (24U)
#define DISPC_VID1_FIR_COEF_H_HC3_MASK                                                  (0xff000000U)

#define DISPC_VID1_FIR_COEF_HV_HC4_SHIFT                                                (0U)
#define DISPC_VID1_FIR_COEF_HV_HC4_MASK                                                 (0x000000ffU)

#define DISPC_VID1_FIR_COEF_HV_VC0_SHIFT                                                (8U)
#define DISPC_VID1_FIR_COEF_HV_VC0_MASK                                                 (0x0000ff00U)

#define DISPC_VID1_FIR_COEF_HV_VC1_SHIFT                                                (16U)
#define DISPC_VID1_FIR_COEF_HV_VC1_MASK                                                 (0x00ff0000U)

#define DISPC_VID1_FIR_COEF_HV_VC2_SHIFT                                                (24U)
#define DISPC_VID1_FIR_COEF_HV_VC2_MASK                                                 (0xff000000U)

#define DISPC_VID_PRELOAD_SHIFT                                                         (0U)
#define DISPC_VID_PRELOAD_MASK                                                          (0x00000fffU)

#define DISPC_GFX_PRELOAD_SHIFT                                                         (0U)
#define DISPC_GFX_PRELOAD_MASK                                                          (0x00000fffU)

#define DISPC_VID2_FIR_COEF_H_HC0_SHIFT                                                 (0U)
#define DISPC_VID2_FIR_COEF_H_HC0_MASK                                                  (0x000000ffU)

#define DISPC_VID2_FIR_COEF_H_HC1_SHIFT                                                 (8U)
#define DISPC_VID2_FIR_COEF_H_HC1_MASK                                                  (0x0000ff00U)

#define DISPC_VID2_FIR_COEF_H_HC2_SHIFT                                                 (16U)
#define DISPC_VID2_FIR_COEF_H_HC2_MASK                                                  (0x00ff0000U)

#define DISPC_VID2_FIR_COEF_H_HC3_SHIFT                                                 (24U)
#define DISPC_VID2_FIR_COEF_H_HC3_MASK                                                  (0xff000000U)

#define DISPC_VID2_FIR_COEF_HV_HC4_SHIFT                                                (0U)
#define DISPC_VID2_FIR_COEF_HV_HC4_MASK                                                 (0x000000ffU)

#define DISPC_VID2_FIR_COEF_HV_VC0_SHIFT                                                (8U)
#define DISPC_VID2_FIR_COEF_HV_VC0_MASK                                                 (0x0000ff00U)

#define DISPC_VID2_FIR_COEF_HV_VC1_SHIFT                                                (16U)
#define DISPC_VID2_FIR_COEF_HV_VC1_MASK                                                 (0x00ff0000U)

#define DISPC_VID2_FIR_COEF_HV_VC2_SHIFT                                                (24U)
#define DISPC_VID2_FIR_COEF_HV_VC2_MASK                                                 (0xff000000U)

#define DISPC_DATA_CYCLE_NB_BITS_PIXEL1_SHIFT                                           (0U)
#define DISPC_DATA_CYCLE_NB_BITS_PIXEL1_MASK                                            (0x0000001fU)

#define DISPC_DATA_CYCLE_BIT_ALIGNMENT_PIXEL1_SHIFT                                     (8U)
#define DISPC_DATA_CYCLE_BIT_ALIGNMENT_PIXEL1_MASK                                      (0x00000f00U)

#define DISPC_DATA_CYCLE_NB_BITS_PIXEL2_SHIFT                                           (16U)
#define DISPC_DATA_CYCLE_NB_BITS_PIXEL2_MASK                                            (0x001f0000U)

#define DISPC_DATA_CYCLE_BIT_ALIGNMENT_PIXEL2_SHIFT                                     (24U)
#define DISPC_DATA_CYCLE_BIT_ALIGNMENT_PIXEL2_MASK                                      (0x0f000000U)

#define DISPC_CPR_COEF_R_RB_SHIFT                                                       (0U)
#define DISPC_CPR_COEF_R_RB_MASK                                                        (0x000003ffU)

#define DISPC_CPR_COEF_R_RG_SHIFT                                                       (11U)
#define DISPC_CPR_COEF_R_RG_MASK                                                        (0x001ff800U)

#define DISPC_CPR_COEF_R_RR_SHIFT                                                       (22U)
#define DISPC_CPR_COEF_R_RR_MASK                                                        (0xffc00000U)

#define DISPC_CPR_COEF_G_GB_SHIFT                                                       (0U)
#define DISPC_CPR_COEF_G_GB_MASK                                                        (0x000003ffU)

#define DISPC_CPR_COEF_G_GG_SHIFT                                                       (11U)
#define DISPC_CPR_COEF_G_GG_MASK                                                        (0x001ff800U)

#define DISPC_CPR_COEF_G_GR_SHIFT                                                       (22U)
#define DISPC_CPR_COEF_G_GR_MASK                                                        (0xffc00000U)

#define DISPC_CPR_COEF_B_BB_SHIFT                                                       (0U)
#define DISPC_CPR_COEF_B_BB_MASK                                                        (0x000003ffU)

#define DISPC_CPR_COEF_B_BG_SHIFT                                                       (11U)
#define DISPC_CPR_COEF_B_BG_MASK                                                        (0x001ff800U)

#define DISPC_CPR_COEF_B_BR_SHIFT                                                       (22U)
#define DISPC_CPR_COEF_B_BR_MASK                                                        (0xffc00000U)

#define DISPC_VID_CONV_COEF0_RY_SHIFT                                                   (0U)
#define DISPC_VID_CONV_COEF0_RY_MASK                                                    (0x000007ffU)

#define DISPC_VID_CONV_COEF0_RCR_SHIFT                                                  (16U)
#define DISPC_VID_CONV_COEF0_RCR_MASK                                                   (0x07ff0000U)

#define DISPC_VID_CONV_COEF1_RCB_SHIFT                                                  (0U)
#define DISPC_VID_CONV_COEF1_RCB_MASK                                                   (0x000007ffU)

#define DISPC_VID_CONV_COEF1_GY_SHIFT                                                   (16U)
#define DISPC_VID_CONV_COEF1_GY_MASK                                                    (0x07ff0000U)

#define DISPC_VID_CONV_COEF2_GCR_SHIFT                                                  (0U)
#define DISPC_VID_CONV_COEF2_GCR_MASK                                                   (0x000007ffU)

#define DISPC_VID_CONV_COEF2_GCB_SHIFT                                                  (16U)
#define DISPC_VID_CONV_COEF2_GCB_MASK                                                   (0x07ff0000U)

#define DISPC_VID_CONV_COEF3_BY_SHIFT                                                   (0U)
#define DISPC_VID_CONV_COEF3_BY_MASK                                                    (0x000007ffU)

#define DISPC_VID_CONV_COEF3_BCR_SHIFT                                                  (16U)
#define DISPC_VID_CONV_COEF3_BCR_MASK                                                   (0x07ff0000U)

#define DISPC_VID_CONV_COEF4_BCB_SHIFT                                                  (0U)
#define DISPC_VID_CONV_COEF4_BCB_MASK                                                   (0x000007ffU)

#define DISPC_VID_FIR_COEF_V_VC00_SHIFT                                                 (0U)
#define DISPC_VID_FIR_COEF_V_VC00_MASK                                                  (0x000000ffU)

#define DISPC_VID_FIR_COEF_V_VC22_SHIFT                                                 (8U)
#define DISPC_VID_FIR_COEF_V_VC22_MASK                                                  (0x0000ff00U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_DSS_DISPC_H_ */
