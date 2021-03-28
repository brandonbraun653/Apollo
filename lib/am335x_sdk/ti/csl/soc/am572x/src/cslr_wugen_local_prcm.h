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
#ifndef CSLR_WUGENLOCALPRCM_H
#define CSLR_WUGENLOCALPRCM_H

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
    volatile Uint32 DUCATI_CTRL_REG;
    volatile Uint32 STANDBY_CORE_SYSCONFIG;
    volatile Uint32 IDLE_CORE_SYSCONFIG;
    volatile Uint32 WUGEN_MEVT0;
    volatile Uint32 WUGEN_MEVT1;
    volatile Uint32 DUCATI_GP_REG;
} CSL_WugenLocalPrcmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Interrupt set/clear to CortexM3 CPU1 or CPU2 */
#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG                      (0x0U)

/* Standby Protocol */
#define CSL_WUGENLOCALPRCM_STANDBY_CORE_SYSCONFIG               (0x4U)

/* Idle protocol */
#define CSL_WUGENLOCALPRCM_IDLE_CORE_SYSCONFIG                  (0x8U)

/* This register contains the interrupt enable (LSB) Wakeup enable bit per
 * interrupt request 0: Interrupt is disabled 1: Interrupt is enabled. */
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0                          (0xCU)

/* This register contains the interrupt enable (MSB) Wakeup enable bit per
 * interrupt request 0: Interrupt is disabled 1: Interrupt is enabled. */
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1                          (0x10U)

