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
#ifndef CSLR_OCP_SOCKET_PRM_H
#define CSLR_OCP_SOCKET_PRM_H

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
    volatile Uint32 REVISION_PRM_REG;
    volatile Uint8  RSVD0[12];
    volatile Uint32 PRM_IRQSTATUS_MPU_REG;
    volatile Uint32 PRM_IRQSTATUS_MPU_2_REG;
    volatile Uint32 PRM_IRQENABLE_MPU_REG;
    volatile Uint32 PRM_IRQENABLE_MPU_2_REG;
    volatile Uint32 PRM_IRQSTATUS_IPU2_REG;
    volatile Uint8  RSVD1[4];
    volatile Uint32 PRM_IRQENABLE_IPU2_REG;
    volatile Uint8  RSVD2[4];
    volatile Uint32 PRM_IRQSTATUS_DSP1_REG;
    volatile Uint8  RSVD3[4];
    volatile Uint32 PRM_IRQENABLE_DSP1_REG;
    volatile Uint8  RSVD4[4];
    volatile Uint32 CM_PRM_PROFILING_CLKCTRL_REG;
    volatile Uint32 PRM_IRQENABLE_DSP2_REG;
    volatile Uint32 PRM_IRQENABLE_EVE1_REG;
    volatile Uint32 PRM_IRQENABLE_EVE2_REG;
    volatile Uint32 PRM_IRQENABLE_EVE3_REG;
    volatile Uint32 PRM_IRQENABLE_EVE4_REG;
    volatile Uint32 PRM_IRQENABLE_IPU1_REG;
    volatile Uint32 PRM_IRQSTATUS_DSP2_REG;
    volatile Uint32 PRM_IRQSTATUS_EVE1_REG;
    volatile Uint32 PRM_IRQSTATUS_EVE2_REG;
    volatile Uint32 PRM_IRQSTATUS_EVE3_REG;
    volatile Uint32 PRM_IRQSTATUS_EVE4_REG;
    volatile Uint32 PRM_IRQSTATUS_IPU1_REG;
    volatile Uint8  RSVD5[112];
    volatile Uint32 PRM_DEBUG_CFG1_REG;
    volatile Uint32 PRM_DEBUG_CFG2_REG;
    volatile Uint32 PRM_DEBUG_CFG3_REG;
    volatile Uint32 PRM_DEBUG_CFG_REG;
    volatile Uint32 PRM_DEBUG_OUT_REG;
} CSL_ocp_socket_prmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register contains the IP revision code for the PRM part of the PRCM */
#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG                     (0x0U)
/* Below define for backward compatibility */
#define REVISION_PRM       (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG)


/* This register provides status on MPU interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG                (0x10U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG)


/* This register provides status on MPU interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG              (0x14U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_2  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG)


/* This register is used to enable or disable MPU interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG                (0x18U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG)


/* This register is used to enable or disable MPU interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG              (0x1CU)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_2  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG)


/* This register provides status on IPU2 interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG               (0x20U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG)


/* This register is used to enable or disable IPU2 interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG               (0x28U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG)


/* This register provides status on DSP1 interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG               (0x30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG)


/* This register is used to enable or disable DSP1 interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG               (0x38U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG)


/* This register manages the PRM_PROFILING clock. [warm reset insensitive] */
#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG         (0x40U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL  (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG)


/* This register is used to enable or disable DSP2 interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG               (0x44U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG)


/* This register is used to enable or disable EVE1 interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG               (0x48U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG)


/* This register is used to enable or disable EVE2 interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG               (0x4CU)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG)


/* This register is used to enable or disable EVE3 interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG               (0x50U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG)


/* This register is used to enable or disable EVE4 interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG               (0x54U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG)


/* This register is used to enable or disable IPU1 interrupt activation upon 
 * presence of corresponding IRQSTATUS bit. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG               (0x58U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG)


/* This register provides status on DSP interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG               (0x5CU)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG)


/* This register provides status on EVE interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG               (0x60U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG)


/* This register provides status on EVE interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG               (0x64U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG)


/* This register provides status on EVE interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG               (0x68U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG)


/* This register provides status on EVE interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG               (0x6CU)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG)


/* This register provides status on IPU1 interrupt events. Any event is logged 
 * independently of the corresponding IRQENABLE value. SW is required to clear 
 * a set bit by writing a '1' into the bit-position to be cleared. */
#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG               (0x70U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG)


/* This register is used to configure the PRM's 32-bit debug output. There is 
 * one 7-bit source select field for selecting from a shared set of 8-bit 
 * internal signal blocks per byte. The signals included in each block are 
 * specified in the PRCM integration specification. [warm reset insensitive] */
#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG1_REG                   (0xE4U)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG1     (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG1_REG)


/* This register is used to configure the PRM's 32-bit debug output. There is 
 * one 7-bit source select field for selecting from a shared set of 8-bit 
 * internal signal blocks per byte. The signals included in each block are 
 * specified in the PRCM integration specification. [warm reset insensitive] */
#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG2_REG                   (0xE8U)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG2     (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG2_REG)


/* This register is used to configure the PRM's 32-bit debug output. There is 
 * one 7-bit source select field for selecting from a shared set of 8-bit 
 * internal signal blocks per byte. The signals included in each block are 
 * specified in the PRCM integration specification. [warm reset insensitive] */
#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG3_REG                   (0xECU)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG3     (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG3_REG)


/* This register is used to configure the PRM's 32-bit debug output. There is 
 * one 7-bit source select field for selecting from a shared set of 8-bit 
 * internal signal blocks per byte. The signals included in each block are 
 * specified in the PRCM integration specification. [warm reset insensitive] */
#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG_REG                    (0xF0U)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG      (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG_REG)


/* This register is used to monitor the PRM's 32 bit HEDEBUG BUS [warm reset 
 * insensitive] */
#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_OUT_REG                    (0xF4U)
/* Below define for backward compatibility */
#define PRM_DEBUG_OUT      (CSL_OCP_SOCKET_PRM_PRM_DEBUG_OUT_REG)



/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION_PRM_REG */

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_Y_MINOR_MASK        (0x0000003FU)
/* Below define for backward compatibility */
#define REVISION_PRM_Y_MINOR_MASK                     (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_Y_MINOR_MASK)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_Y_MINOR_RESETVAL    (0x00000001U)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_Y_MINOR_SHIFT       (0U)
/* Below define for backward compatibility */
#define REVISION_PRM_Y_MINOR_SHIFT                    (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_Y_MINOR_SHIFT)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_Y_MINOR_ES1         (0x00000000U)
/* Below define for backward compatibility */
#define REVISION_PRM_Y_MINOR_ES1                      (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_Y_MINOR_ES1)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_Y_MINOR_ES2         (0x00000001U)
/* Below define for backward compatibility */
#define REVISION_PRM_Y_MINOR_ES2                      (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_Y_MINOR_ES2)


#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_CUSTOM_MASK         (0x000000C0U)
/* Below define for backward compatibility */
#define REVISION_PRM_CUSTOM_MASK                      (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_CUSTOM_MASK)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_CUSTOM_RESETVAL     (0x00000000U)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_CUSTOM_SHIFT        (6U)
/* Below define for backward compatibility */
#define REVISION_PRM_CUSTOM_SHIFT                     (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_CUSTOM_SHIFT)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_CUSTOM_STANDARD     (0x00000000U)
/* Below define for backward compatibility */
#define REVISION_PRM_CUSTOM_STANDARD                  (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_CUSTOM_STANDARD)


#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_R_RTL_MASK          (0x0000F800U)
/* Below define for backward compatibility */
#define REVISION_PRM_R_RTL_MASK                       (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_R_RTL_MASK)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_R_RTL_RESETVAL      (0x00000000U)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_R_RTL_SHIFT         (11U)
/* Below define for backward compatibility */
#define REVISION_PRM_R_RTL_SHIFT                      (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_R_RTL_SHIFT)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_R_RTL_MAX           (0x0000001fU)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_FUNC_MASK           (0x0FFF0000U)
/* Below define for backward compatibility */
#define REVISION_PRM_FUNC_MASK                        (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_FUNC_MASK)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_FUNC_RESETVAL       (0x00000000U)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_FUNC_SHIFT          (16U)
/* Below define for backward compatibility */
#define REVISION_PRM_FUNC_SHIFT                       (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_FUNC_SHIFT)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_FUNC_MAX            (0x00000fffU)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_SCHEME_MASK         (0xC0000000U)
/* Below define for backward compatibility */
#define REVISION_PRM_SCHEME_MASK                      (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_SCHEME_MASK)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_SCHEME_RESETVAL     (0x00000001U)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_SCHEME_SHIFT        (30U)
/* Below define for backward compatibility */
#define REVISION_PRM_SCHEME_SHIFT                     (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_SCHEME_SHIFT)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_SCHEME_H08          (0x00000001U)
/* Below define for backward compatibility */
#define REVISION_PRM_SCHEME_H08                       (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_SCHEME_H08)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_SCHEME_LEGACY       (0x00000000U)
/* Below define for backward compatibility */
#define REVISION_PRM_SCHEME_LEGACY                    (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_SCHEME_LEGACY)


#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_MASK        (0x00000700U)
/* Below define for backward compatibility */
#define REVISION_PRM_X_MAJOR_MASK                     (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_MASK)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_RESETVAL    (0x00000003U)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_SHIFT       (8U)
/* Below define for backward compatibility */
#define REVISION_PRM_X_MAJOR_SHIFT                    (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_SHIFT)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP4430_ES1_X  (0x00000000U)
/* Below define for backward compatibility */
#define REVISION_PRM_X_MAJOR_OMAP4430_ES1_X           (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP4430_ES1_X)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP4430_ES2_X  (0x00000001U)
/* Below define for backward compatibility */
#define REVISION_PRM_X_MAJOR_OMAP4430_ES2_X           (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP4430_ES2_X)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP4460    (0x00000002U)
/* Below define for backward compatibility */
#define REVISION_PRM_X_MAJOR_OMAP4460                 (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP4460)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP5430    (0x00000003U)
/* Below define for backward compatibility */
#define REVISION_PRM_X_MAJOR_OMAP5430                 (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP5430)

#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP470     (0x00000004U)
/* Below define for backward compatibility */
#define REVISION_PRM_X_MAJOR_OMAP470                  (CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_X_MAJOR_OMAP470)


#define CSL_OCP_SOCKET_PRM_REVISION_PRM_REG_RESETVAL            (0x40000301U)

