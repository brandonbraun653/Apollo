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
#ifndef CSLR_MLB_H_
#define CSLR_MLB_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for MESSAGE_REGSET_0_15
**************************************************************************/
typedef struct {
    volatile Uint32 MESSAGE;
} CSL_MlbMessage_regset_0_15Regs;


/**************************************************************************
* Register Overlay Structure for FIFOSTATUS_REGSET_0_15
**************************************************************************/
typedef struct {
    volatile Uint32 FIFOSTS;
} CSL_MlbFifostatus_regset_0_15Regs;


/**************************************************************************
* Register Overlay Structure for MAILBOX_MSGSTATUS_REGSET_0_15
**************************************************************************/
typedef struct {
    volatile Uint32 MSGSTS;
} CSL_MlbMailbox_msgstatus_regset_0_15Regs;


/**************************************************************************
* Register Overlay Structure for IRQ_REGSET_0_3
**************************************************************************/
typedef struct {
    volatile Uint32 IRQSTS_RAW;
    volatile Uint32 IRQSTS_CLR;
    volatile Uint32 IRQEN_SET;
    volatile Uint32 IRQEN_CLR;
} CSL_MlbIrq_regset_0_3Regs;


/**************************************************************************
* Register Overlay Structure for Trailer
**************************************************************************/
typedef struct {
    volatile Uint32 IRQ_EOI;
} CSL_MlbTrailerRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD0[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint8  RSVD1[44];
    CSL_MlbMessage_regset_0_15Regs	MESSAGE_REGSET_0_15[6];
    volatile Uint8  RSVD2[40];
    CSL_MlbFifostatus_regset_0_15Regs	FIFOSTATUS_REGSET_0_15[6];
    volatile Uint8  RSVD3[40];
    CSL_MlbMailbox_msgstatus_regset_0_15Regs	MAILBOX_MSGSTATUS_REGSET_0_15[6];
    volatile Uint8  RSVD4[40];
    CSL_MlbIrq_regset_0_3Regs	IRQ_REGSET_0_3[4];
    CSL_MlbTrailerRegs	TRAILER;
} CSL_MlbRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* This register contains the IP revision code */
#define CSL_MLB_REVISION                                        (0x0U)

/* This register controls the various parameters of the OCP interface */
#define CSL_MLB_SYSCONFIG                                       (0x10U)

/* The message register stores the next to be read message of the mailbox X */
#define CSL_MLB_MESSAGE(n)                                      (0x40U + ((n) * (0x4U)))

/* The FIFO status register has the status related to the mailbox internal
 * FIFO */
#define CSL_MLB_FIFOSTS(n)                                      (0x80U + ((n) * (0x4U)))

/* The message status register has the status of the messages in the mailbox */
#define CSL_MLB_MSGSTS(n)                                       (0xC0U + ((n) * (0x4U)))

/* The interrupt status register has the status for each event that may be
 * responsible for the generation of an interrupt to the corresponding user -
 * write 1 to a given bit sets this bit (note : HW reset value is 0x0, but
 * first value that can be seen by SW is 0x0AAA) */
#define CSL_MLB_IRQSTS_RAW(n)                                   (0x100U + ((n) * (0x10U)))

/* The interrupt status register has the status combined with irq-enable for
 * each event that may be responsible for the generation of an interrupt to
 * the corresponding user - write 1 to a given bit resets this bit */
#define CSL_MLB_IRQSTS_CLR(n)                                   (0x104U + ((n) * (0x10U)))

/* The interrupt enable register enables to mask/unmask the module internal
 * source of interrupt to the corresponding user. This register is write 1 to
 * clear. */
#define CSL_MLB_IRQEN_CLR(n)                                    (0x10CU + ((n) * (0x10U)))

/* The interrupt enable register enables to mask/unmask the module internal
 * source of interrupt to the corresponding user This register is write 1 to
 * set. */
#define CSL_MLB_IRQEN_SET(n)                                    (0x108U + ((n) * (0x10U)))

/* This register is used for the software EOI clearance of the pulse. This
 * register being write only gives 0 on read. */
#define CSL_MLB_IRQ_EOI                                         (0x140U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_MLB_REVISION_SCHEME_MASK                            (0xC0000000U)
#define CSL_MLB_REVISION_SCHEME_SHIFT                           (30U)
#define CSL_MLB_REVISION_SCHEME_RESETVAL                        (0x00000000U)
#define CSL_MLB_REVISION_SCHEME_MAX                             (0x00000003U)

