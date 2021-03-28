/*
 * cslr_dfe_dpd.h
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

/* The file is auto generated at 14:43:47 02/19/13 (Rev 1.68)*/

#ifndef CSLR_DFE_DPD_H__
#define CSLR_DFE_DPD_H__

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/

typedef struct 
{
    /* Addr: h(0), d(0) */
    volatile Uint32 rsvd0[128];
    /* Addr: h(200), d(512) */
    volatile Uint32 top_subchip_mode_subsample;
    /* Addr: h(204), d(516) */
    volatile Uint32 input_dpdinput_scale;
    /* Addr: h(208), d(520) */
    volatile Uint32 input_mux_sqrt;
    /* Addr: h(20C), d(524) */
    volatile Uint32 input_mux_complx_signal;
    /* Addr: h(210), d(528) */
    volatile Uint32 input_mux_real_magnitude;
    /* Addr: h(214), d(532) */
    volatile Uint32 output_mux_dpd_output;
    /* Addr: h(218), d(536) */
    volatile Uint32 top_dpdadapt_update_mode;
    /* Addr: h(21C), d(540) */
    volatile Uint32 top_f_ssel;
    /* Addr: h(220), d(544) */
    volatile Uint32 top_c_ssel;
    /* Addr: h(224), d(548) */
    volatile Uint32 top_dpd_disable;
    /* Addr: h(228), d(552) */
    volatile Uint32 top_sync_b_ssel;
    /* Addr: h(22C), d(556) */
    volatile Uint32 top_inits;
    /* Addr: h(230), d(560) */
    volatile Uint32 top_gc_clk_gate_delay;
    /* Addr: h(234), d(564) */
    volatile Uint32 top_testbus_control;
    /* Addr: h(238), d(568) */
    volatile Uint32 rsvd1[114];
    /* Addr: h(400), d(1024) */
    volatile Uint32 dpd0_mux_blk0;
    /* Addr: h(404), d(1028) */
    volatile Uint32 dpd0_current_lut_mpu_blk0;
    /* Addr: h(408), d(1032) */
    volatile Uint32 dpd0_row_cell_config_blk0_row0;
    /* Addr: h(40C), d(1036) */
    volatile Uint32 dpd0_row_cell_config_blk0_row1;
    /* Addr: h(410), d(1040) */
    volatile Uint32 dpd0_row_cell_config_blk0_row2;
    /* Addr: h(414), d(1044) */
    volatile Uint32 dpd0_row_cell_config_blk0_row3;
    /* Addr: h(418), d(1048) */
    volatile Uint32 dpd0_row_cell_config_blk0_row4;
    /* Addr: h(41C), d(1052) */
    volatile Uint32 dpd0_row_cell_config_blk0_row5;
    /* Addr: h(420), d(1056) */
    volatile Uint32 dpd1_mux_blk1;
    /* Addr: h(424), d(1060) */
    volatile Uint32 dpd1_current_lut_mpu_blk1;
    /* Addr: h(428), d(1064) */
    volatile Uint32 dpd1_row_cell_config_blk1_row0;
    /* Addr: h(42C), d(1068) */
    volatile Uint32 dpd1_row_cell_config_blk1_row1;
    /* Addr: h(430), d(1072) */
    volatile Uint32 dpd1_row_cell_config_blk1_row2;
    /* Addr: h(434), d(1076) */
    volatile Uint32 dpd1_row_cell_config_blk1_row3;
    /* Addr: h(438), d(1080) */
    volatile Uint32 dpd1_row_cell_config_blk1_row4;
    /* Addr: h(43C), d(1084) */
    volatile Uint32 dpd1_row_cell_config_blk1_row5;
    /* Addr: h(440), d(1088) */
    volatile Uint32 dpd2_mux_blk2;
    /* Addr: h(444), d(1092) */
    volatile Uint32 dpd2_current_lut_mpu_blk2;
    /* Addr: h(448), d(1096) */
    volatile Uint32 dpd2_row_cell_config_blk2_row0;
    /* Addr: h(44C), d(1100) */
    volatile Uint32 dpd2_row_cell_config_blk2_row1;
    /* Addr: h(450), d(1104) */
    volatile Uint32 dpd2_row_cell_config_blk2_row2;
    /* Addr: h(454), d(1108) */
    volatile Uint32 dpd2_row_cell_config_blk2_row3;
    /* Addr: h(458), d(1112) */
    volatile Uint32 dpd2_row_cell_config_blk2_row4;
    /* Addr: h(45C), d(1116) */
    volatile Uint32 dpd2_row_cell_config_blk2_row5;
    /* Addr: h(460), d(1120) */
    volatile Uint32 dpd3_mux_blk3;
    /* Addr: h(464), d(1124) */
    volatile Uint32 dpd3_current_lut_mpu_blk3;
    /* Addr: h(468), d(1128) */
    volatile Uint32 dpd3_row_cell_config_blk3_row0;
    /* Addr: h(46C), d(1132) */
    volatile Uint32 dpd3_row_cell_config_blk3_row1;
    /* Addr: h(470), d(1136) */
    volatile Uint32 dpd3_row_cell_config_blk3_row2;
    /* Addr: h(474), d(1140) */
    volatile Uint32 dpd3_row_cell_config_blk3_row3;
    /* Addr: h(478), d(1144) */
    volatile Uint32 dpd3_row_cell_config_blk3_row4;
    /* Addr: h(47C), d(1148) */
    volatile Uint32 dpd3_row_cell_config_blk3_row5;
    /* Addr: h(480), d(1152) */
    volatile Uint32 rsvd2[101];
    /* Addr: h(614), d(1556) */
    volatile Uint32 top_signal_gen0_general;
    /* Addr: h(618), d(1560) */
    volatile Uint32 top_signal_gen0_ramp_start_lo;
    /* Addr: h(61C), d(1564) */
    volatile Uint32 top_signal_gen0_ramp_start_hi;
    /* Addr: h(620), d(1568) */
    volatile Uint32 top_signal_gen0_ramp_stop_lo;
    /* Addr: h(624), d(1572) */
    volatile Uint32 top_signal_gen0_ramp_stop_hi;
    /* Addr: h(628), d(1576) */
    volatile Uint32 top_signal_gen0_ramp_slope_lo;
    /* Addr: h(62C), d(1580) */
    volatile Uint32 top_signal_gen0_ramp_slope_hi;
    /* Addr: h(630), d(1584) */
    volatile Uint32 top_signal_gen0_gen_timer;
    /* Addr: h(634), d(1588) */
    volatile Uint32 top_signal_gen0_internal_only;
    /* Addr: h(638), d(1592) */
    volatile Uint32 top_signal_gen1_general;
    /* Addr: h(63C), d(1596) */
    volatile Uint32 top_signal_gen1_ramp_start_lo;
    /* Addr: h(640), d(1600) */
    volatile Uint32 top_signal_gen1_ramp_start_hi;
    /* Addr: h(644), d(1604) */
    volatile Uint32 top_signal_gen1_ramp_stop_lo;
    /* Addr: h(648), d(1608) */
    volatile Uint32 top_signal_gen1_ramp_stop_hi;
    /* Addr: h(64C), d(1612) */
    volatile Uint32 top_signal_gen1_ramp_slope_lo;
    /* Addr: h(650), d(1616) */
    volatile Uint32 top_signal_gen1_ramp_slope_hi;
    /* Addr: h(654), d(1620) */
    volatile Uint32 top_signal_gen1_gen_timer;
    /* Addr: h(658), d(1624) */
    volatile Uint32 top_signal_gen1_internal_only;
    /* Addr: h(65C), d(1628) */
    volatile Uint32 top_signal_gen2_general;
    /* Addr: h(660), d(1632) */
    volatile Uint32 top_signal_gen2_ramp_start_lo;
    /* Addr: h(664), d(1636) */
    volatile Uint32 top_signal_gen2_ramp_start_hi;
    /* Addr: h(668), d(1640) */
    volatile Uint32 top_signal_gen2_ramp_stop_lo;
    /* Addr: h(66C), d(1644) */
    volatile Uint32 top_signal_gen2_ramp_stop_hi;
    /* Addr: h(670), d(1648) */
    volatile Uint32 top_signal_gen2_ramp_slope_lo;
    /* Addr: h(674), d(1652) */
    volatile Uint32 top_signal_gen2_ramp_slope_hi;
    /* Addr: h(678), d(1656) */
    volatile Uint32 top_signal_gen2_gen_timer;
    /* Addr: h(67C), d(1660) */
    volatile Uint32 top_signal_gen2_internal_only;
    /* Addr: h(680), d(1664) */
    volatile Uint32 top_signal_gen3_general;
    /* Addr: h(684), d(1668) */
    volatile Uint32 top_signal_gen3_ramp_start_lo;
    /* Addr: h(688), d(1672) */
    volatile Uint32 top_signal_gen3_ramp_start_hi;
    /* Addr: h(68C), d(1676) */
    volatile Uint32 top_signal_gen3_ramp_stop_lo;
    /* Addr: h(690), d(1680) */
    volatile Uint32 top_signal_gen3_ramp_stop_hi;
    /* Addr: h(694), d(1684) */
    volatile Uint32 top_signal_gen3_ramp_slope_lo;
    /* Addr: h(698), d(1688) */
    volatile Uint32 top_signal_gen3_ramp_slope_hi;
    /* Addr: h(69C), d(1692) */
    volatile Uint32 top_signal_gen3_gen_timer;
    /* Addr: h(6A0), d(1696) */
    volatile Uint32 top_signal_gen3_internal_only;
    /* Addr: h(6A4), d(1700) */
    volatile Uint32 top_signal_gen4_general;
    /* Addr: h(6A8), d(1704) */
    volatile Uint32 top_signal_gen4_ramp_start_lo;
    /* Addr: h(6AC), d(1708) */
    volatile Uint32 top_signal_gen4_ramp_start_hi;
    /* Addr: h(6B0), d(1712) */
    volatile Uint32 top_signal_gen4_ramp_stop_lo;
    /* Addr: h(6B4), d(1716) */
    volatile Uint32 top_signal_gen4_ramp_stop_hi;
    /* Addr: h(6B8), d(1720) */
    volatile Uint32 top_signal_gen4_ramp_slope_lo;
    /* Addr: h(6BC), d(1724) */
    volatile Uint32 top_signal_gen4_ramp_slope_hi;
    /* Addr: h(6C0), d(1728) */
    volatile Uint32 top_signal_gen4_gen_timer;
    /* Addr: h(6C4), d(1732) */
    volatile Uint32 top_signal_gen4_internal_only;
    /* Addr: h(6C8), d(1736) */
    volatile Uint32 top_signal_gen5_general;
    /* Addr: h(6CC), d(1740) */
    volatile Uint32 top_signal_gen5_ramp_start_lo;
    /* Addr: h(6D0), d(1744) */
    volatile Uint32 top_signal_gen5_ramp_start_hi;
    /* Addr: h(6D4), d(1748) */
    volatile Uint32 top_signal_gen5_ramp_stop_lo;
    /* Addr: h(6D8), d(1752) */
    volatile Uint32 top_signal_gen5_ramp_stop_hi;
    /* Addr: h(6DC), d(1756) */
    volatile Uint32 top_signal_gen5_ramp_slope_lo;
    /* Addr: h(6E0), d(1760) */
    volatile Uint32 top_signal_gen5_ramp_slope_hi;
    /* Addr: h(6E4), d(1764) */
    volatile Uint32 top_signal_gen5_gen_timer;
    /* Addr: h(6E8), d(1768) */
    volatile Uint32 top_signal_gen5_internal_only;
    /* Addr: h(6EC), d(1772) */
    volatile Uint32 top_signal_gen6_general;
    /* Addr: h(6F0), d(1776) */
    volatile Uint32 top_signal_gen6_ramp_start_lo;
    /* Addr: h(6F4), d(1780) */
    volatile Uint32 top_signal_gen6_ramp_start_hi;
    /* Addr: h(6F8), d(1784) */
    volatile Uint32 top_signal_gen6_ramp_stop_lo;
    /* Addr: h(6FC), d(1788) */
    volatile Uint32 top_signal_gen6_ramp_stop_hi;
    /* Addr: h(700), d(1792) */
    volatile Uint32 top_signal_gen6_ramp_slope_lo;
    /* Addr: h(704), d(1796) */
    volatile Uint32 top_signal_gen6_ramp_slope_hi;
    /* Addr: h(708), d(1800) */
    volatile Uint32 top_signal_gen6_gen_timer;
    /* Addr: h(70C), d(1804) */
    volatile Uint32 top_signal_gen6_internal_only;
    /* Addr: h(710), d(1808) */
    volatile Uint32 top_signal_gen7_general;
    /* Addr: h(714), d(1812) */
    volatile Uint32 top_signal_gen7_ramp_start_lo;
    /* Addr: h(718), d(1816) */
    volatile Uint32 top_signal_gen7_ramp_start_hi;
    /* Addr: h(71C), d(1820) */
    volatile Uint32 top_signal_gen7_ramp_stop_lo;
    /* Addr: h(720), d(1824) */
    volatile Uint32 top_signal_gen7_ramp_stop_hi;
    /* Addr: h(724), d(1828) */
    volatile Uint32 top_signal_gen7_ramp_slope_lo;
    /* Addr: h(728), d(1832) */
    volatile Uint32 top_signal_gen7_ramp_slope_hi;
    /* Addr: h(72C), d(1836) */
    volatile Uint32 top_signal_gen7_gen_timer;
    /* Addr: h(730), d(1840) */
    volatile Uint32 top_signal_gen7_internal_only;
    /* Addr: h(734), d(1844) */
    volatile Uint32 top_check_sum_ctrl;
    /* Addr: h(738), d(1848) */
    volatile Uint32 top_check_sum_signal_len;
    /* Addr: h(73C), d(1852) */
    volatile Uint32 top_check_sum_chan_sel;
    /* Addr: h(740), d(1856) */
    volatile Uint32 top_check_sum_result_lo;
    /* Addr: h(744), d(1860) */
    volatile Uint32 top_check_sum_result_hi;
    /* Addr: h(748), d(1864) */
    volatile Uint32 top_signal_gen_ssel_part0;
    /* Addr: h(74C), d(1868) */
    volatile Uint32 top_signal_gen_ssel_part1;
    /* Addr: h(750), d(1872) */
    volatile Uint32 top_check_sum_ssel;
    /* Addr: h(754), d(1876) */
    volatile Uint32 rsvd3[65067];
    /* Addr: h(40000), d(262144) */
    volatile Uint32 dpd0_dpdlut_b0_r0_c0[512];
    /* Addr: h(40800), d(264192) */
    volatile Uint32 dpd0_dpdlut_b0_r0_c1[512];
    /* Addr: h(41000), d(266240) */
    volatile Uint32 dpd0_dpdlut_b0_r0_c2[512];
    /* Addr: h(41800), d(268288) */
    volatile Uint32 dpd0_dpdlut_b0_r1_c0[512];
    /* Addr: h(42000), d(270336) */
    volatile Uint32 dpd0_dpdlut_b0_r1_c1[512];
    /* Addr: h(42800), d(272384) */
    volatile Uint32 dpd0_dpdlut_b0_r1_c2[512];
    /* Addr: h(43000), d(274432) */
    volatile Uint32 dpd0_dpdlut_b0_r2_c0[512];
    /* Addr: h(43800), d(276480) */
    volatile Uint32 dpd0_dpdlut_b0_r2_c1[512];
    /* Addr: h(44000), d(278528) */
    volatile Uint32 dpd0_dpdlut_b0_r2_c2[512];
    /* Addr: h(44800), d(280576) */
    volatile Uint32 dpd0_dpdlut_b0_r3_c0[512];
    /* Addr: h(45000), d(282624) */
    volatile Uint32 dpd0_dpdlut_b0_r3_c1[512];
    /* Addr: h(45800), d(284672) */
    volatile Uint32 dpd0_dpdlut_b0_r3_c2[512];
    /* Addr: h(46000), d(286720) */
    volatile Uint32 dpd0_dpdlut_b0_r4_c0[512];
    /* Addr: h(46800), d(288768) */
    volatile Uint32 dpd0_dpdlut_b0_r4_c1[512];
    /* Addr: h(47000), d(290816) */
    volatile Uint32 dpd0_dpdlut_b0_r4_c2[512];
    /* Addr: h(47800), d(292864) */
    volatile Uint32 dpd0_dpdlut_b0_r5_c0[512];
    /* Addr: h(48000), d(294912) */
    volatile Uint32 dpd0_dpdlut_b0_r5_c1[512];
    /* Addr: h(48800), d(296960) */
    volatile Uint32 dpd0_dpdlut_b0_r5_c2[512];
    /* Addr: h(49000), d(299008) */
    volatile Uint32 dpd1_dpdlut_b1_r0_c0[512];
    /* Addr: h(49800), d(301056) */
    volatile Uint32 dpd1_dpdlut_b1_r0_c1[512];
    /* Addr: h(4A000), d(303104) */
    volatile Uint32 dpd1_dpdlut_b1_r0_c2[512];
    /* Addr: h(4A800), d(305152) */
    volatile Uint32 dpd1_dpdlut_b1_r1_c0[512];
    /* Addr: h(4B000), d(307200) */
    volatile Uint32 dpd1_dpdlut_b1_r1_c1[512];
    /* Addr: h(4B800), d(309248) */
    volatile Uint32 dpd1_dpdlut_b1_r1_c2[512];
    /* Addr: h(4C000), d(311296) */
    volatile Uint32 dpd1_dpdlut_b1_r2_c0[512];
    /* Addr: h(4C800), d(313344) */
    volatile Uint32 dpd1_dpdlut_b1_r2_c1[512];
    /* Addr: h(4D000), d(315392) */
    volatile Uint32 dpd1_dpdlut_b1_r2_c2[512];
    /* Addr: h(4D800), d(317440) */
    volatile Uint32 dpd1_dpdlut_b1_r3_c0[512];
    /* Addr: h(4E000), d(319488) */
    volatile Uint32 dpd1_dpdlut_b1_r3_c1[512];
    /* Addr: h(4E800), d(321536) */
    volatile Uint32 dpd1_dpdlut_b1_r3_c2[512];
    /* Addr: h(4F000), d(323584) */
    volatile Uint32 dpd1_dpdlut_b1_r4_c0[512];
    /* Addr: h(4F800), d(325632) */
    volatile Uint32 dpd1_dpdlut_b1_r4_c1[512];
    /* Addr: h(50000), d(327680) */
    volatile Uint32 dpd1_dpdlut_b1_r4_c2[512];
    /* Addr: h(50800), d(329728) */
    volatile Uint32 dpd1_dpdlut_b1_r5_c0[512];
    /* Addr: h(51000), d(331776) */
    volatile Uint32 dpd1_dpdlut_b1_r5_c1[512];
    /* Addr: h(51800), d(333824) */
    volatile Uint32 dpd1_dpdlut_b1_r5_c2[512];
    /* Addr: h(52000), d(335872) */
    volatile Uint32 dpd2_dpdlut_b2_r0_c0[512];
    /* Addr: h(52800), d(337920) */
    volatile Uint32 dpd2_dpdlut_b2_r0_c1[512];
    /* Addr: h(53000), d(339968) */
    volatile Uint32 dpd2_dpdlut_b2_r0_c2[512];
    /* Addr: h(53800), d(342016) */
    volatile Uint32 dpd2_dpdlut_b2_r1_c0[512];
    /* Addr: h(54000), d(344064) */
    volatile Uint32 dpd2_dpdlut_b2_r1_c1[512];
    /* Addr: h(54800), d(346112) */
    volatile Uint32 dpd2_dpdlut_b2_r1_c2[512];
    /* Addr: h(55000), d(348160) */
    volatile Uint32 dpd2_dpdlut_b2_r2_c0[512];
    /* Addr: h(55800), d(350208) */
    volatile Uint32 dpd2_dpdlut_b2_r2_c1[512];
    /* Addr: h(56000), d(352256) */
    volatile Uint32 dpd2_dpdlut_b2_r2_c2[512];
    /* Addr: h(56800), d(354304) */
    volatile Uint32 dpd2_dpdlut_b2_r3_c0[512];
    /* Addr: h(57000), d(356352) */
    volatile Uint32 dpd2_dpdlut_b2_r3_c1[512];
    /* Addr: h(57800), d(358400) */
    volatile Uint32 dpd2_dpdlut_b2_r3_c2[512];
    /* Addr: h(58000), d(360448) */
    volatile Uint32 dpd2_dpdlut_b2_r4_c0[512];
    /* Addr: h(58800), d(362496) */
    volatile Uint32 dpd2_dpdlut_b2_r4_c1[512];
    /* Addr: h(59000), d(364544) */
    volatile Uint32 dpd2_dpdlut_b2_r4_c2[512];
    /* Addr: h(59800), d(366592) */
    volatile Uint32 dpd2_dpdlut_b2_r5_c0[512];
    /* Addr: h(5A000), d(368640) */
    volatile Uint32 dpd2_dpdlut_b2_r5_c1[512];
    /* Addr: h(5A800), d(370688) */
    volatile Uint32 dpd2_dpdlut_b2_r5_c2[512];
    /* Addr: h(5B000), d(372736) */
    volatile Uint32 dpd3_dpdlut_b3_r0_c0[512];
    /* Addr: h(5B800), d(374784) */
    volatile Uint32 dpd3_dpdlut_b3_r0_c1[512];
    /* Addr: h(5C000), d(376832) */
    volatile Uint32 dpd3_dpdlut_b3_r0_c2[512];
    /* Addr: h(5C800), d(378880) */
    volatile Uint32 dpd3_dpdlut_b3_r1_c0[512];
    /* Addr: h(5D000), d(380928) */
    volatile Uint32 dpd3_dpdlut_b3_r1_c1[512];
    /* Addr: h(5D800), d(382976) */
    volatile Uint32 dpd3_dpdlut_b3_r1_c2[512];
    /* Addr: h(5E000), d(385024) */
    volatile Uint32 dpd3_dpdlut_b3_r2_c0[512];
    /* Addr: h(5E800), d(387072) */
    volatile Uint32 dpd3_dpdlut_b3_r2_c1[512];
    /* Addr: h(5F000), d(389120) */
    volatile Uint32 dpd3_dpdlut_b3_r2_c2[512];
    /* Addr: h(5F800), d(391168) */
    volatile Uint32 dpd3_dpdlut_b3_r3_c0[512];
    /* Addr: h(60000), d(393216) */
    volatile Uint32 dpd3_dpdlut_b3_r3_c1[512];
    /* Addr: h(60800), d(395264) */
    volatile Uint32 dpd3_dpdlut_b3_r3_c2[512];
    /* Addr: h(61000), d(397312) */
    volatile Uint32 dpd3_dpdlut_b3_r4_c0[512];
    /* Addr: h(61800), d(399360) */
    volatile Uint32 dpd3_dpdlut_b3_r4_c1[512];
    /* Addr: h(62000), d(401408) */
    volatile Uint32 dpd3_dpdlut_b3_r4_c2[512];
    /* Addr: h(62800), d(403456) */
    volatile Uint32 dpd3_dpdlut_b3_r5_c0[512];
    /* Addr: h(63000), d(405504) */
    volatile Uint32 dpd3_dpdlut_b3_r5_c1[512];
    /* Addr: h(63800), d(407552) */
    volatile Uint32 dpd3_dpdlut_b3_r5_c2[512];
} CSL_DFE_DPD_REGS;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* TOP_SUBCHIP_MODE_SUBSAMPLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 23;
    Uint32 subsample : 1;
    Uint32 rsvd0 : 4;
    Uint32 subchip_mode : 4;
#else 
    Uint32 subchip_mode : 4;
    Uint32 rsvd0 : 4;
    Uint32 subsample : 1;
    Uint32 rsvd1 : 23;
#endif 
} CSL_DFE_DPD_TOP_SUBCHIP_MODE_SUBSAMPLE_REG;

/* subchip mode: */
#define CSL_DFE_DPD_TOP_SUBCHIP_MODE_SUBSAMPLE_REG_SUBCHIP_MODE_MASK (0x0000000Fu)
#define CSL_DFE_DPD_TOP_SUBCHIP_MODE_SUBSAMPLE_REG_SUBCHIP_MODE_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SUBCHIP_MODE_SUBSAMPLE_REG_SUBCHIP_MODE_RESETVAL (0x00000000u)

/* subsample, matters when poly2LUT writes to DPD LUT's: */
#define CSL_DFE_DPD_TOP_SUBCHIP_MODE_SUBSAMPLE_REG_SUBSAMPLE_MASK (0x00000100u)
#define CSL_DFE_DPD_TOP_SUBCHIP_MODE_SUBSAMPLE_REG_SUBSAMPLE_SHIFT (0x00000008u)
#define CSL_DFE_DPD_TOP_SUBCHIP_MODE_SUBSAMPLE_REG_SUBSAMPLE_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SUBCHIP_MODE_SUBSAMPLE_REG_ADDR (0x00000200u)
#define CSL_DFE_DPD_TOP_SUBCHIP_MODE_SUBSAMPLE_REG_RESETVAL (0x00000000u)

/* INPUT_DPDINPUT_SCALE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 22;
    Uint32 dpdinput_scale : 10;
#else 
    Uint32 dpdinput_scale : 10;
    Uint32 rsvd0 : 22;
#endif 
} CSL_DFE_DPD_INPUT_DPDINPUT_SCALE_REG;

/* scaling factor applied to dpd input, in (4,6) format */
#define CSL_DFE_DPD_INPUT_DPDINPUT_SCALE_REG_DPDINPUT_SCALE_MASK (0x000003FFu)
#define CSL_DFE_DPD_INPUT_DPDINPUT_SCALE_REG_DPDINPUT_SCALE_SHIFT (0x00000000u)
#define CSL_DFE_DPD_INPUT_DPDINPUT_SCALE_REG_DPDINPUT_SCALE_RESETVAL (0x00000100u)

#define CSL_DFE_DPD_INPUT_DPDINPUT_SCALE_REG_ADDR (0x00000204u)
#define CSL_DFE_DPD_INPUT_DPDINPUT_SCALE_REG_RESETVAL (0x00000100u)

