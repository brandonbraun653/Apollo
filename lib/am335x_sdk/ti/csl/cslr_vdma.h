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
#ifndef CSLR_VDMA_H_
#define CSLR_VDMA_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for Deterministic_descriptor_entry
**************************************************************************/
typedef struct {
    volatile Uint32 L_DETERM_31_0;
    volatile Uint32 L_DETERM_63_32;
    volatile Uint32 L_DETERM_95_64;
    volatile Uint32 L_DETERM_127_96;
    volatile Uint32 H_DETERM_31_0;
    volatile Uint32 H_DETERM_63_32;
    volatile Uint32 H_DETERM_95_64;
    volatile Uint32 H_DETERM_127_96;
} CSL_VdmaDeterministic_descriptor_entryRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 REVISION;
    volatile Uint8  RSVD0[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint8  RSVD1[12];
    volatile Uint32 IRQ_EOI;
    volatile Uint32 IRQSTS_RAW_0;
    volatile Uint32 IRQSTS_0;
    volatile Uint32 IRQEN_SET_0;
    volatile Uint32 IRQEN_CLR_0;
    volatile Uint32 IRQSTS_RAW_1;
    volatile Uint32 IRQSTS_1;
    volatile Uint32 IRQEN_SET_1;
    volatile Uint32 IRQEN_CLR_1;
    volatile Uint32 IRQSTS_RAW_2;
    volatile Uint32 IRQSTS_2;
    volatile Uint32 IRQEN_SET_2;
    volatile Uint32 IRQEN_CLR_2;
    volatile Uint32 SYNCHR_LIST_LEVEL;
    volatile Uint32 ASYNCHR_LIST_LEVEL;
    volatile Uint32 NON_DETERM_FIFO_LEVEL;
    volatile Uint32 TBA;
    volatile Uint32 CONTEXT_STS;
    volatile Uint32 GROUP_TRIGGER;
    volatile Uint32 MAX_CONTEXT_SYNCHR;
    volatile Uint32 MAX_CONTEXT_ASYNCHR;
    volatile Uint32 IRQ_NEOG;
    volatile Uint32 GROUP_STS[32];
    volatile Uint32 GROUP_DEFINITION[32];
    volatile Uint32 NON_DETERM[4];
    volatile Uint8  RSVD2[1656];
    volatile Uint32 TRIGGER_CTR[128];
    volatile Uint8  RSVD3[1536];
    CSL_VdmaDeterministic_descriptor_entryRegs	DETERMINISTIC_DESCRIPTOR_ENTRY[128];
} CSL_VdmaRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* IP Revision Identifier This allows a PID showing X.Y.R in silicon to relate
 * the RTL release with a (close-to-correct) spec version X.Y.S. A peripheral
 * ID register must be included at address offset 0 of a peripherals control
 * register MAP. The purpose is to let software read the peripheral to
 * understand what type of peripheral is there and what features are enabled
 * as well as what bugs or issues may exist in a particular version. */
#define CSL_VDMA_REVISION                                       (0x0U)

/* Clock management configuration */
#define CSL_VDMA_SYSCONFIG                                      (0x10U)

/* End Of Interrupt number specification */
#define CSL_VDMA_IRQ_EOI                                        (0x20U)

/* Per-end of group (31 down to 0) internal signaling raw interrupt status
 * vector, line #0. Raw status is set even if end of group (31 downto 0)
 * interrupt is not enabled. Write 1 to set the (raw) status, mostly for
 * debug. */
#define CSL_VDMA_IRQSTS_RAW_0                                   (0x24U)

/* Per-end of group (31 down to 0) internal signaling "enabled" interrupt
 * status vector, line #0. Enabled status isn't set unless event is enabled.
 * Write 1 to clear the status after interrupt has been serviced (raw status
 * gets cleared, i.e. even if not enabled). */
#define CSL_VDMA_IRQSTS_0                                       (0x28U)

/* Per-end of group (31 down to 0) internal event interrupt enable bit vector,
 * line #0. Write 1 to set (enable interrupt). Readout equal to corresponding
 * _CLR register. */
#define CSL_VDMA_IRQEN_SET_0                                    (0x2CU)

/* Per-end of group (31 down to 0) internal event interrupt enable bit vector,
 * line #0. Write 1 to clear (disable interrupt). Readout equal to
 * corresponding _SET register. */
#define CSL_VDMA_IRQEN_CLR_0                                    (0x30U)

/* Per-end of group (31 down to 0) internal signaling raw interrupt status
 * vector, line #1. Raw status is set even if event is not enabled. Write 1 to
 * set the (raw) status, mostly for debug. */
#define CSL_VDMA_IRQSTS_RAW_1                                   (0x34U)

/* Per-end of group (31 down to 0) internal signaling "enabled" interrupt
 * status vector, line #1. Enabled status isn't set unless event is enabled.
 * Write 1 to clear the status after interrupt has been serviced (raw status
 * gets cleared, i.e. even if not enabled). */
#define CSL_VDMA_IRQSTS_1                                       (0x38U)

/* Per-end of group (31 down to 0) internal event interrupt enable bit vector,
 * line #1. Write 1 to set (enable interrupt). Readout equal to corresponding
 * _CLR register. */
#define CSL_VDMA_IRQEN_SET_1                                    (0x3CU)

/* Per-end of group (31 down to 0) internal event interrupt enable bit vector,
 * line #1. Write 1 to clear (disable interrupt). Readout equal to
 * corresponding _SET register. */
#define CSL_VDMA_IRQEN_CLR_1                                    (0x40U)

/* Per-error event raw interrupt status vector, line #2. Raw status is set
 * even if event is not enabled. Write 1 to set the (raw) status, mostly for
 * debug. Write 0: No action Read 0: No evt pend. Read 1: Event pend. Write 1:
 * Set event */
#define CSL_VDMA_IRQSTS_RAW_2                                   (0x44U)

/* Per-error event "enabled" interrupt status vector, line #2. Enabled status
 * isn't set unless event is enabled. Write 1 to clear the status after
 * interrupt has been serviced (raw status gets cleared, i.e. even if not
 * enabled). Write 0: No action Read 0: No (enabled) event pending Read 1:
 * Event pending Write 1: Clear (raw) event */