#define CSL_MLB_REVISION_RES_MASK                               (0x30000000U)
#define CSL_MLB_REVISION_RES_SHIFT                              (28U)
#define CSL_MLB_REVISION_RES_RESETVAL                           (0x00000000U)
#define CSL_MLB_REVISION_RES_MAX                                (0x00000003U)

#define CSL_MLB_REVISION_FUNC_MASK                              (0x0FFF0000U)
#define CSL_MLB_REVISION_FUNC_SHIFT                             (16U)
#define CSL_MLB_REVISION_FUNC_RESETVAL                          (0x00000000U)
#define CSL_MLB_REVISION_FUNC_MAX                               (0x00000fffU)

#define CSL_MLB_REVISION_RTL_MASK                               (0x0000F800U)
#define CSL_MLB_REVISION_RTL_SHIFT                              (11U)
#define CSL_MLB_REVISION_RTL_RESETVAL                           (0x00000000U)
#define CSL_MLB_REVISION_RTL_MAX                                (0x0000001fU)

#define CSL_MLB_REVISION_MAJOR_MASK                             (0x00000700U)
#define CSL_MLB_REVISION_MAJOR_SHIFT                            (8U)
#define CSL_MLB_REVISION_MAJOR_RESETVAL                         (0x00000004U)
#define CSL_MLB_REVISION_MAJOR_MAX                              (0x00000007U)

#define CSL_MLB_REVISION_CUSTOM_MASK                            (0x000000C0U)
#define CSL_MLB_REVISION_CUSTOM_SHIFT                           (6U)
#define CSL_MLB_REVISION_CUSTOM_RESETVAL                        (0x00000000U)
#define CSL_MLB_REVISION_CUSTOM_MAX                             (0x00000003U)

#define CSL_MLB_REVISION_MINOR_MASK                             (0x0000003FU)
#define CSL_MLB_REVISION_MINOR_SHIFT                            (0U)
#define CSL_MLB_REVISION_MINOR_RESETVAL                         (0x00000000U)
#define CSL_MLB_REVISION_MINOR_MAX                              (0x0000003fU)

#define CSL_MLB_REVISION_RESETVAL                               (0x00000400U)

/* SYSCONFIG */

#define CSL_MLB_SYSCONFIG_SOFTRESET_MASK                        (0x00000001U)
#define CSL_MLB_SYSCONFIG_SOFTRESET_SHIFT                       (0U)
#define CSL_MLB_SYSCONFIG_SOFTRESET_RESETVAL                    (0x00000000U)
#define CSL_MLB_SYSCONFIG_SOFTRESET_B0                          (0x00000000U)
#define CSL_MLB_SYSCONFIG_SOFTRESET_B1                          (0x00000001U)

#define CSL_MLB_SYSCONFIG_SIDLEMODE_MASK                        (0x0000000CU)
#define CSL_MLB_SYSCONFIG_SIDLEMODE_SHIFT                       (2U)
#define CSL_MLB_SYSCONFIG_SIDLEMODE_RESETVAL                    (0x00000002U)
#define CSL_MLB_SYSCONFIG_SIDLEMODE_B00                         (0x00000000U)
#define CSL_MLB_SYSCONFIG_SIDLEMODE_B01                         (0x00000001U)
#define CSL_MLB_SYSCONFIG_SIDLEMODE_B10                         (0x00000002U)
#define CSL_MLB_SYSCONFIG_SIDLEMODE_B11                         (0x00000003U)

#define CSL_MLB_SYSCONFIG_RESETVAL                              (0x00000008U)

/* MESSAGE */

#define CSL_MLB_MESSAGE_MESSAGEVALUEMBM_MASK                    (0xFFFFFFFFU)
#define CSL_MLB_MESSAGE_MESSAGEVALUEMBM_SHIFT                   (0U)
#define CSL_MLB_MESSAGE_MESSAGEVALUEMBM_RESETVAL                (0x00000000U)
#define CSL_MLB_MESSAGE_MESSAGEVALUEMBM_MAX                     (0xffffffffU)

#define CSL_MLB_MESSAGE_RESETVAL                                (0x00000000U)

/* FIFOSTS */

#define CSL_MLB_FIFOSTS_FIFOFULLMBM_MASK                        (0x00000001U)
#define CSL_MLB_FIFOSTS_FIFOFULLMBM_SHIFT                       (0U)
#define CSL_MLB_FIFOSTS_FIFOFULLMBM_RESETVAL                    (0x00000000U)
#define CSL_MLB_FIFOSTS_FIFOFULLMBM_MAX                         (0x00000001U)

