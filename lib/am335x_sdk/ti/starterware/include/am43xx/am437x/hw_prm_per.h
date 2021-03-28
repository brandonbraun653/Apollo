/*
* hw_prm_per.h
*
* Register-level header file for PRM_PER
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

#ifndef HW_PRM_PER_H_
#define HW_PRM_PER_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/

#define PRCM_PM_PER_PWRSTCTRL                                       (0x0U)
#define PRCM_PM_PER_PWRSTST                                         (0x4U)
#define PRCM_RM_PER_RSTCTRL                                         (0x10U)
#define PRCM_RM_PER_RSTST                                           (0x14U)
#define PRCM_RM_PER_L3_CONTEXT                                      (0x24U)
#define PRCM_RM_PER_AES0_CONTEXT                                    (0x2cU)
#define PRCM_RM_PER_DES_CONTEXT                                     (0x34U)
#define PRCM_RM_PER_CRYPTODMA_CONTEXT                               (0x3cU)
#define PRCM_RM_PER_L3_INSTR_CONTEXT                                (0x44U)
#define PRCM_RM_PER_MSTR_EXPS_CONTEXT                               (0x4cU)
#define PRCM_RM_PER_OCMCRAM_CONTEXT                                 (0x54U)
#define PRCM_RM_PER_SHA0_CONTEXT                                    (0x5cU)
#define PRCM_RM_PER_SLV_EXPS_CONTEXT                                (0x64U)
#define PRCM_RM_PER_VPFE0_CONTEXT                                   (0x6cU)
#define PRCM_RM_PER_VPFE1_CONTEXT                                   (0x74U)
#define PRCM_RM_PER_TPCC_CONTEXT                                    (0x7cU)
#define PRCM_RM_PER_TPTC0_CONTEXT                                   (0x84U)
#define PRCM_RM_PER_TPTC1_CONTEXT                                   (0x8cU)
#define PRCM_RM_PER_TPTC2_CONTEXT                                   (0x94U)
#define PRCM_RM_PER_DLL_AGING_CONTEXT                               (0x9cU)
#define PRCM_RM_PER_L4HS_CONTEXT                                    (0xa4U)
#define PRCM_RM_PER_L4FW_CONTEXT                                    (0xacU)
#define PRCM_RM_PER_GPMC_CONTEXT                                    (0x224U)
#define PRCM_RM_PER_IEEE5000_CONTEXT                                (0x22cU)
#define PRCM_RM_PER_MAG_CARD_CONTEXT                                (0x234U)
#define PRCM_RM_PER_MCASP0_CONTEXT                                  (0x23cU)
#define PRCM_RM_PER_MCASP1_CONTEXT                                  (0x244U)
#define PRCM_RM_PER_MMC2_CONTEXT                                    (0x24cU)
#define PRCM_RM_PER_QSPI_CONTEXT                                    (0x25cU)
#define PRCM_RM_PER_USB_OTG_SS0_CONTEXT                             (0x264U)
#define PRCM_RM_PER_USB_OTG_SS1_CONTEXT                             (0x26cU)
#define PRCM_RM_PER_ICSS_CONTEXT                                    (0x324U)
#define PRCM_RM_PER_L4LS_CONTEXT                                    (0x424U)
#define PRCM_RM_PER_DCAN0_CONTEXT                                   (0x42cU)
#define PRCM_RM_PER_DCAN1_CONTEXT                                   (0x434U)
#define PRCM_RM_PER_EPWMSS0_CONTEXT                                 (0x43cU)
#define PRCM_RM_PER_EPWMSS1_CONTEXT                                 (0x444U)
#define PRCM_RM_PER_EPWMSS2_CONTEXT                                 (0x44cU)
#define PRCM_RM_PER_EPWMSS3_CONTEXT                                 (0x454U)
#define PRCM_RM_PER_EPWMSS4_CONTEXT                                 (0x45cU)
#define PRCM_RM_PER_EPWMSS5_CONTEXT                                 (0x464U)
#define PRCM_RM_PER_ELM_CONTEXT                                     (0x46cU)
#define PRCM_RM_PER_ERMC_CONTEXT                                    (0x474U)
#define PRCM_RM_PER_GPIO1_CONTEXT                                   (0x47cU)
#define PRCM_RM_PER_GPIO2_CONTEXT                                   (0x484U)
#define PRCM_RM_PER_GPIO3_CONTEXT                                   (0x48cU)
#define PRCM_RM_PER_GPIO4_CONTEXT                                   (0x494U)
#define PRCM_RM_PER_GPIO5_CONTEXT                                   (0x49cU)
#define PRCM_RM_PER_HDQ1W_CONTEXT                                   (0x4a4U)
#define PRCM_RM_PER_I2C1_CONTEXT                                    (0x4acU)
#define PRCM_RM_PER_I2C2_CONTEXT                                    (0x4b4U)
#define PRCM_RM_PER_MAILBOX0_CONTEXT                                (0x4bcU)
#define PRCM_RM_PER_MMC0_CONTEXT                                    (0x4c4U)
#define PRCM_RM_PER_MMC1_CONTEXT                                    (0x4ccU)
#define PRCM_RM_PER_PKA_CONTEXT                                     (0x4d4U)
#define PRCM_RM_PER_RNG_CONTEXT                                     (0x4e4U)
#define PRCM_RM_PER_SPARE0_CONTEXT                                  (0x4ecU)
#define PRCM_RM_PER_SPARE1_CONTEXT                                  (0x4f4U)
#define PRCM_RM_PER_SPI0_CONTEXT                                    (0x504U)
#define PRCM_RM_PER_SPI1_CONTEXT                                    (0x50cU)
#define PRCM_RM_PER_SPI2_CONTEXT                                    (0x514U)
#define PRCM_RM_PER_SPI3_CONTEXT                                    (0x51cU)
#define PRCM_RM_PER_SPI4_CONTEXT                                    (0x524U)
#define PRCM_RM_PER_SPINLOCK_CONTEXT                                (0x52cU)
#define PRCM_RM_PER_TIMER2_CONTEXT                                  (0x534U)
#define PRCM_RM_PER_TIMER3_CONTEXT                                  (0x53cU)
#define PRCM_RM_PER_TIMER4_CONTEXT                                  (0x544U)
#define PRCM_RM_PER_TIMER5_CONTEXT                                  (0x54cU)
#define PRCM_RM_PER_TIMER6_CONTEXT                                  (0x554U)
#define PRCM_RM_PER_TIMER7_CONTEXT                                  (0x55cU)
#define PRCM_RM_PER_TIMER8_CONTEXT                                  (0x564U)
#define PRCM_RM_PER_TIMER9_CONTEXT                                  (0x56cU)
#define PRCM_RM_PER_TIMER10_CONTEXT                                 (0x574U)
#define PRCM_RM_PER_TIMER11_CONTEXT                                 (0x57cU)
#define PRCM_RM_PER_UART1_CONTEXT                                   (0x584U)
#define PRCM_RM_PER_UART2_CONTEXT                                   (0x58cU)
#define PRCM_RM_PER_UART3_CONTEXT                                   (0x594U)
#define PRCM_RM_PER_UART4_CONTEXT                                   (0x59cU)
#define PRCM_RM_PER_UART5_CONTEXT                                   (0x5a4U)
#define PRCM_RM_PER_USIM0_CONTEXT                                   (0x5acU)
#define PRCM_RM_PER_USIM1_CONTEXT                                   (0x5b4U)
#define PRCM_RM_PER_USBPHYOCP2SCP0_CONTEXT                          (0x5bcU)
#define PRCM_RM_PER_USBPHYOCP2SCP1_CONTEXT                          (0x5c4U)
#define PRCM_RM_PER_EMIF_CONTEXT                                    (0x724U)
#define PRCM_RM_PER_DLL_CONTEXT                                     (0x72cU)
#define PRCM_RM_PER_EMIF_FW_CONTEXT                                 (0x734U)
#define PRCM_RM_PER_OTFA_EMIF_CONTEXT                               (0x73cU)
#define PRCM_RM_PER_LCDC_CONTEXT                                    (0x824U)
#define PRCM_RM_PER_DSS_CONTEXT                                     (0xa24U)
#define PRCM_RM_PER_CPGMAC0_CONTEXT                                 (0xb24U)
#define PRCM_RM_PER_OCPWP_CONTEXT                                   (0xc24U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define PRCM_PM_PER_PWRSTCTRL_POWERSTATE_SHIFT                                          (0U)
#define PRCM_PM_PER_PWRSTCTRL_POWERSTATE_MASK                                           (0x00000003U)
#define PRCM_PM_PER_PWRSTCTRL_POWERSTATE_ON                                              (3U)
#define PRCM_PM_PER_PWRSTCTRL_POWERSTATE_OFF                                             (0U)
#define PRCM_PM_PER_PWRSTCTRL_POWERSTATE_RET                                             (1U)
#define PRCM_PM_PER_PWRSTCTRL_POWERSTATE_RESERVED1                                       (2U)

#define PRCM_PM_PER_PWRSTCTRL_MEM_ONSTATE_SHIFT                                         (18U)
#define PRCM_PM_PER_PWRSTCTRL_MEM_ONSTATE_MASK                                          (0x000c0000U)
#define PRCM_PM_PER_PWRSTCTRL_MEM_ONSTATE_ON                                             (3U)

#define PRCM_PM_PER_PWRSTCTRL_RAM1_MEM_RETSTATE_SHIFT                                   (10U)
#define PRCM_PM_PER_PWRSTCTRL_RAM1_MEM_RETSTATE_MASK                                    (0x00000400U)
#define PRCM_PM_PER_PWRSTCTRL_RAM1_MEM_RETSTATE_OFF                                      (0U)
#define PRCM_PM_PER_PWRSTCTRL_RAM1_MEM_RETSTATE_RET                                      (1U)

#define PRCM_PM_PER_PWRSTCTRL_MEM_RETSTATE_SHIFT                                        (9U)
#define PRCM_PM_PER_PWRSTCTRL_MEM_RETSTATE_MASK                                         (0x00000200U)
#define PRCM_PM_PER_PWRSTCTRL_MEM_RETSTATE_OFF                                           (0U)
#define PRCM_PM_PER_PWRSTCTRL_MEM_RETSTATE_RET                                           (1U)

#define PRCM_PM_PER_PWRSTCTRL_RAM1_MEM_ONSTATE_SHIFT                                    (20U)
#define PRCM_PM_PER_PWRSTCTRL_RAM1_MEM_ONSTATE_MASK                                     (0x00300000U)
#define PRCM_PM_PER_PWRSTCTRL_RAM1_MEM_ONSTATE_ON                                        (3U)

#define PRCM_PM_PER_PWRSTCTRL_LOWPOWERSTATECHANGE_SHIFT                                 (4U)
#define PRCM_PM_PER_PWRSTCTRL_LOWPOWERSTATECHANGE_MASK                                  (0x00000010U)
#define PRCM_PM_PER_PWRSTCTRL_LOWPOWERSTATECHANGE_EN                                     (1U)
#define PRCM_PM_PER_PWRSTCTRL_LOWPOWERSTATECHANGE_DIS                                    (0U)

#define PRCM_PM_PER_PWRSTCTRL_LOGICRETSTATE_SHIFT                                       (2U)
#define PRCM_PM_PER_PWRSTCTRL_LOGICRETSTATE_MASK                                        (0x00000004U)
#define PRCM_PM_PER_PWRSTCTRL_LOGICRETSTATE_LOGIC_RET                                    (1U)
#define PRCM_PM_PER_PWRSTCTRL_LOGICRETSTATE_LOGIC_OFF                                    (0U)

#define PRCM_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_SHIFT                                    (16U)
#define PRCM_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_MASK                                     (0x00030000U)
#define PRCM_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_ON                                        (3U)

#define PRCM_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_SHIFT                                   (8U)
#define PRCM_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_MASK                                    (0x00000100U)
#define PRCM_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_OFF                                      (0U)
#define PRCM_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_RET                                      (1U)

#define PRCM_PM_PER_PWRSTCTRL_RAM2_MEM_RETSTATE_SHIFT                                   (11U)
#define PRCM_PM_PER_PWRSTCTRL_RAM2_MEM_RETSTATE_MASK                                    (0x00000800U)
#define PRCM_PM_PER_PWRSTCTRL_RAM2_MEM_RETSTATE_OFF                                      (0U)
#define PRCM_PM_PER_PWRSTCTRL_RAM2_MEM_RETSTATE_RET                                      (1U)

#define PRCM_PM_PER_PWRSTCTRL_RAM2_MEM_ONSTATE_SHIFT                                    (22U)
#define PRCM_PM_PER_PWRSTCTRL_RAM2_MEM_ONSTATE_MASK                                     (0x00c00000U)
#define PRCM_PM_PER_PWRSTCTRL_RAM2_MEM_ONSTATE_ON                                        (3U)

#define PRCM_PM_PER_PWRSTST_POWERSTATEST_SHIFT                                          (0U)
#define PRCM_PM_PER_PWRSTST_POWERSTATEST_MASK                                           (0x00000003U)
#define PRCM_PM_PER_PWRSTST_POWERSTATEST_OFF                                             (0U)
#define PRCM_PM_PER_PWRSTST_POWERSTATEST_ON                                              (3U)
#define PRCM_PM_PER_PWRSTST_POWERSTATEST_RET                                             (1U)

#define PRCM_PM_PER_PWRSTST_INTRANSITION_SHIFT                                          (20U)
#define PRCM_PM_PER_PWRSTST_INTRANSITION_MASK                                           (0x00100000U)
#define PRCM_PM_PER_PWRSTST_INTRANSITION_NO                                              (0U)
#define PRCM_PM_PER_PWRSTST_INTRANSITION_ONGOING                                         (1U)

#define PRCM_PM_PER_PWRSTST_LOGICSTATEST_SHIFT                                          (2U)
#define PRCM_PM_PER_PWRSTST_LOGICSTATEST_MASK                                           (0x00000004U)
#define PRCM_PM_PER_PWRSTST_LOGICSTATEST_ON                                              (1U)
#define PRCM_PM_PER_PWRSTST_LOGICSTATEST_OFF                                             (0U)

#define PRCM_PM_PER_PWRSTST_MEM_STATEST_SHIFT                                           (6U)
#define PRCM_PM_PER_PWRSTST_MEM_STATEST_MASK                                            (0x000000c0U)
#define PRCM_PM_PER_PWRSTST_MEM_STATEST_ON                                               (3U)
#define PRCM_PM_PER_PWRSTST_MEM_STATEST_OFF                                              (0U)
#define PRCM_PM_PER_PWRSTST_MEM_STATEST_RET                                              (1U)
#define PRCM_PM_PER_PWRSTST_MEM_STATEST_RESERVED                                         (2U)

#define PRCM_PM_PER_PWRSTST_RAM1_MEM_STATEST_SHIFT                                      (8U)
#define PRCM_PM_PER_PWRSTST_RAM1_MEM_STATEST_MASK                                       (0x00000300U)
#define PRCM_PM_PER_PWRSTST_RAM1_MEM_STATEST_ON                                          (3U)
#define PRCM_PM_PER_PWRSTST_RAM1_MEM_STATEST_OFF                                         (0U)
#define PRCM_PM_PER_PWRSTST_RAM1_MEM_STATEST_RET                                         (1U)
#define PRCM_PM_PER_PWRSTST_RAM1_MEM_STATEST_RESERVED                                    (2U)

#define PRCM_PM_PER_PWRSTST_ICSS_MEM_STATEST_SHIFT                                      (4U)
#define PRCM_PM_PER_PWRSTST_ICSS_MEM_STATEST_MASK                                       (0x00000030U)
#define PRCM_PM_PER_PWRSTST_ICSS_MEM_STATEST_ON                                          (3U)
#define PRCM_PM_PER_PWRSTST_ICSS_MEM_STATEST_OFF                                         (0U)
#define PRCM_PM_PER_PWRSTST_ICSS_MEM_STATEST_RET                                         (1U)
#define PRCM_PM_PER_PWRSTST_ICSS_MEM_STATEST_RESERVED                                    (2U)

#define PRCM_PM_PER_PWRSTST_RAM2_MEM_STATEST_SHIFT                                      (10U)
#define PRCM_PM_PER_PWRSTST_RAM2_MEM_STATEST_MASK                                       (0x00000c00U)
#define PRCM_PM_PER_PWRSTST_RAM2_MEM_STATEST_ON                                          (3U)
#define PRCM_PM_PER_PWRSTST_RAM2_MEM_STATEST_OFF                                         (0U)
#define PRCM_PM_PER_PWRSTST_RAM2_MEM_STATEST_RET                                         (1U)
#define PRCM_PM_PER_PWRSTST_RAM2_MEM_STATEST_RESERVED                                    (2U)

#define PRCM_PM_PER_PWRSTST_LASTPOWERSTATEENTERED_SHIFT                                 (24U)
#define PRCM_PM_PER_PWRSTST_LASTPOWERSTATEENTERED_MASK                                  (0x03000000U)
#define PRCM_PM_PER_PWRSTST_LASTPOWERSTATEENTERED_ON                                     (3U)
#define PRCM_PM_PER_PWRSTST_LASTPOWERSTATEENTERED_OFF                                    (0U)
#define PRCM_PM_PER_PWRSTST_LASTPOWERSTATEENTERED_RET                                    (1U)
#define PRCM_PM_PER_PWRSTST_LASTPOWERSTATEENTERED_INACTIVE                               (2U)

#define PRCM_RM_PER_RSTCTRL_ICSS_LRST_SHIFT                                             (1U)
#define PRCM_RM_PER_RSTCTRL_ICSS_LRST_MASK                                              (0x00000002U)
#define PRCM_RM_PER_RSTCTRL_ICSS_LRST_ASSERT                                             (1U)
#define PRCM_RM_PER_RSTCTRL_ICSS_LRST_CLEAR                                              (0U)

#define PRCM_RM_PER_RSTST_ICSS_LRST_SHIFT                                               (0U)
#define PRCM_RM_PER_RSTST_ICSS_LRST_MASK                                                (0x00000001U)
#define PRCM_RM_PER_RSTST_ICSS_LRST_RESET_YES                                            (1U)
#define PRCM_RM_PER_RSTST_ICSS_LRST_RESET_NO                                             (0U)

#define PRCM_RM_PER_L3_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                    (0U)
#define PRCM_RM_PER_L3_CONTEXT_LOSTCONTEXT_DFF_MASK                                     (0x00000001U)
#define PRCM_RM_PER_L3_CONTEXT_LOSTCONTEXT_DFF_LOST                                      (1U)
#define PRCM_RM_PER_L3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                                (0U)

#define PRCM_RM_PER_AES0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_AES0_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_AES0_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_AES0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_DES_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                   (0U)
#define PRCM_RM_PER_DES_CONTEXT_LOSTCONTEXT_DFF_MASK                                    (0x00000001U)
#define PRCM_RM_PER_DES_CONTEXT_LOSTCONTEXT_DFF_LOST                                     (1U)
#define PRCM_RM_PER_DES_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                               (0U)

#define PRCM_RM_PER_CRYPTODMA_CONTEXT_LOSTCONTEXT_DFF_SHIFT                             (0U)
#define PRCM_RM_PER_CRYPTODMA_CONTEXT_LOSTCONTEXT_DFF_MASK                              (0x00000001U)
#define PRCM_RM_PER_CRYPTODMA_CONTEXT_LOSTCONTEXT_DFF_LOST                               (1U)
#define PRCM_RM_PER_CRYPTODMA_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                         (0U)

#define PRCM_RM_PER_CRYPTODMA_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                       (8U)
#define PRCM_RM_PER_CRYPTODMA_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                        (0x00000100U)
#define PRCM_RM_PER_CRYPTODMA_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                         (1U)
#define PRCM_RM_PER_CRYPTODMA_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                   (0U)

#define PRCM_RM_PER_L3_INSTR_CONTEXT_LOSTCONTEXT_DFF_SHIFT                              (0U)
#define PRCM_RM_PER_L3_INSTR_CONTEXT_LOSTCONTEXT_DFF_MASK                               (0x00000001U)
#define PRCM_RM_PER_L3_INSTR_CONTEXT_LOSTCONTEXT_DFF_LOST                                (1U)
#define PRCM_RM_PER_L3_INSTR_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                          (0U)

#define PRCM_RM_PER_MSTR_EXPS_CONTEXT_LOSTCONTEXT_DFF_SHIFT                             (0U)
#define PRCM_RM_PER_MSTR_EXPS_CONTEXT_LOSTCONTEXT_DFF_MASK                              (0x00000001U)
#define PRCM_RM_PER_MSTR_EXPS_CONTEXT_LOSTCONTEXT_DFF_LOST                               (1U)
#define PRCM_RM_PER_MSTR_EXPS_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                         (0U)

#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTMEM_RAM1_MEM_SHIFT                              (8U)
#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTMEM_RAM1_MEM_MASK                               (0x00000100U)
#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTMEM_RAM1_MEM_LOST                                (1U)
#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTMEM_RAM1_MEM_MAINTAINED                          (0U)

#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTMEM_RAM2_MEM_SHIFT                              (9U)
#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTMEM_RAM2_MEM_MASK                               (0x00000200U)
#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTMEM_RAM2_MEM_LOST                                (1U)
#define PRCM_RM_PER_OCMCRAM_CONTEXT_LOSTMEM_RAM2_MEM_MAINTAINED                          (0U)

#define PRCM_RM_PER_SHA0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_SHA0_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_SHA0_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_SHA0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_SLV_EXPS_CONTEXT_LOSTCONTEXT_DFF_SHIFT                              (0U)
#define PRCM_RM_PER_SLV_EXPS_CONTEXT_LOSTCONTEXT_DFF_MASK                               (0x00000001U)
#define PRCM_RM_PER_SLV_EXPS_CONTEXT_LOSTCONTEXT_DFF_LOST                                (1U)
#define PRCM_RM_PER_SLV_EXPS_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                          (0U)

#define PRCM_RM_PER_VPFE0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_VPFE0_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_VPFE0_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_VPFE0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_VPFE0_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_VPFE0_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_VPFE0_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_VPFE0_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_VPFE1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_VPFE1_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_VPFE1_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_VPFE1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_VPFE1_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_VPFE1_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_VPFE1_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_VPFE1_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_TPCC_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_TPCC_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_TPCC_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_TPCC_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_TPCC_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                            (8U)
#define PRCM_RM_PER_TPCC_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                             (0x00000100U)
#define PRCM_RM_PER_TPCC_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                              (1U)
#define PRCM_RM_PER_TPCC_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                        (0U)

#define PRCM_RM_PER_TPTC0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_TPTC0_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_TPTC0_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_TPTC0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_TPTC0_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_TPTC0_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_TPTC0_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_TPTC0_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_TPTC1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_TPTC1_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_TPTC1_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_TPTC1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_TPTC1_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_TPTC1_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_TPTC1_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_TPTC1_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_TPTC2_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_TPTC2_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_TPTC2_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_TPTC2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_TPTC2_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_TPTC2_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_TPTC2_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_TPTC2_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_DLL_AGING_CONTEXT_LOSTCONTEXT_DFF_SHIFT                             (0U)
#define PRCM_RM_PER_DLL_AGING_CONTEXT_LOSTCONTEXT_DFF_MASK                              (0x00000001U)
#define PRCM_RM_PER_DLL_AGING_CONTEXT_LOSTCONTEXT_DFF_LOST                               (1U)
#define PRCM_RM_PER_DLL_AGING_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                         (0U)

#define PRCM_RM_PER_L4HS_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_L4HS_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_L4HS_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_L4HS_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_L4FW_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_L4FW_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_L4FW_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_L4FW_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_GPMC_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_GPMC_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_GPMC_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_GPMC_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_IEEE5000_CONTEXT_LOSTCONTEXT_DFF_SHIFT                              (0U)
#define PRCM_RM_PER_IEEE5000_CONTEXT_LOSTCONTEXT_DFF_MASK                               (0x00000001U)
#define PRCM_RM_PER_IEEE5000_CONTEXT_LOSTCONTEXT_DFF_LOST                                (1U)
#define PRCM_RM_PER_IEEE5000_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                          (0U)

#define PRCM_RM_PER_MAG_CARD_CONTEXT_LOSTCONTEXT_DFF_SHIFT                              (0U)
#define PRCM_RM_PER_MAG_CARD_CONTEXT_LOSTCONTEXT_DFF_MASK                               (0x00000001U)
#define PRCM_RM_PER_MAG_CARD_CONTEXT_LOSTCONTEXT_DFF_LOST                                (1U)
#define PRCM_RM_PER_MAG_CARD_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                          (0U)

#define PRCM_RM_PER_MCASP0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_MCASP0_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_MCASP0_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_MCASP0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_MCASP1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_MCASP1_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_MCASP1_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_MCASP1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_MMC2_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_MMC2_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_MMC2_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_MMC2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_MMC2_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                            (8U)
#define PRCM_RM_PER_MMC2_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                             (0x00000100U)
#define PRCM_RM_PER_MMC2_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                              (1U)
#define PRCM_RM_PER_MMC2_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                        (0U)

#define PRCM_RM_PER_QSPI_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_QSPI_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_QSPI_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_QSPI_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_USB_OTG_SS0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                           (0U)
#define PRCM_RM_PER_USB_OTG_SS0_CONTEXT_LOSTCONTEXT_DFF_MASK                            (0x00000001U)
#define PRCM_RM_PER_USB_OTG_SS0_CONTEXT_LOSTCONTEXT_DFF_LOST                             (1U)
#define PRCM_RM_PER_USB_OTG_SS0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                       (0U)

#define PRCM_RM_PER_USB_OTG_SS0_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                     (8U)
#define PRCM_RM_PER_USB_OTG_SS0_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                      (0x00000100U)
#define PRCM_RM_PER_USB_OTG_SS0_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                       (1U)
#define PRCM_RM_PER_USB_OTG_SS0_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                 (0U)

#define PRCM_RM_PER_USB_OTG_SS1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                           (0U)
#define PRCM_RM_PER_USB_OTG_SS1_CONTEXT_LOSTCONTEXT_DFF_MASK                            (0x00000001U)
#define PRCM_RM_PER_USB_OTG_SS1_CONTEXT_LOSTCONTEXT_DFF_LOST                             (1U)
#define PRCM_RM_PER_USB_OTG_SS1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                       (0U)

#define PRCM_RM_PER_USB_OTG_SS1_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                     (8U)
#define PRCM_RM_PER_USB_OTG_SS1_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                      (0x00000100U)
#define PRCM_RM_PER_USB_OTG_SS1_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                       (1U)
#define PRCM_RM_PER_USB_OTG_SS1_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                 (0U)

#define PRCM_RM_PER_ICSS_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_ICSS_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_ICSS_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_ICSS_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_ICSS_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                            (8U)
#define PRCM_RM_PER_ICSS_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                             (0x00000100U)
#define PRCM_RM_PER_ICSS_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                              (1U)
#define PRCM_RM_PER_ICSS_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                        (0U)

#define PRCM_RM_PER_L4LS_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_L4LS_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_L4LS_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_L4LS_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_DCAN0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_DCAN0_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_DCAN0_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_DCAN0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_DCAN1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_DCAN1_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_DCAN1_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_DCAN1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_EPWMSS0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_EPWMSS0_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_EPWMSS0_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_EPWMSS0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_EPWMSS1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_EPWMSS1_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_EPWMSS1_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_EPWMSS1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_EPWMSS2_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_EPWMSS2_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_EPWMSS2_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_EPWMSS2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_EPWMSS3_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_EPWMSS3_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_EPWMSS3_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_EPWMSS3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_EPWMSS4_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_EPWMSS4_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_EPWMSS4_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_EPWMSS4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_EPWMSS5_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_EPWMSS5_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_EPWMSS5_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_EPWMSS5_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_ELM_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                   (0U)
#define PRCM_RM_PER_ELM_CONTEXT_LOSTCONTEXT_DFF_MASK                                    (0x00000001U)
#define PRCM_RM_PER_ELM_CONTEXT_LOSTCONTEXT_DFF_LOST                                     (1U)
#define PRCM_RM_PER_ELM_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                               (0U)

#define PRCM_RM_PER_ERMC_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_ERMC_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_ERMC_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_ERMC_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_GPIO1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_GPIO1_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_GPIO1_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_GPIO1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_GPIO2_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_GPIO2_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_GPIO2_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_GPIO2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_GPIO3_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_GPIO3_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_GPIO3_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_GPIO3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_GPIO4_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_GPIO4_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_GPIO4_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_GPIO4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_GPIO5_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_GPIO5_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_GPIO5_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_GPIO5_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_HDQ1W_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_HDQ1W_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_HDQ1W_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_HDQ1W_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_I2C1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_I2C1_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_I2C1_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_I2C1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_I2C2_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_I2C2_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_I2C2_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_I2C2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_MAILBOX0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                              (0U)
#define PRCM_RM_PER_MAILBOX0_CONTEXT_LOSTCONTEXT_DFF_MASK                               (0x00000001U)
#define PRCM_RM_PER_MAILBOX0_CONTEXT_LOSTCONTEXT_DFF_LOST                                (1U)
#define PRCM_RM_PER_MAILBOX0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                          (0U)

#define PRCM_RM_PER_MMC0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_MMC0_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_MMC0_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_MMC0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_MMC0_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                            (8U)
#define PRCM_RM_PER_MMC0_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                             (0x00000100U)
#define PRCM_RM_PER_MMC0_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                              (1U)
#define PRCM_RM_PER_MMC0_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                        (0U)

#define PRCM_RM_PER_MMC1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_MMC1_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_MMC1_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_MMC1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_MMC1_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                            (8U)
#define PRCM_RM_PER_MMC1_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                             (0x00000100U)
#define PRCM_RM_PER_MMC1_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                              (1U)
#define PRCM_RM_PER_MMC1_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                        (0U)

#define PRCM_RM_PER_PKA_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                   (0U)
#define PRCM_RM_PER_PKA_CONTEXT_LOSTCONTEXT_DFF_MASK                                    (0x00000001U)
#define PRCM_RM_PER_PKA_CONTEXT_LOSTCONTEXT_DFF_LOST                                     (1U)
#define PRCM_RM_PER_PKA_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                               (0U)

#define PRCM_RM_PER_PKA_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                             (8U)
#define PRCM_RM_PER_PKA_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                              (0x00000100U)
#define PRCM_RM_PER_PKA_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                               (1U)
#define PRCM_RM_PER_PKA_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                         (0U)

#define PRCM_RM_PER_RNG_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                   (0U)
#define PRCM_RM_PER_RNG_CONTEXT_LOSTCONTEXT_DFF_MASK                                    (0x00000001U)
#define PRCM_RM_PER_RNG_CONTEXT_LOSTCONTEXT_DFF_LOST                                     (1U)
#define PRCM_RM_PER_RNG_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                               (0U)

#define PRCM_RM_PER_SPARE0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_SPARE0_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_SPARE0_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_SPARE0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_SPARE1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_SPARE1_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_SPARE1_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_SPARE1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_SPI0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_SPI0_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_SPI0_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_SPI0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_SPI1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_SPI1_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_SPI1_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_SPI1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_SPI2_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_SPI2_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_SPI2_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_SPI2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_SPI3_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_SPI3_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_SPI3_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_SPI3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_SPI4_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_SPI4_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_SPI4_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_SPI4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_SPINLOCK_CONTEXT_LOSTCONTEXT_DFF_SHIFT                              (0U)
#define PRCM_RM_PER_SPINLOCK_CONTEXT_LOSTCONTEXT_DFF_MASK                               (0x00000001U)
#define PRCM_RM_PER_SPINLOCK_CONTEXT_LOSTCONTEXT_DFF_LOST                                (1U)
#define PRCM_RM_PER_SPINLOCK_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                          (0U)

#define PRCM_RM_PER_SPINLOCK_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                        (8U)
#define PRCM_RM_PER_SPINLOCK_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                         (0x00000100U)
#define PRCM_RM_PER_SPINLOCK_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                          (1U)
#define PRCM_RM_PER_SPINLOCK_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                    (0U)

#define PRCM_RM_PER_TIMER2_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_TIMER2_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_TIMER2_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_TIMER2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_TIMER3_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_TIMER3_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_TIMER3_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_TIMER3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_TIMER4_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_TIMER4_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_TIMER4_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_TIMER4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_TIMER5_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_TIMER5_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_TIMER5_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_TIMER5_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_TIMER6_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_TIMER6_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_TIMER6_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_TIMER6_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_TIMER7_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_TIMER7_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_TIMER7_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_TIMER7_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_TIMER8_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_TIMER8_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_TIMER8_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_TIMER8_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_TIMER9_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_PER_TIMER9_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_PER_TIMER9_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_PER_TIMER9_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_PER_TIMER10_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_TIMER10_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_TIMER10_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_TIMER10_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_TIMER11_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_TIMER11_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_TIMER11_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_TIMER11_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_UART1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_UART1_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_UART1_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_UART1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_UART1_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_UART1_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_UART1_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_UART1_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_UART2_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_UART2_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_UART2_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_UART2_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_UART2_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_UART2_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_UART2_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_UART2_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_UART3_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_UART3_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_UART3_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_UART3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_UART3_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_UART3_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_UART3_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_UART3_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_UART4_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_UART4_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_UART4_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_UART4_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_UART4_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_UART4_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_UART4_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_UART4_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_UART5_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_UART5_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_UART5_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_UART5_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_UART5_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                           (8U)
#define PRCM_RM_PER_UART5_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                            (0x00000100U)
#define PRCM_RM_PER_UART5_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                             (1U)
#define PRCM_RM_PER_UART5_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                       (0U)

#define PRCM_RM_PER_USIM0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_USIM0_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_USIM0_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_USIM0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_USIM1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_USIM1_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_USIM1_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_USIM1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_PER_USBPHYOCP2SCP0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                        (0U)
#define PRCM_RM_PER_USBPHYOCP2SCP0_CONTEXT_LOSTCONTEXT_DFF_MASK                         (0x00000001U)
#define PRCM_RM_PER_USBPHYOCP2SCP0_CONTEXT_LOSTCONTEXT_DFF_LOST                          (1U)
#define PRCM_RM_PER_USBPHYOCP2SCP0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                    (0U)

#define PRCM_RM_PER_USBPHYOCP2SCP1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                        (0U)
#define PRCM_RM_PER_USBPHYOCP2SCP1_CONTEXT_LOSTCONTEXT_DFF_MASK                         (0x00000001U)
#define PRCM_RM_PER_USBPHYOCP2SCP1_CONTEXT_LOSTCONTEXT_DFF_LOST                          (1U)
#define PRCM_RM_PER_USBPHYOCP2SCP1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                    (0U)

#define PRCM_RM_PER_EMIF_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_EMIF_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_EMIF_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_EMIF_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_DLL_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                   (0U)
#define PRCM_RM_PER_DLL_CONTEXT_LOSTCONTEXT_DFF_MASK                                    (0x00000001U)
#define PRCM_RM_PER_DLL_CONTEXT_LOSTCONTEXT_DFF_LOST                                     (1U)
#define PRCM_RM_PER_DLL_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                               (0U)

#define PRCM_RM_PER_EMIF_FW_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_EMIF_FW_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_EMIF_FW_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_EMIF_FW_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_OTFA_EMIF_CONTEXT_LOSTCONTEXT_DFF_SHIFT                             (0U)
#define PRCM_RM_PER_OTFA_EMIF_CONTEXT_LOSTCONTEXT_DFF_MASK                              (0x00000001U)
#define PRCM_RM_PER_OTFA_EMIF_CONTEXT_LOSTCONTEXT_DFF_LOST                               (1U)
#define PRCM_RM_PER_OTFA_EMIF_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                         (0U)

#define PRCM_RM_PER_LCDC_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                  (0U)
#define PRCM_RM_PER_LCDC_CONTEXT_LOSTCONTEXT_DFF_MASK                                   (0x00000001U)
#define PRCM_RM_PER_LCDC_CONTEXT_LOSTCONTEXT_DFF_LOST                                    (1U)
#define PRCM_RM_PER_LCDC_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                              (0U)

#define PRCM_RM_PER_LCDC_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                            (8U)
#define PRCM_RM_PER_LCDC_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                             (0x00000100U)
#define PRCM_RM_PER_LCDC_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                              (1U)
#define PRCM_RM_PER_LCDC_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                        (0U)

#define PRCM_RM_PER_DSS_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                   (0U)
#define PRCM_RM_PER_DSS_CONTEXT_LOSTCONTEXT_DFF_MASK                                    (0x00000001U)
#define PRCM_RM_PER_DSS_CONTEXT_LOSTCONTEXT_DFF_LOST                                     (1U)
#define PRCM_RM_PER_DSS_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                               (0U)

#define PRCM_RM_PER_DSS_CONTEXT_LOSTMEM_MEM_SHIFT                                       (8U)
#define PRCM_RM_PER_DSS_CONTEXT_LOSTMEM_MEM_MASK                                        (0x00000100U)
#define PRCM_RM_PER_DSS_CONTEXT_LOSTMEM_MEM_LOST                                         (1U)
#define PRCM_RM_PER_DSS_CONTEXT_LOSTMEM_MEM_MAINTAINED                                   (0U)

#define PRCM_RM_PER_CPGMAC0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_PER_CPGMAC0_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_PER_CPGMAC0_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_PER_CPGMAC0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_PER_CPGMAC0_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                         (8U)
#define PRCM_RM_PER_CPGMAC0_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                          (0x00000100U)
#define PRCM_RM_PER_CPGMAC0_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                           (1U)
#define PRCM_RM_PER_CPGMAC0_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                     (0U)

#define PRCM_RM_PER_OCPWP_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_PER_OCPWP_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_PER_OCPWP_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_PER_OCPWP_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_PRM_PER_H_ */

