/*
 * cslr_dfe_cfr.h
 *
 * This file contains the macros for Register Chip Support Library (CSL) which 
 * can be used for operations on the respective underlying hardware/peripheral
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

/* The file is auto generated at 15:05:17 08/16/13 (Rev 1.71)*/

#ifndef CSLR_DFE_CFR_H__
#define CSLR_DFE_CFR_H__

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 hi;
} CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_REGS;

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 hi;
} CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_REGS;

typedef struct
{
    volatile Uint32 a0lo;
    volatile Uint32 a0hi;
    volatile Uint32 a1lo;
    volatile Uint32 a1hi;
} CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_REGS;

typedef struct
{
    volatile Uint32 w0;
    volatile Uint32 w1;
    volatile Uint32 w2;
    volatile Uint32 w3;
    volatile Uint32 w4;
    volatile Uint32 w5;
    volatile Uint32 w6;
    volatile Uint32 w7;
    volatile Uint32 w8;
    volatile Uint32 w9;
    volatile Uint32 rsvd0[6];
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_REGS;

typedef struct
{
    volatile Uint32 w10;
    volatile Uint32 w11;
    volatile Uint32 w12;
    volatile Uint32 w13;
    volatile Uint32 w14;
    volatile Uint32 w15;
    volatile Uint32 w16;
    volatile Uint32 w17;
    volatile Uint32 w18;
    volatile Uint32 w19;
    volatile Uint32 rsvd0[6];
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_REGS;

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 hi;
} CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_REGS;

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 hi;
} CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_REGS;

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 hi;
} CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_REGS;

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 hi;
} CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_REGS;

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 hi;
} CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_REGS;

typedef struct
{
    volatile Uint32 lo;
    volatile Uint32 hi;
} CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_REGS;

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[1];
    /* Addr: h(4), d(4) */
    volatile Uint32 inits_clks;
    /* Addr: h(8), d(8) */
    volatile Uint32 rsvd1[14];
    /* Addr: h(40), d(64) */
    volatile Uint32 cfr_pdc_intr_mask;
    /* Addr: h(44), d(68) */
    volatile Uint32 cfr_agc_dth_intr_mask;
    /* Addr: h(48), d(72) */
    volatile Uint32 cfr_pdc_intr_status;
    /* Addr: h(4C), d(76) */
    volatile Uint32 cfr_agc_dth_intr_status;
    /* Addr: h(50), d(80) */
    volatile Uint32 cfr_pdc_intr_force;
    /* Addr: h(54), d(84) */
    volatile Uint32 cfr_agc_dth_intr_force;
    /* Addr: h(58), d(88) */
    volatile Uint32 rsvd2[106];
    /* Addr: h(200), d(512) */
    volatile Uint32 cfr0_pdc0_weight_factor_a0;
    /* Addr: h(204), d(516) */
    volatile Uint32 cfr1_pdc0_weight_factor_a1;
    /* Addr: h(208), d(520) */
    volatile Uint32 cfr0_pdc0_luts_updt_prms;
    /* Addr: h(20C), d(524) */
    volatile Uint32 rsvd3[1];
    /* Addr: h(210), d(528) */
    volatile Uint32 cfr0_pdc0_mode_a0;
    /* Addr: h(214), d(532) */
    volatile Uint32 cfr1_pdc0_mode_a1;
    /* Addr: h(218), d(536) */
    volatile Uint32 cfr0_pdc0_max_m1_cp_a0;
    /* Addr: h(21C), d(540) */
    volatile Uint32 cfr1_pdc0_max_m1_cp_a1;
    /* Addr: h(220), d(544) */
    volatile Uint32 cfr0_pdc0_cp_winlutstart_a0;
    /* Addr: h(224), d(548) */
    volatile Uint32 cfr1_pdc0_cp_winlutstart_a1;
    /* Addr: h(228), d(552) */
    volatile Uint32 cfr0_pdc0_cp_firtlutstart_a0;
    /* Addr: h(22C), d(556) */
    volatile Uint32 cfr1_pdc0_cp_firtlutstart_a1;
    /* Addr: h(230), d(560) */
    volatile Uint32 cfr0_pdc0_cp_lutlength_a0;
    /* Addr: h(234), d(564) */
    volatile Uint32 cfr1_pdc0_cp_lutlength_a1;
    /* Addr: h(238), d(568) */
    volatile Uint32 rsvd4[2];
    /* Addr: h(240), d(576) */
    volatile Uint32 cfr0_pdc0_stat_pk_alloc_a0s0;
    /* Addr: h(244), d(580) */
    volatile Uint32 cfr0_pdc0_stat_pk_alloc_a1s0;
    /* Addr: h(248), d(584) */
    volatile Uint32 cfr1_pdc0_stat_pk_alloc_a0s1;
    /* Addr: h(24C), d(588) */
    volatile Uint32 cfr1_pdc0_stat_pk_alloc_a1s1;
    /* Addr: h(250), d(592) */
    volatile Uint32 cfr0_pdc0_stat_pk_missed_a0s0;
    /* Addr: h(254), d(596) */
    volatile Uint32 cfr0_pdc0_stat_pk_missed_a1s0;
    /* Addr: h(258), d(600) */
    volatile Uint32 cfr1_pdc0_stat_pk_missed_a0s1;
    /* Addr: h(25C), d(604) */
    volatile Uint32 cfr1_pdc0_stat_pk_missed_a1s1;
    /* Addr: h(260), d(608) */
    volatile Uint32 cfr0_pdc0_stat_distance_a0s0;
    /* Addr: h(264), d(612) */
    volatile Uint32 cfr1_pdc0_stat_distance_a1s0;
    /* Addr: h(268), d(616) */
    volatile Uint32 cfr0_pdc0_stat_distance_a0s1;
    /* Addr: h(26C), d(620) */
    volatile Uint32 cfr1_pdc0_stat_distance_a1s1;
    /* Addr: h(270), d(624) */
    volatile Uint32 rsvd5[4];
    /* Addr: h(280), d(640) */
    volatile Uint32 cfr0_pdc1_weight_factor_a0;
    /* Addr: h(284), d(644) */
    volatile Uint32 cfr1_pdc1_weight_factor_a1;
    /* Addr: h(288), d(648) */
    volatile Uint32 cfr0_pdc1_luts_updt_prms;
    /* Addr: h(28C), d(652) */
    volatile Uint32 rsvd6[1];
    /* Addr: h(290), d(656) */
    volatile Uint32 cfr0_pdc1_mode_a0;
    /* Addr: h(294), d(660) */
    volatile Uint32 cfr1_pdc1_mode_a1;
    /* Addr: h(298), d(664) */
    volatile Uint32 cfr0_pdc1_max_m1_cp_a0;
    /* Addr: h(29C), d(668) */
    volatile Uint32 cfr1_pdc1_max_m1_cp_a1;
    /* Addr: h(2A0), d(672) */
    volatile Uint32 cfr0_pdc1_cp_winlutstart_a0;
    /* Addr: h(2A4), d(676) */
    volatile Uint32 cfr1_pdc1_cp_winlutstart_a1;
    /* Addr: h(2A8), d(680) */
    volatile Uint32 cfr0_pdc1_cp_firtlutstart_a0;
    /* Addr: h(2AC), d(684) */
    volatile Uint32 cfr1_pdc1_cp_firtlutstart_a1;
    /* Addr: h(2B0), d(688) */
    volatile Uint32 cfr0_pdc1_cp_lutlength_a0;
    /* Addr: h(2B4), d(692) */
    volatile Uint32 cfr1_pdc1_cp_lutlength_a1;
    /* Addr: h(2B8), d(696) */
    volatile Uint32 rsvd7[2];
    /* Addr: h(2C0), d(704) */
    volatile Uint32 cfr0_pdc1_stat_pk_alloc_a0s0;
    /* Addr: h(2C4), d(708) */
    volatile Uint32 cfr1_pdc1_stat_pk_alloc_a1s0;
    /* Addr: h(2C8), d(712) */
    volatile Uint32 cfr0_pdc1_stat_pk_alloc_a0s1;
    /* Addr: h(2CC), d(716) */
    volatile Uint32 cfr1_pdc1_stat_pk_alloc_a1s1;
    /* Addr: h(2D0), d(720) */
    volatile Uint32 cfr0_pdc1_stat_pk_missed_a0s0;
    /* Addr: h(2D4), d(724) */
    volatile Uint32 cfr1_pdc1_stat_pk_missed_a1s0;
    /* Addr: h(2D8), d(728) */
    volatile Uint32 cfr0_pdc1_stat_pk_missed_a0s1;
    /* Addr: h(2DC), d(732) */
    volatile Uint32 cfr1_pdc1_stat_pk_missed_a1s1;
    /* Addr: h(2E0), d(736) */
    volatile Uint32 cfr0_pdc1_stat_distance_a0s0;
    /* Addr: h(2E4), d(740) */
    volatile Uint32 cfr1_pdc1_stat_distance_a1s0;
    /* Addr: h(2E8), d(744) */
    volatile Uint32 cfr0_pdc1_stat_distance_a0s1;
    /* Addr: h(2EC), d(748) */
    volatile Uint32 cfr1_pdc1_stat_distance_a1s1;
    /* Addr: h(2F0), d(752) */
    volatile Uint32 rsvd8[4];
    /* Addr: h(300), d(768) */
    volatile Uint32 cpa0_agc_min_in_th_a0;
    /* Addr: h(304), d(772) */
    volatile Uint32 cpa1_agc_min_in_th_a1;
    /* Addr: h(308), d(776) */
    volatile Uint32 cpa0_agc_min_out_th_a0;
    /* Addr: h(30C), d(780) */
    volatile Uint32 cpa1_agc_min_out_th_a1;
    /* Addr: h(310), d(784) */
    volatile Uint32 cpa0_agc_max_in_th_a0;
    /* Addr: h(314), d(788) */
    volatile Uint32 cpa1_agc_max_in_th_a1;
    /* Addr: h(318), d(792) */
    volatile Uint32 cpa0_agc_max_out_th_a0;
    /* Addr: h(31C), d(796) */
    volatile Uint32 cpa1_agc_max_out_th_a1;
    /* Addr: h(320), d(800) */
    volatile Uint32 cpa0_cfr_in_dly_a0;
    /* Addr: h(324), d(804) */
    volatile Uint32 cpa1_cfr_in_dly_a1;
    /* Addr: h(328), d(808) */
    volatile Uint32 cpa0_cfr_out_dly_a0;
    /* Addr: h(32C), d(812) */
    volatile Uint32 cpa1_cfr_out_dly_a1;
    /* Addr: h(330), d(816) */
    volatile Uint32 cpa0_cfr_frm_msb_a0;
    /* Addr: h(334), d(820) */
    volatile Uint32 cpa1_cfr_frm_msb_a1;
    /* Addr: h(338), d(824) */
    volatile Uint32 cpa0_cfr_frm_lsw_a0;
    /* Addr: h(33C), d(828) */
    volatile Uint32 cpa1_cfr_frm_lsw_a1;
    /* Addr: h(340), d(832) */
    volatile Uint32 cpa0_agc_mode_a0;
    /* Addr: h(344), d(836) */
    volatile Uint32 cpa1_agc_mode_a1;
    /* Addr: h(348), d(840) */
    volatile Uint32 cpa0_agc_ravg_a0;
    /* Addr: h(34C), d(844) */
    volatile Uint32 cpa1_agc_ravg_a1;
    /* Addr: h(350), d(848) */
    volatile Uint32 cpa0_agc_bp_in_ravg_msw_a0;
    /* Addr: h(354), d(852) */
    volatile Uint32 cpa1_agc_bp_in_ravg_msw_a1;
    /* Addr: h(358), d(856) */
    volatile Uint32 cpa0_agc_bp_in_ravg_lsw_a0;
    /* Addr: h(35C), d(860) */
    volatile Uint32 cpa1_agc_bp_in_ravg_lsw_a1;
    /* Addr: h(360), d(864) */
    volatile Uint32 cfr0_cfr_prem_a0;
    /* Addr: h(364), d(868) */
    volatile Uint32 cfr1_cfr_prem_a1;
    /* Addr: h(368), d(872) */
    volatile Uint32 cfr0_cfr_pa_protect_a0;
    /* Addr: h(36C), d(876) */
    volatile Uint32 cfr1_cfr_pa_protect_a1;
    /* Addr: h(370), d(880) */
    volatile Uint32 cfr0_cfr_postm_a0;
    /* Addr: h(374), d(884) */
    volatile Uint32 cfr1_cfr_postm_a1;
    /* Addr: h(378), d(888) */
    volatile Uint32 cfr0_cfr_mode_a0;
    /* Addr: h(37C), d(892) */
    volatile Uint32 cfr1_cfr_mode_a1;
    /* Addr: h(380), d(896) */
    volatile Uint32 rsvd9[16];
    /* Addr: h(3C0), d(960) */
    volatile Uint32 cfr0_latch_and_clr_stat;
    /* Addr: h(3C4), d(964) */
    volatile Uint32 cfr1_latch_and_clr_stat;
    /* Addr: h(3C8), d(968) */
    volatile Uint32 cfr_test_bus_mux;
    /* Addr: h(3CC), d(972) */
    volatile Uint32 cfr_cfr_config0;
    /* Addr: h(3D0), d(976) */
    volatile Uint32 cfr_cfr_status;
    /* Addr: h(3D4), d(980) */
    volatile Uint32 rsvd10[1];
    /* Addr: h(3D8), d(984) */
    volatile Uint32 cfr0_cfr_scmode_a0;
    /* Addr: h(3DC), d(988) */
    volatile Uint32 cfr1_cfr_scmode_a1;
    /* Addr: h(3E0), d(992) */
    volatile Uint32 cfr0_agc_stat_ravg_in_a0_lo;
    /* Addr: h(3E4), d(996) */
    volatile Uint32 cfr0_agc_stat_ravg_in_a0_hi;
    /* Addr: h(3E8), d(1000) */
    volatile Uint32 cfr1_agc_stat_ravg_in_a1_lo;
    /* Addr: h(3EC), d(1004) */
    volatile Uint32 cfr1_agc_stat_ravg_in_a1_hi;
    /* Addr: h(3F0), d(1008) */
    volatile Uint32 cfr0_agc_stat_ravg_out_a0_lo;
    /* Addr: h(3F4), d(1012) */
    volatile Uint32 cfr0_agc_stat_ravg_out_a0_hi;
    /* Addr: h(3F8), d(1016) */
    volatile Uint32 cfr1_agc_stat_ravg_out_a1_lo;
    /* Addr: h(3FC), d(1020) */
    volatile Uint32 cfr1_agc_stat_ravg_out_a1_hi;
    /* Addr: h(400), d(1024) */
    volatile Uint32 rsvd11[128];
    /* Addr: h(600), d(1536) */
    volatile Uint32 cfr0_cfr_updt_gen_0;
    /* Addr: h(604), d(1540) */
    volatile Uint32 cfr1_cfr_updt_gen_1;
    /* Addr: h(608), d(1544) */
    volatile Uint32 cfr_cfr_updt_gen_2;
    /* Addr: h(60C), d(1548) */
    volatile Uint32 cfr_cfr_updt_gen_3;
    /* Addr: h(610), d(1552) */
    volatile Uint32 cfr0_cfr_updt_gen_4;
    /* Addr: h(614), d(1556) */
    volatile Uint32 cfr1_cfr_updt_gen_5;
    /* Addr: h(618), d(1560) */
    volatile Uint32 cfr0_cfr_updt_gen_6;
    /* Addr: h(61C), d(1564) */
    volatile Uint32 cfr1_cfr_updt_gen_7;
    /* Addr: h(620), d(1568) */
    volatile Uint32 rsvd12[8];
    /* Addr: h(640), d(1600) */
    volatile Uint32 cfr_sig_gen_mode;
    /* Addr: h(644), d(1604) */
    volatile Uint32 cfr_sig_gen_ramp_start_lsw;
    /* Addr: h(648), d(1608) */
    volatile Uint32 cfr_sig_gen_ramp_start_msw;
    /* Addr: h(64C), d(1612) */
    volatile Uint32 cfr_sig_gen_ramp_stop_lsw;
    /* Addr: h(650), d(1616) */
    volatile Uint32 cfr_sig_gen_ramp_stop_msw;
    /* Addr: h(654), d(1620) */
    volatile Uint32 cfr_sig_gen_ramp_slope_lsw;
    /* Addr: h(658), d(1624) */
    volatile Uint32 cfr_sig_gen_ramp_slope_msw;
    /* Addr: h(65C), d(1628) */
    volatile Uint32 cfr_sig_gen_pulse_width;
    /* Addr: h(660), d(1632) */
    volatile Uint32 cfr_sig_gen_bits;
    /* Addr: h(664), d(1636) */
    volatile Uint32 rsvd13[7];
    /* Addr: h(680), d(1664) */
    volatile Uint32 cfr_check_sum0_mode;
    /* Addr: h(684), d(1668) */
    volatile Uint32 cfr_check_sum0_signal_len;
    /* Addr: h(688), d(1672) */
    volatile Uint32 cfr_check_sum0_chan_sel;
    /* Addr: h(68C), d(1676) */
    volatile Uint32 cfr_check_sum0_result_lsw;
    /* Addr: h(690), d(1680) */
    volatile Uint32 cfr_check_sum0_result_msw;
    /* Addr: h(694), d(1684) */
    volatile Uint32 rsvd14[3];
    /* Addr: h(6A0), d(1696) */
    volatile Uint32 cfr_check_sum1_mode;
    /* Addr: h(6A4), d(1700) */
    volatile Uint32 cfr_check_sum1_signal_len;
    /* Addr: h(6A8), d(1704) */
    volatile Uint32 cfr_check_sum1_chan_sel;
    /* Addr: h(6AC), d(1708) */
    volatile Uint32 cfr_check_sum1_result_lsw;
    /* Addr: h(6B0), d(1712) */
    volatile Uint32 cfr_check_sum1_result_msw;
    /* Addr: h(6B4), d(1716) */
    volatile Uint32 rsvd15[3];
    /* Addr: h(6C0), d(1728) */
    volatile Uint32 dth0_dth_mode_a0;
    /* Addr: h(6C4), d(1732) */
    volatile Uint32 dth1_dth_mode_a1;
    /* Addr: h(6C8), d(1736) */
    volatile Uint32 dth0_dth_t01_a0;
    /* Addr: h(6CC), d(1740) */
    volatile Uint32 dth1_dth_t01_a1;
    /* Addr: h(6D0), d(1744) */
    volatile Uint32 dth0_dth_t02_a0;
    /* Addr: h(6D4), d(1748) */
    volatile Uint32 dth1_dth_t02_a1;
    /* Addr: h(6D8), d(1752) */
    volatile Uint32 dth0_dth_t03_a0;
    /* Addr: h(6DC), d(1756) */
    volatile Uint32 dth1_dth_t03_a1;
    /* Addr: h(6E0), d(1760) */
    volatile Uint32 dth0_dth_t04_a0;
    /* Addr: h(6E4), d(1764) */
    volatile Uint32 dth1_dth_t04_a1;
    /* Addr: h(6E8), d(1768) */
    volatile Uint32 dth0_dth_t05_a0;
    /* Addr: h(6EC), d(1772) */
    volatile Uint32 dth1_dth_t05_a1;
    /* Addr: h(6F0), d(1776) */
    volatile Uint32 dth0_dth_t06_a0;
    /* Addr: h(6F4), d(1780) */
    volatile Uint32 dth1_dth_t06_a1;
    /* Addr: h(6F8), d(1784) */
    volatile Uint32 dth0_dth_t07_a0;
    /* Addr: h(6FC), d(1788) */
    volatile Uint32 dth1_dth_t07_a1;
    /* Addr: h(700), d(1792) */
    volatile Uint32 dth0_dth_t08_a0;
    /* Addr: h(704), d(1796) */
    volatile Uint32 dth1_dth_t08_a1;
    /* Addr: h(708), d(1800) */
    volatile Uint32 dth0_dth_t09_a0;
    /* Addr: h(70C), d(1804) */
    volatile Uint32 dth1_dth_t09_a1;
    /* Addr: h(710), d(1808) */
    volatile Uint32 dth0_dth_t0a_a0;
    /* Addr: h(714), d(1812) */
    volatile Uint32 dth1_dth_t0a_a1;
    /* Addr: h(718), d(1816) */
    volatile Uint32 dth0_dth_t0b_a0;
    /* Addr: h(71C), d(1820) */
    volatile Uint32 dth1_dth_t0b_a1;
    /* Addr: h(720), d(1824) */
    volatile Uint32 dth0_dth_t0c_a0;
    /* Addr: h(724), d(1828) */
    volatile Uint32 dth1_dth_t0c_a1;
    /* Addr: h(728), d(1832) */
    volatile Uint32 dth0_dth_t0d_a0;
    /* Addr: h(72C), d(1836) */
    volatile Uint32 dth1_dth_t0d_a1;
    /* Addr: h(730), d(1840) */
    volatile Uint32 dth0_dth_t0e_a0;
    /* Addr: h(734), d(1844) */
    volatile Uint32 dth1_dth_t0e_a1;
    /* Addr: h(738), d(1848) */
    volatile Uint32 dth0_dth_t0f_a0;
    /* Addr: h(73C), d(1852) */
    volatile Uint32 dth1_dth_t0f_a1;
    /* Addr: h(740), d(1856) */
    volatile Uint32 dth0_dth_t10_a0;
    /* Addr: h(744), d(1860) */
    volatile Uint32 dth1_dth_t10_a1;
    /* Addr: h(748), d(1864) */
    volatile Uint32 dth0_dth_t11_a0;
    /* Addr: h(74C), d(1868) */
    volatile Uint32 dth1_dth_t11_a1;
    /* Addr: h(750), d(1872) */
    volatile Uint32 dth0_dth_t12_a0;
    /* Addr: h(754), d(1876) */
    volatile Uint32 dth1_dth_t12_a1;
    /* Addr: h(758), d(1880) */
    volatile Uint32 dth0_dth_t13_a0;
    /* Addr: h(75C), d(1884) */
    volatile Uint32 dth1_dth_t13_a1;
    /* Addr: h(760), d(1888) */
    volatile Uint32 dth0_dth_t14_a0;
    /* Addr: h(764), d(1892) */
    volatile Uint32 dth1_dth_t14_a1;
    /* Addr: h(768), d(1896) */
    volatile Uint32 dth0_dth_t15_a0;
    /* Addr: h(76C), d(1900) */
    volatile Uint32 dth1_dth_t15_a1;
    /* Addr: h(770), d(1904) */
    volatile Uint32 dth0_dth_t16_a0;
    /* Addr: h(774), d(1908) */
    volatile Uint32 dth1_dth_t16_a1;
    /* Addr: h(778), d(1912) */
    volatile Uint32 dth0_dth_t17_a0;
    /* Addr: h(77C), d(1916) */
    volatile Uint32 dth1_dth_t17_a1;
    /* Addr: h(780), d(1920) */
    volatile Uint32 dth0_dth_t18_a0;
    /* Addr: h(784), d(1924) */
    volatile Uint32 dth1_dth_t18_a1;
    /* Addr: h(788), d(1928) */
    volatile Uint32 dth0_dth_t19_a0;
    /* Addr: h(78C), d(1932) */
    volatile Uint32 dth1_dth_t19_a1;
    /* Addr: h(790), d(1936) */
    volatile Uint32 dth0_dth_t1a_a0;
    /* Addr: h(794), d(1940) */
    volatile Uint32 dth1_dth_t1a_a1;
    /* Addr: h(798), d(1944) */
    volatile Uint32 dth0_dth_t1b_a0;
    /* Addr: h(79C), d(1948) */
    volatile Uint32 dth1_dth_t1b_a1;
    /* Addr: h(7A0), d(1952) */
    volatile Uint32 dth0_dth_t1c_a0;
    /* Addr: h(7A4), d(1956) */
    volatile Uint32 dth1_dth_t1c_a1;
    /* Addr: h(7A8), d(1960) */
    volatile Uint32 dth0_dth_t1d_a0;
    /* Addr: h(7AC), d(1964) */
    volatile Uint32 dth1_dth_t1d_a1;
    /* Addr: h(7B0), d(1968) */
    volatile Uint32 dth0_dth_t1e_a0;
    /* Addr: h(7B4), d(1972) */
    volatile Uint32 dth1_dth_t1e_a1;
    /* Addr: h(7B8), d(1976) */
    volatile Uint32 dth0_dth_t1f_a0;
    /* Addr: h(7BC), d(1980) */
    volatile Uint32 dth1_dth_t1f_a1;
    /* Addr: h(7C0), d(1984) */
    volatile Uint32 dth0_dth_pwr_section;
    /* Addr: h(7C4), d(1988) */
    volatile Uint32 dth1_dth_pwr_section;
    /* Addr: h(7C8), d(1992) */
    volatile Uint32 rsvd16[3598];
    /* Addr: h(4000), d(16384) */
    volatile Uint32 pdc0_pdc_luts_sw_a_i[256];
    /* Addr: h(4400), d(17408) */
    volatile Uint32 pdc0_pdc_luts_sw_b_i[256];
    /* Addr: h(4800), d(18432) */
    volatile Uint32 pdc0_pdc_luts_sw_c_i[256];
    /* Addr: h(4C00), d(19456) */
    volatile Uint32 pdc0_pdc_luts_sw_shdw_i[256];
    /* Addr: h(5000), d(20480) */
    volatile Uint32 pdc0_pdc_luts_sw_a_q[256];
    /* Addr: h(5400), d(21504) */
    volatile Uint32 pdc0_pdc_luts_sw_b_q[256];
    /* Addr: h(5800), d(22528) */
    volatile Uint32 pdc0_pdc_luts_sw_c_q[256];
    /* Addr: h(5C00), d(23552) */
    volatile Uint32 pdc0_pdc_luts_sw_shdw_q[256];
    /* Addr: h(6000), d(24576) */
    volatile Uint32 pdc0_pdc_luts_sw_a_iq[256];
    /* Addr: h(6400), d(25600) */
    volatile Uint32 pdc0_pdc_luts_sw_b_iq[256];
    /* Addr: h(6800), d(26624) */
    volatile Uint32 pdc0_pdc_luts_sw_c_iq[256];
    /* Addr: h(6C00), d(27648) */
    volatile Uint32 pdc0_pdc_luts_sw_shdw_iq[256];
    /* Addr: h(7000), d(28672) */
    volatile Uint32 rsvd17[1024];
    /* Addr: h(8000), d(32768) */
    volatile Uint32 pdc1_pdc_luts_sw_a_i[256];
    /* Addr: h(8400), d(33792) */
    volatile Uint32 pdc1_pdc_luts_sw_b_i[256];
    /* Addr: h(8800), d(34816) */
    volatile Uint32 pdc1_pdc_luts_sw_c_i[256];
    /* Addr: h(8C00), d(35840) */
    volatile Uint32 pdc1_pdc_luts_sw_shdw_i[256];
    /* Addr: h(9000), d(36864) */
    volatile Uint32 pdc1_pdc_luts_sw_a_q[256];
    /* Addr: h(9400), d(37888) */
    volatile Uint32 pdc1_pdc_luts_sw_b_q[256];
    /* Addr: h(9800), d(38912) */
    volatile Uint32 pdc1_pdc_luts_sw_c_q[256];
    /* Addr: h(9C00), d(39936) */
    volatile Uint32 pdc1_pdc_luts_sw_shdw_q[256];
    /* Addr: h(A000), d(40960) */
    volatile Uint32 pdc1_pdc_luts_sw_a_iq[256];
    /* Addr: h(A400), d(41984) */
    volatile Uint32 pdc1_pdc_luts_sw_b_iq[256];
    /* Addr: h(A800), d(43008) */
    volatile Uint32 pdc1_pdc_luts_sw_c_iq[256];
    /* Addr: h(AC00), d(44032) */
    volatile Uint32 pdc1_pdc_luts_sw_shdw_iq[256];
    /* Addr: h(B000), d(45056) */
    volatile Uint32 rsvd18[1024];
    /* Addr: h(C000), d(49152) */
    volatile Uint32 pdc_01_pdc_luts_sw_a_i[256];
    /* Addr: h(C400), d(50176) */
    volatile Uint32 pdc_01_pdc_luts_sw_b_i[256];
    /* Addr: h(C800), d(51200) */
    volatile Uint32 pdc_01_pdc_luts_sw_c_i[256];
    /* Addr: h(CC00), d(52224) */
    volatile Uint32 pdc_01_pdc_luts_sw_shdw_i[256];
    /* Addr: h(D000), d(53248) */
    volatile Uint32 pdc_01_pdc_luts_sw_a_q[256];
    /* Addr: h(D400), d(54272) */
    volatile Uint32 pdc_01_pdc_luts_sw_b_q[256];
    /* Addr: h(D800), d(55296) */
    volatile Uint32 pdc_01_pdc_luts_sw_c_q[256];
    /* Addr: h(DC00), d(56320) */
    volatile Uint32 pdc_01_pdc_luts_sw_shdw_q[256];
    /* Addr: h(E000), d(57344) */
    volatile Uint32 pdc_01_pdc_luts_sw_a_iq[256];
    /* Addr: h(E400), d(58368) */
    volatile Uint32 pdc_01_pdc_luts_sw_b_iq[256];
    /* Addr: h(E800), d(59392) */
    volatile Uint32 pdc_01_pdc_luts_sw_c_iq[256];
    /* Addr: h(EC00), d(60416) */
    volatile Uint32 pdc_01_pdc_luts_sw_shdw_iq[256];
    /* Addr: h(F000), d(61440) */
    volatile Uint32 rsvd19[1024];
    /* Addr: h(10000), d(65536) */
    volatile CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_REGS cpa0_agc_sgen_32x27_sgen_mem_a0[16];
    /* Addr: h(10080), d(65664) */
    volatile CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_REGS cpa1_agc_sgen_32x27_sgen_mem_a1[16];
    /* Addr: h(10100), d(65792) */
    volatile CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_REGS cpa0_agc_16x19_prms_mem[8];
    /* Addr: h(10180), d(65920) */
    volatile Uint32 rsvd20[4000];
    /* Addr: h(14000), d(81920) */
    volatile CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_REGS dth0_dth_64x160_th_mem[32];
    /* Addr: h(14800), d(83968) */
    volatile CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_REGS dth1_dth_64x160_th_mem[32];
    /* Addr: h(15000), d(86016) */
    volatile CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_REGS dth0_dth_sgen_32x27_sgen_mem_a0[16];
    /* Addr: h(15080), d(86144) */
    volatile CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_REGS dth1_dth_sgen_32x27_sgen_mem_a1[16];
    /* Addr: h(15100), d(86272) */
    volatile CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_REGS dth0_agc_dth_sgen_32x27_sgen_mem_a0[16];
    /* Addr: h(15180), d(86400) */
    volatile CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_REGS dth1_agc_dth_sgen_32x27_sgen_mem_a1[16];
    /* Addr: h(15200), d(86528) */
    volatile Uint32 rsvd21[2944];
    /* Addr: h(18000), d(98304) */
    volatile CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_REGS cfr_cl_256x26_cl_lut_a0[128];
    /* Addr: h(18400), d(99328) */
    volatile CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_REGS cfr_cl_256x26_cl_lut_a1[128];
} CSL_DFE_CFR_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* INITS_CLKS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 cfr1_mux : 1;
    Uint32 cfr_cken_dly_2_0 : 3;
    Uint32 cfr_bypass : 1;
    Uint32 clear_data : 1;
    Uint32 init_state : 1;
    Uint32 init_clk_gate : 1;
    Uint32 inits_ssel_3_0 : 4;
#else 
    Uint32 inits_ssel_3_0 : 4;
    Uint32 init_clk_gate : 1;
    Uint32 init_state : 1;
    Uint32 clear_data : 1;
    Uint32 cfr_bypass : 1;
    Uint32 cfr_cken_dly_2_0 : 3;
    Uint32 cfr1_mux : 1;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_INITS_CLKS_REG;

/* inits_ssel */
#define CSL_DFE_CFR_INITS_CLKS_REG_INITS_SSEL_3_0_MASK (0x0000000Fu)
#define CSL_DFE_CFR_INITS_CLKS_REG_INITS_SSEL_3_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_INITS_CLKS_REG_INITS_SSEL_3_0_RESETVAL (0x00000000u)

/* init_clk_gate */
#define CSL_DFE_CFR_INITS_CLKS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_CFR_INITS_CLKS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_CFR_INITS_CLKS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* init_sate */
#define CSL_DFE_CFR_INITS_CLKS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_CFR_INITS_CLKS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_CFR_INITS_CLKS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* clear_data */
#define CSL_DFE_CFR_INITS_CLKS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_CFR_INITS_CLKS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_CFR_INITS_CLKS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

/* cfr_bypass */
#define CSL_DFE_CFR_INITS_CLKS_REG_CFR_BYPASS_MASK (0x00000080u)
#define CSL_DFE_CFR_INITS_CLKS_REG_CFR_BYPASS_SHIFT (0x00000007u)
#define CSL_DFE_CFR_INITS_CLKS_REG_CFR_BYPASS_RESETVAL (0x00000000u)

/* cfr_cken_dly (delay for cfr input cken; CYA feature) */
#define CSL_DFE_CFR_INITS_CLKS_REG_CFR_CKEN_DLY_2_0_MASK (0x00000700u)
#define CSL_DFE_CFR_INITS_CLKS_REG_CFR_CKEN_DLY_2_0_SHIFT (0x00000008u)
#define CSL_DFE_CFR_INITS_CLKS_REG_CFR_CKEN_DLY_2_0_RESETVAL (0x00000000u)

/* cfr1_mux control is both confusing and a misnomer. There is a cfr1_mux control for cfr0 and for cfr1. What they REALLY do is the cfr0.cfr1_mux controls if cfr0 output is replaced with cfr1 output before going to cdfr. The cfr1.cfr1_mux controls if cfr1's INPUT comes from cfr0 or from summer. cmd5798 sets these for you. */
#define CSL_DFE_CFR_INITS_CLKS_REG_CFR1_MUX_MASK (0x00000800u)
#define CSL_DFE_CFR_INITS_CLKS_REG_CFR1_MUX_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_INITS_CLKS_REG_CFR1_MUX_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_INITS_CLKS_REG_ADDR (0x00000004u)
#define CSL_DFE_CFR_INITS_CLKS_REG_RESETVAL (0x00000070u)

/* CFR_PDC_INTR_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 cfr0_pdc1_luts_updt_done_intr_mask : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s1_intr_mask : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s0_intr_mask : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s1_intr_mask : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s0_intr_mask : 1;
    Uint32 cfr0_pdc0_luts_updt_done_intr_mask : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s1_intr_mask : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s0_intr_mask : 1;
    Uint32 cfr0_pdc0_no_cpge_a0s1_intr_mask : 1;
    Uint32 cfr0_pdc0_no_cpge_a0s0_intr_mask : 1;
#else 
    Uint32 cfr0_pdc0_no_cpge_a0s0_intr_mask : 1;
    Uint32 cfr0_pdc0_no_cpge_a0s1_intr_mask : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s0_intr_mask : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s1_intr_mask : 1;
    Uint32 cfr0_pdc0_luts_updt_done_intr_mask : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s0_intr_mask : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s1_intr_mask : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s0_intr_mask : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s1_intr_mask : 1;
    Uint32 cfr0_pdc1_luts_updt_done_intr_mask : 1;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG;

/* cfr0_pdc0_no_cpge_a0s0_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A0S0_INTR_MASK_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A0S0_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A0S0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_pdc0_no_cpge_a0s1_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A0S1_INTR_MASK_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A0S1_INTR_MASK_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A0S1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_pdc0_no_cpge_a1s0_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A1S0_INTR_MASK_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A1S0_INTR_MASK_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A1S0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_pdc0_no_cpge_a1s1_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A1S1_INTR_MASK_MASK (0x00000008u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A1S1_INTR_MASK_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_NO_CPGE_A1S1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_pdc0_luts_updt_done_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_LUTS_UPDT_DONE_INTR_MASK_MASK (0x00000010u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_LUTS_UPDT_DONE_INTR_MASK_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC0_LUTS_UPDT_DONE_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a0s0_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A0S0_INTR_MASK_MASK (0x00000020u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A0S0_INTR_MASK_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A0S0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a0s1_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A0S1_INTR_MASK_MASK (0x00000040u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A0S1_INTR_MASK_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A0S1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a1s0_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A1S0_INTR_MASK_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A1S0_INTR_MASK_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A1S0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a1s1_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A1S1_INTR_MASK_MASK (0x00000100u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A1S1_INTR_MASK_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_NO_CPGE_A1S1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_pdc1_luts_updt_done_intr_mask */
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_LUTS_UPDT_DONE_INTR_MASK_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_LUTS_UPDT_DONE_INTR_MASK_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_CFR0_PDC1_LUTS_UPDT_DONE_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_ADDR (0x00000040u)
#define CSL_DFE_CFR_CFR_PDC_INTR_MASK_REG_RESETVAL (0x00000000u)

/* CFR_AGC_DTH_INTR_MASK */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_dth_sync0_a1_intr_mask : 1;
    Uint32 cfr0_dth_sync0_a0_intr_mask : 1;
    Uint32 cfr0_dth_pwr_cng_a1_intr_mask : 1;
    Uint32 cfr0_dth_pwr_cng_a0_intr_mask : 1;
    Uint32 cfr0_agc_sync1_a1_intr_mask : 1;
    Uint32 cfr0_agc_sync0_a1_intr_mask : 1;
    Uint32 cfr0_agc_sync1_a0_intr_mask : 1;
    Uint32 cfr0_agc_sync0_a0_intr_mask : 1;
    Uint32 cfr0_agc_max_out_th_a1_intr_mask : 1;
    Uint32 cfr0_agc_max_in_th_a1_intr_mask : 1;
    Uint32 cfr0_agc_min_out_th_a1_intr_mask : 1;
    Uint32 cfr0_agc_min_in_th_a1_intr_mask : 1;
    Uint32 cfr0_agc_max_out_th_a0_intr_mask : 1;
    Uint32 cfr0_agc_max_in_th_a0_intr_mask : 1;
    Uint32 cfr0_agc_min_out_th_a0_intr_mask : 1;
    Uint32 cfr0_agc_min_in_th_a0_intr_mask : 1;
#else 
    Uint32 cfr0_agc_min_in_th_a0_intr_mask : 1;
    Uint32 cfr0_agc_min_out_th_a0_intr_mask : 1;
    Uint32 cfr0_agc_max_in_th_a0_intr_mask : 1;
    Uint32 cfr0_agc_max_out_th_a0_intr_mask : 1;
    Uint32 cfr0_agc_min_in_th_a1_intr_mask : 1;
    Uint32 cfr0_agc_min_out_th_a1_intr_mask : 1;
    Uint32 cfr0_agc_max_in_th_a1_intr_mask : 1;
    Uint32 cfr0_agc_max_out_th_a1_intr_mask : 1;
    Uint32 cfr0_agc_sync0_a0_intr_mask : 1;
    Uint32 cfr0_agc_sync1_a0_intr_mask : 1;
    Uint32 cfr0_agc_sync0_a1_intr_mask : 1;
    Uint32 cfr0_agc_sync1_a1_intr_mask : 1;
    Uint32 cfr0_dth_pwr_cng_a0_intr_mask : 1;
    Uint32 cfr0_dth_pwr_cng_a1_intr_mask : 1;
    Uint32 cfr0_dth_sync0_a0_intr_mask : 1;
    Uint32 cfr0_dth_sync0_a1_intr_mask : 1;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG;

