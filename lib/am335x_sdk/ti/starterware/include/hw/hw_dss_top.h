/*
* hw_dss_top.h
*
* Register-level header file for DSS_TOP [AEGIS_PUBLIC_INCLUDE]
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

#ifndef HW_DSS_TOP_H_
#define HW_DSS_TOP_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define DSS_REVISIONNUMBER                                          (0x0U)
#define DSS_SYSCONFIG                                               (0x10U)
#define DSS_SYSSTS                                                  (0x14U)
#define DSS_CTRL                                                    (0x40U)
#define DSS_CLK_STS                                                 (0x5cU)
#define DSS_IRQSTS                                                  (0x18U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define DSS_REVISIONNUMBER_REV_SHIFT                                                    (0U)
#define DSS_REVISIONNUMBER_REV_MASK                                                     (0x000000ffU)

#define DSS_SYSCONFIG_SOFTRESET_SHIFT                                                   (1U)
#define DSS_SYSCONFIG_SOFTRESET_MASK                                                    (0x00000002U)
#define DSS_SYSCONFIG_SOFTRESET_NORMAL                                                   (0U)
#define DSS_SYSCONFIG_SOFTRESET_RESET                                                    (1U)

#define DSS_SYSCONFIG_AUTOIDLE_SHIFT                                                    (0U)
#define DSS_SYSCONFIG_AUTOIDLE_MASK                                                     (0x00000001U)
#define DSS_SYSCONFIG_AUTOIDLE_FREE_RUNNING                                              (0U)
#define DSS_SYSCONFIG_AUTOIDLE_AUTOMATIC                                                 (1U)

#define DSS_SYSSTS_RESETDONE_SHIFT                                                      (0U)
#define DSS_SYSSTS_RESETDONE_MASK                                                       (0x00000001U)
#define DSS_SYSSTS_RESETDONE_DONE                                                        (1U)
#define DSS_SYSSTS_RESETDONE_ONGOING                                                     (0U)

#define DSS_CTRL_LCD1_CLK_SWITCH_SHIFT                                                  (0U)
#define DSS_CTRL_LCD1_CLK_SWITCH_MASK                                                   (0x00000001U)
#define DSS_CTRL_LCD1_CLK_SWITCH_SEL                                                     (0U)
#define DSS_CTRL_LCD1_CLK_SWITCH_PLL1_CLK1_SEL                                           (1U)

#define DSS_CTRL_DSI1_CLK_SWITCH_SHIFT                                                  (1U)
#define DSS_CTRL_DSI1_CLK_SWITCH_MASK                                                   (0x00000002U)
#define DSS_CTRL_DSI1_CLK_SWITCH_SEL                                                     (0U)
#define DSS_CTRL_DSI1_CLK_SWITCH_PLL1_CLK1_SEL                                           (1U)

#define DSS_CTRL_VENC_CLOCK_MODE_SHIFT                                                  (2U)
#define DSS_CTRL_VENC_CLOCK_MODE_MASK                                                   (0x00000004U)
#define DSS_CTRL_VENC_CLOCK_MODE_MODE0                                                   (0U)
#define DSS_CTRL_VENC_CLOCK_MODE_MODE1                                                   (1U)

#define DSS_CTRL_VENC_CLOCK_4X_EN_SHIFT                                                 (3U)
#define DSS_CTRL_VENC_CLOCK_4X_EN_MASK                                                  (0x00000008U)
#define DSS_CTRL_VENC_CLOCK_4X_EN_DISABLE                                                (0U)
#define DSS_CTRL_VENC_CLOCK_4X_EN_ENABLE                                                 (1U)

#define DSS_CTRL_DAC_DEMEN_SHIFT                                                        (4U)
#define DSS_CTRL_DAC_DEMEN_MASK                                                         (0x00000010U)
#define DSS_CTRL_DAC_DEMEN_DISABLE                                                       (0U)
#define DSS_CTRL_DAC_DEMEN_ENABLE                                                        (1U)

#define DSS_CTRL_DAC_POWERDN_BGZ_SHIFT                                                  (5U)
#define DSS_CTRL_DAC_POWERDN_BGZ_MASK                                                   (0x00000020U)
#define DSS_CTRL_DAC_POWERDN_BGZ_DISABLE                                                 (0U)
#define DSS_CTRL_DAC_POWERDN_BGZ_ENABLE                                                  (1U)

#define DSS_CTRL_VENC_OUT_SEL_SHIFT                                                     (6U)
#define DSS_CTRL_VENC_OUT_SEL_MASK                                                      (0x00000040U)
#define DSS_CTRL_VENC_OUT_SEL_COMPOSITE                                                  (0U)
#define DSS_CTRL_VENC_OUT_SEL_LUMINANCE                                                  (1U)

#define DSS_CTRL_FCK_CLK_SWITCH_SHIFT                                                   (8U)
#define DSS_CTRL_FCK_CLK_SWITCH_MASK                                                    (0x00000300U)
#define DSS_CTRL_FCK_CLK_SWITCH                                                          (0U)
#define DSS_CTRL_FCK_CLK_SWITCH_PLL1_CLK1                                                (1U)
#define DSS_CTRL_FCK_CLK_SWITCH_PLL2_CLK1                                                (2U)
#define DSS_CTRL_FCK_CLK_SWITCH_PLL3_CLK1                                                (3U)

#define DSS_CTRL_DSI2_CLK_SWITCH_SHIFT                                                  (10U)
#define DSS_CTRL_DSI2_CLK_SWITCH_MASK                                                   (0x00000400U)
#define DSS_CTRL_DSI2_CLK_SWITCH                                                         (0U)
#define DSS_CTRL_DSI2_CLK_SWITCH_PLL2_CLK2                                               (1U)

#define DSS_CTRL_TV_CLK_SWITCH_SHIFT                                                    (11U)
#define DSS_CTRL_TV_CLK_SWITCH_MASK                                                     (0x00000800U)
#define DSS_CTRL_TV_CLK_SWITCH_PLL3_CLK1                                                 (0U)
#define DSS_CTRL_TV_CLK_SWITCH                                                           (1U)

#define DSS_CTRL_LCD2_CLK_SWITCH_SHIFT                                                  (12U)
#define DSS_CTRL_LCD2_CLK_SWITCH_MASK                                                   (0x00001000U)
#define DSS_CTRL_LCD2_CLK_SWITCH                                                         (0U)
#define DSS_CTRL_LCD2_CLK_SWITCH_PLL2_CLK1                                               (1U)

#define DSS_CTRL_SYNC_SWITCH_SHIFT                                                      (13U)
#define DSS_CTRL_SYNC_SWITCH_MASK                                                       (0x00002000U)
#define DSS_CTRL_SYNC_SWITCH_INTERNAL_VENC                                               (0U)
#define DSS_CTRL_SYNC_SWITCH_COMPONENT_VENC                                              (1U)

#define DSS_CTRL_RFBI_SWITCH_SHIFT                                                      (14U)
#define DSS_CTRL_RFBI_SWITCH_MASK                                                       (0x00004000U)
#define DSS_CTRL_RFBI_SWITCH_VIDEO_PORT_1                                                (0U)
#define DSS_CTRL_RFBI_SWITCH_VIDEO_PORT_2                                                (1U)

#define DSS_CTRL_VENC_HDMI_SWITCH_SHIFT                                                 (15U)
#define DSS_CTRL_VENC_HDMI_SWITCH_MASK                                                  (0x00008000U)
/* TODO: #define DSS_CTRL_VENC_HDMI_SWITCH                                                        (0U) */
/* TODO: #define DSS_CTRL_VENC_HDMI_SWITCH                                                        (1U) */

