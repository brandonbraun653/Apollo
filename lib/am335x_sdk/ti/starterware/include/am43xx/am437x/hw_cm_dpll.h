/*
* hw_cm_dpll.h
*
* Register-level header file for CM_DPLL
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

#ifndef HW_CM_DPLL_H_
#define HW_CM_DPLL_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/

#define PRCM_CM_DPLL_CLKSEL_TIMER1_CLK                              (0x0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER2_CLK                              (0x4U)
#define PRCM_CM_DPLL_CLKSEL_TIMER3_CLK                              (0x8U)
#define PRCM_CM_DPLL_CLKSEL_TIMER4_CLK                              (0xcU)
#define PRCM_CM_DPLL_CLKSEL_TIMER5_CLK                              (0x10U)
#define PRCM_CM_DPLL_CLKSEL_TIMER6_CLK                              (0x14U)
#define PRCM_CM_DPLL_CLKSEL_TIMER7_CLK                              (0x18U)
#define PRCM_CM_DPLL_CLKSEL_TIMER8_CLK                              (0x1cU)
#define PRCM_CM_DPLL_CLKSEL_TIMER9_CLK                              (0x20U)
#define PRCM_CM_DPLL_CLKSEL_TIMER10_CLK                             (0x24U)
#define PRCM_CM_DPLL_CLKSEL_TIMER11_CLK                             (0x28U)
#define PRCM_CM_DPLL_CLKSEL_WDT1_CLK                                (0x2cU)
#define PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK                           (0x30U)
#define PRCM_CM_DPLL_CLKSEL_MAC_CLK                                 (0x34U)
#define PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK                            (0x38U)
#define PRCM_CM_DPLL_CLKSEL_GFX_FCLK                                (0x3cU)
#define PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK                             (0x40U)
#define PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK                          (0x44U)
#define PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK                            (0x48U)
#define PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK                            (0x4cU)
#define PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK                           (0x50U)
#define PRCM_CM_DPLL_CLKSEL_USIM_FCLK(m)                            ((uint32_t)0x54U + (m * 0x4U))
#define PRCM_CM_DPLL_CLKSEL_USIM_FCLK_NUM_ELEMS                     (2U)
#define PRCM_CM_DPLL_CLKSEL_USIM_DBCLK                              (0x5cU)
#define PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK                        (0x60U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_MASK                                             (0x00000007U)
#define PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_M_OSC                                             (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_32KHZ                                             (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_TCLKIN                                            (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_RC32K                                             (3U)
#define PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_RTC_32K                                           (4U)
#define PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_TPM_32K                                           (5U)

#define PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_MASK                                             (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_TCLKIN                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_M_OSC                                             (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_32KHZ                                             (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_RSVD                                              (3U)

#define PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_MASK                                             (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_TCLKIN                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_M_OSC                                             (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_32KHZ                                             (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_RSVD                                              (3U)

#define PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_MASK                                             (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_TCLKIN                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_M_OSC                                             (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_32KHZ                                             (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_RSVD                                              (3U)

#define PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_MASK                                             (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_TCLKIN                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_M_OSC                                             (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_32KHZ                                             (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_RSVD                                              (3U)

#define PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_MASK                                             (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_TCLKIN                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_M_OSC                                             (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_32KHZ                                             (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_RSVD                                              (3U)

#define PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_MASK                                             (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_TCLKIN                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_M_OSC                                             (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_32KHZ                                             (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_RSVD                                              (3U)

#define PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_MASK                                             (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_TCLKIN                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_M_OSC                                             (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_32KHZ                                             (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_RSVD                                              (3U)

#define PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_MASK                                             (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_TCLKIN                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_M_OSC                                             (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_32KHZ                                             (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_RSVD                                              (3U)

#define PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_SHIFT                                           (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_MASK                                            (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_TCLKIN                                           (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_M_OSC                                            (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_32KHZ                                            (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_RSVD                                             (3U)

#define PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_SHIFT                                           (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_MASK                                            (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_TCLKIN                                           (0U)
#define PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_M_OSC                                            (1U)
#define PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_32KHZ                                            (2U)
#define PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_RSVD                                             (3U)

#define PRCM_CM_DPLL_CLKSEL_WDT1_CLK_SHIFT                                              (0U)
#define PRCM_CM_DPLL_CLKSEL_WDT1_CLK_MASK                                               (0x00000001U)
#define PRCM_CM_DPLL_CLKSEL_WDT1_CLK_RC32K                                               (0U)
#define PRCM_CM_DPLL_CLKSEL_WDT1_CLK_CLKDIV_32KHZ                                        (1U)

#define PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_SHIFT                                         (0U)
#define PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_MASK                                          (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_RTC_32K                                        (0U)
#define PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_TPM_32K                                        (1U)
#define PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_PER_PLL_32K                                    (2U)
#define PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_RSVD                                           (3U)

#define PRCM_CM_DPLL_CLKSEL_MAC_CLK_MII_SEL_SHIFT                                       (2U)
#define PRCM_CM_DPLL_CLKSEL_MAC_CLK_MII_SEL_MASK                                        (0x00000004U)
#define PRCM_CM_DPLL_CLKSEL_MAC_CLK_MII_SEL_DIV_1_2                                      (0U)
#define PRCM_CM_DPLL_CLKSEL_MAC_CLK_MII_SEL_DIV_1_5                                      (1U)

#define PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_SHIFT                                          (0U)
#define PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_MASK                                           (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_HSDIV_CORE_M4                                   (0U)
#define PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_HSDIV_CORE_M5                                   (1U)
#define PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_DISP_PLL                                        (2U)

#define PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_SHIFT                                   (0U)
#define PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_MASK                                    (0x00000001U)
#define PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_DIV1                                     (0U)
#define PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_DIV2                                     (1U)

#define PRCM_CM_DPLL_CLKSEL_GFX_FCLK_SHIFT                                              (1U)
#define PRCM_CM_DPLL_CLKSEL_GFX_FCLK_MASK                                               (0x00000002U)
#define PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CORE_PLL                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_GFX_FCLK_PER_PLL                                             (1U)

#define PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_SHIFT                                           (0U)
#define PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_MASK                                            (0x00000007U)
#define PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_CLK_RC32K                                        (0U)
#define PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_OSC_32K                                          (1U)
#define PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_PER_PLL                                          (2U)
#define PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_SYS_CLK                                          (3U)
#define PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_CLK_32K_TPM                                      (4U)

#define PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_SHIFT                                        (0U)
#define PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_MASK                                         (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_DISP_PLL_CLKOUTM2                             (0U)
#define PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_CORE_PLL_CLKOUTM5                             (1U)
#define PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_PER_PLL_CLKOUTM2                              (2U)
#define PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_RSVD                                          (3U)

#define PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_SHIFT                                          (0U)
#define PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_MASK                                           (0x00000001U)
#define PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_L3F                                             (0U)
#define PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_DISP                                            (1U)

#define PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK_SHIFT                                          (0U)
#define PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK_MASK                                           (0x00000001U)
#define PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK_MAIN_XTAL                                       (0U)
#define PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK_PER_PLL                                         (1U)

#define PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_SHIFT                                         (0U)
#define PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_MASK                                          (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_DIV8                                           (0U)
#define PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_DIV16                                          (1U)
#define PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_DIV32                                          (2U)
#define PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_RSVD                                           (3U)

#define PRCM_CM_DPLL_CLKSEL_USIM_FCLK_SHIFT                                             (0U)
#define PRCM_CM_DPLL_CLKSEL_USIM_FCLK_MASK                                              (0x00000001U)
#define PRCM_CM_DPLL_CLKSEL_USIM_FCLK_OSC_CLK                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_USIM_FCLK_CORE_PLL                                           (1U)

#define PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_SHIFT                                            (0U)
#define PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_MASK                                             (0x00000003U)
#define PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_CLK_RC32K                                         (0U)
#define PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_MOSC                                              (1U)
#define PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_PER_PLL                                           (2U)

#define PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK_SHIFT                                      (0U)
#define PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK_MASK                                       (0x00000001U)
#define PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK_RTC_32K                                     (0U)
#define PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK_TPM_32K                                     (1U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CM_DPLL_H_ */

