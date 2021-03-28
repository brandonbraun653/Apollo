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
#ifndef CSLR_CUSTEFUSE_CM_CORE_H
#define CSLR_CUSTEFUSE_CM_CORE_H

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
    volatile Uint32 CM_CUSTEFUSE_CLKSTCTRL_REG;
    volatile Uint8  RSVD0[28];
    volatile Uint32 CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG;
} CSL_custefuse_cm_coreRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register enables the domain power state transition. It controls the HW 
 * supervised domain power state transition between ON-ACTIVE and ON-INACTIVE 
 * states. It also hold one status bit per clock input of the domain. */
#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG        (0x0U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG)


/* This register manages the CUSTEFUSE clocks. */
#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG  (0x20U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CM_CUSTEFUSE_CLKSTCTRL_REG */

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKTRCTRL_MASK         (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000003U)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKTRCTRL_SHIFT        (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKTRCTRL_NO_SLEEP     (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_RESERVED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKTRCTRL_RESERVED     (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_RESERVED)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKTRCTRL_SW_WKUP      (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKTRCTRL_HW_AUTO      (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_L4_GICLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKACTIVITY_CUSTEFUSE_L4_GICLK_MASK  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_L4_GICLK_MASK)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_L4_GICLK_RESETVAL  (0x00000000U)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_L4_GICLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKACTIVITY_CUSTEFUSE_L4_GICLK_SHIFT  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_L4_GICLK_SHIFT)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_L4_GICLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKACTIVITY_CUSTEFUSE_L4_GICLK_INACT  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_L4_GICLK_INACT)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_L4_GICLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKACTIVITY_CUSTEFUSE_L4_GICLK_ACT  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_L4_GICLK_ACT)


#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_MASK  (0x00000200U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_MASK  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_MASK)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_RESETVAL  (0x00000000U)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_SHIFT  (9U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_SHIFT  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_SHIFT)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_INACT  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_INACT)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_CLKSTCTRL_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_ACT  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_CLKACTIVITY_CUSTEFUSE_SYS_GFCLK_ACT)


#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_CLKSTCTRL_REG_RESETVAL  (0x00000003U)

/* CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG */

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_IDLEST_MASK  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_MASK)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_IDLEST_SHIFT  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_IDLEST_DISABLE  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_IDLEST_IDLE  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_IDLEST_FUNC  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_IDLEST_TRANS  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_MODULEMODE_MASK  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_MODULEMODE_SHIFT  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_MODULEMODE_DISABLED  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_RESERVED_1  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_MODULEMODE_RESERVED_1  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_RESERVED_1)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_ENABLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_MODULEMODE_ENABLE  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_ENABLE)

#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_MODULEMODE_RESERVED  (CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_CUSTEFUSE_CM_CORE_CM_CUSTEFUSE_EFUSE_CTRL_CUST_CLKCTRL_REG_RESETVAL  (0x00030000U)

#ifdef __cplusplus
}
#endif
#endif
