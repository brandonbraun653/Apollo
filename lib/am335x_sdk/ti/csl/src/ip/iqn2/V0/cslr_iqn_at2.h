/*
 *
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
*********************************************************************
* file: cslr_iqn_at2.h
*
* Brief: This file contains the Register Description for iqn_at2
*
*********************************************************************/
#ifndef CSLR_IQN_AT2_H_
#define CSLR_IQN_AT2_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for AT2_START
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT2_TIMER_ENABLES_CFG; /* Control for each of the RADT and the BCN timers */
} CSL_Iqn_at2At2_startRegs;

/**************************************************************************\
* Register Overlay Structure for AT2_RP1
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT2_RP1_CTRL_CFG; /* Configuration for OBSAI RP1 CRC circuit. (Unused for CPRI or non-RP1 OBSAI sync options) */
    volatile Uint32 AT2_RP1_TYPE_CAPTURE_STS; /* OBSAI RP1 Sync mechanism. Capture incoming RP1 FCB. (Ignore if not using RP1) */
    volatile Uint32 AT2_RP1_PAYLOAD_CAPTURE_TOD_LSB_STS; /* OBSAI RP1 Sync mechanism. Capture incoming RP1 FCB. (Ignore if not using RP1) */
    volatile Uint32 AT2_RP1_PAYLOAD_CAPTURE_TOD_MSB_STS; /* OBSAI RP1 Sync mechanism. Capture incoming RP1 FCB. (Ignore if not using RP1) */
} CSL_Iqn_at2At2_rp1Regs; /* Group of registers which relate to the OBSAI RP1 synchronization interface (Unused for CPRI and unsed for OBSAI when using other synch source such as IEEE1588) */

/**************************************************************************\
* Register Overlay Structure for AT2_BCN
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT2_BCN_OFFSET_CFG;
    volatile Uint32 AT2_BCN_PA_TSCOMP_CAPT_STS; /* CPTS module in NETCP/PA provides a measurement pulse called pa_tscomp. When this pulse fires, the BCN Timer value is captured to this register. SW may then use this captured value to calculate a BCN timer error which is corrected by writing to the BCN Offset register. */
    volatile Uint32 AT2_BCN_PHYSYNC_CAPT_STS; /* An external pin called PHYSYNC provides an optional sync measurement source. When a rising edge is detected on this pin, the BCN Timer value is captured to this register. */
    volatile Uint32 AT2_BCN_RADSYNC_CAPT_STS; /* An external pin called RADSYNC provides an optional sync measurement source. When a rising edge is detected on this pin, the BCN Timer value is captured to this register. this RADSYNC is not used for RAD timer but only used for BCN timer  */
    volatile Uint32 AT2_BCN_RP1_SYNC_CAPT_STS; /* OBSAI RP1 optionally may be used as a sync measurement source. When a successful RP1 FCB is recieved, optionally a system event fires, the FCB message is captured to registers, and the BCN timer value is captured to this register. */
    volatile Uint32 AT2_BCN_SLVSYNC_CAPT_STS; /* The uAT will provide frame sync pulses back to the AT2. When this pulse fires, the BCN Timer value is captured to this register. SW may then use this captured value to calculate a BCN timer error which is corrected by writing to the BCN Offset register. */
    volatile Uint32 AT2_BCN_FRM_VALUE_LSB_STS; /* BCN Frame count value (BTS Frame Number). Increments every time 10ms BCN timer wraps. This Register only allows reading of the value  */
    volatile Uint32 AT2_BCN_FRM_VALUE_MSB_STS; /* BCN Frame count value (BTS Frame Number). Increments every time 10ms BCN timer wraps. This Register only allows reading of the value  */
    volatile Uint32 AT2_BCN_SLVSEL_CFG; /* BCN uat slave select for capturing the BCN when the uat slave sends back it's sync. This is for debug and small time adjustment in systems which have different AIL uAT clk vs sys_clk, not in Lamarr since ail uAT is on the same sys_clk as AT */
    volatile Uint32 AT2_BCN_FRM_INIT_LSBS_CFG; /* BCN Frame count value (BTS Frame Number). Increments every time 10ms BCN timer wraps. This Register only allows writing of the value. User may write to this register while BCN is running. Advisable to write in the middle of frame time to avoid wrap uncertaninty */
    volatile Uint32 AT2_BCN_FRM_INIT_MSBS_CFG; /* BCN Frame count value (BTS Frame Number). Increments every time 10ms BCN timer wraps. This Register only allows writing of the value. User may write to this register while BCN is running. */
    volatile Uint32 AT2_BCN_CLKCNT_TC_CFG; /* Terminal count of BCN. User should chose value which vields 10ms. (245.76MHz) 2,457,599 (307.2MHz) 3,071,999 */
    volatile Uint32 AT2_BCN_FRAME_TC_LSB_CFG; /* BCN Frame count value (BTS Frame Number). Terminal count for frame_count field. Frame count goes to 0 when it matches the concatenated MSB and LSB value of these two registers. */
    volatile Uint32 AT2_BCN_FRAME_TC_MSB_CFG; /* BCN Frame count value (BTS Frame Number). Terminal count for frame_count field */
} CSL_Iqn_at2At2_bcnRegs; /* Group of all registers relating to the BCN (BTS Chip Number) Timer. The BCN timer is the SOC central timer which synchronizes all timing applications. All uAT slave timers and System Event RADT timers are synchronized by this centralized AT2 BCN timer. */

