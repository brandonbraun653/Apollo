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
#ifndef CSLR_PMMCCONTROL_H_
#define CSLR_PMMCCONTROL_H_

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
    volatile Uint32 REVISION;
    volatile Uint8  RSVD0[28];
    volatile Uint32 LOCK0;
    volatile Uint32 LOCK1;
    volatile Uint32 LOCK2;
    volatile Uint8  RSVD1[20];
    volatile Uint32 FW_CTRL_OUT0;
    volatile Uint32 FW_CTRL_OUT0_SET;
    volatile Uint32 FW_CTRL_OUT0_CLR;
    volatile Uint32 FW_STS_IN0;
    volatile Uint32 FW_CTRL_OUT1;
    volatile Uint32 FW_CTRL_OUT1_SET;
    volatile Uint32 FW_CTRL_OUT1_CLR;
    volatile Uint32 FW_STS_IN1;
    volatile Uint8  RSVD2[32];
    volatile Uint32 PMCTRL_SYS;
    volatile Uint32 PMCTRL_IO;
    volatile Uint32 PMCTRL_DDR;
    volatile Uint32 PMCTRL_MOSC;
    volatile Uint32 PMCTRL_PMMC;
    volatile Uint8  RSVD3[172];
    volatile Uint32 CPU_STCALIB;
    volatile Uint8  RSVD4[60];
    volatile Uint32 WKUP0_EN;
    volatile Uint32 WKUP1_EN;
    volatile Uint32 WKUP2_EN;
    volatile Uint32 WKUP3_EN;
    volatile Uint32 WKUP4_EN;
    volatile Uint32 WKUP5_EN;
    volatile Uint32 WKUP6_EN;
    volatile Uint32 WKUP7_EN;
    volatile Uint32 MADDR_BASE0;
    volatile Uint32 MADDR_BASE1;
    volatile Uint32 MADDR_BASE2;
    volatile Uint32 MADDR_BASE3;
    volatile Uint32 MADDR_BASE4;
    volatile Uint32 MADDR_BASE5;
    volatile Uint32 MADDR_BASE6;
    volatile Uint32 MADDR_BASE7;
    volatile Uint8  RSVD5[576];
    volatile Uint32 SPARE0;
    volatile Uint32 SPARE1;
    volatile Uint32 SPARE2;
    volatile Uint8  RSVD6[3060];
    volatile Uint32 LOCK3;
    volatile Uint32 LOCK4;
    volatile Uint32 LOCK5;
    volatile Uint8  RSVD7[16];
    volatile Uint32 INTR_EOI;
    volatile Uint32 INTR0_OUT_IRQSTATUS_RAW;
    volatile Uint32 INTR0_OUT_IRQSTATUS;
    volatile Uint32 INTR0_OUT_IRQENABLE_SET;
    volatile Uint32 INTR0_OUT_IRQENABLE_CLR;
    volatile Uint32 INTR1_OUT_IRQSTATUS_RAW;
    volatile Uint32 INTR1_OUT_IRQSTATUS;
    volatile Uint32 INTR1_OUT_IRQENABLE_SET;
    volatile Uint32 INTR1_OUT_IRQENABLE_CLR;
    volatile Uint8  RSVD8[64];
    volatile Uint32 INTR_FAULTDET_IRQSTATUS_RAW;
    volatile Uint32 INTR_FAULTDET_IRQSTATUS;
    volatile Uint32 INTR_FAULTDET_IRQENABLE_SET;
    volatile Uint32 INTR_FAULTDET_IRQENABLE_CLR;
} CSL_pmmcControlRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_REVISION                                (0x0U)

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_LOCK0                                   (0x20U)

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_LOCK1                                   (0x24U)

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_LOCK2                                   (0x28U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_FW_CTRL_OUT0                            (0x40U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_SET                        (0x44U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_CLR                        (0x48U)

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_FW_STS_IN0                              (0x4CU)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_FW_CTRL_OUT1                            (0x50U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_SET                        (0x54U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_CLR                        (0x58U)

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_FW_STS_IN1                              (0x5CU)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_PMCTRL_SYS                              (0x80U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_PMCTRL_IO                               (0x84U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_PMCTRL_DDR                              (0x88U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_PMCTRL_MOSC                             (0x8CU)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_PMCTRL_PMMC                             (0x90U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_CPU_STCALIB                             (0x140U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_WKUP0_EN                                (0x180U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_WKUP1_EN                                (0x184U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_WKUP2_EN                                (0x188U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_WKUP3_EN                                (0x18CU)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_WKUP4_EN                                (0x190U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_WKUP5_EN                                (0x194U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_WKUP6_EN                                (0x198U)

/* This register is writable only when lock1 is unlocked */
#define CSL_PMMCCONTROL_WKUP7_EN                                (0x19CU)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_MADDR_BASE0                             (0x1A0U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_MADDR_BASE1                             (0x1A4U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_MADDR_BASE2                             (0x1A8U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_MADDR_BASE3                             (0x1ACU)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_MADDR_BASE4                             (0x1B0U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_MADDR_BASE5                             (0x1B4U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_MADDR_BASE6                             (0x1B8U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_MADDR_BASE7                             (0x1BCU)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_SPARE0                                  (0x400U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_SPARE1                                  (0x404U)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_SPARE2                                  (0x408U)

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_LOCK3                                   (0x1000U)

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_LOCK4                                   (0x1004U)

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_LOCK5                                   (0x1008U)

/* This register doesnt need unlocking */
#define CSL_PMMCCONTROL_INTR_EOI                                (0x101CU)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_RAW                 (0x1020U)

/* This register is writable only when lock3 is unlocked */
#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS                     (0x1024U)

/* This register is writable only when lock3 is unlocked */
#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_SET                 (0x1028U)

/* This register is writable only when lock3 is unlocked */
#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_CLR                 (0x102CU)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_RAW                 (0x1030U)

/* This register is writable only when lock4 is unlocked */
#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS                     (0x1034U)

/* This register is writable only when lock4 is unlocked */
#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_SET                 (0x1038U)

/* This register is writable only when lock4 is unlocked */
#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_CLR                 (0x103CU)

/* This register is writable only when lock0 is unlocked */
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW             (0x1080U)

/* This register is writable only when lock5 is unlocked */
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS                 (0x1084U)

/* This register is writable only when lock5 is unlocked */
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET             (0x1088U)

/* This register is writable only when lock5 is unlocked */
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_CLR             (0x108CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_PMMCCONTROL_REVISION_MINOR_MASK                     (0x0000003FU)
#define CSL_PMMCCONTROL_REVISION_MINOR_SHIFT                    (0U)
#define CSL_PMMCCONTROL_REVISION_MINOR_RESETVAL                 (0x00000000U)
#define CSL_PMMCCONTROL_REVISION_MINOR_MAX                      (0x0000003fU)

#define CSL_PMMCCONTROL_REVISION_CUSTOM_MASK                    (0x000000C0U)
#define CSL_PMMCCONTROL_REVISION_CUSTOM_SHIFT                   (6U)
#define CSL_PMMCCONTROL_REVISION_CUSTOM_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_REVISION_CUSTOM_MAX                     (0x00000003U)

#define CSL_PMMCCONTROL_REVISION_MAJOR_MASK                     (0x00000700U)
#define CSL_PMMCCONTROL_REVISION_MAJOR_SHIFT                    (8U)
#define CSL_PMMCCONTROL_REVISION_MAJOR_RESETVAL                 (0x00000001U)
#define CSL_PMMCCONTROL_REVISION_MAJOR_MAX                      (0x00000007U)

#define CSL_PMMCCONTROL_REVISION_RTL_MASK                       (0x0000F800U)
#define CSL_PMMCCONTROL_REVISION_RTL_SHIFT                      (11U)
#define CSL_PMMCCONTROL_REVISION_RTL_RESETVAL                   (0x00000000U)
#define CSL_PMMCCONTROL_REVISION_RTL_MAX                        (0x0000001fU)

#define CSL_PMMCCONTROL_REVISION_FUNC_MASK                      (0x0FFF0000U)
#define CSL_PMMCCONTROL_REVISION_FUNC_SHIFT                     (16U)
#define CSL_PMMCCONTROL_REVISION_FUNC_RESETVAL                  (0x000006e0U)
#define CSL_PMMCCONTROL_REVISION_FUNC_MAX                       (0x00000fffU)

#define CSL_PMMCCONTROL_REVISION_BU_MASK                        (0x30000000U)
#define CSL_PMMCCONTROL_REVISION_BU_SHIFT                       (28U)
#define CSL_PMMCCONTROL_REVISION_BU_RESETVAL                    (0x00000002U)
#define CSL_PMMCCONTROL_REVISION_BU_MAX                         (0x00000003U)

#define CSL_PMMCCONTROL_REVISION_SCHEME_MASK                    (0xC0000000U)
#define CSL_PMMCCONTROL_REVISION_SCHEME_SHIFT                   (30U)
#define CSL_PMMCCONTROL_REVISION_SCHEME_RESETVAL                (0x00000001U)
#define CSL_PMMCCONTROL_REVISION_SCHEME_MAX                     (0x00000003U)

#define CSL_PMMCCONTROL_REVISION_RESETVAL                       (0x66e00100U)

/* LOCK0 */

#define CSL_PMMCCONTROL_LOCK0_KEY_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_LOCK0_KEY_SHIFT                         (0U)
#define CSL_PMMCCONTROL_LOCK0_KEY_RESETVAL                      (0x8a6b7cdaU)
#define CSL_PMMCCONTROL_LOCK0_KEY_MAX                           (0xffffffffU)

#define CSL_PMMCCONTROL_LOCK0_RESETVAL                          (0x8a6b7cdaU)

/* LOCK1 */

#define CSL_PMMCCONTROL_LOCK1_KEY_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_LOCK1_KEY_SHIFT                         (0U)
#define CSL_PMMCCONTROL_LOCK1_KEY_RESETVAL                      (0x823caef9U)
#define CSL_PMMCCONTROL_LOCK1_KEY_MAX                           (0xffffffffU)

#define CSL_PMMCCONTROL_LOCK1_RESETVAL                          (0x823caef9U)

/* LOCK2 */

#define CSL_PMMCCONTROL_LOCK2_KEY_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_LOCK2_KEY_SHIFT                         (0U)
#define CSL_PMMCCONTROL_LOCK2_KEY_RESETVAL                      (0xfea765bcU)
#define CSL_PMMCCONTROL_LOCK2_KEY_MAX                           (0xffffffffU)

#define CSL_PMMCCONTROL_LOCK2_RESETVAL                          (0xfea765bcU)

/* FW_CTRL_OUT0 */

#define CSL_PMMCCONTROL_FW_CTRL_OUT0_EVENT_MASK                 (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_EVENT_SHIFT                (0U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_EVENT_RESETVAL             (0x00000000U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_EVENT_MAX                  (0xffffffffU)

#define CSL_PMMCCONTROL_FW_CTRL_OUT0_RESETVAL                   (0x00000000U)

/* FW_CTRL_OUT0_SET */

#define CSL_PMMCCONTROL_FW_CTRL_OUT0_SET_EVENT_MASK             (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_SET_EVENT_SHIFT            (0U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_SET_EVENT_RESETVAL         (0x00000000U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_SET_EVENT_MAX              (0xffffffffU)

#define CSL_PMMCCONTROL_FW_CTRL_OUT0_SET_RESETVAL               (0x00000000U)

/* FW_CTRL_OUT0_CLR */

#define CSL_PMMCCONTROL_FW_CTRL_OUT0_CLR_EVENT_MASK             (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_CLR_EVENT_SHIFT            (0U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_CLR_EVENT_RESETVAL         (0x00000000U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT0_CLR_EVENT_MAX              (0xffffffffU)

#define CSL_PMMCCONTROL_FW_CTRL_OUT0_CLR_RESETVAL               (0x00000000U)

/* FW_STS_IN0 */

#define CSL_PMMCCONTROL_FW_STS_IN0_EVENT_MASK                   (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_FW_STS_IN0_EVENT_SHIFT                  (0U)
#define CSL_PMMCCONTROL_FW_STS_IN0_EVENT_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_FW_STS_IN0_EVENT_MAX                    (0xffffffffU)

#define CSL_PMMCCONTROL_FW_STS_IN0_RESETVAL                     (0x00000000U)

/* FW_CTRL_OUT1 */

#define CSL_PMMCCONTROL_FW_CTRL_OUT1_EVENT_MASK                 (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_EVENT_SHIFT                (0U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_EVENT_RESETVAL             (0x00000000U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_EVENT_MAX                  (0xffffffffU)

#define CSL_PMMCCONTROL_FW_CTRL_OUT1_RESETVAL                   (0x00000000U)

/* FW_CTRL_OUT1_SET */

#define CSL_PMMCCONTROL_FW_CTRL_OUT1_SET_EVENT_MASK             (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_SET_EVENT_SHIFT            (0U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_SET_EVENT_RESETVAL         (0x00000000U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_SET_EVENT_MAX              (0xffffffffU)

#define CSL_PMMCCONTROL_FW_CTRL_OUT1_SET_RESETVAL               (0x00000000U)

/* FW_CTRL_OUT1_CLR */

#define CSL_PMMCCONTROL_FW_CTRL_OUT1_CLR_EVENT_MASK             (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_CLR_EVENT_SHIFT            (0U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_CLR_EVENT_RESETVAL         (0x00000000U)
#define CSL_PMMCCONTROL_FW_CTRL_OUT1_CLR_EVENT_MAX              (0xffffffffU)

#define CSL_PMMCCONTROL_FW_CTRL_OUT1_CLR_RESETVAL               (0x00000000U)

/* FW_STS_IN1 */

#define CSL_PMMCCONTROL_FW_STS_IN1_EVENT_MASK                   (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_FW_STS_IN1_EVENT_SHIFT                  (0U)
#define CSL_PMMCCONTROL_FW_STS_IN1_EVENT_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_FW_STS_IN1_EVENT_MAX                    (0xffffffffU)

#define CSL_PMMCCONTROL_FW_STS_IN1_RESETVAL                     (0x00000000U)

/* PMCTRL_SYS */

#define CSL_PMMCCONTROL_PMCTRL_SYS_ULPM_EN_MASK                 (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_SYS_ULPM_EN_SHIFT                (0U)
#define CSL_PMMCCONTROL_PMCTRL_SYS_ULPM_EN_RESETVAL             (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_SYS_ULPM_EN_MAX                  (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_SYS_RSVD0_MASK                   (0xFFFFFFFEU)
#define CSL_PMMCCONTROL_PMCTRL_SYS_RSVD0_SHIFT                  (1U)
#define CSL_PMMCCONTROL_PMCTRL_SYS_RSVD0_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_SYS_RSVD0_MAX                    (0x7fffffffU)

#define CSL_PMMCCONTROL_PMCTRL_SYS_RESETVAL                     (0x00000000U)

/* PMCTRL_IO */

#define CSL_PMMCCONTROL_PMCTRL_IO_ISOCLK_OVERRIDE_MASK          (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_IO_ISOCLK_OVERRIDE_SHIFT         (0U)
#define CSL_PMMCCONTROL_PMCTRL_IO_ISOCLK_OVERRIDE_RESETVAL      (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_ISOCLK_OVERRIDE_MAX           (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_IO_ISOCLK_STATUS_MASK            (0x00000002U)
#define CSL_PMMCCONTROL_PMCTRL_IO_ISOCLK_STATUS_SHIFT           (1U)
#define CSL_PMMCCONTROL_PMCTRL_IO_ISOCLK_STATUS_RESETVAL        (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_ISOCLK_STATUS_MAX             (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD0_MASK                    (0x0000000CU)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD0_SHIFT                   (2U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD0_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD0_MAX                     (0x00000003U)

#define CSL_PMMCCONTROL_PMCTRL_IO_ISOOVR_EXTEND_MASK            (0x00000010U)
#define CSL_PMMCCONTROL_PMCTRL_IO_ISOOVR_EXTEND_SHIFT           (4U)
#define CSL_PMMCCONTROL_PMCTRL_IO_ISOOVR_EXTEND_RESETVAL        (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_ISOOVR_EXTEND_MAX             (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ON_STATUS_MASK             (0x00000020U)
#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ON_STATUS_SHIFT            (5U)
#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ON_STATUS_RESETVAL         (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ON_STATUS_MAX              (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD1_MASK                    (0x000000C0U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD1_SHIFT                   (6U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD1_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD1_MAX                     (0x00000003U)

#define CSL_PMMCCONTROL_PMCTRL_IO_WUCLK_CTRL_MASK               (0x00000100U)
#define CSL_PMMCCONTROL_PMCTRL_IO_WUCLK_CTRL_SHIFT              (8U)
#define CSL_PMMCCONTROL_PMCTRL_IO_WUCLK_CTRL_RESETVAL           (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_WUCLK_CTRL_MAX                (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_IO_WUCLK_STATUS_MASK             (0x00000200U)
#define CSL_PMMCCONTROL_PMCTRL_IO_WUCLK_STATUS_SHIFT            (9U)
#define CSL_PMMCCONTROL_PMCTRL_IO_WUCLK_STATUS_RESETVAL         (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_WUCLK_STATUS_MAX              (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD2_MASK                    (0x0000FC00U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD2_SHIFT                   (10U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD2_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD2_MAX                     (0x0000003fU)

#define CSL_PMMCCONTROL_PMCTRL_IO_GLOBAL_WUEN_MASK              (0x00010000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_GLOBAL_WUEN_SHIFT             (16U)
#define CSL_PMMCCONTROL_PMCTRL_IO_GLOBAL_WUEN_RESETVAL          (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_GLOBAL_WUEN_MAX               (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD3_MASK                    (0x00FE0000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD3_SHIFT                   (17U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD3_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD3_MAX                     (0x0000007fU)

#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ISO_CTRL_MASK              (0x01000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ISO_CTRL_SHIFT             (24U)
#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ISO_CTRL_RESETVAL          (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ISO_CTRL_MAX               (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ISO_STATUS_MASK            (0x02000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ISO_STATUS_SHIFT           (25U)
#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ISO_STATUS_RESETVAL        (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_IO_ISO_STATUS_MAX             (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD4_MASK                    (0xFC000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD4_SHIFT                   (26U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD4_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_IO_RSVD4_MAX                     (0x0000003fU)

#define CSL_PMMCCONTROL_PMCTRL_IO_RESETVAL                      (0x00000020U)

/* PMCTRL_DDR */

#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR0_CKE_OVERRIDE_EN_MASK    (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR0_CKE_OVERRIDE_EN_SHIFT   (0U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR0_CKE_OVERRIDE_EN_RESETVAL  (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR0_CKE_OVERRIDE_EN_MAX     (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR0_RESET_OVERRIDE_EN_MASK  (0x00000002U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR0_RESET_OVERRIDE_EN_SHIFT  (1U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR0_RESET_OVERRIDE_EN_RESETVAL  (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR0_RESET_OVERRIDE_EN_MAX   (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR1_CKE_OVERRIDE_EN_MASK    (0x00000004U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR1_CKE_OVERRIDE_EN_SHIFT   (2U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR1_CKE_OVERRIDE_EN_RESETVAL  (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR1_CKE_OVERRIDE_EN_MAX     (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR1_RESET_OVERRIDE_EN_MASK  (0x00000008U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR1_RESET_OVERRIDE_EN_SHIFT  (3U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR1_RESET_OVERRIDE_EN_RESETVAL  (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR1_RESET_OVERRIDE_EN_MAX   (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR2_CKE_OVERRIDE_EN_MASK    (0x00000010U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR2_CKE_OVERRIDE_EN_SHIFT   (4U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR2_CKE_OVERRIDE_EN_RESETVAL  (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR2_CKE_OVERRIDE_EN_MAX     (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR2_RESET_OVERRIDE_EN_MASK  (0x00000020U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR2_RESET_OVERRIDE_EN_SHIFT  (5U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR2_RESET_OVERRIDE_EN_RESETVAL  (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR2_RESET_OVERRIDE_EN_MAX   (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR3_CKE_OVERRIDE_EN_MASK    (0x00000040U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR3_CKE_OVERRIDE_EN_SHIFT   (6U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR3_CKE_OVERRIDE_EN_RESETVAL  (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR3_CKE_OVERRIDE_EN_MAX     (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR3_RESET_OVERRIDE_EN_MASK  (0x00000080U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR3_RESET_OVERRIDE_EN_SHIFT  (7U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR3_RESET_OVERRIDE_EN_RESETVAL  (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_DDR3_RESET_OVERRIDE_EN_MAX   (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_DDR_RSVD0_MASK                   (0x0000FF00U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_RSVD0_SHIFT                  (8U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_RSVD0_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_RSVD0_MAX                    (0x000000ffU)

#define CSL_PMMCCONTROL_PMCTRL_DDR_EMIF_DEVOFF_MASK             (0x00010000U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_EMIF_DEVOFF_SHIFT            (16U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_EMIF_DEVOFF_RESETVAL         (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_EMIF_DEVOFF_MAX              (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_DDR_RSVD1_MASK                   (0xFFFE0000U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_RSVD1_SHIFT                  (17U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_RSVD1_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_DDR_RSVD1_MAX                    (0x00007fffU)

#define CSL_PMMCCONTROL_PMCTRL_DDR_RESETVAL                     (0x000000ffU)

/* PMCTRL_MOSC */

#define CSL_PMMCCONTROL_PMCTRL_MOSC_SETUP_TIME_MASK             (0x00000FFFU)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_SETUP_TIME_SHIFT            (0U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_SETUP_TIME_RESETVAL         (0x00000100U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_SETUP_TIME_MAX              (0x00000fffU)

#define CSL_PMMCCONTROL_PMCTRL_MOSC_RSVD0_MASK                  (0x0000F000U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_RSVD0_SHIFT                 (12U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_RSVD0_MAX                   (0x0000000fU)

#define CSL_PMMCCONTROL_PMCTRL_MOSC_MOSC_PWRDN_ENABLE_MASK      (0x00010000U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_MOSC_PWRDN_ENABLE_SHIFT     (16U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_MOSC_PWRDN_ENABLE_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_MOSC_PWRDN_ENABLE_MAX       (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_MOSC_RSVD1_MASK                  (0xFFFE0000U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_RSVD1_SHIFT                 (17U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_RSVD1_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_MOSC_RSVD1_MAX                   (0x00007fffU)

#define CSL_PMMCCONTROL_PMCTRL_MOSC_RESETVAL                    (0x00000100U)

/* PMCTRL_PMMC */

#define CSL_PMMCCONTROL_PMCTRL_PMMC_PMMC_MEM_DS_EN_MASK         (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_PMMC_MEM_DS_EN_SHIFT        (0U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_PMMC_MEM_DS_EN_RESETVAL     (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_PMMC_MEM_DS_EN_MAX          (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_PMMC_RSVD0_MASK                  (0x0000000EU)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_RSVD0_SHIFT                 (1U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_RSVD0_MAX                   (0x00000007U)

#define CSL_PMMCCONTROL_PMCTRL_PMMC_WWDT_ENABLE_MASK            (0x00000010U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_WWDT_ENABLE_SHIFT           (4U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_WWDT_ENABLE_RESETVAL        (0x00000001U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_WWDT_ENABLE_MAX             (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_PMMC_WWDT_ENABLE_PERM_MASK       (0x00000020U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_WWDT_ENABLE_PERM_SHIFT      (5U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_WWDT_ENABLE_PERM_RESETVAL   (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_WWDT_ENABLE_PERM_MAX        (0x00000001U)

#define CSL_PMMCCONTROL_PMCTRL_PMMC_RSVD1_MASK                  (0xFFFFFFC0U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_RSVD1_SHIFT                 (6U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_RSVD1_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_PMCTRL_PMMC_RSVD1_MAX                   (0x03ffffffU)

#define CSL_PMMCCONTROL_PMCTRL_PMMC_RESETVAL                    (0x00000010U)

/* CPU_STCALIB */

#define CSL_PMMCCONTROL_CPU_STCALIB_TENMS_MASK                  (0x00FFFFFFU)
#define CSL_PMMCCONTROL_CPU_STCALIB_TENMS_SHIFT                 (0U)
#define CSL_PMMCCONTROL_CPU_STCALIB_TENMS_RESETVAL              (0x0000ea60U)
#define CSL_PMMCCONTROL_CPU_STCALIB_TENMS_MAX                   (0x00ffffffU)

#define CSL_PMMCCONTROL_CPU_STCALIB_RSVD0_MASK                  (0xFF000000U)
#define CSL_PMMCCONTROL_CPU_STCALIB_RSVD0_SHIFT                 (24U)
#define CSL_PMMCCONTROL_CPU_STCALIB_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_CPU_STCALIB_RSVD0_MAX                   (0x000000ffU)

#define CSL_PMMCCONTROL_CPU_STCALIB_RESETVAL                    (0x0000ea60U)

/* WKUP0_EN */

#define CSL_PMMCCONTROL_WKUP0_EN_WKUPEN_MASK                    (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_WKUP0_EN_WKUPEN_SHIFT                   (0U)
#define CSL_PMMCCONTROL_WKUP0_EN_WKUPEN_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_WKUP0_EN_WKUPEN_MAX                     (0xffffffffU)

#define CSL_PMMCCONTROL_WKUP0_EN_RESETVAL                       (0x00000000U)

/* WKUP1_EN */

#define CSL_PMMCCONTROL_WKUP1_EN_WKUPEN_MASK                    (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_WKUP1_EN_WKUPEN_SHIFT                   (0U)
#define CSL_PMMCCONTROL_WKUP1_EN_WKUPEN_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_WKUP1_EN_WKUPEN_MAX                     (0xffffffffU)

#define CSL_PMMCCONTROL_WKUP1_EN_RESETVAL                       (0x00000000U)

/* WKUP2_EN */

#define CSL_PMMCCONTROL_WKUP2_EN_WKUPEN_MASK                    (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_WKUP2_EN_WKUPEN_SHIFT                   (0U)
#define CSL_PMMCCONTROL_WKUP2_EN_WKUPEN_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_WKUP2_EN_WKUPEN_MAX                     (0xffffffffU)

#define CSL_PMMCCONTROL_WKUP2_EN_RESETVAL                       (0x00000000U)

/* WKUP3_EN */

#define CSL_PMMCCONTROL_WKUP3_EN_WKUPEN_MASK                    (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_WKUP3_EN_WKUPEN_SHIFT                   (0U)
#define CSL_PMMCCONTROL_WKUP3_EN_WKUPEN_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_WKUP3_EN_WKUPEN_MAX                     (0xffffffffU)

#define CSL_PMMCCONTROL_WKUP3_EN_RESETVAL                       (0x00000000U)

/* WKUP4_EN */

#define CSL_PMMCCONTROL_WKUP4_EN_WKUPEN_MASK                    (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_WKUP4_EN_WKUPEN_SHIFT                   (0U)
#define CSL_PMMCCONTROL_WKUP4_EN_WKUPEN_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_WKUP4_EN_WKUPEN_MAX                     (0xffffffffU)

#define CSL_PMMCCONTROL_WKUP4_EN_RESETVAL                       (0x00000000U)

/* WKUP5_EN */

#define CSL_PMMCCONTROL_WKUP5_EN_WKUPEN_MASK                    (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_WKUP5_EN_WKUPEN_SHIFT                   (0U)
#define CSL_PMMCCONTROL_WKUP5_EN_WKUPEN_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_WKUP5_EN_WKUPEN_MAX                     (0xffffffffU)

#define CSL_PMMCCONTROL_WKUP5_EN_RESETVAL                       (0x00000000U)

/* WKUP6_EN */

#define CSL_PMMCCONTROL_WKUP6_EN_WKUPEN_MASK                    (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_WKUP6_EN_WKUPEN_SHIFT                   (0U)
#define CSL_PMMCCONTROL_WKUP6_EN_WKUPEN_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_WKUP6_EN_WKUPEN_MAX                     (0xffffffffU)

#define CSL_PMMCCONTROL_WKUP6_EN_RESETVAL                       (0x00000000U)

/* WKUP7_EN */

#define CSL_PMMCCONTROL_WKUP7_EN_WKUPEN_MASK                    (0x0000FFFFU)
#define CSL_PMMCCONTROL_WKUP7_EN_WKUPEN_SHIFT                   (0U)
#define CSL_PMMCCONTROL_WKUP7_EN_WKUPEN_RESETVAL                (0x00000000U)
#define CSL_PMMCCONTROL_WKUP7_EN_WKUPEN_MAX                     (0x0000ffffU)

#define CSL_PMMCCONTROL_WKUP7_EN_RSVD0_MASK                     (0xFFFF0000U)
#define CSL_PMMCCONTROL_WKUP7_EN_RSVD0_SHIFT                    (16U)
#define CSL_PMMCCONTROL_WKUP7_EN_RSVD0_RESETVAL                 (0x00000000U)
#define CSL_PMMCCONTROL_WKUP7_EN_RSVD0_MAX                      (0x0000ffffU)

#define CSL_PMMCCONTROL_WKUP7_EN_RESETVAL                       (0x00000000U)

/* MADDR_BASE0 */

#define CSL_PMMCCONTROL_MADDR_BASE0_ADDR_MASK                   (0x000FFFFFU)
#define CSL_PMMCCONTROL_MADDR_BASE0_ADDR_SHIFT                  (0U)
#define CSL_PMMCCONTROL_MADDR_BASE0_ADDR_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE0_ADDR_MAX                    (0x000fffffU)

#define CSL_PMMCCONTROL_MADDR_BASE0_RSVD0_MASK                  (0xFFF00000U)
#define CSL_PMMCCONTROL_MADDR_BASE0_RSVD0_SHIFT                 (20U)
#define CSL_PMMCCONTROL_MADDR_BASE0_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE0_RSVD0_MAX                   (0x00000fffU)

#define CSL_PMMCCONTROL_MADDR_BASE0_RESETVAL                    (0x00000000U)

/* MADDR_BASE1 */

#define CSL_PMMCCONTROL_MADDR_BASE1_ADDR_MASK                   (0x000FFFFFU)
#define CSL_PMMCCONTROL_MADDR_BASE1_ADDR_SHIFT                  (0U)
#define CSL_PMMCCONTROL_MADDR_BASE1_ADDR_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE1_ADDR_MAX                    (0x000fffffU)

#define CSL_PMMCCONTROL_MADDR_BASE1_RSVD0_MASK                  (0xFFF00000U)
#define CSL_PMMCCONTROL_MADDR_BASE1_RSVD0_SHIFT                 (20U)
#define CSL_PMMCCONTROL_MADDR_BASE1_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE1_RSVD0_MAX                   (0x00000fffU)

#define CSL_PMMCCONTROL_MADDR_BASE1_RESETVAL                    (0x00000000U)

/* MADDR_BASE2 */

#define CSL_PMMCCONTROL_MADDR_BASE2_ADDR_MASK                   (0x000FFFFFU)
#define CSL_PMMCCONTROL_MADDR_BASE2_ADDR_SHIFT                  (0U)
#define CSL_PMMCCONTROL_MADDR_BASE2_ADDR_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE2_ADDR_MAX                    (0x000fffffU)

#define CSL_PMMCCONTROL_MADDR_BASE2_RSVD0_MASK                  (0xFFF00000U)
#define CSL_PMMCCONTROL_MADDR_BASE2_RSVD0_SHIFT                 (20U)
#define CSL_PMMCCONTROL_MADDR_BASE2_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE2_RSVD0_MAX                   (0x00000fffU)

#define CSL_PMMCCONTROL_MADDR_BASE2_RESETVAL                    (0x00000000U)

/* MADDR_BASE3 */

#define CSL_PMMCCONTROL_MADDR_BASE3_ADDR_MASK                   (0x000FFFFFU)
#define CSL_PMMCCONTROL_MADDR_BASE3_ADDR_SHIFT                  (0U)
#define CSL_PMMCCONTROL_MADDR_BASE3_ADDR_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE3_ADDR_MAX                    (0x000fffffU)

#define CSL_PMMCCONTROL_MADDR_BASE3_RSVD0_MASK                  (0xFFF00000U)
#define CSL_PMMCCONTROL_MADDR_BASE3_RSVD0_SHIFT                 (20U)
#define CSL_PMMCCONTROL_MADDR_BASE3_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE3_RSVD0_MAX                   (0x00000fffU)

#define CSL_PMMCCONTROL_MADDR_BASE3_RESETVAL                    (0x00000000U)

/* MADDR_BASE4 */

#define CSL_PMMCCONTROL_MADDR_BASE4_ADDR_MASK                   (0x000FFFFFU)
#define CSL_PMMCCONTROL_MADDR_BASE4_ADDR_SHIFT                  (0U)
#define CSL_PMMCCONTROL_MADDR_BASE4_ADDR_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE4_ADDR_MAX                    (0x000fffffU)

#define CSL_PMMCCONTROL_MADDR_BASE4_RSVD0_MASK                  (0xFFF00000U)
#define CSL_PMMCCONTROL_MADDR_BASE4_RSVD0_SHIFT                 (20U)
#define CSL_PMMCCONTROL_MADDR_BASE4_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE4_RSVD0_MAX                   (0x00000fffU)

#define CSL_PMMCCONTROL_MADDR_BASE4_RESETVAL                    (0x00000000U)

/* MADDR_BASE5 */

#define CSL_PMMCCONTROL_MADDR_BASE5_ADDR_MASK                   (0x000FFFFFU)
#define CSL_PMMCCONTROL_MADDR_BASE5_ADDR_SHIFT                  (0U)
#define CSL_PMMCCONTROL_MADDR_BASE5_ADDR_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE5_ADDR_MAX                    (0x000fffffU)

#define CSL_PMMCCONTROL_MADDR_BASE5_RSVD0_MASK                  (0xFFF00000U)
#define CSL_PMMCCONTROL_MADDR_BASE5_RSVD0_SHIFT                 (20U)
#define CSL_PMMCCONTROL_MADDR_BASE5_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE5_RSVD0_MAX                   (0x00000fffU)

#define CSL_PMMCCONTROL_MADDR_BASE5_RESETVAL                    (0x00000000U)

/* MADDR_BASE6 */

#define CSL_PMMCCONTROL_MADDR_BASE6_ADDR_MASK                   (0x000FFFFFU)
#define CSL_PMMCCONTROL_MADDR_BASE6_ADDR_SHIFT                  (0U)
#define CSL_PMMCCONTROL_MADDR_BASE6_ADDR_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE6_ADDR_MAX                    (0x000fffffU)

#define CSL_PMMCCONTROL_MADDR_BASE6_RSVD0_MASK                  (0xFFF00000U)
#define CSL_PMMCCONTROL_MADDR_BASE6_RSVD0_SHIFT                 (20U)
#define CSL_PMMCCONTROL_MADDR_BASE6_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE6_RSVD0_MAX                   (0x00000fffU)

#define CSL_PMMCCONTROL_MADDR_BASE6_RESETVAL                    (0x00000000U)

/* MADDR_BASE7 */

#define CSL_PMMCCONTROL_MADDR_BASE7_ADDR_MASK                   (0x000FFFFFU)
#define CSL_PMMCCONTROL_MADDR_BASE7_ADDR_SHIFT                  (0U)
#define CSL_PMMCCONTROL_MADDR_BASE7_ADDR_RESETVAL               (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE7_ADDR_MAX                    (0x000fffffU)

#define CSL_PMMCCONTROL_MADDR_BASE7_RSVD0_MASK                  (0xFFF00000U)
#define CSL_PMMCCONTROL_MADDR_BASE7_RSVD0_SHIFT                 (20U)
#define CSL_PMMCCONTROL_MADDR_BASE7_RSVD0_RESETVAL              (0x00000000U)
#define CSL_PMMCCONTROL_MADDR_BASE7_RSVD0_MAX                   (0x00000fffU)

#define CSL_PMMCCONTROL_MADDR_BASE7_RESETVAL                    (0x00000000U)

/* SPARE0 */

#define CSL_PMMCCONTROL_SPARE0_SPARE_MASK                       (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_SPARE0_SPARE_SHIFT                      (0U)
#define CSL_PMMCCONTROL_SPARE0_SPARE_RESETVAL                   (0x00000000U)
#define CSL_PMMCCONTROL_SPARE0_SPARE_MAX                        (0xffffffffU)

#define CSL_PMMCCONTROL_SPARE0_RESETVAL                         (0x00000000U)

/* SPARE1 */

#define CSL_PMMCCONTROL_SPARE1_SPARE_MASK                       (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_SPARE1_SPARE_SHIFT                      (0U)
#define CSL_PMMCCONTROL_SPARE1_SPARE_RESETVAL                   (0x00000000U)
#define CSL_PMMCCONTROL_SPARE1_SPARE_MAX                        (0xffffffffU)

#define CSL_PMMCCONTROL_SPARE1_RESETVAL                         (0x00000000U)

/* SPARE2 */

#define CSL_PMMCCONTROL_SPARE2_SPARE_MASK                       (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_SPARE2_SPARE_SHIFT                      (0U)
#define CSL_PMMCCONTROL_SPARE2_SPARE_RESETVAL                   (0x00000000U)
#define CSL_PMMCCONTROL_SPARE2_SPARE_MAX                        (0xffffffffU)

#define CSL_PMMCCONTROL_SPARE2_RESETVAL                         (0x00000000U)

/* LOCK3 */

#define CSL_PMMCCONTROL_LOCK3_KEY_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_LOCK3_KEY_SHIFT                         (0U)
#define CSL_PMMCCONTROL_LOCK3_KEY_RESETVAL                      (0xb9e864afU)
#define CSL_PMMCCONTROL_LOCK3_KEY_MAX                           (0xffffffffU)

#define CSL_PMMCCONTROL_LOCK3_RESETVAL                          (0xb9e864afU)

/* LOCK4 */

#define CSL_PMMCCONTROL_LOCK4_KEY_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_LOCK4_KEY_SHIFT                         (0U)
#define CSL_PMMCCONTROL_LOCK4_KEY_RESETVAL                      (0xfde46920U)
#define CSL_PMMCCONTROL_LOCK4_KEY_MAX                           (0xffffffffU)

#define CSL_PMMCCONTROL_LOCK4_RESETVAL                          (0xfde46920U)

/* LOCK5 */

#define CSL_PMMCCONTROL_LOCK5_KEY_MASK                          (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_LOCK5_KEY_SHIFT                         (0U)
#define CSL_PMMCCONTROL_LOCK5_KEY_RESETVAL                      (0xed676313U)
#define CSL_PMMCCONTROL_LOCK5_KEY_MAX                           (0xffffffffU)

#define CSL_PMMCCONTROL_LOCK5_RESETVAL                          (0xed676313U)

/* INTR_EOI */

#define CSL_PMMCCONTROL_INTR_EOI_EOI_MASK                       (0x00000003U)
#define CSL_PMMCCONTROL_INTR_EOI_EOI_SHIFT                      (0U)
#define CSL_PMMCCONTROL_INTR_EOI_EOI_RESETVAL                   (0x00000000U)
#define CSL_PMMCCONTROL_INTR_EOI_EOI_MAX                        (0x00000003U)

#define CSL_PMMCCONTROL_INTR_EOI_RSVD0_MASK                     (0xFFFFFFFCU)
#define CSL_PMMCCONTROL_INTR_EOI_RSVD0_SHIFT                    (2U)
#define CSL_PMMCCONTROL_INTR_EOI_RSVD0_RESETVAL                 (0x00000000U)
#define CSL_PMMCCONTROL_INTR_EOI_RSVD0_MAX                      (0x3fffffffU)

#define CSL_PMMCCONTROL_INTR_EOI_RESETVAL                       (0x00000000U)

/* INTR0_OUT_IRQSTATUS_RAW */

#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_RAW_EVENT_MASK      (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_RAW_EVENT_SHIFT     (0U)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_RAW_EVENT_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_RAW_EVENT_MAX       (0xffffffffU)

#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_RAW_RESETVAL        (0x00000000U)

/* INTR0_OUT_IRQSTATUS */

#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_EVENT_MASK          (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_EVENT_SHIFT         (0U)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_EVENT_RESETVAL      (0x00000000U)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_EVENT_MAX           (0xffffffffU)

#define CSL_PMMCCONTROL_INTR0_OUT_IRQSTATUS_RESETVAL            (0x00000000U)

/* INTR0_OUT_IRQENABLE_SET */

#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_SET_ENABLE_MASK     (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_SET_ENABLE_SHIFT    (0U)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_SET_ENABLE_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_SET_ENABLE_MAX      (0xffffffffU)

#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_SET_RESETVAL        (0x00000000U)

/* INTR0_OUT_IRQENABLE_CLR */

#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_CLR_ENABLE_MASK     (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_CLR_ENABLE_SHIFT    (0U)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_CLR_ENABLE_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_CLR_ENABLE_MAX      (0xffffffffU)

#define CSL_PMMCCONTROL_INTR0_OUT_IRQENABLE_CLR_RESETVAL        (0x00000000U)

/* INTR1_OUT_IRQSTATUS_RAW */

#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_RAW_EVENT_MASK      (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_RAW_EVENT_SHIFT     (0U)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_RAW_EVENT_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_RAW_EVENT_MAX       (0xffffffffU)

#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_RAW_RESETVAL        (0x00000000U)

/* INTR1_OUT_IRQSTATUS */

#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_EVENT_MASK          (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_EVENT_SHIFT         (0U)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_EVENT_RESETVAL      (0x00000000U)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_EVENT_MAX           (0xffffffffU)

#define CSL_PMMCCONTROL_INTR1_OUT_IRQSTATUS_RESETVAL            (0x00000000U)

/* INTR1_OUT_IRQENABLE_SET */

#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_SET_ENABLE_MASK     (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_SET_ENABLE_SHIFT    (0U)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_SET_ENABLE_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_SET_ENABLE_MAX      (0xffffffffU)

#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_SET_RESETVAL        (0x00000000U)

/* INTR1_OUT_IRQENABLE_CLR */

#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_CLR_ENABLE_MASK     (0xFFFFFFFFU)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_CLR_ENABLE_SHIFT    (0U)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_CLR_ENABLE_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_CLR_ENABLE_MAX      (0xffffffffU)

#define CSL_PMMCCONTROL_INTR1_OUT_IRQENABLE_CLR_RESETVAL        (0x00000000U)

/* INTR_FAULTDET_IRQSTATUS_RAW */

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW_EVENT_MASK  (0x0000FFFFU)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW_EVENT_SHIFT  (0U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW_EVENT_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW_EVENT_MAX   (0x0000ffffU)

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW_RSVD0_MASK  (0xFFFF0000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW_RSVD0_SHIFT  (16U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW_RSVD0_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW_RSVD0_MAX   (0x0000ffffU)

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RAW_RESETVAL    (0x00000000U)

/* INTR_FAULTDET_IRQSTATUS */

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_EVENT_MASK      (0x0000FFFFU)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_EVENT_SHIFT     (0U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_EVENT_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_EVENT_MAX       (0x0000ffffU)

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RSVD0_MASK      (0xFFFF0000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RSVD0_SHIFT     (16U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RSVD0_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RSVD0_MAX       (0x0000ffffU)

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQSTATUS_RESETVAL        (0x00000000U)

/* INTR_FAULTDET_IRQENABLE_SET */

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET_ENABLE_MASK  (0x0000FFFFU)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET_ENABLE_SHIFT  (0U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET_ENABLE_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET_ENABLE_MAX  (0x0000ffffU)

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET_RSVD0_MASK  (0xFFFF0000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET_RSVD0_SHIFT  (16U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET_RSVD0_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET_RSVD0_MAX   (0x0000ffffU)

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_SET_RESETVAL    (0x00000000U)

/* INTR_FAULTDET_IRQENABLE_CLR */

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_CLR_ENABLE_MASK  (0x0000FFFFU)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_CLR_ENABLE_SHIFT  (0U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_CLR_ENABLE_RESETVAL  (0x00000000U)
#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_CLR_ENABLE_MAX  (0x0000ffffU)

#define CSL_PMMCCONTROL_INTR_FAULTDET_IRQENABLE_CLR_RESETVAL    (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
