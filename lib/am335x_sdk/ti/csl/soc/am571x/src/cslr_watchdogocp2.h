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
#ifndef CSLR_WATCHDOGOCP2_H
#define CSLR_WATCHDOGOCP2_H

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
    volatile Uint32 WIDR;
    volatile Uint8  RSVD0[12];
    volatile Uint32 WDSC;
    volatile Uint32 WDST;
    volatile Uint32 WISR;
    volatile Uint32 WIER;
    volatile Uint32 WWER;
    volatile Uint32 WCLR;
    volatile Uint32 WCRR;
    volatile Uint32 WLDR;
    volatile Uint32 WTGR;
    volatile Uint32 WWPS;
    volatile Uint8  RSVD1[12];
    volatile Uint32 WDLY;
    volatile Uint32 WSPR;
    volatile Uint8  RSVD2[4];
    volatile Uint32 WIRQEOI;
    volatile Uint32 WIRQSTATRAW;
    volatile Uint32 WIRQSTAT;
    volatile Uint32 WIRQENSET;
    volatile Uint32 WIRQENCLR;
    volatile Uint32 WIRQWAKEEN;
} CSL_watchdogocp2Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* IP Revision Identifier This allows a PID showing X.Y.R in silicon to relate
 * the RTL release with a (close-to-correct) spec version X.Y.S. */
#define CSL_WATCHDOGOCP2_WIDR                                   (0x0U)

/* This register controls the various parameters of the OCP interface */
#define CSL_WATCHDOGOCP2_WDSC                                   (0x10U)

/* This register provides status information about the module */
#define CSL_WATCHDOGOCP2_WDST                                   (0x14U)

/* This register shows which interrupt events are pending inside the module */
#define CSL_WATCHDOGOCP2_WISR                                   (0x18U)

/* This register controls (enable/disable) the interrupt events */
#define CSL_WATCHDOGOCP2_WIER                                   (0x1CU)

/* This register controls (enable/disable) the wakeup events */
#define CSL_WATCHDOGOCP2_WWER                                   (0x20U)

/* This register controls the prescaler stage of the counter */
#define CSL_WATCHDOGOCP2_WCLR                                   (0x24U)

/* This register holds the value of the internal counter */
#define CSL_WATCHDOGOCP2_WCRR                                   (0x28U)

/* This register holds the timer's load value */
#define CSL_WATCHDOGOCP2_WLDR                                   (0x2CU)

/* Writing a different value than the one alredy written in this register does
 * a watchdog counter reload */
#define CSL_WATCHDOGOCP2_WTGR                                   (0x30U)

/* This register contains the write posting bits for all write-able functional
 * registers */
#define CSL_WATCHDOGOCP2_WWPS                                   (0x34U)

/* This register holds the delay value that controls the internal pre-overflow
 * event detection */
#define CSL_WATCHDOGOCP2_WDLY                                   (0x44U)

/* This register holds the start-stop value that controls the internal
 * start-stop fsm */
#define CSL_WATCHDOGOCP2_WSPR                                   (0x48U)

/* Software End Of Interrupt */
#define CSL_WATCHDOGOCP2_WIRQEOI                                (0x50U)

/* IRQ unmasked status, status set Per-event raw interrupt status vector, line
 * #0. Raw status is set even if event is not enabled. Write 1 to set the
 * (raw) status, mostly for debug. */
#define CSL_WATCHDOGOCP2_WIRQSTATRAW                            (0x54U)

/* IRQ masked status, status clear Per-event "enabled" interrupt status
 * vector, line #0. Enabled status isn't set unless event is enabled. Write 1
 * to clear the status after interrupt has been serviced (raw status gets
 * cleared, i.e. even if not enabled). */
#define CSL_WATCHDOGOCP2_WIRQSTAT                               (0x58U)

/* IRQ enable set Per-event interrupt enable bit vector, line #0. Write 1 to
 * set (enable interrupt). Readout equal to corresponding _CLR register. */
#define CSL_WATCHDOGOCP2_WIRQENSET                              (0x5CU)

