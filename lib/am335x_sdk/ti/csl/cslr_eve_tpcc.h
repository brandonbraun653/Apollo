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
#ifndef CSLR_EVETPCC_H_
#define CSLR_EVETPCC_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for QRAEN
**************************************************************************/
typedef struct {
    volatile Uint32 QRAEN[8];
} CSL_EvetpccQraenRegs;


/**************************************************************************
* Register Overlay Structure for CONFIG
**************************************************************************/
typedef struct {
    volatile Uint32 QSTATN[2];
    volatile Uint8  RSVD0[24];
    volatile Uint32 QWMTHRA;
    volatile Uint32 QWMTHRB;
    volatile Uint8  RSVD1[24];
    volatile Uint32 CCSTAT;
    volatile Uint8  RSVD2[188];
    volatile Uint32 AETCTL;
    volatile Uint32 AETSTAT;
    volatile Uint32 AETCMD;
    volatile Uint8  RSVD3[244];
    volatile Uint32 MPFAR;
    volatile Uint32 MPFSR;
    volatile Uint32 MPFCR;
    volatile Uint32 MPPAG;
    volatile Uint32 MPPAN[8];
    volatile Uint8  RSVD4[2000];
    volatile Uint32 ER;
    volatile Uint32 ERH;
    volatile Uint32 ECR;
    volatile Uint32 ECRH;
    volatile Uint32 ESR;
    volatile Uint32 ESRH;
    volatile Uint32 CER;
    volatile Uint32 CERH;
    volatile Uint32 EER;
    volatile Uint32 EERH;
    volatile Uint32 EECR;
    volatile Uint32 EECRH;
    volatile Uint32 EESR;
    volatile Uint32 EESRH;
    volatile Uint32 SER;
    volatile Uint32 SERH;
    volatile Uint32 SECR;
    volatile Uint32 SECRH;
    volatile Uint8  RSVD5[8];
    volatile Uint32 IER;
    volatile Uint32 IERH;
    volatile Uint32 IECR;
    volatile Uint32 IECRH;
    volatile Uint32 IESR;
    volatile Uint32 IESRH;
    volatile Uint32 IPR;
    volatile Uint32 IPRH;
    volatile Uint32 ICR;
    volatile Uint32 ICRH;
    volatile Uint32 IEVAL;
    volatile Uint8  RSVD6[4];
    volatile Uint32 QER;
    volatile Uint32 QEER;
    volatile Uint32 QEECR;
    volatile Uint32 QEESR;
    volatile Uint32 QSER;
    volatile Uint32 QSECR;
} CSL_EvetpccConfigRegs;


/**************************************************************************
* Register Overlay Structure for SHADOW_N
**************************************************************************/
typedef struct {
    volatile Uint32 ER_RN;
    volatile Uint32 ERH_RN;
    volatile Uint32 ECR_RN;
    volatile Uint32 ECRH_RN;
    volatile Uint32 ESR_RN;
    volatile Uint32 ESRH_RN;
    volatile Uint32 CER_RN;
    volatile Uint32 CERH_RN;
    volatile Uint32 EER_RN;
    volatile Uint32 EERH_RN;
    volatile Uint32 EECR_RN;
    volatile Uint32 EECRH_RN;
    volatile Uint32 EESR_RN;
    volatile Uint32 EESRH_RN;
    volatile Uint32 SER_RN;
    volatile Uint32 SERH_RN;
    volatile Uint32 SECR_RN;
    volatile Uint32 SECRH_RN;
    volatile Uint8  RSVD0[8];
    volatile Uint32 IER_RN;
    volatile Uint32 IERH_RN;
    volatile Uint32 IECR_RN;
    volatile Uint32 IECRH_RN;
    volatile Uint32 IESR_RN;
    volatile Uint32 IESRH_RN;
    volatile Uint32 IPR_RN;
    volatile Uint32 IPRH_RN;
    volatile Uint32 ICR_RN;
    volatile Uint32 ICRH_RN;
    volatile Uint32 IEVAL_RN;
    volatile Uint8  RSVD1[4];
    volatile Uint32 QER_RN;
    volatile Uint32 QEER_RN;
    volatile Uint32 QEECR_RN;
    volatile Uint32 QEESR_RN;
    volatile Uint32 QSER_RN;
    volatile Uint32 QSECR_RN;
    volatile Uint8  RSVD2[360];
} CSL_EvetpccShadow_nRegs;


/**************************************************************************
* Register Overlay Structure for PARAMSET
**************************************************************************/
typedef struct {
    volatile Uint32 OPT;
    volatile Uint32 SRC;
    volatile Uint32 ABCNT;
    volatile Uint32 DST;
    volatile Uint32 BIDX;
    volatile Uint32 LNK;
    volatile Uint32 CIDX;
    volatile Uint32 CCNT;
} CSL_EvetpccParamsetRegs;


/**************************************************************************
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 PID;
    volatile Uint32 CCCFG;
    volatile Uint8  RSVD0[244];
    volatile Uint32 CLKGDIS;
    volatile Uint32 DCHMAPN[16];
    volatile Uint8  RSVD1[192];
    volatile Uint32 QCHMAPN[8];
    volatile Uint8  RSVD2[32];
    volatile Uint32 DMAQNUMN[2];
    volatile Uint8  RSVD3[24];
    volatile Uint32 QDMAQNUM;
    volatile Uint8  RSVD4[28];
    volatile Uint32 QUETCMAP;
    volatile Uint32 QUEPRI;
    volatile Uint8  RSVD5[120];
    volatile Uint32 EMR;
    volatile Uint32 EMRH;
    volatile Uint32 EMCR;
    volatile Uint32 EMCRH;
    volatile Uint32 QEMR;
    volatile Uint32 QEMCR;
    volatile Uint32 CCERR;
    volatile Uint32 CCERRCLR;
    volatile Uint32 EEVAL;
    volatile Uint8  RSVD6[92];
    CSL_EvetpccQraenRegs	QRAEN;
    volatile Uint8  RSVD7[608];
    CSL_EvetpccConfigRegs	CONFIG;
    volatile Uint8  RSVD8[3944];
    CSL_EvetpccShadow_nRegs	SHADOW_N[8];
    volatile Uint8  RSVD9[4096];
    CSL_EvetpccParamsetRegs	PARAMSET[128];
} CSL_EveTpccRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* Peripheral ID Register */
#define CSL_EVETPCC_PID                                         (0x0U)

/* CC Configuration Register */
#define CSL_EVETPCC_CCCFG                                       (0x4U)

/* Auto Clock Gate Disable */
#define CSL_EVETPCC_CLKGDIS                                     (0xFCU)

/* DMA Channel N Mapping Register */
#define CSL_EVETPCC_DCHMAPN(i)                                  (0x100U + ((i) * (0x4U)))

/* QDMA Channel N Mapping Register */
#define CSL_EVETPCC_QCHMAPN(i)                                  (0x200U + ((i) * (0x4U)))

/* DMA Queue Number Register n Contains the Event queue number to be used for
 * the corresponding DMA Channel. */
#define CSL_EVETPCC_DMAQNUMN(i)                                 (0x240U + ((i) * (0x4U)))

/* QDMA Queue Number Register Contains the Event queue number to be used for
 * the corresponding QDMA Channel. */
#define CSL_EVETPCC_QDMAQNUM                                    (0x260U)

/* Queue to TC Mapping */
#define CSL_EVETPCC_QUETCMAP                                    (0x280U)

/* Queue Priority */
#define CSL_EVETPCC_QUEPRI                                      (0x284U)

/* Event Missed Register: The Event Missed register is set if 2 events are
 * received without the first event being cleared or if a Null TR is serviced.
 * Chained events (CER), Set Events (ESR), and normal events (ER) are treated
 * individually. If any bit in the EMR register is set (and all errors
 * (including QEMR/CCERR) were previously clear), then an error will be
 * signaled with TPCC error interrupt. */
#define CSL_EVETPCC_EMR                                         (0x300U)

/* Event Missed Register (High Part): The Event Missed register is set if 2
 * events are received without the first event being cleared or if a Null TR
 * is serviced. Chained events (CER), Set Events (ESR), and normal events (ER)
 * are treated individually. If any bit in the EMR register is set (and all
 * errors (including QEMR/CCERR) were previously clear), then an error will be
 * signaled with TPCC error interrupt. */
#define CSL_EVETPCC_EMRH                                        (0x304U)

/* Event Missed Clear Register: CPU write of '1' to the EMCR.En bit causes the
 * EMR.En bit to be cleared. CPU write of '0' has no effect.. All error bits
 * must be cleared before additional error interrupts will be asserted by CC. */
#define CSL_EVETPCC_EMCR                                        (0x308U)

/* Event Missed Clear Register (High Part): CPU write of '1' to the EMCR.En
 * bit causes the EMR.En bit to be cleared. CPU write of '0' has no effect..
 * All error bits must be cleared before additional error interrupts will be
 * asserted by CC. */
#define CSL_EVETPCC_EMCRH                                       (0x30CU)

/* QDMA Event Missed Register: The QDMA Event Missed register is set if 2 QDMA
 * events are detected without the first event being cleared or if a Null TR
 * is serviced.. If any bit in the QEMR register is set (and all errors
 * (including EMR/CCERR) were previously clear), then an error will be
 * signaled with TPCC error interrupt. */
#define CSL_EVETPCC_QEMR                                        (0x310U)

/* QDMA Event Missed Clear Register: CPU write of '1' to the QEMCR.En bit
 * causes the QEMR.En bit to be cleared. CPU write of '0' has no effect.. All
 * error bits must be cleared before additional error interrupts will be
 * asserted by CC. */
#define CSL_EVETPCC_QEMCR                                       (0x314U)

/* CC Error Register */
#define CSL_EVETPCC_CCERR                                       (0x318U)

/* CC Error Clear Register */
#define CSL_EVETPCC_CCERRCLR                                    (0x31CU)

/* Error Eval Register */
#define CSL_EVETPCC_EEVAL                                       (0x320U)

/* QDMA Region Access enable for bit N in Region M: En = 0 : Accesses via
 * Region M address space to Bit N in any QDMA Channel Register are not
 * allowed. Reads will return 'b0 on Bit N and writes will not modify the
 * state of bit N. Enabled interrupt bits for bit N do not contribute to the
 * generation of the TPCC region M interrupt. En = 1 : Accesses via Region M
 * address space to Bit N in any QDMA Channel Register are allowed. Reads will
 * return the value from Bit N and writes will modify the state of bit N.
 * Enabled interrupt bits for bit N do contribute to the generation of the
 * TPCC region n interrupt. */
#define CSL_EVETPCC_QRAEN(i)                                    (0x380U + ((i) * (0x4U)))

/* QSTATn Register Set */
#define CSL_EVETPCC_QSTATN(i)                                   (0x600U + ((i) * (0x4U)))

/* Queue Threshold A, for Q[3:0]: CCERR.QTHRXCDn and QSTATn.THRXCD error bit
 * is set when the number of Events in QueueN at an instant in time (visible
 * via QSTATn.NUMVAL) equals or exceeds the value specified by QWMTHRA.Qn.
 * Legal values = 0x0 (ever used?) to 0x10 (ever full?) A value of 0x11
 * disables threshold errors. */
#define CSL_EVETPCC_QWMTHRA                                     (0x620U)

/* Queue Threshold B, for Q[7:4]: CCERR.QTHRXCDn and QSTATn.THRXCD error bit
 * is set when the number of Events in QueueN at an instant in time (visible
 * via QSTATn.NUMVAL) equals or exceeds the value specified by QWMTHRB.Qn.
 * Legal values = 0x0 (ever used?) to 0x10 (ever full?) A value of 0x11
 * disables threshold errors. */
#define CSL_EVETPCC_QWMTHRB                                     (0x624U)

/* CC Status Register */
#define CSL_EVETPCC_CCSTAT                                      (0x640U)

/* Advanced Event Trigger Control */
#define CSL_EVETPCC_AETCTL                                      (0x700U)

/* Advanced Event Trigger Stat */
#define CSL_EVETPCC_AETSTAT                                     (0x704U)

/* AET Command */
#define CSL_EVETPCC_AETCMD                                      (0x708U)

/* Memory Protection Fault Address */
#define CSL_EVETPCC_MPFAR                                       (0x800U)

/* Memory Protection Fault Status Register */
#define CSL_EVETPCC_MPFSR                                       (0x804U)

/* Memory Protection Fault Command Register */
#define CSL_EVETPCC_MPFCR                                       (0x808U)

/* Memory Protection Page Attribute for Global registers */
#define CSL_EVETPCC_MPPAG                                       (0x80CU)

/* MP Permission Attribute for DMA Region n */
#define CSL_EVETPCC_MPPAN(i)                                    (0x810U + ((i) * (0x4U)))

/* Event Register: If ER.En bit is set and the EER.En bit is also set, then
 * the corresponding DMA channel is prioritized vs. other pending DMA events
 * for submission to the TC. ER.En bit is set when the input event #n
 * transitions from inactive (low) to active (high), regardless of the state
 * of EER.En bit. ER.En bit is cleared when the corresponding event is
 * prioritized and serviced. If the ER.En bit is already set and a new
 * inactive to active transition is detected on the input event #n input AND
 * the corresponding bit in the EER register is set, then the corresponding
 * bit in the Event Missed Register is set. Event N can be cleared via sw by
 * writing a '1' to the ECR pseudo-register. */
#define CSL_EVETPCC_ER                                          (0x1000U)

/* Event Register (High Part): If ERH.En bit is set and the EERH.En bit is
 * also set, then the corresponding DMA channel is prioritized vs. other
 * pending DMA events for submission to the TC. ERH.En bit is set when the
 * input event #n transitions from inactive (low) to active (high), regardless
 * of the state of EERH.En bit. ER.En bit is cleared when the corresponding
 * event is prioritized and serviced. If the ERH.En bit is already set and a
 * new inactive to active transition is detected on the input event #n input
 * AND the corresponding bit in the EERH register is set, then the
 * corresponding bit in the Event Missed Register is set. Event N can be
 * cleared via sw by writing a '1' to the ECRH pseudo-register. */
#define CSL_EVETPCC_ERH                                         (0x1004U)

/* Event Clear Register: CPU write of '1' to the ECR.En bit causes the ER.En
 * bit to be cleared. CPU write of '0' has no effect. */
#define CSL_EVETPCC_ECR                                         (0x1008U)

/* Event Clear Register (High Part): CPU write of '1' to the ECRH.En bit
 * causes the ERH.En bit to be cleared. CPU write of '0' has no effect. */
#define CSL_EVETPCC_ECRH                                        (0x100CU)

/* Event Set Register: CPU write of '1' to the ESR.En bit causes the ER.En bit
 * to be set. CPU write of '0' has no effect. */
#define CSL_EVETPCC_ESR                                         (0x1010U)

/* Event Set Register (High Part) CPU write of '1' to the ESRH.En bit causes
 * the ERH.En bit to be set. CPU write of '0' has no effect. */
#define CSL_EVETPCC_ESRH                                        (0x1014U)

/* Chained Event Register: If CER.En bit is set (regardless of state of
 * EER.En), then the corresponding DMA channel is prioritized vs. other
 * pending DMA events for submission to the TC. CER.En bit is set when a
 * chaining completion code is returned from one of the 3PTCs via the
 * completion interface, or is generated internally via Early Completion path.
 * CER.En bit is cleared when the corresponding event is prioritized and
 * serviced. If the CER.En bit is already set and the corresponding chaining
 * completion code is returned from the TC, then the corresponding bit in the
 * Event Missed Register is set. CER.En cannot be set or cleared via software. */
#define CSL_EVETPCC_CER                                         (0x1018U)

/* Chained Event Register (High Part): If CERH.En bit is set (regardless of
 * state of EERH.En), then the corresponding DMA channel is prioritized vs.
 * other pending DMA events for submission to the TC. CERH.En bit is set when
 * a chaining completion code is returned from one of the 3PTCs via the
 * completion interface, or is generated internally via Early Completion path.
 * CERH.En bit is cleared when the corresponding event is prioritized and
 * serviced. If the CERH.En bit is already set and the corresponding chaining
 * completion code is returned from the TC, then the corresponding bit in the
 * Event Missed Register is set. CERH.En cannot be set or cleared via
 * software. */
#define CSL_EVETPCC_CERH                                        (0x101CU)

/* Event Enable Register: Enables DMA transfers for ER.En pending events.
 * ER.En is set based on externally asserted events (via tpcc_eventN_pi). This
 * register has no effect on Chained Event Register (CER) or Event Set
 * Register (ESR). Note that if a bit is set in ER.En while EER.En is
 * disabled, no action is taken. If EER.En is enabled at a later point (and
 * ER.En has not been cleared via SW) then the event will be recognized as a
 * valid 'TR Sync' EER.En is not directly writeable. Events can be enabled via
 * writes to EESR and can be disabled via writes to EECR register. EER.En = 0:
 * ER.En is not enabled to trigger DMA transfers. EER.En = 1: ER.En is enabled
 * to trigger DMA transfers. */
#define CSL_EVETPCC_EER                                         (0x1020U)

/* Event Enable Register (High Part): Enables DMA transfers for ERH.En pending
 * events. ERH.En is set based on externally asserted events (via
 * tpcc_eventN_pi). This register has no effect on Chained Event Register
 * (CERH) or Event Set Register (ESRH). Note that if a bit is set in ERH.En
 * while EERH.En is disabled, no action is taken. If EERH.En is enabled at a
 * later point (and ERH.En has not been cleared via SW) then the event will be
 * recognized as a valid 'TR Sync' EERH.En is not directly writeable. Events
 * can be enabled via writes to EESRH and can be disabled via writes to EECRH
 * register. EERH.En = 0: ER.En is not enabled to trigger DMA transfers.
 * EERH.En = 1: ER.En is enabled to trigger DMA transfers. */
#define CSL_EVETPCC_EERH                                        (0x1024U)

/* Event Enable Clear Register: CPU write of '1' to the EECR.En bit causes the
 * EER.En bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_EECR                                        (0x1028U)

/* Event Enable Clear Register (High Part): CPU write of '1' to the EECRH.En
 * bit causes the EERH.En bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_EECRH                                       (0x102CU)

/* Event Enable Set Register: CPU write of '1' to the EESR.En bit causes the
 * EER.En bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_EESR                                        (0x1030U)

/* Event Enable Set Register (High Part): CPU write of '1' to the EESRH.En bit
 * causes the EERH.En bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_EESRH                                       (0x1034U)

/* Secondary Event Register: The secondary event register is used along with
 * the Event Register (ER) to provide information on the state of an Event. En
 * = 0 : Event is not currently in the Event Queue. En = 1 : Event is
 * currently stored in Event Queue. Event arbiter will not prioritize
 * additional events. */
#define CSL_EVETPCC_SER                                         (0x1038U)

/* Secondary Event Register (High Part): The secondary event register is used
 * along with the Event Register (ERH) to provide information on the state of
 * an Event. En = 0 : Event is not currently in the Event Queue. En = 1 :
 * Event is currently stored in Event Queue. Event arbiter will not prioritize
 * additional events. */
#define CSL_EVETPCC_SERH                                        (0x103CU)

/* Secondary Event Clear Register: The secondary event clear register is used
 * to clear the status of the SER registers. CPU write of '1' to the SECR.En
 * bit clears the SER register. CPU write of '0' has no effect. */
#define CSL_EVETPCC_SECR                                        (0x1040U)

/* Secondary Event Clear Register (High Part): The secondary event clear
 * register is used to clear the status of the SERH registers. CPU write of
 * '1' to the SECRH.En bit clears the SERH register. CPU write of '0' has no
 * effect. */
#define CSL_EVETPCC_SECRH                                       (0x1044U)

/* Int Enable Register: IER.In is not directly writeable. Interrupts can be
 * enabled via writes to IESR and can be disabled via writes to IECR register.
 * IER.In = 0: IPR.In is NOT enabled for interrupts. IER.In = 1: IPR.In IS
 * enabled for interrupts. */
#define CSL_EVETPCC_IER                                         (0x1050U)

/* Int Enable Register (High Part): IERH.In is not directly writeable.
 * Interrupts can be enabled via writes to IESRH and can be disabled via
 * writes to IECRH register. IERH.In = 0: IPRH.In is NOT enabled for
 * interrupts. IERH.In = 1: IPRH.In IS enabled for interrupts. */
#define CSL_EVETPCC_IERH                                        (0x1054U)

/* Int Enable Clear Register: CPU write of '1' to the IECR.In bit causes the
 * IER.In bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_IECR                                        (0x1058U)

/* Int Enable Clear Register (High Part): CPU write of '1' to the IECRH.In bit
 * causes the IERH.In bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_IECRH                                       (0x105CU)

/* Int Enable Set Register: CPU write of '1' to the IESR.In bit causes the
 * IESR.In bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_IESR                                        (0x1060U)

/* Int Enable Set Register (High Part): CPU write of '1' to the IESRH.In bit
 * causes the IESRH.In bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_IESRH                                       (0x1064U)

/* Interrupt Pending Register: IPR.In bit is set when a interrupt completion
 * code with TCC of N is detected. IPR.In bit is cleared via software by
 * writing a '1' to ICR.In bit. */
#define CSL_EVETPCC_IPR                                         (0x1068U)

/* Interrupt Pending Register (High Part): IPRH.In bit is set when a interrupt
 * completion code with TCC of N is detected. IPRH.In bit is cleared via
 * software by writing a '1' to ICRH.In bit. */
#define CSL_EVETPCC_IPRH                                        (0x106CU)

/* Interrupt Clear Register: CPU write of '1' to the ICR.In bit causes the
 * IPR.In bit to be cleared. CPU write of '0' has no effect. All IPR.In bits
 * must be cleared before additional interrupts will be asserted by CC. */
#define CSL_EVETPCC_ICR                                         (0x1070U)

/* Interrupt Clear Register (High Part): CPU write of '1' to the ICRH.In bit
 * causes the IPRH.In bit to be cleared. CPU write of '0' has no effect. All
 * IPRH.In bits must be cleared before additional interrupts will be asserted
 * by CC. */
#define CSL_EVETPCC_ICRH                                        (0x1074U)

/* Interrupt Eval Register */
#define CSL_EVETPCC_IEVAL                                       (0x1078U)

/* QDMA Event Register: If QER.En bit is set, then the corresponding QDMA
 * channel is prioritized vs. other qdma events for submission to the TC.
 * QER.En bit is set when a vbus write byte matches the address defined in the
 * QCHMAPn register. QER.En bit is cleared when the corresponding event is
 * prioritized and serviced. QER.En is also cleared when user writes a '1' to
 * the QSECR.En bit. If the QER.En bit is already set and a new QDMA event is
 * detected due to user write to QDMA trigger location and QEER register is
 * set, then the corresponding bit in the QDMA Event Missed Register is set. */
#define CSL_EVETPCC_QER                                         (0x1080U)

/* QDMA Event Enable Register: Enabled/disabled QDMA address comparator for
 * QDMA Channel N. QEER.En is not directly writeable. QDMA channels can be
 * enabled via writes to QEESR and can be disabled via writes to QEECR
 * register. QEER.En = 1, The corresponding QDMA channel comparator is enabled
 * and Events will be recognized and latched in QER.En. QEER.En = 0, The
 * corresponding QDMA channel comparator is disabled. Events will not be
 * recognized/latched in QER.En. */
#define CSL_EVETPCC_QEER                                        (0x1084U)

/* QDMA Event Enable Clear Register: CPU write of '1' to the QEECR.En bit
 * causes the QEER.En bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_QEECR                                       (0x1088U)

/* QDMA Event Enable Set Register: CPU write of '1' to the QEESR.En bit causes
 * the QEESR.En bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_QEESR                                       (0x108CU)

/* QDMA Secondary Event Register: The QDMA secondary event register is used
 * along with the QDMA Event Register (QER) to provide information on the
 * state of a QDMA Event. En = 0 : Event is not currently in the Event Queue.
 * En = 1 : Event is currently stored in Event Queue. Event arbiter will not
 * prioritize additional events. */
#define CSL_EVETPCC_QSER                                        (0x1090U)

/* QDMA Secondary Event Clear Register: The secondary event clear register is
 * used to clear the status of the QSER and QER register (note that this is
 * slightly different than the SER operation, which does not clear the ER.En
 * register). CPU write of '1' to the QSECR.En bit clears the QSER.En and
 * QER.En register fields. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_QSECR                                       (0x1094U)

/* Interrupt Eval Register */
#define CSL_EVETPCC_IEVAL_RN(n)                                 (0x2078U + ((n) * (0x200U)))

/* Int Enable Set Register (High Part): CPU write of '1' to the IESRH.In bit
 * causes the IESRH.In bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_IESRH_RN(n)                                 (0x2064U + ((n) * (0x200U)))

/* Secondary Event Register: The secondary event register is used along with
 * the Event Register (ER) to provide information on the state of an Event. En
 * = 0 : Event is not currently in the Event Queue. En = 1 : Event is
 * currently stored in Event Queue. Event arbiter will not prioritize
 * additional events. */
#define CSL_EVETPCC_SER_RN(n)                                   (0x2038U + ((n) * (0x200U)))

/* Secondary Event Register (High Part): The secondary event register is used
 * along with the Event Register (ERH) to provide information on the state of
 * an Event. En = 0 : Event is not currently in the Event Queue. En = 1 :
 * Event is currently stored in Event Queue. Event arbiter will not prioritize
 * additional events. */
#define CSL_EVETPCC_SERH_RN(n)                                  (0x203CU + ((n) * (0x200U)))

/* Event Set Register: CPU write of '1' to the ESR.En bit causes the ER.En bit
 * to be set. CPU write of '0' has no effect. */
#define CSL_EVETPCC_ESR_RN(n)                                   (0x2010U + ((n) * (0x200U)))

/* Event Enable Clear Register: CPU write of '1' to the EECR.En bit causes the
 * EER.En bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_EECR_RN(n)                                  (0x2028U + ((n) * (0x200U)))

/* Event Register: If ER.En bit is set and the EER.En bit is also set, then
 * the corresponding DMA channel is prioritized vs. other pending DMA events
 * for submission to the TC. ER.En bit is set when the input event #n
 * transitions from inactive (low) to active (high), regardless of the state
 * of EER.En bit. ER.En bit is cleared when the corresponding event is
 * prioritized and serviced. If the ER.En bit is already set and a new
 * inactive to active transition is detected on the input event #n input AND
 * the corresponding bit in the EER register is set, then the corresponding
 * bit in the Event Missed Register is set. Event N can be cleared via sw by
 * writing a '1' to the ECR pseudo-register. */
#define CSL_EVETPCC_ER_RN(n)                                    (0x2000U + ((n) * (0x200U)))

/* Interrupt Clear Register (High Part): CPU write of '1' to the ICRH.In bit
 * causes the IPRH.In bit to be cleared. CPU write of '0' has no effect. All
 * IPRH.In bits must be cleared before additional interrupts will be asserted
 * by CC. */
#define CSL_EVETPCC_ICRH_RN(n)                                  (0x2074U + ((n) * (0x200U)))

/* Event Enable Clear Register (High Part): CPU write of '1' to the EECRH.En
 * bit causes the EERH.En bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_EECRH_RN(n)                                 (0x202CU + ((n) * (0x200U)))

/* Int Enable Set Register: CPU write of '1' to the IESR.In bit causes the
 * IESR.In bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_IESR_RN(n)                                  (0x2060U + ((n) * (0x200U)))

/* Secondary Event Clear Register: The secondary event clear register is used
 * to clear the status of the SER registers. CPU write of '1' to the SECR.En
 * bit clears the SER register. CPU write of '0' has no effect. */
#define CSL_EVETPCC_SECR_RN(n)                                  (0x2040U + ((n) * (0x200U)))

/* Event Enable Set Register: CPU write of '1' to the EESR.En bit causes the
 * EER.En bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_EESR_RN(n)                                  (0x2030U + ((n) * (0x200U)))

/* QDMA Event Register: If QER.En bit is set, then the corresponding QDMA
 * channel is prioritized vs. other qdma events for submission to the TC.
 * QER.En bit is set when a vbus write byte matches the address defined in the
 * QCHMAPn register. QER.En bit is cleared when the corresponding event is
 * prioritized and serviced. QER.En is also cleared when user writes a '1' to
 * the QSECR.En bit. If the QER.En bit is already set and a new QDMA event is
 * detected due to user write to QDMA trigger location and QEER register is
 * set, then the corresponding bit in the QDMA Event Missed Register is set. */
#define CSL_EVETPCC_QER_RN(n)                                   (0x2080U + ((n) * (0x200U)))

/* Secondary Event Clear Register (High Part): The secondary event clear
 * register is used to clear the status of the SERH registers. CPU write of
 * '1' to the SECRH.En bit clears the SERH register. CPU write of '0' has no
 * effect. */
#define CSL_EVETPCC_SECRH_RN(n)                                 (0x2044U + ((n) * (0x200U)))

/* Event Enable Set Register (High Part): CPU write of '1' to the EESRH.En bit
 * causes the EERH.En bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_EESRH_RN(n)                                 (0x2034U + ((n) * (0x200U)))

/* Int Enable Register: IER.In is not directly writeable. Interrupts can be
 * enabled via writes to IESR and can be disabled via writes to IECR register.
 * IER.In = 0: IPR.In is NOT enabled for interrupts. IER.In = 1: IPR.In IS
 * enabled for interrupts. */
#define CSL_EVETPCC_IER_RN(n)                                   (0x2050U + ((n) * (0x200U)))

/* QDMA Event Enable Clear Register: CPU write of '1' to the QEECR.En bit
 * causes the QEER.En bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_QEECR_RN(n)                                 (0x2088U + ((n) * (0x200U)))

/* Event Enable Register: Enables DMA transfers for ER.En pending events.
 * ER.En is set based on externally asserted events (via tpcc_eventN_pi). This
 * register has no effect on Chained Event Register (CER) or Event Set
 * Register (ESR). Note that if a bit is set in ER.En while EER.En is
 * disabled, no action is taken. If EER.En is enabled at a later point (and
 * ER.En has not been cleared via SW) then the event will be recognized as a
 * valid 'TR Sync' EER.En is not directly writeable. Events can be enabled via
 * writes to EESR and can be disabled via writes to EECR register. EER.En = 0:
 * ER.En is not enabled to trigger DMA transfers. EER.En = 1: ER.En is enabled
 * to trigger DMA transfers. */
#define CSL_EVETPCC_EER_RN(n)                                   (0x2020U + ((n) * (0x200U)))

/* Chained Event Register (High Part): If CERH.En bit is set (regardless of
 * state of EERH.En), then the corresponding DMA channel is prioritized vs.
 * other pending DMA events for submission to the TC. CERH.En bit is set when
 * a chaining completion code is returned from one of the 3PTCs via the
 * completion interface, or is generated internally via Early Completion path.
 * CERH.En bit is cleared when the corresponding event is prioritized and
 * serviced. If the CERH.En bit is already set and the corresponding chaining
 * completion code is returned from the TC, then the corresponding bit in the
 * Event Missed Register is set. CERH.En cannot be set or cleared via
 * software. */
#define CSL_EVETPCC_CERH_RN(n)                                  (0x201CU + ((n) * (0x200U)))

/* QDMA Event Enable Register: Enabled/disabled QDMA address comparator for
 * QDMA Channel N. QEER.En is not directly writeable. QDMA channels can be
 * enabled via writes to QEESR and can be disabled via writes to QEECR
 * register. QEER.En = 1, The corresponding QDMA channel comparator is enabled
 * and Events will be recognized and latched in QER.En. QEER.En = 0, The
 * corresponding QDMA channel comparator is disabled. Events will not be
 * recognized/latched in QER.En. */
#define CSL_EVETPCC_QEER_RN(n)                                  (0x2084U + ((n) * (0x200U)))

/* QDMA Secondary Event Clear Register: The secondary event clear register is
 * used to clear the status of the QSER and QER register (note that this is
 * slightly different than the SER operation, which does not clear the ER.En
 * register). CPU write of '1' to the QSECR.En bit clears the QSER.En and
 * QER.En register fields. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_QSECR_RN(n)                                 (0x2094U + ((n) * (0x200U)))

/* Event Clear Register (High Part): CPU write of '1' to the ECRH.En bit
 * causes the ERH.En bit to be cleared. CPU write of '0' has no effect. */
#define CSL_EVETPCC_ECRH_RN(n)                                  (0x200CU + ((n) * (0x200U)))

/* Interrupt Clear Register: CPU write of '1' to the ICR.In bit causes the
 * IPR.In bit to be cleared. CPU write of '0' has no effect. All IPR.In bits
 * must be cleared before additional interrupts will be asserted by CC. */
#define CSL_EVETPCC_ICR_RN(n)                                   (0x2070U + ((n) * (0x200U)))

/* Interrupt Pending Register (High Part): IPRH.In bit is set when a interrupt
 * completion code with TCC of N is detected. IPRH.In bit is cleared via
 * software by writing a '1' to ICRH.In bit. */
#define CSL_EVETPCC_IPRH_RN(n)                                  (0x206CU + ((n) * (0x200U)))

/* Chained Event Register: If CER.En bit is set (regardless of state of
 * EER.En), then the corresponding DMA channel is prioritized vs. other
 * pending DMA events for submission to the TC. CER.En bit is set when a
 * chaining completion code is returned from one of the 3PTCs via the
 * completion interface, or is generated internally via Early Completion path.
 * CER.En bit is cleared when the corresponding event is prioritized and
 * serviced. If the CER.En bit is already set and the corresponding chaining
 * completion code is returned from the TC, then the corresponding bit in the
 * Event Missed Register is set. CER.En cannot be set or cleared via software. */
#define CSL_EVETPCC_CER_RN(n)                                   (0x2018U + ((n) * (0x200U)))

/* Int Enable Clear Register (High Part): CPU write of '1' to the IECRH.In bit
 * causes the IERH.In bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_IECRH_RN(n)                                 (0x205CU + ((n) * (0x200U)))

/* Int Enable Clear Register: CPU write of '1' to the IECR.In bit causes the
 * IER.In bit to be cleared. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_IECR_RN(n)                                  (0x2058U + ((n) * (0x200U)))

/* QDMA Secondary Event Register: The QDMA secondary event register is used
 * along with the QDMA Event Register (QER) to provide information on the
 * state of a QDMA Event. En = 0 : Event is not currently in the Event Queue.
 * En = 1 : Event is currently stored in Event Queue. Event arbiter will not
 * prioritize additional events. */
#define CSL_EVETPCC_QSER_RN(n)                                  (0x2090U + ((n) * (0x200U)))

/* Int Enable Register (High Part): IERH.In is not directly writeable.
 * Interrupts can be enabled via writes to IESRH and can be disabled via
 * writes to IECRH register. IERH.In = 0: IPRH.In is NOT enabled for
 * interrupts. IERH.In = 1: IPRH.In IS enabled for interrupts. */
#define CSL_EVETPCC_IERH_RN(n)                                  (0x2054U + ((n) * (0x200U)))

/* Event Clear Register: CPU write of '1' to the ECR.En bit causes the ER.En
 * bit to be cleared. CPU write of '0' has no effect. */
#define CSL_EVETPCC_ECR_RN(n)                                   (0x2008U + ((n) * (0x200U)))

/* Event Enable Register (High Part): Enables DMA transfers for ERH.En pending
 * events. ERH.En is set based on externally asserted events (via
 * tpcc_eventN_pi). This register has no effect on Chained Event Register
 * (CERH) or Event Set Register (ESRH). Note that if a bit is set in ERH.En
 * while EERH.En is disabled, no action is taken. If EERH.En is enabled at a
 * later point (and ERH.En has not been cleared via SW) then the event will be
 * recognized as a valid 'TR Sync' EERH.En is not directly writeable. Events
 * can be enabled via writes to EESRH and can be disabled via writes to EECRH
 * register. EERH.En = 0: ER.En is not enabled to trigger DMA transfers.
 * EERH.En = 1: ER.En is enabled to trigger DMA transfers. */
#define CSL_EVETPCC_EERH_RN(n)                                  (0x2024U + ((n) * (0x200U)))

/* Interrupt Pending Register: IPR.In bit is set when a interrupt completion
 * code with TCC of N is detected. IPR.In bit is cleared via software by
 * writing a '1' to ICR.In bit. */
#define CSL_EVETPCC_IPR_RN(n)                                   (0x2068U + ((n) * (0x200U)))

/* Event Set Register (High Part) CPU write of '1' to the ESRH.En bit causes
 * the ERH.En bit to be set. CPU write of '0' has no effect. */
#define CSL_EVETPCC_ESRH_RN(n)                                  (0x2014U + ((n) * (0x200U)))

/* QDMA Event Enable Set Register: CPU write of '1' to the QEESR.En bit causes
 * the QEESR.En bit to be set. CPU write of '0' has no effect.. */
#define CSL_EVETPCC_QEESR_RN(n)                                 (0x208CU + ((n) * (0x200U)))

/* Event Register (High Part): If ERH.En bit is set and the EERH.En bit is
 * also set, then the corresponding DMA channel is prioritized vs. other
 * pending DMA events for submission to the TC. ERH.En bit is set when the
 * input event #n transitions from inactive (low) to active (high), regardless
 * of the state of EERH.En bit. ER.En bit is cleared when the corresponding
 * event is prioritized and serviced. If the ERH.En bit is already set and a
 * new inactive to active transition is detected on the input event #n input
 * AND the corresponding bit in the EERH register is set, then the
 * corresponding bit in the Event Missed Register is set. Event N can be
 * cleared via sw by writing a '1' to the ECRH pseudo-register. */
#define CSL_EVETPCC_ERH_RN(n)                                   (0x2004U + ((n) * (0x200U)))

/* Options Parameter */
#define CSL_EVETPCC_OPT(n)                                      (0x4000U + ((n) * (0x20U)))

/* Source Address */
#define CSL_EVETPCC_SRC(n)                                      (0x4004U + ((n) * (0x20U)))

/* A and B byte count */
#define CSL_EVETPCC_ABCNT(n)                                    (0x4008U + ((n) * (0x20U)))

/* BIDX */
#define CSL_EVETPCC_BIDX(n)                                     (0x4010U + ((n) * (0x20U)))

/* Link and Reload parameters */
#define CSL_EVETPCC_LNK(n)                                      (0x4014U + ((n) * (0x20U)))

/* CIDX */
#define CSL_EVETPCC_CIDX(n)                                     (0x4018U + ((n) * (0x20U)))

/* C byte count */
#define CSL_EVETPCC_CCNT(n)                                     (0x401CU + ((n) * (0x20U)))

/* Destination Address */
#define CSL_EVETPCC_DST(n)                                      (0x400CU + ((n) * (0x20U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PID */

#define CSL_EVETPCC_PID_MINOR_MASK                              (0x0000003FU)
#define CSL_EVETPCC_PID_MINOR_SHIFT                             (0U)
#define CSL_EVETPCC_PID_MINOR_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_PID_MINOR_MAX                               (0x0000003fU)

#define CSL_EVETPCC_PID_CUSTOM_MASK                             (0x000000C0U)
#define CSL_EVETPCC_PID_CUSTOM_SHIFT                            (6U)
#define CSL_EVETPCC_PID_CUSTOM_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_PID_CUSTOM_MAX                              (0x00000003U)

#define CSL_EVETPCC_PID_MAJOR_MASK                              (0x00000700U)
#define CSL_EVETPCC_PID_MAJOR_SHIFT                             (8U)
#define CSL_EVETPCC_PID_MAJOR_RESETVAL                          (0x00000003U)
#define CSL_EVETPCC_PID_MAJOR_MAX                               (0x00000007U)

#define CSL_EVETPCC_PID_RTL_MASK                                (0x0000F800U)
#define CSL_EVETPCC_PID_RTL_SHIFT                               (11U)
#define CSL_EVETPCC_PID_RTL_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_PID_RTL_MAX                                 (0x0000001fU)

#define CSL_EVETPCC_PID_FUNC_MASK                               (0x0FFF0000U)
#define CSL_EVETPCC_PID_FUNC_SHIFT                              (16U)
#define CSL_EVETPCC_PID_FUNC_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_PID_FUNC_MAX                                (0x00000fffU)

#define CSL_EVETPCC_PID_SCHEME_MASK                             (0xC0000000U)
#define CSL_EVETPCC_PID_SCHEME_SHIFT                            (30U)
#define CSL_EVETPCC_PID_SCHEME_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_PID_SCHEME_MAX                              (0x00000003U)

#define CSL_EVETPCC_PID_RESETVAL                                (0x40010300U)

/* CCCFG */

#define CSL_EVETPCC_CCCFG_NUMTC_MASK                            (0x00070000U)
#define CSL_EVETPCC_CCCFG_NUMTC_SHIFT                           (16U)
#define CSL_EVETPCC_CCCFG_NUMTC_RESETVAL                        (0x00000001U)
#define CSL_EVETPCC_CCCFG_NUMTC_NUMTC7                          (0x00000006U)
#define CSL_EVETPCC_CCCFG_NUMTC_NUMTC4                          (0x00000003U)
#define CSL_EVETPCC_CCCFG_NUMTC_NUMTC1                          (0x00000000U)
#define CSL_EVETPCC_CCCFG_NUMTC_NUMTC6                          (0x00000005U)
#define CSL_EVETPCC_CCCFG_NUMTC_NUMTC8                          (0x00000007U)
#define CSL_EVETPCC_CCCFG_NUMTC_NUMTC5                          (0x00000004U)
#define CSL_EVETPCC_CCCFG_NUMTC_NUMTC3                          (0x00000002U)
#define CSL_EVETPCC_CCCFG_NUMTC_NUMTC2                          (0x00000001U)

#define CSL_EVETPCC_CCCFG_NUMREGN_MASK                          (0x00300000U)
#define CSL_EVETPCC_CCCFG_NUMREGN_SHIFT                         (20U)
#define CSL_EVETPCC_CCCFG_NUMREGN_RESETVAL                      (0x00000003U)
#define CSL_EVETPCC_CCCFG_NUMREGN_NUMREG4                       (0x00000002U)
#define CSL_EVETPCC_CCCFG_NUMREGN_NUMREG8                       (0x00000003U)
#define CSL_EVETPCC_CCCFG_NUMREGN_NUMREG0                       (0x00000000U)
#define CSL_EVETPCC_CCCFG_NUMREGN_NUMREG2                       (0x00000001U)

#define CSL_EVETPCC_CCCFG_NUMINTCH_MASK                         (0x00000700U)
#define CSL_EVETPCC_CCCFG_NUMINTCH_SHIFT                        (8U)
#define CSL_EVETPCC_CCCFG_NUMINTCH_RESETVAL                     (0x00000004U)
#define CSL_EVETPCC_CCCFG_NUMINTCH_NUMINTCH32                   (0x00000003U)
#define CSL_EVETPCC_CCCFG_NUMINTCH_NUMINTCH64                   (0x00000004U)
#define CSL_EVETPCC_CCCFG_NUMINTCH_NUMINTCH16                   (0x00000002U)
#define CSL_EVETPCC_CCCFG_NUMINTCH_NUMINTCH8                    (0x00000001U)

#define CSL_EVETPCC_CCCFG_NUMPAENTRY_MASK                       (0x00007000U)
#define CSL_EVETPCC_CCCFG_NUMPAENTRY_SHIFT                      (12U)
#define CSL_EVETPCC_CCCFG_NUMPAENTRY_RESETVAL                   (0x00000003U)
#define CSL_EVETPCC_CCCFG_NUMPAENTRY_NUMPARAMENTRIES16          (0x00000000U)
#define CSL_EVETPCC_CCCFG_NUMPAENTRY_NUMPARAMENTRIES32          (0x00000001U)
#define CSL_EVETPCC_CCCFG_NUMPAENTRY_NUMPARAMENTRIES64          (0x00000002U)
#define CSL_EVETPCC_CCCFG_NUMPAENTRY_NUMPARAMENTRIES128         (0x00000003U)
#define CSL_EVETPCC_CCCFG_NUMPAENTRY_NUMPARAMENTRIES256         (0x00000004U)
#define CSL_EVETPCC_CCCFG_NUMPAENTRY_NUMPARAMENTRIES512         (0x00000005U)

#define CSL_EVETPCC_CCCFG_CHMAPEXIST_MASK                       (0x01000000U)
#define CSL_EVETPCC_CCCFG_CHMAPEXIST_SHIFT                      (24U)
#define CSL_EVETPCC_CCCFG_CHMAPEXIST_RESETVAL                   (0x00000001U)
#define CSL_EVETPCC_CCCFG_CHMAPEXIST_MAX                        (0x00000001U)

#define CSL_EVETPCC_CCCFG_MPEXIST_MASK                          (0x02000000U)
#define CSL_EVETPCC_CCCFG_MPEXIST_SHIFT                         (25U)
#define CSL_EVETPCC_CCCFG_MPEXIST_RESETVAL                      (0x00000001U)
#define CSL_EVETPCC_CCCFG_MPEXIST_MAX                           (0x00000001U)

#define CSL_EVETPCC_CCCFG_NUMDMACH_MASK                         (0x00000007U)
#define CSL_EVETPCC_CCCFG_NUMDMACH_SHIFT                        (0U)
#define CSL_EVETPCC_CCCFG_NUMDMACH_RESETVAL                     (0x00000005U)
#define CSL_EVETPCC_CCCFG_NUMDMACH_NUMDMACH4                    (0x00000001U)
#define CSL_EVETPCC_CCCFG_NUMDMACH_NUMDMACH32                   (0x00000004U)
#define CSL_EVETPCC_CCCFG_NUMDMACH_NUMDMACH8                    (0x00000002U)
#define CSL_EVETPCC_CCCFG_NUMDMACH_NUMDMACH64                   (0x00000005U)
#define CSL_EVETPCC_CCCFG_NUMDMACH_NUMDMACH16                   (0x00000003U)
#define CSL_EVETPCC_CCCFG_NUMDMACH_NUMDMACH0                    (0x00000000U)

#define CSL_EVETPCC_CCCFG_NUMQDMACH_MASK                        (0x00000070U)
#define CSL_EVETPCC_CCCFG_NUMQDMACH_SHIFT                       (4U)
#define CSL_EVETPCC_CCCFG_NUMQDMACH_RESETVAL                    (0x00000004U)
#define CSL_EVETPCC_CCCFG_NUMQDMACH_NUMQDMACH4                  (0x00000002U)
#define CSL_EVETPCC_CCCFG_NUMQDMACH_NUMQDMACH8                  (0x00000004U)
#define CSL_EVETPCC_CCCFG_NUMQDMACH_NUMQDMACH6                  (0x00000003U)
#define CSL_EVETPCC_CCCFG_NUMQDMACH_NUMQDMACH0                  (0x00000000U)
#define CSL_EVETPCC_CCCFG_NUMQDMACH_NUMQDMACH2                  (0x00000001U)

#define CSL_EVETPCC_CCCFG_RESETVAL                              (0x03313445U)

/* CLKGDIS */

#define CSL_EVETPCC_CLKGDIS_CLKGDIS_MASK                        (0x00000001U)
#define CSL_EVETPCC_CLKGDIS_CLKGDIS_SHIFT                       (0U)
#define CSL_EVETPCC_CLKGDIS_CLKGDIS_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CLKGDIS_CLKGDIS_MAX                         (0x00000001U)

#define CSL_EVETPCC_CLKGDIS_RESETVAL                            (0x00000000U)

/* DCHMAPN */

#define CSL_EVETPCC_DCHMAPN_PAENTRY_MASK                        (0x00003FE0U)
#define CSL_EVETPCC_DCHMAPN_PAENTRY_SHIFT                       (5U)
#define CSL_EVETPCC_DCHMAPN_PAENTRY_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_DCHMAPN_PAENTRY_MAX                         (0x000001ffU)

#define CSL_EVETPCC_DCHMAPN_RESETVAL                            (0x00000000U)

/* QCHMAPN */

#define CSL_EVETPCC_QCHMAPN_PAENTRY_MASK                        (0x00003FE0U)
#define CSL_EVETPCC_QCHMAPN_PAENTRY_SHIFT                       (5U)
#define CSL_EVETPCC_QCHMAPN_PAENTRY_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_QCHMAPN_PAENTRY_MAX                         (0x000001ffU)

#define CSL_EVETPCC_QCHMAPN_TRWORD_MASK                         (0x0000001CU)
#define CSL_EVETPCC_QCHMAPN_TRWORD_SHIFT                        (2U)
#define CSL_EVETPCC_QCHMAPN_TRWORD_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_QCHMAPN_TRWORD_MAX                          (0x00000007U)

#define CSL_EVETPCC_QCHMAPN_RESETVAL                            (0x00000000U)

/* DMAQNUMN */

#define CSL_EVETPCC_DMAQNUMN_E6_MASK                            (0x07000000U)
#define CSL_EVETPCC_DMAQNUMN_E6_SHIFT                           (24U)
#define CSL_EVETPCC_DMAQNUMN_E6_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E6_Q3                              (0x00000003U)
#define CSL_EVETPCC_DMAQNUMN_E6_Q7                              (0x00000007U)
#define CSL_EVETPCC_DMAQNUMN_E6_Q4                              (0x00000004U)
#define CSL_EVETPCC_DMAQNUMN_E6_Q6                              (0x00000006U)
#define CSL_EVETPCC_DMAQNUMN_E6_Q1                              (0x00000001U)
#define CSL_EVETPCC_DMAQNUMN_E6_Q0                              (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E6_Q5                              (0x00000005U)
#define CSL_EVETPCC_DMAQNUMN_E6_Q2                              (0x00000002U)

#define CSL_EVETPCC_DMAQNUMN_E2_MASK                            (0x00000700U)
#define CSL_EVETPCC_DMAQNUMN_E2_SHIFT                           (8U)
#define CSL_EVETPCC_DMAQNUMN_E2_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E2_Q4                              (0x00000004U)
#define CSL_EVETPCC_DMAQNUMN_E2_Q7                              (0x00000007U)
#define CSL_EVETPCC_DMAQNUMN_E2_Q1                              (0x00000001U)
#define CSL_EVETPCC_DMAQNUMN_E2_Q2                              (0x00000002U)
#define CSL_EVETPCC_DMAQNUMN_E2_Q5                              (0x00000005U)
#define CSL_EVETPCC_DMAQNUMN_E2_Q0                              (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E2_Q3                              (0x00000003U)
#define CSL_EVETPCC_DMAQNUMN_E2_Q6                              (0x00000006U)

#define CSL_EVETPCC_DMAQNUMN_E1_MASK                            (0x00000070U)
#define CSL_EVETPCC_DMAQNUMN_E1_SHIFT                           (4U)
#define CSL_EVETPCC_DMAQNUMN_E1_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E1_Q4                              (0x00000004U)
#define CSL_EVETPCC_DMAQNUMN_E1_Q3                              (0x00000003U)
#define CSL_EVETPCC_DMAQNUMN_E1_Q6                              (0x00000006U)
#define CSL_EVETPCC_DMAQNUMN_E1_Q0                              (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E1_Q1                              (0x00000001U)
#define CSL_EVETPCC_DMAQNUMN_E1_Q7                              (0x00000007U)
#define CSL_EVETPCC_DMAQNUMN_E1_Q2                              (0x00000002U)
#define CSL_EVETPCC_DMAQNUMN_E1_Q5                              (0x00000005U)

#define CSL_EVETPCC_DMAQNUMN_E4_MASK                            (0x00070000U)
#define CSL_EVETPCC_DMAQNUMN_E4_SHIFT                           (16U)
#define CSL_EVETPCC_DMAQNUMN_E4_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E4_Q1                              (0x00000001U)
#define CSL_EVETPCC_DMAQNUMN_E4_Q0                              (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E4_Q4                              (0x00000004U)
#define CSL_EVETPCC_DMAQNUMN_E4_Q2                              (0x00000002U)
#define CSL_EVETPCC_DMAQNUMN_E4_Q5                              (0x00000005U)
#define CSL_EVETPCC_DMAQNUMN_E4_Q7                              (0x00000007U)
#define CSL_EVETPCC_DMAQNUMN_E4_Q3                              (0x00000003U)
#define CSL_EVETPCC_DMAQNUMN_E4_Q6                              (0x00000006U)

#define CSL_EVETPCC_DMAQNUMN_E3_MASK                            (0x00007000U)
#define CSL_EVETPCC_DMAQNUMN_E3_SHIFT                           (12U)
#define CSL_EVETPCC_DMAQNUMN_E3_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E3_Q2                              (0x00000002U)
#define CSL_EVETPCC_DMAQNUMN_E3_Q5                              (0x00000005U)
#define CSL_EVETPCC_DMAQNUMN_E3_Q0                              (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E3_Q4                              (0x00000004U)
#define CSL_EVETPCC_DMAQNUMN_E3_Q3                              (0x00000003U)
#define CSL_EVETPCC_DMAQNUMN_E3_Q6                              (0x00000006U)
#define CSL_EVETPCC_DMAQNUMN_E3_Q7                              (0x00000007U)
#define CSL_EVETPCC_DMAQNUMN_E3_Q1                              (0x00000001U)

#define CSL_EVETPCC_DMAQNUMN_E5_MASK                            (0x00700000U)
#define CSL_EVETPCC_DMAQNUMN_E5_SHIFT                           (20U)
#define CSL_EVETPCC_DMAQNUMN_E5_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E5_Q7                              (0x00000007U)
#define CSL_EVETPCC_DMAQNUMN_E5_Q1                              (0x00000001U)
#define CSL_EVETPCC_DMAQNUMN_E5_Q2                              (0x00000002U)
#define CSL_EVETPCC_DMAQNUMN_E5_Q5                              (0x00000005U)
#define CSL_EVETPCC_DMAQNUMN_E5_Q3                              (0x00000003U)
#define CSL_EVETPCC_DMAQNUMN_E5_Q4                              (0x00000004U)
#define CSL_EVETPCC_DMAQNUMN_E5_Q6                              (0x00000006U)
#define CSL_EVETPCC_DMAQNUMN_E5_Q0                              (0x00000000U)

#define CSL_EVETPCC_DMAQNUMN_E0_MASK                            (0x00000007U)
#define CSL_EVETPCC_DMAQNUMN_E0_SHIFT                           (0U)
#define CSL_EVETPCC_DMAQNUMN_E0_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E0_Q5                              (0x00000005U)
#define CSL_EVETPCC_DMAQNUMN_E0_Q4                              (0x00000004U)
#define CSL_EVETPCC_DMAQNUMN_E0_Q6                              (0x00000006U)
#define CSL_EVETPCC_DMAQNUMN_E0_Q1                              (0x00000001U)
#define CSL_EVETPCC_DMAQNUMN_E0_Q0                              (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E0_Q3                              (0x00000003U)
#define CSL_EVETPCC_DMAQNUMN_E0_Q2                              (0x00000002U)
#define CSL_EVETPCC_DMAQNUMN_E0_Q7                              (0x00000007U)

#define CSL_EVETPCC_DMAQNUMN_E7_MASK                            (0x70000000U)
#define CSL_EVETPCC_DMAQNUMN_E7_SHIFT                           (28U)
#define CSL_EVETPCC_DMAQNUMN_E7_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E7_Q3                              (0x00000003U)
#define CSL_EVETPCC_DMAQNUMN_E7_Q7                              (0x00000007U)
#define CSL_EVETPCC_DMAQNUMN_E7_Q6                              (0x00000006U)
#define CSL_EVETPCC_DMAQNUMN_E7_Q1                              (0x00000001U)
#define CSL_EVETPCC_DMAQNUMN_E7_Q0                              (0x00000000U)
#define CSL_EVETPCC_DMAQNUMN_E7_Q4                              (0x00000004U)
#define CSL_EVETPCC_DMAQNUMN_E7_Q2                              (0x00000002U)
#define CSL_EVETPCC_DMAQNUMN_E7_Q5                              (0x00000005U)

#define CSL_EVETPCC_DMAQNUMN_RESETVAL                           (0x00000000U)

/* QDMAQNUM */

#define CSL_EVETPCC_QDMAQNUM_E5_MASK                            (0x00700000U)
#define CSL_EVETPCC_QDMAQNUM_E5_SHIFT                           (20U)
#define CSL_EVETPCC_QDMAQNUM_E5_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E5_Q7                              (0x00000007U)
#define CSL_EVETPCC_QDMAQNUM_E5_Q0                              (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E5_Q3                              (0x00000003U)
#define CSL_EVETPCC_QDMAQNUM_E5_Q2                              (0x00000002U)
#define CSL_EVETPCC_QDMAQNUM_E5_Q6                              (0x00000006U)
#define CSL_EVETPCC_QDMAQNUM_E5_Q4                              (0x00000004U)
#define CSL_EVETPCC_QDMAQNUM_E5_Q5                              (0x00000005U)
#define CSL_EVETPCC_QDMAQNUM_E5_Q1                              (0x00000001U)

#define CSL_EVETPCC_QDMAQNUM_E6_MASK                            (0x07000000U)
#define CSL_EVETPCC_QDMAQNUM_E6_SHIFT                           (24U)
#define CSL_EVETPCC_QDMAQNUM_E6_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E6_Q1                              (0x00000001U)
#define CSL_EVETPCC_QDMAQNUM_E6_Q5                              (0x00000005U)
#define CSL_EVETPCC_QDMAQNUM_E6_Q0                              (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E6_Q4                              (0x00000004U)
#define CSL_EVETPCC_QDMAQNUM_E6_Q7                              (0x00000007U)
#define CSL_EVETPCC_QDMAQNUM_E6_Q2                              (0x00000002U)
#define CSL_EVETPCC_QDMAQNUM_E6_Q6                              (0x00000006U)
#define CSL_EVETPCC_QDMAQNUM_E6_Q3                              (0x00000003U)

#define CSL_EVETPCC_QDMAQNUM_E7_MASK                            (0x70000000U)
#define CSL_EVETPCC_QDMAQNUM_E7_SHIFT                           (28U)
#define CSL_EVETPCC_QDMAQNUM_E7_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E7_Q0                              (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E7_Q4                              (0x00000004U)
#define CSL_EVETPCC_QDMAQNUM_E7_Q5                              (0x00000005U)
#define CSL_EVETPCC_QDMAQNUM_E7_Q3                              (0x00000003U)
#define CSL_EVETPCC_QDMAQNUM_E7_Q2                              (0x00000002U)
#define CSL_EVETPCC_QDMAQNUM_E7_Q1                              (0x00000001U)
#define CSL_EVETPCC_QDMAQNUM_E7_Q6                              (0x00000006U)
#define CSL_EVETPCC_QDMAQNUM_E7_Q7                              (0x00000007U)

#define CSL_EVETPCC_QDMAQNUM_E4_MASK                            (0x00070000U)
#define CSL_EVETPCC_QDMAQNUM_E4_SHIFT                           (16U)
#define CSL_EVETPCC_QDMAQNUM_E4_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E4_Q0                              (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E4_Q4                              (0x00000004U)
#define CSL_EVETPCC_QDMAQNUM_E4_Q6                              (0x00000006U)
#define CSL_EVETPCC_QDMAQNUM_E4_Q3                              (0x00000003U)
#define CSL_EVETPCC_QDMAQNUM_E4_Q1                              (0x00000001U)
#define CSL_EVETPCC_QDMAQNUM_E4_Q2                              (0x00000002U)
#define CSL_EVETPCC_QDMAQNUM_E4_Q5                              (0x00000005U)
#define CSL_EVETPCC_QDMAQNUM_E4_Q7                              (0x00000007U)

#define CSL_EVETPCC_QDMAQNUM_E3_MASK                            (0x00007000U)
#define CSL_EVETPCC_QDMAQNUM_E3_SHIFT                           (12U)
#define CSL_EVETPCC_QDMAQNUM_E3_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E3_Q5                              (0x00000005U)
#define CSL_EVETPCC_QDMAQNUM_E3_Q7                              (0x00000007U)
#define CSL_EVETPCC_QDMAQNUM_E3_Q4                              (0x00000004U)
#define CSL_EVETPCC_QDMAQNUM_E3_Q6                              (0x00000006U)
#define CSL_EVETPCC_QDMAQNUM_E3_Q3                              (0x00000003U)
#define CSL_EVETPCC_QDMAQNUM_E3_Q2                              (0x00000002U)
#define CSL_EVETPCC_QDMAQNUM_E3_Q1                              (0x00000001U)
#define CSL_EVETPCC_QDMAQNUM_E3_Q0                              (0x00000000U)

#define CSL_EVETPCC_QDMAQNUM_E1_MASK                            (0x00000070U)
#define CSL_EVETPCC_QDMAQNUM_E1_SHIFT                           (4U)
#define CSL_EVETPCC_QDMAQNUM_E1_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E1_Q3                              (0x00000003U)
#define CSL_EVETPCC_QDMAQNUM_E1_Q5                              (0x00000005U)
#define CSL_EVETPCC_QDMAQNUM_E1_Q7                              (0x00000007U)
#define CSL_EVETPCC_QDMAQNUM_E1_Q1                              (0x00000001U)
#define CSL_EVETPCC_QDMAQNUM_E1_Q6                              (0x00000006U)
#define CSL_EVETPCC_QDMAQNUM_E1_Q0                              (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E1_Q4                              (0x00000004U)
#define CSL_EVETPCC_QDMAQNUM_E1_Q2                              (0x00000002U)

#define CSL_EVETPCC_QDMAQNUM_E0_MASK                            (0x00000007U)
#define CSL_EVETPCC_QDMAQNUM_E0_SHIFT                           (0U)
#define CSL_EVETPCC_QDMAQNUM_E0_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E0_Q1                              (0x00000001U)
#define CSL_EVETPCC_QDMAQNUM_E0_Q6                              (0x00000006U)
#define CSL_EVETPCC_QDMAQNUM_E0_Q3                              (0x00000003U)
#define CSL_EVETPCC_QDMAQNUM_E0_Q4                              (0x00000004U)
#define CSL_EVETPCC_QDMAQNUM_E0_Q7                              (0x00000007U)
#define CSL_EVETPCC_QDMAQNUM_E0_Q2                              (0x00000002U)
#define CSL_EVETPCC_QDMAQNUM_E0_Q5                              (0x00000005U)
#define CSL_EVETPCC_QDMAQNUM_E0_Q0                              (0x00000000U)

#define CSL_EVETPCC_QDMAQNUM_E2_MASK                            (0x00000700U)
#define CSL_EVETPCC_QDMAQNUM_E2_SHIFT                           (8U)
#define CSL_EVETPCC_QDMAQNUM_E2_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E2_Q5                              (0x00000005U)
#define CSL_EVETPCC_QDMAQNUM_E2_Q7                              (0x00000007U)
#define CSL_EVETPCC_QDMAQNUM_E2_Q0                              (0x00000000U)
#define CSL_EVETPCC_QDMAQNUM_E2_Q1                              (0x00000001U)
#define CSL_EVETPCC_QDMAQNUM_E2_Q2                              (0x00000002U)
#define CSL_EVETPCC_QDMAQNUM_E2_Q4                              (0x00000004U)
#define CSL_EVETPCC_QDMAQNUM_E2_Q6                              (0x00000006U)
#define CSL_EVETPCC_QDMAQNUM_E2_Q3                              (0x00000003U)

#define CSL_EVETPCC_QDMAQNUM_RESETVAL                           (0x00000000U)

/* QUETCMAP */

#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_MASK                       (0x00000007U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_SHIFT                      (0U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_RESETVAL                   (0x00000000U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_TC0                        (0x00000000U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_TC1                        (0x00000001U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_TC2                        (0x00000002U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_TC3                        (0x00000003U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_TC4                        (0x00000004U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_TC5                        (0x00000005U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_TC6                        (0x00000006U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ0_TC7                        (0x00000007U)

#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_MASK                       (0x00000070U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_SHIFT                      (4U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_RESETVAL                   (0x00000001U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_TC1                        (0x00000001U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_TC0                        (0x00000000U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_TC6                        (0x00000006U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_TC2                        (0x00000002U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_TC3                        (0x00000003U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_TC5                        (0x00000005U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_TC7                        (0x00000007U)
#define CSL_EVETPCC_QUETCMAP_TCNUMQ1_TC4                        (0x00000004U)

#define CSL_EVETPCC_QUETCMAP_RESETVAL                           (0x00000010U)

/* QUEPRI */

#define CSL_EVETPCC_QUEPRI_PRIQ0_MASK                           (0x00000007U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_SHIFT                          (0U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_PRIORITY7                      (0x00000007U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_PRIORITY6                      (0x00000006U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_PRIORITY5                      (0x00000005U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_PRIORITY4                      (0x00000004U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_PRIORITY3                      (0x00000003U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_PRIORITY2                      (0x00000002U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_PRIORITY1                      (0x00000001U)
#define CSL_EVETPCC_QUEPRI_PRIQ0_PRIORITY0                      (0x00000000U)

#define CSL_EVETPCC_QUEPRI_PRIQ1_MASK                           (0x00000070U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_SHIFT                          (4U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_PRIORITY7                      (0x00000007U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_PRIORITY6                      (0x00000006U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_PRIORITY0                      (0x00000000U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_PRIORITY1                      (0x00000001U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_PRIORITY3                      (0x00000003U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_PRIORITY4                      (0x00000004U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_PRIORITY2                      (0x00000002U)
#define CSL_EVETPCC_QUEPRI_PRIQ1_PRIORITY5                      (0x00000005U)

#define CSL_EVETPCC_QUEPRI_RESETVAL                             (0x00000000U)

/* EMR */

#define CSL_EVETPCC_EMR_E0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_EMR_E0_SHIFT                                (0U)
#define CSL_EVETPCC_EMR_E0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_EMR_E1_SHIFT                                (1U)
#define CSL_EVETPCC_EMR_E1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_EMR_E2_SHIFT                                (2U)
#define CSL_EVETPCC_EMR_E2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_EMR_E3_SHIFT                                (3U)
#define CSL_EVETPCC_EMR_E3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_EMR_E4_SHIFT                                (4U)
#define CSL_EVETPCC_EMR_E4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_EMR_E5_SHIFT                                (5U)
#define CSL_EVETPCC_EMR_E5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_EMR_E6_SHIFT                                (6U)
#define CSL_EVETPCC_EMR_E6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_EMR_E7_SHIFT                                (7U)
#define CSL_EVETPCC_EMR_E7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E8_MASK                                 (0x00000100U)
#define CSL_EVETPCC_EMR_E8_SHIFT                                (8U)
#define CSL_EVETPCC_EMR_E8_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E8_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E9_MASK                                 (0x00000200U)
#define CSL_EVETPCC_EMR_E9_SHIFT                                (9U)
#define CSL_EVETPCC_EMR_E9_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EMR_E9_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EMR_E10_MASK                                (0x00000400U)
#define CSL_EVETPCC_EMR_E10_SHIFT                               (10U)
#define CSL_EVETPCC_EMR_E10_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E10_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E11_MASK                                (0x00000800U)
#define CSL_EVETPCC_EMR_E11_SHIFT                               (11U)
#define CSL_EVETPCC_EMR_E11_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E11_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E12_MASK                                (0x00001000U)
#define CSL_EVETPCC_EMR_E12_SHIFT                               (12U)
#define CSL_EVETPCC_EMR_E12_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E12_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E13_MASK                                (0x00002000U)
#define CSL_EVETPCC_EMR_E13_SHIFT                               (13U)
#define CSL_EVETPCC_EMR_E13_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E13_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E14_MASK                                (0x00004000U)
#define CSL_EVETPCC_EMR_E14_SHIFT                               (14U)
#define CSL_EVETPCC_EMR_E14_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E14_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E15_MASK                                (0x00008000U)
#define CSL_EVETPCC_EMR_E15_SHIFT                               (15U)
#define CSL_EVETPCC_EMR_E15_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E15_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E16_MASK                                (0x00010000U)
#define CSL_EVETPCC_EMR_E16_SHIFT                               (16U)
#define CSL_EVETPCC_EMR_E16_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E16_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E17_MASK                                (0x00020000U)
#define CSL_EVETPCC_EMR_E17_SHIFT                               (17U)
#define CSL_EVETPCC_EMR_E17_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E17_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E18_MASK                                (0x00040000U)
#define CSL_EVETPCC_EMR_E18_SHIFT                               (18U)
#define CSL_EVETPCC_EMR_E18_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E18_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E19_MASK                                (0x00080000U)
#define CSL_EVETPCC_EMR_E19_SHIFT                               (19U)
#define CSL_EVETPCC_EMR_E19_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E19_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E20_MASK                                (0x00100000U)
#define CSL_EVETPCC_EMR_E20_SHIFT                               (20U)
#define CSL_EVETPCC_EMR_E20_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E20_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E21_MASK                                (0x00200000U)
#define CSL_EVETPCC_EMR_E21_SHIFT                               (21U)
#define CSL_EVETPCC_EMR_E21_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E21_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E22_MASK                                (0x00400000U)
#define CSL_EVETPCC_EMR_E22_SHIFT                               (22U)
#define CSL_EVETPCC_EMR_E22_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E22_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E23_MASK                                (0x00800000U)
#define CSL_EVETPCC_EMR_E23_SHIFT                               (23U)
#define CSL_EVETPCC_EMR_E23_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E23_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E24_MASK                                (0x01000000U)
#define CSL_EVETPCC_EMR_E24_SHIFT                               (24U)
#define CSL_EVETPCC_EMR_E24_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E24_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E25_MASK                                (0x02000000U)
#define CSL_EVETPCC_EMR_E25_SHIFT                               (25U)
#define CSL_EVETPCC_EMR_E25_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E25_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E26_MASK                                (0x04000000U)
#define CSL_EVETPCC_EMR_E26_SHIFT                               (26U)
#define CSL_EVETPCC_EMR_E26_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E26_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E27_MASK                                (0x08000000U)
#define CSL_EVETPCC_EMR_E27_SHIFT                               (27U)
#define CSL_EVETPCC_EMR_E27_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E27_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E28_MASK                                (0x10000000U)
#define CSL_EVETPCC_EMR_E28_SHIFT                               (28U)
#define CSL_EVETPCC_EMR_E28_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E28_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E29_MASK                                (0x20000000U)
#define CSL_EVETPCC_EMR_E29_SHIFT                               (29U)
#define CSL_EVETPCC_EMR_E29_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E29_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E30_MASK                                (0x40000000U)
#define CSL_EVETPCC_EMR_E30_SHIFT                               (30U)
#define CSL_EVETPCC_EMR_E30_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E30_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_E31_MASK                                (0x80000000U)
#define CSL_EVETPCC_EMR_E31_SHIFT                               (31U)
#define CSL_EVETPCC_EMR_E31_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMR_E31_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMR_RESETVAL                                (0x00000000U)

/* EMRH */

#define CSL_EVETPCC_EMRH_E48_MASK                               (0x00010000U)
#define CSL_EVETPCC_EMRH_E48_SHIFT                              (16U)
#define CSL_EVETPCC_EMRH_E48_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E48_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E33_MASK                               (0x00000002U)
#define CSL_EVETPCC_EMRH_E33_SHIFT                              (1U)
#define CSL_EVETPCC_EMRH_E33_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E33_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E42_MASK                               (0x00000400U)
#define CSL_EVETPCC_EMRH_E42_SHIFT                              (10U)
#define CSL_EVETPCC_EMRH_E42_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E42_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E43_MASK                               (0x00000800U)
#define CSL_EVETPCC_EMRH_E43_SHIFT                              (11U)
#define CSL_EVETPCC_EMRH_E43_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E43_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E45_MASK                               (0x00002000U)
#define CSL_EVETPCC_EMRH_E45_SHIFT                              (13U)
#define CSL_EVETPCC_EMRH_E45_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E45_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E60_MASK                               (0x10000000U)
#define CSL_EVETPCC_EMRH_E60_SHIFT                              (28U)
#define CSL_EVETPCC_EMRH_E60_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E60_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E49_MASK                               (0x00020000U)
#define CSL_EVETPCC_EMRH_E49_SHIFT                              (17U)
#define CSL_EVETPCC_EMRH_E49_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E49_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E54_MASK                               (0x00400000U)
#define CSL_EVETPCC_EMRH_E54_SHIFT                              (22U)
#define CSL_EVETPCC_EMRH_E54_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E54_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E39_MASK                               (0x00000080U)
#define CSL_EVETPCC_EMRH_E39_SHIFT                              (7U)
#define CSL_EVETPCC_EMRH_E39_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E39_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E55_MASK                               (0x00800000U)
#define CSL_EVETPCC_EMRH_E55_SHIFT                              (23U)
#define CSL_EVETPCC_EMRH_E55_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E55_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E53_MASK                               (0x00200000U)
#define CSL_EVETPCC_EMRH_E53_SHIFT                              (21U)
#define CSL_EVETPCC_EMRH_E53_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E53_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E32_MASK                               (0x00000001U)
#define CSL_EVETPCC_EMRH_E32_SHIFT                              (0U)
#define CSL_EVETPCC_EMRH_E32_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E32_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E41_MASK                               (0x00000200U)
#define CSL_EVETPCC_EMRH_E41_SHIFT                              (9U)
#define CSL_EVETPCC_EMRH_E41_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E41_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E47_MASK                               (0x00008000U)
#define CSL_EVETPCC_EMRH_E47_SHIFT                              (15U)
#define CSL_EVETPCC_EMRH_E47_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E47_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E58_MASK                               (0x04000000U)
#define CSL_EVETPCC_EMRH_E58_SHIFT                              (26U)
#define CSL_EVETPCC_EMRH_E58_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E58_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E35_MASK                               (0x00000008U)
#define CSL_EVETPCC_EMRH_E35_SHIFT                              (3U)
#define CSL_EVETPCC_EMRH_E35_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E35_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E34_MASK                               (0x00000004U)
#define CSL_EVETPCC_EMRH_E34_SHIFT                              (2U)
#define CSL_EVETPCC_EMRH_E34_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E34_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E38_MASK                               (0x00000040U)
#define CSL_EVETPCC_EMRH_E38_SHIFT                              (6U)
#define CSL_EVETPCC_EMRH_E38_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E38_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E59_MASK                               (0x08000000U)
#define CSL_EVETPCC_EMRH_E59_SHIFT                              (27U)
#define CSL_EVETPCC_EMRH_E59_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E59_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E37_MASK                               (0x00000020U)
#define CSL_EVETPCC_EMRH_E37_SHIFT                              (5U)
#define CSL_EVETPCC_EMRH_E37_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E37_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E63_MASK                               (0x80000000U)
#define CSL_EVETPCC_EMRH_E63_SHIFT                              (31U)
#define CSL_EVETPCC_EMRH_E63_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E63_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E57_MASK                               (0x02000000U)
#define CSL_EVETPCC_EMRH_E57_SHIFT                              (25U)
#define CSL_EVETPCC_EMRH_E57_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E57_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E62_MASK                               (0x40000000U)
#define CSL_EVETPCC_EMRH_E62_SHIFT                              (30U)
#define CSL_EVETPCC_EMRH_E62_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E62_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E36_MASK                               (0x00000010U)
#define CSL_EVETPCC_EMRH_E36_SHIFT                              (4U)
#define CSL_EVETPCC_EMRH_E36_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E36_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E44_MASK                               (0x00001000U)
#define CSL_EVETPCC_EMRH_E44_SHIFT                              (12U)
#define CSL_EVETPCC_EMRH_E44_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E44_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E56_MASK                               (0x01000000U)
#define CSL_EVETPCC_EMRH_E56_SHIFT                              (24U)
#define CSL_EVETPCC_EMRH_E56_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E56_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E50_MASK                               (0x00040000U)
#define CSL_EVETPCC_EMRH_E50_SHIFT                              (18U)
#define CSL_EVETPCC_EMRH_E50_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E50_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E40_MASK                               (0x00000100U)
#define CSL_EVETPCC_EMRH_E40_SHIFT                              (8U)
#define CSL_EVETPCC_EMRH_E40_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E40_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E46_MASK                               (0x00004000U)
#define CSL_EVETPCC_EMRH_E46_SHIFT                              (14U)
#define CSL_EVETPCC_EMRH_E46_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E46_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E51_MASK                               (0x00080000U)
#define CSL_EVETPCC_EMRH_E51_SHIFT                              (19U)
#define CSL_EVETPCC_EMRH_E51_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E51_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E52_MASK                               (0x00100000U)
#define CSL_EVETPCC_EMRH_E52_SHIFT                              (20U)
#define CSL_EVETPCC_EMRH_E52_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E52_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_E61_MASK                               (0x20000000U)
#define CSL_EVETPCC_EMRH_E61_SHIFT                              (29U)
#define CSL_EVETPCC_EMRH_E61_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMRH_E61_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMRH_RESETVAL                               (0x00000000U)

/* EMCR */

#define CSL_EVETPCC_EMCR_E10_MASK                               (0x00000400U)
#define CSL_EVETPCC_EMCR_E10_SHIFT                              (10U)
#define CSL_EVETPCC_EMCR_E10_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E10_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E7_MASK                                (0x00000080U)
#define CSL_EVETPCC_EMCR_E7_SHIFT                               (7U)
#define CSL_EVETPCC_EMCR_E7_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E7_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E29_MASK                               (0x20000000U)
#define CSL_EVETPCC_EMCR_E29_SHIFT                              (29U)
#define CSL_EVETPCC_EMCR_E29_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E29_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E30_MASK                               (0x40000000U)
#define CSL_EVETPCC_EMCR_E30_SHIFT                              (30U)
#define CSL_EVETPCC_EMCR_E30_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E30_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E11_MASK                               (0x00000800U)
#define CSL_EVETPCC_EMCR_E11_SHIFT                              (11U)
#define CSL_EVETPCC_EMCR_E11_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E11_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E16_MASK                               (0x00010000U)
#define CSL_EVETPCC_EMCR_E16_SHIFT                              (16U)
#define CSL_EVETPCC_EMCR_E16_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E16_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E2_MASK                                (0x00000004U)
#define CSL_EVETPCC_EMCR_E2_SHIFT                               (2U)
#define CSL_EVETPCC_EMCR_E2_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E2_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E28_MASK                               (0x10000000U)
#define CSL_EVETPCC_EMCR_E28_SHIFT                              (28U)
#define CSL_EVETPCC_EMCR_E28_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E28_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E17_MASK                               (0x00020000U)
#define CSL_EVETPCC_EMCR_E17_SHIFT                              (17U)
#define CSL_EVETPCC_EMCR_E17_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E17_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E12_MASK                               (0x00001000U)
#define CSL_EVETPCC_EMCR_E12_SHIFT                              (12U)
#define CSL_EVETPCC_EMCR_E12_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E12_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E24_MASK                               (0x01000000U)
#define CSL_EVETPCC_EMCR_E24_SHIFT                              (24U)
#define CSL_EVETPCC_EMCR_E24_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E24_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E4_MASK                                (0x00000010U)
#define CSL_EVETPCC_EMCR_E4_SHIFT                               (4U)
#define CSL_EVETPCC_EMCR_E4_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E4_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E25_MASK                               (0x02000000U)
#define CSL_EVETPCC_EMCR_E25_SHIFT                              (25U)
#define CSL_EVETPCC_EMCR_E25_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E25_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E8_MASK                                (0x00000100U)
#define CSL_EVETPCC_EMCR_E8_SHIFT                               (8U)
#define CSL_EVETPCC_EMCR_E8_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E8_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E15_MASK                               (0x00008000U)
#define CSL_EVETPCC_EMCR_E15_SHIFT                              (15U)
#define CSL_EVETPCC_EMCR_E15_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E15_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E31_MASK                               (0x80000000U)
#define CSL_EVETPCC_EMCR_E31_SHIFT                              (31U)
#define CSL_EVETPCC_EMCR_E31_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E31_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E26_MASK                               (0x04000000U)
#define CSL_EVETPCC_EMCR_E26_SHIFT                              (26U)
#define CSL_EVETPCC_EMCR_E26_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E26_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E14_MASK                               (0x00004000U)
#define CSL_EVETPCC_EMCR_E14_SHIFT                              (14U)
#define CSL_EVETPCC_EMCR_E14_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E14_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E9_MASK                                (0x00000200U)
#define CSL_EVETPCC_EMCR_E9_SHIFT                               (9U)
#define CSL_EVETPCC_EMCR_E9_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E9_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E23_MASK                               (0x00800000U)
#define CSL_EVETPCC_EMCR_E23_SHIFT                              (23U)
#define CSL_EVETPCC_EMCR_E23_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E23_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E6_MASK                                (0x00000040U)
#define CSL_EVETPCC_EMCR_E6_SHIFT                               (6U)
#define CSL_EVETPCC_EMCR_E6_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E6_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E13_MASK                               (0x00002000U)
#define CSL_EVETPCC_EMCR_E13_SHIFT                              (13U)
#define CSL_EVETPCC_EMCR_E13_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E13_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E1_MASK                                (0x00000002U)
#define CSL_EVETPCC_EMCR_E1_SHIFT                               (1U)
#define CSL_EVETPCC_EMCR_E1_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E1_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E21_MASK                               (0x00200000U)
#define CSL_EVETPCC_EMCR_E21_SHIFT                              (21U)
#define CSL_EVETPCC_EMCR_E21_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E21_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E22_MASK                               (0x00400000U)
#define CSL_EVETPCC_EMCR_E22_SHIFT                              (22U)
#define CSL_EVETPCC_EMCR_E22_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E22_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E27_MASK                               (0x08000000U)
#define CSL_EVETPCC_EMCR_E27_SHIFT                              (27U)
#define CSL_EVETPCC_EMCR_E27_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E27_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E20_MASK                               (0x00100000U)
#define CSL_EVETPCC_EMCR_E20_SHIFT                              (20U)
#define CSL_EVETPCC_EMCR_E20_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E20_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E19_MASK                               (0x00080000U)
#define CSL_EVETPCC_EMCR_E19_SHIFT                              (19U)
#define CSL_EVETPCC_EMCR_E19_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E19_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_E0_MASK                                (0x00000001U)
#define CSL_EVETPCC_EMCR_E0_SHIFT                               (0U)
#define CSL_EVETPCC_EMCR_E0_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E0_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E5_MASK                                (0x00000020U)
#define CSL_EVETPCC_EMCR_E5_SHIFT                               (5U)
#define CSL_EVETPCC_EMCR_E5_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E5_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E3_MASK                                (0x00000008U)
#define CSL_EVETPCC_EMCR_E3_SHIFT                               (3U)
#define CSL_EVETPCC_EMCR_E3_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EMCR_E3_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EMCR_E18_MASK                               (0x00040000U)
#define CSL_EVETPCC_EMCR_E18_SHIFT                              (18U)
#define CSL_EVETPCC_EMCR_E18_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EMCR_E18_MAX                                (0x00000001U)

#define CSL_EVETPCC_EMCR_RESETVAL                               (0x00000000U)

/* EMCRH */

#define CSL_EVETPCC_EMCRH_E41_MASK                              (0x00000200U)
#define CSL_EVETPCC_EMCRH_E41_SHIFT                             (9U)
#define CSL_EVETPCC_EMCRH_E41_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E41_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E60_MASK                              (0x10000000U)
#define CSL_EVETPCC_EMCRH_E60_SHIFT                             (28U)
#define CSL_EVETPCC_EMCRH_E60_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E60_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E43_MASK                              (0x00000800U)
#define CSL_EVETPCC_EMCRH_E43_SHIFT                             (11U)
#define CSL_EVETPCC_EMCRH_E43_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E43_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E63_MASK                              (0x80000000U)
#define CSL_EVETPCC_EMCRH_E63_SHIFT                             (31U)
#define CSL_EVETPCC_EMCRH_E63_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E63_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E55_MASK                              (0x00800000U)
#define CSL_EVETPCC_EMCRH_E55_SHIFT                             (23U)
#define CSL_EVETPCC_EMCRH_E55_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E55_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E38_MASK                              (0x00000040U)
#define CSL_EVETPCC_EMCRH_E38_SHIFT                             (6U)
#define CSL_EVETPCC_EMCRH_E38_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E38_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E62_MASK                              (0x40000000U)
#define CSL_EVETPCC_EMCRH_E62_SHIFT                             (30U)
#define CSL_EVETPCC_EMCRH_E62_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E62_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E34_MASK                              (0x00000004U)
#define CSL_EVETPCC_EMCRH_E34_SHIFT                             (2U)
#define CSL_EVETPCC_EMCRH_E34_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E34_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E46_MASK                              (0x00004000U)
#define CSL_EVETPCC_EMCRH_E46_SHIFT                             (14U)
#define CSL_EVETPCC_EMCRH_E46_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E46_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E42_MASK                              (0x00000400U)
#define CSL_EVETPCC_EMCRH_E42_SHIFT                             (10U)
#define CSL_EVETPCC_EMCRH_E42_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E42_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E48_MASK                              (0x00010000U)
#define CSL_EVETPCC_EMCRH_E48_SHIFT                             (16U)
#define CSL_EVETPCC_EMCRH_E48_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E48_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E32_MASK                              (0x00000001U)
#define CSL_EVETPCC_EMCRH_E32_SHIFT                             (0U)
#define CSL_EVETPCC_EMCRH_E32_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E32_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E44_MASK                              (0x00001000U)
#define CSL_EVETPCC_EMCRH_E44_SHIFT                             (12U)
#define CSL_EVETPCC_EMCRH_E44_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E44_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E50_MASK                              (0x00040000U)
#define CSL_EVETPCC_EMCRH_E50_SHIFT                             (18U)
#define CSL_EVETPCC_EMCRH_E50_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E50_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E53_MASK                              (0x00200000U)
#define CSL_EVETPCC_EMCRH_E53_SHIFT                             (21U)
#define CSL_EVETPCC_EMCRH_E53_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E53_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E37_MASK                              (0x00000020U)
#define CSL_EVETPCC_EMCRH_E37_SHIFT                             (5U)
#define CSL_EVETPCC_EMCRH_E37_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E37_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E45_MASK                              (0x00002000U)
#define CSL_EVETPCC_EMCRH_E45_SHIFT                             (13U)
#define CSL_EVETPCC_EMCRH_E45_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E45_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E59_MASK                              (0x08000000U)
#define CSL_EVETPCC_EMCRH_E59_SHIFT                             (27U)
#define CSL_EVETPCC_EMCRH_E59_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E59_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E58_MASK                              (0x04000000U)
#define CSL_EVETPCC_EMCRH_E58_SHIFT                             (26U)
#define CSL_EVETPCC_EMCRH_E58_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E58_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E40_MASK                              (0x00000100U)
#define CSL_EVETPCC_EMCRH_E40_SHIFT                             (8U)
#define CSL_EVETPCC_EMCRH_E40_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E40_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E54_MASK                              (0x00400000U)
#define CSL_EVETPCC_EMCRH_E54_SHIFT                             (22U)
#define CSL_EVETPCC_EMCRH_E54_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E54_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E49_MASK                              (0x00020000U)
#define CSL_EVETPCC_EMCRH_E49_SHIFT                             (17U)
#define CSL_EVETPCC_EMCRH_E49_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E49_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E33_MASK                              (0x00000002U)
#define CSL_EVETPCC_EMCRH_E33_SHIFT                             (1U)
#define CSL_EVETPCC_EMCRH_E33_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E33_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E47_MASK                              (0x00008000U)
#define CSL_EVETPCC_EMCRH_E47_SHIFT                             (15U)
#define CSL_EVETPCC_EMCRH_E47_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E47_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E36_MASK                              (0x00000010U)
#define CSL_EVETPCC_EMCRH_E36_SHIFT                             (4U)
#define CSL_EVETPCC_EMCRH_E36_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E36_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E56_MASK                              (0x01000000U)
#define CSL_EVETPCC_EMCRH_E56_SHIFT                             (24U)
#define CSL_EVETPCC_EMCRH_E56_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E56_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E57_MASK                              (0x02000000U)
#define CSL_EVETPCC_EMCRH_E57_SHIFT                             (25U)
#define CSL_EVETPCC_EMCRH_E57_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E57_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E51_MASK                              (0x00080000U)
#define CSL_EVETPCC_EMCRH_E51_SHIFT                             (19U)
#define CSL_EVETPCC_EMCRH_E51_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E51_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E61_MASK                              (0x20000000U)
#define CSL_EVETPCC_EMCRH_E61_SHIFT                             (29U)
#define CSL_EVETPCC_EMCRH_E61_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E61_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E39_MASK                              (0x00000080U)
#define CSL_EVETPCC_EMCRH_E39_SHIFT                             (7U)
#define CSL_EVETPCC_EMCRH_E39_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E39_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E52_MASK                              (0x00100000U)
#define CSL_EVETPCC_EMCRH_E52_SHIFT                             (20U)
#define CSL_EVETPCC_EMCRH_E52_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E52_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_E35_MASK                              (0x00000008U)
#define CSL_EVETPCC_EMCRH_E35_SHIFT                             (3U)
#define CSL_EVETPCC_EMCRH_E35_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EMCRH_E35_MAX                               (0x00000001U)

#define CSL_EVETPCC_EMCRH_RESETVAL                              (0x00000000U)

/* QEMR */

#define CSL_EVETPCC_QEMR_E7_MASK                                (0x00000080U)
#define CSL_EVETPCC_QEMR_E7_SHIFT                               (7U)
#define CSL_EVETPCC_QEMR_E7_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEMR_E7_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEMR_E6_MASK                                (0x00000040U)
#define CSL_EVETPCC_QEMR_E6_SHIFT                               (6U)
#define CSL_EVETPCC_QEMR_E6_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEMR_E6_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEMR_E5_MASK                                (0x00000020U)
#define CSL_EVETPCC_QEMR_E5_SHIFT                               (5U)
#define CSL_EVETPCC_QEMR_E5_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEMR_E5_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEMR_E4_MASK                                (0x00000010U)
#define CSL_EVETPCC_QEMR_E4_SHIFT                               (4U)
#define CSL_EVETPCC_QEMR_E4_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEMR_E4_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEMR_E3_MASK                                (0x00000008U)
#define CSL_EVETPCC_QEMR_E3_SHIFT                               (3U)
#define CSL_EVETPCC_QEMR_E3_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEMR_E3_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEMR_E2_MASK                                (0x00000004U)
#define CSL_EVETPCC_QEMR_E2_SHIFT                               (2U)
#define CSL_EVETPCC_QEMR_E2_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEMR_E2_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEMR_E1_MASK                                (0x00000002U)
#define CSL_EVETPCC_QEMR_E1_SHIFT                               (1U)
#define CSL_EVETPCC_QEMR_E1_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEMR_E1_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEMR_E0_MASK                                (0x00000001U)
#define CSL_EVETPCC_QEMR_E0_SHIFT                               (0U)
#define CSL_EVETPCC_QEMR_E0_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEMR_E0_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEMR_RESETVAL                               (0x00000000U)

/* QEMCR */

#define CSL_EVETPCC_QEMCR_E7_MASK                               (0x00000080U)
#define CSL_EVETPCC_QEMCR_E7_SHIFT                              (7U)
#define CSL_EVETPCC_QEMCR_E7_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEMCR_E7_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEMCR_E6_MASK                               (0x00000040U)
#define CSL_EVETPCC_QEMCR_E6_SHIFT                              (6U)
#define CSL_EVETPCC_QEMCR_E6_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEMCR_E6_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEMCR_E5_MASK                               (0x00000020U)
#define CSL_EVETPCC_QEMCR_E5_SHIFT                              (5U)
#define CSL_EVETPCC_QEMCR_E5_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEMCR_E5_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEMCR_E4_MASK                               (0x00000010U)
#define CSL_EVETPCC_QEMCR_E4_SHIFT                              (4U)
#define CSL_EVETPCC_QEMCR_E4_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEMCR_E4_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEMCR_E3_MASK                               (0x00000008U)
#define CSL_EVETPCC_QEMCR_E3_SHIFT                              (3U)
#define CSL_EVETPCC_QEMCR_E3_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEMCR_E3_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEMCR_E2_MASK                               (0x00000004U)
#define CSL_EVETPCC_QEMCR_E2_SHIFT                              (2U)
#define CSL_EVETPCC_QEMCR_E2_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEMCR_E2_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEMCR_E1_MASK                               (0x00000002U)
#define CSL_EVETPCC_QEMCR_E1_SHIFT                              (1U)
#define CSL_EVETPCC_QEMCR_E1_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEMCR_E1_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEMCR_E0_MASK                               (0x00000001U)
#define CSL_EVETPCC_QEMCR_E0_SHIFT                              (0U)
#define CSL_EVETPCC_QEMCR_E0_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEMCR_E0_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEMCR_RESETVAL                              (0x00000000U)

/* CCERR */

#define CSL_EVETPCC_CCERR_QTHRXCD0_MASK                         (0x00000001U)
#define CSL_EVETPCC_CCERR_QTHRXCD0_SHIFT                        (0U)
#define CSL_EVETPCC_CCERR_QTHRXCD0_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCERR_QTHRXCD0_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCERR_TCERR_MASK                            (0x00010000U)
#define CSL_EVETPCC_CCERR_TCERR_SHIFT                           (16U)
#define CSL_EVETPCC_CCERR_TCERR_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CCERR_TCERR_MAX                             (0x00000001U)

#define CSL_EVETPCC_CCERR_QTHRXCD1_MASK                         (0x00000002U)
#define CSL_EVETPCC_CCERR_QTHRXCD1_SHIFT                        (1U)
#define CSL_EVETPCC_CCERR_QTHRXCD1_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCERR_QTHRXCD1_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCERR_QTHRXCD2_MASK                         (0x00000004U)
#define CSL_EVETPCC_CCERR_QTHRXCD2_SHIFT                        (2U)
#define CSL_EVETPCC_CCERR_QTHRXCD2_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCERR_QTHRXCD2_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCERR_QTHRXCD3_MASK                         (0x00000008U)
#define CSL_EVETPCC_CCERR_QTHRXCD3_SHIFT                        (3U)
#define CSL_EVETPCC_CCERR_QTHRXCD3_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCERR_QTHRXCD3_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCERR_QTHRXCD4_MASK                         (0x00000010U)
#define CSL_EVETPCC_CCERR_QTHRXCD4_SHIFT                        (4U)
#define CSL_EVETPCC_CCERR_QTHRXCD4_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCERR_QTHRXCD4_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCERR_QTHRXCD5_MASK                         (0x00000020U)
#define CSL_EVETPCC_CCERR_QTHRXCD5_SHIFT                        (5U)
#define CSL_EVETPCC_CCERR_QTHRXCD5_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCERR_QTHRXCD5_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCERR_QTHRXCD6_MASK                         (0x00000040U)
#define CSL_EVETPCC_CCERR_QTHRXCD6_SHIFT                        (6U)
#define CSL_EVETPCC_CCERR_QTHRXCD6_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCERR_QTHRXCD6_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCERR_QTHRXCD7_MASK                         (0x00000080U)
#define CSL_EVETPCC_CCERR_QTHRXCD7_SHIFT                        (7U)
#define CSL_EVETPCC_CCERR_QTHRXCD7_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCERR_QTHRXCD7_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCERR_RESETVAL                              (0x00000000U)

/* CCERRCLR */

#define CSL_EVETPCC_CCERRCLR_QTHRXCD0_MASK                      (0x00000001U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD0_SHIFT                     (0U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD0_RESETVAL                  (0x00000000U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD0_MAX                       (0x00000001U)

#define CSL_EVETPCC_CCERRCLR_QTHRXCD1_MASK                      (0x00000002U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD1_SHIFT                     (1U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD1_RESETVAL                  (0x00000000U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD1_MAX                       (0x00000001U)

#define CSL_EVETPCC_CCERRCLR_QTHRXCD2_MASK                      (0x00000004U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD2_SHIFT                     (2U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD2_RESETVAL                  (0x00000000U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD2_MAX                       (0x00000001U)

#define CSL_EVETPCC_CCERRCLR_QTHRXCD3_MASK                      (0x00000008U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD3_SHIFT                     (3U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD3_RESETVAL                  (0x00000000U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD3_MAX                       (0x00000001U)

#define CSL_EVETPCC_CCERRCLR_QTHRXCD4_MASK                      (0x00000010U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD4_SHIFT                     (4U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD4_RESETVAL                  (0x00000000U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD4_MAX                       (0x00000001U)

#define CSL_EVETPCC_CCERRCLR_QTHRXCD5_MASK                      (0x00000020U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD5_SHIFT                     (5U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD5_RESETVAL                  (0x00000000U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD5_MAX                       (0x00000001U)

#define CSL_EVETPCC_CCERRCLR_QTHRXCD6_MASK                      (0x00000040U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD6_SHIFT                     (6U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD6_RESETVAL                  (0x00000000U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD6_MAX                       (0x00000001U)

#define CSL_EVETPCC_CCERRCLR_QTHRXCD7_MASK                      (0x00000080U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD7_SHIFT                     (7U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD7_RESETVAL                  (0x00000000U)
#define CSL_EVETPCC_CCERRCLR_QTHRXCD7_MAX                       (0x00000001U)

#define CSL_EVETPCC_CCERRCLR_TCERR_MASK                         (0x00010000U)
#define CSL_EVETPCC_CCERRCLR_TCERR_SHIFT                        (16U)
#define CSL_EVETPCC_CCERRCLR_TCERR_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCERRCLR_TCERR_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCERRCLR_RESETVAL                           (0x00000000U)

/* EEVAL */

#define CSL_EVETPCC_EEVAL_SET_MASK                              (0x00000002U)
#define CSL_EVETPCC_EEVAL_SET_SHIFT                             (1U)
#define CSL_EVETPCC_EEVAL_SET_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EEVAL_SET_MAX                               (0x00000001U)

#define CSL_EVETPCC_EEVAL_EVAL_MASK                             (0x00000001U)
#define CSL_EVETPCC_EEVAL_EVAL_SHIFT                            (0U)
#define CSL_EVETPCC_EEVAL_EVAL_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EEVAL_EVAL_MAX                              (0x00000001U)

#define CSL_EVETPCC_EEVAL_RESETVAL                              (0x00000000U)

/* QRAEN */

#define CSL_EVETPCC_QRAEN_E3_MASK                               (0x00000008U)
#define CSL_EVETPCC_QRAEN_E3_SHIFT                              (3U)
#define CSL_EVETPCC_QRAEN_E3_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QRAEN_E3_MAX                                (0x00000001U)

#define CSL_EVETPCC_QRAEN_E4_MASK                               (0x00000010U)
#define CSL_EVETPCC_QRAEN_E4_SHIFT                              (4U)
#define CSL_EVETPCC_QRAEN_E4_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QRAEN_E4_MAX                                (0x00000001U)

#define CSL_EVETPCC_QRAEN_E5_MASK                               (0x00000020U)
#define CSL_EVETPCC_QRAEN_E5_SHIFT                              (5U)
#define CSL_EVETPCC_QRAEN_E5_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QRAEN_E5_MAX                                (0x00000001U)

#define CSL_EVETPCC_QRAEN_E1_MASK                               (0x00000002U)
#define CSL_EVETPCC_QRAEN_E1_SHIFT                              (1U)
#define CSL_EVETPCC_QRAEN_E1_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QRAEN_E1_MAX                                (0x00000001U)

#define CSL_EVETPCC_QRAEN_E7_MASK                               (0x00000080U)
#define CSL_EVETPCC_QRAEN_E7_SHIFT                              (7U)
#define CSL_EVETPCC_QRAEN_E7_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QRAEN_E7_MAX                                (0x00000001U)

#define CSL_EVETPCC_QRAEN_E0_MASK                               (0x00000001U)
#define CSL_EVETPCC_QRAEN_E0_SHIFT                              (0U)
#define CSL_EVETPCC_QRAEN_E0_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QRAEN_E0_MAX                                (0x00000001U)

#define CSL_EVETPCC_QRAEN_E6_MASK                               (0x00000040U)
#define CSL_EVETPCC_QRAEN_E6_SHIFT                              (6U)
#define CSL_EVETPCC_QRAEN_E6_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QRAEN_E6_MAX                                (0x00000001U)

#define CSL_EVETPCC_QRAEN_E2_MASK                               (0x00000004U)
#define CSL_EVETPCC_QRAEN_E2_SHIFT                              (2U)
#define CSL_EVETPCC_QRAEN_E2_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QRAEN_E2_MAX                                (0x00000001U)

#define CSL_EVETPCC_QRAEN_RESETVAL                              (0x00000000U)

/* QSTATN */

#define CSL_EVETPCC_QSTATN_STRTPTR_MASK                         (0x0000000FU)
#define CSL_EVETPCC_QSTATN_STRTPTR_SHIFT                        (0U)
#define CSL_EVETPCC_QSTATN_STRTPTR_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_QSTATN_STRTPTR_MAX                          (0x0000000fU)

#define CSL_EVETPCC_QSTATN_NUMVAL_MASK                          (0x00001F00U)
#define CSL_EVETPCC_QSTATN_NUMVAL_SHIFT                         (8U)
#define CSL_EVETPCC_QSTATN_NUMVAL_RESETVAL                      (0x00000000U)
#define CSL_EVETPCC_QSTATN_NUMVAL_MAX                           (0x0000001fU)

#define CSL_EVETPCC_QSTATN_WM_MASK                              (0x001F0000U)
#define CSL_EVETPCC_QSTATN_WM_SHIFT                             (16U)
#define CSL_EVETPCC_QSTATN_WM_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_QSTATN_WM_MAX                               (0x0000001fU)

#define CSL_EVETPCC_QSTATN_THRXCD_MASK                          (0x01000000U)
#define CSL_EVETPCC_QSTATN_THRXCD_SHIFT                         (24U)
#define CSL_EVETPCC_QSTATN_THRXCD_RESETVAL                      (0x00000000U)
#define CSL_EVETPCC_QSTATN_THRXCD_MAX                           (0x00000001U)

#define CSL_EVETPCC_QSTATN_RESETVAL                             (0x00000000U)

/* QWMTHRA */

#define CSL_EVETPCC_QWMTHRA_Q1_MASK                             (0x00001F00U)
#define CSL_EVETPCC_QWMTHRA_Q1_SHIFT                            (8U)
#define CSL_EVETPCC_QWMTHRA_Q1_RESETVAL                         (0x00000010U)
#define CSL_EVETPCC_QWMTHRA_Q1_MAX                              (0x0000001fU)

#define CSL_EVETPCC_QWMTHRA_Q0_MASK                             (0x0000001FU)
#define CSL_EVETPCC_QWMTHRA_Q0_SHIFT                            (0U)
#define CSL_EVETPCC_QWMTHRA_Q0_RESETVAL                         (0x00000010U)
#define CSL_EVETPCC_QWMTHRA_Q0_MAX                              (0x0000001fU)

#define CSL_EVETPCC_QWMTHRA_Q3_MASK                             (0x1F000000U)
#define CSL_EVETPCC_QWMTHRA_Q3_SHIFT                            (24U)
#define CSL_EVETPCC_QWMTHRA_Q3_RESETVAL                         (0x00000010U)
#define CSL_EVETPCC_QWMTHRA_Q3_MAX                              (0x0000001fU)

#define CSL_EVETPCC_QWMTHRA_Q2_MASK                             (0x001F0000U)
#define CSL_EVETPCC_QWMTHRA_Q2_SHIFT                            (16U)
#define CSL_EVETPCC_QWMTHRA_Q2_RESETVAL                         (0x00000010U)
#define CSL_EVETPCC_QWMTHRA_Q2_MAX                              (0x0000001fU)

#define CSL_EVETPCC_QWMTHRA_RESETVAL                            (0x10101010U)

/* QWMTHRB */

#define CSL_EVETPCC_QWMTHRB_Q6_MASK                             (0x001F0000U)
#define CSL_EVETPCC_QWMTHRB_Q6_SHIFT                            (16U)
#define CSL_EVETPCC_QWMTHRB_Q6_RESETVAL                         (0x00000010U)
#define CSL_EVETPCC_QWMTHRB_Q6_MAX                              (0x0000001fU)

#define CSL_EVETPCC_QWMTHRB_Q7_MASK                             (0x1F000000U)
#define CSL_EVETPCC_QWMTHRB_Q7_SHIFT                            (24U)
#define CSL_EVETPCC_QWMTHRB_Q7_RESETVAL                         (0x00000010U)
#define CSL_EVETPCC_QWMTHRB_Q7_MAX                              (0x0000001fU)

#define CSL_EVETPCC_QWMTHRB_Q4_MASK                             (0x0000001FU)
#define CSL_EVETPCC_QWMTHRB_Q4_SHIFT                            (0U)
#define CSL_EVETPCC_QWMTHRB_Q4_RESETVAL                         (0x00000010U)
#define CSL_EVETPCC_QWMTHRB_Q4_MAX                              (0x0000001fU)

#define CSL_EVETPCC_QWMTHRB_Q5_MASK                             (0x00001F00U)
#define CSL_EVETPCC_QWMTHRB_Q5_SHIFT                            (8U)
#define CSL_EVETPCC_QWMTHRB_Q5_RESETVAL                         (0x00000010U)
#define CSL_EVETPCC_QWMTHRB_Q5_MAX                              (0x0000001fU)

#define CSL_EVETPCC_QWMTHRB_RESETVAL                            (0x10101010U)

/* CCSTAT */

#define CSL_EVETPCC_CCSTAT_EVTACTV_MASK                         (0x00000001U)
#define CSL_EVETPCC_CCSTAT_EVTACTV_SHIFT                        (0U)
#define CSL_EVETPCC_CCSTAT_EVTACTV_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_CCSTAT_EVTACTV_MAX                          (0x00000001U)

#define CSL_EVETPCC_CCSTAT_QEVTACTV_MASK                        (0x00000002U)
#define CSL_EVETPCC_CCSTAT_QEVTACTV_SHIFT                       (1U)
#define CSL_EVETPCC_CCSTAT_QEVTACTV_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_QEVTACTV_MAX                         (0x00000001U)

#define CSL_EVETPCC_CCSTAT_TRACTV_MASK                          (0x00000004U)
#define CSL_EVETPCC_CCSTAT_TRACTV_SHIFT                         (2U)
#define CSL_EVETPCC_CCSTAT_TRACTV_RESETVAL                      (0x00000000U)
#define CSL_EVETPCC_CCSTAT_TRACTV_MAX                           (0x00000001U)

#define CSL_EVETPCC_CCSTAT_ACTV_MASK                            (0x00000010U)
#define CSL_EVETPCC_CCSTAT_ACTV_SHIFT                           (4U)
#define CSL_EVETPCC_CCSTAT_ACTV_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CCSTAT_ACTV_MAX                             (0x00000001U)

#define CSL_EVETPCC_CCSTAT_COMPACTV_MASK                        (0x00003F00U)
#define CSL_EVETPCC_CCSTAT_COMPACTV_SHIFT                       (8U)
#define CSL_EVETPCC_CCSTAT_COMPACTV_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_COMPACTV_MAX                         (0x0000003fU)

#define CSL_EVETPCC_CCSTAT_QUEACTV0_MASK                        (0x00010000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV0_SHIFT                       (16U)
#define CSL_EVETPCC_CCSTAT_QUEACTV0_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV0_MAX                         (0x00000001U)

#define CSL_EVETPCC_CCSTAT_QUEACTV1_MASK                        (0x00020000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV1_SHIFT                       (17U)
#define CSL_EVETPCC_CCSTAT_QUEACTV1_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV1_MAX                         (0x00000001U)

#define CSL_EVETPCC_CCSTAT_QUEACTV2_MASK                        (0x00040000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV2_SHIFT                       (18U)
#define CSL_EVETPCC_CCSTAT_QUEACTV2_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV2_MAX                         (0x00000001U)

#define CSL_EVETPCC_CCSTAT_QUEACTV3_MASK                        (0x00080000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV3_SHIFT                       (19U)
#define CSL_EVETPCC_CCSTAT_QUEACTV3_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV3_MAX                         (0x00000001U)

#define CSL_EVETPCC_CCSTAT_QUEACTV4_MASK                        (0x00100000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV4_SHIFT                       (20U)
#define CSL_EVETPCC_CCSTAT_QUEACTV4_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV4_MAX                         (0x00000001U)

#define CSL_EVETPCC_CCSTAT_QUEACTV5_MASK                        (0x00200000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV5_SHIFT                       (21U)
#define CSL_EVETPCC_CCSTAT_QUEACTV5_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV5_MAX                         (0x00000001U)

#define CSL_EVETPCC_CCSTAT_QUEACTV6_MASK                        (0x00400000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV6_SHIFT                       (22U)
#define CSL_EVETPCC_CCSTAT_QUEACTV6_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV6_MAX                         (0x00000001U)

#define CSL_EVETPCC_CCSTAT_QUEACTV7_MASK                        (0x00800000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV7_SHIFT                       (23U)
#define CSL_EVETPCC_CCSTAT_QUEACTV7_RESETVAL                    (0x00000000U)
#define CSL_EVETPCC_CCSTAT_QUEACTV7_MAX                         (0x00000001U)

#define CSL_EVETPCC_CCSTAT_RESETVAL                             (0x00000000U)

/* AETCTL */

#define CSL_EVETPCC_AETCTL_TYPE_MASK                            (0x00000040U)
#define CSL_EVETPCC_AETCTL_TYPE_SHIFT                           (6U)
#define CSL_EVETPCC_AETCTL_TYPE_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_AETCTL_TYPE_MAX                             (0x00000001U)

#define CSL_EVETPCC_AETCTL_STRTEVT_MASK                         (0x0000003FU)
#define CSL_EVETPCC_AETCTL_STRTEVT_SHIFT                        (0U)
#define CSL_EVETPCC_AETCTL_STRTEVT_RESETVAL                     (0x00000000U)
#define CSL_EVETPCC_AETCTL_STRTEVT_MAX                          (0x0000003fU)

#define CSL_EVETPCC_AETCTL_EN_MASK                              (0x80000000U)
#define CSL_EVETPCC_AETCTL_EN_SHIFT                             (31U)
#define CSL_EVETPCC_AETCTL_EN_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_AETCTL_EN_MAX                               (0x00000001U)

#define CSL_EVETPCC_AETCTL_ENDINT_MASK                          (0x00003F00U)
#define CSL_EVETPCC_AETCTL_ENDINT_SHIFT                         (8U)
#define CSL_EVETPCC_AETCTL_ENDINT_RESETVAL                      (0x00000000U)
#define CSL_EVETPCC_AETCTL_ENDINT_MAX                           (0x0000003fU)

#define CSL_EVETPCC_AETCTL_RESETVAL                             (0x00000000U)

/* AETSTAT */

#define CSL_EVETPCC_AETSTAT_STAT_MASK                           (0x00000001U)
#define CSL_EVETPCC_AETSTAT_STAT_SHIFT                          (0U)
#define CSL_EVETPCC_AETSTAT_STAT_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_AETSTAT_STAT_MAX                            (0x00000001U)

#define CSL_EVETPCC_AETSTAT_RESETVAL                            (0x00000000U)

/* AETCMD */

#define CSL_EVETPCC_AETCMD_CLR_MASK                             (0x00000001U)
#define CSL_EVETPCC_AETCMD_CLR_SHIFT                            (0U)
#define CSL_EVETPCC_AETCMD_CLR_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_AETCMD_CLR_MAX                              (0x00000001U)

#define CSL_EVETPCC_AETCMD_RESETVAL                             (0x00000000U)

/* MPFAR */

#define CSL_EVETPCC_MPFAR_FADDR_MASK                            (0xFFFFFFFFU)
#define CSL_EVETPCC_MPFAR_FADDR_SHIFT                           (0U)
#define CSL_EVETPCC_MPFAR_FADDR_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_MPFAR_FADDR_MAX                             (0xffffffffU)

#define CSL_EVETPCC_MPFAR_RESETVAL                              (0x00000000U)

/* MPFSR */

#define CSL_EVETPCC_MPFSR_FID_MASK                              (0x00001E00U)
#define CSL_EVETPCC_MPFSR_FID_SHIFT                             (9U)
#define CSL_EVETPCC_MPFSR_FID_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_MPFSR_FID_MAX                               (0x0000000fU)

#define CSL_EVETPCC_MPFSR_SECE_MASK                             (0x00000080U)
#define CSL_EVETPCC_MPFSR_SECE_SHIFT                            (7U)
#define CSL_EVETPCC_MPFSR_SECE_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_MPFSR_SECE_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPFSR_SXE_MASK                              (0x00000008U)
#define CSL_EVETPCC_MPFSR_SXE_SHIFT                             (3U)
#define CSL_EVETPCC_MPFSR_SXE_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_MPFSR_SXE_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPFSR_URE_MASK                              (0x00000004U)
#define CSL_EVETPCC_MPFSR_URE_SHIFT                             (2U)
#define CSL_EVETPCC_MPFSR_URE_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_MPFSR_URE_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPFSR_SRE_MASK                              (0x00000020U)
#define CSL_EVETPCC_MPFSR_SRE_SHIFT                             (5U)
#define CSL_EVETPCC_MPFSR_SRE_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_MPFSR_SRE_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPFSR_SWE_MASK                              (0x00000010U)
#define CSL_EVETPCC_MPFSR_SWE_SHIFT                             (4U)
#define CSL_EVETPCC_MPFSR_SWE_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_MPFSR_SWE_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPFSR_UWE_MASK                              (0x00000002U)
#define CSL_EVETPCC_MPFSR_UWE_SHIFT                             (1U)
#define CSL_EVETPCC_MPFSR_UWE_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_MPFSR_UWE_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPFSR_UXE_MASK                              (0x00000001U)
#define CSL_EVETPCC_MPFSR_UXE_SHIFT                             (0U)
#define CSL_EVETPCC_MPFSR_UXE_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_MPFSR_UXE_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPFSR_RESETVAL                              (0x00000000U)

/* MPFCR */

#define CSL_EVETPCC_MPFCR_MPFCLR_MASK                           (0x00000001U)
#define CSL_EVETPCC_MPFCR_MPFCLR_SHIFT                          (0U)
#define CSL_EVETPCC_MPFCR_MPFCLR_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_MPFCR_MPFCLR_MAX                            (0x00000001U)

#define CSL_EVETPCC_MPFCR_RESETVAL                              (0x00000000U)

/* MPPAG */

#define CSL_EVETPCC_MPPAG_EMU_MASK                              (0x00000040U)
#define CSL_EVETPCC_MPPAG_EMU_SHIFT                             (6U)
#define CSL_EVETPCC_MPPAG_EMU_RESETVAL                          (0x00000001U)
#define CSL_EVETPCC_MPPAG_EMU_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPPAG_EXT_MASK                              (0x00000200U)
#define CSL_EVETPCC_MPPAG_EXT_SHIFT                             (9U)
#define CSL_EVETPCC_MPPAG_EXT_RESETVAL                          (0x00000001U)
#define CSL_EVETPCC_MPPAG_EXT_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPPAG_SR_MASK                               (0x00000020U)
#define CSL_EVETPCC_MPPAG_SR_SHIFT                              (5U)
#define CSL_EVETPCC_MPPAG_SR_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAG_SR_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAG_AID4_MASK                             (0x00004000U)
#define CSL_EVETPCC_MPPAG_AID4_SHIFT                            (14U)
#define CSL_EVETPCC_MPPAG_AID4_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAG_AID4_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAG_UR_MASK                               (0x00000004U)
#define CSL_EVETPCC_MPPAG_UR_SHIFT                              (2U)
#define CSL_EVETPCC_MPPAG_UR_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAG_UR_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAG_AID5_MASK                             (0x00008000U)
#define CSL_EVETPCC_MPPAG_AID5_SHIFT                            (15U)
#define CSL_EVETPCC_MPPAG_AID5_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAG_AID5_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAG_NS_MASK                               (0x00000080U)
#define CSL_EVETPCC_MPPAG_NS_SHIFT                              (7U)
#define CSL_EVETPCC_MPPAG_NS_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAG_NS_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAG_SW_MASK                               (0x00000010U)
#define CSL_EVETPCC_MPPAG_SW_SHIFT                              (4U)
#define CSL_EVETPCC_MPPAG_SW_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAG_SW_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAG_UW_MASK                               (0x00000002U)
#define CSL_EVETPCC_MPPAG_UW_SHIFT                              (1U)
#define CSL_EVETPCC_MPPAG_UW_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAG_UW_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAG_AID0_MASK                             (0x00000400U)
#define CSL_EVETPCC_MPPAG_AID0_SHIFT                            (10U)
#define CSL_EVETPCC_MPPAG_AID0_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAG_AID0_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAG_AID1_MASK                             (0x00000800U)
#define CSL_EVETPCC_MPPAG_AID1_SHIFT                            (11U)
#define CSL_EVETPCC_MPPAG_AID1_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAG_AID1_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAG_SX_MASK                               (0x00000008U)
#define CSL_EVETPCC_MPPAG_SX_SHIFT                              (3U)
#define CSL_EVETPCC_MPPAG_SX_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_MPPAG_SX_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAG_AID2_MASK                             (0x00001000U)
#define CSL_EVETPCC_MPPAG_AID2_SHIFT                            (12U)
#define CSL_EVETPCC_MPPAG_AID2_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAG_AID2_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAG_UX_MASK                               (0x00000001U)
#define CSL_EVETPCC_MPPAG_UX_SHIFT                              (0U)
#define CSL_EVETPCC_MPPAG_UX_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_MPPAG_UX_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAG_AID3_MASK                             (0x00002000U)
#define CSL_EVETPCC_MPPAG_AID3_SHIFT                            (13U)
#define CSL_EVETPCC_MPPAG_AID3_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAG_AID3_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAG_RESETVAL                              (0x0000fff6U)

/* MPPAN */

#define CSL_EVETPCC_MPPAN_AID5_MASK                             (0x00008000U)
#define CSL_EVETPCC_MPPAN_AID5_SHIFT                            (15U)
#define CSL_EVETPCC_MPPAN_AID5_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAN_AID5_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAN_AID4_MASK                             (0x00004000U)
#define CSL_EVETPCC_MPPAN_AID4_SHIFT                            (14U)
#define CSL_EVETPCC_MPPAN_AID4_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAN_AID4_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAN_AID3_MASK                             (0x00002000U)
#define CSL_EVETPCC_MPPAN_AID3_SHIFT                            (13U)
#define CSL_EVETPCC_MPPAN_AID3_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAN_AID3_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAN_AID2_MASK                             (0x00001000U)
#define CSL_EVETPCC_MPPAN_AID2_SHIFT                            (12U)
#define CSL_EVETPCC_MPPAN_AID2_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAN_AID2_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAN_AID1_MASK                             (0x00000800U)
#define CSL_EVETPCC_MPPAN_AID1_SHIFT                            (11U)
#define CSL_EVETPCC_MPPAN_AID1_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAN_AID1_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAN_AID0_MASK                             (0x00000400U)
#define CSL_EVETPCC_MPPAN_AID0_SHIFT                            (10U)
#define CSL_EVETPCC_MPPAN_AID0_RESETVAL                         (0x00000001U)
#define CSL_EVETPCC_MPPAN_AID0_MAX                              (0x00000001U)

#define CSL_EVETPCC_MPPAN_EXT_MASK                              (0x00000200U)
#define CSL_EVETPCC_MPPAN_EXT_SHIFT                             (9U)
#define CSL_EVETPCC_MPPAN_EXT_RESETVAL                          (0x00000001U)
#define CSL_EVETPCC_MPPAN_EXT_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPPAN_NS_MASK                               (0x00000080U)
#define CSL_EVETPCC_MPPAN_NS_SHIFT                              (7U)
#define CSL_EVETPCC_MPPAN_NS_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAN_NS_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAN_EMU_MASK                              (0x00000040U)
#define CSL_EVETPCC_MPPAN_EMU_SHIFT                             (6U)
#define CSL_EVETPCC_MPPAN_EMU_RESETVAL                          (0x00000001U)
#define CSL_EVETPCC_MPPAN_EMU_MAX                               (0x00000001U)

#define CSL_EVETPCC_MPPAN_SR_MASK                               (0x00000020U)
#define CSL_EVETPCC_MPPAN_SR_SHIFT                              (5U)
#define CSL_EVETPCC_MPPAN_SR_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAN_SR_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAN_SW_MASK                               (0x00000010U)
#define CSL_EVETPCC_MPPAN_SW_SHIFT                              (4U)
#define CSL_EVETPCC_MPPAN_SW_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAN_SW_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAN_SX_MASK                               (0x00000008U)
#define CSL_EVETPCC_MPPAN_SX_SHIFT                              (3U)
#define CSL_EVETPCC_MPPAN_SX_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_MPPAN_SX_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAN_UR_MASK                               (0x00000004U)
#define CSL_EVETPCC_MPPAN_UR_SHIFT                              (2U)
#define CSL_EVETPCC_MPPAN_UR_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAN_UR_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAN_UW_MASK                               (0x00000002U)
#define CSL_EVETPCC_MPPAN_UW_SHIFT                              (1U)
#define CSL_EVETPCC_MPPAN_UW_RESETVAL                           (0x00000001U)
#define CSL_EVETPCC_MPPAN_UW_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAN_UX_MASK                               (0x00000001U)
#define CSL_EVETPCC_MPPAN_UX_SHIFT                              (0U)
#define CSL_EVETPCC_MPPAN_UX_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_MPPAN_UX_MAX                                (0x00000001U)

#define CSL_EVETPCC_MPPAN_RESETVAL                              (0x0000fef6U)

/* ER */

#define CSL_EVETPCC_ER_E22_MASK                                 (0x00400000U)
#define CSL_EVETPCC_ER_E22_SHIFT                                (22U)
#define CSL_EVETPCC_ER_E22_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E22_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E2_MASK                                  (0x00000004U)
#define CSL_EVETPCC_ER_E2_SHIFT                                 (2U)
#define CSL_EVETPCC_ER_E2_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E2_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E19_MASK                                 (0x00080000U)
#define CSL_EVETPCC_ER_E19_SHIFT                                (19U)
#define CSL_EVETPCC_ER_E19_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E19_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E5_MASK                                  (0x00000020U)
#define CSL_EVETPCC_ER_E5_SHIFT                                 (5U)
#define CSL_EVETPCC_ER_E5_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E5_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E29_MASK                                 (0x20000000U)
#define CSL_EVETPCC_ER_E29_SHIFT                                (29U)
#define CSL_EVETPCC_ER_E29_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E29_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E18_MASK                                 (0x00040000U)
#define CSL_EVETPCC_ER_E18_SHIFT                                (18U)
#define CSL_EVETPCC_ER_E18_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E18_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E6_MASK                                  (0x00000040U)
#define CSL_EVETPCC_ER_E6_SHIFT                                 (6U)
#define CSL_EVETPCC_ER_E6_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E6_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E21_MASK                                 (0x00200000U)
#define CSL_EVETPCC_ER_E21_SHIFT                                (21U)
#define CSL_EVETPCC_ER_E21_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E21_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E3_MASK                                  (0x00000008U)
#define CSL_EVETPCC_ER_E3_SHIFT                                 (3U)
#define CSL_EVETPCC_ER_E3_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E3_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E31_MASK                                 (0x80000000U)
#define CSL_EVETPCC_ER_E31_SHIFT                                (31U)
#define CSL_EVETPCC_ER_E31_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E31_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E20_MASK                                 (0x00100000U)
#define CSL_EVETPCC_ER_E20_SHIFT                                (20U)
#define CSL_EVETPCC_ER_E20_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E20_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E4_MASK                                  (0x00000010U)
#define CSL_EVETPCC_ER_E4_SHIFT                                 (4U)
#define CSL_EVETPCC_ER_E4_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E4_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E9_MASK                                  (0x00000200U)
#define CSL_EVETPCC_ER_E9_SHIFT                                 (9U)
#define CSL_EVETPCC_ER_E9_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E9_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E28_MASK                                 (0x10000000U)
#define CSL_EVETPCC_ER_E28_SHIFT                                (28U)
#define CSL_EVETPCC_ER_E28_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E28_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E14_MASK                                 (0x00004000U)
#define CSL_EVETPCC_ER_E14_SHIFT                                (14U)
#define CSL_EVETPCC_ER_E14_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E14_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E10_MASK                                 (0x00000400U)
#define CSL_EVETPCC_ER_E10_SHIFT                                (10U)
#define CSL_EVETPCC_ER_E10_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E10_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E27_MASK                                 (0x08000000U)
#define CSL_EVETPCC_ER_E27_SHIFT                                (27U)
#define CSL_EVETPCC_ER_E27_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E27_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E7_MASK                                  (0x00000080U)
#define CSL_EVETPCC_ER_E7_SHIFT                                 (7U)
#define CSL_EVETPCC_ER_E7_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E7_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E17_MASK                                 (0x00020000U)
#define CSL_EVETPCC_ER_E17_SHIFT                                (17U)
#define CSL_EVETPCC_ER_E17_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E17_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E8_MASK                                  (0x00000100U)
#define CSL_EVETPCC_ER_E8_SHIFT                                 (8U)
#define CSL_EVETPCC_ER_E8_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E8_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E16_MASK                                 (0x00010000U)
#define CSL_EVETPCC_ER_E16_SHIFT                                (16U)
#define CSL_EVETPCC_ER_E16_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E16_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E30_MASK                                 (0x40000000U)
#define CSL_EVETPCC_ER_E30_SHIFT                                (30U)
#define CSL_EVETPCC_ER_E30_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E30_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E24_MASK                                 (0x01000000U)
#define CSL_EVETPCC_ER_E24_SHIFT                                (24U)
#define CSL_EVETPCC_ER_E24_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E24_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E23_MASK                                 (0x00800000U)
#define CSL_EVETPCC_ER_E23_SHIFT                                (23U)
#define CSL_EVETPCC_ER_E23_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E23_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E0_MASK                                  (0x00000001U)
#define CSL_EVETPCC_ER_E0_SHIFT                                 (0U)
#define CSL_EVETPCC_ER_E0_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E0_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E13_MASK                                 (0x00002000U)
#define CSL_EVETPCC_ER_E13_SHIFT                                (13U)
#define CSL_EVETPCC_ER_E13_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E13_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E11_MASK                                 (0x00000800U)
#define CSL_EVETPCC_ER_E11_SHIFT                                (11U)
#define CSL_EVETPCC_ER_E11_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E11_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E26_MASK                                 (0x04000000U)
#define CSL_EVETPCC_ER_E26_SHIFT                                (26U)
#define CSL_EVETPCC_ER_E26_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E26_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E1_MASK                                  (0x00000002U)
#define CSL_EVETPCC_ER_E1_SHIFT                                 (1U)
#define CSL_EVETPCC_ER_E1_RESETVAL                              (0x00000000U)
#define CSL_EVETPCC_ER_E1_MAX                                   (0x00000001U)

#define CSL_EVETPCC_ER_E12_MASK                                 (0x00001000U)
#define CSL_EVETPCC_ER_E12_SHIFT                                (12U)
#define CSL_EVETPCC_ER_E12_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E12_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E25_MASK                                 (0x02000000U)
#define CSL_EVETPCC_ER_E25_SHIFT                                (25U)
#define CSL_EVETPCC_ER_E25_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E25_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_E15_MASK                                 (0x00008000U)
#define CSL_EVETPCC_ER_E15_SHIFT                                (15U)
#define CSL_EVETPCC_ER_E15_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ER_E15_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ER_RESETVAL                                 (0x00000000U)

/* ERH */

#define CSL_EVETPCC_ERH_E61_MASK                                (0x20000000U)
#define CSL_EVETPCC_ERH_E61_SHIFT                               (29U)
#define CSL_EVETPCC_ERH_E61_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E61_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E54_MASK                                (0x00400000U)
#define CSL_EVETPCC_ERH_E54_SHIFT                               (22U)
#define CSL_EVETPCC_ERH_E54_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E54_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E55_MASK                                (0x00800000U)
#define CSL_EVETPCC_ERH_E55_SHIFT                               (23U)
#define CSL_EVETPCC_ERH_E55_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E55_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E59_MASK                                (0x08000000U)
#define CSL_EVETPCC_ERH_E59_SHIFT                               (27U)
#define CSL_EVETPCC_ERH_E59_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E59_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E50_MASK                                (0x00040000U)
#define CSL_EVETPCC_ERH_E50_SHIFT                               (18U)
#define CSL_EVETPCC_ERH_E50_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E50_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E52_MASK                                (0x00100000U)
#define CSL_EVETPCC_ERH_E52_SHIFT                               (20U)
#define CSL_EVETPCC_ERH_E52_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E52_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E53_MASK                                (0x00200000U)
#define CSL_EVETPCC_ERH_E53_SHIFT                               (21U)
#define CSL_EVETPCC_ERH_E53_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E53_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E51_MASK                                (0x00080000U)
#define CSL_EVETPCC_ERH_E51_SHIFT                               (19U)
#define CSL_EVETPCC_ERH_E51_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E51_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E36_MASK                                (0x00000010U)
#define CSL_EVETPCC_ERH_E36_SHIFT                               (4U)
#define CSL_EVETPCC_ERH_E36_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E36_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E40_MASK                                (0x00000100U)
#define CSL_EVETPCC_ERH_E40_SHIFT                               (8U)
#define CSL_EVETPCC_ERH_E40_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E40_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E39_MASK                                (0x00000080U)
#define CSL_EVETPCC_ERH_E39_SHIFT                               (7U)
#define CSL_EVETPCC_ERH_E39_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E39_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E38_MASK                                (0x00000040U)
#define CSL_EVETPCC_ERH_E38_SHIFT                               (6U)
#define CSL_EVETPCC_ERH_E38_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E38_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E42_MASK                                (0x00000400U)
#define CSL_EVETPCC_ERH_E42_SHIFT                               (10U)
#define CSL_EVETPCC_ERH_E42_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E42_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E49_MASK                                (0x00020000U)
#define CSL_EVETPCC_ERH_E49_SHIFT                               (17U)
#define CSL_EVETPCC_ERH_E49_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E49_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E41_MASK                                (0x00000200U)
#define CSL_EVETPCC_ERH_E41_SHIFT                               (9U)
#define CSL_EVETPCC_ERH_E41_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E41_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E32_MASK                                (0x00000001U)
#define CSL_EVETPCC_ERH_E32_SHIFT                               (0U)
#define CSL_EVETPCC_ERH_E32_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E32_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E35_MASK                                (0x00000008U)
#define CSL_EVETPCC_ERH_E35_SHIFT                               (3U)
#define CSL_EVETPCC_ERH_E35_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E35_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E43_MASK                                (0x00000800U)
#define CSL_EVETPCC_ERH_E43_SHIFT                               (11U)
#define CSL_EVETPCC_ERH_E43_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E43_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E34_MASK                                (0x00000004U)
#define CSL_EVETPCC_ERH_E34_SHIFT                               (2U)
#define CSL_EVETPCC_ERH_E34_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E34_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E44_MASK                                (0x00001000U)
#define CSL_EVETPCC_ERH_E44_SHIFT                               (12U)
#define CSL_EVETPCC_ERH_E44_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E44_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E37_MASK                                (0x00000020U)
#define CSL_EVETPCC_ERH_E37_SHIFT                               (5U)
#define CSL_EVETPCC_ERH_E37_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E37_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E45_MASK                                (0x00002000U)
#define CSL_EVETPCC_ERH_E45_SHIFT                               (13U)
#define CSL_EVETPCC_ERH_E45_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E45_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E58_MASK                                (0x04000000U)
#define CSL_EVETPCC_ERH_E58_SHIFT                               (26U)
#define CSL_EVETPCC_ERH_E58_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E58_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E62_MASK                                (0x40000000U)
#define CSL_EVETPCC_ERH_E62_SHIFT                               (30U)
#define CSL_EVETPCC_ERH_E62_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E62_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E46_MASK                                (0x00004000U)
#define CSL_EVETPCC_ERH_E46_SHIFT                               (14U)
#define CSL_EVETPCC_ERH_E46_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E46_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E57_MASK                                (0x02000000U)
#define CSL_EVETPCC_ERH_E57_SHIFT                               (25U)
#define CSL_EVETPCC_ERH_E57_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E57_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E63_MASK                                (0x80000000U)
#define CSL_EVETPCC_ERH_E63_SHIFT                               (31U)
#define CSL_EVETPCC_ERH_E63_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E63_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E47_MASK                                (0x00008000U)
#define CSL_EVETPCC_ERH_E47_SHIFT                               (15U)
#define CSL_EVETPCC_ERH_E47_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E47_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E56_MASK                                (0x01000000U)
#define CSL_EVETPCC_ERH_E56_SHIFT                               (24U)
#define CSL_EVETPCC_ERH_E56_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E56_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E48_MASK                                (0x00010000U)
#define CSL_EVETPCC_ERH_E48_SHIFT                               (16U)
#define CSL_EVETPCC_ERH_E48_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E48_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E33_MASK                                (0x00000002U)
#define CSL_EVETPCC_ERH_E33_SHIFT                               (1U)
#define CSL_EVETPCC_ERH_E33_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E33_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_E60_MASK                                (0x10000000U)
#define CSL_EVETPCC_ERH_E60_SHIFT                               (28U)
#define CSL_EVETPCC_ERH_E60_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ERH_E60_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ERH_RESETVAL                                (0x00000000U)

/* ECR */

#define CSL_EVETPCC_ECR_E16_MASK                                (0x00010000U)
#define CSL_EVETPCC_ECR_E16_SHIFT                               (16U)
#define CSL_EVETPCC_ECR_E16_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E16_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E10_MASK                                (0x00000400U)
#define CSL_EVETPCC_ECR_E10_SHIFT                               (10U)
#define CSL_EVETPCC_ECR_E10_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E10_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E30_MASK                                (0x40000000U)
#define CSL_EVETPCC_ECR_E30_SHIFT                               (30U)
#define CSL_EVETPCC_ECR_E30_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E30_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E19_MASK                                (0x00080000U)
#define CSL_EVETPCC_ECR_E19_SHIFT                               (19U)
#define CSL_EVETPCC_ECR_E19_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E19_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E29_MASK                                (0x20000000U)
#define CSL_EVETPCC_ECR_E29_SHIFT                               (29U)
#define CSL_EVETPCC_ECR_E29_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E29_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E12_MASK                                (0x00001000U)
#define CSL_EVETPCC_ECR_E12_SHIFT                               (12U)
#define CSL_EVETPCC_ECR_E12_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E12_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E18_MASK                                (0x00040000U)
#define CSL_EVETPCC_ECR_E18_SHIFT                               (18U)
#define CSL_EVETPCC_ECR_E18_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E18_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E11_MASK                                (0x00000800U)
#define CSL_EVETPCC_ECR_E11_SHIFT                               (11U)
#define CSL_EVETPCC_ECR_E11_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E11_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E21_MASK                                (0x00200000U)
#define CSL_EVETPCC_ECR_E21_SHIFT                               (21U)
#define CSL_EVETPCC_ECR_E21_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E21_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E31_MASK                                (0x80000000U)
#define CSL_EVETPCC_ECR_E31_SHIFT                               (31U)
#define CSL_EVETPCC_ECR_E31_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E31_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E14_MASK                                (0x00004000U)
#define CSL_EVETPCC_ECR_E14_SHIFT                               (14U)
#define CSL_EVETPCC_ECR_E14_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E14_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E26_MASK                                (0x04000000U)
#define CSL_EVETPCC_ECR_E26_SHIFT                               (26U)
#define CSL_EVETPCC_ECR_E26_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E26_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E13_MASK                                (0x00002000U)
#define CSL_EVETPCC_ECR_E13_SHIFT                               (13U)
#define CSL_EVETPCC_ECR_E13_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E13_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E25_MASK                                (0x02000000U)
#define CSL_EVETPCC_ECR_E25_SHIFT                               (25U)
#define CSL_EVETPCC_ECR_E25_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E25_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E15_MASK                                (0x00008000U)
#define CSL_EVETPCC_ECR_E15_SHIFT                               (15U)
#define CSL_EVETPCC_ECR_E15_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E15_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E28_MASK                                (0x10000000U)
#define CSL_EVETPCC_ECR_E28_SHIFT                               (28U)
#define CSL_EVETPCC_ECR_E28_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E28_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E17_MASK                                (0x00020000U)
#define CSL_EVETPCC_ECR_E17_SHIFT                               (17U)
#define CSL_EVETPCC_ECR_E17_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E17_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E27_MASK                                (0x08000000U)
#define CSL_EVETPCC_ECR_E27_SHIFT                               (27U)
#define CSL_EVETPCC_ECR_E27_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E27_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_ECR_E4_SHIFT                                (4U)
#define CSL_EVETPCC_ECR_E4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_E24_MASK                                (0x01000000U)
#define CSL_EVETPCC_ECR_E24_SHIFT                               (24U)
#define CSL_EVETPCC_ECR_E24_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E24_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_ECR_E2_SHIFT                                (2U)
#define CSL_EVETPCC_ECR_E2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_E3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_ECR_E3_SHIFT                                (3U)
#define CSL_EVETPCC_ECR_E3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_E0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_ECR_E0_SHIFT                                (0U)
#define CSL_EVETPCC_ECR_E0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_E20_MASK                                (0x00100000U)
#define CSL_EVETPCC_ECR_E20_SHIFT                               (20U)
#define CSL_EVETPCC_ECR_E20_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E20_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_ECR_E6_SHIFT                                (6U)
#define CSL_EVETPCC_ECR_E6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_E1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_ECR_E1_SHIFT                                (1U)
#define CSL_EVETPCC_ECR_E1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_E5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_ECR_E5_SHIFT                                (5U)
#define CSL_EVETPCC_ECR_E5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_E23_MASK                                (0x00800000U)
#define CSL_EVETPCC_ECR_E23_SHIFT                               (23U)
#define CSL_EVETPCC_ECR_E23_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E23_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E8_MASK                                 (0x00000100U)
#define CSL_EVETPCC_ECR_E8_SHIFT                                (8U)
#define CSL_EVETPCC_ECR_E8_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E8_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_E9_MASK                                 (0x00000200U)
#define CSL_EVETPCC_ECR_E9_SHIFT                                (9U)
#define CSL_EVETPCC_ECR_E9_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E9_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_E22_MASK                                (0x00400000U)
#define CSL_EVETPCC_ECR_E22_SHIFT                               (22U)
#define CSL_EVETPCC_ECR_E22_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ECR_E22_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ECR_E7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_ECR_E7_SHIFT                                (7U)
#define CSL_EVETPCC_ECR_E7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ECR_E7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ECR_RESETVAL                                (0x00000000U)

/* ECRH */

#define CSL_EVETPCC_ECRH_E50_MASK                               (0x00040000U)
#define CSL_EVETPCC_ECRH_E50_SHIFT                              (18U)
#define CSL_EVETPCC_ECRH_E50_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E50_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E36_MASK                               (0x00000010U)
#define CSL_EVETPCC_ECRH_E36_SHIFT                              (4U)
#define CSL_EVETPCC_ECRH_E36_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E36_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E60_MASK                               (0x10000000U)
#define CSL_EVETPCC_ECRH_E60_SHIFT                              (28U)
#define CSL_EVETPCC_ECRH_E60_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E60_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E49_MASK                               (0x00020000U)
#define CSL_EVETPCC_ECRH_E49_SHIFT                              (17U)
#define CSL_EVETPCC_ECRH_E49_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E49_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E37_MASK                               (0x00000020U)
#define CSL_EVETPCC_ECRH_E37_SHIFT                              (5U)
#define CSL_EVETPCC_ECRH_E37_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E37_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E48_MASK                               (0x00010000U)
#define CSL_EVETPCC_ECRH_E48_SHIFT                              (16U)
#define CSL_EVETPCC_ECRH_E48_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E48_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E58_MASK                               (0x04000000U)
#define CSL_EVETPCC_ECRH_E58_SHIFT                              (26U)
#define CSL_EVETPCC_ECRH_E58_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E58_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E38_MASK                               (0x00000040U)
#define CSL_EVETPCC_ECRH_E38_SHIFT                              (6U)
#define CSL_EVETPCC_ECRH_E38_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E38_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E63_MASK                               (0x80000000U)
#define CSL_EVETPCC_ECRH_E63_SHIFT                              (31U)
#define CSL_EVETPCC_ECRH_E63_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E63_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E47_MASK                               (0x00008000U)
#define CSL_EVETPCC_ECRH_E47_SHIFT                              (15U)
#define CSL_EVETPCC_ECRH_E47_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E47_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E39_MASK                               (0x00000080U)
#define CSL_EVETPCC_ECRH_E39_SHIFT                              (7U)
#define CSL_EVETPCC_ECRH_E39_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E39_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E32_MASK                               (0x00000001U)
#define CSL_EVETPCC_ECRH_E32_SHIFT                              (0U)
#define CSL_EVETPCC_ECRH_E32_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E32_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E51_MASK                               (0x00080000U)
#define CSL_EVETPCC_ECRH_E51_SHIFT                              (19U)
#define CSL_EVETPCC_ECRH_E51_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E51_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E33_MASK                               (0x00000002U)
#define CSL_EVETPCC_ECRH_E33_SHIFT                              (1U)
#define CSL_EVETPCC_ECRH_E33_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E33_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E34_MASK                               (0x00000004U)
#define CSL_EVETPCC_ECRH_E34_SHIFT                              (2U)
#define CSL_EVETPCC_ECRH_E34_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E34_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E35_MASK                               (0x00000008U)
#define CSL_EVETPCC_ECRH_E35_SHIFT                              (3U)
#define CSL_EVETPCC_ECRH_E35_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E35_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E42_MASK                               (0x00000400U)
#define CSL_EVETPCC_ECRH_E42_SHIFT                              (10U)
#define CSL_EVETPCC_ECRH_E42_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E42_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E52_MASK                               (0x00100000U)
#define CSL_EVETPCC_ECRH_E52_SHIFT                              (20U)
#define CSL_EVETPCC_ECRH_E52_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E52_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E41_MASK                               (0x00000200U)
#define CSL_EVETPCC_ECRH_E41_SHIFT                              (9U)
#define CSL_EVETPCC_ECRH_E41_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E41_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E55_MASK                               (0x00800000U)
#define CSL_EVETPCC_ECRH_E55_SHIFT                              (23U)
#define CSL_EVETPCC_ECRH_E55_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E55_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E53_MASK                               (0x00200000U)
#define CSL_EVETPCC_ECRH_E53_SHIFT                              (21U)
#define CSL_EVETPCC_ECRH_E53_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E53_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E46_MASK                               (0x00004000U)
#define CSL_EVETPCC_ECRH_E46_SHIFT                              (14U)
#define CSL_EVETPCC_ECRH_E46_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E46_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E62_MASK                               (0x40000000U)
#define CSL_EVETPCC_ECRH_E62_SHIFT                              (30U)
#define CSL_EVETPCC_ECRH_E62_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E62_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E40_MASK                               (0x00000100U)
#define CSL_EVETPCC_ECRH_E40_SHIFT                              (8U)
#define CSL_EVETPCC_ECRH_E40_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E40_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E56_MASK                               (0x01000000U)
#define CSL_EVETPCC_ECRH_E56_SHIFT                              (24U)
#define CSL_EVETPCC_ECRH_E56_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E56_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E61_MASK                               (0x20000000U)
#define CSL_EVETPCC_ECRH_E61_SHIFT                              (29U)
#define CSL_EVETPCC_ECRH_E61_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E61_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E45_MASK                               (0x00002000U)
#define CSL_EVETPCC_ECRH_E45_SHIFT                              (13U)
#define CSL_EVETPCC_ECRH_E45_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E45_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E59_MASK                               (0x08000000U)
#define CSL_EVETPCC_ECRH_E59_SHIFT                              (27U)
#define CSL_EVETPCC_ECRH_E59_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E59_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E44_MASK                               (0x00001000U)
#define CSL_EVETPCC_ECRH_E44_SHIFT                              (12U)
#define CSL_EVETPCC_ECRH_E44_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E44_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E54_MASK                               (0x00400000U)
#define CSL_EVETPCC_ECRH_E54_SHIFT                              (22U)
#define CSL_EVETPCC_ECRH_E54_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E54_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E43_MASK                               (0x00000800U)
#define CSL_EVETPCC_ECRH_E43_SHIFT                              (11U)
#define CSL_EVETPCC_ECRH_E43_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E43_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_E57_MASK                               (0x02000000U)
#define CSL_EVETPCC_ECRH_E57_SHIFT                              (25U)
#define CSL_EVETPCC_ECRH_E57_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ECRH_E57_MAX                                (0x00000001U)

#define CSL_EVETPCC_ECRH_RESETVAL                               (0x00000000U)

/* ESR */

#define CSL_EVETPCC_ESR_E3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_ESR_E3_SHIFT                                (3U)
#define CSL_EVETPCC_ESR_E3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_ESR_E6_SHIFT                                (6U)
#define CSL_EVETPCC_ESR_E6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E20_MASK                                (0x00100000U)
#define CSL_EVETPCC_ESR_E20_SHIFT                               (20U)
#define CSL_EVETPCC_ESR_E20_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E20_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_ESR_E1_SHIFT                                (1U)
#define CSL_EVETPCC_ESR_E1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_ESR_E4_SHIFT                                (4U)
#define CSL_EVETPCC_ESR_E4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E18_MASK                                (0x00040000U)
#define CSL_EVETPCC_ESR_E18_SHIFT                               (18U)
#define CSL_EVETPCC_ESR_E18_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E18_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_ESR_E7_SHIFT                                (7U)
#define CSL_EVETPCC_ESR_E7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E11_MASK                                (0x00000800U)
#define CSL_EVETPCC_ESR_E11_SHIFT                               (11U)
#define CSL_EVETPCC_ESR_E11_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E11_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E10_MASK                                (0x00000400U)
#define CSL_EVETPCC_ESR_E10_SHIFT                               (10U)
#define CSL_EVETPCC_ESR_E10_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E10_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_ESR_E5_SHIFT                                (5U)
#define CSL_EVETPCC_ESR_E5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E8_MASK                                 (0x00000100U)
#define CSL_EVETPCC_ESR_E8_SHIFT                                (8U)
#define CSL_EVETPCC_ESR_E8_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E8_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E22_MASK                                (0x00400000U)
#define CSL_EVETPCC_ESR_E22_SHIFT                               (22U)
#define CSL_EVETPCC_ESR_E22_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E22_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E21_MASK                                (0x00200000U)
#define CSL_EVETPCC_ESR_E21_SHIFT                               (21U)
#define CSL_EVETPCC_ESR_E21_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E21_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E23_MASK                                (0x00800000U)
#define CSL_EVETPCC_ESR_E23_SHIFT                               (23U)
#define CSL_EVETPCC_ESR_E23_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E23_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E31_MASK                                (0x80000000U)
#define CSL_EVETPCC_ESR_E31_SHIFT                               (31U)
#define CSL_EVETPCC_ESR_E31_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E31_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E15_MASK                                (0x00008000U)
#define CSL_EVETPCC_ESR_E15_SHIFT                               (15U)
#define CSL_EVETPCC_ESR_E15_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E15_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E26_MASK                                (0x04000000U)
#define CSL_EVETPCC_ESR_E26_SHIFT                               (26U)
#define CSL_EVETPCC_ESR_E26_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E26_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E24_MASK                                (0x01000000U)
#define CSL_EVETPCC_ESR_E24_SHIFT                               (24U)
#define CSL_EVETPCC_ESR_E24_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E24_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E12_MASK                                (0x00001000U)
#define CSL_EVETPCC_ESR_E12_SHIFT                               (12U)
#define CSL_EVETPCC_ESR_E12_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E12_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E13_MASK                                (0x00002000U)
#define CSL_EVETPCC_ESR_E13_SHIFT                               (13U)
#define CSL_EVETPCC_ESR_E13_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E13_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E9_MASK                                 (0x00000200U)
#define CSL_EVETPCC_ESR_E9_SHIFT                                (9U)
#define CSL_EVETPCC_ESR_E9_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E9_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E28_MASK                                (0x10000000U)
#define CSL_EVETPCC_ESR_E28_SHIFT                               (28U)
#define CSL_EVETPCC_ESR_E28_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E28_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E25_MASK                                (0x02000000U)
#define CSL_EVETPCC_ESR_E25_SHIFT                               (25U)
#define CSL_EVETPCC_ESR_E25_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E25_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_ESR_E0_SHIFT                                (0U)
#define CSL_EVETPCC_ESR_E0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E19_MASK                                (0x00080000U)
#define CSL_EVETPCC_ESR_E19_SHIFT                               (19U)
#define CSL_EVETPCC_ESR_E19_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E19_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E16_MASK                                (0x00010000U)
#define CSL_EVETPCC_ESR_E16_SHIFT                               (16U)
#define CSL_EVETPCC_ESR_E16_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E16_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_ESR_E2_SHIFT                                (2U)
#define CSL_EVETPCC_ESR_E2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ESR_E2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ESR_E27_MASK                                (0x08000000U)
#define CSL_EVETPCC_ESR_E27_SHIFT                               (27U)
#define CSL_EVETPCC_ESR_E27_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E27_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E17_MASK                                (0x00020000U)
#define CSL_EVETPCC_ESR_E17_SHIFT                               (17U)
#define CSL_EVETPCC_ESR_E17_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E17_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E30_MASK                                (0x40000000U)
#define CSL_EVETPCC_ESR_E30_SHIFT                               (30U)
#define CSL_EVETPCC_ESR_E30_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E30_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E14_MASK                                (0x00004000U)
#define CSL_EVETPCC_ESR_E14_SHIFT                               (14U)
#define CSL_EVETPCC_ESR_E14_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E14_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_E29_MASK                                (0x20000000U)
#define CSL_EVETPCC_ESR_E29_SHIFT                               (29U)
#define CSL_EVETPCC_ESR_E29_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ESR_E29_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ESR_RESETVAL                                (0x00000000U)

/* ESRH */

#define CSL_EVETPCC_ESRH_E41_MASK                               (0x00000200U)
#define CSL_EVETPCC_ESRH_E41_SHIFT                              (9U)
#define CSL_EVETPCC_ESRH_E41_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E41_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E57_MASK                               (0x02000000U)
#define CSL_EVETPCC_ESRH_E57_SHIFT                              (25U)
#define CSL_EVETPCC_ESRH_E57_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E57_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E46_MASK                               (0x00004000U)
#define CSL_EVETPCC_ESRH_E46_SHIFT                              (14U)
#define CSL_EVETPCC_ESRH_E46_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E46_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E42_MASK                               (0x00000400U)
#define CSL_EVETPCC_ESRH_E42_SHIFT                              (10U)
#define CSL_EVETPCC_ESRH_E42_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E42_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E56_MASK                               (0x01000000U)
#define CSL_EVETPCC_ESRH_E56_SHIFT                              (24U)
#define CSL_EVETPCC_ESRH_E56_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E56_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E33_MASK                               (0x00000002U)
#define CSL_EVETPCC_ESRH_E33_SHIFT                              (1U)
#define CSL_EVETPCC_ESRH_E33_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E33_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E43_MASK                               (0x00000800U)
#define CSL_EVETPCC_ESRH_E43_SHIFT                              (11U)
#define CSL_EVETPCC_ESRH_E43_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E43_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E55_MASK                               (0x00800000U)
#define CSL_EVETPCC_ESRH_E55_SHIFT                              (23U)
#define CSL_EVETPCC_ESRH_E55_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E55_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E32_MASK                               (0x00000001U)
#define CSL_EVETPCC_ESRH_E32_SHIFT                              (0U)
#define CSL_EVETPCC_ESRH_E32_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E32_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E48_MASK                               (0x00010000U)
#define CSL_EVETPCC_ESRH_E48_SHIFT                              (16U)
#define CSL_EVETPCC_ESRH_E48_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E48_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E44_MASK                               (0x00001000U)
#define CSL_EVETPCC_ESRH_E44_SHIFT                              (12U)
#define CSL_EVETPCC_ESRH_E44_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E44_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E45_MASK                               (0x00002000U)
#define CSL_EVETPCC_ESRH_E45_SHIFT                              (13U)
#define CSL_EVETPCC_ESRH_E45_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E45_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E49_MASK                               (0x00020000U)
#define CSL_EVETPCC_ESRH_E49_SHIFT                              (17U)
#define CSL_EVETPCC_ESRH_E49_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E49_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E61_MASK                               (0x20000000U)
#define CSL_EVETPCC_ESRH_E61_SHIFT                              (29U)
#define CSL_EVETPCC_ESRH_E61_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E61_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E52_MASK                               (0x00100000U)
#define CSL_EVETPCC_ESRH_E52_SHIFT                              (20U)
#define CSL_EVETPCC_ESRH_E52_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E52_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E63_MASK                               (0x80000000U)
#define CSL_EVETPCC_ESRH_E63_SHIFT                              (31U)
#define CSL_EVETPCC_ESRH_E63_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E63_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E34_MASK                               (0x00000004U)
#define CSL_EVETPCC_ESRH_E34_SHIFT                              (2U)
#define CSL_EVETPCC_ESRH_E34_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E34_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E47_MASK                               (0x00008000U)
#define CSL_EVETPCC_ESRH_E47_SHIFT                              (15U)
#define CSL_EVETPCC_ESRH_E47_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E47_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E60_MASK                               (0x10000000U)
#define CSL_EVETPCC_ESRH_E60_SHIFT                              (28U)
#define CSL_EVETPCC_ESRH_E60_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E60_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E59_MASK                               (0x08000000U)
#define CSL_EVETPCC_ESRH_E59_SHIFT                              (27U)
#define CSL_EVETPCC_ESRH_E59_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E59_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E50_MASK                               (0x00040000U)
#define CSL_EVETPCC_ESRH_E50_SHIFT                              (18U)
#define CSL_EVETPCC_ESRH_E50_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E50_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E58_MASK                               (0x04000000U)
#define CSL_EVETPCC_ESRH_E58_SHIFT                              (26U)
#define CSL_EVETPCC_ESRH_E58_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E58_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E53_MASK                               (0x00200000U)
#define CSL_EVETPCC_ESRH_E53_SHIFT                              (21U)
#define CSL_EVETPCC_ESRH_E53_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E53_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E35_MASK                               (0x00000008U)
#define CSL_EVETPCC_ESRH_E35_SHIFT                              (3U)
#define CSL_EVETPCC_ESRH_E35_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E35_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E51_MASK                               (0x00080000U)
#define CSL_EVETPCC_ESRH_E51_SHIFT                              (19U)
#define CSL_EVETPCC_ESRH_E51_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E51_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E54_MASK                               (0x00400000U)
#define CSL_EVETPCC_ESRH_E54_SHIFT                              (22U)
#define CSL_EVETPCC_ESRH_E54_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E54_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E36_MASK                               (0x00000010U)
#define CSL_EVETPCC_ESRH_E36_SHIFT                              (4U)
#define CSL_EVETPCC_ESRH_E36_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E36_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E62_MASK                               (0x40000000U)
#define CSL_EVETPCC_ESRH_E62_SHIFT                              (30U)
#define CSL_EVETPCC_ESRH_E62_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E62_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E37_MASK                               (0x00000020U)
#define CSL_EVETPCC_ESRH_E37_SHIFT                              (5U)
#define CSL_EVETPCC_ESRH_E37_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E37_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E38_MASK                               (0x00000040U)
#define CSL_EVETPCC_ESRH_E38_SHIFT                              (6U)
#define CSL_EVETPCC_ESRH_E38_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E38_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E39_MASK                               (0x00000080U)
#define CSL_EVETPCC_ESRH_E39_SHIFT                              (7U)
#define CSL_EVETPCC_ESRH_E39_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E39_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_E40_MASK                               (0x00000100U)
#define CSL_EVETPCC_ESRH_E40_SHIFT                              (8U)
#define CSL_EVETPCC_ESRH_E40_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ESRH_E40_MAX                                (0x00000001U)

#define CSL_EVETPCC_ESRH_RESETVAL                               (0x00000000U)

/* CER */

#define CSL_EVETPCC_CER_E6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_CER_E6_SHIFT                                (6U)
#define CSL_EVETPCC_CER_E6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E25_MASK                                (0x02000000U)
#define CSL_EVETPCC_CER_E25_SHIFT                               (25U)
#define CSL_EVETPCC_CER_E25_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E25_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E18_MASK                                (0x00040000U)
#define CSL_EVETPCC_CER_E18_SHIFT                               (18U)
#define CSL_EVETPCC_CER_E18_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E18_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_CER_E7_SHIFT                                (7U)
#define CSL_EVETPCC_CER_E7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E24_MASK                                (0x01000000U)
#define CSL_EVETPCC_CER_E24_SHIFT                               (24U)
#define CSL_EVETPCC_CER_E24_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E24_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E31_MASK                                (0x80000000U)
#define CSL_EVETPCC_CER_E31_SHIFT                               (31U)
#define CSL_EVETPCC_CER_E31_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E31_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E8_MASK                                 (0x00000100U)
#define CSL_EVETPCC_CER_E8_SHIFT                                (8U)
#define CSL_EVETPCC_CER_E8_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E8_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E26_MASK                                (0x04000000U)
#define CSL_EVETPCC_CER_E26_SHIFT                               (26U)
#define CSL_EVETPCC_CER_E26_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E26_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E29_MASK                                (0x20000000U)
#define CSL_EVETPCC_CER_E29_SHIFT                               (29U)
#define CSL_EVETPCC_CER_E29_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E29_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E9_MASK                                 (0x00000200U)
#define CSL_EVETPCC_CER_E9_SHIFT                                (9U)
#define CSL_EVETPCC_CER_E9_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E9_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E30_MASK                                (0x40000000U)
#define CSL_EVETPCC_CER_E30_SHIFT                               (30U)
#define CSL_EVETPCC_CER_E30_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E30_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E10_MASK                                (0x00000400U)
#define CSL_EVETPCC_CER_E10_SHIFT                               (10U)
#define CSL_EVETPCC_CER_E10_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E10_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E28_MASK                                (0x10000000U)
#define CSL_EVETPCC_CER_E28_SHIFT                               (28U)
#define CSL_EVETPCC_CER_E28_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E28_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E11_MASK                                (0x00000800U)
#define CSL_EVETPCC_CER_E11_SHIFT                               (11U)
#define CSL_EVETPCC_CER_E11_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E11_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E27_MASK                                (0x08000000U)
#define CSL_EVETPCC_CER_E27_SHIFT                               (27U)
#define CSL_EVETPCC_CER_E27_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E27_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_CER_E0_SHIFT                                (0U)
#define CSL_EVETPCC_CER_E0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E12_MASK                                (0x00001000U)
#define CSL_EVETPCC_CER_E12_SHIFT                               (12U)
#define CSL_EVETPCC_CER_E12_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E12_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_CER_E1_SHIFT                                (1U)
#define CSL_EVETPCC_CER_E1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E13_MASK                                (0x00002000U)
#define CSL_EVETPCC_CER_E13_SHIFT                               (13U)
#define CSL_EVETPCC_CER_E13_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E13_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E19_MASK                                (0x00080000U)
#define CSL_EVETPCC_CER_E19_SHIFT                               (19U)
#define CSL_EVETPCC_CER_E19_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E19_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_CER_E2_SHIFT                                (2U)
#define CSL_EVETPCC_CER_E2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E14_MASK                                (0x00004000U)
#define CSL_EVETPCC_CER_E14_SHIFT                               (14U)
#define CSL_EVETPCC_CER_E14_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E14_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_CER_E3_SHIFT                                (3U)
#define CSL_EVETPCC_CER_E3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E15_MASK                                (0x00008000U)
#define CSL_EVETPCC_CER_E15_SHIFT                               (15U)
#define CSL_EVETPCC_CER_E15_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E15_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E21_MASK                                (0x00200000U)
#define CSL_EVETPCC_CER_E21_SHIFT                               (21U)
#define CSL_EVETPCC_CER_E21_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E21_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E20_MASK                                (0x00100000U)
#define CSL_EVETPCC_CER_E20_SHIFT                               (20U)
#define CSL_EVETPCC_CER_E20_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E20_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_CER_E4_SHIFT                                (4U)
#define CSL_EVETPCC_CER_E4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E23_MASK                                (0x00800000U)
#define CSL_EVETPCC_CER_E23_SHIFT                               (23U)
#define CSL_EVETPCC_CER_E23_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E23_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E16_MASK                                (0x00010000U)
#define CSL_EVETPCC_CER_E16_SHIFT                               (16U)
#define CSL_EVETPCC_CER_E16_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E16_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_CER_E5_SHIFT                                (5U)
#define CSL_EVETPCC_CER_E5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_CER_E5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_CER_E22_MASK                                (0x00400000U)
#define CSL_EVETPCC_CER_E22_SHIFT                               (22U)
#define CSL_EVETPCC_CER_E22_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E22_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_E17_MASK                                (0x00020000U)
#define CSL_EVETPCC_CER_E17_SHIFT                               (17U)
#define CSL_EVETPCC_CER_E17_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_CER_E17_MAX                                 (0x00000001U)

#define CSL_EVETPCC_CER_RESETVAL                                (0x00000000U)

/* CERH */

#define CSL_EVETPCC_CERH_E49_MASK                               (0x00020000U)
#define CSL_EVETPCC_CERH_E49_SHIFT                              (17U)
#define CSL_EVETPCC_CERH_E49_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E49_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E38_MASK                               (0x00000040U)
#define CSL_EVETPCC_CERH_E38_SHIFT                              (6U)
#define CSL_EVETPCC_CERH_E38_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E38_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E39_MASK                               (0x00000080U)
#define CSL_EVETPCC_CERH_E39_SHIFT                              (7U)
#define CSL_EVETPCC_CERH_E39_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E39_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E40_MASK                               (0x00000100U)
#define CSL_EVETPCC_CERH_E40_SHIFT                              (8U)
#define CSL_EVETPCC_CERH_E40_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E40_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E63_MASK                               (0x80000000U)
#define CSL_EVETPCC_CERH_E63_SHIFT                              (31U)
#define CSL_EVETPCC_CERH_E63_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E63_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E41_MASK                               (0x00000200U)
#define CSL_EVETPCC_CERH_E41_SHIFT                              (9U)
#define CSL_EVETPCC_CERH_E41_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E41_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E62_MASK                               (0x40000000U)
#define CSL_EVETPCC_CERH_E62_SHIFT                              (30U)
#define CSL_EVETPCC_CERH_E62_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E62_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E61_MASK                               (0x20000000U)
#define CSL_EVETPCC_CERH_E61_SHIFT                              (29U)
#define CSL_EVETPCC_CERH_E61_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E61_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E42_MASK                               (0x00000400U)
#define CSL_EVETPCC_CERH_E42_SHIFT                              (10U)
#define CSL_EVETPCC_CERH_E42_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E42_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E32_MASK                               (0x00000001U)
#define CSL_EVETPCC_CERH_E32_SHIFT                              (0U)
#define CSL_EVETPCC_CERH_E32_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E32_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E57_MASK                               (0x02000000U)
#define CSL_EVETPCC_CERH_E57_SHIFT                              (25U)
#define CSL_EVETPCC_CERH_E57_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E57_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E43_MASK                               (0x00000800U)
#define CSL_EVETPCC_CERH_E43_SHIFT                              (11U)
#define CSL_EVETPCC_CERH_E43_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E43_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E58_MASK                               (0x04000000U)
#define CSL_EVETPCC_CERH_E58_SHIFT                              (26U)
#define CSL_EVETPCC_CERH_E58_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E58_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E44_MASK                               (0x00001000U)
#define CSL_EVETPCC_CERH_E44_SHIFT                              (12U)
#define CSL_EVETPCC_CERH_E44_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E44_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E59_MASK                               (0x08000000U)
#define CSL_EVETPCC_CERH_E59_SHIFT                              (27U)
#define CSL_EVETPCC_CERH_E59_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E59_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E60_MASK                               (0x10000000U)
#define CSL_EVETPCC_CERH_E60_SHIFT                              (28U)
#define CSL_EVETPCC_CERH_E60_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E60_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E45_MASK                               (0x00002000U)
#define CSL_EVETPCC_CERH_E45_SHIFT                              (13U)
#define CSL_EVETPCC_CERH_E45_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E45_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E33_MASK                               (0x00000002U)
#define CSL_EVETPCC_CERH_E33_SHIFT                              (1U)
#define CSL_EVETPCC_CERH_E33_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E33_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E46_MASK                               (0x00004000U)
#define CSL_EVETPCC_CERH_E46_SHIFT                              (14U)
#define CSL_EVETPCC_CERH_E46_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E46_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E34_MASK                               (0x00000004U)
#define CSL_EVETPCC_CERH_E34_SHIFT                              (2U)
#define CSL_EVETPCC_CERH_E34_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E34_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E47_MASK                               (0x00008000U)
#define CSL_EVETPCC_CERH_E47_SHIFT                              (15U)
#define CSL_EVETPCC_CERH_E47_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E47_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E53_MASK                               (0x00200000U)
#define CSL_EVETPCC_CERH_E53_SHIFT                              (21U)
#define CSL_EVETPCC_CERH_E53_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E53_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E54_MASK                               (0x00400000U)
#define CSL_EVETPCC_CERH_E54_SHIFT                              (22U)
#define CSL_EVETPCC_CERH_E54_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E54_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E50_MASK                               (0x00040000U)
#define CSL_EVETPCC_CERH_E50_SHIFT                              (18U)
#define CSL_EVETPCC_CERH_E50_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E50_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E35_MASK                               (0x00000008U)
#define CSL_EVETPCC_CERH_E35_SHIFT                              (3U)
#define CSL_EVETPCC_CERH_E35_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E35_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E48_MASK                               (0x00010000U)
#define CSL_EVETPCC_CERH_E48_SHIFT                              (16U)
#define CSL_EVETPCC_CERH_E48_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E48_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E56_MASK                               (0x01000000U)
#define CSL_EVETPCC_CERH_E56_SHIFT                              (24U)
#define CSL_EVETPCC_CERH_E56_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E56_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E51_MASK                               (0x00080000U)
#define CSL_EVETPCC_CERH_E51_SHIFT                              (19U)
#define CSL_EVETPCC_CERH_E51_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E51_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E36_MASK                               (0x00000010U)
#define CSL_EVETPCC_CERH_E36_SHIFT                              (4U)
#define CSL_EVETPCC_CERH_E36_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E36_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E55_MASK                               (0x00800000U)
#define CSL_EVETPCC_CERH_E55_SHIFT                              (23U)
#define CSL_EVETPCC_CERH_E55_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E55_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E52_MASK                               (0x00100000U)
#define CSL_EVETPCC_CERH_E52_SHIFT                              (20U)
#define CSL_EVETPCC_CERH_E52_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E52_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_E37_MASK                               (0x00000020U)
#define CSL_EVETPCC_CERH_E37_SHIFT                              (5U)
#define CSL_EVETPCC_CERH_E37_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_CERH_E37_MAX                                (0x00000001U)

#define CSL_EVETPCC_CERH_RESETVAL                               (0x00000000U)

/* EER */

#define CSL_EVETPCC_EER_E11_MASK                                (0x00000800U)
#define CSL_EVETPCC_EER_E11_SHIFT                               (11U)
#define CSL_EVETPCC_EER_E11_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E11_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E24_MASK                                (0x01000000U)
#define CSL_EVETPCC_EER_E24_SHIFT                               (24U)
#define CSL_EVETPCC_EER_E24_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E24_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E10_MASK                                (0x00000400U)
#define CSL_EVETPCC_EER_E10_SHIFT                               (10U)
#define CSL_EVETPCC_EER_E10_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E10_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E12_MASK                                (0x00001000U)
#define CSL_EVETPCC_EER_E12_SHIFT                               (12U)
#define CSL_EVETPCC_EER_E12_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E12_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E25_MASK                                (0x02000000U)
#define CSL_EVETPCC_EER_E25_SHIFT                               (25U)
#define CSL_EVETPCC_EER_E25_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E25_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E9_MASK                                 (0x00000200U)
#define CSL_EVETPCC_EER_E9_SHIFT                                (9U)
#define CSL_EVETPCC_EER_E9_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E9_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E21_MASK                                (0x00200000U)
#define CSL_EVETPCC_EER_E21_SHIFT                               (21U)
#define CSL_EVETPCC_EER_E21_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E21_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E22_MASK                                (0x00400000U)
#define CSL_EVETPCC_EER_E22_SHIFT                               (22U)
#define CSL_EVETPCC_EER_E22_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E22_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_EER_E0_SHIFT                                (0U)
#define CSL_EVETPCC_EER_E0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E23_MASK                                (0x00800000U)
#define CSL_EVETPCC_EER_E23_SHIFT                               (23U)
#define CSL_EVETPCC_EER_E23_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E23_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E19_MASK                                (0x00080000U)
#define CSL_EVETPCC_EER_E19_SHIFT                               (19U)
#define CSL_EVETPCC_EER_E19_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E19_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E20_MASK                                (0x00100000U)
#define CSL_EVETPCC_EER_E20_SHIFT                               (20U)
#define CSL_EVETPCC_EER_E20_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E20_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E29_MASK                                (0x20000000U)
#define CSL_EVETPCC_EER_E29_SHIFT                               (29U)
#define CSL_EVETPCC_EER_E29_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E29_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E30_MASK                                (0x40000000U)
#define CSL_EVETPCC_EER_E30_SHIFT                               (30U)
#define CSL_EVETPCC_EER_E30_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E30_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E18_MASK                                (0x00040000U)
#define CSL_EVETPCC_EER_E18_SHIFT                               (18U)
#define CSL_EVETPCC_EER_E18_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E18_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E31_MASK                                (0x80000000U)
#define CSL_EVETPCC_EER_E31_SHIFT                               (31U)
#define CSL_EVETPCC_EER_E31_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E31_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_EER_E5_SHIFT                                (5U)
#define CSL_EVETPCC_EER_E5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_EER_E6_SHIFT                                (6U)
#define CSL_EVETPCC_EER_E6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E8_MASK                                 (0x00000100U)
#define CSL_EVETPCC_EER_E8_SHIFT                                (8U)
#define CSL_EVETPCC_EER_E8_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E8_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_EER_E7_SHIFT                                (7U)
#define CSL_EVETPCC_EER_E7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E28_MASK                                (0x10000000U)
#define CSL_EVETPCC_EER_E28_SHIFT                               (28U)
#define CSL_EVETPCC_EER_E28_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E28_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_EER_E3_SHIFT                                (3U)
#define CSL_EVETPCC_EER_E3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_EER_E2_SHIFT                                (2U)
#define CSL_EVETPCC_EER_E2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_EER_E1_SHIFT                                (1U)
#define CSL_EVETPCC_EER_E1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E13_MASK                                (0x00002000U)
#define CSL_EVETPCC_EER_E13_SHIFT                               (13U)
#define CSL_EVETPCC_EER_E13_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E13_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E17_MASK                                (0x00020000U)
#define CSL_EVETPCC_EER_E17_SHIFT                               (17U)
#define CSL_EVETPCC_EER_E17_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E17_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E26_MASK                                (0x04000000U)
#define CSL_EVETPCC_EER_E26_SHIFT                               (26U)
#define CSL_EVETPCC_EER_E26_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E26_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E14_MASK                                (0x00004000U)
#define CSL_EVETPCC_EER_E14_SHIFT                               (14U)
#define CSL_EVETPCC_EER_E14_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E14_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E16_MASK                                (0x00010000U)
#define CSL_EVETPCC_EER_E16_SHIFT                               (16U)
#define CSL_EVETPCC_EER_E16_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E16_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E27_MASK                                (0x08000000U)
#define CSL_EVETPCC_EER_E27_SHIFT                               (27U)
#define CSL_EVETPCC_EER_E27_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E27_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_E4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_EER_E4_SHIFT                                (4U)
#define CSL_EVETPCC_EER_E4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_EER_E4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_EER_E15_MASK                                (0x00008000U)
#define CSL_EVETPCC_EER_E15_SHIFT                               (15U)
#define CSL_EVETPCC_EER_E15_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EER_E15_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EER_RESETVAL                                (0x00000000U)

/* EERH */

#define CSL_EVETPCC_EERH_E47_MASK                               (0x00008000U)
#define CSL_EVETPCC_EERH_E47_SHIFT                              (15U)
#define CSL_EVETPCC_EERH_E47_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E47_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E45_MASK                               (0x00002000U)
#define CSL_EVETPCC_EERH_E45_SHIFT                              (13U)
#define CSL_EVETPCC_EERH_E45_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E45_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E35_MASK                               (0x00000008U)
#define CSL_EVETPCC_EERH_E35_SHIFT                              (3U)
#define CSL_EVETPCC_EERH_E35_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E35_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E56_MASK                               (0x01000000U)
#define CSL_EVETPCC_EERH_E56_SHIFT                              (24U)
#define CSL_EVETPCC_EERH_E56_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E56_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E46_MASK                               (0x00004000U)
#define CSL_EVETPCC_EERH_E46_SHIFT                              (14U)
#define CSL_EVETPCC_EERH_E46_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E46_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E36_MASK                               (0x00000010U)
#define CSL_EVETPCC_EERH_E36_SHIFT                              (4U)
#define CSL_EVETPCC_EERH_E36_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E36_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E55_MASK                               (0x00800000U)
#define CSL_EVETPCC_EERH_E55_SHIFT                              (23U)
#define CSL_EVETPCC_EERH_E55_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E55_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E33_MASK                               (0x00000002U)
#define CSL_EVETPCC_EERH_E33_SHIFT                              (1U)
#define CSL_EVETPCC_EERH_E33_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E33_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E54_MASK                               (0x00400000U)
#define CSL_EVETPCC_EERH_E54_SHIFT                              (22U)
#define CSL_EVETPCC_EERH_E54_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E54_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E43_MASK                               (0x00000800U)
#define CSL_EVETPCC_EERH_E43_SHIFT                              (11U)
#define CSL_EVETPCC_EERH_E43_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E43_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E53_MASK                               (0x00200000U)
#define CSL_EVETPCC_EERH_E53_SHIFT                              (21U)
#define CSL_EVETPCC_EERH_E53_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E53_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E63_MASK                               (0x80000000U)
#define CSL_EVETPCC_EERH_E63_SHIFT                              (31U)
#define CSL_EVETPCC_EERH_E63_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E63_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E34_MASK                               (0x00000004U)
#define CSL_EVETPCC_EERH_E34_SHIFT                              (2U)
#define CSL_EVETPCC_EERH_E34_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E34_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E44_MASK                               (0x00001000U)
#define CSL_EVETPCC_EERH_E44_SHIFT                              (12U)
#define CSL_EVETPCC_EERH_E44_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E44_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E52_MASK                               (0x00100000U)
#define CSL_EVETPCC_EERH_E52_SHIFT                              (20U)
#define CSL_EVETPCC_EERH_E52_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E52_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E41_MASK                               (0x00000200U)
#define CSL_EVETPCC_EERH_E41_SHIFT                              (9U)
#define CSL_EVETPCC_EERH_E41_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E41_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E62_MASK                               (0x40000000U)
#define CSL_EVETPCC_EERH_E62_SHIFT                              (30U)
#define CSL_EVETPCC_EERH_E62_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E62_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E32_MASK                               (0x00000001U)
#define CSL_EVETPCC_EERH_E32_SHIFT                              (0U)
#define CSL_EVETPCC_EERH_E32_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E32_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E51_MASK                               (0x00080000U)
#define CSL_EVETPCC_EERH_E51_SHIFT                              (19U)
#define CSL_EVETPCC_EERH_E51_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E51_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E42_MASK                               (0x00000400U)
#define CSL_EVETPCC_EERH_E42_SHIFT                              (10U)
#define CSL_EVETPCC_EERH_E42_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E42_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E61_MASK                               (0x20000000U)
#define CSL_EVETPCC_EERH_E61_SHIFT                              (29U)
#define CSL_EVETPCC_EERH_E61_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E61_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E50_MASK                               (0x00040000U)
#define CSL_EVETPCC_EERH_E50_SHIFT                              (18U)
#define CSL_EVETPCC_EERH_E50_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E50_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E39_MASK                               (0x00000080U)
#define CSL_EVETPCC_EERH_E39_SHIFT                              (7U)
#define CSL_EVETPCC_EERH_E39_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E39_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E60_MASK                               (0x10000000U)
#define CSL_EVETPCC_EERH_E60_SHIFT                              (28U)
#define CSL_EVETPCC_EERH_E60_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E60_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E49_MASK                               (0x00020000U)
#define CSL_EVETPCC_EERH_E49_SHIFT                              (17U)
#define CSL_EVETPCC_EERH_E49_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E49_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E40_MASK                               (0x00000100U)
#define CSL_EVETPCC_EERH_E40_SHIFT                              (8U)
#define CSL_EVETPCC_EERH_E40_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E40_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E59_MASK                               (0x08000000U)
#define CSL_EVETPCC_EERH_E59_SHIFT                              (27U)
#define CSL_EVETPCC_EERH_E59_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E59_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E48_MASK                               (0x00010000U)
#define CSL_EVETPCC_EERH_E48_SHIFT                              (16U)
#define CSL_EVETPCC_EERH_E48_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E48_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E58_MASK                               (0x04000000U)
#define CSL_EVETPCC_EERH_E58_SHIFT                              (26U)
#define CSL_EVETPCC_EERH_E58_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E58_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E37_MASK                               (0x00000020U)
#define CSL_EVETPCC_EERH_E37_SHIFT                              (5U)
#define CSL_EVETPCC_EERH_E37_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E37_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E57_MASK                               (0x02000000U)
#define CSL_EVETPCC_EERH_E57_SHIFT                              (25U)
#define CSL_EVETPCC_EERH_E57_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E57_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_E38_MASK                               (0x00000040U)
#define CSL_EVETPCC_EERH_E38_SHIFT                              (6U)
#define CSL_EVETPCC_EERH_E38_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EERH_E38_MAX                                (0x00000001U)

#define CSL_EVETPCC_EERH_RESETVAL                               (0x00000000U)

/* EECR */

#define CSL_EVETPCC_EECR_E30_MASK                               (0x40000000U)
#define CSL_EVETPCC_EECR_E30_SHIFT                              (30U)
#define CSL_EVETPCC_EECR_E30_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E30_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E25_MASK                               (0x02000000U)
#define CSL_EVETPCC_EECR_E25_SHIFT                              (25U)
#define CSL_EVETPCC_EECR_E25_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E25_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E14_MASK                               (0x00004000U)
#define CSL_EVETPCC_EECR_E14_SHIFT                              (14U)
#define CSL_EVETPCC_EECR_E14_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E14_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E15_MASK                               (0x00008000U)
#define CSL_EVETPCC_EECR_E15_SHIFT                              (15U)
#define CSL_EVETPCC_EECR_E15_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E15_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E5_MASK                                (0x00000020U)
#define CSL_EVETPCC_EECR_E5_SHIFT                               (5U)
#define CSL_EVETPCC_EECR_E5_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E5_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E31_MASK                               (0x80000000U)
#define CSL_EVETPCC_EECR_E31_SHIFT                              (31U)
#define CSL_EVETPCC_EECR_E31_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E31_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E24_MASK                               (0x01000000U)
#define CSL_EVETPCC_EECR_E24_SHIFT                              (24U)
#define CSL_EVETPCC_EECR_E24_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E24_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E28_MASK                               (0x10000000U)
#define CSL_EVETPCC_EECR_E28_SHIFT                              (28U)
#define CSL_EVETPCC_EECR_E28_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E28_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E6_MASK                                (0x00000040U)
#define CSL_EVETPCC_EECR_E6_SHIFT                               (6U)
#define CSL_EVETPCC_EECR_E6_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E6_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E16_MASK                               (0x00010000U)
#define CSL_EVETPCC_EECR_E16_SHIFT                              (16U)
#define CSL_EVETPCC_EECR_E16_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E16_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E29_MASK                               (0x20000000U)
#define CSL_EVETPCC_EECR_E29_SHIFT                              (29U)
#define CSL_EVETPCC_EECR_E29_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E29_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E26_MASK                               (0x04000000U)
#define CSL_EVETPCC_EECR_E26_SHIFT                              (26U)
#define CSL_EVETPCC_EECR_E26_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E26_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E8_MASK                                (0x00000100U)
#define CSL_EVETPCC_EECR_E8_SHIFT                               (8U)
#define CSL_EVETPCC_EECR_E8_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E8_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E18_MASK                               (0x00040000U)
#define CSL_EVETPCC_EECR_E18_SHIFT                              (18U)
#define CSL_EVETPCC_EECR_E18_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E18_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E7_MASK                                (0x00000080U)
#define CSL_EVETPCC_EECR_E7_SHIFT                               (7U)
#define CSL_EVETPCC_EECR_E7_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E7_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E17_MASK                               (0x00020000U)
#define CSL_EVETPCC_EECR_E17_SHIFT                              (17U)
#define CSL_EVETPCC_EECR_E17_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E17_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E10_MASK                               (0x00000400U)
#define CSL_EVETPCC_EECR_E10_SHIFT                              (10U)
#define CSL_EVETPCC_EECR_E10_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E10_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E20_MASK                               (0x00100000U)
#define CSL_EVETPCC_EECR_E20_SHIFT                              (20U)
#define CSL_EVETPCC_EECR_E20_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E20_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E9_MASK                                (0x00000200U)
#define CSL_EVETPCC_EECR_E9_SHIFT                               (9U)
#define CSL_EVETPCC_EECR_E9_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E9_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E0_MASK                                (0x00000001U)
#define CSL_EVETPCC_EECR_E0_SHIFT                               (0U)
#define CSL_EVETPCC_EECR_E0_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E0_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E19_MASK                               (0x00080000U)
#define CSL_EVETPCC_EECR_E19_SHIFT                              (19U)
#define CSL_EVETPCC_EECR_E19_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E19_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E1_MASK                                (0x00000002U)
#define CSL_EVETPCC_EECR_E1_SHIFT                               (1U)
#define CSL_EVETPCC_EECR_E1_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E1_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E12_MASK                               (0x00001000U)
#define CSL_EVETPCC_EECR_E12_SHIFT                              (12U)
#define CSL_EVETPCC_EECR_E12_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E12_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E22_MASK                               (0x00400000U)
#define CSL_EVETPCC_EECR_E22_SHIFT                              (22U)
#define CSL_EVETPCC_EECR_E22_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E22_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E2_MASK                                (0x00000004U)
#define CSL_EVETPCC_EECR_E2_SHIFT                               (2U)
#define CSL_EVETPCC_EECR_E2_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E2_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E11_MASK                               (0x00000800U)
#define CSL_EVETPCC_EECR_E11_SHIFT                              (11U)
#define CSL_EVETPCC_EECR_E11_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E11_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E21_MASK                               (0x00200000U)
#define CSL_EVETPCC_EECR_E21_SHIFT                              (21U)
#define CSL_EVETPCC_EECR_E21_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E21_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E27_MASK                               (0x08000000U)
#define CSL_EVETPCC_EECR_E27_SHIFT                              (27U)
#define CSL_EVETPCC_EECR_E27_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E27_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E3_MASK                                (0x00000008U)
#define CSL_EVETPCC_EECR_E3_SHIFT                               (3U)
#define CSL_EVETPCC_EECR_E3_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E3_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E23_MASK                               (0x00800000U)
#define CSL_EVETPCC_EECR_E23_SHIFT                              (23U)
#define CSL_EVETPCC_EECR_E23_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E23_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_E4_MASK                                (0x00000010U)
#define CSL_EVETPCC_EECR_E4_SHIFT                               (4U)
#define CSL_EVETPCC_EECR_E4_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EECR_E4_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EECR_E13_MASK                               (0x00002000U)
#define CSL_EVETPCC_EECR_E13_SHIFT                              (13U)
#define CSL_EVETPCC_EECR_E13_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EECR_E13_MAX                                (0x00000001U)

#define CSL_EVETPCC_EECR_RESETVAL                               (0x00000000U)

/* EECRH */

#define CSL_EVETPCC_EECRH_E62_MASK                              (0x40000000U)
#define CSL_EVETPCC_EECRH_E62_SHIFT                             (30U)
#define CSL_EVETPCC_EECRH_E62_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E62_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E37_MASK                              (0x00000020U)
#define CSL_EVETPCC_EECRH_E37_SHIFT                             (5U)
#define CSL_EVETPCC_EECRH_E37_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E37_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E51_MASK                              (0x00080000U)
#define CSL_EVETPCC_EECRH_E51_SHIFT                             (19U)
#define CSL_EVETPCC_EECRH_E51_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E51_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E36_MASK                              (0x00000010U)
#define CSL_EVETPCC_EECRH_E36_SHIFT                             (4U)
#define CSL_EVETPCC_EECRH_E36_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E36_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E50_MASK                              (0x00040000U)
#define CSL_EVETPCC_EECRH_E50_SHIFT                             (18U)
#define CSL_EVETPCC_EECRH_E50_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E50_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E35_MASK                              (0x00000008U)
#define CSL_EVETPCC_EECRH_E35_SHIFT                             (3U)
#define CSL_EVETPCC_EECRH_E35_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E35_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E63_MASK                              (0x80000000U)
#define CSL_EVETPCC_EECRH_E63_SHIFT                             (31U)
#define CSL_EVETPCC_EECRH_E63_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E63_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E54_MASK                              (0x00400000U)
#define CSL_EVETPCC_EECRH_E54_SHIFT                             (22U)
#define CSL_EVETPCC_EECRH_E54_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E54_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E58_MASK                              (0x04000000U)
#define CSL_EVETPCC_EECRH_E58_SHIFT                             (26U)
#define CSL_EVETPCC_EECRH_E58_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E58_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E48_MASK                              (0x00010000U)
#define CSL_EVETPCC_EECRH_E48_SHIFT                             (16U)
#define CSL_EVETPCC_EECRH_E48_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E48_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E59_MASK                              (0x08000000U)
#define CSL_EVETPCC_EECRH_E59_SHIFT                             (27U)
#define CSL_EVETPCC_EECRH_E59_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E59_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E53_MASK                              (0x00200000U)
#define CSL_EVETPCC_EECRH_E53_SHIFT                             (21U)
#define CSL_EVETPCC_EECRH_E53_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E53_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E49_MASK                              (0x00020000U)
#define CSL_EVETPCC_EECRH_E49_SHIFT                             (17U)
#define CSL_EVETPCC_EECRH_E49_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E49_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E60_MASK                              (0x10000000U)
#define CSL_EVETPCC_EECRH_E60_SHIFT                             (28U)
#define CSL_EVETPCC_EECRH_E60_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E60_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E61_MASK                              (0x20000000U)
#define CSL_EVETPCC_EECRH_E61_SHIFT                             (29U)
#define CSL_EVETPCC_EECRH_E61_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E61_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E52_MASK                              (0x00100000U)
#define CSL_EVETPCC_EECRH_E52_SHIFT                             (20U)
#define CSL_EVETPCC_EECRH_E52_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E52_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E44_MASK                              (0x00001000U)
#define CSL_EVETPCC_EECRH_E44_SHIFT                             (12U)
#define CSL_EVETPCC_EECRH_E44_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E44_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E34_MASK                              (0x00000004U)
#define CSL_EVETPCC_EECRH_E34_SHIFT                             (2U)
#define CSL_EVETPCC_EECRH_E34_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E34_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E43_MASK                              (0x00000800U)
#define CSL_EVETPCC_EECRH_E43_SHIFT                             (11U)
#define CSL_EVETPCC_EECRH_E43_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E43_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E33_MASK                              (0x00000002U)
#define CSL_EVETPCC_EECRH_E33_SHIFT                             (1U)
#define CSL_EVETPCC_EECRH_E33_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E33_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E55_MASK                              (0x00800000U)
#define CSL_EVETPCC_EECRH_E55_SHIFT                             (23U)
#define CSL_EVETPCC_EECRH_E55_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E55_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E42_MASK                              (0x00000400U)
#define CSL_EVETPCC_EECRH_E42_SHIFT                             (10U)
#define CSL_EVETPCC_EECRH_E42_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E42_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E56_MASK                              (0x01000000U)
#define CSL_EVETPCC_EECRH_E56_SHIFT                             (24U)
#define CSL_EVETPCC_EECRH_E56_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E56_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E32_MASK                              (0x00000001U)
#define CSL_EVETPCC_EECRH_E32_SHIFT                             (0U)
#define CSL_EVETPCC_EECRH_E32_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E32_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E41_MASK                              (0x00000200U)
#define CSL_EVETPCC_EECRH_E41_SHIFT                             (9U)
#define CSL_EVETPCC_EECRH_E41_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E41_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E57_MASK                              (0x02000000U)
#define CSL_EVETPCC_EECRH_E57_SHIFT                             (25U)
#define CSL_EVETPCC_EECRH_E57_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E57_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E47_MASK                              (0x00008000U)
#define CSL_EVETPCC_EECRH_E47_SHIFT                             (15U)
#define CSL_EVETPCC_EECRH_E47_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E47_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E40_MASK                              (0x00000100U)
#define CSL_EVETPCC_EECRH_E40_SHIFT                             (8U)
#define CSL_EVETPCC_EECRH_E40_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E40_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E46_MASK                              (0x00004000U)
#define CSL_EVETPCC_EECRH_E46_SHIFT                             (14U)
#define CSL_EVETPCC_EECRH_E46_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E46_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E39_MASK                              (0x00000080U)
#define CSL_EVETPCC_EECRH_E39_SHIFT                             (7U)
#define CSL_EVETPCC_EECRH_E39_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E39_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E45_MASK                              (0x00002000U)
#define CSL_EVETPCC_EECRH_E45_SHIFT                             (13U)
#define CSL_EVETPCC_EECRH_E45_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E45_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_E38_MASK                              (0x00000040U)
#define CSL_EVETPCC_EECRH_E38_SHIFT                             (6U)
#define CSL_EVETPCC_EECRH_E38_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EECRH_E38_MAX                               (0x00000001U)

#define CSL_EVETPCC_EECRH_RESETVAL                              (0x00000000U)

/* EESR */

#define CSL_EVETPCC_EESR_E15_MASK                               (0x00008000U)
#define CSL_EVETPCC_EESR_E15_SHIFT                              (15U)
#define CSL_EVETPCC_EESR_E15_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E15_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E6_MASK                                (0x00000040U)
#define CSL_EVETPCC_EESR_E6_SHIFT                               (6U)
#define CSL_EVETPCC_EESR_E6_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E6_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E16_MASK                               (0x00010000U)
#define CSL_EVETPCC_EESR_E16_SHIFT                              (16U)
#define CSL_EVETPCC_EESR_E16_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E16_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E30_MASK                               (0x40000000U)
#define CSL_EVETPCC_EESR_E30_SHIFT                              (30U)
#define CSL_EVETPCC_EESR_E30_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E30_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E7_MASK                                (0x00000080U)
#define CSL_EVETPCC_EESR_E7_SHIFT                               (7U)
#define CSL_EVETPCC_EESR_E7_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E7_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E4_MASK                                (0x00000010U)
#define CSL_EVETPCC_EESR_E4_SHIFT                               (4U)
#define CSL_EVETPCC_EESR_E4_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E4_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E5_MASK                                (0x00000020U)
#define CSL_EVETPCC_EESR_E5_SHIFT                               (5U)
#define CSL_EVETPCC_EESR_E5_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E5_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E29_MASK                               (0x20000000U)
#define CSL_EVETPCC_EESR_E29_SHIFT                              (29U)
#define CSL_EVETPCC_EESR_E29_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E29_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E0_MASK                                (0x00000001U)
#define CSL_EVETPCC_EESR_E0_SHIFT                               (0U)
#define CSL_EVETPCC_EESR_E0_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E0_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E10_MASK                               (0x00000400U)
#define CSL_EVETPCC_EESR_E10_SHIFT                              (10U)
#define CSL_EVETPCC_EESR_E10_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E10_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E28_MASK                               (0x10000000U)
#define CSL_EVETPCC_EESR_E28_SHIFT                              (28U)
#define CSL_EVETPCC_EESR_E28_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E28_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E27_MASK                               (0x08000000U)
#define CSL_EVETPCC_EESR_E27_SHIFT                              (27U)
#define CSL_EVETPCC_EESR_E27_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E27_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E26_MASK                               (0x04000000U)
#define CSL_EVETPCC_EESR_E26_SHIFT                              (26U)
#define CSL_EVETPCC_EESR_E26_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E26_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E8_MASK                                (0x00000100U)
#define CSL_EVETPCC_EESR_E8_SHIFT                               (8U)
#define CSL_EVETPCC_EESR_E8_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E8_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E9_MASK                                (0x00000200U)
#define CSL_EVETPCC_EESR_E9_SHIFT                               (9U)
#define CSL_EVETPCC_EESR_E9_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E9_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E25_MASK                               (0x02000000U)
#define CSL_EVETPCC_EESR_E25_SHIFT                              (25U)
#define CSL_EVETPCC_EESR_E25_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E25_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E24_MASK                               (0x01000000U)
#define CSL_EVETPCC_EESR_E24_SHIFT                              (24U)
#define CSL_EVETPCC_EESR_E24_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E24_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E11_MASK                               (0x00000800U)
#define CSL_EVETPCC_EESR_E11_SHIFT                              (11U)
#define CSL_EVETPCC_EESR_E11_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E11_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E23_MASK                               (0x00800000U)
#define CSL_EVETPCC_EESR_E23_SHIFT                              (23U)
#define CSL_EVETPCC_EESR_E23_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E23_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E20_MASK                               (0x00100000U)
#define CSL_EVETPCC_EESR_E20_SHIFT                              (20U)
#define CSL_EVETPCC_EESR_E20_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E20_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E22_MASK                               (0x00400000U)
#define CSL_EVETPCC_EESR_E22_SHIFT                              (22U)
#define CSL_EVETPCC_EESR_E22_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E22_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E21_MASK                               (0x00200000U)
#define CSL_EVETPCC_EESR_E21_SHIFT                              (21U)
#define CSL_EVETPCC_EESR_E21_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E21_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E2_MASK                                (0x00000004U)
#define CSL_EVETPCC_EESR_E2_SHIFT                               (2U)
#define CSL_EVETPCC_EESR_E2_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E2_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E18_MASK                               (0x00040000U)
#define CSL_EVETPCC_EESR_E18_SHIFT                              (18U)
#define CSL_EVETPCC_EESR_E18_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E18_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E3_MASK                                (0x00000008U)
#define CSL_EVETPCC_EESR_E3_SHIFT                               (3U)
#define CSL_EVETPCC_EESR_E3_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E3_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E19_MASK                               (0x00080000U)
#define CSL_EVETPCC_EESR_E19_SHIFT                              (19U)
#define CSL_EVETPCC_EESR_E19_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E19_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E31_MASK                               (0x80000000U)
#define CSL_EVETPCC_EESR_E31_SHIFT                              (31U)
#define CSL_EVETPCC_EESR_E31_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E31_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E13_MASK                               (0x00002000U)
#define CSL_EVETPCC_EESR_E13_SHIFT                              (13U)
#define CSL_EVETPCC_EESR_E13_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E13_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E12_MASK                               (0x00001000U)
#define CSL_EVETPCC_EESR_E12_SHIFT                              (12U)
#define CSL_EVETPCC_EESR_E12_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E12_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E14_MASK                               (0x00004000U)
#define CSL_EVETPCC_EESR_E14_SHIFT                              (14U)
#define CSL_EVETPCC_EESR_E14_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E14_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_E1_MASK                                (0x00000002U)
#define CSL_EVETPCC_EESR_E1_SHIFT                               (1U)
#define CSL_EVETPCC_EESR_E1_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_EESR_E1_MAX                                 (0x00000001U)

#define CSL_EVETPCC_EESR_E17_MASK                               (0x00020000U)
#define CSL_EVETPCC_EESR_E17_SHIFT                              (17U)
#define CSL_EVETPCC_EESR_E17_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_EESR_E17_MAX                                (0x00000001U)

#define CSL_EVETPCC_EESR_RESETVAL                               (0x00000000U)

/* EESRH */

#define CSL_EVETPCC_EESRH_E33_MASK                              (0x00000002U)
#define CSL_EVETPCC_EESRH_E33_SHIFT                             (1U)
#define CSL_EVETPCC_EESRH_E33_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E33_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E35_MASK                              (0x00000008U)
#define CSL_EVETPCC_EESRH_E35_SHIFT                             (3U)
#define CSL_EVETPCC_EESRH_E35_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E35_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E44_MASK                              (0x00001000U)
#define CSL_EVETPCC_EESRH_E44_SHIFT                             (12U)
#define CSL_EVETPCC_EESRH_E44_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E44_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E32_MASK                              (0x00000001U)
#define CSL_EVETPCC_EESRH_E32_SHIFT                             (0U)
#define CSL_EVETPCC_EESRH_E32_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E32_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E43_MASK                              (0x00000800U)
#define CSL_EVETPCC_EESRH_E43_SHIFT                             (11U)
#define CSL_EVETPCC_EESRH_E43_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E43_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E55_MASK                              (0x00800000U)
#define CSL_EVETPCC_EESRH_E55_SHIFT                             (23U)
#define CSL_EVETPCC_EESRH_E55_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E55_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E42_MASK                              (0x00000400U)
#define CSL_EVETPCC_EESRH_E42_SHIFT                             (10U)
#define CSL_EVETPCC_EESRH_E42_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E42_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E54_MASK                              (0x00400000U)
#define CSL_EVETPCC_EESRH_E54_SHIFT                             (22U)
#define CSL_EVETPCC_EESRH_E54_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E54_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E53_MASK                              (0x00200000U)
#define CSL_EVETPCC_EESRH_E53_SHIFT                             (21U)
#define CSL_EVETPCC_EESRH_E53_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E53_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E56_MASK                              (0x01000000U)
#define CSL_EVETPCC_EESRH_E56_SHIFT                             (24U)
#define CSL_EVETPCC_EESRH_E56_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E56_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E41_MASK                              (0x00000200U)
#define CSL_EVETPCC_EESRH_E41_SHIFT                             (9U)
#define CSL_EVETPCC_EESRH_E41_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E41_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E40_MASK                              (0x00000100U)
#define CSL_EVETPCC_EESRH_E40_SHIFT                             (8U)
#define CSL_EVETPCC_EESRH_E40_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E40_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E57_MASK                              (0x02000000U)
#define CSL_EVETPCC_EESRH_E57_SHIFT                             (25U)
#define CSL_EVETPCC_EESRH_E57_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E57_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E52_MASK                              (0x00100000U)
#define CSL_EVETPCC_EESRH_E52_SHIFT                             (20U)
#define CSL_EVETPCC_EESRH_E52_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E52_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E34_MASK                              (0x00000004U)
#define CSL_EVETPCC_EESRH_E34_SHIFT                             (2U)
#define CSL_EVETPCC_EESRH_E34_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E34_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E39_MASK                              (0x00000080U)
#define CSL_EVETPCC_EESRH_E39_SHIFT                             (7U)
#define CSL_EVETPCC_EESRH_E39_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E39_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E58_MASK                              (0x04000000U)
#define CSL_EVETPCC_EESRH_E58_SHIFT                             (26U)
#define CSL_EVETPCC_EESRH_E58_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E58_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E51_MASK                              (0x00080000U)
#define CSL_EVETPCC_EESRH_E51_SHIFT                             (19U)
#define CSL_EVETPCC_EESRH_E51_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E51_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E36_MASK                              (0x00000010U)
#define CSL_EVETPCC_EESRH_E36_SHIFT                             (4U)
#define CSL_EVETPCC_EESRH_E36_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E36_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E38_MASK                              (0x00000040U)
#define CSL_EVETPCC_EESRH_E38_SHIFT                             (6U)
#define CSL_EVETPCC_EESRH_E38_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E38_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E59_MASK                              (0x08000000U)
#define CSL_EVETPCC_EESRH_E59_SHIFT                             (27U)
#define CSL_EVETPCC_EESRH_E59_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E59_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E50_MASK                              (0x00040000U)
#define CSL_EVETPCC_EESRH_E50_SHIFT                             (18U)
#define CSL_EVETPCC_EESRH_E50_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E50_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E37_MASK                              (0x00000020U)
#define CSL_EVETPCC_EESRH_E37_SHIFT                             (5U)
#define CSL_EVETPCC_EESRH_E37_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E37_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E60_MASK                              (0x10000000U)
#define CSL_EVETPCC_EESRH_E60_SHIFT                             (28U)
#define CSL_EVETPCC_EESRH_E60_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E60_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E49_MASK                              (0x00020000U)
#define CSL_EVETPCC_EESRH_E49_SHIFT                             (17U)
#define CSL_EVETPCC_EESRH_E49_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E49_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E61_MASK                              (0x20000000U)
#define CSL_EVETPCC_EESRH_E61_SHIFT                             (29U)
#define CSL_EVETPCC_EESRH_E61_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E61_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E48_MASK                              (0x00010000U)
#define CSL_EVETPCC_EESRH_E48_SHIFT                             (16U)
#define CSL_EVETPCC_EESRH_E48_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E48_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E62_MASK                              (0x40000000U)
#define CSL_EVETPCC_EESRH_E62_SHIFT                             (30U)
#define CSL_EVETPCC_EESRH_E62_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E62_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E47_MASK                              (0x00008000U)
#define CSL_EVETPCC_EESRH_E47_SHIFT                             (15U)
#define CSL_EVETPCC_EESRH_E47_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E47_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E63_MASK                              (0x80000000U)
#define CSL_EVETPCC_EESRH_E63_SHIFT                             (31U)
#define CSL_EVETPCC_EESRH_E63_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E63_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E46_MASK                              (0x00004000U)
#define CSL_EVETPCC_EESRH_E46_SHIFT                             (14U)
#define CSL_EVETPCC_EESRH_E46_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E46_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_E45_MASK                              (0x00002000U)
#define CSL_EVETPCC_EESRH_E45_SHIFT                             (13U)
#define CSL_EVETPCC_EESRH_E45_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EESRH_E45_MAX                               (0x00000001U)

#define CSL_EVETPCC_EESRH_RESETVAL                              (0x00000000U)

/* SER */

#define CSL_EVETPCC_SER_E0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_SER_E0_SHIFT                                (0U)
#define CSL_EVETPCC_SER_E0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E13_MASK                                (0x00002000U)
#define CSL_EVETPCC_SER_E13_SHIFT                               (13U)
#define CSL_EVETPCC_SER_E13_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E13_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E21_MASK                                (0x00200000U)
#define CSL_EVETPCC_SER_E21_SHIFT                               (21U)
#define CSL_EVETPCC_SER_E21_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E21_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E14_MASK                                (0x00004000U)
#define CSL_EVETPCC_SER_E14_SHIFT                               (14U)
#define CSL_EVETPCC_SER_E14_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E14_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E31_MASK                                (0x80000000U)
#define CSL_EVETPCC_SER_E31_SHIFT                               (31U)
#define CSL_EVETPCC_SER_E31_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E31_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_SER_E1_SHIFT                                (1U)
#define CSL_EVETPCC_SER_E1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E11_MASK                                (0x00000800U)
#define CSL_EVETPCC_SER_E11_SHIFT                               (11U)
#define CSL_EVETPCC_SER_E11_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E11_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E19_MASK                                (0x00080000U)
#define CSL_EVETPCC_SER_E19_SHIFT                               (19U)
#define CSL_EVETPCC_SER_E19_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E19_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E20_MASK                                (0x00100000U)
#define CSL_EVETPCC_SER_E20_SHIFT                               (20U)
#define CSL_EVETPCC_SER_E20_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E20_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E12_MASK                                (0x00001000U)
#define CSL_EVETPCC_SER_E12_SHIFT                               (12U)
#define CSL_EVETPCC_SER_E12_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E12_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_SER_E3_SHIFT                                (3U)
#define CSL_EVETPCC_SER_E3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_SER_E4_SHIFT                                (4U)
#define CSL_EVETPCC_SER_E4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E24_MASK                                (0x01000000U)
#define CSL_EVETPCC_SER_E24_SHIFT                               (24U)
#define CSL_EVETPCC_SER_E24_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E24_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_SER_E2_SHIFT                                (2U)
#define CSL_EVETPCC_SER_E2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E22_MASK                                (0x00400000U)
#define CSL_EVETPCC_SER_E22_SHIFT                               (22U)
#define CSL_EVETPCC_SER_E22_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E22_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E23_MASK                                (0x00800000U)
#define CSL_EVETPCC_SER_E23_SHIFT                               (23U)
#define CSL_EVETPCC_SER_E23_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E23_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E25_MASK                                (0x02000000U)
#define CSL_EVETPCC_SER_E25_SHIFT                               (25U)
#define CSL_EVETPCC_SER_E25_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E25_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E26_MASK                                (0x04000000U)
#define CSL_EVETPCC_SER_E26_SHIFT                               (26U)
#define CSL_EVETPCC_SER_E26_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E26_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_SER_E6_SHIFT                                (6U)
#define CSL_EVETPCC_SER_E6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_SER_E5_SHIFT                                (5U)
#define CSL_EVETPCC_SER_E5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E8_MASK                                 (0x00000100U)
#define CSL_EVETPCC_SER_E8_SHIFT                                (8U)
#define CSL_EVETPCC_SER_E8_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E8_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E17_MASK                                (0x00020000U)
#define CSL_EVETPCC_SER_E17_SHIFT                               (17U)
#define CSL_EVETPCC_SER_E17_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E17_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E29_MASK                                (0x20000000U)
#define CSL_EVETPCC_SER_E29_SHIFT                               (29U)
#define CSL_EVETPCC_SER_E29_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E29_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E18_MASK                                (0x00040000U)
#define CSL_EVETPCC_SER_E18_SHIFT                               (18U)
#define CSL_EVETPCC_SER_E18_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E18_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E30_MASK                                (0x40000000U)
#define CSL_EVETPCC_SER_E30_SHIFT                               (30U)
#define CSL_EVETPCC_SER_E30_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E30_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_SER_E7_SHIFT                                (7U)
#define CSL_EVETPCC_SER_E7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E10_MASK                                (0x00000400U)
#define CSL_EVETPCC_SER_E10_SHIFT                               (10U)
#define CSL_EVETPCC_SER_E10_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E10_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E15_MASK                                (0x00008000U)
#define CSL_EVETPCC_SER_E15_SHIFT                               (15U)
#define CSL_EVETPCC_SER_E15_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E15_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E27_MASK                                (0x08000000U)
#define CSL_EVETPCC_SER_E27_SHIFT                               (27U)
#define CSL_EVETPCC_SER_E27_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E27_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E9_MASK                                 (0x00000200U)
#define CSL_EVETPCC_SER_E9_SHIFT                                (9U)
#define CSL_EVETPCC_SER_E9_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_SER_E9_MAX                                  (0x00000001U)

#define CSL_EVETPCC_SER_E16_MASK                                (0x00010000U)
#define CSL_EVETPCC_SER_E16_SHIFT                               (16U)
#define CSL_EVETPCC_SER_E16_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E16_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_E28_MASK                                (0x10000000U)
#define CSL_EVETPCC_SER_E28_SHIFT                               (28U)
#define CSL_EVETPCC_SER_E28_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SER_E28_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SER_RESETVAL                                (0x00000000U)

/* SERH */

#define CSL_EVETPCC_SERH_E53_MASK                               (0x00200000U)
#define CSL_EVETPCC_SERH_E53_SHIFT                              (21U)
#define CSL_EVETPCC_SERH_E53_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E53_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E42_MASK                               (0x00000400U)
#define CSL_EVETPCC_SERH_E42_SHIFT                              (10U)
#define CSL_EVETPCC_SERH_E42_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E42_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E52_MASK                               (0x00100000U)
#define CSL_EVETPCC_SERH_E52_SHIFT                              (20U)
#define CSL_EVETPCC_SERH_E52_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E52_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E43_MASK                               (0x00000800U)
#define CSL_EVETPCC_SERH_E43_SHIFT                              (11U)
#define CSL_EVETPCC_SERH_E43_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E43_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E32_MASK                               (0x00000001U)
#define CSL_EVETPCC_SERH_E32_SHIFT                              (0U)
#define CSL_EVETPCC_SERH_E32_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E32_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E44_MASK                               (0x00001000U)
#define CSL_EVETPCC_SERH_E44_SHIFT                              (12U)
#define CSL_EVETPCC_SERH_E44_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E44_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E55_MASK                               (0x00800000U)
#define CSL_EVETPCC_SERH_E55_SHIFT                              (23U)
#define CSL_EVETPCC_SERH_E55_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E55_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E45_MASK                               (0x00002000U)
#define CSL_EVETPCC_SERH_E45_SHIFT                              (13U)
#define CSL_EVETPCC_SERH_E45_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E45_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E54_MASK                               (0x00400000U)
#define CSL_EVETPCC_SERH_E54_SHIFT                              (22U)
#define CSL_EVETPCC_SERH_E54_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E54_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E46_MASK                               (0x00004000U)
#define CSL_EVETPCC_SERH_E46_SHIFT                              (14U)
#define CSL_EVETPCC_SERH_E46_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E46_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E56_MASK                               (0x01000000U)
#define CSL_EVETPCC_SERH_E56_SHIFT                              (24U)
#define CSL_EVETPCC_SERH_E56_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E56_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E58_MASK                               (0x04000000U)
#define CSL_EVETPCC_SERH_E58_SHIFT                              (26U)
#define CSL_EVETPCC_SERH_E58_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E58_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E57_MASK                               (0x02000000U)
#define CSL_EVETPCC_SERH_E57_SHIFT                              (25U)
#define CSL_EVETPCC_SERH_E57_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E57_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E60_MASK                               (0x10000000U)
#define CSL_EVETPCC_SERH_E60_SHIFT                              (28U)
#define CSL_EVETPCC_SERH_E60_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E60_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E59_MASK                               (0x08000000U)
#define CSL_EVETPCC_SERH_E59_SHIFT                              (27U)
#define CSL_EVETPCC_SERH_E59_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E59_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E61_MASK                               (0x20000000U)
#define CSL_EVETPCC_SERH_E61_SHIFT                              (29U)
#define CSL_EVETPCC_SERH_E61_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E61_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E37_MASK                               (0x00000020U)
#define CSL_EVETPCC_SERH_E37_SHIFT                              (5U)
#define CSL_EVETPCC_SERH_E37_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E37_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E47_MASK                               (0x00008000U)
#define CSL_EVETPCC_SERH_E47_SHIFT                              (15U)
#define CSL_EVETPCC_SERH_E47_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E47_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E38_MASK                               (0x00000040U)
#define CSL_EVETPCC_SERH_E38_SHIFT                              (6U)
#define CSL_EVETPCC_SERH_E38_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E38_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E35_MASK                               (0x00000008U)
#define CSL_EVETPCC_SERH_E35_SHIFT                              (3U)
#define CSL_EVETPCC_SERH_E35_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E35_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E48_MASK                               (0x00010000U)
#define CSL_EVETPCC_SERH_E48_SHIFT                              (16U)
#define CSL_EVETPCC_SERH_E48_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E48_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E62_MASK                               (0x40000000U)
#define CSL_EVETPCC_SERH_E62_SHIFT                              (30U)
#define CSL_EVETPCC_SERH_E62_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E62_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E39_MASK                               (0x00000080U)
#define CSL_EVETPCC_SERH_E39_SHIFT                              (7U)
#define CSL_EVETPCC_SERH_E39_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E39_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E63_MASK                               (0x80000000U)
#define CSL_EVETPCC_SERH_E63_SHIFT                              (31U)
#define CSL_EVETPCC_SERH_E63_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E63_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E36_MASK                               (0x00000010U)
#define CSL_EVETPCC_SERH_E36_SHIFT                              (4U)
#define CSL_EVETPCC_SERH_E36_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E36_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E49_MASK                               (0x00020000U)
#define CSL_EVETPCC_SERH_E49_SHIFT                              (17U)
#define CSL_EVETPCC_SERH_E49_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E49_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E40_MASK                               (0x00000100U)
#define CSL_EVETPCC_SERH_E40_SHIFT                              (8U)
#define CSL_EVETPCC_SERH_E40_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E40_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E33_MASK                               (0x00000002U)
#define CSL_EVETPCC_SERH_E33_SHIFT                              (1U)
#define CSL_EVETPCC_SERH_E33_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E33_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E50_MASK                               (0x00040000U)
#define CSL_EVETPCC_SERH_E50_SHIFT                              (18U)
#define CSL_EVETPCC_SERH_E50_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E50_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E41_MASK                               (0x00000200U)
#define CSL_EVETPCC_SERH_E41_SHIFT                              (9U)
#define CSL_EVETPCC_SERH_E41_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E41_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E34_MASK                               (0x00000004U)
#define CSL_EVETPCC_SERH_E34_SHIFT                              (2U)
#define CSL_EVETPCC_SERH_E34_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E34_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_E51_MASK                               (0x00080000U)
#define CSL_EVETPCC_SERH_E51_SHIFT                              (19U)
#define CSL_EVETPCC_SERH_E51_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SERH_E51_MAX                                (0x00000001U)

#define CSL_EVETPCC_SERH_RESETVAL                               (0x00000000U)

/* SECR */

#define CSL_EVETPCC_SECR_E21_MASK                               (0x00200000U)
#define CSL_EVETPCC_SECR_E21_SHIFT                              (21U)
#define CSL_EVETPCC_SECR_E21_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E21_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E29_MASK                               (0x20000000U)
#define CSL_EVETPCC_SECR_E29_SHIFT                              (29U)
#define CSL_EVETPCC_SECR_E29_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E29_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E20_MASK                               (0x00100000U)
#define CSL_EVETPCC_SECR_E20_SHIFT                              (20U)
#define CSL_EVETPCC_SECR_E20_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E20_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E0_MASK                                (0x00000001U)
#define CSL_EVETPCC_SECR_E0_SHIFT                               (0U)
#define CSL_EVETPCC_SECR_E0_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E0_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E10_MASK                               (0x00000400U)
#define CSL_EVETPCC_SECR_E10_SHIFT                              (10U)
#define CSL_EVETPCC_SECR_E10_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E10_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E9_MASK                                (0x00000200U)
#define CSL_EVETPCC_SECR_E9_SHIFT                               (9U)
#define CSL_EVETPCC_SECR_E9_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E9_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E27_MASK                               (0x08000000U)
#define CSL_EVETPCC_SECR_E27_SHIFT                              (27U)
#define CSL_EVETPCC_SECR_E27_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E27_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E2_MASK                                (0x00000004U)
#define CSL_EVETPCC_SECR_E2_SHIFT                               (2U)
#define CSL_EVETPCC_SECR_E2_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E2_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E12_MASK                               (0x00001000U)
#define CSL_EVETPCC_SECR_E12_SHIFT                              (12U)
#define CSL_EVETPCC_SECR_E12_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E12_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E28_MASK                               (0x10000000U)
#define CSL_EVETPCC_SECR_E28_SHIFT                              (28U)
#define CSL_EVETPCC_SECR_E28_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E28_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E1_MASK                                (0x00000002U)
#define CSL_EVETPCC_SECR_E1_SHIFT                               (1U)
#define CSL_EVETPCC_SECR_E1_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E1_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E11_MASK                               (0x00000800U)
#define CSL_EVETPCC_SECR_E11_SHIFT                              (11U)
#define CSL_EVETPCC_SECR_E11_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E11_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E25_MASK                               (0x02000000U)
#define CSL_EVETPCC_SECR_E25_SHIFT                              (25U)
#define CSL_EVETPCC_SECR_E25_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E25_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E4_MASK                                (0x00000010U)
#define CSL_EVETPCC_SECR_E4_SHIFT                               (4U)
#define CSL_EVETPCC_SECR_E4_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E4_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E14_MASK                               (0x00004000U)
#define CSL_EVETPCC_SECR_E14_SHIFT                              (14U)
#define CSL_EVETPCC_SECR_E14_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E14_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E26_MASK                               (0x04000000U)
#define CSL_EVETPCC_SECR_E26_SHIFT                              (26U)
#define CSL_EVETPCC_SECR_E26_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E26_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E3_MASK                                (0x00000008U)
#define CSL_EVETPCC_SECR_E3_SHIFT                               (3U)
#define CSL_EVETPCC_SECR_E3_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E3_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E13_MASK                               (0x00002000U)
#define CSL_EVETPCC_SECR_E13_SHIFT                              (13U)
#define CSL_EVETPCC_SECR_E13_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E13_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E6_MASK                                (0x00000040U)
#define CSL_EVETPCC_SECR_E6_SHIFT                               (6U)
#define CSL_EVETPCC_SECR_E6_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E6_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E16_MASK                               (0x00010000U)
#define CSL_EVETPCC_SECR_E16_SHIFT                              (16U)
#define CSL_EVETPCC_SECR_E16_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E16_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E24_MASK                               (0x01000000U)
#define CSL_EVETPCC_SECR_E24_SHIFT                              (24U)
#define CSL_EVETPCC_SECR_E24_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E24_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E5_MASK                                (0x00000020U)
#define CSL_EVETPCC_SECR_E5_SHIFT                               (5U)
#define CSL_EVETPCC_SECR_E5_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E5_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E15_MASK                               (0x00008000U)
#define CSL_EVETPCC_SECR_E15_SHIFT                              (15U)
#define CSL_EVETPCC_SECR_E15_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E15_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E18_MASK                               (0x00040000U)
#define CSL_EVETPCC_SECR_E18_SHIFT                              (18U)
#define CSL_EVETPCC_SECR_E18_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E18_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E31_MASK                               (0x80000000U)
#define CSL_EVETPCC_SECR_E31_SHIFT                              (31U)
#define CSL_EVETPCC_SECR_E31_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E31_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E8_MASK                                (0x00000100U)
#define CSL_EVETPCC_SECR_E8_SHIFT                               (8U)
#define CSL_EVETPCC_SECR_E8_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E8_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E22_MASK                               (0x00400000U)
#define CSL_EVETPCC_SECR_E22_SHIFT                              (22U)
#define CSL_EVETPCC_SECR_E22_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E22_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E7_MASK                                (0x00000080U)
#define CSL_EVETPCC_SECR_E7_SHIFT                               (7U)
#define CSL_EVETPCC_SECR_E7_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SECR_E7_MAX                                 (0x00000001U)

#define CSL_EVETPCC_SECR_E19_MASK                               (0x00080000U)
#define CSL_EVETPCC_SECR_E19_SHIFT                              (19U)
#define CSL_EVETPCC_SECR_E19_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E19_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E17_MASK                               (0x00020000U)
#define CSL_EVETPCC_SECR_E17_SHIFT                              (17U)
#define CSL_EVETPCC_SECR_E17_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E17_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E23_MASK                               (0x00800000U)
#define CSL_EVETPCC_SECR_E23_SHIFT                              (23U)
#define CSL_EVETPCC_SECR_E23_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E23_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_E30_MASK                               (0x40000000U)
#define CSL_EVETPCC_SECR_E30_SHIFT                              (30U)
#define CSL_EVETPCC_SECR_E30_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_SECR_E30_MAX                                (0x00000001U)

#define CSL_EVETPCC_SECR_RESETVAL                               (0x00000000U)

/* SECRH */

#define CSL_EVETPCC_SECRH_E34_MASK                              (0x00000004U)
#define CSL_EVETPCC_SECRH_E34_SHIFT                             (2U)
#define CSL_EVETPCC_SECRH_E34_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E34_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E44_MASK                              (0x00001000U)
#define CSL_EVETPCC_SECRH_E44_SHIFT                             (12U)
#define CSL_EVETPCC_SECRH_E44_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E44_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E54_MASK                              (0x00400000U)
#define CSL_EVETPCC_SECRH_E54_SHIFT                             (22U)
#define CSL_EVETPCC_SECRH_E54_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E54_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E33_MASK                              (0x00000002U)
#define CSL_EVETPCC_SECRH_E33_SHIFT                             (1U)
#define CSL_EVETPCC_SECRH_E33_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E33_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E43_MASK                              (0x00000800U)
#define CSL_EVETPCC_SECRH_E43_SHIFT                             (11U)
#define CSL_EVETPCC_SECRH_E43_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E43_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E53_MASK                              (0x00200000U)
#define CSL_EVETPCC_SECRH_E53_SHIFT                             (21U)
#define CSL_EVETPCC_SECRH_E53_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E53_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E58_MASK                              (0x04000000U)
#define CSL_EVETPCC_SECRH_E58_SHIFT                             (26U)
#define CSL_EVETPCC_SECRH_E58_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E58_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E32_MASK                              (0x00000001U)
#define CSL_EVETPCC_SECRH_E32_SHIFT                             (0U)
#define CSL_EVETPCC_SECRH_E32_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E32_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E63_MASK                              (0x80000000U)
#define CSL_EVETPCC_SECRH_E63_SHIFT                             (31U)
#define CSL_EVETPCC_SECRH_E63_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E63_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E57_MASK                              (0x02000000U)
#define CSL_EVETPCC_SECRH_E57_SHIFT                             (25U)
#define CSL_EVETPCC_SECRH_E57_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E57_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E56_MASK                              (0x01000000U)
#define CSL_EVETPCC_SECRH_E56_SHIFT                             (24U)
#define CSL_EVETPCC_SECRH_E56_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E56_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E55_MASK                              (0x00800000U)
#define CSL_EVETPCC_SECRH_E55_SHIFT                             (23U)
#define CSL_EVETPCC_SECRH_E55_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E55_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E52_MASK                              (0x00100000U)
#define CSL_EVETPCC_SECRH_E52_SHIFT                             (20U)
#define CSL_EVETPCC_SECRH_E52_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E52_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E42_MASK                              (0x00000400U)
#define CSL_EVETPCC_SECRH_E42_SHIFT                             (10U)
#define CSL_EVETPCC_SECRH_E42_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E42_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E51_MASK                              (0x00080000U)
#define CSL_EVETPCC_SECRH_E51_SHIFT                             (19U)
#define CSL_EVETPCC_SECRH_E51_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E51_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E41_MASK                              (0x00000200U)
#define CSL_EVETPCC_SECRH_E41_SHIFT                             (9U)
#define CSL_EVETPCC_SECRH_E41_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E41_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E50_MASK                              (0x00040000U)
#define CSL_EVETPCC_SECRH_E50_SHIFT                             (18U)
#define CSL_EVETPCC_SECRH_E50_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E50_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E40_MASK                              (0x00000100U)
#define CSL_EVETPCC_SECRH_E40_SHIFT                             (8U)
#define CSL_EVETPCC_SECRH_E40_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E40_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E49_MASK                              (0x00020000U)
#define CSL_EVETPCC_SECRH_E49_SHIFT                             (17U)
#define CSL_EVETPCC_SECRH_E49_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E49_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E39_MASK                              (0x00000080U)
#define CSL_EVETPCC_SECRH_E39_SHIFT                             (7U)
#define CSL_EVETPCC_SECRH_E39_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E39_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E48_MASK                              (0x00010000U)
#define CSL_EVETPCC_SECRH_E48_SHIFT                             (16U)
#define CSL_EVETPCC_SECRH_E48_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E48_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E38_MASK                              (0x00000040U)
#define CSL_EVETPCC_SECRH_E38_SHIFT                             (6U)
#define CSL_EVETPCC_SECRH_E38_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E38_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E59_MASK                              (0x08000000U)
#define CSL_EVETPCC_SECRH_E59_SHIFT                             (27U)
#define CSL_EVETPCC_SECRH_E59_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E59_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E47_MASK                              (0x00008000U)
#define CSL_EVETPCC_SECRH_E47_SHIFT                             (15U)
#define CSL_EVETPCC_SECRH_E47_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E47_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E37_MASK                              (0x00000020U)
#define CSL_EVETPCC_SECRH_E37_SHIFT                             (5U)
#define CSL_EVETPCC_SECRH_E37_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E37_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E60_MASK                              (0x10000000U)
#define CSL_EVETPCC_SECRH_E60_SHIFT                             (28U)
#define CSL_EVETPCC_SECRH_E60_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E60_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E36_MASK                              (0x00000010U)
#define CSL_EVETPCC_SECRH_E36_SHIFT                             (4U)
#define CSL_EVETPCC_SECRH_E36_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E36_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E46_MASK                              (0x00004000U)
#define CSL_EVETPCC_SECRH_E46_SHIFT                             (14U)
#define CSL_EVETPCC_SECRH_E46_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E46_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E61_MASK                              (0x20000000U)
#define CSL_EVETPCC_SECRH_E61_SHIFT                             (29U)
#define CSL_EVETPCC_SECRH_E61_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E61_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E35_MASK                              (0x00000008U)
#define CSL_EVETPCC_SECRH_E35_SHIFT                             (3U)
#define CSL_EVETPCC_SECRH_E35_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E35_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E62_MASK                              (0x40000000U)
#define CSL_EVETPCC_SECRH_E62_SHIFT                             (30U)
#define CSL_EVETPCC_SECRH_E62_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E62_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_E45_MASK                              (0x00002000U)
#define CSL_EVETPCC_SECRH_E45_SHIFT                             (13U)
#define CSL_EVETPCC_SECRH_E45_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SECRH_E45_MAX                               (0x00000001U)

#define CSL_EVETPCC_SECRH_RESETVAL                              (0x00000000U)

/* IER */

#define CSL_EVETPCC_IER_I15_MASK                                (0x00008000U)
#define CSL_EVETPCC_IER_I15_SHIFT                               (15U)
#define CSL_EVETPCC_IER_I15_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I15_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I30_MASK                                (0x40000000U)
#define CSL_EVETPCC_IER_I30_SHIFT                               (30U)
#define CSL_EVETPCC_IER_I30_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I30_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I14_MASK                                (0x00004000U)
#define CSL_EVETPCC_IER_I14_SHIFT                               (14U)
#define CSL_EVETPCC_IER_I14_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I14_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I29_MASK                                (0x20000000U)
#define CSL_EVETPCC_IER_I29_SHIFT                               (29U)
#define CSL_EVETPCC_IER_I29_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I29_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_IER_I7_SHIFT                                (7U)
#define CSL_EVETPCC_IER_I7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I28_MASK                                (0x10000000U)
#define CSL_EVETPCC_IER_I28_SHIFT                               (28U)
#define CSL_EVETPCC_IER_I28_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I28_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I17_MASK                                (0x00020000U)
#define CSL_EVETPCC_IER_I17_SHIFT                               (17U)
#define CSL_EVETPCC_IER_I17_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I17_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I16_MASK                                (0x00010000U)
#define CSL_EVETPCC_IER_I16_SHIFT                               (16U)
#define CSL_EVETPCC_IER_I16_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I16_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I27_MASK                                (0x08000000U)
#define CSL_EVETPCC_IER_I27_SHIFT                               (27U)
#define CSL_EVETPCC_IER_I27_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I27_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_IER_I0_SHIFT                                (0U)
#define CSL_EVETPCC_IER_I0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_IER_I1_SHIFT                                (1U)
#define CSL_EVETPCC_IER_I1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I13_MASK                                (0x00002000U)
#define CSL_EVETPCC_IER_I13_SHIFT                               (13U)
#define CSL_EVETPCC_IER_I13_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I13_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_IER_I2_SHIFT                                (2U)
#define CSL_EVETPCC_IER_I2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I31_MASK                                (0x80000000U)
#define CSL_EVETPCC_IER_I31_SHIFT                               (31U)
#define CSL_EVETPCC_IER_I31_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I31_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I22_MASK                                (0x00400000U)
#define CSL_EVETPCC_IER_I22_SHIFT                               (22U)
#define CSL_EVETPCC_IER_I22_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I22_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_IER_I3_SHIFT                                (3U)
#define CSL_EVETPCC_IER_I3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I26_MASK                                (0x04000000U)
#define CSL_EVETPCC_IER_I26_SHIFT                               (26U)
#define CSL_EVETPCC_IER_I26_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I26_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_IER_I5_SHIFT                                (5U)
#define CSL_EVETPCC_IER_I5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I19_MASK                                (0x00080000U)
#define CSL_EVETPCC_IER_I19_SHIFT                               (19U)
#define CSL_EVETPCC_IER_I19_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I19_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I8_MASK                                 (0x00000100U)
#define CSL_EVETPCC_IER_I8_SHIFT                                (8U)
#define CSL_EVETPCC_IER_I8_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I8_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I25_MASK                                (0x02000000U)
#define CSL_EVETPCC_IER_I25_SHIFT                               (25U)
#define CSL_EVETPCC_IER_I25_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I25_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_IER_I4_SHIFT                                (4U)
#define CSL_EVETPCC_IER_I4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I18_MASK                                (0x00040000U)
#define CSL_EVETPCC_IER_I18_SHIFT                               (18U)
#define CSL_EVETPCC_IER_I18_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I18_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I9_MASK                                 (0x00000200U)
#define CSL_EVETPCC_IER_I9_SHIFT                                (9U)
#define CSL_EVETPCC_IER_I9_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I9_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I21_MASK                                (0x00200000U)
#define CSL_EVETPCC_IER_I21_SHIFT                               (21U)
#define CSL_EVETPCC_IER_I21_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I21_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I24_MASK                                (0x01000000U)
#define CSL_EVETPCC_IER_I24_SHIFT                               (24U)
#define CSL_EVETPCC_IER_I24_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I24_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I10_MASK                                (0x00000400U)
#define CSL_EVETPCC_IER_I10_SHIFT                               (10U)
#define CSL_EVETPCC_IER_I10_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I10_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I12_MASK                                (0x00001000U)
#define CSL_EVETPCC_IER_I12_SHIFT                               (12U)
#define CSL_EVETPCC_IER_I12_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I12_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I23_MASK                                (0x00800000U)
#define CSL_EVETPCC_IER_I23_SHIFT                               (23U)
#define CSL_EVETPCC_IER_I23_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I23_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I20_MASK                                (0x00100000U)
#define CSL_EVETPCC_IER_I20_SHIFT                               (20U)
#define CSL_EVETPCC_IER_I20_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I20_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_I6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_IER_I6_SHIFT                                (6U)
#define CSL_EVETPCC_IER_I6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IER_I6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IER_I11_MASK                                (0x00000800U)
#define CSL_EVETPCC_IER_I11_SHIFT                               (11U)
#define CSL_EVETPCC_IER_I11_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IER_I11_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IER_RESETVAL                                (0x00000000U)

/* IERH */

#define CSL_EVETPCC_IERH_I48_MASK                               (0x00010000U)
#define CSL_EVETPCC_IERH_I48_SHIFT                              (16U)
#define CSL_EVETPCC_IERH_I48_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I48_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I35_MASK                               (0x00000008U)
#define CSL_EVETPCC_IERH_I35_SHIFT                              (3U)
#define CSL_EVETPCC_IERH_I35_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I35_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I34_MASK                               (0x00000004U)
#define CSL_EVETPCC_IERH_I34_SHIFT                              (2U)
#define CSL_EVETPCC_IERH_I34_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I34_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I46_MASK                               (0x00004000U)
#define CSL_EVETPCC_IERH_I46_SHIFT                              (14U)
#define CSL_EVETPCC_IERH_I46_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I46_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I59_MASK                               (0x08000000U)
#define CSL_EVETPCC_IERH_I59_SHIFT                              (27U)
#define CSL_EVETPCC_IERH_I59_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I59_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I33_MASK                               (0x00000002U)
#define CSL_EVETPCC_IERH_I33_SHIFT                              (1U)
#define CSL_EVETPCC_IERH_I33_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I33_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I45_MASK                               (0x00002000U)
#define CSL_EVETPCC_IERH_I45_SHIFT                              (13U)
#define CSL_EVETPCC_IERH_I45_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I45_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I60_MASK                               (0x10000000U)
#define CSL_EVETPCC_IERH_I60_SHIFT                              (28U)
#define CSL_EVETPCC_IERH_I60_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I60_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I32_MASK                               (0x00000001U)
#define CSL_EVETPCC_IERH_I32_SHIFT                              (0U)
#define CSL_EVETPCC_IERH_I32_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I32_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I44_MASK                               (0x00001000U)
#define CSL_EVETPCC_IERH_I44_SHIFT                              (12U)
#define CSL_EVETPCC_IERH_I44_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I44_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I61_MASK                               (0x20000000U)
#define CSL_EVETPCC_IERH_I61_SHIFT                              (29U)
#define CSL_EVETPCC_IERH_I61_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I61_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I43_MASK                               (0x00000800U)
#define CSL_EVETPCC_IERH_I43_SHIFT                              (11U)
#define CSL_EVETPCC_IERH_I43_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I43_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I49_MASK                               (0x00020000U)
#define CSL_EVETPCC_IERH_I49_SHIFT                              (17U)
#define CSL_EVETPCC_IERH_I49_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I49_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I62_MASK                               (0x40000000U)
#define CSL_EVETPCC_IERH_I62_SHIFT                              (30U)
#define CSL_EVETPCC_IERH_I62_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I62_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I50_MASK                               (0x00040000U)
#define CSL_EVETPCC_IERH_I50_SHIFT                              (18U)
#define CSL_EVETPCC_IERH_I50_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I50_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I42_MASK                               (0x00000400U)
#define CSL_EVETPCC_IERH_I42_SHIFT                              (10U)
#define CSL_EVETPCC_IERH_I42_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I42_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I63_MASK                               (0x80000000U)
#define CSL_EVETPCC_IERH_I63_SHIFT                              (31U)
#define CSL_EVETPCC_IERH_I63_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I63_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I51_MASK                               (0x00080000U)
#define CSL_EVETPCC_IERH_I51_SHIFT                              (19U)
#define CSL_EVETPCC_IERH_I51_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I51_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I41_MASK                               (0x00000200U)
#define CSL_EVETPCC_IERH_I41_SHIFT                              (9U)
#define CSL_EVETPCC_IERH_I41_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I41_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I52_MASK                               (0x00100000U)
#define CSL_EVETPCC_IERH_I52_SHIFT                              (20U)
#define CSL_EVETPCC_IERH_I52_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I52_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I40_MASK                               (0x00000100U)
#define CSL_EVETPCC_IERH_I40_SHIFT                              (8U)
#define CSL_EVETPCC_IERH_I40_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I40_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I53_MASK                               (0x00200000U)
#define CSL_EVETPCC_IERH_I53_SHIFT                              (21U)
#define CSL_EVETPCC_IERH_I53_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I53_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I39_MASK                               (0x00000080U)
#define CSL_EVETPCC_IERH_I39_SHIFT                              (7U)
#define CSL_EVETPCC_IERH_I39_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I39_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I54_MASK                               (0x00400000U)
#define CSL_EVETPCC_IERH_I54_SHIFT                              (22U)
#define CSL_EVETPCC_IERH_I54_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I54_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I55_MASK                               (0x00800000U)
#define CSL_EVETPCC_IERH_I55_SHIFT                              (23U)
#define CSL_EVETPCC_IERH_I55_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I55_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I56_MASK                               (0x01000000U)
#define CSL_EVETPCC_IERH_I56_SHIFT                              (24U)
#define CSL_EVETPCC_IERH_I56_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I56_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I38_MASK                               (0x00000040U)
#define CSL_EVETPCC_IERH_I38_SHIFT                              (6U)
#define CSL_EVETPCC_IERH_I38_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I38_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I57_MASK                               (0x02000000U)
#define CSL_EVETPCC_IERH_I57_SHIFT                              (25U)
#define CSL_EVETPCC_IERH_I57_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I57_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I58_MASK                               (0x04000000U)
#define CSL_EVETPCC_IERH_I58_SHIFT                              (26U)
#define CSL_EVETPCC_IERH_I58_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I58_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I37_MASK                               (0x00000020U)
#define CSL_EVETPCC_IERH_I37_SHIFT                              (5U)
#define CSL_EVETPCC_IERH_I37_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I37_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I47_MASK                               (0x00008000U)
#define CSL_EVETPCC_IERH_I47_SHIFT                              (15U)
#define CSL_EVETPCC_IERH_I47_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I47_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_I36_MASK                               (0x00000010U)
#define CSL_EVETPCC_IERH_I36_SHIFT                              (4U)
#define CSL_EVETPCC_IERH_I36_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IERH_I36_MAX                                (0x00000001U)

#define CSL_EVETPCC_IERH_RESETVAL                               (0x00000000U)

/* IECR */

#define CSL_EVETPCC_IECR_I27_MASK                               (0x08000000U)
#define CSL_EVETPCC_IECR_I27_SHIFT                              (27U)
#define CSL_EVETPCC_IECR_I27_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I27_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I28_MASK                               (0x10000000U)
#define CSL_EVETPCC_IECR_I28_SHIFT                              (28U)
#define CSL_EVETPCC_IECR_I28_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I28_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I25_MASK                               (0x02000000U)
#define CSL_EVETPCC_IECR_I25_SHIFT                              (25U)
#define CSL_EVETPCC_IECR_I25_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I25_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I16_MASK                               (0x00010000U)
#define CSL_EVETPCC_IECR_I16_SHIFT                              (16U)
#define CSL_EVETPCC_IECR_I16_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I16_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I26_MASK                               (0x04000000U)
#define CSL_EVETPCC_IECR_I26_SHIFT                              (26U)
#define CSL_EVETPCC_IECR_I26_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I26_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I15_MASK                               (0x00008000U)
#define CSL_EVETPCC_IECR_I15_SHIFT                              (15U)
#define CSL_EVETPCC_IECR_I15_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I15_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I14_MASK                               (0x00004000U)
#define CSL_EVETPCC_IECR_I14_SHIFT                              (14U)
#define CSL_EVETPCC_IECR_I14_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I14_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I13_MASK                               (0x00002000U)
#define CSL_EVETPCC_IECR_I13_SHIFT                              (13U)
#define CSL_EVETPCC_IECR_I13_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I13_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I0_MASK                                (0x00000001U)
#define CSL_EVETPCC_IECR_I0_SHIFT                               (0U)
#define CSL_EVETPCC_IECR_I0_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I0_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_I22_MASK                               (0x00400000U)
#define CSL_EVETPCC_IECR_I22_SHIFT                              (22U)
#define CSL_EVETPCC_IECR_I22_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I22_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I10_MASK                               (0x00000400U)
#define CSL_EVETPCC_IECR_I10_SHIFT                              (10U)
#define CSL_EVETPCC_IECR_I10_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I10_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I21_MASK                               (0x00200000U)
#define CSL_EVETPCC_IECR_I21_SHIFT                              (21U)
#define CSL_EVETPCC_IECR_I21_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I21_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I9_MASK                                (0x00000200U)
#define CSL_EVETPCC_IECR_I9_SHIFT                               (9U)
#define CSL_EVETPCC_IECR_I9_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I9_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_I1_MASK                                (0x00000002U)
#define CSL_EVETPCC_IECR_I1_SHIFT                               (1U)
#define CSL_EVETPCC_IECR_I1_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I1_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_I24_MASK                               (0x01000000U)
#define CSL_EVETPCC_IECR_I24_SHIFT                              (24U)
#define CSL_EVETPCC_IECR_I24_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I24_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I3_MASK                                (0x00000008U)
#define CSL_EVETPCC_IECR_I3_SHIFT                               (3U)
#define CSL_EVETPCC_IECR_I3_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I3_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_I2_MASK                                (0x00000004U)
#define CSL_EVETPCC_IECR_I2_SHIFT                               (2U)
#define CSL_EVETPCC_IECR_I2_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I2_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_I12_MASK                               (0x00001000U)
#define CSL_EVETPCC_IECR_I12_SHIFT                              (12U)
#define CSL_EVETPCC_IECR_I12_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I12_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I23_MASK                               (0x00800000U)
#define CSL_EVETPCC_IECR_I23_SHIFT                              (23U)
#define CSL_EVETPCC_IECR_I23_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I23_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I4_MASK                                (0x00000010U)
#define CSL_EVETPCC_IECR_I4_SHIFT                               (4U)
#define CSL_EVETPCC_IECR_I4_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I4_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_I11_MASK                               (0x00000800U)
#define CSL_EVETPCC_IECR_I11_SHIFT                              (11U)
#define CSL_EVETPCC_IECR_I11_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I11_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I6_MASK                                (0x00000040U)
#define CSL_EVETPCC_IECR_I6_SHIFT                               (6U)
#define CSL_EVETPCC_IECR_I6_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I6_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_I31_MASK                               (0x80000000U)
#define CSL_EVETPCC_IECR_I31_SHIFT                              (31U)
#define CSL_EVETPCC_IECR_I31_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I31_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I18_MASK                               (0x00040000U)
#define CSL_EVETPCC_IECR_I18_SHIFT                              (18U)
#define CSL_EVETPCC_IECR_I18_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I18_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I17_MASK                               (0x00020000U)
#define CSL_EVETPCC_IECR_I17_SHIFT                              (17U)
#define CSL_EVETPCC_IECR_I17_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I17_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I5_MASK                                (0x00000020U)
#define CSL_EVETPCC_IECR_I5_SHIFT                               (5U)
#define CSL_EVETPCC_IECR_I5_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I5_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_I20_MASK                               (0x00100000U)
#define CSL_EVETPCC_IECR_I20_SHIFT                              (20U)
#define CSL_EVETPCC_IECR_I20_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I20_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I29_MASK                               (0x20000000U)
#define CSL_EVETPCC_IECR_I29_SHIFT                              (29U)
#define CSL_EVETPCC_IECR_I29_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I29_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I8_MASK                                (0x00000100U)
#define CSL_EVETPCC_IECR_I8_SHIFT                               (8U)
#define CSL_EVETPCC_IECR_I8_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I8_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_I19_MASK                               (0x00080000U)
#define CSL_EVETPCC_IECR_I19_SHIFT                              (19U)
#define CSL_EVETPCC_IECR_I19_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I19_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I30_MASK                               (0x40000000U)
#define CSL_EVETPCC_IECR_I30_SHIFT                              (30U)
#define CSL_EVETPCC_IECR_I30_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IECR_I30_MAX                                (0x00000001U)

#define CSL_EVETPCC_IECR_I7_MASK                                (0x00000080U)
#define CSL_EVETPCC_IECR_I7_SHIFT                               (7U)
#define CSL_EVETPCC_IECR_I7_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IECR_I7_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IECR_RESETVAL                               (0x00000000U)

/* IECRH */

#define CSL_EVETPCC_IECRH_I35_MASK                              (0x00000008U)
#define CSL_EVETPCC_IECRH_I35_SHIFT                             (3U)
#define CSL_EVETPCC_IECRH_I35_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I35_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I48_MASK                              (0x00010000U)
#define CSL_EVETPCC_IECRH_I48_SHIFT                             (16U)
#define CSL_EVETPCC_IECRH_I48_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I48_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I56_MASK                              (0x01000000U)
#define CSL_EVETPCC_IECRH_I56_SHIFT                             (24U)
#define CSL_EVETPCC_IECRH_I56_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I56_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I34_MASK                              (0x00000004U)
#define CSL_EVETPCC_IECRH_I34_SHIFT                             (2U)
#define CSL_EVETPCC_IECRH_I34_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I34_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I47_MASK                              (0x00008000U)
#define CSL_EVETPCC_IECRH_I47_SHIFT                             (15U)
#define CSL_EVETPCC_IECRH_I47_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I47_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I46_MASK                              (0x00004000U)
#define CSL_EVETPCC_IECRH_I46_SHIFT                             (14U)
#define CSL_EVETPCC_IECRH_I46_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I46_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I55_MASK                              (0x00800000U)
#define CSL_EVETPCC_IECRH_I55_SHIFT                             (23U)
#define CSL_EVETPCC_IECRH_I55_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I55_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I45_MASK                              (0x00002000U)
#define CSL_EVETPCC_IECRH_I45_SHIFT                             (13U)
#define CSL_EVETPCC_IECRH_I45_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I45_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I58_MASK                              (0x04000000U)
#define CSL_EVETPCC_IECRH_I58_SHIFT                             (26U)
#define CSL_EVETPCC_IECRH_I58_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I58_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I32_MASK                              (0x00000001U)
#define CSL_EVETPCC_IECRH_I32_SHIFT                             (0U)
#define CSL_EVETPCC_IECRH_I32_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I32_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I44_MASK                              (0x00001000U)
#define CSL_EVETPCC_IECRH_I44_SHIFT                             (12U)
#define CSL_EVETPCC_IECRH_I44_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I44_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I33_MASK                              (0x00000002U)
#define CSL_EVETPCC_IECRH_I33_SHIFT                             (1U)
#define CSL_EVETPCC_IECRH_I33_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I33_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I57_MASK                              (0x02000000U)
#define CSL_EVETPCC_IECRH_I57_SHIFT                             (25U)
#define CSL_EVETPCC_IECRH_I57_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I57_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I43_MASK                              (0x00000800U)
#define CSL_EVETPCC_IECRH_I43_SHIFT                             (11U)
#define CSL_EVETPCC_IECRH_I43_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I43_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I60_MASK                              (0x10000000U)
#define CSL_EVETPCC_IECRH_I60_SHIFT                             (28U)
#define CSL_EVETPCC_IECRH_I60_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I60_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I42_MASK                              (0x00000400U)
#define CSL_EVETPCC_IECRH_I42_SHIFT                             (10U)
#define CSL_EVETPCC_IECRH_I42_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I42_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I59_MASK                              (0x08000000U)
#define CSL_EVETPCC_IECRH_I59_SHIFT                             (27U)
#define CSL_EVETPCC_IECRH_I59_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I59_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I41_MASK                              (0x00000200U)
#define CSL_EVETPCC_IECRH_I41_SHIFT                             (9U)
#define CSL_EVETPCC_IECRH_I41_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I41_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I62_MASK                              (0x40000000U)
#define CSL_EVETPCC_IECRH_I62_SHIFT                             (30U)
#define CSL_EVETPCC_IECRH_I62_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I62_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I61_MASK                              (0x20000000U)
#define CSL_EVETPCC_IECRH_I61_SHIFT                             (29U)
#define CSL_EVETPCC_IECRH_I61_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I61_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I52_MASK                              (0x00100000U)
#define CSL_EVETPCC_IECRH_I52_SHIFT                             (20U)
#define CSL_EVETPCC_IECRH_I52_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I52_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I38_MASK                              (0x00000040U)
#define CSL_EVETPCC_IECRH_I38_SHIFT                             (6U)
#define CSL_EVETPCC_IECRH_I38_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I38_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I40_MASK                              (0x00000100U)
#define CSL_EVETPCC_IECRH_I40_SHIFT                             (8U)
#define CSL_EVETPCC_IECRH_I40_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I40_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I51_MASK                              (0x00080000U)
#define CSL_EVETPCC_IECRH_I51_SHIFT                             (19U)
#define CSL_EVETPCC_IECRH_I51_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I51_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I50_MASK                              (0x00040000U)
#define CSL_EVETPCC_IECRH_I50_SHIFT                             (18U)
#define CSL_EVETPCC_IECRH_I50_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I50_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I63_MASK                              (0x80000000U)
#define CSL_EVETPCC_IECRH_I63_SHIFT                             (31U)
#define CSL_EVETPCC_IECRH_I63_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I63_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I39_MASK                              (0x00000080U)
#define CSL_EVETPCC_IECRH_I39_SHIFT                             (7U)
#define CSL_EVETPCC_IECRH_I39_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I39_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I54_MASK                              (0x00400000U)
#define CSL_EVETPCC_IECRH_I54_SHIFT                             (22U)
#define CSL_EVETPCC_IECRH_I54_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I54_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I36_MASK                              (0x00000010U)
#define CSL_EVETPCC_IECRH_I36_SHIFT                             (4U)
#define CSL_EVETPCC_IECRH_I36_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I36_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I53_MASK                              (0x00200000U)
#define CSL_EVETPCC_IECRH_I53_SHIFT                             (21U)
#define CSL_EVETPCC_IECRH_I53_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I53_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I49_MASK                              (0x00020000U)
#define CSL_EVETPCC_IECRH_I49_SHIFT                             (17U)
#define CSL_EVETPCC_IECRH_I49_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I49_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_I37_MASK                              (0x00000020U)
#define CSL_EVETPCC_IECRH_I37_SHIFT                             (5U)
#define CSL_EVETPCC_IECRH_I37_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IECRH_I37_MAX                               (0x00000001U)

#define CSL_EVETPCC_IECRH_RESETVAL                              (0x00000000U)

/* IESR */

#define CSL_EVETPCC_IESR_I22_MASK                               (0x00400000U)
#define CSL_EVETPCC_IESR_I22_SHIFT                              (22U)
#define CSL_EVETPCC_IESR_I22_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I22_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I11_MASK                               (0x00000800U)
#define CSL_EVETPCC_IESR_I11_SHIFT                              (11U)
#define CSL_EVETPCC_IESR_I11_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I11_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I23_MASK                               (0x00800000U)
#define CSL_EVETPCC_IESR_I23_SHIFT                              (23U)
#define CSL_EVETPCC_IESR_I23_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I23_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I0_MASK                                (0x00000001U)
#define CSL_EVETPCC_IESR_I0_SHIFT                               (0U)
#define CSL_EVETPCC_IESR_I0_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I0_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I21_MASK                               (0x00200000U)
#define CSL_EVETPCC_IESR_I21_SHIFT                              (21U)
#define CSL_EVETPCC_IESR_I21_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I21_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I10_MASK                               (0x00000400U)
#define CSL_EVETPCC_IESR_I10_SHIFT                              (10U)
#define CSL_EVETPCC_IESR_I10_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I10_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I31_MASK                               (0x80000000U)
#define CSL_EVETPCC_IESR_I31_SHIFT                              (31U)
#define CSL_EVETPCC_IESR_I31_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I31_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I8_MASK                                (0x00000100U)
#define CSL_EVETPCC_IESR_I8_SHIFT                               (8U)
#define CSL_EVETPCC_IESR_I8_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I8_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I20_MASK                               (0x00100000U)
#define CSL_EVETPCC_IESR_I20_SHIFT                              (20U)
#define CSL_EVETPCC_IESR_I20_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I20_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I9_MASK                                (0x00000200U)
#define CSL_EVETPCC_IESR_I9_SHIFT                               (9U)
#define CSL_EVETPCC_IESR_I9_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I9_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I6_MASK                                (0x00000040U)
#define CSL_EVETPCC_IESR_I6_SHIFT                               (6U)
#define CSL_EVETPCC_IESR_I6_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I6_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I30_MASK                               (0x40000000U)
#define CSL_EVETPCC_IESR_I30_SHIFT                              (30U)
#define CSL_EVETPCC_IESR_I30_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I30_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I17_MASK                               (0x00020000U)
#define CSL_EVETPCC_IESR_I17_SHIFT                              (17U)
#define CSL_EVETPCC_IESR_I17_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I17_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I7_MASK                                (0x00000080U)
#define CSL_EVETPCC_IESR_I7_SHIFT                               (7U)
#define CSL_EVETPCC_IESR_I7_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I7_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I16_MASK                               (0x00010000U)
#define CSL_EVETPCC_IESR_I16_SHIFT                              (16U)
#define CSL_EVETPCC_IESR_I16_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I16_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I28_MASK                               (0x10000000U)
#define CSL_EVETPCC_IESR_I28_SHIFT                              (28U)
#define CSL_EVETPCC_IESR_I28_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I28_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I4_MASK                                (0x00000010U)
#define CSL_EVETPCC_IESR_I4_SHIFT                               (4U)
#define CSL_EVETPCC_IESR_I4_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I4_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I29_MASK                               (0x20000000U)
#define CSL_EVETPCC_IESR_I29_SHIFT                              (29U)
#define CSL_EVETPCC_IESR_I29_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I29_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I19_MASK                               (0x00080000U)
#define CSL_EVETPCC_IESR_I19_SHIFT                              (19U)
#define CSL_EVETPCC_IESR_I19_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I19_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I5_MASK                                (0x00000020U)
#define CSL_EVETPCC_IESR_I5_SHIFT                               (5U)
#define CSL_EVETPCC_IESR_I5_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I5_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I18_MASK                               (0x00040000U)
#define CSL_EVETPCC_IESR_I18_SHIFT                              (18U)
#define CSL_EVETPCC_IESR_I18_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I18_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I26_MASK                               (0x04000000U)
#define CSL_EVETPCC_IESR_I26_SHIFT                              (26U)
#define CSL_EVETPCC_IESR_I26_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I26_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I2_MASK                                (0x00000004U)
#define CSL_EVETPCC_IESR_I2_SHIFT                               (2U)
#define CSL_EVETPCC_IESR_I2_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I2_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I13_MASK                               (0x00002000U)
#define CSL_EVETPCC_IESR_I13_SHIFT                              (13U)
#define CSL_EVETPCC_IESR_I13_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I13_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I3_MASK                                (0x00000008U)
#define CSL_EVETPCC_IESR_I3_SHIFT                               (3U)
#define CSL_EVETPCC_IESR_I3_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I3_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I27_MASK                               (0x08000000U)
#define CSL_EVETPCC_IESR_I27_SHIFT                              (27U)
#define CSL_EVETPCC_IESR_I27_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I27_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I12_MASK                               (0x00001000U)
#define CSL_EVETPCC_IESR_I12_SHIFT                              (12U)
#define CSL_EVETPCC_IESR_I12_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I12_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I24_MASK                               (0x01000000U)
#define CSL_EVETPCC_IESR_I24_SHIFT                              (24U)
#define CSL_EVETPCC_IESR_I24_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I24_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I15_MASK                               (0x00008000U)
#define CSL_EVETPCC_IESR_I15_SHIFT                              (15U)
#define CSL_EVETPCC_IESR_I15_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I15_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I1_MASK                                (0x00000002U)
#define CSL_EVETPCC_IESR_I1_SHIFT                               (1U)
#define CSL_EVETPCC_IESR_I1_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IESR_I1_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IESR_I25_MASK                               (0x02000000U)
#define CSL_EVETPCC_IESR_I25_SHIFT                              (25U)
#define CSL_EVETPCC_IESR_I25_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I25_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_I14_MASK                               (0x00004000U)
#define CSL_EVETPCC_IESR_I14_SHIFT                              (14U)
#define CSL_EVETPCC_IESR_I14_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IESR_I14_MAX                                (0x00000001U)

#define CSL_EVETPCC_IESR_RESETVAL                               (0x00000000U)

/* IESRH */

#define CSL_EVETPCC_IESRH_I52_MASK                              (0x00100000U)
#define CSL_EVETPCC_IESRH_I52_SHIFT                             (20U)
#define CSL_EVETPCC_IESRH_I52_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I52_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I41_MASK                              (0x00000200U)
#define CSL_EVETPCC_IESRH_I41_SHIFT                             (9U)
#define CSL_EVETPCC_IESRH_I41_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I41_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I53_MASK                              (0x00200000U)
#define CSL_EVETPCC_IESRH_I53_SHIFT                             (21U)
#define CSL_EVETPCC_IESRH_I53_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I53_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I42_MASK                              (0x00000400U)
#define CSL_EVETPCC_IESRH_I42_SHIFT                             (10U)
#define CSL_EVETPCC_IESRH_I42_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I42_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I54_MASK                              (0x00400000U)
#define CSL_EVETPCC_IESRH_I54_SHIFT                             (22U)
#define CSL_EVETPCC_IESRH_I54_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I54_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I43_MASK                              (0x00000800U)
#define CSL_EVETPCC_IESRH_I43_SHIFT                             (11U)
#define CSL_EVETPCC_IESRH_I43_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I43_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I55_MASK                              (0x00800000U)
#define CSL_EVETPCC_IESRH_I55_SHIFT                             (23U)
#define CSL_EVETPCC_IESRH_I55_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I55_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I44_MASK                              (0x00001000U)
#define CSL_EVETPCC_IESRH_I44_SHIFT                             (12U)
#define CSL_EVETPCC_IESRH_I44_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I44_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I33_MASK                              (0x00000002U)
#define CSL_EVETPCC_IESRH_I33_SHIFT                             (1U)
#define CSL_EVETPCC_IESRH_I33_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I33_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I56_MASK                              (0x01000000U)
#define CSL_EVETPCC_IESRH_I56_SHIFT                             (24U)
#define CSL_EVETPCC_IESRH_I56_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I56_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I45_MASK                              (0x00002000U)
#define CSL_EVETPCC_IESRH_I45_SHIFT                             (13U)
#define CSL_EVETPCC_IESRH_I45_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I45_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I57_MASK                              (0x02000000U)
#define CSL_EVETPCC_IESRH_I57_SHIFT                             (25U)
#define CSL_EVETPCC_IESRH_I57_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I57_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I32_MASK                              (0x00000001U)
#define CSL_EVETPCC_IESRH_I32_SHIFT                             (0U)
#define CSL_EVETPCC_IESRH_I32_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I32_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I46_MASK                              (0x00004000U)
#define CSL_EVETPCC_IESRH_I46_SHIFT                             (14U)
#define CSL_EVETPCC_IESRH_I46_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I46_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I35_MASK                              (0x00000008U)
#define CSL_EVETPCC_IESRH_I35_SHIFT                             (3U)
#define CSL_EVETPCC_IESRH_I35_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I35_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I58_MASK                              (0x04000000U)
#define CSL_EVETPCC_IESRH_I58_SHIFT                             (26U)
#define CSL_EVETPCC_IESRH_I58_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I58_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I47_MASK                              (0x00008000U)
#define CSL_EVETPCC_IESRH_I47_SHIFT                             (15U)
#define CSL_EVETPCC_IESRH_I47_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I47_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I34_MASK                              (0x00000004U)
#define CSL_EVETPCC_IESRH_I34_SHIFT                             (2U)
#define CSL_EVETPCC_IESRH_I34_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I34_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I59_MASK                              (0x08000000U)
#define CSL_EVETPCC_IESRH_I59_SHIFT                             (27U)
#define CSL_EVETPCC_IESRH_I59_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I59_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I48_MASK                              (0x00010000U)
#define CSL_EVETPCC_IESRH_I48_SHIFT                             (16U)
#define CSL_EVETPCC_IESRH_I48_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I48_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I60_MASK                              (0x10000000U)
#define CSL_EVETPCC_IESRH_I60_SHIFT                             (28U)
#define CSL_EVETPCC_IESRH_I60_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I60_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I37_MASK                              (0x00000020U)
#define CSL_EVETPCC_IESRH_I37_SHIFT                             (5U)
#define CSL_EVETPCC_IESRH_I37_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I37_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I49_MASK                              (0x00020000U)
#define CSL_EVETPCC_IESRH_I49_SHIFT                             (17U)
#define CSL_EVETPCC_IESRH_I49_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I49_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I36_MASK                              (0x00000010U)
#define CSL_EVETPCC_IESRH_I36_SHIFT                             (4U)
#define CSL_EVETPCC_IESRH_I36_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I36_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I50_MASK                              (0x00040000U)
#define CSL_EVETPCC_IESRH_I50_SHIFT                             (18U)
#define CSL_EVETPCC_IESRH_I50_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I50_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I39_MASK                              (0x00000080U)
#define CSL_EVETPCC_IESRH_I39_SHIFT                             (7U)
#define CSL_EVETPCC_IESRH_I39_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I39_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I38_MASK                              (0x00000040U)
#define CSL_EVETPCC_IESRH_I38_SHIFT                             (6U)
#define CSL_EVETPCC_IESRH_I38_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I38_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I63_MASK                              (0x80000000U)
#define CSL_EVETPCC_IESRH_I63_SHIFT                             (31U)
#define CSL_EVETPCC_IESRH_I63_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I63_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I62_MASK                              (0x40000000U)
#define CSL_EVETPCC_IESRH_I62_SHIFT                             (30U)
#define CSL_EVETPCC_IESRH_I62_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I62_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I40_MASK                              (0x00000100U)
#define CSL_EVETPCC_IESRH_I40_SHIFT                             (8U)
#define CSL_EVETPCC_IESRH_I40_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I40_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I61_MASK                              (0x20000000U)
#define CSL_EVETPCC_IESRH_I61_SHIFT                             (29U)
#define CSL_EVETPCC_IESRH_I61_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I61_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_I51_MASK                              (0x00080000U)
#define CSL_EVETPCC_IESRH_I51_SHIFT                             (19U)
#define CSL_EVETPCC_IESRH_I51_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IESRH_I51_MAX                               (0x00000001U)

#define CSL_EVETPCC_IESRH_RESETVAL                              (0x00000000U)

/* IPR */

#define CSL_EVETPCC_IPR_I15_MASK                                (0x00008000U)
#define CSL_EVETPCC_IPR_I15_SHIFT                               (15U)
#define CSL_EVETPCC_IPR_I15_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I15_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I27_MASK                                (0x08000000U)
#define CSL_EVETPCC_IPR_I27_SHIFT                               (27U)
#define CSL_EVETPCC_IPR_I27_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I27_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_IPR_I3_SHIFT                                (3U)
#define CSL_EVETPCC_IPR_I3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I14_MASK                                (0x00004000U)
#define CSL_EVETPCC_IPR_I14_SHIFT                               (14U)
#define CSL_EVETPCC_IPR_I14_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I14_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_IPR_I2_SHIFT                                (2U)
#define CSL_EVETPCC_IPR_I2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_IPR_I1_SHIFT                                (1U)
#define CSL_EVETPCC_IPR_I1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I13_MASK                                (0x00002000U)
#define CSL_EVETPCC_IPR_I13_SHIFT                               (13U)
#define CSL_EVETPCC_IPR_I13_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I13_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I28_MASK                                (0x10000000U)
#define CSL_EVETPCC_IPR_I28_SHIFT                               (28U)
#define CSL_EVETPCC_IPR_I28_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I28_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I17_MASK                                (0x00020000U)
#define CSL_EVETPCC_IPR_I17_SHIFT                               (17U)
#define CSL_EVETPCC_IPR_I17_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I17_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_IPR_I0_SHIFT                                (0U)
#define CSL_EVETPCC_IPR_I0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I12_MASK                                (0x00001000U)
#define CSL_EVETPCC_IPR_I12_SHIFT                               (12U)
#define CSL_EVETPCC_IPR_I12_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I12_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I29_MASK                                (0x20000000U)
#define CSL_EVETPCC_IPR_I29_SHIFT                               (29U)
#define CSL_EVETPCC_IPR_I29_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I29_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_IPR_I6_SHIFT                                (6U)
#define CSL_EVETPCC_IPR_I6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I26_MASK                                (0x04000000U)
#define CSL_EVETPCC_IPR_I26_SHIFT                               (26U)
#define CSL_EVETPCC_IPR_I26_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I26_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_IPR_I5_SHIFT                                (5U)
#define CSL_EVETPCC_IPR_I5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_IPR_I4_SHIFT                                (4U)
#define CSL_EVETPCC_IPR_I4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I16_MASK                                (0x00010000U)
#define CSL_EVETPCC_IPR_I16_SHIFT                               (16U)
#define CSL_EVETPCC_IPR_I16_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I16_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I23_MASK                                (0x00800000U)
#define CSL_EVETPCC_IPR_I23_SHIFT                               (23U)
#define CSL_EVETPCC_IPR_I23_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I23_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_IPR_I7_SHIFT                                (7U)
#define CSL_EVETPCC_IPR_I7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I22_MASK                                (0x00400000U)
#define CSL_EVETPCC_IPR_I22_SHIFT                               (22U)
#define CSL_EVETPCC_IPR_I22_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I22_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I25_MASK                                (0x02000000U)
#define CSL_EVETPCC_IPR_I25_SHIFT                               (25U)
#define CSL_EVETPCC_IPR_I25_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I25_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I24_MASK                                (0x01000000U)
#define CSL_EVETPCC_IPR_I24_SHIFT                               (24U)
#define CSL_EVETPCC_IPR_I24_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I24_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I19_MASK                                (0x00080000U)
#define CSL_EVETPCC_IPR_I19_SHIFT                               (19U)
#define CSL_EVETPCC_IPR_I19_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I19_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I30_MASK                                (0x40000000U)
#define CSL_EVETPCC_IPR_I30_SHIFT                               (30U)
#define CSL_EVETPCC_IPR_I30_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I30_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I11_MASK                                (0x00000800U)
#define CSL_EVETPCC_IPR_I11_SHIFT                               (11U)
#define CSL_EVETPCC_IPR_I11_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I11_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I18_MASK                                (0x00040000U)
#define CSL_EVETPCC_IPR_I18_SHIFT                               (18U)
#define CSL_EVETPCC_IPR_I18_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I18_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I31_MASK                                (0x80000000U)
#define CSL_EVETPCC_IPR_I31_SHIFT                               (31U)
#define CSL_EVETPCC_IPR_I31_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I31_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I10_MASK                                (0x00000400U)
#define CSL_EVETPCC_IPR_I10_SHIFT                               (10U)
#define CSL_EVETPCC_IPR_I10_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I10_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I9_MASK                                 (0x00000200U)
#define CSL_EVETPCC_IPR_I9_SHIFT                                (9U)
#define CSL_EVETPCC_IPR_I9_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I9_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I21_MASK                                (0x00200000U)
#define CSL_EVETPCC_IPR_I21_SHIFT                               (21U)
#define CSL_EVETPCC_IPR_I21_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I21_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_I8_MASK                                 (0x00000100U)
#define CSL_EVETPCC_IPR_I8_SHIFT                                (8U)
#define CSL_EVETPCC_IPR_I8_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_IPR_I8_MAX                                  (0x00000001U)

#define CSL_EVETPCC_IPR_I20_MASK                                (0x00100000U)
#define CSL_EVETPCC_IPR_I20_SHIFT                               (20U)
#define CSL_EVETPCC_IPR_I20_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_IPR_I20_MAX                                 (0x00000001U)

#define CSL_EVETPCC_IPR_RESETVAL                                (0x00000000U)

/* IPRH */

#define CSL_EVETPCC_IPRH_I53_MASK                               (0x00200000U)
#define CSL_EVETPCC_IPRH_I53_SHIFT                              (21U)
#define CSL_EVETPCC_IPRH_I53_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I53_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I41_MASK                               (0x00000200U)
#define CSL_EVETPCC_IPRH_I41_SHIFT                              (9U)
#define CSL_EVETPCC_IPRH_I41_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I41_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I52_MASK                               (0x00100000U)
#define CSL_EVETPCC_IPRH_I52_SHIFT                              (20U)
#define CSL_EVETPCC_IPRH_I52_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I52_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I40_MASK                               (0x00000100U)
#define CSL_EVETPCC_IPRH_I40_SHIFT                              (8U)
#define CSL_EVETPCC_IPRH_I40_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I40_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I51_MASK                               (0x00080000U)
#define CSL_EVETPCC_IPRH_I51_SHIFT                              (19U)
#define CSL_EVETPCC_IPRH_I51_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I51_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I39_MASK                               (0x00000080U)
#define CSL_EVETPCC_IPRH_I39_SHIFT                              (7U)
#define CSL_EVETPCC_IPRH_I39_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I39_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I32_MASK                               (0x00000001U)
#define CSL_EVETPCC_IPRH_I32_SHIFT                              (0U)
#define CSL_EVETPCC_IPRH_I32_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I32_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I50_MASK                               (0x00040000U)
#define CSL_EVETPCC_IPRH_I50_SHIFT                              (18U)
#define CSL_EVETPCC_IPRH_I50_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I50_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I33_MASK                               (0x00000002U)
#define CSL_EVETPCC_IPRH_I33_SHIFT                              (1U)
#define CSL_EVETPCC_IPRH_I33_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I33_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I34_MASK                               (0x00000004U)
#define CSL_EVETPCC_IPRH_I34_SHIFT                              (2U)
#define CSL_EVETPCC_IPRH_I34_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I34_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I49_MASK                               (0x00020000U)
#define CSL_EVETPCC_IPRH_I49_SHIFT                              (17U)
#define CSL_EVETPCC_IPRH_I49_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I49_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I60_MASK                               (0x10000000U)
#define CSL_EVETPCC_IPRH_I60_SHIFT                              (28U)
#define CSL_EVETPCC_IPRH_I60_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I60_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I47_MASK                               (0x00008000U)
#define CSL_EVETPCC_IPRH_I47_SHIFT                              (15U)
#define CSL_EVETPCC_IPRH_I47_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I47_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I35_MASK                               (0x00000008U)
#define CSL_EVETPCC_IPRH_I35_SHIFT                              (3U)
#define CSL_EVETPCC_IPRH_I35_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I35_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I36_MASK                               (0x00000010U)
#define CSL_EVETPCC_IPRH_I36_SHIFT                              (4U)
#define CSL_EVETPCC_IPRH_I36_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I36_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I59_MASK                               (0x08000000U)
#define CSL_EVETPCC_IPRH_I59_SHIFT                              (27U)
#define CSL_EVETPCC_IPRH_I59_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I59_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I48_MASK                               (0x00010000U)
#define CSL_EVETPCC_IPRH_I48_SHIFT                              (16U)
#define CSL_EVETPCC_IPRH_I48_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I48_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I37_MASK                               (0x00000020U)
#define CSL_EVETPCC_IPRH_I37_SHIFT                              (5U)
#define CSL_EVETPCC_IPRH_I37_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I37_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I61_MASK                               (0x20000000U)
#define CSL_EVETPCC_IPRH_I61_SHIFT                              (29U)
#define CSL_EVETPCC_IPRH_I61_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I61_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I38_MASK                               (0x00000040U)
#define CSL_EVETPCC_IPRH_I38_SHIFT                              (6U)
#define CSL_EVETPCC_IPRH_I38_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I38_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I58_MASK                               (0x04000000U)
#define CSL_EVETPCC_IPRH_I58_SHIFT                              (26U)
#define CSL_EVETPCC_IPRH_I58_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I58_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I46_MASK                               (0x00004000U)
#define CSL_EVETPCC_IPRH_I46_SHIFT                              (14U)
#define CSL_EVETPCC_IPRH_I46_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I46_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I45_MASK                               (0x00002000U)
#define CSL_EVETPCC_IPRH_I45_SHIFT                              (13U)
#define CSL_EVETPCC_IPRH_I45_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I45_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I57_MASK                               (0x02000000U)
#define CSL_EVETPCC_IPRH_I57_SHIFT                              (25U)
#define CSL_EVETPCC_IPRH_I57_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I57_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I44_MASK                               (0x00001000U)
#define CSL_EVETPCC_IPRH_I44_SHIFT                              (12U)
#define CSL_EVETPCC_IPRH_I44_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I44_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I56_MASK                               (0x01000000U)
#define CSL_EVETPCC_IPRH_I56_SHIFT                              (24U)
#define CSL_EVETPCC_IPRH_I56_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I56_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I63_MASK                               (0x80000000U)
#define CSL_EVETPCC_IPRH_I63_SHIFT                              (31U)
#define CSL_EVETPCC_IPRH_I63_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I63_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I43_MASK                               (0x00000800U)
#define CSL_EVETPCC_IPRH_I43_SHIFT                              (11U)
#define CSL_EVETPCC_IPRH_I43_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I43_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I55_MASK                               (0x00800000U)
#define CSL_EVETPCC_IPRH_I55_SHIFT                              (23U)
#define CSL_EVETPCC_IPRH_I55_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I55_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I62_MASK                               (0x40000000U)
#define CSL_EVETPCC_IPRH_I62_SHIFT                              (30U)
#define CSL_EVETPCC_IPRH_I62_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I62_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I42_MASK                               (0x00000400U)
#define CSL_EVETPCC_IPRH_I42_SHIFT                              (10U)
#define CSL_EVETPCC_IPRH_I42_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I42_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_I54_MASK                               (0x00400000U)
#define CSL_EVETPCC_IPRH_I54_SHIFT                              (22U)
#define CSL_EVETPCC_IPRH_I54_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_IPRH_I54_MAX                                (0x00000001U)

#define CSL_EVETPCC_IPRH_RESETVAL                               (0x00000000U)

/* ICR */

#define CSL_EVETPCC_ICR_I17_MASK                                (0x00020000U)
#define CSL_EVETPCC_ICR_I17_SHIFT                               (17U)
#define CSL_EVETPCC_ICR_I17_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I17_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I30_MASK                                (0x40000000U)
#define CSL_EVETPCC_ICR_I30_SHIFT                               (30U)
#define CSL_EVETPCC_ICR_I30_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I30_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_ICR_I7_SHIFT                                (7U)
#define CSL_EVETPCC_ICR_I7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I19_MASK                                (0x00080000U)
#define CSL_EVETPCC_ICR_I19_SHIFT                               (19U)
#define CSL_EVETPCC_ICR_I19_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I19_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I16_MASK                                (0x00010000U)
#define CSL_EVETPCC_ICR_I16_SHIFT                               (16U)
#define CSL_EVETPCC_ICR_I16_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I16_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_ICR_I6_SHIFT                                (6U)
#define CSL_EVETPCC_ICR_I6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I31_MASK                                (0x80000000U)
#define CSL_EVETPCC_ICR_I31_SHIFT                               (31U)
#define CSL_EVETPCC_ICR_I31_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I31_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I20_MASK                                (0x00100000U)
#define CSL_EVETPCC_ICR_I20_SHIFT                               (20U)
#define CSL_EVETPCC_ICR_I20_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I20_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I18_MASK                                (0x00040000U)
#define CSL_EVETPCC_ICR_I18_SHIFT                               (18U)
#define CSL_EVETPCC_ICR_I18_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I18_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I21_MASK                                (0x00200000U)
#define CSL_EVETPCC_ICR_I21_SHIFT                               (21U)
#define CSL_EVETPCC_ICR_I21_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I21_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I8_MASK                                 (0x00000100U)
#define CSL_EVETPCC_ICR_I8_SHIFT                                (8U)
#define CSL_EVETPCC_ICR_I8_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I8_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I22_MASK                                (0x00400000U)
#define CSL_EVETPCC_ICR_I22_SHIFT                               (22U)
#define CSL_EVETPCC_ICR_I22_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I22_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I13_MASK                                (0x00002000U)
#define CSL_EVETPCC_ICR_I13_SHIFT                               (13U)
#define CSL_EVETPCC_ICR_I13_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I13_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_ICR_I3_SHIFT                                (3U)
#define CSL_EVETPCC_ICR_I3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I23_MASK                                (0x00800000U)
#define CSL_EVETPCC_ICR_I23_SHIFT                               (23U)
#define CSL_EVETPCC_ICR_I23_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I23_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I12_MASK                                (0x00001000U)
#define CSL_EVETPCC_ICR_I12_SHIFT                               (12U)
#define CSL_EVETPCC_ICR_I12_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I12_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_ICR_I2_SHIFT                                (2U)
#define CSL_EVETPCC_ICR_I2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I24_MASK                                (0x01000000U)
#define CSL_EVETPCC_ICR_I24_SHIFT                               (24U)
#define CSL_EVETPCC_ICR_I24_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I24_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I15_MASK                                (0x00008000U)
#define CSL_EVETPCC_ICR_I15_SHIFT                               (15U)
#define CSL_EVETPCC_ICR_I15_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I15_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I25_MASK                                (0x02000000U)
#define CSL_EVETPCC_ICR_I25_SHIFT                               (25U)
#define CSL_EVETPCC_ICR_I25_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I25_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_ICR_I5_SHIFT                                (5U)
#define CSL_EVETPCC_ICR_I5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I14_MASK                                (0x00004000U)
#define CSL_EVETPCC_ICR_I14_SHIFT                               (14U)
#define CSL_EVETPCC_ICR_I14_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I14_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_ICR_I4_SHIFT                                (4U)
#define CSL_EVETPCC_ICR_I4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I9_MASK                                 (0x00000200U)
#define CSL_EVETPCC_ICR_I9_SHIFT                                (9U)
#define CSL_EVETPCC_ICR_I9_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I9_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I27_MASK                                (0x08000000U)
#define CSL_EVETPCC_ICR_I27_SHIFT                               (27U)
#define CSL_EVETPCC_ICR_I27_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I27_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I26_MASK                                (0x04000000U)
#define CSL_EVETPCC_ICR_I26_SHIFT                               (26U)
#define CSL_EVETPCC_ICR_I26_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I26_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I11_MASK                                (0x00000800U)
#define CSL_EVETPCC_ICR_I11_SHIFT                               (11U)
#define CSL_EVETPCC_ICR_I11_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I11_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_ICR_I1_SHIFT                                (1U)
#define CSL_EVETPCC_ICR_I1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I10_MASK                                (0x00000400U)
#define CSL_EVETPCC_ICR_I10_SHIFT                               (10U)
#define CSL_EVETPCC_ICR_I10_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I10_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I28_MASK                                (0x10000000U)
#define CSL_EVETPCC_ICR_I28_SHIFT                               (28U)
#define CSL_EVETPCC_ICR_I28_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I28_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_I0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_ICR_I0_SHIFT                                (0U)
#define CSL_EVETPCC_ICR_I0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_ICR_I0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_ICR_I29_MASK                                (0x20000000U)
#define CSL_EVETPCC_ICR_I29_SHIFT                               (29U)
#define CSL_EVETPCC_ICR_I29_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_ICR_I29_MAX                                 (0x00000001U)

#define CSL_EVETPCC_ICR_RESETVAL                                (0x00000000U)

/* ICRH */

#define CSL_EVETPCC_ICRH_I37_MASK                               (0x00000020U)
#define CSL_EVETPCC_ICRH_I37_SHIFT                              (5U)
#define CSL_EVETPCC_ICRH_I37_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I37_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I47_MASK                               (0x00008000U)
#define CSL_EVETPCC_ICRH_I47_SHIFT                              (15U)
#define CSL_EVETPCC_ICRH_I47_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I47_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I53_MASK                               (0x00200000U)
#define CSL_EVETPCC_ICRH_I53_SHIFT                              (21U)
#define CSL_EVETPCC_ICRH_I53_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I53_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I36_MASK                               (0x00000010U)
#define CSL_EVETPCC_ICRH_I36_SHIFT                              (4U)
#define CSL_EVETPCC_ICRH_I36_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I36_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I63_MASK                               (0x80000000U)
#define CSL_EVETPCC_ICRH_I63_SHIFT                              (31U)
#define CSL_EVETPCC_ICRH_I63_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I63_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I46_MASK                               (0x00004000U)
#define CSL_EVETPCC_ICRH_I46_SHIFT                              (14U)
#define CSL_EVETPCC_ICRH_I46_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I46_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I39_MASK                               (0x00000080U)
#define CSL_EVETPCC_ICRH_I39_SHIFT                              (7U)
#define CSL_EVETPCC_ICRH_I39_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I39_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I49_MASK                               (0x00020000U)
#define CSL_EVETPCC_ICRH_I49_SHIFT                              (17U)
#define CSL_EVETPCC_ICRH_I49_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I49_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I38_MASK                               (0x00000040U)
#define CSL_EVETPCC_ICRH_I38_SHIFT                              (6U)
#define CSL_EVETPCC_ICRH_I38_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I38_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I48_MASK                               (0x00010000U)
#define CSL_EVETPCC_ICRH_I48_SHIFT                              (16U)
#define CSL_EVETPCC_ICRH_I48_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I48_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I41_MASK                               (0x00000200U)
#define CSL_EVETPCC_ICRH_I41_SHIFT                              (9U)
#define CSL_EVETPCC_ICRH_I41_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I41_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I51_MASK                               (0x00080000U)
#define CSL_EVETPCC_ICRH_I51_SHIFT                              (19U)
#define CSL_EVETPCC_ICRH_I51_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I51_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I40_MASK                               (0x00000100U)
#define CSL_EVETPCC_ICRH_I40_SHIFT                              (8U)
#define CSL_EVETPCC_ICRH_I40_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I40_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I50_MASK                               (0x00040000U)
#define CSL_EVETPCC_ICRH_I50_SHIFT                              (18U)
#define CSL_EVETPCC_ICRH_I50_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I50_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I42_MASK                               (0x00000400U)
#define CSL_EVETPCC_ICRH_I42_SHIFT                              (10U)
#define CSL_EVETPCC_ICRH_I42_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I42_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I62_MASK                               (0x40000000U)
#define CSL_EVETPCC_ICRH_I62_SHIFT                              (30U)
#define CSL_EVETPCC_ICRH_I62_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I62_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I52_MASK                               (0x00100000U)
#define CSL_EVETPCC_ICRH_I52_SHIFT                              (20U)
#define CSL_EVETPCC_ICRH_I52_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I52_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I61_MASK                               (0x20000000U)
#define CSL_EVETPCC_ICRH_I61_SHIFT                              (29U)
#define CSL_EVETPCC_ICRH_I61_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I61_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I32_MASK                               (0x00000001U)
#define CSL_EVETPCC_ICRH_I32_SHIFT                              (0U)
#define CSL_EVETPCC_ICRH_I32_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I32_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I60_MASK                               (0x10000000U)
#define CSL_EVETPCC_ICRH_I60_SHIFT                              (28U)
#define CSL_EVETPCC_ICRH_I60_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I60_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I59_MASK                               (0x08000000U)
#define CSL_EVETPCC_ICRH_I59_SHIFT                              (27U)
#define CSL_EVETPCC_ICRH_I59_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I59_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I58_MASK                               (0x04000000U)
#define CSL_EVETPCC_ICRH_I58_SHIFT                              (26U)
#define CSL_EVETPCC_ICRH_I58_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I58_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I57_MASK                               (0x02000000U)
#define CSL_EVETPCC_ICRH_I57_SHIFT                              (25U)
#define CSL_EVETPCC_ICRH_I57_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I57_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I33_MASK                               (0x00000002U)
#define CSL_EVETPCC_ICRH_I33_SHIFT                              (1U)
#define CSL_EVETPCC_ICRH_I33_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I33_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I43_MASK                               (0x00000800U)
#define CSL_EVETPCC_ICRH_I43_SHIFT                              (11U)
#define CSL_EVETPCC_ICRH_I43_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I43_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I56_MASK                               (0x01000000U)
#define CSL_EVETPCC_ICRH_I56_SHIFT                              (24U)
#define CSL_EVETPCC_ICRH_I56_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I56_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I35_MASK                               (0x00000008U)
#define CSL_EVETPCC_ICRH_I35_SHIFT                              (3U)
#define CSL_EVETPCC_ICRH_I35_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I35_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I55_MASK                               (0x00800000U)
#define CSL_EVETPCC_ICRH_I55_SHIFT                              (23U)
#define CSL_EVETPCC_ICRH_I55_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I55_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I45_MASK                               (0x00002000U)
#define CSL_EVETPCC_ICRH_I45_SHIFT                              (13U)
#define CSL_EVETPCC_ICRH_I45_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I45_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I34_MASK                               (0x00000004U)
#define CSL_EVETPCC_ICRH_I34_SHIFT                              (2U)
#define CSL_EVETPCC_ICRH_I34_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I34_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I54_MASK                               (0x00400000U)
#define CSL_EVETPCC_ICRH_I54_SHIFT                              (22U)
#define CSL_EVETPCC_ICRH_I54_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I54_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_I44_MASK                               (0x00001000U)
#define CSL_EVETPCC_ICRH_I44_SHIFT                              (12U)
#define CSL_EVETPCC_ICRH_I44_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ICRH_I44_MAX                                (0x00000001U)

#define CSL_EVETPCC_ICRH_RESETVAL                               (0x00000000U)

/* IEVAL */

#define CSL_EVETPCC_IEVAL_SET_MASK                              (0x00000002U)
#define CSL_EVETPCC_IEVAL_SET_SHIFT                             (1U)
#define CSL_EVETPCC_IEVAL_SET_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IEVAL_SET_MAX                               (0x00000001U)

#define CSL_EVETPCC_IEVAL_EVAL_MASK                             (0x00000001U)
#define CSL_EVETPCC_IEVAL_EVAL_SHIFT                            (0U)
#define CSL_EVETPCC_IEVAL_EVAL_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IEVAL_EVAL_MAX                              (0x00000001U)

#define CSL_EVETPCC_IEVAL_RESETVAL                              (0x00000000U)

/* QER */

#define CSL_EVETPCC_QER_E7_MASK                                 (0x00000080U)
#define CSL_EVETPCC_QER_E7_SHIFT                                (7U)
#define CSL_EVETPCC_QER_E7_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_QER_E7_MAX                                  (0x00000001U)

#define CSL_EVETPCC_QER_E6_MASK                                 (0x00000040U)
#define CSL_EVETPCC_QER_E6_SHIFT                                (6U)
#define CSL_EVETPCC_QER_E6_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_QER_E6_MAX                                  (0x00000001U)

#define CSL_EVETPCC_QER_E5_MASK                                 (0x00000020U)
#define CSL_EVETPCC_QER_E5_SHIFT                                (5U)
#define CSL_EVETPCC_QER_E5_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_QER_E5_MAX                                  (0x00000001U)

#define CSL_EVETPCC_QER_E3_MASK                                 (0x00000008U)
#define CSL_EVETPCC_QER_E3_SHIFT                                (3U)
#define CSL_EVETPCC_QER_E3_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_QER_E3_MAX                                  (0x00000001U)

#define CSL_EVETPCC_QER_E4_MASK                                 (0x00000010U)
#define CSL_EVETPCC_QER_E4_SHIFT                                (4U)
#define CSL_EVETPCC_QER_E4_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_QER_E4_MAX                                  (0x00000001U)

#define CSL_EVETPCC_QER_E1_MASK                                 (0x00000002U)
#define CSL_EVETPCC_QER_E1_SHIFT                                (1U)
#define CSL_EVETPCC_QER_E1_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_QER_E1_MAX                                  (0x00000001U)

#define CSL_EVETPCC_QER_E2_MASK                                 (0x00000004U)
#define CSL_EVETPCC_QER_E2_SHIFT                                (2U)
#define CSL_EVETPCC_QER_E2_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_QER_E2_MAX                                  (0x00000001U)

#define CSL_EVETPCC_QER_E0_MASK                                 (0x00000001U)
#define CSL_EVETPCC_QER_E0_SHIFT                                (0U)
#define CSL_EVETPCC_QER_E0_RESETVAL                             (0x00000000U)
#define CSL_EVETPCC_QER_E0_MAX                                  (0x00000001U)

#define CSL_EVETPCC_QER_RESETVAL                                (0x00000000U)

/* QEER */

#define CSL_EVETPCC_QEER_E6_MASK                                (0x00000040U)
#define CSL_EVETPCC_QEER_E6_SHIFT                               (6U)
#define CSL_EVETPCC_QEER_E6_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEER_E6_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEER_E5_MASK                                (0x00000020U)
#define CSL_EVETPCC_QEER_E5_SHIFT                               (5U)
#define CSL_EVETPCC_QEER_E5_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEER_E5_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEER_E7_MASK                                (0x00000080U)
#define CSL_EVETPCC_QEER_E7_SHIFT                               (7U)
#define CSL_EVETPCC_QEER_E7_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEER_E7_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEER_E0_MASK                                (0x00000001U)
#define CSL_EVETPCC_QEER_E0_SHIFT                               (0U)
#define CSL_EVETPCC_QEER_E0_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEER_E0_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEER_E2_MASK                                (0x00000004U)
#define CSL_EVETPCC_QEER_E2_SHIFT                               (2U)
#define CSL_EVETPCC_QEER_E2_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEER_E2_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEER_E1_MASK                                (0x00000002U)
#define CSL_EVETPCC_QEER_E1_SHIFT                               (1U)
#define CSL_EVETPCC_QEER_E1_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEER_E1_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEER_E4_MASK                                (0x00000010U)
#define CSL_EVETPCC_QEER_E4_SHIFT                               (4U)
#define CSL_EVETPCC_QEER_E4_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEER_E4_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEER_E3_MASK                                (0x00000008U)
#define CSL_EVETPCC_QEER_E3_SHIFT                               (3U)
#define CSL_EVETPCC_QEER_E3_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QEER_E3_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QEER_RESETVAL                               (0x00000000U)

/* QEECR */

#define CSL_EVETPCC_QEECR_E3_MASK                               (0x00000008U)
#define CSL_EVETPCC_QEECR_E3_SHIFT                              (3U)
#define CSL_EVETPCC_QEECR_E3_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEECR_E3_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEECR_E2_MASK                               (0x00000004U)
#define CSL_EVETPCC_QEECR_E2_SHIFT                              (2U)
#define CSL_EVETPCC_QEECR_E2_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEECR_E2_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEECR_E1_MASK                               (0x00000002U)
#define CSL_EVETPCC_QEECR_E1_SHIFT                              (1U)
#define CSL_EVETPCC_QEECR_E1_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEECR_E1_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEECR_E4_MASK                               (0x00000010U)
#define CSL_EVETPCC_QEECR_E4_SHIFT                              (4U)
#define CSL_EVETPCC_QEECR_E4_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEECR_E4_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEECR_E0_MASK                               (0x00000001U)
#define CSL_EVETPCC_QEECR_E0_SHIFT                              (0U)
#define CSL_EVETPCC_QEECR_E0_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEECR_E0_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEECR_E6_MASK                               (0x00000040U)
#define CSL_EVETPCC_QEECR_E6_SHIFT                              (6U)
#define CSL_EVETPCC_QEECR_E6_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEECR_E6_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEECR_E5_MASK                               (0x00000020U)
#define CSL_EVETPCC_QEECR_E5_SHIFT                              (5U)
#define CSL_EVETPCC_QEECR_E5_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEECR_E5_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEECR_E7_MASK                               (0x00000080U)
#define CSL_EVETPCC_QEECR_E7_SHIFT                              (7U)
#define CSL_EVETPCC_QEECR_E7_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEECR_E7_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEECR_RESETVAL                              (0x00000000U)

/* QEESR */

#define CSL_EVETPCC_QEESR_E5_MASK                               (0x00000020U)
#define CSL_EVETPCC_QEESR_E5_SHIFT                              (5U)
#define CSL_EVETPCC_QEESR_E5_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEESR_E5_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEESR_E3_MASK                               (0x00000008U)
#define CSL_EVETPCC_QEESR_E3_SHIFT                              (3U)
#define CSL_EVETPCC_QEESR_E3_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEESR_E3_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEESR_E6_MASK                               (0x00000040U)
#define CSL_EVETPCC_QEESR_E6_SHIFT                              (6U)
#define CSL_EVETPCC_QEESR_E6_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEESR_E6_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEESR_E4_MASK                               (0x00000010U)
#define CSL_EVETPCC_QEESR_E4_SHIFT                              (4U)
#define CSL_EVETPCC_QEESR_E4_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEESR_E4_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEESR_E1_MASK                               (0x00000002U)
#define CSL_EVETPCC_QEESR_E1_SHIFT                              (1U)
#define CSL_EVETPCC_QEESR_E1_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEESR_E1_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEESR_E2_MASK                               (0x00000004U)
#define CSL_EVETPCC_QEESR_E2_SHIFT                              (2U)
#define CSL_EVETPCC_QEESR_E2_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEESR_E2_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEESR_E0_MASK                               (0x00000001U)
#define CSL_EVETPCC_QEESR_E0_SHIFT                              (0U)
#define CSL_EVETPCC_QEESR_E0_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEESR_E0_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEESR_E7_MASK                               (0x00000080U)
#define CSL_EVETPCC_QEESR_E7_SHIFT                              (7U)
#define CSL_EVETPCC_QEESR_E7_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QEESR_E7_MAX                                (0x00000001U)

#define CSL_EVETPCC_QEESR_RESETVAL                              (0x00000000U)

/* QSER */

#define CSL_EVETPCC_QSER_E4_MASK                                (0x00000010U)
#define CSL_EVETPCC_QSER_E4_SHIFT                               (4U)
#define CSL_EVETPCC_QSER_E4_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QSER_E4_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QSER_E3_MASK                                (0x00000008U)
#define CSL_EVETPCC_QSER_E3_SHIFT                               (3U)
#define CSL_EVETPCC_QSER_E3_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QSER_E3_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QSER_E2_MASK                                (0x00000004U)
#define CSL_EVETPCC_QSER_E2_SHIFT                               (2U)
#define CSL_EVETPCC_QSER_E2_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QSER_E2_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QSER_E1_MASK                                (0x00000002U)
#define CSL_EVETPCC_QSER_E1_SHIFT                               (1U)
#define CSL_EVETPCC_QSER_E1_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QSER_E1_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QSER_E0_MASK                                (0x00000001U)
#define CSL_EVETPCC_QSER_E0_SHIFT                               (0U)
#define CSL_EVETPCC_QSER_E0_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QSER_E0_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QSER_E7_MASK                                (0x00000080U)
#define CSL_EVETPCC_QSER_E7_SHIFT                               (7U)
#define CSL_EVETPCC_QSER_E7_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QSER_E7_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QSER_E5_MASK                                (0x00000020U)
#define CSL_EVETPCC_QSER_E5_SHIFT                               (5U)
#define CSL_EVETPCC_QSER_E5_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QSER_E5_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QSER_E6_MASK                                (0x00000040U)
#define CSL_EVETPCC_QSER_E6_SHIFT                               (6U)
#define CSL_EVETPCC_QSER_E6_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_QSER_E6_MAX                                 (0x00000001U)

#define CSL_EVETPCC_QSER_RESETVAL                               (0x00000000U)

/* QSECR */

#define CSL_EVETPCC_QSECR_E5_MASK                               (0x00000020U)
#define CSL_EVETPCC_QSECR_E5_SHIFT                              (5U)
#define CSL_EVETPCC_QSECR_E5_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QSECR_E5_MAX                                (0x00000001U)

#define CSL_EVETPCC_QSECR_E6_MASK                               (0x00000040U)
#define CSL_EVETPCC_QSECR_E6_SHIFT                              (6U)
#define CSL_EVETPCC_QSECR_E6_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QSECR_E6_MAX                                (0x00000001U)

#define CSL_EVETPCC_QSECR_E7_MASK                               (0x00000080U)
#define CSL_EVETPCC_QSECR_E7_SHIFT                              (7U)
#define CSL_EVETPCC_QSECR_E7_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QSECR_E7_MAX                                (0x00000001U)

#define CSL_EVETPCC_QSECR_E0_MASK                               (0x00000001U)
#define CSL_EVETPCC_QSECR_E0_SHIFT                              (0U)
#define CSL_EVETPCC_QSECR_E0_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QSECR_E0_MAX                                (0x00000001U)

#define CSL_EVETPCC_QSECR_E2_MASK                               (0x00000004U)
#define CSL_EVETPCC_QSECR_E2_SHIFT                              (2U)
#define CSL_EVETPCC_QSECR_E2_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QSECR_E2_MAX                                (0x00000001U)

#define CSL_EVETPCC_QSECR_E1_MASK                               (0x00000002U)
#define CSL_EVETPCC_QSECR_E1_SHIFT                              (1U)
#define CSL_EVETPCC_QSECR_E1_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QSECR_E1_MAX                                (0x00000001U)

#define CSL_EVETPCC_QSECR_E4_MASK                               (0x00000010U)
#define CSL_EVETPCC_QSECR_E4_SHIFT                              (4U)
#define CSL_EVETPCC_QSECR_E4_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QSECR_E4_MAX                                (0x00000001U)

#define CSL_EVETPCC_QSECR_E3_MASK                               (0x00000008U)
#define CSL_EVETPCC_QSECR_E3_SHIFT                              (3U)
#define CSL_EVETPCC_QSECR_E3_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_QSECR_E3_MAX                                (0x00000001U)

#define CSL_EVETPCC_QSECR_RESETVAL                              (0x00000000U)

/* IEVAL_RN */

#define CSL_EVETPCC_IEVAL_RN_SET_MASK                           (0x00000002U)
#define CSL_EVETPCC_IEVAL_RN_SET_SHIFT                          (1U)
#define CSL_EVETPCC_IEVAL_RN_SET_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IEVAL_RN_SET_MAX                            (0x00000001U)

#define CSL_EVETPCC_IEVAL_RN_EVAL_MASK                          (0x00000001U)
#define CSL_EVETPCC_IEVAL_RN_EVAL_SHIFT                         (0U)
#define CSL_EVETPCC_IEVAL_RN_EVAL_RESETVAL                      (0x00000000U)
#define CSL_EVETPCC_IEVAL_RN_EVAL_MAX                           (0x00000001U)

#define CSL_EVETPCC_IEVAL_RN_RESETVAL                           (0x00000000U)

/* IESRH_RN */

#define CSL_EVETPCC_IESRH_RN_I52_MASK                           (0x00100000U)
#define CSL_EVETPCC_IESRH_RN_I52_SHIFT                          (20U)
#define CSL_EVETPCC_IESRH_RN_I52_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I52_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I41_MASK                           (0x00000200U)
#define CSL_EVETPCC_IESRH_RN_I41_SHIFT                          (9U)
#define CSL_EVETPCC_IESRH_RN_I41_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I41_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I53_MASK                           (0x00200000U)
#define CSL_EVETPCC_IESRH_RN_I53_SHIFT                          (21U)
#define CSL_EVETPCC_IESRH_RN_I53_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I53_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I42_MASK                           (0x00000400U)
#define CSL_EVETPCC_IESRH_RN_I42_SHIFT                          (10U)
#define CSL_EVETPCC_IESRH_RN_I42_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I42_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I54_MASK                           (0x00400000U)
#define CSL_EVETPCC_IESRH_RN_I54_SHIFT                          (22U)
#define CSL_EVETPCC_IESRH_RN_I54_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I54_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I43_MASK                           (0x00000800U)
#define CSL_EVETPCC_IESRH_RN_I43_SHIFT                          (11U)
#define CSL_EVETPCC_IESRH_RN_I43_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I43_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I55_MASK                           (0x00800000U)
#define CSL_EVETPCC_IESRH_RN_I55_SHIFT                          (23U)
#define CSL_EVETPCC_IESRH_RN_I55_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I55_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I44_MASK                           (0x00001000U)
#define CSL_EVETPCC_IESRH_RN_I44_SHIFT                          (12U)
#define CSL_EVETPCC_IESRH_RN_I44_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I44_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I33_MASK                           (0x00000002U)
#define CSL_EVETPCC_IESRH_RN_I33_SHIFT                          (1U)
#define CSL_EVETPCC_IESRH_RN_I33_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I33_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I56_MASK                           (0x01000000U)
#define CSL_EVETPCC_IESRH_RN_I56_SHIFT                          (24U)
#define CSL_EVETPCC_IESRH_RN_I56_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I56_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I45_MASK                           (0x00002000U)
#define CSL_EVETPCC_IESRH_RN_I45_SHIFT                          (13U)
#define CSL_EVETPCC_IESRH_RN_I45_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I45_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I57_MASK                           (0x02000000U)
#define CSL_EVETPCC_IESRH_RN_I57_SHIFT                          (25U)
#define CSL_EVETPCC_IESRH_RN_I57_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I57_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I32_MASK                           (0x00000001U)
#define CSL_EVETPCC_IESRH_RN_I32_SHIFT                          (0U)
#define CSL_EVETPCC_IESRH_RN_I32_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I32_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I46_MASK                           (0x00004000U)
#define CSL_EVETPCC_IESRH_RN_I46_SHIFT                          (14U)
#define CSL_EVETPCC_IESRH_RN_I46_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I46_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I35_MASK                           (0x00000008U)
#define CSL_EVETPCC_IESRH_RN_I35_SHIFT                          (3U)
#define CSL_EVETPCC_IESRH_RN_I35_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I35_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I58_MASK                           (0x04000000U)
#define CSL_EVETPCC_IESRH_RN_I58_SHIFT                          (26U)
#define CSL_EVETPCC_IESRH_RN_I58_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I58_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I47_MASK                           (0x00008000U)
#define CSL_EVETPCC_IESRH_RN_I47_SHIFT                          (15U)
#define CSL_EVETPCC_IESRH_RN_I47_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I47_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I34_MASK                           (0x00000004U)
#define CSL_EVETPCC_IESRH_RN_I34_SHIFT                          (2U)
#define CSL_EVETPCC_IESRH_RN_I34_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I34_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I59_MASK                           (0x08000000U)
#define CSL_EVETPCC_IESRH_RN_I59_SHIFT                          (27U)
#define CSL_EVETPCC_IESRH_RN_I59_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I59_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I48_MASK                           (0x00010000U)
#define CSL_EVETPCC_IESRH_RN_I48_SHIFT                          (16U)
#define CSL_EVETPCC_IESRH_RN_I48_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I48_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I60_MASK                           (0x10000000U)
#define CSL_EVETPCC_IESRH_RN_I60_SHIFT                          (28U)
#define CSL_EVETPCC_IESRH_RN_I60_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I60_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I37_MASK                           (0x00000020U)
#define CSL_EVETPCC_IESRH_RN_I37_SHIFT                          (5U)
#define CSL_EVETPCC_IESRH_RN_I37_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I37_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I49_MASK                           (0x00020000U)
#define CSL_EVETPCC_IESRH_RN_I49_SHIFT                          (17U)
#define CSL_EVETPCC_IESRH_RN_I49_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I49_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I36_MASK                           (0x00000010U)
#define CSL_EVETPCC_IESRH_RN_I36_SHIFT                          (4U)
#define CSL_EVETPCC_IESRH_RN_I36_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I36_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I50_MASK                           (0x00040000U)
#define CSL_EVETPCC_IESRH_RN_I50_SHIFT                          (18U)
#define CSL_EVETPCC_IESRH_RN_I50_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I50_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I39_MASK                           (0x00000080U)
#define CSL_EVETPCC_IESRH_RN_I39_SHIFT                          (7U)
#define CSL_EVETPCC_IESRH_RN_I39_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I39_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I38_MASK                           (0x00000040U)
#define CSL_EVETPCC_IESRH_RN_I38_SHIFT                          (6U)
#define CSL_EVETPCC_IESRH_RN_I38_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I38_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I63_MASK                           (0x80000000U)
#define CSL_EVETPCC_IESRH_RN_I63_SHIFT                          (31U)
#define CSL_EVETPCC_IESRH_RN_I63_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I63_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I62_MASK                           (0x40000000U)
#define CSL_EVETPCC_IESRH_RN_I62_SHIFT                          (30U)
#define CSL_EVETPCC_IESRH_RN_I62_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I62_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I40_MASK                           (0x00000100U)
#define CSL_EVETPCC_IESRH_RN_I40_SHIFT                          (8U)
#define CSL_EVETPCC_IESRH_RN_I40_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I40_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I61_MASK                           (0x20000000U)
#define CSL_EVETPCC_IESRH_RN_I61_SHIFT                          (29U)
#define CSL_EVETPCC_IESRH_RN_I61_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I61_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_I51_MASK                           (0x00080000U)
#define CSL_EVETPCC_IESRH_RN_I51_SHIFT                          (19U)
#define CSL_EVETPCC_IESRH_RN_I51_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IESRH_RN_I51_MAX                            (0x00000001U)

#define CSL_EVETPCC_IESRH_RN_RESETVAL                           (0x00000000U)

/* SER_RN */

#define CSL_EVETPCC_SER_RN_E0_MASK                              (0x00000001U)
#define CSL_EVETPCC_SER_RN_E0_SHIFT                             (0U)
#define CSL_EVETPCC_SER_RN_E0_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E0_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E13_MASK                             (0x00002000U)
#define CSL_EVETPCC_SER_RN_E13_SHIFT                            (13U)
#define CSL_EVETPCC_SER_RN_E13_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E13_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E21_MASK                             (0x00200000U)
#define CSL_EVETPCC_SER_RN_E21_SHIFT                            (21U)
#define CSL_EVETPCC_SER_RN_E21_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E21_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E14_MASK                             (0x00004000U)
#define CSL_EVETPCC_SER_RN_E14_SHIFT                            (14U)
#define CSL_EVETPCC_SER_RN_E14_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E14_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E31_MASK                             (0x80000000U)
#define CSL_EVETPCC_SER_RN_E31_SHIFT                            (31U)
#define CSL_EVETPCC_SER_RN_E31_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E31_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E1_MASK                              (0x00000002U)
#define CSL_EVETPCC_SER_RN_E1_SHIFT                             (1U)
#define CSL_EVETPCC_SER_RN_E1_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E1_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E11_MASK                             (0x00000800U)
#define CSL_EVETPCC_SER_RN_E11_SHIFT                            (11U)
#define CSL_EVETPCC_SER_RN_E11_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E11_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E19_MASK                             (0x00080000U)
#define CSL_EVETPCC_SER_RN_E19_SHIFT                            (19U)
#define CSL_EVETPCC_SER_RN_E19_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E19_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E20_MASK                             (0x00100000U)
#define CSL_EVETPCC_SER_RN_E20_SHIFT                            (20U)
#define CSL_EVETPCC_SER_RN_E20_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E20_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E12_MASK                             (0x00001000U)
#define CSL_EVETPCC_SER_RN_E12_SHIFT                            (12U)
#define CSL_EVETPCC_SER_RN_E12_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E12_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E3_MASK                              (0x00000008U)
#define CSL_EVETPCC_SER_RN_E3_SHIFT                             (3U)
#define CSL_EVETPCC_SER_RN_E3_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E3_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E4_MASK                              (0x00000010U)
#define CSL_EVETPCC_SER_RN_E4_SHIFT                             (4U)
#define CSL_EVETPCC_SER_RN_E4_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E4_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E24_MASK                             (0x01000000U)
#define CSL_EVETPCC_SER_RN_E24_SHIFT                            (24U)
#define CSL_EVETPCC_SER_RN_E24_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E24_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E2_MASK                              (0x00000004U)
#define CSL_EVETPCC_SER_RN_E2_SHIFT                             (2U)
#define CSL_EVETPCC_SER_RN_E2_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E2_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E22_MASK                             (0x00400000U)
#define CSL_EVETPCC_SER_RN_E22_SHIFT                            (22U)
#define CSL_EVETPCC_SER_RN_E22_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E22_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E23_MASK                             (0x00800000U)
#define CSL_EVETPCC_SER_RN_E23_SHIFT                            (23U)
#define CSL_EVETPCC_SER_RN_E23_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E23_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E25_MASK                             (0x02000000U)
#define CSL_EVETPCC_SER_RN_E25_SHIFT                            (25U)
#define CSL_EVETPCC_SER_RN_E25_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E25_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E26_MASK                             (0x04000000U)
#define CSL_EVETPCC_SER_RN_E26_SHIFT                            (26U)
#define CSL_EVETPCC_SER_RN_E26_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E26_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E6_MASK                              (0x00000040U)
#define CSL_EVETPCC_SER_RN_E6_SHIFT                             (6U)
#define CSL_EVETPCC_SER_RN_E6_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E6_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E5_MASK                              (0x00000020U)
#define CSL_EVETPCC_SER_RN_E5_SHIFT                             (5U)
#define CSL_EVETPCC_SER_RN_E5_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E5_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E8_MASK                              (0x00000100U)
#define CSL_EVETPCC_SER_RN_E8_SHIFT                             (8U)
#define CSL_EVETPCC_SER_RN_E8_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E8_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E17_MASK                             (0x00020000U)
#define CSL_EVETPCC_SER_RN_E17_SHIFT                            (17U)
#define CSL_EVETPCC_SER_RN_E17_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E17_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E29_MASK                             (0x20000000U)
#define CSL_EVETPCC_SER_RN_E29_SHIFT                            (29U)
#define CSL_EVETPCC_SER_RN_E29_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E29_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E18_MASK                             (0x00040000U)
#define CSL_EVETPCC_SER_RN_E18_SHIFT                            (18U)
#define CSL_EVETPCC_SER_RN_E18_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E18_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E30_MASK                             (0x40000000U)
#define CSL_EVETPCC_SER_RN_E30_SHIFT                            (30U)
#define CSL_EVETPCC_SER_RN_E30_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E30_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E7_MASK                              (0x00000080U)
#define CSL_EVETPCC_SER_RN_E7_SHIFT                             (7U)
#define CSL_EVETPCC_SER_RN_E7_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E7_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E10_MASK                             (0x00000400U)
#define CSL_EVETPCC_SER_RN_E10_SHIFT                            (10U)
#define CSL_EVETPCC_SER_RN_E10_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E10_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E15_MASK                             (0x00008000U)
#define CSL_EVETPCC_SER_RN_E15_SHIFT                            (15U)
#define CSL_EVETPCC_SER_RN_E15_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E15_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E27_MASK                             (0x08000000U)
#define CSL_EVETPCC_SER_RN_E27_SHIFT                            (27U)
#define CSL_EVETPCC_SER_RN_E27_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E27_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E9_MASK                              (0x00000200U)
#define CSL_EVETPCC_SER_RN_E9_SHIFT                             (9U)
#define CSL_EVETPCC_SER_RN_E9_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_SER_RN_E9_MAX                               (0x00000001U)

#define CSL_EVETPCC_SER_RN_E16_MASK                             (0x00010000U)
#define CSL_EVETPCC_SER_RN_E16_SHIFT                            (16U)
#define CSL_EVETPCC_SER_RN_E16_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E16_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_E28_MASK                             (0x10000000U)
#define CSL_EVETPCC_SER_RN_E28_SHIFT                            (28U)
#define CSL_EVETPCC_SER_RN_E28_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SER_RN_E28_MAX                              (0x00000001U)

#define CSL_EVETPCC_SER_RN_RESETVAL                             (0x00000000U)

/* SERH_RN */

#define CSL_EVETPCC_SERH_RN_E53_MASK                            (0x00200000U)
#define CSL_EVETPCC_SERH_RN_E53_SHIFT                           (21U)
#define CSL_EVETPCC_SERH_RN_E53_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E53_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E42_MASK                            (0x00000400U)
#define CSL_EVETPCC_SERH_RN_E42_SHIFT                           (10U)
#define CSL_EVETPCC_SERH_RN_E42_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E42_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E52_MASK                            (0x00100000U)
#define CSL_EVETPCC_SERH_RN_E52_SHIFT                           (20U)
#define CSL_EVETPCC_SERH_RN_E52_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E52_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E43_MASK                            (0x00000800U)
#define CSL_EVETPCC_SERH_RN_E43_SHIFT                           (11U)
#define CSL_EVETPCC_SERH_RN_E43_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E43_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E32_MASK                            (0x00000001U)
#define CSL_EVETPCC_SERH_RN_E32_SHIFT                           (0U)
#define CSL_EVETPCC_SERH_RN_E32_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E32_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E44_MASK                            (0x00001000U)
#define CSL_EVETPCC_SERH_RN_E44_SHIFT                           (12U)
#define CSL_EVETPCC_SERH_RN_E44_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E44_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E55_MASK                            (0x00800000U)
#define CSL_EVETPCC_SERH_RN_E55_SHIFT                           (23U)
#define CSL_EVETPCC_SERH_RN_E55_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E55_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E45_MASK                            (0x00002000U)
#define CSL_EVETPCC_SERH_RN_E45_SHIFT                           (13U)
#define CSL_EVETPCC_SERH_RN_E45_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E45_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E54_MASK                            (0x00400000U)
#define CSL_EVETPCC_SERH_RN_E54_SHIFT                           (22U)
#define CSL_EVETPCC_SERH_RN_E54_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E54_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E46_MASK                            (0x00004000U)
#define CSL_EVETPCC_SERH_RN_E46_SHIFT                           (14U)
#define CSL_EVETPCC_SERH_RN_E46_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E46_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E56_MASK                            (0x01000000U)
#define CSL_EVETPCC_SERH_RN_E56_SHIFT                           (24U)
#define CSL_EVETPCC_SERH_RN_E56_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E56_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E58_MASK                            (0x04000000U)
#define CSL_EVETPCC_SERH_RN_E58_SHIFT                           (26U)
#define CSL_EVETPCC_SERH_RN_E58_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E58_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E57_MASK                            (0x02000000U)
#define CSL_EVETPCC_SERH_RN_E57_SHIFT                           (25U)
#define CSL_EVETPCC_SERH_RN_E57_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E57_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E60_MASK                            (0x10000000U)
#define CSL_EVETPCC_SERH_RN_E60_SHIFT                           (28U)
#define CSL_EVETPCC_SERH_RN_E60_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E60_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E59_MASK                            (0x08000000U)
#define CSL_EVETPCC_SERH_RN_E59_SHIFT                           (27U)
#define CSL_EVETPCC_SERH_RN_E59_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E59_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E61_MASK                            (0x20000000U)
#define CSL_EVETPCC_SERH_RN_E61_SHIFT                           (29U)
#define CSL_EVETPCC_SERH_RN_E61_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E61_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E37_MASK                            (0x00000020U)
#define CSL_EVETPCC_SERH_RN_E37_SHIFT                           (5U)
#define CSL_EVETPCC_SERH_RN_E37_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E37_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E47_MASK                            (0x00008000U)
#define CSL_EVETPCC_SERH_RN_E47_SHIFT                           (15U)
#define CSL_EVETPCC_SERH_RN_E47_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E47_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E38_MASK                            (0x00000040U)
#define CSL_EVETPCC_SERH_RN_E38_SHIFT                           (6U)
#define CSL_EVETPCC_SERH_RN_E38_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E38_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E35_MASK                            (0x00000008U)
#define CSL_EVETPCC_SERH_RN_E35_SHIFT                           (3U)
#define CSL_EVETPCC_SERH_RN_E35_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E35_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E48_MASK                            (0x00010000U)
#define CSL_EVETPCC_SERH_RN_E48_SHIFT                           (16U)
#define CSL_EVETPCC_SERH_RN_E48_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E48_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E62_MASK                            (0x40000000U)
#define CSL_EVETPCC_SERH_RN_E62_SHIFT                           (30U)
#define CSL_EVETPCC_SERH_RN_E62_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E62_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E39_MASK                            (0x00000080U)
#define CSL_EVETPCC_SERH_RN_E39_SHIFT                           (7U)
#define CSL_EVETPCC_SERH_RN_E39_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E39_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E63_MASK                            (0x80000000U)
#define CSL_EVETPCC_SERH_RN_E63_SHIFT                           (31U)
#define CSL_EVETPCC_SERH_RN_E63_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E63_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E36_MASK                            (0x00000010U)
#define CSL_EVETPCC_SERH_RN_E36_SHIFT                           (4U)
#define CSL_EVETPCC_SERH_RN_E36_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E36_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E49_MASK                            (0x00020000U)
#define CSL_EVETPCC_SERH_RN_E49_SHIFT                           (17U)
#define CSL_EVETPCC_SERH_RN_E49_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E49_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E40_MASK                            (0x00000100U)
#define CSL_EVETPCC_SERH_RN_E40_SHIFT                           (8U)
#define CSL_EVETPCC_SERH_RN_E40_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E40_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E33_MASK                            (0x00000002U)
#define CSL_EVETPCC_SERH_RN_E33_SHIFT                           (1U)
#define CSL_EVETPCC_SERH_RN_E33_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E33_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E50_MASK                            (0x00040000U)
#define CSL_EVETPCC_SERH_RN_E50_SHIFT                           (18U)
#define CSL_EVETPCC_SERH_RN_E50_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E50_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E41_MASK                            (0x00000200U)
#define CSL_EVETPCC_SERH_RN_E41_SHIFT                           (9U)
#define CSL_EVETPCC_SERH_RN_E41_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E41_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E34_MASK                            (0x00000004U)
#define CSL_EVETPCC_SERH_RN_E34_SHIFT                           (2U)
#define CSL_EVETPCC_SERH_RN_E34_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E34_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_E51_MASK                            (0x00080000U)
#define CSL_EVETPCC_SERH_RN_E51_SHIFT                           (19U)
#define CSL_EVETPCC_SERH_RN_E51_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SERH_RN_E51_MAX                             (0x00000001U)

#define CSL_EVETPCC_SERH_RN_RESETVAL                            (0x00000000U)

/* ESR_RN */

#define CSL_EVETPCC_ESR_RN_E3_MASK                              (0x00000008U)
#define CSL_EVETPCC_ESR_RN_E3_SHIFT                             (3U)
#define CSL_EVETPCC_ESR_RN_E3_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E3_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E6_MASK                              (0x00000040U)
#define CSL_EVETPCC_ESR_RN_E6_SHIFT                             (6U)
#define CSL_EVETPCC_ESR_RN_E6_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E6_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E20_MASK                             (0x00100000U)
#define CSL_EVETPCC_ESR_RN_E20_SHIFT                            (20U)
#define CSL_EVETPCC_ESR_RN_E20_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E20_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E1_MASK                              (0x00000002U)
#define CSL_EVETPCC_ESR_RN_E1_SHIFT                             (1U)
#define CSL_EVETPCC_ESR_RN_E1_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E1_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E4_MASK                              (0x00000010U)
#define CSL_EVETPCC_ESR_RN_E4_SHIFT                             (4U)
#define CSL_EVETPCC_ESR_RN_E4_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E4_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E18_MASK                             (0x00040000U)
#define CSL_EVETPCC_ESR_RN_E18_SHIFT                            (18U)
#define CSL_EVETPCC_ESR_RN_E18_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E18_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E7_MASK                              (0x00000080U)
#define CSL_EVETPCC_ESR_RN_E7_SHIFT                             (7U)
#define CSL_EVETPCC_ESR_RN_E7_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E7_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E11_MASK                             (0x00000800U)
#define CSL_EVETPCC_ESR_RN_E11_SHIFT                            (11U)
#define CSL_EVETPCC_ESR_RN_E11_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E11_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E10_MASK                             (0x00000400U)
#define CSL_EVETPCC_ESR_RN_E10_SHIFT                            (10U)
#define CSL_EVETPCC_ESR_RN_E10_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E10_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E5_MASK                              (0x00000020U)
#define CSL_EVETPCC_ESR_RN_E5_SHIFT                             (5U)
#define CSL_EVETPCC_ESR_RN_E5_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E5_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E8_MASK                              (0x00000100U)
#define CSL_EVETPCC_ESR_RN_E8_SHIFT                             (8U)
#define CSL_EVETPCC_ESR_RN_E8_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E8_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E22_MASK                             (0x00400000U)
#define CSL_EVETPCC_ESR_RN_E22_SHIFT                            (22U)
#define CSL_EVETPCC_ESR_RN_E22_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E22_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E21_MASK                             (0x00200000U)
#define CSL_EVETPCC_ESR_RN_E21_SHIFT                            (21U)
#define CSL_EVETPCC_ESR_RN_E21_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E21_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E23_MASK                             (0x00800000U)
#define CSL_EVETPCC_ESR_RN_E23_SHIFT                            (23U)
#define CSL_EVETPCC_ESR_RN_E23_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E23_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E31_MASK                             (0x80000000U)
#define CSL_EVETPCC_ESR_RN_E31_SHIFT                            (31U)
#define CSL_EVETPCC_ESR_RN_E31_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E31_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E15_MASK                             (0x00008000U)
#define CSL_EVETPCC_ESR_RN_E15_SHIFT                            (15U)
#define CSL_EVETPCC_ESR_RN_E15_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E15_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E26_MASK                             (0x04000000U)
#define CSL_EVETPCC_ESR_RN_E26_SHIFT                            (26U)
#define CSL_EVETPCC_ESR_RN_E26_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E26_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E24_MASK                             (0x01000000U)
#define CSL_EVETPCC_ESR_RN_E24_SHIFT                            (24U)
#define CSL_EVETPCC_ESR_RN_E24_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E24_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E12_MASK                             (0x00001000U)
#define CSL_EVETPCC_ESR_RN_E12_SHIFT                            (12U)
#define CSL_EVETPCC_ESR_RN_E12_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E12_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E13_MASK                             (0x00002000U)
#define CSL_EVETPCC_ESR_RN_E13_SHIFT                            (13U)
#define CSL_EVETPCC_ESR_RN_E13_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E13_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E9_MASK                              (0x00000200U)
#define CSL_EVETPCC_ESR_RN_E9_SHIFT                             (9U)
#define CSL_EVETPCC_ESR_RN_E9_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E9_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E28_MASK                             (0x10000000U)
#define CSL_EVETPCC_ESR_RN_E28_SHIFT                            (28U)
#define CSL_EVETPCC_ESR_RN_E28_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E28_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E25_MASK                             (0x02000000U)
#define CSL_EVETPCC_ESR_RN_E25_SHIFT                            (25U)
#define CSL_EVETPCC_ESR_RN_E25_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E25_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E0_MASK                              (0x00000001U)
#define CSL_EVETPCC_ESR_RN_E0_SHIFT                             (0U)
#define CSL_EVETPCC_ESR_RN_E0_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E0_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E19_MASK                             (0x00080000U)
#define CSL_EVETPCC_ESR_RN_E19_SHIFT                            (19U)
#define CSL_EVETPCC_ESR_RN_E19_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E19_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E16_MASK                             (0x00010000U)
#define CSL_EVETPCC_ESR_RN_E16_SHIFT                            (16U)
#define CSL_EVETPCC_ESR_RN_E16_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E16_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E2_MASK                              (0x00000004U)
#define CSL_EVETPCC_ESR_RN_E2_SHIFT                             (2U)
#define CSL_EVETPCC_ESR_RN_E2_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E2_MAX                               (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E27_MASK                             (0x08000000U)
#define CSL_EVETPCC_ESR_RN_E27_SHIFT                            (27U)
#define CSL_EVETPCC_ESR_RN_E27_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E27_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E17_MASK                             (0x00020000U)
#define CSL_EVETPCC_ESR_RN_E17_SHIFT                            (17U)
#define CSL_EVETPCC_ESR_RN_E17_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E17_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E30_MASK                             (0x40000000U)
#define CSL_EVETPCC_ESR_RN_E30_SHIFT                            (30U)
#define CSL_EVETPCC_ESR_RN_E30_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E30_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E14_MASK                             (0x00004000U)
#define CSL_EVETPCC_ESR_RN_E14_SHIFT                            (14U)
#define CSL_EVETPCC_ESR_RN_E14_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E14_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_E29_MASK                             (0x20000000U)
#define CSL_EVETPCC_ESR_RN_E29_SHIFT                            (29U)
#define CSL_EVETPCC_ESR_RN_E29_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ESR_RN_E29_MAX                              (0x00000001U)

#define CSL_EVETPCC_ESR_RN_RESETVAL                             (0x00000000U)

/* EECR_RN */

#define CSL_EVETPCC_EECR_RN_E30_MASK                            (0x40000000U)
#define CSL_EVETPCC_EECR_RN_E30_SHIFT                           (30U)
#define CSL_EVETPCC_EECR_RN_E30_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E30_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E25_MASK                            (0x02000000U)
#define CSL_EVETPCC_EECR_RN_E25_SHIFT                           (25U)
#define CSL_EVETPCC_EECR_RN_E25_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E25_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E14_MASK                            (0x00004000U)
#define CSL_EVETPCC_EECR_RN_E14_SHIFT                           (14U)
#define CSL_EVETPCC_EECR_RN_E14_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E14_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E15_MASK                            (0x00008000U)
#define CSL_EVETPCC_EECR_RN_E15_SHIFT                           (15U)
#define CSL_EVETPCC_EECR_RN_E15_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E15_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E5_MASK                             (0x00000020U)
#define CSL_EVETPCC_EECR_RN_E5_SHIFT                            (5U)
#define CSL_EVETPCC_EECR_RN_E5_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E5_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E31_MASK                            (0x80000000U)
#define CSL_EVETPCC_EECR_RN_E31_SHIFT                           (31U)
#define CSL_EVETPCC_EECR_RN_E31_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E31_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E24_MASK                            (0x01000000U)
#define CSL_EVETPCC_EECR_RN_E24_SHIFT                           (24U)
#define CSL_EVETPCC_EECR_RN_E24_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E24_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E28_MASK                            (0x10000000U)
#define CSL_EVETPCC_EECR_RN_E28_SHIFT                           (28U)
#define CSL_EVETPCC_EECR_RN_E28_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E28_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E6_MASK                             (0x00000040U)
#define CSL_EVETPCC_EECR_RN_E6_SHIFT                            (6U)
#define CSL_EVETPCC_EECR_RN_E6_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E6_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E16_MASK                            (0x00010000U)
#define CSL_EVETPCC_EECR_RN_E16_SHIFT                           (16U)
#define CSL_EVETPCC_EECR_RN_E16_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E16_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E29_MASK                            (0x20000000U)
#define CSL_EVETPCC_EECR_RN_E29_SHIFT                           (29U)
#define CSL_EVETPCC_EECR_RN_E29_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E29_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E26_MASK                            (0x04000000U)
#define CSL_EVETPCC_EECR_RN_E26_SHIFT                           (26U)
#define CSL_EVETPCC_EECR_RN_E26_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E26_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E8_MASK                             (0x00000100U)
#define CSL_EVETPCC_EECR_RN_E8_SHIFT                            (8U)
#define CSL_EVETPCC_EECR_RN_E8_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E8_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E18_MASK                            (0x00040000U)
#define CSL_EVETPCC_EECR_RN_E18_SHIFT                           (18U)
#define CSL_EVETPCC_EECR_RN_E18_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E18_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E7_MASK                             (0x00000080U)
#define CSL_EVETPCC_EECR_RN_E7_SHIFT                            (7U)
#define CSL_EVETPCC_EECR_RN_E7_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E7_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E17_MASK                            (0x00020000U)
#define CSL_EVETPCC_EECR_RN_E17_SHIFT                           (17U)
#define CSL_EVETPCC_EECR_RN_E17_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E17_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E10_MASK                            (0x00000400U)
#define CSL_EVETPCC_EECR_RN_E10_SHIFT                           (10U)
#define CSL_EVETPCC_EECR_RN_E10_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E10_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E20_MASK                            (0x00100000U)
#define CSL_EVETPCC_EECR_RN_E20_SHIFT                           (20U)
#define CSL_EVETPCC_EECR_RN_E20_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E20_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E9_MASK                             (0x00000200U)
#define CSL_EVETPCC_EECR_RN_E9_SHIFT                            (9U)
#define CSL_EVETPCC_EECR_RN_E9_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E9_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E0_MASK                             (0x00000001U)
#define CSL_EVETPCC_EECR_RN_E0_SHIFT                            (0U)
#define CSL_EVETPCC_EECR_RN_E0_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E0_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E19_MASK                            (0x00080000U)
#define CSL_EVETPCC_EECR_RN_E19_SHIFT                           (19U)
#define CSL_EVETPCC_EECR_RN_E19_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E19_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E1_MASK                             (0x00000002U)
#define CSL_EVETPCC_EECR_RN_E1_SHIFT                            (1U)
#define CSL_EVETPCC_EECR_RN_E1_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E1_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E12_MASK                            (0x00001000U)
#define CSL_EVETPCC_EECR_RN_E12_SHIFT                           (12U)
#define CSL_EVETPCC_EECR_RN_E12_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E12_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E22_MASK                            (0x00400000U)
#define CSL_EVETPCC_EECR_RN_E22_SHIFT                           (22U)
#define CSL_EVETPCC_EECR_RN_E22_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E22_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E2_MASK                             (0x00000004U)
#define CSL_EVETPCC_EECR_RN_E2_SHIFT                            (2U)
#define CSL_EVETPCC_EECR_RN_E2_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E2_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E11_MASK                            (0x00000800U)
#define CSL_EVETPCC_EECR_RN_E11_SHIFT                           (11U)
#define CSL_EVETPCC_EECR_RN_E11_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E11_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E21_MASK                            (0x00200000U)
#define CSL_EVETPCC_EECR_RN_E21_SHIFT                           (21U)
#define CSL_EVETPCC_EECR_RN_E21_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E21_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E27_MASK                            (0x08000000U)
#define CSL_EVETPCC_EECR_RN_E27_SHIFT                           (27U)
#define CSL_EVETPCC_EECR_RN_E27_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E27_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E3_MASK                             (0x00000008U)
#define CSL_EVETPCC_EECR_RN_E3_SHIFT                            (3U)
#define CSL_EVETPCC_EECR_RN_E3_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E3_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E23_MASK                            (0x00800000U)
#define CSL_EVETPCC_EECR_RN_E23_SHIFT                           (23U)
#define CSL_EVETPCC_EECR_RN_E23_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E23_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E4_MASK                             (0x00000010U)
#define CSL_EVETPCC_EECR_RN_E4_SHIFT                            (4U)
#define CSL_EVETPCC_EECR_RN_E4_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E4_MAX                              (0x00000001U)

#define CSL_EVETPCC_EECR_RN_E13_MASK                            (0x00002000U)
#define CSL_EVETPCC_EECR_RN_E13_SHIFT                           (13U)
#define CSL_EVETPCC_EECR_RN_E13_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EECR_RN_E13_MAX                             (0x00000001U)

#define CSL_EVETPCC_EECR_RN_RESETVAL                            (0x00000000U)

/* ER_RN */

#define CSL_EVETPCC_ER_RN_E22_MASK                              (0x00400000U)
#define CSL_EVETPCC_ER_RN_E22_SHIFT                             (22U)
#define CSL_EVETPCC_ER_RN_E22_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E22_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E2_MASK                               (0x00000004U)
#define CSL_EVETPCC_ER_RN_E2_SHIFT                              (2U)
#define CSL_EVETPCC_ER_RN_E2_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E2_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E19_MASK                              (0x00080000U)
#define CSL_EVETPCC_ER_RN_E19_SHIFT                             (19U)
#define CSL_EVETPCC_ER_RN_E19_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E19_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E5_MASK                               (0x00000020U)
#define CSL_EVETPCC_ER_RN_E5_SHIFT                              (5U)
#define CSL_EVETPCC_ER_RN_E5_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E5_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E29_MASK                              (0x20000000U)
#define CSL_EVETPCC_ER_RN_E29_SHIFT                             (29U)
#define CSL_EVETPCC_ER_RN_E29_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E29_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E18_MASK                              (0x00040000U)
#define CSL_EVETPCC_ER_RN_E18_SHIFT                             (18U)
#define CSL_EVETPCC_ER_RN_E18_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E18_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E6_MASK                               (0x00000040U)
#define CSL_EVETPCC_ER_RN_E6_SHIFT                              (6U)
#define CSL_EVETPCC_ER_RN_E6_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E6_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E21_MASK                              (0x00200000U)
#define CSL_EVETPCC_ER_RN_E21_SHIFT                             (21U)
#define CSL_EVETPCC_ER_RN_E21_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E21_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E3_MASK                               (0x00000008U)
#define CSL_EVETPCC_ER_RN_E3_SHIFT                              (3U)
#define CSL_EVETPCC_ER_RN_E3_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E3_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E31_MASK                              (0x80000000U)
#define CSL_EVETPCC_ER_RN_E31_SHIFT                             (31U)
#define CSL_EVETPCC_ER_RN_E31_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E31_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E20_MASK                              (0x00100000U)
#define CSL_EVETPCC_ER_RN_E20_SHIFT                             (20U)
#define CSL_EVETPCC_ER_RN_E20_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E20_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E4_MASK                               (0x00000010U)
#define CSL_EVETPCC_ER_RN_E4_SHIFT                              (4U)
#define CSL_EVETPCC_ER_RN_E4_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E4_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E9_MASK                               (0x00000200U)
#define CSL_EVETPCC_ER_RN_E9_SHIFT                              (9U)
#define CSL_EVETPCC_ER_RN_E9_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E9_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E28_MASK                              (0x10000000U)
#define CSL_EVETPCC_ER_RN_E28_SHIFT                             (28U)
#define CSL_EVETPCC_ER_RN_E28_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E28_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E14_MASK                              (0x00004000U)
#define CSL_EVETPCC_ER_RN_E14_SHIFT                             (14U)
#define CSL_EVETPCC_ER_RN_E14_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E14_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E10_MASK                              (0x00000400U)
#define CSL_EVETPCC_ER_RN_E10_SHIFT                             (10U)
#define CSL_EVETPCC_ER_RN_E10_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E10_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E27_MASK                              (0x08000000U)
#define CSL_EVETPCC_ER_RN_E27_SHIFT                             (27U)
#define CSL_EVETPCC_ER_RN_E27_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E27_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E7_MASK                               (0x00000080U)
#define CSL_EVETPCC_ER_RN_E7_SHIFT                              (7U)
#define CSL_EVETPCC_ER_RN_E7_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E7_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E17_MASK                              (0x00020000U)
#define CSL_EVETPCC_ER_RN_E17_SHIFT                             (17U)
#define CSL_EVETPCC_ER_RN_E17_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E17_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E8_MASK                               (0x00000100U)
#define CSL_EVETPCC_ER_RN_E8_SHIFT                              (8U)
#define CSL_EVETPCC_ER_RN_E8_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E8_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E16_MASK                              (0x00010000U)
#define CSL_EVETPCC_ER_RN_E16_SHIFT                             (16U)
#define CSL_EVETPCC_ER_RN_E16_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E16_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E30_MASK                              (0x40000000U)
#define CSL_EVETPCC_ER_RN_E30_SHIFT                             (30U)
#define CSL_EVETPCC_ER_RN_E30_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E30_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E24_MASK                              (0x01000000U)
#define CSL_EVETPCC_ER_RN_E24_SHIFT                             (24U)
#define CSL_EVETPCC_ER_RN_E24_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E24_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E23_MASK                              (0x00800000U)
#define CSL_EVETPCC_ER_RN_E23_SHIFT                             (23U)
#define CSL_EVETPCC_ER_RN_E23_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E23_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E0_MASK                               (0x00000001U)
#define CSL_EVETPCC_ER_RN_E0_SHIFT                              (0U)
#define CSL_EVETPCC_ER_RN_E0_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E0_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E13_MASK                              (0x00002000U)
#define CSL_EVETPCC_ER_RN_E13_SHIFT                             (13U)
#define CSL_EVETPCC_ER_RN_E13_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E13_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E11_MASK                              (0x00000800U)
#define CSL_EVETPCC_ER_RN_E11_SHIFT                             (11U)
#define CSL_EVETPCC_ER_RN_E11_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E11_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E26_MASK                              (0x04000000U)
#define CSL_EVETPCC_ER_RN_E26_SHIFT                             (26U)
#define CSL_EVETPCC_ER_RN_E26_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E26_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E1_MASK                               (0x00000002U)
#define CSL_EVETPCC_ER_RN_E1_SHIFT                              (1U)
#define CSL_EVETPCC_ER_RN_E1_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_ER_RN_E1_MAX                                (0x00000001U)

#define CSL_EVETPCC_ER_RN_E12_MASK                              (0x00001000U)
#define CSL_EVETPCC_ER_RN_E12_SHIFT                             (12U)
#define CSL_EVETPCC_ER_RN_E12_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E12_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E25_MASK                              (0x02000000U)
#define CSL_EVETPCC_ER_RN_E25_SHIFT                             (25U)
#define CSL_EVETPCC_ER_RN_E25_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E25_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_E15_MASK                              (0x00008000U)
#define CSL_EVETPCC_ER_RN_E15_SHIFT                             (15U)
#define CSL_EVETPCC_ER_RN_E15_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ER_RN_E15_MAX                               (0x00000001U)

#define CSL_EVETPCC_ER_RN_RESETVAL                              (0x00000000U)

/* ICRH_RN */

#define CSL_EVETPCC_ICRH_RN_I37_MASK                            (0x00000020U)
#define CSL_EVETPCC_ICRH_RN_I37_SHIFT                           (5U)
#define CSL_EVETPCC_ICRH_RN_I37_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I37_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I47_MASK                            (0x00008000U)
#define CSL_EVETPCC_ICRH_RN_I47_SHIFT                           (15U)
#define CSL_EVETPCC_ICRH_RN_I47_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I47_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I53_MASK                            (0x00200000U)
#define CSL_EVETPCC_ICRH_RN_I53_SHIFT                           (21U)
#define CSL_EVETPCC_ICRH_RN_I53_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I53_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I36_MASK                            (0x00000010U)
#define CSL_EVETPCC_ICRH_RN_I36_SHIFT                           (4U)
#define CSL_EVETPCC_ICRH_RN_I36_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I36_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I63_MASK                            (0x80000000U)
#define CSL_EVETPCC_ICRH_RN_I63_SHIFT                           (31U)
#define CSL_EVETPCC_ICRH_RN_I63_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I63_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I46_MASK                            (0x00004000U)
#define CSL_EVETPCC_ICRH_RN_I46_SHIFT                           (14U)
#define CSL_EVETPCC_ICRH_RN_I46_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I46_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I39_MASK                            (0x00000080U)
#define CSL_EVETPCC_ICRH_RN_I39_SHIFT                           (7U)
#define CSL_EVETPCC_ICRH_RN_I39_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I39_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I49_MASK                            (0x00020000U)
#define CSL_EVETPCC_ICRH_RN_I49_SHIFT                           (17U)
#define CSL_EVETPCC_ICRH_RN_I49_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I49_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I38_MASK                            (0x00000040U)
#define CSL_EVETPCC_ICRH_RN_I38_SHIFT                           (6U)
#define CSL_EVETPCC_ICRH_RN_I38_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I38_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I48_MASK                            (0x00010000U)
#define CSL_EVETPCC_ICRH_RN_I48_SHIFT                           (16U)
#define CSL_EVETPCC_ICRH_RN_I48_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I48_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I41_MASK                            (0x00000200U)
#define CSL_EVETPCC_ICRH_RN_I41_SHIFT                           (9U)
#define CSL_EVETPCC_ICRH_RN_I41_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I41_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I51_MASK                            (0x00080000U)
#define CSL_EVETPCC_ICRH_RN_I51_SHIFT                           (19U)
#define CSL_EVETPCC_ICRH_RN_I51_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I51_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I40_MASK                            (0x00000100U)
#define CSL_EVETPCC_ICRH_RN_I40_SHIFT                           (8U)
#define CSL_EVETPCC_ICRH_RN_I40_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I40_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I50_MASK                            (0x00040000U)
#define CSL_EVETPCC_ICRH_RN_I50_SHIFT                           (18U)
#define CSL_EVETPCC_ICRH_RN_I50_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I50_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I42_MASK                            (0x00000400U)
#define CSL_EVETPCC_ICRH_RN_I42_SHIFT                           (10U)
#define CSL_EVETPCC_ICRH_RN_I42_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I42_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I62_MASK                            (0x40000000U)
#define CSL_EVETPCC_ICRH_RN_I62_SHIFT                           (30U)
#define CSL_EVETPCC_ICRH_RN_I62_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I62_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I52_MASK                            (0x00100000U)
#define CSL_EVETPCC_ICRH_RN_I52_SHIFT                           (20U)
#define CSL_EVETPCC_ICRH_RN_I52_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I52_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I61_MASK                            (0x20000000U)
#define CSL_EVETPCC_ICRH_RN_I61_SHIFT                           (29U)
#define CSL_EVETPCC_ICRH_RN_I61_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I61_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I32_MASK                            (0x00000001U)
#define CSL_EVETPCC_ICRH_RN_I32_SHIFT                           (0U)
#define CSL_EVETPCC_ICRH_RN_I32_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I32_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I60_MASK                            (0x10000000U)
#define CSL_EVETPCC_ICRH_RN_I60_SHIFT                           (28U)
#define CSL_EVETPCC_ICRH_RN_I60_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I60_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I59_MASK                            (0x08000000U)
#define CSL_EVETPCC_ICRH_RN_I59_SHIFT                           (27U)
#define CSL_EVETPCC_ICRH_RN_I59_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I59_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I58_MASK                            (0x04000000U)
#define CSL_EVETPCC_ICRH_RN_I58_SHIFT                           (26U)
#define CSL_EVETPCC_ICRH_RN_I58_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I58_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I57_MASK                            (0x02000000U)
#define CSL_EVETPCC_ICRH_RN_I57_SHIFT                           (25U)
#define CSL_EVETPCC_ICRH_RN_I57_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I57_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I33_MASK                            (0x00000002U)
#define CSL_EVETPCC_ICRH_RN_I33_SHIFT                           (1U)
#define CSL_EVETPCC_ICRH_RN_I33_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I33_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I43_MASK                            (0x00000800U)
#define CSL_EVETPCC_ICRH_RN_I43_SHIFT                           (11U)
#define CSL_EVETPCC_ICRH_RN_I43_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I43_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I56_MASK                            (0x01000000U)
#define CSL_EVETPCC_ICRH_RN_I56_SHIFT                           (24U)
#define CSL_EVETPCC_ICRH_RN_I56_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I56_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I35_MASK                            (0x00000008U)
#define CSL_EVETPCC_ICRH_RN_I35_SHIFT                           (3U)
#define CSL_EVETPCC_ICRH_RN_I35_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I35_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I55_MASK                            (0x00800000U)
#define CSL_EVETPCC_ICRH_RN_I55_SHIFT                           (23U)
#define CSL_EVETPCC_ICRH_RN_I55_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I55_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I45_MASK                            (0x00002000U)
#define CSL_EVETPCC_ICRH_RN_I45_SHIFT                           (13U)
#define CSL_EVETPCC_ICRH_RN_I45_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I45_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I34_MASK                            (0x00000004U)
#define CSL_EVETPCC_ICRH_RN_I34_SHIFT                           (2U)
#define CSL_EVETPCC_ICRH_RN_I34_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I34_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I54_MASK                            (0x00400000U)
#define CSL_EVETPCC_ICRH_RN_I54_SHIFT                           (22U)
#define CSL_EVETPCC_ICRH_RN_I54_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I54_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_I44_MASK                            (0x00001000U)
#define CSL_EVETPCC_ICRH_RN_I44_SHIFT                           (12U)
#define CSL_EVETPCC_ICRH_RN_I44_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ICRH_RN_I44_MAX                             (0x00000001U)

#define CSL_EVETPCC_ICRH_RN_RESETVAL                            (0x00000000U)

/* EECRH_RN */

#define CSL_EVETPCC_EECRH_RN_E62_MASK                           (0x40000000U)
#define CSL_EVETPCC_EECRH_RN_E62_SHIFT                          (30U)
#define CSL_EVETPCC_EECRH_RN_E62_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E62_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E37_MASK                           (0x00000020U)
#define CSL_EVETPCC_EECRH_RN_E37_SHIFT                          (5U)
#define CSL_EVETPCC_EECRH_RN_E37_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E37_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E51_MASK                           (0x00080000U)
#define CSL_EVETPCC_EECRH_RN_E51_SHIFT                          (19U)
#define CSL_EVETPCC_EECRH_RN_E51_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E51_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E36_MASK                           (0x00000010U)
#define CSL_EVETPCC_EECRH_RN_E36_SHIFT                          (4U)
#define CSL_EVETPCC_EECRH_RN_E36_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E36_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E50_MASK                           (0x00040000U)
#define CSL_EVETPCC_EECRH_RN_E50_SHIFT                          (18U)
#define CSL_EVETPCC_EECRH_RN_E50_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E50_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E35_MASK                           (0x00000008U)
#define CSL_EVETPCC_EECRH_RN_E35_SHIFT                          (3U)
#define CSL_EVETPCC_EECRH_RN_E35_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E35_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E63_MASK                           (0x80000000U)
#define CSL_EVETPCC_EECRH_RN_E63_SHIFT                          (31U)
#define CSL_EVETPCC_EECRH_RN_E63_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E63_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E54_MASK                           (0x00400000U)
#define CSL_EVETPCC_EECRH_RN_E54_SHIFT                          (22U)
#define CSL_EVETPCC_EECRH_RN_E54_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E54_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E58_MASK                           (0x04000000U)
#define CSL_EVETPCC_EECRH_RN_E58_SHIFT                          (26U)
#define CSL_EVETPCC_EECRH_RN_E58_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E58_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E48_MASK                           (0x00010000U)
#define CSL_EVETPCC_EECRH_RN_E48_SHIFT                          (16U)
#define CSL_EVETPCC_EECRH_RN_E48_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E48_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E59_MASK                           (0x08000000U)
#define CSL_EVETPCC_EECRH_RN_E59_SHIFT                          (27U)
#define CSL_EVETPCC_EECRH_RN_E59_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E59_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E53_MASK                           (0x00200000U)
#define CSL_EVETPCC_EECRH_RN_E53_SHIFT                          (21U)
#define CSL_EVETPCC_EECRH_RN_E53_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E53_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E49_MASK                           (0x00020000U)
#define CSL_EVETPCC_EECRH_RN_E49_SHIFT                          (17U)
#define CSL_EVETPCC_EECRH_RN_E49_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E49_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E60_MASK                           (0x10000000U)
#define CSL_EVETPCC_EECRH_RN_E60_SHIFT                          (28U)
#define CSL_EVETPCC_EECRH_RN_E60_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E60_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E61_MASK                           (0x20000000U)
#define CSL_EVETPCC_EECRH_RN_E61_SHIFT                          (29U)
#define CSL_EVETPCC_EECRH_RN_E61_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E61_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E52_MASK                           (0x00100000U)
#define CSL_EVETPCC_EECRH_RN_E52_SHIFT                          (20U)
#define CSL_EVETPCC_EECRH_RN_E52_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E52_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E44_MASK                           (0x00001000U)
#define CSL_EVETPCC_EECRH_RN_E44_SHIFT                          (12U)
#define CSL_EVETPCC_EECRH_RN_E44_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E44_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E34_MASK                           (0x00000004U)
#define CSL_EVETPCC_EECRH_RN_E34_SHIFT                          (2U)
#define CSL_EVETPCC_EECRH_RN_E34_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E34_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E43_MASK                           (0x00000800U)
#define CSL_EVETPCC_EECRH_RN_E43_SHIFT                          (11U)
#define CSL_EVETPCC_EECRH_RN_E43_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E43_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E33_MASK                           (0x00000002U)
#define CSL_EVETPCC_EECRH_RN_E33_SHIFT                          (1U)
#define CSL_EVETPCC_EECRH_RN_E33_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E33_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E55_MASK                           (0x00800000U)
#define CSL_EVETPCC_EECRH_RN_E55_SHIFT                          (23U)
#define CSL_EVETPCC_EECRH_RN_E55_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E55_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E42_MASK                           (0x00000400U)
#define CSL_EVETPCC_EECRH_RN_E42_SHIFT                          (10U)
#define CSL_EVETPCC_EECRH_RN_E42_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E42_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E56_MASK                           (0x01000000U)
#define CSL_EVETPCC_EECRH_RN_E56_SHIFT                          (24U)
#define CSL_EVETPCC_EECRH_RN_E56_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E56_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E32_MASK                           (0x00000001U)
#define CSL_EVETPCC_EECRH_RN_E32_SHIFT                          (0U)
#define CSL_EVETPCC_EECRH_RN_E32_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E32_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E41_MASK                           (0x00000200U)
#define CSL_EVETPCC_EECRH_RN_E41_SHIFT                          (9U)
#define CSL_EVETPCC_EECRH_RN_E41_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E41_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E57_MASK                           (0x02000000U)
#define CSL_EVETPCC_EECRH_RN_E57_SHIFT                          (25U)
#define CSL_EVETPCC_EECRH_RN_E57_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E57_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E47_MASK                           (0x00008000U)
#define CSL_EVETPCC_EECRH_RN_E47_SHIFT                          (15U)
#define CSL_EVETPCC_EECRH_RN_E47_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E47_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E40_MASK                           (0x00000100U)
#define CSL_EVETPCC_EECRH_RN_E40_SHIFT                          (8U)
#define CSL_EVETPCC_EECRH_RN_E40_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E40_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E46_MASK                           (0x00004000U)
#define CSL_EVETPCC_EECRH_RN_E46_SHIFT                          (14U)
#define CSL_EVETPCC_EECRH_RN_E46_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E46_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E39_MASK                           (0x00000080U)
#define CSL_EVETPCC_EECRH_RN_E39_SHIFT                          (7U)
#define CSL_EVETPCC_EECRH_RN_E39_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E39_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E45_MASK                           (0x00002000U)
#define CSL_EVETPCC_EECRH_RN_E45_SHIFT                          (13U)
#define CSL_EVETPCC_EECRH_RN_E45_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E45_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_E38_MASK                           (0x00000040U)
#define CSL_EVETPCC_EECRH_RN_E38_SHIFT                          (6U)
#define CSL_EVETPCC_EECRH_RN_E38_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EECRH_RN_E38_MAX                            (0x00000001U)

#define CSL_EVETPCC_EECRH_RN_RESETVAL                           (0x00000000U)

/* IESR_RN */

#define CSL_EVETPCC_IESR_RN_I22_MASK                            (0x00400000U)
#define CSL_EVETPCC_IESR_RN_I22_SHIFT                           (22U)
#define CSL_EVETPCC_IESR_RN_I22_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I22_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I11_MASK                            (0x00000800U)
#define CSL_EVETPCC_IESR_RN_I11_SHIFT                           (11U)
#define CSL_EVETPCC_IESR_RN_I11_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I11_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I23_MASK                            (0x00800000U)
#define CSL_EVETPCC_IESR_RN_I23_SHIFT                           (23U)
#define CSL_EVETPCC_IESR_RN_I23_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I23_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I0_MASK                             (0x00000001U)
#define CSL_EVETPCC_IESR_RN_I0_SHIFT                            (0U)
#define CSL_EVETPCC_IESR_RN_I0_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I0_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I21_MASK                            (0x00200000U)
#define CSL_EVETPCC_IESR_RN_I21_SHIFT                           (21U)
#define CSL_EVETPCC_IESR_RN_I21_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I21_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I10_MASK                            (0x00000400U)
#define CSL_EVETPCC_IESR_RN_I10_SHIFT                           (10U)
#define CSL_EVETPCC_IESR_RN_I10_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I10_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I31_MASK                            (0x80000000U)
#define CSL_EVETPCC_IESR_RN_I31_SHIFT                           (31U)
#define CSL_EVETPCC_IESR_RN_I31_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I31_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I8_MASK                             (0x00000100U)
#define CSL_EVETPCC_IESR_RN_I8_SHIFT                            (8U)
#define CSL_EVETPCC_IESR_RN_I8_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I8_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I20_MASK                            (0x00100000U)
#define CSL_EVETPCC_IESR_RN_I20_SHIFT                           (20U)
#define CSL_EVETPCC_IESR_RN_I20_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I20_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I9_MASK                             (0x00000200U)
#define CSL_EVETPCC_IESR_RN_I9_SHIFT                            (9U)
#define CSL_EVETPCC_IESR_RN_I9_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I9_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I6_MASK                             (0x00000040U)
#define CSL_EVETPCC_IESR_RN_I6_SHIFT                            (6U)
#define CSL_EVETPCC_IESR_RN_I6_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I6_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I30_MASK                            (0x40000000U)
#define CSL_EVETPCC_IESR_RN_I30_SHIFT                           (30U)
#define CSL_EVETPCC_IESR_RN_I30_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I30_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I17_MASK                            (0x00020000U)
#define CSL_EVETPCC_IESR_RN_I17_SHIFT                           (17U)
#define CSL_EVETPCC_IESR_RN_I17_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I17_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I7_MASK                             (0x00000080U)
#define CSL_EVETPCC_IESR_RN_I7_SHIFT                            (7U)
#define CSL_EVETPCC_IESR_RN_I7_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I7_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I16_MASK                            (0x00010000U)
#define CSL_EVETPCC_IESR_RN_I16_SHIFT                           (16U)
#define CSL_EVETPCC_IESR_RN_I16_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I16_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I28_MASK                            (0x10000000U)
#define CSL_EVETPCC_IESR_RN_I28_SHIFT                           (28U)
#define CSL_EVETPCC_IESR_RN_I28_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I28_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I4_MASK                             (0x00000010U)
#define CSL_EVETPCC_IESR_RN_I4_SHIFT                            (4U)
#define CSL_EVETPCC_IESR_RN_I4_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I4_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I29_MASK                            (0x20000000U)
#define CSL_EVETPCC_IESR_RN_I29_SHIFT                           (29U)
#define CSL_EVETPCC_IESR_RN_I29_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I29_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I19_MASK                            (0x00080000U)
#define CSL_EVETPCC_IESR_RN_I19_SHIFT                           (19U)
#define CSL_EVETPCC_IESR_RN_I19_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I19_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I5_MASK                             (0x00000020U)
#define CSL_EVETPCC_IESR_RN_I5_SHIFT                            (5U)
#define CSL_EVETPCC_IESR_RN_I5_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I5_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I18_MASK                            (0x00040000U)
#define CSL_EVETPCC_IESR_RN_I18_SHIFT                           (18U)
#define CSL_EVETPCC_IESR_RN_I18_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I18_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I26_MASK                            (0x04000000U)
#define CSL_EVETPCC_IESR_RN_I26_SHIFT                           (26U)
#define CSL_EVETPCC_IESR_RN_I26_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I26_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I2_MASK                             (0x00000004U)
#define CSL_EVETPCC_IESR_RN_I2_SHIFT                            (2U)
#define CSL_EVETPCC_IESR_RN_I2_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I2_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I13_MASK                            (0x00002000U)
#define CSL_EVETPCC_IESR_RN_I13_SHIFT                           (13U)
#define CSL_EVETPCC_IESR_RN_I13_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I13_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I3_MASK                             (0x00000008U)
#define CSL_EVETPCC_IESR_RN_I3_SHIFT                            (3U)
#define CSL_EVETPCC_IESR_RN_I3_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I3_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I27_MASK                            (0x08000000U)
#define CSL_EVETPCC_IESR_RN_I27_SHIFT                           (27U)
#define CSL_EVETPCC_IESR_RN_I27_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I27_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I12_MASK                            (0x00001000U)
#define CSL_EVETPCC_IESR_RN_I12_SHIFT                           (12U)
#define CSL_EVETPCC_IESR_RN_I12_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I12_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I24_MASK                            (0x01000000U)
#define CSL_EVETPCC_IESR_RN_I24_SHIFT                           (24U)
#define CSL_EVETPCC_IESR_RN_I24_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I24_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I15_MASK                            (0x00008000U)
#define CSL_EVETPCC_IESR_RN_I15_SHIFT                           (15U)
#define CSL_EVETPCC_IESR_RN_I15_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I15_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I1_MASK                             (0x00000002U)
#define CSL_EVETPCC_IESR_RN_I1_SHIFT                            (1U)
#define CSL_EVETPCC_IESR_RN_I1_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I1_MAX                              (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I25_MASK                            (0x02000000U)
#define CSL_EVETPCC_IESR_RN_I25_SHIFT                           (25U)
#define CSL_EVETPCC_IESR_RN_I25_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I25_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_I14_MASK                            (0x00004000U)
#define CSL_EVETPCC_IESR_RN_I14_SHIFT                           (14U)
#define CSL_EVETPCC_IESR_RN_I14_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IESR_RN_I14_MAX                             (0x00000001U)

#define CSL_EVETPCC_IESR_RN_RESETVAL                            (0x00000000U)

/* SECR_RN */

#define CSL_EVETPCC_SECR_RN_E21_MASK                            (0x00200000U)
#define CSL_EVETPCC_SECR_RN_E21_SHIFT                           (21U)
#define CSL_EVETPCC_SECR_RN_E21_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E21_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E29_MASK                            (0x20000000U)
#define CSL_EVETPCC_SECR_RN_E29_SHIFT                           (29U)
#define CSL_EVETPCC_SECR_RN_E29_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E29_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E20_MASK                            (0x00100000U)
#define CSL_EVETPCC_SECR_RN_E20_SHIFT                           (20U)
#define CSL_EVETPCC_SECR_RN_E20_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E20_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E0_MASK                             (0x00000001U)
#define CSL_EVETPCC_SECR_RN_E0_SHIFT                            (0U)
#define CSL_EVETPCC_SECR_RN_E0_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E0_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E10_MASK                            (0x00000400U)
#define CSL_EVETPCC_SECR_RN_E10_SHIFT                           (10U)
#define CSL_EVETPCC_SECR_RN_E10_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E10_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E9_MASK                             (0x00000200U)
#define CSL_EVETPCC_SECR_RN_E9_SHIFT                            (9U)
#define CSL_EVETPCC_SECR_RN_E9_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E9_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E27_MASK                            (0x08000000U)
#define CSL_EVETPCC_SECR_RN_E27_SHIFT                           (27U)
#define CSL_EVETPCC_SECR_RN_E27_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E27_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E2_MASK                             (0x00000004U)
#define CSL_EVETPCC_SECR_RN_E2_SHIFT                            (2U)
#define CSL_EVETPCC_SECR_RN_E2_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E2_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E12_MASK                            (0x00001000U)
#define CSL_EVETPCC_SECR_RN_E12_SHIFT                           (12U)
#define CSL_EVETPCC_SECR_RN_E12_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E12_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E28_MASK                            (0x10000000U)
#define CSL_EVETPCC_SECR_RN_E28_SHIFT                           (28U)
#define CSL_EVETPCC_SECR_RN_E28_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E28_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E1_MASK                             (0x00000002U)
#define CSL_EVETPCC_SECR_RN_E1_SHIFT                            (1U)
#define CSL_EVETPCC_SECR_RN_E1_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E1_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E11_MASK                            (0x00000800U)
#define CSL_EVETPCC_SECR_RN_E11_SHIFT                           (11U)
#define CSL_EVETPCC_SECR_RN_E11_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E11_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E25_MASK                            (0x02000000U)
#define CSL_EVETPCC_SECR_RN_E25_SHIFT                           (25U)
#define CSL_EVETPCC_SECR_RN_E25_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E25_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E4_MASK                             (0x00000010U)
#define CSL_EVETPCC_SECR_RN_E4_SHIFT                            (4U)
#define CSL_EVETPCC_SECR_RN_E4_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E4_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E14_MASK                            (0x00004000U)
#define CSL_EVETPCC_SECR_RN_E14_SHIFT                           (14U)
#define CSL_EVETPCC_SECR_RN_E14_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E14_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E26_MASK                            (0x04000000U)
#define CSL_EVETPCC_SECR_RN_E26_SHIFT                           (26U)
#define CSL_EVETPCC_SECR_RN_E26_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E26_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E3_MASK                             (0x00000008U)
#define CSL_EVETPCC_SECR_RN_E3_SHIFT                            (3U)
#define CSL_EVETPCC_SECR_RN_E3_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E3_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E13_MASK                            (0x00002000U)
#define CSL_EVETPCC_SECR_RN_E13_SHIFT                           (13U)
#define CSL_EVETPCC_SECR_RN_E13_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E13_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E6_MASK                             (0x00000040U)
#define CSL_EVETPCC_SECR_RN_E6_SHIFT                            (6U)
#define CSL_EVETPCC_SECR_RN_E6_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E6_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E16_MASK                            (0x00010000U)
#define CSL_EVETPCC_SECR_RN_E16_SHIFT                           (16U)
#define CSL_EVETPCC_SECR_RN_E16_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E16_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E24_MASK                            (0x01000000U)
#define CSL_EVETPCC_SECR_RN_E24_SHIFT                           (24U)
#define CSL_EVETPCC_SECR_RN_E24_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E24_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E5_MASK                             (0x00000020U)
#define CSL_EVETPCC_SECR_RN_E5_SHIFT                            (5U)
#define CSL_EVETPCC_SECR_RN_E5_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E5_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E15_MASK                            (0x00008000U)
#define CSL_EVETPCC_SECR_RN_E15_SHIFT                           (15U)
#define CSL_EVETPCC_SECR_RN_E15_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E15_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E18_MASK                            (0x00040000U)
#define CSL_EVETPCC_SECR_RN_E18_SHIFT                           (18U)
#define CSL_EVETPCC_SECR_RN_E18_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E18_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E31_MASK                            (0x80000000U)
#define CSL_EVETPCC_SECR_RN_E31_SHIFT                           (31U)
#define CSL_EVETPCC_SECR_RN_E31_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E31_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E8_MASK                             (0x00000100U)
#define CSL_EVETPCC_SECR_RN_E8_SHIFT                            (8U)
#define CSL_EVETPCC_SECR_RN_E8_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E8_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E22_MASK                            (0x00400000U)
#define CSL_EVETPCC_SECR_RN_E22_SHIFT                           (22U)
#define CSL_EVETPCC_SECR_RN_E22_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E22_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E7_MASK                             (0x00000080U)
#define CSL_EVETPCC_SECR_RN_E7_SHIFT                            (7U)
#define CSL_EVETPCC_SECR_RN_E7_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E7_MAX                              (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E19_MASK                            (0x00080000U)
#define CSL_EVETPCC_SECR_RN_E19_SHIFT                           (19U)
#define CSL_EVETPCC_SECR_RN_E19_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E19_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E17_MASK                            (0x00020000U)
#define CSL_EVETPCC_SECR_RN_E17_SHIFT                           (17U)
#define CSL_EVETPCC_SECR_RN_E17_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E17_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E23_MASK                            (0x00800000U)
#define CSL_EVETPCC_SECR_RN_E23_SHIFT                           (23U)
#define CSL_EVETPCC_SECR_RN_E23_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E23_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_E30_MASK                            (0x40000000U)
#define CSL_EVETPCC_SECR_RN_E30_SHIFT                           (30U)
#define CSL_EVETPCC_SECR_RN_E30_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_SECR_RN_E30_MAX                             (0x00000001U)

#define CSL_EVETPCC_SECR_RN_RESETVAL                            (0x00000000U)

/* EESR_RN */

#define CSL_EVETPCC_EESR_RN_E15_MASK                            (0x00008000U)
#define CSL_EVETPCC_EESR_RN_E15_SHIFT                           (15U)
#define CSL_EVETPCC_EESR_RN_E15_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E15_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E6_MASK                             (0x00000040U)
#define CSL_EVETPCC_EESR_RN_E6_SHIFT                            (6U)
#define CSL_EVETPCC_EESR_RN_E6_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E6_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E16_MASK                            (0x00010000U)
#define CSL_EVETPCC_EESR_RN_E16_SHIFT                           (16U)
#define CSL_EVETPCC_EESR_RN_E16_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E16_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E30_MASK                            (0x40000000U)
#define CSL_EVETPCC_EESR_RN_E30_SHIFT                           (30U)
#define CSL_EVETPCC_EESR_RN_E30_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E30_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E7_MASK                             (0x00000080U)
#define CSL_EVETPCC_EESR_RN_E7_SHIFT                            (7U)
#define CSL_EVETPCC_EESR_RN_E7_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E7_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E4_MASK                             (0x00000010U)
#define CSL_EVETPCC_EESR_RN_E4_SHIFT                            (4U)
#define CSL_EVETPCC_EESR_RN_E4_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E4_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E5_MASK                             (0x00000020U)
#define CSL_EVETPCC_EESR_RN_E5_SHIFT                            (5U)
#define CSL_EVETPCC_EESR_RN_E5_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E5_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E29_MASK                            (0x20000000U)
#define CSL_EVETPCC_EESR_RN_E29_SHIFT                           (29U)
#define CSL_EVETPCC_EESR_RN_E29_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E29_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E0_MASK                             (0x00000001U)
#define CSL_EVETPCC_EESR_RN_E0_SHIFT                            (0U)
#define CSL_EVETPCC_EESR_RN_E0_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E0_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E10_MASK                            (0x00000400U)
#define CSL_EVETPCC_EESR_RN_E10_SHIFT                           (10U)
#define CSL_EVETPCC_EESR_RN_E10_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E10_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E28_MASK                            (0x10000000U)
#define CSL_EVETPCC_EESR_RN_E28_SHIFT                           (28U)
#define CSL_EVETPCC_EESR_RN_E28_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E28_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E27_MASK                            (0x08000000U)
#define CSL_EVETPCC_EESR_RN_E27_SHIFT                           (27U)
#define CSL_EVETPCC_EESR_RN_E27_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E27_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E26_MASK                            (0x04000000U)
#define CSL_EVETPCC_EESR_RN_E26_SHIFT                           (26U)
#define CSL_EVETPCC_EESR_RN_E26_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E26_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E8_MASK                             (0x00000100U)
#define CSL_EVETPCC_EESR_RN_E8_SHIFT                            (8U)
#define CSL_EVETPCC_EESR_RN_E8_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E8_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E9_MASK                             (0x00000200U)
#define CSL_EVETPCC_EESR_RN_E9_SHIFT                            (9U)
#define CSL_EVETPCC_EESR_RN_E9_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E9_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E25_MASK                            (0x02000000U)
#define CSL_EVETPCC_EESR_RN_E25_SHIFT                           (25U)
#define CSL_EVETPCC_EESR_RN_E25_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E25_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E24_MASK                            (0x01000000U)
#define CSL_EVETPCC_EESR_RN_E24_SHIFT                           (24U)
#define CSL_EVETPCC_EESR_RN_E24_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E24_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E11_MASK                            (0x00000800U)
#define CSL_EVETPCC_EESR_RN_E11_SHIFT                           (11U)
#define CSL_EVETPCC_EESR_RN_E11_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E11_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E23_MASK                            (0x00800000U)
#define CSL_EVETPCC_EESR_RN_E23_SHIFT                           (23U)
#define CSL_EVETPCC_EESR_RN_E23_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E23_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E20_MASK                            (0x00100000U)
#define CSL_EVETPCC_EESR_RN_E20_SHIFT                           (20U)
#define CSL_EVETPCC_EESR_RN_E20_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E20_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E22_MASK                            (0x00400000U)
#define CSL_EVETPCC_EESR_RN_E22_SHIFT                           (22U)
#define CSL_EVETPCC_EESR_RN_E22_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E22_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E21_MASK                            (0x00200000U)
#define CSL_EVETPCC_EESR_RN_E21_SHIFT                           (21U)
#define CSL_EVETPCC_EESR_RN_E21_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E21_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E2_MASK                             (0x00000004U)
#define CSL_EVETPCC_EESR_RN_E2_SHIFT                            (2U)
#define CSL_EVETPCC_EESR_RN_E2_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E2_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E18_MASK                            (0x00040000U)
#define CSL_EVETPCC_EESR_RN_E18_SHIFT                           (18U)
#define CSL_EVETPCC_EESR_RN_E18_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E18_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E3_MASK                             (0x00000008U)
#define CSL_EVETPCC_EESR_RN_E3_SHIFT                            (3U)
#define CSL_EVETPCC_EESR_RN_E3_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E3_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E19_MASK                            (0x00080000U)
#define CSL_EVETPCC_EESR_RN_E19_SHIFT                           (19U)
#define CSL_EVETPCC_EESR_RN_E19_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E19_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E31_MASK                            (0x80000000U)
#define CSL_EVETPCC_EESR_RN_E31_SHIFT                           (31U)
#define CSL_EVETPCC_EESR_RN_E31_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E31_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E13_MASK                            (0x00002000U)
#define CSL_EVETPCC_EESR_RN_E13_SHIFT                           (13U)
#define CSL_EVETPCC_EESR_RN_E13_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E13_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E12_MASK                            (0x00001000U)
#define CSL_EVETPCC_EESR_RN_E12_SHIFT                           (12U)
#define CSL_EVETPCC_EESR_RN_E12_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E12_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E14_MASK                            (0x00004000U)
#define CSL_EVETPCC_EESR_RN_E14_SHIFT                           (14U)
#define CSL_EVETPCC_EESR_RN_E14_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E14_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E1_MASK                             (0x00000002U)
#define CSL_EVETPCC_EESR_RN_E1_SHIFT                            (1U)
#define CSL_EVETPCC_EESR_RN_E1_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E1_MAX                              (0x00000001U)

#define CSL_EVETPCC_EESR_RN_E17_MASK                            (0x00020000U)
#define CSL_EVETPCC_EESR_RN_E17_SHIFT                           (17U)
#define CSL_EVETPCC_EESR_RN_E17_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EESR_RN_E17_MAX                             (0x00000001U)

#define CSL_EVETPCC_EESR_RN_RESETVAL                            (0x00000000U)

/* QER_RN */

#define CSL_EVETPCC_QER_RN_E7_MASK                              (0x00000080U)
#define CSL_EVETPCC_QER_RN_E7_SHIFT                             (7U)
#define CSL_EVETPCC_QER_RN_E7_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_QER_RN_E7_MAX                               (0x00000001U)

#define CSL_EVETPCC_QER_RN_E6_MASK                              (0x00000040U)
#define CSL_EVETPCC_QER_RN_E6_SHIFT                             (6U)
#define CSL_EVETPCC_QER_RN_E6_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_QER_RN_E6_MAX                               (0x00000001U)

#define CSL_EVETPCC_QER_RN_E5_MASK                              (0x00000020U)
#define CSL_EVETPCC_QER_RN_E5_SHIFT                             (5U)
#define CSL_EVETPCC_QER_RN_E5_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_QER_RN_E5_MAX                               (0x00000001U)

#define CSL_EVETPCC_QER_RN_E3_MASK                              (0x00000008U)
#define CSL_EVETPCC_QER_RN_E3_SHIFT                             (3U)
#define CSL_EVETPCC_QER_RN_E3_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_QER_RN_E3_MAX                               (0x00000001U)

#define CSL_EVETPCC_QER_RN_E4_MASK                              (0x00000010U)
#define CSL_EVETPCC_QER_RN_E4_SHIFT                             (4U)
#define CSL_EVETPCC_QER_RN_E4_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_QER_RN_E4_MAX                               (0x00000001U)

#define CSL_EVETPCC_QER_RN_E1_MASK                              (0x00000002U)
#define CSL_EVETPCC_QER_RN_E1_SHIFT                             (1U)
#define CSL_EVETPCC_QER_RN_E1_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_QER_RN_E1_MAX                               (0x00000001U)

#define CSL_EVETPCC_QER_RN_E2_MASK                              (0x00000004U)
#define CSL_EVETPCC_QER_RN_E2_SHIFT                             (2U)
#define CSL_EVETPCC_QER_RN_E2_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_QER_RN_E2_MAX                               (0x00000001U)

#define CSL_EVETPCC_QER_RN_E0_MASK                              (0x00000001U)
#define CSL_EVETPCC_QER_RN_E0_SHIFT                             (0U)
#define CSL_EVETPCC_QER_RN_E0_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_QER_RN_E0_MAX                               (0x00000001U)

#define CSL_EVETPCC_QER_RN_RESETVAL                             (0x00000000U)

/* SECRH_RN */

#define CSL_EVETPCC_SECRH_RN_E34_MASK                           (0x00000004U)
#define CSL_EVETPCC_SECRH_RN_E34_SHIFT                          (2U)
#define CSL_EVETPCC_SECRH_RN_E34_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E34_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E44_MASK                           (0x00001000U)
#define CSL_EVETPCC_SECRH_RN_E44_SHIFT                          (12U)
#define CSL_EVETPCC_SECRH_RN_E44_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E44_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E54_MASK                           (0x00400000U)
#define CSL_EVETPCC_SECRH_RN_E54_SHIFT                          (22U)
#define CSL_EVETPCC_SECRH_RN_E54_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E54_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E33_MASK                           (0x00000002U)
#define CSL_EVETPCC_SECRH_RN_E33_SHIFT                          (1U)
#define CSL_EVETPCC_SECRH_RN_E33_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E33_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E43_MASK                           (0x00000800U)
#define CSL_EVETPCC_SECRH_RN_E43_SHIFT                          (11U)
#define CSL_EVETPCC_SECRH_RN_E43_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E43_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E53_MASK                           (0x00200000U)
#define CSL_EVETPCC_SECRH_RN_E53_SHIFT                          (21U)
#define CSL_EVETPCC_SECRH_RN_E53_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E53_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E58_MASK                           (0x04000000U)
#define CSL_EVETPCC_SECRH_RN_E58_SHIFT                          (26U)
#define CSL_EVETPCC_SECRH_RN_E58_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E58_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E32_MASK                           (0x00000001U)
#define CSL_EVETPCC_SECRH_RN_E32_SHIFT                          (0U)
#define CSL_EVETPCC_SECRH_RN_E32_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E32_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E63_MASK                           (0x80000000U)
#define CSL_EVETPCC_SECRH_RN_E63_SHIFT                          (31U)
#define CSL_EVETPCC_SECRH_RN_E63_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E63_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E57_MASK                           (0x02000000U)
#define CSL_EVETPCC_SECRH_RN_E57_SHIFT                          (25U)
#define CSL_EVETPCC_SECRH_RN_E57_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E57_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E56_MASK                           (0x01000000U)
#define CSL_EVETPCC_SECRH_RN_E56_SHIFT                          (24U)
#define CSL_EVETPCC_SECRH_RN_E56_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E56_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E55_MASK                           (0x00800000U)
#define CSL_EVETPCC_SECRH_RN_E55_SHIFT                          (23U)
#define CSL_EVETPCC_SECRH_RN_E55_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E55_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E52_MASK                           (0x00100000U)
#define CSL_EVETPCC_SECRH_RN_E52_SHIFT                          (20U)
#define CSL_EVETPCC_SECRH_RN_E52_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E52_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E42_MASK                           (0x00000400U)
#define CSL_EVETPCC_SECRH_RN_E42_SHIFT                          (10U)
#define CSL_EVETPCC_SECRH_RN_E42_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E42_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E51_MASK                           (0x00080000U)
#define CSL_EVETPCC_SECRH_RN_E51_SHIFT                          (19U)
#define CSL_EVETPCC_SECRH_RN_E51_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E51_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E41_MASK                           (0x00000200U)
#define CSL_EVETPCC_SECRH_RN_E41_SHIFT                          (9U)
#define CSL_EVETPCC_SECRH_RN_E41_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E41_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E50_MASK                           (0x00040000U)
#define CSL_EVETPCC_SECRH_RN_E50_SHIFT                          (18U)
#define CSL_EVETPCC_SECRH_RN_E50_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E50_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E40_MASK                           (0x00000100U)
#define CSL_EVETPCC_SECRH_RN_E40_SHIFT                          (8U)
#define CSL_EVETPCC_SECRH_RN_E40_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E40_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E49_MASK                           (0x00020000U)
#define CSL_EVETPCC_SECRH_RN_E49_SHIFT                          (17U)
#define CSL_EVETPCC_SECRH_RN_E49_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E49_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E39_MASK                           (0x00000080U)
#define CSL_EVETPCC_SECRH_RN_E39_SHIFT                          (7U)
#define CSL_EVETPCC_SECRH_RN_E39_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E39_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E48_MASK                           (0x00010000U)
#define CSL_EVETPCC_SECRH_RN_E48_SHIFT                          (16U)
#define CSL_EVETPCC_SECRH_RN_E48_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E48_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E38_MASK                           (0x00000040U)
#define CSL_EVETPCC_SECRH_RN_E38_SHIFT                          (6U)
#define CSL_EVETPCC_SECRH_RN_E38_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E38_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E59_MASK                           (0x08000000U)
#define CSL_EVETPCC_SECRH_RN_E59_SHIFT                          (27U)
#define CSL_EVETPCC_SECRH_RN_E59_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E59_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E47_MASK                           (0x00008000U)
#define CSL_EVETPCC_SECRH_RN_E47_SHIFT                          (15U)
#define CSL_EVETPCC_SECRH_RN_E47_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E47_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E37_MASK                           (0x00000020U)
#define CSL_EVETPCC_SECRH_RN_E37_SHIFT                          (5U)
#define CSL_EVETPCC_SECRH_RN_E37_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E37_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E60_MASK                           (0x10000000U)
#define CSL_EVETPCC_SECRH_RN_E60_SHIFT                          (28U)
#define CSL_EVETPCC_SECRH_RN_E60_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E60_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E36_MASK                           (0x00000010U)
#define CSL_EVETPCC_SECRH_RN_E36_SHIFT                          (4U)
#define CSL_EVETPCC_SECRH_RN_E36_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E36_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E46_MASK                           (0x00004000U)
#define CSL_EVETPCC_SECRH_RN_E46_SHIFT                          (14U)
#define CSL_EVETPCC_SECRH_RN_E46_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E46_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E61_MASK                           (0x20000000U)
#define CSL_EVETPCC_SECRH_RN_E61_SHIFT                          (29U)
#define CSL_EVETPCC_SECRH_RN_E61_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E61_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E35_MASK                           (0x00000008U)
#define CSL_EVETPCC_SECRH_RN_E35_SHIFT                          (3U)
#define CSL_EVETPCC_SECRH_RN_E35_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E35_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E62_MASK                           (0x40000000U)
#define CSL_EVETPCC_SECRH_RN_E62_SHIFT                          (30U)
#define CSL_EVETPCC_SECRH_RN_E62_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E62_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_E45_MASK                           (0x00002000U)
#define CSL_EVETPCC_SECRH_RN_E45_SHIFT                          (13U)
#define CSL_EVETPCC_SECRH_RN_E45_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_SECRH_RN_E45_MAX                            (0x00000001U)

#define CSL_EVETPCC_SECRH_RN_RESETVAL                           (0x00000000U)

/* EESRH_RN */

#define CSL_EVETPCC_EESRH_RN_E33_MASK                           (0x00000002U)
#define CSL_EVETPCC_EESRH_RN_E33_SHIFT                          (1U)
#define CSL_EVETPCC_EESRH_RN_E33_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E33_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E35_MASK                           (0x00000008U)
#define CSL_EVETPCC_EESRH_RN_E35_SHIFT                          (3U)
#define CSL_EVETPCC_EESRH_RN_E35_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E35_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E44_MASK                           (0x00001000U)
#define CSL_EVETPCC_EESRH_RN_E44_SHIFT                          (12U)
#define CSL_EVETPCC_EESRH_RN_E44_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E44_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E32_MASK                           (0x00000001U)
#define CSL_EVETPCC_EESRH_RN_E32_SHIFT                          (0U)
#define CSL_EVETPCC_EESRH_RN_E32_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E32_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E43_MASK                           (0x00000800U)
#define CSL_EVETPCC_EESRH_RN_E43_SHIFT                          (11U)
#define CSL_EVETPCC_EESRH_RN_E43_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E43_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E55_MASK                           (0x00800000U)
#define CSL_EVETPCC_EESRH_RN_E55_SHIFT                          (23U)
#define CSL_EVETPCC_EESRH_RN_E55_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E55_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E42_MASK                           (0x00000400U)
#define CSL_EVETPCC_EESRH_RN_E42_SHIFT                          (10U)
#define CSL_EVETPCC_EESRH_RN_E42_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E42_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E54_MASK                           (0x00400000U)
#define CSL_EVETPCC_EESRH_RN_E54_SHIFT                          (22U)
#define CSL_EVETPCC_EESRH_RN_E54_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E54_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E53_MASK                           (0x00200000U)
#define CSL_EVETPCC_EESRH_RN_E53_SHIFT                          (21U)
#define CSL_EVETPCC_EESRH_RN_E53_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E53_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E56_MASK                           (0x01000000U)
#define CSL_EVETPCC_EESRH_RN_E56_SHIFT                          (24U)
#define CSL_EVETPCC_EESRH_RN_E56_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E56_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E41_MASK                           (0x00000200U)
#define CSL_EVETPCC_EESRH_RN_E41_SHIFT                          (9U)
#define CSL_EVETPCC_EESRH_RN_E41_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E41_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E40_MASK                           (0x00000100U)
#define CSL_EVETPCC_EESRH_RN_E40_SHIFT                          (8U)
#define CSL_EVETPCC_EESRH_RN_E40_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E40_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E57_MASK                           (0x02000000U)
#define CSL_EVETPCC_EESRH_RN_E57_SHIFT                          (25U)
#define CSL_EVETPCC_EESRH_RN_E57_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E57_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E52_MASK                           (0x00100000U)
#define CSL_EVETPCC_EESRH_RN_E52_SHIFT                          (20U)
#define CSL_EVETPCC_EESRH_RN_E52_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E52_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E34_MASK                           (0x00000004U)
#define CSL_EVETPCC_EESRH_RN_E34_SHIFT                          (2U)
#define CSL_EVETPCC_EESRH_RN_E34_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E34_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E39_MASK                           (0x00000080U)
#define CSL_EVETPCC_EESRH_RN_E39_SHIFT                          (7U)
#define CSL_EVETPCC_EESRH_RN_E39_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E39_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E58_MASK                           (0x04000000U)
#define CSL_EVETPCC_EESRH_RN_E58_SHIFT                          (26U)
#define CSL_EVETPCC_EESRH_RN_E58_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E58_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E51_MASK                           (0x00080000U)
#define CSL_EVETPCC_EESRH_RN_E51_SHIFT                          (19U)
#define CSL_EVETPCC_EESRH_RN_E51_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E51_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E36_MASK                           (0x00000010U)
#define CSL_EVETPCC_EESRH_RN_E36_SHIFT                          (4U)
#define CSL_EVETPCC_EESRH_RN_E36_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E36_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E38_MASK                           (0x00000040U)
#define CSL_EVETPCC_EESRH_RN_E38_SHIFT                          (6U)
#define CSL_EVETPCC_EESRH_RN_E38_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E38_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E59_MASK                           (0x08000000U)
#define CSL_EVETPCC_EESRH_RN_E59_SHIFT                          (27U)
#define CSL_EVETPCC_EESRH_RN_E59_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E59_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E50_MASK                           (0x00040000U)
#define CSL_EVETPCC_EESRH_RN_E50_SHIFT                          (18U)
#define CSL_EVETPCC_EESRH_RN_E50_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E50_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E37_MASK                           (0x00000020U)
#define CSL_EVETPCC_EESRH_RN_E37_SHIFT                          (5U)
#define CSL_EVETPCC_EESRH_RN_E37_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E37_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E60_MASK                           (0x10000000U)
#define CSL_EVETPCC_EESRH_RN_E60_SHIFT                          (28U)
#define CSL_EVETPCC_EESRH_RN_E60_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E60_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E49_MASK                           (0x00020000U)
#define CSL_EVETPCC_EESRH_RN_E49_SHIFT                          (17U)
#define CSL_EVETPCC_EESRH_RN_E49_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E49_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E61_MASK                           (0x20000000U)
#define CSL_EVETPCC_EESRH_RN_E61_SHIFT                          (29U)
#define CSL_EVETPCC_EESRH_RN_E61_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E61_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E48_MASK                           (0x00010000U)
#define CSL_EVETPCC_EESRH_RN_E48_SHIFT                          (16U)
#define CSL_EVETPCC_EESRH_RN_E48_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E48_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E62_MASK                           (0x40000000U)
#define CSL_EVETPCC_EESRH_RN_E62_SHIFT                          (30U)
#define CSL_EVETPCC_EESRH_RN_E62_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E62_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E47_MASK                           (0x00008000U)
#define CSL_EVETPCC_EESRH_RN_E47_SHIFT                          (15U)
#define CSL_EVETPCC_EESRH_RN_E47_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E47_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E63_MASK                           (0x80000000U)
#define CSL_EVETPCC_EESRH_RN_E63_SHIFT                          (31U)
#define CSL_EVETPCC_EESRH_RN_E63_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E63_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E46_MASK                           (0x00004000U)
#define CSL_EVETPCC_EESRH_RN_E46_SHIFT                          (14U)
#define CSL_EVETPCC_EESRH_RN_E46_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E46_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_E45_MASK                           (0x00002000U)
#define CSL_EVETPCC_EESRH_RN_E45_SHIFT                          (13U)
#define CSL_EVETPCC_EESRH_RN_E45_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_EESRH_RN_E45_MAX                            (0x00000001U)

#define CSL_EVETPCC_EESRH_RN_RESETVAL                           (0x00000000U)

/* IER_RN */

#define CSL_EVETPCC_IER_RN_I15_MASK                             (0x00008000U)
#define CSL_EVETPCC_IER_RN_I15_SHIFT                            (15U)
#define CSL_EVETPCC_IER_RN_I15_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I15_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I30_MASK                             (0x40000000U)
#define CSL_EVETPCC_IER_RN_I30_SHIFT                            (30U)
#define CSL_EVETPCC_IER_RN_I30_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I30_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I14_MASK                             (0x00004000U)
#define CSL_EVETPCC_IER_RN_I14_SHIFT                            (14U)
#define CSL_EVETPCC_IER_RN_I14_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I14_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I29_MASK                             (0x20000000U)
#define CSL_EVETPCC_IER_RN_I29_SHIFT                            (29U)
#define CSL_EVETPCC_IER_RN_I29_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I29_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I7_MASK                              (0x00000080U)
#define CSL_EVETPCC_IER_RN_I7_SHIFT                             (7U)
#define CSL_EVETPCC_IER_RN_I7_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I7_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I28_MASK                             (0x10000000U)
#define CSL_EVETPCC_IER_RN_I28_SHIFT                            (28U)
#define CSL_EVETPCC_IER_RN_I28_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I28_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I17_MASK                             (0x00020000U)
#define CSL_EVETPCC_IER_RN_I17_SHIFT                            (17U)
#define CSL_EVETPCC_IER_RN_I17_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I17_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I16_MASK                             (0x00010000U)
#define CSL_EVETPCC_IER_RN_I16_SHIFT                            (16U)
#define CSL_EVETPCC_IER_RN_I16_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I16_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I27_MASK                             (0x08000000U)
#define CSL_EVETPCC_IER_RN_I27_SHIFT                            (27U)
#define CSL_EVETPCC_IER_RN_I27_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I27_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I0_MASK                              (0x00000001U)
#define CSL_EVETPCC_IER_RN_I0_SHIFT                             (0U)
#define CSL_EVETPCC_IER_RN_I0_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I0_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I1_MASK                              (0x00000002U)
#define CSL_EVETPCC_IER_RN_I1_SHIFT                             (1U)
#define CSL_EVETPCC_IER_RN_I1_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I1_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I13_MASK                             (0x00002000U)
#define CSL_EVETPCC_IER_RN_I13_SHIFT                            (13U)
#define CSL_EVETPCC_IER_RN_I13_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I13_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I2_MASK                              (0x00000004U)
#define CSL_EVETPCC_IER_RN_I2_SHIFT                             (2U)
#define CSL_EVETPCC_IER_RN_I2_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I2_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I31_MASK                             (0x80000000U)
#define CSL_EVETPCC_IER_RN_I31_SHIFT                            (31U)
#define CSL_EVETPCC_IER_RN_I31_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I31_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I22_MASK                             (0x00400000U)
#define CSL_EVETPCC_IER_RN_I22_SHIFT                            (22U)
#define CSL_EVETPCC_IER_RN_I22_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I22_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I3_MASK                              (0x00000008U)
#define CSL_EVETPCC_IER_RN_I3_SHIFT                             (3U)
#define CSL_EVETPCC_IER_RN_I3_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I3_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I26_MASK                             (0x04000000U)
#define CSL_EVETPCC_IER_RN_I26_SHIFT                            (26U)
#define CSL_EVETPCC_IER_RN_I26_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I26_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I5_MASK                              (0x00000020U)
#define CSL_EVETPCC_IER_RN_I5_SHIFT                             (5U)
#define CSL_EVETPCC_IER_RN_I5_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I5_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I19_MASK                             (0x00080000U)
#define CSL_EVETPCC_IER_RN_I19_SHIFT                            (19U)
#define CSL_EVETPCC_IER_RN_I19_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I19_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I8_MASK                              (0x00000100U)
#define CSL_EVETPCC_IER_RN_I8_SHIFT                             (8U)
#define CSL_EVETPCC_IER_RN_I8_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I8_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I25_MASK                             (0x02000000U)
#define CSL_EVETPCC_IER_RN_I25_SHIFT                            (25U)
#define CSL_EVETPCC_IER_RN_I25_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I25_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I4_MASK                              (0x00000010U)
#define CSL_EVETPCC_IER_RN_I4_SHIFT                             (4U)
#define CSL_EVETPCC_IER_RN_I4_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I4_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I18_MASK                             (0x00040000U)
#define CSL_EVETPCC_IER_RN_I18_SHIFT                            (18U)
#define CSL_EVETPCC_IER_RN_I18_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I18_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I9_MASK                              (0x00000200U)
#define CSL_EVETPCC_IER_RN_I9_SHIFT                             (9U)
#define CSL_EVETPCC_IER_RN_I9_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I9_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I21_MASK                             (0x00200000U)
#define CSL_EVETPCC_IER_RN_I21_SHIFT                            (21U)
#define CSL_EVETPCC_IER_RN_I21_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I21_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I24_MASK                             (0x01000000U)
#define CSL_EVETPCC_IER_RN_I24_SHIFT                            (24U)
#define CSL_EVETPCC_IER_RN_I24_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I24_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I10_MASK                             (0x00000400U)
#define CSL_EVETPCC_IER_RN_I10_SHIFT                            (10U)
#define CSL_EVETPCC_IER_RN_I10_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I10_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I12_MASK                             (0x00001000U)
#define CSL_EVETPCC_IER_RN_I12_SHIFT                            (12U)
#define CSL_EVETPCC_IER_RN_I12_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I12_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I23_MASK                             (0x00800000U)
#define CSL_EVETPCC_IER_RN_I23_SHIFT                            (23U)
#define CSL_EVETPCC_IER_RN_I23_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I23_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I20_MASK                             (0x00100000U)
#define CSL_EVETPCC_IER_RN_I20_SHIFT                            (20U)
#define CSL_EVETPCC_IER_RN_I20_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I20_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_I6_MASK                              (0x00000040U)
#define CSL_EVETPCC_IER_RN_I6_SHIFT                             (6U)
#define CSL_EVETPCC_IER_RN_I6_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IER_RN_I6_MAX                               (0x00000001U)

#define CSL_EVETPCC_IER_RN_I11_MASK                             (0x00000800U)
#define CSL_EVETPCC_IER_RN_I11_SHIFT                            (11U)
#define CSL_EVETPCC_IER_RN_I11_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IER_RN_I11_MAX                              (0x00000001U)

#define CSL_EVETPCC_IER_RN_RESETVAL                             (0x00000000U)

/* QEECR_RN */

#define CSL_EVETPCC_QEECR_RN_E3_MASK                            (0x00000008U)
#define CSL_EVETPCC_QEECR_RN_E3_SHIFT                           (3U)
#define CSL_EVETPCC_QEECR_RN_E3_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEECR_RN_E3_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEECR_RN_E2_MASK                            (0x00000004U)
#define CSL_EVETPCC_QEECR_RN_E2_SHIFT                           (2U)
#define CSL_EVETPCC_QEECR_RN_E2_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEECR_RN_E2_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEECR_RN_E1_MASK                            (0x00000002U)
#define CSL_EVETPCC_QEECR_RN_E1_SHIFT                           (1U)
#define CSL_EVETPCC_QEECR_RN_E1_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEECR_RN_E1_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEECR_RN_E4_MASK                            (0x00000010U)
#define CSL_EVETPCC_QEECR_RN_E4_SHIFT                           (4U)
#define CSL_EVETPCC_QEECR_RN_E4_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEECR_RN_E4_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEECR_RN_E0_MASK                            (0x00000001U)
#define CSL_EVETPCC_QEECR_RN_E0_SHIFT                           (0U)
#define CSL_EVETPCC_QEECR_RN_E0_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEECR_RN_E0_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEECR_RN_E6_MASK                            (0x00000040U)
#define CSL_EVETPCC_QEECR_RN_E6_SHIFT                           (6U)
#define CSL_EVETPCC_QEECR_RN_E6_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEECR_RN_E6_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEECR_RN_E5_MASK                            (0x00000020U)
#define CSL_EVETPCC_QEECR_RN_E5_SHIFT                           (5U)
#define CSL_EVETPCC_QEECR_RN_E5_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEECR_RN_E5_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEECR_RN_E7_MASK                            (0x00000080U)
#define CSL_EVETPCC_QEECR_RN_E7_SHIFT                           (7U)
#define CSL_EVETPCC_QEECR_RN_E7_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEECR_RN_E7_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEECR_RN_RESETVAL                           (0x00000000U)

/* EER_RN */

#define CSL_EVETPCC_EER_RN_E11_MASK                             (0x00000800U)
#define CSL_EVETPCC_EER_RN_E11_SHIFT                            (11U)
#define CSL_EVETPCC_EER_RN_E11_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E11_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E24_MASK                             (0x01000000U)
#define CSL_EVETPCC_EER_RN_E24_SHIFT                            (24U)
#define CSL_EVETPCC_EER_RN_E24_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E24_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E10_MASK                             (0x00000400U)
#define CSL_EVETPCC_EER_RN_E10_SHIFT                            (10U)
#define CSL_EVETPCC_EER_RN_E10_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E10_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E12_MASK                             (0x00001000U)
#define CSL_EVETPCC_EER_RN_E12_SHIFT                            (12U)
#define CSL_EVETPCC_EER_RN_E12_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E12_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E25_MASK                             (0x02000000U)
#define CSL_EVETPCC_EER_RN_E25_SHIFT                            (25U)
#define CSL_EVETPCC_EER_RN_E25_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E25_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E9_MASK                              (0x00000200U)
#define CSL_EVETPCC_EER_RN_E9_SHIFT                             (9U)
#define CSL_EVETPCC_EER_RN_E9_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E9_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E21_MASK                             (0x00200000U)
#define CSL_EVETPCC_EER_RN_E21_SHIFT                            (21U)
#define CSL_EVETPCC_EER_RN_E21_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E21_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E22_MASK                             (0x00400000U)
#define CSL_EVETPCC_EER_RN_E22_SHIFT                            (22U)
#define CSL_EVETPCC_EER_RN_E22_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E22_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E0_MASK                              (0x00000001U)
#define CSL_EVETPCC_EER_RN_E0_SHIFT                             (0U)
#define CSL_EVETPCC_EER_RN_E0_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E0_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E23_MASK                             (0x00800000U)
#define CSL_EVETPCC_EER_RN_E23_SHIFT                            (23U)
#define CSL_EVETPCC_EER_RN_E23_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E23_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E19_MASK                             (0x00080000U)
#define CSL_EVETPCC_EER_RN_E19_SHIFT                            (19U)
#define CSL_EVETPCC_EER_RN_E19_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E19_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E20_MASK                             (0x00100000U)
#define CSL_EVETPCC_EER_RN_E20_SHIFT                            (20U)
#define CSL_EVETPCC_EER_RN_E20_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E20_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E29_MASK                             (0x20000000U)
#define CSL_EVETPCC_EER_RN_E29_SHIFT                            (29U)
#define CSL_EVETPCC_EER_RN_E29_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E29_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E30_MASK                             (0x40000000U)
#define CSL_EVETPCC_EER_RN_E30_SHIFT                            (30U)
#define CSL_EVETPCC_EER_RN_E30_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E30_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E18_MASK                             (0x00040000U)
#define CSL_EVETPCC_EER_RN_E18_SHIFT                            (18U)
#define CSL_EVETPCC_EER_RN_E18_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E18_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E31_MASK                             (0x80000000U)
#define CSL_EVETPCC_EER_RN_E31_SHIFT                            (31U)
#define CSL_EVETPCC_EER_RN_E31_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E31_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E5_MASK                              (0x00000020U)
#define CSL_EVETPCC_EER_RN_E5_SHIFT                             (5U)
#define CSL_EVETPCC_EER_RN_E5_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E5_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E6_MASK                              (0x00000040U)
#define CSL_EVETPCC_EER_RN_E6_SHIFT                             (6U)
#define CSL_EVETPCC_EER_RN_E6_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E6_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E8_MASK                              (0x00000100U)
#define CSL_EVETPCC_EER_RN_E8_SHIFT                             (8U)
#define CSL_EVETPCC_EER_RN_E8_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E8_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E7_MASK                              (0x00000080U)
#define CSL_EVETPCC_EER_RN_E7_SHIFT                             (7U)
#define CSL_EVETPCC_EER_RN_E7_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E7_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E28_MASK                             (0x10000000U)
#define CSL_EVETPCC_EER_RN_E28_SHIFT                            (28U)
#define CSL_EVETPCC_EER_RN_E28_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E28_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E3_MASK                              (0x00000008U)
#define CSL_EVETPCC_EER_RN_E3_SHIFT                             (3U)
#define CSL_EVETPCC_EER_RN_E3_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E3_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E2_MASK                              (0x00000004U)
#define CSL_EVETPCC_EER_RN_E2_SHIFT                             (2U)
#define CSL_EVETPCC_EER_RN_E2_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E2_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E1_MASK                              (0x00000002U)
#define CSL_EVETPCC_EER_RN_E1_SHIFT                             (1U)
#define CSL_EVETPCC_EER_RN_E1_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E1_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E13_MASK                             (0x00002000U)
#define CSL_EVETPCC_EER_RN_E13_SHIFT                            (13U)
#define CSL_EVETPCC_EER_RN_E13_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E13_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E17_MASK                             (0x00020000U)
#define CSL_EVETPCC_EER_RN_E17_SHIFT                            (17U)
#define CSL_EVETPCC_EER_RN_E17_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E17_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E26_MASK                             (0x04000000U)
#define CSL_EVETPCC_EER_RN_E26_SHIFT                            (26U)
#define CSL_EVETPCC_EER_RN_E26_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E26_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E14_MASK                             (0x00004000U)
#define CSL_EVETPCC_EER_RN_E14_SHIFT                            (14U)
#define CSL_EVETPCC_EER_RN_E14_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E14_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E16_MASK                             (0x00010000U)
#define CSL_EVETPCC_EER_RN_E16_SHIFT                            (16U)
#define CSL_EVETPCC_EER_RN_E16_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E16_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E27_MASK                             (0x08000000U)
#define CSL_EVETPCC_EER_RN_E27_SHIFT                            (27U)
#define CSL_EVETPCC_EER_RN_E27_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E27_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_E4_MASK                              (0x00000010U)
#define CSL_EVETPCC_EER_RN_E4_SHIFT                             (4U)
#define CSL_EVETPCC_EER_RN_E4_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_EER_RN_E4_MAX                               (0x00000001U)

#define CSL_EVETPCC_EER_RN_E15_MASK                             (0x00008000U)
#define CSL_EVETPCC_EER_RN_E15_SHIFT                            (15U)
#define CSL_EVETPCC_EER_RN_E15_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_EER_RN_E15_MAX                              (0x00000001U)

#define CSL_EVETPCC_EER_RN_RESETVAL                             (0x00000000U)

/* CERH_RN */

#define CSL_EVETPCC_CERH_RN_E49_MASK                            (0x00020000U)
#define CSL_EVETPCC_CERH_RN_E49_SHIFT                           (17U)
#define CSL_EVETPCC_CERH_RN_E49_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E49_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E38_MASK                            (0x00000040U)
#define CSL_EVETPCC_CERH_RN_E38_SHIFT                           (6U)
#define CSL_EVETPCC_CERH_RN_E38_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E38_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E39_MASK                            (0x00000080U)
#define CSL_EVETPCC_CERH_RN_E39_SHIFT                           (7U)
#define CSL_EVETPCC_CERH_RN_E39_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E39_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E40_MASK                            (0x00000100U)
#define CSL_EVETPCC_CERH_RN_E40_SHIFT                           (8U)
#define CSL_EVETPCC_CERH_RN_E40_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E40_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E63_MASK                            (0x80000000U)
#define CSL_EVETPCC_CERH_RN_E63_SHIFT                           (31U)
#define CSL_EVETPCC_CERH_RN_E63_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E63_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E41_MASK                            (0x00000200U)
#define CSL_EVETPCC_CERH_RN_E41_SHIFT                           (9U)
#define CSL_EVETPCC_CERH_RN_E41_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E41_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E62_MASK                            (0x40000000U)
#define CSL_EVETPCC_CERH_RN_E62_SHIFT                           (30U)
#define CSL_EVETPCC_CERH_RN_E62_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E62_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E61_MASK                            (0x20000000U)
#define CSL_EVETPCC_CERH_RN_E61_SHIFT                           (29U)
#define CSL_EVETPCC_CERH_RN_E61_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E61_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E42_MASK                            (0x00000400U)
#define CSL_EVETPCC_CERH_RN_E42_SHIFT                           (10U)
#define CSL_EVETPCC_CERH_RN_E42_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E42_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E32_MASK                            (0x00000001U)
#define CSL_EVETPCC_CERH_RN_E32_SHIFT                           (0U)
#define CSL_EVETPCC_CERH_RN_E32_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E32_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E57_MASK                            (0x02000000U)
#define CSL_EVETPCC_CERH_RN_E57_SHIFT                           (25U)
#define CSL_EVETPCC_CERH_RN_E57_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E57_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E43_MASK                            (0x00000800U)
#define CSL_EVETPCC_CERH_RN_E43_SHIFT                           (11U)
#define CSL_EVETPCC_CERH_RN_E43_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E43_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E58_MASK                            (0x04000000U)
#define CSL_EVETPCC_CERH_RN_E58_SHIFT                           (26U)
#define CSL_EVETPCC_CERH_RN_E58_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E58_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E44_MASK                            (0x00001000U)
#define CSL_EVETPCC_CERH_RN_E44_SHIFT                           (12U)
#define CSL_EVETPCC_CERH_RN_E44_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E44_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E59_MASK                            (0x08000000U)
#define CSL_EVETPCC_CERH_RN_E59_SHIFT                           (27U)
#define CSL_EVETPCC_CERH_RN_E59_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E59_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E60_MASK                            (0x10000000U)
#define CSL_EVETPCC_CERH_RN_E60_SHIFT                           (28U)
#define CSL_EVETPCC_CERH_RN_E60_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E60_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E45_MASK                            (0x00002000U)
#define CSL_EVETPCC_CERH_RN_E45_SHIFT                           (13U)
#define CSL_EVETPCC_CERH_RN_E45_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E45_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E33_MASK                            (0x00000002U)
#define CSL_EVETPCC_CERH_RN_E33_SHIFT                           (1U)
#define CSL_EVETPCC_CERH_RN_E33_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E33_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E46_MASK                            (0x00004000U)
#define CSL_EVETPCC_CERH_RN_E46_SHIFT                           (14U)
#define CSL_EVETPCC_CERH_RN_E46_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E46_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E34_MASK                            (0x00000004U)
#define CSL_EVETPCC_CERH_RN_E34_SHIFT                           (2U)
#define CSL_EVETPCC_CERH_RN_E34_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E34_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E47_MASK                            (0x00008000U)
#define CSL_EVETPCC_CERH_RN_E47_SHIFT                           (15U)
#define CSL_EVETPCC_CERH_RN_E47_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E47_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E53_MASK                            (0x00200000U)
#define CSL_EVETPCC_CERH_RN_E53_SHIFT                           (21U)
#define CSL_EVETPCC_CERH_RN_E53_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E53_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E54_MASK                            (0x00400000U)
#define CSL_EVETPCC_CERH_RN_E54_SHIFT                           (22U)
#define CSL_EVETPCC_CERH_RN_E54_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E54_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E50_MASK                            (0x00040000U)
#define CSL_EVETPCC_CERH_RN_E50_SHIFT                           (18U)
#define CSL_EVETPCC_CERH_RN_E50_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E50_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E35_MASK                            (0x00000008U)
#define CSL_EVETPCC_CERH_RN_E35_SHIFT                           (3U)
#define CSL_EVETPCC_CERH_RN_E35_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E35_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E48_MASK                            (0x00010000U)
#define CSL_EVETPCC_CERH_RN_E48_SHIFT                           (16U)
#define CSL_EVETPCC_CERH_RN_E48_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E48_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E56_MASK                            (0x01000000U)
#define CSL_EVETPCC_CERH_RN_E56_SHIFT                           (24U)
#define CSL_EVETPCC_CERH_RN_E56_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E56_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E51_MASK                            (0x00080000U)
#define CSL_EVETPCC_CERH_RN_E51_SHIFT                           (19U)
#define CSL_EVETPCC_CERH_RN_E51_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E51_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E36_MASK                            (0x00000010U)
#define CSL_EVETPCC_CERH_RN_E36_SHIFT                           (4U)
#define CSL_EVETPCC_CERH_RN_E36_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E36_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E55_MASK                            (0x00800000U)
#define CSL_EVETPCC_CERH_RN_E55_SHIFT                           (23U)
#define CSL_EVETPCC_CERH_RN_E55_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E55_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E52_MASK                            (0x00100000U)
#define CSL_EVETPCC_CERH_RN_E52_SHIFT                           (20U)
#define CSL_EVETPCC_CERH_RN_E52_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E52_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_E37_MASK                            (0x00000020U)
#define CSL_EVETPCC_CERH_RN_E37_SHIFT                           (5U)
#define CSL_EVETPCC_CERH_RN_E37_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_CERH_RN_E37_MAX                             (0x00000001U)

#define CSL_EVETPCC_CERH_RN_RESETVAL                            (0x00000000U)

/* QEER_RN */

#define CSL_EVETPCC_QEER_RN_E6_MASK                             (0x00000040U)
#define CSL_EVETPCC_QEER_RN_E6_SHIFT                            (6U)
#define CSL_EVETPCC_QEER_RN_E6_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QEER_RN_E6_MAX                              (0x00000001U)

#define CSL_EVETPCC_QEER_RN_E5_MASK                             (0x00000020U)
#define CSL_EVETPCC_QEER_RN_E5_SHIFT                            (5U)
#define CSL_EVETPCC_QEER_RN_E5_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QEER_RN_E5_MAX                              (0x00000001U)

#define CSL_EVETPCC_QEER_RN_E7_MASK                             (0x00000080U)
#define CSL_EVETPCC_QEER_RN_E7_SHIFT                            (7U)
#define CSL_EVETPCC_QEER_RN_E7_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QEER_RN_E7_MAX                              (0x00000001U)

#define CSL_EVETPCC_QEER_RN_E0_MASK                             (0x00000001U)
#define CSL_EVETPCC_QEER_RN_E0_SHIFT                            (0U)
#define CSL_EVETPCC_QEER_RN_E0_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QEER_RN_E0_MAX                              (0x00000001U)

#define CSL_EVETPCC_QEER_RN_E2_MASK                             (0x00000004U)
#define CSL_EVETPCC_QEER_RN_E2_SHIFT                            (2U)
#define CSL_EVETPCC_QEER_RN_E2_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QEER_RN_E2_MAX                              (0x00000001U)

#define CSL_EVETPCC_QEER_RN_E1_MASK                             (0x00000002U)
#define CSL_EVETPCC_QEER_RN_E1_SHIFT                            (1U)
#define CSL_EVETPCC_QEER_RN_E1_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QEER_RN_E1_MAX                              (0x00000001U)

#define CSL_EVETPCC_QEER_RN_E4_MASK                             (0x00000010U)
#define CSL_EVETPCC_QEER_RN_E4_SHIFT                            (4U)
#define CSL_EVETPCC_QEER_RN_E4_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QEER_RN_E4_MAX                              (0x00000001U)

#define CSL_EVETPCC_QEER_RN_E3_MASK                             (0x00000008U)
#define CSL_EVETPCC_QEER_RN_E3_SHIFT                            (3U)
#define CSL_EVETPCC_QEER_RN_E3_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QEER_RN_E3_MAX                              (0x00000001U)

#define CSL_EVETPCC_QEER_RN_RESETVAL                            (0x00000000U)

/* QSECR_RN */

#define CSL_EVETPCC_QSECR_RN_E5_MASK                            (0x00000020U)
#define CSL_EVETPCC_QSECR_RN_E5_SHIFT                           (5U)
#define CSL_EVETPCC_QSECR_RN_E5_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QSECR_RN_E5_MAX                             (0x00000001U)

#define CSL_EVETPCC_QSECR_RN_E6_MASK                            (0x00000040U)
#define CSL_EVETPCC_QSECR_RN_E6_SHIFT                           (6U)
#define CSL_EVETPCC_QSECR_RN_E6_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QSECR_RN_E6_MAX                             (0x00000001U)

#define CSL_EVETPCC_QSECR_RN_E7_MASK                            (0x00000080U)
#define CSL_EVETPCC_QSECR_RN_E7_SHIFT                           (7U)
#define CSL_EVETPCC_QSECR_RN_E7_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QSECR_RN_E7_MAX                             (0x00000001U)

#define CSL_EVETPCC_QSECR_RN_E0_MASK                            (0x00000001U)
#define CSL_EVETPCC_QSECR_RN_E0_SHIFT                           (0U)
#define CSL_EVETPCC_QSECR_RN_E0_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QSECR_RN_E0_MAX                             (0x00000001U)

#define CSL_EVETPCC_QSECR_RN_E2_MASK                            (0x00000004U)
#define CSL_EVETPCC_QSECR_RN_E2_SHIFT                           (2U)
#define CSL_EVETPCC_QSECR_RN_E2_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QSECR_RN_E2_MAX                             (0x00000001U)

#define CSL_EVETPCC_QSECR_RN_E1_MASK                            (0x00000002U)
#define CSL_EVETPCC_QSECR_RN_E1_SHIFT                           (1U)
#define CSL_EVETPCC_QSECR_RN_E1_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QSECR_RN_E1_MAX                             (0x00000001U)

#define CSL_EVETPCC_QSECR_RN_E4_MASK                            (0x00000010U)
#define CSL_EVETPCC_QSECR_RN_E4_SHIFT                           (4U)
#define CSL_EVETPCC_QSECR_RN_E4_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QSECR_RN_E4_MAX                             (0x00000001U)

#define CSL_EVETPCC_QSECR_RN_E3_MASK                            (0x00000008U)
#define CSL_EVETPCC_QSECR_RN_E3_SHIFT                           (3U)
#define CSL_EVETPCC_QSECR_RN_E3_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QSECR_RN_E3_MAX                             (0x00000001U)

#define CSL_EVETPCC_QSECR_RN_RESETVAL                           (0x00000000U)

/* ECRH_RN */

#define CSL_EVETPCC_ECRH_RN_E50_MASK                            (0x00040000U)
#define CSL_EVETPCC_ECRH_RN_E50_SHIFT                           (18U)
#define CSL_EVETPCC_ECRH_RN_E50_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E50_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E36_MASK                            (0x00000010U)
#define CSL_EVETPCC_ECRH_RN_E36_SHIFT                           (4U)
#define CSL_EVETPCC_ECRH_RN_E36_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E36_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E60_MASK                            (0x10000000U)
#define CSL_EVETPCC_ECRH_RN_E60_SHIFT                           (28U)
#define CSL_EVETPCC_ECRH_RN_E60_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E60_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E49_MASK                            (0x00020000U)
#define CSL_EVETPCC_ECRH_RN_E49_SHIFT                           (17U)
#define CSL_EVETPCC_ECRH_RN_E49_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E49_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E37_MASK                            (0x00000020U)
#define CSL_EVETPCC_ECRH_RN_E37_SHIFT                           (5U)
#define CSL_EVETPCC_ECRH_RN_E37_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E37_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E48_MASK                            (0x00010000U)
#define CSL_EVETPCC_ECRH_RN_E48_SHIFT                           (16U)
#define CSL_EVETPCC_ECRH_RN_E48_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E48_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E58_MASK                            (0x04000000U)
#define CSL_EVETPCC_ECRH_RN_E58_SHIFT                           (26U)
#define CSL_EVETPCC_ECRH_RN_E58_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E58_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E38_MASK                            (0x00000040U)
#define CSL_EVETPCC_ECRH_RN_E38_SHIFT                           (6U)
#define CSL_EVETPCC_ECRH_RN_E38_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E38_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E63_MASK                            (0x80000000U)
#define CSL_EVETPCC_ECRH_RN_E63_SHIFT                           (31U)
#define CSL_EVETPCC_ECRH_RN_E63_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E63_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E47_MASK                            (0x00008000U)
#define CSL_EVETPCC_ECRH_RN_E47_SHIFT                           (15U)
#define CSL_EVETPCC_ECRH_RN_E47_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E47_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E39_MASK                            (0x00000080U)
#define CSL_EVETPCC_ECRH_RN_E39_SHIFT                           (7U)
#define CSL_EVETPCC_ECRH_RN_E39_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E39_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E32_MASK                            (0x00000001U)
#define CSL_EVETPCC_ECRH_RN_E32_SHIFT                           (0U)
#define CSL_EVETPCC_ECRH_RN_E32_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E32_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E51_MASK                            (0x00080000U)
#define CSL_EVETPCC_ECRH_RN_E51_SHIFT                           (19U)
#define CSL_EVETPCC_ECRH_RN_E51_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E51_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E33_MASK                            (0x00000002U)
#define CSL_EVETPCC_ECRH_RN_E33_SHIFT                           (1U)
#define CSL_EVETPCC_ECRH_RN_E33_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E33_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E34_MASK                            (0x00000004U)
#define CSL_EVETPCC_ECRH_RN_E34_SHIFT                           (2U)
#define CSL_EVETPCC_ECRH_RN_E34_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E34_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E35_MASK                            (0x00000008U)
#define CSL_EVETPCC_ECRH_RN_E35_SHIFT                           (3U)
#define CSL_EVETPCC_ECRH_RN_E35_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E35_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E42_MASK                            (0x00000400U)
#define CSL_EVETPCC_ECRH_RN_E42_SHIFT                           (10U)
#define CSL_EVETPCC_ECRH_RN_E42_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E42_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E52_MASK                            (0x00100000U)
#define CSL_EVETPCC_ECRH_RN_E52_SHIFT                           (20U)
#define CSL_EVETPCC_ECRH_RN_E52_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E52_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E41_MASK                            (0x00000200U)
#define CSL_EVETPCC_ECRH_RN_E41_SHIFT                           (9U)
#define CSL_EVETPCC_ECRH_RN_E41_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E41_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E55_MASK                            (0x00800000U)
#define CSL_EVETPCC_ECRH_RN_E55_SHIFT                           (23U)
#define CSL_EVETPCC_ECRH_RN_E55_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E55_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E53_MASK                            (0x00200000U)
#define CSL_EVETPCC_ECRH_RN_E53_SHIFT                           (21U)
#define CSL_EVETPCC_ECRH_RN_E53_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E53_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E46_MASK                            (0x00004000U)
#define CSL_EVETPCC_ECRH_RN_E46_SHIFT                           (14U)
#define CSL_EVETPCC_ECRH_RN_E46_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E46_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E62_MASK                            (0x40000000U)
#define CSL_EVETPCC_ECRH_RN_E62_SHIFT                           (30U)
#define CSL_EVETPCC_ECRH_RN_E62_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E62_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E40_MASK                            (0x00000100U)
#define CSL_EVETPCC_ECRH_RN_E40_SHIFT                           (8U)
#define CSL_EVETPCC_ECRH_RN_E40_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E40_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E56_MASK                            (0x01000000U)
#define CSL_EVETPCC_ECRH_RN_E56_SHIFT                           (24U)
#define CSL_EVETPCC_ECRH_RN_E56_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E56_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E61_MASK                            (0x20000000U)
#define CSL_EVETPCC_ECRH_RN_E61_SHIFT                           (29U)
#define CSL_EVETPCC_ECRH_RN_E61_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E61_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E45_MASK                            (0x00002000U)
#define CSL_EVETPCC_ECRH_RN_E45_SHIFT                           (13U)
#define CSL_EVETPCC_ECRH_RN_E45_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E45_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E59_MASK                            (0x08000000U)
#define CSL_EVETPCC_ECRH_RN_E59_SHIFT                           (27U)
#define CSL_EVETPCC_ECRH_RN_E59_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E59_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E44_MASK                            (0x00001000U)
#define CSL_EVETPCC_ECRH_RN_E44_SHIFT                           (12U)
#define CSL_EVETPCC_ECRH_RN_E44_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E44_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E54_MASK                            (0x00400000U)
#define CSL_EVETPCC_ECRH_RN_E54_SHIFT                           (22U)
#define CSL_EVETPCC_ECRH_RN_E54_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E54_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E43_MASK                            (0x00000800U)
#define CSL_EVETPCC_ECRH_RN_E43_SHIFT                           (11U)
#define CSL_EVETPCC_ECRH_RN_E43_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E43_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_E57_MASK                            (0x02000000U)
#define CSL_EVETPCC_ECRH_RN_E57_SHIFT                           (25U)
#define CSL_EVETPCC_ECRH_RN_E57_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ECRH_RN_E57_MAX                             (0x00000001U)

#define CSL_EVETPCC_ECRH_RN_RESETVAL                            (0x00000000U)

/* ICR_RN */

#define CSL_EVETPCC_ICR_RN_I17_MASK                             (0x00020000U)
#define CSL_EVETPCC_ICR_RN_I17_SHIFT                            (17U)
#define CSL_EVETPCC_ICR_RN_I17_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I17_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I30_MASK                             (0x40000000U)
#define CSL_EVETPCC_ICR_RN_I30_SHIFT                            (30U)
#define CSL_EVETPCC_ICR_RN_I30_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I30_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I7_MASK                              (0x00000080U)
#define CSL_EVETPCC_ICR_RN_I7_SHIFT                             (7U)
#define CSL_EVETPCC_ICR_RN_I7_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I7_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I19_MASK                             (0x00080000U)
#define CSL_EVETPCC_ICR_RN_I19_SHIFT                            (19U)
#define CSL_EVETPCC_ICR_RN_I19_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I19_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I16_MASK                             (0x00010000U)
#define CSL_EVETPCC_ICR_RN_I16_SHIFT                            (16U)
#define CSL_EVETPCC_ICR_RN_I16_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I16_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I6_MASK                              (0x00000040U)
#define CSL_EVETPCC_ICR_RN_I6_SHIFT                             (6U)
#define CSL_EVETPCC_ICR_RN_I6_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I6_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I31_MASK                             (0x80000000U)
#define CSL_EVETPCC_ICR_RN_I31_SHIFT                            (31U)
#define CSL_EVETPCC_ICR_RN_I31_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I31_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I20_MASK                             (0x00100000U)
#define CSL_EVETPCC_ICR_RN_I20_SHIFT                            (20U)
#define CSL_EVETPCC_ICR_RN_I20_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I20_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I18_MASK                             (0x00040000U)
#define CSL_EVETPCC_ICR_RN_I18_SHIFT                            (18U)
#define CSL_EVETPCC_ICR_RN_I18_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I18_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I21_MASK                             (0x00200000U)
#define CSL_EVETPCC_ICR_RN_I21_SHIFT                            (21U)
#define CSL_EVETPCC_ICR_RN_I21_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I21_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I8_MASK                              (0x00000100U)
#define CSL_EVETPCC_ICR_RN_I8_SHIFT                             (8U)
#define CSL_EVETPCC_ICR_RN_I8_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I8_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I22_MASK                             (0x00400000U)
#define CSL_EVETPCC_ICR_RN_I22_SHIFT                            (22U)
#define CSL_EVETPCC_ICR_RN_I22_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I22_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I13_MASK                             (0x00002000U)
#define CSL_EVETPCC_ICR_RN_I13_SHIFT                            (13U)
#define CSL_EVETPCC_ICR_RN_I13_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I13_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I3_MASK                              (0x00000008U)
#define CSL_EVETPCC_ICR_RN_I3_SHIFT                             (3U)
#define CSL_EVETPCC_ICR_RN_I3_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I3_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I23_MASK                             (0x00800000U)
#define CSL_EVETPCC_ICR_RN_I23_SHIFT                            (23U)
#define CSL_EVETPCC_ICR_RN_I23_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I23_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I12_MASK                             (0x00001000U)
#define CSL_EVETPCC_ICR_RN_I12_SHIFT                            (12U)
#define CSL_EVETPCC_ICR_RN_I12_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I12_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I2_MASK                              (0x00000004U)
#define CSL_EVETPCC_ICR_RN_I2_SHIFT                             (2U)
#define CSL_EVETPCC_ICR_RN_I2_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I2_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I24_MASK                             (0x01000000U)
#define CSL_EVETPCC_ICR_RN_I24_SHIFT                            (24U)
#define CSL_EVETPCC_ICR_RN_I24_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I24_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I15_MASK                             (0x00008000U)
#define CSL_EVETPCC_ICR_RN_I15_SHIFT                            (15U)
#define CSL_EVETPCC_ICR_RN_I15_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I15_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I25_MASK                             (0x02000000U)
#define CSL_EVETPCC_ICR_RN_I25_SHIFT                            (25U)
#define CSL_EVETPCC_ICR_RN_I25_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I25_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I5_MASK                              (0x00000020U)
#define CSL_EVETPCC_ICR_RN_I5_SHIFT                             (5U)
#define CSL_EVETPCC_ICR_RN_I5_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I5_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I14_MASK                             (0x00004000U)
#define CSL_EVETPCC_ICR_RN_I14_SHIFT                            (14U)
#define CSL_EVETPCC_ICR_RN_I14_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I14_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I4_MASK                              (0x00000010U)
#define CSL_EVETPCC_ICR_RN_I4_SHIFT                             (4U)
#define CSL_EVETPCC_ICR_RN_I4_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I4_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I9_MASK                              (0x00000200U)
#define CSL_EVETPCC_ICR_RN_I9_SHIFT                             (9U)
#define CSL_EVETPCC_ICR_RN_I9_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I9_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I27_MASK                             (0x08000000U)
#define CSL_EVETPCC_ICR_RN_I27_SHIFT                            (27U)
#define CSL_EVETPCC_ICR_RN_I27_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I27_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I26_MASK                             (0x04000000U)
#define CSL_EVETPCC_ICR_RN_I26_SHIFT                            (26U)
#define CSL_EVETPCC_ICR_RN_I26_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I26_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I11_MASK                             (0x00000800U)
#define CSL_EVETPCC_ICR_RN_I11_SHIFT                            (11U)
#define CSL_EVETPCC_ICR_RN_I11_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I11_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I1_MASK                              (0x00000002U)
#define CSL_EVETPCC_ICR_RN_I1_SHIFT                             (1U)
#define CSL_EVETPCC_ICR_RN_I1_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I1_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I10_MASK                             (0x00000400U)
#define CSL_EVETPCC_ICR_RN_I10_SHIFT                            (10U)
#define CSL_EVETPCC_ICR_RN_I10_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I10_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I28_MASK                             (0x10000000U)
#define CSL_EVETPCC_ICR_RN_I28_SHIFT                            (28U)
#define CSL_EVETPCC_ICR_RN_I28_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I28_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I0_MASK                              (0x00000001U)
#define CSL_EVETPCC_ICR_RN_I0_SHIFT                             (0U)
#define CSL_EVETPCC_ICR_RN_I0_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I0_MAX                               (0x00000001U)

#define CSL_EVETPCC_ICR_RN_I29_MASK                             (0x20000000U)
#define CSL_EVETPCC_ICR_RN_I29_SHIFT                            (29U)
#define CSL_EVETPCC_ICR_RN_I29_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ICR_RN_I29_MAX                              (0x00000001U)

#define CSL_EVETPCC_ICR_RN_RESETVAL                             (0x00000000U)

/* IPRH_RN */

#define CSL_EVETPCC_IPRH_RN_I53_MASK                            (0x00200000U)
#define CSL_EVETPCC_IPRH_RN_I53_SHIFT                           (21U)
#define CSL_EVETPCC_IPRH_RN_I53_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I53_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I41_MASK                            (0x00000200U)
#define CSL_EVETPCC_IPRH_RN_I41_SHIFT                           (9U)
#define CSL_EVETPCC_IPRH_RN_I41_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I41_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I52_MASK                            (0x00100000U)
#define CSL_EVETPCC_IPRH_RN_I52_SHIFT                           (20U)
#define CSL_EVETPCC_IPRH_RN_I52_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I52_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I40_MASK                            (0x00000100U)
#define CSL_EVETPCC_IPRH_RN_I40_SHIFT                           (8U)
#define CSL_EVETPCC_IPRH_RN_I40_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I40_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I51_MASK                            (0x00080000U)
#define CSL_EVETPCC_IPRH_RN_I51_SHIFT                           (19U)
#define CSL_EVETPCC_IPRH_RN_I51_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I51_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I39_MASK                            (0x00000080U)
#define CSL_EVETPCC_IPRH_RN_I39_SHIFT                           (7U)
#define CSL_EVETPCC_IPRH_RN_I39_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I39_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I32_MASK                            (0x00000001U)
#define CSL_EVETPCC_IPRH_RN_I32_SHIFT                           (0U)
#define CSL_EVETPCC_IPRH_RN_I32_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I32_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I50_MASK                            (0x00040000U)
#define CSL_EVETPCC_IPRH_RN_I50_SHIFT                           (18U)
#define CSL_EVETPCC_IPRH_RN_I50_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I50_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I33_MASK                            (0x00000002U)
#define CSL_EVETPCC_IPRH_RN_I33_SHIFT                           (1U)
#define CSL_EVETPCC_IPRH_RN_I33_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I33_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I34_MASK                            (0x00000004U)
#define CSL_EVETPCC_IPRH_RN_I34_SHIFT                           (2U)
#define CSL_EVETPCC_IPRH_RN_I34_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I34_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I49_MASK                            (0x00020000U)
#define CSL_EVETPCC_IPRH_RN_I49_SHIFT                           (17U)
#define CSL_EVETPCC_IPRH_RN_I49_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I49_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I60_MASK                            (0x10000000U)
#define CSL_EVETPCC_IPRH_RN_I60_SHIFT                           (28U)
#define CSL_EVETPCC_IPRH_RN_I60_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I60_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I47_MASK                            (0x00008000U)
#define CSL_EVETPCC_IPRH_RN_I47_SHIFT                           (15U)
#define CSL_EVETPCC_IPRH_RN_I47_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I47_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I35_MASK                            (0x00000008U)
#define CSL_EVETPCC_IPRH_RN_I35_SHIFT                           (3U)
#define CSL_EVETPCC_IPRH_RN_I35_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I35_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I36_MASK                            (0x00000010U)
#define CSL_EVETPCC_IPRH_RN_I36_SHIFT                           (4U)
#define CSL_EVETPCC_IPRH_RN_I36_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I36_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I59_MASK                            (0x08000000U)
#define CSL_EVETPCC_IPRH_RN_I59_SHIFT                           (27U)
#define CSL_EVETPCC_IPRH_RN_I59_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I59_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I48_MASK                            (0x00010000U)
#define CSL_EVETPCC_IPRH_RN_I48_SHIFT                           (16U)
#define CSL_EVETPCC_IPRH_RN_I48_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I48_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I37_MASK                            (0x00000020U)
#define CSL_EVETPCC_IPRH_RN_I37_SHIFT                           (5U)
#define CSL_EVETPCC_IPRH_RN_I37_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I37_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I61_MASK                            (0x20000000U)
#define CSL_EVETPCC_IPRH_RN_I61_SHIFT                           (29U)
#define CSL_EVETPCC_IPRH_RN_I61_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I61_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I38_MASK                            (0x00000040U)
#define CSL_EVETPCC_IPRH_RN_I38_SHIFT                           (6U)
#define CSL_EVETPCC_IPRH_RN_I38_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I38_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I58_MASK                            (0x04000000U)
#define CSL_EVETPCC_IPRH_RN_I58_SHIFT                           (26U)
#define CSL_EVETPCC_IPRH_RN_I58_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I58_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I46_MASK                            (0x00004000U)
#define CSL_EVETPCC_IPRH_RN_I46_SHIFT                           (14U)
#define CSL_EVETPCC_IPRH_RN_I46_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I46_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I45_MASK                            (0x00002000U)
#define CSL_EVETPCC_IPRH_RN_I45_SHIFT                           (13U)
#define CSL_EVETPCC_IPRH_RN_I45_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I45_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I57_MASK                            (0x02000000U)
#define CSL_EVETPCC_IPRH_RN_I57_SHIFT                           (25U)
#define CSL_EVETPCC_IPRH_RN_I57_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I57_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I44_MASK                            (0x00001000U)
#define CSL_EVETPCC_IPRH_RN_I44_SHIFT                           (12U)
#define CSL_EVETPCC_IPRH_RN_I44_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I44_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I56_MASK                            (0x01000000U)
#define CSL_EVETPCC_IPRH_RN_I56_SHIFT                           (24U)
#define CSL_EVETPCC_IPRH_RN_I56_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I56_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I63_MASK                            (0x80000000U)
#define CSL_EVETPCC_IPRH_RN_I63_SHIFT                           (31U)
#define CSL_EVETPCC_IPRH_RN_I63_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I63_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I43_MASK                            (0x00000800U)
#define CSL_EVETPCC_IPRH_RN_I43_SHIFT                           (11U)
#define CSL_EVETPCC_IPRH_RN_I43_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I43_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I55_MASK                            (0x00800000U)
#define CSL_EVETPCC_IPRH_RN_I55_SHIFT                           (23U)
#define CSL_EVETPCC_IPRH_RN_I55_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I55_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I62_MASK                            (0x40000000U)
#define CSL_EVETPCC_IPRH_RN_I62_SHIFT                           (30U)
#define CSL_EVETPCC_IPRH_RN_I62_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I62_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I42_MASK                            (0x00000400U)
#define CSL_EVETPCC_IPRH_RN_I42_SHIFT                           (10U)
#define CSL_EVETPCC_IPRH_RN_I42_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I42_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_I54_MASK                            (0x00400000U)
#define CSL_EVETPCC_IPRH_RN_I54_SHIFT                           (22U)
#define CSL_EVETPCC_IPRH_RN_I54_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IPRH_RN_I54_MAX                             (0x00000001U)

#define CSL_EVETPCC_IPRH_RN_RESETVAL                            (0x00000000U)

/* CER_RN */

#define CSL_EVETPCC_CER_RN_E6_MASK                              (0x00000040U)
#define CSL_EVETPCC_CER_RN_E6_SHIFT                             (6U)
#define CSL_EVETPCC_CER_RN_E6_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E6_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E25_MASK                             (0x02000000U)
#define CSL_EVETPCC_CER_RN_E25_SHIFT                            (25U)
#define CSL_EVETPCC_CER_RN_E25_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E25_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E18_MASK                             (0x00040000U)
#define CSL_EVETPCC_CER_RN_E18_SHIFT                            (18U)
#define CSL_EVETPCC_CER_RN_E18_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E18_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E7_MASK                              (0x00000080U)
#define CSL_EVETPCC_CER_RN_E7_SHIFT                             (7U)
#define CSL_EVETPCC_CER_RN_E7_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E7_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E24_MASK                             (0x01000000U)
#define CSL_EVETPCC_CER_RN_E24_SHIFT                            (24U)
#define CSL_EVETPCC_CER_RN_E24_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E24_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E31_MASK                             (0x80000000U)
#define CSL_EVETPCC_CER_RN_E31_SHIFT                            (31U)
#define CSL_EVETPCC_CER_RN_E31_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E31_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E8_MASK                              (0x00000100U)
#define CSL_EVETPCC_CER_RN_E8_SHIFT                             (8U)
#define CSL_EVETPCC_CER_RN_E8_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E8_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E26_MASK                             (0x04000000U)
#define CSL_EVETPCC_CER_RN_E26_SHIFT                            (26U)
#define CSL_EVETPCC_CER_RN_E26_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E26_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E29_MASK                             (0x20000000U)
#define CSL_EVETPCC_CER_RN_E29_SHIFT                            (29U)
#define CSL_EVETPCC_CER_RN_E29_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E29_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E9_MASK                              (0x00000200U)
#define CSL_EVETPCC_CER_RN_E9_SHIFT                             (9U)
#define CSL_EVETPCC_CER_RN_E9_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E9_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E30_MASK                             (0x40000000U)
#define CSL_EVETPCC_CER_RN_E30_SHIFT                            (30U)
#define CSL_EVETPCC_CER_RN_E30_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E30_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E10_MASK                             (0x00000400U)
#define CSL_EVETPCC_CER_RN_E10_SHIFT                            (10U)
#define CSL_EVETPCC_CER_RN_E10_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E10_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E28_MASK                             (0x10000000U)
#define CSL_EVETPCC_CER_RN_E28_SHIFT                            (28U)
#define CSL_EVETPCC_CER_RN_E28_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E28_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E11_MASK                             (0x00000800U)
#define CSL_EVETPCC_CER_RN_E11_SHIFT                            (11U)
#define CSL_EVETPCC_CER_RN_E11_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E11_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E27_MASK                             (0x08000000U)
#define CSL_EVETPCC_CER_RN_E27_SHIFT                            (27U)
#define CSL_EVETPCC_CER_RN_E27_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E27_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E0_MASK                              (0x00000001U)
#define CSL_EVETPCC_CER_RN_E0_SHIFT                             (0U)
#define CSL_EVETPCC_CER_RN_E0_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E0_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E12_MASK                             (0x00001000U)
#define CSL_EVETPCC_CER_RN_E12_SHIFT                            (12U)
#define CSL_EVETPCC_CER_RN_E12_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E12_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E1_MASK                              (0x00000002U)
#define CSL_EVETPCC_CER_RN_E1_SHIFT                             (1U)
#define CSL_EVETPCC_CER_RN_E1_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E1_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E13_MASK                             (0x00002000U)
#define CSL_EVETPCC_CER_RN_E13_SHIFT                            (13U)
#define CSL_EVETPCC_CER_RN_E13_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E13_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E19_MASK                             (0x00080000U)
#define CSL_EVETPCC_CER_RN_E19_SHIFT                            (19U)
#define CSL_EVETPCC_CER_RN_E19_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E19_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E2_MASK                              (0x00000004U)
#define CSL_EVETPCC_CER_RN_E2_SHIFT                             (2U)
#define CSL_EVETPCC_CER_RN_E2_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E2_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E14_MASK                             (0x00004000U)
#define CSL_EVETPCC_CER_RN_E14_SHIFT                            (14U)
#define CSL_EVETPCC_CER_RN_E14_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E14_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E3_MASK                              (0x00000008U)
#define CSL_EVETPCC_CER_RN_E3_SHIFT                             (3U)
#define CSL_EVETPCC_CER_RN_E3_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E3_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E15_MASK                             (0x00008000U)
#define CSL_EVETPCC_CER_RN_E15_SHIFT                            (15U)
#define CSL_EVETPCC_CER_RN_E15_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E15_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E21_MASK                             (0x00200000U)
#define CSL_EVETPCC_CER_RN_E21_SHIFT                            (21U)
#define CSL_EVETPCC_CER_RN_E21_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E21_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E20_MASK                             (0x00100000U)
#define CSL_EVETPCC_CER_RN_E20_SHIFT                            (20U)
#define CSL_EVETPCC_CER_RN_E20_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E20_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E4_MASK                              (0x00000010U)
#define CSL_EVETPCC_CER_RN_E4_SHIFT                             (4U)
#define CSL_EVETPCC_CER_RN_E4_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E4_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E23_MASK                             (0x00800000U)
#define CSL_EVETPCC_CER_RN_E23_SHIFT                            (23U)
#define CSL_EVETPCC_CER_RN_E23_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E23_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E16_MASK                             (0x00010000U)
#define CSL_EVETPCC_CER_RN_E16_SHIFT                            (16U)
#define CSL_EVETPCC_CER_RN_E16_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E16_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E5_MASK                              (0x00000020U)
#define CSL_EVETPCC_CER_RN_E5_SHIFT                             (5U)
#define CSL_EVETPCC_CER_RN_E5_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CER_RN_E5_MAX                               (0x00000001U)

#define CSL_EVETPCC_CER_RN_E22_MASK                             (0x00400000U)
#define CSL_EVETPCC_CER_RN_E22_SHIFT                            (22U)
#define CSL_EVETPCC_CER_RN_E22_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E22_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_E17_MASK                             (0x00020000U)
#define CSL_EVETPCC_CER_RN_E17_SHIFT                            (17U)
#define CSL_EVETPCC_CER_RN_E17_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CER_RN_E17_MAX                              (0x00000001U)

#define CSL_EVETPCC_CER_RN_RESETVAL                             (0x00000000U)

/* IECRH_RN */

#define CSL_EVETPCC_IECRH_RN_I35_MASK                           (0x00000008U)
#define CSL_EVETPCC_IECRH_RN_I35_SHIFT                          (3U)
#define CSL_EVETPCC_IECRH_RN_I35_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I35_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I48_MASK                           (0x00010000U)
#define CSL_EVETPCC_IECRH_RN_I48_SHIFT                          (16U)
#define CSL_EVETPCC_IECRH_RN_I48_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I48_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I56_MASK                           (0x01000000U)
#define CSL_EVETPCC_IECRH_RN_I56_SHIFT                          (24U)
#define CSL_EVETPCC_IECRH_RN_I56_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I56_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I34_MASK                           (0x00000004U)
#define CSL_EVETPCC_IECRH_RN_I34_SHIFT                          (2U)
#define CSL_EVETPCC_IECRH_RN_I34_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I34_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I47_MASK                           (0x00008000U)
#define CSL_EVETPCC_IECRH_RN_I47_SHIFT                          (15U)
#define CSL_EVETPCC_IECRH_RN_I47_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I47_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I46_MASK                           (0x00004000U)
#define CSL_EVETPCC_IECRH_RN_I46_SHIFT                          (14U)
#define CSL_EVETPCC_IECRH_RN_I46_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I46_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I55_MASK                           (0x00800000U)
#define CSL_EVETPCC_IECRH_RN_I55_SHIFT                          (23U)
#define CSL_EVETPCC_IECRH_RN_I55_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I55_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I45_MASK                           (0x00002000U)
#define CSL_EVETPCC_IECRH_RN_I45_SHIFT                          (13U)
#define CSL_EVETPCC_IECRH_RN_I45_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I45_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I58_MASK                           (0x04000000U)
#define CSL_EVETPCC_IECRH_RN_I58_SHIFT                          (26U)
#define CSL_EVETPCC_IECRH_RN_I58_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I58_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I32_MASK                           (0x00000001U)
#define CSL_EVETPCC_IECRH_RN_I32_SHIFT                          (0U)
#define CSL_EVETPCC_IECRH_RN_I32_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I32_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I44_MASK                           (0x00001000U)
#define CSL_EVETPCC_IECRH_RN_I44_SHIFT                          (12U)
#define CSL_EVETPCC_IECRH_RN_I44_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I44_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I33_MASK                           (0x00000002U)
#define CSL_EVETPCC_IECRH_RN_I33_SHIFT                          (1U)
#define CSL_EVETPCC_IECRH_RN_I33_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I33_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I57_MASK                           (0x02000000U)
#define CSL_EVETPCC_IECRH_RN_I57_SHIFT                          (25U)
#define CSL_EVETPCC_IECRH_RN_I57_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I57_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I43_MASK                           (0x00000800U)
#define CSL_EVETPCC_IECRH_RN_I43_SHIFT                          (11U)
#define CSL_EVETPCC_IECRH_RN_I43_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I43_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I60_MASK                           (0x10000000U)
#define CSL_EVETPCC_IECRH_RN_I60_SHIFT                          (28U)
#define CSL_EVETPCC_IECRH_RN_I60_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I60_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I42_MASK                           (0x00000400U)
#define CSL_EVETPCC_IECRH_RN_I42_SHIFT                          (10U)
#define CSL_EVETPCC_IECRH_RN_I42_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I42_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I59_MASK                           (0x08000000U)
#define CSL_EVETPCC_IECRH_RN_I59_SHIFT                          (27U)
#define CSL_EVETPCC_IECRH_RN_I59_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I59_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I41_MASK                           (0x00000200U)
#define CSL_EVETPCC_IECRH_RN_I41_SHIFT                          (9U)
#define CSL_EVETPCC_IECRH_RN_I41_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I41_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I62_MASK                           (0x40000000U)
#define CSL_EVETPCC_IECRH_RN_I62_SHIFT                          (30U)
#define CSL_EVETPCC_IECRH_RN_I62_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I62_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I61_MASK                           (0x20000000U)
#define CSL_EVETPCC_IECRH_RN_I61_SHIFT                          (29U)
#define CSL_EVETPCC_IECRH_RN_I61_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I61_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I52_MASK                           (0x00100000U)
#define CSL_EVETPCC_IECRH_RN_I52_SHIFT                          (20U)
#define CSL_EVETPCC_IECRH_RN_I52_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I52_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I38_MASK                           (0x00000040U)
#define CSL_EVETPCC_IECRH_RN_I38_SHIFT                          (6U)
#define CSL_EVETPCC_IECRH_RN_I38_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I38_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I40_MASK                           (0x00000100U)
#define CSL_EVETPCC_IECRH_RN_I40_SHIFT                          (8U)
#define CSL_EVETPCC_IECRH_RN_I40_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I40_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I51_MASK                           (0x00080000U)
#define CSL_EVETPCC_IECRH_RN_I51_SHIFT                          (19U)
#define CSL_EVETPCC_IECRH_RN_I51_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I51_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I50_MASK                           (0x00040000U)
#define CSL_EVETPCC_IECRH_RN_I50_SHIFT                          (18U)
#define CSL_EVETPCC_IECRH_RN_I50_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I50_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I63_MASK                           (0x80000000U)
#define CSL_EVETPCC_IECRH_RN_I63_SHIFT                          (31U)
#define CSL_EVETPCC_IECRH_RN_I63_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I63_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I39_MASK                           (0x00000080U)
#define CSL_EVETPCC_IECRH_RN_I39_SHIFT                          (7U)
#define CSL_EVETPCC_IECRH_RN_I39_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I39_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I54_MASK                           (0x00400000U)
#define CSL_EVETPCC_IECRH_RN_I54_SHIFT                          (22U)
#define CSL_EVETPCC_IECRH_RN_I54_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I54_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I36_MASK                           (0x00000010U)
#define CSL_EVETPCC_IECRH_RN_I36_SHIFT                          (4U)
#define CSL_EVETPCC_IECRH_RN_I36_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I36_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I53_MASK                           (0x00200000U)
#define CSL_EVETPCC_IECRH_RN_I53_SHIFT                          (21U)
#define CSL_EVETPCC_IECRH_RN_I53_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I53_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I49_MASK                           (0x00020000U)
#define CSL_EVETPCC_IECRH_RN_I49_SHIFT                          (17U)
#define CSL_EVETPCC_IECRH_RN_I49_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I49_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_I37_MASK                           (0x00000020U)
#define CSL_EVETPCC_IECRH_RN_I37_SHIFT                          (5U)
#define CSL_EVETPCC_IECRH_RN_I37_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_IECRH_RN_I37_MAX                            (0x00000001U)

#define CSL_EVETPCC_IECRH_RN_RESETVAL                           (0x00000000U)

/* IECR_RN */

#define CSL_EVETPCC_IECR_RN_I27_MASK                            (0x08000000U)
#define CSL_EVETPCC_IECR_RN_I27_SHIFT                           (27U)
#define CSL_EVETPCC_IECR_RN_I27_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I27_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I28_MASK                            (0x10000000U)
#define CSL_EVETPCC_IECR_RN_I28_SHIFT                           (28U)
#define CSL_EVETPCC_IECR_RN_I28_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I28_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I25_MASK                            (0x02000000U)
#define CSL_EVETPCC_IECR_RN_I25_SHIFT                           (25U)
#define CSL_EVETPCC_IECR_RN_I25_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I25_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I16_MASK                            (0x00010000U)
#define CSL_EVETPCC_IECR_RN_I16_SHIFT                           (16U)
#define CSL_EVETPCC_IECR_RN_I16_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I16_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I26_MASK                            (0x04000000U)
#define CSL_EVETPCC_IECR_RN_I26_SHIFT                           (26U)
#define CSL_EVETPCC_IECR_RN_I26_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I26_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I15_MASK                            (0x00008000U)
#define CSL_EVETPCC_IECR_RN_I15_SHIFT                           (15U)
#define CSL_EVETPCC_IECR_RN_I15_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I15_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I14_MASK                            (0x00004000U)
#define CSL_EVETPCC_IECR_RN_I14_SHIFT                           (14U)
#define CSL_EVETPCC_IECR_RN_I14_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I14_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I13_MASK                            (0x00002000U)
#define CSL_EVETPCC_IECR_RN_I13_SHIFT                           (13U)
#define CSL_EVETPCC_IECR_RN_I13_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I13_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I0_MASK                             (0x00000001U)
#define CSL_EVETPCC_IECR_RN_I0_SHIFT                            (0U)
#define CSL_EVETPCC_IECR_RN_I0_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I0_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I22_MASK                            (0x00400000U)
#define CSL_EVETPCC_IECR_RN_I22_SHIFT                           (22U)
#define CSL_EVETPCC_IECR_RN_I22_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I22_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I10_MASK                            (0x00000400U)
#define CSL_EVETPCC_IECR_RN_I10_SHIFT                           (10U)
#define CSL_EVETPCC_IECR_RN_I10_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I10_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I21_MASK                            (0x00200000U)
#define CSL_EVETPCC_IECR_RN_I21_SHIFT                           (21U)
#define CSL_EVETPCC_IECR_RN_I21_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I21_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I9_MASK                             (0x00000200U)
#define CSL_EVETPCC_IECR_RN_I9_SHIFT                            (9U)
#define CSL_EVETPCC_IECR_RN_I9_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I9_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I1_MASK                             (0x00000002U)
#define CSL_EVETPCC_IECR_RN_I1_SHIFT                            (1U)
#define CSL_EVETPCC_IECR_RN_I1_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I1_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I24_MASK                            (0x01000000U)
#define CSL_EVETPCC_IECR_RN_I24_SHIFT                           (24U)
#define CSL_EVETPCC_IECR_RN_I24_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I24_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I3_MASK                             (0x00000008U)
#define CSL_EVETPCC_IECR_RN_I3_SHIFT                            (3U)
#define CSL_EVETPCC_IECR_RN_I3_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I3_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I2_MASK                             (0x00000004U)
#define CSL_EVETPCC_IECR_RN_I2_SHIFT                            (2U)
#define CSL_EVETPCC_IECR_RN_I2_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I2_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I12_MASK                            (0x00001000U)
#define CSL_EVETPCC_IECR_RN_I12_SHIFT                           (12U)
#define CSL_EVETPCC_IECR_RN_I12_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I12_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I23_MASK                            (0x00800000U)
#define CSL_EVETPCC_IECR_RN_I23_SHIFT                           (23U)
#define CSL_EVETPCC_IECR_RN_I23_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I23_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I4_MASK                             (0x00000010U)
#define CSL_EVETPCC_IECR_RN_I4_SHIFT                            (4U)
#define CSL_EVETPCC_IECR_RN_I4_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I4_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I11_MASK                            (0x00000800U)
#define CSL_EVETPCC_IECR_RN_I11_SHIFT                           (11U)
#define CSL_EVETPCC_IECR_RN_I11_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I11_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I6_MASK                             (0x00000040U)
#define CSL_EVETPCC_IECR_RN_I6_SHIFT                            (6U)
#define CSL_EVETPCC_IECR_RN_I6_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I6_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I31_MASK                            (0x80000000U)
#define CSL_EVETPCC_IECR_RN_I31_SHIFT                           (31U)
#define CSL_EVETPCC_IECR_RN_I31_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I31_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I18_MASK                            (0x00040000U)
#define CSL_EVETPCC_IECR_RN_I18_SHIFT                           (18U)
#define CSL_EVETPCC_IECR_RN_I18_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I18_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I17_MASK                            (0x00020000U)
#define CSL_EVETPCC_IECR_RN_I17_SHIFT                           (17U)
#define CSL_EVETPCC_IECR_RN_I17_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I17_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I5_MASK                             (0x00000020U)
#define CSL_EVETPCC_IECR_RN_I5_SHIFT                            (5U)
#define CSL_EVETPCC_IECR_RN_I5_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I5_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I20_MASK                            (0x00100000U)
#define CSL_EVETPCC_IECR_RN_I20_SHIFT                           (20U)
#define CSL_EVETPCC_IECR_RN_I20_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I20_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I29_MASK                            (0x20000000U)
#define CSL_EVETPCC_IECR_RN_I29_SHIFT                           (29U)
#define CSL_EVETPCC_IECR_RN_I29_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I29_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I8_MASK                             (0x00000100U)
#define CSL_EVETPCC_IECR_RN_I8_SHIFT                            (8U)
#define CSL_EVETPCC_IECR_RN_I8_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I8_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I19_MASK                            (0x00080000U)
#define CSL_EVETPCC_IECR_RN_I19_SHIFT                           (19U)
#define CSL_EVETPCC_IECR_RN_I19_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I19_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I30_MASK                            (0x40000000U)
#define CSL_EVETPCC_IECR_RN_I30_SHIFT                           (30U)
#define CSL_EVETPCC_IECR_RN_I30_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I30_MAX                             (0x00000001U)

#define CSL_EVETPCC_IECR_RN_I7_MASK                             (0x00000080U)
#define CSL_EVETPCC_IECR_RN_I7_SHIFT                            (7U)
#define CSL_EVETPCC_IECR_RN_I7_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IECR_RN_I7_MAX                              (0x00000001U)

#define CSL_EVETPCC_IECR_RN_RESETVAL                            (0x00000000U)

/* QSER_RN */

#define CSL_EVETPCC_QSER_RN_E4_MASK                             (0x00000010U)
#define CSL_EVETPCC_QSER_RN_E4_SHIFT                            (4U)
#define CSL_EVETPCC_QSER_RN_E4_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QSER_RN_E4_MAX                              (0x00000001U)

#define CSL_EVETPCC_QSER_RN_E3_MASK                             (0x00000008U)
#define CSL_EVETPCC_QSER_RN_E3_SHIFT                            (3U)
#define CSL_EVETPCC_QSER_RN_E3_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QSER_RN_E3_MAX                              (0x00000001U)

#define CSL_EVETPCC_QSER_RN_E2_MASK                             (0x00000004U)
#define CSL_EVETPCC_QSER_RN_E2_SHIFT                            (2U)
#define CSL_EVETPCC_QSER_RN_E2_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QSER_RN_E2_MAX                              (0x00000001U)

#define CSL_EVETPCC_QSER_RN_E1_MASK                             (0x00000002U)
#define CSL_EVETPCC_QSER_RN_E1_SHIFT                            (1U)
#define CSL_EVETPCC_QSER_RN_E1_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QSER_RN_E1_MAX                              (0x00000001U)

#define CSL_EVETPCC_QSER_RN_E0_MASK                             (0x00000001U)
#define CSL_EVETPCC_QSER_RN_E0_SHIFT                            (0U)
#define CSL_EVETPCC_QSER_RN_E0_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QSER_RN_E0_MAX                              (0x00000001U)

#define CSL_EVETPCC_QSER_RN_E7_MASK                             (0x00000080U)
#define CSL_EVETPCC_QSER_RN_E7_SHIFT                            (7U)
#define CSL_EVETPCC_QSER_RN_E7_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QSER_RN_E7_MAX                              (0x00000001U)

#define CSL_EVETPCC_QSER_RN_E5_MASK                             (0x00000020U)
#define CSL_EVETPCC_QSER_RN_E5_SHIFT                            (5U)
#define CSL_EVETPCC_QSER_RN_E5_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QSER_RN_E5_MAX                              (0x00000001U)

#define CSL_EVETPCC_QSER_RN_E6_MASK                             (0x00000040U)
#define CSL_EVETPCC_QSER_RN_E6_SHIFT                            (6U)
#define CSL_EVETPCC_QSER_RN_E6_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_QSER_RN_E6_MAX                              (0x00000001U)

#define CSL_EVETPCC_QSER_RN_RESETVAL                            (0x00000000U)

/* IERH_RN */

#define CSL_EVETPCC_IERH_RN_I48_MASK                            (0x00010000U)
#define CSL_EVETPCC_IERH_RN_I48_SHIFT                           (16U)
#define CSL_EVETPCC_IERH_RN_I48_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I48_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I35_MASK                            (0x00000008U)
#define CSL_EVETPCC_IERH_RN_I35_SHIFT                           (3U)
#define CSL_EVETPCC_IERH_RN_I35_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I35_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I34_MASK                            (0x00000004U)
#define CSL_EVETPCC_IERH_RN_I34_SHIFT                           (2U)
#define CSL_EVETPCC_IERH_RN_I34_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I34_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I46_MASK                            (0x00004000U)
#define CSL_EVETPCC_IERH_RN_I46_SHIFT                           (14U)
#define CSL_EVETPCC_IERH_RN_I46_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I46_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I59_MASK                            (0x08000000U)
#define CSL_EVETPCC_IERH_RN_I59_SHIFT                           (27U)
#define CSL_EVETPCC_IERH_RN_I59_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I59_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I33_MASK                            (0x00000002U)
#define CSL_EVETPCC_IERH_RN_I33_SHIFT                           (1U)
#define CSL_EVETPCC_IERH_RN_I33_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I33_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I45_MASK                            (0x00002000U)
#define CSL_EVETPCC_IERH_RN_I45_SHIFT                           (13U)
#define CSL_EVETPCC_IERH_RN_I45_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I45_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I60_MASK                            (0x10000000U)
#define CSL_EVETPCC_IERH_RN_I60_SHIFT                           (28U)
#define CSL_EVETPCC_IERH_RN_I60_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I60_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I32_MASK                            (0x00000001U)
#define CSL_EVETPCC_IERH_RN_I32_SHIFT                           (0U)
#define CSL_EVETPCC_IERH_RN_I32_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I32_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I44_MASK                            (0x00001000U)
#define CSL_EVETPCC_IERH_RN_I44_SHIFT                           (12U)
#define CSL_EVETPCC_IERH_RN_I44_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I44_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I61_MASK                            (0x20000000U)
#define CSL_EVETPCC_IERH_RN_I61_SHIFT                           (29U)
#define CSL_EVETPCC_IERH_RN_I61_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I61_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I43_MASK                            (0x00000800U)
#define CSL_EVETPCC_IERH_RN_I43_SHIFT                           (11U)
#define CSL_EVETPCC_IERH_RN_I43_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I43_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I49_MASK                            (0x00020000U)
#define CSL_EVETPCC_IERH_RN_I49_SHIFT                           (17U)
#define CSL_EVETPCC_IERH_RN_I49_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I49_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I62_MASK                            (0x40000000U)
#define CSL_EVETPCC_IERH_RN_I62_SHIFT                           (30U)
#define CSL_EVETPCC_IERH_RN_I62_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I62_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I50_MASK                            (0x00040000U)
#define CSL_EVETPCC_IERH_RN_I50_SHIFT                           (18U)
#define CSL_EVETPCC_IERH_RN_I50_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I50_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I42_MASK                            (0x00000400U)
#define CSL_EVETPCC_IERH_RN_I42_SHIFT                           (10U)
#define CSL_EVETPCC_IERH_RN_I42_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I42_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I63_MASK                            (0x80000000U)
#define CSL_EVETPCC_IERH_RN_I63_SHIFT                           (31U)
#define CSL_EVETPCC_IERH_RN_I63_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I63_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I51_MASK                            (0x00080000U)
#define CSL_EVETPCC_IERH_RN_I51_SHIFT                           (19U)
#define CSL_EVETPCC_IERH_RN_I51_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I51_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I41_MASK                            (0x00000200U)
#define CSL_EVETPCC_IERH_RN_I41_SHIFT                           (9U)
#define CSL_EVETPCC_IERH_RN_I41_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I41_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I52_MASK                            (0x00100000U)
#define CSL_EVETPCC_IERH_RN_I52_SHIFT                           (20U)
#define CSL_EVETPCC_IERH_RN_I52_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I52_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I40_MASK                            (0x00000100U)
#define CSL_EVETPCC_IERH_RN_I40_SHIFT                           (8U)
#define CSL_EVETPCC_IERH_RN_I40_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I40_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I53_MASK                            (0x00200000U)
#define CSL_EVETPCC_IERH_RN_I53_SHIFT                           (21U)
#define CSL_EVETPCC_IERH_RN_I53_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I53_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I39_MASK                            (0x00000080U)
#define CSL_EVETPCC_IERH_RN_I39_SHIFT                           (7U)
#define CSL_EVETPCC_IERH_RN_I39_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I39_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I54_MASK                            (0x00400000U)
#define CSL_EVETPCC_IERH_RN_I54_SHIFT                           (22U)
#define CSL_EVETPCC_IERH_RN_I54_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I54_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I55_MASK                            (0x00800000U)
#define CSL_EVETPCC_IERH_RN_I55_SHIFT                           (23U)
#define CSL_EVETPCC_IERH_RN_I55_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I55_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I56_MASK                            (0x01000000U)
#define CSL_EVETPCC_IERH_RN_I56_SHIFT                           (24U)
#define CSL_EVETPCC_IERH_RN_I56_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I56_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I38_MASK                            (0x00000040U)
#define CSL_EVETPCC_IERH_RN_I38_SHIFT                           (6U)
#define CSL_EVETPCC_IERH_RN_I38_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I38_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I57_MASK                            (0x02000000U)
#define CSL_EVETPCC_IERH_RN_I57_SHIFT                           (25U)
#define CSL_EVETPCC_IERH_RN_I57_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I57_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I58_MASK                            (0x04000000U)
#define CSL_EVETPCC_IERH_RN_I58_SHIFT                           (26U)
#define CSL_EVETPCC_IERH_RN_I58_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I58_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I37_MASK                            (0x00000020U)
#define CSL_EVETPCC_IERH_RN_I37_SHIFT                           (5U)
#define CSL_EVETPCC_IERH_RN_I37_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I37_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I47_MASK                            (0x00008000U)
#define CSL_EVETPCC_IERH_RN_I47_SHIFT                           (15U)
#define CSL_EVETPCC_IERH_RN_I47_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I47_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_I36_MASK                            (0x00000010U)
#define CSL_EVETPCC_IERH_RN_I36_SHIFT                           (4U)
#define CSL_EVETPCC_IERH_RN_I36_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_IERH_RN_I36_MAX                             (0x00000001U)

#define CSL_EVETPCC_IERH_RN_RESETVAL                            (0x00000000U)

/* ECR_RN */

#define CSL_EVETPCC_ECR_RN_E16_MASK                             (0x00010000U)
#define CSL_EVETPCC_ECR_RN_E16_SHIFT                            (16U)
#define CSL_EVETPCC_ECR_RN_E16_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E16_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E10_MASK                             (0x00000400U)
#define CSL_EVETPCC_ECR_RN_E10_SHIFT                            (10U)
#define CSL_EVETPCC_ECR_RN_E10_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E10_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E30_MASK                             (0x40000000U)
#define CSL_EVETPCC_ECR_RN_E30_SHIFT                            (30U)
#define CSL_EVETPCC_ECR_RN_E30_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E30_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E19_MASK                             (0x00080000U)
#define CSL_EVETPCC_ECR_RN_E19_SHIFT                            (19U)
#define CSL_EVETPCC_ECR_RN_E19_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E19_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E29_MASK                             (0x20000000U)
#define CSL_EVETPCC_ECR_RN_E29_SHIFT                            (29U)
#define CSL_EVETPCC_ECR_RN_E29_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E29_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E12_MASK                             (0x00001000U)
#define CSL_EVETPCC_ECR_RN_E12_SHIFT                            (12U)
#define CSL_EVETPCC_ECR_RN_E12_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E12_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E18_MASK                             (0x00040000U)
#define CSL_EVETPCC_ECR_RN_E18_SHIFT                            (18U)
#define CSL_EVETPCC_ECR_RN_E18_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E18_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E11_MASK                             (0x00000800U)
#define CSL_EVETPCC_ECR_RN_E11_SHIFT                            (11U)
#define CSL_EVETPCC_ECR_RN_E11_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E11_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E21_MASK                             (0x00200000U)
#define CSL_EVETPCC_ECR_RN_E21_SHIFT                            (21U)
#define CSL_EVETPCC_ECR_RN_E21_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E21_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E31_MASK                             (0x80000000U)
#define CSL_EVETPCC_ECR_RN_E31_SHIFT                            (31U)
#define CSL_EVETPCC_ECR_RN_E31_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E31_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E14_MASK                             (0x00004000U)
#define CSL_EVETPCC_ECR_RN_E14_SHIFT                            (14U)
#define CSL_EVETPCC_ECR_RN_E14_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E14_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E26_MASK                             (0x04000000U)
#define CSL_EVETPCC_ECR_RN_E26_SHIFT                            (26U)
#define CSL_EVETPCC_ECR_RN_E26_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E26_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E13_MASK                             (0x00002000U)
#define CSL_EVETPCC_ECR_RN_E13_SHIFT                            (13U)
#define CSL_EVETPCC_ECR_RN_E13_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E13_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E25_MASK                             (0x02000000U)
#define CSL_EVETPCC_ECR_RN_E25_SHIFT                            (25U)
#define CSL_EVETPCC_ECR_RN_E25_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E25_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E15_MASK                             (0x00008000U)
#define CSL_EVETPCC_ECR_RN_E15_SHIFT                            (15U)
#define CSL_EVETPCC_ECR_RN_E15_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E15_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E28_MASK                             (0x10000000U)
#define CSL_EVETPCC_ECR_RN_E28_SHIFT                            (28U)
#define CSL_EVETPCC_ECR_RN_E28_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E28_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E17_MASK                             (0x00020000U)
#define CSL_EVETPCC_ECR_RN_E17_SHIFT                            (17U)
#define CSL_EVETPCC_ECR_RN_E17_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E17_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E27_MASK                             (0x08000000U)
#define CSL_EVETPCC_ECR_RN_E27_SHIFT                            (27U)
#define CSL_EVETPCC_ECR_RN_E27_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E27_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E4_MASK                              (0x00000010U)
#define CSL_EVETPCC_ECR_RN_E4_SHIFT                             (4U)
#define CSL_EVETPCC_ECR_RN_E4_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E4_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E24_MASK                             (0x01000000U)
#define CSL_EVETPCC_ECR_RN_E24_SHIFT                            (24U)
#define CSL_EVETPCC_ECR_RN_E24_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E24_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E2_MASK                              (0x00000004U)
#define CSL_EVETPCC_ECR_RN_E2_SHIFT                             (2U)
#define CSL_EVETPCC_ECR_RN_E2_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E2_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E3_MASK                              (0x00000008U)
#define CSL_EVETPCC_ECR_RN_E3_SHIFT                             (3U)
#define CSL_EVETPCC_ECR_RN_E3_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E3_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E0_MASK                              (0x00000001U)
#define CSL_EVETPCC_ECR_RN_E0_SHIFT                             (0U)
#define CSL_EVETPCC_ECR_RN_E0_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E0_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E20_MASK                             (0x00100000U)
#define CSL_EVETPCC_ECR_RN_E20_SHIFT                            (20U)
#define CSL_EVETPCC_ECR_RN_E20_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E20_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E6_MASK                              (0x00000040U)
#define CSL_EVETPCC_ECR_RN_E6_SHIFT                             (6U)
#define CSL_EVETPCC_ECR_RN_E6_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E6_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E1_MASK                              (0x00000002U)
#define CSL_EVETPCC_ECR_RN_E1_SHIFT                             (1U)
#define CSL_EVETPCC_ECR_RN_E1_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E1_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E5_MASK                              (0x00000020U)
#define CSL_EVETPCC_ECR_RN_E5_SHIFT                             (5U)
#define CSL_EVETPCC_ECR_RN_E5_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E5_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E23_MASK                             (0x00800000U)
#define CSL_EVETPCC_ECR_RN_E23_SHIFT                            (23U)
#define CSL_EVETPCC_ECR_RN_E23_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E23_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E8_MASK                              (0x00000100U)
#define CSL_EVETPCC_ECR_RN_E8_SHIFT                             (8U)
#define CSL_EVETPCC_ECR_RN_E8_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E8_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E9_MASK                              (0x00000200U)
#define CSL_EVETPCC_ECR_RN_E9_SHIFT                             (9U)
#define CSL_EVETPCC_ECR_RN_E9_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E9_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E22_MASK                             (0x00400000U)
#define CSL_EVETPCC_ECR_RN_E22_SHIFT                            (22U)
#define CSL_EVETPCC_ECR_RN_E22_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E22_MAX                              (0x00000001U)

#define CSL_EVETPCC_ECR_RN_E7_MASK                              (0x00000080U)
#define CSL_EVETPCC_ECR_RN_E7_SHIFT                             (7U)
#define CSL_EVETPCC_ECR_RN_E7_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_ECR_RN_E7_MAX                               (0x00000001U)

#define CSL_EVETPCC_ECR_RN_RESETVAL                             (0x00000000U)

/* EERH_RN */

#define CSL_EVETPCC_EERH_RN_E47_MASK                            (0x00008000U)
#define CSL_EVETPCC_EERH_RN_E47_SHIFT                           (15U)
#define CSL_EVETPCC_EERH_RN_E47_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E47_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E45_MASK                            (0x00002000U)
#define CSL_EVETPCC_EERH_RN_E45_SHIFT                           (13U)
#define CSL_EVETPCC_EERH_RN_E45_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E45_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E35_MASK                            (0x00000008U)
#define CSL_EVETPCC_EERH_RN_E35_SHIFT                           (3U)
#define CSL_EVETPCC_EERH_RN_E35_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E35_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E56_MASK                            (0x01000000U)
#define CSL_EVETPCC_EERH_RN_E56_SHIFT                           (24U)
#define CSL_EVETPCC_EERH_RN_E56_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E56_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E46_MASK                            (0x00004000U)
#define CSL_EVETPCC_EERH_RN_E46_SHIFT                           (14U)
#define CSL_EVETPCC_EERH_RN_E46_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E46_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E36_MASK                            (0x00000010U)
#define CSL_EVETPCC_EERH_RN_E36_SHIFT                           (4U)
#define CSL_EVETPCC_EERH_RN_E36_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E36_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E55_MASK                            (0x00800000U)
#define CSL_EVETPCC_EERH_RN_E55_SHIFT                           (23U)
#define CSL_EVETPCC_EERH_RN_E55_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E55_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E33_MASK                            (0x00000002U)
#define CSL_EVETPCC_EERH_RN_E33_SHIFT                           (1U)
#define CSL_EVETPCC_EERH_RN_E33_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E33_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E54_MASK                            (0x00400000U)
#define CSL_EVETPCC_EERH_RN_E54_SHIFT                           (22U)
#define CSL_EVETPCC_EERH_RN_E54_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E54_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E43_MASK                            (0x00000800U)
#define CSL_EVETPCC_EERH_RN_E43_SHIFT                           (11U)
#define CSL_EVETPCC_EERH_RN_E43_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E43_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E53_MASK                            (0x00200000U)
#define CSL_EVETPCC_EERH_RN_E53_SHIFT                           (21U)
#define CSL_EVETPCC_EERH_RN_E53_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E53_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E63_MASK                            (0x80000000U)
#define CSL_EVETPCC_EERH_RN_E63_SHIFT                           (31U)
#define CSL_EVETPCC_EERH_RN_E63_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E63_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E34_MASK                            (0x00000004U)
#define CSL_EVETPCC_EERH_RN_E34_SHIFT                           (2U)
#define CSL_EVETPCC_EERH_RN_E34_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E34_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E44_MASK                            (0x00001000U)
#define CSL_EVETPCC_EERH_RN_E44_SHIFT                           (12U)
#define CSL_EVETPCC_EERH_RN_E44_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E44_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E52_MASK                            (0x00100000U)
#define CSL_EVETPCC_EERH_RN_E52_SHIFT                           (20U)
#define CSL_EVETPCC_EERH_RN_E52_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E52_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E41_MASK                            (0x00000200U)
#define CSL_EVETPCC_EERH_RN_E41_SHIFT                           (9U)
#define CSL_EVETPCC_EERH_RN_E41_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E41_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E62_MASK                            (0x40000000U)
#define CSL_EVETPCC_EERH_RN_E62_SHIFT                           (30U)
#define CSL_EVETPCC_EERH_RN_E62_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E62_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E32_MASK                            (0x00000001U)
#define CSL_EVETPCC_EERH_RN_E32_SHIFT                           (0U)
#define CSL_EVETPCC_EERH_RN_E32_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E32_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E51_MASK                            (0x00080000U)
#define CSL_EVETPCC_EERH_RN_E51_SHIFT                           (19U)
#define CSL_EVETPCC_EERH_RN_E51_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E51_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E42_MASK                            (0x00000400U)
#define CSL_EVETPCC_EERH_RN_E42_SHIFT                           (10U)
#define CSL_EVETPCC_EERH_RN_E42_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E42_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E61_MASK                            (0x20000000U)
#define CSL_EVETPCC_EERH_RN_E61_SHIFT                           (29U)
#define CSL_EVETPCC_EERH_RN_E61_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E61_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E50_MASK                            (0x00040000U)
#define CSL_EVETPCC_EERH_RN_E50_SHIFT                           (18U)
#define CSL_EVETPCC_EERH_RN_E50_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E50_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E39_MASK                            (0x00000080U)
#define CSL_EVETPCC_EERH_RN_E39_SHIFT                           (7U)
#define CSL_EVETPCC_EERH_RN_E39_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E39_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E60_MASK                            (0x10000000U)
#define CSL_EVETPCC_EERH_RN_E60_SHIFT                           (28U)
#define CSL_EVETPCC_EERH_RN_E60_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E60_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E49_MASK                            (0x00020000U)
#define CSL_EVETPCC_EERH_RN_E49_SHIFT                           (17U)
#define CSL_EVETPCC_EERH_RN_E49_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E49_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E40_MASK                            (0x00000100U)
#define CSL_EVETPCC_EERH_RN_E40_SHIFT                           (8U)
#define CSL_EVETPCC_EERH_RN_E40_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E40_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E59_MASK                            (0x08000000U)
#define CSL_EVETPCC_EERH_RN_E59_SHIFT                           (27U)
#define CSL_EVETPCC_EERH_RN_E59_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E59_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E48_MASK                            (0x00010000U)
#define CSL_EVETPCC_EERH_RN_E48_SHIFT                           (16U)
#define CSL_EVETPCC_EERH_RN_E48_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E48_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E58_MASK                            (0x04000000U)
#define CSL_EVETPCC_EERH_RN_E58_SHIFT                           (26U)
#define CSL_EVETPCC_EERH_RN_E58_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E58_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E37_MASK                            (0x00000020U)
#define CSL_EVETPCC_EERH_RN_E37_SHIFT                           (5U)
#define CSL_EVETPCC_EERH_RN_E37_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E37_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E57_MASK                            (0x02000000U)
#define CSL_EVETPCC_EERH_RN_E57_SHIFT                           (25U)
#define CSL_EVETPCC_EERH_RN_E57_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E57_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_E38_MASK                            (0x00000040U)
#define CSL_EVETPCC_EERH_RN_E38_SHIFT                           (6U)
#define CSL_EVETPCC_EERH_RN_E38_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_EERH_RN_E38_MAX                             (0x00000001U)

#define CSL_EVETPCC_EERH_RN_RESETVAL                            (0x00000000U)

/* IPR_RN */

#define CSL_EVETPCC_IPR_RN_I15_MASK                             (0x00008000U)
#define CSL_EVETPCC_IPR_RN_I15_SHIFT                            (15U)
#define CSL_EVETPCC_IPR_RN_I15_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I15_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I27_MASK                             (0x08000000U)
#define CSL_EVETPCC_IPR_RN_I27_SHIFT                            (27U)
#define CSL_EVETPCC_IPR_RN_I27_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I27_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I3_MASK                              (0x00000008U)
#define CSL_EVETPCC_IPR_RN_I3_SHIFT                             (3U)
#define CSL_EVETPCC_IPR_RN_I3_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I3_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I14_MASK                             (0x00004000U)
#define CSL_EVETPCC_IPR_RN_I14_SHIFT                            (14U)
#define CSL_EVETPCC_IPR_RN_I14_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I14_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I2_MASK                              (0x00000004U)
#define CSL_EVETPCC_IPR_RN_I2_SHIFT                             (2U)
#define CSL_EVETPCC_IPR_RN_I2_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I2_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I1_MASK                              (0x00000002U)
#define CSL_EVETPCC_IPR_RN_I1_SHIFT                             (1U)
#define CSL_EVETPCC_IPR_RN_I1_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I1_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I13_MASK                             (0x00002000U)
#define CSL_EVETPCC_IPR_RN_I13_SHIFT                            (13U)
#define CSL_EVETPCC_IPR_RN_I13_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I13_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I28_MASK                             (0x10000000U)
#define CSL_EVETPCC_IPR_RN_I28_SHIFT                            (28U)
#define CSL_EVETPCC_IPR_RN_I28_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I28_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I17_MASK                             (0x00020000U)
#define CSL_EVETPCC_IPR_RN_I17_SHIFT                            (17U)
#define CSL_EVETPCC_IPR_RN_I17_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I17_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I0_MASK                              (0x00000001U)
#define CSL_EVETPCC_IPR_RN_I0_SHIFT                             (0U)
#define CSL_EVETPCC_IPR_RN_I0_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I0_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I12_MASK                             (0x00001000U)
#define CSL_EVETPCC_IPR_RN_I12_SHIFT                            (12U)
#define CSL_EVETPCC_IPR_RN_I12_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I12_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I29_MASK                             (0x20000000U)
#define CSL_EVETPCC_IPR_RN_I29_SHIFT                            (29U)
#define CSL_EVETPCC_IPR_RN_I29_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I29_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I6_MASK                              (0x00000040U)
#define CSL_EVETPCC_IPR_RN_I6_SHIFT                             (6U)
#define CSL_EVETPCC_IPR_RN_I6_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I6_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I26_MASK                             (0x04000000U)
#define CSL_EVETPCC_IPR_RN_I26_SHIFT                            (26U)
#define CSL_EVETPCC_IPR_RN_I26_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I26_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I5_MASK                              (0x00000020U)
#define CSL_EVETPCC_IPR_RN_I5_SHIFT                             (5U)
#define CSL_EVETPCC_IPR_RN_I5_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I5_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I4_MASK                              (0x00000010U)
#define CSL_EVETPCC_IPR_RN_I4_SHIFT                             (4U)
#define CSL_EVETPCC_IPR_RN_I4_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I4_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I16_MASK                             (0x00010000U)
#define CSL_EVETPCC_IPR_RN_I16_SHIFT                            (16U)
#define CSL_EVETPCC_IPR_RN_I16_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I16_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I23_MASK                             (0x00800000U)
#define CSL_EVETPCC_IPR_RN_I23_SHIFT                            (23U)
#define CSL_EVETPCC_IPR_RN_I23_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I23_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I7_MASK                              (0x00000080U)
#define CSL_EVETPCC_IPR_RN_I7_SHIFT                             (7U)
#define CSL_EVETPCC_IPR_RN_I7_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I7_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I22_MASK                             (0x00400000U)
#define CSL_EVETPCC_IPR_RN_I22_SHIFT                            (22U)
#define CSL_EVETPCC_IPR_RN_I22_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I22_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I25_MASK                             (0x02000000U)
#define CSL_EVETPCC_IPR_RN_I25_SHIFT                            (25U)
#define CSL_EVETPCC_IPR_RN_I25_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I25_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I24_MASK                             (0x01000000U)
#define CSL_EVETPCC_IPR_RN_I24_SHIFT                            (24U)
#define CSL_EVETPCC_IPR_RN_I24_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I24_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I19_MASK                             (0x00080000U)
#define CSL_EVETPCC_IPR_RN_I19_SHIFT                            (19U)
#define CSL_EVETPCC_IPR_RN_I19_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I19_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I30_MASK                             (0x40000000U)
#define CSL_EVETPCC_IPR_RN_I30_SHIFT                            (30U)
#define CSL_EVETPCC_IPR_RN_I30_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I30_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I11_MASK                             (0x00000800U)
#define CSL_EVETPCC_IPR_RN_I11_SHIFT                            (11U)
#define CSL_EVETPCC_IPR_RN_I11_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I11_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I18_MASK                             (0x00040000U)
#define CSL_EVETPCC_IPR_RN_I18_SHIFT                            (18U)
#define CSL_EVETPCC_IPR_RN_I18_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I18_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I31_MASK                             (0x80000000U)
#define CSL_EVETPCC_IPR_RN_I31_SHIFT                            (31U)
#define CSL_EVETPCC_IPR_RN_I31_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I31_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I10_MASK                             (0x00000400U)
#define CSL_EVETPCC_IPR_RN_I10_SHIFT                            (10U)
#define CSL_EVETPCC_IPR_RN_I10_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I10_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I9_MASK                              (0x00000200U)
#define CSL_EVETPCC_IPR_RN_I9_SHIFT                             (9U)
#define CSL_EVETPCC_IPR_RN_I9_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I9_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I21_MASK                             (0x00200000U)
#define CSL_EVETPCC_IPR_RN_I21_SHIFT                            (21U)
#define CSL_EVETPCC_IPR_RN_I21_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I21_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I8_MASK                              (0x00000100U)
#define CSL_EVETPCC_IPR_RN_I8_SHIFT                             (8U)
#define CSL_EVETPCC_IPR_RN_I8_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I8_MAX                               (0x00000001U)

#define CSL_EVETPCC_IPR_RN_I20_MASK                             (0x00100000U)
#define CSL_EVETPCC_IPR_RN_I20_SHIFT                            (20U)
#define CSL_EVETPCC_IPR_RN_I20_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_IPR_RN_I20_MAX                              (0x00000001U)

#define CSL_EVETPCC_IPR_RN_RESETVAL                             (0x00000000U)

/* ESRH_RN */

#define CSL_EVETPCC_ESRH_RN_E41_MASK                            (0x00000200U)
#define CSL_EVETPCC_ESRH_RN_E41_SHIFT                           (9U)
#define CSL_EVETPCC_ESRH_RN_E41_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E41_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E57_MASK                            (0x02000000U)
#define CSL_EVETPCC_ESRH_RN_E57_SHIFT                           (25U)
#define CSL_EVETPCC_ESRH_RN_E57_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E57_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E46_MASK                            (0x00004000U)
#define CSL_EVETPCC_ESRH_RN_E46_SHIFT                           (14U)
#define CSL_EVETPCC_ESRH_RN_E46_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E46_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E42_MASK                            (0x00000400U)
#define CSL_EVETPCC_ESRH_RN_E42_SHIFT                           (10U)
#define CSL_EVETPCC_ESRH_RN_E42_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E42_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E56_MASK                            (0x01000000U)
#define CSL_EVETPCC_ESRH_RN_E56_SHIFT                           (24U)
#define CSL_EVETPCC_ESRH_RN_E56_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E56_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E33_MASK                            (0x00000002U)
#define CSL_EVETPCC_ESRH_RN_E33_SHIFT                           (1U)
#define CSL_EVETPCC_ESRH_RN_E33_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E33_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E43_MASK                            (0x00000800U)
#define CSL_EVETPCC_ESRH_RN_E43_SHIFT                           (11U)
#define CSL_EVETPCC_ESRH_RN_E43_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E43_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E55_MASK                            (0x00800000U)
#define CSL_EVETPCC_ESRH_RN_E55_SHIFT                           (23U)
#define CSL_EVETPCC_ESRH_RN_E55_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E55_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E32_MASK                            (0x00000001U)
#define CSL_EVETPCC_ESRH_RN_E32_SHIFT                           (0U)
#define CSL_EVETPCC_ESRH_RN_E32_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E32_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E48_MASK                            (0x00010000U)
#define CSL_EVETPCC_ESRH_RN_E48_SHIFT                           (16U)
#define CSL_EVETPCC_ESRH_RN_E48_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E48_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E44_MASK                            (0x00001000U)
#define CSL_EVETPCC_ESRH_RN_E44_SHIFT                           (12U)
#define CSL_EVETPCC_ESRH_RN_E44_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E44_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E45_MASK                            (0x00002000U)
#define CSL_EVETPCC_ESRH_RN_E45_SHIFT                           (13U)
#define CSL_EVETPCC_ESRH_RN_E45_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E45_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E49_MASK                            (0x00020000U)
#define CSL_EVETPCC_ESRH_RN_E49_SHIFT                           (17U)
#define CSL_EVETPCC_ESRH_RN_E49_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E49_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E61_MASK                            (0x20000000U)
#define CSL_EVETPCC_ESRH_RN_E61_SHIFT                           (29U)
#define CSL_EVETPCC_ESRH_RN_E61_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E61_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E52_MASK                            (0x00100000U)
#define CSL_EVETPCC_ESRH_RN_E52_SHIFT                           (20U)
#define CSL_EVETPCC_ESRH_RN_E52_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E52_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E63_MASK                            (0x80000000U)
#define CSL_EVETPCC_ESRH_RN_E63_SHIFT                           (31U)
#define CSL_EVETPCC_ESRH_RN_E63_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E63_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E34_MASK                            (0x00000004U)
#define CSL_EVETPCC_ESRH_RN_E34_SHIFT                           (2U)
#define CSL_EVETPCC_ESRH_RN_E34_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E34_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E47_MASK                            (0x00008000U)
#define CSL_EVETPCC_ESRH_RN_E47_SHIFT                           (15U)
#define CSL_EVETPCC_ESRH_RN_E47_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E47_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E60_MASK                            (0x10000000U)
#define CSL_EVETPCC_ESRH_RN_E60_SHIFT                           (28U)
#define CSL_EVETPCC_ESRH_RN_E60_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E60_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E59_MASK                            (0x08000000U)
#define CSL_EVETPCC_ESRH_RN_E59_SHIFT                           (27U)
#define CSL_EVETPCC_ESRH_RN_E59_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E59_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E50_MASK                            (0x00040000U)
#define CSL_EVETPCC_ESRH_RN_E50_SHIFT                           (18U)
#define CSL_EVETPCC_ESRH_RN_E50_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E50_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E58_MASK                            (0x04000000U)
#define CSL_EVETPCC_ESRH_RN_E58_SHIFT                           (26U)
#define CSL_EVETPCC_ESRH_RN_E58_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E58_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E53_MASK                            (0x00200000U)
#define CSL_EVETPCC_ESRH_RN_E53_SHIFT                           (21U)
#define CSL_EVETPCC_ESRH_RN_E53_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E53_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E35_MASK                            (0x00000008U)
#define CSL_EVETPCC_ESRH_RN_E35_SHIFT                           (3U)
#define CSL_EVETPCC_ESRH_RN_E35_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E35_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E51_MASK                            (0x00080000U)
#define CSL_EVETPCC_ESRH_RN_E51_SHIFT                           (19U)
#define CSL_EVETPCC_ESRH_RN_E51_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E51_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E54_MASK                            (0x00400000U)
#define CSL_EVETPCC_ESRH_RN_E54_SHIFT                           (22U)
#define CSL_EVETPCC_ESRH_RN_E54_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E54_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E36_MASK                            (0x00000010U)
#define CSL_EVETPCC_ESRH_RN_E36_SHIFT                           (4U)
#define CSL_EVETPCC_ESRH_RN_E36_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E36_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E62_MASK                            (0x40000000U)
#define CSL_EVETPCC_ESRH_RN_E62_SHIFT                           (30U)
#define CSL_EVETPCC_ESRH_RN_E62_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E62_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E37_MASK                            (0x00000020U)
#define CSL_EVETPCC_ESRH_RN_E37_SHIFT                           (5U)
#define CSL_EVETPCC_ESRH_RN_E37_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E37_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E38_MASK                            (0x00000040U)
#define CSL_EVETPCC_ESRH_RN_E38_SHIFT                           (6U)
#define CSL_EVETPCC_ESRH_RN_E38_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E38_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E39_MASK                            (0x00000080U)
#define CSL_EVETPCC_ESRH_RN_E39_SHIFT                           (7U)
#define CSL_EVETPCC_ESRH_RN_E39_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E39_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_E40_MASK                            (0x00000100U)
#define CSL_EVETPCC_ESRH_RN_E40_SHIFT                           (8U)
#define CSL_EVETPCC_ESRH_RN_E40_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_ESRH_RN_E40_MAX                             (0x00000001U)

#define CSL_EVETPCC_ESRH_RN_RESETVAL                            (0x00000000U)

/* QEESR_RN */

#define CSL_EVETPCC_QEESR_RN_E5_MASK                            (0x00000020U)
#define CSL_EVETPCC_QEESR_RN_E5_SHIFT                           (5U)
#define CSL_EVETPCC_QEESR_RN_E5_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEESR_RN_E5_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEESR_RN_E3_MASK                            (0x00000008U)
#define CSL_EVETPCC_QEESR_RN_E3_SHIFT                           (3U)
#define CSL_EVETPCC_QEESR_RN_E3_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEESR_RN_E3_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEESR_RN_E6_MASK                            (0x00000040U)
#define CSL_EVETPCC_QEESR_RN_E6_SHIFT                           (6U)
#define CSL_EVETPCC_QEESR_RN_E6_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEESR_RN_E6_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEESR_RN_E4_MASK                            (0x00000010U)
#define CSL_EVETPCC_QEESR_RN_E4_SHIFT                           (4U)
#define CSL_EVETPCC_QEESR_RN_E4_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEESR_RN_E4_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEESR_RN_E1_MASK                            (0x00000002U)
#define CSL_EVETPCC_QEESR_RN_E1_SHIFT                           (1U)
#define CSL_EVETPCC_QEESR_RN_E1_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEESR_RN_E1_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEESR_RN_E2_MASK                            (0x00000004U)
#define CSL_EVETPCC_QEESR_RN_E2_SHIFT                           (2U)
#define CSL_EVETPCC_QEESR_RN_E2_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEESR_RN_E2_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEESR_RN_E0_MASK                            (0x00000001U)
#define CSL_EVETPCC_QEESR_RN_E0_SHIFT                           (0U)
#define CSL_EVETPCC_QEESR_RN_E0_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEESR_RN_E0_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEESR_RN_E7_MASK                            (0x00000080U)
#define CSL_EVETPCC_QEESR_RN_E7_SHIFT                           (7U)
#define CSL_EVETPCC_QEESR_RN_E7_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_QEESR_RN_E7_MAX                             (0x00000001U)

#define CSL_EVETPCC_QEESR_RN_RESETVAL                           (0x00000000U)

/* ERH_RN */

#define CSL_EVETPCC_ERH_RN_E61_MASK                             (0x20000000U)
#define CSL_EVETPCC_ERH_RN_E61_SHIFT                            (29U)
#define CSL_EVETPCC_ERH_RN_E61_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E61_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E54_MASK                             (0x00400000U)
#define CSL_EVETPCC_ERH_RN_E54_SHIFT                            (22U)
#define CSL_EVETPCC_ERH_RN_E54_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E54_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E55_MASK                             (0x00800000U)
#define CSL_EVETPCC_ERH_RN_E55_SHIFT                            (23U)
#define CSL_EVETPCC_ERH_RN_E55_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E55_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E59_MASK                             (0x08000000U)
#define CSL_EVETPCC_ERH_RN_E59_SHIFT                            (27U)
#define CSL_EVETPCC_ERH_RN_E59_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E59_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E50_MASK                             (0x00040000U)
#define CSL_EVETPCC_ERH_RN_E50_SHIFT                            (18U)
#define CSL_EVETPCC_ERH_RN_E50_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E50_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E52_MASK                             (0x00100000U)
#define CSL_EVETPCC_ERH_RN_E52_SHIFT                            (20U)
#define CSL_EVETPCC_ERH_RN_E52_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E52_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E53_MASK                             (0x00200000U)
#define CSL_EVETPCC_ERH_RN_E53_SHIFT                            (21U)
#define CSL_EVETPCC_ERH_RN_E53_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E53_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E51_MASK                             (0x00080000U)
#define CSL_EVETPCC_ERH_RN_E51_SHIFT                            (19U)
#define CSL_EVETPCC_ERH_RN_E51_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E51_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E36_MASK                             (0x00000010U)
#define CSL_EVETPCC_ERH_RN_E36_SHIFT                            (4U)
#define CSL_EVETPCC_ERH_RN_E36_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E36_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E40_MASK                             (0x00000100U)
#define CSL_EVETPCC_ERH_RN_E40_SHIFT                            (8U)
#define CSL_EVETPCC_ERH_RN_E40_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E40_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E39_MASK                             (0x00000080U)
#define CSL_EVETPCC_ERH_RN_E39_SHIFT                            (7U)
#define CSL_EVETPCC_ERH_RN_E39_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E39_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E38_MASK                             (0x00000040U)
#define CSL_EVETPCC_ERH_RN_E38_SHIFT                            (6U)
#define CSL_EVETPCC_ERH_RN_E38_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E38_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E42_MASK                             (0x00000400U)
#define CSL_EVETPCC_ERH_RN_E42_SHIFT                            (10U)
#define CSL_EVETPCC_ERH_RN_E42_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E42_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E49_MASK                             (0x00020000U)
#define CSL_EVETPCC_ERH_RN_E49_SHIFT                            (17U)
#define CSL_EVETPCC_ERH_RN_E49_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E49_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E41_MASK                             (0x00000200U)
#define CSL_EVETPCC_ERH_RN_E41_SHIFT                            (9U)
#define CSL_EVETPCC_ERH_RN_E41_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E41_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E32_MASK                             (0x00000001U)
#define CSL_EVETPCC_ERH_RN_E32_SHIFT                            (0U)
#define CSL_EVETPCC_ERH_RN_E32_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E32_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E35_MASK                             (0x00000008U)
#define CSL_EVETPCC_ERH_RN_E35_SHIFT                            (3U)
#define CSL_EVETPCC_ERH_RN_E35_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E35_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E43_MASK                             (0x00000800U)
#define CSL_EVETPCC_ERH_RN_E43_SHIFT                            (11U)
#define CSL_EVETPCC_ERH_RN_E43_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E43_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E34_MASK                             (0x00000004U)
#define CSL_EVETPCC_ERH_RN_E34_SHIFT                            (2U)
#define CSL_EVETPCC_ERH_RN_E34_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E34_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E44_MASK                             (0x00001000U)
#define CSL_EVETPCC_ERH_RN_E44_SHIFT                            (12U)
#define CSL_EVETPCC_ERH_RN_E44_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E44_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E37_MASK                             (0x00000020U)
#define CSL_EVETPCC_ERH_RN_E37_SHIFT                            (5U)
#define CSL_EVETPCC_ERH_RN_E37_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E37_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E45_MASK                             (0x00002000U)
#define CSL_EVETPCC_ERH_RN_E45_SHIFT                            (13U)
#define CSL_EVETPCC_ERH_RN_E45_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E45_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E58_MASK                             (0x04000000U)
#define CSL_EVETPCC_ERH_RN_E58_SHIFT                            (26U)
#define CSL_EVETPCC_ERH_RN_E58_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E58_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E62_MASK                             (0x40000000U)
#define CSL_EVETPCC_ERH_RN_E62_SHIFT                            (30U)
#define CSL_EVETPCC_ERH_RN_E62_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E62_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E46_MASK                             (0x00004000U)
#define CSL_EVETPCC_ERH_RN_E46_SHIFT                            (14U)
#define CSL_EVETPCC_ERH_RN_E46_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E46_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E57_MASK                             (0x02000000U)
#define CSL_EVETPCC_ERH_RN_E57_SHIFT                            (25U)
#define CSL_EVETPCC_ERH_RN_E57_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E57_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E63_MASK                             (0x80000000U)
#define CSL_EVETPCC_ERH_RN_E63_SHIFT                            (31U)
#define CSL_EVETPCC_ERH_RN_E63_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E63_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E47_MASK                             (0x00008000U)
#define CSL_EVETPCC_ERH_RN_E47_SHIFT                            (15U)
#define CSL_EVETPCC_ERH_RN_E47_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E47_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E56_MASK                             (0x01000000U)
#define CSL_EVETPCC_ERH_RN_E56_SHIFT                            (24U)
#define CSL_EVETPCC_ERH_RN_E56_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E56_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E48_MASK                             (0x00010000U)
#define CSL_EVETPCC_ERH_RN_E48_SHIFT                            (16U)
#define CSL_EVETPCC_ERH_RN_E48_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E48_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E33_MASK                             (0x00000002U)
#define CSL_EVETPCC_ERH_RN_E33_SHIFT                            (1U)
#define CSL_EVETPCC_ERH_RN_E33_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E33_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_E60_MASK                             (0x10000000U)
#define CSL_EVETPCC_ERH_RN_E60_SHIFT                            (28U)
#define CSL_EVETPCC_ERH_RN_E60_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ERH_RN_E60_MAX                              (0x00000001U)

#define CSL_EVETPCC_ERH_RN_RESETVAL                             (0x00000000U)

/* OPT */

#define CSL_EVETPCC_OPT_PRIV_MASK                               (0x80000000U)
#define CSL_EVETPCC_OPT_PRIV_SHIFT                              (31U)
#define CSL_EVETPCC_OPT_PRIV_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_OPT_PRIV_MAX                                (0x00000001U)

#define CSL_EVETPCC_OPT_SECURE_MASK                             (0x40000000U)
#define CSL_EVETPCC_OPT_SECURE_SHIFT                            (30U)
#define CSL_EVETPCC_OPT_SECURE_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_OPT_SECURE_MAX                              (0x00000001U)

#define CSL_EVETPCC_OPT_PRIVID_MASK                             (0x0F000000U)
#define CSL_EVETPCC_OPT_PRIVID_SHIFT                            (24U)
#define CSL_EVETPCC_OPT_PRIVID_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_OPT_PRIVID_MAX                              (0x0000000fU)

#define CSL_EVETPCC_OPT_ITCCHEN_MASK                            (0x00800000U)
#define CSL_EVETPCC_OPT_ITCCHEN_SHIFT                           (23U)
#define CSL_EVETPCC_OPT_ITCCHEN_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_OPT_ITCCHEN_MAX                             (0x00000001U)

#define CSL_EVETPCC_OPT_TCCHEN_MASK                             (0x00400000U)
#define CSL_EVETPCC_OPT_TCCHEN_SHIFT                            (22U)
#define CSL_EVETPCC_OPT_TCCHEN_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_OPT_TCCHEN_MAX                              (0x00000001U)

#define CSL_EVETPCC_OPT_ITCINTEN_MASK                           (0x00200000U)
#define CSL_EVETPCC_OPT_ITCINTEN_SHIFT                          (21U)
#define CSL_EVETPCC_OPT_ITCINTEN_RESETVAL                       (0x00000000U)
#define CSL_EVETPCC_OPT_ITCINTEN_MAX                            (0x00000001U)

#define CSL_EVETPCC_OPT_TCINTEN_MASK                            (0x00100000U)
#define CSL_EVETPCC_OPT_TCINTEN_SHIFT                           (20U)
#define CSL_EVETPCC_OPT_TCINTEN_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_OPT_TCINTEN_MAX                             (0x00000001U)

#define CSL_EVETPCC_OPT_WIMODE_MASK                             (0x00080000U)
#define CSL_EVETPCC_OPT_WIMODE_SHIFT                            (19U)
#define CSL_EVETPCC_OPT_WIMODE_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_OPT_WIMODE_MAX                              (0x00000001U)

#define CSL_EVETPCC_OPT_TCC_MASK                                (0x0003F000U)
#define CSL_EVETPCC_OPT_TCC_SHIFT                               (12U)
#define CSL_EVETPCC_OPT_TCC_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_OPT_TCC_MAX                                 (0x0000003fU)

#define CSL_EVETPCC_OPT_TCCMODE_MASK                            (0x00000800U)
#define CSL_EVETPCC_OPT_TCCMODE_SHIFT                           (11U)
#define CSL_EVETPCC_OPT_TCCMODE_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_OPT_TCCMODE_MAX                             (0x00000001U)

#define CSL_EVETPCC_OPT_FWID_MASK                               (0x00000700U)
#define CSL_EVETPCC_OPT_FWID_SHIFT                              (8U)
#define CSL_EVETPCC_OPT_FWID_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_OPT_FWID_FIFOWIDTH256BIT                    (0x00000005U)
#define CSL_EVETPCC_OPT_FWID_FIFOWIDTH128BIT                    (0x00000004U)
#define CSL_EVETPCC_OPT_FWID_FIFOWIDTH64BIT                     (0x00000003U)
#define CSL_EVETPCC_OPT_FWID_FIFOWIDTH32BIT                     (0x00000002U)
#define CSL_EVETPCC_OPT_FWID_FIFOWIDTH16BIT                     (0x00000001U)
#define CSL_EVETPCC_OPT_FWID_FIFOWIDTH8BIT                      (0x00000000U)

#define CSL_EVETPCC_OPT_STATIC_MASK                             (0x00000008U)
#define CSL_EVETPCC_OPT_STATIC_SHIFT                            (3U)
#define CSL_EVETPCC_OPT_STATIC_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_OPT_STATIC_MAX                              (0x00000001U)

#define CSL_EVETPCC_OPT_SYNCDIM_MASK                            (0x00000004U)
#define CSL_EVETPCC_OPT_SYNCDIM_SHIFT                           (2U)
#define CSL_EVETPCC_OPT_SYNCDIM_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_OPT_SYNCDIM_MAX                             (0x00000001U)

#define CSL_EVETPCC_OPT_DAM_MASK                                (0x00000002U)
#define CSL_EVETPCC_OPT_DAM_SHIFT                               (1U)
#define CSL_EVETPCC_OPT_DAM_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_OPT_DAM_MAX                                 (0x00000001U)

#define CSL_EVETPCC_OPT_SAM_MASK                                (0x00000001U)
#define CSL_EVETPCC_OPT_SAM_SHIFT                               (0U)
#define CSL_EVETPCC_OPT_SAM_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_OPT_SAM_MAX                                 (0x00000001U)

#define CSL_EVETPCC_OPT_RESETVAL                                (0x00000000U)

/* SRC */

#define CSL_EVETPCC_SRC_SRC_MASK                                (0xFFFFFFFFU)
#define CSL_EVETPCC_SRC_SRC_SHIFT                               (0U)
#define CSL_EVETPCC_SRC_SRC_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_SRC_SRC_MAX                                 (0xffffffffU)

#define CSL_EVETPCC_SRC_RESETVAL                                (0x00000000U)

/* ABCNT */

#define CSL_EVETPCC_ABCNT_ACNT_MASK                             (0x0000FFFFU)
#define CSL_EVETPCC_ABCNT_ACNT_SHIFT                            (0U)
#define CSL_EVETPCC_ABCNT_ACNT_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ABCNT_ACNT_MAX                              (0x0000ffffU)

#define CSL_EVETPCC_ABCNT_BCNT_MASK                             (0xFFFF0000U)
#define CSL_EVETPCC_ABCNT_BCNT_SHIFT                            (16U)
#define CSL_EVETPCC_ABCNT_BCNT_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_ABCNT_BCNT_MAX                              (0x0000ffffU)

#define CSL_EVETPCC_ABCNT_RESETVAL                              (0x00000000U)

/* BIDX */

#define CSL_EVETPCC_BIDX_SBIDX_MASK                             (0x0000FFFFU)
#define CSL_EVETPCC_BIDX_SBIDX_SHIFT                            (0U)
#define CSL_EVETPCC_BIDX_SBIDX_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_BIDX_SBIDX_MAX                              (0x0000ffffU)

#define CSL_EVETPCC_BIDX_DBIDX_MASK                             (0xFFFF0000U)
#define CSL_EVETPCC_BIDX_DBIDX_SHIFT                            (16U)
#define CSL_EVETPCC_BIDX_DBIDX_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_BIDX_DBIDX_MAX                              (0x0000ffffU)

#define CSL_EVETPCC_BIDX_RESETVAL                               (0x00000000U)

/* LNK */

#define CSL_EVETPCC_LNK_BCNTRLD_MASK                            (0xFFFF0000U)
#define CSL_EVETPCC_LNK_BCNTRLD_SHIFT                           (16U)
#define CSL_EVETPCC_LNK_BCNTRLD_RESETVAL                        (0x00000000U)
#define CSL_EVETPCC_LNK_BCNTRLD_MAX                             (0x0000ffffU)

#define CSL_EVETPCC_LNK_LINK_MASK                               (0x0000FFFFU)
#define CSL_EVETPCC_LNK_LINK_SHIFT                              (0U)
#define CSL_EVETPCC_LNK_LINK_RESETVAL                           (0x00000000U)
#define CSL_EVETPCC_LNK_LINK_MAX                                (0x0000ffffU)

#define CSL_EVETPCC_LNK_RESETVAL                                (0x00000000U)

/* CIDX */

#define CSL_EVETPCC_CIDX_SCIDX_MASK                             (0x0000FFFFU)
#define CSL_EVETPCC_CIDX_SCIDX_SHIFT                            (0U)
#define CSL_EVETPCC_CIDX_SCIDX_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CIDX_SCIDX_MAX                              (0x0000ffffU)

#define CSL_EVETPCC_CIDX_DCIDX_MASK                             (0xFFFF0000U)
#define CSL_EVETPCC_CIDX_DCIDX_SHIFT                            (16U)
#define CSL_EVETPCC_CIDX_DCIDX_RESETVAL                         (0x00000000U)
#define CSL_EVETPCC_CIDX_DCIDX_MAX                              (0x0000ffffU)

#define CSL_EVETPCC_CIDX_RESETVAL                               (0x00000000U)

/* CCNT */

#define CSL_EVETPCC_CCNT_CCNT_MASK                              (0x0000FFFFU)
#define CSL_EVETPCC_CCNT_CCNT_SHIFT                             (0U)
#define CSL_EVETPCC_CCNT_CCNT_RESETVAL                          (0x00000000U)
#define CSL_EVETPCC_CCNT_CCNT_MAX                               (0x0000ffffU)

#define CSL_EVETPCC_CCNT_RESETVAL                               (0x00000000U)

/* DST */

#define CSL_EVETPCC_DST_DST_MASK                                (0xFFFFFFFFU)
#define CSL_EVETPCC_DST_DST_SHIFT                               (0U)
#define CSL_EVETPCC_DST_DST_RESETVAL                            (0x00000000U)
#define CSL_EVETPCC_DST_DST_MAX                                 (0xffffffffU)

#define CSL_EVETPCC_DST_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