#define CSL_VDMA_IRQSTS_2                                       (0x48U)

/* Per-error event interrupt enable bit vector, line #2. Write 1 to set
 * (enable interrupt). Readout equal to corresponding _CLR register. enable
 * for end_of_group31 to 0 interrupts Write 0: No action Read 0: Interrupt
 * disabled (masked) Read 1: Interrupt enabled Write 1: Enable interrupt */
#define CSL_VDMA_IRQEN_SET_2                                    (0x4CU)

/* Per-error event interrupt enable bit vector, line #2. Write 1 to clear
 * (disable interrupt). Readout equal to corresponding _SET register. Write 0:
 * No action Read 0: Interrupt disabled (masked) Read 1: Interrupt enabled
 * Write 1: Disable interrupt */
#define CSL_VDMA_IRQEN_CLR_2                                    (0x50U)

/* SYNCHR_LIST_LEVEL */
#define CSL_VDMA_SYNCHR_LIST_LEVEL                              (0x54U)

/* ASYNCHR_LIST_LEVEL */
#define CSL_VDMA_ASYNCHR_LIST_LEVEL                             (0x58U)

/* NON_DETERM_FIFO_LEVEL */
#define CSL_VDMA_NON_DETERM_FIFO_LEVEL                          (0x5CU)

/* tiler address mapping. This register shall only be set statically, i.e. at
 * early vDMA configuration time, before any transfer is ever triggered. */
#define CSL_VDMA_TBA                                            (0x60U)

/* When individual bit is reset, corresponding context is available When
 * individual bit is set, corresponding context is allocated. */
#define CSL_VDMA_CONTEXT_STS                                    (0x64U)

/* Register entry for SW user to trigger deterministic (only) groups through
 * CPU writes. write "1" to desired bit triggers corresponding group (which
 * SHALL be defined as deterministic through GROUP_DEFINITION register set).
 * Writing "1" to a group defined as non deterministic leads to vDMA undefined
 * behavior. write "0" has no effect. */
#define CSL_VDMA_GROUP_TRIGGER                                  (0x68U)

/* SW user configurable maximum number of context synchronous list can get
 * benefit of. This register should only be set statically, i.e. at early vDMA
 * configuration time, before any transfer is ever triggered. Should it be set
 * with another value at run time, SW user shall ensure that there is no
 * pending trigger, no pending descriptors in non deterministic FIFO, no
 * pending descriptors in asynchronous nor synchronous list and no pending
 * transactions on master ports. */
#define CSL_VDMA_MAX_CONTEXT_SYNCHR                             (0x6CU)

/* SW user configurable maximum number of context asynchronous list can get
 * benefit of. This register should only be set statically, i.e. at early vDMA
 * configuration time, before any transfer is ever triggered. Should it be set
 * with another value at run time, SW user shall ensure that there is no
 * pending trigger, no pending descriptors in non deterministic FIFO, no
 * pending descriptors in asynchronous nor synchronous list and no pending
 * transactions on master ports. */
#define CSL_VDMA_MAX_CONTEXT_ASYNCHR                            (0x70U)

/* Sets whether end of group signaling should be set through external HW lines
 * (pulse) or wrapped into interrupt line. */
#define CSL_VDMA_IRQ_NEOG                                       (0x74U)

/* GROUP_STS */
#define CSL_VDMA_GROUP_STS(i)                                   (0x78U + ((i) * (0x4U)))

/* Group_definition register set is the SW user entry to define groups mapping
 * and routing into and through event engine: -throw group into synchronous or
 * asynchronous list -pick descriptors from non deterministic or deterministic
 * memory -start address of descriptors when belonging to a deterministic
 * group. */
#define CSL_VDMA_GROUP_DEFINITION(i)                            (0xF8U + ((i) * (0x4U)))

/* Non deterministic descriptor FIFO width being 128b and configuration port
 * width being 32b, four OCP write commands into four different (incremental)
 * addresses to create one (short) non deterministic descriptor. Least
 * significant 32b word of (short) descriptor shall be written at 0x178h. . .
 * Most significant 32b word of (short) descriptor shall be written at 0x184h.
 * Write command order has no importance. When a long descriptor is required,
 * four write commands (above) sequence should be repeated. Note that the
 * first four write command sequence shall set the most significant 128b of
 * the 256b descriptor to respect the requirement of pushing the 128b part
 * containing the descriptor header field first. */
#define CSL_VDMA_NON_DETERM(i)                                  (0x178U + ((i) * (0x4U)))

/* TRIGGER_CTR */
#define CSL_VDMA_TRIGGER_CTR(i)                                 (0x800U + ((i) * (0x4U)))

/* 32b word positionned at bit 127 to 96 in deterministic memory 128b word
 * entry of most significant 128b word of 256b descriptor */
#define CSL_VDMA_H_DETERM_127_96(n)                             (0x101CU + ((n) * (0x20U)))

/* 32b word positionned at bit 95 to 64 in deterministic memory 128b word
 * entry of most significant 128b word of 256b descriptor */
#define CSL_VDMA_H_DETERM_95_64(n)                              (0x1018U + ((n) * (0x20U)))

/* 32b word positionned at bits [63..32] in deterministic memory 128b word
 * entry of most significant 128b word of 256b descriptor */
#define CSL_VDMA_H_DETERM_63_32(n)                              (0x1014U + ((n) * (0x20U)))

/* Least significant 32b word of deterministic memory 128b word entry of most
 * significant 128b word of 256b descriptor */
#define CSL_VDMA_H_DETERM_31_0(n)                               (0x1010U + ((n) * (0x20U)))

/* 32b word positionned at bit 127 to 96 in deterministic memory 128b word
 * entry of least significant 128b word of 256b descriptor */
#define CSL_VDMA_L_DETERM_127_96(n)                             (0x100CU + ((n) * (0x20U)))

/* 32b word positionned at bit 95 to 64 in deterministic memory 128b word
 * entry of least significant 128b word of 256b descriptor */
#define CSL_VDMA_L_DETERM_95_64(n)                              (0x1008U + ((n) * (0x20U)))

