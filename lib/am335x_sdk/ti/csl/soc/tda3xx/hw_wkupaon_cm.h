/*
 *  Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file   hw_wkupaon_cm.h
 *
 *  \brief  Register-level header file for PRCM
 *
**/

#ifndef HW_WKUPAON_CM_H_
#define HW_WKUPAON_CM_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CM_WKUPAON_CLKSTCTRL                                        (0x0U)
#define CM_WKUPAON_L4_WKUP_CLKCTRL                             (0x20U)
#define CM_WKUPAON_WD_TIMER1_CLKCTRL                           (0x28U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL                           (0x30U)
#define CM_WKUPAON_GPIO1_CLKCTRL                               (0x38U)
#define CM_WKUPAON_TIMER1_CLKCTRL                              (0x40U)
#define CM_WKUPAON_TIMER12_CLKCTRL                             (0x48U)
#define CM_WKUPAON_COUNTER_32K_CLKCTRL                         (0x50U)
#define CM_WKUPAON_KBD_CLKCTRL                                 (0x78U)
#define CM_WKUPAON_UART10_CLKCTRL                              (0x80U)
#define CM_WKUPAON_DCAN1_CLKCTRL                               (0x88U)
#define CM_WKUPAON_SCRM_CLKCTRL                                (0x90U)
#define CM_WKUPAON_IO_SRCOMP_CLKCTRL                           (0x98U)
#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL                       (0xb0U)
#define CM_WKUPAON_RTI1_CLKCTRL                                     (0xb8U)
#define CM_WKUPAON_RTI2_CLKCTRL                                     (0xc0U)
#define CM_WKUPAON_RTI3_CLKCTRL                                     (0xc8U)
#define CM_WKUPAON_RTI4_CLKCTRL                                     (0xd0U)
#define CM_WKUPAON_RTI5_CLKCTRL                                     (0xd8U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CM_WKUPAON_CLKSTCTRL_CLKTRCTRL_SHIFT                                            (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKTRCTRL_MASK                                             (0x00000003U)
#define CM_WKUPAON_CLKSTCTRL_CLKTRCTRL_NO_SLEEP                                          (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKTRCTRL_RESERVED_1                                        (1U)
#define CM_WKUPAON_CLKSTCTRL_CLKTRCTRL_SW_WKUP                                           (2U)
#define CM_WKUPAON_CLKSTCTRL_CLKTRCTRL_HW_AUTO                                           (3U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_SHIFT                                  (8U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_MASK                                   (0x00000100U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_INACT                                   (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_ACT                                     (1U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_ABE_LP_CLK_SHIFT                               (9U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_ABE_LP_CLK_MASK                                (0x00000200U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_ABE_LP_CLK_INACT                                (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_ABE_LP_CLK_ACT                                  (1U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_WKUPAON_SYS_GFCLK_SHIFT                                            (11U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_WKUPAON_SYS_GFCLK_MASK                                             (0x00000800U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_WKUPAON_SYS_GFCLK_INACT                                             (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_WKUPAON_SYS_GFCLK_ACT                                               (1U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_WKUPAON_GICLK_SHIFT                                                (12U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_WKUPAON_GICLK_MASK                                                 (0x00001000U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_WKUPAON_GICLK_INACT                                                 (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_WKUPAON_GICLK_ACT                                                   (1U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_IO_SRCOMP_GFCLK_SHIFT                          (13U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_IO_SRCOMP_GFCLK_MASK                           (0x00002000U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_IO_SRCOMP_GFCLK_INACT                           (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_IO_SRCOMP_GFCLK_ACT                             (1U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_FUNC_SHIFT                             (14U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_FUNC_MASK                              (0x00004000U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_FUNC_INACT                              (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_FUNC_ACT                                (1U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_ALL_SHIFT                              (15U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_ALL_MASK                               (0x00008000U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_ALL_INACT                               (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_SYS_CLK_ALL_ACT                                 (1U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_DCAN1_SYS_CLK_SHIFT                            (16U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_DCAN1_SYS_CLK_MASK                             (0x00010000U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_DCAN1_SYS_CLK_INACT                             (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_DCAN1_SYS_CLK_ACT                               (1U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_TIMER1_GFCLK_SHIFT                             (17U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_TIMER1_GFCLK_MASK                              (0x00020000U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_TIMER1_GFCLK_INACT                              (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_TIMER1_GFCLK_ACT                                (1U)

