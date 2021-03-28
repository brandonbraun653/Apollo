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
#ifndef CSLR_KBD_H_
#define CSLR_KBD_H_

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
    volatile Uint8  RSVD0[12];
    volatile Uint32 SYSCONFIG;
    volatile Uint8  RSVD1[8];
    volatile Uint32 EOI;
    volatile Uint32 IRQSTS_RAW;
    volatile Uint32 IRQSTS;
    volatile Uint32 IRQEN_SET;
    volatile Uint32 IRQEN_CLR;
    volatile Uint32 IRQWAKEEN;
    volatile Uint32 PENDING;
    volatile Uint32 CTRL;
    volatile Uint32 DEBOUNCINGTIME;
    volatile Uint32 KEYLONGTIME;
    volatile Uint32 TIMEOUT;
    volatile Uint32 STATEMACHINE;
    volatile Uint32 ROWINPUTS;
    volatile Uint32 COLUMNOUTPUTS;
    volatile Uint32 FULLCODE31_0;
    volatile Uint32 FULLCODE63_32;
    volatile Uint32 FULLCODE17_0;
    volatile Uint32 FULLCODE35_18;
    volatile Uint32 FULLCODE53_36;
    volatile Uint32 FULLCODE71_54;
    volatile Uint32 FULLCODE80_72;
} CSL_KbdRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* This register contains the IP revision code. A write to this register has
 * no effect. */
#define CSL_KBD_REVISION                                        (0x0U)

/* This register controls the various parameters of the OCP interface */
#define CSL_KBD_SYSCONFIG                                       (0x10U)

/* Software End-Of-Interrupt: Allows the generation of further pulses on the
 * interrupt line, if an new interrupt event is pending, when using the pulsed
 * output. Unused when using the level interrupt line (depending on module
 * integration). */
#define CSL_KBD_EOI                                             (0x1CU)

/* Per-event raw interrupt status vector Raw status is set even if event is
 * not enabled. Write 1 to set the (raw) status, mostly for debug. */
#define CSL_KBD_IRQSTS_RAW                                      (0x20U)

/* Per-event "enabled" interrupt status vector. Enabled status isn't set
 * unless event is enabled. Write 1 to clear the status after interrupt has
 * been serviced (raw status gets cleared, i.e. even if not enabled). */
#define CSL_KBD_IRQSTS                                          (0x24U)

/* Per-event interrupt enable bit vector Write 1 to set (enable interrupt).
 * Readout equal to corresponding _CLR register. */
#define CSL_KBD_IRQEN_SET                                       (0x28U)

/* Per-event interrupt enable bit vector Write 1 to clear (disable interrupt).
 * Readout equal to corresponding _SET register. */
#define CSL_KBD_IRQEN_CLR                                       (0x2CU)

/* The Keyboard Wake-up Enable Register allows the user to mask the expected
 * source of wake-up event that will generate a wake-up request. The
 * KBD_WAKEUPENABLE is programmed synchronously with the interface clock
 * before any idle mode request comes from the host processor. */
#define CSL_KBD_IRQWAKEEN                                       (0x30U)

/* The software must read the pending write bits to insure that following
 * write access will not be discarded due to on going write synchronization
 * process. These bits are automatically cleared by internal logic when the
 * write to the corresponding register is acknowledged. */
#define CSL_KBD_PENDING                                         (0x34U)

/* This register sets the functional configuration of the module. */
#define CSL_KBD_CTRL                                            (0x38U)

/* This register is used to filter glitches on the press key or release key. */
#define CSL_KBD_DEBOUNCINGTIME                                  (0x3CU)

/* This register is used to measure duration of a key press, to allow,
 * shortcut detection. */
#define CSL_KBD_KEYLONGTIME                                     (0x40U)

/* This register is used to detect a long inactivity on the keyboard. */
#define CSL_KBD_TIMEOUT                                         (0x44U)

/* This register indicates the state of the sequencer. */
#define CSL_KBD_STATEMACHINE                                    (0x48U)

/* This register stores the value of the rows input. */
#define CSL_KBD_ROWINPUTS                                       (0x4CU)

/* This register holds the value of the columns output. */
#define CSL_KBD_COLUMNOUTPUTS                                   (0x50U)

