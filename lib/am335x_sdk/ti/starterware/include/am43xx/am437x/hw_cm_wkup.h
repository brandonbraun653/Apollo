/*
* hw_cm_wkup.h
*
* Register-level header file for CM_WKUP
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

#ifndef HW_CM_WKUP_H_
#define HW_CM_WKUP_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/

#define PRCM_CM_L3_AON_CLKSTCTRL                                    (0x0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL                                  (0x20U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL                                   (0x100U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL                                (0x120U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL                               (0x200U)
#define PRCM_CM_WKUP_L4WKUP_CLKCTRL                                 (0x220U)
#define PRCM_CM_WKUP_M3_CLKCTRL                                     (0x228U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL                              (0x230U)
#define PRCM_CM_WKUP_CLKDIV32K_CLKCTRL                              (0x238U)
#define PRCM_CM_WKUP_USBPHY0_CLKCTRL                                (0x240U)
#define PRCM_CM_WKUP_USBPHY1_CLKCTRL                                (0x248U)
#define PRCM_CM_WKUP_CLKSTCTRL                                      (0x300U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL                                 (0x320U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL                                 (0x328U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL                                   (0x330U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL                                   (0x338U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL                                   (0x340U)
#define PRCM_CM_WKUP_UART0_CLKCTRL                                  (0x348U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL                           (0x350U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL                           (0x358U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL                                   (0x360U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL                                  (0x368U)
#define PRCM_CM_CLKMODE_DPLL_CORE                                   (0x520U)
#define PRCM_CM_IDLEST_DPLL_CORE                                    (0x524U)
#define PRCM_CM_CLKSEL_DPLL_CORE                                    (0x52cU)
#define PRCM_CM_DIV_M4_DPLL_CORE                                    (0x538U)
#define PRCM_CM_DIV_M5_DPLL_CORE                                    (0x53cU)
#define PRCM_CM_DIV_M6_DPLL_CORE                                    (0x540U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_CORE                            (0x548U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_CORE                            (0x54cU)
#define PRCM_CM_CLKMODE_DPLL_MPU                                    (0x560U)
#define PRCM_CM_IDLEST_DPLL_MPU                                     (0x564U)
#define PRCM_CM_CLKSEL_DPLL_MPU                                     (0x56cU)
#define PRCM_CM_DIV_M2_DPLL_MPU                                     (0x570U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_MPU                             (0x588U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_MPU                             (0x58cU)
#define PRCM_CM_CLKMODE_DPLL_DDR                                    (0x5a0U)
#define PRCM_CM_IDLEST_DPLL_DDR                                     (0x5a4U)
#define PRCM_CM_CLKSEL_DPLL_DDR                                     (0x5acU)
#define PRCM_CM_DIV_M2_DPLL_DDR                                     (0x5b0U)
#define PRCM_CM_DIV_M4_DPLL_DDR                                     (0x5b8U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_DDR                             (0x5c8U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_DDR                             (0x5ccU)
#define PRCM_CM_CLKMODE_DPLL_PER                                    (0x5e0U)
#define PRCM_CM_IDLEST_DPLL_PER                                     (0x5e4U)
#define PRCM_CM_CLKSEL_DPLL_PER                                     (0x5ecU)
#define PRCM_CM_DIV_M2_DPLL_PER                                     (0x5f0U)
#define PRCM_CM_CLKSEL2_DPLL_PER                                    (0x604U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_PER                             (0x608U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_PER                             (0x60cU)
#define PRCM_CM_CLKDCOLDO_DPLL_PER                                  (0x614U)
#define PRCM_CM_CLKMODE_DPLL_DISP                                   (0x620U)
#define PRCM_CM_IDLEST_DPLL_DISP                                    (0x624U)
#define PRCM_CM_CLKSEL_DPLL_DISP                                    (0x62cU)
#define PRCM_CM_DIV_M2_DPLL_DISP                                    (0x630U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_DISP                            (0x648U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_DISP                            (0x64cU)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV                                 (0x660U)
#define PRCM_CM_IDLEST_DPLL_EXTDEV                                  (0x664U)
#define PRCM_CM_CLKSEL_DPLL_EXTDEV                                  (0x66cU)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV                                  (0x670U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV                                 (0x684U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_EXTDEV                          (0x688U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_EXTDEV                          (0x68cU)
#define PRCM_CM_SHADOW_FREQ_CONFIG1                                 (0x7a0U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2                                 (0x7a4U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define PRCM_CM_L3_AON_CLKSTCTRL_CLKTRCTRL_SHIFT                                        (0U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKTRCTRL_MASK                                         (0x00000003U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKTRCTRL_NO_SLEEP                                      (0U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKTRCTRL_SW_SLEEP                                      (1U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKTRCTRL_SW_WKUP                                       (2U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKTRCTRL_RESERVED                                      (3U)

#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBGSYSCLK_SHIFT                            (8U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBGSYSCLK_MASK                             (0x00000100U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBGSYSCLK_INACT                             (0U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBGSYSCLK_ACT                               (1U)

#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT                                 (9U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_GCLK_MASK                                  (0x00000200U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_GCLK_INACT                                  (0U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_GCLK_ACT                                    (1U)

#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBG_CLKA_SHIFT                             (10U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBG_CLKA_MASK                              (0x00000400U)

#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBG_CLKB_SHIFT                             (11U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBG_CLKB_MASK                              (0x00000800U)

#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBG_CLKC_SHIFT                             (12U)
#define PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBG_CLKC_MASK                              (0x00001000U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_IDLEST_SHIFT                                         (16U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_IDLEST_MASK                                          (0x00030000U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_IDLEST_DISABLE                                        (3U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_IDLEST_IDLE                                           (2U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_IDLEST_FUNC                                           (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_IDLEST_TRANS                                          (1U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STBYST_SHIFT                                         (18U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STBYST_MASK                                          (0x00040000U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STBYST_FUNC                                           (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STBYST_STANDBY                                        (1U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_MODULEMODE_SHIFT                                     (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_MODULEMODE_MASK                                      (0x00000003U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_MODULEMODE_DISABLED                                   (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_MODULEMODE_RESERVED_1                                 (1U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_MODULEMODE_ENABLE                                     (2U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_MODULEMODE_RESERVED                                   (3U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTFCLKEN_DBGSYSCLK_SHIFT                            (8U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTFCLKEN_DBGSYSCLK_MASK                             (0x00000100U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTFCLKEN_DBGSYSCLK_FCLK_EN                           (1U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTFCLKEN_DBGSYSCLK_FCLK_DIS                          (0U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKDIVSEL_SHIFT                              (27U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKDIVSEL_MASK                               (0x38000000U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKDIVSEL_DIV1                                (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKDIVSEL_DIV2                                (2U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKDIVSEL_DIV4                                (4U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKDIVSEL_SHIFT                              (24U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKDIVSEL_MASK                               (0x07000000U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKDIVSEL_DIV1                                (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKDIVSEL_DIV2                                (2U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKDIVSEL_DIV4                                (4U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKSEL_SHIFT                                 (20U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKSEL_MASK                                  (0x00300000U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKSEL_SEL1                                   (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKSEL_SEL2                                   (1U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKSEL_SEL3                                   (2U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_STM_PMD_CLKSEL_SEL4                                   (3U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKSEL_SHIFT                                 (22U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKSEL_MASK                                  (0x00c00000U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKSEL_SEL1                                   (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKSEL_SEL2                                   (1U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKSEL_SEL3                                   (2U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_TRC_PMD_CLKSEL_SEL4                                   (3U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKA_SHIFT                                (9U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKA_MASK                                 (0x00000200U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKA_DISABLE                               (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKA_ENABLE                                (1U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKC_SHIFT                                (11U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKC_MASK                                 (0x00000800U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKC_DISABLE                               (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKC_ENABLE                                (1U)

#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKB_SHIFT                                (10U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKB_MASK                                 (0x00000400U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKB_DISABLE                               (0U)
#define PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTCLK_DBG_CLKB_ENABLE                                (1U)

#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKTRCTRL_SHIFT                                       (0U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKTRCTRL_MASK                                        (0x00000003U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKTRCTRL_NO_SLEEP                                     (0U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKTRCTRL_SW_SLEEP                                     (1U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKTRCTRL_SW_WKUP                                      (2U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKTRCTRL_RESERVED                                     (3U)

#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT                                (8U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_GCLK_MASK                                 (0x00000100U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_GCLK_INACT                                 (0U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_GCLK_ACT                                   (1U)

#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_ADC_FCLK_SHIFT                            (9U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_ADC_FCLK_MASK                             (0x00000200U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_ADC_FCLK_INACT                             (0U)
#define PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_ADC_FCLK_ACT                               (1U)

#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_IDLEST_SHIFT                                       (16U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_IDLEST_MASK                                        (0x00030000U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_IDLEST_DISABLE                                      (3U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_IDLEST_IDLE                                         (2U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_IDLEST_FUNC                                         (0U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_IDLEST_TRANS                                        (1U)

#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_MODULEMODE_SHIFT                                   (0U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_MODULEMODE_MASK                                    (0x00000003U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_MODULEMODE_DISABLED                                 (0U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_MODULEMODE_RESERVED_1                               (1U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_MODULEMODE_ENABLE                                   (2U)
#define PRCM_CM_WKUP_ADC_TSC_CLKCTRL_MODULEMODE_RESERVED                                 (3U)

#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT                            (8U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_GCLK_MASK                             (0x00000100U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_GCLK_INACT                             (0U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_GCLK_ACT                               (1U)

#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKTRCTRL_SHIFT                                   (0U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKTRCTRL_MASK                                    (0x00000003U)

#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_SYNCTIMER32K_GFCLK_SHIFT              (9U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_SYNCTIMER32K_GFCLK_MASK               (0x00000200U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_SYNCTIMER32K_GFCLK_INACT               (0U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_SYNCTIMER32K_GFCLK_ACT                 (1U)

#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_USBPHY_32KHZ_GCLK_SHIFT               (10U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_USBPHY_32KHZ_GCLK_MASK                (0x00000400U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_USBPHY_32KHZ_GCLK_INACT                (0U)
#define PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_USBPHY_32KHZ_GCLK_ACT                  (1U)

#define PRCM_CM_WKUP_L4WKUP_CLKCTRL_IDLEST_SHIFT                                        (16U)
#define PRCM_CM_WKUP_L4WKUP_CLKCTRL_IDLEST_MASK                                         (0x00030000U)
#define PRCM_CM_WKUP_L4WKUP_CLKCTRL_IDLEST_DISABLE                                       (3U)
#define PRCM_CM_WKUP_L4WKUP_CLKCTRL_IDLEST_IDLE                                          (2U)
#define PRCM_CM_WKUP_L4WKUP_CLKCTRL_IDLEST_FUNC                                          (0U)
#define PRCM_CM_WKUP_L4WKUP_CLKCTRL_IDLEST_TRANS                                         (1U)

#define PRCM_CM_WKUP_L4WKUP_CLKCTRL_MODULEMODE_SHIFT                                    (0U)
#define PRCM_CM_WKUP_L4WKUP_CLKCTRL_MODULEMODE_MASK                                     (0x00000003U)

#define PRCM_CM_WKUP_M3_CLKCTRL_STBYST_SHIFT                                            (18U)
#define PRCM_CM_WKUP_M3_CLKCTRL_STBYST_MASK                                             (0x00040000U)
#define PRCM_CM_WKUP_M3_CLKCTRL_STBYST_FUNC                                              (0U)
#define PRCM_CM_WKUP_M3_CLKCTRL_STBYST_STANDBY                                           (1U)

#define PRCM_CM_WKUP_M3_CLKCTRL_MODULEMODE_SHIFT                                        (0U)
#define PRCM_CM_WKUP_M3_CLKCTRL_MODULEMODE_MASK                                         (0x00000003U)

#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_IDLEST_SHIFT                                     (16U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_IDLEST_MASK                                      (0x00030000U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_IDLEST_DISABLE                                    (3U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_IDLEST_IDLE                                       (2U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_IDLEST_FUNC                                       (0U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_IDLEST_TRANS                                      (1U)

#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_MODULEMODE_SHIFT                                 (0U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_MODULEMODE_MASK                                  (0x00000003U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_MODULEMODE_DISABLED                               (0U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_MODULEMODE_RESERVED_1                             (1U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_MODULEMODE_ENABLE                                 (2U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_MODULEMODE_RESERVED                               (3U)

#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_OPTFCLKEN_FCLK32_SHIFT                           (8U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_OPTFCLKEN_FCLK32_MASK                            (0x00000100U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_OPTFCLKEN_FCLK32_FCLK_EN                          (1U)
#define PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_OPTFCLKEN_FCLK32_FCLK_DIS                         (0U)

#define PRCM_CM_WKUP_CLKDIV32K_CLKCTRL_OPTFCLKEN_FCLK_SHIFT                             (8U)
#define PRCM_CM_WKUP_CLKDIV32K_CLKCTRL_OPTFCLKEN_FCLK_MASK                              (0x00000100U)
#define PRCM_CM_WKUP_CLKDIV32K_CLKCTRL_OPTFCLKEN_FCLK_EN                                 (1U)
#define PRCM_CM_WKUP_CLKDIV32K_CLKCTRL_OPTFCLKEN_FCLK_DIS                                (0U)

#define PRCM_CM_WKUP_USBPHY0_CLKCTRL_OPTFCLKEN_CLK32K_SHIFT                             (8U)
#define PRCM_CM_WKUP_USBPHY0_CLKCTRL_OPTFCLKEN_CLK32K_MASK                              (0x00000100U)
#define PRCM_CM_WKUP_USBPHY0_CLKCTRL_OPTFCLKEN_CLK32K_FCLK_EN                            (1U)
#define PRCM_CM_WKUP_USBPHY0_CLKCTRL_OPTFCLKEN_CLK32K_FCLK_DIS                           (0U)

#define PRCM_CM_WKUP_USBPHY1_CLKCTRL_OPTFCLKEN_CLK32K_SHIFT                             (8U)
#define PRCM_CM_WKUP_USBPHY1_CLKCTRL_OPTFCLKEN_CLK32K_MASK                              (0x00000100U)
#define PRCM_CM_WKUP_USBPHY1_CLKCTRL_OPTFCLKEN_CLK32K_FCLK_EN                            (1U)
#define PRCM_CM_WKUP_USBPHY1_CLKCTRL_OPTFCLKEN_CLK32K_FCLK_DIS                           (0U)

#define PRCM_CM_WKUP_CLKSTCTRL_CLKTRCTRL_SHIFT                                          (0U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKTRCTRL_MASK                                           (0x00000003U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKTRCTRL_NO_SLEEP                                        (0U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKTRCTRL_SW_SLEEP                                        (1U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKTRCTRL_SW                                              (2U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKTRCTRL_RESERVED                                        (3U)

#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_GPIO0_GDBCLK_SHIFT                           (11U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_GPIO0_GDBCLK_MASK                            (0x00000800U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_GPIO0_GDBCLK_INACT                            (0U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_GPIO0_GDBCLK_ACT                              (1U)

#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT                                (8U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_MASK                                 (0x00000100U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_INACT                                 (0U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_ACT                                   (1U)

#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_SR_SYSCLK_SHIFT                              (9U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_SR_SYSCLK_MASK                               (0x00000200U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_SR_SYSCLK_INACT                               (0U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_SR_SYSCLK_ACT                                 (1U)

#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK_SHIFT                             (14U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK_MASK                              (0x00004000U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK_INACT                              (0U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK_ACT                                (1U)

#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_UART0_GFCLK_SHIFT                            (15U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_UART0_GFCLK_MASK                             (0x00008000U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_UART0_GFCLK_INACT                             (0U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_UART0_GFCLK_ACT                               (1U)

#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_TIMER1_GCLK_SHIFT                            (16U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_TIMER1_GCLK_MASK                             (0x00010000U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_TIMER1_GCLK_INACT                             (0U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_TIMER1_GCLK_ACT                               (1U)

#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_WDT1_GCLK_SHIFT                              (10U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_WDT1_GCLK_MASK                               (0x00000400U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_WDT1_GCLK_INACT                               (0U)
#define PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_WDT1_GCLK_ACT                                 (1U)

#define PRCM_CM_WKUP_TIMER0_CLKCTRL_IDLEST_SHIFT                                        (16U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_IDLEST_MASK                                         (0x00030000U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_IDLEST_DISABLE                                       (3U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_IDLEST_IDLE                                          (2U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_IDLEST_FUNC                                          (0U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_IDLEST_TRANS                                         (1U)

#define PRCM_CM_WKUP_TIMER0_CLKCTRL_MODULEMODE_SHIFT                                    (0U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_MODULEMODE_MASK                                     (0x00000003U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_MODULEMODE_DISABLED                                  (0U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_MODULEMODE_RESERVED_1                                (1U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_MODULEMODE_ENABLE                                    (2U)
#define PRCM_CM_WKUP_TIMER0_CLKCTRL_MODULEMODE_RESERVED                                  (3U)

#define PRCM_CM_WKUP_TIMER1_CLKCTRL_IDLEST_SHIFT                                        (16U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_IDLEST_MASK                                         (0x00030000U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_IDLEST_DISABLE                                       (3U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_IDLEST_IDLE                                          (2U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_IDLEST_FUNC                                          (0U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_IDLEST_TRANS                                         (1U)

#define PRCM_CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_SHIFT                                    (0U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_MASK                                     (0x00000003U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_DISABLED                                  (0U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_RESERVED_1                                (1U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_ENABLE                                    (2U)
#define PRCM_CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_RESERVED                                  (3U)

#define PRCM_CM_WKUP_WDT0_CLKCTRL_IDLEST_SHIFT                                          (16U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_IDLEST_MASK                                           (0x00030000U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_IDLEST_DISABLE                                         (3U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_IDLEST_IDLE                                            (2U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_IDLEST_FUNC                                            (0U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_IDLEST_TRANS                                           (1U)

#define PRCM_CM_WKUP_WDT0_CLKCTRL_MODULEMODE_SHIFT                                      (0U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_MODULEMODE_MASK                                       (0x00000003U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_MODULEMODE_DISABLED                                    (0U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_MODULEMODE_RESERVED_1                                  (1U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_MODULEMODE_ENABLE                                      (2U)
#define PRCM_CM_WKUP_WDT0_CLKCTRL_MODULEMODE_RESERVED                                    (3U)

#define PRCM_CM_WKUP_WDT1_CLKCTRL_IDLEST_SHIFT                                          (16U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_IDLEST_MASK                                           (0x00030000U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_IDLEST_DISABLE                                         (3U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_IDLEST_IDLE                                            (2U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_IDLEST_FUNC                                            (0U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_IDLEST_TRANS                                           (1U)

#define PRCM_CM_WKUP_WDT1_CLKCTRL_MODULEMODE_SHIFT                                      (0U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_MODULEMODE_MASK                                       (0x00000003U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_MODULEMODE_DISABLED                                    (0U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_MODULEMODE_RESERVED_1                                  (1U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_MODULEMODE_ENABLE                                      (2U)
#define PRCM_CM_WKUP_WDT1_CLKCTRL_MODULEMODE_RESERVED                                    (3U)

#define PRCM_CM_WKUP_I2C0_CLKCTRL_IDLEST_SHIFT                                          (16U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_IDLEST_MASK                                           (0x00030000U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_IDLEST_DISABLE                                         (3U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_IDLEST_IDLE                                            (2U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_IDLEST_FUNC                                            (0U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_IDLEST_TRANS                                           (1U)

#define PRCM_CM_WKUP_I2C0_CLKCTRL_MODULEMODE_SHIFT                                      (0U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_MODULEMODE_MASK                                       (0x00000003U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_MODULEMODE_DISABLED                                    (0U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_MODULEMODE_RESERVED_1                                  (1U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_MODULEMODE_ENABLE                                      (2U)
#define PRCM_CM_WKUP_I2C0_CLKCTRL_MODULEMODE_RESERVED                                    (3U)

#define PRCM_CM_WKUP_UART0_CLKCTRL_IDLEST_SHIFT                                         (16U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_IDLEST_MASK                                          (0x00030000U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_IDLEST_DISABLE                                        (3U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_IDLEST_IDLE                                           (2U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_IDLEST_FUNC                                           (0U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_IDLEST_TRANS                                          (1U)

#define PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE_SHIFT                                     (0U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE_MASK                                      (0x00000003U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE_DISABLED                                   (0U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE_RESERVED_1                                 (1U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE_ENABLE                                     (2U)
#define PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE_RESERVED                                   (3U)

#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_IDLEST_SHIFT                                  (16U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_IDLEST_MASK                                   (0x00030000U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_IDLEST_DISABLE                                 (3U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_IDLEST_IDLE                                    (2U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_IDLEST_FUNC                                    (0U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_IDLEST_TRANS                                   (1U)

#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_MODULEMODE_SHIFT                              (0U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_MODULEMODE_MASK                               (0x00000003U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_MODULEMODE_DISABLED                            (0U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_MODULEMODE_RESERVED_1                          (1U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_MODULEMODE_ENABLE                              (2U)
#define PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL_MODULEMODE_RESERVED                            (3U)

#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_IDLEST_SHIFT                                  (16U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_IDLEST_MASK                                   (0x00030000U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_IDLEST_DISABLE                                 (3U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_IDLEST_IDLE                                    (2U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_IDLEST_FUNC                                    (0U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_IDLEST_TRANS                                   (1U)

#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_MODULEMODE_SHIFT                              (0U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_MODULEMODE_MASK                               (0x00000003U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_MODULEMODE_DISABLED                            (0U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_MODULEMODE_RESERVED_1                          (1U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_MODULEMODE_ENABLE                              (2U)
#define PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL_MODULEMODE_RESERVED                            (3U)

#define PRCM_CM_WKUP_CTRL_CLKCTRL_IDLEST_SHIFT                                          (16U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_IDLEST_MASK                                           (0x00030000U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_IDLEST_DISABLE                                         (3U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_IDLEST_IDLE                                            (2U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_IDLEST_FUNC                                            (0U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_IDLEST_TRANS                                           (1U)

#define PRCM_CM_WKUP_CTRL_CLKCTRL_MODULEMODE_SHIFT                                      (0U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_MODULEMODE_MASK                                       (0x00000003U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_MODULEMODE_DISABLED                                    (0U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_MODULEMODE_RESERVED_1                                  (1U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_MODULEMODE_ENABLE                                      (2U)
#define PRCM_CM_WKUP_CTRL_CLKCTRL_MODULEMODE_RESERVED                                    (3U)

#define PRCM_CM_WKUP_GPIO0_CLKCTRL_IDLEST_SHIFT                                         (16U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_IDLEST_MASK                                          (0x00030000U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_IDLEST_DISABLE                                        (3U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_IDLEST_IDLE                                           (2U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_IDLEST_FUNC                                           (0U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_IDLEST_TRANS                                          (1U)

#define PRCM_CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_SHIFT                                     (0U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_MASK                                      (0x00000003U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_DISABLED                                   (0U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_RESERVED_1                                 (1U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_ENABLE                                     (2U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_MODULEMODE_RESERVED                                   (3U)

#define PRCM_CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GDBCLK_SHIFT                               (8U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GDBCLK_MASK                                (0x00000100U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GDBCLK_FCLK_EN                              (1U)
#define PRCM_CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GDBCLK_FCLK_DIS                             (0U)

#define PRCM_CM_CLKMODE_DPLL_CORE_EN_SHIFT                                              (0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_EN_MASK                                               (0x00000007U)
#define PRCM_CM_CLKMODE_DPLL_CORE_EN_RESERVED                                            (0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_EN_RESERVED1                                           (1U)
#define PRCM_CM_CLKMODE_DPLL_CORE_EN_RESERVED2                                           (2U)
#define PRCM_CM_CLKMODE_DPLL_CORE_EN_RESERVED3                                           (3U)
#define PRCM_CM_CLKMODE_DPLL_CORE_EN_MN_BYP_MODE                                         (4U)
#define PRCM_CM_CLKMODE_DPLL_CORE_EN_LP_BYP_MODE                                         (5U)
#define PRCM_CM_CLKMODE_DPLL_CORE_EN_FR_BYP_MODE                                         (6U)
#define PRCM_CM_CLKMODE_DPLL_CORE_EN_LOCK_MODE                                           (7U)

#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_LEVEL_SHIFT                                      (3U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_LEVEL_MASK                                       (0x00000018U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_LEVEL_DISABLE                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_LEVEL_ALGO1                                       (1U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_LEVEL_ALGO2                                       (2U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_LEVEL_RESERVED                                    (3U)

#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_SHIFT                                       (5U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_MASK                                        (0x000000e0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_REFCLKX2                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_REFCLKX4                                     (1U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_REFCLKX8                                     (2U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_REFCLKX16                                    (3U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_REFCLKX32                                    (4U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_REFCLKX64                                    (5U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_REFCLKX128                                   (6U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RAMP_RATE_REFCLKX512                                   (7U)

#define PRCM_CM_CLKMODE_DPLL_CORE_DRIFTGUARD_EN_SHIFT                                   (8U)
#define PRCM_CM_CLKMODE_DPLL_CORE_DRIFTGUARD_EN_MASK                                    (0x00000100U)
#define PRCM_CM_CLKMODE_DPLL_CORE_DRIFTGUARD_EN_ENABLED                                  (1U)
#define PRCM_CM_CLKMODE_DPLL_CORE_DRIFTGUARD_EN_DIASBLED                                 (0U)

#define PRCM_CM_CLKMODE_DPLL_CORE_RELOCK_RAMP_EN_SHIFT                                  (9U)
#define PRCM_CM_CLKMODE_DPLL_CORE_RELOCK_RAMP_EN_MASK                                   (0x00000200U)

#define PRCM_CM_CLKMODE_DPLL_CORE_LPMODE_EN_SHIFT                                       (10U)
#define PRCM_CM_CLKMODE_DPLL_CORE_LPMODE_EN_MASK                                        (0x00000400U)
#define PRCM_CM_CLKMODE_DPLL_CORE_LPMODE_EN_DISABLED                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_LPMODE_EN_ENABLED                                      (1U)

#define PRCM_CM_CLKMODE_DPLL_CORE_REGM4XEN_SHIFT                                        (11U)
#define PRCM_CM_CLKMODE_DPLL_CORE_REGM4XEN_MASK                                         (0x00000800U)
#define PRCM_CM_CLKMODE_DPLL_CORE_REGM4XEN_DISABLED                                      (0U)

#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_EN_SHIFT                                          (12U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_EN_MASK                                           (0x00001000U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_EN_DISABLED                                        (0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_EN_ENABLED                                         (1U)

#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_ACK_SHIFT                                         (13U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_ACK_MASK                                          (0x00002000U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_ACK_DISABLED                                       (0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_ACK_ENABLED                                        (1U)

#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_DOWNSPREAD_SHIFT                                  (14U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_DOWNSPREAD_MASK                                   (0x00004000U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_DOWNSPREAD_FULL_SPREAD                             (0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_DOWNSPREAD_LOW_SPREAD                              (1U)

#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_TYPE_SHIFT                                        (15U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_TYPE_MASK                                         (0x00008000U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_TYPE_TRIANGULAR                                    (0U)
#define PRCM_CM_CLKMODE_DPLL_CORE_SSC_TYPE_SQUARE                                        (1U)

#define PRCM_CM_IDLEST_DPLL_CORE_ST_CLK_SHIFT                                           (0U)
#define PRCM_CM_IDLEST_DPLL_CORE_ST_CLK_MASK                                            (0x00000001U)
#define PRCM_CM_IDLEST_DPLL_CORE_ST_CLK_UNLOCKED                                         (0U)
#define PRCM_CM_IDLEST_DPLL_CORE_ST_CLK_LOCKED                                           (1U)

#define PRCM_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS_SHIFT                                     (8U)
#define PRCM_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS_MASK                                      (0x00000100U)
#define PRCM_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS_NO_MNBYPASS                                (0U)
#define PRCM_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS                                            (1U)

#define PRCM_CM_CLKSEL_DPLL_CORE_DIV_SHIFT                                              (0U)
#define PRCM_CM_CLKSEL_DPLL_CORE_DIV_MASK                                               (0x0000007fU)

#define PRCM_CM_CLKSEL_DPLL_CORE_MULT_SHIFT                                             (8U)
#define PRCM_CM_CLKSEL_DPLL_CORE_MULT_MASK                                              (0x0007ff00U)
#define PRCM_CM_CLKSEL_DPLL_CORE_MULT_RESERVED_0                                         (0U)
#define PRCM_CM_CLKSEL_DPLL_CORE_MULT_RESERVED_1                                         (1U)

#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_SHIFT                                (0U)
#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_MASK                                 (0x0000001fU)
#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_RESERVED                              (0U)

#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_DIVCHACK_SHIFT                       (5U)
#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_DIVCHACK_MASK                        (0x00000020U)

#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_GATE_CTRL_SHIFT                      (8U)
#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_GATE_CTRL_MASK                       (0x00000100U)
#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_GATE_CTRL_CLK_AUTOGATE                (0U)
#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_GATE_CTRL_CLK_ENABLE                  (1U)

#define PRCM_CM_DIV_M4_DPLL_CORE_ST_HSDIVIDER_CLKOUT1_SHIFT                             (9U)
#define PRCM_CM_DIV_M4_DPLL_CORE_ST_HSDIVIDER_CLKOUT1_MASK                              (0x00000200U)
#define PRCM_CM_DIV_M4_DPLL_CORE_ST_HSDIVIDER_CLKOUT1_DISABLED                           (0U)
#define PRCM_CM_DIV_M4_DPLL_CORE_ST_HSDIVIDER_CLKOUT1_ENABLED                            (1U)

#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_PWDN_SHIFT                           (12U)
#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_PWDN_MASK                            (0x00001000U)
#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_PWDN_ACTIVE                           (0U)
#define PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_PWDN_PWRDN                            (1U)

#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_SHIFT                                (0U)
#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_MASK                                 (0x0000001fU)
#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_RESERVED                              (0U)

#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_DIVCHACK_SHIFT                       (5U)
#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_DIVCHACK_MASK                        (0x00000020U)

#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_GATE_CTRL_SHIFT                      (8U)
#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_GATE_CTRL_MASK                       (0x00000100U)
#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_GATE_CTRL_CLK_AUTOGATE                (0U)
#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_GATE_CTRL_CLK_ENABLE                  (1U)

#define PRCM_CM_DIV_M5_DPLL_CORE_ST_HSDIVIDER_CLKOUT2_SHIFT                             (9U)
#define PRCM_CM_DIV_M5_DPLL_CORE_ST_HSDIVIDER_CLKOUT2_MASK                              (0x00000200U)
#define PRCM_CM_DIV_M5_DPLL_CORE_ST_HSDIVIDER_CLKOUT2_CLK_GATED                          (0U)
#define PRCM_CM_DIV_M5_DPLL_CORE_ST_HSDIVIDER_CLKOUT2_CLK_ENABLED                        (1U)

#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_PWDN_SHIFT                           (12U)
#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_PWDN_MASK                            (0x00001000U)
#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_PWDN_ACTIVE                           (0U)
#define PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_PWDN_PWRDN                            (1U)

#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_SHIFT                                (0U)
#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_MASK                                 (0x0000001fU)
#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_RESERVED                              (0U)

#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_DIVCHACK_SHIFT                       (5U)
#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_DIVCHACK_MASK                        (0x00000020U)

#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_GATE_CTRL_SHIFT                      (8U)
#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_GATE_CTRL_MASK                       (0x00000100U)
#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_GATE_CTRL_CLK_AUTOGATE                (0U)
#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_GATE_CTRL_CLK_ENABLE                  (1U)

#define PRCM_CM_DIV_M6_DPLL_CORE_ST_HSDIVIDER_CLKOUT3_SHIFT                             (9U)
#define PRCM_CM_DIV_M6_DPLL_CORE_ST_HSDIVIDER_CLKOUT3_MASK                              (0x00000200U)
#define PRCM_CM_DIV_M6_DPLL_CORE_ST_HSDIVIDER_CLKOUT3_GATED                              (0U)
#define PRCM_CM_DIV_M6_DPLL_CORE_ST_HSDIVIDER_CLKOUT3_ENABLED                            (1U)

#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_PWDN_SHIFT                           (12U)
#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_PWDN_MASK                            (0x00001000U)
#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_PWDN_ACTIVE                           (0U)
#define PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_PWDN_PWRDN                            (1U)

#define PRCM_CM_SSC_DELTAMSTEP_DPLL_CORE_SHIFT                                          (0U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_CORE_MASK                                           (0x000fffffU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_CORE_MANTISSA_SHIFT                                 (0U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_CORE_MANTISSA_MASK                                  (0x0000007fU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_CORE_EXPONENT_SHIFT                                 (8U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_CORE_EXPONENT_MASK                                  (0x00000700U)

#define PRCM_CM_CLKMODE_DPLL_MPU_EN_SHIFT                                               (0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_EN_MASK                                                (0x00000007U)
#define PRCM_CM_CLKMODE_DPLL_MPU_EN_RESERVED                                             (0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_EN_RESERVED1                                            (1U)
#define PRCM_CM_CLKMODE_DPLL_MPU_EN_RESERVED2                                            (2U)
#define PRCM_CM_CLKMODE_DPLL_MPU_EN_RESERVED3                                            (3U)
#define PRCM_CM_CLKMODE_DPLL_MPU_EN_MN_BYP_MODE                                          (4U)
#define PRCM_CM_CLKMODE_DPLL_MPU_EN_LP_BYP_MODE                                          (5U)
#define PRCM_CM_CLKMODE_DPLL_MPU_EN_FR_BYP_MODE                                          (6U)
#define PRCM_CM_CLKMODE_DPLL_MPU_EN_LOCK_MODE                                            (7U)

#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_SHIFT                                       (3U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_MASK                                        (0x00000018U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_DISABLE                                      (0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_ALGO1                                        (1U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_ALGO2                                        (2U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_RESERVED                                     (3U)

#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_SHIFT                                        (5U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_MASK                                         (0x000000e0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX2                                      (0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX4                                      (1U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX8                                      (2U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX16                                     (3U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX32                                     (4U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX64                                     (5U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX128                                    (6U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX512                                    (7U)

#define PRCM_CM_CLKMODE_DPLL_MPU_DRIFTGUARD_EN_SHIFT                                    (8U)
#define PRCM_CM_CLKMODE_DPLL_MPU_DRIFTGUARD_EN_MASK                                     (0x00000100U)
#define PRCM_CM_CLKMODE_DPLL_MPU_DRIFTGUARD_EN_ENABLED                                   (1U)
#define PRCM_CM_CLKMODE_DPLL_MPU_DRIFTGUARD_EN_DIASBLED                                  (0U)

#define PRCM_CM_CLKMODE_DPLL_MPU_RELOCK_RAMP_EN_SHIFT                                   (9U)
#define PRCM_CM_CLKMODE_DPLL_MPU_RELOCK_RAMP_EN_MASK                                    (0x00000200U)

#define PRCM_CM_CLKMODE_DPLL_MPU_LPMODE_EN_SHIFT                                        (10U)
#define PRCM_CM_CLKMODE_DPLL_MPU_LPMODE_EN_MASK                                         (0x00000400U)
#define PRCM_CM_CLKMODE_DPLL_MPU_LPMODE_EN_DISABLED                                      (0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_LPMODE_EN_ENABLED                                       (1U)

#define PRCM_CM_CLKMODE_DPLL_MPU_REGM4XEN_SHIFT                                         (11U)
#define PRCM_CM_CLKMODE_DPLL_MPU_REGM4XEN_MASK                                          (0x00000800U)
#define PRCM_CM_CLKMODE_DPLL_MPU_REGM4XEN_DISABLED                                       (0U)

#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_EN_SHIFT                                           (12U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_EN_MASK                                            (0x00001000U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_EN_DISABLED                                         (0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_EN_ENABLED                                          (1U)

#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_ACK_SHIFT                                          (13U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_ACK_MASK                                           (0x00002000U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_ACK_DISABLED                                        (0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_ACK_ENABLED                                         (1U)

#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_DOWNSPREAD_SHIFT                                   (14U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_DOWNSPREAD_MASK                                    (0x00004000U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_DOWNSPREAD_FULL_SPREAD                              (0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_DOWNSPREAD_LOW_SPREAD                               (1U)

#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_TYPE_SHIFT                                         (15U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_TYPE_MASK                                          (0x00008000U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_TYPE_TRIANGULAR                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_MPU_SSC_TYPE_SQUARE                                         (1U)

#define PRCM_CM_IDLEST_DPLL_MPU_ST_CLK_SHIFT                                            (0U)
#define PRCM_CM_IDLEST_DPLL_MPU_ST_CLK_MASK                                             (0x00000001U)
#define PRCM_CM_IDLEST_DPLL_MPU_ST_CLK_UNLOCKED                                          (0U)
#define PRCM_CM_IDLEST_DPLL_MPU_ST_CLK_LOCKED                                            (1U)

#define PRCM_CM_IDLEST_DPLL_MPU_ST_MN_BYPASS_SHIFT                                      (8U)
#define PRCM_CM_IDLEST_DPLL_MPU_ST_MN_BYPASS_MASK                                       (0x00000100U)
#define PRCM_CM_IDLEST_DPLL_MPU_ST_MN_BYPASS_NO_MNBYPASS                                 (0U)
#define PRCM_CM_IDLEST_DPLL_MPU_ST_MN_BYPASS                                             (1U)

#define PRCM_CM_CLKSEL_DPLL_MPU_DIV_SHIFT                                               (0U)
#define PRCM_CM_CLKSEL_DPLL_MPU_DIV_MASK                                                (0x0000007fU)

#define PRCM_CM_CLKSEL_DPLL_MPU_BYP_SHIFT                                               (23U)
#define PRCM_CM_CLKSEL_DPLL_MPU_BYP_MASK                                                (0x00800000U)
#define PRCM_CM_CLKSEL_DPLL_MPU_BYP_SEL0                                                 (0U)
#define PRCM_CM_CLKSEL_DPLL_MPU_BYP_SEL1                                                 (1U)

#define PRCM_CM_CLKSEL_DPLL_MPU_MULT_SHIFT                                              (8U)
#define PRCM_CM_CLKSEL_DPLL_MPU_MULT_MASK                                               (0x0007ff00U)
#define PRCM_CM_CLKSEL_DPLL_MPU_MULT_0                                                   (0U)
#define PRCM_CM_CLKSEL_DPLL_MPU_MULT_1                                                   (1U)

#define PRCM_CM_CLKSEL_DPLL_MPU_DCC_EN_SHIFT                                            (22U)
#define PRCM_CM_CLKSEL_DPLL_MPU_DCC_EN_MASK                                             (0x00400000U)
#define PRCM_CM_CLKSEL_DPLL_MPU_DCC_EN_DISABLED                                          (0U)
#define PRCM_CM_CLKSEL_DPLL_MPU_DCC_EN_ENABLED                                           (1U)

#define PRCM_CM_CLKSEL_DPLL_MPU_DCC_COUNT_MAX_SHIFT                                     (24U)
#define PRCM_CM_CLKSEL_DPLL_MPU_DCC_COUNT_MAX_MASK                                      (0xff000000U)

#define PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_SHIFT                                            (0U)
#define PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_MASK                                             (0x0000001fU)
#define PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_RESERVED                                          (0U)

#define PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_DIVCHACK_SHIFT                                   (5U)
#define PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_DIVCHACK_MASK                                    (0x00000020U)

#define PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_GATE_CTRL_SHIFT                                  (8U)
#define PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_GATE_CTRL_MASK                                   (0x00000100U)
#define PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_GATE_CTRL_CLK_AUTOGATE                            (0U)
#define PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_GATE_CTRL_CLK_ENABLE                              (1U)

#define PRCM_CM_DIV_M2_DPLL_MPU_ST_CLKOUT_SHIFT                                         (9U)
#define PRCM_CM_DIV_M2_DPLL_MPU_ST_CLKOUT_MASK                                          (0x00000200U)
#define PRCM_CM_DIV_M2_DPLL_MPU_ST_CLKOUT_CLK_ENABLED                                    (1U)
#define PRCM_CM_DIV_M2_DPLL_MPU_ST_CLKOUT_CLK_GATED                                      (0U)

#define PRCM_CM_SSC_DELTAMSTEP_DPLL_MPU_SHIFT                                           (0U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_MPU_MASK                                            (0x000fffffU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_MPU_MANTISSA_SHIFT                                  (0U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_MPU_MANTISSA_MASK                                   (0x0000007fU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_MPU_EXPONENT_SHIFT                                  (8U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_MPU_EXPONENT_MASK                                   (0x00000700U)

#define PRCM_CM_CLKMODE_DPLL_DDR_EN_SHIFT                                               (0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_EN_MASK                                                (0x00000007U)
#define PRCM_CM_CLKMODE_DPLL_DDR_EN_RESERVED                                             (0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_EN_RESERVED1                                            (1U)
#define PRCM_CM_CLKMODE_DPLL_DDR_EN_RESERVED2                                            (2U)
#define PRCM_CM_CLKMODE_DPLL_DDR_EN_RESERVED3                                            (3U)
#define PRCM_CM_CLKMODE_DPLL_DDR_EN_MN_BYP_MODE                                          (4U)
#define PRCM_CM_CLKMODE_DPLL_DDR_EN_LP_BYP_MODE                                          (5U)
#define PRCM_CM_CLKMODE_DPLL_DDR_EN_FR_BYP_MODE                                          (6U)
#define PRCM_CM_CLKMODE_DPLL_DDR_EN_LOCK_MODE                                            (7U)

#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_LEVEL_SHIFT                                       (3U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_LEVEL_MASK                                        (0x00000018U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_LEVEL_DISABLE                                      (0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_LEVEL_ALGO1                                        (1U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_LEVEL_ALGO2                                        (2U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_LEVEL_RESERVED                                     (3U)

#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_SHIFT                                        (5U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_MASK                                         (0x000000e0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_REFCLKX2                                      (0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_REFCLKX4                                      (1U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_REFCLKX8                                      (2U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_REFCLKX16                                     (3U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_REFCLKX32                                     (4U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_REFCLKX64                                     (5U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_REFCLKX128                                    (6U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RAMP_RATE_REFCLKX512                                    (7U)

#define PRCM_CM_CLKMODE_DPLL_DDR_DRIFTGUARD_EN_SHIFT                                    (8U)
#define PRCM_CM_CLKMODE_DPLL_DDR_DRIFTGUARD_EN_MASK                                     (0x00000100U)
#define PRCM_CM_CLKMODE_DPLL_DDR_DRIFTGUARD_EN_ENABLED                                   (1U)
#define PRCM_CM_CLKMODE_DPLL_DDR_DRIFTGUARD_EN_DIASBLED                                  (0U)

#define PRCM_CM_CLKMODE_DPLL_DDR_RELOCK_RAMP_EN_SHIFT                                   (9U)
#define PRCM_CM_CLKMODE_DPLL_DDR_RELOCK_RAMP_EN_MASK                                    (0x00000200U)

#define PRCM_CM_CLKMODE_DPLL_DDR_LPMODE_EN_SHIFT                                        (10U)
#define PRCM_CM_CLKMODE_DPLL_DDR_LPMODE_EN_MASK                                         (0x00000400U)
#define PRCM_CM_CLKMODE_DPLL_DDR_LPMODE_EN_DISABLED                                      (0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_LPMODE_EN_ENABLED                                       (1U)

#define PRCM_CM_CLKMODE_DPLL_DDR_REGM4XEN_SHIFT                                         (11U)
#define PRCM_CM_CLKMODE_DPLL_DDR_REGM4XEN_MASK                                          (0x00000800U)
#define PRCM_CM_CLKMODE_DPLL_DDR_REGM4XEN_DISABLED                                       (0U)

#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_EN_SHIFT                                           (12U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_EN_MASK                                            (0x00001000U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_EN_DISABLED                                         (0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_EN_ENABLED                                          (1U)

#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_ACK_SHIFT                                          (13U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_ACK_MASK                                           (0x00002000U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_ACK_DISABLED                                        (0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_ACK_ENABLED                                         (1U)

#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_DOWNSPREAD_SHIFT                                   (14U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_DOWNSPREAD_MASK                                    (0x00004000U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_DOWNSPREAD_FULL_SPREAD                              (0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_DOWNSPREAD_LOW_SPREAD                               (1U)

#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_TYPE_SHIFT                                         (15U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_TYPE_MASK                                          (0x00008000U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_TYPE_TRIANGULAR                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_DDR_SSC_TYPE_SQUARE                                         (1U)

#define PRCM_CM_IDLEST_DPLL_DDR_ST_CLK_SHIFT                                            (0U)
#define PRCM_CM_IDLEST_DPLL_DDR_ST_CLK_MASK                                             (0x00000001U)
#define PRCM_CM_IDLEST_DPLL_DDR_ST_CLK_UNLOCKED                                          (0U)
#define PRCM_CM_IDLEST_DPLL_DDR_ST_CLK_LOCKED                                            (1U)

#define PRCM_CM_IDLEST_DPLL_DDR_ST_MN_BYPASS_SHIFT                                      (8U)
#define PRCM_CM_IDLEST_DPLL_DDR_ST_MN_BYPASS_MASK                                       (0x00000100U)
#define PRCM_CM_IDLEST_DPLL_DDR_ST_MN_BYPASS_NO_MNBYPASS                                 (0U)
#define PRCM_CM_IDLEST_DPLL_DDR_ST_MN_BYPASS                                             (1U)

#define PRCM_CM_CLKSEL_DPLL_DDR_DIV_SHIFT                                               (0U)
#define PRCM_CM_CLKSEL_DPLL_DDR_DIV_MASK                                                (0x0000007fU)

#define PRCM_CM_CLKSEL_DPLL_DDR_BYP_SHIFT                                               (23U)
#define PRCM_CM_CLKSEL_DPLL_DDR_BYP_MASK                                                (0x00800000U)
#define PRCM_CM_CLKSEL_DPLL_DDR_BYP_SEL0                                                 (0U)
#define PRCM_CM_CLKSEL_DPLL_DDR_BYP_SEL1                                                 (1U)

#define PRCM_CM_CLKSEL_DPLL_DDR_MULT_SHIFT                                              (8U)
#define PRCM_CM_CLKSEL_DPLL_DDR_MULT_MASK                                               (0x0007ff00U)
#define PRCM_CM_CLKSEL_DPLL_DDR_MULT_0                                                   (0U)
#define PRCM_CM_CLKSEL_DPLL_DDR_MULT_1                                                   (1U)

#define PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_SHIFT                                            (0U)
#define PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_MASK                                             (0x0000001fU)
#define PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_RESERVED                                          (0U)

#define PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_DIVCHACK_SHIFT                                   (5U)
#define PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_DIVCHACK_MASK                                    (0x00000020U)

#define PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_GATE_CTRL_SHIFT                                  (8U)
#define PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_GATE_CTRL_MASK                                   (0x00000100U)
#define PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_GATE_CTRL_CLK_AUTOGATE                            (0U)
#define PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_GATE_CTRL_CLK_ENABLE                              (1U)

#define PRCM_CM_DIV_M2_DPLL_DDR_ST_CLKOUT_SHIFT                                         (9U)
#define PRCM_CM_DIV_M2_DPLL_DDR_ST_CLKOUT_MASK                                          (0x00000200U)
#define PRCM_CM_DIV_M2_DPLL_DDR_ST_CLKOUT_CLK_ENABLED                                    (1U)
#define PRCM_CM_DIV_M2_DPLL_DDR_ST_CLKOUT_CLK_GATED                                      (0U)

#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_SHIFT                                 (0U)
#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_MASK                                  (0x0000001fU)
#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_RESERVED                               (0U)

#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_DIVCHACK_SHIFT                        (5U)
#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_DIVCHACK_MASK                         (0x00000020U)

#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_GATE_CTRL_SHIFT                       (8U)
#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_GATE_CTRL_MASK                        (0x00000100U)
#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_GATE_CTRL_CLK_AUTOGATE                 (0U)
#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_GATE_CTRL_CLK_ENABLE                   (1U)

#define PRCM_CM_DIV_M4_DPLL_DDR_ST_HSDIVIDER_CLKOUT1_SHIFT                              (9U)
#define PRCM_CM_DIV_M4_DPLL_DDR_ST_HSDIVIDER_CLKOUT1_MASK                               (0x00000200U)
#define PRCM_CM_DIV_M4_DPLL_DDR_ST_HSDIVIDER_CLKOUT1_DISABLED                            (0U)
#define PRCM_CM_DIV_M4_DPLL_DDR_ST_HSDIVIDER_CLKOUT1_ENABLED                             (1U)

#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_PWDN_SHIFT                            (12U)
#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_PWDN_MASK                             (0x00001000U)
#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_PWDN_ACTIVE                            (0U)
#define PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_PWDN_PWRDN                             (1U)

#define PRCM_CM_SSC_DELTAMSTEP_DPLL_DDR_SHIFT                                           (0U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_DDR_MASK                                            (0x000fffffU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_DDR_MANTISSA_SHIFT                                  (0U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_DDR_MANTISSA_MASK                                   (0x0000007fU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_DDR_EXPONENT_SHIFT                                  (8U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_DDR_EXPONENT_MASK                                   (0x00000700U)

#define PRCM_CM_CLKMODE_DPLL_PER_SSC_EN_SHIFT                                           (12U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_EN_MASK                                            (0x00001000U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_EN_DISABLED                                         (0U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_EN_ENABLED                                          (1U)

#define PRCM_CM_CLKMODE_DPLL_PER_SSC_ACK_SHIFT                                          (13U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_ACK_MASK                                           (0x00002000U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_ACK_DISABLED                                        (0U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_ACK_ENABLED                                         (1U)

#define PRCM_CM_CLKMODE_DPLL_PER_SSC_DOWNSPREAD_SHIFT                                   (14U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_DOWNSPREAD_MASK                                    (0x00004000U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_DOWNSPREAD_FULL_SPREAD                              (0U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_DOWNSPREAD_LOW_SPREAD                               (1U)

#define PRCM_CM_CLKMODE_DPLL_PER_SSC_TYPE_SHIFT                                         (15U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_TYPE_MASK                                          (0x00008000U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_TYPE_TRIANGULAR                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_PER_SSC_TYPE_SQUARE                                         (1U)

#define PRCM_CM_CLKMODE_DPLL_PER_EN_SHIFT                                               (0U)
#define PRCM_CM_CLKMODE_DPLL_PER_EN_MASK                                                (0x00000007U)
#define PRCM_CM_CLKMODE_DPLL_PER_EN_RESERVED                                             (0U)
#define PRCM_CM_CLKMODE_DPLL_PER_EN_RESERVED1                                            (1U)
#define PRCM_CM_CLKMODE_DPLL_PER_EN_RESERVED2                                            (2U)
#define PRCM_CM_CLKMODE_DPLL_PER_EN_RESERVED3                                            (3U)
#define PRCM_CM_CLKMODE_DPLL_PER_EN_MN_BYP_MODE                                          (4U)
#define PRCM_CM_CLKMODE_DPLL_PER_EN_LP_BYP_MODE                                          (5U)
#define PRCM_CM_CLKMODE_DPLL_PER_EN_RESERVED6                                            (6U)
#define PRCM_CM_CLKMODE_DPLL_PER_EN_LOCK_MODE                                            (7U)

#define PRCM_CM_IDLEST_DPLL_PER_ST_CLK_SHIFT                                            (0U)
#define PRCM_CM_IDLEST_DPLL_PER_ST_CLK_MASK                                             (0x00000001U)
#define PRCM_CM_IDLEST_DPLL_PER_ST_CLK_UNLOCKED                                          (0U)
#define PRCM_CM_IDLEST_DPLL_PER_ST_CLK_LOCKED                                            (1U)

#define PRCM_CM_IDLEST_DPLL_PER_ST_MN_BYPASS_SHIFT                                      (8U)
#define PRCM_CM_IDLEST_DPLL_PER_ST_MN_BYPASS_MASK                                       (0x00000100U)
#define PRCM_CM_IDLEST_DPLL_PER_ST_MN_BYPASS_NO_MNBYPASS                                 (0U)
#define PRCM_CM_IDLEST_DPLL_PER_ST_MN_BYPASS                                             (1U)

#define PRCM_CM_CLKSEL_DPLL_PER_DIV_SHIFT                                               (0U)
#define PRCM_CM_CLKSEL_DPLL_PER_DIV_MASK                                                (0x000000ffU)

#define PRCM_CM_CLKSEL_DPLL_PER_MULT_SHIFT                                              (8U)
#define PRCM_CM_CLKSEL_DPLL_PER_MULT_MASK                                               (0x000fff00U)
#define PRCM_CM_CLKSEL_DPLL_PER_MULT_0                                                   (0U)
#define PRCM_CM_CLKSEL_DPLL_PER_MULT_1                                                   (1U)

#define PRCM_CM_CLKSEL_DPLL_PER_SD_DIV_SHIFT                                            (24U)
#define PRCM_CM_CLKSEL_DPLL_PER_SD_DIV_MASK                                             (0xff000000U)
#define PRCM_CM_CLKSEL_DPLL_PER_SD_DIV_RESERVED                                          (0U)
#define PRCM_CM_CLKSEL_DPLL_PER_SD_DIV_RESERVED1                                         (1U)

#define PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_SHIFT                                            (0U)
#define PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_MASK                                             (0x0000007fU)
#define PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_RESERVED                                          (0U)

#define PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_DIVCHACK_SHIFT                                   (7U)
#define PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_DIVCHACK_MASK                                    (0x00000080U)

#define PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_GATE_CTRL_SHIFT                                  (8U)
#define PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_GATE_CTRL_MASK                                   (0x00000100U)
#define PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_GATE_CTRL_CLK_AUTOGATE                            (0U)
#define PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_GATE_CTRL_CLK_ENABLE                              (1U)

#define PRCM_CM_DIV_M2_DPLL_PER_ST_CLKOUT_SHIFT                                         (9U)
#define PRCM_CM_DIV_M2_DPLL_PER_ST_CLKOUT_MASK                                          (0x00000200U)
#define PRCM_CM_DIV_M2_DPLL_PER_ST_CLKOUT_CLK_ENABLED                                    (1U)
#define PRCM_CM_DIV_M2_DPLL_PER_ST_CLKOUT_CLK_GATED                                      (0U)

#define PRCM_CM_CLKSEL2_DPLL_PER_MULT_FRAC_SHIFT                                        (0U)
#define PRCM_CM_CLKSEL2_DPLL_PER_MULT_FRAC_MASK                                         (0x0003ffffU)

#define PRCM_CM_CLKSEL2_DPLL_PER_BW_INCR_DECRZ_SHIFT                                    (22U)
#define PRCM_CM_CLKSEL2_DPLL_PER_BW_INCR_DECRZ_MASK                                     (0x00400000U)
#define PRCM_CM_CLKSEL2_DPLL_PER_BW_INCR_DECRZ_DEC                                       (0U)
#define PRCM_CM_CLKSEL2_DPLL_PER_BW_INCR_DECRZ                                           (1U)

#define PRCM_CM_CLKSEL2_DPLL_PER_BW_CTRL_SHIFT                                          (24U)
#define PRCM_CM_CLKSEL2_DPLL_PER_BW_CTRL_MASK                                           (0x03000000U)
#define PRCM_CM_CLKSEL2_DPLL_PER_BW_CTRL_SEL0                                            (0U)
#define PRCM_CM_CLKSEL2_DPLL_PER_BW_CTRL_SEL1                                            (1U)
#define PRCM_CM_CLKSEL2_DPLL_PER_BW_CTRL_SEL2                                            (2U)
#define PRCM_CM_CLKSEL2_DPLL_PER_BW_CTRL_SEL3                                            (3U)

#define PRCM_CM_SSC_DELTAMSTEP_DPLL_PER_SHIFT                                           (0U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_PER_MASK                                            (0x000fffffU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_PER_MANTISSA_SHIFT                                  (0U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_PER_MANTISSA_MASK                                   (0x0000007fU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_PER_EXPONENT_SHIFT                                  (8U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_PER_EXPONENT_MASK                                   (0x00000700U)

#define PRCM_CM_CLKDCOLDO_DPLL_PER_GATE_CTRL_SHIFT                                      (8U)
#define PRCM_CM_CLKDCOLDO_DPLL_PER_GATE_CTRL_MASK                                       (0x00000100U)
#define PRCM_CM_CLKDCOLDO_DPLL_PER_GATE_CTRL_CLK_AUTOGATE                                (0U)
#define PRCM_CM_CLKDCOLDO_DPLL_PER_GATE_CTRL_CLK_ENABLE                                  (1U)

#define PRCM_CM_CLKDCOLDO_DPLL_PER_ST_SHIFT                                             (9U)
#define PRCM_CM_CLKDCOLDO_DPLL_PER_ST_MASK                                              (0x00000200U)
#define PRCM_CM_CLKDCOLDO_DPLL_PER_ST_CLK_GATED                                          (0U)
#define PRCM_CM_CLKDCOLDO_DPLL_PER_ST_CLK_ENABLED                                        (1U)

#define PRCM_CM_CLKDCOLDO_DPLL_PER_PWDN_SHIFT                                           (12U)
#define PRCM_CM_CLKDCOLDO_DPLL_PER_PWDN_MASK                                            (0x00001000U)
#define PRCM_CM_CLKDCOLDO_DPLL_PER_PWDN_ACTIVE                                           (0U)
#define PRCM_CM_CLKDCOLDO_DPLL_PER_PWDN_PWRDN                                            (1U)

#define PRCM_CM_CLKMODE_DPLL_DISP_EN_SHIFT                                              (0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_EN_MASK                                               (0x00000007U)
#define PRCM_CM_CLKMODE_DPLL_DISP_EN_RESERVED                                            (0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_EN_RESERVED1                                           (1U)
#define PRCM_CM_CLKMODE_DPLL_DISP_EN_RESERVED2                                           (2U)
#define PRCM_CM_CLKMODE_DPLL_DISP_EN_RESERVED3                                           (3U)
#define PRCM_CM_CLKMODE_DPLL_DISP_EN_MN_BYP_MODE                                         (4U)
#define PRCM_CM_CLKMODE_DPLL_DISP_EN_LP_BYP_MODE                                         (5U)
#define PRCM_CM_CLKMODE_DPLL_DISP_EN_FR_BYP_MODE                                         (6U)
#define PRCM_CM_CLKMODE_DPLL_DISP_EN_LOCK_MODE                                           (7U)

#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_LEVEL_SHIFT                                      (3U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_LEVEL_MASK                                       (0x00000018U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_LEVEL_DISABLE                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_LEVEL_ALGO1                                       (1U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_LEVEL_ALGO2                                       (2U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_LEVEL_RESERVED                                    (3U)

#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_SHIFT                                       (5U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_MASK                                        (0x000000e0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_REFCLKX2                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_REFCLKX4                                     (1U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_REFCLKX8                                     (2U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_REFCLKX16                                    (3U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_REFCLKX32                                    (4U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_REFCLKX64                                    (5U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_REFCLKX128                                   (6U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RAMP_RATE_REFCLKX512                                   (7U)

#define PRCM_CM_CLKMODE_DPLL_DISP_DRIFTGUARD_EN_SHIFT                                   (8U)
#define PRCM_CM_CLKMODE_DPLL_DISP_DRIFTGUARD_EN_MASK                                    (0x00000100U)
#define PRCM_CM_CLKMODE_DPLL_DISP_DRIFTGUARD_EN_ENABLED                                  (1U)
#define PRCM_CM_CLKMODE_DPLL_DISP_DRIFTGUARD_EN_DIASBLED                                 (0U)

#define PRCM_CM_CLKMODE_DPLL_DISP_RELOCK_RAMP_EN_SHIFT                                  (9U)
#define PRCM_CM_CLKMODE_DPLL_DISP_RELOCK_RAMP_EN_MASK                                   (0x00000200U)

#define PRCM_CM_CLKMODE_DPLL_DISP_LPMODE_EN_SHIFT                                       (10U)
#define PRCM_CM_CLKMODE_DPLL_DISP_LPMODE_EN_MASK                                        (0x00000400U)
#define PRCM_CM_CLKMODE_DPLL_DISP_LPMODE_EN_DISABLED                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_LPMODE_EN_ENABLED                                      (1U)

#define PRCM_CM_CLKMODE_DPLL_DISP_REGM4XEN_SHIFT                                        (11U)
#define PRCM_CM_CLKMODE_DPLL_DISP_REGM4XEN_MASK                                         (0x00000800U)
#define PRCM_CM_CLKMODE_DPLL_DISP_REGM4XEN_DISABLED                                      (0U)

#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_EN_SHIFT                                          (12U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_EN_MASK                                           (0x00001000U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_EN_DISABLED                                        (0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_EN_ENABLED                                         (1U)

#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_ACK_SHIFT                                         (13U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_ACK_MASK                                          (0x00002000U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_ACK_DISABLED                                       (0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_ACK_ENABLED                                        (1U)

#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_DOWNSPREAD_SHIFT                                  (14U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_DOWNSPREAD_MASK                                   (0x00004000U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_DOWNSPREAD_FULL_SPREAD                             (0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_DOWNSPREAD_LOW_SPREAD                              (1U)

#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_TYPE_SHIFT                                        (15U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_TYPE_MASK                                         (0x00008000U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_TYPE_TRIANGULAR                                    (0U)
#define PRCM_CM_CLKMODE_DPLL_DISP_SSC_TYPE_SQUARE                                        (1U)

#define PRCM_CM_IDLEST_DPLL_DISP_ST_CLK_SHIFT                                           (0U)
#define PRCM_CM_IDLEST_DPLL_DISP_ST_CLK_MASK                                            (0x00000001U)
#define PRCM_CM_IDLEST_DPLL_DISP_ST_CLK_UNLOCKED                                         (0U)
#define PRCM_CM_IDLEST_DPLL_DISP_ST_CLK_LOCKED                                           (1U)

#define PRCM_CM_IDLEST_DPLL_DISP_ST_MN_BYPASS_SHIFT                                     (8U)
#define PRCM_CM_IDLEST_DPLL_DISP_ST_MN_BYPASS_MASK                                      (0x00000100U)
#define PRCM_CM_IDLEST_DPLL_DISP_ST_MN_BYPASS_NO_MNBYPASS                                (0U)
#define PRCM_CM_IDLEST_DPLL_DISP_ST_MN_BYPASS                                            (1U)

#define PRCM_CM_CLKSEL_DPLL_DISP_DIV_SHIFT                                              (0U)
#define PRCM_CM_CLKSEL_DPLL_DISP_DIV_MASK                                               (0x0000007fU)

#define PRCM_CM_CLKSEL_DPLL_DISP_BYP_SHIFT                                              (23U)
#define PRCM_CM_CLKSEL_DPLL_DISP_BYP_MASK                                               (0x00800000U)
#define PRCM_CM_CLKSEL_DPLL_DISP_BYP_SEL0                                                (0U)
#define PRCM_CM_CLKSEL_DPLL_DISP_BYP_SEL1                                                (1U)

#define PRCM_CM_CLKSEL_DPLL_DISP_MULT_SHIFT                                             (8U)
#define PRCM_CM_CLKSEL_DPLL_DISP_MULT_MASK                                              (0x0007ff00U)
#define PRCM_CM_CLKSEL_DPLL_DISP_MULT_0                                                  (0U)
#define PRCM_CM_CLKSEL_DPLL_DISP_MULT_1                                                  (1U)

#define PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_SHIFT                                           (0U)
#define PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_MASK                                            (0x0000001fU)
#define PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_RESERVED                                         (0U)

#define PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_DIVCHACK_SHIFT                                  (5U)
#define PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_DIVCHACK_MASK                                   (0x00000020U)

#define PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_GATE_CTRL_SHIFT                                 (8U)
#define PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_GATE_CTRL_MASK                                  (0x00000100U)
#define PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_GATE_CTRL_CLK_AUTOGATE                           (0U)
#define PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_GATE_CTRL_CLK_ENABLE                             (1U)

#define PRCM_CM_DIV_M2_DPLL_DISP_ST_CLKOUT_SHIFT                                        (9U)
#define PRCM_CM_DIV_M2_DPLL_DISP_ST_CLKOUT_MASK                                         (0x00000200U)
#define PRCM_CM_DIV_M2_DPLL_DISP_ST_CLKOUT_CLK_ENABLED                                   (1U)
#define PRCM_CM_DIV_M2_DPLL_DISP_ST_CLKOUT_CLK_GATED                                     (0U)

#define PRCM_CM_SSC_DELTAMSTEP_DPLL_DISP_SHIFT                                          (0U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_DISP_MASK                                           (0x000fffffU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_DISP_MANTISSA_SHIFT                                 (0U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_DISP_MANTISSA_MASK                                  (0x0000007fU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_DISP_EXPONENT_SHIFT                                 (8U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_DISP_EXPONENT_MASK                                  (0x00000700U)

#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_EN_SHIFT                                        (12U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_EN_MASK                                         (0x00001000U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_EN_DISABLED                                      (0U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_EN_ENABLED                                       (1U)

#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_ACK_SHIFT                                       (13U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_ACK_MASK                                        (0x00002000U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_ACK_DISABLED                                     (0U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_ACK_ENABLED                                      (1U)

#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_DOWNSPREAD_SHIFT                                (14U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_DOWNSPREAD_MASK                                 (0x00004000U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_DOWNSPREAD_FULL_SPREAD                           (0U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_DOWNSPREAD_LOW_SPREAD                            (1U)

#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_TYPE_SHIFT                                      (15U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_TYPE_MASK                                       (0x00008000U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_TYPE_TRIANGULAR                                  (0U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_SSC_TYPE_SQUARE                                      (1U)

#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_SHIFT                                            (0U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_MASK                                             (0x00000007U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_RESERVED                                          (0U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_RESERVED1                                         (1U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_RESERVED2                                         (2U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_RESERVED3                                         (3U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_MN_BYP_MODE                                       (4U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_LP_BYP_MODE                                       (5U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_RESERVED6                                         (6U)
#define PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_LOCK_MODE                                         (7U)

#define PRCM_CM_IDLEST_DPLL_EXTDEV_ST_CLK_SHIFT                                         (0U)
#define PRCM_CM_IDLEST_DPLL_EXTDEV_ST_CLK_MASK                                          (0x00000001U)
#define PRCM_CM_IDLEST_DPLL_EXTDEV_ST_CLK_UNLOCKED                                       (0U)
#define PRCM_CM_IDLEST_DPLL_EXTDEV_ST_CLK_LOCKED                                         (1U)

#define PRCM_CM_IDLEST_DPLL_EXTDEV_ST_MN_BYPASS_SHIFT                                   (8U)
#define PRCM_CM_IDLEST_DPLL_EXTDEV_ST_MN_BYPASS_MASK                                    (0x00000100U)
#define PRCM_CM_IDLEST_DPLL_EXTDEV_ST_MN_BYPASS_NO_MNBYPASS                              (0U)
#define PRCM_CM_IDLEST_DPLL_EXTDEV_ST_MN_BYPASS                                          (1U)

#define PRCM_CM_CLKSEL_DPLL_EXTDEV_DIV_SHIFT                                            (0U)
#define PRCM_CM_CLKSEL_DPLL_EXTDEV_DIV_MASK                                             (0x000000ffU)

#define PRCM_CM_CLKSEL_DPLL_EXTDEV_MULT_SHIFT                                           (8U)
#define PRCM_CM_CLKSEL_DPLL_EXTDEV_MULT_MASK                                            (0x000fff00U)
#define PRCM_CM_CLKSEL_DPLL_EXTDEV_MULT_0                                                (0U)
#define PRCM_CM_CLKSEL_DPLL_EXTDEV_MULT_1                                                (1U)

#define PRCM_CM_CLKSEL_DPLL_EXTDEV_SD_DIV_SHIFT                                         (24U)
#define PRCM_CM_CLKSEL_DPLL_EXTDEV_SD_DIV_MASK                                          (0xff000000U)
#define PRCM_CM_CLKSEL_DPLL_EXTDEV_SD_DIV_RESERVED                                       (0U)
#define PRCM_CM_CLKSEL_DPLL_EXTDEV_SD_DIV_RESERVED1                                      (1U)

#define PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_SHIFT                                         (0U)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_MASK                                          (0x0000007fU)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_RESERVED                                       (0U)

#define PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_DIVCHACK_SHIFT                                (7U)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_DIVCHACK_MASK                                 (0x00000080U)

#define PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_GATE_CTRL_SHIFT                               (8U)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_GATE_CTRL_MASK                                (0x00000100U)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_GATE_CTRL_CLK_AUTOGATE                         (0U)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_GATE_CTRL_CLK_ENABLE                           (1U)

#define PRCM_CM_DIV_M2_DPLL_EXTDEV_ST_CLKOUT_SHIFT                                      (9U)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV_ST_CLKOUT_MASK                                       (0x00000200U)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV_ST_CLKOUT_CLK_ENABLED                                 (1U)
#define PRCM_CM_DIV_M2_DPLL_EXTDEV_ST_CLKOUT_CLK_GATED                                   (0U)

#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_MULT_FRAC_SHIFT                                     (0U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_MULT_FRAC_MASK                                      (0x0003ffffU)

#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_SHIFT                                    (18U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_MASK                                     (0x001c0000U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_RESERVED                                  (0U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_RESERVED1                                 (1U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_SEL1                                      (2U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_RESERVED3                                 (3U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_SEL2                                      (4U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_RESERVED4                                 (5U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_RESERVED5                                 (6U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_FREQSELDCO_RESERVED6                                 (7U)

#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_INCR_DECRZ_SHIFT                                 (22U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_INCR_DECRZ_MASK                                  (0x00400000U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_INCR_DECRZ_DEC                                    (0U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_INCR_DECRZ                                        (1U)

#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_CTRL_SHIFT                                       (24U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_CTRL_MASK                                        (0x03000000U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_CTRL_SEL0                                         (0U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_CTRL_SEL1                                         (1U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_CTRL_SEL2                                         (2U)
#define PRCM_CM_CLKSEL2_DPLL_EXTDEV_BW_CTRL_SEL3                                         (3U)

#define PRCM_CM_SSC_DELTAMSTEP_DPLL_EXTDEV_SHIFT                                        (0U)
#define PRCM_CM_SSC_DELTAMSTEP_DPLL_EXTDEV_MASK                                         (0x000fffffU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_EXTDEV_MANTISSA_SHIFT                               (0U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_EXTDEV_MANTISSA_MASK                                (0x0000007fU)

#define PRCM_CM_SSC_MODFREQDIV_DPLL_EXTDEV_EXPONENT_SHIFT                               (8U)
#define PRCM_CM_SSC_MODFREQDIV_DPLL_EXTDEV_EXPONENT_MASK                                (0x00000700U)

#define PRCM_CM_SHADOW_FREQ_CONFIG1_UPDATE_SHIFT                                        (0U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_UPDATE_MASK                                         (0x00000001U)

#define PRCM_CM_SHADOW_FREQ_CONFIG1_RSVD1_SHIFT                                         (1U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_RSVD1_MASK                                          (0x00000002U)

#define PRCM_CM_SHADOW_FREQ_CONFIG1_DLL_OVERRIDE_SHIFT                                  (2U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DLL_OVERRIDE_MASK                                   (0x00000004U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DLL_OVERRIDE_NO_OVR                                  (0U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DLL_OVERRIDE_OVR                                     (1U)

#define PRCM_CM_SHADOW_FREQ_CONFIG1_DLL_RESET_SHIFT                                     (3U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DLL_RESET_MASK                                      (0x00000008U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DLL_RESET_NO                                         (0U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DLL_RESET                                            (1U)

#define PRCM_CM_SHADOW_FREQ_CONFIG1_RSVD2_SHIFT                                         (4U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_RSVD2_MASK                                          (0x000000f0U)

#define PRCM_CM_SHADOW_FREQ_CONFIG1_RSVD5_SHIFT                                         (16U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_RSVD5_MASK                                          (0xffff0000U)

#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_SHIFT                                   (8U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_MASK                                    (0x00000700U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_RESERVED                                 (0U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_RESERVED1                                (1U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_RESERVED2                                (2U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_RESERVED3                                (3U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_MN_BYP_MODE                              (4U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_LP_BYP_MODE                              (5U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_FR_BYP_MODE                              (6U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_EN_LOCK_MODE                                (7U)

#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_M2_DIV_SHIFT                               (11U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_M2_DIV_MASK                                (0x0000f800U)
#define PRCM_CM_SHADOW_FREQ_CONFIG1_DPLL_DDR_M2_DIV_RESERVED                             (0U)

#define PRCM_CM_SHADOW_FREQ_CONFIG2_GPMC_UPDATE_SHIFT                                   (0U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_GPMC_UPDATE_MASK                                    (0x00000001U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_GPMC_UPDATE_DISABLED                                 (0U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_GPMC_UPDATE_ENABLED                                  (1U)

#define PRCM_CM_SHADOW_FREQ_CONFIG2_RSVD1_SHIFT                                         (1U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_RSVD1_MASK                                          (0x00000002U)

#define PRCM_CM_SHADOW_FREQ_CONFIG2_RSVD5_SHIFT                                         (7U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_RSVD5_MASK                                          (0x00000080U)

#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_M4_DIV_SHIFT                              (2U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_M4_DIV_MASK                               (0x0000007cU)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_M4_DIV_RESERVED                            (0U)

#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_SHIFT                                  (8U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_MASK                                   (0x00000700U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_RESERVED                                (0U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_RESERVED1                               (1U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_RESERVED2                               (2U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_RESERVED3                               (3U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_MN_BYP_MODE                             (4U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_LP_BYP_MODE                             (5U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_FR_BYP_MODE                             (6U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_DPLL_CORE_EN_LOCK_MODE                               (7U)

#define PRCM_CM_SHADOW_FREQ_CONFIG2_RSVD6_SHIFT                                         (11U)
#define PRCM_CM_SHADOW_FREQ_CONFIG2_RSVD6_MASK                                          (0xfffff800U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CM_WKUP_H_ */