#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_UART10_GFCLK_SHIFT                             (18U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_UART10_GFCLK_MASK                              (0x00040000U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_UART10_GFCLK_INACT                              (0U)
#define CM_WKUPAON_CLKSTCTRL_CLKACTIVITY_UART10_GFCLK_ACT                                (1U)

#define CM_WKUPAON_L4_WKUP_CLKCTRL_MODULEMODE_SHIFT                                (0U)
#define CM_WKUPAON_L4_WKUP_CLKCTRL_MODULEMODE_MASK                                 (0x00000003U)
#define CM_WKUPAON_L4_WKUP_CLKCTRL_MODULEMODE_AUTO                                  (1U)

#define CM_WKUPAON_L4_WKUP_CLKCTRL_IDLEST_SHIFT                                    (16U)
#define CM_WKUPAON_L4_WKUP_CLKCTRL_IDLEST_MASK                                     (0x00030000U)
#define CM_WKUPAON_L4_WKUP_CLKCTRL_IDLEST_DISABLE                                   (3U)
#define CM_WKUPAON_L4_WKUP_CLKCTRL_IDLEST_IDLE                                      (2U)
#define CM_WKUPAON_L4_WKUP_CLKCTRL_IDLEST_FUNC                                      (0U)
#define CM_WKUPAON_L4_WKUP_CLKCTRL_IDLEST_TRANS                                     (1U)

#define CM_WKUPAON_WD_TIMER1_CLKCTRL_IDLEST_SHIFT                                  (16U)
#define CM_WKUPAON_WD_TIMER1_CLKCTRL_IDLEST_MASK                                   (0x00030000U)
#define CM_WKUPAON_WD_TIMER1_CLKCTRL_IDLEST_DISABLE                                 (3U)
#define CM_WKUPAON_WD_TIMER1_CLKCTRL_IDLEST_IDLE                                    (2U)
#define CM_WKUPAON_WD_TIMER1_CLKCTRL_IDLEST_FUNC                                    (0U)
#define CM_WKUPAON_WD_TIMER1_CLKCTRL_IDLEST_TRANS                                   (1U)

#define CM_WKUPAON_WD_TIMER1_CLKCTRL_MODULEMODE_SHIFT                              (0U)
#define CM_WKUPAON_WD_TIMER1_CLKCTRL_MODULEMODE_MASK                               (0x00000003U)
#define CM_WKUPAON_WD_TIMER1_CLKCTRL_MODULEMODE_AUTO                                (1U)

#define CM_WKUPAON_WD_TIMER2_CLKCTRL_IDLEST_SHIFT                                  (16U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_IDLEST_MASK                                   (0x00030000U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_IDLEST_DISABLE                                 (3U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_IDLEST_IDLE                                    (2U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_IDLEST_FUNC                                    (0U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_IDLEST_TRANS                                   (1U)

#define CM_WKUPAON_WD_TIMER2_CLKCTRL_MODULEMODE_SHIFT                              (0U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_MODULEMODE_MASK                               (0x00000003U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_MODULEMODE_DISABLED                            (0U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_MODULEMODE_RESERVED_1                          (1U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_MODULEMODE_ENABLE                              (2U)
#define CM_WKUPAON_WD_TIMER2_CLKCTRL_MODULEMODE_RESERVED                            (3U)

#define CM_WKUPAON_GPIO1_CLKCTRL_IDLEST_SHIFT                                      (16U)
#define CM_WKUPAON_GPIO1_CLKCTRL_IDLEST_MASK                                       (0x00030000U)
#define CM_WKUPAON_GPIO1_CLKCTRL_IDLEST_DISABLE                                     (3U)
#define CM_WKUPAON_GPIO1_CLKCTRL_IDLEST_IDLE                                        (2U)
#define CM_WKUPAON_GPIO1_CLKCTRL_IDLEST_FUNC                                        (0U)
#define CM_WKUPAON_GPIO1_CLKCTRL_IDLEST_TRANS                                       (1U)