#define DSS_CLK_STS_LCD1_SHIFT                                                          (0U)
#define DSS_CLK_STS_LCD1_MASK                                                           (0x00000003U)
/* TODO:#define DSS_CLK_STS_LCD1                                                                 (0U)  */
/* TODO:#define DSS_CLK_STS_LCD1                                                                 (1U)  */
/* TODO:#define DSS_CLK_STS_LCD1_PLL1_CLK1                                                       (2U)  */

#define DSS_CLK_STS_TV_OUT_SHIFT                                                        (5U)
#define DSS_CLK_STS_TV_OUT_MASK                                                         (0x00000060U)
#define DSS_CLK_STS_TV_OUT                                                               (1U)
#define DSS_CLK_STS_TV_OUT_P                                                             (2U)

#define DSS_CLK_STS_DSI1_SHIFT                                                          (7U)
#define DSS_CLK_STS_DSI1_MASK                                                           (0x00000180U)
/* TODO:#define DSS_CLK_STS_DSI1                                                                 (0U) */
/* TODO:#define DSS_CLK_STS_DSI1                                                                 (1U) */
/* TODO:#define DSS_CLK_STS_DSI1_PLL1_CLK2                                                       (2U) */

#define DSS_CLK_STS_DSI2_SHIFT                                                          (9U)
#define DSS_CLK_STS_DSI2_MASK                                                           (0x00000600U)
/* TODO:#define DSS_CLK_STS_DSI2                                                                 (0U)  */
/* TODO:#define DSS_CLK_STS_DSI2                                                                 (1U)  */
/* TODO:#define DSS_CLK_STS_DSI2_PLL2_CLK2                                                       (2U)  */

