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
#ifndef CSLR_IVASYS_H_
#define CSLR_IVASYS_H_

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
    volatile Uint32 HWINFO;
    volatile Uint8  RSVD0[8];
    volatile Uint32 SYSCONFIG;
    volatile Uint8  RSVD1[12];
    volatile Uint32 IRQ_EOI;
    volatile Uint32 IRQSTS_RAW;
    volatile Uint32 IRQSTS;
    volatile Uint32 IRQEN_SET;
    volatile Uint32 IRQEN_CLR;
    volatile Uint32 SYNC_IRQSTS_RAW;
    volatile Uint32 SYNC_IRQSTS;
    volatile Uint32 SYNC_IRQEN_SET;
    volatile Uint32 SYNC_IRQEN_CLR;
    volatile Uint8  RSVD2[12];
    volatile Uint32 CLKCTRL;
    volatile Uint32 CLKST;
    volatile Uint32 STDBYST;
} CSL_IvaSysRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* IVA-HD Revision Identifier (X.Y.R) Used by software to track features,
 * bugs, and compatibility */
#define CSL_IVASYS_REVISION                                     (0x0U)

/* Information about the IP module's hardware configuration. */
#define CSL_IVASYS_HWINFO                                       (0x4U)

/* Clock management configuration */
#define CSL_IVASYS_SYSCONFIG                                    (0x10U)

/* End Of Interrupt number specification */
#define CSL_IVASYS_IRQ_EOI                                      (0x20U)

/* Per-event raw interrupt status vector. Raw status is set even if event is
 * not enabled. Write 1 to set the (raw) status, mostly for debug. */
#define CSL_IVASYS_IRQSTS_RAW                                   (0x24U)

/* Per-event "enabled" interrupt status vector, line #0. Enabled status isn't
 * set unless event is enabled. Write 1 to clear the status after interrupt
 * has been serviced (raw status gets cleared, i.e. even if not enabled). */
#define CSL_IVASYS_IRQSTS                                       (0x28U)

/* Per-event interrupt enable bit vector. Write 1 to set (enable interrupt).
 * Readout equal to corresponding _CLR register. */
#define CSL_IVASYS_IRQEN_SET                                    (0x2CU)

/* Per-event interrupt enable bit vector. Write 1 to clear (disable
 * interrupt). Readout equal to corresponding _SET register. */
#define CSL_IVASYS_IRQEN_CLR                                    (0x30U)

/* Per-event raw interrupt status vector. Raw status is set even if event is
 * not enabled. Write 1 to set the (raw) status, mostly for debug. */
#define CSL_IVASYS_SYNC_IRQSTS_RAW                              (0x34U)

/* Per-event "enabled" interrupt status vector, line #0. Enabled status isn't
 * set unless event is enabled. Write 1 to clear the status after interrupt
 * has been serviced (raw status gets cleared, i.e. even if not enabled). */
#define CSL_IVASYS_SYNC_IRQSTS                                  (0x38U)

/* Per-event interrupt enable bit vector. Write 1 to set (enable interrupt).
 * Readout equal to corresponding _CLR register. */
#define CSL_IVASYS_SYNC_IRQEN_SET                               (0x3CU)

/* Per-event interrupt enable bit vector. Write 1 to clear (disable
 * interrupt). Readout equal to corresponding _SET register. */
#define CSL_IVASYS_SYNC_IRQEN_CLR                               (0x40U)

/* IVAHD clock control register */
#define CSL_IVASYS_CLKCTRL                                      (0x50U)

/* IVA-HD clock status register. Each bitfield of this register is set to '0'
 * when sub-module is in idle state otherwise set to '1'. */
#define CSL_IVASYS_CLKST                                        (0x54U)

/* IVA-HD STANDBY status */
#define CSL_IVASYS_STDBYST                                      (0x58U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_IVASYS_REVISION_Y_MINOR_MASK                        (0x0000003FU)
#define CSL_IVASYS_REVISION_Y_MINOR_SHIFT                       (0U)
#define CSL_IVASYS_REVISION_Y_MINOR_RESETVAL                    (0x00000000U)
#define CSL_IVASYS_REVISION_Y_MINOR_MAX                         (0x0000003fU)

