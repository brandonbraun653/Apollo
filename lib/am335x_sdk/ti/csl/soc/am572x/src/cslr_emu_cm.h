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
#ifndef CSLR_EMU_CM_H
#define CSLR_EMU_CM_H

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
    volatile Uint32 CM_EMU_CLKSTCTRL_REG;
    volatile Uint32 CM_EMU_DEBUGSS_CLKCTRL_REG;
    volatile Uint32 CM_EMU_DYNAMICDEP_REG;
    volatile Uint32 CM_EMU_MPU_EMU_DBG_CLKCTRL_REG;
} CSL_emu_cmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register enables the EMU domain power state transition. It controls
 * the HW supervised domain power state transition between ON-ACTIVE and
 * ON-INACTIVE states. It also hold one status bit per clock input of the
 * domain. [warm reset insensitive] */
#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG                         (0x0U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL           (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG)


/* This register manages the DEBUGSS clocks. [warm reset insensitive] */
#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG                   (0x4U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL     (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG)


/* This register controls the dynamic domain depedencies from EMU domain
 * towards 'target' domains. It is relevant only for domain having OCP master
 * port(s). */
#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG                        (0x8U)
/* Below define for backward compatibility */
#define CM_EMU_DYNAMICDEP          (CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG)


/* This register manages the MPU_EMU_DBG clocks. [warm reset insensitive] */
#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG               (0xCU)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL  (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CM_EMU_CLKSTCTRL_REG */

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_MASK          (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKTRCTRL_MASK               (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL      (0x00000002U)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_SHIFT         (0U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKTRCTRL_SHIFT              (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_RESERVED      (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKTRCTRL_RESERVED           (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_RESERVED)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1    (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKTRCTRL_RESERVED_1         (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_RESERVED_1)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP       (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKTRCTRL_SW_WKUP            (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO       (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKTRCTRL_HW_AUTO            (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKACTIVITY_EMU_SYS_CLK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKACTIVITY_EMU_SYS_CLK_MASK  (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKACTIVITY_EMU_SYS_CLK_MASK)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKACTIVITY_EMU_SYS_CLK_RESETVAL  (0x00000000U)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKACTIVITY_EMU_SYS_CLK_SHIFT  (8U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKACTIVITY_EMU_SYS_CLK_SHIFT  (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKACTIVITY_EMU_SYS_CLK_SHIFT)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKACTIVITY_EMU_SYS_CLK_INACT  (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKACTIVITY_EMU_SYS_CLK_INACT  (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKACTIVITY_EMU_SYS_CLK_INACT)

#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKACTIVITY_EMU_SYS_CLK_ACT  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMU_CLKSTCTRL_CLKACTIVITY_EMU_SYS_CLK_ACT  (CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_CLKACTIVITY_EMU_SYS_CLK_ACT)


#define CSL_EMU_CM_CM_EMU_CLKSTCTRL_REG_RESETVAL                (0x00000002U)

/* CM_EMU_DEBUGSS_CLKCTRL_REG */

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_MASK       (0x00030000U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_IDLEST_MASK            (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_MASK)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_RESETVAL   (0x00000003U)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_SHIFT      (16U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_IDLEST_SHIFT           (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_DISABLE    (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_IDLEST_DISABLE         (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_IDLE       (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_IDLEST_IDLE            (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_FUNC       (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_IDLEST_FUNC            (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_TRANS      (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_IDLEST_TRANS           (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_STBYST_MASK       (0x00040000U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_STBYST_MASK            (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_STBYST_MASK)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_STBYST_RESETVAL   (0x00000001U)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_STBYST_SHIFT      (18U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_STBYST_SHIFT           (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_STBYST_SHIFT)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_STBYST_FUNC       (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_STBYST_FUNC            (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_STBYST_FUNC)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_STBYST_STANDBY    (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_STBYST_STANDBY         (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_STBYST_STANDBY)


#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_MODULEMODE_MASK   (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_MODULEMODE_MASK        (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_MODULEMODE_SHIFT       (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_MODULEMODE_AUTO   (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMU_DEBUGSS_CLKCTRL_MODULEMODE_AUTO        (CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_EMU_CM_CM_EMU_DEBUGSS_CLKCTRL_REG_RESETVAL          (0x00070001U)

/* CM_EMU_DYNAMICDEP_REG */

#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK    (0x00000020U)
/* Below define for backward compatibility */
#define CM_EMU_DYNAMICDEP_L3MAIN1_DYNDEP_MASK         (CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_L3MAIN1_DYNDEP_MASK)

#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_L3MAIN1_DYNDEP_RESETVAL  (0x00000001U)

#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT   (5U)
/* Below define for backward compatibility */
#define CM_EMU_DYNAMICDEP_L3MAIN1_DYNDEP_SHIFT        (CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_L3MAIN1_DYNDEP_SHIFT)

#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_L3MAIN1_DYNDEP_ENABLED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMU_DYNAMICDEP_L3MAIN1_DYNDEP_ENABLED      (CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_L3MAIN1_DYNDEP_ENABLED)


#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_WINDOWSIZE_MASK        (0x0F000000U)
/* Below define for backward compatibility */
#define CM_EMU_DYNAMICDEP_WINDOWSIZE_MASK             (CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_WINDOWSIZE_MASK)

#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_WINDOWSIZE_RESETVAL    (0x00000004U)

#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_WINDOWSIZE_SHIFT       (24U)
/* Below define for backward compatibility */
#define CM_EMU_DYNAMICDEP_WINDOWSIZE_SHIFT            (CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_WINDOWSIZE_SHIFT)

#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_WINDOWSIZE_MAX         (0x0000000fU)

#define CSL_EMU_CM_CM_EMU_DYNAMICDEP_REG_RESETVAL               (0x04000020U)

/* CM_EMU_MPU_EMU_DBG_CLKCTRL_REG */

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_MASK   (0x00030000U)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL_IDLEST_MASK        (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_MASK)

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL_IDLEST_SHIFT       (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL_IDLEST_DISABLE     (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_IDLE   (0x00000002U)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL_IDLEST_IDLE        (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_FUNC   (0x00000000U)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL_IDLEST_FUNC        (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL_IDLEST_TRANS       (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL_MODULEMODE_MASK    (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000001U)

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL_MODULEMODE_SHIFT   (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_EMU_MPU_EMU_DBG_CLKCTRL_MODULEMODE_AUTO    (CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_MODULEMODE_AUTO)


#define CSL_EMU_CM_CM_EMU_MPU_EMU_DBG_CLKCTRL_REG_RESETVAL      (0x00030001U)

#ifdef __cplusplus
}
#endif
#endif
