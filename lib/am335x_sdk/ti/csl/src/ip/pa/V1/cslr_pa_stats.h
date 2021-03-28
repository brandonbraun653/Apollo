/*
 * Copyright (C) 2012-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/********************************************************************
* file: cslr_pa_stats.h
*
* Brief: This file contains the Register Description for pa_stats
*
*********************************************************************/
#ifndef CSLR_PA_STATS_H_
#define CSLR_PA_STATS_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */      

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVISION;
    volatile Uint32 SOFT_RESET;
    volatile Uint32 ENABLE_ALLOC;
    volatile Uint32 COUNTER_UPDATE;
    volatile Uint32 TIMER_CTL;
    volatile Uint32 TIMER_LOAD;
    volatile Uint32 TIMER_VALUE;
    volatile Uint32 PKT_ROUTING_INFO;
} CSL_Pa_stats_controlRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVISION; /* The Revision Register contains the ID and revision information. */
    volatile Uint32 SOFT_RESET; /* The Soft Reset Register is written in order to clear the contents of all statistics. */
    volatile Uint32 ENABLE_ALLOC; /* This register contains the enable for the engine and controls the allocation of 64-bit counters in the memory. */
    volatile Uint32 COUNTER_UPDATE; /* The Counter Update Register defines the events that may reset the counter value. */
    volatile Uint32 TIMER_CTL; /* The Timer Control Register controls a 16-bit timer. */
    volatile Uint32 TIMER_LOAD; /* The timer load register contains the starting count down value for the 16-bit timer. */
    volatile Uint32 TIMER_VALUE; /* The timer value register contains the current value of the timer. */
    volatile Uint32 PKT_ROUTING_INFO; /* The Statistics Packet Routing Info Register needs to be set correctly so packet is sent to the destination where software expects it. */
    volatile Uint8 RSVD0[8160];
    volatile Uint32 QUERY_STATS[4096]; /* Return the current statistics value but do not clear the stat value (query mode). */
    volatile Uint32 COLLECT_STATS[4096]; /* Return the current statistics value and clear the stat value (collect mode). */
} CSL_Pa_statsRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVISION */

#define CSL_PA_STATS_REVISION_SCHEME_MASK (0xC0000000u)
#define CSL_PA_STATS_REVISION_SCHEME_SHIFT (0x0000001Eu)
#define CSL_PA_STATS_REVISION_SCHEME_RESETVAL (0x00000001u)

#define CSL_PA_STATS_REVISION_MODID_MASK (0x0FFF0000u)
#define CSL_PA_STATS_REVISION_MODID_SHIFT (0x00000010u)
#define CSL_PA_STATS_REVISION_MODID_RESETVAL (0x00000EF5u)

#define CSL_PA_STATS_REVISION_REVRTL_MASK (0x0000F800u)
#define CSL_PA_STATS_REVISION_REVRTL_SHIFT (0x0000000Bu)
#define CSL_PA_STATS_REVISION_REVRTL_RESETVAL (0x00000000u)

#define CSL_PA_STATS_REVISION_REVMAJ_MASK (0x00000700u)
#define CSL_PA_STATS_REVISION_REVMAJ_SHIFT (0x00000008u)
#define CSL_PA_STATS_REVISION_REVMAJ_RESETVAL (0x00000001u)

#define CSL_PA_STATS_REVISION_REVCUSTOM_MASK (0x000000C0u)
#define CSL_PA_STATS_REVISION_REVCUSTOM_SHIFT (0x00000006u)
#define CSL_PA_STATS_REVISION_REVCUSTOM_RESETVAL (0x00000000u)

#define CSL_PA_STATS_REVISION_REVMIN_MASK (0x0000003Fu)
#define CSL_PA_STATS_REVISION_REVMIN_SHIFT (0x00000000u)
#define CSL_PA_STATS_REVISION_REVMIN_RESETVAL (0x00000000u)

#define CSL_PA_STATS_REVISION_RESETVAL   (0x4EF50100u)

/* SOFT_RESET */

#define CSL_PA_STATS_SOFT_RESET_GO_MASK  (0xFFFFFFFFu)
#define CSL_PA_STATS_SOFT_RESET_GO_SHIFT (0x00000000u)
#define CSL_PA_STATS_SOFT_RESET_GO_RESETVAL (0x00000000u)

#define CSL_PA_STATS_SOFT_RESET_RESETVAL (0x00000000u)

/* ENABLE_ALLOC */

#define CSL_PA_STATS_ENABLE_ALLOC_ENABLE_MASK (0x80000000u)
#define CSL_PA_STATS_ENABLE_ALLOC_ENABLE_SHIFT (0x0000001Fu)
#define CSL_PA_STATS_ENABLE_ALLOC_ENABLE_RESETVAL (0x00000000u)

#define CSL_PA_STATS_ENABLE_ALLOC_64BIT_CNT_MASK (0x00003FFFu)
#define CSL_PA_STATS_ENABLE_ALLOC_64BIT_CNT_SHIFT (0x00000000u)
#define CSL_PA_STATS_ENABLE_ALLOC_64BIT_CNT_RESETVAL (0x00000200u)

#define CSL_PA_STATS_ENABLE_ALLOC_RESETVAL (0x00000200u)

/* COUNTER_UPDATE */

#define CSL_PA_STATS_COUNTER_UPDATE_CLR_AFTER_PKT_MASK (0x80000000u)
#define CSL_PA_STATS_COUNTER_UPDATE_CLR_AFTER_PKT_SHIFT (0x0000001Fu)
#define CSL_PA_STATS_COUNTER_UPDATE_CLR_AFTER_PKT_RESETVAL (0x00000000u)