#define CSL_IVASYS_REVISION_CUSTOM_MASK                         (0x000000C0U)
#define CSL_IVASYS_REVISION_CUSTOM_SHIFT                        (6U)
#define CSL_IVASYS_REVISION_CUSTOM_RESETVAL                     (0x00000000U)
#define CSL_IVASYS_REVISION_CUSTOM_STANDARD                     (0x00000000U)

#define CSL_IVASYS_REVISION_X_MAJOR_MASK                        (0x00000700U)
#define CSL_IVASYS_REVISION_X_MAJOR_SHIFT                       (8U)
#define CSL_IVASYS_REVISION_X_MAJOR_RESETVAL                    (0x00000000U)
#define CSL_IVASYS_REVISION_X_MAJOR_MAX                         (0x00000007U)

#define CSL_IVASYS_REVISION_R_RTL_MASK                          (0x0000F800U)
#define CSL_IVASYS_REVISION_R_RTL_SHIFT                         (11U)
#define CSL_IVASYS_REVISION_R_RTL_RESETVAL                      (0x00000000U)
#define CSL_IVASYS_REVISION_R_RTL_MAX                           (0x0000001fU)

#define CSL_IVASYS_REVISION_FUNC_MASK                           (0x0FFF0000U)
#define CSL_IVASYS_REVISION_FUNC_SHIFT                          (16U)
#define CSL_IVASYS_REVISION_FUNC_RESETVAL                       (0x00000000U)
#define CSL_IVASYS_REVISION_FUNC_MAX                            (0x00000fffU)

#define CSL_IVASYS_REVISION_SCHEME_MASK                         (0xC0000000U)
#define CSL_IVASYS_REVISION_SCHEME_SHIFT                        (30U)
#define CSL_IVASYS_REVISION_SCHEME_RESETVAL                     (0x00000001U)
#define CSL_IVASYS_REVISION_SCHEME_H08                          (0x00000001U)
#define CSL_IVASYS_REVISION_SCHEME_LEGACY                       (0x00000000U)

#define CSL_IVASYS_REVISION_RESETVAL                            (0x50000000U)

/* HWINFO */

#define CSL_IVASYS_HWINFO_SL2SIZE_MASK                          (0x0000000FU)
#define CSL_IVASYS_HWINFO_SL2SIZE_SHIFT                         (0U)
#define CSL_IVASYS_HWINFO_SL2SIZE_RESETVAL                      (0x0000000aU)
#define CSL_IVASYS_HWINFO_SL2SIZE_MAX                           (0x0000000fU)

#define CSL_IVASYS_HWINFO_ICONT1_MASK                           (0x00000040U)
#define CSL_IVASYS_HWINFO_ICONT1_SHIFT                          (6U)
#define CSL_IVASYS_HWINFO_ICONT1_RESETVAL                       (0x00000001U)
#define CSL_IVASYS_HWINFO_ICONT1_MAX                            (0x00000001U)

#define CSL_IVASYS_HWINFO_IME3_MASK                             (0x00000400U)
#define CSL_IVASYS_HWINFO_IME3_SHIFT                            (10U)
#define CSL_IVASYS_HWINFO_IME3_RESETVAL                         (0x00000001U)
#define CSL_IVASYS_HWINFO_IME3_MAX                              (0x00000001U)

#define CSL_IVASYS_HWINFO_ICONT2_MASK                           (0x00000080U)
#define CSL_IVASYS_HWINFO_ICONT2_SHIFT                          (7U)
#define CSL_IVASYS_HWINFO_ICONT2_RESETVAL                       (0x00000001U)
#define CSL_IVASYS_HWINFO_ICONT2_MAX                            (0x00000001U)

#define CSL_IVASYS_HWINFO_VDMA_MASK                             (0x00000100U)
#define CSL_IVASYS_HWINFO_VDMA_SHIFT                            (8U)
#define CSL_IVASYS_HWINFO_VDMA_RESETVAL                         (0x00000001U)
#define CSL_IVASYS_HWINFO_VDMA_MAX                              (0x00000001U)

#define CSL_IVASYS_HWINFO_ILF3_MASK                             (0x00000200U)
#define CSL_IVASYS_HWINFO_ILF3_SHIFT                            (9U)
#define CSL_IVASYS_HWINFO_ILF3_RESETVAL                         (0x00000001U)
#define CSL_IVASYS_HWINFO_ILF3_MAX                              (0x00000001U)

