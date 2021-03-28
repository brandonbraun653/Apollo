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
#ifndef CSLR_PRCM_MPU_PRM_C0_H
#define CSLR_PRCM_MPU_PRM_C0_H

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
    volatile Uint32 PM_CPU0_PWRSTCTRL_REG;
    volatile Uint32 PM_CPU0_PWRSTST_REG;
    volatile Uint8  RSVD0[8];
    volatile Uint32 RM_CPU0_CPU0_RSTCTRL_REG;
    volatile Uint32 RM_CPU0_CPU0_RSTST_REG;
    volatile Uint8  RSVD1[12];
    volatile Uint32 RM_CPU0_CPU0_CONTEXT_REG;
} CSL_PRCM_MPU_PRM_C0Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register controls the CPU domain power state to reach upon a domain
 * sleep transition */
#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG               (0x0U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL  (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG)


/* This register provides a status on the CPU domain current power state.
 * [warm reset insensitive] */
#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG                 (0x4U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST   (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG)


/* This register controls the assertion/release of the CPU CORE reset. */
#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG            (0x10U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTCTRL  (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG)


/* This register logs the different reset sources of the MPU domain. Each bit
 * is set upon release of the domain reset signal. Must be cleared by
 * software. [warm reset insensitive] */
#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG              (0x14U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTST  (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG)


/* This register contains dedicated CPU context statuses. [warm reset
 * insensitive] */