/**************************************************************************\
* Register Overlay Structure for AT2_GSM
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT2_GSM_TCOUNT_INIT_CFG; /* Special GSM T1, T2, T3 count GSM frames in way which is useful to GSM only APP SW. This register is for writing only and can be written either before the timer starts counting or on-the-fly (Users should avoid modifiying value near wrap position to avoid uncertanty) */
    volatile Uint32 AT2_GSM_TCOUNT_VALUE_STS; /* Special GSM T1, T2, T3 count GSM frames in way which is useful to GSM only APP SW. This register is for only for reading the current state (Users should avoid reading the value near the increment to avoid uncertainty) */
} CSL_Iqn_at2At2_gsmRegs; /* Special GSM T1, T1, T3 Timer Registers. The init values have the effect of over-writing the free running timers. The free running values are read from the sts register. */

/**************************************************************************\
* Register Overlay Structure for AT2_RADT
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT2_RADT_0_STS; /* Radio timer sample and symbol count value  */
    volatile Uint32 AT2_RADT_1_STS; /* RADT Frame Value 12 LSBs */
    volatile Uint32 AT2_RADT_2_STS; /* RADT Frame Value MSBs */
    volatile Uint32 AT2_RADT_3_STS; /* RADT has specific format which is expected by the RAC and TAC HW accelerator modules. EDMA performs a read of these values each RAC or TAC iteration cycle giving RAC and TAC a sense of real time. */
    volatile Uint32 AT2_RADT_INIT_1_CFG; /* RADT Frame Init LSBs */
    volatile Uint32 AT2_RADT_INIT_2_CFG; /* RADT Frame Init MSBs */
    volatile Uint32 AT2_RADT_0_CFG; /* AT RADT clock, LUT index and symbol counter terminal counts */
    volatile Uint8 RSVD0[4];
    volatile Uint32 AT2_RADT_1_CFG; /* Radio frame terminal count LSBs. Frame counter resets to 0 when a frame boundary is met and the concatenated radt_frame_tc_msbs and radt_frame_tc_lsbs match the frame counter. */
    volatile Uint32 AT2_RADT_2_CFG; /* Radio frame terminal count MSBs. Frame counter resets to 0 when a frame boundary is met and the concatenated radt_frame_tc_msbs and radt_frame_tc_lsbs match the frame counter. */
    volatile Uint32 AT2_RADT_3_CFG; /* Radio timer LUT index start address pointer */
    volatile Uint32 AT2_RADT_4_CFG; /* radt BCN sync compare */
    volatile Uint8 RSVD1[16];
} CSL_Iqn_at2At2_radtRegs; /* Group containing RADT configuration and status. A total of 8 RADT timers are available for purpose of supplying radio timer information to APP SW, RAC, and TAC. RADT timers are also available to system event circuits for purpose of radio timed system events. */