#define CM_WKUPAON_GPIO1_CLKCTRL_OPTFCLKEN_DBCLK_SHIFT                             (8U)
#define CM_WKUPAON_GPIO1_CLKCTRL_OPTFCLKEN_DBCLK_MASK                              (0x00000100U)
#define CM_WKUPAON_GPIO1_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_EN                            (1U)
#define CM_WKUPAON_GPIO1_CLKCTRL_OPTFCLKEN_DBCLK_FCLK_DIS                           (0U)

#define CM_WKUPAON_GPIO1_CLKCTRL_MODULEMODE_SHIFT                                  (0U)
#define CM_WKUPAON_GPIO1_CLKCTRL_MODULEMODE_MASK                                   (0x00000003U)
#define CM_WKUPAON_GPIO1_CLKCTRL_MODULEMODE_DISABLED                                (0U)
#define CM_WKUPAON_GPIO1_CLKCTRL_MODULEMODE_AUTO                                    (1U)
#define CM_WKUPAON_GPIO1_CLKCTRL_MODULEMODE_RESERVED_2                              (2U)
#define CM_WKUPAON_GPIO1_CLKCTRL_MODULEMODE_RESERVED                                (3U)

#define CM_WKUPAON_TIMER1_CLKCTRL_IDLEST_SHIFT                                     (16U)
#define CM_WKUPAON_TIMER1_CLKCTRL_IDLEST_MASK                                      (0x00030000U)
#define CM_WKUPAON_TIMER1_CLKCTRL_IDLEST_DISABLE                                    (3U)
#define CM_WKUPAON_TIMER1_CLKCTRL_IDLEST_IDLE                                       (2U)
#define CM_WKUPAON_TIMER1_CLKCTRL_IDLEST_FUNC                                       (0U)
#define CM_WKUPAON_TIMER1_CLKCTRL_IDLEST_TRANS                                      (1U)

#define CM_WKUPAON_TIMER1_CLKCTRL_MODULEMODE_SHIFT                                 (0U)
#define CM_WKUPAON_TIMER1_CLKCTRL_MODULEMODE_MASK                                  (0x00000003U)
#define CM_WKUPAON_TIMER1_CLKCTRL_MODULEMODE_DISABLED                               (0U)
#define CM_WKUPAON_TIMER1_CLKCTRL_MODULEMODE_RESERVED_1                             (1U)
#define CM_WKUPAON_TIMER1_CLKCTRL_MODULEMODE_ENABLE                                 (2U)
#define CM_WKUPAON_TIMER1_CLKCTRL_MODULEMODE_RESERVED                               (3U)

#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SHIFT                                     (24U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_MASK                                      (0x0f000000U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_TIMER_SYS_CLK                          (0U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK                       (1U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_SYS_CLK2                               (2U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_XREF_CLK0                              (3U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_XREF_CLK1                              (4U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_XREF_CLK2                              (5U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_XREF_CLK3                              (6U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_VIDEO1_CLK                             (8U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_VIDEO2_CLK                             (9U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_HDMI_CLK                               (10U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_RESERVED                                   (11U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_RESERVED1                                  (12U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_RESERVED2                                  (13U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_RESERVED3                                  (14U)
#define CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_RESERVED4                                  (15U)

#define CM_WKUPAON_TIMER12_CLKCTRL_IDLEST_SHIFT                                    (16U)
#define CM_WKUPAON_TIMER12_CLKCTRL_IDLEST_MASK                                     (0x00030000U)
#define CM_WKUPAON_TIMER12_CLKCTRL_IDLEST_DISABLE                                   (3U)
#define CM_WKUPAON_TIMER12_CLKCTRL_IDLEST_IDLE                                      (2U)
#define CM_WKUPAON_TIMER12_CLKCTRL_IDLEST_FUNC                                      (0U)
#define CM_WKUPAON_TIMER12_CLKCTRL_IDLEST_TRANS                                     (1U)

#define CM_WKUPAON_TIMER12_CLKCTRL_MODULEMODE_SHIFT                                (0U)
#define CM_WKUPAON_TIMER12_CLKCTRL_MODULEMODE_MASK                                 (0x00000003U)
#define CM_WKUPAON_TIMER12_CLKCTRL_MODULEMODE_AUTO                                  (1U)