/* The KBD_FULLCODE31_0 register codes the row 0, row 1, row 2 and row 3 */
#define CSL_KBD_FULLCODE31_0                                    (0x54U)

/* The KBD_FULLCODE63_32 register codes the row 4, row 5, row 6 and row 7. */
#define CSL_KBD_FULLCODE63_32                                   (0x58U)

/* The KBD_FULLCODE17_0 register codes the row 0 and row 1. The row 0 is coded
 * between bit 0 and 8, the row 1 is coded between bit 24 and */
#define CSL_KBD_FULLCODE17_0                                    (0x5CU)

/* The KBD_FULLCODE35_18 register codes the row 2 and row 3. The row 2 is
 * coded between bit 0 and 8, the row 3 is coded between bit 24 and 16 */
#define CSL_KBD_FULLCODE35_18                                   (0x60U)

/* The KBD_FULLCODE53_36 register codes the row 4 and row 5. The row 4 is
 * coded between bit 0 and 8, the row 5 is coded between bit 24 and 16. */
#define CSL_KBD_FULLCODE53_36                                   (0x64U)

/* The KBD_FULLCODE71_54 register codes the row 6 and row 7. The row 0 is
 * coded between bit 0 and 8, the row 1 is coded between bit 24 and 16 */
#define CSL_KBD_FULLCODE71_54                                   (0x68U)

/* The KBD_FULLCODE80_72 register codes the row 8. The row 8 is coded between
 * bit 0 and 8. */
#define CSL_KBD_FULLCODE80_72                                   (0x6CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION */

#define CSL_KBD_REVISION_X_MAJOR_MASK                           (0x00000700U)
#define CSL_KBD_REVISION_X_MAJOR_SHIFT                          (8U)
#define CSL_KBD_REVISION_X_MAJOR_RESETVAL                       (0x00000002U)
#define CSL_KBD_REVISION_X_MAJOR_MAX                            (0x00000007U)

#define CSL_KBD_REVISION_Y_MINOR_MASK                           (0x0000003FU)
#define CSL_KBD_REVISION_Y_MINOR_SHIFT                          (0U)
#define CSL_KBD_REVISION_Y_MINOR_RESETVAL                       (0x00000000U)
#define CSL_KBD_REVISION_Y_MINOR_MAX                            (0x0000003fU)

#define CSL_KBD_REVISION_CUSTOM_MASK                            (0x000000C0U)
#define CSL_KBD_REVISION_CUSTOM_SHIFT                           (6U)
#define CSL_KBD_REVISION_CUSTOM_RESETVAL                        (0x00000000U)
#define CSL_KBD_REVISION_CUSTOM_MAX                             (0x00000003U)

#define CSL_KBD_REVISION_R_RTL_MASK                             (0x0000F800U)
#define CSL_KBD_REVISION_R_RTL_SHIFT                            (11U)
#define CSL_KBD_REVISION_R_RTL_RESETVAL                         (0x00000000U)
#define CSL_KBD_REVISION_R_RTL_MAX                              (0x0000001fU)

#define CSL_KBD_REVISION_FUNC_MASK                              (0x0FFF0000U)
#define CSL_KBD_REVISION_FUNC_SHIFT                             (16U)
#define CSL_KBD_REVISION_FUNC_RESETVAL                          (0x00000fffU)
#define CSL_KBD_REVISION_FUNC_MAX                               (0x00000fffU)

#define CSL_KBD_REVISION_SCHEME_MASK                            (0xC0000000U)
#define CSL_KBD_REVISION_SCHEME_SHIFT                           (30U)
#define CSL_KBD_REVISION_SCHEME_RESETVAL                        (0x00000001U)
#define CSL_KBD_REVISION_SCHEME_MAX                             (0x00000003U)

#define CSL_KBD_REVISION_RESETVAL                               (0x5fff0200U)

/* SYSCONFIG */

#define CSL_KBD_SYSCONFIG_EMUFREE_MASK                          (0x00000020U)
#define CSL_KBD_SYSCONFIG_EMUFREE_SHIFT                         (5U)
#define CSL_KBD_SYSCONFIG_EMUFREE_RESETVAL                      (0x00000000U)
#define CSL_KBD_SYSCONFIG_EMUFREE_MODULE_FROZEN                 (0x00000000U)
#define CSL_KBD_SYSCONFIG_EMUFREE_MODULE_FREE                   (0x00000001U)