/* IRQ enable clear Per-event interrupt enable bit vector, line #0. Write 1 to
 * clear (disable interrupt). Readout equal to corresponding _SET register. */
#define CSL_WATCHDOGOCP2_WIRQENCLR                              (0x60U)

/* This register controls (enable/disable) the wakeup events */
#define CSL_WATCHDOGOCP2_WIRQWAKEEN                             (0x64U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* WIDR */

#define CSL_WATCHDOGOCP2_WIDR_MINOR_MASK                        (0x0000003FU)
#define CSL_WATCHDOGOCP2_WIDR_MINOR_SHIFT                       (0U)
#define CSL_WATCHDOGOCP2_WIDR_MINOR_RESETVAL                    (0x00000000U)
#define CSL_WATCHDOGOCP2_WIDR_MINOR_MAX                         (0x0000003fU)

#define CSL_WATCHDOGOCP2_WIDR_CUSTOM_MASK                       (0x000000C0U)
#define CSL_WATCHDOGOCP2_WIDR_CUSTOM_SHIFT                      (6U)
#define CSL_WATCHDOGOCP2_WIDR_CUSTOM_RESETVAL                   (0x00000000U)
#define CSL_WATCHDOGOCP2_WIDR_CUSTOM_MAX                        (0x00000003U)

#define CSL_WATCHDOGOCP2_WIDR_MAJOR_MASK                        (0x00000700U)
#define CSL_WATCHDOGOCP2_WIDR_MAJOR_SHIFT                       (8U)
#define CSL_WATCHDOGOCP2_WIDR_MAJOR_RESETVAL                    (0x00000005U)
#define CSL_WATCHDOGOCP2_WIDR_MAJOR_MAX                         (0x00000007U)

#define CSL_WATCHDOGOCP2_WIDR_RTL_MASK                          (0x0000F800U)
#define CSL_WATCHDOGOCP2_WIDR_RTL_SHIFT                         (11U)
#define CSL_WATCHDOGOCP2_WIDR_RTL_RESETVAL                      (0x00000001U)
#define CSL_WATCHDOGOCP2_WIDR_RTL_MAX                           (0x0000001fU)

#define CSL_WATCHDOGOCP2_WIDR_FUNC_MASK                         (0x0FFF0000U)
#define CSL_WATCHDOGOCP2_WIDR_FUNC_SHIFT                        (16U)
#define CSL_WATCHDOGOCP2_WIDR_FUNC_RESETVAL                     (0x0000002aU)
#define CSL_WATCHDOGOCP2_WIDR_FUNC_MAX                          (0x00000fffU)

#define CSL_WATCHDOGOCP2_WIDR_SCHEME_MASK                       (0xC0000000U)
#define CSL_WATCHDOGOCP2_WIDR_SCHEME_SHIFT                      (30U)
#define CSL_WATCHDOGOCP2_WIDR_SCHEME_RESETVAL                   (0x00000001U)
#define CSL_WATCHDOGOCP2_WIDR_SCHEME_MAX                        (0x00000003U)

#define CSL_WATCHDOGOCP2_WIDR_RESETVAL                          (0x502a0d00U)

/* WDSC */

#define CSL_WATCHDOGOCP2_WDSC_SOFTRESET_MASK                    (0x00000002U)
#define CSL_WATCHDOGOCP2_WDSC_SOFTRESET_SHIFT                   (1U)
#define CSL_WATCHDOGOCP2_WDSC_SOFTRESET_RESETVAL                (0x00000000U)
#define CSL_WATCHDOGOCP2_WDSC_SOFTRESET_NOACTION                (0x00000000U)
#define CSL_WATCHDOGOCP2_WDSC_SOFTRESET_RESETCMD                (0x00000001U)
#define CSL_WATCHDOGOCP2_WDSC_SOFTRESET_RESETONGOING            (0x00000001U)
#define CSL_WATCHDOGOCP2_WDSC_SOFTRESET_RESETCOMPLETED          (0x00000000U)