/* 32b word positionned at bits [63..32] in deterministic memory 128b word
 * entry of least significant 128b word of 256b descriptor */
#define CSL_VDMA_L_DETERM_63_32(n)                              (0x1004U + ((n) * (0x20U)))

/* Least significant 32b word of deterministic memory 128b word entry of least
 * significant 128b word of 256b descriptor */
#define CSL_VDMA_L_DETERM_31_0(n)                               (0x1000U + ((n) * (0x20U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_VDMA_REVISION_MINOR_MASK                            (0x0000003FU)
#define CSL_VDMA_REVISION_MINOR_SHIFT                           (0U)
#define CSL_VDMA_REVISION_MINOR_RESETVAL                        (0x00000000U)
#define CSL_VDMA_REVISION_MINOR_MAX                             (0x0000003fU)

#define CSL_VDMA_REVISION_CUSTOM_MASK                           (0x000000C0U)
#define CSL_VDMA_REVISION_CUSTOM_SHIFT                          (6U)
#define CSL_VDMA_REVISION_CUSTOM_RESETVAL                       (0x00000000U)
#define CSL_VDMA_REVISION_CUSTOM_MAX                            (0x00000003U)

#define CSL_VDMA_REVISION_MAJOR_MASK                            (0x00000700U)
#define CSL_VDMA_REVISION_MAJOR_SHIFT                           (8U)
#define CSL_VDMA_REVISION_MAJOR_RESETVAL                        (0x00000000U)
#define CSL_VDMA_REVISION_MAJOR_MAX                             (0x00000007U)

#define CSL_VDMA_REVISION_RTL_MASK                              (0x0000F800U)
#define CSL_VDMA_REVISION_RTL_SHIFT                             (11U)
#define CSL_VDMA_REVISION_RTL_RESETVAL                          (0x00000000U)
#define CSL_VDMA_REVISION_RTL_MAX                               (0x0000001fU)

#define CSL_VDMA_REVISION_FUNC_MASK                             (0x0FFF0000U)
#define CSL_VDMA_REVISION_FUNC_SHIFT                            (16U)
#define CSL_VDMA_REVISION_FUNC_RESETVAL                         (0x00000000U)
#define CSL_VDMA_REVISION_FUNC_MAX                              (0x00000fffU)

#define CSL_VDMA_REVISION_SCHEME_MASK                           (0xC0000000U)
#define CSL_VDMA_REVISION_SCHEME_SHIFT                          (30U)
#define CSL_VDMA_REVISION_SCHEME_RESETVAL                       (0x00000001U)
#define CSL_VDMA_REVISION_SCHEME_MAX                            (0x00000003U)

#define CSL_VDMA_REVISION_RESETVAL                              (0x40000000U)

/* SYSCONFIG */

#define CSL_VDMA_SYSCONFIG_SOFTRESET_MASK                       (0x00000001U)
#define CSL_VDMA_SYSCONFIG_SOFTRESET_SHIFT                      (0U)
#define CSL_VDMA_SYSCONFIG_SOFTRESET_RESETVAL                   (0x00000000U)
#define CSL_VDMA_SYSCONFIG_SOFTRESET_MAX                        (0x00000001U)

#define CSL_VDMA_SYSCONFIG_IDLEMODE_MASK                        (0x0000000CU)
#define CSL_VDMA_SYSCONFIG_IDLEMODE_SHIFT                       (2U)
#define CSL_VDMA_SYSCONFIG_IDLEMODE_RESETVAL                    (0x00000002U)
#define CSL_VDMA_SYSCONFIG_IDLEMODE__0X0                        (0x00000000U)
#define CSL_VDMA_SYSCONFIG_IDLEMODE__0X1                        (0x00000001U)
#define CSL_VDMA_SYSCONFIG_IDLEMODE__0X2                        (0x00000002U)
#define CSL_VDMA_SYSCONFIG_IDLEMODE__0X3                        (0x00000003U)

#define CSL_VDMA_SYSCONFIG_STANDBYMODE_MASK                     (0x00000030U)
#define CSL_VDMA_SYSCONFIG_STANDBYMODE_SHIFT                    (4U)
#define CSL_VDMA_SYSCONFIG_STANDBYMODE_RESETVAL                 (0x00000002U)
#define CSL_VDMA_SYSCONFIG_STANDBYMODE__0X0                     (0x00000000U)
#define CSL_VDMA_SYSCONFIG_STANDBYMODE__0X1                     (0x00000001U)
#define CSL_VDMA_SYSCONFIG_STANDBYMODE__0X2                     (0x00000002U)
#define CSL_VDMA_SYSCONFIG_STANDBYMODE__0X3                     (0x00000003U)

#define CSL_VDMA_SYSCONFIG_RESETVAL                             (0x00000028U)

/* IRQ_EOI */

#define CSL_VDMA_IRQ_EOI_LINE_NUMBER_MASK                       (0x000000FFU)
#define CSL_VDMA_IRQ_EOI_LINE_NUMBER_SHIFT                      (0U)
#define CSL_VDMA_IRQ_EOI_LINE_NUMBER_RESETVAL                   (0x00000000U)
#define CSL_VDMA_IRQ_EOI_LINE_NUMBER_MAX                        (0x000000ffU)

#define CSL_VDMA_IRQ_EOI_RESETVAL                               (0x00000000U)

/* IRQSTS_RAW_0 */

#define CSL_VDMA_IRQSTS_RAW_0_ICONT1_END_GROUP31_0_MASK         (0xFFFFFFFFU)
#define CSL_VDMA_IRQSTS_RAW_0_ICONT1_END_GROUP31_0_SHIFT        (0U)
#define CSL_VDMA_IRQSTS_RAW_0_ICONT1_END_GROUP31_0_RESETVAL     (0x00000000U)
#define CSL_VDMA_IRQSTS_RAW_0_ICONT1_END_GROUP31_0_MAX          (0xffffffffU)

#define CSL_VDMA_IRQSTS_RAW_0_RESETVAL                          (0x00000000U)

/* IRQSTS_0 */