#define CSL_KBD_SYSCONFIG_IDLEMODE_MASK                         (0x00000018U)
#define CSL_KBD_SYSCONFIG_IDLEMODE_SHIFT                        (3U)
#define CSL_KBD_SYSCONFIG_IDLEMODE_RESETVAL                     (0x00000000U)
#define CSL_KBD_SYSCONFIG_IDLEMODE_FORCE_IDLE                   (0x00000000U)
#define CSL_KBD_SYSCONFIG_IDLEMODE_NO_IDLE                      (0x00000001U)
#define CSL_KBD_SYSCONFIG_IDLEMODE_SMART_IDLE                   (0x00000002U)
#define CSL_KBD_SYSCONFIG_IDLEMODE_RESERVED                     (0x00000003U)

#define CSL_KBD_SYSCONFIG_SOFTRESET_MASK                        (0x00000002U)
#define CSL_KBD_SYSCONFIG_SOFTRESET_SHIFT                       (1U)
#define CSL_KBD_SYSCONFIG_SOFTRESET_RESETVAL                    (0x00000000U)
#define CSL_KBD_SYSCONFIG_SOFTRESET_NORMAL_MODE                 (0x00000000U)
#define CSL_KBD_SYSCONFIG_SOFTRESET_RESET_MODE                  (0x00000001U)

#define CSL_KBD_SYSCONFIG_RESETVAL                              (0x00000000U)

/* EOI */

#define CSL_KBD_EOI_LINE_NUMBER_MASK                            (0x00000001U)
#define CSL_KBD_EOI_LINE_NUMBER_SHIFT                           (0U)
#define CSL_KBD_EOI_LINE_NUMBER_RESETVAL                        (0x00000000U)
#define CSL_KBD_EOI_LINE_NUMBER_IT_EVENT_0                      (0x00000000U)
#define CSL_KBD_EOI_LINE_NUMBER_IT_EVENT_1                      (0x00000001U)

#define CSL_KBD_EOI_RESETVAL                                    (0x00000000U)

/* IRQSTS_RAW */

#define CSL_KBD_IRQSTS_RAW_IT_TIMEOUT_MASK                      (0x00000004U)
#define CSL_KBD_IRQSTS_RAW_IT_TIMEOUT_SHIFT                     (2U)
#define CSL_KBD_IRQSTS_RAW_IT_TIMEOUT_RESETVAL                  (0x00000000U)
#define CSL_KBD_IRQSTS_RAW_IT_TIMEOUT_MAX                       (0x00000001U)

#define CSL_KBD_IRQSTS_RAW_IT_LONG_KEY_MASK                     (0x00000002U)
#define CSL_KBD_IRQSTS_RAW_IT_LONG_KEY_SHIFT                    (1U)
#define CSL_KBD_IRQSTS_RAW_IT_LONG_KEY_RESETVAL                 (0x00000000U)
#define CSL_KBD_IRQSTS_RAW_IT_LONG_KEY_MAX                      (0x00000001U)

#define CSL_KBD_IRQSTS_RAW_IT_EVT_MASK                          (0x00000001U)
#define CSL_KBD_IRQSTS_RAW_IT_EVT_SHIFT                         (0U)
#define CSL_KBD_IRQSTS_RAW_IT_EVT_RESETVAL                      (0x00000000U)
#define CSL_KBD_IRQSTS_RAW_IT_EVT_MAX                           (0x00000001U)

#define CSL_KBD_IRQSTS_RAW_MISS_EVT_MASK                        (0x00000008U)
#define CSL_KBD_IRQSTS_RAW_MISS_EVT_SHIFT                       (3U)
#define CSL_KBD_IRQSTS_RAW_MISS_EVT_RESETVAL                    (0x00000000U)
#define CSL_KBD_IRQSTS_RAW_MISS_EVT_MAX                         (0x00000001U)

#define CSL_KBD_IRQSTS_RAW_RESETVAL                             (0x00000000U)

/* IRQSTS */

#define CSL_KBD_IRQSTS_IT_EVT_MASK                              (0x00000001U)
#define CSL_KBD_IRQSTS_IT_EVT_SHIFT                             (0U)
#define CSL_KBD_IRQSTS_IT_EVT_RESETVAL                          (0x00000000U)
#define CSL_KBD_IRQSTS_IT_EVT_MAX                               (0x00000001U)