#define CM_WKUPAON_COUNTER_32K_CLKCTRL_IDLEST_SHIFT                                (16U)
#define CM_WKUPAON_COUNTER_32K_CLKCTRL_IDLEST_MASK                                 (0x00030000U)
#define CM_WKUPAON_COUNTER_32K_CLKCTRL_IDLEST_DISABLE                               (3U)
#define CM_WKUPAON_COUNTER_32K_CLKCTRL_IDLEST_IDLE                                  (2U)
#define CM_WKUPAON_COUNTER_32K_CLKCTRL_IDLEST_FUNC                                  (0U)
#define CM_WKUPAON_COUNTER_32K_CLKCTRL_IDLEST_TRANS                                 (1U)

#define CM_WKUPAON_COUNTER_32K_CLKCTRL_MODULEMODE_SHIFT                            (0U)
#define CM_WKUPAON_COUNTER_32K_CLKCTRL_MODULEMODE_MASK                             (0x00000003U)
#define CM_WKUPAON_COUNTER_32K_CLKCTRL_MODULEMODE_AUTO                              (1U)

#define CM_WKUPAON_KBD_CLKCTRL_IDLEST_SHIFT                                        (16U)
#define CM_WKUPAON_KBD_CLKCTRL_IDLEST_MASK                                         (0x00030000U)
#define CM_WKUPAON_KBD_CLKCTRL_IDLEST_DISABLE                                       (3U)
#define CM_WKUPAON_KBD_CLKCTRL_IDLEST_IDLE                                          (2U)
#define CM_WKUPAON_KBD_CLKCTRL_IDLEST_FUNC                                          (0U)
#define CM_WKUPAON_KBD_CLKCTRL_IDLEST_TRANS                                         (1U)

#define CM_WKUPAON_KBD_CLKCTRL_MODULEMODE_SHIFT                                    (0U)
#define CM_WKUPAON_KBD_CLKCTRL_MODULEMODE_MASK                                     (0x00000003U)
#define CM_WKUPAON_KBD_CLKCTRL_MODULEMODE_DISABLED                                  (0U)
#define CM_WKUPAON_KBD_CLKCTRL_MODULEMODE_RESERVED_1                                (1U)
#define CM_WKUPAON_KBD_CLKCTRL_MODULEMODE_ENABLE                                    (2U)
#define CM_WKUPAON_KBD_CLKCTRL_MODULEMODE_RESERVED                                  (3U)

#define CM_WKUPAON_UART10_CLKCTRL_IDLEST_SHIFT                                     (16U)
#define CM_WKUPAON_UART10_CLKCTRL_IDLEST_MASK                                      (0x00030000U)
#define CM_WKUPAON_UART10_CLKCTRL_IDLEST_DISABLE                                    (3U)
#define CM_WKUPAON_UART10_CLKCTRL_IDLEST_IDLE                                       (2U)
#define CM_WKUPAON_UART10_CLKCTRL_IDLEST_FUNC                                       (0U)
#define CM_WKUPAON_UART10_CLKCTRL_IDLEST_TRANS                                      (1U)

#define CM_WKUPAON_UART10_CLKCTRL_MODULEMODE_SHIFT                                 (0U)
#define CM_WKUPAON_UART10_CLKCTRL_MODULEMODE_MASK                                  (0x00000003U)
#define CM_WKUPAON_UART10_CLKCTRL_MODULEMODE_DISABLED                               (0U)
#define CM_WKUPAON_UART10_CLKCTRL_MODULEMODE_RESERVED_1                             (1U)
#define CM_WKUPAON_UART10_CLKCTRL_MODULEMODE_ENABLE                                 (2U)
#define CM_WKUPAON_UART10_CLKCTRL_MODULEMODE_RESERVED                               (3U)

#define CM_WKUPAON_UART10_CLKCTRL_CLKSEL_SHIFT                                     (24U)
#define CM_WKUPAON_UART10_CLKCTRL_CLKSEL_MASK                                      (0x01000000U)
#define CM_WKUPAON_UART10_CLKCTRL_CLKSEL_SEL_FUNC_48M_CLK                           (0U)
#define CM_WKUPAON_UART10_CLKCTRL_CLKSEL_SEL_FUNC_192M_CLK                          (1U)