/**************************************************************************\
* Register Overlay Structure for AT2_EVENTS_24ARRAY
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT2_EVENT_OFFSET_CFG; /* event_offset after the start of frame and event strobe selection, the sys_event generator count out OFFSET clocks then fires once */
    volatile Uint32 AT2_EVENT_MOD_TC_CFG; /* Periodic system event rate. Programmed in sys_clks minus 1. after the event has fired once, the event will re-fire every MOD clocks */
    volatile Uint32 AT2_EVENT_MASK_LSBS_CFG; /* Programmably mask GSM system events. The system event generator maintains a count which indexes this mask LUT starting with the LSB. When zero, the bit suppresses the system event. This mechanism supports irregular patterns of system events. After the table is exausted, after 64 events, the pattern is repeated until the next strobe boundary slected by evt_strb_sel is detected. */
    volatile Uint32 AT2_EVENT_MASK_MSBS_CFG; /* Programmably mask GSM system events. */
} CSL_Iqn_at2At2_events_24arrayRegs; /* Array of system event control register. Each entry in Array is for each of 24 system events. System events are slaves of either RADT or BCN timers. */

/**************************************************************************\
* Register Overlay Structure for AT2_EVENTS
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT2_EVT_ENABLE_CFG; /* AT2 system events control APP SW timing. This MMR Enables each of 24 of these system events */
    volatile Uint32 AT2_EVT_FORCE_STB; /* For diagnostic purposes, this register allows the user to activate any of the 24 system events with a simple registers write. Useful for activating SW thread for testing purposes */
} CSL_Iqn_at2At2_eventsRegs; /* Group containing Non-Arrayed System Event control. Registers are 24 bits wide, one bit per system event. */

/**************************************************************************\
* Register Overlay Structure for AT2_RADT_SYM_LUT_RAM
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT2_RADT_SYM_LUT_RAM_CFG; /* RAM based LUT which give a clock count length per sym/time_slot. This table approach gives a flexible approach to program framing timing for any random radio standard. For GSM, use 104 table entries, one each for 104 time_slots per 60 ms. For LTE norm_cyc_prefix use 7 or 14 table entries, one each for every symbol in a sub-frame. For WCDMA use a single entry to be replayed 15 (time slots) times per frame */
} CSL_Iqn_at2At2_radt_sym_lut_ramRegs; /* RAM containing table of terminal count lengths of symbols or time slots. Programmed in units of AT2 clocks */

/**************************************************************************\
* Register Overlay Structure for AT2_EE
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT2_AT_EE_0_RAW_STS; /* RP1 Errors and Synchronization input Info. */
    volatile Uint32 AT2_AT_EE_0_RAW_SET; /* Raw Set */
    volatile Uint32 AT2_AT_EE_0_RAW_CLR; /* Raw Clear */
    volatile Uint32 AT2_AT_EE_0_EV0_EN_STS; /* EV0 Enable Status */
    volatile Uint32 AT2_AT_EE_0_EV0_EN_SET; /* EV0 Enable Set */
    volatile Uint32 AT2_AT_EE_0_EV0_EN_CLR; /* EV0 Enable Clear */
    volatile Uint32 AT2_AT_EE_0_EV1_EN_STS; /* EV1 Enable Status */
    volatile Uint32 AT2_AT_EE_0_EV1_EN_SET; /* EV1 Enable Set */
    volatile Uint32 AT2_AT_EE_0_EV1_EN_CLR; /* EV1 Enable Clear */
    volatile Uint32 AT2_AT_EE_0_EV0_ENABLED_STS; /* EV0 Enabled Status */
    volatile Uint32 AT2_AT_EE_0_EV1_ENABLED_STS; /* EV1 Enabled Status */
} CSL_Iqn_at2At2_eeRegs; /* IQN_AT2_EE EE register group */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Iqn_at2At2_startRegs AT2_START;
    volatile Uint8 RSVD0[12];
    CSL_Iqn_at2At2_rp1Regs AT2_RP1;
    CSL_Iqn_at2At2_bcnRegs AT2_BCN;
    volatile Uint8 RSVD1[8];
    CSL_Iqn_at2At2_gsmRegs AT2_GSM;
    volatile Uint8 RSVD2[408];
    CSL_Iqn_at2At2_radtRegs AT2_RADT[8];
    CSL_Iqn_at2At2_events_24arrayRegs AT2_EVENTS_24ARRAY[24];
    volatile Uint8 RSVD3[128];
    CSL_Iqn_at2At2_eventsRegs AT2_EVENTS;
    volatile Uint8 RSVD4[504];
    CSL_Iqn_at2At2_radt_sym_lut_ramRegs AT2_RADT_SYM_LUT_RAM[256];
    volatile Uint8 RSVD5[29696];
    CSL_Iqn_at2At2_eeRegs AT2_EE;
