/*
* hw_cm_cefuse.h
*
* Register-level header file for CM_CEFUSE
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

#ifndef HW_CM_CEFUSE_H_
#define HW_CM_CEFUSE_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/

#define PRCM_CM_CEFUSE_CLKSTCTRL                                    (0x0U)
#define PRCM_CM_CEFUSE_CLKCTRL                                      (0x20U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_L4_GICLK_SHIFT                             (8U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_L4_GICLK_MASK                              (0x00000100U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_L4_GICLK_INACT                              (0U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_L4_GICLK_ACT                                (1U)

#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_CUST_EFUSE_SYS_CLK_SHIFT                   (9U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_CUST_EFUSE_SYS_CLK_MASK                    (0x00000200U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_CUST_EFUSE_SYS_CLK_INACT                    (0U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_CUST_EFUSE_SYS_CLK_ACT                      (1U)

#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKTRCTRL_SHIFT                                        (0U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKTRCTRL_MASK                                         (0x00000003U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKTRCTRL_NO_SLEEP                                      (0U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKTRCTRL_SW_SLEEP                                      (1U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKTRCTRL_SW_WKUP                                       (2U)
#define PRCM_CM_CEFUSE_CLKSTCTRL_CLKTRCTRL_RESERVED                                      (3U)

#define PRCM_CM_CEFUSE_CLKCTRL_IDLEST_SHIFT                                             (16U)
#define PRCM_CM_CEFUSE_CLKCTRL_IDLEST_MASK                                              (0x00030000U)
#define PRCM_CM_CEFUSE_CLKCTRL_IDLEST_DISABLE                                            (3U)
#define PRCM_CM_CEFUSE_CLKCTRL_IDLEST_IDLE                                               (2U)
#define PRCM_CM_CEFUSE_CLKCTRL_IDLEST_FUNC                                               (0U)
#define PRCM_CM_CEFUSE_CLKCTRL_IDLEST_TRANS                                              (1U)

#define PRCM_CM_CEFUSE_CLKCTRL_MODULEMODE_SHIFT                                         (0U)
#define PRCM_CM_CEFUSE_CLKCTRL_MODULEMODE_MASK                                          (0x00000003U)
#define PRCM_CM_CEFUSE_CLKCTRL_MODULEMODE_DISABLED                                       (0U)
#define PRCM_CM_CEFUSE_CLKCTRL_MODULEMODE_RESERVED_1                                     (1U)
#define PRCM_CM_CEFUSE_CLKCTRL_MODULEMODE_ENABLE                                         (2U)
#define PRCM_CM_CEFUSE_CLKCTRL_MODULEMODE_RESERVED                                       (3U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CM_CEFUSE_H_ */