#define CSL_IVASYS_HWINFO_CALC3_MASK                            (0x00000800U)
#define CSL_IVASYS_HWINFO_CALC3_SHIFT                           (11U)
#define CSL_IVASYS_HWINFO_CALC3_RESETVAL                        (0x00000001U)
#define CSL_IVASYS_HWINFO_CALC3_MAX                             (0x00000001U)

#define CSL_IVASYS_HWINFO_IPE3_MASK                             (0x00001000U)
#define CSL_IVASYS_HWINFO_IPE3_SHIFT                            (12U)
#define CSL_IVASYS_HWINFO_IPE3_RESETVAL                         (0x00000001U)
#define CSL_IVASYS_HWINFO_IPE3_MAX                              (0x00000001U)

#define CSL_IVASYS_HWINFO_MC3_MASK                              (0x00002000U)
#define CSL_IVASYS_HWINFO_MC3_SHIFT                             (13U)
#define CSL_IVASYS_HWINFO_MC3_RESETVAL                          (0x00000001U)
#define CSL_IVASYS_HWINFO_MC3_MAX                               (0x00000001U)

#define CSL_IVASYS_HWINFO_ECD3_MASK                             (0x00004000U)
#define CSL_IVASYS_HWINFO_ECD3_SHIFT                            (14U)
#define CSL_IVASYS_HWINFO_ECD3_RESETVAL                         (0x00000001U)
#define CSL_IVASYS_HWINFO_ECD3_MAX                              (0x00000001U)

#define CSL_IVASYS_HWINFO_SL2BANK_MASK                          (0x00000030U)
#define CSL_IVASYS_HWINFO_SL2BANK_SHIFT                         (4U)
#define CSL_IVASYS_HWINFO_SL2BANK_RESETVAL                      (0x00000003U)
#define CSL_IVASYS_HWINFO_SL2BANK__1BANK                        (0x00000000U)
#define CSL_IVASYS_HWINFO_SL2BANK__2BANK                        (0x00000001U)
#define CSL_IVASYS_HWINFO_SL2BANK__4BANK                        (0x00000002U)
#define CSL_IVASYS_HWINFO_SL2BANK__8BANK                        (0x00000003U)

#define CSL_IVASYS_HWINFO_RESETVAL                              (0x00007ffaU)

/* SYSCONFIG */

#define CSL_IVASYS_SYSCONFIG_IDLEMODE_MASK                      (0x0000000CU)
#define CSL_IVASYS_SYSCONFIG_IDLEMODE_SHIFT                     (2U)
#define CSL_IVASYS_SYSCONFIG_IDLEMODE_RESETVAL                  (0x00000002U)
#define CSL_IVASYS_SYSCONFIG_IDLEMODE_RESERVED                  (0x00000000U)
#define CSL_IVASYS_SYSCONFIG_IDLEMODE_NO                        (0x00000001U)
#define CSL_IVASYS_SYSCONFIG_IDLEMODE_SMART                     (0x00000002U)
#define CSL_IVASYS_SYSCONFIG_IDLEMODE_RESERVED1                 (0x00000003U)

#define CSL_IVASYS_SYSCONFIG_STANDBYMODE_MASK                   (0x00000030U)
#define CSL_IVASYS_SYSCONFIG_STANDBYMODE_SHIFT                  (4U)
#define CSL_IVASYS_SYSCONFIG_STANDBYMODE_RESETVAL               (0x00000002U)
#define CSL_IVASYS_SYSCONFIG_STANDBYMODE_RESERVED               (0x00000000U)
#define CSL_IVASYS_SYSCONFIG_STANDBYMODE_NO                     (0x00000001U)
#define CSL_IVASYS_SYSCONFIG_STANDBYMODE_SMART                  (0x00000002U)
#define CSL_IVASYS_SYSCONFIG_STANDBYMODE_RESERVED1              (0x00000003U)

#define CSL_IVASYS_SYSCONFIG_RESETVAL                           (0x00000028U)

/* IRQ_EOI */