/******************************************/
/*  TEMPORARY FIX: Manual addition till   */
/*  autogenerated file becomes available. */
    volatile Uint8 RSVD6[32724];
/******************************************/
} CSL_Iqn_at2Regs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* at2_timer_enables_cfg */

#define CSL_IQN_AT2_AT2_TIMER_ENABLES_CFG_RADT_EN_MASK (0x000000FFu)
#define CSL_IQN_AT2_AT2_TIMER_ENABLES_CFG_RADT_EN_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_TIMER_ENABLES_CFG_RADT_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_TIMER_ENABLES_CFG_RUN_BCN_MASK (0x00000200u)
#define CSL_IQN_AT2_AT2_TIMER_ENABLES_CFG_RUN_BCN_SHIFT (0x00000009u)
#define CSL_IQN_AT2_AT2_TIMER_ENABLES_CFG_RUN_BCN_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_TIMER_ENABLES_CFG_RESETVAL (0x00000000u)

/* at2_rp1_ctrl_cfg */


#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_USE_MASK (0x00000200u)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_USE_SHIFT (0x00000009u)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_USE_RESETVAL (0x00000000u)
/*----crc_use Tokens----*/
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_USE_DONT_USE (0x00000000u)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_USE_USE (0x00000001u)

#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_FLIP_MASK (0x00000400u)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_FLIP_SHIFT (0x0000000Au)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_FLIP_RESETVAL (0x00000000u)
/*----crc_flip Tokens----*/
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_FLIP_NORMAL (0x00000000u)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_FLIP_REVERSE (0x00000001u)

#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INIT_ONES_MASK (0x00000800u)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INIT_ONES_SHIFT (0x0000000Bu)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INIT_ONES_RESETVAL (0x00000000u)
/*----crc_init_ones Tokens----*/
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INIT_ONES_INIT0 (0x00000000u)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INIT_ONES_INIT1 (0x00000001u)

#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INVERT_MASK (0x00001000u)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INVERT_SHIFT (0x0000000Cu)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INVERT_RESETVAL (0x00000000u)
/*----crc_invert Tokens----*/
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INVERT_NOINVERT (0x00000000u)
#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_CRC_INVERT_INVERT (0x00000001u)


#define CSL_IQN_AT2_AT2_RP1_CTRL_CFG_RESETVAL (0x00000000u)

/* at2_rp1_type_capture_sts */

#define CSL_IQN_AT2_AT2_RP1_TYPE_CAPTURE_STS_RD_VAL_MASK (0x000000FFu)
#define CSL_IQN_AT2_AT2_RP1_TYPE_CAPTURE_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RP1_TYPE_CAPTURE_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RP1_TYPE_CAPTURE_STS_RESETVAL (0x00000000u)

/* at2_rp1_payload_capture_tod_lsb_sts */

#define CSL_IQN_AT2_AT2_RP1_PAYLOAD_CAPTURE_TOD_LSB_STS_RD_VAL_MASK (0xFFFFFFFFu)
#define CSL_IQN_AT2_AT2_RP1_PAYLOAD_CAPTURE_TOD_LSB_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RP1_PAYLOAD_CAPTURE_TOD_LSB_STS_RD_VAL_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_RP1_PAYLOAD_CAPTURE_TOD_LSB_STS_RESETVAL (0x00000000u)

/* at2_rp1_payload_capture_tod_msb_sts */

#define CSL_IQN_AT2_AT2_RP1_PAYLOAD_CAPTURE_TOD_MSB_STS_RD_VAL_MASK (0xFFFFFFFFu)
#define CSL_IQN_AT2_AT2_RP1_PAYLOAD_CAPTURE_TOD_MSB_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RP1_PAYLOAD_CAPTURE_TOD_MSB_STS_RD_VAL_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_RP1_PAYLOAD_CAPTURE_TOD_MSB_STS_RESETVAL (0x00000000u)

/* at2_bcn_offset_cfg */

#define CSL_IQN_AT2_AT2_BCN_OFFSET_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_OFFSET_CFG_RESETVAL (0x00000000u)

/* at2_bcn_pa_tscomp_capt_sts */