#define DSS_CLK_STS_LCD2_SHIFT                                                          (11U)
#define DSS_CLK_STS_LCD2_MASK                                                           (0x00001800U)
/* TODO:#define DSS_CLK_STS_LCD2                                                                 (0U)  */
/* TODO:#define DSS_CLK_STS_LCD2                                                                 (1U)  */
/* TODO:#define DSS_CLK_STS_LCD2_PLL2_CLK2                                                       (2U)  */

#define DSS_CLK_STS_TV_SHIFT                                                            (13U)
#define DSS_CLK_STS_TV_MASK                                                             (0x00006000U)
#define DSS_CLK_STS_TV                                                                   (2U)
#define DSS_CLK_STS_TV_PLL3_CLK1                                                         (1U)

#define DSS_CLK_STS_FCK_SHIFT                                                           (15U)
#define DSS_CLK_STS_FCK_MASK                                                            (0x00078000U)
#define DSS_CLK_STS_FCK_SWITCH                                                           (0U)
#define DSS_CLK_STS_FCK                                                                  (1U)
#define DSS_CLK_STS_FCK_PLL1_CLK1                                                        (2U)
#define DSS_CLK_STS_FCK_PLL2_CLK1                                                        (4U)
#define DSS_CLK_STS_FCK_PLL3_CLK1                                                        (8U)

#define DSS_CLK_STS_SYNC_SHIFT                                                          (19U)
#define DSS_CLK_STS_SYNC_MASK                                                           (0x00180000U)
#define DSS_CLK_STS_SYNC_INTERNAL_VENC                                                   (0U)
#define DSS_CLK_STS_SYNC_COMPONENT_VENC                                                  (1U)
#define DSS_CLK_STS_SYNC_HDMI                                                            (2U)

#define DSS_CLK_STS_RFBI_SHIFT                                                          (21U)
#define DSS_CLK_STS_RFBI_MASK                                                           (0x00200000U)
#define DSS_CLK_STS_RFBI_VIDEO_PORT_1                                                    (0U)
#define DSS_CLK_STS_RFBI_VIDEO_PORT_2                                                    (1U)

#define DSS_CLK_STS_SYNC_SHIFT                                                          (19U)
#define DSS_CLK_STS_SYNC_MASK                                                           (0x00180000U)
#define DSS_CLK_STS_SYNC_INTERNAL_VENC                                                   (0U)
#define DSS_CLK_STS_SYNC_COMPONENT_VENC                                                  (1U)
#define DSS_CLK_STS_SYNC_HDMI                                                            (2U)

#define DSS_IRQSTS_DISPC_IRQ_SHIFT                                                      (0U)
#define DSS_IRQSTS_DISPC_IRQ_MASK                                                       (0x00000001U)
#define DSS_IRQSTS_DISPC_IRQ_INACTIVE                                                    (0U)
#define DSS_IRQSTS_DISPC_IRQ_ACTIVE                                                      (1U)

#define DSS_IRQSTS_DSI_IRQ_SHIFT                                                        (1U)
#define DSS_IRQSTS_DSI_IRQ_MASK                                                         (0x00000002U)
#define DSS_IRQSTS_DSI_IRQ_INACTIVE                                                      (0U)
#define DSS_IRQSTS_DSI_IRQ_ACTIVE                                                        (1U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_DSS_TOP_H_ */
