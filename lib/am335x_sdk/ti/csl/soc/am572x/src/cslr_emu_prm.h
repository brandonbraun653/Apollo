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
#ifndef CSLR_EMU_PRM_H
#define CSLR_EMU_PRM_H

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
    volatile Uint32 PM_EMU_PWRSTCTRL_REG;
    volatile Uint32 PM_EMU_PWRSTST_REG;
    volatile Uint8  RSVD0[28];
    volatile Uint32 RM_EMU_DEBUGSS_CONTEXT_REG;
} CSL_emu_prmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register controls the EMU power state to reach upon a domain sleep
 * transition */
#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG                        (0x0U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTCTRL          (CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG)


/* This register provides a status on the EMU domain current power state.
 * [warm reset insensitive] */
#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG                          (0x4U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST            (CSL_EMU_PRM_PM_EMU_PWRSTST_REG)


/* This register contains dedicated DEBUGSS context statuses. [warm reset
 * insensitive] */
#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG                  (0x24U)
/* Below define for backward compatibility */
#define RM_EMU_DEBUGSS_CONTEXT    (CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PM_EMU_PWRSTCTRL_REG */

#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_EMU_BANK_ONSTATE_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTCTRL_EMU_BANK_ONSTATE_MASK        (CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_EMU_BANK_ONSTATE_MASK)

#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_EMU_BANK_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_EMU_BANK_ONSTATE_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTCTRL_EMU_BANK_ONSTATE_SHIFT       (CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_EMU_BANK_ONSTATE_SHIFT)

#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_EMU_BANK_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTCTRL_EMU_BANK_ONSTATE_MEM_ON      (CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_EMU_BANK_ONSTATE_MEM_ON)


#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_POWERSTATE_MASK        (0x00000003U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTCTRL_POWERSTATE_MASK              (CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_POWERSTATE_MASK)

#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_POWERSTATE_RESETVAL    (0x00000000U)

#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_POWERSTATE_SHIFT       (0U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTCTRL_POWERSTATE_SHIFT             (CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_POWERSTATE_SHIFT)

#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_POWERSTATE_OFF         (0x00000000U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTCTRL_POWERSTATE_OFF               (CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_POWERSTATE_OFF)


#define CSL_EMU_PRM_PM_EMU_PWRSTCTRL_REG_RESETVAL               (0x00030000U)

/* PM_EMU_PWRSTST_REG */

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_POWERSTATEST_MASK        (0x00000003U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_POWERSTATEST_MASK              (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_POWERSTATEST_MASK)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_POWERSTATEST_RESETVAL    (0x00000003U)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_POWERSTATEST_SHIFT       (0U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_POWERSTATEST_SHIFT             (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_POWERSTATEST_SHIFT)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_POWERSTATEST_ON          (0x00000003U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_POWERSTATEST_ON                (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_POWERSTATEST_ON)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_POWERSTATEST_OFF         (0x00000000U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_POWERSTATEST_OFF               (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_POWERSTATEST_OFF)


#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_INTRANSITION_MASK        (0x00100000U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_INTRANSITION_MASK              (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_INTRANSITION_MASK)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_INTRANSITION_RESETVAL    (0x00000000U)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_INTRANSITION_SHIFT       (20U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_INTRANSITION_SHIFT             (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_INTRANSITION_SHIFT)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_INTRANSITION_NO          (0x00000000U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_INTRANSITION_NO                (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_INTRANSITION_NO)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_INTRANSITION_ONGOING     (0x00000001U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_INTRANSITION_ONGOING           (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_INTRANSITION_ONGOING)


#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LOGICSTATEST_MASK        (0x00000004U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LOGICSTATEST_MASK              (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LOGICSTATEST_MASK)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LOGICSTATEST_RESETVAL    (0x00000001U)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LOGICSTATEST_SHIFT       (2U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LOGICSTATEST_SHIFT             (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LOGICSTATEST_SHIFT)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LOGICSTATEST_ON          (0x00000001U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LOGICSTATEST_ON                (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LOGICSTATEST_ON)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LOGICSTATEST_OFF         (0x00000000U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LOGICSTATEST_OFF               (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LOGICSTATEST_OFF)


#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_MASK    (0x00000030U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_EMU_BANK_STATEST_MASK          (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_MASK)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_RESETVAL  (0x00000003U)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_SHIFT   (4U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_EMU_BANK_STATEST_SHIFT         (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_SHIFT)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_EMU_BANK_STATEST_MEM_ON        (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_MEM_ON)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_RESERVED1  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_EMU_BANK_STATEST_RESERVED1     (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_RESERVED1)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_EMU_BANK_STATEST_MEM_OFF       (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_MEM_OFF)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_RESERVED2  (0x00000002U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_EMU_BANK_STATEST_RESERVED2     (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_EMU_BANK_STATEST_RESERVED2)


#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LASTPOWERSTATEENTERED_MASK     (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_RESETVAL  (0x00000000U)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT  (24U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LASTPOWERSTATEENTERED_SHIFT    (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LASTPOWERSTATEENTERED_ON       (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_ON)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LASTPOWERSTATEENTERED_OFF      (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LASTPOWERSTATEENTERED_RET      (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_RET)

#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_EMU_PWRSTST_LASTPOWERSTATEENTERED_INACTIVE  (CSL_EMU_PRM_PM_EMU_PWRSTST_REG_LASTPOWERSTATEENTERED_INACTIVE)


#define CSL_EMU_PRM_PM_EMU_PWRSTST_REG_RESETVAL                 (0x00000037U)

/* RM_EMU_DEBUGSS_CONTEXT_REG */

#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMU_DEBUGSS_CONTEXT_LOSTCONTEXT_DFF_MASK   (CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_EMU_DEBUGSS_CONTEXT_LOSTCONTEXT_DFF_SHIFT  (CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMU_DEBUGSS_CONTEXT_LOSTCONTEXT_DFF_LOST   (CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMU_DEBUGSS_CONTEXT_LOSTCONTEXT_DFF_MAINTAINED  (CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTMEM_EMU_BANK_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_EMU_DEBUGSS_CONTEXT_LOSTMEM_EMU_BANK_MASK  (CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTMEM_EMU_BANK_MASK)

#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTMEM_EMU_BANK_RESETVAL  (0x00000001U)

#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTMEM_EMU_BANK_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_EMU_DEBUGSS_CONTEXT_LOSTMEM_EMU_BANK_SHIFT  (CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTMEM_EMU_BANK_SHIFT)

#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTMEM_EMU_BANK_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_EMU_DEBUGSS_CONTEXT_LOSTMEM_EMU_BANK_LOST  (CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTMEM_EMU_BANK_LOST)

#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTMEM_EMU_BANK_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_EMU_DEBUGSS_CONTEXT_LOSTMEM_EMU_BANK_MAINTAINED  (CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_LOSTMEM_EMU_BANK_MAINTAINED)


#define CSL_EMU_PRM_RM_EMU_DEBUGSS_CONTEXT_REG_RESETVAL         (0x00000101U)

#ifdef __cplusplus
}
#endif
#endif