#define CSL_IQN_AT2_AT2_BCN_PA_TSCOMP_CAPT_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_PA_TSCOMP_CAPT_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_PA_TSCOMP_CAPT_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_PA_TSCOMP_CAPT_STS_RESETVAL (0x00000000u)

/* at2_bcn_physync_capt_sts */

#define CSL_IQN_AT2_AT2_BCN_PHYSYNC_CAPT_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_PHYSYNC_CAPT_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_PHYSYNC_CAPT_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_PHYSYNC_CAPT_STS_RESETVAL (0x00000000u)

/* at2_bcn_radsync_capt_sts */

#define CSL_IQN_AT2_AT2_BCN_RADSYNC_CAPT_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_RADSYNC_CAPT_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_RADSYNC_CAPT_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_RADSYNC_CAPT_STS_RESETVAL (0x00000000u)

/* at2_bcn_rp1_sync_capt_sts */

#define CSL_IQN_AT2_AT2_BCN_RP1_SYNC_CAPT_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_RP1_SYNC_CAPT_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_RP1_SYNC_CAPT_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_RP1_SYNC_CAPT_STS_RESETVAL (0x00000000u)

/* at2_bcn_slvsync_capt_sts */

#define CSL_IQN_AT2_AT2_BCN_SLVSYNC_CAPT_STS_RD_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_SLVSYNC_CAPT_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_SLVSYNC_CAPT_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_SLVSYNC_CAPT_STS_RESETVAL (0x00000000u)

/* at2_bcn_frm_value_lsb_sts */

#define CSL_IQN_AT2_AT2_BCN_FRM_VALUE_LSB_STS_RD_VAL_MASK (0x00000FFFu)
#define CSL_IQN_AT2_AT2_BCN_FRM_VALUE_LSB_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_FRM_VALUE_LSB_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_FRM_VALUE_LSB_STS_RESETVAL (0x00000000u)

/* at2_bcn_frm_value_msb_sts */

#define CSL_IQN_AT2_AT2_BCN_FRM_VALUE_MSB_STS_RD_VAL_MASK (0x0FFFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_FRM_VALUE_MSB_STS_RD_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_FRM_VALUE_MSB_STS_RD_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_FRM_VALUE_MSB_STS_RESETVAL (0x00000000u)

/* at2_bcn_slvsel_cfg */

#define CSL_IQN_AT2_AT2_BCN_SLVSEL_CFG_VAL_MASK (0x0000000Fu)
#define CSL_IQN_AT2_AT2_BCN_SLVSEL_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_SLVSEL_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_SLVSEL_CFG_RESETVAL (0x00000000u)

/* at2_bcn_frm_init_lsbs_cfg */

#define CSL_IQN_AT2_AT2_BCN_FRM_INIT_LSBS_CFG_WR_VAL_MASK (0x00000FFFu)
#define CSL_IQN_AT2_AT2_BCN_FRM_INIT_LSBS_CFG_WR_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_FRM_INIT_LSBS_CFG_WR_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_FRM_INIT_LSBS_CFG_RESETVAL (0x00000000u)

/* at2_bcn_frm_init_msbs_cfg */

#define CSL_IQN_AT2_AT2_BCN_FRM_INIT_MSBS_CFG_WR_VAL_MASK (0x0FFFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_FRM_INIT_MSBS_CFG_WR_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_FRM_INIT_MSBS_CFG_WR_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_FRM_INIT_MSBS_CFG_RESETVAL (0x00000000u)

/* at2_bcn_clkcnt_tc_cfg */

#define CSL_IQN_AT2_AT2_BCN_CLKCNT_TC_CFG_VAL_MASK (0x01FFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_CLKCNT_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_CLKCNT_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_CLKCNT_TC_CFG_RESETVAL (0x00000000u)

/* at2_bcn_frame_tc_lsb_cfg */

#define CSL_IQN_AT2_AT2_BCN_FRAME_TC_LSB_CFG_VAL_MASK (0xFFFFFFFFu)
#define CSL_IQN_AT2_AT2_BCN_FRAME_TC_LSB_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_FRAME_TC_LSB_CFG_VAL_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_BCN_FRAME_TC_LSB_CFG_RESETVAL (0x00000000u)

/* at2_bcn_frame_tc_msb_cfg */