#define CSL_PA_STATS_COUNTER_UPDATE_GEN_PKT_MASK (0x00000002u)
#define CSL_PA_STATS_COUNTER_UPDATE_GEN_PKT_SHIFT (0x00000001u)
#define CSL_PA_STATS_COUNTER_UPDATE_GEN_PKT_RESETVAL (0x00000000u)

#define CSL_PA_STATS_COUNTER_UPDATE_GLOBAL_CLR_MASK (0x00000001u)
#define CSL_PA_STATS_COUNTER_UPDATE_GLOBAL_CLR_SHIFT (0x00000000u)
#define CSL_PA_STATS_COUNTER_UPDATE_GLOBAL_CLR_RESETVAL (0x00000000u)

#define CSL_PA_STATS_COUNTER_UPDATE_RESETVAL (0x00000000u)

/* TIMER_CTL */

#define CSL_PA_STATS_TIMER_CTL_CLK_ENABLE_MASK (0x00008000u)
#define CSL_PA_STATS_TIMER_CTL_CLK_ENABLE_SHIFT (0x0000000Fu)
#define CSL_PA_STATS_TIMER_CTL_CLK_ENABLE_RESETVAL (0x00000001u)

#define CSL_PA_STATS_TIMER_CTL_PRESCALER_MASK (0x0000003Cu)
#define CSL_PA_STATS_TIMER_CTL_PRESCALER_SHIFT (0x00000002u)
#define CSL_PA_STATS_TIMER_CTL_PRESCALER_RESETVAL (0x0000000Fu)

#define CSL_PA_STATS_TIMER_CTL_START_STOP_MASK (0x00000001u)
#define CSL_PA_STATS_TIMER_CTL_START_STOP_SHIFT (0x00000000u)
#define CSL_PA_STATS_TIMER_CTL_START_STOP_RESETVAL (0x00000000u)

#define CSL_PA_STATS_TIMER_CTL_RESETVAL  (0x0000803Cu)

/* TIMER_LOAD */

#define CSL_PA_STATS_TIMER_LOAD_COUNT_MASK (0x0000FFFFu)
#define CSL_PA_STATS_TIMER_LOAD_COUNT_SHIFT (0x00000000u)
#define CSL_PA_STATS_TIMER_LOAD_COUNT_RESETVAL (0x00000000u)

#define CSL_PA_STATS_TIMER_LOAD_RESETVAL (0x00000000u)

/* TIMER_VALUE */

#define CSL_PA_STATS_TIMER_VALUE_COUNT_MASK (0x0000FFFFu)
#define CSL_PA_STATS_TIMER_VALUE_COUNT_SHIFT (0x00000000u)
#define CSL_PA_STATS_TIMER_VALUE_COUNT_RESETVAL (0x00000000u)

#define CSL_PA_STATS_TIMER_VALUE_RESETVAL (0x00000000u)

/* PKT_ROUTING_INFO */

#define CSL_PA_STATS_PKT_ROUTING_INFO_THREADID_MASK (0x80000000u)
#define CSL_PA_STATS_PKT_ROUTING_INFO_THREADID_SHIFT (0x0000001Fu)
#define CSL_PA_STATS_PKT_ROUTING_INFO_THREADID_RESETVAL (0x00000000u)

#define CSL_PA_STATS_PKT_ROUTING_INFO_PKT_TYPE_MASK (0x7C000000u)
#define CSL_PA_STATS_PKT_ROUTING_INFO_PKT_TYPE_SHIFT (0x0000001Au)
#define CSL_PA_STATS_PKT_ROUTING_INFO_PKT_TYPE_RESETVAL (0x00000000u)

#define CSL_PA_STATS_PKT_ROUTING_INFO_FLOW_INDEX_MASK (0x00FF0000u)
#define CSL_PA_STATS_PKT_ROUTING_INFO_FLOW_INDEX_SHIFT (0x00000010u)
#define CSL_PA_STATS_PKT_ROUTING_INFO_FLOW_INDEX_RESETVAL (0x00000000u)

#define CSL_PA_STATS_PKT_ROUTING_INFO_DST_QMGR_MASK (0x0000C000u)
#define CSL_PA_STATS_PKT_ROUTING_INFO_DST_QMGR_SHIFT (0x0000000Eu)
#define CSL_PA_STATS_PKT_ROUTING_INFO_DST_QMGR_RESETVAL (0x00000000u)

#define CSL_PA_STATS_PKT_ROUTING_INFO_DST_QNUM_MASK (0x00000FFFu)
#define CSL_PA_STATS_PKT_ROUTING_INFO_DST_QNUM_SHIFT (0x00000000u)
#define CSL_PA_STATS_PKT_ROUTING_INFO_DST_QNUM_RESETVAL (0x00000000u)

#define CSL_PA_STATS_PKT_ROUTING_INFO_RESETVAL (0x00000000u)

/* QUERY_STATS */

#define CSL_PA_STATS_QUERY_STATS_VALUE_MASK (0xFFFFFFFFu)
#define CSL_PA_STATS_QUERY_STATS_VALUE_SHIFT (0x00000000u)
#define CSL_PA_STATS_QUERY_STATS_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_STATS_QUERY_STATS_RESETVAL (0x00000000u)

/* COLLECT_STATS */

#define CSL_PA_STATS_COLLECT_STATS_VALUE_MASK (0xFFFFFFFFu)
#define CSL_PA_STATS_COLLECT_STATS_VALUE_SHIFT (0x00000000u)
#define CSL_PA_STATS_COLLECT_STATS_VALUE_RESETVAL (0x00000000u)

#define CSL_PA_STATS_COLLECT_STATS_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