#define CSL_KBD_IRQSTS_IT_LONG_KEY_MASK                         (0x00000002U)
#define CSL_KBD_IRQSTS_IT_LONG_KEY_SHIFT                        (1U)
#define CSL_KBD_IRQSTS_IT_LONG_KEY_RESETVAL                     (0x00000000U)
#define CSL_KBD_IRQSTS_IT_LONG_KEY_MAX                          (0x00000001U)

#define CSL_KBD_IRQSTS_IT_TIMEOUT_MASK                          (0x00000004U)
#define CSL_KBD_IRQSTS_IT_TIMEOUT_SHIFT                         (2U)
#define CSL_KBD_IRQSTS_IT_TIMEOUT_RESETVAL                      (0x00000000U)
#define CSL_KBD_IRQSTS_IT_TIMEOUT_MAX                           (0x00000001U)

#define CSL_KBD_IRQSTS_MISS_EVT_MASK                            (0x00000008U)
#define CSL_KBD_IRQSTS_MISS_EVT_SHIFT                           (3U)
#define CSL_KBD_IRQSTS_MISS_EVT_RESETVAL                        (0x00000000U)
#define CSL_KBD_IRQSTS_MISS_EVT_MAX                             (0x00000001U)

#define CSL_KBD_IRQSTS_RESETVAL                                 (0x00000000U)

/* IRQEN_SET */

#define CSL_KBD_IRQEN_SET_IT_EVT_EN_MASK                        (0x00000001U)
#define CSL_KBD_IRQEN_SET_IT_EVT_EN_SHIFT                       (0U)
#define CSL_KBD_IRQEN_SET_IT_EVT_EN_RESETVAL                    (0x00000000U)
#define CSL_KBD_IRQEN_SET_IT_EVT_EN_MAX                         (0x00000001U)

#define CSL_KBD_IRQEN_SET_IT_LONG_KEY_EN_MASK                   (0x00000002U)
#define CSL_KBD_IRQEN_SET_IT_LONG_KEY_EN_SHIFT                  (1U)
#define CSL_KBD_IRQEN_SET_IT_LONG_KEY_EN_RESETVAL               (0x00000000U)
#define CSL_KBD_IRQEN_SET_IT_LONG_KEY_EN_MAX                    (0x00000001U)

#define CSL_KBD_IRQEN_SET_IT_TIMEOUT_EN_MASK                    (0x00000004U)
#define CSL_KBD_IRQEN_SET_IT_TIMEOUT_EN_SHIFT                   (2U)
#define CSL_KBD_IRQEN_SET_IT_TIMEOUT_EN_RESETVAL                (0x00000000U)
#define CSL_KBD_IRQEN_SET_IT_TIMEOUT_EN_MAX                     (0x00000001U)

#define CSL_KBD_IRQEN_SET_RESETVAL                              (0x00000000U)

/* IRQEN_CLR */

#define CSL_KBD_IRQEN_CLR_IT_EVT_EN_MASK                        (0x00000001U)
#define CSL_KBD_IRQEN_CLR_IT_EVT_EN_SHIFT                       (0U)
#define CSL_KBD_IRQEN_CLR_IT_EVT_EN_RESETVAL                    (0x00000000U)
#define CSL_KBD_IRQEN_CLR_IT_EVT_EN_MAX                         (0x00000001U)

#define CSL_KBD_IRQEN_CLR_IT_LONG_KEY_EN_MASK                   (0x00000002U)
#define CSL_KBD_IRQEN_CLR_IT_LONG_KEY_EN_SHIFT                  (1U)
#define CSL_KBD_IRQEN_CLR_IT_LONG_KEY_EN_RESETVAL               (0x00000000U)
#define CSL_KBD_IRQEN_CLR_IT_LONG_KEY_EN_MAX                    (0x00000001U)

#define CSL_KBD_IRQEN_CLR_IT_TIMEOUT_EN_MASK                    (0x00000004U)
#define CSL_KBD_IRQEN_CLR_IT_TIMEOUT_EN_SHIFT                   (2U)
#define CSL_KBD_IRQEN_CLR_IT_TIMEOUT_EN_RESETVAL                (0x00000000U)
#define CSL_KBD_IRQEN_CLR_IT_TIMEOUT_EN_MAX                     (0x00000001U)