#define CSL_IQN_AT2_AT2_BCN_FRAME_TC_MSB_CFG_VAL_MASK (0x000000FFu)
#define CSL_IQN_AT2_AT2_BCN_FRAME_TC_MSB_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_BCN_FRAME_TC_MSB_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_BCN_FRAME_TC_MSB_CFG_RESETVAL (0x00000000u)

/* at2_gsm_tcount_init_cfg */

#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_T1_MASK (0x000007FFu)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_T1_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_T1_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_T2_MASK (0x0000F800u)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_T2_SHIFT (0x0000000Bu)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_T2_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_T3_MASK (0x003F0000u)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_T3_SHIFT (0x00000010u)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_T3_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_GSM_TCOUNT_INIT_CFG_RESETVAL (0x00000000u)

/* at2_gsm_tcount_value_sts */

#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_T1_MASK (0x000007FFu)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_T1_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_T1_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_T2_MASK (0x0000F800u)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_T2_SHIFT (0x0000000Bu)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_T2_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_T3_MASK (0x003F0000u)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_T3_SHIFT (0x00000010u)
#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_T3_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_GSM_TCOUNT_VALUE_STS_RESETVAL (0x00000000u)

/* at2_radt_0_sts */

#define CSL_IQN_AT2_AT2_RADT_0_STS_RADT_SAMPCNT_VAL_MASK (0x0007FFFFu)
#define CSL_IQN_AT2_AT2_RADT_0_STS_RADT_SAMPCNT_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_0_STS_RADT_SAMPCNT_VAL_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_RADT_0_STS_RADT_SYMCNT_VAL_MASK (0x07F80000u)
#define CSL_IQN_AT2_AT2_RADT_0_STS_RADT_SYMCNT_VAL_SHIFT (0x00000013u)
#define CSL_IQN_AT2_AT2_RADT_0_STS_RADT_SYMCNT_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_0_STS_RESETVAL (0x00000000u)

/* at2_radt_1_sts */

#define CSL_IQN_AT2_AT2_RADT_1_STS_RADT_FRM_VAL_LSB_MASK (0x00000FFFu)
#define CSL_IQN_AT2_AT2_RADT_1_STS_RADT_FRM_VAL_LSB_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_1_STS_RADT_FRM_VAL_LSB_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_1_STS_RESETVAL (0x00000000u)

/* at2_radt_2_sts */

#define CSL_IQN_AT2_AT2_RADT_2_STS_RADT_FRM_VAL_MSB_MASK (0x0FFFFFFFu)
#define CSL_IQN_AT2_AT2_RADT_2_STS_RADT_FRM_VAL_MSB_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_2_STS_RADT_FRM_VAL_MSB_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_2_STS_RESETVAL (0x00000000u)

/* at2_radt_3_sts */

#define CSL_IQN_AT2_AT2_RADT_3_STS_RADT_CHIP_MASK (0x00000FFFu)
#define CSL_IQN_AT2_AT2_RADT_3_STS_RADT_CHIP_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_3_STS_RADT_CHIP_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_RADT_3_STS_RADT_SLOT_MASK (0x0000F000u)
#define CSL_IQN_AT2_AT2_RADT_3_STS_RADT_SLOT_SHIFT (0x0000000Cu)
#define CSL_IQN_AT2_AT2_RADT_3_STS_RADT_SLOT_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_RADT_3_STS_RADT_FRME_MASK (0x0FFF0000u)
#define CSL_IQN_AT2_AT2_RADT_3_STS_RADT_FRME_SHIFT (0x00000010u)
#define CSL_IQN_AT2_AT2_RADT_3_STS_RADT_FRME_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_3_STS_RESETVAL (0x00000000u)

/* at2_radt_init_1_cfg */

#define CSL_IQN_AT2_AT2_RADT_INIT_1_CFG_FRM_INIT_LSB_MASK (0x00000FFFu)
#define CSL_IQN_AT2_AT2_RADT_INIT_1_CFG_FRM_INIT_LSB_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_INIT_1_CFG_FRM_INIT_LSB_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_INIT_1_CFG_RESETVAL (0x00000000u)

/* at2_radt_init_2_cfg */

#define CSL_IQN_AT2_AT2_RADT_INIT_2_CFG_FRM_INIT_MSB_MASK (0x0FFFFFFFu)
#define CSL_IQN_AT2_AT2_RADT_INIT_2_CFG_FRM_INIT_MSB_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_INIT_2_CFG_FRM_INIT_MSB_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_INIT_2_CFG_RESETVAL (0x00000000u)

/* at2_radt_0_cfg */

#define CSL_IQN_AT2_AT2_RADT_0_CFG_CLKCNT_TC_MASK (0x000007FFu)
#define CSL_IQN_AT2_AT2_RADT_0_CFG_CLKCNT_TC_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_0_CFG_CLKCNT_TC_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_RADT_0_CFG_LUTINDEX_TC_MASK (0x0007F800u)
#define CSL_IQN_AT2_AT2_RADT_0_CFG_LUTINDEX_TC_SHIFT (0x0000000Bu)
#define CSL_IQN_AT2_AT2_RADT_0_CFG_LUTINDEX_TC_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_RADT_0_CFG_SYMB_TC_MASK (0x07F80000u)
#define CSL_IQN_AT2_AT2_RADT_0_CFG_SYMB_TC_SHIFT (0x00000013u)
#define CSL_IQN_AT2_AT2_RADT_0_CFG_SYMB_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_0_CFG_RESETVAL (0x00000000u)

/* at2_radt_1_cfg */

#define CSL_IQN_AT2_AT2_RADT_1_CFG_FRM_TC_LSB_MASK (0xFFFFFFFFu)
#define CSL_IQN_AT2_AT2_RADT_1_CFG_FRM_TC_LSB_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_1_CFG_FRM_TC_LSB_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_RADT_1_CFG_RESETVAL (0x00000000u)

/* at2_radt_2_cfg */

#define CSL_IQN_AT2_AT2_RADT_2_CFG_FRM_TC_MSB_MASK (0x000000FFu)
#define CSL_IQN_AT2_AT2_RADT_2_CFG_FRM_TC_MSB_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_2_CFG_FRM_TC_MSB_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_2_CFG_RESETVAL (0x00000000u)

/* at2_radt_3_cfg */

#define CSL_IQN_AT2_AT2_RADT_3_CFG_LUT_INDEX_STRT_MASK (0x000000FFu)
#define CSL_IQN_AT2_AT2_RADT_3_CFG_LUT_INDEX_STRT_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_3_CFG_LUT_INDEX_STRT_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_3_CFG_RESETVAL (0x00000000u)

/* at2_radt_4_cfg */

#define CSL_IQN_AT2_AT2_RADT_4_CFG_BCN_SYNC_CMP_MASK (0x01FFFFFFu)
#define CSL_IQN_AT2_AT2_RADT_4_CFG_BCN_SYNC_CMP_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_4_CFG_BCN_SYNC_CMP_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_4_CFG_RESETVAL (0x00000000u)

/* at2_event_offset_cfg */