#define CSL_VDMA_IRQSTS_0_ICONT1_END_GROUP31_0_MASK             (0xFFFFFFFFU)
#define CSL_VDMA_IRQSTS_0_ICONT1_END_GROUP31_0_SHIFT            (0U)
#define CSL_VDMA_IRQSTS_0_ICONT1_END_GROUP31_0_RESETVAL         (0x00000000U)
#define CSL_VDMA_IRQSTS_0_ICONT1_END_GROUP31_0_MAX              (0xffffffffU)

#define CSL_VDMA_IRQSTS_0_RESETVAL                              (0x00000000U)

/* IRQEN_SET_0 */

#define CSL_VDMA_IRQEN_SET_0_EN_SET_ICONT1_GROUP31_0_MASK       (0xFFFFFFFFU)
#define CSL_VDMA_IRQEN_SET_0_EN_SET_ICONT1_GROUP31_0_SHIFT      (0U)
#define CSL_VDMA_IRQEN_SET_0_EN_SET_ICONT1_GROUP31_0_RESETVAL   (0x00000000U)
#define CSL_VDMA_IRQEN_SET_0_EN_SET_ICONT1_GROUP31_0_MAX        (0xffffffffU)

#define CSL_VDMA_IRQEN_SET_0_RESETVAL                           (0x00000000U)

/* IRQEN_CLR_0 */

#define CSL_VDMA_IRQEN_CLR_0_EN_CLR_ICONT1_GROUP31_0_MASK       (0xFFFFFFFFU)
#define CSL_VDMA_IRQEN_CLR_0_EN_CLR_ICONT1_GROUP31_0_SHIFT      (0U)
#define CSL_VDMA_IRQEN_CLR_0_EN_CLR_ICONT1_GROUP31_0_RESETVAL   (0x00000000U)
#define CSL_VDMA_IRQEN_CLR_0_EN_CLR_ICONT1_GROUP31_0_MAX        (0xffffffffU)

#define CSL_VDMA_IRQEN_CLR_0_RESETVAL                           (0x00000000U)

/* IRQSTS_RAW_1 */

#define CSL_VDMA_IRQSTS_RAW_1_ICONT2_END_GROUP31_0_MASK         (0xFFFFFFFFU)
#define CSL_VDMA_IRQSTS_RAW_1_ICONT2_END_GROUP31_0_SHIFT        (0U)
#define CSL_VDMA_IRQSTS_RAW_1_ICONT2_END_GROUP31_0_RESETVAL     (0x00000000U)
#define CSL_VDMA_IRQSTS_RAW_1_ICONT2_END_GROUP31_0_MAX          (0xffffffffU)

#define CSL_VDMA_IRQSTS_RAW_1_RESETVAL                          (0x00000000U)

/* IRQSTS_1 */

#define CSL_VDMA_IRQSTS_1_ICONT2_END_GROUP31_0_MASK             (0xFFFFFFFFU)
#define CSL_VDMA_IRQSTS_1_ICONT2_END_GROUP31_0_SHIFT            (0U)
#define CSL_VDMA_IRQSTS_1_ICONT2_END_GROUP31_0_RESETVAL         (0x00000000U)
#define CSL_VDMA_IRQSTS_1_ICONT2_END_GROUP31_0_MAX              (0xffffffffU)

#define CSL_VDMA_IRQSTS_1_RESETVAL                              (0x00000000U)

/* IRQEN_SET_1 */

#define CSL_VDMA_IRQEN_SET_1_EN_SET_ICONT2_GROUP31_0_MASK       (0xFFFFFFFFU)
#define CSL_VDMA_IRQEN_SET_1_EN_SET_ICONT2_GROUP31_0_SHIFT      (0U)
#define CSL_VDMA_IRQEN_SET_1_EN_SET_ICONT2_GROUP31_0_RESETVAL   (0x00000000U)
#define CSL_VDMA_IRQEN_SET_1_EN_SET_ICONT2_GROUP31_0_MAX        (0xffffffffU)

#define CSL_VDMA_IRQEN_SET_1_RESETVAL                           (0x00000000U)

/* IRQEN_CLR_1 */

#define CSL_VDMA_IRQEN_CLR_1_EN_CLR_ICONT2_GROUP31_0_MASK       (0xFFFFFFFFU)
#define CSL_VDMA_IRQEN_CLR_1_EN_CLR_ICONT2_GROUP31_0_SHIFT      (0U)
#define CSL_VDMA_IRQEN_CLR_1_EN_CLR_ICONT2_GROUP31_0_RESETVAL   (0x00000000U)
#define CSL_VDMA_IRQEN_CLR_1_EN_CLR_ICONT2_GROUP31_0_MAX        (0xffffffffU)

#define CSL_VDMA_IRQEN_CLR_1_RESETVAL                           (0x00000000U)

/* IRQSTS_RAW_2 */

#define CSL_VDMA_IRQSTS_RAW_2_COHERENCY_ERROR_MASK              (0x00000001U)
#define CSL_VDMA_IRQSTS_RAW_2_COHERENCY_ERROR_SHIFT             (0U)
#define CSL_VDMA_IRQSTS_RAW_2_COHERENCY_ERROR_RESETVAL          (0x00000000U)
#define CSL_VDMA_IRQSTS_RAW_2_COHERENCY_ERROR_MAX               (0x00000001U)

#define CSL_VDMA_IRQSTS_RAW_2_TRIGGER_TWICE_MASK                (0x00000002U)
#define CSL_VDMA_IRQSTS_RAW_2_TRIGGER_TWICE_SHIFT               (1U)
#define CSL_VDMA_IRQSTS_RAW_2_TRIGGER_TWICE_RESETVAL            (0x00000000U)
#define CSL_VDMA_IRQSTS_RAW_2_TRIGGER_TWICE_MAX                 (0x00000001U)

#define CSL_VDMA_IRQSTS_RAW_2_DIR_INTERLEAVE_MASK               (0x00000004U)
#define CSL_VDMA_IRQSTS_RAW_2_DIR_INTERLEAVE_SHIFT              (2U)
#define CSL_VDMA_IRQSTS_RAW_2_DIR_INTERLEAVE_RESETVAL           (0x00000000U)
#define CSL_VDMA_IRQSTS_RAW_2_DIR_INTERLEAVE_MAX                (0x00000001U)