#define CSL_WATCHDOGOCP2_WDSC_IDLEMODE_MASK                     (0x00000018U)
#define CSL_WATCHDOGOCP2_WDSC_IDLEMODE_SHIFT                    (3U)
#define CSL_WATCHDOGOCP2_WDSC_IDLEMODE_RESETVAL                 (0x00000002U)
#define CSL_WATCHDOGOCP2_WDSC_IDLEMODE_FORCEIDLE                (0x00000000U)
#define CSL_WATCHDOGOCP2_WDSC_IDLEMODE_NOIDLE                   (0x00000001U)
#define CSL_WATCHDOGOCP2_WDSC_IDLEMODE_SMARTIDLE                (0x00000002U)
#define CSL_WATCHDOGOCP2_WDSC_IDLEMODE_SMARTIDLEWAKEUP          (0x00000003U)

#define CSL_WATCHDOGOCP2_WDSC_EMUFREE_MASK                      (0x00000020U)
#define CSL_WATCHDOGOCP2_WDSC_EMUFREE_SHIFT                     (5U)
#define CSL_WATCHDOGOCP2_WDSC_EMUFREE_RESETVAL                  (0x00000000U)
#define CSL_WATCHDOGOCP2_WDSC_EMUFREE_DISABLED                  (0x00000000U)
#define CSL_WATCHDOGOCP2_WDSC_EMUFREE_ENABLED                   (0x00000001U)

#define CSL_WATCHDOGOCP2_WDSC_RESETVAL                          (0x00000010U)

/* WDST */

#define CSL_WATCHDOGOCP2_WDST_RESETDONE_MASK                    (0x00000001U)
#define CSL_WATCHDOGOCP2_WDST_RESETDONE_SHIFT                   (0U)
#define CSL_WATCHDOGOCP2_WDST_RESETDONE_RESETVAL                (0x00000001U)
#define CSL_WATCHDOGOCP2_WDST_RESETDONE_ONGOING                 (0x00000000U)
#define CSL_WATCHDOGOCP2_WDST_RESETDONE_RESETDONE               (0x00000001U)

#define CSL_WATCHDOGOCP2_WDST_RESETVAL                          (0x00000001U)

/* WISR */

#define CSL_WATCHDOGOCP2_WISR_OVF_IT_FLAG_MASK                  (0x00000001U)
#define CSL_WATCHDOGOCP2_WISR_OVF_IT_FLAG_SHIFT                 (0U)
#define CSL_WATCHDOGOCP2_WISR_OVF_IT_FLAG_RESETVAL              (0x00000000U)
#define CSL_WATCHDOGOCP2_WISR_OVF_IT_FLAG_READ_0                (0x00000000U)
#define CSL_WATCHDOGOCP2_WISR_OVF_IT_FLAG_READ_1                (0x00000001U)
#define CSL_WATCHDOGOCP2_WISR_OVF_IT_FLAG_WRITE_0               (0x00000000U)
#define CSL_WATCHDOGOCP2_WISR_OVF_IT_FLAG_WRITE_1               (0x00000001U)

#define CSL_WATCHDOGOCP2_WISR_DLY_IT_FLAG_MASK                  (0x00000002U)
#define CSL_WATCHDOGOCP2_WISR_DLY_IT_FLAG_SHIFT                 (1U)
#define CSL_WATCHDOGOCP2_WISR_DLY_IT_FLAG_RESETVAL              (0x00000000U)
#define CSL_WATCHDOGOCP2_WISR_DLY_IT_FLAG_READ_0                (0x00000000U)
#define CSL_WATCHDOGOCP2_WISR_DLY_IT_FLAG_READ_1                (0x00000001U)
#define CSL_WATCHDOGOCP2_WISR_DLY_IT_FLAG_WRITE_0               (0x00000000U)
#define CSL_WATCHDOGOCP2_WISR_DLY_IT_FLAG_WRITE_1               (0x00000001U)

#define CSL_WATCHDOGOCP2_WISR_RESETVAL                          (0x00000000U)

/* WIER */

