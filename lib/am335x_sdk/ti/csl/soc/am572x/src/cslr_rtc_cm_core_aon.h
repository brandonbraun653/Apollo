/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_RTC_CM_CORE_AON_H
#define CSLR_RTC_CM_CORE_AON_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 CM_RTC_CLKSTCTRL_REG;
    volatile Uint32 CM_RTC_RTCSS_CLKCTRL_REG;
} CSL_rtc_cm_core_aonRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register enables the domain power state transition. It controls the HW
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG                (0x0U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL  (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG)


/* This register manages the RTC clocks. */
#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG            (0x4U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL  (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CM_RTC_CLKSTCTRL_REG */

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKTRCTRL_MASK               (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000000U)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKTRCTRL_SHIFT              (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKTRCTRL_NO_SLEEP           (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKTRCTRL_RESERVED_1         (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKTRCTRL_SW_WKUP            (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKTRCTRL_HW_AUTO            (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_L4_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_L4_GICLK_MASK  (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_L4_GICLK_MASK)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_L4_GICLK_RESETVAL  (0x00000000U)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_L4_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_L4_GICLK_SHIFT  (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_L4_GICLK_SHIFT)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_L4_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_L4_GICLK_INACT  (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_L4_GICLK_INACT)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_L4_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_L4_GICLK_ACT  (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_L4_GICLK_ACT)


#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_AUX_CLK_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_AUX_CLK_MASK  (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_AUX_CLK_MASK)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_AUX_CLK_RESETVAL  (0x00000000U)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_AUX_CLK_SHIFT  (10U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_AUX_CLK_SHIFT  (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_AUX_CLK_SHIFT)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_AUX_CLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_AUX_CLK_INACT  (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_AUX_CLK_INACT)

#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_AUX_CLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_AUX_CLK_ACT  (CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_CLKACTIVITY_RTC_AUX_CLK_ACT)


#define CSL_RTC_CM_CORE_AON_CM_RTC_CLKSTCTRL_REG_RESETVAL       (0x00000000U)

/* CM_RTC_RTCSS_CLKCTRL_REG */

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_IDLEST_MASK              (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_MASK)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_IDLEST_SHIFT             (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_IDLEST_DISABLE           (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_IDLEST_IDLE              (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_IDLEST_FUNC              (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_IDLEST_TRANS             (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_MODULEMODE_MASK          (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_MODULEMODE_SHIFT         (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_MODULEMODE_DISABLED      (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_MODULEMODE_RESERVED_1    (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_ENABLED  (0x00000002U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_MODULEMODE_ENABLED       (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_ENABLED)

#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_RTC_RTCSS_CLKCTRL_MODULEMODE_RESERVED      (CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_RTC_CM_CORE_AON_CM_RTC_RTCSS_CLKCTRL_REG_RESETVAL   (0x00030000U)

#ifdef __cplusplus
}
#endif
#endif