/* INPUT_MUX_SQRT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 23;
    Uint32 mux_magx3_sqrt : 1;
    Uint32 mux_magx2_sqrt : 1;
    Uint32 mux_r33_sqrt : 1;
    Uint32 mux_r32_sqrt : 1;
    Uint32 mux_r31_sqrt : 1;
    Uint32 mux_r2_sqrt : 1;
    Uint32 mux_r1_sqrt : 1;
    Uint32 mux_r01_sqrt : 1;
    Uint32 mux_r00_sqrt : 1;
#else 
    Uint32 mux_r00_sqrt : 1;
    Uint32 mux_r01_sqrt : 1;
    Uint32 mux_r1_sqrt : 1;
    Uint32 mux_r2_sqrt : 1;
    Uint32 mux_r31_sqrt : 1;
    Uint32 mux_r32_sqrt : 1;
    Uint32 mux_r33_sqrt : 1;
    Uint32 mux_magx2_sqrt : 1;
    Uint32 mux_magx3_sqrt : 1;
    Uint32 rsvd0 : 23;
#endif 
} CSL_DFE_DPD_INPUT_MUX_SQRT_REG;

/* choose to use the orignal value of 'r00' or the square root of the 'r00' as real magnitude:  */
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R00_SQRT_MASK (0x00000001u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R00_SQRT_SHIFT (0x00000000u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R00_SQRT_RESETVAL (0x00000000u)

/* choose to use the orignal value of 'r01' or the square root of the 'r01' as real magnitude:  */
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R01_SQRT_MASK (0x00000002u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R01_SQRT_SHIFT (0x00000001u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R01_SQRT_RESETVAL (0x00000000u)

/* choose to use the orignal value of 'r1' or the square root of the 'r1' as real magnitude:  */
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R1_SQRT_MASK (0x00000004u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R1_SQRT_SHIFT (0x00000002u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R1_SQRT_RESETVAL (0x00000000u)

/* choose to use the orignal value of '2' or the square root of the 'r2' as real magnitude:  */
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R2_SQRT_MASK (0x00000008u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R2_SQRT_SHIFT (0x00000003u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R2_SQRT_RESETVAL (0x00000000u)

/* choose to use the orignal value of 'r31' or the square root of the 'r31' as real magnitude:  */
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R31_SQRT_MASK (0x00000010u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R31_SQRT_SHIFT (0x00000004u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R31_SQRT_RESETVAL (0x00000000u)

/* choose to use the orignal value of 'r32' or the square root of the 'r32' as real magnitude:  */
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R32_SQRT_MASK (0x00000020u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R32_SQRT_SHIFT (0x00000005u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R32_SQRT_RESETVAL (0x00000000u)

/* choose to use the orignal value of 'r33' or the square root of the 'r33' as real magnitude:  */
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R33_SQRT_MASK (0x00000040u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R33_SQRT_SHIFT (0x00000006u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_R33_SQRT_RESETVAL (0x00000000u)

/* choose to use the square magnitude of 'x2' or the magnitude of 'x2' as real magnitude:  */
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_MAGX2_SQRT_MASK (0x00000080u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_MAGX2_SQRT_SHIFT (0x00000007u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_MAGX2_SQRT_RESETVAL (0x00000000u)

/* choose to use the square magnitude of 'x3' or the magnitude 0f 'x3' as real magnitude:  */
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_MAGX3_SQRT_MASK (0x00000100u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_MAGX3_SQRT_SHIFT (0x00000008u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_MUX_MAGX3_SQRT_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_ADDR (0x00000208u)
#define CSL_DFE_DPD_INPUT_MUX_SQRT_REG_RESETVAL (0x00000000u)

/* INPUT_MUX_COMPLX_SIGNAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 mux_b3_o : 2;
    Uint32 mux_b3_e : 2;
    Uint32 mux_b2_o : 2;
    Uint32 mux_b2_e : 2;
    Uint32 mux_b1_o : 2;
    Uint32 mux_b1_e : 2;
    Uint32 mux_b0_o : 2;
    Uint32 mux_b0_e : 2;
#else 
    Uint32 mux_b0_e : 2;
    Uint32 mux_b0_o : 2;
    Uint32 mux_b1_e : 2;
    Uint32 mux_b1_o : 2;
    Uint32 mux_b2_e : 2;
    Uint32 mux_b2_o : 2;
    Uint32 mux_b3_e : 2;
    Uint32 mux_b3_o : 2;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG;

/* choose the complex input for DPD block0 even input port: */
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B0_E_MASK (0x00000003u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B0_E_SHIFT (0x00000000u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B0_E_RESETVAL (0x00000000u)

/* choose the complex input for DPD block0 odd input port: */
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B0_O_MASK (0x0000000Cu)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B0_O_SHIFT (0x00000002u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B0_O_RESETVAL (0x00000000u)

/* choose the complex input for DPD block1 even input port: */
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B1_E_MASK (0x00000030u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B1_E_SHIFT (0x00000004u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B1_E_RESETVAL (0x00000001u)

/* choose the complex input for DPD block1 odd input port: */
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B1_O_MASK (0x000000C0u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B1_O_SHIFT (0x00000006u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B1_O_RESETVAL (0x00000001u)

/* choose the complex input for DPD block2 even input port: */
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B2_E_MASK (0x00000300u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B2_E_SHIFT (0x00000008u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B2_E_RESETVAL (0x00000002u)

/* choose the complex input for DPD block2 odd input port: */
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B2_O_MASK (0x00000C00u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B2_O_SHIFT (0x0000000Au)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B2_O_RESETVAL (0x00000002u)

/* choose the complex input for DPD block3 even input port: */
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B3_E_MASK (0x00003000u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B3_E_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B3_E_RESETVAL (0x00000003u)

/* choose the complex input for DPD block3 odd input port: */
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B3_O_MASK (0x0000C000u)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B3_O_SHIFT (0x0000000Eu)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_MUX_B3_O_RESETVAL (0x00000003u)

#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_ADDR (0x0000020Cu)
#define CSL_DFE_DPD_INPUT_MUX_COMPLX_SIGNAL_REG_RESETVAL (0x0000FA50u)

/* INPUT_MUX_REAL_MAGNITUDE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mux_b3_omag : 4;
    Uint32 mux_b3_emag : 4;
    Uint32 mux_b2_omag : 4;
    Uint32 mux_b2_emag : 4;
    Uint32 mux_b1_omag : 4;
    Uint32 mux_b1_emag : 4;
    Uint32 mux_b0_omag : 4;
    Uint32 mux_b0_emag : 4;
#else 
    Uint32 mux_b0_emag : 4;
    Uint32 mux_b0_omag : 4;
    Uint32 mux_b1_emag : 4;
    Uint32 mux_b1_omag : 4;
    Uint32 mux_b2_emag : 4;
    Uint32 mux_b2_omag : 4;
    Uint32 mux_b3_emag : 4;
    Uint32 mux_b3_omag : 4;
#endif 
} CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG;

/* choose the real magnitude signal for DPD block0 even input port: */
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B0_EMAG_MASK (0x0000000Fu)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B0_EMAG_SHIFT (0x00000000u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B0_EMAG_RESETVAL (0x00000000u)

/* choose the real magnitude signal for DPD block0 odd input port. */
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B0_OMAG_MASK (0x000000F0u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B0_OMAG_SHIFT (0x00000004u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B0_OMAG_RESETVAL (0x00000000u)

/* choose the real magnitude signal for DPD block1 even input port. */
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B1_EMAG_MASK (0x00000F00u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B1_EMAG_SHIFT (0x00000008u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B1_EMAG_RESETVAL (0x00000001u)

/* choose the real magnitude signal for DPD block1 odd input port. */
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B1_OMAG_MASK (0x0000F000u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B1_OMAG_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B1_OMAG_RESETVAL (0x00000001u)

/* choose the real magnitude signal for DPD block2 even input port. */
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B2_EMAG_MASK (0x000F0000u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B2_EMAG_SHIFT (0x00000010u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B2_EMAG_RESETVAL (0x00000007u)

/* choose the real magnitude signal for DPD block2 odd input port. */
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B2_OMAG_MASK (0x00F00000u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B2_OMAG_SHIFT (0x00000014u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B2_OMAG_RESETVAL (0x00000007u)

/* choose the real magnitude signal for DPD block3 even input port. */
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B3_EMAG_MASK (0x0F000000u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B3_EMAG_SHIFT (0x00000018u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B3_EMAG_RESETVAL (0x00000008u)

/* choose the real magnitude signal for DPD block3 odd input port. */
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B3_OMAG_MASK (0xF0000000u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B3_OMAG_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_MUX_B3_OMAG_RESETVAL (0x00000008u)

#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_ADDR (0x00000210u)
#define CSL_DFE_DPD_INPUT_MUX_REAL_MAGNITUDE_REG_RESETVAL (0x88771100u)

/* OUTPUT_MUX_DPD_OUTPUT */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 mux_dpdout3 : 4;
    Uint32 mux_dpdout2 : 4;
    Uint32 mux_dpdout1 : 4;
    Uint32 mux_dpdout0 : 4;
#else 
    Uint32 mux_dpdout0 : 4;
    Uint32 mux_dpdout1 : 4;
    Uint32 mux_dpdout2 : 4;
    Uint32 mux_dpdout3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG;

/* mux to choose output 0 of DPD subchip: */
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT0_MASK (0x0000000Fu)
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT0_RESETVAL (0x00000000u)

/* mux to choose output 1 of DPD subchip */
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT1_MASK (0x000000F0u)
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT1_RESETVAL (0x00000001u)

/* mux to choose output 2 of DPD subchip */
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT2_MASK (0x00000F00u)
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT2_RESETVAL (0x00000002u)

/* mux to choose output 3 of DPD subchip */
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT3_MASK (0x0000F000u)
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_MUX_DPDOUT3_RESETVAL (0x00000003u)

#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_ADDR (0x00000214u)
#define CSL_DFE_DPD_OUTPUT_MUX_DPD_OUTPUT_REG_RESETVAL (0x00003210u)

/* TOP_DPDADAPT_UPDATE_MODE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 20;
    Uint32 mux_csync_dpdadapt_b3 : 1;
    Uint32 mux_csync_dpdadapt_b2 : 1;
    Uint32 mux_csync_dpdadapt_b1 : 1;
    Uint32 mux_csync_dpdadapt_b0 : 1;
    Uint32 mux_fsync_dpdadapt_b3 : 1;
    Uint32 mux_fsync_dpdadapt_b2 : 1;
    Uint32 mux_fsync_dpdadapt_b1 : 1;
    Uint32 mux_fsync_dpdadapt_b0 : 1;
    Uint32 dpdadapt_update_mode_b3 : 1;
    Uint32 dpdadapt_update_mode_b2 : 1;
    Uint32 dpdadapt_update_mode_b1 : 1;
    Uint32 dpdadapt_update_mode_b0 : 1;
#else 
    Uint32 dpdadapt_update_mode_b0 : 1;
    Uint32 dpdadapt_update_mode_b1 : 1;
    Uint32 dpdadapt_update_mode_b2 : 1;
    Uint32 dpdadapt_update_mode_b3 : 1;
    Uint32 mux_fsync_dpdadapt_b0 : 1;
    Uint32 mux_fsync_dpdadapt_b1 : 1;
    Uint32 mux_fsync_dpdadapt_b2 : 1;
    Uint32 mux_fsync_dpdadapt_b3 : 1;
    Uint32 mux_csync_dpdadapt_b0 : 1;
    Uint32 mux_csync_dpdadapt_b1 : 1;
    Uint32 mux_csync_dpdadapt_b2 : 1;
    Uint32 mux_csync_dpdadapt_b3 : 1;
    Uint32 rsvd0 : 20;
#endif 
} CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG;

/* per block control of the write access to the DPD LUT's when mem_mpu_access = 0: */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B0_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B0_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B1_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B1_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B1_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B2_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B2_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B2_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B3_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B3_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_DPDADAPT_UPDATE_MODE_B3_RESETVAL (0x00000000u)

/* When 'DPDadapt_update_mode_b0' is set to '1', 'mux_fsync_DPDadapt_b0' determines whether we route the fsync directly from poly2LUT or the combined sync (i.e. fsync from poly2LUT arms it and fsync from top-level set the time) to each DPD block:  */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B0_MASK (0x00000010u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B0_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B0_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B1_MASK (0x00000020u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B1_SHIFT (0x00000005u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B1_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B2_MASK (0x00000040u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B2_SHIFT (0x00000006u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B2_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B3_MASK (0x00000080u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B3_SHIFT (0x00000007u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_FSYNC_DPDADAPT_B3_RESETVAL (0x00000000u)

/* When 'DPDadapt_update_mode_b0' is set to '1', 'mux_csync_DPDadapt_b0' determines whether we route the csync directly from poly2LUT or the combined sync (i.e. csync from poly2LUT arms it and csync from top-level set the time) to each DPD block:  */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B0_MASK (0x00000100u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B0_SHIFT (0x00000008u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B0_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B1_MASK (0x00000200u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B1_SHIFT (0x00000009u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B1_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B2_MASK (0x00000400u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B2_SHIFT (0x0000000Au)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B2_RESETVAL (0x00000000u)

/* same as above */
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B3_MASK (0x00000800u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B3_SHIFT (0x0000000Bu)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_MUX_CSYNC_DPDADAPT_B3_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_ADDR (0x00000218u)
#define CSL_DFE_DPD_TOP_DPDADAPT_UPDATE_MODE_REG_RESETVAL (0x00000000u)

/* TOP_F_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 c_f_ssel_b3 : 4;
    Uint32 c_f_ssel_b2 : 4;
    Uint32 c_f_ssel_b1 : 4;
    Uint32 c_f_ssel_b0 : 4;
#else 
    Uint32 c_f_ssel_b0 : 4;
    Uint32 c_f_ssel_b1 : 4;
    Uint32 c_f_ssel_b2 : 4;
    Uint32 c_f_ssel_b3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_F_SSEL_REG;

/* Configuration of which of the synchs will be tied to f_synch of dpd block0 */
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B0_MASK (0x0000000Fu)
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B0_RESETVAL (0x00000000u)

/* Configuration of which of the synchs will be tied to f_synch of dpd block1 */
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B1_MASK (0x000000F0u)
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B1_RESETVAL (0x00000000u)

/* Configuration of which of the synchs will be tied to f_synch of dpd block2 */
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B2_MASK (0x00000F00u)
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B2_RESETVAL (0x00000000u)

/* Configuration of which of the synchs will be tied to f_synch of dpd block3 */
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B3_MASK (0x0000F000u)
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_TOP_F_SSEL_REG_C_F_SSEL_B3_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_F_SSEL_REG_ADDR (0x0000021Cu)
#define CSL_DFE_DPD_TOP_F_SSEL_REG_RESETVAL (0x00000000u)

/* TOP_C_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 c_c_ssel_b3 : 4;
    Uint32 c_c_ssel_b2 : 4;
    Uint32 c_c_ssel_b1 : 4;
    Uint32 c_c_ssel_b0 : 4;
#else 
    Uint32 c_c_ssel_b0 : 4;
    Uint32 c_c_ssel_b1 : 4;
    Uint32 c_c_ssel_b2 : 4;
    Uint32 c_c_ssel_b3 : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_C_SSEL_REG;

/* Configuration of which of the synchs will be tied to c_synch of dpd block0 */
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B0_MASK (0x0000000Fu)
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B0_RESETVAL (0x00000000u)

/* Configuration of which of the synchs will be tied to c_synch of dpd block1 */
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B1_MASK (0x000000F0u)
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B1_RESETVAL (0x00000000u)

/* Configuration of which of the synchs will be tied to c_synch of dpd block2 */
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B2_MASK (0x00000F00u)
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B2_RESETVAL (0x00000000u)

/* Configuration of which of the synchs will be tied to c_synch of dpd block3 */
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B3_MASK (0x0000F000u)
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_TOP_C_SSEL_REG_C_C_SSEL_B3_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_C_SSEL_REG_ADDR (0x00000220u)
#define CSL_DFE_DPD_TOP_C_SSEL_REG_RESETVAL (0x00000000u)

/* TOP_DPD_DISABLE */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 dpd_disable_b3 : 1;
    Uint32 dpd_disable_b2 : 1;
    Uint32 dpd_disable_b1 : 1;
    Uint32 dpd_disable_b0 : 1;
#else 
    Uint32 dpd_disable_b0 : 1;
    Uint32 dpd_disable_b1 : 1;
    Uint32 dpd_disable_b2 : 1;
    Uint32 dpd_disable_b3 : 1;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_DPD_TOP_DPD_DISABLE_REG;

/* 0: DPD block0 is enabled. */
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B0_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B0_RESETVAL (0x00000000u)

/* 0: DPD block1 is enabled. */
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B1_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B1_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B1_RESETVAL (0x00000000u)

/* 0: DPD block2 is enabled. */
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B2_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B2_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B2_RESETVAL (0x00000000u)

/* 0: DPD block3 is enabled. */
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B3_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B3_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_DPD_DISABLE_B3_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_ADDR (0x00000224u)
#define CSL_DFE_DPD_TOP_DPD_DISABLE_REG_RESETVAL (0x00000000u)

/* TOP_SYNC_B_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 sync_b_ssel : 4;
#else 
    Uint32 sync_b_ssel : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_DPD_TOP_SYNC_B_SSEL_REG;

/* sync select for 'sync_b'. For additional sync scheme that checks both 'sync_b' and sync from 'poly2LUT' block. Note: this register is no longer in use since we want the 'combined_sync' to be per block, we decided to use per block 'f_sync' and 'c_sync' in the place of 'sync_b'. (not in use any more with new sync scheme) */
#define CSL_DFE_DPD_TOP_SYNC_B_SSEL_REG_SYNC_B_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DPD_TOP_SYNC_B_SSEL_REG_SYNC_B_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SYNC_B_SSEL_REG_SYNC_B_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SYNC_B_SSEL_REG_ADDR (0x00000228u)
#define CSL_DFE_DPD_TOP_SYNC_B_SSEL_REG_RESETVAL (0x00000000u)

/* TOP_INITS */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 25;
    Uint32 clear_data : 1;
    Uint32 init_state : 1;
    Uint32 init_clk_gate : 1;
    Uint32 inits_ssel : 4;
#else 
    Uint32 inits_ssel : 4;
    Uint32 init_clk_gate : 1;
    Uint32 init_state : 1;
    Uint32 clear_data : 1;
    Uint32 rsvd0 : 25;
#endif 
} CSL_DFE_DPD_TOP_INITS_REG;

/* sync select for 'init_state' */
#define CSL_DFE_DPD_TOP_INITS_REG_INITS_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DPD_TOP_INITS_REG_INITS_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_INITS_REG_INITS_SSEL_RESETVAL (0x00000000u)

/* for init_clk_gate */
#define CSL_DFE_DPD_TOP_INITS_REG_INIT_CLK_GATE_MASK (0x00000010u)
#define CSL_DFE_DPD_TOP_INITS_REG_INIT_CLK_GATE_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_INITS_REG_INIT_CLK_GATE_RESETVAL (0x00000001u)

/* for init_state */
#define CSL_DFE_DPD_TOP_INITS_REG_INIT_STATE_MASK (0x00000020u)
#define CSL_DFE_DPD_TOP_INITS_REG_INIT_STATE_SHIFT (0x00000005u)
#define CSL_DFE_DPD_TOP_INITS_REG_INIT_STATE_RESETVAL (0x00000001u)

/* for clear_data */
#define CSL_DFE_DPD_TOP_INITS_REG_CLEAR_DATA_MASK (0x00000040u)
#define CSL_DFE_DPD_TOP_INITS_REG_CLEAR_DATA_SHIFT (0x00000006u)
#define CSL_DFE_DPD_TOP_INITS_REG_CLEAR_DATA_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_TOP_INITS_REG_ADDR (0x0000022Cu)
#define CSL_DFE_DPD_TOP_INITS_REG_RESETVAL (0x00000070u)

/* TOP_GC_CLK_GATE_DELAY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 29;
    Uint32 gc_clk_gate_delay : 3;
#else 
    Uint32 gc_clk_gate_delay : 3;
    Uint32 rsvd0 : 29;
#endif 
} CSL_DFE_DPD_TOP_GC_CLK_GATE_DELAY_REG;

/* can program to delay clk gating signal by 0~7 clock cycles */
#define CSL_DFE_DPD_TOP_GC_CLK_GATE_DELAY_REG_GC_CLK_GATE_DELAY_MASK (0x00000007u)
#define CSL_DFE_DPD_TOP_GC_CLK_GATE_DELAY_REG_GC_CLK_GATE_DELAY_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_GC_CLK_GATE_DELAY_REG_GC_CLK_GATE_DELAY_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_GC_CLK_GATE_DELAY_REG_ADDR (0x00000230u)
#define CSL_DFE_DPD_TOP_GC_CLK_GATE_DELAY_REG_RESETVAL (0x00000000u)

/* TOP_TESTBUS_CONTROL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 testbus_control : 4;
#else 
    Uint32 testbus_control : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_DPD_TOP_TESTBUS_CONTROL_REG;

/* DPD test bus control: */
#define CSL_DFE_DPD_TOP_TESTBUS_CONTROL_REG_TESTBUS_CONTROL_MASK (0x0000000Fu)
#define CSL_DFE_DPD_TOP_TESTBUS_CONTROL_REG_TESTBUS_CONTROL_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_TESTBUS_CONTROL_REG_TESTBUS_CONTROL_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_TESTBUS_CONTROL_REG_ADDR (0x00000234u)
#define CSL_DFE_DPD_TOP_TESTBUS_CONTROL_REG_RESETVAL (0x00000000u)

/* DPD0_MUX_BLK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mux_dgxo_o_b0 : 4;
    Uint32 mux_dgxo_e_b0 : 4;
    Uint32 mux_dgaxo_o_b0 : 4;
    Uint32 mux_dgaxo_e_b0 : 4;
    Uint32 rsvd3 : 2;
    Uint32 mux_dg_o_b0 : 1;
    Uint32 mux_dg_e_b0 : 1;
    Uint32 rsvd2 : 2;
    Uint32 mux_dga_o_b0 : 1;
    Uint32 mux_dga_e_b0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 mux_dg_2x_b0 : 1;
    Uint32 rsvd0 : 3;
    Uint32 mux_2x_b0 : 1;
#else 
    Uint32 mux_2x_b0 : 1;
    Uint32 rsvd0 : 3;
    Uint32 mux_dg_2x_b0 : 1;
    Uint32 rsvd1 : 3;
    Uint32 mux_dga_e_b0 : 1;
    Uint32 mux_dga_o_b0 : 1;
    Uint32 rsvd2 : 2;
    Uint32 mux_dg_e_b0 : 1;
    Uint32 mux_dg_o_b0 : 1;
    Uint32 rsvd3 : 2;
    Uint32 mux_dgaxo_e_b0 : 4;
    Uint32 mux_dgaxo_o_b0 : 4;
    Uint32 mux_dgxo_e_b0 : 4;
    Uint32 mux_dgxo_o_b0 : 4;
#endif 
} CSL_DFE_DPD_DPD0_MUX_BLK0_REG;

/* 0 = Rows within the block configured for only 1 daisy chain  */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_2X_B0_MASK (0x00000001u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_2X_B0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_2X_B0_RESETVAL (0x00000000u)

/* 0 = Delay line within delay generator configured as 1 delay line of 8 registers */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DG_2X_B0_MASK (0x00000010u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DG_2X_B0_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DG_2X_B0_RESETVAL (0x00000000u)

/* 0 = takes the absolute value data stream from the dgaxo even output of another gc_delay_generator for the even input.  */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGA_E_B0_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGA_E_B0_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGA_E_B0_RESETVAL (0x00000000u)

/* 0 = takes the absolute value data stream from the dgaxo odd output of another gc_delay_generator for the odd input.  */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGA_O_B0_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGA_O_B0_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGA_O_B0_RESETVAL (0x00000000u)

/* 0 = takes the complex data stream from the dgxo even output of another gc_delay_generator for the even input */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DG_E_B0_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DG_E_B0_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DG_E_B0_RESETVAL (0x00000000u)

/* 0 = takes the complex data stream from the dgxo odd outputt of another gc_delay_generator for the odd input */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DG_O_B0_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DG_O_B0_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DG_O_B0_RESETVAL (0x00000000u)

/* [3] If 1?b0, dgaxo_o is nulled */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGAXO_E_B0_MASK (0x000F0000u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGAXO_E_B0_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGAXO_E_B0_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b0', except for it is for dgaxo odd stream. */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGAXO_O_B0_MASK (0x00F00000u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGAXO_O_B0_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGAXO_O_B0_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b0', except for it is for dgxo even stream. */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGXO_E_B0_MASK (0x0F000000u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGXO_E_B0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGXO_E_B0_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b0', except for it is for dgxo odd stream. */
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGXO_O_B0_MASK (0xF0000000u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGXO_O_B0_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_MUX_DGXO_O_B0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_ADDR (0x00000400u)
#define CSL_DFE_DPD_DPD0_MUX_BLK0_REG_RESETVAL (0x00000000u)

/* DPD0_CURRENT_LUT_MPU_BLK0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd5 : 9;
    Uint32 current_lut_mpu_b0_r5 : 3;
    Uint32 rsvd4 : 1;
    Uint32 current_lut_mpu_b0_r4 : 3;
    Uint32 rsvd3 : 1;
    Uint32 current_lut_mpu_b0_r3 : 3;
    Uint32 rsvd2 : 1;
    Uint32 current_lut_mpu_b0_r2 : 3;
    Uint32 rsvd1 : 1;
    Uint32 current_lut_mpu_b0_r1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 current_lut_mpu_b0_r0 : 3;
#else 
    Uint32 current_lut_mpu_b0_r0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 current_lut_mpu_b0_r1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 current_lut_mpu_b0_r2 : 3;
    Uint32 rsvd2 : 1;
    Uint32 current_lut_mpu_b0_r3 : 3;
    Uint32 rsvd3 : 1;
    Uint32 current_lut_mpu_b0_r4 : 3;
    Uint32 rsvd4 : 1;
    Uint32 current_lut_mpu_b0_r5 : 3;
    Uint32 rsvd5 : 9;
#endif 
} CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG;

/* DPD block 0, row 0, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R0_MASK (0x00000007u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R0_RESETVAL (0x00000000u)

/* DPD block 0, row 1, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R1_MASK (0x00000070u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R1_RESETVAL (0x00000000u)

/* DPD block 0, row 2, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R2_MASK (0x00000700u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R2_RESETVAL (0x00000000u)

/* DPD block 0, row 3, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R3_MASK (0x00007000u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R3_RESETVAL (0x00000000u)

/* DPD block 0, row 4, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R4_MASK (0x00070000u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R4_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R4_RESETVAL (0x00000000u)

/* DPD block 0, row 5, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R5_MASK (0x00700000u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R5_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_CURRENT_LUT_MPU_B0_R5_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_ADDR (0x00000404u)
#define CSL_DFE_DPD_DPD0_CURRENT_LUT_MPU_BLK0_REG_RESETVAL (0x00000000u)

/* DPD0_ROW_CELL_CONFIG_BLK0_ROW0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b0_r0_c2 : 2;
    Uint32 synch_cell_b0_r0_c1 : 2;
    Uint32 synch_cell_b0_r0_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b0_r0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b0_r0 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b0_r0 : 1;
    Uint32 mux_daxi_b0_r0 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b0_r0 : 1;
    Uint32 mux_real_b0_r0 : 1;
    Uint32 mux_dgxi_b0_r0 : 4;
    Uint32 mux_dgaxi_b0_r0 : 4;
#else 
    Uint32 mux_dgaxi_b0_r0 : 4;
    Uint32 mux_dgxi_b0_r0 : 4;
    Uint32 mux_real_b0_r0 : 1;
    Uint32 mux_complex_b0_r0 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b0_r0 : 1;
    Uint32 mux_dxi_b0_r0 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b0_r0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b0_r0 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b0_r0_c0 : 2;
    Uint32 synch_cell_b0_r0_c1 : 2;
    Uint32 synch_cell_b0_r0_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG;

/* [3]: If 1?b0, dgaxi_row0 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DGAXI_B0_R0_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DGAXI_B0_R0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DGAXI_B0_R0_RESETVAL (0x00000000u)

/* [3]: If 1?b0, dgxi_row0 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DGXI_B0_R0_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DGXI_B0_R0_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DGXI_B0_R0_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_REAL_B0_R0_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_REAL_B0_R0_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_REAL_B0_R0_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_COMPLEX_B0_R0_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_COMPLEX_B0_R0_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_COMPLEX_B0_R0_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DAXI_B0_R0_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DAXI_B0_R0_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DAXI_B0_R0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DXI_B0_R0_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DXI_B0_R0_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_MUX_DXI_B0_R0_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_LUT_INIT_B0_R0_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_LUT_INIT_B0_R0_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_LUT_INIT_B0_R0_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_LUT_TOGGLE_B0_R0_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_LUT_TOGGLE_B0_R0_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_LUT_TOGGLE_B0_R0_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_SYNCH_CELL_B0_R0_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_SYNCH_CELL_B0_R0_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_SYNCH_CELL_B0_R0_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_SYNCH_CELL_B0_R0_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_SYNCH_CELL_B0_R0_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_SYNCH_CELL_B0_R0_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_SYNCH_CELL_B0_R0_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_SYNCH_CELL_B0_R0_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_SYNCH_CELL_B0_R0_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_ADDR (0x00000408u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW0_REG_RESETVAL (0x15000000u)

/* DPD0_ROW_CELL_CONFIG_BLK0_ROW1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b0_r1_c2 : 2;
    Uint32 synch_cell_b0_r1_c1 : 2;
    Uint32 synch_cell_b0_r1_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b0_r1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b0_r1 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b0_r1 : 1;
    Uint32 mux_daxi_b0_r1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b0_r1 : 1;
    Uint32 mux_real_b0_r1 : 1;
    Uint32 mux_dgxi_b0_r1 : 4;
    Uint32 mux_dgaxi_b0_r1 : 4;
#else 
    Uint32 mux_dgaxi_b0_r1 : 4;
    Uint32 mux_dgxi_b0_r1 : 4;
    Uint32 mux_real_b0_r1 : 1;
    Uint32 mux_complex_b0_r1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b0_r1 : 1;
    Uint32 mux_dxi_b0_r1 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b0_r1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b0_r1 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b0_r1_c0 : 2;
    Uint32 synch_cell_b0_r1_c1 : 2;
    Uint32 synch_cell_b0_r1_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG;

/* [3]: If 1?b0, dgaxi_row1 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DGAXI_B0_R1_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DGAXI_B0_R1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DGAXI_B0_R1_RESETVAL (0x00000000u)

/* [3]: If 1?b0, dgxi_row1 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DGXI_B0_R1_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DGXI_B0_R1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DGXI_B0_R1_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_REAL_B0_R1_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_REAL_B0_R1_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_REAL_B0_R1_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_COMPLEX_B0_R1_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_COMPLEX_B0_R1_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_COMPLEX_B0_R1_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DAXI_B0_R1_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DAXI_B0_R1_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DAXI_B0_R1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DXI_B0_R1_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DXI_B0_R1_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_MUX_DXI_B0_R1_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_LUT_INIT_B0_R1_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_LUT_INIT_B0_R1_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_LUT_INIT_B0_R1_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_LUT_TOGGLE_B0_R1_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_LUT_TOGGLE_B0_R1_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_LUT_TOGGLE_B0_R1_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_SYNCH_CELL_B0_R1_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_SYNCH_CELL_B0_R1_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_SYNCH_CELL_B0_R1_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_SYNCH_CELL_B0_R1_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_SYNCH_CELL_B0_R1_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_SYNCH_CELL_B0_R1_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_SYNCH_CELL_B0_R1_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_SYNCH_CELL_B0_R1_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_SYNCH_CELL_B0_R1_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_ADDR (0x0000040Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW1_REG_RESETVAL (0x15000000u)

/* DPD0_ROW_CELL_CONFIG_BLK0_ROW2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b0_r2_c2 : 2;
    Uint32 synch_cell_b0_r2_c1 : 2;
    Uint32 synch_cell_b0_r2_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b0_r2 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b0_r2 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b0_r2 : 1;
    Uint32 mux_daxi_b0_r2 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b0_r2 : 1;
    Uint32 mux_real_b0_r2 : 1;
    Uint32 mux_dgxi_b0_r2 : 4;
    Uint32 mux_dgaxi_b0_r2 : 4;
#else 
    Uint32 mux_dgaxi_b0_r2 : 4;
    Uint32 mux_dgxi_b0_r2 : 4;
    Uint32 mux_real_b0_r2 : 1;
    Uint32 mux_complex_b0_r2 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b0_r2 : 1;
    Uint32 mux_dxi_b0_r2 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b0_r2 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b0_r2 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b0_r2_c0 : 2;
    Uint32 synch_cell_b0_r2_c1 : 2;
    Uint32 synch_cell_b0_r2_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG;

/* [3]: If 1?b0, dgaxi_row2 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DGAXI_B0_R2_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DGAXI_B0_R2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DGAXI_B0_R2_RESETVAL (0x00000000u)

/* [3]: If 1?b0, dgxi_row2 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DGXI_B0_R2_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DGXI_B0_R2_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DGXI_B0_R2_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_REAL_B0_R2_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_REAL_B0_R2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_REAL_B0_R2_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_COMPLEX_B0_R2_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_COMPLEX_B0_R2_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_COMPLEX_B0_R2_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DAXI_B0_R2_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DAXI_B0_R2_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DAXI_B0_R2_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DXI_B0_R2_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DXI_B0_R2_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_MUX_DXI_B0_R2_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_LUT_INIT_B0_R2_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_LUT_INIT_B0_R2_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_LUT_INIT_B0_R2_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_LUT_TOGGLE_B0_R2_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_LUT_TOGGLE_B0_R2_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_LUT_TOGGLE_B0_R2_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_SYNCH_CELL_B0_R2_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_SYNCH_CELL_B0_R2_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_SYNCH_CELL_B0_R2_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_SYNCH_CELL_B0_R2_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_SYNCH_CELL_B0_R2_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_SYNCH_CELL_B0_R2_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_SYNCH_CELL_B0_R2_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_SYNCH_CELL_B0_R2_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_SYNCH_CELL_B0_R2_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_ADDR (0x00000410u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW2_REG_RESETVAL (0x15000000u)

/* DPD0_ROW_CELL_CONFIG_BLK0_ROW3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b0_r3_c2 : 2;
    Uint32 synch_cell_b0_r3_c1 : 2;
    Uint32 synch_cell_b0_r3_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b0_r3 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b0_r3 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b0_r3 : 1;
    Uint32 mux_daxi_b0_r3 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b0_r3 : 1;
    Uint32 mux_real_b0_r3 : 1;
    Uint32 mux_dgxi_b0_r3 : 4;
    Uint32 mux_dgaxi_b0_r3 : 4;
#else 
    Uint32 mux_dgaxi_b0_r3 : 4;
    Uint32 mux_dgxi_b0_r3 : 4;
    Uint32 mux_real_b0_r3 : 1;
    Uint32 mux_complex_b0_r3 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b0_r3 : 1;
    Uint32 mux_dxi_b0_r3 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b0_r3 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b0_r3 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b0_r3_c0 : 2;
    Uint32 synch_cell_b0_r3_c1 : 2;
    Uint32 synch_cell_b0_r3_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG;

/* [3]: If 1?b0, dgaxi_row3 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DGAXI_B0_R3_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DGAXI_B0_R3_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DGAXI_B0_R3_RESETVAL (0x00000000u)

/* [3]: If 1?b0, dgxi_row3 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DGXI_B0_R3_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DGXI_B0_R3_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DGXI_B0_R3_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_REAL_B0_R3_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_REAL_B0_R3_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_REAL_B0_R3_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_COMPLEX_B0_R3_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_COMPLEX_B0_R3_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_COMPLEX_B0_R3_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DAXI_B0_R3_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DAXI_B0_R3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DAXI_B0_R3_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DXI_B0_R3_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DXI_B0_R3_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_MUX_DXI_B0_R3_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_LUT_INIT_B0_R3_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_LUT_INIT_B0_R3_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_LUT_INIT_B0_R3_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_LUT_TOGGLE_B0_R3_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_LUT_TOGGLE_B0_R3_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_LUT_TOGGLE_B0_R3_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_SYNCH_CELL_B0_R3_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_SYNCH_CELL_B0_R3_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_SYNCH_CELL_B0_R3_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_SYNCH_CELL_B0_R3_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_SYNCH_CELL_B0_R3_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_SYNCH_CELL_B0_R3_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_SYNCH_CELL_B0_R3_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_SYNCH_CELL_B0_R3_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_SYNCH_CELL_B0_R3_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_ADDR (0x00000414u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW3_REG_RESETVAL (0x15000000u)

/* DPD0_ROW_CELL_CONFIG_BLK0_ROW4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b0_r4_c2 : 2;
    Uint32 synch_cell_b0_r4_c1 : 2;
    Uint32 synch_cell_b0_r4_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b0_r4 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b0_r4 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b0_r4 : 1;
    Uint32 mux_daxi_b0_r4 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b0_r4 : 1;
    Uint32 mux_real_b0_r4 : 1;
    Uint32 mux_dgxi_b0_r4 : 4;
    Uint32 mux_dgaxi_b0_r4 : 4;
#else 
    Uint32 mux_dgaxi_b0_r4 : 4;
    Uint32 mux_dgxi_b0_r4 : 4;
    Uint32 mux_real_b0_r4 : 1;
    Uint32 mux_complex_b0_r4 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b0_r4 : 1;
    Uint32 mux_dxi_b0_r4 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b0_r4 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b0_r4 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b0_r4_c0 : 2;
    Uint32 synch_cell_b0_r4_c1 : 2;
    Uint32 synch_cell_b0_r4_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG;

/* [3]: If 1?b0, dgaxi_row4 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DGAXI_B0_R4_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DGAXI_B0_R4_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DGAXI_B0_R4_RESETVAL (0x00000000u)

/* [3]: If 1?b0, dgxi_row4 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DGXI_B0_R4_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DGXI_B0_R4_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DGXI_B0_R4_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_REAL_B0_R4_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_REAL_B0_R4_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_REAL_B0_R4_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_COMPLEX_B0_R4_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_COMPLEX_B0_R4_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_COMPLEX_B0_R4_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DAXI_B0_R4_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DAXI_B0_R4_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DAXI_B0_R4_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DXI_B0_R4_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DXI_B0_R4_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_MUX_DXI_B0_R4_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_LUT_INIT_B0_R4_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_LUT_INIT_B0_R4_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_LUT_INIT_B0_R4_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_LUT_TOGGLE_B0_R4_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_LUT_TOGGLE_B0_R4_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_LUT_TOGGLE_B0_R4_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_SYNCH_CELL_B0_R4_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_SYNCH_CELL_B0_R4_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_SYNCH_CELL_B0_R4_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_SYNCH_CELL_B0_R4_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_SYNCH_CELL_B0_R4_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_SYNCH_CELL_B0_R4_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_SYNCH_CELL_B0_R4_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_SYNCH_CELL_B0_R4_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_SYNCH_CELL_B0_R4_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_ADDR (0x00000418u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW4_REG_RESETVAL (0x15000000u)

/* DPD0_ROW_CELL_CONFIG_BLK0_ROW5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b0_r5_c2 : 2;
    Uint32 synch_cell_b0_r5_c1 : 2;
    Uint32 synch_cell_b0_r5_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b0_r5 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b0_r5 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b0_r5 : 1;
    Uint32 mux_daxi_b0_r5 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b0_r5 : 1;
    Uint32 mux_real_b0_r5 : 1;
    Uint32 mux_dgxi_b0_r5 : 4;
    Uint32 mux_dgaxi_b0_r5 : 4;
#else 
    Uint32 mux_dgaxi_b0_r5 : 4;
    Uint32 mux_dgxi_b0_r5 : 4;
    Uint32 mux_real_b0_r5 : 1;
    Uint32 mux_complex_b0_r5 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b0_r5 : 1;
    Uint32 mux_dxi_b0_r5 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b0_r5 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b0_r5 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b0_r5_c0 : 2;
    Uint32 synch_cell_b0_r5_c1 : 2;
    Uint32 synch_cell_b0_r5_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG;

/* [3]: If 1?b0, dgaxi_row5 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DGAXI_B0_R5_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DGAXI_B0_R5_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DGAXI_B0_R5_RESETVAL (0x00000000u)

/* [3]: If 1?b0, dgxi_row5 output is nulled */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DGXI_B0_R5_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DGXI_B0_R5_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DGXI_B0_R5_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_REAL_B0_R5_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_REAL_B0_R5_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_REAL_B0_R5_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_COMPLEX_B0_R5_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_COMPLEX_B0_R5_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_COMPLEX_B0_R5_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DAXI_B0_R5_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DAXI_B0_R5_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DAXI_B0_R5_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DXI_B0_R5_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DXI_B0_R5_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_MUX_DXI_B0_R5_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_LUT_INIT_B0_R5_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_LUT_INIT_B0_R5_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_LUT_INIT_B0_R5_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_LUT_TOGGLE_B0_R5_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_LUT_TOGGLE_B0_R5_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_LUT_TOGGLE_B0_R5_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_SYNCH_CELL_B0_R5_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_SYNCH_CELL_B0_R5_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_SYNCH_CELL_B0_R5_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_SYNCH_CELL_B0_R5_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_SYNCH_CELL_B0_R5_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_SYNCH_CELL_B0_R5_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_SYNCH_CELL_B0_R5_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_SYNCH_CELL_B0_R5_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_SYNCH_CELL_B0_R5_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_ADDR (0x0000041Cu)
#define CSL_DFE_DPD_DPD0_ROW_CELL_CONFIG_BLK0_ROW5_REG_RESETVAL (0x15000000u)

/* DPD1_MUX_BLK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mux_dgxo_o_b1 : 4;
    Uint32 mux_dgxo_e_b1 : 4;
    Uint32 mux_dgaxo_o_b1 : 4;
    Uint32 mux_dgaxo_e_b1 : 4;
    Uint32 rsvd3 : 2;
    Uint32 mux_dg_o_b1 : 1;
    Uint32 mux_dg_e_b1 : 1;
    Uint32 rsvd2 : 2;
    Uint32 mux_dga_o_b1 : 1;
    Uint32 mux_dga_e_b1 : 1;
    Uint32 rsvd1 : 3;
    Uint32 mux_dg_2x_b1 : 1;
    Uint32 rsvd0 : 3;
    Uint32 mux_2x_b1 : 1;
#else 
    Uint32 mux_2x_b1 : 1;
    Uint32 rsvd0 : 3;
    Uint32 mux_dg_2x_b1 : 1;
    Uint32 rsvd1 : 3;
    Uint32 mux_dga_e_b1 : 1;
    Uint32 mux_dga_o_b1 : 1;
    Uint32 rsvd2 : 2;
    Uint32 mux_dg_e_b1 : 1;
    Uint32 mux_dg_o_b1 : 1;
    Uint32 rsvd3 : 2;
    Uint32 mux_dgaxo_e_b1 : 4;
    Uint32 mux_dgaxo_o_b1 : 4;
    Uint32 mux_dgxo_e_b1 : 4;
    Uint32 mux_dgxo_o_b1 : 4;
#endif 
} CSL_DFE_DPD_DPD1_MUX_BLK1_REG;

/* 0 = Rows within the block configured for only 1 daisy chain  */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_2X_B1_MASK (0x00000001u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_2X_B1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_2X_B1_RESETVAL (0x00000000u)

/* 0 = Delay line within delay generator configured as 1 delay line of 8 registers */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DG_2X_B1_MASK (0x00000010u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DG_2X_B1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DG_2X_B1_RESETVAL (0x00000000u)

/* 0 = takes the absolute value data stream from the dgaxo even output of another gc_delay_generator for the even input.  */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGA_E_B1_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGA_E_B1_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGA_E_B1_RESETVAL (0x00000000u)

/* 0 = takes the absolute value data stream from the dgaxo odd output of another gc_delay_generator for the odd input.  */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGA_O_B1_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGA_O_B1_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGA_O_B1_RESETVAL (0x00000000u)

/* 0 = takes the complex data stream from the dgxo even output of another gc_delay_generator for the even input */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DG_E_B1_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DG_E_B1_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DG_E_B1_RESETVAL (0x00000000u)

/* 0 = takes the complex data stream from the dgxo odd outputt of another gc_delay_generator for the odd input */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DG_O_B1_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DG_O_B1_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DG_O_B1_RESETVAL (0x00000000u)

/* [3] If 1?b0, dgaxo_o is nulled */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGAXO_E_B1_MASK (0x000F0000u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGAXO_E_B1_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGAXO_E_B1_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b1', except for it is for dgaxo odd stream. */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGAXO_O_B1_MASK (0x00F00000u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGAXO_O_B1_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGAXO_O_B1_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b1', except for it is for dgxo even stream. */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGXO_E_B1_MASK (0x0F000000u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGXO_E_B1_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGXO_E_B1_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b1', except for it is for dgxo odd stream. */
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGXO_O_B1_MASK (0xF0000000u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGXO_O_B1_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_MUX_DGXO_O_B1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_ADDR (0x00000420u)
#define CSL_DFE_DPD_DPD1_MUX_BLK1_REG_RESETVAL (0x00000000u)

/* DPD1_CURRENT_LUT_MPU_BLK1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd5 : 9;
    Uint32 current_lut_mpu_b1_r5 : 3;
    Uint32 rsvd4 : 1;
    Uint32 current_lut_mpu_b1_r4 : 3;
    Uint32 rsvd3 : 1;
    Uint32 current_lut_mpu_b1_r3 : 3;
    Uint32 rsvd2 : 1;
    Uint32 current_lut_mpu_b1_r2 : 3;
    Uint32 rsvd1 : 1;
    Uint32 current_lut_mpu_b1_r1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 current_lut_mpu_b1_r0 : 3;
#else 
    Uint32 current_lut_mpu_b1_r0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 current_lut_mpu_b1_r1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 current_lut_mpu_b1_r2 : 3;
    Uint32 rsvd2 : 1;
    Uint32 current_lut_mpu_b1_r3 : 3;
    Uint32 rsvd3 : 1;
    Uint32 current_lut_mpu_b1_r4 : 3;
    Uint32 rsvd4 : 1;
    Uint32 current_lut_mpu_b1_r5 : 3;
    Uint32 rsvd5 : 9;
#endif 
} CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG;

/* DPD block 0, row 0, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R0_MASK (0x00000007u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R0_RESETVAL (0x00000000u)

/* DPD block 0, row 1, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R1_MASK (0x00000070u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R1_RESETVAL (0x00000000u)

/* DPD block 0, row 2, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R2_MASK (0x00000700u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R2_RESETVAL (0x00000000u)

/* DPD block 0, row 3, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R3_MASK (0x00007000u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R3_RESETVAL (0x00000000u)

/* DPD block 0, row 4, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R4_MASK (0x00070000u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R4_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R4_RESETVAL (0x00000000u)

/* DPD block 0, row 5, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R5_MASK (0x00700000u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R5_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_CURRENT_LUT_MPU_B1_R5_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_ADDR (0x00000424u)
#define CSL_DFE_DPD_DPD1_CURRENT_LUT_MPU_BLK1_REG_RESETVAL (0x00000000u)

/* DPD1_ROW_CELL_CONFIG_BLK1_ROW0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b1_r0_c2 : 2;
    Uint32 synch_cell_b1_r0_c1 : 2;
    Uint32 synch_cell_b1_r0_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b1_r0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b1_r0 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b1_r0 : 1;
    Uint32 mux_daxi_b1_r0 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b1_r0 : 1;
    Uint32 mux_real_b1_r0 : 1;
    Uint32 mux_dgxi_b1_r0 : 4;
    Uint32 mux_dgaxi_b1_r0 : 4;
#else 
    Uint32 mux_dgaxi_b1_r0 : 4;
    Uint32 mux_dgxi_b1_r0 : 4;
    Uint32 mux_real_b1_r0 : 1;
    Uint32 mux_complex_b1_r0 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b1_r0 : 1;
    Uint32 mux_dxi_b1_r0 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b1_r0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b1_r0 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b1_r0_c0 : 2;
    Uint32 synch_cell_b1_r0_c1 : 2;
    Uint32 synch_cell_b1_r0_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG;

/* [3]: If 1?b0, dgaxi_row0 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DGAXI_B1_R0_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DGAXI_B1_R0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DGAXI_B1_R0_RESETVAL (0x00000000u)

/* [3]: If 1?b1, dgxi_row0 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DGXI_B1_R0_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DGXI_B1_R0_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DGXI_B1_R0_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_REAL_B1_R0_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_REAL_B1_R0_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_REAL_B1_R0_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_COMPLEX_B1_R0_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_COMPLEX_B1_R0_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_COMPLEX_B1_R0_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DAXI_B1_R0_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DAXI_B1_R0_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DAXI_B1_R0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DXI_B1_R0_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DXI_B1_R0_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_MUX_DXI_B1_R0_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_LUT_INIT_B1_R0_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_LUT_INIT_B1_R0_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_LUT_INIT_B1_R0_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_LUT_TOGGLE_B1_R0_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_LUT_TOGGLE_B1_R0_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_LUT_TOGGLE_B1_R0_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_SYNCH_CELL_B1_R0_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_SYNCH_CELL_B1_R0_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_SYNCH_CELL_B1_R0_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_SYNCH_CELL_B1_R0_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_SYNCH_CELL_B1_R0_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_SYNCH_CELL_B1_R0_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_SYNCH_CELL_B1_R0_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_SYNCH_CELL_B1_R0_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_SYNCH_CELL_B1_R0_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_ADDR (0x00000428u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW0_REG_RESETVAL (0x15000000u)

/* DPD1_ROW_CELL_CONFIG_BLK1_ROW1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b1_r1_c2 : 2;
    Uint32 synch_cell_b1_r1_c1 : 2;
    Uint32 synch_cell_b1_r1_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b1_r1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b1_r1 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b1_r1 : 1;
    Uint32 mux_daxi_b1_r1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b1_r1 : 1;
    Uint32 mux_real_b1_r1 : 1;
    Uint32 mux_dgxi_b1_r1 : 4;
    Uint32 mux_dgaxi_b1_r1 : 4;
#else 
    Uint32 mux_dgaxi_b1_r1 : 4;
    Uint32 mux_dgxi_b1_r1 : 4;
    Uint32 mux_real_b1_r1 : 1;
    Uint32 mux_complex_b1_r1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b1_r1 : 1;
    Uint32 mux_dxi_b1_r1 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b1_r1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b1_r1 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b1_r1_c0 : 2;
    Uint32 synch_cell_b1_r1_c1 : 2;
    Uint32 synch_cell_b1_r1_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG;

/* [3]: If 1?b0, dgaxi_row1 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DGAXI_B1_R1_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DGAXI_B1_R1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DGAXI_B1_R1_RESETVAL (0x00000000u)

/* [3]: If 1?b1, dgxi_row1 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DGXI_B1_R1_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DGXI_B1_R1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DGXI_B1_R1_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_REAL_B1_R1_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_REAL_B1_R1_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_REAL_B1_R1_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_COMPLEX_B1_R1_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_COMPLEX_B1_R1_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_COMPLEX_B1_R1_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DAXI_B1_R1_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DAXI_B1_R1_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DAXI_B1_R1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DXI_B1_R1_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DXI_B1_R1_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_MUX_DXI_B1_R1_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_LUT_INIT_B1_R1_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_LUT_INIT_B1_R1_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_LUT_INIT_B1_R1_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_LUT_TOGGLE_B1_R1_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_LUT_TOGGLE_B1_R1_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_LUT_TOGGLE_B1_R1_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_SYNCH_CELL_B1_R1_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_SYNCH_CELL_B1_R1_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_SYNCH_CELL_B1_R1_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_SYNCH_CELL_B1_R1_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_SYNCH_CELL_B1_R1_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_SYNCH_CELL_B1_R1_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_SYNCH_CELL_B1_R1_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_SYNCH_CELL_B1_R1_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_SYNCH_CELL_B1_R1_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_ADDR (0x0000042Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW1_REG_RESETVAL (0x15000000u)

/* DPD1_ROW_CELL_CONFIG_BLK1_ROW2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b1_r2_c2 : 2;
    Uint32 synch_cell_b1_r2_c1 : 2;
    Uint32 synch_cell_b1_r2_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b1_r2 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b1_r2 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b1_r2 : 1;
    Uint32 mux_daxi_b1_r2 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b1_r2 : 1;
    Uint32 mux_real_b1_r2 : 1;
    Uint32 mux_dgxi_b1_r2 : 4;
    Uint32 mux_dgaxi_b1_r2 : 4;
#else 
    Uint32 mux_dgaxi_b1_r2 : 4;
    Uint32 mux_dgxi_b1_r2 : 4;
    Uint32 mux_real_b1_r2 : 1;
    Uint32 mux_complex_b1_r2 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b1_r2 : 1;
    Uint32 mux_dxi_b1_r2 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b1_r2 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b1_r2 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b1_r2_c0 : 2;
    Uint32 synch_cell_b1_r2_c1 : 2;
    Uint32 synch_cell_b1_r2_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG;

/* [3]: If 1?b0, dgaxi_row2 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DGAXI_B1_R2_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DGAXI_B1_R2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DGAXI_B1_R2_RESETVAL (0x00000000u)

/* [3]: If 1?b1, dgxi_row2 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DGXI_B1_R2_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DGXI_B1_R2_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DGXI_B1_R2_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_REAL_B1_R2_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_REAL_B1_R2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_REAL_B1_R2_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_COMPLEX_B1_R2_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_COMPLEX_B1_R2_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_COMPLEX_B1_R2_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DAXI_B1_R2_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DAXI_B1_R2_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DAXI_B1_R2_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DXI_B1_R2_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DXI_B1_R2_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_MUX_DXI_B1_R2_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_LUT_INIT_B1_R2_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_LUT_INIT_B1_R2_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_LUT_INIT_B1_R2_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_LUT_TOGGLE_B1_R2_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_LUT_TOGGLE_B1_R2_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_LUT_TOGGLE_B1_R2_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_SYNCH_CELL_B1_R2_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_SYNCH_CELL_B1_R2_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_SYNCH_CELL_B1_R2_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_SYNCH_CELL_B1_R2_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_SYNCH_CELL_B1_R2_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_SYNCH_CELL_B1_R2_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_SYNCH_CELL_B1_R2_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_SYNCH_CELL_B1_R2_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_SYNCH_CELL_B1_R2_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_ADDR (0x00000430u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW2_REG_RESETVAL (0x15000000u)

/* DPD1_ROW_CELL_CONFIG_BLK1_ROW3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b1_r3_c2 : 2;
    Uint32 synch_cell_b1_r3_c1 : 2;
    Uint32 synch_cell_b1_r3_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b1_r3 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b1_r3 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b1_r3 : 1;
    Uint32 mux_daxi_b1_r3 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b1_r3 : 1;
    Uint32 mux_real_b1_r3 : 1;
    Uint32 mux_dgxi_b1_r3 : 4;
    Uint32 mux_dgaxi_b1_r3 : 4;
#else 
    Uint32 mux_dgaxi_b1_r3 : 4;
    Uint32 mux_dgxi_b1_r3 : 4;
    Uint32 mux_real_b1_r3 : 1;
    Uint32 mux_complex_b1_r3 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b1_r3 : 1;
    Uint32 mux_dxi_b1_r3 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b1_r3 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b1_r3 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b1_r3_c0 : 2;
    Uint32 synch_cell_b1_r3_c1 : 2;
    Uint32 synch_cell_b1_r3_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG;

/* [3]: If 1?b0, dgaxi_row3 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DGAXI_B1_R3_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DGAXI_B1_R3_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DGAXI_B1_R3_RESETVAL (0x00000000u)

/* [3]: If 1?b1, dgxi_row3 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DGXI_B1_R3_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DGXI_B1_R3_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DGXI_B1_R3_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_REAL_B1_R3_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_REAL_B1_R3_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_REAL_B1_R3_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_COMPLEX_B1_R3_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_COMPLEX_B1_R3_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_COMPLEX_B1_R3_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DAXI_B1_R3_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DAXI_B1_R3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DAXI_B1_R3_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DXI_B1_R3_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DXI_B1_R3_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_MUX_DXI_B1_R3_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_LUT_INIT_B1_R3_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_LUT_INIT_B1_R3_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_LUT_INIT_B1_R3_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_LUT_TOGGLE_B1_R3_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_LUT_TOGGLE_B1_R3_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_LUT_TOGGLE_B1_R3_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_SYNCH_CELL_B1_R3_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_SYNCH_CELL_B1_R3_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_SYNCH_CELL_B1_R3_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_SYNCH_CELL_B1_R3_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_SYNCH_CELL_B1_R3_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_SYNCH_CELL_B1_R3_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_SYNCH_CELL_B1_R3_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_SYNCH_CELL_B1_R3_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_SYNCH_CELL_B1_R3_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_ADDR (0x00000434u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW3_REG_RESETVAL (0x15000000u)

/* DPD1_ROW_CELL_CONFIG_BLK1_ROW4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b1_r4_c2 : 2;
    Uint32 synch_cell_b1_r4_c1 : 2;
    Uint32 synch_cell_b1_r4_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b1_r4 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b1_r4 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b1_r4 : 1;
    Uint32 mux_daxi_b1_r4 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b1_r4 : 1;
    Uint32 mux_real_b1_r4 : 1;
    Uint32 mux_dgxi_b1_r4 : 4;
    Uint32 mux_dgaxi_b1_r4 : 4;
#else 
    Uint32 mux_dgaxi_b1_r4 : 4;
    Uint32 mux_dgxi_b1_r4 : 4;
    Uint32 mux_real_b1_r4 : 1;
    Uint32 mux_complex_b1_r4 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b1_r4 : 1;
    Uint32 mux_dxi_b1_r4 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b1_r4 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b1_r4 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b1_r4_c0 : 2;
    Uint32 synch_cell_b1_r4_c1 : 2;
    Uint32 synch_cell_b1_r4_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG;

/* [3]: If 1?b0, dgaxi_row4 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DGAXI_B1_R4_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DGAXI_B1_R4_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DGAXI_B1_R4_RESETVAL (0x00000000u)

/* [3]: If 1?b1, dgxi_row4 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DGXI_B1_R4_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DGXI_B1_R4_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DGXI_B1_R4_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_REAL_B1_R4_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_REAL_B1_R4_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_REAL_B1_R4_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_COMPLEX_B1_R4_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_COMPLEX_B1_R4_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_COMPLEX_B1_R4_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DAXI_B1_R4_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DAXI_B1_R4_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DAXI_B1_R4_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DXI_B1_R4_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DXI_B1_R4_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_MUX_DXI_B1_R4_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_LUT_INIT_B1_R4_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_LUT_INIT_B1_R4_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_LUT_INIT_B1_R4_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_LUT_TOGGLE_B1_R4_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_LUT_TOGGLE_B1_R4_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_LUT_TOGGLE_B1_R4_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_SYNCH_CELL_B1_R4_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_SYNCH_CELL_B1_R4_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_SYNCH_CELL_B1_R4_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_SYNCH_CELL_B1_R4_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_SYNCH_CELL_B1_R4_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_SYNCH_CELL_B1_R4_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_SYNCH_CELL_B1_R4_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_SYNCH_CELL_B1_R4_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_SYNCH_CELL_B1_R4_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_ADDR (0x00000438u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW4_REG_RESETVAL (0x15000000u)

/* DPD1_ROW_CELL_CONFIG_BLK1_ROW5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b1_r5_c2 : 2;
    Uint32 synch_cell_b1_r5_c1 : 2;
    Uint32 synch_cell_b1_r5_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b1_r5 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b1_r5 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b1_r5 : 1;
    Uint32 mux_daxi_b1_r5 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b1_r5 : 1;
    Uint32 mux_real_b1_r5 : 1;
    Uint32 mux_dgxi_b1_r5 : 4;
    Uint32 mux_dgaxi_b1_r5 : 4;
#else 
    Uint32 mux_dgaxi_b1_r5 : 4;
    Uint32 mux_dgxi_b1_r5 : 4;
    Uint32 mux_real_b1_r5 : 1;
    Uint32 mux_complex_b1_r5 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b1_r5 : 1;
    Uint32 mux_dxi_b1_r5 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b1_r5 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b1_r5 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b1_r5_c0 : 2;
    Uint32 synch_cell_b1_r5_c1 : 2;
    Uint32 synch_cell_b1_r5_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG;

/* [3]: If 1?b0, dgaxi_row5 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DGAXI_B1_R5_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DGAXI_B1_R5_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DGAXI_B1_R5_RESETVAL (0x00000000u)

/* [3]: If 1?b1, dgxi_row5 output is nulled */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DGXI_B1_R5_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DGXI_B1_R5_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DGXI_B1_R5_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_REAL_B1_R5_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_REAL_B1_R5_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_REAL_B1_R5_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_COMPLEX_B1_R5_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_COMPLEX_B1_R5_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_COMPLEX_B1_R5_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DAXI_B1_R5_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DAXI_B1_R5_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DAXI_B1_R5_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DXI_B1_R5_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DXI_B1_R5_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_MUX_DXI_B1_R5_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_LUT_INIT_B1_R5_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_LUT_INIT_B1_R5_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_LUT_INIT_B1_R5_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_LUT_TOGGLE_B1_R5_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_LUT_TOGGLE_B1_R5_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_LUT_TOGGLE_B1_R5_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_SYNCH_CELL_B1_R5_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_SYNCH_CELL_B1_R5_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_SYNCH_CELL_B1_R5_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_SYNCH_CELL_B1_R5_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_SYNCH_CELL_B1_R5_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_SYNCH_CELL_B1_R5_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_SYNCH_CELL_B1_R5_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_SYNCH_CELL_B1_R5_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_SYNCH_CELL_B1_R5_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_ADDR (0x0000043Cu)
#define CSL_DFE_DPD_DPD1_ROW_CELL_CONFIG_BLK1_ROW5_REG_RESETVAL (0x15000000u)

/* DPD2_MUX_BLK2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mux_dgxo_o_b2 : 4;
    Uint32 mux_dgxo_e_b2 : 4;
    Uint32 mux_dgaxo_o_b2 : 4;
    Uint32 mux_dgaxo_e_b2 : 4;
    Uint32 rsvd3 : 2;
    Uint32 mux_dg_o_b2 : 1;
    Uint32 mux_dg_e_b2 : 1;
    Uint32 rsvd2 : 2;
    Uint32 mux_dga_o_b2 : 1;
    Uint32 mux_dga_e_b2 : 1;
    Uint32 rsvd1 : 3;
    Uint32 mux_dg_2x_b2 : 1;
    Uint32 rsvd0 : 3;
    Uint32 mux_2x_b2 : 1;
#else 
    Uint32 mux_2x_b2 : 1;
    Uint32 rsvd0 : 3;
    Uint32 mux_dg_2x_b2 : 1;
    Uint32 rsvd1 : 3;
    Uint32 mux_dga_e_b2 : 1;
    Uint32 mux_dga_o_b2 : 1;
    Uint32 rsvd2 : 2;
    Uint32 mux_dg_e_b2 : 1;
    Uint32 mux_dg_o_b2 : 1;
    Uint32 rsvd3 : 2;
    Uint32 mux_dgaxo_e_b2 : 4;
    Uint32 mux_dgaxo_o_b2 : 4;
    Uint32 mux_dgxo_e_b2 : 4;
    Uint32 mux_dgxo_o_b2 : 4;
#endif 
} CSL_DFE_DPD_DPD2_MUX_BLK2_REG;

/* 0 = Rows within the block configured for only 1 daisy chain  */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_2X_B2_MASK (0x00000001u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_2X_B2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_2X_B2_RESETVAL (0x00000000u)

/* 0 = Delay line within delay generator configured as 1 delay line of 8 registers */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DG_2X_B2_MASK (0x00000010u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DG_2X_B2_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DG_2X_B2_RESETVAL (0x00000000u)

/* 0 = takes the absolute value data stream from the dgaxo even output of another gc_delay_generator for the even input.  */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGA_E_B2_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGA_E_B2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGA_E_B2_RESETVAL (0x00000000u)

/* 0 = takes the absolute value data stream from the dgaxo odd output of another gc_delay_generator for the odd input.  */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGA_O_B2_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGA_O_B2_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGA_O_B2_RESETVAL (0x00000000u)

/* 0 = takes the complex data stream from the dgxo even output of another gc_delay_generator for the even input */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DG_E_B2_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DG_E_B2_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DG_E_B2_RESETVAL (0x00000000u)

/* 0 = takes the complex data stream from the dgxo odd outputt of another gc_delay_generator for the odd input */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DG_O_B2_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DG_O_B2_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DG_O_B2_RESETVAL (0x00000000u)

/* [3] If 1?b2, dgaxo_o is nulled */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGAXO_E_B2_MASK (0x000F0000u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGAXO_E_B2_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGAXO_E_B2_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b2', except for it is for dgaxo odd stream. */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGAXO_O_B2_MASK (0x00F00000u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGAXO_O_B2_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGAXO_O_B2_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b2', except for it is for dgxo even stream. */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGXO_E_B2_MASK (0x0F000000u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGXO_E_B2_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGXO_E_B2_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b2', except for it is for dgxo odd stream. */
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGXO_O_B2_MASK (0xF0000000u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGXO_O_B2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_MUX_DGXO_O_B2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_ADDR (0x00000440u)
#define CSL_DFE_DPD_DPD2_MUX_BLK2_REG_RESETVAL (0x00000000u)

/* DPD2_CURRENT_LUT_MPU_BLK2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd5 : 9;
    Uint32 current_lut_mpu_b2_r5 : 3;
    Uint32 rsvd4 : 1;
    Uint32 current_lut_mpu_b2_r4 : 3;
    Uint32 rsvd3 : 1;
    Uint32 current_lut_mpu_b2_r3 : 3;
    Uint32 rsvd2 : 1;
    Uint32 current_lut_mpu_b2_r2 : 3;
    Uint32 rsvd1 : 1;
    Uint32 current_lut_mpu_b2_r1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 current_lut_mpu_b2_r0 : 3;
#else 
    Uint32 current_lut_mpu_b2_r0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 current_lut_mpu_b2_r1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 current_lut_mpu_b2_r2 : 3;
    Uint32 rsvd2 : 1;
    Uint32 current_lut_mpu_b2_r3 : 3;
    Uint32 rsvd3 : 1;
    Uint32 current_lut_mpu_b2_r4 : 3;
    Uint32 rsvd4 : 1;
    Uint32 current_lut_mpu_b2_r5 : 3;
    Uint32 rsvd5 : 9;
#endif 
} CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG;

/* DPD block 0, row 0, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R0_MASK (0x00000007u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R0_RESETVAL (0x00000000u)

/* DPD block 0, row 1, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R1_MASK (0x00000070u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R1_RESETVAL (0x00000000u)

/* DPD block 0, row 2, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R2_MASK (0x00000700u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R2_RESETVAL (0x00000000u)

/* DPD block 0, row 3, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R3_MASK (0x00007000u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R3_RESETVAL (0x00000000u)

/* DPD block 0, row 4, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R4_MASK (0x00070000u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R4_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R4_RESETVAL (0x00000000u)

/* DPD block 0, row 5, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R5_MASK (0x00700000u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R5_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_CURRENT_LUT_MPU_B2_R5_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_ADDR (0x00000444u)
#define CSL_DFE_DPD_DPD2_CURRENT_LUT_MPU_BLK2_REG_RESETVAL (0x00000000u)

/* DPD2_ROW_CELL_CONFIG_BLK2_ROW0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b2_r0_c2 : 2;
    Uint32 synch_cell_b2_r0_c1 : 2;
    Uint32 synch_cell_b2_r0_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b2_r0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b2_r0 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b2_r0 : 1;
    Uint32 mux_daxi_b2_r0 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b2_r0 : 1;
    Uint32 mux_real_b2_r0 : 1;
    Uint32 mux_dgxi_b2_r0 : 4;
    Uint32 mux_dgaxi_b2_r0 : 4;
#else 
    Uint32 mux_dgaxi_b2_r0 : 4;
    Uint32 mux_dgxi_b2_r0 : 4;
    Uint32 mux_real_b2_r0 : 1;
    Uint32 mux_complex_b2_r0 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b2_r0 : 1;
    Uint32 mux_dxi_b2_r0 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b2_r0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b2_r0 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b2_r0_c0 : 2;
    Uint32 synch_cell_b2_r0_c1 : 2;
    Uint32 synch_cell_b2_r0_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG;

/* [3]: If 1?b0, dgaxi_row0 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DGAXI_B2_R0_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DGAXI_B2_R0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DGAXI_B2_R0_RESETVAL (0x00000000u)

/* [3]: If 1?b2, dgxi_row0 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DGXI_B2_R0_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DGXI_B2_R0_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DGXI_B2_R0_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_REAL_B2_R0_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_REAL_B2_R0_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_REAL_B2_R0_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_COMPLEX_B2_R0_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_COMPLEX_B2_R0_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_COMPLEX_B2_R0_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DAXI_B2_R0_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DAXI_B2_R0_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DAXI_B2_R0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DXI_B2_R0_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DXI_B2_R0_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_MUX_DXI_B2_R0_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_LUT_INIT_B2_R0_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_LUT_INIT_B2_R0_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_LUT_INIT_B2_R0_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_LUT_TOGGLE_B2_R0_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_LUT_TOGGLE_B2_R0_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_LUT_TOGGLE_B2_R0_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_SYNCH_CELL_B2_R0_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_SYNCH_CELL_B2_R0_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_SYNCH_CELL_B2_R0_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_SYNCH_CELL_B2_R0_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_SYNCH_CELL_B2_R0_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_SYNCH_CELL_B2_R0_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_SYNCH_CELL_B2_R0_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_SYNCH_CELL_B2_R0_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_SYNCH_CELL_B2_R0_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_ADDR (0x00000448u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW0_REG_RESETVAL (0x15000000u)

/* DPD2_ROW_CELL_CONFIG_BLK2_ROW1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b2_r1_c2 : 2;
    Uint32 synch_cell_b2_r1_c1 : 2;
    Uint32 synch_cell_b2_r1_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b2_r1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b2_r1 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b2_r1 : 1;
    Uint32 mux_daxi_b2_r1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b2_r1 : 1;
    Uint32 mux_real_b2_r1 : 1;
    Uint32 mux_dgxi_b2_r1 : 4;
    Uint32 mux_dgaxi_b2_r1 : 4;
#else 
    Uint32 mux_dgaxi_b2_r1 : 4;
    Uint32 mux_dgxi_b2_r1 : 4;
    Uint32 mux_real_b2_r1 : 1;
    Uint32 mux_complex_b2_r1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b2_r1 : 1;
    Uint32 mux_dxi_b2_r1 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b2_r1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b2_r1 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b2_r1_c0 : 2;
    Uint32 synch_cell_b2_r1_c1 : 2;
    Uint32 synch_cell_b2_r1_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG;

/* [3]: If 1?b0, dgaxi_row1 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DGAXI_B2_R1_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DGAXI_B2_R1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DGAXI_B2_R1_RESETVAL (0x00000000u)

/* [3]: If 1?b2, dgxi_row1 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DGXI_B2_R1_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DGXI_B2_R1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DGXI_B2_R1_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_REAL_B2_R1_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_REAL_B2_R1_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_REAL_B2_R1_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_COMPLEX_B2_R1_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_COMPLEX_B2_R1_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_COMPLEX_B2_R1_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DAXI_B2_R1_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DAXI_B2_R1_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DAXI_B2_R1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DXI_B2_R1_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DXI_B2_R1_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_MUX_DXI_B2_R1_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_LUT_INIT_B2_R1_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_LUT_INIT_B2_R1_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_LUT_INIT_B2_R1_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_LUT_TOGGLE_B2_R1_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_LUT_TOGGLE_B2_R1_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_LUT_TOGGLE_B2_R1_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_SYNCH_CELL_B2_R1_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_SYNCH_CELL_B2_R1_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_SYNCH_CELL_B2_R1_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_SYNCH_CELL_B2_R1_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_SYNCH_CELL_B2_R1_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_SYNCH_CELL_B2_R1_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_SYNCH_CELL_B2_R1_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_SYNCH_CELL_B2_R1_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_SYNCH_CELL_B2_R1_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_ADDR (0x0000044Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW1_REG_RESETVAL (0x15000000u)

/* DPD2_ROW_CELL_CONFIG_BLK2_ROW2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b2_r2_c2 : 2;
    Uint32 synch_cell_b2_r2_c1 : 2;
    Uint32 synch_cell_b2_r2_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b2_r2 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b2_r2 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b2_r2 : 1;
    Uint32 mux_daxi_b2_r2 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b2_r2 : 1;
    Uint32 mux_real_b2_r2 : 1;
    Uint32 mux_dgxi_b2_r2 : 4;
    Uint32 mux_dgaxi_b2_r2 : 4;
#else 
    Uint32 mux_dgaxi_b2_r2 : 4;
    Uint32 mux_dgxi_b2_r2 : 4;
    Uint32 mux_real_b2_r2 : 1;
    Uint32 mux_complex_b2_r2 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b2_r2 : 1;
    Uint32 mux_dxi_b2_r2 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b2_r2 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b2_r2 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b2_r2_c0 : 2;
    Uint32 synch_cell_b2_r2_c1 : 2;
    Uint32 synch_cell_b2_r2_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG;

/* [3]: If 1?b0, dgaxi_row2 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DGAXI_B2_R2_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DGAXI_B2_R2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DGAXI_B2_R2_RESETVAL (0x00000000u)

/* [3]: If 1?b2, dgxi_row2 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DGXI_B2_R2_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DGXI_B2_R2_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DGXI_B2_R2_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_REAL_B2_R2_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_REAL_B2_R2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_REAL_B2_R2_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_COMPLEX_B2_R2_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_COMPLEX_B2_R2_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_COMPLEX_B2_R2_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DAXI_B2_R2_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DAXI_B2_R2_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DAXI_B2_R2_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DXI_B2_R2_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DXI_B2_R2_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_MUX_DXI_B2_R2_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_LUT_INIT_B2_R2_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_LUT_INIT_B2_R2_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_LUT_INIT_B2_R2_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_LUT_TOGGLE_B2_R2_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_LUT_TOGGLE_B2_R2_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_LUT_TOGGLE_B2_R2_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_SYNCH_CELL_B2_R2_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_SYNCH_CELL_B2_R2_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_SYNCH_CELL_B2_R2_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_SYNCH_CELL_B2_R2_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_SYNCH_CELL_B2_R2_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_SYNCH_CELL_B2_R2_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_SYNCH_CELL_B2_R2_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_SYNCH_CELL_B2_R2_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_SYNCH_CELL_B2_R2_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_ADDR (0x00000450u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW2_REG_RESETVAL (0x15000000u)

/* DPD2_ROW_CELL_CONFIG_BLK2_ROW3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b2_r3_c2 : 2;
    Uint32 synch_cell_b2_r3_c1 : 2;
    Uint32 synch_cell_b2_r3_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b2_r3 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b2_r3 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b2_r3 : 1;
    Uint32 mux_daxi_b2_r3 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b2_r3 : 1;
    Uint32 mux_real_b2_r3 : 1;
    Uint32 mux_dgxi_b2_r3 : 4;
    Uint32 mux_dgaxi_b2_r3 : 4;
#else 
    Uint32 mux_dgaxi_b2_r3 : 4;
    Uint32 mux_dgxi_b2_r3 : 4;
    Uint32 mux_real_b2_r3 : 1;
    Uint32 mux_complex_b2_r3 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b2_r3 : 1;
    Uint32 mux_dxi_b2_r3 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b2_r3 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b2_r3 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b2_r3_c0 : 2;
    Uint32 synch_cell_b2_r3_c1 : 2;
    Uint32 synch_cell_b2_r3_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG;

/* [3]: If 1?b0, dgaxi_row3 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DGAXI_B2_R3_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DGAXI_B2_R3_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DGAXI_B2_R3_RESETVAL (0x00000000u)

/* [3]: If 1?b2, dgxi_row3 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DGXI_B2_R3_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DGXI_B2_R3_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DGXI_B2_R3_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_REAL_B2_R3_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_REAL_B2_R3_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_REAL_B2_R3_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_COMPLEX_B2_R3_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_COMPLEX_B2_R3_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_COMPLEX_B2_R3_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DAXI_B2_R3_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DAXI_B2_R3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DAXI_B2_R3_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DXI_B2_R3_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DXI_B2_R3_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_MUX_DXI_B2_R3_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_LUT_INIT_B2_R3_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_LUT_INIT_B2_R3_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_LUT_INIT_B2_R3_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_LUT_TOGGLE_B2_R3_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_LUT_TOGGLE_B2_R3_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_LUT_TOGGLE_B2_R3_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_SYNCH_CELL_B2_R3_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_SYNCH_CELL_B2_R3_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_SYNCH_CELL_B2_R3_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_SYNCH_CELL_B2_R3_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_SYNCH_CELL_B2_R3_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_SYNCH_CELL_B2_R3_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_SYNCH_CELL_B2_R3_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_SYNCH_CELL_B2_R3_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_SYNCH_CELL_B2_R3_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_ADDR (0x00000454u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW3_REG_RESETVAL (0x15000000u)

/* DPD2_ROW_CELL_CONFIG_BLK2_ROW4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b2_r4_c2 : 2;
    Uint32 synch_cell_b2_r4_c1 : 2;
    Uint32 synch_cell_b2_r4_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b2_r4 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b2_r4 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b2_r4 : 1;
    Uint32 mux_daxi_b2_r4 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b2_r4 : 1;
    Uint32 mux_real_b2_r4 : 1;
    Uint32 mux_dgxi_b2_r4 : 4;
    Uint32 mux_dgaxi_b2_r4 : 4;
#else 
    Uint32 mux_dgaxi_b2_r4 : 4;
    Uint32 mux_dgxi_b2_r4 : 4;
    Uint32 mux_real_b2_r4 : 1;
    Uint32 mux_complex_b2_r4 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b2_r4 : 1;
    Uint32 mux_dxi_b2_r4 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b2_r4 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b2_r4 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b2_r4_c0 : 2;
    Uint32 synch_cell_b2_r4_c1 : 2;
    Uint32 synch_cell_b2_r4_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG;

/* [3]: If 1?b0, dgaxi_row4 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DGAXI_B2_R4_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DGAXI_B2_R4_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DGAXI_B2_R4_RESETVAL (0x00000000u)

/* [3]: If 1?b2, dgxi_row4 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DGXI_B2_R4_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DGXI_B2_R4_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DGXI_B2_R4_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_REAL_B2_R4_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_REAL_B2_R4_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_REAL_B2_R4_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_COMPLEX_B2_R4_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_COMPLEX_B2_R4_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_COMPLEX_B2_R4_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DAXI_B2_R4_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DAXI_B2_R4_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DAXI_B2_R4_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DXI_B2_R4_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DXI_B2_R4_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_MUX_DXI_B2_R4_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_LUT_INIT_B2_R4_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_LUT_INIT_B2_R4_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_LUT_INIT_B2_R4_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_LUT_TOGGLE_B2_R4_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_LUT_TOGGLE_B2_R4_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_LUT_TOGGLE_B2_R4_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_SYNCH_CELL_B2_R4_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_SYNCH_CELL_B2_R4_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_SYNCH_CELL_B2_R4_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_SYNCH_CELL_B2_R4_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_SYNCH_CELL_B2_R4_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_SYNCH_CELL_B2_R4_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_SYNCH_CELL_B2_R4_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_SYNCH_CELL_B2_R4_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_SYNCH_CELL_B2_R4_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_ADDR (0x00000458u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW4_REG_RESETVAL (0x15000000u)

/* DPD2_ROW_CELL_CONFIG_BLK2_ROW5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b2_r5_c2 : 2;
    Uint32 synch_cell_b2_r5_c1 : 2;
    Uint32 synch_cell_b2_r5_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b2_r5 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b2_r5 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b2_r5 : 1;
    Uint32 mux_daxi_b2_r5 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b2_r5 : 1;
    Uint32 mux_real_b2_r5 : 1;
    Uint32 mux_dgxi_b2_r5 : 4;
    Uint32 mux_dgaxi_b2_r5 : 4;
#else 
    Uint32 mux_dgaxi_b2_r5 : 4;
    Uint32 mux_dgxi_b2_r5 : 4;
    Uint32 mux_real_b2_r5 : 1;
    Uint32 mux_complex_b2_r5 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b2_r5 : 1;
    Uint32 mux_dxi_b2_r5 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b2_r5 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b2_r5 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b2_r5_c0 : 2;
    Uint32 synch_cell_b2_r5_c1 : 2;
    Uint32 synch_cell_b2_r5_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG;

/* [3]: If 1?b0, dgaxi_row5 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DGAXI_B2_R5_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DGAXI_B2_R5_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DGAXI_B2_R5_RESETVAL (0x00000000u)

/* [3]: If 1?b2, dgxi_row5 output is nulled */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DGXI_B2_R5_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DGXI_B2_R5_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DGXI_B2_R5_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_REAL_B2_R5_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_REAL_B2_R5_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_REAL_B2_R5_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_COMPLEX_B2_R5_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_COMPLEX_B2_R5_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_COMPLEX_B2_R5_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DAXI_B2_R5_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DAXI_B2_R5_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DAXI_B2_R5_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DXI_B2_R5_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DXI_B2_R5_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_MUX_DXI_B2_R5_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_LUT_INIT_B2_R5_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_LUT_INIT_B2_R5_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_LUT_INIT_B2_R5_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_LUT_TOGGLE_B2_R5_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_LUT_TOGGLE_B2_R5_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_LUT_TOGGLE_B2_R5_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_SYNCH_CELL_B2_R5_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_SYNCH_CELL_B2_R5_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_SYNCH_CELL_B2_R5_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_SYNCH_CELL_B2_R5_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_SYNCH_CELL_B2_R5_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_SYNCH_CELL_B2_R5_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_SYNCH_CELL_B2_R5_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_SYNCH_CELL_B2_R5_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_SYNCH_CELL_B2_R5_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_ADDR (0x0000045Cu)
#define CSL_DFE_DPD_DPD2_ROW_CELL_CONFIG_BLK2_ROW5_REG_RESETVAL (0x15000000u)

/* DPD3_MUX_BLK3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 mux_dgxo_o_b3 : 4;
    Uint32 mux_dgxo_e_b3 : 4;
    Uint32 mux_dgaxo_o_b3 : 4;
    Uint32 mux_dgaxo_e_b3 : 4;
    Uint32 rsvd3 : 2;
    Uint32 mux_dg_o_b3 : 1;
    Uint32 mux_dg_e_b3 : 1;
    Uint32 rsvd2 : 2;
    Uint32 mux_dga_o_b3 : 1;
    Uint32 mux_dga_e_b3 : 1;
    Uint32 rsvd1 : 3;
    Uint32 mux_dg_2x_b3 : 1;
    Uint32 rsvd0 : 3;
    Uint32 mux_2x_b3 : 1;
#else 
    Uint32 mux_2x_b3 : 1;
    Uint32 rsvd0 : 3;
    Uint32 mux_dg_2x_b3 : 1;
    Uint32 rsvd1 : 3;
    Uint32 mux_dga_e_b3 : 1;
    Uint32 mux_dga_o_b3 : 1;
    Uint32 rsvd2 : 2;
    Uint32 mux_dg_e_b3 : 1;
    Uint32 mux_dg_o_b3 : 1;
    Uint32 rsvd3 : 2;
    Uint32 mux_dgaxo_e_b3 : 4;
    Uint32 mux_dgaxo_o_b3 : 4;
    Uint32 mux_dgxo_e_b3 : 4;
    Uint32 mux_dgxo_o_b3 : 4;
#endif 
} CSL_DFE_DPD_DPD3_MUX_BLK3_REG;

/* 0 = Rows within the block configured for only 1 daisy chain  */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_2X_B3_MASK (0x00000001u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_2X_B3_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_2X_B3_RESETVAL (0x00000000u)

/* 0 = Delay line within delay generator configured as 1 delay line of 8 registers */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DG_2X_B3_MASK (0x00000010u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DG_2X_B3_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DG_2X_B3_RESETVAL (0x00000000u)

/* 0 = takes the absolute value data stream from the dgaxo even output of another gc_delay_generator for the even input.  */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGA_E_B3_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGA_E_B3_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGA_E_B3_RESETVAL (0x00000000u)

/* 0 = takes the absolute value data stream from the dgaxo odd output of another gc_delay_generator for the odd input.  */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGA_O_B3_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGA_O_B3_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGA_O_B3_RESETVAL (0x00000000u)

/* 0 = takes the complex data stream from the dgxo even output of another gc_delay_generator for the even input */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DG_E_B3_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DG_E_B3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DG_E_B3_RESETVAL (0x00000000u)

/* 0 = takes the complex data stream from the dgxo odd outputt of another gc_delay_generator for the odd input */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DG_O_B3_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DG_O_B3_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DG_O_B3_RESETVAL (0x00000000u)

/* [3] If 1?b3, dgaxo_o is nulled */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGAXO_E_B3_MASK (0x000F0000u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGAXO_E_B3_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGAXO_E_B3_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b3', except for it is for dgaxo odd stream. */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGAXO_O_B3_MASK (0x00F00000u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGAXO_O_B3_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGAXO_O_B3_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b3', except for it is for dgxo even stream. */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGXO_E_B3_MASK (0x0F000000u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGXO_E_B3_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGXO_E_B3_RESETVAL (0x00000000u)

/* Same as 'mux_dgaxo_e_b3', except for it is for dgxo odd stream. */
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGXO_O_B3_MASK (0xF0000000u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGXO_O_B3_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_MUX_DGXO_O_B3_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_ADDR (0x00000460u)
#define CSL_DFE_DPD_DPD3_MUX_BLK3_REG_RESETVAL (0x00000000u)

/* DPD3_CURRENT_LUT_MPU_BLK3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd5 : 9;
    Uint32 current_lut_mpu_b3_r5 : 3;
    Uint32 rsvd4 : 1;
    Uint32 current_lut_mpu_b3_r4 : 3;
    Uint32 rsvd3 : 1;
    Uint32 current_lut_mpu_b3_r3 : 3;
    Uint32 rsvd2 : 1;
    Uint32 current_lut_mpu_b3_r2 : 3;
    Uint32 rsvd1 : 1;
    Uint32 current_lut_mpu_b3_r1 : 3;
    Uint32 rsvd0 : 1;
    Uint32 current_lut_mpu_b3_r0 : 3;
#else 
    Uint32 current_lut_mpu_b3_r0 : 3;
    Uint32 rsvd0 : 1;
    Uint32 current_lut_mpu_b3_r1 : 3;
    Uint32 rsvd1 : 1;
    Uint32 current_lut_mpu_b3_r2 : 3;
    Uint32 rsvd2 : 1;
    Uint32 current_lut_mpu_b3_r3 : 3;
    Uint32 rsvd3 : 1;
    Uint32 current_lut_mpu_b3_r4 : 3;
    Uint32 rsvd4 : 1;
    Uint32 current_lut_mpu_b3_r5 : 3;
    Uint32 rsvd5 : 9;
#endif 
} CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG;

/* DPD block 0, row 0, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R0_MASK (0x00000007u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R0_RESETVAL (0x00000000u)

/* DPD block 0, row 1, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R1_MASK (0x00000070u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R1_RESETVAL (0x00000000u)

/* DPD block 0, row 2, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R2_MASK (0x00000700u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R2_RESETVAL (0x00000000u)

/* DPD block 0, row 3, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R3_MASK (0x00007000u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R3_RESETVAL (0x00000000u)

/* DPD block 0, row 4, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R4_MASK (0x00070000u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R4_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R4_RESETVAL (0x00000000u)

/* DPD block 0, row 5, bit [0] for cell0, bit [1] for cell1 and bit [2] for cell2: */
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R5_MASK (0x00700000u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R5_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_CURRENT_LUT_MPU_B3_R5_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_ADDR (0x00000464u)
#define CSL_DFE_DPD_DPD3_CURRENT_LUT_MPU_BLK3_REG_RESETVAL (0x00000000u)

/* DPD3_ROW_CELL_CONFIG_BLK3_ROW0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b3_r0_c2 : 2;
    Uint32 synch_cell_b3_r0_c1 : 2;
    Uint32 synch_cell_b3_r0_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b3_r0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b3_r0 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b3_r0 : 1;
    Uint32 mux_daxi_b3_r0 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b3_r0 : 1;
    Uint32 mux_real_b3_r0 : 1;
    Uint32 mux_dgxi_b3_r0 : 4;
    Uint32 mux_dgaxi_b3_r0 : 4;
#else 
    Uint32 mux_dgaxi_b3_r0 : 4;
    Uint32 mux_dgxi_b3_r0 : 4;
    Uint32 mux_real_b3_r0 : 1;
    Uint32 mux_complex_b3_r0 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b3_r0 : 1;
    Uint32 mux_dxi_b3_r0 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b3_r0 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b3_r0 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b3_r0_c0 : 2;
    Uint32 synch_cell_b3_r0_c1 : 2;
    Uint32 synch_cell_b3_r0_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG;

/* [3]: If 1?b0, dgaxi_row0 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DGAXI_B3_R0_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DGAXI_B3_R0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DGAXI_B3_R0_RESETVAL (0x00000000u)

/* [3]: If 1?b3, dgxi_row0 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DGXI_B3_R0_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DGXI_B3_R0_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DGXI_B3_R0_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_REAL_B3_R0_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_REAL_B3_R0_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_REAL_B3_R0_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_COMPLEX_B3_R0_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_COMPLEX_B3_R0_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_COMPLEX_B3_R0_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DAXI_B3_R0_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DAXI_B3_R0_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DAXI_B3_R0_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DXI_B3_R0_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DXI_B3_R0_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_MUX_DXI_B3_R0_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_LUT_INIT_B3_R0_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_LUT_INIT_B3_R0_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_LUT_INIT_B3_R0_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_LUT_TOGGLE_B3_R0_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_LUT_TOGGLE_B3_R0_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_LUT_TOGGLE_B3_R0_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_SYNCH_CELL_B3_R0_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_SYNCH_CELL_B3_R0_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_SYNCH_CELL_B3_R0_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_SYNCH_CELL_B3_R0_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_SYNCH_CELL_B3_R0_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_SYNCH_CELL_B3_R0_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_SYNCH_CELL_B3_R0_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_SYNCH_CELL_B3_R0_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_SYNCH_CELL_B3_R0_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_ADDR (0x00000468u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW0_REG_RESETVAL (0x15000000u)

/* DPD3_ROW_CELL_CONFIG_BLK3_ROW1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b3_r1_c2 : 2;
    Uint32 synch_cell_b3_r1_c1 : 2;
    Uint32 synch_cell_b3_r1_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b3_r1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b3_r1 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b3_r1 : 1;
    Uint32 mux_daxi_b3_r1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b3_r1 : 1;
    Uint32 mux_real_b3_r1 : 1;
    Uint32 mux_dgxi_b3_r1 : 4;
    Uint32 mux_dgaxi_b3_r1 : 4;
#else 
    Uint32 mux_dgaxi_b3_r1 : 4;
    Uint32 mux_dgxi_b3_r1 : 4;
    Uint32 mux_real_b3_r1 : 1;
    Uint32 mux_complex_b3_r1 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b3_r1 : 1;
    Uint32 mux_dxi_b3_r1 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b3_r1 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b3_r1 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b3_r1_c0 : 2;
    Uint32 synch_cell_b3_r1_c1 : 2;
    Uint32 synch_cell_b3_r1_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG;

/* [3]: If 1?b0, dgaxi_row1 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DGAXI_B3_R1_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DGAXI_B3_R1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DGAXI_B3_R1_RESETVAL (0x00000000u)

/* [3]: If 1?b3, dgxi_row1 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DGXI_B3_R1_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DGXI_B3_R1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DGXI_B3_R1_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_REAL_B3_R1_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_REAL_B3_R1_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_REAL_B3_R1_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_COMPLEX_B3_R1_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_COMPLEX_B3_R1_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_COMPLEX_B3_R1_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DAXI_B3_R1_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DAXI_B3_R1_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DAXI_B3_R1_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DXI_B3_R1_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DXI_B3_R1_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_MUX_DXI_B3_R1_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_LUT_INIT_B3_R1_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_LUT_INIT_B3_R1_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_LUT_INIT_B3_R1_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_LUT_TOGGLE_B3_R1_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_LUT_TOGGLE_B3_R1_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_LUT_TOGGLE_B3_R1_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_SYNCH_CELL_B3_R1_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_SYNCH_CELL_B3_R1_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_SYNCH_CELL_B3_R1_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_SYNCH_CELL_B3_R1_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_SYNCH_CELL_B3_R1_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_SYNCH_CELL_B3_R1_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_SYNCH_CELL_B3_R1_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_SYNCH_CELL_B3_R1_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_SYNCH_CELL_B3_R1_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_ADDR (0x0000046Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW1_REG_RESETVAL (0x15000000u)

/* DPD3_ROW_CELL_CONFIG_BLK3_ROW2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b3_r2_c2 : 2;
    Uint32 synch_cell_b3_r2_c1 : 2;
    Uint32 synch_cell_b3_r2_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b3_r2 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b3_r2 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b3_r2 : 1;
    Uint32 mux_daxi_b3_r2 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b3_r2 : 1;
    Uint32 mux_real_b3_r2 : 1;
    Uint32 mux_dgxi_b3_r2 : 4;
    Uint32 mux_dgaxi_b3_r2 : 4;
#else 
    Uint32 mux_dgaxi_b3_r2 : 4;
    Uint32 mux_dgxi_b3_r2 : 4;
    Uint32 mux_real_b3_r2 : 1;
    Uint32 mux_complex_b3_r2 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b3_r2 : 1;
    Uint32 mux_dxi_b3_r2 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b3_r2 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b3_r2 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b3_r2_c0 : 2;
    Uint32 synch_cell_b3_r2_c1 : 2;
    Uint32 synch_cell_b3_r2_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG;

/* [3]: If 1?b0, dgaxi_row2 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DGAXI_B3_R2_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DGAXI_B3_R2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DGAXI_B3_R2_RESETVAL (0x00000000u)

/* [3]: If 1?b3, dgxi_row2 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DGXI_B3_R2_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DGXI_B3_R2_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DGXI_B3_R2_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_REAL_B3_R2_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_REAL_B3_R2_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_REAL_B3_R2_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_COMPLEX_B3_R2_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_COMPLEX_B3_R2_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_COMPLEX_B3_R2_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DAXI_B3_R2_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DAXI_B3_R2_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DAXI_B3_R2_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DXI_B3_R2_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DXI_B3_R2_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_MUX_DXI_B3_R2_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_LUT_INIT_B3_R2_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_LUT_INIT_B3_R2_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_LUT_INIT_B3_R2_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_LUT_TOGGLE_B3_R2_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_LUT_TOGGLE_B3_R2_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_LUT_TOGGLE_B3_R2_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_SYNCH_CELL_B3_R2_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_SYNCH_CELL_B3_R2_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_SYNCH_CELL_B3_R2_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_SYNCH_CELL_B3_R2_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_SYNCH_CELL_B3_R2_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_SYNCH_CELL_B3_R2_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_SYNCH_CELL_B3_R2_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_SYNCH_CELL_B3_R2_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_SYNCH_CELL_B3_R2_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_ADDR (0x00000470u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW2_REG_RESETVAL (0x15000000u)

/* DPD3_ROW_CELL_CONFIG_BLK3_ROW3 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b3_r3_c2 : 2;
    Uint32 synch_cell_b3_r3_c1 : 2;
    Uint32 synch_cell_b3_r3_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b3_r3 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b3_r3 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b3_r3 : 1;
    Uint32 mux_daxi_b3_r3 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b3_r3 : 1;
    Uint32 mux_real_b3_r3 : 1;
    Uint32 mux_dgxi_b3_r3 : 4;
    Uint32 mux_dgaxi_b3_r3 : 4;
#else 
    Uint32 mux_dgaxi_b3_r3 : 4;
    Uint32 mux_dgxi_b3_r3 : 4;
    Uint32 mux_real_b3_r3 : 1;
    Uint32 mux_complex_b3_r3 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b3_r3 : 1;
    Uint32 mux_dxi_b3_r3 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b3_r3 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b3_r3 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b3_r3_c0 : 2;
    Uint32 synch_cell_b3_r3_c1 : 2;
    Uint32 synch_cell_b3_r3_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG;

/* [3]: If 1?b0, dgaxi_row3 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DGAXI_B3_R3_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DGAXI_B3_R3_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DGAXI_B3_R3_RESETVAL (0x00000000u)

/* [3]: If 1?b3, dgxi_row3 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DGXI_B3_R3_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DGXI_B3_R3_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DGXI_B3_R3_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_REAL_B3_R3_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_REAL_B3_R3_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_REAL_B3_R3_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_COMPLEX_B3_R3_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_COMPLEX_B3_R3_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_COMPLEX_B3_R3_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DAXI_B3_R3_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DAXI_B3_R3_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DAXI_B3_R3_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DXI_B3_R3_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DXI_B3_R3_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_MUX_DXI_B3_R3_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_LUT_INIT_B3_R3_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_LUT_INIT_B3_R3_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_LUT_INIT_B3_R3_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_LUT_TOGGLE_B3_R3_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_LUT_TOGGLE_B3_R3_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_LUT_TOGGLE_B3_R3_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_SYNCH_CELL_B3_R3_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_SYNCH_CELL_B3_R3_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_SYNCH_CELL_B3_R3_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_SYNCH_CELL_B3_R3_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_SYNCH_CELL_B3_R3_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_SYNCH_CELL_B3_R3_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_SYNCH_CELL_B3_R3_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_SYNCH_CELL_B3_R3_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_SYNCH_CELL_B3_R3_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_ADDR (0x00000474u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW3_REG_RESETVAL (0x15000000u)

/* DPD3_ROW_CELL_CONFIG_BLK3_ROW4 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b3_r4_c2 : 2;
    Uint32 synch_cell_b3_r4_c1 : 2;
    Uint32 synch_cell_b3_r4_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b3_r4 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b3_r4 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b3_r4 : 1;
    Uint32 mux_daxi_b3_r4 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b3_r4 : 1;
    Uint32 mux_real_b3_r4 : 1;
    Uint32 mux_dgxi_b3_r4 : 4;
    Uint32 mux_dgaxi_b3_r4 : 4;
#else 
    Uint32 mux_dgaxi_b3_r4 : 4;
    Uint32 mux_dgxi_b3_r4 : 4;
    Uint32 mux_real_b3_r4 : 1;
    Uint32 mux_complex_b3_r4 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b3_r4 : 1;
    Uint32 mux_dxi_b3_r4 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b3_r4 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b3_r4 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b3_r4_c0 : 2;
    Uint32 synch_cell_b3_r4_c1 : 2;
    Uint32 synch_cell_b3_r4_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG;

/* [3]: If 1?b0, dgaxi_row4 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DGAXI_B3_R4_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DGAXI_B3_R4_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DGAXI_B3_R4_RESETVAL (0x00000000u)

/* [3]: If 1?b3, dgxi_row4 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DGXI_B3_R4_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DGXI_B3_R4_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DGXI_B3_R4_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_REAL_B3_R4_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_REAL_B3_R4_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_REAL_B3_R4_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_COMPLEX_B3_R4_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_COMPLEX_B3_R4_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_COMPLEX_B3_R4_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DAXI_B3_R4_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DAXI_B3_R4_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DAXI_B3_R4_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DXI_B3_R4_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DXI_B3_R4_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_MUX_DXI_B3_R4_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_LUT_INIT_B3_R4_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_LUT_INIT_B3_R4_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_LUT_INIT_B3_R4_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_LUT_TOGGLE_B3_R4_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_LUT_TOGGLE_B3_R4_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_LUT_TOGGLE_B3_R4_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_SYNCH_CELL_B3_R4_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_SYNCH_CELL_B3_R4_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_SYNCH_CELL_B3_R4_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_SYNCH_CELL_B3_R4_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_SYNCH_CELL_B3_R4_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_SYNCH_CELL_B3_R4_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_SYNCH_CELL_B3_R4_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_SYNCH_CELL_B3_R4_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_SYNCH_CELL_B3_R4_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_ADDR (0x00000478u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW4_REG_RESETVAL (0x15000000u)

/* DPD3_ROW_CELL_CONFIG_BLK3_ROW5 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd4 : 2;
    Uint32 synch_cell_b3_r5_c2 : 2;
    Uint32 synch_cell_b3_r5_c1 : 2;
    Uint32 synch_cell_b3_r5_c0 : 2;
    Uint32 rsvd3 : 3;
    Uint32 lut_toggle_b3_r5 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_init_b3_r5 : 1;
    Uint32 rsvd1 : 2;
    Uint32 mux_dxi_b3_r5 : 1;
    Uint32 mux_daxi_b3_r5 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_complex_b3_r5 : 1;
    Uint32 mux_real_b3_r5 : 1;
    Uint32 mux_dgxi_b3_r5 : 4;
    Uint32 mux_dgaxi_b3_r5 : 4;
#else 
    Uint32 mux_dgaxi_b3_r5 : 4;
    Uint32 mux_dgxi_b3_r5 : 4;
    Uint32 mux_real_b3_r5 : 1;
    Uint32 mux_complex_b3_r5 : 1;
    Uint32 rsvd0 : 2;
    Uint32 mux_daxi_b3_r5 : 1;
    Uint32 mux_dxi_b3_r5 : 1;
    Uint32 rsvd1 : 2;
    Uint32 lut_init_b3_r5 : 1;
    Uint32 rsvd2 : 3;
    Uint32 lut_toggle_b3_r5 : 1;
    Uint32 rsvd3 : 3;
    Uint32 synch_cell_b3_r5_c0 : 2;
    Uint32 synch_cell_b3_r5_c1 : 2;
    Uint32 synch_cell_b3_r5_c2 : 2;
    Uint32 rsvd4 : 2;
#endif 
} CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG;

/* [3]: If 1?b0, dgaxi_row5 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DGAXI_B3_R5_MASK (0x0000000Fu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DGAXI_B3_R5_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DGAXI_B3_R5_RESETVAL (0x00000000u)

/* [3]: If 1?b3, dgxi_row5 output is nulled */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DGXI_B3_R5_MASK (0x000000F0u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DGXI_B3_R5_SHIFT (0x00000004u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DGXI_B3_R5_RESETVAL (0x00000000u)

/* 0 = nonLinearIn is daxi for all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_REAL_B3_R5_MASK (0x00000100u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_REAL_B3_R5_SHIFT (0x00000008u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_REAL_B3_R5_RESETVAL (0x00000000u)

/* 0 = linearIn is dxi for all  all 3 cells of the row */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_COMPLEX_B3_R5_MASK (0x00000200u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_COMPLEX_B3_R5_SHIFT (0x00000009u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_COMPLEX_B3_R5_RESETVAL (0x00000000u)

/* 0 = daxi comes from the delay_generator.v */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DAXI_B3_R5_MASK (0x00001000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DAXI_B3_R5_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DAXI_B3_R5_RESETVAL (0x00000000u)

/*  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DXI_B3_R5_MASK (0x00002000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DXI_B3_R5_SHIFT (0x0000000Du)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_MUX_DXI_B3_R5_RESETVAL (0x00000000u)

/* 0 = start with LUT0 in the datapath and LUT1 accessible by  the MPU/poly2LUT, for all internal gc_dpd_cell.v  */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_LUT_INIT_B3_R5_MASK (0x00010000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_LUT_INIT_B3_R5_SHIFT (0x00000010u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_LUT_INIT_B3_R5_RESETVAL (0x00000000u)

/* 0 = test mode. Synchs do not cause any change for all 3 cells of the row   */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_LUT_TOGGLE_B3_R5_MASK (0x00100000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_LUT_TOGGLE_B3_R5_SHIFT (0x00000014u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_LUT_TOGGLE_B3_R5_RESETVAL (0x00000000u)

/* Each cell receives 2 synch lines from outside, f_synch and c_synch. synch_cell determines which synch to use: */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_SYNCH_CELL_B3_R5_C0_MASK (0x03000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_SYNCH_CELL_B3_R5_C0_SHIFT (0x00000018u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_SYNCH_CELL_B3_R5_C0_RESETVAL (0x00000001u)

/* same as above, for cell1 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_SYNCH_CELL_B3_R5_C1_MASK (0x0C000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_SYNCH_CELL_B3_R5_C1_SHIFT (0x0000001Au)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_SYNCH_CELL_B3_R5_C1_RESETVAL (0x00000001u)

/* same as above, for cell2 */
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_SYNCH_CELL_B3_R5_C2_MASK (0x30000000u)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_SYNCH_CELL_B3_R5_C2_SHIFT (0x0000001Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_SYNCH_CELL_B3_R5_C2_RESETVAL (0x00000001u)

#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_ADDR (0x0000047Cu)
#define CSL_DFE_DPD_DPD3_ROW_CELL_CONFIG_BLK3_ROW5_REG_RESETVAL (0x15000000u)

/* TOP_SIGNAL_GEN0_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen0_frame_len_m1 : 12;
    Uint32 signal_gen0_seed : 1;
    Uint32 signal_gen0_ramp_mode : 1;
    Uint32 signal_gen0_gen_frame : 1;
    Uint32 signal_gen0_gen_data : 1;
#else 
    Uint32 signal_gen0_gen_data : 1;
    Uint32 signal_gen0_gen_frame : 1;
    Uint32 signal_gen0_ramp_mode : 1;
    Uint32 signal_gen0_seed : 1;
    Uint32 signal_gen0_frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_SEED_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_SEED_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_SIGNAL_GEN0_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_ADDR (0x00000614u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GENERAL_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN0_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen0_ramp_start_15_0 : 16;
#else 
    Uint32 signal_gen0_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_LO_REG_SIGNAL_GEN0_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_LO_REG_SIGNAL_GEN0_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_LO_REG_SIGNAL_GEN0_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_LO_REG_ADDR (0x00000618u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN0_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen0_ramp_start_31_16 : 16;
#else 
    Uint32 signal_gen0_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_HI_REG_SIGNAL_GEN0_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_HI_REG_SIGNAL_GEN0_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_HI_REG_SIGNAL_GEN0_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_HI_REG_ADDR (0x0000061Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN0_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen0_ramp_stop_15_0 : 16;
#else 
    Uint32 signal_gen0_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_LO_REG_SIGNAL_GEN0_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_LO_REG_SIGNAL_GEN0_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_LO_REG_SIGNAL_GEN0_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_LO_REG_ADDR (0x00000620u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN0_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen0_ramp_stop_31_16 : 16;
#else 
    Uint32 signal_gen0_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_HI_REG_SIGNAL_GEN0_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_HI_REG_SIGNAL_GEN0_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_HI_REG_SIGNAL_GEN0_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_HI_REG_ADDR (0x00000624u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN0_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen0_ramp_slope_15_0 : 16;
#else 
    Uint32 signal_gen0_ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_SIGNAL_GEN0_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_SIGNAL_GEN0_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_SIGNAL_GEN0_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_ADDR (0x00000628u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN0_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen0_ramp_slope_31_16 : 16;
#else 
    Uint32 signal_gen0_ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_SIGNAL_GEN0_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_SIGNAL_GEN0_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_SIGNAL_GEN0_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_ADDR (0x0000062Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN0_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen0_gen_timer : 16;
#else 
    Uint32 signal_gen0_gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN0_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GEN_TIMER_REG_SIGNAL_GEN0_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GEN_TIMER_REG_SIGNAL_GEN0_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GEN_TIMER_REG_SIGNAL_GEN0_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GEN_TIMER_REG_ADDR (0x00000630u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN0_INTERNAL_ONLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen0_bits : 16;
#else 
    Uint32 signal_gen0_bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN0_INTERNAL_ONLY_REG;

/* number of data bits inverted (read-only) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_INTERNAL_ONLY_REG_SIGNAL_GEN0_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_INTERNAL_ONLY_REG_SIGNAL_GEN0_BITS_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_INTERNAL_ONLY_REG_SIGNAL_GEN0_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_INTERNAL_ONLY_REG_ADDR (0x00000634u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN0_INTERNAL_ONLY_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN1_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen1_frame_len_m1 : 12;
    Uint32 signal_gen1_seed : 1;
    Uint32 signal_gen1_ramp_mode : 1;
    Uint32 signal_gen1_gen_frame : 1;
    Uint32 signal_gen1_gen_data : 1;
#else 
    Uint32 signal_gen1_gen_data : 1;
    Uint32 signal_gen1_gen_frame : 1;
    Uint32 signal_gen1_ramp_mode : 1;
    Uint32 signal_gen1_seed : 1;
    Uint32 signal_gen1_frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_SEED_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_SEED_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_SIGNAL_GEN1_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_ADDR (0x00000638u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GENERAL_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN1_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen1_ramp_start_15_0 : 16;
#else 
    Uint32 signal_gen1_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_LO_REG_SIGNAL_GEN1_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_LO_REG_SIGNAL_GEN1_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_LO_REG_SIGNAL_GEN1_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_LO_REG_ADDR (0x0000063Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN1_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen1_ramp_start_31_16 : 16;
#else 
    Uint32 signal_gen1_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_HI_REG_SIGNAL_GEN1_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_HI_REG_SIGNAL_GEN1_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_HI_REG_SIGNAL_GEN1_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_HI_REG_ADDR (0x00000640u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN1_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen1_ramp_stop_15_0 : 16;
#else 
    Uint32 signal_gen1_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_LO_REG_SIGNAL_GEN1_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_LO_REG_SIGNAL_GEN1_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_LO_REG_SIGNAL_GEN1_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_LO_REG_ADDR (0x00000644u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN1_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen1_ramp_stop_31_16 : 16;
#else 
    Uint32 signal_gen1_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_HI_REG_SIGNAL_GEN1_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_HI_REG_SIGNAL_GEN1_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_HI_REG_SIGNAL_GEN1_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_HI_REG_ADDR (0x00000648u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN1_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen1_ramp_slope_15_0 : 16;
#else 
    Uint32 signal_gen1_ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_SIGNAL_GEN1_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_SIGNAL_GEN1_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_SIGNAL_GEN1_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_ADDR (0x0000064Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN1_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen1_ramp_slope_31_16 : 16;
#else 
    Uint32 signal_gen1_ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_SIGNAL_GEN1_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_SIGNAL_GEN1_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_SIGNAL_GEN1_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_ADDR (0x00000650u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN1_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen1_gen_timer : 16;
#else 
    Uint32 signal_gen1_gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN1_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GEN_TIMER_REG_SIGNAL_GEN1_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GEN_TIMER_REG_SIGNAL_GEN1_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GEN_TIMER_REG_SIGNAL_GEN1_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GEN_TIMER_REG_ADDR (0x00000654u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN1_INTERNAL_ONLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen1_bits : 16;
#else 
    Uint32 signal_gen1_bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN1_INTERNAL_ONLY_REG;

/* number of data bits inverted (read-only) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_INTERNAL_ONLY_REG_SIGNAL_GEN1_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_INTERNAL_ONLY_REG_SIGNAL_GEN1_BITS_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_INTERNAL_ONLY_REG_SIGNAL_GEN1_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_INTERNAL_ONLY_REG_ADDR (0x00000658u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN1_INTERNAL_ONLY_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN2_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen2_frame_len_m1 : 12;
    Uint32 signal_gen2_seed : 1;
    Uint32 signal_gen2_ramp_mode : 1;
    Uint32 signal_gen2_gen_frame : 1;
    Uint32 signal_gen2_gen_data : 1;
#else 
    Uint32 signal_gen2_gen_data : 1;
    Uint32 signal_gen2_gen_frame : 1;
    Uint32 signal_gen2_ramp_mode : 1;
    Uint32 signal_gen2_seed : 1;
    Uint32 signal_gen2_frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_SEED_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_SEED_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_SIGNAL_GEN2_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_ADDR (0x0000065Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GENERAL_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN2_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen2_ramp_start_15_0 : 16;
#else 
    Uint32 signal_gen2_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_LO_REG_SIGNAL_GEN2_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_LO_REG_SIGNAL_GEN2_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_LO_REG_SIGNAL_GEN2_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_LO_REG_ADDR (0x00000660u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN2_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen2_ramp_start_31_16 : 16;
#else 
    Uint32 signal_gen2_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_HI_REG_SIGNAL_GEN2_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_HI_REG_SIGNAL_GEN2_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_HI_REG_SIGNAL_GEN2_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_HI_REG_ADDR (0x00000664u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN2_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen2_ramp_stop_15_0 : 16;
#else 
    Uint32 signal_gen2_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_LO_REG_SIGNAL_GEN2_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_LO_REG_SIGNAL_GEN2_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_LO_REG_SIGNAL_GEN2_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_LO_REG_ADDR (0x00000668u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN2_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen2_ramp_stop_31_16 : 16;
#else 
    Uint32 signal_gen2_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_HI_REG_SIGNAL_GEN2_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_HI_REG_SIGNAL_GEN2_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_HI_REG_SIGNAL_GEN2_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_HI_REG_ADDR (0x0000066Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN2_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen2_ramp_slope_15_0 : 16;
#else 
    Uint32 signal_gen2_ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_SIGNAL_GEN2_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_SIGNAL_GEN2_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_SIGNAL_GEN2_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_ADDR (0x00000670u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN2_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen2_ramp_slope_31_16 : 16;
#else 
    Uint32 signal_gen2_ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_SIGNAL_GEN2_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_SIGNAL_GEN2_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_SIGNAL_GEN2_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_ADDR (0x00000674u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN2_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen2_gen_timer : 16;
#else 
    Uint32 signal_gen2_gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN2_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GEN_TIMER_REG_SIGNAL_GEN2_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GEN_TIMER_REG_SIGNAL_GEN2_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GEN_TIMER_REG_SIGNAL_GEN2_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GEN_TIMER_REG_ADDR (0x00000678u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN2_INTERNAL_ONLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen2_bits : 16;
#else 
    Uint32 signal_gen2_bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN2_INTERNAL_ONLY_REG;

/* number of data bits inverted (read-only) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_INTERNAL_ONLY_REG_SIGNAL_GEN2_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_INTERNAL_ONLY_REG_SIGNAL_GEN2_BITS_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_INTERNAL_ONLY_REG_SIGNAL_GEN2_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_INTERNAL_ONLY_REG_ADDR (0x0000067Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN2_INTERNAL_ONLY_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN3_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_frame_len_m1 : 12;
    Uint32 signal_gen3_seed : 1;
    Uint32 signal_gen3_ramp_mode : 1;
    Uint32 signal_gen3_gen_frame : 1;
    Uint32 signal_gen3_gen_data : 1;
#else 
    Uint32 signal_gen3_gen_data : 1;
    Uint32 signal_gen3_gen_frame : 1;
    Uint32 signal_gen3_ramp_mode : 1;
    Uint32 signal_gen3_seed : 1;
    Uint32 signal_gen3_frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_SEED_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_SEED_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_SIGNAL_GEN3_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_ADDR (0x00000680u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GENERAL_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN3_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_ramp_start_15_0 : 16;
#else 
    Uint32 signal_gen3_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_LO_REG_SIGNAL_GEN3_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_LO_REG_SIGNAL_GEN3_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_LO_REG_SIGNAL_GEN3_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_LO_REG_ADDR (0x00000684u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN3_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_ramp_start_31_16 : 16;
#else 
    Uint32 signal_gen3_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_HI_REG_SIGNAL_GEN3_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_HI_REG_SIGNAL_GEN3_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_HI_REG_SIGNAL_GEN3_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_HI_REG_ADDR (0x00000688u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN3_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_ramp_stop_15_0 : 16;
#else 
    Uint32 signal_gen3_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_LO_REG_SIGNAL_GEN3_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_LO_REG_SIGNAL_GEN3_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_LO_REG_SIGNAL_GEN3_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_LO_REG_ADDR (0x0000068Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN3_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_ramp_stop_31_16 : 16;
#else 
    Uint32 signal_gen3_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_HI_REG_SIGNAL_GEN3_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_HI_REG_SIGNAL_GEN3_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_HI_REG_SIGNAL_GEN3_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_HI_REG_ADDR (0x00000690u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN3_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_ramp_slope_15_0 : 16;
#else 
    Uint32 signal_gen3_ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_SIGNAL_GEN3_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_SIGNAL_GEN3_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_SIGNAL_GEN3_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_ADDR (0x00000694u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN3_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_ramp_slope_31_16 : 16;
#else 
    Uint32 signal_gen3_ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_SIGNAL_GEN3_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_SIGNAL_GEN3_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_SIGNAL_GEN3_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_ADDR (0x00000698u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN3_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_gen_timer : 16;
#else 
    Uint32 signal_gen3_gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN3_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GEN_TIMER_REG_SIGNAL_GEN3_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GEN_TIMER_REG_SIGNAL_GEN3_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GEN_TIMER_REG_SIGNAL_GEN3_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GEN_TIMER_REG_ADDR (0x0000069Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN3_INTERNAL_ONLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_bits : 16;
#else 
    Uint32 signal_gen3_bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN3_INTERNAL_ONLY_REG;

/* number of data bits inverted (read-only) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_INTERNAL_ONLY_REG_SIGNAL_GEN3_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_INTERNAL_ONLY_REG_SIGNAL_GEN3_BITS_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_INTERNAL_ONLY_REG_SIGNAL_GEN3_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_INTERNAL_ONLY_REG_ADDR (0x000006A0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN3_INTERNAL_ONLY_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN4_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen4_frame_len_m1 : 12;
    Uint32 signal_gen4_seed : 1;
    Uint32 signal_gen4_ramp_mode : 1;
    Uint32 signal_gen4_gen_frame : 1;
    Uint32 signal_gen4_gen_data : 1;
#else 
    Uint32 signal_gen4_gen_data : 1;
    Uint32 signal_gen4_gen_frame : 1;
    Uint32 signal_gen4_ramp_mode : 1;
    Uint32 signal_gen4_seed : 1;
    Uint32 signal_gen4_frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_SEED_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_SEED_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_SIGNAL_GEN4_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_ADDR (0x000006A4u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GENERAL_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN4_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen4_ramp_start_15_0 : 16;
#else 
    Uint32 signal_gen4_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_LO_REG_SIGNAL_GEN4_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_LO_REG_SIGNAL_GEN4_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_LO_REG_SIGNAL_GEN4_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_LO_REG_ADDR (0x000006A8u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN4_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen4_ramp_start_31_16 : 16;
#else 
    Uint32 signal_gen4_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_HI_REG_SIGNAL_GEN4_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_HI_REG_SIGNAL_GEN4_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_HI_REG_SIGNAL_GEN4_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_HI_REG_ADDR (0x000006ACu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN4_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen4_ramp_stop_15_0 : 16;
#else 
    Uint32 signal_gen4_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_LO_REG_SIGNAL_GEN4_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_LO_REG_SIGNAL_GEN4_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_LO_REG_SIGNAL_GEN4_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_LO_REG_ADDR (0x000006B0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN4_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen4_ramp_stop_31_16 : 16;
#else 
    Uint32 signal_gen4_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_HI_REG_SIGNAL_GEN4_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_HI_REG_SIGNAL_GEN4_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_HI_REG_SIGNAL_GEN4_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_HI_REG_ADDR (0x000006B4u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN4_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen4_ramp_slope_15_0 : 16;
#else 
    Uint32 signal_gen4_ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_SIGNAL_GEN4_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_SIGNAL_GEN4_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_SIGNAL_GEN4_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_ADDR (0x000006B8u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN4_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen4_ramp_slope_31_16 : 16;
#else 
    Uint32 signal_gen4_ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_SIGNAL_GEN4_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_SIGNAL_GEN4_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_SIGNAL_GEN4_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_ADDR (0x000006BCu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN4_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen4_gen_timer : 16;
#else 
    Uint32 signal_gen4_gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN4_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GEN_TIMER_REG_SIGNAL_GEN4_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GEN_TIMER_REG_SIGNAL_GEN4_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GEN_TIMER_REG_SIGNAL_GEN4_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GEN_TIMER_REG_ADDR (0x000006C0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN4_INTERNAL_ONLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen4_bits : 16;
#else 
    Uint32 signal_gen4_bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN4_INTERNAL_ONLY_REG;

/* number of data bits inverted (read-only) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_INTERNAL_ONLY_REG_SIGNAL_GEN4_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_INTERNAL_ONLY_REG_SIGNAL_GEN4_BITS_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_INTERNAL_ONLY_REG_SIGNAL_GEN4_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_INTERNAL_ONLY_REG_ADDR (0x000006C4u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN4_INTERNAL_ONLY_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN5_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen5_frame_len_m1 : 12;
    Uint32 signal_gen5_seed : 1;
    Uint32 signal_gen5_ramp_mode : 1;
    Uint32 signal_gen5_gen_frame : 1;
    Uint32 signal_gen5_gen_data : 1;
#else 
    Uint32 signal_gen5_gen_data : 1;
    Uint32 signal_gen5_gen_frame : 1;
    Uint32 signal_gen5_ramp_mode : 1;
    Uint32 signal_gen5_seed : 1;
    Uint32 signal_gen5_frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_SEED_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_SEED_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_SIGNAL_GEN5_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_ADDR (0x000006C8u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GENERAL_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN5_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen5_ramp_start_15_0 : 16;
#else 
    Uint32 signal_gen5_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_LO_REG_SIGNAL_GEN5_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_LO_REG_SIGNAL_GEN5_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_LO_REG_SIGNAL_GEN5_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_LO_REG_ADDR (0x000006CCu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN5_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen5_ramp_start_31_16 : 16;
#else 
    Uint32 signal_gen5_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_HI_REG_SIGNAL_GEN5_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_HI_REG_SIGNAL_GEN5_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_HI_REG_SIGNAL_GEN5_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_HI_REG_ADDR (0x000006D0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN5_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen5_ramp_stop_15_0 : 16;
#else 
    Uint32 signal_gen5_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_LO_REG_SIGNAL_GEN5_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_LO_REG_SIGNAL_GEN5_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_LO_REG_SIGNAL_GEN5_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_LO_REG_ADDR (0x000006D4u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN5_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen5_ramp_stop_31_16 : 16;
#else 
    Uint32 signal_gen5_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_HI_REG_SIGNAL_GEN5_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_HI_REG_SIGNAL_GEN5_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_HI_REG_SIGNAL_GEN5_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_HI_REG_ADDR (0x000006D8u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN5_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen5_ramp_slope_15_0 : 16;
#else 
    Uint32 signal_gen5_ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_SIGNAL_GEN5_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_SIGNAL_GEN5_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_SIGNAL_GEN5_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_ADDR (0x000006DCu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN5_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen5_ramp_slope_31_16 : 16;
#else 
    Uint32 signal_gen5_ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_SIGNAL_GEN5_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_SIGNAL_GEN5_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_SIGNAL_GEN5_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_ADDR (0x000006E0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN5_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen5_gen_timer : 16;
#else 
    Uint32 signal_gen5_gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN5_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GEN_TIMER_REG_SIGNAL_GEN5_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GEN_TIMER_REG_SIGNAL_GEN5_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GEN_TIMER_REG_SIGNAL_GEN5_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GEN_TIMER_REG_ADDR (0x000006E4u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN5_INTERNAL_ONLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen5_bits : 16;
#else 
    Uint32 signal_gen5_bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN5_INTERNAL_ONLY_REG;

/* number of data bits inverted (read-only) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_INTERNAL_ONLY_REG_SIGNAL_GEN5_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_INTERNAL_ONLY_REG_SIGNAL_GEN5_BITS_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_INTERNAL_ONLY_REG_SIGNAL_GEN5_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_INTERNAL_ONLY_REG_ADDR (0x000006E8u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN5_INTERNAL_ONLY_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN6_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen6_frame_len_m1 : 12;
    Uint32 signal_gen6_seed : 1;
    Uint32 signal_gen6_ramp_mode : 1;
    Uint32 signal_gen6_gen_frame : 1;
    Uint32 signal_gen6_gen_data : 1;
#else 
    Uint32 signal_gen6_gen_data : 1;
    Uint32 signal_gen6_gen_frame : 1;
    Uint32 signal_gen6_ramp_mode : 1;
    Uint32 signal_gen6_seed : 1;
    Uint32 signal_gen6_frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_SEED_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_SEED_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_SIGNAL_GEN6_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_ADDR (0x000006ECu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GENERAL_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN6_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen6_ramp_start_15_0 : 16;
#else 
    Uint32 signal_gen6_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_LO_REG_SIGNAL_GEN6_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_LO_REG_SIGNAL_GEN6_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_LO_REG_SIGNAL_GEN6_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_LO_REG_ADDR (0x000006F0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN6_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen6_ramp_start_31_16 : 16;
#else 
    Uint32 signal_gen6_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_HI_REG_SIGNAL_GEN6_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_HI_REG_SIGNAL_GEN6_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_HI_REG_SIGNAL_GEN6_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_HI_REG_ADDR (0x000006F4u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN6_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen6_ramp_stop_15_0 : 16;
#else 
    Uint32 signal_gen6_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_LO_REG_SIGNAL_GEN6_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_LO_REG_SIGNAL_GEN6_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_LO_REG_SIGNAL_GEN6_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_LO_REG_ADDR (0x000006F8u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN6_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen6_ramp_stop_31_16 : 16;
#else 
    Uint32 signal_gen6_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_HI_REG_SIGNAL_GEN6_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_HI_REG_SIGNAL_GEN6_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_HI_REG_SIGNAL_GEN6_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_HI_REG_ADDR (0x000006FCu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN6_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen6_ramp_slope_15_0 : 16;
#else 
    Uint32 signal_gen6_ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_SIGNAL_GEN6_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_SIGNAL_GEN6_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_SIGNAL_GEN6_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_ADDR (0x00000700u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN6_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen6_ramp_slope_31_16 : 16;
#else 
    Uint32 signal_gen6_ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_SIGNAL_GEN6_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_SIGNAL_GEN6_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_SIGNAL_GEN6_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_ADDR (0x00000704u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN6_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen6_gen_timer : 16;
#else 
    Uint32 signal_gen6_gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN6_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GEN_TIMER_REG_SIGNAL_GEN6_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GEN_TIMER_REG_SIGNAL_GEN6_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GEN_TIMER_REG_SIGNAL_GEN6_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GEN_TIMER_REG_ADDR (0x00000708u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN6_INTERNAL_ONLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen6_bits : 16;
#else 
    Uint32 signal_gen6_bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN6_INTERNAL_ONLY_REG;

/* number of data bits inverted (read-only) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_INTERNAL_ONLY_REG_SIGNAL_GEN6_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_INTERNAL_ONLY_REG_SIGNAL_GEN6_BITS_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_INTERNAL_ONLY_REG_SIGNAL_GEN6_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_INTERNAL_ONLY_REG_ADDR (0x0000070Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN6_INTERNAL_ONLY_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN7_GENERAL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_frame_len_m1 : 12;
    Uint32 signal_gen7_seed : 1;
    Uint32 signal_gen7_ramp_mode : 1;
    Uint32 signal_gen7_gen_frame : 1;
    Uint32 signal_gen7_gen_data : 1;
#else 
    Uint32 signal_gen7_gen_data : 1;
    Uint32 signal_gen7_gen_frame : 1;
    Uint32 signal_gen7_ramp_mode : 1;
    Uint32 signal_gen7_seed : 1;
    Uint32 signal_gen7_frame_len_m1 : 12;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG;

/* 1 = enable data generation, 0 = use data_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_GEN_DATA_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_GEN_DATA_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_GEN_DATA_RESETVAL (0x00000000u)

/* 1 = enable frame generation, 0 = use frame_in */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_GEN_FRAME_MASK (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_GEN_FRAME_SHIFT (0x00000001u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_GEN_FRAME_RESETVAL (0x00000000u)

/* 1 = generate ramp data, 0 = generate LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_RAMP_MODE_MASK (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_RAMP_MODE_SHIFT (0x00000002u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_RAMP_MODE_RESETVAL (0x00000000u)

/* 1 = use alternate seed value for LFSR data */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_SEED_MASK (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_SEED_SHIFT (0x00000003u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_SEED_RESETVAL (0x00000000u)

/* number of clocks per frame minus 1 */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_FRAME_LEN_M1_MASK (0x0000FFF0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_FRAME_LEN_M1_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_SIGNAL_GEN7_FRAME_LEN_M1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_ADDR (0x00000710u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GENERAL_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN7_RAMP_START_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_ramp_start_15_0 : 16;
#else 
    Uint32 signal_gen7_ramp_start_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_LO_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_LO_REG_SIGNAL_GEN7_RAMP_START_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_LO_REG_SIGNAL_GEN7_RAMP_START_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_LO_REG_SIGNAL_GEN7_RAMP_START_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_LO_REG_ADDR (0x00000714u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN7_RAMP_START_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_ramp_start_31_16 : 16;
#else 
    Uint32 signal_gen7_ramp_start_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_HI_REG;

/* ramp starting value */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_HI_REG_SIGNAL_GEN7_RAMP_START_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_HI_REG_SIGNAL_GEN7_RAMP_START_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_HI_REG_SIGNAL_GEN7_RAMP_START_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_HI_REG_ADDR (0x00000718u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_START_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN7_RAMP_STOP_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_ramp_stop_15_0 : 16;
#else 
    Uint32 signal_gen7_ramp_stop_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_LO_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_LO_REG_SIGNAL_GEN7_RAMP_STOP_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_LO_REG_SIGNAL_GEN7_RAMP_STOP_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_LO_REG_SIGNAL_GEN7_RAMP_STOP_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_LO_REG_ADDR (0x0000071Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN7_RAMP_STOP_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_ramp_stop_31_16 : 16;
#else 
    Uint32 signal_gen7_ramp_stop_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_HI_REG;

/* ramp stop value - ramp loops back to ramp_start */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_HI_REG_SIGNAL_GEN7_RAMP_STOP_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_HI_REG_SIGNAL_GEN7_RAMP_STOP_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_HI_REG_SIGNAL_GEN7_RAMP_STOP_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_HI_REG_ADDR (0x00000720u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_STOP_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN7_RAMP_SLOPE_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_ramp_slope_15_0 : 16;
#else 
    Uint32 signal_gen7_ramp_slope_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_LO_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_SIGNAL_GEN7_RAMP_SLOPE_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_SIGNAL_GEN7_RAMP_SLOPE_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_SIGNAL_GEN7_RAMP_SLOPE_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_ADDR (0x00000724u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_LO_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN7_RAMP_SLOPE_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_ramp_slope_31_16 : 16;
#else 
    Uint32 signal_gen7_ramp_slope_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_HI_REG;

/* ramp slope value - ramp increments by this value every clock (not every sample) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_SIGNAL_GEN7_RAMP_SLOPE_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_SIGNAL_GEN7_RAMP_SLOPE_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_SIGNAL_GEN7_RAMP_SLOPE_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_ADDR (0x00000728u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_RAMP_SLOPE_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN7_GEN_TIMER */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_gen_timer : 16;
#else 
    Uint32 signal_gen7_gen_timer : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN7_GEN_TIMER_REG;

/* 0 = generate data forever, n = generate data for n clock cycles */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GEN_TIMER_REG_SIGNAL_GEN7_GEN_TIMER_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GEN_TIMER_REG_SIGNAL_GEN7_GEN_TIMER_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GEN_TIMER_REG_SIGNAL_GEN7_GEN_TIMER_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GEN_TIMER_REG_ADDR (0x0000072Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_GEN_TIMER_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN7_INTERNAL_ONLY */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_bits : 16;
#else 
    Uint32 signal_gen7_bits : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN7_INTERNAL_ONLY_REG;

/* number of data bits inverted (read-only) */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_INTERNAL_ONLY_REG_SIGNAL_GEN7_BITS_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_INTERNAL_ONLY_REG_SIGNAL_GEN7_BITS_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_INTERNAL_ONLY_REG_SIGNAL_GEN7_BITS_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_INTERNAL_ONLY_REG_ADDR (0x00000730u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN7_INTERNAL_ONLY_REG_RESETVAL (0x00000000u)

/* TOP_CHECK_SUM_CTRL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd1 : 16;
    Uint32 check_sum_stable_len : 12;
    Uint32 rsvd0 : 3;
    Uint32 check_sum_mode : 1;
#else 
    Uint32 check_sum_mode : 1;
    Uint32 rsvd0 : 3;
    Uint32 check_sum_stable_len : 12;
    Uint32 rsvd1 : 16;
#endif 
} CSL_DFE_DPD_TOP_CHECK_SUM_CTRL_REG;

/* 1 = return latency calculation, 0 = return check sum */
#define CSL_DFE_DPD_TOP_CHECK_SUM_CTRL_REG_CHECK_SUM_MODE_MASK (0x00000001u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_CTRL_REG_CHECK_SUM_MODE_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_CTRL_REG_CHECK_SUM_MODE_RESETVAL (0x00000000u)

/* latency calculation - clocks that data must remain stable after pulse */
#define CSL_DFE_DPD_TOP_CHECK_SUM_CTRL_REG_CHECK_SUM_STABLE_LEN_MASK (0x0000FFF0u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_CTRL_REG_CHECK_SUM_STABLE_LEN_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_CTRL_REG_CHECK_SUM_STABLE_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_CHECK_SUM_CTRL_REG_ADDR (0x00000734u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_CTRL_REG_RESETVAL (0x00000000u)

/* TOP_CHECK_SUM_SIGNAL_LEN */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum_signal_len : 16;
#else 
    Uint32 check_sum_signal_len : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_CHECK_SUM_SIGNAL_LEN_REG;

/* latency calculation - width of data pulse from signal_gen */
#define CSL_DFE_DPD_TOP_CHECK_SUM_SIGNAL_LEN_REG_CHECK_SUM_SIGNAL_LEN_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_CHECK_SUM_SIGNAL_LEN_REG_CHECK_SUM_SIGNAL_LEN_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_SIGNAL_LEN_REG_CHECK_SUM_SIGNAL_LEN_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_CHECK_SUM_SIGNAL_LEN_REG_ADDR (0x00000738u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_SIGNAL_LEN_REG_RESETVAL (0x00000000u)

/* TOP_CHECK_SUM_CHAN_SEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 24;
    Uint32 check_sum_chan_sel : 8;
#else 
    Uint32 check_sum_chan_sel : 8;
    Uint32 rsvd0 : 24;
#endif 
} CSL_DFE_DPD_TOP_CHECK_SUM_CHAN_SEL_REG;

/* latency calculation - channel select specified by clocks after frame */
#define CSL_DFE_DPD_TOP_CHECK_SUM_CHAN_SEL_REG_CHECK_SUM_CHAN_SEL_MASK (0x000000FFu)
#define CSL_DFE_DPD_TOP_CHECK_SUM_CHAN_SEL_REG_CHECK_SUM_CHAN_SEL_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_CHAN_SEL_REG_CHECK_SUM_CHAN_SEL_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_CHECK_SUM_CHAN_SEL_REG_ADDR (0x0000073Cu)
#define CSL_DFE_DPD_TOP_CHECK_SUM_CHAN_SEL_REG_RESETVAL (0x00000000u)

/* TOP_CHECK_SUM_RESULT_LO */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum_result_15_0 : 16;
#else 
    Uint32 check_sum_result_15_0 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_LO_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_LO_REG_CHECK_SUM_RESULT_15_0_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_LO_REG_CHECK_SUM_RESULT_15_0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_LO_REG_CHECK_SUM_RESULT_15_0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_LO_REG_ADDR (0x00000740u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_LO_REG_RESETVAL (0x00000000u)

/* TOP_CHECK_SUM_RESULT_HI */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 check_sum_result_31_16 : 16;
#else 
    Uint32 check_sum_result_31_16 : 16;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_HI_REG;

/* result of check sum or latency calculation depending on mode */
#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_HI_REG_CHECK_SUM_RESULT_31_16_MASK (0x0000FFFFu)
#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_HI_REG_CHECK_SUM_RESULT_31_16_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_HI_REG_CHECK_SUM_RESULT_31_16_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_HI_REG_ADDR (0x00000744u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_RESULT_HI_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN_SSEL_PART0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen3_ssel : 4;
    Uint32 signal_gen2_ssel : 4;
    Uint32 signal_gen1_ssel : 4;
    Uint32 signal_gen0_ssel : 4;
#else 
    Uint32 signal_gen0_ssel : 4;
    Uint32 signal_gen1_ssel : 4;
    Uint32 signal_gen2_ssel : 4;
    Uint32 signal_gen3_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG;

/* sync select for signal generator inside dpd. */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN0_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN0_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN0_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator inside dpd. */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN1_SSEL_MASK (0x000000F0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN1_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN1_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator inside dpd. */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN2_SSEL_MASK (0x00000F00u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN2_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN2_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator inside dpd. */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN3_SSEL_MASK (0x0000F000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN3_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_SIGNAL_GEN3_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_ADDR (0x00000748u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART0_REG_RESETVAL (0x00000000u)

/* TOP_SIGNAL_GEN_SSEL_PART1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 16;
    Uint32 signal_gen7_ssel : 4;
    Uint32 signal_gen6_ssel : 4;
    Uint32 signal_gen5_ssel : 4;
    Uint32 signal_gen4_ssel : 4;
#else 
    Uint32 signal_gen4_ssel : 4;
    Uint32 signal_gen5_ssel : 4;
    Uint32 signal_gen6_ssel : 4;
    Uint32 signal_gen7_ssel : 4;
    Uint32 rsvd0 : 16;
#endif 
} CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG;

/* sync select for signal generator inside dpd. */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN4_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN4_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN4_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator inside dpd. */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN5_SSEL_MASK (0x000000F0u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN5_SSEL_SHIFT (0x00000004u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN5_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator inside dpd. */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN6_SSEL_MASK (0x00000F00u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN6_SSEL_SHIFT (0x00000008u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN6_SSEL_RESETVAL (0x00000000u)

/* sync select for signal generator inside dpd. */
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN7_SSEL_MASK (0x0000F000u)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN7_SSEL_SHIFT (0x0000000Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_SIGNAL_GEN7_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_ADDR (0x0000074Cu)
#define CSL_DFE_DPD_TOP_SIGNAL_GEN_SSEL_PART1_REG_RESETVAL (0x00000000u)

/* TOP_CHECK_SUM_SSEL */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 28;
    Uint32 check_sum_ssel : 4;
#else 
    Uint32 check_sum_ssel : 4;
    Uint32 rsvd0 : 28;
#endif 
} CSL_DFE_DPD_TOP_CHECK_SUM_SSEL_REG;

/* sync select for check sum inside dpd. */
#define CSL_DFE_DPD_TOP_CHECK_SUM_SSEL_REG_CHECK_SUM_SSEL_MASK (0x0000000Fu)
#define CSL_DFE_DPD_TOP_CHECK_SUM_SSEL_REG_CHECK_SUM_SSEL_SHIFT (0x00000000u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_SSEL_REG_CHECK_SUM_SSEL_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_TOP_CHECK_SUM_SSEL_REG_ADDR (0x00000750u)
#define CSL_DFE_DPD_TOP_CHECK_SUM_SSEL_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R0_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r0_c0 : 26;
#else 
    Uint32 dpdlut_b0_r0_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C0_REG;

/* data[25:0] = {slope_real[9:0], gain_real[15:0]} for even addresses */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C0_REG_DPDLUT_B0_R0_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C0_REG_DPDLUT_B0_R0_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C0_REG_DPDLUT_B0_R0_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C0_REG_ADDR (0x00040000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C0_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R0_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r0_c1 : 26;
#else 
    Uint32 dpdlut_b0_r0_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C1_REG_DPDLUT_B0_R0_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C1_REG_DPDLUT_B0_R0_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C1_REG_DPDLUT_B0_R0_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C1_REG_ADDR (0x00040800u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C1_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R0_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r0_c2 : 26;
#else 
    Uint32 dpdlut_b0_r0_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C2_REG_DPDLUT_B0_R0_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C2_REG_DPDLUT_B0_R0_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C2_REG_DPDLUT_B0_R0_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C2_REG_ADDR (0x00041000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R0_C2_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R1_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r1_c0 : 26;
#else 
    Uint32 dpdlut_b0_r1_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C0_REG_DPDLUT_B0_R1_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C0_REG_DPDLUT_B0_R1_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C0_REG_DPDLUT_B0_R1_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C0_REG_ADDR (0x00041800u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C0_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R1_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r1_c1 : 26;
#else 
    Uint32 dpdlut_b0_r1_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C1_REG_DPDLUT_B0_R1_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C1_REG_DPDLUT_B0_R1_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C1_REG_DPDLUT_B0_R1_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C1_REG_ADDR (0x00042000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C1_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R1_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r1_c2 : 26;
#else 
    Uint32 dpdlut_b0_r1_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C2_REG_DPDLUT_B0_R1_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C2_REG_DPDLUT_B0_R1_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C2_REG_DPDLUT_B0_R1_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C2_REG_ADDR (0x00042800u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R1_C2_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R2_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r2_c0 : 26;
#else 
    Uint32 dpdlut_b0_r2_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C0_REG_DPDLUT_B0_R2_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C0_REG_DPDLUT_B0_R2_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C0_REG_DPDLUT_B0_R2_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C0_REG_ADDR (0x00043000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C0_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R2_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r2_c1 : 26;
#else 
    Uint32 dpdlut_b0_r2_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C1_REG_DPDLUT_B0_R2_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C1_REG_DPDLUT_B0_R2_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C1_REG_DPDLUT_B0_R2_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C1_REG_ADDR (0x00043800u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C1_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R2_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r2_c2 : 26;
#else 
    Uint32 dpdlut_b0_r2_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C2_REG_DPDLUT_B0_R2_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C2_REG_DPDLUT_B0_R2_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C2_REG_DPDLUT_B0_R2_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C2_REG_ADDR (0x00044000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R2_C2_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R3_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r3_c0 : 26;
#else 
    Uint32 dpdlut_b0_r3_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C0_REG_DPDLUT_B0_R3_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C0_REG_DPDLUT_B0_R3_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C0_REG_DPDLUT_B0_R3_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C0_REG_ADDR (0x00044800u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C0_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R3_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r3_c1 : 26;
#else 
    Uint32 dpdlut_b0_r3_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C1_REG_DPDLUT_B0_R3_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C1_REG_DPDLUT_B0_R3_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C1_REG_DPDLUT_B0_R3_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C1_REG_ADDR (0x00045000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C1_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R3_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r3_c2 : 26;
#else 
    Uint32 dpdlut_b0_r3_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C2_REG_DPDLUT_B0_R3_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C2_REG_DPDLUT_B0_R3_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C2_REG_DPDLUT_B0_R3_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C2_REG_ADDR (0x00045800u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R3_C2_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R4_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r4_c0 : 26;
#else 
    Uint32 dpdlut_b0_r4_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C0_REG_DPDLUT_B0_R4_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C0_REG_DPDLUT_B0_R4_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C0_REG_DPDLUT_B0_R4_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C0_REG_ADDR (0x00046000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C0_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R4_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r4_c1 : 26;
#else 
    Uint32 dpdlut_b0_r4_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C1_REG_DPDLUT_B0_R4_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C1_REG_DPDLUT_B0_R4_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C1_REG_DPDLUT_B0_R4_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C1_REG_ADDR (0x00046800u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C1_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R4_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r4_c2 : 26;
#else 
    Uint32 dpdlut_b0_r4_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C2_REG_DPDLUT_B0_R4_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C2_REG_DPDLUT_B0_R4_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C2_REG_DPDLUT_B0_R4_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C2_REG_ADDR (0x00047000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R4_C2_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R5_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r5_c0 : 26;
#else 
    Uint32 dpdlut_b0_r5_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C0_REG_DPDLUT_B0_R5_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C0_REG_DPDLUT_B0_R5_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C0_REG_DPDLUT_B0_R5_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C0_REG_ADDR (0x00047800u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C0_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R5_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r5_c1 : 26;
#else 
    Uint32 dpdlut_b0_r5_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C1_REG_DPDLUT_B0_R5_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C1_REG_DPDLUT_B0_R5_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C1_REG_DPDLUT_B0_R5_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C1_REG_ADDR (0x00048000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C1_REG_RESETVAL (0x00000000u)

/* DPD0_DPDLUT_B0_R5_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b0_r5_c2 : 26;
#else 
    Uint32 dpdlut_b0_r5_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C2_REG_DPDLUT_B0_R5_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C2_REG_DPDLUT_B0_R5_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C2_REG_DPDLUT_B0_R5_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C2_REG_ADDR (0x00048800u)
#define CSL_DFE_DPD_DPD0_DPDLUT_B0_R5_C2_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R0_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r0_c0 : 26;
#else 
    Uint32 dpdlut_b1_r0_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C0_REG_DPDLUT_B1_R0_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C0_REG_DPDLUT_B1_R0_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C0_REG_DPDLUT_B1_R0_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C0_REG_ADDR (0x00049000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C0_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R0_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r0_c1 : 26;
#else 
    Uint32 dpdlut_b1_r0_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C1_REG_DPDLUT_B1_R0_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C1_REG_DPDLUT_B1_R0_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C1_REG_DPDLUT_B1_R0_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C1_REG_ADDR (0x00049800u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C1_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R0_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r0_c2 : 26;
#else 
    Uint32 dpdlut_b1_r0_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C2_REG_DPDLUT_B1_R0_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C2_REG_DPDLUT_B1_R0_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C2_REG_DPDLUT_B1_R0_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C2_REG_ADDR (0x0004A000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R0_C2_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R1_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r1_c0 : 26;
#else 
    Uint32 dpdlut_b1_r1_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C0_REG_DPDLUT_B1_R1_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C0_REG_DPDLUT_B1_R1_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C0_REG_DPDLUT_B1_R1_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C0_REG_ADDR (0x0004A800u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C0_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R1_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r1_c1 : 26;
#else 
    Uint32 dpdlut_b1_r1_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C1_REG_DPDLUT_B1_R1_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C1_REG_DPDLUT_B1_R1_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C1_REG_DPDLUT_B1_R1_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C1_REG_ADDR (0x0004B000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C1_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R1_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r1_c2 : 26;
#else 
    Uint32 dpdlut_b1_r1_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C2_REG_DPDLUT_B1_R1_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C2_REG_DPDLUT_B1_R1_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C2_REG_DPDLUT_B1_R1_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C2_REG_ADDR (0x0004B800u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R1_C2_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R2_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r2_c0 : 26;
#else 
    Uint32 dpdlut_b1_r2_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C0_REG_DPDLUT_B1_R2_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C0_REG_DPDLUT_B1_R2_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C0_REG_DPDLUT_B1_R2_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C0_REG_ADDR (0x0004C000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C0_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R2_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r2_c1 : 26;
#else 
    Uint32 dpdlut_b1_r2_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C1_REG_DPDLUT_B1_R2_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C1_REG_DPDLUT_B1_R2_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C1_REG_DPDLUT_B1_R2_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C1_REG_ADDR (0x0004C800u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C1_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R2_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r2_c2 : 26;
#else 
    Uint32 dpdlut_b1_r2_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C2_REG_DPDLUT_B1_R2_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C2_REG_DPDLUT_B1_R2_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C2_REG_DPDLUT_B1_R2_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C2_REG_ADDR (0x0004D000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R2_C2_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R3_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r3_c0 : 26;
#else 
    Uint32 dpdlut_b1_r3_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C0_REG_DPDLUT_B1_R3_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C0_REG_DPDLUT_B1_R3_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C0_REG_DPDLUT_B1_R3_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C0_REG_ADDR (0x0004D800u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C0_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R3_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r3_c1 : 26;
#else 
    Uint32 dpdlut_b1_r3_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C1_REG_DPDLUT_B1_R3_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C1_REG_DPDLUT_B1_R3_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C1_REG_DPDLUT_B1_R3_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C1_REG_ADDR (0x0004E000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C1_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R3_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r3_c2 : 26;
#else 
    Uint32 dpdlut_b1_r3_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C2_REG_DPDLUT_B1_R3_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C2_REG_DPDLUT_B1_R3_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C2_REG_DPDLUT_B1_R3_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C2_REG_ADDR (0x0004E800u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R3_C2_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R4_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r4_c0 : 26;
#else 
    Uint32 dpdlut_b1_r4_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C0_REG_DPDLUT_B1_R4_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C0_REG_DPDLUT_B1_R4_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C0_REG_DPDLUT_B1_R4_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C0_REG_ADDR (0x0004F000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C0_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R4_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r4_c1 : 26;
#else 
    Uint32 dpdlut_b1_r4_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C1_REG_DPDLUT_B1_R4_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C1_REG_DPDLUT_B1_R4_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C1_REG_DPDLUT_B1_R4_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C1_REG_ADDR (0x0004F800u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C1_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R4_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r4_c2 : 26;
#else 
    Uint32 dpdlut_b1_r4_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C2_REG_DPDLUT_B1_R4_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C2_REG_DPDLUT_B1_R4_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C2_REG_DPDLUT_B1_R4_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C2_REG_ADDR (0x00050000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R4_C2_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R5_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r5_c0 : 26;
#else 
    Uint32 dpdlut_b1_r5_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C0_REG_DPDLUT_B1_R5_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C0_REG_DPDLUT_B1_R5_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C0_REG_DPDLUT_B1_R5_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C0_REG_ADDR (0x00050800u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C0_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R5_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r5_c1 : 26;
#else 
    Uint32 dpdlut_b1_r5_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C1_REG_DPDLUT_B1_R5_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C1_REG_DPDLUT_B1_R5_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C1_REG_DPDLUT_B1_R5_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C1_REG_ADDR (0x00051000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C1_REG_RESETVAL (0x00000000u)

/* DPD1_DPDLUT_B1_R5_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b1_r5_c2 : 26;
#else 
    Uint32 dpdlut_b1_r5_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C2_REG_DPDLUT_B1_R5_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C2_REG_DPDLUT_B1_R5_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C2_REG_DPDLUT_B1_R5_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C2_REG_ADDR (0x00051800u)
#define CSL_DFE_DPD_DPD1_DPDLUT_B1_R5_C2_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R0_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r0_c0 : 26;
#else 
    Uint32 dpdlut_b2_r0_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C0_REG_DPDLUT_B2_R0_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C0_REG_DPDLUT_B2_R0_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C0_REG_DPDLUT_B2_R0_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C0_REG_ADDR (0x00052000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C0_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R0_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r0_c1 : 26;
#else 
    Uint32 dpdlut_b2_r0_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C1_REG_DPDLUT_B2_R0_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C1_REG_DPDLUT_B2_R0_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C1_REG_DPDLUT_B2_R0_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C1_REG_ADDR (0x00052800u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C1_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R0_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r0_c2 : 26;
#else 
    Uint32 dpdlut_b2_r0_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C2_REG_DPDLUT_B2_R0_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C2_REG_DPDLUT_B2_R0_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C2_REG_DPDLUT_B2_R0_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C2_REG_ADDR (0x00053000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R0_C2_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R1_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r1_c0 : 26;
#else 
    Uint32 dpdlut_b2_r1_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C0_REG_DPDLUT_B2_R1_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C0_REG_DPDLUT_B2_R1_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C0_REG_DPDLUT_B2_R1_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C0_REG_ADDR (0x00053800u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C0_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R1_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r1_c1 : 26;
#else 
    Uint32 dpdlut_b2_r1_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C1_REG_DPDLUT_B2_R1_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C1_REG_DPDLUT_B2_R1_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C1_REG_DPDLUT_B2_R1_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C1_REG_ADDR (0x00054000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C1_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R1_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r1_c2 : 26;
#else 
    Uint32 dpdlut_b2_r1_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C2_REG_DPDLUT_B2_R1_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C2_REG_DPDLUT_B2_R1_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C2_REG_DPDLUT_B2_R1_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C2_REG_ADDR (0x00054800u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R1_C2_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R2_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r2_c0 : 26;
#else 
    Uint32 dpdlut_b2_r2_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C0_REG_DPDLUT_B2_R2_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C0_REG_DPDLUT_B2_R2_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C0_REG_DPDLUT_B2_R2_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C0_REG_ADDR (0x00055000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C0_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R2_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r2_c1 : 26;
#else 
    Uint32 dpdlut_b2_r2_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C1_REG_DPDLUT_B2_R2_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C1_REG_DPDLUT_B2_R2_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C1_REG_DPDLUT_B2_R2_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C1_REG_ADDR (0x00055800u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C1_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R2_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r2_c2 : 26;
#else 
    Uint32 dpdlut_b2_r2_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C2_REG_DPDLUT_B2_R2_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C2_REG_DPDLUT_B2_R2_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C2_REG_DPDLUT_B2_R2_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C2_REG_ADDR (0x00056000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R2_C2_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R3_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r3_c0 : 26;
#else 
    Uint32 dpdlut_b2_r3_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C0_REG_DPDLUT_B2_R3_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C0_REG_DPDLUT_B2_R3_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C0_REG_DPDLUT_B2_R3_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C0_REG_ADDR (0x00056800u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C0_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R3_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r3_c1 : 26;
#else 
    Uint32 dpdlut_b2_r3_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C1_REG_DPDLUT_B2_R3_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C1_REG_DPDLUT_B2_R3_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C1_REG_DPDLUT_B2_R3_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C1_REG_ADDR (0x00057000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C1_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R3_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r3_c2 : 26;
#else 
    Uint32 dpdlut_b2_r3_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C2_REG_DPDLUT_B2_R3_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C2_REG_DPDLUT_B2_R3_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C2_REG_DPDLUT_B2_R3_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C2_REG_ADDR (0x00057800u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R3_C2_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R4_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r4_c0 : 26;
#else 
    Uint32 dpdlut_b2_r4_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C0_REG_DPDLUT_B2_R4_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C0_REG_DPDLUT_B2_R4_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C0_REG_DPDLUT_B2_R4_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C0_REG_ADDR (0x00058000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C0_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R4_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r4_c1 : 26;
#else 
    Uint32 dpdlut_b2_r4_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C1_REG_DPDLUT_B2_R4_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C1_REG_DPDLUT_B2_R4_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C1_REG_DPDLUT_B2_R4_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C1_REG_ADDR (0x00058800u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C1_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R4_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r4_c2 : 26;
#else 
    Uint32 dpdlut_b2_r4_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C2_REG_DPDLUT_B2_R4_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C2_REG_DPDLUT_B2_R4_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C2_REG_DPDLUT_B2_R4_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C2_REG_ADDR (0x00059000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R4_C2_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R5_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r5_c0 : 26;
#else 
    Uint32 dpdlut_b2_r5_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C0_REG_DPDLUT_B2_R5_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C0_REG_DPDLUT_B2_R5_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C0_REG_DPDLUT_B2_R5_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C0_REG_ADDR (0x00059800u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C0_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R5_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r5_c1 : 26;
#else 
    Uint32 dpdlut_b2_r5_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C1_REG_DPDLUT_B2_R5_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C1_REG_DPDLUT_B2_R5_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C1_REG_DPDLUT_B2_R5_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C1_REG_ADDR (0x0005A000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C1_REG_RESETVAL (0x00000000u)

/* DPD2_DPDLUT_B2_R5_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b2_r5_c2 : 26;
#else 
    Uint32 dpdlut_b2_r5_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C2_REG_DPDLUT_B2_R5_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C2_REG_DPDLUT_B2_R5_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C2_REG_DPDLUT_B2_R5_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C2_REG_ADDR (0x0005A800u)
#define CSL_DFE_DPD_DPD2_DPDLUT_B2_R5_C2_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R0_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r0_c0 : 26;
#else 
    Uint32 dpdlut_b3_r0_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C0_REG_DPDLUT_B3_R0_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C0_REG_DPDLUT_B3_R0_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C0_REG_DPDLUT_B3_R0_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C0_REG_ADDR (0x0005B000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C0_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R0_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r0_c1 : 26;
#else 
    Uint32 dpdlut_b3_r0_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C1_REG_DPDLUT_B3_R0_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C1_REG_DPDLUT_B3_R0_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C1_REG_DPDLUT_B3_R0_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C1_REG_ADDR (0x0005B800u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C1_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R0_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r0_c2 : 26;
#else 
    Uint32 dpdlut_b3_r0_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C2_REG_DPDLUT_B3_R0_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C2_REG_DPDLUT_B3_R0_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C2_REG_DPDLUT_B3_R0_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C2_REG_ADDR (0x0005C000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R0_C2_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R1_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r1_c0 : 26;
#else 
    Uint32 dpdlut_b3_r1_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C0_REG_DPDLUT_B3_R1_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C0_REG_DPDLUT_B3_R1_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C0_REG_DPDLUT_B3_R1_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C0_REG_ADDR (0x0005C800u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C0_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R1_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r1_c1 : 26;
#else 
    Uint32 dpdlut_b3_r1_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C1_REG_DPDLUT_B3_R1_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C1_REG_DPDLUT_B3_R1_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C1_REG_DPDLUT_B3_R1_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C1_REG_ADDR (0x0005D000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C1_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R1_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r1_c2 : 26;
#else 
    Uint32 dpdlut_b3_r1_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C2_REG_DPDLUT_B3_R1_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C2_REG_DPDLUT_B3_R1_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C2_REG_DPDLUT_B3_R1_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C2_REG_ADDR (0x0005D800u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R1_C2_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R2_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r2_c0 : 26;
#else 
    Uint32 dpdlut_b3_r2_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C0_REG_DPDLUT_B3_R2_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C0_REG_DPDLUT_B3_R2_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C0_REG_DPDLUT_B3_R2_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C0_REG_ADDR (0x0005E000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C0_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R2_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r2_c1 : 26;
#else 
    Uint32 dpdlut_b3_r2_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C1_REG_DPDLUT_B3_R2_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C1_REG_DPDLUT_B3_R2_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C1_REG_DPDLUT_B3_R2_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C1_REG_ADDR (0x0005E800u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C1_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R2_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r2_c2 : 26;
#else 
    Uint32 dpdlut_b3_r2_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C2_REG_DPDLUT_B3_R2_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C2_REG_DPDLUT_B3_R2_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C2_REG_DPDLUT_B3_R2_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C2_REG_ADDR (0x0005F000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R2_C2_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R3_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r3_c0 : 26;
#else 
    Uint32 dpdlut_b3_r3_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C0_REG_DPDLUT_B3_R3_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C0_REG_DPDLUT_B3_R3_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C0_REG_DPDLUT_B3_R3_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C0_REG_ADDR (0x0005F800u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C0_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R3_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r3_c1 : 26;
#else 
    Uint32 dpdlut_b3_r3_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C1_REG_DPDLUT_B3_R3_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C1_REG_DPDLUT_B3_R3_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C1_REG_DPDLUT_B3_R3_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C1_REG_ADDR (0x00060000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C1_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R3_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r3_c2 : 26;
#else 
    Uint32 dpdlut_b3_r3_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C2_REG_DPDLUT_B3_R3_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C2_REG_DPDLUT_B3_R3_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C2_REG_DPDLUT_B3_R3_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C2_REG_ADDR (0x00060800u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R3_C2_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R4_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r4_c0 : 26;
#else 
    Uint32 dpdlut_b3_r4_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C0_REG_DPDLUT_B3_R4_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C0_REG_DPDLUT_B3_R4_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C0_REG_DPDLUT_B3_R4_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C0_REG_ADDR (0x00061000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C0_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R4_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r4_c1 : 26;
#else 
    Uint32 dpdlut_b3_r4_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C1_REG_DPDLUT_B3_R4_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C1_REG_DPDLUT_B3_R4_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C1_REG_DPDLUT_B3_R4_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C1_REG_ADDR (0x00061800u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C1_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R4_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r4_c2 : 26;
#else 
    Uint32 dpdlut_b3_r4_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C2_REG_DPDLUT_B3_R4_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C2_REG_DPDLUT_B3_R4_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C2_REG_DPDLUT_B3_R4_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C2_REG_ADDR (0x00062000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R4_C2_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R5_C0 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r5_c0 : 26;
#else 
    Uint32 dpdlut_b3_r5_c0 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C0_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C0_REG_DPDLUT_B3_R5_C0_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C0_REG_DPDLUT_B3_R5_C0_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C0_REG_DPDLUT_B3_R5_C0_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C0_REG_ADDR (0x00062800u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C0_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R5_C1 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r5_c1 : 26;
#else 
    Uint32 dpdlut_b3_r5_c1 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C1_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C1_REG_DPDLUT_B3_R5_C1_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C1_REG_DPDLUT_B3_R5_C1_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C1_REG_DPDLUT_B3_R5_C1_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C1_REG_ADDR (0x00063000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C1_REG_RESETVAL (0x00000000u)

/* DPD3_DPDLUT_B3_R5_C2 */
typedef struct 
{
#ifdef _BIG_ENDIAN
    Uint32 rsvd0 : 6;
    Uint32 dpdlut_b3_r5_c2 : 26;
#else 
    Uint32 dpdlut_b3_r5_c2 : 26;
    Uint32 rsvd0 : 6;
#endif 
} CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C2_REG;

/* save as above, but for a different dpd cell */
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C2_REG_DPDLUT_B3_R5_C2_MASK (0x03FFFFFFu)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C2_REG_DPDLUT_B3_R5_C2_SHIFT (0x00000000u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C2_REG_DPDLUT_B3_R5_C2_RESETVAL (0x00000000u)

#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C2_REG_ADDR (0x00063800u)
#define CSL_DFE_DPD_DPD3_DPDLUT_B3_R5_C2_REG_RESETVAL (0x00000000u)

#endif /* CSLR_DFE_DPD_H__ */