#define CSL_WATCHDOGOCP2_WIER_OVF_IT_ENA_MASK                   (0x00000001U)
#define CSL_WATCHDOGOCP2_WIER_OVF_IT_ENA_SHIFT                  (0U)
#define CSL_WATCHDOGOCP2_WIER_OVF_IT_ENA_RESETVAL               (0x00000000U)
#define CSL_WATCHDOGOCP2_WIER_OVF_IT_ENA_DISABLED               (0x00000000U)
#define CSL_WATCHDOGOCP2_WIER_OVF_IT_ENA_ENABLED                (0x00000001U)

#define CSL_WATCHDOGOCP2_WIER_DLY_IT_ENA_MASK                   (0x00000002U)
#define CSL_WATCHDOGOCP2_WIER_DLY_IT_ENA_SHIFT                  (1U)
#define CSL_WATCHDOGOCP2_WIER_DLY_IT_ENA_RESETVAL               (0x00000000U)
#define CSL_WATCHDOGOCP2_WIER_DLY_IT_ENA_DISABLED               (0x00000000U)
#define CSL_WATCHDOGOCP2_WIER_DLY_IT_ENA_ENABLED                (0x00000001U)

#define CSL_WATCHDOGOCP2_WIER_RESETVAL                          (0x00000000U)

/* WWER */

#define CSL_WATCHDOGOCP2_WWER_OVF_WK_ENA_MASK                   (0x00000001U)
#define CSL_WATCHDOGOCP2_WWER_OVF_WK_ENA_SHIFT                  (0U)
#define CSL_WATCHDOGOCP2_WWER_OVF_WK_ENA_RESETVAL               (0x00000000U)
#define CSL_WATCHDOGOCP2_WWER_OVF_WK_ENA_DISABLED               (0x00000000U)
#define CSL_WATCHDOGOCP2_WWER_OVF_WK_ENA_ENABLED                (0x00000001U)

#define CSL_WATCHDOGOCP2_WWER_DLY_WK_ENA_MASK                   (0x00000002U)
#define CSL_WATCHDOGOCP2_WWER_DLY_WK_ENA_SHIFT                  (1U)
#define CSL_WATCHDOGOCP2_WWER_DLY_WK_ENA_RESETVAL               (0x00000000U)
#define CSL_WATCHDOGOCP2_WWER_DLY_WK_ENA_DISABLED               (0x00000000U)
#define CSL_WATCHDOGOCP2_WWER_DLY_WK_ENA_ENABLED                (0x00000001U)

#define CSL_WATCHDOGOCP2_WWER_RESETVAL                          (0x00000000U)

/* WCLR */

#define CSL_WATCHDOGOCP2_WCLR_PTV_MASK                          (0x0000001CU)
#define CSL_WATCHDOGOCP2_WCLR_PTV_SHIFT                         (2U)
#define CSL_WATCHDOGOCP2_WCLR_PTV_RESETVAL                      (0x00000000U)
#define CSL_WATCHDOGOCP2_WCLR_PTV_MAX                           (0x00000007U)

#define CSL_WATCHDOGOCP2_WCLR_PRE_MASK                          (0x00000020U)
#define CSL_WATCHDOGOCP2_WCLR_PRE_SHIFT                         (5U)
#define CSL_WATCHDOGOCP2_WCLR_PRE_RESETVAL                      (0x00000001U)
#define CSL_WATCHDOGOCP2_WCLR_PRE_DISABLED                      (0x00000000U)
#define CSL_WATCHDOGOCP2_WCLR_PRE_ENABLED                       (0x00000001U)

#define CSL_WATCHDOGOCP2_WCLR_RESETVAL                          (0x00000020U)

/* WCRR */

#define CSL_WATCHDOGOCP2_WCRR_TIMER_COUNTER_MASK                (0xFFFFFFFFU)
#define CSL_WATCHDOGOCP2_WCRR_TIMER_COUNTER_SHIFT               (0U)
#define CSL_WATCHDOGOCP2_WCRR_TIMER_COUNTER_RESETVAL            (0x00000000U)
#define CSL_WATCHDOGOCP2_WCRR_TIMER_COUNTER_MAX                 (0xffffffffU)