#define CM_WKUPAON_DCAN1_CLKCTRL_IDLEST_SHIFT                                      (16U)
#define CM_WKUPAON_DCAN1_CLKCTRL_IDLEST_MASK                                       (0x00030000U)
#define CM_WKUPAON_DCAN1_CLKCTRL_IDLEST_DISABLE                                     (3U)
#define CM_WKUPAON_DCAN1_CLKCTRL_IDLEST_IDLE                                        (2U)
#define CM_WKUPAON_DCAN1_CLKCTRL_IDLEST_FUNC                                        (0U)
#define CM_WKUPAON_DCAN1_CLKCTRL_IDLEST_TRANS                                       (1U)

#define CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE_SHIFT                                  (0U)
#define CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE_MASK                                   (0x00000003U)
#define CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE_DISABLED                                (0U)
#define CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE_RESERVED_1                              (1U)
#define CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE_ENABLE                                  (2U)
#define CM_WKUPAON_DCAN1_CLKCTRL_MODULEMODE_RESERVED                                (3U)

#define CM_WKUPAON_DCAN1_CLKCTRL_CLKSEL_SHIFT                                      (24U)
#define CM_WKUPAON_DCAN1_CLKCTRL_CLKSEL_MASK                                       (0x01000000U)
#define CM_WKUPAON_DCAN1_CLKCTRL_CLKSEL_SEL_SYS_CLK1                                (0U)
#define CM_WKUPAON_DCAN1_CLKCTRL_CLKSEL_SEL_SYS_CLK2                                (1U)

#define CM_WKUPAON_SCRM_CLKCTRL_OPTFCLKEN_SCRM_CORE_SHIFT                                                   (8U)
#define CM_WKUPAON_SCRM_CLKCTRL_OPTFCLKEN_SCRM_CORE_MASK                                                    (0x00000100U)
#define CM_WKUPAON_SCRM_CLKCTRL_OPTFCLKEN_SCRM_CORE_FCLK_EN                                                  (1U)
#define CM_WKUPAON_SCRM_CLKCTRL_OPTFCLKEN_SCRM_CORE_FCLK_DIS                                                 (0U)

#define CM_WKUPAON_SCRM_CLKCTRL_OPTFCLKEN_SCRM_PER_SHIFT                                (9U)
#define CM_WKUPAON_SCRM_CLKCTRL_OPTFCLKEN_SCRM_PER_MASK                                 (0x00000200U)
#define CM_WKUPAON_SCRM_CLKCTRL_OPTFCLKEN_SCRM_PER_FCLK_EN                               (1U)
#define CM_WKUPAON_SCRM_CLKCTRL_OPTFCLKEN_SCRM_PER_FCLK_DIS                              (0U)

#define CM_WKUPAON_IO_SRCOMP_CLKCTRL_CLKEN_FCLK_SHIFT                              (8U)
#define CM_WKUPAON_IO_SRCOMP_CLKCTRL_CLKEN_FCLK_MASK                               (0x00000100U)
#define CM_WKUPAON_IO_SRCOMP_CLKCTRL_CLKEN_FCLK_DIS                                 (0U)
#define CM_WKUPAON_IO_SRCOMP_CLKCTRL_CLKEN_FCLK_EN                                  (1U)

#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL_IDLEST_SHIFT                              (16U)
#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL_IDLEST_MASK                               (0x00030000U)
#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL_IDLEST_DISABLE                             (3U)
#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL_IDLEST_IDLE                                (2U)
#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL_IDLEST_FUNC                                (0U)
#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL_IDLEST_TRANS                               (1U)

#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL_MODULEMODE_SHIFT                          (0U)
#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL_MODULEMODE_MASK                           (0x00000003U)
#define CM_WKUPAON_SPARE_SAFETY1_CLKCTRL_MODULEMODE_AUTO                            (1U)

#define CM_WKUPAON_RTI1_CLKCTRL_IDLEST_SHIFT                                            (16U)
#define CM_WKUPAON_RTI1_CLKCTRL_IDLEST_MASK                                             (0x00030000U)
#define CM_WKUPAON_RTI1_CLKCTRL_IDLEST_DISABLE                                           (3U)
#define CM_WKUPAON_RTI1_CLKCTRL_IDLEST_IDLE                                              (2U)
#define CM_WKUPAON_RTI1_CLKCTRL_IDLEST_FUNC                                              (0U)
#define CM_WKUPAON_RTI1_CLKCTRL_IDLEST_TRANS                                             (1U)

