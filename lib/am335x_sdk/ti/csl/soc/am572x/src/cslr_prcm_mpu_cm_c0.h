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
#ifndef CSLR_PRCM_MPU_CM_C0_H
#define CSLR_PRCM_MPU_CM_C0_H

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
    volatile Uint32 CM_CPU0_CLKSTCTRL_REG;
    volatile Uint8  RSVD0[28];
    volatile Uint32 CM_CPU0_CPU0_CLKCTRL_REG;
} CSL_PRCM_MPU_CM_C0Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register enables the CPU domain power state transition. It controls
 * the HW supervised domain power state transition between ON-ACTIVE and
 * ON-INACTIVE states. It also hold one status bit per clock input of the
 * domain. */
#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG                (0x0U)
/* Below define for backward compatibility */
#define CM_CPU0_CLKSTCTRL  (CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG)


/* This register manages the CPU clocks. */
#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG             (0x20U)
/* Below define for backward compatibility */
#define CM_CPU0_CPU0_CLKCTRL  (CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CM_CPU0_CLKSTCTRL_REG */

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CPU0_CLKSTCTRL_CLKTRCTRL_MASK              (CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_MASK)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CPU0_CLKSTCTRL_CLKTRCTRL_SHIFT             (CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_SHIFT)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CPU0_CLKSTCTRL_CLKTRCTRL_NO_SLEEP          (CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_NO_SLEEP)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_RESERVED  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CPU0_CLKSTCTRL_CLKTRCTRL_Reserved          (CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_RESERVED)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP  (0x00000002U)
/* Below define for backward compatibility */
#define CM_CPU0_CLKSTCTRL_CLKTRCTRL_SW_WKUP           (CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_SW_WKUP)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO  (0x00000003U)
/* Below define for backward compatibility */
#define CM_CPU0_CLKSTCTRL_CLKTRCTRL_HW_AUTO           (CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_CLKTRCTRL_HW_AUTO)


#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CLKSTCTRL_REG_RESETVAL       (0x00000000U)

/* CM_CPU0_CPU0_CLKCTRL_REG */

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_STBYST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CPU0_CPU0_CLKCTRL_STBYST_MASK              (CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_STBYST_MASK)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_STBYST_RESETVAL  (0x00000001U)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_STBYST_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_CPU0_CPU0_CLKCTRL_STBYST_SHIFT             (CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_STBYST_SHIFT)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_STBYST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_CPU0_CPU0_CLKCTRL_STBYST_Func              (CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_STBYST_FUNC)

#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_STBYST_STANDBY  (0x00000001U)
/* Below define for backward compatibility */
#define CM_CPU0_CPU0_CLKCTRL_STBYST_Standby           (CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_STBYST_STANDBY)


#define CSL_PRCM_MPU_CM_C0_CM_CPU0_CPU0_CLKCTRL_REG_RESETVAL    (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif
