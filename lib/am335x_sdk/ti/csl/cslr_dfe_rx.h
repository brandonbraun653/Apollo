/*
 * cslr_dfe_rx.h
 *
 * This file contains the macros for Register Chip Support Library (CSL) which 
 * can be used for operations on the respective underlying hardware/peripheral
 *
 * Copyright (C) 2009-2012 Texas Instruments Incorporated - http://www.ti.com/
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
 *  AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
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

/* The file is auto generated at 16:58:23 10/30/12 (Rev 1.66)*/

#ifndef CSLR_DFE_RX_H__
#define CSLR_DFE_RX_H__

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
    volatile Uint32 w2;
    volatile Uint32 rsvd0[1];
} CSL_DFE_RX_NCO_FREQ_WORD_REGS;

typedef struct
{
    volatile Uint32 ioffset;
    volatile Uint32 qoffset;
} CSL_DFE_RX_EQR_DC_REGS;

typedef struct
{
    volatile Uint32 ii;
    volatile Uint32 iq;
    volatile Uint32 qi;
    volatile Uint32 qq;
} CSL_DFE_RX_IMB_TAP_REGS;

typedef struct
{
    volatile Uint32 ii0;
    volatile Uint32 ii1;
    volatile Uint32 iq0;
    volatile Uint32 iq1;
    volatile Uint32 qi0;
    volatile Uint32 qi1;
    volatile Uint32 qq0;
    volatile Uint32 qq1;
} CSL_DFE_RX_IMB_COR_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
} CSL_DFE_RX_FEAGC_GAIN_INIT_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
} CSL_DFE_RX_PM_NSAMP_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
} CSL_DFE_RX_PM_INTERVAL_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
    volatile Uint32 w2;
    volatile Uint32 w3;
} CSL_DFE_RX_PM_POWER_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
    volatile Uint32 w2;
    volatile Uint32 rsvd0[1];
} CSL_DFE_RX_PM_MAGSQ_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
} CSL_DFE_RX_PM_HIST_ONE_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
} CSL_DFE_RX_PM_HIST_TWO_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
} CSL_DFE_RX_IMB_GSG_TIMER_TABLE_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
} CSL_DFE_RX_DC_GSG_TIMER_TABLE_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
} CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
} CSL_DFE_RX_FEAGC_GAIN_TABLE_REGS;

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[128];
    /* Addr: h(200), d(512) */
    volatile Uint32 config;
    /* Addr: h(204), d(516) */
    volatile Uint32 bypass;
    /* Addr: h(208), d(520) */
    volatile Uint32 r2c_global;
    /* Addr: h(20C), d(524) */
    volatile Uint32 sw_switch_sel;
    /* Addr: h(210), d(528) */
    volatile Uint32 nco_dither_enable;
    /* Addr: h(214), d(532) */
    volatile Uint32 df_decimation;
    /* Addr: h(218), d(536) */
    volatile Uint32 eqr_spec_inv;
    /* Addr: h(21C), d(540) */
    volatile Uint32 eqr_shift;
    /* Addr: h(220), d(544) */
    volatile Uint32 imb_global;
    /* Addr: h(224), d(548) */
    volatile Uint32 imb_n;
    /* Addr: h(228), d(552) */
    volatile Uint32 imb_err_shift;
    /* Addr: h(22C), d(556) */
    volatile Uint32 testbus;
    /* Addr: h(230), d(560) */
    volatile Uint32 feagc_dc_testbus;
    /* Addr: h(234), d(564) */
    volatile Uint32 mem_access;
    /* Addr: h(238), d(568) */
    volatile Uint32 rsvd1[1];
    /* Addr: h(23C), d(572) */
    volatile Uint32 clock_gating;
    /* Addr: h(240), d(576) */
    volatile CSL_DFE_RX_NCO_FREQ_WORD_REGS nco_freq_word[4];
    /* Addr: h(280), d(640) */
    volatile CSL_DFE_RX_EQR_DC_REGS eqr_dc[4];
    /* Addr: h(2A0), d(672) */
    volatile Uint32 rsvd2[8];
    /* Addr: h(2C0), d(704) */
    volatile CSL_DFE_RX_IMB_TAP_REGS imb_tap[4];
    /* Addr: h(300), d(768) */
    volatile Uint32 r2c_ssel;
    /* Addr: h(304), d(772) */
    volatile Uint32 nco_ssel;
    /* Addr: h(308), d(776) */
    volatile Uint32 eqr_ssel;
    /* Addr: h(30C), d(780) */
    volatile Uint32 imb_ssel;
    /* Addr: h(310), d(784) */
    volatile Uint32 gsg_ssel;
    /* Addr: h(314), d(788) */
    volatile Uint32 feagc_ssel;
    /* Addr: h(318), d(792) */
    volatile Uint32 dc_ssel;
    /* Addr: h(31C), d(796) */
    volatile Uint32 pm_ssel;
    /* Addr: h(320), d(800) */
    volatile Uint32 test_ssel;
    /* Addr: h(324), d(804) */
    volatile Uint32 rsvd3[7];
    /* Addr: h(340), d(832) */
    volatile CSL_DFE_RX_IMB_COR_REGS imb_cor[4];
    /* Addr: h(3C0), d(960) */
    volatile Uint32 rsvd4[11];
    /* Addr: h(3EC), d(1004) */
    volatile Uint32 imb_gsg_timer_seq_len[4];
    /* Addr: h(3FC), d(1020) */
    volatile Uint32 imb_gsg_config;
    /* Addr: h(400), d(1024) */
    volatile Uint32 rsvd5[128];
    /* Addr: h(600), d(1536) */
    volatile Uint32 feagc_notch_filt;
    /* Addr: h(604), d(1540) */
    volatile Uint32 feagc_pow_global;
    /* Addr: h(608), d(1544) */
    volatile Uint32 feagc_interval_w0;
    /* Addr: h(60C), d(1548) */
    volatile Uint32 feagc_interval_w1;
    /* Addr: h(610), d(1552) */
    volatile Uint32 feagc_update_delay[4];
    /* Addr: h(620), d(1568) */
    volatile Uint32 feagc_err_shift;
    /* Addr: h(624), d(1572) */
    volatile Uint32 feagc_sd_ena;
    /* Addr: h(628), d(1576) */
    volatile Uint32 feagc_sd_thresh_w0;
    /* Addr: h(62C), d(1580) */
    volatile Uint32 feagc_sd_thresh_w1;
    /* Addr: h(630), d(1584) */
    volatile Uint32 feagc_sd_samples;
    /* Addr: h(634), d(1588) */
    volatile Uint32 feagc_sd_timer;
    /* Addr: h(638), d(1592) */
    volatile Uint32 feagc_pk_high_ena;
    /* Addr: h(63C), d(1596) */
    volatile Uint32 feagc_pk_high_thres;
    /* Addr: h(640), d(1600) */
    volatile Uint32 feagc_pk_high_samples;
    /* Addr: h(644), d(1604) */
    volatile Uint32 feagc_pk_high_timer;
    /* Addr: h(648), d(1608) */
    volatile Uint32 feagc_pk_high_step;
    /* Addr: h(64C), d(1612) */
    volatile Uint32 feagc_pk_low_ena;
    /* Addr: h(650), d(1616) */
    volatile Uint32 feagc_pk_low_thres;
    /* Addr: h(654), d(1620) */
    volatile Uint32 feagc_pk_low_samples;
    /* Addr: h(658), d(1624) */
    volatile Uint32 feagc_pk_low_timer;
    /* Addr: h(65C), d(1628) */
    volatile Uint32 feagc_pk_low_step;
    /* Addr: h(660), d(1632) */
    volatile CSL_DFE_RX_FEAGC_GAIN_INIT_REGS feagc_gain_init[4];
    /* Addr: h(680), d(1664) */
    volatile Uint32 rsvd6[4];
    /* Addr: h(690), d(1680) */
    volatile Uint32 feagc_maskout[4];
    /* Addr: h(6A0), d(1696) */
    volatile Uint32 feagc_stream_mode;
    /* Addr: h(6A4), d(1700) */
    volatile Uint32 feagc_freeze;
    /* Addr: h(6A8), d(1704) */
    volatile Uint32 feagc_frz_reset_pwr;
    /* Addr: h(6AC), d(1708) */
    volatile Uint32 feagc_mult_enable;
    /* Addr: h(6B0), d(1712) */
    volatile Uint32 rsvd7[1];
    /* Addr: h(6B4), d(1716) */
    volatile Uint32 feagc_table_mode;
    /* Addr: h(6B8), d(1720) */
    volatile Uint32 feagc_delay_adjust[4];
    /* Addr: h(6C8), d(1736) */
    volatile Uint32 feagc_mult_value[4];
    /* Addr: h(6D8), d(1752) */
    volatile Uint32 rsvd8[5];
    /* Addr: h(6EC), d(1772) */
    volatile Uint32 feagc_gsg_timer_seq_len[4];
    /* Addr: h(6FC), d(1788) */
    volatile Uint32 feagc_gsg_config;
    /* Addr: h(700), d(1792) */
    volatile Uint32 dc_global;
    /* Addr: h(704), d(1796) */
    volatile Uint32 dc_init[8];
    /* Addr: h(724), d(1828) */
    volatile Uint32 dc_interval_w0;
    /* Addr: h(728), d(1832) */
    volatile Uint32 dc_interval_w1;
    /* Addr: h(72C), d(1836) */
    volatile Uint32 dc_update_delay[4];
    /* Addr: h(73C), d(1852) */
    volatile Uint32 dc_shift_mode;
    /* Addr: h(740), d(1856) */
    volatile Uint32 siggen_i_mode;
    /* Addr: h(744), d(1860) */
    volatile Uint32 siggen_i_ramp_start_w0;
    /* Addr: h(748), d(1864) */
    volatile Uint32 siggen_i_ramp_start_w1;
    /* Addr: h(74C), d(1868) */
    volatile Uint32 siggen_i_ramp_stop_w0;
    /* Addr: h(750), d(1872) */
    volatile Uint32 siggen_i_ramp_stop_w1;
    /* Addr: h(754), d(1876) */
    volatile Uint32 siggen_i_ramp_inc_w0;
    /* Addr: h(758), d(1880) */
    volatile Uint32 siggen_i_ramp_inc_w1;
    /* Addr: h(75C), d(1884) */
    volatile Uint32 siggen_i_pulse_width;
    /* Addr: h(760), d(1888) */
    volatile Uint32 rsvd9[1];
    /* Addr: h(764), d(1892) */
    volatile Uint32 siggen_q_mode;
    /* Addr: h(768), d(1896) */
    volatile Uint32 siggen_q_ramp_start_w0;
    /* Addr: h(76C), d(1900) */
    volatile Uint32 siggen_q_ramp_start_w1;
    /* Addr: h(770), d(1904) */
    volatile Uint32 siggen_q_ramp_stop_w0;
    /* Addr: h(774), d(1908) */
    volatile Uint32 siggen_q_ramp_stop_w1;
    /* Addr: h(778), d(1912) */
    volatile Uint32 siggen_q_ramp_inc_w0;
    /* Addr: h(77C), d(1916) */
    volatile Uint32 siggen_q_ramp_inc_w1;
    /* Addr: h(780), d(1920) */
    volatile Uint32 siggen_q_pulse_width;
    /* Addr: h(784), d(1924) */
    volatile Uint32 rsvd10[1];
    /* Addr: h(788), d(1928) */
    volatile Uint32 chksum_mode;
    /* Addr: h(78C), d(1932) */
    volatile Uint32 chksum_sig_len;
    /* Addr: h(790), d(1936) */
    volatile Uint32 chksum_chan_sel;
    /* Addr: h(794), d(1940) */
    volatile Uint32 chksum_w0;
    /* Addr: h(798), d(1944) */
    volatile Uint32 chksum_w1;
    /* Addr: h(79C), d(1948) */
    volatile Uint32 rsvd11[20];
    /* Addr: h(7EC), d(2028) */
    volatile Uint32 dc_gsg_timer_seq_len[4];
    /* Addr: h(7FC), d(2044) */
    volatile Uint32 dc_gsg_config;
    /* Addr: h(800), d(2048) */
    volatile Uint32 rsvd12[128];
    /* Addr: h(A00), d(2560) */
    volatile Uint32 pm_mode;
    /* Addr: h(A04), d(2564) */
    volatile Uint32 pm_handshake;
    /* Addr: h(A08), d(2568) */
    volatile Uint32 pm_hist_one_thresh_w0;
    /* Addr: h(A0C), d(2572) */
    volatile Uint32 pm_hist_one_thresh_w1;
    /* Addr: h(A10), d(2576) */
    volatile Uint32 pm_hist_two_thresh_w0;
    /* Addr: h(A14), d(2580) */
    volatile Uint32 pm_hist_two_thresh_w1;
    /* Addr: h(A18), d(2584) */
    volatile Uint32 pm_sync_delay[4];
    /* Addr: h(A28), d(2600) */
    volatile Uint32 rsvd13[6];
    /* Addr: h(A40), d(2624) */
    volatile CSL_DFE_RX_PM_NSAMP_REGS pm_nsamp[4];
    /* Addr: h(A60), d(2656) */
    volatile CSL_DFE_RX_PM_INTERVAL_REGS pm_interval[4];
    /* Addr: h(A80), d(2688) */
    volatile CSL_DFE_RX_PM_POWER_REGS pm_power[4];
    /* Addr: h(AC0), d(2752) */
    volatile CSL_DFE_RX_PM_MAGSQ_REGS pm_magsq[4];
    /* Addr: h(B00), d(2816) */
    volatile CSL_DFE_RX_PM_HIST_ONE_REGS pm_hist_one[4];
    /* Addr: h(B20), d(2848) */
    volatile CSL_DFE_RX_PM_HIST_TWO_REGS pm_hist_two[4];
    /* Addr: h(B40), d(2880) */
    volatile Uint32 rsvd14[176];
    /* Addr: h(E00), d(3584) */
    volatile Uint32 inits;
    /* Addr: h(E04), d(3588) */
    volatile Uint32 interrupt_mask;
    /* Addr: h(E08), d(3592) */
    volatile Uint32 interrupt_service;
    /* Addr: h(E0C), d(3596) */
    volatile Uint32 interrupt_force;
    /* Addr: h(E10), d(3600) */
    volatile Uint32 rsvd15[64636];
    /* Addr: h(40000), d(262144) */
    volatile Uint32 eqr_taps_ii0[16];
    /* Addr: h(40040), d(262208) */
    volatile Uint32 eqr_taps_iq0[16];
    /* Addr: h(40080), d(262272) */
    volatile Uint32 eqr_taps_qi0[16];
    /* Addr: h(400C0), d(262336) */
    volatile Uint32 eqr_taps_qq0[16];
    /* Addr: h(40100), d(262400) */
    volatile Uint32 rsvd16[64];
    /* Addr: h(40200), d(262656) */
    volatile Uint32 eqr_taps_ii1[16];
    /* Addr: h(40240), d(262720) */
    volatile Uint32 eqr_taps_iq1[16];
    /* Addr: h(40280), d(262784) */
    volatile Uint32 eqr_taps_qi1[16];
    /* Addr: h(402C0), d(262848) */
    volatile Uint32 eqr_taps_qq1[16];
    /* Addr: h(40300), d(262912) */
    volatile Uint32 rsvd17[64];
    /* Addr: h(40400), d(263168) */
    volatile Uint32 eqr_taps_ii2[16];
    /* Addr: h(40440), d(263232) */
    volatile Uint32 eqr_taps_iq2[16];
    /* Addr: h(40480), d(263296) */
    volatile Uint32 eqr_taps_qi2[16];
    /* Addr: h(404C0), d(263360) */
    volatile Uint32 eqr_taps_qq2[16];
    /* Addr: h(40500), d(263424) */
    volatile Uint32 rsvd18[64];
    /* Addr: h(40600), d(263680) */
    volatile Uint32 eqr_taps_ii3[16];
    /* Addr: h(40640), d(263744) */
    volatile Uint32 eqr_taps_iq3[16];
    /* Addr: h(40680), d(263808) */
    volatile Uint32 eqr_taps_qi3[16];
    /* Addr: h(406C0), d(263872) */
    volatile Uint32 eqr_taps_qq3[16];
    /* Addr: h(40700), d(263936) */
    volatile Uint32 rsvd19[64];
    /* Addr: h(40800), d(264192) */
    volatile Uint32 imb_adapt_k[256];
    /* Addr: h(40C00), d(265216) */
    volatile Uint32 imb_gsg_seq_table[64];
    /* Addr: h(40D00), d(265472) */
    volatile CSL_DFE_RX_IMB_GSG_TIMER_TABLE_REGS imb_gsg_timer_table[16];
    /* Addr: h(40D80), d(265600) */
    volatile Uint32 rsvd20[160];
    /* Addr: h(41000), d(266240) */
    volatile Uint32 dc_gsg_seq_table[64];
    /* Addr: h(41100), d(266496) */
    volatile CSL_DFE_RX_DC_GSG_TIMER_TABLE_REGS dc_gsg_timer_table[16];
    /* Addr: h(41180), d(266624) */
    volatile Uint32 rsvd21[160];
    /* Addr: h(41400), d(267264) */
    volatile Uint32 feagc_gsg_seq_table[64];
    /* Addr: h(41500), d(267520) */
    volatile CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_REGS feagc_gsg_timer_table[16];
    /* Addr: h(41580), d(267648) */
    volatile Uint32 rsvd22[160];
    /* Addr: h(41800), d(268288) */
    volatile Uint32 feagc_err_table[256];
    /* Addr: h(41C00), d(269312) */
    volatile CSL_DFE_RX_FEAGC_GAIN_TABLE_REGS feagc_gain_table[128];
} CSL_DFE_RX_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd2 : 18;
    Uint32 input_power_down : 1;
    Uint32 output_power_down : 1;
    Uint32 rsvd1 : 2;
    Uint32 input_antenna_mode : 2;
    Uint32 rsvd0 : 2;
    Uint32 output_stream_mode : 2;
    Uint32 output_delay : 3;
    Uint32 output_format : 1;
#else 
    Uint32 output_format : 1;
    Uint32 output_delay : 3;
    Uint32 output_stream_mode : 2;
    Uint32 rsvd0 : 2;
    Uint32 input_antenna_mode : 2;
    Uint32 rsvd1 : 2;
    Uint32 output_power_down : 1;
    Uint32 input_power_down : 1;
    Uint32 rsvd2 : 18;
#endif 
} CSL_DFE_RX_CONFIG_REG;

/* RX output bus data format. */
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_FORMAT_MASK (0x00000001u)
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_FORMAT_SHIFT (0x00000000u)
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_FORMAT_RESETVAL (0x00000000u)

/* RX output delay.  Delays the output data bus, frame and valid signals 0-7 clock cycles. */
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_DELAY_MASK (0x0000000Eu)
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_DELAY_SHIFT (0x00000001u)
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_DELAY_RESETVAL (0x00000000u)

/* Path stream mode control for the RX blocks from the output side of the Switch block through to the RX output. */
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_STREAM_MODE_MASK (0x00000030u)
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_STREAM_MODE_SHIFT (0x00000004u)
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_STREAM_MODE_RESETVAL (0x00000000u)

/* Path antenna mode control for the RX input blocks through to the input side of the Switch block. */
#define CSL_DFE_RX_CONFIG_REG_INPUT_ANTENNA_MODE_MASK (0x00000300u)
#define CSL_DFE_RX_CONFIG_REG_INPUT_ANTENNA_MODE_SHIFT (0x00000008u)
#define CSL_DFE_RX_CONFIG_REG_INPUT_ANTENNA_MODE_RESETVAL (0x00000000u)

/* Power down control for the RX blocks from the output side of the Switch block through to the RX output. */
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_POWER_DOWN_MASK (0x00001000u)
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_POWER_DOWN_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_CONFIG_REG_OUTPUT_POWER_DOWN_RESETVAL (0x00000000u)

/* Power down control for the RX input blocks through to the input side of the Switch block. */
#define CSL_DFE_RX_CONFIG_REG_INPUT_POWER_DOWN_MASK (0x00002000u)
#define CSL_DFE_RX_CONFIG_REG_INPUT_POWER_DOWN_SHIFT (0x0000000Du)
#define CSL_DFE_RX_CONFIG_REG_INPUT_POWER_DOWN_RESETVAL (0x00000000u)

#define CSL_DFE_RX_CONFIG_REG_ADDR (0x00000200u)
#define CSL_DFE_RX_CONFIG_REG_RESETVAL (0x00000000u)

/* BYPASS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 sw_bypass : 1;
    Uint32 nco_bypass : 1;
    Uint32 eqr_bypass : 1;
    Uint32 imb_bypass : 1;
#else 
    Uint32 imb_bypass : 1;
    Uint32 eqr_bypass : 1;
    Uint32 nco_bypass : 1;
    Uint32 sw_bypass : 1;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_RX_BYPASS_REG;

/* IQ Imbalance Correction block bypass control.  */
#define CSL_DFE_RX_BYPASS_REG_IMB_BYPASS_MASK (0x00000001u)
#define CSL_DFE_RX_BYPASS_REG_IMB_BYPASS_SHIFT (0x00000000u)
#define CSL_DFE_RX_BYPASS_REG_IMB_BYPASS_RESETVAL (0x00000000u)

/* Equalizer block bypass control.  */
#define CSL_DFE_RX_BYPASS_REG_EQR_BYPASS_MASK (0x00000002u)
#define CSL_DFE_RX_BYPASS_REG_EQR_BYPASS_SHIFT (0x00000001u)
#define CSL_DFE_RX_BYPASS_REG_EQR_BYPASS_RESETVAL (0x00000000u)

/* NCO/Mixer block bypass control.  */
#define CSL_DFE_RX_BYPASS_REG_NCO_BYPASS_MASK (0x00000004u)
#define CSL_DFE_RX_BYPASS_REG_NCO_BYPASS_SHIFT (0x00000002u)
#define CSL_DFE_RX_BYPASS_REG_NCO_BYPASS_RESETVAL (0x00000000u)

/* Switch block bypass control. */
#define CSL_DFE_RX_BYPASS_REG_SW_BYPASS_MASK (0x00000008u)
#define CSL_DFE_RX_BYPASS_REG_SW_BYPASS_SHIFT (0x00000003u)
#define CSL_DFE_RX_BYPASS_REG_SW_BYPASS_RESETVAL (0x00000000u)

#define CSL_DFE_RX_BYPASS_REG_ADDR (0x00000204u)
#define CSL_DFE_RX_BYPASS_REG_RESETVAL (0x00000000u)

/* R2C_GLOBAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 real_in : 1;
    Uint32 spec_inv3 : 1;
    Uint32 spec_inv2 : 1;
    Uint32 spec_inv1 : 1;
    Uint32 spec_inv0 : 1;
#else 
    Uint32 spec_inv0 : 1;
    Uint32 spec_inv1 : 1;
    Uint32 spec_inv2 : 1;
    Uint32 spec_inv3 : 1;
    Uint32 real_in : 1;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_RX_R2C_GLOBAL_REG;

/*  */
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV0_MASK (0x00000001u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV0_SHIFT (0x00000000u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV1_MASK (0x00000002u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV1_SHIFT (0x00000001u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV2_MASK (0x00000004u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV2_SHIFT (0x00000002u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV2_RESETVAL (0x00000000u)

/* Real-to-Complex block spectral inversion control.  Enables spectral inversion of the Real-to-Complex block inputs as part of the real-to-complex mixing process (i.e. the spectrally inverted signal.) Only applies to real input signals. */
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV3_MASK (0x00000008u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV3_SHIFT (0x00000003u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_SPEC_INV3_RESETVAL (0x00000000u)

/* Real-toComplex block mode control. */
#define CSL_DFE_RX_R2C_GLOBAL_REG_REAL_IN_MASK (0x00000010u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_REAL_IN_SHIFT (0x00000004u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_REAL_IN_RESETVAL (0x00000000u)

#define CSL_DFE_RX_R2C_GLOBAL_REG_ADDR (0x00000208u)
#define CSL_DFE_RX_R2C_GLOBAL_REG_RESETVAL (0x00000000u)

/* SW_SWITCH_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 17;
    Uint32 output_sel3 : 3;
    Uint32 rsvd2 : 1;
    Uint32 output_sel2 : 3;
    Uint32 rsvd1 : 1;
    Uint32 output_sel1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 output_sel0 : 3;
#else 
    Uint32 output_sel0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 output_sel1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 output_sel2 : 3;
    Uint32 rsvd2 : 1;
    Uint32 output_sel3 : 3;
    Uint32 rsvd3 : 17;
#endif 
} CSL_DFE_RX_SW_SWITCH_SEL_REG;

/*  */
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL0_MASK (0x00000007u)
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL0_SHIFT (0x00000000u)
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL1_MASK (0x00000070u)
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL1_SHIFT (0x00000004u)
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL2_MASK (0x00000700u)
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL2_SHIFT (0x00000008u)
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL2_RESETVAL (0x00000000u)

/* Switch block antenna to stream mapping.  Selects which input antenna to output on path m output stream n. */
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL3_MASK (0x00007000u)
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL3_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_OUTPUT_SEL3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SW_SWITCH_SEL_REG_ADDR (0x0000020Cu)
#define CSL_DFE_RX_SW_SWITCH_SEL_REG_RESETVAL (0x00000000u)

/* NCO_DITHER_ENABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 dither_enable3 : 1;
    Uint32 dither_enable2 : 1;
    Uint32 dither_enable1 : 1;
    Uint32 dither_enable0 : 1;
#else 
    Uint32 dither_enable0 : 1;
    Uint32 dither_enable1 : 1;
    Uint32 dither_enable2 : 1;
    Uint32 dither_enable3 : 1;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_RX_NCO_DITHER_ENABLE_REG;

/*  */
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE0_MASK (0x00000001u)
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE0_SHIFT (0x00000000u)
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE1_MASK (0x00000002u)
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE1_SHIFT (0x00000001u)
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE2_MASK (0x00000004u)
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE2_SHIFT (0x00000002u)
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE2_RESETVAL (0x00000000u)

/* NCO/Mixer block dither enable. */
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE3_MASK (0x00000008u)
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE3_SHIFT (0x00000003u)
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_DITHER_ENABLE3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_ADDR (0x00000210u)
#define CSL_DFE_RX_NCO_DITHER_ENABLE_REG_RESETVAL (0x00000000u)

/* DF_DECIMATION */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 27;
    Uint32 f1_dec : 1;
    Uint32 rsvd0 : 2;
    Uint32 f2_dec : 2;
#else 
    Uint32 f2_dec : 2;
    Uint32 rsvd0 : 2;
    Uint32 f1_dec : 1;
    Uint32 rsvd1 : 27;
#endif 
} CSL_DFE_RX_DF_DECIMATION_REG;

/* Decimation filter block F2 decimation control. */
#define CSL_DFE_RX_DF_DECIMATION_REG_F2_DEC_MASK (0x00000003u)
#define CSL_DFE_RX_DF_DECIMATION_REG_F2_DEC_SHIFT (0x00000000u)
#define CSL_DFE_RX_DF_DECIMATION_REG_F2_DEC_RESETVAL (0x00000000u)

/* Decimation filter block F1 decimation control. */
#define CSL_DFE_RX_DF_DECIMATION_REG_F1_DEC_MASK (0x00000010u)
#define CSL_DFE_RX_DF_DECIMATION_REG_F1_DEC_SHIFT (0x00000004u)
#define CSL_DFE_RX_DF_DECIMATION_REG_F1_DEC_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DF_DECIMATION_REG_ADDR (0x00000214u)
#define CSL_DFE_RX_DF_DECIMATION_REG_RESETVAL (0x00000000u)

/* EQR_SPEC_INV */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 spec_inv3 : 1;
    Uint32 spec_inv2 : 1;
    Uint32 spec_inv1 : 1;
    Uint32 spec_inv0 : 1;
#else 
    Uint32 spec_inv0 : 1;
    Uint32 spec_inv1 : 1;
    Uint32 spec_inv2 : 1;
    Uint32 spec_inv3 : 1;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_RX_EQR_SPEC_INV_REG;

/*  */
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV0_MASK (0x00000001u)
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV0_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV1_MASK (0x00000002u)
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV1_SHIFT (0x00000001u)
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV2_MASK (0x00000004u)
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV2_SHIFT (0x00000002u)
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV2_RESETVAL (0x00000000u)

/* Equalizer block spectral inversion control.  Enables spectral inversion of the equalizer inputs prior to the equalizer filter. */
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV3_MASK (0x00000008u)
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV3_SHIFT (0x00000003u)
#define CSL_DFE_RX_EQR_SPEC_INV_REG_SPEC_INV3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_SPEC_INV_REG_ADDR (0x00000218u)
#define CSL_DFE_RX_EQR_SPEC_INV_REG_RESETVAL (0x00000000u)

/* EQR_SHIFT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 18;
    Uint32 shift3 : 2;
    Uint32 rsvd2 : 2;
    Uint32 shift2 : 2;
    Uint32 rsvd1 : 2;
    Uint32 shift1 : 2;
    Uint32 rsvd0 : 2;
    Uint32 shift0 : 2;
#else 
    Uint32 shift0 : 2;
    Uint32 rsvd0 : 2;
    Uint32 shift1 : 2;
    Uint32 rsvd1 : 2;
    Uint32 shift2 : 2;
    Uint32 rsvd2 : 2;
    Uint32 shift3 : 2;
    Uint32 rsvd3 : 18;
#endif 
} CSL_DFE_RX_EQR_SHIFT_REG;

/*  */
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT0_MASK (0x00000003u)
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT0_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT1_MASK (0x00000030u)
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT1_SHIFT (0x00000004u)
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT2_MASK (0x00000300u)
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT2_SHIFT (0x00000008u)
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT2_RESETVAL (0x00000000u)

/* Equalizer block output gain shift control. */
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT3_MASK (0x00003000u)
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT3_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_EQR_SHIFT_REG_SHIFT3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_SHIFT_REG_ADDR (0x0000021Cu)
#define CSL_DFE_RX_EQR_SHIFT_REG_RESETVAL (0x00000000u)

/* IMB_GLOBAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 cor_rd_ack : 1;
    Uint32 cor_rd_req : 1;
    Uint32 mag_shift : 4;
    Uint32 avg_length_n_minus_one : 4;
    Uint32 rsvd0 : 2;
    Uint32 mode : 2;
#else 
    Uint32 mode : 2;
    Uint32 rsvd0 : 2;
    Uint32 avg_length_n_minus_one : 4;
    Uint32 mag_shift : 4;
    Uint32 cor_rd_req : 1;
    Uint32 cor_rd_ack : 1;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_RX_IMB_GLOBAL_REG;

/* IQ Imbalance Correction block mode control. */
#define CSL_DFE_RX_IMB_GLOBAL_REG_MODE_MASK (0x00000003u)
#define CSL_DFE_RX_IMB_GLOBAL_REG_MODE_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_GLOBAL_REG_MODE_RESETVAL (0x00000000u)

/* IQ Imbalance Correction block continuous or synchronous modes averaging length in log2. (=n-1, where n = 1,2,3,…,16) */
#define CSL_DFE_RX_IMB_GLOBAL_REG_AVG_LENGTH_N_MINUS_ONE_MASK (0x000000F0u)
#define CSL_DFE_RX_IMB_GLOBAL_REG_AVG_LENGTH_N_MINUS_ONE_SHIFT (0x00000004u)
#define CSL_DFE_RX_IMB_GLOBAL_REG_AVG_LENGTH_N_MINUS_ONE_RESETVAL (0x00000000u)

/* IQ Imbalance Correction block error magnitude shift (M.) */
#define CSL_DFE_RX_IMB_GLOBAL_REG_MAG_SHIFT_MASK (0x00000F00u)
#define CSL_DFE_RX_IMB_GLOBAL_REG_MAG_SHIFT_SHIFT (0x00000008u)
#define CSL_DFE_RX_IMB_GLOBAL_REG_MAG_SHIFT_RESETVAL (0x00000000u)

/* IQ Imbalance Correction block correction value read request flag.  Set high by the user to request permission to read the captured iq imbalance correction values.  Set low by the user to enable correction value captures to proceed. */
#define CSL_DFE_RX_IMB_GLOBAL_REG_COR_RD_REQ_MASK (0x00001000u)
#define CSL_DFE_RX_IMB_GLOBAL_REG_COR_RD_REQ_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_IMB_GLOBAL_REG_COR_RD_REQ_RESETVAL (0x00000000u)

/* IQ Imbalance Correction block correction value read acknowledgement.  Set high by the CG5330 to acknowledge the read request and indicate that the current set of correction values is complete and will not be updated unitl the user sets the read request flag low.  Set low by the GC5330 to indicate that updates are proceeding.  (READ ONLY) */
#define CSL_DFE_RX_IMB_GLOBAL_REG_COR_RD_ACK_MASK (0x00002000u)
#define CSL_DFE_RX_IMB_GLOBAL_REG_COR_RD_ACK_SHIFT (0x0000000Du)
#define CSL_DFE_RX_IMB_GLOBAL_REG_COR_RD_ACK_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_GLOBAL_REG_ADDR (0x00000220u)
#define CSL_DFE_RX_IMB_GLOBAL_REG_RESETVAL (0x00000000u)

/* IMB_N */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 avg_length_n_minus_one : 16;
#else 
    Uint32 avg_length_n_minus_one : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_N_REG;

/* IQ Imbalance Correction block synchronous mode averaging length. */
#define CSL_DFE_RX_IMB_N_REG_AVG_LENGTH_N_MINUS_ONE_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_N_REG_AVG_LENGTH_N_MINUS_ONE_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_N_REG_AVG_LENGTH_N_MINUS_ONE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_N_REG_ADDR (0x00000224u)
#define CSL_DFE_RX_IMB_N_REG_RESETVAL (0x00000000u)

/* IMB_ERR_SHIFT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 rms_threshold : 5;
    Uint32 err_shift_mode : 1;
    Uint32 rsvd0 : 2;
    Uint32 err_shift : 5;
#else 
    Uint32 err_shift : 5;
    Uint32 rsvd0 : 2;
    Uint32 err_shift_mode : 1;
    Uint32 rms_threshold : 5;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_RX_IMB_ERR_SHIFT_REG;

/* IQ Imbalance Correction block error signal shift (S.) */
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_ERR_SHIFT_MASK (0x0000001Fu)
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_ERR_SHIFT_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_ERR_SHIFT_RESETVAL (0x00000000u)

/* IQ Imbalance Correction block error signal shift mode. */
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_ERR_SHIFT_MODE_MASK (0x00000080u)
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_ERR_SHIFT_MODE_SHIFT (0x00000007u)
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_ERR_SHIFT_MODE_RESETVAL (0x00000000u)

/* IQ Imbalance Correction block RMS power measurement threshold value. */
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_RMS_THRESHOLD_MASK (0x00001F00u)
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_RMS_THRESHOLD_SHIFT (0x00000008u)
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_RMS_THRESHOLD_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_ADDR (0x00000228u)
#define CSL_DFE_RX_IMB_ERR_SHIFT_REG_RESETVAL (0x00000000u)

/* TESTBUS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 top_test_ctrl : 4;
    Uint32 rsvd0 : 3;
    Uint32 imb_test_ctrl : 9;
#else 
    Uint32 imb_test_ctrl : 9;
    Uint32 rsvd0 : 3;
    Uint32 top_test_ctrl : 4;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_RX_TESTBUS_REG;

/* Testbus control. IMB node selection. */
#define CSL_DFE_RX_TESTBUS_REG_IMB_TEST_CTRL_MASK (0x000001FFu)
#define CSL_DFE_RX_TESTBUS_REG_IMB_TEST_CTRL_SHIFT (0x00000000u)
#define CSL_DFE_RX_TESTBUS_REG_IMB_TEST_CTRL_RESETVAL (0x00000000u)

/* Testbus control. Top level Rx sub-chip node selection.   */
#define CSL_DFE_RX_TESTBUS_REG_TOP_TEST_CTRL_MASK (0x0000F000u)
#define CSL_DFE_RX_TESTBUS_REG_TOP_TEST_CTRL_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_TESTBUS_REG_TOP_TEST_CTRL_RESETVAL (0x00000000u)

#define CSL_DFE_RX_TESTBUS_REG_ADDR (0x0000022Cu)
#define CSL_DFE_RX_TESTBUS_REG_RESETVAL (0x00000000u)

/* FEAGC_DC_TESTBUS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 feagc_dc_test_ctrl : 9;
#else 
    Uint32 feagc_dc_test_ctrl : 9;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_RX_FEAGC_DC_TESTBUS_REG;

/* Testbus control. Feagc & DC node selection. */
#define CSL_DFE_RX_FEAGC_DC_TESTBUS_REG_FEAGC_DC_TEST_CTRL_MASK (0x000001FFu)
#define CSL_DFE_RX_FEAGC_DC_TESTBUS_REG_FEAGC_DC_TEST_CTRL_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_DC_TESTBUS_REG_FEAGC_DC_TEST_CTRL_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_DC_TESTBUS_REG_ADDR (0x00000230u)
#define CSL_DFE_RX_FEAGC_DC_TESTBUS_REG_RESETVAL (0x00000000u)

/* MEM_ACCESS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 gain_err_mem_access : 1;
    Uint32 gsg_mem_access : 1;
#else 
    Uint32 gsg_mem_access : 1;
    Uint32 gain_err_mem_access : 1;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_RX_MEM_ACCESS_REG;

/* Front-end AGC, DC Canceller and IQ Imbalance Correction gate signal generator local memory access control. */
#define CSL_DFE_RX_MEM_ACCESS_REG_GSG_MEM_ACCESS_MASK (0x00000001u)
#define CSL_DFE_RX_MEM_ACCESS_REG_GSG_MEM_ACCESS_SHIFT (0x00000000u)
#define CSL_DFE_RX_MEM_ACCESS_REG_GSG_MEM_ACCESS_RESETVAL (0x00000000u)

/* Front-end AGC gain and error map local memory access control. */
#define CSL_DFE_RX_MEM_ACCESS_REG_GAIN_ERR_MEM_ACCESS_MASK (0x00000002u)
#define CSL_DFE_RX_MEM_ACCESS_REG_GAIN_ERR_MEM_ACCESS_SHIFT (0x00000001u)
#define CSL_DFE_RX_MEM_ACCESS_REG_GAIN_ERR_MEM_ACCESS_RESETVAL (0x00000000u)

#define CSL_DFE_RX_MEM_ACCESS_REG_ADDR (0x00000234u)
#define CSL_DFE_RX_MEM_ACCESS_REG_RESETVAL (0x00000000u)

/* CLOCK_GATING */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd3 : 16;
    Uint32 input_clk_gate : 2;
    Uint32 switch_clk_gate : 2;
    Uint32 rsvd2 : 1;
    Uint32 dec1_clk_gate : 3;
    Uint32 rsvd1 : 1;
    Uint32 dec2_clk_gate : 3;
    Uint32 rsvd0 : 1;
    Uint32 output_clk_gate : 3;
#else 
    Uint32 output_clk_gate : 3;
    Uint32 rsvd0 : 1;
    Uint32 dec2_clk_gate : 3;
    Uint32 rsvd1 : 1;
    Uint32 dec1_clk_gate : 3;
    Uint32 rsvd2 : 1;
    Uint32 switch_clk_gate : 2;
    Uint32 input_clk_gate : 2;
    Uint32 rsvd3 : 16;
#endif 
} CSL_DFE_RX_CLOCK_GATING_REG;

/* Output stream reference clock gating control.  */
#define CSL_DFE_RX_CLOCK_GATING_REG_OUTPUT_CLK_GATE_MASK (0x00000007u)
#define CSL_DFE_RX_CLOCK_GATING_REG_OUTPUT_CLK_GATE_SHIFT (0x00000000u)
#define CSL_DFE_RX_CLOCK_GATING_REG_OUTPUT_CLK_GATE_RESETVAL (0x00000000u)

/* Decimation filter 2 reference clock gating control.  */
#define CSL_DFE_RX_CLOCK_GATING_REG_DEC2_CLK_GATE_MASK (0x00000070u)
#define CSL_DFE_RX_CLOCK_GATING_REG_DEC2_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_RX_CLOCK_GATING_REG_DEC2_CLK_GATE_RESETVAL (0x00000000u)

/* Decimation filter 1 reference clock gating control.  */
#define CSL_DFE_RX_CLOCK_GATING_REG_DEC1_CLK_GATE_MASK (0x00000700u)
#define CSL_DFE_RX_CLOCK_GATING_REG_DEC1_CLK_GATE_SHIFT (0x00000008u)
#define CSL_DFE_RX_CLOCK_GATING_REG_DEC1_CLK_GATE_RESETVAL (0x00000000u)

/* Switch reference clock gating control.  */
#define CSL_DFE_RX_CLOCK_GATING_REG_SWITCH_CLK_GATE_MASK (0x00003000u)
#define CSL_DFE_RX_CLOCK_GATING_REG_SWITCH_CLK_GATE_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_CLOCK_GATING_REG_SWITCH_CLK_GATE_RESETVAL (0x00000000u)

/* Input antenna reference clock gating control. */
#define CSL_DFE_RX_CLOCK_GATING_REG_INPUT_CLK_GATE_MASK (0x0000C000u)
#define CSL_DFE_RX_CLOCK_GATING_REG_INPUT_CLK_GATE_SHIFT (0x0000000Eu)
#define CSL_DFE_RX_CLOCK_GATING_REG_INPUT_CLK_GATE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_CLOCK_GATING_REG_ADDR (0x0000023Cu)
#define CSL_DFE_RX_CLOCK_GATING_REG_RESETVAL (0x00000000u)

/* NCO_FREQ_WORD_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_15_0 : 16;
#else 
    Uint32 freq_word_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_NCO_FREQ_WORD_W0_REG;

/* NCO/Mixer block frequency control words. */
#define CSL_DFE_RX_NCO_FREQ_WORD_W0_REG_FREQ_WORD_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_NCO_FREQ_WORD_W0_REG_FREQ_WORD_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_NCO_FREQ_WORD_W0_REG_FREQ_WORD_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_NCO_FREQ_WORD_W0_REG_ADDR (0x00000240u)
#define CSL_DFE_RX_NCO_FREQ_WORD_W0_REG_RESETVAL (0x00000000u)

/* NCO_FREQ_WORD_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_31_16 : 16;
#else 
    Uint32 freq_word_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_NCO_FREQ_WORD_W1_REG;

/*  */
#define CSL_DFE_RX_NCO_FREQ_WORD_W1_REG_FREQ_WORD_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_NCO_FREQ_WORD_W1_REG_FREQ_WORD_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_NCO_FREQ_WORD_W1_REG_FREQ_WORD_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_NCO_FREQ_WORD_W1_REG_ADDR (0x00000244u)
#define CSL_DFE_RX_NCO_FREQ_WORD_W1_REG_RESETVAL (0x00000000u)

/* NCO_FREQ_WORD_W2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 freq_word_47_32 : 16;
#else 
    Uint32 freq_word_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_NCO_FREQ_WORD_W2_REG;

/*  */
#define CSL_DFE_RX_NCO_FREQ_WORD_W2_REG_FREQ_WORD_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_RX_NCO_FREQ_WORD_W2_REG_FREQ_WORD_47_32_SHIFT (0x00000000u)
#define CSL_DFE_RX_NCO_FREQ_WORD_W2_REG_FREQ_WORD_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_RX_NCO_FREQ_WORD_W2_REG_ADDR (0x00000248u)
#define CSL_DFE_RX_NCO_FREQ_WORD_W2_REG_RESETVAL (0x00000000u)

/* EQR_DC_IOFFSET */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dc_i_offset : 16;
#else 
    Uint32 dc_i_offset : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_DC_IOFFSET_REG;

/* Equalizer block DC offsets for equalizer i-path outputs. */
#define CSL_DFE_RX_EQR_DC_IOFFSET_REG_DC_I_OFFSET_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_DC_IOFFSET_REG_DC_I_OFFSET_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_DC_IOFFSET_REG_DC_I_OFFSET_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_DC_IOFFSET_REG_ADDR (0x00000280u)
#define CSL_DFE_RX_EQR_DC_IOFFSET_REG_RESETVAL (0x00000000u)

/* EQR_DC_QOFFSET */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dc_q_offset : 16;
#else 
    Uint32 dc_q_offset : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_DC_QOFFSET_REG;

/* Equalizer block DC offsets for equalizer q-path outputs. */
#define CSL_DFE_RX_EQR_DC_QOFFSET_REG_DC_Q_OFFSET_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_DC_QOFFSET_REG_DC_Q_OFFSET_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_DC_QOFFSET_REG_DC_Q_OFFSET_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_DC_QOFFSET_REG_ADDR (0x00000284u)
#define CSL_DFE_RX_EQR_DC_QOFFSET_REG_RESETVAL (0x00000000u)

/* IMB_TAP_II */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tap_ii : 16;
#else 
    Uint32 tap_ii : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_TAP_II_REG;

/* IQ Imbalance Correction block fixed IQ imbalance i-tap on i-data. */
#define CSL_DFE_RX_IMB_TAP_II_REG_TAP_II_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_TAP_II_REG_TAP_II_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_TAP_II_REG_TAP_II_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_TAP_II_REG_ADDR (0x000002C0u)
#define CSL_DFE_RX_IMB_TAP_II_REG_RESETVAL (0x00000000u)

/* IMB_TAP_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tap_iq : 16;
#else 
    Uint32 tap_iq : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_TAP_IQ_REG;

/* IQ Imbalance Correction block fixed IQ imbalance q-tap on i-data. */
#define CSL_DFE_RX_IMB_TAP_IQ_REG_TAP_IQ_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_TAP_IQ_REG_TAP_IQ_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_TAP_IQ_REG_TAP_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_TAP_IQ_REG_ADDR (0x000002C4u)
#define CSL_DFE_RX_IMB_TAP_IQ_REG_RESETVAL (0x00000000u)

/* IMB_TAP_QI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tap_qi : 16;
#else 
    Uint32 tap_qi : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_TAP_QI_REG;

/* IQ Imbalance Correction block fixed IQ imbalance i-tap on q-data. */
#define CSL_DFE_RX_IMB_TAP_QI_REG_TAP_QI_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_TAP_QI_REG_TAP_QI_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_TAP_QI_REG_TAP_QI_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_TAP_QI_REG_ADDR (0x000002C8u)
#define CSL_DFE_RX_IMB_TAP_QI_REG_RESETVAL (0x00000000u)

/* IMB_TAP_QQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 tap_qq : 16;
#else 
    Uint32 tap_qq : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_TAP_QQ_REG;

/* IQ Imbalance Correction block fixed IQ imbalance q-tap on q-data. */
#define CSL_DFE_RX_IMB_TAP_QQ_REG_TAP_QQ_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_TAP_QQ_REG_TAP_QQ_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_TAP_QQ_REG_TAP_QQ_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_TAP_QQ_REG_ADDR (0x000002CCu)
#define CSL_DFE_RX_IMB_TAP_QQ_REG_RESETVAL (0x00000000u)

/* R2C_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 phase_ssel : 4;
#else 
    Uint32 phase_ssel : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_RX_R2C_SSEL_REG;

/* Real-to-Complex block sync selection control for resetting the Fs/4 mixer phase. */
#define CSL_DFE_RX_R2C_SSEL_REG_PHASE_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_RX_R2C_SSEL_REG_PHASE_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_RX_R2C_SSEL_REG_PHASE_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_RX_R2C_SSEL_REG_ADDR (0x00000300u)
#define CSL_DFE_RX_R2C_SSEL_REG_RESETVAL (0x00000000u)

/* NCO_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 dither_ssel : 4;
    Uint32 phase_ssel : 4;
    Uint32 freq_ssel : 4;
#else 
    Uint32 freq_ssel : 4;
    Uint32 phase_ssel : 4;
    Uint32 dither_ssel : 4;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_RX_NCO_SSEL_REG;

/* NCO/Mixer block sync selection control for syncing frequency control words into the NCO. */
#define CSL_DFE_RX_NCO_SSEL_REG_FREQ_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_RX_NCO_SSEL_REG_FREQ_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_RX_NCO_SSEL_REG_FREQ_SSEL_RESETVAL (0x00000000u)

/* NCO/Mixer block sync selection control to zero the NCO phase accumulator. */
#define CSL_DFE_RX_NCO_SSEL_REG_PHASE_SSEL_MASK (0x000000F0u)
#define CSL_DFE_RX_NCO_SSEL_REG_PHASE_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_RX_NCO_SSEL_REG_PHASE_SSEL_RESETVAL (0x00000000u)

/* NCO/Mixer block sync selection control to reset the NCO dither generator. */
#define CSL_DFE_RX_NCO_SSEL_REG_DITHER_SSEL_MASK (0x00000F00u)
#define CSL_DFE_RX_NCO_SSEL_REG_DITHER_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_RX_NCO_SSEL_REG_DITHER_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_RX_NCO_SSEL_REG_ADDR (0x00000304u)
#define CSL_DFE_RX_NCO_SSEL_REG_RESETVAL (0x00000000u)

/* EQR_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel3 : 4;
    Uint32 ssel2 : 4;
    Uint32 ssel1 : 4;
    Uint32 ssel0 : 4;
#else 
    Uint32 ssel0 : 4;
    Uint32 ssel1 : 4;
    Uint32 ssel2 : 4;
    Uint32 ssel3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_SSEL_REG;

/*  */
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL0_MASK (0x0000000Fu)
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL0_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL1_MASK (0x000000F0u)
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL1_SHIFT (0x00000004u)
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL2_MASK (0x00000F00u)
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL2_SHIFT (0x00000008u)
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL2_RESETVAL (0x00000000u)

/* Equalizer block sync selection control for syncing new coefficients into the equalizer. */
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL3_MASK (0x0000F000u)
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL3_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_EQR_SSEL_REG_SSEL3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_SSEL_REG_ADDR (0x00000308u)
#define CSL_DFE_RX_EQR_SSEL_REG_RESETVAL (0x00000000u)

/* IMB_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel3 : 4;
    Uint32 ssel2 : 4;
    Uint32 ssel1 : 4;
    Uint32 ssel0 : 4;
#else 
    Uint32 ssel0 : 4;
    Uint32 ssel1 : 4;
    Uint32 ssel2 : 4;
    Uint32 ssel3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_SSEL_REG;

/*  */
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL0_MASK (0x0000000Fu)
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL0_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL1_MASK (0x000000F0u)
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL1_SHIFT (0x00000004u)
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL2_MASK (0x00000F00u)
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL2_SHIFT (0x00000008u)
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL2_RESETVAL (0x00000000u)

/* IQ Imbalance Correction block sync selection control to synchronize the start of the computational block integration period. */
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL3_MASK (0x0000F000u)
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL3_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_IMB_SSEL_REG_SSEL3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_SSEL_REG_ADDR (0x0000030Cu)
#define CSL_DFE_RX_IMB_SSEL_REG_RESETVAL (0x00000000u)

/* GSG_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 feagc_gsg_ssel : 4;
    Uint32 dc_gsg_ssel : 4;
    Uint32 imb_gsg_ssel : 4;
#else 
    Uint32 imb_gsg_ssel : 4;
    Uint32 dc_gsg_ssel : 4;
    Uint32 feagc_gsg_ssel : 4;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_RX_GSG_SSEL_REG;

/* IQ Imbalance Correction gate signal generator sync selection control. */
#define CSL_DFE_RX_GSG_SSEL_REG_IMB_GSG_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_RX_GSG_SSEL_REG_IMB_GSG_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_RX_GSG_SSEL_REG_IMB_GSG_SSEL_RESETVAL (0x00000000u)

/* DC Canceller gate signal generator sync selection control. */
#define CSL_DFE_RX_GSG_SSEL_REG_DC_GSG_SSEL_MASK (0x000000F0u)
#define CSL_DFE_RX_GSG_SSEL_REG_DC_GSG_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_RX_GSG_SSEL_REG_DC_GSG_SSEL_RESETVAL (0x00000000u)

/* Front-end AGC gate signal generator sync selection control. */
#define CSL_DFE_RX_GSG_SSEL_REG_FEAGC_GSG_SSEL_MASK (0x00000F00u)
#define CSL_DFE_RX_GSG_SSEL_REG_FEAGC_GSG_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_RX_GSG_SSEL_REG_FEAGC_GSG_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_RX_GSG_SSEL_REG_ADDR (0x00000310u)
#define CSL_DFE_RX_GSG_SSEL_REG_RESETVAL (0x00000000u)

/* FEAGC_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gainacc_ssel3 : 4;
    Uint32 gainacc_ssel2 : 4;
    Uint32 gainacc_ssel1 : 4;
    Uint32 gainacc_ssel0 : 4;
#else 
    Uint32 gainacc_ssel0 : 4;
    Uint32 gainacc_ssel1 : 4;
    Uint32 gainacc_ssel2 : 4;
    Uint32 gainacc_ssel3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_SSEL_REG;

/*  */
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL0_MASK (0x0000000Fu)
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL0_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL1_MASK (0x000000F0u)
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL1_SHIFT (0x00000004u)
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL2_MASK (0x00000F00u)
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL2_SHIFT (0x00000008u)
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL2_RESETVAL (0x00000000u)

/* FEAGC block sync source select for loading “gain_init” into the gain loop accumulator. */
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL3_MASK (0x0000F000u)
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL3_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_FEAGC_SSEL_REG_GAINACC_SSEL3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_SSEL_REG_ADDR (0x00000314u)
#define CSL_DFE_RX_FEAGC_SSEL_REG_RESETVAL (0x00000000u)

/* DC_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dkacc_ssel3 : 4;
    Uint32 dkacc_ssel2 : 4;
    Uint32 dkacc_ssel1 : 4;
    Uint32 dkacc_ssel0 : 4;
#else 
    Uint32 dkacc_ssel0 : 4;
    Uint32 dkacc_ssel1 : 4;
    Uint32 dkacc_ssel2 : 4;
    Uint32 dkacc_ssel3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_DC_SSEL_REG;

/*  */
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL0_MASK (0x0000000Fu)
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL0_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL1_MASK (0x000000F0u)
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL1_SHIFT (0x00000004u)
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL2_MASK (0x00000F00u)
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL2_SHIFT (0x00000008u)
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL2_RESETVAL (0x00000000u)

/* DC Canceller sync source select for loading  */
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL3_MASK (0x0000F000u)
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL3_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_DC_SSEL_REG_DKACC_SSEL3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_SSEL_REG_ADDR (0x00000318u)
#define CSL_DFE_RX_DC_SSEL_REG_RESETVAL (0x00000000u)

/* PM_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 ssel3 : 4;
    Uint32 ssel2 : 4;
    Uint32 ssel1 : 4;
    Uint32 ssel0 : 4;
#else 
    Uint32 ssel0 : 4;
    Uint32 ssel1 : 4;
    Uint32 ssel2 : 4;
    Uint32 ssel3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_SSEL_REG;

/*  */
#define CSL_DFE_RX_PM_SSEL_REG_SSEL0_MASK (0x0000000Fu)
#define CSL_DFE_RX_PM_SSEL_REG_SSEL0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_SSEL_REG_SSEL0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_PM_SSEL_REG_SSEL1_MASK (0x000000F0u)
#define CSL_DFE_RX_PM_SSEL_REG_SSEL1_SHIFT (0x00000004u)
#define CSL_DFE_RX_PM_SSEL_REG_SSEL1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_PM_SSEL_REG_SSEL2_MASK (0x00000F00u)
#define CSL_DFE_RX_PM_SSEL_REG_SSEL2_SHIFT (0x00000008u)
#define CSL_DFE_RX_PM_SSEL_REG_SSEL2_RESETVAL (0x00000000u)

/* Power meter sync selection to sync the start of a new power meter cycle. */
#define CSL_DFE_RX_PM_SSEL_REG_SSEL3_MASK (0x0000F000u)
#define CSL_DFE_RX_PM_SSEL_REG_SSEL3_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_PM_SSEL_REG_SSEL3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_SSEL_REG_ADDR (0x0000031Cu)
#define CSL_DFE_RX_PM_SSEL_REG_RESETVAL (0x00000000u)

/* TEST_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 chksum_ssel : 4;
    Uint32 siggen_ssel : 4;
#else 
    Uint32 siggen_ssel : 4;
    Uint32 chksum_ssel : 4;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_TEST_SSEL_REG;

/* Signal generator sync selection control. */
#define CSL_DFE_RX_TEST_SSEL_REG_SIGGEN_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_RX_TEST_SSEL_REG_SIGGEN_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_RX_TEST_SSEL_REG_SIGGEN_SSEL_RESETVAL (0x00000000u)

/* Checksum signature analyzer sync selection control. */
#define CSL_DFE_RX_TEST_SSEL_REG_CHKSUM_SSEL_MASK (0x000000F0u)
#define CSL_DFE_RX_TEST_SSEL_REG_CHKSUM_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_RX_TEST_SSEL_REG_CHKSUM_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_RX_TEST_SSEL_REG_ADDR (0x00000320u)
#define CSL_DFE_RX_TEST_SSEL_REG_RESETVAL (0x00000000u)

/* IMB_COR_II0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 cor_ii_2_0 : 3;
#else 
    Uint32 cor_ii_2_0 : 3;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_RX_IMB_COR_II0_REG;

/* IQ Imbalance Correction block i-tap on i-data correction value.  (READ ONLY) */
#define CSL_DFE_RX_IMB_COR_II0_REG_COR_II_2_0_MASK (0x00000007u)
#define CSL_DFE_RX_IMB_COR_II0_REG_COR_II_2_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_COR_II0_REG_COR_II_2_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_COR_II0_REG_ADDR (0x00000340u)
#define CSL_DFE_RX_IMB_COR_II0_REG_RESETVAL (0x00000000u)

/* IMB_COR_II1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cor_ii_18_3 : 16;
#else 
    Uint32 cor_ii_18_3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_COR_II1_REG;

/*  */
#define CSL_DFE_RX_IMB_COR_II1_REG_COR_II_18_3_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_COR_II1_REG_COR_II_18_3_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_COR_II1_REG_COR_II_18_3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_COR_II1_REG_ADDR (0x00000344u)
#define CSL_DFE_RX_IMB_COR_II1_REG_RESETVAL (0x00000000u)

/* IMB_COR_IQ0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 cor_iq0_2_0 : 3;
#else 
    Uint32 cor_iq0_2_0 : 3;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_RX_IMB_COR_IQ0_REG;

/* IQ Imbalance Correction block q-tap on i-data correction value.  (READ ONLY) */
#define CSL_DFE_RX_IMB_COR_IQ0_REG_COR_IQ0_2_0_MASK (0x00000007u)
#define CSL_DFE_RX_IMB_COR_IQ0_REG_COR_IQ0_2_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_COR_IQ0_REG_COR_IQ0_2_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_COR_IQ0_REG_ADDR (0x00000348u)
#define CSL_DFE_RX_IMB_COR_IQ0_REG_RESETVAL (0x00000000u)

/* IMB_COR_IQ1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cor_iq0_18_3 : 16;
#else 
    Uint32 cor_iq0_18_3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_COR_IQ1_REG;

/*  */
#define CSL_DFE_RX_IMB_COR_IQ1_REG_COR_IQ0_18_3_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_COR_IQ1_REG_COR_IQ0_18_3_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_COR_IQ1_REG_COR_IQ0_18_3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_COR_IQ1_REG_ADDR (0x0000034Cu)
#define CSL_DFE_RX_IMB_COR_IQ1_REG_RESETVAL (0x00000000u)

/* IMB_COR_QI0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 cor_qi0_2_0 : 3;
#else 
    Uint32 cor_qi0_2_0 : 3;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_RX_IMB_COR_QI0_REG;

/* IQ Imbalance Correction block i-tap on q-data correction value.  (READ ONLY) */
#define CSL_DFE_RX_IMB_COR_QI0_REG_COR_QI0_2_0_MASK (0x00000007u)
#define CSL_DFE_RX_IMB_COR_QI0_REG_COR_QI0_2_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_COR_QI0_REG_COR_QI0_2_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_COR_QI0_REG_ADDR (0x00000350u)
#define CSL_DFE_RX_IMB_COR_QI0_REG_RESETVAL (0x00000000u)

/* IMB_COR_QI1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cor_qi0_18_3 : 16;
#else 
    Uint32 cor_qi0_18_3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_COR_QI1_REG;

/*  */
#define CSL_DFE_RX_IMB_COR_QI1_REG_COR_QI0_18_3_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_COR_QI1_REG_COR_QI0_18_3_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_COR_QI1_REG_COR_QI0_18_3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_COR_QI1_REG_ADDR (0x00000354u)
#define CSL_DFE_RX_IMB_COR_QI1_REG_RESETVAL (0x00000000u)

/* IMB_COR_QQ0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 cor_qq0_2_0 : 3;
#else 
    Uint32 cor_qq0_2_0 : 3;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_RX_IMB_COR_QQ0_REG;

/* IQ Imbalance Correction block q-tap on q-data correction value.  (READ ONLY) */
#define CSL_DFE_RX_IMB_COR_QQ0_REG_COR_QQ0_2_0_MASK (0x00000007u)
#define CSL_DFE_RX_IMB_COR_QQ0_REG_COR_QQ0_2_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_COR_QQ0_REG_COR_QQ0_2_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_COR_QQ0_REG_ADDR (0x00000358u)
#define CSL_DFE_RX_IMB_COR_QQ0_REG_RESETVAL (0x00000000u)

/* IMB_COR_QQ1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cor_qq0_18_3 : 16;
#else 
    Uint32 cor_qq0_18_3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_COR_QQ1_REG;

/*  */
#define CSL_DFE_RX_IMB_COR_QQ1_REG_COR_QQ0_18_3_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_COR_QQ1_REG_COR_QQ0_18_3_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_COR_QQ1_REG_COR_QQ0_18_3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_COR_QQ1_REG_ADDR (0x0000035Cu)
#define CSL_DFE_RX_IMB_COR_QQ1_REG_RESETVAL (0x00000000u)

/* IMB_GSG_TIMER_SEQ_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 26;
    Uint32 timer_seq_len : 6;
#else 
    Uint32 timer_seq_len : 6;
    Uint32 rsvd0 : 26;
#endif 
} CSL_DFE_RX_IMB_GSG_TIMER_SEQ_LEN_REG;

/* IQ Imbalance Correction block gate signal generator timer sequence lengths.  Length of the timer sequence (per gating signal) between sync pulses. May be 0 to 63.  */
#define CSL_DFE_RX_IMB_GSG_TIMER_SEQ_LEN_REG_TIMER_SEQ_LEN_MASK (0x0000003Fu)
#define CSL_DFE_RX_IMB_GSG_TIMER_SEQ_LEN_REG_TIMER_SEQ_LEN_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_GSG_TIMER_SEQ_LEN_REG_TIMER_SEQ_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_GSG_TIMER_SEQ_LEN_REG_ADDR (0x000003ECu)
#define CSL_DFE_RX_IMB_GSG_TIMER_SEQ_LEN_REG_RESETVAL (0x00000000u)

/* IMB_GSG_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 init_toggle_state3 : 1;
    Uint32 init_toggle_state2 : 1;
    Uint32 init_toggle_state1 : 1;
    Uint32 init_toggle_state0 : 1;
    Uint32 rsvd0 : 4;
    Uint32 gating_mode3 : 2;
    Uint32 gating_mode2 : 2;
    Uint32 gating_mode1 : 2;
    Uint32 gating_mode0 : 2;
#else 
    Uint32 gating_mode0 : 2;
    Uint32 gating_mode1 : 2;
    Uint32 gating_mode2 : 2;
    Uint32 gating_mode3 : 2;
    Uint32 rsvd0 : 4;
    Uint32 init_toggle_state0 : 1;
    Uint32 init_toggle_state1 : 1;
    Uint32 init_toggle_state2 : 1;
    Uint32 init_toggle_state3 : 1;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_RX_IMB_GSG_CONFIG_REG;

/*  */
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE0_MASK (0x00000003u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE0_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE1_MASK (0x0000000Cu)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE1_SHIFT (0x00000002u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE2_MASK (0x00000030u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE2_SHIFT (0x00000004u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE2_RESETVAL (0x00000000u)

/* IQ Imbalance Correction block gate signal generator gating mode. */
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE3_MASK (0x000000C0u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE3_SHIFT (0x00000006u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_GATING_MODE3_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE0_MASK (0x00001000u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE0_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE1_MASK (0x00002000u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE1_SHIFT (0x0000000Du)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE2_MASK (0x00004000u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE2_SHIFT (0x0000000Eu)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE2_RESETVAL (0x00000000u)

/* IQ Imbalance Correction block gate signal generator initial toggle state value. */
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE3_MASK (0x00008000u)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE3_SHIFT (0x0000000Fu)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_INIT_TOGGLE_STATE3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_ADDR (0x000003FCu)
#define CSL_DFE_RX_IMB_GSG_CONFIG_REG_RESETVAL (0x00000000u)

/* FEAGC_NOTCH_FILT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 26;
    Uint32 filter_corner : 4;
    Uint32 nyq_mode : 1;
    Uint32 filter_ena : 1;
#else 
    Uint32 filter_ena : 1;
    Uint32 nyq_mode : 1;
    Uint32 filter_corner : 4;
    Uint32 rsvd0 : 26;
#endif 
} CSL_DFE_RX_FEAGC_NOTCH_FILT_REG;

/* FEAGC block enable for DC/Nyquist notch filter. */
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_FILTER_ENA_MASK (0x00000001u)
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_FILTER_ENA_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_FILTER_ENA_RESETVAL (0x00000000u)

/* FEAGC block notch filter mode selection. */
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_NYQ_MODE_MASK (0x00000002u)
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_NYQ_MODE_SHIFT (0x00000001u)
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_NYQ_MODE_RESETVAL (0x00000000u)

/* FEAGC block coefficient in the notch filter: */
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_FILTER_CORNER_MASK (0x0000003Cu)
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_FILTER_CORNER_SHIFT (0x00000002u)
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_FILTER_CORNER_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_ADDR (0x00000600u)
#define CSL_DFE_RX_FEAGC_NOTCH_FILT_REG_RESETVAL (0x00000000u)

/* FEAGC_POW_GLOBAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 acc_offset : 8;
    Uint32 rsvd0 : 1;
    Uint32 acc_shift : 6;
    Uint32 avgpow_ena : 1;
#else 
    Uint32 avgpow_ena : 1;
    Uint32 acc_shift : 6;
    Uint32 rsvd0 : 1;
    Uint32 acc_offset : 8;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_RX_FEAGC_POW_GLOBAL_REG;

/* FEAGC block enable for averaging power measurement block. */
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_AVGPOW_ENA_MASK (0x00000001u)
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_AVGPOW_ENA_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_AVGPOW_ENA_RESETVAL (0x00000000u)

/* FEAGC block right shift of power meas result (0 to 55) based on the error map table and actual number of samples integrated. */
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_ACC_SHIFT_MASK (0x0000007Eu)
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_ACC_SHIFT_SHIFT (0x00000001u)
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_ACC_SHIFT_RESETVAL (0x00000000u)

/* Program as 2s complement negative number; based on the error map table. */
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_ACC_OFFSET_MASK (0x0000FF00u)
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_ACC_OFFSET_SHIFT (0x00000008u)
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_ACC_OFFSET_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_ADDR (0x00000604u)
#define CSL_DFE_RX_FEAGC_POW_GLOBAL_REG_RESETVAL (0x00000000u)

/* FEAGC_INTERVAL_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_INTERVAL_W0_REG;

/* FEAGC block integration interval value (0 to 2^24 – 1). Number of signal samples (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate) between dc_update pulses. Must be > 0 for normal operation. */
#define CSL_DFE_RX_FEAGC_INTERVAL_W0_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_INTERVAL_W0_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_INTERVAL_W0_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_INTERVAL_W0_REG_ADDR (0x00000608u)
#define CSL_DFE_RX_FEAGC_INTERVAL_W0_REG_RESETVAL (0x00000000u)

/* FEAGC_INTERVAL_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 interval_23_16 : 8;
#else 
    Uint32 interval_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_FEAGC_INTERVAL_W1_REG;

/*  */
#define CSL_DFE_RX_FEAGC_INTERVAL_W1_REG_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_RX_FEAGC_INTERVAL_W1_REG_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_INTERVAL_W1_REG_INTERVAL_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_INTERVAL_W1_REG_ADDR (0x0000060Cu)
#define CSL_DFE_RX_FEAGC_INTERVAL_W1_REG_RESETVAL (0x00000000u)

/* FEAGC_UPDATE_DELAY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 update_delay : 16;
#else 
    Uint32 update_delay : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_UPDATE_DELAY_REG;

/* FEAGC block delay value from sync to first dc_update pulse (0 to 2^16 -1). Number of signal samples (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate.) */
#define CSL_DFE_RX_FEAGC_UPDATE_DELAY_REG_UPDATE_DELAY_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_UPDATE_DELAY_REG_UPDATE_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_UPDATE_DELAY_REG_UPDATE_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_UPDATE_DELAY_REG_ADDR (0x00000610u)
#define CSL_DFE_RX_FEAGC_UPDATE_DELAY_REG_RESETVAL (0x00000000u)

/* FEAGC_ERR_SHIFT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 err_shift : 5;
#else 
    Uint32 err_shift : 5;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_RX_FEAGC_ERR_SHIFT_REG;

/* FEAGC block left shift of 8-bit error value from error map table. 0 to 31 */
#define CSL_DFE_RX_FEAGC_ERR_SHIFT_REG_ERR_SHIFT_MASK (0x0000001Fu)
#define CSL_DFE_RX_FEAGC_ERR_SHIFT_REG_ERR_SHIFT_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_ERR_SHIFT_REG_ERR_SHIFT_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_ERR_SHIFT_REG_ADDR (0x00000620u)
#define CSL_DFE_RX_FEAGC_ERR_SHIFT_REG_RESETVAL (0x00000000u)

/* FEAGC_SD_ENA */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 31;
    Uint32 sd_ena : 1;
#else 
    Uint32 sd_ena : 1;
    Uint32 rsvd0 : 31;
#endif 
} CSL_DFE_RX_FEAGC_SD_ENA_REG;

/* FEAGC block enable for signal level detector. */
#define CSL_DFE_RX_FEAGC_SD_ENA_REG_SD_ENA_MASK (0x00000001u)
#define CSL_DFE_RX_FEAGC_SD_ENA_REG_SD_ENA_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_SD_ENA_REG_SD_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_SD_ENA_REG_ADDR (0x00000624u)
#define CSL_DFE_RX_FEAGC_SD_ENA_REG_RESETVAL (0x00000000u)

/* FEAGC_SD_THRESH_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sd_thresh_15_0 : 16;
#else 
    Uint32 sd_thresh_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_SD_THRESH_W0_REG;

/* FEAGC block threshold to compare mag-squared block output (which may contain sum of up to 4 mag-squared samples, depending on mode) to qualify “no signal”. Aligned with the LSBs of the mag-squared result. Unsigned value. */
#define CSL_DFE_RX_FEAGC_SD_THRESH_W0_REG_SD_THRESH_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_SD_THRESH_W0_REG_SD_THRESH_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_SD_THRESH_W0_REG_SD_THRESH_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_SD_THRESH_W0_REG_ADDR (0x00000628u)
#define CSL_DFE_RX_FEAGC_SD_THRESH_W0_REG_RESETVAL (0x00000000u)

/* FEAGC_SD_THRESH_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 sd_thresh_23_16 : 8;
#else 
    Uint32 sd_thresh_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_FEAGC_SD_THRESH_W1_REG;

/*  */
#define CSL_DFE_RX_FEAGC_SD_THRESH_W1_REG_SD_THRESH_23_16_MASK (0x000000FFu)
#define CSL_DFE_RX_FEAGC_SD_THRESH_W1_REG_SD_THRESH_23_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_SD_THRESH_W1_REG_SD_THRESH_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_SD_THRESH_W1_REG_ADDR (0x0000062Cu)
#define CSL_DFE_RX_FEAGC_SD_THRESH_W1_REG_RESETVAL (0x00000000u)

/* FEAGC_SD_SAMPLES */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sd_samples : 16;
#else 
    Uint32 sd_samples : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_SD_SAMPLES_REG;

/* FEAGC block number of mag-squared block outputs below threshold in window to assert “freeze” signal. 0 to 2^16 – 1. Specifies the number of samples – 1 (i.e. value of 0 is 1 sample). */
#define CSL_DFE_RX_FEAGC_SD_SAMPLES_REG_SD_SAMPLES_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_SD_SAMPLES_REG_SD_SAMPLES_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_SD_SAMPLES_REG_SD_SAMPLES_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_SD_SAMPLES_REG_ADDR (0x00000630u)
#define CSL_DFE_RX_FEAGC_SD_SAMPLES_REG_RESETVAL (0x00000000u)

/* FEAGC_SD_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sd_timer : 16;
#else 
    Uint32 sd_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_SD_TIMER_REG;

/* FEAGC block signal detect window timer value. 0 to 2^16 – 1. Number of signal samples (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate). Must be > 0 for normal operation. */
#define CSL_DFE_RX_FEAGC_SD_TIMER_REG_SD_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_SD_TIMER_REG_SD_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_SD_TIMER_REG_SD_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_SD_TIMER_REG_ADDR (0x00000634u)
#define CSL_DFE_RX_FEAGC_SD_TIMER_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_HIGH_ENA */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 31;
    Uint32 high_ena : 1;
#else 
    Uint32 high_ena : 1;
    Uint32 rsvd0 : 31;
#endif 
} CSL_DFE_RX_FEAGC_PK_HIGH_ENA_REG;

/* FEAGC block enable for high peak detector. */
#define CSL_DFE_RX_FEAGC_PK_HIGH_ENA_REG_HIGH_ENA_MASK (0x00000001u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_ENA_REG_HIGH_ENA_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_ENA_REG_HIGH_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_HIGH_ENA_REG_ADDR (0x00000638u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_ENA_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_HIGH_THRES */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 high_thres : 16;
#else 
    Uint32 high_thres : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_PK_HIGH_THRES_REG;

/* FEAGC block threshold to compare magnitude to qualify high sample value (unsigned) */
#define CSL_DFE_RX_FEAGC_PK_HIGH_THRES_REG_HIGH_THRES_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_PK_HIGH_THRES_REG_HIGH_THRES_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_THRES_REG_HIGH_THRES_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_HIGH_THRES_REG_ADDR (0x0000063Cu)
#define CSL_DFE_RX_FEAGC_PK_HIGH_THRES_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_HIGH_SAMPLES */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 high_samples : 16;
#else 
    Uint32 high_samples : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_PK_HIGH_SAMPLES_REG;

/* FEAGC block number of samples above threshold in window to assert “high_event” pulse. Specifies the number of samples – 1 (i.e. value of 0 is 1 sample). */
#define CSL_DFE_RX_FEAGC_PK_HIGH_SAMPLES_REG_HIGH_SAMPLES_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_PK_HIGH_SAMPLES_REG_HIGH_SAMPLES_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_SAMPLES_REG_HIGH_SAMPLES_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_HIGH_SAMPLES_REG_ADDR (0x00000640u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_SAMPLES_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_HIGH_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 high_timer : 16;
#else 
    Uint32 high_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_PK_HIGH_TIMER_REG;

/* FEAGC block high window timer value. Set to either 1/4 (if the streams value is 0 or 1) or 1/2 (if streams is 2-7) the desired number of complex samples. Must be > 0 for normal operation. */
#define CSL_DFE_RX_FEAGC_PK_HIGH_TIMER_REG_HIGH_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_PK_HIGH_TIMER_REG_HIGH_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_TIMER_REG_HIGH_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_HIGH_TIMER_REG_ADDR (0x00000644u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_TIMER_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_HIGH_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 high_step : 16;
#else 
    Uint32 high_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_PK_HIGH_STEP_REG;

/* FEAGC block gain step size when high sample event; 2s complement negative value */
#define CSL_DFE_RX_FEAGC_PK_HIGH_STEP_REG_HIGH_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_PK_HIGH_STEP_REG_HIGH_STEP_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_STEP_REG_HIGH_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_HIGH_STEP_REG_ADDR (0x00000648u)
#define CSL_DFE_RX_FEAGC_PK_HIGH_STEP_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_LOW_ENA */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 31;
    Uint32 low_ena : 1;
#else 
    Uint32 low_ena : 1;
    Uint32 rsvd0 : 31;
#endif 
} CSL_DFE_RX_FEAGC_PK_LOW_ENA_REG;

/* FEAGC block enable for low peak detector. */
#define CSL_DFE_RX_FEAGC_PK_LOW_ENA_REG_LOW_ENA_MASK (0x00000001u)
#define CSL_DFE_RX_FEAGC_PK_LOW_ENA_REG_LOW_ENA_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_LOW_ENA_REG_LOW_ENA_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_LOW_ENA_REG_ADDR (0x0000064Cu)
#define CSL_DFE_RX_FEAGC_PK_LOW_ENA_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_LOW_THRES */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 low_thres : 16;
#else 
    Uint32 low_thres : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_PK_LOW_THRES_REG;

/* FEAGC block threshold to compare magnitude to qualify low sample value (unsigned) */
#define CSL_DFE_RX_FEAGC_PK_LOW_THRES_REG_LOW_THRES_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_PK_LOW_THRES_REG_LOW_THRES_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_LOW_THRES_REG_LOW_THRES_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_LOW_THRES_REG_ADDR (0x00000650u)
#define CSL_DFE_RX_FEAGC_PK_LOW_THRES_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_LOW_SAMPLES */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 low_samples : 16;
#else 
    Uint32 low_samples : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_PK_LOW_SAMPLES_REG;

/* FEAGC block number of samples above threshold in window to assert “low_event” pulse. Specifies the number of samples – 1 (i.e. value of 0 is 1 sample). */
#define CSL_DFE_RX_FEAGC_PK_LOW_SAMPLES_REG_LOW_SAMPLES_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_PK_LOW_SAMPLES_REG_LOW_SAMPLES_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_LOW_SAMPLES_REG_LOW_SAMPLES_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_LOW_SAMPLES_REG_ADDR (0x00000654u)
#define CSL_DFE_RX_FEAGC_PK_LOW_SAMPLES_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_LOW_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 low_timer : 16;
#else 
    Uint32 low_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_PK_LOW_TIMER_REG;

/* FEAGC block low window timer value. Set to either 1/4 (if the streams value is 0 or 1) or 1/2 (if streams is 2-7) the desired number of complex samples. Must be > 0 for normal operation. */
#define CSL_DFE_RX_FEAGC_PK_LOW_TIMER_REG_LOW_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_PK_LOW_TIMER_REG_LOW_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_LOW_TIMER_REG_LOW_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_LOW_TIMER_REG_ADDR (0x00000658u)
#define CSL_DFE_RX_FEAGC_PK_LOW_TIMER_REG_RESETVAL (0x00000000u)

/* FEAGC_PK_LOW_STEP */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 low_step : 16;
#else 
    Uint32 low_step : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_PK_LOW_STEP_REG;

/* FEAGC block gain step size when low sample event; 2s complement negative value */
#define CSL_DFE_RX_FEAGC_PK_LOW_STEP_REG_LOW_STEP_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_PK_LOW_STEP_REG_LOW_STEP_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_PK_LOW_STEP_REG_LOW_STEP_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_PK_LOW_STEP_REG_ADDR (0x0000065Cu)
#define CSL_DFE_RX_FEAGC_PK_LOW_STEP_REG_RESETVAL (0x00000000u)

/* FEAGC_GAIN_INIT_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gain_init_15_0 : 16;
#else 
    Uint32 gain_init_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_GAIN_INIT_W0_REG;

/* FEAGC block initial values for the 4 gain loop accumulator registers per feAGC block. */
#define CSL_DFE_RX_FEAGC_GAIN_INIT_W0_REG_GAIN_INIT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_GAIN_INIT_W0_REG_GAIN_INIT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_GAIN_INIT_W0_REG_GAIN_INIT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_GAIN_INIT_W0_REG_ADDR (0x00000660u)
#define CSL_DFE_RX_FEAGC_GAIN_INIT_W0_REG_RESETVAL (0x00000000u)

/* FEAGC_GAIN_INIT_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 gain_init_31_16 : 16;
#else 
    Uint32 gain_init_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_GAIN_INIT_W1_REG;

/*  */
#define CSL_DFE_RX_FEAGC_GAIN_INIT_W1_REG_GAIN_INIT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_GAIN_INIT_W1_REG_GAIN_INIT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_GAIN_INIT_W1_REG_GAIN_INIT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_GAIN_INIT_W1_REG_ADDR (0x00000664u)
#define CSL_DFE_RX_FEAGC_GAIN_INIT_W1_REG_RESETVAL (0x00000000u)

/* FEAGC_MASKOUT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 maskout : 11;
#else 
    Uint32 maskout : 11;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_RX_FEAGC_MASKOUT_REG;

/* FEAGC block mask out timer value (0 to 2047) per antenna. Starts on update from peak detector or power measurement path and holds off computation on these paths until it expires. Number of signal samples (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate). Must be > 0 for normal operation. */
#define CSL_DFE_RX_FEAGC_MASKOUT_REG_MASKOUT_MASK (0x000007FFu)
#define CSL_DFE_RX_FEAGC_MASKOUT_REG_MASKOUT_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_MASKOUT_REG_MASKOUT_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_MASKOUT_REG_ADDR (0x00000690u)
#define CSL_DFE_RX_FEAGC_MASKOUT_REG_RESETVAL (0x00000000u)

/* FEAGC_STREAM_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 sub_block_mode : 2;
    Uint32 streams : 3;
#else 
    Uint32 streams : 3;
    Uint32 sub_block_mode : 2;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_RX_FEAGC_STREAM_MODE_REG;

/* FEAGC block antenna mode control. */
#define CSL_DFE_RX_FEAGC_STREAM_MODE_REG_STREAMS_MASK (0x00000007u)
#define CSL_DFE_RX_FEAGC_STREAM_MODE_REG_STREAMS_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_STREAM_MODE_REG_STREAMS_RESETVAL (0x00000000u)

/* FEAGC block power mode control. */
#define CSL_DFE_RX_FEAGC_STREAM_MODE_REG_SUB_BLOCK_MODE_MASK (0x00000018u)
#define CSL_DFE_RX_FEAGC_STREAM_MODE_REG_SUB_BLOCK_MODE_SHIFT (0x00000003u)
#define CSL_DFE_RX_FEAGC_STREAM_MODE_REG_SUB_BLOCK_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_STREAM_MODE_REG_ADDR (0x000006A0u)
#define CSL_DFE_RX_FEAGC_STREAM_MODE_REG_RESETVAL (0x00000000u)

/* FEAGC_FREEZE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 freeze3 : 1;
    Uint32 freeze2 : 1;
    Uint32 freeze1 : 1;
    Uint32 freeze0 : 1;
#else 
    Uint32 freeze0 : 1;
    Uint32 freeze1 : 1;
    Uint32 freeze2 : 1;
    Uint32 freeze3 : 1;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_RX_FEAGC_FREEZE_REG;

/*  */
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE0_MASK (0x00000001u)
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE0_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE1_MASK (0x00000002u)
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE1_SHIFT (0x00000001u)
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE2_MASK (0x00000004u)
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE2_SHIFT (0x00000002u)
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE2_RESETVAL (0x00000000u)

/* FEAGC block freeze control.  Set to 1 to suspend feagc control function.  */
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE3_MASK (0x00000008u)
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE3_SHIFT (0x00000003u)
#define CSL_DFE_RX_FEAGC_FREEZE_REG_FREEZE3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_FREEZE_REG_ADDR (0x000006A4u)
#define CSL_DFE_RX_FEAGC_FREEZE_REG_RESETVAL (0x00000000u)

/* FEAGC_FRZ_RESET_PWR */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 frz_reset_pwr3 : 1;
    Uint32 frz_reset_pwr2 : 1;
    Uint32 frz_reset_pwr1 : 1;
    Uint32 frz_reset_pwr0 : 1;
#else 
    Uint32 frz_reset_pwr0 : 1;
    Uint32 frz_reset_pwr1 : 1;
    Uint32 frz_reset_pwr2 : 1;
    Uint32 frz_reset_pwr3 : 1;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG;

/*  */
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR0_MASK (0x00000001u)
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR0_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR1_MASK (0x00000002u)
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR1_SHIFT (0x00000001u)
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR2_MASK (0x00000004u)
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR2_SHIFT (0x00000002u)
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR2_RESETVAL (0x00000000u)

/* Controls behavior of power measurement path on “freeze” signal.  */
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR3_MASK (0x00000008u)
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR3_SHIFT (0x00000003u)
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_FRZ_RESET_PWR3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_ADDR (0x000006A8u)
#define CSL_DFE_RX_FEAGC_FRZ_RESET_PWR_REG_RESETVAL (0x00000000u)

/* FEAGC_MULT_ENABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 mult_out_shift3 : 3;
    Uint32 mult_out_shift2 : 3;
    Uint32 mult_out_shift1 : 3;
    Uint32 mult_out_shift0 : 3;
    Uint32 rsvd0 : 3;
    Uint32 mult_ena : 1;
#else 
    Uint32 mult_ena : 1;
    Uint32 rsvd0 : 3;
    Uint32 mult_out_shift0 : 3;
    Uint32 mult_out_shift1 : 3;
    Uint32 mult_out_shift2 : 3;
    Uint32 mult_out_shift3 : 3;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_RX_FEAGC_MULT_ENABLE_REG;

/* FEAGC block multiplier enable control. */
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_ENA_MASK (0x00000001u)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_ENA_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_ENA_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT0_MASK (0x00000070u)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT0_SHIFT (0x00000004u)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT1_MASK (0x00000380u)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT1_SHIFT (0x00000007u)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT2_MASK (0x00001C00u)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT2_SHIFT (0x0000000Au)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT2_RESETVAL (0x00000000u)

/* FEAGC multiplier output shift value (gain) on a per stram basis.  Sets the post-FEAGC gain amount from 0dB to 42dB in steps of 6dB. */
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT3_MASK (0x0000E000u)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT3_SHIFT (0x0000000Du)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_MULT_OUT_SHIFT3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_ADDR (0x000006ACu)
#define CSL_DFE_RX_FEAGC_MULT_ENABLE_REG_RESETVAL (0x00000000u)

/* FEAGC_TABLE_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 table_mode : 2;
#else 
    Uint32 table_mode : 2;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_RX_FEAGC_TABLE_MODE_REG;

/* FEAGC block dvga/gain table mode */
#define CSL_DFE_RX_FEAGC_TABLE_MODE_REG_TABLE_MODE_MASK (0x00000003u)
#define CSL_DFE_RX_FEAGC_TABLE_MODE_REG_TABLE_MODE_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_TABLE_MODE_REG_TABLE_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_TABLE_MODE_REG_ADDR (0x000006B4u)
#define CSL_DFE_RX_FEAGC_TABLE_MODE_REG_RESETVAL (0x00000000u)

/* FEAGC_DELAY_ADJUST */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 delay_adjust : 11;
#else 
    Uint32 delay_adjust : 11;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_RX_FEAGC_DELAY_ADJUST_REG;

/* FEAGC block delay value per antenna to align internal gain multiplier change with external DVGA gain change. Equals number of signal samples (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate), minus 2. Must be > 0 for normal operation. */
#define CSL_DFE_RX_FEAGC_DELAY_ADJUST_REG_DELAY_ADJUST_MASK (0x000007FFu)
#define CSL_DFE_RX_FEAGC_DELAY_ADJUST_REG_DELAY_ADJUST_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_DELAY_ADJUST_REG_DELAY_ADJUST_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_DELAY_ADJUST_REG_ADDR (0x000006B8u)
#define CSL_DFE_RX_FEAGC_DELAY_ADJUST_REG_RESETVAL (0x00000000u)

/* FEAGC_MULT_VALUE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 17;
    Uint32 mult_value : 15;
#else 
    Uint32 mult_value : 15;
    Uint32 rsvd0 : 17;
#endif 
} CSL_DFE_RX_FEAGC_MULT_VALUE_REG;

/* FEAGC block Value in gain multiplier register per antenna. */
#define CSL_DFE_RX_FEAGC_MULT_VALUE_REG_MULT_VALUE_MASK (0x00007FFFu)
#define CSL_DFE_RX_FEAGC_MULT_VALUE_REG_MULT_VALUE_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_MULT_VALUE_REG_MULT_VALUE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_MULT_VALUE_REG_ADDR (0x000006C8u)
#define CSL_DFE_RX_FEAGC_MULT_VALUE_REG_RESETVAL (0x00000000u)

/* FEAGC_GSG_TIMER_SEQ_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 26;
    Uint32 timer_seq_len : 6;
#else 
    Uint32 timer_seq_len : 6;
    Uint32 rsvd0 : 26;
#endif 
} CSL_DFE_RX_FEAGC_GSG_TIMER_SEQ_LEN_REG;

/* FEAGC block gate signal generator timer sequence lengths.  Length of the timer sequence (per gating signal) between sync pulses. May be 0 to 63.  */
#define CSL_DFE_RX_FEAGC_GSG_TIMER_SEQ_LEN_REG_TIMER_SEQ_LEN_MASK (0x0000003Fu)
#define CSL_DFE_RX_FEAGC_GSG_TIMER_SEQ_LEN_REG_TIMER_SEQ_LEN_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_GSG_TIMER_SEQ_LEN_REG_TIMER_SEQ_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_GSG_TIMER_SEQ_LEN_REG_ADDR (0x000006ECu)
#define CSL_DFE_RX_FEAGC_GSG_TIMER_SEQ_LEN_REG_RESETVAL (0x00000000u)

/* FEAGC_GSG_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 init_toggle_state3 : 1;
    Uint32 init_toggle_state2 : 1;
    Uint32 init_toggle_state1 : 1;
    Uint32 init_toggle_state0 : 1;
    Uint32 rsvd0 : 4;
    Uint32 gating_mode3 : 2;
    Uint32 gating_mode2 : 2;
    Uint32 gating_mode1 : 2;
    Uint32 gating_mode0 : 2;
#else 
    Uint32 gating_mode0 : 2;
    Uint32 gating_mode1 : 2;
    Uint32 gating_mode2 : 2;
    Uint32 gating_mode3 : 2;
    Uint32 rsvd0 : 4;
    Uint32 init_toggle_state0 : 1;
    Uint32 init_toggle_state1 : 1;
    Uint32 init_toggle_state2 : 1;
    Uint32 init_toggle_state3 : 1;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_RX_FEAGC_GSG_CONFIG_REG;

/*  */
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE0_MASK (0x00000003u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE0_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE1_MASK (0x0000000Cu)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE1_SHIFT (0x00000002u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE2_MASK (0x00000030u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE2_SHIFT (0x00000004u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE2_RESETVAL (0x00000000u)

/* FEAGC block gate signal generator gating mode. */
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE3_MASK (0x000000C0u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE3_SHIFT (0x00000006u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_GATING_MODE3_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE0_MASK (0x00001000u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE0_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE1_MASK (0x00002000u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE1_SHIFT (0x0000000Du)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE2_MASK (0x00004000u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE2_SHIFT (0x0000000Eu)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE2_RESETVAL (0x00000000u)

/* FEAGC block gate signal generator initial toggle state value. */
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE3_MASK (0x00008000u)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE3_SHIFT (0x0000000Fu)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_INIT_TOGGLE_STATE3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_ADDR (0x000006FCu)
#define CSL_DFE_RX_FEAGC_GSG_CONFIG_REG_RESETVAL (0x00000000u)

/* DC_GLOBAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 dc_frz_rst_int3 : 1;
    Uint32 dc_frz_rst_int2 : 1;
    Uint32 dc_frz_rst_int1 : 1;
    Uint32 dc_frz_rst_int0 : 1;
    Uint32 dc_freeze3 : 1;
    Uint32 dc_freeze2 : 1;
    Uint32 dc_freeze1 : 1;
    Uint32 dc_freeze0 : 1;
    Uint32 rsvd0 : 8;
#else 
    Uint32 rsvd0 : 8;
    Uint32 dc_freeze0 : 1;
    Uint32 dc_freeze1 : 1;
    Uint32 dc_freeze2 : 1;
    Uint32 dc_freeze3 : 1;
    Uint32 dc_frz_rst_int0 : 1;
    Uint32 dc_frz_rst_int1 : 1;
    Uint32 dc_frz_rst_int2 : 1;
    Uint32 dc_frz_rst_int3 : 1;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_RX_DC_GLOBAL_REG;

/*  */
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE0_MASK (0x00000100u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE0_SHIFT (0x00000008u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE1_MASK (0x00000200u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE1_SHIFT (0x00000009u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE2_MASK (0x00000400u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE2_SHIFT (0x0000000Au)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE2_RESETVAL (0x00000000u)

/* DC Canceller freeze control.  Set to 1 to suspend dc cancellation function. */
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE3_MASK (0x00000800u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE3_SHIFT (0x0000000Bu)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FREEZE3_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT0_MASK (0x00001000u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT0_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT1_MASK (0x00002000u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT1_SHIFT (0x0000000Du)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT2_MASK (0x00004000u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT2_SHIFT (0x0000000Eu)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT2_RESETVAL (0x00000000u)

/* Controls behavior of dc integration accumulator s(k) (power measurement) on “freeze” signal.  */
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT3_MASK (0x00008000u)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT3_SHIFT (0x0000000Fu)
#define CSL_DFE_RX_DC_GLOBAL_REG_DC_FRZ_RST_INT3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_GLOBAL_REG_ADDR (0x00000700u)
#define CSL_DFE_RX_DC_GLOBAL_REG_RESETVAL (0x00000000u)

/* DC_INIT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dc_init : 16;
#else 
    Uint32 dc_init : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_DC_INIT_REG;

/* Initial values for the 8 dc correction accumulator (d(k)) registers (2 per antenna) per dc cancellation block.  */
#define CSL_DFE_RX_DC_INIT_REG_DC_INIT_MASK (0x0000FFFFu)
#define CSL_DFE_RX_DC_INIT_REG_DC_INIT_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_INIT_REG_DC_INIT_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_INIT_REG_ADDR (0x00000704u)
#define CSL_DFE_RX_DC_INIT_REG_RESETVAL (0x00000000u)

/* DC_INTERVAL_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dc_interval_15_0 : 16;
#else 
    Uint32 dc_interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_DC_INTERVAL_W0_REG;

/* Integration interval value (0 to 2^24 – 1). Number of signal samples (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate) between dc_update pulses. Must be > 0 for normal operation. */
#define CSL_DFE_RX_DC_INTERVAL_W0_REG_DC_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_DC_INTERVAL_W0_REG_DC_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_INTERVAL_W0_REG_DC_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_INTERVAL_W0_REG_ADDR (0x00000724u)
#define CSL_DFE_RX_DC_INTERVAL_W0_REG_RESETVAL (0x00000000u)

/* DC_INTERVAL_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 dc_interval_23_16 : 8;
#else 
    Uint32 dc_interval_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_DC_INTERVAL_W1_REG;

/*  */
#define CSL_DFE_RX_DC_INTERVAL_W1_REG_DC_INTERVAL_23_16_MASK (0x000000FFu)
#define CSL_DFE_RX_DC_INTERVAL_W1_REG_DC_INTERVAL_23_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_INTERVAL_W1_REG_DC_INTERVAL_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_INTERVAL_W1_REG_ADDR (0x00000728u)
#define CSL_DFE_RX_DC_INTERVAL_W1_REG_RESETVAL (0x00000000u)

/* DC_UPDATE_DELAY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dc_update_delay : 16;
#else 
    Uint32 dc_update_delay : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_DC_UPDATE_DELAY_REG;

/* DC Canceller delay value from sync to first dc_update pulse (0 to 2^16 -1). Number of signal samples (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate). */
#define CSL_DFE_RX_DC_UPDATE_DELAY_REG_DC_UPDATE_DELAY_MASK (0x0000FFFFu)
#define CSL_DFE_RX_DC_UPDATE_DELAY_REG_DC_UPDATE_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_UPDATE_DELAY_REG_DC_UPDATE_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_UPDATE_DELAY_REG_ADDR (0x0000072Cu)
#define CSL_DFE_RX_DC_UPDATE_DELAY_REG_RESETVAL (0x00000000u)

/* DC_SHIFT_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 dc_mode : 1;
    Uint32 rsvd0 : 10;
    Uint32 dc_shift : 5;
#else 
    Uint32 dc_shift : 5;
    Uint32 rsvd0 : 10;
    Uint32 dc_mode : 1;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_RX_DC_SHIFT_MODE_REG;

/* DC Canceller shift control. Right shift value to apply to the integrated dc signal. Range 0 to 31. Typically set to log2(dc_interval) + 3 for fast tracking and log2(dc_interval) + 7 for slow tracking. */
#define CSL_DFE_RX_DC_SHIFT_MODE_REG_DC_SHIFT_MASK (0x0000001Fu)
#define CSL_DFE_RX_DC_SHIFT_MODE_REG_DC_SHIFT_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_SHIFT_MODE_REG_DC_SHIFT_RESETVAL (0x00000000u)

/* DC Canceller mode control. */
#define CSL_DFE_RX_DC_SHIFT_MODE_REG_DC_MODE_MASK (0x00008000u)
#define CSL_DFE_RX_DC_SHIFT_MODE_REG_DC_MODE_SHIFT (0x0000000Fu)
#define CSL_DFE_RX_DC_SHIFT_MODE_REG_DC_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_SHIFT_MODE_REG_ADDR (0x0000073Cu)
#define CSL_DFE_RX_DC_SHIFT_MODE_REG_RESETVAL (0x00000000u)

/* SIGGEN_I_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_i_frame_len : 12;
    Uint32 siggen_i_seed : 1;
    Uint32 siggen_i_ramp : 1;
    Uint32 siggen_i_frame : 1;
    Uint32 siggen_i_enable : 1;
#else 
    Uint32 siggen_i_enable : 1;
    Uint32 siggen_i_frame : 1;
    Uint32 siggen_i_ramp : 1;
    Uint32 siggen_i_seed : 1;
    Uint32 siggen_i_frame_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_I_MODE_REG;

/* I bus input signal generator enable.  Broadcast to both the inline and cross I inputs. */
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_ENABLE_MASK (0x00000001u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_ENABLE_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_ENABLE_RESETVAL (0x00000000u)

/* I bus input signal generator frame enable. */
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_MASK (0x00000002u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_RESETVAL (0x00000000u)

/* I bus input signal generator ramp enable. */
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_RAMP_MASK (0x00000004u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_RAMP_SHIFT (0x00000002u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_RAMP_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_SEED_MASK (0x00000008u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_SEED_SHIFT (0x00000003u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_SEED_RESETVAL (0x00000000u)

/* I bus input signal generator frame length in clocks when sig_gen_I_frame is enabled. */
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_LEN_SHIFT (0x00000004u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_SIGGEN_I_FRAME_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_I_MODE_REG_ADDR (0x00000740u)
#define CSL_DFE_RX_SIGGEN_I_MODE_REG_RESETVAL (0x00000000u)

/* SIGGEN_I_RAMP_START_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_i_ramp_start_15_0 : 16;
#else 
    Uint32 siggen_i_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_I_RAMP_START_W0_REG;

/* I bus input ramp start value.  If ramp mode is enabled, the ramp generator starts at this value. */
#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W0_REG_SIGGEN_I_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W0_REG_SIGGEN_I_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W0_REG_SIGGEN_I_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W0_REG_ADDR (0x00000744u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W0_REG_RESETVAL (0x00000000u)

/* SIGGEN_I_RAMP_START_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_i_ramp_start_31_16 : 16;
#else 
    Uint32 siggen_i_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_I_RAMP_START_W1_REG;

/*  */
#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W1_REG_SIGGEN_I_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W1_REG_SIGGEN_I_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W1_REG_SIGGEN_I_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W1_REG_ADDR (0x00000748u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_START_W1_REG_RESETVAL (0x00000000u)

/* SIGGEN_I_RAMP_STOP_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_i_ramp_stop_15_0 : 16;
#else 
    Uint32 siggen_i_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W0_REG;

/* I bus input ramp stop value.  If ramp mode is enabled, the ramp generator rolls over to the ramp start value when this value is hit.   */
#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W0_REG_SIGGEN_I_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W0_REG_SIGGEN_I_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W0_REG_SIGGEN_I_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W0_REG_ADDR (0x0000074Cu)
#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W0_REG_RESETVAL (0x00000000u)

/* SIGGEN_I_RAMP_STOP_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_i_ramp_stop_31_16 : 16;
#else 
    Uint32 siggen_i_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W1_REG;

/*  */
#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W1_REG_SIGGEN_I_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W1_REG_SIGGEN_I_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W1_REG_SIGGEN_I_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W1_REG_ADDR (0x00000750u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_STOP_W1_REG_RESETVAL (0x00000000u)

/* SIGGEN_I_RAMP_INC_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_i_ramp_inc_15_0 : 16;
#else 
    Uint32 siggen_i_ramp_inc_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_I_RAMP_INC_W0_REG;

/* I bus input ramp increment value.  If ramp mode is enabled, the ramp generator increments by this value every clock. */
#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W0_REG_SIGGEN_I_RAMP_INC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W0_REG_SIGGEN_I_RAMP_INC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W0_REG_SIGGEN_I_RAMP_INC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W0_REG_ADDR (0x00000754u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W0_REG_RESETVAL (0x00000000u)

/* SIGGEN_I_RAMP_INC_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_i_ramp_inc_31_16 : 16;
#else 
    Uint32 siggen_i_ramp_inc_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_I_RAMP_INC_W1_REG;

/*  */
#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W1_REG_SIGGEN_I_RAMP_INC_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W1_REG_SIGGEN_I_RAMP_INC_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W1_REG_SIGGEN_I_RAMP_INC_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W1_REG_ADDR (0x00000758u)
#define CSL_DFE_RX_SIGGEN_I_RAMP_INC_W1_REG_RESETVAL (0x00000000u)

/* SIGGEN_I_PULSE_WIDTH */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_i_pulse_width : 16;
#else 
    Uint32 siggen_i_pulse_width : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_I_PULSE_WIDTH_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_RX_SIGGEN_I_PULSE_WIDTH_REG_SIGGEN_I_PULSE_WIDTH_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_I_PULSE_WIDTH_REG_SIGGEN_I_PULSE_WIDTH_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_I_PULSE_WIDTH_REG_SIGGEN_I_PULSE_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_I_PULSE_WIDTH_REG_ADDR (0x0000075Cu)
#define CSL_DFE_RX_SIGGEN_I_PULSE_WIDTH_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_frame_len : 12;
    Uint32 siggen_q_seed : 1;
    Uint32 siggen_q_ramp : 1;
    Uint32 siggen_q_frame : 1;
    Uint32 siggen_q_enable : 1;
#else 
    Uint32 siggen_q_enable : 1;
    Uint32 siggen_q_frame : 1;
    Uint32 siggen_q_ramp : 1;
    Uint32 siggen_q_seed : 1;
    Uint32 siggen_q_frame_len : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_Q_MODE_REG;

/* Q bus input signal generator enable.  Broadcast to both the inline and cross Q inputs. */
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_ENABLE_MASK (0x00000001u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_ENABLE_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_ENABLE_RESETVAL (0x00000000u)

/* Q bus input signal generator frame enable. */
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_MASK (0x00000002u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_RESETVAL (0x00000000u)

/* Q bus input signal generator ramp enable. */
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_RAMP_MASK (0x00000004u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_RAMP_SHIFT (0x00000002u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_RAMP_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_SEED_MASK (0x00000008u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_SEED_SHIFT (0x00000003u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_SEED_RESETVAL (0x00000000u)

/* Q bus input signal generator frame length in clocks when sig_gen_Q_frame is enabled. */
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_LEN_SHIFT (0x00000004u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_SIGGEN_Q_FRAME_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_ADDR (0x00000764u)
#define CSL_DFE_RX_SIGGEN_Q_MODE_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_RAMP_START_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_ramp_start_15_0 : 16;
#else 
    Uint32 siggen_q_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_Q_RAMP_START_W0_REG;

/* Q bus input ramp start value.  If ramp mode is enabled, the ramp generator starts at this value. */
#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W0_REG_SIGGEN_Q_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W0_REG_SIGGEN_Q_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W0_REG_SIGGEN_Q_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W0_REG_ADDR (0x00000768u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W0_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_RAMP_START_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_ramp_start_31_16 : 16;
#else 
    Uint32 siggen_q_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_Q_RAMP_START_W1_REG;

/*  */
#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W1_REG_SIGGEN_Q_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W1_REG_SIGGEN_Q_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W1_REG_SIGGEN_Q_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W1_REG_ADDR (0x0000076Cu)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_START_W1_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_RAMP_STOP_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_ramp_stop_15_0 : 16;
#else 
    Uint32 siggen_q_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W0_REG;

/* Q bus input ramp stop value.  If ramp mode is enabled, the ramp generator rolls over to the ramp start value when this value is hit.   */
#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W0_REG_SIGGEN_Q_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W0_REG_SIGGEN_Q_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W0_REG_SIGGEN_Q_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W0_REG_ADDR (0x00000770u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W0_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_RAMP_STOP_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_ramp_stop_31_16 : 16;
#else 
    Uint32 siggen_q_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W1_REG;

/*  */
#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W1_REG_SIGGEN_Q_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W1_REG_SIGGEN_Q_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W1_REG_SIGGEN_Q_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W1_REG_ADDR (0x00000774u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_STOP_W1_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_RAMP_INC_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_ramp_inc_15_0 : 16;
#else 
    Uint32 siggen_q_ramp_inc_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W0_REG;

/* Q bus input ramp increment value.  If ramp mode is enabled, the ramp generator increments by this value every clock. */
#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W0_REG_SIGGEN_Q_RAMP_INC_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W0_REG_SIGGEN_Q_RAMP_INC_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W0_REG_SIGGEN_Q_RAMP_INC_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W0_REG_ADDR (0x00000778u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W0_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_RAMP_INC_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_ramp_inc_31_16 : 16;
#else 
    Uint32 siggen_q_ramp_inc_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W1_REG;

/*  */
#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W1_REG_SIGGEN_Q_RAMP_INC_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W1_REG_SIGGEN_Q_RAMP_INC_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W1_REG_SIGGEN_Q_RAMP_INC_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W1_REG_ADDR (0x0000077Cu)
#define CSL_DFE_RX_SIGGEN_Q_RAMP_INC_W1_REG_RESETVAL (0x00000000u)

/* SIGGEN_Q_PULSE_WIDTH */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 siggen_q_pulse_width : 16;
#else 
    Uint32 siggen_q_pulse_width : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_SIGGEN_Q_PULSE_WIDTH_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_RX_SIGGEN_Q_PULSE_WIDTH_REG_SIGGEN_Q_PULSE_WIDTH_MASK (0x0000FFFFu)
#define CSL_DFE_RX_SIGGEN_Q_PULSE_WIDTH_REG_SIGGEN_Q_PULSE_WIDTH_SHIFT (0x00000000u)
#define CSL_DFE_RX_SIGGEN_Q_PULSE_WIDTH_REG_SIGGEN_Q_PULSE_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_RX_SIGGEN_Q_PULSE_WIDTH_REG_ADDR (0x00000780u)
#define CSL_DFE_RX_SIGGEN_Q_PULSE_WIDTH_REG_RESETVAL (0x00000000u)

/* CHKSUM_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 latency_mode_stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 chksum_mode : 1;
#else 
    Uint32 chksum_mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 latency_mode_stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_RX_CHKSUM_MODE_REG;

/* Checksum mode control: 1 = return latency, 0 = return checksum */
#define CSL_DFE_RX_CHKSUM_MODE_REG_CHKSUM_MODE_MASK (0x00000001u)
#define CSL_DFE_RX_CHKSUM_MODE_REG_CHKSUM_MODE_SHIFT (0x00000000u)
#define CSL_DFE_RX_CHKSUM_MODE_REG_CHKSUM_MODE_RESETVAL (0x00000000u)

/* Latency mode number of clocks that data must remain stable for after pulse */
#define CSL_DFE_RX_CHKSUM_MODE_REG_LATENCY_MODE_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_RX_CHKSUM_MODE_REG_LATENCY_MODE_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_RX_CHKSUM_MODE_REG_LATENCY_MODE_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_RX_CHKSUM_MODE_REG_ADDR (0x00000788u)
#define CSL_DFE_RX_CHKSUM_MODE_REG_RESETVAL (0x00000000u)

/* CHKSUM_SIG_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 latency_mode_signal_len : 16;
#else 
    Uint32 latency_mode_signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_CHKSUM_SIG_LEN_REG;

/* Latency mode width of data pulse from signal generator */
#define CSL_DFE_RX_CHKSUM_SIG_LEN_REG_LATENCY_MODE_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_RX_CHKSUM_SIG_LEN_REG_LATENCY_MODE_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_RX_CHKSUM_SIG_LEN_REG_LATENCY_MODE_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_RX_CHKSUM_SIG_LEN_REG_ADDR (0x0000078Cu)
#define CSL_DFE_RX_CHKSUM_SIG_LEN_REG_RESETVAL (0x00000000u)

/* CHKSUM_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 latency_mode_chan_sel : 12;
#else 
    Uint32 latency_mode_chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_RX_CHKSUM_CHAN_SEL_REG;

/* Latency mode channel select (specified by clocks after frame signal) */
#define CSL_DFE_RX_CHKSUM_CHAN_SEL_REG_LATENCY_MODE_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_RX_CHKSUM_CHAN_SEL_REG_LATENCY_MODE_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_RX_CHKSUM_CHAN_SEL_REG_LATENCY_MODE_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_RX_CHKSUM_CHAN_SEL_REG_ADDR (0x00000790u)
#define CSL_DFE_RX_CHKSUM_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CHKSUM_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 chksum_15_0 : 16;
#else 
    Uint32 chksum_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_CHKSUM_W0_REG;

/* Lower 16 bits of rx subchip output checksum signature analyzer result. */
#define CSL_DFE_RX_CHKSUM_W0_REG_CHKSUM_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_CHKSUM_W0_REG_CHKSUM_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_CHKSUM_W0_REG_CHKSUM_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_CHKSUM_W0_REG_ADDR (0x00000794u)
#define CSL_DFE_RX_CHKSUM_W0_REG_RESETVAL (0x00000000u)

/* CHKSUM_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 chksum_31_16 : 16;
#else 
    Uint32 chksum_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_CHKSUM_W1_REG;

/* Upper 16 bits of rx subchip output checksum signature analyzer result. */
#define CSL_DFE_RX_CHKSUM_W1_REG_CHKSUM_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_CHKSUM_W1_REG_CHKSUM_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_CHKSUM_W1_REG_CHKSUM_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_CHKSUM_W1_REG_ADDR (0x00000798u)
#define CSL_DFE_RX_CHKSUM_W1_REG_RESETVAL (0x00000000u)

/* DC_GSG_TIMER_SEQ_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 26;
    Uint32 dc_timer_seq_len : 6;
#else 
    Uint32 dc_timer_seq_len : 6;
    Uint32 rsvd0 : 26;
#endif 
} CSL_DFE_RX_DC_GSG_TIMER_SEQ_LEN_REG;

/* DC Canceller block gate signal generator timer sequence lengths.  Length of the timer sequence (per gating signal) between sync pulses. May be 0 to 63. */
#define CSL_DFE_RX_DC_GSG_TIMER_SEQ_LEN_REG_DC_TIMER_SEQ_LEN_MASK (0x0000003Fu)
#define CSL_DFE_RX_DC_GSG_TIMER_SEQ_LEN_REG_DC_TIMER_SEQ_LEN_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_GSG_TIMER_SEQ_LEN_REG_DC_TIMER_SEQ_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_GSG_TIMER_SEQ_LEN_REG_ADDR (0x000007ECu)
#define CSL_DFE_RX_DC_GSG_TIMER_SEQ_LEN_REG_RESETVAL (0x00000000u)

/* DC_GSG_CONFIG */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 dc_init_toggle_state3 : 1;
    Uint32 dc_init_toggle_state2 : 1;
    Uint32 dc_init_toggle_state1 : 1;
    Uint32 dc_init_toggle_state0 : 1;
    Uint32 rsvd0 : 4;
    Uint32 dc_gating_mode3 : 2;
    Uint32 dc_gating_mode2 : 2;
    Uint32 dc_gating_mode1 : 2;
    Uint32 dc_gating_mode0 : 2;
#else 
    Uint32 dc_gating_mode0 : 2;
    Uint32 dc_gating_mode1 : 2;
    Uint32 dc_gating_mode2 : 2;
    Uint32 dc_gating_mode3 : 2;
    Uint32 rsvd0 : 4;
    Uint32 dc_init_toggle_state0 : 1;
    Uint32 dc_init_toggle_state1 : 1;
    Uint32 dc_init_toggle_state2 : 1;
    Uint32 dc_init_toggle_state3 : 1;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_RX_DC_GSG_CONFIG_REG;

/*  */
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE0_MASK (0x00000003u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE0_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE1_MASK (0x0000000Cu)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE1_SHIFT (0x00000002u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE2_MASK (0x00000030u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE2_SHIFT (0x00000004u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE2_RESETVAL (0x00000000u)

/* DC Canceller block gate signal generator gating mode. */
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE3_MASK (0x000000C0u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE3_SHIFT (0x00000006u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_GATING_MODE3_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE0_MASK (0x00001000u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE0_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE1_MASK (0x00002000u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE1_SHIFT (0x0000000Du)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE2_MASK (0x00004000u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE2_SHIFT (0x0000000Eu)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE2_RESETVAL (0x00000000u)

/* DC Canceller block gate signal generator initial toggle state value. */
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE3_MASK (0x00008000u)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE3_SHIFT (0x0000000Fu)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_DC_INIT_TOGGLE_STATE3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_GSG_CONFIG_REG_ADDR (0x000007FCu)
#define CSL_DFE_RX_DC_GSG_CONFIG_REG_RESETVAL (0x00000000u)

/* PM_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 read_mode : 1;
    Uint32 one_shot_mode3 : 1;
    Uint32 one_shot_mode2 : 1;
    Uint32 one_shot_mode1 : 1;
    Uint32 one_shot_mode0 : 1;
    Uint32 meter_mode3 : 2;
    Uint32 meter_mode2 : 2;
    Uint32 meter_mode1 : 2;
    Uint32 meter_mode0 : 2;
#else 
    Uint32 meter_mode0 : 2;
    Uint32 meter_mode1 : 2;
    Uint32 meter_mode2 : 2;
    Uint32 meter_mode3 : 2;
    Uint32 one_shot_mode0 : 1;
    Uint32 one_shot_mode1 : 1;
    Uint32 one_shot_mode2 : 1;
    Uint32 one_shot_mode3 : 1;
    Uint32 read_mode : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_RX_PM_MODE_REG;

/*  */
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE0_MASK (0x00000003u)
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE1_MASK (0x0000000Cu)
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE1_SHIFT (0x00000002u)
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE2_MASK (0x00000030u)
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE2_SHIFT (0x00000004u)
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE2_RESETVAL (0x00000000u)

/* Power meter operational mode.   */
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE3_MASK (0x000000C0u)
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE3_SHIFT (0x00000006u)
#define CSL_DFE_RX_PM_MODE_REG_METER_MODE3_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE0_MASK (0x00000100u)
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE0_SHIFT (0x00000008u)
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE1_MASK (0x00000200u)
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE1_SHIFT (0x00000009u)
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE2_MASK (0x00000400u)
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE2_SHIFT (0x0000000Au)
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE2_RESETVAL (0x00000000u)

/* Power meter one shot mode. */
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE3_MASK (0x00000800u)
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE3_SHIFT (0x0000000Bu)
#define CSL_DFE_RX_PM_MODE_REG_ONE_SHOT_MODE3_RESETVAL (0x00000000u)

/* Power meter mpu read mode. Determines the method of reading the power meter integrated power, peak magnitude squared and threshold histogram results. */
#define CSL_DFE_RX_PM_MODE_REG_READ_MODE_MASK (0x00001000u)
#define CSL_DFE_RX_PM_MODE_REG_READ_MODE_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_PM_MODE_REG_READ_MODE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_MODE_REG_ADDR (0x00000A00u)
#define CSL_DFE_RX_PM_MODE_REG_RESETVAL (0x00000000u)

/* PM_HANDSHAKE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 missed3 : 1;
    Uint32 done3 : 1;
    Uint32 read_ack3 : 1;
    Uint32 read_req3 : 1;
    Uint32 missed2 : 1;
    Uint32 done2 : 1;
    Uint32 read_ack2 : 1;
    Uint32 read_req2 : 1;
    Uint32 missed1 : 1;
    Uint32 done1 : 1;
    Uint32 read_ack1 : 1;
    Uint32 read_req1 : 1;
    Uint32 missed0 : 1;
    Uint32 done0 : 1;
    Uint32 read_ack0 : 1;
    Uint32 read_req0 : 1;
#else 
    Uint32 read_req0 : 1;
    Uint32 read_ack0 : 1;
    Uint32 done0 : 1;
    Uint32 missed0 : 1;
    Uint32 read_req1 : 1;
    Uint32 read_ack1 : 1;
    Uint32 done1 : 1;
    Uint32 missed1 : 1;
    Uint32 read_req2 : 1;
    Uint32 read_ack2 : 1;
    Uint32 done2 : 1;
    Uint32 missed2 : 1;
    Uint32 read_req3 : 1;
    Uint32 read_ack3 : 1;
    Uint32 done3 : 1;
    Uint32 missed3 : 1;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_HANDSHAKE_REG;

/* Power meter antenna 0 read request bit. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ0_MASK (0x00000001u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ0_RESETVAL (0x00000000u)

/* Power meter antenna 0 read acknowledgment flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK0_MASK (0x00000002u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK0_SHIFT (0x00000001u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK0_RESETVAL (0x00000000u)

/* Power meter antenna 0 done reading flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE0_MASK (0x00000004u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE0_SHIFT (0x00000002u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE0_RESETVAL (0x00000000u)

/* Power meter antenna 0 missed flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED0_MASK (0x00000008u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED0_SHIFT (0x00000003u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED0_RESETVAL (0x00000000u)

/* Power meter antenna 1 read request bit. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ1_MASK (0x00000010u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ1_SHIFT (0x00000004u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ1_RESETVAL (0x00000000u)

/* Power meter antenna 1 read acknowledgment flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK1_MASK (0x00000020u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK1_SHIFT (0x00000005u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK1_RESETVAL (0x00000000u)

/* Power meter antenna 1 done reading flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE1_MASK (0x00000040u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE1_SHIFT (0x00000006u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE1_RESETVAL (0x00000000u)

/* Power meter antenna 1 missed flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED1_MASK (0x00000080u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED1_SHIFT (0x00000007u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED1_RESETVAL (0x00000000u)

/* Power meter antenna 2 read request bit. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ2_MASK (0x00000100u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ2_SHIFT (0x00000008u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ2_RESETVAL (0x00000000u)

/* Power meter antenna 2 read acknowledgment flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK2_MASK (0x00000200u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK2_SHIFT (0x00000009u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK2_RESETVAL (0x00000000u)

/* Power meter antenna 2 done reading flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE2_MASK (0x00000400u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE2_SHIFT (0x0000000Au)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE2_RESETVAL (0x00000000u)

/* Power meter antenna 2 missed flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED2_MASK (0x00000800u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED2_SHIFT (0x0000000Bu)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED2_RESETVAL (0x00000000u)

/* Power meter antenna 3 read request bit.  When in software handshake read mode, set high by the user to request permission to read the latest power measurement results.  Set low by the user to enable power measurement results to be updated to the mpu read registers. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ3_MASK (0x00001000u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ3_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_REQ3_RESETVAL (0x00000000u)

/* Power meter antenna 3 read acknowledgment flag.  When in software handshake read mode, set high by the GC5498 to acknowledge the users read request and indicate that the current set of power measurement results are complete and will not be updated until the user clears the read request bit. Set low by the GC5498 to indicate that power meter updates are proceeding and being written to the mpu read registers. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK3_MASK (0x00002000u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK3_SHIFT (0x0000000Du)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_READ_ACK3_RESETVAL (0x00000000u)

/* Power meter antenna 3 done reading flag.  When in hardware interrupt read mode, this flag is used by the user to indicate to the GC5498 that the host is done reading the results.  When the HW finishes a measurement cycle and either sets or clears the missed flag, it will also clear the done flag. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE3_MASK (0x00004000u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE3_SHIFT (0x0000000Eu)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_DONE3_RESETVAL (0x00000000u)

/* Power meter antenna 3 missed flag.  When in hardware interrupt read mode, this flag indicates that the previous set of measurement result was not read (as indicated by setting the done flag) before the subsequent measurement cycle completed and the mpu read registers were updated with the new result. */
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED3_MASK (0x00008000u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED3_SHIFT (0x0000000Fu)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_MISSED3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_HANDSHAKE_REG_ADDR (0x00000A04u)
#define CSL_DFE_RX_PM_HANDSHAKE_REG_RESETVAL (0x00000000u)

/* PM_HIST_ONE_THRESH_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 hist_one_thresh_15_0 : 16;
#else 
    Uint32 hist_one_thresh_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_HIST_ONE_THRESH_W0_REG;

/* Power meter histogram one threshold (unsigned number) lower 16 bits */
#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W0_REG_HIST_ONE_THRESH_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W0_REG_HIST_ONE_THRESH_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W0_REG_HIST_ONE_THRESH_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W0_REG_ADDR (0x00000A08u)
#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W0_REG_RESETVAL (0x00000000u)

/* PM_HIST_ONE_THRESH_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 hist_one_thresh_31_16 : 16;
#else 
    Uint32 hist_one_thresh_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_HIST_ONE_THRESH_W1_REG;

/* Power meter histogram one threshold (unsigned number) upper 16 bits  */
#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W1_REG_HIST_ONE_THRESH_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W1_REG_HIST_ONE_THRESH_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W1_REG_HIST_ONE_THRESH_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W1_REG_ADDR (0x00000A0Cu)
#define CSL_DFE_RX_PM_HIST_ONE_THRESH_W1_REG_RESETVAL (0x00000000u)

/* PM_HIST_TWO_THRESH_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 hist_two_thresh_15_0 : 16;
#else 
    Uint32 hist_two_thresh_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_HIST_TWO_THRESH_W0_REG;

/* Power meter histogram two threshold (unsigned number) lower 16 bits */
#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W0_REG_HIST_TWO_THRESH_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W0_REG_HIST_TWO_THRESH_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W0_REG_HIST_TWO_THRESH_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W0_REG_ADDR (0x00000A10u)
#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W0_REG_RESETVAL (0x00000000u)

/* PM_HIST_TWO_THRESH_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 hist_two_thresh_31_16 : 16;
#else 
    Uint32 hist_two_thresh_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_HIST_TWO_THRESH_W1_REG;

/* Power meter histogram two threshold (unsigned number) upper 16 bits */
#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W1_REG_HIST_TWO_THRESH_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W1_REG_HIST_TWO_THRESH_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W1_REG_HIST_TWO_THRESH_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W1_REG_ADDR (0x00000A14u)
#define CSL_DFE_RX_PM_HIST_TWO_THRESH_W1_REG_RESETVAL (0x00000000u)

/* PM_SYNC_DELAY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 sync_delay : 16;
#else 
    Uint32 sync_delay : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_SYNC_DELAY_REG;

/* Power meter sync delay counter */
#define CSL_DFE_RX_PM_SYNC_DELAY_REG_SYNC_DELAY_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_SYNC_DELAY_REG_SYNC_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_SYNC_DELAY_REG_SYNC_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_SYNC_DELAY_REG_ADDR (0x00000A18u)
#define CSL_DFE_RX_PM_SYNC_DELAY_REG_RESETVAL (0x00000000u)

/* PM_NSAMP_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 nsamp_15_0 : 16;
#else 
    Uint32 nsamp_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_NSAMP_W0_REG;

/* Power meter # of samples to integrate lower 16 bits (0 = 0 samples) */
#define CSL_DFE_RX_PM_NSAMP_W0_REG_NSAMP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_NSAMP_W0_REG_NSAMP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_NSAMP_W0_REG_NSAMP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_NSAMP_W0_REG_ADDR (0x00000A40u)
#define CSL_DFE_RX_PM_NSAMP_W0_REG_RESETVAL (0x00000000u)

/* PM_NSAMP_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 nsamp_31_16 : 16;
#else 
    Uint32 nsamp_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_NSAMP_W1_REG;

/* Power meter # of samples to integrate upper 16 bits  */
#define CSL_DFE_RX_PM_NSAMP_W1_REG_NSAMP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_NSAMP_W1_REG_NSAMP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_NSAMP_W1_REG_NSAMP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_NSAMP_W1_REG_ADDR (0x00000A44u)
#define CSL_DFE_RX_PM_NSAMP_W1_REG_RESETVAL (0x00000000u)

/* PM_INTERVAL_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_15_0 : 16;
#else 
    Uint32 interval_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_INTERVAL_W0_REG;

/* Power meter interval counter lower 16 bits (0 = 0 samples) */
#define CSL_DFE_RX_PM_INTERVAL_W0_REG_INTERVAL_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_INTERVAL_W0_REG_INTERVAL_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_INTERVAL_W0_REG_INTERVAL_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_INTERVAL_W0_REG_ADDR (0x00000A60u)
#define CSL_DFE_RX_PM_INTERVAL_W0_REG_RESETVAL (0x00000000u)

/* PM_INTERVAL_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 interval_31_16 : 16;
#else 
    Uint32 interval_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_INTERVAL_W1_REG;

/* Power meter interval counter upper 16 bits  */
#define CSL_DFE_RX_PM_INTERVAL_W1_REG_INTERVAL_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_INTERVAL_W1_REG_INTERVAL_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_INTERVAL_W1_REG_INTERVAL_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_INTERVAL_W1_REG_ADDR (0x00000A64u)
#define CSL_DFE_RX_PM_INTERVAL_W1_REG_RESETVAL (0x00000000u)

/* PM_POWER_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 power_15_0 : 16;
#else 
    Uint32 power_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_POWER_W0_REG;

/* Power meter power bit [15:0] */
#define CSL_DFE_RX_PM_POWER_W0_REG_POWER_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_POWER_W0_REG_POWER_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_POWER_W0_REG_POWER_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_POWER_W0_REG_ADDR (0x00000A80u)
#define CSL_DFE_RX_PM_POWER_W0_REG_RESETVAL (0x00000000u)

/* PM_POWER_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 power_31_16 : 16;
#else 
    Uint32 power_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_POWER_W1_REG;

/* Power meter power bit [31:16] */
#define CSL_DFE_RX_PM_POWER_W1_REG_POWER_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_POWER_W1_REG_POWER_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_POWER_W1_REG_POWER_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_POWER_W1_REG_ADDR (0x00000A84u)
#define CSL_DFE_RX_PM_POWER_W1_REG_RESETVAL (0x00000000u)

/* PM_POWER_W2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 power_47_32 : 16;
#else 
    Uint32 power_47_32 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_POWER_W2_REG;

/* Power meter power bit [47:32] */
#define CSL_DFE_RX_PM_POWER_W2_REG_POWER_47_32_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_POWER_W2_REG_POWER_47_32_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_POWER_W2_REG_POWER_47_32_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_POWER_W2_REG_ADDR (0x00000A88u)
#define CSL_DFE_RX_PM_POWER_W2_REG_RESETVAL (0x00000000u)

/* PM_POWER_W3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 power_unstable : 1;
    Uint32 power_cnt : 3;
    Uint32 power_59_48 : 12;
#else 
    Uint32 power_59_48 : 12;
    Uint32 power_cnt : 3;
    Uint32 power_unstable : 1;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_POWER_W3_REG;

/* Power meter power bit [59:48] */
#define CSL_DFE_RX_PM_POWER_W3_REG_POWER_59_48_MASK (0x00000FFFu)
#define CSL_DFE_RX_PM_POWER_W3_REG_POWER_59_48_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_POWER_W3_REG_POWER_59_48_RESETVAL (0x00000000u)

/* Power meter power meter value reading counter; 3-bits; gets incremented whenever the overall power result is updated. For a valid power result reading, must read this register before and after reading the 4 power result registers. If the value is unchanged between the two reads, then the power result is valid. */
#define CSL_DFE_RX_PM_POWER_W3_REG_POWER_CNT_MASK (0x00007000u)
#define CSL_DFE_RX_PM_POWER_W3_REG_POWER_CNT_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_PM_POWER_W3_REG_POWER_CNT_RESETVAL (0x00000000u)

/* if = 1, indicates power meter power reading is invalid; the entire 4 register power value is only stable for a read when this flag is 0.  */
#define CSL_DFE_RX_PM_POWER_W3_REG_POWER_UNSTABLE_MASK (0x00008000u)
#define CSL_DFE_RX_PM_POWER_W3_REG_POWER_UNSTABLE_SHIFT (0x0000000Fu)
#define CSL_DFE_RX_PM_POWER_W3_REG_POWER_UNSTABLE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_POWER_W3_REG_ADDR (0x00000A8Cu)
#define CSL_DFE_RX_PM_POWER_W3_REG_RESETVAL (0x00000000u)

/* PM_MAGSQ_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 magsq_15_0 : 16;
#else 
    Uint32 magsq_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_MAGSQ_W0_REG;

/* Power meter magnitude square value bit [15:0] */
#define CSL_DFE_RX_PM_MAGSQ_W0_REG_MAGSQ_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_MAGSQ_W0_REG_MAGSQ_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_MAGSQ_W0_REG_MAGSQ_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_MAGSQ_W0_REG_ADDR (0x00000AC0u)
#define CSL_DFE_RX_PM_MAGSQ_W0_REG_RESETVAL (0x00000000u)

/* PM_MAGSQ_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 magsq_31_16 : 16;
#else 
    Uint32 magsq_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_MAGSQ_W1_REG;

/* Power meter magnitude square value bit [31:16] */
#define CSL_DFE_RX_PM_MAGSQ_W1_REG_MAGSQ_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_MAGSQ_W1_REG_MAGSQ_31_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_MAGSQ_W1_REG_MAGSQ_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_MAGSQ_W1_REG_ADDR (0x00000AC4u)
#define CSL_DFE_RX_PM_MAGSQ_W1_REG_RESETVAL (0x00000000u)

/* PM_MAGSQ_W2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 magsq_unstable : 1;
    Uint32 magsq_cnt : 3;
    Uint32 magsq_35_32 : 4;
#else 
    Uint32 magsq_35_32 : 4;
    Uint32 magsq_cnt : 3;
    Uint32 magsq_unstable : 1;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_PM_MAGSQ_W2_REG;

/* Power meter magnitude square value bit [35:32] */
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_MAGSQ_35_32_MASK (0x0000000Fu)
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_MAGSQ_35_32_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_MAGSQ_35_32_RESETVAL (0x00000000u)

/* Power meter magsq value reading counter; 3-bits; gets incremented whenever the overall magsq result is updated. For a valid magsq result reading, must read this register before and after reading the 3 magsq result registers. If the value is unchanged between the two reads, then the magsq result is valid. */
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_MAGSQ_CNT_MASK (0x00000070u)
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_MAGSQ_CNT_SHIFT (0x00000004u)
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_MAGSQ_CNT_RESETVAL (0x00000000u)

/* if = 1, indicates power meter magsq reading is invalid; the entire 3 register magsq value is only stable for a read when this flag is 0.   */
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_MAGSQ_UNSTABLE_MASK (0x00000080u)
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_MAGSQ_UNSTABLE_SHIFT (0x00000007u)
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_MAGSQ_UNSTABLE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_MAGSQ_W2_REG_ADDR (0x00000AC8u)
#define CSL_DFE_RX_PM_MAGSQ_W2_REG_RESETVAL (0x00000000u)

/* PM_HIST_ONE_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 hist_one_15_0 : 16;
#else 
    Uint32 hist_one_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_HIST_ONE_W0_REG;

/* Power meter histogram 1 value bit [15:0] */
#define CSL_DFE_RX_PM_HIST_ONE_W0_REG_HIST_ONE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_HIST_ONE_W0_REG_HIST_ONE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_HIST_ONE_W0_REG_HIST_ONE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_HIST_ONE_W0_REG_ADDR (0x00000B00u)
#define CSL_DFE_RX_PM_HIST_ONE_W0_REG_RESETVAL (0x00000000u)

/* PM_HIST_ONE_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 hist_one_unstable : 1;
    Uint32 hist_one_cnt : 4;
    Uint32 hist_one_23_16 : 8;
#else 
    Uint32 hist_one_23_16 : 8;
    Uint32 hist_one_cnt : 4;
    Uint32 hist_one_unstable : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_RX_PM_HIST_ONE_W1_REG;

/* Power meter histogram 1 value bit [23:16] */
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_HIST_ONE_23_16_MASK (0x000000FFu)
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_HIST_ONE_23_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_HIST_ONE_23_16_RESETVAL (0x00000000u)

/* Power meter hist1 value reading counter; 4-bits; gets incremented whenever the overall hist result is updated. For a valid hist result reading, must read this register before and after reading the 2 hist result registers. If the value is unchanged between the two reads, then the hist result is valid. */
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_HIST_ONE_CNT_MASK (0x00000F00u)
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_HIST_ONE_CNT_SHIFT (0x00000008u)
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_HIST_ONE_CNT_RESETVAL (0x00000000u)

/* if = 1, indicates power meter hist1 reading is invalid; the entire 2 register histogram value is only stable for a read when this flag is 0.  */
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_HIST_ONE_UNSTABLE_MASK (0x00001000u)
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_HIST_ONE_UNSTABLE_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_HIST_ONE_UNSTABLE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_ADDR (0x00000B04u)
#define CSL_DFE_RX_PM_HIST_ONE_W1_REG_RESETVAL (0x00000000u)

/* PM_HIST_TWO_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 hist_two_15_0 : 16;
#else 
    Uint32 hist_two_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_PM_HIST_TWO_W0_REG;

/* Power meter histogram 2 value bit [15:0] */
#define CSL_DFE_RX_PM_HIST_TWO_W0_REG_HIST_TWO_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_PM_HIST_TWO_W0_REG_HIST_TWO_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_HIST_TWO_W0_REG_HIST_TWO_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_HIST_TWO_W0_REG_ADDR (0x00000B20u)
#define CSL_DFE_RX_PM_HIST_TWO_W0_REG_RESETVAL (0x00000000u)

/* PM_HIST_TWO_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 hist_two_unstable : 1;
    Uint32 hist_two_cnt : 4;
    Uint32 hist_two_23_16 : 8;
#else 
    Uint32 hist_two_23_16 : 8;
    Uint32 hist_two_cnt : 4;
    Uint32 hist_two_unstable : 1;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_RX_PM_HIST_TWO_W1_REG;

/* Power meter histogram 2 value bit [23:16] */
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_HIST_TWO_23_16_MASK (0x000000FFu)
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_HIST_TWO_23_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_HIST_TWO_23_16_RESETVAL (0x00000000u)

/* Power meter hist2 value reading counter; 4-bits; gets incremented whenever the overall hist result is updated. For a valid hist result reading, must read this register before and after reading the 2 hist result registers. If the value is unchanged between the two reads, then the hist result is valid. */
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_HIST_TWO_CNT_MASK (0x00000F00u)
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_HIST_TWO_CNT_SHIFT (0x00000008u)
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_HIST_TWO_CNT_RESETVAL (0x00000000u)

/* if = 1, indicates power meter hist2 reading is invalid; the entire 2 register histogram value is only stable for a read when this flag is 0.  */
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_HIST_TWO_UNSTABLE_MASK (0x00001000u)
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_HIST_TWO_UNSTABLE_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_HIST_TWO_UNSTABLE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_ADDR (0x00000B24u)
#define CSL_DFE_RX_PM_HIST_TWO_W1_REG_RESETVAL (0x00000000u)

/* INITS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 18;
    Uint32 input_select : 2;
    Uint32 clk_mult_factor : 2;
    Uint32 cken_dly : 3;
    Uint32 clear_data : 1;
    Uint32 init_state : 1;
    Uint32 init_clk_gate : 1;
    Uint32 inits_ssel : 4;
#else 
    Uint32 inits_ssel : 4;
    Uint32 init_clk_gate : 1;
    Uint32 init_state : 1;
    Uint32 clear_data : 1;
    Uint32 cken_dly : 3;
    Uint32 clk_mult_factor : 2;
    Uint32 input_select : 2;
    Uint32 rsvd0 : 18;
#endif 
} CSL_DFE_RX_INITS_REG;

/* Inits sync selection. */
#define CSL_DFE_RX_INITS_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_RX_INITS_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_RX_INITS_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* RX block init clock gate control. */
#define CSL_DFE_RX_INITS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_RX_INITS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_RX_INITS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* RX block init state control. */
#define CSL_DFE_RX_INITS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_RX_INITS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_RX_INITS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* RX block clear data control. */
#define CSL_DFE_RX_INITS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_RX_INITS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_RX_INITS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

/* RX block clock enable delay control. */
#define CSL_DFE_RX_INITS_REG_CKEN_DLY_MASK (0x00000380u)
#define CSL_DFE_RX_INITS_REG_CKEN_DLY_SHIFT (0x00000007u)
#define CSL_DFE_RX_INITS_REG_CKEN_DLY_RESETVAL (0x00000000u)

/* RX block clock multiply factor control. */
#define CSL_DFE_RX_INITS_REG_CLK_MULT_FACTOR_MASK (0x00000C00u)
#define CSL_DFE_RX_INITS_REG_CLK_MULT_FACTOR_SHIFT (0x0000000Au)
#define CSL_DFE_RX_INITS_REG_CLK_MULT_FACTOR_RESETVAL (0x00000000u)

/* RX block input select control. */
#define CSL_DFE_RX_INITS_REG_INPUT_SELECT_MASK (0x00003000u)
#define CSL_DFE_RX_INITS_REG_INPUT_SELECT_SHIFT (0x0000000Cu)
#define CSL_DFE_RX_INITS_REG_INPUT_SELECT_RESETVAL (0x00000000u)

#define CSL_DFE_RX_INITS_REG_ADDR (0x00000E00u)
#define CSL_DFE_RX_INITS_REG_RESETVAL (0x00000070u)

/* INTERRUPT_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 intr_mask : 4;
#else 
    Uint32 intr_mask : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_RX_INTERRUPT_MASK_REG;

/* RX interrupt mask register. */
#define CSL_DFE_RX_INTERRUPT_MASK_REG_INTR_MASK_MASK (0x0000000Fu)
#define CSL_DFE_RX_INTERRUPT_MASK_REG_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_RX_INTERRUPT_MASK_REG_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_RX_INTERRUPT_MASK_REG_ADDR (0x00000E04u)
#define CSL_DFE_RX_INTERRUPT_MASK_REG_RESETVAL (0x00000000u)

/* INTERRUPT_SERVICE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 ibpm_interrupt : 4;
#else 
    Uint32 ibpm_interrupt : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_RX_INTERRUPT_SERVICE_REG;

/* RX ibpm interrupt register. */
#define CSL_DFE_RX_INTERRUPT_SERVICE_REG_IBPM_INTERRUPT_MASK (0x0000000Fu)
#define CSL_DFE_RX_INTERRUPT_SERVICE_REG_IBPM_INTERRUPT_SHIFT (0x00000000u)
#define CSL_DFE_RX_INTERRUPT_SERVICE_REG_IBPM_INTERRUPT_RESETVAL (0x00000000u)

#define CSL_DFE_RX_INTERRUPT_SERVICE_REG_ADDR (0x00000E08u)
#define CSL_DFE_RX_INTERRUPT_SERVICE_REG_RESETVAL (0x00000000u)

/* INTERRUPT_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 intr_force : 4;
#else 
    Uint32 intr_force : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_RX_INTERRUPT_FORCE_REG;

/* RX interrupt force register. */
#define CSL_DFE_RX_INTERRUPT_FORCE_REG_INTR_FORCE_MASK (0x0000000Fu)
#define CSL_DFE_RX_INTERRUPT_FORCE_REG_INTR_FORCE_SHIFT (0x00000000u)
#define CSL_DFE_RX_INTERRUPT_FORCE_REG_INTR_FORCE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_INTERRUPT_FORCE_REG_ADDR (0x00000E0Cu)
#define CSL_DFE_RX_INTERRUPT_FORCE_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_II0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_ii0 : 16;
#else 
    Uint32 taps_ii0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_II0_REG;

/* Equalizer block i-taps on i-data path. */
#define CSL_DFE_RX_EQR_TAPS_II0_REG_TAPS_II0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_II0_REG_TAPS_II0_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_II0_REG_TAPS_II0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_II0_REG_ADDR (0x00040000u)
#define CSL_DFE_RX_EQR_TAPS_II0_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_IQ0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_iq0 : 16;
#else 
    Uint32 taps_iq0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_IQ0_REG;

/* Equalizer block q-taps on i-data path. */
#define CSL_DFE_RX_EQR_TAPS_IQ0_REG_TAPS_IQ0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_IQ0_REG_TAPS_IQ0_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_IQ0_REG_TAPS_IQ0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_IQ0_REG_ADDR (0x00040040u)
#define CSL_DFE_RX_EQR_TAPS_IQ0_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QI0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_qi0 : 16;
#else 
    Uint32 taps_qi0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_QI0_REG;

/* Equalizer block i-taps on q-data path. */
#define CSL_DFE_RX_EQR_TAPS_QI0_REG_TAPS_QI0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_QI0_REG_TAPS_QI0_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_QI0_REG_TAPS_QI0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_QI0_REG_ADDR (0x00040080u)
#define CSL_DFE_RX_EQR_TAPS_QI0_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QQ0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_qq0 : 16;
#else 
    Uint32 taps_qq0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_QQ0_REG;

/* Equalizer block q-taps on q-data path. */
#define CSL_DFE_RX_EQR_TAPS_QQ0_REG_TAPS_QQ0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_QQ0_REG_TAPS_QQ0_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_QQ0_REG_TAPS_QQ0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_QQ0_REG_ADDR (0x000400C0u)
#define CSL_DFE_RX_EQR_TAPS_QQ0_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_II1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_ii1 : 16;
#else 
    Uint32 taps_ii1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_II1_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_II1_REG_TAPS_II1_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_II1_REG_TAPS_II1_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_II1_REG_TAPS_II1_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_II1_REG_ADDR (0x00040200u)
#define CSL_DFE_RX_EQR_TAPS_II1_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_IQ1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_iq1 : 16;
#else 
    Uint32 taps_iq1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_IQ1_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_IQ1_REG_TAPS_IQ1_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_IQ1_REG_TAPS_IQ1_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_IQ1_REG_TAPS_IQ1_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_IQ1_REG_ADDR (0x00040240u)
#define CSL_DFE_RX_EQR_TAPS_IQ1_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QI1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_qi1 : 16;
#else 
    Uint32 taps_qi1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_QI1_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_QI1_REG_TAPS_QI1_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_QI1_REG_TAPS_QI1_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_QI1_REG_TAPS_QI1_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_QI1_REG_ADDR (0x00040280u)
#define CSL_DFE_RX_EQR_TAPS_QI1_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QQ1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_qq1 : 16;
#else 
    Uint32 taps_qq1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_QQ1_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_QQ1_REG_TAPS_QQ1_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_QQ1_REG_TAPS_QQ1_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_QQ1_REG_TAPS_QQ1_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_QQ1_REG_ADDR (0x000402C0u)
#define CSL_DFE_RX_EQR_TAPS_QQ1_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_II2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_ii2 : 16;
#else 
    Uint32 taps_ii2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_II2_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_II2_REG_TAPS_II2_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_II2_REG_TAPS_II2_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_II2_REG_TAPS_II2_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_II2_REG_ADDR (0x00040400u)
#define CSL_DFE_RX_EQR_TAPS_II2_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_IQ2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_iq2 : 16;
#else 
    Uint32 taps_iq2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_IQ2_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_IQ2_REG_TAPS_IQ2_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_IQ2_REG_TAPS_IQ2_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_IQ2_REG_TAPS_IQ2_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_IQ2_REG_ADDR (0x00040440u)
#define CSL_DFE_RX_EQR_TAPS_IQ2_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QI2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_qi2 : 16;
#else 
    Uint32 taps_qi2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_QI2_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_QI2_REG_TAPS_QI2_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_QI2_REG_TAPS_QI2_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_QI2_REG_TAPS_QI2_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_QI2_REG_ADDR (0x00040480u)
#define CSL_DFE_RX_EQR_TAPS_QI2_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QQ2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_qq2 : 16;
#else 
    Uint32 taps_qq2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_QQ2_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_QQ2_REG_TAPS_QQ2_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_QQ2_REG_TAPS_QQ2_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_QQ2_REG_TAPS_QQ2_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_QQ2_REG_ADDR (0x000404C0u)
#define CSL_DFE_RX_EQR_TAPS_QQ2_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_II3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_ii3 : 16;
#else 
    Uint32 taps_ii3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_II3_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_II3_REG_TAPS_II3_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_II3_REG_TAPS_II3_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_II3_REG_TAPS_II3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_II3_REG_ADDR (0x00040600u)
#define CSL_DFE_RX_EQR_TAPS_II3_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_IQ3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_iq3 : 16;
#else 
    Uint32 taps_iq3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_IQ3_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_IQ3_REG_TAPS_IQ3_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_IQ3_REG_TAPS_IQ3_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_IQ3_REG_TAPS_IQ3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_IQ3_REG_ADDR (0x00040640u)
#define CSL_DFE_RX_EQR_TAPS_IQ3_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QI3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_qi3 : 16;
#else 
    Uint32 taps_qi3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_QI3_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_QI3_REG_TAPS_QI3_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_QI3_REG_TAPS_QI3_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_QI3_REG_TAPS_QI3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_QI3_REG_ADDR (0x00040680u)
#define CSL_DFE_RX_EQR_TAPS_QI3_REG_RESETVAL (0x00000000u)

/* EQR_TAPS_QQ3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 taps_qq3 : 16;
#else 
    Uint32 taps_qq3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_EQR_TAPS_QQ3_REG;

/*  */
#define CSL_DFE_RX_EQR_TAPS_QQ3_REG_TAPS_QQ3_MASK (0x0000FFFFu)
#define CSL_DFE_RX_EQR_TAPS_QQ3_REG_TAPS_QQ3_SHIFT (0x00000000u)
#define CSL_DFE_RX_EQR_TAPS_QQ3_REG_TAPS_QQ3_RESETVAL (0x00000000u)

#define CSL_DFE_RX_EQR_TAPS_QQ3_REG_ADDR (0x000406C0u)
#define CSL_DFE_RX_EQR_TAPS_QQ3_REG_RESETVAL (0x00000000u)

/* IMB_ADAPT_K */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 adapt_k : 5;
#else 
    Uint32 adapt_k : 5;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_RX_IMB_ADAPT_K_REG;

/* IQ Imbalance Correction block adaptation constant table.  Typically: */
#define CSL_DFE_RX_IMB_ADAPT_K_REG_ADAPT_K_MASK (0x0000001Fu)
#define CSL_DFE_RX_IMB_ADAPT_K_REG_ADAPT_K_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_ADAPT_K_REG_ADAPT_K_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_ADAPT_K_REG_ADDR (0x00040800u)
#define CSL_DFE_RX_IMB_ADAPT_K_REG_RESETVAL (0x00000000u)

/* IMB_GSG_SEQ_TABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 seq_table : 16;
#else 
    Uint32 seq_table : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_GSG_SEQ_TABLE_REG;

/* IQ Imbalance Correction block gate signal generator timer values and stream sequences table.   */
#define CSL_DFE_RX_IMB_GSG_SEQ_TABLE_REG_SEQ_TABLE_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_GSG_SEQ_TABLE_REG_SEQ_TABLE_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_GSG_SEQ_TABLE_REG_SEQ_TABLE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_GSG_SEQ_TABLE_REG_ADDR (0x00040C00u)
#define CSL_DFE_RX_IMB_GSG_SEQ_TABLE_REG_RESETVAL (0x00000000u)

/* IMB_GSG_TIMER_TABLE_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 timer_table_15_0 : 16;
#else 
    Uint32 timer_table_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W0_REG;

/* The upper 32 locations hold the 16 24-bit timer lengths.  These specify the number of signal samples - 1 per interval (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate, i.e. there are multiple samples per timer unit). Same table used for all 4 gating signals. */
#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W0_REG_TIMER_TABLE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W0_REG_TIMER_TABLE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W0_REG_TIMER_TABLE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W0_REG_ADDR (0x00040D00u)
#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W0_REG_RESETVAL (0x00000000u)

/* IMB_GSG_TIMER_TABLE_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 timer_table_23_16 : 8;
#else 
    Uint32 timer_table_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W1_REG;

/*  */
#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W1_REG_TIMER_TABLE_23_16_MASK (0x000000FFu)
#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W1_REG_TIMER_TABLE_23_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W1_REG_TIMER_TABLE_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W1_REG_ADDR (0x00040D04u)
#define CSL_DFE_RX_IMB_GSG_TIMER_TABLE_W1_REG_RESETVAL (0x00000000u)

/* DC_GSG_SEQ_TABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 seq_table : 16;
#else 
    Uint32 seq_table : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_DC_GSG_SEQ_TABLE_REG;

/* DC Canceller block gate signal generator timer values and antenna sequences table.   */
#define CSL_DFE_RX_DC_GSG_SEQ_TABLE_REG_SEQ_TABLE_MASK (0x0000FFFFu)
#define CSL_DFE_RX_DC_GSG_SEQ_TABLE_REG_SEQ_TABLE_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_GSG_SEQ_TABLE_REG_SEQ_TABLE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_GSG_SEQ_TABLE_REG_ADDR (0x00041000u)
#define CSL_DFE_RX_DC_GSG_SEQ_TABLE_REG_RESETVAL (0x00000000u)

/* DC_GSG_TIMER_TABLE_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 timer_table_15_0 : 16;
#else 
    Uint32 timer_table_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_DC_GSG_TIMER_TABLE_W0_REG;

/* The upper 32 locations hold the 16 24-bit timer lengths.  These specify the number of signal samples - 1 per interval (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate, i.e. there are multiple samples per timer unit). Same table used for all 4 gating signals. */
#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W0_REG_TIMER_TABLE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W0_REG_TIMER_TABLE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W0_REG_TIMER_TABLE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W0_REG_ADDR (0x00041100u)
#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W0_REG_RESETVAL (0x00000000u)

/* DC_GSG_TIMER_TABLE_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 timer_table_23_16 : 8;
#else 
    Uint32 timer_table_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_DC_GSG_TIMER_TABLE_W1_REG;

/*  */
#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W1_REG_TIMER_TABLE_23_16_MASK (0x000000FFu)
#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W1_REG_TIMER_TABLE_23_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W1_REG_TIMER_TABLE_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W1_REG_ADDR (0x00041104u)
#define CSL_DFE_RX_DC_GSG_TIMER_TABLE_W1_REG_RESETVAL (0x00000000u)

/* FEAGC_GSG_SEQ_TABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 seq_table : 16;
#else 
    Uint32 seq_table : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_GSG_SEQ_TABLE_REG;

/* FEAGC block gate signal generator timer values and antenna sequences table.   */
#define CSL_DFE_RX_FEAGC_GSG_SEQ_TABLE_REG_SEQ_TABLE_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_GSG_SEQ_TABLE_REG_SEQ_TABLE_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_GSG_SEQ_TABLE_REG_SEQ_TABLE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_GSG_SEQ_TABLE_REG_ADDR (0x00041400u)
#define CSL_DFE_RX_FEAGC_GSG_SEQ_TABLE_REG_RESETVAL (0x00000000u)

/* FEAGC_GSG_TIMER_TABLE_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 timer_table_15_0 : 16;
#else 
    Uint32 timer_table_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W0_REG;

/* The upper 32 locations hold the 16 24-bit timer lengths.  These specify the number of signal samples - 1 per interval (or 1/2, or 1/4 the number of samples in the case of sample rate higher than clock rate, i.e. there are multiple samples per timer unit). Same table used for all 4 gating signals. */
#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W0_REG_TIMER_TABLE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W0_REG_TIMER_TABLE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W0_REG_TIMER_TABLE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W0_REG_ADDR (0x00041500u)
#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W0_REG_RESETVAL (0x00000000u)

/* FEAGC_GSG_TIMER_TABLE_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 timer_table_23_16 : 8;
#else 
    Uint32 timer_table_23_16 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W1_REG;

/*  */
#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W1_REG_TIMER_TABLE_23_16_MASK (0x000000FFu)
#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W1_REG_TIMER_TABLE_23_16_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W1_REG_TIMER_TABLE_23_16_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W1_REG_ADDR (0x00041504u)
#define CSL_DFE_RX_FEAGC_GSG_TIMER_TABLE_W1_REG_RESETVAL (0x00000000u)

/* FEAGC_ERR_TABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 err_table : 8;
#else 
    Uint32 err_table : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_FEAGC_ERR_TABLE_REG;

/* FEAGC block 256-word error map table. */
#define CSL_DFE_RX_FEAGC_ERR_TABLE_REG_ERR_TABLE_MASK (0x000000FFu)
#define CSL_DFE_RX_FEAGC_ERR_TABLE_REG_ERR_TABLE_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_ERR_TABLE_REG_ERR_TABLE_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_ERR_TABLE_REG_ADDR (0x00041800u)
#define CSL_DFE_RX_FEAGC_ERR_TABLE_REG_RESETVAL (0x00000000u)

/* FEAGC_GAIN_TABLE_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 17;
    Uint32 gain_table_14_0 : 15;
#else 
    Uint32 gain_table_14_0 : 15;
    Uint32 rsvd0 : 17;
#endif 
} CSL_DFE_RX_FEAGC_GAIN_TABLE_W0_REG;

/* FEAGC block 256-word gain map table. Top 8-bits of each word are the DVGA map values, bottom 15-bits are the gain map values (for feAGC multiplier) */
#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W0_REG_GAIN_TABLE_14_0_MASK (0x00007FFFu)
#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W0_REG_GAIN_TABLE_14_0_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W0_REG_GAIN_TABLE_14_0_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W0_REG_ADDR (0x00041C00u)
#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W0_REG_RESETVAL (0x00000000u)

/* FEAGC_GAIN_TABLE_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 gain_table_22_15 : 8;
#else 
    Uint32 gain_table_22_15 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_RX_FEAGC_GAIN_TABLE_W1_REG;

/*  */
#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W1_REG_GAIN_TABLE_22_15_MASK (0x000000FFu)
#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W1_REG_GAIN_TABLE_22_15_SHIFT (0x00000000u)
#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W1_REG_GAIN_TABLE_22_15_RESETVAL (0x00000000u)

#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W1_REG_ADDR (0x00041C04u)
#define CSL_DFE_RX_FEAGC_GAIN_TABLE_W1_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_RX_H__ */