#define CSL_KBD_IRQEN_CLR_RESETVAL                              (0x00000000U)

/* IRQWAKEEN */

#define CSL_KBD_IRQWAKEEN_WUP_TIMEOUT_ENA_MASK                  (0x00000004U)
#define CSL_KBD_IRQWAKEEN_WUP_TIMEOUT_ENA_SHIFT                 (2U)
#define CSL_KBD_IRQWAKEEN_WUP_TIMEOUT_ENA_RESETVAL              (0x00000000U)
#define CSL_KBD_IRQWAKEEN_WUP_TIMEOUT_ENA_WUP_TIMEOUT_ENA_0     (0x00000000U)
#define CSL_KBD_IRQWAKEEN_WUP_TIMEOUT_ENA_WUP_TIMEOUT_ENA_1     (0x00000001U)

#define CSL_KBD_IRQWAKEEN_WUP_LONG_KEY_ENA_MASK                 (0x00000002U)
#define CSL_KBD_IRQWAKEEN_WUP_LONG_KEY_ENA_SHIFT                (1U)
#define CSL_KBD_IRQWAKEEN_WUP_LONG_KEY_ENA_RESETVAL             (0x00000000U)
#define CSL_KBD_IRQWAKEEN_WUP_LONG_KEY_ENA_WUP_LONG_KEY_ENA_1   (0x00000001U)
#define CSL_KBD_IRQWAKEEN_WUP_LONG_KEY_ENA_WUP_LONG_KEY_ENA_0   (0x00000000U)

#define CSL_KBD_IRQWAKEEN_WUP_EVT_ENA_MASK                      (0x00000001U)
#define CSL_KBD_IRQWAKEEN_WUP_EVT_ENA_SHIFT                     (0U)
#define CSL_KBD_IRQWAKEEN_WUP_EVT_ENA_RESETVAL                  (0x00000000U)
#define CSL_KBD_IRQWAKEEN_WUP_EVT_ENA_WUP_EVENT_ENA_1           (0x00000001U)
#define CSL_KBD_IRQWAKEEN_WUP_EVT_ENA_WUP_EVENT_ENA_0           (0x00000000U)

#define CSL_KBD_IRQWAKEEN_RESETVAL                              (0x00000000U)

/* PENDING */

#define CSL_KBD_PENDING_PEND_TIMEOUT_MASK                       (0x00000008U)
#define CSL_KBD_PENDING_PEND_TIMEOUT_SHIFT                      (3U)
#define CSL_KBD_PENDING_PEND_TIMEOUT_RESETVAL                   (0x00000000U)
#define CSL_KBD_PENDING_PEND_TIMEOUT_PEND_TIMEOUT_0             (0x00000000U)
#define CSL_KBD_PENDING_PEND_TIMEOUT_PEND_TIMEOUT_1             (0x00000001U)

#define CSL_KBD_PENDING_PEND_LONG_KEY_MASK                      (0x00000004U)
#define CSL_KBD_PENDING_PEND_LONG_KEY_SHIFT                     (2U)
#define CSL_KBD_PENDING_PEND_LONG_KEY_RESETVAL                  (0x00000000U)
#define CSL_KBD_PENDING_PEND_LONG_KEY_PEND_LONGKEY_0            (0x00000000U)
#define CSL_KBD_PENDING_PEND_LONG_KEY_PEND_LONGKEY_1            (0x00000001U)

#define CSL_KBD_PENDING_PEND_DEBOUNCING_MASK                    (0x00000002U)
#define CSL_KBD_PENDING_PEND_DEBOUNCING_SHIFT                   (1U)
#define CSL_KBD_PENDING_PEND_DEBOUNCING_RESETVAL                (0x00000000U)
#define CSL_KBD_PENDING_PEND_DEBOUNCING_PEND_DEBOUNCING_0       (0x00000000U)
#define CSL_KBD_PENDING_PEND_DEBOUNCING_PEND_DEBOUNCING_1       (0x00000001U)