#define CM_WKUPAON_RTI1_CLKCTRL_MODULEMODE_SHIFT                                        (0U)
#define CM_WKUPAON_RTI1_CLKCTRL_MODULEMODE_MASK                                         (0x00000003U)
#define CM_WKUPAON_RTI1_CLKCTRL_MODULEMODE_AUTO                                          (1U)

#define CM_WKUPAON_RTI2_CLKCTRL_IDLEST_SHIFT                                            (16U)
#define CM_WKUPAON_RTI2_CLKCTRL_IDLEST_MASK                                             (0x00030000U)
#define CM_WKUPAON_RTI2_CLKCTRL_IDLEST_DISABLE                                           (3U)
#define CM_WKUPAON_RTI2_CLKCTRL_IDLEST_IDLE                                              (2U)
#define CM_WKUPAON_RTI2_CLKCTRL_IDLEST_FUNC                                              (0U)
#define CM_WKUPAON_RTI2_CLKCTRL_IDLEST_TRANS                                             (1U)

#define CM_WKUPAON_RTI2_CLKCTRL_MODULEMODE_SHIFT                                        (0U)
#define CM_WKUPAON_RTI2_CLKCTRL_MODULEMODE_MASK                                         (0x00000003U)
#define CM_WKUPAON_RTI2_CLKCTRL_MODULEMODE_AUTO                                          (1U)

#define CM_WKUPAON_RTI3_CLKCTRL_IDLEST_SHIFT                                            (16U)
#define CM_WKUPAON_RTI3_CLKCTRL_IDLEST_MASK                                             (0x00030000U)
#define CM_WKUPAON_RTI3_CLKCTRL_IDLEST_DISABLE                                           (3U)
#define CM_WKUPAON_RTI3_CLKCTRL_IDLEST_IDLE                                              (2U)
#define CM_WKUPAON_RTI3_CLKCTRL_IDLEST_FUNC                                              (0U)
#define CM_WKUPAON_RTI3_CLKCTRL_IDLEST_TRANS                                             (1U)

#define CM_WKUPAON_RTI3_CLKCTRL_MODULEMODE_SHIFT                                        (0U)
#define CM_WKUPAON_RTI3_CLKCTRL_MODULEMODE_MASK                                         (0x00000003U)
#define CM_WKUPAON_RTI3_CLKCTRL_MODULEMODE_AUTO                                          (1U)

#define CM_WKUPAON_RTI4_CLKCTRL_IDLEST_SHIFT                                            (16U)
#define CM_WKUPAON_RTI4_CLKCTRL_IDLEST_MASK                                             (0x00030000U)
#define CM_WKUPAON_RTI4_CLKCTRL_IDLEST_DISABLE                                           (3U)
#define CM_WKUPAON_RTI4_CLKCTRL_IDLEST_IDLE                                              (2U)
#define CM_WKUPAON_RTI4_CLKCTRL_IDLEST_FUNC                                              (0U)
#define CM_WKUPAON_RTI4_CLKCTRL_IDLEST_TRANS                                             (1U)

#define CM_WKUPAON_RTI4_CLKCTRL_MODULEMODE_SHIFT                                        (0U)
#define CM_WKUPAON_RTI4_CLKCTRL_MODULEMODE_MASK                                         (0x00000003U)
#define CM_WKUPAON_RTI4_CLKCTRL_MODULEMODE_AUTO                                          (1U)

#define CM_WKUPAON_RTI5_CLKCTRL_IDLEST_SHIFT                                            (16U)
#define CM_WKUPAON_RTI5_CLKCTRL_IDLEST_MASK                                             (0x00030000U)
#define CM_WKUPAON_RTI5_CLKCTRL_IDLEST_DISABLE                                           (3U)
#define CM_WKUPAON_RTI5_CLKCTRL_IDLEST_IDLE                                              (2U)
#define CM_WKUPAON_RTI5_CLKCTRL_IDLEST_FUNC                                              (0U)
#define CM_WKUPAON_RTI5_CLKCTRL_IDLEST_TRANS                                             (1U)

#define CM_WKUPAON_RTI5_CLKCTRL_MODULEMODE_SHIFT                                        (0U)
#define CM_WKUPAON_RTI5_CLKCTRL_MODULEMODE_MASK                                         (0x00000003U)
#define CM_WKUPAON_RTI5_CLKCTRL_MODULEMODE_AUTO                                          (1U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_WKUPAON_CM_H_ */