#define CSL_WATCHDOGOCP2_WCRR_RESETVAL                          (0x00000000U)

/* WLDR */

#define CSL_WATCHDOGOCP2_WLDR_TIMER_LOAD_MASK                   (0xFFFFFFFFU)
#define CSL_WATCHDOGOCP2_WLDR_TIMER_LOAD_SHIFT                  (0U)
#define CSL_WATCHDOGOCP2_WLDR_TIMER_LOAD_RESETVAL               (0x00000000U)
#define CSL_WATCHDOGOCP2_WLDR_TIMER_LOAD_MAX                    (0xffffffffU)

#define CSL_WATCHDOGOCP2_WLDR_RESETVAL                          (0x00000000U)

/* WTGR */

#define CSL_WATCHDOGOCP2_WTGR_TTGR_VALUE_MASK                   (0xFFFFFFFFU)
#define CSL_WATCHDOGOCP2_WTGR_TTGR_VALUE_SHIFT                  (0U)
#define CSL_WATCHDOGOCP2_WTGR_TTGR_VALUE_RESETVAL               (0x00000000U)
#define CSL_WATCHDOGOCP2_WTGR_TTGR_VALUE_MAX                    (0xffffffffU)

#define CSL_WATCHDOGOCP2_WTGR_RESETVAL                          (0x00000000U)

/* WWPS */

#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCLR_MASK                  (0x00000001U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCLR_SHIFT                 (0U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCLR_RESETVAL              (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCLR_READY                 (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCLR_PENDING               (0x00000001U)

#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WTGR_MASK                  (0x00000008U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WTGR_SHIFT                 (3U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WTGR_RESETVAL              (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WTGR_READY                 (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WTGR_PENDING               (0x00000001U)

#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WSPR_MASK                  (0x00000010U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WSPR_SHIFT                 (4U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WSPR_RESETVAL              (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WSPR_READY                 (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WSPR_PENDING               (0x00000001U)

#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WDLY_MASK                  (0x00000020U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WDLY_SHIFT                 (5U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WDLY_RESETVAL              (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WDLY_READY                 (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WDLY_PENDING               (0x00000001U)

#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCRR_MASK                  (0x00000002U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCRR_SHIFT                 (1U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCRR_RESETVAL              (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCRR_READY                 (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WCRR_PENDING               (0x00000001U)

#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WLDR_MASK                  (0x00000004U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WLDR_SHIFT                 (2U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WLDR_RESETVAL              (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WLDR_READY                 (0x00000000U)
#define CSL_WATCHDOGOCP2_WWPS_W_PEND_WLDR_PENDING               (0x00000001U)

#define CSL_WATCHDOGOCP2_WWPS_RESETVAL                          (0x00000000U)

/* WDLY */

#define CSL_WATCHDOGOCP2_WDLY_WDLY_VALUE_MASK                   (0xFFFFFFFFU)
#define CSL_WATCHDOGOCP2_WDLY_WDLY_VALUE_SHIFT                  (0U)
#define CSL_WATCHDOGOCP2_WDLY_WDLY_VALUE_RESETVAL               (0x00000000U)
#define CSL_WATCHDOGOCP2_WDLY_WDLY_VALUE_MAX                    (0xffffffffU)

#define CSL_WATCHDOGOCP2_WDLY_RESETVAL                          (0x00000000U)

/* WSPR */

#define CSL_WATCHDOGOCP2_WSPR_WSPR_VALUE_MASK                   (0xFFFFFFFFU)
#define CSL_WATCHDOGOCP2_WSPR_WSPR_VALUE_SHIFT                  (0U)
#define CSL_WATCHDOGOCP2_WSPR_WSPR_VALUE_RESETVAL               (0x00000000U)
#define CSL_WATCHDOGOCP2_WSPR_WSPR_VALUE_MAX                    (0xffffffffU)

#define CSL_WATCHDOGOCP2_WSPR_RESETVAL                          (0x00000000U)