#define CSL_KBD_PENDING_PEND_CTRL_MASK                          (0x00000001U)
#define CSL_KBD_PENDING_PEND_CTRL_SHIFT                         (0U)
#define CSL_KBD_PENDING_PEND_CTRL_RESETVAL                      (0x00000000U)
#define CSL_KBD_PENDING_PEND_CTRL_PEND_CTRL_0                   (0x00000000U)
#define CSL_KBD_PENDING_PEND_CTRL_PEND_CTRL_1                   (0x00000001U)

#define CSL_KBD_PENDING_RESETVAL                                (0x00000000U)

/* CTRL */

#define CSL_KBD_CTRL_NSOFTWARE_MODE_MASK                        (0x00000002U)
#define CSL_KBD_CTRL_NSOFTWARE_MODE_SHIFT                       (1U)
#define CSL_KBD_CTRL_NSOFTWARE_MODE_RESETVAL                    (0x00000001U)
#define CSL_KBD_CTRL_NSOFTWARE_MODE_NSOFTWARE_MODE_1            (0x00000001U)
#define CSL_KBD_CTRL_NSOFTWARE_MODE_NSOFTWARE_MODE_0            (0x00000000U)

#define CSL_KBD_CTRL_TIMEOUT_EMPTY_MASK                         (0x00000040U)
#define CSL_KBD_CTRL_TIMEOUT_EMPTY_SHIFT                        (6U)
#define CSL_KBD_CTRL_TIMEOUT_EMPTY_RESETVAL                     (0x00000000U)
#define CSL_KBD_CTRL_TIMEOUT_EMPTY_TIMEOUT_EMPTY_0              (0x00000000U)
#define CSL_KBD_CTRL_TIMEOUT_EMPTY_TIMEOUT_EMPTY_1              (0x00000001U)

#define CSL_KBD_CTRL_LONG_KEY_MASK                              (0x00000020U)
#define CSL_KBD_CTRL_LONG_KEY_SHIFT                             (5U)
#define CSL_KBD_CTRL_LONG_KEY_RESETVAL                          (0x00000000U)
#define CSL_KBD_CTRL_LONG_KEY_LONG_KEY_1                        (0x00000001U)
#define CSL_KBD_CTRL_LONG_KEY_LONG_KEY_0                        (0x00000000U)

#define CSL_KBD_CTRL_REPEAT_MODE_MASK                           (0x00000100U)
#define CSL_KBD_CTRL_REPEAT_MODE_SHIFT                          (8U)
#define CSL_KBD_CTRL_REPEAT_MODE_RESETVAL                       (0x00000000U)
#define CSL_KBD_CTRL_REPEAT_MODE_REPEAT_MODE_1                  (0x00000001U)
#define CSL_KBD_CTRL_REPEAT_MODE_REPEAT_MODE_0                  (0x00000000U)

#define CSL_KBD_CTRL_PTV_MASK                                   (0x0000001CU)
#define CSL_KBD_CTRL_PTV_SHIFT                                  (2U)
#define CSL_KBD_CTRL_PTV_RESETVAL                               (0x00000007U)
#define CSL_KBD_CTRL_PTV_MAX                                    (0x00000007U)

#define CSL_KBD_CTRL_TIMEOUT_LONG_KEY_MASK                      (0x00000080U)
#define CSL_KBD_CTRL_TIMEOUT_LONG_KEY_SHIFT                     (7U)
#define CSL_KBD_CTRL_TIMEOUT_LONG_KEY_RESETVAL                  (0x00000000U)
#define CSL_KBD_CTRL_TIMEOUT_LONG_KEY_TIMEOUT_LONG_KEY_0        (0x00000000U)
#define CSL_KBD_CTRL_TIMEOUT_LONG_KEY_TIMEOUT_LONG_KEY_1        (0x00000001U)

#define CSL_KBD_CTRL_RESETVAL                                   (0x0000001eU)

/* DEBOUNCINGTIME */

#define CSL_KBD_DEBOUNCINGTIME_DEBOUNCING_VALUE_MASK            (0x0000003FU)
#define CSL_KBD_DEBOUNCINGTIME_DEBOUNCING_VALUE_SHIFT           (0U)
#define CSL_KBD_DEBOUNCINGTIME_DEBOUNCING_VALUE_RESETVAL        (0x00000000U)
#define CSL_KBD_DEBOUNCINGTIME_DEBOUNCING_VALUE_MAX             (0x0000003fU)

