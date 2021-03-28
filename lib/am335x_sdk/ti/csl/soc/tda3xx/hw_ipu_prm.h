/*
* hw_ipu_prm.h
*
* Register-level header file for PRCM
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

#ifndef HW_IPU_PRM_H_
#define HW_IPU_PRM_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define PM_IPU_PWRSTCTRL                                       (0x0U)
#define PM_IPU_PWRSTST                                         (0x4U)
#define RM_IPU1_RSTCTRL                                        (0x10U)
#define RM_IPU1_RSTST                                          (0x14U)
#define RM_IPU1_IPU1_CONTEXT                                                                                (0x24U)
#define PM_IPU_MCASP1_WKDEP                                         (0x50U)
#define RM_IPU_MCASP1_CONTEXT                                  (0x54U)
#define PM_IPU_TIMER5_WKDEP                                         (0x58U)
#define RM_IPU_TIMER5_CONTEXT                                  (0x5cU)
#define PM_IPU_TIMER6_WKDEP                                         (0x60U)
#define RM_IPU_TIMER6_CONTEXT                                  (0x64U)
#define PM_IPU_TIMER7_WKDEP                                         (0x68U)
#define RM_IPU_TIMER7_CONTEXT                                  (0x6cU)
#define PM_IPU_TIMER8_WKDEP                                         (0x70U)
#define RM_IPU_TIMER8_CONTEXT                                  (0x74U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define PM_IPU_PWRSTCTRL_AESSMEM_RETSTATE_SHIFT                                    (8U)
#define PM_IPU_PWRSTCTRL_AESSMEM_RETSTATE_MASK                                     (0x00000100U)
#define PM_IPU_PWRSTCTRL_AESSMEM_RETSTATE_MEM_RET                                   (1U)
#define PM_IPU_PWRSTCTRL_AESSMEM_RETSTATE_MEM_OFF                                   (0U)

#define PM_IPU_PWRSTCTRL_AESSMEM_ONSTATE_SHIFT                                     (16U)
#define PM_IPU_PWRSTCTRL_AESSMEM_ONSTATE_MASK                                      (0x00030000U)
#define PM_IPU_PWRSTCTRL_AESSMEM_ONSTATE_MEM_ON                                     (3U)

#define PM_IPU_PWRSTCTRL_LOGICRETSTATE_SHIFT                                       (2U)
#define PM_IPU_PWRSTCTRL_LOGICRETSTATE_MASK                                        (0x00000004U)
#define PM_IPU_PWRSTCTRL_LOGICRETSTATE_LOGIC_OFF                                    (0U)

#define PM_IPU_PWRSTCTRL_POWERSTATE_SHIFT                                          (0U)
#define PM_IPU_PWRSTCTRL_POWERSTATE_MASK                                           (0x00000003U)
#define PM_IPU_PWRSTCTRL_POWERSTATE_OFF                                             (0U)
#define PM_IPU_PWRSTCTRL_POWERSTATE_INACT                                           (2U)
#define PM_IPU_PWRSTCTRL_POWERSTATE_RET                                             (1U)
#define PM_IPU_PWRSTCTRL_POWERSTATE_ON                                              (3U)

#define PM_IPU_PWRSTCTRL_PERIPHMEM_RETSTATE_SHIFT                                  (10U)
#define PM_IPU_PWRSTCTRL_PERIPHMEM_RETSTATE_MASK                                   (0x00000400U)
#define PM_IPU_PWRSTCTRL_PERIPHMEM_RETSTATE_MEM_OFF                                 (0U)
#define PM_IPU_PWRSTCTRL_PERIPHMEM_RETSTATE_MEM_RET                                 (1U)

#define PM_IPU_PWRSTCTRL_PERIPHMEM_ONSTATE_SHIFT                                   (20U)
#define PM_IPU_PWRSTCTRL_PERIPHMEM_ONSTATE_MASK                                    (0x00300000U)
#define PM_IPU_PWRSTCTRL_PERIPHMEM_ONSTATE_MEM_ON                                   (3U)

#define PM_IPU_PWRSTCTRL_LOWPOWERSTATECHANGE_SHIFT                                 (4U)
#define PM_IPU_PWRSTCTRL_LOWPOWERSTATECHANGE_MASK                                  (0x00000010U)
#define PM_IPU_PWRSTCTRL_LOWPOWERSTATECHANGE_EN                                     (1U)
#define PM_IPU_PWRSTCTRL_LOWPOWERSTATECHANGE_DIS                                    (0U)

#define PM_IPU_PWRSTST_POWERSTATEST_SHIFT                                          (0U)
#define PM_IPU_PWRSTST_POWERSTATEST_MASK                                           (0x00000003U)
#define PM_IPU_PWRSTST_POWERSTATEST_ON                                              (3U)
#define PM_IPU_PWRSTST_POWERSTATEST_OFF                                             (0U)
#define PM_IPU_PWRSTST_POWERSTATEST_RET                                             (1U)
#define PM_IPU_PWRSTST_POWERSTATEST_INACTIVE                                        (2U)

#define PM_IPU_PWRSTST_INTRANSITION_SHIFT                                          (20U)
#define PM_IPU_PWRSTST_INTRANSITION_MASK                                           (0x00100000U)
#define PM_IPU_PWRSTST_INTRANSITION_NO                                              (0U)
#define PM_IPU_PWRSTST_INTRANSITION_ONGOING                                         (1U)

#define PM_IPU_PWRSTST_LOGICSTATEST_SHIFT                                          (2U)
#define PM_IPU_PWRSTST_LOGICSTATEST_MASK                                           (0x00000004U)
#define PM_IPU_PWRSTST_LOGICSTATEST_ON                                              (1U)
#define PM_IPU_PWRSTST_LOGICSTATEST_OFF                                             (0U)

#define PM_IPU_PWRSTST_AESSMEM_STATEST_SHIFT                                       (4U)
#define PM_IPU_PWRSTST_AESSMEM_STATEST_MASK                                        (0x00000030U)
#define PM_IPU_PWRSTST_AESSMEM_STATEST_MEM_ON                                       (3U)
#define PM_IPU_PWRSTST_AESSMEM_STATEST_MEM_RET                                      (1U)
#define PM_IPU_PWRSTST_AESSMEM_STATEST_MEM_OFF                                      (0U)
#define PM_IPU_PWRSTST_AESSMEM_STATEST_RESERVED                                     (2U)

#define PM_IPU_PWRSTST_PERIPHMEM_STATEST_SHIFT                                     (8U)
#define PM_IPU_PWRSTST_PERIPHMEM_STATEST_MASK                                      (0x00000300U)
#define PM_IPU_PWRSTST_PERIPHMEM_STATEST_MEM_ON                                     (3U)
#define PM_IPU_PWRSTST_PERIPHMEM_STATEST_RESERVED1                                  (1U)
#define PM_IPU_PWRSTST_PERIPHMEM_STATEST_MEM_OFF                                    (0U)
#define PM_IPU_PWRSTST_PERIPHMEM_STATEST_RESERVED                                   (2U)

#define PM_IPU_PWRSTST_LASTPOWERSTATEENTERED_SHIFT                                 (24U)
#define PM_IPU_PWRSTST_LASTPOWERSTATEENTERED_MASK                                  (0x03000000U)
#define PM_IPU_PWRSTST_LASTPOWERSTATEENTERED_ON                                     (3U)
#define PM_IPU_PWRSTST_LASTPOWERSTATEENTERED_OFF                                    (0U)
#define PM_IPU_PWRSTST_LASTPOWERSTATEENTERED_RET                                    (1U)
#define PM_IPU_PWRSTST_LASTPOWERSTATEENTERED_INACTIVE                               (2U)

#define RM_IPU1_RSTCTRL_RST_CPU0_SHIFT                                             (0U)
#define RM_IPU1_RSTCTRL_RST_CPU0_MASK                                              (0x00000001U)
#define RM_IPU1_RSTCTRL_RST_CPU0_ASSERT                                             (1U)
#define RM_IPU1_RSTCTRL_RST_CPU0_CLEAR                                              (0U)

#define RM_IPU1_RSTCTRL_RST_CPU1_SHIFT                                             (1U)
#define RM_IPU1_RSTCTRL_RST_CPU1_MASK                                              (0x00000002U)
#define RM_IPU1_RSTCTRL_RST_CPU1_ASSERT                                             (1U)
#define RM_IPU1_RSTCTRL_RST_CPU1_CLEAR                                              (0U)

#define RM_IPU1_RSTCTRL_RST_IPU_SHIFT                                              (2U)
#define RM_IPU1_RSTCTRL_RST_IPU_MASK                                               (0x00000004U)
#define RM_IPU1_RSTCTRL_RST_IPU_ASSERT                                              (1U)
#define RM_IPU1_RSTCTRL_RST_IPU_CLEAR                                               (0U)

#define RM_IPU1_RSTST_RST_EMULATION_CPU0_SHIFT                                     (3U)
#define RM_IPU1_RSTST_RST_EMULATION_CPU0_MASK                                      (0x00000008U)
#define RM_IPU1_RSTST_RST_EMULATION_CPU0_RESET_YES                                  (1U)
#define RM_IPU1_RSTST_RST_EMULATION_CPU0_RESET_NO                                   (0U)

#define RM_IPU1_RSTST_RST_EMULATION_CPU1_SHIFT                                     (4U)
#define RM_IPU1_RSTST_RST_EMULATION_CPU1_MASK                                      (0x00000010U)
#define RM_IPU1_RSTST_RST_EMULATION_CPU1_RESET_YES                                  (1U)
#define RM_IPU1_RSTST_RST_EMULATION_CPU1_RESET_NO                                   (0U)

#define RM_IPU1_RSTST_RST_CPU0_SHIFT                                               (0U)
#define RM_IPU1_RSTST_RST_CPU0_MASK                                                (0x00000001U)
#define RM_IPU1_RSTST_RST_CPU0_RESET_YES                                            (1U)
#define RM_IPU1_RSTST_RST_CPU0_RESET_NO                                             (0U)

#define RM_IPU1_RSTST_RST_CPU1_SHIFT                                               (1U)
#define RM_IPU1_RSTST_RST_CPU1_MASK                                                (0x00000002U)
#define RM_IPU1_RSTST_RST_CPU1_RESET_YES                                            (1U)
#define RM_IPU1_RSTST_RST_CPU1_RESET_NO                                             (0U)

#define RM_IPU1_RSTST_RST_IPU_SHIFT                                                (2U)
#define RM_IPU1_RSTST_RST_IPU_MASK                                                 (0x00000004U)
#define RM_IPU1_RSTST_RST_IPU_RESET_YES                                             (1U)
#define RM_IPU1_RSTST_RST_IPU_RESET_NO                                              (0U)

#define RM_IPU1_RSTST_RST_ICECRUSHER_CPU0_SHIFT                                    (5U)
#define RM_IPU1_RSTST_RST_ICECRUSHER_CPU0_MASK                                     (0x00000020U)
#define RM_IPU1_RSTST_RST_ICECRUSHER_CPU0_RESET_YES                                 (1U)
#define RM_IPU1_RSTST_RST_ICECRUSHER_CPU0_RESET_NO                                  (0U)

#define RM_IPU1_RSTST_RST_ICECRUSHER_CPU1_SHIFT                                    (6U)
#define RM_IPU1_RSTST_RST_ICECRUSHER_CPU1_MASK                                     (0x00000040U)
#define RM_IPU1_RSTST_RST_ICECRUSHER_CPU1_RESET_YES                                 (1U)
#define RM_IPU1_RSTST_RST_ICECRUSHER_CPU1_RESET_NO                                  (0U)

#define RM_IPU1_IPU1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                                          (0U)
#define RM_IPU1_IPU1_CONTEXT_LOSTCONTEXT_DFF_MASK                                                           (0x00000001U)
#define RM_IPU1_IPU1_CONTEXT_LOSTCONTEXT_DFF_LOST                                                            (1U)
#define RM_IPU1_IPU1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                                                      (0U)

#define RM_IPU1_IPU1_CONTEXT_LOSTCONTEXT_RFF_SHIFT                                                          (1U)
#define RM_IPU1_IPU1_CONTEXT_LOSTCONTEXT_RFF_MASK                                                           (0x00000002U)
#define RM_IPU1_IPU1_CONTEXT_LOSTCONTEXT_RFF_LOST                                                            (1U)
#define RM_IPU1_IPU1_CONTEXT_LOSTCONTEXT_RFF_MAINTAINED                                                      (0U)

#define RM_IPU1_IPU1_CONTEXT_LOSTMEM_IPU_UNICACHE_SHIFT                                                     (8U)
#define RM_IPU1_IPU1_CONTEXT_LOSTMEM_IPU_UNICACHE_MASK                                                      (0x00000100U)
#define RM_IPU1_IPU1_CONTEXT_LOSTMEM_IPU_UNICACHE_LOST                                                       (1U)
#define RM_IPU1_IPU1_CONTEXT_LOSTMEM_IPU_UNICACHE_MAINTAINED                                                 (0U)

#define RM_IPU1_IPU1_CONTEXT_LOSTMEM_IPU_L2RAM_SHIFT                                                        (9U)
#define RM_IPU1_IPU1_CONTEXT_LOSTMEM_IPU_L2RAM_MASK                                                         (0x00000200U)
#define RM_IPU1_IPU1_CONTEXT_LOSTMEM_IPU_L2RAM_LOST                                                          (1U)
#define RM_IPU1_IPU1_CONTEXT_LOSTMEM_IPU_L2RAM_MAINTAINED                                                    (0U)

#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_DSP1_SHIFT                                                   (2U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_DSP1_MASK                                                    (0x00000004U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_DSP1_ENABLED                                                  (1U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_DSP1_DISABLED                                                 (0U)

#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_IPU1_SHIFT                                                   (4U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_IPU1_MASK                                                    (0x00000010U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_IPU1_ENABLED                                                  (1U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_IPU1_DISABLED                                                 (0U)

#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_DSP2_SHIFT                                                   (5U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_DSP2_MASK                                                    (0x00000020U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_DSP2_ENABLED                                                  (1U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_DSP2_DISABLED                                                 (0U)

#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_EVE1_SHIFT                                                   (6U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_EVE1_MASK                                                    (0x00000040U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_EVE1_ENABLED                                                  (1U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_IRQ_EVE1_DISABLED                                                 (0U)

#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_SDMA_SHIFT                                                   (13U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_SDMA_MASK                                                    (0x00002000U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_SDMA_ENABLED                                                  (1U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_SDMA_DISABLED                                                 (0U)

#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_DSP1_SHIFT                                                   (12U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_DSP1_MASK                                                    (0x00001000U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_DSP1_ENABLED                                                  (1U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_DSP1_DISABLED                                                 (0U)

#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_DSP2_SHIFT                                                   (15U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_DSP2_MASK                                                    (0x00008000U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_DSP2_ENABLED                                                  (1U)
#define PM_IPU_MCASP1_WKDEP_WKUPDEP_MCASP1_DMA_DSP2_DISABLED                                                 (0U)

#define RM_IPU_MCASP1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define RM_IPU_MCASP1_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define RM_IPU_MCASP1_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define RM_IPU_MCASP1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_DSP1_SHIFT                                                       (2U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_DSP1_MASK                                                        (0x00000004U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_DSP1_ENABLED                                                      (1U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_DSP1_DISABLED                                                     (0U)

#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_IPU1_SHIFT                                                       (4U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_IPU1_MASK                                                        (0x00000010U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_IPU1_ENABLED                                                      (1U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_IPU1_DISABLED                                                     (0U)

#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_DSP2_SHIFT                                                       (5U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_DSP2_MASK                                                        (0x00000020U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_DSP2_ENABLED                                                      (1U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_DSP2_DISABLED                                                     (0U)

#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_EVE1_SHIFT                                                       (6U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_EVE1_MASK                                                        (0x00000040U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_EVE1_ENABLED                                                      (1U)
#define PM_IPU_TIMER5_WKDEP_WKUPDEP_TIMER5_EVE1_DISABLED                                                     (0U)

#define RM_IPU_TIMER5_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define RM_IPU_TIMER5_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define RM_IPU_TIMER5_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define RM_IPU_TIMER5_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_DSP1_SHIFT                                                       (2U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_DSP1_MASK                                                        (0x00000004U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_DSP1_ENABLED                                                      (1U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_DSP1_DISABLED                                                     (0U)

#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_IPU1_SHIFT                                                       (4U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_IPU1_MASK                                                        (0x00000010U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_IPU1_ENABLED                                                      (1U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_IPU1_DISABLED                                                     (0U)

#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_DSP2_SHIFT                                                       (5U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_DSP2_MASK                                                        (0x00000020U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_DSP2_ENABLED                                                      (1U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_DSP2_DISABLED                                                     (0U)

#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_EVE1_SHIFT                                                       (6U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_EVE1_MASK                                                        (0x00000040U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_EVE1_ENABLED                                                      (1U)
#define PM_IPU_TIMER6_WKDEP_WKUPDEP_TIMER6_EVE1_DISABLED                                                     (0U)

#define RM_IPU_TIMER6_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define RM_IPU_TIMER6_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define RM_IPU_TIMER6_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define RM_IPU_TIMER6_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_DSP1_SHIFT                                                       (2U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_DSP1_MASK                                                        (0x00000004U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_DSP1_ENABLED                                                      (1U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_DSP1_DISABLED                                                     (0U)

#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_IPU1_SHIFT                                                       (4U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_IPU1_MASK                                                        (0x00000010U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_IPU1_ENABLED                                                      (1U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_IPU1_DISABLED                                                     (0U)

#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_DSP2_SHIFT                                                       (5U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_DSP2_MASK                                                        (0x00000020U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_DSP2_ENABLED                                                      (1U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_DSP2_DISABLED                                                     (0U)

#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_EVE1_SHIFT                                                       (6U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_EVE1_MASK                                                        (0x00000040U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_EVE1_ENABLED                                                      (1U)
#define PM_IPU_TIMER7_WKDEP_WKUPDEP_TIMER7_EVE1_DISABLED                                                     (0U)

#define RM_IPU_TIMER7_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define RM_IPU_TIMER7_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define RM_IPU_TIMER7_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define RM_IPU_TIMER7_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_DSP1_SHIFT                                                       (2U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_DSP1_MASK                                                        (0x00000004U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_DSP1_ENABLED                                                      (1U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_DSP1_DISABLED                                                     (0U)

#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_IPU1_SHIFT                                                       (4U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_IPU1_MASK                                                        (0x00000010U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_IPU1_ENABLED                                                      (1U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_IPU1_DISABLED                                                     (0U)

#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_DSP2_SHIFT                                                       (5U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_DSP2_MASK                                                        (0x00000020U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_DSP2_ENABLED                                                      (1U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_DSP2_DISABLED                                                     (0U)

#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_EVE1_SHIFT                                                       (6U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_EVE1_MASK                                                        (0x00000040U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_EVE1_ENABLED                                                      (1U)
#define PM_IPU_TIMER8_WKDEP_WKUPDEP_TIMER8_EVE1_DISABLED                                                     (0U)

#define RM_IPU_TIMER8_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define RM_IPU_TIMER8_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define RM_IPU_TIMER8_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define RM_IPU_TIMER8_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_IPU_PRM_H_ */

