/*
* hw_prm_wkup.h
*
* Register-level header file for PRM_WKUP
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

#ifndef HW_PRM_WKUP_H_
#define HW_PRM_WKUP_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/

#define PRCM_RM_WKUP_RSTCTRL                                        (0x0U)
#define PRCM_RM_WKUP_RSTST                                          (0x4U)
#define PRCM_RM_WKUP_DBGSS_CONTEXT                                  (0x14U)
#define PRCM_RM_WKUP_ADC_TSC_CONTEXT                                (0x114U)
#define PRCM_RM_WKUP_L4WKUP_CONTEXT                                 (0x214U)
#define PRCM_RM_WKUP_M3_CONTEXT                                     (0x21cU)
#define PRCM_RM_WKUP_SYNCTIMER_CONTEXT                              (0x224U)
#define PRCM_RM_WKUP_TIMER0_CONTEXT                                 (0x314U)
#define PRCM_RM_WKUP_TIMER1_CONTEXT                                 (0x31cU)
#define PRCM_RM_WKUP_WDT0_CONTEXT                                   (0x324U)
#define PRCM_RM_WKUP_WDT1_CONTEXT                                   (0x32cU)
#define PRCM_RM_WKUP_I2C0_CONTEXT                                   (0x334U)
#define PRCM_RM_WKUP_UART0_CONTEXT                                  (0x33cU)
#define PRCM_RM_WKUP_SMARTREFLEX0_CONTEXT                           (0x344U)
#define PRCM_RM_WKUP_SMARTREFLEX1_CONTEXT                           (0x34cU)
#define PRCM_RM_WKUP_GPIO0_CONTEXT                                  (0x35cU)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define PRCM_RM_WKUP_RSTCTRL_M3_LRST_SHIFT                                              (3U)
#define PRCM_RM_WKUP_RSTCTRL_M3_LRST_MASK                                               (0x00000008U)
#define PRCM_RM_WKUP_RSTCTRL_M3_LRST_ASSERT                                              (1U)
#define PRCM_RM_WKUP_RSTCTRL_M3_LRST_CLEAR                                               (0U)

#define PRCM_RM_WKUP_RSTST_M3_LRST_SHIFT                                                (5U)
#define PRCM_RM_WKUP_RSTST_M3_LRST_MASK                                                 (0x00000020U)
#define PRCM_RM_WKUP_RSTST_M3_LRST_RESET_YES                                             (1U)
#define PRCM_RM_WKUP_RSTST_M3_LRST_RESET_NO                                              (0U)

#define PRCM_RM_WKUP_RSTST_EMULATION_M3_RST_SHIFT                                       (6U)
#define PRCM_RM_WKUP_RSTST_EMULATION_M3_RST_MASK                                        (0x00000040U)
#define PRCM_RM_WKUP_RSTST_EMULATION_M3_RST_RESET_YES                                    (1U)
#define PRCM_RM_WKUP_RSTST_EMULATION_M3_RST_RESET_NO                                     (0U)

#define PRCM_RM_WKUP_RSTST_ICECRUSHER_M3_RST_SHIFT                                      (7U)
#define PRCM_RM_WKUP_RSTST_ICECRUSHER_M3_RST_MASK                                       (0x00000080U)
#define PRCM_RM_WKUP_RSTST_ICECRUSHER_M3_RST_RESET_YES                                   (1U)
#define PRCM_RM_WKUP_RSTST_ICECRUSHER_M3_RST_RESET_NO                                    (0U)

#define PRCM_RM_WKUP_DBGSS_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_WKUP_DBGSS_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_WKUP_DBGSS_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_WKUP_DBGSS_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_WKUP_DBGSS_CONTEXT_LOSTMEM_MEM_SHIFT                                    (8U)
#define PRCM_RM_WKUP_DBGSS_CONTEXT_LOSTMEM_MEM_MASK                                     (0x00000100U)
#define PRCM_RM_WKUP_DBGSS_CONTEXT_LOSTMEM_MEM_LOST                                      (1U)
#define PRCM_RM_WKUP_DBGSS_CONTEXT_LOSTMEM_MEM_MAINTAINED                                (0U)

#define PRCM_RM_WKUP_ADC_TSC_CONTEXT_LOSTCONTEXT_DFF_SHIFT                              (0U)
#define PRCM_RM_WKUP_ADC_TSC_CONTEXT_LOSTCONTEXT_DFF_MASK                               (0x00000001U)
#define PRCM_RM_WKUP_ADC_TSC_CONTEXT_LOSTCONTEXT_DFF_LOST                                (1U)
#define PRCM_RM_WKUP_ADC_TSC_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                          (0U)

#define PRCM_RM_WKUP_L4WKUP_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_WKUP_L4WKUP_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_WKUP_L4WKUP_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_WKUP_L4WKUP_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_WKUP_M3_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                   (0U)
#define PRCM_RM_WKUP_M3_CONTEXT_LOSTCONTEXT_DFF_MASK                                    (0x00000001U)
#define PRCM_RM_WKUP_M3_CONTEXT_LOSTCONTEXT_DFF_LOST                                     (1U)
#define PRCM_RM_WKUP_M3_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                               (0U)

#define PRCM_RM_WKUP_SYNCTIMER_CONTEXT_LOSTCONTEXT_DFF_SHIFT                            (0U)
#define PRCM_RM_WKUP_SYNCTIMER_CONTEXT_LOSTCONTEXT_DFF_MASK                             (0x00000001U)
#define PRCM_RM_WKUP_SYNCTIMER_CONTEXT_LOSTCONTEXT_DFF_LOST                              (1U)
#define PRCM_RM_WKUP_SYNCTIMER_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                        (0U)

#define PRCM_RM_WKUP_TIMER0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_WKUP_TIMER0_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_WKUP_TIMER0_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_WKUP_TIMER0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_WKUP_TIMER1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                               (0U)
#define PRCM_RM_WKUP_TIMER1_CONTEXT_LOSTCONTEXT_DFF_MASK                                (0x00000001U)
#define PRCM_RM_WKUP_TIMER1_CONTEXT_LOSTCONTEXT_DFF_LOST                                 (1U)
#define PRCM_RM_WKUP_TIMER1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                           (0U)

#define PRCM_RM_WKUP_WDT0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_WKUP_WDT0_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_WKUP_WDT0_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_WKUP_WDT0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_WKUP_WDT1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_WKUP_WDT1_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_WKUP_WDT1_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_WKUP_WDT1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_WKUP_I2C0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                 (0U)
#define PRCM_RM_WKUP_I2C0_CONTEXT_LOSTCONTEXT_DFF_MASK                                  (0x00000001U)
#define PRCM_RM_WKUP_I2C0_CONTEXT_LOSTCONTEXT_DFF_LOST                                   (1U)
#define PRCM_RM_WKUP_I2C0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                             (0U)

#define PRCM_RM_WKUP_UART0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_WKUP_UART0_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_WKUP_UART0_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_WKUP_UART0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#define PRCM_RM_WKUP_UART0_CONTEXT_LOSTMEM_RETAINED_BANK_SHIFT                          (8U)
#define PRCM_RM_WKUP_UART0_CONTEXT_LOSTMEM_RETAINED_BANK_MASK                           (0x00000100U)
#define PRCM_RM_WKUP_UART0_CONTEXT_LOSTMEM_RETAINED_BANK_LOST                            (1U)
#define PRCM_RM_WKUP_UART0_CONTEXT_LOSTMEM_RETAINED_BANK_MAINTAINED                      (0U)

#define PRCM_RM_WKUP_SMARTREFLEX0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                         (0U)
#define PRCM_RM_WKUP_SMARTREFLEX0_CONTEXT_LOSTCONTEXT_DFF_MASK                          (0x00000001U)
#define PRCM_RM_WKUP_SMARTREFLEX0_CONTEXT_LOSTCONTEXT_DFF_LOST                           (1U)
#define PRCM_RM_WKUP_SMARTREFLEX0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                     (0U)

#define PRCM_RM_WKUP_SMARTREFLEX1_CONTEXT_LOSTCONTEXT_DFF_SHIFT                         (0U)
#define PRCM_RM_WKUP_SMARTREFLEX1_CONTEXT_LOSTCONTEXT_DFF_MASK                          (0x00000001U)
#define PRCM_RM_WKUP_SMARTREFLEX1_CONTEXT_LOSTCONTEXT_DFF_LOST                           (1U)
#define PRCM_RM_WKUP_SMARTREFLEX1_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                     (0U)

#define PRCM_RM_WKUP_GPIO0_CONTEXT_LOSTCONTEXT_DFF_SHIFT                                (0U)
#define PRCM_RM_WKUP_GPIO0_CONTEXT_LOSTCONTEXT_DFF_MASK                                 (0x00000001U)
#define PRCM_RM_WKUP_GPIO0_CONTEXT_LOSTCONTEXT_DFF_LOST                                  (1U)
#define PRCM_RM_WKUP_GPIO0_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED                            (0U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_PRM_WKUP_H_ */