/* PRM_IRQSTATUS_MPU_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_CORE_RECAL_ST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_CORE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_CORE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_CORE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_CORE_RECAL_ST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_CORE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_CORE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_CORE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_CORE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_CORE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_CORE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_CORE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_CORE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_MPU_RECAL_ST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_MPU_RECAL_ST_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_MPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_MPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_MPU_RECAL_ST_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_MPU_RECAL_ST_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_MPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_MPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_MPU_RECAL_ST_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_MPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_MPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_MPU_RECAL_ST_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_MPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_IVA_RECAL_ST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_IVA_RECAL_ST_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_IVA_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_IVA_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_IVA_RECAL_ST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_IVA_RECAL_ST_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_IVA_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_IVA_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_IVA_RECAL_ST_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_IVA_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_IVA_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_IVA_RECAL_ST_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_IVA_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_PER_RECAL_ST_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_PER_RECAL_ST_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_PER_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_PER_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_PER_RECAL_ST_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_PER_RECAL_ST_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_PER_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_PER_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_PER_RECAL_ST_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_PER_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_PER_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_PER_RECAL_ST_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_PER_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_ABE_RECAL_ST_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_ABE_RECAL_ST_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_ABE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_ABE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_ABE_RECAL_ST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_ABE_RECAL_ST_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_ABE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_ABE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_ABE_RECAL_ST_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_ABE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_ABE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_ABE_RECAL_ST_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_ABE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_TRANSITION_ST_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_TRANSITION_ST_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_TRANSITION_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_TRANSITION_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_TRANSITION_ST_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_TRANSITION_ST_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_TRANSITION_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_TRANSITION_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_TRANSITION_ST_IRQ_TRU       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_TRANSITION_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_TRANSITION_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_TRANSITION_ST_IRQ_FAL       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_TRANSITION_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_IO_ST_MASK     (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_IO_ST_MASK                  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_IO_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_IO_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_IO_ST_SHIFT    (9U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_IO_ST_SHIFT                 (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_IO_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_IO_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_IO_ST_IRQ_TRU               (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_IO_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_IO_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_IO_ST_IRQ_FAL               (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_IO_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_GPU_DONE_ST_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_GPU_DONE_ST_MASK        (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_GPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_GPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_GPU_DONE_ST_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_GPU_DONE_ST_SHIFT       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_GPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_GPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_GPU_DONE_ST_IRQ_TRU     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_GPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_GPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_GPU_DONE_ST_IRQ_FAL     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_GPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GMAC_RECAL_ST_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_GMAC_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GMAC_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GMAC_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GMAC_RECAL_ST_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_GMAC_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GMAC_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_GMAC_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_GMAC_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GPU_RECAL_ST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_GPU_RECAL_ST_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GPU_RECAL_ST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_GPU_RECAL_ST_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_GPU_RECAL_ST_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_GPU_RECAL_ST_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_GPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DDR_RECAL_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_DDR_RECAL_ST_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DDR_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DDR_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DDR_RECAL_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_DDR_RECAL_ST_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DDR_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DDR_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_DDR_RECAL_ST_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DDR_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DDR_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_DDR_RECAL_ST_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DDR_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DSP_RECAL_ST_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_DSP_RECAL_ST_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DSP_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DSP_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DSP_RECAL_ST_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_DSP_RECAL_ST_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DSP_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DSP_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_DSP_RECAL_ST_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DSP_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DSP_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_DSP_RECAL_ST_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_DSP_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_EVE_RECAL_ST_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_EVE_RECAL_ST_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_EVE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_EVE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_EVE_RECAL_ST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_EVE_RECAL_ST_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_EVE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_EVE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_EVE_RECAL_ST_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_EVE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_EVE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_DPLL_EVE_RECAL_ST_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_DPLL_EVE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_IVA_DONE_ST_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_IVA_DONE_ST_MASK        (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_IVA_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_IVA_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_IVA_DONE_ST_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_IVA_DONE_ST_SHIFT       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_IVA_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_IVA_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_IVA_DONE_ST_IRQ_TRU     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_IVA_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_IVA_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_IVA_DONE_ST_IRQ_FAL     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_IVA_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_DSPEVE_DONE_ST_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_DSPEVE_DONE_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_DSPEVE_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_DSPEVE_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_DSPEVE_DONE_ST_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_DSPEVE_DONE_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_DSPEVE_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_DSPEVE_DONE_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_ABB_DSPEVE_DONE_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_REG_RESETVAL       (0x00000000U)

/* PRM_IRQSTATUS_MPU_2_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_ABB_MPU_DONE_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_2_ABB_MPU_DONE_ST_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_ABB_MPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_ABB_MPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_ABB_MPU_DONE_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_2_ABB_MPU_DONE_ST_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_ABB_MPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_ABB_MPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_2_ABB_MPU_DONE_ST_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_ABB_MPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_ABB_MPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_MPU_2_ABB_MPU_DONE_ST_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_ABB_MPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_MPU_2_REG_RESETVAL     (0x00000000U)

/* PRM_IRQENABLE_MPU_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_TRANSITION_EN_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_TRANSITION_EN_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_TRANSITION_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_TRANSITION_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_TRANSITION_EN_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_TRANSITION_EN_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_TRANSITION_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_TRANSITION_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_TRANSITION_EN_IRQ_EN        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_TRANSITION_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_TRANSITION_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_TRANSITION_EN_IRQ_MSK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_TRANSITION_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_CORE_RECAL_EN_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_CORE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_CORE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_CORE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_CORE_RECAL_EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_CORE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_CORE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_CORE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_CORE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_CORE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_CORE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_CORE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_CORE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_IO_EN_MASK     (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_IO_EN_MASK                  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_IO_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_IO_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_IO_EN_SHIFT    (9U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_IO_EN_SHIFT                 (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_IO_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_IO_EN_IRQ_EN   (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_IO_EN_IRQ_EN                (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_IO_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_IO_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_IO_EN_IRQ_MSK               (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_IO_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_MPU_RECAL_EN_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_MPU_RECAL_EN_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_MPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_MPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_MPU_RECAL_EN_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_MPU_RECAL_EN_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_MPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_MPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_MPU_RECAL_EN_IRQ_MSK   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_MPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_MPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_MPU_RECAL_EN_IRQ_EN    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_MPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_IVA_RECAL_EN_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_IVA_RECAL_EN_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_IVA_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_IVA_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_IVA_RECAL_EN_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_IVA_RECAL_EN_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_IVA_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_IVA_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_IVA_RECAL_EN_IRQ_MSK   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_IVA_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_IVA_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_IVA_RECAL_EN_IRQ_EN    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_IVA_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_PER_RECAL_EN_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_PER_RECAL_EN_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_PER_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_PER_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_PER_RECAL_EN_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_PER_RECAL_EN_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_PER_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_PER_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_PER_RECAL_EN_IRQ_MSK   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_PER_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_PER_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_PER_RECAL_EN_IRQ_EN    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_PER_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_ABE_RECAL_EN_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_ABE_RECAL_EN_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_ABE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_ABE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_ABE_RECAL_EN_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_ABE_RECAL_EN_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_ABE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_ABE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_ABE_RECAL_EN_IRQ_MSK   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_ABE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_ABE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_ABE_RECAL_EN_IRQ_EN    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_ABE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_IVA_DONE_EN_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_IVA_DONE_EN_MASK        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_IVA_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_IVA_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_IVA_DONE_EN_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_IVA_DONE_EN_SHIFT       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_IVA_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_IVA_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_IVA_DONE_EN_IRQ_TRU     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_IVA_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_IVA_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_IVA_DONE_EN_IRQ_FAL     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_IVA_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GMAC_RECAL_EN_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_GMAC_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GMAC_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GMAC_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GMAC_RECAL_EN_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_GMAC_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GMAC_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_GMAC_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GMAC_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_GMAC_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GMAC_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GPU_RECAL_EN_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_GPU_RECAL_EN_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GPU_RECAL_EN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_GPU_RECAL_EN_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_GPU_RECAL_EN_IRQ_MSK   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_GPU_RECAL_EN_IRQ_EN    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_GPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DDR_RECAL_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_DDR_RECAL_EN_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DDR_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DDR_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DDR_RECAL_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_DDR_RECAL_EN_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DDR_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DDR_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_DDR_RECAL_EN_IRQ_MSK   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DDR_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DDR_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_DDR_RECAL_EN_IRQ_EN    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DDR_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DSP_RECAL_EN_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_DSP_RECAL_EN_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DSP_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DSP_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DSP_RECAL_EN_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_DSP_RECAL_EN_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DSP_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DSP_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_DSP_RECAL_EN_IRQ_MSK   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DSP_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DSP_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_DSP_RECAL_EN_IRQ_EN    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_DSP_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_EVE_RECAL_EN_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_EVE_RECAL_EN_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_EVE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_EVE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_EVE_RECAL_EN_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_EVE_RECAL_EN_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_EVE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_EVE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_EVE_RECAL_EN_IRQ_MSK   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_EVE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_EVE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_DPLL_EVE_RECAL_EN_IRQ_EN    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_DPLL_EVE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_GPU_DONE_EN_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_GPU_DONE_EN_MASK        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_GPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_GPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_GPU_DONE_EN_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_GPU_DONE_EN_SHIFT       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_GPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_GPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_GPU_DONE_EN_IRQ_TRU     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_GPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_GPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_GPU_DONE_EN_IRQ_FAL     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_GPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_DSPEVE_DONE_EN_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_DSPEVE_DONE_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_DSPEVE_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_DSPEVE_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_DSPEVE_DONE_EN_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_DSPEVE_DONE_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_DSPEVE_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_DSPEVE_DONE_EN_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_ABB_DSPEVE_DONE_EN_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_REG_RESETVAL       (0x00000000U)

/* PRM_IRQENABLE_MPU_2_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_ABB_MPU_DONE_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_2_ABB_MPU_DONE_EN_MASK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_ABB_MPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_ABB_MPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_ABB_MPU_DONE_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_2_ABB_MPU_DONE_EN_SHIFT     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_ABB_MPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_ABB_MPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_2_ABB_MPU_DONE_EN_IRQ_TRU   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_ABB_MPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_ABB_MPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_MPU_2_ABB_MPU_DONE_EN_IRQ_FAL   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_ABB_MPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_MPU_2_REG_RESETVAL     (0x00000000U)

/* PRM_IRQSTATUS_IPU2_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_FORCEWKUP_ST_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_FORCEWKUP_ST_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_FORCEWKUP_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_FORCEWKUP_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_FORCEWKUP_ST_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_FORCEWKUP_ST_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_FORCEWKUP_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_FORCEWKUP_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_FORCEWKUP_ST_IRQ_TRU       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_FORCEWKUP_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_FORCEWKUP_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_FORCEWKUP_ST_IRQ_FAL       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_FORCEWKUP_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_CORE_RECAL_ST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_CORE_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_CORE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_CORE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_CORE_RECAL_ST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_CORE_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_CORE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_CORE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_CORE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_CORE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_CORE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_CORE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_CORE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_MPU_RECAL_ST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_MPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_MPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_MPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_MPU_RECAL_ST_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_MPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_MPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_MPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_MPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_MPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_MPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_MPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_MPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_IVA_RECAL_ST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_IVA_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_IVA_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_IVA_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_IVA_RECAL_ST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_IVA_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_IVA_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_IVA_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_IVA_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_IVA_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_IVA_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_IVA_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_IVA_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_PER_RECAL_ST_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_PER_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_PER_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_PER_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_PER_RECAL_ST_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_PER_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_PER_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_PER_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_PER_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_PER_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_PER_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_PER_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_PER_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_ABE_RECAL_ST_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_ABE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_ABE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_ABE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_ABE_RECAL_ST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_ABE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_ABE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_ABE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_ABE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_ABE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_ABE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_ABE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_ABE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GMAC_RECAL_ST_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_GMAC_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GMAC_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GMAC_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GMAC_RECAL_ST_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_GMAC_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GMAC_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_GMAC_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_GMAC_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GPU_RECAL_ST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_GPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GPU_RECAL_ST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_GPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_GPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_GPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_GPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DDR_RECAL_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_DDR_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DDR_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DDR_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DDR_RECAL_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_DDR_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DDR_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DDR_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_DDR_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DDR_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DDR_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_DDR_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DDR_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_TRANSITION_ST_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_TRANSITION_ST_MASK         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_TRANSITION_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_TRANSITION_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_TRANSITION_ST_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_TRANSITION_ST_SHIFT        (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_TRANSITION_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_TRANSITION_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_TRANSITION_ST_IRQ_TRU      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_TRANSITION_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_TRANSITION_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_TRANSITION_ST_IRQ_FAL      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_TRANSITION_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_IO_ST_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_IO_ST_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_IO_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_IO_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_IO_ST_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_IO_ST_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_IO_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_IO_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_IO_ST_IRQ_TRU              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_IO_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_IO_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_IO_ST_IRQ_FAL              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_IO_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DSP_RECAL_ST_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_DSP_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DSP_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DSP_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DSP_RECAL_ST_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_DSP_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DSP_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DSP_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_DSP_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DSP_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DSP_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_DSP_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_DSP_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_EVE_RECAL_ST_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_EVE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_EVE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_EVE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_EVE_RECAL_ST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_EVE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_EVE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_EVE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_EVE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_EVE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_EVE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_DPLL_EVE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_DPLL_EVE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_DSPEVE_DONE_ST_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_DSPEVE_DONE_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_DSPEVE_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_DSPEVE_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_DSPEVE_DONE_ST_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_DSPEVE_DONE_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_DSPEVE_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_DSPEVE_DONE_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_DSPEVE_DONE_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_IVA_DONE_ST_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_IVA_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_IVA_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_IVA_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_IVA_DONE_ST_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_IVA_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_IVA_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_IVA_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_IVA_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_IVA_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_IVA_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_IVA_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_IVA_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_GPU_DONE_ST_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_GPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_GPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_GPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_GPU_DONE_ST_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_GPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_GPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_GPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_GPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_GPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_GPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_GPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_GPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_MPU_DONE_ST_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_MPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_MPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_MPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_MPU_DONE_ST_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_MPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_MPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_MPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_MPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_MPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_MPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU2_ABB_MPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_ABB_MPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU2_REG_RESETVAL      (0x00000000U)

/* PRM_IRQENABLE_IPU2_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_FORCEWKUP_EN_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_FORCEWKUP_EN_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_FORCEWKUP_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_FORCEWKUP_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_FORCEWKUP_EN_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_FORCEWKUP_EN_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_FORCEWKUP_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_FORCEWKUP_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_FORCEWKUP_EN_IRQ_EN        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_FORCEWKUP_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_FORCEWKUP_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_FORCEWKUP_EN_IRQ_MSK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_FORCEWKUP_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_CORE_RECAL_EN_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_CORE_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_CORE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_CORE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_CORE_RECAL_EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_CORE_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_CORE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_CORE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_CORE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_CORE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_CORE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_CORE_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_CORE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_MPU_RECAL_EN_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_MPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_MPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_MPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_MPU_RECAL_EN_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_MPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_MPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_MPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_MPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_MPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_MPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_MPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_MPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_IVA_RECAL_EN_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_IVA_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_IVA_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_IVA_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_IVA_RECAL_EN_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_IVA_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_IVA_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_IVA_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_IVA_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_IVA_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_IVA_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_IVA_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_IVA_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_PER_RECAL_EN_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_PER_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_PER_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_PER_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_PER_RECAL_EN_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_PER_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_PER_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_PER_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_PER_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_PER_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_PER_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_PER_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_PER_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_ABE_RECAL_EN_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_ABE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_ABE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_ABE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_ABE_RECAL_EN_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_ABE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_ABE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_ABE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_ABE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_ABE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_ABE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_ABE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_ABE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GMAC_RECAL_EN_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_GMAC_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GMAC_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GMAC_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GMAC_RECAL_EN_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_GMAC_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GMAC_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_GMAC_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GMAC_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_GMAC_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GMAC_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GPU_RECAL_EN_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_GPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GPU_RECAL_EN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_GPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_GPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_GPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_GPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DDR_RECAL_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_DDR_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DDR_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DDR_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DDR_RECAL_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_DDR_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DDR_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DDR_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_DDR_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DDR_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DDR_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_DDR_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DDR_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_TRANSITION_EN_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_TRANSITION_EN_MASK         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_TRANSITION_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_TRANSITION_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_TRANSITION_EN_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_TRANSITION_EN_SHIFT        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_TRANSITION_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_TRANSITION_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_TRANSITION_EN_IRQ_EN       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_TRANSITION_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_TRANSITION_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_TRANSITION_EN_IRQ_MSK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_TRANSITION_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_IO_EN_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_IO_EN_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_IO_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_IO_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_IO_EN_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_IO_EN_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_IO_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_IO_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_IO_EN_IRQ_EN               (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_IO_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_IO_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_IO_EN_IRQ_MSK              (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_IO_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DSP_RECAL_EN_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_DSP_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DSP_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DSP_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DSP_RECAL_EN_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_DSP_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DSP_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DSP_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_DSP_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DSP_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DSP_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_DSP_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_DSP_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_EVE_RECAL_EN_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_EVE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_EVE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_EVE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_EVE_RECAL_EN_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_EVE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_EVE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_EVE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_EVE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_EVE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_EVE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_DPLL_EVE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_DPLL_EVE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_GPU_DONE_EN_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_GPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_GPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_GPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_GPU_DONE_EN_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_GPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_GPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_GPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_GPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_GPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_GPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_GPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_GPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_DSPEVE_DONE_EN_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_DSPEVE_DONE_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_DSPEVE_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_DSPEVE_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_DSPEVE_DONE_EN_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_DSPEVE_DONE_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_DSPEVE_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_DSPEVE_DONE_EN_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_DSPEVE_DONE_EN_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_IVA_DONE_EN_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_IVA_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_IVA_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_IVA_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_IVA_DONE_EN_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_IVA_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_IVA_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_IVA_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_IVA_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_IVA_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_IVA_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_IVA_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_IVA_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_MPU_DONE_EN_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_MPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_MPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_MPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_MPU_DONE_EN_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_MPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_MPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_MPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_MPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_MPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_MPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU2_ABB_MPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_ABB_MPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU2_REG_RESETVAL      (0x00000000U)

/* PRM_IRQSTATUS_DSP1_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_CORE_RECAL_ST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_CORE_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_CORE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_CORE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_CORE_RECAL_ST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_CORE_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_CORE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_CORE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_CORE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_CORE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_CORE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_CORE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_CORE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_MPU_RECAL_ST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_MPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_MPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_MPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_MPU_RECAL_ST_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_MPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_MPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_MPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_MPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_MPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_MPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_MPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_MPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_IVA_RECAL_ST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_IVA_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_IVA_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_IVA_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_IVA_RECAL_ST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_IVA_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_IVA_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_IVA_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_IVA_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_IVA_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_IVA_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_IVA_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_IVA_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_PER_RECAL_ST_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_PER_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_PER_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_PER_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_PER_RECAL_ST_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_PER_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_PER_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_PER_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_PER_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_PER_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_PER_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_PER_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_PER_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_ABE_RECAL_ST_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_ABE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_ABE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_ABE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_ABE_RECAL_ST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_ABE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_ABE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_ABE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_ABE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_ABE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_ABE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_ABE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_ABE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GMAC_RECAL_ST_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_GMAC_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GMAC_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GMAC_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GMAC_RECAL_ST_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_GMAC_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GMAC_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_GMAC_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_GMAC_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GPU_RECAL_ST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_GPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GPU_RECAL_ST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_GPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_GPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_GPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_GPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DDR_RECAL_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_DDR_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DDR_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DDR_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DDR_RECAL_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_DDR_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DDR_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DDR_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_DDR_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DDR_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DDR_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_DDR_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DDR_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_IO_ST_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_IO_ST_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_IO_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_IO_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_IO_ST_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_IO_ST_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_IO_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_IO_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_IO_ST_IRQ_TRU              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_IO_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_IO_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_IO_ST_IRQ_FAL              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_IO_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_FORCEWKUP_ST_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_FORCEWKUP_ST_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_FORCEWKUP_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_FORCEWKUP_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_FORCEWKUP_ST_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_FORCEWKUP_ST_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_FORCEWKUP_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_FORCEWKUP_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_FORCEWKUP_ST_IRQ_TRU       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_FORCEWKUP_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_FORCEWKUP_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_FORCEWKUP_ST_IRQ_FAL       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_FORCEWKUP_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DSP_RECAL_ST_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_DSP_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DSP_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DSP_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DSP_RECAL_ST_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_DSP_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DSP_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DSP_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_DSP_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DSP_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DSP_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_DSP_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_DSP_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_EVE_RECAL_ST_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_EVE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_EVE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_EVE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_EVE_RECAL_ST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_EVE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_EVE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_EVE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_EVE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_EVE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_EVE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_DPLL_EVE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_DPLL_EVE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_GPU_DONE_ST_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_GPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_GPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_GPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_GPU_DONE_ST_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_GPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_GPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_GPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_GPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_GPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_GPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_GPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_GPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_DSPEVE_DONE_ST_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_DSPEVE_DONE_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_DSPEVE_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_DSPEVE_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_DSPEVE_DONE_ST_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_DSPEVE_DONE_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_DSPEVE_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_DSPEVE_DONE_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_DSPEVE_DONE_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_IVA_DONE_ST_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_IVA_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_IVA_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_IVA_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_IVA_DONE_ST_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_IVA_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_IVA_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_IVA_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_IVA_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_IVA_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_IVA_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_IVA_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_IVA_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_MPU_DONE_ST_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_MPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_MPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_MPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_MPU_DONE_ST_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_MPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_MPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_MPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_MPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_MPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_MPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP1_ABB_MPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_ABB_MPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP1_REG_RESETVAL      (0x00000000U)

/* PRM_IRQENABLE_DSP1_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_CORE_RECAL_EN_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_CORE_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_CORE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_CORE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_CORE_RECAL_EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_CORE_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_CORE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_CORE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_CORE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_CORE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_CORE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_CORE_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_CORE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_MPU_RECAL_EN_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_MPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_MPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_MPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_MPU_RECAL_EN_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_MPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_MPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_MPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_MPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_MPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_MPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_MPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_MPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_IVA_RECAL_EN_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_IVA_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_IVA_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_IVA_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_IVA_RECAL_EN_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_IVA_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_IVA_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_IVA_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_IVA_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_IVA_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_IVA_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_IVA_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_IVA_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_PER_RECAL_EN_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_PER_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_PER_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_PER_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_PER_RECAL_EN_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_PER_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_PER_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_PER_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_PER_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_PER_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_PER_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_PER_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_PER_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_ABE_RECAL_EN_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_ABE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_ABE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_ABE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_ABE_RECAL_EN_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_ABE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_ABE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_ABE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_ABE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_ABE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_ABE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_ABE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_ABE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GMAC_RECAL_EN_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_GMAC_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GMAC_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GMAC_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GMAC_RECAL_EN_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_GMAC_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GMAC_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_GMAC_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GMAC_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_GMAC_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GMAC_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GPU_RECAL_EN_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_GPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GPU_RECAL_EN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_GPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_GPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_GPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_GPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DDR_RECAL_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_DDR_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DDR_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DDR_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DDR_RECAL_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_DDR_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DDR_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DDR_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_DDR_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DDR_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DDR_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_DDR_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DDR_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_IO_EN_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_IO_EN_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_IO_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_IO_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_IO_EN_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_IO_EN_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_IO_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_IO_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_IO_EN_IRQ_EN               (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_IO_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_IO_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_IO_EN_IRQ_MSK              (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_IO_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_FORCEWKUP_EN_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_FORCEWKUP_EN_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_FORCEWKUP_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_FORCEWKUP_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_FORCEWKUP_EN_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_FORCEWKUP_EN_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_FORCEWKUP_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_FORCEWKUP_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_FORCEWKUP_EN_IRQ_EN        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_FORCEWKUP_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_FORCEWKUP_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_FORCEWKUP_EN_IRQ_MSK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_FORCEWKUP_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DSP_RECAL_EN_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_DSP_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DSP_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DSP_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DSP_RECAL_EN_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_DSP_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DSP_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DSP_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_DSP_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DSP_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DSP_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_DSP_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_DSP_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_EVE_RECAL_EN_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_EVE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_EVE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_EVE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_EVE_RECAL_EN_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_EVE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_EVE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_EVE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_EVE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_EVE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_EVE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_EVE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_EVE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_USB_RECAL_EN_MASK  (0x00002000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_USB_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_USB_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_USB_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_USB_RECAL_EN_SHIFT  (13U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_USB_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_USB_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_USB_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_USB_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_USB_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_USB_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_DPLL_USB_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_DPLL_USB_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_GPU_DONE_EN_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_GPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_GPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_GPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_GPU_DONE_EN_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_GPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_GPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_GPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_GPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_GPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_GPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_GPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_GPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_DSPEVE_DONE_EN_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_DSPEVE_DONE_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_DSPEVE_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_DSPEVE_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_DSPEVE_DONE_EN_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_DSPEVE_DONE_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_DSPEVE_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_DSPEVE_DONE_EN_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_DSPEVE_DONE_EN_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_IVA_DONE_EN_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_IVA_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_IVA_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_IVA_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_IVA_DONE_EN_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_IVA_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_IVA_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_IVA_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_IVA_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_IVA_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_IVA_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_IVA_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_IVA_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_MPU_DONE_EN_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_MPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_MPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_MPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_MPU_DONE_EN_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_MPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_MPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_MPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_MPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_MPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_MPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP1_ABB_MPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_ABB_MPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP1_REG_RESETVAL      (0x00000000U)

/* CM_PRM_PROFILING_CLKCTRL_REG */

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_MASK  (0x00000003U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_MODULEMODE_MASK      (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_MASK)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_SHIFT  (0U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_MODULEMODE_SHIFT     (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_SHIFT)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_DISABLED  (0x00000000U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_MODULEMODE_DISABLED  (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_DISABLED)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_AUTO  (0x00000001U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_MODULEMODE_AUTO      (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_AUTO)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_RESERVED_2  (0x00000002U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_MODULEMODE_RESERVED_2  (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_RESERVED_2)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_RESERVED  (0x00000003U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_MODULEMODE_RESERVED  (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_MODULEMODE_RESERVED)


#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_MASK  (0x00030000U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_IDLEST_MASK          (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_MASK)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_RESETVAL  (0x00000003U)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_SHIFT  (16U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_IDLEST_SHIFT         (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_SHIFT)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_DISABLE  (0x00000003U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_IDLEST_DISABLE       (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_DISABLE)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_IDLE  (0x00000002U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_IDLEST_IDLE          (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_IDLE)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_FUNC  (0x00000000U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_IDLEST_FUNC          (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_FUNC)

#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_TRANS  (0x00000001U)
/* Below define for backward compatibility */
#define CM_PRM_PROFILING_CLKCTRL_IDLEST_TRANS         (CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_IDLEST_TRANS)


#define CSL_OCP_SOCKET_PRM_CM_PRM_PROFILING_CLKCTRL_REG_RESETVAL  (0x00030000U)

/* PRM_IRQENABLE_DSP2_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_CORE_RECAL_EN_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_CORE_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_CORE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_CORE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_CORE_RECAL_EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_CORE_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_CORE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_CORE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_CORE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_CORE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_CORE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_CORE_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_CORE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_MPU_RECAL_EN_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_MPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_MPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_MPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_MPU_RECAL_EN_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_MPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_MPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_MPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_MPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_MPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_MPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_MPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_MPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_IVA_RECAL_EN_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_IVA_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_IVA_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_IVA_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_IVA_RECAL_EN_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_IVA_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_IVA_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_IVA_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_IVA_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_IVA_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_IVA_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_IVA_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_IVA_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_PER_RECAL_EN_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_PER_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_PER_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_PER_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_PER_RECAL_EN_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_PER_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_PER_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_PER_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_PER_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_PER_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_PER_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_PER_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_PER_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_ABE_RECAL_EN_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_ABE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_ABE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_ABE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_ABE_RECAL_EN_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_ABE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_ABE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_ABE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_ABE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_ABE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_ABE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_ABE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_ABE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GMAC_RECAL_EN_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_GMAC_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GMAC_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GMAC_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GMAC_RECAL_EN_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_GMAC_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GMAC_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_GMAC_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GMAC_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_GMAC_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GMAC_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GPU_RECAL_EN_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_GPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GPU_RECAL_EN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_GPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_GPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_GPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_GPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DDR_RECAL_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_DDR_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DDR_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DDR_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DDR_RECAL_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_DDR_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DDR_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DDR_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_DDR_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DDR_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DDR_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_DDR_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DDR_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_IO_EN_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_IO_EN_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_IO_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_IO_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_IO_EN_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_IO_EN_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_IO_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_IO_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_IO_EN_IRQ_EN               (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_IO_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_IO_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_IO_EN_IRQ_MSK              (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_IO_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_FORCEWKUP_EN_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_FORCEWKUP_EN_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_FORCEWKUP_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_FORCEWKUP_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_FORCEWKUP_EN_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_FORCEWKUP_EN_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_FORCEWKUP_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_FORCEWKUP_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_FORCEWKUP_EN_IRQ_EN        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_FORCEWKUP_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_FORCEWKUP_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_FORCEWKUP_EN_IRQ_MSK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_FORCEWKUP_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DSP_RECAL_EN_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_DSP_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DSP_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DSP_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DSP_RECAL_EN_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_DSP_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DSP_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DSP_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_DSP_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DSP_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DSP_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_DSP_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_DSP_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_EVE_RECAL_EN_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_EVE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_EVE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_EVE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_EVE_RECAL_EN_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_EVE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_EVE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_EVE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_EVE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_EVE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_EVE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_DPLL_EVE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_DPLL_EVE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_GPU_DONE_EN_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_GPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_GPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_GPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_GPU_DONE_EN_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_GPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_GPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_GPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_GPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_GPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_GPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_GPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_GPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_DSPEVE_DONE_EN_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_DSPEVE_DONE_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_DSPEVE_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_DSPEVE_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_DSPEVE_DONE_EN_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_DSPEVE_DONE_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_DSPEVE_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_DSPEVE_DONE_EN_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_DSPEVE_DONE_EN_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_IVA_DONE_EN_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_IVA_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_IVA_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_IVA_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_IVA_DONE_EN_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_IVA_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_IVA_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_IVA_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_IVA_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_IVA_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_IVA_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_IVA_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_IVA_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_MPU_DONE_EN_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_MPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_MPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_MPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_MPU_DONE_EN_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_MPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_MPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_MPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_MPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_MPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_MPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_DSP2_ABB_MPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_ABB_MPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_DSP2_REG_RESETVAL      (0x00000000U)

/* PRM_IRQENABLE_EVE1_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_CORE_RECAL_EN_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_CORE_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_CORE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_CORE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_CORE_RECAL_EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_CORE_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_CORE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_CORE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_CORE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_CORE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_CORE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_CORE_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_CORE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_MPU_RECAL_EN_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_MPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_MPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_MPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_MPU_RECAL_EN_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_MPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_MPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_MPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_MPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_MPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_MPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_MPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_MPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_IVA_RECAL_EN_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_IVA_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_IVA_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_IVA_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_IVA_RECAL_EN_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_IVA_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_IVA_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_IVA_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_IVA_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_IVA_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_IVA_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_IVA_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_IVA_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_PER_RECAL_EN_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_PER_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_PER_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_PER_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_PER_RECAL_EN_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_PER_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_PER_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_PER_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_PER_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_PER_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_PER_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_PER_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_PER_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_ABE_RECAL_EN_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_ABE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_ABE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_ABE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_ABE_RECAL_EN_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_ABE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_ABE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_ABE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_ABE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_ABE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_ABE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_ABE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_ABE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GMAC_RECAL_EN_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_GMAC_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GMAC_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GMAC_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GMAC_RECAL_EN_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_GMAC_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GMAC_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_GMAC_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GMAC_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_GMAC_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GMAC_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GPU_RECAL_EN_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_GPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GPU_RECAL_EN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_GPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_GPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_GPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_GPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DDR_RECAL_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_DDR_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DDR_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DDR_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DDR_RECAL_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_DDR_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DDR_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DDR_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_DDR_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DDR_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DDR_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_DDR_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DDR_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_IO_EN_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_IO_EN_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_IO_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_IO_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_IO_EN_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_IO_EN_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_IO_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_IO_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_IO_EN_IRQ_EN               (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_IO_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_IO_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_IO_EN_IRQ_MSK              (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_IO_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_FORCEWKUP_EN_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_FORCEWKUP_EN_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_FORCEWKUP_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_FORCEWKUP_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_FORCEWKUP_EN_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_FORCEWKUP_EN_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_FORCEWKUP_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_FORCEWKUP_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_FORCEWKUP_EN_IRQ_EN        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_FORCEWKUP_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_FORCEWKUP_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_FORCEWKUP_EN_IRQ_MSK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_FORCEWKUP_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DSP_RECAL_EN_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_DSP_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DSP_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DSP_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DSP_RECAL_EN_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_DSP_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DSP_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DSP_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_DSP_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DSP_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DSP_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_DSP_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_DSP_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_EVE_RECAL_EN_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_EVE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_EVE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_EVE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_EVE_RECAL_EN_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_EVE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_EVE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_EVE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_EVE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_EVE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_EVE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_DPLL_EVE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_DPLL_EVE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_GPU_DONE_EN_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_GPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_GPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_GPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_GPU_DONE_EN_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_GPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_GPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_GPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_GPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_GPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_GPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_GPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_GPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_DSPEVE_DONE_EN_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_DSPEVE_DONE_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_DSPEVE_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_DSPEVE_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_DSPEVE_DONE_EN_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_DSPEVE_DONE_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_DSPEVE_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_DSPEVE_DONE_EN_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_DSPEVE_DONE_EN_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_IVA_DONE_EN_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_IVA_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_IVA_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_IVA_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_IVA_DONE_EN_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_IVA_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_IVA_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_IVA_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_IVA_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_IVA_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_IVA_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_IVA_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_IVA_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_MPU_DONE_EN_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_MPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_MPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_MPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_MPU_DONE_EN_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_MPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_MPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_MPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_MPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_MPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_MPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE1_ABB_MPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_ABB_MPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE1_REG_RESETVAL      (0x00000000U)

/* PRM_IRQENABLE_EVE2_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_CORE_RECAL_EN_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_CORE_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_CORE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_CORE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_CORE_RECAL_EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_CORE_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_CORE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_CORE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_CORE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_CORE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_CORE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_CORE_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_CORE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_MPU_RECAL_EN_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_MPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_MPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_MPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_MPU_RECAL_EN_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_MPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_MPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_MPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_MPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_MPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_MPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_MPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_MPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_IVA_RECAL_EN_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_IVA_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_IVA_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_IVA_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_IVA_RECAL_EN_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_IVA_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_IVA_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_IVA_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_IVA_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_IVA_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_IVA_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_IVA_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_IVA_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_PER_RECAL_EN_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_PER_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_PER_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_PER_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_PER_RECAL_EN_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_PER_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_PER_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_PER_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_PER_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_PER_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_PER_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_PER_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_PER_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_ABE_RECAL_EN_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_ABE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_ABE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_ABE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_ABE_RECAL_EN_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_ABE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_ABE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_ABE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_ABE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_ABE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_ABE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_ABE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_ABE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GMAC_RECAL_EN_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_GMAC_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GMAC_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GMAC_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GMAC_RECAL_EN_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_GMAC_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GMAC_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_GMAC_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GMAC_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_GMAC_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GMAC_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GPU_RECAL_EN_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_GPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GPU_RECAL_EN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_GPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_GPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_GPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_GPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DDR_RECAL_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_DDR_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DDR_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DDR_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DDR_RECAL_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_DDR_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DDR_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DDR_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_DDR_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DDR_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DDR_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_DDR_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DDR_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_IO_EN_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_IO_EN_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_IO_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_IO_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_IO_EN_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_IO_EN_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_IO_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_IO_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_IO_EN_IRQ_EN               (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_IO_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_IO_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_IO_EN_IRQ_MSK              (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_IO_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_FORCEWKUP_EN_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_FORCEWKUP_EN_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_FORCEWKUP_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_FORCEWKUP_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_FORCEWKUP_EN_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_FORCEWKUP_EN_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_FORCEWKUP_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_FORCEWKUP_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_FORCEWKUP_EN_IRQ_EN        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_FORCEWKUP_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_FORCEWKUP_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_FORCEWKUP_EN_IRQ_MSK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_FORCEWKUP_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DSP_RECAL_EN_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_DSP_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DSP_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DSP_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DSP_RECAL_EN_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_DSP_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DSP_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DSP_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_DSP_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DSP_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DSP_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_DSP_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_DSP_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_EVE_RECAL_EN_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_EVE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_EVE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_EVE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_EVE_RECAL_EN_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_EVE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_EVE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_EVE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_EVE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_EVE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_EVE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_DPLL_EVE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_DPLL_EVE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_GPU_DONE_EN_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_GPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_GPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_GPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_GPU_DONE_EN_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_GPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_GPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_GPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_GPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_GPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_GPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_GPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_GPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_DSPEVE_DONE_EN_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_DSPEVE_DONE_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_DSPEVE_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_DSPEVE_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_DSPEVE_DONE_EN_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_DSPEVE_DONE_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_DSPEVE_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_DSPEVE_DONE_EN_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_DSPEVE_DONE_EN_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_IVA_DONE_EN_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_IVA_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_IVA_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_IVA_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_IVA_DONE_EN_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_IVA_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_IVA_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_IVA_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_IVA_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_IVA_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_IVA_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_IVA_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_IVA_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_MPU_DONE_EN_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_MPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_MPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_MPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_MPU_DONE_EN_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_MPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_MPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_MPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_MPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_MPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_MPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE2_ABB_MPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_ABB_MPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE2_REG_RESETVAL      (0x00000000U)

/* PRM_IRQENABLE_EVE3_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_CORE_RECAL_EN_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_CORE_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_CORE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_CORE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_CORE_RECAL_EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_CORE_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_CORE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_CORE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_CORE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_CORE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_CORE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_CORE_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_CORE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_MPU_RECAL_EN_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_MPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_MPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_MPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_MPU_RECAL_EN_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_MPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_MPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_MPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_MPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_MPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_MPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_MPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_MPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_IVA_RECAL_EN_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_IVA_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_IVA_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_IVA_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_IVA_RECAL_EN_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_IVA_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_IVA_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_IVA_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_IVA_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_IVA_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_IVA_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_IVA_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_IVA_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_PER_RECAL_EN_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_PER_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_PER_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_PER_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_PER_RECAL_EN_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_PER_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_PER_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_PER_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_PER_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_PER_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_PER_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_PER_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_PER_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_ABE_RECAL_EN_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_ABE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_ABE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_ABE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_ABE_RECAL_EN_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_ABE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_ABE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_ABE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_ABE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_ABE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_ABE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_ABE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_ABE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GMAC_RECAL_EN_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_GMAC_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GMAC_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GMAC_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GMAC_RECAL_EN_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_GMAC_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GMAC_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_GMAC_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GMAC_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_GMAC_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GMAC_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GPU_RECAL_EN_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_GPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GPU_RECAL_EN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_GPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_GPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_GPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_GPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DDR_RECAL_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_DDR_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DDR_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DDR_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DDR_RECAL_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_DDR_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DDR_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DDR_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_DDR_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DDR_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DDR_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_DDR_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DDR_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_IO_EN_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_IO_EN_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_IO_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_IO_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_IO_EN_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_IO_EN_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_IO_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_IO_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_IO_EN_IRQ_EN               (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_IO_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_IO_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_IO_EN_IRQ_MSK              (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_IO_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_FORCEWKUP_EN_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_FORCEWKUP_EN_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_FORCEWKUP_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_FORCEWKUP_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_FORCEWKUP_EN_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_FORCEWKUP_EN_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_FORCEWKUP_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_FORCEWKUP_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_FORCEWKUP_EN_IRQ_EN        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_FORCEWKUP_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_FORCEWKUP_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_FORCEWKUP_EN_IRQ_MSK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_FORCEWKUP_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DSP_RECAL_EN_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_DSP_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DSP_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DSP_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DSP_RECAL_EN_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_DSP_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DSP_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DSP_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_DSP_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DSP_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DSP_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_DSP_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_DSP_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_EVE_RECAL_EN_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_EVE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_EVE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_EVE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_EVE_RECAL_EN_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_EVE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_EVE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_EVE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_EVE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_EVE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_EVE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_DPLL_EVE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_DPLL_EVE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_GPU_DONE_EN_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_GPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_GPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_GPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_GPU_DONE_EN_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_GPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_GPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_GPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_GPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_GPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_GPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_GPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_GPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_DSPEVE_DONE_EN_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_DSPEVE_DONE_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_DSPEVE_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_DSPEVE_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_DSPEVE_DONE_EN_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_DSPEVE_DONE_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_DSPEVE_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_DSPEVE_DONE_EN_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_DSPEVE_DONE_EN_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_IVA_DONE_EN_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_IVA_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_IVA_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_IVA_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_IVA_DONE_EN_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_IVA_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_IVA_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_IVA_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_IVA_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_IVA_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_IVA_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_IVA_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_IVA_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_MPU_DONE_EN_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_MPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_MPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_MPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_MPU_DONE_EN_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_MPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_MPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_MPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_MPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_MPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_MPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE3_ABB_MPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_ABB_MPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE3_REG_RESETVAL      (0x00000000U)

/* PRM_IRQENABLE_EVE4_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_CORE_RECAL_EN_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_CORE_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_CORE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_CORE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_CORE_RECAL_EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_CORE_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_CORE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_CORE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_CORE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_CORE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_CORE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_CORE_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_CORE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_MPU_RECAL_EN_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_MPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_MPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_MPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_MPU_RECAL_EN_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_MPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_MPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_MPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_MPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_MPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_MPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_MPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_MPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_IVA_RECAL_EN_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_IVA_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_IVA_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_IVA_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_IVA_RECAL_EN_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_IVA_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_IVA_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_IVA_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_IVA_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_IVA_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_IVA_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_IVA_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_IVA_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_PER_RECAL_EN_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_PER_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_PER_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_PER_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_PER_RECAL_EN_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_PER_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_PER_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_PER_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_PER_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_PER_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_PER_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_PER_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_PER_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_ABE_RECAL_EN_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_ABE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_ABE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_ABE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_ABE_RECAL_EN_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_ABE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_ABE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_ABE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_ABE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_ABE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_ABE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_ABE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_ABE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GMAC_RECAL_EN_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_GMAC_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GMAC_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GMAC_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GMAC_RECAL_EN_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_GMAC_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GMAC_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_GMAC_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GMAC_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_GMAC_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GMAC_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GPU_RECAL_EN_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_GPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GPU_RECAL_EN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_GPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_GPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_GPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_GPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DDR_RECAL_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_DDR_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DDR_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DDR_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DDR_RECAL_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_DDR_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DDR_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DDR_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_DDR_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DDR_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DDR_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_DDR_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DDR_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_IO_EN_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_IO_EN_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_IO_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_IO_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_IO_EN_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_IO_EN_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_IO_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_IO_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_IO_EN_IRQ_EN               (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_IO_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_IO_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_IO_EN_IRQ_MSK              (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_IO_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_FORCEWKUP_EN_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_FORCEWKUP_EN_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_FORCEWKUP_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_FORCEWKUP_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_FORCEWKUP_EN_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_FORCEWKUP_EN_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_FORCEWKUP_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_FORCEWKUP_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_FORCEWKUP_EN_IRQ_EN        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_FORCEWKUP_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_FORCEWKUP_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_FORCEWKUP_EN_IRQ_MSK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_FORCEWKUP_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DSP_RECAL_EN_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_DSP_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DSP_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DSP_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DSP_RECAL_EN_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_DSP_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DSP_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DSP_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_DSP_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DSP_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DSP_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_DSP_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_DSP_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_EVE_RECAL_EN_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_EVE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_EVE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_EVE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_EVE_RECAL_EN_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_EVE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_EVE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_EVE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_EVE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_EVE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_EVE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_DPLL_EVE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_DPLL_EVE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_GPU_DONE_EN_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_GPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_GPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_GPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_GPU_DONE_EN_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_GPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_GPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_GPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_GPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_GPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_GPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_GPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_GPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_DSPEVE_DONE_EN_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_DSPEVE_DONE_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_DSPEVE_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_DSPEVE_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_DSPEVE_DONE_EN_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_DSPEVE_DONE_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_DSPEVE_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_DSPEVE_DONE_EN_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_DSPEVE_DONE_EN_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_IVA_DONE_EN_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_IVA_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_IVA_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_IVA_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_IVA_DONE_EN_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_IVA_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_IVA_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_IVA_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_IVA_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_IVA_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_IVA_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_IVA_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_IVA_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_MPU_DONE_EN_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_MPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_MPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_MPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_MPU_DONE_EN_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_MPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_MPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_MPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_MPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_MPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_MPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_EVE4_ABB_MPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_ABB_MPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_EVE4_REG_RESETVAL      (0x00000000U)

/* PRM_IRQENABLE_IPU1_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_CORE_RECAL_EN_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_CORE_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_CORE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_CORE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_CORE_RECAL_EN_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_CORE_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_CORE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_CORE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_CORE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_CORE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_CORE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_CORE_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_CORE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_MPU_RECAL_EN_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_MPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_MPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_MPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_MPU_RECAL_EN_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_MPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_MPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_MPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_MPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_MPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_MPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_MPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_MPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_IVA_RECAL_EN_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_IVA_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_IVA_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_IVA_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_IVA_RECAL_EN_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_IVA_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_IVA_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_IVA_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_IVA_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_IVA_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_IVA_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_IVA_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_IVA_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_PER_RECAL_EN_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_PER_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_PER_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_PER_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_PER_RECAL_EN_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_PER_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_PER_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_PER_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_PER_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_PER_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_PER_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_PER_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_PER_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_ABE_RECAL_EN_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_ABE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_ABE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_ABE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_ABE_RECAL_EN_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_ABE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_ABE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_ABE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_ABE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_ABE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_ABE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_ABE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_ABE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GMAC_RECAL_EN_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_GMAC_RECAL_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GMAC_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GMAC_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GMAC_RECAL_EN_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_GMAC_RECAL_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GMAC_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_GMAC_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GMAC_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GMAC_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_GMAC_RECAL_EN_IRQ_EN  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GMAC_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GPU_RECAL_EN_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_GPU_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GPU_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GPU_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GPU_RECAL_EN_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_GPU_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GPU_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GPU_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_GPU_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GPU_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GPU_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_GPU_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_GPU_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DDR_RECAL_EN_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_DDR_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DDR_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DDR_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DDR_RECAL_EN_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_DDR_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DDR_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DDR_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_DDR_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DDR_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DDR_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_DDR_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DDR_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_TRANSITION_EN_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_TRANSITION_EN_MASK         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_TRANSITION_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_TRANSITION_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_TRANSITION_EN_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_TRANSITION_EN_SHIFT        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_TRANSITION_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_TRANSITION_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_TRANSITION_EN_IRQ_EN       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_TRANSITION_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_TRANSITION_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_TRANSITION_EN_IRQ_MSK      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_TRANSITION_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_IO_EN_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_IO_EN_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_IO_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_IO_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_IO_EN_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_IO_EN_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_IO_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_IO_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_IO_EN_IRQ_EN               (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_IO_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_IO_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_IO_EN_IRQ_MSK              (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_IO_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_FORCEWKUP_EN_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_FORCEWKUP_EN_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_FORCEWKUP_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_FORCEWKUP_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_FORCEWKUP_EN_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_FORCEWKUP_EN_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_FORCEWKUP_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_FORCEWKUP_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_FORCEWKUP_EN_IRQ_EN        (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_FORCEWKUP_EN_IRQ_EN)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_FORCEWKUP_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_FORCEWKUP_EN_IRQ_MSK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_FORCEWKUP_EN_IRQ_MSK)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DSP_RECAL_EN_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_DSP_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DSP_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DSP_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DSP_RECAL_EN_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_DSP_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DSP_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DSP_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_DSP_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DSP_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DSP_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_DSP_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_DSP_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_EVE_RECAL_EN_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_EVE_RECAL_EN_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_EVE_RECAL_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_EVE_RECAL_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_EVE_RECAL_EN_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_EVE_RECAL_EN_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_EVE_RECAL_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_EVE_RECAL_EN_IRQ_MSK  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_EVE_RECAL_EN_IRQ_MSK  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_EVE_RECAL_EN_IRQ_MSK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_EVE_RECAL_EN_IRQ_EN  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_DPLL_EVE_RECAL_EN_IRQ_EN   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_DPLL_EVE_RECAL_EN_IRQ_EN)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_GPU_DONE_EN_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_GPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_GPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_GPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_GPU_DONE_EN_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_GPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_GPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_GPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_GPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_GPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_GPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_GPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_GPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_DSPEVE_DONE_EN_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_DSPEVE_DONE_EN_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_DSPEVE_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_DSPEVE_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_DSPEVE_DONE_EN_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_DSPEVE_DONE_EN_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_DSPEVE_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_DSPEVE_DONE_EN_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_DSPEVE_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_DSPEVE_DONE_EN_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_DSPEVE_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_IVA_DONE_EN_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_IVA_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_IVA_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_IVA_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_IVA_DONE_EN_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_IVA_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_IVA_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_IVA_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_IVA_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_IVA_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_IVA_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_IVA_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_IVA_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_MPU_DONE_EN_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_MPU_DONE_EN_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_MPU_DONE_EN_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_MPU_DONE_EN_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_MPU_DONE_EN_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_MPU_DONE_EN_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_MPU_DONE_EN_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_MPU_DONE_EN_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_MPU_DONE_EN_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_MPU_DONE_EN_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_MPU_DONE_EN_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQENABLE_IPU1_ABB_MPU_DONE_EN_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_ABB_MPU_DONE_EN_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQENABLE_IPU1_REG_RESETVAL      (0x00000000U)

/* PRM_IRQSTATUS_DSP2_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_CORE_RECAL_ST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_CORE_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_CORE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_CORE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_CORE_RECAL_ST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_CORE_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_CORE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_CORE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_CORE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_CORE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_CORE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_CORE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_CORE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_MPU_RECAL_ST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_MPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_MPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_MPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_MPU_RECAL_ST_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_MPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_MPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_MPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_MPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_MPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_MPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_MPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_MPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_IVA_RECAL_ST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_IVA_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_IVA_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_IVA_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_IVA_RECAL_ST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_IVA_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_IVA_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_IVA_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_IVA_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_IVA_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_IVA_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_IVA_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_IVA_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_PER_RECAL_ST_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_PER_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_PER_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_PER_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_PER_RECAL_ST_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_PER_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_PER_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_PER_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_PER_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_PER_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_PER_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_PER_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_PER_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_ABE_RECAL_ST_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_ABE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_ABE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_ABE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_ABE_RECAL_ST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_ABE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_ABE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_ABE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_ABE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_ABE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_ABE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_ABE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_ABE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GMAC_RECAL_ST_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_GMAC_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GMAC_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GMAC_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GMAC_RECAL_ST_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_GMAC_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GMAC_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_GMAC_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_GMAC_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GPU_RECAL_ST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_GPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GPU_RECAL_ST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_GPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_GPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_GPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_GPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DDR_RECAL_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_DDR_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DDR_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DDR_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DDR_RECAL_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_DDR_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DDR_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DDR_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_DDR_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DDR_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DDR_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_DDR_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DDR_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_IO_ST_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_IO_ST_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_IO_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_IO_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_IO_ST_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_IO_ST_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_IO_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_IO_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_IO_ST_IRQ_TRU              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_IO_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_IO_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_IO_ST_IRQ_FAL              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_IO_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_FORCEWKUP_ST_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_FORCEWKUP_ST_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_FORCEWKUP_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_FORCEWKUP_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_FORCEWKUP_ST_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_FORCEWKUP_ST_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_FORCEWKUP_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_FORCEWKUP_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_FORCEWKUP_ST_IRQ_TRU       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_FORCEWKUP_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_FORCEWKUP_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_FORCEWKUP_ST_IRQ_FAL       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_FORCEWKUP_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DSP_RECAL_ST_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_DSP_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DSP_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DSP_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DSP_RECAL_ST_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_DSP_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DSP_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DSP_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_DSP_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DSP_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DSP_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_DSP_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_DSP_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_EVE_RECAL_ST_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_EVE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_EVE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_EVE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_EVE_RECAL_ST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_EVE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_EVE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_EVE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_EVE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_EVE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_EVE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_DPLL_EVE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_DPLL_EVE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_GPU_DONE_ST_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_GPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_GPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_GPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_GPU_DONE_ST_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_GPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_GPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_GPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_GPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_GPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_GPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_GPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_GPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_DSPEVE_DONE_ST_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_DSPEVE_DONE_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_DSPEVE_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_DSPEVE_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_DSPEVE_DONE_ST_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_DSPEVE_DONE_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_DSPEVE_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_DSPEVE_DONE_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_DSPEVE_DONE_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_IVA_DONE_ST_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_IVA_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_IVA_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_IVA_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_IVA_DONE_ST_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_IVA_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_IVA_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_IVA_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_IVA_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_IVA_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_IVA_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_IVA_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_IVA_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_MPU_DONE_ST_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_MPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_MPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_MPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_MPU_DONE_ST_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_MPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_MPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_MPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_MPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_MPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_MPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_DSP2_ABB_MPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_ABB_MPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_DSP2_REG_RESETVAL      (0x00000000U)

/* PRM_IRQSTATUS_EVE1_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_CORE_RECAL_ST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_CORE_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_CORE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_CORE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_CORE_RECAL_ST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_CORE_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_CORE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_CORE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_CORE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_CORE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_CORE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_CORE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_CORE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_MPU_RECAL_ST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_MPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_MPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_MPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_MPU_RECAL_ST_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_MPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_MPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_MPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_MPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_MPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_MPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_MPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_MPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_IVA_RECAL_ST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_IVA_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_IVA_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_IVA_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_IVA_RECAL_ST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_IVA_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_IVA_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_IVA_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_IVA_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_IVA_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_IVA_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_IVA_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_IVA_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_PER_RECAL_ST_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_PER_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_PER_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_PER_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_PER_RECAL_ST_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_PER_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_PER_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_PER_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_PER_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_PER_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_PER_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_PER_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_PER_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_ABE_RECAL_ST_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_ABE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_ABE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_ABE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_ABE_RECAL_ST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_ABE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_ABE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_ABE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_ABE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_ABE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_ABE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_ABE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_ABE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GMAC_RECAL_ST_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_GMAC_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GMAC_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GMAC_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GMAC_RECAL_ST_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_GMAC_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GMAC_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_GMAC_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_GMAC_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GPU_RECAL_ST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_GPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GPU_RECAL_ST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_GPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_GPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_GPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_GPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DDR_RECAL_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_DDR_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DDR_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DDR_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DDR_RECAL_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_DDR_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DDR_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DDR_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_DDR_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DDR_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DDR_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_DDR_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DDR_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_IO_ST_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_IO_ST_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_IO_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_IO_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_IO_ST_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_IO_ST_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_IO_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_IO_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_IO_ST_IRQ_TRU              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_IO_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_IO_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_IO_ST_IRQ_FAL              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_IO_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_FORCEWKUP_ST_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_FORCEWKUP_ST_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_FORCEWKUP_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_FORCEWKUP_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_FORCEWKUP_ST_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_FORCEWKUP_ST_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_FORCEWKUP_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_FORCEWKUP_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_FORCEWKUP_ST_IRQ_TRU       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_FORCEWKUP_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_FORCEWKUP_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_FORCEWKUP_ST_IRQ_FAL       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_FORCEWKUP_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DSP_RECAL_ST_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_DSP_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DSP_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DSP_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DSP_RECAL_ST_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_DSP_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DSP_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DSP_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_DSP_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DSP_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DSP_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_DSP_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_DSP_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_EVE_RECAL_ST_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_EVE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_EVE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_EVE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_EVE_RECAL_ST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_EVE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_EVE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_EVE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_EVE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_EVE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_EVE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_DPLL_EVE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_DPLL_EVE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_GPU_DONE_ST_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_GPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_GPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_GPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_GPU_DONE_ST_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_GPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_GPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_GPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_GPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_GPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_GPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_GPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_GPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_DSPEVE_DONE_ST_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_DSPEVE_DONE_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_DSPEVE_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_DSPEVE_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_DSPEVE_DONE_ST_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_DSPEVE_DONE_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_DSPEVE_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_DSPEVE_DONE_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_DSPEVE_DONE_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_IVA_DONE_ST_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_IVA_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_IVA_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_IVA_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_IVA_DONE_ST_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_IVA_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_IVA_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_IVA_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_IVA_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_IVA_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_IVA_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_IVA_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_IVA_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_MPU_DONE_ST_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_MPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_MPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_MPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_MPU_DONE_ST_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_MPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_MPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_MPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_MPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_MPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_MPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE1_ABB_MPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_ABB_MPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE1_REG_RESETVAL      (0x00000000U)

/* PRM_IRQSTATUS_EVE2_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_CORE_RECAL_ST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_CORE_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_CORE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_CORE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_CORE_RECAL_ST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_CORE_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_CORE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_CORE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_CORE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_CORE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_CORE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_CORE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_CORE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_MPU_RECAL_ST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_MPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_MPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_MPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_MPU_RECAL_ST_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_MPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_MPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_MPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_MPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_MPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_MPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_MPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_MPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_IVA_RECAL_ST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_IVA_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_IVA_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_IVA_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_IVA_RECAL_ST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_IVA_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_IVA_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_IVA_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_IVA_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_IVA_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_IVA_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_IVA_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_IVA_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_PER_RECAL_ST_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_PER_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_PER_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_PER_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_PER_RECAL_ST_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_PER_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_PER_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_PER_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_PER_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_PER_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_PER_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_PER_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_PER_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_ABE_RECAL_ST_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_ABE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_ABE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_ABE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_ABE_RECAL_ST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_ABE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_ABE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_ABE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_ABE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_ABE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_ABE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_ABE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_ABE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GMAC_RECAL_ST_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_GMAC_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GMAC_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GMAC_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GMAC_RECAL_ST_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_GMAC_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GMAC_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_GMAC_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_GMAC_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GPU_RECAL_ST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_GPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GPU_RECAL_ST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_GPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_GPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_GPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_GPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DDR_RECAL_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_DDR_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DDR_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DDR_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DDR_RECAL_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_DDR_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DDR_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DDR_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_DDR_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DDR_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DDR_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_DDR_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DDR_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_IO_ST_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_IO_ST_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_IO_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_IO_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_IO_ST_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_IO_ST_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_IO_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_IO_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_IO_ST_IRQ_TRU              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_IO_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_IO_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_IO_ST_IRQ_FAL              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_IO_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_FORCEWKUP_ST_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_FORCEWKUP_ST_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_FORCEWKUP_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_FORCEWKUP_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_FORCEWKUP_ST_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_FORCEWKUP_ST_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_FORCEWKUP_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_FORCEWKUP_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_FORCEWKUP_ST_IRQ_TRU       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_FORCEWKUP_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_FORCEWKUP_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_FORCEWKUP_ST_IRQ_FAL       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_FORCEWKUP_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DSP_RECAL_ST_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_DSP_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DSP_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DSP_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DSP_RECAL_ST_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_DSP_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DSP_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DSP_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_DSP_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DSP_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DSP_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_DSP_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_DSP_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_EVE_RECAL_ST_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_EVE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_EVE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_EVE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_EVE_RECAL_ST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_EVE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_EVE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_EVE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_EVE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_EVE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_EVE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_DPLL_EVE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_DPLL_EVE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_GPU_DONE_ST_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_GPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_GPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_GPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_GPU_DONE_ST_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_GPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_GPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_GPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_GPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_GPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_GPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_GPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_GPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_DSPEVE_DONE_ST_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_DSPEVE_DONE_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_DSPEVE_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_DSPEVE_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_DSPEVE_DONE_ST_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_DSPEVE_DONE_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_DSPEVE_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_DSPEVE_DONE_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_DSPEVE_DONE_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_IVA_DONE_ST_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_IVA_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_IVA_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_IVA_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_IVA_DONE_ST_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_IVA_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_IVA_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_IVA_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_IVA_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_IVA_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_IVA_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_IVA_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_IVA_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_MPU_DONE_ST_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_MPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_MPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_MPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_MPU_DONE_ST_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_MPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_MPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_MPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_MPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_MPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_MPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE2_ABB_MPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_ABB_MPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE2_REG_RESETVAL      (0x00000000U)

/* PRM_IRQSTATUS_EVE3_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_CORE_RECAL_ST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_CORE_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_CORE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_CORE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_CORE_RECAL_ST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_CORE_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_CORE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_CORE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_CORE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_CORE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_CORE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_CORE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_CORE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_MPU_RECAL_ST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_MPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_MPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_MPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_MPU_RECAL_ST_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_MPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_MPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_MPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_MPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_MPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_MPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_MPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_MPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_IVA_RECAL_ST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_IVA_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_IVA_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_IVA_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_IVA_RECAL_ST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_IVA_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_IVA_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_IVA_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_IVA_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_IVA_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_IVA_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_IVA_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_IVA_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_PER_RECAL_ST_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_PER_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_PER_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_PER_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_PER_RECAL_ST_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_PER_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_PER_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_PER_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_PER_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_PER_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_PER_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_PER_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_PER_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_ABE_RECAL_ST_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_ABE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_ABE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_ABE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_ABE_RECAL_ST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_ABE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_ABE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_ABE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_ABE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_ABE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_ABE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_ABE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_ABE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GMAC_RECAL_ST_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_GMAC_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GMAC_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GMAC_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GMAC_RECAL_ST_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_GMAC_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GMAC_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_GMAC_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_GMAC_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GPU_RECAL_ST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_GPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GPU_RECAL_ST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_GPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_GPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_GPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_GPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DDR_RECAL_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_DDR_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DDR_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DDR_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DDR_RECAL_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_DDR_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DDR_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DDR_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_DDR_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DDR_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DDR_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_DDR_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DDR_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_IO_ST_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_IO_ST_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_IO_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_IO_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_IO_ST_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_IO_ST_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_IO_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_IO_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_IO_ST_IRQ_TRU              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_IO_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_IO_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_IO_ST_IRQ_FAL              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_IO_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_FORCEWKUP_ST_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_FORCEWKUP_ST_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_FORCEWKUP_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_FORCEWKUP_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_FORCEWKUP_ST_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_FORCEWKUP_ST_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_FORCEWKUP_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_FORCEWKUP_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_FORCEWKUP_ST_IRQ_TRU       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_FORCEWKUP_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_FORCEWKUP_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_FORCEWKUP_ST_IRQ_FAL       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_FORCEWKUP_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DSP_RECAL_ST_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_DSP_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DSP_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DSP_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DSP_RECAL_ST_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_DSP_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DSP_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DSP_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_DSP_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DSP_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DSP_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_DSP_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_DSP_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_EVE_RECAL_ST_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_EVE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_EVE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_EVE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_EVE_RECAL_ST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_EVE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_EVE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_EVE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_EVE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_EVE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_EVE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_DPLL_EVE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_DPLL_EVE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_GPU_DONE_ST_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_GPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_GPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_GPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_GPU_DONE_ST_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_GPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_GPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_GPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_GPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_GPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_GPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_GPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_GPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_DSPEVE_DONE_ST_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_DSPEVE_DONE_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_DSPEVE_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_DSPEVE_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_DSPEVE_DONE_ST_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_DSPEVE_DONE_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_DSPEVE_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_DSPEVE_DONE_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_DSPEVE_DONE_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_IVA_DONE_ST_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_IVA_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_IVA_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_IVA_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_IVA_DONE_ST_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_IVA_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_IVA_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_IVA_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_IVA_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_IVA_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_IVA_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_IVA_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_IVA_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_MPU_DONE_ST_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_MPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_MPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_MPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_MPU_DONE_ST_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_MPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_MPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_MPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_MPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_MPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_MPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE3_ABB_MPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_ABB_MPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE3_REG_RESETVAL      (0x00000000U)

/* PRM_IRQSTATUS_EVE4_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_CORE_RECAL_ST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_CORE_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_CORE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_CORE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_CORE_RECAL_ST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_CORE_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_CORE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_CORE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_CORE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_CORE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_CORE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_CORE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_CORE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_MPU_RECAL_ST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_MPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_MPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_MPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_MPU_RECAL_ST_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_MPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_MPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_MPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_MPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_MPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_MPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_MPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_MPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_IVA_RECAL_ST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_IVA_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_IVA_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_IVA_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_IVA_RECAL_ST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_IVA_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_IVA_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_IVA_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_IVA_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_IVA_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_IVA_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_IVA_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_IVA_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_PER_RECAL_ST_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_PER_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_PER_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_PER_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_PER_RECAL_ST_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_PER_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_PER_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_PER_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_PER_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_PER_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_PER_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_PER_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_PER_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_ABE_RECAL_ST_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_ABE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_ABE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_ABE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_ABE_RECAL_ST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_ABE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_ABE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_ABE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_ABE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_ABE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_ABE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_ABE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_ABE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GMAC_RECAL_ST_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_GMAC_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GMAC_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GMAC_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GMAC_RECAL_ST_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_GMAC_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GMAC_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_GMAC_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_GMAC_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GPU_RECAL_ST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_GPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GPU_RECAL_ST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_GPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_GPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_GPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_GPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DDR_RECAL_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_DDR_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DDR_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DDR_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DDR_RECAL_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_DDR_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DDR_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DDR_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_DDR_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DDR_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DDR_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_DDR_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DDR_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_IO_ST_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_IO_ST_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_IO_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_IO_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_IO_ST_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_IO_ST_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_IO_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_IO_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_IO_ST_IRQ_TRU              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_IO_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_IO_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_IO_ST_IRQ_FAL              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_IO_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_FORCEWKUP_ST_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_FORCEWKUP_ST_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_FORCEWKUP_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_FORCEWKUP_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_FORCEWKUP_ST_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_FORCEWKUP_ST_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_FORCEWKUP_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_FORCEWKUP_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_FORCEWKUP_ST_IRQ_TRU       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_FORCEWKUP_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_FORCEWKUP_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_FORCEWKUP_ST_IRQ_FAL       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_FORCEWKUP_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DSP_RECAL_ST_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_DSP_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DSP_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DSP_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DSP_RECAL_ST_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_DSP_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DSP_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DSP_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_DSP_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DSP_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DSP_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_DSP_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_DSP_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_EVE_RECAL_ST_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_EVE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_EVE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_EVE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_EVE_RECAL_ST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_EVE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_EVE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_EVE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_EVE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_EVE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_EVE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_DPLL_EVE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_DPLL_EVE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_GPU_DONE_ST_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_GPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_GPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_GPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_GPU_DONE_ST_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_GPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_GPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_GPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_GPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_GPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_GPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_GPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_GPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_DSPEVE_DONE_ST_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_DSPEVE_DONE_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_DSPEVE_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_DSPEVE_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_DSPEVE_DONE_ST_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_DSPEVE_DONE_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_DSPEVE_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_DSPEVE_DONE_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_DSPEVE_DONE_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_IVA_DONE_ST_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_IVA_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_IVA_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_IVA_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_IVA_DONE_ST_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_IVA_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_IVA_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_IVA_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_IVA_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_IVA_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_IVA_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_IVA_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_IVA_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_MPU_DONE_ST_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_MPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_MPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_MPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_MPU_DONE_ST_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_MPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_MPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_MPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_MPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_MPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_MPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_EVE4_ABB_MPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_ABB_MPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_EVE4_REG_RESETVAL      (0x00000000U)

/* PRM_IRQSTATUS_IPU1_REG */

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_CORE_RECAL_ST_MASK  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_CORE_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_CORE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_CORE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_CORE_RECAL_ST_SHIFT  (0U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_CORE_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_CORE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_CORE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_CORE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_CORE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_CORE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_CORE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_CORE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_MPU_RECAL_ST_MASK  (0x00000002U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_MPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_MPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_MPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_MPU_RECAL_ST_SHIFT  (1U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_MPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_MPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_MPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_MPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_MPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_MPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_MPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_MPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_IVA_RECAL_ST_MASK  (0x00000004U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_IVA_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_IVA_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_IVA_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_IVA_RECAL_ST_SHIFT  (2U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_IVA_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_IVA_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_IVA_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_IVA_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_IVA_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_IVA_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_IVA_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_IVA_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_PER_RECAL_ST_MASK  (0x00000008U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_PER_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_PER_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_PER_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_PER_RECAL_ST_SHIFT  (3U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_PER_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_PER_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_PER_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_PER_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_PER_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_PER_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_PER_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_PER_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_ABE_RECAL_ST_MASK  (0x00000010U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_ABE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_ABE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_ABE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_ABE_RECAL_ST_SHIFT  (4U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_ABE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_ABE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_ABE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_ABE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_ABE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_ABE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_ABE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_ABE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GMAC_RECAL_ST_MASK  (0x00000020U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_GMAC_RECAL_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GMAC_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GMAC_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GMAC_RECAL_ST_SHIFT  (5U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_GMAC_RECAL_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GMAC_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_GMAC_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GMAC_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_GMAC_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GMAC_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GPU_RECAL_ST_MASK  (0x00000040U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_GPU_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GPU_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GPU_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GPU_RECAL_ST_SHIFT  (6U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_GPU_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GPU_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GPU_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_GPU_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GPU_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GPU_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_GPU_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_GPU_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DDR_RECAL_ST_MASK  (0x00000080U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_DDR_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DDR_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DDR_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DDR_RECAL_ST_SHIFT  (7U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_DDR_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DDR_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DDR_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_DDR_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DDR_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DDR_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_DDR_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DDR_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_TRANSITION_ST_MASK  (0x00000100U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_TRANSITION_ST_MASK         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_TRANSITION_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_TRANSITION_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_TRANSITION_ST_SHIFT  (8U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_TRANSITION_ST_SHIFT        (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_TRANSITION_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_TRANSITION_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_TRANSITION_ST_IRQ_TRU      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_TRANSITION_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_TRANSITION_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_TRANSITION_ST_IRQ_FAL      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_TRANSITION_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_IO_ST_MASK    (0x00000200U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_IO_ST_MASK                 (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_IO_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_IO_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_IO_ST_SHIFT   (9U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_IO_ST_SHIFT                (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_IO_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_IO_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_IO_ST_IRQ_TRU              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_IO_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_IO_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_IO_ST_IRQ_FAL              (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_IO_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_FORCEWKUP_ST_MASK  (0x00000400U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_FORCEWKUP_ST_MASK          (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_FORCEWKUP_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_FORCEWKUP_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_FORCEWKUP_ST_SHIFT  (10U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_FORCEWKUP_ST_SHIFT         (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_FORCEWKUP_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_FORCEWKUP_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_FORCEWKUP_ST_IRQ_TRU       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_FORCEWKUP_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_FORCEWKUP_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_FORCEWKUP_ST_IRQ_FAL       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_FORCEWKUP_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DSP_RECAL_ST_MASK  (0x00000800U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_DSP_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DSP_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DSP_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DSP_RECAL_ST_SHIFT  (11U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_DSP_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DSP_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DSP_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_DSP_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DSP_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DSP_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_DSP_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_DSP_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_EVE_RECAL_ST_MASK  (0x00001000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_EVE_RECAL_ST_MASK     (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_EVE_RECAL_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_EVE_RECAL_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_EVE_RECAL_ST_SHIFT  (12U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_EVE_RECAL_ST_SHIFT    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_EVE_RECAL_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_EVE_RECAL_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_EVE_RECAL_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_EVE_RECAL_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_EVE_RECAL_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_DPLL_EVE_RECAL_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_DPLL_EVE_RECAL_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_GPU_DONE_ST_MASK  (0x10000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_GPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_GPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_GPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_GPU_DONE_ST_SHIFT  (28U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_GPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_GPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_GPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_GPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_GPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_GPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_GPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_GPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_DSPEVE_DONE_ST_MASK  (0x20000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_DSPEVE_DONE_ST_MASK    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_DSPEVE_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_DSPEVE_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_DSPEVE_DONE_ST_SHIFT  (29U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_DSPEVE_DONE_ST_SHIFT   (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_DSPEVE_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_DSPEVE_DONE_ST_IRQ_TRU  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_DSPEVE_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_DSPEVE_DONE_ST_IRQ_FAL  (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_DSPEVE_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_IVA_DONE_ST_MASK  (0x40000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_IVA_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_IVA_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_IVA_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_IVA_DONE_ST_SHIFT  (30U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_IVA_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_IVA_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_IVA_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_IVA_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_IVA_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_IVA_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_IVA_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_IVA_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_MPU_DONE_ST_MASK  (0x80000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_MPU_DONE_ST_MASK       (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_MPU_DONE_ST_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_MPU_DONE_ST_RESETVAL  (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_MPU_DONE_ST_SHIFT  (31U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_MPU_DONE_ST_SHIFT      (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_MPU_DONE_ST_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_MPU_DONE_ST_IRQ_TRU  (0x00000001U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_MPU_DONE_ST_IRQ_TRU    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_MPU_DONE_ST_IRQ_TRU)

#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_MPU_DONE_ST_IRQ_FAL  (0x00000000U)
/* Below define for backward compatibility */
#define PRM_IRQSTATUS_IPU1_ABB_MPU_DONE_ST_IRQ_FAL    (CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_ABB_MPU_DONE_ST_IRQ_FAL)


#define CSL_OCP_SOCKET_PRM_PRM_IRQSTATUS_IPU1_REG_RESETVAL      (0x00000000U)

/* PRM_DEBUG_CFG1_REG */

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG1_REG_SEL1_MASK         (0x000001FFU)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG1_SEL1_MASK                      (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG1_REG_SEL1_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG1_REG_SEL1_RESETVAL     (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG1_REG_SEL1_SHIFT        (0U)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG1_SEL1_SHIFT                     (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG1_REG_SEL1_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG1_REG_SEL1_MAX          (0x000001ffU)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG1_REG_RESETVAL          (0x00000000U)

/* PRM_DEBUG_CFG2_REG */

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG2_REG_SEL2_MASK         (0x000001FFU)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG2_SEL2_MASK                      (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG2_REG_SEL2_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG2_REG_SEL2_RESETVAL     (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG2_REG_SEL2_SHIFT        (0U)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG2_SEL2_SHIFT                     (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG2_REG_SEL2_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG2_REG_SEL2_MAX          (0x000001ffU)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG2_REG_RESETVAL          (0x00000000U)

/* PRM_DEBUG_CFG3_REG */

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG3_REG_SEL3_MASK         (0x000001FFU)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG3_SEL3_MASK                      (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG3_REG_SEL3_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG3_REG_SEL3_RESETVAL     (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG3_REG_SEL3_SHIFT        (0U)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG3_SEL3_SHIFT                     (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG3_REG_SEL3_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG3_REG_SEL3_MAX          (0x000001ffU)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG3_REG_RESETVAL          (0x00000000U)

/* PRM_DEBUG_CFG_REG */

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG_REG_SEL0_MASK          (0x000001FFU)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG_SEL0_MASK                       (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG_REG_SEL0_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG_REG_SEL0_RESETVAL      (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG_REG_SEL0_SHIFT         (0U)
/* Below define for backward compatibility */
#define PRM_DEBUG_CFG_SEL0_SHIFT                      (CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG_REG_SEL0_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG_REG_SEL0_MAX           (0x000001ffU)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_CFG_REG_RESETVAL           (0x00000000U)

/* PRM_DEBUG_OUT_REG */

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_OUT_REG_OUTPUT_MASK        (0xFFFFFFFFU)
/* Below define for backward compatibility */
#define PRM_DEBUG_OUT_OUTPUT_MASK                     (CSL_OCP_SOCKET_PRM_PRM_DEBUG_OUT_REG_OUTPUT_MASK)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_OUT_REG_OUTPUT_RESETVAL    (0x00000000U)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_OUT_REG_OUTPUT_SHIFT       (0U)
/* Below define for backward compatibility */
#define PRM_DEBUG_OUT_OUTPUT_SHIFT                    (CSL_OCP_SOCKET_PRM_PRM_DEBUG_OUT_REG_OUTPUT_SHIFT)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_OUT_REG_OUTPUT_MAX         (0xffffffffU)

#define CSL_OCP_SOCKET_PRM_PRM_DEBUG_OUT_REG_RESETVAL           (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