#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG            (0x24U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_CONTEXT  (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PM_CPU0_PWRSTCTRL_REG */

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_ONSTATE_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_L1_BANK_ONSTATE_MASK        (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_ONSTATE_MASK)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_ONSTATE_RESETVAL  (0x00000003U)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_ONSTATE_SHIFT  (16U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_L1_BANK_ONSTATE_SHIFT       (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_ONSTATE_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_ONSTATE_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_L1_BANK_ONSTATE_Mem_on      (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_ONSTATE_MEM_ON)


#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_POWERSTATE_MASK             (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_MASK)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_RESETVAL  (0x00000003U)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_POWERSTATE_SHIFT            (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_POWERSTATE_OFF              (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_OFF)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_INACT  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_POWERSTATE_INACT            (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_INACT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_POWERSTATE_RET              (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_RET)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_POWERSTATE_ON               (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_POWERSTATE_ON)


#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_RETSTATE_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_L1_BANK_RETSTATE_MASK       (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_RETSTATE_MASK)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_RETSTATE_RESETVAL  (0x00000001U)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_RETSTATE_SHIFT  (8U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_L1_BANK_RETSTATE_SHIFT      (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_RETSTATE_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_RETSTATE_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_L1_BANK_RETSTATE_mem_ret    (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_L1_BANK_RETSTATE_MEM_RET)


#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_LOGICRETSTATE_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_LOGICRETSTATE_MASK          (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_LOGICRETSTATE_MASK)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_LOGICRETSTATE_RESETVAL  (0x00000001U)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_LOGICRETSTATE_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_LOGICRETSTATE_SHIFT         (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_LOGICRETSTATE_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTCTRL_LOGICRETSTATE_logic_ret     (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_LOGICRETSTATE_LOGIC_RET)


#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTCTRL_REG_RESETVAL      (0x00030107U)

/* PM_CPU0_PWRSTST_REG */

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_POWERSTATEST_MASK             (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_MASK)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_RESETVAL  (0x00000003U)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_POWERSTATEST_SHIFT            (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_POWERSTATEST_ON               (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_ON)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_POWERSTATEST_OFF              (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_OFF)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_POWERSTATEST_RET              (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_RET)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_INACTIVE  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_POWERSTATEST_INACTIVE         (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_POWERSTATEST_INACTIVE)


#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_INTRANSITION_MASK  (0x00100000U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_INTRANSITION_MASK             (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_INTRANSITION_MASK)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_INTRANSITION_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_INTRANSITION_SHIFT  (20U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_INTRANSITION_SHIFT            (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_INTRANSITION_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_INTRANSITION_NO  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_INTRANSITION_No               (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_INTRANSITION_NO)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_INTRANSITION_ONGOING  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_INTRANSITION_Ongoing          (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_INTRANSITION_ONGOING)


#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LOGICSTATEST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LOGICSTATEST_MASK             (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LOGICSTATEST_MASK)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LOGICSTATEST_RESETVAL  (0x00000001U)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LOGICSTATEST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LOGICSTATEST_SHIFT            (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LOGICSTATEST_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LOGICSTATEST_ON  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LOGICSTATEST_ON               (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LOGICSTATEST_ON)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LOGICSTATEST_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LOGICSTATEST_OFF              (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LOGICSTATEST_OFF)


#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_MASK  (0x00000030U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_L1_BANK_STATEST_MASK          (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_MASK)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_RESETVAL  (0x00000003U)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_L1_BANK_STATEST_SHIFT         (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_MEM_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_L1_BANK_STATEST_Mem_off       (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_MEM_OFF)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_MEM_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_L1_BANK_STATEST_Mem_ret       (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_MEM_RET)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_RESERVED  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_L1_BANK_STATEST_Reserved      (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_RESERVED)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_MEM_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_L1_BANK_STATEST_Mem_on        (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_L1_BANK_STATEST_MEM_ON)


#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK  (0x03000000U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LASTPOWERSTATEENTERED_MASK    (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_MASK)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT  (24U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LASTPOWERSTATEENTERED_SHIFT   (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_ON  (0x00000003U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LASTPOWERSTATEENTERED_ON      (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_ON)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF  (0x00000000U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LASTPOWERSTATEENTERED_OFF     (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_OFF)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_RET  (0x00000001U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LASTPOWERSTATEENTERED_RET     (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_RET)

#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_INACT  (0x00000002U)
/* Below define for backward compatibility */
#define PM_CPU0_PWRSTST_LASTPOWERSTATEENTERED_INACT   (CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_LASTPOWERSTATEENTERED_INACT)


#define CSL_PRCM_MPU_PRM_C0_PM_CPU0_PWRSTST_REG_RESETVAL        (0x00000037U)

/* RM_CPU0_CPU0_RSTCTRL_REG */

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RST_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTCTRL_RST_MASK                 (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RST_MASK)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RST_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RST_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTCTRL_RST_SHIFT                (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RST_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RST_ASSERT  (0x00000001U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTCTRL_RST_ASSERT               (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RST_ASSERT)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RST_CLEAR  (0x00000000U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTCTRL_RST_CLEAR                (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RST_CLEAR)


#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTCTRL_REG_RESETVAL   (0x00000000U)

/* RM_CPU0_CPU0_RSTST_REG */

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RSTST_MASK   (0x00000001U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTST_RSTST_MASK                 (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RSTST_MASK)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RSTST_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RSTST_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTST_RSTST_SHIFT                (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RSTST_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RSTST_CLEAR  (0x00000000U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTST_RSTST_CLEAR                (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RSTST_CLEAR)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RSTST_ASSERT  (0x00000001U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTST_RSTST_ASSERT               (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RSTST_ASSERT)


#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_DBGRST_REQ_RSTST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTST_DBGRST_REQ_RSTST_MASK      (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_DBGRST_REQ_RSTST_MASK)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_DBGRST_REQ_RSTST_RESETVAL  (0x00000000U)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_DBGRST_REQ_RSTST_SHIFT  (1U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTST_DBGRST_REQ_RSTST_SHIFT     (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_DBGRST_REQ_RSTST_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_DBGRST_REQ_RSTST_CLEAR  (0x00000000U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTST_DBGRST_REQ_RSTST_CLEAR     (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_DBGRST_REQ_RSTST_CLEAR)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_DBGRST_REQ_RSTST_ASSERT  (0x00000001U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_RSTST_DBGRST_REQ_RSTST_ASSERT    (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_DBGRST_REQ_RSTST_ASSERT)


#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_RSTST_REG_RESETVAL     (0x00000000U)

/* RM_CPU0_CPU0_CONTEXT_REG */

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTCONTEXT_DFF_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_CONTEXT_LOSTCONTEXT_DFF_MASK     (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTCONTEXT_DFF_MASK)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTCONTEXT_DFF_RESETVAL  (0x00000001U)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT  (0U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_CONTEXT_LOSTCONTEXT_DFF_SHIFT    (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTCONTEXT_DFF_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTCONTEXT_DFF_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_CONTEXT_LOSTCONTEXT_DFF_Lost     (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTCONTEXT_DFF_LOST)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_CONTEXT_LOSTCONTEXT_DFF_Maintained  (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTCONTEXT_DFF_MAINTAINED)


#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTMEM_CPU_L1_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_CONTEXT_LOSTMEM_CPU_L1_MASK      (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTMEM_CPU_L1_MASK)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTMEM_CPU_L1_RESETVAL  (0x00000001U)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTMEM_CPU_L1_SHIFT  (8U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_CONTEXT_LOSTMEM_CPU_L1_SHIFT     (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTMEM_CPU_L1_SHIFT)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTMEM_CPU_L1_LOST  (0x00000001U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_CONTEXT_LOSTMEM_CPU_L1_Lost      (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTMEM_CPU_L1_LOST)

#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTMEM_CPU_L1_MAINTAINED  (0x00000000U)
/* Below define for backward compatibility */
#define RM_CPU0_CPU0_CONTEXT_LOSTMEM_CPU_L1_Maintained  (CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_LOSTMEM_CPU_L1_MAINTAINED)


#define CSL_PRCM_MPU_PRM_C0_RM_CPU0_CPU0_CONTEXT_REG_RESETVAL   (0x00000101U)

#ifdef __cplusplus
}
#endif
#endif