#define CSL_IVASYS_IRQ_EOI_LINE_NUMBER_MASK                     (0x00000001U)
#define CSL_IVASYS_IRQ_EOI_LINE_NUMBER_SHIFT                    (0U)
#define CSL_IVASYS_IRQ_EOI_LINE_NUMBER_RESETVAL                 (0x00000000U)
#define CSL_IVASYS_IRQ_EOI_LINE_NUMBER_READ0                    (0x00000000U)
#define CSL_IVASYS_IRQ_EOI_LINE_NUMBER_EOI0                     (0x00000000U)
#define CSL_IVASYS_IRQ_EOI_LINE_NUMBER_EOI1                     (0x00000001U)

#define CSL_IVASYS_IRQ_EOI_RESETVAL                             (0x00000000U)

/* IRQSTS_RAW */

#define CSL_IVASYS_IRQSTS_RAW_SYSCTRL_CLKERR_MASK               (0x00000001U)
#define CSL_IVASYS_IRQSTS_RAW_SYSCTRL_CLKERR_SHIFT              (0U)
#define CSL_IVASYS_IRQSTS_RAW_SYSCTRL_CLKERR_RESETVAL           (0x00000000U)
#define CSL_IVASYS_IRQSTS_RAW_SYSCTRL_CLKERR_NOACTION           (0x00000000U)
#define CSL_IVASYS_IRQSTS_RAW_SYSCTRL_CLKERR_SET                (0x00000001U)
#define CSL_IVASYS_IRQSTS_RAW_SYSCTRL_CLKERR_NOEVENT            (0x00000000U)
#define CSL_IVASYS_IRQSTS_RAW_SYSCTRL_CLKERR_PENDING            (0x00000001U)

#define CSL_IVASYS_IRQSTS_RAW_RESETVAL                          (0x00000000U)

/* IRQSTS */

#define CSL_IVASYS_IRQSTS_SYSCTRL_CLKERR_MASK                   (0x00000001U)
#define CSL_IVASYS_IRQSTS_SYSCTRL_CLKERR_SHIFT                  (0U)
#define CSL_IVASYS_IRQSTS_SYSCTRL_CLKERR_RESETVAL               (0x00000000U)
#define CSL_IVASYS_IRQSTS_SYSCTRL_CLKERR_NOACTION               (0x00000000U)
#define CSL_IVASYS_IRQSTS_SYSCTRL_CLKERR_CLEAR                  (0x00000001U)
#define CSL_IVASYS_IRQSTS_SYSCTRL_CLKERR_NOEVENT                (0x00000000U)
#define CSL_IVASYS_IRQSTS_SYSCTRL_CLKERR_PENDING                (0x00000001U)

#define CSL_IVASYS_IRQSTS_RESETVAL                              (0x00000000U)

/* IRQEN_SET */

#define CSL_IVASYS_IRQEN_SET_SYSCTRL_CLKERR_MASK                (0x00000001U)
#define CSL_IVASYS_IRQEN_SET_SYSCTRL_CLKERR_SHIFT               (0U)
#define CSL_IVASYS_IRQEN_SET_SYSCTRL_CLKERR_RESETVAL            (0x00000000U)
#define CSL_IVASYS_IRQEN_SET_SYSCTRL_CLKERR_NOACTION            (0x00000000U)
#define CSL_IVASYS_IRQEN_SET_SYSCTRL_CLKERR_ENABLE              (0x00000001U)
#define CSL_IVASYS_IRQEN_SET_SYSCTRL_CLKERR_DISABLED            (0x00000000U)
#define CSL_IVASYS_IRQEN_SET_SYSCTRL_CLKERR_ENABLED             (0x00000001U)

#define CSL_IVASYS_IRQEN_SET_RESETVAL                           (0x00000000U)

/* IRQEN_CLR */

#define CSL_IVASYS_IRQEN_CLR_SYSCTRL_CLKERR_MASK                (0x00000001U)
#define CSL_IVASYS_IRQEN_CLR_SYSCTRL_CLKERR_SHIFT               (0U)
#define CSL_IVASYS_IRQEN_CLR_SYSCTRL_CLKERR_RESETVAL            (0x00000000U)
#define CSL_IVASYS_IRQEN_CLR_SYSCTRL_CLKERR_NOACTION            (0x00000000U)
#define CSL_IVASYS_IRQEN_CLR_SYSCTRL_CLKERR_DISABLE             (0x00000001U)
#define CSL_IVASYS_IRQEN_CLR_SYSCTRL_CLKERR_DISABLED            (0x00000000U)
#define CSL_IVASYS_IRQEN_CLR_SYSCTRL_CLKERR_ENABLED             (0x00000001U)