/* GPO pin mapping */
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG                        (0x14U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* DUCATI_CTRL_REG */

#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG_INT_CORTEX_1_MASK    (0x00000001U)
#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG_INT_CORTEX_1_SHIFT   (0U)
#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG_INT_CORTEX_1_RESETVAL  (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG_INT_CORTEX_1_MAX     (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG_INT_CORTEX_2_MASK    (0x00010000U)
#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG_INT_CORTEX_2_SHIFT   (16U)
#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG_INT_CORTEX_2_RESETVAL  (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG_INT_CORTEX_2_MAX     (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_CTRL_REG_RESETVAL             (0x00000000U)

/* STANDBY_CORE_SYSCONFIG */

#define CSL_WUGENLOCALPRCM_STANDBY_CORE_SYSCONFIG_STANDBYMODE_MASK  (0x00000003U)
#define CSL_WUGENLOCALPRCM_STANDBY_CORE_SYSCONFIG_STANDBYMODE_SHIFT  (0U)
#define CSL_WUGENLOCALPRCM_STANDBY_CORE_SYSCONFIG_STANDBYMODE_RESETVAL  (0x00000003U)
#define CSL_WUGENLOCALPRCM_STANDBY_CORE_SYSCONFIG_STANDBYMODE_MAX  (0x00000003U)

#define CSL_WUGENLOCALPRCM_STANDBY_CORE_SYSCONFIG_RESETVAL      (0x00000003U)

/* IDLE_CORE_SYSCONFIG */

#define CSL_WUGENLOCALPRCM_IDLE_CORE_SYSCONFIG_IDLEMODE_MASK    (0x00000003U)
#define CSL_WUGENLOCALPRCM_IDLE_CORE_SYSCONFIG_IDLEMODE_SHIFT   (0U)
#define CSL_WUGENLOCALPRCM_IDLE_CORE_SYSCONFIG_IDLEMODE_RESETVAL  (0x00000003U)
#define CSL_WUGENLOCALPRCM_IDLE_CORE_SYSCONFIG_IDLEMODE_MAX     (0x00000003U)

#define CSL_WUGENLOCALPRCM_IDLE_CORE_SYSCONFIG_RESETVAL         (0x00000003U)

/* WUGEN_MEVT0 */

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ0_MASK               (0x00000001U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ0_SHIFT              (0U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ0_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ0_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ1_MASK               (0x00000002U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ1_SHIFT              (1U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ1_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ1_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ2_MASK               (0x00000004U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ2_SHIFT              (2U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ2_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ2_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ3_MASK               (0x00000008U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ3_SHIFT              (3U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ3_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ3_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ4_MASK               (0x00000010U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ4_SHIFT              (4U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ4_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ4_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ5_MASK               (0x00000020U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ5_SHIFT              (5U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ5_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ5_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ6_MASK               (0x00000040U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ6_SHIFT              (6U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ6_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ6_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ7_MASK               (0x00000080U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ7_SHIFT              (7U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ7_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ7_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ8_MASK               (0x00000100U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ8_SHIFT              (8U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ8_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ8_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ9_MASK               (0x00000200U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ9_SHIFT              (9U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ9_RESETVAL           (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ9_MAX                (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ10_MASK              (0x00000400U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ10_SHIFT             (10U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ10_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ10_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ11_MASK              (0x00000800U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ11_SHIFT             (11U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ11_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ11_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ12_MASK              (0x00001000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ12_SHIFT             (12U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ12_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ12_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ13_MASK              (0x00002000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ13_SHIFT             (13U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ13_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ13_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ14_MASK              (0x00004000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ14_SHIFT             (14U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ14_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ14_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ15_MASK              (0x00008000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ15_SHIFT             (15U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ15_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ15_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ16_MASK              (0x00010000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ16_SHIFT             (16U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ16_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ16_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ17_MASK              (0x00020000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ17_SHIFT             (17U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ17_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ17_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ18_MASK              (0x00040000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ18_SHIFT             (18U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ18_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ18_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ19_MASK              (0x00080000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ19_SHIFT             (19U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ19_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ19_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ20_MASK              (0x00100000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ20_SHIFT             (20U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ20_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ20_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ21_MASK              (0x00200000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ21_SHIFT             (21U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ21_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ21_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ22_MASK              (0x00400000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ22_SHIFT             (22U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ22_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ22_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ23_MASK              (0x00800000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ23_SHIFT             (23U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ23_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ23_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ24_MASK              (0x01000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ24_SHIFT             (24U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ24_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ24_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ25_MASK              (0x02000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ25_SHIFT             (25U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ25_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ25_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ26_MASK              (0x04000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ26_SHIFT             (26U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ26_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ26_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ27_MASK              (0x08000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ27_SHIFT             (27U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ27_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ27_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ28_MASK              (0x10000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ28_SHIFT             (28U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ28_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ28_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ29_MASK              (0x20000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ29_SHIFT             (29U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ29_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ29_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ30_MASK              (0x40000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ30_SHIFT             (30U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ30_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ30_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ31_MASK              (0x80000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ31_SHIFT             (31U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ31_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_MIRQ31_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT0_RESETVAL                 (0x00000000U)

/* WUGEN_MEVT1 */

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ32_MASK              (0x00000001U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ32_SHIFT             (0U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ32_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ32_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ33_MASK              (0x00000002U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ33_SHIFT             (1U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ33_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ33_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ34_MASK              (0x00000004U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ34_SHIFT             (2U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ34_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ34_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ35_MASK              (0x00000008U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ35_SHIFT             (3U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ35_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ35_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ36_MASK              (0x00000010U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ36_SHIFT             (4U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ36_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ36_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ37_MASK              (0x00000020U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ37_SHIFT             (5U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ37_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ37_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ38_MASK              (0x00000040U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ38_SHIFT             (6U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ38_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ38_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ39_MASK              (0x00000080U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ39_SHIFT             (7U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ39_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ39_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ40_MASK              (0x00000100U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ40_SHIFT             (8U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ40_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ40_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ41_MASK              (0x00000200U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ41_SHIFT             (9U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ41_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ41_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ42_MASK              (0x00000400U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ42_SHIFT             (10U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ42_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ42_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ43_MASK              (0x00000800U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ43_SHIFT             (11U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ43_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ43_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ44_MASK              (0x00001000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ44_SHIFT             (12U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ44_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ44_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ45_MASK              (0x00002000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ45_SHIFT             (13U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ45_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ45_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ46_MASK              (0x00004000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ46_SHIFT             (14U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ46_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ46_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ47_MASK              (0x00008000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ47_SHIFT             (15U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ47_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ47_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ48_MASK              (0x00010000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ48_SHIFT             (16U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ48_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ48_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ49_MASK              (0x00020000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ49_SHIFT             (17U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ49_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ49_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ50_MASK              (0x00040000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ50_SHIFT             (18U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ50_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ50_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ51_MASK              (0x00080000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ51_SHIFT             (19U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ51_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ51_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ52_MASK              (0x00100000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ52_SHIFT             (20U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ52_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ52_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ53_MASK              (0x00200000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ53_SHIFT             (21U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ53_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ53_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ54_MASK              (0x00400000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ54_SHIFT             (22U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ54_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ54_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ55_MASK              (0x00800000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ55_SHIFT             (23U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ55_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ55_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ56_MASK              (0x01000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ56_SHIFT             (24U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ56_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ56_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ57_MASK              (0x02000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ57_SHIFT             (25U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ57_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ57_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ58_MASK              (0x04000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ58_SHIFT             (26U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ58_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ58_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ59_MASK              (0x08000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ59_SHIFT             (27U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ59_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ59_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ60_MASK              (0x10000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ60_SHIFT             (28U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ60_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ60_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ61_MASK              (0x20000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ61_SHIFT             (29U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ61_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ61_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ62_MASK              (0x40000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ62_SHIFT             (30U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ62_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ62_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ63_MASK              (0x80000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ63_SHIFT             (31U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ63_RESETVAL          (0x00000000U)
#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_MIRQ63_MAX               (0x00000001U)

#define CSL_WUGENLOCALPRCM_WUGEN_MEVT1_RESETVAL                 (0x00000000U)

/* DUCATI_GP_REG */

#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT0_MASK        (0x00000002U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT0_SHIFT       (1U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT0_RESETVAL    (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT0_MAX         (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT1_MASK        (0x00000004U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT1_SHIFT       (2U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT1_RESETVAL    (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT1_MAX         (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT2_MASK        (0x00000008U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT2_SHIFT       (3U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT2_RESETVAL    (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT2_MAX         (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT3_MASK        (0x00000010U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT3_SHIFT       (4U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT3_RESETVAL    (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT3_MAX         (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT4_MASK        (0x00000020U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT4_SHIFT       (5U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT4_RESETVAL    (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT4_MAX         (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT5_MASK        (0x00000040U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT5_SHIFT       (6U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT5_RESETVAL    (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT5_MAX         (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT6_MASK        (0x00000080U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT6_SHIFT       (7U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT6_RESETVAL    (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT6_MAX         (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT7_MASK        (0x00000001U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT7_SHIFT       (0U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT7_RESETVAL    (0x00000000U)
#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_POUSEROUT7_MAX         (0x00000001U)

#define CSL_WUGENLOCALPRCM_DUCATI_GP_REG_RESETVAL               (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