#define CSL_VDMA_IRQSTS_RAW_2_MASTER_SRESPERR_MASK              (0x00000008U)
#define CSL_VDMA_IRQSTS_RAW_2_MASTER_SRESPERR_SHIFT             (3U)
#define CSL_VDMA_IRQSTS_RAW_2_MASTER_SRESPERR_RESETVAL          (0x00000000U)
#define CSL_VDMA_IRQSTS_RAW_2_MASTER_SRESPERR_MAX               (0x00000001U)

#define CSL_VDMA_IRQSTS_RAW_2_RESETVAL                          (0x00000000U)

/* IRQSTS_2 */

#define CSL_VDMA_IRQSTS_2_COHERENCY_ERROR_MASK                  (0x00000001U)
#define CSL_VDMA_IRQSTS_2_COHERENCY_ERROR_SHIFT                 (0U)
#define CSL_VDMA_IRQSTS_2_COHERENCY_ERROR_RESETVAL              (0x00000000U)
#define CSL_VDMA_IRQSTS_2_COHERENCY_ERROR_MAX                   (0x00000001U)

#define CSL_VDMA_IRQSTS_2_TRIGGER_TWICE_MASK                    (0x00000002U)
#define CSL_VDMA_IRQSTS_2_TRIGGER_TWICE_SHIFT                   (1U)
#define CSL_VDMA_IRQSTS_2_TRIGGER_TWICE_RESETVAL                (0x00000000U)
#define CSL_VDMA_IRQSTS_2_TRIGGER_TWICE_MAX                     (0x00000001U)

#define CSL_VDMA_IRQSTS_2_DIR_INTERLEAVE_MASK                   (0x00000004U)
#define CSL_VDMA_IRQSTS_2_DIR_INTERLEAVE_SHIFT                  (2U)
#define CSL_VDMA_IRQSTS_2_DIR_INTERLEAVE_RESETVAL               (0x00000000U)
#define CSL_VDMA_IRQSTS_2_DIR_INTERLEAVE_MAX                    (0x00000001U)

#define CSL_VDMA_IRQSTS_2_MASTER_SRESPERR_MASK                  (0x00000008U)
#define CSL_VDMA_IRQSTS_2_MASTER_SRESPERR_SHIFT                 (3U)
#define CSL_VDMA_IRQSTS_2_MASTER_SRESPERR_RESETVAL              (0x00000000U)
#define CSL_VDMA_IRQSTS_2_MASTER_SRESPERR_MAX                   (0x00000001U)

#define CSL_VDMA_IRQSTS_2_RESETVAL                              (0x00000000U)

/* IRQEN_SET_2 */

#define CSL_VDMA_IRQEN_SET_2_COHERENCY_ERROR_MASK               (0x00000001U)
#define CSL_VDMA_IRQEN_SET_2_COHERENCY_ERROR_SHIFT              (0U)
#define CSL_VDMA_IRQEN_SET_2_COHERENCY_ERROR_RESETVAL           (0x00000000U)
#define CSL_VDMA_IRQEN_SET_2_COHERENCY_ERROR_MAX                (0x00000001U)

#define CSL_VDMA_IRQEN_SET_2_TRIGGER_TWICE_MASK                 (0x00000002U)
#define CSL_VDMA_IRQEN_SET_2_TRIGGER_TWICE_SHIFT                (1U)
#define CSL_VDMA_IRQEN_SET_2_TRIGGER_TWICE_RESETVAL             (0x00000000U)
#define CSL_VDMA_IRQEN_SET_2_TRIGGER_TWICE_MAX                  (0x00000001U)

#define CSL_VDMA_IRQEN_SET_2_DIR_INTERLEAVE_MASK                (0x00000004U)
#define CSL_VDMA_IRQEN_SET_2_DIR_INTERLEAVE_SHIFT               (2U)
#define CSL_VDMA_IRQEN_SET_2_DIR_INTERLEAVE_RESETVAL            (0x00000000U)
#define CSL_VDMA_IRQEN_SET_2_DIR_INTERLEAVE_MAX                 (0x00000001U)

#define CSL_VDMA_IRQEN_SET_2_MASTER_SRESPERR_MASK               (0x00000008U)
#define CSL_VDMA_IRQEN_SET_2_MASTER_SRESPERR_SHIFT              (3U)
#define CSL_VDMA_IRQEN_SET_2_MASTER_SRESPERR_RESETVAL           (0x00000000U)
#define CSL_VDMA_IRQEN_SET_2_MASTER_SRESPERR_MAX                (0x00000001U)

#define CSL_VDMA_IRQEN_SET_2_RESETVAL                           (0x00000000U)

/* IRQEN_CLR_2 */

#define CSL_VDMA_IRQEN_CLR_2_COHERENCY_ERROR_MASK               (0x00000001U)
#define CSL_VDMA_IRQEN_CLR_2_COHERENCY_ERROR_SHIFT              (0U)
#define CSL_VDMA_IRQEN_CLR_2_COHERENCY_ERROR_RESETVAL           (0x00000000U)
#define CSL_VDMA_IRQEN_CLR_2_COHERENCY_ERROR_MAX                (0x00000001U)

#define CSL_VDMA_IRQEN_CLR_2_TRIGGER_TWICE_MASK                 (0x00000002U)
#define CSL_VDMA_IRQEN_CLR_2_TRIGGER_TWICE_SHIFT                (1U)
#define CSL_VDMA_IRQEN_CLR_2_TRIGGER_TWICE_RESETVAL             (0x00000000U)
#define CSL_VDMA_IRQEN_CLR_2_TRIGGER_TWICE_MAX                  (0x00000001U)

#define CSL_VDMA_IRQEN_CLR_2_DIR_INTERLEAVE_MASK                (0x00000004U)
#define CSL_VDMA_IRQEN_CLR_2_DIR_INTERLEAVE_SHIFT               (2U)
#define CSL_VDMA_IRQEN_CLR_2_DIR_INTERLEAVE_RESETVAL            (0x00000000U)
#define CSL_VDMA_IRQEN_CLR_2_DIR_INTERLEAVE_MAX                 (0x00000001U)