#define CSL_IVASYS_IRQEN_CLR_RESETVAL                           (0x00000000U)

/* SYNC_IRQSTS_RAW */

#define CSL_IVASYS_SYNC_IRQSTS_RAW_SYNC_INPUT7_0_MASK           (0x000000FFU)
#define CSL_IVASYS_SYNC_IRQSTS_RAW_SYNC_INPUT7_0_SHIFT          (0U)
#define CSL_IVASYS_SYNC_IRQSTS_RAW_SYNC_INPUT7_0_RESETVAL       (0x00000000U)
#define CSL_IVASYS_SYNC_IRQSTS_RAW_SYNC_INPUT7_0_MAX            (0x000000ffU)

#define CSL_IVASYS_SYNC_IRQSTS_RAW_RESETVAL                     (0x00000000U)

/* SYNC_IRQSTS */

#define CSL_IVASYS_SYNC_IRQSTS_SYNC_INPUT7_0_MASK               (0x000000FFU)
#define CSL_IVASYS_SYNC_IRQSTS_SYNC_INPUT7_0_SHIFT              (0U)
#define CSL_IVASYS_SYNC_IRQSTS_SYNC_INPUT7_0_RESETVAL           (0x00000000U)
#define CSL_IVASYS_SYNC_IRQSTS_SYNC_INPUT7_0_MAX                (0x000000ffU)

#define CSL_IVASYS_SYNC_IRQSTS_RESETVAL                         (0x00000000U)

/* SYNC_IRQEN_SET */

#define CSL_IVASYS_SYNC_IRQEN_SET_SYNC_INPUT7_0_MASK            (0x000000FFU)
#define CSL_IVASYS_SYNC_IRQEN_SET_SYNC_INPUT7_0_SHIFT           (0U)
#define CSL_IVASYS_SYNC_IRQEN_SET_SYNC_INPUT7_0_RESETVAL        (0x00000000U)
#define CSL_IVASYS_SYNC_IRQEN_SET_SYNC_INPUT7_0_MAX             (0x000000ffU)

#define CSL_IVASYS_SYNC_IRQEN_SET_RESETVAL                      (0x00000000U)

/* SYNC_IRQEN_CLR */

#define CSL_IVASYS_SYNC_IRQEN_CLR_SYNC_INPUT7_0_MASK            (0x000000FFU)
#define CSL_IVASYS_SYNC_IRQEN_CLR_SYNC_INPUT7_0_SHIFT           (0U)
#define CSL_IVASYS_SYNC_IRQEN_CLR_SYNC_INPUT7_0_RESETVAL        (0x00000000U)
#define CSL_IVASYS_SYNC_IRQEN_CLR_SYNC_INPUT7_0_MAX             (0x000000ffU)

#define CSL_IVASYS_SYNC_IRQEN_CLR_RESETVAL                      (0x00000000U)

/* CLKCTRL */

#define CSL_IVASYS_CLKCTRL_ICONT2_MASK                          (0x00000002U)
#define CSL_IVASYS_CLKCTRL_ICONT2_SHIFT                         (1U)
#define CSL_IVASYS_CLKCTRL_ICONT2_RESETVAL                      (0x00000000U)
#define CSL_IVASYS_CLKCTRL_ICONT2_MAX                           (0x00000001U)

#define CSL_IVASYS_CLKCTRL_VDMA_MASK                            (0x00000004U)
#define CSL_IVASYS_CLKCTRL_VDMA_SHIFT                           (2U)
#define CSL_IVASYS_CLKCTRL_VDMA_RESETVAL                        (0x00000000U)
#define CSL_IVASYS_CLKCTRL_VDMA_MAX                             (0x00000001U)

#define CSL_IVASYS_CLKCTRL_IME3_MASK                            (0x00000008U)
#define CSL_IVASYS_CLKCTRL_IME3_SHIFT                           (3U)
#define CSL_IVASYS_CLKCTRL_IME3_RESETVAL                        (0x00000000U)
#define CSL_IVASYS_CLKCTRL_IME3_MAX                             (0x00000001U)