#define CSL_MLB_FIFOSTS_RESETVAL                                (0x00000000U)

/* MSGSTS */

#define CSL_MLB_MSGSTS_NBOFMSGMBM_MASK                          (0x0000007FU)
#define CSL_MLB_MSGSTS_NBOFMSGMBM_SHIFT                         (0U)
#define CSL_MLB_MSGSTS_NBOFMSGMBM_RESETVAL                      (0x00000000U)
#define CSL_MLB_MSGSTS_NBOFMSGMBM_MAX                           (0x0000007fU)

#define CSL_MLB_MSGSTS_RESETVAL                                 (0x00000000U)

/* IRQSTS_RAW */

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_MASK                 (0x00000002U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_SHIFT                (1U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB0_MAX                  (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB4_MASK                 (0x00000200U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB4_SHIFT                (9U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB4_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB4_MAX                  (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB8_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB8_SHIFT                (17U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB8_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB8_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_MASK                  (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_SHIFT                 (0U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB0_MAX                   (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB4_MASK                  (0x00000100U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB4_SHIFT                 (8U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB4_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB4_MAX                   (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB8_MASK                  (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB8_SHIFT                 (16U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB8_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB8_MAX                   (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB3_MASK                 (0x00000080U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB3_SHIFT                (7U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB3_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB3_MAX                  (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB3_MASK                  (0x00000040U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB3_SHIFT                 (6U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB3_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB3_MAX                   (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB1_MASK                 (0x00000008U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB1_SHIFT                (3U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB1_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB1_MAX                  (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB5_MASK                 (0x00000800U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB5_SHIFT                (11U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB5_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB5_MAX                  (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB9_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB9_SHIFT                (19U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB9_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB9_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB13_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB13_SHIFT               (27U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB13_RESETVAL            (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB13_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB1_MASK                  (0x00000004U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB1_SHIFT                 (2U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB1_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB1_MAX                   (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB5_MASK                  (0x00000400U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB5_SHIFT                 (10U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB5_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB5_MAX                   (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB9_MASK                  (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB9_SHIFT                 (18U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB9_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB9_MAX                   (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB13_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB13_SHIFT                (26U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB13_RESETVAL             (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB13_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB12_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB12_SHIFT               (25U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB12_RESETVAL            (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB12_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB12_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB12_SHIFT                (24U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB12_RESETVAL             (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB12_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB7_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB7_SHIFT                (15U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB7_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB7_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB11_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB11_SHIFT               (23U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB11_RESETVAL            (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB11_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB15_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB15_SHIFT               (31U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB15_RESETVAL            (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB15_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB7_MASK                  (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB7_SHIFT                 (14U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB7_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB7_MAX                   (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB11_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB11_SHIFT                (22U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB11_RESETVAL             (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB11_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB15_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB15_SHIFT                (30U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB15_RESETVAL             (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB15_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB2_MASK                 (0x00000020U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB2_SHIFT                (5U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB2_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB2_MAX                  (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB6_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB6_SHIFT                (13U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB6_RESETVAL             (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB6_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB10_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB10_SHIFT               (21U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB10_RESETVAL            (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB10_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB14_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB14_SHIFT               (29U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB14_RESETVAL            (0x00000001U)
#define CSL_MLB_IRQSTS_RAW_NOTFULLSTSUUMB14_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB2_MASK                  (0x00000010U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB2_SHIFT                 (4U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB2_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB2_MAX                   (0x00000001U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB6_MASK                  (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB6_SHIFT                 (12U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB6_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB6_MAX                   (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB10_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB10_SHIFT                (20U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB10_RESETVAL             (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB10_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB14_MASK                 (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB14_SHIFT                (28U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB14_RESETVAL             (0x00000000U)
#define CSL_MLB_IRQSTS_RAW_NEWMSGSTSUUMB14_MAX                  (0x00000000U)

#define CSL_MLB_IRQSTS_RAW_RESETVAL                             (0xaaaaaaaaU)

/* IRQSTS_CLR */

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB0_MASK               (0x00000002U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB0_SHIFT              (1U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB0_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB0_MAX                (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB4_MASK               (0x00000200U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB4_SHIFT              (9U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB4_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB4_MAX                (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB8_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB8_SHIFT              (17U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB8_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB8_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB0_MASK                (0x00000001U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB0_SHIFT               (0U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB0_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB0_MAX                 (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB4_MASK                (0x00000100U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB4_SHIFT               (8U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB4_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB4_MAX                 (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB8_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB8_SHIFT               (16U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB8_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB8_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB3_MASK               (0x00000080U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB3_SHIFT              (7U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB3_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB3_MAX                (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB3_MASK                (0x00000040U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB3_SHIFT               (6U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB3_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB3_MAX                 (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB1_MASK               (0x00000008U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB1_SHIFT              (3U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB1_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB1_MAX                (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB5_MASK               (0x00000800U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB5_SHIFT              (11U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB5_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB5_MAX                (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB9_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB9_SHIFT              (19U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB9_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB9_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB13_MASK              (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB13_SHIFT             (27U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB13_RESETVAL          (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB13_MAX               (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB1_MASK                (0x00000004U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB1_SHIFT               (2U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB1_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB1_MAX                 (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB5_MASK                (0x00000400U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB5_SHIFT               (10U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB5_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB5_MAX                 (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB9_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB9_SHIFT               (18U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB9_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB9_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB13_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB13_SHIFT              (26U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB13_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB13_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB12_MASK              (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB12_SHIFT             (25U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB12_RESETVAL          (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB12_MAX               (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB12_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB12_SHIFT              (24U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB12_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB12_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB7_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB7_SHIFT              (15U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB7_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB7_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB11_MASK              (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB11_SHIFT             (23U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB11_RESETVAL          (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB11_MAX               (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB15_MASK              (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB15_SHIFT             (31U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB15_RESETVAL          (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB15_MAX               (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB7_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB7_SHIFT               (14U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB7_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB7_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB11_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB11_SHIFT              (22U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB11_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB11_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB15_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB15_SHIFT              (30U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB15_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB15_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB2_MASK               (0x00000020U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB2_SHIFT              (5U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB2_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB2_MAX                (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB6_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB6_SHIFT              (13U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB6_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB6_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB10_MASK              (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB10_SHIFT             (21U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB10_RESETVAL          (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB10_MAX               (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB14_MASK              (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB14_SHIFT             (29U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB14_RESETVAL          (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NOTFULLSTSENUUMB14_MAX               (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB2_MASK                (0x00000010U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB2_SHIFT               (4U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB2_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB2_MAX                 (0x00000001U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB6_MASK                (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB6_SHIFT               (12U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB6_RESETVAL            (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB6_MAX                 (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB10_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB10_SHIFT              (20U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB10_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB10_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB14_MASK               (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB14_SHIFT              (28U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB14_RESETVAL           (0x00000000U)
#define CSL_MLB_IRQSTS_CLR_NEWMSGSTSENUUMB14_MAX                (0x00000000U)

#define CSL_MLB_IRQSTS_CLR_RESETVAL                             (0x00000000U)

/* IRQEN_CLR */

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB14_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB14_SHIFT                  (28U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB14_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB14_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB10_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB10_SHIFT                  (20U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB10_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB10_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB6_MASK                    (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB6_SHIFT                   (12U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB6_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB6_MAX                     (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB2_MASK                    (0x00000010U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB2_SHIFT                   (4U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB2_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB2_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB14_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB14_SHIFT                 (29U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB14_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB14_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB10_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB10_SHIFT                 (21U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB10_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB10_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB6_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB6_SHIFT                  (13U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB6_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB6_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB2_MASK                   (0x00000020U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB2_SHIFT                  (5U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB2_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB2_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB15_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB15_SHIFT                  (30U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB15_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB15_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB11_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB11_SHIFT                  (22U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB11_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB11_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB7_MASK                    (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB7_SHIFT                   (14U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB7_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB7_MAX                     (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB15_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB15_SHIFT                 (31U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB15_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB15_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB11_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB11_SHIFT                 (23U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB11_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB11_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB7_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB7_SHIFT                  (15U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB7_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB7_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB12_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB12_SHIFT                  (24U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB12_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB12_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB12_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB12_SHIFT                 (25U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB12_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB12_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB13_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB13_SHIFT                  (26U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB13_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB13_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB9_MASK                    (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB9_SHIFT                   (18U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB9_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB9_MAX                     (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB5_MASK                    (0x00000400U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB5_SHIFT                   (10U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB5_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB5_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB1_MASK                    (0x00000004U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB1_SHIFT                   (2U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB1_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB1_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB13_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB13_SHIFT                 (27U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB13_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB13_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB9_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB9_SHIFT                  (19U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB9_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB9_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB5_MASK                   (0x00000800U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB5_SHIFT                  (11U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB5_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB5_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB1_MASK                   (0x00000008U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB1_SHIFT                  (3U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB1_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB1_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB3_MASK                    (0x00000040U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB3_SHIFT                   (6U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB3_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB3_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB3_MASK                   (0x00000080U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB3_SHIFT                  (7U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB3_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB3_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB8_MASK                    (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB8_SHIFT                   (16U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB8_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB8_MAX                     (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB4_MASK                    (0x00000100U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB4_SHIFT                   (8U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB4_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB4_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB0_MASK                    (0x00000001U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB0_SHIFT                   (0U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB0_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NEWMSGENUUMB0_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB8_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB8_SHIFT                  (17U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB8_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB8_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB4_MASK                   (0x00000200U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB4_SHIFT                  (9U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB4_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB4_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB0_MASK                   (0x00000002U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB0_SHIFT                  (1U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB0_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_CLR_NOTFULLENUUMB0_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_CLR_RESETVAL                              (0x00000000U)

/* IRQEN_SET */

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB14_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB14_SHIFT                  (28U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB14_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB14_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB10_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB10_SHIFT                  (20U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB10_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB10_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB6_MASK                    (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB6_SHIFT                   (12U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB6_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB6_MAX                     (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB2_MASK                    (0x00000010U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB2_SHIFT                   (4U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB2_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB2_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB14_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB14_SHIFT                 (29U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB14_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB14_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB10_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB10_SHIFT                 (21U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB10_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB10_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB6_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB6_SHIFT                  (13U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB6_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB6_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB2_MASK                   (0x00000020U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB2_SHIFT                  (5U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB2_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB2_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB15_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB15_SHIFT                  (30U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB15_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB15_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB11_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB11_SHIFT                  (22U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB11_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB11_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB7_MASK                    (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB7_SHIFT                   (14U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB7_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB7_MAX                     (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB15_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB15_SHIFT                 (31U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB15_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB15_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB11_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB11_SHIFT                 (23U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB11_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB11_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB7_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB7_SHIFT                  (15U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB7_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB7_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB12_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB12_SHIFT                  (24U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB12_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB12_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB12_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB12_SHIFT                 (25U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB12_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB12_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB13_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB13_SHIFT                  (26U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB13_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB13_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB9_MASK                    (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB9_SHIFT                   (18U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB9_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB9_MAX                     (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB5_MASK                    (0x00000400U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB5_SHIFT                   (10U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB5_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB5_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB1_MASK                    (0x00000004U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB1_SHIFT                   (2U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB1_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB1_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB13_MASK                  (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB13_SHIFT                 (27U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB13_RESETVAL              (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB13_MAX                   (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB9_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB9_SHIFT                  (19U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB9_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB9_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB5_MASK                   (0x00000800U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB5_SHIFT                  (11U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB5_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB5_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB1_MASK                   (0x00000008U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB1_SHIFT                  (3U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB1_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB1_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB3_MASK                    (0x00000040U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB3_SHIFT                   (6U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB3_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB3_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB3_MASK                   (0x00000080U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB3_SHIFT                  (7U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB3_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB3_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB8_MASK                    (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB8_SHIFT                   (16U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB8_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB8_MAX                     (0x00000000U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB4_MASK                    (0x00000100U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB4_SHIFT                   (8U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB4_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB4_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB0_MASK                    (0x00000001U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB0_SHIFT                   (0U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB0_RESETVAL                (0x00000000U)
#define CSL_MLB_IRQEN_SET_NEWMSGENUUMB0_MAX                     (0x00000001U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB8_MASK                   (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB8_SHIFT                  (17U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB8_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB8_MAX                    (0x00000000U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB4_MASK                   (0x00000200U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB4_SHIFT                  (9U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB4_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB4_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB0_MASK                   (0x00000002U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB0_SHIFT                  (1U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB0_RESETVAL               (0x00000000U)
#define CSL_MLB_IRQEN_SET_NOTFULLENUUMB0_MAX                    (0x00000001U)

#define CSL_MLB_IRQEN_SET_RESETVAL                              (0x00000000U)

/* IRQ_EOI */

#define CSL_MLB_IRQ_EOI_EOIVAL_MASK                             (0x00000003U)
#define CSL_MLB_IRQ_EOI_EOIVAL_SHIFT                            (0U)
#define CSL_MLB_IRQ_EOI_EOIVAL_RESETVAL                         (0x00000000U)
#define CSL_MLB_IRQ_EOI_EOIVAL_B0                               (0x00000000U)
#define CSL_MLB_IRQ_EOI_EOIVAL_B1                               (0x00000001U)

#define CSL_MLB_IRQ_EOI_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