#define CSL_VDMA_IRQEN_CLR_2_MASTER_SRESPERR_MASK               (0x00000008U)
#define CSL_VDMA_IRQEN_CLR_2_MASTER_SRESPERR_SHIFT              (3U)
#define CSL_VDMA_IRQEN_CLR_2_MASTER_SRESPERR_RESETVAL           (0x00000000U)
#define CSL_VDMA_IRQEN_CLR_2_MASTER_SRESPERR_MAX                (0x00000001U)

#define CSL_VDMA_IRQEN_CLR_2_RESETVAL                           (0x00000000U)

/* SYNCHR_LIST_LEVEL */

#define CSL_VDMA_SYNCHR_LIST_LEVEL_LEVEL_MASK                   (0x0000000FU)
#define CSL_VDMA_SYNCHR_LIST_LEVEL_LEVEL_SHIFT                  (0U)
#define CSL_VDMA_SYNCHR_LIST_LEVEL_LEVEL_RESETVAL               (0x00000000U)
#define CSL_VDMA_SYNCHR_LIST_LEVEL_LEVEL_MAX                    (0x0000000fU)

#define CSL_VDMA_SYNCHR_LIST_LEVEL_RESETVAL                     (0x00000000U)

/* ASYNCHR_LIST_LEVEL */

#define CSL_VDMA_ASYNCHR_LIST_LEVEL_LEVEL_MASK                  (0x0000000FU)
#define CSL_VDMA_ASYNCHR_LIST_LEVEL_LEVEL_SHIFT                 (0U)
#define CSL_VDMA_ASYNCHR_LIST_LEVEL_LEVEL_RESETVAL              (0x00000000U)
#define CSL_VDMA_ASYNCHR_LIST_LEVEL_LEVEL_MAX                   (0x0000000fU)

#define CSL_VDMA_ASYNCHR_LIST_LEVEL_RESETVAL                    (0x00000000U)

/* NON_DETERM_FIFO_LEVEL */

#define CSL_VDMA_NON_DETERM_FIFO_LEVEL_LEVEL_MASK               (0x000000FFU)
#define CSL_VDMA_NON_DETERM_FIFO_LEVEL_LEVEL_SHIFT              (0U)
#define CSL_VDMA_NON_DETERM_FIFO_LEVEL_LEVEL_RESETVAL           (0x00000000U)
#define CSL_VDMA_NON_DETERM_FIFO_LEVEL_LEVEL_MAX                (0x000000ffU)

#define CSL_VDMA_NON_DETERM_FIFO_LEVEL_RESETVAL                 (0x00000000U)

/* TBA */

#define CSL_VDMA_TBA_OCP_3MSB_MASK                              (0x00000007U)
#define CSL_VDMA_TBA_OCP_3MSB_SHIFT                             (0U)
#define CSL_VDMA_TBA_OCP_3MSB_RESETVAL                          (0x00000000U)
#define CSL_VDMA_TBA_OCP_3MSB_MAX                               (0x00000007U)

#define CSL_VDMA_TBA_RESETVAL                                   (0x00000000U)

/* CONTEXT_STS */

#define CSL_VDMA_CONTEXT_STS_CONTEXT0_MASK                      (0x00000001U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT0_SHIFT                     (0U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT0_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT0_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT1_MASK                      (0x00000002U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT1_SHIFT                     (1U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT1_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT1_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT2_MASK                      (0x00000004U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT2_SHIFT                     (2U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT2_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT2_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT3_MASK                      (0x00000008U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT3_SHIFT                     (3U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT3_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT3_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT4_MASK                      (0x00000010U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT4_SHIFT                     (4U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT4_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT4_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT5_MASK                      (0x00000020U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT5_SHIFT                     (5U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT5_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT5_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT6_MASK                      (0x00000040U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT6_SHIFT                     (6U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT6_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT6_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT7_MASK                      (0x00000080U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT7_SHIFT                     (7U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT7_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT7_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT8_MASK                      (0x00000100U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT8_SHIFT                     (8U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT8_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT8_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT9_MASK                      (0x00000200U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT9_SHIFT                     (9U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT9_RESETVAL                  (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT9_MAX                       (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT10_MASK                     (0x00000400U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT10_SHIFT                    (10U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT10_RESETVAL                 (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT10_MAX                      (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT11_MASK                     (0x00000800U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT11_SHIFT                    (11U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT11_RESETVAL                 (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT11_MAX                      (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT12_MASK                     (0x00001000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT12_SHIFT                    (12U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT12_RESETVAL                 (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT12_MAX                      (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT13_MASK                     (0x00002000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT13_SHIFT                    (13U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT13_RESETVAL                 (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT13_MAX                      (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT14_MASK                     (0x00004000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT14_SHIFT                    (14U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT14_RESETVAL                 (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT14_MAX                      (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_CONTEXT15_MASK                     (0x00008000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT15_SHIFT                    (15U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT15_RESETVAL                 (0x00000000U)
#define CSL_VDMA_CONTEXT_STS_CONTEXT15_MAX                      (0x00000001U)

#define CSL_VDMA_CONTEXT_STS_RESETVAL                           (0x00000000U)

/* GROUP_TRIGGER */

#define CSL_VDMA_GROUP_TRIGGER_CPU_TRIGGER_GROUP0_31_MASK       (0xFFFFFFFFU)
#define CSL_VDMA_GROUP_TRIGGER_CPU_TRIGGER_GROUP0_31_SHIFT      (0U)
#define CSL_VDMA_GROUP_TRIGGER_CPU_TRIGGER_GROUP0_31_RESETVAL   (0x00000000U)
#define CSL_VDMA_GROUP_TRIGGER_CPU_TRIGGER_GROUP0_31_MAX        (0xffffffffU)

#define CSL_VDMA_GROUP_TRIGGER_RESETVAL                         (0x00000000U)

/* MAX_CONTEXT_SYNCHR */

#define CSL_VDMA_MAX_CONTEXT_SYNCHR_MAX_VALUE_MASK              (0x0000000FU)
#define CSL_VDMA_MAX_CONTEXT_SYNCHR_MAX_VALUE_SHIFT             (0U)
#define CSL_VDMA_MAX_CONTEXT_SYNCHR_MAX_VALUE_RESETVAL          (0x0000000fU)
#define CSL_VDMA_MAX_CONTEXT_SYNCHR_MAX_VALUE_MAX               (0x0000000fU)