#define CSL_KBD_DEBOUNCINGTIME_RESETVAL                         (0x00000000U)

/* KEYLONGTIME */

#define CSL_KBD_KEYLONGTIME_LONG_KEY_VALUE_MASK                 (0x00000FFFU)
#define CSL_KBD_KEYLONGTIME_LONG_KEY_VALUE_SHIFT                (0U)
#define CSL_KBD_KEYLONGTIME_LONG_KEY_VALUE_RESETVAL             (0x00000000U)
#define CSL_KBD_KEYLONGTIME_LONG_KEY_VALUE_MAX                  (0x00000fffU)

#define CSL_KBD_KEYLONGTIME_RESETVAL                            (0x00000000U)

/* TIMEOUT */

#define CSL_KBD_TIMEOUT_TIMEOUT_VALUE_MASK                      (0x0000FFFFU)
#define CSL_KBD_TIMEOUT_TIMEOUT_VALUE_SHIFT                     (0U)
#define CSL_KBD_TIMEOUT_TIMEOUT_VALUE_RESETVAL                  (0x00000000U)
#define CSL_KBD_TIMEOUT_TIMEOUT_VALUE_MAX                       (0x0000ffffU)

#define CSL_KBD_TIMEOUT_RESETVAL                                (0x00000000U)

/* STATEMACHINE */

#define CSL_KBD_STATEMACHINE_STATE_MACHINE_MASK                 (0x0000000FU)
#define CSL_KBD_STATEMACHINE_STATE_MACHINE_SHIFT                (0U)
#define CSL_KBD_STATEMACHINE_STATE_MACHINE_RESETVAL             (0x00000000U)
#define CSL_KBD_STATEMACHINE_STATE_MACHINE_MAX                  (0x0000000fU)

#define CSL_KBD_STATEMACHINE_RESETVAL                           (0x00000000U)

/* ROWINPUTS */

#define CSL_KBD_ROWINPUTS_KBR_LATCH_MASK                        (0x000001FFU)
#define CSL_KBD_ROWINPUTS_KBR_LATCH_SHIFT                       (0U)
#define CSL_KBD_ROWINPUTS_KBR_LATCH_RESETVAL                    (0x00000000U)
#define CSL_KBD_ROWINPUTS_KBR_LATCH_MAX                         (0x000001ffU)

#define CSL_KBD_ROWINPUTS_RESETVAL                              (0x00000000U)

/* COLUMNOUTPUTS */

#define CSL_KBD_COLUMNOUTPUTS_KBC_REG_MASK                      (0x000001FFU)
#define CSL_KBD_COLUMNOUTPUTS_KBC_REG_SHIFT                     (0U)
#define CSL_KBD_COLUMNOUTPUTS_KBC_REG_RESETVAL                  (0x00000000U)
#define CSL_KBD_COLUMNOUTPUTS_KBC_REG_MAX                       (0x000001ffU)

#define CSL_KBD_COLUMNOUTPUTS_RESETVAL                          (0x00000000U)

/* FULLCODE31_0 */

#define CSL_KBD_FULLCODE31_0_FULL_CODE_31_0_MASK                (0xFFFFFFFFU)
#define CSL_KBD_FULLCODE31_0_FULL_CODE_31_0_SHIFT               (0U)
#define CSL_KBD_FULLCODE31_0_FULL_CODE_31_0_RESETVAL            (0x00000000U)
#define CSL_KBD_FULLCODE31_0_FULL_CODE_31_0_MAX                 (0xffffffffU)

#define CSL_KBD_FULLCODE31_0_RESETVAL                           (0x00000000U)

/* FULLCODE63_32 */

#define CSL_KBD_FULLCODE63_32_FULL_CODE_63_32_MASK              (0xFFFFFFFFU)
#define CSL_KBD_FULLCODE63_32_FULL_CODE_63_32_SHIFT             (0U)
#define CSL_KBD_FULLCODE63_32_FULL_CODE_63_32_RESETVAL          (0x00000000U)
#define CSL_KBD_FULLCODE63_32_FULL_CODE_63_32_MAX               (0xffffffffU)

#define CSL_KBD_FULLCODE63_32_RESETVAL                          (0x00000000U)