#define CSL_IVASYS_CLKCTRL_ILF3_MASK                            (0x00000010U)
#define CSL_IVASYS_CLKCTRL_ILF3_SHIFT                           (4U)
#define CSL_IVASYS_CLKCTRL_ILF3_RESETVAL                        (0x00000000U)
#define CSL_IVASYS_CLKCTRL_ILF3_MAX                             (0x00000001U)

#define CSL_IVASYS_CLKCTRL_CALC3_MASK                           (0x00000020U)
#define CSL_IVASYS_CLKCTRL_CALC3_SHIFT                          (5U)
#define CSL_IVASYS_CLKCTRL_CALC3_RESETVAL                       (0x00000000U)
#define CSL_IVASYS_CLKCTRL_CALC3_MAX                            (0x00000001U)

#define CSL_IVASYS_CLKCTRL_IPE3_MASK                            (0x00000040U)
#define CSL_IVASYS_CLKCTRL_IPE3_SHIFT                           (6U)
#define CSL_IVASYS_CLKCTRL_IPE3_RESETVAL                        (0x00000000U)
#define CSL_IVASYS_CLKCTRL_IPE3_MAX                             (0x00000001U)

#define CSL_IVASYS_CLKCTRL_MC3_MASK                             (0x00000080U)
#define CSL_IVASYS_CLKCTRL_MC3_SHIFT                            (7U)
#define CSL_IVASYS_CLKCTRL_MC3_RESETVAL                         (0x00000000U)
#define CSL_IVASYS_CLKCTRL_MC3_MAX                              (0x00000001U)

#define CSL_IVASYS_CLKCTRL_ECD3_MASK                            (0x00000100U)
#define CSL_IVASYS_CLKCTRL_ECD3_SHIFT                           (8U)
#define CSL_IVASYS_CLKCTRL_ECD3_RESETVAL                        (0x00000000U)
#define CSL_IVASYS_CLKCTRL_ECD3_MAX                             (0x00000001U)

#define CSL_IVASYS_CLKCTRL_ICONT1_MASK                          (0x00000001U)
#define CSL_IVASYS_CLKCTRL_ICONT1_SHIFT                         (0U)
#define CSL_IVASYS_CLKCTRL_ICONT1_RESETVAL                      (0x00000000U)
#define CSL_IVASYS_CLKCTRL_ICONT1_MAX                           (0x00000001U)

#define CSL_IVASYS_CLKCTRL_MSGIF_MASK                           (0x00000200U)
#define CSL_IVASYS_CLKCTRL_MSGIF_SHIFT                          (9U)
#define CSL_IVASYS_CLKCTRL_MSGIF_RESETVAL                       (0x00000000U)
#define CSL_IVASYS_CLKCTRL_MSGIF_MAX                            (0x00000001U)

#define CSL_IVASYS_CLKCTRL_SMSET_MASK                           (0x00000400U)
#define CSL_IVASYS_CLKCTRL_SMSET_SHIFT                          (10U)
#define CSL_IVASYS_CLKCTRL_SMSET_RESETVAL                       (0x00000000U)
#define CSL_IVASYS_CLKCTRL_SMSET_MAX                            (0x00000001U)

#define CSL_IVASYS_CLKCTRL_RESETVAL                             (0x00000000U)

/* CLKST */

#define CSL_IVASYS_CLKST_ICONT2_MASK                            (0x00000002U)
#define CSL_IVASYS_CLKST_ICONT2_SHIFT                           (1U)
#define CSL_IVASYS_CLKST_ICONT2_RESETVAL                        (0x00000001U)
#define CSL_IVASYS_CLKST_ICONT2_MAX                             (0x00000001U)

#define CSL_IVASYS_CLKST_VDMA_MASK                              (0x00000004U)
#define CSL_IVASYS_CLKST_VDMA_SHIFT                             (2U)
#define CSL_IVASYS_CLKST_VDMA_RESETVAL                          (0x00000001U)
#define CSL_IVASYS_CLKST_VDMA_MAX                               (0x00000001U)

#define CSL_IVASYS_CLKST_IME3_MASK                              (0x00000008U)
#define CSL_IVASYS_CLKST_IME3_SHIFT                             (3U)
#define CSL_IVASYS_CLKST_IME3_RESETVAL                          (0x00000001U)
#define CSL_IVASYS_CLKST_IME3_MAX                               (0x00000001U)