#define CSL_VDMA_MAX_CONTEXT_SYNCHR_RESETVAL                    (0x0000000fU)

/* MAX_CONTEXT_ASYNCHR */

#define CSL_VDMA_MAX_CONTEXT_ASYNCHR_MAX_VALUE_MASK             (0x0000000FU)
#define CSL_VDMA_MAX_CONTEXT_ASYNCHR_MAX_VALUE_SHIFT            (0U)
#define CSL_VDMA_MAX_CONTEXT_ASYNCHR_MAX_VALUE_RESETVAL         (0x00000000U)
#define CSL_VDMA_MAX_CONTEXT_ASYNCHR_MAX_VALUE_MAX              (0x0000000fU)

#define CSL_VDMA_MAX_CONTEXT_ASYNCHR_RESETVAL                   (0x00000000U)

/* IRQ_NEOG */

#define CSL_VDMA_IRQ_NEOG_IRQ_NEOG_GROUP31_0_MASK               (0xFFFFFFFFU)
#define CSL_VDMA_IRQ_NEOG_IRQ_NEOG_GROUP31_0_SHIFT              (0U)
#define CSL_VDMA_IRQ_NEOG_IRQ_NEOG_GROUP31_0_RESETVAL           (0x00000000U)
#define CSL_VDMA_IRQ_NEOG_IRQ_NEOG_GROUP31_0_MAX                (0xffffffffU)

#define CSL_VDMA_IRQ_NEOG_RESETVAL                              (0x00000000U)

/* GROUP_STS */

#define CSL_VDMA_GROUP_STS_SERVICING_CONTEXTS_MASK              (0x0000001FU)
#define CSL_VDMA_GROUP_STS_SERVICING_CONTEXTS_SHIFT             (0U)
#define CSL_VDMA_GROUP_STS_SERVICING_CONTEXTS_RESETVAL          (0x00000000U)
#define CSL_VDMA_GROUP_STS_SERVICING_CONTEXTS_MAX               (0x0000001fU)

#define CSL_VDMA_GROUP_STS_PENDING_DATA_PROCESSING_MASK         (0x000003E0U)
#define CSL_VDMA_GROUP_STS_PENDING_DATA_PROCESSING_SHIFT        (5U)
#define CSL_VDMA_GROUP_STS_PENDING_DATA_PROCESSING_RESETVAL     (0x00000000U)
#define CSL_VDMA_GROUP_STS_PENDING_DATA_PROCESSING_MAX          (0x0000001fU)

#define CSL_VDMA_GROUP_STS_FIRST_MASK                           (0x00000400U)
#define CSL_VDMA_GROUP_STS_FIRST_SHIFT                          (10U)
#define CSL_VDMA_GROUP_STS_FIRST_RESETVAL                       (0x00000000U)
#define CSL_VDMA_GROUP_STS_FIRST_MAX                            (0x00000001U)

#define CSL_VDMA_GROUP_STS_LAST_MASK                            (0x00000800U)
#define CSL_VDMA_GROUP_STS_LAST_SHIFT                           (11U)
#define CSL_VDMA_GROUP_STS_LAST_RESETVAL                        (0x00000000U)
#define CSL_VDMA_GROUP_STS_LAST_MAX                             (0x00000001U)

#define CSL_VDMA_GROUP_STS_RESETVAL                             (0x00000000U)

/* GROUP_DEFINITION */

#define CSL_VDMA_GROUP_DEFINITION_ASYNCHR_SYNCHR_MASK           (0x00001000U)
#define CSL_VDMA_GROUP_DEFINITION_ASYNCHR_SYNCHR_SHIFT          (12U)
#define CSL_VDMA_GROUP_DEFINITION_ASYNCHR_SYNCHR_RESETVAL       (0x00000000U)
#define CSL_VDMA_GROUP_DEFINITION_ASYNCHR_SYNCHR_MAX            (0x00000001U)

#define CSL_VDMA_GROUP_DEFINITION_NON_DETERM_MASK               (0x00002000U)
#define CSL_VDMA_GROUP_DEFINITION_NON_DETERM_SHIFT              (13U)
#define CSL_VDMA_GROUP_DEFINITION_NON_DETERM_RESETVAL           (0x00000000U)
#define CSL_VDMA_GROUP_DEFINITION_NON_DETERM_MAX                (0x00000001U)

#define CSL_VDMA_GROUP_DEFINITION_START_ADDR_MASK               (0x00000FFFU)
#define CSL_VDMA_GROUP_DEFINITION_START_ADDR_SHIFT              (0U)
#define CSL_VDMA_GROUP_DEFINITION_START_ADDR_RESETVAL           (0x00000000U)
#define CSL_VDMA_GROUP_DEFINITION_START_ADDR_MAX                (0x00000fffU)

#define CSL_VDMA_GROUP_DEFINITION_RESETVAL                      (0x00000000U)

/* NON_DETERM */

#define CSL_VDMA_NON_DETERM_ONE_OUT_OF_FOUR_32B_WORD_MASK       (0xFFFFFFFFU)
#define CSL_VDMA_NON_DETERM_ONE_OUT_OF_FOUR_32B_WORD_SHIFT      (0U)
#define CSL_VDMA_NON_DETERM_ONE_OUT_OF_FOUR_32B_WORD_RESETVAL   (0x00000000U)
#define CSL_VDMA_NON_DETERM_ONE_OUT_OF_FOUR_32B_WORD_MAX        (0xffffffffU)

#define CSL_VDMA_NON_DETERM_RESETVAL                            (0x00000000U)

/* TRIGGER_CTR */

#define CSL_VDMA_TRIGGER_CTR_SOURCE_MASK                        (0x000000FFU)
#define CSL_VDMA_TRIGGER_CTR_SOURCE_SHIFT                       (0U)
#define CSL_VDMA_TRIGGER_CTR_SOURCE_RESETVAL                    (0x00000000U)
#define CSL_VDMA_TRIGGER_CTR_SOURCE_MAX                         (0x000000ffU)