/* cfr0_agc_min_in_th_a0_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_IN_TH_A0_INTR_MASK_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_IN_TH_A0_INTR_MASK_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_IN_TH_A0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_min_out_th_a0_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_OUT_TH_A0_INTR_MASK_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_OUT_TH_A0_INTR_MASK_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_OUT_TH_A0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_max_in_th_a0_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_IN_TH_A0_INTR_MASK_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_IN_TH_A0_INTR_MASK_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_IN_TH_A0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_max_out_th_a0_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_OUT_TH_A0_INTR_MASK_MASK (0x00000008u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_OUT_TH_A0_INTR_MASK_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_OUT_TH_A0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_min_in_th_a1_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_IN_TH_A1_INTR_MASK_MASK (0x00000010u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_IN_TH_A1_INTR_MASK_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_IN_TH_A1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_min_out_th_a1_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_OUT_TH_A1_INTR_MASK_MASK (0x00000020u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_OUT_TH_A1_INTR_MASK_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MIN_OUT_TH_A1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_max_in_th_a1_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_IN_TH_A1_INTR_MASK_MASK (0x00000040u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_IN_TH_A1_INTR_MASK_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_IN_TH_A1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_max_out_th_a1_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_OUT_TH_A1_INTR_MASK_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_OUT_TH_A1_INTR_MASK_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_MAX_OUT_TH_A1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_sync0_a0_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC0_A0_INTR_MASK_MASK (0x00000100u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC0_A0_INTR_MASK_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC0_A0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_sync1_a0_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC1_A0_INTR_MASK_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC1_A0_INTR_MASK_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC1_A0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_sync0_a1_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC0_A1_INTR_MASK_MASK (0x00000400u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC0_A1_INTR_MASK_SHIFT (0x0000000Au)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC0_A1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_agc_sync1_a1_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC1_A1_INTR_MASK_MASK (0x00000800u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC1_A1_INTR_MASK_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_AGC_SYNC1_A1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a0_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_PWR_CNG_A0_INTR_MASK_MASK (0x00001000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_PWR_CNG_A0_INTR_MASK_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_PWR_CNG_A0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a1_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_PWR_CNG_A1_INTR_MASK_MASK (0x00002000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_PWR_CNG_A1_INTR_MASK_SHIFT (0x0000000Du)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_PWR_CNG_A1_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a0_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_SYNC0_A0_INTR_MASK_MASK (0x00004000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_SYNC0_A0_INTR_MASK_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_SYNC0_A0_INTR_MASK_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a1_intr_mask */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_SYNC0_A1_INTR_MASK_MASK (0x00008000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_SYNC0_A1_INTR_MASK_SHIFT (0x0000000Fu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_CFR0_DTH_SYNC0_A1_INTR_MASK_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_ADDR (0x00000044u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_MASK_REG_RESETVAL (0x00000000u)

/* CFR_PDC_INTR_STATUS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 cfr0_pdc1_luts_updt_done_intr_status : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s1_intr_status : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s0_intr_status : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s1_intr_status : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s0_intr_status : 1;
    Uint32 cfr0_pdc0_luts_updt_done_intr_status : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s1_intr_status : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s0_intr_status : 1;
    Uint32 cfr0_pdc0_no_cpge_a0s1_intr_status : 1;
    Uint32 cfr0_pdc0_no_cpge_a0s0_intr_status : 1;
#else 
    Uint32 cfr0_pdc0_no_cpge_a0s0_intr_status : 1;
    Uint32 cfr0_pdc0_no_cpge_a0s1_intr_status : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s0_intr_status : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s1_intr_status : 1;
    Uint32 cfr0_pdc0_luts_updt_done_intr_status : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s0_intr_status : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s1_intr_status : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s0_intr_status : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s1_intr_status : 1;
    Uint32 cfr0_pdc1_luts_updt_done_intr_status : 1;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG;

/* cfr0_pdc0_no_cpge_a0s0_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A0S0_INTR_STATUS_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A0S0_INTR_STATUS_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A0S0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_pdc0_no_cpge_a0s1_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A0S1_INTR_STATUS_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A0S1_INTR_STATUS_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A0S1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_pdc0_no_cpge_a1s0_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A1S0_INTR_STATUS_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A1S0_INTR_STATUS_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A1S0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_pdc0_no_cpge_a1s1_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A1S1_INTR_STATUS_MASK (0x00000008u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A1S1_INTR_STATUS_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_NO_CPGE_A1S1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_pdc0_luts_updt_done_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_LUTS_UPDT_DONE_INTR_STATUS_MASK (0x00000010u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_LUTS_UPDT_DONE_INTR_STATUS_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC0_LUTS_UPDT_DONE_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a0s0_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A0S0_INTR_STATUS_MASK (0x00000020u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A0S0_INTR_STATUS_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A0S0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a0s1_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A0S1_INTR_STATUS_MASK (0x00000040u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A0S1_INTR_STATUS_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A0S1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a1s0_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A1S0_INTR_STATUS_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A1S0_INTR_STATUS_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A1S0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a1s1_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A1S1_INTR_STATUS_MASK (0x00000100u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A1S1_INTR_STATUS_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_NO_CPGE_A1S1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_pdc1_luts_updt_done_intr_status */
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_LUTS_UPDT_DONE_INTR_STATUS_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_LUTS_UPDT_DONE_INTR_STATUS_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_CFR0_PDC1_LUTS_UPDT_DONE_INTR_STATUS_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_ADDR (0x00000048u)
#define CSL_DFE_CFR_CFR_PDC_INTR_STATUS_REG_RESETVAL (0x00000000u)

/* CFR_AGC_DTH_INTR_STATUS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_dth_sync0_a1_intr_status : 1;
    Uint32 cfr0_dth_sync0_a0_intr_status : 1;
    Uint32 cfr0_dth_pwr_cng_a1_intr_status : 1;
    Uint32 cfr0_dth_pwr_cng_a0_intr_status : 1;
    Uint32 cfr0_agc_sync1_a1_intr_status : 1;
    Uint32 cfr0_agc_sync0_a1_intr_status : 1;
    Uint32 cfr0_agc_sync1_a0_intr_status : 1;
    Uint32 cfr0_agc_sync0_a0_intr_status : 1;
    Uint32 cfr0_agc_max_out_th_a1_intr_status : 1;
    Uint32 cfr0_agc_max_in_th_a1_intr_status : 1;
    Uint32 cfr0_agc_min_out_th_a1_intr_status : 1;
    Uint32 cfr0_agc_min_in_th_a1_intr_status : 1;
    Uint32 cfr0_agc_max_out_th_a0_intr_status : 1;
    Uint32 cfr0_agc_max_in_th_a0_intr_status : 1;
    Uint32 cfr0_agc_min_out_th_a0_intr_status : 1;
    Uint32 cfr0_agc_min_in_th_a0_intr_status : 1;
#else 
    Uint32 cfr0_agc_min_in_th_a0_intr_status : 1;
    Uint32 cfr0_agc_min_out_th_a0_intr_status : 1;
    Uint32 cfr0_agc_max_in_th_a0_intr_status : 1;
    Uint32 cfr0_agc_max_out_th_a0_intr_status : 1;
    Uint32 cfr0_agc_min_in_th_a1_intr_status : 1;
    Uint32 cfr0_agc_min_out_th_a1_intr_status : 1;
    Uint32 cfr0_agc_max_in_th_a1_intr_status : 1;
    Uint32 cfr0_agc_max_out_th_a1_intr_status : 1;
    Uint32 cfr0_agc_sync0_a0_intr_status : 1;
    Uint32 cfr0_agc_sync1_a0_intr_status : 1;
    Uint32 cfr0_agc_sync0_a1_intr_status : 1;
    Uint32 cfr0_agc_sync1_a1_intr_status : 1;
    Uint32 cfr0_dth_pwr_cng_a0_intr_status : 1;
    Uint32 cfr0_dth_pwr_cng_a1_intr_status : 1;
    Uint32 cfr0_dth_sync0_a0_intr_status : 1;
    Uint32 cfr0_dth_sync0_a1_intr_status : 1;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG;

/* cfr0_agc_min_in_th_a0_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_IN_TH_A0_INTR_STATUS_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_IN_TH_A0_INTR_STATUS_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_IN_TH_A0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_min_out_th_a0_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_OUT_TH_A0_INTR_STATUS_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_OUT_TH_A0_INTR_STATUS_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_OUT_TH_A0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_max_in_th_a0_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_IN_TH_A0_INTR_STATUS_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_IN_TH_A0_INTR_STATUS_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_IN_TH_A0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_max_out_th_a0_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_OUT_TH_A0_INTR_STATUS_MASK (0x00000008u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_OUT_TH_A0_INTR_STATUS_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_OUT_TH_A0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_min_in_th_a1_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_IN_TH_A1_INTR_STATUS_MASK (0x00000010u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_IN_TH_A1_INTR_STATUS_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_IN_TH_A1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_min_out_th_a1_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_OUT_TH_A1_INTR_STATUS_MASK (0x00000020u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_OUT_TH_A1_INTR_STATUS_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MIN_OUT_TH_A1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_max_in_th_a1_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_IN_TH_A1_INTR_STATUS_MASK (0x00000040u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_IN_TH_A1_INTR_STATUS_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_IN_TH_A1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_max_out_th_a1_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_OUT_TH_A1_INTR_STATUS_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_OUT_TH_A1_INTR_STATUS_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_MAX_OUT_TH_A1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_sync0_a0_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC0_A0_INTR_STATUS_MASK (0x00000100u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC0_A0_INTR_STATUS_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC0_A0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_sync1_a0_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC1_A0_INTR_STATUS_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC1_A0_INTR_STATUS_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC1_A0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_sync0_a1_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC0_A1_INTR_STATUS_MASK (0x00000400u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC0_A1_INTR_STATUS_SHIFT (0x0000000Au)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC0_A1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_agc_sync1_a1_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC1_A1_INTR_STATUS_MASK (0x00000800u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC1_A1_INTR_STATUS_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_AGC_SYNC1_A1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a0_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_PWR_CNG_A0_INTR_STATUS_MASK (0x00001000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_PWR_CNG_A0_INTR_STATUS_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_PWR_CNG_A0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a1_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_PWR_CNG_A1_INTR_STATUS_MASK (0x00002000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_PWR_CNG_A1_INTR_STATUS_SHIFT (0x0000000Du)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_PWR_CNG_A1_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a0_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_SYNC0_A0_INTR_STATUS_MASK (0x00004000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_SYNC0_A0_INTR_STATUS_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_SYNC0_A0_INTR_STATUS_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a1_intr_status */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_SYNC0_A1_INTR_STATUS_MASK (0x00008000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_SYNC0_A1_INTR_STATUS_SHIFT (0x0000000Fu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_CFR0_DTH_SYNC0_A1_INTR_STATUS_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_ADDR (0x0000004Cu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_STATUS_REG_RESETVAL (0x00000000u)

/* CFR_PDC_INTR_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 cfr0_pdc1_luts_updt_done_intr_force : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s1_intr_force : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s0_intr_force : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s1_intr_force : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s0_intr_force : 1;
    Uint32 cfr0_pdc0_luts_updt_done_intr_force : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s1_intr_force : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s0_intr_force : 1;
    Uint32 cfr0_pdc0_no_cpge_a0s1_intr_force : 1;
    Uint32 cfr0_pdc0_no_cpge_a0s0_intr_force : 1;
#else 
    Uint32 cfr0_pdc0_no_cpge_a0s0_intr_force : 1;
    Uint32 cfr0_pdc0_no_cpge_a0s1_intr_force : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s0_intr_force : 1;
    Uint32 cfr0_pdc0_no_cpge_a1s1_intr_force : 1;
    Uint32 cfr0_pdc0_luts_updt_done_intr_force : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s0_intr_force : 1;
    Uint32 cfr0_pdc1_no_cpge_a0s1_intr_force : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s0_intr_force : 1;
    Uint32 cfr0_pdc1_no_cpge_a1s1_intr_force : 1;
    Uint32 cfr0_pdc1_luts_updt_done_intr_force : 1;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG;

/* cfr0_pdc0_no_cpge_a0s0_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A0S0_INTR_FORCE_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A0S0_INTR_FORCE_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A0S0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_pdc0_no_cpge_a0s1_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A0S1_INTR_FORCE_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A0S1_INTR_FORCE_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A0S1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_pdc0_no_cpge_a1s0_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A1S0_INTR_FORCE_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A1S0_INTR_FORCE_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A1S0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_pdc0_no_cpge_a1s1_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A1S1_INTR_FORCE_MASK (0x00000008u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A1S1_INTR_FORCE_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_NO_CPGE_A1S1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_pdc0_luts_updt_done_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_LUTS_UPDT_DONE_INTR_FORCE_MASK (0x00000010u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_LUTS_UPDT_DONE_INTR_FORCE_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC0_LUTS_UPDT_DONE_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a0s0_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A0S0_INTR_FORCE_MASK (0x00000020u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A0S0_INTR_FORCE_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A0S0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a0s1_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A0S1_INTR_FORCE_MASK (0x00000040u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A0S1_INTR_FORCE_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A0S1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a1s0_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A1S0_INTR_FORCE_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A1S0_INTR_FORCE_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A1S0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_pdc1_no_cpge_a1s1_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A1S1_INTR_FORCE_MASK (0x00000100u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A1S1_INTR_FORCE_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_NO_CPGE_A1S1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_pdc1_luts_updt_done_intr_force */
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_LUTS_UPDT_DONE_INTR_FORCE_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_LUTS_UPDT_DONE_INTR_FORCE_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_CFR0_PDC1_LUTS_UPDT_DONE_INTR_FORCE_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_ADDR (0x00000050u)
#define CSL_DFE_CFR_CFR_PDC_INTR_FORCE_REG_RESETVAL (0x00000000u)

/* CFR_AGC_DTH_INTR_FORCE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_dth_sync0_a1_intr_force : 1;
    Uint32 cfr0_dth_sync0_a0_intr_force : 1;
    Uint32 cfr0_dth_pwr_cng_a1_intr_force : 1;
    Uint32 cfr0_dth_pwr_cng_a0_intr_force : 1;
    Uint32 cfr0_agc_sync1_a1_intr_force : 1;
    Uint32 cfr0_agc_sync0_a1_intr_force : 1;
    Uint32 cfr0_agc_sync1_a0_intr_force : 1;
    Uint32 cfr0_agc_sync0_a0_intr_force : 1;
    Uint32 cfr0_agc_max_out_th_a1_intr_force : 1;
    Uint32 cfr0_agc_max_in_th_a1_intr_force : 1;
    Uint32 cfr0_agc_min_out_th_a1_intr_force : 1;
    Uint32 cfr0_agc_min_in_th_a1_intr_force : 1;
    Uint32 cfr0_agc_max_out_th_a0_intr_force : 1;
    Uint32 cfr0_agc_max_in_th_a0_intr_force : 1;
    Uint32 cfr0_agc_min_out_th_a0_intr_force : 1;
    Uint32 cfr0_agc_min_in_th_a0_intr_force : 1;
#else 
    Uint32 cfr0_agc_min_in_th_a0_intr_force : 1;
    Uint32 cfr0_agc_min_out_th_a0_intr_force : 1;
    Uint32 cfr0_agc_max_in_th_a0_intr_force : 1;
    Uint32 cfr0_agc_max_out_th_a0_intr_force : 1;
    Uint32 cfr0_agc_min_in_th_a1_intr_force : 1;
    Uint32 cfr0_agc_min_out_th_a1_intr_force : 1;
    Uint32 cfr0_agc_max_in_th_a1_intr_force : 1;
    Uint32 cfr0_agc_max_out_th_a1_intr_force : 1;
    Uint32 cfr0_agc_sync0_a0_intr_force : 1;
    Uint32 cfr0_agc_sync1_a0_intr_force : 1;
    Uint32 cfr0_agc_sync0_a1_intr_force : 1;
    Uint32 cfr0_agc_sync1_a1_intr_force : 1;
    Uint32 cfr0_dth_pwr_cng_a0_intr_force : 1;
    Uint32 cfr0_dth_pwr_cng_a1_intr_force : 1;
    Uint32 cfr0_dth_sync0_a0_intr_force : 1;
    Uint32 cfr0_dth_sync0_a1_intr_force : 1;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG;

/* cfr0_agc_min_in_th_a0_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_IN_TH_A0_INTR_FORCE_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_IN_TH_A0_INTR_FORCE_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_IN_TH_A0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_min_out_th_a0_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_OUT_TH_A0_INTR_FORCE_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_OUT_TH_A0_INTR_FORCE_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_OUT_TH_A0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_max_in_th_a0_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_IN_TH_A0_INTR_FORCE_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_IN_TH_A0_INTR_FORCE_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_IN_TH_A0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_max_out_th_a0_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_OUT_TH_A0_INTR_FORCE_MASK (0x00000008u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_OUT_TH_A0_INTR_FORCE_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_OUT_TH_A0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_min_in_th_a1_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_IN_TH_A1_INTR_FORCE_MASK (0x00000010u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_IN_TH_A1_INTR_FORCE_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_IN_TH_A1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_min_out_th_a1_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_OUT_TH_A1_INTR_FORCE_MASK (0x00000020u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_OUT_TH_A1_INTR_FORCE_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MIN_OUT_TH_A1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_max_in_th_a1_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_IN_TH_A1_INTR_FORCE_MASK (0x00000040u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_IN_TH_A1_INTR_FORCE_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_IN_TH_A1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_max_out_th_a1_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_OUT_TH_A1_INTR_FORCE_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_OUT_TH_A1_INTR_FORCE_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_MAX_OUT_TH_A1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_sync0_a0_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC0_A0_INTR_FORCE_MASK (0x00000100u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC0_A0_INTR_FORCE_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC0_A0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_sync1_a0_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC1_A0_INTR_FORCE_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC1_A0_INTR_FORCE_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC1_A0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_sync0_a1_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC0_A1_INTR_FORCE_MASK (0x00000400u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC0_A1_INTR_FORCE_SHIFT (0x0000000Au)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC0_A1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_agc_sync1_a1_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC1_A1_INTR_FORCE_MASK (0x00000800u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC1_A1_INTR_FORCE_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_AGC_SYNC1_A1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a0_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_PWR_CNG_A0_INTR_FORCE_MASK (0x00001000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_PWR_CNG_A0_INTR_FORCE_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_PWR_CNG_A0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a1_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_PWR_CNG_A1_INTR_FORCE_MASK (0x00002000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_PWR_CNG_A1_INTR_FORCE_SHIFT (0x0000000Du)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_PWR_CNG_A1_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a0_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_SYNC0_A0_INTR_FORCE_MASK (0x00004000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_SYNC0_A0_INTR_FORCE_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_SYNC0_A0_INTR_FORCE_RESETVAL (0x00000000u)

/* cfr0_dth_sync0_a1_intr_force */
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_SYNC0_A1_INTR_FORCE_MASK (0x00008000u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_SYNC0_A1_INTR_FORCE_SHIFT (0x0000000Fu)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_CFR0_DTH_SYNC0_A1_INTR_FORCE_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_ADDR (0x00000054u)
#define CSL_DFE_CFR_CFR_AGC_DTH_INTR_FORCE_REG_RESETVAL (0x00000000u)

/* CFR0_PDC0_WEIGHT_FACTOR_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 cfr0_weight_factor_1 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cfr0_weight_factor_0 : 5;
#else 
    Uint32 cfr0_weight_factor_0 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cfr0_weight_factor_1 : 5;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_WEIGHT_FACTOR_A0_REG;

/* Static weight factor for antenna #0 stage 0 */
#define CSL_DFE_CFR_CFR0_PDC0_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_0_MASK (0x0000001Fu)
#define CSL_DFE_CFR_CFR0_PDC0_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_0_RESETVAL (0x00000010u)

/* Static weight factor for antenna #0 stage 1 */
#define CSL_DFE_CFR_CFR0_PDC0_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_1_MASK (0x00001F00u)
#define CSL_DFE_CFR_CFR0_PDC0_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_PDC0_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_1_RESETVAL (0x00000010u)

#define CSL_DFE_CFR_CFR0_PDC0_WEIGHT_FACTOR_A0_REG_ADDR (0x00000200u)
#define CSL_DFE_CFR_CFR0_PDC0_WEIGHT_FACTOR_A0_REG_RESETVAL (0x00001010u)

/* CFR1_PDC0_WEIGHT_FACTOR_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 cfr1_weight_factor_1 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cfr1_weight_factor_0 : 5;
#else 
    Uint32 cfr1_weight_factor_0 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cfr1_weight_factor_1 : 5;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_WEIGHT_FACTOR_A1_REG;

/* Static weight factor for antenna #1 stage 0 */
#define CSL_DFE_CFR_CFR1_PDC0_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_0_MASK (0x0000001Fu)
#define CSL_DFE_CFR_CFR1_PDC0_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_0_RESETVAL (0x00000010u)

/* Static weight factor for antenna #1 stage 1 */
#define CSL_DFE_CFR_CFR1_PDC0_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_1_MASK (0x00001F00u)
#define CSL_DFE_CFR_CFR1_PDC0_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_PDC0_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_1_RESETVAL (0x00000010u)

#define CSL_DFE_CFR_CFR1_PDC0_WEIGHT_FACTOR_A1_REG_ADDR (0x00000204u)
#define CSL_DFE_CFR_CFR1_PDC0_WEIGHT_FACTOR_A1_REG_RESETVAL (0x00001010u)

/* CFR0_PDC0_LUTS_UPDT_PRMS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 cfr0_eng_reloaddelay : 13;
#else 
    Uint32 cfr0_eng_reloaddelay : 13;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_LUTS_UPDT_PRMS_REG;

/* Wait time (In clock cycles) after LUT swap before allowing writing to the new shadow */
#define CSL_DFE_CFR_CFR0_PDC0_LUTS_UPDT_PRMS_REG_CFR0_ENG_RELOADDELAY_MASK (0x00001FFFu)
#define CSL_DFE_CFR_CFR0_PDC0_LUTS_UPDT_PRMS_REG_CFR0_ENG_RELOADDELAY_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_LUTS_UPDT_PRMS_REG_CFR0_ENG_RELOADDELAY_RESETVAL (0x00001FFFu)

#define CSL_DFE_CFR_CFR0_PDC0_LUTS_UPDT_PRMS_REG_ADDR (0x00000208u)
#define CSL_DFE_CFR_CFR0_PDC0_LUTS_UPDT_PRMS_REG_RESETVAL (0x00001FFFu)

/* CFR0_PDC0_MODE_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_cp_complexflag_for_pool_0_s1 : 2;
    Uint32 cfr0_cp_winlut_symodd_for_pool_0_s1 : 3;
    Uint32 cfr0_cp_firlut_symodd_for_pool_0_s1 : 3;
    Uint32 cfr0_cp_complexflag_for_pool_0 : 2;
    Uint32 cfr0_cp_winlut_symodd_for_pool_0 : 3;
    Uint32 cfr0_cp_firlut_symodd_for_pool_0 : 3;
#else 
    Uint32 cfr0_cp_firlut_symodd_for_pool_0 : 3;
    Uint32 cfr0_cp_winlut_symodd_for_pool_0 : 3;
    Uint32 cfr0_cp_complexflag_for_pool_0 : 2;
    Uint32 cfr0_cp_firlut_symodd_for_pool_0_s1 : 3;
    Uint32 cfr0_cp_winlut_symodd_for_pool_0_s1 : 3;
    Uint32 cfr0_cp_complexflag_for_pool_0_s1 : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG;

/* Antenna #0, stage 0: */
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_FIRLUT_SYMODD_FOR_POOL_0_MASK (0x00000007u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_FIRLUT_SYMODD_FOR_POOL_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_FIRLUT_SYMODD_FOR_POOL_0_RESETVAL (0x00000000u)

/* Antenna #0, stage 0: */
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_WINLUT_SYMODD_FOR_POOL_0_MASK (0x00000038u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_WINLUT_SYMODD_FOR_POOL_0_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_WINLUT_SYMODD_FOR_POOL_0_RESETVAL (0x00000000u)

/* antenna #0, stage0: */
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_COMPLEXFLAG_FOR_POOL_0_MASK (0x000000C0u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_COMPLEXFLAG_FOR_POOL_0_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_COMPLEXFLAG_FOR_POOL_0_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_FIRLUT_SYMODD_FOR_POOL_0_S1_MASK (0x00000700u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_FIRLUT_SYMODD_FOR_POOL_0_S1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_FIRLUT_SYMODD_FOR_POOL_0_S1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_WINLUT_SYMODD_FOR_POOL_0_S1_MASK (0x00003800u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_WINLUT_SYMODD_FOR_POOL_0_S1_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_WINLUT_SYMODD_FOR_POOL_0_S1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_COMPLEXFLAG_FOR_POOL_0_S1_MASK (0x0000C000u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_COMPLEXFLAG_FOR_POOL_0_S1_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_CFR0_CP_COMPLEXFLAG_FOR_POOL_0_S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_ADDR (0x00000210u)
#define CSL_DFE_CFR_CFR0_PDC0_MODE_A0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC0_MODE_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_cp_complexflag_for_pool_0_s1 : 2;
    Uint32 cfr1_cp_winlut_symodd_for_pool_0_s1 : 3;
    Uint32 cfr1_cp_firlut_symodd_for_pool_0_s1 : 3;
    Uint32 cfr1_cp_complexflag_for_pool_0 : 2;
    Uint32 cfr1_cp_winlut_symodd_for_pool_0 : 3;
    Uint32 cfr1_cp_firlut_symodd_for_pool_0 : 3;
#else 
    Uint32 cfr1_cp_firlut_symodd_for_pool_0 : 3;
    Uint32 cfr1_cp_winlut_symodd_for_pool_0 : 3;
    Uint32 cfr1_cp_complexflag_for_pool_0 : 2;
    Uint32 cfr1_cp_firlut_symodd_for_pool_0_s1 : 3;
    Uint32 cfr1_cp_winlut_symodd_for_pool_0_s1 : 3;
    Uint32 cfr1_cp_complexflag_for_pool_0_s1 : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG;

/* Antenna #1, stage 0: */
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_0_MASK (0x00000007u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_0_RESETVAL (0x00000000u)

/* Antenna #1, stage 0: */
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_0_MASK (0x00000038u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_0_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_0_RESETVAL (0x00000000u)

/* antenna #1, stage0: */
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_0_MASK (0x000000C0u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_0_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_0_RESETVAL (0x00000000u)

/* INTERNAL ONLY:: */
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_0_S1_MASK (0x00000700u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_0_S1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_0_S1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_0_S1_MASK (0x00003800u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_0_S1_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_0_S1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_0_S1_MASK (0x0000C000u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_0_S1_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_0_S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_ADDR (0x00000214u)
#define CSL_DFE_CFR_CFR1_PDC0_MODE_A1_REG_RESETVAL (0x00000000u)

/* CFR0_PDC0_MAX_M1_CP_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 cfr0_eng_max_cp_per_stage_1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cfr0_eng_max_cp_per_stage_0 : 6;
#else 
    Uint32 cfr0_eng_max_cp_per_stage_0 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cfr0_eng_max_cp_per_stage_1 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_MAX_M1_CP_A0_REG;

/* Maximum number less one of cancellers that can be allocated for the 1st stage of this PDC for antenna #0. If more cancellers then physical LUT ports are allowed for the any stage, it enables borrowing cancellers from the other stage. */
#define CSL_DFE_CFR_CFR0_PDC0_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_0_MASK (0x0000003Fu)
#define CSL_DFE_CFR_CFR0_PDC0_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_0_RESETVAL (0x00000007u)

/* Maximum number less one of cancellers that can be allocated for the 2nd stage of this PDC for antenna #0. If more cancellers then physical LUT ports are allowed for the any stage, it enables borrowing cancellers from the other stage. */
#define CSL_DFE_CFR_CFR0_PDC0_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_1_MASK (0x00003F00u)
#define CSL_DFE_CFR_CFR0_PDC0_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_PDC0_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_1_RESETVAL (0x00000007u)

#define CSL_DFE_CFR_CFR0_PDC0_MAX_M1_CP_A0_REG_ADDR (0x00000218u)
#define CSL_DFE_CFR_CFR0_PDC0_MAX_M1_CP_A0_REG_RESETVAL (0x00000707u)

/* CFR1_PDC0_MAX_M1_CP_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 cfr1_eng_max_cp_per_stage_1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cfr1_eng_max_cp_per_stage_0 : 6;
#else 
    Uint32 cfr1_eng_max_cp_per_stage_0 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cfr1_eng_max_cp_per_stage_1 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_MAX_M1_CP_A1_REG;

/* Maximum number less one of cancellers that can be allocated for the 1st stage of this PDC for antenna #1. If more cancellers then physical LUT ports are allowed for the any stage, it enables borrowing cancellers from the other stage. */
#define CSL_DFE_CFR_CFR1_PDC0_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_0_MASK (0x0000003Fu)
#define CSL_DFE_CFR_CFR1_PDC0_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_0_RESETVAL (0x00000007u)

/* Maximum number less one of cancellers that can be allocated for the 2nd stage of this PDC for antenna #1. If more cancellers then physical LUT ports are allowed for the any stage, it enables borrowing cancellers from the other stage. */
#define CSL_DFE_CFR_CFR1_PDC0_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_1_MASK (0x00003F00u)
#define CSL_DFE_CFR_CFR1_PDC0_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_PDC0_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_1_RESETVAL (0x00000007u)

#define CSL_DFE_CFR_CFR1_PDC0_MAX_M1_CP_A1_REG_ADDR (0x0000021Cu)
#define CSL_DFE_CFR_CFR1_PDC0_MAX_M1_CP_A1_REG_RESETVAL (0x00000707u)

/* CFR0_PDC0_CP_WINLUTSTART_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr0_cp_winlut_startaddr_for_pool_0 : 8;
#else 
    Uint32 cfr0_cp_winlut_startaddr_for_pool_0 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_CP_WINLUTSTART_A0_REG;

/* Address in LUT of the first coefficient to be used for the cancellers in stage 0 in antenna #0 for the WIN CPGE. */
#define CSL_DFE_CFR_CFR0_PDC0_CP_WINLUTSTART_A0_REG_CFR0_CP_WINLUT_STARTADDR_FOR_POOL_0_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR0_PDC0_CP_WINLUTSTART_A0_REG_CFR0_CP_WINLUT_STARTADDR_FOR_POOL_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_CP_WINLUTSTART_A0_REG_CFR0_CP_WINLUT_STARTADDR_FOR_POOL_0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC0_CP_WINLUTSTART_A0_REG_ADDR (0x00000220u)
#define CSL_DFE_CFR_CFR0_PDC0_CP_WINLUTSTART_A0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC0_CP_WINLUTSTART_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr1_cp_winlut_startaddr_for_pool_0 : 8;
#else 
    Uint32 cfr1_cp_winlut_startaddr_for_pool_0 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_CP_WINLUTSTART_A1_REG;

/* Address in LUT of the first coefficient to be used for the cancellers in stage 0 in antenna #1 for the WIN CPGE. */
#define CSL_DFE_CFR_CFR1_PDC0_CP_WINLUTSTART_A1_REG_CFR1_CP_WINLUT_STARTADDR_FOR_POOL_0_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR1_PDC0_CP_WINLUTSTART_A1_REG_CFR1_CP_WINLUT_STARTADDR_FOR_POOL_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_CP_WINLUTSTART_A1_REG_CFR1_CP_WINLUT_STARTADDR_FOR_POOL_0_RESETVAL (0x00000080u)

#define CSL_DFE_CFR_CFR1_PDC0_CP_WINLUTSTART_A1_REG_ADDR (0x00000224u)
#define CSL_DFE_CFR_CFR1_PDC0_CP_WINLUTSTART_A1_REG_RESETVAL (0x00000080u)

/* CFR0_PDC0_CP_FIRTLUTSTART_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr0_cp_firlut_startaddr_for_pool_0 : 8;
#else 
    Uint32 cfr0_cp_firlut_startaddr_for_pool_0 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_CP_FIRTLUTSTART_A0_REG;

/* Address in LUT of the first coefficient to be used for the cancellers in stage 0 in antenna #0 for the FIR CPGE. */
#define CSL_DFE_CFR_CFR0_PDC0_CP_FIRTLUTSTART_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_0_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR0_PDC0_CP_FIRTLUTSTART_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_CP_FIRTLUTSTART_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC0_CP_FIRTLUTSTART_A0_REG_ADDR (0x00000228u)
#define CSL_DFE_CFR_CFR0_PDC0_CP_FIRTLUTSTART_A0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC0_CP_FIRTLUTSTART_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr1_cp_firlut_startaddr_for_pool_0 : 8;
#else 
    Uint32 cfr1_cp_firlut_startaddr_for_pool_0 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_CP_FIRTLUTSTART_A1_REG;

/* Address in LUT of the first coefficient to be used for the cancellers in stage 0 in antenna #1 for the FIR CPGE. */
#define CSL_DFE_CFR_CFR1_PDC0_CP_FIRTLUTSTART_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_0_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR1_PDC0_CP_FIRTLUTSTART_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_CP_FIRTLUTSTART_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_0_RESETVAL (0x00000080u)

#define CSL_DFE_CFR_CFR1_PDC0_CP_FIRTLUTSTART_A1_REG_ADDR (0x0000022Cu)
#define CSL_DFE_CFR_CFR1_PDC0_CP_FIRTLUTSTART_A1_REG_RESETVAL (0x00000080u)

/* CFR0_PDC0_CP_LUTLENGTH_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr0_eng_cp_size_for_pool_0 : 8;
#else 
    Uint32 cfr0_eng_cp_size_for_pool_0 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_CP_LUTLENGTH_A0_REG;

/* Length of the cancellers in stage 0 in antenna #0. If symmetric or asymmetric and even, the actual length will be double, and if symmetric or asymmetric and odd, the actual length will be double plus one. */
#define CSL_DFE_CFR_CFR0_PDC0_CP_LUTLENGTH_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_0_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR0_PDC0_CP_LUTLENGTH_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_CP_LUTLENGTH_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_0_RESETVAL (0x000000FFu)

#define CSL_DFE_CFR_CFR0_PDC0_CP_LUTLENGTH_A0_REG_ADDR (0x00000230u)
#define CSL_DFE_CFR_CFR0_PDC0_CP_LUTLENGTH_A0_REG_RESETVAL (0x000000FFu)

/* CFR1_PDC0_CP_LUTLENGTH_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr1_eng_cp_size_for_pool_0 : 8;
#else 
    Uint32 cfr1_eng_cp_size_for_pool_0 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_CP_LUTLENGTH_A1_REG;

/* Length of the cancellers in stage 0 in antenna #1. If symmetric or asymmetric and even, the actual length will be double, and if symmetric or asymmetric and odd, the actual length will be double plus one. */
#define CSL_DFE_CFR_CFR1_PDC0_CP_LUTLENGTH_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_0_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR1_PDC0_CP_LUTLENGTH_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_CP_LUTLENGTH_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_0_RESETVAL (0x000000FFu)

#define CSL_DFE_CFR_CFR1_PDC0_CP_LUTLENGTH_A1_REG_ADDR (0x00000234u)
#define CSL_DFE_CFR_CFR1_PDC0_CP_LUTLENGTH_A1_REG_RESETVAL (0x000000FFu)

/* CFR0_PDC0_STAT_PK_ALLOC_A0S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_pk_alloc_a0s0 : 16;
#else 
    Uint32 pdc0_stat_pk_alloc_a0s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A0S0_REG;

/* Peaks allocated for pdc0 antenna 0 stage 0 */
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A0S0_REG_PDC0_STAT_PK_ALLOC_A0S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A0S0_REG_PDC0_STAT_PK_ALLOC_A0S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A0S0_REG_PDC0_STAT_PK_ALLOC_A0S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A0S0_REG_ADDR (0x00000240u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A0S0_REG_RESETVAL (0x00000000u)

/* CFR0_PDC0_STAT_PK_ALLOC_A1S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_pk_alloc_a1s0 : 16;
#else 
    Uint32 pdc0_stat_pk_alloc_a1s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A1S0_REG;

/* Peaks allocated for pdc0 antenna 1 stage 0 */
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A1S0_REG_PDC0_STAT_PK_ALLOC_A1S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A1S0_REG_PDC0_STAT_PK_ALLOC_A1S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A1S0_REG_PDC0_STAT_PK_ALLOC_A1S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A1S0_REG_ADDR (0x00000244u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_ALLOC_A1S0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC0_STAT_PK_ALLOC_A0S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_pk_alloc_a0s1 : 16;
#else 
    Uint32 pdc0_stat_pk_alloc_a0s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A0S1_REG;

/* Peaks allocated for pdc0 antenna 0 stage 1 */
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A0S1_REG_PDC0_STAT_PK_ALLOC_A0S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A0S1_REG_PDC0_STAT_PK_ALLOC_A0S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A0S1_REG_PDC0_STAT_PK_ALLOC_A0S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A0S1_REG_ADDR (0x00000248u)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A0S1_REG_RESETVAL (0x00000000u)

/* CFR1_PDC0_STAT_PK_ALLOC_A1S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_pk_alloc_a1s1 : 16;
#else 
    Uint32 pdc0_stat_pk_alloc_a1s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A1S1_REG;

/* Peaks allocated for pdc0 antenna 1 stage 1 */
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A1S1_REG_PDC0_STAT_PK_ALLOC_A1S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A1S1_REG_PDC0_STAT_PK_ALLOC_A1S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A1S1_REG_PDC0_STAT_PK_ALLOC_A1S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A1S1_REG_ADDR (0x0000024Cu)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_ALLOC_A1S1_REG_RESETVAL (0x00000000u)

/* CFR0_PDC0_STAT_PK_MISSED_A0S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_pk_missed_a0s0 : 16;
#else 
    Uint32 pdc0_stat_pk_missed_a0s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A0S0_REG;

/* Peaks missed for pdc0 antenna 0 stage 0 */
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A0S0_REG_PDC0_STAT_PK_MISSED_A0S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A0S0_REG_PDC0_STAT_PK_MISSED_A0S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A0S0_REG_PDC0_STAT_PK_MISSED_A0S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A0S0_REG_ADDR (0x00000250u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A0S0_REG_RESETVAL (0x00000000u)

/* CFR0_PDC0_STAT_PK_MISSED_A1S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_pk_missed_a1s0 : 16;
#else 
    Uint32 pdc0_stat_pk_missed_a1s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A1S0_REG;

/* Peaks missed for pdc0 antenna 1 stage 0 */
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A1S0_REG_PDC0_STAT_PK_MISSED_A1S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A1S0_REG_PDC0_STAT_PK_MISSED_A1S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A1S0_REG_PDC0_STAT_PK_MISSED_A1S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A1S0_REG_ADDR (0x00000254u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_PK_MISSED_A1S0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC0_STAT_PK_MISSED_A0S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_pk_missed_a0s1 : 16;
#else 
    Uint32 pdc0_stat_pk_missed_a0s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A0S1_REG;

/* Peaks missed for pdc0 antenna 0 stage 1 */
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A0S1_REG_PDC0_STAT_PK_MISSED_A0S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A0S1_REG_PDC0_STAT_PK_MISSED_A0S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A0S1_REG_PDC0_STAT_PK_MISSED_A0S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A0S1_REG_ADDR (0x00000258u)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A0S1_REG_RESETVAL (0x00000000u)

/* CFR1_PDC0_STAT_PK_MISSED_A1S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_pk_missed_a1s1 : 16;
#else 
    Uint32 pdc0_stat_pk_missed_a1s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A1S1_REG;

/* Peaks missed for pdc0 antenna 1 stage 1 */
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A1S1_REG_PDC0_STAT_PK_MISSED_A1S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A1S1_REG_PDC0_STAT_PK_MISSED_A1S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A1S1_REG_PDC0_STAT_PK_MISSED_A1S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A1S1_REG_ADDR (0x0000025Cu)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_PK_MISSED_A1S1_REG_RESETVAL (0x00000000u)

/* CFR0_PDC0_STAT_DISTANCE_A0S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_distance_a0s0 : 16;
#else 
    Uint32 pdc0_stat_distance_a0s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S0_REG;

/* Peak minimum distance for pdc0 antenna 0 stage 0 */
#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S0_REG_PDC0_STAT_DISTANCE_A0S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S0_REG_PDC0_STAT_DISTANCE_A0S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S0_REG_PDC0_STAT_DISTANCE_A0S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S0_REG_ADDR (0x00000260u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC0_STAT_DISTANCE_A1S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_distance_a1s0 : 16;
#else 
    Uint32 pdc0_stat_distance_a1s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S0_REG;

/* Peak minimum distance for pdc0 antenna 1 stage 0 */
#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S0_REG_PDC0_STAT_DISTANCE_A1S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S0_REG_PDC0_STAT_DISTANCE_A1S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S0_REG_PDC0_STAT_DISTANCE_A1S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S0_REG_ADDR (0x00000264u)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S0_REG_RESETVAL (0x00000000u)

/* CFR0_PDC0_STAT_DISTANCE_A0S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_distance_a0s1 : 16;
#else 
    Uint32 pdc0_stat_distance_a0s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S1_REG;

/* Peak minimum distance for pdc0 antenna 0 stage 1 */
#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S1_REG_PDC0_STAT_DISTANCE_A0S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S1_REG_PDC0_STAT_DISTANCE_A0S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S1_REG_PDC0_STAT_DISTANCE_A0S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S1_REG_ADDR (0x00000268u)
#define CSL_DFE_CFR_CFR0_PDC0_STAT_DISTANCE_A0S1_REG_RESETVAL (0x00000000u)

/* CFR1_PDC0_STAT_DISTANCE_A1S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc0_stat_distance_a1s1 : 16;
#else 
    Uint32 pdc0_stat_distance_a1s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S1_REG;

/* Peak minimum distance for pdc0 antenna 1 stage 1 */
#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S1_REG_PDC0_STAT_DISTANCE_A1S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S1_REG_PDC0_STAT_DISTANCE_A1S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S1_REG_PDC0_STAT_DISTANCE_A1S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S1_REG_ADDR (0x0000026Cu)
#define CSL_DFE_CFR_CFR1_PDC0_STAT_DISTANCE_A1S1_REG_RESETVAL (0x00000000u)

/* CFR0_PDC1_WEIGHT_FACTOR_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 cfr0_weight_factor_3 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cfr0_weight_factor_2 : 5;
#else 
    Uint32 cfr0_weight_factor_2 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cfr0_weight_factor_3 : 5;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_WEIGHT_FACTOR_A0_REG;

/* Static weight factor for antenna #0 stage 2 */
#define CSL_DFE_CFR_CFR0_PDC1_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_2_MASK (0x0000001Fu)
#define CSL_DFE_CFR_CFR0_PDC1_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_2_RESETVAL (0x00000010u)

/* Static weight factor for antenna #0 stage 3 */
#define CSL_DFE_CFR_CFR0_PDC1_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_3_MASK (0x00001F00u)
#define CSL_DFE_CFR_CFR0_PDC1_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_3_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_PDC1_WEIGHT_FACTOR_A0_REG_CFR0_WEIGHT_FACTOR_3_RESETVAL (0x00000010u)

#define CSL_DFE_CFR_CFR0_PDC1_WEIGHT_FACTOR_A0_REG_ADDR (0x00000280u)
#define CSL_DFE_CFR_CFR0_PDC1_WEIGHT_FACTOR_A0_REG_RESETVAL (0x00001010u)

/* CFR1_PDC1_WEIGHT_FACTOR_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 19;
    Uint32 cfr1_weight_factor_3 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cfr1_weight_factor_2 : 5;
#else 
    Uint32 cfr1_weight_factor_2 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cfr1_weight_factor_3 : 5;
    Uint32 rsvd1 : 19;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_WEIGHT_FACTOR_A1_REG;

/* Static weight factor for antenna #1 stage 2 */
#define CSL_DFE_CFR_CFR1_PDC1_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_2_MASK (0x0000001Fu)
#define CSL_DFE_CFR_CFR1_PDC1_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_2_RESETVAL (0x00000010u)

/* Static weight factor for antenna #1 stage 3 */
#define CSL_DFE_CFR_CFR1_PDC1_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_3_MASK (0x00001F00u)
#define CSL_DFE_CFR_CFR1_PDC1_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_3_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_PDC1_WEIGHT_FACTOR_A1_REG_CFR1_WEIGHT_FACTOR_3_RESETVAL (0x00000010u)

#define CSL_DFE_CFR_CFR1_PDC1_WEIGHT_FACTOR_A1_REG_ADDR (0x00000284u)
#define CSL_DFE_CFR_CFR1_PDC1_WEIGHT_FACTOR_A1_REG_RESETVAL (0x00001010u)

/* CFR0_PDC1_LUTS_UPDT_PRMS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 cfr0_eng_reloaddelay : 13;
#else 
    Uint32 cfr0_eng_reloaddelay : 13;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_LUTS_UPDT_PRMS_REG;

/* Wait time (In clock cycles) after LUT swap before allowing writing to the new shadow */
#define CSL_DFE_CFR_CFR0_PDC1_LUTS_UPDT_PRMS_REG_CFR0_ENG_RELOADDELAY_MASK (0x00001FFFu)
#define CSL_DFE_CFR_CFR0_PDC1_LUTS_UPDT_PRMS_REG_CFR0_ENG_RELOADDELAY_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_LUTS_UPDT_PRMS_REG_CFR0_ENG_RELOADDELAY_RESETVAL (0x00001FFFu)

#define CSL_DFE_CFR_CFR0_PDC1_LUTS_UPDT_PRMS_REG_ADDR (0x00000288u)
#define CSL_DFE_CFR_CFR0_PDC1_LUTS_UPDT_PRMS_REG_RESETVAL (0x00001FFFu)

/* CFR0_PDC1_MODE_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_cp_complexflag_for_pool_1_s1 : 2;
    Uint32 cfr1_cp_winlut_symodd_for_pool_1_s1 : 3;
    Uint32 cfr1_cp_firlut_symodd_for_pool_1_s1 : 3;
    Uint32 cfr0_cp_complexflag_for_pool_1 : 2;
    Uint32 cfr0_cp_winlut_symodd_for_pool_1 : 3;
    Uint32 cfr0_cp_firlut_symodd_for_pool_1 : 3;
#else 
    Uint32 cfr0_cp_firlut_symodd_for_pool_1 : 3;
    Uint32 cfr0_cp_winlut_symodd_for_pool_1 : 3;
    Uint32 cfr0_cp_complexflag_for_pool_1 : 2;
    Uint32 cfr1_cp_firlut_symodd_for_pool_1_s1 : 3;
    Uint32 cfr1_cp_winlut_symodd_for_pool_1_s1 : 3;
    Uint32 cfr1_cp_complexflag_for_pool_1_s1 : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG;

/* Antenna #0, stage 2: */
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR0_CP_FIRLUT_SYMODD_FOR_POOL_1_MASK (0x00000007u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR0_CP_FIRLUT_SYMODD_FOR_POOL_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR0_CP_FIRLUT_SYMODD_FOR_POOL_1_RESETVAL (0x00000000u)

/* Antenna #0, stage 2: */
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR0_CP_WINLUT_SYMODD_FOR_POOL_1_MASK (0x00000038u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR0_CP_WINLUT_SYMODD_FOR_POOL_1_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR0_CP_WINLUT_SYMODD_FOR_POOL_1_RESETVAL (0x00000000u)

/* antenna #0, stage2: */
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR0_CP_COMPLEXFLAG_FOR_POOL_1_MASK (0x000000C0u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR0_CP_COMPLEXFLAG_FOR_POOL_1_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR0_CP_COMPLEXFLAG_FOR_POOL_1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_1_S1_MASK (0x00000700u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_1_S1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_1_S1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_1_S1_MASK (0x00003800u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_1_S1_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_1_S1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_1_S1_MASK (0x0000C000u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_1_S1_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_1_S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_ADDR (0x00000290u)
#define CSL_DFE_CFR_CFR0_PDC1_MODE_A0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC1_MODE_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_cp_complexflag_for_pool_1_s1 : 2;
    Uint32 cfr1_cp_winlut_symodd_for_pool_1_s1 : 3;
    Uint32 cfr1_cp_firlut_symodd_for_pool_1_s1 : 3;
    Uint32 cfr1_cp_complexflag_for_pool_1 : 2;
    Uint32 cfr1_cp_winlut_symodd_for_pool_1 : 3;
    Uint32 cfr1_cp_firlut_symodd_for_pool_1 : 3;
#else 
    Uint32 cfr1_cp_firlut_symodd_for_pool_1 : 3;
    Uint32 cfr1_cp_winlut_symodd_for_pool_1 : 3;
    Uint32 cfr1_cp_complexflag_for_pool_1 : 2;
    Uint32 cfr1_cp_firlut_symodd_for_pool_1_s1 : 3;
    Uint32 cfr1_cp_winlut_symodd_for_pool_1_s1 : 3;
    Uint32 cfr1_cp_complexflag_for_pool_1_s1 : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG;

/* Antenna #1, stage 2: */
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_1_MASK (0x00000007u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_1_RESETVAL (0x00000000u)

/* Antenna #1, stage 2: */
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_1_MASK (0x00000038u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_1_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_1_RESETVAL (0x00000000u)

/* antenna #1, stage2: */
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_1_MASK (0x000000C0u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_1_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_1_S1_MASK (0x00000700u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_1_S1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_FIRLUT_SYMODD_FOR_POOL_1_S1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_1_S1_MASK (0x00003800u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_1_S1_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_WINLUT_SYMODD_FOR_POOL_1_S1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_1_S1_MASK (0x0000C000u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_1_S1_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_CFR1_CP_COMPLEXFLAG_FOR_POOL_1_S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_ADDR (0x00000294u)
#define CSL_DFE_CFR_CFR1_PDC1_MODE_A1_REG_RESETVAL (0x00000000u)

/* CFR0_PDC1_MAX_M1_CP_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 cfr0_eng_max_cp_per_stage_1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cfr0_eng_max_cp_per_stage_0 : 6;
#else 
    Uint32 cfr0_eng_max_cp_per_stage_0 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cfr0_eng_max_cp_per_stage_1 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_MAX_M1_CP_A0_REG;

/* Maximum number less one of cancellers that can be allocated for the 1st stage of this PDC for antenna #0. If more cancellers then physical LUT ports are allowed for the any stage, it enables borrowing cancellers from the other stage. */
#define CSL_DFE_CFR_CFR0_PDC1_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_0_MASK (0x0000003Fu)
#define CSL_DFE_CFR_CFR0_PDC1_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_0_RESETVAL (0x00000007u)

/* Maximum number less one of cancellers that can be allocated for the 2nd stage of this PDC for antenna #0. If more cancellers then physical LUT ports are allowed for the any stage, it enables borrowing cancellers from the other stage. */
#define CSL_DFE_CFR_CFR0_PDC1_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_1_MASK (0x00003F00u)
#define CSL_DFE_CFR_CFR0_PDC1_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_PDC1_MAX_M1_CP_A0_REG_CFR0_ENG_MAX_CP_PER_STAGE_1_RESETVAL (0x00000007u)

#define CSL_DFE_CFR_CFR0_PDC1_MAX_M1_CP_A0_REG_ADDR (0x00000298u)
#define CSL_DFE_CFR_CFR0_PDC1_MAX_M1_CP_A0_REG_RESETVAL (0x00000707u)

/* CFR1_PDC1_MAX_M1_CP_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 18;
    Uint32 cfr1_eng_max_cp_per_stage_1 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cfr1_eng_max_cp_per_stage_0 : 6;
#else 
    Uint32 cfr1_eng_max_cp_per_stage_0 : 6;
    Uint32 rsvd0 : 2;
    Uint32 cfr1_eng_max_cp_per_stage_1 : 6;
    Uint32 rsvd1 : 18;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_MAX_M1_CP_A1_REG;

/* Maximum number less one of cancellers that can be allocated for the 1st stage of this PDC for antenna #1. If more cancellers then physical LUT ports are allowed for the any stage, it enables borrowing cancellers from the other stage. */
#define CSL_DFE_CFR_CFR1_PDC1_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_0_MASK (0x0000003Fu)
#define CSL_DFE_CFR_CFR1_PDC1_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_0_RESETVAL (0x00000007u)

/* Maximum number less one of cancellers that can be allocated for the 2nd stage of this PDC for antenna #1. If more cancellers then physical LUT ports are allowed for the any stage, it enables borrowing cancellers from the other stage. */
#define CSL_DFE_CFR_CFR1_PDC1_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_1_MASK (0x00003F00u)
#define CSL_DFE_CFR_CFR1_PDC1_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_PDC1_MAX_M1_CP_A1_REG_CFR1_ENG_MAX_CP_PER_STAGE_1_RESETVAL (0x00000007u)

#define CSL_DFE_CFR_CFR1_PDC1_MAX_M1_CP_A1_REG_ADDR (0x0000029Cu)
#define CSL_DFE_CFR_CFR1_PDC1_MAX_M1_CP_A1_REG_RESETVAL (0x00000707u)

/* CFR0_PDC1_CP_WINLUTSTART_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr0_cp_winlut_startaddr_for_pool_1 : 8;
#else 
    Uint32 cfr0_cp_winlut_startaddr_for_pool_1 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_CP_WINLUTSTART_A0_REG;

/* Address in LUT of the first coefficient to be used for the cancellers in stage 2 in antenna #0 for the WIN CPGE. */
#define CSL_DFE_CFR_CFR0_PDC1_CP_WINLUTSTART_A0_REG_CFR0_CP_WINLUT_STARTADDR_FOR_POOL_1_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR0_PDC1_CP_WINLUTSTART_A0_REG_CFR0_CP_WINLUT_STARTADDR_FOR_POOL_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_CP_WINLUTSTART_A0_REG_CFR0_CP_WINLUT_STARTADDR_FOR_POOL_1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC1_CP_WINLUTSTART_A0_REG_ADDR (0x000002A0u)
#define CSL_DFE_CFR_CFR0_PDC1_CP_WINLUTSTART_A0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC1_CP_WINLUTSTART_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr1_cp_winlut_startaddr_for_pool_1 : 8;
#else 
    Uint32 cfr1_cp_winlut_startaddr_for_pool_1 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_CP_WINLUTSTART_A1_REG;

/* Address in LUT of the first coefficient to be used for the cancellers in stage 2 in antenna #1 for the WIN CPGE. */
#define CSL_DFE_CFR_CFR1_PDC1_CP_WINLUTSTART_A1_REG_CFR1_CP_WINLUT_STARTADDR_FOR_POOL_1_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR1_PDC1_CP_WINLUTSTART_A1_REG_CFR1_CP_WINLUT_STARTADDR_FOR_POOL_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_CP_WINLUTSTART_A1_REG_CFR1_CP_WINLUT_STARTADDR_FOR_POOL_1_RESETVAL (0x00000080u)

#define CSL_DFE_CFR_CFR1_PDC1_CP_WINLUTSTART_A1_REG_ADDR (0x000002A4u)
#define CSL_DFE_CFR_CFR1_PDC1_CP_WINLUTSTART_A1_REG_RESETVAL (0x00000080u)

/* CFR0_PDC1_CP_FIRTLUTSTART_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr0_cp_firlut_startaddr_for_pool_1 : 8;
#else 
    Uint32 cfr0_cp_firlut_startaddr_for_pool_1 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_CP_FIRTLUTSTART_A0_REG;

/* Address in LUT of the first coefficient to be used for the cancellers in stage 2 in antenna #0 for the FIR CPGE. */
#define CSL_DFE_CFR_CFR0_PDC1_CP_FIRTLUTSTART_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_1_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR0_PDC1_CP_FIRTLUTSTART_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_CP_FIRTLUTSTART_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC1_CP_FIRTLUTSTART_A0_REG_ADDR (0x000002A8u)
#define CSL_DFE_CFR_CFR0_PDC1_CP_FIRTLUTSTART_A0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC1_CP_FIRTLUTSTART_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr1_cp_firlut_startaddr_for_pool_1 : 8;
#else 
    Uint32 cfr1_cp_firlut_startaddr_for_pool_1 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_CP_FIRTLUTSTART_A1_REG;

/* Address in LUT of the first coefficient to be used for the cancellers in stage 2 in antenna #1 for the FIR CPGE. */
#define CSL_DFE_CFR_CFR1_PDC1_CP_FIRTLUTSTART_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_1_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR1_PDC1_CP_FIRTLUTSTART_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_CP_FIRTLUTSTART_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_1_RESETVAL (0x00000080u)

#define CSL_DFE_CFR_CFR1_PDC1_CP_FIRTLUTSTART_A1_REG_ADDR (0x000002ACu)
#define CSL_DFE_CFR_CFR1_PDC1_CP_FIRTLUTSTART_A1_REG_RESETVAL (0x00000080u)

/* CFR0_PDC1_CP_LUTLENGTH_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr0_eng_cp_size_for_pool_1 : 8;
#else 
    Uint32 cfr0_eng_cp_size_for_pool_1 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_CP_LUTLENGTH_A0_REG;

/* Length of the cancellers in stage 2 in antenna #0. If symmetric or asymmetric and even, the actual length will be double, and if symmetric or asymmetric and odd, the actual length will be double plus one. */
#define CSL_DFE_CFR_CFR0_PDC1_CP_LUTLENGTH_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_1_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR0_PDC1_CP_LUTLENGTH_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_CP_LUTLENGTH_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_1_RESETVAL (0x000000FFu)

#define CSL_DFE_CFR_CFR0_PDC1_CP_LUTLENGTH_A0_REG_ADDR (0x000002B0u)
#define CSL_DFE_CFR_CFR0_PDC1_CP_LUTLENGTH_A0_REG_RESETVAL (0x000000FFu)

/* CFR1_PDC1_CP_LUTLENGTH_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cfr1_eng_cp_size_for_pool_1 : 8;
#else 
    Uint32 cfr1_eng_cp_size_for_pool_1 : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_CP_LUTLENGTH_A1_REG;

/* Length of the cancellers in stage 2 in antenna #1. If symmetric or asymmetric and even, the actual length will be double, and if symmetric or asymmetric and odd, the actual length will be double plus one. */
#define CSL_DFE_CFR_CFR1_PDC1_CP_LUTLENGTH_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_1_MASK (0x000000FFu)
#define CSL_DFE_CFR_CFR1_PDC1_CP_LUTLENGTH_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_CP_LUTLENGTH_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_1_RESETVAL (0x000000FFu)

#define CSL_DFE_CFR_CFR1_PDC1_CP_LUTLENGTH_A1_REG_ADDR (0x000002B4u)
#define CSL_DFE_CFR_CFR1_PDC1_CP_LUTLENGTH_A1_REG_RESETVAL (0x000000FFu)

/* CFR0_PDC1_STAT_PK_ALLOC_A0S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_pk_alloc_a0s0 : 16;
#else 
    Uint32 pdc1_stat_pk_alloc_a0s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S0_REG;

/* Peaks allocated for pdc1 antenna 0 stage 0 */
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S0_REG_PDC1_STAT_PK_ALLOC_A0S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S0_REG_PDC1_STAT_PK_ALLOC_A0S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S0_REG_PDC1_STAT_PK_ALLOC_A0S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S0_REG_ADDR (0x000002C0u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC1_STAT_PK_ALLOC_A1S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_pk_alloc_a1s0 : 16;
#else 
    Uint32 pdc1_stat_pk_alloc_a1s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S0_REG;

/* Peaks allocated for pdc1 antenna 1 stage 0 */
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S0_REG_PDC1_STAT_PK_ALLOC_A1S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S0_REG_PDC1_STAT_PK_ALLOC_A1S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S0_REG_PDC1_STAT_PK_ALLOC_A1S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S0_REG_ADDR (0x000002C4u)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S0_REG_RESETVAL (0x00000000u)

/* CFR0_PDC1_STAT_PK_ALLOC_A0S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_pk_alloc_a0s1 : 16;
#else 
    Uint32 pdc1_stat_pk_alloc_a0s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S1_REG;

/* Peaks allocated for pdc1 antenna 0 stage 1 */
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S1_REG_PDC1_STAT_PK_ALLOC_A0S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S1_REG_PDC1_STAT_PK_ALLOC_A0S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S1_REG_PDC1_STAT_PK_ALLOC_A0S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S1_REG_ADDR (0x000002C8u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_ALLOC_A0S1_REG_RESETVAL (0x00000000u)

/* CFR1_PDC1_STAT_PK_ALLOC_A1S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_pk_alloc_a1s1 : 16;
#else 
    Uint32 pdc1_stat_pk_alloc_a1s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S1_REG;

/* Peaks allocated for pdc1 antenna 1 stage 1 */
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S1_REG_PDC1_STAT_PK_ALLOC_A1S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S1_REG_PDC1_STAT_PK_ALLOC_A1S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S1_REG_PDC1_STAT_PK_ALLOC_A1S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S1_REG_ADDR (0x000002CCu)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_ALLOC_A1S1_REG_RESETVAL (0x00000000u)

/* CFR0_PDC1_STAT_PK_MISSED_A0S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_pk_missed_a0s0 : 16;
#else 
    Uint32 pdc1_stat_pk_missed_a0s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S0_REG;

/* Peaks missed for pdc1 antenna 0 stage 0 */
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S0_REG_PDC1_STAT_PK_MISSED_A0S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S0_REG_PDC1_STAT_PK_MISSED_A0S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S0_REG_PDC1_STAT_PK_MISSED_A0S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S0_REG_ADDR (0x000002D0u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC1_STAT_PK_MISSED_A1S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_pk_missed_a1s0 : 16;
#else 
    Uint32 pdc1_stat_pk_missed_a1s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S0_REG;

/* Peaks missed for pdc1 antenna 1 stage 0 */
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S0_REG_PDC1_STAT_PK_MISSED_A1S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S0_REG_PDC1_STAT_PK_MISSED_A1S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S0_REG_PDC1_STAT_PK_MISSED_A1S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S0_REG_ADDR (0x000002D4u)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S0_REG_RESETVAL (0x00000000u)

/* CFR0_PDC1_STAT_PK_MISSED_A0S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_pk_missed_a0s1 : 16;
#else 
    Uint32 pdc1_stat_pk_missed_a0s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S1_REG;

/* Peaks missed for pdc1 antenna 0 stage 1 */
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S1_REG_PDC1_STAT_PK_MISSED_A0S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S1_REG_PDC1_STAT_PK_MISSED_A0S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S1_REG_PDC1_STAT_PK_MISSED_A0S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S1_REG_ADDR (0x000002D8u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_PK_MISSED_A0S1_REG_RESETVAL (0x00000000u)

/* CFR1_PDC1_STAT_PK_MISSED_A1S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_pk_missed_a1s1 : 16;
#else 
    Uint32 pdc1_stat_pk_missed_a1s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S1_REG;

/* Peaks missed for pdc1 antenna 1 stage 1 */
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S1_REG_PDC1_STAT_PK_MISSED_A1S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S1_REG_PDC1_STAT_PK_MISSED_A1S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S1_REG_PDC1_STAT_PK_MISSED_A1S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S1_REG_ADDR (0x000002DCu)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_PK_MISSED_A1S1_REG_RESETVAL (0x00000000u)

/* CFR0_PDC1_STAT_DISTANCE_A0S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_distance_a0s0 : 16;
#else 
    Uint32 pdc1_stat_distance_a0s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S0_REG;

/* Peak minimum distance for pdc1 antenna 0 stage 0 */
#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S0_REG_PDC1_STAT_DISTANCE_A0S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S0_REG_PDC1_STAT_DISTANCE_A0S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S0_REG_PDC1_STAT_DISTANCE_A0S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S0_REG_ADDR (0x000002E0u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S0_REG_RESETVAL (0x00000000u)

/* CFR1_PDC1_STAT_DISTANCE_A1S0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_distance_a1s0 : 16;
#else 
    Uint32 pdc1_stat_distance_a1s0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S0_REG;

/* Peak minimum distance for pdc1 antenna 1 stage 0 */
#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S0_REG_PDC1_STAT_DISTANCE_A1S0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S0_REG_PDC1_STAT_DISTANCE_A1S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S0_REG_PDC1_STAT_DISTANCE_A1S0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S0_REG_ADDR (0x000002E4u)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S0_REG_RESETVAL (0x00000000u)

/* CFR0_PDC1_STAT_DISTANCE_A0S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_distance_a0s1 : 16;
#else 
    Uint32 pdc1_stat_distance_a0s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S1_REG;

/* Peak minimum distance for pdc1 antenna 0 stage 1 */
#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S1_REG_PDC1_STAT_DISTANCE_A0S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S1_REG_PDC1_STAT_DISTANCE_A0S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S1_REG_PDC1_STAT_DISTANCE_A0S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S1_REG_ADDR (0x000002E8u)
#define CSL_DFE_CFR_CFR0_PDC1_STAT_DISTANCE_A0S1_REG_RESETVAL (0x00000000u)

/* CFR1_PDC1_STAT_DISTANCE_A1S1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 pdc1_stat_distance_a1s1 : 16;
#else 
    Uint32 pdc1_stat_distance_a1s1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S1_REG;

/* Peak minimum distance for pdc1 antenna 1 stage 1 */
#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S1_REG_PDC1_STAT_DISTANCE_A1S1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S1_REG_PDC1_STAT_DISTANCE_A1S1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S1_REG_PDC1_STAT_DISTANCE_A1S1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S1_REG_ADDR (0x000002ECu)
#define CSL_DFE_CFR_CFR1_PDC1_STAT_DISTANCE_A1S1_REG_RESETVAL (0x00000000u)

/* CPA0_AGC_MIN_IN_TH_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa0_cpa_cpain_min_meas_th : 16;
#else 
    Uint32 cpa0_cpa_cpain_min_meas_th : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA0_AGC_MIN_IN_TH_A0_REG;

/* If enabled, No adaptation if CFR input running average is below this 2.14 threshold. Static gain shall be used. If disabled, an interrupt will still be issued. */
#define CSL_DFE_CFR_CPA0_AGC_MIN_IN_TH_A0_REG_CPA0_CPA_CPAIN_MIN_MEAS_TH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA0_AGC_MIN_IN_TH_A0_REG_CPA0_CPA_CPAIN_MIN_MEAS_TH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_MIN_IN_TH_A0_REG_CPA0_CPA_CPAIN_MIN_MEAS_TH_RESETVAL (0x00001000u)

#define CSL_DFE_CFR_CPA0_AGC_MIN_IN_TH_A0_REG_ADDR (0x00000300u)
#define CSL_DFE_CFR_CPA0_AGC_MIN_IN_TH_A0_REG_RESETVAL (0x00001000u)

/* CPA1_AGC_MIN_IN_TH_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa1_cpa_cpain_min_meas_th : 16;
#else 
    Uint32 cpa1_cpa_cpain_min_meas_th : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA1_AGC_MIN_IN_TH_A1_REG;

/* If enabled, No adaptation if CFR input running average is below this 2.14 threshold. Static gain  shall be used. If disabled, an interrupt will still be issued. */
#define CSL_DFE_CFR_CPA1_AGC_MIN_IN_TH_A1_REG_CPA1_CPA_CPAIN_MIN_MEAS_TH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA1_AGC_MIN_IN_TH_A1_REG_CPA1_CPA_CPAIN_MIN_MEAS_TH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_MIN_IN_TH_A1_REG_CPA1_CPA_CPAIN_MIN_MEAS_TH_RESETVAL (0x00001000u)

#define CSL_DFE_CFR_CPA1_AGC_MIN_IN_TH_A1_REG_ADDR (0x00000304u)
#define CSL_DFE_CFR_CPA1_AGC_MIN_IN_TH_A1_REG_RESETVAL (0x00001000u)

/* CPA0_AGC_MIN_OUT_TH_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa0_cpa_cpaout_min_meas_th : 16;
#else 
    Uint32 cpa0_cpa_cpaout_min_meas_th : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA0_AGC_MIN_OUT_TH_A0_REG;

/* If enabled, No adaptation if CFR output running average is below this 2.14 threshold. Static gain shall be used. If disabled, an interrupt will still be issued. */
#define CSL_DFE_CFR_CPA0_AGC_MIN_OUT_TH_A0_REG_CPA0_CPA_CPAOUT_MIN_MEAS_TH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA0_AGC_MIN_OUT_TH_A0_REG_CPA0_CPA_CPAOUT_MIN_MEAS_TH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_MIN_OUT_TH_A0_REG_CPA0_CPA_CPAOUT_MIN_MEAS_TH_RESETVAL (0x00001000u)

#define CSL_DFE_CFR_CPA0_AGC_MIN_OUT_TH_A0_REG_ADDR (0x00000308u)
#define CSL_DFE_CFR_CPA0_AGC_MIN_OUT_TH_A0_REG_RESETVAL (0x00001000u)

/* CPA1_AGC_MIN_OUT_TH_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa1_cpa_cpaout_min_meas_th : 16;
#else 
    Uint32 cpa1_cpa_cpaout_min_meas_th : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA1_AGC_MIN_OUT_TH_A1_REG;

/* If enabled, No adaptation if CFR output running average is below this 2.14 threshold. Static gain shall be used. If disabled, an interrupt will still be issued. */
#define CSL_DFE_CFR_CPA1_AGC_MIN_OUT_TH_A1_REG_CPA1_CPA_CPAOUT_MIN_MEAS_TH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA1_AGC_MIN_OUT_TH_A1_REG_CPA1_CPA_CPAOUT_MIN_MEAS_TH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_MIN_OUT_TH_A1_REG_CPA1_CPA_CPAOUT_MIN_MEAS_TH_RESETVAL (0x00001000u)

#define CSL_DFE_CFR_CPA1_AGC_MIN_OUT_TH_A1_REG_ADDR (0x0000030Cu)
#define CSL_DFE_CFR_CPA1_AGC_MIN_OUT_TH_A1_REG_RESETVAL (0x00001000u)

/* CPA0_AGC_MAX_IN_TH_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa0_cpa_cpain_max_meas_th : 16;
#else 
    Uint32 cpa0_cpa_cpain_max_meas_th : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA0_AGC_MAX_IN_TH_A0_REG;

/* If enabled, No adaptation if CFR input running average is above this 2.14 threshold. Static gain shall be used. If disabled, an interrupt will still be issued. */
#define CSL_DFE_CFR_CPA0_AGC_MAX_IN_TH_A0_REG_CPA0_CPA_CPAIN_MAX_MEAS_TH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA0_AGC_MAX_IN_TH_A0_REG_CPA0_CPA_CPAIN_MAX_MEAS_TH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_MAX_IN_TH_A0_REG_CPA0_CPA_CPAIN_MAX_MEAS_TH_RESETVAL (0x0000F000u)

#define CSL_DFE_CFR_CPA0_AGC_MAX_IN_TH_A0_REG_ADDR (0x00000310u)
#define CSL_DFE_CFR_CPA0_AGC_MAX_IN_TH_A0_REG_RESETVAL (0x0000F000u)

/* CPA1_AGC_MAX_IN_TH_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa1_cpa_cpain_max_meas_th : 16;
#else 
    Uint32 cpa1_cpa_cpain_max_meas_th : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA1_AGC_MAX_IN_TH_A1_REG;

/* If enabled, No adaptation if CFR input running average is above this 2.14 threshold. Static gain  shall be used. If disabled, an interrupt will still be issued. */
#define CSL_DFE_CFR_CPA1_AGC_MAX_IN_TH_A1_REG_CPA1_CPA_CPAIN_MAX_MEAS_TH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA1_AGC_MAX_IN_TH_A1_REG_CPA1_CPA_CPAIN_MAX_MEAS_TH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_MAX_IN_TH_A1_REG_CPA1_CPA_CPAIN_MAX_MEAS_TH_RESETVAL (0x0000F000u)

#define CSL_DFE_CFR_CPA1_AGC_MAX_IN_TH_A1_REG_ADDR (0x00000314u)
#define CSL_DFE_CFR_CPA1_AGC_MAX_IN_TH_A1_REG_RESETVAL (0x0000F000u)

/* CPA0_AGC_MAX_OUT_TH_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa0_cpa_cpaout_max_meas_th : 16;
#else 
    Uint32 cpa0_cpa_cpaout_max_meas_th : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA0_AGC_MAX_OUT_TH_A0_REG;

/* If enabled, No adaptation if CFR output running average is above this 2.14 threshold. Static gain shall be used. If disabled, an interrupt will still be issued. */
#define CSL_DFE_CFR_CPA0_AGC_MAX_OUT_TH_A0_REG_CPA0_CPA_CPAOUT_MAX_MEAS_TH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA0_AGC_MAX_OUT_TH_A0_REG_CPA0_CPA_CPAOUT_MAX_MEAS_TH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_MAX_OUT_TH_A0_REG_CPA0_CPA_CPAOUT_MAX_MEAS_TH_RESETVAL (0x0000F000u)

#define CSL_DFE_CFR_CPA0_AGC_MAX_OUT_TH_A0_REG_ADDR (0x00000318u)
#define CSL_DFE_CFR_CPA0_AGC_MAX_OUT_TH_A0_REG_RESETVAL (0x0000F000u)

/* CPA1_AGC_MAX_OUT_TH_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa1_cpa_cpaout_max_meas_th : 16;
#else 
    Uint32 cpa1_cpa_cpaout_max_meas_th : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA1_AGC_MAX_OUT_TH_A1_REG;

/* If enabled, No adaptation if CFR output running average is above this 2.14 threshold. Static gain shall be used. If disabled, an interrupt will still be issued. */
#define CSL_DFE_CFR_CPA1_AGC_MAX_OUT_TH_A1_REG_CPA1_CPA_CPAOUT_MAX_MEAS_TH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA1_AGC_MAX_OUT_TH_A1_REG_CPA1_CPA_CPAOUT_MAX_MEAS_TH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_MAX_OUT_TH_A1_REG_CPA1_CPA_CPAOUT_MAX_MEAS_TH_RESETVAL (0x0000F000u)

#define CSL_DFE_CFR_CPA1_AGC_MAX_OUT_TH_A1_REG_ADDR (0x0000031Cu)
#define CSL_DFE_CFR_CPA1_AGC_MAX_OUT_TH_A1_REG_RESETVAL (0x0000F000u)

/* CPA0_CFR_IN_DLY_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 cpa0_sim_hw_delay_before_cfr : 12;
#else 
    Uint32 cpa0_sim_hw_delay_before_cfr : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_CPA0_CFR_IN_DLY_A0_REG;

/* Delay from the input to the chip to the input to the CFR */
#define CSL_DFE_CFR_CPA0_CFR_IN_DLY_A0_REG_CPA0_SIM_HW_DELAY_BEFORE_CFR_MASK (0x00000FFFu)
#define CSL_DFE_CFR_CPA0_CFR_IN_DLY_A0_REG_CPA0_SIM_HW_DELAY_BEFORE_CFR_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_CFR_IN_DLY_A0_REG_CPA0_SIM_HW_DELAY_BEFORE_CFR_RESETVAL (0x00000800u)

#define CSL_DFE_CFR_CPA0_CFR_IN_DLY_A0_REG_ADDR (0x00000320u)
#define CSL_DFE_CFR_CPA0_CFR_IN_DLY_A0_REG_RESETVAL (0x00000800u)

/* CPA1_CFR_IN_DLY_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 cpa1_sim_hw_delay_before_cfr : 12;
#else 
    Uint32 cpa1_sim_hw_delay_before_cfr : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_CPA1_CFR_IN_DLY_A1_REG;

/* Delay from the input to the chip to the input to the CFR */
#define CSL_DFE_CFR_CPA1_CFR_IN_DLY_A1_REG_CPA1_SIM_HW_DELAY_BEFORE_CFR_MASK (0x00000FFFu)
#define CSL_DFE_CFR_CPA1_CFR_IN_DLY_A1_REG_CPA1_SIM_HW_DELAY_BEFORE_CFR_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_CFR_IN_DLY_A1_REG_CPA1_SIM_HW_DELAY_BEFORE_CFR_RESETVAL (0x00000800u)

#define CSL_DFE_CFR_CPA1_CFR_IN_DLY_A1_REG_ADDR (0x00000324u)
#define CSL_DFE_CFR_CPA1_CFR_IN_DLY_A1_REG_RESETVAL (0x00000800u)

/* CPA0_CFR_OUT_DLY_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 cpa0_calc_cpa_total_cfr_delay : 12;
#else 
    Uint32 cpa0_calc_cpa_total_cfr_delay : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_CPA0_CFR_OUT_DLY_A0_REG;

/* Delay through the CFR */
#define CSL_DFE_CFR_CPA0_CFR_OUT_DLY_A0_REG_CPA0_CALC_CPA_TOTAL_CFR_DELAY_MASK (0x00000FFFu)
#define CSL_DFE_CFR_CPA0_CFR_OUT_DLY_A0_REG_CPA0_CALC_CPA_TOTAL_CFR_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_CFR_OUT_DLY_A0_REG_CPA0_CALC_CPA_TOTAL_CFR_DELAY_RESETVAL (0x00000200u)

#define CSL_DFE_CFR_CPA0_CFR_OUT_DLY_A0_REG_ADDR (0x00000328u)
#define CSL_DFE_CFR_CPA0_CFR_OUT_DLY_A0_REG_RESETVAL (0x00000200u)

/* CPA1_CFR_OUT_DLY_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 cpa1_calc_cpa_total_cfr_delay : 12;
#else 
    Uint32 cpa1_calc_cpa_total_cfr_delay : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_CPA1_CFR_OUT_DLY_A1_REG;

/* Delay through the CFR */
#define CSL_DFE_CFR_CPA1_CFR_OUT_DLY_A1_REG_CPA1_CALC_CPA_TOTAL_CFR_DELAY_MASK (0x00000FFFu)
#define CSL_DFE_CFR_CPA1_CFR_OUT_DLY_A1_REG_CPA1_CALC_CPA_TOTAL_CFR_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_CFR_OUT_DLY_A1_REG_CPA1_CALC_CPA_TOTAL_CFR_DELAY_RESETVAL (0x00000200u)

#define CSL_DFE_CFR_CPA1_CFR_OUT_DLY_A1_REG_ADDR (0x0000032Cu)
#define CSL_DFE_CFR_CPA1_CFR_OUT_DLY_A1_REG_RESETVAL (0x00000200u)

/* CPA0_CFR_FRM_MSB_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cpa0_sim_frame_length : 8;
#else 
    Uint32 cpa0_sim_frame_length : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CPA0_CFR_FRM_MSB_A0_REG;

/* 8 MSbs of the Frame size */
#define CSL_DFE_CFR_CPA0_CFR_FRM_MSB_A0_REG_CPA0_SIM_FRAME_LENGTH_MASK (0x000000FFu)
#define CSL_DFE_CFR_CPA0_CFR_FRM_MSB_A0_REG_CPA0_SIM_FRAME_LENGTH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_CFR_FRM_MSB_A0_REG_CPA0_SIM_FRAME_LENGTH_RESETVAL (0x00000003u)

#define CSL_DFE_CFR_CPA0_CFR_FRM_MSB_A0_REG_ADDR (0x00000330u)
#define CSL_DFE_CFR_CPA0_CFR_FRM_MSB_A0_REG_RESETVAL (0x00000003u)

/* CPA1_CFR_FRM_MSB_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 cpa1_sim_frame_length : 8;
#else 
    Uint32 cpa1_sim_frame_length : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_CFR_CPA1_CFR_FRM_MSB_A1_REG;

/* 8 MSbs of the Frame size */
#define CSL_DFE_CFR_CPA1_CFR_FRM_MSB_A1_REG_CPA1_SIM_FRAME_LENGTH_MASK (0x000000FFu)
#define CSL_DFE_CFR_CPA1_CFR_FRM_MSB_A1_REG_CPA1_SIM_FRAME_LENGTH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_CFR_FRM_MSB_A1_REG_CPA1_SIM_FRAME_LENGTH_RESETVAL (0x00000003u)

#define CSL_DFE_CFR_CPA1_CFR_FRM_MSB_A1_REG_ADDR (0x00000334u)
#define CSL_DFE_CFR_CPA1_CFR_FRM_MSB_A1_REG_RESETVAL (0x00000003u)

/* CPA0_CFR_FRM_LSW_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa0_sim_frame_length : 16;
#else 
    Uint32 cpa0_sim_frame_length : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA0_CFR_FRM_LSW_A0_REG;

/* 16 LSbs of the Frame size */
#define CSL_DFE_CFR_CPA0_CFR_FRM_LSW_A0_REG_CPA0_SIM_FRAME_LENGTH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA0_CFR_FRM_LSW_A0_REG_CPA0_SIM_FRAME_LENGTH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_CFR_FRM_LSW_A0_REG_CPA0_SIM_FRAME_LENGTH_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA0_CFR_FRM_LSW_A0_REG_ADDR (0x00000338u)
#define CSL_DFE_CFR_CPA0_CFR_FRM_LSW_A0_REG_RESETVAL (0x00000000u)

/* CPA1_CFR_FRM_LSW_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa1_sim_frame_length : 16;
#else 
    Uint32 cpa1_sim_frame_length : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA1_CFR_FRM_LSW_A1_REG;

/* 16 LSbs of the Frame size */
#define CSL_DFE_CFR_CPA1_CFR_FRM_LSW_A1_REG_CPA1_SIM_FRAME_LENGTH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA1_CFR_FRM_LSW_A1_REG_CPA1_SIM_FRAME_LENGTH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_CFR_FRM_LSW_A1_REG_CPA1_SIM_FRAME_LENGTH_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA1_CFR_FRM_LSW_A1_REG_ADDR (0x0000033Cu)
#define CSL_DFE_CFR_CPA1_CFR_FRM_LSW_A1_REG_RESETVAL (0x00000000u)

/* CPA0_AGC_MODE_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cpa0_eng_bypass : 1;
    Uint32 cpa0_eng_pwrsaveflag : 1;
    Uint32 rsvd0 : 2;
    Uint32 cpa0_calc_cpa_fifo_depth : 4;
    Uint32 cpa0_eng_updaten : 8;
#else 
    Uint32 cpa0_eng_updaten : 8;
    Uint32 cpa0_calc_cpa_fifo_depth : 4;
    Uint32 rsvd0 : 2;
    Uint32 cpa0_eng_pwrsaveflag : 1;
    Uint32 cpa0_eng_bypass : 1;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG;

/* Down sampling rate (minus 1) for antenna #0. Legal values are 1-255. */
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_ENG_UPDATEN_MASK (0x000000FFu)
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_ENG_UPDATEN_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_ENG_UPDATEN_RESETVAL (0x00000007u)

/* FIFO size (Depth) minus 1 for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_CALC_CPA_FIFO_DEPTH_MASK (0x00000F00u)
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_CALC_CPA_FIFO_DEPTH_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_CALC_CPA_FIFO_DEPTH_RESETVAL (0x0000000Fu)

/* Not implemented: Enable running average in non-adaptive modes 0-2 (For power savings) for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_ENG_PWRSAVEFLAG_MASK (0x00004000u)
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_ENG_PWRSAVEFLAG_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_ENG_PWRSAVEFLAG_RESETVAL (0x00000000u)

/* Enabled Post AGC. If disabled, then it is being bypassed for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_ENG_BYPASS_MASK (0x00008000u)
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_ENG_BYPASS_SHIFT (0x0000000Fu)
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_CPA0_ENG_BYPASS_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_ADDR (0x00000340u)
#define CSL_DFE_CFR_CPA0_AGC_MODE_A0_REG_RESETVAL (0x00000F07u)

/* CPA1_AGC_MODE_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cpa1_eng_bypass : 1;
    Uint32 cpa1_eng_pwrsaveflag : 1;
    Uint32 rsvd0 : 2;
    Uint32 cpa1_calc_cpa_fifo_depth : 4;
    Uint32 cpa1_eng_updaten : 8;
#else 
    Uint32 cpa1_eng_updaten : 8;
    Uint32 cpa1_calc_cpa_fifo_depth : 4;
    Uint32 rsvd0 : 2;
    Uint32 cpa1_eng_pwrsaveflag : 1;
    Uint32 cpa1_eng_bypass : 1;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG;

/* Down sampling rate (minus 1) for antenna #1. Legal values are 1-255. */
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_ENG_UPDATEN_MASK (0x000000FFu)
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_ENG_UPDATEN_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_ENG_UPDATEN_RESETVAL (0x00000007u)

/* FIFO size (Depth) minus 1 for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_CALC_CPA_FIFO_DEPTH_MASK (0x00000F00u)
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_CALC_CPA_FIFO_DEPTH_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_CALC_CPA_FIFO_DEPTH_RESETVAL (0x0000000Fu)

/* Not implemented: Enable running average in non-adaptive modes 0-2 (For power savings) for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_ENG_PWRSAVEFLAG_MASK (0x00004000u)
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_ENG_PWRSAVEFLAG_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_ENG_PWRSAVEFLAG_RESETVAL (0x00000000u)

/* Enabled Post AGC. If disabled, then it is being bypassed for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_ENG_BYPASS_MASK (0x00008000u)
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_ENG_BYPASS_SHIFT (0x0000000Fu)
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_CPA1_ENG_BYPASS_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_ADDR (0x00000344u)
#define CSL_DFE_CFR_CPA1_AGC_MODE_A1_REG_RESETVAL (0x00000F07u)

/* CPA0_AGC_RAVG_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 cpa0_cfrinavg_bypass : 1;
    Uint32 cpa0_cfrout_max_staticgaout : 1;
    Uint32 cpa0_cfrout_max_en : 1;
    Uint32 cpa0_cfrin_max_staticgain : 1;
    Uint32 cpa0_cfrin_max_en : 1;
    Uint32 cpa0_cfrout_min_staticgaout : 1;
    Uint32 cpa0_cfrout_min_en : 1;
    Uint32 cpa0_cfrin_min_staticgain : 1;
    Uint32 cpa0_cfrin_min_en : 1;
#else 
    Uint32 cpa0_cfrin_min_en : 1;
    Uint32 cpa0_cfrin_min_staticgain : 1;
    Uint32 cpa0_cfrout_min_en : 1;
    Uint32 cpa0_cfrout_min_staticgaout : 1;
    Uint32 cpa0_cfrin_max_en : 1;
    Uint32 cpa0_cfrin_max_staticgain : 1;
    Uint32 cpa0_cfrout_max_en : 1;
    Uint32 cpa0_cfrout_max_staticgaout : 1;
    Uint32 cpa0_cfrinavg_bypass : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG;

/* Enable switching to static/last gain on min_in threshold for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MIN_EN_MASK (0x00000001u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MIN_EN_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MIN_EN_RESETVAL (0x00000000u)

/* 0: Use last gain. 1: Use static gain */
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MIN_STATICGAIN_MASK (0x00000002u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MIN_STATICGAIN_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MIN_STATICGAIN_RESETVAL (0x00000000u)

/* Enable switching to static/last gain on min_out threshold for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MIN_EN_MASK (0x00000004u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MIN_EN_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MIN_EN_RESETVAL (0x00000000u)

/* 0: Use last gain. 1: Use static gain */
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MIN_STATICGAOUT_MASK (0x00000008u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MIN_STATICGAOUT_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MIN_STATICGAOUT_RESETVAL (0x00000000u)

/* Enable switching to static/last gain on max_in threshold for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MAX_EN_MASK (0x00000010u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MAX_EN_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MAX_EN_RESETVAL (0x00000000u)

/* 0: Use last gain. 1: Use static gain */
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MAX_STATICGAIN_MASK (0x00000020u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MAX_STATICGAIN_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRIN_MAX_STATICGAIN_RESETVAL (0x00000000u)

/* Enable switching to static/last gain on max_out threshold for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MAX_EN_MASK (0x00000040u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MAX_EN_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MAX_EN_RESETVAL (0x00000000u)

/* 0: Use last gain. 1: Use static gain */
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MAX_STATICGAOUT_MASK (0x00000080u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MAX_STATICGAOUT_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFROUT_MAX_STATICGAOUT_RESETVAL (0x00000000u)

/* Bypass AGC in ravg for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRINAVG_BYPASS_MASK (0x00000100u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRINAVG_BYPASS_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_CPA0_CFRINAVG_BYPASS_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_ADDR (0x00000348u)
#define CSL_DFE_CFR_CPA0_AGC_RAVG_A0_REG_RESETVAL (0x00000000u)

/* CPA1_AGC_RAVG_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 cpa1_cfrinavg_bypass : 1;
    Uint32 cpa1_cfrout_max_staticgaout : 1;
    Uint32 cpa1_cfrout_max_en : 1;
    Uint32 cpa1_cfrin_max_staticgain : 1;
    Uint32 cpa1_cfrin_max_en : 1;
    Uint32 cpa1_cfrout_min_staticgaout : 1;
    Uint32 cpa1_cfrout_min_en : 1;
    Uint32 cpa1_cfrin_min_staticgain : 1;
    Uint32 cpa1_cfrin_min_en : 1;
#else 
    Uint32 cpa1_cfrin_min_en : 1;
    Uint32 cpa1_cfrin_min_staticgain : 1;
    Uint32 cpa1_cfrout_min_en : 1;
    Uint32 cpa1_cfrout_min_staticgaout : 1;
    Uint32 cpa1_cfrin_max_en : 1;
    Uint32 cpa1_cfrin_max_staticgain : 1;
    Uint32 cpa1_cfrout_max_en : 1;
    Uint32 cpa1_cfrout_max_staticgaout : 1;
    Uint32 cpa1_cfrinavg_bypass : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG;

/* Enable switching to static/last gain on min_in threshold for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MIN_EN_MASK (0x00000001u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MIN_EN_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MIN_EN_RESETVAL (0x00000000u)

/* 0: Use last gain. 1: Use static gain */
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MIN_STATICGAIN_MASK (0x00000002u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MIN_STATICGAIN_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MIN_STATICGAIN_RESETVAL (0x00000000u)

/* Enable switching to static/last gain on min_out threshold for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MIN_EN_MASK (0x00000004u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MIN_EN_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MIN_EN_RESETVAL (0x00000000u)

/* 0: Use last gain. 1: Use static gain */
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MIN_STATICGAOUT_MASK (0x00000008u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MIN_STATICGAOUT_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MIN_STATICGAOUT_RESETVAL (0x00000000u)

/* Enable switching to static/last gain on max_in threshold for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MAX_EN_MASK (0x00000010u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MAX_EN_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MAX_EN_RESETVAL (0x00000000u)

/* 0: Use last gain. 1: Use static gain */
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MAX_STATICGAIN_MASK (0x00000020u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MAX_STATICGAIN_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRIN_MAX_STATICGAIN_RESETVAL (0x00000000u)

/* Enable switching to static/last gain on max_out threshold for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MAX_EN_MASK (0x00000040u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MAX_EN_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MAX_EN_RESETVAL (0x00000000u)

/* 0: Use last gain. 1: Use static gain */
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MAX_STATICGAOUT_MASK (0x00000080u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MAX_STATICGAOUT_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFROUT_MAX_STATICGAOUT_RESETVAL (0x00000000u)

/* Bypass AGC in ravg for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRINAVG_BYPASS_MASK (0x00000100u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRINAVG_BYPASS_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_CPA1_CFRINAVG_BYPASS_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_ADDR (0x0000034Cu)
#define CSL_DFE_CFR_CPA1_AGC_RAVG_A1_REG_RESETVAL (0x00000000u)

/* CPA0_AGC_BP_IN_RAVG_MSW_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa0_cfrinavg_power : 16;
#else 
    Uint32 cpa0_cfrinavg_power : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_MSW_A0_REG;

/* 16 MSB of the target power to be used for adjusting the CFR output power for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_MSW_A0_REG_CPA0_CFRINAVG_POWER_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_MSW_A0_REG_CPA0_CFRINAVG_POWER_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_MSW_A0_REG_CPA0_CFRINAVG_POWER_RESETVAL (0x00008000u)

#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_MSW_A0_REG_ADDR (0x00000350u)
#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_MSW_A0_REG_RESETVAL (0x00008000u)

/* CPA1_AGC_BP_IN_RAVG_MSW_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa1_cfrinavg_power : 16;
#else 
    Uint32 cpa1_cfrinavg_power : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_MSW_A1_REG;

/* 16 MSB of the target power to be used for adjusting the CFR output power for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_MSW_A1_REG_CPA1_CFRINAVG_POWER_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_MSW_A1_REG_CPA1_CFRINAVG_POWER_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_MSW_A1_REG_CPA1_CFRINAVG_POWER_RESETVAL (0x00008000u)

#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_MSW_A1_REG_ADDR (0x00000354u)
#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_MSW_A1_REG_RESETVAL (0x00008000u)

/* CPA0_AGC_BP_IN_RAVG_LSW_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa0_cfrinavg_power : 16;
#else 
    Uint32 cpa0_cfrinavg_power : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_LSW_A0_REG;

/* 16 LSB of the target power to be used for adjusting the CFR output power for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_LSW_A0_REG_CPA0_CFRINAVG_POWER_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_LSW_A0_REG_CPA0_CFRINAVG_POWER_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_LSW_A0_REG_CPA0_CFRINAVG_POWER_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_LSW_A0_REG_ADDR (0x00000358u)
#define CSL_DFE_CFR_CPA0_AGC_BP_IN_RAVG_LSW_A0_REG_RESETVAL (0x00000000u)

/* CPA1_AGC_BP_IN_RAVG_LSW_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa1_cfrinavg_power : 16;
#else 
    Uint32 cpa1_cfrinavg_power : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_LSW_A1_REG;

/* 16 LSB of the target power to be used for adjusting the CFR output power for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_LSW_A1_REG_CPA1_CFRINAVG_POWER_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_LSW_A1_REG_CPA1_CFRINAVG_POWER_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_LSW_A1_REG_CPA1_CFRINAVG_POWER_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_LSW_A1_REG_ADDR (0x0000035Cu)
#define CSL_DFE_CFR_CPA1_AGC_BP_IN_RAVG_LSW_A1_REG_RESETVAL (0x00000000u)

/* CFR0_CFR_PREM_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_precfrgain_0 : 16;
#else 
    Uint32 cfr0_precfrgain_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_CFR_PREM_A0_REG;

/* (Shadow) Pre CFR multiplier for antenna #0. 0x8000 for gain of 1. */
#define CSL_DFE_CFR_CFR0_CFR_PREM_A0_REG_CFR0_PRECFRGAIN_0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_CFR_PREM_A0_REG_CFR0_PRECFRGAIN_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_CFR_PREM_A0_REG_CFR0_PRECFRGAIN_0_RESETVAL (0x00008000u)

#define CSL_DFE_CFR_CFR0_CFR_PREM_A0_REG_ADDR (0x00000360u)
#define CSL_DFE_CFR_CFR0_CFR_PREM_A0_REG_RESETVAL (0x00008000u)

/* CFR1_CFR_PREM_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_precfrgain_1 : 16;
#else 
    Uint32 cfr1_precfrgain_1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_CFR_PREM_A1_REG;

/* (Shadow) Pre CFR multiplier for antenna #1. 0x8000 for gain of 1. */
#define CSL_DFE_CFR_CFR1_CFR_PREM_A1_REG_CFR1_PRECFRGAIN_1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_CFR_PREM_A1_REG_CFR1_PRECFRGAIN_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_CFR_PREM_A1_REG_CFR1_PRECFRGAIN_1_RESETVAL (0x00008000u)

#define CSL_DFE_CFR_CFR1_CFR_PREM_A1_REG_ADDR (0x00000364u)
#define CSL_DFE_CFR_CFR1_CFR_PREM_A1_REG_RESETVAL (0x00008000u)

/* CFR0_CFR_PA_PROTECT_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_protpagain_0 : 16;
#else 
    Uint32 cfr0_protpagain_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_CFR_PA_PROTECT_A0_REG;

/* PA protection mode pre-CFR multiplier for antenna #0. 0x8000 for gain of 1. */
#define CSL_DFE_CFR_CFR0_CFR_PA_PROTECT_A0_REG_CFR0_PROTPAGAIN_0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_CFR_PA_PROTECT_A0_REG_CFR0_PROTPAGAIN_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_CFR_PA_PROTECT_A0_REG_CFR0_PROTPAGAIN_0_RESETVAL (0x00004000u)

#define CSL_DFE_CFR_CFR0_CFR_PA_PROTECT_A0_REG_ADDR (0x00000368u)
#define CSL_DFE_CFR_CFR0_CFR_PA_PROTECT_A0_REG_RESETVAL (0x00004000u)

/* CFR1_CFR_PA_PROTECT_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_protpagain_1 : 16;
#else 
    Uint32 cfr1_protpagain_1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_CFR_PA_PROTECT_A1_REG;

/* PA protection mode pre-CFR multiplier for antenna #1. 0x8000 for gain of 1. */
#define CSL_DFE_CFR_CFR1_CFR_PA_PROTECT_A1_REG_CFR1_PROTPAGAIN_1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_CFR_PA_PROTECT_A1_REG_CFR1_PROTPAGAIN_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_CFR_PA_PROTECT_A1_REG_CFR1_PROTPAGAIN_1_RESETVAL (0x00004000u)

#define CSL_DFE_CFR_CFR1_CFR_PA_PROTECT_A1_REG_ADDR (0x0000036Cu)
#define CSL_DFE_CFR_CFR1_CFR_PA_PROTECT_A1_REG_RESETVAL (0x00004000u)

/* CFR0_CFR_POSTM_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr0_postcfrgain_0 : 16;
#else 
    Uint32 cfr0_postcfrgain_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_CFR_POSTM_A0_REG;

/* (Shadow) Post CFR multiplier for antenna #0. 0x8000 for gain of 1. */
#define CSL_DFE_CFR_CFR0_CFR_POSTM_A0_REG_CFR0_POSTCFRGAIN_0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_CFR_POSTM_A0_REG_CFR0_POSTCFRGAIN_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_CFR_POSTM_A0_REG_CFR0_POSTCFRGAIN_0_RESETVAL (0x00008000u)

#define CSL_DFE_CFR_CFR0_CFR_POSTM_A0_REG_ADDR (0x00000370u)
#define CSL_DFE_CFR_CFR0_CFR_POSTM_A0_REG_RESETVAL (0x00008000u)

/* CFR1_CFR_POSTM_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr1_postcfrgain_1 : 16;
#else 
    Uint32 cfr1_postcfrgain_1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_CFR_POSTM_A1_REG;

/* (Shadow) Post CFR multiplier for antenna #1. 0x8000 for gain of 1. */
#define CSL_DFE_CFR_CFR1_CFR_POSTM_A1_REG_CFR1_POSTCFRGAIN_1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_CFR_POSTM_A1_REG_CFR1_POSTCFRGAIN_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_CFR_POSTM_A1_REG_CFR1_POSTCFRGAIN_1_RESETVAL (0x00008000u)

#define CSL_DFE_CFR_CFR1_CFR_POSTM_A1_REG_ADDR (0x00000374u)
#define CSL_DFE_CFR_CFR1_CFR_POSTM_A1_REG_RESETVAL (0x00008000u)

/* CFR0_CFR_MODE_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cfr0_half_delay_filter_en : 1;
    Uint32 cfr0_cp_firlut_startaddr_1_s1 : 1;
    Uint32 cfr0_cp_firlut_startaddr_for_pool_1 : 1;
    Uint32 cfr0_cp_firlut_startaddr_0_s1 : 1;
    Uint32 cfr0_cp_firlut_startaddr_for_pool_0 : 1;
    Uint32 cfr0_eng_cp_size_for_pool_1_s1 : 1;
    Uint32 cfr0_eng_cp_size_for_pool_1 : 1;
    Uint32 cfr0_eng_cp_size_for_pool_0_s1 : 1;
    Uint32 cfr0_eng_cp_size_for_pool_0 : 1;
    Uint32 cfr0_pd_frac_delay : 3;
    Uint32 rsvd0 : 2;
    Uint32 cfr_mlu_0_1 : 1;
    Uint32 cfr_mlu_0_0 : 1;
#else 
    Uint32 cfr_mlu_0_0 : 1;
    Uint32 cfr_mlu_0_1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 cfr0_pd_frac_delay : 3;
    Uint32 cfr0_eng_cp_size_for_pool_0 : 1;
    Uint32 cfr0_eng_cp_size_for_pool_0_s1 : 1;
    Uint32 cfr0_eng_cp_size_for_pool_1 : 1;
    Uint32 cfr0_eng_cp_size_for_pool_1_s1 : 1;
    Uint32 cfr0_cp_firlut_startaddr_for_pool_0 : 1;
    Uint32 cfr0_cp_firlut_startaddr_0_s1 : 1;
    Uint32 cfr0_cp_firlut_startaddr_for_pool_1 : 1;
    Uint32 cfr0_cp_firlut_startaddr_1_s1 : 1;
    Uint32 cfr0_half_delay_filter_en : 1;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG;

/* bit0 (master) = 1 if the multiband master in a0 MB, i.e.: It detects the peak and fine power^2 for peak parameters calculation for the rest of the antennas in this multiband. */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR_MLU_0_0_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR_MLU_0_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR_MLU_0_0_RESETVAL (0x00000000u)

/* bit0 (master) = 1 if the multiband master in a0 MB, i.e.: It detects the peak and fine power^2 for peak parameters calculation for the rest of the antennas in this multiband. */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR_MLU_0_1_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR_MLU_0_1_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR_MLU_0_1_RESETVAL (0x00000000u)

/* Valid only if multiband_master=0: Delay the 8 fractional power outputs going to the MB master by up to 7/8 of a sample. (NOT IMPLEMNENTED) */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_PD_FRAC_DELAY_MASK (0x00000070u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_PD_FRAC_DELAY_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_PD_FRAC_DELAY_RESETVAL (0x00000000u)

/* MSB of the length of the cancellers in stage 0 (PDC0) in antenna #0 for non-symmetric filters only. */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_0_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_0_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_0_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_0_S1_MASK (0x00000100u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_0_S1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_0_S1_RESETVAL (0x00000000u)

/* MSB of the length of the cancellers in stage 2 (PDC1) in antenna #0 for non-symmetric filters only. */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_1_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_1_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_1_S1_MASK (0x00000400u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_1_S1_SHIFT (0x0000000Au)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_ENG_CP_SIZE_FOR_POOL_1_S1_RESETVAL (0x00000000u)

/* MSB of the start address of the FIR cancellers in stage 0 (PDC0) in antenna #0 for non-symmetric filters only. */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_0_MASK (0x00000800u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_0_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_0_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_0_S1_MASK (0x00001000u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_0_S1_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_0_S1_RESETVAL (0x00000000u)

/* MSB of the start address of the FIR cancellers in stage 2 (PDC1) in antenna #0 for non-symmetric filters only. */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_1_MASK (0x00002000u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_1_SHIFT (0x0000000Du)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_FOR_POOL_1_RESETVAL (0x00000000u)

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_1_S1_MASK (0x00004000u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_1_S1_SHIFT (0x0000000Eu)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_CP_FIRLUT_STARTADDR_1_S1_RESETVAL (0x00000000u)

/* Enable half_delay filter for a0. If 1: All length MSB above must be 0for non-symmetric filters only. */
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_HALF_DELAY_FILTER_EN_MASK (0x00008000u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_HALF_DELAY_FILTER_EN_SHIFT (0x0000000Fu)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_CFR0_HALF_DELAY_FILTER_EN_RESETVAL (0x00000001u)

#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_ADDR (0x00000378u)
#define CSL_DFE_CFR_CFR0_CFR_MODE_A0_REG_RESETVAL (0x00008000u)

/* CFR1_CFR_MODE_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd5 : 16;
    Uint32 cfr1_half_delay_filter_en : 1;
    Uint32 rsvd4 : 1;
    Uint32 cfr1_cp_firlut_startaddr_for_pool_1 : 1;
    Uint32 rsvd3 : 1;
    Uint32 cfr1_cp_firlut_startaddr_for_pool_0 : 1;
    Uint32 rsvd2 : 1;
    Uint32 cfr1_eng_cp_size_for_pool_1 : 1;
    Uint32 rsvd1 : 1;
    Uint32 cfr1_eng_cp_size_for_pool_0 : 1;
    Uint32 cfr1_pd_frac_delay : 3;
    Uint32 rsvd0 : 2;
    Uint32 cfr_mlu_1_1 : 1;
    Uint32 cfr_mlu_1_0 : 1;
#else 
    Uint32 cfr_mlu_1_0 : 1;
    Uint32 cfr_mlu_1_1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 cfr1_pd_frac_delay : 3;
    Uint32 cfr1_eng_cp_size_for_pool_0 : 1;
    Uint32 rsvd1 : 1;
    Uint32 cfr1_eng_cp_size_for_pool_1 : 1;
    Uint32 rsvd2 : 1;
    Uint32 cfr1_cp_firlut_startaddr_for_pool_0 : 1;
    Uint32 rsvd3 : 1;
    Uint32 cfr1_cp_firlut_startaddr_for_pool_1 : 1;
    Uint32 rsvd4 : 1;
    Uint32 cfr1_half_delay_filter_en : 1;
    Uint32 rsvd5 : 16;
#endif 
} CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG;

/* bit0 (master) = 1 if the multiband master in a0 MB, i.e.: It detects the peak and fine power^2 for peak parameters calculation for the rest of the antennas in this multiband. */
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR_MLU_1_0_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR_MLU_1_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR_MLU_1_0_RESETVAL (0x00000000u)

/* bit0 (master) = 1 if the multiband master in a0 MB, i.e.: It detects the peak and fine power^2 for peak parameters calculation for the rest of the antennas in this multiband. */
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR_MLU_1_1_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR_MLU_1_1_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR_MLU_1_1_RESETVAL (0x00000000u)

/* Valid only if multiband_master=0: Delay the 8 fractional power outputs going to the MB master by up to 7/8 of a sample. */
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_PD_FRAC_DELAY_MASK (0x00000070u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_PD_FRAC_DELAY_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_PD_FRAC_DELAY_RESETVAL (0x00000000u)

/* MSB of the length of the cancellers in stage 0 (PDC0) in antenna #1 for non-symmetric filters only. */
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_0_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_0_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_0_RESETVAL (0x00000000u)

/* MSB of the length of the cancellers in stage 2 (PDC1) in antenna #1 for non-symmetric filters only. */
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_1_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_1_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_ENG_CP_SIZE_FOR_POOL_1_RESETVAL (0x00000000u)

/* MSB of the start address of the FIR cancellers in stage 0 (PDC0) in antenna #1 for non-symmetric filters only. */
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_0_MASK (0x00000800u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_0_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_0_RESETVAL (0x00000000u)

/* MSB of the start address of the FIR cancellers in stage 2 (PDC1) in antenna #1 for non-symmetric filters only. */
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_1_MASK (0x00002000u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_1_SHIFT (0x0000000Du)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_CP_FIRLUT_STARTADDR_FOR_POOL_1_RESETVAL (0x00000000u)

/* Enable half_delay filter for a1. If 1: All length MSB above must be 0. */
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_HALF_DELAY_FILTER_EN_MASK (0x00008000u)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_HALF_DELAY_FILTER_EN_SHIFT (0x0000000Fu)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_CFR1_HALF_DELAY_FILTER_EN_RESETVAL (0x00000001u)

#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_ADDR (0x0000037Cu)
#define CSL_DFE_CFR_CFR1_CFR_MODE_A1_REG_RESETVAL (0x00008000u)

/* CFR0_LATCH_AND_CLR_STAT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 18;
    Uint32 latch_and_clr_stat_ravg_out_a0 : 1;
    Uint32 latch_and_clr_stat_ravg_in_a0 : 1;
    Uint32 latch_and_clr_stat_free_stage_p1a0 : 1;
    Uint32 latch_and_clr_stat_free_ant_p1a0 : 1;
    Uint32 latch_and_clr_stat_distance_p1a0s1 : 1;
    Uint32 latch_and_clr_stat_pk_p1a0s1 : 1;
    Uint32 latch_and_clr_stat_distance_p1a0s0 : 1;
    Uint32 latch_and_clr_stat_pk_p1a0s0 : 1;
    Uint32 latch_and_clr_stat_free_stage_p0a0 : 1;
    Uint32 latch_and_clr_stat_free_ant_p0a0 : 1;
    Uint32 latch_and_clr_stat_distance_p0a0s1 : 1;
    Uint32 latch_and_clr_stat_pk_p0a0s1 : 1;
    Uint32 latch_and_clr_stat_distance_p0a0s0 : 1;
    Uint32 latch_and_clr_stat_pk_p0a0s0 : 1;
#else 
    Uint32 latch_and_clr_stat_pk_p0a0s0 : 1;
    Uint32 latch_and_clr_stat_distance_p0a0s0 : 1;
    Uint32 latch_and_clr_stat_pk_p0a0s1 : 1;
    Uint32 latch_and_clr_stat_distance_p0a0s1 : 1;
    Uint32 latch_and_clr_stat_free_ant_p0a0 : 1;
    Uint32 latch_and_clr_stat_free_stage_p0a0 : 1;
    Uint32 latch_and_clr_stat_pk_p1a0s0 : 1;
    Uint32 latch_and_clr_stat_distance_p1a0s0 : 1;
    Uint32 latch_and_clr_stat_pk_p1a0s1 : 1;
    Uint32 latch_and_clr_stat_distance_p1a0s1 : 1;
    Uint32 latch_and_clr_stat_free_ant_p1a0 : 1;
    Uint32 latch_and_clr_stat_free_stage_p1a0 : 1;
    Uint32 latch_and_clr_stat_ravg_in_a0 : 1;
    Uint32 latch_and_clr_stat_ravg_out_a0 : 1;
    Uint32 rsvd0 : 18;
#endif 
} CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG;

/* Latch the number of peaks allocated and number of peaks missed in PDC0 for antenna #0 stage #0 into the shadow registers, and clear the active counters. */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A0S0_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A0S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A0S0_RESETVAL (0x00000000u)

/* Latch the minimum distance between peaks in PDC0 for antenna #0 stage #0 into the shadow register, and clear the active counter. */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A0S0_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A0S0_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A0S0_RESETVAL (0x00000000u)

/* Latch the number of peaks allocated and number of peaks missed in PDC0 for antenna #0 stage #1 into the shadow registers, and clear the active counters. */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A0S1_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A0S1_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A0S1_RESETVAL (0x00000000u)

/* Latch the minimum distance between peaks in PDC0 for antenna #0 stage #1 into the shadow register, and clear the active counter. */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A0S1_MASK (0x00000008u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A0S1_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A0S1_RESETVAL (0x00000000u)

/* Store free canceller per antenna into for antenna0 */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P0A0_MASK (0x00000010u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P0A0_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P0A0_RESETVAL (0x00000000u)

/* Store free canceller per stage      into for antenna0 */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P0A0_MASK (0x00000020u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P0A0_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P0A0_RESETVAL (0x00000000u)

/* Latch the number of peaks allocated and number of peaks missed in PDC0 for antenna #0 stage #0 into the shadow registers, and clear the active counters. */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A0S0_MASK (0x00000040u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A0S0_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A0S0_RESETVAL (0x00000000u)

/* Latch the minimum distance between peaks in PDC0 for antenna #0 stage #0 into the shadow register, and clear the active counter. */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A0S0_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A0S0_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A0S0_RESETVAL (0x00000000u)

/* Latch the number of peaks allocated and number of peaks missed in PDC0 for antenna #0 stage #1 into the shadow registers, and clear the active counters. */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A0S1_MASK (0x00000100u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A0S1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A0S1_RESETVAL (0x00000000u)

/* Latch the minimum distance between peaks in PDC0 for antenna #0 stage #1 into the shadow register, and clear the active counter. */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A0S1_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A0S1_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A0S1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P1A0_MASK (0x00000400u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P1A0_SHIFT (0x0000000Au)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P1A0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P1A0_MASK (0x00000800u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P1A0_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P1A0_RESETVAL (0x00000000u)

/* Latch AGC power running average for CFR input for antenna #0 into the shadow register. The active registers is not getting cleared! */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_IN_A0_MASK (0x00001000u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_IN_A0_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_IN_A0_RESETVAL (0x00000000u)

/* Latch AGC power running average for CFR output for antenna #0 into the shadow register. The active registers is not getting cleared! */
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_OUT_A0_MASK (0x00002000u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_OUT_A0_SHIFT (0x0000000Du)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_OUT_A0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_ADDR (0x000003C0u)
#define CSL_DFE_CFR_CFR0_LATCH_AND_CLR_STAT_REG_RESETVAL (0x00000000u)

/* CFR1_LATCH_AND_CLR_STAT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 18;
    Uint32 latch_and_clr_stat_ravg_out_a1 : 1;
    Uint32 latch_and_clr_stat_ravg_in_a1 : 1;
    Uint32 latch_and_clr_stat_free_stage_p1a1 : 1;
    Uint32 latch_and_clr_stat_free_ant_p1a1 : 1;
    Uint32 latch_and_clr_stat_distance_p1a1s1 : 1;
    Uint32 latch_and_clr_stat_pk_p1a1s1 : 1;
    Uint32 latch_and_clr_stat_distance_p1a1s0 : 1;
    Uint32 latch_and_clr_stat_pk_p1a1s0 : 1;
    Uint32 latch_and_clr_stat_free_stage_p0a1 : 1;
    Uint32 latch_and_clr_stat_free_ant_p0a1 : 1;
    Uint32 latch_and_clr_stat_distance_p0a1s1 : 1;
    Uint32 latch_and_clr_stat_pk_p0a1s1 : 1;
    Uint32 latch_and_clr_stat_distance_p0a1s0 : 1;
    Uint32 latch_and_clr_stat_pk_p0a1s0 : 1;
#else 
    Uint32 latch_and_clr_stat_pk_p0a1s0 : 1;
    Uint32 latch_and_clr_stat_distance_p0a1s0 : 1;
    Uint32 latch_and_clr_stat_pk_p0a1s1 : 1;
    Uint32 latch_and_clr_stat_distance_p0a1s1 : 1;
    Uint32 latch_and_clr_stat_free_ant_p0a1 : 1;
    Uint32 latch_and_clr_stat_free_stage_p0a1 : 1;
    Uint32 latch_and_clr_stat_pk_p1a1s0 : 1;
    Uint32 latch_and_clr_stat_distance_p1a1s0 : 1;
    Uint32 latch_and_clr_stat_pk_p1a1s1 : 1;
    Uint32 latch_and_clr_stat_distance_p1a1s1 : 1;
    Uint32 latch_and_clr_stat_free_ant_p1a1 : 1;
    Uint32 latch_and_clr_stat_free_stage_p1a1 : 1;
    Uint32 latch_and_clr_stat_ravg_in_a1 : 1;
    Uint32 latch_and_clr_stat_ravg_out_a1 : 1;
    Uint32 rsvd0 : 18;
#endif 
} CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG;

/* Latch the number of peaks allocated and number of peaks missed in PDC0 for antenna #1 stage #1 into the shadow registers, and clear the active counters. */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A1S0_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A1S0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A1S0_RESETVAL (0x00000000u)

/* Latch the minimum distance between peaks in PDC0 for antenna #1 stage #1 into the shadow register, and clear the active counter. */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A1S0_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A1S0_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A1S0_RESETVAL (0x00000000u)

/* Latch the number of peaks allocated and number of peaks missed in PDC0 for antenna #1 stage #1 into the shadow registers, and clear the active counters. */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A1S1_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A1S1_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P0A1S1_RESETVAL (0x00000000u)

/* Latch the minimum distance between peaks in PDC0 for antenna #1 stage #1 into the shadow register, and clear the active counter. */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A1S1_MASK (0x00000008u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A1S1_SHIFT (0x00000003u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P0A1S1_RESETVAL (0x00000000u)

/* Store free canceller per antenna into for antenna0 */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P0A1_MASK (0x00000010u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P0A1_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P0A1_RESETVAL (0x00000000u)

/* Store free canceller per stage      into for antenna0 */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P0A1_MASK (0x00000020u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P0A1_SHIFT (0x00000005u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P0A1_RESETVAL (0x00000000u)

/* Latch the number of peaks allocated and number of peaks missed in PDC0 for antenna #1 stage #1 into the shadow registers, and clear the active counters. */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A1S0_MASK (0x00000040u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A1S0_SHIFT (0x00000006u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A1S0_RESETVAL (0x00000000u)

/* Latch the minimum distance between peaks in PDC0 for antenna #1 stage #1 into the shadow register, and clear the active counter. */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A1S0_MASK (0x00000080u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A1S0_SHIFT (0x00000007u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A1S0_RESETVAL (0x00000000u)

/* Latch the number of peaks allocated and number of peaks missed in PDC0 for antenna #1 stage #1 into the shadow registers, and clear the active counters. */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A1S1_MASK (0x00000100u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A1S1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_PK_P1A1S1_RESETVAL (0x00000000u)

/* Latch the minimum distance between peaks in PDC0 for antenna #1 stage #1 into the shadow register, and clear the active counter. */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A1S1_MASK (0x00000200u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A1S1_SHIFT (0x00000009u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_DISTANCE_P1A1S1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P1A1_MASK (0x00000400u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P1A1_SHIFT (0x0000000Au)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_ANT_P1A1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P1A1_MASK (0x00000800u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P1A1_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_FREE_STAGE_P1A1_RESETVAL (0x00000000u)

/* Latch AGC power running average for CFR input for antenna #1 into the shadow register. The active registers is not getting cleared! */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_IN_A1_MASK (0x00001000u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_IN_A1_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_IN_A1_RESETVAL (0x00000000u)

/* Latch AGC power running average for CFR output for antenna #1 into the shadow register. The active registers is not getting cleared! */
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_OUT_A1_MASK (0x00002000u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_OUT_A1_SHIFT (0x0000000Du)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_LATCH_AND_CLR_STAT_RAVG_OUT_A1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_ADDR (0x000003C4u)
#define CSL_DFE_CFR_CFR1_LATCH_AND_CLR_STAT_REG_RESETVAL (0x00000000u)

/* CFR_TEST_BUS_MUX */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 cfr_test_bus_mux_sc0 : 9;
#else 
    Uint32 cfr_test_bus_mux_sc0 : 9;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_CFR_CFR_TEST_BUS_MUX_REG;

/* 000: test_bus = {38 {1'b0}} */
#define CSL_DFE_CFR_CFR_TEST_BUS_MUX_REG_CFR_TEST_BUS_MUX_SC0_MASK (0x000001FFu)
#define CSL_DFE_CFR_CFR_TEST_BUS_MUX_REG_CFR_TEST_BUS_MUX_SC0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_TEST_BUS_MUX_REG_CFR_TEST_BUS_MUX_SC0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_TEST_BUS_MUX_REG_ADDR (0x000003C8u)
#define CSL_DFE_CFR_CFR_TEST_BUS_MUX_REG_RESETVAL (0x00000000u)

/* CFR_CFR_CONFIG0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cfr_test_sync_rlsd : 1;
    Uint32 cfr_mxs_step_sc0_a1 : 3;
    Uint32 cfr_mxs_combine_sc0 : 1;
    Uint32 cfr_mxs_step_sc0_a0 : 3;
    Uint32 rsvd0 : 3;
    Uint32 cfr_config0 : 5;
#else 
    Uint32 cfr_config0 : 5;
    Uint32 rsvd0 : 3;
    Uint32 cfr_mxs_step_sc0_a0 : 3;
    Uint32 cfr_mxs_combine_sc0 : 1;
    Uint32 cfr_mxs_step_sc0_a1 : 3;
    Uint32 cfr_test_sync_rlsd : 1;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_CFR_CFR_CFR_CONFIG0_REG;

/* CFR configuration mode. If config[4] = 0m config[3:0] would be one of the gc5330 configurations. */
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_CONFIG0_MASK (0x0000001Fu)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_CONFIG0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_CONFIG0_RESETVAL (0x00000006u)

/* Modulation in Sampling_rate/8 steps for antenna #0. */
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_MXS_STEP_SC0_A0_MASK (0x00000700u)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_MXS_STEP_SC0_A0_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_MXS_STEP_SC0_A0_RESETVAL (0x00000000u)

/* Combine 2 antennas into 1 */
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_MXS_COMBINE_SC0_MASK (0x00000800u)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_MXS_COMBINE_SC0_SHIFT (0x0000000Bu)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_MXS_COMBINE_SC0_RESETVAL (0x00000000u)

/* Modulation in Sampling_rate/8 steps for antenna #1. */
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_MXS_STEP_SC0_A1_MASK (0x00007000u)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_MXS_STEP_SC0_A1_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_MXS_STEP_SC0_A1_RESETVAL (0x00000000u)

/* Syncs the release of all cancellers to cp_alloc_cycle to match C model sample resolution */
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_TEST_SYNC_RLSD_MASK (0x00008000u)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_TEST_SYNC_RLSD_SHIFT (0x0000000Fu)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_CFR_TEST_SYNC_RLSD_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_ADDR (0x000003CCu)
#define CSL_DFE_CFR_CFR_CFR_CONFIG0_REG_RESETVAL (0x00000006u)

/* CFR_CFR_STATUS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 30;
    Uint32 cfr_status_p1 : 1;
    Uint32 cfr_status_p0 : 1;
#else 
    Uint32 cfr_status_p0 : 1;
    Uint32 cfr_status_p1 : 1;
    Uint32 rsvd0 : 30;
#endif 
} CSL_DFE_CFR_CFR_CFR_STATUS_REG;

/* 0: The shadow LUT in PDC0 is accessible to MPU for programming. */
#define CSL_DFE_CFR_CFR_CFR_STATUS_REG_CFR_STATUS_P0_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_CFR_STATUS_REG_CFR_STATUS_P0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CFR_STATUS_REG_CFR_STATUS_P0_RESETVAL (0x00000000u)

/* 0: The shadow LUT in PDC1 is accessible to MPU for programming. */
#define CSL_DFE_CFR_CFR_CFR_STATUS_REG_CFR_STATUS_P1_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR_CFR_STATUS_REG_CFR_STATUS_P1_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR_CFR_STATUS_REG_CFR_STATUS_P1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CFR_STATUS_REG_ADDR (0x000003D0u)
#define CSL_DFE_CFR_CFR_CFR_STATUS_REG_RESETVAL (0x00000000u)

/* CFR0_CFR_SCMODE_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 cfr_cl_bypass_0 : 1;
    Uint32 cfr_post_bypass_0 : 1;
    Uint32 cfr_prem_bypass_0 : 1;
#else 
    Uint32 cfr_prem_bypass_0 : 1;
    Uint32 cfr_post_bypass_0 : 1;
    Uint32 cfr_cl_bypass_0 : 1;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG;

/* Bypass prem (Pre CFR multiplier) for antenna #0 */
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_CFR_PREM_BYPASS_0_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_CFR_PREM_BYPASS_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_CFR_PREM_BYPASS_0_RESETVAL (0x00000000u)

/* Bypass postm (Post CFR multiplier) for antenna #0 */
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_CFR_POST_BYPASS_0_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_CFR_POST_BYPASS_0_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_CFR_POST_BYPASS_0_RESETVAL (0x00000000u)

/* Bypass cl (Circular clipper/limiter) for antenna #0 */
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_CFR_CL_BYPASS_0_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_CFR_CL_BYPASS_0_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_CFR_CL_BYPASS_0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_ADDR (0x000003D8u)
#define CSL_DFE_CFR_CFR0_CFR_SCMODE_A0_REG_RESETVAL (0x00000000u)

/* CFR1_CFR_SCMODE_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 cfr_cl_bypass_1 : 1;
    Uint32 cfr_post_bypass_1 : 1;
    Uint32 cfr_prem_bypass_1 : 1;
#else 
    Uint32 cfr_prem_bypass_1 : 1;
    Uint32 cfr_post_bypass_1 : 1;
    Uint32 cfr_cl_bypass_1 : 1;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG;

/* Bypass prem (Pre CFR multiplier) for antenna #1 */
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_CFR_PREM_BYPASS_1_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_CFR_PREM_BYPASS_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_CFR_PREM_BYPASS_1_RESETVAL (0x00000000u)

/* Bypass postm (Post CFR multiplier) for antenna #1 */
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_CFR_POST_BYPASS_1_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_CFR_POST_BYPASS_1_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_CFR_POST_BYPASS_1_RESETVAL (0x00000000u)

/* Bypass cl (Circular clipper/limiter) for antenna #1 */
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_CFR_CL_BYPASS_1_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_CFR_CL_BYPASS_1_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_CFR_CL_BYPASS_1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_ADDR (0x000003DCu)
#define CSL_DFE_CFR_CFR1_CFR_SCMODE_A1_REG_RESETVAL (0x00000000u)

/* CFR0_AGC_STAT_RAVG_IN_A0_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 agc_stat_ravg_in_a0_lo : 16;
#else 
    Uint32 agc_stat_ravg_in_a0_lo : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_LO_REG;

/* AGC power running average for the CFR input for antenna #0 */
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_LO_REG_AGC_STAT_RAVG_IN_A0_LO_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_LO_REG_AGC_STAT_RAVG_IN_A0_LO_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_LO_REG_AGC_STAT_RAVG_IN_A0_LO_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_LO_REG_ADDR (0x000003E0u)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_LO_REG_RESETVAL (0x00000000u)

/* CFR0_AGC_STAT_RAVG_IN_A0_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 agc_stat_ravg_in_a0_hi : 16;
#else 
    Uint32 agc_stat_ravg_in_a0_hi : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_HI_REG;

/* AGC power running average for the CFR input for antenna #0 */
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_HI_REG_AGC_STAT_RAVG_IN_A0_HI_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_HI_REG_AGC_STAT_RAVG_IN_A0_HI_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_HI_REG_AGC_STAT_RAVG_IN_A0_HI_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_HI_REG_ADDR (0x000003E4u)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_IN_A0_HI_REG_RESETVAL (0x00000000u)

/* CFR1_AGC_STAT_RAVG_IN_A1_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 agc_stat_ravg_in_a1_lo : 16;
#else 
    Uint32 agc_stat_ravg_in_a1_lo : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_LO_REG;

/* AGC power running average for the CFR input for antenna #1 */
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_LO_REG_AGC_STAT_RAVG_IN_A1_LO_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_LO_REG_AGC_STAT_RAVG_IN_A1_LO_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_LO_REG_AGC_STAT_RAVG_IN_A1_LO_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_LO_REG_ADDR (0x000003E8u)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_LO_REG_RESETVAL (0x00000000u)

/* CFR1_AGC_STAT_RAVG_IN_A1_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 agc_stat_ravg_in_a1_hi : 16;
#else 
    Uint32 agc_stat_ravg_in_a1_hi : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_HI_REG;

/* AGC power running average for the CFR input for antenna #1 */
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_HI_REG_AGC_STAT_RAVG_IN_A1_HI_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_HI_REG_AGC_STAT_RAVG_IN_A1_HI_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_HI_REG_AGC_STAT_RAVG_IN_A1_HI_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_HI_REG_ADDR (0x000003ECu)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_IN_A1_HI_REG_RESETVAL (0x00000000u)

/* CFR0_AGC_STAT_RAVG_OUT_A0_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 agc_stat_ravg_out_a0_lo : 16;
#else 
    Uint32 agc_stat_ravg_out_a0_lo : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_LO_REG;

/* AGC power running average for the CFR output for antenna #0 */
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_LO_REG_AGC_STAT_RAVG_OUT_A0_LO_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_LO_REG_AGC_STAT_RAVG_OUT_A0_LO_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_LO_REG_AGC_STAT_RAVG_OUT_A0_LO_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_LO_REG_ADDR (0x000003F0u)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_LO_REG_RESETVAL (0x00000000u)

/* CFR0_AGC_STAT_RAVG_OUT_A0_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 agc_stat_ravg_out_a0_hi : 16;
#else 
    Uint32 agc_stat_ravg_out_a0_hi : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_HI_REG;

/* AGC power running average for the CFR output for antenna #0 */
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_HI_REG_AGC_STAT_RAVG_OUT_A0_HI_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_HI_REG_AGC_STAT_RAVG_OUT_A0_HI_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_HI_REG_AGC_STAT_RAVG_OUT_A0_HI_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_HI_REG_ADDR (0x000003F4u)
#define CSL_DFE_CFR_CFR0_AGC_STAT_RAVG_OUT_A0_HI_REG_RESETVAL (0x00000000u)

/* CFR1_AGC_STAT_RAVG_OUT_A1_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 agc_stat_ravg_out_a1_lo : 16;
#else 
    Uint32 agc_stat_ravg_out_a1_lo : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_LO_REG;

/* AGC power running average for the CFR output for antenna #1 */
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_LO_REG_AGC_STAT_RAVG_OUT_A1_LO_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_LO_REG_AGC_STAT_RAVG_OUT_A1_LO_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_LO_REG_AGC_STAT_RAVG_OUT_A1_LO_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_LO_REG_ADDR (0x000003F8u)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_LO_REG_RESETVAL (0x00000000u)

/* CFR1_AGC_STAT_RAVG_OUT_A1_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 agc_stat_ravg_out_a1_hi : 16;
#else 
    Uint32 agc_stat_ravg_out_a1_hi : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_HI_REG;

/* AGC power running average for the CFR output for antenna #1 */
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_HI_REG_AGC_STAT_RAVG_OUT_A1_HI_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_HI_REG_AGC_STAT_RAVG_OUT_A1_HI_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_HI_REG_AGC_STAT_RAVG_OUT_A1_HI_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_HI_REG_ADDR (0x000003FCu)
#define CSL_DFE_CFR_CFR1_AGC_STAT_RAVG_OUT_A1_HI_REG_RESETVAL (0x00000000u)

/* CFR0_CFR_UPDT_GEN_0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_syncgen_frm_ssel : 4;
    Uint32 cfr_agc_start_ssel : 4;
    Uint32 cfr_postm_0_ssel : 4;
    Uint32 cfr_prem_0_ssel : 4;
#else 
    Uint32 cfr_prem_0_ssel : 4;
    Uint32 cfr_postm_0_ssel : 4;
    Uint32 cfr_agc_start_ssel : 4;
    Uint32 cfr_syncgen_frm_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG;

/* Load active gain of Pre multiplier for antenna #0 from its shadow */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_PREM_0_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_PREM_0_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_PREM_0_SSEL_RESETVAL (0x00000000u)

/* Load active gain of Post multiplier for antenna #0 from its shadow */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_POSTM_0_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_POSTM_0_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_POSTM_0_SSEL_RESETVAL (0x00000000u)

/* Start AGC for antenna #0 */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_AGC_START_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_AGC_START_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_AGC_START_SSEL_RESETVAL (0x00000000u)

/* sc_sync_mux2cfr */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_SYNCGEN_FRM_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_SYNCGEN_FRM_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_CFR_SYNCGEN_FRM_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_ADDR (0x00000600u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_0_REG_RESETVAL (0x00000000u)

/* CFR1_CFR_UPDT_GEN_1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_syncgen_frm_ssel : 4;
    Uint32 cfr_agc_start_ssel : 4;
    Uint32 cfr_postm_0_ssel : 4;
    Uint32 cfr_prem_0_ssel : 4;
#else 
    Uint32 cfr_prem_0_ssel : 4;
    Uint32 cfr_postm_0_ssel : 4;
    Uint32 cfr_agc_start_ssel : 4;
    Uint32 cfr_syncgen_frm_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG;

/* Load active gain of Pre multiplier for antenna #1 from its shadow */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_PREM_0_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_PREM_0_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_PREM_0_SSEL_RESETVAL (0x00000000u)

/* Load active gain of Post multiplier for antenna #1 from its shadow */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_POSTM_0_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_POSTM_0_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_POSTM_0_SSEL_RESETVAL (0x00000000u)

/* Start AGC for antenna #1 */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_AGC_START_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_AGC_START_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_AGC_START_SSEL_RESETVAL (0x00000000u)

/* sc_sync_mux2cfr */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_SYNCGEN_FRM_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_SYNCGEN_FRM_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_CFR_SYNCGEN_FRM_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_ADDR (0x00000604u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_1_REG_RESETVAL (0x00000000u)

/* CFR_CFR_UPDT_GEN_2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_lut_p1_f1_sc0_ssel : 4;
    Uint32 cfr_lut_p1_f0_sc0_ssel : 4;
    Uint32 cfr_lut_p0_f1_sc0_ssel : 4;
    Uint32 cfr_lut_p0_f0_sc0_ssel : 4;
#else 
    Uint32 cfr_lut_p0_f0_sc0_ssel : 4;
    Uint32 cfr_lut_p0_f1_sc0_ssel : 4;
    Uint32 cfr_lut_p1_f0_sc0_ssel : 4;
    Uint32 cfr_lut_p1_f1_sc0_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG;

/* synch for Updating LUT tables for the base filter in PDC0 */
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P0_F0_SC0_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P0_F0_SC0_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P0_F0_SC0_SSEL_RESETVAL (0x00000000u)

/* synch for Updating LUT tables for the half delayed filter in PDC0 */
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P0_F1_SC0_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P0_F1_SC0_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P0_F1_SC0_SSEL_RESETVAL (0x00000000u)

/* synch for Updating LUT tables for the base filter in PDC1 */
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P1_F0_SC0_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P1_F0_SC0_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P1_F0_SC0_SSEL_RESETVAL (0x00000000u)

/* synch for Updating LUT tables for the half delayed filter in PDC1 */
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P1_F1_SC0_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P1_F1_SC0_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_CFR_LUT_P1_F1_SC0_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_ADDR (0x00000608u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_2_REG_RESETVAL (0x00000000u)

/* CFR_CFR_UPDT_GEN_3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_clr_busy_p1_sc0_ssel : 4;
    Uint32 cfr_clr_busy_p0_sc0_ssel : 4;
    Uint32 cfr_sig_gen_sc0_ssel : 4;
    Uint32 cfr_stats_sc0_ssel : 4;
#else 
    Uint32 cfr_stats_sc0_ssel : 4;
    Uint32 cfr_sig_gen_sc0_ssel : 4;
    Uint32 cfr_clr_busy_p0_sc0_ssel : 4;
    Uint32 cfr_clr_busy_p1_sc0_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG;

/* synch for latching all requested statistics into shadow registers, and clearing their corresponding active registers if applicable. */
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_STATS_SC0_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_STATS_SC0_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_STATS_SC0_SSEL_RESETVAL (0x00000000u)

/* Start the signal generator */
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_SIG_GEN_SC0_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_SIG_GEN_SC0_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_SIG_GEN_SC0_SSEL_RESETVAL (0x00000000u)

/* sync for clearing/stopping the Update Luts busy counter in PDC0 */
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_CLR_BUSY_P0_SC0_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_CLR_BUSY_P0_SC0_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_CLR_BUSY_P0_SC0_SSEL_RESETVAL (0x00000000u)

/* sync for clearing/stopping the Update Luts busy counter in PDC1 */
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_CLR_BUSY_P1_SC0_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_CLR_BUSY_P1_SC0_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_CFR_CLR_BUSY_P1_SC0_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_ADDR (0x0000060Cu)
#define CSL_DFE_CFR_CFR_CFR_UPDT_GEN_3_REG_RESETVAL (0x00000000u)

/* CFR0_CFR_UPDT_GEN_4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 cfr_th_a0_ssel : 4;
    Uint32 cfr_clr_cp_p1_a0_ssel : 4;
    Uint32 cfr_clr_cp_p0_a0_ssel : 4;
#else 
    Uint32 cfr_clr_cp_p0_a0_ssel : 4;
    Uint32 cfr_clr_cp_p1_a0_ssel : 4;
    Uint32 cfr_th_a0_ssel : 4;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG;

/* Load active gain of Pre multiplier for antenna #0 from its shadow */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_CFR_CLR_CP_P0_A0_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_CFR_CLR_CP_P0_A0_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_CFR_CLR_CP_P0_A0_SSEL_RESETVAL (0x00000000u)

/* Load active gain of Post multiplier for antenna #0 from its shadow */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_CFR_CLR_CP_P1_A0_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_CFR_CLR_CP_P1_A0_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_CFR_CLR_CP_P1_A0_SSEL_RESETVAL (0x00000000u)

/* synch for Updating threshold registers (Detect and target) for antenna #0 */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_CFR_TH_A0_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_CFR_TH_A0_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_CFR_TH_A0_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_ADDR (0x00000610u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_4_REG_RESETVAL (0x00000000u)

/* CFR1_CFR_UPDT_GEN_5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 cfr_th_a1_ssel : 4;
    Uint32 cfr_clr_cp_p1_a1_ssel : 4;
    Uint32 cfr_clr_cp_p0_a1_ssel : 4;
#else 
    Uint32 cfr_clr_cp_p0_a1_ssel : 4;
    Uint32 cfr_clr_cp_p1_a1_ssel : 4;
    Uint32 cfr_th_a1_ssel : 4;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG;

/* Load active gain of Pre multiplier for antenna #1 from its shadow */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_CFR_CLR_CP_P0_A1_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_CFR_CLR_CP_P0_A1_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_CFR_CLR_CP_P0_A1_SSEL_RESETVAL (0x00000000u)

/* Load active gain of Post multiplier for antenna #1 from its shadow */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_CFR_CLR_CP_P1_A1_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_CFR_CLR_CP_P1_A1_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_CFR_CLR_CP_P1_A1_SSEL_RESETVAL (0x00000000u)

/* synch for Updating threshold registers (Detect and target) for antenna #1 */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_CFR_TH_A1_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_CFR_TH_A1_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_CFR_TH_A1_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_ADDR (0x00000614u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_5_REG_RESETVAL (0x00000000u)

/* CFR0_CFR_UPDT_GEN_6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_resume_alloc_p1_a0_ssel : 4;
    Uint32 cfr_stop_alloc_p1_a0s_ssel : 4;
    Uint32 cfr_resume_alloc_p0_a0_ssel : 4;
    Uint32 cfr_stop_alloc_p0_a0_ssel : 4;
#else 
    Uint32 cfr_stop_alloc_p0_a0_ssel : 4;
    Uint32 cfr_resume_alloc_p0_a0_ssel : 4;
    Uint32 cfr_stop_alloc_p1_a0s_ssel : 4;
    Uint32 cfr_resume_alloc_p1_a0_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG;

/* Load active gain of Pre multiplier for antenna #0 from its shadow */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_STOP_ALLOC_P0_A0_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_STOP_ALLOC_P0_A0_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_STOP_ALLOC_P0_A0_SSEL_RESETVAL (0x00000000u)

/* Load active gain of Post multiplier for antenna #0 from its shadow */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_RESUME_ALLOC_P0_A0_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_RESUME_ALLOC_P0_A0_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_RESUME_ALLOC_P0_A0_SSEL_RESETVAL (0x00000000u)

/* synch for Updating threshold registers (Detect and target) for antenna #0 */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_STOP_ALLOC_P1_A0S_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_STOP_ALLOC_P1_A0S_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_STOP_ALLOC_P1_A0S_SSEL_RESETVAL (0x00000000u)

/* Not used */
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_RESUME_ALLOC_P1_A0_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_RESUME_ALLOC_P1_A0_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_CFR_RESUME_ALLOC_P1_A0_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_ADDR (0x00000618u)
#define CSL_DFE_CFR_CFR0_CFR_UPDT_GEN_6_REG_RESETVAL (0x00000000u)

/* CFR1_CFR_UPDT_GEN_7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_resume_alloc_p1_a1_ssel : 4;
    Uint32 cfr_stop_alloc_p1_a1_ssel : 4;
    Uint32 cfr_resume_alloc_p0_a1_ssel : 4;
    Uint32 cfr_stop_alloc_p0_a1_ssel : 4;
#else 
    Uint32 cfr_stop_alloc_p0_a1_ssel : 4;
    Uint32 cfr_resume_alloc_p0_a1_ssel : 4;
    Uint32 cfr_stop_alloc_p1_a1_ssel : 4;
    Uint32 cfr_resume_alloc_p1_a1_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG;

/* Load active gain of Pre multiplier for antenna #1 from its shadow */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_STOP_ALLOC_P0_A1_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_STOP_ALLOC_P0_A1_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_STOP_ALLOC_P0_A1_SSEL_RESETVAL (0x00000000u)

/* Load active gain of Post multiplier for antenna #1 from its shadow */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_RESUME_ALLOC_P0_A1_SSEL_MASK (0x000000F0u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_RESUME_ALLOC_P0_A1_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_RESUME_ALLOC_P0_A1_SSEL_RESETVAL (0x00000000u)

/* synch for Updating threshold registers (Detect and target) for antenna #1 */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_STOP_ALLOC_P1_A1_SSEL_MASK (0x00000F00u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_STOP_ALLOC_P1_A1_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_STOP_ALLOC_P1_A1_SSEL_RESETVAL (0x00000000u)

/* Not used */
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_RESUME_ALLOC_P1_A1_SSEL_MASK (0x0000F000u)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_RESUME_ALLOC_P1_A1_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_CFR_RESUME_ALLOC_P1_A1_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_ADDR (0x0000061Cu)
#define CSL_DFE_CFR_CFR1_CFR_UPDT_GEN_7_REG_RESETVAL (0x00000000u)

/* CFR_SIG_GEN_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cfr_sig_gen_frame_len_m1 : 12;
    Uint32 rsvd0 : 1;
    Uint32 cfr_sig_gen_ramp_mode : 1;
    Uint32 cfr_sig_gen_frame : 1;
    Uint32 cfr_sig_gen_data : 1;
#else 
    Uint32 cfr_sig_gen_data : 1;
    Uint32 cfr_sig_gen_frame : 1;
    Uint32 cfr_sig_gen_ramp_mode : 1;
    Uint32 rsvd0 : 1;
    Uint32 cfr_sig_gen_frame_len_m1 : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_RAMP_MODE_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_CFR_SIG_GEN_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_ADDR (0x00000640u)
#define CSL_DFE_CFR_CFR_SIG_GEN_MODE_REG_RESETVAL (0x00000000u)

/* CFR_SIG_GEN_RAMP_START_LSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_sig_gen_ramp_start_15_0 : 16;
#else 
    Uint32 cfr_sig_gen_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_LSW_REG;

/* 16LSB of ramp starting value */
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_LSW_REG_CFR_SIG_GEN_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_LSW_REG_CFR_SIG_GEN_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_LSW_REG_CFR_SIG_GEN_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_LSW_REG_ADDR (0x00000644u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_LSW_REG_RESETVAL (0x00000000u)

/* CFR_SIG_GEN_RAMP_START_MSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_sig_gen_ramp_start_31_16 : 16;
#else 
    Uint32 cfr_sig_gen_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_MSW_REG;

/* 16MSB of ramp starting value */
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_MSW_REG_CFR_SIG_GEN_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_MSW_REG_CFR_SIG_GEN_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_MSW_REG_CFR_SIG_GEN_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_MSW_REG_ADDR (0x00000648u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_START_MSW_REG_RESETVAL (0x00000000u)

/* CFR_SIG_GEN_RAMP_STOP_LSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_sig_gen_ramp_stop_15_0 : 16;
#else 
    Uint32 cfr_sig_gen_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_LSW_REG;

/* 16LSB of ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_LSW_REG_CFR_SIG_GEN_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_LSW_REG_CFR_SIG_GEN_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_LSW_REG_CFR_SIG_GEN_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_LSW_REG_ADDR (0x0000064Cu)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_LSW_REG_RESETVAL (0x00000000u)

/* CFR_SIG_GEN_RAMP_STOP_MSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_sig_gen_ramp_start_31_16 : 16;
#else 
    Uint32 cfr_sig_gen_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_MSW_REG;

/* 16MSB of ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_MSW_REG_CFR_SIG_GEN_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_MSW_REG_CFR_SIG_GEN_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_MSW_REG_CFR_SIG_GEN_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_MSW_REG_ADDR (0x00000650u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_STOP_MSW_REG_RESETVAL (0x00000000u)

/* CFR_SIG_GEN_RAMP_SLOPE_LSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_sig_gen_ramp_slope_15_0 : 16;
#else 
    Uint32 cfr_sig_gen_ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_LSW_REG;

/* 16LSB of ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_LSW_REG_CFR_SIG_GEN_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_LSW_REG_CFR_SIG_GEN_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_LSW_REG_CFR_SIG_GEN_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_LSW_REG_ADDR (0x00000654u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_LSW_REG_RESETVAL (0x00000000u)

/* CFR_SIG_GEN_RAMP_SLOPE_MSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_sig_gen_ramp_start_31_16 : 16;
#else 
    Uint32 cfr_sig_gen_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_MSW_REG;

/* 16MSB of ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_MSW_REG_CFR_SIG_GEN_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_MSW_REG_CFR_SIG_GEN_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_MSW_REG_CFR_SIG_GEN_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_MSW_REG_ADDR (0x00000658u)
#define CSL_DFE_CFR_CFR_SIG_GEN_RAMP_SLOPE_MSW_REG_RESETVAL (0x00000000u)

/* CFR_SIG_GEN_PULSE_WIDTH */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_sig_gen_pulse_width : 16;
#else 
    Uint32 cfr_sig_gen_pulse_width : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_SIG_GEN_PULSE_WIDTH_REG;

/* n=0: generate data forever, n>0: generate data for n clock cycles */
#define CSL_DFE_CFR_CFR_SIG_GEN_PULSE_WIDTH_REG_CFR_SIG_GEN_PULSE_WIDTH_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_SIG_GEN_PULSE_WIDTH_REG_CFR_SIG_GEN_PULSE_WIDTH_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_SIG_GEN_PULSE_WIDTH_REG_CFR_SIG_GEN_PULSE_WIDTH_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_SIG_GEN_PULSE_WIDTH_REG_ADDR (0x0000065Cu)
#define CSL_DFE_CFR_CFR_SIG_GEN_PULSE_WIDTH_REG_RESETVAL (0x00000000u)

/* CFR_SIG_GEN_BITS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_sig_gen_bits : 16;
#else 
    Uint32 cfr_sig_gen_bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_SIG_GEN_BITS_REG;

/* INTERNAL ONLY: */
#define CSL_DFE_CFR_CFR_SIG_GEN_BITS_REG_CFR_SIG_GEN_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_SIG_GEN_BITS_REG_CFR_SIG_GEN_BITS_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_SIG_GEN_BITS_REG_CFR_SIG_GEN_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_SIG_GEN_BITS_REG_ADDR (0x00000660u)
#define CSL_DFE_CFR_CFR_SIG_GEN_BITS_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM0_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cfr_check_sum0_latency : 12;
    Uint32 rsvd0 : 3;
    Uint32 cfr_check_sum0_mode : 1;
#else 
    Uint32 cfr_check_sum0_mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 cfr_check_sum0_latency : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM0_MODE_REG;

/* 1 = return latency, 0 = return check sum */
#define CSL_DFE_CFR_CFR_CHECK_SUM0_MODE_REG_CFR_CHECK_SUM0_MODE_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_MODE_REG_CFR_CHECK_SUM0_MODE_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_MODE_REG_CFR_CHECK_SUM0_MODE_RESETVAL (0x00000000u)

/* latency - clocks that data must remain stable after pulse */
#define CSL_DFE_CFR_CFR_CHECK_SUM0_MODE_REG_CFR_CHECK_SUM0_LATENCY_MASK (0x0000FFF0u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_MODE_REG_CFR_CHECK_SUM0_LATENCY_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_MODE_REG_CFR_CHECK_SUM0_LATENCY_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM0_MODE_REG_ADDR (0x00000680u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_MODE_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM0_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum0_signal_len : 16;
#else 
    Uint32 check_sum0_signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM0_SIGNAL_LEN_REG;

/* latency - width of data pulse from signal_gen */
#define CSL_DFE_CFR_CFR_CHECK_SUM0_SIGNAL_LEN_REG_CHECK_SUM0_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_SIGNAL_LEN_REG_CHECK_SUM0_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_SIGNAL_LEN_REG_CHECK_SUM0_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM0_SIGNAL_LEN_REG_ADDR (0x00000684u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM0_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 cfr_check_sum0_chan_sel : 12;
#else 
    Uint32 cfr_check_sum0_chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM0_CHAN_SEL_REG;

/* latency - channel select specified by clocks after frame */
#define CSL_DFE_CFR_CFR_CHECK_SUM0_CHAN_SEL_REG_CFR_CHECK_SUM0_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_CHAN_SEL_REG_CFR_CHECK_SUM0_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_CHAN_SEL_REG_CFR_CHECK_SUM0_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM0_CHAN_SEL_REG_ADDR (0x00000688u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM0_RESULT_LSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum0_result_lsw : 16;
#else 
    Uint32 check_sum0_result_lsw : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_LSW_REG;

/* 16 LSB of result of check sum or latency calculation depending on mode */
#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_LSW_REG_CHECK_SUM0_RESULT_LSW_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_LSW_REG_CHECK_SUM0_RESULT_LSW_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_LSW_REG_CHECK_SUM0_RESULT_LSW_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_LSW_REG_ADDR (0x0000068Cu)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_LSW_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM0_RESULT_MSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum0_result_msw : 16;
#else 
    Uint32 check_sum0_result_msw : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_MSW_REG;

/* 16 LSB of result of check sum or latency calculation depending on mode */
#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_MSW_REG_CHECK_SUM0_RESULT_MSW_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_MSW_REG_CHECK_SUM0_RESULT_MSW_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_MSW_REG_CHECK_SUM0_RESULT_MSW_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_MSW_REG_ADDR (0x00000690u)
#define CSL_DFE_CFR_CFR_CHECK_SUM0_RESULT_MSW_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM1_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 cfr_check_sum1_latency : 12;
    Uint32 rsvd0 : 3;
    Uint32 cfr_check_sum1_mode : 1;
#else 
    Uint32 cfr_check_sum1_mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 cfr_check_sum1_latency : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM1_MODE_REG;

/* 1 = return latency, 0 = return check sum */
#define CSL_DFE_CFR_CFR_CHECK_SUM1_MODE_REG_CFR_CHECK_SUM1_MODE_MASK (0x00000001u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_MODE_REG_CFR_CHECK_SUM1_MODE_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_MODE_REG_CFR_CHECK_SUM1_MODE_RESETVAL (0x00000000u)

/* latency - clocks that data must remain stable after pulse */
#define CSL_DFE_CFR_CFR_CHECK_SUM1_MODE_REG_CFR_CHECK_SUM1_LATENCY_MASK (0x0000FFF0u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_MODE_REG_CFR_CHECK_SUM1_LATENCY_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_MODE_REG_CFR_CHECK_SUM1_LATENCY_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM1_MODE_REG_ADDR (0x000006A0u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_MODE_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM1_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum1_signal_len : 16;
#else 
    Uint32 check_sum1_signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM1_SIGNAL_LEN_REG;

/* latency - width of data pulse from signal_gen */
#define CSL_DFE_CFR_CFR_CHECK_SUM1_SIGNAL_LEN_REG_CHECK_SUM1_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_SIGNAL_LEN_REG_CHECK_SUM1_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_SIGNAL_LEN_REG_CHECK_SUM1_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM1_SIGNAL_LEN_REG_ADDR (0x000006A4u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM1_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 cfr_check_sum1_chan_sel : 12;
#else 
    Uint32 cfr_check_sum1_chan_sel : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM1_CHAN_SEL_REG;

/* latency - channel select specified by clocks after frame */
#define CSL_DFE_CFR_CFR_CHECK_SUM1_CHAN_SEL_REG_CFR_CHECK_SUM1_CHAN_SEL_MASK (0x00000FFFu)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_CHAN_SEL_REG_CFR_CHECK_SUM1_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_CHAN_SEL_REG_CFR_CHECK_SUM1_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM1_CHAN_SEL_REG_ADDR (0x000006A8u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM1_RESULT_LSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum1_result_lsw : 16;
#else 
    Uint32 check_sum1_result_lsw : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_LSW_REG;

/* 16 LSB of result of check sum or latency calculation depending on mode */
#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_LSW_REG_CHECK_SUM1_RESULT_LSW_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_LSW_REG_CHECK_SUM1_RESULT_LSW_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_LSW_REG_CHECK_SUM1_RESULT_LSW_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_LSW_REG_ADDR (0x000006ACu)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_LSW_REG_RESETVAL (0x00000000u)

/* CFR_CHECK_SUM1_RESULT_MSW */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum1_result_msw : 16;
#else 
    Uint32 check_sum1_result_msw : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_MSW_REG;

/* 16 LSB of result of check sum or latency calculation depending on mode */
#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_MSW_REG_CHECK_SUM1_RESULT_MSW_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_MSW_REG_CHECK_SUM1_RESULT_MSW_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_MSW_REG_CHECK_SUM1_RESULT_MSW_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_MSW_REG_ADDR (0x000006B0u)
#define CSL_DFE_CFR_CFR_CHECK_SUM1_RESULT_MSW_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_MODE_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 dth0_en_hyst : 1;
    Uint32 dth0_en_th : 1;
    Uint32 dth0_mode : 2;
    Uint32 dth0_shift : 5;
#else 
    Uint32 dth0_shift : 5;
    Uint32 dth0_mode : 2;
    Uint32 dth0_en_th : 1;
    Uint32 dth0_en_hyst : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG;

/* Shift factor for the AGC or BB power input  for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_SHIFT_MASK (0x0000001Fu)
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_SHIFT_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_SHIFT_RESETVAL (0x00000000u)

/*  for antenna #0: */
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_MODE_MASK (0x00000060u)
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_MODE_SHIFT (0x00000005u)
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_MODE_RESETVAL (0x00000000u)

/* Enable dynamic threshold  for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_EN_TH_MASK (0x00000080u)
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_EN_TH_SHIFT (0x00000007u)
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_EN_TH_RESETVAL (0x00000000u)

/* Enable dynamic hysteresis  for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_EN_HYST_MASK (0x00000100u)
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_EN_HYST_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_DTH0_EN_HYST_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_ADDR (0x000006C0u)
#define CSL_DFE_CFR_DTH0_DTH_MODE_A0_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_MODE_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 dth1_en_hyst : 1;
    Uint32 dth1_en_th : 1;
    Uint32 dth1_mode : 2;
    Uint32 dth1_shift : 5;
#else 
    Uint32 dth1_shift : 5;
    Uint32 dth1_mode : 2;
    Uint32 dth1_en_th : 1;
    Uint32 dth1_en_hyst : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG;

/* Shift factor for the AGC or BB power input for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_SHIFT_MASK (0x0000001Fu)
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_SHIFT_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_SHIFT_RESETVAL (0x00000000u)

/*  for antenna #1: */
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_MODE_MASK (0x00000060u)
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_MODE_SHIFT (0x00000005u)
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_MODE_RESETVAL (0x00000000u)

/* Enable dynamic threshold  for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_EN_TH_MASK (0x00000080u)
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_EN_TH_SHIFT (0x00000007u)
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_EN_TH_RESETVAL (0x00000000u)

/* Enable dynamic hysteresis  for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_EN_HYST_MASK (0x00000100u)
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_EN_HYST_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_DTH1_EN_HYST_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_ADDR (0x000006C4u)
#define CSL_DFE_CFR_DTH1_DTH_MODE_A1_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_T01_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t1 : 16;
#else 
    Uint32 dth0_t1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T01_A0_REG;

/* Power threshold #1 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T01_A0_REG_DTH0_T1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T01_A0_REG_DTH0_T1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T01_A0_REG_DTH0_T1_RESETVAL (0x00000800u)

#define CSL_DFE_CFR_DTH0_DTH_T01_A0_REG_ADDR (0x000006C8u)
#define CSL_DFE_CFR_DTH0_DTH_T01_A0_REG_RESETVAL (0x00000800u)

/* DTH1_DTH_T01_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t1 : 16;
#else 
    Uint32 dth1_t1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T01_A1_REG;

/* Power threshold #1 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T01_A1_REG_DTH1_T1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T01_A1_REG_DTH1_T1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T01_A1_REG_DTH1_T1_RESETVAL (0x00000800u)

#define CSL_DFE_CFR_DTH1_DTH_T01_A1_REG_ADDR (0x000006CCu)
#define CSL_DFE_CFR_DTH1_DTH_T01_A1_REG_RESETVAL (0x00000800u)

/* DTH0_DTH_T02_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t2 : 16;
#else 
    Uint32 dth0_t2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T02_A0_REG;

/* Power threshold #2 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T02_A0_REG_DTH0_T2_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T02_A0_REG_DTH0_T2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T02_A0_REG_DTH0_T2_RESETVAL (0x00001000u)

#define CSL_DFE_CFR_DTH0_DTH_T02_A0_REG_ADDR (0x000006D0u)
#define CSL_DFE_CFR_DTH0_DTH_T02_A0_REG_RESETVAL (0x00001000u)

/* DTH1_DTH_T02_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t2 : 16;
#else 
    Uint32 dth1_t2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T02_A1_REG;

/* Power threshold #2 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T02_A1_REG_DTH1_T2_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T02_A1_REG_DTH1_T2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T02_A1_REG_DTH1_T2_RESETVAL (0x00001000u)

#define CSL_DFE_CFR_DTH1_DTH_T02_A1_REG_ADDR (0x000006D4u)
#define CSL_DFE_CFR_DTH1_DTH_T02_A1_REG_RESETVAL (0x00001000u)

/* DTH0_DTH_T03_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t3 : 16;
#else 
    Uint32 dth0_t3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T03_A0_REG;

/* Power threshold #3 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T03_A0_REG_DTH0_T3_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T03_A0_REG_DTH0_T3_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T03_A0_REG_DTH0_T3_RESETVAL (0x00001800u)

#define CSL_DFE_CFR_DTH0_DTH_T03_A0_REG_ADDR (0x000006D8u)
#define CSL_DFE_CFR_DTH0_DTH_T03_A0_REG_RESETVAL (0x00001800u)

/* DTH1_DTH_T03_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t3 : 16;
#else 
    Uint32 dth1_t3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T03_A1_REG;

/* Power threshold #3 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T03_A1_REG_DTH1_T3_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T03_A1_REG_DTH1_T3_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T03_A1_REG_DTH1_T3_RESETVAL (0x00001800u)

#define CSL_DFE_CFR_DTH1_DTH_T03_A1_REG_ADDR (0x000006DCu)
#define CSL_DFE_CFR_DTH1_DTH_T03_A1_REG_RESETVAL (0x00001800u)

/* DTH0_DTH_T04_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t4 : 16;
#else 
    Uint32 dth0_t4 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T04_A0_REG;

/* Power threshold #4 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T04_A0_REG_DTH0_T4_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T04_A0_REG_DTH0_T4_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T04_A0_REG_DTH0_T4_RESETVAL (0x00002000u)

#define CSL_DFE_CFR_DTH0_DTH_T04_A0_REG_ADDR (0x000006E0u)
#define CSL_DFE_CFR_DTH0_DTH_T04_A0_REG_RESETVAL (0x00002000u)

/* DTH1_DTH_T04_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t4 : 16;
#else 
    Uint32 dth1_t4 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T04_A1_REG;

/* Power threshold #4 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T04_A1_REG_DTH1_T4_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T04_A1_REG_DTH1_T4_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T04_A1_REG_DTH1_T4_RESETVAL (0x00002000u)

#define CSL_DFE_CFR_DTH1_DTH_T04_A1_REG_ADDR (0x000006E4u)
#define CSL_DFE_CFR_DTH1_DTH_T04_A1_REG_RESETVAL (0x00002000u)

/* DTH0_DTH_T05_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t5 : 16;
#else 
    Uint32 dth0_t5 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T05_A0_REG;

/* Power threshold #5 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T05_A0_REG_DTH0_T5_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T05_A0_REG_DTH0_T5_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T05_A0_REG_DTH0_T5_RESETVAL (0x00002800u)

#define CSL_DFE_CFR_DTH0_DTH_T05_A0_REG_ADDR (0x000006E8u)
#define CSL_DFE_CFR_DTH0_DTH_T05_A0_REG_RESETVAL (0x00002800u)

/* DTH1_DTH_T05_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t5 : 16;
#else 
    Uint32 dth1_t5 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T05_A1_REG;

/* Power threshold #5 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T05_A1_REG_DTH1_T5_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T05_A1_REG_DTH1_T5_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T05_A1_REG_DTH1_T5_RESETVAL (0x00002800u)

#define CSL_DFE_CFR_DTH1_DTH_T05_A1_REG_ADDR (0x000006ECu)
#define CSL_DFE_CFR_DTH1_DTH_T05_A1_REG_RESETVAL (0x00002800u)

/* DTH0_DTH_T06_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t6 : 16;
#else 
    Uint32 dth0_t6 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T06_A0_REG;

/* Power threshold #6 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T06_A0_REG_DTH0_T6_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T06_A0_REG_DTH0_T6_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T06_A0_REG_DTH0_T6_RESETVAL (0x00003000u)

#define CSL_DFE_CFR_DTH0_DTH_T06_A0_REG_ADDR (0x000006F0u)
#define CSL_DFE_CFR_DTH0_DTH_T06_A0_REG_RESETVAL (0x00003000u)

/* DTH1_DTH_T06_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t6 : 16;
#else 
    Uint32 dth1_t6 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T06_A1_REG;

/* Power threshold #6 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T06_A1_REG_DTH1_T6_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T06_A1_REG_DTH1_T6_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T06_A1_REG_DTH1_T6_RESETVAL (0x00003000u)

#define CSL_DFE_CFR_DTH1_DTH_T06_A1_REG_ADDR (0x000006F4u)
#define CSL_DFE_CFR_DTH1_DTH_T06_A1_REG_RESETVAL (0x00003000u)

/* DTH0_DTH_T07_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t7 : 16;
#else 
    Uint32 dth0_t7 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T07_A0_REG;

/* Power threshold #7 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T07_A0_REG_DTH0_T7_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T07_A0_REG_DTH0_T7_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T07_A0_REG_DTH0_T7_RESETVAL (0x00003800u)

#define CSL_DFE_CFR_DTH0_DTH_T07_A0_REG_ADDR (0x000006F8u)
#define CSL_DFE_CFR_DTH0_DTH_T07_A0_REG_RESETVAL (0x00003800u)

/* DTH1_DTH_T07_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t7 : 16;
#else 
    Uint32 dth1_t7 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T07_A1_REG;

/* Power threshold #7 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T07_A1_REG_DTH1_T7_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T07_A1_REG_DTH1_T7_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T07_A1_REG_DTH1_T7_RESETVAL (0x00003800u)

#define CSL_DFE_CFR_DTH1_DTH_T07_A1_REG_ADDR (0x000006FCu)
#define CSL_DFE_CFR_DTH1_DTH_T07_A1_REG_RESETVAL (0x00003800u)

/* DTH0_DTH_T08_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t8 : 16;
#else 
    Uint32 dth0_t8 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T08_A0_REG;

/* Power threshold #8 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T08_A0_REG_DTH0_T8_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T08_A0_REG_DTH0_T8_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T08_A0_REG_DTH0_T8_RESETVAL (0x00004000u)

#define CSL_DFE_CFR_DTH0_DTH_T08_A0_REG_ADDR (0x00000700u)
#define CSL_DFE_CFR_DTH0_DTH_T08_A0_REG_RESETVAL (0x00004000u)

/* DTH1_DTH_T08_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t8 : 16;
#else 
    Uint32 dth1_t8 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T08_A1_REG;

/* Power threshold #8 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T08_A1_REG_DTH1_T8_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T08_A1_REG_DTH1_T8_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T08_A1_REG_DTH1_T8_RESETVAL (0x00004000u)

#define CSL_DFE_CFR_DTH1_DTH_T08_A1_REG_ADDR (0x00000704u)
#define CSL_DFE_CFR_DTH1_DTH_T08_A1_REG_RESETVAL (0x00004000u)

/* DTH0_DTH_T09_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t9 : 16;
#else 
    Uint32 dth0_t9 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T09_A0_REG;

/* Power threshold #9 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T09_A0_REG_DTH0_T9_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T09_A0_REG_DTH0_T9_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T09_A0_REG_DTH0_T9_RESETVAL (0x00004800u)

#define CSL_DFE_CFR_DTH0_DTH_T09_A0_REG_ADDR (0x00000708u)
#define CSL_DFE_CFR_DTH0_DTH_T09_A0_REG_RESETVAL (0x00004800u)

/* DTH1_DTH_T09_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t9 : 16;
#else 
    Uint32 dth1_t9 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T09_A1_REG;

/* Power threshold #9 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T09_A1_REG_DTH1_T9_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T09_A1_REG_DTH1_T9_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T09_A1_REG_DTH1_T9_RESETVAL (0x00004800u)

#define CSL_DFE_CFR_DTH1_DTH_T09_A1_REG_ADDR (0x0000070Cu)
#define CSL_DFE_CFR_DTH1_DTH_T09_A1_REG_RESETVAL (0x00004800u)

/* DTH0_DTH_T0A_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t10 : 16;
#else 
    Uint32 dth0_t10 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T0A_A0_REG;

/* Power threshold #10 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T0A_A0_REG_DTH0_T10_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T0A_A0_REG_DTH0_T10_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T0A_A0_REG_DTH0_T10_RESETVAL (0x00005000u)

#define CSL_DFE_CFR_DTH0_DTH_T0A_A0_REG_ADDR (0x00000710u)
#define CSL_DFE_CFR_DTH0_DTH_T0A_A0_REG_RESETVAL (0x00005000u)

/* DTH1_DTH_T0A_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t10 : 16;
#else 
    Uint32 dth1_t10 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T0A_A1_REG;

/* Power threshold #10 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T0A_A1_REG_DTH1_T10_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T0A_A1_REG_DTH1_T10_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T0A_A1_REG_DTH1_T10_RESETVAL (0x00005000u)

#define CSL_DFE_CFR_DTH1_DTH_T0A_A1_REG_ADDR (0x00000714u)
#define CSL_DFE_CFR_DTH1_DTH_T0A_A1_REG_RESETVAL (0x00005000u)

/* DTH0_DTH_T0B_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t11 : 16;
#else 
    Uint32 dth0_t11 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T0B_A0_REG;

/* Power threshold #11 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T0B_A0_REG_DTH0_T11_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T0B_A0_REG_DTH0_T11_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T0B_A0_REG_DTH0_T11_RESETVAL (0x00005800u)

#define CSL_DFE_CFR_DTH0_DTH_T0B_A0_REG_ADDR (0x00000718u)
#define CSL_DFE_CFR_DTH0_DTH_T0B_A0_REG_RESETVAL (0x00005800u)

/* DTH1_DTH_T0B_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t11 : 16;
#else 
    Uint32 dth1_t11 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T0B_A1_REG;

/* Power threshold #11 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T0B_A1_REG_DTH1_T11_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T0B_A1_REG_DTH1_T11_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T0B_A1_REG_DTH1_T11_RESETVAL (0x00005800u)

#define CSL_DFE_CFR_DTH1_DTH_T0B_A1_REG_ADDR (0x0000071Cu)
#define CSL_DFE_CFR_DTH1_DTH_T0B_A1_REG_RESETVAL (0x00005800u)

/* DTH0_DTH_T0C_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t12 : 16;
#else 
    Uint32 dth0_t12 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T0C_A0_REG;

/* Power threshold #12 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T0C_A0_REG_DTH0_T12_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T0C_A0_REG_DTH0_T12_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T0C_A0_REG_DTH0_T12_RESETVAL (0x00006000u)

#define CSL_DFE_CFR_DTH0_DTH_T0C_A0_REG_ADDR (0x00000720u)
#define CSL_DFE_CFR_DTH0_DTH_T0C_A0_REG_RESETVAL (0x00006000u)

/* DTH1_DTH_T0C_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t12 : 16;
#else 
    Uint32 dth1_t12 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T0C_A1_REG;

/* Power threshold #12 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T0C_A1_REG_DTH1_T12_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T0C_A1_REG_DTH1_T12_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T0C_A1_REG_DTH1_T12_RESETVAL (0x00006000u)

#define CSL_DFE_CFR_DTH1_DTH_T0C_A1_REG_ADDR (0x00000724u)
#define CSL_DFE_CFR_DTH1_DTH_T0C_A1_REG_RESETVAL (0x00006000u)

/* DTH0_DTH_T0D_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t13 : 16;
#else 
    Uint32 dth0_t13 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T0D_A0_REG;

/* Power threshold #13 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T0D_A0_REG_DTH0_T13_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T0D_A0_REG_DTH0_T13_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T0D_A0_REG_DTH0_T13_RESETVAL (0x00006800u)

#define CSL_DFE_CFR_DTH0_DTH_T0D_A0_REG_ADDR (0x00000728u)
#define CSL_DFE_CFR_DTH0_DTH_T0D_A0_REG_RESETVAL (0x00006800u)

/* DTH1_DTH_T0D_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t13 : 16;
#else 
    Uint32 dth1_t13 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T0D_A1_REG;

/* Power threshold #13 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T0D_A1_REG_DTH1_T13_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T0D_A1_REG_DTH1_T13_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T0D_A1_REG_DTH1_T13_RESETVAL (0x00006800u)

#define CSL_DFE_CFR_DTH1_DTH_T0D_A1_REG_ADDR (0x0000072Cu)
#define CSL_DFE_CFR_DTH1_DTH_T0D_A1_REG_RESETVAL (0x00006800u)

/* DTH0_DTH_T0E_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t14 : 16;
#else 
    Uint32 dth0_t14 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T0E_A0_REG;

/* Power threshold #14 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T0E_A0_REG_DTH0_T14_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T0E_A0_REG_DTH0_T14_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T0E_A0_REG_DTH0_T14_RESETVAL (0x00007000u)

#define CSL_DFE_CFR_DTH0_DTH_T0E_A0_REG_ADDR (0x00000730u)
#define CSL_DFE_CFR_DTH0_DTH_T0E_A0_REG_RESETVAL (0x00007000u)

/* DTH1_DTH_T0E_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t14 : 16;
#else 
    Uint32 dth1_t14 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T0E_A1_REG;

/* Power threshold #14 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T0E_A1_REG_DTH1_T14_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T0E_A1_REG_DTH1_T14_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T0E_A1_REG_DTH1_T14_RESETVAL (0x00007000u)

#define CSL_DFE_CFR_DTH1_DTH_T0E_A1_REG_ADDR (0x00000734u)
#define CSL_DFE_CFR_DTH1_DTH_T0E_A1_REG_RESETVAL (0x00007000u)

/* DTH0_DTH_T0F_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t15 : 16;
#else 
    Uint32 dth0_t15 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T0F_A0_REG;

/* Power threshold #15 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T0F_A0_REG_DTH0_T15_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T0F_A0_REG_DTH0_T15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T0F_A0_REG_DTH0_T15_RESETVAL (0x00007800u)

#define CSL_DFE_CFR_DTH0_DTH_T0F_A0_REG_ADDR (0x00000738u)
#define CSL_DFE_CFR_DTH0_DTH_T0F_A0_REG_RESETVAL (0x00007800u)

/* DTH1_DTH_T0F_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t15 : 16;
#else 
    Uint32 dth1_t15 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T0F_A1_REG;

/* Power threshold #15 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T0F_A1_REG_DTH1_T15_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T0F_A1_REG_DTH1_T15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T0F_A1_REG_DTH1_T15_RESETVAL (0x00007800u)

#define CSL_DFE_CFR_DTH1_DTH_T0F_A1_REG_ADDR (0x0000073Cu)
#define CSL_DFE_CFR_DTH1_DTH_T0F_A1_REG_RESETVAL (0x00007800u)

/* DTH0_DTH_T10_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t16 : 16;
#else 
    Uint32 dth0_t16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T10_A0_REG;

/* Power threshold #16 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T10_A0_REG_DTH0_T16_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T10_A0_REG_DTH0_T16_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T10_A0_REG_DTH0_T16_RESETVAL (0x00008000u)

#define CSL_DFE_CFR_DTH0_DTH_T10_A0_REG_ADDR (0x00000740u)
#define CSL_DFE_CFR_DTH0_DTH_T10_A0_REG_RESETVAL (0x00008000u)

/* DTH1_DTH_T10_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t16 : 16;
#else 
    Uint32 dth1_t16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T10_A1_REG;

/* Power threshold #16 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T10_A1_REG_DTH1_T16_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T10_A1_REG_DTH1_T16_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T10_A1_REG_DTH1_T16_RESETVAL (0x00008000u)

#define CSL_DFE_CFR_DTH1_DTH_T10_A1_REG_ADDR (0x00000744u)
#define CSL_DFE_CFR_DTH1_DTH_T10_A1_REG_RESETVAL (0x00008000u)

/* DTH0_DTH_T11_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t17 : 16;
#else 
    Uint32 dth0_t17 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T11_A0_REG;

/* Power threshold #17 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T11_A0_REG_DTH0_T17_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T11_A0_REG_DTH0_T17_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T11_A0_REG_DTH0_T17_RESETVAL (0x00008800u)

#define CSL_DFE_CFR_DTH0_DTH_T11_A0_REG_ADDR (0x00000748u)
#define CSL_DFE_CFR_DTH0_DTH_T11_A0_REG_RESETVAL (0x00008800u)

/* DTH1_DTH_T11_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t17 : 16;
#else 
    Uint32 dth1_t17 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T11_A1_REG;

/* Power threshold #17 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T11_A1_REG_DTH1_T17_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T11_A1_REG_DTH1_T17_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T11_A1_REG_DTH1_T17_RESETVAL (0x00008800u)

#define CSL_DFE_CFR_DTH1_DTH_T11_A1_REG_ADDR (0x0000074Cu)
#define CSL_DFE_CFR_DTH1_DTH_T11_A1_REG_RESETVAL (0x00008800u)

/* DTH0_DTH_T12_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t18 : 16;
#else 
    Uint32 dth0_t18 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T12_A0_REG;

/* Power threshold #18 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T12_A0_REG_DTH0_T18_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T12_A0_REG_DTH0_T18_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T12_A0_REG_DTH0_T18_RESETVAL (0x00009000u)

#define CSL_DFE_CFR_DTH0_DTH_T12_A0_REG_ADDR (0x00000750u)
#define CSL_DFE_CFR_DTH0_DTH_T12_A0_REG_RESETVAL (0x00009000u)

/* DTH1_DTH_T12_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t18 : 16;
#else 
    Uint32 dth1_t18 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T12_A1_REG;

/* Power threshold #18 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T12_A1_REG_DTH1_T18_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T12_A1_REG_DTH1_T18_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T12_A1_REG_DTH1_T18_RESETVAL (0x00009000u)

#define CSL_DFE_CFR_DTH1_DTH_T12_A1_REG_ADDR (0x00000754u)
#define CSL_DFE_CFR_DTH1_DTH_T12_A1_REG_RESETVAL (0x00009000u)

/* DTH0_DTH_T13_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t19 : 16;
#else 
    Uint32 dth0_t19 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T13_A0_REG;

/* Power threshold #19 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T13_A0_REG_DTH0_T19_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T13_A0_REG_DTH0_T19_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T13_A0_REG_DTH0_T19_RESETVAL (0x00009800u)

#define CSL_DFE_CFR_DTH0_DTH_T13_A0_REG_ADDR (0x00000758u)
#define CSL_DFE_CFR_DTH0_DTH_T13_A0_REG_RESETVAL (0x00009800u)

/* DTH1_DTH_T13_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t19 : 16;
#else 
    Uint32 dth1_t19 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T13_A1_REG;

/* Power threshold #19 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T13_A1_REG_DTH1_T19_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T13_A1_REG_DTH1_T19_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T13_A1_REG_DTH1_T19_RESETVAL (0x00009800u)

#define CSL_DFE_CFR_DTH1_DTH_T13_A1_REG_ADDR (0x0000075Cu)
#define CSL_DFE_CFR_DTH1_DTH_T13_A1_REG_RESETVAL (0x00009800u)

/* DTH0_DTH_T14_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t20 : 16;
#else 
    Uint32 dth0_t20 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T14_A0_REG;

/* Power threshold #20 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T14_A0_REG_DTH0_T20_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T14_A0_REG_DTH0_T20_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T14_A0_REG_DTH0_T20_RESETVAL (0x0000A000u)

#define CSL_DFE_CFR_DTH0_DTH_T14_A0_REG_ADDR (0x00000760u)
#define CSL_DFE_CFR_DTH0_DTH_T14_A0_REG_RESETVAL (0x0000A000u)

/* DTH1_DTH_T14_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t20 : 16;
#else 
    Uint32 dth1_t20 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T14_A1_REG;

/* Power threshold #20 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T14_A1_REG_DTH1_T20_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T14_A1_REG_DTH1_T20_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T14_A1_REG_DTH1_T20_RESETVAL (0x0000A000u)

#define CSL_DFE_CFR_DTH1_DTH_T14_A1_REG_ADDR (0x00000764u)
#define CSL_DFE_CFR_DTH1_DTH_T14_A1_REG_RESETVAL (0x0000A000u)

/* DTH0_DTH_T15_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t21 : 16;
#else 
    Uint32 dth0_t21 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T15_A0_REG;

/* Power threshold #21 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T15_A0_REG_DTH0_T21_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T15_A0_REG_DTH0_T21_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T15_A0_REG_DTH0_T21_RESETVAL (0x0000A800u)

#define CSL_DFE_CFR_DTH0_DTH_T15_A0_REG_ADDR (0x00000768u)
#define CSL_DFE_CFR_DTH0_DTH_T15_A0_REG_RESETVAL (0x0000A800u)

/* DTH1_DTH_T15_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t21 : 16;
#else 
    Uint32 dth1_t21 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T15_A1_REG;

/* Power threshold #21 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T15_A1_REG_DTH1_T21_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T15_A1_REG_DTH1_T21_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T15_A1_REG_DTH1_T21_RESETVAL (0x0000A800u)

#define CSL_DFE_CFR_DTH1_DTH_T15_A1_REG_ADDR (0x0000076Cu)
#define CSL_DFE_CFR_DTH1_DTH_T15_A1_REG_RESETVAL (0x0000A800u)

/* DTH0_DTH_T16_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t22 : 16;
#else 
    Uint32 dth0_t22 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T16_A0_REG;

/* Power threshold #22 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T16_A0_REG_DTH0_T22_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T16_A0_REG_DTH0_T22_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T16_A0_REG_DTH0_T22_RESETVAL (0x0000B000u)

#define CSL_DFE_CFR_DTH0_DTH_T16_A0_REG_ADDR (0x00000770u)
#define CSL_DFE_CFR_DTH0_DTH_T16_A0_REG_RESETVAL (0x0000B000u)

/* DTH1_DTH_T16_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t22 : 16;
#else 
    Uint32 dth1_t22 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T16_A1_REG;

/* Power threshold #22 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T16_A1_REG_DTH1_T22_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T16_A1_REG_DTH1_T22_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T16_A1_REG_DTH1_T22_RESETVAL (0x0000B000u)

#define CSL_DFE_CFR_DTH1_DTH_T16_A1_REG_ADDR (0x00000774u)
#define CSL_DFE_CFR_DTH1_DTH_T16_A1_REG_RESETVAL (0x0000B000u)

/* DTH0_DTH_T17_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t23 : 16;
#else 
    Uint32 dth0_t23 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T17_A0_REG;

/* Power threshold #23 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T17_A0_REG_DTH0_T23_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T17_A0_REG_DTH0_T23_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T17_A0_REG_DTH0_T23_RESETVAL (0x0000B800u)

#define CSL_DFE_CFR_DTH0_DTH_T17_A0_REG_ADDR (0x00000778u)
#define CSL_DFE_CFR_DTH0_DTH_T17_A0_REG_RESETVAL (0x0000B800u)

/* DTH1_DTH_T17_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t23 : 16;
#else 
    Uint32 dth1_t23 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T17_A1_REG;

/* Power threshold #23 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T17_A1_REG_DTH1_T23_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T17_A1_REG_DTH1_T23_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T17_A1_REG_DTH1_T23_RESETVAL (0x0000B800u)

#define CSL_DFE_CFR_DTH1_DTH_T17_A1_REG_ADDR (0x0000077Cu)
#define CSL_DFE_CFR_DTH1_DTH_T17_A1_REG_RESETVAL (0x0000B800u)

/* DTH0_DTH_T18_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t24 : 16;
#else 
    Uint32 dth0_t24 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T18_A0_REG;

/* Power threshold #24 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T18_A0_REG_DTH0_T24_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T18_A0_REG_DTH0_T24_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T18_A0_REG_DTH0_T24_RESETVAL (0x0000C000u)

#define CSL_DFE_CFR_DTH0_DTH_T18_A0_REG_ADDR (0x00000780u)
#define CSL_DFE_CFR_DTH0_DTH_T18_A0_REG_RESETVAL (0x0000C000u)

/* DTH1_DTH_T18_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t24 : 16;
#else 
    Uint32 dth1_t24 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T18_A1_REG;

/* Power threshold #24 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T18_A1_REG_DTH1_T24_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T18_A1_REG_DTH1_T24_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T18_A1_REG_DTH1_T24_RESETVAL (0x0000C000u)

#define CSL_DFE_CFR_DTH1_DTH_T18_A1_REG_ADDR (0x00000784u)
#define CSL_DFE_CFR_DTH1_DTH_T18_A1_REG_RESETVAL (0x0000C000u)

/* DTH0_DTH_T19_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t25 : 16;
#else 
    Uint32 dth0_t25 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T19_A0_REG;

/* Power threshold #25 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T19_A0_REG_DTH0_T25_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T19_A0_REG_DTH0_T25_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T19_A0_REG_DTH0_T25_RESETVAL (0x0000C800u)

#define CSL_DFE_CFR_DTH0_DTH_T19_A0_REG_ADDR (0x00000788u)
#define CSL_DFE_CFR_DTH0_DTH_T19_A0_REG_RESETVAL (0x0000C800u)

/* DTH1_DTH_T19_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t25 : 16;
#else 
    Uint32 dth1_t25 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T19_A1_REG;

/* Power threshold #25 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T19_A1_REG_DTH1_T25_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T19_A1_REG_DTH1_T25_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T19_A1_REG_DTH1_T25_RESETVAL (0x0000C800u)

#define CSL_DFE_CFR_DTH1_DTH_T19_A1_REG_ADDR (0x0000078Cu)
#define CSL_DFE_CFR_DTH1_DTH_T19_A1_REG_RESETVAL (0x0000C800u)

/* DTH0_DTH_T1A_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t26 : 16;
#else 
    Uint32 dth0_t26 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T1A_A0_REG;

/* Power threshold #26 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T1A_A0_REG_DTH0_T26_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T1A_A0_REG_DTH0_T26_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T1A_A0_REG_DTH0_T26_RESETVAL (0x0000D000u)

#define CSL_DFE_CFR_DTH0_DTH_T1A_A0_REG_ADDR (0x00000790u)
#define CSL_DFE_CFR_DTH0_DTH_T1A_A0_REG_RESETVAL (0x0000D000u)

/* DTH1_DTH_T1A_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t26 : 16;
#else 
    Uint32 dth1_t26 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T1A_A1_REG;

/* Power threshold #26 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T1A_A1_REG_DTH1_T26_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T1A_A1_REG_DTH1_T26_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T1A_A1_REG_DTH1_T26_RESETVAL (0x0000D000u)

#define CSL_DFE_CFR_DTH1_DTH_T1A_A1_REG_ADDR (0x00000794u)
#define CSL_DFE_CFR_DTH1_DTH_T1A_A1_REG_RESETVAL (0x0000D000u)

/* DTH0_DTH_T1B_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t27 : 16;
#else 
    Uint32 dth0_t27 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T1B_A0_REG;

/* Power threshold #27 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T1B_A0_REG_DTH0_T27_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T1B_A0_REG_DTH0_T27_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T1B_A0_REG_DTH0_T27_RESETVAL (0x0000D800u)

#define CSL_DFE_CFR_DTH0_DTH_T1B_A0_REG_ADDR (0x00000798u)
#define CSL_DFE_CFR_DTH0_DTH_T1B_A0_REG_RESETVAL (0x0000D800u)

/* DTH1_DTH_T1B_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t27 : 16;
#else 
    Uint32 dth1_t27 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T1B_A1_REG;

/* Power threshold #27 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T1B_A1_REG_DTH1_T27_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T1B_A1_REG_DTH1_T27_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T1B_A1_REG_DTH1_T27_RESETVAL (0x0000D800u)

#define CSL_DFE_CFR_DTH1_DTH_T1B_A1_REG_ADDR (0x0000079Cu)
#define CSL_DFE_CFR_DTH1_DTH_T1B_A1_REG_RESETVAL (0x0000D800u)

/* DTH0_DTH_T1C_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t28 : 16;
#else 
    Uint32 dth0_t28 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T1C_A0_REG;

/* Power threshold #28 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T1C_A0_REG_DTH0_T28_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T1C_A0_REG_DTH0_T28_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T1C_A0_REG_DTH0_T28_RESETVAL (0x0000E000u)

#define CSL_DFE_CFR_DTH0_DTH_T1C_A0_REG_ADDR (0x000007A0u)
#define CSL_DFE_CFR_DTH0_DTH_T1C_A0_REG_RESETVAL (0x0000E000u)

/* DTH1_DTH_T1C_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t28 : 16;
#else 
    Uint32 dth1_t28 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T1C_A1_REG;

/* Power threshold #8 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T1C_A1_REG_DTH1_T28_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T1C_A1_REG_DTH1_T28_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T1C_A1_REG_DTH1_T28_RESETVAL (0x0000E000u)

#define CSL_DFE_CFR_DTH1_DTH_T1C_A1_REG_ADDR (0x000007A4u)
#define CSL_DFE_CFR_DTH1_DTH_T1C_A1_REG_RESETVAL (0x0000E000u)

/* DTH0_DTH_T1D_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t29 : 16;
#else 
    Uint32 dth0_t29 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T1D_A0_REG;

/* Power threshold #29 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T1D_A0_REG_DTH0_T29_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T1D_A0_REG_DTH0_T29_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T1D_A0_REG_DTH0_T29_RESETVAL (0x0000E800u)

#define CSL_DFE_CFR_DTH0_DTH_T1D_A0_REG_ADDR (0x000007A8u)
#define CSL_DFE_CFR_DTH0_DTH_T1D_A0_REG_RESETVAL (0x0000E800u)

/* DTH1_DTH_T1D_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t29 : 16;
#else 
    Uint32 dth1_t29 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T1D_A1_REG;

/* Power threshold #29 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T1D_A1_REG_DTH1_T29_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T1D_A1_REG_DTH1_T29_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T1D_A1_REG_DTH1_T29_RESETVAL (0x0000E800u)

#define CSL_DFE_CFR_DTH1_DTH_T1D_A1_REG_ADDR (0x000007ACu)
#define CSL_DFE_CFR_DTH1_DTH_T1D_A1_REG_RESETVAL (0x0000E800u)

/* DTH0_DTH_T1E_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t30 : 16;
#else 
    Uint32 dth0_t30 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T1E_A0_REG;

/* Power threshold #30 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T1E_A0_REG_DTH0_T30_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T1E_A0_REG_DTH0_T30_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T1E_A0_REG_DTH0_T30_RESETVAL (0x0000F000u)

#define CSL_DFE_CFR_DTH0_DTH_T1E_A0_REG_ADDR (0x000007B0u)
#define CSL_DFE_CFR_DTH0_DTH_T1E_A0_REG_RESETVAL (0x0000F000u)

/* DTH1_DTH_T1E_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t30 : 16;
#else 
    Uint32 dth1_t30 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T1E_A1_REG;

/* Power threshold #30 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T1E_A1_REG_DTH1_T30_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T1E_A1_REG_DTH1_T30_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T1E_A1_REG_DTH1_T30_RESETVAL (0x0000F000u)

#define CSL_DFE_CFR_DTH1_DTH_T1E_A1_REG_ADDR (0x000007B4u)
#define CSL_DFE_CFR_DTH1_DTH_T1E_A1_REG_RESETVAL (0x0000F000u)

/* DTH0_DTH_T1F_A0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_t31 : 16;
#else 
    Uint32 dth0_t31 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_T1F_A0_REG;

/* Power threshold #31 for dynamically selecting Detection and target thresholds and hysteresis for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_T1F_A0_REG_DTH0_T31_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_T1F_A0_REG_DTH0_T31_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_T1F_A0_REG_DTH0_T31_RESETVAL (0x0000F800u)

#define CSL_DFE_CFR_DTH0_DTH_T1F_A0_REG_ADDR (0x000007B8u)
#define CSL_DFE_CFR_DTH0_DTH_T1F_A0_REG_RESETVAL (0x0000F800u)

/* DTH1_DTH_T1F_A1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_t31 : 16;
#else 
    Uint32 dth1_t31 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_T1F_A1_REG;

/* Power threshold #31 for dynamically selecting Detection and target thresholds and hysteresis for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_T1F_A1_REG_DTH1_T31_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_T1F_A1_REG_DTH1_T31_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_T1F_A1_REG_DTH1_T31_RESETVAL (0x0000F800u)

#define CSL_DFE_CFR_DTH1_DTH_T1F_A1_REG_ADDR (0x000007BCu)
#define CSL_DFE_CFR_DTH1_DTH_T1F_A1_REG_RESETVAL (0x0000F800u)

/* DTH0_DTH_PWR_SECTION */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 dth_pwr_section : 5;
#else 
    Uint32 dth_pwr_section : 5;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_CFR_DTH0_DTH_PWR_SECTION_REG;

/* Last new power section detected by DTH (mode 2 or 3) for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_PWR_SECTION_REG_DTH_PWR_SECTION_MASK (0x0000001Fu)
#define CSL_DFE_CFR_DTH0_DTH_PWR_SECTION_REG_DTH_PWR_SECTION_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_PWR_SECTION_REG_DTH_PWR_SECTION_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_PWR_SECTION_REG_ADDR (0x000007C0u)
#define CSL_DFE_CFR_DTH0_DTH_PWR_SECTION_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_PWR_SECTION */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 27;
    Uint32 dth_pwr_section : 5;
#else 
    Uint32 dth_pwr_section : 5;
    Uint32 rsvd0 : 27;
#endif 
} CSL_DFE_CFR_DTH1_DTH_PWR_SECTION_REG;

/* Last new power section detected by DTH (mode 2 or 3) for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_PWR_SECTION_REG_DTH_PWR_SECTION_MASK (0x0000001Fu)
#define CSL_DFE_CFR_DTH1_DTH_PWR_SECTION_REG_DTH_PWR_SECTION_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_PWR_SECTION_REG_DTH_PWR_SECTION_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_PWR_SECTION_REG_ADDR (0x000007C4u)
#define CSL_DFE_CFR_DTH1_DTH_PWR_SECTION_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_A_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_a_i : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_a_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_I_REG;

/* Initialize I of all 4 PDC0 Base filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_I_REG_PDC0_PDC_LUTS_SW_A_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_I_REG_PDC0_PDC_LUTS_SW_A_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_I_REG_PDC0_PDC_LUTS_SW_A_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_I_REG_ADDR (0x00004000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_I_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_B_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_b_i : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_b_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_I_REG;

/* Initialize I of all 4 PDC0 Delayed filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_I_REG_PDC0_PDC_LUTS_SW_B_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_I_REG_PDC0_PDC_LUTS_SW_B_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_I_REG_PDC0_PDC_LUTS_SW_B_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_I_REG_ADDR (0x00004400u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_I_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_C_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_c_i : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_c_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_I_REG;

/* Initialize I of all 4 PDC) Shadow filter(s) during initialization (mpu_mem_access=1) (Not required) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_I_REG_PDC0_PDC_LUTS_SW_C_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_I_REG_PDC0_PDC_LUTS_SW_C_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_I_REG_PDC0_PDC_LUTS_SW_C_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_I_REG_ADDR (0x00004800u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_I_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_SHDW_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_shdw_i : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_shdw_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_I_REG;

/* Program I of PDC0 Shadow filter (Independent of mpu_mem_access) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_I_REG_PDC0_PDC_LUTS_SW_SHDW_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_I_REG_PDC0_PDC_LUTS_SW_SHDW_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_I_REG_PDC0_PDC_LUTS_SW_SHDW_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_I_REG_ADDR (0x00004C00u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_I_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_A_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_a_q : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_a_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_Q_REG;

/* Initialize Q of all 4 PDC0 Base filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_Q_REG_PDC0_PDC_LUTS_SW_A_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_Q_REG_PDC0_PDC_LUTS_SW_A_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_Q_REG_PDC0_PDC_LUTS_SW_A_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_Q_REG_ADDR (0x00005000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_Q_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_B_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_b_q : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_b_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_Q_REG;

/* Initialize Q of all 4 PDC0 Delayed filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_Q_REG_PDC0_PDC_LUTS_SW_B_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_Q_REG_PDC0_PDC_LUTS_SW_B_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_Q_REG_PDC0_PDC_LUTS_SW_B_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_Q_REG_ADDR (0x00005400u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_Q_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_C_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_c_q : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_c_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_Q_REG;

/* Initialize Q of all 4 PDC) Shadow filter(s) during initialization (mpu_mem_access=1) (Not required) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_Q_REG_PDC0_PDC_LUTS_SW_C_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_Q_REG_PDC0_PDC_LUTS_SW_C_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_Q_REG_PDC0_PDC_LUTS_SW_C_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_Q_REG_ADDR (0x00005800u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_Q_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_SHDW_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_shdw_q : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_shdw_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_Q_REG;

/* Program Q of PDC0 Shadow filter (Independent of mpu_mem_access) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_Q_REG_PDC0_PDC_LUTS_SW_SHDW_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_Q_REG_PDC0_PDC_LUTS_SW_SHDW_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_Q_REG_PDC0_PDC_LUTS_SW_SHDW_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_Q_REG_ADDR (0x00005C00u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_Q_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_A_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_a_iq : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_a_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_IQ_REG;

/* Initialize all 8 PDC0 Base real filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_IQ_REG_PDC0_PDC_LUTS_SW_A_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_IQ_REG_PDC0_PDC_LUTS_SW_A_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_IQ_REG_PDC0_PDC_LUTS_SW_A_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_IQ_REG_ADDR (0x00006000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_A_IQ_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_B_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_b_iq : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_b_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_IQ_REG;

/* Initialize all 8 PDC0 Delayed real filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_IQ_REG_PDC0_PDC_LUTS_SW_B_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_IQ_REG_PDC0_PDC_LUTS_SW_B_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_IQ_REG_PDC0_PDC_LUTS_SW_B_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_IQ_REG_ADDR (0x00006400u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_B_IQ_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_C_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_c_iq : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_c_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_IQ_REG;

/* Initialize all 8 PDC) Shadow real filter(s) during initialization (mpu_mem_access=1) (Not required) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_IQ_REG_PDC0_PDC_LUTS_SW_C_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_IQ_REG_PDC0_PDC_LUTS_SW_C_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_IQ_REG_PDC0_PDC_LUTS_SW_C_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_IQ_REG_ADDR (0x00006800u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_C_IQ_REG_RESETVAL (0x00000000u)

/* PDC0_PDC_LUTS_SW_SHDW_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc0_pdc_luts_sw_shdw_iq : 12;
#else 
    Uint32 pdc0_pdc_luts_sw_shdw_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_IQ_REG;

/* Program all 8 PDC0 Shadow real filter (Independent of mpu_mem_access) */
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_IQ_REG_PDC0_PDC_LUTS_SW_SHDW_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_IQ_REG_PDC0_PDC_LUTS_SW_SHDW_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_IQ_REG_PDC0_PDC_LUTS_SW_SHDW_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_IQ_REG_ADDR (0x00006C00u)
#define CSL_DFE_CFR_PDC0_PDC_LUTS_SW_SHDW_IQ_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_A_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_a_i : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_a_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_I_REG;

/* Initialize I of all 4 PDC1 Base filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_I_REG_PDC1_PDC_LUTS_SW_A_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_I_REG_PDC1_PDC_LUTS_SW_A_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_I_REG_PDC1_PDC_LUTS_SW_A_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_I_REG_ADDR (0x00008000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_I_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_B_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_b_i : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_b_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_I_REG;

/* Initialize I of all 4 PDC1 Delayed filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_I_REG_PDC1_PDC_LUTS_SW_B_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_I_REG_PDC1_PDC_LUTS_SW_B_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_I_REG_PDC1_PDC_LUTS_SW_B_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_I_REG_ADDR (0x00008400u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_I_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_C_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_c_i : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_c_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_I_REG;

/* Initialize I of all 4 PDC) Shadow filter(s) during initialization (mpu_mem_access=1) (Not required) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_I_REG_PDC1_PDC_LUTS_SW_C_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_I_REG_PDC1_PDC_LUTS_SW_C_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_I_REG_PDC1_PDC_LUTS_SW_C_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_I_REG_ADDR (0x00008800u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_I_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_SHDW_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_shdw_i : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_shdw_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_I_REG;

/* Program I of PDC1 Shadow filter (Independent of mpu_mem_access) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_I_REG_PDC1_PDC_LUTS_SW_SHDW_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_I_REG_PDC1_PDC_LUTS_SW_SHDW_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_I_REG_PDC1_PDC_LUTS_SW_SHDW_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_I_REG_ADDR (0x00008C00u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_I_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_A_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_a_q : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_a_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_Q_REG;

/* Initialize Q of all 4 PDC1 Base filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_Q_REG_PDC1_PDC_LUTS_SW_A_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_Q_REG_PDC1_PDC_LUTS_SW_A_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_Q_REG_PDC1_PDC_LUTS_SW_A_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_Q_REG_ADDR (0x00009000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_Q_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_B_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_b_q : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_b_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_Q_REG;

/* Initialize Q of all 4 PDC1 Delayed filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_Q_REG_PDC1_PDC_LUTS_SW_B_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_Q_REG_PDC1_PDC_LUTS_SW_B_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_Q_REG_PDC1_PDC_LUTS_SW_B_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_Q_REG_ADDR (0x00009400u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_Q_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_C_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_c_q : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_c_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_Q_REG;

/* Initialize Q of all 4 PDC) Shadow filter(s) during initialization (mpu_mem_access=1) (Not required) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_Q_REG_PDC1_PDC_LUTS_SW_C_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_Q_REG_PDC1_PDC_LUTS_SW_C_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_Q_REG_PDC1_PDC_LUTS_SW_C_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_Q_REG_ADDR (0x00009800u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_Q_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_SHDW_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_shdw_q : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_shdw_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_Q_REG;

/* Program Q of PDC1 Shadow filter (Independent of mpu_mem_access) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_Q_REG_PDC1_PDC_LUTS_SW_SHDW_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_Q_REG_PDC1_PDC_LUTS_SW_SHDW_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_Q_REG_PDC1_PDC_LUTS_SW_SHDW_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_Q_REG_ADDR (0x00009C00u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_Q_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_A_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_a_iq : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_a_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_IQ_REG;

/* Initialize all 8 PDC1 Base real filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_IQ_REG_PDC1_PDC_LUTS_SW_A_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_IQ_REG_PDC1_PDC_LUTS_SW_A_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_IQ_REG_PDC1_PDC_LUTS_SW_A_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_IQ_REG_ADDR (0x0000A000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_A_IQ_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_B_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_b_iq : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_b_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_IQ_REG;

/* Initialize all 8 PDC1 Delayed real filter(s) during initialization (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_IQ_REG_PDC1_PDC_LUTS_SW_B_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_IQ_REG_PDC1_PDC_LUTS_SW_B_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_IQ_REG_PDC1_PDC_LUTS_SW_B_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_IQ_REG_ADDR (0x0000A400u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_B_IQ_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_C_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_c_iq : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_c_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_IQ_REG;

/* Initialize all 8 PDC) Shadow real filter(s) during initialization (mpu_mem_access=1) (Not required) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_IQ_REG_PDC1_PDC_LUTS_SW_C_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_IQ_REG_PDC1_PDC_LUTS_SW_C_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_IQ_REG_PDC1_PDC_LUTS_SW_C_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_IQ_REG_ADDR (0x0000A800u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_C_IQ_REG_RESETVAL (0x00000000u)

/* PDC1_PDC_LUTS_SW_SHDW_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc1_pdc_luts_sw_shdw_iq : 12;
#else 
    Uint32 pdc1_pdc_luts_sw_shdw_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_IQ_REG;

/* Program all 8 PDC1 Shadow real filter (Independent of mpu_mem_access) */
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_IQ_REG_PDC1_PDC_LUTS_SW_SHDW_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_IQ_REG_PDC1_PDC_LUTS_SW_SHDW_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_IQ_REG_PDC1_PDC_LUTS_SW_SHDW_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_IQ_REG_ADDR (0x0000AC00u)
#define CSL_DFE_CFR_PDC1_PDC_LUTS_SW_SHDW_IQ_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_A_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_a_i : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_a_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_I_REG;

/* Initialize I of all 4 Base filter(s) during initialization in both PDCs (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_I_REG_PDC_01_PDC_LUTS_SW_A_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_I_REG_PDC_01_PDC_LUTS_SW_A_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_I_REG_PDC_01_PDC_LUTS_SW_A_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_I_REG_ADDR (0x0000C000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_I_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_B_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_b_i : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_b_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_I_REG;

/* Initialize I of all 4 Delayed filter(s) during initialization in both PDCs (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_I_REG_PDC_01_PDC_LUTS_SW_B_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_I_REG_PDC_01_PDC_LUTS_SW_B_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_I_REG_PDC_01_PDC_LUTS_SW_B_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_I_REG_ADDR (0x0000C400u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_I_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_C_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_c_i : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_c_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_I_REG;

/* Initialize I of all 4 PDC) Shadow filter(s) during initialization in both PDCs (mpu_mem_access=1) (Not required) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_I_REG_PDC_01_PDC_LUTS_SW_C_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_I_REG_PDC_01_PDC_LUTS_SW_C_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_I_REG_PDC_01_PDC_LUTS_SW_C_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_I_REG_ADDR (0x0000C800u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_I_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_SHDW_I */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_shdw_i : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_shdw_i : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_I_REG;

/* Program I of Shadow filter in both PDCs (Independent of mpu_mem_access) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_I_REG_PDC_01_PDC_LUTS_SW_SHDW_I_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_I_REG_PDC_01_PDC_LUTS_SW_SHDW_I_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_I_REG_PDC_01_PDC_LUTS_SW_SHDW_I_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_I_REG_ADDR (0x0000CC00u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_I_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_A_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_a_q : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_a_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_Q_REG;

/* Initialize Q of all 4 Base filter(s) during initialization in both PDCs (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_Q_REG_PDC_01_PDC_LUTS_SW_A_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_Q_REG_PDC_01_PDC_LUTS_SW_A_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_Q_REG_PDC_01_PDC_LUTS_SW_A_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_Q_REG_ADDR (0x0000D000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_Q_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_B_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_b_q : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_b_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_Q_REG;

/* Initialize Q of all 4 Delayed filter(s) during initialization in both PDCs (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_Q_REG_PDC_01_PDC_LUTS_SW_B_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_Q_REG_PDC_01_PDC_LUTS_SW_B_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_Q_REG_PDC_01_PDC_LUTS_SW_B_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_Q_REG_ADDR (0x0000D400u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_Q_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_C_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_c_q : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_c_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_Q_REG;

/* Initialize Q of all 4 PDC) Shadow filter(s) during initialization in both PDCs (mpu_mem_access=1) (Not required) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_Q_REG_PDC_01_PDC_LUTS_SW_C_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_Q_REG_PDC_01_PDC_LUTS_SW_C_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_Q_REG_PDC_01_PDC_LUTS_SW_C_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_Q_REG_ADDR (0x0000D800u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_Q_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_SHDW_Q */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_shdw_q : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_shdw_q : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_Q_REG;

/* Program Q of Shadow filter in both PDCs (Independent of mpu_mem_access) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_Q_REG_PDC_01_PDC_LUTS_SW_SHDW_Q_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_Q_REG_PDC_01_PDC_LUTS_SW_SHDW_Q_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_Q_REG_PDC_01_PDC_LUTS_SW_SHDW_Q_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_Q_REG_ADDR (0x0000DC00u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_Q_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_A_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_a_iq : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_a_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_IQ_REG;

/* Initialize all 8 Base real filter(s) during initialization in both PDCs (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_IQ_REG_PDC_01_PDC_LUTS_SW_A_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_IQ_REG_PDC_01_PDC_LUTS_SW_A_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_IQ_REG_PDC_01_PDC_LUTS_SW_A_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_IQ_REG_ADDR (0x0000E000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_A_IQ_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_B_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_b_iq : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_b_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_IQ_REG;

/* Initialize all 8 Delayed real filter(s) during initialization in both PDCs (mpu_mem_access=1) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_IQ_REG_PDC_01_PDC_LUTS_SW_B_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_IQ_REG_PDC_01_PDC_LUTS_SW_B_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_IQ_REG_PDC_01_PDC_LUTS_SW_B_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_IQ_REG_ADDR (0x0000E400u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_B_IQ_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_C_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_c_iq : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_c_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_IQ_REG;

/* Initialize all 8 PDC) Shadow real filter(s) during initialization in both PDCs (mpu_mem_access=1) (Not required) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_IQ_REG_PDC_01_PDC_LUTS_SW_C_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_IQ_REG_PDC_01_PDC_LUTS_SW_C_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_IQ_REG_PDC_01_PDC_LUTS_SW_C_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_IQ_REG_ADDR (0x0000E800u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_C_IQ_REG_RESETVAL (0x00000000u)

/* PDC_01_PDC_LUTS_SW_SHDW_IQ */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 pdc_01_pdc_luts_sw_shdw_iq : 12;
#else 
    Uint32 pdc_01_pdc_luts_sw_shdw_iq : 12;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_IQ_REG;

/* Program all 8 Shadow real filter in both PDCs (Independent of mpu_mem_access) */
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_IQ_REG_PDC_01_PDC_LUTS_SW_SHDW_IQ_MASK (0x00000FFFu)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_IQ_REG_PDC_01_PDC_LUTS_SW_SHDW_IQ_SHIFT (0x00000000u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_IQ_REG_PDC_01_PDC_LUTS_SW_SHDW_IQ_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_IQ_REG_ADDR (0x0000EC00u)
#define CSL_DFE_CFR_PDC_01_PDC_LUTS_SW_SHDW_IQ_REG_RESETVAL (0x00000000u)

/* CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa0_sync_switch_th_0_15 : 16;
#else 
    Uint32 cpa0_sync_switch_th_0_15 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_LO_REG;

/* Switching time #0-#15 - LSW for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_LO_REG_CPA0_SYNC_SWITCH_TH_0_15_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_LO_REG_CPA0_SYNC_SWITCH_TH_0_15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_LO_REG_CPA0_SYNC_SWITCH_TH_0_15_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_LO_REG_ADDR (0x00010000u)
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_LO_REG_RESETVAL (0x00000000u)

/* CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 cpa0_sync_state_map_0_15 : 3;
    Uint32 cpa0_sync_switch_th_0_15 : 8;
#else 
    Uint32 cpa0_sync_switch_th_0_15 : 8;
    Uint32 cpa0_sync_state_map_0_15 : 3;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI_REG;

/* Switching time #0-#15 - MSB for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI_REG_CPA0_SYNC_SWITCH_TH_0_15_MASK (0x000000FFu)
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI_REG_CPA0_SYNC_SWITCH_TH_0_15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI_REG_CPA0_SYNC_SWITCH_TH_0_15_RESETVAL (0x00000000u)

/* Stage mapping of switch #0-#7 for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI_REG_CPA0_SYNC_STATE_MAP_0_15_MASK (0x00000700u)
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI_REG_CPA0_SYNC_STATE_MAP_0_15_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI_REG_CPA0_SYNC_STATE_MAP_0_15_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI_REG_ADDR (0x00010004u)
#define CSL_DFE_CFR_CPA0_AGC_SGEN_32X27_SGEN_MEM_A0_HI_REG_RESETVAL (0x00000000u)

/* CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa1_sync_switch_th_0_15 : 16;
#else 
    Uint32 cpa1_sync_switch_th_0_15 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_LO_REG;

/* Switching time #0-#15 - LSW for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_LO_REG_CPA1_SYNC_SWITCH_TH_0_15_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_LO_REG_CPA1_SYNC_SWITCH_TH_0_15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_LO_REG_CPA1_SYNC_SWITCH_TH_0_15_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_LO_REG_ADDR (0x00010080u)
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_LO_REG_RESETVAL (0x00000000u)

/* CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 21;
    Uint32 cpa1_sync_state_map_0_15 : 3;
    Uint32 cpa1_sync_switch_th_0_15 : 8;
#else 
    Uint32 cpa1_sync_switch_th_0_15 : 8;
    Uint32 cpa1_sync_state_map_0_15 : 3;
    Uint32 rsvd0 : 21;
#endif 
} CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI_REG;

/* Switching time #0-#15 - MSB for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI_REG_CPA1_SYNC_SWITCH_TH_0_15_MASK (0x000000FFu)
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI_REG_CPA1_SYNC_SWITCH_TH_0_15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI_REG_CPA1_SYNC_SWITCH_TH_0_15_RESETVAL (0x00000000u)

/* Stage mapping of switch #0-#7 for antenna #1 */
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI_REG_CPA1_SYNC_STATE_MAP_0_15_MASK (0x00000700u)
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI_REG_CPA1_SYNC_STATE_MAP_0_15_SHIFT (0x00000008u)
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI_REG_CPA1_SYNC_STATE_MAP_0_15_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI_REG_ADDR (0x00010084u)
#define CSL_DFE_CFR_CPA1_AGC_SGEN_32X27_SGEN_MEM_A1_HI_REG_RESETVAL (0x00000000u)

/* CPA0_AGC_16X19_PRMS_MEM_A0LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa0_eng_static_gain_0_7 : 12;
    Uint32 cpa0_eng_ff_inlog2_0_7 : 4;
#else 
    Uint32 cpa0_eng_ff_inlog2_0_7 : 4;
    Uint32 cpa0_eng_static_gain_0_7 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0LO_REG;

/* Weighting factor minus 5 for the running average for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0LO_REG_CPA0_ENG_FF_INLOG2_0_7_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0LO_REG_CPA0_ENG_FF_INLOG2_0_7_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0LO_REG_CPA0_ENG_FF_INLOG2_0_7_RESETVAL (0x00000000u)

/* AGC static gain LSbits for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0LO_REG_CPA0_ENG_STATIC_GAIN_0_7_MASK (0x0000FFF0u)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0LO_REG_CPA0_ENG_STATIC_GAIN_0_7_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0LO_REG_CPA0_ENG_STATIC_GAIN_0_7_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0LO_REG_ADDR (0x00010100u)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0LO_REG_RESETVAL (0x00000000u)

/* CPA0_AGC_16X19_PRMS_MEM_A0HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 cpa0_mode_0_7 : 2;
    Uint32 cpa0_eng_static_gain_0_7 : 1;
#else 
    Uint32 cpa0_eng_static_gain_0_7 : 1;
    Uint32 cpa0_mode_0_7 : 2;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0HI_REG;

/* AGC static gain MSb for antenna #0 */
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0HI_REG_CPA0_ENG_STATIC_GAIN_0_7_MASK (0x00000001u)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0HI_REG_CPA0_ENG_STATIC_GAIN_0_7_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0HI_REG_CPA0_ENG_STATIC_GAIN_0_7_RESETVAL (0x00000000u)

/* AGC adaptation mode for antenna #0: */
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0HI_REG_CPA0_MODE_0_7_MASK (0x00000006u)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0HI_REG_CPA0_MODE_0_7_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0HI_REG_CPA0_MODE_0_7_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0HI_REG_ADDR (0x00010104u)
#define CSL_DFE_CFR_CPA0_AGC_16X19_PRMS_MEM_A0HI_REG_RESETVAL (0x00000000u)

/* CPA1_AGC_16X19_PRMS_MEM_A1LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cpa1_eng_static_gain_0_7 : 12;
    Uint32 cpa1_eng_ff_inlog2_0_7 : 4;
#else 
    Uint32 cpa1_eng_ff_inlog2_0_7 : 4;
    Uint32 cpa1_eng_static_gain_0_7 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1LO_REG;

/* Weighting factor minus 5 for the running average for antenna #0 */
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1LO_REG_CPA1_ENG_FF_INLOG2_0_7_MASK (0x0000000Fu)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1LO_REG_CPA1_ENG_FF_INLOG2_0_7_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1LO_REG_CPA1_ENG_FF_INLOG2_0_7_RESETVAL (0x00000000u)

/* AGC static gain LSbits for antenna #0 */
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1LO_REG_CPA1_ENG_STATIC_GAIN_0_7_MASK (0x0000FFF0u)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1LO_REG_CPA1_ENG_STATIC_GAIN_0_7_SHIFT (0x00000004u)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1LO_REG_CPA1_ENG_STATIC_GAIN_0_7_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1LO_REG_ADDR (0x00010108u)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1LO_REG_RESETVAL (0x00000000u)

/* CPA1_AGC_16X19_PRMS_MEM_A1HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 cpa1_mode_0_7 : 2;
    Uint32 cpa1_eng_static_gain_0_7 : 1;
#else 
    Uint32 cpa1_eng_static_gain_0_7 : 1;
    Uint32 cpa1_mode_0_7 : 2;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1HI_REG;

/* AGC static gain MSb for antenna #0 */
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1HI_REG_CPA1_ENG_STATIC_GAIN_0_7_MASK (0x00000001u)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1HI_REG_CPA1_ENG_STATIC_GAIN_0_7_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1HI_REG_CPA1_ENG_STATIC_GAIN_0_7_RESETVAL (0x00000000u)

/* AGC adaptation mode for antenna #0: */
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1HI_REG_CPA1_MODE_0_7_MASK (0x00000006u)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1HI_REG_CPA1_MODE_0_7_SHIFT (0x00000001u)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1HI_REG_CPA1_MODE_0_7_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1HI_REG_ADDR (0x0001010Cu)
#define CSL_DFE_CFR_CPA1_AGC_16X19_PRMS_MEM_A1HI_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_detect_th_phase0_31_stage0 : 16;
#else 
    Uint32 dth0_eng_peak_detect_th_phase0_31_stage0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W0_REG;

/* detect Threshold for antenna #0, stage 0, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W0_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W0_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W0_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W0_REG_ADDR (0x00014000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W0_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_target_th_phase0_31_stage0 : 16;
#else 
    Uint32 dth0_eng_peak_target_th_phase0_31_stage0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W1_REG;

/* target Threshold for antenna #0, stage 0, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W1_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W1_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W1_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W1_REG_ADDR (0x00014004u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W1_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_detect_th_phase0_31_stage1 : 16;
#else 
    Uint32 dth0_eng_peak_detect_th_phase0_31_stage1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W2_REG;

/* detect Threshold for antenna #0, stage 1, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W2_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W2_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W2_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W2_REG_ADDR (0x00014008u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W2_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_target_th_phase0_31_stage1 : 16;
#else 
    Uint32 dth0_eng_peak_target_th_phase0_31_stage1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W3_REG;

/* target Threshold for antenna #0, stage 1, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W3_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W3_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W3_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W3_REG_ADDR (0x0001400Cu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W3_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_detect_th_phase0_31_stage2 : 16;
#else 
    Uint32 dth0_eng_peak_detect_th_phase0_31_stage2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W4_REG;

/* detect Threshold for antenna #0, stage 2, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W4_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE2_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W4_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W4_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE2_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W4_REG_ADDR (0x00014010u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W4_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_target_th_phase0_31_stage2 : 16;
#else 
    Uint32 dth0_eng_peak_target_th_phase0_31_stage2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W5_REG;

/* target Threshold for antenna #0, stage 2, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W5_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE2_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W5_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W5_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE2_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W5_REG_ADDR (0x00014014u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W5_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W6 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_detect_th_phase0_31_stage3 : 16;
#else 
    Uint32 dth0_eng_peak_detect_th_phase0_31_stage3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W6_REG;

/* detect Threshold for antenna #0, stage 3, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W6_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE3_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W6_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE3_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W6_REG_DTH0_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE3_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W6_REG_ADDR (0x00014018u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W6_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W7 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_target_th_phase0_31_stage3 : 16;
#else 
    Uint32 dth0_eng_peak_target_th_phase0_31_stage3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W7_REG;

/* target Threshold for antenna #0, stage 3, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W7_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE3_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W7_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE3_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W7_REG_DTH0_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE3_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W7_REG_ADDR (0x0001401Cu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W7_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W8 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_detect_phase0_31_stage1 : 8;
    Uint32 dth0_eng_peak_detect_phase0_31_stage0 : 8;
#else 
    Uint32 dth0_eng_peak_detect_phase0_31_stage0 : 8;
    Uint32 dth0_eng_peak_detect_phase0_31_stage1 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W8_REG;

/* Hysteresis for antenna #0, stage 0, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W8_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE0_MASK (0x000000FFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W8_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W8_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE0_RESETVAL (0x00000000u)

/* Hysteresis for antenna #0, stage 1, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W8_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE1_MASK (0x0000FF00u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W8_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W8_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W8_REG_ADDR (0x00014020u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W8_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_64X160_TH_MEM_W9 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_eng_peak_detect_phase0_31_stage3 : 8;
    Uint32 dth0_eng_peak_detect_phase0_31_stage2 : 8;
#else 
    Uint32 dth0_eng_peak_detect_phase0_31_stage2 : 8;
    Uint32 dth0_eng_peak_detect_phase0_31_stage3 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W9_REG;

/* Hysteresis for antenna #0, stage 2, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W9_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE2_MASK (0x000000FFu)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W9_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W9_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE2_RESETVAL (0x00000000u)

/* Hysteresis for antenna #0, stage 3, phases #1-#31 */
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W9_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE3_MASK (0x0000FF00u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W9_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE3_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W9_REG_DTH0_ENG_PEAK_DETECT_PHASE0_31_STAGE3_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W9_REG_ADDR (0x00014024u)
#define CSL_DFE_CFR_DTH0_DTH_64X160_TH_MEM_W9_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W10 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_detect_th_phase0_31_stage0 : 16;
#else 
    Uint32 dth1_eng_peak_detect_th_phase0_31_stage0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W10_REG;

/* detect Threshold for antenna #1, stage 0, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W10_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W10_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W10_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W10_REG_ADDR (0x00014800u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W10_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W11 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_target_th_phase0_31_stage0 : 16;
#else 
    Uint32 dth1_eng_peak_target_th_phase0_31_stage0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W11_REG;

/* target Threshold for antenna #1, stage 0, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W11_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W11_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W11_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W11_REG_ADDR (0x00014804u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W11_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W12 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_detect_th_phase0_31_stage1 : 16;
#else 
    Uint32 dth1_eng_peak_detect_th_phase0_31_stage1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W12_REG;

/* detect Threshold for antenna #1, stage 1, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W12_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W12_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W12_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W12_REG_ADDR (0x00014808u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W12_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W13 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_target_th_phase0_31_stage1 : 16;
#else 
    Uint32 dth1_eng_peak_target_th_phase0_31_stage1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W13_REG;

/* target Threshold for antenna #1, stage 1, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W13_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W13_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W13_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W13_REG_ADDR (0x0001480Cu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W13_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W14 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_detect_th_phase0_31_stage2 : 16;
#else 
    Uint32 dth1_eng_peak_detect_th_phase0_31_stage2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W14_REG;

/* detect Threshold for antenna #1, stage 2, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W14_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE2_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W14_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W14_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE2_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W14_REG_ADDR (0x00014810u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W14_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W15 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_target_th_phase0_31_stage2 : 16;
#else 
    Uint32 dth1_eng_peak_target_th_phase0_31_stage2 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W15_REG;

/* target Threshold for antenna #1, stage 2, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W15_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE2_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W15_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W15_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE2_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W15_REG_ADDR (0x00014814u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W15_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W16 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_detect_th_phase0_31_stage3 : 16;
#else 
    Uint32 dth1_eng_peak_detect_th_phase0_31_stage3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W16_REG;

/* detect Threshold for antenna #1, stage 3, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W16_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE3_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W16_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE3_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W16_REG_DTH1_ENG_PEAK_DETECT_TH_PHASE0_31_STAGE3_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W16_REG_ADDR (0x00014818u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W16_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W17 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_target_th_phase0_31_stage3 : 16;
#else 
    Uint32 dth1_eng_peak_target_th_phase0_31_stage3 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W17_REG;

/* target Threshold for antenna #1, stage 3, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W17_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE3_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W17_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE3_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W17_REG_DTH1_ENG_PEAK_TARGET_TH_PHASE0_31_STAGE3_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W17_REG_ADDR (0x0001481Cu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W17_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W18 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_detect_phase0_31_stage1 : 8;
    Uint32 dth1_eng_peak_detect_phase0_31_stage0 : 8;
#else 
    Uint32 dth1_eng_peak_detect_phase0_31_stage0 : 8;
    Uint32 dth1_eng_peak_detect_phase0_31_stage1 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W18_REG;

/* Hysteresis for antenna #1, stage 0, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W18_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE0_MASK (0x000000FFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W18_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W18_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE0_RESETVAL (0x00000000u)

/* Hysteresis for antenna #1, stage 1, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W18_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE1_MASK (0x0000FF00u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W18_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W18_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W18_REG_ADDR (0x00014820u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W18_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_64X160_TH_MEM_W19 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_eng_peak_detect_phase0_31_stage3 : 8;
    Uint32 dth1_eng_peak_detect_phase0_31_stage2 : 8;
#else 
    Uint32 dth1_eng_peak_detect_phase0_31_stage2 : 8;
    Uint32 dth1_eng_peak_detect_phase0_31_stage3 : 8;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W19_REG;

/* Hysteresis for antenna #1, stage 2, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W19_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE2_MASK (0x000000FFu)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W19_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE2_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W19_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE2_RESETVAL (0x00000000u)

/* Hysteresis for antenna #1, stage 3, phases #1-#31 */
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W19_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE3_MASK (0x0000FF00u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W19_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE3_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W19_REG_DTH1_ENG_PEAK_DETECT_PHASE0_31_STAGE3_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W19_REG_ADDR (0x00014824u)
#define CSL_DFE_CFR_DTH1_DTH_64X160_TH_MEM_W19_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth0_switch_th_0_15 : 16;
#else 
    Uint32 dth0_switch_th_0_15 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG;

/* Switching time #0-#15 - LSW for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_DTH0_SWITCH_TH_0_15_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_DTH0_SWITCH_TH_0_15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_DTH0_SWITCH_TH_0_15_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_ADDR (0x00015000u)
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_RESETVAL (0x00000000u)

/* DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 dth0_state_map_0_15 : 5;
    Uint32 dth0_switch_th_0_15 : 8;
#else 
    Uint32 dth0_switch_th_0_15 : 8;
    Uint32 dth0_state_map_0_15 : 5;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG;

/* Switching time #0-#15 - MSB for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH0_SWITCH_TH_0_15_MASK (0x000000FFu)
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH0_SWITCH_TH_0_15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH0_SWITCH_TH_0_15_RESETVAL (0x00000000u)

/* Stage mapping of switch #0-#7 for antenna #0 */
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH0_STATE_MAP_0_15_MASK (0x00001F00u)
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH0_STATE_MAP_0_15_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH0_STATE_MAP_0_15_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_ADDR (0x00015004u)
#define CSL_DFE_CFR_DTH0_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth1_switch_th_0_15 : 16;
#else 
    Uint32 dth1_switch_th_0_15 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG;

/* Switching time #0-#15 - LSW for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_DTH1_SWITCH_TH_0_15_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_DTH1_SWITCH_TH_0_15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_DTH1_SWITCH_TH_0_15_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_ADDR (0x00015080u)
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_RESETVAL (0x00000000u)

/* DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 dth1_state_map_0_15 : 5;
    Uint32 dth1_switch_th_0_15 : 8;
#else 
    Uint32 dth1_switch_th_0_15 : 8;
    Uint32 dth1_state_map_0_15 : 5;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG;

/* Switching time #0-#15 - MSB for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH1_SWITCH_TH_0_15_MASK (0x000000FFu)
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH1_SWITCH_TH_0_15_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH1_SWITCH_TH_0_15_RESETVAL (0x00000000u)

/* Stage mapping of switch #0-#7 for antenna #1 */
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH1_STATE_MAP_0_15_MASK (0x00001F00u)
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH1_STATE_MAP_0_15_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH1_STATE_MAP_0_15_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_ADDR (0x00015084u)
#define CSL_DFE_CFR_DTH1_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_RESETVAL (0x00000000u)

/* DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth_cpa_switch_th_a0 : 16;
#else 
    Uint32 dth_cpa_switch_th_a0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG;

/* Switching time #0-#15 - LSW for both AGC and DTH for antenna #0 */
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_DTH_CPA_SWITCH_TH_A0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_DTH_CPA_SWITCH_TH_A0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_DTH_CPA_SWITCH_TH_A0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_ADDR (0x00015100u)
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_LO_REG_RESETVAL (0x00000000u)

/* DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 dth_cpa_state_map_a0 : 5;
    Uint32 dth_cpa_switch_th_a0 : 8;
#else 
    Uint32 dth_cpa_switch_th_a0 : 8;
    Uint32 dth_cpa_state_map_a0 : 5;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG;

/* Switching time #0-#15 - MSB for both AGC and DTH for antenna #0 */
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH_CPA_SWITCH_TH_A0_MASK (0x000000FFu)
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH_CPA_SWITCH_TH_A0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH_CPA_SWITCH_TH_A0_RESETVAL (0x00000000u)

/* Stage mapping of switch #0-#7 for both AGC and DTH for antenna #0 */
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH_CPA_STATE_MAP_A0_MASK (0x00001F00u)
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH_CPA_STATE_MAP_A0_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_DTH_CPA_STATE_MAP_A0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_ADDR (0x00015104u)
#define CSL_DFE_CFR_DTH0_AGC_DTH_SGEN_32X27_SGEN_MEM_A0_HI_REG_RESETVAL (0x00000000u)

/* DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 dth_cpa_switch_th_a1 : 16;
#else 
    Uint32 dth_cpa_switch_th_a1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG;

/* Switching time #0-#15 - LSW for both AGC and DTH for antenna #1 */
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_DTH_CPA_SWITCH_TH_A1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_DTH_CPA_SWITCH_TH_A1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_DTH_CPA_SWITCH_TH_A1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_ADDR (0x00015180u)
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_LO_REG_RESETVAL (0x00000000u)

/* DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 19;
    Uint32 dth_cpa_state_map_a1 : 5;
    Uint32 dth_cpa_switch_th_a1 : 8;
#else 
    Uint32 dth_cpa_switch_th_a1 : 8;
    Uint32 dth_cpa_state_map_a1 : 5;
    Uint32 rsvd0 : 19;
#endif 
} CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG;

/* Switching time #0-#15 - MSB for both AGC and DTH for antenna #1 */
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH_CPA_SWITCH_TH_A1_MASK (0x000000FFu)
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH_CPA_SWITCH_TH_A1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH_CPA_SWITCH_TH_A1_RESETVAL (0x00000000u)

/* Stage mapping of switch #0-#7 for both AGC and DTH for antenna #1 */
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH_CPA_STATE_MAP_A1_MASK (0x00001F00u)
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH_CPA_STATE_MAP_A1_SHIFT (0x00000008u)
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_DTH_CPA_STATE_MAP_A1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_ADDR (0x00015184u)
#define CSL_DFE_CFR_DTH1_AGC_DTH_SGEN_32X27_SGEN_MEM_A1_HI_REG_RESETVAL (0x00000000u)

/* CFR_CL_256X26_CL_LUT_A0_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 cfr_cl_filename_0 : 10;
#else 
    Uint32 cfr_cl_filename_0 : 10;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_LO_REG;

/* Interpolation slope for entries #0-#127 for antenna #0 */
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_LO_REG_CFR_CL_FILENAME_0_MASK (0x000003FFu)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_LO_REG_CFR_CL_FILENAME_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_LO_REG_CFR_CL_FILENAME_0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_LO_REG_ADDR (0x00018000u)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_LO_REG_RESETVAL (0x00000000u)

/* CFR_CL_256X26_CL_LUT_A0_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_cl_filename_0 : 16;
#else 
    Uint32 cfr_cl_filename_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_HI_REG;

/* Base #0-#127 for antenna #0 */
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_HI_REG_CFR_CL_FILENAME_0_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_HI_REG_CFR_CL_FILENAME_0_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_HI_REG_CFR_CL_FILENAME_0_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_HI_REG_ADDR (0x00018004u)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A0_HI_REG_RESETVAL (0x00000000u)

/* CFR_CL_256X26_CL_LUT_A1_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 cfr_cl_filename_1 : 10;
#else 
    Uint32 cfr_cl_filename_1 : 10;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_LO_REG;

/* Interpolation slope for entries #0-#127 for antenna #1 */
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_LO_REG_CFR_CL_FILENAME_1_MASK (0x000003FFu)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_LO_REG_CFR_CL_FILENAME_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_LO_REG_CFR_CL_FILENAME_1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_LO_REG_ADDR (0x00018400u)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_LO_REG_RESETVAL (0x00000000u)

/* CFR_CL_256X26_CL_LUT_A1_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 cfr_cl_filename_1 : 16;
#else 
    Uint32 cfr_cl_filename_1 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_HI_REG;

/* Base #0-#127 for antenna #1 */
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_HI_REG_CFR_CL_FILENAME_1_MASK (0x0000FFFFu)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_HI_REG_CFR_CL_FILENAME_1_SHIFT (0x00000000u)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_HI_REG_CFR_CL_FILENAME_1_RESETVAL (0x00000000u)

#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_HI_REG_ADDR (0x00018404u)
#define CSL_DFE_CFR_CFR_CL_256X26_CL_LUT_A1_HI_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_CFR_H__ */