#define CSL_IVASYS_CLKST_ILF3_MASK                              (0x00000010U)
#define CSL_IVASYS_CLKST_ILF3_SHIFT                             (4U)
#define CSL_IVASYS_CLKST_ILF3_RESETVAL                          (0x00000001U)
#define CSL_IVASYS_CLKST_ILF3_MAX                               (0x00000001U)

#define CSL_IVASYS_CLKST_CALC3_MASK                             (0x00000020U)
#define CSL_IVASYS_CLKST_CALC3_SHIFT                            (5U)
#define CSL_IVASYS_CLKST_CALC3_RESETVAL                         (0x00000001U)
#define CSL_IVASYS_CLKST_CALC3_MAX                              (0x00000001U)

#define CSL_IVASYS_CLKST_IPE3_MASK                              (0x00000040U)
#define CSL_IVASYS_CLKST_IPE3_SHIFT                             (6U)
#define CSL_IVASYS_CLKST_IPE3_RESETVAL                          (0x00000001U)
#define CSL_IVASYS_CLKST_IPE3_MAX                               (0x00000001U)

#define CSL_IVASYS_CLKST_MC3_MASK                               (0x00000080U)
#define CSL_IVASYS_CLKST_MC3_SHIFT                              (7U)
#define CSL_IVASYS_CLKST_MC3_RESETVAL                           (0x00000001U)
#define CSL_IVASYS_CLKST_MC3_MAX                                (0x00000001U)

#define CSL_IVASYS_CLKST_ECD3_MASK                              (0x00000100U)
#define CSL_IVASYS_CLKST_ECD3_SHIFT                             (8U)
#define CSL_IVASYS_CLKST_ECD3_RESETVAL                          (0x00000001U)
#define CSL_IVASYS_CLKST_ECD3_MAX                               (0x00000001U)

#define CSL_IVASYS_CLKST_ICONT1_MASK                            (0x00000001U)
#define CSL_IVASYS_CLKST_ICONT1_SHIFT                           (0U)
#define CSL_IVASYS_CLKST_ICONT1_RESETVAL                        (0x00000001U)
#define CSL_IVASYS_CLKST_ICONT1_MAX                             (0x00000001U)

#define CSL_IVASYS_CLKST_MSGIF_MASK                             (0x00000200U)
#define CSL_IVASYS_CLKST_MSGIF_SHIFT                            (9U)
#define CSL_IVASYS_CLKST_MSGIF_RESETVAL                         (0x00000001U)
#define CSL_IVASYS_CLKST_MSGIF_MAX                              (0x00000001U)

#define CSL_IVASYS_CLKST_SMSET_MASK                             (0x00000400U)
#define CSL_IVASYS_CLKST_SMSET_SHIFT                            (10U)
#define CSL_IVASYS_CLKST_SMSET_RESETVAL                         (0x00000001U)
#define CSL_IVASYS_CLKST_SMSET_MAX                              (0x00000001U)

#define CSL_IVASYS_CLKST_RESETVAL                               (0x000007ffU)

/* STDBYST */

#define CSL_IVASYS_STDBYST_ICONT1_MASK                          (0x00000001U)
#define CSL_IVASYS_STDBYST_ICONT1_SHIFT                         (0U)
#define CSL_IVASYS_STDBYST_ICONT1_RESETVAL                      (0x00000001U)
#define CSL_IVASYS_STDBYST_ICONT1_MAX                           (0x00000001U)

#define CSL_IVASYS_STDBYST_ICONT2_MASK                          (0x00000002U)
#define CSL_IVASYS_STDBYST_ICONT2_SHIFT                         (1U)
#define CSL_IVASYS_STDBYST_ICONT2_RESETVAL                      (0x00000001U)
#define CSL_IVASYS_STDBYST_ICONT2_MAX                           (0x00000001U)

#define CSL_IVASYS_STDBYST_VDMA_MASK                            (0x00000004U)
#define CSL_IVASYS_STDBYST_VDMA_SHIFT                           (2U)
#define CSL_IVASYS_STDBYST_VDMA_RESETVAL                        (0x00000001U)
#define CSL_IVASYS_STDBYST_VDMA_MAX                             (0x00000001U)

#define CSL_IVASYS_STDBYST_RESETVAL                             (0x00000007U)

#ifdef __cplusplus
}
#endif
#endif