#define CSL_VDMA_TRIGGER_CTR_DESTINATION_MASK                   (0x0000FF00U)
#define CSL_VDMA_TRIGGER_CTR_DESTINATION_SHIFT                  (8U)
#define CSL_VDMA_TRIGGER_CTR_DESTINATION_RESETVAL               (0x00000000U)
#define CSL_VDMA_TRIGGER_CTR_DESTINATION_MAX                    (0x000000ffU)

#define CSL_VDMA_TRIGGER_CTR_RESETVAL                           (0x00000000U)

/* H_DETERM_127_96 */

#define CSL_VDMA_H_DETERM_127_96_DESCRIPTOR_BITS_255_TO_224_MASK  (0xFFFFFFFFU)
#define CSL_VDMA_H_DETERM_127_96_DESCRIPTOR_BITS_255_TO_224_SHIFT  (0U)
#define CSL_VDMA_H_DETERM_127_96_DESCRIPTOR_BITS_255_TO_224_RESETVAL  (0x00000000U)
#define CSL_VDMA_H_DETERM_127_96_DESCRIPTOR_BITS_255_TO_224_MAX  (0xffffffffU)

#define CSL_VDMA_H_DETERM_127_96_RESETVAL                       (0x00000000U)

/* H_DETERM_95_64 */

#define CSL_VDMA_H_DETERM_95_64_DESCRIPTOR_BITS_223_TO_192_MASK  (0xFFFFFFFFU)
#define CSL_VDMA_H_DETERM_95_64_DESCRIPTOR_BITS_223_TO_192_SHIFT  (0U)
#define CSL_VDMA_H_DETERM_95_64_DESCRIPTOR_BITS_223_TO_192_RESETVAL  (0x00000000U)
#define CSL_VDMA_H_DETERM_95_64_DESCRIPTOR_BITS_223_TO_192_MAX  (0xffffffffU)

#define CSL_VDMA_H_DETERM_95_64_RESETVAL                        (0x00000000U)

/* H_DETERM_63_32 */

#define CSL_VDMA_H_DETERM_63_32_DESCRIPTOR_BITS_191_TO_160_MASK  (0xFFFFFFFFU)
#define CSL_VDMA_H_DETERM_63_32_DESCRIPTOR_BITS_191_TO_160_SHIFT  (0U)
#define CSL_VDMA_H_DETERM_63_32_DESCRIPTOR_BITS_191_TO_160_RESETVAL  (0x00000000U)
#define CSL_VDMA_H_DETERM_63_32_DESCRIPTOR_BITS_191_TO_160_MAX  (0xffffffffU)

#define CSL_VDMA_H_DETERM_63_32_RESETVAL                        (0x00000000U)

/* H_DETERM_31_0 */

#define CSL_VDMA_H_DETERM_31_0_DESCRIPTOR_BITS_159_TO_128_MASK  (0xFFFFFFFFU)
#define CSL_VDMA_H_DETERM_31_0_DESCRIPTOR_BITS_159_TO_128_SHIFT  (0U)
#define CSL_VDMA_H_DETERM_31_0_DESCRIPTOR_BITS_159_TO_128_RESETVAL  (0x00000000U)
#define CSL_VDMA_H_DETERM_31_0_DESCRIPTOR_BITS_159_TO_128_MAX   (0xffffffffU)

#define CSL_VDMA_H_DETERM_31_0_RESETVAL                         (0x00000000U)

/* L_DETERM_127_96 */

#define CSL_VDMA_L_DETERM_127_96_DESCRIPTOR_BITS_127_TO_96_MASK  (0xFFFFFFFFU)
#define CSL_VDMA_L_DETERM_127_96_DESCRIPTOR_BITS_127_TO_96_SHIFT  (0U)
#define CSL_VDMA_L_DETERM_127_96_DESCRIPTOR_BITS_127_TO_96_RESETVAL  (0x00000000U)
#define CSL_VDMA_L_DETERM_127_96_DESCRIPTOR_BITS_127_TO_96_MAX  (0xffffffffU)

#define CSL_VDMA_L_DETERM_127_96_RESETVAL                       (0x00000000U)

/* L_DETERM_95_64 */

#define CSL_VDMA_L_DETERM_95_64_DESCRIPTOR_BITS_95_TO_64_MASK   (0xFFFFFFFFU)
#define CSL_VDMA_L_DETERM_95_64_DESCRIPTOR_BITS_95_TO_64_SHIFT  (0U)
#define CSL_VDMA_L_DETERM_95_64_DESCRIPTOR_BITS_95_TO_64_RESETVAL  (0x00000000U)
#define CSL_VDMA_L_DETERM_95_64_DESCRIPTOR_BITS_95_TO_64_MAX    (0xffffffffU)

#define CSL_VDMA_L_DETERM_95_64_RESETVAL                        (0x00000000U)

/* L_DETERM_63_32 */

#define CSL_VDMA_L_DETERM_63_32_DESCRIPTOR_BITS_63_TO_32_MASK   (0xFFFFFFFFU)
#define CSL_VDMA_L_DETERM_63_32_DESCRIPTOR_BITS_63_TO_32_SHIFT  (0U)
#define CSL_VDMA_L_DETERM_63_32_DESCRIPTOR_BITS_63_TO_32_RESETVAL  (0x00000000U)
#define CSL_VDMA_L_DETERM_63_32_DESCRIPTOR_BITS_63_TO_32_MAX    (0xffffffffU)

#define CSL_VDMA_L_DETERM_63_32_RESETVAL                        (0x00000000U)

/* L_DETERM_31_0 */

#define CSL_VDMA_L_DETERM_31_0_DESCRIPTOR_BITS_31_TO_0_MASK     (0xFFFFFFFFU)
#define CSL_VDMA_L_DETERM_31_0_DESCRIPTOR_BITS_31_TO_0_SHIFT    (0U)
#define CSL_VDMA_L_DETERM_31_0_DESCRIPTOR_BITS_31_TO_0_RESETVAL  (0x00000000U)
#define CSL_VDMA_L_DETERM_31_0_DESCRIPTOR_BITS_31_TO_0_MAX      (0xffffffffU)

#define CSL_VDMA_L_DETERM_31_0_RESETVAL                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