/* WIRQEOI */

#define CSL_WATCHDOGOCP2_WIRQEOI_LINE_NUMBER_MASK               (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQEOI_LINE_NUMBER_SHIFT              (0U)
#define CSL_WATCHDOGOCP2_WIRQEOI_LINE_NUMBER_RESETVAL           (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQEOI_LINE_NUMBER_MAX                (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQEOI_RESETVAL                       (0x00000000U)

/* WIRQSTATRAW */

#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_OVF_MASK             (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_OVF_SHIFT            (0U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_OVF_RESETVAL         (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_OVF_READ_0           (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_OVF_READ_1           (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_OVF_WRITE_0          (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_OVF_WRITE_1          (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_DLY_MASK             (0x00000002U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_DLY_SHIFT            (1U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_DLY_RESETVAL         (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_DLY_READ_0           (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_DLY_READ_1           (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_DLY_WRITE_0          (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTATRAW_EVENT_DLY_WRITE_1          (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQSTATRAW_RESETVAL                   (0x00000000U)

/* WIRQSTAT */

#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_OVF_MASK                (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_OVF_SHIFT               (0U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_OVF_RESETVAL            (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_OVF_READ_0              (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_OVF_READ_1              (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_OVF_WRITE_0             (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_OVF_WRITE_1             (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_DLY_MASK                (0x00000002U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_DLY_SHIFT               (1U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_DLY_RESETVAL            (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_DLY_READ_0              (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_DLY_READ_1              (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_DLY_WRITE_0             (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQSTAT_EVENT_DLY_WRITE_1             (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQSTAT_RESETVAL                      (0x00000000U)

/* WIRQENSET */

#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_OVF_MASK              (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_OVF_SHIFT             (0U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_OVF_RESETVAL          (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_OVF_READ_0            (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_OVF_READ_1            (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_OVF_WRITE_0           (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_OVF_WRITE_1           (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_DLY_MASK              (0x00000002U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_DLY_SHIFT             (1U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_DLY_RESETVAL          (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_DLY_READ_0            (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_DLY_READ_1            (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_DLY_WRITE_0           (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENSET_ENABLE_DLY_WRITE_1           (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQENSET_RESETVAL                     (0x00000000U)

/* WIRQENCLR */

#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_OVF_MASK              (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_OVF_SHIFT             (0U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_OVF_RESETVAL          (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_OVF_READ_0            (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_OVF_READ_1            (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_OVF_WRITE_0           (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_OVF_WRITE_1           (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_DLY_MASK              (0x00000002U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_DLY_SHIFT             (1U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_DLY_RESETVAL          (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_DLY_READ_0            (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_DLY_READ_1            (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_DLY_WRITE_0           (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQENCLR_ENABLE_DLY_WRITE_1           (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQENCLR_RESETVAL                     (0x00000000U)

/* WIRQWAKEEN */

#define CSL_WATCHDOGOCP2_WIRQWAKEEN_OVF_WK_ENA_MASK             (0x00000001U)
#define CSL_WATCHDOGOCP2_WIRQWAKEEN_OVF_WK_ENA_SHIFT            (0U)
#define CSL_WATCHDOGOCP2_WIRQWAKEEN_OVF_WK_ENA_RESETVAL         (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQWAKEEN_OVF_WK_ENA_DISABLED         (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQWAKEEN_OVF_WK_ENA_ENABLED          (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQWAKEEN_DLY_WK_ENA_MASK             (0x00000002U)
#define CSL_WATCHDOGOCP2_WIRQWAKEEN_DLY_WK_ENA_SHIFT            (1U)
#define CSL_WATCHDOGOCP2_WIRQWAKEEN_DLY_WK_ENA_RESETVAL         (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQWAKEEN_DLY_WK_ENA_DISABLED         (0x00000000U)
#define CSL_WATCHDOGOCP2_WIRQWAKEEN_DLY_WK_ENA_ENABLED          (0x00000001U)

#define CSL_WATCHDOGOCP2_WIRQWAKEEN_RESETVAL                    (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