/* FULLCODE17_0 */

#define CSL_KBD_FULLCODE17_0_ROW0_MASK                          (0x000001FFU)
#define CSL_KBD_FULLCODE17_0_ROW0_SHIFT                         (0U)
#define CSL_KBD_FULLCODE17_0_ROW0_RESETVAL                      (0x00000000U)
#define CSL_KBD_FULLCODE17_0_ROW0_MAX                           (0x000001ffU)

#define CSL_KBD_FULLCODE17_0_ROW1_MASK                          (0x01FF0000U)
#define CSL_KBD_FULLCODE17_0_ROW1_SHIFT                         (16U)
#define CSL_KBD_FULLCODE17_0_ROW1_RESETVAL                      (0x00000000U)
#define CSL_KBD_FULLCODE17_0_ROW1_MAX                           (0x000001ffU)

#define CSL_KBD_FULLCODE17_0_RESETVAL                           (0x00000000U)

/* FULLCODE35_18 */

#define CSL_KBD_FULLCODE35_18_ROW2_MASK                         (0x000001FFU)
#define CSL_KBD_FULLCODE35_18_ROW2_SHIFT                        (0U)
#define CSL_KBD_FULLCODE35_18_ROW2_RESETVAL                     (0x00000000U)
#define CSL_KBD_FULLCODE35_18_ROW2_MAX                          (0x000001ffU)

#define CSL_KBD_FULLCODE35_18_ROW3_MASK                         (0x01FF0000U)
#define CSL_KBD_FULLCODE35_18_ROW3_SHIFT                        (16U)
#define CSL_KBD_FULLCODE35_18_ROW3_RESETVAL                     (0x00000000U)
#define CSL_KBD_FULLCODE35_18_ROW3_MAX                          (0x000001ffU)

#define CSL_KBD_FULLCODE35_18_RESETVAL                          (0x00000000U)

/* FULLCODE53_36 */

#define CSL_KBD_FULLCODE53_36_ROW4_MASK                         (0x000001FFU)
#define CSL_KBD_FULLCODE53_36_ROW4_SHIFT                        (0U)
#define CSL_KBD_FULLCODE53_36_ROW4_RESETVAL                     (0x00000000U)
#define CSL_KBD_FULLCODE53_36_ROW4_MAX                          (0x000001ffU)

#define CSL_KBD_FULLCODE53_36_ROW5_MASK                         (0x01FF0000U)
#define CSL_KBD_FULLCODE53_36_ROW5_SHIFT                        (16U)
#define CSL_KBD_FULLCODE53_36_ROW5_RESETVAL                     (0x00000000U)
#define CSL_KBD_FULLCODE53_36_ROW5_MAX                          (0x000001ffU)

#define CSL_KBD_FULLCODE53_36_RESETVAL                          (0x00000000U)

/* FULLCODE71_54 */

#define CSL_KBD_FULLCODE71_54_ROW6_MASK                         (0x000001FFU)
#define CSL_KBD_FULLCODE71_54_ROW6_SHIFT                        (0U)
#define CSL_KBD_FULLCODE71_54_ROW6_RESETVAL                     (0x00000000U)
#define CSL_KBD_FULLCODE71_54_ROW6_MAX                          (0x000001ffU)

#define CSL_KBD_FULLCODE71_54_ROW7_MASK                         (0x01FF0000U)
#define CSL_KBD_FULLCODE71_54_ROW7_SHIFT                        (16U)
#define CSL_KBD_FULLCODE71_54_ROW7_RESETVAL                     (0x00000000U)
#define CSL_KBD_FULLCODE71_54_ROW7_MAX                          (0x000001ffU)

#define CSL_KBD_FULLCODE71_54_RESETVAL                          (0x00000000U)

/* FULLCODE80_72 */

#define CSL_KBD_FULLCODE80_72_ROW8_MASK                         (0x000001FFU)
#define CSL_KBD_FULLCODE80_72_ROW8_SHIFT                        (0U)
#define CSL_KBD_FULLCODE80_72_ROW8_RESETVAL                     (0x00000000U)
#define CSL_KBD_FULLCODE80_72_ROW8_MAX                          (0x000001ffU)

#define CSL_KBD_FULLCODE80_72_RESETVAL                          (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