#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_VAL_MASK (0x003FFFFFu)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_MASK (0x1F000000u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_SHIFT (0x00000018u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RESETVAL (0x00000000u)
/*----evt_strb_sel Tokens----*/
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT0_FRAME (0x00000000u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT1_FRAME (0x00000001u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT2_FRAME (0x00000002u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT3_FRAME (0x00000003u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT4_FRAME (0x00000004u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT5_FRAME (0x00000005u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT6_FRAME (0x00000006u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT7_FRAME (0x00000007u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT0_SYMB (0x00000008u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT1_SYMB (0x00000009u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT2_SYMB (0x0000000au)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT3_SYMB (0x0000000bu)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT4_SYMB (0x0000000cu)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT5_SYMB (0x0000000du)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT6_SYMB (0x0000000eu)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_RADT7_SYMB (0x0000000fu)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_BCN_FRAME (0x00000010u)
#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_EVT_STRB_SEL_EVT_NREST (0x00000011u)


#define CSL_IQN_AT2_AT2_EVENT_OFFSET_CFG_RESETVAL (0x00000000u)

/* at2_event_mod_tc_cfg */

#define CSL_IQN_AT2_AT2_EVENT_MOD_TC_CFG_VAL_MASK (0x003FFFFFu)
#define CSL_IQN_AT2_AT2_EVENT_MOD_TC_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_EVENT_MOD_TC_CFG_VAL_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_EVENT_MOD_TC_CFG_RESETVAL (0x00000000u)

/* at2_event_mask_lsbs_cfg */

#define CSL_IQN_AT2_AT2_EVENT_MASK_LSBS_CFG_VAL_MASK (0xFFFFFFFFu)
#define CSL_IQN_AT2_AT2_EVENT_MASK_LSBS_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_EVENT_MASK_LSBS_CFG_VAL_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_EVENT_MASK_LSBS_CFG_RESETVAL (0x00000000u)

/* at2_event_mask_msbs_cfg */

#define CSL_IQN_AT2_AT2_EVENT_MASK_MSBS_CFG_VAL_MASK (0xFFFFFFFFu)
#define CSL_IQN_AT2_AT2_EVENT_MASK_MSBS_CFG_VAL_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_EVENT_MASK_MSBS_CFG_VAL_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_EVENT_MASK_MSBS_CFG_RESETVAL (0x00000000u)

/* at2_evt_enable_cfg */

#define CSL_IQN_AT2_AT2_EVT_ENABLE_CFG_EN_MASK (0x00FFFFFFu)
#define CSL_IQN_AT2_AT2_EVT_ENABLE_CFG_EN_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_EVT_ENABLE_CFG_EN_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_EVT_ENABLE_CFG_RESETVAL (0x00000000u)

/* at2_evt_force_stb */

#define CSL_IQN_AT2_AT2_EVT_FORCE_STB_STRB_MASK (0x00FFFFFFu)
#define CSL_IQN_AT2_AT2_EVT_FORCE_STB_STRB_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_EVT_FORCE_STB_STRB_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_EVT_FORCE_STB_RESETVAL (0x00000000u)

/* at2_radt_sym_lut_ram_cfg */

#define CSL_IQN_AT2_AT2_RADT_SYM_LUT_RAM_CFG_SYMBCNT_TC_MASK (0x0007FFFFu)
#define CSL_IQN_AT2_AT2_RADT_SYM_LUT_RAM_CFG_SYMBCNT_TC_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_RADT_SYM_LUT_RAM_CFG_SYMBCNT_TC_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_RADT_SYM_LUT_RAM_CFG_RESETVAL (0x00000000u)

/* at2_at_ee_0_raw_sts */

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_STS_RESETVAL (0x00000000u)

/* at2_at_ee_0_raw_set */

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_SET_RESETVAL (0x00000000u)

/* at2_at_ee_0_raw_clr */

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_RAW_CLR_RESETVAL (0x00000000u)

/* at2_at_ee_0_ev0_en_sts */

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_STS_RESETVAL (0x00000000u)

/* at2_at_ee_0_ev0_en_set */

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_SET_RESETVAL (0x00000000u)

/* at2_at_ee_0_ev0_en_clr */

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_EN_CLR_RESETVAL (0x00000000u)

/* at2_at_ee_0_ev1_en_sts */

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_STS_RESETVAL (0x00000000u)

/* at2_at_ee_0_ev1_en_set */

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_SET_RESETVAL (0x00000000u)

/* at2_at_ee_0_ev1_en_clr */

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_EN_CLR_RESETVAL (0x00000000u)

/* at2_at_ee_0_ev0_enabled_sts */

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_EV0_ENABLED_STS_RESETVAL (0x00000000u)

/* at2_at_ee_0_ev1_enabled_sts */

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RP1_CRC_ERR_MASK (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RP1_CRC_ERR_SHIFT (0x00000000u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RP1_CRC_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RP1_BIT_ERR_MASK (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RP1_BIT_ERR_SHIFT (0x00000001u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RP1_BIT_ERR_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RP1_SYNC_INFO_MASK (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RP1_SYNC_INFO_SHIFT (0x00000002u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RP1_SYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RADSYNC_INFO_MASK (0x00000008u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RADSYNC_INFO_SHIFT (0x00000003u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RADSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_PHYSYNC_INFO_MASK (0x00000010u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_PHYSYNC_INFO_SHIFT (0x00000004u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_PHYSYNC_INFO_RESETVAL (0x00000000u)

#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_PA_TSCOMP_INFO_MASK (0x00000020u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_PA_TSCOMP_INFO_SHIFT (0x00000005u)
#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_PA_TSCOMP_INFO_RESETVAL (0x00000000u)


#define CSL_IQN_AT2_AT2_AT_EE_0_EV1_ENABLED_STS_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
